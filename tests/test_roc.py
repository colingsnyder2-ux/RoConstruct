"""Smoke tests that need no client exe and no compiler. Run: python tests/test_roc.py"""
import struct
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent.parent))
from roc.analyze import find_functions, kind_of, demangle_class
from roc.auto import candidates
from roc.draft import extract_code, mini_elf
from roc.match import coff_functions, score, asm_lines, reject_asm, CompileError
from roc.progress import summarize
from roc.server import Store


def test_find_functions():
    base = 0x1000
    code = bytes.fromhex(
        "e807000000"        # 1000: call 100c
        "a1" "00200000"     # 1005: mov eax, [2000]  (reloc at 1006)
        "c3"                # 100a: ret
        "cc"                # 100b: padding
        "33c0" "c3"         # 100c: xor eax,eax; ret
        "cc"                # padding to 16
        "c3"                # 1010: ret, no caller: found by alignment
    )
    funcs = find_functions(code, base, {base}, [0x1006])
    assert funcs == [
        {"addr": "00001000", "size": 11, "relocs": [6], "calls": 1, "kind": "code"},
        {"addr": "0000100c", "size": 3, "relocs": [], "calls": 0, "kind": "code"},
        {"addr": "00001010", "size": 1, "relocs": [], "calls": 0, "kind": "code"},
    ], funcs


def test_kinds():
    assert kind_of(bytes.fromhex("ff2500104000"), [2]) == "thunk"
    assert kind_of(bytes.fromhex("83e960e938ffffff"), []) == "adjustor"
    assert kind_of(bytes.fromhex("8b4dd8e9d868c7ff"), []) == "eh"
    assert kind_of(bytes.fromhex("ff"), []) == "bad"
    assert kind_of(bytes.fromhex("8b4144c3"), []) == "code"
    assert demangle_class(".?AVInstance@RBX@@") == "RBX::Instance"


def test_summarize():
    s = summarize([[0x1000, 10, 100], [0x1010, 5, 40], [0x1020, 5, 0]])
    assert s == {"functions": 3, "matched": 1, "partial": 1, "bytes": 20, "matched_bytes": 10}, s


def fake_obj(code, relocs):
    """Minimal i386 COFF: one section, one function symbol `_f`."""
    relptr = 60 + len(code)
    symptr = relptr + 10 * len(relocs)
    head = struct.pack("<HHIIIHH", 0x14C, 1, 0, symptr, 1, 0, 0)
    sec = struct.pack("<8sIIIIIIHHI", b".text$mn", 0, 0, len(code), 60, relptr, 0, len(relocs), 0, 0x60500020)
    rel = b"".join(struct.pack("<IIH", r, 0, 0x14) for r in relocs)
    sym = struct.pack("<8sIhHBB", b"_f", 0, 1, 0x20, 2, 0)
    return head + sec + code + rel + sym + struct.pack("<I", 4)


def test_match():
    obj = fake_obj(bytes.fromhex("e800000000c3"), [1])
    [(name, code, relocs)] = coff_functions(obj)
    assert (name, relocs) == ("_f", [1]), (name, relocs)
    # Same call to a different target in the exe: masked, so 100.
    assert score(bytes.fromhex("e812345678c3"), [], code, relocs) == 100
    assert score(bytes.fromhex("e812345678c2"), [], code, relocs) < 100
    assert asm_lines(bytes.fromhex("a100104000c3"), [1]) == ["mov eax, dword ptr [sym]", "ret "]
    reject_asm("#include <string>\n")
    for bad in ("__asm { nop }", "_emit 0x90", '#include "C:/secret.txt"', "#import <x.tlb>",
                '#pragma comment(lib, "x")'):
        try:
            reject_asm(bad)
            raise AssertionError(bad)
        except CompileError:
            pass
    reject_asm("int masm_count;")


def test_auto_candidates():
    assert any("return m_x;" in c and "pad0[68]" in c
               for c in candidates(["mov eax, dword ptr [ecx + 0x44]", "ret "]))
    assert any("{\n}" in c for c in candidates(["ret "]))
    assert any("__stdcall" in c and "int a2" in c for c in candidates(["ret 8"]))
    assert candidates(["push ebp", "call sym"]) == []


def test_draft_helpers():
    assert extract_code("text\n```cpp\nint f();\n```\nmore") == "int f();\n"
    assert extract_code("no code") is None
    elf = mini_elf(b"\xc3", 0x401234)
    assert elf[:4] == b"\x7fELF" and elf[0x1000 + 0x234] == 0xC3


def test_server_store():
    st = Store(":memory:", lease_seconds=1)
    st.db.executemany("INSERT INTO funcs(client,addr,size,unit) VALUES(?,?,?,?)",
                      [("C", "00401000", 4, "A"), ("C", "00401010", 8, "B")])
    a = st.lease("alice", "w1", ["C"], "ai", 256)
    b = st.lease("bob", "w2", ["C"], "ai", 256)
    assert {a["addr"], b["addr"]} == {"00401000", "00401010"}
    assert st.lease("carol", "w3", ["C"], "ai", 256) is None      # both leased
    time.sleep(1.1)                                                  # nobody heartbeats
    assert st.lease("carol", "w3", ["C"], "ai", 256) is not None  # expired lease frees up
    assert st.submit("C", "00401000", "alice", 60, "x") == (60, True)
    assert st.submit("C", "00401000", "bob", 50, "y") == (60, False)  # worse: ignored
    assert st.submit("C", "00401000", "bob", 100, "z") == (100, True)
    board = {r["user"]: r for r in st.leaderboard()}
    assert board["bob"]["matched"] == 1 and board["alice"]["points"] == 60
    assert st.lease("dave", "w4", ["C"], "ai", 4) is None  # matched one never handed out again


if __name__ == "__main__":
    for name, fn in list(globals().items()):
        if name.startswith("test_"):
            fn()
            print("ok ", name)
