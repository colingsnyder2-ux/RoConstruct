"""Verify original Debugable::dump body and runtime targets."""
import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
proof=root/'work/2008-06/shared-layouts';prior=json.loads((proof/'runservice-fresh-current.json').read_text());out=root/'rebuild/2008-06/out/native-layouts/debugable-dump-integrated';out.mkdir(parents=True,exist_ok=True);src=root/'rebuild/2008-06/native-classes/DebugableDump.cpp';obj=out/'DebugableDump.obj';flags=[x for x in prior['flags'] if not x.startswith('/Fo') and not x.endswith('RunService.cpp')]+['/Fo'+str(obj),str(src)];c,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,out);assert c==0,log;raw=obj.read_bytes();name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?dump@Debugable@RBX@@'));target,tr,_=match.target('2008-06','0056a560');assert match.exact_match(target,tr,body,refs),(len(body),len(target));secs,sy,defs,_=match._coff_data_index(raw);start,idx=defs[name];tab=secs[idx];bindings={}
for i in range(tab[7]):
 off,si,kind=struct.unpack_from('<IIH',raw,tab[5]+i*10);off-=start
 if 0<=off<len(body)-3:
  value=struct.unpack_from('<I',target,off)[0]
  if kind==20:value=(0x56a560+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
  bindings[sy[si][0]]=hex(value)
assert {'0x6a1de2','0x97dce8','0x802654','0x44a450'} <= set(bindings.values()),bindings
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();paths=[src,root/'tools/rbxgs/Client/App/include/util/Debug.h',Path(__file__)];result={'scope':'Inactive native Debugable dump; body and selected targets match, RTTI/data identity and runtime unproven.','address':'0x56a560','symbol':name,'size':len(body),'bindings':bindings,'sources':{str(p.relative_to(root)):sha(p) for p in paths},'object_sha256':sha(obj),'flags':flags};(proof/'debugable-dump-integrated.json').write_text(json.dumps(result,indent=2)+'\n');print('PASS native Debugable dump and original targets')
