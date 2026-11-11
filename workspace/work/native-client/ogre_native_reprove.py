"""Reprove compiled native Ogre units against closure-bound target identities."""
import argparse
import json
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import match


def symbols(object_path):
    return {name for name, _, _ in match.coff_functions(Path(object_path).read_bytes())}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--config', type=Path, required=True)
    ap.add_argument('--manifest', type=Path, required=True)
    ap.add_argument('--closure', type=Path, required=True)
    ap.add_argument('--out', type=Path, required=True)
    args = ap.parse_args()
    base = json.loads(args.config.read_text())
    manifest = json.loads(args.manifest.read_text())
    closure = json.loads(args.closure.read_text())
    bound = {row['symbol']: row for row in closure['bindings'] if row.get('body_exact') and row.get('function_start')}
    wanted = set()
    for family in manifest['families']:
        for job in family.get('jobs', []):
            if job.get('object') and Path(job['object']).is_file():
                wanted.update(bound[name]['addr'] for name in symbols(job['object']) if name in bound)
    out = args.out.resolve()
    out.mkdir(parents=True, exist_ok=True)
    evidence = out / 'identity.json'
    command = [sys.executable, str(ROOT / 'work/native-client/native_identity_evidence.py'),
               '--closure', str(args.closure), '--output', str(evidence)]
    for address in sorted(wanted):
        command += ['--addr', address]
    subprocess.run(command, cwd=ROOT, check=True)
    config = dict(base)
    config['targets'] = sorted(wanted)
    for family in config['families']:
        family['evidence'] = [str(evidence.relative_to(ROOT)).replace('\\', '/')]
    config_path = out / 'config.json'
    config_path.write_text(json.dumps(config, indent=1) + '\n')
    subprocess.run([str(ROOT / 'roc.cmd'), 'native-bulk', str(config_path), '--out', str(out / 'bulk')], cwd=ROOT, check=True)
    result = json.loads((out / 'bulk' / 'manifest.json').read_text())
    families = {}
    for family in result['families']:
        exact = [row for row in family['symbols'] if row.get('status') == 'inactive_exact']
        families[family['name']] = {
            'emitted_symbols': len(family['symbols']),
            'exact_symbol_rows': len(exact),
            'exact_distinct_addresses': len({row['addr'] for row in exact if row.get('addr')}),
        }
    summary = {
        'targets': len(wanted),
        'families': families,
        'exact_distinct_addresses': len({row['addr'] for family in result['families']
                                         for row in family['symbols']
                                         if row.get('status') == 'inactive_exact' and row.get('addr')}),
    }
    (out / 'summary.json').write_text(json.dumps(summary, indent=1) + '\n')
    print(json.dumps(summary))


if __name__ == '__main__':
    main()
