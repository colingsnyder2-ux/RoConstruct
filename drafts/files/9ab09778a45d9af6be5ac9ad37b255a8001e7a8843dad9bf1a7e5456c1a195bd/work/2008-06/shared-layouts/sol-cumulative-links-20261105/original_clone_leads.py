"""Read verified original clone/creator leads; do not compile or infer runtime closure."""
import hashlib
import json
from pathlib import Path
import struct
import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

ROOT = Path(__file__).resolve().parents[4]
HERE = Path(__file__).resolve().parent
original = ROOT / 'clients/2008-06/Roblox.exe'
sha = lambda raw: hashlib.sha256(raw).hexdigest()
assert sha(original.read_bytes()) == '2fbbfdf8577b5b28ea198c14747613ba8fd83d094363b2b23fe2f9e587343764'
pe = pefile.PE(str(original))
base = pe.OPTIONAL_HEADER.ImageBase
read = lambda address, size: pe.get_data(address - base, size)
ptr = lambda address: struct.unpack('<I', read(address, 4))[0]


def table(address, slots):
    col = ptr(address - 4)
    assert ptr(col) == 0
    descriptor = ptr(col + 12)
    name = read(descriptor + 8, 200).split(b'\0')[0].decode('ascii')
    return {'vtable': hex(address), 'col': hex(col), 'offset': ptr(col + 4),
            'type_descriptor': hex(descriptor), 'rtti_name': name,
            'slots': [hex(ptr(address + 4 * index)) for index in range(slots)]}


clone, creator, axis = table(0x0084a4dc, 2), table(0x0080f1c4, 1), table(0x0084a5ac, 16)
assert clone['rtti_name'] == '.?AVCloneTool@RBX@@' and clone['slots'][1] == '0x63ff50'
assert 'Creator@?$FactoryProduct@VPartInstance@RBX@@' in creator['rtti_name']
assert creator['slots'] == ['0x41ea40']
assert axis['rtti_name'] == '.?AVAxisMoveTool@RBX@@' and '0x640800' in axis['slots']
wanted = {'0041e9c0', '0041ea40', '00559350', '0063ff50', '00640800'}
functions = {}
for line in (ROOT / 'work/2008-06/functions.jsonl').open():
    row = json.loads(line)
    if row['addr'] not in wanted:
        continue
    address = int(row['addr'], 16)
    body = read(address, row['size'])
    instructions = list(Cs(CS_ARCH_X86, CS_MODE_32).disasm(body, address))
    functions[row['addr']] = {'size': len(body), 'raw_sha256': sha(body),
        'indexed_callers': row.get('callers'),
        'calls': [{'address': hex(i.address), 'operands': i.op_str}
                  for i in instructions if i.mnemonic == 'call'],
        'instructions': [{'address': hex(i.address), 'mnemonic': i.mnemonic, 'operands': i.op_str}
                         for i in instructions]}
assert any(i['address'] == '0x63ff86' and i['operands'] == '0x559350'
           for i in functions['0063ff50']['calls'])
assert any(i['address'] == '0x41ea65' and i['operands'] == '0x41e9c0'
           for i in functions['0041ea40']['calls'])
report = {'original_sha256': sha(original.read_bytes()),
          'clone_table': clone, 'part_creator_table': creator, 'axis_table': axis,
          'axis_move_slot': axis['slots'].index('0x640800'), 'original_functions': functions,
          'clone_name_provenance': 'Packaged record_native_clone_down_trial.py maps the CloneTool call to Instance::clone; primary RTTI/vtable and call bytes above corroborate its entrypoint. No candidate was compiled here.',
          'scope': 'Original static entrypoint leads only. Registry/clone producer coverage and runtime/selected-PE ownership remain unproven.'}
(HERE / 'original-clone-leads.json').write_text(json.dumps(report, indent=2) + '\n')
print(json.dumps({'clone_call': '0063ff86 -> 00559350', 'creator': '0080f1c4 -> 0041ea40',
                  'axis_move': '00640800', 'slot': report['axis_move_slot']}))
