"""Draft sources for the worker: Rev.ng (hint C) and Ollama (writes C++).

The LLM gets the target asm, the Rev.ng hint, and after each try the asm diff
or compile error of its last attempt, so it can converge on a byte match.
"""
import html
import json
import os
import re
import time
import shutil
import struct
import subprocess
import tempfile
import urllib.request
import urllib.error
import functools
from pathlib import Path

from roc import match

OLLAMA = "http://127.0.0.1:11434"
PREFERRED_MODELS = ["qwen2.5-coder:14b", "qwen2.5-coder:7b-instruct", "qwen2.5-coder:7b",
                    "qwen2.5-coder", "deepseek-coder-v2", "codellama"]
MODEL_PROFILES = (("qwen2.5-coder:14b", {"num_ctx": 8192, "num_predict": 2048}),
                  ("qwen2.5-coder:7b", {"num_ctx": 6144, "num_predict": 1536}),)
MODEL_ROUNDS = (("qwen2.5-coder:14b", 5), ("qwen2.5-coder:7b", 3))
REVNG_IMAGE = "revng/revng:latest"


# ---------- Rev.ng ----------

def mini_elf(code, va):
    """Wrap one function's bytes in an ELF32 i386 exec at its original address."""
    page = va & ~0xFFF
    pad = va - page
    ehdr = b"\x7fELF\x01\x01\x01" + b"\0" * 9 + struct.pack(
        "<HHIIIIIHHHHHH", 2, 3, 1, va, 52, 0, 0, 52, 32, 1, 0, 0, 0)
    phdr = struct.pack("<IIIIIIII", 1, 0x1000, page, page, pad + len(code), pad + len(code), 5, 0x1000)
    head = ehdr + phdr
    return head + b"\0" * (0x1000 - len(head)) + b"\0" * pad + code


@functools.lru_cache(maxsize=1)
def _docker():
    """Docker's path, resolved once. winget puts it outside the running process's
    PATH, so which() alone reports a freshly installed Docker Desktop as missing.
    Cached: this is called per function in a worker run, and PATH lookups are not free."""
    from roc import setup
    setup.refresh_path()
    return setup.find_exe("docker")


def revng_available():
    docker = _docker()
    if not docker:
        return False
    try:
        run = subprocess.run([docker, "image", "inspect", REVNG_IMAGE], capture_output=True, timeout=30)
    except (OSError, subprocess.TimeoutExpired):
        return False
    return run.returncode == 0


def revng_c(code, va, timeout=120):
    """Rev.ng's C for one function, or None. Types are generic; it is a hint."""
    with tempfile.TemporaryDirectory() as tmp:
        Path(tmp, "f.elf").write_bytes(mini_elf(code, va))
        docker = _docker()
        if not docker:
            return None
        try:
            run = subprocess.run(
                [docker, "run", "--rm", "-v", "%s:/w" % tmp, REVNG_IMAGE, "bash", "-lc",
                 "cd /w && revng quick artifact emit-c-as-single-file f.elf"],
                capture_output=True, text=True, timeout=timeout)
        except (OSError, subprocess.TimeoutExpired):
            return None
    if run.returncode or "function_0x" not in run.stdout:
        return None
    text = html.unescape(re.sub(r"<[^>]+>", "", run.stdout))
    text = "\n".join(l for l in text.splitlines() if l.strip() and not l.startswith("#include"))
    return text.replace("_ABI(SystemV_x86)\n", "")


# ---------- Ollama ----------

def _get(path, payload=None, timeout=600):
    data = json.dumps(payload).encode() if payload is not None else None
    req = urllib.request.Request(OLLAMA + path, data=data, headers={"Content-Type": "application/json"})
    with urllib.request.urlopen(req, timeout=timeout) as r:
        return json.loads(r.read())


def ollama_models():
    try:
        return [m.get("name") or m["model"] for m in _get("/api/tags", timeout=5).get("models", [])]
    except (OSError, ValueError, KeyError):
        return []


def pick_model(wanted=None):
    from roc import providers
    models = ollama_models()
    if wanted == "default":
        wanted = None
    if wanted:
        if providers.is_cloud(wanted):
            return wanted if providers.available(wanted) else None
        if wanted.startswith("local:"):
            return wanted if wanted[6:] in models else None
        return wanted if wanted in models else None
    for want in PREFERRED_MODELS:
        for m in models:
            if m == want or m.startswith(want + ":"):
                return m
    return models[0] if models else None


def route_model(default, job, installed=None, automatic=True):
    """Use the faster installed coder for tiny leaf jobs; keep explicit choice untouched."""
    if not automatic:
        return default
    installed = installed if installed is not None else ollama_models()
    if not default or job.get("size", 999999) > 64 or job.get("calls", 0):
        return default
    if len(installed) > 1:
        from roc import metrics
        stats = {row["model"]: row for row in metrics.model_stats() if row["jobs"] >= 3}
        measured = [stats[m] for m in installed if m in stats and stats[m]["match_rate"] > 0]
        if measured:
            return max(measured, key=lambda row: (row["match_rate"], row["score_gain"], -row["avg_seconds"]))["model"]
    for name in installed:
        if name == "qwen2.5-coder:7b" or name.startswith("qwen2.5-coder:7b"):
            return name
    return default


