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
    """a op b op c -> a op (b op c), and the explicit (a op b) op c, for + and *.
    Sums regroup whole product terms (x*x + y*y + z*z): x87 sum order follows the grouping."""
    out = []
    for op in ("+", "*"):
        o, unit = re.escape(op), _TERM if op == "+" else _ATOM
        pattern = re.compile(r"(?<![\w.\]\)>])(%s)\s*%s\s*(%s)\s*%s\s*(%s)(?![\w(\[.*/]|->)" % (unit, o, unit, o, unit))
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


_CASTS = {"float", "double", "int", "unsigned", "long", "short", "char"}


def inline_locals(src, spans):
    """Fold a local initialised once and read once into its use: a named temporary
    versus an inline subexpression decides what stays on the x87 stack."""
    out = []
    decl = re.compile(r"(?m)^[ \t]+(?:const\s+)?[\w:]+\s+(%s)\s*=\s*([^;{}]+);[ \t]*\n" % _ID)
    for m in decl.finditer(src):
        body = next(((s, e) for s, e in spans if s <= m.start() < e), None)
        if not body:
            continue
        name, expr = m.group(1), m.group(2).strip()
        if any(word not in _CASTS for word in re.findall(r"(%s)\s*\(" % _ID, expr)):
            continue  # moving a call can reorder observable effects
        rest = src[m.end():body[1]]
        uses = list(re.finditer(r"(?<![\w.>])%s\b" % re.escape(name), rest))
        if len(uses) != 1:
            continue
        between = rest[:uses[0].start()]
        written = [_writes(stmt) for stmt in between.split(";")]
        if "++" in between or "--" in between or any(w and _mentions(expr, w) for w in written) or \
                any(word not in _CASTS | _KEYWORDS for word in re.findall(r"(%s)\s*\(" % _ID, between)):
            continue  # an operand may change before the use
        text = rest[:uses[0].start()] + "(%s)" % expr + rest[uses[0].end():]
        out.append(("inline local %s" % name, src[:m.start()] + text + src[body[1]:]))
    return out


def variants(src):
    """Every one-edit semantics-preserving rewrite of the function bodies in src."""
    spans = bodies(src)
    found = (commutations(src, spans) + regroupings(src, spans) + statement_swaps(src, spans) +
             compound_assignments(src, spans) + inline_locals(src, spans) + [("reorder decls", v) for v in mutate.reorder_decls_variants(src)])
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


_LIB = re.compile(r"(?m)^(//[ \t]*roc-lib:[ \t]*)(\S+)[ \t]+(\S.*?)[ \t]*$")
_FLAGS = re.compile(r"(?m)^(//[ \t]*roc-flags:[ \t]*)(.*?)[ \t]*$")
_PRECISE_OFF = "#pragma float_control(precise,off,push)\n"


def gates(stub, unit):
    """The two float gates past x87 exacts needed: /fp:fast on the flags, and
    precise-off float control around the code (the unit when there is one)."""
    out = []
    m = _FLAGS.search(stub)
    if m:
        flags = m.group(2)
        new = re.sub(r"\s*/fp:fast\b", "", flags) if "/fp:fast" in flags else flags + " /fp:fast"
        out.append(("toggle /fp:fast", (stub[:m.start(2)] + new + stub[m.end(2):], unit)))
    if unit is not None:
        toggled = unit.replace(_PRECISE_OFF, "", 1) if _PRECISE_OFF in unit else _PRECISE_OFF + unit
        out.append(("toggle float_control", (stub, toggled)))
    elif _PRECISE_OFF in stub:
        out.append(("toggle float_control", (stub.replace(_PRECISE_OFF, "", 1), None)))
    return out


def edits(state):
    """One-edit neighbours of (stub, unit): a roc-lib stub mutates its unit, a plain source itself."""
    stub, unit = state
    if unit is None:
        return gates(stub, unit) + [(name, (text, None)) for name, text in variants(stub)]
    return gates(stub, unit) + [(name, (stub, text)) for name, text in variants(unit)]


def unit_of(source):
    """(recipe, path, folder, text) of the generated/vendor unit a roc-lib stub names, else None."""
    m = _LIB.search(source)
    if not m:
        return None
    from roc import libs
    recipe, path = m.group(2), m.group(3).replace("\\", "/")
    folder = libs.fetch(recipe)
    file = folder / path
    if not file.is_file():
        raise match.CompileError("no file %r in library %s (run `roc pull`)" % (path, recipe))
    return recipe, path, folder, file.read_text(encoding="utf-8", errors="replace")


