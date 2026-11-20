import re
from collections import Counter

with open('build_output.txt', 'r', errors='replace') as f:
    content = f.read()

errors = re.findall(r'(\S+\.obj) : error LNK20[10][09]: unresolved external symbol "([^"]+)"', content)
print(f'Total unresolved: {len(errors)}')
obj_counts = Counter(e[0] for e in errors)
for obj, count in obj_counts.most_common():
    print(f'  {obj}: {count}')

print("\n--- All unique unresolved symbols ---")
seen = set()
for obj, sym in errors:
    if sym not in seen:
        seen.add(sym)
        print(f'  {sym}')
