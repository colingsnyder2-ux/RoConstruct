"""Verify inactive DebugSettings singleton bytes, targets, and original storage."""
import hashlib, json, os, subprocess, sys
from pathlib import Path
root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root/'rebuild/2008-06/tests'))
from native_bind import Original, match, verify
base = root/'rebuild/2008-06'
out = base/'out/native-debugsettings-singleton-evidence'
env = dict(os.environ, NATIVE_CHECK_OUT=str(out))
prefix = '?singleton@?$GlobalSettingsItem@VDebugSettings'
p = subprocess.run([sys.executable,str(base/'tests/check_native_class.py'),'native-classes/DebugSettingsSingleton.cpp','00407be0='+prefix,'00407820=??$create@VDebugSettings@RBX@@','00407450=??$?0VDebugSettings@RBX@@'],cwd=root,env=env,capture_output=True,text=True,check=True)
assert '3/3 exact' in p.stdout, p.stdout
obj=out/'CheckDebugSettingsSingleton.obj'; raw=obj.read_bytes()
names=[n for n,_,_ in match.coff_functions(raw)]
methods=[(next(n for n in names if n.startswith(k)),address) for k,address in [(prefix,0x407be0),('??$create@VDebugSettings@RBX@@',0x407820),('??$?0VDebugSettings@RBX@@',0x407450)]]
_, symbols, _, _ = match._coff_data_index(raw)
mapping=[('?mutex@GlobalSettings@',0x974aa0),('?do_lock@recursive_mutex@',0x563090),('?do_unlock@recursive_mutex@',0x5630e0),('?sing@?$GlobalSettingsItem@VDebugSettings',0x96c318),('?singleton@GlobalSettings@',0x5690f0),('?setParent@Instance@',0x55a8f0),('??0DebugSettings@RBX@@',0x565ac0),('??$?0PAVDebugSettings@RBX@@',0x406ed0)]
internal={next(v[0] for v in symbols.values() if v[0].startswith(k)): addr for k,addr in mapping}
original=Original(); assert original.data(0x96c318,4)==b'\0'*4
rows=verify(original,obj,methods,internal)
paths=[base/'native-classes/DebugSettingsSingleton.cpp',base/'native-headers/v8datamodel/DebugSettings.h',base/'native-headers/v8datamodel/GlobalSettings.h',base/'tests/native_bind.py',Path(__file__)]
receipt={'revision':subprocess.check_output(['git','rev-parse','HEAD'],cwd=root,text=True).strip(),'sources':{str(x.relative_to(root)):hashlib.sha256(x.read_bytes()).hexdigest() for x in paths},'object_sha256':hashlib.sha256(raw).hexdigest(),'methods':rows,'scope':'Inactive exact singleton, creator and shared_ptr constructor; call and storage targets checked. Provider ownership, indirect calls, ABI and runtime unverified.'}
(root/'work/2008-06/native-debugsettings-singleton.json').write_text(json.dumps(receipt,indent=2)+'\n')
print(p.stdout,end='');print('PASS: direct bindings and original singleton storage')
