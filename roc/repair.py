"""Deterministic compilation repair for AI-generated C++ candidates.

Compile repair (make it build) stays separate from match repair (make the
bytes identical). Every fix here targets provably-broken source: unknown
roc directives, member functions with no declaration, `this` used as an
identifier, and MSVC2005/2008-incompatible constructs with identical
semantics. Code that already compiles is never touched.
"""
import json
import re
from pathlib import Path
from urllib.parse import quote


ERROR_RE = re.compile(r"error C(\d+)")

ASM_RE = re.compile(r"__asm|\b_asm\b|\b_emit\b|#pragma\s+code_seg")

DIRECTIVE_RE = re.compile(r"(?m)^\s*//\s*roc-(lib|archive):\s*(\S+).*$")

DEF_RE = re.compile(r"(?m)^\s*(.*?)\s+([A-Za-z_]\w*(?:::[A-Za-z_]\w*)+)\s*\(([^;{}]*)\)\s*(const)?\s*\{")

CLASS_RE = re.compile(r"(struct|class)\s+([A-Za-z_]\w*)\b")

# Never treat STL/template qualifiers as a misspelled class: renaming
# `vector::` or `RBX::VInstance::` to a local struct would corrupt code.
STL_CLASSES = {"vector", "string", "wstring", "map", "set", "list", "deque",
               "basic_string", "allocator", "iterator", "shared_ptr", "unique_ptr"}

THIS_PARAM_RE = re.compile(r"\(\s*[^;{}()]*\*\s*this\s*[,)]")

FREE_DEF_RE = re.compile(r"(?m)^\s*[\w][\w\s*&<>,:]*\s+(\w+)\s*\([^;{}]*\)\s*(const)?\s*\{")

FIXEDWIDTH = (("uint8_t", "typedef unsigned char uint8_t;"),
              ("int8_t", "typedef signed char int8_t;"),
              ("uint16_t", "typedef unsigned short uint16_t;"),
              ("int16_t", "typedef short int16_t;"),
              ("uint32_t", "typedef unsigned int uint32_t;"),
              ("int32_t", "typedef int int32_t;"),
              ("uint64_t", "typedef unsigned __int64 uint64_t;"),
              ("int64_t", "typedef __int64 int64_t;"),
              ("size_t", "typedef unsigned int size_t;"),
              ("uintptr_t", "typedef unsigned int uintptr_t;"),
              ("intptr_t", "typedef int intptr_t;"))

def parse_error_codes(message):
    """MSVC error codes in order seen, deduplicated: ['2039', '2143']."""
    seen, out = set(), []
    for code in ERROR_RE.findall(message or ""):
        if code not in seen:
            seen.add(code)
            out.append(code)
    return out

def contains_asm(src):
    """Same inline-asm rule as match.reject_asm, without compiling."""
    return bool(ASM_RE.search(src or ""))

def sanitize(src):
    """Drop unknown `roc-lib`/`roc-archive` directives. Returns (src, dropped).

    Known recipes (libs.RECIPES) are kept verbatim. Unknown ones (e.g. a
    hallucinated `seg_00...` unit) can never compile, so removing them only
    helps. All other lines are untouched.
    """
    from roc import libs
    dropped = 0

    def keep(match):
        nonlocal dropped
        if match.group(2) in libs.RECIPES:
            return match.group(0)
        dropped += 1
        return ""
    out = DIRECTIVE_RE.sub(keep, src or "")
    return out, dropped

def _class_spans(src):
    """{name: (body_start, body_end)} for struct/class bodies with braces."""
    spans = {}
    for match in CLASS_RE.finditer(src or ""):
        brace = src.find("{", match.end())
        if brace < 0:
            continue
        depth, i = 0, brace
        while i < len(src):
            if src[i] == "{":
                depth += 1
            elif src[i] == "}":
                depth -= 1
                if depth == 0:
                    spans[match.group(2)] = (brace, i)
                    break
            i += 1
    return spans

