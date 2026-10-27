import sys
import re
sys.path.insert(0, r'.')
from roc import draft, match

# Get function data
row = match._functions('2008-06').get('004402d0')
if not row:
    print('Function not found')
    sys.exit(1)

# Get assembly
code, relocs, _ = match.target('2008-06', '004402d0')
asm = match.disasm(code, int('004402d0', 16))

# Manually _insn the lines
insn_lines = [draft._insn(line) for line in asm]
print('First 10 _insn() processed lines:')
for i, line in enumerate(insn_lines[:10]):
    print(f'  {i}: |{line}|')

# Check prologue detection
has_ebp = any(re.search(r"^\s*push\s+ebp", line) for line in insn_lines)
has_mov = any(re.search(r"^\s*mov\s+ebp\s*,?\s*esp", line) for line in insn_lines)
print(f'\nhas push ebp: {has_ebp}')
print(f'has mov ebp, esp: {has_mov}')
print(f'Both: {has_ebp and has_mov}')

# Check the actual regex matches
import re
for i, line in enumerate(insn_lines[:5]):
    m1 = re.search(r"^\s*push\s+ebp", line)
    m2 = re.search(r"^\s*mov\s+ebp\s*,?\s*esp", line)
    print(f'Line {i}: push match={m1 is not None}, mov match={m2 is not None}, line={line!r}')