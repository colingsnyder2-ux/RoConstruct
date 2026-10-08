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
    try:
        base, _, _, _ = check(client, addr, src, flags)
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
    return ImproveResult(best[0], best[1], tried, speculative)
