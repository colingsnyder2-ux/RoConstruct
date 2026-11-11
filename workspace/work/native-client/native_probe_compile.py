"""Compile one inactive real-header transplant probe with VS2008 and time it."""
import argparse
import json
import sys
import time
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import libs, rebuild


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--source', type=Path, required=True)
    ap.add_argument('--output', type=Path, required=True)
    ap.add_argument('--include', action='append', default=[])
    ap.add_argument('--flag', action='append', default=[])
    args = ap.parse_args()
    args.source = args.source.resolve()
    args.output = args.output.resolve()
    recipe = libs.RECIPES['rbxgs']
    headers = ROOT / 'rebuild/2008-06/native-headers'
    args.output.mkdir(parents=True, exist_ok=True)
    flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD',
             '/D_AFXDLL', '/DNDEBUG', '/D_MBCS', '/DBOOST_ALL_NO_LIB']
    flags += ['/D' + value for value in recipe['defines'].split()]
    flags += ['/I' + str(headers), '/I' + str(ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/include')]
    flags += ['/I' + str((libs.LIBS / value).resolve()) for value in recipe['include'] if value != 'WINSDK']
    flags += ['/I' + value for value in args.include]
    flags += args.flag
    flags += ['/D_XTP_STATICLINK', '/D_XTPLIB_NOAUTOLINK',
              '/I' + str(ROOT / 'tools/libs/xtp-11.2.2/Source'),
              '/Fo' + str(args.output / 'candidate.obj'), str(args.source)]
    started = time.monotonic()
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, args.output)
    elapsed = round(time.monotonic() - started, 3)
    (args.output / 'compile.log').write_text(log, encoding='utf-8')
    receipt = {'source': str(args.source), 'compiler_exit': code, 'seconds': elapsed,
               'object': str(args.output / 'candidate.obj'), 'flags': flags,
               'scope': 'inactive real-header compile probe; not a byte/link/runtime proof'}
    (args.output / 'receipt.json').write_text(json.dumps(receipt, indent=1) + '\n')
    print('compile-exit', code, 'seconds', elapsed, 'log', args.output / 'compile.log')
    raise SystemExit(code)


if __name__ == '__main__':
    main()
