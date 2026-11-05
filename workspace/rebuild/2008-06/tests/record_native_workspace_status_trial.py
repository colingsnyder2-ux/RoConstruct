"""Compile the original status logger against the recovered StandardOut API."""
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
source = root / 'rebuild/2008-06/tests/NativeWorkspaceStatusTrial.cpp'
obj = out / 'NativeWorkspaceStatusTrial.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?reportWorkspaceStatus@@'))
target, target_refs, _ = match.target('2008-06', '00427c20')
assert match.exact_match(target, target_refs, body, refs)
sections, symbols, definitions, _ = match._coff_data_index(raw)
start, section = definitions[name]
table = sections[section]
bindings = {}
for i in range(table[7]):
    offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
    offset -= start
    if 0 <= offset < len(body) - 3:
        value = struct.unpack_from('<I', target, offset)[0]
        if kind == 20:
            value = (0x427c20 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        bindings.setdefault(symbols[index][0], set()).add(value)
for prefix, address in [('?singleton@StandardOut@RBX@@', 0x569620), ('?print@StandardOut@RBX@@', 0x5693a0), ('??1?$shared_ptr@VStandardOut@RBX@@', 0x600660), ('??_C@_02', 0x8103ac)]:
    assert any(k.startswith(prefix) and v == {address} for k, v in bindings.items()), (prefix, bindings)
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
assert pe.get_string_at_rva(0x8103ac - pe.OPTIONAL_HEADER.ImageBase) == b'%s'
donor = root / 'rebuild/2008-06/out/RbxgsApp/linked/standardout.obj'
donor_rows = []
for prefix, address in [('?singleton@StandardOut@RBX@@', '00569620'), ('?print@StandardOut@RBX@@', '005693a0')]:
    donor_name, donor_body, donor_refs = next(x for x in match.coff_functions(donor.read_bytes()) if x[0].startswith(prefix))
    original, original_refs, _ = match.target('2008-06', address)
    donor_rows.append({'symbol': donor_name, 'address': address, 'candidate_size': len(donor_body), 'original_size': len(original), 'exact': match.exact_match(original, original_refs, donor_body, donor_refs)})
receipt = {'scope': 'Inactive status logger matches; selected StandardOut implementations and runtime ABI remain unproven.', 'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(), 'object_sha256': hashlib.sha256(raw).hexdigest(), 'address': '00427c20', 'size': len(body), 'relocation_normalized_exact': True, 'bindings': {k: [hex(v) for v in sorted(values)] for k, values in bindings.items()}, 'donor_standardout': donor_rows, 'flags': flags}
(root / 'work/2008-06/shared-layouts/workspace-status-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS 00427c20 and selected targets; donor StandardOut:', donor_rows)
