"""Auto-match trivial functions from their assembly shape.

Getters, setters, constant returns, empty bodies... are recognised by pattern,
turned into C++ candidates, and compiled hundreds at a time in one cl.exe run.
Only byte-identical results are kept, so a wrong guess costs nothing.
"""
import re
from pathlib import Path

from roc import match

ROOT = Path(__file__).resolve().parent.parent
OFF = r"(?: \+ (0x[0-9a-f]+|\d+))?"
MEM_TYPES = {"dword": "int", "word": "short", "byte": "char"}


def off(text):
    return int(text, 0) if text else 0


def member_struct(name, fields):
    """struct with fields at fixed offsets: fields = [(offset, type, fieldname)]"""
    body, pos = [], 0
    for i, (o, t, f) in enumerate(sorted(fields)):
        if o < pos:
            return None
        if o > pos:
            body.append("    char pad%d[%d];" % (i, o - pos))
        body.append("    %s %s;" % (t, f))
        pos = o + {"int": 4, "short": 2, "char": 1, "unsigned char": 1, "unsigned short": 2}[t]
    return body


def returns(body):
    """[(return type, expression, fields, needs_this)] for a body (asm before ret)."""
    out = []
    b = body
    if b == "":
        out.append(("void", None, [], False))
    consts = {"xor eax, eax": ["0"], "mov eax, 1": ["1"], "or eax, 0xffffffff": ["-1"],
              "mov al, 1": [None], "xor al, al": [None]}
    if b in ("mov al, 1", "xor al, al"):
        out.append(("bool", "true" if b == "mov al, 1" else "false", [], False))
    elif b in consts:
        out.append(("int", consts[b][0], [], False))
    m = re.fullmatch(r"mov eax, (0x[0-9a-f]+|\d+)", b)
    if m:
        out.append(("unsigned int", "%su" % m.group(1), [], False))
    if b == "mov eax, sym":
        out.append(("char*", "&G", [], False))
    if b == "mov eax, ecx":
        out.append(("void*", "this", [], True))
    m = re.fullmatch(r"(mov|movzx|movsx) (eax|al|ax), (dword|word|byte) ptr \[ecx%s\]" % OFF, b)
    if m:
        t = MEM_TYPES[m.group(3)]
        if m.group(1) == "movzx":
            t = "unsigned " + t
        rt = "bool" if t == "char" and m.group(2) == "al" else t
        out.append((rt if rt != "char" else "char", "m_x", [(off(m.group(4)), t, "m_x")], True))
        if rt == "bool":
            out.append(("char", "m_x", [(off(m.group(4)), t, "m_x")], True))
    m = re.fullmatch(r"lea eax, \[ecx%s\]" % OFF, b)
    if m:
        out.append(("int*", "&m_x", [(off(m.group(1)), "int", "m_x")], True))
    m = re.fullmatch(r"mov eax, dword ptr \[ecx%s\]; imul eax, eax, (0x[0-9a-f]+|\d+)" % OFF, b)
    if m:
        out.append(("int", "m_x * %s" % m.group(2), [(off(m.group(1)), "int", "m_x")], True))
    m = re.fullmatch(r"mov eax, dword ptr \[ecx%s\]; add eax, (0x[0-9a-f]+|\d+)" % OFF, b)
    if m:
        out.append(("int", "m_x + %s" % m.group(2), [(off(m.group(1)), "int", "m_x")], True))
    m = re.fullmatch(r"mov eax, dword ptr \[ecx%s\]; sub eax, (0x[0-9a-f]+|\d+)" % OFF, b)
    if m:
        out.append(("int", "m_x - %s" % m.group(2), [(off(m.group(1)), "int", "m_x")], True))
    m = re.fullmatch(r"mov eax, dword ptr \[ecx%s\]; xor eax, (0x[0-9a-f]+|\d+)" % OFF, b)
    if m:
        out.append(("int", "m_x ^ %s" % m.group(2), [(off(m.group(1)), "int", "m_x")], True))
    m = re.fullmatch(r"mov eax, dword ptr \[ecx%s\]; neg eax" % OFF, b)
    if m:
        out.append(("int", "-m_x", [(off(m.group(1)), "int", "m_x")], True))
    m = re.fullmatch(r"cmp dword ptr \[ecx%s\], 0; setne al; movzx eax, al" % OFF, b)
    if m:
        out.append(("bool", "m_x != 0", [(off(m.group(1)), "int", "m_x")], True))
    return out


