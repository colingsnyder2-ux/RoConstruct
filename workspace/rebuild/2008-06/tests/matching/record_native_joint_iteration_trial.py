"""Verify typed 2008 joint-array iteration without selecting donor pointers."""
import hashlib,json,sys
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root))
from roc import libs,match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';body=root/'rebuild/2008-06/tests/NativeJointIterationTrial.inc'
unit='roc_part_grouped_tail_constructor_9b19d0716f31ff52.cpp'
pre=libs.unit('rbxgs-dll',unit,21022)
ctor=pre.rindex('PartInstance::PartInstance()');opening=pre.index('{',ctor);depth=0
for end in range(opening,len(pre)):
    if pre[end]=='{':depth+=1
    elif pre[end]=='}':
        depth-=1
        if depth==0:break
assert depth==0
text=pre[:ctor]+pre[end+1:]
start=text.index('class __declspec(novtable) Edge : public IPipelined');end=text.index('\n\t};',start)+4
edge=text[start:end];old='Edge* next0;\n\t\tEdge* next1;';assert edge.count(old)==1
edge=edge.replace(old,'int index0;\n\t\tint index1;')
a=edge.index('\t\tEdge* getNext(const Primitive* p) const');b=edge.index('\n\t\tbool links(Primitive*, Primitive*) const;',a)
edge=edge[:a]+'\t\tint getEdgeIndex(const Primitive* p) const { return p == prim0 ? index0 : index1; }\n        Edge* getNext(const Primitive*) const;\n        void setNext(Primitive*, Edge*);'+edge[b:]
source=out/'NativeJointIterationProfile.cpp';source.write_text(text[:start]+edge+text[end:]+'\n'+body.read_text())
ctor_source=out/'NativeJointIterationCtorProfile.cpp';ctor_source.write_text(pre[:start]+edge+pre[end:])
ctor_obj=out/'NativeJointIterationCtorProfile.obj'
ctor_flags=['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(ctor_obj),str(ctor_source)]
code,log=rebuild.run(rebuild.toolchain(21022),'cl',ctor_flags,out);assert code==0,log
name,ctor_body,ctor_refs=next(x for x in match.coff_functions(ctor_obj.read_bytes()) if x[0].startswith('??0PartInstance@RBX@@'))
target,targetrefs,_=match.target('2008-06','0059d4d0');assert match.exact_match(target,targetrefs,ctor_body,ctor_refs)
obj=out/'NativeJointIterationProfile.obj';flags=['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj),str(source)]
code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,out);assert code==0,log
raw=obj.read_bytes();rows=[]
for prefix,address in [('?getFirstJoint@Primitive@RBX@@','005e7b90'),('?getNextJoint@Primitive@RBX@@','005e7ba0')]:
    name,code,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06',address)
    assert match.exact_match(target,targetrefs,code,refs),(address,len(code),len(target))
    rows.append({'address':address,'symbol':name,'size':len(code)})
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
receipt={'observer_sha256':sha(Path(__file__)),'body_sha256':sha(body),'recipe':unit,'preprocessed_sha256':hashlib.sha256(pre.encode()).hexdigest(),'profile_sha256':sha(source),'object_sha256':sha(obj),'flags':flags,'part_constructor':{'address':'0059d4d0','size':len(ctor_body),'object_sha256':sha(ctor_obj),'flags':ctor_flags},'methods':rows,'scope':'Inactive typed profile. Part constructor matches with Edge index fields; Edge constructor/destructor, full Primitive/Part destructors, layouts and runtime ABI remain unproven.'}
(root/'work/2008-06/shared-layouts/joint-iteration-profile.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS native joint first/next iteration in typed profile')
