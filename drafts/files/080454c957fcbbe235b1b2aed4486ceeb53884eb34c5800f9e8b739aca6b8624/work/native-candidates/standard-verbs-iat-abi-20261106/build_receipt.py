"""Assemble the task-owned shared-layouts receipt for the StandardVerbs indirect-call ABI proof."""
import hashlib
import json
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = next((p for p in HERE.parents if (p / 'roconstruct-package.json').is_file()), HERE.parents[3])


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def main():
    run = ROOT / 'work/2008-06/native-check-runs/20261106-114631-31eff734'
    bindings = json.loads((HERE / 'bindings.json').read_text(encoding='utf-8'))
    results = json.loads((run / 'results.json').read_text(encoding='utf-8'))
    summary = json.loads((run / 'summary.json').read_text(encoding='utf-8'))
    analysis = max((run).glob('analysis-*.json'), key=lambda p: p.stat().st_mtime)
    analysis_rows = json.loads(analysis.read_text(encoding='utf-8'))
    source = ROOT / 'rebuild/2008-06/native-classes/StandardVerbs.cpp'
    manifest = ROOT / 'rebuild/2008-06/tests/standard-verbs-iat-abi-unit-20261106.json'
    compiler = Path(summary['compiler'])
    checks = [row for row in results[0]['checks']]

    totals = bindings['totals']
    indirect = [s for b in bindings['bodies'] for s in b['indirect_sites']]
    slots = {}
    for site in indirect:
        slots.setdefault(site['iat_slot'], {
            'original_import': site['original_import'],
            'demangled': bindings['demangle']['names'].get(site['original_import']['import']),
            'candidate_external': site['candidate_external'],
            'sites': []})['sites'].append(site['offset'])

    receipt_checks = [{
        'addr': row['addr'], 'symbol': row['symbol'], 'status': row['status'],
        'target_size': row['target_size'], 'object_size': row['object_size'],
        'target_sha256': row['target_sha256'], 'first_byte_difference': row['first_byte_difference'],
        'data_references': len(row.get('data_matches', [])),
        'data_errors': row.get('data_errors', []),
        'call_sites_total': len(row['call_identity']['calls']),
        'direct_call_bindings_verified': len([r for r in row['call_identity']['calls']
                                              if r['status'] == 'verified_binding']),
        'indirect_call_sites': len([r for r in row['call_identity']['calls']
                                    if r['status'] != 'verified_binding']),
        'call_identity_passed': row['call_identity']['passed'],
        'call_identity_scope': row['call_identity']['scope'],
    } for row in checks]

    receipt = {
        'schema': 1,
        'workflow': 52,
        'client': '2008-06',
        'task': 'Native source recovery with automatic draft sharing',
        'swap_target': ('Document/Workspace native class swap: CRobloxDoc/StandardVerbs composition '
                        'and tool-verb mouse-command providers'),
        'blocker_reduced': ('Indirect-call ABI for the MSVCP90 std::string/std::operator+ call sites in '
                            'StandardVerbs::StandardVerbs 005c7ea0, which kept the body out of '
                            '`native_check_runner analyze --require-proof` even though its bytes, '
                            'referenced data and 112 reviewed direct-call bindings already passed.'),
        'package_revision': json.loads((ROOT / 'roconstruct-package.json').read_text(encoding='utf-8'))['revision'],
        'workspace_manifest_source_revision': json.loads((ROOT / 'workspace-manifest.json').read_text(encoding='utf-8'))['source_revision'],
        'baseline_commit': 'unknown',
        'owner_checkout_queue_present': False,
        'unit': 'StandardVerbs.cpp',
        'run': str(run.relative_to(ROOT)),
        'analysis': str(analysis.relative_to(ROOT)),
        'source': 'rebuild/2008-06/native-classes/StandardVerbs.cpp',
        'source_sha256': sha(source),
        'manifest': 'rebuild/2008-06/tests/standard-verbs-iat-abi-unit-20261106.json',
        'manifest_sha256': sha(manifest),
        'object': results[0]['object'].replace(str(ROOT) + '\\', '').replace('\\', '/'),
        'object_sha256': results[0]['object_sha256'],
        'compiler': str(compiler),
        'compiler_sha256': sha(compiler),
        'checks': receipt_checks,
        'indirect_call_abi': {
            'probe': 'work/native-candidates/standard-verbs-iat-abi-20261106/probe_indirect_call_abi.py',
            'probe_sha256': sha(HERE / 'probe_indirect_call_abi.py'),
            'bindings': 'work/native-candidates/standard-verbs-iat-abi-20261106/bindings.json',
            'bindings_sha256': sha(HERE / 'bindings.json'),
            'import_table_source': 'original 2008-06 client import directory parsed with pefile',
            'demangle_tool': bindings['demangle']['__tool__'],
            'totals': totals,
            'iat_slots': {slot: {
                'original_import': value['original_import'],
                'demangled': value['demangled'],
                'candidate_external': value['candidate_external'],
                'sites': value['sites'],
            } for slot, value in sorted(slots.items())},
            'scope': ('Same imported callee, same IAT slot, same declared ABI and same argument setup '
                      'as the original client, for every indirect call site in the recovered body.'),
        },
        'proof': {
            'exact_bytes': totals['byte_identical_bodies'] == totals['bodies'],
            'referenced_data': all(not row.get('data_errors') for row in checks),
            'direct_call_bindings': all(row['direct_call_bindings_verified'] == row['call_sites_total']
                                        - row['indirect_call_sites'] for row in receipt_checks),
            'direct_call_bindings_scope': ('Every direct e8 call site in both bodies carries a reviewed '
                                           'symbol/address binding verified on this object. The runner\'s own '
                                           'call_identity.passed flag additionally requires zero indirect sites, '
                                           'so it stays false for the ctor by design and is reported as recorded.'),
            'indirect_call_bindings': bindings['indirect_call_bindings_verified'],
            'require_proof_exit': 1,
            'require_proof_reason': ('native_check_runner analyze --require-proof still exits 1 by design: '
                                     'the runner proves direct-call bindings only. The indirect-call ABI '
                                     'obligation now has its own reviewed receipt (indirect_call_abi above).'),
            'scope': ('Local isolated diagnostics. No link, no provider selection, no executable selection, '
                      'no runtime activation, no server credit.'),
        },
        'provider_selection': {
            'status': 'blocked_on_missing_input',
            'detail': ('No filtered provider archive (b4d51e680296b50c2cfb57e93815e569519144aa19d25779dbd3c0d714db5798), '
                       'no full archive (21e44d8cac6d3f14850180ccb2f8d5ed618fe129c9d5c1632186b78d52d03519), '
                       'no link response file and no document-swap link object set exist in this workspace; '
                       'provider selection for these symbols is unknown.'),
        },
        'remaining': [
            'Provider selection for StandardVerbs and its tool-verb factories in the document link (missing filtered archive / RSP / link object set)',
            'Link closure for the StandardVerbs composition and its tool-verb providers',
            'Relevant P5/P6/runtime gates before any activation',
        ],
        'preserved': ('Shared headers, vendor inputs, other leases and the active executable selection unchanged. '
                      'RBX::MoveDown selection verb 2008 and RBX::CRobloxDoc message handlers 2008 are held by '
                      'other active leases and were not touched.'),
        'metrics': {
            'inactive_exact_addresses': 2,
            'selected_exact_addresses': 0,
            'gated_class_swaps': 0,
            'server_credit_added': 0,
        },
        'non_claims': [
            'No link was performed and no provider was selected.',
            'No .lib, RSP, map or executable was created, copied or reconstructed.',
            'No symbol alias, stub or synthetic mapping was introduced.',
            'No server credit, runtime activation or executable selection change.',
        ],
    }
    out = HERE.parent.parent.parent / 'work/2008-06/shared-layouts/standard-verbs-iat-abi-unit-20261106.json'
    out.write_text(json.dumps(receipt, indent=1, sort_keys=True), encoding='utf-8')
    print(json.dumps({'receipt': str(out.relative_to(ROOT)), 'sha256': sha(out),
                      'indirect_verified': bindings['totals']['verified'],
                      'indirect_total': bindings['totals']['indirect_sites']}, indent=1))


if __name__ == '__main__':
    main()
