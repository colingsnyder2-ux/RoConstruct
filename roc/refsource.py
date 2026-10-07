"""Resolve a client function to the Roblox source that probably produced it.

The 2007-2012 clients only keep mangled unit names in the analysis (`?func_...@@YAXXZ`,
`CMultiPlayerPane`, `RBX::VHat::?$FactoryProduct::Creator`), because the linker threw
away everything else. The 2016 client source carries the real class, member and method
names. That makes it a dictionary:

  * a unit name that *is* a class or namespace matches real source directly
  * `RBX::VHat::...Creator` points at class VHat in the RBX namespace
  * a member of a known class, or a symbol that exists in both trees, is a strong hint

Two things this is used for, in increasing order of value:

  1. `sources_for()` proposes the files and the actual code for a function, which is what
     the AI worker is handed as a hint instead of nothing but assembly.
  2. `compile_candidates()` returns real source that can be compiled with the client's own
     compiler and fingerprinted, exactly like the library recipes do. Most 2016 code will
     not build under VS2005/VS2008, but simple leaf functions often will, and every byte-exact
     hit is free.

The tree is only indexed once and cached, because it is tens of thousands of files.
"""
import functools
import json
import re
from collections import defaultdict
from pathlib import Path

from roc import clients, match

ROOT = Path(__file__).resolve().parent.parent
TREE = ROOT / "tools" / "roblox2016" / "src"
CACHE = ROOT / "work" / "refsource.json"

SOURCE_SUFFIXES = {".cpp", ".c", ".h", ".hpp", ".inl", ".cc", ".cxx"}
# The repo nests everything under ROBLOX2016-main/<Module>/...
SKIP_DIRS = {".git", "ThirdParty", "ThirdPartyIncluded", "UnitTest", "UnitTests",
             "Test", "Tests", "Android", "Mac", "Installer", "PrepAllForUpload"}

CLASS_RE = re.compile(r"\b(?:class|struct)\s+([A-Za-z_]\w*)")
NAMESPACE_RE = re.compile(r"^\s*namespace\s+([A-Za-z_]\w*)", re.M)
FUNC_RE = re.compile(r"^\s*(?:[A-Za-z_][\w:<>,\s\*&]*?\s+)?([A-Za-z_]\w*)\s*\(", re.M)
DECL_RE = re.compile(r"^\s*(?:[A-Za-z_][\w:<>,\s\*&]*?\s+)+([A-Za-z_]\w*)\s*\([^;{]*\)\s*(?:const\s*)?;", re.M)


def _walk(root):
    for path in sorted(root.rglob("*")):
        if path.suffix.lower() not in SOURCE_SUFFIXES or not path.is_file():
            continue
        if any(part in SKIP_DIRS for part in path.parts):
            continue
        yield path


def build_index(force=False, log=print):
    """{class name: [paths]}, {function name: [paths]} over the 2016 source tree."""
    if CACHE.exists() and not force:
        try:
            data = json.loads(CACHE.read_text())
            if data.get("files") == str(TREE):
                return data["classes"], data["funcs"]
        except (OSError, ValueError, KeyError):
            pass
    if not TREE.is_dir():
        raise SystemExit("2016 source not extracted at %s" % TREE)
    classes, funcs, n = defaultdict(list), defaultdict(list), 0
    for path in _walk(TREE):
        n += 1
        try:
            text = path.read_text(errors="replace")
        except OSError:
            continue
        rel = str(path.relative_to(TREE))
        found = set(CLASS_RE.findall(text))
        for ns in NAMESPACE_RE.findall(text):
            found.add(ns)
        for name in found:
            if len(name) > 2 and not name.startswith(("std", "boost")):
                classes[name].append(rel)
        for name in set(DECL_RE.findall(text)) | set(FUNC_RE.findall(text)):
            if len(name) > 2:
                funcs[name].append(rel)
    data = {"files": str(TREE),
            "classes": {k: sorted(set(v)) for k, v in classes.items()},
            "funcs": {k: sorted(set(v)) for k, v in funcs.items()}}
    CACHE.parent.mkdir(parents=True, exist_ok=True)
    CACHE.write_text(json.dumps(data, separators=(",", ":")))
    log("indexed %d source file(s): %d class/namespace name(s), %d function name(s)"
        % (n, len(data["classes"]), len(data["funcs"])))
    return data["classes"], data["funcs"]


# ---------- name resolution ----------

MANGLED_PREFIXES = ("A6A",)   # MSVC calling-convention marker in front of a real name


def identifiers(unit):
    """Candidate plain identifiers inside a mangled or plain unit name.

    `RBX::VInstance::?$NonFactoryProduct` -> RBX, VInstance, NonFactoryProduct
    `CMultiPlayerPane` -> CMultiPlayerPane
    `A6AXVColor3` -> also VColor3, Color3

    MSVC glues its calling-convention markers onto the front of the name and the marker
    length varies by mangling, so rather than guess which prefix is in play, every short
    leading-character suffix is offered. These are only ever used as lookup keys or prompt
    hints, so a few spurious candidates cost nothing and a missed prefix costs a real hit.
    """
    out = []
    for chunk in re.split(r"[:@$?\s]+", unit):
        chunk = chunk.strip()
        if not chunk or not re.match(r"^[A-Za-z_]\w*$", chunk):
            continue
        if chunk in ("A", "B", "C", "D", "E", "F", "G", "V", "W", "X", "Y", "Z", "YAXXZ"):
            continue
        out.append(chunk)
        for i in range(1, min(7, len(chunk) - 2)):
            tail = chunk[i:]
            if tail.isupper() and len(tail) <= 2:
                continue              # another marker, not a name
            if re.match(r"^[A-Za-z_]\w*$", tail):
                out.append(tail)
    return out


