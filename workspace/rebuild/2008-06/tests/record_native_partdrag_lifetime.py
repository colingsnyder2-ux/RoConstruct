"""Verify native unlocked-part selection and filter lifetime."""
import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root))
from roc import match,rebuild
donor=root/'rebuild/2008-06/out/RbxgsApp/linked/PartDragTool.obj'
units=[(donor,'??0PartDragTool@RBX@@','00665f20',{'??0MouseCommand@RBX@@':0x6159f0,'??_7PartDragTool@RBX@@6BINamed@':0x84cbb4,'??_7PartDragTool@RBX@@6BIRenderable@':0x84cb9c,'??0RunDragger@RBX@@':0x66c900,'??0MegaDragger@RBX@@':0x60e540}),
       (donor,'??1PartDragTool@RBX@@','00665bd0',{'??1MouseCommand@RBX@@':0x615780,'??_7PartDragTool@RBX@@6BINamed@':0x84cbb4,'??_7PartDragTool@RBX@@6BIRenderable@':0x84cb9c,'??1RunDragger@RBX@@':0x66c400,'??1MegaDragger@RBX@@':0x60e700}),
       (donor,'??_GPartDragTool@RBX@@','00665cc0',{'??1PartDragTool@RBX@@':0x665bd0})]
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
headers=[root/'rebuild/2008-06/tests/NativePartDragToolTrial.h',root/'rebuild/2008-06/native-headers/v8datamodel/MouseCommand.h']
receipt={'observer_sha256':sha(Path(__file__)),'headers':{str(p.relative_to(root)):sha(p) for p in headers},'methods':rows,'scope':'Existing donor object constructor/destructors and selected targets verified against original; all other methods, linked layout and runtime remain unproven.'}
(root/'work/2008-06/shared-layouts/partdrag-lifetime-trial.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS existing PartDragTool constructor and both destructor forms')
