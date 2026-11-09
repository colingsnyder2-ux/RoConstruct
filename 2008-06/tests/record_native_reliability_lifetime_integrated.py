"""Check native ReliabilityLayer constructor and destructor."""
import hashlib, json, struct, sys
from pathlib import Path
root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild
prior = json.loads((root / 'work/2008-06/shared-layouts/profiling-integrated.json').read_text())
flags = [x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')]
out = root / 'rebuild/2008-06/out/native-layouts/reliability-lifetime-integrated'
out.mkdir(parents=True, exist_ok=True)
source = root / 'rebuild/2008-06/native-classes/ReliabilityLayerLifetime.cpp'
obj = out / 'ReliabilityLayerLifetime.obj'
donor = root / 'tools/openrbx/3rdparty/RakNet30/Source'
flags.insert(next(i for i, x in enumerate(flags) if x.startswith('/I')) + 1, '/I' + str(donor))
flags += ['/I' + str(root / 'tools/openrbx/util'), '/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
(out / 'compile.log').write_text(log)
if code:
    print(log)
    sys.exit(code)
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
rows = []
for prefix, address, expected in [('??0ReliabilityLayer@@', 0x4d25d0, [('??0BitStream@', 0x4a50c0), ('??0DataBlockEncryptor@@', 0x4d5980), ('?InitializeVariables@ReliabilityLayer@@', 0x4cea10)]), ('??1ReliabilityLayer@@', 0x4d3b40, [('?FreeThreadSafeMemory@ReliabilityLayer@@', 0x4d2780), ('??1BitStream@', 0x4a51a0), ('??1DataBlockEncryptor@@', 0x47d410)])]:
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', '%08x' % address)
    assert match.exact_match(target, targetrefs, body, refs)
    start, index = definitions[name]
    table = sections[index]
    bindings = {}
    for i in range(table[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', raw, table[5] + i * 10)
        offset -= start
        if kind == 20 and 0 <= offset < len(body) - 3:
            bindings[symbols[symbol][0]] = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
    for key, value in expected:
        assert any(k.startswith(key) and v == value for k, v in bindings.items()), (key, bindings)
    rows.append({'symbol': name, 'address': hex(address), 'size': len(body), 'bindings': {k: hex(v) for k, v in bindings.items()}})
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
paths = [source, root / 'rebuild/2008-06/native-headers/ReliabilityLayer.h', Path(__file__)]
receipt = {'scope': 'Native ReliabilityLayer lifetime byte and selected binding checks only; complete ABI and runtime remain unproven.', 'sources': {str(p.relative_to(root)): sha(p) for p in paths}, 'object_sha256': sha(obj), 'flags': flags, 'methods': rows}
(root / 'work/2008-06/shared-layouts/reliability-lifetime-integrated.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native ReliabilityLayer constructor, destructor and selected bindings')
