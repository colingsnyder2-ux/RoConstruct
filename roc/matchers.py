"""matchers"""
import csv
import functools
import hashlib
import json
import os
import re
import shutil
import struct
import subprocess
from bisect import bisect_left
from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path

from roc import clients, fingerprint, match, setup


# --- auto ---
# Auto-match trivial functions from their assembly shape.

ROOT = Path(__file__).resolve().parent.parent


HEX = re.compile(r"0x[0-9a-fA-F]+")


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


def family_propagate(asm, exemplar):
    """Rewrite address literals in verified sibling source, conservatively.

    Only same opcode shape should call this. Equal literal counts are required;
    compiler/byte scoring remains final authority. Empty result means unsafe.
    """
    source = (exemplar or "").strip()
    target = [m.group(0) for line in asm or () for m in HEX.finditer(line)]
    old = list(HEX.finditer(source))
    if not source or not target or len(old) != len(target):
        return None
    out, pos = [], 0
    for match_obj, value in zip(old, target):
        out.append(source[pos:match_obj.start()])
        out.append(value)
        pos = match_obj.end()
    out.append(source[pos:])
    candidate = "".join(out)
    return candidate if candidate != source else None


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


# --- xcopy ---
# Copy a match from one client to every other client that contains the same function.

CHUNK = 250


TAG = re.compile(r"ROCX([0-9a-f]{6,})")


FUNC = re.compile(r"\bfunc_[0-9a-f]{8}\b")


def _fingerprint():
    """roc/fingerprint.py holds the shared mass-matching helpers. Imported lazily so
    this module still loads (and is testable) when that file is absent."""
    from roc import fingerprint
    return fingerprint


def matched_sources(log=print):
    """[(body, [(origin client, addr), ...])] for every stored match, deduped by body text.

    The template header (disassembly comments) is dropped: it names the origin client
    and address and would be wrong in the copy. Deduplication matters because the same
    trivial function is often stored under many addresses."""
    groups = {}
    for client in sorted(clients.load()):
        folder = ROOT / "src" / client
        if not folder.is_dir():
            continue
        for path in sorted(folder.glob("*.cpp")):
            text = path.read_text(errors="replace")
            if "\n\n" not in text:
                continue
            body = text.split("\n\n", 1)[1].strip()
            if not body:
                continue
            key = hashlib.sha256(body.encode()).hexdigest()
            if key not in groups:
                groups[key] = (body, [])
            groups[key][1].append((client, path.stem))
    out = [v for v in groups.values()]
    log("%d distinct matched source(s) from %d client(s)" % (len(out), len(clients.load())))
    return out


def _lang(body):
    return match.directives(body).get("lang", "cpp")


def needs_global_scope(body):
    """True if a candidate cannot go inside a namespace.

    System headers must be included at global scope: inside a namespace, the CRT
    headers fail with "fpos_t is not a member of global namespace" because their
    using-declarations land in the wrong namespace. C has no namespaces at all. These
    get one translation unit each instead."""
    return _lang(body) == "c" or "#include" in body


def _build_of(body, origins, reg):
    """Which compiler produced these bytes: the library's own directive if it has one,
    else the client it was matched in. A copy can only reach a client sharing it."""
    declared = match.directives(body).get("cl", "")
    if declared.isdigit():
        return int(declared)
    for client, _addr in origins:
        got = reg.get(client, {}).get("compiler_build")
        if got:
            return got
    return None


def _order(clients, target, reg):
    """Own sources first, then same-compiler sources, then the rest.

    Own sources come first on purpose: re-verifying them is what recovers a client
    whose scores.json was lost, and it is also the cheapest way to be sure the pool
    reflects what is actually stored. Same-compiler sources are next because those are
    the only ones that can reproduce identical bytes."""
    build = reg[target].get("compiler_build")
    own, same, other = [], [], []
    for body, origins in clients:
        if all(c == target for c, _ in origins):
            own.append((body, origins))
        elif _build_of(body, origins, reg) == build:
            same.append((body, origins))
        else:
            other.append((body, origins))
    return own + same + other


def _matched_count(client):
    path = ROOT / "work" / client / "scores.json"
    try:
        return sum(1 for v in json.loads(path.read_text()).values() if v == 100)
    except (OSError, ValueError):
        return 0


