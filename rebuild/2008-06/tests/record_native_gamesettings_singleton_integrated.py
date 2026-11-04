import json,sys,struct,hashlib
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
prior=json.loads((root/'work/2008-06/shared-layouts/profiling-integrated.json').read_text());flags=[x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')];out=root/'rebuild/2008-06/out/native-layouts/gamesettings-singleton-integrated';out.mkdir(parents=True,exist_ok=True);src=root/'rebuild/2008-06/native-classes/GameSettingsSingleton.cpp';obj=out/'GameSettingsSingleton.obj';code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);(out/'compile.log').write_text(log);assert code==0,log
raw=obj.read_bytes();n,b,r=next(x for x in match.coff_functions(raw) if x[0].startswith('?singleton@?$GlobalSettingsItem@VGameSettings'));t,tr,_=match.target('2008-06','0044bee0');exact=match.exact_match(t,tr,b,r);sections,symbols,defs,_=match._coff_data_index(raw);start,index=defs[n];sec=sections[index];bind={}
if len(b)==len(t):
 for i in range(sec[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,sec[5]+10*i);off-=start
  if 0<=off<len(b)-3:
   v=struct.unpack_from('<I',t,off)[0]
   if kind==20:v=(0x44bee0+off+4+struct.unpack_from('<i',t,off)[0])&0xffffffff
   bind[symbols[sym][0]]=hex(v)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();res={'scope':'Isolated native singleton template candidate derived from existing AuthoringSettings source; bytes and relocation targets checked separately; runtime and provider closure unproven.','symbol':n,'address':'0x44bee0','size':len(b),'target_size':len(t),'exact':exact,'bindings':bind,'native_header_sha256':{str(p.relative_to(root)):sha(p) for p in [root/'rebuild/2008-06/native-headers/v8datamodel/GameSettings.h',root/'rebuild/2008-06/native-headers/v8datamodel/GlobalSettings.h',root/'rebuild/2008-06/native-headers/v8tree/Instance.h',root/'rebuild/2008-06/native-headers/util/Sound.h']},'source_sha256':sha(src),'object_sha256':sha(obj),'recorder_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/gamesettings-singleton-integrated.json').write_text(json.dumps(res,indent=2)+'\n');print(json.dumps(res,indent=2))
assert exact
for prefix,want in [('?mutex@GlobalSettings@','0x974aa0'),('?do_lock@recursive_mutex@','0x563090'),('?do_unlock@recursive_mutex@','0x5630e0'),('?sing@?$GlobalSettingsItem@VGameSettings','0x96dd10'),('??$create@VGameSettings','0x44bdc0'),('?singleton@GlobalSettings@','0x5690f0'),('?setParent@Instance@','0x55a8f0')]:assert any(k.startswith(prefix) and v==want for k,v in bind.items()),(prefix,bind)
print('PASS original singleton target bindings')
