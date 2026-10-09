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
REF = re.compile(r"(// roc-lang: cpp\n// roc-cl: \d+\n// roc-flags: [^\n]+\n// roc-(?:lib|archive): [^\n]+)")


def source_family(source):
    recipe = source.rsplit(": ", 1)[-1].split(" ", 1)[0].lower()
    if recipe.startswith("xtp-"):
        return "xtp"
    if recipe.startswith("mfc-") or recipe.startswith("atl-"):
        return "mfc-atl"
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
    if recipe.startswith("rbx"):
        return "roblox"
    return recipe.split("-", 1)[0]


def unit_family(unit):
    if unit.startswith(("CXTP", "CXT")):
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
    for prefix in ("cxtp", "xtp", "rbx", "c"):
        if token.startswith(prefix) and len(token) > len(prefix) + 3:
            token = token[len(prefix):]
            break
    return token if len(token) >= 5 else None


def unit_has_class(unit, token):
    value = re.sub(r"[^a-z0-9]", "", unit.lower())
    for prefix in ("cxtp", "xtp", "rbx", "c"):
        if value.startswith(prefix) and len(value) > len(prefix) + 3:
            value = value[len(prefix):]
            break
    return token in value


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


def key(client, source, addrs):
    return hashlib.sha256((client + "\0" + source + "\0" + ",".join(addrs)).encode()).hexdigest()


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
    parser.add_argument("--partials", action="store_true",
                        help="try other exact same-unit sources against existing partial matches")
    parser.add_argument("--server", help="override saved server address")
    args = parser.parse_args()
    settings = worker.load_settings()
    state_path = ROOT / "work" / ("batch-fingerprint-partials.json" if args.partials else "batch-fingerprint.json")
    state = json.loads(state_path.read_text()) if state_path.exists() else {"done": []}
    done = set(state.get("done", []))
    db = sqlite3.connect("file:work/server.db?mode=ro", uri=True)
    todo = [(item, key(*item)) for item in batches(db, partials=args.partials)]
    todo = [(item, marker) for item, marker in todo if marker not in done]
    if args.max_batches:
        todo = todo[:args.max_batches]
    print("queued", len(todo), flush=True)
    with ThreadPoolExecutor(max_workers=max(1, args.workers)) as pool:
        jobs = {pool.submit(run_one, args.server or settings["server"], settings.get("token"), settings["user"], item): marker
                for item, marker in todo}
        for future in as_completed(jobs):
            marker = jobs[future]
            try:
                client, source, targets, improved, best = future.result()
                print(client, source_family(source), targets, "improved", improved, "best", best,
                      source.splitlines()[-1], flush=True)
                done.add(marker)
                state_path.write_text(json.dumps({"done": sorted(done)}, separators=(",", ":")))
            except Exception as error:
                print("ERROR", repr(error), flush=True)


if __name__ == "__main__":
    main()
