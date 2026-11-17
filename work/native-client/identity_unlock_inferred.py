"""Inferred-name tier: give every still-unnamed function its best-supported name, flagged.

Real (validated) names live in unnamed-identities.json, which the native_llm loop reads.
This tier is written to work/native-client/unnamed-identities-inferred.json only, so
guesses never reach the gate.  Each row: name, inferred=True, confidence, alternatives,
evidence.  Ranking per address:
  1. exact reloc-masked body twins in compiled objects: candidate symbols not yet placed,
     ordered by (authentic owner/header parts, named-caller votes, neighbour-owner match);
  2. no body twin: '<owner>::sub_<addr>' from link-order neighbours (both neighbours share
     the owner), else 'sub_<addr>' with the neighbour library.
Each mangled name is used once.  Upgrades to real names are done by identity_unlock_merge
routes, never here.
"""
import bisect
import gzip
from functools import lru_cache
import hashlib
import json
import os
import time
import pickle
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
import identity_unlock_bodyhash as B  # noqa: E402
import identity_unlock_merge as M  # noqa: E402
from identity_unlock_common import ROOT, REG, IMG, BASE, CODE_STARTS, end_of, unnamed, undname_many  # noqa: E402
from identity_unlock_align import target_refs  # noqa: E402

NC = ROOT / 'work/native-client'
OUT = NC / 'unnamed-identities-inferred.json'
RX = re.compile(r'\?(?:\?[0-9A-Z_]{1,2})?\w+@((?:\w+@)*?\w+)@@')


