"""Batch partial-source fingerprinting from already verified library evidence."""
import argparse
import hashlib
import json
import re
import sqlite3
import time
from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path

from roc import worker

ROOT = Path(__file__).resolve().parent.parent
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


def main():
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


if __name__ == "__main__":
    main()
