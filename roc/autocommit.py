"""Auto-save: commit and push all source work in this checkout. Runs inside the server's publish cycle
(roc/server.py _publish_once, every 6 h by default since 2026-11-10); there is no separate scheduler.

Commits rebuild/, roc/, research/, tests/, docs/ (guides), root docs, plus the tool scripts under
work/native-client (work/ is otherwise ignored).  Pathspec commit: staged changes elsewhere are left alone.
Refuses the run if any staged file is a binary/build artifact, over 20 MB, or contains a secret pattern.

  python roc/autocommit.py                 # run once by hand
  python roc/autocommit.py --dry-run       # list what would be committed

Log: work/autocommit.jsonl.
"""
import argparse
import datetime
import json
import os
import re
import subprocess
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
LOG = ROOT / 'work' / 'autocommit.jsonl'
LOCK = ROOT / 'work' / 'autocommit.lock'
PATHS = ['rebuild', 'roc', 'research', 'tests', 'docs', 'roc.py', 'roc.cmd', 'roc.sh',
         'CLAUDE.md', 'AGENTS.md', 'README.md', '.gitignore']
# Tool code only from the ignored work/ tree: never outputs, caches, objects or receipts.
TOOLS = ['work/native-client/*.py', 'work/native-client/ogre/*.py', 'work/native-client/CLAUDE_HANDOFF.md',
         'work/native-client/native-llm/bin/opencode.cmd']
BINARY = re.compile(r'\.(obj|o|lib|a|exe|dll|pdb|ilk|exp|idb|pch|zip|7z|rar|gz|bz2|db|sqlite|bin)$', re.I)
SECRET = re.compile(rb'discord(?:app)?\.com/api/webhooks/\d{6,}/[\w-]{20,}|ghp_[A-Za-z0-9]{30,}|github_pat_\w{30,}|'
                    rb'nvapi-[A-Za-z0-9_\-]{20,}|sk-[A-Za-z0-9]{32,}|-----BEGIN [A-Z ]*PRIVATE KEY')
MAX_BYTES = 20 * 1024 * 1024


def git(*args, check=False):
    run = subprocess.run(['git', *args], cwd=ROOT, capture_output=True, text=True, encoding='utf-8', errors='replace')
    if check and run.returncode:
        raise RuntimeError('git %s: %s' % (' '.join(args[:2]), (run.stderr or run.stdout).strip()[-400:]))
    return run


def log(**row):
    row['time'] = datetime.datetime.now().isoformat(timespec='seconds')
    LOG.parent.mkdir(exist_ok=True)
    with LOG.open('a', encoding='utf-8') as out:
        out.write(json.dumps(row) + '\n')
    print(json.dumps(row))


def stage():
    """Stage our paths; return the staged file list inside them."""
    paths = [p for p in PATHS if (ROOT / p).exists()]
    # The pre-commit hook refuses stale native-status banners; regenerate them (idempotent, generated lines only).
    # The writer requires a live lease of ours on every file it touches: hold one briefly over the native dirs.
    roc = [sys.executable, str(ROOT / 'roc.py')]
    lease = 'autocommit-native-banners'
    subprocess.run(roc + ['lease', 'take', lease, 'rebuild/2008-06/native-classes/*', 'rebuild/2008-06/native-headers/*',
                          'rebuild/2008-06/native-world/*', '--hours', '1'], cwd=ROOT, capture_output=True, text=True)
    try:
        banner = subprocess.run(roc + ['native-status', '--write'], cwd=ROOT, capture_output=True, text=True)
        if banner.returncode:
            log(state='banner-write-failed', error=(banner.stdout + banner.stderr).strip()[-400:])
    finally:
        subprocess.run(roc + ['lease', 'release', lease], cwd=ROOT, capture_output=True, text=True)
    git('add', '-A', '--', *paths, check=True)
    tools = sorted({str(p.relative_to(ROOT)).replace('\\', '/') for pattern in TOOLS for p in ROOT.glob(pattern)})
    if tools:
        git('add', '-f', '--', *tools, check=True)
    # A file another worker edits between the banner write and here would fail the hook: skip it this cycle.
    check = subprocess.run([sys.executable, str(ROOT / 'scripts' / 'native_status.py'), '--check', '--staged'],
                           cwd=ROOT, capture_output=True, text=True)
    stale = [line[len('STALE: '):].strip().replace('\\', '/') for line in check.stdout.splitlines()
             if line.startswith('STALE: ')]
    if stale:
        git('reset', '-q', '--', *stale)
        log(state='skipped-stale-banners', files=stale[:20], count=len(stale))
    names = git('diff', '--cached', '--name-only', '-z', '--', *paths, *tools, check=True).stdout
    return [n for n in names.split('\0') if n], paths + tools


def unsafe(files):
    bad = []
    for name in files:
        path = ROOT / name
        if not path.is_file():
            continue                                   # a deletion or rename source
        if BINARY.search(name):
            bad.append((name, 'binary/build artifact'))
        elif path.stat().st_size > MAX_BYTES:
            bad.append((name, 'over 20 MB'))
        elif SECRET.search(path.read_bytes()):
            bad.append((name, 'secret pattern'))
    return bad


def run_once(dry_run=False, message=None):
    import msvcrt
    LOCK.parent.mkdir(exist_ok=True)
    handle = LOCK.open('a+b')
    try:
        msvcrt.locking(handle.fileno(), msvcrt.LK_NBLCK, 1)
    except OSError:
        return log(state='skipped', why='another auto-commit is running')
    try:
        if (ROOT / '.git' / 'index.lock').exists():
            return log(state='skipped', why='git index locked by another git command')
        files, specs = stage()
        if not files:
            return log(state='nothing-to-commit')
        bad = unsafe(files)
        if bad:
            git('reset', '-q', '--', *[n for n, _ in bad])   # unstage only the refused files
            log(state='refused-files', files=bad[:20], count=len(bad))
            files = [n for n in files if n not in {b for b, _ in bad}]
            if not files:
                return log(state='nothing-safe-to-commit')
        if dry_run:
            return log(state='dry-run', count=len(files), sample=files[:30])
        msg = message or 'Auto-save native work (%s)' % datetime.datetime.now().strftime('%Y-%m-%d %H:%M')
        commit = git('commit', '-q', '-m', msg, '--', *specs)
        if commit.returncode:
            return log(state='commit-failed', error=(commit.stderr or commit.stdout).strip()[-600:])
        sha = git('rev-parse', '--short', 'HEAD').stdout.strip()
        for wait in (0, 2, 4, 8, 16):                 # network retries only
            time.sleep(wait)
            push = git('push', '-u', 'origin', 'HEAD')
            if push.returncode == 0 or 'rejected' in push.stderr:
                break
        log(state='pushed' if push.returncode == 0 else 'push-failed', commit=sha, files=len(files),
            error=None if push.returncode == 0 else push.stderr.strip()[-400:])
    finally:
        handle.close()


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--dry-run', action='store_true')
    ap.add_argument('--message')
    args = ap.parse_args()
    os.chdir(ROOT)
    run_once(args.dry_run, args.message)


if __name__ == '__main__':
    main()
