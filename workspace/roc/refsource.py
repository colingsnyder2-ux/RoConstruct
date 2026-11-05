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
import os
import re
import subprocess
from concurrent.futures import ThreadPoolExecutor
from collections import defaultdict
from pathlib import Path

from roc import clients, match

ROOT = Path(__file__).resolve().parent.parent
TREE = ROOT / "tools" / "roblox2016" / "src"
CACHE = ROOT / "work" / "refsource.json"
META_CACHE = ROOT / "work" / "refsource-meta.json"
LITERAL_CACHE = ROOT / "work" / "refsource-literals.json"
CROSS_CACHE = ROOT / "work" / "refsource-cross.json"
_INDEX = None
_INDEX_KEY = None
_LITERAL_INDEX = None
_LITERAL_KEY = None
_LITERAL_SEARCHED = set()

SOURCE_SUFFIXES = {".cpp", ".c", ".h", ".hpp", ".inl", ".cc", ".cxx"}
# The repo nests everything under ROBLOX2016-main/<Module>/...
SKIP_DIRS = {".git", "ThirdParty", "ThirdPartyIncluded", "UnitTest", "UnitTests",
             "Test", "Tests", "Android", "Mac", "Installer", "PrepAllForUpload"}
SKIP_DIRS_LOWER = {name.lower() for name in SKIP_DIRS} | {
    "3rdparty", "dependencies", "build", "bin", "lib", "libs", "docs", "docsource"
}


def reference_trees():
    """Small authentic source trees used when stale linker unit names mislead lookup."""
    rbxgs = ROOT / "tools" / "rbxgs" / "Client"
    openrbx = ROOT / "tools" / "openrbx" / "Client"
    source2016 = TREE / "ROBLOX2016-main"
    return {
        "rbxgs-app": rbxgs / "App", "rbxgs-net": rbxgs / "Network",
        "rbxgs-appdraw": rbxgs / "Rendering" / "AppDraw",
        "rbxgs-g3d": rbxgs / "Rendering" / "g3d" / "G3Dcpp",
        "rbxgs-glg3d": rbxgs / "Rendering" / "g3d" / "GLG3Dcpp",
        "rbxgs-renderlib": rbxgs / "Rendering" / "RenderLib",
        "openrbx-app": openrbx / "App", "openrbx-net": openrbx / "Network",
        "openrbx-appdraw": openrbx / "Rendering" / "AppDraw",
        "openrbx-renderlib": openrbx / "Rendering" / "RenderLib",
        "2016-app": source2016 / "App", "2016-net": source2016 / "Network",
        "2016-studio": source2016 / "RobloxStudio",
    }

CLASS_RE = re.compile(r"\b(?:class|struct)\s+([A-Za-z_]\w*)")
NAMESPACE_RE = re.compile(r"^\s*namespace\s+([A-Za-z_]\w*)", re.M)
INCLUDE_RE = re.compile(r"^\s*#\s*include\s+[<\"]([^>\"]+)[>\"]", re.M)
INHERIT_RE = re.compile(r"\b(?:class|struct)\s+([A-Za-z_]\w*)\s*:\s*([^\{]+)\{")
STRING_RE = re.compile(r"(?:\"([^\"\\]*(?:\\.[^\"\\]*)*)\"|'([^'\\]*(?:\\.[^'\\]*)*)')")
TOKEN_RE = re.compile(r"[A-Za-z_]\w*|\d+(?:\.\d+)?|==|!=|<=|>=|->|\+\+|--|&&|\|\||[^\s]")
# One flat character class, no nested quantifiers: the old nested form backtracked
# exponentially on long declaration lines and never finished indexing the tree.
FUNC_RE = re.compile(r"^[ \t]*[\w:<>,*& \t]*?\b([A-Za-z_]\w*)[ \t]*\(", re.M)


def _decode_literal(value):
    try:
        return bytes(value, "utf-8").decode("unicode_escape")
    except UnicodeDecodeError:
        return value


def function_facts(client, addr):
    """Read one analyzed row without loading the full matcher/PE state."""
    path = ROOT / "work" / client / "functions.jsonl"
    wanted = str(addr).lower().removeprefix("0x").zfill(8)
    try:
        for line in path.read_text().splitlines():
            row = json.loads(line)
            if row.get("addr", "").lower() == wanted:
                return row
    except (OSError, ValueError):
        pass
    return None