def main():
    real = json.load(open(NC / 'unnamed-identities.json'))
    promoted = {a for a, r in real.items() if r['name_source'] in ('identity-unlock-upgrade', 'identity-unlock-reflect')}
    att = json.load(open(NC / 'unnamed-remaining-attribution.json'))
    rem = sorted(a for a in unnamed() if a not in real or a in promoted)  # upgrade re-derives its rows
    rows = [r for p in sorted(NC.glob('identity-unlock-bodyhash*.pkl.gz')) for r in pickle.load(gzip.open(p))['funcs']]
    by, lens = defaultdict(set), set()
    for ln, h, s in rows:
        by[(ln, h)].add(s)
        lens.add(ln)
    relocs = B.base_relocs()
    taken = {v['name'] for v in REG.values() if not v.get('placeholder')} |         {r['name'] for a, r in real.items() if a not in promoted}
    cands = {}
    for a in rem:
        va = int(a, 16)
        hi = end_of(va) - va
        lo = hi
        while lo > 1 and IMG[va - BASE + lo - 1] in (0xCC, 0x90):
            lo -= 1
        hs = [k for k in {(n, hashlib.sha1(B.masked(va, n, relocs)).digest()[:12]) for n in range(lo, hi + 1)
                          if n in lens} if k in by]
        if len(hs) == 1:
            free = by[hs[0]] - taken
            if free:
                cands[a] = (hs[0][0], free)
    print('remaining', len(rem), 'with body candidates', len(cands), flush=True)
    U = undname_many(sorted({s for _, f in cands.values() for s in f}))
    idents, vendor = M.header_idents(), M.vendor_classes()
    owners = Counter(m.group(1) for m in (RX.match(v['name']) for v in REG.values() if not v.get('placeholder')) if m)

    @lru_cache(None)
    def authentic(s):
        sig = U.get(s)
        if not sig or sig == s or not all(x in idents for x in M.qual_parts(sig)):
            return False
        m = RX.match(s)
        return not m or owners[m.group(1)] > 0 or M.vendor_owner(m.group(1), vendor)

    # only authentic candidates can be promoted (upgrade/reflect/merge all require it); trivial
    # bodies have thousands of non-authentic twins, which made this file >200 MB
    tmp = NC / 'identity-unlock-bodyhash-candidates.json.tmp'
    json.dump({a: sorted(x for x in f if authentic(x))[:10] for a, (_, f) in cands.items()},  # >=10: ambiguous
              open(tmp, 'w'), indent=0, sort_keys=True)
    for k in range(30):  # another session may be reading it (Windows denies replace meanwhile)
        try:
            os.replace(tmp, NC / 'identity-unlock-bodyhash-candidates.json')
            break
        except PermissionError:
            time.sleep(1)
    else:
        raise PermissionError('identity-unlock-bodyhash-candidates.json stays locked')

    # named-caller votes (compiled caller calls this symbol at this site), relaxed: 1 anchor
    funcs = set()
    for p in sorted(NC.glob('identity-unlock-objindex*.pkl.gz')):
        funcs |= set(pickle.load(gzip.open(p))['funcs'])
    bys = defaultdict(list)
    for r in funcs:
        bys[r[0]].append(r)
    name = {a: v['name'] for a, v in REG.items() if not v.get('placeholder')}
    name.update({a: r['name'] for a, r in real.items()})
    want = set(cands)
    seq, callers = {}, defaultdict(set)
    for va in CODE_STARTS:
        a = '%08x' % va
        if a in name and name[a] in bys:
            c = target_refs(va)[0]
            if want & set(c):
                seq[a] = c
                for t in c:
                    callers[t].add(a)
    votes = defaultdict(Counter)
    for t in want:
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
                if ok and anc:
                    for x, o in zip(tc, oc):
                        if x == t and o in cands[t][1]:
                            votes[t][o] += 1
    named_sorted = sorted(a for a in name if REG.get(a, {}).get('kind') == 'code')

    def nb_owner(a):
        i = bisect.bisect_left(named_sorted, a)
        out = set()
        for j in (i - 1, i):
            if 0 <= j < len(named_sorted) and named_sorted[j] != a:
                m = RX.match(name[named_sorted[j]])
                if m:
                    out.add(m.group(1))
        return out

    out, used = {}, set()
    order = sorted(cands, key=lambda a: -max([votes[a][s] for s in cands[a][1]] + [0]))
    for a in order:
        n, free = cands[a]
        nb = nb_owner(a)
        ranked = sorted((s for s in free if authentic(s)),
                        key=lambda s: (-votes[a][s], not (RX.match(s) and RX.match(s).group(1) in nb), s))
        pick = next((s for s in ranked if s not in used), None)  # scratch-object names never picked
        if not pick:
            continue
        used.add(pick)
        auth = [s for s in free if authentic(s)]
        # measured on already-named functions: sole authentic candidate 88.7% right
        conf = 'sole-authentic-candidate' if len(auth) == 1 else 'one-of-%d-authentic' % min(len(auth), 9)
        out[a] = {'name': pick, 'signature': U.get(pick), 'kind': 'code', 'inferred': True, 'confidence': conf,
                  'name_source': 'identity-unlock-inferred',
                  'alternatives': [s for s in ranked if s != pick][:8],
                  'evidence': [{'kind': 'exact-masked-body-candidates', 'length': n, 'candidates': len(free),
                                'authentic_candidates': len(auth), 'caller_votes': dict(votes[a]),
                                'neighbour_owners': sorted(nb)}]}
    api = {}
    p_api = NC / 'identity-unlock-reflect-inferred.json'
    if p_api.exists():
        api = json.load(open(p_api))
    for a in rem:
        if a in out:
            continue
        if a in api:  # bound by a reflection descriptor: API-derived name beats sub_<addr>
            out[a] = dict(api[a], alternatives=[], signature=None)
            continue
        r = att.get(a, {})
        own = r.get('owner_guess')
        nm = ('%s::sub_%s' % (own, a)) if own else 'sub_%s' % a
        out[a] = {'name': nm, 'signature': None, 'kind': 'code', 'inferred': True, 'confidence': 'placeholder',
                  'name_source': 'identity-unlock-inferred', 'alternatives': [],
                  'evidence': [{'kind': 'link-order-neighbours', 'library': r.get('library'),
                                'prev': r.get('prev'), 'next': r.get('next'), 'reach': r.get('reach')}]}
    out = {a: r for a, r in out.items() if a not in promoted}
    for fn in ('identity-unlock-wsfp-inferred.json', 'identity-unlock-ws-inferred.json'):
        p_ws = NC / fn  # WebService.pdb evidence (94-96% measured) beats placeholders / one-of-N guesses
        if p_ws.exists():
            for a, r in json.load(open(p_ws)).items():
                if a not in real and (a not in out or out[a]['confidence'] != 'sole-authentic-candidate'):
                    out[a] = r
    p_wg = NC / 'identity-unlock-wsgraph-inferred.json'
    if p_wg.exists():  # WebService graph match (~65% on hidden named functions): placeholders only
        for a, r in json.load(open(p_wg)).items():
            if a in out and out[a]['confidence'] == 'placeholder':
                out[a] = r
    p_dc = NC / 'identity-unlock-dupctor.json'
    if p_dc.exists():  # bogus-duplicate descriptor ctors: member-pointer evidence, not validated
        for a, r in json.load(open(p_dc)).items():
            if a not in real:
                out[a] = dict(r, inferred=True, confidence='descriptor-member-pointer', alternatives=[])
    json.dump(out, open(OUT, 'w'), indent=1, sort_keys=True)
    print(json.dumps({'remaining': len(rem) - len(promoted), 'inferred': len(out),
                      'confidence': Counter(r['confidence'] for r in out.values())}))


if __name__ == '__main__':
    main()
