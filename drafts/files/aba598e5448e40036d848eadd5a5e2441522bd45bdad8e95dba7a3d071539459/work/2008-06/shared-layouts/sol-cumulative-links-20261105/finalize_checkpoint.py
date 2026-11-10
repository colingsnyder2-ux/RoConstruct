"""Save the input-blocked handoff without rerunning an unchanged diagnostic."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[4]
HERE = Path(__file__).resolve().parent
sha = lambda path: hashlib.sha256(Path(path).read_bytes()).hexdigest()
campaign = json.loads((HERE / 'campaign.json').read_text())
run = ROOT / 'work/2008-06/native-doc-relinks' / campaign['current_run']
result = json.loads((run / 'result.json').read_text())
inputs = json.loads((run / 'inputs.json').read_text())
assert len(inputs) == 332 and not result['changed_inputs']
assert all(sha(path) == expected for path, expected in inputs.items())
assert len(result['blockers']) == 3 and not result['duplicates']
assert sha(campaign['cumulative_archive']) == campaign['cumulative_archive_sha256']
prerequisite_path = ROOT / 'work/2008-06/shared-layouts/sol-snapshot-20261105/fresh-prerequisite-snapshot.json'
prerequisites = json.loads(prerequisite_path.read_text())
assert len(prerequisites) == 15
assert all(row['report']['linked'] and row['report']['test_exit'] == 0 for row in prerequisites.values())
parked = [
    {'target': 'AxisMoveTool::render2d / render3dAdorn', 'addresses': ['00640f30', '00641040'],
     'rejected_hypotheses': 3, 'missing': 'Original June2008 Axis TU/PCH/compiler context or version-proven differing Extents/G3D headers.',
     'receipt': str(ROOT / 'work/2008-06/shared-layouts/sol-extents-evidence-20261105/evidence.json')},
    {'target': 'CWorkspace::write', 'addresses': ['0046b860'], 'rejected_hypotheses': 3,
     'missing': 'Provider-bearing original writer declaration/TU and compiler context preserving implicit destructor boundary and EH state1.',
     'receipt': str(ROOT / 'work/2008-06/shared-layouts/sol-writer-evidence-20261105/evidence.json')},
    {'target': 'ArchiveBinder::resolveRefs', 'addresses': ['00592720'], 'rejected_hypotheses': 3,
     'missing': 'Genuine new source/compiler context explaining original boolean normalization and epilogue; no H4/grid authorized.',
     'receipt': str(ROOT / 'work/2008-06/shared-layouts/sol-archive-resolve-final-20261105/summary.json')}]
campaign.update(status='blocked_on_genuine_original_inputs', additional_compiles_authorized=0,
                parked=parked, inputs_changed=[], exact_selected_in_pe=None,
                fully_gated_swaps=0, new_server_credit_claimed=0,
                next_queue=['Acquire a specific missing original input; read resume.json and hashes first.',
                            'Reuse exact saved objects and the cumulative b9d archive; never select the conditional8f1d resolver archive without a separately exact method.',
                            'Successful isolated link/map/PE selection, transitive ABI/EH/import/weak binding and affected runtime gates precede activation.'])
(HERE / 'campaign.json').write_text(json.dumps(campaign, indent=2) + '\n')
handoff = {
    'status': campaign['status'], 'workspace': str(ROOT),
    'authority': 'RoConstruct/work/workspace',
    'baseline_revision': 'e9bfe6671a60913f56cc7efc99de1b9045ede2ecfe9570327ad0a53f2f195188',
    'latest_diagnostic': str(run), 'latest_result_sha256': sha(run / 'result.json'),
    'current_explicit_inputs': 332, 'input_drift': [],
    'unresolved': [row['symbol'] for row in result['blockers']], 'duplicates': [],
    'current_archive': campaign['cumulative_archive'], 'current_archive_sha256': campaign['cumulative_archive_sha256'],
    'fresh_baseline_prerequisites_passed': 15,
    'prerequisite_receipt': str(prerequisite_path), 'prerequisite_receipt_sha256': sha(prerequisite_path),
    'module_scope': 'Baseline canonical modules linked/smoked. Subsequent native-provider changes were isolated diagnostics; these are not native class/runtime swap passes.',
    'recent_exact_supplied_providers': [
        {'address': '0047d410', 'name': 'IRenderable destructor', 'bytes': 1},
        {'address': '00559350', 'name': 'Instance::clone', 'bytes': 149},
        {'address': '00559250', 'name': 'Instance::fromXmlRoot', 'bytes': 245},
        {'address': '00593250', 'name': 'SerializerV2::loadInstances', 'bytes': 550}],
    'provider_scope': 'Original code/data checks passed; detailed direct/indirect proofs are in per-provider receipts. These are supplied diagnostic inputs, not selected PE or complete ABI/runtime proof.',
    'parked': parked,
    'canonical_resolve_projection': str(HERE / 'parked-resolve-projection.json'),
    'resume': str(HERE / 'resume.json'),
    'private_profile_gates': ['Canonical ODR/compatibility is still required before shared-header adoption.',
                              'xstring.h is the uploadable source; extensionless compiler xstring is reproduced by prepare_inline_cstr_context.py.'],
    'selection_gates': ['No selected PE/map because three original providers remain unresolved.',
                        'Factory create exact and competing near-match COMDATs require actual selected bytes.',
                        'COFF weak externals use LIBRARY search=2, not unconditional ALIAS.',
                        'Implicit library/SxS, exhaustive dynamic controlblock lifetimes, transitive EH/ABI and runtime remain open.'],
    'diagnostic_executed': False, 'activation': False, 'fully_gated_swaps': 0,
    'new_server_credit_claimed': 0, 'source_compiles_this_finalization': 0, 'links_this_finalization': 0}
(HERE / 'final-handoff.json').write_text(json.dumps(handoff, indent=2) + '\n')
print(json.dumps({'status': handoff['status'], 'prerequisites': 15, 'inputs': 332,
                  'unresolved': 3, 'duplicates': 0, 'changed_inputs': 0,
                  'handoff': str(HERE / 'final-handoff.json')}))
