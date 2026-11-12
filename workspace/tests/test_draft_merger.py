import hashlib
import json
from pathlib import Path
import subprocess
import tempfile
import unittest
from unittest.mock import patch

from roc import native_drafts
from roc.draft_merger import canonical_state, classify_packet, content_hash, process, proof_key


class DraftMergerTests(unittest.TestCase):
    def make_repo(self, temp):
        root = Path(temp)
        subprocess.run(['git', 'init', '-q'], cwd=root, check=True)
        subprocess.run(['git', 'config', 'user.name', 'Test'], cwd=root, check=True)
        subprocess.run(['git', 'config', 'user.email', 'test@example.invalid'], cwd=root, check=True)
        source = root / 'docs/A.txt'
        source.parent.mkdir(parents=True, exist_ok=True)
        source.write_text('baseline')
        subprocess.run(['git', 'add', '.'], cwd=root, check=True)
        subprocess.run(['git', 'commit', '-qm', 'baseline'], cwd=root, check=True)
        return root, source, subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip()

    def add_bundle(self, root, head, text, base='baseline', session=None):
        packet = dict(schema=1, user='TestUser', model='unittest', session=session or hashlib.md5(text.encode()).hexdigest(),
                      baseline=head, parent=None, status='draft', exact_credits=0, created=1,
                      files={'docs/A.txt': {'base': base, 'text': text}})
        identifier = native_drafts.digest(packet)
        with native_drafts.Inbox(root).connect() as db:
            db.execute('INSERT INTO bundles(id,user,packet,received) VALUES(?,?,?,?)',
                       (identifier, packet['user'], native_drafts.encoded(packet).decode(), 1))
        return identifier

    def unlocked_process(self, *args, **kwargs):
        with patch('roc.draft_merger.native_drafts.integration_lock',
                   side_effect=lambda root, action, token=None: {'token': 'test-lock'}):
            return process(*args, **kwargs)

    def test_content_hash_uses_exact_bytes(self):
        self.assertEqual(content_hash(b'\xef\xbb\xbfline\r\n'), hashlib.sha256(b'\xef\xbb\xbfline\r\n').hexdigest())
        self.assertNotEqual(content_hash(b'line\r\n'), content_hash(b'line\n'))
        self.assertNotEqual(content_hash(b'\xef\xbb\xbfline\r\n'), content_hash(b'line\r\n'))

    def test_proof_key_is_stable_for_mapping_order(self):
        self.assertEqual(proof_key({'b': 2, 'a': 1}), proof_key({'a': 1, 'b': 2}))
        self.assertNotEqual(proof_key({'a': 1}), proof_key({'a': '1'}))

    def test_canonical_state_tracks_missing_and_invalidates_on_byte_change(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            file = root / 'rebuild/2008-06/native-classes/Foo.cpp'
            file.parent.mkdir(parents=True)
            file.write_bytes(b'first\r\n')
            before = canonical_state(root, ['rebuild/2008-06/native-classes/Foo.cpp', 'rebuild/2008-06/native-classes/Missing.cpp'])
            self.assertEqual(before['rebuild/2008-06/native-classes/Foo.cpp'], {'sha256': content_hash(b'first\r\n'), 'exists': True})
            self.assertEqual(before['rebuild/2008-06/native-classes/Missing.cpp'], {'sha256': None, 'exists': False})
            file.write_bytes(b'first\n')
            after = canonical_state(root, ['rebuild/2008-06/native-classes/Foo.cpp', 'rebuild/2008-06/native-classes/Missing.cpp'])
            self.assertNotEqual(proof_key(before), proof_key(after))

    def test_canonical_state_rejects_symlink_escape(self):
        with tempfile.TemporaryDirectory() as temp, tempfile.TemporaryDirectory() as outside:
            root = Path(temp)
            link = root / 'rebuild/2008-06/native-classes/escape'
            link.parent.mkdir(parents=True)
            try:
                link.symlink_to(Path(outside), target_is_directory=True)
            except (OSError, NotImplementedError):
                self.skipTest('directory symlinks unavailable')
            with self.assertRaises(ValueError):
                canonical_state(root, ['rebuild/2008-06/native-classes/escape/outside.cpp'])

    def test_classifies_mixed_packet_rows_independently(self):
        hashes = {text: content_hash(text.encode()) for text in ('same', 'live', 'new', 'candidate', 'candidate-2')}
        packet = {'files': {
            'same.cpp': {'text': 'same', 'base': 'old'},
            'live.cpp': {'text': 'live', 'base': 'old'},
            'unchanged.cpp': {'text': 'same', 'base': 'same'},
            'deleted.cpp': {'text': None, 'base': 'old'},
            'new.cpp': {'text': 'new', 'base': None},
            'apply.cpp': {'text': 'candidate', 'base': 'base'},
            'conflict.cpp': {'text': 'candidate-2', 'base': 'stale'},
        }}
        committed = {'same.cpp': 'same', 'deleted.cpp': None}
        live = {
            'same.cpp': 'other', 'live.cpp': 'live', 'unchanged.cpp': 'other',
            'deleted.cpp': 'old', 'new.cpp': None, 'apply.cpp': 'base', 'conflict.cpp': 'changed',
        }
        rows = classify_packet(packet, committed, live)
        self.assertEqual([row['path'] for row in rows], list(packet['files']))
        self.assertEqual([row['state'] for row in rows], [
            'duplicate-committed', 'already-live', 'no-change', 'deletion-review',
            'new-file', 'base-applies', 'conflict-review',
        ])
        self.assertEqual(rows[0]['candidate_sha256'], hashes['same'])
        self.assertEqual(rows[0]['base_sha256'], content_hash(b'old'))
        self.assertEqual(rows[0]['current_sha256'], content_hash(b'other'))

    def test_deletion_never_counts_as_committed_duplicate(self):
        packet = {'files': {'gone.cpp': {'text': None, 'base': 'old'}}}
        row = classify_packet(packet, {'gone.cpp': None}, {'gone.cpp': None})[0]
        self.assertEqual(row['state'], 'deletion-review')

    def test_committed_duplicate_comparison_preserves_newlines(self):
        packet = {'files': {'file.cpp': {'text': 'line\r\n', 'base': 'old'}}}
        row = classify_packet(packet, {'file.cpp': 'line\n'}, {'file.cpp': 'old'})[0]
        self.assertEqual(row['state'], 'base-applies')

    def test_stale_base_is_conflict_even_when_candidate_hash_known(self):
        packet = {'files': {'file.cpp': {'text': 'candidate', 'base': 'old'}}}
        row = classify_packet(packet, {}, {'file.cpp': 'newer'})[0]
        self.assertEqual(row['state'], 'conflict-review')
        self.assertEqual(row['current_sha256'], content_hash(b'newer'))

    def test_process_records_all_bundles_once_and_preserves_rejection(self):
        with tempfile.TemporaryDirectory() as temp:
            root, _, head = self.make_repo(temp)
            first = self.add_bundle(root, head, 'candidate one', session='1' * 32)
            duplicate = self.add_bundle(root, head, 'baseline', base='old baseline', session='2' * 32)
            rejected = self.add_bundle(root, head, 'candidate three', session='3' * 32)
            with native_drafts.Inbox(root).connect() as db:
                db.execute('INSERT INTO reviews VALUES(?,?,?,?)', (rejected, 'rejected', '{"owner":"keep"}', 1))

            first_run = self.unlocked_process(root, record_reviews=True)
            self.assertEqual(first_run['bundle_count'], 3)
            self.assertEqual(first_run['reviews_recorded'], 2)
            with native_drafts.Inbox(root).connect() as db:
                self.assertEqual(db.execute('SELECT COUNT(*) FROM bundles').fetchone()[0], 3)
                states = dict(db.execute('SELECT id,state FROM reviews'))
                detail = db.execute('SELECT detail FROM reviews WHERE id=?', (rejected,)).fetchone()[0]
            self.assertEqual(states[first], 'reviewing')
            self.assertEqual(states[duplicate], 'duplicate')
            self.assertEqual(states[rejected], 'rejected')
            self.assertEqual(detail, '{"owner":"keep"}')

            second_run = self.unlocked_process(root, record_reviews=True)
            self.assertEqual(second_run['bundle_count'], 3)
            self.assertEqual(second_run['reviews_recorded'], 0)
            with native_drafts.Inbox(root).connect() as db:
                self.assertEqual(db.execute('SELECT COUNT(*) FROM reviews').fetchone()[0], 3)

    def test_dirty_only_identical_content_remains_reviewing(self):
        with tempfile.TemporaryDirectory() as temp:
            root, source, head = self.make_repo(temp)
            source.write_text('working copy candidate')
            identifier = self.add_bundle(root, head, 'working copy candidate')

            report = root / 'draft-report.json'
            result = self.unlocked_process(root, report=report, record_reviews=True)
            self.assertEqual(result['reviews_recorded'], 1)
            row = next(row for row in json.loads(report.read_text())['bundles'] if row['id'] == identifier)
            self.assertEqual(row['files'][0]['state'], 'already-live')
            with native_drafts.Inbox(root).connect() as db:
                state = db.execute('SELECT state FROM reviews WHERE id=?', (identifier,)).fetchone()[0]
            self.assertEqual(state, 'reviewing')

    def test_source_mutation_during_review_marks_run_stale_without_reviews(self):
        with tempfile.TemporaryDirectory() as temp:
            root, source, head = self.make_repo(temp)
            identifier = self.add_bundle(root, head, 'review candidate')

            def mutate_source(*args):
                source.write_text('changed during processing')
                return None

            with patch('roc.draft_merger.native_drafts.integration_lock',
                       side_effect=lambda root, action, token=None: {'token': 'test-lock'}), \
                    patch('roc.draft_merger.syntax_check', side_effect=mutate_source):
                result = process(root, record_reviews=True)
            self.assertTrue(result['stale'])
            self.assertEqual(result['reviews_recorded'], 0)
            with native_drafts.Inbox(root).connect() as db:
                self.assertIsNone(db.execute('SELECT state FROM reviews WHERE id=?', (identifier,)).fetchone())


if __name__ == '__main__':
    unittest.main()
