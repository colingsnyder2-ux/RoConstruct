"""Small validated C++ source mutations with compile-and-test feedback.

Each mutator is a pure text transform returning a variant or None. `improve`
compiles every variant with the client's real compiler via an injectable
check function and keeps the best score, so a bad guess costs compile time
and nothing else. No LLM, no new models.
"""
import re

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


class ImproveResult(tuple):
    """(score, src, tried) plus `.speculative`; unpacks like the old 3-tuple."""
    def __new__(cls, score, src, tried, speculative=False):
        self = super().__new__(cls, (score, src, tried))
        self.speculative = speculative
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


def improve(client, addr, src, flags=None, check=None):
    """Compile-and-test every variant. Returns ImproveResult(score, src, tried).

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
    best, tried, speculative = (base, src), 0, False
    for fn in MUTATORS:
        try:
            v = fn(src)
        except (ValueError, IndexError):
            continue
        if not v or v == src:
            continue
        tried += 1
        try:
            s, _, _, _ = check(client, addr, v, flags)
        except match.CompileError:
            continue
        if s > best[0]:
            best = (s, v)
            speculative = fn.__name__ in SPECULATIVE
    if _reversed_call_order(diagnosis):
        for v in swap_call_argument_variants(src):
            if v == src:
                continue
            tried += 1
            try:
                s, _, _, _ = check(client, addr, v, flags)
            except match.CompileError:
                continue
            if s > best[0]:
                best, speculative = (s, v), True
    return ImproveResult(best[0], best[1], tried, speculative)
