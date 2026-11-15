"""Route 3: name unnamed callees from named callers' compiled call sequences.

For an unnamed function U with a named direct caller C: every compiled object that
defines C's decorated symbol (exact body or not) lists C's direct calls (E8 + REL32
relocation) in order.  When that list has the same length as the original C's direct
calls, and every original callee that already has a registry name equals the object's
symbol at the same position (at least one such anchor, no contradiction), the object's
symbol at U's position is a vote for U.  A name is kept when all votes agree, it is not
an existing registry name, and it is unique in the output.
Output: work/native-client/identity-unlock-calls.json
"""
import os
import json
import subprocess
import sys
import tempfile
from collections import defaultdict, Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from identity_unlock_common import ROOT, REG, BASE, IMG, MD, end_of, unnamed  # noqa: E402
from native_identity_closure import functions  # noqa: E402  (read-only reuse)

OUT = ROOT / 'work/native-client/identity-unlock-calls.json'
OBJ_ROOTS = [str(ROOT / d) for d in ('work', 'out', 'rebuild')]
CODE = sorted(int(a, 16) for a, v in REG.items() if v['kind'] == 'code')
CODESET = set(CODE)


def calls(va):
    o = va - BASE
    out = []
    for i in MD.disasm_lite(bytes(IMG[o:o + (end_of(va) - va)]), va):
        if i[2] == 'call' and i[3].startswith('0x'):
            t = int(i[3], 16)
            if t in CODESET:
                out.append(t)
    return out


def main():
    targets = set(unnamed())
    tset = {int(a, 16) for a in targets}
    callers = defaultdict(set)  # caller va -> unnamed callees
    seqs = {}
    for va in CODE:
        row = REG['%08x' % va]
        if row.get('placeholder'):
            continue
        s = calls(va)
        hit = tset.intersection(s)
        if hit:
            callers[va] = hit
            seqs[va] = s
    sym_of = {REG['%08x' % va]['name']: va for va in callers}
    print('unnamed with named callers', len(set().union(*callers.values())), 'callers', len(callers), flush=True)
    with tempfile.NamedTemporaryFile('w', suffix='.txt', delete=False, encoding='utf-8') as f:
        f.write(chr(10).join(sym_of) + chr(10))
    files = subprocess.run(['rg', '-uu', '-a', '-l', '-F', '-g', '*.obj', '-f', f.name] + OBJ_ROOTS,
                           capture_output=True, text=True, encoding='utf-8', errors='ignore').stdout.splitlines()
    os.unlink(f.name)
    print('objects', len(files), flush=True)
    import hashlib
    votes = defaultdict(lambda: defaultdict(set))
    seen = set()
    for p in files:
        try:
            raw = open(p, 'rb').read()
        except OSError:
            continue
        h = hashlib.sha1(raw).digest()
        if h in seen:
            continue
        seen.add(h)
        try:
            rows = list(functions(raw))
        except Exception:
            continue
        for symbol, body, relocs, refs in rows:
            va = sym_of.get(symbol)
            if va is None:
                continue
            ocalls = [name for at, name, kind, _ in refs if kind == 20 and at >= 1 and body[at - 1] == 0xE8]
            tcalls = seqs[va]
            if len(ocalls) != len(tcalls):
                continue
            anchors, bad = 0, False
            for t, o in zip(tcalls, ocalls):
                row = REG['%08x' % t]
                if not row.get('placeholder'):
                    if row['name'] == o:
                        anchors += 1
                    else:
                        bad = True
                        break
            if bad or not anchors:
                continue
            for t, o in zip(tcalls, ocalls):
                if t in tset:
                    votes['%08x' % t][o].add((symbol, os.path.relpath(p, ROOT)))
    taken = {v['name'] for v in REG.values() if not v.get('placeholder')}
    out = {}
    for a, syms in votes.items():
        syms = {s: v for s, v in syms.items() if s not in taken and s[:1] in '?_'}
        if len(syms) != 1:
            continue
        s, v = next(iter(syms.items()))
        v = sorted(v)
        out[a] = {'name': s, 'owner_class': None, 'signature': None, 'kind': 'code',
                  'name_source': 'identity-unlock-calls',
                  'evidence': [{'kind': 'caller-call-sequence', 'callers': sorted({c for c, _ in v})[:4],
                                'objects': [o for _, o in v][:3], 'votes': len(v)},
                               {'kind': 'decorated-signature', 'symbol': s}]}
    n = Counter(r['name'] for r in out.values())
    out = {a: r for a, r in out.items() if n[r['name']] == 1}
    json.dump(out, open(OUT, 'w'), indent=1, sort_keys=True)
    print('bound', len(out))


if __name__ == '__main__':
    main()
