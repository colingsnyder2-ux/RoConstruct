import hashlib,json,struct,sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';work=out/'rocket-worker';src=root/'rebuild/2008-06/experiments/trials/NativeRocketLaunchWorkerTrial.cpp';obj=work/'NativeRocketLaunchWorkerTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags[:0]=['/I'+str(out/'workspace-model-vector-include'),'/I'+str(root/'rebuild/2008-06/tests')];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/fp:fast','/Fo'+str(obj),str(src)],work);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?launch@RocketTool@'));target,targetrefs,_=match.target('2008-06','0063e6c0');assert match.exact_match(target,targetrefs,body,refs),(len(body),len(target));start,index=defs[name];table=sections[index];bindings={}
for i in range(table[7]):
 off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
 if 0<=off<len(body)-3:
  value=struct.unpack_from('<I',target,off)[0]
  if kind==20:value=(0x63e6c0+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
  bindings[symbols[sym][0]]=value
for prefix,address in [('?getPart@MouseCommand@',0x615d90),('?zLookDirection@CoordinateFrame@',0x828b60),('?getColumn@Matrix3@',0x513240),('??0CoordinateFrame@',0x4782d0),('?lookAt@CoordinateFrame@',0x518e20),('__real@40a00000',0x81ccbc),('??0Velocity@',0x614170)]:assert any(k.startswith(prefix) and v==address for k,v in bindings.items()),(prefix,bindings)
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));image=pe.OPTIONAL_HEADER.ImageBase;rd=lambda a:struct.unpack('<I',pe.get_data(a-image,4))[0];assert rd(0x839aec+17*4)==0x63e6c0;locator=rd(0x839aec-4);descriptor=rd(locator+12);assert pe.get_string_at_rva(descriptor+8-image)==b'.?AVRocketTool@RBX@@';assert pe.get_data(0x81ccbc-image,4)==struct.pack('<f',5.0)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Inactive rocket launch matches bytes, selected calls/constants and vtable/RTTI; placement, complete class ABI and runtime remain unproven.','address':'0x63e6c0','size':len(body),'bindings':{k:hex(v) for k,v in bindings.items()},'source_sha256':sha(src),'object_sha256':sha(obj),'rocket_header_sha256':sha(root/'rebuild/2008-06/tests/NativeRocketWorkerTrial.h'),'shoot_header_sha256':sha(root/'rebuild/2008-06/tests/NativeSlingshotWorkerTrial.h'),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/rocket-launch-worker-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS Rocket launch bytes, targets and vtable')
