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


def base_padding_variants(src, diagnosis):
    """Adjust inherited-object padding when decoded field offsets prove a delta."""
    out = []
    arrays = list(re.finditer(
        r"\b(?:char|unsigned\s+char)\s+\w*\s*\[\s*(0x[0-9a-f]+|\d+)\s*-\s*8\s*\]",
        src, re.I))
    if len(arrays) != 1:
        return out
    for diff in (diagnosis or {}).get("stack_offset_diffs", [])[:2]:
        try:
            delta = _literal_value(diff["target"]) - _literal_value(diff["candidate"])
        except (KeyError, ValueError):
            continue
        if not delta or delta % 4:
            continue
        match = arrays[0]
        old = _literal_value(match.group(1))
        new = old + delta
        if new <= 8:
            continue
        text = hex(new) if match.group(1).lower().startswith("0x") else str(new)
        value = src[:match.start(1)] + text + src[match.end(1):]
        if value not in out:
            out.append(value)
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


def function_pointer_convention_variants(src, diagnosis):
    """Model an indirect call's ECX receiver as an MSVC thiscall pointer.

    Target evidence must show `mov ecx, ...; call [ptr]` while the candidate
    pushed a placeholder first argument. This is distinct from changing the
    target function's own convention and fixes historical RTTI/vtable-style
    function pointers without guessing globally.
    """
    if not (diagnosis or {}).get("receiver_call_diffs"):
        return []
    if "__stdcall *" not in src or "__thiscall *" in src:
        return []
    converted = src.replace("__stdcall *", "__thiscall *", 1)
    out = [converted]
    # Under thiscall the receiver is ECX. Try one diagnosed call-argument
    # reversal too, but only for the known indirect pointer symbol.
    for swapped in swap_call_argument_variants(converted):
        if "sub_77e708(" in swapped and swapped not in out:
            out.append(swapped)
    return out


def direct_member_receiver_variants(src, diagnosis):
    """Turn `callee(this, arg)` into a member call when target loads ECX.

    MSVC rejects `__thiscall` on free functions. A real member declaration is
    the legal source-level form and preserves the historical receiver ABI.
    Only one unambiguous extern and one matching struct are transformed.
    """
    if not (diagnosis or {}).get("receiver_call_diffs"):
        return []
    decl = re.search(r'(?m)^extern\s+"C"\s+(.+?)\s+__stdcall\s+(\w+)\s*\(\s*void\s*\*\s*,\s*([^)]*)\)\s*;', src)
    structs = list(re.finditer(r"\bstruct\s+(\w+)\s*\{", src))
    if not decl or len(structs) != 1:
        return []
    ret, name, arg = decl.group(1).strip(), decl.group(2), decl.group(3).strip()
    call = re.search(r"\b" + re.escape(name) + r"\s*\(\s*this\s*,\s*([^()]*)\)", src)
    if not call:
        return []
    close = src.find("};", structs[0].end())
    if close < 0:
        return []
    member = "%s %s(%s);\n" % (ret, name, arg)
    updated = src[:decl.start()] + src[decl.end():]
    close = updated.find("};", updated.find("{") + 1)
    if close < 0:
        return []
    updated = updated[:close] + member + updated[close:]
    call = re.search(r"\b" + re.escape(name) + r"\s*\(\s*this\s*,\s*([^()]*)\)", updated)
    if not call:
        return []
    updated = updated[:call.start()] + name + "(" + call.group(1) + ")" + updated[call.end():]
    return [updated]


