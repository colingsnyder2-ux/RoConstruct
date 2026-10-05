"""Mine type information already present in the decompiled corpus.

Why this exists
---------------
Per-function standalone compilation is the wrong oracle for a stripped
binary: with no shared type environment each function invents its own types
and they collide (C2040/C2371/C2372/C2377). The prerequisite is ONE
consistent type universe that every function compiles against.

Three cheap, high-signal sources, all from data we already have:
  1. RTTI class names   -- the binary kept its RTTI (we already saw
     `Ogre::AlignedMemory::allocate` and `RBX::Network::*`), so the class
     universe is recoverable almost for free.
  2. Field-offset evidence -- Ghidra decompile shows `*(int *)(x + 0x18)`;
     counting distinct offsets per type-ish name gives real layouts.
  3. Accessor pairs    -- `get_x`/`set_x` neighbours in the name column.

Run:  python scripts/re/types.py universe
      python scripts/re/types.py report
"""
import collections
import os
import re
import sqlite3
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from summarize import DEFAULT_DB  # noqa: E402

RE_DIR = os.path.join(os.path.dirname(os.path.dirname(os.path.dirname(
    os.path.abspath(__file__)))), "work", "re")
TYPE_DIR = os.path.join(RE_DIR, "types")

# RTTI / qualified names, e.g. RBX::Network::Client, Ogre::DynLibManager
_QUALIFIED = re.compile(
    r"\b([A-Z][A-Za-z0-9_]*(?:::[A-Za-z_][A-Za-z0-9_]*)+)\b")
# Ogre/RBX style demangled method: Class::method
_METHOD = re.compile(
    r"\b([A-Z][A-Za-z0-9_]*)::([A-Za-z_~][A-Za-z_0-9_]*)\s*\(")
# Ghidra's offset access: *(TYPE *)(base + 0xNN) or base + 0xNN
_OFF_ACCESS = re.compile(
    r"\*\s*\(\s*(?:u?int(?:8|16|32|64)_t|undefined\d?|uint|ulong|int|long|"
    r"char|short|byte|void)\s*\*\s*\)\s*\([^()]*\+\s*(0x[0-9a-fA-F]+|\d+)\s*\)")
_OFF_BARE = re.compile(
    r"(?<![.\w])\+\s*(0x[0-9a-fA-F]{1,4}|\d{1,4})\s*\)")

_DECL = """
CREATE TABLE IF NOT EXISTS types(
    name       TEXT PRIMARY KEY,   -- mangled/qualified C++ name
    namespace  TEXT,
    kind       TEXT,               -- class | method
    n_refs     INTEGER DEFAULT 0,  -- functions mentioning it
    n_methods  INTEGER DEFAULT 0,
    offsets    TEXT,               -- comma-separated observed field offsets
    n_offsets  INTEGER DEFAULT 0,
    sample     TEXT
);
CREATE TABLE IF NOT EXISTS type_offsets(
    tname  TEXT NOT NULL,
    off    INTEGER NOT NULL,
    n      INTEGER NOT NULL,
    PRIMARY KEY(tname, off)
);
CREATE INDEX IF NOT EXISTS idx_ton_t ON type_offsets(tname);
"""


def connect(db=DEFAULT_DB):
    c = sqlite3.connect(db)
    c.executescript(_DECL)
    return c


def _ns_of(name):
    return "::".join(name.split("::")[:-1]) if "::" in name else ""


