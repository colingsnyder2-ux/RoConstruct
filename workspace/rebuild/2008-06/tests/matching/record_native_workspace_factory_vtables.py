"""Compare generated ATL workspace vtable targets to the original executable."""
import hashlib
import json
import struct
import sys
from pathlib import Path

import pefile

root = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(root))
from roc import match

obj = root / 'rebuild/2008-06/out/native-layouts/NativeWorkspaceFactoryTrial.obj'
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
functions = {name: (body, refs) for name, body, refs in match.coff_functions(raw)}
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
image = pe.OPTIONAL_HEADER.ImageBase
tables = [('Listener@VWorkspace@RBX@@', 0x80ae0c), ('Listener@VSelection@RBX@@', 0x80ae18), ('IObjectWithSiteImpl@', 0x80ae24), ('IObjectSafetyRobloxImpl@', 0x80ae40), ('ISupportErrorInfoImpl@', 0x80ae58), ('IDispatchImpl@', 0x80ae6c)]
rows = []
for token, address in tables:
    name, (start, section) = next((k, v) for k, v in definitions.items() if k.startswith('??_7') and 'CWorkspace' in k and token in k)
    table = sections[section]
    relocations = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if offset >= start:
            assert kind == 6
            relocations[offset - start] = symbols[index][0]
    assert set(relocations) == set(range(0, table[3] - start, 4))
    slots = []
    for offset, symbol in sorted(relocations.items()):
        original = struct.unpack('<I', pe.get_data(address + offset - image, 4))[0]
        exact = None
        if symbol in functions:
            try:
                target, refs, _ = match.target('2008-06', '%08x' % original)
                candidate, candidate_refs = functions[symbol]
                exact = match.exact_match(target, refs, candidate, candidate_refs)
            except (KeyError, ValueError):
                pass
        slots.append({'offset': hex(offset), 'symbol': symbol, 'original_target': hex(original), 'local_body_matches': exact})
    rows.append({'symbol': name, 'original_address': hex(address), 'slots': slots})
receipt = {'scope': 'Inactive emitted vtable slot inventory. Target addresses recorded; matches do not verify data identity or runtime ABI.', 'observer_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(), 'object_sha256': hashlib.sha256(raw).hexdigest(), 'tables': rows}
(root / 'work/2008-06/shared-layouts/workspace-factory-vtables-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('tables:', len(rows), 'slots:', sum(len(row['slots']) for row in rows), 'matching local bodies:', sum(slot['local_body_matches'] is True for row in rows for slot in row['slots']), 'different local bodies:', sum(slot['local_body_matches'] is False for row in rows for slot in row['slots']))
