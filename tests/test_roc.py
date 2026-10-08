"""Smoke tests that need no client exe and no compiler. Run: python tests/test_roc.py"""
import re
import struct
import json
import sys
import time
from unittest.mock import patch
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent.parent))
from roc import auto, shapes, xcopy
from roc.analyze import find_functions, kind_of, demangle_class
from roc.analyze import asm_shape
from roc.auto import candidates
from roc import draft
from roc.draft import extract_code, mini_elf
from roc.match import coff_functions, score, asm_lines, reject_asm, CompileError
from roc.match import exact_match, similarity_ratio, diagnose
from roc import mutate
from roc import repair as _repair
from roc.draft import select_topk
from roc import metrics as _metrics


def test_repair_member_decl():
    fixed = _repair.ensure_member_declared("struct PAVX {\n    int* vtable;\n};\nint PAVX::f()\n{\n    return 0;\n}\n")
    assert fixed is not None and "int f();" in fixed
    # qualifier mismatch with a single class: S::f -> PAVX::f plus decl
    bad = "struct PAVX {\n    int* vtable;\n};\nint S::f()\n{\n    return 0;\n}\n"
    fixed = _repair.ensure_member_declared(bad)
    assert fixed is not None and "S::" not in fixed and "PAVX::f" in fixed
    # ambiguous with two classes: untouched
    two = "struct A {};\nstruct B {};\nint S::f()\n{\n    return 0;\n}\n"
    assert _repair.ensure_member_declared(two) is None


def test_repair_this_and_types():
    free = "int linked_f(Linked* this)\n{\n    return this->x;\n}\n"
    fixed = _repair.rename_this_identifier(free)
    assert fixed is not None and "this_" in fixed and re.search(r"\bthis\b", fixed) is None
    member = "struct S {\n    int f();\n};\nint S::f()\n{\n    return this->x;\n}\n"
    assert _repair.rename_this_identifier(member) is None  # valid use untouched
    typed = "struct H {\n    uint8_t b[4];\n    size_t n;\n};\nint H::g()\n{\n    return 0;\n}\n"
    fixed = _repair.add_fixedwidth_typedefs(typed)
    assert fixed is not None and "typedef unsigned char uint8_t;" in fixed
    assert _repair.nullptr_to_zero("int* p = nullptr;") == "int* p = 0;"
    assert _repair.parse_error_codes("source(7) : error C2039: x  source(8) : error C2143: y") == ["2039", "2143"]


def test_repair_sanitize_and_loop():
    src = "// roc-lib: seg_00430000\nint f()\n{\n    return 0;\n}\n"
    san, dropped = _repair.sanitize(src)
    assert dropped == 1 and "roc-lib" not in san
    calls = []
    def fake_check(client, addr, text, flags=None):
        calls.append(text)
        if "uint8_t" in text and "typedef" not in text:
            raise CompileError("source(4) : error C4430: missing type specifier")
        return 71, "f", "diff", []
    score, out, _, _, _, applied, err = _repair.repair_loop(
        "C", "1", "struct H {\n    uint8_t b;\n};\nint H::g()\n{\n    return 1;\n}\n",
        check=fake_check)
    assert err is None and score == 71 and "fixedwidth-typedefs" in applied
    assert len(calls) == 2  # no retry loop: one fail, one fixed recheck
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
    assert asm_shape(bytes.fromhex("8b442404c3"), 0x1000) == "mov eax, dword ptr [esp + N] ; ret"


def test_kinds():
    assert kind_of(bytes.fromhex("ff2500104000"), [2]) == "thunk"
    assert kind_of(bytes.fromhex("83e960e938ffffff"), []) == "adjustor"
    assert kind_of(bytes.fromhex("8b442404ff20"), []) == "thunk"                  # vcall thunk
    assert kind_of(bytes.fromhex("ff2500104000ff2504104000"), [2, 8]) == "thunk"  # glued import thunks
    assert kind_of(bytes.fromhex("836c240408e900000000"), []) == "adjustor"       # this-adjustor
    assert kind_of(bytes.fromhex("8b442404c3"), []) == "code"                     # real getter stays code
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
    assert any("m_x * 3" in c for c in candidates([
        "mov eax, dword ptr [ecx + 0x4]", "imul eax, eax, 3", "ret "]))
    assert any("m_x != 0" in c for c in candidates([
        "cmp dword ptr [ecx + 0x4], 0", "setne al", "movzx eax, al", "ret "]))
    assert any("m_x - 3" in c for c in candidates([
        "mov eax, dword ptr [ecx + 0x4]", "sub eax, 3", "ret "]))
    assert any("__stdcall" in c and "int a2" in c for c in candidates(["ret 8"]))
    assert candidates(["push ebp", "call sym"]) == []


