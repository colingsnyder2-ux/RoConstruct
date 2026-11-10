import struct

import pytest

from roc import agent_recovery as recovery, match, rtti


def fixture(monkeypatch, tail=bytes.fromhex("8b45f464890d000000008be55dc3"), kind="eh"):
    prefix = bytes.fromhex("558bec64a100000000")
    code = prefix + b"\xe9" + struct.pack("<i", 0x1103 - (0x1000 + len(prefix) + 5))
    image = bytearray(0x200)
    image[:len(code)] = code
    image[0x103:0x103 + len(tail)] = tail
    rows = {"00001000": dict(addr="00001000", kind="code", size=len(code)),
            "00001100": dict(addr="00001100", kind=kind, size=len(tail) + 3)}
    monkeypatch.setattr(match, "_image", lambda client: (0x1000, bytes(image)))
    return code, rows


def test_excluded_normal_exit_inside_eh_row_is_review_evidence(monkeypatch):
    code, rows = fixture(monkeypatch)
    before = {addr: dict(row) for addr, row in rows.items()}
    review = recovery.frame_exit_review("C", "00001000", code, rows)
    assert review["normal_exit"] == "00001103"
    assert review["inventory_owner"] == "00001100"
    assert review["recorded_size"] == len(code) and review["candidate_only"]
    assert review["instructions"][-1].endswith("ret ")
    assert rows == before  # Evidence never rewrites inventory or score coverage.


@pytest.mark.parametrize("kind", ["code", "gen", "data"])
def test_independent_target_kind_is_not_treated_as_parent_exit(monkeypatch, kind):
    code, rows = fixture(monkeypatch, kind=kind)
    assert recovery.frame_exit_review("C", "00001000", code, rows) is None


@pytest.mark.parametrize("tail", [
    bytes.fromhex("558bec64890d000000008be55dc3"),  # Independent frame.
    bytes.fromhex("740064890d000000008be55dc3"),    # Unresolved branch.
    bytes.fromhex("8b45f48be55dc3"),                # No FS restoration.
    bytes.fromhex("64890d00000000c3"),             # No parent frame restoration.
])
def test_catch_and_incomplete_tail_shapes_are_not_promoted(monkeypatch, tail):
    code, rows = fixture(monkeypatch, tail=tail)
    assert recovery.frame_exit_review("C", "00001000", code, rows) is None


def test_plain_tail_call_never_reads_more_image(monkeypatch):
    monkeypatch.setattr(match, "_image", lambda client: pytest.fail("not a framed prefix"))
    assert recovery.frame_exit_review("C", "00001000", bytes.fromhex("e9fb000000"), {}) is None


@pytest.mark.parametrize("restore", [0x44, 0x40])
def test_conditional_exit_from_adjusted_ebp_frame_requires_matching_restore(monkeypatch, restore):
    # Native ContentProvider::loadContent: conditional normal exit precedes an
    # in-range retry jump; the LEA frame is restored only in the excluded row.
    prefix = bytes.fromhex("558d6c24bc83ec4464a100000000")
    branch = b"\x0f\x84" + struct.pack("<i", 0x1103 - (0x1000 + len(prefix) + 6))
    code = prefix + branch + bytes.fromhex("ebfe")
    tail = bytes.fromhex("8b4df464890d0000000083c5") + bytes([restore]) + bytes.fromhex("8be55dc22800")
    image = bytearray(0x200)
    image[:len(code)] = code
    image[0x103:0x103 + len(tail)] = tail
    rows = {"00001000": dict(addr="00001000", kind="code", size=len(code)),
            "00001100": dict(addr="00001100", kind="eh", size=len(tail) + 3)}
    monkeypatch.setattr(match, "_image", lambda client: (0x1000, bytes(image)))
    review = recovery.frame_exit_review("C", "00001000", code, rows)
    if restore == 0x44:
        assert review["normal_exit"] == "00001103"
        assert review["exit_end"] == "%08x" % (0x1103 + len(tail))
        assert review["candidate_only"]
    else:
        assert review is None


def test_adjusted_frame_requires_matching_entry_stack_reservation(monkeypatch):
    monkeypatch.setattr(match, "_image", lambda client: pytest.fail("entry frame mismatch"))
    code = bytes.fromhex("558d6c24bc83ec4064a100000000e900010000")
    assert recovery.frame_exit_review("C", "00001000", code, {}) is None


def test_packet_surfaces_extent_review_without_claiming_a_repair(tmp_path, monkeypatch):
    code, rows = fixture(monkeypatch)
    monkeypatch.setattr(match, "_functions", lambda client: rows)
    monkeypatch.setattr(match, "target", lambda client, addr: (code, [], rows[addr]))
    monkeypatch.setattr(rtti, "vtable_stores", lambda *args: [])
    packet = recovery.packet(tmp_path, "C", "00001000", "", {})
    assert packet["extent_review"]["normal_exit"] == "00001103"
    assert packet["extent_review"]["reason"] in packet["missing_evidence"]
