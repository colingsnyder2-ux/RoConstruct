"""python odrdiff.py: one-definition-rule breaks between native objects: the same data symbol (function-local static,
COMDAT global) defined by several objects of the link with DIFFERENT sizes means those translation units saw different
class layouts (ContentProvider::singleton's static was 0x88 bytes in TUs that included the 2007 util/ContentProvider.h,
0x19c in the others; the small copy won and the constructor overwrote the next statics). Writes auto/odrdiff.json."""
import json, os, re, sys
from pathlib import Path
H = Path(__file__).parent
src = (H / 'vt_strip.py').read_text()
ns = {'__file__': str(H / 'vt_strip.py')}
exec(src.split('\n\nrsp = ')[0], ns)
data_defs = ns['data_defs']
seen = {}
for l in (H / 'link/donorfree.rsp').read_text().splitlines():
    p = l.strip().strip('"')
    if not p.lower().endswith('.obj') or not os.path.exists(p) or 'renamed' + os.sep + 'obj' in os.path.normpath(p):
        continue
    try:
        for n, z in data_defs(Path(p).read_bytes()).items():
            seen.setdefault(n, {}).setdefault(z, []).append(p)
    except Exception:
        pass
bad = {n: {str(z): [q[-60:] for q in ps[:3]] for z, ps in v.items()} for n, v in seen.items() if len(v) > 1}
(H / 'auto/odrdiff.json').write_text(json.dumps(bad, indent=1))
print('%d data symbols defined with different sizes by different native objects' % len(bad))
for n, v in sorted(bad.items())[:20]:
    print('  %-90s %s' % (n[:90], ' / '.join('%s B' % z for z in v)))
