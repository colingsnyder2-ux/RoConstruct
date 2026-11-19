"""Route 15: fix bogus-duplicate descriptor constructors from the member pointers they receive.

BoundFuncDesc<C, Sig, ...> / PropDescriptor<C, T> / SurfacePropDescriptor<...> constructors of
different instantiations compile to identical code, so library replay gave many addresses
one instantiation's name.  Each initializer passes named member-function pointers to its
constructor; their owner class C and parameter list pin the instantiation.  A constructor
address is named when, over all its initializers, exactly one compiled-object constructor
symbol of the same outer template undecorates to a class mentioning C and whose own
parameter list contains each pushed pointer's type.
--validate applies the rule to correctly named (non-bogus) descriptor constructors.
Output: work/native-client/identity-unlock-dupctor.json
"""
import gzip
import json
import pickle
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from identity_unlock_common import ROOT, REG, CODE_STARTS, insns, refs, undname_many, dump_json  # noqa: E402

NC = ROOT / 'work/native-client'
OUT = NC / 'identity-unlock-dupctor.json'
TEMPL = re.compile(r'\?\?(?:0|\$\?0.*?@)\?\$(\w+)@')


def tmpl_of(sym):
    m = TEMPL.match(sym)
    return m.group(1) if m and ('Desc' in m.group(1) or 'Prop' in m.group(1)) else None


def main(validate=False):
    d = json.load(open(NC / 'remaining-classified.json'))
    bogus = {a for a, v in d.items() if v.get('bucket') == 'bogus duplicate name'}
    real = json.load(open(NC / 'unnamed-identities.json'))
    name = {a: v['name'] for a, v in REG.items() if not v.get('placeholder') and not v['name'].startswith('func_')}
    name.update({a: r['name'] for a, r in real.items() if r['name_source'] != 'identity-unlock-dupctor'})
    # initializer call sites: ctor address -> list of pushed named code pointers per call
    sites = defaultdict(list)
    for va in CODE_STARTS:
        if not (0x7e0000 <= va < 0x7fa000):
            continue
        pushed = []
        for i in insns(va):
            r = refs(i)
            if i.mnemonic in ('push', 'mov') and r:
                pushed += ['%08x' % v for v in r if '%08x' % v in name and REG.get('%08x' % v, {}).get('kind') == 'code']
            if i.mnemonic == 'call' and r:
                t = '%08x' % r[0]
                n = name.get(t) or (REG.get(t) or {}).get('name') or ''
                if tmpl_of(n):
                    sites[t].append([p for p in pushed if name[p].startswith('?') and not name[p].startswith('??')])
                pushed = []
    tasks = {}
    for t, calls in sites.items():
        cur = (REG.get(t) or {}).get('name') or ''
        if validate:
            if t in bogus or t not in name:
                continue
        elif t not in bogus:
            continue
        ptrs = {p for c in calls for p in c}
        if ptrs:
            tasks[t] = (tmpl_of(cur), ptrs)
    universe = set()
    for p in sorted(NC.glob('identity-unlock-objindex*.pkl.gz')):
        dd = pickle.load(gzip.open(p))
        for s, _, calls, _ in dd['funcs']:
            universe.add(s)
            universe.update(calls)
    want_t = {tm for tm, _ in tasks.values()}
    pool = defaultdict(list)
    for s in universe:
        tm = tmpl_of(s)
        if tm in want_t:
            pool[tm].append(s)
    U = undname_many(sorted({s for v in pool.values() for s in v} |
                            {name[p] for _, ps in tasks.values() for p in ps}))
    mp = re.compile(r'__thiscall ([\w:]+)::\w+\(([^()]*)\)( const)?')
    taken = {v['name'] for v in REG.values() if not v.get('placeholder')} - {
        (REG.get(a) or {}).get('name') for a in bogus}
    out, st = {}, Counter()
    for t, (tm, ptrs) in tasks.items():
        need = []
        for p in ptrs:
            m = mp.search(U.get(name[p], ''))
            if m:
                need.append((m.group(1), '(__thiscall %s::*)(%s)%s' % (m.group(1), m.group(2), m.group(3) or '')))
        if not need or len({c for c, _ in need}) != 1:
            st['no-member-pointer'] += 1
            continue
        C = need[0][0]
        hits = [s for s in pool.get(tm, ()) if 'class %s' % C in U.get(s, '').split('::' + tm.split('@')[0])[0] + U.get(s, '')
                and all(x in U.get(s, '') for _, x in need)]
        hits = [s for s in hits if ('<class %s,' % C) in U.get(s, '') or ('<class %s>' % C) in U.get(s, '')]
        if len(hits) != 1:
            st['symbols-%s' % ('0' if not hits else 'n')] += 1
            continue
        n = hits[0]
        if validate:
            st['right' if n == name[t] else 'wrong'] += 1
            if n != name[t]:
                print('WRONG', t, name[t][:100], '->', n[:100])
            continue
        if n in taken:
            st['taken'] += 1
            continue
        out[t] = {'name': n, 'owner_class': None, 'signature': U[n], 'kind': 'code',
                  'name_source': 'identity-unlock-dupctor',
                  'evidence': [{'kind': 'descriptor-ctor-member-pointers', 'bogus_name': (REG.get(t) or {}).get('name'),
                                'member_functions': sorted(name[p] for p in ptrs)},
                               {'kind': 'compiled-object-symbol', 'symbol': n}]}
    per = Counter(r['name'] for r in out.values())
    out = {a: r for a, r in out.items() if per[r['name']] == 1}
    if not validate:
        dump_json(out, OUT)
    print('tasks', len(tasks), 'named', len(out), dict(st))


if __name__ == '__main__':
    main('--validate' in sys.argv)