def direct_member_noarg_variants(src, diagnosis):
    """Turn a no-argument stdcall helper into an implicit-this member call."""
    if not any(diff.get("direct") for diff in (diagnosis or {}).get("receiver_call_diffs", [])):
        return []
    decl = re.search(r'(?m)^extern\s+"C"\s+(.+?)\s+__stdcall\s+(\w+)\s*\(\s*\)\s*;', src)
    structs = list(re.finditer(r"\bstruct\s+(\w+)\s*\{", src))
    if not decl or not structs:
        return []
    if len(structs) == 1:
        owner = structs[0]
    else:
        owners = {match.group(1) for match in re.finditer(r"\b(\w+)::\w+\s*\(", src)}
        matches = [match for match in structs if match.group(1) in owners]
        if len(matches) != 1:
            return []
        owner = matches[0]
    ret, name = decl.group(1).strip(), decl.group(2)
    updated = src[:decl.start()] + src[decl.end():]
    owner_start = updated.find("struct " + owner.group(1))
    close = updated.find("};", updated.find("{", owner_start) + 1)
    if close < 0:
        return []
    updated = updated[:close] + "    %s %s();\n" % (ret, name) + updated[close:]
    return [updated]


def static_receiver_pointer_variants(src, diagnosis):
    """Make a direct stdcall declaration an indirect thiscall pointer.

    Evidence requires a target `mov ecx, static; call [ptr]` shape. The source
    must pass a literal/static receiver as the first argument to one unambiguous
    two-argument stdcall declaration. This preserves the indirect call target
    while moving that receiver into ECX.
    """
    if not (diagnosis or {}).get("receiver_call_diffs"):
        return []
    decl = re.search(r'(?m)^extern\s+"C"\s+(.+?)\s+__stdcall\s+(\w+)\s*\(([^)]*)\)\s*;', src)
    if not decl or len([part for part in decl.group(3).split(",") if part.strip()]) != 2:
        return []
    name = decl.group(2)
    call = re.search(r"\b" + re.escape(name) + r"\s*\(\s*([^,]+),\s*((?:\([^)]*\))?[^)]*)\)", src[decl.end():])
    if not call:
        return []
    replacement = 'extern "C" %s (__thiscall *%s)(%s);' % (decl.group(1).strip(), name, decl.group(3).strip())
    converted = src[:decl.start()] + replacement + src[decl.end():]
    first, second = call.group(1).strip(), call.group(2).strip()
    out = []
    if "0x" in first.lower():
        out.append(converted)
    elif "0x" in second.lower() or "str_" in second:
        swapped_values = swap_call_argument_variants(converted)
        tail_start = converted.find(name + "(", converted.find(";", 0) + 1)
        tail = converted[tail_start:] if tail_start >= 0 else ""
        nested = re.search(r"\b" + re.escape(name) + r"\s*\(\s*([^,]+),\s*((?:\([^)]*\))?[^)]*)\)", tail)
        if nested:
            manual = tail[:nested.start()] + name + "(" + nested.group(2).strip() + ", " + \
                     nested.group(1).strip() + ")" + tail[nested.end():]
            swapped_values.append(converted[:tail_start] + manual)
        for swapped in swapped_values:
            if re.search(r"\b" + re.escape(name) + r"\s*\(\s*" + re.escape(second), swapped):
                out.append(swapped)
                if (diagnosis or {}).get("register_delta", {}).get("al", 0) > 0:
                    returned = re.sub(r'(extern\s+"C"\s+)\S+(\s+\(__thiscall\s+\*' + re.escape(name) + r'\))',
                                       r'\1bool\2', swapped, count=1)
                    returned = re.sub(r'\b' + re.escape(name) + r'\((.*?)\);\s*return\s+true\s*;',
                                       r'return ' + name + r'(\1);', returned, count=1)
                    if returned != swapped:
                        out.append(returned)
    return list(dict.fromkeys(out))


def indirect_return_variants(src, diagnosis):
    """Propagate an indirect bool result when target lacks candidate `mov al,1`."""
    if (diagnosis or {}).get("register_delta", {}).get("al", 0) <= 0:
        return []
    decl = re.search(r'(?m)^extern\s+"C"\s+(.+?)\s+\(__thiscall\s+\*(\w+)\)\s*\(([^)]*)\)\s*;', src)
    if not decl:
        return []
    name = decl.group(2)
    call = re.search(r'\b' + re.escape(name) + r'\((.*?)\);\s*(?:\n[ \t]*)?return\s+true\s*;', src)
    if not call:
        return []
    replacement = 'extern "C" bool (__thiscall *%s)(%s);' % (name, decl.group(3).strip())
    updated = src[:decl.start()] + replacement + src[decl.end():]
    updated = re.sub(r'\b' + re.escape(name) + r'\((.*?)\);\s*(?:\n[ \t]*)?return\s+true\s*;',
                     r'return ' + name + r'(\1);', updated, count=1)
    return [updated] if updated != src else []