ZERO_FIELDS = re.compile(r"mov (dword|byte|word) ptr \[eax \+ (0x[0-9a-f]+|\d+)\], (ecx|cl) ; ")
# Members can also be initialised to a constant: `mov dword ptr [eax + 4], 0x67452301`
# and friends is a common init table, so capture immediates rather than skipping them.
CONST_FIELDS = re.compile(
    r"mov (dword|byte|word) ptr \[eax \+ (0x[0-9a-f]+|\d+)\], "
    r"(0x[0-9a-f]+|\d+) ; ")
WIDTH = {"dword": ("int", 4), "byte": ("char", 1), "word": ("short", 2)}


def _zero_ctor(tail):
    """C++ candidates for `mov eax, ecx ; xor ecx, ecx ; vptr ; zero... ; ret`.

    A pointer member at offset 0 initialised from a global, followed by members cleared
    to zero. Offsets come straight from the asm; overlapping fields cannot be a struct
    and are skipped rather than guessed at.

    Several orderings are emitted because MSVC's store order follows the source order and
    the exes are not consistent about it: a chained `z0 = z1 = z2 = 0` stores descending,
    separate statements store ascending, and real functions mix the two. Rather than
    derive the rule, offer every plausible ordering and let the byte-exact check pick -
    a wrong one costs nothing because only a 100% result is ever kept."""
    fields = [(off(o), t, None) for t, o, _r in ZERO_FIELDS.findall(tail)]
    fields += [(off(o), t, c) for t, o, c in CONST_FIELDS.findall(tail)]
    if not fields:
        return []
    pos, body, names = 4, [], []  # offset 0 is the pointer member
    for i, (o, ty, const) in enumerate(sorted(fields)):
        ctype, width = WIDTH[ty]
        if o < pos:
            return []                      # overlapping: not expressible as members
        if o > pos:
            body.append("    char pad%d[%d];" % (i, o - pos))
        body.append("    %s z%d;" % (ctype, i))
        names.append(("z%d" % i, "0" if const is None else const))
        pos = o + width
    if not names:
        return []
    decl = "".join(b + "\n" for b in body)
    head = "extern char G;\nstruct S_NAME\n{\n    void* p0;\n%s    S_NAME();\n};\n" % decl

    def unit(statements):
        return head + "S_NAME::S_NAME()\n{\n%s\n}\n" % "\n".join("    " + s for s in statements)

    zeros = [(n, v) for n, v in names if v == "0"]
    constants = [(n, v) for n, v in names if v != "0"]
    out = []
    if constants:
        # Constants cannot take part in a zero chain, so only the two natural orders.
        for order in (names, list(reversed(names))):
            stmts = ["p0 = (void*)&G;"] + ["%s = %s;" % (n, v) for n, v in order]
            out.append(unit(stmts))
        return out
    if not zeros:
        return out
    flat = [n for n, _v in zeros]
    # pointer member first, then the zeros in a range of orderings
    for k in range(len(flat) + 1):
        stmts = ["p0 = (void*)&G;"] + ["%s = 0;" % z for z in flat[:k]]
        if flat[k:]:
            stmts.append("%s = 0;" % " = ".join(flat[k:]))
        out.append(unit(stmts))
    # and the pointer member written last
    for k in range(len(flat) + 1):
        stmts = ["%s = 0;" % z for z in flat[:k]]
        if flat[k:]:
            stmts.append("%s = 0;" % " = ".join(flat[k:]))
        stmts.append("p0 = (void*)&G;")
        out.append(unit(stmts))
    return out


