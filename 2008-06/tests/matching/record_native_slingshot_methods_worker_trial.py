import hashlib,json,struct,sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';work=out/'worker-slingshot';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(out/'workspace-model-vector-include'));rows=[];objects=[];sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
checks=[('NativeSlingshotMethodsWorkerTrial',[],[('?onMouseDown@ShootTool',0x63ec10,[('?shoot@ShootTool',0x63e890)]),('?onMouseIdle@ShootTool',0x63e400,[]),('?onMouseMove@ShootTool',0x63ec40,[('?shoot@ShootTool',0x63e890)]),('?onMouseUp@ShootTool',0x617e70,[]),('?getCursorName@ShootTool',0x63e3b0,[]),('?isSticky@SlingshotTool',0x5c7a80,[('??0ShootTool@',0x63e850)]),('?getName@?$Named@VShootTool@RBX@@$1?sSlingshotTool',0x5c7b80,[('?call_once@boost@@',0x557330),('?doDeclare@',0x5c5bb0)])]),('NativeSlingshotLaunchWorkerTrial',['/fp:fast'],[('?launch@SlingshotTool',0x63e430,[('?getPart@MouseCommand@',0x615d90),('?ballisticAngle@',0x5ded80),('?kmsAccelerationToRbx@',0x660180),('??0PV@RBX@@',0x613e30)]),('?getShootSound@SlingshotTool',0x5cb9d0,[])])]
for stem,extra,methods in checks:
 src=root/('rebuild/2008-06/tests/'+stem+'.cpp');obj=work/(stem+'.obj');code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+extra+['/Fo'+str(obj),str(src)],work);assert code==0,log;objects.append({'source':str(src.relative_to(root)),'source_sha256':sha(src),'object':str(obj.relative_to(root)),'object_sha256':sha(obj)})
 raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);fs=match.coff_functions(raw)
 for prefix,address,expected in methods:
  name,body,refs=next(x for x in fs if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06','%08x'%address);assert match.exact_match(target,targetrefs,body,refs),(prefix,len(body),len(target));start,index=defs[name];table=sections[index];bindings={}
  for i in range(table[7]):
   off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
   if 0<=off<len(body)-3:
    value=struct.unpack_from('<I',target,off)[0]
    if kind==20:value=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
    bindings.setdefault(symbols[sym][0],value)
  for key,value in expected:assert any(k.startswith(key) and v==value for k,v in bindings.items()),(key,bindings)
  rows.append({'address':hex(address),'size':len(body),'symbol':name,'bindings':{k:hex(v) for k,v in bindings.items()}})
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));image=pe.OPTIONAL_HEADER.ImageBase;rd=lambda a:struct.unpack('<I',pe.get_data(a-image,4))[0];assert [rd(0x839a64+i*4) for i in [0,1,2,6,8,13,15,17,18]]==[0x5c7b80,0x63ec10,0x63e400,0x63ec40,0x617e70,0x5c7a80,0x63e3b0,0x63e430,0x5cb9d0];assert pe.get_string_at_rva(0x84a330-image)==b'GunWaitCursor';assert pe.get_string_at_rva(0x839bb4-image)==b'GunCursor'
receipt={'scope':'Inactive slingshot/shoot virtuals match bytes, original vtable and selected target bindings. getShootSound and ballisticAngle names/types provisional; EH/static data and runtime ABI unproven.','methods':rows,'objects':objects,'header_sha256':sha(root/'rebuild/2008-06/tests/NativeSlingshotWorkerTrial.h'),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/slingshot-methods-worker-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS nine Slingshot/Shoot virtuals and bindings')
