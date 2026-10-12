"""Mass matching: compile a whole source file once, then compare every function it
produces against every open function of the same size in a client exe.

Used for library code (zlib, Lua, ...), STL instantiations, and copying matches to
identical functions. Only byte-identical results count, with a strict rule: every
place the exe has a relocated address must also be a relocation in the compiled
object, so a constant can never pass for an address. Matches are saved as normal
src/<client>/<addr>.cpp files, so `roc check` and the server verify them unchanged.
"""
import argparse
import hashlib
import json
import re
import sqlite3
import time
from bisect import bisect_left
from collections import Counter, defaultdict, deque
from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path

from roc import clients, libs, match, setup, worker


ROOT = Path(__file__).resolve().parent.parent

def open_index(client):
    """{size: [addr, ...]} of real-code functions not yet matched."""
    path = ROOT / "work" / client / "scores.json"
    scores = json.loads(path.read_text()) if path.exists() else {}
    index = {}
    for r in match._functions(client).values():
        if r["kind"] == "code" and scores.get(r["addr"], 0) < 100:
            index.setdefault(r["size"], []).append(r["addr"])
    return index

class Target:
    """One client's exe bytes and relocations, ready for fast comparisons."""

    def __init__(self, client):
        self.client = client
        self.base, self.image = match._image(client)
        self.relocs = sorted(match._base_relocs(client))
        self.index = open_index(client)

    def exe_relocs(self, va, size):
        lo, hi = bisect_left(self.relocs, va), bisect_left(self.relocs, va + size)
        return {r - va for r in self.relocs[lo:hi]}

    def same(self, addr, code, relocs):
        """Exe function at addr equals code (masked), with exe relocs a subset of the object's."""
        va = int(addr, 16)
        exe_rel = self.exe_relocs(va, len(code))
        if not exe_rel <= set(relocs):
            return None
        exe = bytes(self.image[va - self.base:va - self.base + len(code)])
        return exe if match.masked(exe, relocs) == match.masked(code, relocs) else None

    def match_obj(self, obj, source, data_check=True):
        """{addr: (source, symbol, data spans)} for every object function found in the exe."""
        found = {}
        for name, code, relocs in match.coff_functions(obj):
            if len(code) < 6:  # too short to say anything (a lone ret matches everywhere)
                continue
            for addr in self.index.get(len(code), []):
                if addr in found:
                    continue
                exe = self.same(addr, code, relocs)
                if exe is None:
                    continue
                spans, bad = (match.data_check(self.client, addr, exe, match.coff_data_refs(obj, name))
                              if data_check else ([], []))
                if not bad:
                    found[addr] = (source, name, spans)
        for addr in found:  # matched functions leave the pool
            self.index[len(match.target(self.client, addr)[0])].remove(addr)
        return found

def save(client, found, note):
    """Write matches into src/<client>/. Returns how many were new.
    `found` only holds functions that were open (score < 100), so an existing file
    there is an unverified attempt and the exact match replaces it."""
    new = 0
    for addr, (source, symbol, spans) in found.items():
        path = ROOT / "src" / client / ("%s.cpp" % addr)
        match.save_score(client, addr, 100)
        match.save_data(client, addr, spans)
        header = match.template(client, addr).split("\n\n")[0]
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text("%s\n// %s (function %s)\n\n%s" % (header, note, symbol, source))
        new += 1
    return new


# --- families ---
# Small clean-room grouping for repeated machine-code function shapes.

_OP = re.compile(r"^\S+\s+\S+\s+([a-z][a-z0-9]*)\b", re.I)


def opcode_shape(asm):
    """Return opcode-only shape; operands/addresses stay target-specific."""
    return tuple(match.group(1).lower() for line in asm or ()
                 for match in [_OP.match(line)] if match)


def family_key(row, asm):
    """Group same-sized functions with the same opcode sequence."""
    return (int(row.get("size", 0) or 0), opcode_shape(asm))


