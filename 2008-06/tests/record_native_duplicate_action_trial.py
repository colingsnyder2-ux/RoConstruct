import hashlib,json,struct,sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';src=root/'rebuild/2008-06/experiments/trials/NativeDuplicateActionTrial.cpp';obj=out/'NativeDuplicateActionTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?doIt@DuplicateSelectionVerb@'));target,targetrefs,_=match.target('2008-06','00582bb0');assert match.exact_match(target,targetrefs,body,refs);start,index=defs[name];table=sections[index];bindings={}
for i in range(table[7]):
 off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
 if 0<=off<len(body)-3:
  value=struct.unpack_from('<I',target,off)[0]
  if kind==20:value=(0x582bb0+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
  bindings[symbols[sym][0]]=value
for prefix,address in [('?checkRunPermissions@',0x57d250),('?newRootElement@SerializerV2@',0x591a30),('??$create@VSelection@',0x4153b0),('?collectSelection@',0x57e140),('??$for_each@',0x423ba0),('?isolateHandles@SerializerV2@',0x593480),('?insertItems@Workspace@',0x5a05d0),('??$setSelection@',0x413b00),('??$create@VSoundService@',0x4531e0),('?playSound@SoundService@',0x5bd820),('?recordCameraHistory@',0x58c5c0),('??1XmlElement@',0x413a70)]:assert any(k.startswith(prefix) and v==address for k,v in bindings.items()),(prefix,bindings)
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));assert struct.unpack('<I',pe.get_data(0x8307f4+16-pe.OPTIONAL_HEADER.ImageBase,4))[0]==0x582bb0
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Inactive duplicate action matches bytes, targets and vtable; serializer, workspace lifetime and runtime ABI unproven.','address':'0x582bb0','size':len(body),'bindings':{k:hex(v) for k,v in bindings.items()},'source_sha256':sha(src),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/duplicate-action-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS duplicate action bytes and call targets')
