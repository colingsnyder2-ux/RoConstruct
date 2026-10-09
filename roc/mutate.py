"""Small validated C++ source mutations with compile-and-test feedback.

Each mutator is a pure text transform returning a variant or None. `improve`
compiles every variant with the client's real compiler via an injectable
check function and keeps the best score, so a bad guess costs compile time
and nothing else. No LLM, no new models.
"""
import re
import time

CMP_FLIP = {"==": "!=", "!=": "==", "<": ">=", ">=": "<", ">": "<=", "<=": ">",
            "&&": "||", "||": "&&"}


def toggle_char_signedness(src):
    """char <-> unsigned char on member/decl types (movsx vs movzx codegen)."""
    if "unsigned char" in src:
        out = src.replace("unsigned char", "char")
    elif re.search(r"\bchar\b", src):
        out = re.sub(r"\bchar\b", "unsigned char", src, count=1)
    else:
        return None
    return out if out != src else None


def toggle_int_signedness(src):
    """int <-> unsigned int, first occurrence only (keeps variants small)."""
    if "unsigned int" in src:
        out = src.replace("unsigned int", "int", 1)
    elif re.search(r"\bint\b", src):
        out = re.sub(r"\bint\b", "unsigned int", src, count=1)
    else:
        return None
    return out if out != src else None


def negate_comparison(src):
    """Flip the first comparison/logical operator (branch-swap hypothesis)."""
    for op, flipped in CMP_FLIP.items():
        if op in src:
            return src.replace(op, flipped, 1)
    return None


def swap_add_operands(src):
    """a + b -> b + a for the first simple addition (operand-order codegen)."""
    m = re.search(r"(\b[A-Za-z_]\w*(?:->\w+|\.\w+|\[\w+\])?)\s*\+\s*(\b[A-Za-z_]\w*(?:->\w+|\.\w+|\[\w+\])?)", src)
    if not m or m.group(1) == m.group(2):
        return None
    return src[:m.start()] + m.group(2) + " + " + m.group(1) + src[m.end():]


MUTATORS = (toggle_char_signedness, toggle_int_signedness,
            negate_comparison, swap_add_operands)
# Mutations that can change program behavior: valid search moves, but a
# higher fuzzy score from one is never evidence of correctness. Only an
# exact compiler-backed match verifies.
SPECULATIVE = {"negate_comparison", "swap_add_operands"}


def swap_call_argument_variants(src):
    """Swap two top-level call args; caller needs byte-level reversal evidence."""
    src = src or ""
    out = []
    for opening, char in enumerate(src):
        if char != "(":
            continue
        name = re.search(r"([A-Za-z_]\w*(?:::[A-Za-z_]\w*)*)\s*$", src[:opening])
        if not name or name.group(1) in {"if", "while", "for", "switch", "catch", "sizeof", "decltype"}:
            continue
        depth, quote, escaped, commas, closing = 1, "", False, [], None
        for i in range(opening + 1, len(src)):
            c = src[i]
            if quote:
                if escaped:
                    escaped = False
                elif c == "\\":
                    escaped = True
                elif c == quote:
                    quote = ""
                continue
            if c in "\"'":
                quote = c
            elif c in "([{":
                depth += 1
            elif c in ")]}" :
                depth -= 1
                if depth == 0:
                    closing = i
                    break
            elif c == "," and depth == 1:
                commas.append(i)
        if closing is None or len(commas) != 1 or re.match(r"\s*(?:const\s*)?\{", src[closing + 1:]):
            continue
        left_start, left_end = opening + 1, commas[0]
        right_start, right_end = commas[0] + 1, closing
        while left_start < left_end and src[left_start].isspace():
            left_start += 1
        while left_end > left_start and src[left_end - 1].isspace():
            left_end -= 1
        while right_start < right_end and src[right_start].isspace():
            right_start += 1
        while right_end > right_start and src[right_end - 1].isspace():
            right_end -= 1
        left, right = src[left_start:left_end], src[right_start:right_end]
        if left and right and left != right:
            out.append(src[:left_start] + right + src[left_end:right_start] + left + src[right_end:])
        if len(out) == 4:
            break
    return out


def _reversed_call_order(diagnosis):
    return any(len(row.get("target", [])) == 2 and len(row.get("candidate", [])) == 2 and
               row["target"] == row["candidate"][::-1]
               for row in (diagnosis or {}).get("call_argument_diffs", []))


def _literal_value(token):
    token = re.sub(r"(?i)(?:ull|llu|ul|lu|u|ll|l)$", "", token)
    return int(token, 16 if token.lower().startswith("0x") else 10)


