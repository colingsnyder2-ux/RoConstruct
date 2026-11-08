import json,sys,hashlib,struct
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts/workspace-name-provider-worker';out.mkdir(parents=True,exist_ok=True);prior=json.loads((root/'work/2008-06/shared-layouts/workspace-lifetime-integrated.json').read_text());flags=[x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')];src=root/'rebuild/2008-06/tests/NativeWorkspaceClassNameProviderWorker.cpp';obj=out/'NativeWorkspaceClassNameProviderWorker.obj';code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log
raw=obj.read_bytes();functions=match.coff_functions(raw);rows=[]
for pre in ['?getClassName@?$NonFactoryProduct@VRootInstance','?className@?$NonFactoryProduct@VRootInstance','??$doDeclare@$1?sWorkspace']:
 for name,body,refs in functions:
  if not name.startswith(pre):continue
  matches=[]
  for addr in (0x5a17f0,0x489c30,0x48aa70):
   target,tr,_=match.target('2008-06','%08x'%addr)
   if match.exact_match(target,tr,body,refs):matches.append(hex(addr))
  rows.append({'symbol':name,'size':len(body),'matched':matches})
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();res={'scope':'Inactive template provider candidate; byte equality masks relocations, original target identity and runtime must be separately checked.','methods':rows,'source_sha256':sha(src),'object_sha256':sha(obj),'recorder_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/workspace-name-provider-worker.json').write_text(json.dumps(res,indent=2)+'\n');print(json.dumps(rows,indent=2))
sections,symbols,defs,_=match._coff_data_index(raw)
for row in rows:
 name=row['symbol'];addr=int(row['matched'][0],16);target,_,_=match.target('2008-06','%08x'%addr);start,index=defs[name];table=sections[index];bindings={}
 for i in range(table[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
  if 0<=off<len(target)-3:
   value=struct.unpack_from('<I',target,off)[0]
   if kind==20:value=(addr+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
   bindings[symbols[sym][0]]=hex(value)
 row['bindings']=bindings
 if row['size']==23:
  assert any(k.startswith('??$callDoDeclare@') and v=='0x48aa70' for k,v in bindings.items()) and any('call_once@boost' in k and v=='0x557330' for k,v in bindings.items()) and any(k.startswith('??$doDeclare@') and v=='0x489c30' for k,v in bindings.items()),bindings
 else:assert bindings['?sWorkspace@RBX@@3PADA']=='0x94b680' and any(k.startswith('?declare@Name@RBX@@') and v=='0x553f90' for k,v in bindings.items()),bindings
res['methods']=rows;res['scope']='Inactive native template candidate; same 23-byte body matches 0x5a17f0 for getClassName/className, doDeclare matches 0x489c30. Original Workspace +0x10 vtable second slot points 0x5a17f0. Targets checked, semantic Name provider/link/runtime still require integration.';res['recorder_sha256']=sha(Path(__file__));(root/'work/2008-06/shared-layouts/workspace-name-provider-worker.json').write_text(json.dumps(res,indent=2)+'\n');print('PASS method byte matches and original typed target bindings')
import pefile
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));image=pe.OPTIONAL_HEADER.ImageBase;assert struct.unpack('<I',pe.get_data(0x833a48-image,4))[0]==0x5a17f0
print('PASS Workspace original getClassName vtable slot')
