"""Quick test: identifiers and _plausible."""
import sys
sys.path.insert(0, r"C:\Users\colin\RoConstruct")
from roc import refsource as r

ids = r.identifiers
print("identifiers:")
u = "RBX::VInstance::?$NonFactoryProduct"
result = ids(u)
print("  %s -> %s" % (u, result))
assert "VInstance" in result

u = "A6AXVColor3"
result = ids(u)
print("  %s -> %s" % (u, result))
assert "VColor3" in result

u = "A6AXHHW4FriendEventType"
result = ids(u)
print("  %s -> %s" % (u, result))
assert "W4FriendEventType" in result

u = "RakNet::RakPeer"
result = ids(u)
print("  %s -> %s" % (u, result))
assert "RakPeer" in result

u = "?func_0077cd30@@YAXXZ"
result = ids(u)
print("  %s -> %s" % (u, result))
assert not [n for n in result if n and n[0].isupper()]

from roc.refsource import _plausible
print()
print("_plausible:")
assert _plausible(["nstance", "VInstance"], {"VInstance": []}) == ["VInstance"]
assert _plausible(["VInstance", "Instance"], {"VInstance": [], "Instance": []}) == ["VInstance", "Instance"]
print("all assertions passed")