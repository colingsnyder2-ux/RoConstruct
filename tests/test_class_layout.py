from benchmarks.class_layout import candidates, displacement_map


def test_consistent_fields_and_stack_guard():
    # Two this fields shift by eight bytes.
    assert displacement_map(bytes.fromhex("8b41148b5118c3"), bytes.fromhex("8b410c8b5110c3")) == {12: 20, 16: 24}
    # A changed stack argument is ABI evidence, never a class field.
    assert displacement_map(bytes.fromhex("8b442408c3"), bytes.fromhex("8b442404c3")) == {}
    # One donor offset cannot map to two different target fields.
    assert displacement_map(bytes.fromhex("8b41148b5118c3"), bytes.fromhex("8b410c8b510cc3")) == {}
    assert displacement_map(bytes.fromhex("8b8100004000c3"), bytes.fromhex("8b410cc3")) == {}


def test_padding_and_simultaneous_offset_rewrite():
    source = "struct S { char pad[12]; int x; }; int f() { return 0xc + 0x10; }"
    variants = dict(candidates(source, {12: 16, 16: 20}))
    assert "0x10 + 0x14" in variants["explicit-offsets"]
    assert "pad[16]" in variants["padding-shift"]
