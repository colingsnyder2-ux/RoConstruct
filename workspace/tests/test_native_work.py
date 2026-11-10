import json
from pathlib import Path
import tempfile
import sys
from unittest.mock import patch

import pytest

from roc import native_work as work


def test_repeated_start_keeps_clock_and_budget_then_persists_outcome():
    with tempfile.TemporaryDirectory() as temporary, patch.object(work, 'LOGS', Path(temporary)):
        with patch.object(work.time, 'time', return_value=100):
            first = work.start('0x500000', 'one hypothesis', 10)
        with patch.object(work.time, 'time', return_value=112):
            resumed = work.start('00500000', 'do not reset clock', 999)
            assert resumed['id'] == first['id'] and resumed['seconds'] == 12
            assert resumed['budget_seconds'] == 10
            assert work.over_budget([{'addr': '500000'}]) == ['00500000']
            done = work.finish('500000', 'blocked', 'missing proven declaration')
        assert done['seconds'] == 12 and done['budget_exceeded']
        assert work.active('500000') is None
        stored = json.loads((Path(temporary) / 'history' / (done['id'] + '.json')).read_text())
        assert stored['note'] == 'missing proven declaration'


def test_exact_outcome_requires_evidence_and_preserves_active_clock_on_error(tmp_path):
    with patch.object(work, 'LOGS', tmp_path):
        work.start('500000', 'body check')
        with pytest.raises(ValueError, match='receipt'):
            work.finish('500000', 'local_exact', 'not enough evidence')
        assert work.active('500000')
        receipt = tmp_path / 'proof.json'
        receipt.write_text('{"scope":"local only"}')
        done = work.finish('500000', 'local_exact', 'local body only', receipt)
        assert done['receipt_sha256']


def test_diagnostic_logs_keep_compile_shared_and_correlate_active_session(tmp_path):
    with patch.object(work, 'LOGS', tmp_path / 'work'):
        session = work.start('500000', 'trial')
        run = tmp_path / 'run-unique'
        run.mkdir()
        job = {'source': 'Foo.cpp', 'checks': [{'addr': '500000', 'symbol': '?foo'},
                                             {'addr': '500010', 'symbol': '?bar'}]}
        result = {'status': 'complete', 'compile_seconds': 8, 'seconds': 9,
                  'checks': [{'addr': '00500000', 'requested_symbol': '?foo', 'status': 'exact',
                              'check_seconds': 0.1, 'data_errors': ['wrong data']}]}
        work.log_checks(run, job, result)
        rows = [json.loads(l) for l in (run / 'function-timings.jsonl').read_text().splitlines()]
        assert rows[0]['status'] == 'data_mismatch'
        assert rows[0]['session'] == session['id']
        assert rows[0]['check_seconds'] == 0.1
        assert rows[1]['check_seconds'] is None
        assert all(r['source_compile_seconds_shared'] == 8 for r in rows)
        assert (work.LOGS / 'trials' / session['id'] / (run.name + '.jsonl')).exists()


def test_shared_header_snapshot_detects_edits_additions_and_removals(tmp_path):
    reflection = tmp_path / 'reflection'
    reflection.mkdir()
    header = reflection / 'property.h'
    header.write_text('before')
    before = work.headers(tmp_path)
    header.write_text('after')
    added = reflection / 'new.h'
    added.write_text('added')
    assert work.changed(before, work.headers(tmp_path)) == sorted([str(header), str(added)])
    header.unlink()
    assert str(header) in work.changed(before, work.headers(tmp_path))


def test_report_totals_multiple_attempts_without_resetting_spent_time(tmp_path, capsys):
    with patch.object(work, 'LOGS', tmp_path):
        for start, end in [(100, 110), (200, 220)]:
            with patch.object(work.time, 'time', return_value=start):
                work.start('500000', 'new evidence')
            with patch.object(work.time, 'time', return_value=end):
                work.finish('500000', 'blocked', 'next required proof')
        with patch.object(sys, 'argv', ['native_work', 'report', '--sort', 'seconds']):
            work.main()
        report = json.loads(capsys.readouterr().out)
        assert report['function_totals'][0]['attempts'] == 2
        assert report['function_totals'][0]['work_seconds'] == 30
