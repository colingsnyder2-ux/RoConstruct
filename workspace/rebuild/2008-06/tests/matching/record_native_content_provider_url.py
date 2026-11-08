"""Verify original content URL classifier including data and import targets."""
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
source = root / 'rebuild/2008-06/native-classes/ContentProviderUrl.cpp'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
obj = out / 'NativeContentProviderUrl.obj'
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?isUrl@ContentProvider@RBX@@'))
target, targetrefs, _ = match.target('2008-06', '0055bd10')
assert match.exact_match(target, targetrefs, body, refs)
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
imports = {entry.address: entry.name.decode('ascii') for dll in pe.DIRECTORY_ENTRY_IMPORT
           for entry in dll.imports if entry.name}
data = {offset: value.split(b'\0', 1)[0] for offset, value, _ in match.coff_data_refs(raw, name)}
assert data[0xa] == pe.get_string_at_rva(0x82db1c-pe.OPTIONAL_HEADER.ImageBase) == b'http://'
assert data[0x23] == pe.get_string_at_rva(0x82db10-pe.OPTIONAL_HEADER.ImageBase) == b'https://'
sections, symbols, definitions, _ = match._coff_data_index(raw)
start, index = definitions[name]
section = sections[index]
calls = []
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
    offset -= start
    if 0 <= offset < len(body)-3 and symbols[symbol][0].startswith('__imp_'):
        value = struct.unpack_from('<I', target, offset)[0]
        assert value == 0x802498 and symbols[symbol][0][6:] == imports[value]
        calls.append(imports[value])
assert len(calls) == 2
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256': sha(source), 'observer_sha256': sha(Path(__file__)), 'object_sha256': sha(obj),
           'flags': flags, 'address': '0055bd10', 'size': len(body), 'strings': ['http://', 'https://'],
           'import_address': '0x802498', 'import_symbol': calls[0],
           'scope': 'Inactive diagnostic; ContentProvider class ownership and runtime ABI remain unproven.'}
(root/'work/2008-06/shared-layouts/content-provider-url-working.json').write_text(json.dumps(receipt, indent=2)+'\n')
print('PASS ContentProvider URL classifier and original targets')