def fingerprint(row, asm):
    """Stable wire-safe family id: size plus ordered opcode shape."""
    size, ops = family_key(row, asm)
    text = "%d:%s" % (size, ",".join(ops))
    return hashlib.sha256(text.encode("ascii")).hexdigest()[:24]


def representatives(rows, disassemble, minimum=2):
    """Return one deterministic representative per repeated family."""
    groups = defaultdict(list)
    for row in rows:
        key = family_key(row, disassemble(row))
        groups[key].append(row)
    out = []
    for key, members in groups.items():
        if len(members) >= minimum:
            out.append((key, sorted(members, key=lambda row: row["addr"])[0], members))
    return sorted(out, key=lambda item: (item[0][0], item[1]["addr"]))


# --- shapes ---
# Count the assembly shapes of unmatched functions, so pattern templates can be chosen

HEX = re.compile(r"^0x[0-9a-f]+$")


NUM = re.compile(r"^\d+$")


MEMOFF = re.compile(r"(\+ 0x[0-9a-f]+|\+ \d+)")


def norm_line(line):
    """One asm line with addresses and immediates generalised."""
    text = line.strip()
    if not text:
        return ""
    head, _, rest = text.partition(" ")
    if not rest.strip():
        return head
    parts = []
    for token in rest.split(","):
        token = token.strip()
        if HEX.match(token) or NUM.match(token):
            parts.append("#")
        else:
            parts.append(MEMOFF.sub("+ #", token))
    return "%s %s" % (head, ", ".join(parts))


def shape_from_lines(lines, drop_ret_operand=True):
    """Shape of already-disassembled lines. Split out from shape_of so the
    normalisation can be reasoned about (and tested) without an exe or a compiler."""
    kept = []
    for line in lines:
        text = line.strip()
        head, _, rest = text.partition(" ")
        # `ret 8` and `ret` are the same shape: the cleanup is implied by the arguments,
        # and a shape that distinguished them would split a family in two.
        kept.append(head if head == "ret" else norm_line(text))
    # collapse runs of identical lines: a constructor's chain of zero-inits repeats
    out = []
    for line in kept:
        if not out or out[-1] != line:
            out.append(line)
    return tuple(out)


def shape_of(code, relocs, drop_ret_operand=True):
    """Normalised shape of a function's assembly."""
    return shape_from_lines(match.asm_lines(code, relocs), drop_ret_operand)


def collect(client, max_size=None, kind="code"):
    """{shape: [addr, ...]} for unmatched functions of one client."""
    scores = match._scores(client) if hasattr(match, "_scores") else None
    import json
    from pathlib import Path
    path = Path("work") / client / "scores.json"
    scores = json.loads(path.read_text()) if path.exists() else {}
    out = defaultdict(list)
    for addr, row in match._functions(client).items():
        if row.get("kind", "code") != kind or scores.get(addr, 0) >= 100:
            continue
        if max_size and row["size"] > max_size:
            continue
        code, relocs, _ = match.target(client, addr)
        out[shape_of(code, relocs)].append((addr, row["size"], row["unit"]))
    return out