def _measure(client, addr, text):
    """(score, precise %, diff) for one candidate text."""
    score, _, diff, _ = match.check_text(client, addr, text)
    return score, match.precise_score(client, addr, text), diff


def _scratch_check(client, addr, recipe, path, folder):
    """check_text for a (stub, unit) state. A mutated unit is written beside the original
    (so its relative includes resolve) under a throwaway roc_ name, then removed with
    its preprocessed cache; only a winner is registered (save)."""
    directory = path.rsplit("/", 1)[0] + "/" if "/" in path else ""

    def check(state):
        stub, unit = state
        if unit is None:
            return _measure(client, addr, stub)
        rel = "%sroc_mutscratch_%s.cpp" % (directory, hashlib.sha256(unit.encode()).hexdigest()[:16])
        file = folder / rel
        file.write_text(unit, encoding="utf-8")
        try:
            return _measure(client, addr, _LIB.sub(lambda m: m.group(1) + recipe + " " + rel, stub, 1))
        finally:
            file.unlink(missing_ok=True)
            for cache in (match.ROOT / "work" / "libcache" / recipe).glob("*/" + rel.replace("/", "__") + "*"):
                cache.unlink(missing_ok=True)
    return check


def search(client, addr, source, budget=120, beam=3, depth=3, jobs=6, log=None, check=None):
    """Beam search ranked by score, untruncated precise %, then residue lines; returns
    dict(score, precise, residue, source, unit, start, start_precise, path=[edit names], compiles).
    `source` may be a roc-lib stub: its unit text is then what gets rewritten."""
    found = unit_of(source)
    unit = found[3] if found else None
    if check is None:
        check = _scratch_check(client, addr, *found[:3]) if found else \
            (lambda state: _measure(client, addr, state[0]))
    cache = {}

    def evaluate(state):
        key = hashlib.sha256(repr(state).encode()).hexdigest()
        if key not in cache:
            try:
                score, precise, diff = check(state)
                cache[key] = (score if score is not None else -1, precise, residue(diff))
            except match.CompileError:
                cache[key] = (-1, -1.0, 1 << 30)
        return cache[key]

    origin = (source, unit)
    start = evaluate(origin)
    best = dict(score=start[0], precise=start[1], residue=start[2], source=source, unit=unit,
                start=start[0], start_precise=start[1], path=[], compiles=1)
    frontier = [(start, origin, [])]
    with cf.ThreadPoolExecutor(jobs) as pool:
        for generation in range(depth):
            pending = {}
            for _, state, path in frontier:
                for name, state2 in edits(state):
                    pending.setdefault(state2, path + [name])
            pending = [item for item in pending.items() if hashlib.sha256(repr(item[0]).encode()).hexdigest() not in cache]
            room = budget - len(cache)
            if room <= 0 or not pending:
                break
            results = list(pool.map(lambda item: (evaluate(item[0]), item[0], item[1]), pending[:room]))
            results.sort(key=lambda r: (-r[0][0], -r[0][1], r[0][2]))
            top = results[0]
            if (top[0][0], top[0][1], -top[0][2]) > (best["score"], best["precise"], -best["residue"]):
                best.update(score=top[0][0], precise=top[0][1], residue=top[0][2],
                            source=top[1][0], unit=top[1][1], path=top[2])
                if log:
                    log("%s %s gen %d: %.3f%% residue %d via %s" % (client, addr, generation + 1, top[0][1], top[0][2], " > ".join(top[2])))
            if best["score"] == 100:
                break
            frontier = [r for r in results[:beam] if r[0][0] >= 0]
    best["compiles"] = len(cache)
    return best


def save(client, addr, original, best):
    """Write an improved winner to work/CLIENT/scratch/ADDR/mutsearch/ADDR.cpp (submit-ready
    name), registering a changed unit with libs.add_unit. Returns the path, or None."""
    if not best["path"]:  # search only records a path on a strict improvement
        return None
    stub = best["source"]
    found = unit_of(original)
    if found and best["unit"] != found[3]:
        from roc import libs
        recipe, path = found[0], found[1]
        directory = path.rsplit("/", 1)[0] + "/" if "/" in path else ""
        name = libs.add_unit(recipe, best["unit"], prefix="roc_mutsearch_%s_" % addr)
        stub = _LIB.sub(lambda m: m.group(1) + recipe + " " + directory + name, stub, 1)
    out = match.ROOT / "work" / client / "scratch" / addr / "mutsearch" / (addr + ".cpp")
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(stub, encoding="utf-8")
    return out
