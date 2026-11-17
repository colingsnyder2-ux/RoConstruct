"""Route 14: fix 'bogus duplicate name' rows (one template-peer name on several addresses).

Identical-code template peers (FactoryProduct<X>::Creator::create, ...) were all given one
instantiation's name.  When such an address is a slot of exactly one primary vtable, that
vtable's class is the real owner: rewrite the name's owner qualifier to the vtable's
qualifier.  Kept only when undname(new) == undname(old) with the old owner's printed name
replaced by the new owner's (parameter types and back-references survive), the new name is
not already used, and the old owner is a vtable class of the same outer template.
Targets: remaining-classified.json bucket 'bogus duplicate name'.
Output: work/native-client/identity-unlock-dupfix.json
"""
import json
import sys
from collections import Counter, defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from identity_unlock_common import ROOT, REG, undname_many  # noqa: E402
from identity_unlock_vtable import head_of  # noqa: E402
from identity_unlock_vtsib import load  # noqa: E402

NC = ROOT / 'work/native-client'
OUT = NC / 'identity-unlock-dupfix.json'


def outer(q):
    """Outermost template of a vtable qualifier: 'Creator@?$FactoryProduct@' -> '?$FactoryProduct@'."""
    i = q.find('?$')
    return q[i:q.index('@', i) + 1] if i >= 0 else None


def targets():
    d = json.load(open(NC / 'remaining-classified.json'))
    return {a: v['name'] for a, v in d.items() if v.get('bucket') == 'bogus duplicate name'}


def main():
    tg = targets()
    vts, _, _ = load()
    quals = sorted({q for q, _ in vts.values()}, key=len, reverse=True)
    owners = defaultdict(set)
    for va, (q, sl) in vts.items():
        for t in sl:
            owners[t].add(q)
    cands, st, right = {}, Counter(), set()
    for a, n in tg.items():
        if len(owners[a]) != 1:
            st['vtables-%s' % ('0' if not owners[a] else 'n')] += 1
            continue
        q = next(iter(owners[a]))
        head = head_of(n)
        if not head:
            st['no-head'] += 1
            continue
        rest = n[len(head):]
        oq = next((x for x in quals if rest.startswith(x)), None)
        if not oq or outer(oq) != outer(q) or not outer(q):
            st['owner-not-peer'] += 1
            continue
        if oq == q:
            st['already-right'] += 1
            right.add(n)
            continue
        cands[a] = (head + q + rest[len(oq):], n, q, oq)
    und = undname_many(sorted({x for c in cands.values() for x in (c[0], c[1])} |
                              {'??_7' + x + '6B@' for c in cands.values() for x in (c[2], c[3])}))

    def cls(q):
        s = und.get('??_7' + q + '6B@', '')
        return s.replace('const ', '', 1).rsplit('::`vftable', 1)[0] if '`vftable' in s else None

    taken = {v['name'] for v in REG.values() if not v.get('placeholder')}
    taken -= set(tg.values())  # the bogus names themselves stay claimable by their real owner
    taken |= right  # ...unless a vtable proves another address already owns that name
    out = {}
    for a, (new, old, q, oq) in cands.items():
        D, B = cls(q), cls(oq)
        if not D or not B or new not in und or old not in und or und[old].replace(B + '::', D + '::') != und[new]:
            st['unverified'] += 1
            continue
        if new in taken:
            st['taken'] += 1
            continue
        out[a] = {'name': new, 'owner_class': D, 'signature': und[new], 'kind': 'code',
                  'name_source': 'identity-unlock-dupfix',
                  'evidence': [{'kind': 'vtable-slot-owner-rewrite', 'bogus_name': old,
                                'vtable': '??_7' + q + '6B@', 'old_owner': B, 'new_owner': D}]}
    per = Counter(r['name'] for r in out.values())
    out = {a: r for a, r in out.items() if per[r['name']] == 1}
    json.dump(out, open(OUT, 'w'), indent=1, sort_keys=True)
    print('bogus', len(tg), 'fixed', len(out), dict(st))


if __name__ == '__main__':
    main()
