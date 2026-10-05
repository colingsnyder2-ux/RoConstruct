"""Emit a real shared type universe: per-class struct layouts from observed
field offsets, so pointer assignments typecheck instead of failing C2440.

Why
---
The last mechanical repairs got the compile oracle to 20%. What is left is
genuine unknown-type recovery:

    error C2440: '=': cannot convert from 'uint32_t *' to 'StringInterface *'
    error C2440: '=': cannot convert from 'uint32_t *' to 'uint8_t *'

Every function re-guessed the same classes and guessed differently. The cure
is ONE shared universe that every function compiles against, built from
evidence we already mined in `typelib.py`: for each class, the set of field
offsets actually observed in decompiled code, plus whether the accesses were
reads or writes through a pointer.

Field naming: an offset that is read AND written through a `TYPE *` cast is a
field of TYPE. Ghidra prints `*(uint32_t *)(x + 0x18)`, so `uint32_t` is the
field type and `0x18` the offset.

Run:  python scripts/re/typelib.py layouts     # per-class offset -> width
      python scripts/re/typelib.py universe2   # emit work/re/types/universe.h
"""
import collections
import os
import re
import sqlite3
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from summarize import DEFAULT_DB  # noqa: E402

TYPE_DIR = os.path.join(os.path.dirname(os.path.dirname(os.path.dirname(
    os.path.abspath(__file__)))), "work", "re", "types")

# Ghidra decompile access forms we can attribute to a class:
#   *(uint32_t *)(this + 0x18)          -> field at 0x18, width 4
#   *(StringInterface *)(x + 0x8)      -> field at 0x8, is a pointer
#   *(uint32_t *)(x + 0x1c) = v        -> write
_ACCESS = re.compile(
    r"\*\s*\(\s*(?P<ty>[A-Za-z_][A-Za-z_0-9]*)\s*\*\s*\)\s*"
    r"\(\s*(?P<base>[A-Za-z_][A-Za-z_0-9]*)\s*\+\s*"
    r"(?P<off>0x[0-9a-fA-F]+|\d+)\s*\)")

WIDTHS = {
    "undefined1": 1, "byte": 1, "uchar": 1, "char": 1, "int8_t": 1,
    "BOOL": 1, "BOOL": 1, "BOOLEAN": 1,
    "undefined2": 2, "ushort": 2, "WORD": 2, "short": 2, "int16_t": 2,
    "undefined4": 4, "uint": 4, "int": 4, "uint32_t": 4, "int32_t": 4,
    "dword": 4, "DWORD": 4, "long": 4, "float": 4, "size_t": 4,
    "undefined8": 8, "ulong": 8, "uint64_t": 8, "int64_t": 8,
    "longlong": 8, "qword": 8, "double": 8, "intptr_t": 8, "PVOID": 8,
}

_WRITE_ACCESS = re.compile(
    r"\*\s*\(\s*(?P<ty>[A-Za-z_]\w*)\s*\*\s*\)\s*\(\s*(?P<base>\w+)\s*\+\s*"
    r"(?P<off>0x[0-9a-fA-F]+|\d+)\s*\)\s*=")

SAFE = re.compile(r"[^A-Za-z0-9_]")


def safe(name):
    return SAFE.sub("_", name)


