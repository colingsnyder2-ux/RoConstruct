"""Verify inactive Render::SpecData construction and recovered helper bytes."""
import hashlib
import json
import os
import subprocess
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root / 'rebuild/2008-06/tests'))
from native_bind import Original, match, verify

base = root / 'rebuild/2008-06'
out = base / 'out/native-render-specdata-evidence'
checks = [('00501ae0', '??0SpecData@Render@RBX@@'), ('005011d0', '?getShaderModel@Render@RBX@@'),
          ('005016f0', '?getCPUSpeed@Render@RBX@@'), ('00501590', '?getCPUMake@Render@RBX@@'),
          ('005019f0', '?getMaxRes@Render@RBX@@'), ('00501400', '?GetCyclesDifference@Render@RBX@@'),
          ('005014b0', '?Delay@Render@RBX@@'), ('00501520', '?DelayOverhead@Render@RBX@@'),
          ('00501650', '?getCPUCount@Render@RBX@@')]
run = subprocess.run([sys.executable, str(base / 'tests/check_native_class.py'),
                      'native-classes/RenderSpecData.cpp'] + [a + '=' + p for a, p in checks],
                     cwd=root, env=dict(os.environ, NATIVE_CHECK_OUT=str(out)),
                     capture_output=True, text=True, check=True)
assert '9/9 exact' in run.stdout, run.stdout
obj = out / 'CheckRenderSpecData.obj'
raw = obj.read_bytes()
names = [n for n, _, _ in match.coff_functions(raw)]
ctor = next(n for n in names if n.startswith('??0SpecData@Render@RBX@@'))
_, symbols, _, _ = match._coff_data_index(raw)
mapping = [('?glLoaded@SpecData@Render@RBX@@', 0x972888),
           ('?getShaderModel@Render@RBX@@', 0x5011d0), ('?videoMemorySize@DXCaps@G3D@@', 0x476470),
           ('?getCPUSpeed@Render@RBX@@', 0x5016f0), ('?getCPUCount@Render@RBX@@', 0x501650),
           ('?vendor@GLCaps@G3D@@', 0x470880), ('?renderer@GLCaps@G3D@@', 0x4709a0),
           ('?getCPUMake@Render@RBX@@', 0x501590), ('?getMaxRes@Render@RBX@@', 0x5019f0),
           ('?format@G3D@@', 0x509b10), ('?keyExists@RegistryUtil@G3D@@', 0x513f50)]
internal = {next(s[0] for s in symbols.values() if s[0].startswith(prefix)): address for prefix, address in mapping}
cpu_count = next(n for n in names if n.startswith('?getCPUCount@Render@RBX@@'))
rows = verify(Original(), obj, [(ctor, 0x501ae0), (cpu_count, 0x501650)], internal)
paths = [base / 'native-classes/RenderSpecData.cpp', base / 'native-headers/RenderLib/Profiler.h',
         base / 'tests/native_bind.py', Path(__file__)]
receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
           'sources': {str(p.relative_to(root)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
           'object_sha256': hashlib.sha256(raw).hexdigest(), 'checks': run.stdout, 'constructor_bindings': rows,
           'scope': 'Inactive exact constructor and eight helper byte checks; constructor and CPU-count targets verified. Other helper targets, provider selection and runtime unverified.'}
(root / 'work/2008-06/native-render-specdata.json').write_text(json.dumps(receipt, indent=2) + '\n')
print(run.stdout, end='')
