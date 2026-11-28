"""python auto/cmpfn.py ORIG:OURS ... : side-by-side mnemonic diff of original vs our function (stops at first ret)."""
import sys,pefile,capstone
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
po=pefile.PE('run/RobloxOrig.exe',fast_load=True); pq=pefile.PE('run/RobloxQT.exe',fast_load=True)
def dis(pe,a,n=0x400):
    out=[]
    for i in md.disasm(pe.get_data(a-0x400000,n),a):
        out.append((i.mnemonic,i.op_str))
        if i.mnemonic in('ret','int3'): break
    return out
for arg in [a for a in sys.argv[1:] if ":" in a]:
    o,q=(int(x,16) for x in arg.split(':'))
    A,B=dis(po,o),dis(pq,q); bad=sum(x[0]!=y[0] for x,y in zip(A,B))+abs(len(A)-len(B))
    print('== %x:%x len %d/%d mismatch %d'%(o,q,len(A),len(B),bad))
    if bad or '-v' in sys.argv:
        for x,y in zip(A,B): print(('   ' if x[0]==y[0] else '!! ')+'%-44s | %s'%(' '.join(x),' '.join(y)))
