"""Assemble the task-owned shared-layouts receipt for the EditSelectionVerb provider unit."""
import hashlib
import json
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = next((p for p in HERE.parents if (p / 'roconstruct-package.json').is_file()), HERE.parents[4])


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def main():
    run = ROOT / 'work/2008-06/native-check-runs/20261106-121512-f7611e2e'
    results = json.loads((run / 'results.json').read_text(encoding='utf-8'))
    summary = json.loads((run / 'summary.json').read_text(encoding='utf-8'))
    bindings = json.loads((HERE / 'bindings.json').read_text(encoding='utf-8'))
    source = ROOT / 'rebuild/2008-06/native-classes/EditSelectionVerbConstructor.cpp'
    manifest = ROOT / 'rebuild/2008-06/tests/editselectionverb-provider-unit-20261106.json'
    row = results[0]['checks'][0]
    body = bindings['bodies'][0]
    direct = [s for s in bindings['bodies'][0]['indirect_sites']]  # not direct; kept empty
    indirect_sites = body['indirect_sites']

    receipt = {
        'schema': 1,
        'workflow': 52,
        'client': '2008-06',
        'task': 'Native source recovery with automatic draft sharing',
        'swap_target': ('Document/Workspace native class swap: CRobloxDoc/StandardVerbs composition '
                        'and tool-verb mouse-command providers'),
        'blocker_reduced': ('EditSelectionVerb::EditSelectionVerb 0057e730, the base-class provider the '
                            'StandardVerbs ctor constructs at eight call sites, is now byte-exact from the '
                            'existing native source, and its two MSVCP90 std::string call sites carry the '
                            'same reviewed indirect-call ABI receipt as the StandardVerbs unit.'),
        'package_revision': json.loads((ROOT / 'roconstruct-package.json').read_text(encoding='utf-8'))['revision'],
        'workspace_manifest_source_revision': json.loads((ROOT / 'workspace-manifest.json').read_text(encoding='utf-8'))['source_revision'],
        'baseline_commit': 'unknown',
        'owner_checkout_queue_present': False,
        'unit': 'EditSelectionVerbConstructor.cpp',
        'run': str(run.relative_to(ROOT)),
        'source': 'rebuild/2008-06/native-classes/EditSelectionVerbConstructor.cpp',
        'source_sha256': sha(source),
        'manifest': 'rebuild/2008-06/tests/editselectionverb-provider-unit-20261106.json',
        'manifest_sha256': sha(manifest),
        'object': results[0]['object'].replace(str(ROOT) + '\\', '').replace('\\', '/'),
        'object_sha256': results[0]['object_sha256'],
        'compiler': summary['compiler'],
        'compiler_sha256': summary['compiler_sha256'],
        'check': {
            'addr': row['addr'], 'symbol': row['symbol'], 'status': row['status'],
            'target_size': row['target_size'], 'object_size': row['object_size'],
            'target_sha256': row['target_sha256'], 'first_byte_difference': row['first_byte_difference'],
            'data_references': len(row['data_matches']), 'data_errors': row['data_errors'],
        },
        'indirect_call_abi': {
            'probe': 'work/native-candidates/standard-verbs-iat-abi-20261106/probe_indirect_call_abi.py',
            'probe_sha256': sha(ROOT / 'work/native-candidates/standard-verbs-iat-abi-20261106/probe_indirect_call_abi.py'),
            'bindings': 'work/native-candidates/editselectionverb-provider-20261106/bindings.json',
            'bindings_sha256': sha(HERE / 'bindings.json'),
            'totals': bindings['totals'],
            'iat_slots': {
                site['iat_slot']: {
                    'original_import': site['original_import'],
                    'demangled': bindings['demangle']['names'].get(site['original_import']['import']),
                    'candidate_external': site['candidate_external'],
                    'sites': [site['offset']],
                } for site in indirect_sites},
            'scope': ('Same imported callee, same IAT slot, same declared ABI and same argument setup as '
                      'the original client, for every indirect call site in the recovered body.'),
        },
        'direct_call_bindings': {
            'status': 'open',
            'sites': [
                {'offset': 80, 'target': '005833e0',
                 'candidate_external': '??0Verb@RBX@@IAE@PAVVerbContainer@1@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z',
                 'independent_evidence': 'work/2008-06/shared-layouts/verb-ctor.json (task-owned receipt, no build fingerprint; historical, not a fresh proof)'},
                {'offset': 107, 'target': '00618a40',
                 'candidate_external': '??$shared_from@VWorkspace@RBX@@@RBX@@YA?AV?$shared_ptr@VWorkspace@RBX@@@boost@@PAVWorkspace@0@@Z',
                 'independent_evidence': ('none resolved: several task-owned receipts label 00618a40 as '
                                          '??$shared_from@VInstance@RBX@@@RBX@@YA?AV?$shared_ptr@VInstance@RBX@@@boost@@PAVInstance@0@@Z '
                                          'with an explicit "(external)" / "(evidence name)" qualifier, so the '
                                          'specialization identity at 00618a40 is unresolved')},
            ],
            'scope': ('Recorded for the next batch. This unit ran in diagnostic call mode, so no reviewed '
                      'direct-call binding is claimed here; candidate externals are quoted as candidate-derived '
                      'evidence, never as reviewed bindings.'),
        },
        'proof': {
            'exact_bytes': body['byte_identical'],
            'referenced_data': not row['data_errors'],
            'indirect_call_bindings': bindings['indirect_call_bindings_verified'],
            'direct_call_bindings': False,
            'require_proof_exit': 1,
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
            'Reviewed direct-call bindings for the two direct call sites in 0057e730 (offsets 80 and 107)',
            'Resolve the 00618a40 specialization identity (shared_from<Workspace> versus shared_from<Instance>)',
            'Provider selection and link closure for the StandardVerbs composition (missing owner-side inputs)',
            'Relevant P5/P6/runtime gates before any activation',
        ],
        'preserved': ('Shared headers, vendor inputs, other leases and the active executable selection unchanged. '
                      'RBX::MoveDown selection verb 2008 and RBX::CRobloxDoc message handlers 2008 are held by '
                      'other active leases and were not touched.'),
        'metrics': {
            'inactive_exact_addresses': 1,
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
    out = ROOT / 'work/2008-06/shared-layouts/editselectionverb-provider-unit-20261106.json'
    out.write_text(json.dumps(receipt, indent=1, sort_keys=True), encoding='utf-8')
    print(json.dumps({'receipt': str(out.relative_to(ROOT)), 'sha256': sha(out),
                      'indirect_verified': bindings['totals']['verified'],
                      'indirect_total': bindings['totals']['indirect_sites']}, indent=1))


if __name__ == '__main__':
    main()