def _batch_cpp(clients):
    """C++ candidates batched into one .cpp, each in its own namespace.

    Namespacing is needed because matches routinely declare the same type name - two
    zlib sources both defining z_stream_s - which is a hard error in one translation
    unit and would otherwise cost the whole chunk."""
    snippets = []
    for i, (body, _origins) in enumerate(clients):
        tag = "ROCX%06x" % i
        snippets.append((tag, "namespace ns_%s {\n%s\n}\n" % (tag, FUNC.sub("fn_%s" % tag, body))))
    return "\n\n".join(text for _tag, text in snippets), dict(snippets)


def _batch_alone(source):
    """One candidate in its own translation unit: needed for C, and for anything that
    includes a system header."""
    tag = "ROCX000000"
    return FUNC.sub("fn_%s" % tag, source), {tag: source}


def _match_batch(target, obj, sources_by_tag, client):
    """{addr: (source, symbol, data spans)} for every function of obj found in the exe."""
    found = {}
    for name, code, relocs in match.coff_functions(obj):
        tag = TAG.search(name)
        if not tag or tag.group(0) not in sources_by_tag:
            continue
        source = sources_by_tag[tag.group(0)]
        for addr in target.index.get(len(code), []):
            if addr in found:
                continue
            exe = target.same(addr, code, relocs)
            if exe is None:
                continue
            spans, bad = match.data_check(client, addr, exe, match.coff_data_refs(obj, name))
            if not bad:
                found[addr] = (source, name, spans)
    for addr in found:  # matched functions leave the pool
        target.index[len(match.target(client, addr)[0])].remove(addr)
    return found


def compile_batch(target, clients, reg, log):
    """Compile a batch, halving it whenever it fails.

    One bad source poisons a whole translation unit: an unbalanced brace or an
    unterminated #if leaves the parser mid-state, and the next candidate gets a syntax
    error instead of its own diagnostics. Splitting until the culprits are isolated
    keeps every other source usable instead of throwing away 250 of them. Returns
    [(obj, by_tag)] for everything that compiled."""
    out, bad = [], []

    def attempt(chunk):
        if not chunk:
            return
        try:
            if len(chunk) == 1 and needs_global_scope(chunk[0][0]):
                text, by_tag = _batch_alone(chunk[0][0])
            else:
                text, by_tag = _batch_cpp(chunk)
            obj = match.compile_text(target, text, build=reg[target].get("compiler_build"))
        except match.CompileError as error:
            if len(chunk) == 1:
                bad.append((chunk[0][0], str(error).splitlines()[0]))
                return
            half = len(chunk) // 2
            attempt(chunk[:half])
            attempt(chunk[half:])
            return
        out.append((obj, by_tag))

    attempt(clients)
    if bad:
        log("  %d source(s) failed even alone and were skipped" % len(bad))
        for text, why in bad[:4]:
            log("    %-58s %s" % (" ".join(text.split())[:58], why[:100]))
        if len(bad) > 4:
            log("    ... and %d more" % (len(bad) - 4))
    return out


def run(targets=None, log=print, limit=None, dry_run=False):
    """Copy stored matches into the given clients (default: all). Returns {client: new}."""
    reg = clients.load()
    targets = [c for c in (targets or sorted(reg)) if c in reg]
    sources = matched_sources(log=log)
    if not clients:
        log("Nothing stored to copy yet. Run  roc auto <client>  or match some by hand first.")
        return {}

    result = {}
    for target in targets:
        cands = _order(clients, target, reg)
        if limit:
            cands = cands[:limit]
        probe = _fingerprint().Target(target)
        open_before = sum(len(v) for v in probe.index.values())
        if not open_before:
            log("%-8s nothing open to match" % target)
            result[target] = (0, 0)
            continue
        log("%-8s %d candidate source(s) against %d open function(s)" % (target, len(cands), open_before))

        found = {}
        chunks = [cands[i:i + CHUNK] for i in range(0, len(cands), CHUNK)]
        for n, chunk in enumerate(chunks, 1):
            for obj, by_tag in compile_batch(target, chunk, reg, log):
                found.update(_match_batch(probe, obj, by_tag, target))
            log("  chunk %d/%d: %d new so far" % (n, len(chunks), len(found)))

        if not found:
            log("%-8s no new matches" % target)
            result[target] = (0, 0)
            continue
        if dry_run:
            log("%-8s would verify %d function(s)" % (target, len(found)))
            result[target] = (len(found), 0)
            continue
        before = _matched_count(target)
        files = _fingerprint().save(target, found, "copied from an identical function in another client")
        after = _matched_count(target)
        log("%-8s %d verified byte-identical: %d new file(s), matched %d -> %d"
            % (target, len(found), files, before, after))
        result[target] = (files, after - before)
    return result


