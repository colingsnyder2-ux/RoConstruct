"""Measure already-emitted ViewNew template bodies against the 2008 target."""
import json
import sys
import argparse
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))


def main():
    from roc import match, rebuild
    ap = argparse.ArgumentParser()
    ap.add_argument('--compile-all', action='store_true')
    args = ap.parse_args()
    if args.compile_all:
        sys.path.insert(0, str(ROOT / 'rebuild/2008-06/tests'))
        import native_bind
        out = ROOT / 'rebuild/2008-06/out/native-layouts'
        for source in (ROOT / 'rebuild/2008-06/native-classes').glob('ViewNew*.cpp'):
            if 'QuadVolumeFace.h' not in source.read_text(errors='replace'):
                continue
            obj = out / ('NativeViewNew_' + source.stem + '.obj')
            code, log = rebuild.run(rebuild.toolchain(21022), 'cl', native_bind.flags() + ['/fp:fast', '/Fo' + str(obj), str(source)], out)
            if code:
                print('compile-failed', source.name, log[-400:].replace('\n', ' '))
    queue = json.loads((ROOT / 'work/native-client/ogre-conversion-queue-v10.json').read_text())
    wanted = {}
    for cls in queue['classes']:
        if cls['owner'] != 'RBX::ViewNew::LevelBuilder':
            continue
        for row in cls['methods']:
            if row['state'] == 'convert' and '$' in row['symbol']:
                wanted[row['symbol']] = row['addr']
    emitted = defaultdict(list)
    for obj in (ROOT / 'rebuild/2008-06/out/native-layouts').glob('NativeViewNew_*.obj'):
        for symbol, body, refs in match.coff_functions(obj.read_bytes()):
            if symbol in wanted:
                emitted[symbol].append((obj.name, body, refs))
    rows = []
    for symbol, address in wanted.items():
        target, target_refs, _ = match.target('2008-06', address)
        candidates = emitted[symbol]
        exact = [name for name, body, refs in candidates if match.exact_match(target, target_refs, body, refs)]
        rows.append({'addr': address, 'symbol': symbol, 'emitted_in': [name for name, _, _ in candidates],
                     'exact_in': exact, 'status': 'inactive_exact' if exact else
                     ('emitted_inexact' if candidates else 'not_emitted'), 'target_size': len(target)})
    out = ROOT / 'work/native-client/viewnew-template-existing.json'
    out.write_text(json.dumps({'scope': 'existing native ViewNew template bodies; no source edits', 'rows': rows}, indent=1) + '\n')
    print(json.dumps({'targets': len(rows), 'exact': sum(r['status'] == 'inactive_exact' for r in rows),
                      'exact_bytes': sum(r['target_size'] for r in rows if r['status'] == 'inactive_exact'),
                      'inexact': sum(r['status'] == 'emitted_inexact' for r in rows),
                      'missing': sum(r['status'] == 'not_emitted' for r in rows)}, sort_keys=True))


if __name__ == '__main__':
    main()
