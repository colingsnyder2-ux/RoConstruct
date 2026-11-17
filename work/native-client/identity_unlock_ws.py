"""Route 16: WebService.pdb call-graph alignment (RBXGS 0.3.676, Dec 2007, same engine source).

A named exe function whose WebService.dll twin (same PDB public name) has a call sequence of
the same length, agreeing with every named exe call target (>= 2 anchors), names the unnamed
targets at the remaining positions.  Measured alone on named functions: 89-96% (VC8 /GL vs VC9
inlining), so it is used two ways:
  real     - the WebService vote equals the address's sole authentic exact-body candidate
             (two independent signals: identical compiled body + PDB-named caller alignment);
  inferred - otherwise a unique non-template vote not already used names the address in the
             inferred tier (confidence 'webservice-pdb-alignment').
Outputs: work/native-client/identity-unlock-ws.json, identity-unlock-ws-inferred.json
Needs identity-unlock-wsindex.pkl.gz (identity_unlock_wsindex.py).
"""
import gzip
import json
import pickle
import sys
from collections import Counter, defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from identity_unlock_align import target_refs  # noqa: E402
from identity_unlock_common import ROOT, REG, CODE_STARTS, unnamed, dump_json  # noqa: E402

NC = ROOT / 'work/native-client'
OUT, OUT_INF = NC / 'identity-unlock-ws.json', NC / 'identity-unlock-ws-inferred.json'


def main():
    p = NC / 'identity-unlock-wsindex.pkl.gz'
    if not p.exists():
        return
    by = defaultdict(list)
    for r in pickle.load(gzip.open(p))['funcs']:
        by[r[0]].append(r)
    real = json.load(open(NC / 'unnamed-identities.json'))
    real = {a: r for a, r in real.items() if r['name_source'] != 'identity-unlock-ws'}
    name = {a: v['name'] for a, v in REG.items() if not v.get('placeholder') and not v['name'].startswith('func_')}
    name.update({a: r['name'] for a, r in real.items()})
    targets = set(unnamed()) - set(real)
    votes = defaultdict(lambda: defaultdict(set))
    for va in CODE_STARTS:
        a = '%08x' % va
        if a not in name or name[a] not in by:
            continue
        tc = target_refs(va)[0]
        if not targets & set(tc):
            continue
        for row in by[name[a]]:
            oc = row[2]
            if len(oc) != len(tc):
                continue
            anc = sum(1 for x, o in zip(tc, oc) if name.get(x) == o)
            bad = any(x in name and name[x] != o and not o.startswith('?unknown') for x, o in zip(tc, oc))
            if anc < 2 or bad:
                continue
            for x, o in zip(tc, oc):
                if x in targets and not o.startswith('?unknown'):
                    votes[x][o].add(a)
    cands = json.load(open(NC / 'identity-unlock-bodyhash-candidates.json'))
    taken = set(name.values())
    out, inf, st = {}, {}, Counter()
    for t, v in votes.items():
        if len(v) != 1:
            st['conflict'] += 1
            continue
        s, callers = next(iter(v.items()))
        if s in taken:
            st['taken'] += 1
            continue
        ev = {'kind': 'webservice-pdb-caller-alignment', 'pdb': 'WebService.pdb (RBXGS 0.3.676)',
              'callers': sorted(callers)[:6], 'caller_names': sorted(name[c] for c in callers)[:6]}
        if cands.get(t) == [s]:
            out[t] = {'name': s, 'owner_class': None, 'signature': None, 'kind': 'code',
                      'name_source': 'identity-unlock-ws',
                      'evidence': [ev, {'kind': 'exact-masked-body-sole-authentic-candidate'}]}
            st['real'] += 1
        elif '?$' not in s and not s.startswith('??$'):
            inf[t] = {'name': s, 'signature': None, 'kind': 'code', 'inferred': True,
                      'confidence': 'webservice-pdb-alignment', 'name_source': 'identity-unlock-ws',
                      'alternatives': cands.get(t, [])[:8], 'evidence': [ev]}
            st['inferred'] += 1
        else:
            st['template-skipped'] += 1
    per = Counter(r['name'] for r in list(out.values()) + list(inf.values()))
    out = {a: r for a, r in out.items() if per[r['name']] == 1}
    inf = {a: r for a, r in inf.items() if per[r['name']] == 1}
    dump_json(out, OUT)
    dump_json(inf, OUT_INF)
    print('ws real', len(out), 'inferred', len(inf), dict(st))


if __name__ == '__main__':
    main()
