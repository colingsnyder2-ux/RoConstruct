"""Verify native camera pan/tilt units and original constant bindings."""
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
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')] + ['/fp:fast']
source = root / 'rebuild/2008-06/native-classes/CameraUnits.cpp'
constant_source = root / 'rebuild/2008-06/native-classes/CameraConstants.cpp'
obj = out / 'NativeCameraUnits.obj'
constant_obj = out / 'NativeCameraConstants.obj'
for path, output in [(source, obj), (constant_source, constant_obj)]:
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/Fo' + str(output), str(path)], out)
    assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
rows = []
for prefix, address, expected in [
        ('?panUnits@Camera@RBX@@', 0x5cc930, [('?panRadians@Camera@RBX@@', 0x5cc810), ('__real@3fa2f983', 0x83a3f0), ('__real@3f490fdb', 0x8271b0)]),
        ('?tiltUnits@Camera@RBX@@', 0x5cc890, [('?tiltRadians@Camera@RBX@@', 0x5cc740), ('?getElevation@Math@RBX@@', 0x5de190), ('?cameraRadiansToDegrees@RBX@@', 0x83a310), ('__real@3dcccccd', 0x81e704), ('__real@3e32b8c3', 0x83a3ec)])]:
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', '%08x' % address)
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
                value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            bindings[symbols[index][0]] = value
    for key, value in expected + [('?getColumn@Matrix3@G3D@@', 0x513240), ('?zLookDirection@CoordinateFrame@G3D@@', 0x828b60)]:
        assert any(k.startswith(key) and v == value for k, v in bindings.items()), (key, bindings)
    rows.append({'address': hex(address), 'symbol': name, 'size': len(body), 'exact': True, 'bindings': {k: hex(v) for k, v in bindings.items()}})
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
constant_raw = constant_obj.read_bytes()
constant_sections, _, constant_definitions, _ = match._coff_data_index(constant_raw)
start, section = constant_definitions['?cameraRadiansToDegrees@RBX@@3MB']
assert constant_raw[constant_sections[section][4] + start:][:4] == pe.get_data(0x83a310 - pe.OPTIONAL_HEADER.ImageBase, 4)
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'scope': 'Inactive camera units match. Camera lifetime/layout, constant identity and dependent implementations remain unproven.', 'source_sha256': sha(source), 'constant_source_sha256': sha(constant_source), 'observer_sha256': sha(Path(__file__)), 'object_sha256': sha(obj), 'constant_object_sha256': sha(constant_obj), 'methods': rows, 'flags': flags}
(root / 'work/2008-06/shared-layouts/camera-units-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native camera pan/tilt units and constants')
