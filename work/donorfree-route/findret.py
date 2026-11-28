import re
res=[]
for line in open('linkexp/qt.map',errors='ignore'):
    m=re.match(r'\s*0001:([0-9a-fA-F]+)\s+00000001H\s+(\S+)', line)
    if m:
        res.append((m.group(1), m.group(2)))
print(len(res))
print(res[:20])
PY