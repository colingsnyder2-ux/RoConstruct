import sys
sys.path.insert(0, '.')
from pathlib import Path
from roc import rebuild

with open('work/rbxgs-rebase/symcheck.py') as f:
    content = f.read()
exec(content.split('def archive_symbols')[0])

ws = rebuild.workspace('2008-06')
engine_dir = ws / 'out/RbxgsApp/linked'

targets = [
    'hasStringValue@?$TypedPropertyDescriptor@M@Reflection@RBX@@UBE_NXZ',
    'hasStringValue@?$TypedPropertyDescriptor@_N@Reflection@RBX@@UBE_NXZ',
    'hasStringValue@?$TypedPropertyDescriptor@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Reflection@RBX@@UBE_NXZ',
]
for p in sorted(engine_dir.glob('*.obj')):
    try:
        syms = symbols(p.read_bytes())
        for t in targets:
            for n, k in syms.items():
                if t in n and k != 'undef':
                    print(f'{p.name}: {n} ({k})')
    except Exception:
        pass
