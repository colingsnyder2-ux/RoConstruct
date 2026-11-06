"""Write durable evidence for the local exact RunService notifier raise body.

Reads the saved native_check_runner result and reanalysis; does not compile.
"""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[4]
RUN = ROOT / "work/2008-06/native-check-runs/20261105-145712-c902c37a"
BATCH = ROOT / "work/2008-06/shared-layouts/runservice-raise-00554ae0/batch.json"
OUT = ROOT / "work/2008-06/shared-layouts/runservice-raise-00554ae0/receipt.json"
ADDR = "00554ae0"
SYMBOL = "?raise@?$Notifier@VRunService@RBX@@W4RunState@2@@RBX@@IBEXW4RunState@2@@Z"
CALLEE = ("?raise@?$Notifier@VRunService@RBX@@W4RunState@2@@RBX@@"
          "IBEXW4RunState@2@PAV?$Listener@VRunService@RBX@@W4RunState@2@@2@@Z")


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


results = json.loads((RUN / "results.json").read_text())
analysis = json.loads((RUN / "analysis-23ee74c2.json").read_text())
source = next(row for row in results if row["source"].endswith("RunService.cpp"))
check = next(row for row in analysis if row["source"].endswith("RunService.cpp"))["checks"]
check = next(row for row in check if row["addr"] == ADDR)
assert check["status"] == "exact", check
assert check["call_identity"]["passed"] is False  # indirect call at +71 remains separate
direct = next(row for row in check["call_identity"]["calls"] if row["offset"] == 83)
assert direct["status"] == "verified_binding" and direct["target"] == "00554750"
indirect = next(row for row in check["call_identity"]["calls"] if row["offset"] == 71)
assert indirect["status"] == "unresolved_or_wrong_binding"
assert sha(ROOT / source["source"]) == source["source_sha256"]
paths = [ROOT / source["source"],
         ROOT / "rebuild/2008-06/native-headers/util/RunStateOwner.h",
         ROOT / "rebuild/2008-06/native-headers/util/Events.h",
         ROOT / "rebuild/2008-06/native-headers/util/GuidItem.h",
         ROOT / "rebuild/2008-06/native-headers/v8tree/Instance.h"]
receipt = {
    "scope": ("Inactive original-MSVC byte/data proof for one RunService notifier body; "
              "direct callee binding verified, indirect IAT call and runtime ABI remain unproven."),
    "address": ADDR,
    "symbol": SYMBOL,
    "size": check["object_size"],
    "target_sha256": check["target_sha256"],
    "object_sha256": hashlib.sha256((RUN / "unit-000/candidate.obj").read_bytes()).hexdigest(),
    "exact_masked_bytes": True,
    "referenced_data_matches": check["data_matches"],
    "referenced_data_errors": check["data_errors"],
    "direct_calls": [{
        "offset": 83,
        "target": "00554750",
        "symbol": CALLEE,
        "status": "verified_binding",
    }],
    "indirect_calls": [{
        "offset": 71,
        "target": "IAT 0x802890",
        "symbol": "MSVCR90.dll!_invalid_parameter_noinfo",
        "status": "separate proof required",
    }],
    "compiler_build": "21022",
    "flags": source["flags"],
    "source_sha256": source["source_sha256"],
    "inputs": {str(path.relative_to(ROOT)): sha(path) for path in paths},
    "batch_sha256": sha(BATCH),
    "run": str(RUN.relative_to(ROOT)),
    "results_sha256": sha(RUN / "results.json"),
    "analysis_sha256": sha(RUN / "analysis-23ee74c2.json"),
    "next_obligation": ("Prove caller/provider selection and callee ABI for "
                        "Notifier<RunService, RunState>::raise; no runtime or server claim."),
}
OUT.write_text(json.dumps(receipt, indent=2) + "\n")
print(json.dumps({"receipt": str(OUT.relative_to(ROOT)), "exact": True,
                  "direct_calls": 1, "indirect_calls": 1}, indent=2))
