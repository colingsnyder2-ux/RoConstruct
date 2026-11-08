"""Verify native tool predicate against the isolated Workspace layout hypothesis."""
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
model = overlay / 'v8datamodel/ModelInstance.h'
assert model.exists(), 'run record_native_workspace_finalconstruct_trial.py --model-vector-trial first'
workspace = root / 'rebuild/2008-06/native-headers/v8datamodel/Workspace.h'
text = workspace.read_text()
before = 'RBXASSERT(currentCommand.get());'
assert text.count(before) == 1
(overlay / 'v8datamodel/Workspace.h').write_text(text.replace(before, '', 1))
source = root / 'rebuild/2008-06/experiments/trials/NativeToolCheckedTrial.cpp'
obj = out / 'NativeToolCheckedVectorTrial.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags.insert(0, '/I' + str(overlay))
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?isChecked@?$TToolVerb@VArrowTool@'))
target, targetrefs, _ = match.target('2008-06', '005c6240')
assert match.exact_match(target, targetrefs, body, refs), (len(body), len(target))
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
            value = (0x5c6240 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        bindings[symbols[index][0]] = value
assert any('ArrowTool' in k and v == 0x94bc74 for k, v in bindings.items()), bindings
assert any('RTtypeid' in k and v == 0x6a1de2 for k, v in bindings.items()), bindings
receipt = {'scope': 'Inactive Arrow predicate matches using provisional ModelInstance vector and an assertion-free Workspace accessor. Element type, entire layout and runtime remain unproven.', 'observer_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(), 'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(), 'model_overlay_sha256': hashlib.sha256(model.read_bytes()).hexdigest(), 'workspace_overlay_sha256': hashlib.sha256((overlay / 'v8datamodel/Workspace.h').read_bytes()).hexdigest(), 'object_sha256': hashlib.sha256(raw).hexdigest(), 'address': '005c6240', 'size': len(body), 'exact': True, 'bindings': {k: hex(v) for k, v in bindings.items()}, 'flags': flags}
(root / 'work/2008-06/shared-layouts/tool-checked-vector-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS Arrow tool predicate with provisional Workspace profile')
