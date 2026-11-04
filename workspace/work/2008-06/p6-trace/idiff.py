import sys,re,difflib
sys.path.insert(0,'.')
from pathlib import Path
from roc import match
import capstone
obj=Path('rebuild/2008-06/out/native-layouts/CRobloxViewInit.obj').read_bytes()
t,rel,_=match.target('2008-06','0045a4a0')
n,b,cr=next((n,b,r) for n,b,r in match.coff_functions(obj) if n.startswith('?OnInitialUpdate@CRobloxView'))
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
def norm(code):
    o=[]
    for i in md.disasm(code,0):
        s=i.mnemonic+' '+i.op_str
        if i.mnemonic in('call','jmp') or i.mnemonic.startswith('j'): s=i.mnemonic+(' '+i.op_str if 'ptr' in i.op_str or i.op_str[:2]!='0x' else ' X')
        s=re.sub(r'dword ptr \[0x[0-9a-f]+\]','[G]',s)
        s=re.sub(r'push 0x[0-9a-f]{3,}','push G',s) if int(0)==0 else s
        s=re.sub(r', 0x8[0-9a-f]{5}$',', G',s)
        o.append(s)
    return o
A,B=norm(t),norm(b)
print(len(A),len(B))
for l in difflib.unified_diff(A,B,lineterm='',n=1,fromfile='orig',tofile='mine'):
    print(l[:70])
