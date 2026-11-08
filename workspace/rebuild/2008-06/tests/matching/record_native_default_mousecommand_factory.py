"""Verify native default mouse command factory and lifetime."""
import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root))
from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';source=root/'rebuild/2008-06/experiments/trials/NativeDefaultMouseCommandTrial.cpp';obj=out/'NativeDefaultMouseCommandTrial.obj'
base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]+['/Fo'+str(obj),str(source)]
code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,out);assert code==0,log
donor=root/'rebuild/2008-06/out/RbxgsApp/linked/NullTool.obj'
units=[(obj,'?createDefaultMouseCommand@RBX@@','005a0280',{'??0NewNullTool@RBX@@':0x618160}),
       (donor,'??0NewNullTool@RBX@@','00618160',{'??0MouseCommand@RBX@@':0x6159f0,'??_7NewNullTool@RBX@@6BINamed@':0x843c44,'??_7NewNullTool@RBX@@6BIRenderable@':0x843c28}),
       (donor,'??1NewNullTool@RBX@@','00617de0',{'??1MouseCommand@RBX@@':0x615780,'??_7NewNullTool@RBX@@6BINamed@':0x843c44,'??_7NewNullTool@RBX@@6BIRenderable@':0x843c28}),
       (donor,'??_GNewNullTool@RBX@@','006181d0',{'??1NewNullTool@RBX@@':0x617de0})]
rows=[];sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
for path,prefix,address,expected in units:
    raw=path.read_bytes();name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06',address)
    assert match.exact_match(target,targetrefs,body,refs),(address,len(body),len(target))
    sections,symbols,definitions,_=match._coff_data_index(raw);start,idx=definitions[name];section=sections[idx];found={}
    for i in range(section[7]):
        offset,sym,kind=struct.unpack_from('<IIH',raw,section[5]+10*i);offset-=start
        if not 0<=offset<len(body)-3:continue
        value=struct.unpack_from('<I',target,offset)[0]
        if kind==20:value=(int(address,16)+offset+4+struct.unpack_from('<i',target,offset)[0])&0xffffffff
        for key,wanted in expected.items():
            if symbols[sym][0].startswith(key):assert value==wanted,(address,key,hex(value));found[key]=hex(value)
    assert set(found)==set(expected),(address,found)
    rows.append({'address':address,'size':len(body),'object_sha256':sha(path),'targets':found})
headers=[root/'rebuild/2008-06/native-headers/v8datamodel/MouseCommand.h',root/'rebuild/2008-06/native-headers/StandardVerbs.h',root/'tools/rbxgs/Client/App/include/tool/NullTool.h']
receipt={'source_sha256':sha(source),'observer_sha256':sha(Path(__file__)),'headers':{str(p.relative_to(root)):sha(p) for p in headers},'flags':flags,'methods':rows,'scope':'Inactive trial. Existing object ctor/dtor direct targets verified; all vtable methods, object identity, EH and runtime ABI remain unproven.'}
(root/'work/2008-06/shared-layouts/default-mousecommand-factory-trial.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS default mouse command factory and NewNullTool lifetime')