def immediate_variants(src, diagnosis):
    """Replace one uniquely occurring source literal when disassembly agrees."""
    out = []
    literal = re.compile(r"(?<![\w.])(?:0[xX][0-9a-fA-F]+|\d+)(?:[uUlL]{1,3})?(?![\w.])")
    for diff in (diagnosis or {}).get("immediate_diffs", [])[:4]:
        try:
            old, new = diff["candidate"], diff["target"]
            old_value, new_value = _literal_value(old), _literal_value(new)
        except (KeyError, ValueError):
            continue
        matches = [m for m in literal.finditer(src) if _literal_value(m.group()) == old_value]
        if len(matches) != 1:
            continue
        match = matches[0]
        suffix = re.search(r"[uUlL]+$", match.group())
        replacement = (hex(new_value) if match.group().lower().startswith("0x") else str(new_value))
        if suffix:
            replacement += suffix.group()
        out.append(src[:match.start()] + replacement + src[match.end():])
    return out


def stack_layout_variants(src, diagnosis):
    """Adjust one uniquely matching padding array by decoded stack delta."""
    out = []
    arrays = list(re.finditer(r"\b(?:char|unsigned\s+char)\s+\w*\s*\[\s*(0x[0-9a-f]+|\d+)\s*\]", src, re.I))
    for diff in (diagnosis or {}).get("stack_offset_diffs", [])[:2]:
        try:
            delta = _literal_value(diff["target"]) - _literal_value(diff["candidate"])
        except (KeyError, ValueError):
            continue
        if not delta or len(arrays) != 1:
            continue
        match = arrays[0]
        old = _literal_value(match.group(1))
        new = old + delta
        if new <= 0:
            continue
        text = (hex(new) if match.group(1).lower().startswith("0x") else str(new))
        out.append(src[:match.start(1)] + text + src[match.end(1):])
    return out


def intrinsic_call_variants(src, diagnosis):
    """Switch only known MSVC Interlocked spelling when xadd/call evidence agrees."""
    if (diagnosis or {}).get("mismatch_class") != "intrinsic/call mismatch":
        return []
    if "InterlockedExchangeAdd" not in src:
        return []
    if "_InterlockedExchangeAdd" in src:
        return [src.replace("_InterlockedExchangeAdd", "InterlockedExchangeAdd", 1)]
    return [src.replace("InterlockedExchangeAdd", "_InterlockedExchangeAdd", 1)]


def calling_convention_variants(src, diagnosis):
    """Add/remove explicit MSVC convention only when return cleanup proves it."""
    if (diagnosis or {}).get("mismatch_class") != "calling-convention mismatch":
        return []
    cleanup = diagnosis.get("return_cleanup", {})
    target_cleans, candidate_cleans = bool(cleanup.get("target")), bool(cleanup.get("candidate"))
    if target_cleans == candidate_cleans or "__cdecl" in src or "__stdcall" in src:
        return []
    if not target_cleans:
        return []
    pattern = re.compile(r"\b([A-Za-z_]\w*(?:\s*\*)?)\s+([A-Za-z_]\w*(?:::[A-Za-z_]\w*)?)\s*\(")
    matches = list(pattern.finditer(src))
    if not matches:
        return []
    match = matches[-1]
    return [src[:match.start(1)] + match.group(1) + " __stdcall " +
            match.group(2) + src[match.end(2):]]


def return_value_variants(src, diagnosis):
    """Add `return this` for a decoded missing EAX return immediately before epilogue."""
    info = (diagnosis or {}).get("missing_return_value")
    if (diagnosis or {}).get("mismatch_class") != "missing return value" or not info:
        return []
    if info.get("register") not in {"esi", "edi", "ebx", "ebp", "eax"}:
        return []
    matches = list(re.finditer(r"\bvoid(\s+[A-Za-z_]\w*(?:::[A-Za-z_]\w+)?)\s*\([^)]*\)\s*\{", src))
    if not matches:
        return []
    function = matches[-1]
    opening = src.find("{", function.end() - 1)
    depth, close = 0, None
    for index in range(opening, len(src)):
        if src[index] == "{":
            depth += 1
        elif src[index] == "}":
            depth -= 1
            if depth == 0:
                close = index
                break
    if opening < 0 or close is None:
        return []
    name = function.group(1).strip().split("::")[-1]
    updated = re.sub(r"\bvoid(\s+(?:[A-Za-z_]\w*::)?" + re.escape(name) + r"\s*\()",
                     r"void*\1", src)
    function = list(re.finditer(r"\bvoid\*(\s+[A-Za-z_]\w*(?:::[A-Za-z_]\w+)?)\s*\([^)]*\)\s*\{", updated))[-1]
    opening = updated.find("{", function.end() - 1)
    depth, close = 0, None
    for index in range(opening, len(updated)):
        if updated[index] == "{":
            depth += 1
        elif updated[index] == "}":
            depth -= 1
            if depth == 0:
                close = index
                break
    if close is None:
        return []
    updated = updated[:close] + "\n    return this;\n" + updated[close:]
    return [updated]


