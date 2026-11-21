"""Route 4: name unnamed functions from the symbolized iOS 2013 donor by string literals.

1. Collect printable string literals each unnamed function references.
2. ripgrep the donor pseudo-C export for each literal (quoted); keep literals found in
   at most 3 donor functions.  The donor function's qualified name (its /* ... */ header
   comment) is a candidate; one candidate must win (majority, or the only one).
3. Map the donor C++ name to an MSVC decorated name that some compiled 2008-06 object
   already uses (defined or external), via ripgrep over *.obj: ?method@Class@NS@@...
   The candidate must not already name another registry address, and when overloads
   exist the undname parameter count must equal the donor's.
Donor evidence is a proposal only (docs/GHIDRA_REFERENCE.md); the native gate proves it.
Output: work/native-client/identity-unlock-donor.json
"""
import json
import re
import subprocess
import sys
import tempfile
from collections import Counter, defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from identity_unlock_common import ROOT, REG, BASE, IMG, insns, refs, unnamed, undname_many, dump_json  # noqa: E402

DONOR = ROOT / 'local/references/ios-2013-12_2.132.41333'
OUT = ROOT / 'work/native-client/identity-unlock-donor.json'
OBJ_ROOTS = [str(ROOT / d) for d in ('work', 'out', 'rebuild')]
TAKEN = {v['name'] for v in REG.values() if not v.get('placeholder')}


def cstr(va):
    o = va - BASE
    try:
        e = IMG.index(b'\0', o, o + 512)
    except ValueError:
        return None
    try:
        t = IMG[o:e].decode('ascii')
    except UnicodeDecodeError:
        return None
    return t if len(t) >= 6 and all(32 <= ord(c) < 127 for c in t) and '"' not in t and '\\' not in t else None


def rg(patterns, paths, extra):
    with tempfile.NamedTemporaryFile('w', suffix='.txt', delete=False, encoding='utf-8') as f:
        f.write('\n'.join(patterns) + '\n')
    out = subprocess.run(['rg', '-uu', '-a', '-o', '--no-line-number'] + extra + ['-f', f.name] + paths,
                         capture_output=True, text=True, encoding='utf-8', errors='ignore').stdout
    Path(f.name).unlink()
    return out.splitlines()


def donor_qual(path, cache={}):
    if path not in cache:
        q = None
        for line in open(path, encoding='utf-8', errors='ignore').read().splitlines()[:40]:
            m = re.match(r'/\* (.*) \*/$', line)
            if m and not m.group(1).startswith('WARNING') and '(' in m.group(1):
                q = m.group(1)
                break
        cache[path] = q
    return cache[path]


def split_donor(q):
    """'RBX::Network::Server::start(int, int)' -> (['RBX','Network','Server'], 'start', nparams)"""
    m = re.match(r'^(.*?)\((.*)\)\s*(const)?$', q)
    if not m or '<' in m.group(1):
        return None
    parts = m.group(1).split('::')
    if len(parts) < 2:
        return None
    params = m.group(2).strip()
    n = 0 if params in ('', 'void') else params.count(',') + 1
    return parts[:-1], parts[-1], n


def main():
    targets = unnamed()
    lits = {}
    for a in targets:
        s = {cstr(v) for i in insns(int(a, 16)) for v in refs(i) if 0x800000 <= v < 0x960000}
        s.discard(None)
        if s:
            lits[a] = s
    allp = sorted({'"%s"' % x for s in lits.values() for x in s})
    hits = defaultdict(set)
    for line in rg(allp, [str(DONOR)], ['-F', '-g', '*.c']):
        path, _, lit = line.partition(':"')
        hits[lit[:-1]].add(path)
    cands = {}
    for a, s in lits.items():
        c = Counter()
        why = defaultdict(list)
        for x in s:
            fs = hits.get(x, ())
            if 0 < len(fs) <= 3:
                for f in fs:
                    q = donor_qual(f)
                    if q:
                        c[q] += 1
                        why[q].append(x)
        if not c:
            continue
        top = c.most_common(2)
        if len(top) == 2 and top[0][1] == top[1][1]:
            continue
        q = top[0][0]
        sd = split_donor(q)
        if sd:
            cands[a] = (q, sd, why[q], [str(Path(f).relative_to(ROOT)) for f in hits[why[q][0]]][:3])
    # MSVC decorated names already present in compiled objects
    def prefix(scope, meth):
        q = '@'.join(reversed(scope)) + '@@'
        if meth == scope[-1]:
            return '??0' + q
        if meth == '~' + scope[-1]:
            return '??1' + q
        return '?%s@%s' % (meth, q)

    prefixes = {a: prefix(sd[0], sd[1]) for a, (q, sd, _, _) in cands.items()}
    pats = sorted({re.escape(p) + r'[!-~]+' for p in prefixes.values()})
    found = {line.strip() for line in rg(pats, OBJ_ROOTS, ['--no-filename', '-g', '*.obj'])}
    pool = defaultdict(set)
    for sym in found:
        for p in set(prefixes.values()):
            if sym.startswith(p):
                pool[p].add(sym)
    und = undname_many(sorted({s for v in pool.values() for s in v}))
    out, stats = {}, Counter()
    for a, (q, (scope, meth, n), why, files) in cands.items():
        syms = {s for s in pool.get(prefixes[a], ()) if s in und and s not in TAKEN}
        if len(syms) > 1:
            def nparams(sig):
                m = re.search(r'\((.*)\)', sig)
                p = m.group(1) if m else ''
                return 0 if p in ('', 'void') else p.count(',') + 1  # ponytail: no template-comma parsing
            syms = {s for s in syms if nparams(und[s]) == n}
        if len(syms) != 1:
            stats['ambiguous-msvc-name' if syms else 'no-msvc-name'] += 1
            continue
        s = syms.pop()
        stats['bound'] += 1
        owner = '::'.join(scope)
        out[a] = {'name': s, 'owner_class': owner, 'signature': und[s], 'kind': 'code',
                  'name_source': 'identity-unlock-donor',
                  'evidence': [{'kind': 'ios2013-donor-string', 'donor': q, 'literals': sorted(why)[:4],
                                'donor_files': files},
                               {'kind': 'decorated-signature', 'symbol': s}]}
    names = Counter(r['name'] for r in out.values())
    out = {a: r for a, r in out.items() if names[r['name']] == 1}
    dump_json(out, OUT)
    print('with-literals', len(lits), 'donor-candidates', len(cands), 'bound', len(out), dict(stats))


if __name__ == '__main__':
    main()
