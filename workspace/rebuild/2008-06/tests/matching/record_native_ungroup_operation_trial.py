import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';src=root/'rebuild/2008-06/experiments/trials/NativeUngroupOperationTrial.cpp';obj=out/'NativeUngroupOperationTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('??RUngroupOperation@'));target,targetrefs,_=match.target('2008-06','0057fb10');assert match.exact_match(target,targetrefs,body,refs);start,index=defs[name];table=sections[index];bindings={}
for i in range(table[7]):
 off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
 if 0<=off<len(body)-3:
  value=struct.unpack_from('<I',target,off)[0]
  if kind==20:value=(0x57fb10+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
  bindings[symbols[sym][0]]=value
for prefix,address in [('?push_back@?$vector@PAVInstance@',0x4213a0),('?removeAllChildren@Instance@',0x55b360),('?setParent@Instance@',0x55a8f0),('__imp___invalid_parameter_noinfo',0x802890)]:assert any(k.startswith(prefix) and v==address for k,v in bindings.items()),(prefix,bindings)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Inactive ungroup operation matches bytes and targets; ownership, selected object lifetimes and runtime ABI remain unproven.','address':'0x57fb10','size':len(body),'bindings':{k:hex(v) for k,v in bindings.items()},'source_sha256':sha(src),'object_sha256':sha(obj),'header_sha256':sha(root/'rebuild/2008-06/native-headers/v8tree/Instance.h'),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/ungroup-operation-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS ungroup operation bytes and call targets')
