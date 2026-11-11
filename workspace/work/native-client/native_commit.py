"""One command for a native commit: lease the paths, write their banners, commit, push, release.

  python work/native-client/native_commit.py -m "message" PATH [PATH ...] [--no-push]

Native files (rebuild/<client>/native-*) get a lease and a path-scoped banner write; other paths are committed as
they are (tool .py files under work/ are force-added). The pre-commit hook still runs lease/banner checks.
"""
import argparse
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
TRAILER = '\n\nCo-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>\n'


def run(*argv, check=True):
    done = subprocess.run(argv, cwd=ROOT, capture_output=True, text=True, encoding='utf-8', errors='replace')
    if check and done.returncode:
        sys.exit('failed: %s\n%s' % (' '.join(argv[:4]), (done.stdout + done.stderr)[-1500:]))
    return done


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('-m', '--message', required=True)
    ap.add_argument('paths', nargs='+')
    ap.add_argument('--no-push', action='store_true')
    args = ap.parse_args()
    paths = [Path(p).as_posix() for p in args.paths]
    native = [p for p in paths if '/native-' in p and p.startswith('rebuild/')]
    name = 'commit-' + Path(paths[0]).stem
    py = sys.executable
    if native:
        run(py, 'roc.py', 'lease', 'take', name, *native, '--hours', '1')
    try:
        if native:        # one banner pass for every native path (each pass indexes the whole tree)
            run(py, 'scripts/native_status.py', '--write', *sum((['--path', p] for p in native), []))
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
