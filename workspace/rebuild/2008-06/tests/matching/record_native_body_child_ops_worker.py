import sys,json,hashlib
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import rebuild,match
work=root/'rebuild/2008-06/out/native-layouts/body-child-ops-worker';work.mkdir(exist_ok=True);base=root/'rebuild/2008-06/out/native-layouts/body-mass-state-worker/outofclass0.cpp';inc=root/'rebuild/2008-06/tests/NativeBodyChildOpsWorker.inc';src=work/'BodyChildOpsWorker.cpp';src.write_text(base.read_text()+'\n'+inc.read_text());obj=work/'BodyChildOpsWorker.obj';flags=['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj),str(src)];c,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,work);print('compile',c,log[-2000:]);assert c==0
for prefix,a in [('?onChildRemoved@Body@',0x614760),('?onChildAdded@Body@',0x6147f0),('?makeCofmDirty@Body@',0x613f70)]:
 try:n,b,r=next(x for x in match.coff_functions(obj.read_bytes()) if x[0].startswith(prefix))
 except StopIteration:print(prefix,'not emitted');continue
 t,tr,_=match.target('2008-06','%08x'%a);print(prefix,len(b),len(t),match.exact_match(t,tr,b,r),flush=True)
import struct
raw=obj.read_bytes();secs,syms,defs,_=match._coff_data_index(raw);results=[]
for prefix,address in [('?onChildRemoved@Body@',0x614760),('?onChildAdded@Body@',0x6147f0),('?makeCofmDirty@Body@',0x613f70)]:
 n,b,r=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));t,tr,_=match.target('2008-06','%08x'%address);assert match.exact_match(t,tr,b,r);start,idx=defs[n];tab=secs[idx];bindings={}
 for i in range(tab[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,tab[5]+10*i);off-=start
  if 0<=off<len(b)-3:
   value=struct.unpack_from('<I',t,off)[0]
   if kind==20:value=(address+off+4+struct.unpack_from('<i',t,off)[0])&0xffffffff
   bindings[syms[sym][0]]=value
 expected={0x614760:[('?resize@',0x5fa770),('??3@YAXPAX@Z',0x6a067a),('?makeCofmDirty@',0x613f70)],0x6147f0:[('?append@',0x5fabc0),('??2@YAPAXI@Z',0x6a0920),('??0Cofm@',0x65fef0),('?makeCofmDirty@',0x613f70)],0x613f70:[('?makeCofmDirty@',0x613f70)]}[address]
 for key,value in expected: assert any(k.startswith(key) and v==value for k,v in bindings.items()),(key,bindings)
 results.append({'address':hex(address),'size':len(b),'symbol':n,'exact':True,'bindings':{k:hex(v) for k,v in bindings.items()}});print(hex(address),bindings)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Isolated donor methods on provisional Body/SimBody layouts. Match does not prove full layout, vtable, callers or runtime.','methods':results,'base_sha256':sha(base),'inc_sha256':sha(inc),'source_sha256':sha(src),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__)),'flags':flags};(root/'work/2008-06/shared-layouts/body-child-ops-worker.json').write_text(json.dumps(receipt,indent=2)+'\n')

