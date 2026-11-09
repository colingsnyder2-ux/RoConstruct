"""Verify native RunService class-name provider and original targets."""
import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
proof=root/'work/2008-06/shared-layouts';prior=json.loads((proof/'runservice-fresh-current.json').read_text());out=root/'rebuild/2008-06/out/native-layouts/runservice-classname-integrated';out.mkdir(parents=True,exist_ok=True);src=root/'rebuild/2008-06/native-classes/RunServiceClassName.cpp';obj=out/'RunServiceClassName.obj';flags=[x for x in prior['flags'] if not x.startswith('/Fo') and not x.endswith('RunService.cpp')]+['/Fo'+str(obj),str(src)];c,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,out);assert c==0,log;raw=obj.read_bytes();name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?getClassName@?$FactoryProduct@VRunService'));target,tr,_=match.target('2008-06','00555020');assert match.exact_match(target,tr,body,refs);secs,sy,defs,_=match._coff_data_index(raw);start,idx=defs[name];tab=secs[idx];bindings={}
for i in range(tab[7]):
 offset,si,kind=struct.unpack_from('<IIH',raw,tab[5]+i*10);offset-=start
 if 0<=offset<len(body)-3:
  value=struct.unpack_from('<I',target,offset)[0]
  if kind==20:value=(0x555020+offset+4+struct.unpack_from('<i',target,offset)[0])&0xffffffff
  bindings[sy[si][0]]=hex(value)
for prefix,address in [('?flag@?1???$declare@',0x96c2b0),('??$callDoDeclare@',0x4029f0),('?call_once@boost@@',0x557330),('??$doDeclare@',0x401a00)]:assert any(k.startswith(prefix) and v==hex(address) for k,v in bindings.items()),(prefix,bindings)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();paths=[src,root/'rebuild/2008-06/native-headers/util/RunStateOwner.h',root/'rebuild/2008-06/native-headers/util/Name.h',Path(__file__)];result={'scope':'Inactive native class-name method and selected targets; data ownership, full ABI and runtime unproven.','address':'0x555020','symbol':name,'size':len(body),'bindings':bindings,'sources':{str(p.relative_to(root)):sha(p) for p in paths},'object_sha256':sha(obj),'flags':flags};(proof/'runservice-classname-integrated.json').write_text(json.dumps(result,indent=2)+'\n');print('PASS RunService class-name method and original targets')
