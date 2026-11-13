"""Dump compiler-derived class layouts for a native source's real headers.

Runs VS2008 `cl /Zs /d1reportAllClassLayout` (front end only, no object) with
the source's normal flags and parses every `class X size(N):` block into JSON:
size, base classes, vfptr/vbptr and every member offset.  This is what the
compiler believes the headers say.  It is header evidence, not target proof:
compare offsets against displacement operands of byte-exact methods.
"""
import argparse
import importlib.util
import json
import re
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import rebuild  # noqa: E402

HEAD = re.compile(r'^class (.+?)\s+size\((\d+)\):\s*$')
BASE = re.compile(r'^\s*\|\s?([| ]*)\+--- \(base class (.*)\)\s*$')
ROW = re.compile(r'^\s*(\d+)\s*\|\s?([| ]*)(.*?)\s*$')


def runner():
    path = ROOT / 'rebuild/2008-06/tests/native_check_runner.py'
    spec = importlib.util.spec_from_file_location('_layout_native_checker', path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def parse(log):
    classes, current = {}, None
    for line in log.splitlines():
        head = HEAD.match(line)
        if head:
            current = classes.setdefault(head[1], {'size': int(head[2]), 'bases': [], 'members': []})
            current['bases'], current['members'] = [], []
            continue
        if current is None:
            continue
        if line.startswith('\t+---') and current['members']:
            current = None if current.get('closed') else current
            if current is not None:
                current['closed'] = True
            continue
        base = BASE.match(line)
        if base:
            # offset is the next numbered row; depth 0 = direct base
            current['bases'].append({'offset': None, 'class': base[2], 'depth': base[1].count('|')})
            continue
        row = ROW.match(line.replace('\t', ''))
        if not row:
            continue
        offset, nesting, text = int(row[1]), row[2].count('|'), row[3]
        for b in current['bases']:
            if b['offset'] is None:
                b['offset'] = offset
        if text.startswith('+---') or not text or text.startswith('<alignment'):
            continue
        else:
            current['members'].append({'offset': offset, 'name': text, 'depth': nesting})
    for value in classes.values():
        value.pop('closed', None)
    return classes


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('source', type=Path)
    ap.add_argument('--output', type=Path, required=True)
    ap.add_argument('--match', default='', help='keep only classes whose name contains this text')
    args = ap.parse_args()
    source = args.source.resolve()
    flags = [f for f in runner().compiler_flags(source) if f != '/c']
    args.output.parent.mkdir(parents=True, exist_ok=True)
    started = time.monotonic()
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl',
                            flags + ['/Zs', '/d1reportAllClassLayout', str(source)], args.output.parent)
    seconds = round(time.monotonic() - started, 2)
    classes = {k: v for k, v in parse(log).items() if args.match in k}
    args.output.write_text(json.dumps({'source': str(source.relative_to(ROOT)).replace('\\', '/'),
                                       'compiler_exit': code, 'seconds': seconds,
                                       'scope': 'compiler view of existing headers; not target layout proof',
                                       'classes': classes}, indent=1) + '\n')
    print('exit', code, 'seconds', seconds, 'classes', len(classes))


if __name__ == '__main__':
    main()
