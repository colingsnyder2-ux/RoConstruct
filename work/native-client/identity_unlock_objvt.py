"""Route 2b: compiler-reported vtable slots from any compiled object.

For every original vtable (registry ??_7 name) with an unnamed slot target, search all
*.obj under the given roots for an emitted table with the same ??_7 symbol.  The
object's relocation at slot offset k names the symbol the compiler put there (from the
native header's virtual order).  A slot is bound only when every object agrees, the
symbol is not already the registry name of another address, and the symbol is unique
among the output.  Output: work/native-client/identity-unlock-objvt.json.
Usage: identity_unlock_objvt.py [ROOT ...]   (default: work out rebuild)
"""
import hashlib
import json
import os
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from identity_unlock_common import ROOT, REG, u32, unnamed  # noqa: E402
from native_identity_closure import vtables  # noqa: E402  (read-only reuse)

OUT = ROOT / 'work/native-client/identity-unlock-objvt.json'
CODE = {a for a, v in REG.items() if v['kind'] == 'code'}
TAKEN = {v['name'] for v in REG.values() if not v.get('placeholder')}


def walk(roots, names):
    """Only objects whose bytes contain one of the wanted vtable symbols (ripgrep prefilter)."""
    import subprocess
    import tempfile
    with tempfile.NamedTemporaryFile('w', suffix='.txt', delete=False, encoding='utf-8') as f:
        f.write(chr(10).join(names) + chr(10))
    out = subprocess.run(['rg', '-uu', '-a', '-l', '-F', '-g', '*.obj', '-f', f.name] + roots,
                         capture_output=True, text=True, encoding='utf-8', errors='ignore').stdout
    os.unlink(f.name)
    return out.splitlines()


def main():
    roots = sys.argv[1:] or [str(ROOT / d) for d in ('work', 'out', 'rebuild')]
    targets = set(unnamed())
    want = {}  # vtable symbol -> (va, {offset: target})
    for a, v in REG.items():
        if v['kind'] != 'vtable':
            continue
        va, slots = int(a, 16), {}
        for k in range(512):
            if k and REG.get('%08x' % (va + 4 * k), {}).get('kind', 'code') != 'code':
                break
            t = '%08x' % u32(va + 4 * k)
            if t not in CODE:
                break
            if t in targets:
                slots[4 * k] = t
        if slots:
            want[v['name']] = (va, slots)
    keys = {n.encode(): n for n in want}
    votes = defaultdict(lambda: defaultdict(set))  # target -> symbol -> {obj sha}
    seen, nobj, nhit = set(), 0, 0
    for p in walk(roots, list(want)):
        try:
            raw = open(p, 'rb').read()
        except OSError:
            continue
        if b'??_7' not in raw:
            continue
        h = hashlib.sha1(raw).digest()
        if h in seen:
            continue
        seen.add(h)
        nobj += 1
        hits = [k for k in keys if k in raw]
        if not hits:
            continue
        nhit += 1
        try:
            tabs = list(vtables(raw))
        except Exception:
            continue
        for name, slots in tabs:
            if name not in want:
                continue
            for off, sym in slots:
                t = want[name][1].get(off)
                if t:
                    votes[t][sym].add(p)
    out = {}
    for t, syms in votes.items():
        syms = {s: ps for s, ps in syms.items() if s not in TAKEN}
        if len(syms) != 1:
            continue
        s, ps = next(iter(syms.items()))
        out[t] = {'name': s, 'owner_class': None, 'signature': None, 'kind': 'code',
                  'name_source': 'identity-unlock-objvt',
                  'evidence': [{'kind': 'compiled-vtable-slot', 'objects': sorted(os.path.relpath(x, ROOT) for x in ps)[:3],
                                'object_count': len(ps)}, {'kind': 'decorated-signature', 'symbol': s}]}
    names = defaultdict(list)
    for t, r in out.items():
        names[r['name']].append(t)
    out = {t: r for t, r in out.items() if len(names[r['name']]) == 1}
    json.dump(out, open(OUT, 'w'), indent=1, sort_keys=True)
    print('objects', nobj, 'with-wanted-vtable', nhit, 'bound', len(out))


if __name__ == '__main__':
    main()
