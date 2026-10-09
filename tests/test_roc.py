"""Smoke tests that need no client exe and no compiler. Run: python tests/test_roc.py"""
import re
import os
import shutil
import struct
import json
import sys
import time
import tempfile
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
from roc.server import Store, make_handler


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
    assert s == {"functions": 3, "matched": 1, "partial": 1, "bytes": 20, "matched_bytes": 10,
                 "source_bytes": 0, "mined_bytes": 10, "partial_bytes": 5}, s


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
    from roc.draft import reconstruction_outline
    outline = reconstruction_outline(["ret 0x10"])
    assert "callee pops 4 stack arg(s)" in outline and "cdecl" not in outline
    assert extract_code("text\n```cpp\nint f();\n```\nmore") == "int f();\n"
    assert extract_code("no code") is None
    assert extract_code("Here is the answer:\nint f() { return 1; }\n") == "int f() { return 1; }\n"
    assert "struct S" in extract_code("struct S { int f(); };\nint S::f() { return 1; }\n")
    plain = ('extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);\n'
             '#pragma intrinsic(_InterlockedExchangeAdd)\n'
             'struct Inner { long count; };\nstruct S { Inner* p; int f(); };\n'
             'int S::f() { return _InterlockedExchangeAdd(&p->count, -1); }\n')
    assert extract_code("Generated source:\n" + plain) == plain
    elf = mini_elf(b"\xc3", 0x401234)
    assert elf[:4] == b"\x7fELF" and elf[0x1000 + 0x234] == 0xC3
    facts = draft.facts_from_asm(["mov eax, dword ptr [ecx + 0x34]", "call dword ptr [sym]", "ret 8"])
    assert facts["calls"] == 1 and facts["this_offsets"] == ["0x34"] and facts["returns"] == ["ret 8"]
    assert draft.model_profile("qwen2.5-coder:7b") == {"num_ctx": 6144, "num_predict": 1536}
    assert draft.model_profile("custom") == {"num_ctx": 8192, "num_predict": 2048}
    assert draft.model_rounds("qwen2.5-coder:7b-instruct", 9) == 3
    assert draft.select_generation_strategy("auto", "deepseek:deepseek-flash", {"size": 32}) == "structured"
    assert draft.select_generation_strategy("auto", "deepseek:deepseek-flash", {"size": 33}) == "direct"
    assert draft.select_generation_strategy("auto", "qwen2.5-coder:7b", {"size": 16}) == "direct"
    assert draft.classify_target(["mov eax, dword ptr [ecx + 0x4]", "ret "]) == "leaf/getter"
    assert draft.classify_target(["call sym", "ret "]) == "wrapper/thunk"
    assert "struct Namespace::Type" in draft.RULES
    outline = draft.reconstruction_outline(["mov eax, dword ptr [ecx + 4]", "jne sym", "ret 8"])
    assert "ECX dereferenced" in outline and "callee pops 2" in outline and "jne sym" in outline
    outlined = draft.reconstruction_outline(["00401000  8b4104               mov eax, dword ptr [ecx + 4]",
                                              "00401003  7502                 jne 0x401007", "00401005  c20800               ret 8"])
    assert "branches: jne 0x401007" in outlined
    cfg = draft.cfg_outline(["00401000  7502                 jne 0x401004", "00401002  c3                   ret ",
                             "00401004  ebfa                 jmp 0x401000"])
    assert "B0@00401000:B2/B1" in cfg and "loops=B2->B0" in cfg
    graph = draft.cfg_facts(["00401000  7502                 jne 0x401004", "00401002  c3                   ret ",
                            "00401004  ebfa                 jmp 0x401000"])
    assert graph["reachable"] == [0, 1, 2] and graph["loop_headers"] == [0]
    assert graph["dominators"]["2"] == [0, 2]
    assert draft.semantic_facts(["mov eax, 4", "add eax, 8", "xor ecx, ecx"]) == [
        "eax=4", "eax=(4 + 8)", "ecx=0"]
    constraints = draft.type_constraints(["jb sym", "ret 8"], {"this_reads": [4], "stack_args": [8],
                                                            "virtual_slots": [3], "returns": ["ret 8"]})
    assert "ECX receiver" in constraints and "unsigned branch" in constraints and "virtual slots 3" in constraints
    ir = draft.structure_ir(["00401000  8b4104               mov eax, dword ptr [ecx + 4]",
                             "00401003  7202                 jb 0x401007", "00401005  c20800               ret 8"], facts)
    assert ir["branches"][0]["unsigned"] and ir["receiver_offsets"] == ["0x34"]
    assert ir["signature"]["receiver"] and ir["signature"]["return_instruction"] == "ret 8"
    assert draft.source_contract_error("struct S { int x; };") == "missing function definition"
    assert not draft.source_contract_error("int f(){ return 0; }")
    assert "pseudo-instruction" in draft.source_contract_error("int f(){ push(1); return 0; }")
    sprawl = "struct S {\n" + "\n".join("int field_%d;" % i for i in range(20)) + "\n};\nint f(){return 0;}"
    assert "numbered-field" in draft.source_contract_error(sprawl)
    assert draft.compile_failure_class("error C2227") == "receiver/object pointer misuse"


def test_opcode_family_grouping():
    from roc import families
    asm = ["00401000  8b01                 mov eax, [ecx]",
           "00401002  c3                   ret"]
    assert families.opcode_shape(asm) == ("mov", "ret")
    rows = [{"addr": "00401000", "size": 3}, {"addr": "00401010", "size": 3},
            {"addr": "00401020", "size": 5}]
    reps = families.representatives(rows, lambda row: asm if row["size"] == 3 else ["ret"])
    assert len(reps) == 1 and reps[0][2][0]["addr"] == "00401000"
    assert families.fingerprint(rows[0], asm) == families.fingerprint(rows[1], asm)
    assert families.fingerprint(rows[0], ["ret"]) != families.fingerprint(rows[0], asm)


def test_family_propagation_rewrites_only_equal_literal_shapes():
    from roc import auto
    source = "void f(){ *(int*)0x1111 = 0x2222; }"
    assert auto.family_propagate(["mov dword ptr [0x3333], 0x4444", "ret"], source) == \
        "void f(){ *(int*)0x3333 = 0x4444; }"
    assert auto.family_propagate(["ret"], source) is None


def test_draft_rejects_inline_asm(monkeypatch):
    from roc import draft
    calls = []
    def ask(*args):
        calls.append(args)
        return "```cpp\nvoid f(){ __asm { nop } }\n```", "old-context"
    monkeypatch.setattr(draft, "_ask_context", ask)
    monkeypatch.setattr(draft.match, "target", lambda *args: (b"\xc3", [], {"size": 1, "unit": "x"}))
    monkeypatch.setattr(draft.match, "disasm", lambda *args: ["ret "])
    monkeypatch.setattr(draft, "prompt_for", lambda *args, **kwargs: args[5][0] if args[5] else "initial")
    stats = []
    score, source = draft.llm_rounds("C", "1", "model", 2, stats=stats, log=lambda *_: None)
    assert score == 0 and source is None and stats[0]["rejected_asm"]
    assert [call[2] for call in calls] == [None, None]
    assert "__asm" not in calls[1][1]


def test_draft_stops_at_code_fence(monkeypatch):
    from roc import draft
    class Stream:
        def __init__(self):
            self.rows = iter([b'{"response":"```cpp\\nint f(){}\\n```"}\n',
                              b'{"response":"ignored"}\n'])
        def __enter__(self): return self
        def __exit__(self, *_): return None
        def __iter__(self): return self
        def __next__(self): return next(self.rows)
    monkeypatch.setattr(draft.urllib.request, "urlopen", lambda *args, **kwargs: Stream())
    reply, context = draft._ask_context("model", "prompt")
    assert reply.endswith("```") and context is None


def test_cloud_tiny_job_keeps_full_output_budget(monkeypatch):
    from roc import draft
    seen = []
    def ask(model, prompt, context=None, options=None, details=False):
        seen.append(dict(options or {}))
        return "no code here", None, {"output_tokens": 1, "finish_reason": "stop"}
    monkeypatch.setattr(draft, "_ask_context", ask)
    monkeypatch.setattr(draft.match, "target", lambda *args: (b"\xc3", [], {"size": 9, "unit": "x"}))
    monkeypatch.setattr(draft.match, "disasm", lambda *args: ["ret "])
    monkeypatch.setattr(draft.match.clients, "load", lambda: {"C": {"compiler": "cl", "flags": "/O2"}})
    monkeypatch.setattr(draft, "prompt_for", lambda *args, **kwargs: "prompt")
    logs = []
    draft.llm_rounds("C", "1", "deepseek:deepseek-flash", 1, log=logs.append,
                     provider_options={"allow_cloud": True})
    assert seen and seen[0].get("max_tokens", 0) >= 1024
    draft.llm_rounds("C", "1", "qwen2.5-coder:7b", 1, log=lambda *_: None)
    assert seen[-1].get("max_tokens", 0) == draft.output_budget(9)


def test_budget_refunds_token_overestimate():
    from roc import providers
    budget = providers.CloudBudget(requests=5, tokens=20000)
    ticket = budget.reserve(16000)  # reserve books input estimate + max_tokens
    budget.settle(ticket, 3000)      # measured usage was much smaller
    assert budget.tokens == 3000
    ticket = budget.reserve(16000)   # overestimate refunded: budget still usable
    assert budget.tokens == 19000


def test_output_budget_override_and_truncation_flags(monkeypatch):
    from roc import draft
    seen = []
    def ask(model, prompt, context=None, options=None, details=False):
        seen.append(dict(options or {}))
        return "", None, {"output_tokens": 1024, "finish_reason": "length"}
    monkeypatch.setattr(draft, "_ask_context", ask)
    monkeypatch.setattr(draft.match, "target", lambda *args: (b"\xc3", [], {"size": 200, "unit": "x"}))
    monkeypatch.setattr(draft.match, "disasm", lambda *args: ["ret "])
    monkeypatch.setattr(draft.match.clients, "load", lambda: {"C": {"compiler": "cl", "flags": "/O2"}})
    monkeypatch.setattr(draft, "prompt_for", lambda *args, **kwargs: "prompt")
    stats = []
    draft.llm_rounds("C", "1", "deepseek:deepseek-flash", 1, stats=stats,
                     log=lambda *_: None,
                     provider_options={"allow_cloud": True, "max_tokens": 4096})
    assert seen and seen[0].get("max_tokens") == 4096
    empty = next(row for row in stats if isinstance(row.get("round"), int))
    assert empty["truncated"] is True and empty["empty_reply"] is True
    assert empty["code"] is False and empty["finish_reason"] == "length"


