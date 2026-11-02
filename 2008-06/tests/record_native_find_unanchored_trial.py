import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';src=root/'rebuild/2008-06/tests/NativeFindUnanchoredTrial.cpp';header=root/'tools/rbxgs/Client/App/include/v8datamodel/Surface.h';overlay=out/'find-unanchored-include/v8datamodel';overlay.mkdir(parents=True,exist_ok=True);data=header.read_text();assert data.count('PartInstance* getPartInstance() const;')==1;patched=overlay/'Surface.h';patched.write_text(data.replace('PartInstance* getPartInstance() const;','PartInstance* getPartInstance() const { return partInstance; }'))
instance=root/'rebuild/2008-06/native-headers/v8tree/Instance.h'; t=instance.read_text(); needle='    Instance();'; assert t.count(needle)==1; (overlay.parent/'v8tree').mkdir(parents=True,exist_ok=True); (overlay.parent/'v8tree/Instance.h').write_text(t.replace(needle,'    struct AnchorAction { bool value; }; void applyAnchoredToChildren(AnchorAction);\n'+needle))
utilities=root/'tools/rbxgs/Client/App/include/util/Utilities.h'; u=utilities.read_text(); needle='boost::shared_ptr<const T> read() const'; assert u.count(needle)==1; (overlay.parent/'util').mkdir(parents=True,exist_ok=True); (overlay.parent/'util/Utilities.h').write_text(u.replace(needle,'__declspec(noinline) '+needle))
obj=out/'NativeFindUnanchoredTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(out/'workspace-model-vector-include'));flags.insert(0,'/I'+str(overlay.parent));code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);rows=[]
for prefix,address,expected in [('?nativeFindUnanchoredPart@',0x63dfe0,[('___RTDynamicCast',0x6a17c6),('??_R0?AVInstance@',0x92907c),('??_R0?AVPartInstance@',0x92dd50),('?getAnchored@PartInstance@',0x598d40),('?read@?$CopyOnWrite@',0x4915b0),('__imp___invalid_parameter_noinfo',0x802890),('?nativeFindUnanchoredPart@',0x63dfe0)]),('?read@?$CopyOnWrite@',0x4915b0,[])]:
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
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Anchor dispatcher matches; child traversal symbol name and Instance ABI provisional.','methods':rows,'source_sha256':sha(src),'surface_header_sha256':sha(header),'overlay_sha256':sha(patched),'object_sha256':sha(obj),'instance_header_sha256':sha(instance),'instance_overlay_sha256':sha(overlay.parent/'v8tree/Instance.h'),'utilities_overlay_sha256':sha(overlay.parent/'util/Utilities.h'),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/find-unanchored-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS find unanchored and bindings')

