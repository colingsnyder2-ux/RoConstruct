"""Tiny SMT verifier for register-only x86-32 window candidates.

Conservative by design: unknown instructions are rejected, never assumed equal.
"""
import argparse
import json
import re

from z3 import BitVec, Solver, sat
from roc.pressure import estimate, estimate_killed


MOV = re.compile(r"^mov\s+(e[abcd]x|e[sd]i|e[bp]p),\s*(e[abcd]x|e[sd]i|e[bp]p)$", re.I)


def prove(left, right, equal=()):
    a = {r: BitVec(r, 32) for r in ("eax", "ebx", "ecx", "edx", "esi", "edi", "ebp", "esp")}
    lm, rm = MOV.match(left.strip()), MOV.match(right.strip())
    if not lm or not rm or lm.group(1).lower() != rm.group(1).lower():
        return {"status": "rejected", "reason": "unsupported-window",
                "pressure": estimate(left + "\n" + right),
                "killed_pressure": estimate_killed(left + "\n" + right)}
    dst = lm.group(1).lower()
    lx, rx = a[lm.group(2).lower()], a[rm.group(2).lower()]
    s = Solver()
    for x, y in equal:
        s.add(a[x] == a[y])
    s.add(lx != rx)
    result = s.check()
    return {"status": "equivalent" if result != sat else "not-equivalent",
            "counterexample": result == sat, "dst": dst,
            "pressure": estimate(left + "\n" + right),
            "killed_pressure": estimate_killed(left + "\n" + right)}


def main(argv=None):
    p = argparse.ArgumentParser()
    p.add_argument("left")
    p.add_argument("right")
    p.add_argument("--equal", action="append", default=[])
    a = p.parse_args(argv)
    pairs = [tuple(x.lower().split("=")) for x in a.equal]
    print(json.dumps(prove(a.left, a.right, pairs), sort_keys=True))


if __name__ == "__main__":
    main()
