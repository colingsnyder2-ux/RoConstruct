"""Re-prove library native files after a checker change and report the files whose exact bytes moved.

  python work/native-client/reprove_libs.py PREFIX [PREFIX ...]      e.g. G3D XTP Lua Png Jpeg Boost Zlib Mfc Scint Atl
  python work/native-client/reprove_libs.py --why "reference identity differs" G3D XTP Mfc

Per-file proofs (cached objects are reused), not a census. Prints `file  old -> new B` only for files that changed.
--why FILTER re-proves only files whose last proof (work/native-client/prove-out/prove-<file>/manifest.json) has a
rejection error containing FILTER: after a checker fix, only the files blocked by that error need a new proof.
"""
import argparse
import json
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
LOG = HERE / 'prove-log.jsonl'


def latest():
    out = {}
    for line in LOG.read_text(errors='replace').splitlines():
        try:
            d = json.loads(line)
        except ValueError:
            continue
        if d.get('family', '').startswith('prove-'):
            out[d['family']] = d['exact_bytes']
    return out


def blocked_by(source, needle):
    """True when the file's last per-file proof rejected a symbol with an error containing `needle`."""
    manifest = HERE / 'prove-out' / ('prove-' + source.stem) / 'manifest.json'
    if not manifest.exists():
        return True     # never proved: include it
    try:
        data = json.loads(manifest.read_text(encoding='utf-8'))
    except ValueError:
        return True
    return any(needle in error for family in data.get('families', []) for row in family.get('symbols', [])
               for rejection in row.get('rejections', []) for error in rejection.get('errors', []))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('prefixes', nargs='+')
    ap.add_argument('--why', help='only files whose last proof has a rejection error containing this text')
    args = ap.parse_args()
    before = latest()
    files = sorted({p for prefix in args.prefixes for p in (ROOT / 'rebuild/2008-06/native-classes').glob(prefix + '*.cpp')})
    if args.why:
        total = len(files)
        files = [f for f in files if blocked_by(f, args.why)]
        print('%d of %d files blocked by %r' % (len(files), total, args.why), flush=True)
    gain = 0
    for f in files:
        run = subprocess.run([sys.executable, str(HERE / 'prove.py'), str(f), '--rounds', '2', '--infer-names', '--quiet'],
                             cwd=ROOT, capture_output=True, text=True)
        rows = [json.loads(l) for l in run.stdout.splitlines() if l.startswith('{')]
        if not rows:
            print('%-36s proof produced no result (compile clash?): rerun it alone' % f.name, flush=True)
            continue
        new, old = rows[-1]['exact_bytes'], before.get('prove-' + f.stem, 0)
        if new != old:
            gain += new - old
            print('%-36s %7d -> %7d B (%+d)' % (f.name, old, new, new - old), flush=True)
    print('DONE %d files, net %+d B' % (len(files), gain), flush=True)


if __name__ == '__main__':
    main()
