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
# Compile budget per repair round. 8 keeps a single arm fast; combining the
# permutation engine with guided repair needs a larger budget or the guided
# variants get crowded out (measured: 10 -> 8 improved at 8).
MAX_VARIANTS = 16

# --- permutation transforms (semantics-preserving) ---
# Adapted from decomp-permuter's PERM list (MIT): commutative operands,
# reversed inequalities, and adjacent independent declaration reordering.
# Text-level and conservative: each transform only reorders forms that
# compile to the same semantics so the compiler's own codegen choice is
# what changes.

_COMMUTATIVE_OPS = ("+", "*", "&", "|", "^", "==", "!=")
# longest first so "<=" is not shadowed by "<"
_INEQUALITIES = (("<=", ">="), (">=", "<="), ("<", ">"), (">", "<"))
_OPERAND = r"[A-Za-z_]\w*(?:\s*\([^()]*\)|->\w+|\.\w+|\[\w+\])?"
# relational swaps also compare against numeric literals (a >= 2 -> 2 <= a)
_REL_OPERAND = r"[A-Za-z_0-9]\w*(?:\s*\([^()]*\)|->\w+|\.\w+|\[\w+\])?"
_SWAP = r"\s*%s\s*"


def commutative_swap_variants(src):
    """Swap operands of every commutative operator, at every site.

    A function usually has several, and each swap is an independent variant
    worth trying: the compiler may allocate registers differently for one
    ordering than another. Operands may be calls or member accesses, which
    is what the generated code actually looks like.
    """
    out = []
    for op in _COMMUTATIVE_OPS:
        pattern = re.compile("(%s)%s(%s)" % (_OPERAND, _SWAP % re.escape(op), _OPERAND))
        for m in pattern.finditer(src):
            if m.group(1) == m.group(2):
                continue  # a + a swaps to itself
            out.append(src[:m.start()] + m.group(2) + " " + op + " "
                        + m.group(1) + src[m.end():])
    return list(dict.fromkeys(out))


def inequality_swap_variant(src):
    """a < b -> b > a (and friends) for the first relational operator."""
    for op, flipped in _INEQUALITIES:
        m = re.compile("(%s)%s(%s)" % (_REL_OPERAND, _SWAP % re.escape(op), _REL_OPERAND)).search(src)
        if m and m.group(1) != m.group(2):
            return src[:m.start()] + m.group(2) + " " + flipped + " " + m.group(1) + src[m.end():]
    return None


def reorder_decls_variants(src):
    """Swap two adjacent same-type scalar locals with no initializers.

    Declaration order drives MSVC stack slot and (in practice) register
    allocation, which the instruction alignment sees as regalloc deltas.
    Only trivially independent declarations are touched.
    """
    decl = re.compile(r"(?m)^([ \t]*)([A-Za-z_]\w*(?:\s+[A-Za-z_]\w*)?)\s+([A-Za-z_]\w*)[ \t]*;$")
    matches = list(decl.finditer(src))
    out = []
    for a, b in zip(matches, matches[1:]):
        if a.group(2) != b.group(2) or src[a.end():b.start()].strip():
            continue
        if a.group(3) == b.group(3):
            continue
        swapped = (b.group(1) + b.group(2) + " " + b.group(3) + ";" +
                   src[a.end():b.start()] +
                   a.group(1) + a.group(2) + " " + a.group(3) + ";")
        out.append(src[:a.start()] + swapped + src[b.end():])
        if len(out) >= 4:
            break
    return out


def permute_variants(src, alignment=None):
    """Ordered semantics-preserving variants ranked by alignment evidence.

    alignment is match.align_insns evidence from the best-compiled candidate:
    regalloc-dominated mismatches try declaration reordering first (it is what
    moves MSVC allocation), args-dominated try operand swaps, and value/branch
    differences try the comparison forms. Without evidence the canonical
    transform order is used.
    """
    ranked = []
    ranked.extend(("commutative", v) for v in commutative_swap_variants(src))
    ineq = inequality_swap_variant(src)
    if ineq:
        ranked.append(("inequality", ineq))
    ranked.extend(("reorder_decls", v) for v in reorder_decls_variants(src))
    if not alignment or not alignment.get("steps"):
        out, seen = [], {src}
        for category, value in ranked:
            if value not in seen:
                seen.add(value)
                out.append((category, value))
        return out
    counts = {"regalloc": 0, "args": 0, "del": 0, "ins": 0, "same": 0}
    for step in alignment["steps"]:
        if step["op"] in counts:
            counts[step["op"]] += 1
    if counts["regalloc"] >= counts["args"]:
        first = ("reorder_decls",)
    else:
        first = ("commutative", "inequality")
    ordered = ([r for r in ranked if r[0] in first] +
               [r for r in ranked if r[0] not in first])
    out, seen = [], {src}
    for category, value in ordered:
        if value not in seen:
            seen.add(value)
            out.append((category, value))
    return out


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


