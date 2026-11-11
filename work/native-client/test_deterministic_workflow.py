import json
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import Mock, patch

HERE = Path(__file__).resolve().parent
sys.path[:0] = [str(HERE), str(HERE / 'ogre')]
import deterministic_workflow as workflow
import fix_loop
import analog_to_native


class DeterministicWorkflowTests(unittest.TestCase):
    def test_candidate_addresses_never_receive_recovery_credit(self):
        manifest = {'families': [{'symbols': [
            {'status': 'inactive_exact', 'addr': '00100000', 'candidates': ['00100000', '00200000']},
            {'status': 'draft', 'candidates': ['00300000']},
        ]}]}
        self.assertEqual({'00100000'}, workflow.accepted(manifest))
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            path = root / 'prove-out/prove-Owner/manifest.json'
            path.parent.mkdir(parents=True)
            path.write_text(json.dumps(manifest))
            with patch.object(analog_to_native, 'HERE', root):
                self.assertEqual({'00100000'}, analog_to_native.exact_addrs('Owner.cpp'))

    def test_worker_never_enables_model_ladder(self):
        with patch.object(workflow.fix_loop, 'run_target', return_value='reverted: no rule') as worker:
            workflow.execute({'address': '004ef930'}, 25)
        self.assertFalse(worker.call_args.kwargs['allow_models'])
        self.assertEqual(1500, worker.call_args.kwargs['budget_seconds'])

    def test_repair_tools_are_opt_in_and_do_not_enable_models(self):
        with patch.object(workflow.fix_loop, 'run_target', return_value='reverted: no rule') as worker:
            workflow.execute({'address': '004ef930'}, 5, True)
        self.assertTrue(worker.call_args.kwargs['use_repair_tools'])
        self.assertFalse(worker.call_args.kwargs['allow_models'])

    def test_repair_tool_transaction_logs_draft_and_restores_rejection(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            source = root / 'Owner.cpp'
            source.write_bytes(b'original\r\n')
            def trial(*args):
                source.write_text('// 004ef930: transplanted\nvoid Owner::f() {}\n')
                analog_to_native.prove(source)
                return 'reverted: not exact'
            with patch.object(fix_loop, 'ROOT', root), patch.object(fix_loop, 'HERE', root), \
                 patch.object(analog_to_native, 'transplant_targets',
                    return_value=[('004ef930', 'RBX::Owner', 'Owner', 'f', 'Owner.cpp')]), \
                 patch.object(analog_to_native, 'transplant', side_effect=trial), \
                 patch.object(analog_to_native, 'exact_addrs', return_value=set()), \
                 patch.object(fix_loop, 'compile_errors', return_value=''), \
                 patch.object(fix_loop, 'bounded_run', return_value=subprocess.CompletedProcess([], 0, '', '')), \
                 patch.object(fix_loop.subprocess, 'run', return_value=subprocess.CompletedProcess([], 0)), \
                 patch.object(fix_loop, 'external_diagnostics', return_value={'status': 'draft_only'}) as tools, \
                 patch.object(fix_loop, 'model_body', side_effect=AssertionError('model called')):
                outcome = fix_loop.run_target('004ef930', budget_seconds=60, allow_models=False, use_repair_tools=True)
            self.assertTrue(outcome.startswith('reverted'))
            tools.assert_called_once()
            self.assertEqual(b'original\r\n', source.read_bytes())
            records = [json.loads(line) for line in (root / 'fix-loop.jsonl').read_text().splitlines()]
            self.assertEqual('repair_diagnostics', records[0]['status'])
            self.assertEqual('parked', records[-1]['status'])

    def test_no_model_mode_restores_rejected_trial_without_provider_call(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            source = root / 'Owner.cpp'
            source.write_bytes(b'original\r\n')

            def trial(*args):
                source.write_text('// 004ef930: transplanted\nvoid Owner::f() {}\n')
                analog_to_native.prove(source)
                return 'reverted: not exact'

            with patch.object(fix_loop, 'ROOT', root), patch.object(fix_loop, 'HERE', root), \
                 patch.object(analog_to_native, 'transplant_targets',
                    return_value=[('004ef930', 'RBX::Owner', 'Owner', 'f', 'Owner.cpp')]), \
                 patch.object(analog_to_native, 'transplant', side_effect=trial), \
                 patch.object(analog_to_native, 'exact_addrs', return_value=set()), \
                 patch.object(fix_loop, 'compile_errors', return_value=''), \
                 patch.object(fix_loop, 'bounded_run', return_value=subprocess.CompletedProcess([], 0, '', '')), \
                 patch.object(fix_loop.subprocess, 'run', return_value=subprocess.CompletedProcess([], 0)), \
                 patch.object(fix_loop, 'model_body', side_effect=AssertionError('model called')) as model:
                result = fix_loop.run_target('004ef930', allow_models=False)
            self.assertIn('reverted', result)
            model.assert_not_called()
            self.assertEqual(b'original\r\n', source.read_bytes())

    def test_timeout_stops_windows_proof_tree(self):
        process = Mock(pid=12345)
        process.communicate.side_effect = [subprocess.TimeoutExpired('proof', 1), ('', '')]
        with patch.object(fix_loop.sys, 'platform', 'win32'), \
             patch.object(fix_loop.subprocess, 'Popen', return_value=process), \
             patch.object(fix_loop.subprocess, 'run') as stop:
            with self.assertRaises(subprocess.TimeoutExpired):
                fix_loop.bounded_run(['proof'], 1)
        self.assertEqual(['taskkill', '/PID', '12345', '/T', '/F'], stop.call_args.args[0])

    def test_unchanged_parked_target_not_retried(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            with patch.object(workflow, 'ROOT', root), patch.object(workflow, 'NATIVE', root), \
                 patch.object(workflow.run_all, 'roots', return_value=['004ef930']), \
                 patch.object(workflow.run_all.match, 'target', return_value=(b'abcd',)), \
                 patch.object(workflow.fix_loop.transplant, 'transplant_targets',
                    return_value=[('004ef930', 'RBX::Owner', 'Owner', 'f', 'Owner.cpp')]), \
                 patch.object(workflow, 'fingerprint', return_value='same'):
                state = {'targets': {'004ef930': {'status': 'parked', 'fingerprint': 'same'}}}
                self.assertEqual([], workflow.queue({'families': []}, state))
                self.assertEqual(1, len(workflow.queue({'families': []}, state, retry=True)))

    def test_existing_parked_evidence_not_retried_by_default(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / 'CLAUDE_HANDOFF.md').write_text('PARKED 004ef930: missing layout')
            with patch.object(workflow, 'ROOT', root), patch.object(workflow, 'NATIVE', root), \
                 patch.object(workflow.run_all, 'roots', return_value=['004ef930']), \
                 patch.object(workflow.run_all.match, 'target', return_value=(b'abcd',)), \
                 patch.object(workflow.fix_loop.transplant, 'transplant_targets', return_value=[]):
                result = workflow.queue({'families': []}, {})
            self.assertEqual('parked_evidence', result[0]['status'])

    def test_os_lock_releases_without_deleting_lock_file(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / 'lock'
            first = workflow.acquire_lock(path)
            first.close()
            second = workflow.acquire_lock(path)
            second.close()
            self.assertTrue(path.exists())

    def test_commit_refuses_to_include_preexisting_user_edits(self):
        import hashlib
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            path = root / 'rebuild/2008-06/Owner.cpp'
            path.parent.mkdir(parents=True)
            path.write_bytes(b'proved')
            receipt = {'sha256': {'rebuild/2008-06/Owner.cpp': hashlib.sha256(b'proved').hexdigest()},
                       'original_sha256': {'rebuild/2008-06/Owner.cpp': hashlib.sha256(b'user edit').hexdigest()}}
            with patch.object(workflow, 'ROOT', root), patch.object(workflow, 'require_branch'), \
                 patch.object(workflow.subprocess, 'run', side_effect=[
                    subprocess.CompletedProcess([], 0, '', ''),
                    subprocess.CompletedProcess([], 0, b'HEAD version', b'')]):
                with self.assertRaisesRegex(RuntimeError, 'pre-existing edits'):
                    workflow.commit_survivors([receipt])

    def test_batch_persists_parked_result_and_resume_runs_no_worker(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            manifest = root / 'manifest.json'
            manifest.write_text('{"families":[]}')
            state = root / 'state/state.json'
            target = {'address': '004ef930', 'status': 'ready', 'destination': 'Owner.cpp',
                      'fingerprint': 'same'}
            argv = ['workflow', '--manifest', str(manifest), '--state', str(state), '--run']
            with patch.object(workflow, 'ROOT', root), patch.object(workflow, 'NATIVE', root), \
                 patch.object(workflow, 'require_branch'), \
                 patch.object(workflow.sys, 'argv', argv), \
                 patch.object(workflow, 'active_proofs', return_value=[]), \
                 patch.object(workflow, 'fingerprint', return_value='same'), \
                 patch.object(workflow, 'queue', side_effect=[[target], []]), \
                 patch.object(workflow, 'execute', return_value='reverted: missing API') as worker:
                workflow.main()
                workflow.main()
            self.assertEqual(1, worker.call_count)
            self.assertEqual('parked', json.loads(state.read_text())['targets']['004ef930']['status'])
            self.assertEqual(1, len((state.parent / 'events.jsonl').read_text().splitlines()))

    def test_commit_compares_filtered_checkout_bytes(self):
        import hashlib
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            name = 'rebuild/2008-06/Owner.cpp'
            path = root / name
            path.parent.mkdir(parents=True)
            path.write_bytes(b'proved\r\n')
            receipt = {'sha256': {name: hashlib.sha256(b'proved\r\n').hexdigest()},
                       'original_sha256': {name: hashlib.sha256(b'original\r\n').hexdigest()}}
            with patch.object(workflow, 'ROOT', root), patch.object(workflow, 'require_branch'), \
                 patch.object(workflow.subprocess, 'run', side_effect=[
                    subprocess.CompletedProcess([], 0, '', ''),
                    subprocess.CompletedProcess([], 0, b'original\r\n', b''),
                    subprocess.CompletedProcess([], 0)]) as git:
                workflow.commit_survivors([receipt])
            self.assertEqual(['git', 'cat-file', '--filters', 'HEAD:' + name], git.call_args_list[1].args[0])


if __name__ == '__main__':
    unittest.main()
