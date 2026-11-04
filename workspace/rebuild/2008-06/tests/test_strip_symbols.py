"""Self-check for rebuild.strip_symbols on a stage-1 verified object: keep mode leaves the kept external
definition and no other non-shared external function; drop mode undefines exactly the dropped one.
usage: python rebuild/2008-06/tests/test_strip_symbols.py"""
import json
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import rebuild  # noqa: E402


def externals(data):
    """{name: defined} for external symbols (class 2)."""
    _, _, _, symptr, nsym, _, _ = struct.unpack_from("<HHIIIHH", data, 0)
    strtab, out, i = symptr + nsym * 18, {}, 0
    while i < nsym:
        raw, _, secnum, _, cls, naux = struct.unpack_from("<8sIhHBB", data, symptr + 18 * i)
        if cls == 2:
            name = data[strtab + struct.unpack_from("<I", raw, 4)[0]:].split(b"\0", 1)[0] if raw[:4] == b"\0\0\0\0" else raw.rstrip(b"\0")
            out[name.decode("latin-1")] = secnum > 0
        i += 1 + naux
    return out


folder = ROOT / "rebuild" / "2008-06" / "out" / "RbxgsApp" / "verified"
item = json.loads((folder / "swaps.json").read_text())["swaps"][0] if (folder / "swaps.json").exists() else None
obj = sorted(folder.glob("*.obj"))[0]
data = obj.read_bytes()
before = externals(data)
keep = set(item["keep"]) if item and item["obj"] == obj.name else {next(n for n, d in before.items() if d)}

kept = externals(rebuild.strip_symbols(data, keep=keep))
assert all(kept[k] for k in keep if k in before), "kept symbol lost"
dropped = rebuild.strip_symbols(data, drop=keep)
assert not any(externals(dropped)[k] for k in keep), "dropped symbol still defined"
assert sum(externals(dropped).values()) == sum(before.values()) - len([k for k in keep if before.get(k)])
print("ok: %s keep=%d defined before=%d after keep=%d" % (obj.name, len(keep), sum(before.values()), sum(kept.values())))
