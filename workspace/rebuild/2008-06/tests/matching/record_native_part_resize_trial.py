"""Rebuild Part::resize in constructor-matched typed profile; no runtime claim."""
import hashlib, json, struct, sys
from pathlib import Path
import pefile
root = Path(__file__).resolve().parents[4]; sys.path.insert(0, str(root))
from roc import libs, match, rebuild
out = root / 'rebuild/2008-06/out/native-layouts'
unit = 'roc_part_grouped_tail_constructor_9b19d0716f31ff52.cpp'
pre = libs.unit('rbxgs-dll', unit, 21022)
baseline_source = out / 'NativePartResizeConstructor.cpp'; baseline_source.write_text(pre)
baseline_obj = out / 'NativePartResizeConstructor.obj'
baseline_flags = ['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(baseline_obj),str(baseline_source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', baseline_flags, out); assert code == 0, log
_, ctor, ctorrefs = next(x for x in match.coff_functions(baseline_obj.read_bytes()) if x[0].startswith('??0PartInstance@RBX@@'))
ctor_target, ctor_targetrefs, _ = match.target('2008-06', '0059d4d0')
assert match.exact_match(ctor_target, ctor_targetrefs, ctor, ctorrefs)
start = pre.rindex('PartInstance::PartInstance()'); opening = pre.index('{', start); depth = 0
for end in range(opening, len(pre)):
    if pre[end] == '{': depth += 1
    elif pre[end] == '}':
        depth -= 1
        if depth == 0: break
assert depth == 0
source = pre[:start] + pre[end+1:]
a = source.index('class PartInstance :'); b = source.index('typedef char primitive_target_size', a)
t = source[a:b]; old = 'G3D::Vector3 uiToXmlSize(const G3D::Vector3& uiSize) const;'
assert t.count(old) == 1
t = t.replace(old, '__declspec(noalias) ' + old); source = source[:a] + t + source[b:]
a = source.index('class Matrix3 {'); i = source.index('inline Vector3 operator* (const Vector3& v) const {', a)
opening = source.index('{', i); depth = 0
for end in range(opening, len(source)):
    if source[end] == '{': depth += 1
    elif source[end] == '}':
        depth -= 1
        if depth == 0: break
assert depth == 0
source = source[:i] + '__declspec(noinline) Vector3 operator* (const Vector3& v) const;' + source[end+1:]
body = root / 'rebuild/2008-06/tests/NativePartResizeTrial.inc'
source += '\n' + body.read_text()
generated = out / 'NativePartResizeTrial.cpp'; generated.write_text(source)
obj = out / 'NativePartResizeTrial.obj'
flags = ['/nologo','/c','/O2','/Gy','/GS-','/EHsc','/MD','/fp:fast','/Fo'+str(obj),str(generated)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out); assert code == 0, log
raw = obj.read_bytes(); sections, symbols, definitions, _ = match._coff_data_index(raw)
name, data, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?resize@PartInstance@RBX@@'))
address = 0x59e150; target, targetrefs, _ = match.target('2008-06', '%08x' % address)
assert match.exact_match(target, targetrefs, data, refs)
link_obj = out / 'NativePartResizeLink.obj'
link_raw = rebuild.strip_symbols(raw, keep={name})
link_obj.write_bytes(link_raw)
_, link_body, link_refs = next(x for x in match.coff_functions(link_raw) if x[0] == name)
assert match.exact_match(target, targetrefs, link_body, link_refs)
start, section = definitions[name]; table = sections[section]; bindings = {}
for i in range(table[7]):
    offset, sym, kind = struct.unpack_from('<IIH', raw, table[5] + 10*i); offset -= start
    if not 0 <= offset < len(data) - 3: continue
    value = struct.unpack_from('<I', target, offset)[0]
    if kind == 20: value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
    bindings.setdefault(symbols[sym][0], value)
for token, value in [('?getCoordinateFrame@Primitive@', 0x5e82c0), ('??0Matrix3@', 0x513220),
                     ('?uiToXmlSize@PartInstance@', 0x599eb0), ('??DMatrix3@', 0x476580),
                     ('?setCoordinateFrame@PartInstance@', 0x59d8a0), ('?setPartSizeXml@PartInstance@', 0x59db90),
                     ('?join@PartInstance@', 0x59b4f0), ('?fuzzyEq@Math@', 0x5de2a0)]:
    assert any(k.startswith(token) and v == value for k, v in bindings.items()), (token, bindings)
# Original scalar destructor calls Part destructor; Part destructor destroys embedded Primitive at +0x228.
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe')); base = pe.OPTIONAL_HEADER.ImageBase
read = lambda a, n: pe.get_data(a - base, n)
assert struct.unpack('<I', read(0x832d3c, 4))[0] == 0x59bb40
assert read(0x59bb40, 8) == bytes.fromhex('83 e9 10 e9 c8 05 00 00')
assert read(0x59c113, 5) == bytes.fromhex('e8 58 f8 ff ff')
assert read(0x59ba9c, 6) == bytes.fromhex('8d 8e 28 02 00 00')
assert 0x59baac + struct.unpack('<i', read(0x59baa8, 4))[0] == 0x5e7df0
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'scope': 'Inactive Part resize and original lifetime evidence. Full rebuilt destructor, data identity and runtime ABI unproven.',
 'unit': unit, 'preprocessed_sha256': hashlib.sha256(pre.encode()).hexdigest(), 'source_sha256': sha(body),
 'generated_sha256': sha(generated), 'object_sha256': sha(obj), 'link_object_sha256': sha(link_obj),
 'constructor': {'address': '0x59d4d0', 'size': len(ctor), 'exact': True, 'object_sha256': sha(baseline_obj)}, 'observer_sha256': sha(Path(__file__)),
 'method': {'symbol': name, 'address': hex(address), 'size': len(data), 'exact': True,
            'bindings': {k: hex(v) for k, v in bindings.items()}},
 'original_destructor': {'vtable_thunk': '0x59bb40', 'deleting_destructor': '0x59c110', 'destructor': '0x59b970',
                         'primitive_offset': '0x228', 'primitive_destructor': '0x5e7df0'}, 'flags': flags}
(root / 'work/2008-06/shared-layouts/part-resize-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native Part resize and original embedded Primitive lifetime evidence')
