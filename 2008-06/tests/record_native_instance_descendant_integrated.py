"""Check current native Instance descendant callbacks."""
import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root))
from roc import match,rebuild
prior=json.loads((root/'work/2008-06/shared-layouts/profiling-integrated.json').read_text())
flags=[x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')]
out=root/'rebuild/2008-06/out/native-layouts/instance-descendant-integrated';out.mkdir(parents=True,exist_ok=True)
source=root/'rebuild/2008-06/native-classes/InstanceDescendantEvents.cpp';obj=out/'InstanceDescendantEvents.obj'
flags+=['/Fo'+str(obj),str(source)]
code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,out);(out/'compile.log').write_text(log)
if code: print(log);sys.exit(code)
raw=obj.read_bytes();sections,symbols,definitions,_=match._coff_data_index(raw);rows=[]
for prefix,address in [('?onDescendentAdded@Instance@',0x55ae20),('?onDescendentRemoving@Instance@',0x55ae90)]:
 name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06','%08x'%address);assert match.exact_match(target,targetrefs,body,refs),(name,len(body),len(target));start,index=definitions[name];table=sections[index];bindings={}
 for i in range(table[7]):
  offset,symbol,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);offset-=start
  if kind==20 and 0<=offset<len(body)-3:bindings[symbols[symbol][0]]=hex((address+offset+4+struct.unpack_from('<i',target,offset)[0])&0xffffffff)
 rows.append({'symbol':name,'address':hex(address),'size':len(body),'bindings':bindings})
for prefix,value in [('??0DescendantAdded@', '0x558910'), ('?raise@', '0x557e80'), ('??$shared_from@', '0x618a40'), ('?fire@', '0x49d200')]:
 assert any(k.startswith(prefix) and v==value for k,v in rows[0]['bindings'].items()),(prefix,rows[0]['bindings'])
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();paths=[source,root/'rebuild/2008-06/native-headers/v8tree/Instance.h',root/'rebuild/2008-06/native-headers/util/Events.h',Path(__file__)]
receipt={'scope':'Current native descendant callback bytes and selected targets; helper ABI, final link and runtime unproven.','sources':{str(p.relative_to(root)):sha(p) for p in paths},'object_sha256':sha(obj),'flags':flags,'methods':rows}
(root/'work/2008-06/shared-layouts/instance-descendant-integrated.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS native Instance descendant callbacks and selected targets')