def report(clients_wanted=(), max_size=48, show=3, top=25):
    reg = clients.load()
    names = sorted(reg) if "all" in clients_wanted or not clients_wanted else list(clients_wanted)
    total = Counter()
    where = defaultdict(set)
    examples = {}
    per_client = {}
    for client in names:
        shapes = collect(client, max_size=max_size)
        per_client[client] = {s: len(v) for s, v in items()}
        for shape, addrs in items():
            total[shape] += len(addrs)
            where[shape].add(client)
            if shape not in examples:
                examples[shape] = (client, addrs[0])
    for client in names:
        n = sum(per_client[client].values())
        print("%-8s %d unmatched function(s) up to %d bytes, %d distinct shape(s)"
              % (client, n, max_size, len(per_client[client])))
    print()
    print("Top shapes overall (a template for one of these matches every copy of it):")
    for rank, (shape, count) in enumerate(total.most_common(top), 1):
        covered = sum(per_client[c].get(shape, 0) for c in where[shape])
        client, (addr, size, unit) = examples[shape]
        print("%3d. %5d function(s) in %d client(s)  %s" % (rank, count, len(where[shape]),
                                                            ", ".join(sorted(where[shape]))))
        for line in shape[:show]:
            print("       %s" % line)
        if len(shape) > show:
            print("       ... (%d more instructions, %d bytes in %s %s)"
                  % (len(shape) - show, size, client, addr))
        print()
    print("A single template for the top shape would match %d functions." % total.most_common(1)[0][1]
          if total else "no unmatched small functions")
    return total, where, per_client


def shapes_main(argv=None):
    ap = argparse.ArgumentParser(prog="roc shapes", description=__doc__)
    ap.add_argument("name", nargs="?", default="all")
    ap.add_argument("--size", type=int, default=48, help="only functions up to this many bytes")
    ap.add_argument("--top", type=int, default=25)
    ap.add_argument("--show", type=int, default=3, help="instructions of each shape to print")
    a = ap.parse_args(argv)
    report([a.name], max_size=a.size, show=a.show, top=a.top)


# --- batch fingerprint ---
# Batch partial-source fingerprinting from already verified library evidence.

REF = re.compile(r"(// roc-lang: (?:c|cpp)\n// roc-cl: \d+\n// roc-flags: [^\n]+\n// roc-(?:lib|archive): [^\n]+)")


def source_family(source):
    recipe = source.rsplit(": ", 1)[-1].split(" ", 1)[0].lower()
    if recipe.startswith("xtp-"):
        return "xtp"
    if recipe.startswith("mfc-") or recipe.startswith("atl-"):
        return "mfc-atl"
    if "boost" in recipe:
        return "boost"
    if "g3d" in recipe:
        return "g3d"
    if "raknet" in recipe:
        return "raknet"
    if "lua" in recipe:
        return "lua"
    if "jpeg" in recipe:
        return "jpeg"
    if "png" in recipe:
        return "png"
    if recipe.startswith(("rbx", "openrbx")):
        return "roblox"
    return recipe.split("-", 1)[0]


def unit_family(unit):
    if unit.startswith(("CXTP", "CXT", "XTPPaintThemes::")):
        return "xtp"
    if unit.startswith("boost::"):
        return "boost"
    if unit.startswith("G3D::"):
        return "g3d"
    if unit.startswith("RakNet"):
        return "raknet"
    if unit.startswith(("Ogre::", "Ogre")):
        return "ogre"
    if unit.startswith(("Scintilla", "CScintilla")):
        return "scintilla"
    if unit.startswith(("Wm", "WildMagic")):
        return "wildmagic"
    if unit.startswith(("Lua::", "lua::")):
        return "lua"
    if unit.startswith(("RBX::", "rbx::", "Roblox")):
        return "roblox"
    return None


def source_class(source):
    path = source.rsplit(": ", 1)[-1].split(" ", 1)[-1]
    token = re.sub(r"[^a-z0-9]", "", Path(path).stem.lower())
    prefixes = ("ogre",) if source_family(source) == "ogre" else ("cxtp", "xtp", "rbx", "c")
    for prefix in prefixes:
        if token.startswith(prefix) and len(token) > len(prefix) + 3:
            token = token[len(prefix):]
            break
    return token if len(token) >= 5 else None


def unit_has_class(unit, token):
    if unit_family(unit) == "ogre":
        return unit_class(unit) == token
    value = re.sub(r"[^a-z0-9]", "", unit.lower())
    for prefix in ("cxtp", "xtp", "rbx", "c"):
        if value.startswith(prefix) and len(value) > len(prefix) + 3:
            value = value[len(prefix):]
            break
    return token in value