# --- donor ---
# RBXGS WebService.dll (0.3.676, December 2007) as a name donor.

OPENRBX = ROOT / "tools" / "openrbx"


TABLE = ROOT / "clients" / "json"


MSI_URL = "https://archive.org/download/rbxgssetup/S3FileHandler_RBXGSSetup_0.3.676.0.msi"


MSI_SHA256 = "43935127301bf4189b2cec13bceef23bc32538bd4cd3fed94b14b1143a38e5e0"


DLL_SHA256 = "5e9c6b82605fc8429c5fc5f682f2d7f98b55b73d993dfba58437365754410e2f"


DLL_KEY = "_E338FA13480D4C3C3257E3F2D3E3A98D"  # File-table key of WebService.dll in that MSI


DLL = ROOT / "tools" / "rbxgs_msi" / "WebService.dll"


MARKER = re.compile(r"^//\s*(FUNCTION|STUB|TEMPLATE|SYNTHETIC|LIBRARY):\s*WEBSERVICE\s+0x([0-9a-fA-F]+)")


def fetch():
    """WebService.dll, extracted from the hash-pinned installer. msiexec /a fails on
    this MSI (IIS custom actions), so the cab stream is pulled out directly."""
    if DLL.exists() and setup.sha256(DLL) == DLL_SHA256:
        return DLL
    msi = setup.download(MSI_URL, DLL.with_name("rbxgs676.msi"))
    setup.require_sha256(msi, MSI_SHA256)
    try:
        import olefile
    except ImportError:
        raise SystemExit("Extracting WebService.dll needs olefile: python -m pip install olefile")
    ole = olefile.OleFileIO(str(msi))
    cab = DLL.with_name("rbxgs676.cab")
    for entry in ole.listdir():
        data = ole.openstream(entry).read()
        if data[:4] == b"MSCF":
            cab.write_bytes(data)
            break
    else:
        raise SystemExit("no cabinet inside %s" % msi.name)
    out = DLL.parent / DLL_KEY
    if setup.WINDOWS:
        subprocess.run(["expand.exe", str(cab), "-F:" + DLL_KEY, str(DLL.parent)], check=True,
                       capture_output=True)
    elif shutil.which("cabextract"):
        subprocess.run(["cabextract", "-q", "-F", DLL_KEY, "-d", str(DLL.parent), str(cab)], check=True)
    else:
        raise SystemExit("Install cabextract to unpack %s" % cab.name)
    out.replace(DLL)
    cab.unlink()
    setup.require_sha256(DLL, DLL_SHA256)
    return DLL


def names(folder=None):
    """{donor va: (csv kind, symbol)} from OpenRBX's PDB-derived CSVs."""
    out = {}
    for path in sorted((folder or OPENRBX / "reccmp").glob("webservice-*.csv")):
        kind = path.stem.split("-", 1)[1]
        with open(path, encoding="utf-8") as f:
            for row in csv.DictReader(f):
                sym = row.get("symbol") or row.get("name")
                if sym and row.get("type") in ("library", "stub", None):
                    out[int(row["address"], 16)] = (kind, sym)
    return out


def annotations(root=None):
    """{donor va: "path:line"} for every OpenRBX source marker."""
    root = root or OPENRBX
    out = {}
    for path in sorted(root.rglob("*.cpp")) + sorted(root.rglob("*.h")):
        try:
            lines = path.read_text(encoding="utf-8", errors="replace").splitlines()
        except OSError:
            continue
        for i, line in enumerate(lines, 1):
            m = MARKER.match(line.strip())
            if m:
                out.setdefault(int(m.group(2), 16), "%s:%d" % (path.relative_to(root).as_posix(), i))
    return out


