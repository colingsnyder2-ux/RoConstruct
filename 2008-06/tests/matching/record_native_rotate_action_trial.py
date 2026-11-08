import hashlib,json,struct,sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';src=root/'rebuild/2008-06/experiments/trials/NativeRotateActionTrial.cpp';obj=out/'NativeRotateActionTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);functions=match.coff_functions(raw);rows=[]
for prefix,address,expected in [('?doIt@RotateAxisCommand@',0x5812b0,[('?checkRunPermissions@',0x57d250),('??$create@V?$FilteredSelection@VPVInstance',0x5805d0),('?rotateAboutAxis@',0x57f5b0),('??$create@VSoundService@',0x4531e0),('?playSound@SoundService@',0x5bd820),('?raise@?$Notifier@VWorkspace@',0x576940),('?recordCameraHistory@',0x58c5c0)]),('?rotateAboutAxis@RotateAxisCommand@',0x57f5b0,[('??0MegaDragger@',0x60e540),('?startDragging@MegaDragger@',0x60de00),('?safeRotate@MegaDragger@',0x60e310),('?finishDragging@MegaDragger@',0x60e780),('?raise@?$Notifier@VWorkspace@',0x576940),('??1MegaDragger@',0x60e700)])]:
 name,body,refs=next(x for x in functions if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06','%08x'%address);assert match.exact_match(target,targetrefs,body,refs);start,index=defs[name];table=sections[index];bindings={}
 for i in range(table[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+i*10);off-=start
  if kind==20 and 0<=off<len(body)-3:bindings[symbols[sym][0]]=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
 for key,value in expected:assert any(k.startswith(key) and v==value for k,v in bindings.items()),(key,bindings)
 rows.append({'address':hex(address),'size':len(body),'symbol':name,'bindings':{k:hex(v) for k,v in bindings.items()}})
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));assert struct.unpack('<I',pe.get_data(0x830a50+16-pe.OPTIONAL_HEADER.ImageBase,4))[0]==0x5812b0
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Inactive rotate action and helper match bytes, call targets and vtable slot; lifetime and runtime ABI unproven.','methods':rows,'source_sha256':sha(src),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/rotate-action-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS rotate action and helper bytes and bindings')