_FUNC_DEF = re.compile(r"(?m)^([A-Za-z_][\w:<>,*& \t]*?)\b([A-Za-z_]\w*(?:::[A-Za-z_]\w*)?)\s*\(")
_MEMBER_DECL = re.compile(r"(?m)^(\s+[A-Za-z_][\w:<>,*& \t]*?)\b([A-Za-z_]\w*)\s*\([^;{]*\)\s*;")


def _target_function_name(src):
    matches = list(_FUNC_DEF.finditer(src))
    return matches[-1].group(2) if matches else None


def _function_body(src, name):
    """Brace-delimited body of the definition of name, or None."""
    m = re.search(r"(?m)^[A-Za-z_][\w:<>,*& \t]*?\b" + re.escape(name) + r"\s*\(", src)
    if not m:
        return None
    opening = src.find("{", m.end() - 1)
    if opening < 0:
        return None
    depth = 0
    for i in range(opening, len(src)):
        if src[i] == "{":
            depth += 1
        elif src[i] == "}":
            depth -= 1
            if depth == 0:
                return src[opening:i]
    return None


def cdecl_member_variants(src, diagnosis):
    """Member functions default to thiscall (ret N); targets are often __cdecl
    members (plain ret). Add __cdecl to the in-class declaration — MSVC
    rejects the keyword on the out-of-class definition (C2373)."""
    if not diagnosis:
        return []
    cleanup = diagnosis.get("return_cleanup") or {}
    if cleanup.get("target") or not cleanup.get("candidate"):
        return []
    name = _target_function_name(src)
    if not name or "::" not in name:
        return []
    short = name.split("::")[-1]
    out = []
    for m in _MEMBER_DECL.finditer(src):
        if m.group(2) != short or "__cdecl" in m.group(1):
            continue
        if "__stdcall" in m.group(1) or "__thiscall" in m.group(1):
            fixed = re.sub(r"__(?:stdcall|thiscall)", "__cdecl", m.group(1))
            out.append(src[:m.start()] + fixed + src[m.start():])
        else:
            head = src[:m.end(1)]
            if not head.endswith(" "):
                head += " "
            out.append(head + "__cdecl " + src[m.end(1):])
    return out


def free_function_variants(src, diagnosis):
    """When the target is a free function (no this) but the candidate is a
    member, converting to a free __cdecl function removes the extra stack
    argument. Only when the body never uses `this`."""
    if not diagnosis:
        return []
    cleanup = diagnosis.get("return_cleanup") or {}
    if cleanup.get("target") or not cleanup.get("candidate"):
        return []
    name = _target_function_name(src)
    if not name or "::" not in name:
        return []
    short = name.split("::")[-1]
    body = _function_body(src, name)
    if body is None or re.search(r"\bthis\b", body):
        return []
    out = []
    for m in _MEMBER_DECL.finditer(src):
        if m.group(2) == short:
            tail = src[m.end():]
            if tail.startswith("\n"):
                tail = tail[1:]
            removed = src[:m.start()] + tail
            m2 = re.search(r"(?m)^([A-Za-z_][\w:<>,*& \t]*?)\b" + re.escape(name) + r"\s*\(", removed)
            if m2 and "__cdecl" not in m2.group(1):
                head = removed[:m2.end(1)]
                if not head.endswith(" "):
                    head += " "
                out.append(head + "__cdecl " + removed[m2.end(1):].replace(name, short, 1))
            break
    return out


def calling_convention_variants(src, diagnosis):
    """Add/remove explicit MSVC convention only when return cleanup proves it.
    The convention is read from the target function's own declaration and
    definition, never from unrelated externs in the same file."""
    if not diagnosis:
        return []
    cleanup = diagnosis.get("return_cleanup") or {}
    target_cleans, candidate_cleans = bool(cleanup.get("target")), bool(cleanup.get("candidate"))
    if target_cleans == candidate_cleans:
        return []
    name = _target_function_name(src)
    if not name:
        return []
    out = []
    if not target_cleans and candidate_cleans:
        out.extend(cdecl_member_variants(src, diagnosis))
        out.extend(free_function_variants(src, diagnosis))
        if "::" not in name:
            m = re.search(r"(?m)^([A-Za-z_][\w:<>,*& \t]*?)\b" + re.escape(name) + r"\s*\(", src)
            if m and "__stdcall" in m.group(1):
                out.append(src[:m.start()] + m.group(1).replace("__stdcall", "__cdecl") + src[m.end(1):])
    else:
        m = re.search(r"(?m)^([A-Za-z_][\w:<>,*& \t]*?)\b" + re.escape(name) + r"\s*\(", src)
        if m and not any(k in m.group(1) for k in ("__cdecl", "__stdcall", "__thiscall")):
            head = src[:m.end(1)]
            if not head.endswith(" "):
                head += " "
            out.append(head + "__stdcall " + src[m.end(1):])
    return out


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


