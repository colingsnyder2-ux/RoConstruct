"""Verify recovered ResizeTool lifetime and original symbol bindings."""
import hashlib, json, struct, sys
from pathlib import Path
root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild
out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/tests/NativeResizeToolTrial.cpp'
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
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'scope': 'Inactive ResizeTool lifetime only; complete vtable, other methods and runtime unproven.',
           'size': '0x48', 'source_sha256': sha(source), 'header_sha256': sha(header),
           'object_sha256': sha(obj), 'observer_sha256': sha(Path(__file__)), 'methods': rows, 'flags': flags}
(root / 'work/2008-06/shared-layouts/resize-tool-lifetime-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS ResizeTool constructor, implicit destructor, deleting destructor and bindings')
