import json
from pathlib import Path
import sqlite3
import tempfile
import unittest
from contextlib import closing

from roc.draft_merger import SCHEMA
from roc.draft_report import reconcile


class DraftReportTests(unittest.TestCase):
    def test_preserving_append_keeps_older_accepted_method_current(self):
        from roc.draft_merger import content_hash
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            path = 'rebuild/2008-06/native-classes/Foo.cpp'
            _, folder = self.make_fixture(root, [(path, 'a' * 64)])
            target = root / path
            target.parent.mkdir(parents=True)
            old = b'old implementation\n'
            after = old + b'new implementation\n'
            target.write_bytes(after)
            with closing(sqlite3.connect(folder / 'state.sqlite3')) as db, db:
                for identifier, before, added, before_sha, after_sha, checks in [
                    ('old', [], ['old-method'], '0' * 64, content_hash(old), {}),
                    ('new', ['old-method'], ['old-method', 'new-method'], content_hash(old), content_hash(after),
                     dict(existing_code_preserved=True, existing_data_preserved=True))]:
                    receipt = dict(path=path, before_methods=before, after_methods=added, checks=checks)
                    db.execute('INSERT INTO proofs VALUES(?,?,?,?,?,?)',
                               (identifier, 'key', 'reviewed-inactive-methods-v1', after_sha, json.dumps(receipt), 1))
                    db.execute('INSERT INTO actions VALUES(?,?,?,?,?,?,?,?)',
                               (identifier, 'run-current', 'bundle-0', path, before_sha, after_sha,
                                'applied-inactive', json.dumps(dict(proof=identifier))))
            self.assertEqual(reconcile(root)['accepted_methods'], 2)
            target.write_bytes(b'external replacement')
            self.assertEqual(reconcile(root)['accepted_methods'], 0)

    def make_fixture(self, root, files, methods=None, native=None):
        folder = root / 'work/draft-merger'
        folder.mkdir(parents=True)
        run = 'run-current'
        intake = {
            'summary': {'run': run, 'input_key': 'key-current', 'stale': False},
            'bundles': [
                {'id': f'bundle-{index}', 'state': 'proof-or-review-required',
                 'files': [{'path': path, 'candidate_sha256': sha, 'state': 'base-applies',
                            'blockers': ['Need independent proof']}]}
                for index, (path, sha) in enumerate(files)
            ],
        }
        (folder / 'latest.json').write_text(json.dumps(intake))
        with closing(sqlite3.connect(folder / 'state.sqlite3')) as db:
            db.executescript(SCHEMA)
        if methods is not None:
            (folder / 'method-decisions.json').write_text(json.dumps(methods))
        if native is not None:
            (folder / 'native-latest.json').write_text(json.dumps(native))
        return run, folder

    def test_reference_verified_candidate_ranks_above_code_only_and_stays_ineligible(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            files = [('rebuild/2008-06/native-classes/A.cpp', 'a' * 64),
                     ('rebuild/2008-06/native-classes/B.cpp', 'b' * 64)]
            run, _ = self.make_fixture(root, files, native={
                'summary': {'run': 'run-current', 'stale': False},
                'units': [
                    {'path': files[0][0], 'candidate_sha256': files[0][1], 'blockers': [], 'methods': [
                        {'symbol': 'Foo::bar', 'address': '0x1000', 'exact_code': False,
                         'references_verified': True, 'score': 0.1}]},
                    {'path': files[1][0], 'candidate_sha256': files[1][1], 'blockers': [], 'methods': [
                        {'symbol': 'Foo::bar', 'address': '0x1000', 'exact_code': True,
                         'references_verified': False, 'score': 1.0}]},
                ],
            })
            report_path = root / 'report.json'
            result = reconcile(root, report_path)
            report = json.loads(report_path.read_text())
            candidates = report['competing_methods'][0]['candidates']
            self.assertTrue(candidates[0]['references_verified'])
            self.assertEqual(candidates[0]['path'], files[0][0])
            self.assertFalse(report['competing_methods'][0]['eligible_for_integration'])
            self.assertEqual(result['run'], run)

    def test_stale_measurements_never_become_integration_eligible(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            path, sha = 'rebuild/2008-06/native-classes/Foo.cpp', 'c' * 64
            _, _ = self.make_fixture(root, [(path, sha)], native={
                'summary': {'run': 'old-run', 'stale': True},
                'units': [{'path': path, 'candidate_sha256': sha, 'blockers': [], 'methods': [
                    {'symbol': 'Foo::bar', 'address': '0x1000', 'exact_code': True,
                     'references_verified': True, 'score': 1.0}]}],
            })
            report_path = root / 'report.json'
            summary = reconcile(root, report_path)
            report = json.loads(report_path.read_text())
            self.assertTrue(summary['native_measurements_stale'])
            self.assertTrue(report['competing_methods'][0]['candidates'][0]['stale'])
            self.assertFalse(report['competing_methods'][0]['eligible_for_integration'])

    def test_missing_measurements_mark_stale_without_failing(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            self.make_fixture(root, [('rebuild/2008-06/native-classes/Foo.cpp', 'd' * 64)])
            summary = reconcile(root)
            self.assertTrue(summary['method_index_stale'])
            self.assertTrue(summary['native_measurements_stale'])
            self.assertEqual(summary['ranked_method_targets'], 0)

    def test_review_updates_only_current_coordinator_reviewing_rows(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            path = root / 'docs/A.txt'
            path.parent.mkdir(parents=True)
            path.write_text('canonical stays intact')
            run, _ = self.make_fixture(root, [
                ('docs/A.txt', 'e' * 64), ('docs/B.txt', 'f' * 64), ('docs/C.txt', '0' * 64)])
            inbox = root / 'work/agent-inbox/drafts.sqlite3'
            inbox.parent.mkdir(parents=True)
            with closing(sqlite3.connect(inbox)) as db:
                db.execute('CREATE TABLE reviews(id TEXT PRIMARY KEY,state TEXT,detail TEXT,updated REAL)')
                db.executemany('INSERT INTO reviews VALUES(?,?,?,?)', [
                    ('bundle-0', 'reviewing', json.dumps({'coordinator_run': run, 'input_key': 'old'}), 1),
                    ('bundle-1', 'reviewing', json.dumps({'coordinator_run': 'older-run'}), 1),
                    ('bundle-2', 'rejected', '{"human":"keep"}', 1),
                ])
                db.commit()

            reconcile(root, record_reviews=True)
            with closing(sqlite3.connect(inbox)) as db:
                rows = dict((identifier, (state, detail)) for identifier, state, detail
                            in db.execute('SELECT id,state,detail FROM reviews'))
            self.assertEqual(rows['bundle-0'][0], 'reviewing')
            self.assertEqual(json.loads(rows['bundle-0'][1])['input_key'], 'key-current')
            self.assertEqual(rows['bundle-1'][1], json.dumps({'coordinator_run': 'older-run'}))
            self.assertEqual(rows['bundle-2'], ('rejected', '{"human":"keep"}'))
            self.assertEqual(path.read_text(), 'canonical stays intact')


if __name__ == '__main__':
    unittest.main()