def test_thinking_disabled_by_default_for_cloud(monkeypatch):
    """Reasoning expands to fill any output budget, so cloud generation disables
    it by default for every size; explicit thinking=enabled stays opt-in."""
    from roc import draft
    seen = []
    def ask(model, prompt, context=None, options=None, details=False):
        seen.append(dict(options or {}))
        return "no code", None, {"output_tokens": 1, "finish_reason": "stop"}
    monkeypatch.setattr(draft, "_ask_context", ask)
    monkeypatch.setattr(draft.match, "target", lambda *args: (b"\xc3", [], {"size": 200, "unit": "x"}))
    monkeypatch.setattr(draft.match, "disasm", lambda *args: ["ret "])
    monkeypatch.setattr(draft.match.clients, "load", lambda: {"C": {"compiler": "cl", "flags": "/O2"}})
    monkeypatch.setattr(draft, "prompt_for", lambda *args, **kwargs: "prompt")
    draft.llm_rounds("C", "1", "deepseek:deepseek-flash", 1, log=lambda *_: None,
                     provider_options={"allow_cloud": True})
    assert seen and seen[0].get("thinking") == "disabled"
    seen.clear()
    draft.llm_rounds("C", "1", "deepseek:deepseek-flash", 1, log=lambda *_: None,
                     provider_options={"allow_cloud": True, "thinking": "enabled"})
    assert seen and seen[0].get("thinking") == "enabled"


def test_reference_prompt_is_bounded(monkeypatch):
    from roc import draft, refsource
    monkeypatch.setattr(draft.match.clients, "load", lambda: {"C": {"compiler": "cl", "flags": "/O2"}})
    monkeypatch.setattr(refsource, "hint", lambda *_: "must not appear")
    row = {"size": 8, "unit": "Thing"}
    source = {"path": "Thing.cpp", "text": "text" * 1000, "method": "method" * 1000,
              "facts": {"classes": ["Thing"]}}
    prompt = draft.prompt_for("C", "1", row, ["ret "], None, None, source_hints=[source], strategy="reference")
    assert "must not appear" not in prompt and "method" * 150 in prompt and "method" * 151 not in prompt


def test_model_choice(monkeypatch):
    from roc import draft
    monkeypatch.setattr(draft, "ollama_models", lambda: ["my-model", "qwen2.5-coder:7b"])
    assert draft.pick_model() == "qwen2.5-coder:7b"
    assert draft.pick_model("my-model") == "my-model"
    assert draft.pick_model("local:my-model") == "local:my-model"
    assert draft.pick_model("default") == "qwen2.5-coder:7b"
    monkeypatch.setattr(draft, "ollama_models", lambda: ["my-model"])
    assert draft.pick_model() == "my-model"
    assert draft.pick_model("local:my-model") == "local:my-model"


def test_cloud_provider_core():
    from roc import providers
    old_post = providers._post
    old_key = os.environ.get("NVIDIA_API_KEY")
    os.environ["NVIDIA_API_KEY"] = "test-key"
    try:
        providers._post = lambda *args: ({"id": "req1", "choices": [{"message": {"content": "```cpp\\nint f(){}\\n```"}, "finish_reason": "stop"}], "usage": {"prompt_tokens": 4, "completion_tokens": 7}}, {"x-request-id": "req1"})
        out = providers.generate("nvidia:qwen/test", r"C:\Users\alice\secret", options={"allow_cloud": True, "max_tokens": 8})
        assert out.provider == "nvidia" and out.model == "qwen/test" and out.input_tokens == 4
        assert "alice" not in out.state["messages"][0]["content"]
        listed = providers.generate("nvidia:qwen/test", [{"role": "system", "content": "short"},
                                                            {"role": "user", "content": "message-list"}],
                                    options={"allow_cloud": True, "max_tokens": 8})
        assert listed.text and listed.state["messages"][0]["role"] == "system"
        history = providers.generate("nvidia:qwen/test", [{"role": "system", "content": r"C:\Users\alice\private"},
                                                             {"role": "user", "content": "message-list"}],
                                      options={"allow_cloud": True, "max_tokens": 8})
        assert "alice" not in history.state["messages"][0]["content"]
        assert "private" not in providers.sanitize_prompt("token=private-token-value")
        old_secret_path = os.environ.get("ROCONSTRUCT_SECRETS_FILE")
        with tempfile.TemporaryDirectory() as temp:
            secret_path = Path(temp) / "secrets.json"
            secret_path.write_text(json.dumps({"DEEPSEEK_API_KEY": "file-key"}))
            os.environ["ROCONSTRUCT_SECRETS_FILE"] = str(secret_path)
            assert providers.key_available("DEEPSEEK_API_KEY")
            assert providers.secret("DEEPSEEK_API_KEY") == "file-key"
        if old_secret_path is None:
            os.environ.pop("ROCONSTRUCT_SECRETS_FILE", None)
        else:
            os.environ["ROCONSTRUCT_SECRETS_FILE"] = old_secret_path
        try:
            providers.save_provider("bad", "openai-chat", "https://example.com/v1?token=x", "BAD_KEY")
            raise AssertionError("secret query URL was accepted")
        except ValueError:
            pass
        try:
            providers.generate("nvidia:qwen/test", "x", options={})
            raise AssertionError("cloud request was not blocked")
        except providers.ProviderError as error:
            assert error.category == "cloud_disabled"
        budget = providers.CloudBudget(requests=1, tokens=20)
        ticket = budget.reserve(8)
        budget.settle(ticket, 10)
        assert budget.requests == 1 and budget.tokens == 10
        try:
            budget.reserve(1)
            raise AssertionError("request budget was not enforced")
        except providers.ProviderError:
            pass
        gate = providers.CloudGate(concurrency=1, failures=1)
        lock = gate.enter("nvidia")
        lock.release()
        gate.done("nvidia", False)
        try:
            gate.enter("nvidia")
            raise AssertionError("circuit breaker was not enforced")
        except providers.ProviderError as error:
            assert error.category == "provider_circuit"
        gate.reset("nvidia")
        lock = gate.enter("nvidia")
        lock.release()
    finally:
        providers._post = old_post
        if old_key is None:
            os.environ.pop("NVIDIA_API_KEY", None)
        else:
            os.environ["NVIDIA_API_KEY"] = old_key


def test_model_pricing_is_exact_and_usable_for_caps():
    from roc import providers
    config = {"pricing": {"models": {"flash": {
        "input_per_million": 1.0, "output_per_million": 2.0}}}}
    assert providers._cost(config, 2, 3, "flash") == 0.000008
    assert providers._cost(config, 2, 3, "unknown") is None
    with patch("roc.providers.parse_model", return_value=("deepseek", "flash", config)):
        assert providers.has_pricing("deepseek:flash")
    with patch("roc.providers.parse_model", return_value=("deepseek", "other", config)):
        assert not providers.has_pricing("deepseek:other")


def test_native_cloud_adapters():
    from roc import providers
    names = {"OPENAI_API_KEY": "test-openai", "ANTHROPIC_API_KEY": "test-anthropic",
             "GEMINI_API_KEY": "test-gemini", "DEEPSEEK_API_KEY": "test-deepseek"}
    before = {name: os.environ.get(name) for name in names}
    old_post = providers._post
    calls = []
    def fake_post(url, body, headers, timeout):
        calls.append((url, body, headers))
        if url.endswith("/chat/completions"):
            return {"choices": [{"message": {"content": "deepseek"}, "finish_reason": "stop"}],
                    "usage": {"prompt_tokens": 11, "completion_tokens": 1,
                              "prompt_cache_hit_tokens": 7}}, {}
        if url.endswith("/responses"):
            return {"id": "openai-r", "output_text": "openai", "status": "completed",
                    "usage": {"input_tokens": 3, "output_tokens": 4,
                              "input_tokens_details": {"cached_tokens": 2}}}, {}
        if url.endswith("/messages"):
            return {"id": "anthropic-r", "content": [{"type": "text", "text": "anthropic"}],
                    "stop_reason": "end_turn", "usage": {"input_tokens": 5, "output_tokens": 6,
                                                             "cache_read_input_tokens": 4}}, {}
        return {"candidates": [{"content": {"parts": [{"text": "gemini"}]}, "finishReason": "STOP"}],
                "usageMetadata": {"promptTokenCount": 7, "candidatesTokenCount": 8,
                                   "cachedContentTokenCount": 3}}, {}
    try:
        os.environ.update(names)
        providers._post = fake_post
        deepseek = providers.generate("deepseek:deepseek-flash", "p", options={"allow_cloud": True})
        auto = providers.generate("deepseek:deepseek-flash", "p",
                                  options={"allow_cloud": True, "thinking": "auto"})
        disabled = providers.generate("deepseek:deepseek-flash", "p",
                                      options={"allow_cloud": True, "thinking": "disabled"})
        openai = providers.generate("openai:gpt-test", "p", options={"allow_cloud": True})
        anthropic = providers.generate("anthropic:claude-test", "p", options={"allow_cloud": True})
        gemini = providers.generate("gemini:gemini-test", "p", options={"allow_cloud": True})
        assert [deepseek.cached_tokens, openai.cached_tokens,
                anthropic.cached_tokens, gemini.cached_tokens] == [7, 2, 4, 3]
        assert "thinking" not in calls[0][1] and "thinking" not in calls[1][1]
        assert calls[2][1]["thinking"] == {"type": "disabled"}
        assert calls[3][1]["store"] is False and calls[4][2]["anthropic-version"]
        assert "x-goog-api-key" in calls[5][2]
    finally:
        providers._post = old_post
        for name, value in before.items():
            if value is None:
                os.environ.pop(name, None)
            else:
                os.environ[name] = value


def test_cloud_retry_and_budget_do_not_trip_circuit():
    from roc import providers
    old_key = os.environ.get("NVIDIA_API_KEY")
    old_post = providers._post
    calls = []
    os.environ["NVIDIA_API_KEY"] = "test-key"
    def flaky(*args):
        calls.append(1)
        if len(calls) < 3:
            raise providers.ProviderError("provider_retry", "temporary", 503)
        return {"id": "ok", "choices": [{"message": {"content": "ok"}}]}, {}
    try:
        providers._post = flaky
        gate = providers.CloudGate(concurrency=1, failures=1)
        out = providers.generate("nvidia:qwen/test", "p", options={"allow_cloud": True,
                                                                       "retries": 2, "gate": gate})
        assert out.text == "ok" and out.retries == 2 and len(calls) == 3
        budget = providers.CloudBudget(requests=0)
        try:
            providers.generate("nvidia:qwen/test", "p", options={"allow_cloud": True,
                                                                      "gate": gate, "budget": budget})
            raise AssertionError("budget did not stop request")
        except providers.ProviderError as error:
            assert error.category == "cloud_budget"
        lock = gate.enter("nvidia")
        lock.release()
    finally:
        providers._post = old_post
        if old_key is None:
            os.environ.pop("NVIDIA_API_KEY", None)
        else:
            os.environ["NVIDIA_API_KEY"] = old_key


