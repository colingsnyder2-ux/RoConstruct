"""Revalidate Decal/Texture factory wrappers after FaceInstance base recovery."""
import hashlib
import json
import struct
import sys
from pathlib import Path
import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

root = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts/decal-factory-probe'
out.mkdir(exist_ok=True)
source = root / 'rebuild/2008-06/experiments/trials/NativeDocumentInitializeTrial.cpp'
text = source.read_text().replace('#include "Network/Players.h"', '#include "Network/Players.h"\n#include "v8datamodel/Decal.h"')
text += '\nboost::shared_ptr<Decal> InsertDecal::createInstance() { return Creatable<Instance>::create<Decal>(); }\n'
text += 'boost::shared_ptr<Decal> InsertTexture::createInstance() { return Creatable<Instance>::create<Texture>(); }\n'
profile = out / 'NativeDecalFactoryProbe.cpp'
profile.write_text(text)
obj = out / 'NativeDecalFactoryProbe.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags += ['/I' + str(root / 'rebuild/2008-06/tests'), '/Fo' + str(obj), str(profile)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
functions = match.coff_functions(raw)
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
image = pe.OPTIONAL_HEADER.ImageBase
rows = []
for cls, wrapper, vtable, factory, native_size, donor_size, ctor, ctor_vtable in [
        ('Decal', 0x41e650, 0x80f15c, 0x41e4d0, 0x16c, 0x15c, 0x598400, 0x8327b4),
        ('Texture', 0x41e670, 0x817324, 0x41e550, 0x174, 0x164, 0x598870, 0x83296c)]:
    command = 'Insert' + cls
    wrapper_name, body, refs = next(x for x in functions if x[0].startswith('?createInstance@' + command + '@@'))
    target, targetrefs, _ = match.target('2008-06', '%08x' % wrapper)
    assert match.exact_match(target, targetrefs, body, refs)
    assert struct.unpack('<I', pe.get_data(vtable + 20 - image, 4))[0] == wrapper
    factory_name, factory_body, factory_refs = next(x for x in functions if x[0].startswith('??$create@V' + cls + '@RBX@@@?$Creatable@VInstance@RBX@@'))
    factory_target, factory_targetrefs, _ = match.target('2008-06', '%08x' % factory)
    assert match.exact_match(factory_target, factory_targetrefs, factory_body, factory_refs)
    decoder = Cs(CS_ARCH_X86, CS_MODE_32)
    assert any(i.mnemonic == 'push' and i.op_str == hex(native_size) for i in decoder.disasm(factory_body, 0))
    assert any(i.mnemonic == 'push' and i.op_str == hex(native_size) for i in decoder.disasm(factory_target, factory))
    locator = struct.unpack('<I', pe.get_data(ctor_vtable - 4 - image, 4))[0]
    descriptor = struct.unpack('<I', pe.get_data(locator + 12 - image, 4))[0]
    assert pe.get_string_at_rva(descriptor + 8 - image) == ('.?AV' + cls + '@RBX@@').encode()
    ctor_body, _, _ = match.target('2008-06', '%08x' % ctor)
    assert struct.pack('<I', ctor_vtable) in ctor_body
    rows.append({'class': cls, 'wrapper': hex(wrapper), 'wrapper_exact': True, 'factory': hex(factory), 'factory_exact': True, 'previous_donor_allocation': hex(donor_size), 'candidate_allocation': hex(native_size), 'original_allocation': hex(native_size), 'constructor': hex(ctor), 'constructor_vtable': hex(ctor_vtable)})
consumer, _, _ = match.target('2008-06', '0041f040')
calls = {int(i.op_str, 16) for i in Cs(CS_ARCH_X86, CS_MODE_32).disasm(consumer, 0x41f040) if i.mnemonic == 'call' and i.op_str.startswith('0x')}
assert 0x598610 in calls
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'scope': 'Inactive wrappers and allocations match after FaceInstance renderable-base recovery; Decal/Texture constructors, destructors, runtime ownership and all consumers remain unproven.', 'source_sha256': sha(source), 'face_header_sha256': sha(root / 'rebuild/2008-06/native-headers/v8datamodel/FaceInstance.h'), 'profile_sha256': sha(profile), 'observer_sha256': sha(Path(__file__)), 'object_sha256': sha(obj), 'methods': rows, 'consumer': '0041f040', 'decal_set_texture_target': '0x598610', 'flags': flags}
(root / 'work/2008-06/shared-layouts/decal-factory-revalidated.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS Decal/Texture wrappers and corrected factory allocations')
