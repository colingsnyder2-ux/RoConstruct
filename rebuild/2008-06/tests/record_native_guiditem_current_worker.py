import json,sys,struct,hashlib
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
prior=json.loads((root/'work/2008-06/shared-layouts/guid-item-working-probe.json').read_text());flags=[x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')];out=root/'rebuild/2008-06/out/native-layouts/guiditem-current-worker';out.mkdir(parents=True,exist_ok=True);src=root/'rebuild/2008-06/native-classes/GuidItem.cpp';obj=out/'GuidItem.obj';code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);(out/'compile.log').write_text(log);assert code==0,log
raw=obj.read_bytes();n,b,r=next(x for x in match.coff_functions(raw) if x[0].startswith('??1?$GuidItem@VInstance@RBX@@'));t,tr,_=match.target('2008-06','004b3760');exact=match.exact_match(t,tr,b,r);ss,sy,defs,_=match._coff_data_index(raw);start,index=defs[n];sec=ss[index];bind={}
if len(b)==len(t):
 for i in range(sec[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,sec[5]+10*i);off-=start
  if 0<=off<len(b)-3:
   value=struct.unpack_from('<I',t,off)[0]
   if kind==20:value=(0x4b3760+off+4+struct.unpack_from('<i',t,off)[0])&0xffffffff
   bind[sy[sym][0]]=hex(value)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();result={'scope':'Current native-header-first compile, relocation-masked byte comparison and selected original binding mapping. Registry names/type ownership still provisional, full ABI and runtime not proven.','symbol':n,'address':'0x4b3760','size':len(b),'original_size':len(t),'exact':exact,'bindings':bind,'source_sha256':sha(src),'object_sha256':sha(obj),'guid_registry_header_sha256':sha(root/'rebuild/2008-06/native-headers/util/GuidRegistry.h')};(root/'work/2008-06/shared-layouts/guiditem-current-worker.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result,indent=2))
