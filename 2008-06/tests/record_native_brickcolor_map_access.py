"""Verify BrickColor byte access, nearest color and map singleton."""
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root / 'rebuild/2008-06/tests'))
from native_bind import Original, match, verify

base = root / 'rebuild/2008-06'
out = base / 'out/native-brickcolor-map-evidence'
env = dict(os.environ, NATIVE_CHECK_OUT=str(out))
jobs = [('BrickColorMapAccess', ['005b6120=?color4uint8@BrickColor@RBX@@',
                                '005b5d80=?closest@BrickColor@RBX@@SA?AV12@VColor4uint8']),
        ('BrickColorMapSingleton', ['005b5c20=?singleton@BrickMap@BrickColor@RBX@@'])]
def compile_unit(job):
    unit, checks = job
    result = subprocess.run([sys.executable, str(base / 'tests/check_native_class.py'),
                             'native-classes/' + unit + '.cpp'] + checks,
                            cwd=root, env=env, capture_output=True, text=True, check=True)
    assert '%d/%d exact' % (len(checks), len(checks)) in result.stdout, result.stdout
    return unit, result.stdout
with ThreadPoolExecutor(max_workers=2) as pool:
    outputs = dict(pool.map(compile_unit, jobs))
original = Original()
rows = []
maps = {
    'BrickColorMapAccess': ([('?color4uint8@BrickColor@RBX@@', 0x5b6120),
                             ('?closest@BrickColor@RBX@@SA?AV12@VColor4uint8', 0x5b5d80)],
                            [('?singleton@BrickMap@BrickColor@RBX@@', 0x5b5c20),
                             ('?find@?$_Tree@V?$_Tmap_traits@W4Number@BrickColor@RBX@@', 0x5b3990),
                             ('?_Inc@const_iterator@?$_Tree@V?$_Tmap_traits@W4Number@BrickColor@RBX@@', 0x68dfa0)]),
    'BrickColorMapSingleton': ([('?singleton@BrickMap@BrickColor@RBX@@', 0x5b5c20)],
                               [('?$S1@?1??singleton@BrickMap@BrickColor@RBX@@', 0x976f98),
                                ('?map@?1??singleton@BrickMap@BrickColor@RBX@@', 0x976ee8),
                                ('??0BrickMap@BrickColor@RBX@@', 0x5b4630),
                                ('??__Fmap@?1??singleton@BrickMap@BrickColor@RBX@@', 0x7fe2c0),
                                ('_atexit', 0x6a17af)]),
}
objects = {}
for unit, (methods, bindings) in maps.items():
    obj = out / ('Check' + unit + '.obj')
    raw = obj.read_bytes()
    names = [n for n, _, _ in match.coff_functions(raw)]
    _, symbols, _, _ = match._coff_data_index(raw)
    chosen = [(next(n for n in names if n.startswith(prefix)), address) for prefix, address in methods]
    internal = {next(s[0] for s in symbols.values() if s[0].startswith(prefix)): address
                for prefix, address in bindings}
    rows += verify(original, obj, chosen, internal)
    objects[unit] = hashlib.sha256(raw).hexdigest()
paths = [base / 'native-classes/BrickColorMapAccess.cpp', base / 'native-classes/BrickColorMapSingleton.cpp',
         root / 'tools/rbxgs/Client/App/include/v8datamodel/BrickColor.h',
         base / 'tests/native_bind.py', base / 'tests/check_native_class.py', Path(__file__)]
receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
           'sources': {str(p.relative_to(root)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
           'objects': objects, 'methods': rows,
           'scope': 'Inactive exact methods and bindings. BrickMap construction, palette data and runtime remain unverified.'}
path = root / 'work/2008-06/native-brickcolor-map-access.json'
path.write_text(json.dumps(receipt, indent=2) + '\n')
print(''.join(outputs.values()), end='')
print(path)
