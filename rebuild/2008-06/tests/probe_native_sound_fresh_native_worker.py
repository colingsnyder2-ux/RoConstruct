import sys,json,hashlib,re,shutil
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import rebuild
from roc import libs
proof=root/'work/2008-06/shared-layouts'; prior=json.loads((proof/'sound-service-lookup-worker.json').read_text());out=root/'rebuild/2008-06/out/native-layouts/sound-fresh-native-worker';out.mkdir(parents=True,exist_ok=True);sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();inputs=[];hashes={};source_hashes={};compile_flags={}
spec=json.loads((root/'rebuild/2008-06/modules/p4-sound-asset.json').read_text());layer=spec['layers'][0];inc=[root/'rebuild/2008-06/native-headers',root/'rebuild/2008-06/out/P4SoundAsset/overlay/App/include']+[(libs.LIBS/i).resolve() for i in libs.RECIPES['rbxgs']['include'] if i!='WINSDK']+[root/p for p in layer['extra_includes']];defs=(libs.RECIPES['rbxgs']['defines']+' '+layer['extra_defines']).split()
for filename in layer['files'].split():
 src=root/'rebuild/2008-06/tests'/filename;obj=out/(src.stem+'.obj');args=['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj)]+['/I'+str(p) for p in inc]+['/D'+d for d in defs]+[str(src)];code,log=rebuild.run(rebuild.toolchain(21022),'cl',args,out);(out/(src.stem+'.log')).write_text(log);assert code==0,(src,log);source_hashes[str(src)]=sha(src);hashes[str(obj)]=sha(obj);compile_flags[str(src)]=args
for name,digest in prior['inputs'].items():
 p=Path(name);assert sha(p)==digest,(p,sha(p),digest)
 if '_PlayerNative' in p.name:continue
 q=out/p.name;shutil.copy2(p,q);hashes[str(q)]=sha(q);inputs.append(str(q))
inputs += [str(out/(Path(filename).stem+'.obj')) for filename in layer['files'].split()]
libs=['kernel32.lib','user32.lib','gdi32.lib','advapi32.lib','shell32.lib','ole32.lib','oleaut32.lib','comdlg32.lib','ws2_32.lib','winmm.lib','opengl32.lib','glu32.lib','imagehlp.lib','version.lib','wininet.lib','dbghelp.lib','psapi.lib']+['/NODEFAULTLIB:'+x for x in rebuild.VENDOR_AUTOLINK]
def run(name,extra):
 args=['/nologo','/SUBSYSTEM:CONSOLE','/MACHINE:X86']+inputs+extra+libs+['/OUT:'+name+'.exe','/MAP:'+name+'.map'];code,log=rebuild.run(rebuild.toolchain(21022),'link',args,out);(out/(name+'.log')).write_text(log);errors=[x.strip() for x in log.splitlines() if re.search(r'\berror LNK(?:2001|2019|2005|1104)',x)];syms=set()
 for line in errors:
  m=re.search(r'unresolved external symbol (?:".*?" \(([^)]+)\)|([^ ]+))',line)
  if m:syms.add(m.group(1) or m.group(2))
 return {'exit':code,'unique':sorted(syms),'unique_count':len(syms),'duplicates':[x for x in errors if 'LNK2005' in x],'other_errors':[x for x in errors if 'LNK1104' in x],'lines':len(errors)}
candidate=run('candidate',[]);old=set(prior['candidate']['unique']);candidate['resolved']=sorted(old-set(candidate['unique']));candidate['new']=sorted(set(candidate['unique'])-old);result={'scope':'Seven fresh native-first sound sources, prior frozen providers and libs. Hash verified project inputs; system libs external. Link only; no runtime.','candidate':candidate,'sources':source_hashes,'compile_flags':compile_flags,'inputs':hashes,'observer_sha256':sha(Path(__file__))};(proof/'sound-fresh-native-worker.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(candidate,indent=2))
