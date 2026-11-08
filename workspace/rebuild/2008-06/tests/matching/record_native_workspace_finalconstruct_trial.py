"""Profile Workspace FinalConstruct with typed native declarations."""
import hashlib
import json
import struct
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/experiments/trials/NativeWorkspaceFinalConstructTrial.cpp'
obj = out / 'NativeWorkspaceFinalConstructTrial.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if x != '/c' and not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
vector_trial = '--model-vector-trial' in sys.argv
if vector_trial:
    model_header = root / 'rebuild/2008-06/native-headers/v8datamodel/ModelInstance.h'
    model = model_header.read_text()
    assert model.count('std::vector<IModelModifier*> modifiers;') == 1
    overlay = out / 'workspace-model-vector-include' / 'v8datamodel'
    overlay.mkdir(parents=True, exist_ok=True)
    (overlay / 'ModelInstance.h').write_text(model)
    flags.insert(0, '/I' + str(overlay.parent))
pre = out / 'workspace-finalconstruct-preprocess'
pre.mkdir(exist_ok=True)
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/P', str(source)], pre)
assert code == 0, log
text = (pre / 'NativeWorkspaceFinalConstructTrial.i').read_text(errors='replace')
profile = out / ('NativeWorkspaceFinalConstructVectorProfile.cpp' if vector_trial else 'NativeWorkspaceFinalConstructProfile.cpp')
profile.write_text(text)
if vector_trial:
    obj = out / 'NativeWorkspaceFinalConstructVectorTrial.obj'
compileflags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/Fo' + str(obj), str(profile)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', compileflags, out)
assert code == 0, log
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?FinalConstruct@CWorkspace@@'))
target, targetrefs, _ = match.target('2008-06', '0046b5c0')
exact = match.exact_match(target, targetrefs, body, refs)
donor_offset, native_offset = struct.pack('<I', 0x32c), struct.pack('<I', 0x344)
if vector_trial:
    assert exact
else:
    assert not exact and body.count(donor_offset) == 1 and match.exact_match(target, targetrefs, body.replace(donor_offset, native_offset), refs)
sections, symbols, definitions, _ = match._coff_data_index(raw)
start, section = definitions[name]
table = sections[section]
calls = {}
for i in range(table[7]):
    offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
    offset -= start
    if kind == 20 and 0 <= offset < len(body) - 3:
        calls[symbols[index][0]] = (0x46b5c0 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
for prefix, address in [('?createDataModel@DataModel@RBX@@', 0x57c100), ('??0Lock@DataModel@RBX@@', 0x411b40), ('??$create@VRunService@', 0x4530f0), ('??$shared_from@VRunService@', 0x618a40), ('?addListener@?$Notifier@VWorkspace@', 0x4218a0), ('??$find@VSelection@', 0x4153b0), ('?addListener@?$Notifier@VSelection@', 0x4218a0), ('??1Lock@DataModel@RBX@@', 0x5773c0)]:
    assert any(k.startswith(prefix) and v == address for k, v in calls.items()), (prefix, calls)
receipt = {'scope': 'Inactive trial. Vector element type and semantics, full ModelInstance/Workspace layout, class lifetimes and linked target implementations remain unproven.', 'observer_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(), 'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(), 'profile_sha256': hashlib.sha256(profile.read_bytes()).hexdigest(), 'object_sha256': hashlib.sha256(raw).hexdigest(), 'address': '0046b5c0', 'size': len(body), 'original_size': len(target), 'exact': exact, 'normalized_offset_only_matches': not vector_trial, 'donor_notifier_offset': '0x32c', 'original_notifier_offset': '0x344', 'calls': {k: hex(v) for k, v in calls.items()}, 'flags': compileflags}
if vector_trial:
    receipt['model_header_sha256'] = hashlib.sha256(model_header.read_bytes()).hexdigest()
    receipt['overlay_header_sha256'] = hashlib.sha256((overlay / 'ModelInstance.h').read_bytes()).hexdigest()
filename = 'workspace-finalconstruct-vector-trial.json' if vector_trial else 'workspace-finalconstruct-mismatch.json'
(root / 'work/2008-06/shared-layouts' / filename).write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS FinalConstruct exact:', exact, '; vector semantics and runtime remain unproven')
