"""Swap plan: which exact 2008-06 library-member sources from the rbxgs/OpenRBX recipes the rebuild does
not yet reproduce, grouped by the compile (recipe, file, compiler, flags) that produces them.
Read-only; writes rebuild/2008-06/out/swap-plan.json.
usage: python rebuild/2008-06/swap_plan.py"""
import collections
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
LIBS = {"rbxgs", "rbxgs-dll", "openrbx-client", "openrbx-client-dll"}
LIB_PREFIXES = ("xtp-11.2.2", "g3d-6.09", "boost-1.34.1", "libpng-1.2", "lua-5.1")  # library modules swap these in
OUT = ROOT / "rebuild" / "2008-06" / "out"


def owned():
    """Addresses the linked modules reproduce from their own layers. Those supplied by a module's verified layer
    (swap_build's output) are not counted, or each regenerated plan would drop the previous swaps."""
    addrs = set()
    for report in OUT.glob("*/report.json"):
        data = json.loads(report.read_text())
        if data.get("linked"):
            mine = set(data.get("owned_addrs", []))
            swaps = report.parent / "verified" / "swaps.json"
            if swaps.exists():
                for item in json.loads(swaps.read_text()).get("swaps", []):
                    mine -= set(item["keep"].values())
            addrs.update(mine)
    return addrs


def main():
    scores = json.loads((ROOT / "work" / "2008-06" / "scores.json").read_text())
    have = owned()
    groups = collections.defaultdict(list)
    for addr, value in scores.items():
        if (value if isinstance(value, int) else value.get("score", 0)) != 100:
            continue
        path = ROOT / "src" / "2008-06" / (addr + ".cpp")
        if not path.exists():
            continue
        text = path.read_text(errors="replace")
        lib = re.search(r"^// roc-lib: (\S+) (\S+)", text, re.M)
        if not lib or (lib.group(1) not in LIBS and not lib.group(1).startswith(LIB_PREFIXES)):
            continue
        cl = re.search(r"^// roc-cl: (\d+)", text, re.M)
        flags = re.search(r"^// roc-flags: (.*)$", text, re.M)
        key = (lib.group(1), lib.group(2).replace("\\", "/"), cl.group(1) if cl else "default",
               flags.group(1).strip() if flags else "")
        groups[key].append(addr)

    plan, totals = [], collections.Counter()
    for (lib, unit, cl, flags), addrs in sorted(groups.items()):
        missing = sorted(a for a in addrs if a not in have and "0x" + a not in have and int(a, 16) not in have)
        totals["exact"] += len(addrs)
        totals["already in rebuild"] += len(addrs) - len(missing)
        totals["to swap in"] += len(missing)
        if missing:
            plan.append({"recipe": lib, "file": unit, "cl": cl, "flags": flags, "addrs": missing})
    by_cl = collections.Counter()
    for item in plan:
        by_cl[item["cl"]] += len(item["addrs"])
    (OUT / "swap-plan.json").write_text(json.dumps({"totals": totals, "by_compiler": by_cl, "groups": plan}, indent=1))
    print(dict(totals), "compiles:", len(plan), "by compiler:", dict(by_cl))


if __name__ == "__main__":
    main()
