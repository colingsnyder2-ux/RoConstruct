"""Verify ATL SAFEARRAY accessor and isolate builder profile mismatch."""
import hashlib
import json
import struct
import sys
from pathlib import Path

import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

root = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/tests/NativeSafeArrayMismatch.cpp'
obj = out / 'NativeSafeArrayMismatch.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
functions = match.coff_functions(raw)
builder_name, body, refs = next(x for x in functions if x[0].startswith('?makeSafeArray@@'))
target, targetrefs, _ = match.target('2008-06', '004165e0')
assert len(body) == 189 and len(target) == 168 and not match.exact_match(target, targetrefs, body, refs)
config_obj = out / 'NativeSafeArrayUncheckedTrial.obj'
config_flags = [x for x in flags if not x.startswith('/Fo')] + ['/D_SECURE_SCL=0', '/Fo' + str(config_obj)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', config_flags, out)
assert code == 0, log
_, config_body, config_refs = next(x for x in match.coff_functions(config_obj.read_bytes()) if x[0].startswith('?makeSafeArray@@'))
assert len(config_body) == 166 and not match.exact_match(target, targetrefs, config_body, config_refs)
access_name, access_body, access_refs = next(x for x in functions if 'GetAt@?$CComSafeArray' in x[0])
access_target, access_targetrefs, _ = match.target('2008-06', '00415b00')
assert match.exact_match(access_target, access_targetrefs, access_body, access_refs)
start, section = definitions[access_name]
table = sections[section]
bindings = {}
for i in range(table[7]):
    offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
    offset -= start
    if 0 <= offset < len(access_body) - 3:
        value = struct.unpack_from('<I', access_target, offset)[0]
        if kind == 20:
            value = (0x415b00 + offset + 4 + struct.unpack_from('<i', access_target, offset)[0]) & 0xffffffff
        bindings[symbols[index][0]] = value
for prefix, value in [('__imp__SafeArrayGetLBound@12', 0x802918), ('__imp__SafeArrayGetUBound@12', 0x802914), ('?AtlThrowImpl@ATL@@', 0x401000)]:
    assert any(k.startswith(prefix) and v == value for k, v in bindings.items()), (prefix, bindings)
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
image = pe.OPTIONAL_HEADER.ImageBase
type_checks = []
for address, descriptor, name in [
    (0x415d10, 0x92bef8, b'.?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@'),
    (0x415d30, 0x92bf44, b'.?AVContentId@RBX@@'),
    (0x415d50, 0x92bf60, b'.?AV?$vector@VValue@Reflection@RBX@@V?$allocator@VValue@Reflection@RBX@@@std@@@std@@'),
]:
    code, _, _ = match.target('2008-06', '%08x' % address)
    assert b'\xb9' + struct.pack('<I', descriptor) in code
    assert pe.get_string_at_rva(descriptor + 8 - image) == name
    type_checks.append({'address': hex(address), 'descriptor': hex(descriptor), 'type': name.decode()})
value_converter, _, _ = match.target('2008-06', '00416370')
calls = {int(i.op_str, 16) for i in Cs(CS_ARCH_X86, CS_MODE_32).disasm(value_converter, 0x416370) if i.mnemonic == 'call' and i.op_str.startswith('0x')}
assert {0x415d10, 0x415d30, 0x415d50, 0x4165e0} <= calls
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
receipt = {'scope': 'Inactive builder mismatch; do not link or run. Original ATL GetAt matches; builder and Reflection::Value conversion remain unproven.', 'observer_sha256': sha(Path(__file__)), 'source_sha256': sha(source), 'object_sha256': sha(obj), 'builder': {'address': '004165e0', 'symbol': builder_name, 'candidate_size': len(body), 'original_size': len(target), 'exact': False}, 'accessor': {'address': '00415b00', 'symbol': access_name, 'size': len(access_body), 'exact': True, 'bindings': {k: hex(v) for k, v in bindings.items()}}, 'flags': flags}
receipt['value_converter'] = {'address': '00416370', 'type_checks': type_checks, 'nested_array_target': '0x4165e0', 'note': 'Original nested type is vector<Reflection::Value>, not vector<Instance> from mined stub.'}
receipt['unchecked_vector_trial'] = {'flags': config_flags, 'object_sha256': sha(config_obj), 'candidate_size': len(config_body), 'original_size': len(target), 'exact': False, 'note': 'Unchecked profile uses vector storage at +4/+8; original accesses +0xc/+0x10. This ABI change is not a valid integration.'}
(root / 'work/2008-06/shared-layouts/safearray-builder-mismatch.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS ATL SAFEARRAY accessor; builder mismatch recorded')
