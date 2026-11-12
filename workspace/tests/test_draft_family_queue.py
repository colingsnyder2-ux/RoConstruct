import json
from contextlib import closing
from pathlib import Path
import sqlite3
import tempfile
import unittest
from unittest.mock import patch

from roc import draft_family_queue as queue, native_drafts


class FamilyQueueTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.identity = dict(native_input_key='a' * 64, gates={})
        self.patch = patch('roc.draft_family_queue.identity', side_effect=lambda root: self.identity.copy())
        self.patch.start()
        self.addCleanup(self.patch.stop)
        self.inbox = native_drafts.Inbox(self.root)

    def bundle(self, path, text='int new_method;', user='review-test'):
        packet = dict(schema=1, user=user, model='test', session='a' * 32, baseline='test', parent=None,
                      status='draft', exact_credits=0, created=1, files={path: dict(base=None, text=text)})
        identifier = native_drafts.digest(packet)
        with self.inbox.connect() as db:
            db.execute('INSERT INTO bundles(id,user,packet,received) VALUES(?,?,?,?)',
                       (identifier, user, native_drafts.encoded(packet).decode(), 1))
        return identifier

    def prepare(self, root, bundle, companions=()):
        output = root / 'work/draft-merger/families' / bundle
        output.mkdir(parents=True, exist_ok=True)
        result = dict(bundle_id=bundle, companion_bundles=list(companions), output=str(output))
        native_drafts.atomic(output / 'manifest.json', result)
        return result

    def states(self):
        with closing(sqlite3.connect(self.root / 'work/draft-merger/state.sqlite3')) as db:
            return db.execute('SELECT bundle,state,attempts FROM family_jobs ORDER BY seq').fetchall()

    def test_work_can_prioritize_one_uploader(self):
        other = self.bundle('rebuild/2008-06/native-classes/Newer.cpp', user='other')
        wanted = self.bundle('rebuild/2008-06/native-classes/Wanted.cpp', user='coldek')
        self.bundle('rebuild/2008-06/native-classes/Newest.cpp', user='other')
        queue.plan(self.root)
        with patch('roc.draft_family.prepare', side_effect=self.prepare), \
                patch('roc.draft_family.measure', return_value=dict(state='measured-unverified', summary={}, blockers=[])):
            result = queue.work(self.root, 2, users=['COLDEK'])
        self.assertEqual([row['bundle'] for row in result['results']], [wanted])
        self.assertNotEqual(other, wanted)

    def test_following_json_evidence_is_attached_as_companion(self):
        source = self.bundle('rebuild/2008-06/native-classes/Proofed.cpp', user='coldek')
        evidence = self.bundle('work/2008-06/shared-layouts/proof.json', '{"address":"00401000"}', user='coldek')
        queue.plan(self.root)
        with closing(sqlite3.connect(self.root / 'work/draft-merger/state.sqlite3')) as db:
            detail = json.loads(db.execute('SELECT detail FROM family_jobs WHERE bundle=?', (source,)).fetchone()[0])
        self.assertEqual(detail['companions'], [evidence])
        with patch('roc.draft_family.prepare', side_effect=self.prepare) as prepare, \
                patch('roc.draft_family.measure', return_value=dict(state='measured-unverified', summary={}, blockers=[])):
            queue.work(self.root, 1, users=['coldek'])
        self.assertEqual(prepare.call_args.kwargs['companions'], [evidence])

    def test_every_bundle_planned_non_native_explicit_and_newest_first(self):
        old = self.bundle('rebuild/2008-06/native-classes/Old.cpp')
        self.bundle('docs/evidence.md', 'unverified narrative')
        new = self.bundle('rebuild/2008-06/native-classes/New.cpp')
        result = queue.plan(self.root)
        self.assertEqual(result['bundle_count'], 3)
        self.assertEqual(result['states'], {'non-native-review': 1, 'queued': 2})
        with patch('roc.draft_family.prepare', side_effect=self.prepare) as prepare, \
                patch('roc.draft_family.measure', return_value=dict(state='measured-unverified', summary={}, blockers=[])):
            first = queue.work(self.root, 1)
            queue.plan(self.root)  # Replanning must not erase completed work.
            second = queue.work(self.root, 1)
        self.assertEqual([row['bundle'] for row in first['results'] + second['results']], [new, old])
        self.assertEqual(first['accepted'], 0)
        self.assertEqual(prepare.call_count, 2)

    def test_fixed_profiles_and_header_only_blocker(self):
        self.bundle('rebuild/2008-06/native-classes/Profile.cpp',
                    '// native-flags: /fp:fast /I{headers}/partchunk-profile\nint x;')
        self.bundle('rebuild/2008-06/native-headers/Only.h', 'class Only {};')
        self.assertEqual(queue.plan(self.root)['states']['queued'], 3)
        with closing(sqlite3.connect(self.root / 'work/draft-merger/state.sqlite3')) as db:
            row = db.execute("SELECT detail FROM family_jobs WHERE profile='default' ORDER BY seq DESC LIMIT 1").fetchone()
        self.assertIn('Header-only', json.loads(row[0])['blocker'])

    def test_failure_retries_resume_private_output_and_stop_after_three(self):
        bundle = self.bundle('rebuild/2008-06/native-classes/Retry.cpp')
        queue.plan(self.root)
        with patch('roc.draft_family.prepare', side_effect=self.prepare) as prepare, \
                patch('roc.draft_family.measure', side_effect=RuntimeError('compiler unavailable')):
            for _ in range(3):
                queue.work(self.root, 1)
            self.assertEqual(queue.work(self.root, 1)['attempted'], 0)
        self.assertEqual(prepare.call_count, 1)
        self.assertEqual(self.states(), [(bundle, 'needs-tool-repair', 3)])

    def test_input_changes_invalidate_results_and_cannot_reuse_plan(self):
        self.bundle('rebuild/2008-06/native-classes/Stale.cpp')
        queue.plan(self.root)

        def measure(*args):
            self.identity = dict(native_input_key='b' * 64, gates={})
            return dict(state='measured-unverified', summary={}, blockers=[])

        with patch('roc.draft_family.prepare', side_effect=self.prepare), patch('roc.draft_family.measure', side_effect=measure):
            result = queue.work(self.root, 1)
        self.assertTrue(result['stale'])
        self.assertEqual(self.states()[0][1], 'stale')
        with self.assertRaisesRegex(ValueError, 'fresh plan'):
            queue.work(self.root)
        self.assertFalse(queue.plan(self.root)['stale'])
        self.assertEqual(queue.summary(self.root)['states'], {'queued': 1})

    def test_live_worker_lock_is_never_stolen(self):
        self.bundle('rebuild/2008-06/native-classes/Locked.cpp')
        queue.plan(self.root)
        with native_drafts.lock(self.root / 'work/draft-integration.lock'):
            with self.assertRaisesRegex(RuntimeError, 'Already running'):
                queue.work(self.root)


if __name__ == '__main__':
    unittest.main()
