import sys,json
from pathlib import Path
root=Path(__file__).resolve().parents[3]; main=root; sys.path.insert(0,str(main))
from roc import match,rebuild
out=root/'rebuild/2008-06/out/insert-service'; out.mkdir(parents=True,exist_ok=True)
base=json.loads((main/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
overlay=out/'overlay/v8tree'; overlay.mkdir(parents=True,exist_ok=True)
hdr=(main/'rebuild/2008-06/native-headers/v8tree/Service.h').read_text(); (overlay/'Service.h').write_text(hdr.replace('    static size_t newIndex();','    static Instance* create(Instance*, const Name&);\n    static size_t newIndex();'))
(overlay.parent/'StandardVerbs.h').write_text((main/'rebuild/2008-06/native-headers/StandardVerbs.h').read_text())
flags.insert(0,'/I'+str(overlay.parent))
source=root/'rebuild/2008-06/experiments/trials/NativeInsertServiceTrial.cpp'; obj=out/'NativeInsertServiceTrial.obj'
code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(source)],out)
print(log); assert code==0
name,body,refs=next(x for x in match.coff_functions(obj.read_bytes()) if x[0].startswith('?doIt@InsertService@@'))
target,targetrefs,_=match.target('2008-06','0041f3c0')
print(name,'body',len(body),'target',len(target),'exact',match.exact_match(target,targetrefs,body,refs))

import struct,hashlib
assert match.exact_match(target,targetrefs,body,refs)
raw=obj.read_bytes(); sections,symbols,defs,_=match._coff_data_index(raw); start,sec=defs[name]; table=sections[sec]; bindings={}
for i in range(table[7]):
 off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i); off-=start
 if not 0<=off<len(body)-3: continue
 value=struct.unpack_from('<I',target,off)[0]
 if kind==20: value=(0x41f3c0+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
 bindings[symbols[sym][0]]=value
for symbol,value in bindings.items(): print(hex(value),symbol)
assert any(k.startswith('?create@ServiceProvider@RBX@@') and v==0x5726f0 for k,v in bindings.items())
assert any(k.startswith('??0CInsertObjectDialog@@') and v==0x41fe00 for k,v in bindings.items())
assert any(k.startswith('??1CInsertObjectDialog@@') and v==0x41ff40 for k,v in bindings.items())
print('PASS bytes and typed call bindings; dialog layout remains unproven')
import pefile
pe=pefile.PE(str(main/'work/2008-06/original-p4-reference/Roblox.exe')); baseaddr=pe.OPTIONAL_HEADER.ImageBase
assert struct.unpack('<I',pe.get_data(0x80f22c+16-baseaddr,4))[0]==0x41f3c0
assert pe.get_string_at_rva(0x80f250-baseaddr)==b'InsertService'
assert pe.get_string_at_rva(0x80f260-baseaddr)==b'ClassName'
link=out/'NativeInsertServiceLink.obj';link.write_bytes(rebuild.strip_symbols(raw,keep={name}));linkname,linkbody,linkrefs=next(x for x in match.coff_functions(link.read_bytes()) if x[0]==name);assert match.exact_match(target,targetrefs,linkbody,linkrefs)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
receipt={'scope':'Exact native method body and typed service call; dialog member layout and runtime ABI remain unproven. Diagnostic overlay only.', 'address':'0041f3c0','size':len(body),'exact':True,'vtable':'0080f22c','bindings':{k:hex(v) for k,v in bindings.items()},'source_sha256':sha(source),'object_sha256':sha(obj),'link_object_sha256':sha(link),'overlay_sha256':sha(overlay/'Service.h'),'observer_sha256':sha(Path(__file__))}
(root/'work/2008-06/shared-layouts/insert-service-trial.json').write_text(json.dumps(receipt,indent=2)+'\n')
