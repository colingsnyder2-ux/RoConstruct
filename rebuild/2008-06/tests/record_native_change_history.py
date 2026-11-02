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
units += [('enable',root/'rebuild/2008-06/native-classes/ChangeHistoryEnable.cpp','NativeChangeHistoryEnable.obj')]
units += [('reset',root/'rebuild/2008-06/native-classes/ChangeHistoryReset.cpp','NativeChangeHistoryReset.obj')]
units += [('record_lifetime',root/'rebuild/2008-06/native-classes/HistoryRecordLifetime.cpp','NativeHistoryRecordLifetime.obj')]
units += [('events',root/'rebuild/2008-06/native-classes/ChangeHistoryEvents.cpp','NativeChangeHistoryEvents.obj')]
units += [('lookup',root/'rebuild/2008-06/native-classes/HistoryRecordLookup.cpp','NativeHistoryRecordLookup.obj')]
units += [('state',root/'rebuild/2008-06/native-classes/HistoryItemState.cpp','NativeHistoryItemState.obj')]
for name,src,objname in units:
 obj=out/objname;f=[x for x in common if name!='state' or x!='/D_RELEASEASSERT']+['/Fo'+str(obj),str(src)];code,log=rebuild.run(rebuild.toolchain(21022),'cl',f,out);assert code==0,log;objects[name]=obj;flags[name]=f
