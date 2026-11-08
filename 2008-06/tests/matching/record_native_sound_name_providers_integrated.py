import json,sys,struct,hashlib
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import rebuild,match
prior=json.loads((root/'work/2008-06/shared-layouts/profiling-integrated.json').read_text());flags=[x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')]+['/I'+str(root/'tools/openrbx/3rdparty/fmod/api/inc')];out=root/'rebuild/2008-06/out/native-layouts/sound-name-providers-integrated';out.mkdir(parents=True,exist_ok=True);src=root/'rebuild/2008-06/native-classes/SoundClassName.cpp';obj=out/'SoundClassName.obj';code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log
raw=obj.read_bytes();fs=match.coff_functions(raw);rows=[]
for pre,addr in [('?getClassName@?$FactoryProduct@VSoundService',0x5b8450),('?getClassName@?$FactoryProduct@VSoundChannel',0x5b8470),('?getClassName@?$FactoryProduct@VStockSound',0x5b8490),('??$doDeclare@$1?sStockSound',0x5b6ce0)]:
 n,b,r=next(x for x in fs if x[0].startswith(pre));t,tr,_=match.target('2008-06','%08x'%addr);rows.append({'symbol':n,'address':hex(addr),'size':len(b),'target_size':len(t),'exact':match.exact_match(t,tr,b,r)})
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();result={'scope':'Inactive real factory/name template candidates against native headers, relocations masked; selected addresses and bindings still need verification before link/runtime.','methods':rows,'native_header_sha256':{str(p.relative_to(root)):sha(p) for p in [root/'rebuild/2008-06/native-headers/v8datamodel/GameSettings.h',root/'rebuild/2008-06/native-headers/v8datamodel/GlobalSettings.h',root/'rebuild/2008-06/native-headers/v8tree/Instance.h',root/'rebuild/2008-06/native-headers/util/Sound.h']},'source_sha256':sha(src),'object_sha256':sha(obj),'recorder_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/sound-name-providers-integrated.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(rows,indent=2))
sections,symbols,defs,_=match._coff_data_index(raw)
for row in rows:
 addr=int(row['address'],16);t,_,_=match.target('2008-06','%08x'%addr);start,index=defs[row['symbol']];sec=sections[index];bind={}
 for i in range(sec[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,sec[5]+10*i);off-=start
  if 0<=off<len(t)-3:
   v=struct.unpack_from('<I',t,off)[0]
   if kind==20:v=(addr+off+4+struct.unpack_from('<i',t,off)[0])&0xffffffff
   bind[symbols[sym][0]]=hex(v)
 row['bindings']=bind
res=result;res['methods']=rows;(root/'work/2008-06/shared-layouts/sound-name-providers-integrated.json').write_text(json.dumps(res,indent=2)+'\n');print(json.dumps(rows,indent=2))

import pefile
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));base=pe.OPTIONAL_HEADER.ImageBase;u=lambda a:struct.unpack('<I',pe.get_data(a-base,4))[0]
for vt,addr,typename in [(0x837ac8,0x5b8450,b'.?AVSoundService@Soundscape@RBX@@'),(0x8376ec,0x5b8470,b'.?AVSoundChannel@Soundscape@RBX@@'),(0x8381f4,0x5b8490,b'.?AVStockSound@@')]:
 col=u(vt-4);desc=u(col+12);assert u(col+4)==0x10 and u(vt+4)==addr and pe.get_string_at_rva(desc+8-base)==typename
assert all(x['exact'] for x in rows)
for row, target in zip(rows[:2], ('0x437f20', '0x437f90')):
 assert row['bindings']['?call_once@boost@@YAXP6AXXZAAJ@Z']=='0x557330' and any(k.startswith('??$doDeclare@') and v==target for k,v in row['bindings'].items()), row
stock=rows[2]['bindings'];assert stock['?call_once@boost@@YAXP6AXXZAAJ@Z']=='0x557330' and any(k.startswith('??$callDoDeclare@') and v=='0x5b73b0' for k,v in stock.items()) and any(k.startswith('??$doDeclare@') and v=='0x5b6ce0' for k,v in stock.items());assert rows[3]['bindings']['?sStockSound@@3PADA']=='0x94d304' and rows[3]['bindings']['?declare@Name@RBX@@SAABV12@PBDH@Z']=='0x553f90'
res['scope']='All three getClassName methods and StockSound doDeclare match bytes; original class RTTI/vtable slot and selected StockSound call/data bindings verified. Full class, provider identity and runtime unproven.';res['stock_vtable']='0x8381f4';res['recorder_sha256']=sha(Path(__file__));(root/'work/2008-06/shared-layouts/sound-name-providers-integrated.json').write_text(json.dumps(res,indent=2)+'\n');print('PASS three original RTTI/vtables and StockSound bindings')
