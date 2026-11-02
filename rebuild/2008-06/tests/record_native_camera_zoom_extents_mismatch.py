"""Record the native-typed zoom-extents candidate without promoting it."""
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

out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/tests/NativeCameraZoomExtentsAction.cpp'
obj = out / 'NativeCameraZoomExtentsAction.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')] + ['/fp:fast']
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/Fo' + str(obj), str(source)], out)
assert code == 0, log
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?doIt@CameraZoomExtentsCommand@RBX@@'))
target, targetrefs, _ = match.target('2008-06', '00582f50')
assert len(body) == len(target) == 691 and not match.exact_match(target, targetrefs, body, refs)
decoder = Cs(CS_ARCH_X86, CS_MODE_32)
candidate = [(hex(i.address), i.mnemonic, i.op_str) for i in decoder.disasm(body, 0) if 0xf0 <= i.address < 0x103]
original = [(hex(i.address), i.mnemonic, i.op_str) for i in decoder.disasm(target, 0) if 0xf0 <= i.address < 0x103]
assert ('0xf3', 'fstp', 'dword ptr [esp + 0x34]') in candidate
assert ('0xff', 'fstp', 'dword ptr [esp + 0x34]') in original
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
assert struct.unpack('<I', pe.get_data(0x817b84 + 16 - pe.OPTIONAL_HEADER.ImageBase, 4))[0] == 0x582f50
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'scope': 'Inactive mismatch. Candidate excluded; camera and selection ABI, ownership and runtime remain unproven.', 'source_sha256': sha(source), 'selection_header_sha256': sha(root / 'rebuild/2008-06/native-headers/v8datamodel/Selection.h'), 'observer_sha256': sha(Path(__file__)), 'object_sha256': sha(obj), 'address': '00582f50', 'candidate_size': len(body), 'original_size': len(target), 'exact': False, 'vtable_slot': '0x817b94', 'candidate_instructions': candidate, 'original_instructions': original, 'flags': flags}
(root / 'work/2008-06/shared-layouts/camera-zoom-extents-mismatch.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS zoom-extents mismatch recorded; candidate excluded')
