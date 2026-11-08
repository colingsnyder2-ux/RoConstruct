"""Verify recovered workspace getter and verb constructor for Doc initializer."""
import hashlib, json, struct, sys
from pathlib import Path
root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild
out = root / 'rebuild/2008-06/out/native-layouts'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
common = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
units = [('rebuild/2008-06/native-classes/Verb.cpp', 'NativeVerbConstructor.obj', '005833e0', '??0Verb@RBX@@', {'?declare@Name@RBX@@': 0x553f90, '??A?$map@': 0x5644a0}),
         ('rebuild/2008-06/experiments/trials/NativeWorkspaceGetWorkspaceTrial.cpp', 'NativeWorkspaceGetWorkspaceTrial.obj', '0046a970', '?getWorkspace@CWorkspace@@', {}),
         ('rebuild/2008-06/experiments/trials/NativeRunStateVerbConstructorTrial.cpp', 'NativeRunStateVerbConstructorTrial.obj', '0057e330', '??0RunStateVerb@RBX@@', {'??0Verb@RBX@@': 0x5833e0, '??_7RunStateVerb@RBX@@': 0x83074c}),
         ('rebuild/2008-06/tests/NativeEditSelectionVerbConstructorTrial.cpp', 'NativeEditSelectionVerbConstructorTrial.obj', '0057e730', '??0EditSelectionVerb@RBX@@', {'??0Verb@RBX@@': 0x5833e0, '??_7EditSelectionVerb@RBX@@': 0x830764, '??$shared_from@VWorkspace@RBX@@': 0x618a40}),
         ('rebuild/2008-06/experiments/trials/NativeWorkspaceSharedFromTrial.cpp', 'NativeWorkspaceSharedFromTrial.obj', '00618a40', '??$shared_from@VWorkspace@RBX@@', {'?shared_from_this@': 0x42af90, '??$shared_static_cast@VWorkspace@RBX@@': 0x4a2070}),
         ('rebuild/2008-06/experiments/trials/NativeAxisBaseTrial.cpp', 'NativeAxisBaseTrial.obj', '0057f450', '??0RotateAxisCommand@RBX@@', {'??0EditSelectionVerb@RBX@@': 0x57e730, '??_7RotateAxisCommand@RBX@@': 0x830a50}),
         ('rebuild/2008-06/experiments/trials/NativeAxisBaseTrial.cpp', 'NativeAxisBaseTrial.obj', '0057f4c0', '??0ControllerCommand@RBX@@', {'??0EditSelectionVerb@RBX@@': 0x57e730, '??_7ControllerCommand@RBX@@': 0x830a6c})]
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
rows = []
for path, output, address, prefix, expected in units:
    source, obj = root / path, out / output
    flags = common + ['/Fo' + str(obj), str(source)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
    assert code == 0, log
    raw = obj.read_bytes()
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', address)
    assert match.exact_match(target, targetrefs, body, refs), address
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    start, index = definitions[name]
    section = sections[index]
    found = {}
    for i in range(section[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
        offset -= start
        if not 0 <= offset < len(body)-3:
            continue
        value = struct.unpack_from('<I', target, offset)[0]
        if kind == 20:
            value = (int(address,16) + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        for key, wanted in expected.items():
            if symbols[symbol][0].startswith(key):
                assert value == wanted, (key, hex(value))
                found[key] = hex(value)
    assert set(found) == set(expected)
    rows.append({'address': address, 'size': len(body), 'source_sha256': sha(source), 'object_sha256': sha(obj), 'flags': flags, 'targets': found})
headers = [root / 'rebuild/2008-06/native-headers'/p for p in ('CWorkspace.h','v8datamodel/DataModel.h','v8tree/Verb.h','v8tree/VerbContainer.h')]
headers.append(root / 'tools/rbxgs/Client/App/include/v8datamodel/Workspace.h')
receipt = {'observer_sha256': sha(Path(__file__)), 'headers': {str(p.relative_to(root)): sha(p) for p in headers}, 'methods': rows, 'scope': 'Inactive trial. Containing layouts, destructor and runtime ABI still require verification.'}
(root / 'work/2008-06/shared-layouts/initializer-dependencies-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS workspace getter, shared ownership helper and native verb constructors')
