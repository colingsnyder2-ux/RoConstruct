import json,re,sys,hashlib,shutil,struct
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import rebuild,match
old=root/'rebuild/2008-06/out/native-layouts/sound-integrated-link-worker';out=root/'rebuild/2008-06/out/native-layouts/sound-provider-comdat-worker';out.mkdir(parents=True,exist_ok=True);snap=json.loads((root/'work/2008-06/shared-layouts/sound-player-build-worker.json').read_text());integrated=json.loads((root/'work/2008-06/shared-layouts/sound-integrated-link-worker.json').read_text());sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();valid=set(snap['snapshots'].values())|set(integrated['candidate_objects'].values());paths=sorted(old.glob('frozen_*.obj'))+sorted(old.glob('frozen_*.lib'))+sorted(old.glob('provider_*.obj'))+[old/'SoundClassName.obj',old/'SoundClassNames.obj'];copied=[]
for i,p in enumerate(paths):
 assert sha(p) in valid,(p,'hash mismatch');q=out/('snapshot_%03d_'%i+p.name);shutil.copy2(p,q);copied.append((p.name,str(q)))
standalone=next(v for k,v in copied if 'NativeSoundProviderMemberWorker.obj' in k);archive=next(Path(v) for k,v in copied if k.startswith('frozen_008_'));providers=[];pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));base=pe.OPTIONAL_HEADER.ImageBase
for member in ['Replicator.obj','Workspace.obj','glue_runtime.obj']:
 dst=out/('extracted_'+member);code,log=rebuild.run(rebuild.toolchain(21022),'lib',['/nologo','/extract:'+member,'/out:'+str(dst),str(archive)],out);assert code==0,log;raw=dst.read_bytes();n,b,r=next(x for x in match.coff_functions(raw) if x[0].startswith('?findServiceProvider@ServiceProvider@RBX@@'));t,tr,_=match.target('2008-06','004898d0');assert match.exact_match(t,tr,b,r);sections,symbols,defs,_=match._coff_data_index(raw);start,index=defs[n];sec=sections[index];bindings={}
 for i in range(sec[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,sec[5]+10*i);off-=start
  if 0<=off<len(b)-3:
   val=struct.unpack_from('<I',t,off)[0]
   if kind==20:val=(0x4898d0+off+4+struct.unpack_from('<i',t,off)[0])&0xffffffff
   bindings[symbols[sym][0]]=hex(val)
 assert bindings['??_R0?AVServiceProvider@RBX@@@8']=='0x92e15c' and bindings['??_R0?AVInstance@RBX@@@8']=='0x92907c' and bindings['___RTDynamicCast']=='0x6a17c6';assert pe.get_string_at_rva(0x92e15c-base+8)==b'.?AVServiceProvider@RBX@@' and pe.get_string_at_rva(0x92907c-base+8)==b'.?AVInstance@RBX@@';providers.append({'member':member,'size':len(b),'bindings':bindings,'sha256':sha(dst)})
lib=['kernel32.lib','user32.lib','gdi32.lib','advapi32.lib','shell32.lib','ole32.lib','oleaut32.lib','comdlg32.lib','ws2_32.lib','winmm.lib','opengl32.lib','glu32.lib','imagehlp.lib','version.lib','wininet.lib','dbghelp.lib','psapi.lib']
def link(name,exclude):
 args=['/nologo','/SUBSYSTEM:CONSOLE','/MACHINE:X86','/OUT:'+name+'.exe','/MAP:'+name+'.map']+[v for k,v in copied if v!=exclude]+lib+['/NODEFAULTLIB:'+x for x in rebuild.VENDOR_AUTOLINK];code,log=rebuild.run(rebuild.toolchain(21022),'link',args,out);(out/(name+'.log')).write_text(log);return code,[x.strip() for x in log.splitlines() if re.search(r'\berror LNK(?:2001|2019|2005)',x)]
bc,be=link('baseline',None);cc,ce=link('candidate',standalone);removed=set(be)-set(ce);added=set(ce)-set(be);result={'scope':'Hash-checked frozen mixed ABI diagnostic; three donor COMDATs byte-identical with original target bindings but final class hierarchy/runtime unverified. Never run.','providers':providers,'baseline_exit':bc,'candidate_exit':cc,'baseline_errors':len(be),'candidate_errors':len(ce),'removed':sorted(removed),'added':sorted(added),'recorder_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/sound-provider-comdat-worker.json').write_text(json.dumps(result,indent=2)+'\n');print('providers',len(providers),'baseline',len(be),'candidate',len(ce),'removed',len(removed),'added',len(added));print('ADDED',*sorted(added),sep='\n')
