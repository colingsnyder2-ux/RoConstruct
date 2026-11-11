import sys
sys.path.insert(0, '.')
from pathlib import Path
from roc import rebuild

with open('work/rbxgs-rebase/symcheck.py') as f:
    content = f.read()
exec(content.split('def archive_symbols')[0])

obj_dir = Path('work/native-client/obj')
targets = [
    'hasStringValue@?$TypedPropertyDescriptor@M@Reflection@RBX@@UBE_NXZ',
    'hasStringValue@?$TypedPropertyDescriptor@_N@Reflection@RBX@@UBE_NXZ',
    'hasStringValue@?$TypedPropertyDescriptor@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Reflection@RBX@@UBE_NXZ',
]
for p in sorted(obj_dir.glob('*.obj')):
    try:
        syms = symbols(p.read_bytes())
        for t in targets:
            for n, k in syms.items():
                if t in n and k == 'strong':
                    print(f'{p.name}: {n} ({k})')
    except Exception:
        pass