def donor_functions(dll, folder=None):
    """{size: [(va, code, relocs)]} for every function OpenRBX sized."""
    import pefile
    from roc.analyze import reloc_sites
    pe = pefile.PE(str(dll))
    base, image = pe.OPTIONAL_HEADER.ImageBase, pe.get_memory_mapped_image()
    relocs = sorted(reloc_sites(pe))
    out = {}
    with open((folder or OPENRBX / "reccmp") / "webservice-function-size.csv", encoding="utf-8") as f:
        for row in csv.DictReader(f):
            va, size = int(row["address"], 16), int(row["size"])
            if size < 6:  # a lone ret matches everywhere
                continue
            lo, hi = bisect_left(relocs, va), bisect_left(relocs, va + size)
            out.setdefault(size, []).append((va, bytes(image[va - base:va - base + size]),
                                             [r - va for r in relocs[lo:hi]]))
    return out


def build(targets, log=print):
    """Write clients/json: {client: {addr: [donor va, kind, symbol, openrbx path:line]}}."""
    pool, named, marked = donor_functions(fetch()), names(), annotations()
    table = json.loads(TABLE.read_text()) if TABLE.exists() else {}
    for client in targets:
        t, hits = fingerprint.Target(client), {}
        for size, addrs in t.index.items():
            for va, code, rel in pool.get(size, ()):
                if va not in named and va not in marked:
                    continue
                for addr in addrs:
                    if addr not in hits and t.same(addr, code, rel) is not None:
                        kind, sym = named.get(va, ("source", ""))
                        hits[addr] = ["%08x" % va, kind, sym, marked.get(va, "")]
        table[client] = dict(sorted(hits.items()))
        log("%s: %d functions identical to a named WebService.dll function" % (client, len(hits)))
    TABLE.write_text(json.dumps(table, indent=0, sort_keys=True) + "\n")
    _table.cache_clear()
    hint.cache_clear()
    return table


@functools.lru_cache(maxsize=None)
def _table():
    try:
        return json.loads(TABLE.read_text())
    except (OSError, ValueError):
        return {}


def source_at(where, limit=60):
    """The OpenRBX source after a marker, up to the next marker (local checkout only)."""
    path, _, line = where.rpartition(":")
    try:
        lines = (OPENRBX / path).read_text(encoding="utf-8", errors="replace").splitlines()
    except OSError:
        return ""
    body = []
    for text in lines[int(line):int(line) + limit]:
        if MARKER.match(text.strip()):
            break
        body.append(text)
    return "\n".join(body).strip()


@functools.lru_cache(maxsize=4096)
def hint(client, addr):
    """{"donor", "kind", "symbol", "path", "source"} for an identical donor function, or None."""
    row = _table().get(client, {}).get(addr)
    if not row:
        return None
    va, kind, sym, where = row
    return {"donor": va, "kind": kind, "symbol": sym, "path": where,
            "source": source_at(where) if where else ""}


def default_targets():
    return [n for n, e in sorted(clients.load().items())
            if clients.status(n, e) == "ok" and (ROOT / "work" / n / "functions.jsonl").exists()]


# --- mass ---
# More mass-matching methods on top of roc/fingerprint.py:

def ar_members(data):
    """Object files inside a .lib (ar archive). Import stubs and linker members skipped."""
    if not data.startswith(b"!<arch>\n"):
        return
    pos = 8
    while pos + 60 <= len(data):
        name = data[pos:pos + 16].strip()
        size = int(data[pos + 48:pos + 58].strip() or 0)
        body = data[pos + 60:pos + 60 + size]
        pos += 60 + size + (size & 1)
        if name in (b"/", b"//") or len(body) < 20:
            continue
        if body[:4] == b"\0\0\xff\xff":  # short import object
            continue
        if struct.unpack_from("<H", body, 0)[0] == 0x14C:  # i386 COFF
            yield body


