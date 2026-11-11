"""No-LLM fixpoint driver for run_all.py.  Nothing here decides exactness: ogre_convert.py's
byte/reloc/data proofs do.  This only repeats the batches until a whole round adds no exact address.

  python work/native-client/ogre/auto_loop.py [--batch 20] [--minutes 30]

Round = --next (mined) until empty, --next --vendor until empty, one --repair batch,
then one retry of every still-blocked root (a callee proved later can unblock it).
run_all.py takes an OS lock per batch, so this is safe beside another runner.
"""
import argparse
import json
import os
import subprocess
import sys
import time
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
BATCHES = HERE / 'batches'
LOCK = HERE / 'auto_loop.lock'
LOG = HERE / 'auto_loop.jsonl'
LOOP_SCOPE = 'Ogre::,RBX::RenderNew,RBX::ViewNew'


def reports():
    out = []
    for path in sorted(BATCHES.glob('*/link/ogre_convert.json')):
        try:
            out.append(json.loads(path.read_text()))
        except ValueError:          # another runner is mid-write; its rows arrive next round
            pass
    return out


def state():
    """-> (exact addresses, roots whose every attempt ended blocked, exact roots still named roc_fn_*)."""
    exact, blocked, named, synthetic = set(), set(), set(), set()
    for report in reports():
        for addr, row in report.items():
            if row['status'] == 'renamed':
                exact.add(addr)
                if row.get('name_source') not in ('synthetic', 'registry:placeholder'):
                    named.add(addr)
                elif row.get('scope'):
                    synthetic.add(addr)
            elif row['status'] in ('blocked', 'vendor-source', 'compile-fail', 'nomatch') and row.get('scope'):
                # a callee gets proved, the vendor lane turns on, a missing library source gets fetched
                blocked.add(addr)
    return exact, blocked - exact, synthetic - named


def run_all(*flags):
    """One run_all.py batch -> its JSON line, or None when the queue is empty."""
    run = subprocess.run([sys.executable, '-u', str(HERE / 'run_all.py'), *flags],
                         cwd=ROOT, text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    last = run.stdout.strip().splitlines()[-1] if run.stdout.strip() else ''
    if run.returncode or not last.startswith('{'):
        if not run.returncode and 'no source-backed roots' in last:
            return None
        log(stage=' '.join(flags), error=run.stdout[-600:])
        raise RuntimeError('batch failed; see loop log (exit %s)' % run.returncode)
    return json.loads(last)


def retry(roots, n):
    """Re-run blocked roots with the vendor lane on, in a batch dir run_all.py's scans understand."""
    stem = BATCHES / ('retry-%03d-%s' % (n, roots[0]))
    env = dict(os.environ, OGRE_OUT=str(stem / 'renamed'), OGRE_LINK=str(stem / 'link'), OGRE_VENDOR_SOURCE='1',
               ROC_SCOPE=LOOP_SCOPE, OGRE_CACHE=str(HERE / 'cache' / BATCHES.name))
    run = subprocess.run([sys.executable, str(HERE / 'ogre_convert.py'), *roots], cwd=ROOT, env=env,
                         text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    if run.returncode:
        log(stage='retry', error=run.stdout[-600:])
        raise RuntimeError('retry failed; see loop log (exit %s)' % run.returncode)
    (stem / 'roots.json').write_text(json.dumps(roots, indent=1) + '\n')


def log(**row):
    row['time'] = time.strftime('%Y-%m-%d %H:%M:%S')
    with LOG.open('a') as out:
        out.write(json.dumps(row, sort_keys=True) + '\n')
    print(json.dumps(row, sort_keys=True), flush=True)


def main():
    global BATCHES, LOCK, LOG, LOOP_SCOPE
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--batch', type=int, default=20)
    ap.add_argument('--minutes', type=float, default=30)
    ap.add_argument('--scope', default='Ogre::,RBX::RenderNew,RBX::ViewNew')
    args = ap.parse_args()
    tag = '-'.join(x.replace(':', '').replace('/', '_') for x in args.scope.split(',') if x)
    if not tag:
        ap.error('--scope needs one prefix')
    BATCHES = HERE / 'batches' / tag
    LOCK = HERE / ('auto_loop-' + tag + '.lock')
    LOG = HERE / ('auto_loop-' + tag + '.jsonl')
    LOOP_SCOPE = args.scope
    try:
        fd = os.open(LOCK, os.O_CREAT | os.O_EXCL | os.O_WRONLY)
    except FileExistsError:
        raise SystemExit('auto_loop already running (delete %s if stale)' % LOCK)
    os.close(fd)
    deadline = time.time() + args.minutes * 60
    size = str(args.batch)
    zero_batches = 0
    try:
        for rnd in range(1, 1000):
            before = len(state()[0])
            for stage in (('--next',), ('--next', '--vendor'), ('--repair',)):
                while time.time() < deadline:
                    got = run_all('--scope', args.scope, '--batch', size, *stage)
                    if got is None:
                        break
                    log(round=rnd, stage=' '.join(stage), roots=got['roots'], root_status=got['root_status'],
                        new_exact=got['metrics']['new_exact_addresses'], new_bytes=got['metrics']['new_exact_bytes'])
                    zero_batches = zero_batches + 1 if got['metrics']['new_exact_addresses'] == 0 else 0
                    if zero_batches >= 2:
                        log(round=rnd, stage='stop', reason='two consecutive zero-gain batches')
                        return
                    if stage == ('--repair',):
                        break               # same top callees every time; one batch per round
            _, blocked, synthetic = state()
            again = sorted(blocked | (synthetic if rnd == 1 else set()))   # a name map fix can rename old exacts
            if again and time.time() < deadline:
                retry(again, rnd)
            exact, still, synthetic = state()
            log(round=rnd, stage='round-end', retried=len(again), still_blocked=len(still),
                still_synthetic=len(synthetic), exact_addresses=len(exact), gained=len(exact) - before)
            if len(exact) == before or time.time() >= deadline:
                break
    finally:
        LOCK.unlink()


if __name__ == '__main__':
    main()
