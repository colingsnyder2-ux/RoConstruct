"""Record inactive color-dialog codegen evidence; no executable selection changes."""
import hashlib
import json
import subprocess
import sys
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
BASE = ROOT / 'rebuild/2008-06'
source = BASE / 'native-classes/CMainFramePropertyGrid.cpp'
header = BASE / 'native-headers/mainframe-getter/v8datamodel/ToolsPart.h'
obj = BASE / 'out/native-layouts/CheckCMainFramePropertyGrid.obj'
commands = [
    [sys.executable, str(BASE / 'tests/check_native_class.py'),
     'native-classes/CMainFramePropertyGrid.cpp', '00431160=?handle_431160'],
    [sys.executable, str(BASE / 'tests/call_targets_native.py'), str(obj),
     '00431160', '?handle_431160'],
]
results = []
for command in commands:
    run = subprocess.run(command, cwd=ROOT, capture_output=True, text=True)
    print(run.stdout, end='')
    results.append(dict(command=command, exit=run.returncode,
                        stdout=run.stdout, stderr=run.stderr))
    if run.returncode:
        break
passed = len(results) == 2 and all(r['exit'] == 0 for r in results) and '1/1 exact' in results[0]['stdout']
sys.path.insert(0, str(ROOT))
from roc import match
from capstone import Cs, CS_ARCH_X86, CS_MODE_32
expected = [
    (0x5b6270, '?color3@BrickColor@RBX@@'),
    (0x5106a0, '??0Color3uint8@G3D@@'),
    (0x7065f0, '??0CXTColorDialog@@'),
    (None, '?DoModal@CPropertySheet@@'),
    (0x5b62a0, '?closest@BrickColor@RBX@@'),
    (0x430e10, '?raise@?$Notifier@VFillToolColor@RBX@@'),
    (0x706740, '??1CXTColorDialog@@'),
]
verified_calls = []
if passed:
    data = obj.read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(data)
    symbol = next(n for n in definitions if n.startswith('?handle_431160@'))
    start, section = definitions[symbol]
    table = sections[section]
    refs = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', data, table[5] + 10 * i)
        refs[offset - start] = symbols[index][0]
    target, _, _ = match.target('2008-06', '00431160')
    calls = [i for i in Cs(CS_ARCH_X86, CS_MODE_32).disasm(target, 0x431160)
             if i.mnemonic == 'call']
    assert len(calls) == len(expected)
    for instruction, (address, prefix) in zip(calls, expected):
        displacement = instruction.address - 0x431160 + (1 if instruction.bytes[0] == 0xe8 else 2)
        assert refs[displacement].startswith(prefix), (instruction, refs.get(displacement))
        if address:
            assert int(instruction.op_str, 16) == address
        verified_calls.append(dict(offset=displacement, symbol=refs[displacement], target=address))
receipt = dict(address='00431160', inactive_exact=passed,
               runtime_proven=False, executable_selected=False,
               limitation='Scoped inline by-value setter is a codegen analog; shared-header ABI remains unproven.',
               verified_calls=verified_calls,
               hashes={str(p.relative_to(ROOT)): hashlib.sha256(p.read_bytes()).hexdigest()
                       for p in (source, header, obj, Path(__file__)) if p.exists()}, results=results)
destination = ROOT / 'work/2008-06/shared-layouts/mainframe-property-grid.json'
destination.parent.mkdir(parents=True, exist_ok=True)
destination.write_text(json.dumps(receipt, indent=2) + '\n', encoding='utf-8')
sys.exit(0 if passed else 1)
