import json,sys,re,hashlib
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import libs,rebuild
spec=json.loads((root/'rebuild/2008-06/modules/p4-sound-asset.json').read_text());layer=spec['layers'][0];out=root/'rebuild/2008-06/out/native-layouts/sound-header-worker';out.mkdir(parents=True,exist_ok=True)
inc=[root/'rebuild/2008-06/native-headers',root/'rebuild/2008-06/out/P4SoundAsset/overlay/App/include']+[(libs.LIBS/i).resolve() for i in libs.RECIPES['rbxgs']['include'] if i!='WINSDK']+[root/p for p in layer['extra_includes']];defs=(libs.RECIPES['rbxgs']['defines']+' '+layer['extra_defines']).split();tc=rebuild.toolchain(21022);results={}
for file in layer['files'].split():
 src=root/layer['dir']/file;obj=out/(src.stem+'.obj');args=['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj)]+['/I'+str(p) for p in inc]+['/D'+d for d in defs]+[str(src)];code,log=rebuild.run(tc,'cl',args,out);(out/(src.stem+'.log')).write_text(log,encoding='utf8');errors=[x.strip() for x in log.splitlines() if re.search(r'error C\d+',x)];results[file]={'exit':code,'errors':errors,'source_sha256':hashlib.sha256(src.read_bytes()).hexdigest()};print(file,code,len(errors),flush=True)
receipt={'scope':'Native-header-first isolated compile; no shared header, player, or verifier changes; output objects are diagnostic only.','include_order':[str(p) for p in inc],'results':results};(root/'work/2008-06/shared-layouts/sound-header-worker.json').write_text(json.dumps(receipt,indent=2)+'\n')
