"""Quick assertions for refsource name recovery after A6A prefix stripping."""
import sys
sys.path.insert(0, r"C:\Users\colin\RoConstruct")
from roc import refsource as r

ids = r.identifiers

# VInstance, RakPeer, FactoryProduct are recoverable from mangled names
assert "VInstance" in ids("RBX::VInstance::?$NonFactoryProduct"), "VInstance lookup"
assert "RakPeer" in ids("RakNet::RakPeer"), "RakPeer lookup"
assert "FactoryProduct" in ids("VAuthoringSettings::?$FactoryProduct"), "FactoryProduct lookup"

# A6A marker stripping
assert "VColor3" in ids("A6AXVColor3"), "A6A prefix stripping gives VColor3"
assert "W4FriendEventType" in ids("A6AXHHW4FriendEventType"), "HH prefix stripping"

# Anonymous functions carry no real name
anon = ids("?func_0077cd30@@YAXXZ")
assert not [n for n in anon if n and n[0].isupper()], anon

# _plausible only keeps UpperCamelCase names (first char uppercase)
from roc.refsource import _plausible
assert _plausible(["nstance", "VInstance"], {"VInstance": []}) == ["VInstance"]
assert _plausible(["VInstance", "Instance"], {"VInstance": [], "Instance": []}) == ["VInstance", "Instance"]

# Also verify summarise filter logic
units_seen = {"VInstance": 5, "Instance": 3}
explained = 0
for unit in units_seen:
    ids2 = ids(unit)
    matched = any(i in {"VInstance"} for i in ids2 if i and i[0].isupper())
    if matched:
        explained += units_seen[unit]
total = sum(units_seen.values())
pct = 100.0 * explained / total if total else 0.0
print("explained=%d total=%d pct=%.1f%%" % (explained, total, pct))
assert pct > 0, "at least one unit should explain"
print("\nall assertions passed")