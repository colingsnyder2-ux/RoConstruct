"""Check a selective module against a frozen baseline and run isolated milestones."""
import json
import shutil
import sys
from pathlib import Path
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import rebuild

CLIENT = "2008-06"
MODULE = "rbxgs-app-openrbx-selective"
OUT = ROOT / "rebuild/2008-06/out/RbxgsAppOpenRBXSelective"
RUNTIME = ROOT / "work/openrbx-selective-codex"
# The donor file uses a shorter name than the existing 2008 object.
OWNER_NAMES = {"SerializerSelected": "SerializerV2"}

def groups_from_swaps():
    groups = {}
    for entry in read(OUT / "verified/swaps.json")["swaps"]:
        obj = entry["obj"]
        if not obj.startswith("selective_"):
            continue
        selected = obj[len("selective_"):-len(".obj")]
        owner = OWNER_NAMES.get(selected, selected.removesuffix("Selected"))
        groups.setdefault(owner, set()).update({owner.lower() + ".obj", "verified_" + obj.lower()})
    return groups

def read(path):
    return json.loads(path.read_text())

def owned_by(bindings, names):
    return {addr for addr, entries in bindings.items()
            if any(entry["object"].lower() in names for entry in entries)}

def verify(baseline):
    before = read(baseline / "report.json")
    old_symbols = read(baseline / "owned-symbols.json")
    report = read(OUT / "report.json")
    symbols = read(OUT / "owned-symbols.json")
    if not before.get("linked") or before.get("test_exit") != 0:
        raise RuntimeError("Baseline did not link and pass smoke")
    if not report.get("linked") or report.get("test_exit") != 0 or report.get("owned_2008") is None:
        raise RuntimeError("Trial did not link, pass smoke, and complete scoring")
    old, new = set(before["owned_addrs"]), set(report["owned_addrs"])
    lost = old - new
    groups = {}
    for original, names in groups_from_swaps().items():
        prior, current = owned_by(old_symbols, names), owned_by(symbols, names)
        if prior or current:
            groups[original] = {"gained": sorted(current - prior), "lost": sorted(prior - current)}
    object_losses = {name: value["lost"] for name, value in groups.items() if value["lost"]}
    if lost or object_losses:
        raise RuntimeError("Ownership loss: " + json.dumps({"global": sorted(lost), "objects": object_losses}))
    result = {"before": len(old), "after": len(new), "gained": sorted(new - old),
              "lost": sorted(lost), "objects": groups, "milestones": {}}
    if not result["gained"]:
        raise RuntimeError("No new owned addresses; milestones skipped")

    original_ws, original_link, original_dump = rebuild.workspace, rebuild.link_test, rebuild._dump
    def isolated_link(client, test, *args, **kwargs):
        dst = RUNTIME / "tests" / (test + ".cpp")
        dst.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(original_ws(client) / "tests" / (test + ".cpp"), dst)
        dlls = original_ws(client) / "out/tests" / test
        target = RUNTIME / "out/tests" / test
        target.mkdir(parents=True, exist_ok=True)
        for dll in dlls.glob("*.dll"):
            shutil.copy2(dll, target / dll.name)
        with patch.object(rebuild, "workspace", lambda _: RUNTIME):
            return original_link(client, test, *args, **kwargs)
    def isolated_dump(path, data):
        return original_dump(OUT / "milestones.json" if Path(path).name == "milestones.json" else path, data)
    milestones = {k: (test, MODULE) for k, (test, _) in rebuild.MILESTONES.items()}
    with patch.object(rebuild, "MILESTONES", milestones), patch.object(rebuild, "link_test", isolated_link), patch.object(rebuild, "_dump", isolated_dump):
        results = rebuild.milestones(CLIENT, log=lambda message: print(message, flush=True))
    result["milestones"] = {name: row["passed"] for name, row in results.items()}
    (OUT / "batch-verification.json").write_text(json.dumps(result, indent=2) + "\n")
    if not all(result["milestones"].values()):
        raise RuntimeError("Runtime milestone failed: " + json.dumps(result["milestones"]))
    return result

if __name__ == "__main__":
    if len(sys.argv) != 2:
        raise SystemExit("usage: python verify_trial.py BASELINE_DIRECTORY")
    print(json.dumps(verify(Path(sys.argv[1])), indent=2))
