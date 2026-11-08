import json,sys,struct,hashlib
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import libs,rebuild,match
out=root/'rebuild/2008-06/out/native-layouts/sound-typed-variant-worker';out.mkdir(parents=True,exist_ok=True);over=root/'rebuild/2008-06/out/native-layouts/sound-property-overlay-worker/overlay';inc=[over,root/'rebuild/2008-06/native-headers',root/'rebuild/2008-06/out/P4SoundAsset/overlay/App/include']+[(libs.LIBS/i).resolve() for i in libs.RECIPES['rbxgs']['include'] if i!='WINSDK']+[root/'tools/openrbx/3rdparty/fmod/api/inc'];defs=(libs.RECIPES['rbxgs']['defines']+' BOOST_ALL_NO_LIB').split();src=root/'rebuild/2008-06/tests/NativeSoundTypedVariantWorker.cpp';obj=out/'NativeSoundTypedVariantWorker.obj';flags=['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj)]+['/I'+str(p) for p in inc]+['/D'+d for d in defs]+[str(src)];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,out);(out/'compile.log').write_text(log);assert code==0,log
raw=obj.read_bytes();f=match.coff_functions(raw);rows=[]
for tp,prefixes in [('_N',(0x443310,0x40a660,0x40aa70)),('M',(0x443310,0x445d40,0x445ff0)),('H',(0x443310,0x443680,0x443c10)),('VSoundId@Soundscape@RBX@@',(0x443310,0x5b8240,0x5b9d90))]:
 for method,addr in zip(['isWriteOnly','getVariant','setVariant'],prefixes):
  pre='?'+method+'@?$TypedPropertyDescriptor@'+tp+'@';n,b,r=next(x for x in f if x[0].startswith(pre));t,tr,_=match.target('2008-06','%08x'%addr);rows.append({'type':tp,'method':method,'address':hex(addr),'size':len(b),'target_size':len(t),'exact':match.exact_match(t,tr,b,r),'symbol':n})
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();res={'scope':'Isolated generic native template candidate, original target slots from sound descriptor vtables, relocation-masked comparison only; no link/runtime proof.','methods':rows,'source_sha256':sha(src),'object_sha256':sha(obj),'overlay_sha256':sha(over/'reflection/property.h')};(root/'work/2008-06/shared-layouts/sound-typed-variant-worker.json').write_text(json.dumps(res,indent=2)+'\n');print(json.dumps(rows,indent=2))
secs,syms,defs,_=match._coff_data_index(raw);p=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));base=p.OPTIONAL_HEADER.ImageBase;u=lambda a:struct.unpack('<I',p.get_data(a-base,4))[0]
for row in rows:
 tp=row['type'];vt={'_N':0x837cd0,'M':0x837c68,'H':0x837c9c,'VSoundId@Soundscape@RBX@@':0x837c34}[tp];slot={'isWriteOnly':2,'getVariant':4,'setVariant':5}[row['method']];assert u(vt+4*slot)==int(row['address'],16);col=u(vt-4);td=u(col+12);assert b'SoundChannel' in p.get_string_at_rva(td+8-base);row['vtable']=hex(vt)
 if row['exact']:
  addr=int(row['address'],16);t,_,_=match.target('2008-06','%08x'%addr);start,index=defs[row['symbol']];sec=secs[index];bind={}
  for i in range(sec[7]):
   off,sym,kind=struct.unpack_from('<IIH',raw,sec[5]+10*i);off-=start
   if 0<=off<len(t)-3:
    value=struct.unpack_from('<I',t,off)[0]
    if kind==20:value=(addr+off+4+struct.unpack_from('<i',t,off)[0])&0xffffffff
    bind[syms[sym][0]]=hex(value)
  row['bindings']=bind
res['methods']=rows;res['scope']='Candidate compiles with 2008 trial reflection overlay. Four original SoundChannel descriptor RTTI vtables establish slots; 10/12 exact relocation-masked, SoundId get/set nonexact; binding mappings recorded but final providers/runtime unproven.';(root/'work/2008-06/shared-layouts/sound-typed-variant-worker.json').write_text(json.dumps(res,indent=2)+'\n');print('PASS four original vtable target sets; exact',sum(x['exact'] for x in rows),'/12')
