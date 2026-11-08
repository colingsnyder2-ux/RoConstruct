import hashlib,json,struct,sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';work=out/'worker-hammer';overlay=work/'include';(overlay/'v8datamodel').mkdir(parents=True,exist_ok=True);(overlay/'reflection').mkdir(parents=True,exist_ok=True)
explosion=root/'tools/rbxgs/Client/App/include/v8datamodel/Explosion.h';data=explosion.read_text();assert data.count('extern const char* sExplosion;')==1 and data.count('&sExplosion')==1;(overlay/'v8datamodel/Explosion.h').write_text(data.replace('extern const char* sExplosion;','extern char sExplosion[];').replace('&sExplosion','sExplosion'))
property_header=root/'tools/rbxgs/Client/App/include/reflection/property.h';data=property_header.read_text();needle='virtual bool isReadOnly() const = 0;\n\t\t\t\tvirtual PropType getValue';assert data.count(needle)==1;(overlay/'reflection/property.h').write_text(data.replace(needle,'virtual bool isReadOnly() const = 0;\n\t\t\t\tvirtual bool isWriteOnly() const = 0;\n\t\t\t\tvirtual PropType getValue'))
base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags[:0]=['/I'+str(overlay),'/I'+str(out/'grab-methods-include'),'/I'+str(out/'workspace-model-vector-include')];rows=[];objs=[];sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
checks=[('NativeHammerMethodsWorkerTrial',[('?onMouseIdle@HammerTool',0x63f710,[('?getUnlockedPartByLocalCharacter@',0x616000),('??$shared_from@VPartInstance@',0x618a40)]),('?render3dAdorn@HammerTool',0x63f6f0,[]),('?getCursorName@HammerTool',0x63f6c0,[]),('?isSticky@HammerTool',0x5c7890,[('??0MouseCommand@',0x6159f0)]),('?getName@?$Named@VMouseCommand@RBX@@$1?sHammerTool',0x5c79b0,[('?callDoDeclare@',0x5c61d0),('?doDeclare@',0x5c5d00),('?call_once@boost@@',0x557330)])]),('NativeHammerClickWorkerTrial',[('?onMouseDown@HammerTool',0x63f7b0,[('??$create@VExplosion@',0x5c0dd0),('?getCoordinateFrame@PartInstance@',0x598cb0),('?propPosition@Explosion@',0x97c008),('?propBlastPressure@Explosion@',0x97c024),('?setParent@Instance@',0x55a8f0),('??$create@VSoundService@',0x5807b0),('?playSound@SoundService@',0x5bd820)])])]
for stem,methods in checks:
 src=root/('rebuild/2008-06/tests/'+stem+'.cpp');obj=work/(stem+'.obj');code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],work);assert code==0,log;objs.append({'source':str(src.relative_to(root)),'source_sha256':sha(src),'object':str(obj.relative_to(root)),'object_sha256':sha(obj)})
 raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);fs=match.coff_functions(raw)
 for prefix,address,expected in methods:
  name,body,refs=next(x for x in fs if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06','%08x'%address);assert match.exact_match(target,targetrefs,body,refs),(prefix,len(body),len(target));start,index=defs[name];table=sections[index];bindings={}
  for i in range(table[7]):
   off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
   if 0<=off<len(body)-3:
    value=struct.unpack_from('<I',target,off)[0]
    if kind==20:value=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
    bindings[symbols[sym][0]]=value
  for key,value in expected:assert any(k.startswith(key) and v==value for k,v in bindings.items()),(key,bindings)
  rows.append({'address':hex(address),'size':len(body),'symbol':name,'bindings':{k:hex(v) for k,v in bindings.items()}})
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));image=pe.OPTIONAL_HEADER.ImageBase;rd=lambda a:struct.unpack('<I',pe.get_data(a-image,4))[0];assert [rd(0x8399ec+i*4) for i in [0,1,2,13,15]]==[0x5c79b0,0x63f7b0,0x63f710,0x5c7890,0x63f6c0];assert rd(0x8399d4+12)==0x63f6f0
receipt={'scope':'Inactive Hammer methods match bytes, original vtable and target bindings. Explosion and GetSet overlay types are ABI hypotheses; no runtime promotion. GetSet has two boolean slots then getter/setter in RTTI-confirmed original vtables; first query identity remains unproven.','methods':rows,'objects':objs,'source_header_sha256':sha(root/'rebuild/2008-06/tests/NativeHammerWorkerTrial.h'),'property_overlay_sha256':sha(overlay/'reflection/property.h'),'explosion_overlay_sha256':sha(overlay/'v8datamodel/Explosion.h'),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/hammer-methods-worker-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS six Hammer virtual/name methods and bindings')
