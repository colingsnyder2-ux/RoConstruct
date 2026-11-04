import sys,json,hashlib,struct
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts/sound-provider-member-worker';overlay=out/'v8tree';overlay.mkdir(parents=True,exist_ok=True);header=(root/'rebuild/2008-06/native-headers/v8tree/Service.h').read_text();assert header.count('    static const ServiceProvider* findServiceProvider(const Instance*);')==1;(overlay/'Service.h').write_text(header)
src=root/'rebuild/2008-06/tests/NativeSoundProviderMemberWorker.cpp';obj=out/'NativeSoundProviderMemberWorker.obj';prior=json.loads((root/'work/2008-06/shared-layouts/instance-ancestor-trial.json').read_text());flags=[x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')];flags.insert(7,'/I'+str(out));flags+=['/Fo'+str(obj),str(src)];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,out);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?findServiceProvider@ServiceProvider@RBX@@'));target,tr,_=match.target('2008-06','004898d0');assert match.exact_match(target,tr,body,refs);start,index=defs[name];table=sections[index];bindings={}
for i in range(table[7]):
 off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
 if 0<=off<len(body)-3:
  value=struct.unpack_from('<I',target,off)[0]
  if kind==20:value=(0x4898d0+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
  bindings[symbols[sym][0]]=hex(value)
assert bindings['??_R0?AVServiceProvider@RBX@@@8']=='0x92e15c' and bindings['??_R0?AVInstance@RBX@@@8']=='0x92907c' and bindings['___RTDynamicCast']=='0x6a17c6';pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));base=pe.OPTIONAL_HEADER.ImageBase;assert pe.get_string_at_rva(0x92e15c-base+8)==b'.?AVServiceProvider@RBX@@' and pe.get_string_at_rva(0x92907c-base+8)==b'.?AVInstance@RBX@@'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Isolated static member declaration matches existing donor; original machine code confirms ABI-compatible implementation and cast RTTI; compiler bytes do not establish original source-level symbol name. No integration/runtime validation.','target':'0x4898d0','exact':True,'size':len(body),'symbol':name,'bindings':bindings,'source_sha256':sha(src),'shadow_header_sha256':sha(overlay/'Service.h'),'object_sha256':sha(obj),'recorder_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/sound-provider-member-worker.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS',name,len(body),bindings)
