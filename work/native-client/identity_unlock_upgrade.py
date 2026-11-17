"""Route 9: promote inferred names to real names when two independent signals agree.

Among an unnamed function's exact reloc-masked body twins (identity-unlock-bodyhash-
candidates.json, written by identity_unlock_inferred.py), keep the authentic candidates
(undnames; every name part in authentic headers; owner class already named in the binary or a
namespaced vendor class).  If exactly one is authentic AND
  vote - a named caller's compiled body calls it at this call site (>=1 anchor), or
  nb    - its owner class equals the owner of one of the 5 nearest named functions on either side,
the name is promoted.  Cross-validated on already-named functions:
  sole authentic + vote 201 right / 1 wrong; sole authentic + nb 311 / 5.
Output: work/native-client/identity-unlock-upgrade.json
"""
import bisect
import gzip
from functools import lru_cache
import json
import pickle
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
import identity_unlock_merge as M  # noqa: E402
from identity_unlock_common import ROOT, REG, CODE_STARTS, undname_many  # noqa: E402
from identity_unlock_align import target_refs  # noqa: E402

NC = ROOT / 'work/native-client'
OUT = NC / 'identity-unlock-upgrade.json'
RX = re.compile(r'\?(?:\?[0-9A-Z_]{1,2})?\w+@((?:\w+@)*?\w+)@@')


def main():
    cands = json.load(open(NC / 'identity-unlock-bodyhash-candidates.json'))
    real = {a: r for a, r in json.load(open(NC / 'unnamed-identities.json')).items()
            if r['name_source'] != 'identity-unlock-upgrade'}
    cands = {a: c for a, c in cands.items() if a not in real}
    taken = {v['name'] for v in REG.values() if not v.get('placeholder')} | {r['name'] for r in real.values()}
    U = undname_many(sorted({s for c in cands.values() for s in c}))
    idents, vendor = M.header_idents(), M.vendor_classes()
    owners = Counter(m.group(1) for m in (RX.match(v['name']) for v in REG.values() if not v.get('placeholder')) if m)

    @lru_cache(None)
    def authentic(s):
        sig = U.get(s)
        if s in taken or not sig or sig == s or not all(x in idents for x in M.qual_parts(sig)):
            return False
        m = RX.match(s)
        return not m or owners[m.group(1)] > 0 or M.vendor_owner(m.group(1), vendor)

    auth = {a: [s for s in c if authentic(s)] for a, c in cands.items()}
    sole = {a: v[0] for a, v in auth.items() if len(v) == 1}
    print('candidates', len(cands), 'sole authentic', len(sole), flush=True)
    name = {a: v['name'] for a, v in REG.items() if not v.get('placeholder') and not v['name'].startswith('func_')}
    name.update({a: r['name'] for a, r in real.items()})
    funcs = set()
    for p in sorted(NC.glob('identity-unlock-objindex*.pkl.gz')):
        funcs |= set(pickle.load(gzip.open(p))['funcs'])
    bys = defaultdict(list)
    for r in funcs:
        bys[r[0]].append(r)
    want = set(sole)
    seq, callers = {}, defaultdict(set)
    for va in CODE_STARTS:
        a = '%08x' % va
        if a in name and name[a] in bys:
            c = target_refs(va)[0]
            if want & set(c):
                seq[a] = c
                for t in c:
                    callers[t].add(a)

    def voted(t, sym):
        for c in callers.get(t, ()):
            tc = seq[c]
            for row in bys[name[c]]:
                oc = row[2]
                if len(oc) != len(tc):
                    continue
                ok, anc = True, 0
                for x, o in zip(tc, oc):
                    if x == t:
                        continue
                    k = name.get(x)
                    if k is not None:
                        if k != o:
                            ok = False
                            break
                        anc += 1
                if ok and anc and any(x == t and o == sym for x, o in zip(tc, oc)):
                    return c
        return None

    code_named = sorted(a for a in name if REG.get(a, {}).get('kind') == 'code')
    out = {}
    for a, s in sole.items():
        ev = []
        c = voted(a, s)
        if c:
            ev.append({'kind': 'named-caller-call-site', 'caller': c, 'caller_name': name[c]})
        i = bisect.bisect_left(code_named, a)
        m = RX.match(s)
        # 5 nearest named functions each side (k=5: 358 right / 7 wrong on named functions)
        for j in sorted(range(i - 5, i + 5), key=lambda j: abs(j - i + 0.5)):
            if m and 0 <= j < len(code_named) and code_named[j] != a:
                mn = RX.match(name[code_named[j]])
                if mn and mn.group(1) == m.group(1):
                    ev.append({'kind': 'link-order-neighbour-same-owner', 'neighbour': code_named[j],
                               'neighbour_name': name[code_named[j]]})
                    break
        if ev:
            out[a] = {'name': s, 'owner_class': None, 'signature': U.get(s), 'kind': 'code',
                      'name_source': 'identity-unlock-upgrade',
                      'evidence': [{'kind': 'exact-masked-body-sole-authentic-candidate',
                                    'other_candidates': [x for x in cands[a] if x != s][:6]}] + ev}
    per = Counter(out[a]['name'] for a in out)
    out = {a: r for a, r in out.items() if per[r['name']] == 1}
    json.dump(out, open(OUT, 'w'), indent=1, sort_keys=True)
    print('promoted', len(out), Counter(e['kind'] for r in out.values() for e in r['evidence'][1:]))


if __name__ == '__main__':
    main()
