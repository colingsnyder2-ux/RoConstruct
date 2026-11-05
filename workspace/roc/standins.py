"""Stand-in map: for a byte-exact mined source, which real 2008 symbol each of its stand-in externs is.

A mined source names its callees, globals and RTTI descriptors with invented placeholders (G1_func_x, flag_type,
acquire, ...). Its object relocates each placeholder at an offset where the exe holds the real target address, so
the pair is binary-proven, never guessed from names. Real names come from the rebuild's own symbols
(out/native-names.json), RTTI type descriptors, the import table, then the mined unit label.
Virtual calls carry no relocation and are not mapped.

usage: roc standins 2008-06 ADDR"""
import functools
import json
import struct

from roc import clients, match, rtti

DIR32, REL32 = 6, 20
# Compiler/runtime names that are already real in any source.
REAL_PREFIXES = ("__RTDynamicCast", "__CxxFrameHandler", "__EH_prolog", "__security", "_Interlocked", "__chkstk",
                 "??_7type_info", "__purecall", "___CxxFrameHandler", "__except_list", "__ehhandler$", "__unwindfunclet$",
                 "__catch$", "$L", "??_R0", "__imp_")
REAL = tuple(p.lstrip("_") for p in REAL_PREFIXES)


def obj_relocations(obj, symbol):
    """[(offset in symbol, target symbol name, reloc type)] for one function symbol of a COFF object."""
    _, nsec, _, symptr, nsym, optsz, _ = struct.unpack_from("<HHIIIHH", obj, 0)
    strtab = symptr + nsym * 18
    names, where, i = {}, None, 0
    while i < nsym:
        raw, value, secnum, _, _, naux = struct.unpack_from("<8sIhHBB", obj, symptr + 18 * i)
        if raw[:4] == b"\0\0\0\0":
            off = strtab + struct.unpack_from("<I", raw, 4)[0]
            raw = obj[off:obj.index(b"\0", off)]
        name = raw.rstrip(b"\0").decode("latin-1")
        names[i] = name
        if name == symbol and secnum > 0:
            where = (secnum - 1, value)
        i += 1 + naux
    if where is None:
        return []
    sec, value = where
    relptr, nrel = struct.unpack_from("<IIH", obj, 20 + optsz + 40 * sec + 24)[0], \
        struct.unpack_from("<H", obj, 20 + optsz + 40 * sec + 32)[0]
    out = []
    for k in range(nrel):
        va, index, kind = struct.unpack_from("<IIH", obj, relptr + 10 * k)
        if va >= value:
            out.append((va - value, names.get(index, "?"), kind))
    return out


@functools.lru_cache(maxsize=None)
def _names(client):
    from roc.rebuild import workspace
    path = workspace(client) / "out" / "native-names.json"
    cached = match.ROOT / "work/integration-client/evidence.json"  # server copy for PCs without rebuild artifacts
    names = json.loads(path.read_text()) if path.exists() else \
        json.loads(cached.read_text())["names"] if cached.exists() else {}
    rebuilt = {int(a, 16): v["symbol"] for a, v in names.items() if v.get("symbol")}
    units = {int(a, 16): row.get("unit") for a, row in match._functions(client).items() if row.get("unit")}
    return rebuilt, rtti.descriptors(client), units


@functools.lru_cache(maxsize=None)
def _imports(client):
    import pefile
    pe = pefile.PE(str(clients.exe_path(client, clients.load()[client])))
    return {item.address: "%s!%s" % (dll.dll.decode("latin-1"), item.name.decode("latin-1") if item.name
                                     else "#%d" % item.ordinal)
            for dll in getattr(pe, "DIRECTORY_ENTRY_IMPORT", []) for item in dll.imports if item.address}


def real_name(client, va):
    rebuilt, descriptors, units = _names(client)
    if va in rebuilt:
        return "symbol", rebuilt[va]
    if va in descriptors:
        return "rtti", descriptors[va]
    imports = _imports(client)
    if va in imports:
        return "import", imports[va]
    if va in units:
        return "unit", units[va]
    return None, None


def mapping(client, addr, source, obj=None):
    """[{standin, kind, target, real}] for each placeholder an exact mined source relocates, deduplicated."""
    obj = obj or match.compile_text(client, source)
    value, symbol, _, _ = match.check_text(client, addr, source, obj=obj)
    if value != 100 or not symbol:
        return []
    code = match.target(client, addr)[0]
    start, out, seen = int(addr, 16), [], set()
    for off, name, kind in obj_relocations(obj, symbol):
        if off + 4 > len(code) or name in seen or name.lstrip("_").startswith(REAL) or kind not in (DIR32, REL32):
            continue
        word = int.from_bytes(code[off:off + 4], "little", signed=kind == REL32)
        va = (start + off + 4 + word) & 0xFFFFFFFF if kind == REL32 else word
        found, real = real_name(client, va)
        seen.add(name)
        out.append({"standin": name, "kind": found or "unknown", "target": "%08x" % va, "real": real})
    return out


def main(argv):
    client, addr = argv[0], argv[1].lower()
    from roc.packet import _source
    for row in mapping(client, addr, _source(client, addr)[0]):
        print("%-40s -> %-7s %s %s" % (row["standin"][:40], row["kind"], row["target"], row["real"] or ""))
