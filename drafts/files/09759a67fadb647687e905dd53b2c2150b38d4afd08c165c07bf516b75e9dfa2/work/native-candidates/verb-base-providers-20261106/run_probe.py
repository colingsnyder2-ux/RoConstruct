"""Run the StandardVerbs indirect-call ABI probe over every unit of the verb provider batch."""
import json
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = next((p for p in HERE.parents if (p / 'roconstruct-package.json').is_file()), HERE.parents[4])
PROBE = ROOT / 'work/native-candidates/standard-verbs-iat-abi-20261106/probe_indirect_call_abi.py'
RUN = ROOT / 'work/2008-06/native-check-runs/20261106-122432-79a80ce8'
TARGETS = [
    ('unit-000', '0057e330', '??0RunStateVerb@RBX@@IAE@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAVDataModel@1@@Z'),
    ('unit-001', '005833e0', '??0Verb@RBX@@IAE@PAVVerbContainer@1@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z'),
    ('unit-002', '005832c0', '??1Verb@RBX@@UAE@XZ'),
    ('unit-003', '0057e8d0', '??0DeleteBase@RBX@@IAE@PAVDataModel@1@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z'),
]


def main():
    merged = {'bodies': [], 'demangle': {'__available__': True}, 'failures': [], 'totals': {}}
    for unit, addr, symbol in TARGETS:
        out = HERE / ('bindings-' + unit + '.json')
        result = subprocess.run([sys.executable, str(PROBE), '--object', str(RUN / unit / 'candidate.obj'),
                                 '--receipt', str(out), addr + ':' + symbol],
                                cwd=str(ROOT), capture_output=True, text=True)
        if result.returncode not in (0, 1):
            print(result.stdout, result.stderr, file=sys.stderr)
            raise SystemExit('probe failed for ' + unit)
        data = json.loads(out.read_text(encoding='utf-8'))
        for body in data['bodies']:
            body['unit'] = unit
            merged['bodies'].append(body)
        merged['failures'].extend(data['failures'])
        merged['demangle']['names'] = {**merged['demangle'].get('names', {}), **data['demangle'].get('names', {})}
        merged['demangle']['__tool__'] = data['demangle'].get('__tool__')
        print(json.dumps({'unit': unit, 'addr': addr, 'totals': data['totals'],
                          'verified': data['indirect_call_bindings_verified']}))
    totals = {
        'bodies': len(merged['bodies']),
        'indirect_sites': sum(len(b['indirect_sites']) for b in merged['bodies']),
        'verified': sum(1 for b in merged['bodies'] for s in b['indirect_sites'] if s['verified_indirect_call_binding']),
        'byte_identical_bodies': sum(1 for b in merged['bodies'] if b['byte_identical']),
        'direct_sites': sum(b['direct_sites'] for b in merged['bodies']),
        'unclassified_sites': sum(b['unclassified_sites'] for b in merged['bodies']),
        'virtual_dispatch_sites': sum(b.get('virtual_dispatch_sites', 0) for b in merged['bodies']),
    }
    merged['totals'] = totals
    merged['indirect_call_bindings_verified'] = (
        totals['verified'] == totals['indirect_sites'] and totals['indirect_sites'] > 0
        and not totals['unclassified_sites'] and totals['byte_identical_bodies'] == totals['bodies'])
    merged['schema'] = 1
    merged['client'] = '2008-06'
    merged['run'] = str(RUN.relative_to(ROOT))
    out = HERE / 'bindings.json'
    out.write_text(json.dumps(merged, indent=1, sort_keys=True), encoding='utf-8')
    print(json.dumps({'receipt': str(out), 'totals': totals,
                      'verified': merged['indirect_call_bindings_verified'],
                      'failures': merged['failures'][:10]}, indent=1))
    return 0 if merged['indirect_call_bindings_verified'] else 1


if __name__ == '__main__':
    raise SystemExit(main())
