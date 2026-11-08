"""Verify default-command implementation in original 2008 Workspace profile."""
import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root))
from roc import libs,match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';unit='roc_espclaude_164c05053810c4f5.cpp'
interface=root/'rebuild/2008-06/tests/NativeWorkspaceMouseInterfaceTrial.inc';body=root/'rebuild/2008-06/tests/NativeWorkspaceDefaultTrial.inc'
pre=libs.unit('rbxgs-dll',unit,21022);old='class MouseCommand { public: virtual ~MouseCommand(); };';assert pre.count(old)==1
pre=pre.replace(old,interface.read_text().strip(),1);old='Workspace(IDataState* dataState);';assert pre.count(old)==1
pre=pre.replace(old,'void setDefaultMouseCommand();\n    '+old,1)
start=pre.index('Workspace::Workspace(IDataState* dataState)');opening=pre.index('{',start);depth=0
for end in range(opening,len(pre)):
    if pre[end]=='{':depth+=1
    elif pre[end]=='}':
        depth-=1
        if depth==0:break
assert depth==0
sources=[out/'NativeWorkspaceDefaultCtorProfile.cpp',out/'NativeWorkspaceDefaultProfile.cpp'];sources[0].write_text(pre);sources[1].write_text(pre[:start]+pre[end+1:]+'\n'+body.read_text())
objects=[];allflags=[]
for source in sources:
    obj=source.with_suffix('.obj');flags=['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj),str(source)]
    code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,out);assert code==0,log
    objects.append(obj);allflags.append(flags)
rows=[]
for obj,prefix,address,expected in [(objects[0],'??0Workspace@RBX@@','005a4d90',{}),(objects[1],'?setDefaultMouseCommand@Workspace@RBX@@','005a0610',{'?createDefaultMouseCommand@RBX@@':0x5a0280})]:
    raw=obj.read_bytes();name,code,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06',address)
    assert match.exact_match(target,targetrefs,code,refs),(address,len(code),len(target))
    sections,symbols,definitions,_=match._coff_data_index(raw);start,idx=definitions[name];section=sections[idx];found={}
    for i in range(section[7]):
        offset,sym,kind=struct.unpack_from('<IIH',raw,section[5]+10*i);offset-=start
        if not 0<=offset<len(code)-3:continue
        value=struct.unpack_from('<I',target,offset)[0]
        if kind==20:value=(int(address,16)+offset+4+struct.unpack_from('<i',target,offset)[0])&0xffffffff
        for key,wanted in expected.items():
            if symbols[sym][0].startswith(key):assert value==wanted,(key,hex(value));found[key]=hex(value)
    assert set(found)==set(expected),(address,found)
    rows.append({'address':address,'size':len(code),'targets':found})
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
receipt={'observer_sha256':sha(Path(__file__)),'interface_sha256':sha(interface),'body_sha256':sha(body),'recipe':unit,'profile_sha256':hashlib.sha256(pre.encode()).hexdigest(),'objects':[sha(p) for p in objects],'flags':allflags,'methods':rows,'scope':'Inactive profile. Workspace constructor and default command match, but profile has partial MouseCommand declaration and provisional Workspace bases; native destructor, full vtable, linked ownership and runtime ABI remain unproven.'}
(root/'work/2008-06/shared-layouts/workspace-default-profile.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS native Workspace constructor and default-command profile')