def unit_class(unit):
    """Strict leaf class token, excluding containing namespaces."""
    value = re.sub(r"[^a-z0-9]", "", unit.rsplit("::", 1)[-1].lower())
    prefixes = ("ogre",) if unit_family(unit) == "ogre" else ("cxtp", "xtp", "rbx", "c")
    for prefix in prefixes:
        if value.startswith(prefix) and len(value) > len(prefix) + 3:
            return value[len(prefix):]
    return value


def cross_client_batches(db):
    """Transfer exact source evidence only between identical named class families."""
    refs = {}
    for client, unit, source in db.execute("SELECT client,unit,source FROM funcs WHERE score=100 AND source IS NOT NULL"):
        found = REF.search(source)
        if not unit or not found:
            continue
        source = found.group(1)
        family, token = source_family(source), source_class(source)
        if token and unit_family(unit) == family and unit_class(unit) == token:
            refs.setdefault((family, token, source), set()).add(client)
    targets = {}
    for client, unit, addr, source in db.execute(
            "SELECT client,unit,addr,source FROM funcs WHERE score<100 ORDER BY client,unit,addr"):
        if not unit or not unit_family(unit):
            continue
        found = REF.search(source or "")
        targets.setdefault((unit_family(unit), unit_class(unit)), {}).setdefault(client, []).append(
            (addr, found.group(1) if found else None))
    for (family, token, source), origins in sorted(refs.items()):
        for client, rows in targets.get((family, token), {}).items():
            if client in origins:
                continue
            addrs = sorted(addr for addr, previous in rows if previous != source)
            for start in range(0, len(addrs), 1000):
                yield client, source, addrs[start:start + 1000]


def batches(db, partials=False):
    refs = {}
    labels = {}
    for client, unit, source in db.execute("SELECT client,unit,source FROM funcs WHERE score=100 AND source IS NOT NULL"):
        match = REF.search(source)
        if unit and match:
            source = match.group(1)
            refs.setdefault((client, source), set()).add(unit)
            labels.setdefault((client, unit), set()).add(source_family(source))
    open_by_unit = {}
    condition = "score BETWEEN 1 AND 99" if partials else "score=0"
    for client, unit, addr, source in db.execute(
            "SELECT client,unit,addr,source FROM funcs WHERE " + condition + " ORDER BY client,unit,addr"):
        found = REF.search(source or "")
        open_by_unit.setdefault((client, unit), []).append((addr, found.group(1) if found else None))
    for (client, source), units in refs.items():
        family = source_family(source)
        units = {unit for unit in units
                 if (unit_family(unit) or family) == family and family in labels[(client, unit)]}
        token = source_class(source)
        class_units = {unit for unit in units if token and unit_has_class(unit, token)}
        if class_units:
            units = class_units
        addrs = sorted(addr for unit in units for addr, previous in open_by_unit.get((client, unit), [])
                       if not partials or previous != source)
        for start in range(0, len(addrs), 1000):
            group = addrs[start:start + 1000]
            if group:
                yield client, source, group


def flag_batches(db):
    """Try measured frame/inlining flags on exact-evidenced named classes."""
    evidence = set()
    for unit, source in db.execute("SELECT unit,source FROM funcs WHERE score=100 AND source IS NOT NULL"):
        found = REF.search(source)
        if not unit or not found:
            continue
        source = found.group(1)
        family, token = source_family(source), source_class(source)
        if token and unit_family(unit) == family and unit_class(unit) == token:
            evidence.add((family, token, source.rsplit(": ", 1)[-1]))
    groups = {}
    for client, addr, unit, source in db.execute(
            "SELECT client,addr,unit,source FROM funcs WHERE score BETWEEN 40 AND 99 AND source IS NOT NULL"):
        found = REF.search(source)
        if not unit or not found:
            continue
        source = found.group(1)
        family, token = source_family(source), source_class(source)
        if (family not in {"xtp", "roblox"} or unit_family(unit) != family or unit_class(unit) != token
                or (family, token, source.rsplit(": ", 1)[-1]) not in evidence):
            continue
        flags = re.search(r"// roc-flags: ([^\n]+)", source).group(1)
        flags = " ".join(flag for flag in flags.split() if not flag.startswith(("/Ob", "/Oy"))) + " /Ob1 /Oy-"
        candidate = re.sub(r"// roc-flags: [^\n]+", "// roc-flags: " + flags, source)
        if candidate != source:
            groups.setdefault((client, candidate), set()).add(addr)
    for (client, source), addrs in sorted(groups.items()):
        addrs = sorted(addrs)
        for start in range(0, len(addrs), 1000):
            yield client, source, addrs[start:start + 1000]


