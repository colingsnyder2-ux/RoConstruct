"""header_lane.py: create missing NATIVE headers from the 2007 donor headers (no model calls).
  python work/native-client/header_lane.py --names BrickColor,worker_thread [--verify UNIT.cpp,...] [--keep-unverified]
  python work/native-client/header_lane.py --scan      # collect names from workflow-fail/*.txt, report only
Flow per name: find donor header (rbxgs, bounded dirs) -> skip if a native header of that relative path exists ->
write native copy with INFERRED first line -> prove --verify units before/after (exact counts must match) ->
else delete the header. Results: work/native-client/header-lane-results.json. Lease the path yourself (roc.py lease).
"""
import argparse, json, re, subprocess, sys
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]
NH = ROOT / 'rebuild/2008-06/native-headers'
DONOR = ROOT / 'tools/rbxgs/Client'
DONOR_DIRS = [DONOR / 'App/include', DONOR / 'Network/raknet30/Source']
FAIL = ROOT / 'work/native-client/workflow-fail'
RES = ROOT / 'work/native-client/header-lane-results.json'
CORE = ('v8tree/Instance.h', 'v8datamodel/DataModel.h', 'util/Events.h', 'reflection/')

def find_donor(name):
    for d in DONOR_DIRS:
        for ext in ('.h', '.hpp'):
            p = d / (name + ext)
            hits = [p] if p.exists() else list(d.glob('*/' + name + ext))
            if hits: return d, hits[0]
    pat = re.compile(r'\b(class|struct)\s+%s\b\s*[:{]' % re.escape(name))
    for d in DONOR_DIRS:
        for p in list(d.glob('*/*.h')) + list(d.glob('*/*.hpp')):  # bounded: one level
            if pat.search(p.read_text(errors='ignore')): return d, p
    return None, None

def prove(unit):
    out = subprocess.run([sys.executable, str(ROOT / 'work/native-client/prove.py'), unit, '--rounds', '1', '--no-register'],
                         cwd=ROOT, capture_output=True, text=True).stdout.strip().splitlines()
    m = re.search(r'(\d+) exact', out[-1] if out else '')
    return int(m.group(1)) if m else None

def scan():
    names = {}
    for f in FAIL.glob('*.txt'):
        t = f.read_text(errors='ignore')
        for m in re.finditer(r"'(\w+)' : is not a member of '(?:RBX|\w+)'|Cannot open include file: '([\w./]+)'|'(\w+)' : is not a class or namespace|use of undefined type '(\w+)'", t):
            n = next(g for g in m.groups() if g)
            names.setdefault(Path(n).stem, set()).add(f.stem)
    return names

def make(name, verify):
    r = {'name': name}
    d, p = find_donor(name)
    if not p: return {**r, 'status': 'no-donor'}
    rel = p.relative_to(d).as_posix(); dst = NH / rel
    if dst.exists() or any(rel.startswith(c) for c in CORE): return {**r, 'status': 'native-exists-or-core', 'path': rel}
    if next(NH.glob('**/' + p.name), None) and not dst.exists(): r['note'] = 'same file name exists elsewhere natively'
    before = {u: prove(u) for u in verify}
    dst.parent.mkdir(parents=True, exist_ok=True)
    dst.write_text('// INFERRED: generated from the 2007 donor header %s by header_lane.py; layout verified against %s\n'
                   % (p.relative_to(ROOT).as_posix(), ','.join(Path(u).name for u in verify)) + p.read_text(errors='ignore'))
    after = {u: prove(u) for u in verify}
    ok = bool(verify) and before == after and all(v is not None for v in after.values())
    if not ok: dst.unlink()
    return {**r, 'status': 'kept' if ok else 'rejected', 'path': rel, 'before': before, 'after': after}

if __name__ == '__main__':
    a = argparse.ArgumentParser(); a.add_argument('--names'); a.add_argument('--scan', action='store_true'); a.add_argument('--verify', default='')
    a = a.parse_args(); v = [x for x in a.verify.split(',') if x]
    if a.scan:
        res = {n: {'files': sorted(f)[:6], 'donor': str(find_donor(n)[1] and find_donor(n)[1].relative_to(ROOT)), 'native': bool(next(NH.glob('**/' + n + '.h*'), None))} for n, f in scan().items()}
    else:
        res = [make(n, v) for n in a.names.split(',')]
    old = json.loads(RES.read_text()) if RES.exists() else {}
    old['scan' if a.scan else 'last'] = res; RES.write_text(json.dumps(old, indent=1)); print(json.dumps(res, indent=1)[:3000])
