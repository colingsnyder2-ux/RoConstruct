import sys,json,hashlib,re,shutil
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import rebuild
out=root/'rebuild/2008-06/out/native-layouts/sound-zlib-provider-worker';out.mkdir(exist_ok=True);proof=root/'work/2008-06/shared-layouts';base=json.loads((proof/'sound-native-link-frozen-worker.json').read_text());inst=json.loads((proof/'sound-native-instance-worker.json').read_text());latest=json.loads((proof/'sound-names-provider-link-worker.json').read_text());single=json.loads((proof/'sound-singleton-link-worker.json').read_text());newreceipt=json.loads((proof/'sound-constructors-integrated.json').read_text());sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();allowed=set(base['inputs'].values())|set(inst['objects'].values());inputs=[];hashes={}
for i,arg in enumerate(base['flags']):
 p=Path(arg)
 if p.is_file() and p.suffix.lower() in ('.obj','.lib'):
  assert sha(p) in allowed,(p,sha(p));q=out/('input%03d_'%i+p.name);shutil.copy2(p,q);hashes[str(q)]=sha(q);inputs.append(str(q))
for s,h in inst['objects'].items():
 if s.endswith('NativeSoundProviderMemberWorker.obj'): continue
 p=Path(s);assert sha(p)==h;q=out/('instance_'+p.name);shutil.copy2(p,q);hashes[str(q)]=sha(q);inputs.append(str(q))
def add(path,expected):
 p=root/path;assert sha(p)==expected,(p,sha(p),expected);q=out/('extra_'+p.name);shutil.copy2(p,q);hashes[str(q)]=sha(q);inputs.append(str(q));return q
r=json.loads((proof/'sound-classnames-worker.json').read_text());add('rebuild/2008-06/out/native-layouts/sound-classnames-worker/NativeSoundClassNamesWorker.obj',r['object_sha256'])
r=json.loads((proof/'instance-descendant-integrated.json').read_text());add('rebuild/2008-06/out/native-layouts/instance-descendant-integrated/InstanceDescendantEvents.obj',r['object_sha256'])
for rname,path in [('gamesettings-singleton-integrated.json','rebuild/2008-06/out/native-layouts/gamesettings-singleton-integrated/GameSettingsSingleton.obj'),('gamesettings-storage-integrated.json','rebuild/2008-06/out/native-layouts/gamesettings-storage-integrated/GameSettingsStorage.obj'),('sound-name-providers-integrated.json','rebuild/2008-06/out/native-layouts/sound-name-providers-integrated/SoundClassName.obj')]:
 rr=json.loads((proof/rname).read_text());add(path,rr['object_sha256'])
old=add('rebuild/2008-06/out/native-layouts/sound-storage-link-worker/SoundConstructors.obj',single['constructors_sha256']);new=out/'updated-SoundConstructors.obj';p=root/'rebuild/2008-06/out/native-layouts/sound-constructors-integrated/SoundConstructors.obj';assert sha(p)==newreceipt['object_sha256'];shutil.copy2(p,new);hashes[str(new)]=sha(new)
libs=['kernel32.lib','user32.lib','gdi32.lib','advapi32.lib','shell32.lib','ole32.lib','oleaut32.lib','comdlg32.lib','ws2_32.lib','winmm.lib','opengl32.lib','glu32.lib','imagehlp.lib','version.lib','wininet.lib','dbghelp.lib','psapi.lib']+['/NODEFAULTLIB:'+x for x in rebuild.VENDOR_AUTOLINK]
def run(name,replace):
 args=['/nologo','/SUBSYSTEM:CONSOLE','/MACHINE:X86']+[str(new) if replace and x==str(old) else x for x in inputs]+libs+['/OUT:'+name+'.exe','/MAP:'+name+'.map'];c,log=rebuild.run(rebuild.toolchain(21022),'link',args,out);(out/(name+'.log')).write_text(log);return c,[x.strip() for x in log.splitlines() if re.search(r'\berror LNK(?:2001|2019|2005|1104)',x)]
def syms(lines):
 out=set()
 for l in lines:
  m=re.search(r'unresolved external symbol (?:".*?" \(([^)]+)\)|([^ ]+))',l)
  if m:out.add(m.group(1) or m.group(2))
 return out

# Genuine 2008 zlib builds supply separate cdecl and ZLIB_WINAPI ABIs.
providers = []
for name in ["zlib", "zlib-winapi"]:
 p = root / "rebuild/2008-06/out" / name / "linked/linked.lib"
 q = out / (name + ".lib")
 shutil.copy2(p, q); hashes[str(q)] = sha(q); providers.append(str(q))
results = {}
for label, extra in [("baseline", []), ("cdecl", providers[:1]), ("winapi", providers[1:]), ("both", providers)]:
 inputs.extend(extra)
 code, errors = run(label, True)
 if extra: del inputs[-len(extra):]
 results[label] = {"exit":code, "unique":sorted(syms(errors)), "duplicates":[x for x in errors if "LNK2005" in x], "lines":len(errors)}
base = set(results["baseline"]["unique"])
for value in results.values():
 current=set(value["unique"]); value["resolved"]=sorted(base-current); value["new"]=sorted(current-base); value["unique_count"]=len(current)
result={"scope":"Frozen input copies; system libs external; link only, no execution", "inputs":hashes, "results":results, "observer_sha256":sha(Path(__file__))}
(proof/"sound-zlib-provider-worker.json").write_text(json.dumps(result,indent=2)+"\n")
print(json.dumps({k:{x:y for x,y in v.items() if x != "unique"} for k,v in results.items()},indent=2))
