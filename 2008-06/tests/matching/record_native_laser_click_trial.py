import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';work=out/'laser-click-trial';inc=work/'include';(inc/'v8tree').mkdir(parents=True,exist_ok=True);(inc/'v8datamodel').mkdir(parents=True,exist_ok=True);(inc/'reflection').mkdir(parents=True,exist_ok=True)
s=(root/'rebuild/2008-06/native-headers/v8tree/Instance.h').read_text();assert s.count('void removeAllChildren();')==1;(inc/'v8tree/Instance.h').write_text(s.replace('void removeAllChildren();','void removeAllChildren();\n    void remove();'))
s=(root/'tools/rbxgs/Client/App/include/v8datamodel/Explosion.h').read_text();assert s.count('extern const char* sExplosion;')==1 and s.count('&sExplosion')==1;(inc/'v8datamodel/Explosion.h').write_text(s.replace('extern const char* sExplosion;','extern char sExplosion[];').replace('&sExplosion','sExplosion'))
s=(root/'tools/rbxgs/Client/App/include/reflection/property.h').read_text();needle='virtual bool isReadOnly() const = 0;\n\t\t\t\tvirtual PropType getValue';assert s.count(needle)==1;(inc/'reflection/property.h').write_text(s.replace(needle,'virtual bool isReadOnly() const = 0;\n\t\t\t\tvirtual bool isWriteOnly() const = 0;\n\t\t\t\tvirtual PropType getValue'))
src=root/'rebuild/2008-06/experiments/trials/NativeLaserClickTrial.cpp';obj=work/'NativeLaserClickTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags[:0]=['/I'+str(inc),'/I'+str(out/'workspace-model-vector-include')];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],work);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?onMouseDown@LaserTool'));target,targetrefs,_=match.target('2008-06','0063f970');assert match.exact_match(target,targetrefs,body,refs);start,index=defs[name];table=sections[index];bindings={}
for i in range(table[7]):
 off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
 if 0<=off<len(body)-3:
  value=struct.unpack_from('<I',target,off)[0]
  if kind==20:value=(0x63f970+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
  bindings[symbols[sym][0]]=value
for prefix,address in [('?getLocalHeadFromContext@Humanoid@',0x5d7990),('?getCoordinateFrame@PartInstance@',0x598cb0),('?getPart@MouseCommand@',0x615d90),('??$create@VExplosion@',0x5c0dd0),('?propPosition@Explosion@',0x97c008),('?propBlastPressure@Explosion@',0x97c024),('?setParent@Instance@',0x55a8f0),('?remove@Instance@',0x55b4a0),('??$create@VSoundService@',0x5807b0),('?playSound@SoundService@',0x5bd820)]:assert any(k.startswith(prefix) and v==address for k,v in bindings.items()),(prefix,bindings)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Inactive Laser click matches bytes and selected target bindings. Overlay signatures, dynamic types and runtime ABI unproven.','address':'0x63f970','size':len(body),'bindings':{k:hex(v) for k,v in bindings.items()},'source_sha256':sha(src),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__)),'overlays':{str(p.relative_to(work)):sha(p) for p in inc.rglob('*.h')}};(root/'work/2008-06/shared-layouts/laser-click-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS Laser click bytes and targets; ABI provisional')

