import sys,json,struct,hashlib,capstone
from pathlib import Path
root=Path.cwd();sys.path.insert(0,str(root));from roc import match
out=root/'work/2008-06/shared-layouts/sol-mega-cleanup-20261105';base,image=match._image('2008-06');md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
p=root/'work/2008-06/shared-layouts/sol-filesystem-owner-20261105/linked.lib';raw=p.read_bytes();off=8;providers=[]
while off+60<=len(raw):
 size=int(raw[off+48:off+58]);data=raw[off+60:off+60+size];name=raw[off:off+16].decode(errors='replace').strip();off+=60+size+(size&1)
 if data[:2]!=b'\x4c\x01':continue
 try:fs=match.coff_functions(data)
 except Exception:continue
 for sym,body,refs in fs:
  va=0x405e10 if sym=='?destroy@sp_counted_base@detail@boost@@UAEXXZ' else 0x415000 if sym.startswith('??_Gsp_counted_base@detail@boost@@') else None
  if va is None:continue
  secs,syms,defs,starts=match._coff_data_index(data);v,s=defs[sym];sec=secs[s];rel=[]
  for i in range(sec[7]):
   ro,idx,kind=struct.unpack_from('<IIH',data,sec[5]+i*10)
   if v<=ro<v+len(body):
    d=ro-v;target=struct.unpack_from('<I',image,va-base+d)[0]
    if kind==20:target=(va+d+4+struct.unpack_from('<i',image,va-base+d)[0])&0xffffffff
    rel.append(dict(offset=d,kind=kind,symbol=syms[idx][0],original_target=hex(target)))
  original=bytes(image[va-base:va-base+len(body)])
  providers.append(dict(member=name,member_sha256=hashlib.sha256(data).hexdigest(),symbol=sym,address=hex(va),size=len(body),normalized_exact=match.exact_match(original,[],body,refs),relocations=rel))
vt=0x80f1cc;col=struct.unpack_from('<I',image,vt-base-4)[0];td=struct.unpack_from('<I',image,col-base+12)[0];rtti=image[td-base+8:].split(b'\0',1)[0].decode()
headers=['tools/rbxgs/Client/boost_1_34_1/src/boost/detail/sp_counted_base_w32.hpp','tools/rbxgs/Client/boost_1_34_1/src/boost/detail/shared_count.hpp','tools/rbxgs/Client/boost_1_34_1/src/boost/detail/sp_counted_impl.hpp','tools/rbxgs/Client/App/tool/MegaDragger.cpp','tools/rbxgs/Client/App/include/tool/MegaDragger.h']
r=dict(scope='Conditional static graph, no exhaustive controlblock provenance or selected PE proof',providers=providers,part_example=dict(vtable=hex(vt),COL=hex(col),type_descriptor=hex(td),rtti=rtti,slots=[hex(struct.unpack_from('<I',image,vt-base+i*4)[0]) for i in range(4)]),headers_sha256={p:hashlib.sha256((root/p).read_bytes()).hexdigest() for p in headers})
(out/'controlblock-bindings.json').write_text(json.dumps(r,indent=2));print(json.dumps(r,indent=2))
