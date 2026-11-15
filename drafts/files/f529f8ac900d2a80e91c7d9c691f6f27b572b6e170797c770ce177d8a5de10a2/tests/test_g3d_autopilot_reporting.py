import importlib.util
import json
from pathlib import Path
import sys
from unittest.mock import patch
from subprocess import CompletedProcess
import pytest

directory = Path(__file__).resolve().parents[1] / 'rebuild/2008-06/tests'
sys.path.insert(0, str(directory))
spec = importlib.util.spec_from_file_location('autopilot_reporting', directory / 'g3d_native_batch_review.py')
batch = importlib.util.module_from_spec(spec)
spec.loader.exec_module(batch)


def test_report_includes_decimal_scores_compile_failure_and_proof_gaps():
    plan = {'jobs': [{'source': 'x.cpp', 'checks': [{'addr': '00401000', 'symbol': '?foo', 'library': 'G3D'}]},
                     {'source': 'bad.cpp', 'checks': [{'addr': '00401100', 'symbol': '?bar', 'library': 'zlib'}]}]}
    builds = [{'source': 'x.cpp', 'status': 'complete', 'dependencies': {'x.cpp': 'abc'}},
              {'source': 'bad.cpp', 'status': 'failed', 'error': 'compiler failed'}]
    checked = [{'source': 'x.cpp', 'checks': [{'addr': '00401000', 'status': 'exact', 'metrics': {
        'positional_percent': 100.0, 'raw_positional_percent': 79.123456}, 'call_identity': {'passed': False}}]}]
    rows, dependencies = batch.report_diagnostics(plan, builds, checked)
    assert dependencies == {'x.cpp': 'abc'}
    assert rows[0]['metrics']['raw_positional_percent'] == 79.123456
    assert rows[0]['call_identity']['passed'] is False
    assert rows[0]['library'] == 'G3D'
    assert rows[1]['status'] == 'compile_failed'
    assert rows[1]['error'] == 'compiler failed'


def test_diagnostic_compile_failure_retains_successful_source_results(tmp_path):
    results = tmp_path / 'results.json'
    results.write_text('[]')
    output = '{"results": ' + __import__('json').dumps(str(results)) + '}\n'
    with patch.object(batch.subprocess, 'run', return_value=CompletedProcess([], 1, output, '')):
        assert batch.invoke_checker('run', tmp_path / 'plan.json') == results
        with pytest.raises(RuntimeError):
            batch.invoke_checker('analyze', tmp_path, '--require-proof')


def test_all_failed_sources_produce_report_without_empty_proof_analysis(tmp_path):
    source = tmp_path / 'bad.cpp'
    source.write_text('// native-flags: /O2\ninvalid code')
    plan = tmp_path / 'plan.json'
    plan.write_text(json.dumps({'jobs': [{'source': str(source), 'checks': [
        {'addr': '00401000', 'symbol': '?bad', 'review_only': True}]}]}))
    builds = tmp_path / 'results.json'
    builds.write_text(json.dumps([{'source': str(source), 'status': 'failed', 'error': 'compiler failed'}]))
    identities = tmp_path / 'identities.json'
    identities.write_text('{}')
    manifest = tmp_path / 'review.json'
    with patch.object(sys, 'argv', ['batch', str(plan), str(identities), str(manifest), '--run',
             '--no-discovery', '--no-variants', '--verified-identities', str(tmp_path / 'absent.json')]), \
         patch.object(batch.runner, 'import_evidence', return_value=({}, {})), \
         patch.object(batch, 'invoke_checker', side_effect=[builds]) as invoke:
        batch.main()
    assert invoke.call_count == 1
    report = json.loads((tmp_path / 'review-report.json').read_text())
    assert report['indexed'] == []
    assert report['receipts'] == []
    assert report['diagnostics'][0]['status'] == 'compile_failed'
    assert report['unresolved'][0]['reason'] == 'compiler failed'


def test_identity_context_must_stay_fresh(tmp_path):
    verifier = batch.runner.ROOT / 'roc/native_autopilot_identity.py'
    source = tmp_path / 'source.cpp'
    source.write_text('original')
    proof = tmp_path / 'identity-vtables.json'
    proof.write_text(json.dumps({'verifier_sha256': batch.runner.sha(verifier),
        'inputs': {str(source): batch.runner.sha(source)},
        'identities': [{'address': '00401000', 'symbol': '?foo'}]}))
    plan = {'jobs': [{'checks': [{'addr': '00401000', 'symbol': '?foo', 'identity_evidence': {
        'path': str(proof), 'sha256': batch.runner.sha(proof)}}]}]}
    assert batch.identity_inputs(plan)[str(proof)] == batch.runner.sha(proof)
    source.write_text('changed')
    with pytest.raises(ValueError, match='identity input changed'):
        batch.identity_inputs(plan)
    source.write_text('original')
    plan['jobs'][0]['checks'][0]['symbol'] = '?other'
    with pytest.raises(ValueError, match='identity target'):
        batch.identity_inputs(plan)


def test_binding_map_requires_unchanged_independent_evidence(tmp_path):
    source = tmp_path / 'reviewed-caller.cpp'; source.write_text('verified source')
    identities = tmp_path / 'bindings.json'; identities.write_text('{"?callee":["00401000"]}')
    sidecar = identities.with_suffix('.inputs.json')
    sidecar.write_text(json.dumps({'inputs': {str(source): batch.runner.sha(source)}}))
    pins = batch.binding_inputs(identities)
    assert pins[str(identities)] == batch.runner.sha(identities)
    assert pins[str(sidecar)] == batch.runner.sha(sidecar)
    source.write_text('changed source')
    with pytest.raises(ValueError, match='binding input changed'):
        batch.binding_inputs(identities)
