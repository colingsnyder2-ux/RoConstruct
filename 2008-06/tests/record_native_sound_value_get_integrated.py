import json,sys,hashlib,struct
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import libs,rebuild,match
out=root/'rebuild/2008-06/out/native-layouts/sound-value-get-integrated';out.mkdir(parents=True,exist_ok=True);src=root/'rebuild/2008-06/native-classes/SoundValueGet.cpp';obj=out/'SoundValueGet.obj';inc=[root/'rebuild/2008-06/native-headers',root/'rebuild/2008-06/out/P4SoundAsset/overlay/App/include']+[(libs.LIBS/i).resolve() for i in libs.RECIPES['rbxgs']['include'] if i!='WINSDK']+[root/'tools/openrbx/3rdparty/fmod/api/inc'];defs=(libs.RECIPES['rbxgs']['defines']+' BOOST_ALL_NO_LIB').split();flags=['/nologo','/c','/O2','/Ob1','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj)]+['/I'+str(x) for x in inc]+['/D'+x for x in defs]+[str(src)];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,out);(out/'compile.log').write_text(log);assert code==0,log
raw=obj.read_bytes();f=match.coff_functions(raw);rows=[]
for tp,addr in [('_N',0x40a7e0),('M',0x445f10),('H',0x443960),('VSoundId@Soundscape@RBX@@',0x5b86b0)]:
 pre='??$get@'+tp+'@Value@Reflection@RBX@@';n,b,r=next(x for x in f if x[0].startswith(pre));t,tr,_=match.target('2008-06','%08x'%addr);rows.append({'type':tp,'symbol':n,'address':hex(addr),'size':len(b),'target_size':len(t),'exact':match.exact_match(t,tr,b,r)})
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();res={'scope':'Isolated typed generic Value::get candidate based on original branch semantics; relocation matches masked, runtime and transitive providers unproven.','methods':rows,'source_sha256':sha(src),'object_sha256':sha(obj)};(root/'work/2008-06/shared-layouts/sound-value-get-integrated.json').write_text(json.dumps(res,indent=2)+'\n');print(json.dumps(rows,indent=2))

assert len(rows)==4 and all(row['exact'] for row in rows),rows
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
for row, targets in zip(rows, [('0x40a470','0x56ebb0'),('0x445a80','0x56ed00'),('0x443370','0x56ea60'),('0x5b8000','0x5b8090')]):
 assert set(targets) <= set(row['bindings'].values()),row
res['scope']='Integrated native throwing-reference any_cast and conversion candidate; four byte matches and original helper targets checked, full provider identity/ABI/runtime unproven.';res['methods']=rows;res['recorder_sha256']=sha(Path(__file__));res['headers']={str(p.relative_to(root)):sha(p) for p in (root/'rebuild/2008-06/native-headers/reflection/type.h',root/'rebuild/2008-06/native-headers/util/Sound.h')};(root/'work/2008-06/shared-layouts/sound-value-get-integrated.json').write_text(json.dumps(res,indent=2)+'\n');print('PASS four Value getters and original cast/conversion targets')
