"""Remove scaffolding explicit template instantiations from a native source when proofs do not need them.

  python work/native-client/drop_explicit_instantiations.py rebuild/2008-06/native-classes/X.cpp [--dry-run] [--all]

Proof scaffolding often forces members with single-line `template class ...;` statements the original source never
had (its callers instantiated them implicitly). Run this when a file's callers are native and exact, as the last step
before integration. It proves the file, tries removing every candidate at once, and bisects only when that loses
exact bytes, so the result is a largest removal set whose proof keeps every exact byte. By default only std:: /
stdext:: instantiations are candidates (project-template ones such as MeshFactory<...> may be original); --all includes
every single-line explicit instantiation. The file is restored if anything fails. Lease the file before running.
"""
import argparse
import json
import re
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
LINE = re.compile(r'^template class (.+);\s*$')


def prove(path):
    run = subprocess.run([sys.executable, str(HERE / 'prove.py'), str(path), '--rounds', '1', '--quiet'],
                         cwd=ROOT, capture_output=True, text=True)
    rows = [json.loads(l) for l in run.stdout.splitlines() if l.startswith('{')]
    if run.returncode or not rows:
        raise RuntimeError('proof failed: ' + (run.stderr.strip().splitlines() or ['no output'])[-1][:200])
    return rows[-1]['exact_bytes']


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('source')
    ap.add_argument('--dry-run', action='store_true', help='list candidates only')
    ap.add_argument('--all', action='store_true', help='also try project-template instantiations')
    args = ap.parse_args()
    path = (ROOT / args.source).resolve()
    original = path.read_text(encoding='utf-8')
    lines = original.splitlines(keepends=True)
    candidates = [i for i, text in enumerate(lines)
                  if (m := LINE.match(text)) and (args.all or re.match(r'(std|stdext)::', m.group(1)))]
    print('%s: %d candidate instantiations' % (path.name, len(candidates)))
    if args.dry_run or not candidates:
        return

    def attempt(drop):
        path.write_text(''.join(t for i, t in enumerate(lines) if i not in drop), encoding='utf-8')
        try:
            return prove(path)
        except RuntimeError:
            return -1      # no longer compiles: something used it

    try:
        baseline = prove(path)
        print('baseline exact bytes:', baseline)
        kept_removed = set()

        def solve(group):
            # largest subset of `group` removable alongside kept_removed without losing exact bytes
            if not group:
                return
            if attempt(kept_removed | set(group)) >= baseline:
                kept_removed.update(group)
                return
            if len(group) == 1:
                return
            half = len(group) // 2
            solve(group[:half])
            solve(group[half:])

        solve(candidates)
        final = attempt(kept_removed)
        if final < baseline:     # interactions between halves: fall back to the original
            raise RuntimeError('combined removal lost bytes (%d < %d)' % (final, baseline))
        print(json.dumps({'file': path.relative_to(ROOT).as_posix(), 'baseline': baseline, 'final': final,
                          'removed': len(kept_removed), 'kept': len(candidates) - len(kept_removed)}))
    except BaseException:
        path.write_text(original, encoding='utf-8')
        raise


if __name__ == '__main__':
    main()
