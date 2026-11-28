"""python cnames.py: C-spelled undefined names (_name) that NO linked object ever calls (only DIR32 references, never
REL32) are variables: a code stub for them (`mov eax,0; ret` in .text) faulted when call_once wrote the flag
_flagInitScriptCpp (Insert Object). Scans the relocations of every object in linkexp/qt.rsp (per-object cache by
mtime/size in linkexp/cnames_cache.pkl) for the C names our last link stubbed. Writes auto/cdata.json (grow-only);
quicktest stubs them as data."""
import json, os, pickle, re, struct
from pathlib import Path
H = Path(__file__).parent
stubs = set()
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and 'stubs' in p[-1] and re.fullmatch(r'_[A-Za-z]\w*', p[1]):
        stubs.add(p[1])
cf = H / 'linkexp/cnames_cache.pkl'
try:
    cache = pickle.load(open(cf, 'rb'))
except Exception:
    cache = {}


def refs(path):
    d = open(path, 'rb').read()
    _, nsec, _, sp, ns, opt, _ = struct.unpack_from('<HHIIIHH', d, 0)
    st = sp + ns * 18
    names, i = {}, 0
    while i < ns:
        raw, val, sec, typ, cls, naux = struct.unpack_from('<8sIHHBB', d, sp + 18 * i)
        if sec == 0 and cls == 2:
            if raw[:4] == b'\0\0\0\0':
                o = st + struct.unpack_from('<I', raw, 4)[0]; n = d[o:d.index(b'\0', o)].decode('latin-1')
            else:
                n = raw.rstrip(b'\0').decode('latin-1')
            if re.fullmatch(r'_[A-Za-z]\w*', n):
                names[i] = n
        i += 1 + naux
    call, data = set(), set()
    for k in range(nsec):
        sh = 20 + opt + 40 * k
        relptr, nrel = struct.unpack_from('<I', d, sh + 24)[0], struct.unpack_from('<H', d, sh + 32)[0]
        for r in range(nrel):
            _, idx, ty = struct.unpack_from('<IIH', d, relptr + 10 * r)
            if idx in names:
                (call if ty == 0x14 else data).add(names[idx])
    return call, data


calls, datas = set(), set()
dirty = False
for l in open(H / 'linkexp/qt.rsp', errors='replace'):
    p = l.strip().strip('"')
    if not p.lower().endswith('.obj') or not os.path.exists(p):
        continue
    stt = os.stat(p); key = (stt.st_mtime_ns, stt.st_size)
    v = cache.get(p)
    if not v or v[0] != key:
        try:
            v = cache[p] = (key,) + refs(p); dirty = True
        except Exception:
            continue
    calls |= v[1]; datas |= v[2]
if dirty:
    pickle.dump(cache, open(cf, 'wb'), protocol=4)
out = H / 'auto/cdata.json'
prev = set(json.loads(out.read_text())) if out.exists() else set()
new = {n for n in stubs if n not in calls}   # DIR32-only, or no longer referenced at all (a sticky name from an older link)
out.write_text(json.dumps(sorted(prev | new)))
print('cnames: C-spelled stubs %d, only ever used as data: %d (e.g. %s)' % (len(stubs), len(new), sorted(new)[:4]))
