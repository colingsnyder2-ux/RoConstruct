"""Consolidate local evidence for the parked link blockers; no build or network."""
import hashlib
import json
from pathlib import Path
import pefile

ROOT = Path(__file__).resolve().parents[4]
HERE = Path(__file__).resolve().parent
sha = lambda path: hashlib.sha256(Path(path).read_bytes()).hexdigest()
campaign = json.loads((HERE / 'campaign.json').read_text())
run = ROOT / 'work/2008-06/native-doc-relinks' / campaign['current_run']
inputs = json.loads((run / 'inputs.json').read_text())
assert all(sha(path) == expected for path, expected in inputs.items())
evidence = [ROOT / 'work/2008-06/shared-layouts' / task / name for task, name in (
    ('sol-extents-evidence-20261105', 'evidence.json'),
    ('sol-writer-evidence-20261105', 'evidence.json'),
    ('sol-vista-abi-20261105', 'contracts.txt'),
    ('sol-vista-abi-20261105', 'inputs.json'),
    ('sol-drag-abi-20261105', 'helper-providers.json'),
    ('sol-drag-abi-20261105', 'contracts.json'),
    ('sol-axis-lifetime-20261105', 'bindings.json'),
    ('sol-axis-lifetime-20261105', 'handoff.json'),
    ('sol-mega-cleanup-20261105', 'handoff.json'),
    ('sol-irenderable-20261105', 'replacement.json'),
    ('sol-irenderable-20261105', 'native-proof.json'),
    ('sol-mega-provenance-20261105', 'handoff.json'),
    ('sol-axis-data-20261105', 'handoff.json'),
    ('sol-xml-actual-20261105', 'receipt.json'),
    ('sol-axis-eh-20261105', 'continuation.json'),
    ('sol-drag-calls-20261105', 'handoff.json'),
    ('sol-clone-provenance-20261105', 'handoff.json'),
    ('sol-clone-owner-20261105', 'handoff.json'),
    ('sol-clone-wrapper-20261105', 'saved-object.json'),
    ('sol-clone-delayed-20261105', 'saved-object.json'),
    ('sol-clone-helper-20261105', 'compile-receipt.json'),
    ('sol-clone-helper-20261105', 'callee-inventory.json'),
    ('sol-serializer-compile-20261105', 'receipt.json'),
    ('sol-serializer-audit-20261105', 'summary.json'),
    ('sol-serializer-audit-20261105', 'include-log-correction.json'),
    ('sol-serializer-callees-20261105', 'inventory.json'),
    ('sol-serializer-inline-20261105', 'receipt.json'),
    ('sol-archive-resolve-20261105', 'summary.json'),
    ('sol-archive-resolve-owner-20261105', 'handoff.json'))]