def scope(planned, families=(), clients_=()):
    """Narrow a planned batch stream to the requested families and clients.

    Batches are keyed on the source's recipe family, so scoping lets a single
    library unit (for example raknet) be swept exhaustively instead of sharing
    selection slots with every other family.
    """
    families = {value.lower() for value in families}
    clients_ = set(clients_)
    for client, source, addrs in planned:
        if clients_ and client not in clients_:
            continue
        if families and source_family(source) not in families:
            continue
        yield client, source, addrs


def key(client, source, addrs):
    return hashlib.sha256((client + "\0" + source + "\0" + ",".join(addrs)).encode()).hexdigest()


def pending_batches(planned, state):
    """Resume by source/target pair even when progress changes batch membership."""
    done = set(state.get("done", []))
    checked = state.get("checked", {})
    for client, source, addrs in planned:
        if key(client, source, addrs) in done:
            continue
        previous = set(checked.get(key(client, source, []), ()))
        remaining = [addr for addr in addrs if addr not in previous]
        if remaining:
            item = client, source, remaining
            yield item, key(*item)


def run_one(server, token, user, item):
    client, source, addrs = item
    payload = {"user": user, "worker": "batch-fingerprint", "model": "roc fingerprint",
               "client": client, "source": source, "addrs": addrs}
    for attempt in range(3):
        try:
            result = worker.Api(server, token).call("/v1/submit-batch", payload, timeout=180)
            break
        except worker.ApiFailure:
            if attempt == 2:
                raise
            time.sleep(5 * (attempt + 1))
    rows = result["results"]
    return client, source, len(addrs), sum(row["improved"] for row in rows), max((row["score"] for row in rows), default=0)


