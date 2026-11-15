#!/usr/bin/env python
"""native-bulk with identity-registry evidence: two passes over the given native-classes files.

Pass 1 compiles and collects byte-identical candidate addresses. Pass 2 re-runs with evidence rows
(symbol, address) taken from work/native-client/data/identity-registry.json.gz wherever the registry's
decorated name equals the compiled symbol. Bytes, data and references are still verified by native-bulk.
Prints inactive_exact addresses that docs/integration.json does not count yet.

  python rebuild/2008-06/tests/bulk_with_registry.py NAME file1.cpp [file2.cpp ...]   (paths relative to repo root)
"""
import gzip, json, subprocess, sys
from pathlib import Path
ROOT = Path(__file__).resolve().parents[3]
name, files = sys.argv[1], sys.argv[2:]
out = ROOT / "work/native-bulk"
def bulk(cfg, tag):
    (out / f"{tag}.json").write_text(json.dumps(cfg))
    subprocess.run([str(ROOT / "roc.cmd"), "native-bulk", str(out / f"{tag}.json"), "--out", str(out / tag)], cwd=ROOT, capture_output=True)
    m = json.load(open(out / tag / "manifest.json"))
    f = m["families"]; return f if isinstance(f, list) else list(f.values())
fams = lambda ev=None: {"client": "2008-06", "families": [{"name": Path(x).stem, "sources": [x]} | ({"evidence": [ev]} if ev else {}) for x in files]}
reg = json.load(gzip.open(ROOT / "work/native-client/data/identity-registry.json.gz"))
p1 = bulk(fams(), name + "-p1")
pairs = sorted({(s["symbol"], a) for f in p1 for s in f["symbols"] for a in s["candidates"]
                if reg.get(a) and not reg[a].get("placeholder") and reg[a].get("name") == s["symbol"]})
ev = out / f"{name}-evidence.json"
# References (_atexit, vtables, ctors) also need identities: add every unambiguous registry name.
byname = {}
for a, r in reg.items():
    if not r.get("placeholder") and r.get("name"):
        byname.setdefault(r["name"], set()).add(a)
extra = [(n, next(iter(v))) for n, v in byname.items() if len(v) == 1]
ev.write_text(json.dumps({"identities": [{"symbol": s, "address": a, "status": "exact"} for s, a in sorted(set(pairs) | set(extra))]}))
p2 = bulk(fams(str(ev.relative_to(ROOT)).replace("\\", "/")), name + "-p2")
known = json.load(open(ROOT / "docs/integration.json")); known = set(known["native"]) | set(known["inactive"])
exact = {s["addr"] for f in p2 for s in f["symbols"] if s["status"] == "inactive_exact"}
print(len(pairs), "registry pairs;", len(exact), "inactive_exact;", len(exact - known), "new:", sorted(exact - known))
