import json
from pathlib import Path
from unittest.mock import patch

import pytest
from roc import auto_native as auto


def test_unknown_identity_cannot_promote_and_metadata_survives(tmp_path):
    native = tmp_path / 'rebuild/2008-06/native-classes'
    native.mkdir(parents=True)
    source = native / 'Foo.cpp'
    source.touch()
    check = {'addr': '401000', 'symbol': '?foo', 'references': [], 'library': 'G3D'}
    jobs, issues = auto.make_jobs({'jobs': [{'source': str(source), 'checks': [check, check]}]}, {}, tmp_path)
    assert not issues
    assert jobs[0]['checks'] == [dict(check, addr='00401000', review_only=True)]


def test_changed_dependency_retries_only_affected_batch(tmp_path):
    header = tmp_path / 'foo.h'
    header.write_text('old')
    batch = {'state': 'complete', 'dependencies': {str(header): auto.sha(header)}}
    assert auto.retry_reason(batch, 'registry', 'registry') is None
    header.write_text('new')
    assert auto.retry_reason(batch, 'registry', 'registry') == 'inputs_changed'


def test_failed_batch_retries_once_and_identity_change_retries_review():
    assert auto.retry_reason({'state': 'failed', 'attempts': 1}, 'a', 'a') == 'transient_failure'
    assert auto.retry_reason({'state': 'failed', 'attempts': 2}, 'a', 'a') is None
    batch = {'state': 'complete', 'result': {'unresolved': [{'reason': 'identity'}]}}
    assert auto.retry_reason(batch, 'a', 'b') == 'identity_evidence_changed'


def test_pid_reuse_is_not_same_process():
    import psutil
    with patch.object(psutil, 'Process') as process:
        process.return_value.create_time.return_value = 200
        assert auto.alive({'pid': 42, 'created': 100}) is False


def test_plan_only_cannot_replace_active_state(tmp_path):
    (tmp_path / 'state.json').write_text(json.dumps({'state': 'running', 'client': '2008-06', 'limit': None, 'run': 'x'}))
    with pytest.raises(ValueError, match='plan-only'):
        auto.run(plan_only=True, directory=tmp_path)


def test_summary_dedupes_functions_and_keeps_runtime_separate():
    report = {'indexed': ['00401000', '00401000'], 'unresolved': [
        {'address': '00401100', 'reason': 'calls'}, {'address': '00401100', 'reason': 'identity'}],
        'diagnostics': [{'address': '00401100', 'source': 'x.cpp', 'library': 'G3D', 'status': 'exact',
                         'metrics': {'raw_positional_percent': 80.25, 'positional_percent': 100.0}}]}
    state = {'state': 'running', 'run': 'x', 'issues': [], 'integration': {'gated': 0}, 'llm_review': {},
             'batches': [{'state': 'complete', 'result': report}]}
    result = auto.summary(state)
    assert result['indexed'] == 1
    assert result['unresolved'] == 1
    assert result['libraries']['G3D']['functions'] == 1
    assert result['server_credit'] == 'not_requested'
