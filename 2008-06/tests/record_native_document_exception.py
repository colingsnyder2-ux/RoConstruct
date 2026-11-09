"""Verify shared native document exception logger."""
import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root))
from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';src=root/'rebuild/2008-06/native-classes/DocumentException.cpp'
base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]+['/FoNativeDocumentException.obj',str(src)]
code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,out);assert code==0,log
obj=out/'NativeDocumentException.obj';raw=obj.read_bytes();name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?reportDocumentException@@'));target,target_refs,_=match.target('2008-06','00428850');assert match.exact_match(target,target_refs,body,refs)
sections,symbols,defs,_=match._coff_data_index(raw);start,section=defs[name];table=sections[section];edges={}
for i in range(table[7]):
 offset,index,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);offset-=start
 if 0<=offset<len(body)-4 and kind==20:edges[symbols[index][0]]=hex(0x428850+offset+4+struct.unpack_from('<i',target,offset)[0])
for prefix,destination in [('?singleton@StandardOut@RBX@@','0x569620'),('?print@StandardOut@RBX@@','0x5693a0')]:
 assert any(symbol.startswith(prefix) and value==destination for symbol,value in edges.items()),(prefix,edges)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
paths=[Path(__file__),src,root/'rebuild/2008-06/native-classes/CRobloxDoc.cpp',root/'tools/rbxgs/Client/App/include/util/StandardOut.h']
receipt={'scope':'Inactive exception logger; original code and direct targets match.','inputs':{str(p.relative_to(root)):sha(p) for p in paths},'flags':flags,'object_sha256':sha(obj),'address':'00428850','size':len(body),'relocation_normalized_exact':True,'direct_calls':edges}
(root/'work/2008-06/shared-layouts/document-exception-working.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS native exception logger: 146 bytes and direct targets')
