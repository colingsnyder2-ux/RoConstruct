"""Verify Selection ancestor listener calls and vtable binding from a native batch."""
import hashlib
import json
from pathlib import Path
import struct
import sys
import pefile

ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT))
from roc import match
run=Path(sys.argv[1]);rows=json.loads((run/'results.json').read_text())
event=next(x for x in rows if x['source'].endswith('SelectionAncestorListener.cpp'))
lifetime=next(x for x in rows if x['source'].endswith('SelectionLifetime.cpp'))
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
for row in (event,lifetime):
    assert sha(row['source'])==row['source_sha256'] and sha(row['object'])==row['object_sha256']
    for path,digest in row['dependencies'].items():assert sha(path)==digest,path
    assert all(x['status']=='exact' for x in row['checks'])
raw=Path(event['object']).read_bytes();sections,symbols,definitions,_=match._coff_data_index(raw)
name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?onEvent@Selection@RBX@@'))
target,tr,_=match.target('2008-06','005682e0');assert match.exact_match(target,tr,body,refs)
start,section=definitions[name];table=sections[section];found=[]
for i in range(table[7]):
    offset,index,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);offset-=start
    if kind==20 and 0<=offset<=len(body)-4:
        symbol=symbols[index][0];value=(0x5682e0+offset+4+struct.unpack_from('<i',target,offset)[0])&0xffffffff
        assert struct.unpack_from('<I',body,offset)[0]==0
        found.append((symbol,hex(value)))
assert sum(x[0].startswith('?getRootAncestor@Instance@') and x[1]=='0x42a5f0' for x in found)==2
assert sum(x[0].startswith('?removeFromSelection@Selection@') and x[1]=='0x567c10' for x in found)==1
raw2=Path(lifetime['object']).read_bytes();sec2,sy2,defs2,_=match._coff_data_index(raw2)
vtable=next(n for n in defs2 if n.startswith('??_7Selection@RBX@@6B?$Listener@VInstance@RBX@@UAncestorChanged@'))
start,section=defs2[vtable];table=sec2[section];slots={}
for i in range(table[7]):
    offset,index,kind=struct.unpack_from('<IIH',raw2,table[5]+10*i);offset-=start
    if offset>=0:slots[offset]=sy2[index][0]
assert slots[0]==name
pe=pefile.PE(str(ROOT/'work/2008-06/original-p4-reference/Roblox.exe'))
assert struct.unpack('<I',pe.get_data(0x82ed28-pe.OPTIONAL_HEADER.ImageBase,4))[0]==0x5682e0
result={'scope':'Local listener body, root helper, selected calls and original vtable slot; other vtable entries, linked ownership and runtime unproven.','calls':found,'vtable':vtable,'slot':0,'original_slot_target':'0x5682e0','event_object_sha256':sha(event['object']),'lifetime_object_sha256':sha(lifetime['object']),'run':str(run)}
(ROOT/'work/2008-06/selection-ancestor-proof.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
print('PASS Selection ancestor listener, original calls and vtable slot')
