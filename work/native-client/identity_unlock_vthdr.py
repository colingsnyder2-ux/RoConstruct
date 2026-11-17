"""Route 12: name unnamed vtable slots from the class header's virtual declaration order.

Slot model of class D (RTTI primary chain, nearest base B first):
  k < len(vtable(B))  -> the virtual B has at slot k (named slot symbol, else B's own model);
  k >= len(vtable(B)) -> the (k - len(B))-th new virtual declared in D's authentic header
                          (virtuals whose name B's slots do not already carry; all overloads of
                          one name sit together at the first declaration).
D's header must declare the leaf (an override is declared where it is defined).  The exact
decorated name must then be a symbol that compiled objects define or reference
('?leaf@<D qual>' with exactly one decoration), so no mangling is guessed.
--validate hides every already-named single-vtable slot owned by its class and reports how
often the route reproduces it.
Output: work/native-client/identity-unlock-vthdr.json
"""
import gzip
import json
import pickle
import re
import subprocess
import sys
from collections import Counter, defaultdict
from functools import lru_cache
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
import identity_unlock_merge as M  # noqa: E402
from identity_unlock_common import ROOT, REG, undname_many  # noqa: E402
from identity_unlock_vtable import head_of  # noqa: E402
from identity_unlock_vtsib import load  # noqa: E402

NC = ROOT / 'work/native-client'
OUT = NC / 'identity-unlock-vthdr.json'


@lru_cache(None)
def header_virtuals(classes):
    """{class leaf: [(name, has 'virtual')] in declaration order} for classes declared in
    authentic headers; a leaf declared with two different bodies maps to None (ambiguous)."""
    dirs = M.HEADER_DIRS + [str(p.relative_to(ROOT)) for p in ROOT.glob('tools/vc2008rtm/*/VC/include')] + \
        [str(p.relative_to(ROOT)) for p in ROOT.glob('tools/vc2008rtm/*/VC/atlmfc/include')]
    out = {}
    names = sorted(c for c in classes if re.match(r'\w+$', c))
    for i in range(0, len(names), 300):
        alt = '|'.join(names[i:i + 300])
        files = subprocess.run(['rg', '-uu', '-l', '-g', '*.h', '-g', '*.hpp', '-g', '*.inl', '-g', '!roc_*',
                                '-g', '!*_archive*', r'\b(class|struct)\s+(\w+\s+)?(%s)\b' % alt] +
                               [str(ROOT / d) for d in dirs],
                               capture_output=True, text=True, encoding='utf-8', errors='ignore').stdout.split()
        hd = re.compile(r'\b(class|struct)\s+(?:\w+\s+)?(%s)\b\s*(?::[^;{]*)?\{' % alt)
        for f in files:
            txt = open(f, encoding='utf-8', errors='ignore').read()
            txt = re.sub(r'//[^\n]*|/\*.*?\*/', '', txt, flags=re.S)
            for mt in hd.finditer(txt):
                cls, depth, j = mt.group(2), 1, mt.end()
                while j < len(txt) and depth:
                    depth += {'{': 1, '}': -1}.get(txt[j], 0)
                    j += 1
                flat, d = [], 0
                for ch in txt[mt.end():j]:
                    if ch == '}':
                        d -= 1
                        if d == 0:
                            flat.append(';')
                    if d == 0:
                        flat.append(ch)
                    if ch == '{':
                        d += 1
                decls = []
                for st in ''.join(flat).split(';'):
                    st = re.sub(r'\b(public|protected|private)\s*:', '', st).strip()
                    m = re.search(r'(~?\w+)\s*\(', st)
                    if not m or st.startswith(('typedef', 'friend', 'using')):
                        continue
                    decls.append((m.group(1), bool(re.search(r'\bvirtual\b', st))))
                if cls in out and out[cls] != decls:
                    out[cls] = None
                else:
                    out.setdefault(cls, decls)
    return out


