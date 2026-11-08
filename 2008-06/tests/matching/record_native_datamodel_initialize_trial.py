"""Profile native DataModel initialization against recovered headers."""
import hashlib
import json
import struct
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
overlay = out / 'workspace-model-vector-include'
source = root / 'rebuild/2008-06/tests/NativeDataModelInitializeTrial.cpp'
obj = out / 'NativeDataModelInitializeTrial.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if x != '/c' and not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags.insert(0, '/I' + str(overlay))
pre = out / 'datamodel-initialize-preprocess'
pre.mkdir(exist_ok=True)
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/P', str(source)], pre)
assert code == 0, log
text = (pre / 'NativeDataModelInitializeTrial.i').read_text(errors='replace')
start = text.index('class RunService : public DescribedCreatable<RunService')
opening = text.index('{', start)
text = text[:opening + 1] + '\nfriend class DataModel;\n' + text[opening + 1:]
profile = out / 'NativeDataModelInitializeProfile.cpp'
profile.write_text(text)
compileflags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/Fo' + str(obj), str(profile)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', compileflags, out)
assert code == 0, log
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?initializeContents@DataModel@RBX@@'))
target, targetrefs, _ = match.target('2008-06', '0057a9f0')
assert match.exact_match(target, targetrefs, body, refs)
sections, symbols, definitions, _ = match._coff_data_index(raw)
start, section = definitions[name]
table = sections[section]
calls = {}
for i in range(table[7]):
    offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
    offset -= start
    if kind == 20 and 0 <= offset < len(body) - 3:
        calls.setdefault(symbols[index][0], set()).add((0x57a9f0 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff)
expected = [('?setParent@Instance@RBX@@', 0x55a8f0), ('??$create@VLocalBackpack@', 0x578930), ('??$create@VStarterPackService@', 0x4b3960), ('??$create@VRunService@', 0x4530f0), ('??$shared_from@VRunService@', 0x618a40), ('??$create@VSoundService@', 0x4531e0), ('?setNullMouseCommand@Workspace@', 0x5a2730), ('?setVerbParent@VerbContainer@', 0x583210), ('?start@RunService@', 0x556520), ('?addListener@?$Notifier@VRunService@', 0x4218a0), ('??$create@VJointsService@', 0x4b3a50), ('??$create@VPhysicsService@', 0x4cd7e0)]
for prefix, address in expected:
    assert any(k.startswith(prefix) and v == {address} for k, v in calls.items()), (prefix, calls)
receipt = {'scope': 'Inactive original initialization matches including null-command setter. Overlay class layout, service identities, ownership and runtime remain unproven.', 'observer_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(), 'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(), 'profile_sha256': hashlib.sha256(profile.read_bytes()).hexdigest(), 'object_sha256': hashlib.sha256(raw).hexdigest(), 'address': '0057a9f0', 'symbol': name, 'size': len(body), 'exact': True, 'calls': {k: [hex(v) for v in sorted(values)] for k, values in calls.items()}, 'flags': compileflags}
(root / 'work/2008-06/shared-layouts/datamodel-initialize-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native DataModel initialization with original null-command binding')
