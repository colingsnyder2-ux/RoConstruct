from roc import twinpatch


def test_pairs_come_only_from_numeric_operand_differences():
    # shr ebp, 9 / shr ebp, 0xf ; same mov ; a jump and an address never count
    twin = bytes.fromhex("c1ed09" "8bc1" "c705" "00104000" "01000000")
    target = bytes.fromhex("c1ed0f" "8bc1" "c705" "00204000" "01000000")
    assert twinpatch.constant_pairs(twin, target) == {(9, 15)}


def test_substitutions_try_each_spot_and_keep_hex_spelling():
    out = dict(twinpatch.substitutions("a = (x >> 9) & 7; b = 9; c = 0x9;", {(9, 15)}))
    assert "a = (x >> 15) & 7; b = 9; c = 0x9;" in out.values()
    assert "a = (x >> 9) & 7; b = 9; c = 0xf;" in out.values()
    assert all("15) & 15" not in text for text in out.values())