def batch_main():
    parser = argparse.ArgumentParser(description="Batch-score known library sources against open same-unit functions.")
    parser.add_argument("--workers", type=int, default=2)
    parser.add_argument("--max-batches", type=int, default=0)
    mode = parser.add_mutually_exclusive_group()
    mode.add_argument("--partials", action="store_true",
                        help="try other exact same-unit sources against existing partial matches")
    mode.add_argument("--cross-client", action="store_true",
                      help="try foreign exact sources against identical named classes/families")
    mode.add_argument("--c-sources", action="store_true",
                      help="fingerprint C library sources using exact same-unit evidence")
    mode.add_argument("--frame-flags", action="store_true",
                      help="try measured /Ob1 /Oy- flags on exact-evidenced XTP/Roblox classes")
    parser.add_argument("--family", action="append", default=[],
                        help="only run sources from this recipe family (repeatable, e.g. raknet)")
    parser.add_argument("--client", action="append", default=[],
                        help="only run batches for this client (repeatable)")
    parser.add_argument("--server", help="override saved server address")
    args = parser.parse_args()
    settings = worker.load_settings()
    state_name = "batch-fingerprint-flags.json" if args.frame_flags else (
        "batch-fingerprint-c.json" if args.c_sources else (
        "batch-fingerprint-cross-client.json" if args.cross_client else (
        "batch-fingerprint-partials.json" if args.partials else "batch-fingerprint.json")
    ))
    state_path = ROOT / "work" / state_name
    state = json.loads(state_path.read_text()) if state_path.exists() else {"done": []}
    done = set(state.get("done", []))
    checked = {marker: set(addrs) for marker, addrs in state.get("checked", {}).items()}
    db = sqlite3.connect("file:work/server.db?mode=ro", uri=True)
    planned = (flag_batches(db) if args.frame_flags else
               cross_client_batches(db) if args.cross_client else batches(db, partials=args.partials))
    if args.c_sources:
        planned = (item for item in planned if item[1].startswith("// roc-lang: c\n"))
    if args.family or args.client:
        planned = scope(planned, args.family, args.client)
    todo = list(pending_batches(planned, state))
    if args.max_batches:
        todo = todo[:args.max_batches]
    print("queued", len(todo), flush=True)
    with ThreadPoolExecutor(max_workers=max(1, args.workers)) as pool:
        jobs = {pool.submit(run_one, args.server or settings["server"], settings.get("token"), settings["user"], item): (item, marker)
                for item, marker in todo}
        for future in as_completed(jobs):
            item, marker = jobs[future]
            try:
                client, source, targets, improved, best = future.result()
                print(client, source_family(source), targets, "improved", improved, "best", best,
                      source.splitlines()[-1], flush=True)
                done.add(marker)
                checked.setdefault(key(client, source, []), set()).update(item[2])
                temporary = state_path.with_suffix(".json.tmp")
                temporary.write_text(json.dumps({"done": sorted(done),
                                                "checked": {k: sorted(v) for k, v in checked.items()}},
                                               separators=(",", ":")))
                temporary.replace(state_path)
            except Exception as error:
                print("ERROR", repr(error), flush=True)


# --- deep fingerprint ---
# Bounded, resumable expansion of exact-evidenced library/class searches.

def flag_variants(source):
    flags = source.splitlines()[2].split(': ', 1)[1]
    keep = [flag for flag in flags.split()
            if flag not in {'/O1', '/O2', '/Ox', '/Od', '/Ob0', '/Ob1', '/Ob2', '/Oy', '/Oy-'}]
    yield flags
    for optimization in ('/O2 /Ob0 /Oy-', '/O2 /Ob1 /Oy-', '/O2 /Ob2 /Oy-',
                         '/O2 /Ob1 /Oy', '/O1 /Ob1 /Oy-', '/Ox /Ob2 /Oy-',
                         '/O2 /Ob2 /Oy', '/Od /Ob0 /Oy-'):
        candidate = ' '.join([*keep, optimization])
        if candidate != flags:
            yield candidate


def local_versions(families):
    """No downloads: index installed recipes, excluding Wild Magic's local-only source."""
    versions = defaultdict(list)
    for name, recipe in sorted(libs.RECIPES.items()):
        family = source_family('// roc-lib: ' + name + ' file.cpp')
        folder = libs.LIBS / recipe['src'] if recipe.get('src') else None
        if (family not in families or family == 'wildmagic' or recipe.get('archive') is True
                or folder is None or not folder.is_dir()):
            continue
        for path in libs.files_of(recipe, folder):
            relative = Path(path).as_posix()
            if not (folder / relative).is_file():
                continue
            token = source_class('// roc-lib: ' + name + ' ' + relative)
            if token:
                versions[family, token].append((name, relative))
    return versions


