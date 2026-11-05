"""Verify Selection lifetime vtable bindings from a fresh native batch."""
import hashlib
import json
from pathlib import Path
import struct
import sys

ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT))
from roc import match
run=Path(sys.argv[1])
rows=json.loads((run/'results.json').read_text())
row=next(x for x in rows if x['source'].endswith('SelectionLifetime.cpp'))
assert all(x['status']=='exact' for x in row['checks']),row['checks']
assert any(x['source'].endswith('NativeSelectionLayout.cpp') and x['compiler_exit']==0 for x in rows)
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
assert sha(row['source'])==row['source_sha256'] and sha(row['object'])==row['object_sha256']
for path,digest in row['dependencies'].items():assert sha(path)==digest,path
raw=Path(row['object']).read_bytes();sections,symbols,definitions,_=match._coff_data_index(raw);functions=list(match.coff_functions(raw));tables=[]
for address,prefix in [(0x568180,'??0Selection@RBX@@'),(0x566f00,'??1Selection@RBX@@')]:
    name,body,refs=next(x for x in functions if x[0].startswith(prefix));target,tr,_=match.target('2008-06',f'{address:08x}');assert match.exact_match(target,tr,body,refs)
    start,section=definitions[name];table=sections[section];found={}
    for i in range(table[7]):
        offset,index,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);offset-=start
        if 0<=offset<=len(body)-4 and symbols[index][0].startswith('??_7Selection@RBX@@'):
            assert kind==6
            found[symbols[index][0]]=hex(struct.unpack_from('<I',target,offset)[0])
    assert len(found)==12,(name,found)
    tables.append(found)
assert tables[0]==tables[1]
assert '0x82edc4' in tables[0].values() and '0x82ed28' in tables[0].values()
result={'scope':'Selection ctor/dtor/factory masked bodies, explicit size/offset fixture and identical original vtable references. Vtable slot bodies, instance listener implementation, linked ABI and runtime unproven.','object_sha256':sha(row['object']),'source_sha256':sha(row['source']),'selection_size':'0x174','selection_offset':'0x154','filters_offset':'0x15c','vtable_bindings':tables[0],'run':str(run)}
(ROOT/'work/2008-06/selection-lifetime-proof.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
print('PASS Selection lifetime, 12 ctor/dtor vtable bindings and layout')
