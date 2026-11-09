"""Verify Selection removal, notification and native call targets."""
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT))
from roc import match
run=Path(sys.argv[1]);rows=json.loads((run/'results.json').read_text())
row=next(x for x in rows if x['source'].endswith('SelectionMutations.cpp'))
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
assert sha(row['source'])==row['source_sha256'] and sha(row['object'])==row['object_sha256']
for path,digest in row['dependencies'].items():assert sha(path)==digest,path
assert all(x['status']=='exact' for x in row['checks'])
raw=Path(row['object']).read_bytes();sections,symbols,definitions,_=match._coff_data_index(raw);functions=list(match.coff_functions(raw));results=[]
checks=[
(0x566ba0,'?raiseAdded@Selection@RBX@@',{'??0SelectionChanged@RBX@@':0x566860,'?raise@?$Notifier@VSelection@':0x566ab0,'??1SelectionChanged@RBX@@':0x422c60}),
(0x567420,'?addToSelection@Selection@RBX@@',{'??$shared_from@':0x618a40,'?write@?$CopyOnWrite@':0x49add0,'?push_back@?$vector@':0x420110,'?addListener@?$Notifier@':0x4218a0,'?raiseAdded@Selection@':0x566ba0}),
(0x5675d0,'?clearSelection@Selection@RBX@@',{'?write@?$CopyOnWrite@':0x49add0,'??$_Destroy_range@':0x5a1990,'?removeListener@?$Notifier@':0x5e5a80,'?raiseRemoved@Selection@':0x566d50}),
(0x567770,'?setSelection@Selection@RBX@@',{'??$shared_from@':0x618a40,'?write@?$CopyOnWrite@':0x49add0,'??$_Destroy_range@':0x5a1990,'?removeListener@?$Notifier@':0x5e5a80,'?raiseRemoved@Selection@':0x566d50,'?push_back@?$vector@':0x420110,'?addListener@?$Notifier@':0x4218a0,'?raiseAdded@Selection@':0x566ba0})]
for address,prefix,expected in checks:
    name,body,refs=next(x for x in functions if x[0].startswith(prefix));target,tr,_=match.target('2008-06',f'{address:08x}');assert match.exact_match(target,tr,body,refs)
    start,section=definitions[name];table=sections[section];found={}
    for i in range(table[7]):
        offset,index,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);offset-=start
        if kind==20 and 0<=offset<=len(body)-4:
            symbol=symbols[index][0];key=next((p for p in expected if symbol.startswith(p)),None)
            if key:
                target_addr=(address+offset+4+struct.unpack_from('<i',target,offset)[0])&0xffffffff
                assert target_addr==expected[key] and struct.unpack_from('<I',body,offset)[0]==0,(symbol,hex(target_addr))
                found[key]=hex(target_addr)
    assert set(found)==set(expected),(name,found)
    eh=ROOT/'work/2008-06'/('selection-mutation-eh-%08x.json'%address)
    subprocess.run([sys.executable,str(ROOT/'rebuild/2008-06/tests/audit_native_eh_graph.py'),row['object'],f'{address:08x}',name,'--output',str(eh)],cwd=ROOT,check=True)
    results.append({'address':hex(address),'symbol':name,'targets':found,'eh_sha256':sha(eh)})
result={'scope':'Local four bodies, selected call identities and EH graphs; linked ownership, ABI and runtime unproven.','methods':results,'object_sha256':sha(row['object']),'source_sha256':sha(row['source']),'run':str(run)}
(ROOT/'work/2008-06/selection-mutations-proof.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
print('PASS Selection mutations: original calls and EH')
