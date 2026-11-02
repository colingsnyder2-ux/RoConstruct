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
for tool, address in [('GlueTool', 0x5c66d0), ('WeldTool', 0x5c6840), ('StudsTool', 0x5c6990), ('InletTool', 0x5c6ae0), ('HingeTool', 0x5c6c30), ('RightMotorTool', 0x5c6d80), ('LeftMotorTool', 0x5c6e40), ('OscillateMotorTool', 0x5c6f40), ('ModelSetFrontTool', 0x5c7030), ('AnchorTool', 0x5c71e0), ('LockTool', 0x5c72b0), ('FlatTool', 0x5c6580), ('AxisMoveTool', 0x5c64e0), ('ResizeTool', 0x5c6420), ('ArrowTool', 0x5c6240), ('NullTool', 0x5c75e0), ('GameTool', 0x5c7680), ('FillTool', 0x5c7380), ('DropperTool', 0x5c74d0), ('ModelSetPrimaryPartTool', 0x5c7120)]:
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
receipt = {'scope': 'Inactive native predicates match with provisional ModelInstance/Workspace overlay. Full layout, type identity and runtime ABI remain unproven.', 'observer_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(), 'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(), 'resize_header_sha256': hashlib.sha256((source.parent / 'NativeResizeToolTrial.h').read_bytes()).hexdigest(), 'axis_header_sha256': hashlib.sha256((source.parent / 'NativeAxisMoveToolTrial.h').read_bytes()).hexdigest(), 'flat_header_sha256': hashlib.sha256((source.parent / 'NativeFlatToolTrial.h').read_bytes()).hexdigest(), 'surface_header_sha256': hashlib.sha256((source.parent / 'NativeSurfaceToolTrial.h').read_bytes()).hexdigest(), 'sibling_header_sha256': hashlib.sha256((source.parent / 'NativeSurfaceSiblingsTrial.h').read_bytes()).hexdigest(), 'model_tools_header_sha256': hashlib.sha256((source.parent / 'NativeModelToolsTrial.h').read_bytes()).hexdigest(), 'model_tool_header_sha256': hashlib.sha256((source.parent / 'NativeModelToolTrial.h').read_bytes()).hexdigest(), 'object_sha256': hashlib.sha256(raw).hexdigest(), 'model_overlay_sha256': hashlib.sha256((overlay / 'v8datamodel/ModelInstance.h').read_bytes()).hexdigest(), 'workspace_overlay_sha256': hashlib.sha256((overlay / 'v8datamodel/Workspace.h').read_bytes()).hexdigest(), 'methods': rows, 'flags': flags}
(root / 'work/2008-06/shared-layouts/tool-checked-multi-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS', len(rows), 'native tool predicates')
