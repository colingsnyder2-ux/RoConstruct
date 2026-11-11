"""Verify both original palette-map generation methods and their bindings."""
import hashlib
import json
import os
from pathlib import Path
import struct
import subprocess
import sys

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root / 'rebuild/2008-06/tests'))
from native_bind import Original, match, verify

base = root / 'rebuild/2008-06'
out = base / 'out/native-brickmap-population-evidence'
env = dict(os.environ, NATIVE_CHECK_OUT=str(out))
checks = ['005b42f0=?generatePaletteMap@BrickMap@BrickColor@RBX@@AAEXXZ',
          '005b4130=?generatePaletteMap@BrickMap@BrickColor@RBX@@AAEXW4']
run = subprocess.run([sys.executable, str(base / 'tests/check_native_class.py'),
                      'native-classes/BrickColorMapPopulation.cpp'] + checks,
                     cwd=root, env=env, capture_output=True, text=True, check=True)
assert '2/2 exact' in run.stdout, run.stdout
obj = out / 'CheckBrickColorMapPopulation.obj'
raw = obj.read_bytes()
names = [n for n, _, _ in match.coff_functions(raw)]
methods = [(next(n for n in names if n.startswith(prefix)), address) for address, prefix in
           ((0x5b42f0, '?generatePaletteMap@BrickMap@BrickColor@RBX@@AAEXXZ'),
            (0x5b4130, '?generatePaletteMap@BrickMap@BrickColor@RBX@@AAEXW4'))]
_, symbols, _, _ = match._coff_data_index(raw)
mapping = [('??A?$map@W4Number@BrickColor@RBX@@VColor4@G3D@@', 0x5b3f10),
           ('??A?$map@W4Number@BrickColor@RBX@@H', 0x46d3d0), ('__real@461c4000', 0x82746c)]
internal = {next(s[0] for s in symbols.values() if s[0].startswith(prefix)): address for prefix, address in mapping}
original = Original()
assert original.data(0x82746c, 4) == struct.pack('<f', 10000.0)
rows = verify(original, obj, methods, internal)
paths = [base / 'native-classes/BrickColorMapPopulation.cpp',
         root / 'tools/rbxgs/Client/App/include/v8datamodel/BrickColor.h',
         base / 'tests/native_bind.py', Path(__file__)]
receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
           'sources': {str(p.relative_to(root)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
           'object_sha256': hashlib.sha256(raw).hexdigest(), 'methods': rows,
           'scope': 'Inactive exact palette-map methods and bindings. Insertion and construction remain nonexact; runtime unverified.'}
path = root / 'work/2008-06/native-brickmap-population.json'
path.write_text(json.dumps(receipt, indent=2) + '\n')
print(run.stdout, end='')
print(path)
