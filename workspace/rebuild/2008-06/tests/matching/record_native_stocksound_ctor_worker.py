import sys,json,hashlib
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import rebuild,match
w=root/'rebuild/2008-06/out/native-layouts/stocksound-ctor-worker';w.mkdir(exist_ok=True);src=root/'rebuild/2008-06/tests/NativeStockSoundCtorWorker.cpp';obj=w/'StockSoundCtor.obj';prior=json.loads((root/'work/2008-06/shared-layouts/profiling-integrated.json').read_text());flags=[x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')]+['/I'+str(root/'tools/openrbx/3rdparty/fmod/api/inc')];c,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],w);(w/'compile.log').write_text(log);print('compile',c,log[-1500:]);rows=[]
if not c:
 for pre,a in [('??0StockSound@@',0x5bd250)]:
  n,b,r=next(x for x in match.coff_functions(obj.read_bytes()) if x[0].startswith(pre));t,tr,_=match.target('2008-06','%08x'%a);rows.append({'symbol':n,'address':hex(a),'size':len(b),'target_size':len(t),'exact':match.exact_match(t,tr,b,r)})
 print(rows)
import struct,pefile
assert not c and rows[0]['exact'];raw=obj.read_bytes();secs,syms,defs,_=match._coff_data_index(raw);n=rows[0]['symbol'];t,tr,_=match.target('2008-06','005bd250');start,idx=defs[n];tab=secs[idx];bindings={}
for i in range(tab[7]):
 off,k,kind=struct.unpack_from('<IIH',raw,tab[5]+10*i);off-=start
 if 0<=off<len(t)-3:
  val=struct.unpack_from('<I',t,off)[0]
  if kind==20:val=(0x5bd250+off+4+struct.unpack_from('<i',t,off)[0])&0xffffffff
  bindings[syms[k][0]]=val
for key,val in [('??0?$DescribedCreatable@VStockSound',0x5bd0f0),('?propArchivable@Instance@',0x973e8c)]:assert any(k.startswith(key) and v==val for k,v in bindings.items()),(key,bindings)
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));base=pe.OPTIONAL_HEADER.ImageBase;read=lambda a,n:pe.get_data(a-base,n);u=lambda a:struct.unpack('<I',read(a,4))[0];vtables=[]
for v,off in [(0x838204,0),(0x8381f4,0x10),(0x838248,0x14),(0x8381ec,0x20),(0x8381dc,0x24),(0x8381cc,0x44),(0x8381bc,0x64),(0x8381ac,0x84),(0x83819c,0xa4),(0x83818c,0xc4),(0x838180,0x130)]:
 col=u(v-4);td=u(col+12);assert u(col+4)==off and read(td+8,30).split(b'\0')[0]==b'.?AVStockSound@@';assert v in bindings.values();vtables.append({'address':hex(v),'offset':hex(off),'rtti':'StockSound'})
assert u(0x8381f4+4)==0x5b8490 and read(0x5bd61f,5)==bytes.fromhex('6870010000')
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Inactive ctor candidate matching native bytes, selected original bindings and StockSound RTTI; original factory allocates 0x170. Base lifetime, selected provider duplicates, final linked vtables and runtime unproven.','methods':rows,'descriptor_base':'0x973e74','descriptor_member':'0x973e8c','vtables':vtables,'bindings':{k:hex(v) for k,v in bindings.items()},'source_sha256':sha(src),'object_sha256':sha(obj),'sound_header_sha256':sha(root/'rebuild/2008-06/native-headers/util/Sound.h'),'instance_header_sha256':sha(root/'rebuild/2008-06/native-headers/v8tree/Instance.h'),'observer_sha256':sha(Path(__file__)),'flags':flags};(root/'work/2008-06/shared-layouts/stocksound-ctor-worker.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS StockSound ctor, original class RTTI, 11 vtables and selected bindings')
