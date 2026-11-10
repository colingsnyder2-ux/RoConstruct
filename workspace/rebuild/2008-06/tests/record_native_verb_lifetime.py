"""Verify native verb destructors and selection query targets."""
import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root))
from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
common=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
units=['VerbLifetime','VerbBaseLifetime','VerbQueries'];objects={};flags={}
for unit in units:
 src=root/('rebuild/2008-06/native-classes/'+unit+'.cpp');obj=out/('Native'+unit+'.obj');f=common+['/Fo'+str(obj),str(src)];code,log=rebuild.run(rebuild.toolchain(21022),'cl',f,out);assert code==0,log;objects[unit]=obj;flags[unit]=f
methods=[('VerbBaseLifetime','005832c0','??1Verb@RBX@@',[('?erase@',0x405ce0)]),('VerbLifetime','0057dfd0','??1RunStateVerb@RBX@@',[('??1Verb@RBX@@',0x5832c0)]),('VerbLifetime','0057e050','??1EditSelectionVerb@RBX@@',[('??1Verb@RBX@@',0x5832c0)]),('VerbQueries','00565950','?isEnabled@Verb@RBX@@',[]),('VerbQueries','0060a2f0','?isChecked@Verb@RBX@@',[]),('VerbQueries','00582830','?isEnabled@EditSelectionVerb@RBX@@',[('?createService@',0x581cc0)]),('VerbQueries','00581cc0','?createService@?$ServiceClient@VSelection@RBX@@@RBX@@', [('??$create@VSelection@RBX@@',0x421cb0),('??$shared_from@VSelection@RBX@@',0x618a40),('??4shared_count@detail@boost@@',0x4025b0)])]
rows=[]
for unit,address,prefix,expected in methods:
 raw=objects[unit].read_bytes();name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06',address);assert match.exact_match(target,targetrefs,body,refs),(address,len(body),len(target))
 sec,sy,defs,_=match._coff_data_index(raw);start,idx=defs[name];tab=sec[idx];edges={}
 for i in range(tab[7]):
  offset,index,kind=struct.unpack_from('<IIH',raw,tab[5]+10*i);offset-=start
  if 0<=offset<len(body)-4 and kind==20:edges[sy[index][0]]=hex(int(address,16)+offset+4+struct.unpack_from('<i',target,offset)[0])
 for symbol,dest in expected:assert any(k.startswith(symbol) and v==hex(dest) for k,v in edges.items()),(address,symbol,edges)
 rows.append({'address':address,'symbol':name,'size':len(body),'direct_calls':edges})
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
inputs=[Path(__file__),root/'rebuild/2008-06/native-headers/StandardVerbs.h',root/'rebuild/2008-06/native-headers/v8tree/Verb.h',root/'rebuild/2008-06/native-headers/v8tree/Service.h',root/'rebuild/2008-06/native-headers/v8datamodel/Selection.h']+[root/('rebuild/2008-06/native-classes/'+u+'.cpp') for u in units]
receipt={'scope':'Inactive native destructor and query bodies; referenced class constructors, complete virtual tables and runtime swap remain unverified.', 'inputs':{str(p.relative_to(root)):sha(p) for p in inputs},'objects':{k:sha(v) for k,v in objects.items()},'flags':flags,'methods':rows}
(root/'work/2008-06/shared-layouts/verb-lifetime-queries.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS seven verb lifetime/query bodies and original direct targets')
