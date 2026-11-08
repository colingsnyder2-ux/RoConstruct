"""Verify recovered ResizeTool lifetime and original symbol bindings."""
import hashlib, json, struct, sys
from pathlib import Path
import pefile
root = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(root))
from roc import match, rebuild
out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/experiments/trials/NativeResizeToolTrial.cpp'
header = root / 'rebuild/2008-06/tests/NativeResizeToolTrial.h'
obj = out / 'NativeResizeToolTrial.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags.insert(0, '/I' + str(out / 'workspace-model-vector-include'))
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/Fo' + str(obj), str(source)], out)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
rows = []
for prefix, address, expected in [
    ('??0ResizeTool@RBX@@', 0x5c62f0, [('??0MouseCommand@', 0x6159f0), ('??_7ResizeTool@RBX@@6BINamed', 0x839124), ('??_7ResizeTool@RBX@@6BIRenderable', 0x839108)]),
    ('??1ResizeTool@RBX@@', 0x5c6340, [('??1MouseCommand@', 0x615780)]),
    ('??_GResizeTool@RBX@@', 0x5c6400, [('??1ResizeTool@', 0x5c6340), ('??3@', 0x6a067a)]),
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
        bindings[symbols[symbol][0]] = value
    for symbol, value in expected:
        assert any(k.startswith(symbol) and v == value for k, v in bindings.items()), (symbol, bindings)
    rows.append({'symbol': name, 'address': hex(address), 'size': len(body), 'exact': True,
                 'bindings': {k: hex(v) for k, v in bindings.items()}})
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
image = pe.OPTIONAL_HEADER.ImageBase
vtables = []
for suffix, address, expected in [
    ('IRenderable', 0x839108, [0x60a2f0, 0x60a2f0, 0x63f470, 0x63f2d0, 0x458e90]),
    ('INamed', 0x839124, [0x5c64c0, 0x63f670, 0x616180, 0x63f630, 0x5c72e0,
                          0x5f2310, 0x63ee20, 0x70bdf0, 0x63ed20, 0x615820,
                          0x5a0150, 0x5a04a0, 0x5c6400, 0x5c63a0, 0x615a50, 0x63ec60]),
]:
    name = next(k for k in definitions if k.startswith('??_7ResizeTool@') and suffix in k)
    start, section = definitions[name]; table = sections[section]
    assert table[3] - start == 4 * len(expected), (name, table[3], start)
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
factory_source = root / 'rebuild/2008-06/experiments/trials/NativeResizeToolFactoryTrial.cpp'
factory_obj = out / 'NativeResizeToolFactoryTrial.obj'
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/Fo' + str(factory_obj), str(factory_source)], out)
assert code == 0, log
factory_raw = factory_obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(factory_raw)
name, body, refs = next(x for x in match.coff_functions(factory_raw) if x[0].startswith('?newMouseCommand@?$TToolVerb@VResizeTool'))
address = 0x5c6450
target, targetrefs, _ = match.target('2008-06', '%08x' % address)
assert match.exact_match(target, targetrefs, body, refs)
start, section = definitions[name]; table = sections[section]; bindings = {}
for i in range(table[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', factory_raw, table[5] + 10*i); offset -= start
    if not 0 <= offset < len(body) - 3: continue
    value = struct.unpack_from('<I', target, offset)[0]
    if kind == 20: value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
    bindings[symbols[symbol][0]] = value
for symbol, value in [('??2@', 0x6a0920), ('??0ResizeTool@', 0x5c62f0)]:
    assert any(k.startswith(symbol) and v == value for k, v in bindings.items()), (symbol, bindings)
rows.append({'symbol': name, 'address': hex(address), 'size': len(body), 'exact': True,
             'bindings': {k: hex(v) for k, v in bindings.items()}})
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'scope': 'Inactive ResizeTool lifetime only; complete vtable, other methods and runtime unproven.',
           'size': '0x48', 'vtables': vtables, 'source_sha256': sha(source), 'header_sha256': sha(header),
           'object_sha256': sha(obj), 'factory_source_sha256': sha(factory_source), 'factory_object_sha256': sha(factory_obj), 'observer_sha256': sha(Path(__file__)), 'methods': rows, 'flags': flags}
(root / 'work/2008-06/shared-layouts/resize-tool-lifetime-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS ResizeTool constructor, destructors, factory and bindings')
