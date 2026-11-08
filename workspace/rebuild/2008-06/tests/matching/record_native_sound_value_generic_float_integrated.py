import json,sys,hashlib,struct
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import libs,rebuild,match
out=root/'rebuild/2008-06/out/native-layouts/sound-value-generic-float-integrated';out.mkdir(parents=True,exist_ok=True);src=root/'rebuild/2008-06/native-classes/SoundValueGenericFloat.cpp';obj=out/'SoundValueGenericFloat.obj';inc=[root/'rebuild/2008-06/native-headers',root/'rebuild/2008-06/out/P4SoundAsset/overlay/App/include']+[(libs.LIBS/i).resolve() for i in libs.RECIPES['rbxgs']['include'] if i!='WINSDK']+[root/'tools/openrbx/3rdparty/fmod/api/inc'];defs=(libs.RECIPES['rbxgs']['defines']+' BOOST_ALL_NO_LIB').split();flags=['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj)]+['/I'+str(x) for x in inc]+['/D'+x for x in defs]+[str(src)];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,out);(out/'compile.log').write_text(log);assert code==0,log
raw=obj.read_bytes();f=match.coff_functions(raw);rows=[]
for tp,addr in [('M',0x56d650)]:
 pre='??$genericConvert@'+tp+'@Value@Reflection@RBX@@';n,b,r=next(x for x in f if x[0].startswith(pre));t,tr,_=match.target('2008-06','%08x'%addr);rows.append({'type':tp,'symbol':n,'address':hex(addr),'size':len(b),'target_size':len(t),'exact':match.exact_match(t,tr,b,r)})
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();res={'scope':'Isolated typed generic Value::get candidate based on original branch semantics; relocation matches masked, runtime and transitive providers unproven.','methods':rows,'source_sha256':sha(src),'object_sha256':sha(obj)};(root/'work/2008-06/shared-layouts/sound-value-generic-float-integrated.json').write_text(json.dumps(res,indent=2)+'\n');print(json.dumps(rows,indent=2))

assert len(rows)==1 and all(row['exact'] for row in rows),rows
sections,symbols,definitions,_=match._coff_data_index(raw)
for row in rows:
 address=int(row['address'],16);target,_,_=match.target('2008-06','%08x'%address);start,index=definitions[row['symbol']];table=sections[index];bindings={}
 for i in range(table[7]):
  offset,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);offset-=start
  if 0<=offset<len(target)-3:
   value=struct.unpack_from('<I',target,offset)[0]
   if kind==20:value=(address+offset+4+struct.unpack_from('<i',target,offset)[0])&0xffffffff
   bindings[symbols[sym][0]]=hex(value)
 row['bindings']=bindings
assert {'0x415c90','0x5be790','0x4459a0','0x56cca0','0x415c10','0x509b10'} <= set(rows[0]['bindings'].values()),rows[0]['bindings']
res['scope']='Native generic float conversion byte match; relocated targets recorded, provider ABI and runtime unproven.';res['methods']=rows;res['recorder_sha256']=sha(Path(__file__));res['headers']={str(p.relative_to(root)):sha(p) for p in (root/'rebuild/2008-06/native-headers/reflection/type.h',)};(root/'work/2008-06/shared-layouts/sound-value-generic-float-integrated.json').write_text(json.dumps(res,indent=2)+'\n');print('PASS generic float converter 0056d650')