@functools.lru_cache(maxsize=32)
def _client_size_index(client):
    rows = defaultdict(list)
    for addr, row in match._functions(client).items():
        rows[row.get("size", 0)].append((addr, row))
    return rows


@functools.lru_cache(maxsize=8192)
def _same_size_rows(client, size):
    """Use host DB metadata when present; avoid loading every client's JSONL."""
    database = ROOT / "work" / "server.db"
    if database.exists():
        try:
            import sqlite3
            connection = sqlite3.connect(str(database))
            rows = connection.execute(
                "select addr, unit from funcs where client=? and size=?", (client, size)).fetchall()
            connection.close()
            return tuple((addr, {"size": size, "unit": unit or ""}) for addr, unit in rows)
        except (OSError, sqlite3.Error):
            pass
    return tuple(_client_size_index(client).get(size, ()))


@functools.lru_cache(maxsize=2048)
def cross_client_sources(client, addr, limit=4):
    """Stored sources for byte-identical functions in other client binaries."""
    try:
        cached = json.loads(CROSS_CACHE.read_text()).get(client, {})
        if addr in cached:
            rows = []
            for sibling in cached[addr][:limit]:
                path = Path(sibling["path"])
                if path.exists():
                    rows.append({**sibling, "text": path.read_text(errors="replace")})
            return rows
    except (OSError, ValueError, KeyError):
        pass
    facts = function_facts(client, addr)
    if not facts:
        return []
    try:
        target_code, target_relocs, _ = match.target(client, addr)
    except (KeyError, OSError, ValueError):
        return []
    rows = []
    for other in sorted(clients.load()):
        if other == client:
            continue
        for other_addr, row in _same_size_rows(other, facts.get("size")):
            try:
                code, relocs, _ = match.target(other, other_addr)
            except (KeyError, OSError, ValueError):
                continue
            if not match.exact_match(target_code, target_relocs, code, relocs):
                continue
            path = ROOT / "src" / other / (other_addr + ".cpp")
            if not path.exists():
                continue
            try:
                text = path.read_text(errors="replace")
            except OSError:
                continue
            rows.append({"client": other, "addr": other_addr, "unit": row.get("unit", ""),
                         "path": str(path), "text": text})
            if len(rows) >= limit:
                return rows
    return rows


@functools.lru_cache(maxsize=2048)
def shape_client_sources(client, addr, limit=4):
    """Stored sources with the same normalized instruction shape in another client."""
    facts = function_facts(client, addr)
    shape = (facts or {}).get("shape")
    if not shape:
        return []
    found = []
    database = ROOT / "work" / "server.db"
    if database.exists():
        try:
            import sqlite3
            connection = sqlite3.connect(str(database))
            rows = connection.execute(
                "select client,addr,unit,score from funcs where client<>? and shape=? order by score desc",
                (client, shape)).fetchall()
            connection.close()
        except (OSError, sqlite3.Error):
            rows = []
    else:
        rows = [(other, other_addr, row.get("unit", ""), 0)
                for other in clients.load() if other != client
                for other_addr, row in match._functions(other).items()
                if row.get("shape") == shape]
    for other, other_addr, unit, score in rows:
        path = ROOT / "src" / other / (other_addr + ".cpp")
        if not path.exists():
            continue
        found.append({"client": other, "addr": other_addr, "unit": unit or "",
                      "score": score or 0, "path": str(path),
                      "text": path.read_text(errors="replace")})
        if len(found) >= limit:
            break
    return found


def warm_lineage(client="2008-06", min_size=500, max_score=39, log=print):
    """Persist exact-binary cross-client source matches for one low-score queue."""
    scores_path = ROOT / "work" / client / "scores.json"
    try:
        scores = json.loads(scores_path.read_text())
        targets = [row for row in match._functions(client).values()
                   if row.get("kind", "code") == "code" and int(row.get("size", 0)) >= min_size
                   and int(scores.get(row.get("addr"), 0)) <= max_score]
    except (OSError, ValueError):
        return 0
    rows = {}
    for i, target in enumerate(targets, 1):
        addr = target["addr"]
        siblings = []
        try:
            target_code, target_relocs, _ = match.target(client, addr)
        except (KeyError, OSError, ValueError):
            rows[addr] = siblings
            continue
        for other in sorted(clients.load()):
            if other == client:
                continue
            for other_addr, row in _same_size_rows(other, target.get("size")):
                try:
                    code, relocs, _ = match.target(other, other_addr)
                except (KeyError, OSError, ValueError):
                    continue
                path = ROOT / "src" / other / (other_addr + ".cpp")
                if path.exists() and match.exact_match(target_code, target_relocs, code, relocs):
                    siblings.append({"client": other, "addr": other_addr,
                                     "unit": row.get("unit", ""), "path": str(path)})
        rows[addr] = siblings
        if i % 50 == 0:
            log("lineage: %d/%d targets" % (i, len(targets)))
    try:
        data = json.loads(CROSS_CACHE.read_text()) if CROSS_CACHE.exists() else {}
    except (OSError, ValueError):
        data = {}
    data[client] = rows
    CROSS_CACHE.parent.mkdir(parents=True, exist_ok=True)
    CROSS_CACHE.write_text(json.dumps(data, separators=(",", ":")))
    cross_client_sources.cache_clear()
    return sum(bool(value) for value in rows.values())