def model_profile(model):
    """Conservative per-model context/output defaults; unknown models stay supported."""
    from roc import providers
    if providers.is_cloud(model):
        return {"max_tokens": 1024}
    for prefix, profile in MODEL_PROFILES:
        if model == prefix or model.startswith(prefix + ":"):
            return dict(profile)
    return {"num_ctx": 8192, "num_predict": 2048}


def model_rounds(model, requested):
    """Conservative retry budget per model; explicit worker rounds remain an upper bound."""
    for prefix, cap in MODEL_ROUNDS:
        if model == prefix or model.startswith(prefix):
            return min(int(requested), cap)
    return int(requested)


def output_budget(size):
    """Bound cloud/local output before a giant function can burn a whole worker."""
    if size <= 32:
        return 256
    if size <= 128:
        return 512
    return 1024


def _ask_context(model, prompt, context=None, options=None, details=False):
    """Provider-neutral ask. The old two-value result stays public compatibility."""
    from roc import providers
    options = dict(options or {})
    profile = model_profile(model)
    options.setdefault("max_tokens", profile.get("max_tokens", profile.get("num_predict", 1024)))
    if "num_predict" in profile:
        profile = dict(profile)
        profile["num_predict"] = min(profile["num_predict"], options["max_tokens"])
    options.setdefault("profile", profile if "num_predict" in profile else {})
    generation = providers.generate(model, prompt, options=options, state=context)
    result = (generation.text, generation.state)
    return result + (generation.telemetry(),) if details else result


def ask(model, prompt):
    """Generate one bounded reply; compatibility wrapper for callers/tests."""
    return _ask_context(model, prompt)[0]


def extract_code(reply):
    blocks = re.findall(r"```(?:cpp|c\+\+|c)?\s*\n(.*?)```", reply, re.S)
    if blocks:
        return max(blocks, key=len).strip() + "\n"
    # Some providers ignore the fence contract and return plain C++. Recover a
    # balanced function only when its signature is unmistakable; never pass prose
    # or a partial brace block to the compiler.
    text = str(reply or "").strip()
    match = re.search(r"(?m)^[ \t]*(?:[A-Za-z_]\w*[ \t*&]+)?[A-Za-z_]\w*(?:\s*::\s*[A-Za-z_]\w*)?\s*\([^;{}]*\)\s*(?:const\s*)?\{", text)
    if not match:
        return None
    start = match.start()
    prior = text[:start]
    declaration = list(re.finditer(r"(?m)^[ \t]*(?:struct|class)\s+[A-Za-z_]\w*\s*\{", prior))
    if declaration and re.search(r"\};\s*$", prior[declaration[-1].start():]):
        start = declaration[-1].start()
    open_brace = text.find("{", match.start())
    depth, quote, end = 0, None, None
    for index in range(open_brace, len(text)):
        char = text[index]
        if quote:
            if char == "\\":
                continue
            if char == quote:
                quote = None
        elif char in "\"'":
            quote = char
        elif char == "{":
            depth += 1
        elif char == "}":
            depth -= 1
            if depth == 0:
                end = index + 1
                break
    return text[start:end].strip() + "\n" if end else None


def invalid_qualified_definition(src):
    """C++ forbids defining a class with a qualified declarator."""
    return bool(re.search(r"\b(?:struct|class|enum)\s+[A-Za-z_]\w*(?:::[A-Za-z_]\w*)+\s*\{", src or ""))


def source_contract_error(src):
    """Cheap invalid-output gate; no guessed C++ rewrite is performed here."""
    src = src or ""
    if src.count("{") != src.count("}"):
        return "unbalanced braces"
    if re.search(r"\b0x[0-9A-Fa-f]+\s*\(", src):
        return "numeric address used as function name"
    if re.search(r"\b(?:mov|lea|push|pop|call|ret|jmp|cmp|test|add|sub|imul|xor|and|or|shl|shr)\s*\(", src):
        return "assembly pseudo-instruction used as C++ call"
    # Declarations alone cannot emit the requested function. Inline or out-of-class
    # definitions are both accepted; constructors intentionally have no return type.
    if not re.search(r"(?:\b[A-Za-z_]\w*\s*::\s*)?[~A-Za-z_]\w*\s*\([^;{}]*\)\s*(?:const\s*)?\{", src):
        return "missing function definition"
    return ""


def compile_failure_class(error):
    text = str(error or "")
    if "C2059" in text or "C2143" in text:
        return "invalid expression or call syntax"
    if "C2227" in text:
        return "receiver/object pointer misuse"
    if "C2614" in text:
        return "invalid member/base initializer"
    if "C2065" in text:
        return "undeclared identifier"
    if "C2027" in text:
        return "undefined qualified type"
    if "C2374" in text:
        return "duplicate local declaration"
    return ""