def ensure_member_declared(src):
    """Declare out-of-line `Cls::fn` members missing from their class body.

    Also renames the qualifier when it names no defined class and exactly
    one class exists (`int S::f` vs `struct PAV...`): the model's placeholder
    habit, and the top C2039/C2653 source. Ambiguous cases return None.
    """
    text = src or ""
    spans = _class_spans(text)
    if not spans:
        return None
    defs = [(m.group(1).strip(), m.group(2), m.group(3).strip(), (m.group(4) or "").strip())
            for m in DEF_RE.finditer(text)
            if "template" not in m.group(0).split("\n")[0]]
    if not defs:
        return None
    changed = False
    for ret, qualified, params, const in defs:
        parts = qualified.split("::")
        if len(parts) != 2:
            continue  # namespaced/STL qualifier: never guess renames here
        cls, func = parts
        if cls not in spans:
            if len(spans) != 1 or cls in STL_CLASSES:
                continue  # ambiguous: leave for the LLM
            sole = next(iter(spans))
            text = re.sub(r"\b%s::" % re.escape(cls), sole + "::", text)
            spans = _class_spans(text)
            cls = sole
            changed = True
        start, end = spans[cls]
        body = text[start:end]
        if re.search(r"\b%s\s*\(" % re.escape(func), body):
            continue
        decl = "%s(%s)%s;" % (func, params, (" " + const) if const else "")
        # ret is kept whole (e.g. `int __stdcall`) so the declaration matches
        # the definition's calling convention; mismatched conventions are C2511.
        decl = ("%s %s" % (ret, decl)) if ret else decl
        text = text[:end] + "\n    " + decl + "\n" + text[end:]
        spans = _class_spans(text)
        changed = True
    return text if changed else None

def rename_this_identifier(src):
    """Rename param `this` to `this_` in pure free-function candidates.

    `this` is a keyword and can never be an identifier, so any such parameter
    is broken by definition. Skipped when a qualified definition exists, so
    real member functions using `this->` are never touched (`std::` mentions
    in free functions do not block the fix).
    """
    text = src or ""
    if not THIS_PARAM_RE.search(text) or DEF_RE.search(text):
        return None
    fixed = re.sub(r"\bthis\b", "this_", text)
    return fixed if fixed != text else None

def add_fixedwidth_typedefs(src):
    """Prepend missing fixed-width typedefs (VS2005/2008 have no stdint.h)."""
    text = src or ""
    if re.search(r"#include\s*<(stdint|stddef|cstdint|cstddef)\.h>", text):
        return None
    needed = [line for tok, line in FIXEDWIDTH
              if re.search(r"\b%s\b" % tok, text)
              and not re.search(r"typedef\b[^\n]*\b%s\b" % tok, text)]
    if not needed:
        return None
    return "// roc-repair: fixed-width shims for MSVC2005/2008\n" + "\n".join(needed) + "\n" + text

def _opaque(name):
    """Opaque handle exactly as windows.h declares it (pointer-sized, no layout)."""
    return "struct %s__; typedef struct %s__ *%s;" % (name, name, name)

WIN_TYPES = (("DWORD", "typedef unsigned long DWORD;"),
             ("BOOL", "typedef int BOOL;"),
             ("BYTE", "typedef unsigned char BYTE;"),
             ("WORD", "typedef unsigned short WORD;"),
             ("LONG", "typedef long LONG;"),
             ("UINT", "typedef unsigned int UINT;"),
             ("HANDLE", _opaque("HANDLE")),
             ("HWND", _opaque("HWND")),
             ("HDC", _opaque("HDC")),
             ("HBITMAP", _opaque("HBITMAP")),
             ("HGDIOBJ", _opaque("HGDIOBJ")),
             ("HINSTANCE", _opaque("HINSTANCE")),
             ("LPVOID", "typedef void* LPVOID;"),
             ("LPCSTR", "typedef const char* LPCSTR;"),
             ("LRESULT", "typedef long LRESULT;"),
             ("WPARAM", "typedef unsigned int WPARAM;"),
             ("LPARAM", "typedef long LPARAM;"))

def add_win_typedefs(src, error_msg):
    """Prepend true Windows SDK type definitions, only for identifiers the
    compiler itself reported missing (C2065 names them). Opaque handles match
    windows.h (pointer-sized); DWORD/BOOL/etc. match WinNT.h exactly. Anything
    else is left for the LLM — never guessed."""
    text, msg = src or "", error_msg or ""
    if re.search(r"#include\s*<windows\.h>", text):
        return None
    needed = [line for tok, line in WIN_TYPES
              if re.search(r"'%s'" % re.escape(tok), msg)
              and re.search(r"\b%s\b" % tok, text)
              and not re.search(r"typedef\b[^\n]*\b%s\b" % tok, text)]
    if not needed:
        return None
    return "// roc-repair: genuine WinNT.h definitions (no SDK shipped)\n" + "\n".join(needed) + "\n" + text

