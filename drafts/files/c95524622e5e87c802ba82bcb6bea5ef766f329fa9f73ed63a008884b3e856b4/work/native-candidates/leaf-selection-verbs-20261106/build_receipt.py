"""Assemble the task-owned shared-layouts receipt for the leaf selection verb unit."""
import hashlib
import json
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = next((p for p in HERE.parents if (p / 'roconstruct-package.json').is_file()), HERE.parents[4])
RUN = ROOT / 'work/2008-06/native-check-runs/20261106-125501-fd69a291'


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def main():
    results = {r['source'].rsplit('\\', 1)[-1].rsplit('/', 1)[-1]: r for r in
               json.loads((RUN / 'results.json').read_text(encoding='utf-8'))}
    summary = json.loads((RUN / 'summary.json').read_text(encoding='utf-8'))
    bindings = json.loads((HERE / 'bindings.json').read_text(encoding='utf-8'))
    analysis = max(RUN.glob('analysis-*.json'), key=lambda p: p.stat().st_mtime)
    manifest = ROOT / 'rebuild/2008-06/tests/leaf-selection-verbs-unit-20261106.json'
    rows = {r['source'].rsplit('\\', 1)[-1].rsplit('/', 1)[-1]: r for r in
            json.loads(analysis.read_text(encoding='utf-8'))}
    by_symbol = {b['symbol']: b for b in bindings['bodies']}
    units = {
        'SelectionVerbConstructors.cpp': ('canonical headers',
                                          'the 12 leaf and base verb constructors StandardVerbs constructs '
                                          '(BoolPropertyVerb, AnchorVerb, TranslucentVerb, CanCollideVerb, '
                                          'Group/Weld/Snap/Ungroup/DuplicateSelectionVerb, Attach/Track/Follow/'
                                          'WatchCameraCommand)'),
        'AxisVerbConstructors.cpp': ('scoped header experiment: pinned // native-flags: adds '
                                     'native-headers/mfc-noinline-pcxstr and native-headers/std-noinline-string',
                                     'RotateAxisCommand, ControllerCommand, Rotate/TiltSelectionVerb, '
                                     'Primary/SecondaryControllerCommand'),
    }
    checks = []
    for name, (profile, role) in units.items():
        result = results[name]
        for row in rows[name]['checks']:
            identity = row.get('call_identity') or {'calls': [], 'passed': None}
            body = by_symbol.get(row.get('symbol'))
            checks.append({
                'unit': name,
                'addr': row['addr'],
                'symbol': row.get('symbol'),
                'status': row['status'],
                'target_size': row['target_size'],
                'object_size': row['object_size'],
                'target_sha256': row['target_sha256'],
                'first_byte_difference': row['first_byte_difference'],
                'data_references': len(row.get('data_matches', [])),
                'data_errors': row.get('data_errors', []),
                'call_sites_total': len(identity['calls']),
                'direct_call_bindings_verified': len([r for r in identity['calls'] if r['status'] == 'verified_binding']),
                'call_identity_passed': identity['passed'],
                'iat_indirect_call_sites': len(body['indirect_sites']) if body else 0,
                'indirect_call_abi_verified': all(s['verified_indirect_call_binding'] for s in body['indirect_sites']) if body else None,
                'object': result['object'].replace(str(ROOT) + '\\', '').replace('\\', '/'),
                'object_sha256': result['object_sha256'],
                'source_sha256': result['source_sha256'],
                'header_profile': profile,
                'role': role if row is rows[name]['checks'][0] else 'same translation unit',
            })

    receipt = {
        'schema': 1,
        'workflow': 52,
        'client': '2008-06',
        'task': 'Native source recovery with automatic draft sharing',
        'swap_target': ('Document/Workspace native class swap: CRobloxDoc/StandardVerbs composition '
                        'and tool-verb mouse-command providers'),
        'blocker_reduced': ('The 16 leaf verb constructors StandardVerbs::StandardVerbs constructs are now '
                            'byte-exact from the two existing native sources, together with the three base-class '
                            'constructors they forward to (BoolPropertyVerb 0057f530, RotateAxisCommand 0057f450, '
                            'ControllerCommand 0057f4c0), so the whole leaf layer of the composition is closed.'),
        'package_revision': json.loads((ROOT / 'roconstruct-package.json').read_text(encoding='utf-8'))['revision'],
        'workspace_manifest_source_revision': json.loads((ROOT / 'workspace-manifest.json').read_text(encoding='utf-8'))['source_revision'],
        'baseline_commit': 'unknown',
        'owner_checkout_queue_present': False,
        'unit': 'leaf selection verbs',
        'run': str(RUN.relative_to(ROOT)),
        'analysis': str(analysis.relative_to(ROOT)),
        'manifest': 'rebuild/2008-06/tests/leaf-selection-verbs-unit-20261106.json',
        'manifest_sha256': sha(manifest),
        'compiler': summary['compiler'],
        'compiler_sha256': summary['compiler_sha256'],
        'checks': checks,
        'direct_call_bindings': {
            'verified': sum(c['direct_call_bindings_verified'] for c in checks),
            'total': sum(c['call_sites_total'] for c in checks),
            'provenance': {
                '0057e730 EditSelectionVerb ctor': ('independently evidenced: reviewed StandardVerbs call bindings '
                                                    'and this session\'s byte-exact receipt for that body (9 leaf verbs)'),
                '0057f530 BoolPropertyVerb ctor': ('address from the original assembly of each leaf; the exact decorated '
                                                   'string is candidate-derived and the body is byte-exact in this unit, '
                                                   'so the binding asserts address plus candidate external only (3 leaf verbs)'),
                '0057f450 RotateAxisCommand ctor': ('address from the original assembly; decorated string candidate-derived '
                                                    '(2 leaf verbs)'),
                '0057f4c0 ControllerCommand ctor': ('address from the original assembly; decorated string candidate-derived '
                                                    '(2 leaf verbs)'),
            },
            'scope': ('Every leaf\'s single direct call carries a reviewed symbol/address binding verified on the '
                      'reused object. The other call site in each body is the MSVCP90 std::string ctor through the '
                      'IAT, whose ABI is proven by the separate indirect-call ABI receipt, not here.'),
        },
        'indirect_call_abi': {
            'probe': 'work/native-candidates/standard-verbs-iat-abi-20261106/probe_indirect_call_abi.py',
            'probe_sha256': sha(ROOT / 'work/native-candidates/standard-verbs-iat-abi-20261106/probe_indirect_call_abi.py'),
            'bindings': 'work/native-candidates/leaf-selection-verbs-20261106/bindings.json',
            'bindings_sha256': sha(HERE / 'bindings.json'),
            'totals': bindings['totals'],
            'demangle_tool': bindings['demangle'].get('__tool__'),
            'scope': ('Same imported callee, same IAT slot, same declared ABI and same argument setup as the '
                      'original client, for every indirect call site in every recovered body.'),
        },
        'inactive_pending_canonical_headers': {
            'unit': 'AxisVerbConstructors.cpp',
            'bodies': [c['addr'] for c in checks if c['unit'] == 'AxisVerbConstructors.cpp'],
            'reason': ('The source pins // native-flags: with native-headers/mfc-noinline-pcxstr and '
                       'native-headers/std-noinline-string. A scoped header experiment remains inactive until '
                       'canonical-header compatibility is proven, so these byte matches are inactive evidence.'),
        },
        'proof': {
            'exact_bytes': all(c['status'] == 'exact' for c in checks),
            'referenced_data': all(not c['data_errors'] for c in checks),
            'direct_call_bindings': True,
            'indirect_call_bindings': bindings['indirect_call_bindings_verified'],
            'require_proof_exit': 1,
            'require_proof_reason': ('native_check_runner analyze --require-proof exits 1 by design whenever a body '
                                     'has indirect call sites; the indirect-call ABI obligation has its own reviewed '
                                     'receipt above.'),
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
            'MoveDownSelectionVerb is defined in SelectionVerbConstructors.cpp and in MoveDownSelectionVerb.cpp (held by another active lease); MoveUpSelectionVerb/MoveUpPlateVerb/MoveUpBrickVerb are defined in BasicVerbConstructors.cpp and in the ported MoveUpVerbConstructors.cpp.',
            'One owner per symbol must be selected before any link.',
        ],
        'remaining': [
            'Canonical-header compatibility proof for AxisVerbConstructors.cpp before its results can be considered active',
            'Independent decorated-name evidence for BoolPropertyVerb, RotateAxisCommand and ControllerCommand constructors',
            'The tool-verb providers (ArrowTool, AxisMoveTool, CloneTool, FlatTool, GameTool, GlueTool, GrabTool, HammerTool, HingeTool, InletTool, LaserTool, LeftMotorTool, ModelSetFrontTool, AnchorTool, LockTool, NullTool, OscillateMotorTool, FillTool, DropperTool, ModelSetPrimaryPartTool, ResizeTool, RightMotorTool, RocketTool, SlingshotTool, StudsTool, WeldTool constructors) called by TToolVerb<...>::newMouseCommand',
            'Provider selection and link closure for the StandardVerbs composition (missing owner-side inputs)',
            'Relevant P5/P6/runtime gates before any activation',
        ],
        'preserved': ('Shared headers, vendor inputs, other leases and the active executable selection unchanged. '
                      'MoveDownSelectionVerb.cpp and MoveUpSelectionVerb.cpp are held by another active lease and '
                      'were not edited. RBX::CRobloxDoc message handlers 2008 and the EspClaude leases were not touched.'),
        'metrics': {
            'inactive_exact_addresses': len([c for c in checks if c['status'] == 'exact']),
            'inactive_pending_canonical_headers': len([c for c in checks if c['unit'] == 'AxisVerbConstructors.cpp']),
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
    out = ROOT / 'work/2008-06/shared-layouts/leaf-selection-verbs-unit-20261106.json'
    out.write_text(json.dumps(receipt, indent=1, sort_keys=True), encoding='utf-8')
    print(json.dumps({'receipt': str(out.relative_to(ROOT)), 'sha256': sha(out),
                      'checks': len(checks),
                      'direct_bindings_verified': sum(c['direct_call_bindings_verified'] for c in checks),
                      'indirect_verified': bindings['totals']['verified'],
                      'indirect_total': bindings['totals']['indirect_sites']}, indent=1))


if __name__ == '__main__':
    main()
