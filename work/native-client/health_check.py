"""Health check for the unattended native pipeline: servers up, lanes progressing, no stale locks, results.json valid.
Prints one line per problem (nothing wrong -> 'OK ...').  python work/native-client/health_check.py"""
import json
import socket
import sys
import time
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(HERE))
problems, notes = [], []


def port(p, host='127.0.0.1'):
    try:
        socket.create_connection((host, p), timeout=2).close()
        return True
    except OSError:
        return False


for name, p, host in (('group/lease server', 8765, '127.0.0.2'), ('dashboard', 8791, '127.0.0.1'), ('gate server', 8799, '127.0.0.1')):
    if not port(p, host) and not port(p):
        problems.append('%s DOWN (port %d)' % (name, p))

try:
    import results_store
    r = results_store.load()
    notes.append('results %d rows, %d exact' % (len(r), sum(v.get('status') == 'inactive_exact' for v in r.values())))
except Exception as error:                                     # noqa: BLE001
    problems.append('results.json unreadable: %r' % error)

now = time.time()
for lock in [HERE / 'prove-out/CENSUS.lock', HERE / 'placeholder-lane/results.lock', *HERE.glob('prove-out/*/run.lock'),
             *HERE.glob('creator-gate/*-bulk/run.lock')]:
    if lock.is_file() and now - lock.stat().st_mtime > (6 * 3600 if 'CENSUS' in lock.name else 1800):
        age = (now - lock.stat().st_mtime) / 60
        if 'creator-gate' in str(lock):                      # a gate takes minutes: a 30+ min gate lock is a killed run
            lock.unlink(missing_ok=True)
            notes.append('removed stale gate lock %s (%d min)' % (lock.parent.name, age))
        else:
            problems.append('stale lock %s (%d min old)' % (lock.relative_to(ROOT), age))

# Lane activity: newest answer/err file in the placeholder lane.
newest = max((p.stat().st_mtime for p in (HERE / 'placeholder-lane').glob('*/err*.txt')), default=0)
notes.append('last lane answer %d min ago' % ((now - newest) / 60))
if now - newest > 3600:
    problems.append('no lane answer for %d min (lanes idle or stuck?)' % ((now - newest) / 60))

print(('PROBLEMS: ' + '; '.join(problems)) if problems else 'OK', '|', '; '.join(notes))
