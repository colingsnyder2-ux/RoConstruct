import hashlib,json,re,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root))
from roc import rebuild
proof=root/'work/2008-06/shared-layouts'; prior=json.loads((proof/'sound-property-fresh-worker.json').read_text());sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
inputs=list(prior['inputs']);assert all(sha(Path(p))==v for p,v in prior['inputs'].items())
extra=[]
for label,obj in [('sound-value-get-integrated','SoundValueGet.obj'),('sound-value-convert-float-integrated','SoundValueConvertFloat.obj'),('sound-value-generic-float-integrated','SoundValueGenericFloat.obj'),('sound-value-convert-id-integrated','SoundValueConvertSoundId.obj'),('sound-value-generic-id-integrated','SoundValueGenericSoundId.obj'),('sound-string-converter-integrated','SoundStringConverter.obj')]:
 receipt=json.loads((proof/(label+'.json')).read_text());p=root/'rebuild/2008-06/out/native-layouts'/label/obj;assert sha(p)==receipt['object_sha256'];extra.append(str(p))
if '--guid' in sys.argv:
 receipt=json.loads((proof/'guiditem-current-worker.json').read_text());p=root/'rebuild/2008-06/out/native-layouts/guiditem-current-worker/GuidItem.obj';assert receipt['exact'] and sha(p)==receipt['object_sha256'];extra.append(str(p))
if '--guid-providers' in sys.argv:
 assert '--guid' in sys.argv
 for receipt_name,filename in [('guid-registry-initialize-working','NativeGuidRegistryInitialize.obj'),('guid-registry-mutex-working','NativeGuidRegistryMutex.obj'),('guid-critical-section-working','NativeGuidRegistryCriticalSection.obj')]:
  receipt=json.loads((proof/(receipt_name+'.json')).read_text());p=root/'rebuild/2008-06/out/native-layouts'/filename;assert sha(p)==receipt['object_sha256'];extra.append(str(p))
out=root/'rebuild/2008-06/out/native-layouts/sound-value-convert-link';out.mkdir(parents=True,exist_ok=True)
libs=['kernel32.lib','user32.lib','gdi32.lib','advapi32.lib','shell32.lib','ole32.lib','oleaut32.lib','comdlg32.lib','ws2_32.lib','winmm.lib','opengl32.lib','glu32.lib','imagehlp.lib','version.lib','wininet.lib','dbghelp.lib','psapi.lib']+['/NODEFAULTLIB:'+x for x in rebuild.VENDOR_AUTOLINK]
args=['/nologo','/SUBSYSTEM:CONSOLE','/MACHINE:X86']+inputs[9:]+inputs[:9]+extra+libs+['/OUT:candidate.exe','/MAP:candidate.map'];code,log=rebuild.run(rebuild.toolchain(21022),'link',args,out);(out/'candidate.log').write_text(log)
errors=[x.strip() for x in log.splitlines() if re.search(r'\berror LNK(?:2001|2019|2005|1104)',x)];symbols=[]
for line in errors:
 m=re.search(r'unresolved external symbol (?:".*?" \(([^)]+)\)|([^ ]+))',line)
 if m:symbols.append(m.group(1) or m.group(2))
result={'scope':'Frozen native-first diagnostic; mixed ABI, link only, no runtime.','exit':code,'unique':sorted(set(symbols)),'errors':errors,'inputs':{p:sha(Path(p)) for p in inputs+extra},'observer_sha256':sha(Path(__file__))};name='sound-value-convert-guid-providers-link.json' if '--guid-providers' in sys.argv else ('sound-value-convert-guid-link.json' if '--guid' in sys.argv else 'sound-value-convert-link.json');(proof/name).write_text(json.dumps(result,indent=2)+'\n');print(json.dumps({'exit':code,'unique':result['unique'],'errors':len(errors)},indent=2))
