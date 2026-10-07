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
from concurrent.futures import ThreadPoolExecutor
from collections import defaultdict
from pathlib import Path

from roc import clients, match

ROOT = Path(__file__).resolve().parent.parent
TREE = ROOT / "tools" / "roblox2016" / "src"
CACHE = ROOT / "work" / "refsource.json"
META_CACHE = ROOT / "work" / "refsource-meta.json"
_INDEX = None
_INDEX_KEY = None

SOURCE_SUFFIXES = {".cpp", ".c", ".h", ".hpp", ".inl", ".cc", ".cxx"}
# The repo nests everything under ROBLOX2016-main/<Module>/...
SKIP_DIRS = {".git", "ThirdParty", "ThirdPartyIncluded", "UnitTest", "UnitTests",
             "Test", "Tests", "Android", "Mac", "Installer", "PrepAllForUpload"}

CLASS_RE = re.compile(r"\b(?:class|struct)\s+([A-Za-z_]\w*)")
NAMESPACE_RE = re.compile(r"^\s*namespace\s+([A-Za-z_]\w*)", re.M)
INCLUDE_RE = re.compile(r"^\s*#\s*include\s+[<\"]([^>\"]+)[>\"]", re.M)
INHERIT_RE = re.compile(r"\b(?:class|struct)\s+([A-Za-z_]\w*)\s*:\s*([^\{]+)\{")
STRING_RE = re.compile(r"(?:\"([^\"\\]*(?:\\.[^\"\\]*)*)\"|'([^'\\]*(?:\\.[^'\\]*)*)')")
TOKEN_RE = re.compile(r"[A-Za-z_]\w*|\d+(?:\.\d+)?|==|!=|<=|>=|->|\+\+|--|&&|\|\||[^\s]")
# One flat character class, no nested quantifiers: the old nested form backtracked
# exponentially on long declaration lines and never finished indexing the tree.
FUNC_RE = re.compile(r"^[ \t]*[\w:<>,*& \t]*?\b([A-Za-z_]\w*)[ \t]*\(", re.M)


def _walk(root):
    for path in sorted(root.rglob("*")):
        if path.suffix.lower() not in SOURCE_SUFFIXES or not path.is_file():
            continue
        if any(part in SKIP_DIRS for part in path.parts):
            continue
        yield path


def build_index(force=False, log=print):
    """{class name: [paths]}, {function name: [paths]} over the 2016 source tree."""
    global _INDEX, _INDEX_KEY
    key = (str(TREE), str(CACHE))
    if _INDEX is not None and _INDEX_KEY == key and not force:
        return _INDEX
    if CACHE.exists() and not force:
        try:
            data = json.loads(CACHE.read_text())
            if data.get("files") == str(TREE):
                _INDEX = (data["classes"], data["funcs"])
                _INDEX_KEY = key
                return _INDEX
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
        for name in set(FUNC_RE.findall(text)):
            if len(name) > 2:
                funcs[name].append(rel)
    data = {"files": str(TREE),
            "classes": {k: sorted(set(v)) for k, v in classes.items()},
            "funcs": {k: sorted(set(v)) for k, v in funcs.items()}}
    CACHE.parent.mkdir(parents=True, exist_ok=True)
    CACHE.write_text(json.dumps(data, separators=(",", ":")))
    log("indexed %d source file(s): %d class/namespace name(s), %d function name(s)"
        % (n, len(data["classes"]), len(data["funcs"])))
    _INDEX = (data["classes"], data["funcs"])
    _INDEX_KEY = key
    return _INDEX


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
            found.append((100 + len(name), rel, snippet(rel, focus=name)))
    for name in _plausible(names, funcs):
        if len(found) >= limit * 2:
            break
        for rel in funcs[name][:limit]:
            if rel in seen:
                continue
            seen.add(rel)
            found.append((50 + len(name), rel, snippet(rel, focus=name)))
    found.sort(key=lambda r: -r[0])
    return found