def universe(conn, limit=None, min_refs=1):
    """Scan every decompiled function for type evidence and store it."""
    q = ("SELECT program, addr, name, sig, decompiled FROM functions "
         "WHERE decompiled IS NOT NULL AND length(decompiled) > 200")
    if limit:
        q += " LIMIT %d" % limit

    refcount = collections.Counter()
    methods = collections.defaultdict(set)
    offs = collections.defaultdict(collections.Counter)
    sample = {}
    # for offset evidence we need a name to attach it to; use the function's
    # own qualified name, else fall back to the first `this`-ish parameter
    scanned = 0
    for prog, addr, name, sig, dec in conn.execute(q):
        scanned += 1
        text = (name or "") + "\n" + (sig or "") + "\n" + dec

        found = set()
        for m in _QUALIFIED.finditer(text):
            found.add(m.group(1))
        for m in _METHOD.finditer(text):
            cls, meth = m.group(1), m.group(2)
            found.add(cls)
            methods[cls].add(meth)
            found.add("%s::%s" % (cls, meth))

        for f in found:
            if f.startswith(("RBX::", "Ogre::", "std::", "lua_", "_")) or \
                    "::" in f or (f[:1].isupper() and len(f) > 3):
                refcount[f] += 1
                if f not in sample:
                    sample[f] = (prog, addr, name)

        # field offsets, attributed to this function's class if we can tell
        cls_guess = None
        for m in _METHOD.finditer(text):
            cls_guess = m.group(1)
            break
        if cls_guess is None:
            mq = _QUALIFIED.search((name or "") + " " + (sig or ""))
            cls_guess = mq.group(1) if mq else None
        if cls_guess:
            seen = set()
            for m in _OFF_ACCESS.finditer(dec):
                v = int(m.group(1), 0)
                if v % 4 == 0 and v <= 0x400 and v not in seen:
                    seen.add(v)
            for m in _OFF_BARE.finditer(dec):
                v = int(m.group(1), 0)
                if v % 4 == 0 and v <= 0x400 and v not in seen:
                    seen.add(v)
            for v in seen:
                offs[cls_guess][v] += 1

    print("scanned %d functions, %d type names, %d with offsets"
          % (scanned, len(refcount), len(offs)))

    for f, n in refcount.items():
        if n < min_refs:
            continue
        prog, addr, fname = sample.get(f, (None, None, None))
        ns = _ns_of(f)
        kind = "method" if "::" in f and f.rsplit("::", 1)[1] not in () else "class"
        conn.execute(
            "INSERT OR REPLACE INTO types"
            "(name, namespace, kind, n_refs, n_methods, offsets, n_offsets, sample)"
            " VALUES(?,?,?,?,?,?,?,?)",
            (f, ns, kind, n, len(methods.get(f, ())), None, 0,
             "%s@%s %s" % (prog, addr, fname) if prog else None))

    for cls, counter in offs.items():
        tot = sum(counter.values())
        lst = ",".join(str(k) for k, _ in sorted(counter.items()))
        conn.execute("UPDATE types SET offsets=?, n_offsets=? WHERE name=?",
                     (lst, len(counter), cls))
        for o, c in counter.items():
            conn.execute(
                "INSERT OR REPLACE INTO type_offsets(tname, off, n) VALUES(?,?,?)",
                (cls, o, c))
        print("  %-40s %2d offsets, %d refs" % (cls, len(counter), tot))

    conn.commit()
    print("types stored: %d" % conn.execute(
        "SELECT COUNT(*) FROM types").fetchone()[0])


def report(conn, n=30):
    print("=== classes by references")
    for r in conn.execute(
            "SELECT name, namespace, n_refs, n_methods, n_offsets FROM types "
            "WHERE kind='class' ORDER BY n_refs DESC LIMIT ?", (n,)):
        print("  %-46s ns=%-18s refs=%-5d methods=%-3d offs=%d" % r)
    print()
    print("=== namespaces")
    for r in conn.execute(
            "SELECT namespace, COUNT(*) c, SUM(n_refs) s FROM types "
            "WHERE namespace<>'' GROUP BY namespace ORDER BY c DESC LIMIT 25"):
        print("  %-40s types=%-5d refs=%d" % (r[0], r[1], r[2] or 0))
    print()
    print("=== richest offset evidence")
    for r in conn.execute(
            "SELECT tname, COUNT(*) n, MIN(off), MAX(off) FROM type_offsets "
            "GROUP BY tname ORDER BY n DESC LIMIT 20"):
        print("  %-40s offsets=%-3d range=0x%x..0x%x" % r)


def emit_header(conn, path=None):
    """Emit a shared C++ header: one opaque class per recovered name.

    This is the 'type universe' every reconstructed function compiles
    against. Sizes come from the highest observed field offset.
    """
    os.makedirs(TYPE_DIR, exist_ok=True)
    path = path or os.path.join(TYPE_DIR, "universe.h")
    rows = conn.execute(
        "SELECT name, n_offsets, offsets FROM types "
        "WHERE kind='class' AND name NOT LIKE '%::%' ESCAPE '\\' "
        "OR (kind='class' AND n_offsets > 0)").fetchall()
    lines = ["/* Generated by scripts/re/types.py -- SHARED TYPE UNIVERSE.",
             " * Every reconstructed function compiles against this header,",
             " * which is what stops each function inventing conflicting",
             " * types for the same class (C2040/C2371/C2372). */",
             "#pragma once",
             "#include <stdint.h>",
             ""]
    seen = set()
    for name, n_off, offs in rows:
        if name in seen:
            continue
        seen.add(name)
        size = 8
        if offs:
            try:
                size = max(int(x, 0) for x in offs.split(",")) + 8
            except ValueError:
                size = 8
        safe = re.sub(r"[^A-Za-z0-9_]", "_", name)
        lines.append("struct %s_%s { uint8_t _opaque[%d]; };"
                     % (safe, "x", size))
    lines.append("")
    with open(path, "w", encoding="utf-8") as f:
        f.write("\n".join(lines))
    print("wrote %s (%d structs)" % (path, len(seen)))
    return path


def main():
    ap_cmd = sys.argv[1] if len(sys.argv) > 1 else "universe"
    c = connect()
    if ap_cmd == "universe":
        universe(c, limit=int(sys.argv[2]) if len(sys.argv) > 2 else None)
    elif ap_cmd == "report":
        report(c)
    elif ap_cmd == "header":
        emit_header(c)
    else:
        print("cmd: universe | report | header")
    c.close()


if __name__ == "__main__":
    main()