def test_cloud_worker_retries_usage_until_success():
    from roc import providers
    old_key = os.environ.get("NVIDIA_API_KEY")
    old_post, old_sleep = providers._post, providers.time.sleep
    os.environ["NVIDIA_API_KEY"] = "test-key"
    calls, retries = [], []
    def flaky(*args):
        calls.append(1)
        if len(calls) < 4:
            raise providers.ProviderError("provider_retry", "usage limit", 429)
        return {"id": "ok", "choices": [{"message": {"content": "ok"}}]}, {}
    providers._post = flaky
    providers.time.sleep = lambda *_: None
    try:
        out = providers.generate("nvidia:qwen/test", "p", options={"allow_cloud": True,
                                                                         "retries": 0,
                                                                         "retry_forever": True,
                                                                         "on_retry": lambda *row: retries.append(row)})
        assert out.text == "ok" and out.retries == 3 and len(calls) == 4 and len(retries) == 3
    finally:
        providers._post, providers.time.sleep = old_post, old_sleep
        if old_key is None:
            os.environ.pop("NVIDIA_API_KEY", None)
        else:
            os.environ["NVIDIA_API_KEY"] = old_key


def test_non_retryable_http_fails_fast():
    """A request the provider rejects (e.g. context overflow, HTTP 400) must
    surface immediately: no retry loop, no repeated spend."""
    from roc import providers
    old_key = os.environ.get("NVIDIA_API_KEY")
    old_post = providers._post
    calls = []
    os.environ["NVIDIA_API_KEY"] = "test-key"
    def rejected(*args):
        calls.append(1)
        raise providers.ProviderError("provider_error", "HTTP 400", 400)
    try:
        providers._post = rejected
        try:
            providers.generate("nvidia:qwen/test", "p",
                               options={"allow_cloud": True, "retries": 2})
            raise AssertionError("rejected request did not fail")
        except providers.ProviderError as error:
            assert error.category == "provider_error" and error.status == 400
        assert len(calls) == 1
    finally:
        providers._post = old_post
        if old_key is None:
            os.environ.pop("NVIDIA_API_KEY", None)
        else:
            os.environ["NVIDIA_API_KEY"] = old_key


def test_deepseek_openai_compatible_provider():
    from roc import providers
    old_key = os.environ.get("DEEPSEEK_API_KEY")
    old_post = providers._post
    calls = []
    os.environ["DEEPSEEK_API_KEY"] = "test-deepseek"
    def fake_post(url, body, headers, timeout):
        calls.append((url, body, headers))
        return {"id": "ds-1", "choices": [{"message": {"content": "ok"},
                                                "finish_reason": "stop"}],
                "usage": {"prompt_tokens": 2, "completion_tokens": 3,
                          "completion_tokens_details": {"reasoning_tokens": 2}}}, {}
    try:
        providers._post = fake_post
        out = providers.generate("deepseek:deepseek-flash", "Reply ok",
                                 options={"allow_cloud": True, "max_tokens": 8,
                                          "thinking": "enabled", "reasoning_effort": "high"})
        assert out.provider == "deepseek" and out.model == "deepseek-flash"
        assert calls[0][0] == "https://api.deepseek.com/chat/completions"
        assert calls[0][2]["Authorization"] == "Bearer test-deepseek"
        assert calls[0][1]["thinking"] == {"type": "enabled"}
        assert calls[0][1]["reasoning_effort"] == "high"
        assert out.output_tokens == 3 and out.telemetry()["reasoning_tokens"] == 2
        assert providers.Generation("", None).telemetry()["reasoning_tokens"] is None
    finally:
        providers._post = old_post
        if old_key is None:
            os.environ.pop("DEEPSEEK_API_KEY", None)
        else:
            os.environ["DEEPSEEK_API_KEY"] = old_key


def test_link_options():
    from roc.link import choose_options
    with patch("roc.draft.ollama_models", return_value=["qwen2.5-coder:14b", "qwen2.5-coder:7b"]), \
         patch("roc.draft.pick_model", return_value="qwen2.5-coder:14b"), \
         patch("roc.worker.save_settings") as saved, \
         patch("builtins.input", side_effect=["qwen2.5-coder:7b", "fast", "auto", ""]):
        assert choose_options({"model": "qwen2.5-coder:14b"}) == ("qwen2.5-coder:7b", 2, 96, False, "auto", 2048, "auto")
        assert saved.call_count == 2
    with patch("roc.draft.ollama_models", return_value=["qwen2.5-coder:14b", "qwen2.5-coder:7b"]), \
         patch("roc.draft.pick_model", return_value="qwen2.5-coder:14b"), \
         patch("roc.worker.save_settings"), \
         patch("builtins.input", side_effect=["", "", "", "y", "", "512", "", "", "", "direct", "", ""]):
        assert choose_options({"model": "qwen2.5-coder:14b", "worker_preset": "deep",
                               "worker_workers": "auto", "worker_revng": False,
                               "worker_output_budget": 2048}) == ("qwen2.5-coder:14b", 6, 512, False, "auto", 2048, "auto")
    with patch("roc.draft.ollama_models", return_value=["qwen2.5-coder:14b", "qwen2.5-coder:7b"]), \
         patch("roc.draft.pick_model", return_value="qwen2.5-coder:14b"), \
         patch("roc.worker.save_settings"), \
         patch("builtins.input", side_effect=["", "balanced", "1", "y", "6", "256", "1024", "n", "disabled", "direct", "matched", "compact"]):
        assert choose_options({}) == ("qwen2.5-coder:14b", 6, 256, False, 1, 1024, "disabled")
    with patch("roc.draft.ollama_models", return_value=["qwen2.5-coder:14b", "qwen2.5-coder:7b"]), \
         patch("roc.draft.pick_model", return_value="qwen2.5-coder:14b"), \
         patch("roc.worker.save_settings"), \
         patch("builtins.input", side_effect=["", "balanced", "99", ""]):
        assert choose_options({}) == ("qwen2.5-coder:14b", 4, 256, True, 99, 2048, "auto")


    with patch("roc.draft.ollama_models", return_value=["qwen2.5-coder:7b"]), \
         patch("roc.draft.pick_model", return_value="qwen2.5-coder:7b"), \
         patch("roc.worker.save_settings"), \
         patch("builtins.input", side_effect=["", "auto", "1", ""]):
        assert choose_options({}) == ("qwen2.5-coder:7b", "auto", 512, False, 1, 2048, "auto")


def test_uri_link_checks_updates_before_launch():
    import importlib.util
    spec = importlib.util.spec_from_file_location("roc_cli_test", Path(__file__).resolve().parent.parent / "roc.py")
    cli = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(cli)
    calls = []
    with patch("roc.selfupdate.try_update", side_effect=lambda: calls.append("update") or "current"), \
         patch("roc.link.run", side_effect=lambda target: calls.append("launch")), \
         patch("builtins.print"):
        cli.cmd_link(type("Args", (), {"target": "roconstruct://work?client=2008"})())
    assert calls == ["update", "launch"]


def test_optimizer_split_and_one_time_profile():
    from roc import optimizer
    assert any(config["name"] == "auto" and config["strategy"] == "auto"
               for config in optimizer.CONFIGS)
    targets = [{"client": "C", "addr": "%08x" % n} for n in range(6)]
    calibration, validation = optimizer.split_targets(targets)
    assert len(calibration) == 4 and len(validation) == 2
    assert not ({row["addr"] for row in calibration} & {row["addr"] for row in validation})
    with patch("roc.optimizer.profile", return_value=None), \
         patch("roc.draft.pick_model", return_value="local-model"), \
         patch("roc.providers.is_cloud", return_value=False), \
         patch("roc.benchmark.build_hidden", return_value=targets), \
         patch("roc.optimizer._local_targets", return_value=targets), \
         patch("roc.benchmark.run_local"), \
         patch("roc.optimizer._fresh_targets", return_value=targets), \
         patch("roc.optimizer._concurrency", return_value=(4, [{"workers": 4, "valid": 6}])), \
         patch("roc.optimizer.fingerprint", return_value="model-fingerprint"), \
         patch("roc.optimizer._session_rows", side_effect=lambda session: [
             {"score": 100 if "structured" in session else 0, "seconds": 1,
              "rounds": [{"round": 1, "code": True, "compile_error": ""}]}
             for _ in range(2 if "-v-" in session else 4)]), \
         patch("roc.worker.load_settings", return_value={}), \
         patch("roc.worker.save_settings") as saved:
        result = optimizer.run("local-model", log=lambda *args: None)
    assert result["name"] == "structured"
    assert result["validated"] and result["sample_count"] == 6
    assert saved.call_args.kwargs["optimizer_profiles"]["local-model"] == result
    with patch("roc.optimizer.fingerprint", return_value="new-version"):
        assert optimizer.profile("local-model", {"optimizer_profiles": {
            "local-model": {"fingerprint": "old-version"}}}) is None
    from types import SimpleNamespace
    with patch("roc.metrics.PATH", SimpleNamespace(read_text=lambda **_kwargs: (
            '{"event":"job","client":"C","addr":"00000000","model":"local-model"}\n'
            '{"event":"job","client":"C","addr":"00000001","model":"other-model"}\n'))):
            assert {row["addr"] for row in optimizer._fresh_targets(targets, "local-model")} == {
                row["addr"] for row in targets if row["addr"] != "00000000"}


def test_optimizer_concurrency_probe():
    from types import SimpleNamespace
    from roc.optimizer import _concurrency
    with patch("roc.providers.generate", return_value=SimpleNamespace(text="OK")) as generate:
        workers, rows = _concurrency("local-model", False, None, lambda *args: None)
    assert workers in (1, 4, 8)
    assert len(rows) == 3 and all(row["valid"] == 6 for row in rows)
    assert generate.call_count == 19


def test_optimizer_cloud_and_incomplete_safety():
    from roc import optimizer
    with patch("roc.worker.load_settings", return_value={}), \
         patch("roc.providers.is_cloud", return_value=True), \
         patch("roc.providers.available", return_value=True):
        try:
            optimizer.run("deepseek:deepseek-flash")
            assert False, "cloud consent required"
        except SystemExit as error:
            assert "--allow-cloud" in str(error)
        try:
            optimizer.run("deepseek:deepseek-flash", allow_cloud=True)
            assert False, "cloud cost cap required"
        except SystemExit as error:
            assert "--max-cloud-cost" in str(error)
        with patch("roc.providers.parse_model", return_value=("deepseek", "deepseek-flash", {
                "key_env": "DEEPSEEK_API_KEY", "pricing": {}})):
            try:
                optimizer.run("deepseek:deepseek-flash", allow_cloud=True, max_cloud_cost=0.25)
                assert False, "unpriced cloud spend cannot be capped"
            except SystemExit as error:
                assert "pricing" in str(error)
    targets = [{"client": "C", "addr": "%08x" % n} for n in range(2)]
    with patch("roc.worker.load_settings", return_value={}), \
         patch("roc.draft.pick_model", return_value="local-model"), \
         patch("roc.providers.is_cloud", return_value=False), \
         patch("roc.benchmark.build_hidden", return_value=targets), \
         patch("roc.optimizer._local_targets", return_value=targets), \
         patch("roc.optimizer._fresh_targets", return_value=targets), \
         patch("roc.optimizer._concurrency", return_value=(1, [{"workers": 1, "valid": 6}])), \
         patch("roc.benchmark.run_local"), \
         patch("roc.optimizer._session_rows", return_value=[]), \
         patch("roc.worker.save_settings") as saved:
        try:
            optimizer.run("local-model", log=lambda *args: None)
            assert False, "incomplete optimizer must not save"
        except SystemExit as error:
            assert "no profile saved" in str(error)
    saved.assert_not_called()


