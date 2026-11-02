"""Build native Part setLocked from the constructor-matched Part profile."""
import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root))
from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';base=out/'NativePartResizeTrial.cpp';body=root/'rebuild/2008-06/tests/NativePartSetLockedTrial.inc';obj=out/'NativePartSetLockedTrial.obj';link=out/'NativePartSetLockedLink.obj';sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
proof=json.loads((root/'work/2008-06/shared-layouts/part-resize-trial.json').read_text());assert sha(base)==proof['generated_sha256']
s=base.read_text();i=s.rindex('namespace RBX {\ninline const G3D::Vector3& PartInstance::getPartSizeXml');generated=out/'NativePartSetLockedTrial.cpp';generated.write_text(s[:i]+body.read_text())
flags=['/nologo','/c','/O2','/Gy','/GS-','/EHsc','/MD','/Fo'+str(obj),str(generated)];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,out);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);name,data,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?setLocked@PartInstance@'));address=0x59de20;target,targetrefs,_=match.target('2008-06','0059de20');assert match.exact_match(target,targetrefs,data,refs)
start,section=defs[name];table=sections[section];bindings={}
for i in range(table[7]):
 off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
 if not 0<=off<len(data)-3:continue
 value=struct.unpack_from('<I',target,off)[0]
 if kind==20:value=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
 bindings.setdefault(symbols[sym][0],value)
for token,value in [('??_R0?AVPartInstance@',0x92dd50),('??_R0?AVInstance@',0x92907c),('___RTDynamicCast',0x6a17c6),('?prop_Locked@PartInstance@',0x9760cc),('?raisePropertyChanged@Instance@',0x40db00),('?numChildren@Instance@',0x48ae20),('?setLocked@PartInstance@',0x59de20)]:assert any(k.startswith(token) and v==value for k,v in bindings.items()),(token,bindings)
link.write_bytes(rebuild.strip_symbols(raw,keep={name}));_,linkdata,linkrefs=next(x for x in match.coff_functions(link.read_bytes()) if x[0]==name);assert match.exact_match(target,targetrefs,linkdata,linkrefs)
receipt={'scope':'Inactive constructor-matched Part profile; descriptor identity, destructor, shared ABI and runtime unproven.','address':hex(address),'size':len(data),'exact':True,'symbol':name,'bindings':{k:hex(v) for k,v in bindings.items()},'source_sha256':sha(body),'part_profile_sha256':sha(base),'object_sha256':sha(obj),'link_object_sha256':sha(link),'observer_sha256':sha(Path(__file__)),'flags':flags};(root/'work/2008-06/shared-layouts/part-set-locked-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS Part::setLocked and typed bindings')
