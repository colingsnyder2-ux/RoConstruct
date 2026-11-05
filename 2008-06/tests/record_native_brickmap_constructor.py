"""Verify the recovered constructor, call bindings, and palette inputs."""
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import sys
import pefile

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root / 'rebuild/2008-06/tests'))
from native_bind import Original, match, verify
base = root / 'rebuild/2008-06'
source = base / 'native-classes/BrickColorMapPopulation.cpp'
text = source.read_text()
colors = [(int(n), int(r), int(g), int(b), name) for n, r, g, b, name in re.findall(
    r'insert\(lego_(\d+),\s*(\d+),\s*(\d+),\s*(\d+),\s*"([^"]+)"\)', text)]
palette = [int(n) for n in re.findall(r'insertPaletteItem\(lego_(\d+)\)', text)]
assert len(colors) == 112 and len(palette) == 32
asm = subprocess.run([str(root / 'roc.cmd'), 'native-asm', '2008-06', '005b4630',
                      '--only', 'push,call,mov,xor'], cwd=root, capture_output=True,
                     text=True, check=True).stdout.splitlines()
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'), fast_load=True)
image_base = pe.OPTIONAL_HEADER.ImageBase
pushes = []
found = []
found_palette = []
zero_ebp = False
label = None
palette_value = None
for line in asm:
    if re.search(r'\bxor ebp, ebp\b', line):
        zero_ebp = True
    elif re.search(r'\bmov ebp,', line):
        zero_ebp = False
    store = re.search(r'\bmov dword ptr \[esp \+ 0x(?:14|18)\], (0x[0-9a-f]+|\d+)\b', line)
    if store:
        palette_value = int(store[1], 0)
    pushed = re.search(r'\bpush (0x[0-9a-f]+|\d+|ebp)\b', line)
    if pushed:
        token = pushed[1]
        pushes.append(0 if token == 'ebp' and zero_ebp else int(token, 0) if token != 'ebp' else None)
        continue
    if 'call dword ptr [0x802458]' in line:
        assert pushes and pushes[-1] is not None
        label = pe.get_string_at_rva(pushes[-1] - image_base).decode('ascii')
        pushes = []
    elif 'call 0x5b4410' in line:
        assert len(pushes) >= 4 and None not in pushes[-4:]
        found.append((*reversed(pushes[-4:]), label))
        pushes = []
    elif 'call 0x446f20' in line:
        assert palette_value is not None
        found_palette.append(palette_value)
        palette_value = None
        pushes = []
    elif ' call ' in line:
        pushes = []
assert found == colors, [(i, a, b) for i, (a, b) in enumerate(zip(found, colors)) if a != b]
assert found_palette == palette, [(i, a, b) for i, (a, b) in enumerate(zip(found_palette, palette)) if a != b]
out = base / 'out/native-brickmap-constructor-evidence'
env = dict(os.environ, NATIVE_CHECK_OUT=str(out))
run = subprocess.run([sys.executable, str(base / 'tests/check_native_class.py'),
                      'native-classes/BrickColorMapPopulation.cpp', '005b4630=??0BrickMap@BrickColor@RBX@@'],
                     cwd=root, env=env, capture_output=True, text=True, check=True)
assert '1/1 exact' in run.stdout, run.stdout
obj = out / 'CheckBrickColorMapPopulation.obj'
raw = obj.read_bytes()
names = [n for n, _, _ in match.coff_functions(raw)]
name = next(n for n in names if n.startswith('??0BrickMap@BrickColor@RBX@@'))
_, symbols, _, _ = match._coff_data_index(raw)
mapping = [
    ('??0?$_Tree@V?$_Tmap_traits@W4Number@BrickColor@RBX@@VColor4uint8@G3D@@', 0x446110),
    ('??0?$_Tree@V?$_Tmap_traits@W4Number@BrickColor@RBX@@VColor4@G3D@@', 0x4f0fc0),
    ('??0?$_Tree@V?$_Tmap_traits@W4Number@BrickColor@RBX@@V?$basic_string', 0x699b30),
    ('??0?$_Tree@V?$_Tmap_traits@W4Number@BrickColor@RBX@@H', 0x446110),
    ('?insert@BrickMap@BrickColor@RBX@@', 0x5b4410),
    ('?push_back@?$vector@VBrickColor@RBX@@', 0x446f20),
    ('?generatePaletteMap@BrickMap@BrickColor@RBX@@AAEXXZ', 0x5b42f0),
]
internal = {next(s[0] for s in symbols.values() if s[0].startswith(prefix)): address for prefix, address in mapping}
rows = verify(Original(), obj, [(name, 0x5b4630)], internal)
paths = [source, root / 'tools/rbxgs/Client/App/include/v8datamodel/BrickColor.h', base / 'tests/native_bind.py', Path(__file__)]
receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
           'sources': {str(p.relative_to(root)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
           'original_sha256': hashlib.sha256((root / 'work/2008-06/original-p4-reference/Roblox.exe').read_bytes()).hexdigest(),
           'object_sha256': hashlib.sha256(raw).hexdigest(), 'colors': len(colors), 'palette': len(palette),
           'data_match': True, 'body_check': run.stdout, 'methods': rows,
           'scope': 'Inactive exact constructor, palette literals and bindings. Insertion provider and runtime unverified.'}
path = root / 'work/2008-06/native-brickmap-constructor.json'
path.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS: exact constructor, bindings, 112 colors and 32 palette entries')