def plan(db, min_score=85, targets=8, families=()):
    families = {value.lower() for value in families}
    evidence, labels = defaultdict(set), defaultdict(set)
    for client, unit, text in db.execute('SELECT client,unit,source FROM funcs WHERE score=100 AND source IS NOT NULL'):
        found = REF.search(text)
        if not unit or not found:
            continue
        source = found.group(1)
        family = source_family(source)
        if families and family not in families:
            continue
        structural = unit_family(unit)
        if family == 'wildmagic' or (structural and structural != family):
            continue
        if structural and source_class(source) != unit_class(unit):
            continue
        evidence[family, unit_class(unit)].add(source)
        labels[client, unit].add(family)
    groups = defaultdict(list)
    for client, addr, unit, score, text in db.execute(
            'SELECT client,addr,unit,score,source FROM funcs WHERE score>=? AND score<100 ORDER BY score DESC,client,addr',
            (min_score,)):
        family = unit_family(unit or '')
        if family is None:
            proven = labels.get((client, unit), set())
            family = next(iter(proven)) if len(proven) == 1 else None
        if not family or (family, unit_class(unit)) not in evidence:
            continue
        if families and family not in families:
            continue
        found = REF.search(text or '')
        groups[client, family, unit_class(unit)].append((addr, score, found.group(1) if found else None))
    versions = local_versions({family for _, family, _ in groups})
    have, registry = set(setup.compilers()), clients.load()
    # Round-robin families so a pilot is not consumed by one large XTP class.
    queues = defaultdict(deque)
    for (client, family, token), rows in sorted(groups.items(), key=lambda item: -item[1][0][1]):
        seeds = sorted(evidence[family, token])
        recipes = []
        for source in seeds:
            name, path = source.splitlines()[-1].split(': ', 1)[1].split(' ', 1)
            recipes.append((name, path, source))
        for name, path in versions.get((family, token), []):
            if not any(name == n and path == p for n, p, _ in recipes):
                recipes.append((name, path, seeds[0]))
        per_recipe = []
        for name, path, seed in recipes:
            recipe = libs.RECIPES.get(name)
            if not recipe or recipe.get('archive') is True:
                continue
            language = seed.splitlines()[0].split(': ', 1)[1]
            if language not in recipe.get('langs', []):
                continue
            original = int(seed.splitlines()[1].split(': ', 1)[1])
            builds = [registry.get(client, {}).get('compiler_build'), original, *sorted(have)]
            builds = list(dict.fromkeys(b for b in builds if b in have and b in recipe.get('builds', libs.BUILDS)))
            variants = deque()
            for flags in dict.fromkeys(flag_variants(seed)):
                for build in builds:
                    candidate = libs.source_for(name, path, language, build, flags).strip()
                    if candidate not in variants:
                        variants.append(candidate)
            per_recipe.append(variants)
        candidates = []
        seen = set()
        # Try one candidate per installed version before exhausting a version's flag grid.
        while any(per_recipe):
            for variants in per_recipe:
                if variants:
                    candidate = variants.popleft()
                    if candidate not in seen:
                        seen.add(candidate)
                        candidates.append(candidate)
        for start in range(0, len(rows), targets):
            group = rows[start:start + targets]
            # All variants for this group run before expanding to lower-priority targets.
            for candidate in candidates:
                addrs = [addr for addr, _, previous in group if previous != candidate]
                if addrs:
                    queues[family].append((client, candidate, addrs))
    while any(queues.values()):
        for family in sorted(queues):
            if queues[family]:
                yield queues[family].popleft()


