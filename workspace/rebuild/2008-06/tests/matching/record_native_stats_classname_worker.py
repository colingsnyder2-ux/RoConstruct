import sys,json,hashlib,struct
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import rebuild,match
prior=json.loads((root/'work/2008-06/shared-layouts/profiling-integrated.json').read_text());flags=[x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')]+['/I'+str(root/'tools/openrbx/3rdparty/fmod/api/inc')];out=root/'rebuild/2008-06/out/native-layouts/stats-classname-worker';out.mkdir(parents=True,exist_ok=True);src=root/'rebuild/2008-06/tests/NativeStatsClassNameWorker.cpp';obj=out/'NativeStatsClassNameWorker.obj';code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log
raw=obj.read_bytes();fs=match.coff_functions(raw);rows=[]
for n,b,r in fs:
 if '?getClassName@?$NonFactoryProduct@VInstance' not in n:continue
 t,tr,_=match.target('2008-06','0045c660');rows.append({'symbol':n,'address':'0x45c660','size':len(b),'target_size':len(t),'exact':match.exact_match(t,tr,b,r),'candidate_relocations':r,'target_relocations':tr})
for prefix, address in [('??$doDeclare@$1?sStatsItem',0x45b1d0),('??$callDoDeclare@$1?sStatsItem',0x45b6e0)]:
 n,b,r=next(x for x in fs if x[0].startswith(prefix)); t,tr,_=match.target('2008-06',f'{address:08x}'); rows.append({'symbol':n,'address':hex(address),'size':len(b),'target_size':len(t),'exact':match.exact_match(t,tr,b,r)})
assert all(x['exact'] for x in rows)
sections,symbols,defs,_=match._coff_data_index(raw);n=rows[0]['symbol'];start,idx=defs[n];sec=sections[idx];target,_,_=match.target('2008-06','0045c660');bindings={}
for i in range(sec[7]):
 off,sym,kind=struct.unpack_from('<IIH',raw,sec[5]+10*i);off-=start
 if 0<=off<len(target)-3:
  value=struct.unpack_from('<I',target,off)[0]
  if kind==20:value=(0x45c660+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
  bindings[symbols[sym][0]]=hex(value)
assert sorted(bindings.values())==sorted(['0x96de8c','0x45b6e0','0x557330','0x45b1d0'])
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();result={'scope':'Original Stats::Item RTTI primary factory subobject vtable 0x819fb8 at +0x10 slot 1 -> 0x45c660; exact comparison masks relocation targets; getClassName relocation targets checked; helpers exact with relocations masked. No runtime.','methods':rows,'getClassName_bindings':bindings,'source_sha256':sha(src),'object_sha256':sha(obj),'recorder_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/stats-classname-worker.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result,indent=2))