methods=[('lifetime','0058ab90','??0ChangeHistoryService@RBX@@',[('??$?0PBD@?$DescribedCreatable@VChangeHistoryService',0x58a8d0),('??0?$list@',0x61a200)]),('lifetime','0058c1c0','??1ChangeHistoryService@RBX@@',[('??1HistoryRecord@RBX@@',0x58bed0),('??1scoped_connection@signals@boost@@',0x5954b0),('?_Tidy@?$list@',0x682b40),('??1?$FactoryProduct@VChangeHistoryService',0x587060)]),('queries','00587a90','?queryPlay@ChangeHistoryService@RBX@@',[]),('queries','00587b70','?queryUnplay@ChangeHistoryService@RBX@@',[])]
methods += [('playback','00588780','?play@ChangeHistoryService@RBX@@',[('?play@HistoryRecord@RBX@@',0x588710)]),('playback','0058a130','?unplay@ChangeHistoryService@RBX@@',[('?unplay@HistoryRecord@RBX@@',0x58a040)]),('record','00588710','?play@HistoryRecord@RBX@@',[('?play@HistoryItem@RBX@@',0x588440)]),('record','0058a040','?unplay@HistoryRecord@RBX@@',[('?unplay@HistoryItem@RBX@@',0x589a20),('?setParent@Instance@RBX@@',0x55a8f0)])]
methods += [('item','00588440','?play@HistoryItem@RBX@@',[('?setParent@Instance@RBX@@',0x55a8f0),('??$for_each@',0x588240)])]
methods += [('item','00589a20','?unplay@HistoryItem@RBX@@',[('?find@?$_Tree@',0x587ce0),('?push_back@?$deque@',0x589330),('?play@HistoryItem@RBX@@',0x588440),('?_Tidy@?$deque@',0x64fa10)])]
methods += [('enable','0058c8b0','?setEnabled@ChangeHistoryService@RBX@@',[('?current@Context@Security@RBX@@',0x493760),('?requirePermission@Context@Security@RBX@@',0x489810),('?start@ChangeHistoryService@RBX@@',0x58c620),('?reset@ChangeHistoryService@RBX@@',0x58c3c0),('?disconnect@connection@signals@boost@@',0x595230)])]
methods += [('enable','0058c4f0','?onServiceProvider@ChangeHistoryService@RBX@@',[('?reset@ChangeHistoryService@RBX@@',0x58c3c0),('?disconnect@connection@signals@boost@@',0x595230)])]
methods += [('reset','0058c3c0','?reset@ChangeHistoryService@RBX@@',[('??1HistoryRecord@RBX@@',0x58bed0),('??0HistoryRecord@RBX@@',0x58bf20),('??1?$_Tree@',0x58be50)])]
methods += [('record_lifetime','0058bf20','??0HistoryRecord@RBX@@',[('??0?$_Tree@',0x5892b0)]),('reset','0058bed0','??1HistoryRecord@RBX@@',[('??1?$_Tree@',0x58be50)])]
methods += [('reset','00589720','??1HistoryItem@RBX@@',[('??1?$_Tree@',0x589120)])]
methods += [('events','0058b870','?onHistoryAdded@ChangeHistoryService@RBX@@',[('___RTDynamicCast',0x6a17c6),('?get@HistoryRecord@RBX@@',0x58b6c0),('?captureAll@HistoryItem@RBX@@',0x589530)]),('events','0058b970','?onHistoryRemoving@ChangeHistoryService@RBX@@',[('___RTDynamicCast',0x6a17c6),('?get@HistoryRecord@RBX@@',0x58b6c0),('?reset@HistoryItem@RBX@@',0x588f60)]),('events','0058ba70','?onHistoryChanged@ChangeHistoryService@RBX@@',[('?get@HistoryRecord@RBX@@',0x58b6c0),('?update@HistoryItem@RBX@@',0x589650)])]
methods += [('lookup','0058b6c0','?get@HistoryRecord@RBX@@',[('?find@?$_Tree@',0x587ce0),('??0HistoryItem@RBX@@QAE@PAV',0x589890),('??0HistoryItem@RBX@@QAE@ABU',0x589cd0),('?insert@?$_Tree@',0x58b280),('??1HistoryItem@RBX@@',0x589720)]),('lookup','00589890','??0HistoryItem@RBX@@QAE@PAV',[('??0?$_Tree@',0x589190)]),('lookup','00589cd0','??0HistoryItem@RBX@@QAE@ABU',[('??0?$_Tree@',0x589210)])]
methods += [('state','00588f60','?reset@HistoryItem@RBX@@',[('?reset@?$shared_ptr@',0x456e80),('?_Erase@?$_Tree@',0x587d70)])]
methods += [('state','00589650','?update@HistoryItem@RBX@@',[('?captureProperty@HistoryItem@RBX@@',0x589410),('??$shared_from@VInstance@RBX@@',0x618a40),('??4shared_count@detail@boost@@',0x4025b0)])]
methods += [('state','00589530','?captureAll@HistoryItem@RBX@@',[('??$for_each@',0x5882f0),('??$shared_from@VInstance@RBX@@',0x618a40),('??4shared_count@detail@boost@@',0x4025b0)])]
methods += [('state','005894c0','?capture@HistoryItem@RBX@@',[('?captureProperty@HistoryItem@RBX@@',0x589410)])]
methods += [('state','005882f0','??$for_each@VIterator@?$MemberDescriptorContainer@VPropertyDescriptor',[])]
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
  if address=='0058c8b0' and 0<=offset<len(body)-4 and kind==6 and sy[index][0].startswith('??_C@'):
   assert struct.unpack_from('<I',target,offset)[0]==0x831950;member_edges.append(hex(0x831950))
  if address in ('0058b870','0058b970') and 0<=offset<len(body)-4 and kind==6 and sy[index][0].startswith('??_R0?AV'):
   member_edges.append((sy[index][0],struct.unpack_from('<I',target,offset)[0]))
  if address in ('00589650','005894c0') and 0<=offset<len(body)-4 and kind==6 and sy[index][0].startswith('?propParent@Instance@RBX@@'):
   member_edges.append(hex(struct.unpack_from('<I',target,offset)[0]))
  if address=='00589530' and 0<=offset<len(body)-4 and kind==6 and sy[index][0].startswith('?capture@HistoryItem@RBX@@'):
   member_edges.append(hex(struct.unpack_from('<I',target,offset)[0]))
 if address=='0058a040':assert member_edges==['0x5884d0']
 if address=='00588440':assert member_edges==['0x5872a0','0x5872a0']
 if address=='0058c8b0':assert member_edges==['0x831950']
 if address in ('0058b870','0058b970'):assert {v for _,v in member_edges}=={0x929844,0x92907c}
 if address in ('00589650','005894c0'):assert member_edges==['0x973d34']
 if address=='00589530':assert member_edges==['0x5894c0']
 for symbol,dest in expected:assert any(k.startswith(symbol) and v==hex(dest) for k,v in edges.items()),(address,symbol,edges)
 rows.append({'address':address,'symbol':name,'size':len(body),'direct_calls':edges})
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));baseaddr=pe.OPTIONAL_HEADER.ImageBase
u=lambda addr:struct.unpack('<I',pe.get_data(addr-baseaddr,4))[0]
vtable=0x8318bc;locator=u(vtable-4);typedesc=u(locator+12);assert pe.get_string_at_rva(typedesc+8-baseaddr)==b'.?AVChangeHistoryService@RBX@@'
factory,_,_=match.target('2008-06','004150d0');assert bytes.fromhex('68 a4 01 00 00') in factory
raw=objects['lifetime'].read_bytes();sections,symbols,definitions,_=match._coff_data_index(raw)
vname=next(n for n in definitions if n.startswith('??_7ChangeHistoryService@RBX@@6B?$GuidItem'))
start,index=definitions[vname];section=sections[index];slots={}
for i in range(section[7]):
 offset,symbol,kind=struct.unpack_from('<IIH',raw,section[5]+10*i)
 if offset>=start and kind==6:slots[(offset-start)//4]=symbols[symbol][0]
for index,name,address in [(12,'onServiceProvider',0x58c4f0),(16,'onHistoryAdded',0x58b870),(17,'onHistoryRemoving',0x58b970),(18,'onHistoryChanged',0x58ba70)]:
 assert slots[index].startswith('?'+name+'@ChangeHistoryService@RBX@@') and u(vtable+4*index)==address
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();paths=[Path(__file__),root/'rebuild/2008-06/native-classes/ChangeHistoryLifetime.cpp',root/'rebuild/2008-06/native-classes/ChangeHistoryQueries.cpp',root/'rebuild/2008-06/tests/NativeChangeHistoryLayout.cpp',root/'rebuild/2008-06/native-headers/v8datamodel/ChangeHistoryService.h',root/'rebuild/2008-06/native-headers/v8datamodel/HistoryRecord.h',root/'rebuild/2008-06/native-headers/v8tree/Instance.h']
paths += [root/'rebuild/2008-06/native-classes/ChangeHistoryPlayback.cpp',root/'rebuild/2008-06/native-classes/HistoryRecordPlayback.cpp',root/'rebuild/2008-06/native-classes/HistoryItemPlayback.cpp']
paths += [root/'rebuild/2008-06/native-classes/ChangeHistoryEnable.cpp',root/'rebuild/2008-06/native-classes/ChangeHistoryReset.cpp',root/'rebuild/2008-06/native-classes/HistoryRecordLifetime.cpp',root/'rebuild/2008-06/native-classes/ChangeHistoryEvents.cpp',root/'rebuild/2008-06/native-classes/HistoryRecordLookup.cpp',root/'rebuild/2008-06/native-classes/HistoryItemState.cpp']
receipt={'scope':'Inactive layout and twenty-seven matched bodies; descriptor ABI, context identity, record behavior, data/vtable linkage and runtime remain unverified.', 'inputs':{str(p.relative_to(root)):sha(p) for p in paths},'objects':{k:sha(v) for k,v in objects.items()},'flags':flags,'methods':rows,'factory':'004150d0','size':0x1a4,'vtable':hex(vtable),'record_size':0x40,'record_name_offset':0x24}
(root/'work/2008-06/shared-layouts/change-history-layout-working.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS change history lifecycle, queries, playback and original RTTI')
