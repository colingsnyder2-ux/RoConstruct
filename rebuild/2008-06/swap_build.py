"""Phase 2, stage 1: compile each swap-plan group exactly as mining verified it and find, per target address,
the symbol in that object that is byte-identical (code and referenced data) to the 2008 function.
Only groups whose recipe shares the module's headers, from real source files, are taken (an exact function carries its class
layouts; rbxgs-app uses rbxgs headers, rbx-app uses OpenRBX headers).
Writes out/<Module>/verified/<n>.obj plus out/<Module>/verified/swaps.json:
  [{"obj": "<n>.obj", "keep": {symbol: addr}}]
usage: python rebuild/2008-06/swap_build.py MODULE [LIMIT]"""
import json
import re
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import match  # noqa: E402

CLIENT = "2008-06"
RECIPES = {"RbxgsApp": {"rbxgs", "rbxgs-dll"}, "RbxApp": {"openrbx-client", "openrbx-client-dll"}}
OUT = ROOT / "rebuild" / CLIENT / "out"


ALIAS = re.compile(r'#pragma\s+include_alias\(\s*"([^"]+)"\s*,\s*"([^"]+)"\s*\)')
TREES = {"RbxgsApp": ROOT / "tools" / "rbxgs" / "Client" / "App"}
PATCHES = {"RbxgsApp": ROOT / "rebuild" / CLIENT / "patches" / "rbxgs-client.json"}


def adopted(module):
    """{header under include/: replacement unit file name} from the module's @replace overlay patches."""
    if module not in PATCHES or not PATCHES[module].exists():
        return {}
    out = {}
    for rel, edits in json.loads(PATCHES[module].read_text()).items():
        for old, new in edits:
            if old == "@replace":
                out[rel.split("/include/", 1)[-1]] = new.rsplit("/", 1)[-1]
    return out


def compatible(module, unit):
    if not unit.rsplit("/", 1)[-1].startswith("roc_"):
        return True
    src = TREES.get(module, Path("-")) / unit
    if not src.exists():
        return False
    aliases = ALIAS.findall(src.read_text(errors="replace"))
    have = adopted(module)
    return bool(aliases) and all(have.get(h) == r.rsplit("/", 1)[-1] for h, r in aliases)


def build_group(item):
    text = (ROOT / "src" / CLIENT / (item["addrs"][0] + ".cpp")).read_text(errors="replace")
    try:
        obj = match.compile_text(CLIENT, text)
    except Exception as error:  # noqa: BLE001 - report and continue with the other groups
        return item, None, {}, str(error)[:300]
    keep = {}
    for addr in item["addrs"]:
        value, symbol, _, _ = match.check_text(CLIENT, addr, text, obj=obj)
        if value == 100 and symbol:
            keep.setdefault(symbol, addr)
    return item, obj, keep, None


def main(module, limit=None):
    plan = json.loads((OUT / "swap-plan.json").read_text())
    # generated analog units (roc_*) encode recovered 2008 layouts: take one only when every header it aliases
    # is a header the module adopted with that same replacement (Phase 4 canonical headers)
    groups = [g for g in plan["groups"] if g["recipe"] in RECIPES[module] and compatible(module, g["file"])][:limit]
    folder = OUT / module / "verified"
    folder.mkdir(parents=True, exist_ok=True)
    for old in folder.glob("*.obj"):
        old.unlink()
    swaps, failed, wanted, found = [], [], 0, 0
    with ThreadPoolExecutor(8) as pool:
        for n, (item, obj, keep, error) in enumerate(pool.map(build_group, groups)):
            wanted += len(item["addrs"])
            if error:
                failed.append({"file": item["file"], "cl": item["cl"], "flags": item["flags"], "error": error})
                continue
            found += len(set(keep.values()))
            if keep:
                name = "%04d.obj" % n
                (folder / name).write_bytes(obj)
                swaps.append({"obj": name, "recipe": item["recipe"], "file": item["file"], "keep": keep})
    (folder / "swaps.json").write_text(json.dumps({"swaps": swaps, "failed": failed}, indent=1))
    print("%s: %d groups, %d/%d addresses found exact, %d groups failed to compile"
          % (module, len(groups), found, wanted, len(failed)))


if __name__ == "__main__":
    main(sys.argv[1], int(sys.argv[2]) if len(sys.argv) > 2 else None)