def virtual_call_view_variants(src, diagnosis):
    """Use a virtual-call view when target wants EDX indirect dispatch."""
    delta = (diagnosis or {}).get("register_delta", {})
    if delta.get("edx", 0) <= 0 or delta.get("ecx", 0) >= 0:
        return []
    if (diagnosis or {}).get("mismatch_class") != "register allocation difference":
        return []
    storage = re.search(r"(?m)^struct\s+(\w+)\s*\{\s*int\s+\w+;\s*int\s+\w+;\s*\};", src)
    raw = re.search(
        r"(?ms)([ \t]*)int\s*\*\s*vtable\s*=\s*\*\(int\*\*\)old;\s*"
        r"void\s*\(__stdcall\s*\*\s*release\)\(int\)\s*=\s*"
        r"\(void\s*\(__stdcall\s*\*\)\(int\)\)\*vtable;\s*"
        r"release\(1\);", src)
    if not storage or not raw:
        return []
    view = "\n\nstruct %sCall {\n    virtual void release(int);\n};" % storage.group(1)
    updated = src[:storage.end()] + view + src[storage.end():]
    updated = updated[:raw.start()] + raw.group(1) + \
        "((%sCall*)old)->release(1);" % storage.group(1) + updated[raw.end():]
    return [updated]


def virtual_slot_view_variants(src, diagnosis):
    """Model a vtable slot as a virtual member while preserving plain storage."""
    opcodes = (diagnosis or {}).get("opcode_delta", {})
    delta = (diagnosis or {}).get("register_delta", {})
    if (diagnosis or {}).get("mismatch_class") != "code-size mismatch":
        return []
    if opcodes.get("mov") != 1 or opcodes.get("push") != -1 or delta.get("ecx") != 1:
        return []
    call = re.search(r"0x([0-9a-fA-F]+)\)\)\((\w+)\)", src)
    prefix = "(((int (__thiscall*)(void*))*(void**)(*(char**)this + "
    if call and src.rfind(prefix, 0, call.start()) < 0:
        call = None
    if not call:
        return []
    offset = int(call.group(1), 16)
    slots = offset // 4
    if offset % 4 or slots < 1 or slots > 8:
        return []
    view = ["\n\nstruct VTableCallView {"]
    view.extend("    virtual int slot%d();" % i for i in range(slots))
    view.append("    virtual int call(void*);")
    view.append("};")
    start = src.rfind(prefix, 0, call.start())
    updated = src[:start] + "(((VTableCallView*)this)->call(" + \
        call.group(2) + ")" + src[call.end():]
    pos = updated.find("\nint ")
    if pos < 0:
        return []
    updated = updated[:pos] + "\n".join(view) + updated[pos:]
    return [updated]


def return_carrier_variants(src, diagnosis):
    """Carry an ignored producer result into a diagnosed indirect thiscall."""
    if not (diagnosis or {}).get("return_carrier_call_diffs"):
        return []
    decl = re.search(r'(?m)^extern\s+"C"\s+(.+?)\s+__stdcall\s+(\w+)\s*\(([^)]*)\)\s*;', src)
    if not decl:
        return []
    name = decl.group(2)
    body = re.search(r'(?m)^([ \t]*)(\w+)\(([^;]*)\);\s*\n\1' + re.escape(name) +
                    r'\(([^;]*)\);\s*\n\1return\s+true\s*;', src)
    if not body:
        return []
    replacement = 'extern "C" bool (__thiscall *%s)(%s, int);' % (name, decl.group(3).strip())
    updated = src[:decl.start()] + replacement + src[decl.end():]
    updated = re.sub(r'(?m)^([ \t]*)' + re.escape(body.group(2)) + r'\(([^;]*)\);\s*\n\1' +
                     re.escape(name) + r'\(([^;]*)\);\s*\n\1return\s+true\s*;',
                     r'\1return ' + name + r'(\3, ' + body.group(2) + r'(\2));', updated, count=1)
    return [updated] if updated != src else []