def _observed_strings(client="2008-06"):
    path = ROOT / "work" / client / "functions.jsonl"
    wanted = set()
    try:
        for line in path.read_text().splitlines():
            row = json.loads(line)
            wanted.update(value for value in row.get("strings", ())
                          if len(value) >= 5 and value.isprintable())
    except (OSError, ValueError):
        pass
    return wanted


def build_literal_index(strings=(), force=False, log=lambda *a: None):
    """Map exact C/C++ string literals to files across local Roblox source trees."""
    global _LITERAL_INDEX, _LITERAL_KEY, _LITERAL_SEARCHED
    trees = reference_trees()
    key = tuple(sorted((name, str(path)) for name, path in trees.items()))
    requested = {value for value in strings if len(value) >= 5 and value.isprintable()
                 and "\n" not in value and "\r" not in value}
    if _LITERAL_INDEX is None or _LITERAL_KEY != key or force:
        _LITERAL_INDEX, _LITERAL_SEARCHED, _LITERAL_KEY = {}, set(), key
    if LITERAL_CACHE.exists() and not force and not _LITERAL_SEARCHED:
        try:
            data = json.loads(LITERAL_CACHE.read_text())
            if tuple(map(tuple, data.get("trees", []))) == key:
                _LITERAL_INDEX = data["literals"]
                _LITERAL_SEARCHED = set(data.get("searched", _LITERAL_INDEX))
        except (OSError, ValueError, KeyError):
            pass
    wanted = requested - _LITERAL_SEARCHED
    if not wanted:
        return _LITERAL_INDEX
    index = defaultdict(list, {value: list(paths) for value, paths in _LITERAL_INDEX.items()})
    pattern_values = defaultdict(set)
    for value in wanted:
        if "\n" in value or "\r" in value:
            continue
        pattern_values[value].add(value)
        pattern_values[json.dumps(value)[1:-1]].add(value)
    patterns = ROOT / "work" / "refsource-literals.patterns"
    patterns.parent.mkdir(parents=True, exist_ok=True)
    patterns.write_text("\n".join(sorted(pattern_values)), encoding="utf-8")
    roots = [str(path) for path in trees.values() if path.is_dir()]
    command = ["rg", "--json", "-F", "-f", str(patterns), "-g", "*.cpp", "-g", "*.c",
               "-g", "*.cc", "-g", "*.cxx", "-g", "*.h", "-g", "*.hpp", "-g", "*.inl",
               "-g", "!roc_*", *roots]
    run = subprocess.run(command, cwd=ROOT, capture_output=True, text=True, encoding="utf-8", errors="replace")
    if run.returncode not in (0, 1):
        raise OSError(run.stderr.strip() or "rg source scan failed")
    files = set()
    resolved = [(name, path.resolve()) for name, path in trees.items() if path.is_dir()]
    for line in run.stdout.splitlines():
        try:
            event = json.loads(line)
            if event.get("type") != "match":
                continue
            path = (ROOT / event["data"]["path"]["text"]).resolve()
            owner = next(((name, root) for name, root in resolved if path.is_relative_to(root)), None)
            if not owner:
                continue
            name, root = owner
            ref = "%s:%s" % (name, path.relative_to(root).as_posix())
            files.add(ref)
            for submatch in event["data"].get("submatches", ()):
                for value in pattern_values.get(submatch["match"]["text"], ()):
                    if ref not in index[value]:
                        index[value].append(ref)
        except (KeyError, ValueError):
            continue
    result = {literal: paths for literal, paths in index.items()}
    _LITERAL_SEARCHED.update(wanted)
    LITERAL_CACHE.parent.mkdir(parents=True, exist_ok=True)
    LITERAL_CACHE.write_text(json.dumps({"trees": key, "searched": sorted(_LITERAL_SEARCHED),
                                        "literals": result}, separators=(",", ":")))
    _LITERAL_INDEX, _LITERAL_KEY = result, key
    log("indexed %d source file(s): %d target string literal(s)" % (len(files), len(result)))
    return result