def nullptr_to_zero(src):
    """`nullptr` does not exist in VS2005/2008; `0` is identical here."""
    fixed = re.sub(r"\bnullptr\b", "0", src or "")
    return fixed if fixed != src else None

def repair_compile(src, error_msg):
    """One deterministic repair pass. Returns (fixed_src, [applied]) or (None, []).

    Only repairs matching the reported error codes run; each transform is
    semantics-preserving or fixes provably-invalid code.
    """
    cur, applied = src or "", []
    san, dropped = sanitize(cur)
    if dropped:
        cur = san
        applied.append("sanitize-directives")
    codes = set(parse_error_codes(error_msg))
    if codes & {"2039", "2653", "2673", "2511", "2512", "2504", "2352"} or \
            ("not a member" in (error_msg or "") and "::" in cur):
        fixed = ensure_member_declared(cur)
        if fixed:
            cur = fixed
            applied.append("member-decl")
    if "this" in (error_msg or "") and re.search(r"\bthis\b", cur):
        fixed = rename_this_identifier(cur)
        if fixed:
            cur = fixed
            applied.append("this-param")
    if codes & {"4430", "2146", "2065"}:
        fixed = add_fixedwidth_typedefs(cur)
        if fixed:
            cur = fixed
            applied.append("fixedwidth-typedefs")
        fixed = add_win_typedefs(cur, error_msg)
        if fixed:
            cur = fixed
            applied.append("win-typedefs")
    if re.search(r"\bnullptr\b", cur):
        fixed = nullptr_to_zero(cur)
        if fixed != cur:
            cur = fixed
            applied.append("nullptr-zero")
    if applied and cur != src:
        return cur, applied
    return None, []

def repair_loop(client, addr, src, flags=None, check=None, max_retries=2):
    """Compile-and-test repair. Returns (score, src, sym, diff, spans, applied, error).

    error is None on success. No AI calls; at most 1 + max_retries compiles.
    """
    from roc import match
    check = check or match.check_text
    applied_all, cur, error = [], src, None
    for _ in range(max(0, max_retries) + 1):
        try:
            score, sym, diff, spans = check(client, addr, cur, flags)
            return score, cur, sym, diff, spans, applied_all, None
        except match.CompileError as err:
            error = str(err)
            fixed, applied = repair_compile(cur, error)
            if not fixed:
                return 0, cur, None, error, [], applied_all, error
            cur, applied_all = fixed, applied_all + applied
    try:
        score, sym, diff, spans = check(client, addr, cur, flags)
        return score, cur, sym, diff, spans, applied_all, None
    except match.CompileError as err:
        return 0, cur, None, str(err), [], applied_all, str(err)


# --- repair patterns ---
# Small, measured repair-pattern registry used for deterministic ranking.

ROOT = Path(__file__).resolve().parent.parent


REGISTRY = ROOT / "research" / "repair-patterns.json"


def load():
    try:
        rows = json.loads(REGISTRY.read_text())
    except (OSError, ValueError):
        return []
    return [row for row in rows if isinstance(row, dict) and row.get("name")]


def rank_categories(diagnosis, categories):
    """Return categories in evidence/history order; unknowns keep input order."""
    diagnosis = diagnosis or {}
    labels = set()
    for row in diagnosis.get("classifications", []):
        labels.add(row.get("category"))
    if diagnosis.get("mismatch_class"):
        labels.add(diagnosis["mismatch_class"])
    patterns = load()
    weights = {}
    for row in patterns:
        if labels.intersection(row.get("evidence", [])):
            for category in row.get("categories", []):
                weights[category] = max(weights.get(category, 0),
                                        int(row.get("exact", 0)) * 100 + int(row.get("improved", 0)))
    return sorted(enumerate(categories), key=lambda item: (-weights.get(item[1], 0), item[0]))


# --- abi graph ---
# Small caller/callee ABI evidence graph for compiler-guided repair.