def shape_candidates(full):
    """Whole-function shapes: tail calls, global-object calls, destructors, wrappers.
    full = asm lines joined with ' ; ' (relocated operands shown as sym)."""
    out = []
    o = r"(?: \+ (0x[0-9a-f]+|\d+))?"
    if full == "jmp sym":
        out.append("extern void G1_NAME();\nvoid NAME()\n{\n    G1_NAME();\n}\n")
        out.append("struct S_NAME { void f(); void g(); };\nvoid S_NAME::f()\n{\n    g();\n}\n")
    # Imported function called with one pointer argument, result stored to a global.
    # Present in all six clients; the shape report puts it at ~240 functions.
    if full == "push sym ; call sym ; add esp, 4 ; mov dword ptr [sym], eax ; ret":
        out.append("extern char G3_OBJ;\nextern int* G1_VALUE;\nextern int __cdecl G2_NAME(void*);\n"
                   "void NAME()\n{\n    G1_VALUE = (int*)G2_NAME(&G3_OBJ);\n}\n")
        out.append("extern char G3_OBJ;\nextern void* G1_VALUE;\nextern void* __cdecl G2_NAME(void*);\n"
                   "void NAME()\n{\n    G1_VALUE = G2_NAME(&G3_OBJ);\n}\n")
    if full == "jmp dword ptr [sym]":
        # Import thunk: the jump table slot for a dllimport function.
        out.append("extern void __cdecl G1_NAME();\nvoid NAME()\n{\n    G1_NAME();\n}\n")
        out.append("struct S_NAME { void m(); };\nextern S_NAME* G1_OBJ;\nvoid S_NAME::m()\n{\n}\n")
    # Constructor: a pointer member at offset 0 set to a global, then every following
    # member zeroed. 306 unmatched functions across all six clients. There is no vtable
    # (the class has no virtuals) - that is why MSVC parks `this` in eax first.
    #
    # The zeroing must be a *chained* assignment: `m1 = m2 = m3 = m4 = 0` is what makes
    # MSVC emit the stores in descending offset order, which is what the exes contain.
    # Written as separate statements it stores ascending and scores 78% instead of 100.
    m = re.fullmatch(r"mov eax, ecx ; xor ecx, ecx ; mov dword ptr \[eax\], sym ; "
                     r"((?:mov (dword|byte|word) ptr \[eax \+ (0x[0-9a-f]+|\d+)\], (?:ecx|cl) ; )+)ret",
                     full)
    if m:
        out.extend(_zero_ctor(m.group(1)))
    # Known but not yet matched, kept here so the shapes are not rediscovered blind:
    #   mov ecx, sym ; call sym ; push sym ; call sym ; pop ecx ; ret   (402 functions,
    #     all six clients) - the two calls disagree on calling convention or return use;
    #     best attempt reached 80%.
    #   mov eax, ecx ; xor ecx, ecx ; mov dword ptr [eax], sym ;
    #     mov dword ptr [eax + N], ecx ... ; ret   (306 functions) - destructor that
    #     installs a vptr then zeroes its own fields. The vptr occupies offset 0, so
    #     members must be declared four bytes lower than the asm shows, and MSVC must be
    #     pushed into keeping `this` in eax with stores descending; the best source form
    #     found reached 68%.
    #   mov dword ptr [ecx], sym ; mov dword ptr [ecx + sym], sym ... ; jmp sym   (359
    #     functions) - the member offsets are relocated addresses, not constants, so they
    #     cannot be written as fixed struct members.
    if full in ("mov ecx, sym ; jmp sym", "mov ecx, sym ; jmp dword ptr [sym]"):
        imp = "__declspec(dllimport) " if "[sym]" in full else ""
        out.append("struct %sT_NAME { void m(); };\nextern T_NAME G1_NAME;\nvoid NAME()\n{\n    G1_NAME.m();\n}\n" % imp)
    if full == "mov dword ptr [ecx], sym ; ret":
        out.append("struct S_NAME { virtual ~S_NAME(); };\nS_NAME::~S_NAME()\n{\n}\n")
    if full in ("mov dword ptr [ecx], sym ; jmp sym", "mov dword ptr [ecx], sym ; jmp dword ptr [sym]"):
        imp = "__declspec(dllimport) " if "[sym]" in full else ""
        out.append("struct %sB_NAME { virtual ~B_NAME(); };\nstruct S_NAME : B_NAME { ~S_NAME(); };\n"
                   "S_NAME::~S_NAME()\n{\n}\n" % imp)
        out.append("struct %sM_NAME { ~M_NAME(); };\nstruct S_NAME { virtual ~S_NAME(); M_NAME m; };\n"
                   "S_NAME::~S_NAME()\n{\n}\n" % imp)
    if full == "mov dword ptr [sym], sym ; ret":
        out.append("extern void* G1_NAME;\nextern char G2_NAME;\nvoid NAME()\n{\n    G1_NAME = &G2_NAME;\n}\n")
    m = re.fullmatch(r"fld (dword|qword) ptr \[ecx%s\] ; ret" % o, full)
    if m:
        t = "float" if m.group(1) == "dword" else "double"
        pad = off(m.group(2))
        out.append("struct S_NAME {\n%s    %s m_x;\n    %s f();\n};\n%s S_NAME::f()\n{\n    return m_x;\n}\n"
                   % ("    char pad[%d];\n" % pad if pad else "", t, t, t))
    m = re.fullmatch(r"mov ecx, dword ptr \[ecx%s\] ; jmp sym" % o, full)
    if m:
        pad = off(m.group(1))
        out.append("struct P_NAME { void g(); };\nstruct S_NAME {\n%s    P_NAME* m_p;\n    void f();\n};\n"
                   "void S_NAME::f()\n{\n    m_p->g();\n}\n" % ("    char pad[%d];\n" % pad if pad else ""))
    m = re.fullmatch(r"mov eax, dword ptr \[ecx%s\] ; mov eax, dword ptr \[eax%s\] ; ret" % (o, o), full)
    if m:
        p1, p2 = off(m.group(1)), off(m.group(2))
        out.append("struct I_NAME {\n%s    int m_x;\n};\nstruct S_NAME {\n%s    I_NAME* m_p;\n    int f();\n};\n"
                   "int S_NAME::f()\n{\n    return m_p->m_x;\n}\n"
                   % ("    char pad[%d];\n" % p2 if p2 else "", "    char pad[%d];\n" % p1 if p1 else ""))
    if full == "call sym ; push eax ; call sym ; ret":
        out.append("extern int G1_NAME();\nextern int __stdcall G2_NAME(int);\nint NAME()\n{\n    return G2_NAME(G1_NAME());\n}\n")
        out.append("extern int G1_NAME();\nextern void __stdcall G2_NAME(int);\nvoid NAME()\n{\n    G2_NAME(G1_NAME());\n}\n")
    if full in ("push sym ; call sym ; pop ecx ; ret",):
        out.append("extern char G2_NAME;\nextern void G1_NAME(void*);\nvoid NAME()\n{\n    G1_NAME(&G2_NAME);\n}\n")
        out.append("extern char G2_NAME;\nextern int G1_NAME(void*);\nint NAME()\n{\n    return G1_NAME(&G2_NAME);\n}\n")
    # global loaded, passed to a cdecl call, then a global assigned: the plumbing that
    # most of the registration/init functions of this era are made of.
    if full == "mov eax, dword ptr [sym] ; push eax ; call sym ; add esp, 4 ; mov dword ptr [sym], sym ; ret":
        out.append("extern int G1_VALUE;\nextern int G2_VALUE;\nextern char G3_OBJ;\n"
                   "extern int __cdecl G4_NAME(int);\nvoid NAME()\n{\n"
                   "    G4_NAME(G1_VALUE);\n    G2_VALUE = (int)&G3_OBJ;\n}\n")
    if full == "push sym ; call sym ; add esp, 4 ; jmp sym":
        out.append("extern char G2_OBJ;\nextern int __cdecl G1_NAME(void*);\nextern void G3_NAME();\n"
                   "void NAME()\n{\n    G1_NAME(&G2_OBJ);\n    G3_NAME();\n}\n")
    if full == "mov eax, dword ptr [sym] ; push eax ; call sym ; add esp, 4 ; ret":
        out.append("extern int G1_VALUE;\nextern int __cdecl G2_NAME(int);\nvoid NAME()\n{\n"
                   "    G2_NAME(G1_VALUE);\n}\n")
        out.append("extern int G1_VALUE;\nextern void __cdecl G2_NAME(int);\nvoid NAME()\n{\n"
                   "    G2_NAME(G1_VALUE);\n}\n")
    if full == "push sym ; call sym ; add esp, 4 ; pop edi ; ret":
        out.append("extern char G2_OBJ;\nextern int __cdecl G1_NAME(void*);\nvoid NAME()\n{\n"
                   "    G1_NAME(&G2_OBJ);\n}\n")
    if full == "mov dword ptr [sym], eax ; ret":
        out.append("extern int G1_VALUE;\nvoid NAME(int a1)\n{\n    G1_VALUE = a1;\n}\n")
        out.append("extern int* G1_VALUE;\nvoid NAME(int* a1)\n{\n    G1_VALUE = a1;\n}\n")
    if full == "push esi ; mov esi, ecx ; call sym ; mov ecx, esi ; pop esi ; jmp sym":
        out.append("struct S_NAME { void f(); void a(); void b(); };\nvoid S_NAME::f()\n{\n    a();\n    b();\n}\n")
    m = re.fullmatch(r"mov dword ptr \[ecx\], sym ; mov ecx, dword ptr \[ecx \+ (0x[0-9a-f]+|\d+)\] ; test ecx, ecx ; "
                     r"je 0x[0-9a-f]+ ; push ecx ; call sym ; pop ecx ; ret", full)
    if m:
        pad = off(m.group(1)) - 4
        out.append("extern \"C\" void __cdecl G1_NAME(void*);\nstruct S_NAME {\n    virtual ~S_NAME();\n%s    void* m_p;\n};\n"
                   "S_NAME::~S_NAME()\n{\n    if (m_p)\n        G1_NAME(m_p);\n}\n" % ("    char pad[%d];\n" % pad if pad else ""))
    return out


