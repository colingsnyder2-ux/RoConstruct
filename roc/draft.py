"""Draft sources for the worker: Rev.ng (hint C) and Ollama (writes C++).

The LLM gets the target asm, the Rev.ng hint, and after each try the asm diff
or compile error of its last attempt, so it can converge on a byte match.
"""
import html
import json
import re
import shutil
import struct
import subprocess
import tempfile
import urllib.request
from pathlib import Path

from roc import match

OLLAMA = "http://127.0.0.1:11434"
PREFERRED_MODELS = ["qwen2.5-coder:14b", "qwen2.5-coder:7b", "qwen2.5-coder", "deepseek-coder-v2", "codellama"]
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


def revng_available():
    if not shutil.which("docker"):
        return False
    run = subprocess.run(["docker", "image", "inspect", REVNG_IMAGE], capture_output=True)
    return run.returncode == 0


def revng_c(code, va, timeout=300):
    """Rev.ng's C for one function, or None. Types are generic; it is a hint."""
    with tempfile.TemporaryDirectory() as tmp:
        Path(tmp, "f.elf").write_bytes(mini_elf(code, va))
        try:
            run = subprocess.run(
                ["docker", "run", "--rm", "-v", "%s:/w" % tmp, REVNG_IMAGE, "bash", "-lc",
                 "cd /w && revng quick artifact emit-c-as-single-file f.elf"],
                capture_output=True, text=True, timeout=timeout)
        except subprocess.TimeoutExpired:
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
        return [m["name"] for m in _get("/api/tags", timeout=5)["models"]]
    except OSError:
        return []


def pick_model(wanted=None):
    models = ollama_models()
    if wanted:
        return wanted if wanted in models else None
    for want in PREFERRED_MODELS:
        for m in models:
            if m == want or m.startswith(want + ":"):
                return m
    return None


def ask(model, prompt):
    out = _get("/api/generate", {"model": model, "prompt": prompt, "stream": False,
                                 "options": {"temperature": 0.2, "num_ctx": 8192}})
    return out.get("response", "")


def extract_code(reply):
    blocks = re.findall(r"```(?:cpp|c\+\+|c)?\s*\n(.*?)```", reply, re.S)
    return max(blocks, key=len).strip() + "\n" if blocks else None


RULES = """Rules:
- 32-bit x86, Microsoft Visual C++ ({compiler}), flags: {flags}.
- Write C++ that compiles to EXACTLY the target machine code. Inline asm is forbidden.
- If ecx is used before being set, it is `this`: write a member function of a struct.
- Define the function OUTSIDE the struct (`int S::f() {{ ... }}`). A body written inside
  the struct is inline and never gets compiled, which scores 0.
- `ret N` means the callee pops N bytes of arguments (thiscall/stdcall).
- `call dword ptr [addr]` is a call to an imported function: declare it
  extern "C" __declspec(dllimport) with the right calling convention.
- Addresses of globals/functions are masked, any name works. Declare everything you use;
  there are no headers. Keep only the one function plus declarations.
- Reply with ONE ```cpp code block and nothing else."""


def prompt_for(client, addr, row, asm, hint, attempt, flags=None, examples=()):
    entry = match.clients.load()[client]
    p = ["You are doing matching decompilation of a function from an old Roblox client.",
         RULES.format(compiler=entry["compiler"], flags=flags or entry.get("flags") or match.DEFAULT_FLAGS)]
    for ex in examples:
        p += ["", "Example of an already matched function from this client:", "```cpp", ex.strip(), "```"]
    p += ["", "Function %s, %d bytes, class (from RTTI, may be a guess): %s" % (addr, row["size"], row["unit"]),
          "Target assembly:", "\n".join(asm)]
    if hint:
        p += ["", "Rev.ng decompiler output (generic types, hint only):", hint]
    if attempt:
        src, score, feedback = attempt
        p += ["", "Your previous attempt scored %d%%:" % score, "```cpp", src.strip(), "```",
              "Problem (assembly diff '-' target '+' yours, or compiler error):", feedback,
              "Fix it so the assembly is identical."]
    return "\n".join(p)


def llm_rounds(client, addr, model, rounds=4, hint=None, start=None, log=print, flags=None, examples=()):
    """Ask/compile/diff loop. Returns (best score, best source)."""
    code, _, row = match.target(client, addr)
    asm = match.disasm(code, int(addr, 16))
    best = (start[1], start[0]) if start and start[0] else (0, None)
    # Feedback always comes from the best attempt so far (a worse round never
    # becomes the new baseline); compile errors are fed back until something scores.
    attempt = None
    if best[1]:
        try:
            attempt = (best[1],) + match.check_text(client, addr, best[1], flags)[::2]
        except match.CompileError as error:
            attempt = (best[1], 0, str(error)[-1500:])
    for i in range(rounds):
        src = extract_code(ask(model, prompt_for(client, addr, row, asm, hint, attempt, flags, examples)))
        if not src:
            log("  round %d: no code in reply" % (i + 1))
            continue
        try:
            score, _, d = match.check_text(client, addr, src, flags)
            this = (src, score, d)
        except match.CompileError as error:
            score, this = 0, (src, 0, str(error)[-1500:])
        log("  round %d: %d%%" % (i + 1, score))
        if attempt is None or score > attempt[1] or (score == 0 and attempt[1] == 0):
            attempt = this
        if score > best[0] or best[1] is None:
            best = (score, src)
        if score == 100:
            break
    return best
