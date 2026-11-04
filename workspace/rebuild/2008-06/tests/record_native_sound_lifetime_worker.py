import json,sys,hashlib
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import libs,rebuild,match
spec=json.loads((root/'rebuild/2008-06/modules/p4-sound-asset.json').read_text());layer=spec['layers'][0];out=root/'rebuild/2008-06/out/native-layouts/sound-lifetime-worker';out.mkdir(parents=True,exist_ok=True);src=root/'rebuild/2008-06/tests/PlayerNativeSoundService.cpp';obj=out/'PlayerNativeSoundService.obj';inc=[root/'rebuild/2008-06/native-headers',root/'rebuild/2008-06/out/P4SoundAsset/overlay/App/include']+[(libs.LIBS/i).resolve() for i in libs.RECIPES['rbxgs']['include'] if i!='WINSDK']+[root/p for p in layer['extra_includes']];defs=(libs.RECIPES['rbxgs']['defines']+' '+layer['extra_defines']).split();args=['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/d1reportSingleClassLayoutSoundService','/Fo'+str(obj)]+['/I'+str(p) for p in inc]+['/D'+d for d in defs]+[str(src)];code,log=rebuild.run(rebuild.toolchain(21022),'cl',args,out);(out/'compile.log').write_text(log);assert code==0,log
raw=obj.read_bytes();functions=match.coff_functions(raw);rows=[]
for pre,addr in [('??0SoundService@Soundscape@RBX@@',0x5bc160),('??1SoundService@Soundscape@RBX@@',0x5bb120)]:
 name,body,refs=next(x for x in functions if x[0].startswith(pre));target,tr,_=match.target('2008-06','%08x'%addr);rows.append({'symbol':name,'target':hex(addr),'candidate_size':len(body),'target_size':len(target),'exact':match.exact_match(target,tr,body,refs)})
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();result={'scope':'Current shared headers and PlayerNativeSoundService.cpp compiled isolated; equality masks relocations, not bindings. Layout compile log is evidence; no runtime integration performed.','methods':rows,'source_sha256':sha(src),'object_sha256':sha(obj),'native_sound_header_sha256':sha(root/'rebuild/2008-06/native-headers/util/Sound.h'),'recorder_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/sound-lifetime-worker.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result,indent=2))
import struct
sections,symbols,defs,_=match._coff_data_index(raw)
for row in rows:
 name=row['symbol'];start,index=defs[name];section=sections[index];target,_,_=match.target('2008-06',row['target'][2:].zfill(8));bindings={}
 for i in range(section[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,section[5]+10*i);off-=start
  if 0<=off<len(target)-3:
   value=struct.unpack_from('<I',target,off)[0]
   if kind==20:value=(int(row['target'],16)+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
   bindings[symbols[sym][0]]=hex(value)
 row['bindings']=bindings
result['scope']='Current shared headers; lifetime exact with relocations masked; bindings recorded but not all independently validated. Layout and live runtime remain unproven.';result['candidate_size']='0x1c8';result['layout_log_sha256']=sha(out/'compile.log');(root/'work/2008-06/shared-layouts/sound-lifetime-worker.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(rows,indent=2))
