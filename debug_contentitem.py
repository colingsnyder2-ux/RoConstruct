import sys
sys.path.insert(0, r'.')
from roc import draft, match

row = match._functions('2008-06').get('004402d0')
code, relocs, _ = match.target('2008-06', '004402d0')
asm = match.disasm(code, int('004402d0', 16))
facts = draft.facts_from_asm(asm)

prompt = draft.prompt_for(
    client='2008-06', addr='004402d0', row=row, asm=asm, hint=None, attempt=None,
    flags=None, examples=(), source_hints=(), facts=facts,
    strategy='direct', compact_rules=True, binary_only=False,
    minimal_layout=False, family_exemplars=False, near_repair=False,
    remill_evidence=None, prompt_style='lean'
)

# Find all lines with ContentItem
lines = prompt.split('\n')
print(f'Total lines: {len(lines)}')
print(f'Lines containing ContentItem:')
for i, line in enumerate(lines):
    if 'ContentItem' in line:
        print(f'  Line {i+1}: {line[:150]}')

print()
print(f'Lines containing Qt:')
for i, line in enumerate(lines):
    if 'Qt' in line and 'function' not in line.lower():
        print(f'  Line {i+1}: {line[:150]}')

# Show what's in row['unit']
print(f'\nrow["unit"]: {row.get("unit", "")}')
print(f'\nFacts:')
for k, v in facts.items():
    print(f'  {k}: {v}')