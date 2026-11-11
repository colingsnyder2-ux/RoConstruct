"""Stop native_drafts watchers whose session has produced no packet for N hours (default 2).

  python work/native-client/stop_stale_watchers.py [--hours 2] [--dry-run]

Each stop is cooperative (`native_drafts stop SESSION`): final checkpoint + flush first, so no draft is lost.
A session can be resumed later with `native_drafts start SESSION`. Sessions that never produced a packet count as stale
once their folder is older than N hours.
"""
import argparse
import re
import subprocess
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def watchers():
    ps = "Get-CimInstance Win32_Process -Filter \"Name='python.exe'\" | ?{$_.CommandLine -match 'native_drafts'} | %{ $_.CommandLine }"
    out = subprocess.run(['powershell', '-NoProfile', '-Command', ps], capture_output=True, text=True).stdout
    return sorted({m[1] for l in out.splitlines() if (m := re.search(r'\bwatch ([0-9a-f]{32})', l))})


def last_activity(session):
    folder = ROOT / 'local/drafts/sessions' / session
    stamps = [p.stat().st_mtime for p in (folder / 'outbox').glob('*')] if (folder / 'outbox').exists() else []
    return max(stamps, default=folder.stat().st_mtime if folder.exists() else 0)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--hours', type=float, default=2.0)
    ap.add_argument('--dry-run', action='store_true')
    args = ap.parse_args()
    now = time.time()
    stopping = []
    for session in watchers():
        idle = (now - last_activity(session)) / 3600
        if idle < args.hours:
            print('keep ', session[:8], 'idle %.1f h' % idle, flush=True)
            continue
        print('stop ', session[:8], 'idle %.1f h' % idle, flush=True)
        stopping.append(session)
        if not args.dry_run:      # same as `native_drafts stop SESSION`: the watcher sees the file, does its final checkpoint + flush, exits
            subprocess.run([sys.executable, '-m', 'roc.native_drafts', '--root', str(ROOT), 'stop', session], capture_output=True, cwd=ROOT)
    if stopping and not args.dry_run:
        deadline = time.time() + 180
        while time.time() < deadline and set(stopping) & set(watchers()):
            time.sleep(5)
        left = set(stopping) & set(watchers())
        print('stopped %d, still running %d (retain their folders; rerun later)' % (len(stopping) - len(left), len(left)))


if __name__ == '__main__':
    main()
