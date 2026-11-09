"""Verify original Selection service factory wrappers and call identities."""
import hashlib
import json
import os
from pathlib import Path
import struct
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT))
from roc import match
out=ROOT/'work/2008-06/selection-create-proof'
out.mkdir(parents=True,exist_ok=True)
checks=['004153b0=??$create@VSelection@RBX@@@ServiceProvider@RBX@@QBE','00421cb0=??$create@VSelection@RBX@@@ServiceProvider@RBX@@SA']
proc=subprocess.run([sys.executable,str(ROOT/'rebuild/2008-06/tests/check_native_class.py'),'native-classes/SelectionCreate.cpp']+checks,cwd=ROOT,env=dict(os.environ,NATIVE_CHECK_OUT=str(out)),capture_output=True,text=True,check=True)
assert '2/2 exact' in proc.stdout,proc.stdout
obj=out/'CheckSelectionCreate.obj';raw=obj.read_bytes();sections,symbols,definitions,_=match._coff_data_index(raw);functions=list(match.coff_functions(raw));rows=[]
for address,prefix,expected in [
    (0x4153b0,'??$create@VSelection@RBX@@@ServiceProvider@RBX@@QBE',{'??$find@VSelection@':0x415200,'??$create@VSelection@RBX@@@?$Creatable':0x409620,'?setParent@Instance@':0x55a8f0}),
    (0x421cb0,'??$create@VSelection@RBX@@@ServiceProvider@RBX@@SA',{'??_R0?AVServiceProvider@RBX@@':0x92e15c,'??_R0?AVInstance@RBX@@':0x92907c,'___RTDynamicCast':0x6a17c6,'??$create@VSelection@RBX@@@ServiceProvider@RBX@@QBE':0x4153b0}),
]:
    name,body,refs=next(x for x in functions if x[0].startswith(prefix));target,_,_=match.target('2008-06',f'{address:08x}');start,section=definitions[name];table=sections[section];found={}
    for i in range(table[7]):
        offset,index,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);offset-=start
        if 0<=offset<=len(body)-4:
            symbol=symbols[index][0];key=next((p for p in expected if symbol.startswith(p)),None)
            if key:
                value=struct.unpack_from('<I',target,offset)[0]
                if kind==20:value=(address+offset+4+struct.unpack_from('<i',target,offset)[0])&0xffffffff
                assert value==expected[key] and struct.unpack_from('<I',body,offset)[0]==0,(symbol,hex(value))
                found[key]=hex(value)
    assert set(found)==set(expected),found
    rows.append({'address':hex(address),'symbol':name,'targets':found})
eh=out/'eh.json'
subprocess.run([sys.executable,str(ROOT/'rebuild/2008-06/tests/audit_native_eh_graph.py'),str(obj),'004153b0',rows[0]['symbol'],'--output',str(eh)],cwd=ROOT,check=True)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
paths=['rebuild/2008-06/native-classes/SelectionCreate.cpp','rebuild/2008-06/native-headers/v8datamodel/Selection.h','rebuild/2008-06/p6/build_client.py','rebuild/2008-06/tests/record_native_selection_create.py']
result={'scope':'Inactive native wrappers and selected targets with member-create EH; Selection instance factory, full layout/ABI, linked selection and runtime unproven.','methods':rows,'inputs':{p:sha(ROOT/p) for p in paths},'object_sha256':sha(obj),'eh_sha256':sha(eh)}
(out/'result.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
print('PASS Selection create wrappers, targets and local EH')
