import os, re
hits=[]
for line in open('linkexp/qt.map',errors='ignore'):
    p=line.split()
    if len(p)>=4 and p[1].startswith('func_') and 'qt_stubs.obj' in line:
        addr=p[1][5:]  # XXXXXXXX
        if os.path.exists(os.path.join('renamed','obj',addr+'.obj')) or os.path.exists(os.path.join('renamed','obj',addr.upper()+'.obj')):
            hits.append(addr)
print(len(hits))
print(hits[:50])