import json
import hashlib
from pathlib import Path
import subprocess
import tempfile
import unittest
from unittest.mock import patch
from types import SimpleNamespace

from roc import mew_import


class MewImportTests(unittest.TestCase):
    def test_fetch_donor_defaults_to_active_native_branch_and_pins_selected_ref(self):
        self.assertEqual(mew_import.DEFAULT_BRANCH, 'claude/optimistic-shannon-0xccuy')
        with patch('roc.mew_import.subprocess.run', return_value=SimpleNamespace(returncode=0)), \
                patch('roc.mew_import.git') as git:
            mew_import.fetch_donor(Path('repo'), 'main')
        git.assert_called_once_with(
            Path('repo'), 'fetch', 'https://github.com/mewpokemons/RoConstruct.git',
            '+refs/heads/main:refs/remotes/mew-review/selected')

    def test_fetch_donor_rejects_invalid_branch_before_fetch(self):
        with patch('roc.mew_import.subprocess.run', return_value=SimpleNamespace(returncode=1)), \
                patch('roc.mew_import.git') as git:
            with self.assertRaisesRegex(ValueError, 'Invalid Mew branch'):
                mew_import.fetch_donor(Path('repo'), '../main:evil')
        git.assert_not_called()

    def test_failed_batch_does_not_stop_next_batch(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            responses = [SimpleNamespace(returncode=1, stdout='failure', stderr='error'),
                         SimpleNamespace(returncode=0, stdout='{"run": "second"}\n', stderr='')]
            with patch('roc.mew_import.subprocess.run', side_effect=responses) as run:
                result = mew_import.check_batches(root, root, ['first', 'second'], 2)
            self.assertEqual(run.call_count, 2)
            self.assertEqual([x['exit_code'] for x in result], [1, 0])
            self.assertEqual(result[1]['summary']['run'], 'second')
            self.assertTrue((root / 'checks.json').is_file())

    def test_receipt_groups_ignore_pending_and_unmapped(self):
        receipt = {'flags': {'good': ['/fp:fast', '/tmp/Foo.cpp'], 'bad': ['/tmp/X.cpp', '/tmp/Y.cpp']},
                   'rows': {'good': [{'exact': True, 'address': '005a01e0', 'symbol': '?a'},
                                     {'exact': False, 'address': '005a01e1', 'symbol': '?b'}],
                            'bad': [{'exact': True, 'address': '005a01e2', 'symbol': '?c'}]}}
        self.assertEqual(mew_import.receipt_groups(receipt),
                         [('foo.cpp', 'good', [{'addr': '005a01e0', 'symbol': '?a'}], True, False, False)])

    def test_receipt_groups_support_flat_rows_with_unit(self):
        receipt = {
            'flags': {'templates': ['/tmp/AppUnit404Templates.cpp']},
            'rows': [
                {'unit': 'templates', 'exact': True, 'address': '00405da0', 'symbol': '?getCreators'},
                {'unit': 'templates', 'exact': True, 'address': '00405dbe',
                 'symbol': '__catch$?getCreators$0'},
                {'unit': 'templates', 'exact': False, 'address': '00405e30', 'symbol': '?partial'},
            ],
        }
        self.assertEqual(mew_import.receipt_groups(receipt), [
            ('appunit404templates.cpp', 'templates',
             [{'addr': '00405da0', 'symbol': '?getCreators'}], False, False, False)
        ])

    def test_pinned_ogre_profile_detected_without_trusting_external_path(self):
        receipt = {'flags': {'g': ['/I/home/user/roconstruct/tools/libs/ogre-1.4.5/ogrenew/OgreMain/include',
                                   '/tmp/Foo.cpp']},
                   'rows': {'g': [{'exact': True, 'address': '005a01e0', 'symbol': '?a'}]}}
        self.assertTrue(mew_import.receipt_groups(receipt)[0][-1])

    def test_inventory_deduplicates_and_does_not_overwrite(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            def git(*args):
                subprocess.run(['git', *args], cwd=root, check=True, capture_output=True)
            git('init')
            git('config', 'user.email', 'local@example.invalid')
            git('config', 'user.name', 'Local Test')
            def put(name, data):
                p = root / name
                p.parent.mkdir(parents=True, exist_ok=True)
                p.write_text(data, encoding='utf-8')
            put('workspace/rebuild/2008-06/native-classes/Same.cpp', 'same')
            put('workspace/rebuild/2008-06/native-classes/Conflict.cpp', 'old')
            git('add', '.')
            git('commit', '-m', 'work')
            git('branch', 'work-test')
            put('rebuild/2008-06/native-classes/Same.cpp', 'same')
            put('rebuild/2008-06/native-classes/Conflict.cpp', 'new')
            put('rebuild/2008-06/native-classes/New.cpp', 'int new_body() { return 1; }')
            receipt = {'sources': {'new': hashlib.sha256(b'int new_body() { return 1; }').hexdigest()},
                       'flags': {'new': ['/fp:fast', '/tmp/New.cpp']},
                       'rows': {'new': [{'exact': True, 'address': '005a01e0', 'symbol': '?new_body'}]}}
            put('work/2008-06/shared-layouts/test-working.json', json.dumps(receipt))
            git('add', '.')
            git('commit', '-m', 'donor')
            out = root / 'out'
            report = mew_import.prepare(root, out, donor='HEAD', work='work-test')
            states = {Path(x['path']).name: x['state'] for x in report['files']}
            self.assertEqual(states, {'Conflict.cpp': 'same_name_differs', 'New.cpp': 'candidate_unreviewed',
                                      'Same.cpp': 'identical_blob'})
            batch = json.loads(Path(report['manifests'][0]).read_text())
            self.assertEqual(len(batch['jobs'][0]['checks']), 1)
            self.assertEqual((root / 'workspace/rebuild/2008-06/native-classes/Conflict.cpp').read_text(), 'old')
            with self.assertRaises(FileExistsError):
                mew_import.prepare(root, out, donor='HEAD', work='work-test')


if __name__ == '__main__':
    unittest.main()