def main(validate=False):
    vts, td_vt, bases = load()
    name = {a: v['name'] for a, v in REG.items() if not v.get('placeholder') and not v['name'].startswith('func_')}
    real = json.load(open(NC / 'unnamed-identities.json'))
    for a, r in real.items():
        if r['name_source'] != 'identity-unlock-vthdr':
            name.setdefault(a, r['name'])
    owners = defaultdict(set)
    for va, (q, sl) in vts.items():
        for t in sl:
            owners[t].add(va)
    und = undname_many(sorted('??_7' + q + '6B@' for q, _ in vts.values()))

    def cls(va):
        s = und.get('??_7' + vts[va][0] + '6B@', '')
        return s.replace('const ', '', 1).rsplit('::`vftable', 1)[0] if '`vftable' in s else None

    def leaf_cls(va):
        c = cls(va)
        return M.untemplate(c).split('::')[-1] if c else None

    hv = header_virtuals(frozenset(leaf_cls(va) for va in vts if leaf_cls(va)))

    def slot_leaf_named(va, k, hide):
        t = vts[va][1][k]
        if t == hide or REG.get(t, {}).get('name') == '__purecall':
            return None
        s = name.get(t)
        h = head_of(s) if s else None
        if h and h.startswith('??_'):
            return '~'
        return h[1:-1] if h and not h.startswith('??') else None

    @lru_cache(None)
    def model(va, hide):
        """Method leaf per slot of va's vtable (None = unknown)."""
        n = len(vts[va][1])
        bl = [td_vt[b] for b in bases.get(va, []) if b in td_vt]
        bm = model(bl[0], hide) if bl else ()
        # (leaf, trusted): named slots are trusted; header-derived slots only when the header's new
        # virtuals number exactly the vtable growth and agree with every named slot (>= 1 anchor)
        lv = []
        for k in range(min(len(bm), n)):
            own = slot_leaf_named(va, k, hide)
            lv.append((own, True) if own else bm[k])
        decl = hv.get(leaf_cls(va))
        new = []
        if decl:
            seen, order = {x for x, _ in bm}, []
            for nm, virt in decl:
                key = '~' if nm.startswith('~') else nm
                if virt and key not in seen and key not in order:
                    order.append(key)
            for key in order:
                new += [key] * sum(1 for x, v in decl if v and ('~' if x.startswith('~') else x) == key)
        base_n = len(lv)
        named = [(k, slot_leaf_named(va, k, hide)) for k in range(base_n, n)]
        agree = sum(1 for k, s in named if s and k - base_n < len(new) and new[k - base_n] == s)
        clash = sum(1 for k, s in named if s and (k - base_n >= len(new) or new[k - base_n] != s))
        ok = bool(decl) and len(new) == n - base_n and agree >= 1 and not clash
        for k in range(base_n, n):
            own = slot_leaf_named(va, k, hide)
            lv.append((own, True) if own else (new[k - base_n] if k - base_n < len(new) else None, ok))
        return tuple(lv)

    universe = set()
    for p in sorted(NC.glob('identity-unlock-objindex*.pkl.gz')):
        d = pickle.load(gzip.open(p))
        for s, _, calls, data in d['funcs']:
            universe.add(s)
            universe.update(calls)
            universe.update(data)
        for _, sl in d['vtables']:
            universe.update(x for _, x in sl)
    by_head_q = defaultdict(set)
    for s in universe:
        h = head_of(s) if s.startswith('?') else None
        if h and not h.startswith('??'):
            by_head_q[h].add(s)

    def symbol(va, leaf):
        q = vts[va][0]  # 'Cls@NS@@' or '?$T@..@@' (owner qual incl. the terminating '@')
        return {s for s in by_head_q.get('?' + leaf + '@', ()) if s[len(leaf) + 2:].startswith(q)}

    taken = set(name.values())
    out, st = {}, Counter()
    for va, (q, sl) in vts.items():
        if va not in bases:
            continue
        decl = hv.get(leaf_cls(va))
        if not decl:
            continue
        declared = {nm for nm, _ in decl}
        for k, t in enumerate(sl):
            if len(owners[t]) != 1:
                continue
            if validate:
                if t not in name or not name[t].startswith('?') or name[t].startswith('??') or                         not name[t][len(head_of(name[t]) or ''):].startswith(q):
                    continue  # only slots whose registry name is owned by this vtable's class
                lf, tr = model(va, t)[k]
            elif t in name:
                continue
            else:
                lf, tr = model(va, None)[k]
            if not lf or lf == '~' or lf not in declared or not tr:
                st['no-leaf' if not lf else 'dtor' if lf == '~' else 'not-declared' if lf not in declared
                   else 'header-order-unverified'] += 1
                continue
            hits = symbol(va, lf)
            if len(hits) != 1:
                st['symbols-%s' % ('0' if not hits else 'n')] += 1
                continue
            n = hits.pop()
            if validate:
                st['right' if n == name[t] else 'wrong'] += 1
                if n != name[t]:
                    print('WRONG', t, name[t], '->', n)
                continue
            if n in taken:
                st['taken'] += 1
                continue
            out[t] = {'name': n, 'owner_class': cls(va), 'signature': None, 'kind': 'code',
                      'name_source': 'identity-unlock-vthdr',
                      'evidence': [{'kind': 'vtable-slot-header-order', 'vtable': REG['%08x' % va]['name'],
                                    'slot': k, 'leaf': lf},
                                   {'kind': 'compiled-object-symbol', 'symbol': n}]}
    per = Counter(r['name'] for r in out.values())
    out = {a: r for a, r in out.items() if per[r['name']] == 1}
    if not validate:
        json.dump(out, open(OUT, 'w'), indent=1, sort_keys=True)
    print('named', len(out), dict(st))


if __name__ == '__main__':
    main('--validate' in sys.argv)