def guided_variants(src, diagnosis, categories=None):
    """Only propose bounded source edits supported by decoded mismatch evidence."""
    out, seen = [], {src}
    allowed = None if categories is None else set(categories)

    def add(category, values):
        if allowed is not None and category not in allowed:
            return
        for value in values:
            if value and value not in seen and len(out) < 8:
                seen.add(value)
                out.append((category, value))

    if _reversed_call_order(diagnosis):
        add("argument_order", swap_call_argument_variants(src))
    if (diagnosis or {}).get("immediate_diffs") and not (diagnosis or {}).get("stack_offset_diffs"):
        add("immediate_constant", immediate_variants(src, diagnosis))
    if (diagnosis or {}).get("stack_offset_diffs"):
        add("stack_layout", stack_layout_variants(src, diagnosis))
    if (diagnosis or {}).get("mismatch_class") == "intrinsic/call mismatch":
        add("intrinsic_call", intrinsic_call_variants(src, diagnosis))
    if (diagnosis or {}).get("branch_condition_diff"):
        add("branch_condition", [negate_comparison(src)])
    opcodes = (diagnosis or {}).get("opcode_delta", {})
    if (opcodes.get("sar", 0) < 0 < opcodes.get("shr", 0) and "unsigned int" in src):
        add("signedness", [toggle_int_signedness(src)])
    elif "movsx" in opcodes or "movzx" in opcodes:
        add("signedness", [toggle_char_signedness(src), toggle_int_signedness(src)])
    if (diagnosis or {}).get("mismatch_class") == "calling-convention mismatch":
        add("calling_convention", calling_convention_variants(src, diagnosis))
        cleanup = diagnosis.get("return_cleanup", {})
        target_cleans, candidate_cleans = bool(cleanup.get("target")), bool(cleanup.get("candidate"))
        if "__stdcall" in src and not target_cleans and candidate_cleans:
            add("calling_convention", [src.replace("__stdcall", "__cdecl", 1)])
        elif "__cdecl" in src and target_cleans and not candidate_cleans:
            add("calling_convention", [src.replace("__cdecl", "__stdcall", 1)])
    if (diagnosis or {}).get("mismatch_class") == "missing return value":
        add("return_value", return_value_variants(src, diagnosis))
    return out


class ImproveResult(tuple):
    """(score, src, tried) plus `.speculative`; unpacks like the old 3-tuple."""
    def __new__(cls, score, src, tried, speculative=False, mutations=()):
        self = super().__new__(cls, (score, src, tried))
        self.speculative = speculative
        self.mutations = list(mutations)
        return self


def variants(src):
    """Unique non-trivial variants of src, in mutator order."""
    out, seen = [], {src}
    for fn in MUTATORS:
        try:
            v = fn(src)
        except (ValueError, IndexError):
            continue
        if v and v not in seen:
            seen.add(v)
            out.append(v)
    return out


def improve(client, addr, src, flags=None, check=None, guided=False,
            guided_categories=None, guided_fallback=True):
    """Compile-and-test bounded variants; guided mode requires mismatch evidence.

    ImproveResult is a 3-tuple (score, src, tried) with a `.speculative`
    attribute, True when the winning variant came from a SPECULATIVE
    mutator. The tuple form keeps old 3-unpacking callers working.
    check is injectable as check(client, addr, text, flags) -> (score, ...);
    defaults to match.check_text. Variants raising CompileError are skipped.
    """
    from roc import match
    check = check or match.check_text
    diagnosis = None
    try:
        try:
            measured = check(client, addr, src, flags, include_diagnosis=True)
        except TypeError:
            measured = check(client, addr, src, flags)
        base = measured[0]
        diagnosis = measured[4] if len(measured) > 4 else None
    except match.CompileError:
        base = 0
    best, tried, speculative, mutations = (base, src), 0, False, []
    if base == 100:
        return ImproveResult(base, src, 0, mutations=mutations)
    legacy = []
    for fn in MUTATORS:
        try:
            value = fn(src)
        except (ValueError, IndexError):
            continue
        if value and value != src:
            legacy.append((fn.__name__, value))
    if _reversed_call_order(diagnosis):
        legacy.extend(("argument_order", value) for value in swap_call_argument_variants(src))
    if guided:
        variants_to_try = guided_variants(src, diagnosis, guided_categories)
        known = {value for _, value in variants_to_try}
        if guided_fallback:
            variants_to_try.extend((category, value) for category, value in legacy if value not in known)
        variants_to_try = variants_to_try[:8]
    else:
        variants_to_try = legacy
    for category, v in variants_to_try:
        tried += 1
        started = time.monotonic()
        try:
            s, _, _, _ = check(client, addr, v, flags)
        except match.CompileError:
            mutations.append({"category": category, "score": 0, "compile_error": True,
                              "seconds": round(time.monotonic() - started, 3)})
            continue
        mutations.append({"category": category, "score": s, "compile_error": False,
                          "exact": s == 100, "seconds": round(time.monotonic() - started, 3)})
        if s > best[0]:
            best = (s, v)
            speculative = category in SPECULATIVE or category in ("argument_order", "immediate_constant",
                                                                  "branch_condition", "calling_convention")
        if s == 100:
            break
    return ImproveResult(best[0], best[1], tried, speculative, mutations)
