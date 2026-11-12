import json
from pathlib import Path
import subprocess
import tempfile
import unittest
from unittest.mock import patch

from roc import draft_hourly as hourly, native_drafts, providers


class HourlyDraftTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        patches = [
            ('roc.draft_hourly.subprocess.run', dict(return_value=subprocess.CompletedProcess([], 0, hourly.draft_publish.BRANCH + '\n', ''))),
            ('roc.draft_merger._process', dict(return_value={'bundle_count': 10})),
            ('roc.draft_family_queue.plan', dict(return_value={'stale': False})),
            ('roc.draft_family_queue.work', dict(return_value={'stale': False, 'attempted': 2})),
            ('roc.draft_source_queue.discover', dict(return_value={'count': 1, 'models_used': 0})),
            ('roc.draft_source_queue.work', dict(return_value={'integrated': 1, 'models_used': 0})),
            ('roc.draft_publish.publish', dict(return_value={'state': 'nothing-current-to-publish'})),
            ('roc.draft_report.reconcile', dict(return_value={'bundle_count': 10})),
        ]
        self.mocks = {}
        for name, kwargs in patches:
            item = patch(name, **kwargs)
            self.mocks[name] = item.start()
            self.addCleanup(item.stop)

    def test_runs_fixed_no_model_stages_and_records_terminal_results(self):
        result = hourly.run_once(self.root)
        self.assertEqual(result['state'], 'completed')
        self.assertEqual(result['models_used'], 0)
        self.assertEqual(result['model_attempts_blocked'], 0)
        self.assertEqual([row['name'] for row in result['stages']],
                         ['intake', 'family-plan', 'family-work', 'source-discovery', 'source-work', 'publication', 'dispositions'])
        self.mocks['roc.draft_source_queue.work'].assert_called_once_with(self.root, 3, True)
        self.mocks['roc.draft_publish.publish'].assert_called_once_with(self.root, push=True)
        self.assertEqual(json.loads((self.root/'work/draft-merger/hourly/latest.json').read_text())['state'], 'completed')

    def test_any_accidental_model_call_fails_closed_without_contacting_provider(self):
        with patch('roc.providers.generate') as original:
            self.mocks['roc.draft_source_queue.work'].side_effect = lambda *args: providers.generate('not-allowed')
            result = hourly.run_once(self.root)
            original.assert_not_called()
            self.assertIs(providers.generate, original)
        self.assertEqual(result['state'], 'failed')
        self.assertEqual(result['model_attempts_blocked'], 1)
        self.assertEqual(result['stages'][-1]['state'], 'failed')
        self.mocks['roc.draft_publish.publish'].assert_not_called()

    def test_overlap_stop_switch_and_wrong_branch_do_not_apply_source(self):
        folder = self.root/'work/draft-merger/hourly'
        with native_drafts.lock(folder/'runner.lock'):
            self.assertEqual(hourly.run_once(self.root)['state'], 'busy')
        stop = self.root/'work/draft-merger/STOP_AUTO'
        stop.touch()
        self.assertEqual(hourly.run_once(self.root)['state'], 'disabled')
        stop.unlink()
        self.mocks['roc.draft_hourly.subprocess.run'].return_value.stdout = 'unrelated-branch\n'
        self.assertEqual(hourly.run_once(self.root)['state'], 'failed')
        self.mocks['roc.draft_source_queue.work'].assert_not_called()

    def test_stale_inputs_stop_before_source_and_dry_run_never_publishes(self):
        self.mocks['roc.draft_family_queue.work'].return_value = {'stale': True}
        self.assertEqual(hourly.run_once(self.root)['state'], 'inputs-changed')
        self.mocks['roc.draft_source_queue.work'].assert_not_called()
        self.mocks['roc.draft_family_queue.work'].return_value = {'stale': False}
        result = hourly.run_once(self.root, apply=False, publish=False)
        self.assertEqual(result['state'], 'completed')
        self.mocks['roc.draft_source_queue.work'].assert_called_once_with(self.root, 3, False)
        self.mocks['roc.draft_publish.publish'].assert_not_called()


if __name__ == '__main__':
    unittest.main()
