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
RECIPE_PREFIXES = {"XTP": ("xtp-11.2.2",), "G3D": ("g3d-6.09",), "Boost": ("boost-1.34.1",), "libpng": ("libpng-1.2",),
                   "Lua": ("lua-5.1",)}


def of_module(module, recipe):
    return recipe in RECIPES.get(module, ()) or recipe.startswith(RECIPE_PREFIXES.get(module, ()))


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


OVERLAY_ROOTS = {"RbxgsApp": ROOT / "tools" / "rbxgs" / "Client"}


def overlay_candidate(module, unit):
    """A generated unit whose aliases disagree with the adopted headers: it can still be tried against the module's
    own (overlay) headers, which now carry the 2008 layouts its private header copies stood in for."""
    src = TREES.get(module, Path("-")) / unit
    return module in OVERLAY_ROOTS and unit.rsplit("/", 1)[-1].startswith("roc_") and src.exists() \
        and bool(ALIAS.search(src.read_text(errors="replace")))


def compile_against_overlay(module, item, n):
    """The unit with every include_alias removed, compiled with the recipe's settings but the module overlay's copy
    of each include folder first: its functions then use exactly the headers the module links with. Only those still
    byte-exact are kept (check_text decides)."""
    from roc import libs
    root, overlay = OVERLAY_ROOTS[module].resolve(), OUT / module / "overlay"
    text = ALIAS.sub("", (TREES[module] / item["file"]).read_text(errors="replace"))
    path = OUT / module / "remap" / ("%04d-%s" % (n, item["file"].rsplit("/", 1)[-1]))
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text)
    r, folder = libs.RECIPES[item["recipe"]], libs.fetch(item["recipe"]).resolve()
    dirs = [folder] + [Path(libs.winsdk_include()) if i == "WINSDK" else libs._case_path(libs.LIBS / i)
                       for i in r.get("include", [])]
    include = []
    for d in dirs:
        d = Path(d).resolve()
        if d.is_relative_to(root) and (overlay / d.relative_to(root)).exists():
            include.append(str(overlay / d.relative_to(root)))
        include.append(str(d))
    build = int(item["cl"]) if item["cl"].isdigit() else match.clients.load()[CLIENT]["compiler_build"]
    body = libs.preprocess(build, path, ";".join(include), r.get("defines", ""))
    return match._compile(body, item["flags"] or match.DEFAULT_FLAGS, build, False)


# The modules link against the DLL CRT (/MD). A group mining verified with a recipe that leaves _DLL undefined (static
# CRT headers) carries inline STL/CRT code with another ABI (CRT data not imported, e.g. std::_BADOFF): recompile it with
# its _DLL twin and keep only what is still byte-exact.
DLL_TWIN = {"rbxgs": "rbxgs-dll", "openrbx-client": "openrbx-client-dll"}


def libs_recipes():
    from roc import libs
    return libs.RECIPES


def build_group(job):
    module, n, item = job
    text = (ROOT / "src" / CLIENT / (item["addrs"][0] + ".cpp")).read_text(errors="replace")
    twin = DLL_TWIN.get(item["recipe"])
    if twin is None and "_DLL" not in libs_recipes().get(item["recipe"], {}).get("defines", "")             and item["recipe"] + "-dll" in libs_recipes():
        twin = item["recipe"] + "-dll"  # e.g. g3d-6.09 -> g3d-6.09-dll
    if twin:
        item = dict(item, recipe=twin)
        text = re.sub(r"(?m)^(// roc-lib: )%s " % re.escape(job[2]["recipe"]), r"\g<1>%s " % twin, text)
    try:
        obj = compile_against_overlay(module, item, n) if item.get("overlay") else match.compile_text(CLIENT, text)
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
    # is a header the module adopted with that same replacement (Phase 4 canonical headers); one that disagrees is
    # compiled against the module's overlay headers instead (compile_against_overlay)
    groups = []
    for g in plan["groups"]:
        if not of_module(module, g["recipe"]):
            continue
        if compatible(module, g["file"]):
            groups.append(g)
        elif overlay_candidate(module, g["file"]):
            groups.append(dict(g, overlay=True))
    groups = groups[:limit]
    folder = OUT / module / "verified"
    folder.mkdir(parents=True, exist_ok=True)
    for old in folder.glob("*.obj"):
        old.unlink()
    swaps, failed, wanted, found = [], [], 0, 0
    with ThreadPoolExecutor(8) as pool:
        for n, (item, obj, keep, error) in enumerate(pool.map(build_group, [(module, i, g) for i, g in enumerate(groups)])):
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
