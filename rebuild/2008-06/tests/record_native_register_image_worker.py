import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';work=out/'value-worker';work.mkdir(exist_ok=True);src=root/'rebuild/2008-06/tests/NativeRegisterImageWorker.cpp';obj=work/'NativeRegisterImageWorker.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],work);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);functions=match.coff_functions(raw);rows=[]
for prefix,address,expected in [('?registerImageContent@',0x55fbc0,[('?getNullName@Name@',0x554270),('?create@MD5Hasher@',0x55c8b0),('?getLocalCachePath@',0x55f940),('?Append@?$CPathT@',0x55df40),('__imp__PathFileExistsA@4',0x802b1c),('__imp_?seekg@',0x802418),('__imp_?read@',0x8024e4),('__imp_?write@',0x8024ec)]),('?getLocalCachePath@',0x55f940,[('?getCacheDirectory@FileSystem@',0x5a7ea0),('?g_strmgr@ATL@@',0x97f2ec),('?SetString@',0x55d950),('_atexit',0x6a17af)])]:
 name,body,refs=next(x for x in functions if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06','%08x'%address);assert match.exact_match(target,targetrefs,body,refs);start,index=defs[name];table=sections[index];bindings={}
 for i in range(table[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
  if 0<=off<len(body)-3:
   value=struct.unpack_from('<I',target,off)[0]
   if kind==20:value=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
   bindings[symbols[sym][0]]=value
 for key,value in expected:assert any(k.startswith(key) and v==value for k,v in bindings.items()),(key,bindings)
 rows.append({'address':hex(address),'size':len(body),'symbol':name,'bindings':{k:hex(v) for k,v in bindings.items()}})
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Inactive image registration and cache path match original code shape and call targets. Static identity, cache lifetime, ownership, exception and runtime ABI unproven.','methods':rows,'source_sha256':sha(src),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/register-image-worker-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS register image and cache path bytes and bindings')