def test_optimizer_profile_clear():
    from roc.optimizer import clear_profile
    profiles = {"model-a": {"name": "fast"}, "model-b": {"name": "deep"}}
    with patch("roc.worker.load_settings", return_value={"optimizer_profiles": profiles}), \
         patch("roc.worker.save_settings") as saved:
        assert clear_profile("model-a")
    assert saved.call_args.kwargs["optimizer_profiles"] == {"model-b": {"name": "deep"}}


def test_launcher_can_optimize_before_worker():
    from roc.link import choose_options
    profile = {"name": "structured", "rounds": 2, "max_tokens": 1536, "strategy": "structured"}
    with patch("roc.draft.ollama_models", return_value=["local-model"]), \
         patch("roc.draft.pick_model", return_value="local-model"), \
         patch("roc.worker.save_settings"), \
         patch("roc.optimizer.run", return_value=profile) as optimize, \
         patch("builtins.input", side_effect=["", "5", "", ""]):
        result = choose_options({"model": "local-model"})
    optimize.assert_called_once()
    assert result == ("local-model", 2, 256, True, 1, 1536, "auto")


def test_launcher_saved_setup_starts_with_one_enter():
    from roc.link import choose_options
    settings = {"model": "local-model", "worker_launcher_configured": True,
                "worker_preset": "balanced", "worker_rounds": 3, "worker_workers": 7,
                "worker_output_budget": 1536, "worker_revng": False,
                "worker_thinking": "disabled", "worker_strategy": "structured"}
    with patch("roc.draft.ollama_models", return_value=["local-model"]), \
         patch("roc.draft.pick_model", return_value="local-model"), \
         patch("roc.worker.save_settings"), \
         patch("roc.optimizer.profile", return_value=None), \
         patch("builtins.input", side_effect=[""]):
        assert choose_options(settings) == (
            "local-model", 3, 256, False, 7, 1536, "disabled")


def test_launcher_workers_edit_separate_from_saved_setup():
    from roc.link import choose_options
    settings = {"model": "local-model", "worker_launcher_configured": True,
                "worker_preset": "balanced", "worker_rounds": 3, "worker_workers": 7,
                "worker_output_budget": 1536, "worker_revng": False,
                "worker_thinking": "disabled", "worker_strategy": "structured"}
    with patch("roc.draft.ollama_models", return_value=["local-model"]), \
         patch("roc.draft.pick_model", return_value="local-model"), \
         patch("roc.worker.save_settings") as saved, \
         patch("roc.optimizer.profile", return_value=None), \
         patch("builtins.input", side_effect=["3", "12"]), \
         patch("builtins.print") as printed:
        result = choose_options(settings)
    assert result[4] == 12
    assert saved.call_args.kwargs == {"worker_workers": 12, "worker_workers_model": "local-model"}
    assert "Saved setup: local-model | balanced." in printed.call_args.args[0]
    assert "7 workers" not in printed.call_args.args[0]


def test_launcher_saved_setup_optimize_action_four():
    from roc.link import choose_options
    settings = {"model": "local-model", "worker_launcher_configured": True,
                "worker_preset": "balanced", "worker_workers": 2}
    with patch("roc.draft.ollama_models", return_value=["local-model"]), \
         patch("roc.draft.pick_model", return_value="local-model"), \
         patch("roc.worker.save_settings"), \
         patch("roc.optimizer.profile", return_value=None), \
         patch("roc.optimizer.run", return_value={"name": "fast"}) as optimize, \
         patch("builtins.input", side_effect=["4"]):
        choose_options(settings)
    optimize.assert_called_once_with("local-model", allow_cloud=False, max_cloud_cost=None, force=False)


def test_launcher_numbered_model_and_fast_mode():
    from roc.link import choose_options
    with patch("roc.draft.ollama_models", return_value=["model-a", "model-b"]), \
         patch("roc.draft.pick_model", return_value="model-a"), \
         patch("roc.worker.save_settings"), \
         patch("builtins.input", side_effect=["2", "2", "1", ""]):
        assert choose_options({}) == ("model-b", 2, 96, False, 1, 2048, "auto")


def test_auto_reasoning():
    from roc.worker import auto_reasoning, resolve_rounds
    assert resolve_rounds({"size": 48}, "auto") == 2
    assert resolve_rounds({"size": 49}, "auto") == 4
    assert resolve_rounds({"size": 512}, "auto", "deepseek:deepseek-flash") == 2
    assert resolve_rounds({"size": 512}, 6) == 6
    assert auto_reasoning({"size": 11}, "auto", "auto") == ("disabled", "low")
    assert auto_reasoning({"size": 200, "calls": 2}, "auto", "auto") == (None, None)
    assert auto_reasoning({"size": 200, "calls": 2}, "auto", "auto", "deepseek:deepseek-flash") == ("disabled", None)
    assert auto_reasoning({"size": 200}, "enabled", "high", "deepseek:deepseek-flash") == ("enabled", "high")
    assert auto_reasoning({"size": 11}, "enabled", "high") == ("enabled", "high")
    assert auto_reasoning({"size": 11}, None, None) == (None, None)


def test_announce_once():
    import threading
    from roc import worker
    worker._ANNOUNCED.clear()
    logged = []
    lock = threading.Lock()
    def log(message):
        with lock:
            logged.append(message)
    threads = [threading.Thread(target=worker.announce_once, args=(("k", "v"), log, "hello"))
               for _ in range(8)]
    for thread in threads:
        thread.start()
    for thread in threads:
        thread.join()
    assert logged == ["hello"]
    worker.announce_once(("other",), log, "world")
    assert logged == ["hello", "world"]
    worker._ANNOUNCED.clear()


def test_cloud_history_is_bounded():
    from roc import providers
    history = [{"role": "system", "content": "sys"},
               {"role": "user", "content": "first-target-facts"},
               {"role": "assistant", "content": "try1"},
               {"role": "user", "content": "feedback1"},
               {"role": "assistant", "content": "try2"},
               {"role": "user", "content": "feedback2"}]
    messages = providers._cloud_messages("new-feedback", {"messages": history})
    assert [m["content"] for m in messages] == ["sys", "first-target-facts", "try2",
                                                "feedback2", "new-feedback"]
    assert len(providers._cloud_messages("p", {"messages": history}, keep_last=0)) == 3
    assert providers._cloud_messages("p", None)[0]["role"] == "system"


def test_trim_hint_facts():
    from roc.draft import _trim_hint_facts
    methods = ["alpha%d" % i for i in range(30)] + ["BlockRender", "blockUpdate"]
    trimmed = _trim_hint_facts({"methods": methods, "classes": ["C"],
                                "literals": list(map(str, range(20)))}, ["block"])
    assert len(trimmed["methods"]) == 16
    assert "BlockRender" in trimmed["methods"] and "blockUpdate" in trimmed["methods"]
    assert len(trimmed["literals"]) == 12 and trimmed["classes"] == ["C"]


def test_clip_example(monkeypatch):
    from roc import draft
    short = "int f() { return 1; }"
    assert draft._clip_example(short) == short
    big = "struct S { int f(); };\n" + "int x;\n" * 1000
    clipped = draft._clip_example(big)
    assert len(clipped) < len(big) and "trimmed" in clipped and clipped.startswith("struct S")
    monkeypatch.setattr(draft.match.clients, "load", lambda: {"C": {"compiler": "cl", "flags": "/O2"}})
    row = {"size": 8, "unit": "Thing"}
    prompt = draft.prompt_for("C", "1", row, ["ret "], None, None, examples=[big])
    assert "trimmed" in prompt and big not in prompt and prompt.count("int x;") < 1000
    prompt = draft.prompt_for("C", "1", row, ["ret "], None, None, examples=[short])
    assert short in prompt and "trimmed" not in prompt


def test_mine_digest():
    import time
    from roc.discord import MineLog, fmt_duration
    from roc.server import Store
    assert fmt_duration(45) == "45s" and fmt_duration(300) == "5m"
    assert fmt_duration(5400) == "1h 30m" and fmt_duration(90000) == "25h 0m"
    assert fmt_duration(200000) == "2d 7h"
    st = Store(":memory:", lease_seconds=1)
    st.db.executemany("INSERT INTO funcs(client,addr,size,unit,score) VALUES(?,?,?,?,?)",
                      [("C", "a1", 9, "U1", 100), ("C", "a2", 9, "U2", 50), ("C", "a3", 9, "U3", 0)])
    now = time.time()
    st.db.executemany("INSERT INTO events(ts,client,addr,user,old,new) VALUES(?,?,?,?,?,?)",
                      [(now - 3600, "C", "a1", "alice", 90, 100),
                       (now - 1800, "C", "a2", "alice", 0, 50)])
    st.db.commit()
    assert st.user_points("alice") == 60 and st.user_points("nobody") == 0
    assert st.client_progress("C") == (1, 3)
    assert st.client_bytes("C") == (9, 27)
    assert st.display_progress("C") == (1, 3, 9, 27)
    assert st.match_rate("C") > 0 and st.match_rate("other") == 0
    sent = []
    log = MineLog("http://example.invalid/hook", st, batch_events=10, batch_seconds=60)
    with patch("roc.discord._post", side_effect=lambda url, payload: sent.append(payload)):
        log.submit({"client": "C", "addr": "a1", "unit": "U1", "size": 9}, "alice", "w", "m", 100, 10)
        log.submit({"client": "C", "addr": "a2", "unit": "U2", "size": 9}, "alice", "w", "m", 50, 50)
        assert sent == []  # batched, not spammed
        log.flush()
        assert len(sent) == 1
    embed = sent[0]["embeds"][0]
    assert embed["title"] == "⛏️ RoConstruct Mining Digest"
    assert "33.33%" in embed["description"] and "1 / 3 matched" in embed["description"]
    assert "a1" in embed["fields"][0]["value"] and "a2" in embed["fields"][1]["value"]
    assert embed["fields"][2]["name"] == "⚡ Mining Rate"
    assert embed["fields"][3]["name"] == "⚙️ Verification" and embed["fields"][3]["value"] == "server-verified"
    assert embed["fields"][4]["value"] == "1 full · 1 improved"
    assert embed["footer"]["text"] == "RoConstruct Mining" and "T" in embed["timestamp"]


def test_concurrent_shares_caches_and_clamps():
    from roc import worker
    assert worker.MAX_WORKERS == 256
    calls = []

    def fake_run(*args, **kwargs):
        calls.append((args, kwargs))
        return 0

    with patch("roc.worker.run", side_effect=fake_run), patch("roc.setup.compilers") as warmed:
        worker.run_concurrent("http://x", "u", model="m", max_jobs=3, workers=3, log=lambda *a: None)
        warmed.assert_called_once()
    assert len(calls) == 3
    assert {c[1]["examples_cache"] is calls[0][1]["examples_cache"] for c in calls} == {True}
    assert {c[1]["source_cache"] is calls[0][1]["source_cache"] for c in calls} == {True}
    assert sorted(c[0][7] for c in calls) == [1, 1, 1]
    calls.clear()
    with patch("roc.worker.run", side_effect=fake_run):
        worker.run_concurrent("http://x", "u", model="m", max_jobs=0, workers=99, log=lambda *a: None)
    assert len(calls) == 99


