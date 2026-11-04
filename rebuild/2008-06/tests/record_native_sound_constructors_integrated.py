"""Check native sound constructor template instantiations."""
import hashlib, json, struct, sys
from pathlib import Path
root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild
prior = json.loads((root / 'work/2008-06/shared-layouts/profiling-integrated.json').read_text())
flags = [x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')]
out = root / 'rebuild/2008-06/out/native-layouts/sound-constructors-integrated'
out.mkdir(parents=True, exist_ok=True)
source = root / 'rebuild/2008-06/native-classes/SoundConstructors.cpp'
obj = out / 'SoundConstructors.obj'
flags += ['/I' + str(root / 'tools/openrbx/3rdparty/fmod/api/inc'), '/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
(out / 'compile.log').write_text(log)
if code:
    print(log)
    sys.exit(code)
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
rows = []
for prefix, address, expected in [('??0?$DescribedCreatable@VSoundService', 0x5bbec0, [('??0?$FactoryProduct@VSoundService', 0x5b6b60), ('?classDescriptor@', 0x5bb7f0)]), ('??0?$DescribedCreatable@VSoundChannel', 0x5bbfb0, [('??0?$FactoryProduct@VSoundChannel', 0x5b6bc0), ('?classDescriptor@', 0x5bb860)]), ('??0?$DescribedCreatable@VStockSound', 0x5bd0f0, [('??0?$FactoryProduct@VStockSound', 0x5bc960), ('?classDescriptor@', 0x5bb8d0)])]:
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
paths = [source, root / 'rebuild/2008-06/native-headers/util/Sound.h', root / 'rebuild/2008-06/native-headers/v8tree/Instance.h', root / 'rebuild/2008-06/native-headers/reflection/reflection.h', Path(__file__)]
receipt = {'scope': 'Native constructor template byte and selected binding checks only; full sound ABI and runtime remain unproven.', 'sources': {str(p.relative_to(root)): sha(p) for p in paths}, 'object_sha256': sha(obj), 'flags': flags, 'methods': rows}
(root / 'work/2008-06/shared-layouts/sound-constructors-integrated.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native sound service/channel/stock template constructors and selected targets')