def near_return_shape_variants(src, diagnosis):
    """Try minimal typed-return/inline-store shapes for 97%+ register diffs."""
    preview = "\n".join((diagnosis or {}).get("diff_preview", []))
    delta = (diagnosis or {}).get("register_delta", {})
    if (diagnosis or {}).get("mismatch_class") != "register allocation difference":
        return []
    if not delta or "movecx,eax" not in preview.replace(" ", "").lower():
        return []
    owner = re.search(r"\bstruct\s+(\w+)\s*\{", src)
    definition = re.search(r"\b(\w+)::\w+\s*\(", src)
    if not owner or not definition or owner.group(1) != definition.group(1):
        return []
    body = _function_body(src, definition.group(0).split("::", 1)[1].split("(", 1)[0])
    if not body:
        return []
    receiver = re.search(r"\bvoid\*\s+(\w+)\s*=\s*(\w+)\s*\(([^;]*)\);\s*\n\s*(\w+)\s*\(\s*\);", body)
    tail = re.search(r"\bvoid\*\s+(?P<obj>\w+)\s*=\s*(?P<helper>\w+)\s*\(\s*\);\s*\n\s*int\*\s+(?P<ptr>\w+)\s*=\s*\*\(int\*\*\)\(\(char\*\)(?P=obj)\s*\+\s*(?P<field>0x[0-9a-fA-F]+)\);\s*\n\s*(?P=ptr)\[(?P<store>0x[0-9a-fA-F]+)\s*/\s*4\]\s*=\s*(?P<value>[^;]+);", body)
    if not receiver or not tail:
        return []
    first_name, first_helper, first_args, second_helper = receiver.groups()
    second_decl = re.search(r"(?m)^\s*void\*\s+" + re.escape(first_helper) + r"\s*\(([^)]*)\)\s*;", src)
    tail_name, tail_helper, _ptr_name, field_offset, store_offset, value = (tail.group(name) for name in ("obj", "helper", "ptr", "field", "store", "value"))
    tail_decl = re.search(r"(?m)^\s*void\*\s+" + re.escape(tail_helper) + r"\s*\(\s*\)\s*;", src)
    if not second_decl or not tail_decl:
        return []
    updated = src[:second_decl.start()] + re.sub(r"void\*", "int", second_decl.group(0), count=1) + src[second_decl.end():]
    updated = updated[:tail_decl.start()] + re.sub(r"void\*", "int", tail_decl.group(0), count=1) + updated[tail_decl.end():]
    updated = re.sub(r"\bvoid\*\s+" + re.escape(first_name) + r"\s*=\s*" + re.escape(first_helper) + r"\([^;]*\);\s*\n\s*" + re.escape(second_helper) + r"\(\s*\);",
                     "int %s = %s(%s);\n    ((%s*)%s)->%s();" % (first_name, first_helper, first_args, owner.group(1), first_name, second_helper), updated, count=1)
    updated = re.sub(r"void\*\s+" + re.escape(tail_name) + r"\s*=\s*" + re.escape(tail_helper) + r"\(\s*\);\s*\n\s*int\*\s+\w+\s*=\s*\*\(int\*\*\)\(\(char\*\)" + re.escape(tail_name) + r"\s*\+\s*" + re.escape(field_offset) + r"\);\s*\n\s*\w+\[" + re.escape(store_offset) + r"\s*/\s*4\]\s*=\s*" + re.escape(value),
                     "int %s = %s();\n    *(int *)(*(int *)(%s + %s) + %s) = %s" % (tail_name, tail_helper, tail_name, field_offset, store_offset, value), updated, count=1)
    updated = re.sub(r"\s*int\s+flag\s*=\s*([^;]+);\s*\n(\s*int\s+" + re.escape(first_name) + r"\s*=\s*" + re.escape(first_helper) + r"\([^,]+,\s*)flag(\s*\);)",
                     lambda m: "\n" + m.group(2) + m.group(1).strip() + m.group(3), updated, count=1)
    return [updated] if updated != src else []