def test_compact_worker_log():
    from roc.worker import CompactLog
    out = []
    log = CompactLog(32, out.append)
    log("[C 00401020] 8 B, Unit, best so far 0%")
    log("  round 1: 100%")
    log("  submitted 100% (verified by server)")
    log("[C 00401030] 8 bytes, Unit2, best so far 0%")
    log("  no improvement (best 0%), released")
    log("  thinking disabled for remaining rounds")
    log("  tokens used: 100")
    log.finish()
    assert "✓ C 00401020 8 B 100% Unit" in out
    assert "· C 00401030 8 B no gain (best 0%) Unit2" in out
    assert out[-1] == "⛏ 32w finished | 2 done | 1 matched | 1 improved | 0 errors"


def test_server_store():
    st = Store(":memory:", lease_seconds=1)
    assert make_handler(st, None, set()).protocol_version == "HTTP/1.1"
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


def test_server_ordering():
    st = Store(":memory:", lease_seconds=10)
    st.db.executemany("INSERT INTO funcs(client,addr,size,unit,score,source_confidence,difficulty) VALUES(?,?,?,?,?,?,?)",
                      [("C", "00401000", 30, "A", 0, 0, 30),
                       ("C", "00401010", 10, "B", 50, 1, 10),
                       ("C", "00401020", 50, "C", 90, 2, 50)])
    for order, addr in (("matched", "00401020"), ("unmatched", "00401000"),
                        ("easiest", "00401010"), ("best", "00401020"), ("auto", "00401020")):
        job = st.lease("alice", order, ["C"], "ai", 256, order=order)
        assert job["addr"] == addr
        st.release(job["lease"], 0)
    st.db.execute("UPDATE funcs SET unit='seg_00400000' WHERE addr='00401000'")
    job = st.lease("alice", "random", ["C"], "ai", 256, order="random")
    assert not job["unit"].startswith("seg_")
    st.release(job["lease"], 0)
    job = st.lease("alice", "default", ["C"], "ai", 256)
    assert not job["unit"].startswith("seg_")


def test_fingerprint_partial_scope():
    from roc.batch_fingerprint import batches, source_family
    assert source_family("// roc-lib: templates-boost-1_34_1 vector_sp.cpp") == "boost"
    assert source_family("// roc-lib: openrbx-client App/v8tree/Instance.cpp") == "roblox"
    assert source_family("// roc-lib: rbx2016-g3d MemoryManager.cpp") == "g3d"
    st = Store(":memory:", lease_seconds=10)
    source = "// roc-lang: cpp\n// roc-cl: 30729\n// roc-flags: /O2\n// roc-lib: xtp-11.2.2 XTPReportControl.cpp"
    st.db.executemany("INSERT INTO funcs(client,addr,size,unit,score,source) VALUES(?,?,?,?,?,?)", [
        ("C", "00401000", 20, "CXTPReportControl", 100, source),
        ("C", "00401010", 20, "CXTPReportControl", 0, None),
        ("C", "00401020", 20, "CXTPReportControl", 50, "other source"),
        ("C", "00401030", 20, "CXTPReportControl", 70, source),
        ("C", "00401040", 20, "RBX::Instance", 100, source),
        ("C", "00401050", 20, "RBX::Instance", 50, "other source"),
    ])
    assert list(batches(st.db)) == [("C", source, ["00401010"])]
    assert list(batches(st.db, partials=True)) == [("C", source, ["00401020"])]


def test_fingerprint_crossclient_scope():
    from roc.batch_fingerprint import cross_client_batches
    st = Store(":memory:", lease_seconds=10)
    source = "// roc-lang: cpp\n// roc-cl: 30729\n// roc-flags: /O2\n// roc-lib: xtp-11.2.2 XTPReportControl.cpp"
    st.db.executemany("INSERT INTO funcs(client,addr,size,unit,score,source) VALUES(?,?,?,?,?,?)", [
        ("A", "00401000", 20, "CXTPReportControl", 100, source),
        ("A", "00401010", 20, "CXTPReportControl", 0, None),
        ("B", "00401010", 20, "CXTPReportControl", 0, None),
        ("B", "00401020", 20, "CXTPReportControl", 60, "other source"),
        ("B", "00401030", 20, "CXTPReportControl", 60, source),
        ("B", "00401040", 20, "CXTPReportControlOther", 0, None),
        ("B", "00401050", 20, "RBX::ReportControl", 0, None),
        ("B", "00401060", 20, "seg_00400000", 0, None),
    ])
    assert list(cross_client_batches(st.db)) == [("B", source, ["00401010", "00401020"])]


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


def test_dataset_audit_project_split():
    from roc import dataset
    with tempfile.TemporaryDirectory() as folder:
        root = Path(folder)
        (root / "f.cpp").write_text("int f(){return 0;}\n")
        (root / "f.obj").write_bytes(b"x" * 8)
        (root / "f.relocs.json").write_text("[0]")
        entry = {"project": "p", "split": "train", "license": "MIT", "source": "f.cpp",
                 "client": "2008-06", "addr": "00401000", "size": 4, "compiler": "msvc-2008",
                 "flags": "/O2", "binary": "f.obj", "relocations": "f.relocs.json"}
        manifest = root / "manifest.json"
        manifest.write_text(json.dumps({"format": "roconstruct-msvc-pilot-v1", "entries": [entry]}))
        assert dataset.audit(manifest, strict=False)["ok"]
        leaked = dict(entry, split="test", addr="00401004")
        manifest.write_text(json.dumps({"format": "roconstruct-msvc-pilot-v1", "entries": [entry, leaked]}))
        assert not dataset.audit(manifest, strict=False)["ok"]


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
    assert d["classifications"][0]["category"] != "exact"
    assert d["classifications"][-1]["confidence"] >= 0


def test_repair_pattern_registry_is_measured_and_deterministic():
    from roc.repair_patterns import load, rank_categories
    rows = load()
    assert any(row["name"] == "typed-member-return" for row in rows)
    diag = {"mismatch_class": "branch-condition mismatch",
            "classifications": [{"category": "branch-condition mismatch", "confidence": .95}]}
    first = rank_categories(diag, ["allocation_result", "branch_condition"])
    assert first[0][1] == "allocation_result"
    assert first == rank_categories(diag, ["allocation_result", "branch_condition"])


def test_diagnose_call_argument_order():
    from roc import draft, match, mutate
    target = bytes.fromhex("6a016a02ff1500000000c3")
    candidate = bytes.fromhex("6a026a01ff1500000000c3")
    diag = match.diagnose(target, [], candidate, [])
    assert diag["call_argument_diffs"] == [
        {"call": 1, "target": ["2", "1"], "candidate": ["1", "2"]}]
    target_registers = bytes.fromhex("5052ff1500000000c3")
    candidate_registers = bytes.fromhex("5153ff1500000000c3")
    assert match.diagnose(target_registers, [], candidate_registers, [])["call_argument_diffs"] == []
    near = match.diagnose(target, [], bytes.fromhex("6a016a03ff1500000000c3"), [])
    assert near["byte_diffs"] == [{"offset": 3, "target": 2, "candidate": 3}]
    note_diag = {"similarity": 0.9, "byte_diffs": near["byte_diffs"],
                 "opcode_delta": {}, "register_delta": {},
                 "branches": {"target_jcc": 0, "cand_jcc": 0},
                 "stack_refs": {"target": 0, "cand": 0}, "call_argument_diffs": []}
    assert "same-length byte diffs target>yours +3:02>03" in draft._diagnose_note(
        "unused", "unused", "", None, diagnosis=note_diag)
    assert not draft._diagnose_note("unused", "unused", "", None,
                                    diagnosis=note_diag, byte_feedback=False)
    args_diag = {"call_argument_diffs": [{"target": ["2", "1"], "candidate": ["1", "2"]}]}
    def check_args(_client, _addr, source, _flags=None, include_diagnosis=False):
        score = 100 if "callee(b, a)" in source else 98
        row = (score, None, None, None)
        return row + (args_diag,) if include_diagnosis else row
    improved = mutate.improve("C", "1", "int f(){ return callee(a, b); }", check=check_args)
    assert improved[0] == 100 and "callee(b, a)" in improved[1] and improved.speculative
    nested = "int f(){ return callee(make(a, 1), obj.value); }"
    swapped = mutate.swap_call_argument_variants(nested)
    assert any("callee(obj.value, make(a, 1))" in variant for variant in swapped)


def test_evidence_guided_mutations_are_bounded_and_stop_on_exact():
    from roc import match, mutate
    target, candidate = bytes.fromhex("83c003c3"), bytes.fromhex("83c002c3")
    diagnosis = match.diagnose(target, [], candidate, [])
    assert diagnosis["mismatch_class"] == "immediate/constant mismatch"
    assert diagnosis["immediate_diffs"] == [{"instruction": 0, "mnemonic": "add",
                                              "target": "3", "candidate": "2"}]
    src = "int f(){ return x + 2; }"
    assert mutate.immediate_variants(src, diagnosis) == ["int f(){ return x + 3; }"]
    calls = []
    def check(_client, _addr, source, _flags=None, include_diagnosis=False):
        calls.append(source)
        if include_diagnosis:
            return 95, None, "", [], diagnosis
        return (100 if "+ 3" in source else 95), None, "", []
    result = mutate.improve("C", "1", src, check=check, guided=True)
    assert result[0] == 100 and result[2] == 1
    assert result.mutations[0]["category"] == "immediate_constant"
    assert result.mutations[0]["exact"] is True and calls[-1] == "int f(){ return x + 3; }"


def test_guided_category_filter_disables_fallback():
    from roc import mutate
    diagnosis = {"immediate_diffs": [{"candidate": "2", "target": "3"}]}
    assert mutate.guided_variants("int f(){ return 2; }", diagnosis,
                                  {"return_value"}) == []

    def check(_client, _addr, source, _flags=None, include_diagnosis=False):
        if include_diagnosis:
            return 50, None, "", [], diagnosis
        return (100 if "return 3" in source else 50), None, "", []

    result = mutate.improve("C", "1", "int f(){ return 2; }", check=check,
                            guided=True, guided_categories={"immediate_constant"},
                            guided_fallback=False)
    assert result[0] == 100 and result[2] == 1


def test_structural_low_score_skips_blind_legacy_fallback():
    from roc import mutate
    diagnosis = {"mismatch_class": "missing/extra instruction"}
    assert mutate.legacy_fallback_allowed(74, diagnosis) is False
    assert mutate.legacy_fallback_allowed(75, diagnosis) is True
    assert mutate.legacy_fallback_allowed(60, {"mismatch_class": "register allocation difference"}) is True
    assert mutate.legacy_fallback_allowed(
        98, {"mismatch_class": "register allocation difference",
             "register_delta": {"ecx": 1}}) is False
    assert mutate.legacy_fallback_allowed(
        97, {"mismatch_class": "code-size mismatch",
             "receiver_call_diffs": [{"target": "ecx", "candidate": "push"}]}) is False
    calls = []
    def check(_client, _addr, source, _flags=None, include_diagnosis=False):
        calls.append(source)
        row = (40, None, "", [])
        return row + (diagnosis,) if include_diagnosis else row
    result = mutate.improve("C", "1", "int f(){ return x + 1; }", check=check,
                            guided=True)
    assert result[2] == 0 and len(calls) == 1