def deep_main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--max-batches', type=int, default=24, help='pilot bound; 0 means all pending batches')
    parser.add_argument('--min-score', type=int, default=85)
    parser.add_argument('--targets', type=int, default=8)
    parser.add_argument('--family', action='append', default=[],
                        help='only expand library sources from this recipe family (repeatable)')
    parser.add_argument('--client', action='append', default=[],
                        help='only expand targets for this client (repeatable)')
    parser.add_argument('--server', default='http://127.0.0.1:8765')
    parser.add_argument('--dry-run', action='store_true')
    args = parser.parse_args()
    if not 0 <= args.min_score <= 99 or args.targets < 1 or args.max_batches < 0:
        parser.error('min-score must be 0..99; targets positive; max-batches nonnegative')
    state_path = ROOT / 'work/deep-fingerprint.json'
    state = json.loads(state_path.read_text()) if state_path.exists() else {}
    # Reuse fast-pass pair checkpoints without modifying their live state files.
    prior = {marker: set(addrs) for marker, addrs in state.get('checked', {}).items()}
    for path in (ROOT / 'work').glob('batch-fingerprint*.json'):
        for marker, addrs in json.loads(path.read_text()).get('checked', {}).items():
            prior.setdefault(marker, set()).update(addrs)
    state['checked'] = {marker: sorted(addrs) for marker, addrs in prior.items()}
    db = sqlite3.connect('file:%s?mode=ro' % (ROOT / 'work/server.db').as_posix(), uri=True)
    todo = list(pending_batches(scope(plan(db, args.min_score, args.targets), args.family, args.client), state))
    db.close()
    print('pending', len(todo), 'batches', flush=True)
    if args.max_batches:
        todo = todo[:args.max_batches]
    print('selected', len(todo), 'batches', sum(len(item[2]) for item, _ in todo), 'source/target checks', flush=True)
    if args.dry_run:
        return
    settings = worker.load_settings()
    api = worker.Api(args.server, settings.get('token'))
    started, checks, gains, exact = time.monotonic(), 0, 0, 0
    improved_functions = set()
    by_family = {}
    done = set(state.get('done', []))
    checked = {marker: set(addrs) for marker, addrs in state.get('checked', {}).items()}
    for item, marker in todo:
        client, source, addrs = item
        tick = time.monotonic()
        print('checking', client, source_family(source), len(addrs), source.splitlines()[1:3], source.splitlines()[-1], flush=True)
        try:
            result = api.call('/v1/submit-batch', {'user': settings['user'], 'worker': 'deep-fingerprint',
                              'model': 'roc deep fingerprint', 'client': client, 'source': source, 'addrs': addrs}, timeout=180)
        except worker.ApiFailure as error:
            print('ERROR', str(error), 'batch remains pending', flush=True)
            continue
        rows = result['results']
        if not result.get('verified'):
            raise RuntimeError('Deep pass requires server-verified scoring')
        # A partial response must not permanently skip targets the server never checked.
        returned = {row['addr'] for row in rows} & set(addrs)
        checked.setdefault(key(client, source, []), set()).update(returned)
        if returned == set(addrs):
            done.add(marker)
        changed = [row for row in rows if row['improved']]
        checks += len(returned)
        gains += len(changed)
        improved_functions.update((client, row['addr']) for row in changed)
        exact += sum(row['stored'] == 100 for row in changed)
        family_stats = by_family.setdefault(source_family(source), {'checks': 0, 'gains': 0, 'exact': 0, 'seconds': 0})
        family_stats['checks'] += len(returned)
        family_stats['gains'] += len(changed)
        family_stats['exact'] += sum(row['stored'] == 100 for row in changed)
        family_stats['seconds'] += time.monotonic() - tick
        print('result', 'checks', len(returned), 'improved', len(changed),
              'exact', sum(row['stored'] == 100 for row in changed), 'seconds', round(time.monotonic() - tick, 2), flush=True)
        state.update(done=sorted(done), checked={k: sorted(v) for k, v in checked.items()},
                     last_run={'checks': checks, 'improvement_events': gains,
                               'unique_improved': len(improved_functions), 'new_exact': exact,
                               'seconds': round(time.monotonic() - started, 2), 'families': by_family})
        temporary = state_path.with_suffix('.json.tmp')
        temporary.write_text(json.dumps(state, separators=(',', ':')))
        temporary.replace(state_path)
    elapsed = time.monotonic() - started
    print('SUMMARY', 'checks', checks, 'improvement_events', gains, 'unique_improved', len(improved_functions), 'new_exact', exact,
          'seconds', round(elapsed, 2), 'events_per_hour', round(gains * 3600 / max(elapsed, 0.001), 2), flush=True)
