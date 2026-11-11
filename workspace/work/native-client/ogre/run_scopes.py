"""Whole-client converter fan-out, no LLM: split every code unit into disjoint --scope prefixes and run
auto_loop.py for several scopes at once (each scope already owns its batches/cache/lock).

  python work/native-client/ogre/run_scopes.py --dry-run          # show the partition only
  python work/native-client/ogre/run_scopes.py --jobs 6           # run detached for hours; then read
  work/native-client/ogre/run_scopes.status.json                  # one small file: progress + totals

Nothing here decides exactness; ogre_convert.py's proofs do.  Finished scopes are skipped on restart.
"""
import argparse
import collections
import json
import os
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(ROOT))
from roc import match  # noqa: E402

STATUS = HERE / 'run_scopes.status.json'
LOG = HERE / 'run_scopes.jsonl'
BAD = set('<>"|?*\\/ \t')          # characters a scope tag (a folder name) cannot carry


def partition(limit):
    """Disjoint unit-name prefixes, each covering <= limit functions where it can be split safely."""
    units = collections.Counter(row.get('unit', '') for row in match._functions('2008-06').values()
                                if row.get('kind') == 'code' and row.get('unit'))
    out = []

    def split(prefix, names):
        size = sum(units[n] for n in names)
        kids = collections.defaultdict(list)
        for name in names:
            kids[name[:len(prefix) + 1]].append(name)
        # Stop when small enough, when a unit is exactly this prefix (it would overlap its children),
        # or when a child prefix could not be a folder name.
        if size <= limit or prefix in names or any(k[-1] in BAD for k in kids):
            out.append((prefix, size))
            return
        for kid, group in kids.items():
            split(kid, group)

    split('', list(units))
    # Tags are Windows folder names: 'Co'/'CO' and 'RBX::I'/'RBXI' would share one.  --scope takes a
    # comma list, so prefixes whose tags collide run together as one scope.
    merged = collections.defaultdict(lambda: [[], 0])
    for prefix, size in out:
        merged[tag(prefix).lower()][0].append(prefix)
        merged[tag(prefix).lower()][1] += size
    return sorted(((','.join(sorted(p)), n) for p, n in merged.values()), key=lambda item: -item[1])


def tag(prefix):                     # same rule as run_all.py / auto_loop.py
    return prefix.replace(':', '').replace('/', '_')


def run(prefix, size, args):
    started = time.time()
    env = dict(os.environ, ROC_JOBS=str(max(2, (os.cpu_count() or 8) // args.jobs)))
    proc = subprocess.run([sys.executable, '-u', str(HERE / 'auto_loop.py'), '--scope', prefix,
                           '--batch', str(args.batch), '--minutes', str(args.minutes)],
                          cwd=ROOT, env=env, text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    last = {}
    for line in proc.stdout.splitlines():
        if line.startswith('{') and '"round-end"' in line:
            last = json.loads(line)
    return dict(scope=prefix, functions=size, exit=proc.returncode, seconds=round(time.time() - started, 1),
                exact_addresses=last.get('exact_addresses'), still_blocked=last.get('still_blocked'),
                converged=last.get('gained') == 0, tail='' if last else proc.stdout[-300:])


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--jobs', type=int, default=6, help='scopes in parallel (compile threads are split between them)')
    ap.add_argument('--batch', type=int, default=100, help='big batches: startup cost per batch is ~10 s')
    ap.add_argument('--minutes', type=float, default=600, help='time limit per scope')
    ap.add_argument('--limit', type=int, default=1500, help='functions per scope before splitting deeper')
    ap.add_argument('--only', default='', help='run only scopes starting with this prefix')
    ap.add_argument('--dry-run', action='store_true')
    args = ap.parse_args()
    plan = [(p, n) for p, n in partition(args.limit) if p.startswith(args.only)]
    done = {}
    if LOG.is_file():
        done = {row['scope']: row for row in map(json.loads, LOG.open()) if row.get('converged')}
    todo = [(p, n) for p, n in plan if p not in done]
    print('%d scopes, %d functions; %d already converged' % (len(plan), sum(n for _, n in plan), len(plan) - len(todo)))
    if args.dry_run:
        for p, n in plan:
            print('%6d  %s%s' % (n, p, '  (done)' if p in done else ''))
        return
    rows = list(done.values())

    def one(item):
        row = run(*item, args)
        rows.append(row)
        with LOG.open('a') as out:
            out.write(json.dumps(row, sort_keys=True) + '\n')
        STATUS.write_text(json.dumps({
            'time': time.strftime('%Y-%m-%d %H:%M:%S'), 'scopes_total': len(plan), 'scopes_finished': len(rows),
            'functions_covered': sum(r['functions'] for r in rows),
            'exact_addresses': sum(r['exact_addresses'] or 0 for r in rows),
            'still_blocked': sum(r['still_blocked'] or 0 for r in rows),
            'not_converged': [r['scope'] for r in rows if not r['converged']][:40]}, indent=1) + '\n')

    with ThreadPoolExecutor(args.jobs) as pool:
        list(pool.map(one, todo))


if __name__ == '__main__':
    main()
