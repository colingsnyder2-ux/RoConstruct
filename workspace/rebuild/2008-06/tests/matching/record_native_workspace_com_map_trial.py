"""Compile Workspace's original three-entry ATL COM map in an isolated header."""
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
source = root / 'rebuild/2008-06/experiments/trials/NativeWorkspaceFactoryTrial.cpp'
header = root / 'rebuild/2008-06/native-headers/CWorkspace.h'
overlay = out / 'workspace-com-map-include'
overlay.mkdir(exist_ok=True)
text = header.read_text()
(overlay / 'CWorkspace.h').write_text(text)
obj = out / 'NativeWorkspaceComMapTrial.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags.insert(0, '/I' + str(overlay))
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
functions = match.coff_functions(raw)
sections, symbols, definitions, _ = match._coff_data_index(raw)
rows = []
for prefix, address in [('?QueryInterface@?$CComObject@VCWorkspace@@@ATL@@UAG', '00402730'), ('?CreateInstance@?$CComObject@VCWorkspace@@@ATL@@', '00450370'), ('??0?$CComObject@VCWorkspace@@@ATL@@', '00401910')]:
    name, body, refs = next(x for x in functions if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', address)
    assert match.exact_match(target, targetrefs, body, refs), (name, len(body), len(target))
    if address == '00402730':
        start, section = definitions[name]
        table = sections[section]
        call_targets = {}
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
            offset -= start
            if kind == 20 and 0 <= offset < len(body) - 3:
                call_targets[symbols[index][0]] = (int(address, 16) + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        assert any('InternalQueryInterface' in k and v == 0x402280 for k, v in call_targets.items()), call_targets
    rows.append({'symbol': name, 'address': address, 'size': len(body), 'exact': True})
map_name, (start, section) = next((k, v) for k, v in definitions.items() if k.startswith('?_entries@') and 'CWorkspace' in k)
table = sections[section]
candidate = raw[table[4] + start:table[4] + start + 48]
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
image = pe.OPTIONAL_HEADER.ImageBase
original = pe.get_data(0x80aea8 - image, 48)
relocations = {}
for i in range(table[7]):
    offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
    if start <= offset < start + 48:
        assert kind == 6
        relocations[offset - start] = symbols[index][0]
assert set(relocations) == {0, 12, 24}
guid_rows = []
for offset, symbol in sorted(relocations.items()):
    addr = struct.unpack_from('<I', original, offset)[0]
    guid_offset, guid_section = definitions[symbol]
    value = raw[sections[guid_section][4] + guid_offset:][:16]
    assert value == pe.get_data(addr - image, 16)
    guid_rows.append({'symbol': symbol, 'original_address': hex(addr), 'bytes': value.hex()})
    candidate = candidate[:offset] + original[offset:offset + 4] + candidate[offset + 4:]
assert candidate == original
receipt = {'scope': 'Inactive original COM map data, GUID bytes and three ATL methods match; real interface methods, data ownership and runtime remain unproven.', 'observer_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(), 'header_sha256': hashlib.sha256(header.read_bytes()).hexdigest(), 'overlay_sha256': hashlib.sha256((overlay / 'CWorkspace.h').read_bytes()).hexdigest(), 'object_sha256': hashlib.sha256(raw).hexdigest(), 'methods': rows, 'map': {'symbol': map_name, 'original_address': '0x80aea8', 'size': 48, 'entry_offsets': [0, 0, 4], 'guids': guid_rows}, 'flags': flags}
(root / 'work/2008-06/shared-layouts/workspace-com-map-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS Workspace COM map and factory, constructor, QueryInterface')
