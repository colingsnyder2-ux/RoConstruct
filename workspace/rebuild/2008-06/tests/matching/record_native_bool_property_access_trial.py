import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];rows=[]
for stem,prefix,address,extra in [('Predicate','?testBooleanProperty@',0x57f810,[]),('Setter','??RSetBooleanProperty@',0x57f960,[('??$setValue@_N@Property@',0x4ad1e0)])]:
 src=root/('rebuild/2008-06/experiments/trials/NativeBoolProperty'+stem+'Trial.cpp');obj=out/('NativeBoolProperty'+stem+'Trial.obj');code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log
 raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06','%08x'%address);assert match.exact_match(target,targetrefs,body,refs);start,index=defs[name];table=sections[index];bindings={}
 for i in range(table[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
  if 0<=off<len(body)-3:
   value=struct.unpack_from('<I',target,off)[0]
   if kind==20:value=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
   bindings[symbols[sym][0]]=value
 expected=[('?findDescriptor@',0x61ba10),('??_R0?AV?$TypedPropertyDescriptor@_N@',0x929578),('??_R0?AVPropertyDescriptor@',0x9295b4),('___RTDynamicCast',0x6a17c6),('??DIterator@',0x4174b0),('??$getValue@_N@',0x4ad000)]+extra
 for key,value in expected:assert any(k.startswith(key) and v==value for k,v in bindings.items()),(key,bindings)
 sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();rows.append({'address':hex(address),'size':len(body),'symbol':name,'bindings':{k:hex(v) for k,v in bindings.items()},'source_sha256':sha(src),'object_sha256':sha(obj)})
receipt={'scope':'Inactive boolean property predicate and setter match bytes, targets and RTTI; reflection layout, ownership and runtime unproven.','methods':rows,'observer_sha256':sha(Path(__file__)),'member_header_sha256':sha(root/'rebuild/2008-06/native-headers/reflection/member.h')};(root/'work/2008-06/shared-layouts/bool-property-access-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS property predicate and setter bytes and target bindings')