def test_remaining_guided_mutation_evidence():
    from roc import match, mutate
    branch = match.diagnose(bytes.fromhex("7500c3"), [], bytes.fromhex("7400c3"), [])
    assert branch["mismatch_class"] == "branch-condition mismatch"
    assert mutate.guided_variants("int f(int a,int b){ return a == b; }", branch) == [
        ("branch_condition", "int f(int a,int b){ return a != b; }")]
    cleanup = match.diagnose(bytes.fromhex("c3"), [], bytes.fromhex("c20800"), [])
    assert cleanup["return_cleanup"] == {"target": "", "candidate": "8"}
    assert mutate.guided_variants("void __stdcall f(int a){ }", cleanup) == [
        ("calling_convention", "void __cdecl f(int a){ }")]
    assert mutate.guided_variants("int S::f(int a){ return a; }", {
        "mismatch_class": "calling-convention mismatch",
        "return_cleanup": {"target": "8", "candidate": ""}})[0] == (
        "calling_convention", "int __stdcall S::f(int a){ return a; }")
    assert not any(category == "calling_convention" for category, _ in
                   mutate.guided_variants("void f(int a){ }", cleanup))
    receiver = {"mismatch_class": "instruction-selection mismatch",
                "receiver_call_diffs": [{"target": "ecx, sym", "candidate": "0"}]}
    pointer = 'extern "C" bool (__stdcall *p)(const T*, const T*);'
    assert mutate.function_pointer_convention_variants(pointer, receiver) == [
        'extern "C" bool (__thiscall *p)(const T*, const T*);']
    pointer_call = ('extern "C" bool (__stdcall *sub_77e708)(void*, const T*);\n'
                    'bool f(void* q) { return sub_77e708(q, (const T*)0x10); }')
    pointer_variants = mutate.function_pointer_convention_variants(pointer_call, receiver)
    assert len(pointer_variants) == 2 and "sub_77e708((const T*)0x10, q)" in pointer_variants[1]
    direct = ('struct S { int f(int); };\n'
              'extern "C" int __stdcall sub(void*, int);\n'
              'int S::f(int x) { return sub(this, x); }')
    direct_variants = mutate.direct_member_receiver_variants(direct, receiver)
    assert len(direct_variants) == 1 and 'int sub(int);' in direct_variants[0]
    assert 'return sub(x);' in direct_variants[0] and 'extern "C"' not in direct_variants[0]
    direct_noarg = ('struct S { int f(int); };\n'
                    'extern "C" void __stdcall sub();\n'
                    'int S::f(int x) { sub(); return x; }')
    direct_noarg_diag = {"receiver_call_diffs": [{"direct": True}]}
    noarg_variants = mutate.direct_member_noarg_variants(direct_noarg, direct_noarg_diag)
    assert len(noarg_variants) == 1 and 'void sub();' in noarg_variants[0]
    assert 'extern "C"' not in noarg_variants[0]
    static = ('extern "C" bool __stdcall check(void*, void*);\n'
              'bool f(void* q) { return check((void*)0x1234, q); }')
    static_variants = mutate.static_receiver_pointer_variants(static, receiver)
    assert len(static_variants) == 1 and "(__thiscall *check)" in static_variants[0]
    static_return = ('extern "C" void* __stdcall check(void*, const void*);\n'
                     'bool f(void* q) { check(q, (const void*)0x1234); return true; }')
    receiver_return = dict(receiver, register_delta={"al": 1})
    variants = mutate.static_receiver_pointer_variants(static_return, receiver_return)
    assert len(variants) == 2 and "return check((const void*)0x1234, q);" in variants[1]
    indirect = ('extern "C" void* (__thiscall *check)(void*, void*);\n'
                'bool f(void* q) { check((void*)0x1234, q); return true; }')
    assert "return check((void*)0x1234, q);" in mutate.indirect_return_variants(
        indirect, receiver_return)[0]
    virtual_view = ("struct VNode { int vtbl; int ref; };\n"
                    "void f(void* old) {\n"
                    "    int* vtable = *(int**)old;\n"
                    "    void (__stdcall *release)(int) = (void (__stdcall *)(int))*vtable;\n"
                    "    release(1);\n} ")
    virtual_diag = {"mismatch_class": "register allocation difference",
                    "register_delta": {"ecx": -1, "edx": 1}}
    virtual_variants = mutate.virtual_call_view_variants(virtual_view, virtual_diag)
    assert len(virtual_variants) == 1 and "VNodeCall" in virtual_variants[0]
    assert "((VNodeCall*)old)->release(1);" in virtual_variants[0]
    slot_source = ("struct S { int f(void*); };\n"
                   "int S::f(void* arg) {\n"
                   "    if (((int (__thiscall*)(void*))*(void**)(*(char**)this + 0x14))(arg))\n"
                   "        return 1;\n    return 0;\n}")
    slot_diag = {"mismatch_class": "code-size mismatch",
                 "opcode_delta": {"mov": 1, "push": -1},
                 "register_delta": {"ecx": 1}}
    slot_variants = mutate.virtual_slot_view_variants(slot_source, slot_diag)
    assert len(slot_variants) == 1 and "virtual int slot4();" in slot_variants[0]
    assert "((VTableCallView*)this)->call(arg))" in slot_variants[0]
    carrier = ('extern "C" void* __stdcall check(void*);\n'
               'extern "C" int make(void*);\n'
               'bool f(void* q) {\n    make(q);\n    check((void*)0x1234);\n    return true;\n}')
    carrier_diag = {"return_carrier_call_diffs": [{"carried": "eax"}]}
    assert "return check((void*)0x1234, make(q));" in mutate.return_carrier_variants(
        carrier, carrier_diag)[0]
    rtti = ('struct T { bool operator==(const T&); };\n'
            'extern T typeinfo;\nextern "C" void* __cdecl sub_631392(void*);\n'
            'bool f(void* q) { return typeinfo == *(T*)q; }')
    rtti_variant = mutate.rtti_operator_variants(rtti, {"indirect_call_diffs": [{}]})[0]
    assert "__thiscall *sub_77e708" in rtti_variant and "return sub_77e708(&typeinfo" in rtti_variant
    def check_pointer(_client, _addr, source, _flags=None, include_diagnosis=False):
        value = 100 if "__thiscall *" in source else 97
        row = (value, None, "", [])
        return row + (receiver,) if include_diagnosis else row
    fixed = mutate.improve("C", "1", pointer, check=check_pointer, guided=True)
    assert fixed[0] == 100 and fixed.mutations[0]["category"] == "function_pointer_convention"
    stack = match.diagnose(bytes.fromhex("8b442408c3"), [], bytes.fromhex("8b442404c3"), [])
    assert stack["mismatch_class"] == "stack-frame/layout mismatch"
    assert mutate.guided_variants("struct S { char pad[4]; }; int f(){ return pad[0]; }", stack) == [
        ("stack_layout", "struct S { char pad[8]; }; int f(){ return pad[0]; }")]
    intrinsic = {"mismatch_class": "intrinsic/call mismatch"}
    assert mutate.intrinsic_call_variants("long InterlockedExchangeAdd(long* p,long n){return 0;}", intrinsic) == [
        "long _InterlockedExchangeAdd(long* p,long n){return 0;}"]
    ret = match.diagnose(bytes.fromhex("56568bc6c35e5fc3"), [],
                         bytes.fromhex("56565e5fc3"), [])
    assert ret["mismatch_class"] == "missing return value"
    assert mutate.guided_variants("struct S { void f(){ } };", ret) == [
        ("return_value", "struct S { void* f(){ \n    return this;\n} };")]


def test_cdecl_member_and_free_function_convention_variants():
    from roc import match, mutate
    # member thiscall candidate (ret 4) vs __cdecl target (plain ret):
    # keyword must go on the in-class declaration, not the definition
    diag = {"return_cleanup": {"target": "", "candidate": "4"}}
    src = ("struct S {\n    void f(int a);\n};\n\nvoid S::f(int a) { int x = a; }\n")
    fixes = mutate.cdecl_member_variants(src, diag)
    assert fixes == ["struct S {\n    void __cdecl f(int a);\n};\n\nvoid S::f(int a) { int x = a; }\n"]
    assert mutate.cdecl_member_variants("void f(int a){ }", diag) == []
    # member whose body never uses this can become a free function
    free = mutate.free_function_variants(src, diag)
    assert free == ["struct S {\n};\n\nvoid __cdecl f(int a) { int x = a; }\n"]
    uses_this = "struct S { void f(int a); };\nvoid S::f(int a) { g(this); }\n"
    assert mutate.free_function_variants(uses_this, diag) == []
    # evidence-driven trigger: ret cleanup differs even when the classifier
    # called the mismatch something else
    mixed = match.diagnose(bytes.fromhex("7400c3"), [], bytes.fromhex("7500c20400"), [])
    assert mixed["mismatch_class"] == "branch-condition mismatch"
    assert mixed["return_cleanup"] == {"target": "", "candidate": "4"}
    variants = mutate.guided_variants(
        "struct S {\n    void f(int a);\n};\nvoid S::f(int a) { if (a > 0) g(); }", mixed)
    assert any(category == "calling_convention" for category, _ in variants)


def test_diagnose_frame_size():
    from roc import match
    target = bytes.fromhex("81ec00010000")          # sub esp, 0x100
    candidate = bytes.fromhex("81ec00020000")        # sub esp, 0x200
    diag = match.diagnose(target, [], candidate, [])
    assert diag["frame_size"] == {"target": 256, "candidate": 512}


def test_align_insns_scores_and_ops():
    """Instruction-alignment scoring adapted from cpp_permuter/decomp-permuter:
    register renaming is cheap, argument differences cost more, and a
    missing+extra instruction pair costs most."""
    from roc import match
    identical = match.align_insns(bytes.fromhex("b801000000"), [], bytes.fromhex("b801000000"), [])
    assert identical["cost"] == 0
    assert [s["op"] for s in identical["steps"]] == ["same"]
    regalloc = match.align_insns(bytes.fromhex("b801000000"), [], bytes.fromhex("bb01000000"), [])
    assert regalloc["cost"] == match.ALIGN_PENALTY_REGALLOC
    assert [s["op"] for s in regalloc["steps"]] == ["regalloc"]
    args = match.align_insns(bytes.fromhex("b801000000"), [], bytes.fromhex("b802000000"), [])
    assert args["cost"] == match.ALIGN_PENALTY_ARGS
    assert [s["op"] for s in args["steps"]] == ["args"]
    deleted = match.align_insns(bytes.fromhex("b80100000090"), [], bytes.fromhex("b801000000"), [])
    assert deleted["cost"] == match.ALIGN_PENALTY_DELETE
    assert [s["op"] for s in deleted["steps"]] == ["same", "del"]
    # relocation-only difference: the same instruction text once masked
    reloc = match.align_insns(bytes.fromhex("a100000000"), [0], bytes.fromhex("a100000000"), [0])
    assert reloc["cost"] == 0
    # different mnemonics never substitute: del+ins instead of a cheap arg swap
    multi = match.align_insns(bytes.fromhex("b801000000c3"), [], bytes.fromhex("b801000000c20400"), [])
    assert multi["cost"] >= match.ALIGN_PENALTY_ARGS