def snippet(rel, lines=12, focus=None):
    """Small relevant source window for a hint in a prompt."""
    path = TREE / rel
    try:
        rows = path.read_text(errors="replace").splitlines()
    except OSError:
        return ""
    if focus:
        matches = [i for i, row in enumerate(rows) if re.search(r"\b%s\b" % re.escape(focus), row)]
        if matches:
            center = matches[0]
            start = max(0, center - lines // 3)
            return "\n".join(rows[start:start + lines])
    return "\n".join(rows[:lines])


@functools.lru_cache(maxsize=2048)
def source_facts(rel):
    """Bounded declarations/body clues for a retrieved source file."""
    try:
        text = (TREE / rel).read_text(errors="replace")
    except OSError:
        return {}
    names = sorted(set(CLASS_RE.findall(text)))[:32]
    methods = sorted(set(FUNC_RE.findall(text)))[:48]
    inherits = ["%s:%s" % (name, bases.strip()) for name, bases in INHERIT_RE.findall(text)][:16]
    literals = []
    for left, right in STRING_RE.findall(text):
        value = left or right
        if len(value) >= 4:
            literals.append(value[:120])
    tokens = TOKEN_RE.findall(re.sub(r"//[^\n]*|/\*.*?\*/", " ", text, flags=re.S))
    shape = " ".join("I" if re.match(r"^[A-Za-z_]", token) else
                      "N" if re.match(r"^\d", token) else token for token in tokens[:512])
    clean = re.sub(r"//[^\n]*|/\*.*?\*/", " ", text, flags=re.S)
    nodes = []
    for match in re.finditer(r"\b(class|struct|namespace)\s+([A-Za-z_]\w*)", clean):
        nodes.append({"kind": match.group(1), "name": match.group(2),
                      "offset": match.start()})
    for match in re.finditer(r"\b([A-Za-z_]\w*(?:::\w+)*)\s*\([^;{}]{0,240}\)\s*\{", clean):
        name = match.group(1).split("::")[-1]
        if name not in ("if", "for", "while", "switch", "catch"):
            nodes.append({"kind": "function", "name": name, "offset": match.start()})
    nodes.sort(key=lambda node: node["offset"])
    return {"classes": names, "methods": methods,
            "includes": sorted(set(INCLUDE_RE.findall(text)))[:24],
            "inherits": inherits, "literals": sorted(set(literals))[:24],
            "tokens": sorted(set(re.findall(r"\b[A-Za-z_]\w{2,}\b", text)))[:96],
            "ast_shape": shape, "ast_nodes": nodes[:256],
            "parser": "roc-cpp-structure-v1"}


def build_meta(force=False, log=print):
    """Persist compact source-token/declaration metadata for similarity retrieval."""
    if META_CACHE.exists() and not force:
        try:
            data = json.loads(META_CACHE.read_text())
            if data.get("files") == str(TREE):
                return len(data.get("rows", {}))
        except (OSError, ValueError, KeyError):
            pass
    import hashlib
    paths = list(_walk(TREE))
    partial = META_CACHE.with_suffix(".partial.json")
    rows = {}
    if force and partial.exists():
        try:
            saved = json.loads(partial.read_text())
            if saved.get("files") == str(TREE):
                rows = saved.get("rows", {})
                log("resuming source metadata: %d files" % len(rows))
        except (OSError, ValueError, KeyError):
            rows = {}
    paths = [path for path in paths if str(path.relative_to(TREE)) not in rows]

    def one(path):
        rel = str(path.relative_to(TREE))
        facts = source_facts(rel)
        tokens = " ".join(facts.get("tokens", []))
        row = {k: facts.get(k, []) for k in ("classes", "methods", "includes", "inherits", "literals", "ast_nodes")}
        row["token_hash"] = hashlib.sha256(tokens.encode()).hexdigest()
        row["ast_shape"] = facts.get("ast_shape", "")
        row["parser"] = facts.get("parser", "roc-cpp-structure-v1")
        row["token_count"] = len(facts.get("tokens", []))
        return rel, row

    from concurrent.futures import ThreadPoolExecutor
    with ThreadPoolExecutor(max_workers=4) as pool:
        for i, (rel, row) in enumerate(pool.map(one, paths), 1):
            rows[rel] = row
            if i % 5000 == 0:
                log("source metadata: %d files" % i)
            if force and i % 2000 == 0:
                partial.write_text(json.dumps({"files": str(TREE), "rows": rows}, separators=(",", ":")))
    data = {"files": str(TREE), "rows": rows}
    META_CACHE.parent.mkdir(parents=True, exist_ok=True)
    META_CACHE.write_text(json.dumps(data, separators=(",", ":")))
    try:
        partial.unlink()
    except OSError:
        pass
    return len(rows)


def extract_method(rel, name, max_chars=6000):
    """Return one bounded C/C++ method body from a source file, if present."""
    try:
        text = (TREE / rel).read_text(errors="replace")
    except OSError:
        return ""
    match = re.search(r"\b%s\s*\([^;{}]*\)\s*(?:const\s*)?\{" % re.escape(name), text)
    if not match:
        return ""
    open_brace = text.find("{", match.start(), match.end())
    depth, i, quote = 0, open_brace, None
    while i < len(text):
        ch = text[i]
        if quote:
            if ch == "\\":
                i += 2
                continue
            if ch == quote:
                quote = None
        elif ch in "\"'":
            quote = ch
        elif ch == "{":
            depth += 1
        elif ch == "}":
            depth -= 1
            if depth == 0:
                return text[match.start():min(i + 1, match.start() + max_chars)]
        i += 1
    return text[match.start():match.start() + max_chars]


def extract_method_context(rel, name, max_chars=12000):
    """Return a method plus its nearest in-file class declaration when available."""
    method = extract_method(rel, name, max_chars=max_chars)
    if not method:
        return ""
    try:
        text = (TREE / rel).read_text(errors="replace")
    except OSError:
        return method
    at = text.find(method[: min(80, len(method))])
    if at < 0:
        return method
    classes = list(re.finditer(r"\b(?:class|struct)\s+[A-Za-z_]\w*\s*\{", text[:at]))
    if not classes:
        return method
    start = classes[-1].start()
    brace = text.find("{", start, at)
    depth, i = 0, brace
    while i < at:
        if text[i] == "{":
            depth += 1
        elif text[i] == "}":
            depth -= 1
        i += 1
    declaration = text[start:at] if depth > 0 else ""
    return (declaration + method)[-max_chars:] if declaration else method


@functools.lru_cache(maxsize=1024)
def hint(unit, lines=60):
    """The 2016 declaration of the class behind a unit, for the AI worker's prompt, or None.

    Innermost name first (`RBX::Network::Replicator` -> Replicator), headers before .cpp,
    and only a real `class X {` / `struct X {` counts, so namespaces never qualify."""
    if not unit or unit.startswith("seg_"):
        return None
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


def prompt_hints(unit, limit=3, max_chars=1800, target_facts=None):
    """Compact 2016 source clues for an AI prompt.

    Keep snippets bounded: source names help the model, while whole files waste
    context and hide the target assembly.
    """
    strings = tuple(sorted((target_facts or {}).get("strings", [])))
    return _prompt_hints_cached(unit, limit, max_chars, strings)


@functools.lru_cache(maxsize=2048)
def _prompt_hints_cached(unit, limit=3, max_chars=1800, wanted_strings=()):
    """Cached prompt lookup; workers often revisit the same unit across retries."""
    out = []
    if not unit or unit.startswith("seg_"):
        return []
    try:
        rows = sources_for(unit, limit=limit)
    except SystemExit:
        return []
    wanted = set(identifiers(unit))
    wanted_strings = set(wanted_strings)
    for score, rel, text in rows:
        text = text.strip()
        if not text:
            continue
        facts = source_facts(rel)
        overlap = len(wanted.intersection(facts.get("classes", []) + facts.get("methods", [])))
        overlap += 2 * len(wanted_strings.intersection(facts.get("literals", [])))
        focus = next((name for name in identifiers(unit)
                      if name in facts.get("methods", []) or name in facts.get("classes", [])), None)
        body = extract_method(rel, focus, max_chars=max_chars * 3) if focus else ""
        out.append({"path": rel.replace("\\", "/"), "score": score + overlap,
                    "text": text[:max_chars], "method": body[:max_chars], "facts": facts})
    out.sort(key=lambda row: -row["score"])
    return out


def compile_candidates(client, addr, unit, flags=None, limit=2, log=None):
    """Try source-tree files directly with the target client's compiler.

    Returns ``(score, source, path)`` for the best verified candidate, or None.
    Only files belonging to a local rbx2016 library recipe are considered; source
    outside those recipes remains prompt-only evidence.
    """
    try:
        from roc import libs
        info = clients.load()[client]
        build = int(info["compiler_build"])
        flags = flags or info.get("flags", "")
        best = None
        candidates = []
        direct_attempts = 0
        tried = 0
        for _hint_score, rel, _snippet in sources_for(unit, limit=max(limit * 4, limit), log=log):
            if Path(rel).suffix.lower() not in {".c", ".cc", ".cpp", ".cxx"}:
                continue
            target = (TREE / rel).resolve()
            recipe = None
            for name, row in libs.RECIPES.items():
                if not name.startswith("rbx2016-"):
                    continue
                folder = (libs.LIBS / row["src"]).resolve()
                if target.is_relative_to(folder):
                    recipe = (name, row, target.relative_to(folder))
                    break
            if not recipe:
                if direct_attempts >= 2:
                    continue
                direct_attempts += 1
                try:
                    root = TREE / "ROBLOX2016-main"
                    include = ";".join(str(p) for p in (root, root / "Rendering/g3d/include",
                                                           root / "Network/raknet/Source"))
                    body = libs.preprocess(build, target, include)
                    candidates.append(("// roc-lang: cpp\n// roc-cl: %d\n// roc-flags: %s\n%s" %
                                      (build, flags, body), rel))
                    focus = next((n for n in identifiers(unit) if n in source_facts(rel).get("methods", [])), None)
                    context = extract_method_context(rel, focus) if focus else ""
                    if context:
                        candidates.append(("// roc-lang: cpp\n// roc-cl: %d\n// roc-flags: %s\n%s" %
                                           (build, flags, context), rel + "#method"))
                except (match.CompileError, OSError, SystemExit):
                    pass
                continue
            tried += 1
            if tried > limit:
                break
            name, row, path = recipe
            if row.get("builds") and build not in row["builds"]:
                continue
            lang = row.get("langs", ["cpp"])[0]
            relpath = str(path).replace("\\", "/")
            source = libs.source_for(name, relpath, lang, build, flags)
            candidates.append((source, rel))

        def verify(item):
            source, rel = item
            try:
                score, _ = match.check_text(client, addr, source, flags)
            except (match.CompileError, OSError, SystemExit):
                return None
            return score, source, rel

        if candidates:
            with ThreadPoolExecutor(max_workers=min(2, len(candidates))) as pool:
                for result in pool.map(verify, candidates):
                    if result and (best is None or result[0] > best[0]):
                        best = result
        return best
    except (KeyError, OSError, SystemExit, ValueError):
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
