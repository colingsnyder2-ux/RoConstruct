import json,re,sys,hashlib,shutil
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import rebuild,match
out=root/'rebuild/2008-06/out/native-layouts/sound-integrated-link-worker';out.mkdir(parents=True,exist_ok=True);prev=root/'rebuild/2008-06/out/native-layouts/sound-player-build-worker';baseline=json.loads((root/'work/2008-06/shared-layouts/sound-player-build-worker.json').read_text());valid=set(baseline['snapshots'].values());sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();paths=sorted(prev.glob('frozen_*.obj'))+sorted(prev.glob('frozen_*.lib'))+sorted(prev.glob('provider_*.obj'));inputs=[]
for p in paths:
 assert sha(p) in valid,(p,'hash mismatch');dest=out/p.name;shutil.copy2(p,dest);inputs.append(str(dest))
prior=json.loads((root/'work/2008-06/shared-layouts/profiling-integrated.json').read_text());flags=[x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')]+['/I'+str(root/'tools/openrbx/3rdparty/fmod/api/inc')];objs=[]
for n in ['SoundClassName','SoundClassNames']:
 src=root/'rebuild/2008-06/native-classes'/(n+'.cpp');obj=out/(n+'.obj');code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log;objs.append(obj)
fs=match.coff_functions(objs[0].read_bytes())
for pre,addr in [('?getClassName@?$FactoryProduct@VSoundService',0x5b8450),('?getClassName@?$FactoryProduct@VSoundChannel',0x5b8470),('?getClassName@?$FactoryProduct@VStockSound',0x5b8490),('??$doDeclare@$1?sStockSound',0x5b6ce0)]:
 n,b,r=next(x for x in fs if x[0].startswith(pre));t,tr,_=match.target('2008-06','%08x'%addr);assert match.exact_match(t,tr,b,r)
raw=objs[1].read_bytes();sec,_,defs,_=match._coff_data_index(raw)
for sym,val in [('?sGameSettings@RBX@@3PADA',b'GameSettings\0'),('?sStatsItem@Stats@RBX@@3PADA',b'StatsItem\0'),('?sSoundChannel@Soundscape@RBX@@3PADA',b'Sound\0'),('?sSoundService@Soundscape@RBX@@3PADA',b'SoundService\0')]:
 o,i=defs[sym];assert raw[sec[i][4]+o:sec[i][4]+o+len(val)]==val
args=['/nologo','/SUBSYSTEM:CONSOLE','/MACHINE:X86']+inputs+['kernel32.lib','user32.lib','gdi32.lib','advapi32.lib','shell32.lib','ole32.lib','oleaut32.lib','comdlg32.lib','ws2_32.lib','winmm.lib','opengl32.lib','glu32.lib','imagehlp.lib','version.lib','wininet.lib','dbghelp.lib','psapi.lib']+['/NODEFAULTLIB:'+x for x in rebuild.VENDOR_AUTOLINK]
def link(name,extra):
 code,log=rebuild.run(rebuild.toolchain(21022),'link',args+['/OUT:'+name+'.exe','/MAP:'+name+'.map']+extra,out);(out/(name+'.log')).write_text(log);return code,[x.strip() for x in log.splitlines() if re.search(r'\berror LNK(?:2001|2019|2005)',x)]
bc,be=link('baseline',[]);cc,ce=link('candidate',list(map(str,objs)));removed=set(be)-set(ce);added=set(ce)-set(be);res={'scope':'Frozen mixed-ABI diagnostic, not runnable; input hashes verified against frozen previous build. Candidate uses actual production source objects, individually bytes checked.','baseline_exit':bc,'candidate_exit':cc,'baseline_errors':len(be),'candidate_errors':len(ce),'removed':sorted(removed),'added':sorted(added),'candidate_objects':{x.name:sha(x) for x in objs},'source_hashes':{x.name:sha(root/'rebuild/2008-06/native-classes'/x.name.replace('.obj','.cpp')) for x in objs},'baseline_receipt_sha256':sha(root/'work/2008-06/shared-layouts/sound-player-build-worker.json')};(root/'work/2008-06/shared-layouts/sound-integrated-link-worker.json').write_text(json.dumps(res,indent=2)+'\n');print('baseline',len(be),'candidate',len(ce),'removed',len(removed),'added',len(added));print('NEW',*sorted(added),sep='\n');print('REMOVED',*sorted(removed),sep='\n')
