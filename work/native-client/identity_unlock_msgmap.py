"""Route 6: name unnamed MFC message-map handlers.

An AFX_MSGMAP_ENTRY table in .rdata (6 dwords: nMessage, nCode, nID, nLastID, nSig, pfn)
whose named handlers belong to class X pairs entry k with the k-th ON_* macro of the
authentic BEGIN_MESSAGE_MAP(X, ...) block (XTP 11.2.2 first, the version this exe links;
then native-classes and other trees, never roc_* scratch).  A block is used only when its
macro count equals the entry count and every already-named entry's method name equals the
macro's handler.  Handler names come from the macro argument (ON_COMMAND(id, OnFoo)) or the
macro body in afxmsg_.h / XTP headers (ON_WM_SIZE -> OnSize).  The MSVC symbol comes from the
compiled-object index (unique X::handler).  Output: work/native-client/identity-unlock-msgmap.json
"""
import glob
import gzip
import json
import pickle
import re
import struct
import sys
from collections import Counter, defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from identity_unlock_common import ROOT, REG, IMG, BASE, pe, u32, unnamed, undname_many  # noqa: E402

NC = ROOT / 'work/native-client'
OUT = NC / 'identity-unlock-msgmap.json'
CODE = {a for a, v in REG.items() if v['kind'] == 'code'}
SRC_TREES = ['tools/libs/xtp-11.2.2', 'rebuild/2008-06/native-classes', 'tools/libs/mfc-9.0-rtm',
             'tools/openrbx/Client', 'tools/rbxgs/Client']
MACRO_HDRS = ['tools/libs/mfc-9.0-rtm/atlmfc/include/afxmsg_.h'] + \
    glob.glob(str(ROOT / 'tools/libs/xtp-11.2.2/**/*.h'), recursive=True)


def entry(va):
    msg, code, nid, last, sig, pfn = struct.unpack_from('<6I', IMG, va - BASE)
    if msg < 0x10000 and sig < 100 and '%08x' % pfn in CODE and (last == 0 or last >= nid):
        return '%08x' % pfn
    return None


def macro_table():
    """ON_* macro -> ('fixed', name) | ('arg', index)."""
    out = {}
    for h in MACRO_HDRS:
        p = Path(h) if Path(h).is_absolute() else ROOT / h
        try:
            txt = open(p, errors='ignore').read().replace('\\\n', ' ')
        except OSError:
            continue
        for m in re.finditer(r'#define\s+(ON_\w+)\s*\(([^)]*)\)([^\n]*)', txt):
            name, params, body = m.group(1), [x.strip() for x in m.group(2).split(',')], m.group(3)
            f = re.search(r'ThisClass\s*::\s*(\w+)', body)
            if f:
                out.setdefault(name, ('fixed', f.group(1)))
            elif 'memberFxn' in params:
                out.setdefault(name, ('arg', params.index('memberFxn')))
    return out


def blocks(cls):
    """[(path, [handler-or-None per macro])] for BEGIN_MESSAGE_MAP(cls, ...) blocks."""
    res = []
    for tree in SRC_TREES:
        for p in glob.glob(str(ROOT / tree / '**/*.cpp'), recursive=True):
            if Path(p).name.startswith('roc_'):
                continue
            txt = open(p, errors='ignore').read()
            if 'BEGIN_MESSAGE_MAP' not in txt:
                continue
            txt = re.sub(r'/\*.*?\*/', ' ', txt, flags=re.S)
            txt = re.sub(r'//[^\n]*', '', txt)
            for m in re.finditer(r'BEGIN_MESSAGE_MAP\s*\(\s*' + re.escape(cls) + r'\s*,.*?\)(.*?)END_MESSAGE_MAP',
                                 txt, re.S):
                if '#if' in m.group(1):
                    continue  # conditional entries: count is not reliable
                res.append((p, re.findall(r'\b(ON_\w+)\s*\(([^()]*(?:\([^()]*\)[^()]*)*)\)', m.group(1))))
        if res:
            return res
    return res


