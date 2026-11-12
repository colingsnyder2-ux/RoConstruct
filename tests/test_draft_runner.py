import json
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import call, patch

from roc.draft_merger import run_pipeline


class DraftRunnerTests(unittest.TestCase):
    def test_publication_requires_apply_and_preserves_blocker(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            with self.assertRaisesRegex(ValueError, 'explicit source application'):
                run_pipeline(root, publish=True)
            with patch('roc.draft_merger.process', return_value={'run': 'publish-run'}), \
                    patch('roc.draft_merger.subprocess.run'), \
                    patch('roc.draft_report.reconcile', return_value={}), \
                    patch('roc.draft_getter_queue.discover'), \
                    patch('roc.draft_getter_queue.work', return_value={}), \
                    patch('roc.draft_publish.publish', return_value={'state': 'blocked', 'error': 'inputs changed'}) as publish:
                run_pipeline(root, review_limit=0, apply=True, publish=True)
            publish.assert_called_once_with(root.resolve(), push=True)
            status = json.loads((root / 'work/draft-merger/pipeline-status.json').read_text())
            self.assertEqual(status['publication']['error'], 'inputs changed')
            self.assertEqual(status['stages'][-1]['state'], 'blocked')

    def test_runs_fixed_local_stages_in_order_and_stops_pending_acceptance(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            report = root / 'final-report.json'
            intake = {'run': 'run-7', 'untrusted_command': 'do-not-run-this'}
            reconciled = {'run': 'run-7', 'eligible_for_integration': False}
            with patch('roc.draft_merger.process', return_value=intake) as process, \
                    patch('roc.draft_merger.subprocess.run') as run, \
                    patch('roc.draft_report.reconcile', return_value=reconciled) as reconcile, \
                    patch('roc.draft_review.prepare') as prepare_review, \
                    patch('roc.draft_review.work', return_value={'attempted': 3, 'proposals': 0}) as work_review, \
                    patch('roc.draft_getter_queue.discover') as discover_getters, \
                    patch('roc.draft_getter_queue.work', return_value=[]) as work_getters:
                result = run_pipeline(root, report, record_reviews=True)

            self.assertEqual(result, reconciled)
            process.assert_called_once_with(root.resolve(), record_reviews=True, native_inputs=True)
            self.assertEqual(reconcile.call_args_list, [
                call(root.resolve(), report, True),
                call(root.resolve(), report, True),
            ])
            prepare_review.assert_called_once_with(root.resolve())
            work_review.assert_called_once_with(root.resolve(), 'codex:gpt-6-luna', 3)
            discover_getters.assert_called_once_with(root.resolve())
            work_getters.assert_called_once_with(root.resolve(), False)
            self.assertEqual([entry.args[0] for entry in run.call_args_list], [
                [sys.executable, '-m', 'roc.draft_methods', 'build', '--root', str(root.resolve())],
                [sys.executable, '-m', 'roc.draft_methods', 'inspect', '--root', str(root.resolve())],
                [sys.executable, '-m', 'roc.draft_native', '--root', str(root.resolve())],
            ])
            for entry in run.call_args_list:
                argv = entry.args[0]
                self.assertEqual(argv[0:2], [sys.executable, '-m'])
                self.assertEqual(entry.kwargs, {'cwd': root.resolve(), 'check': True})
                self.assertNotIn('do-not-run-this', argv)

            status = json.loads((root / 'work/draft-merger/pipeline-status.json').read_text())
            self.assertEqual(status['state'], 'processed-pending-acceptance')
            self.assertEqual([stage['name'] for stage in status['stages']], [
                'intake', 'roc.draft_methods:build', 'roc.draft_methods:inspect',
                'roc.draft_native:measure', 'llm-review'])
            self.assertTrue(all(stage['state'] == 'done' for stage in status['stages']))
            self.assertIn('acceptance', status['pending'])
            self.assertNotIn('source integration complete', status['pending'].lower())

    def test_review_proposals_trigger_fixed_native_review_stage_then_getters(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            reconciled = {'run': 'run-review'}
            with patch('roc.draft_merger.process', return_value={'run': 'run-review'}), \
                    patch('roc.draft_merger.subprocess.run') as run, \
                    patch('roc.draft_report.reconcile', return_value=reconciled) as reconcile, \
                    patch('roc.draft_review.prepare') as prepare_review, \
                    patch('roc.draft_review.work', return_value={'attempted': 2, 'proposals': 1}) as work_review, \
                    patch('roc.draft_getter_queue.discover') as discover_getters, \
                    patch('roc.draft_getter_queue.work', return_value=['getter-result']) as work_getters:
                result = run_pipeline(root, review_limit=2, apply=True)

            self.assertEqual(result, reconciled)
            prepare_review.assert_called_once_with(root.resolve())
            work_review.assert_called_once_with(root.resolve(), 'codex:gpt-6-luna', 2)
            discover_getters.assert_called_once_with(root.resolve())
            work_getters.assert_called_once_with(root.resolve(), True)
            self.assertEqual(run.call_args_list[-1].args[0], [
                sys.executable, '-m', 'roc.draft_native', '--reviews-only', '--root', str(root.resolve())])
            self.assertEqual(run.call_args_list[-1].kwargs, {'cwd': root.resolve(), 'check': True})
            self.assertEqual(reconcile.call_count, 2)
            status = json.loads((root / 'work/draft-merger/pipeline-status.json').read_text())
            self.assertEqual(status['getter_results'], ['getter-result'])
            self.assertEqual(status['state'], 'processed-pending-acceptance')

    def test_stage_failure_records_failed_status_and_skips_later_stages(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            failure = subprocess.CalledProcessError(2, ['python', '-m', 'roc.draft_methods', 'build'])
            with patch('roc.draft_merger.process', return_value={'run': 'run-fail'}) as process, \
                    patch('roc.draft_merger.subprocess.run', side_effect=failure) as run, \
                    patch('roc.draft_report.reconcile') as reconcile:
                with self.assertRaises(subprocess.CalledProcessError):
                    run_pipeline(root)

            process.assert_called_once()
            run.assert_called_once()
            reconcile.assert_not_called()
            status = json.loads((root / 'work/draft-merger/pipeline-status.json').read_text())
            self.assertEqual(status['state'], 'failed')
            self.assertEqual(status['stages'][-1], {'name': 'roc.draft_methods:build', 'state': 'running'})
            self.assertTrue(status['error'])


if __name__ == '__main__':
    unittest.main()
