import re

with open('build_output2.txt', 'r', errors='replace') as f:
    content = f.read()

# Join continuation lines: if a line starts with whitespace and the previous line ended inside quotes,
# join them. Actually, let's just find all LNK20 error blocks.
# Pattern: "symbol" followed by mangled name (?...)
# The symbol text can span multiple lines, and the mangled name is in (?...)

# Find all error blocks
blocks = re.findall(
    r'error LNK20[10][09]: unresolved external symbol "(.*?)"\s*referenced in function',
    content, re.DOTALL)
print(f'Found {len(blocks)} error blocks')

# Also find LNK2001 (no "referenced in function")
blocks2 = re.findall(
    r'error LNK2001: unresolved external symbol "(.*?)"',
    content, re.DOTALL)
print(f'Found {len(blocks2)} LNK2001 blocks')

all_symbols = blocks + blocks2
# Clean up: remove newlines and extra spaces from symbol names
cleaned = []
for s in all_symbols:
    cleaned.append(' '.join(s.split()))

unique = sorted(set(cleaned))
print(f'Unique symbols: {len(unique)}')
for s in unique:
    print(f'  {s}')
