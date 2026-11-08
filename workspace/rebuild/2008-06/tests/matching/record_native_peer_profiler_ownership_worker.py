import json,struct,sys,hashlib
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match
p=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));base=p.OPTIONAL_HEADER.ImageBase;u=lambda a:struct.unpack('<I',p.get_data(a-base,4))[0]
def call(a):
 d=p.get_data(a-base,5);assert d[0]==0xe8;return (a+5+struct.unpack_from('<i',d,1)[0])&0xffffffff
for v,off,fn in [(0x824938,0x10,0x4ac940),(0x824898,0x130,0x4ac960),(0x82488c,0x134,0x4ac970)]:
 col=u(v-4);desc=u(col+12);assert u(col+4)==off and p.get_string_at_rva(desc+8-base)==b'.?AVPeer@Network@RBX@@';assert u(v)==fn if off!=0x134 else u(v+4)==fn
for a,target in [(0x4ac943,0x4ad7a0),(0x4ac966,0x4ad7a0),(0x4ac976,0x4ad7a0)]:
 d=p.get_data(a-base,5);assert d[0]==0xe9 and (a+5+struct.unpack_from('<i',d,1)[0])&0xffffffff==target
assert call(0x4ad7a3)==0x4ac830 and call(0x4b4713)==0x5c43a0;v=0x838c5c;col=u(v-4);desc=u(col+12);assert p.get_string_at_rva(desc+8-base)==b'.?AVCodeProfiler@Profiling@RBX@@' and u(v)==0x5c3ed0
ctor,_,_=match.target('2008-06','004b4640');dtor,_,_=match.target('2008-06','004ac830');assert b'\x89\x86\x3c\x01\x00\x00' in ctor and b'\x8b\x8e\x3c\x01\x00\x00' in dtor
result={'scope':'Original RTTI, vtable, ctor and destructor evidence. Peer source implementation and runtime integration are not established.','peer_ctor':'0x4b4640 allocates 0xc048, invokes CodeProfiler ctor 0x5c43a0, stores returned pointer at Peer+0x13c','peer_destructor':'0x4ac830 first deletes Peer+0x140 RakPeer, then loads Peer+0x13c at 0x4ac8e2 and invokes virtual scalar-deleting destructor slot 0 with argument 1','peer_deleting_destructor':'0x4ad7a0 calls 0x4ac830; vtable thunks 0x4ac940/0x4ac960/0x4ac970 adjust Peer subobject pointers','codeprofiler_type':'ctor 0x5c43a0 sets vtable 0x838c5c; RTTI class CodeProfiler; vtable slot 0 -> scalar deleting destructor 0x5c3ed0','order':'RakPeer destructed before CodeProfiler, matching RakPeer stores profiler non-owning pointer at +0x908','original_sha256':hashlib.sha256((root/'work/2008-06/original-p4-reference/Roblox.exe').read_bytes()).hexdigest()};(root/'work/2008-06/shared-layouts/peer-profiler-ownership-worker.json').write_text(json.dumps(result,indent=2)+'\n');print('PASS Peer RTTI destructor thunks, CodeProfiler RTTI and ownership offset')
