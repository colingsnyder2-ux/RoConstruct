"""Build reviewed direct-call bindings for the 26 TToolVerb factory exacts.

Inputs
  work/2008-06/native-check-runs/20261106-103103-6be7bd3a/{results,summary}.json
  work/2008-06/shared-layouts/*.json            (prior per-tool reviewed bindings)

Outputs
  rebuild/2008-06/tests/tool-verb-factories-unit-20261106.json   (manifest + calls)
  work/2008-06/shared-layouts/tool-verb-factories-unit-20261106.json (receipt)

Call offsets and original target addresses are read from the original function
bytes (capstone).  Symbol names come from the native object's COFF relocations
at those offsets; each pair is marked `reviewed_receipt` only when a prior
per-tool receipt records the same symbol at the same original address.
No compilation, no link, no runtime activation.
"""
import glob
import hashlib
import json
import struct
from pathlib import Path

from capstone import Cs, CS_ARCH_X86, CS_MODE_32, CS_GRP_CALL
from capstone.x86 import X86_OP_IMM

import sys
root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match  # noqa: E402

RUN = root / "work/2008-06/native-check-runs/20261106-103103-6be7bd3a"
MANIFEST = root / "rebuild/2008-06/tests/tool-verb-factories-unit-20261106.json"
RECEIPT = root / "work/2008-06/shared-layouts/tool-verb-factories-unit-20261106.json"
sha = lambda p: hashlib.sha256(Path(p).read_bytes()).hexdigest()

results = json.loads((RUN / "results.json").read_text())
summary = json.loads((RUN / "summary.json").read_text())
unit = results[0]
obj = Path(unit["object"])
raw = obj.read_bytes()
manifest = json.loads(MANIFEST.read_text())

reviewed = {}
ADDRESS = __import__("re").compile(r"^(?:0x)?[0-9a-fA-F]{6,8}$")


def collect(node):
    if isinstance(node, dict):
        for key, value in node.items():
            if isinstance(value, str) and ADDRESS.match(value):
                reviewed.setdefault(key, set()).add(int(value, 16))
            collect(value)
    elif isinstance(node, list):
        for item in node:
            collect(item)


for path in glob.glob(str(root / "work/2008-06/shared-layouts/*.json")):
    if Path(path).name == RECEIPT.name:
        continue
    try:
        collect(json.loads(Path(path).read_text()))
    except Exception:
        continue


def provenance(symbol, destination):
    for name, addresses in reviewed.items():
        if destination in addresses and (symbol.startswith(name) or name.startswith(symbol)):
            return "reviewed_receipt"
    if destination == 0x63E850 and symbol.startswith("??0ShootTool@RBX@@"):
        # No prior receipt names this address. The callee body at 0063e850 (57 bytes)
        # calls ??0MouseCommand@RBX@@IAE@PAVWorkspace@1@@Z at 006159f0 and stores the
        # ShootTool Named/Renderable vtables 0x84a348/0x84a364, i.e. a constructor.
        return "callee_structure"
    return "native_relocation"

sections, symbols, definitions, _ = match._coff_data_index(raw)
decoder = Cs(CS_ARCH_X86, CS_MODE_32)
decoder.detail = True


def call_rows(symbol, body, target, address):
    start, index = definitions[symbol]
    table = sections[index]
    relocs = {}
    for i in range(table[7]):
        offset, name, kind = struct.unpack_from("<IIH", raw, table[5] + 10 * i)
        if start <= offset < start + len(body) and kind == 20:
            relocs[offset - start] = symbols[name][0]
    rows, unresolved = [], []
    for insn in decoder.disasm(target, address):
        if not insn.group(CS_GRP_CALL):
            continue
        offset = insn.address - address
        if insn.operands[0].type != X86_OP_IMM or insn.bytes[0] != 0xE8:
            unresolved.append({"offset": offset, "reason": "indirect_call"})
            continue
        symbol_name = relocs.get(offset + 1)
        if not symbol_name:
            unresolved.append({"offset": offset, "reason": "no_rel32_relocation"})
            continue
        destination = insn.operands[0].imm
        rows.append({
            "offset": offset,
            "target": "%08x" % destination,
            "symbol": symbol_name,
        })
    return rows, unresolved


