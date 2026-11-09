"""Correlate original Part constructor, destructor, lock method and Primitive RTTI."""
import hashlib,json,struct,sys
from pathlib import Path
import capstone,pefile
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root))
from roc import match
exe=root/'work/2008-06/original-p4-reference/Roblox.exe';pe=pefile.PE(str(exe));base=pe.OPTIONAL_HEADER.ImageBase
read=lambda a:struct.unpack('<I',pe.get_data(a-base,4))[0]
def typename(vtable):
    descriptor=read(read(vtable-4)+12)
    return pe.get_string_at_rva(descriptor+8-base).decode('ascii')
assert typename(0x832d4c)=='.?AVPartInstance@RBX@@'
assert typename(0x83f83c)=='.?AVPrimitive@RBX@@'
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32);md.detail=True
rows=[]
for address,calladdr in [('0059d4d0',0x5e8770),('0059b970',0x5e7df0)]:
    body,_,_=match.target('2008-06',address);ins=list(md.disasm(body,int(address,16)))
    assert any(i.mnemonic=='mov' and i.op_str=='dword ptr [esi], 0x832d4c' for i in ins)
    starts=[j for j,i in enumerate(ins) if i.mnemonic=='lea' and i.op_str in ('edi, [esi + 0x228]','ecx, [esi + 0x228]')]
    assert len(starts)==1
    j=starts[0]
    assert any(i.mnemonic=='call' and i.op_str==hex(calladdr) for i in ins[j:j+6])
    rows.append({'address':address,'size':len(body),'sha256':hashlib.sha256(body).hexdigest(),'embedded_primitive_instruction':hex(ins[j].address),'primitive_lifetime_call':hex(calladdr)})
body,_,_=match.target('2008-06','00599530');ins=list(md.disasm(body,0x599530))
assert any(i.mnemonic=='lea' and i.op_str=='edi, [ecx + 0x228]' for i in ins)
assert any(i.mnemonic=='call' and i.op_str=='0x5e7b90' for i in ins)
rows.append({'address':'00599530','size':len(body),'sha256':hashlib.sha256(body).hexdigest(),'primitive_offset':'0x228','first_edge_call':'0x5e7b90'})
primitive_dtor,_,_=match.target('2008-06','005e7df0')
assert any(i.mnemonic=='mov' and i.op_str=='dword ptr [edi], 0x83f83c' for i in md.disasm(primitive_dtor,0x5e7df0))
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
receipt={'original_sha256':sha(exe),'observer_sha256':sha(Path(__file__)),'part_vtable':'0x832d4c','primitive_vtable':'0x83f83c','primitive_offset':'0x228','methods':rows,'scope':'Original binary lifetime/RTTI proof only. Full PartInstance and Primitive declarations, sizes and function call bindings remain to be recovered.'}
(root/'work/2008-06/shared-layouts/part-embedded-primitive-evidence.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS Part constructor, destructor and lock path use embedded Primitive at +0x228')
