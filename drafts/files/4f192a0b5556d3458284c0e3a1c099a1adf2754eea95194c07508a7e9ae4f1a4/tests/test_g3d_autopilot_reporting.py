import importlib.util
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
