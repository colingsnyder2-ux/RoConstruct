from roc import analyze
from roc.boundaries import branch_merges, current_scores, seh_entries


def fixture():
    # Native 2008 CRobloxModule owner: branches, two virtual tail calls, one return.
    return bytes.fromhex(
        "e8bbadfbff8b803401000083e801741783e801752d"
        "8b4c24048b018b10c744240401000000ffe2"
        "e89493fbff84c07412"
        "8b4c24048b018b10c744240401000000ffe2c20400")


def test_exact_block_scores_and_old_bounds_do_not_prove_function_entries():
    base = 0x44ce20
    code = fixture() + b"\xcc" * 11 + b"\xc3"
    rows = analyze.find_functions(code, base, {base}, [],
        proven=[(0x44ce35, 18), (0x44ce50, 18)],
        keep={base, 0x44ce35, 0x44ce50, 0x44ce62})
    owner = next(row for row in rows if row["addr"] == "0044ce20")
    assert owner["size"] == 69
    assert owner["boundary_fragments"] == ["0044ce35", "0044ce47", "0044ce50", "0044ce62"]
    assert {row["addr"] for row in rows} == {"0044ce20", "0044ce70"}


def test_independently_referenced_entries_are_preserved():
    rows = [dict(addr="0044ce20", size=21, kind="code"),
            dict(addr="0044ce35", size=18, kind="code"),
            dict(addr="0044ce47", size=9, kind="code"),
            dict(addr="0044ce50", size=18, kind="code"),
            dict(addr="0044ce62", size=3, kind="code")]
    repairs = branch_merges(fixture(), 0x44ce20, rows, {0x44ce20, 0x44ce47})
    assert all("0044ce47" not in repair["fragments"] for repair in repairs)


def test_tiny_function_after_return_is_not_a_fragment():
    rows = [dict(addr="00001000", size=1, kind="code"), dict(addr="00001001", size=3, kind="code")]
    assert branch_merges(b"\xc3\xc2\x04\x00", 0x1000, rows, {0x1000}) == []


def test_only_unchanged_target_scores_survive_reanalysis():
    before = [dict(addr="owner", size=21), dict(addr="fragment", size=9), dict(addr="keep", size=8)]
    after = [dict(addr="owner", size=69), dict(addr="keep", size=8), dict(addr="new", size=12)]
    assert current_scores(before, after, {"owner": 100, "fragment": 100, "keep": 90, "new": 100}) == {"keep": 90}


def test_cleanup_prefix_after_register_reset_still_requires_parent_frame():
    assert analyze.kind_of(bytes.fromhex("33db8b7dd0"), []) == "eh"
    assert analyze.kind_of(bytes.fromhex("558bec8b7dd05dc3"), []) == "code"


def test_unreachable_gap_and_reviewed_data_prevent_merging():
    rows = [dict(addr="00001000", size=2, kind="code"), dict(addr="00001004", size=1, kind="code")]
    assert branch_merges(b"\xeb\x02\xcc\xcc\xc3", 0x1000, rows, {0x1000}) == []
    rows[1]["kind"] = "data"
    assert branch_merges(b"\x90\x90\x90\x90\xc3", 0x1000, rows, {0x1000}) == []


def test_stripped_adjacent_seh_stub_is_seeded_and_fake_padding_start_removed():
    import struct
    base, handler, info = 0x1000, 0x100e, 0x84e5cc
    prefix = bytes.fromhex("a1e88a8b0083e0fea3e88a8b00c3")
    stub = bytes.fromhex("8b5424088d028b4afc33c8e80000ffffb8") + struct.pack("<I", info) + bytes.fromhex("e90000ffff")
    code = prefix + stub + b"\xcc" * 8
    read = lambda address, size: (struct.pack("<III", 0x19930522, 1, 0x2000)[:size] if address == info else b"")
    assert seh_entries(code, base, read) == {handler}
    rows = analyze.find_functions(code, base, {base, handler}, [],
                                  proven=[(0x1020, 8)], keep={base, handler, 0x1020})
    assert "00001020" not in {row["addr"] for row in rows}
    assert any(row["addr"] == "0000100e" and row["size"] == len(stub) for row in rows)
    assert analyze.kind_of(stub, []) == "gen"
    assert not seh_entries(code, base, lambda address, size: b"\0" * size)
