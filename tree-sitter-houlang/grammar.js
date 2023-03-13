module.exports = grammar({
  name: 'houlang',
  rules: {
    source_file: $ => repeat($.week),
    week: $ => seq($.date,  repeat1($.day_line)),
    day_line: $ =>  seq($.day, ': ', $.hour, ' - ', $.hour),
    day: $ => /[a-z]+/,
    hour: $ => /\d{1,2}:\d{1,2}/,
    date: $ => /\d+(-\d+)+/,
  }
})
