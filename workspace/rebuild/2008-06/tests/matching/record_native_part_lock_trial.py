"""Verify Part lock body in recovered 2008 typed declaration profile."""
import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root))
from roc import libs,match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';out.mkdir(exist_ok=True)
unit='roc_part_grouped_tail_constructor_9b19d0716f31ff52.cpp'
bodyfile=root/'rebuild/2008-06/tests/NativePartLockTrial.inc'
preprocessed=libs.unit('rbxgs-dll',unit,21022)
start=preprocessed.rindex('PartInstance::PartInstance()');opening=preprocessed.index('{',start);depth=0
for end in range(opening,len(preprocessed)):
    if preprocessed[end]=='{':depth+=1
    elif preprocessed[end]=='}':
        depth-=1
        if depth==0:break
assert depth==0
sources=[out/'NativePartLockBaseline.cpp',out/'NativePartLockProfile.cpp']
sources[0].write_text(preprocessed)
sources[1].write_text(preprocessed[:start]+preprocessed[end+1:]+'\n'+bodyfile.read_text())
objects=[];flags=[]
for source in sources:
    obj=source.with_suffix('.obj');f=['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj),str(source)]
    code,log=rebuild.run(rebuild.toolchain(21022),'cl',f,out);assert code==0,log
    objects.append(obj);flags.append(f)
rows=[]
for obj,prefix,address,expected in [(objects[0],'??0PartInstance@RBX@@','0059d4d0',{}),
        (objects[1],'?lockedInPlace@PartInstance@RBX@@','00599530',{'?getFirstJoint@Primitive@RBX@@':0x5e7b90,'?getNextJoint@Primitive@RBX@@':0x5e7ba0,'?Matrix3ToNormalId@RBX@@':0x5ec310,'?normalIdOpposite@RBX@@':0x5ec180})]:
    raw=obj.read_bytes();name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06',address)
    assert match.exact_match(target,targetrefs,body,refs),(address,len(body),len(target))
    sections,symbols,definitions,_=match._coff_data_index(raw);start,index=definitions[name];section=sections[index];found={}
    for i in range(section[7]):
        offset,sym,kind=struct.unpack_from('<IIH',raw,section[5]+10*i);offset-=start
        if not 0<=offset<len(body)-3:continue
        value=struct.unpack_from('<I',target,offset)[0]
        if kind==20:value=(int(address,16)+offset+4+struct.unpack_from('<i',target,offset)[0])&0xffffffff
        for key,wanted in expected.items():
            if symbols[sym][0].startswith(key):assert value==wanted,(key,hex(value));found[key]=hex(value)
    assert set(found)==set(expected),(address,found)
    rows.append({'address':address,'size':len(body),'targets':found})
donor=root/'rebuild/2008-06/out/RbxgsApp/linked/Primitive.obj';f=match.coff_functions(donor.read_bytes());comparison=[]
for prefix,address in [('?getFirstJoint@Primitive@RBX@@','005e7b90'),('?getNextJoint@Primitive@RBX@@','005e7ba0')]:
    n,b,r=next(x for x in f if x[0].startswith(prefix));t,tr,_=match.target('2008-06',address)
    comparison.append({'address':address,'donor_size':len(b),'original_size':len(t),'relocation_normalized_exact':match.exact_match(t,tr,b,r)})
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
receipt={'observer_sha256':sha(Path(__file__)),'body_sha256':sha(bodyfile),'recipe':'rbxgs-dll','unit':unit,'preprocessed_sha256':hashlib.sha256(preprocessed.encode()).hexdigest(),'objects':[sha(x) for x in objects],'flags':flags,'methods':rows,'donor_primitive_sha256':sha(donor),'donor_edge_methods':comparison,'scope':'Inactive typed 2008 profile. Constructor and lock body match; source recipe uses provisional Guid declarations. Destructor, complete Part/Primitive/Joint layouts, virtual bindings and runtime remain unproven. Donor next-joint method differs.'}
(root/'work/2008-06/shared-layouts/part-lock-profile.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS Part lock and constructor in typed 2008 profile; donor next-joint differs')
