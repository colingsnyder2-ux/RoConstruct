import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';src=root/'rebuild/2008-06/tests/NativeClearStarterTrial.cpp';header=root/'tools/rbxgs/Client/App/include/v8datamodel/Surface.h';overlay=out/'clear-starter-include/v8datamodel';overlay.mkdir(parents=True,exist_ok=True);data=header.read_text();assert data.count('PartInstance* getPartInstance() const;')==1;patched=overlay/'Surface.h';patched.write_text(data.replace('PartInstance* getPartInstance() const;','PartInstance* getPartInstance() const { return partInstance; }'))
(overlay/'Hopper.h').write_text('#pragma once\nnamespace RBX { class StarterPackService : public Instance {}; }\n')
obj=out/'NativeClearStarterTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(out/'workspace-model-vector-include'));flags.insert(0,'/I'+str(overlay.parent));code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);rows=[]
for prefix,address,expected in [('?isEnabled@ClearStarterpack@',0x580ae0,[('??$create@VStarterPackService@',0x490d70)]),('?doIt@ClearStarterpack@',0x580b20,[('?checkRunPermissions@',0x57d250),('??$create@VStarterPackService@',0x490d70),('?removeAllChildren@Instance@',0x55afd0)]),('?checkRunPermissions@RBX@@',0x57d250,[('?clientIsPresent@Client@',0x495e60),('?serverIsPresent@Server@',0x495e70)])]:
 name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06','%08x'%address);assert match.exact_match(target,targetrefs,body,refs),(prefix,len(body),len(target))
 start,section=defs[name];table=sections[section];bindings={}
 for i in range(table[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
  if not 0<=off<len(body)-3:continue
  value=struct.unpack_from('<I',target,off)[0]
  if kind==20:value=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
  bindings.setdefault(symbols[sym][0],value)
 for token,value in expected:assert any(k.startswith(token) and v==value for k,v in bindings.items()),(token,bindings)
 rows.append({'address':hex(address),'size':len(body),'symbol':name,'bindings':{k:hex(v) for k,v in bindings.items()}})
import pefile
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe')); assert struct.unpack('<II',pe.get_data(0x8306b8+8-pe.OPTIONAL_HEADER.ImageBase,12)[0:4]+pe.get_data(0x8306b8+16-pe.OPTIONAL_HEADER.ImageBase,4))==(0x580ae0,0x580b20)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'ClearStarterpack enable method matches; StarterPackService overlay is incomplete, runtime ABI unproven.','methods':rows,'source_sha256':sha(src),'surface_header_sha256':sha(header),'overlay_sha256':sha(patched),'object_sha256':sha(obj),'hopper_overlay_sha256':sha(overlay/'Hopper.h'),'instance_header_sha256':sha(root/'rebuild/2008-06/native-headers/v8tree/Instance.h'),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/clear-starter-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS ClearStarterpack and bindings')

