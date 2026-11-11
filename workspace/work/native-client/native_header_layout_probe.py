"""Generate a VS2008 offset probe for fields already declared in a native header.

This is analysis only.  It never adds a field or changes a header; the compiler
is the authority for the current declaration layout.
"""
import argparse
from pathlib import Path


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--include', required=True, help='native header include path')
    ap.add_argument('--type', required=True, dest='type_')
    ap.add_argument('--field', action='append', required=True)
    ap.add_argument('--force-public-default', action='store_true')
    ap.add_argument('--force-public-type',
                    help='copy this one existing header into a work-only overlay and change only its class declaration to struct')
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    include = args.include
    if args.force_public_type:
        header = Path.cwd() / 'rebuild/2008-06/native-headers' / args.include
        text = header.read_text(encoding='utf-8')
        old = 'class ' + args.force_public_type
        new = 'struct ' + args.force_public_type
        if text.count(old) != 1:
            raise SystemExit('expected exactly one declaration: ' + old)
        overlay = args.output.parent / '_layout_overlays' / args.include
        overlay.parent.mkdir(parents=True, exist_ok=True)
        overlay.write_text(text.replace(old, new), encoding='utf-8')
        include = str(overlay.resolve()).replace('\\', '/')
    lines = ['// generated layout probe; reads existing declaration only', '#define private public',
             '#define protected public']
    if args.force_public_default:
        lines.append('#define class struct')
    lines += ['#include "%s"' % include]
    if args.force_public_default:
        lines.append('#undef class')
    lines += ['#undef protected', '#undef private', '']
    for field in args.field:
        name = 'roc_offset_' + ''.join(ch if ch.isalnum() else '_' for ch in field)
        lines.append('extern "C" unsigned __cdecl %s() { return (unsigned)&((%s*)0)->%s; }' %
                     (name, args.type_, field))
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text('\n'.join(lines) + '\n')
    print('generated', args.output, 'fields', len(args.field))


if __name__ == '__main__':
    main()
