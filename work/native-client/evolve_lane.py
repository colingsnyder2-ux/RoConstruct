"""evolve_lane.py: automatic diff-guided repair of worker drafts (the prefix_match + evolve.py method that produced startScript).
Every cycle: take worker units (native-classes/*_ADDR.cpp changed or new in git, and lane-drafts/class_*/ drafts) of
still-remaining addresses, score each with prefix_match; a draft that compiles and matches 10-99% of the target goes to
evolve.py with a Sonnet variant model (free models return empty replies); a 100% result is proved with agent_prove.py.
Results: work/native-client/evolve-lane-results.json.  Nothing is installed or committed here: a proved best.cpp still
needs its lease + identity bind (agent_bind / root_ref_bind) by a worker or the owner.
  python work/native-client/evolve_lane.py [--once] [--max 4] [--model claude:sonnet]"""
import argparse
import json
import re
import subprocess
import sys
import time
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(HERE))
RES = HERE / 'evolve-lane-results.json'
ap = argparse.ArgumentParser()
ap.add_argument('--once', action='store_true')
ap.add_argument('--max', type=int, default=4, help='drafts per cycle')
ap.add_argument('--model', default='', help='empty = evolve.py default ladder (free first, Sonnet last)')
ap.add_argument('--every', type=int, default=1800)
args = ap.parse_args()


def load(path, default):
    try:
        return json.loads(Path(path).read_text(encoding='utf-8'))
    except (OSError, ValueError):
        return default


def candidates(remaining):
    out = {}
    git = subprocess.run(['git', 'status', '--porcelain', 'rebuild/2008-06/native-classes'], cwd=ROOT, capture_output=True,
                         text=True).stdout.splitlines()
    files = [ROOT / line[3:].strip() for line in git if line[3:].strip().endswith('.cpp')]
    files += list((HERE / 'lane-drafts').glob('class_*/*.cpp'))
    for f in files:
        m = re.search(r'_([0-9a-f]{8})\.cpp$', f.name)
        if m and m.group(1) in remaining and f.is_file():
            out[(m.group(1), str(f))] = f
    return list(out.items())


def cycle():
    import prefix_match as pm
    remaining = load(HERE / 'remaining-classified.json', {})
    done = load(RES, {})
    todo = 0
    for (addr, name), f in candidates(remaining):
        key = '%s|%s' % (addr, f.stat().st_mtime_ns)
        if key in done:
            continue
        if todo >= args.max:
            break
        try:
            r = pm.score(f, addr, '')
        except Exception as error:                        # noqa: BLE001
            done[key] = {'file': f.name, 'status': 'score failed: %s' % repr(error)[:80]}
            continue
        if not r.get('ok'):
            done[key] = {'file': f.name, 'status': 'does not compile'}
            continue
        if r.get('exact'):
            status = 'prefix exact: prove it'
        elif r['score'] < 0.10:
            status = 'prefix %.1f%%: too far' % (100 * r['score'])
        else:
            todo += 1
            out = subprocess.run([sys.executable, '-u', str(HERE / 'evolve.py'), addr, '--file', str(f), '--rounds', '3',
                                  '--no-permute'] + (['--model', args.model] if args.model else []), cwd=ROOT, capture_output=True, text=True,
                                 encoding='utf-8', errors='replace', timeout=3600).stdout
            best = HERE / 'lane-drafts' / ('evolve_%s_w8' % addr) / 'best.cpp'
            scores = re.search(r'scores per round: ([\d. ]+)', out)
            status = 'evolve: %s' % (scores.group(1).strip() if scores else 'no result')
            if 'IDENTICAL' in out and best.is_file():
                verdict = subprocess.run([sys.executable, str(HERE / 'agent_prove.py'), str(best), addr], cwd=ROOT,
                                         capture_output=True, text=True, encoding='utf-8', errors='replace').stdout
                status += ' | prove: ' + (re.search(r'== %s (\w+)' % addr, verdict) or [0, '?'])[1] + ' -> ' + str(best)
        done[key] = {'file': f.name, 'status': status, 'time': time.strftime('%Y-%m-%d %H:%M')}
        print(addr, f.name, status, flush=True)
        RES.write_text(json.dumps(done, indent=1), encoding='utf-8')
    RES.write_text(json.dumps(done, indent=1), encoding='utf-8')


while True:
    cycle()
    if args.once:
        break
    time.sleep(args.every)
