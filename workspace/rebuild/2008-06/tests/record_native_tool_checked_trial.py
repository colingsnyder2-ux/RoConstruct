"""Profile original tool checked predicate and donor Workspace layout."""
import hashlib
import json
import struct
import sys
from pathlib import Path

import pefile

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/tests/NativeToolCheckedTrial.cpp'
obj = out / 'NativeToolCheckedTrial.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
name, body, refs = next(x for x in match.coff_functions(obj.read_bytes()) if x[0].startswith('?isChecked@?$TToolVerb@VArrowTool@'))
target, target_refs, _ = match.target('2008-06', '005c6240')
assert not match.exact_match(target, target_refs, body, refs)
assert b'\x98\x03\x00\x00' in body and b'\xb0\x03\x00\x00' in target
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
image = pe.OPTIONAL_HEADER.ImageBase
vtables = json.loads((root / 'work/2008-06/shared-layouts/tool-verb-actions-trial.json').read_text())['vtables']
rows = []
for tool, vtable in vtables.items():
    address = struct.unpack('<I', pe.get_data(int(vtable, 16) + 12 - image, 4))[0]
    original, original_refs, _ = match.target('2008-06', '%08x' % address)
    assert len(original) == len(target) == 44
    assert original[:21] == target[:21] and original[25:30] == target[25:30] and original[34:] == target[34:], tool
    assert address + 25 + struct.unpack_from('<i', original, 21)[0] == 0x6a1de2
    descriptor = struct.unpack_from('<I', original, 30)[0]
    actual = pe.get_string_at_rva(descriptor + 8 - image)
    assert actual == ('.?AV' + tool + '@RBX@@').encode(), (tool, actual)
    rows.append({'tool': tool, 'vtable': vtable, 'address': hex(address), 'type_descriptor': hex(descriptor), 'type_name': actual.decode()})
receipt = {'scope': 'Original 26 vtable slots and type descriptors verified; donor predicate differs and is not linked.', 'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(), 'object_sha256': hashlib.sha256(obj.read_bytes()).hexdigest(), 'candidate_size': len(body), 'original_size': len(target), 'donor_workspace_command_offset': '0x398', 'original_workspace_command_offset': '0x3b0', 'methods': rows, 'flags': flags}
(root / 'work/2008-06/shared-layouts/tool-checked-donor-mismatch.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS original 26 checked slots and RTTI names; donor predicate differs')