def test_shapes_and_data():
    from roc.progress import union_bytes
    assert any("G1_NAME();" in c for c in candidates(["jmp sym"]))
    assert any("~S_NAME()" in c for c in candidates(["mov dword ptr [ecx], sym", "ret "]))
    eh = bytes.fromhex("8b5424088d42e88b4ae433c8e88d31ecffb8600c9000e97128ecff")  # real __ehhandler
    assert kind_of(eh, []) == "gen"
    assert union_bytes([[[100, 10], [105, 10]], [[200, 4]]]) == 19


def test_mass_helpers():
    from roc.mass import ar_members
    from roc.match import directives
    from roc.libs import source_for
    obj = fake_obj(bytes.fromhex("e800000000c3"), [1])
    member = lambda name, body: name.ljust(16).encode() + b" " * 32 + str(len(body)).ljust(10).encode() + b"`\n" + body + b"\n" * (len(body) & 1)
    lib = b"!<arch>\n" + member("/", b"\0" * 4) + member("a.obj/", obj) + member("b/", b"\0\0\xff\xff" + b"\0" * 20)
    assert list(ar_members(lib)) == [obj]
    assert directives("// x\n// roc-lang: c\n// roc-cl: 30729\nint a;") == {"lang": "c", "cl": "30729"}
    d = directives(source_for("zlib-1.2.3", "sub\\x.c", "c", 21022, "/O2 /GS- /MD"))
    assert d == {"lang": "c", "cl": "21022", "flags": "/O2 /GS- /MD", "lib": "zlib-1.2.3 sub/x.c"}, d


def test_draft_helpers():
    assert extract_code("text\n```cpp\nint f();\n```\nmore") == "int f();\n"
    assert extract_code("no code") is None
    elf = mini_elf(b"\xc3", 0x401234)
    assert elf[:4] == b"\x7fELF" and elf[0x1000 + 0x234] == 0xC3
    facts = draft.facts_from_asm(["mov eax, dword ptr [ecx + 0x34]", "call dword ptr [sym]", "ret 8"])
    assert facts["calls"] == 1 and facts["this_offsets"] == ["0x34"] and facts["returns"] == ["ret 8"]
    assert draft.model_profile("qwen2.5-coder:7b") == {"num_ctx": 6144, "num_predict": 1536}
    assert draft.model_profile("custom") == {"num_ctx": 8192, "num_predict": 2048}
    assert draft.model_rounds("qwen2.5-coder:7b-instruct", 9) == 3
    assert draft.classify_target(["mov eax, dword ptr [ecx + 0x4]", "ret "]) == "leaf/getter"
    assert draft.classify_target(["call sym", "ret "]) == "wrapper/thunk"


def test_model_choice(monkeypatch):
    from roc import draft
    monkeypatch.setattr(draft, "ollama_models", lambda: ["my-model", "qwen2.5-coder:7b"])
    assert draft.pick_model() == "qwen2.5-coder:7b"
    assert draft.pick_model("my-model") == "my-model"
    assert draft.pick_model("default") == "qwen2.5-coder:7b"
    monkeypatch.setattr(draft, "ollama_models", lambda: ["my-model"])
    assert draft.pick_model() == "my-model"


def test_link_options():
    from roc.link import choose_options
    with patch("roc.draft.ollama_models", return_value=["qwen2.5-coder:14b", "qwen2.5-coder:7b"]), \
         patch("roc.draft.pick_model", return_value="qwen2.5-coder:14b"), \
         patch("builtins.input", side_effect=["qwen2.5-coder:7b", "fast", "auto", "n"]):
        assert choose_options({"model": "qwen2.5-coder:14b"}) == ("qwen2.5-coder:7b", 2, 96, False, "auto")


