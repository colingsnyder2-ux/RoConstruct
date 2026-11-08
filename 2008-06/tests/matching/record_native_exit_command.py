"""Verify inactive ExitCommand body and original vtable/import bindings."""
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
source = root / 'rebuild/2008-06/tests/NativeExitCommand.cpp'
obj = out / 'NativeExitCommand.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp') and x != '/DNOMINMAX']
flags += ['/D_XTP_STATICLINK', '/D_XTPLIB_NOAUTOLINK', '/I' + str(root / 'tools/libs/xtp-11.2.2/Source')]
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?doIt@ExitCommand@@'))
target, targetrefs, _ = match.target('2008-06', '0044f730')
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
            value = (0x44f730 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        bindings[symbols[index][0]] = value
assert bindings['?AfxGetModuleState@@YGPAVAFX_MODULE_STATE@@XZ'] == 0x6a0926
assert bindings['__imp__PostMessageA@16'] == 0x802e0c
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
assert struct.unpack('<I', pe.get_data(0x817304 + 16 - pe.OPTIONAL_HEADER.ImageBase, 4))[0] == 0x44f730
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'scope': 'Inactive body matches; frame and document layout, vtable identity and runtime remain unproven.',
           'source_sha256': sha(source), 'observer_sha256': sha(Path(__file__)), 'object_sha256': sha(obj),
           'header_sha256': sha(root / 'rebuild/2008-06/tests/NativeExitCommand.h'),
           'frame_header_sha256': sha(root / 'rebuild/2008-06/native-headers/CMainFrame.h'),
           'address': '0044f730', 'size': len(body), 'exact': True, 'vtable_slot': '0x817314',
           'bindings': {k: hex(v) for k, v in bindings.items()}, 'flags': flags}
(root / 'work/2008-06/shared-layouts/exit-command-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native ExitCommand body and original targets')
