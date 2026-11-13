"""Find which newly added analog objects make the stub-backed client crash at startup.
python bisect_analogs.py   (base = chosen.json + glue + the analogs in closure/good.json; candidates = the rest of closure/renamed)
Delta debugging by halves; writes closure/bad.json (analogs to leave out) and chosen_good.json."""
import json, os, subprocess, sys
from pathlib import Path
H = Path('work/native-client/shortcut')
C = H / 'closure'
allobjs = sorted(p.as_posix() for p in (C / 'renamed').glob('*.obj'))
good = set(json.load(open(C / 'good.json'))) if (C / 'good.json').exists() else set()
cands = [o for o in allobjs if o not in good]
chosen = json.load(open(H / 'chosen.json'))
extra = json.load(open(C / 'extra.json')) if (C / 'extra.json').exists() else []


def crashes(subset):
    json.dump(chosen + extra + sorted(good) + subset, open(H / 'chosen_try.json', 'w'), indent=0)
    r = subprocess.run([sys.executable, str(H / 'relink_big.py'), 'chosen_try.json'], capture_output=True, text=True)
    out = r.stdout
    if 'final link 0' not in out:
        return True            # does not even link: treat as bad
    return 'exception' in out


bad = []
queue = [cands]
while queue:
    s = queue.pop()
    if not s:
        continue
    if not crashes(s):
        good |= set(s)
        print('ok', len(s), flush=True)
        continue
    if len(s) == 1:
        bad.append(s[0])
        print('bad', s[0], flush=True)
        continue
    mid = len(s) // 2
    # test first half with the rest of good; second half later
    queue.append(s[mid:])
    queue.append(s[:mid])
json.dump(sorted(good), open(C / 'good.json', 'w'), indent=0)
json.dump(bad, open(C / 'bad.json', 'w'), indent=0)
json.dump(chosen + extra + sorted(good), open(H / 'chosen_good.json', 'w'), indent=0)
print('good', len(good), 'bad', len(bad))
