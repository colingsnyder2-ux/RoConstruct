import json,struct,sys,hashlib
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match
p=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));base=p.OPTIONAL_HEADER.ImageBase;u=lambda a:struct.unpack('<I',p.get_data(a-base,4))[0];v=0x8245cc;col=u(v-4);hier=u(col+16);count=u(hier+8);array=u(hier+12);bases=[]
for i in range(count):
 desc=u(array+4*i);name=u(desc);bases.append({'name':p.get_string_at_rva(name+8-base).decode(),'offset':hex(u(desc+8))})
assert [x['name'] for x in bases]==['.?AVProfiledRakPeer@@','.?AVRakPeer@@','.?AVRakPeerInterface@@'] and all(x['offset']=='0x0' for x in bases);assert u(v)==0x4ab830
ctor,_,_=match.target('2008-06','004b4640');assert b'\x68\x10\x09\x00\x00' in ctor and b'\x89\xaf\x08\x09\x00\x00' in ctor and b'\xc7\x07\xcc\x45\x82\x00' in ctor
dtor,_,_=match.target('2008-06','004ab830');assert dtor[0:4]==bytes.fromhex('568bf1e8') and (0x4ab838+struct.unpack_from('<i',dtor,4)[0])&0xffffffff==0x4c4d50
log=(root/'rebuild/2008-06/out/native-layouts/profiled-peer-worker/size.log').read_text();assert 'class RakPeer\tsize(2292)' in log and 'error C2118' in log
result={'scope':'Original RTTI and constructor/destructor binary evidence. +0x908 is borrowed CodeProfiler pointer; original base size and remaining bytes not conclusively established. Donor class size differs from assumed offset; whole-base ABI not verified.','rtti_bases':bases,'vtable':'0x8245cc','vtable_deleting_dtor':'0x4ab830','deleting_dtor_base_call':'0x4c4d50 RakPeer::~RakPeer','original_allocation':'0x910','profiler_pointer_offset':'0x908','constructor':'0x4b4640 inlines base RakPeer::RakPeer 0x4c18d0, writes pointer +0x908 and vtable; no separate derived constructor observed','donor_rakpeer_size':'0x8f4 from native-header-first isolated compile, 0x908 assertion fails; version/layout mismatch','source_inventory':'src/2008-06/004b4640.cpp uses synthetic layout; tools/rbxgs/.../roc_profiled_rakpeer_*.cpp macro-rename RakPeer, not proved real derived class','remaining':'Determine real 2008 RakPeer layout and tail bytes, overridden vtable methods, exact derived lifetime and integration; do not pad or cast.'};(root/'work/2008-06/shared-layouts/profiled-peer-rtti-worker.json').write_text(json.dumps(result,indent=2)+'\n');print('PASS ProfiledRakPeer RTTI/base/dtor; donor size mismatch')
