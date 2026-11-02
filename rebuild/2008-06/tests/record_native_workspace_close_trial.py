"""Verify native Workspace Close against original MFC module-state handling."""
import hashlib
import json
import struct
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/tests/NativeWorkspaceCloseTrial.cpp'
obj = out / 'NativeWorkspaceCloseTrial.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if x != '/c' and not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
pre = out / 'workspace-close-preprocess'
pre.mkdir(exist_ok=True)
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/P', str(source)], pre)
assert code == 0, log
text = (pre / 'NativeWorkspaceCloseTrial.i').read_text(errors='replace')
profile = out / 'NativeWorkspaceCloseProfile.cpp'
profile.write_text(text)
compileflags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHs-c-', '/MD', '/Fo' + str(obj), str(profile)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', compileflags, out)
assert code == 0, log
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?Close@CWorkspace@@'))
target, targetrefs, _ = match.target('2008-06', '0046b500')
assert match.exact_match(target, targetrefs, body, refs)
sections, symbols, definitions, _ = match._coff_data_index(raw)
start, section = definitions[name]
table = sections[section]
calls = {}
for i in range(table[7]):
    offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
    offset -= start
    if kind == 20 and 0 <= offset < len(body) - 3:
        value = (0x46b500 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        calls[symbols[index][0]] = value
assert any(k.startswith('?cleanup@CWorkspace@@') and v == 0x46b0e0 for k, v in calls.items()), calls
donor = out / 'NativeWorkspaceLayout.obj'
donor_name, donor_body, donor_refs = next(x for x in match.coff_functions(donor.read_bytes()) if x[0].startswith('?cleanup@CWorkspace@@'))
donor_target, donor_targetrefs, _ = match.target('2008-06', '0046b0e0')
receipt = {'scope': 'Inactive native Close wrapper matches with exception handling disabled; cleanup body, MFC state linkage and runtime ABI remain unproven.', 'observer_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(), 'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(), 'profile_sha256': hashlib.sha256(profile.read_bytes()).hexdigest(), 'object_sha256': hashlib.sha256(raw).hexdigest(), 'address': '0046b500', 'symbol': name, 'size': len(body), 'exact': True, 'calls': {k: hex(v) for k, v in calls.items()}, 'linked_cleanup': {'symbol': donor_name, 'candidate_size': len(donor_body), 'original_size': len(donor_target), 'exact': match.exact_match(donor_target, donor_targetrefs, donor_body, donor_refs)}, 'flags': compileflags}
(root / 'work/2008-06/shared-layouts/workspace-close-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS Workspace Close; linked cleanup:', receipt['linked_cleanup'])