_SIG = re.compile(
    r'(?m)^\s*(?:extern\s+"C"\s+)?(?P<ret>[A-Za-z_][\w:<>*& ]*?)\s+'
    r"(?P<cc>__(?:cdecl|stdcall|thiscall|fastcall)\s+)?"
    r"(?P<name>[A-Za-z_]\w*(?:::\w+)?)\s*\((?P<args>[^;{}]*)\)"
)


def source_signature(source):
    """Extract conservative return/ABI/arity facts; unknown stays unknown."""
    match = _SIG.search(source or "")
    if not match:
        return {}
    args = match.group("args").strip()
    return {
        "return_type": " ".join(match.group("ret").split()),
        "calling_convention": (match.group("cc") or "").strip() or "default",
        "arity": 0 if not args or args == "void" else args.count(",") + 1,
        "name": match.group("name"),
    }


def target_evidence(api, client, row, limit=6):
    """Build bounded exact-callee evidence for one target."""
    edges = []
    for target in (row.get("call_targets") or [])[:limit]:
        target = str(target).lower()
        if not re.fullmatch(r"[0-9a-f]{8}", target):
            continue
        try:
            item = api.call("/v1/source?client=%s&addr=%s" % (quote(client), target))
        except Exception:
            continue
        if int((item or {}).get("score", 0) or 0) != 100:
            continue
        signature = source_signature((item or {}).get("source"))
        if signature:
            edges.append({"addr": target, **signature})
    return {
        "caller_count": len(row.get("callers") or []),
        "callee_count": len(row.get("call_targets") or []),
        "exact_callees": edges,
    }


# --- pressure ---
# Conservative x86-32 live-register pressure estimate for ranking windows.

REGS = {"eax", "ebx", "ecx", "edx", "esi", "edi", "ebp", "esp"}


OP = re.compile(r"^\s*(\w+)\s+([^,]+)(?:,\s*(.*))?$", re.I)


TARGET = re.compile(r"\b(?:0x[0-9a-f]+|\d+)\b", re.I)


def registers(asm):
    return [set(re.findall(r"\b(eax|ebx|ecx|edx|esi|edi|ebp|esp)\b", line.lower()))
            for line in asm.splitlines()]


def estimate(asm):
    """Return max distinct register names in a short window.

    This is a ranking hint, not liveness proof: aliases, memory effects, and
    control flow are intentionally not guessed.
    """
    rows = registers(asm)
    live = set()
    peaks = []
    for used in reversed(rows):
        live |= used
        peaks.append(len(live))
    return {"instructions": len(rows), "max_registers": max((len(x) for x in rows), default=0),
            "max_live_hint": max(peaks, default=0),
            "distinct_registers": sorted(set().union(*rows) if rows else set())}


def estimate_killed(asm):
    """Backward hint that kills simple destination-register definitions."""
    live, peaks = set(), []
    for line in reversed(asm.splitlines()):
        m = OP.match(line)
        if not m:
            continue
        op, dst, src = m.group(1).lower(), m.group(2).lower(), m.group(3) or ""
        used = set(re.findall(r"\b(eax|ebx|ecx|edx|esi|edi|ebp|esp)\b", src))
        killed = {dst} if op in {"mov", "lea", "pop", "xor"} and dst in REGS else set()
        live = (live - killed) | used
        peaks.append(len(live))
    return max(peaks, default=0)


def blocks(asm):
    """Split linear text at simple terminators; labels/targets remain conservative."""
    out, cur = [], []
    for line in asm.splitlines():
        cur.append(line)
        op = (line.strip().split(None, 1) or [""])[0].lower()
        if op == "ret" or op == "jmp" or op.startswith("j"):
            out.append("\n".join(cur))
            cur = []
    if cur:
        out.append("\n".join(cur))
    return out


def branch_targets(asm):
    """Return numeric targets from simple jump lines; symbolic targets stay unknown."""
    out = []
    for line in asm.splitlines():
        parts = line.strip().split(None, 1)
        if parts and parts[0].lower().startswith("j") and len(parts) == 2:
            m = TARGET.search(parts[1])
            if m:
                out.append(int(m.group(0), 0))
    return out


def block_pressure(asm):
    """Per-block conservative pressure records for ranking/reporting."""
    return [{"index": i, "pressure": estimate_killed(block),
             "instructions": len(block.splitlines())}
            for i, block in enumerate(blocks(asm))]