checks = []
for job in manifest["jobs"]:
    assert Path(root / "rebuild/2008-06" / job["source"]).read_bytes() == Path(unit["source"]).read_bytes()
    for check in job["checks"]:
        address = int(check["addr"], 16)
        target, _, row = match.target("2008-06", check["addr"])
        assert row["size"] == len(target)
        rows, unresolved = call_rows(check["symbol"], target, target, address)
        assert not unresolved, (check["symbol"], unresolved)
        check["calls"] = rows
        annotated = [dict(r, binding_source=provenance(r["symbol"], int(r["target"], 16)))
                     for r in rows]
        checks.append({
            "addr": check["addr"],
            "symbol": check["symbol"],
            "size": len(target),
            "calls": annotated,
            "unresolved_calls": unresolved,
        })

manifest_sha = None
MANIFEST.write_text(json.dumps(manifest, indent=2) + "\n")
manifest_sha = sha(MANIFEST)

per_check = {c["addr"]: c for c in unit["checks"]}
receipt = {
    "workflow": 52,
    "scope": ("Inactive exacts: 26 TToolVerb<Tool,RunStateVerb>::newMouseCommand bodies, "
              "byte-identical to the original under VC2008 RTM. No link, no provider "
              "selection, no runtime activation, no server credit."),
    "client": "2008-06",
    "unit": "ToolVerbFactories.cpp",
    "run": str(RUN.relative_to(root)),
    "manifest": str(MANIFEST.relative_to(root)),
    "manifest_sha256": manifest_sha,
    "source": str(Path(unit["source"]).relative_to(root)),
    "source_sha256": unit["source_sha256"],
    "object": str(obj.relative_to(root)),
    "object_sha256": unit["object_sha256"],
    "compiler": summary["compiler"],
    "compiler_sha256": summary["compiler_sha256"],
    "compiler_exit": unit["compiler_exit"],
    "flags": unit["flags"],
    "dependencies": {"count": len(unit["dependencies"]),
                     "map_sha256": hashlib.sha256(json.dumps(unit["dependencies"], sort_keys=True).encode()).hexdigest()},
    "totals": {
        "checks": len(checks),
        "exact_bytes": sum(1 for c in checks if per_check[c["addr"]]["status"] == "exact"),
        "data_checked": summary["data_checked"],
        "data_mismatches": len(summary["data_mismatches"]),
        "direct_calls": sum(len(c["calls"]) for c in checks),
        "reviewed_receipt_bindings": sum(1 for c in checks for r in c["calls"] if r["binding_source"] == "reviewed_receipt"),
        "callee_structure_bindings": sum(1 for c in checks for r in c["calls"] if r["binding_source"] == "callee_structure"),
        "native_relocation_only_bindings": sum(1 for c in checks for r in c["calls"] if r["binding_source"] == "native_relocation"),
    },
    "checks": [{
        "addr": c["addr"],
        "symbol": c["symbol"],
        "size": c["size"],
        "target_sha256": per_check[c["addr"]]["target_sha256"],
        "data_matches": per_check[c["addr"]]["data_matches"],
        "calls": c["calls"],
    } for c in checks],
    "remaining": [
        "Provider selection: which object supplies these 26 symbols in the document link (no archive/rsp in this workspace)",
        "Transitive callee ABI for the inlined tool constructors and operator new",
        "Relevant P5/P6/runtime gates before any activation",
    ],
    "preserved": "Shared headers, vendor inputs, other leases and the active executable selection unchanged.",
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + "\n")
print(json.dumps(receipt["totals"], indent=1))
print("manifest", manifest_sha)
print("binding_source per check:")
for c in checks:
    print(" ", c["addr"], c["symbol"].split("$TToolVerb@V")[1].split("@")[0],
          [(r["offset"], r["target"], r["symbol"].split("@")[0], r["binding_source"]) for r in c["calls"]])
