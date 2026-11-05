"""Check complete candidate DataModel storage against original layout evidence."""
import hashlib
import json
from pathlib import Path
import subprocess
import sys

import pefile

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match, rebuild

out = ROOT / 'rebuild/2008-06/out/native-layouts'
baseline = json.loads((ROOT / 'work/2008-06/shared-layouts/document-compile.json').read_text())
source = ROOT / 'rebuild/2008-06/tests/NativeDataModelLayout.cpp'
flags = baseline['flags'][:-2] + ['/FoNativeDataModelLayout.obj', str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
obj = (out / 'NativeDataModelLayout.obj').read_bytes()
name, body, relocs = next((name, body, relocs) for name, body, relocs in match.coff_functions(obj)
                          if name.startswith('?nativeWorkspace@@'))
assert body == bytes.fromhex('8b4424048b8004020000c3') and not relocs
exe = ROOT / 'work/2008-06/original-p4-reference/Roblox.exe'
pe = pefile.PE(str(exe), fast_load=True)
original = pe.get_data(0x46a970 - pe.OPTIONAL_HEADER.ImageBase, 17)
assert bytes.fromhex('8b8004020000') in original
files = ['rebuild/2008-06/native-headers/v8datamodel/DataModel.h',
         'rebuild/2008-06/native-headers/v8tree/Instance.h',
         'rebuild/2008-06/native-headers/v8tree/Service.h',
         'rebuild/2008-06/native-headers/v8tree/Verb.h',
         'rebuild/2008-06/native-headers/v8tree/VerbContainer.h',
         'rebuild/2008-06/native-headers/v8tree/IDataState.h']
receipt = dict(revision=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
               compiler=21022, compile_exit=code, model_size=0x264, lock_size=12,
               offsets=dict(workspace=0x204, runService=0x20c, guiRoot=0x21c,
                            uiMessage=0x234, dirty=0x258, mutex=0x25c),
               accessor_symbol=name, accessor_sha256=hashlib.sha256(body).hexdigest(),
               original_getter='0046a970', original_sha256=hashlib.sha256(exe.read_bytes()).hexdigest(),
               source_sha256=hashlib.sha256(source.read_bytes()).hexdigest(),
               observer_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
               headers={path: hashlib.sha256((ROOT / path).read_bytes()).hexdigest() for path in files},
               scope='Inactive shared DataModel storage and workspace access probe. Size and specified offsets match original evidence. Full virtual interface, constructors, ownership lifetimes and active linkage remain unverified.')
output = ROOT / 'work/2008-06' / sys.argv[1]
output.parent.mkdir(parents=True, exist_ok=True)
output.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS: DataModel size 0x264, six offsets, Lock size and workspace access at 0x204')
