import sys
sys.path.insert(0,'.')
from pathlib import Path
from roc import match
import capstone
obj=Path('rebuild/2008-06/out/native-layouts/CRobloxViewInit.obj').read_bytes()
t,rel,_=match.target('2008-06','0045a4a0')
n,b,cr=next((n,b,r) for n,b,r in match.coff_functions(obj) if n.startswith('?OnInitialUpdate@CRobloxView'))
mask={o+k for o in list(rel)+list(cr) for k in range(4)}
d=[i for i,(x,y) in enumerate(zip(t,b)) if x!=y and i not in mask]
print(len(t),len(b),'first diffs',d[:6])
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
def show(code,off,count=9):
    out=[]
    for i in md.disasm(code[max(0,off-12):],max(0,off-12)):
        out.append('%x %s %s'%(i.address,i.mnemonic,i.op_str))
        if len(out)>=count+4: break
    return out
i=d[0]
print('\n'.join(show(t,i)));print('--');print('\n'.join(show(b,i)))
