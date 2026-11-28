"""python ledger.py: one table of EVERY original function (function-files.json) vs. the server's analog status and what
our donor-free link actually does with it -- the "how many functions are really left" count.
Per function: server status (src/2008-06/<addr>.cpp header: 100% / partial / none), converter result (rename.json),
and our link (qt.map owner of its converted symbol, its registry name, its native_addrs name, or an import thunk).
Writes auto/ledger.json {addr: row}; prints the totals and the actionable buckets. Read-only, seconds."""
import json, os, re
from collections import Counter
from pathlib import Path
import pefile
H = Path(__file__).parent
ROOT = H.parents[1]
ff = json.load(open(ROOT / 'work/native-client/layout/function-files.json'))
ren = json.loads((H / 'renamed/rename.json').read_text())
na = json.loads((H / 'renamed/native_addrs.json').read_text()) if (H / 'renamed/native_addrs.json').exists() else {}
own = {}
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        own.setdefault(p[1], p[-1])
o = pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe'), fast_load=True)
oi = o.get_memory_mapped_image()
# every OTHER source we hold per address: integrated natives (native-classes), inactive findings trees, LLM drafts
# (AutoRecover_<addr>.cpp). An address in a comment or a function name counts (natives cite '// 004492d0' etc.).
srcs = {}
_A = re.compile(r'\b(?:func_|sub_|fn_)?([0-9a-f]{8})\b')
for kind, d in (('native', 'native-classes'), ('findings', 'native-findings'), ('findings', 'native-findings-new'),
                ('findings', 'native-findings-mew')):
    for f in (ROOT / 'rebuild/2008-06' / d).glob('*.cpp'):
        k = 'draft' if f.name.startswith('AutoRecover_') else kind
        for m in set(_A.findall(f.read_text(errors='replace'))):
            if m in ff:
                srcs.setdefault(m, set()).add(k)
real = lambda n: bool(n) and n in own and 'stubs' not in own[n]
stub = lambda n: bool(n) and 'stubs' in own.get(n, '')
SRC = ROOT / 'src/2008-06'
rows, tot = {}, Counter()
for a, v in ff.items():
    va = int(a, 16)
    name = (v or {}).get('name') or ''
    p = SRC / (a + '.cpp')
    server = 'none'
    if p.exists():
        m = re.search(r'(\d+(?:\.\d+)?)%', open(p, errors='replace').readline())
        server = 'exact' if m and float(m.group(1)) >= 100 else 'partial'
    r = ren.get(a) or {}
    conv = r.get('status') or 'not queued'
    sym = r.get('symbol')
    off = va - 0x400000
    if 0 <= off < len(oi) - 2 and oi[off:off + 2] == b'\xff\x25':
        link = 'import thunk (DLL)'
    elif real(sym) or real('func_' + a):
        link = 'converted body linked'
    elif real(na.get(a)) or (real(name) and not stub(name)):
        link = 'native/library body linked'
    elif stub(sym) or stub(name) or stub('func_' + a) or stub(na.get(a)):
        link = 'STUB (placeholder)'
    else:
        link = 'not referenced by our link'
    rows[a] = dict(name=name[:120], server=server, convert=conv, link=link, other=sorted(srcs.get(a, ())))
    tot[(link, server, conv if conv != 'renamed' else 'converted')] += 1
(H / 'auto/ledger.json').write_text(json.dumps(rows, indent=0))
print('original functions: %d' % len(rows))
for k, n in Counter(r['link'] for r in rows.values()).most_common():
    print('  %6d  %s' % (n, k))
print('server status: %s' % dict(Counter(r['server'] for r in rows.values())))
print('ACTIONABLE (placeholder in our link):')
st = Counter((r['server'], r['convert']) for r in rows.values() if r['link'] == 'STUB (placeholder)')
for (s, c), n in st.most_common():
    print('  %6d  server %-7s convert %s' % (n, s, c))
ph = [r for r in rows.values() if r['link'] == 'STUB (placeholder)']
def _have(r):
    if r['server'] == 'exact':
        return 'server-exact analog (converter path)'
    if 'native' in r['other']:
        return 'integrated native source mentions it'
    if 'findings' in r['other']:
        return 'inactive findings source'
    if 'draft' in r['other']:
        return 'LLM draft (AutoRecover)'
    if r['server'] == 'partial':
        return 'partial server analog only'
    return 'NO SOURCE ANYWHERE'
print('placeholders by best source we already hold:')
for k, n in Counter(_have(r) for r in ph).most_common():
    print('  %6d  %s' % (n, k))
(H / 'auto/ledger_nosource.txt').write_text(''.join('%s %s\n' % (a, r['name']) for a, r in rows.items()
                                                   if r['link'] == 'STUB (placeholder)' and _have(r) == 'NO SOURCE ANYWHERE'))
print('server-exact but our converter failed: %s' % dict(Counter(r['convert'] for r in rows.values() if r['server'] == 'exact' and r['convert'] in ('nomatch', 'compile', 'error'))))
