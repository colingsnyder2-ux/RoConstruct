"""Verify inclusive containment and strict ancestry call identities."""
import hashlib
import json
from pathlib import Path
import struct
import sys

ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT))
from roc import match
run=Path(sys.argv[1]);rows=json.loads((run/'results.json').read_text());sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
for row in rows:
    assert row['compiler_exit']==0
    for path,digest in row['dependencies'].items():assert sha(path)==digest,path
    assert sha(row['source'])==row['source_sha256'] and sha(row['object'])==row['object_sha256']
    assert all(x['status']=='exact' for x in row['checks'])
accept=next(x for x in rows if x['source'].endswith('InstanceChildAcceptance.cpp'))
raw=Path(accept['object']).read_bytes();sections,symbols,defs,_=match._coff_data_index(raw)
name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?canAcceptChildren@Instance@RBX@@'));target,tr,_=match.target('2008-06','00423700');assert match.exact_match(target,tr,body,refs)
start,section=defs[name];table=sections[section];matches=[]
for i in range(table[7]):
    offset,index,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);offset-=start
    if kind==20 and 0<=offset<=len(body)-4 and symbols[index][0].startswith('?contains@Instance@RBX@@'):
        value=(0x423700+offset+4+struct.unpack_from('<i',target,offset)[0])&0xffffffff
        assert value==0x5574b0 and struct.unpack_from('<I',body,offset)[0]==0
        matches.append(hex(value))
assert matches==['0x5574b0'],matches
fixture=ROOT/'work/2008-06/instance-ancestor-fixture/Checkinstance-ancestor-fixture.obj'
n,b,r=next(x for x in match.coff_functions(fixture.read_bytes()) if x[0].startswith('?isAncestorOf@Instance@RBX@@'));original,orefs,_=match.target('2008-06','004c9c50');assert match.exact_match(original,orefs,b,r)
result={'scope':'Local exact inclusive containment, strict ancestor helper and acceptance binding; runtime, class ABI and linked selection unproven.','acceptance_call':matches[0],'strict_ancestor_address':'0x4c9c50','fixture_object_sha256':sha(fixture),'acceptance_object_sha256':sha(accept['object']),'instance_header_sha256':sha(ROOT/'rebuild/2008-06/native-headers/v8tree/Instance.h'),'run':str(run)}
(ROOT/'work/2008-06/instance-containment-proof.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
print('PASS inclusive contains, strict ancestor and acceptance call identity')
