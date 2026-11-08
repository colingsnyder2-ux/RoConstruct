import sys,json,hashlib,struct
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import rebuild,match
work=root/'rebuild/2008-06/out/native-layouts/body-setparent-worker';work.mkdir(exist_ok=True);base=root/'rebuild/2008-06/out/native-layouts/body-child-ops-worker/BodyChildOpsWorker.cpp';inc=root/'rebuild/2008-06/tests/NativeBodySetParentWorker.inc';src=work/'BodySetParentWorker.cpp';src.write_text(base.read_text()+'\n'+inc.read_text());obj=work/'BodySetParentWorker.obj';flags=['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj),str(src)];c,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,work);assert c==0,log
raw=obj.read_bytes();results=[]
for prefix,a in [('?setParent@Body@',0x6148b0),('?resetRoot@Body@',0x614530),('?calcRoot@Body@',0x613ef0)]:
 try:n,b,r=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
 except StopIteration:print(prefix,'not emitted');continue
 t,tr,_=match.target('2008-06','%08x'%a);exact=match.exact_match(t,tr,b,r);print(prefix,len(b),len(t),exact,flush=True);results.append({'symbol':n,'address':hex(a),'size':len(b),'original_size':len(t),'exact':exact})
(work/'results.json').write_text(json.dumps(results,indent=2))
secs,syms,defs,_=match._coff_data_index(raw)
for row in results:
 a=int(row['address'],16);n=row['symbol'];b=next(x[1] for x in match.coff_functions(raw) if x[0]==n);t,tr,_=match.target('2008-06','%08x'%a);assert row['exact'];start,idx=defs[n];tab=secs[idx];bindings={}
 for i in range(tab[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,tab[5]+10*i);off-=start
  if 0<=off<len(b)-3:
   v=struct.unpack_from('<I',t,off)[0]
   if kind==20:v=(a+off+4+struct.unpack_from('<i',t,off)[0])&0xffffffff
   bindings[syms[sym][0]]=v
 row['bindings']={k:hex(v) for k,v in bindings.items()};print(hex(a),row['bindings'])
 expected={0x6148b0:[('?onChildRemoved@Body@',0x614760),('?onChildAdded@Body@',0x6147f0),('??1SimBody@',0x47d410),('??0SimBody@',0x658ae0),('?calcRoot@Body@',0x613ef0),('?resetRoot@Body@',0x614530),('?p@?1??getNextStateIndex@',0x95a898)],0x614530:[('?resetRoot@Body@',0x614530)],0x613ef0:[('?calcRoot@Body@',0x613ef0)]}[a]
 for key,value in expected:assert any(k.startswith(key) and v==value for k,v in bindings.items()),(key,bindings)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Isolated recovered donor behavior; provisional Body prefix and SimBody layout, no runtime proof.','methods':results,'base_sha256':sha(base),'inc_sha256':sha(inc),'generated_source_sha256':sha(src),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__)),'flags':flags};(root/'work/2008-06/shared-layouts/body-setparent-worker.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS Body::setParent, root propagation, targets')