def candidates(lines):
    """C++ snippets (with NAME placeholder) that might compile to these asm lines."""
    if not lines:
        return []
    shapes = shape_candidates(" ; ".join(l.strip() for l in lines))
    if shapes:
        return shapes
    m = re.fullmatch(r"ret (0x[0-9a-f]+|\d+)?\s*", lines[-1])
    if not m:
        return []
    argbytes = off(m.group(1))
    if argbytes % 4:
        return []
    nargs = argbytes // 4
    body = "; ".join(l.strip() for l in lines[:-1])
    params = ", ".join("int a%d" % i for i in range(1, nargs + 1))
    out = []

    def emit(rtype, stmt, fields, member):
        fields_src = member_struct("S", fields) if fields else []
        if fields_src is None:
            return
        if member or nargs:
            out.append("struct S_NAME {\n%s\n    %s f(%s);\n};\n%s S_NAME::f(%s)\n{\n%s}\n" % (
                "\n".join(fields_src), rtype, params, rtype, params, stmt))
        if not member:
            conv = "__stdcall " if nargs else ""
            out.append("%s %sNAME(%s)\n{\n%s}\n" % (rtype, conv, params, stmt))

    for rtype, expr, fields, member in returns(body):
        stmt = "" if expr is None else "    return %s;\n" % expr
        emit(rtype, stmt, fields, member)
    # Setters: this->x = a1 / this->x = const
    m = re.fullmatch(r"mov (eax|ecx|edx), dword ptr \[esp \+ 4\]; mov (dword|word|byte) ptr \[ecx%s\], (eax|ax|al|edx|dx|dl)" % OFF, body)
    if m and nargs == 1:
        t = MEM_TYPES[m.group(2)]
        emit("void", "    m_x = (%s)a1;\n" % t, [(off(m.group(3)), t, "m_x")], True)
    m = re.fullmatch(r"mov (dword|word|byte) ptr \[ecx%s\], (0x[0-9a-f]+|\d+)" % OFF, body)
    if m:
        t = MEM_TYPES[m.group(1)]
        emit("void", "    m_x = (%s)%s;\n" % (t, m.group(3)), [(off(m.group(2)), t, "m_x")], True)
    m = re.fullmatch(r"mov eax, dword ptr \[esp \+ 4\]", body)
    if m and nargs >= 1:
        emit("int", "    return a1;\n", [], False)
    return out


