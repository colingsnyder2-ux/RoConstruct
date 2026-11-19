"""Route 11: name unnamed vtable slots from sibling classes that share the base introducing the slot.

Slot k of class D's primary vtable is an override of the virtual that some base B (in D's RTTI
primary chain, offset 0) declares at slot k.  Any other class C that also derives from B and
names its own slot k (or B itself) gives the method: rewrite the donor symbol's owner to D.
Kept only when
  - the target appears in exactly one vtable (no ICF/template sharing, so the owner is D),
  - every donor agrees on one rewritten symbol, and undname(new) == undname(donor) with the
    donor owner's printed name replaced by D's (parameter types and backreferences survive),
  - the name is not already in the registry or unnamed-identities.json.
--validate hides every already-named single-vtable slot owned by its vtable class and reports
how often the route reproduces it.
Output: work/native-client/identity-unlock-vtsib.json
"""
import json
from functools import lru_cache
import re
import subprocess
import sys
from collections import Counter, defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from identity_unlock_common import ROOT, REG, u32, undname_many, dump_json  # noqa: E402
from identity_unlock_vtable import vt_qual, slots, head_of  # noqa: E402

NC = ROOT / 'work/native-client'
OUT = NC / 'identity-unlock-vtsib.json'


ACCESS = {'private': 'E', 'protected': 'M', 'public': 'U'}


@lru_cache(None)
def header_access(pairs):
    """{(class leaf, method): set of access levels} for methods declared inside an authentic
    header body of that class (roc_* scratch and archives excluded)."""
    import identity_unlock_merge as M
    dirs = M.HEADER_DIRS + [str(p.relative_to(ROOT)) for p in ROOT.glob('tools/vc2008rtm/*/VC/include')] +         [str(p.relative_to(ROOT)) for p in ROOT.glob('tools/vc2008rtm/*/VC/atlmfc/include')]
    want = defaultdict(set)
    for c, m in pairs:
        want[c].add(m)
    out = defaultdict(set)
    names = sorted(want)
    for i in range(0, len(names), 300):
        alt = '|'.join(names[i:i + 300])
        files = subprocess.run(['rg', '-uu', '-l', '-g', '*.h', '-g', '*.hpp', '-g', '*.inl', '-g', '!roc_*',
                                '-g', '!*_archive*', r'\b(class|struct)\s+(\w+\s+)?(%s)\b' % alt] +
                               [str(ROOT / d) for d in dirs], capture_output=True, text=True,
                               encoding='utf-8', errors='ignore').stdout.split()
        hd = re.compile(r'\b(class|struct)\s+(?:\w+\s+)?(%s)\b[^;{(]*\{' % alt)
        for f in files:
            txt = re.sub(r'//[^\n]*|/\*.*?\*/', '', open(f, encoding='utf-8', errors='ignore').read(), flags=re.S)
            for mt in hd.finditer(txt):
                cls, acc, depth, j = mt.group(2), 'private' if mt.group(1) == 'class' else 'public', 1, mt.end()
                body_start = j
                while j < len(txt) and depth:
                    depth += {'{': 1, '}': -1}.get(txt[j], 0)
                    j += 1
                body, flat, d = txt[body_start:j], [], 0
                for ch in body:  # top-level text of the class body only (nested bodies dropped)
                    if ch == '}':
                        d -= 1
                    if d == 0:
                        flat.append(ch)
                    if ch == '{':
                        d += 1
                flat = ''.join(flat)
                for tok in re.finditer(r'\b(public|protected|private)\s*:|\b(\w+)\s*\(', flat):
                    if tok.group(1):
                        acc = tok.group(1)
                    elif tok.group(2) in want[cls]:
                        out[(cls, tok.group(2))].add(acc)
    return out


def load():
    vts = {}
    for a, v in REG.items():
        if v['kind'] == 'vtable':
            q = vt_qual(v['name'])
            if q:
                vts[int(a, 16)] = (q, slots(int(a, 16)))
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
    return vts, td_vt, bases


