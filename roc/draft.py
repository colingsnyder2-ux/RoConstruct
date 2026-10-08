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
PREFERRED_MODELS = ["qwen2.5-coder:14b", "qwen2.5-coder:7b", "qwen2.5-coder", "deepseek-coder-v2", "codellama"]
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
    models = ollama_models()
    if wanted == "default":
        wanted = None
    if wanted:
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


def _ask_context(model, prompt, context=None):
    profile = model_profile(model)
    request = {"model": model, "prompt": prompt, "stream": True,
                          "keep_alive": "10m",
                          "options": {"temperature": 0.2, **profile}}
    if context:
        request["context"] = context
    payload = json.dumps(request).encode()
    req = urllib.request.Request(OLLAMA + "/api/generate", data=payload,
                                 headers={"Content-Type": "application/json"})
    pieces, fences, returned_context = [], 0, None
    try:
        with urllib.request.urlopen(req, timeout=180) as response:
            for raw in response:
                try:
                    item = json.loads(raw)
                except ValueError:
                    continue
                piece = item.get("response", "")
                pieces.append(piece)
                fences += piece.count("```")
                if item.get("context"):
                    returned_context = item["context"]
                # Keep reading to the final stream record so Ollama returns its
                # reusable context; generated text is still capped at the fence.
                if fences >= 2:
                    pieces = ["".join(pieces)]
                    for tail in response:
                        try:
                            final = json.loads(tail)
                        except ValueError:
                            continue
                        if final.get("context"):
                            returned_context = final["context"]
                    break
    except urllib.error.HTTPError:
        raise
    return "".join(pieces), returned_context


def ask(model, prompt):
    """Generate one bounded reply; compatibility wrapper for callers/tests."""
    return _ask_context(model, prompt)[0]


def extract_code(reply):
    blocks = re.findall(r"```(?:cpp|c\+\+|c)?\s*\n(.*?)```", reply, re.S)
    return max(blocks, key=len).strip() + "\n" if blocks else None


def facts_from_asm(asm):
    """Cheap, stable facts useful to source retrieval and prompt grounding."""
    calls = [line for line in asm if re.search(r"\bcall\b", line)]
    offsets = sorted(set(re.findall(r"\[ecx \+ (0x[0-9a-f]+)]", "\n".join(asm))))
    returns = [line.strip() for line in asm if re.search(r"\bret(?:\s|$)", line)]
    imports = [line.strip() for line in calls if "dword ptr" in line]
    return {"calls": len(calls), "imports": imports[:8], "this_offsets": offsets[:16],
            "returns": returns[-1:]}


def classify_target(asm, facts=None):
    """Cheap deterministic stage selector before drafting/repair."""
    text = " ; ".join(line.lower().strip() for line in asm)
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
- VS2005/VS2008 only: no `nullptr` (use 0), no `auto`, no `static_assert`.
- No `#include`, no `uint8_t`/`size_t` unless you declare them yourself.
- Never emit `// roc-lib:` or `// roc-archive:` lines.
- If ecx is used before being set, it is `this`: write a member function of a struct.
- Declare every member inside the struct before defining it outside
  (`struct S {{ int f(); }}; int S::f() {{ ... }}`).
- Never use `this` as a variable or parameter name.
- Define the function OUTSIDE the struct (`int S::f() {{ ... }}`). A body written inside
  the struct is inline and never gets compiled, which scores 0.
- `ret N` means the callee pops N bytes of arguments (thiscall/stdcall).
- `call dword ptr [addr]` is a call to an imported function: declare it
  extern "C" __declspec(dllimport) with the right calling convention.
- Addresses of globals/functions are masked, any name works. Declare everything you use;
  there are no headers. Keep only the one function plus declarations.
- Reply with ONE ```cpp code block and nothing else."""


def prompt_for(client, addr, row, asm, hint, attempt, flags=None, examples=(), source_hints=(), facts=None):
    entry = match.clients.load()[client]
    p = ["You are doing matching decompilation of a function from an old Roblox client.",
         RULES.format(compiler=entry["compiler"], flags=flags or entry.get("flags") or match.DEFAULT_FLAGS)]
    for ex in examples[:2]:
        p += ["", "Example of an already matched function from this client:", "```cpp", ex.strip(), "```"]
    p += ["", "Stage: %s. Function %s, %d bytes, class (from RTTI, may be a guess): %s" %
          (classify_target(asm, facts), addr, row["size"], row["unit"]),
          "Target assembly:", "\n".join(asm)]
    if facts:
        p += ["", "Extracted binary facts (use as clues, verify against assembly):",
              json.dumps(facts, separators=(",", ":"))]
    if hint:
        p += ["", "Rev.ng decompiler output (generic types, hint only):", hint]
    from roc import refsource
    ref = refsource.hint(row["unit"])
    if ref:
        p += ["", "The same class in Roblox's 2016 source (real names; layout may have changed since):",
              "```cpp", ref, "```"]
    for source in source_hints[:3]:
        p += ["", "Related 2016 source clue (not guaranteed same version): %s" % source["path"],
              "```cpp", source["text"], "```"]
        if source.get("method") and source["method"] != source["text"]:
            p += ["Relevant source method body:", "```cpp", source["method"], "```"]
        if source.get("facts"):
            p += ["Source metadata:", json.dumps({k: source["facts"].get(k, [])
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
                 examples=(), source_hints=(), facts=None, stats=None, keep=3):
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
    for i in range(rounds):
        full_prompt = prompt_for(client, addr, row, asm, hint, attempt, flags,
                                 examples, source_hints, facts or facts_from_asm(asm))
        # After the first round Ollama already has the target facts and prior
        # answer in its context. Send only the changing repair section.
        prompt = full_prompt
        if context and "Your previous attempt scored" in full_prompt:
            prompt = full_prompt[full_prompt.index("Your previous attempt scored"):]
        reply, context = _ask_context(model, prompt, context)
        src = extract_code(reply)
        if not src:
            log("  round %d: no code in reply" % (i + 1))
            if stats is not None:
                stats.append({"round": i + 1, "score": 0, "output_chars": len(reply),
                              "output_tokens": max(1, len(reply) // 4), "code": False})
            continue
        compile_started = time.monotonic()
        compile_error = None
        repaired, duplicate = [], False
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
                    score, this = 0, (src, 0, rerr[-1500:])
            seen[key] = (score, src)
            if key != _norm_src(this[0]):
                seen[_norm_src(this[0])] = (this[1], this[0])
        log("  round %d: %d%%" % (i + 1, score))
        if stats is not None:
            stats.append({"round": i + 1, "score": score, "output_chars": len(reply),
                          "output_tokens": max(1, len(reply) // 4), "code": True,
                          "source": src,
                          "compile_seconds": round(time.monotonic() - compile_started, 3),
                          "compile_error": compile_error, "repaired": repaired,
                          "duplicate": duplicate})
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
        mscore, msrc, tried = _mutate.improve(client, addr, compiled_best[1], flags)
        if stats is not None:
            stats.append({"round": "mutate", "score": mscore, "code": True,
                          "source": msrc, "tried": tried})
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
               examples=(), source_hints=(), facts=None, stats=None):
    """Ask/compile/diff loop. Returns (best score, best source). Keeps top-3 in stats."""
    score, src, _ = llm_rounds_k(client, addr, model, rounds, hint, start, log, flags,
                                 examples, source_hints, facts, stats)
    return score, src
