"""Verify native Instance parenting bodies, bindings, strings and EH."""
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys
import pefile

ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT))
from roc import match
run=Path(sys.argv[1]);rows=json.loads((run/'results.json').read_text());row=next(x for x in rows if x['source'].endswith('InstanceParent.cpp'))
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
assert sha(row['source'])==row['source_sha256'] and sha(row['object'])==row['object_sha256']
for path,digest in row['dependencies'].items():assert sha(path)==digest,path
assert all(x['status']=='exact' for x in row['checks'])
raw=Path(row['object']).read_bytes();sections,symbols,definitions,_=match._coff_data_index(raw);name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?setParent@Instance@RBX@@'));target,tr,_=match.target('2008-06','0055a8f0');assert match.exact_match(target,tr,body,refs)
expected={'?getFullName@Instance@':0x5574d0,'?format@G3D@@':0x509b10,'??0runtime_error@std@@':0x409d50,'__CxxThrowException@8':0x6a158c,'?isAncestorOf@Instance@':0x4c9c50,'??$shared_from@VInstance@':0x618a40,'?shared_from_this@?$enable_shared_from_this@':0x42af90,'?contains@Instance@':0x5574b0,'?signalDescendentRemoving@Instance@':0x558370,'?write@?$CopyOnWrite@':0x49add0,'?end@?$vector@':0x68ff20,'?begin@?$vector@':0x68fef0,'??$find@':0x438b30,'?erase@?$vector@':0x439480,'?reset@?$CopyOnWrite@':0x456e80,'??0?$shared_ptr@VInstance@':0x4116f0,'?fire@?$SignalDescImpl@':0x49d200,'?raise@?$Notifier@VInstance@RBX@@UChildRemoved@':0x558590,'?push_back@?$vector@':0x420110,'?signalDescendentAdded@Instance@':0x558220,'?raise@?$Notifier@VInstance@RBX@@UChildAdded@':0x5584c0,'?raisePropertyChanged@Instance@':0x40db00,'??1?$shared_ptr@VInstance@':0x600660}
data_expected={'?event_childRemoved@Instance@':0x973c6c,'?event_childAdded@Instance@':0x973e90,'?propParent@Instance@':0x973d34}
start,section=definitions[name];table=sections[section];calls=[];data={}
for i in range(table[7]):
    offset,index,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);offset-=start
    if not 0<=offset<=len(body)-4:continue
    symbol=symbols[index][0]
    if kind==20:
        key=next((p for p in expected if symbol.startswith(p)),None);assert key,('unverified direct call',symbol)
        value=(0x55a8f0+offset+4+struct.unpack_from('<i',target,offset)[0])&0xffffffff
        assert value==expected[key] and struct.unpack_from('<I',body,offset)[0]==0,(symbol,hex(value))
        calls.append({'offset':offset,'symbol':symbol,'original':hex(value)})
    elif kind==6:
        key=next((p for p in data_expected if symbol.startswith(p)),None)
        if key:
            value=struct.unpack_from('<I',target,offset)[0];assert value==data_expected[key],(symbol,hex(value));data[key]=hex(value)
assert set(data)==set(data_expected),data
for key in expected:assert any(x['symbol'].startswith(key) for x in calls),key
pe=pefile.PE(str(ROOT/'work/2008-06/original-p4-reference/Roblox.exe'));literals=[]
for offset,value,_ in match.coff_data_refs(raw,name):
    if offset in (99,265):
        text=value.split(b'\0',1)[0];address=struct.unpack_from('<I',target,offset)[0]
        assert pe.get_string_at_rva(address-pe.OPTIONAL_HEADER.ImageBase)==text
        literals.append(text.decode())
assert len(literals)==2
output=ROOT/'work/2008-06/instance-parent-verified-eh.json'
subprocess.run([sys.executable,str(ROOT/'rebuild/2008-06/tests/audit_native_eh_graph.py'),row['object'],'0055a8f0',name,'--output',str(output)],cwd=ROOT,check=True)
result={'scope':'Local original parenting, containment and ancestry bodies, direct call identities, selected data and literals, local EH. Indirect calls, provider selection, full class ABI and runtime unproven.','calls':calls,'data':data,'literals':literals,'object_sha256':sha(row['object']),'source_sha256':sha(row['source']),'eh_sha256':sha(output),'run':str(run)}
(ROOT/'work/2008-06/instance-parent-proof.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
print('PASS Instance::setParent: original direct calls, data, strings and EH')
