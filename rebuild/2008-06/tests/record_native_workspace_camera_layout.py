"""Cross-check Workspace camera base against original RTTI, constructor and destructor."""
import hashlib, json, struct, sys
from pathlib import Path
import capstone
import pefile
root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match
exe = root / 'work/2008-06/original-p4-reference/Roblox.exe'
rtti = root / 'work/2008-06/shared-layouts/workspace-selection-rtti.json'
info = json.loads(rtti.read_text())['classes']['.?AVWorkspace@RBX@@']
camera = [b for b in info['tables'][0]['hierarchy']['bases'] if b['type'] == '.?AVICameraOwner@RBX@@']
assert len(camera) == 1 and camera[0]['member_displacement'] == 0x288
vtables = {t['subobject_offset']: int(t['vtable'],16) for t in info['tables']}
assert vtables[0x288] == 0x833998
expected = {offset: vtables[offset] for offset in (0,0x10,0x14,0x20,0x24,0x44,0x64,0x84,0xa4,0xc4,0x130,0x1a0,0x288,0x2e8,0x340,0x344,0x364,0x384)}
md = capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
md.detail = True
rows = []
for address in ('005a4d90','005a28c0'):
    body, _, _ = match.target('2008-06', address)
    writes = {}
    for ins in md.disasm(body, int(address,16)):
        ops = ins.operands
        if ins.mnemonic != 'mov' or len(ops) != 2 or ops[0].type != capstone.x86.X86_OP_MEM or ops[1].type != capstone.x86.X86_OP_IMM: continue
        offset, value = ops[0].mem.disp, ops[1].imm & 0xffffffff
        if ops[0].mem.base == capstone.x86.X86_REG_ESI and expected.get(offset) == value:
            writes[offset] = {'address':hex(ins.address),'vtable':hex(value)}
    assert set(writes) == set(expected), (address, writes)
    rows.append({'address':address,'size':len(body),'sha256':hashlib.sha256(body).hexdigest(),'writes':{hex(k):v for k,v in writes.items()}})
constructor, _, _ = match.target('2008-06', '005a4d90')
destructor, _, _ = match.target('2008-06', '005a28c0')
ctor_ins = {i.address:(i.mnemonic, i.op_str) for i in md.disasm(constructor, 0x5a4d90)}
dtor_ins = {i.address:(i.mnemonic, i.op_str) for i in md.disasm(destructor, 0x5a28c0)}
for address, expected_ins in {
    0x5a4da9: ('xor', 'ebx, ebx'),
    0x5a5009: ('mov', 'dword ptr [esi + 0x3fc], ebx'),
    0x5a500f: ('mov', 'dword ptr [esi + 0x400], ebx'),
    0x5a5015: ('lea', 'eax, [esi + 0x404]'),
    0x5a5021: ('call', '0x45db40'),
}.items():
    assert ctor_ins[address] == expected_ins, (hex(address), ctor_ins.get(address))
for address, expected_ins in {
    0x5a2a8e: ('mov', 'edi, dword ptr [esi + 0x408]'),
    0x5a2aa3: ('lock xadd', 'dword ptr [ecx], edx'),
    0x5a2ab8: ('lock xadd', 'dword ptr [eax], ecx'),
    0x5a2ac7: ('mov', 'edi, dword ptr [esi + 0x400]'),
    0x5a2adc: ('lock xadd', 'dword ptr [ecx], edx'),
    0x5a2af1: ('lock xadd', 'dword ptr [eax], ecx'),
}.items():
    assert dtor_ins[address] == expected_ins, (hex(address), dtor_ins.get(address))
pe = pefile.PE(str(exe))
image = pe.OPTIONAL_HEADER.ImageBase
factory, _, _ = match.target('2008-06', '0045db40')
camera_ctor, _, _ = match.target('2008-06', '005cd9a0')
factory_ins = {i.address:(i.mnemonic, i.op_str) for i in md.disasm(factory, 0x45db40)}
camera_ctor_ins = {i.address:(i.mnemonic, i.op_str) for i in md.disasm(camera_ctor, 0x5cd9a0)}
assert factory_ins[0x45db5f] == ('push', '0x1e8')
assert factory_ins[0x45db84] == ('call', '0x5cd9a0')
assert camera_ctor_ins[0x5cd9c7] == ('lea', 'ebp, [esi + 0x130]')
assert camera_ctor_ins[0x5cd9d5] == ('mov', 'dword ptr [esi], 0x83a654')
read_ptr = lambda address: struct.unpack('<I', pe.get_data(address - image, 4))[0]
camera_locator = read_ptr(0x83a650)
camera_type = read_ptr(camera_locator + 12)
assert pe.get_string_at_rva(camera_type + 8 - image) == b'.?AVCamera@RBX@@'
slot4, slot8 = struct.unpack('<II', pe.get_data(0x83399c - image, 8))
assert (slot4, slot8) == (0x5a05a0, 0x5a0210)
camera_body, _, _ = match.target('2008-06', '005a05a0')
assert camera_body == bytes.fromhex('8b817401000085c075068b817c010000c3')
donor = root / 'rebuild/2008-06/out/native-layouts/workspace-source-probe/WorkspaceWithoutDefault.obj'
donor_raw = donor.read_bytes()
getters = []
for prefix, address, exact in [('?getCamera@Workspace@RBX@@', '005a05a0', False), ('?getGCamera@Workspace@RBX@@', '005a0210', True)]:
    name, body, refs = next(x for x in match.coff_functions(donor_raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', address)
    assert match.exact_match(target, targetrefs, body, refs) == exact
    getters.append({'symbol':name,'address':address,'candidate_size':len(body),'original_size':len(target),'exact':exact})
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'original_sha256':sha(exe),'rtti_receipt_sha256':sha(rtti),'observer_sha256':sha(Path(__file__)),'camera_base':camera[0],'methods':rows,'scope':'Original Workspace RTTI offsets confirmed by both original constructor and destructor vtable stores; full native C++ hierarchy and member lifetime remain unproven.'}
receipt['camera_vtable'] = {'address':'0x833998','slot4':hex(slot4),'slot8':hex(slot8),'slot4_workspace_pointer_offsets':['0x3fc','0x404'],'donor_object_sha256':sha(donor),'getters':getters}
receipt['camera_member_lifetime'] = {'constructor':'005a4d90','null_pair_offsets':['0x3fc','0x400'],'factory_output_offset':'0x404','factory_target':'0x45db40','destructor':'005a28c0','released_control_offsets':['0x408','0x400'],'scope':'Two reference-counted storage pairs supported by construction and destruction; first pointee type and complete Workspace layout remain unproven.'}
receipt['camera_factory'] = {'address':'0045db40','allocation_size':'0x1e8','constructor':'005cd9a0','vtable':'0x83a654','rtti_locator':hex(camera_locator),'type_descriptor':hex(camera_type),'type':'.?AVCamera@RBX@@','gcamera_offset':'0x130'}
(root / 'work/2008-06/shared-layouts/workspace-camera-layout-evidence.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS Workspace RTTI: 18 base offsets including camera +0x288 verified in constructor and destructor')
