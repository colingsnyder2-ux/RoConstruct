import sys
sys.path.insert(0, '.')
from pathlib import Path
from roc import rebuild

with open('work/rbxgs-rebase/symcheck.py') as f:
    content = f.read()
exec(content.split('def archive_symbols')[0])

obj_path = Path('work/native-client/obj/CRenderSettings.obj')
syms = symbols(obj_path.read_bytes())
for n, k in syms.items():
    if 'hasStringValue' in n:
        print(f'{n} -> {k}')
