use std::fs;

use crate::notification::Notification;
use serde::{Deserialize, Serialize};
use serde_json::Value;
use std::str;
use tower_lsp::jsonrpc::Error;
use tower_lsp::jsonrpc::Result;
use tower_lsp::lsp_types::*;
use tower_lsp::{Client, LanguageServer, LspService, Server};
use tracing::info;
use tree_sitter::Query;
use tree_sitter::QueryCursor;

#[derive(Debug, Deserialize, Serialize)]
struct CustomNotificationParams {
    title: String,
    message: String,
}

impl CustomNotificationParams {
    fn new(title: impl Into<String>, message: impl Into<String>) -> Self {
        CustomNotificationParams {
            title: title.into(),
            message: message.into(),
        }
    }
}

enum CustomNotification {}

impl Notification for CustomNotification {
    type Params = CustomNotificationParams;

    const METHOD: &'static str = "custom/notification";
}

#[derive(Debug)]
struct Backend {
    client: Client,
}

#[tower_lsp::async_trait]
impl LanguageServer for Backend {
    async fn initialize(&self, _: InitializeParams) -> Result<InitializeResult> {
        Ok(InitializeResult {
            server_info: None,
            capabilities: ServerCapabilities {
                document_symbol_provider: Some(tower_lsp::lsp_types::OneOf::Left(true)),
                execute_command_provider: Some(ExecuteCommandOptions {
                    commands: vec!["custom.notification".to_string()],
                    work_done_progress_options: Default::default(),
                }),
                ..ServerCapabilities::default()
            },
            ..Default::default()
        })
    }

    async fn initialized(&self, _: InitializedParams) {
        info!("test");
        self.client
            .log_message(MessageType::INFO, "server initialized!")
            .await;
    }

    async fn shutdown(&self) -> Result<()> {
        Ok(())
    }

    async fn did_open(&self, _f: DidOpenTextDocumentParams) {
        self.client
            .log_message(MessageType::INFO, "file opened!")
            .await;
    }

    async fn document_symbol(
        &self,
        params: DocumentSymbolParams,
    ) -> Result<Option<DocumentSymbolResponse>> {
        if params.text_document.uri.scheme() != "file" {
            return Err(Error::invalid_params(format!(
                "Could not parse document for symbols. URI scheme is: {:?}, only scheme:file is accepted.",
                params.text_document.uri.scheme()
            )));
        }
        let data = fs::read_to_string(params.text_document.uri.path()).unwrap();
        let mut parser = tree_sitter::Parser::new();
        let hou_lang = tree_sitter_houlang::language();
        parser
            .set_language(hou_lang)
            .expect("Error loading houlang grammar");
        let tree = parser.parse(&data, None).unwrap();
        let query = Query::new(hou_lang, "(week (date) @date) @full_week").unwrap();

        let mut query_cursor = QueryCursor::new();
        let all_matches = query_cursor.matches(&query, tree.root_node(), data.as_bytes());
        let symbols: Vec<DocumentSymbol> = all_matches
            .into_iter()
            .map(|m| {
                let date_byte_range = m.captures[1].node.range();
                let date = &data.as_bytes()[date_byte_range.start_byte..date_byte_range.end_byte];
                let ts_range = m.captures[0].node.range();
                let lsp_range = Range {
                    start: Position {
                        line: ts_range.start_point.row.try_into().unwrap(),
                        character: ts_range.start_point.column.try_into().unwrap(),
                    },
                    end: Position {
                        line: ts_range.end_point.row.try_into().unwrap(),
                        character: ts_range.end_point.column.try_into().unwrap(),
                    },
                };
                DocumentSymbol {
                    name: str::from_utf8(&date).unwrap().to_string(),
                    detail: None,
                    kind: SymbolKind::VARIABLE,
                    tags: None,
                    deprecated: None,
                    range: lsp_range,
                    selection_range: lsp_range,
                    children: None,
                }
            })
            .collect();
        Ok(Some(DocumentSymbolResponse::Nested(symbols)))
    }

    async fn execute_command(&self, params: ExecuteCommandParams) -> Result<Option<Value>> {
        info!("outside ohyteah {:?}", params);
        if params.command == "custom.notification" {
            info!("ohyteah {:?}", params);
            self.client
                .show_message(MessageType::WARNING, "Wababalia")
                .await;
            self.client
                .log_message(
                    MessageType::WARNING,
                    format!("Command executed with params: {params:?}"),
                )
                .await;
            self.client
                .send_notification::<CustomNotification>(CustomNotificationParams::new(
                    "Hello", "Message",
                ))
                .await;
            self.client
                .log_message(
                    MessageType::INFO,
                    format!("Command executed with params: {params:?}"),
                )
                .await;
            Ok(None)
        } else {
            Err(Error::invalid_request())
        }
    }
}

#[tokio::main]
async fn main() {
    let file_appender = tracing_appender::rolling::daily("houls_logs", "houls.log");
    let (non_blocking, _guard) = tracing_appender::non_blocking(file_appender);
    tracing_subscriber::fmt().with_writer(non_blocking).init();
    info!("testitinfo");
    println!("thisonetoo");

    let stdin = tokio::io::stdin();
    let stdout = tokio::io::stdout();

    let (service, socket) = LspService::new(|client| Backend { client });
    Server::new(stdin, stdout, socket).serve(service).await;
}