def main():
    targets = set(unnamed())
    done = set(json.load(open(NC / 'unnamed-identities.json')))
    MT = macro_table()
    rd = next(s for s in pe.sections if s.Name.rstrip(b'\0') == b'.rdata')
    tables, seen = [], set()
    for i in range(0, rd.Misc_VirtualSize - 24, 4):
        va = BASE + rd.VirtualAddress + i
        pfn = '%08x' % u32(va + 20)
        if pfn in targets and pfn not in done and entry(va):
            s = va
            while entry(s - 24):
                s -= 24
            if s in seen:
                continue
            seen.add(s)
            ents, e = [], s
            while entry(e):
                ents.append(entry(e))
                e += 24
            tables.append((s, ents))
    print('tables', len(tables), flush=True)
    found, why = {}, Counter()
    for s, ents in tables:
        own = Counter()
        for p in ents:
            m = re.match(r'\?(\w+)@(\w+)@', REG[p]['name'])
            if m and not REG[p].get('placeholder'):
                own[m.group(2)] += 1
        if not own:
            why['no-named-entry'] += 1
            continue
        cls, n = own.most_common(1)[0]
        if n < 2 or n * 2 < sum(own.values()):
            why['owner-unclear'] += 1
            continue
        bl = blocks(cls)
        hit = []
        for path, macros in bl:
            if len(macros) != len(ents):
                continue
            hs = []
            for mac, args in macros:
                kind = MT.get(mac)
                a = [x.strip() for x in args.split(',')]
                h = kind[1] if kind and kind[0] == 'fixed' else (a[kind[1]] if kind and kind[1] < len(a) else
                                                                    (a[-1] if a and re.match(r'On\w+$', a[-1]) else None))
                hs.append(h.split('::')[-1] if h else None)
            ok = True
            for p, h in zip(ents, hs):
                m = re.match(r'\?(\w+)@', REG[p]['name'])
                if h and m and not REG[p].get('placeholder') and p not in targets and h != m.group(1):
                    ok = False
            if ok:
                hit.append((path, hs))
        if len(hit) != 1:
            why['no-matching-block' if not hit else 'several-blocks'] += 1
            continue
        path, hs = hit[0]
        for p, h in zip(ents, hs):
            if p in targets and p not in done and h:
                found.setdefault(p, set()).add((cls, h, path, '%08x' % s))
    found = {p: v.pop() for p, v in found.items() if len(v) == 1}
    print('handler candidates', len(found), dict(why), flush=True)
    want = {(c, h) for c, h, _, _ in found.values()}
    leafs = {h for _, h in want}
    taken = {v['name'] for v in REG.values() if not v.get('placeholder')}
    syms = set()
    for p in sorted(NC.glob('identity-unlock-objindex*.pkl.gz')):
        with gzip.open(p, 'rb') as fh:
            syms.update(r[0] for r in pickle.load(fh)['funcs'])
    pick = [s for s in syms if s not in taken and (re.match(r'\?(\w+)@', s) or [0, 0])[1] in leafs]
    u = undname_many(pick)
    by = defaultdict(set)
    for s in pick:
        m = re.match(r'\?(\w+)@(\w+)@@', s)
        if m and (m.group(2), m.group(1)) in want and u.get(s):
            by[(m.group(2), m.group(1))].add(s)
    # no compiled symbol: the handler signature is fixed by its macro, so take the decorated
    # tail of the same handler on other classes (must be unique) and the access level of the
    # authentic header declaration (public Q / protected I / private A)
    tails = defaultdict(set)
    for n in taken | syms:
        m = re.match(r'\?(\w+)@\w+@@[QIA](AE.*)$', n)
        if m and m.group(1) in leafs:
            tails[m.group(1)].add(m.group(2))

    def access(cls, h):
        for tree in SRC_TREES:
            for hp in glob.glob(str(ROOT / tree / '**/*.h'), recursive=True):
                if Path(hp).name.startswith('roc_'):
                    continue
                txt = open(hp, errors='ignore').read()
                m = re.search(r'\bclass\s+(?:\w+\s+)?' + cls + r'\b[^;{]*\{', txt)
                if not m:
                    continue
                d = re.search(r'\b' + h + r'\s*\(', txt[m.end():])
                if not d:
                    continue
                sec = re.findall(r'\b(public|protected|private)\s*:', txt[m.end():m.end() + d.start()])
                return {'public': 'Q', 'protected': 'I', 'private': 'A'}[sec[-1]] if sec else 'A'
        return None

    for p, (c, h, path, tab) in found.items():
        if len(by.get((c, h), ())) != 1 and len(tails.get(h, ())) == 1:
            acc = access(c, h)
            if acc:
                by[(c, h)] = {'?%s@%s@@%s%s' % (h, c, acc, next(iter(tails[h])))}
    u.update(undname_many([next(iter(v)) for v in by.values() if len(v) == 1]))
    out, nosym = {}, 0
    for p, (c, h, path, tab) in found.items():
        cs = by.get((c, h), set())
        if len(cs) != 1:
            nosym += 1
            continue
        s = cs.pop()
        out[p] = {'name': s, 'owner_class': c, 'signature': u.get(s), 'kind': 'code',
                  'name_source': 'identity-unlock-msgmap',
                  'evidence': [{'kind': 'message-map-entry', 'table': tab, 'class': c, 'handler': h,
                                'source': str(Path(path).relative_to(ROOT)).replace('\\', '/')},
                               {'kind': 'decorated-signature', 'symbol': s, 'from': 'compiled-object index'}]}
    json.dump(out, open(OUT, 'w'), indent=1, sort_keys=True)
    print('named', len(out), 'no unique symbol', nosym)


if __name__ == '__main__':
    main()
