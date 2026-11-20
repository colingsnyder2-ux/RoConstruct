"""One-command lane for 2008-06 boost functor pieces: basic_string genericConvert family.
Proves all four addresses. Drafts live in lane-drafts/basic_string/.
  python work/native-client/basic_string_lane.py
"""
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import agent_prove

TARGETS = [
    ("lane-drafts/basic_string/TwinInst_00597740.cpp", "00597740", "genericConvert"),
    ("lane-drafts/basic_string/TwinInst_005eef20.cpp", "005eef20", "genericConvert"),
    ("lane-drafts/basic_string/TwinInst_005ef020.cpp", "005ef020", "genericConvert"),
    ("lane-drafts/basic_string/TwinInst_006154e0.cpp", "006154e0", "genericConvert"),
]

def main():
    ok = True
    for rel, addr, needle in TARGETS:
        path = HERE / rel
        for a, (status, text) in agent_prove.verdict(str(path), {addr: needle}).items():
            print("== %s %s\n%s" % (a, status, text), flush=True)
            if status != "EXACT":
                ok = False
    raise SystemExit(0 if ok else 1)

if __name__ == "__main__":
    main()