def test_server_store():
    st = Store(":memory:", lease_seconds=1)
    st.db.executemany("INSERT INTO funcs(client,addr,size,unit) VALUES(?,?,?,?)",
                      [("C", "00401000", 6, "A"), ("C", "00401010", 8, "B"), ("C", "00401020", 4, "T")])
    a = st.lease("alice", "w1", ["C"], "ai", 256)
    b = st.lease("bob", "w2", ["C"], "ai", 256)
    assert {a["addr"], b["addr"]} == {"00401000", "00401010"}     # 4-byte 00401020 below the match floor, never leased
    assert st.lease("carol", "w3", ["C"], "ai", 256) is None      # both leasable ones leased
    time.sleep(1.1)                                                  # nobody heartbeats
    assert st.lease("carol", "w3", ["C"], "ai", 256) is not None  # expired lease frees up
    assert st.submit("C", "00401000", "alice", 60, "x") == (60, True)
    assert st.submit("C", "00401000", "bob", 50, "y") == (60, False)  # worse: ignored
    assert st.submit("C", "00401000", "bob", 100, "z") == (100, True)
    board = {r["user"]: r for r in st.leaderboard()}
    assert board["bob"]["matched"] == 1 and board["alice"]["points"] == 60
    assert [r["user"] for r in st.leaderboard("C")] == ["bob", "alice"] and st.leaderboard("other") == []
    assert st.lease("dave", "w4", ["C"], "ai", 4) is None  # matched one never handed out again
    assert st.examples("C", unit="A") and st.examples("C", unit="missing")
    st.db.execute("UPDATE funcs SET shape = 'same' WHERE addr = '00401000'")
    assert st.examples("C", shape="same")
    cool = Store(":memory:", lease_seconds=10)
    cool.db.execute("INSERT INTO funcs(client,addr,size,unit) VALUES('C','x',6,'A')")
    lease = cool.lease("alice", "cool", ["C"], "ai", 256)
    cool.release(lease["lease"], 30)
    assert cool.lease("bob", "next", ["C"], "ai", 256) is None
    fixed = Store(":memory:", lease_seconds=10)
    fixed.db.executemany("INSERT INTO funcs(client,addr,size,unit) VALUES(?,?,?,?)",
                         [("C", "00401000", 6, "A"), ("C", "00401010", 6, "B")])
    picked = fixed.lease("bench", "fixed", ["C"], "ai", 256,
                         model="qwen2.5-coder:7b",
                         targets=[{"client": "C", "addr": "00401010"}])
    assert picked["addr"] == "00401010"
    assert json.loads(fixed.db.execute("SELECT attempts_by_model FROM funcs WHERE addr='00401010'").fetchone()[0])
    guarded = Store(":memory:", lease_seconds=10)
    guarded.db.execute("INSERT INTO funcs(client,addr,size,unit) VALUES('C','00401000',6,'A')")
    lease = guarded.lease("alice", "guard", ["C"], "ai", 256)
    try:
        guarded.submit("C", "00401000", "alice", 100, "x", lease="wrong")
        raise AssertionError("expired/foreign lease accepted")
    except ValueError:
        pass
    assert guarded.submit("C", "00401000", "alice", 100, "x", lease=lease["lease"]) == (100, True)


