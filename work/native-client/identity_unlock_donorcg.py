"""Route 4b: name unnamed functions from the iOS 2013 donor call graph.

Donor pseudo-C (local/references/ios-2013-12_*) names ~88k functions and their direct
calls.  An unnamed 2008 function whose named callees (registry names, undnamed to
qualified names that the donor also defines) are ALL called by exactly one donor
function that has no 2008 address yet, is that donor function.  >=2 anchors required;
names accepted in a round become anchors for the next (fixpoint).
The MSVC symbol comes from the compiled-object index (undname must give the same
qualified name; overloads must agree on parameter count with the donor signature).
Output: work/native-client/identity-unlock-donorcg.json
"""
import glob
import gzip
import json
import pickle
import re
import subprocess
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from identity_unlock_common import ROOT, REG, CODE_STARTS, unnamed, undname_many, dump_json  # noqa: E402
from identity_unlock_align import target_refs  # noqa: E402

NC = ROOT / 'work/native-client'
OUT = NC / 'identity-unlock-donorcg.json'
DONOR = next(iter(glob.glob(str(ROOT / 'local/references/ios-2013-12_*'))))
CALL = re.compile(r'([A-Za-z_~][\w:~]*)\s*\(')


def untemplate(s):
    depth, out = 0, []
    for ch in s:
        depth += ch == '<'
        if not depth:
            out.append(ch)
        depth -= ch == '>'
    return ''.join(out)


def split_params(s):
    depth, n, any_ = 0, 1, False
    for ch in s:
        depth += ch in '<('
        depth -= ch in '>)'
        n += ch == ',' and depth == 0
        any_ = any_ or not ch.isspace()
    return n if any_ and s.strip() != 'void' else 0


def donor():
    """qual -> (callee quals in order, param count) for every donor function."""
    fn = {}
    # one multithreaded rg read; per-file open() of 88k small files is disk-bound
    dump = subprocess.run(['rg', '-uu', '--no-heading', '-H', '-N', '-g', '*.c', '', DONOR],
                          capture_output=True, text=True, encoding='utf-8', errors='ignore').stdout
    files = defaultdict(list)
    for line in dump.splitlines():
        i = line.find('.c:')
        if i > 0:
            files[line[:i + 2]].append(line[i + 3:])
    del dump
    for path, lines in files.items():
        txt = '\n'.join(lines)
        m = next((x for x in re.finditer(r'/\* (.*?)\s*\*/', txt, re.S)
                  if '(' in x.group(1) and not x.group(1).startswith('WARNING')), None)
        if not m:
            continue
        head = ' '.join(m.group(1).split())
        q = untemplate(head)
        i = q.find('(')
        if i < 0:
            continue
        qual = q[:i].strip().split()[-1] if q[:i].strip() else None
        params = split_params(q[i + 1:q.rfind(')')])
        body = txt[m.end():]
        b = body.find('{')
        calls = CALL.findall(untemplate(body[b:])) if b >= 0 else []
        if qual and qual not in fn:
            fn[qual] = (calls, params)
    names = set(fn)
    return {q: ([c for c in cs if c in names and c != q], p) for q, (cs, p) in fn.items()}


def qual_of(sig):
    q = untemplate(sig).split('(')[0].split()
    return q[-1] if q else None


def main():
    targets = set(unnamed())
    D = donor()
    print('donor functions', len(D), flush=True)
    code = {a: v['name'] for a, v in REG.items() if v['kind'] == 'code' and not v.get('placeholder')}
    if '--sample' in sys.argv:  # quick check on N targets
        n = int(sys.argv[sys.argv.index('--sample') + 1])
        targets = set(sorted(targets)[::max(1, len(targets) // n)][:n])
    callees = {}
    for va in CODE_STARTS:
        a = '%08x' % va
        if a in targets:
            callees[a] = target_refs(va)[0]
    # a donor function already holding a 2008 address is not a candidate: match registry
    # names to donor quals by leaf name, then undname only those (plus every callee)
    leaf = {q.split('::')[-1].lstrip('~') for q in D}
    need = {code[c] for cs in callees.values() for c in cs if c in code}
    need |= {n for n in code.values() if (re.match(r'\?(?:\?[01])?(\w+)@', n) or [None, None])[1] in leaf}
    und = undname_many(sorted(need))
    print('undnamed', len(und), flush=True)
    qual = {a: qual_of(und[n]) for a, n in code.items() if n in und}
    taken = {q for q in qual.values() if q}
    by_callee = defaultdict(set)
    for q, (cs, _) in D.items():
        if q not in taken:
            for c in set(cs):
                by_callee[c].add(q)
    accepted = {}
    rnd = 0
    while True:
        rnd += 1
        got = {}
        for t, cs in callees.items():
            if t in accepted:
                continue
            anchors = sorted({qual.get(c) or (accepted[c][0] if c in accepted else None) for c in cs} - {None})
            anchors = [x for x in anchors if x in by_callee]
            if len(anchors) < 2:
                continue
            cand = set.intersection(*(by_callee[x] for x in anchors)) - {v[0] for v in accepted.values()}
            if len(cand) == 1:
                got[t] = (cand.pop(), anchors)
        per = defaultdict(list)
        for t, (q, _) in got.items():
            per[q].append(t)
        new = 0
        for t, (q, an) in got.items():
            if len(per[q]) == 1:
                accepted[t] = (q, an, rnd)
                new += 1
        print('round', rnd, 'new', new, 'total', len(accepted), flush=True)
        if not new:
            break
    # MSVC symbol for each donor qual from the compiled-object index
    want = {q for q, _, _ in accepted.values()}
    syms = set()
    for p in sorted(NC.glob('identity-unlock-objindex*.pkl.gz')):
        with gzip.open(p, 'rb') as fh:
            for row in pickle.load(fh)['funcs']:
                syms.add(row[0])
    regnames = set(code.values())
    leafs = defaultdict(set)
    for q in want:
        parts = q.split('::')
        leafs[parts[-1].lstrip('~')].add(q)
    pick = [s for s in syms if s not in regnames and re.match(r'\?(?:\?[01])?(\w+)@', s)
            and re.match(r'\?(?:\?[01])?(\w+)@', s).group(1) in leafs]
    u = undname_many(pick)
    by_q = defaultdict(list)
    for s in pick:
        sig = u.get(s, '')
        q = qual_of(sig)
        if q in want:
            i = untemplate(sig).find('(')
            j = untemplate(sig).rfind(')')
            by_q[q].append((s, split_params(untemplate(sig)[i + 1:j]), sig))
    out, miss = {}, 0
    for t, (q, an, r) in accepted.items():
        params = D[q][1]
        cs = [x for x in by_q.get(q, []) if x[1] in (params, params - 1)]  # donor lists `this`
        if len({s for s, _, _ in cs}) != 1:
            miss += 1
            continue
        s, _, sig = cs[0]
        out[t] = {'name': s, 'owner_class': None, 'signature': sig, 'kind': 'code',
                  'name_source': 'identity-unlock-donorcg',
                  'evidence': [{'kind': 'donor-callgraph', 'donor_qual': q, 'anchors': an[:6],
                                'anchor_count': len(an), 'round': r},
                               {'kind': 'decorated-signature', 'symbol': s, 'from': 'compiled-object index'}]}
    dump_json(out, OUT)
    print('bound quals', len(accepted), 'with msvc symbol', len(out), 'no unique symbol', miss)


if __name__ == '__main__':
    main()
