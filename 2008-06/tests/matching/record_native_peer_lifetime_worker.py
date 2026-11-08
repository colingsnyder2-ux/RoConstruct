import json,sys,hashlib,struct
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
prior=json.loads((root/'work/2008-06/shared-layouts/profiling-integrated.json').read_text());flags=[x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')];out=root/'rebuild/2008-06/out/native-layouts/peer-lifetime-worker';out.mkdir(parents=True,exist_ok=True);src=root/'rebuild/2008-06/tests/NativePeerLifetimeWorker.cpp';obj=out/'NativePeerLifetimeWorker.obj';flags+=['/I'+str(root/'tools/rbxgs/Client/Network/raknet30/Source'),'/I'+str(root/'tools/rbxgs/Client/Network')];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);(out/'compile.log').write_text(log);assert code==0,log
raw=obj.read_bytes();functions=match.coff_functions(raw);name,body,refs=next(x for x in functions if x[0].startswith('??1Peer@Network@RBX@@'));target,tr,_=match.target('2008-06','004ac830');exact=match.exact_match(target,tr,body,refs);sections,symbols,defs,_=match._coff_data_index(raw);start,index=defs[name];sec=sections[index];bindings={}
if len(body)==len(target):
 for i in range(sec[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,sec[5]+10*i);off-=start
  if 0<=off<len(body)-3:
   value=struct.unpack_from('<I',target,off)[0]
   if kind==20:value=(0x4ac830+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
   bindings[symbols[sym][0]]=hex(value)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();res={'scope':'Donor Peer destructor body using native headers; relocation-masked match only; target bindings and complete hierarchy/runtime need verification.','symbol':name,'target':'0x4ac830','exact':exact,'size':len(body),'target_size':len(target),'bindings':bindings,'source_sha256':sha(src),'object_sha256':sha(obj),'recorder_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/peer-lifetime-worker.json').write_text(json.dumps(res,indent=2)+'\n');print(json.dumps(res,indent=2))