def test_shape_normalisation():
    # Same code with different constants must collapse to one shape, or the counts that
    # decide which template to write next are meaningless.
    a = ["mov eax, dword ptr [sym]", "push eax", "call sym", "add esp, 4",
         "mov dword ptr [sym], sym", "ret "]
    b = ["mov eax, dword ptr [sym]", "push eax", "call sym", "add esp, 8",
         "mov dword ptr [sym], sym", "ret "]
    assert shapes.shape_from_lines(a) == shapes.shape_from_lines(b)
    c = ["mov eax, dword ptr [sym]", "push eax", "call sym", "add esp, 4", "ret "]
    assert shapes.shape_from_lines(a) != shapes.shape_from_lines(c)
    # `ret 8` and `ret` are the same shape: the cleanup is implied by the arguments.
    d = ["mov eax, dword ptr [sym]", "push eax", "call sym", "add esp, 4",
         "mov dword ptr [sym], sym", "ret 8"]
    assert shapes.shape_from_lines(d) == shapes.shape_from_lines(a)
    # A member offset is not a constant and must survive normalisation, or every
    # `this->field` shape would collapse into one useless bucket.
    assert shapes.norm_line("mov dword ptr [ecx + 4], eax") == "mov dword ptr [ecx + #], eax"
    assert shapes.norm_line("mov dword ptr [ecx], eax") == "mov dword ptr [ecx], eax"
    assert shapes.norm_line("push 0") == "push #"
    # A relocated operand prints as `sym` already and must stay as it is.
    assert shapes.norm_line("call sym") == "call sym"
    # Runs of identical normalised lines collapse, so a zero-initialiser chain over
    # several fields is one shape rather than one per field count.
    r = ["mov dword ptr [ecx], 0", "mov dword ptr [ecx + 4], 0", "mov dword ptr [ecx + 8], 0"]
    assert shapes.shape_from_lines(r) == ("mov dword ptr [ecx], #", "mov dword ptr [ecx + #], #")


def test_xcopy_ordering():
    reg = {"A": {"compiler_build": 21022}, "B": {"compiler_build": 30729}}
    own = ("// own\nvoid f(){}\n", [("A", "00000001")])
    same = ("// same\nvoid g(){}\n", [("B", "00000002")])
    other = ("// other\nvoid h(){}\n", [("A", "00000003")])
    ordered = xcopy._order([own, same, other], "A", reg)
    assert ordered[0][0] == own[0], "a client's own sources must be tried first"
    # A source declaring its own compiler (library code) is grouped by that, not the
    # client it happened to be matched in.
    lib = ("// roc-cl: 30729\nvoid k(){}\n", [("A", "00000004")])
    assert xcopy._build_of(lib[0], lib[1], reg) == 30729
    assert xcopy._build_of(*own, reg) == 21022


def test_xcopy_batching_isolates_collisions():
    reg = {"A": {"compiler_build": 21022}}
    # Two candidates declaring the same name with different types: a single translation
    # unit without namespaces is C2371 and the whole chunk is lost.
    collide = [("extern int G1_VALUE;\nvoid NAME(){ G1_VALUE = 1; }\n", []),
               ("extern char* G1_VALUE;\nvoid NAME(){ G1_VALUE = 0; }\n", [])]
    text, by_tag = xcopy._batch_cpp(collide)
    assert text.count("namespace ns_ROCX") == 2, "each candidate needs its own namespace"
    assert set(by_tag) == {"ROCX000000", "ROCX000001"}
    # C has no namespaces, so it is compiled one source per unit instead.
    c_src, c_by = xcopy._batch_alone("extern int G1_VALUE;\nvoid NAME(){ G1_VALUE = 1; }\n")
    assert "namespace" not in c_src and len(c_by) == 1
    assert xcopy._lang("// roc-lang: c\nvoid f(){}\n") == "c"
    assert xcopy._lang("void f(){}\n") == "cpp"
    # A system header inside a namespace breaks the CRT headers ("fpos_t is not a member
    # of global namespace"), so anything with an include is compiled on its own too.
    stl = "#include <vector>\nstruct E { int v[4]; };\ntemplate class std::vector<E>;\n"
    assert xcopy.needs_global_scope(stl)
    assert not xcopy.needs_global_scope("extern int G;\nvoid f(){}\n")
    assert xcopy.needs_global_scope("// roc-lang: c\nvoid f(){}\n")


def test_auto_build_unit_isolates_redefinitions():
    # Two candidates using the same placeholder global with different types must not
    # kill the chunk: that silently lost whole 400-candidate batches.
    a = ("F0000001_0", "extern int G1_VALUE;\nvoid NAME(){ G1_VALUE = 1; }\n")
    b = ("F0000002_0", "extern char* G1_VALUE;\nvoid NAME(){ G1_VALUE = 0; }\n")
    unit = auto.build_unit([a, b])
    assert unit.count("namespace n") == 2
    assert "void F0000001_0(" in unit and "void F0000002_0(" in unit


