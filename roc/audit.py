"""Checks borrowed from reccmp (isledecomp), shaped for one-file-per-address source.

lint     decomplint + roadmap: every src/<client>/<addr>.cpp names a real function
         start, carries known build directives and points at a known recipe;
         function boundaries never overlap; plus verified-data coverage (datacmp's
         question, answered for the data our matches pin down).
vtables  every RTTI vtable with its slots and how many are matched.
ghidra   a Ghidra script that writes recovered names and match status back.

Whole-binary checks (reccmp's datacmp over every section, verexp, a relink)
need a linked rebuild, which does not exist until enough functions match.
"""
import json
import re
from pathlib import Path

from roc import clients, match

ROOT = Path(__file__).resolve().parent.parent
ADDR = re.compile(r"^[0-9a-f]{8}$")
NOTE_SYMBOL = re.compile(r"\(function (\S+)\)")
PARTIAL = re.compile(r"// from server: (\d+)% by ")


def _scores(client):
    path = ROOT / "work" / client / "scores.json"
    return json.loads(path.read_text()) if path.exists() else {}


def lint(client, show=5, log=print):
    """Problems as {category: [detail]}. Errors are categories starting with 'error'."""
    from roc import libs, setup
    funcs, scores = match._functions(client), _scores(client)
    known_builds = set(libs.BUILDS) | set(setup.compilers())
    problems = {}
    add = lambda kind, detail: problems.setdefault(kind, []).append(detail)
    folder = ROOT / "src" / client
    for path in sorted(folder.glob("*.cpp")) if folder.is_dir() else []:
        addr = path.stem
        if not ADDR.match(addr):
            add("error: file name is not an 8-digit lowercase address", path.name)
            continue
        if addr not in funcs:
            add("error: no function starts at this address", path.name)
        text = path.read_text(errors="replace")
        d = match.directives(text)
        if d.get("cl") and (not d["cl"].isdigit() or int(d["cl"]) not in known_builds):
            add("error: unknown compiler build in roc-cl", "%s (%s)" % (path.name, d["cl"]))
        for key in ("lib", "archive"):
            recipe = d.get(key, "").split(" ")[0]
            if recipe and recipe not in libs.RECIPES:
                add("error: roc-%s names an unknown recipe" % key, "%s (%s)" % (path.name, recipe))
        if d.get("lang") not in (None, "c", "cpp"):
            add("error: roc-lang must be c or cpp", path.name)
        partial = PARTIAL.match(text)
        if partial and int(partial.group(1)) < 100 and scores.get(addr) == 100:
            add("warning: scored 100 but file header says a partial attempt (roc check it)",
                "%s (%s%%)" % (path.name, partial.group(1)))
    have = {p.stem for p in folder.glob("*.cpp")} if folder.is_dir() else set()
    for addr, score in scores.items():
        if score == 100 and addr not in have:
            add("warning: scored 100 but no source file here (pull from the server)", addr)
    rows = sorted(funcs.values(), key=lambda r: int(r["addr"], 16))
    for a, b in zip(rows, rows[1:]):
        if int(a["addr"], 16) + a["size"] > int(b["addr"], 16):
            add("error: function bodies overlap (roadmap)", "%s+%d > %s" % (a["addr"], a["size"], b["addr"]))
    for kind in sorted(problems):
        items = problems[kind]
        log("%-70s %6d  e.g. %s" % (kind, len(items), ", ".join(items[:show])))
    log("data: %s" % data_coverage(client))
    return problems


def data_coverage(client):
    """Bytes of .rdata/.data/.tls pinned by verified data spans of matched functions."""
    work = ROOT / "work" / client
    spans = json.loads((work / "data.json").read_text()) if (work / "data.json").exists() else {}
    meta = json.loads((work / "meta.json").read_text()) if (work / "meta.json").exists() else {}
    covered = set()
    for rows in spans.values():
        for va, length in rows:
            covered.update(range(va, va + length))
    total = meta.get("data_bytes") or 0
    return "%d of %d bytes verified (%.2f%%)" % (len(covered), total, 100.0 * len(covered) / total if total else 0)