def test_permutation_transforms_are_semantics_preserving():
    from roc import mutate
    src = ("struct S {\n"
           "    int f(int a);\n"
           "};\n\n"
           "int S::f(int a) {\n"
           "    int v1;\n"
           "    int v2;\n\n"
           "    v1 = g(a) + h(a);\n"
           "    if (a >= 2)\n"
           "        v2 = a * 3;\n"
           "    return v1 + v2;\n"
           "}\n")
    swaps = mutate.commutative_swap_variants(src)
    assert any("h(a) + g(a)" in v for v in swaps)
    assert any("v2 + v1" in v for v in swaps)
    ineq = mutate.inequality_swap_variant(src)
    assert "2 <= a" in ineq
    decls = mutate.reorder_decls_variants(src)
    assert decls and decls[0].index("int v2;") < decls[0].index("int v1;")
    # blank-line structure between declarations is preserved
    assert "\n\n    v1 = g(a)" in decls[0]
    # every variant is distinct, the original never comes back
    variants = mutate.permute_variants(src, None)
    assert len({v for _, v in variants}) == len(variants)
    assert src not in {v for _, v in variants}


def test_permute_variants_rank_by_alignment_evidence():
    from roc import mutate
    src = ("int f(int a) {\n"
           "    int v1;\n"
           "    int v2;\n\n"
           "    v1 = g(a) + h(a);\n"
           "    if (a >= 2)\n"
           "        v2 = v1 + a;\n"
           "    return v2;\n"
           "}\n")
    canonical = [c for c, _ in mutate.permute_variants(src, None)]
    assert canonical[0] == "commutative"
    regalloc_heavy = {"steps": [{"op": "regalloc"}] * 5 + [{"op": "args"}]}
    ranked = [c for c, _ in mutate.permute_variants(src, regalloc_heavy)]
    assert ranked[0] == "reorder_decls"
    args_heavy = {"steps": [{"op": "args"}] * 5}
    ranked = [c for c, _ in mutate.permute_variants(src, args_heavy)]
    assert ranked[0] == "commutative"


def test_improve_permute_is_bounded_and_opt_in():
    from roc import mutate
    calls = []

    def check(_client, _addr, source, _flags=None, include_diagnosis=False):
        calls.append(source)
        if include_diagnosis:
            return 80, None, "", [], {"return_cleanup": {"target": "", "candidate": ""}}
        return (100 if len(calls) == 2 else 80), None, "", []

    src = "int f(int a){ return g(a) + h(a); }"
    # permute is opt-in: the bounded permutation arm only runs when asked
    mutate.improve("C", "1", src, check=check, alignment=False)
    legacy_attempts = len(calls)
    assert legacy_attempts >= 1  # legacy mutators keep their existing behavior
    calls.clear()
    result = mutate.improve("C", "1", src, check=check, permute=True, alignment=False)
    assert result[0] == 100 and result[2] >= 1
    assert len(calls) <= mutate.MAX_VARIANTS + 1  # base check plus the bounded list


def test_guided_variants_are_tried_before_permutations():
    """Guided evidence yields more per candidate than permutations, so the
    bounded list must order guided first or permutations crowd it out
    (measured: 10 improved alone, 8 with permutations first)."""
    from roc import mutate
    src = ("struct S {\n    void f(int a);\n};\nvoid S::f(int a) { if (a > 0) g(); }\n")
    diagnosis = {"return_cleanup": {"target": "", "candidate": "4"},
                 "frame_size": {"target": 8, "candidate": 12}}
    calls = []

    def check(_client, _addr, source, _flags=None, include_diagnosis=False):
        calls.append(source)
        if include_diagnosis:
            return 80, None, "", [], diagnosis
        return 80, None, "", []

    mutate.improve("C", "1", src, check=check, guided=True, permute=True, alignment=False)
    assert calls
    # the first attempted variant is the guided __cdecl fix, not a permutation
    assert "__cdecl" in calls[1]


def test_alignment_evidence_compiles_candidate():
    from roc import match, mutate
    # alignment evidence fails soft on an uncompilable candidate
    assert mutate is not None
    diag = {"return_cleanup": {"target": "", "candidate": ""}}
    diag["frame_size"] = {"target": 4, "candidate": 8}
    src = "void f(int a){ }"
    variants = mutate.permute_variants(src, diag)
    assert variants == []  # no transform available: nothing to try


def test_mismatch_class_and_mutation_summary():
    from roc import match
    immediate = match.diagnose(bytes.fromhex("83c003c3"), [], bytes.fromhex("83c002c3"), [])
    branch = match.diagnose(bytes.fromhex("7500c3"), [], bytes.fromhex("7400c3"), [])
    assert immediate["mismatch_class"] == "immediate/constant mismatch"
    assert branch["mismatch_class"] == "branch-condition mismatch"
    summary = _metrics.summarize_runs([{
        "score": 100, "seconds": 1,
        "rounds": [{"round": 1, "code": True, "score": 99,
                    "mismatch_class": immediate["mismatch_class"]},
                   {"round": "mutate", "exact_conversion": True, "mutations": [
                       {"category": "immediate_constant", "exact": True, "seconds": 0.1},
                       {"category": "branch_condition", "exact": False, "seconds": 0.2}]}]}])
    assert summary["mismatch_classes"] == {"immediate/constant mismatch": 1}
    assert summary["mutation_exact_conversions"] == 1
    assert summary["mutation_attempts"] == 2
    assert summary["mutation_exact_by_category"] == {"immediate_constant": 1}
    assert summary["mutation_seconds"] == 0.3


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
    result = mutate.improve("C", "1", src, check=fake_check)
    best, out, tried, spec = result[0], result[1], result[2], result.speculative
    assert (best, tried) == (90, len(vs)) and "unsigned char" in out
    assert spec is False  # signedness toggle is semantics-preserving
    # old 3-unpacking callers keep working (mixed-version safety)
    legacy_score, legacy_src, legacy_tried = mutate.improve("C", "1", src, check=fake_check)
    assert (legacy_score, legacy_tried) == (90, len(vs))
    def boom(c, a, t, f=None):
        raise CompileError("nope")
    assert mutate.improve("C", "1", src, check=boom)[0] == 0
    neg = "int f(int a, int b)\n{\n    return a == b;\n}\n"
    def prefer_neg(c, a, t, f=None):
        return (80 if "!=" in t else 10, None, None, None)
    assert mutate.improve("C", "1", neg, check=prefer_neg).speculative is True


def test_mutate_preserves_diagnosis_metadata():
    def diagnosed_check(c, a, t, f=None, include_diagnosis=False):
        result = (50, None, None, None)
        return result + ({"mismatch_class": "calling convention mismatch",
                          "classifications": ["return cleanup"]},) if include_diagnosis else result
    result = mutate.improve("C", "1", "int f(){ return 1; }", check=diagnosed_check)
    assert result.diagnosis["mismatch_class"] == "calling convention mismatch"
    assert result.diagnosis["classifications"] == ["return cleanup"]


def test_topk_and_benchmark_summary():
    topk = select_topk([(50, "a"), (90, "b"), (90, "b "), (70, "c")])
    assert topk == [(90, "b"), (70, "c"), (50, "a")]
    jobs = [{"score": 100, "seconds": 10.0, "rounds": [{"round": 1, "score": 100, "code": True}]},
            {"score": 0, "seconds": 20.0, "rounds": [{"round": 1, "score": 0, "code": True,
                                                      "compile_error": "C2039"}]}]
    s = _metrics.summarize_runs(jobs)
    assert s["jobs"] == 2 and s["matched"] == 1 and s["seconds_per_match"] == 30.0
    assert s["compile_success_rate"] == 0.5
    assert s["compile_attempts"] == 2 and s["rejected_inline_asm"] == 0
    assert _metrics.known_generation_cost([{"round": 1, "provider": "nvidia", "estimated_cost": None}]) is None
    assert _metrics.known_generation_cost([{"round": 1, "provider": "nvidia", "estimated_cost": 0.25}]) == 0.25
    old_path = _metrics.PATH
    with tempfile.TemporaryDirectory() as temp:
        _metrics.PATH = Path(temp) / "metrics.jsonl"
        _metrics.record("token-summary", event="job", score=0, improved=False, seconds=1,
                        source_hints=0, source_candidate=False, source_candidate_hit=False,
                        phase_seconds={}, compile_seconds=0, provider="deepseek",
                        input_tokens=12, output_tokens=7, cached_tokens=3, estimated_cost=None)
        text = _metrics.summary("token-summary")
        assert "tokens=in:12 out:7 cached:3" in text and "cost=unknown" in text
        totals = _metrics.session_totals("token-summary")
        assert (totals["input_tokens"], totals["output_tokens"], totals["jobs"]) == (12, 7, 1)
        from roc import worker as _worker
        line = _worker._usage_line("token-summary", [{"round": 1, "input_tokens": 10, "output_tokens": 5}])
        assert line == "  tokens used: 15 (in:10 out:5), total usage: 34 (in:22 out:12)"
    _metrics.PATH = old_path


def test_truncation_disables_thinking(monkeypatch):
    from roc import draft
    seen = []
    replies = iter(["thinking..." * 500, "```cpp\nint f() { return 1; }\n```"])
    def ask(model, prompt, context=None, options=None, details=False):
        seen.append(dict(options or {}))
        reply = next(replies)
        if "```" not in reply:
            return reply, None, {"output_tokens": 3000, "finish_reason": "length"}
        return reply, None, {"output_tokens": 20, "finish_reason": "stop"}
    monkeypatch.setattr(draft, "_ask_context", ask)
    monkeypatch.setattr(draft.match, "target", lambda *args: (b"\xc3", [], {"size": 9, "unit": "x"}))
    monkeypatch.setattr(draft.match, "disasm", lambda *args: ["ret "])
    monkeypatch.setattr(draft, "prompt_for", lambda *args, **kwargs: "p")
    monkeypatch.setattr(draft.match, "check_text", lambda *args, **kwargs: (100, None, "", None))
    logs = []
    score, _ = draft.llm_rounds("C", "1", "deepseek:deepseek-flash", 2, log=logs.append,
                                 provider_options={"allow_cloud": True})
    assert score == 100 and len(seen) == 2
    assert all(row.get("thinking") == "disabled" for row in seen)
    assert all("reasoning_effort" not in row for row in seen)