def layouts(conn, limit=None):
    """Accumulate (class -> offset -> width, is_ptr) from decompiled code."""
    q = ("SELECT program, addr, name, sig, decompiled FROM functions "
         "WHERE decompiled IS NOT NULL AND length(decompiled) > 200")
    if limit:
        q += " LIMIT %d" % limit

    fields = collections.defaultdict(dict)   # cls -> off -> {w, ptr, rd, wr}
    classes_in = collections.defaultdict(collections.Counter)
    n = 0

    for prog, addr, fname, sig, dec in conn.execute(q):
        n += 1
        # which class does this function belong to?
        cls = None
        for rx in (re.compile(r"\b([A-Z]\w+)::~\1\b"),          # ctor
                   re.compile(r"\b([A-Z]\w+)::([A-Za-z_]\w*)\s*\("),  # method
                   re.compile(r"\b([A-Z]\w+)\s*\*\s*(?:__thiscall|this)")):
            m = rx.search((fname or "") + " " + (sig or ""))
            if m:
                cls = m.group(1)
                break
        for m in _ACCESS.finditer(dec or ""):
            base, off, ty = m.group("base"), int(m.group("off"), 0), m.group("ty")
            if base not in ("this", "self", "self_", "param_1", "this_"):
                continue
            if off % 4 or off > 0x800:
                continue
            if cls is None:
                continue
            w = WIDTHS.get(ty, 0)
            is_ptr = 1 if (w == 0 and ty[:1].isupper()) else 0
            if w == 0 and not is_ptr:
                w = 4
            slot = fields[cls].setdefault(off, {"w": w, "ptr": is_ptr,
                                                "rd": 0, "wr": 0})
            slot["rd"] += 1
            if slot["w"] == 0 and w:
                slot["w"] = w
            classes_in[cls][off] += 1
        for m in _WRITE_ACCESS.finditer(dec or ""):
            base, off = m.group("base"), int(m.group("off"), 0)
            if base in ("this", "self", "self_", "this_") and cls and off in fields[cls]:
                fields[cls][off]["wr"] += 1

    print("scanned %d functions, %d classes with field evidence" % (n, len(fields)))
    conn.executescript("""
    CREATE TABLE IF NOT EXISTS layout(
        cls TEXT NOT NULL,
        off INTEGER NOT NULL,
        width INTEGER,
        is_ptr INTEGER DEFAULT 0,
        n_read INTEGER DEFAULT 0,
        n_write INTEGER DEFAULT 0,
        PRIMARY KEY(cls, off)
    );""")
    tot = 0
    for cls, offs in fields.items():
        for off, s in sorted(offs.items()):
            conn.execute(
                "INSERT OR REPLACE INTO layout(cls, off, width, is_ptr, "
                "n_read, n_write) VALUES(?,?,?,?,?,?)",
                (cls, off, s["w"], s["ptr"], s["rd"], s["wr"]))
            tot += 1
    conn.commit()
    print("layout rows: %d" % tot)
    for cls, offs in sorted(fields.items(),
                            key=lambda kv: -len(kv[1]))[:15]:
        print("  %-32s %3d fields, max off 0x%x" %
              (cls, len(offs), max(offs)))


def universe2(conn, out=None):
    """Emit one C++ header with a real struct per recovered class."""
    os.makedirs(TYPE_DIR, exist_ok=True)
    out = out or os.path.join(TYPE_DIR, "universe.h")
    rows = collections.defaultdict(list)
    for cls, off, w, isp, nr, nw in conn.execute(
            "SELECT cls, off, width, is_ptr, n_read, n_write FROM layout "
            "ORDER BY cls, off"):
        rows[cls].append((off, w, isp))

    # also emit a forward declaration for every known class name so that
    # pointer-to-class uses typecheck (the C2440 source)
    names = [r[0] for r in conn.execute("SELECT name FROM types")]

    L = []
    L.append("/* Generated by scripts/re/typelib.py -- SHARED TYPE UNIVERSE v2")
    L.append(" *")
    L.append(" * Built from observed field offsets in the decompiled corpus:")
    L.append(" * each field is placed at the offset the binary actually used,")
    L.append(" * so reconstructions line up with the original layout.")
    L.append(" * Every reconstructed function compiles against THIS header --")
    L.append(" * that is what stops each function inventing its own types.")
    L.append(" */")
    L.append("#pragma once")
    L.append("#include <stdint.h>")
    L.append("")
    L.append("/* ---- forward declarations ---- */")
    seen = set()
    for n in names:
        if "::" in n:
            continue
        s = safe(n)
        if s in seen or s in _KEYWORDS:
            continue
        seen.add(s)
        L.append("struct %s;" % s)
    L.append("")
    L.append("/* ---- layouts recovered from the binary ---- */")
    for cls in sorted(rows):
        s = safe(cls)
        if s in _KEYWORDS:
            continue
        offs = rows[cls]
        size = max(o for o, _w, _p in offs) + 8
        L.append("struct %s {   /* %d fields, size >= 0x%x */" % (s, len(offs), size))
        for off, w, isp in offs:
            if isp:
                L.append("    void        *f_0x%02x;   /* +0x%02x */" % (off, off))
            else:
                L.append("    uint%d_t     f_0x%02x;   /* +0x%02x */"
                         % (w * 8, off, off))
        L.append("    uint8_t      _pad[0];")
        L.append("};")
        L.append("")

    with open(out, "w", encoding="utf-8") as f:
        f.write("\n".join(L))
    n_struct = len([c for c in rows if safe(c) not in _KEYWORDS])
    print("wrote %s: %d layouts + %d forward decls" %
          (out, n_struct, len(seen)))
    return out


_KEYWORDS = set("""int char long short float double void bool wchar_t
unsigned signed const volatile static extern struct class union enum typedef
return if else for while do switch case default break continue goto sizeof
namespace using template typename operator new delete this public private
protected virtual explicit inline friend mutable register auto""".split())


def main():
    cmd = sys.argv[1] if len(sys.argv) > 1 else "layouts"
    c = sqlite3.connect(DEFAULT_DB)
    if cmd == "layouts":
        layouts(c, limit=int(sys.argv[2]) if len(sys.argv) > 2 else None)
    elif cmd == "universe2":
        universe2(c)
    else:
        print("cmd: layouts | universe2")
    c.close()


if __name__ == "__main__":
    main()
