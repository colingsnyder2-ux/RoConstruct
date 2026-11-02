"""Verify native tool predicates using recovered tool types and layout profile."""
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
overlay = out / 'workspace-model-vector-include'
source = root / 'rebuild/2008-06/tests/NativeToolCheckedMultiTrial.cpp'
obj = out / 'NativeToolCheckedMultiTrial.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags.insert(0, '/I' + str(overlay))
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
image = pe.OPTIONAL_HEADER.ImageBase
rows = []
for tool, address in [('ArrowTool', 0x5c6240), ('NullTool', 0x5c75e0), ('GameTool', 0x5c7680), ('FillTool', 0x5c7380), ('DropperTool', 0x5c74d0), ('ModelSetPrimaryPartTool', 0x5c7120)]:
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?isChecked@?$TToolVerb@V' + tool + '@'))
    target, targetrefs, _ = match.target('2008-06', '%08x' % address)
    assert match.exact_match(target, targetrefs, body, refs), tool
    start, section = definitions[name]
    table = sections[section]
    bindings = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        offset -= start
        if 0 <= offset < len(body) - 3:
            value = struct.unpack_from('<I', target, offset)[0]
            if kind == 20:
                value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            bindings[symbols[index][0]] = value
    descriptor = struct.unpack_from('<I', target, 30)[0]
    assert pe.get_string_at_rva(descriptor + 8 - image) == ('.?AV' + tool + '@RBX@@').encode()
    assert any(tool in k and v == descriptor for k, v in bindings.items()), (tool, bindings)
    assert any('RTtypeid' in k and v == 0x6a1de2 for k, v in bindings.items()), bindings
    rows.append({'tool': tool, 'address': hex(address), 'symbol': name, 'size': len(body), 'exact': True, 'type_descriptor': hex(descriptor)})
receipt = {'scope': 'Inactive native predicates match with provisional ModelInstance/Workspace overlay. Full layout, type identity and runtime ABI remain unproven.', 'observer_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(), 'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(), 'object_sha256': hashlib.sha256(raw).hexdigest(), 'model_overlay_sha256': hashlib.sha256((overlay / 'v8datamodel/ModelInstance.h').read_bytes()).hexdigest(), 'workspace_overlay_sha256': hashlib.sha256((overlay / 'v8datamodel/Workspace.h').read_bytes()).hexdigest(), 'methods': rows, 'flags': flags}
(root / 'work/2008-06/shared-layouts/tool-checked-multi-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS', len(rows), 'native tool predicates')
