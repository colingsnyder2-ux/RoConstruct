"""Verify original change-history layout, lifecycle and undo/redo query bodies."""
import hashlib,json,struct,sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root))
from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());common=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
units=[('lifetime',root/'rebuild/2008-06/tests/NativeChangeHistoryLayout.cpp','NativeChangeHistoryLayout.obj'),('queries',root/'rebuild/2008-06/native-classes/ChangeHistoryQueries.cpp','NativeChangeHistoryQueries.obj')];objects={};flags={}
units += [('playback',root/'rebuild/2008-06/native-classes/ChangeHistoryPlayback.cpp','NativeChangeHistoryPlayback.obj'),('record',root/'rebuild/2008-06/native-classes/HistoryRecordPlayback.cpp','NativeHistoryRecordPlayback.obj')]
units += [('item',root/'rebuild/2008-06/native-classes/HistoryItemPlayback.cpp','NativeHistoryItemPlayback.obj')]
for name,src,objname in units:
 obj=out/objname;f=common+['/Fo'+str(obj),str(src)];code,log=rebuild.run(rebuild.toolchain(21022),'cl',f,out);assert code==0,log;objects[name]=obj;flags[name]=f
methods=[('lifetime','0058ab90','??0ChangeHistoryService@RBX@@',[('??$?0PBD@?$DescribedCreatable@VChangeHistoryService',0x58a8d0),('??0?$list@',0x61a200)]),('lifetime','0058c1c0','??1ChangeHistoryService@RBX@@',[('??1HistoryRecord@RBX@@',0x58bed0),('??1scoped_connection@signals@boost@@',0x5954b0),('?_Tidy@?$list@',0x682b40),('??1?$FactoryProduct@VChangeHistoryService',0x587060)]),('queries','00587a90','?queryPlay@ChangeHistoryService@RBX@@',[]),('queries','00587b70','?queryUnplay@ChangeHistoryService@RBX@@',[])]
methods += [('playback','00588780','?play@ChangeHistoryService@RBX@@',[('?play@HistoryRecord@RBX@@',0x588710)]),('playback','0058a130','?unplay@ChangeHistoryService@RBX@@',[('?unplay@HistoryRecord@RBX@@',0x58a040)]),('record','00588710','?play@HistoryRecord@RBX@@',[('?play@HistoryItem@RBX@@',0x588440)]),('record','0058a040','?unplay@HistoryRecord@RBX@@',[('?unplay@HistoryItem@RBX@@',0x589a20),('?setParent@Instance@RBX@@',0x55a8f0)])]
methods += [('item','00588440','?play@HistoryItem@RBX@@',[('?setParent@Instance@RBX@@',0x55a8f0),('??$for_each@',0x588240)])]
rows=[]
for unit,address,prefix,expected in methods:
 raw=objects[unit].read_bytes();name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06',address);assert match.exact_match(target,targetrefs,body,refs),(address,len(body),len(target))
 sec,sy,defs,_=match._coff_data_index(raw);start,idx=defs[name];tab=sec[idx];edges={};member_edges=[]
 for i in range(tab[7]):
  offset,index,kind=struct.unpack_from('<IIH',raw,tab[5]+10*i);offset-=start
  if 0<=offset<len(body)-4 and kind==20:edges[sy[index][0]]=hex(int(address,16)+offset+4+struct.unpack_from('<i',target,offset)[0])
  if address=='0058a040' and 0<=offset<len(body)-4 and kind==6 and sy[index][0].startswith('?unplayProperty@HistoryItem@RBX@@'):
   assert struct.unpack_from('<I',target,offset)[0]==0x5884d0;member_edges.append(hex(0x5884d0))
  if address=='00588440' and 0<=offset<len(body)-4 and kind==6 and sy[index][0].startswith('?applyProperty@HistoryItem@RBX@@'):
   assert struct.unpack_from('<I',target,offset)[0]==0x5872a0;member_edges.append(hex(0x5872a0))
 if address=='0058a040':assert member_edges==['0x5884d0']
 if address=='00588440':assert member_edges==['0x5872a0','0x5872a0']
 for symbol,dest in expected:assert any(k.startswith(symbol) and v==hex(dest) for k,v in edges.items()),(address,symbol,edges)
 rows.append({'address':address,'symbol':name,'size':len(body),'direct_calls':edges})
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));baseaddr=pe.OPTIONAL_HEADER.ImageBase
u=lambda addr:struct.unpack('<I',pe.get_data(addr-baseaddr,4))[0]
vtable=0x8318bc;locator=u(vtable-4);typedesc=u(locator+12);assert pe.get_string_at_rva(typedesc+8-baseaddr)==b'.?AVChangeHistoryService@RBX@@'
factory,_,_=match.target('2008-06','004150d0');assert bytes.fromhex('68 a4 01 00 00') in factory
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();paths=[Path(__file__),root/'rebuild/2008-06/native-classes/ChangeHistoryLifetime.cpp',root/'rebuild/2008-06/native-classes/ChangeHistoryQueries.cpp',root/'rebuild/2008-06/tests/NativeChangeHistoryLayout.cpp',root/'rebuild/2008-06/native-headers/v8datamodel/ChangeHistoryService.h',root/'rebuild/2008-06/native-headers/v8datamodel/HistoryRecord.h',root/'rebuild/2008-06/native-headers/v8tree/Instance.h']
paths += [root/'rebuild/2008-06/native-classes/ChangeHistoryPlayback.cpp',root/'rebuild/2008-06/native-classes/HistoryRecordPlayback.cpp',root/'rebuild/2008-06/native-classes/HistoryItemPlayback.cpp']
receipt={'scope':'Inactive layout and nine matched bodies; descriptor ABI, context identity, record behavior, data/vtable linkage and runtime remain unverified.', 'inputs':{str(p.relative_to(root)):sha(p) for p in paths},'objects':{k:sha(v) for k,v in objects.items()},'flags':flags,'methods':rows,'factory':'004150d0','size':0x1a4,'vtable':hex(vtable),'record_size':0x40,'record_name_offset':0x24}
(root/'work/2008-06/shared-layouts/change-history-layout-working.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS change history lifecycle, queries, playback and original RTTI')