def build_unit(snippets):
    """One .cpp with every candidate; names are unique per (addr, index).

    Each candidate goes in its own namespace. Templates routinely declare the same
    placeholder global with different types (`extern int G1_VALUE` in one, `extern
    char* G1_VALUE` in another), and in a single translation unit that is C2371
    redefinition - which silently killed whole 400-candidate chunks. Namespacing keeps
    them independent, and the generated code is unchanged because every global
    reference still produces the same relocation."""
    return "extern char G;\n\n" + "\n\n".join(
        "namespace n%s {\n%s\n}\n" % (tag, s.replace("NAME", tag)) for tag, s in snippets)


def solve(client, max_size=48, skip=(), log=print):
    """Try pattern candidates on every small open function. Returns {addr: source}."""
    rows = [r for r in match._functions(client).values()
            if r["kind"] == "code" and r["size"] <= max_size and r["addr"] not in skip]
    snippets, targets = [], {}
    for r in rows:
        code, relocs, _ = match.target(client, r["addr"])
        targets[r["addr"]] = (code, relocs)
        for i, c in enumerate(candidates(match.asm_lines(code, relocs))):
            snippets.append(("F%s_%d" % (r["addr"], i), c))
    log("%s: %d small functions, %d candidates" % (client, len(rows), len(snippets)))
    found = {}
    for start in range(0, len(snippets), 400):
        chunk = snippets[start:start + 400]
        try:
            obj = match.compile_text(client, build_unit(chunk))
        except match.CompileError as error:
            log("  chunk failed to compile, skipping: %s" % str(error).splitlines()[0])
            continue
        by_tag = dict(chunk)
        for name, code, relocs in match.coff_functions(obj):
            tag = re.search(r"F([0-9a-f]{8})_(\d+)", name)
            if not tag or tag.group(1) in found:
                continue
            addr = tag.group(1)
            if match.score(*targets[addr], code, relocs) == 100:
                src = by_tag[tag.group(0)].replace("NAME", "func_" + addr)
                if "&G" in src:
                    src = "extern char G;\n\n" + src
                found[addr] = src
    log("%s: auto-matched %d functions" % (client, len(found)))
    return found


def save(client, found):
    """Write matches into src/<client>/ (keeps existing hand-written files). Returns new count."""
    new = 0
    for addr, src in found.items():
        path = ROOT / "src" / client / ("%s.cpp" % addr)
        if path.exists():
            continue
        new += 1
        header = match.template(client, addr).split("\n\n")[0]
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(header + "\n// auto-matched from its assembly shape\n\n" + src)
        match.save_score(client, addr, 100)
    return new
