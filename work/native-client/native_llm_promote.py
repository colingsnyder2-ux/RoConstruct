"""Promote native_llm inactive exacts into their native-classes TU through native_autorecover --apply
(lease, draft upload, whole-destination re-proof).  Serial: one destination edit at a time.
Usage: python native_llm_promote.py [--only-remaining] [--limit N]"""
import argparse
import json
import os
import time
import subprocess
import sys
from pathlib import Path

sys.argv, ARGS = sys.argv[:1], sys.argv[1:]
import native_llm as m  # noqa: E402

ap = argparse.ArgumentParser()
ap.add_argument('--only-remaining', action='store_true', help='only addresses in remaining-3901.json')
ap.add_argument('--limit', type=int, default=0)
args = ap.parse_args(ARGS)
# One promoter at a time (runs launch one at their end): a held lock means another is still promoting.
LOCK = m.HERE / 'promote.lock'
try:
    lock_fd = os.open(str(LOCK), os.O_CREAT | os.O_EXCL | os.O_WRONLY)
except FileExistsError:
    if time.time() - LOCK.stat().st_mtime < 6 * 3600:
        sys.exit('another promoter holds ' + str(LOCK))
    LOCK.unlink(missing_ok=True)
    lock_fd = os.open(str(LOCK), os.O_CREAT | os.O_EXCL | os.O_WRONLY)
import atexit
atexit.register(lambda: (os.close(lock_fd), LOCK.unlink(missing_ok=True)))
remaining = set(json.loads((m.HERE.parent / 'remaining-3901.json').read_text())) if args.only_remaining else None
DONE = m.HERE / 'promoted.json'
done = json.loads(DONE.read_text()) if DONE.is_file() else {}
exact = {}
for line in m.LOG.read_text(encoding='utf-8').splitlines():
    row = m._json(line)
    if row and row.get('status') == 'inactive_exact':
        exact[row['addr']] = row
todo = [t for a, t in exact.items() if a not in done and (remaining is None or a in remaining)]
closure = json.loads(m.CLOSURE.read_text())
for n, t in enumerate(todo[:args.limit or None]):
    attempt = t.get('attempt')
    sub = {'cache': 'recheck', 'dest': 'dest'}.get(t.get('model'), 'try%s' % attempt)
    d = m.folder(t) / sub
    if not (d / 'plan.json').is_file():
        done[t['addr']] = 'no-plan'
        continue
    snap = dict(closure, bindings=[b for b in closure['bindings'] if b['addr'] != t['addr']] + [
        dict(symbol=t['symbol'], addr=t['addr'], address=t['addr'], votes=1, evidence='identity-registry',
             body_exact=False, function_start=True)])
    (d / 'apply-closure.json').write_text(json.dumps(snap))
    run = subprocess.run([sys.executable, str(m.ROOT / 'work/native-client/native_autorecover.py'), '--plan-file', str(d / 'plan.json'),
                          '--closure', str(d / 'apply-closure.json'), '--source-preamble', '--out', str(d / 'apply'),
                          '--apply'], cwd=m.ROOT, capture_output=True, text=True)
    try:
        summary = json.loads(run.stdout.strip().splitlines()[-1])['summary']
        state = next(iter(summary))
    except (IndexError, ValueError, StopIteration, KeyError):
        state = 'tool-error: ' + ' '.join((run.stderr or run.stdout)[-300:].split())
    import shutil
    for junk in list((d / 'apply').glob('plan-*-bulk-*')) + list((d / 'apply').glob('plan-*-destination-*')):
        shutil.rmtree(junk, ignore_errors=True)       # objects/logs: GBs across a batch
    (d / 'apply-closure.json').unlink(missing_ok=True)
    done[t['addr']] = state
    DONE.write_text(json.dumps(done, indent=1))
    print('%d/%d %s %-40s %s' % (n + 1, len(todo), t['addr'], t['qual'][-40:], state), flush=True)
