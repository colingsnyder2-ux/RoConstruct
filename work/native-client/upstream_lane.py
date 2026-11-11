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


def recipe_plan(name):
    """-> (repo-relative source root, {path: native-flags}) from the recipe's mined analogs (winning roc-flags, recipe defines/includes)."""
    import collections
    import glob
    sys.path.insert(0, str(ROOT))
    from roc import libs
    r = libs.RECIPES[name]
    root = (libs.LIBS / r['src']).resolve()
    seen = collections.defaultdict(collections.Counter)
    for f in glob.glob(str(ROOT / 'src/2008-06/*.cpp')):
        head = open(f, errors='replace').read(1500)
        m = re.search(r'^// roc-lib:\s*(\S+)\s+(\S+)', head, re.M)
        if m and m.group(1) == name and not Path(m.group(2)).name.startswith('roc_'):
            fl = re.search(r'^// roc-flags:\s*(.*)$', head, re.M)
            seen[m.group(2)][fl.group(1).strip() if fl else FLAGS] += 1
    defines = ' '.join('/D' + d for d in r.get('defines', '').split())
    incs = ' '.join('/I{headers}/../../../%s' % (Path(libs.LIBS / i).resolve().relative_to(ROOT).as_posix())
                    for i in r.get('include', []) if i != 'WINSDK' and (libs.LIBS / i).exists())
    plan = {}
    for path, counts in seen.items():
        fl = counts.most_common(1)[0][0]
        extra = (' /TC' if path.endswith('.c') else '')
        plan[path] = ('%s %s %s /I{headers}/../../../%s%s' % (fl, defines, incs, (root / Path(path).parent).relative_to(ROOT).as_posix(), extra)).replace('  ', ' ')
    return root.relative_to(ROOT).as_posix(), plan


CRLF = chr(13) + chr(10)
OPT = ('/O', '/G', '/EH', '/M', '/arch', '/fp')


def reflag(dest, plan):
    """Replace the optimisation flags on the file's native-flags line with the plan's; revert unless more bytes prove."""
    if not plan:
        return
    raw = dest.read_bytes()
    text = raw.decode('utf-8', errors='replace')
    first, _, rest = text.partition(CRLF)
    if not first.startswith('// native-flags: '):
        return
    old = first[len('// native-flags: '):].split()
    win = [t for t in plan.split() if t.startswith(OPT) and not t.startswith(('/D', '/I', '/FI'))]
    new = [t for t in old if not t.startswith(OPT) or t.startswith(('/D', '/I', '/FI'))] + win
    if new == old or set(new) == set(old):
        return
    before = prove(dest)
    b = before['exact_bytes'] if before else 0
    dest.write_bytes(('// native-flags: ' + ' '.join(new) + CRLF + rest).encode('utf-8', errors='replace'))
    after = prove(dest)
    a = after['exact_bytes'] if after else 0
    if a > b:
        print('%-34s reflag %7d -> %7d B  (%s)' % (dest.name, b, a, ' '.join(win)), flush=True)
    else:
        dest.write_bytes(raw)
        prove(dest)
        print('%-34s reflag kept old (%d vs %d)' % (dest.name, b, a), flush=True)


def line_directive(recipe, rel):
    """`#line 1 "<name the original build saw>"` so __LINE__/__FILE__ in assert macros match the exe (recipe file_names)."""
    if not recipe:
        return ''
    sys.path.insert(0, str(ROOT))
    from roc import libs
    names = libs.RECIPES[recipe].get('file_names') or {}
    key = rel.replace('/', chr(92))
    name = names.get(key) or (names['*'](key) if callable(names.get('*')) else None)
    if not name:
        return ''
    return '#line 1 "' + name.replace(chr(92), chr(92) * 2) + '"' + chr(13) + chr(10)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('files', nargs='*')
    ap.add_argument('--root', help='upstream source root, repo-relative')
    ap.add_argument('--recipe', help='library recipe: files, flags, defines and includes come from its mined analogs')
    ap.add_argument('--prefix', required=True)
    ap.add_argument('--all-in', nargs='*', default=[], help='sub-directories of --root whose every .cpp is tried')
    ap.add_argument('--flags', default=FLAGS)
    ap.add_argument('--skip-existing', action='store_true')
    ap.add_argument('--reflag', action='store_true', help='existing files: swap in the winning optimisation flags; keep only if more bytes prove')
    ap.add_argument('--list', help='text file of root-relative upstream paths, one per line')
    ap.add_argument('--own-dir', action='store_true', help='add /I for the directory of each file (sibling quoted includes)')
    args = ap.parse_args()
    per_file = {}
    if args.recipe:
        args.root, per_file = recipe_plan(args.recipe)
        args.list = None
    elif not args.root:
        ap.error('--root or --recipe')
    root = ROOT / args.root
    files = list(args.files) + list(per_file)
    if args.list:
        files += [l.strip() for l in Path(args.list).read_text().splitlines() if l.strip()]
    for d in args.all_in:
        files += sorted(p.relative_to(root).as_posix() for p in (root / d).glob('*.cpp') if not p.name.startswith('roc_'))   # roc_*: our generated analogs, not upstream
    kept = total = 0
    for rel in files:
        src = root / rel
        if not src.is_file():
            print('%-34s missing upstream file' % rel)
            continue
        dest = CLASSES / ('%s.cpp' % (src.stem if src.stem.startswith(args.prefix) else args.prefix + src.stem))
        if dest.exists() and args.skip_existing:
            continue
        existed = dest.exists()
        if existed and args.reflag:
            reflag(dest, per_file.get(rel))
            continue
        if not existed:
            text = src.read_text(errors='replace').replace('\r\n', '\n')
            flags = per_file.get(rel) or args.flags
            flags = flags + (' /I{headers}/../../../%s' % (Path(args.root) / rel).parent.as_posix() if args.own_dir else '')
            head = '// native-flags: %s\n// 2008-06 native %s%s (inactive): upstream %s, verbatim.\n' % (
                flags, args.prefix, src.stem, (Path(args.root) / rel).as_posix())
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
