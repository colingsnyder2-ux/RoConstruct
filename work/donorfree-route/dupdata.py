"""python dupdata.py: data symbols DEFINED by two or more linked converted objects. /FORCE:MULTIPLE keeps the first copy
silently, so unrelated functions end up sharing one variable (Context::ptr's thread_specific_ptr and a mutex getter shared
?c@?3??axes@Shape@G3D + its guard). Seconds; writes auto/dupdata.json {name: [addr, ...]}."""
import json, re, sys
from pathlib import Path
H = Path(__file__).parent
sys.path.insert(0, str(H))
import importlib.util
spec = importlib.util.spec_from_file_location('vts', H / 'vt_strip.py')
src = (H / 'vt_strip.py').read_text()
ns = {'__file__': str(H / 'vt_strip.py')}
exec(src.split('\n\nrsp = ')[0], ns)   # vt_slots / data_defs only (no stripping)
data_defs = ns['data_defs']
seen = {}
for r in json.load(open(H / 'renamed/results.json')):
    o = Path(r['object'])
    a = re.search(r'([0-9a-f]{8})\.obj$', o.name).group(1)
    try:
        for n in data_defs(o.read_bytes()):
            if not n.startswith(('dat_', 'roc_', '__')):
                seen.setdefault(n, []).append(a)
    except OSError:
        pass
dup = {n: v for n, v in seen.items() if len(v) > 1}
(H / 'auto/dupdata.json').write_text(json.dumps(dup, indent=1))
print('%d data symbols defined by 2+ converted objects' % len(dup))
for n, v in sorted(dup.items(), key=lambda x: -len(x[1]))[:15]:
    print('  %3d  %s' % (len(v), n[:110]))
