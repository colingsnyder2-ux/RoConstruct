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
    ('sol-irenderable-20261105', 'native-proof.json'))]
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
        'DragUtilities.obj archive header offset is 22672778, member SHA400206004ed3d01dfa715c8cc9f9aef7dd2d0f1b70ae05530f4bdd12890aa62a.',
        'Current helper availability and normalized body equality do not establish linked-PE selection.'],
    'integrated_irenderable': {
        'original_address': '0047d410', 'body_bytes': 1,
        'required_profile': 'Recorded original-MSVC runner flags include /U_RELEASEASSERT /U_DEBUG; source is intentionally not pinned.',
        'scope': 'Exact authentic saved provider plus guarded remainder, supplied to failed diagnostic; no selected-PE proof.'},
    'independent_next_work': ['MegaDragger constructor/controlblock input provenance',
                              'Axis vtable/RTTI and COFF weak fallback data bindings',
                              'Actual XML clearValue provider and lifetime boundary'],
    'executed': False, 'activation': False, 'gated_swaps': 0, 'server_credit': 0}
(HERE / 'resume.json').write_text(json.dumps(resume, indent=2) + '\n')
print(json.dumps({'inputs_rehashed': len(inputs), 'unresolved': len(campaign['unresolved']),
                  'duplicates': len(campaign['duplicates']), 'resume': str(HERE / 'resume.json')}))
