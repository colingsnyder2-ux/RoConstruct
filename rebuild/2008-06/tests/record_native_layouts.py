"""Record original x86 RTTI hierarchies and constructor evidence for shared headers."""
import hashlib
import json
from pathlib import Path
import re
import struct
import subprocess
import sys

import capstone
import pefile

ROOT = Path(__file__).resolve().parents[3]
EXE = ROOT / 'work/2008-06/original-p4-reference/Roblox.exe'
pe = pefile.PE(str(EXE), fast_load=True)
base = pe.OPTIONAL_HEADER.ImageBase
data = pe.get_memory_mapped_image()


def words(address, count):
    return struct.unpack_from('<' + 'I' * count, data, address - base)


def references(address):
    return [base + match.start() for match in re.finditer(re.escape(struct.pack('<I', address)), data)]


def type_name(address):
    start = address - base + 8
    return data[start:data.index(b'\0', start)].decode('ascii')


def hierarchy(address):
    signature, attributes, count, array = words(address, 4)
    assert signature == 0 and 0 < count < 100
    result = []
    for descriptor in words(array, count):
        target, contained, member, vbtable, displacement, flags = words(descriptor, 6)
        signed = lambda value: struct.unpack('<i', struct.pack('<I', value))[0]
        result.append(dict(type=type_name(target), descriptor=hex(descriptor),
                           contained_bases=contained, member_displacement=signed(member),
                           vbtable_displacement=signed(vbtable), virtual_displacement=signed(displacement),
                           attributes=flags))
    return dict(address=hex(address), attributes=attributes, bases=result)


names = list(re.finditer(rb'\.\?AV[^\x00]{1,240}@@\x00', data))
classes = {}
for match in names:
    name = match.group()[:-1].decode('ascii', errors='replace')
    if not (name in ('.?AVCRobloxDoc@@', '.?AVCRobloxView@@', '.?AVCMainFrame@@', '.?AVCRobloxApp@@')
            or 'VerbBinder@VCRoblox' in name
            or re.fullmatch(r'\.\?AV(?:HumanoidState|MovingNoPhysicsBase|RunningNoPhysics|Freefall|Landed|Jumping)@HUMAN@RBX@@', name)):
        continue
    descriptor = base + match.start() - 8
    tables = []
    for reference in references(descriptor):
        locator = reference - 12
        if locator < base:
            continue
        signature, offset, construction, target, tree = words(locator, 5)
        if signature != 0 or target != descriptor or not base <= tree < base + len(data):
            continue
        try:
            bases = hierarchy(tree)
        except (AssertionError, IndexError, struct.error, UnicodeError, ValueError):
            continue
        for pointer in references(locator):
            vtable = pointer + 4
            first = words(vtable, 1)[0]
            section = pe.get_section_by_rva(first - base)
            if section is None or not section.Characteristics & 0x20000000:
                continue
            tables.append(dict(vtable=hex(vtable), locator=hex(locator), subobject_offset=offset,
                               construction_displacement=construction, hierarchy=bases))
    if tables:
        classes[name] = dict(type_descriptor=hex(descriptor), tables=tables)

md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
functions = {}
for address, label, length in (
    (0x451590, 'document intermediate-base constructor', 0x70),
    (0x451ac0, 'CRobloxDoc constructor', 0x90),
    (0x446110, 'document member tree constructor (payload type unresolved)', 0xa0),
    (0x66f070, 'MovingNoPhysicsBase constructor', 0x180),
    (0x66ed50, 'MovingNoPhysicsBase release', 0x140),
):
    raw = pe.get_data(address - base, length)
    instructions = []
    for item in md.disasm(raw, address):
        instructions.append(dict(address=hex(item.address), instruction=item.mnemonic + ' ' + item.op_str))
        if item.mnemonic.startswith('ret'):
            break
    functions[hex(address)] = dict(role=label, window_length=length,
                                  window_sha256=hashlib.sha256(raw).hexdigest(), instructions=instructions)

runtime_path = ROOT / 'rebuild/2008-06/p6/runtime-classes.json'
runtime = json.loads(runtime_path.read_text())
runtime_sizes = {}
for name in ('CRobloxDoc', 'CRobloxView', 'CMainFrame'):
    entry = runtime[name]
    address = int(entry['va'], 16)
    string, size, schema, factory, getter = words(address, 5)
    start = string - base
    assert data[start:data.index(b'\0', start)].decode('ascii') == name
    assert size == entry['size'] and factory == int(entry['create'], 16)
    assert getter == int(entry['baseGetter'], 16)
    runtime_sizes[name] = dict(entry, schema=schema, verified_against_original=True)
receipt = dict(revision=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
               original_sha256=hashlib.sha256(EXE.read_bytes()).hexdigest(),
               observer_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
               runtime_classes_sha256=hashlib.sha256(runtime_path.read_bytes()).hexdigest(),
               runtime_sizes=runtime_sizes,
               classes=classes, functions=functions,
               scope='Original RTTI supplies inheritance and PMD offsets. Runtime metadata supplies complete MFC class sizes. Constructor instructions supply accessed offsets; unresolved member types remain open. Mined codegen analog declarations are not ABI proof.')
for required in ('.?AVCRobloxDoc@@', '.?AVCRobloxView@@', '.?AVCMainFrame@@',
                 '.?AVHumanoidState@HUMAN@RBX@@', '.?AVMovingNoPhysicsBase@HUMAN@RBX@@'):
    assert required in classes, required
output = ROOT / 'work/2008-06' / sys.argv[1]
output.parent.mkdir(parents=True, exist_ok=True)
output.write_text(json.dumps(receipt, indent=2) + '\n')
print('Recorded', len(classes), 'original RTTI classes in', output)
