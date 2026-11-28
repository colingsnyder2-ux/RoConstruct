"""python auto/stuborig.py NAME_SUBSTR...: for each called stub whose name contains a substring, align our call sites with the
original caller (converted objects are named <origaddr>.obj) and print the original call target address."""
import sys,re,struct,bisect,pefile,json
pq=pefile.PE('run/RobloxQT.exe',fast_load=True); po=pefile.PE('run/RobloxOrig.exe',fast_load=True)
iq=pq.get_memory_mapped_image(); io=po.get_memory_mapped_image()
rows=[];addr={}
for l in open('linkexp/qt.map',errors='ignore'):
    p=l.split()
    if len(p)>=4 and p[0].startswith('0001:') and re.fullmatch(r'[0-9a-f]{8}',p[2]):
        a=int(p[2],16); rows.append((a,p[1],p[-1])); addr.setdefault(p[1],(a,p[-1]))
rows.sort(); ks=[r[0] for r in rows]
tx=[s for s in pq.sections if s.Name.startswith(b'.text')][0]; tb=0x400000+tx.VirtualAddress; td=tx.get_data()
for sub in sys.argv[1:]:
    for name,(sa,obj) in addr.items():
        if sub not in name or 'stubs' not in obj: continue
        res=set()
        i=td.find(b'\xe8')
        while i!=-1:
            if i+5<=len(td) and tb+i+5+struct.unpack_from('<i',td,i+1)[0]==sa:
                site=tb+i; j=bisect.bisect_right(ks,site)-1
                while j>0 and ks[j]==ks[j-1]: j-=1
                cands=[r for r in rows[j:j+40] if r[0]==ks[j]]
                for r in cands:
                    m=re.match(r'([0-9a-f]{8})\.obj$',r[2])
                    if m:
                        o=int(m.group(1),16)+(site-r[0])-0x400000
                        if io[o]==0xe8: res.add(('%08x'%(o+0x400000+5+struct.unpack_from('<i',io,o+1)[0]),r[2]))
                        else: res.add(('nomatch',r[2]))
                        break
                else: res.add(('noobj',cands[0][2] if cands else '?'))
            i=td.find(b'\xe8',i+1)
        print(name[:90],sorted(res))
