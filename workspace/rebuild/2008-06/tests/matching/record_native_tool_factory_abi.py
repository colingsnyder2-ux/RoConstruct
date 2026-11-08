"""Verify original tool-factory return ABI and caller usage."""
import hashlib, json, sys
from pathlib import Path
import capstone
root=Path(__file__).resolve().parents[4]
sys.path.insert(0,str(root))
from roc import match
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
rows=[]
for address in ('005c6270','005c6f00'):
    body,_,_=match.target('2008-06',address)
    instructions=[i.mnemonic+' '+i.op_str for i in md.disasm(body,int(address,16))]
    if address=='005c6270':
        assert instructions.count('ret ') == 2 and 'mov eax, esi' in instructions
    else:
        assert 'call eax' in instructions
        index=instructions.index('call eax')
        assert instructions[index+1]=='push eax' and instructions[-1]=='ret 4'
    rows.append({'address':address,'size':len(body),'sha256':hashlib.sha256(body).hexdigest(),'instructions':instructions})
header=root/'rebuild/2008-06/native-headers/StandardVerbs.h'
assert 'virtual MouseCommand* newMouseCommand();' in header.read_text()
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
receipt={'observer_sha256':sha(Path(__file__)),'header_sha256':sha(header),'methods':rows,'scope':'Original Arrow tool factory returns object in EAX without hidden result; shared caller passes EAX directly. Other tool factory bodies and ownership still need proof.'}
(root/'work/2008-06/shared-layouts/tool-factory-abi.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS native tool factory raw-pointer return and caller')
