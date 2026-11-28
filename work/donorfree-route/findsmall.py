import re
items=[]
for line in open('linkexp/qt.map',errors='ignore'):
    m=re.match(r'\s*0001:([0-9a-fA-F]+)\s+([0-9a-fA-F]+)H\s+(func_[0-9a-fA-F]+)', line)
    if m:
        items.append((int(m.group(2),16), m.group(3), m.group(1)))
items.sort()
print(items[:10])