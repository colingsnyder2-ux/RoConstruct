"""Find selective candidates in already compiled donor objects; no source or build changes."""
import argparse
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import rebuild

parser = argparse.ArgumentParser()
parser.add_argument("baseline", type=Path, help="frozen directory with report.json")
parser.add_argument("objects", type=Path, nargs="+", help="already compiled donor object files")
parser.add_argument("--output", type=Path, help="write candidate results as JSON")
args = parser.parse_args()
client = "2008-06"
spec = rebuild.load_module(client, "rbxgs-app-openrbx-selective")
out = rebuild.workspace(client) / "out" / spec["name"]
before = json.loads((args.baseline / "report.json").read_text())
if not before.get("linked") or before.get("test_exit") != 0 or not before.get("owned_addrs"):
    raise SystemExit("Baseline must be linked, scored and smoke-tested")
owned = set(before["owned_addrs"])
identities = json.loads((ROOT / "work/2008-06/identity-registry.json").read_text())
excluded = set(spec.get("verified_exclude", []))
for name in ("excluded.json", "vdrop.json"):
    path = out / "verified" / name
    if path.exists():
        excluded.update(json.loads(path.read_text()))
counts, seen = {}, set()
for layer in spec["layers"]:
    for obj in sorted((out / ("layer-" + layer["name"])).glob("*.obj")):
        if obj.name in seen:
            continue
        seen.add(obj.name)
        for symbol, defined in rebuild.coff_externals(obj.read_bytes()).items():
            if defined:
                counts[symbol] = counts.get(symbol, 0) + 1
rows = []
for obj in args.objects:
    for symbol, size, addresses in rebuild.pair_object(client, obj.read_bytes()):
        if len(addresses) != 1 or addresses[0] in owned:
            continue
        addr = addresses[0]
        if identities.get(addr, {}).get("name") != symbol:
            continue
        definitions = counts.get(symbol, 0)
        if symbol in excluded or definitions != 1:
            continue
        rows.append({"object": str(obj), "address": addr, "symbol": symbol,
                     "size": size, "existing_definitions": definitions})
rows.sort(key=lambda row: (row["object"], row["address"]))
result = {"scope": "candidate only: masked code/data and identity; ABI, calls, selection and runtime not proven",
          "baseline_owned": len(owned), "candidates": rows}
if args.output:
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2) + "\n")
print(json.dumps(result, indent=2))
