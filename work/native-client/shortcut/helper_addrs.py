"""Learn exe addresses for symbols the identity closure has no name for, from the kept comdat helpers of the renamed analogs.
For every function in closure/renamed/*.obj: find the exe function it is byte-identical to (same size, fingerprint.Target.same),
then every relocation of that function names an exe address (same arithmetic as rename.convert).  Writes closure/helper_addrs.json
{symbol: addr}.  python helper_addrs.py"""
import glob, json, struct, sys
from pathlib import Path
sys.path.insert(0, '.')
sys.path.insert(0, 'work/native-client')
from roc import match, fingerprint
import rename as rn

C = Path('work/native-client/shortcut/closure')
rows = [json.loads(l) for l in open('work/2008-06/functions.jsonl')]
by_size = {}
for r in rows:
    if r.get('kind', 'code') == 'code':
        by_size.setdefault(r['size'], []).append(r['addr'])
target = fingerprint.Target('2008-06')
base, image = match._image('2008-06')
out = json.load(open(C / 'helper_addrs.json')) if (C / 'helper_addrs.json').exists() else {}
done_funcs = set()
for o in sorted(glob.glob(str(C / 'renamed' / '*.obj'))):
    data = open(o, 'rb').read()
    syms, _ = rn.symtab(data)
    names = {i: (n, sec, cls) for i, n, sec, cls, v in syms}
    for fname, body, relocs in match.coff_functions(data):
        key = (fname, len(body))
        if key in done_funcs:
            continue
        done_funcs.add(key)
        addr = next((a for a in by_size.get(len(body), []) if target.same(a, body, relocs) is not None), None)
        if not addr:
            continue
        try:
            rels = rn.relocations(data, fname)
        except (StopIteration, struct.error, ValueError):
            continue
        for off, typ, idx, fileoff in rels:
            name, sec, cls = names[idx]
            if sec != 0 or name in out:
                continue            # only undefined externals matter
            site = int(addr, 16) + off
            addend = struct.unpack_from('<i', data, fileoff)[0]
            if typ == rn.DIR32:
                va = struct.unpack_from('<I', image, site - base)[0] - addend
            elif typ == rn.REL32:
                va = (site + 4 + struct.unpack_from('<i', image, site - base)[0]) - addend
            else:
                continue
            out[name] = '%08x' % va
json.dump(out, open(C / 'helper_addrs.json', 'w'), indent=0)
print('learned', len(out), 'symbol addresses from helpers')
