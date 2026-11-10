"""Record original parent-property descriptor virtual-slot incompatibility."""
import hashlib,json,struct,sys
from pathlib import Path
import pefile
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root))
from roc import match
exe=root/'work/2008-06/original-p4-reference/Roblox.exe';pe=pefile.PE(str(exe));base=pe.OPTIONAL_HEADER.ImageBase
u=lambda addr:struct.unpack('<I',pe.get_data(addr-base,4))[0]
vtable=0x82d768;locator=u(vtable-4);typedesc=u(locator+12);rtti=pe.get_string_at_rva(typedesc+8-base).decode();assert rtti=='.?AV?$RefPropDescriptor@VInstance@RBX@@V12@@Reflection@RBX@@'
slots=[u(vtable+4*i) for i in range(10)];assert slots[5]==0x5da5b0
code,_,_=match.target('2008-06','005872a0');instructions=list(Cs(CS_ARCH_X86,CS_MODE_32).disasm(code,0x5872a0));assert any(i.mnemonic=='mov' and i.op_str=='eax, dword ptr [esi + 0x14]' for i in instructions)
setter,_,_=match.target('2008-06','005da5b0');assert any(i.mnemonic=='call' and i.op_str=='0x4917f0' for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(setter,0x5da5b0))
header=root/'tools/rbxgs/Client/App/include/reflection/property.h';source=header.read_text();assert 'virtual bool setStringValue(DescribedBase*, const std::string&) const = 0;' in source
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'original_sha256':sha(exe),'observer_sha256':sha(Path(__file__)),'donor_header_sha256':sha(header),'parent_property_address':'0x973d34','constructor':'0x559920','vtable':hex(vtable),'rtti':rtti,'slots':[hex(x) for x in slots],'history_apply_property':'0x5872a0','original_slot5_setter':'0x5da5b0','slot5_calls_value_getter':'0x4917f0','donor_slot5':'setStringValue(DescribedBase*, const std::string&)','scope':'Original slot 5 handles Reflection::Value, donor slot 5 accepts std::string. Do not call donor virtual interface for native history restoration until full descriptor ABI is reconciled.'}
(root/'work/2008-06/shared-layouts/history-property-abi-conflict.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS original property setter slot; donor ABI conflict confirmed')