def test_tiny_cloud_auto_thinking_starts_disabled(monkeypatch):
    from roc import draft
    seen = []
    def ask(model, prompt, context=None, options=None, details=False):
        seen.append(dict(options or {}))
        return "```cpp\nint f(){return 1;}\n```", None, {"finish_reason": "stop"}
    monkeypatch.setattr(draft, "_ask_context", ask)
    monkeypatch.setattr(draft.match, "target", lambda *args: (b"\xc3", [], {"size": 12, "unit": "x"}))
    monkeypatch.setattr(draft.match, "disasm", lambda *args: ["ret "])
    monkeypatch.setattr(draft, "prompt_for", lambda *args, **kwargs: "p")
    monkeypatch.setattr(draft.match, "check_text", lambda *args, **kwargs: (100, None, "", None))
    draft.llm_rounds("C", "1", "deepseek:deepseek-flash", 1,
                     provider_options={"allow_cloud": True, "thinking": "auto"}, log=lambda *_: None)
    assert seen[0].get("thinking") == "disabled"


def test_asm_strikes_stop_early(monkeypatch):
    from roc import draft
    calls = []

    def ask(model, prompt, context=None, options=None, details=False):
        calls.append(prompt)
        return "```cpp\nvoid f() { __asm { nop } }\n```", None, {"output_tokens": 10}

    monkeypatch.setattr(draft, "_ask_context", ask)
    monkeypatch.setattr(draft.match, "target", lambda *args: (b"\xc3", [], {"size": 9, "unit": "x"}))
    monkeypatch.setattr(draft.match, "disasm", lambda *args: ["ret "])
    monkeypatch.setattr(draft, "prompt_for", lambda *args, **kwargs: "p")
    stats, logs = [], []
    score, source = draft.llm_rounds("C", "1", "m", 4, log=logs.append, stats=stats)
    assert score == 0 and source is None and len(calls) == 2
    assert any("inline asm twice" in message for message in logs)
    assert any(s.get("reason") == "inline asm x2" for s in stats)


def test_asm_strikes_stop_early(monkeypatch):
    from roc import draft
    calls = []

    def ask(model, prompt, context=None, options=None, details=False):
        calls.append(prompt)
        return "```cpp\nvoid f() { __asm { nop } }\n```", None, {"output_tokens": 10}

    monkeypatch.setattr(draft, "_ask_context", ask)
    monkeypatch.setattr(draft.match, "target", lambda *args: (b"\xc3", [], {"size": 9, "unit": "x"}))
    monkeypatch.setattr(draft.match, "disasm", lambda *args: ["ret "])
    monkeypatch.setattr(draft, "prompt_for", lambda *args, **kwargs: "p")
    stats, logs = [], []
    score, source = draft.llm_rounds("C", "1", "m", 4, log=logs.append, stats=stats)
    assert score == 0 and source is None and len(calls) == 2
    assert any("inline asm twice" in message for message in logs)
    assert any(s.get("reason") == "inline asm x2" for s in stats)


def test_qualified_type_definition_rejected():
    from roc import draft
    assert draft.invalid_qualified_definition("struct RBX::FaceInstance { int x; };")
    assert not draft.invalid_qualified_definition("namespace RBX { struct FaceInstance { int x; }; }")
    assert "numeric address" in draft.source_contract_error("int f(){ return 0x401000(1); }")


def test_selfupdate():
    from roc import selfupdate
    import subprocess
    real_which, real_run = shutil.which, subprocess.run

    class Done:
        def __init__(self, code=0, out=""):
            self.returncode, self.stdout = code, out

    def run_case(which, sides, raises=None):
        import roc.selfupdate as su
        su.shutil.which = lambda *a: which
        def fake_run(*args, **k):
            if raises:
                raise raises
            return sides.pop(0)
        su.subprocess.run = fake_run
        try:
            return su.try_update(log=lambda *a: None)
        finally:
            su.shutil.which, su.subprocess.run = real_which, real_run

    assert "git not installed" in run_case(None, [])
    with patch.object(Path, "exists", return_value=False):
        assert "not a git checkout" in run_case("git", [])
    assert "local source edits" in run_case("git", [Done(1)])                       # diff --quiet
    assert "offline" in run_case("git", [Done(0), Done(1)])                          # fetch fails
    assert "current" in run_case("git", [Done(0), Done(0), Done(0, "0\n")])          # behind 0
    assert run_case("git", [Done(0), Done(0), Done(0, "3\n"), Done(0)]) == "updated"  # pull ok
    assert "as-is" in run_case("git", [Done(0), Done(0), Done(0, "3\n"), Done(1)])   # pull fails
    assert "as-is" in run_case("git", [], raises=subprocess.TimeoutExpired("git", 1))
    assert "as-is" in run_case("git", [], raises=OSError("nope"))


def test_repair_safety_guards():
    # namespaced qualifiers are never renamed, even with one class present
    ns = "struct V {\n    int x;\n};\nint RBX::VInstance::Create()\n{\n    return 0;\n}\n"
    assert _repair.ensure_member_declared(ns) is None
    # STL qualifiers are never renamed
    stl = "struct E {\n    int v[4];\n};\nint vector::size()\n{\n    return 0;\n}\n"
    assert _repair.ensure_member_declared(stl) is None
    # calling convention survives into the inserted declaration
    conv = "struct S {\n    int x;\n};\nint __stdcall S::f(int a)\n{\n    return a;\n}\n"
    fixed = _repair.ensure_member_declared(conv)
    assert fixed is not None and "int __stdcall f(int a);" in fixed
    # win typedefs only for identifiers the compiler reported missing
    wsrc = "struct W {\n    DWORD d;\n    int e;\n};\nint W::f()\n{\n    return d;\n}\n"
    assert _repair.add_win_typedefs(wsrc, "error C2065: 'DWORD' : undeclared") is not None
    assert _repair.add_win_typedefs(wsrc, "error C2065: 'HANDLE' : undeclared") is None
    assert "struct HDC__; typedef struct HDC__ *HDC;" in _repair.add_win_typedefs(
        "HDC h;", "error C2065: 'HDC' : undeclared")
    # `this` rename still fires with std:: mentions but no qualified definition
    free = "int g(std::vector<int>* v, X* this)\n{\n    return this->x;\n}\n"
    assert _repair.rename_this_identifier(free) is not None
    assert _repair.rename_this_identifier(
        "struct S {\n    int f();\n};\nint S::f()\n{\n    return this->x;\n}\n") is None


def test_auto_import_skips_dropped_functions():
    from roc.server import Store, import_auto_matches
    st = Store(":memory:", lease_seconds=1)
    st.db.execute("INSERT INTO funcs(client,addr,size,unit) VALUES('C','00401000',6,'A')")
    st.db.commit()
    # 00401040 was dropped by re-analysis (the 2009-12 startup crash): skipped, server lives.
    assert import_auto_matches(st, "C", {"00401000": "void f(){}\n", "00401040": "void g(){}\n"},
                               log=lambda *a: None) == (1, 1)
    assert st.scores() == {"C": {"00401000": 100}}
    try:
        st.submit("C", "00401040", "alice", 100, "x")
        raise AssertionError("unknown function accepted")
    except ValueError:
        pass


def test_truncated_generation_history_reset():
    from roc import draft
    for enabled in (False, True, None):
        contexts, attempts = [], []

        def ask(model, prompt, context=None, options=None, details=False):
            contexts.append(context)
            assert "reset_truncated" not in options
            if len(contexts) == 1:
                return "struct S {", {"malformed": True}, {"finish_reason": "length", "output_tokens": 1024}
            return "```cpp\nint f() { return 1; }\n```", None, {"finish_reason": "stop", "output_tokens": 12}

        def prompt(*args, **kwargs):
            attempts.append(args[5])
            return "target"

        with patch.object(draft, "_ask_context", side_effect=ask), \
             patch.object(draft, "prompt_for", side_effect=prompt), \
             patch.object(draft.match, "target", return_value=(b"\xc3", [], {"size": 9, "unit": "S"})), \
             patch.object(draft.match, "disasm", return_value=["ret"]), \
             patch.object(draft.match, "check_text", return_value=(100, None, "", [])):
            options = {} if enabled is None else {"reset_truncated": enabled}
            score, _ = draft.llm_rounds("C", "1", "deepseek:deepseek-flash", 2,
                                        log=lambda _: None, provider_options=options)
        assert score == 100 and len(contexts) == 2
        reset = enabled is not False
        assert contexts[1] == (None if reset else {"malformed": True})
        assert bool(attempts[1]) == reset


def test_base_padding_variant_uses_decoded_field_delta():
    from roc import mutate
    src = "struct S : B { char pad[0x11c - 8]; int field; };"
    diagnosis = {"stack_offset_diffs": [{"candidate": "0x11c", "target": "0x124"}]}
    assert mutate.guided_variants(src, diagnosis) == [
        ("base_padding", "struct S : B { char pad[0x124 - 8]; int field; };")]


def test_hidden_exact_sources_stay_byte_exact():
    from roc import match
    for addr in ("00401880", "0041eb40", "0041faa0", "0042d840", "0044a1d0",
                 "00460120", "00460190", "00472e90", "004aca90", "004c1b50",
                 "00530880", "00549000", "00580f90", "00580fb0", "0059c7d0",
                 "005f9ff0", "005fc710", "00608490", "006274b0", "0063dcb0",
                 "0064ec50", "0065eb30", "00662440", "006692b0", "00690a90",
                 "004b8aa0", "004d06b0", "006a79f0", "006c79f0", "00775fd0", "004aa3f0"):
        source = Path("src/2007-08/%s.cpp" % addr).read_text()
        assert match.check_text("2007-08", addr, source)[0] == 100


def test_truncated_partial_code_history_reset():
    from roc import draft
    for enabled in (False, True, None):
        contexts, attempts = [], []

        def ask(model, prompt, context=None, options=None, details=False):
            contexts.append(context)
            if len(contexts) == 1:
                return "```cpp\nstruct S { int field;\n```", {"malformed": True}, {
                    "finish_reason": "length", "output_tokens": 1024}
            return "```cpp\nint f() { return 1; }\n```", None, {"finish_reason": "stop", "output_tokens": 12}

        with patch.object(draft, "_ask_context", side_effect=ask), \
             patch.object(draft, "prompt_for", side_effect=lambda *args, **kwargs: attempts.append(args[5]) or "target"), \
             patch.object(draft.match, "target", return_value=(b"\xc3", [], {"size": 9, "unit": "S"})), \
             patch.object(draft.match, "disasm", return_value=["ret"]), \
             patch.object(draft.match, "check_text", return_value=(100, None, "", [])):
            options = {} if enabled is None else {"reset_truncated": enabled}
            score, _ = draft.llm_rounds("C", "1", "deepseek:deepseek-flash", 2,
                                        log=lambda _: None, provider_options=options)
        assert score == 100 and len(contexts) == 2
        reset = enabled is not False
        assert contexts[1] == (None if reset else {"malformed": True})
        assert bool(attempts[1]) == reset


if __name__ == "__main__":
    import inspect
    for name, fn in list(globals().items()):
        if name.startswith("test_"):
            if inspect.signature(fn).parameters:
                continue  # needs pytest fixtures; run under pytest
            fn()
            print("ok ", name)
