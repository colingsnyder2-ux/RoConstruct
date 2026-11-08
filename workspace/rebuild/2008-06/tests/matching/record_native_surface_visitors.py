"""Verify native recursive surface visitors and original call targets."""
import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';source=root/'rebuild/2008-06/experiments/trials/NativeSurfaceVisitorsTrial.cpp';obj=out/'NativeSurfaceVisitorsTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(source)],out);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);rows=[]
for prefix,address in [('?weldInstance@RBX@@',0x57eb80),('?snapInstance@RBX@@',0x57e530)]:
 name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06',f'{address:08x}');assert match.exact_match(target,targetrefs,body,refs)
 start,index=defs[name];section=sections[index];edges={}
 for i in range(section[7]):
  offset,symbol,kind=struct.unpack_from('<IIH',raw,section[5]+i*10);offset-=start
  if not 0<=offset<len(body)-3:continue
  value=struct.unpack_from('<I',target,offset)[0]
  if kind==20:value=(address+offset+4+struct.unpack_from('<i',target,offset)[0])&0xffffffff
  edges[symbols[symbol][0]]=value
 for token,want in [('RTDynamicCast',0x6a17c6),('getSurfaces@PartInstance',0x598de0),('??ASurfaces',0x5ecc00),('getSurfaceType@Surface',0x5f1290),('setSurfaceType@Surface',0x5f13e0),('for_each',0x57e4d0)]:assert any(token in k and v==want for k,v in edges.items()),(token,edges)
 rows.append({'address':hex(address),'size':len(body),'bindings':edges})
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
(root/'work/2008-06/shared-layouts/surface-visitors-trial.json').write_text(json.dumps({'methods':rows,'source_sha256':sha(source),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__)),'scope':'Inactive trial; PartInstance, Surface, recursive ownership and runtime unproven.'},indent=2)+'\n')
print('PASS native weld/snap visitors and surface call targets')
