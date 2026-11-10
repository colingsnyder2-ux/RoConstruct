import json,struct,hashlib,sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match
receipt=json.loads((root/'work/2008-06/shared-layouts/sound-lifetime-worker.json').read_text());pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));base=pe.OPTIONAL_HEADER.ImageBase;u=lambda a:struct.unpack('<I',pe.get_data(a-base,4))[0];imports={entry.address:entry.name.decode('ascii') for dll in pe.DIRECTORY_ENTRY_IMPORT for entry in dll.imports if entry.name};vts=[(0x837ad4,0),(0x837ac8,0x10),(0x837ac0,0x14),(0x837ab8,0x20),(0x837aa8,0x24),(0x837a98,0x44),(0x837a88,0x64),(0x837a78,0x84),(0x837a68,0xa4),(0x837a58,0xc4),(0x837a4c,0x130)];rtti=[]
for vt,offset in vts:
 col=u(vt-4);desc=u(col+12);name=pe.get_string_at_rva(desc+8-base).decode('ascii');assert u(col+4)==offset and name=='.?AVSoundService@Soundscape@RBX@@';rtti.append({'vtable':hex(vt),'base_offset':hex(offset),'rtti_name':name})
factory,_,_=match.target('2008-06','00440980');assert b'\x68\xc8\x01\x00\x00' in factory;off=factory.index(b'\xe8',0x40);assert (0x440980+off+5+struct.unpack_from('<i',factory,off+1)[0])==0x5bc160
rows=receipt['methods'];assert all(x['exact'] for x in rows)
for row in rows:
 for k,v in row['bindings'].items():
  if k.startswith('__imp_'):
   assert imports[int(v,16)]==k[len('__imp_'):],(k,v,imports[int(v,16)])
 for vt,_ in vts:assert hex(vt) in row['bindings'].values(),hex(vt)
assert any(k.startswith('?getTick@System@G3D@@') and v=='0x5083d0' for k,v in rows[0]['bindings'].items());assert any(k.startswith('?setName@Instance@RBX@@') and v=='0x55af90' for k,v in rows[0]['bindings'].items());assert pe.get_string_at_rva(0x837e90-base)==b'Soundscape'
result={'scope':'Vtable RTTI, allocation and imported string method identities verified; template helper targets and getTick/setName source identities remain inferred from candidate binding, not independently matched. EH unwind tables and runtime not tested.','factory':'0x440980','factory_malloc_size':'0x1c8','factory_ctor_call':'0x4409c4 -> 0x5bc160','candidate_size':'0x1c8','vtable_rtti':rtti,'methods':rows,'original_sha256':hashlib.sha256(Path(pe.__data__.name).read_bytes()).hexdigest() if hasattr(pe.__data__,'name') else None,'prior_receipt_sha256':hashlib.sha256((root/'work/2008-06/shared-layouts/sound-lifetime-worker.json').read_bytes()).hexdigest()};(root/'work/2008-06/shared-layouts/sound-lifetime-bindings-worker.json').write_text(json.dumps(result,indent=2)+'\n');print('PASS allocation 0x1c8, 11 original vtable RTTI offsets, ctor/dtor imported names; template identities pending')
