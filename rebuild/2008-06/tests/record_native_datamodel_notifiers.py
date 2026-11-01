"""Verify shared DataModel notifier base adjustments used by native View."""
import hashlib, json, subprocess, sys
from pathlib import Path
ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match, rebuild
out = ROOT / 'rebuild/2008-06/out/native-layouts'
source = ROOT / 'rebuild/2008-06/tests/NativeDataModelNotifierLayout.cpp'
base = json.loads((ROOT / 'work/2008-06/shared-layouts/document-compile.json').read_text(encoding='utf8'))
flags = base['flags'][:-2] + ['/FoNativeDataModelNotifierLayout.obj', str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
obj = (out / 'NativeDataModelNotifierLayout.obj').read_bytes()
rows = []
for prefix, offset in (('?modelAdded@@', 0x150), ('?modelRemoving@@', 0x170)):
    name, body, relocs = next((n,b,r) for n,b,r in match.coff_functions(obj) if n.startswith(prefix))
    assert body == bytes.fromhex('8b44240485c0740605') + offset.to_bytes(4, 'little') + bytes.fromhex('c333c0c3') and not relocs
    rows.append(dict(symbol=name, offset=offset, body=body.hex()))
paths = [source, ROOT / 'rebuild/2008-06/native-headers/v8datamodel/DataModel.h', ROOT / 'rebuild/2008-06/native-headers/v8tree/Service.h', ROOT / 'rebuild/2008-06/native-headers/v8tree/Instance.h', Path(__file__).resolve()]
receipt = dict(revision=subprocess.check_output(['git','rev-parse','HEAD'], cwd=ROOT, text=True).strip(), sources={str(p.relative_to(ROOT)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths}, compiler_build=21022, flags=flags, typed_casts=rows, scope='Shared candidate base adjustments only; original View listener usage and ServiceProvider RTTI are separate evidence. Runtime linkage unverified.')
(ROOT / 'work/2008-06/shared-layouts/datamodel-notifier-working-probe.json').write_text(json.dumps(receipt, indent=2)+'\n', encoding='utf8')
print('PASS: DataModel ServiceAdded +0x150 and ServiceRemoving +0x170')
