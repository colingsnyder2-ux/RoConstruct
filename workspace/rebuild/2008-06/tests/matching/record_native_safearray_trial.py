import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';src=root/'rebuild/2008-06/experiments/trials/NativeSafeArrayTrial.cpp';obj=out/'NativeSafeArrayTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?makeSafeArray@@'));target,targetrefs,_=match.target('2008-06','004165e0');assert match.exact_match(target,targetrefs,body,refs);start,index=defs[name];table=sections[index];bindings={}
for i in range(table[7]):
 off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
 if 0<=off<len(body)-3:
  value=struct.unpack_from('<I',target,off)[0]
  if kind==20:value=(0x4165e0+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
  bindings[symbols[sym][0]]=value
for prefix,address in [('__imp__SafeArrayCreate@12',0x802908),('__imp__SafeArrayLock@4',0x80290c),('?GetAt@?$CComSafeArray@',0x415b00),('?valueToVariant@',0x416370),('__imp__SafeArrayUnlock@4',0x802910)]:assert any(k.startswith(prefix) and v==address for k,v in bindings.items()),(prefix,bindings)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Inactive SAFEARRAY builder matches bytes and imports; value converter, lifetime and runtime ABI unproven.','address':'0x4165e0','size':len(body),'bindings':{k:hex(v) for k,v in bindings.items()},'source_sha256':sha(src),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/safearray-builder-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS SAFEARRAY builder bytes and targets')
