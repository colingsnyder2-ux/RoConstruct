"""Compile setLocked with isolated Instance declaration; layout remains provisional."""
import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';overlay=out/'setlocked-include/v8tree';overlay.mkdir(parents=True,exist_ok=True)
base_header=root/'rebuild/2008-06/native-headers/v8tree/Instance.h';header=base_header.read_text();assert header.count('    void raisePropertyChanged(const Reflection::PropertyDescriptor&')==1;(overlay/'Instance.h').write_text(header)
src=root/'rebuild/2008-06/tests/NativePartSetLockedCompactTrial.cpp';obj=out/'NativePartSetLockedCompactTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags[:0]=['/I'+str(overlay.parent),'/I'+str(out/'workspace-model-vector-include')]
code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?setLocked@PartInstance@'));address=0x59de20;target,targetrefs,_=match.target('2008-06','0059de20');assert match.exact_match(target,targetrefs,body,refs)
start,section=defs[name];table=sections[section];bindings={}
for i in range(table[7]):
 off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
 if not 0<=off<len(body)-3:continue
 value=struct.unpack_from('<I',target,off)[0]
 if kind==20:value=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
 bindings.setdefault(symbols[sym][0],value)
for token,value in [('??_R0?AVPartInstance@',0x92dd50),('??_R0?AVInstance@',0x92907c),('___RTDynamicCast',0x6a17c6),('?prop_Locked@PartInstance@',0x9760cc),('?raisePropertyChanged@Instance@',0x40db00),('?numChildren@Instance@',0x48ae20),('?setLocked@PartInstance@',0x59de20)]:assert any(k.startswith(token) and v==value for k,v in bindings.items()),(token,bindings)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Inactive isolated header overlay and explicit Part offset. Descriptor identity, full shared layout and runtime remain unproven.','address':hex(address),'size':len(body),'exact':True,'bindings':{k:hex(v) for k,v in bindings.items()},'source_sha256':sha(src),'header_sha256':sha(base_header),'overlay_sha256':sha(overlay/'Instance.h'),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__)),'flags':flags};(root/'work/2008-06/shared-layouts/part-set-locked-compact-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS compact Part::setLocked body and bindings')
