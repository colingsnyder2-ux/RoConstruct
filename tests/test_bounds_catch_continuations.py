import copy
import struct

import pytest

from roc.bounds_proof import owned_catch_merges


def fixture(return_to=0x1010, handler=0x2000):
    image = b"\x6a\xff\x68" + struct.pack("<I", 0x2000) + b"\x90" * 9
    image += b"\xeb\xee" + b"\x90" * 14
    image += b"\xb8" + struct.pack("<I", return_to) + b"\xc3"
    rows = [dict(addr="00001000", size=16, kind="code", relocs=[3], calls=0),
            dict(addr="00001010", size=16, kind="eh", relocs=[], calls=0),
            dict(addr="00001020", size=6, kind="eh", relocs=[1], calls=0)]
    read = lambda address, size: image[address - 0x1000:address - 0x1000 + size]
    return rows, {0x1020: [dict(handler=handler)]}, read


def test_owned_catch_return_proves_preceding_continuation():
    rows, handlers, read = fixture()
    result = owned_catch_merges(rows, handlers, read)
    assert result[0]["absorbs"] == ["00001010", "00001020"]
    assert len(rows) == 1
    assert rows[0]["size"] == 38
    assert rows[0]["relocs"] == [3, 33]


@pytest.mark.parametrize("return_to,handler", [(0x1011, 0x2000), (0x1010, 0x3000)])
def test_unrelated_return_or_handler_does_not_prove_ownership(return_to, handler):
    rows, handlers, read = fixture(return_to, handler)
    original = copy.deepcopy(rows)
    assert owned_catch_merges(rows, handlers, read) == []
    assert rows == original


@pytest.mark.parametrize("locked", [(0x1000,), (0x1010,), (0x1020,)])
def test_exact_owner_or_fragment_is_preserved(locked):
    rows, handlers, read = fixture()
    original = copy.deepcopy(rows)
    assert owned_catch_merges(rows, handlers, read, locked) == []
    assert rows == original


def test_intervening_code_row_is_not_absorbed():
    rows, handlers, read = fixture()
    rows[1]["kind"] = "code"
    assert owned_catch_merges(rows, handlers, read) == []


def test_unreachable_mov_ret_after_jump_is_not_a_continuation_proof():
    rows, handlers, original_read = fixture()
    rows[2]["size"] = 8
    read = lambda address, size: (b"\xeb\x06\xb8\x10\x10\x00\x00\xc3"[:size]
                                  if address == 0x1020 else original_read(address, size))
    assert owned_catch_merges(rows, handlers, read) == []


def test_original_catch_then_continuation_still_merges():
    rows, handlers, read = fixture()
    handlers = {0x1010: [dict(handler=0x2000)]}
    assert owned_catch_merges(rows, handlers, read)[0]["absorbs"] == ["00001010", "00001020"]
