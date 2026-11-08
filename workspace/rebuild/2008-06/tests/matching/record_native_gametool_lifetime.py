"""Verify native GameTool factory and lifetime."""
import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root))
from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts'
base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
common=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
units=[('NativeGameToolFactoryTrial','?newMouseCommand@?$TToolVerb@VGameTool@RBX@@','005c76b0',{'??0GameTool@RBX@@':0x640280}),
       ('NativeGameToolLifetimeTrial','??0GameTool@RBX@@','00640280',{'??0MouseCommand@RBX@@':0x6159f0,'??_7GameTool@RBX@@6BINamed@':0x84a544,'??_7GameTool@RBX@@6BIRenderable@':0x84a52c}),
       ('NativeGameToolLifetimeTrial','??1GameTool@RBX@@','00640220',{'??1MouseCommand@RBX@@':0x615780,'??_7GameTool@RBX@@6BINamed@':0x84a544,'??_7GameTool@RBX@@6BIRenderable@':0x84a52c}),
       ('NativeGameToolLifetimeTrial','??_GGameTool@RBX@@','006402e0',{'??1GameTool@RBX@@':0x640220}),
       ('NativeGameToolLifetimeTrial','?isSticky@GameTool@RBX@@','00640300',{'??0GameTool@RBX@@':0x640280}),
       ('NativeGameToolLifetimeTrial','?getCursorName@GameTool@RBX@@','00617e40',{'__imp_??0?$basic_string@':0x80245c}),
       ('NativeGameToolEventsTrial','?onMouseIdle@GameTool@RBX@@','0063fad0',{}),
       ('NativeGameToolEventsTrial','?onMouseHover@GameTool@RBX@@','00640190',{'?getUnlockedPartByLocalCharacter@MouseCommand@RBX@@':0x616000,'?canDrag@GameTool@RBX@@':0x640150,'??_C@_0P@':0x843c14,'??_C@_0M@':0x833850,'??_C@_0L@':0x843a60}),
       ('NativeGameToolDragTrial','?canDrag@GameTool@RBX@@','00640150',{'?lockedInPlace@PartInstance@RBX@@':0x599530,'?characterCanReach@MouseCommand@RBX@@':0x615880}),
       ('NativeGameToolMouseDownTrial','?onMouseDown@GameTool@RBX@@','00640360',{'?getUnlockedPartByLocalCharacter@MouseCommand@RBX@@':0x616000,'?lockedInPlace@PartInstance@RBX@@':0x599530,'?characterCanReach@MouseCommand@RBX@@':0x615880,'??0PartDragTool@RBX@@':0x665f20}),
       ('NativeGameToolNameTrial','?getName@?$Named@VMouseCommand@RBX@@','00640450',{'?callDoDeclare@?$NativeToolName@VGameTool':0x5c6220,'?call_once@boost@@':0x557330,'?doDeclare@?$NativeToolName@VGameTool':0x5c5f30}),
       ('NativeGameToolNameTrial','?doDeclare@?$NativeToolName@VGameTool','005c5f30',{'?declare@Name@RBX@@':0x553f90,'??_C@':0x961af0}),
       ('NativeGameToolNameTrial','?callDoDeclare@?$NativeToolName@VGameTool','005c6220',{'?doDeclare@?$NativeToolName@VGameTool':0x5c5f30})]
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
headers=[root/'rebuild/2008-06/native-headers/v8datamodel/MouseCommand.h',root/'rebuild/2008-06/native-headers/StandardVerbs.h',root/'rebuild/2008-06/tests/NativeGameToolTrial.h',root/'rebuild/2008-06/tests/NativePartDragToolTrial.h',root/'tools/rbxgs/Client/App/include/v8datamodel/PartInstance.h']
receipt={'observer_sha256':sha(Path(__file__)),'headers':{str(p.relative_to(root)):sha(p) for p in headers},'objects':objects,'methods':rows,'scope':'Inactive layout candidate. GameTool constructor, both destructor forms and factory match. Full virtual slots, GameTool methods, linked callees and runtime ABI remain unproven.'}
(root/'work/2008-06/shared-layouts/gametool-lifetime-trial.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS native GameTool constructor, destructors and factory')
