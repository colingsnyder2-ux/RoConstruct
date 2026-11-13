"""Analog-wins mode: which analogs may replace their engine definition without crashing the client at startup?
Base link = chosen_verbs.json; candidate winners = closure/renamed/*.obj that define a symbol the engine also defines.
Delta debugging by halves with ROC_ANALOG_DIR = a folder holding the tried subset.  Writes closure/wins_good.json / wins_bad.json."""
import json, os, shutil, subprocess, sys
from pathlib import Path
sys.path.insert(0, '.')
from roc.rebuild import coff_externals
H = Path('work/native-client/shortcut')
C = H / 'closure'
W = C / 'winners_try'
engine_defs = set()
for o in Path('rebuild/2008-06/out/RbxgsApp/linked').glob('*.obj'):
    engine_defs |= {s for s, d in coff_externals(o.read_bytes()).items() if d}
cands = []
for o in sorted((C / 'renamed').glob('*.obj')):
    d = {s for s, v in coff_externals(o.read_bytes()).items() if v}
    if d & engine_defs:
        cands.append(o.name)
print('candidates', len(cands), flush=True)
good, bad = [], []


def crashes(subset):
    if W.exists():
        shutil.rmtree(W)
    W.mkdir(parents=True)
    for n in subset + good:
        shutil.copy(C / 'renamed' / n, W / n)
    names = set(subset + good)
    base = [c for c in json.load(open(H / 'chosen_verbs.json')) if os.path.basename(c) not in names]
    json.dump(base + [(W / n).resolve().as_posix() for n in sorted(names)], open(H / 'chosen_wins_try.json', 'w'), indent=0)
    env = dict(os.environ, ROC_ANALOG_DIR=str(W.resolve()))
    import re
    from roc import rebuild
    for attempt in range(5):
        r = subprocess.run([sys.executable, str(H / 'relink_big.py'), 'chosen_wins_try.json'], env=env, capture_output=True, text=True)
        out = r.stdout
        if 'final link 0' in out:
            return 'exception' in out
        # link failed: strip duplicate definitions out of the tried copies (and the shared analog copies) and retry
        text = Path('work/native-client/link/link.txt').read_text(errors='replace')
        n = 0
        for m in re.finditer(r'LNK2005:.*?\((\?[^)]*)\)\s+already defined in (\S+\.obj)', text):
            for folder in (W, C / 'renamed'):
                o = folder / m.group(2)
                if o.exists():
                    o.write_bytes(rebuild.strip_symbols(o.read_bytes(), drop={m.group(1)})); n += 1
        if not n:
            print('link failure not duplicates:', [l[:140] for l in text.splitlines() if 'fatal' in l][:2], flush=True)
            return True
    return True


queue = [cands]
while queue:
    s = queue.pop()
    if not s:
        continue
    if not crashes(s):
        good += s
        print('ok', len(s), 'good so far', len(good), flush=True)
    elif len(s) == 1:
        bad += s
        print('bad', s[0], flush=True)
    else:
        mid = len(s) // 2
        queue.append(s[mid:])
        queue.append(s[:mid])
json.dump(good, open(C / 'wins_good.json', 'w'))
json.dump(bad, open(C / 'wins_bad.json', 'w'))
print('good', len(good), 'bad', len(bad))
