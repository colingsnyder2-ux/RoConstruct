"""Route 5: name unnamed functions from source definition order.

MSVC emits a translation unit's non-inline functions in definition order, and the linker
keeps each object's functions together.  For a run of g unnamed functions between named
neighbours P and N (adjacent in address order), an authentic rbxgs 2007 .cpp that defines
both P and N with exactly g namespace-scope definitions between them names the run in
order.  Any inline/template/COMDAT function in the gap breaks the count, so the run is
then skipped (no partial guesses).  The MSVC symbol comes from the compiled-object index
(undname must give the same qualified name; overloads must be unique).
Output: work/native-client/identity-unlock-srcorder.json
"""
import glob
import gzip
import json
import pickle
import re
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from identity_unlock_common import ROOT, REG, CODE_STARTS, unnamed, undname_many, dump_json  # noqa: E402

NC = ROOT / 'work/native-client'
OUT = NC / 'identity-unlock-srcorder.json'
KEYWORDS = {'if', 'for', 'while', 'switch', 'return', 'sizeof', 'catch', 'defined', 'BOOST_STATIC_ASSERT'}


def untemplate(s):
    depth, out = 0, []
    for ch in s:
        depth += ch == '<'
        if not depth:
            out.append(ch)
        depth -= ch == '>' and depth > 0
    return ''.join(out)


def strip_code(txt):
    txt = re.sub(r'/\*.*?\*/', ' ', txt, flags=re.S)
    txt = re.sub(r'//[^\n]*', '', txt)
    txt = re.sub(r'"(?:\\.|[^"\\])*"', '""', txt)
    txt = re.sub(r"'(?:\\.|[^'\\])*'", "''", txt)
    return re.sub(r'^\s*#[^\n]*', '', txt, flags=re.M)


def definitions(path):
    """Qualified names of namespace-scope function definitions, in source order."""
    txt = strip_code(open(path, errors='ignore').read())
    out, stack, depth, buf, i = [], [], 0, '', 0
    while i < len(txt):
        ch = txt[i]
        if ch == '{':
            head = ' '.join(buf.split())
            m = re.match(r'(?:namespace\s+(\w+)|namespace)\s*$', head)
            if depth == len(stack) and m:
                stack.append(m.group(1) or '')
                depth += 1
            elif depth == len(stack) and '(' in head and not re.search(r'\b(class|struct|enum|union)\b[^(]*$', head) \
                    and '=' not in head.split('(')[0]:
                h = untemplate(re.sub(r'^template\s*<[^{]*?>\s*', '', head))
                pre = h.split('(')[0].split()
                name = pre[-1] if pre else ''
                if name.startswith('operator') or (pre[-2:-1] and pre[-2].endswith('operator')):
                    name = ''
                if name and re.match(r'^(?:\w+::)*~?\w+$', name) and name.split('::')[-1] not in KEYWORDS:
                    ns = [s for s in stack if s]
                    out.append('::'.join(ns + [name]) if ns and not name.startswith(ns[0] + '::') else name)
                # skip the body
                d, i = 1, i + 1
                while i < len(txt) and d:
                    d += txt[i] == '{'
                    d -= txt[i] == '}'
                    i += 1
                buf = ''
                continue
            else:
                depth += 1
            buf = ''
        elif ch == '}':
            depth -= 1
            while stack and len(stack) > depth:
                stack.pop()
            buf = ''
        elif ch == ';':
            buf = ''
        else:
            buf += ch
        i += 1
    return out


def qual_of(sig):
    q = untemplate(sig).split('(')[0].split()
    return q[-1] if q else None


def main():
    targets = set(unnamed())
    done = set(json.load(open(NC / 'unnamed-identities.json')))
    files = [p for p in glob.glob(str(ROOT / 'tools/rbxgs/Client/**/*.cpp'), recursive=True)
             if not Path(p).name.startswith('roc_')]
    defs = {}
    for p in files:
        try:
            d = definitions(p)
        except Exception:
            continue
        if len(d) >= 2:
            defs[p] = d
    print('source files', len(defs), 'definitions', sum(map(len, defs.values())), flush=True)
    pos = defaultdict(list)  # qual -> [(file, index)]
    for p, d in defs.items():
        for k, q in enumerate(d):
            pos[q].append((p, k))
    code = [('%08x' % va) for va in CODE_STARTS if REG['%08x' % va]['kind'] == 'code']
    named_at = {a for a in code if a not in targets or a in done}
    und = undname_many(sorted({REG[a]['name'] for a in named_at if not REG[a].get('placeholder')}))

    def q_at(a):
        n = REG[a]['name']
        return qual_of(und.get(n, '')) if a not in done else None

    runs = []
    k = 0
    while k < len(code):
        if code[k] in named_at:
            j = k + 1
            while j < len(code) and code[j] not in named_at:
                j += 1
            if j < len(code) and j > k + 1:
                runs.append((code[k], code[k + 1:j], code[j]))
            k = j
        else:
            k += 1
    print('unnamed runs', len(runs), 'functions', sum(len(r[1]) for r in runs), flush=True)
    found = {}
    for p, gap, n in runs:
        qp, qn = q_at(p), q_at(n)
        if not qp or not qn or qp == qn:
            continue
        hits = []
        for f, ip in pos.get(qp, ()):
            for g, jn in pos.get(qn, ()):
                if g == f and jn - ip - 1 == len(gap):
                    hits.append((f, ip))
        if len(hits) != 1:
            continue
        f, ip = hits[0]
        names = defs[f][ip + 1:ip + 1 + len(gap)]
        for a, q in zip(gap, names):
            if a in targets and a not in done:
                found[a] = (q, f, qp, qn)
    print('source-order candidates', len(found), flush=True)
    # MSVC symbols from the compiled-object index
    want = {q for q, *_ in found.values()}
    leafs = {q.split('::')[-1].lstrip('~') for q in want}
    syms = set()
    for p in sorted(NC.glob('identity-unlock-objindex*.pkl.gz')):
        with gzip.open(p, 'rb') as fh:
            syms.update(r[0] for r in pickle.load(fh)['funcs'])
    taken = {v['name'] for v in REG.values() if not v.get('placeholder')}
    pick = []
    for s in syms:
        m = re.match(r'\?(?:\?[01])?(\w+)@', s)
        if s not in taken and m and m.group(1) in leafs:
            pick.append(s)
    u = undname_many(pick)
    by_q = defaultdict(set)
    for s in pick:
        q = qual_of(u.get(s, ''))
        if q in want:
            by_q[q].add(s)
    out, nosym = {}, 0
    for a, (q, f, qp, qn) in found.items():
        cands = by_q.get(q, set())
        if len(cands) != 1:
            nosym += 1
            continue
        s = next(iter(cands))
        out[a] = {'name': s, 'owner_class': None, 'signature': u.get(s), 'kind': 'code',
                  'name_source': 'identity-unlock-srcorder',
                  'evidence': [{'kind': 'source-definition-order', 'source': str(Path(f).relative_to(ROOT)).replace('\\', '/'),
                                'qual': q, 'prev': qp, 'next': qn},
                               {'kind': 'decorated-signature', 'symbol': s, 'from': 'compiled-object index'}]}
    dump_json(out, OUT)
    print('named', len(out), 'no unique symbol', nosym)


if __name__ == '__main__':
    main()
