"""Compare candidate Workspace base conversions to original RTTI offsets."""
import hashlib
import json
import sys
from pathlib import Path

import capstone

root = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/experiments/trials/NativeWorkspaceBaseOffsetsTrial.cpp'
obj = out / 'NativeWorkspaceBaseOffsetsTrial.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
functions = match.coff_functions(obj.read_bytes())
decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
expected = [('guiOffset', '.?AVGuiTarget@RBX@@', 0x2e8), ('verbOffset', '.?AVVerbContainer@RBX@@', 0x2ec), ('movingOffset', '.?AVIMovingManager@RBX@@', 0x314), ('scriptOffset', '.?AVIScriptOwner@RBX@@', 0x340), ('drawOffset', '.?AV?$Notifier@VWorkspace@RBX@@VDrawChanged@2@@RBX@@', 0x344), ('toolOffset', '.?AV?$Notifier@VWorkspace@RBX@@VToolChanged@2@@RBX@@', 0x364), ('heartbeatOffset', '.?AV?$Listener@VRunService@RBX@@VHeartbeat@2@@RBX@@', 0x384), ('cameraOffset', '.?AVICameraOwner@RBX@@', 0x288), ('renderOffset', '.?AVIRenderable@RBX@@', 0x1a0), ('controllableOffset', '.?AVIControllable@RBX@@', 0x130), ('childNotifierOffset', '.?AV?$Notifier@VInstance@RBX@@UChildAdded@2@@RBX@@', 0x24)]
rtti_path = root / 'work/2008-06/shared-layouts/workspace-selection-rtti.json'
rtti = json.loads(rtti_path.read_text())['classes']['.?AVWorkspace@RBX@@']['tables'][0]['hierarchy']['bases']
rows = []
for function, typename, original in expected:
    assert any(x['type'] == typename and x['member_displacement'] == original for x in rtti), typename
    name, body, refs = next(x for x in functions if x[0].startswith('?' + function + '@@'))
    ins = list(decoder.disasm(body, 0))
    assert len(ins) == 2 and ins[0].mnemonic == 'mov' and ins[0].op_str.startswith('eax, ') and ins[1].mnemonic == 'ret', (name, body.hex())
    actual = int(ins[0].op_str.split(', ')[1], 0)
    assert actual == original, (function, hex(actual), hex(original))
    rows.append({'base': function, 'candidate_offset': hex(actual), 'original_offset': hex(original), 'delta': original - actual})
header = root / 'rebuild/2008-06/native-headers/v8datamodel/ModelInstance.h'
receipt = {'scope': 'Inactive candidate base conversions match original RTTI; full Workspace lifetime and live ABI remain unproven.', 'observer_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(), 'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(), 'model_header_sha256': hashlib.sha256(header.read_bytes()).hexdigest(), 'rtti_sha256': hashlib.sha256(rtti_path.read_bytes()).hexdigest(), 'object_sha256': hashlib.sha256(obj.read_bytes()).hexdigest(), 'rows': rows, 'flags': flags}
(root / 'work/2008-06/shared-layouts/workspace-native-base-offsets.json').write_text(json.dumps(receipt, indent=2) + '\n')
print(rows)
