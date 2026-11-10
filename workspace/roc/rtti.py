"""RTTI reverse-index: binary-proven template types for every function.

MSVC RTTI Type Descriptors have the layout [vfptr(4)][spare(4)][name...], with
names like `.?AVVector2int16@G3D@@`. Functions that take a template type
parameter (Reflection::TypedPropertyDescriptor<T>, BoundFuncDesc<...>,
FactoryProduct) reference these descriptors through relocations — most visibly
as the TargetType push before `__RTDynamicCast`. Reading the descriptor instead
of guessing the type turned 004ad180 from 54% to 100% in one edit; this module
mechanizes that discovery.
"""
import json
import re
from pathlib import Path

from roc import clients, match

ROOT = Path(__file__).resolve().parent.parent
# MSVC type-descriptor names: .?AV (class), .?AU (struct), .?AW, .?$ (templates),
# .?A0x (anonymous), .PEA/.PEAU (pointer decorations used by newer linkers).
NAME_RE = re.compile(rb"^\.(\?A[VUW]|[\$A-Z0-9])")


def _image(client):
    return match._image(client)


def descriptors(client):
    """Every RTTI type descriptor in the client image: {address: demangled name}."""
    base, image = _image(client)
    found = {}
    pos = 0
    while True:
        hit = image.find(b".?", pos)
        if hit < 0:
            break
        pos = hit + 1
        if not NAME_RE.match(image[hit:hit + 4]):
            continue
        start = hit - 8  # descriptors sit 8 bytes before the name
        if start < 0:
            continue
        # The descriptor's leading vfptr must point inside the image.
        vfptr = int.from_bytes(image[start:start + 4], "little")
        if not (base <= vfptr < base + len(image)):
            continue
        raw = image[hit:hit + 200].split(b"\x00", 1)[0]
        try:
            name = raw.decode("ascii", "strict")
        except (UnicodeDecodeError, ValueError):
            continue
        if 3 < len(name) < 200:
            found[base + start] = name
    return found


def function_refs(client, addr, index=None):
    """(offset, address, name) for every RTTI descriptor a function references.

    These are the binary-proven type parameters: a `push <descriptor>` before
    __RTDynamicCast states the exact template type the original source used.
    """
    index = descriptors(client) if index is None else index
    code, relocs, row = match.target(client, addr)
    refs = []
    for off in relocs:
        if off + 4 > len(code):
            continue
        va = int.from_bytes(code[off:off + 4], "little")
        name = index.get(va)
        if name is not None:
            refs.append({"offset": off, "address": va, "type": name})
    return refs


def vtable_stores(client, addr, body=None, relocations=None):
    """Relocated MOV stores of validated x86 MSVC RTTI vtables.

    Constructors and destructors both write vptrs. Report the instruction and
    destination verbatim; this does not establish a complete layout or ABI.
    """
    from capstone import Cs, CS_ARCH_X86, CS_MODE_32
    from capstone.x86_const import X86_OP_IMM, X86_OP_MEM
    if body is None:
        body, relocations, _ = match.target(client, addr)
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    md.detail = True
    start = int(addr, 16)
    sites = set(relocations or ())
    candidates = []
    for insn in md.disasm(body, start):
        if insn.mnemonic in ("ret", "retf", "int3"):
            break  # Do not interpret trailing tables or padding as vptr stores.
        ops = insn.operands
        if (insn.mnemonic == "mov" and len(ops) == 2 and ops[0].type == X86_OP_MEM
                and ops[0].size == 4 and ops[1].type == X86_OP_IMM
                and insn.address - start + insn.imm_offset in sites):
            candidates.append((insn, ops[1].imm & 0xffffffff))
    if not candidates:
        return []
    base, image = _image(client)
    relocs = match._base_relocs(client)
    functions = match._functions(client)
    def word(va):
        return int.from_bytes(image[va-base:va-base+4], "little") if base <= va <= base+len(image)-4 else 0
    out = []
    for insn, table in candidates:
        if table - 4 not in relocs:
            continue
        locator = word(table - 4)
        if not base <= locator <= base + len(image) - 20 or word(locator) != 0 or locator + 12 not in relocs:
            continue
        descriptor = word(locator + 12)
        if not base <= descriptor <= base + len(image) - 9:
            continue
        raw = image[descriptor-base+8:descriptor-base+208].split(b"\0", 1)[0]
        if (not raw.startswith((b".?AV", b".?AU")) or not 4 < len(raw) < 200
                or not raw.isascii() or not 0 < word(descriptor) - base < len(image)):
            continue
        entry = functions.get("%08x" % word(table))
        if table not in relocs or not entry or entry.get("kind", "code") not in ("code", "gen"):
            continue
        out.append(dict(instruction="%08x" % insn.address, destination=insn.op_str.split(",", 1)[0],
            vtable="%08x" % table, type_descriptor="%08x" % descriptor, type=raw.decode("ascii", "replace")))
        if len(out) == 8:
            break
    return out


def pretty(kind):
    """Readable form of an RTTI descriptor name for prompts and diffs."""
    kind = kind.lstrip(".")
    if kind.startswith("?AV"):
        return "class " + kind[3:].rstrip("@").replace("@", "::")
    if kind.startswith("?AU"):
        return "struct " + kind[3:].rstrip("@").replace("@", "::")
    if kind.startswith("?AW"):
        return "enum " + kind[3:].rstrip("@").replace("@", "::")
    return kind


def open_function_refs(client, scores=None, limit=None):
    """RTTI refs for every open function, the actionable mining list."""
    index = descriptors(client)
    rows = []
    path = ROOT / "work" / client / "functions.jsonl"
    if scores is None:
        spath = ROOT / "work" / client / "scores.json"
        scores = json.loads(spath.read_text()) if spath.exists() else {}
    with path.open(encoding="utf-8") as stream:
        for line in stream:
            row = json.loads(line)
            addr = row["addr"]
            if scores.get(addr, 0) >= 100 or row.get("kind", "code") != "code":
                continue
            refs = function_refs(client, addr, index)
            if refs:
                rows.append({"addr": addr, "score": scores.get(addr, 0),
                             "size": row.get("size", 0), "unit": row.get("unit", ""),
                             "refs": refs})
            if limit and len(rows) >= limit:
                break
    return rows
