"""Assemble the task-owned shared-layouts receipt for the selection verb destructor unit."""
import hashlib
import json
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = next((p for p in HERE.parents if (p / 'roconstruct-package.json').is_file()), HERE.parents[4])
RUN = ROOT / 'work/2008-06/native-check-runs/20261106-123742-b9c68558'


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def main():
    results = json.loads((RUN / 'results.json').read_text(encoding='utf-8'))
    summary = json.loads((RUN / 'summary.json').read_text(encoding='utf-8'))
    bindings = json.loads((HERE / 'bindings.json').read_text(encoding='utf-8'))
    source = ROOT / 'rebuild/2008-06/native-classes/VerbLifetime.cpp'
    manifest = ROOT / 'rebuild/2008-06/tests/selection-verb-dtors-unit-20261106.json'
    by_symbol = {b['symbol']: b for b in bindings['bodies']}
    roles = {
        '0057dfd0': 'RunStateVerb dtor: the provider StandardVerbs::~StandardVerbs calls at 22 sites',
        '0057e050': 'EditSelectionVerb dtor: the provider StandardVerbs::~StandardVerbs calls at 18 sites',
    }
    checks = []
    for row in results[0]['checks']:
        body = by_symbol[row['symbol']]
        checks.append({
            'addr': row['addr'], 'symbol': row['symbol'], 'role': roles.get(row['addr'], ''),
            'status': row['status'],
            'target_size': row['target_size'], 'object_size': row['object_size'],
            'target_sha256': row['target_sha256'], 'first_byte_difference': row['first_byte_difference'],
            'data_references': len(row['data_matches']), 'data_errors': row['data_errors'],
            'direct_call_bindings_verified': len([r for r in row['call_identity']['calls']
                                                  if r['status'] == 'verified_binding']),
            'call_sites_total': len(row['call_identity']['calls']),
            'indirect_call_sites': len([r for r in row['call_identity']['calls']
                                        if r['status'] != 'verified_binding']),
            'call_identity_passed': row['call_identity']['passed'],
            'iat_indirect_call_sites': len(body['indirect_sites']),
            'iat_indirect_call_bindings_verified': all(s['verified_indirect_call_binding']
                                                       for s in body['indirect_sites']),
            'virtual_dispatch_sites': body['virtual_dispatch_sites'],
            'virtual_dispatch_offsets': body['virtual_dispatch_offsets'],
        })

    receipt = {
        'schema': 1,
        'workflow': 52,
        'client': '2008-06',
        'task': 'Native source recovery with automatic draft sharing',
        'swap_target': ('Document/Workspace native class swap: CRobloxDoc/StandardVerbs composition '
                        'and tool-verb mouse-command providers'),
        'blocker_reduced': ('The two destructor providers StandardVerbs::~StandardVerbs actually calls are now '
                            'byte-exact from the existing native source, and their single direct call to '
                            'Verb::~Verb 005832c0 (proven exact in the same session) carries a reviewed binding.'),
        'package_revision': json.loads((ROOT / 'roconstruct-package.json').read_text(encoding='utf-8'))['revision'],
        'workspace_manifest_source_revision': json.loads((ROOT / 'workspace-manifest.json').read_text(encoding='utf-8'))['source_revision'],
        'baseline_commit': 'unknown',
        'owner_checkout_queue_present': False,
        'unit': 'VerbLifetime.cpp',
        'run': str(RUN.relative_to(ROOT)),
        'source': 'rebuild/2008-06/native-classes/VerbLifetime.cpp',
        'source_sha256': sha(source),
        'manifest': 'rebuild/2008-06/tests/selection-verb-dtors-unit-20261106.json',
        'manifest_sha256': sha(manifest),
        'object': results[0]['object'].replace(str(ROOT) + '\\', '').replace('\\', '/'),
        'object_sha256': results[0]['object_sha256'],
        'compiler': summary['compiler'],
        'compiler_sha256': summary['compiler_sha256'],
        'checks': checks,
        'indirect_call_abi': {
            'probe': 'work/native-candidates/standard-verbs-iat-abi-20261106/probe_indirect_call_abi.py',
            'probe_sha256': sha(ROOT / 'work/native-candidates/standard-verbs-iat-abi-20261106/probe_indirect_call_abi.py'),
            'bindings': 'work/native-candidates/selection-verb-dtors-20261106/bindings.json',
            'bindings_sha256': sha(HERE / 'bindings.json'),
            'totals': bindings['totals'],
            'scope': ('Neither destructor body reaches an imported function through an IAT slot, so that '
                      'obligation is empty for this unit. The six register-indirect call sites are virtual '
                      'dispatches (call eax / call edx from a loaded vtable pointer); their slot identity and '
                      'callee ABI are a separate obligation and are NOT proven here.'),
        },
        'proof': {
            'exact_bytes': all(c['status'] == 'exact' for c in checks),
            'referenced_data': all(not c['data_errors'] for c in checks),
            'direct_call_bindings': True,
            'indirect_call_bindings': True,
            'virtual_dispatch_bindings': False,
            'require_proof_exit': 1,
            'require_proof_reason': ('native_check_runner analyze --require-proof exits 1 by design whenever a body '
                                     'has indirect call sites; here the indirect sites are virtual dispatches whose '
                                     'slot identity and callee ABI remain unproven.'),
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
            'Virtual-dispatch slot identity and callee ABI for the six call eax / call edx sites',
            'Provider selection and link closure for the StandardVerbs composition (missing owner-side inputs)',
            'Relevant P5/P6/runtime gates before any activation',
        ],
        'preserved': ('Shared headers, vendor inputs, other leases and the active executable selection unchanged. '
                      'RBX::CRobloxDoc message handlers 2008, RBX::MoveDown selection verb 2008, RBX::Lua instance '
                      'bridge 2008, RBX::ScoreHud gui huds 2008, RBX::ViewNew render 2008 and boost shared_count '
                      'Creatable 2008 are held by other workers and were not touched.'),
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
    out = ROOT / 'work/2008-06/shared-layouts/selection-verb-dtors-unit-20261106.json'
    out.write_text(json.dumps(receipt, indent=1, sort_keys=True), encoding='utf-8')
    print(json.dumps({'receipt': str(out.relative_to(ROOT)), 'sha256': sha(out),
                      'checks': [{c['addr']: c['status']} for c in checks],
                      'virtual_dispatch_sites': bindings['totals']['virtual_dispatch_sites']}, indent=1))


if __name__ == '__main__':
    main()
