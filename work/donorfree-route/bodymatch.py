"""python bodymatch.py [EXE MAP]: masked-body hashes of every original function (cached auto/orig_hash.json) and of our
exe. Our named functions whose body equals a DIFFERENT original address = mislabels; original bodies absent from our exe =
missing/never exact. Output auto/bodymatch.json."""
import hashlib, json, re, sys
from collections import defaultdict
from pathlib import Path
import capstone, pefile
H = Path(__file__).parent
ROOT = H.parents[1]
exe = sys.argv[1] if len(sys.argv) > 2 else str(H / 'link/donorfree.exe')
mp = sys.argv[2] if len(sys.argv) > 2 else str(H / 'link/donorfree.map')
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
MASK = re.compile(r'0x[0-9a-f]{5,8}')
def h(img, a, end):
    out = [i.mnemonic + ' ' + MASK.sub('X', i.op_str) for i in md.disasm(img[a - 0x400000:min(end, a + 0x2000) - 0x400000], a)]
    return hashlib.md5('\n'.join(out).encode()).hexdigest()[:16] if len(out) > 3 else None
ff = json.load(open(ROOT / 'work/native-client/layout/function-files.json'))
cf = H / 'auto/orig_hash.json'
if cf.exists():
    oh = json.load(open(cf))
else:
    bo = bytes(pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe')).get_memory_mapped_image())
    st = sorted(int(a, 16) for a in ff)
    oh = {}
    for k, a in enumerate(st):
        x = h(bo, a, st[k + 1] if k + 1 < len(st) else a + 0x100)
        if x:
            oh['%08x' % a] = x
    cf.write_text(json.dumps(oh))
byh = defaultdict(list)
for a, x in oh.items():
    byh[x].append(a)
bn = bytes(pefile.PE(exe).get_memory_mapped_image())
ours = []
for l in open(mp, errors='replace'):
    m = re.match(r'\s*0001:[0-9a-f]{8}\s+(\S+)\s+([0-9a-f]{8})\s+(?:f\s+)?(?:i\s+)?(\S+)', l)
    if m and m.group(3) != 'stubs.obj':
        ours.append((int(m.group(2), 16), m.group(1)))
ours.sort()
name2orig = {}
for a, v in ff.items():
    if (v or {}).get('name'):
        name2orig.setdefault(v['name'], a)
seen, mis, ok, pairs = set(), {}, 0, {}
for k, (a, n) in enumerate(ours):
    end = next((b for b, _ in ours[k + 1:k + 4] if b > a), a + 0x100)
    x = h(bn, a, end)
    if not x:
        continue
    seen.add(x)
    m = re.search(r'f(?:n|unc)_([0-9a-f]{8})', n)
    want = m.group(1) if m else name2orig.get(n)
    if not want:
        continue
    if oh.get(want) == x:
        ok += 1
        pairs[want] = '%08x' % a
    elif byh.get(x) and want not in byh[x]:
        mis[n] = {'labelled': want, 'body_is': byh[x][:4]}
miss = [a for a, x in oh.items() if x not in seen]
(H / 'auto/bodymatch.json').write_text(json.dumps({'mislabel': mis, 'missing': miss, 'pairs': pairs}, indent=0))
print('identical %d | body equals a DIFFERENT original address %d | original bodies absent from our exe %d of %d' % (ok, len(mis), len(miss), len(oh)))
