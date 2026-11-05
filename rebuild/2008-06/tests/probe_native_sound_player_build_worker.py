import json,sys,re,hashlib,shutil
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import libs,rebuild
out=root/'rebuild/2008-06/out/native-layouts/sound-player-build-worker';out.mkdir(parents=True,exist_ok=True);spec=json.loads((root/'rebuild/2008-06/modules/p4-sound-asset.json').read_text());layer=spec['layers'][0];inc=[root/'rebuild/2008-06/native-headers',root/'rebuild/2008-06/out/P4SoundAsset/overlay/App/include']+[(libs.LIBS/i).resolve() for i in libs.RECIPES['rbxgs']['include'] if i!='WINSDK']+[root/p for p in layer['extra_includes']];defs=(libs.RECIPES['rbxgs']['defines']+' '+layer['extra_defines']).split();tc=rebuild.toolchain(21022);objects={}
for file in layer['files'].split():
 src=root/layer['dir']/file;obj=out/(src.stem+'.obj');args=['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj)]+['/I'+str(p) for p in inc]+['/D'+d for d in defs]+[str(src)];code,log=rebuild.run(tc,'cl',args,out);assert code==0,log;objects[src.stem]=obj
base=json.loads((root/'work/2008-06/shared-layouts/sound-native-link-frozen-worker.json').read_text());instance=json.loads((root/'work/2008-06/shared-layouts/sound-native-instance-worker.json').read_text());cn=root/'rebuild/2008-06/out/native-layouts/sound-classnames-worker/NativeSoundClassNamesWorker.obj';sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();assert sha(cn)==json.loads((root/'work/2008-06/shared-layouts/sound-classnames-worker.json').read_text())['object_sha256'];args=[];snap={}
for arg in base['flags']:
 p=Path(arg)
 if arg.startswith('/OUT:'):arg='/OUT:probe.exe'
 elif arg.startswith('/MAP:'):arg='/MAP:probe.map'
 elif p.is_file() and p.suffix.lower() in ('.obj','.lib'):
  stem=re.sub(r'^\d+_','',p.stem);inp=objects.get(stem,p);dst=out/('frozen_%03d_'%len(snap)+inp.name);shutil.copy2(inp,dst);snap[str(inp)]=sha(dst);arg=str(dst)
 args.append(arg)
for i,(name,digest) in enumerate(instance['objects'].items()):
 p=Path(name);assert sha(p)==digest;dst=out/('provider_%02d_'%i+p.name);shutil.copy2(p,dst);snap[str(p)]=sha(dst);args.append(str(dst))
dst=out/'verified-classnames.obj';shutil.copy2(cn,dst);args.append(str(dst));code,log=rebuild.run(tc,'link',args,out);(out/'link.log').write_text(log,encoding='utf8');errors=[x.strip() for x in log.splitlines() if re.search(r'\berror LNK(?:2001|2019|2005)',x)];result={'scope':'Isolated 7 native-header-first P4 sound units linked with frozen donor-ABI test/libraries plus previously byte-matched Instance providers and verified class-name arrays. Mixed ABI, NONRUNNABLE; not player or P4 gate.','compile_units':list(objects),'link_exit':code,'error_lines':len(errors),'errors':errors,'snapshots':snap,'class_name_sha256':sha(dst),'recorder_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/sound-player-build-worker.json').write_text(json.dumps(result,indent=2)+'\n');print('compiled',len(objects),'link',code,'errors',len(errors));print('\n'.join(errors[:12]))
