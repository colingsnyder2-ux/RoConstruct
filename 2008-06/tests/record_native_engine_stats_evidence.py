import hashlib, json, struct
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[3]; binary=root/'work/2008-06/original-p4-reference/Roblox.exe'; pe=pefile.PE(str(binary)); base=pe.OPTIONAL_HEADER.ImageBase
def data(addr,n): return pe.get_data(addr-base,n)
def rel32(addr): return addr+5+struct.unpack('<i',data(addr+1,4))[0]
assert data(0x57dc40,21)==bytes.fromhex('8b410c8b88040200008b91e40200008b8a84000000')
assert data(0x57dc55,1)==b'\xe8' and rel32(0x57dc55)==0x60cbf0
assert data(0x60cbf0,3)==bytes.fromhex('8b09e9') and rel32(0x60cbf2)==0x47d410
assert data(0x47d410,1)==b'\xc3'
assert struct.unpack('<I',data(0x830680,4))[0]==0x57dc40
assert data(0x591799,1)==b'\xe8' and rel32(0x591799)==0x5ea920
assert data(0x5917a6,6)==bytes.fromhex('8986e4020000')
assert data(0x590737,6)==bytes.fromhex('8b8ee4020000') and data(0x590749,8)==bytes.fromhex('8b118b026a01ffd0')
assert data(0x5ea9b8,1)==b'\xe8' and rel32(0x5ea9b8)==0x60d260 and data(0x5ea9c8,6)==bytes.fromhex('898684000000')
assert struct.unpack('<I',data(0x83f8d8,4))[0]==0x5ead10 and rel32(0x5ead13)==0x5ea5e0
assert data(0x5ea636,6)==bytes.fromhex('8b9e84000000') and rel32(0x5ea642)==0x60ccf0 and rel32(0x5ea648)==0x6a067a
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest(); receipt={'scope':'Original EngineStats call-chain evidence only. Workspace and World lifetime/layout remain unproven; never substitute offset overlays into running client.','original_sha256':sha(binary),'observer_sha256':sha(Path(__file__)),'action':'0x57dc40','vtable_slot':'0x830680','datamodel_workspace':'0x204','workspace_world':'0x2e4','world_contact_manager':'0x84','contact_manager_call':'0x60cbf0','tail_target':'0x47d410','tail_bytes':'c3','root_lifetime':{'constructor':'0x591580','world_ctor_call':'0x591799','world_store':'0x5917a6','destructor':'0x590630','world_virtual_delete':'0x590737'},'world_lifetime':{'constructor':'0x5ea920','contact_ctor_call':'0x5ea9b8','contact_store':'0x5ea9c8','deleting_destructor':'0x5ead10','destructor':'0x5ea5e0','contact_destruction':'0x5ea642'},'source_reference':'tools/rbxgs/Client/App/roc_string_source_00451b60_93913931e0517219.cpp'}; (root/'work/2008-06/shared-layouts/engine-stats-chain.json').write_text(json.dumps(receipt,indent=2)+'\n'); print('PASS original EngineStats call chain')
