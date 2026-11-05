"""Verify native Instance ChildAdded listener replay and original calls."""
import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
proof=root/'work/2008-06/shared-layouts';prior=json.loads((proof/'runservice-fresh-current.json').read_text());out=root/'rebuild/2008-06/out/native-layouts/instance-child-listener-integrated';out.mkdir(parents=True,exist_ok=True);src=root/'rebuild/2008-06/native-classes/InstanceChildListener.cpp';obj=out/'InstanceChildListener.obj';flags=[x for x in prior['flags'] if not x.startswith('/Fo') and not x.endswith('RunService.cpp')]+['/Fo'+str(obj),str(src)];c,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,out);assert c==0,log;raw=obj.read_bytes();name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?onAddListener@Instance@RBX@@') and 'UChildAdded' in x[0]);target,tr,_=match.target('2008-06','00558d90');assert match.exact_match(target,tr,body,refs),(len(body),len(target));sections,symbols,defs,_=match._coff_data_index(raw);start,index=defs[name];table=sections[index];calls={}
for i in range(table[7]):
 off,si,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
 if kind==20 and 0<=off<len(body)-3:calls[symbols[si][0]]=hex((0x558d90+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff)
for prefix,address in [('?read@?$CopyOnWrite',0x4915b0),('??$shared_from@VInstance',0x618a40),('?raise@?$Notifier@VInstance@RBX@@UChildAdded',0x557a00)]:assert any(k.startswith(prefix) and v==hex(address) for k,v in calls.items()),(prefix,calls)
other=[]
for prefix,address,required in [('?onAddListener@Instance@RBX@@UBEXPAV?$Listener@VInstance@RBX@@UDescendantAdded',0x559230,{'0x558ff0'}),('??$for_eachChild@VRaiseDescendentAdded2',0x558ff0,{'0x4915b0','0x618a40','0x557780','0x558ff0'})]:
 symbol,code,relocs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));original,original_relocs,_=match.target('2008-06','%08x'%address);assert match.exact_match(original,original_relocs,code,relocs),(symbol,len(code),len(original));begin,section=defs[symbol];tab=sections[section];edges={}
 for i in range(tab[7]):
  off,si,kind=struct.unpack_from('<IIH',raw,tab[5]+10*i);off-=begin
  if kind==20 and 0<=off<len(code)-3:edges.setdefault(symbols[si][0],[]).append(hex((address+off+4+struct.unpack_from('<i',original,off)[0])&0xffffffff))
 assert required <= {v for values in edges.values() for v in values},edges;other.append({'address':hex(address),'symbol':symbol,'size':len(code),'calls':edges})
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();paths=[src,root/'rebuild/2008-06/native-headers/v8tree/Instance.h',root/'rebuild/2008-06/native-headers/v8tree/InstanceEvents.h',root/'rebuild/2008-06/native-headers/util/Events.h',Path(__file__)];result={'scope':'Inactive native ChildAdded and DescendantAdded replay; original bodies and selected direct call targets match. Instance ABI, data relocations and runtime remain unproven.','address':'0x558d90','symbol':name,'size':len(body),'calls':calls,'other_methods':other,'sources':{str(p.relative_to(root)):sha(p) for p in paths},'object_sha256':sha(obj),'flags':flags};(proof/'instance-child-listener-integrated.json').write_text(json.dumps(result,indent=2)+'\n');print('PASS Instance ChildAdded and DescendantAdded listener replay')
