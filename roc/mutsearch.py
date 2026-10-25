"""Compiler-scored beam search over semantics-preserving source rewrites.

Near misses whose residue is x87 operand order, instruction scheduling or register
choice usually respond to expression-tree shape: operand order, grouping, statement
order and declaration order. Each rewrite here keeps the program's meaning; the
compiler decides which shape reproduces the target. No model, no invented facts.
"""
import concurrent.futures as cf
import hashlib
import re

from roc import match, mutate

_ID = r"[A-Za-z_]\w*"
# One operand: an identifier with member/index/call suffixes, a number, or a cast-free paren group.
_ATOM = r"(?:%s(?:\s*(?:->|\.)\s*%s|\[[^\[\]]*\]|\([^()]*\))*|\d+(?:\.\d*)?f?|\([^()]*\))" % (_ID, _ID)
# A product/quotient term counts as one operand of + (a + b * c -> b * c + a).
_TERM = r"%s(?:\s*[*/%%]\s*%s)*" % (_ATOM, _ATOM)
_STMT = re.compile(r"(?m)^([ \t]+)([^\n{};]*;)[ \t]*$")
_BODY_OPEN = re.compile(r"\)\s*(?:const\s*)?\{")
_KEYWORDS = {"return", "if", "for", "while", "switch", "case", "do", "else", "goto", "break", "continue"}


def bodies(src):
    """(start, end) spans of function bodies, inline members included; struct bodies are not."""
    out = []
    for m in _BODY_OPEN.finditer(src):
        start = m.end() - 1
        depth = 0
        for i in range(start, len(src)):
            if src[i] == "{":
                depth += 1
            elif src[i] == "}":
                depth -= 1
                if depth == 0:
                    out.append((start + 1, i))
                    break
    spans = []
    for s, e in sorted(out):
        if not spans or s >= spans[-1][1]:
            spans.append((s, e))
    return spans


def _in_body(spans, pos):
    return any(s <= pos < e for s, e in spans)


_PREC = {"*": 3, "/": 3, "%": 3, "+": 4, "-": 4, "<<": 5, ">>": 5, "<": 6, ">": 6, "<=": 6, ">=": 6,
         "==": 7, "!=": 7, "&": 8, "^": 9, "|": 10, "&&": 11, "||": 12}
_OPS = sorted(_PREC, key=len, reverse=True)


def _left_op(before):
    """Binary operator ending `before`, '' at an expression start ( `(`, `,`, `=`, `return` ...), None if unknown."""
    text = before.rstrip()
    if not text or text[-1] in "(,;=?:[{" or re.search(r"\breturn$", text):
        return "" if not text.endswith(("==", "!=", "<=", ">=")) else text[-2:]
    for op in _OPS:
        if text.endswith(op):
            return op
    return None


def _right_op(after):
    text = after.lstrip()
    if not text or text[0] in "),;]?:}":
        return ""
    for op in _OPS:
        if text.startswith(op) and not text.startswith(op + "="):
            return op
    return None


def _swappable(op, left, right, shared_left_ok):
    """Swapping a op b keeps the parse when both neighbours bind more loosely (or are the same op)."""
    if left is None or right is None:
        return False
    rank = _PREC[op]
    # x - a + b must not become x - b + a; a + b * c must not become b + a * c
    left_ok = left == "" or _PREC[left] > rank or (shared_left_ok and left == op)
    right_ok = right == "" or _PREC[right] >= rank
    return left_ok and right_ok


def commutations(src, spans):
    """Swap the two operands of one arithmetic/bitwise commutative operator."""
    out = []
    for op in ("*", "+", "&", "|", "^"):
        unit = _TERM if op == "+" else _ATOM
        pattern = re.compile(r"(?<![\w.\]\)>])(%s)\s*%s(?![=%s])\s*(%s)(?![\w(\[.]|->)" % (unit, re.escape(op), re.escape(op), unit))
        for m in pattern.finditer(src):
            a, b = m.group(1), m.group(2)
            line_start = src.rfind("\n", 0, m.start()) + 1
            before = src[line_start:m.start()]
            if a == b or not _in_body(spans, m.start()):
                continue
            if not _swappable(op, _left_op(before), _right_op(src[m.end():m.end() + 4]), shared_left_ok=True):
                continue
            if op in "*&" and re.fullmatch(_ID, a) and re.match(r"\s*(?:[=;,)]|\[)", src[m.end():]) and \
                    re.search(r"(?:^\s*|[(,;{]\s*)$", before):
                continue  # `T * name` / `T & name` declaration, not an expression
            out.append(("commute %s" % op, src[:m.start()] + b + " " + op + " " + a + src[m.end():]))
    return out


def regroupings(src, spans):
    """a op b op c -> a op (b op c), and the explicit (a op b) op c, for + and *."""
    out = []
    for op in ("+", "*"):
        o = re.escape(op)
        pattern = re.compile(r"(?<![\w.\]\)>])(%s)\s*%s\s*(%s)\s*%s\s*(%s)(?![\w(\[.*/]|->)" % (_ATOM, o, _ATOM, o, _ATOM))
        for m in pattern.finditer(src):
            line_start = src.rfind("\n", 0, m.start()) + 1
            if not _in_body(spans, m.start()) or not _swappable(
                    op, _left_op(src[line_start:m.start()]), _right_op(src[m.end():m.end() + 4]), shared_left_ok=True):
                continue
            a, b, c = m.groups()
            out.append(("regroup right %s" % op, src[:m.start()] + "%s %s (%s %s %s)" % (a, op, b, op, c) + src[m.end():]))
            out.append(("regroup left %s" % op, src[:m.start()] + "(%s %s %s) %s %s" % (a, op, b, op, c) + src[m.end():]))
    return out


