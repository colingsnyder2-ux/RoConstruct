"""Identify donor Workspace camera ABI mismatch against original tilt getter."""
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
source = root / 'rebuild/2008-06/tests/NativeTiltAxisMismatch.cpp'
obj = out / 'NativeTiltAxisMismatch.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?getRotationAxis@TiltSelectionVerb@'))
target, targetrefs, _ = match.target('2008-06', '0057dc60')
assert len(body) == len(target) == 65 and not match.exact_match(target, targetrefs, body, refs)
assert target[:18] == bytes.fromhex('8b490c8b918802000083ec3081c188020000')
assert body[:18] == bytes.fromhex('8b490c8b917002000083ec3081c170020000')
assert target[24:27] == bytes.fromhex('8b4208') and body[24:27] == bytes.fromhex('8b4204')
rows = json.loads((root / 'work/2008-06/shared-layouts/axis-command-constructors-trial.json').read_text())['methods']
vtable = int(next(row['vtable'] for row in rows if row['class'] == 'TiltSelectionVerb'), 16)
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
assert struct.unpack('<I', pe.get_data(vtable + 20 - pe.OPTIONAL_HEADER.ImageBase, 4))[0] == 0x57dc60
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'scope': 'Inactive donor mismatch only; do not link or run. This identifies native Workspace camera base and virtual-slot differences, not the full class layout.', 'source_sha256': sha(source), 'observer_sha256': sha(Path(__file__)), 'object_sha256': sha(obj), 'address': '0057dc60', 'symbol': name, 'original_size': len(target), 'candidate_size': len(body), 'exact': False, 'vtable': hex(vtable), 'original_camera_base_offset': '0x288', 'donor_camera_base_offset': '0x270', 'original_virtual_slot': '0x8', 'donor_virtual_slot': '0x4', 'flags': flags}
(root / 'work/2008-06/shared-layouts/tilt-axis-donor-mismatch.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS confirmed native Workspace camera base and slot mismatch')
