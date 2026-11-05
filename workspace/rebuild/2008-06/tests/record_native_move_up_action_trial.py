import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';src=root/'rebuild/2008-06/tests/NativeMoveUpActionTrial.cpp';obj=out/'NativeMoveUpActionTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/fp:fast','/Fo'+str(obj),str(src)],out);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?doIt@MoveUpSelectionVerb@'));target,targetrefs,_=match.target('2008-06','00581630');assert match.exact_match(target,targetrefs,body,refs);start,index=defs[name];table=sections[index];bindings={}
for i in range(table[7]):
 off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+i*10);off-=start
 if 0<=off<len(body)-3:
  value=struct.unpack_from('<I',target,off)[0]
  if kind==20:value=(0x581630+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
  bindings[symbols[sym][0]]=value
for prefix,address in [('?checkRunPermissions@',0x57d250),('??$create@V?$FilteredSelection@VPVInstance',0x5805d0),('??0MegaDragger@',0x60e540),('?startDragging@MegaDragger@',0x60de00),('?safeMoveNoDrop@MegaDragger@',0x60e180),('?finishDragging@MegaDragger@',0x60e780),('??$create@VSoundService@',0x4531e0),('?playSound@SoundService@',0x5bd820),('?raise@?$Notifier@VWorkspace@',0x576940),('?recordCameraHistory@',0x58c5c0),('??1MegaDragger@',0x60e700)]:assert any(k.startswith(prefix) and v==address for k,v in bindings.items()),(prefix,bindings)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Inactive move-up action matches bytes and call targets; object lifetime and runtime ABI not proven.','address':'0x581630','size':len(body),'exact':True,'bindings':{k:hex(v) for k,v in bindings.items()},'source_sha256':sha(src),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/move-up-action-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS move-up action bytes and target bindings')

