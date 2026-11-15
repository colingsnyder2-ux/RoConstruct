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


def test_reviewed_symbol_does_not_authorize_another_source(tmp_path):
    native = tmp_path / 'rebuild/2008-06/native-classes'
    native.mkdir(parents=True)
    source = native / 'DifferentOwner.cpp'; source.touch()
    check = {'addr': '00401000', 'symbol': '?foo'}
    identities = {(str(native / 'Reviewed.cpp').casefold(), '00401000', '?foo')}
    jobs, _ = auto.make_jobs({'jobs': [{'source': str(source), 'checks': [check]}]}, identities, tmp_path)
    assert jobs[0]['checks'][0]['review_only'] is True
    identities.add((str(source).casefold(), '00401000', '?foo'))
    jobs, _ = auto.make_jobs({'jobs': [{'source': str(source), 'checks': [check]}]}, identities, tmp_path)
    assert jobs[0]['checks'][0]['review_only'] is False


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


def test_resume_adopts_completed_worker_without_duplicate_compile(tmp_path):
    manifest = tmp_path / 'plan-0000.json'
    report = auto.report_path(manifest)
    report.write_text(json.dumps({'indexed': [], 'unresolved': [], 'diagnostics': []}))
    batch = {'state': 'running', 'manifest': str(manifest), 'source_hashes': {}, 'process': {'pid': 1, 'created': 2}}
    state = {'run': str(tmp_path), 'batches': [batch]}
    with patch.object(auto, 'alive', side_effect=[True, False]), patch.object(auto.time, 'sleep'), \
         patch.object(auto.subprocess, 'Popen') as launch:
        auto.run_batch(state, batch, tmp_path / 'state.json')
    launch.assert_not_called()
    assert batch['state'] == 'complete'


def test_resume_never_duplicates_worker_when_liveness_becomes_unknown(tmp_path):
    batch = {'state': 'running', 'manifest': str(tmp_path / 'plan-0000.json'), 'process': {'pid': 1, 'created': 2}}
    with patch.object(auto, 'alive', side_effect=[True, None]), patch.object(auto.time, 'sleep'), \
         patch.object(auto.subprocess, 'Popen') as launch:
        with pytest.raises(RuntimeError, match='unknown'):
            auto.run_batch({'run': str(tmp_path), 'batches': [batch]}, batch, tmp_path / 'state.json')
    launch.assert_not_called()


def test_stale_source_cannot_compile_or_promote(tmp_path):
    source = tmp_path / 'source.cpp'; source.write_text('changed')
    batch = {'state': 'pending', 'manifest': str(tmp_path / 'plan.json'), 'source_hashes': {str(source): 'old'}}
    with patch.object(auto.subprocess, 'Popen') as launch:
        auto.run_batch({'run': str(tmp_path), 'batches': [batch]}, batch, tmp_path / 'state.json')
    launch.assert_not_called()
    assert batch['state'] == 'stale'


def test_new_header_that_shadows_existing_include_triggers_retry(tmp_path):
    source = tmp_path / 'source.cpp'; source.touch()
    headers = tmp_path / 'headers'; headers.mkdir()
    outputs = tmp_path / 'output'; outputs.mkdir()
    checker = auto.load_module('autopilot_include_test', auto.TESTS / 'native_check_runner.py')
    snapshot = checker.include_search_snapshot(source, ['/I' + str(headers)], outputs, {})
    build = {'object': str(outputs / 'candidate.obj'), 'include_search_snapshot': snapshot}
    assert auto.search_changed([build], {}) is False
    (headers / 'new_header.h').write_text('// can shadow a fallback')
    assert auto.search_changed([build], {}) is True


def test_lease_inventory_marks_cached_data_and_missing_server():
    from roc import leases
    with patch.object(leases, 'fetch', return_value=([{'name': 'other worker'}], True)):
        result = auto.lease_inventory()
    assert result['cached'] is True
    assert result['leases'][0]['name'] == 'other worker'
    with patch.object(leases, 'fetch', side_effect=SystemExit('not configured')):
        result = auto.lease_inventory()
    assert result['state'] == 'unavailable'


def test_finished_worker_cannot_promote_stale_identity_context(tmp_path):
    context = tmp_path / 'identity.json'; context.write_text('changed')
    report = tmp_path / 'report.json'
    report.write_text(json.dumps({'indexed': ['00401000'], 'unresolved': []}))
    batch = {'source_hashes': {}, 'identity_inputs': {str(context): 'old'}}
    auto.finish_batch(batch, report)
    assert batch['state'] == 'stale'
    assert not batch.get('result')


def test_retry_never_adopts_report_left_by_previous_attempt(tmp_path):
    import os
    manifest = tmp_path / 'plan-0000.json'
    report = auto.report_path(manifest)
    old = json.dumps({'indexed': ['00401000'], 'unresolved': []})
    report.write_text(old)
    batch = {'state': 'failed', 'manifest': str(manifest), 'source_hashes': {}}
    state = {'run': str(tmp_path), 'batches': [batch], 'original_sha256': auto.sha(auto.ORIGINAL),
             'runner_sha256': auto.sha(auto.RUNNER)}
    with patch.object(auto.subprocess, 'Popen') as launch:
        launch.return_value.pid = os.getpid()
        launch.return_value.wait.return_value = 1
        auto.run_batch(state, batch, tmp_path / 'state.json')
    assert batch['state'] == 'failed'
    assert not report.exists()
    assert any(path.read_text() == old for path in tmp_path.glob('*previous*'))