def test_refsource_name_recovery():
    from roc import refsource
    # real names recoverable from mangled unit names, A6A/W markers stripped
    assert "VInstance" in refsource.identifiers("RBX::VInstance::?$NonFactoryProduct")
    assert "RakPeer" in refsource.identifiers("RakNet::RakPeer")
    assert "VColor3" in refsource.identifiers("A6AXVColor3")
    # anonymous units carry no UpperCamelCase name
    anon = refsource.identifiers("?func_0077cd30@@YAXXZ")
    assert not [n for n in anon if n and n[0].isupper()]
    # _plausible keeps only names present in the tree, longest first
    assert refsource._plausible(["nstance", "VInstance"], {"VInstance": []}) == ["VInstance"]
    if refsource.TREE.exists():
        body = refsource.extract_method("ROBLOX2016-main\\Network\\raknet\\Source\\RakPeer.cpp", "RakPeer")
        assert body and len(body) <= 6000
        context = refsource.extract_method_context("ROBLOX2016-main\\Network\\raknet\\Source\\RakPeer.cpp", "RakPeer")
        assert context and len(context) <= 12000


def test_model_routing():
    from roc import draft
    assert draft.route_model("qwen2.5-coder:14b", {"size": 32, "calls": 0},
                             ["qwen2.5-coder:7b"]) == "qwen2.5-coder:7b"
    assert draft.route_model("custom", {"size": 32, "calls": 0},
                             ["qwen2.5-coder:7b"], automatic=False) == "custom"


def test_refsource_hint_without_tree(tmp_path, monkeypatch):
    # hint() returns None instead of crashing when the 2016 tree isn't on this PC
    from roc import refsource
    refsource.hint.cache_clear()
    monkeypatch.setattr(refsource, "TREE", tmp_path / "nope")
    monkeypatch.setattr(refsource, "CACHE", tmp_path / "cache.json")
    assert refsource.hint("RBX::Network::Replicator") is None
    assert refsource.prompt_hints("seg_00400000") == []


def test_exact_match_separate_from_fuzzy():
    a = bytes.fromhex("8b442404c3")
    assert exact_match(a, [], a, []) and score(a, [], a, []) == 100
    assert similarity_ratio(a, [], a, []) == 1.0
    b = bytes.fromhex("33c0c3")
    assert not exact_match(b, [], a, [])
    assert 0.0 <= similarity_ratio(b, [], a, []) < 1.0
    assert score(b, [], a, []) < 100
    d = diagnose(b, [], a, [])
    assert d["exact"] is False and d["target_insns"] == 2
    assert "xor" in d["opcode_delta"] or "mov" in d["opcode_delta"]


def test_mutate_validated():
    src = "struct S{ char m_x; }; int S::f(){ return m_x != 0; }"
    vs = mutate.variants(src)
    assert 1 <= len(vs) <= 4 and any("unsigned char" in v for v in vs)
    calls = []
    def fake_check(c, a, t, f=None):
        calls.append(t)
        if "unsigned char" in t:
            return (90, None, None, None)
        return (50, None, None, None)
    best, out, tried = mutate.improve("C", "1", src, check=fake_check)
    assert (best, tried) == (90, len(vs)) and "unsigned char" in out
    def boom(c, a, t, f=None):
        raise CompileError("nope")
    assert mutate.improve("C", "1", src, check=boom)[0] == 0


def test_topk_and_benchmark_summary():
    topk = select_topk([(50, "a"), (90, "b"), (90, "b "), (70, "c")])
    assert topk == [(90, "b"), (70, "c"), (50, "a")]
    jobs = [{"score": 100, "seconds": 10.0, "rounds": [{"round": 1, "score": 100, "code": True}]},
            {"score": 0, "seconds": 20.0, "rounds": [{"round": 1, "score": 0, "code": True,
                                                      "compile_error": "C2039"}]}]
    s = _metrics.summarize_runs(jobs)
    assert s["jobs"] == 2 and s["matched"] == 1 and s["seconds_per_match"] == 30.0
    assert s["compile_success_rate"] == 0.5


if __name__ == "__main__":
    import inspect
    for name, fn in list(globals().items()):
        if name.startswith("test_"):
            if inspect.signature(fn).parameters:
                continue  # needs pytest fixtures; run under pytest
            fn()
            print("ok ", name)
