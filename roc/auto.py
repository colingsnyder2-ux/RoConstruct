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
    return out


def candidates(lines):
    """C++ snippets (with NAME placeholder) that might compile to these asm lines."""
    if not lines:
        return []
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
    """One .cpp with every candidate; names are unique per (addr, index)."""
    return "extern char G;\n\n" + "\n".join(s.replace("NAME", tag) for tag, s in snippets)


def solve(client, max_size=24, skip=(), log=print):
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
    """Write matches into src/<client>/ (keeps existing hand-written files)."""
    for addr, src in found.items():
        path = ROOT / "src" / client / ("%s.cpp" % addr)
        if path.exists():
            continue
        header = match.template(client, addr).split("\n\n")[0]
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(header + "\n// auto-matched from its assembly shape\n\n" + src)
        match.save_score(client, addr, 100)
