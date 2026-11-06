"""Run the indirect-call ABI probe over the selection verb destructor unit."""
import json
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = next((p for p in HERE.parents if (p / 'roconstruct-package.json').is_file()), HERE.parents[4])
PROBE = ROOT / 'work/native-candidates/standard-verbs-iat-abi-20261106/probe_indirect_call_abi.py'
RUN = ROOT / 'work/2008-06/native-check-runs/20261106-123742-b9c68558'
TARGETS = [
    ('0057dfd0', '??1RunStateVerb@RBX@@UAE@XZ'),
    ('0057e050', '??1EditSelectionVerb@RBX@@UAE@XZ'),
]


def main():
    merged = {'bodies': [], 'demangle': {'names': {}}, 'failures': [], 'totals': {}}
    for addr, symbol in TARGETS:
        result = subprocess.run([sys.executable, str(PROBE), '--object', str(RUN / 'unit-000/candidate.obj'),
                                 '--receipt', str(HERE / 'bindings.json'), addr + ':' + symbol],
                                cwd=str(ROOT), capture_output=True, text=True)
        if result.returncode not in (0, 1):
            print(result.stdout, result.stderr, file=sys.stderr)
            raise SystemExit('probe failed for ' + addr)
        data = json.loads((HERE / 'bindings.json').read_text(encoding='utf-8'))
        merged['bodies'].extend(data['bodies'])
        merged['failures'].extend(data['failures'])
        merged['demangle']['names'].update(data['demangle'].get('names', {}))
        merged['demangle']['__tool__'] = data['demangle'].get('__tool__')
        print(json.dumps({'addr': addr, 'totals': data['totals'], 'verified': data['indirect_call_bindings_verified']}))
    totals = {
        'bodies': len(merged['bodies']),
        'indirect_sites': sum(len(b['indirect_sites']) for b in merged['bodies']),
        'verified': sum(1 for b in merged['bodies'] for s in b['indirect_sites'] if s['verified_indirect_call_binding']),
        'byte_identical_bodies': sum(1 for b in merged['bodies'] if b['byte_identical']),
        'direct_sites': sum(b['direct_sites'] for b in merged['bodies']),
        'unclassified_sites': sum(b['unclassified_sites'] for b in merged['bodies']),
        'virtual_dispatch_sites': sum(b['virtual_dispatch_sites'] for b in merged['bodies']),
    }
    merged['totals'] = totals
    merged['indirect_call_bindings_verified'] = (
        totals['verified'] == totals['indirect_sites'] and not totals['unclassified_sites']
        and totals['byte_identical_bodies'] == totals['bodies'])
    merged['schema'] = 1
    merged['client'] = '2008-06'
    merged['run'] = str(RUN.relative_to(ROOT))
    (HERE / 'bindings.json').write_text(json.dumps(merged, indent=1, sort_keys=True), encoding='utf-8')
    print(json.dumps({'totals': totals, 'verified': merged['indirect_call_bindings_verified'],
                      'failures': merged['failures'][:10]}, indent=1))
    return 0 if merged['indirect_call_bindings_verified'] else 1


if __name__ == '__main__':
    raise SystemExit(main())
