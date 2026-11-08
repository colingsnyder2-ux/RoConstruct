"""Verify FaceInstance's native renderable base and both lifetime paths."""
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
source = root / 'rebuild/2008-06/native-classes/FaceInstanceLifetime.cpp'
header = root / 'rebuild/2008-06/native-headers/v8datamodel/FaceInstance.h'
obj = out / 'NativeFaceInstanceLifetime.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/Fo' + str(obj), str(source)], out)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
rows = []
for prefix, address, expected in [
        ('??0FaceInstance@RBX@@', 0x5ef530, [('??0Instance@RBX@@', 0x55b7e0), ('??_7FaceInstance@RBX@@6B@', 0x840698)]),
        ('??1FaceInstance@RBX@@', 0x597500, [('??1IRenderable@RBX@@', 0x47d410), ('??1Instance@RBX@@', 0x55a540)]),
        ('?askSetParent@FaceInstance@RBX@@', 0x62e190, [('??_R0?AVPartInstance@RBX@@', 0x92dd50), ('??_R0?AVInstance@RBX@@', 0x92907c), ('___RTDynamicCast', 0x6a17c6)])]:
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
    for key, value in expected:
        assert any(k.startswith(key) and v == value for k, v in bindings.items()), (key, bindings)
    rows.append({'symbol': name, 'address': hex(address), 'size': len(body), 'exact': True, 'bindings': {k: hex(v) for k, v in bindings.items()}})
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
image = pe.OPTIONAL_HEADER.ImageBase
read = lambda address: struct.unpack('<I', pe.get_data(address-image, 4))[0]
locator = read(0x84072c - 4)
descriptor = read(locator + 12)
assert pe.get_string_at_rva(descriptor + 8 - image) == b'.?AVFaceInstance@RBX@@'
hierarchy = read(locator + 16)
bases = read(hierarchy + 12)
types = {}
for i in range(read(hierarchy + 8)):
    item = read(bases + 4*i)
    typename = pe.get_string_at_rva(read(item) + 8 - image).decode()
    types[typename] = struct.unpack('<i', pe.get_data(item + 8 - image, 4))[0]
assert types['.?AVIRenderable@RBX@@'] == 0x130
assert read(0x84072c + 12) == 0x62e190
assert pe.get_string_at_rva(0x92dd50 + 8 - image) == b'.?AVPartInstance@RBX@@'
assert pe.get_string_at_rva(0x840670 - image) == b'FaceInstance'
assert '?sFaceInstance@RBX@@3PADA' in definitions
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'scope': 'Inactive FaceInstance constructor and destructor match; complete virtual methods, Decal/Texture lifetimes and runtime remain unproven.', 'source_sha256': sha(source), 'header_sha256': sha(header), 'observer_sha256': sha(Path(__file__)), 'object_sha256': sha(obj), 'renderable_base_offset': '0x130', 'methods': rows, 'flags': flags}
(root / 'work/2008-06/shared-layouts/face-instance-lifetime.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native FaceInstance constructor, destructor and renderable RTTI')
