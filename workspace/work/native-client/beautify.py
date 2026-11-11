"""Formatting-only cleanup of native sources, kept only when the proof is unchanged.

clang-format (Ogre style: tabs, Allman braces, 120 columns; includes and comments untouched) -> prove.py on the
file -> keep when every previously exact address is still exact, else restore the original bytes. Whitespace never
changes codegen, but __LINE__ (OGRE_EXCEPT, assert) does, and the proof catches that.

  python work/native-client/beautify.py FILE [FILE ...]      # leases each file for the run
  python work/native-client/beautify.py --check FILE         # print the formatted text, change nothing
"""
import argparse
import json
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
CLANG = Path(r'C:\Program Files\LLVM\bin\clang-format.exe')
STYLE = ('{BasedOnStyle: LLVM, UseTab: ForIndentation, IndentWidth: 4, TabWidth: 4, BreakBeforeBraces: Allman, '
         'ColumnLimit: 120, SortIncludes: Never, ReflowComments: false, NamespaceIndentation: All, '
         'AccessModifierOffset: -4, AllowShortFunctionsOnASingleLine: Inline, PointerAlignment: Left, '
         'IndentPPDirectives: None, MaxEmptyLinesToKeep: 2}')
BANNER = '// >>> native-status'


def formatted(text):
    """clang-format everything except the generated native-status banner block (kept byte-identical)."""
    head, sep, rest = text.partition(BANNER)
    if sep:
        end = rest.index('<<< native-status')
        end = rest.index('\n', end) + 1
        keep = head + sep + rest[:end]
        body = rest[end:]
    else:
        keep, body = '', text
    run = subprocess.run([str(CLANG), '--style=' + STYLE, '--assume-filename=x.cpp'], input=body,
                         capture_output=True, text=True, encoding='utf-8', check=True)
    return keep + run.stdout


def exact(path):
    manifest = HERE / 'prove-out' / ('prove-' + path.stem) / 'manifest.json'
    data = json.loads(manifest.read_text()) if manifest.is_file() else {'families': []}
    return {c for f in data['families'] for r in f['symbols'] if r['status'] == 'inactive_exact'
            for c in (r.get('candidates') or [])}


def prove(path):
    subprocess.run([sys.executable, str(HERE / 'prove.py'), str(path), '--rounds', '1', '--quiet'], cwd=ROOT,
                   capture_output=True, text=True)
    return exact(path)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('files', nargs='+')
    ap.add_argument('--check', action='store_true')
    args = ap.parse_args()
    for name in args.files:
        path = Path(name).resolve()
        raw = path.read_bytes()
        text = raw.decode('utf-8', errors='surrogateescape').replace('\r\n', '\n')
        new = formatted(text)
        if args.check:
            print(new)
            continue
        if new == text:
            print('%s: already formatted' % path.name)
            continue
        if path.suffix != '.cpp' and any(k in text for k in ('__LINE__', 'assert', 'OGRE_EXCEPT')):
            print('%s: header uses line-sensitive macros; not formatted (no single-file proof for headers)' % path.name)
            continue
        rel = path.relative_to(ROOT).as_posix()
        lease = 'beautify-' + path.stem
        if subprocess.run([sys.executable, 'roc.py', 'lease', 'take', lease, rel, '--hours', '1'], cwd=ROOT,
                          capture_output=True, text=True).returncode:
            print('%s: lease refused' % path.name)
            continue
        try:
            before = prove(path)
            path.write_bytes(new.replace('\n', '\r\n').encode('utf-8', errors='surrogateescape'))
            after = prove(path) if path.suffix == '.cpp' else before
            if before <= after:
                print('%s: formatted, %d exact kept' % (path.name, len(before)))
            else:
                path.write_bytes(raw)
                prove(path)
                print('%s: reverted (would lose %d exact; __LINE__ or layout-sensitive)' % (path.name, len(before - after)))
        finally:
            subprocess.run([sys.executable, 'roc.py', 'lease', 'release', lease], cwd=ROOT, capture_output=True)


if __name__ == '__main__':
    main()
