"""Header gaps from model-lane compile failures: for every remaining address, the LAST attempt's compiler errors
(placeholder-lane/<addr>/err*.txt) mined for members the headers lack - C2039 "'m' : is not a member of 'C'",
C2065 undeclared identifiers inside member bodies, C3861 identifier not found.  Ranked by how many remaining
functions each (class, member) blocks: one header line can unblock many.  -> header-gaps.json
  python work/native-client/header_gaps.py [--top 40]"""
import argparse
import collections
import json
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(ROOT))
from roc import integration_site  # noqa: E402

ap = argparse.ArgumentParser()
ap.add_argument('--top', type=int, default=40)
args = ap.parse_args()
exact = {a for a, v in integration_site.inactive_code(ROOT).items() if v[1]}
remaining = set(json.loads((HERE / 'remaining-classified.json').read_text())) - exact
C2039 = re.compile(r"error C2039: '(\w+)' : is not a member of '([\w:<>, ]+?)'")
C2065 = re.compile(r"error C2065: '(\w+)' : undeclared identifier")
C3861 = re.compile(r"error C3861: '(\w+)': identifier not found")
gaps, undeclared, examples = collections.defaultdict(set), collections.defaultdict(set), {}
for addr in remaining:
    errs = sorted((HERE / 'placeholder-lane' / addr).glob('err*.txt'), key=lambda p: int(re.sub(r'\D', '', p.stem) or 0))
    if not errs:
        continue
    text = errs[-1].read_text(errors='replace')
    for member, cls in C2039.findall(text):
        cls = re.sub(r'<.*', '', cls).strip()
        gaps[(cls, member)].add(addr)
        examples.setdefault((cls, member), (addr, errs[-1].relative_to(HERE).as_posix()))
    for name in C2065.findall(text) + C3861.findall(text):
        undeclared[name].add(addr)
ranked = sorted(gaps.items(), key=lambda kv: -len(kv[1]))
out = {'members': [{'class': c, 'member': m, 'functions': sorted(a), 'example': examples[(c, m)]}
                   for (c, m), a in ranked],
       'undeclared': [{'name': n, 'functions': sorted(a)} for n, a in sorted(undeclared.items(), key=lambda kv: -len(kv[1]))]}
(HERE / 'header-gaps.json').write_text(json.dumps(out, indent=1))
blocked = set().union(*gaps.values()) if gaps else set()
print('missing members: %d (class, member) pairs blocking %d remaining functions' % (len(gaps), len(blocked)))
for (c, m), a in ranked[:args.top]:
    print('  %3d  %s::%s' % (len(a), c, m))
print('top undeclared identifiers:', ', '.join('%s(%d)' % (n, len(a)) for n, a in
                                              sorted(undeclared.items(), key=lambda kv: -len(kv[1]))[:15]))
