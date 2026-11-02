import hashlib,json,struct,sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';work=out/'laser-trial';work.mkdir(parents=True,exist_ok=True);header=root/'rebuild/2008-06/native-headers/RbxGraphics/Adorn.h';assert header.read_text().count('virtual void sparkle() = 0;')==1;base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(out/'workspace-model-vector-include'));rows=[];objects=[]
for stem,checks in [('NativeLaserTrial',[('?newMouseCommand@?$TToolVerb@VLaserTool',0x5c7de0,[('??2@',0x6a0920),('??0MouseCommand@',0x6159f0),('??_7LaserTool@RBX@@6BINamed',0x839b74),('??_7LaserTool@RBX@@6BIRenderable',0x839b58)]),('?isChecked@?$TToolVerb@VLaserTool',0x5c7db0,[('___RTtypeid',0x6a1de2),('??_R0?AVLaserTool@',0x950bfc)]),('??_GLaserTool@',0x5c7d90,[('??1MouseCommand@',0x615780),('??3@',0x6a067a)])]),('NativeLaserMethodsTrial',[('?getCursorName@LaserTool',0x5c7cd0,[]),('?isSticky@LaserTool',0x5c7d00,[('??0MouseCommand@',0x6159f0)]),('?getName@?$Named@VMouseCommand@RBX@@$1?sLaserTool',0x5c7e80,[('?call_once@boost@@',0x557330)])]),('NativeLaserRenderTrial',[('?render3dAdorn@LaserTool',0x63f8c0,[('??0CoordinateFrame@',0x4782d0),('?red@Color3@',0x5148b0),('?fromTwoPoints@LineSegment@',0x525ed0),('__real@40a00000',0x81ccbc)])])]:
 src=root/('rebuild/2008-06/tests/'+stem+'.cpp');obj=work/(stem+'.obj');code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],work);assert code==0,log;raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);fs=match.coff_functions(raw)
 for prefix,address,expected in checks:
  name,body,refs=next(x for x in fs if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06','%08x'%address);assert match.exact_match(target,targetrefs,body,refs),(name,len(body),len(target));start,index=defs[name];table=sections[index];bindings={}
  for i in range(table[7]):
   off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
   if 0<=off<len(body)-3:
    value=struct.unpack_from('<I',target,off)[0]
    if kind==20:value=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
    bindings[symbols[sym][0]]=value
  for key,value in expected:assert any(k.startswith(key) and v==value for k,v in bindings.items()),(key,bindings)
  rows.append({'address':hex(address),'size':len(body),'symbol':name,'bindings':{k:hex(v) for k,v in bindings.items()}})
 objects.append({'source':str(src.relative_to(root)),'object':str(obj.relative_to(root)),'source_sha256':hashlib.sha256(src.read_bytes()).hexdigest(),'object_sha256':hashlib.sha256(obj.read_bytes()).hexdigest()})
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));image=pe.OPTIONAL_HEADER.ImageBase;rd=lambda a:struct.unpack('<I',pe.get_data(a-image,4))[0];assert rd(0x839b74+0x30)==0x5c7d90 and rd(0x839b58+0xc)==0x63f8c0;descriptor=rd(rd(0x839b74-4)+12);assert pe.get_string_at_rva(descriptor+8-image)==b'.?AVLaserTool@RBX@@'
adorn_vtable=0x819d24;adorn_descriptor=rd(rd(adorn_vtable-4)+12);assert pe.get_string_at_rva(adorn_descriptor+8-image)==b'.?AVAdornG3D@RBX@@';assert rd(adorn_vtable+0x4c)==0x47d410 and rd(adorn_vtable+0x50)==0x6765f0 and rd(adorn_vtable+0x54)==0x676630 and rd(adorn_vtable+0x58)==0x676660
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Inactive Laser factory, destructor, cursor, sticky, name and render byte match. Original AdornG3D RTTI confirms render slot; sparkle slot identity evidenced separately. Field semantics, lifetime and runtime ABI unproven.','methods':rows,'objects':objects,'adorn_vtable':hex(adorn_vtable),'adorn_ray_slot':'0x54','adorn_line_slot':'0x58','adorn_header_sha256':sha(header),'header_sha256':sha(root/'rebuild/2008-06/tests/NativeLaserTrial.h'),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/laser-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS seven Laser methods, RTTI and bindings; runtime ABI provisional')