def typed_member_return_variants(src, diagnosis):
    """Return owning struct pointer for void member factories/constructors."""
    if (diagnosis or {}).get("mismatch_class") != "missing return value":
        return []
    names = set(re.findall(r"\bstruct\s+(\w+)\s*\{", src))
    out = []
    for name in names:
        decl = re.compile(r"\bvoid\s+(construct|create|init)\s*\(([^)]*)\)\s*;")
        definition = re.compile(r"\bvoid\s+" + re.escape(name) +
                                r"::(construct|create|init)\s*\(")
        if not decl.search(src) or not definition.search(src):
            continue
        updated = decl.sub(lambda m: "%s* %s(%s);" % (name, m.group(1), m.group(2)), src, count=1)
        updated = definition.sub(lambda m: "%s* %s::%s(" % (name, name, m.group(1)), updated, count=1)
        close = updated.rfind("}")
        if close >= 0:
            typed = updated[:close] + "    return this;\n" + updated[close:]
            out.append(typed)
            out.extend(volatile_zero_store_variants(typed, diagnosis))
    return out


def volatile_zero_store_variants(src, diagnosis):
    """Try volatile only on zero stores; MSVC scheduling can then match target order."""
    if (diagnosis or {}).get("mismatch_class") != "missing return value":
        return []
    out = []
    pattern = re.compile(r"\*\(int\*\)\(\(char\*\)this\s*\+\s*(0x[0-9a-fA-F]+|\d+)\)\s*=\s*0\s*;")
    for m in pattern.finditer(src):
        out.append(src[:m.start()] + m.group().replace("*(int*)", "*(volatile int*)", 1) + src[m.end():])
    return out


def noreturn_exception_variants(src, diagnosis):
    """MSVC shrink-wrap hint for imported RaiseException-style calls."""
    if "RaiseException" not in src or "__declspec(noreturn)" in src:
        return []
    marker = 'extern "C" __declspec(dllimport) void __stdcall RaiseException'
    if marker not in src:
        return []
    return [src.replace(marker, 'extern "C" __declspec(noreturn) __declspec(dllimport) void __stdcall RaiseException', 1)]


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
    cleanup = (diagnosis or {}).get("return_cleanup") or {}
    if cleanup.get("target") != cleanup.get("candidate"):
        add("calling_convention", calling_convention_variants(src, diagnosis))
    opcodes = (diagnosis or {}).get("opcode_delta", {})
    if (opcodes.get("sar", 0) < 0 < opcodes.get("shr", 0) and "unsigned int" in src):
        add("signedness", [toggle_int_signedness(src)])
    elif "movsx" in opcodes or "movzx" in opcodes:
        add("signedness", [toggle_char_signedness(src), toggle_int_signedness(src)])
    if (diagnosis or {}).get("mismatch_class") == "missing return value":
        add("return_value", return_value_variants(src, diagnosis))
        add("typed_member_return", typed_member_return_variants(src, diagnosis))
        add("volatile_zero_store", volatile_zero_store_variants(src, diagnosis))
    add("noreturn_exception", noreturn_exception_variants(src, diagnosis))
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
            guided_categories=None, guided_fallback=True, permute=False,
            alignment=None):
    """Compile-and-test bounded variants; guided mode requires mismatch evidence.

    ImproveResult is a 3-tuple (score, src, tried) with a `.speculative`
    attribute, True when the winning variant came from a SPECULATIVE
    mutator. The tuple form keeps old 3-unpacking callers working.
    check is injectable as check(client, addr, text, flags) -> (score, ...);
    defaults to match.check_text. Variants raising CompileError are skipped.
    permute enables the semantics-preserving permutation variants ranked by
    instruction-alignment evidence (opt-in).
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
    variants_to_try = []
    if guided:
        guided_out = guided_variants(src, diagnosis, guided_categories)
        if guided_fallback:
            guided_out.extend((category, value) for category, value in legacy
                              if value not in {v for _, v in guided_out})
        variants_to_try.extend(guided_out)
    if permute:
        if alignment is None:
            alignment = match.alignment_evidence(client, addr, src, flags)
        variants_to_try.extend(permute_variants(src, alignment))
    elif not guided:
        variants_to_try = legacy
    variants_to_try = variants_to_try[:MAX_VARIANTS]
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
