"""Run the indirect-call ABI probe over every unit of the tool-verb provider batch."""
import os
import json
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = next((p for p in HERE.parents if (p / 'roconstruct-package.json').is_file()), HERE.parents[4])
PROBE = ROOT / 'work/native-candidates/standard-verbs-iat-abi-20261106/probe_indirect_call_abi.py'
RUN = ROOT / os.environ.get('ROC_PROBE_RUN', 'work/2008-06/native-check-runs/20261106-130924-bdcb0da1')


def main():
    results = json.loads((RUN / 'results.json').read_text(encoding='utf-8'))
    merged = {'bodies': [], 'demangle': {'names': {}}, 'failures': [], 'totals': {}}
    for index, result in enumerate(results):
        args = [c['addr'] + ':' + c['symbol'] for c in result['checks']]
        tmp = HERE / ('bindings-unit-%03d.json' % index)
        proc = subprocess.run([sys.executable, str(PROBE), '--object', result['object'],
                               '--receipt', str(tmp)] + args, cwd=str(ROOT), capture_output=True, text=True)
        if proc.returncode not in (0, 1):
            print(proc.stdout, proc.stderr, file=sys.stderr)
            raise SystemExit('probe failed for ' + result['source'])
        data = json.loads(tmp.read_text(encoding='utf-8'))
        for body in data['bodies']:
            body['source'] = result['source'].replace(str(ROOT) + '\\', '').replace('\\', '/')
            merged['bodies'].append(body)
        merged['failures'].extend(data['failures'])
        merged['demangle']['names'].update(data['demangle'].get('names', {}))
        merged['demangle']['__tool__'] = data['demangle'].get('__tool__')
        print(json.dumps({'unit': index, 'source': Path(result['source']).name,
                          'totals': data['totals'], 'verified': data['indirect_call_bindings_verified']}))
    totals = {
        'bodies': len(merged['bodies']),
        'indirect_sites': sum(len(b['indirect_sites']) for b in merged['bodies']),
        'verified': sum(1 for b in merged['bodies'] for s in b['indirect_sites']
                        if s['verified_indirect_call_binding']),
        'byte_identical_bodies': sum(1 for b in merged['bodies'] if b['byte_identical']),
        'direct_sites': sum(b['direct_sites'] for b in merged['bodies']),
        'unclassified_sites': sum(b['unclassified_sites'] for b in merged['bodies']),
        'virtual_dispatch_sites': sum(b.get('virtual_dispatch_sites', 0) for b in merged['bodies']),
    }
    merged['totals'] = totals
    merged['indirect_call_bindings_verified'] = (
        totals['verified'] == totals['indirect_sites'] and not totals['unclassified_sites']
        and totals['byte_identical_bodies'] == totals['bodies'])
    merged['schema'] = 1
    merged['client'] = '2008-06'
    merged['run'] = str(RUN.relative_to(ROOT))
    (HERE / 'bindings.json').write_text(json.dumps(merged, indent=1, sort_keys=True), encoding='utf-8')
    for tmp in HERE.glob('bindings-unit-*.json'):
        tmp.unlink()
    print(json.dumps({'totals': totals, 'verified': merged['indirect_call_bindings_verified'],
                      'failures': merged['failures'][:10]}, indent=1))
    return 0 if merged['indirect_call_bindings_verified'] else 1


if __name__ == '__main__':
    raise SystemExit(main())
