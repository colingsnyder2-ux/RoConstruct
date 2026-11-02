"""Verify inactive AxisMoveTool constructor, destructors and vtable structure."""
import hashlib, json, struct, sys
from pathlib import Path
import pefile
root = Path(__file__).resolve().parents[3]; sys.path.insert(0, str(root))
from roc import match, rebuild
out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/tests/NativeAxisMoveToolTrial.cpp'
header = root / 'rebuild/2008-06/tests/NativeAxisMoveToolTrial.h'
obj = out / 'NativeAxisMoveToolTrial.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags.insert(0, '/I' + str(out / 'workspace-model-vector-include'))
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/Fo' + str(obj), str(source)], out); assert code == 0, log
raw = obj.read_bytes(); sections, symbols, definitions, _ = match._coff_data_index(raw)
rows = []
for prefix, address, expected in [
 ('??0AxisMoveTool@RBX@@', 0x640560, [('??0MouseCommand@', 0x6159f0), ('??_7AxisMoveTool@RBX@@6BINamed', 0x84a5ac), ('??_7AxisMoveTool@RBX@@6BIRenderable', 0x84a594), ('??_C@', 0x833850), ('??0Ray@', 0x510a30)]),
 ('??1AxisMoveTool@RBX@@', 0x640620, [('??_7Ray@', 0x8282c4), ('??1MegaDragger@', 0x60e700), ('??3@', 0x6a067a), ('??1MouseCommand@', 0x615780)]),
 ('??_GAxisMoveTool@RBX@@', 0x640760, [('??1AxisMoveTool@', 0x640620), ('??3@', 0x6a067a)]),
 ('?getCursorName@AxisMoveTool@RBX@@', 0x6405f0, [('__imp_??0?$basic_string@', 0x80245c)]),
]:
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', '%08x' % address)
    assert match.exact_match(target, targetrefs, body, refs), name
    start, section = definitions[name]; table = sections[section]; bindings = {}
    for i in range(table[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', raw, table[5] + 10*i); offset -= start
        if not 0 <= offset < len(body) - 3: continue
        value = struct.unpack_from('<I', target, offset)[0]
        if kind == 20: value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        bindings.setdefault(symbols[symbol][0], value)
    for symbol, value in expected:
        assert any(k.startswith(symbol) and v == value for k, v in bindings.items()), (symbol, bindings)
    rows.append({'symbol': name, 'address': hex(address), 'size': len(body), 'exact': True,
                 'bindings': {k: hex(v) for k, v in bindings.items()}})
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe')); image = pe.OPTIONAL_HEADER.ImageBase
vtables = []
for suffix, address, expected in [
 ('IRenderable', 0x84a594, [0x60a2f0, 0x60a2f0, 0x640f30, 0x641040, 0x458e90]),
 ('INamed', 0x84a5ac, [0x640780, 0x640e20, 0x641160, 0x6404b0, 0x5c72e0, 0x5f2310, 0x640800, 0x70bdf0, 0x6406a0, 0x615820, 0x5a0150, 0x5a04a0, 0x640760, 0x640700, 0x615a50, 0x6405f0]),
]:
    name = next(k for k in definitions if k.startswith('??_7AxisMoveTool@') and suffix in k)
    start, section = definitions[name]; table = sections[section]; assert table[3] - start == 4 * len(expected)
    slots = {}
    for i in range(table[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', raw, table[5] + 10*i); offset -= start
        if offset < 0: continue
        assert offset % 4 == 0 and offset // 4 < len(expected)
        target = struct.unpack('<I', pe.get_data(address + offset - image, 4))[0]
        assert target == expected[offset // 4]
        slots[offset // 4] = {'symbol': symbols[symbol][0], 'original_address': hex(target)}
    assert len(slots) == len(expected)
    vtables.append({'base': suffix, 'address': hex(address), 'slots': [slots[i] for i in range(len(expected))]})
methods_source = root / 'rebuild/2008-06/tests/NativeAxisMoveToolMethodsTrial.cpp'
methods_obj = out / 'NativeAxisMoveToolMethodsTrial.obj'
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/Fo' + str(methods_obj), str(methods_source)], out); assert code == 0, log
methods_raw = methods_obj.read_bytes(); sections, symbols, definitions, _ = match._coff_data_index(methods_raw)
for prefix, address, expected in [
 ('?newMouseCommand@?$TToolVerb@VAxisMoveTool', 0x5c6510, [('??2@', 0x6a0920), ('??0AxisMoveTool@', 0x640560)]),
 ('?getName@?$Named@VArrowToolBase@RBX@@$1?sAxisMoveTool', 0x640780, [('?flag@', 0x9796a0), ('?callDoDeclare@', 0x5c6230), ('?call_once@boost@@', 0x557330), ('?doDeclare@', 0x5c5fa0)]),
 ('?isSticky@AxisMoveTool', 0x640700, [('??2@', 0x6a0920), ('??0AxisMoveTool@', 0x640560)]),
 ('?onMouseUp@AxisMoveTool', 0x6406a0, [('?finishDragging@MegaDragger@', 0x60e780), ('?recordCameraHistory@', 0x58c5c0)]),
 ('?onMouseIdle@AxisMoveTool', 0x641160, [('?onMouseIdle@ArrowToolBase@', 0x616180), ('?hitHandle@AxisMoveTool@', 0x640d50), ('?getCursorName@ArrowToolBase@', 0x6161a0)]),
]:
    name, body, refs = next(x for x in match.coff_functions(methods_raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', '%08x' % address)
    assert match.exact_match(target, targetrefs, body, refs), name
    start, section = definitions[name]; table = sections[section]; bindings = {}
    for i in range(table[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', methods_raw, table[5] + 10*i); offset -= start
        if not 0 <= offset < len(body) - 3: continue
        value = struct.unpack_from('<I', target, offset)[0]
        if kind == 20: value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        bindings.setdefault(symbols[symbol][0], value)
    for symbol, value in expected:
        assert any(k.startswith(symbol) and v == value for k, v in bindings.items()), (symbol, bindings)
    rows.append({'symbol': name, 'address': hex(address), 'size': len(body), 'exact': True,
                 'bindings': {k: hex(v) for k, v in bindings.items()}})
down_source = root / 'rebuild/2008-06/tests/NativeAxisMoveDownTrial.cpp'
down_obj = out / 'NativeAxisMoveDownTrial.obj'
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/fp:fast', '/Fo' + str(down_obj), str(down_source)], out); assert code == 0, log
down_raw = down_obj.read_bytes(); sections, symbols, definitions, _ = match._coff_data_index(down_raw)
for prefix, address, expected in [
 ('?hitHandle@AxisMoveTool', 0x640d50, [('?inf@Vector3@', 0x510960), ('?bounds@AxisMoveTool@', 0x640b40), ('?getUnitMouseRay@MouseCommand@', 0x615d00), ('?hitMoveHandles@', 0x665880)]),
 ('?onMouseDown@AxisMoveTool', 0x640e20, [('?hitHandle@AxisMoveTool@', 0x640d50), ('?toGrid@Math@', 0x5dee10), ('?normalIdToVector3@', 0x5ec570), ('?fromOriginAndDirection@Ray@', 0x518830), ('?onMouseDown@ArrowToolBase@', 0x617780)]),
]:
    name, body, refs = next(x for x in match.coff_functions(down_raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', '%08x' % address)
    assert match.exact_match(target, targetrefs, body, refs), name
    start, section = definitions[name]; table = sections[section]; bindings = {}
    for i in range(table[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', down_raw, table[5] + 10*i); offset -= start
        if not 0 <= offset < len(body) - 3: continue
        value = struct.unpack_from('<I', target, offset)[0]
        if kind == 20: value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        bindings.setdefault(symbols[symbol][0], value)
    for symbol, value in expected:
        assert any(k.startswith(symbol) and v == value for k, v in bindings.items()), (symbol, bindings)
    rows.append({'symbol': name, 'address': hex(address), 'size': len(body), 'exact': True,
                 'bindings': {k: hex(v) for k, v in bindings.items()}})
hit_source = root / 'rebuild/2008-06/tests/NativeHitMoveHandlesTrial.cpp'
hit_obj = out / 'NativeHitMoveHandlesTrial.obj'
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/fp:fast', '/Fo' + str(hit_obj), str(hit_source)], out); assert code == 0, log
hit_raw = hit_obj.read_bytes(); sections, symbols, definitions, _ = match._coff_data_index(hit_raw)
name, body, refs = next(x for x in match.coff_functions(hit_raw) if x[0].startswith('?hitMoveHandles@RBX@@'))
address = 0x665880; target, targetrefs, _ = match.target('2008-06', '%08x' % address)
assert match.exact_match(target, targetrefs, body, refs)
start, section = definitions[name]; table = sections[section]; bindings = {}
for i in range(table[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', hit_raw, table[5] + 10*i); offset -= start
    if not 0 <= offset < len(body) - 3: continue
    value = struct.unpack_from('<I', target, offset)[0]
    if kind == 20: value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
    bindings.setdefault(symbols[symbol][0], value)
for symbol, value in [('?identity@Matrix3@', 0x513e20), ('??0Matrix3@', 0x513220), ('?hitTestHandleLocal@HandleHitTest@', 0x6656b0)]:
    assert any(k.startswith(symbol) and v == value for k, v in bindings.items()), (symbol, bindings)
rows.append({'symbol': name, 'address': hex(address), 'size': len(body), 'exact': True,
             'bindings': {k: hex(v) for k, v in bindings.items()}})
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'scope': 'Inactive lifetime and vtable structure only. Full methods, shared ABI and runtime unproven.',
           'size': '0x74', 'source_sha256': sha(source), 'header_sha256': sha(header), 'object_sha256': sha(obj), 'methods_source_sha256': sha(methods_source), 'methods_object_sha256': sha(methods_obj), 'down_source_sha256': sha(down_source), 'down_object_sha256': sha(down_obj), 'hit_source_sha256': sha(hit_source), 'hit_object_sha256': sha(hit_obj),
           'observer_sha256': sha(Path(__file__)), 'methods': rows, 'vtables': vtables, 'flags': flags}
(root / 'work/2008-06/shared-layouts/axis-move-tool-lifetime-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS AxisMoveTool lifetime, six methods, bindings and vtable structure')
