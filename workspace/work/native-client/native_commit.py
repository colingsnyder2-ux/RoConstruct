"""One command for a native commit: lease the paths, write their banners, commit, push, release.

  python work/native-client/native_commit.py -m "message" PATH [PATH ...] [--no-push]

Native files (rebuild/<client>/native-*) get a lease (no banner is written: the generated top-of-file banners are optional); other paths are committed as
they are (tool .py files under work/ are force-added). The pre-commit hook still runs lease/banner checks.
"""
import argparse
import json
import os
import subprocess
import time
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
TRAILER = '\n\nCo-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>\n'


def run(*argv, check=True):
    done = subprocess.run(argv, cwd=ROOT, capture_output=True, text=True, encoding='utf-8', errors='replace')
    if check and done.returncode:
        sys.exit('failed: %s\n%s' % (' '.join(argv[:4]), (done.stdout + done.stderr)[-1500:]))
    return done


def census_running():
    """A `prove.py --all` census is live: editing native files now would void its results."""
    lock = ROOT / 'work/native-client/prove-out/CENSUS.lock'
    try:
        info = json.loads(lock.read_text())
    except (OSError, ValueError):
        return False
    if time.time() - info['started'] > 4 * 3600:
        return False
    try:
        os.kill(info['pid'], 0)
    except (OSError, SystemError):
        return False
    return True


def minutes_since_last_commit():
    stamp = run('git', 'log', '-1', '--format=%ct').stdout.strip()
    return (time.time() - int(stamp or 0)) / 60


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('-m', '--message', required=True)
    ap.add_argument('paths', nargs='+')
    ap.add_argument('--no-push', action='store_true')
    ap.add_argument('--force', action='store_true', help='skip the commit-cadence guard (batch commits: one family, at most hourly)')
    args = ap.parse_args()
    if census_running():
        sys.exit('refused: a prove.py --all census is running; native edits would void it. Wait for it or stop it.')
    if not args.force and minutes_since_last_commit() < 45:
        sys.exit('refused: last commit was %d min ago. Batch your work (one family, at most hourly) or pass --force.' % minutes_since_last_commit())
    paths = [Path(p).as_posix() for p in args.paths]
    native = [p for p in paths if '/native-' in p and p.startswith('rebuild/')]
    name = 'commit-' + Path(paths[0]).stem
    py = sys.executable
    if native:
        patterns = native
        if len(native) > 150:      # the server accepts at most 200 globs: lease the parent directories instead
            patterns = sorted({Path(p).parent.as_posix() + '/*' for p in native})
        run(py, 'roc.py', 'lease', 'take', name, *patterns, '--hours', '1')
    try:
        run('git', 'add', '-f', *paths)
        run('git', 'commit', '-q', '-m', args.message.rstrip() + TRAILER)
        print(run('git', 'log', '--oneline', '-1').stdout.strip())
        if not args.no_push:
            branch = run('git', 'rev-parse', '--abbrev-ref', 'HEAD').stdout.strip()
            run('git', 'push', '-q', '-u', 'origin', branch)
            print('pushed', branch)
    finally:
        if native:
            run(py, 'roc.py', 'lease', 'release', name, check=False)


if __name__ == '__main__':
    main()
