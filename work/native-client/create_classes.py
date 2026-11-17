"""Resolve Creatable<Instance>::create<X> rows whose registry name is shared by several bodies (wrong for most): the
body calls X's constructor (`??0X@...`); its registry name gives X.  -> create-classes.json {addr: 'class RBX::X'}"""
import collections
import json
import re
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.argv = sys.argv[:1]
sys.path.insert(0, str(HERE))
import native_llm as m          # noqa: E402
from roc import match           # noqa: E402

reg = m.load_registry()
cl = json.loads((HERE / 'remaining-classified.json').read_text())
sig = lambda a: ((reg.get(a) or {}).get('signature') or '').strip()
rows = [a for a in cl if re.search(r'Creatable<class RBX::Instance>::create<', sig(a))]
shared = collections.Counter(sig(a) for a in rows)
out, stat = {}, collections.Counter()
for a in rows:
    code, _ = match.target('2008-06', a)[:2]
    va = int(a, 16)
    ctors = set()
    for i in range(len(code) - 4):
        if code[i] == 0xE8:
            tgt = '%08x' % ((va + i + 5 + struct.unpack_from('<i', code, i + 1)[0]) & 0xffffffff)
            s = sig(tgt)
            hit = re.search(r'__thiscall ((?:\w+::)*\w+)::(\w+)\((?!.*~)', s)
            if hit and hit.group(1).split('::')[-1] == hit.group(2):        # a constructor X::X(...)
                ctors.add(hit.group(1))
    named = re.search(r'create<class (.+)>\(void\)$', sig(a))
    stat['shared' if shared[sig(a)] > 1 else 'unique', len(ctors)] += 1
    if len(ctors) == 1:
        x = ctors.pop()
        if not named or named.group(1) != x:
            out[a] = x
print(stat)
print('resolved to a different class than the registry: %d' % len(out), list(out.items())[:5])
(HERE / 'create-classes.json').write_text(json.dumps(out, indent=1))
