import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';src=root/'rebuild/2008-06/experiments/trials/NativeTopLevelPVParentTrial.cpp';header=root/'tools/rbxgs/Client/App/include/v8datamodel/Surface.h';overlay=out/'pv-parent-include/v8datamodel';overlay.mkdir(parents=True,exist_ok=True);data=header.read_text();assert data.count('PartInstance* getPartInstance() const;')==1;patched=overlay/'Surface.h';patched.write_text(data.replace('PartInstance* getPartInstance() const;','PartInstance* getPartInstance() const { return partInstance; }'))
instance=root/'rebuild/2008-06/native-headers/v8tree/Instance.h'; inst=instance.read_text(); assert inst.count('template<class T> const T* getTypedRoot() const')==1; (overlay.parent/'v8tree').mkdir(parents=True,exist_ok=True); (overlay.parent/'v8tree/Instance.h').write_text(inst.replace('template<class T> const T* getTypedRoot() const','template<class T> __declspec(noinline) const T* getTypedRoot() const').replace('return rbx_static_cast<const T*>(parent);','return static_cast<const T*>(parent);').replace('return rbx_static_cast<T*>(parent);','return static_cast<T*>(parent);').replace('        RBXASSERT(dynamic_cast<const T*>(this));\n        const T* typedParent = dynamic_cast<const T*>(parent);\n        return typedParent ? typedParent->getTypedRoot<T>() : static_cast<const T*>(this);', '        const Instance* current = this;\n        const T* typedParent = dynamic_cast<const T*>(current->parent);\n        while (typedParent) { current = typedParent; typedParent = dynamic_cast<const T*>(current->parent); }\n        return static_cast<const T*>(current);'))
obj=out/'NativeTopLevelPVParentTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(overlay.parent));flags.insert(0,'/I'+str(out/'workspace-model-vector-include'));code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);rows=[]
for prefix,address,expected in [('?getTopLevelPVParent@PVInstance@',0x608e20,[('___RTDynamicCast',0x6a17c6),('??$getTypedRoot@VPVInstance@',0x5836d0),('??_R0?AVInstance@',0x92907c),('??_R0?AVPVInstance@',0x947f1c)]),('??$getTypedRoot@VPVInstance@',0x5836d0,[('___RTDynamicCast',0x6a17c6),('??_R0?AVInstance@',0x92907c),('??_R0?AVPVInstance@',0x947f1c)])]:
 name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06','%08x'%address);assert match.exact_match(target,targetrefs,body,refs),(prefix,len(body),len(target))
 start,section=defs[name];table=sections[section];bindings={}
 for i in range(table[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
  if not 0<=off<len(body)-3:continue
  value=struct.unpack_from('<I',target,off)[0]
  if kind==20:value=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
  bindings.setdefault(symbols[sym][0],value)
 for token,value in expected:assert any(k.startswith(token) and v==value for k,v in bindings.items()),(token,bindings)
 rows.append({'address':hex(address),'size':len(body),'symbol':name,'bindings':{k:hex(v) for k,v in bindings.items()}})
link_obj=out/'NativeTopLevelPVParentLink.obj'; link_obj.write_bytes(rebuild.strip_symbols(raw,keep={r['symbol'] for r in rows}))
for row in rows:
 target,targetrefs,_=match.target('2008-06',row['address'][2:].zfill(8)); _,body,refs=next(x for x in match.coff_functions(link_obj.read_bytes()) if x[0]==row['symbol']);assert match.exact_match(target,targetrefs,body,refs)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Parent traversal exact; typed-parent static-cast and noinline-root overlay, complete ABI and runtime unproven. Root helper also matches; provider and complete ABI remain unproven.','methods':rows,'source_sha256':sha(src),'surface_header_sha256':sha(header),'overlay_sha256':sha(patched),'object_sha256':sha(obj),'link_object_sha256':sha(link_obj),'instance_header_sha256':sha(instance),'instance_overlay_sha256':sha(overlay.parent/'v8tree/Instance.h'),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/top-level-pv-parent-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS top-level PV parent and typed root')