def _writes(stmt):
    m = re.match(r"\s*(?:[\w:<>]+\s+)?([*&]?\s*%s(?:\s*(?:->|\.)\s*%s|\[[^\]]*\])*)\s*(?:[-+*/|&^]|<<|>>)?=(?!=)" % (_ID, _ID), stmt)
    return re.sub(r"\s+", "", m.group(1)).lstrip("*&") if m else None


def _mentions(stmt, lvalue):
    """Does stmt read or write lvalue? Plain names match as words, member paths as text."""
    if re.fullmatch(_ID, lvalue):
        return lvalue in re.findall(_ID, stmt)
    return lvalue in re.sub(r"\s+", "", stmt)


def statement_swaps(src, spans):
    """Swap two adjacent simple statements that cannot see each other's writes."""
    out = []
    stmts = [m for m in _STMT.finditer(src) if _in_body(spans, m.start())]
    for x, y in zip(stmts, stmts[1:]):
        between = src[x.end():y.start()]
        if between.strip():
            continue
        a, b = x.group(2), y.group(2)
        words = lambda s: set(re.findall(_ID, s))
        if (words(a) | words(b)) & _KEYWORDS:
            continue
        wa, wb = _writes(a), _writes(b)
        if not wa or not wb:
            continue
        if _mentions(b, wa) or _mentions(a, wb):
            continue
        if "(" in a and "(" in b and re.search(r"%s\s*\(" % _ID, a) and re.search(r"%s\s*\(" % _ID, b):
            continue  # two calls: their order is observable
        swapped = x.group(1) + b + between + y.group(1) + a
        out.append(("swap statements", src[:x.start()] + swapped + src[y.end():]))
    return out


def compound_assignments(src, spans):
    """a = a op b;  <->  a op= b;"""
    out = []
    for m in re.finditer(r"(?m)^([ \t]+)(%s(?:\s*(?:->|\.)\s*%s|\[[^\]]*\])*)\s*=\s*\2\s*([-+*/|&^])\s*([^;]+);" % (_ID, _ID), src):
        if _in_body(spans, m.start()):
            out.append(("compound", src[:m.start()] + "%s%s %s= %s;" % (m.group(1), m.group(2), m.group(3), m.group(4)) + src[m.end():]))
    for m in re.finditer(r"(?m)^([ \t]+)(%s(?:\s*(?:->|\.)\s*%s|\[[^\]]*\])*)\s*([-+*/|&^])=\s*([^;]+);" % (_ID, _ID), src):
        if _in_body(spans, m.start()):
            rhs = m.group(4) if re.fullmatch(_ATOM, m.group(4).strip()) else "(%s)" % m.group(4)
            out.append(("expand compound", src[:m.start()] + "%s%s = %s %s %s;" % (m.group(1), m.group(2), m.group(2), m.group(3), rhs) + src[m.end():]))
    return out


def variants(src):
    """Every one-edit semantics-preserving rewrite of the function bodies in src."""
    spans = bodies(src)
    found = (commutations(src, spans) + regroupings(src, spans) + statement_swaps(src, spans) +
             compound_assignments(src, spans) + [("reorder decls", v) for v in mutate.reorder_decls_variants(src)])
    seen, out = {src}, []
    for name, text in found:
        first = next((i for i, (x, y) in enumerate(zip(src, text)) if x != y), min(len(src), len(text)))
        if text not in seen and _in_body(spans, first):  # never member order: that is layout
            seen.add(text)
            out.append((name, text))
    return out


def residue(diff):
    """Changed instruction lines in a check diff (the score's tie-breaker)."""
    return sum(1 for line in (diff or "").splitlines()
               if line[:1] in "+-" and not line.startswith(("+++", "---")))


def search(client, addr, source, budget=120, beam=3, depth=3, jobs=6, log=None):
    """Beam search; returns dict(score, residue, source, path=[edit names], compiles)."""
    cache = {}

    def evaluate(text):
        key = hashlib.sha256(text.encode()).hexdigest()
        if key not in cache:
            try:
                score, _, diff, _ = match.check_text(client, addr, text)
                cache[key] = (score, residue(diff))
            except match.CompileError:
                cache[key] = (-1, 1 << 30)
        return cache[key]

    start = evaluate(source)
    best = dict(score=start[0], residue=start[1], source=source, path=[], compiles=1)
    frontier = [(start, source, [])]
    with cf.ThreadPoolExecutor(jobs) as pool:
        for generation in range(depth):
            pending = []
            for _, text, path in frontier:
                pending += [(text2, path + [name]) for name, text2 in variants(text)]
            pending = [p for p in dict((t, p) for t, p in pending).items()]  # unique texts
            room = budget - len(cache)
            if room <= 0 or not pending:
                break
            pending = pending[:room]
            results = list(pool.map(lambda item: (evaluate(item[0]), item[0], item[1]), pending))
            results.sort(key=lambda r: (-r[0][0], r[0][1]))
            top = results[0]
            if (top[0][0], -top[0][1]) > (best["score"], -best["residue"]):
                best.update(score=top[0][0], residue=top[0][1], source=top[1], path=top[2])
                if log:
                    log("%s %s gen %d: %d%% residue %d via %s" % (client, addr, generation + 1, top[0][0], top[0][1], " > ".join(top[2])))
            if best["score"] == 100:
                break
            frontier = [r for r in results[:beam] if r[0][0] >= 0]
    best["compiles"] = len(cache)
    return best
