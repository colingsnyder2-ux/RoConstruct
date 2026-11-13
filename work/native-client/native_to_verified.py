"""Turn a module's compiled native layer objects into verified-style swaps: only byte-exact functions get linked.

  python work/native-client/native_to_verified.py MODULE_OUT_NAME [--layers PREFIX]
  e.g. python work/native-client/native_to_verified.py OgreNativeRbxTrial

A native object normally links whole, so one draft function (an out-of-line call where the original inlined) pulls in
symbols the exe never had. This copies each object from out/<Module>/layer-<PREFIX>*/ into out/<Module>/verified/ as
nat_<name>.obj and records in swaps.json only the symbols whose body is identical to an original function (same test
as native_link_select: native_template_probe.exact). The module's build loop (roc/rebuild.py verified_layer) then
strips every other definition. Re-run after the native layers are rebuilt; earlier nat_* entries are replaced.
"""
import argparse
import json
import shutil
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(HERE))
from roc.native_bulk import Targets  # noqa: E402
import native_template_probe as probe  # noqa: E402


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('module')
    ap.add_argument('--layers', default='layer-native')
    args = ap.parse_args()
    out = ROOT / 'rebuild/2008-06/out' / args.module
    verified = out / 'verified'
    swaps_path = verified / 'swaps.json'
    data = json.loads(swaps_path.read_text())
    for item in [s for s in data['swaps'] if s['obj'].startswith('nat_')]:
        (verified / item['obj']).unlink(missing_ok=True)
    data['swaps'] = [s for s in data['swaps'] if not s['obj'].startswith('nat_')]
    targets = Targets('2008-06')
    kept = total = 0
    for layer in sorted(out.glob(args.layers + '*')):
        for obj in sorted(layer.glob('*.obj')):
            exact = probe.exact(obj.read_bytes(), targets)
            keep = {symbol: addresses[0] for symbol, addresses in exact.items() if addresses}
            if not keep:
                continue
            name = 'nat_%s_%s' % (layer.name.removeprefix('layer-'), obj.name)
            shutil.copy2(obj, verified / name)
            data['swaps'].append({'obj': name, 'recipe': 'native', 'file': obj.stem + '.cpp', 'keep': keep})
            kept += len(keep)
            total += 1
    swaps_path.write_text(json.dumps(data, indent=1))
    print(json.dumps({'native_objects': total, 'exact_symbols': kept, 'swaps': len(data['swaps'])}))


if __name__ == '__main__':
    main()