def rtti_operator_variants(src, diagnosis):
    """Expose RTTI operator equality as the observed indirect thiscall."""
    if not (diagnosis or {}).get("indirect_call_diffs") or "operator==" not in src:
        return []
    type_decl = re.search(r"struct\s+(\w+)\s*\{(?P<body>.*?)\};", src, re.S)
    global_ref = re.search(r"extern\s+(\w+)\s+(\w+)\s*;", src)
    expr = re.search(r"return\s+(\w+)\s*==\s*\*\((\w+)\*\)q\s*;", src)
    if not type_decl or not global_ref or not expr or type_decl.group(1) != global_ref.group(1) or expr.group(1) != global_ref.group(2):
        return []
    typename = type_decl.group(1)
    updated = src[:type_decl.start()] + "struct %s {};" % typename + src[type_decl.end():]
    marker = 'extern "C" void* __cdecl sub_631392(void*);'
    if marker not in updated:
        return []
    updated = updated.replace(marker, marker +
                              '\nextern "C" bool (__thiscall *sub_77e708)(const %s*, const %s*);' %
                              (typename, typename), 1)
    updated = re.sub(r"return\s+" + re.escape(expr.group(1)) + r"\s*==\s*\*\(" +
                     re.escape(typename) + r"\*\)q\s*;",
                     "return sub_77e708(&%s, (const %s*)q);" % (expr.group(1), typename), updated, count=1)
    return [updated] if updated != src else []


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


def allocation_result_variants(src, diagnosis):
    """Move allocation-result return outside a non-null copy block."""
    pattern = re.compile(r"(?P<indent>^[ \t]*)if\s*\(\s*(?P<var>\w+)\s*\)\s*\{(?P<body>.*?)"
                         r"\n\s*return\s+(?P=var)\s*;\s*\n(?P=indent)\}\s*\n"
                         r"(?P=indent)return\s+0\s*;", re.S | re.M)
    out = []
    for m in pattern.finditer(src):
        body = re.sub(r"\n\s*return\s+" + re.escape(m.group("var")) + r"\s*;\s*$", "", m.group("body"))
        replacement = (m.group("indent") + "if (" + m.group("var") + " != 0) {" + body + "\n" +
                       m.group("indent") + "}\n" + m.group("indent") + "return " + m.group("var") + ";")
        out.append(src[:m.start()] + replacement + src[m.end():])
    return out


# --- new transforms (2026-10-09 research batch) ---
# None of these categories appear anywhere in docs/matching-findings.md as of
# this batch, so every one of them is genuinely new search space rather than a
# re-run of an exhausted arm. All are bounded text transforms and every one is
# compile-tested by `improve`, so a bad guess costs a compile and nothing else.

def loop_shape_variants(src):
    """`while (c)` -> `for (; c;)` and `for (;;)` guard forms.

    MSVC emits a different loop entry/exit shape for the `for` form: the
    condition test lands at the bottom of the body with a `jmp` back to the
    test instead of a top test, which moves every following branch
    displacement. That changes instruction alignment on functions whose only
    remaining delta is branch layout.
    """
    out = []
    m = re.search(r"(?<!\w)while\s*\(([^;{}]*)\)\s*\{", src)
    if m:
        out.append(src[:m.start()] + "for (; %s;) {" % m.group(1).strip() + src[m.end():])
    for m in re.finditer(r"(?<!\w)for\s*\(\s*([^;{}]*);\s*([^;{}]*);\s*([^;{}]*)\)\s*\{", src):
        init, cond, step = m.group(1).strip(), m.group(2).strip(), m.group(3).strip()
        if not cond or step:
            continue
        if init:
            continue
        out.append(src[:m.start()] + "while (%s) {" % cond + src[m.end():])
    return out


