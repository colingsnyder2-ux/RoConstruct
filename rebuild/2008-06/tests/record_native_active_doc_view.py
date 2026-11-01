"""Verify inactive ActiveDocView lifetime and registry tree code."""
import hashlib,json,struct,subprocess,sys
from pathlib import Path
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
import pefile
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT))
from roc import match,rebuild
out=ROOT/'rebuild/2008-06/out/native-layouts';src=ROOT/'rebuild/2008-06/native-classes/ActiveDocView.cpp';header=ROOT/'rebuild/2008-06/native-headers/ActiveDocView.h';base=json.loads((ROOT/'work/2008-06/shared-layouts/document-compile.json').read_text(encoding='utf8'));flags=base['flags'][:-2]+['/FoNativeActiveDocView.obj',str(src)]
code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,out);assert code==0,log
obj=(out/'NativeActiveDocView.obj').read_bytes();functions=match.coff_functions(obj);rows=[]
for address,prefix in (('00405d50','??0ActiveDocView@@'),('00405d80','??1ActiveDocView@@'),('005e8c40','?insert@?$_Tree@'),('005e9f60','?erase@?$_Tree@')):
 target,tr,_=match.target('2008-06',address);name,body,refs=next((n,b,r) for n,b,r in functions if n.startswith(prefix) and match.exact_match(target,tr,b,r));assert match.exact_match(target,tr,body,refs),name;rows.append(dict(address=address,symbol=name,size=len(body)))
sec,symbols,defs,_=match._coff_data_index(obj)
for row,offset,symbol,target_va in ((rows[0],0x20,'?insert@?$_Tree@',0x5e8c40),(rows[1],0x14,'?erase@?$_Tree@',0x5e9f60)):
 start,section=defs[row['symbol']];table=sec[section];rel={}
 for i in range(table[7]):
  off,si,kind=struct.unpack_from('<IIH',obj,table[5]+i*10)
  if start<=off<start+row['size']:rel[off-start]=symbols[si][0]
 target,_,_=match.target('2008-06',row['address']);addr=int(row['address'],16);calls={i.address-addr+1:int(i.op_str,16) for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(target,addr) if i.mnemonic=='call' and i.op_str.startswith('0x')}
 assert rel[offset].startswith(symbol) and calls[offset]==target_va
pe=pefile.PE(str(ROOT/'work/2008-06/original-p4-reference/Roblox.exe'));base_va=pe.OPTIONAL_HEADER.ImageBase
u32=lambda va:struct.unpack('<I',pe.get_data(va-base_va,4))[0]
col=u32(0x80b2dc);td=u32(col+12);assert pe.get_string_at_rva(td+8-base_va)==b'.?AVActiveDocView@@' and u32(0x80b2e0)==0x6a16be
callback,_,_=match.target('2008-06','00442900');assert callback.endswith(bytes.fromhex('c21000'))
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();paths=[src,header,Path(__file__).resolve()]
receipt=dict(revision=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),sources={str(p.relative_to(ROOT)):sha(p) for p in paths},flags=flags,methods=rows,registry_original_va='0x96c23c',scope='Four relocation-masked body matches, selected registry calls and ActiveDocView pure vtable verified; 16-byte callback arguments observed. Callback pointee types, global registry initialization, other relocations, exception tables and runtime integration unverified.')
(ROOT/'work/2008-06/shared-layouts/active-doc-view-working-probe.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf8')
print('PASS: ActiveDocView constructor/destructor and registry insert/erase')
