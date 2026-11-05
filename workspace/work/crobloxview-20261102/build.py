"""Compile CRobloxView native TU and report which CRobloxView-unit addresses it owns exactly."""
import json, sys
from pathlib import Path
root = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(root))
from roc import match, rebuild
out = root / 'rebuild/2008-06/out/native-layouts'
src = Path(sys.argv[1] if len(sys.argv) > 1 else 'rebuild/2008-06/tests/NativeViewTrial.cpp').resolve()
obj = out / (src.stem + '.cvtrial.obj')
base = json.loads((root / "work/2008-06/shared-layouts/view-init.json").read_text())
flags = [x.replace('roc-p6', 'RoConstruct') for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('.cpp')]
flags.insert(0, '/I' + str(out / 'workspace-model-vector-include')); flags += __import__('os').environ.get('XF','').split()
code, log = rebuild.run(rebuild.toolchain(int(__import__("os").environ.get("CLB","21022"))), 'cl', flags + ['/Fo' + str(obj), str(src)], out)
print(log[-3000:] if code else 'compiled')
if code: sys.exit(1)
fn = {r['addr'] for r in json.load(open(root / 'rebuild/2008-06/manifests/functions.json')) if r.get('unit') == 'CRobloxView'}
for sym, size, addrs in rebuild.pair_object('2008-06', obj.read_bytes()):
    print('%-70s %5d %s' % (sym[:70], size, [a for a in addrs if a in fn] or addrs[:3]))
