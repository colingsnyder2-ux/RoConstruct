import sys
sys.path.insert(0, r'.')
from roc import draft, match, refsource

# Test what happens if source_hints comes from refsource with mixed types
row = match._functions('2008-06').get('004402d0')
code, relocs, _ = match.target('2008-06', '004402d0')
asm = match.disasm(code, int('004402d0', 16))
facts = draft.facts_from_asm(asm)

try:
    hints = refsource.prompt_hints(
        row.get('unit', ''),
        limit=3,
        max_chars=1800,
        target_facts=facts,
        client='2008-06'
    )
    print(f'Got {len(hints)} hints')
    for h in hints:
        p = h.get('path', '')
        s = h.get('score')
        print(f'  path={p[:50]}, score={s}, type={type(s).__name__}')
    # Try sorting
    hints.sort(key=lambda row: -row['score'])
    print('Sorting hints works')
except Exception as e:
    print(f'Error: {type(e).__name__}: {e}')

# Also test where scores come from literal_sources
print('\nTesting literal_sources:')
try:
    rows = refsource.literal_sources(('test',), limit=3)
    for h in rows:
        p = h.get('path', '')
        s = h.get('score')
        print(f'  path={p[:50]}, score={s}, type={type(s).__name__}')
except Exception as e:
    print(f'Error: {type(e).__name__}: {e}')