def lib_files(build):
    cl = Path(setup.compilers()[build])
    lib = cl.parents[1] / "lib"
    return sorted(lib.glob("*.lib")) + sorted(lib.glob("*.obj")) if lib.exists() else []


def staticlibs(targets, log=print):
    """Tag functions that come from the compiler's prebuilt libraries. Returns {client: count}."""
    out = {}
    for client in targets:
        t = fingerprint.Target(client)
        build = match.clients.load()[client]["compiler_build"]
        tagged = set()
        for path in lib_files(build):
            if path.name.endswith("d.lib"):  # debug variants never ship
                continue
            data = path.read_bytes()
            objs = list(ar_members(data)) if path.suffix == ".lib" else [data]
            for obj in objs:
                try:
                    found = t.match_obj(obj, None, data_check=False)
                except (struct.error, ValueError, IndexError):
                    continue
                tagged.update(found)
        path = ROOT / "work" / client / "libmatch.json"
        old = set(json.loads(path.read_text())) if path.exists() else set()
        path.write_text(json.dumps(sorted(old | tagged)))
        out[client] = len(tagged - old)
        log("%s: %d functions come from the compiler's static libraries" % (client, len(tagged)))
    return out


ELEMENTS = {
    "ptr": "struct T; typedef T* E;",
    "int": "typedef int E;",
    "uint": "typedef unsigned int E;",
    "short": "typedef short E;",
    "char": "typedef char E;",
    "float": "typedef float E;",
    "double": "typedef double E;",
    "i64": "typedef __int64 E;",
    "string": "#include <string>\ntypedef std::string E;",
    "wstring": "#include <string>\ntypedef std::wstring E;",
}


ELEMENTS.update({"pod%d" % n: "struct E { int v[%d]; };" % (n // 4) for n in (8, 12, 16, 20, 24, 28, 32, 36, 40, 48, 64)})


ELEMENTS.update({"podc%d" % n: "struct E { char v[%d]; };" % n for n in (2, 3, 5, 6, 7)})


CONTAINERS = {
    "vector": "#include <vector>\ntemplate class std::vector<E>;",
    "list": "#include <list>\ntemplate class std::list<E>;",
    "deque": "#include <deque>\ntemplate class std::deque<E>;",
    "set": "#include <set>\nbool operator<(const E&, const E&);\ntemplate class std::set<E>;",
    "map_int": "#include <map>\ntemplate class std::map<int, E>;",
    "map_ptr": "#include <map>\nstruct K; template class std::map<K*, E>;",
    "map_str": "#include <map>\n#include <string>\ntemplate class std::map<std::string, E>;",
}


def stl_units():
    for cname, cont in CONTAINERS.items():
        for ename, elem in ELEMENTS.items():
            if cname == "set" and not ename.startswith(("pod", "podc")):
                cont_text = cont.replace("bool operator<(const E&, const E&);\n", "")
            else:
                cont_text = cont
            yield "%s<%s>" % (cname, ename), "// stl: %s<%s>\n%s\n%s\n" % (cname, ename, elem, cont_text)


def _compile_unit(client, text, build):
    return match.compile_text(client, text, build=build)


def stl(targets, log=print):
    tgts = {c: fingerprint.Target(c) for c in targets}
    builds = {c: match.clients.load()[c]["compiler_build"] for c in targets}
    new = {c: 0 for c in targets}
    jobs = int(os.environ.get("ROC_JOBS") or 0) or min(12, os.cpu_count() or 4)
    for build in sorted(set(builds.values())):
        group = [c for c in targets if builds[c] == build]
        units = list(stl_units())
        # Compiles are ~0.3s each and serial here; run them concurrently and keep
        # matching/saving serial (the fingerprint index is shared state).
        with ThreadPoolExecutor(max_workers=jobs) as pool:
            futures = {pool.submit(_compile_unit, group[0], text, build): (label, text)
                       for label, text in units}
            for future in as_completed(futures):
                label, text = futures[future]
                try:
                    obj = future.result()
                except (match.CompileError, SystemExit):
                    continue
                for c in group:
                    found = tgts[c].match_obj(obj, text)
                    if found:
                        new[c] += fingerprint.save(c, found, "standard library %s" % label)
    log("stl: new matches %s" % new)
    return new
