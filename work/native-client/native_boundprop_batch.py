"""Run a bounded catalog of real-header BoundProp probes deterministically."""
import argparse
import json
import subprocess
import sys
from pathlib import Path


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--catalog', type=Path, required=True)
    ap.add_argument('--flag', action='append', default=[])
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    catalog = json.loads(args.catalog.read_text())
    args.output.mkdir(parents=True, exist_ok=True)
    rows = []
    probe = Path(__file__).with_name('native_boundprop_probe.py')
    for index, candidate in enumerate(catalog.get('candidates', [])):
        out = args.output / ('candidate-%02d' % index)
        command = [sys.executable, str(probe), '--addr', catalog['addr'],
                   '--include', candidate['include'], '--class', candidate['class'],
                   '--prop-type', candidate['prop_type'], '--unknown', str(candidate['unknown']),
                   '--output', str(out)]
        for flag in args.flag:
            command += ['--flag', flag]
        completed = subprocess.run(command, text=True, capture_output=True)
        result_path = out / 'result.json'
        result = json.loads(result_path.read_text()) if result_path.exists() else {
            'status': 'runner-failed', 'stdout': completed.stdout, 'stderr': completed.stderr}
        rows.append({'candidate': candidate, 'exit': completed.returncode, 'result': result})
    exact = [row for row in rows if row['result'].get('status') == 'exact']
    report = {'addr': catalog.get('addr'), 'catalog': str(args.catalog), 'rows': rows,
              'exact': exact, 'status': 'unique-exact' if len(exact) == 1 else 'not-unique',
              'scope': 'work-only bounded compiler search; no native source promotion/link/runtime proof'}
    (args.output / 'result.json').write_text(json.dumps(report, indent=1) + '\n', encoding='utf-8')
    print('candidates', len(rows), 'exact', len(exact), 'status', report['status'])
    raise SystemExit(0 if report['status'] == 'unique-exact' else 1)


if __name__ == '__main__':
    main()
