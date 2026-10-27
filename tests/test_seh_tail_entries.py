import struct

from capstone import CS_ARCH_X86, CS_MODE_32, Cs

from roc import analyze


def image(dispatcher):
    code = bytearray(b"\x90" * 0xb0)
    code[:len(dispatcher)] = dispatcher
    prologue = (b"\x6a\xff\x68" + struct.pack("<I", 0x10a0)
                + b"\x64\xa1\0\0\0\0\x50\x64\x89\x25\0\0\0\0\xc3")
    code[0x40:0x40 + len(prologue)] = prologue
    code[0x80:0x80 + len(prologue)] = prologue
    return bytes(code)


def entries(code):
    return analyze.seh_tail_entries(code, 0x1000, 0x1000, Cs(CS_ARCH_X86, CS_MODE_32))


def test_two_tail_called_methods_need_no_padding_between_them():
    # test eax,eax; je local second jump; jmp 1040; jmp 1080
    code = image(b"\x85\xc0\x74\x05\xe9\x37\0\0\0\xe9\x72\0\0\0")
    assert entries(code) == {0x1040, 0x1080}
    rows = analyze.find_functions(code, 0x1000, {0x1000}, [], keep={0x1000})
    assert {"00001040", "00001080"} <= {row["addr"] for row in rows}


def test_stack_frame_or_nonvolatile_write_is_not_a_leaf_dispatcher():
    assert not entries(image(b"\x55\xe9\x3a\0\0\0"))
    assert not entries(image(b"\x31\xdb\xe9\x39\0\0\0"))
    assert not entries(image(b"\x89\x01\xe9\x39\0\0\0"))


def test_every_branch_must_keep_the_frame_intact():
    # One branch tail calls, another pushes a frame.
    assert not entries(image(b"\x85\xc0\x74\x05\xe9\x37\0\0\0\x55\xc3"))


def test_plain_loop_unaligned_target_and_bad_handler_are_rejected():
    assert not entries(image(b"\xeb\xfe"))
    assert not entries(image(b"\xe9\x3c\0\0\0"))
    code = bytearray(image(b"\xe9\x3b\0\0\0"))
    code[0x43:0x47] = struct.pack("<I", 0x2000)
    assert not entries(bytes(code))
