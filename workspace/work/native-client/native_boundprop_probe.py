"""Compile a real BoundProp template instantiation and prove one target body.

This is a deterministic discovery route for mined BoundPropGetSet stand-ins.
It produces only work files/JSON; promotion into an owned native class is a
separate leased action.
"""
import argparse
import json
import sys
import time
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import libs, match, rebuild
from roc.fingerprint import Target


def compile_probe(source, output, flags):
    recipe = libs.RECIPES['rbxgs']
    headers = ROOT / 'rebuild/2008-06/native-headers'
    cl_flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD',
                '/D_AFXDLL', '/DNDEBUG', '/D_MBCS', '/DBOOST_ALL_NO_LIB']
    cl_flags += ['/D' + value for value in recipe['defines'].split()]
    cl_flags += ['/I' + str(headers), '/I' + str(ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/include')]
    cl_flags += ['/I' + str((libs.LIBS / value).resolve()) for value in recipe['include'] if value != 'WINSDK']
    cl_flags += flags + ['/D_XTP_STATICLINK', '/D_XTPLIB_NOAUTOLINK',
                         '/I' + str(ROOT / 'tools/libs/xtp-11.2.2/Source'),
                         '/Fo' + str(output / 'candidate.obj'), str(source)]
    started = time.monotonic()
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', cl_flags, output)
    (output / 'compile.log').write_text(log, encoding='utf-8')
    return code, round(time.monotonic() - started, 3), cl_flags


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--addr', required=True)
    ap.add_argument('--include', required=True)
    ap.add_argument('--class', dest='class_', required=True)
    ap.add_argument('--prop-type', required=True)
    ap.add_argument('--unknown', type=int, required=True)
    ap.add_argument('--flag', action='append', default=[])
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    addr = args.addr.lower().replace('0x', '').zfill(8)
    args.output = args.output.resolve()
    args.output.mkdir(parents=True, exist_ok=True)
    source = args.output / 'probe.cpp'
    if args.class_.startswith('RBX::') and '::' not in args.prop_type:
        body = 'namespace RBX {\ntemplate class Reflection::BoundProp<%s, %d>::BoundPropGetSet<%s>;\n}\n' % (
            args.prop_type, args.unknown, args.class_[len('RBX::'):])
    else:
        body = 'template class RBX::Reflection::BoundProp<%s, %d>::BoundPropGetSet<%s>;\n' % (
            args.prop_type, args.unknown, args.class_)
    source.write_text('// generated work-only BoundProp probe\n#include "%s"\n#include "reflection/reflection.h"\n\n%s' %
                      (args.include, body), encoding='utf-8')
    code, seconds, flags = compile_probe(source.resolve(), args.output, args.flag)
    result = {'addr': addr, 'include': args.include, 'class': args.class_,
              'prop_type': args.prop_type, 'unknown': args.unknown, 'flags': flags,
              'source': str(source), 'compiler_exit': code, 'compile_seconds': seconds,
              'scope': 'work-only real-header template probe; no source promotion/link/runtime proof'}
    if code == 0:
        raw = (args.output / 'candidate.obj').read_bytes()
        target = Target('2008-06')
        hits = []
        for symbol, body, relocs in match.coff_functions(raw):
            target_bytes = target.same(addr, body, relocs)
            if target_bytes is None:
                continue
            _, bad = match.data_check('2008-06', addr, target_bytes, match.coff_data_refs(raw, symbol))
            hits.append({'symbol': symbol, 'size': len(body), 'relocs': relocs, 'data_errors': bad})
        result['hits'] = hits
        result['status'] = 'exact' if len(hits) == 1 and not hits[0]['data_errors'] else 'no-unique-exact-hit'
    else:
        result['status'] = 'compile-failed'
    (args.output / 'result.json').write_text(json.dumps(result, indent=1) + '\n', encoding='utf-8')
    print('status', result['status'], 'compile-seconds', seconds, 'output', args.output / 'result.json')
    raise SystemExit(0 if result['status'] == 'exact' else 1)


if __name__ == '__main__':
    main()
