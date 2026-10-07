"""Final verification of all objective deliverables."""
import json, os, sys
sys.path.insert(0, r"C:\Users\colin\RoConstruct")

# 1. Tests
import subprocess
result = subprocess.run(
    ["python", "-m", "pytest", "tests/test_roc.py", "-v"],
    capture_output=True, text=True, cwd=r"C:\Users\colin\RoConstruct"
)
output = result.stdout + result.stderr
passed = "13 passed" in output
print("TESTS:", "PASS" if passed else "FAIL")
if not passed:
    # show failure lines
    for line in output.split("\n"):
        if "FAILED" in line or "ERROR" in line:
            print("  ", line)

# 2. Xcopy all
result2 = subprocess.run(
    ["python", "roc.py", "xcopy", "all"],
    capture_output=True, text=True, cwd=r"C:\Users\colin\RoConstruct"
)
has_0_new = "0 new" in result2.stdout
print("XCOPY ALL:", "PASS" if has_0_new else "output=" + result2.stdout[:80])

# 3. libmatch.json
print("LIBMATCH:")
for c in ["2007-08", "2008-06", "2009-06", "2010-06", "2011-06", "2012-06"]:
    path = "work/%s/libmatch.json" % c
    exists = os.path.exists(path)
    if exists:
        d = json.load(open(path))
        print("  %s: %d entries" % (c, len(d)))
    else:
        print("  %s: MISSING" % c)

# 4. scores.json counts
print("SCORES:")
for c in ["2007-08", "2008-06", "2009-06", "2010-06", "2011-06", "2012-06"]:
    sc = json.load(open("work/%s/scores.json" % c))
    count = sum(1 for v in sc.values() if v == 100)
    total = len(sc)
    print("  %s: %d / %d at 100%%" % (c, count, total))

# 5. refsource
from roc import refsource as r
ids = r.identifiers
# Test with raw string
tag1 = "RBX::VInstance::?$NonFactoryProduct"
tag2 = "A6AXVColor3"
# Use .find() approach
ids1 = ids(tag1)
ids2 = ids(tag2)
v1 = "VInstance" in ids1
# For A6AX, we need to check if any identifier strips to VColor3
v2_any = any(i == "VColor3" for i in ids2)
print("REFSOURCE: VInstance resolve=%s VColor3 strip=%s" % (v1, v2_any))

# Also check W4FriendEventType
tag3 = "A6AXHHW4FriendEventType"
ids3 = ids(tag3)
v3 = "W4FriendEventType" in ids3
print("REFSOURCE: W4FriendEventType strip=%s" % v3)

print("\n=== ALL DELIVERABLES VERIFIED ===" if all([
    passed, has_0_new, 
    all(os.path.exists("work/%s/libmatch.json" % c) for c in ["2007-08","2008-06","2009-06","2010-06","2011-06","2012-06"]),
    v1, v2_any, v3
]) else "=== SOME CHECKS FAILED ===")