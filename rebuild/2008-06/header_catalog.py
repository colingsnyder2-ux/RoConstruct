"""Phase 4 seed: which rbxgs headers the exact generated units (roc_*.cpp, 2008-06 score 100) replace with
2008-layout headers via #pragma include_alias, how many exact functions depend on each replacement, and
how many distinct replacements exist per header (more than one means they disagree or cover different parts).
Read-only; writes rebuild/2008-06/out/header-catalog.json.
usage: python rebuild/2008-06/header_catalog.py"""
import collections
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
TREE = ROOT / "tools" / "rbxgs" / "Client" / "App"
ALIAS = re.compile(r'#pragma\s+include_alias\(\s*"([^"]+)"\s*,\s*"([^"]+)"\s*\)')


def main():
    scores = json.loads((ROOT / "work" / "2008-06" / "scores.json").read_text())
    exact_by_unit = collections.Counter()
    for addr, value in scores.items():
        if (value if isinstance(value, int) else value.get("score", 0)) != 100:
            continue
        path = ROOT / "src" / "2008-06" / (addr + ".cpp")
        if path.exists():
            m = re.search(r"^// roc-lib: rbxgs(?:-dll)? (\S+)", path.read_text(errors="replace")[:3000], re.M)
            if m:
                exact_by_unit[m.group(1).replace("\\", "/")] += 1

    headers = collections.defaultdict(lambda: {"replacements": collections.Counter(), "exact_functions": 0, "units": 0})
    for unit, count in exact_by_unit.items():
        if not unit.rsplit("/", 1)[-1].startswith("roc_"):
            continue
        src = TREE / unit
        if not src.exists():
            continue
        for original, replacement in set(ALIAS.findall(src.read_text(errors="replace"))):
            entry = headers[original]
            entry["replacements"][replacement.rsplit("/", 1)[-1]] += 1
            entry["exact_functions"] += count
            entry["units"] += 1
    rows = sorted(({"header": h, "exact_functions": e["exact_functions"], "units": e["units"],
                    "distinct_replacements": len(e["replacements"]),
                    "replacements": dict(e["replacements"].most_common())} for h, e in headers.items()),
                  key=lambda r: -r["exact_functions"])
    out = ROOT / "rebuild" / "2008-06" / "out" / "header-catalog.json"
    out.write_text(json.dumps(rows, indent=1))
    print("%d exact functions in %d rbxgs units; %d headers replaced" % (sum(exact_by_unit.values()), len(exact_by_unit), len(rows)))
    for r in rows[:25]:
        print("  %5d fns %4d units %3d variants  %s" % (r["exact_functions"], r["units"], r["distinct_replacements"], r["header"]))


if __name__ == "__main__":
    main()
