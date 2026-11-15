"""Route 2: name unnamed primary-vtable slot targets from RTTI.

For slot k of class D's primary vtable whose target is unnamed:
  base  - walk D's RTTI base-class array (nearest first, non-virtual, offset 0) and take
          the first base whose primary vtable names slot k (not __purecall); rewrite the
          owner qualifier B -> D.
  peer  - another instantiation of the same outermost class template names slot k;
          rewrite the qualifier.
  dtor  - a ??_E / ??_G slot becomes D's scalar/vector deleting destructor.
A rewrite is kept only when undname(new) equals undname(old) with B's printed name
replaced by D's (so backreferences and parameter types survive) and the slot target is
unique to one vtable class.  Output: work/native-client/identity-unlock-vtable.json.
"""
import json
import re
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from identity_unlock_common import ROOT, REG, u32, unnamed, undname_many  # noqa: E402

OUT = ROOT / 'work/native-client/identity-unlock-vtable.json'
CODE = {a for a, v in REG.items() if v['kind'] == 'code'}
IUNKNOWN_HOSTS = ('?$CComObject@', '?$CComContainedObject@', '?$CComAggObject@', '?$CComObjectNoLock@',
                  '?$CComObjectCached@', '?$CComPolyObject@', '?$CComObjectStack@', '?$CComObjectGlobal@')
IUNKNOWN = [('?QueryInterface@', 'UAGJABU_GUID@@PAPAX@Z'), ('?AddRef@', 'UAGKXZ'), ('?Release@', 'UAGKXZ')]


def vt_qual(name):
    """Primary vtable '??_7<qual>6B@' -> qual including its terminating '@'."""
    m = re.match(r'\?\?_7(.*@)6B@$', name)
    return m.group(1) if m else None


def slots(va):
    out = []
    for k in range(512):
        if k and ('%08x' % (va + 4 * k)) in REG and REG['%08x' % (va + 4 * k)]['kind'] != 'code':
            break
        t = '%08x' % u32(va + 4 * k)
        if t not in CODE:
            break
        out.append(t)
    return out


def head_of(sym):
    if sym.startswith(('??_E', '??_G')):
        return sym[:4]
    if sym.startswith('??') and sym[2] not in '_$01':
        return sym[:3]
    if sym.startswith('?') and not sym.startswith(('??', '?$')):
        return sym[:sym.index('@') + 1]
    return None


def main():
    targets = set(unnamed())
    vts = {}
    for a, v in REG.items():
        if v['kind'] == 'vtable':
            q = vt_qual(v['name'])
            if q:
                va = int(a, 16)
                vts[va] = (q, slots(va))
    # RTTI: type descriptor -> primary vtable, vtable -> base td list
    td_vt, bases = {}, {}
    for va in vts:
        col = u32(va - 4)
        try:
            if u32(col + 4) != 0:
                continue
            td, chd = u32(col + 12), u32(col + 16)
            n, arr = u32(chd + 8), u32(chd + 12)
            bl = []
            for i in range(1, min(n, 64)):
                bcd = u32(arr + 4 * i)
                if u32(bcd + 8) == 0 and u32(bcd + 12) == 0xffffffff:
                    bl.append(u32(bcd))
        except Exception:
            continue
        td_vt[td] = va
        bases[va] = bl
    owners = defaultdict(set)
    for va, (q, sl) in vts.items():
        for t in sl:
            owners[t].add(q)
    by_template = defaultdict(list)
    for va, (q, sl) in vts.items():
        if q.startswith('?$'):
            by_template[q[:q.index('@') + 1]].append(va)

    cands = {}  # addr -> list of (newsym, oldsym, Dqual, Bqual, evidence)
    for va, (q, sl) in vts.items():
        for k, t in enumerate(sl):
            if t not in targets or len(owners[t]) != 1:
                continue
            if k < 3 and q.startswith(IUNKNOWN_HOSTS):
                # ATL object wrappers implement IUnknown first (atlcom.h): QI, AddRef, Release
                new = IUNKNOWN[k][0] + q + IUNKNOWN[k][1]
                cands.setdefault(t, []).append((new, new, q, q, {'kind': 'vtable-slot-iunknown',
                                                                'vtable': REG['%08x' % va]['name'], 'slot': k}))
                continue
            donors = [('base', td_vt[b]) for b in bases.get(va, []) if b in td_vt]
            if q.startswith('?$'):
                donors += [('peer', p) for p in by_template[q[:q.index('@') + 1]] if p != va]
            for why, bva in donors:
                bq, bsl = vts[bva]
                if k >= len(bsl):
                    continue
                row = REG[bsl[k]]
                if row.get('placeholder') or row['name'] == '__purecall' or bsl[k] == t:
                    continue
                head = head_of(row['name'])
                if not head or not row['name'][len(head):].startswith(bq):
                    continue
                rest = row['name'][len(head) + len(bq):]
                cands.setdefault(t, []).append((head + q + rest, row['name'], q, bq,
                                                {'kind': 'vtable-slot-' + why, 'vtable': REG['%08x' % va]['name'],
                                                 'slot': k, 'donor_vtable': REG['%08x' % bva]['name'],
                                                 'donor_symbol': row['name']}))
                if why == 'base':
                    break  # nearest named base wins
    # verify via undname
    syms = set()
    for lst in cands.values():
        for new, old, q, bq, _ in lst:
            syms.update([new, old, '??_7' + q + '6B@', '??_7' + bq + '6B@'])
    und = undname_many(sorted(syms))

    def cls(q):
        s = und.get('??_7' + q + '6B@', '')
        return s.replace('const ', '', 1).rsplit('::`vftable', 1)[0] if '`vftable' in s else None

    out, stats = {}, defaultdict(int)
    for t, lst in cands.items():
        good = {}
        for new, old, q, bq, ev in lst:
            D, B = cls(q), cls(bq)
            if not D or not B or new not in und or old not in und:
                continue
            if und[old].replace(B + '::', D + '::') != und[new]:
                continue
            good.setdefault(new, (ev, D))
        if len(good) != 1:
            stats['ambiguous' if good else 'unverified'] += 1
            continue
        new, (ev, D) = good.popitem()
        stats[ev['kind']] += 1
        out[t] = {'name': new, 'owner_class': D, 'signature': und[new], 'kind': 'code',
                  'name_source': 'identity-unlock-vtable',
                  'evidence': [ev, {'kind': 'decorated-signature', 'symbol': new}]}
    json.dump(out, open(OUT, 'w'), indent=1, sort_keys=True)
    print(len(out), dict(stats))


if __name__ == '__main__':
    main()
