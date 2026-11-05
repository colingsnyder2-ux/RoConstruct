"""Check native workspace event handlers using original event declarations."""
import hashlib
import json
import struct
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/tests/NativeWorkspaceEventsTrial.cpp'
obj = out / 'NativeWorkspaceEventsTrial.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if x != '/c' and not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
pre = out / 'workspace-events-preprocess'
pre.mkdir(exist_ok=True)
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/P', str(source)], pre)
assert code == 0, log
text = (pre / 'NativeWorkspaceEventsTrial.i').read_text(errors='replace')
profile = out / 'NativeWorkspaceEventsProfile.cpp'
profile.write_text(text)
compileflags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/Fo' + str(obj), str(profile)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', compileflags, out)
assert code == 0, log
raw = obj.read_bytes()
functions = match.coff_functions(raw)
sections, symbols, definitions, _ = match._coff_data_index(raw)
rows = []
for token, address in [('VWorkspace@RBX@@VDrawChanged', '0046a990'), ('VSelection@RBX@@VSelectionChanged', '0046ab10')]:
    name, body, refs = next(x for x in functions if x[0].startswith('?onEvent@CWorkspace@@') and token in x[0])
    target, targetrefs, _ = match.target('2008-06', address)
    assert match.exact_match(target, targetrefs, body, refs)
    start, section = definitions[name]
    table = sections[section]
    calls = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        offset -= start
        if kind == 20 and 0 <= offset < len(body) - 3:
            value = (int(address, 16) + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            calls[symbols[index][0]] = value
    assert any(k.startswith('?invalidateRunViews@RunService@RBX@@') and v == 0x555350 for k, v in calls.items()), calls
    if address == '0046ab10':
        assert any(k.startswith('??1SelectionChanged@RBX@@') and v == 0x422c60 for k, v in calls.items()), calls
    rows.append({'symbol': name, 'address': address, 'size': len(body), 'exact': True, 'calls': {k: hex(v) for k, v in calls.items()}})
donor = root / 'rebuild/2008-06/out/RbxgsApp/linked/RunStateOwner.obj'
name, donor_body, donor_refs = next(x for x in match.coff_functions(donor.read_bytes()) if x[0].startswith('?invalidateRunViews@RunService@RBX@@'))
target, refs, _ = match.target('2008-06', '00555350')
receipt = {'scope': 'Inactive handlers and selected call targets match; RunService layout, event lifetime and runtime ABI remain unproven.', 'observer_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(), 'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(), 'profile_sha256': hashlib.sha256(profile.read_bytes()).hexdigest(), 'object_sha256': hashlib.sha256(raw).hexdigest(), 'methods': rows, 'donor_invalidate': {'address': '00555350', 'symbol': name, 'candidate_size': len(donor_body), 'original_size': len(target), 'exact': match.exact_match(target, refs, donor_body, donor_refs)}, 'flags': compileflags}
(root / 'work/2008-06/shared-layouts/workspace-events-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS both Workspace event handlers; donor invalidate:', receipt['donor_invalidate'])