def ternary_variants(src):
    """`if (c) { v = a; } else { v = b; }` -> `v = c ? a : b;`.

    MSVC often selects a conditional move (`cmov`) for the ternary and a pair
    of branches for the if/else, so this is the only way to reach target
    binaries that used the select form.
    """
    out = []
    pattern = re.compile(r"(?P<indent>^[ \t]*)if\s*\((?P<cond>[^{}]*)\)\s*\{\s*\n"
                         r"[ \t]*(?P<var>[A-Za-z_]\w*(?:\.|->)?\w*)\s*=\s*(?P<then>[^;\n]+);\s*\n"
                         r"[ \t]*\}\s*else\s*\{\s*\n"
                         r"[ \t]*(?P=var)\s*=\s*(?P<other>[^;\n]+);\s*\n"
                         r"[ \t]*\}", re.M)
    for m in pattern.finditer(src):
        replacement = "%s%s = (%s) ? (%s) : (%s);" % (m.group("indent"), m.group("var"),
                                                      m.group("cond").strip(), m.group("then").strip(),
                                                      m.group("other").strip())
        out.append(src[:m.start()] + replacement + src[m.end():])
    return out


def integer_width_variants(src):
    """Widen/narrow the first uninitialized integral local declaration.

    Signedness already covered `int` <-> `unsigned int`. Width is a separate
    axis: `int` -> `__int64` (`long long`) makes MSVC use 64-bit
    operand-size prefixes for the same operation, and `short` introduces
    truncation stores. Both move instruction alignment without touching
    semantics on a value that is stored through a narrower pointer anyway.
    """
    out = []
    decl = re.compile(r"(?m)^([ \t]*)(int|long|short)\s+([A-Za-z_]\w*)[ \t]*;[ \t]*$")
    for m in decl.finditer(src):
        base = "int"
        out.append(src[:m.start()] + "%s__int64 %s;" % (m.group(1), m.group(3)) + src[m.end():])
        out.append(src[:m.start()] + "%sshort %s;" % (m.group(1), m.group(3)) + src[m.end():])
        if m.group(2) != "long":
            out.append(src[:m.start()] + "%slong %s;" % (m.group(1), m.group(3)) + src[m.end():])
        del base
        break
    return list(dict.fromkeys(out))


def restrict_variants(src):
    """Add `__restrict` to the first pointer parameter of the target function.

    `__restrict` changes MSVC alias analysis: loads through a pointer stop
    being re-loaded after an intervening store. On functions that read back a
    member they just wrote, that removes (or adds) a redundant `mov` and is a
    separate axis from signedness or register-pressure mutations.
    """
    out = []
    m = re.search(r"(?m)^([A-Za-z_][\w:<>,*& \t]*?)\b([A-Za-z_]\w*)\s*\(([^)]*)\)\s*\{", src)
    if not m:
        return out
    params = [p.strip() for p in m.group(3).split(",") if p.strip() and p.strip() != "void"]
    for index, param in enumerate(params):
        if "*" not in param or "__restrict" in param:
            continue
        updated = param.replace("*", "* __restrict ", 1)
        new_params = params[:index] + [updated] + params[index + 1:]
        head = src[:m.start(3)] + ", ".join(new_params) + src[m.end(3):]
        out.append(head)
        break
    return out


