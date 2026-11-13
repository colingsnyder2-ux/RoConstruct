import re, subprocess, sys
from pathlib import Path
sys.path.insert(0, '.')
from roc import rebuild
folder = Path('work/native-client/shortcut/closure/renamed')
for it in range(8):
    text = Path('work/native-client/link/link.txt').read_text(errors='replace')
    n = 0
    for m in re.finditer(r'LNK2005:.*?\((\?[^)]*)\)\s+already defined in (\S+\.obj)', text):
        o = folder / m.group(2)
        if o.exists():
            o.write_bytes(rebuild.strip_symbols(o.read_bytes(), drop={m.group(1)})); n += 1
    print('iter', it, 'stripped', n)
    if not n:
        break
    r = subprocess.run([sys.executable, 'work/native-client/shortcut/relink_big.py', 'chosen_closure.json'], capture_output=True, text=True)
    print([l for l in r.stdout.splitlines() if l.startswith(('unstubbed', 'final link'))])
