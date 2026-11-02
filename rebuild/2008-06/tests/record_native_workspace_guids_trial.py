"""Verify Workspace COM GUID data and original type-info-holder bindings."""
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
source = root / 'rebuild/2008-06/tests/NativeWorkspaceGuidsTrial.cpp'
obj = out / 'NativeWorkspaceGuidsTrial.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
image = pe.OPTIONAL_HEADER.ImageBase
holder = struct.unpack('<III', pe.get_data(0x928754 - image, 12))
assert holder == (0x8164b8, 0x8164e8, 0x20001), holder
rows = []
for prefix, address in [('?IID_IWorkspace@@', holder[0]), ('?LIBID_RobloxLib@@', holder[1])]:
    name, (offset, section) = next((k, v) for k, v in definitions.items() if k.startswith(prefix))
    value = raw[sections[section][4] + offset:][:16]
    assert value == pe.get_data(address - image, 16), name
    rows.append({'symbol': name, 'original_address': hex(address), 'bytes': value.hex()})
receipt = {'scope': 'Inactive GUID data matches original holder inputs; type-info holder identity and COM runtime remain unproven.', 'observer_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(), 'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(), 'object_sha256': hashlib.sha256(raw).hexdigest(), 'original_holder_address': '0x928754', 'holder_words': [hex(x) for x in holder], 'guids': rows, 'flags': flags}
(root / 'work/2008-06/shared-layouts/workspace-guids-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS Workspace IID and typelib GUID; original holder version 1.2')
