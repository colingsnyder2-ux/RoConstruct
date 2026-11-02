"""Verify original application BaseUrl storage, accessor and lifetime bodies."""
import pathlib,json,sys,hashlib,struct,pefile
r=pathlib.Path(__file__).resolve().parents[3];sys.path.insert(0,str(r));from roc import rebuild,match
out=r/'rebuild/2008-06/out/native-layouts';d=json.loads((r/'work/2008-06/shared-layouts/document-swap-current.json').read_text());f=[x for x in d['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];src=r/'rebuild/2008-06/native-classes/ApplicationBaseUrl.cpp';obj=out/'NativeApplicationBaseUrl.obj';c,log=rebuild.run(rebuild.toolchain(21022),'cl',f+['/Fo'+str(obj),str(src)],out);assert c==0,log
raw=obj.read_bytes();sec,sy,defs,_=match._coff_data_index(raw);rows=[]
for addr,prefix in [('004060d0','?applicationBaseUrl@@'),('007ef840','??__EapplicationBaseUrlText@@'),('007fade0','??__FapplicationBaseUrlText@@')]:
 n,b,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));t,tr,_=match.target('2008-06',addr);assert match.exact_match(t,tr,b,refs);start,idx=defs[n];tab=sec[idx];globals=[]
 for i in range(tab[7]):
  off,si,k=struct.unpack_from('<IIH',raw,tab[5]+i*10);off-=start
  if 0<=off<=len(b)-4 and sy[si][0].startswith('?applicationBaseUrlText@@3'):
   assert struct.unpack_from('<I',t,off)[0]==0x96dcf0;globals.append(off)
 assert globals,(addr,n);rows.append(dict(address=addr,size=len(b),global_relocations=globals))
pe=pefile.PE(str(r/'work/2008-06/original-p4-reference/Roblox.exe'));assert pe.get_string_at_rva(0x816bb8-pe.OPTIONAL_HEADER.ImageBase)==b'BaseUrl'
registry,_,_=match.target('2008-06','0044c760');assert struct.pack('<I',0x96dcf0) in registry and struct.pack('<I',0x816bb8) in registry
paths=[pathlib.Path(__file__),src,r/'rebuild/2008-06/native-classes/CSaveToRobloxDialog.cpp'];sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();(r/'work/2008-06/shared-layouts/application-base-url-working.json').write_text(json.dumps(dict(sources={str(p.relative_to(r)):sha(p) for p in paths},object_sha256=sha(obj),methods=rows,original_global='0x96dcf0',registry_key='BaseUrl',scope='Inactive original CString lifetime/accessor and registry xref; full native startup initialization and runtime integration remain open.'),indent=2)+'\n');print('PASS: BaseUrl accessor, static lifecycle and registry xref')
