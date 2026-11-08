"""Compare ModelInstance lifetime against the isolated vector hypothesis."""
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
source = root / 'rebuild/2008-06/experiments/trials/NativeModelLifetimeTrial.cpp'
header = root / 'rebuild/2008-06/native-headers/v8datamodel/ModelInstance.h'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
obj = out / 'NativeModelLifetimeTrial.obj'
flags += ['/fp:fast', '/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
rows = []
for prefix, address in [('??0ModelInstance@RBX@@', '00585630'), ('??1ModelInstance@RBX@@', '00584790')]:
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', address)
    assert match.exact_match(target, targetrefs, body, refs)
    start, section = definitions[name]
    table = sections[section]
    calls = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        offset -= start
        if kind == 20 and 0 <= offset < len(body) - 3:
            calls.setdefault(symbols[index][0], set()).add((int(address, 16) + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff)
    expected = [('??0CoordinateFrame@G3D@@', 0x4782d0), ('??0?$ComputeProp@VExtents@', 0x583ee0)] if address == '00585630' else [('??1IRenderable@RBX@@', 0x47d410), ('??1?$FactoryProduct@VModelInstance@', 0x5835b0)]
    for key, value in expected:
        assert any(k.startswith(key) and v == {value} for k, v in calls.items()), (key, calls)
    rows.append({'symbol': name, 'address': address, 'size': len(body), 'original_size': len(target), 'exact': True, 'calls': {k: [hex(v) for v in sorted(values)] for k, values in calls.items()}})
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
base_address = pe.OPTIONAL_HEADER.ImageBase
assert pe.get_string_at_rva(0x936908 - base_address + 8) == b'.?AVIModelModifier@RBX@@'
assert pe.get_string_at_rva(0x92907c - base_address + 8) == b'.?AVInstance@RBX@@'
remove, _, _ = match.target('2008-06', '00584fc0')
instructions = {(i.mnemonic, i.op_str) for i in Cs(CS_ARCH_X86, CS_MODE_32).disasm(remove, 0x584fc0)}
assert {('push', '0x936908'), ('push', '0x92907c'), ('lea', 'edi, [esi + 0x1ec]'),
        ('cmp', 'dword ptr [eax], edx'), ('add', 'eax, 4')} <= instructions
receipt = {'scope': 'Inactive ModelInstance constructor/destructor match; vector RTTI and pointer stride corroborated by removeIModelModifier. Full base layout and runtime ownership remain unproven.', 'observer_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(), 'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(), 'header_sha256': hashlib.sha256(header.read_bytes()).hexdigest(), 'object_sha256': hashlib.sha256(raw).hexdigest(), 'methods': rows, 'flags': flags,
           'modifiers': {'offset': '0x1ec', 'element': 'RBX::IModelModifier*', 'remove_address': '00584fc0', 'instance_type_descriptor': '0x92907c', 'modifier_type_descriptor': '0x936908', 'pointer_stride': 4}}
(root / 'work/2008-06/shared-layouts/model-vector-lifetime-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print(rows)
