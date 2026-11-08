"""Verify inactive native camera-center action and original targets."""
import hashlib
import json
import struct
import sys
from pathlib import Path
import pefile

root = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/tests/NativeCameraCenterAction.cpp'
obj = out / 'NativeCameraCenterAction.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')] + ['/fp:fast']
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/Fo' + str(obj), str(source)], out)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?doIt@CameraCenterCommand@RBX@@'))
target, targetrefs, _ = match.target('2008-06', '005823f0')
assert match.exact_match(target, targetrefs, body, refs)
start, section = definitions[name]
table = sections[section]
bindings = {}
for i in range(table[7]):
    offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10*i)
    offset -= start
    if 0 <= offset < len(body) - 3:
        value = struct.unpack_from('<I', target, offset)[0]
        if kind == 20:
            value = (0x5823f0 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        bindings.setdefault(symbols[index][0], set()).add(value)
for prefix, address in [('?createService@?$ServiceClient@V?$FilteredSelection@VPVInstance@RBX@@', 0x581d80),
                        ('?unionWith@Extents@RBX@@', 0x57dee0), ('?setCameraType@Camera@RBX@@', 0x5cddd0),
                        ('?setCameraFocus@Camera@RBX@@', 0x5cdf00), ('?playSound@SoundService@Soundscape@RBX@@', 0x5bd820)]:
    assert any(k.startswith(prefix) and address in v for k, v in bindings.items()), (prefix, bindings)
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
assert struct.unpack('<I', pe.get_data(0x817bb0 + 16 - pe.OPTIONAL_HEADER.ImageBase, 4))[0] == 0x5823f0
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'scope': 'Inactive center action matches; selection, camera and sound lifetimes, singleton identity and runtime remain unproven.', 'source_sha256': sha(source), 'command_header_sha256': sha(root / 'rebuild/2008-06/tests/NativeCameraCommands.h'), 'selection_header_sha256': sha(root / 'rebuild/2008-06/native-headers/v8datamodel/Selection.h'), 'observer_sha256': sha(Path(__file__)), 'object_sha256': sha(obj), 'address': '005823f0', 'size': len(body), 'exact': True, 'vtable_slot': '0x817bc0', 'bindings': {k: [hex(v) for v in sorted(values)] for k, values in bindings.items()}, 'flags': flags}
(root / 'work/2008-06/shared-layouts/camera-center-action-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native camera-center action')
