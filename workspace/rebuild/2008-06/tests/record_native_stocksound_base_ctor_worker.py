import sys,json,hashlib,struct,pefile
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import rebuild,match
w=root/'rebuild/2008-06/out/native-layouts/stocksound-base-ctor-worker';w.mkdir(exist_ok=True);src=root/'rebuild/2008-06/tests/NativeStockSoundBaseCtorWorker.cpp';obj=w/'StockSoundBaseCtor.obj';prior=json.loads((root/'work/2008-06/shared-layouts/profiling-integrated.json').read_text());flags=[x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')]+['/I'+str(root/'tools/openrbx/3rdparty/fmod/api/inc')];c,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],w);(w/'compile.log').write_text(log);print('compile',c,log[-1200:]);
if c:sys.exit(c)
raw=obj.read_bytes();pre='??0?$DescribedCreatable@VStockSound@@';n,b,r=next(x for x in match.coff_functions(raw) if x[0].startswith(pre));t,tr,_=match.target('2008-06','005bd0f0');exact=match.exact_match(t,tr,b,r);print('ctor',n,len(b),len(t),exact)
ss,sy,defs,_=match._coff_data_index(raw);start,idx=defs[n];sec=ss[idx];bindings={}
for i in range(sec[7]):
 o,k,kind=struct.unpack_from('<IIH',raw,sec[5]+i*10);o-=start
 if 0<=o<len(b)-3:
  v=struct.unpack_from('<I',t,o)[0]
  if kind==20:v=(0x5bd0f0+o+4+struct.unpack_from('<i',t,o)[0])&0xffffffff
  bindings[sy[k][0]]=v
print({k:hex(v) for k,v in bindings.items()})
assert exact
for key,val in [('??0?$FactoryProduct@VStockSound',0x5bc960),('?classDescriptor@?$Described@VStockSound',0x5bb8d0)]:assert any(k.startswith(key) and v==val for k,v in bindings.items()),(key,bindings)
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));base=pe.OPTIONAL_HEADER.ImageBase;rd=lambda a,n:pe.get_data(a-base,n);u=lambda a:struct.unpack('<I',rd(a,4))[0];vt=[]
for v,off in [(0x83813c,0),(0x838130,0x10),(0x838128,0x14),(0x838120,0x20),(0x838110,0x24),(0x838100,0x44),(0x8380f0,0x64),(0x8380e0,0x84),(0x8380d0,0xa4),(0x8380c0,0xc4),(0x8380b4,0x130)]:
 col=u(v-4);td=u(col+12);typename=rd(td+8,120).split(b'\0')[0];assert u(col+4)==off and typename.startswith(b'.?AV?$DescribedCreatable@VStockSound@@') and v in bindings.values();vt.append({'address':hex(v),'offset':hex(off),'type':typename.decode()})
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Inactive explicit template instantiation using genuine shared declarations; final link, all base layout/lifetimes and runtime unproven.','address':'0x5bd0f0','symbol':n,'size':len(b),'exact':True,'bindings':{k:hex(v) for k,v in bindings.items()},'vtables':vt,'source_sha256':sha(src),'object_sha256':sha(obj),'reflection_header_sha256':sha(root/'rebuild/2008-06/native-headers/reflection/reflection.h'),'sound_header_sha256':sha(root/'rebuild/2008-06/native-headers/util/Sound.h'),'observer_sha256':sha(Path(__file__)),'flags':flags};(root/'work/2008-06/shared-layouts/stocksound-base-ctor-worker.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS original constructor, selected targets, RTTI and vtables')
