from benchmarks.g3d_header_repair import assertion_lines
from benchmarks.library_fill import assert_lines


def test_multiline_assertion_ignores_literal_and_comment_parentheses():
    lines = ["int value = 3;", "alwaysAssertM((value > 0), /* ) */", '    "message with ( and )");', "consume(3);"]
    assert assertion_lines(lines) == {2, 3}
    marked = [line + " // assertion" if number in assertion_lines(lines) else line
              for number, line in enumerate(lines, 1)]
    assert assert_lines(b"\x68\x04\x00\x00\x00", {}, b"\x68\x03\x00\x00\x00", {}, marked) == {3: 4}
    assert assert_lines(b"\x68\x05\x00\x00\x00", {}, b"\x68\x04\x00\x00\x00", {}, marked) is None
