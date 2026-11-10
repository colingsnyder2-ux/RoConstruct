"""Verify zoom-extents with an isolated noalias profile for native Extents::unionWith."""
import hashlib
import json
import struct
import sys
from pathlib import Path
import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts/zoom-extents-preprocess'
out.mkdir(exist_ok=True)
source = root / 'rebuild/2008-06/tests/NativeCameraZoomExtentsAction.cpp'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if x != '/c' and not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/fp:fast', '/P', str(source)], out)
assert code == 0, log
text = (out / 'NativeCameraZoomExtentsAction.i').read_text(errors='replace')
needle = 'void unionWith(const Extents& other);'
assert text.count(needle) == 1
profile = out / 'NativeCameraZoomExtentsProfile.cpp'
profile.write_text(text.replace(needle, '__declspec(noalias) ' + needle))
obj = out / 'NativeCameraZoomExtentsProfile.obj'
compile_flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/fp:fast', '/Fo' + str(obj), str(profile)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', compile_flags, out)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?doIt@CameraZoomExtentsCommand@RBX@@'))
target, targetrefs, _ = match.target('2008-06', '00582f50')
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
            value = (0x582f50 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        bindings.setdefault(symbols[index][0], set()).add(value)
for prefix, address in [('?createService@?$ServiceClient@V?$FilteredSelection@VPVInstance@RBX@@', 0x581d80),
                        ('?unionWith@Extents@RBX@@', 0x57dee0), ('?setCameraType@Camera@RBX@@', 0x5cddd0),
                        ('?zoomExtents@Camera@RBX@@QAEX', 0x5ce0d0), ('?zoomExtents@Camera@RBX@@QAE_N', 0x5ce400),
                        ('?playSound@SoundService@Soundscape@RBX@@', 0x5bd820), ('?recordCameraHistory@RBX@@', 0x58c5c0)]:
    assert any(k.startswith(prefix) and address in values for k, values in bindings.items()), (prefix, bindings)
union_body, _, _ = match.target('2008-06', '0057dee0')
assert not any(i.mnemonic == 'call' for i in Cs(CS_ARCH_X86, CS_MODE_32).disasm(union_body, 0x57dee0))
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
assert struct.unpack('<I', pe.get_data(0x817b84 + 16 - pe.OPTIONAL_HEADER.ImageBase, 4))[0] == 0x582f50
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'scope': 'Inactive exact profile adds a noalias compiler annotation; original declaration, singleton identity, class lifetime and runtime remain unproven.', 'source_sha256': sha(source), 'observer_sha256': sha(Path(__file__)), 'profile_sha256': sha(profile), 'object_sha256': sha(obj), 'address': '00582f50', 'size': len(body), 'exact': True, 'vtable_slot': '0x817b94', 'bindings': {k: [hex(v) for v in sorted(values)] for k, values in bindings.items()}, 'flags': compile_flags}
(root / 'work/2008-06/shared-layouts/camera-zoom-extents-profile.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native zoom-extents noalias profile')
