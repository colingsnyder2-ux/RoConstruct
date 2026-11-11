import re

with open('build_output2.txt', 'r', encoding='utf-16', errors='replace') as f:
    content = f.read()

# Join continuation lines
lines = content.split('\n')
joined = []
for line in lines:
    if joined and line.startswith(' ') and joined[-1].count('"') % 2 == 1:
        joined[-1] += line
    else:
        joined.append(line)
content = '\n'.join(joined)

symbols = re.findall(r'unresolved external symbol "([^"]+)"', content)
unique = sorted(set(symbols))
print(f'Unique unresolved symbols: {len(unique)}')
for s in unique:
    print(s)