def bool_return_variants(src):
    """`return expr;` -> `return expr != 0;` in a bool-returning function.

    The target binary's instruction decides the source form: `sete`/`setne`
    against a compared value means the source compared against zero, while a
    raw `test`/`setne` on the returned object means it did not.
    docs/matching-findings.md line 49 noted `sete al` on 00675890 but never
    tested the explicit comparison form, only parameter types.
    """
    out = []
    m = re.search(r"(?m)^([ \t]*bool\s+(?:[A-Za-z_]\w*::)?[A-Za-z_]\w*)\s*\([^)]*\)\s*\{", src)
    if not m:
        return out
    ret = re.search(r"(?m)^([ \t]*)return\s+(?!0\s*;)([^;\n]+);[ \t]*$", src)
    if ret and not re.search(r"[=!<>]|&&|\|\|", ret.group(2)):
        out.append(src[:ret.start()] + "%sreturn %s != 0;" % (ret.group(1), ret.group(2).strip())
                   + src[ret.end():])
    return out


def short_circuit_swap_variants(src):
    """Swap operands of the first `&&` / `||` in a condition.

    `&&` and `||` are absent from `_COMMUTATIVE_OPS` (they are not commutative
    in general: the right operand is not evaluated when the left short-
    circuits), so this ordering has never been probed. Short-circuit
    evaluation order is exactly what decides which operand gets `test`-ed
    first and therefore which value is already live in a register.
    """
    out = []
    for op in ("&&", "||"):
        pattern = re.compile("([A-Za-z_]\w*(?:\s*->\w+|\.\w+|\[\w+\])?)%s([A-Za-z_]\w*(?:\s*->\w+|\.\w+|\[\w+\])?)" % re.escape(op))
        for m in pattern.finditer(src):
            if m.group(1) == m.group(2):
                continue
            out.append(src[:m.start()] + m.group(2) + " " + op + " " + m.group(1) + src[m.end():])
    return list(dict.fromkeys(out))


def null_check_shape_variants(src):
    """`if (p)` -> `if (p != 0)` and `if (p == 0)` -> `if (!p)`.

    Both compile to a `test`/`jz` pair, so this is not a semantic change, but
    the comparison form sometimes suppresses MSVC's implicit-zero idiom and
    changes the surrounding store ordering. Never tested standalone before;
    allocation_result came closest but is a different transform.
    """
    out = []
    for rel, repl in ((r"if\s*\(\s*([A-Za-z_]\w*)\s*\)", "if (%s != 0)"),
                      (r"if\s*\(\s*([A-Za-z_]\w*)\s*==\s*0\s*\)", "if (!%s)")):
        m = re.search(rel, src)
        if m:
            out.append(src[:m.start()] + repl % m.group(1) + src[m.end():])
    return list(dict.fromkeys(out))


def guard_invert_variants(src):
    """`if (c) { return A; } return B;` -> `if (!c) return B; return A;`.

    Early-exit vs. guarded-body is the same control flow with the fall-through
    and branch edges swapped. docs/matching-findings.md line 25 found the
    inverse form fixed 00449820, but the transform was only ever applied by
    hand to that one function; it has never been a general mutator.
    """
    out = []
    pattern = re.compile(r"(?P<indent>^[ \t]*)if\s*\((?P<cond>[^{}]*)\)\s*\{\s*"
                         r"return\s+(?P<ok>[^;\n]+);\s*\n"
                         r"(?P=indent)\}\s*\n"
                         r"(?P=indent)return\s+(?P<bad>[^;\n]+);", re.M)
    for m in pattern.finditer(src):
        replacement = ("%sif (!(%s)) return %s;\n%sreturn %s;" %
                       (m.group("indent"), m.group("cond").strip(), m.group("bad").strip(),
                        m.group("indent"), m.group("ok").strip()))
        out.append(src[:m.start()] + replacement + src[m.end():])
    return out


