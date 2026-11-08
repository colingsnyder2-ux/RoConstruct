"""Check native ATL workspace factory against original 00450370."""
import hashlib
import json
import struct
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/experiments/trials/NativeWorkspaceFactoryTrial.cpp'
obj = out / 'NativeWorkspaceFactoryTrial.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
pre = out / 'workspace-factory-preprocess'
pre.mkdir(exist_ok=True)
preflags = [x for x in flags if x != '/c'] + ['/P', str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', preflags, pre)
assert code == 0, log
text = (pre / 'NativeWorkspaceFactoryTrial.i').read_text(errors='replace')
profile = out / 'NativeWorkspaceFactoryProfile.cpp'
profile.write_text(text)
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/Fo' + str(obj), str(profile)], out)
if code:
    print(log[-4000:])
    raise SystemExit(code)
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?CreateInstance@?$CComObject@VCWorkspace@@'))
target, targetrefs, _ = match.target('2008-06', '00450370')
assert match.exact_match(target, targetrefs, body, refs)
sections, symbols, definitions, _ = match._coff_data_index(raw)
start, section = definitions[name]
table = sections[section]
calls = {}
for i in range(table[7]):
    offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
    offset -= start
    if kind == 20 and 0 <= offset < len(body) - 3:
        value = (0x450370 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        calls.setdefault(symbols[index][0], set()).add(value)
for prefix, address in [('??0?$CComObject@VCWorkspace@@@ATL@@', 0x401910), ('?FinalConstruct@CWorkspace@@', 0x46b5c0)]:
    assert any(k.startswith(prefix) and v == {address} for k, v in calls.items()), (prefix, calls)
ctor_name, ctor_body, ctor_refs = next(x for x in match.coff_functions(raw) if x[0].startswith('??0?$CComObject@VCWorkspace@@@ATL@@'))
ctor_target, ctor_targetrefs, _ = match.target('2008-06', '00401910')
assert match.exact_match(ctor_target, ctor_targetrefs, ctor_body, ctor_refs)
receipt = {'scope': 'Inactive vendor ATL factory and object constructor match. Interface methods, COM map, FinalConstruct, generated vtables, EH data and runtime remain unproven.', 'observer_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(), 'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(), 'header_sha256': hashlib.sha256((root / 'rebuild/2008-06/native-headers/CWorkspace.h').read_bytes()).hexdigest(), 'profile_sha256': hashlib.sha256(profile.read_bytes()).hexdigest(), 'object_sha256': hashlib.sha256(raw).hexdigest(), 'address': '00450370', 'symbol': name, 'size': len(body), 'relocation_normalized_exact': True, 'constructor': {'address': '00401910', 'symbol': ctor_name, 'size': len(ctor_body), 'relocation_normalized_exact': True}, 'calls': {k: [hex(v) for v in sorted(values)] for k, values in calls.items()}, 'flags': flags}
(root / 'work/2008-06/shared-layouts/workspace-factory-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS ATL Workspace factory 00450370 and constructor 00401910; FinalConstruct target verified')
