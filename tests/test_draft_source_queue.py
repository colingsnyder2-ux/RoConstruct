import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

from roc import draft_source_queue as queue, draft_source, native_drafts


class SourceQueueTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.folder = self.root / 'work/draft-merger'
        for path in draft_source.verification_files(self.root) + [self.root / 'roc/draft_source_queue.py']:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text('test verifier')
        self.name = 'rebuild/2008-06/native-classes/Foo.cpp'
        self.target = self.root / self.name
        self.target.parent.mkdir(parents=True)
        self.current = 'namespace RBX {\nint Foo::old() {return 2;}\n}\n'
        self.target.write_bytes(self.current.encode())
        self.family = self.folder / 'families/test'
        (self.family / 'overlay' / self.name).parent.mkdir(parents=True)
        self.candidate = self.family / 'overlay' / self.name
        self.candidate.write_text('namespace RBX {\nint Foo::old() {return 1;}\nint Foo::added() {return 3;}\n}\n')
        native_drafts.atomic(self.family / 'manifest.json', dict(bundle_id='a' * 64))
        self.unit = dict(path=self.name, original_methods=[dict(symbol='?added@Foo@RBX@@QAEHXZ',
                         address='00401000', exact_code=True, references_verified=False)])
        self.save_measurement()

    def save_measurement(self):
        native_drafts.atomic(self.family / 'measurement.json', dict(profile='default', units=[self.unit]))

    def test_proposes_missing_method_preserves_better_existing_body_without_model(self):
        result = queue.discover(self.root)
        self.assertEqual(result['count'], 1)
        self.assertEqual(result['models_used'], 0)
        payload = json.loads((self.folder / 'source-queue.json').read_text())
        review = json.loads(Path(payload['proposals'][0]).read_text())
        self.assertEqual([row['signature'] for row in review['methods']], ['RBX::Foo::added()'])
        self.assertIn('Existing body differs', payload['skipped'][0]['reason'])
        self.assertEqual(self.target.read_bytes(), self.current.encode())

    def test_ambiguous_original_targets_are_not_auto_selected(self):
        self.unit['original_methods'].append(dict(self.unit['original_methods'][0], address='00401010'))
        self.save_measurement()
        self.assertEqual(queue.discover(self.root)['count'], 0)

    def test_existing_overload_cannot_witness_new_method(self):
        self.unit['original_methods'].insert(0, dict(
            symbol='?added@Foo@RBX@@QAEHH@Z', address='00400000', exact_code=True,
            baseline_exact_code=True, references_verified=True))
        self.unit['original_methods'][1]['baseline_exact_code'] = False
        self.save_measurement()
        self.assertEqual(queue.discover(self.root)['count'], 1)
        payload = json.loads((self.folder / 'source-queue.json').read_text())
        review = json.loads(Path(payload['proposals'][0]).read_text())
        self.assertEqual(review['methods'][0]['symbol'], '?added@Foo@RBX@@QAEHXZ')

    def test_new_file_proposes_only_exact_methods(self):
        self.target.unlink()
        result = queue.discover(self.root)
        self.assertEqual(result['count'], 1)
        payload = json.loads((self.folder / 'source-queue.json').read_text())
        review = json.loads(Path(payload['proposals'][0]).read_text())
        self.assertTrue(review['new_file'])
        self.assertIsNone(review['before_sha256'])
        self.assertEqual([row['signature'] for row in review['methods']], ['RBX::Foo::added()'])

    def test_existing_method_is_never_proposed_again(self):
        self.target.write_text(self.candidate.read_text())
        self.assertEqual(queue.discover(self.root)['count'], 0)

    def test_discovery_can_select_one_uploader(self):
        with native_drafts.Inbox(self.root).connect() as db:
            db.execute('INSERT INTO bundles(id,user,packet,received) VALUES(?,?,?,?)',
                       ('a' * 64, 'coldek', '{}', 1))
        self.assertEqual(queue.discover(self.root, users=['other'])['count'], 0)
        self.assertEqual(queue.discover(self.root, users=['COLDEK'])['count'], 1)

    def test_stronger_reference_evidence_wins_equal_method_candidate(self):
        better = self.folder / 'families/better'
        (better / 'overlay' / self.name).parent.mkdir(parents=True)
        (better / 'overlay' / self.name).write_text(self.candidate.read_text())
        native_drafts.atomic(better / 'manifest.json', dict(bundle_id='b' * 64, companion_bundles=['c' * 64]))
        native_drafts.atomic(better / 'measurement.json', dict(profile='default', units=[dict(
            self.unit, original_methods=[dict(self.unit['original_methods'][0], references_verified=True)])]))
        queue.discover(self.root)
        payload = json.loads((self.folder / 'source-queue.json').read_text())
        review = json.loads(Path(payload['proposals'][0]).read_text())
        self.assertEqual(review['bundle'], 'b' * 64)

    def test_blocked_sibling_does_not_prevent_independent_improvement(self):
        self.candidate.write_text(self.candidate.read_text() + '\nnamespace RBX { int Foo::blocked() {return 4;} }\n')
        self.unit['original_methods'].append(dict(symbol='?blocked@Foo@RBX@@QAEHXZ',
            address='00402000', exact_code=True, references_verified=False))
        self.save_measurement()
        queue.discover(self.root)
        for name in ('draft_source_queue', 'draft_source', 'draft_native', 'draft_proof'):
            path = self.root / 'roc' / (name + '.py')
            path.parent.mkdir(exist_ok=True)
            path.write_text('test gate')

        def prove(root, path, apply):
            review = json.loads(Path(path).read_text())
            if len(review['methods']) > 1 or 'blocked' in review['methods'][0]['signature']:
                return dict(state='blocked', blockers=['one unsupported dependency'])
            with self.target.open('a') as stream:
                stream.write('\nnamespace RBX { ' + review['methods'][0]['source'] + ' }\n')
            return dict(state='integrated-inactive')

        with patch('roc.draft_source.prove', side_effect=prove):
            result = queue.work(self.root, limit=3, apply=True)
        self.assertEqual(result['attempted'], 3)
        self.assertEqual(result['integrated'], 1)
        self.assertIn('Foo::added', self.target.read_text())
        self.assertNotIn('Foo::blocked', self.target.read_text())
        self.assertIn('return 2;', self.target.read_text())

    def test_bounded_worker_caches_attempts_until_context_changes(self):
        queue.discover(self.root)
        for name in ('draft_source_queue', 'draft_source', 'draft_native', 'draft_proof'):
            path = self.root / 'roc' / (name + '.py')
            path.parent.mkdir(exist_ok=True)
            path.write_text('test gate')
        native_drafts.atomic(self.folder / 'family-queue.json', dict(input_key='first'))
        with patch('roc.draft_source.prove', return_value=dict(state='blocked', blockers=['unresolved input'])) as prove:
            first = queue.work(self.root, limit=1, apply=True)
            self.assertEqual(first['models_used'], 0)
            self.assertEqual(first['attempted'], 1)
            self.assertEqual(queue.work(self.root, limit=1, apply=True)['attempted'], 0)
            header = self.root / 'rebuild/2008-06/native-headers/Foo.h'
            header.parent.mkdir(parents=True, exist_ok=True)
            header.write_text('changed dependency')
            self.assertEqual(queue.work(self.root, limit=1, apply=True)['attempted'], 1)
            native_drafts.atomic(self.folder / 'family-queue.json', dict(input_key='changed'))
            self.assertEqual(queue.work(self.root, limit=1, apply=True)['attempted'], 1)
        self.assertEqual(prove.call_count, 3)
        self.assertTrue(prove.call_args.args[2])


if __name__ == '__main__':
    unittest.main()
