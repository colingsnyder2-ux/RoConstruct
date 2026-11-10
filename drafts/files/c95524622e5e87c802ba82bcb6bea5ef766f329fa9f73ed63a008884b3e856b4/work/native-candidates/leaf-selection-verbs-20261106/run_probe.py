"""Run the indirect-call ABI probe over the leaf selection verb batch."""
import json
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = next((p for p in HERE.parents if (p / 'roconstruct-package.json').is_file()), HERE.parents[4])
PROBE = ROOT / 'work/native-candidates/standard-verbs-iat-abi-20261106/probe_indirect_call_abi.py'
RUN = ROOT / 'work/2008-06/native-check-runs/20261106-125501-fd69a291'
TARGETS = [
    ('unit-000', 'rebuild/2008-06/native-classes/SelectionVerbConstructors.cpp', [
        ('005c5300', '??0TranslucentVerb@RBX@@QAE@PAVDataModel@1@@Z'),
        ('005c5380', '??0CanCollideVerb@RBX@@QAE@PAVDataModel@1@@Z'),
        ('005c6010', '??0AnchorVerb@RBX@@QAE@PAVDataModel@1@@Z'),
        ('0057e870', '??0UngroupSelectionVerb@RBX@@QAE@PAVDataModel@1@@Z'),
        ('0057e810', '??0WeldSelectionVerb@RBX@@QAE@PAVDataModel@1@@Z'),
        ('0057e840', '??0SnapSelectionVerb@RBX@@QAE@PAVDataModel@1@@Z'),
        ('0057e8a0', '??0DuplicateSelectionVerb@RBX@@QAE@PAVDataModel@1@@Z'),
        ('0057e950', '??0AttachCameraCommand@RBX@@QAE@PAVDataModel@1@@Z'),
        ('0057e980', '??0TrackCameraCommand@RBX@@QAE@PAVDataModel@1@@Z'),
        ('0057e9b0', '??0FollowCameraCommand@RBX@@QAE@PAVDataModel@1@@Z'),
        ('0057e9e0', '??0WatchCameraCommand@RBX@@QAE@PAVDataModel@1@@Z'),
        ('0057e7e0', '??0GroupSelectionVerb@RBX@@QAE@PAVDataModel@1@@Z'),
    ]),
    ('unit-001', 'rebuild/2008-06/native-classes/AxisVerbConstructors.cpp', [
        ('0057f650', '??0RotateSelectionVerb@RBX@@QAE@PAVDataModel@1@@Z'),
        ('0057f680', '??0TiltSelectionVerb@RBX@@QAE@PAVDataModel@1@@Z'),
        ('0057f6b0', '??0PrimaryControllerCommand@RBX@@QAE@PAVDataModel@1@@Z'),
        ('0057f6e0', '??0SecondaryControllerCommand@RBX@@QAE@PAVDataModel@1@@Z'),
    ]),
]


def main():
    merged = {'bodies': [], 'demangle': {'names': {}}, 'failures': [], 'totals': {}}
    for unit, source, pairs in TARGETS:
        args = []
        for addr, symbol in pairs:
            args.append(addr + ':' + symbol)
        result = subprocess.run([sys.executable, str(PROBE), '--object', str(RUN / unit / 'candidate.obj'),
                                 '--receipt', str(HERE / ('bindings-' + unit + '.json'))] + args,
                                cwd=str(ROOT), capture_output=True, text=True)
        if result.returncode not in (0, 1):
            print(result.stdout, result.stderr, file=sys.stderr)
            raise SystemExit('probe failed for ' + unit)
        data = json.loads((HERE / ('bindings-' + unit + '.json')).read_text(encoding='utf-8'))
        for body in data['bodies']:
            body['unit'] = unit
            body['source'] = source
            merged['bodies'].append(body)
        merged['failures'].extend(data['failures'])
        merged['demangle']['names'].update(data['demangle'].get('names', {}))
        merged['demangle']['__tool__'] = data['demangle'].get('__tool__')
        print(json.dumps({'unit': unit, 'totals': data['totals'], 'verified': data['indirect_call_bindings_verified']}))
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