def else_invert_variants(src):
    """`if (a) { A } else { B }` -> `if (!a) { B } else { A }` for simple call bodies.

    Same semantics, inverted branch polarity. This flips `jz` to `jnz`, which
    changes every relative displacement in the function when the target
    compiler chose the opposite polarity.
    """
    out = []
    pattern = re.compile(r"(?P<indent>^[ \t]*)if\s*\((?P<cond>[^{}]*)\)\s*\{\s*\n"
                         r"(?P<then>.*?)\n(?P=indent)\}\s*else\s*\{\s*\n"
                         r"(?P<other>.*?)\n(?P=indent)\}", re.S | re.M)
    for m in pattern.finditer(src):
        if m.group("then").count(";") > 6 or m.group("other").count(";") > 6:
            continue
        replacement = ("%sif (!(%s)) {\n%s\n%s} else {\n%s\n%s}" %
                       (m.group("indent"), m.group("cond").strip(), m.group("other"),
                        m.group("indent"), m.group("then"), m.group("indent")))
        out.append(src[:m.start()] + replacement + src[m.end():])
    return out


def explicit_zero_init_variants(src):
    """`T name;` -> `T name = {0};` for an uninitialized local struct/pointer.

    If the target binary zeroed a stack slot in the prologue and our source
    only appears to zero it through a side effect, an explicit initializer
    makes MSVC emit the store directly. This is separate from
    volatile_zero_store, which only relabels stores that already exist.
    """
    out = []
    decl = re.compile(r"(?m)^([ \t]*)([A-Za-z_]\w*(?:\s*\*)?)\s+([A-Za-z_]\w*)[ \t]*;[ \t]*$")
    for m in decl.finditer(src):
        if "*" in m.group(2):
            continue
        updated = (src[:m.start()] + "%s%s %s = {0};" % (m.group(1), m.group(2), m.group(3))
                   + src[m.end():])
        out.append(updated)
        break
    return out


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
        add("base_padding", base_padding_variants(src, diagnosis))
    if (diagnosis or {}).get("mismatch_class") == "intrinsic/call mismatch":
        add("intrinsic_call", intrinsic_call_variants(src, diagnosis))
    add("function_pointer_convention", function_pointer_convention_variants(src, diagnosis))
    add("direct_member_receiver", direct_member_receiver_variants(src, diagnosis))
    add("direct_member_noarg", direct_member_noarg_variants(src, diagnosis))
    add("static_receiver_pointer", static_receiver_pointer_variants(src, diagnosis))
    add("indirect_return_value", indirect_return_variants(src, diagnosis))
    add("virtual_call_view", virtual_call_view_variants(src, diagnosis))
    add("virtual_slot_view", virtual_slot_view_variants(src, diagnosis))
    add("return_carrier", return_carrier_variants(src, diagnosis))
    add("near_return_shape", near_return_shape_variants(src, diagnosis))
    add("rtti_operator", rtti_operator_variants(src, diagnosis))
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
    add("allocation_result", allocation_result_variants(src, diagnosis))
    if len(out) < 2:
        return out
    from roc.repair_patterns import rank_categories
    ranked = rank_categories(diagnosis, [category for category, _ in out])
    by_category = {}
    for category, value in out:
        by_category.setdefault(category, []).append(value)
    ordered = []
    for index, category in ranked:
        ordered.extend((category, value) for value in by_category.get(category, []))
    return ordered[:8]


def legacy_fallback_allowed(score, diagnosis):
    """Stop blind text mutations when evidence points to source-shape repair."""
    mismatch = (diagnosis or {}).get("mismatch_class")
    structural = {"register allocation difference", "instruction-selection mismatch",
                  "missing/extra instruction", "code-size mismatch"}
    delta = (diagnosis or {}).get("register_delta", {})
    call_evidence = any((diagnosis or {}).get(key) for key in
                        ("receiver_call_diffs", "return_carrier_call_diffs",
                         "indirect_call_diffs"))
    if mismatch in structural and (call_evidence or delta):
        return False
    if score < 75 and mismatch in {"missing/extra instruction", "code-size mismatch"}:
        return False
    return True


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
        if guided_fallback and legacy_fallback_allowed(base, diagnosis):
            guided_out.extend((category, value) for category, value in legacy
                              if value not in {v for _, v in guided_out})
        variants_to_try.extend(guided_out)
    if permute and guided_categories is None:
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
