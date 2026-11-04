"""Verify native null Name provider and original singleton references."""
import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
proof=root/'work/2008-06/shared-layouts';prior=json.loads((proof/'runservice-fresh-current.json').read_text());out=root/'rebuild/2008-06/out/native-layouts/name-null-integrated';out.mkdir(parents=True,exist_ok=True);src=root/'rebuild/2008-06/native-classes/NameNull.cpp';obj=out/'NameNull.obj';flags=[x for x in prior['flags'] if not x.startswith('/Fo') and not x.endswith('RunService.cpp')]+['/Fo'+str(obj),str(src)];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,out);assert code==0,log;raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);rows=[]
for prefix,address,expected in [('?getNullName@Name@RBX@@',0x554270,{'0x973a2c','0x554160','0x557330','0x9739d0'}),('?initNullName@@',0x554160,{'0x80b716','0x553f90','0x9739d0'})]:
 name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));target,tr,_=match.target('2008-06','%08x'%address);assert match.exact_match(target,tr,body,refs),(name,len(body),len(target));start,idx=defs[name];tab=sections[idx];bindings={}
 for i in range(tab[7]):
  off,si,kind=struct.unpack_from('<IIH',raw,tab[5]+10*i);off-=start
  if 0<=off<len(body)-3:
   value=struct.unpack_from('<I',target,off)[0]
   if kind==20:value=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
   bindings[symbols[si][0]]=hex(value)
 assert expected <= set(bindings.values()),bindings;rows.append({'address':hex(address),'symbol':name,'size':len(body),'bindings':bindings})
assert all(row['bindings'].get('_nullName') == '0x9739d0' for row in rows), rows
assert any(k.startswith('?initNullName@@') and v == '0x554160' for k,v in rows[0]['bindings'].items())
assert any(k.startswith('?declare@Name@RBX@@') and v == '0x553f90' for k,v in rows[1]['bindings'].items())
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();paths=[src,root/'rebuild/2008-06/native-headers/util/Name.h',root/'rebuild/2008-06/native-classes/accepted/App/util/Name.cpp',Path(__file__)];result={'scope':'Inactive original Name null initialization source; code and original targets match, singleton storage unification, full ABI and runtime unproven.','methods':rows,'sources':{str(p.relative_to(root)):sha(p) for p in paths},'object_sha256':sha(obj),'flags':flags};(proof/'name-null-integrated.json').write_text(json.dumps(result,indent=2)+'\n');print('PASS native Name null provider and initializer')
