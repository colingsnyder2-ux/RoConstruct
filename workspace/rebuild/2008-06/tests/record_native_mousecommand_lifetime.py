"""Verify native MouseCommand lifetime and ArrowTool factory shared layout."""
import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root))
from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts'
base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
common=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
units=[('NativeMouseCommandLifetimeTrial','??0MouseCommand@RBX@@','006159f0',{'??_7MouseCommand@RBX@@6BINamed@':0x8439fc,'??_7MouseCommand@RBX@@6BIRenderable@':0x8439e0}),
       ('NativeMouseCommandLifetimeTrial','??1MouseCommand@RBX@@','00615780',{'??_7MouseCommand@RBX@@6BINamed@':0x8439fc,'??_7MouseCommand@RBX@@6BIRenderable@':0x8439e0,'??1IRenderable@RBX@@':0x47d410}),
       ('NativeMouseCommandLifetimeTrial','??_GMouseCommand@RBX@@','00615a20',{'??_7MouseCommand@RBX@@6BINamed@':0x8439fc,'??_7MouseCommand@RBX@@6BIRenderable@':0x8439e0,'??1IRenderable@RBX@@':0x47d410}),
       ('NativeArrowFactoryTrial','?newMouseCommand@?$TToolVerb@VArrowTool@RBX@@','005c6270',{'??0MouseCommand@RBX@@':0x6159f0,'??_7ArrowTool@RBX@@6BINamed@':0x8336a4,'??_7ArrowTool@RBX@@6BIRenderable@':0x833688})]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();objects={};rows=[]
for unit,prefix,address,expected in units:
    source=root/'rebuild/2008-06/tests'/(unit+'.cpp');obj=out/(unit+'.obj')
    if unit not in objects:
        flags=common+['/Fo'+str(obj),str(source)];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,out);assert code==0,log
        objects[unit]={'source_sha256':sha(source),'object_sha256':sha(obj),'flags':flags}
    raw=obj.read_bytes();name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target,targetrefs,_=match.target('2008-06',address);assert match.exact_match(target,targetrefs,body,refs),(address,len(body),len(target))
    sections,symbols,definitions,_=match._coff_data_index(raw);start,idx=definitions[name];section=sections[idx];found={}
    for i in range(section[7]):
        offset,sym,kind=struct.unpack_from('<IIH',raw,section[5]+10*i);offset-=start
        if not 0<=offset<len(body)-3:continue
        value=struct.unpack_from('<I',target,offset)[0]
        if kind==20:value=(int(address,16)+offset+4+struct.unpack_from('<i',target,offset)[0])&0xffffffff
        for key,wanted in expected.items():
            if symbols[sym][0].startswith(key):assert value==wanted,(address,key,hex(value));found[key]=hex(value)
    assert set(found)==set(expected),(address,found)
    rows.append({'address':address,'size':len(body),'targets':found})
headers=[root/'rebuild/2008-06/native-headers/v8datamodel/MouseCommand.h',root/'rebuild/2008-06/native-headers/StandardVerbs.h',root/'tools/rbxgs/Client/App/include/tool/ToolsArrow.h']
receipt={'observer_sha256':sha(Path(__file__)),'headers':{str(p.relative_to(root)):sha(p) for p in headers},'objects':objects,'methods':rows,'scope':'Inactive layout candidate. MouseCommand constructor and scalar-deleting destructor match, Arrow factory matches. Full virtual slots, Arrow lifetime, linked callees and runtime ABI remain unproven.'}
(root/'work/2008-06/shared-layouts/mousecommand-lifetime-trial.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS native MouseCommand constructor, deleting destructor and ArrowTool factory')
