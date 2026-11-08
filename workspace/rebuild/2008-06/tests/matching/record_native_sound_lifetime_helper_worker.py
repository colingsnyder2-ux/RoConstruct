import json,sys,struct,hashlib
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match
p=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));base=p.OPTIONAL_HEADER.ImageBase;u=lambda a:struct.unpack('<I',p.get_data(a-base,4))[0]
rt=[]
for address,vt,token in [(0x5bbec0,0x837d84,b'DescribedCreatable'),(0x5b69e0,0x83745c,b'FactoryProduct')]:
 body,_,_=match.target('2008-06','%08x'%address);assert struct.pack('<I',vt) in body;col=u(vt-4);desc=u(col+12);name=p.get_string_at_rva(desc+8-base);assert token in name and b'SoundService' in name;rt.append({'function':hex(address),'stored_vtable':hex(vt),'rtti':name.decode()})
ctor,_,_=match.target('2008-06','005bc160');dtor,_,_=match.target('2008-06','005bb120')
for addr in [0x5bbec0,0x589190,0x671ae0,0x5083d0,0x55af90]:assert any(ctor[i]==0xe8 and (0x5bc160+i+5+struct.unpack_from('<i',ctor,i+1)[0])&0xffffffff==addr for i in range(len(ctor)-4)),hex(addr)
for addr in [0x5bae40,0x4b16a0,0x5b69e0]:assert any(dtor[i] in (0xe8,0xe9) and (0x5bb120+i+5+struct.unpack_from('<i',dtor,i+1)[0])&0xffffffff==addr for i in range(len(dtor)-4)),hex(addr)
assert b'\x68\x38\x00\x00\x00' not in match.target('2008-06','005b78a0')[0] # push imm8, 0x38
assert match.target('2008-06','005b78a0')[0][:2]==b'\x6a\x38' and match.target('2008-06','00591930')[0][:2]==b'\x6a\x1c'
result={'scope':'Direct call targets checked against original instructions, base identities via RTTI. Container semantic identity remains inferred from equivalent tree behavior/node sizes and member types; not byte-checked as independently compiled native helpers. getTick/setName supported by donor source and original behavior, not independent exact body match.','base_rtti':rt,'map_ctor_targets':{'stock_sounds_0x13c':'0x589190; tree allocates 0x1c-byte node via 0x591930','loaded_0x180_and_0x1a0':'0x671ae0; tree allocates 0x38-byte node via 0x5b78a0'},'map_dtor_targets':{'stock_sounds':'0x4b16a0','loaded_sounds':'0x5bae40'},'getTick':'0x5083d0 uses QueryPerformanceCounter; donor tools/rbxgs/Client/Rendering/g3d/G3Dcpp/System.cpp','setName':'0x55af90 is Instance vtable slot +4, assigns string then raises property notification; donor tools/rbxgs/Client/App/v8tree/Instance.cpp','prior_receipt_sha256':hashlib.sha256((root/'work/2008-06/shared-layouts/sound-lifetime-worker.json').read_bytes()).hexdigest()};(root/'work/2008-06/shared-layouts/sound-lifetime-helper-worker.json').write_text(json.dumps(result,indent=2)+'\n');print('PASS base RTTI + original call edges; map semantics remain inferred')
