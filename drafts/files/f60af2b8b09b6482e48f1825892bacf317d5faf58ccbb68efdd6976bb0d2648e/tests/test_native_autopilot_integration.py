import importlib.util
import json
from pathlib import Path
from unittest.mock import patch

import pytest

path = Path(__file__).resolve().parents[1] / 'rebuild/2008-06/tests/native_autopilot_integration.py'
spec = importlib.util.spec_from_file_location('autopilot_integration_test', path)
adapter = importlib.util.module_from_spec(spec)
spec.loader.exec_module(adapter)


def test_empty_candidate_set_never_selects_runtime(tmp_path):
    result = adapter.integrate(tmp_path, [], tmp_path / 'out')
    assert result['selected'] == result['attempted'] == result['gated'] == 0
    assert result['runtime'] == 'not_run'


def test_missing_gate_rejects_even_if_other_checks_pass(tmp_path):
    folder = tmp_path / 'rebuild/2008-06/manifests'
    folder.mkdir(parents=True)
    plan = folder / 'plan.json'
    body = {'schema': 1, 'reviewed_by': 'owner', 'autopilot_targets': ['00401000'], 'inputs': {'source.cpp': 'hash'}, 'stages': [
        {'name': 'checks', 'kind': 'check', 'argv': ['python', 'check.py'],
         'assertions': [{'file': 'proof.json', 'key': 'passed', 'equals': True}], 'gates': sorted(adapter.GATES - {'runtime'})},
        {'name': 'select', 'kind': 'integrate', 'argv': ['python', 'select.py']}]}
    plan.write_text(json.dumps(body))
    entry = {'path': plan.relative_to(tmp_path).as_posix(), 'sha256': adapter.sha(plan), 'addresses': ['00401000']}
    with pytest.raises(ValueError, match='runtime'):
        adapter.reviewed_plan(tmp_path, entry, {'00401000'})
    body['stages'][0]['gates'].append('runtime')
    plan.write_text(json.dumps(body)); entry['sha256'] = adapter.sha(plan)
    assert adapter.reviewed_plan(tmp_path, entry, {'00401000'}) == plan
    plan.write_text('{}')
    with pytest.raises(ValueError, match='changed'):
        adapter.reviewed_plan(tmp_path, entry, {'00401000'})


def test_byte_receipt_without_reference_proof_never_queues(tmp_path):
    source = tmp_path / 'rebuild/2008-06/native-classes/Foo.cpp'
    source.parent.mkdir(parents=True); source.write_text('int foo(){return 1;}')
    receipt = tmp_path / 'work/2008-06/shared-layouts/proof.json'
    receipt.parent.mkdir(parents=True)
    receipt.write_text(json.dumps({'source_path': str(source), 'source_sha256': adapter.sha(source), 'checks': [
        {'address': '00401000', 'exact': True, 'metrics': {'unmasked_differences': 0, 'length_delta': 0}}]}))
    with patch.object(adapter.native_pipeline, 'run') as pipeline:
        result = adapter.integrate(tmp_path, [{'receipt': str(receipt), 'sha256': adapter.sha(receipt),
            'addresses': ['00401000']}], tmp_path / 'out')
        assert result['gated'] == 0
        assert result['issues']
        pipeline.assert_not_called()
