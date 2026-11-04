"""Check native ServiceProvider lookup implementations."""
import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root))
from roc import match,rebuild
prior=json.loads((root/'work/2008-06/shared-layouts/profiling-integrated.json').read_text())
flags=[x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')]
out=root/'rebuild/2008-06/out/native-layouts/service-lookup-integrated';out.mkdir(parents=True,exist_ok=True)
source=root/'rebuild/2008-06/native-classes/ServiceLookup.cpp';obj=out/'ServiceLookup.obj';flags+=['/Fo'+str(obj),str(source)]
code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,out);(out/'compile.log').write_text(log)
if code:print(log);sys.exit(code)
raw=obj.read_bytes();sections,symbols,definitions,_=match._coff_data_index(raw);rows=[]
for prefix,address,expected in [('?newIndex@ServiceProvider@RBX@@',0x572690,[('__imp__InterlockedIncrement',0x8021b0)]),('?findServiceByClassName@ServiceProvider@RBX@@',0x572a90,[])]:
 name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06','%08x'%address);assert match.exact_match(target,targetrefs,body,refs),(name,len(body),len(target));start,index=definitions[name];table=sections[index];bindings={}
 for i in range(table[7]):
  offset,symbol,kind=struct.unpack_from('<IIH',raw,table[5]+i*10);offset-=start
  if 0<=offset<len(body)-3:
   value=struct.unpack_from('<I',target,offset)[0]
   if kind==20:value=(address+offset+4+struct.unpack_from('<i',target,offset)[0])&0xffffffff
   bindings[symbols[symbol][0]]=hex(value)
 for key,value in expected:assert any(k.startswith(key) and v==hex(value) for k,v in bindings.items()),(key,bindings)
 rows.append({'symbol':name,'address':hex(address),'size':len(body),'bindings':bindings})
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();paths=[source,root/'rebuild/2008-06/native-headers/v8tree/Service.h',root/'rebuild/2008-06/native-headers/v8tree/Instance.h',Path(__file__)]
receipt={'scope':'Native ServiceProvider lookup byte and selected IAT target checks; class layout/ownership and runtime unproven.','sources':{str(p.relative_to(root)):sha(p) for p in paths},'object_sha256':sha(obj),'flags':flags,'methods':rows}
(root/'work/2008-06/shared-layouts/service-lookup-integrated.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS native ServiceProvider lookup methods and InterlockedIncrement target')