def vtables(client):
    """[{class, vtable, slots: [[addr, score]]}] read straight from the client exe."""
    import pefile
    from roc.analyze import reloc_sites, rtti_vtables
    pe = pefile.PE(str(clients.exe_path(client, clients.load()[client])))
    base = pe.OPTIONAL_HEADER.ImageBase
    text = next(s for s in pe.sections if s.Name.rstrip(b"\0") == b".text")
    lo = base + text.VirtualAddress
    hi = lo + text.Misc_VirtualSize
    image = pe.get_memory_mapped_image()
    read = lambda va, n: image[va - base:va - base + n] if 0 <= va - base < len(image) else b""
    scores = _scores(client)
    out = []
    for cls, vt, fns in rtti_vtables(read, reloc_sites(pe), lambda va: lo <= va < hi):
        slots = [["%08x" % fn, scores.get("%08x" % fn, 0)] for fn in fns]
        out.append({"class": cls, "vtable": "%08x" % vt, "slots": slots})
    return sorted(out, key=lambda v: v["vtable"])


def vtable_report(client, top=20, log=print):
    tables = vtables(client)
    (ROOT / "work" / client / "vtables.json").write_text(json.dumps(tables, indent=0))
    slots = sum(len(v["slots"]) for v in tables)
    done = sum(1 for v in tables for _, s in v["slots"] if s == 100)
    full = [v for v in tables if v["slots"] and all(s == 100 for _, s in v["slots"])]
    log("%s: %d vtables, %d slots, %d matched (%.1f%%), %d vtables fully matched"
        % (client, len(tables), slots, done, 100.0 * done / slots if slots else 0, len(full)))
    near = sorted((v for v in tables if v not in full and v["slots"]),
                  key=lambda v: -sum(s == 100 for _, s in v["slots"]) / len(v["slots"]))
    for v in near[:top]:
        missing = [a for a, s in v["slots"] if s < 100]
        log("  %s %-50s %d/%d  open: %s" % (v["vtable"], v["class"][:50], len(v["slots"]) - len(missing),
                                           len(v["slots"]), " ".join(missing[:6])))
    log("wrote work/%s/vtables.json" % client)
    return tables


def ghidra_names(client):
    """{addr: (name or "", comment)} from donor PDB names, library symbols and RTTI."""
    from roc import donor
    scores, out = _scores(client), {}
    for addr, row in match._functions(client).items():
        name, notes = "", []
        same = donor.hint(client, addr)
        if same and same["symbol"]:
            name = same["symbol"]
            notes.append("same bytes as WebService.dll 0x%s" % same["donor"])
        path = ROOT / "src" / client / ("%s.cpp" % addr)
        if path.exists():
            m = NOTE_SYMBOL.search(path.read_text(errors="replace")[:2000])
            name = name or (m.group(1) if m else "")
        if not row["unit"].startswith("seg_"):
            notes.append("class %s (RTTI)" % row["unit"])
        if scores.get(addr):
            notes.append("RoConstruct %d%%" % scores[addr])
        if name or notes:
            out[addr] = (name, "; ".join(notes))
    return out


GHIDRA = '''# RoConstruct names and match status for %(client)s. Run from Ghidra's Script Manager
# on the %(client)s exe. Decorated names are kept; run the Demangler analyzer afterwards.
# @category RoConstruct
from ghidra.program.model.symbol import SourceType
NAMES = %(names)s
fm = currentProgram.getFunctionManager()
named = 0
for va, (name, comment) in sorted(NAMES.items()):
    a = toAddr(va)
    f = fm.getFunctionAt(a) or createFunction(a, None)
    if f is None:
        continue
    if name:
        try:
            f.setName(name, SourceType.IMPORTED)
            named += 1
        except Exception:
            pass
    if comment:
        setPlateComment(a, "RoConstruct: " + comment)
print("RoConstruct: %%d functions annotated, %%d renamed" %% (len(NAMES), named))
'''


def ghidra(client):
    names = ghidra_names(client)
    body = "{\n%s}" % "".join("    0x%s: (%r, %r),\n" % (a, n, c) for a, (n, c) in sorted(names.items()))
    path = ROOT / "work" / client / ("ghidra_%s.py" % client.replace("-", "_"))
    path.write_text(GHIDRA % {"client": client, "names": body})
    return path, len(names)
