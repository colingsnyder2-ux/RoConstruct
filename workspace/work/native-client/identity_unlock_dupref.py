"""Route 19: fix 'bogus duplicate name' template peers from what each copy references.

Template peers compile to identical code but call and reference different named symbols
(Bridge<T>::registerClass references Bridge<T>'s statics, create<T> calls T's constructor).
Candidates are compiled-object symbols with the same leaf/outer template as the bogus name.
A candidate fits when its compiled call sequence has the address's length and agrees with every
named exe call target, and every data symbol it references that the registry names is among
the address's named data references; it needs >= 1 agreeing DATA symbol specific to it (not
shared by every candidate).  Exactly one fitting candidate names the address.
Measured on uniquely named template functions: 517 right / 11 wrong (97.9%).
--validate runs the rule on correctly named template functions (name hidden).
Output: work/native-client/identity-unlock-dupref.json
"""
import gzip
import json
import pickle
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from identity_unlock_align import target_refs  # noqa: E402
from identity_unlock_common import ROOT, REG, dump_json  # noqa: E402

NC = ROOT / 'work/native-client'
OUT = NC / 'identity-unlock-dupref.json'


def key(sym):
    """Peer key: leaf + outer template name, args dropped ('?registerClass@?$Bridge@')."""
    m = re.match(r'(\?\?[0-9A-Z_]|\?\?\$\w+@|\?\w+@)(\?\$\w+@)?', sym)
    if not m:
        return None
    k = m.group(1) + (m.group(2) or '')
    if not m.group(2):
        t = re.search(r'\?\$\w+@', sym[len(m.group(1)):])
        k += t.group(0) if t else ''
    return k if '?$' in k else None


def main(validate=False):
    d = json.load(open(NC / 'remaining-classified.json'))
    bogus = {a for a, v in d.items() if v.get('bucket') == 'bogus duplicate name'}
    real = json.load(open(NC / 'unnamed-identities.json'))
    name = {a: v['name'] for a, v in REG.items() if not v.get('placeholder') and not v['name'].startswith('func_')}
    for a, r in real.items():
        if r['name_source'] != 'identity-unlock-dupref':
            name[a] = r['name']
    regnames = set(name.values())
    rows = defaultdict(list)
    for p in sorted(NC.glob('identity-unlock-objindex*.pkl.gz')):
        for r in pickle.load(gzip.open(p))['funcs']:
            rows[r[0]].append(r)
    peers = defaultdict(set)
    for s in rows:
        k = key(s)
        if k:
            peers[k].add(s)
    multi = {}
    if validate:
        once = Counter(v['name'] for v in REG.values() if not v.get('placeholder'))
        tasks = {a: n for a, n in name.items() if a not in bogus and once[n] == 1 and REG.get(a, {}).get('kind') == 'code'
                 and key(n) and len(peers.get(key(n), ())) > 1 and n in rows}
    else:
        tasks = {a: (REG.get(a) or {}).get('name') for a in bogus if a not in real or real[a]['name_source'] == 'identity-unlock-dupref'}
        tasks = {a: n for a, n in tasks.items() if n and key(n)}
        # unnamed addresses whose exact-body twins are several authentic template peers
        multi = {a: c for a, c in json.load(open(NC / 'identity-unlock-bodyhash-candidates.json')).items()
                 if 2 <= len(c) < 10 and (a not in real or real[a]['name_source'] == 'identity-unlock-dupref')}
        tasks.update({a: c[0] for a, c in multi.items()})
    st, out = Counter(), {}
    for a, n in tasks.items():
        cs = sorted(multi[a]) if not validate and a in multi else sorted(peers.get(key(n), ()))
        if len(cs) < 2:
            st['no-peers'] += 1
            continue
        tc, td = target_refs(int(a, 16))
        fits = []
        for c in cs:
            ok = False
            for r in rows[c]:
                oc, od = r[2], set(r[3])
                if len(oc) != len(tc):
                    continue
                if any(x in name and name[x] != o for x, o in zip(tc, oc)):
                    continue
                if any(x in regnames and x not in td for x in od):
                    continue
                ok = (frozenset(o for x, o in zip(tc, oc) if name.get(x) == o) | (od & td))
                break
            if ok is not False:
                fits.append((c, ok))
        common = frozenset.intersection(*[f for _, f in fits]) if fits else frozenset()
        fits = [(c, f) for c, f in fits if f - common]
        if len(fits) != 1:
            st['fits-%s' % ('0' if not fits else 'n')] += 1
            continue
        c = fits[0][0]
        if not any(x not in rows for x in fits[0][1] - common):
            st['calls-only'] += 1  # call-only distinctions measured 38 right / 18 wrong
            continue
        if validate:
            dist = fits[0][1] - common
            nd = len(dist)
            dk = 'data' if any(x not in rows for x in dist) else 'calls'
            st[('right' if c == n else 'wrong', min(nd, 3), dk)] += 1
            continue
        if c in regnames and (a in multi or c != n):
            st['taken'] += 1
            continue
        out[a] = {'name': c, 'owner_class': None, 'signature': None, 'kind': 'code',
                  'name_source': 'identity-unlock-dupref',
                  'evidence': [{'kind': 'template-peer-reference-match',
                                'bogus_name': None if a in multi else n, 'body_twin_candidates': multi.get(a),
                                'distinguishing_refs': sorted(fits[0][1] - common)[:6]},
                               {'kind': 'compiled-object-symbol', 'symbol': c}]}
    per = Counter(r['name'] for r in out.values())
    out = {a: r for a, r in out.items() if per[r['name']] == 1 and (a in multi or r['name'] != tasks[a])}
    if not validate:
        dump_json(out, OUT)
    print('tasks', len(tasks), 'named', len(out), dict(st))


if __name__ == '__main__':
    main('--validate' in sys.argv)
