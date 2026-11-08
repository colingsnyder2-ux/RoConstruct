"""Verify original tool action body, targets and each original vtable slot."""
import hashlib, json, re, struct, sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[4]
sys.path.insert(0,str(root))
from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts'
source=root/'rebuild/2008-06/experiments/trials/NativeToolVerbActionTrial.cpp'
header=root/'rebuild/2008-06/native-headers/StandardVerbs.h'
base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
obj=out/'NativeToolVerbActionTrial.obj'
flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]+['/Fo'+str(obj),str(source)]
code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,out)
assert code==0,log
raw=obj.read_bytes();functions=match.coff_functions(raw);sections,symbols,defs,_=match._coff_data_index(raw)
original,originalrefs,_=match.target('2008-06','005c6f00')
tools=list(dict.fromkeys(re.findall(r'TToolVerb<(\w+)>\s+\w+;',header.read_text())))
assert len(tools)==26
for tool in tools:
    name,body,refs=next(x for x in functions if x[0].startswith('?doIt@?$TToolVerb@V'+tool+'@RBX@@'))
    assert match.exact_match(original,originalrefs,body,refs),tool
    start,idx=defs[name];section=sections[idx];edges={}
    for i in range(section[7]):
        offset,sym,kind=struct.unpack_from('<IIH',raw,section[5]+10*i);offset-=start
        if 0<=offset<len(body)-3 and kind==20:
            edges[symbols[sym][0]]=(0x5c6f00+offset+4+struct.unpack_from('<i',original,offset)[0])&0xffffffff
    for prefix,target in [('?setDefaultMouseCommand@Workspace@RBX@@',0x5a0610),('?setMouseCommand@Workspace@RBX@@',0x5a1fc0)]:
        assert any(k.startswith(prefix) and v==target for k,v in edges.items()),(tool,prefix,edges)
ctorobj=out/'NativeStandardVerbsConstructorTrial.obj';ctorraw=ctorobj.read_bytes()
name,body,refs=next(x for x in match.coff_functions(ctorraw) if x[0].startswith('??0StandardVerbs@RBX@@'))
ctor,ctorrefs,_=match.target('2008-06','005c7ea0');assert match.exact_match(ctor,ctorrefs,body,refs)
sects,syms,definitions,_=match._coff_data_index(ctorraw);start,idx=definitions[name];section=sects[idx];vtables={}
for i in range(section[7]):
    offset,sym,kind=struct.unpack_from('<IIH',ctorraw,section[5]+10*i);offset-=start
    if not 0<=offset<len(body)-3:continue
    symbol=syms[sym][0]
    for tool in tools:
        if symbol.startswith('??_7?$TToolVerb@V'+tool+'@RBX@@'):
            vtables[tool]=struct.unpack_from('<I',ctor,offset)[0]
assert set(vtables)==set(tools),set(tools)-set(vtables)
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));image=pe.OPTIONAL_HEADER.ImageBase
for tool,vt in vtables.items():
    assert struct.unpack('<I',pe.get_data(vt+16-image,4))[0]==0x5c6f00,(tool,hex(vt))
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
donor=out.parent/'RbxgsApp/linked/Workspace.obj'
donor_functions=match.coff_functions(donor.read_bytes()); workspace_calls=[]
for prefix,address in [('?setDefaultMouseCommand@Workspace@RBX@@','005a0610'),('?setMouseCommand@Workspace@RBX@@','005a1fc0')]:
    symbol,donor_body,donor_refs=next(x for x in donor_functions if x[0].startswith(prefix))
    target,targetrefs,_=match.target('2008-06',address)
    workspace_calls.append({'address':address,'donor_size':len(donor_body),'original_size':len(target),'relocation_normalized_exact':match.exact_match(target,targetrefs,donor_body,donor_refs)})
receipt={'source_sha256':sha(source),'header_sha256':sha(header),'observer_sha256':sha(Path(__file__)),'object_sha256':sha(obj),'ctor_object_sha256':sha(ctorobj),'donor_workspace_sha256':sha(donor),'workspace_donor_calls':workspace_calls,'flags':flags,'address':'005c6f00','size':len(original),'vtables':{k:hex(v) for k,v in vtables.items()},'scope':'Inactive trial. Original 26 action slots and call targets verified; donor Workspace default-command body differs, linked call targets, tool factories, layouts and runtime remain unproven.'}
(root/'work/2008-06/shared-layouts/tool-verb-actions-trial.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS 26 native tool actions and original vtable slots')