original = ROOT / 'clients/2008-06/Roblox.exe'
assert sha(original) == '2fbbfdf8577b5b28ea198c14747613ba8fd83d094363b2b23fe2f9e587343764'
pe = pefile.PE(str(original))
debug = pe.DIRECTORY_ENTRY_DEBUG[0].entry
assert debug.CvSignature == b'RSDS'
resume = {
    'swap_target': campaign['swap_target'],
    'current_run': str(run),
    'current_result_sha256': sha(run / 'result.json'),
    'explicit_inputs_rehashed': len(inputs),
    'changed_inputs': [],
    'link_blockers': campaign['unresolved'],
    'duplicates': campaign['duplicates'],
    'cumulative_archive': campaign.get('cumulative_archive'),
    'cumulative_archive_sha256': campaign.get('cumulative_archive_sha256'),
    'primary_evidence': {str(p): sha(p) for p in evidence},
    'original_debug_record': {
        'path': debug.PdbFileName.decode('utf-8').rstrip('\0'),
        'guid': '11AE806B-23B8-4CB0-A191-E30ED910D995',
        'age': debug.Age,
        'nearby_original_pdb_files': [str(p) for p in original.parent.glob('*.pdb')],
        'scope': 'Locator from the verified PE; PDB is not available or authenticated.'},
    'resume_actions': [
        'Acquire version-proven original June 2008 Axis source/include/compiler context before a new render experiment.',
        'Acquire provider-bearing VCWorkspace declaration/TU or matching PDB compiland context before a new writer experiment.',
        'Preserve three-rejected-hypothesis budgets, saved exact providers, and the cumulative archive.',
        'When a justified provider passes exact body/data/call checks, replay the latest explicit command with only guarded changes.',
        'After successful link, verify actual map/PE provider selection, ABI/EH and required runtime gates before activation.'],
    'static_corrections': [
        'computeExtents has direct Geometry size field reads, not a virtual getGridSize call; CRT indirect boundary remains.',
        'DragUtilities.obj header offsets22672778(old0c597) and67861986(historical5e468) are snapshot-specific. Current position is recomputed in drag-static-correction.json. Member SHA400206004ed3d01dfa715c8cc9f9aef7dd2d0f1b70ae05530f4bdd12890aa62a is unchanged.',
        'Axis/Mouse weak externals have search=2 LIBRARY; they are not unconditional search=3 ALIAS records.',
        'Actual XmlElement.obj supplies exact143B clearValue. Prior saved writer EH graphs are conditional; the proof writer object is not a current selected input.',
        'Current helper availability and normalized body equality do not establish linked-PE selection.'],
    'integrated_irenderable': {
        'original_address': '0047d410', 'body_bytes': 1,
        'required_profile': 'Recorded original-MSVC runner flags include /U_RELEASEASSERT /U_DEBUG; source is intentionally not pinned.',
        'scope': 'Exact authentic saved provider plus guarded remainder, supplied to failed diagnostic; no selected-PE proof.'},
    'independent_next_work': ['ResolveRefs hypothesis2 uses original two early-false gates and late true return; one prior rejected native trial.',
                              'Refresh resolve-owner no-loss/consumer audit against current332 inputs and add the exact native method before composition.',
                              'Competing factory COMDAT stays a selected-PE obligation; supplied loader object also has an exact286B factory candidate.'],
    'integrated_loader': {
        'address': '00593250', 'body_bytes': 550, 'data_checks': 3,
        'object_sha256': 'e5508d0afe443b7195efdce28703b97e7c634e15d85a84a97b4ba28d5fc88767',
        'direct_bindings': 17, 'strict_indirect_sites': 4, 'prior_rejections': 1,
        'scope': 'Exact body/data supplied to isolated diagnostic with owner split; resolveRefs, complete ABI/EH, selection and runtime remain gated.'},
    'integrated_clone': {
        'address': '00559350', 'body_bytes': 149,
        'object_sha256': '5ce86906a4f9046887cb1a976ea551944069c3f08313bba25ca84a799a16457f',
        'direct_calls_verified': 4, 'prior_rejected_hypotheses': 1,
        'scope': 'Exact code/data in isolated diagnostic with exact245B helper and owner remainder; virtual indirect, EH/ABI, private canonical ODR and runtime gates remain open.'},
    'inactive_from_xml_root': {
        'address': '00559250', 'body_bytes': 245,
        'object': str(ROOT / 'work/2008-06/native-check-runs/20261105-144726-344e0b26/unit-000/candidate.obj'),
        'object_sha256': '7048fbbf73b4d1f6e9e3fc967eded57734290e8ba4f9037578b99256446a3153',
        'scope': 'Exact code/data with reviewed direct calls; imported indirects, loadInstances callee correctness, EH/selection/ABI/runtime remain separate.'},
    'conditional_eh_extension': {
        'receipt': str(HERE / 'axis-mega-eh-continuation.json'),
        'scope': 'Separate Axis and actual MegaDragger cleanup graphs with supplied actual external bodies; selected PE, indirect ABI/runtime and strict indirect failures remain open.'},
    'executed': False, 'activation': False, 'gated_swaps': 0, 'server_credit': 0}
(HERE / 'resume.json').write_text(json.dumps(resume, indent=2) + '\n')
print(json.dumps({'inputs_rehashed': len(inputs), 'unresolved': len(campaign['unresolved']),
                  'duplicates': len(campaign['duplicates']), 'resume': str(HERE / 'resume.json')}))
