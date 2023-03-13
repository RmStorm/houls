# houls
A tree-sitter grammar and language server for a mini language. The langauge looks something like:

```houlang
01-01-01
mon: 07:15 - 08:45
tue: 08:20 - 09:00
```

I use monthly `.hou` files to keep track of the hours I work and wanted to experiment with tree-sitter and language servers. So I wrote a super minimal grammar to capture weeks, dates, days and hours and a language server that allows doing various trivial little things.

I use [helix](https://docs.helix-editor.com/title-page.html) as an editor and I've added this snippet to incorporate the lsp and the grammar:

```toml
[[language]]
name = "houlang"
language-server = { command = "/home/rmstorm/Documents/rust/houls/target/debug/houls" }
scope = "source.hou"
roots = []
file-types = ["hou"]

[[grammar]]
name = "houlang"
source = { path = "/home/rmstorm/Documents/rust/houls/tree-sitter-houlang" }
```

To build the grammar and parse the example file run:

```bash
cd tree-sitter-houlang
tree-sitter generate && hx --grammar build && tree-sitter parse example.hou
```

To build the language server and tail the logs run:

```bash
cargo build && tail -f houls_logs/houls.log.*
```