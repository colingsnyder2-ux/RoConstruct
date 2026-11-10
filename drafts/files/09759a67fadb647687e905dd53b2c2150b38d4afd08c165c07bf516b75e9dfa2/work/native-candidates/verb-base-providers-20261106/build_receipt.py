"""Assemble the task-owned shared-layouts receipt for the verb base provider unit."""
import hashlib
import json
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = next((p for p in HERE.parents if (p / 'roconstruct-package.json').is_file()), HERE.parents[4])
RUN = ROOT / 'work/2008-06/native-check-runs/20261106-122432-79a80ce8'


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def main():
    results = json.loads((RUN / 'results.json').read_text(encoding='utf-8'))
    summary = json.loads((RUN / 'summary.json').read_text(encoding='utf-8'))
    bindings = json.loads((HERE / 'bindings.json').read_text(encoding='utf-8'))
    analysis = max(RUN.glob('analysis-*.json'), key=lambda p: p.stat().st_mtime)
    rows = {r['source'].rsplit('\\', 1)[-1].rsplit('/', 1)[-1]: r for r in json.loads(analysis.read_text(encoding='utf-8'))}
    manifest = ROOT / 'rebuild/2008-06/tests/verb-base-providers-unit-20261106.json'
    sources = {
        'RunStateVerbConstructor.cpp': ('0057e330', '??0RunStateVerb@RBX@@IAE@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAVDataModel@1@@Z',
                                        'RunStateVerb ctor: the provider StandardVerbs constructs at 26 call sites'),
        'Verb.cpp': ('005833e0', '??0Verb@RBX@@IAE@PAVVerbContainer@1@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z',
                     'Verb ctor: the base of every derived verb in the composition'),
        'VerbBaseLifetime.cpp': ('005832c0', '??1Verb@RBX@@UAE@XZ',
                                 'Verb dtor: called 8 times by StandardVerbs::~StandardVerbs'),
        'BasicVerbConstructors.cpp': ('0057e8d0', '??0DeleteBase@RBX@@IAE@PAVDataModel@1@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z',
                                      'DeleteBase ctor: the provider StandardVerbs constructs twice'),
    }
    by_symbol = {b['symbol']: b for b in bindings['bodies']}
    checks = []
    for name, (addr, symbol, role) in sources.items():
        result = next(r for r in results if r['source'].rsplit('\\', 1)[-1].rsplit('/', 1)[-1] == name)
        analysis_row = rows[name]
        for row in analysis_row['checks']:
            identity = row.get('call_identity') or {'calls': [], 'passed': None}
            body = by_symbol.get(row.get('symbol'))
            entry = {
                'unit': name,
                'role': role if row['addr'] == addr else 'same translation unit',
                'addr': row['addr'],
                'symbol': row.get('symbol'),
                'status': row['status'],
                'target_size': row['target_size'],
                'object_size': row['object_size'],
                'target_sha256': row['target_sha256'],
                'first_byte_difference': row['first_byte_difference'],
                'object': result['object'].replace(str(ROOT) + '\\', '').replace('\\', '/'),
                'object_sha256': result['object_sha256'],
                'source': result['source'].replace(str(ROOT) + '\\', '').replace('\\', '/'),
                'source_sha256': result['source_sha256'],
                'data_references': len(row.get('data_matches', [])),
                'data_errors': row.get('data_errors', []),
                'call_identity_mode': 'reviewed bindings declared' if identity['calls'] else 'diagnostic (no expectations declared)',
                'direct_call_bindings_verified': len([r for r in identity['calls']
                                                      if r['status'] == 'verified_binding']),
                'call_sites_total': len(identity['calls']),
                'indirect_call_sites': len([r for r in identity['calls']
                                            if r['status'] != 'verified_binding']),
                'call_identity_passed': identity['passed'],
            }
            if body:
                entry['iat_indirect_call_sites'] = len(body['indirect_sites'])
                entry['indirect_call_abi_verified'] = all(s['verified_indirect_call_binding']
                                                          for s in body['indirect_sites'])
                entry['virtual_dispatch_sites'] = body.get('virtual_dispatch_sites', 0)
            checks.append(entry)

    open_bindings = []
    for name, row in (('Verb.cpp', rows['Verb.cpp']['checks'][0]), ('VerbBaseLifetime.cpp', rows['VerbBaseLifetime.cpp']['checks'][0])):
        pass
    open_bindings = [
        {'unit': 'Verb.cpp', 'addr': '005833e0', 'offset': 50, 'target': '00553f90',
         'candidate_external': '?declare@Name@RBX@@SAABVName@2@PBDH@Z',
         'evidence': ('address independently recorded as Name::declare 00553f90 by the StandardVerbs adapter '
                      'proof; the exact decorated string is candidate-derived here and not yet independently confirmed')},
        {'unit': 'Verb.cpp', 'addr': '005833e0', 'offset': 80, 'target': '005644a0',
         'candidate_external': '??A?$map@PBVName@RBX@@PAVVerb@2@U?$less@PBVName@RBX@@@std@@V?$allocator@U?$pair@QBVName@RBX@@PAVVerb@2@@std@@@5@@std@@QAEAAPAVVerb@RBX@@ABQBVName@3@@Z',
         'evidence': 'no independent decorated-name evidence yet'},
        {'unit': 'VerbBaseLifetime.cpp', 'addr': '005832c0', 'offset': 21, 'target': '00405ce0',
         'candidate_external': '?erase@?$_Tree@V?$_Tmap_traits@PBVName@RBX@@PAVVerb@2@U?$less@PBVName@RBX@@@std@@V?$allocator@U?$pair@QBVName@RBX@@PAVVerb@2@@std@@@5@$0A@@std@@@std@@QAEIABQBVName@RBX@@@Z',
         'evidence': 'no independent decorated-name evidence yet'},
    ]

    receipt = {
        'schema': 1,
        'workflow': 52,
        'client': '2008-06',
        'task': 'Native source recovery with automatic draft sharing',
        'swap_target': ('Document/Workspace native class swap: CRobloxDoc/StandardVerbs composition '
                        'and tool-verb mouse-command providers'),
        'blocker_reduced': ('The four base-class providers the StandardVerbs ctor/dtor actually call are now '
                            'byte-exact from existing native sources in this package, closing the provider '
                            'chain DeleteBase -> EditSelectionVerb -> Verb -> Name::declare / std::map for the '
                            'StandardVerbs composition.'),
        'package_revision': json.loads((ROOT / 'roconstruct-package.json').read_text(encoding='utf-8'))['revision'],
        'workspace_manifest_source_revision': json.loads((ROOT / 'workspace-manifest.json').read_text(encoding='utf-8'))['source_revision'],
        'baseline_commit': 'unknown',
        'owner_checkout_queue_present': False,
        'unit': 'verb base providers',
        'run': str(RUN.relative_to(ROOT)),
        'analysis': str(analysis.relative_to(ROOT)),
        'manifest': 'rebuild/2008-06/tests/verb-base-providers-unit-20261106.json',
        'manifest_sha256': sha(manifest),
        'compiler': summary['compiler'],
        'compiler_sha256': summary['compiler_sha256'],
        'checks': checks,
        'indirect_call_abi': {
            'probe': 'work/native-candidates/standard-verbs-iat-abi-20261106/probe_indirect_call_abi.py',
            'probe_sha256': sha(ROOT / 'work/native-candidates/standard-verbs-iat-abi-20261106/probe_indirect_call_abi.py'),
            'bindings': 'work/native-candidates/verb-base-providers-20261106/bindings.json',
            'bindings_sha256': sha(HERE / 'bindings.json'),
            'totals': bindings['totals'],
            'demangle_tool': bindings['demangle'].get('__tool__'),
            'scope': ('Same imported callee, same IAT slot, same declared ABI and same argument setup as the '
                      'original client, for every indirect call site in each recovered body. Verb::~Verb 005832c0 '
                      'has no indirect call sites, so that obligation is vacuously satisfied for it.'),
        },
        'open_direct_call_bindings': open_bindings,
        'proof': {
            'exact_bytes': all(c['status'] == 'exact' for c in checks),
            'referenced_data': all(not c['data_errors'] for c in checks),
            'direct_call_bindings': 'partial: 2 of 5 direct call sites carry independently evidenced reviewed bindings',
            'indirect_call_bindings': bindings['indirect_call_bindings_verified'],
            'require_proof_exit': 1,
            'require_proof_reason': ('native_check_runner analyze --require-proof exits 1 by design whenever a body '
                                     'has indirect call sites; the indirect-call ABI obligation has its own reviewed '
                                     'receipt above and three direct-call bindings remain open.'),
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
        'duplicate_definitions': [
            'MoveUpSelectionVerb/MoveUpPlateVerb/MoveUpBrickVerb are defined in both BasicVerbConstructors.cpp and the ported MoveUpVerbConstructors.cpp; a single owner must be selected before any link.',
            'MoveDownSelectionVerb is defined in both BasicVerbConstructors.cpp and SelectionVerbConstructors.cpp; SelectionVerbConstructors.cpp is outside this lease.',
        ],
        'remaining': [
            'Three reviewed direct-call bindings listed in open_direct_call_bindings',
            'Resolve which translation unit owns each duplicated verb constructor before any link',
            'Provider selection and link closure for the StandardVerbs composition (missing owner-side inputs)',
            'Relevant P5/P6/runtime gates before any activation',
        ],
        'preserved': ('Shared headers, vendor inputs, other leases and the active executable selection unchanged. '
                      'RBX::CRobloxDoc message handlers 2008, RBX::MoveDown selection verb 2008, RBX::Lua instance '
                      'bridge 2008, RBX::ScoreHud gui huds 2008, RBX::ViewNew render 2008 and boost shared_count '
                      'Creatable 2008 are held by other workers and were not touched.'),
        'metrics': {
            'inactive_exact_addresses': len([c for c in checks if c['status'] == 'exact']),
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
    out = ROOT / 'work/2008-06/shared-layouts/verb-base-providers-unit-20261106.json'
    out.write_text(json.dumps(receipt, indent=1, sort_keys=True), encoding='utf-8')
    print(json.dumps({'receipt': str(out.relative_to(ROOT)), 'sha256': sha(out),
                      'checks': [{c['unit']: c['status']} for c in checks],
                      'indirect_verified': bindings['totals']['verified'],
                      'indirect_total': bindings['totals']['indirect_sites']}, indent=1))


if __name__ == '__main__':
    main()
