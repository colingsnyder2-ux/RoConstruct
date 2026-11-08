import json,sys,hashlib,re
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import libs,rebuild,match
spec=json.loads((root/'rebuild/2008-06/modules/p4-sound-asset.json').read_text());layer=spec['layers'][0];out=root/'rebuild/2008-06/out/native-layouts/sound-property-overlay-worker';out.mkdir(parents=True,exist_ok=True);trial=out/'overlay';(trial/'reflection').mkdir(parents=True,exist_ok=True);(trial/'reflection/property.h').write_bytes((root/'rebuild/2008-06/out/property-abi-trial/reflection/property.h').read_bytes());reflection=(root/'rebuild/2008-06/native-headers/reflection/reflection.h').read_text();start=reflection.index('class BoundPropGetSet');pos=reflection.index('virtual PropType getValue',start);reflection=reflection[:pos]+'virtual bool isWriteOnly() const { return false; }\n\t\t\t\t'+reflection[pos:]
for cls,answer in [('class GetImpl : public GetSet','false'),('class SetImpl : public GetSet','true'),('class GetSetImpl : public GetSet','false')]:
 start=reflection.index(cls);pos=reflection.index('virtual ReturnType getValue',start);reflection=reflection[:pos]+'virtual bool isWriteOnly() const { return '+answer+'; }\n\t\t\t\t'+reflection[pos:]
(trial/'reflection/reflection.h').write_text(reflection);inc=[trial,root/'rebuild/2008-06/native-headers',root/'rebuild/2008-06/out/P4SoundAsset/overlay/App/include']+[(libs.LIBS/i).resolve() for i in libs.RECIPES['rbxgs']['include'] if i!='WINSDK']+[root/p for p in layer['extra_includes']];defs=(libs.RECIPES['rbxgs']['defines']+' '+layer['extra_defines']).split();tc=rebuild.toolchain(21022);results={};files=[root/layer['dir']/f for f in layer['files'].split()]+[root/'rebuild/2008-06/native-classes/InstanceReadProperty.cpp']
for src in files:
 obj=out/(src.stem+'.obj');args=['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj)]+['/I'+str(p) for p in inc]+['/D'+d for d in defs]+[str(src)];code,log=rebuild.run(tc,'cl',args,out);(out/(src.stem+'.log')).write_text(log);errors=[x.strip() for x in log.splitlines() if re.search(r'error C\d+',x)];row={'exit':code,'errors':errors,'source_sha256':hashlib.sha256(src.read_bytes()).hexdigest()}
 if code==0:
  raw=obj.read_bytes();row['object_sha256']=hashlib.sha256(raw).hexdigest()
  if src.stem=='InstanceReadProperty':
   n,b,r=next(x for x in match.coff_functions(raw) if x[0].startswith('?readProperty@Instance@'));t,tr,_=match.target('2008-06','00559170');row.update(size=len(b),target_size=len(t),exact=match.exact_match(t,tr,b,r))
 results[src.name]=row;print(src.name,code,len(errors),row.get('exact',''),flush=True)
res={'scope':'Trial property overlay plus provisional BoundPropGetSet::isWriteOnly(false), before native headers. Compile/exact evidence only; derived vtable slots and ABI unproven; NEVER RUN.','overlay_sha256':{str(p.relative_to(root)):hashlib.sha256(p.read_bytes()).hexdigest() for p in (trial/'reflection').glob('*.h')},'results':results};(root/'work/2008-06/shared-layouts/sound-property-overlay-worker.json').write_text(json.dumps(res,indent=2)+'\n')

