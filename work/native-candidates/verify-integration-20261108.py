"""One-shot post-integration verification for the 2026-11-08 batch.

Run:  python work/native-candidates/verify-integration-20261108.py
Exits non-zero on any failure. Idempotent; writes a receipt only when the
expected integration commit is found on findings/work.
"""
import json
import subprocess
import sys
import time
from pathlib import Path

ROOT = Path(r'C:\Users\colin\RoConstruct')
BASE = '2da654506111296a9f85e38b18500710df5dd5c3'
EXPECTED_WS = 'f5f808063368a6a50888e1d01172c6a5a720e491'
MANIFEST = ROOT / 'work/native-candidates/integration-manifest-20261108.json'


def git(*args):
    return subprocess.check_output(['git', *args], cwd=ROOT).decode().strip()


def run(*args):
    return subprocess.run(args, cwd=ROOT, capture_output=True)


def main():
    p = run('git', 'fetch', '--no-write-fetch-head', 'findings',
            'refs/heads/work:refs/remotes/findings/work')
    if p.returncode:
        print(p.stderr.decode(errors='replace')); sys.exit(1)
    tip = git('rev-parse', 'refs/remotes/findings/work')
    ws = git('rev-parse', f'{tip}:workspace')
    receipt = dict(recorded=time.strftime('%Y-%m-%dT%H:%M:%S'), findings_commit=tip,
                   base=BASE, expected_workspace=EXPECTED_WS, workspace=ws)
    if tip == BASE:
        receipt['status'] = 'not-integrated-yet'
        print(json.dumps(receipt, indent=2)); sys.exit(0)
    if not run('git', 'merge-base', '--is-ancestor', BASE, tip).returncode == 0:
        receipt['status'] = 'base-not-ancestor'; print(json.dumps(receipt, indent=2)); sys.exit(1)
    receipt['status'] = 'integrated' if ws == EXPECTED_WS else 'workspace-mismatch'
    pres = ROOT / f'work/findings-integration/preservation-{tip}.json'
    receipt['preservation_receipt'] = pres.name if pres.exists() else None
    if pres.exists():
        r = json.loads(pres.read_text(encoding='utf-8'))
        receipt['losses'] = len(r.get('losses', []))
    out = ROOT / 'work/native-candidates/integrated-20261108.json'
    out.write_text(json.dumps(receipt, indent=2) + '\n', encoding='utf-8', newline='\n')
    print(json.dumps(receipt, indent=2))
    sys.exit(0 if receipt['status'] == 'integrated' else 1)


if __name__ == '__main__':
    main()
