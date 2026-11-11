"""Upstream-verbatim lane: copy library source files into native classes and keep the ones that prove byte-exact.

For a library whose exe copy is the stock upstream code (G3D 6.09 here), each upstream .cpp becomes
rebuild/2008-06/native-classes/<Prefix><Stem>.cpp with a `// native-flags:` line, is proved with prove.py (names inferred),
and is kept only if at least one function is byte-exact; otherwise it is moved to work/native-client/converter-failed/.
One summary line per file. Files already present are re-proved, never overwritten.

  python work/native-client/upstream_lane.py --root tools/libs/g3d-6.09/source --prefix G3D G3Dcpp/Matrix3.cpp ...
  python work/native-client/upstream_lane.py --root tools/libs/g3d-6.09/source --prefix G3D --all-in G3Dcpp GLG3Dcpp
"""
import argparse
import json
import re
import shutil
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
CLASSES = ROOT / 'rebuild/2008-06/native-classes'
FAILED = HERE / 'converter-failed'
FLAGS = '/O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast'


def prove(path):
    run = subprocess.run([sys.executable, str(HERE / 'prove.py'), str(path), '--rounds', '3', '--infer-names', '--quiet'],
                         cwd=ROOT, capture_output=True, text=True)
    rows = [json.loads(l) for l in run.stdout.splitlines() if l.startswith('{')]
    return rows[-1] if rows else None


def compile_error(path):
    logs = sorted((HERE / 'prove-out' / ('prove-' + path.stem) / 'objects').rglob('*.log'), key=lambda p: -p.stat().st_mtime)
    for log in logs[:1]:
        errs = [l.strip()[-180:] for l in log.read_text(errors='replace').splitlines() if ' error ' in l or 'fatal error' in l]
        if errs:
            return errs[0]
    return None


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('files', nargs='*')
    ap.add_argument('--root', required=True, help='upstream source root, repo-relative')
    ap.add_argument('--prefix', required=True)
    ap.add_argument('--all-in', nargs='*', default=[], help='sub-directories of --root whose every .cpp is tried')
    ap.add_argument('--flags', default=FLAGS)
    ap.add_argument('--skip-existing', action='store_true')
    args = ap.parse_args()
    root = ROOT / args.root
    files = list(args.files)
    for d in args.all_in:
        files += sorted(p.relative_to(root).as_posix() for p in (root / d).glob('*.cpp') if not p.name.startswith('roc_'))   # roc_*: our generated analogs, not upstream
    kept = total = 0
    for rel in files:
        src = root / rel
        if not src.is_file():
            print('%-34s missing upstream file' % rel)
            continue
        dest = CLASSES / ('%s%s.cpp' % (args.prefix, src.stem))
        if dest.exists() and args.skip_existing:
            continue
        existed = dest.exists()
        if not existed:
            text = src.read_text(errors='replace').replace('\r\n', '\n')
            head = '// native-flags: %s\n// 2008-06 native %s%s (inactive): upstream %s, verbatim.\n' % (
                args.flags, args.prefix, src.stem, (Path(args.root) / rel).as_posix())
            dest.write_bytes((head + text).replace('\n', '\r\n').encode('utf-8', errors='replace'))
        row = prove(dest)
        err = compile_error(dest) if not row or not row['exact'] else None
        if row and row['exact']:
            kept += 1
            total += row['exact_bytes']
            print('%-34s %4d exact %7d B (%s inferred)' % (dest.name, row['exact'], row['exact_bytes'], row['inferred_name_addrs']), flush=True)
        else:
            if not existed:
                out = FAILED / dest.stem
                out.mkdir(parents=True, exist_ok=True)
                shutil.move(str(dest), str(out / dest.name))
            print('%-34s none  %s' % (dest.name, err or 'no exact function'), flush=True)
    print('kept %d files, %d exact bytes' % (kept, total))


if __name__ == '__main__':
    main()