def _insn(line):
    """Drop match.disasm's address/hex prefix without touching plain asm test input."""
    return re.sub(r"^[0-9a-fA-F]{8}\s+[0-9a-fA-F]+\s+", "", line or "").strip()


def cfg_outline(asm, limit=12):
    """Compact CFG from match.disasm output; plain asm intentionally yields none."""
    decoded = []
    for line in asm:
        m = re.match(r"^([0-9a-fA-F]{8})\s+([0-9a-fA-F]+)\s+(.*)$", line or "")
        if m:
            decoded.append((int(m.group(1), 16), len(m.group(2)) // 2, m.group(3).strip()))
    if not decoded:
        return "CFG unavailable (assembly has no addresses)"
    addresses = {addr for addr, _size, _text in decoded}
    starts = {decoded[0][0]}
    for i, (addr, size, text) in enumerate(decoded):
        op = text.split(None, 1)[0] if text else ""
        target = re.search(r"\b0x([0-9a-fA-F]+)\b", text)
        if op.startswith("j") and target and int(target.group(1), 16) in addresses:
            starts.add(int(target.group(1), 16))
        if (op.startswith("j") or op == "ret") and i + 1 < len(decoded):
            starts.add(decoded[i + 1][0])
    starts = sorted(starts)
    index = {addr: i for i, addr in enumerate(starts)}
    blocks, loops = [], []
    for i, start in enumerate(starts[:limit]):
        end = starts[i + 1] if i + 1 < len(starts) else None
        lines = [row for row in decoded if row[0] >= start and (end is None or row[0] < end)]
        if not lines:
            continue
        _addr, _size, text = lines[-1]
        op = text.split(None, 1)[0] if text else ""
        target = re.search(r"\b0x([0-9a-fA-F]+)\b", text)
        edges = []
        if op.startswith("j"):
            dst = int(target.group(1), 16) if target else None
            if dst in index:
                edges.append("B%d" % index[dst])
                if index[dst] <= i:
                    loops.append("B%d->B%d" % (i, index[dst]))
            elif dst is not None:
                edges.append("external")
            if op != "jmp" and i + 1 < len(starts):
                edges.append("B%d" % (i + 1))
        elif op == "ret":
            edges.append("return")
        elif i + 1 < len(starts):
            edges.append("B%d" % (i + 1))
        blocks.append("B%d@%08x:%s" % (i, start, "/".join(edges) or "end"))
    suffix = " loops=" + ",".join(loops[:4]) if loops else ""
    return " ".join(blocks) + suffix


def facts_from_asm(asm):
    """Cheap, stable facts useful to source retrieval and prompt grounding."""
    asm = [_insn(line) for line in asm]
    calls = [line for line in asm if re.search(r"\bcall\b", line)]
    branches = [line for line in asm if re.match(r"j(?:mp|[a-z]+)\b", line)]
    offsets = sorted(set(re.findall(r"\[ecx \+ (0x[0-9a-f]+)]", "\n".join(asm))))
    returns = [line.strip() for line in asm if re.search(r"\bret(?:\s|$)", line)]
    imports = [line.strip() for line in calls if "dword ptr" in line]
    return {"calls": len(calls), "branch_count": len(branches), "imports": imports[:8], "this_offsets": offsets[:16],
            "returns": returns[-1:]}


def reconstruction_outline(asm, facts=None):
    """Small, deterministic CFG/signature scaffold for constrained drafting."""
    facts = facts or facts_from_asm(asm)
    insns = [_insn(line) for line in asm]
    branches = [line for line in insns if re.match(r"j(?:mp|[a-z]+)\b", line)]
    ret = (facts.get("returns") or ["ret"])[-1]
    stack = re.search(r"ret\s+(\d+)", ret)
    args = int(stack.group(1)) // 4 if stack else 0
    signature = "member thiscall" if any("[ecx" in line for line in insns) else "free cdecl"
    if stack:
        signature += ", callee pops %d stack arg(s)" % args
    blocks = 1 + sum(1 for line in insns if re.match(r"(?:j(?:mp|[a-z]+)|ret)\b", line))
    flow = "; ".join(branches[:8]) or "straight-line"
    return "signature: %s\nbasic blocks: about %d\nbranches: %s\nCFG: %s\nreturn: %s\ntype evidence: %s" % (
        signature, blocks, flow, cfg_outline(asm), ret, type_constraints(asm, facts))


def structure_ir(asm, facts=None):
    """Bounded, evidence-only IR for structured prompts and offline validation."""
    facts = facts or facts_from_asm(asm)
    insns = [_insn(line) for line in asm]
    branches, calls, stack, constants = [], [], set(), set()
    for line in insns:
        bits = line.split(None, 1)
        op = bits[0] if bits else ""
        if op.startswith("j"):
            branches.append({"op": op, "target": (bits[1] if len(bits) > 1 else "?")[:40],
                             "signed": op.startswith(("jl", "jg", "js")),
                             "unsigned": op.startswith(("jb", "ja"))})
        if op == "call":
            calls.append((bits[1] if len(bits) > 1 else "?")[:56])
        stack.update(re.findall(r"\[(?:esp|ebp)(?:\s*[+-]\s*(?:0x[0-9a-fA-F]+|\d+))?\]", line))
        constants.update(re.findall(r"\b(?:0x[0-9a-fA-F]+|\d+)\b", line))
    ret = (facts.get("returns") or [""])[-1]
    return {"cfg": cfg_outline(asm, 12), "signature": {
            "calling_convention": facts.get("calling_convention", "unknown"),
            "receiver": bool(facts.get("this_reads") or facts.get("this_offsets") or
                              any("[ecx" in line for line in insns)),
            "stack_args": list(facts.get("stack_args") or ())[:12],
            "return_instruction": ret,
            "return_register_evidence": sorted({reg for reg in ("eax", "edx")
                                                  if any(re.search(r"\bmov\s+%s\b|\b%s\s*=" % (reg, reg), line)
                                                         for line in insns)})},
            "branches": branches[:12], "calls": calls[:12],
            "stack_slots": sorted(stack)[:12], "receiver_offsets": list((facts.get("this_reads") or
            facts.get("this_offsets") or ()))[:12], "returns": list(facts.get("returns") or ())[-2:],
            "constants": sorted(constants, key=lambda v: (len(v), v))[:16],
            "type_evidence": type_constraints(asm, facts),
            "calling_convention": facts.get("calling_convention", "unknown")}


def type_constraints(asm, facts=None):
    """Reliable ABI/data-layout facts, deliberately not recovered C++ types."""
    facts = facts or facts_from_asm(asm)
    out = []
    this_offsets = facts.get("this_reads", ()) or facts.get("this_offsets", ())
    if this_offsets:
        out.append("ECX receiver dereferenced at " + ", ".join(map(str, this_offsets[:8])))
    if facts.get("this_writes"):
        out.append("receiver writes at " + ", ".join(map(str, facts["this_writes"][:8])))
    if facts.get("stack_args"):
        out.append("stack memory accessed at " + ", ".join(map(str, facts["stack_args"][:8])))
    ret = (facts.get("returns") or [""])[-1]
    if re.search(r"ret\s+\d+", ret):
        out.append("callee stack cleanup")
    if facts.get("virtual_slots"):
        out.append("virtual slots " + ", ".join(map(str, facts["virtual_slots"][:8])))
    insns = [_insn(line) for line in asm]
    signed = sorted({line.split()[0] for line in insns if line.startswith(("jl", "jg", "js"))})
    unsigned = sorted({line.split()[0] for line in insns if line.startswith(("jb", "ja"))})
    if signed:
        out.append("signed branch evidence " + ", ".join(signed))
    if unsigned:
        out.append("unsigned branch evidence " + ", ".join(unsigned))
    return "; ".join(out) or "no safe source-level type claim"


def classify_target(asm, facts=None):
    """Cheap deterministic stage selector before drafting/repair."""
    text = " ; ".join(_insn(line).lower() for line in asm)
    facts = facts or {}
    if not text or text in ("ret", "ret "):
        return "empty"
    if "call" not in text and ("[ecx" in text or "mov eax, ecx" in text):
        if "imul" in text or "add eax" in text or "sub eax" in text or "neg eax" in text:
            return "math/getter"
        if "mov dword ptr [ecx" in text:
            return "setter/constructor"
        return "leaf/getter"
    if text.startswith("jmp") or ("call" in text and len(asm) <= 5):
        return "wrapper/thunk"
    if facts.get("calls", text.count("call")) == 0:
        return "leaf"
    return "unknown"


def target_data_facts(client, code, relocs):
    """Read only relocated, printable data referenced by target code."""
    try:
        from roc import match
        base, image = match._image(client)
    except (OSError, ValueError, SystemExit):
        return {}
    strings, refs = [], []
    for off in relocs:
        if off + 4 > len(code):
            continue
        va = int.from_bytes(code[off:off + 4], "little")
        pos = va - base
        if not 0 <= pos < len(image):
            continue
        refs.append("%08x" % va)
        raw = bytes(image[pos:pos + 160]).split(b"\0", 1)[0]
        if 4 <= len(raw) <= 159 and all(32 <= b < 127 for b in raw):
            strings.append(raw.decode("ascii", "replace"))
    return {"global_refs": sorted(set(refs))[:16], "strings": sorted(set(strings))[:8]}


RULES = """Rules:
- 32-bit x86, Microsoft Visual C++ ({compiler}), flags: {flags}.
- Write C++ that compiles to EXACTLY the target machine code. Inline asm is forbidden.
- Reconstruct behavior as ordinary C++ statements; never translate or copy assembly syntax.
- The answer must contain no instruction mnemonic dump, `__asm`, `_emit`, or assembly comments.
- VS2005/VS2008 only: no `nullptr` (use 0), no `auto`, no `static_assert`.
- No `#include` at all: no `<windows.h>` (not installed), no `<memory>`/STL C++11
  (`unique_ptr`, `make_unique` do not exist). Declare DWORD/HDC/etc. yourself or avoid them.
- Never emit `// roc-lib:` or `// roc-archive:` lines.
- If ecx is used before being set, it is `this`: write a member function of a struct.
- Declare every member inside the struct before defining it outside
  (`struct S {{ int f(); }}; int S::f() {{ ... }}`).
- Never write `struct Namespace::Type {{...}}`: that is invalid C++. Either use
  a local `struct S`, or declare it inside `namespace Namespace {{ struct Type {{...}}; }}`.
- Later-source class/namespace names are hints only. Prefer a minimal local declaration
  over copying an undeclared `RBX::...`/STL type.
- Never use `this` as a variable or parameter name.
- Define the function OUTSIDE the struct (`int S::f() {{ ... }}`). A body written inside
  the struct is inline and never gets compiled, which scores 0.
- `ret N` means the callee pops N bytes of arguments (thiscall/stdcall).
- Do not invent APIs, import names, member fields, or function declarations.
  For a known imported call, a plain `extern "C" RETURN __stdcall name(ARGS);`
  declaration is enough to compile; put declarations at global scope before the
  function, never inside a function; never use `__declspec(dllimport)`.
- Never call a numeric address directly (`0x401000(...)` is invalid C++); assign a valid
  symbolic declaration with the observed calling convention first. Addresses are masked,
  so any valid name works. Declare everything you use;
  there are no headers. Keep only the one function plus declarations.
- Reply with ONE ```cpp code block and nothing else."""


def _trim_hint_facts(hint_facts, terms, max_methods=16):
    """Trim hint metadata without losing the names likely to matter.

    Method lists (up to 48 alphabetical entries) dominate hint bytes. Keep
    the ones overlapping observed target terms or the unit name first, then
    fill alphabetically. Classes/inherits stay whole: small and structural.
    """
    out = dict(hint_facts or {})
    methods = list(out.get("methods", []))
    if len(methods) > max_methods:
        lowered = [t.lower() for t in terms if t]
        def rank(name):
            text = str(name).lower()
            return (-sum(1 for t in lowered if t in text), str(name))
        methods = sorted(methods, key=rank)[:max_methods]
        out["methods"] = methods
    for key, cap in (("literals", 12), ("includes", 12)):
        values = list(out.get(key, []))
        if len(values) > cap:
            out[key] = values[:cap]
    return out


def _clip_example(text, limit=1500):
    """Bound example bytes: matched sources run to 90k chars.

    Two whole examples can dwarf the target assembly, blowing cloud budgets
    and the local context window. The head carries the format lesson (fence,
    struct declarations, signature); the marker keeps a hard cut from
    looking like a complete, copyable answer.
    """
    text = (text or "").strip()
    if len(text) <= limit:
        return text
    return text[:limit].rstrip() + "\n// (example trimmed: full source matched, shown for shape only)"


def prompt_for(client, addr, row, asm, hint, attempt, flags=None, examples=(), source_hints=(), facts=None,
               strategy="direct"):
    entry = match.clients.load()[client]
    p = ["You are doing matching decompilation of a function from an old Roblox client.",
         RULES.format(compiler=entry["compiler"], flags=flags or entry.get("flags") or match.DEFAULT_FLAGS)]
    for ex in examples[:2 if strategy == "direct" else 1]:
        p += ["", "Example of an already matched function from this client:", "```cpp", _clip_example(ex), "```"]
    p += ["", "Stage: %s. Function %s, %d bytes, class (from RTTI, may be a guess): %s" %
          (classify_target(asm, facts), addr, row["size"], row["unit"]),
          "Target assembly (read-only evidence; do not copy it into the answer):", "\n".join(asm)]
    if strategy == "structured":
        p += ["", "STRUCTURED MODE: write the C++ from this control-flow IR first. "
              "Use assembly only to verify operators, calls, and ABI. Never emit assembly or instruction comments. "
              "Ground truth is assembly; do not invent facts:",
              json.dumps(structure_ir(asm, facts), separators=(",", ":")),
              "Readable summary:", reconstruction_outline(asm, facts)]
    if facts:
        p += ["", "Extracted binary facts (use as clues, verify against assembly):",
              json.dumps(facts, separators=(",", ":"))]
    if hint:
        p += ["", "Rev.ng decompiler output (generic types, hint only):", hint]
    from roc import refsource
    terms = list(refsource._target_terms(facts)) + re.findall(r"[A-Za-z_]\w{2,}", row.get("unit", ""))
    ref = refsource.hint(row["unit"]) if strategy != "reference" else None
    if ref:
        p += ["", "The same class in Roblox's 2016 source (real names; layout may have changed since):",
              "```cpp", ref, "```"]
    for source in source_hints[:1 if strategy == "reference" else 3]:
        if strategy == "reference":
            # Later-version source is evidence, not a template. A short method window
            # avoids teaching the model to paste an incompatible whole class.
            clue = (source.get("method") or source["text"])[:900]
            p += ["", "Related-source evidence only (may differ; do not copy it): %s" % source["path"],
                  "```cpp", clue, "```"]
            if source.get("facts"):
                p += ["Source metadata:", json.dumps({k: _trim_hint_facts(source["facts"], terms).get(k, [])
                                                         for k in ("classes", "methods", "inherits", "literals")
                                                         if source["facts"].get(k)}, separators=(",", ":"))]
            if source.get("age_delta") is not None:
                p += ["Age: source is %d years newer; names/layout are weak evidence only." % source["age_delta"]]
            continue
        p += ["", "Related 2016 source clue (not guaranteed same version): %s" % source["path"],
              "```cpp", source["text"], "```"]
        if source.get("method") and source["method"] != source["text"]:
            p += ["Relevant source method body:", "```cpp", source["method"], "```"]
        if source.get("facts"):
            p += ["Source metadata:", json.dumps({k: _trim_hint_facts(source["facts"], terms).get(k, [])
                                                    for k in ("classes", "methods", "includes", "inherits", "literals")
                                                    if source["facts"].get(k)}, separators=(",", ":"))]
    if attempt:
        src, score, feedback = attempt
        phase = "compile repair" if score == 0 else "assembly-diff repair"
        p += ["", "Your previous attempt scored %d%%:" % score, "```cpp", src.strip(), "```",
              "Problem (assembly diff '-' target '+' yours, or compiler error):", feedback,
              "Perform %s. Preserve correct bytes; change only what fixes the problem." % phase]
    try:
        from roc import metrics
        rules = json.loads(metrics.TEMPLATES.read_text())
        if rules:
            p += ["", "Recurring failure rules (apply only when relevant):",
                  json.dumps({k: v.get("prompt") for k, v in list(rules.items())[:4]}, separators=(",", ":"))]
    except (OSError, ValueError, TypeError):
        pass
    return "\n".join(p)


def _norm_src(src):
    return re.sub(r"\s+", " ", (src or "").strip())


def select_topk(scored, k=3):
    """Best-k diverse (score, source) pairs: score desc, text-deduplicated."""
    seen, out = set(), []
    for score, src in sorted(scored, key=lambda t: -t[0]):
        key = _norm_src(src)
        if not key or key in seen:
            continue
        seen.add(key)
        out.append((score, src))
        if len(out) >= max(1, k):
            break
    return out


def _diagnose_note(client, addr, src, flags, limit=400):
    """One-line instruction-level mismatch note for the next repair prompt.

    Compiles are served from match.compile_text's cache, so this costs no
    extra compiler run after check_text. Empty on any failure.
    """
    try:
        target_code, target_relocs, _ = match.target(client, addr)
        obj = match.compile_text(client, src, flags)
        funcs = match.coff_functions(obj)
        if not funcs:
            return ""
        best = max(funcs, key=lambda f: match.score(target_code, target_relocs, f[1], f[2]))
        diag = match.diagnose(target_code, target_relocs, best[1], best[2])
        bits = []
        if diag["opcode_delta"]:
            bits.append("opcode %s" % ", ".join(
                "%s%+d" % item for item in sorted(diag["opcode_delta"].items())[:6]))
        if diag["register_delta"]:
            bits.append("regs %s" % ", ".join(
                "%s%+d" % item for item in sorted(diag["register_delta"].items())[:6]))
        tb, cb = diag["branches"]["target_jcc"], diag["branches"]["cand_jcc"]
        if tb != cb:
            bits.append("branches target=%d yours=%d" % (tb, cb))
        ts, cs = diag["stack_refs"]["target"], diag["stack_refs"]["cand"]
        if ts != cs:
            bits.append("stack refs target=%d yours=%d" % (ts, cs))
        if not bits:
            return ""
        return ("\n[Mismatch: %s. Fix structure first; same ops with different "
                "registers need no change.]" % "; ".join(bits))[:limit]
    except (ValueError, KeyError, match.CompileError):
        return ""


def llm_rounds_k(client, addr, model, rounds=4, hint=None, start=None, log=print, flags=None,
                 examples=(), source_hints=(), facts=None, stats=None, keep=3, strategy="direct",
                 provider_options=None):
    """Ask/compile/diff loop. Returns (best score, best source, top-k list)."""
    from roc import repair as _repair
    from roc import mutate as _mutate
    code, _, row = match.target(client, addr)
    asm = match.disasm(code, int(addr, 16))
    best = (start[1], start[0]) if start and start[0] else (0, None)
    scored = [(best[0], best[1])] if best[1] else []
    seen = {}
    if best[1]:
        seen[_norm_src(best[1])] = best
    compiled_best = None
    if best[1]:
        try:
            attempt = (best[1],) + match.check_text(client, addr, best[1], flags)[0:3:2]
            compiled_best = best
        except match.CompileError as error:
            attempt = (best[1], 0, str(error)[-1500:])
    else:
        attempt = None
    context = None
    # Feedback always comes from the best attempt so far (a worse round never
    # becomes the new baseline); compile errors are fed back until something scores.
    err_codes, compiled_any = [], compiled_best is not None
    requested_diversity = max(1, int((provider_options or {}).get("diverse_candidates", 1) or 1))
    hard_target = (row.get("size", 0) > 96 or (facts or {}).get("calls", 0) or
                   int((facts or {}).get("branch_count", 0) or 0) > 1)
    diverse_rounds = min(rounds, requested_diversity) if hard_target else 1
    no_think = False  # set after a truncation: reasoning likely ate the budget
    asm_strikes = 0  # repeat asm dumps rarely learn: 72% repeat after the first
    for i in range(rounds):
        independent = i < diverse_rounds
        full_prompt = prompt_for(client, addr, row, asm, hint,
                                 None if independent else attempt, flags,
                                 examples, source_hints, facts or facts_from_asm(asm), strategy)
        if independent and i:
            full_prompt += ("\n\nIndependent candidate %d/%d: use different compact C++ control flow. "
                            "Still emit exactly one function." % (i + 1, diverse_rounds))
        # After the first round Ollama already has the target facts and prior
        # answer in its context. Send only the changing repair section.
        prompt = full_prompt
        if not independent and context and "Your previous attempt scored" in full_prompt:
            prompt = full_prompt[full_prompt.index("Your previous attempt scored"):]
        ask_options = dict(provider_options or {})
        ask_options.pop("diverse_candidates", None)
        try:
            from roc import providers as _providers
            cloud = _providers.is_cloud(model)
        except (ValueError, RuntimeError):
            cloud = False
        floor = 1024 if cloud else 0
        ask_options.setdefault("max_tokens", max(output_budget(row.get("size", 0)), floor))
        if no_think:
            ask_options["thinking"] = "disabled"
            ask_options.pop("reasoning_effort", None)
        if strategy == "structured":
            ask_options.setdefault("temperature", 0.05)
        if independent:
            context = None
            ask_options.setdefault("temperature", min(0.8, 0.2 + 0.2 * i))
        try:  # old test/mixed-version monkeypatches still return only a pair
            asked = _ask_context(model, prompt, context, ask_options, details=True)
        except TypeError:
            asked = _ask_context(model, prompt, context)
        reply, context = asked[:2]
        generation = dict(asked[2] if len(asked) > 2 else {})
        generated_tokens = generation.pop("output_tokens", 0)
        src = extract_code(reply)
        if not src:
            finish = generation.get("finish_reason", "")
            if finish == "length":
                log("  round %d: truncated at max_tokens=%s (%d chars); reasoning may be eating the budget" % (
                    i + 1, ask_options.get("max_tokens"), len(reply or "")))
                if cloud and not no_think and (provider_options or {}).get("thinking") != "enabled":
                    no_think = True
                    log("  thinking disabled for remaining rounds")
            else:
                log("  round %d: no code in reply" % (i + 1))
            if stats is not None:
                stats.append({"round": i + 1, "candidate_mode": "independent" if independent else "repair", "score": 0, "output_chars": len(reply),
                              "output_tokens": generated_tokens or max(1, len(reply) // 4),
                              "code": False, **generation})
            continue
        compile_started = time.monotonic()
        if _repair.contains_asm(src):
            error = "Candidate rejected: inline asm is forbidden. Reconstruct compact C++ control flow; do not translate instructions."
            log("  round %d: rejected inline asm" % (i + 1))
            if stats is not None:
                stats.append({"round": i + 1, "strategy": strategy, "score": 0,
                              "output_chars": len(reply), "output_tokens": generated_tokens or max(1, len(reply) // 4),
                              "code": True, "source": src, "compile_seconds": 0,
                              "compile_error": error, "rejected_asm": True, **generation})
            # The answer itself is a strong continuation cue. Do not retain an asm
            # dump in Ollama's chat context or paste it back into the next prompt.
            # Start a fresh generation from target facts plus the rejection instead.
            context = None
            attempt = ("// Previous output rejected: it used inline asm.", 0, error)
            err_codes.append("inline-asm")
            asm_strikes += 1
            if asm_strikes >= 2:
                log("  stopping early: inline asm twice in a row, model is not learning")
                if stats is not None:
                    stats.append({"round": "early-stop",
                                  "reason": "inline asm x2", "code": "inline-asm"})
                break
            continue
        if invalid_qualified_definition(src):
            error = ("Candidate rejected: qualified struct/class definitions are invalid C++. "
                     "Declare the type inside namespace or use a local unqualified struct.")
            log("  round %d: rejected qualified type definition" % (i + 1))
            if stats is not None:
                stats.append({"round": i + 1, "strategy": strategy, "score": 0,
                              "output_chars": len(reply), "output_tokens": generated_tokens or max(1, len(reply) // 4),
                              "code": True, "source": src, "compile_seconds": 0,
                              "compile_error": error, "rejected_qualified_type": True, **generation})
            context = None
            attempt = ("// Previous output rejected: qualified type definition.", 0, error)
            err_codes.append("qualified-type")
            continue
        contract_error = source_contract_error(src)
        if contract_error:
            error = "Candidate rejected: %s. Emit one complete C++ function definition." % contract_error
            log("  round %d: rejected %s" % (i + 1, contract_error))
            if stats is not None:
                stats.append({"round": i + 1, "strategy": strategy, "score": 0,
                              "output_chars": len(reply), "output_tokens": generated_tokens or max(1, len(reply) // 4),
                              "code": True, "source": src, "compile_seconds": 0,
                              "compile_error": error, "rejected_contract": True, **generation})
            context = None
            attempt = ("// Previous output rejected: %s." % contract_error, 0, error)
            err_codes.append("source-contract")
            continue
        asm_strikes = 0  # reached real compile: any later asm dump is a new streak
        compile_error = None
        repaired, duplicate = [], False
        reply_src = src  # unmodified LLM output, kept for comparison
        san, dropped = _repair.sanitize(src)
        if dropped:
            src = san
            repaired.append("sanitize-directives")
        key = _norm_src(src)
        if key in seen:
            score, src = seen[key][:2]
            duplicate = True
            this = (src, score, "duplicate candidate; previous result reused")
            compile_error = None if score else "duplicate of failed candidate"
        else:
            try:
                score, _, d, _ = match.check_text(client, addr, src, flags)
                this = (src, score, d)
                if 0 < score < 100:
                    note = _diagnose_note(client, addr, src, flags)
                    if note:
                        this = (src, score, d + note)
            except match.CompileError as error:
                raw = str(error)
                rscore, rsrc, _, rdiff, _, applied, rerr = _repair.repair_loop(
                    client, addr, src, flags, check=match.check_text)
                if applied:
                    repaired.extend(applied)
                if rerr is None:
                    score, src = rscore, rsrc
                    this = (src, score, rdiff)
                    if 0 < score < 100:
                        note = _diagnose_note(client, addr, src, flags)
                        if note:
                            this = (src, score, rdiff + note)
                else:
                    compile_error = rerr[-500:]
                    failure_class = compile_failure_class(compile_error)
                    if failure_class:
                        compile_error = "[%s] %s" % (failure_class, compile_error)
                    score, this = 0, (src, 0, compile_error)
            seen[key] = (score, src)
            if key != _norm_src(this[0]):
                seen[_norm_src(this[0])] = (this[1], this[0])
        log("  round %d: %d%%" % (i + 1, score))
        if stats is not None:
            entry = {"round": i + 1, "strategy": strategy, "candidate_mode": "independent" if independent else "repair", "score": score, "output_chars": len(reply),
                     "output_tokens": generated_tokens or max(1, len(reply) // 4), "code": True,
                     "source": src,
                     "compile_seconds": round(time.monotonic() - compile_started, 3),
                     "compile_error": compile_error, "repaired": repaired,
                     "duplicate": duplicate, **generation}
            if repaired:
                entry["pre_repair_source"] = reply_src
            stats.append(entry)
        if compile_error is None and not duplicate:
            compiled_any = True
            if compiled_best is None or score > compiled_best[0]:
                compiled_best = (score, src)
        elif compile_error:
            err_codes.append((_repair.parse_error_codes(compile_error) or ["?"])[0])
        if attempt is None or score > attempt[1] or (score == 0 and attempt[1] == 0):
            attempt = this
        if score > best[0] or best[1] is None:
            best = (score, src)
        scored.append((score, src))
        if score == 100:
            break
        if (not compiled_any and len(err_codes) >= 3
                and err_codes[-1] != "?" and err_codes[-3:] == [err_codes[-1]] * 3):
            log("  stopping early: 3 straight %s compile failures, nothing compiled yet"
                % err_codes[-1])
            if stats is not None:
                stats.append({"round": "early-stop",
                              "reason": "same compile error x3", "code": err_codes[-1]})
            break
    if compiled_best is not None and best[0] < 100:
        result = _mutate.improve(client, addr, compiled_best[1], flags)
        mscore, msrc, tried = result[0], result[1], result[2]
        if stats is not None:
            stats.append({"round": "mutate", "score": mscore, "code": True,
                          "source": msrc, "tried": tried,
                          "speculative": result.speculative})
        if mscore > best[0]:
            best = (mscore, msrc)
        scored.append((mscore, msrc))
    if os.environ.get("ROCONSTRUCT_LIVE_CODE", "1") != "0" and best[1]:
        preview = "\n".join(best[1].splitlines()[:24])
        if len(best[1].splitlines()) > 24:
            preview += "\n..."
        log("  generated source (final %d%%):\n%s" % (best[0], preview))
    topk = select_topk(scored, keep)
    if stats is not None:
        stats.append({"round": "topk", "topk": [{"score": s, "source": s_src} for s, s_src in topk]})
    return best[0], best[1], topk


def llm_rounds(client, addr, model, rounds=4, hint=None, start=None, log=print, flags=None,
               examples=(), source_hints=(), facts=None, stats=None, strategy="direct", provider_options=None):
    """Ask/compile/diff loop. Returns (best score, best source). Keeps top-3 in stats."""
    score, src, _ = llm_rounds_k(client, addr, model, rounds, hint, start, log, flags,
                                 examples, source_hints, facts, stats, strategy=strategy,
                                 provider_options=provider_options)
    return score, src
