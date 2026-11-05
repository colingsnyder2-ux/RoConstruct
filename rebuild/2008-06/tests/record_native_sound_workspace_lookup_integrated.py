"""Check native sound Workspace lookup against the original call targets."""
import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root))
from roc import match,rebuild
prior=json.loads((root/'work/2008-06/shared-layouts/profiling-integrated.json').read_text())
flags=[x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')]
out=root/'rebuild/2008-06/out/native-layouts/sound-workspace-lookup-integrated';out.mkdir(parents=True,exist_ok=True)
source=root/'rebuild/2008-06/tests/PlayerNativeSoundChannel.cpp';obj=out/'PlayerNativeSoundChannel.obj'
flags+=['/I'+str(root/'tools/openrbx/3rdparty/fmod/api/inc'),'/Fo'+str(obj),str(source)]
code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,out);(out/'compile.log').write_text(log)
if code:print(log);sys.exit(code)
raw=obj.read_bytes();name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?onAncestorChanged@SoundChannel@Soundscape@RBX@@'))
target,targetrefs,_=match.target('2008-06','005bd890');address=0x5bd890
calls=[address+i+5+struct.unpack_from('<i',target,i+1)[0] for i in range(len(target)-4) if target[i]==0xe8]
assert calls.count(0x490af0)==2
undefined=[k for k,v in rebuild.coff_externals(raw).items() if not v]
assert any(k.startswith('??$find@VWorkspace@') for k in undefined),undefined
assert not any(k.startswith('??$create@VWorkspace@') for k in undefined),undefined
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();paths=[source,root/'rebuild/2008-06/native-headers/util/Sound.h',root/'rebuild/2008-06/native-headers/v8tree/Service.h',Path(__file__)]
receipt={'scope':'Workspace lookup correction only. Callback is nonexact; full service ABI/runtime unproven.','sources':{str(p.relative_to(root)):sha(p) for p in paths},'object_sha256':sha(obj),'original_callback':'0x5bd890','original_lookup_target':'0x490af0','original_lookup_calls':2,'candidate_size':len(body),'original_size':len(target),'callback_exact':match.exact_match(target,targetrefs,body,refs),'flags':flags}
(root/'work/2008-06/shared-layouts/sound-workspace-lookup-integrated.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS native sound Workspace lookup; callback exact:',receipt['callback_exact'])