def _reference_path(ref):
    name, rel = ref.split(":", 1)
    return reference_trees()[name] / rel


def _literal_snippet(ref, wanted, lines=16):
    try:
        rows = _reference_path(ref).read_text(errors="replace").splitlines()
    except (OSError, KeyError):
        return ""
    at = next((i for i, row in enumerate(rows) if any(value in row for value in wanted)), 0)
    start = max(0, at - lines // 3)
    return "\n".join(rows[start:start + lines])


def literal_sources(strings, limit=5, log=None):
    """Rank source files by exact target-string overlap, independent of stale unit labels."""
    wanted = {value for value in strings or () if len(value) >= 5 and value.isprintable()}
    if not wanted:
        return []
    index = build_literal_index(wanted, log=log or (lambda *a: None))
    files = defaultdict(set)
    for value in wanted:
        for ref in index.get(value, ()):
            files[ref].add(value)
    rows = sorted(files.items(), key=lambda item: (-len(item[1]), item[0]))[:limit]
    return [{"path": ref, "matches": sorted(values),
             "text": _literal_snippet(ref, values)} for ref, values in rows]


def warm_large(client="2008-06", min_size=500, max_score=39, log=print):
    """Cache string lookup for current large low-score queue in one source scan."""
    scores_path = ROOT / "work" / client / "scores.json"
    functions_path = ROOT / "work" / client / "functions.jsonl"
    try:
        scores = json.loads(scores_path.read_text())
        rows = (json.loads(line) for line in functions_path.read_text().splitlines())
        strings = {value for row in rows
                   if row.get("kind", "code") == "code" and int(row.get("size", 0)) >= min_size
                   and int(scores.get(row.get("addr"), 0)) <= max_score
                   for value in row.get("strings", ())}
    except (OSError, ValueError):
        return 0
    build_literal_index(strings, log=log)
    return len(strings)


def _walk(root):
    for folder, dirs, names in os.walk(root):
        dirs[:] = sorted(d for d in dirs if d.lower() not in SKIP_DIRS_LOWER)
        for name in sorted(names):
            path = Path(folder) / name
            if path.suffix.lower() in SOURCE_SUFFIXES:
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


def _target_terms(facts):
    """Identifiers from observed calls/imports only; never invent source names."""
    text = " ".join(str(value) for key, value in (facts or {}).items()
                     if key in {"call_targets", "external_calls", "imports", "siblings"})
    return tuple(sorted(set(re.findall(r"\b[A-Za-z_]\w{2,}\b", text))))


def _client_year(client):
    match = re.match(r"^(20\d\d)", str(client or ""))
    return int(match.group(1)) if match else None


def prompt_hints(unit, limit=3, max_chars=1800, target_facts=None, client=None):
    """Compact 2016 source clues for an AI prompt.

    Keep snippets bounded: source names help the model, while whole files waste
    context and hide the target assembly.
    """
    facts = target_facts or {}
    strings = tuple(sorted(facts.get("strings", [])))
    rows = []
    if client and facts.get("addr"):
        for sibling in cross_client_sources(client, facts["addr"], limit=limit):
            rows.append({"path": "cross:%s:%s" % (sibling["client"], sibling["addr"]),
                         "score": 10000, "text": sibling["text"][:max_chars], "method": "",
                         "facts": {"byte_identical": True}, "source_year": None,
                         "client_year": _client_year(client), "age_delta": None})
        for sibling in shape_client_sources(client, facts["addr"], limit=limit):
            rows.append({"path": "shape:%s:%s:%s" %
                         (sibling["client"], sibling["addr"], sibling["unit"]),
                         "score": 9000 + sibling["score"], "text": sibling["text"][:max_chars],
                         "method": "", "facts": {"shape_identical": True},
                         "source_year": None, "client_year": _client_year(client), "age_delta": None})
    rows += _prompt_hints_cached(unit, limit, max_chars, strings, _target_terms(facts),
                                int(facts.get("calls", 0) or 0), int(facts.get("branch_count", 0) or 0),
                                _client_year(client))
    seen = {row["path"] for row in rows}
    for row in literal_sources(strings, limit=limit):
        if row["path"] in seen:
            continue
        rows.append({"path": row["path"], "score": 200 + 25 * len(row["matches"]),
                     "text": row["text"][:max_chars], "method": "",
                     "facts": {"literals": row["matches"]}, "source_year": None,
                     "client_year": _client_year(client), "age_delta": None})
    rows.sort(key=lambda row: -row["score"])
    return rows[:limit]


@functools.lru_cache(maxsize=2048)
def _method_shape(text):
    """Source-level control/call shape; no guessed semantics."""
    clean = re.sub(r"//[^\n]*|/\*.*?\*/", " ", text or "", flags=re.S)
    branches = len(re.findall(r"\b(?:if|for|while|switch|catch)\s*\(", clean))
    calls = max(0, len(re.findall(r"\b[A-Za-z_]\w*(?:::[A-Za-z_]\w*)?\s*\(", clean)) - branches)
    return calls, branches


@functools.lru_cache(maxsize=2048)
def _prompt_hints_cached(unit, limit=3, max_chars=1800, wanted_strings=(), wanted_calls=(),
                         target_calls=0, target_branches=0, client_year=None):
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
    wanted_calls = set(wanted_calls)
    for score, rel, text in rows:
        text = text.strip()
        if not text:
            continue
        facts = source_facts(rel)
        overlap = len(wanted.intersection(facts.get("classes", []) + facts.get("methods", [])))
        overlap += 2 * len(wanted_strings.intersection(facts.get("literals", [])))
        overlap += 2 * len(wanted_calls.intersection(facts.get("methods", []) + facts.get("tokens", [])))
        focus = next((name for name in identifiers(unit)
                      if name in facts.get("methods", []) or name in facts.get("classes", [])), None)
        body = extract_method(rel, focus, max_chars=max_chars * 3) if focus else ""
        method_calls, method_branches = _method_shape(body or text)
        shape = max(0, 4 - abs(target_calls - method_calls))
        shape += max(0, 4 - abs(target_branches - method_branches))
        out.append({"path": rel.replace("\\", "/"), "score": score + overlap + shape,
                    "text": text[:max_chars], "method": body[:max_chars], "facts": facts})
    out.sort(key=lambda row: -row["score"])
    for item in out:
        item["source_year"] = 2016
        item["client_year"] = client_year
        item["age_delta"] = 2016 - client_year if client_year else None
    return out


def compile_candidates(client, addr, unit, flags=None, limit=2, log=None):
    """Try exact-string source hits, then 2016 hints, with the target compiler.

    Returns ``(score, source, path)`` for the best verified candidate, or None.
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
        facts = function_facts(client, addr) or {}
        for sibling in cross_client_sources(client, addr, limit=max(1, limit)):
            source = sibling["text"]
            source = re.sub(r"(?m)^//\s*roc-cl:.*$", "// roc-cl: %d" % build, source)
            source = re.sub(r"(?m)^//\s*roc-flags:.*$", "// roc-flags: %s" % flags, source)
            candidates.append((source, "cross:%s:%s" % (sibling["client"], sibling["addr"])))
        for sibling in shape_client_sources(client, addr, limit=max(1, limit)):
            source = sibling["text"]
            source = re.sub(r"(?m)^//\s*roc-cl:.*$", "// roc-cl: %d" % build, source)
            source = re.sub(r"(?m)^//\s*roc-flags:.*$", "// roc-flags: %s" % flags, source)
            candidates.append((source, "shape:%s:%s" % (sibling["client"], sibling["addr"])))
        recipe_names = {
            "rbxgs-app": ("rbxgs", ("rbxgs-dll", "rbxgs")),
            "rbxgs-net": ("rbxgs-net", ("rbxgs-net-dll", "rbxgs-net")),
            "rbxgs-g3d": ("rbxgs-g3d", ("rbxgs-g3d-dll", "rbxgs-g3d")),
            "rbxgs-glg3d": ("rbxgs-g3d", ("rbxgs-g3d-dll", "rbxgs-g3d")),
            "rbxgs-appdraw": ("rbxgs-appdraw", ("rbxgs-appdraw-dll", "rbxgs-appdraw")),
            "rbxgs-renderlib": ("rbxgs-render", ("rbxgs-render-dll", "rbxgs-render")),
            "openrbx-app": (None, ("openrbx-client-dll", "openrbx-client")),
            "openrbx-net": (None, ("openrbx-client-dll", "openrbx-client")),
            "openrbx-appdraw": (None, ("openrbx-client-dll", "openrbx-client")),
            "openrbx-renderlib": (None, ("openrbx-client-dll", "openrbx-client")),
        }
        literal_flags = "/O2 /Ob2 /Oy /GF /GS- /EHsc /MD"
        literal_limit = max(limit, 4)
        hits = literal_sources(facts.get("strings", ()), limit=max(4, limit))
        for hit in hits:
            # One short/common literal creates many costly false source hits.
            if len(hit["matches"]) == 1 and len(hit["matches"][0]) < 12:
                continue
            prefix = hit["path"].split(":", 1)[0]
            target = _reference_path(hit["path"]).resolve()
            if target.suffix.lower() not in {".c", ".cc", ".cpp", ".cxx"}:
                continue
            unit_recipe, names = recipe_names.get(prefix, (None, ()))
            generated_unit = None
            if unit_recipe:
                generated_unit = libs.add_unit(unit_recipe, "#define private public\n" + target.read_text(errors="replace"),
                                               prefix="roc_refsource_%s_" % target.stem.lower())
            for name in names:
                row = libs.RECIPES.get(name)
                if not row:
                    continue
                folder = (libs.LIBS / row["src"]).resolve()
                if not target.is_relative_to(folder):
                    continue
                path = generated_unit or str(target.relative_to(folder)).replace("\\", "/")
                lang = "c" if target.suffix.lower() == ".c" else "cpp"
                for candidate_build in dict.fromkeys((build, 50727)):
                    candidates.append((libs.source_for(name, path, lang, candidate_build, literal_flags),
                                       "%s#%s-%s" % (hit["path"], name, candidate_build)))
                    if len(candidates) >= literal_limit:
                        break
                if len(candidates) >= literal_limit:
                    break
            if len(candidates) >= literal_limit:
                break
        for _hint_score, rel, _snippet in sources_for(unit, limit=max(limit * 4, limit), log=log):
            if len(candidates) >= literal_limit:
                break
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
                if direct_attempts >= 1:
                    continue
                direct_attempts += 1
                try:
                    if log:
                        log("  preparing 2016 source: %s" % rel)
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

        literal_candidates = bool(candidates and "#" in candidates[0][1])
        candidates = candidates[:literal_limit if literal_candidates else limit]

        # Old MSVC /fp:fast often changes x87 scheduling enough to double scores.
        # Restrict retry to floating-point targets and strong source lineages.
        if (literal_candidates or any(rel.startswith("shape:") for _source, rel in candidates)) and any(
                op in facts.get("shape", "") for op in (" fld ", " fst", " fmul", " fadd", " fsub", " fdiv")):
            fast = []
            for source, rel in candidates:
                if not (literal_candidates or rel.startswith("shape:")) or "/fp:fast" in source:
                    continue
                candidate = re.sub(r"(?m)^(//\s*roc-flags:.*)$", r"\1 /fp:fast", source, count=1)
                if candidate != source:
                    fast.append((candidate, rel + "#fp-fast"))
            candidates += fast

        def verify(item):
            source, rel = item
            if log:
                log("  compiling source: %s" % rel)
            try:
                score = match.check_text(client, addr, source, flags)[0]
            except (match.CompileError, OSError, SystemExit) as error:
                if log:
                    log("  source candidate failed: %s" % str(error).splitlines()[0])
                return None
            return score, source, rel

        if candidates:
            with ThreadPoolExecutor(max_workers=min(4, len(candidates))) as pool:
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
    ap.add_argument("--addr", help="rank source by exact strings from this client function")
    ap.add_argument("--warm-large", action="store_true", help="cache source ranking for large low-score functions")
    ap.add_argument("--limit", type=int, default=5)
    a = ap.parse_args(argv)
    if a.summarise:
        summarise(a.client)
        return 0
    if a.addr:
        client = a.client or "2008-06"
        row = function_facts(client, a.addr)
        if not row:
            ap.error("unknown %s function %s" % (client, a.addr))
        for source in literal_sources(row.get("strings", []), limit=a.limit, log=print):
            print("%d %s %s" % (len(source["matches"]), source["path"], repr(source["matches"])))
        return 0
    if a.warm_large:
        print("cached %d target string(s)" % warm_large(a.client or "2008-06"))
        return 0
    if not a.unit:
        ap.error("give a unit name or --summarise")
    report(a.unit, a.limit)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