def _plausible(names, index):
    """Keep identifiers that exist in the 2016 tree, longest first.

    Only UpperCamelCase names qualify: Roblox's own types are UpperCamelCase
    (VInstance, Color3, RakPeer), so requiring an initial capital discards the spurious
    suffixes the mangling strips produce (`nstance`, `tance`) and stops them from
    inflating a coverage figure."""
    hits = [n for n in names if n and n[0].isupper() and n in index]
    return sorted(set(hits), key=len, reverse=True)


def sources_for(unit, limit=5, log=None):
    """[(score, path, snippet)] - the 2016 source most likely behind a client unit."""
    classes, funcs = build_index(log=log or (lambda *a: None))
    names = identifiers(unit)
    found, seen = [], set()
    # a class name is the strongest signal; then a method name
    for name in _plausible(names, classes):
        for rel in classes[name][:limit]:
            if rel in seen:
                continue
            seen.add(rel)
            found.append((100 + len(name), rel, snippet(rel)))
    for name in _plausible(names, funcs):
        if len(found) >= limit * 2:
            break
        for rel in funcs[name][:limit]:
            if rel in seen:
                continue
            seen.add(rel)
            found.append((50 + len(name), rel, snippet(rel)))
    found.sort(key=lambda r: -r[0])
    return found


def snippet(rel, lines=6):
    """First few lines of a file, for a hint in a prompt."""
    path = TREE / rel
    try:
        head = path.read_text(errors="replace").splitlines()[:lines]
    except OSError:
        return ""
    return "\n".join(head)


@functools.lru_cache(maxsize=1024)
def hint(unit, lines=60):
    """The 2016 declaration of the class behind a unit, for the AI worker's prompt, or None.

    Innermost name first (`RBX::Network::Replicator` -> Replicator), headers before .cpp,
    and only a real `class X {` / `struct X {` counts, so namespaces never qualify."""
    try:
        classes, _funcs = build_index(log=lambda *a: None)
    except SystemExit:
        return None  # no 2016 tree on this PC
    seen = set()
    for name in reversed(identifiers(unit)):
        if name in seen or not name[0].isupper() or name not in classes:
            continue
        seen.add(name)
        decl = re.compile(r"\b(?:class|struct)\s+(?:\w+\s+)?%s\b[^;{]*\{" % re.escape(name))
        for rel in sorted(classes[name], key=lambda r: not r.endswith((".h", ".hpp"))):
            try:
                text = (TREE / rel).read_text(errors="replace")
            except OSError:
                continue
            m = decl.search(text)
            if m:
                return "// %s\n%s" % (rel.replace("\\", "/"), "\n".join(text[m.start():].splitlines()[:lines]))
    return None


def report(unit, limit=5):
    rows = sources_for(unit, limit=limit)
    if not rows:
        print("no 2016 source matches %r" % unit)
        return 0
    print("%s ->" % unit)
    for score, rel, _text in rows[:limit]:
        print("   %s" % rel)
    return len(rows)


def summarise(client=None, limit=12):
    """How much of a client's unit vocabulary the 2016 tree can explain at all."""
    classes, funcs = build_index()
    rows = []
    for name, entry in sorted(clients.load().items()):
        if client and name != client:
            continue
        units = {}
        for row in match._functions(name).values():
            if row.get("kind", "code") == "code" and row.get("unit"):
                units[row["unit"]] = units.get(row["unit"], 0) + 1
        explained = 0
        for unit in units:
            ids = identifiers(unit)
            if ids and any(i in classes or i in funcs for i in ids if i and i[0].isupper()):
                explained += units[unit]
        total = sum(units.values())
        rows.append((name, total, explained, 100.0 * explained / total if total else 0.0))
    print("%-9s %8s %10s %8s" % ("client", "code", "explained", "%"))
    for name, total, explained, pct in rows:
        print("%-9s %8d %10d %7.1f%%" % (name, total, explained, pct))
    return rows


def main(argv=None):
    import argparse
    ap = argparse.ArgumentParser(prog="roc ref", description=__doc__)
    ap.add_argument("unit", nargs="?", help="a client unit name, e.g. RBX::VHat::?$FactoryProduct::Creator")
    ap.add_argument("--summarise", action="store_true", help="how much of each client the tree explains")
    ap.add_argument("--client", help="restrict --summarise to one client")
    ap.add_argument("--limit", type=int, default=5)
    a = ap.parse_args(argv)
    if a.summarise:
        summarise(a.client)
        return 0
    if not a.unit:
        ap.error("give a unit name or --summarise")
    report(a.unit, a.limit)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
