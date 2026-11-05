import sys,json,hashlib,re,shutil
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import rebuild
proof=root/'work/2008-06/shared-layouts'; prior=json.loads((proof/'sound-integrated-providers-worker.json').read_text());out=root/'rebuild/2008-06/out/native-layouts/sound-service-lookup-worker';out.mkdir(parents=True,exist_ok=True);sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();inputs=[];hashes={}
for name,digest in prior['inputs'].items():
 p=Path(name);assert sha(p)==digest,(p,sha(p),digest);q=out/p.name;shutil.copy2(p,q);hashes[str(q)]=sha(q);inputs.append(str(q))
r=json.loads((proof/'service-lookup-integrated.json').read_text());p=root/'rebuild/2008-06/out/native-layouts/service-lookup-integrated/ServiceLookup.obj';assert sha(p)==r['object_sha256'];q=out/'ServiceLookup.obj';shutil.copy2(p,q);hashes[str(q)]=sha(q)
libs=['kernel32.lib','user32.lib','gdi32.lib','advapi32.lib','shell32.lib','ole32.lib','oleaut32.lib','comdlg32.lib','ws2_32.lib','winmm.lib','opengl32.lib','glu32.lib','imagehlp.lib','version.lib','wininet.lib','dbghelp.lib','psapi.lib']+['/NODEFAULTLIB:'+x for x in rebuild.VENDOR_AUTOLINK]
def run(name,extra):
 args=['/nologo','/SUBSYSTEM:CONSOLE','/MACHINE:X86']+inputs+extra+libs+['/OUT:'+name+'.exe','/MAP:'+name+'.map'];code,log=rebuild.run(rebuild.toolchain(21022),'link',args,out);(out/(name+'.log')).write_text(log);errors=[x.strip() for x in log.splitlines() if re.search(r'\berror LNK(?:2001|2019|2005|1104)',x)];syms=set()
 for line in errors:
  m=re.search(r'unresolved external symbol (?:".*?" \(([^)]+)\)|([^ ]+))',line)
  if m:syms.add(m.group(1) or m.group(2))
 return {'exit':code,'unique':sorted(syms),'unique_count':len(syms),'duplicates':[x for x in errors if 'LNK2005' in x],'other_errors':[x for x in errors if 'LNK1104' in x],'lines':len(errors)}
b=run('baseline',[]);c=run('candidate',[str(out/'ServiceLookup.obj')]);reference=set(prior['candidate']['unique']);assert set(b['unique'])==reference,(b['unique'],sorted(reference));c['resolved']=sorted(set(b['unique'])-set(c['unique']));c['new']=sorted(set(c['unique'])-set(b['unique']));result={'scope':'Hash verified project input copies, system libraries external. Link only, no runtime.','baseline':b,'candidate':c,'inputs':hashes,'observer_sha256':sha(Path(__file__))};(proof/'sound-service-lookup-worker.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps({'baseline':b,'candidate':c},indent=2))
