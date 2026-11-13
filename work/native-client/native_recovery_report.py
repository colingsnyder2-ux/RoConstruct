"""Merge native-recovery gate receipts without promoting inactive code."""
import argparse
import json
import re
from pathlib import Path


def load(path):
    return json.loads(Path(path).read_text())


def checks(rows):
    if isinstance(rows, dict):
        rows = rows.get('jobs', [])
    return [row for result in rows for row in result.get('checks', [])
            if row.get('status', 'exact') == 'exact' and not row.get('data_errors')]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--owners', type=Path, required=True)
    ap.add_argument('--rocket', type=Path, required=True)
    ap.add_argument('--wedge', type=Path, required=True)
    ap.add_argument('--material', type=Path, required=True)
    ap.add_argument('--transplants', type=Path, required=True)
    ap.add_argument('--probe-receipt', action='append', type=Path, default=[])
    ap.add_argument('--layout-result', action='append', type=Path, default=[])
    ap.add_argument('--existing-run', action='append', type=Path, default=[])
    ap.add_argument('--template-result', action='append', type=Path, default=[])
    ap.add_argument('--template-batch', action='append', type=Path, default=[])
    ap.add_argument('--new-native-manifest', action='append', type=Path, default=[])
    ap.add_argument('--new-native-addr', action='append', default=[])
    ap.add_argument('--new-header', action='append', type=Path, default=[])
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    owner = load(args.owners)
    rocket = checks(load(args.rocket))
    wedge = checks(load(args.wedge))
    material = load(args.material)
    transplants = load(args.transplants)
    probes = []
    for receipt_path in args.probe_receipt:
        receipt = load(receipt_path)
        log = receipt_path.parent / 'compile.log'
        errors = re.findall(r'error C\d+:\s*(.*)', log.read_text(errors='replace'))[:8] if log.exists() else []
        probes.append({'source': receipt['source'], 'compiler_exit': receipt['compiler_exit'],
                       'seconds': receipt['seconds'], 'errors': errors})
    layouts = [load(path) for path in args.layout_result]
    supplemental = []
    for path in args.existing_run:
        for result in load(path):
            for row in result.get('checks', []):
                if row.get('status') == 'exact' and not row.get('data_errors'):
                    supplemental.append({'addr': row['addr'], 'symbol': row['symbol'],
                                       'source': result['source']})
    supplemental_classes = {}
    for row in supplemental:
        name = Path(row['source']).stem
        supplemental_classes[name] = supplemental_classes.get(name, 0) + 1
    templates = [load(path) for path in args.template_result]
    template_batches = [load(path) for path in args.template_batch]
    requested_new = {f'{int(value, 16):08x}' for value in args.new_native_addr}
    generated = []
    for path in args.new_native_manifest:
        manifest = load(path)
        for family in manifest.get('families', []):
            sources = {Path(job['source']).resolve() for job in family.get('jobs', [])}
            for row in family.get('symbols', []):
                if (row.get('status') == 'inactive_exact' and row.get('addr') and row.get('symbol')
                        and row['addr'] in requested_new):
                    generated.append({'addr': row['addr'], 'symbol': row['symbol'],
                                      'sources': sorted(map(str, sources))})
    generated = {(row['addr'], row['symbol']): row for row in generated}
    exact = rocket + wedge
    classes = {'Rocket': len(rocket), 'WedgeBuilder': len(wedge),
               'RenderMaterialFamily': len(material['exact_function_rows'])}
    classes.update(supplemental_classes)
    out = {
        'scope': 'local deterministic native recovery diagnostics; no client selection/runtime gate',
        'owner_gate': owner['summary'],
        'existing_native_proof': {
            'classes': classes,
            'byte_and_data_proved_methods': len(exact) + len(material['exact_function_rows']) + len(supplemental),
            'call_and_vtable_proved_material_rows': len(material['exact_function_rows']),
            'material_vtables_verified': len(material['vtables']),
            'methods': ([{'addr': row['addr'], 'symbol': row['symbol']} for row in exact]
                        + supplemental),
        },
        'new_native_source': {
            'cpp_files': len({source for row in generated.values() for source in row['sources']}),
            'header_files': len({str(path.resolve()) for path in args.new_header}),
            'methods': len(generated),
            'byte_and_data_proved_methods': sorted(generated.values(), key=lambda row: row['addr']),
        },
        'compile_probes': probes,
        'header_layout_evidence': layouts,
        'automatic_template_probes': templates,
        'automatic_template_batches': template_batches,
        'integration': {'linked_methods': 0, 'runtime_gated_classes': 0,
                        'view_rbx_gfx_frames': 0},
        'blocked': {'layout_unproven_owner_routes': len(owner['blocked']),
                    'mined_method_transplant_gate': transplants['summary'],
                    'untranslated_mined_packets': 1,
                    'items': [
                        {'addr': '0062fc00', 'class': 'RBX::Rocket',
                         'reason': 'computeForce packet declares stand-in Body/Connector/Rocket layouts; not promoted'},
                        {'addr': '0062fc00', 'class': 'RBX::Rocket',
                         'reason': 'Body2008.h cannot coexist with BodyMovers.h donor Connector headers; requires a proven shared 2008 Connector/Body include profile'},
                    ]},
    }
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(out, indent=1) + '\n')
    print('existing-byte-data-proved', len(exact) + len(material['exact_function_rows']) + len(supplemental),
          'new-source', len(generated), 'linked', 0)


if __name__ == '__main__':
    main()