def main(validate=False):
    vts, td_vt, bases = load()
    quals = sorted({q for q, _ in vts.values()}, key=len, reverse=True)
    owners = defaultdict(set)
    for va, (q, sl) in vts.items():
        for t in sl:
            owners[t].add(va)
    derived = defaultdict(set)  # base td -> vtables deriving from it (offset 0)
    for va, bl in bases.items():
        for b in bl:
            derived[b].add(va)
    real = json.load(open(NC / 'unnamed-identities.json'))
    name = {a: v['name'] for a, v in REG.items() if not v.get('placeholder') and not v['name'].startswith('func_')}
    for a, r in real.items():
        if r['name_source'] != 'identity-unlock-vtsib':
            name.setdefault(a, r['name'])

    def owner_q(sym):
        head = head_of(sym)
        if not head:
            return None, None
        rest = sym[len(head):]
        return head, next((q for q in quals if rest.startswith(q)), None)

    def chain(c):
        return {vts[c][0]} | {vts[td_vt[b]][0] for b in bases.get(c, []) if b in td_vt}

    # targets: single-vtable slots, unnamed (or, when validating, named and owned by that vtable class)
    tasks = []
    for va, (q, sl) in vts.items():
        if va not in bases:
            continue
        for k, t in enumerate(sl):
            if len(owners[t]) != 1:
                continue
            if validate:
                if t in name and owner_q(name[t])[1] == q:
                    tasks.append((va, k, t))
            elif t not in name:
                tasks.append((va, k, t))
    cands = {}
    for va, k, t in tasks:
        q = vts[va][0]
        news = {}
        for b in bases[va]:
            bva = td_vt.get(b)
            if bva is None or k >= len(vts[bva][1]):
                continue
            bs = '__purecall' if REG.get(vts[bva][1][k], {}).get('name') == '__purecall' else name.get(vts[bva][1][k])
            if not bs or bs.startswith(('??_E', '??_G')):
                continue  # the base must name (or declare pure) slot k; deleting dtors are E/G-ambiguous
            bleaf = None
            if bs != '__purecall':
                bh, bo = owner_q(bs)
                if bo not in chain(bva):
                    continue  # ICF-shared body named after an unrelated class
                bleaf = bh
            for c in derived[b] | {bva}:
                if c == va or k >= len(vts[c][1]):
                    continue
                d = vts[c][1][k]
                s = name.get(d)
                if not s or s == '__purecall' or d == t:
                    continue
                head, oq = owner_q(s)
                if oq not in chain(c) or head.startswith(('??_E', '??_G')) or (bleaf and head != bleaf):
                    continue
                e = news.setdefault(head + q + s[len(head) + len(oq):], [s, oq, REG['%08x' % c]['name'], set(), False])
                e[3].add(c)
                e[4] |= bleaf is None
        if news:
            cands[t] = (va, k, news)
    syms = {'??_7' + vts[va][0] + '6B@' for va in vts}
    for va, k, news in cands.values():
        for n, (s, oq, *_) in news.items():
            syms.update([n, s, '??_7' + oq + '6B@'])
    und = undname_many(sorted(syms))

    def cls(q):
        s = und.get('??_7' + q + '6B@', '')
        return s.replace('const ', '', 1).rsplit('::`vftable', 1)[0] if '`vftable' in s else None

    import identity_unlock_merge as M
    taken = set(name.values())
    picks, st = {}, Counter()
    for t, (va, k, news) in cands.items():
        D = cls(vts[va][0])
        good = {}
        for n, (s, oq, dv, dn, pure) in news.items():
            B = cls(oq)
            if D and B and n in und and s in und and und[s].replace(B + '::', D + '::') == und[n]:
                good.setdefault(n, (s, dv, len(dn)))
        if len(good) != 1:
            st['ambiguous' if good else 'unverified'] += 1
            continue
        n, (s, dv, nd) = good.popitem()
        head = head_of(n)
        if not head.startswith('?') or head.startswith('??'):
            st['not-a-method'] += 1
            continue
        picks[t] = (va, k, n, s, dv, nd, D, M.untemplate(D).split('::')[-1], head[1:-1])
    acc_of = header_access(frozenset((p[7], p[8]) for p in picks.values()))
    out = {}
    for t, (va, k, n, s, dv, nd, D, dleaf, leaf) in picks.items():
        acc = acc_of.get((dleaf, leaf), set())
        if len(acc) != 1:
            st['not-declared-in-header' if not acc else 'header-access-ambiguous'] += 1
            continue
        i = len(head_of(n)) + len(vts[va][0])
        if n[i] not in 'EMU':
            st['not-virtual'] += 1
            continue
        n = n[:i] + ACCESS[acc.pop()] + n[i + 1:]
        if validate:
            st[('right' if n == name[t] else 'wrong', min(nd, 3))] += 1
            if n != name[t]:
                print('WRONG', t, name[t], '->', n)
            continue
        if n in taken:
            st['taken'] += 1
            continue
        out[t] = {'name': n, 'owner_class': D, 'signature': None, 'kind': 'code',
                  'name_source': 'identity-unlock-vtsib',
                  'evidence': [{'kind': 'vtable-slot-sibling', 'vtable': REG['%08x' % va]['name'], 'slot': k,
                                'donor_vtable': dv, 'donor_symbol': s, 'donors': nd},
                               {'kind': 'owner-header-declares-method', 'class': dleaf, 'method': leaf}]}
    per = Counter(r['name'] for r in out.values())
    out = {a: r for a, r in out.items() if per[r['name']] == 1}
    if not validate:
        dump_json(out, OUT)
    print('tasks', len(tasks), 'named', len(out), dict(st))


if __name__ == '__main__':
    main('--validate' in sys.argv)
