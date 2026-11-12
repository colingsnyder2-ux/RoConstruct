import json
from contextlib import contextmanager
from pathlib import Path
import sqlite3
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch

from roc import draft_files, draft_proof
from roc.draft_merger import SCHEMA, content_hash, proof_key
from roc.draft_append import apply_append_file


class DraftAppendTests(unittest.TestCase):
    path = 'rebuild/2008-06/native-classes/Foo.cpp'

    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.root = Path(self.temp.name)
        self.db = sqlite3.connect(':memory:')
        self.db.executescript(SCHEMA)
        self.target = self.root / self.path
        self.target.parent.mkdir(parents=True)
        self.before = b'int Foo::first() { return 1; }\r\n'
        self.addition = b'\r\nint Foo::second() { return 2; }\r\n'
        self.raw = self.before + self.addition
        self.target.write_bytes(self.before)
        self.proof_id = 'proof-append'
        self.expected = {
            'candidate_sha256': content_hash(self.raw),
            'before_sha256': content_hash(self.before),
            'input_key': 'a' * 64,
            'client': '2008-06',
            'verifier_sha256': 'b' * 64,
            'activate': False,
        }
        self.receipt = {
            'schema': 1,
            'kind': 'independent-draft-proof',
            **self.expected,
            'path': self.path,
            'before_methods': ['Foo::first'],
            'after_methods': ['Foo::first', 'Foo::second'],
            'checks': {name: True for name in draft_proof.BASE_CHECKS},
        }
        self.add_proof()

    def tearDown(self):
        self.db.close()
        self.temp.cleanup()

    def add_proof(self, receipt=None):
        self.db.execute('INSERT OR REPLACE INTO proofs VALUES(?,?,?,?,?,?)',
                        (self.proof_id, self.expected['input_key'], 'original-msvc-method-v1',
                         self.expected['candidate_sha256'], json.dumps(receipt or self.receipt), 1))

    def apply(self, lease_check=None, input_check=None):
        return apply_append_file(
            self.root, self.db, 'run-1', 'bundle-1', self.path, self.raw,
            self.proof_id, self.expected, lease_check or (lambda path: None),
            input_check or (lambda: self.expected['input_key']))

    def test_valid_append_preserves_prefix_and_retry_is_idempotent(self):
        first = self.apply()
        self.assertEqual(first['state'], 'applied-inactive')
        self.assertFalse(first['recovered'])
        self.assertEqual(self.target.read_bytes(), self.raw)
        second = self.apply()
        self.assertEqual(second['state'], 'applied-inactive')
        self.assertTrue(second['recovered'])
        self.assertEqual(self.target.read_bytes(), self.raw)
        stored = dict(self.db.execute('SELECT sha256,bytes FROM contents'))
        self.assertEqual(stored[self.expected['before_sha256']], self.before)
        self.assertEqual(stored[self.expected['candidate_sha256']], self.raw)

    def test_nonprefix_replacement_is_rejected(self):
        replacement = b'int Foo::first() { return 9; }\r\n' + self.addition
        self.expected['candidate_sha256'] = content_hash(replacement)
        self.receipt['candidate_sha256'] = self.expected['candidate_sha256']
        self.add_proof()
        with self.assertRaisesRegex(ValueError, 'strict append'):
            apply_append_file(self.root, self.db, 'run-1', 'bundle-1', self.path,
                              replacement, self.proof_id, self.expected,
                              lambda path: None, lambda: self.expected['input_key'])
        self.assertEqual(self.target.read_bytes(), self.before)
        self.assertEqual(self.db.execute('SELECT COUNT(*) FROM actions').fetchone()[0], 0)

    def test_stale_input_blocks_append(self):
        with self.assertRaisesRegex(ValueError, 'Inputs changed'):
            self.apply(input_check=lambda: 'c' * 64)
        self.assertEqual(self.target.read_bytes(), self.before)
        self.assertEqual(self.db.execute('SELECT COUNT(*) FROM actions').fetchone()[0], 0)

    def test_denied_lease_blocks_append(self):
        def reject(path):
            raise PermissionError('lease held')

        with self.assertRaisesRegex(PermissionError, 'lease held'):
            self.apply(lease_check=reject)
        self.assertEqual(self.target.read_bytes(), self.before)

    def test_header_target_is_rejected(self):
        header = 'rebuild/2008-06/native-headers/gui/Gui.h'
        with self.assertRaisesRegex(ValueError, 'native class source'):
            apply_append_file(self.root, self.db, 'run-1', 'bundle-1', header,
                              self.raw, self.proof_id, self.expected,
                              lambda path: None, lambda: self.expected['input_key'])
        self.assertEqual(self.target.read_bytes(), self.before)

    def test_changed_original_is_never_replaced(self):
        changed = b'int Foo::first() { return 3; }\r\n'
        self.target.write_bytes(changed)
        with self.assertRaisesRegex(ValueError, 'Proof baseline'):
            self.apply()
        self.assertEqual(self.target.read_bytes(), changed)

    def test_source_changed_during_input_check_blocks_before_journaling(self):
        changed = b'int Foo::first() { return 4; }\r\n'

        def mutate_source():
            self.target.write_bytes(changed)
            return self.expected['input_key']

        with self.assertRaisesRegex(ValueError, 'changed since append checks'):
            self.apply(input_check=mutate_source)
        self.assertEqual(self.target.read_bytes(), changed)
        self.assertEqual(self.db.execute('SELECT COUNT(*) FROM actions').fetchone()[0], 0)

    def test_source_changed_between_precheck_and_exclusive_open_is_preserved(self):
        changed = b'int Foo::first() { return 5; }\r\n'
        original = draft_files.exclusive_existing

        @contextmanager
        def mutate_then_open(path):
            self.target.write_bytes(changed)
            with original(path) as stream:
                yield stream

        with patch('roc.draft_append.draft_files.exclusive_existing', side_effect=mutate_then_open):
            with self.assertRaisesRegex(ValueError, 'changed before exclusive append'):
                self.apply()
        self.assertEqual(self.target.read_bytes(), changed)
        self.assertEqual(self.db.execute('SELECT state FROM actions').fetchone()[0], 'prepared')
        stored = dict(self.db.execute('SELECT sha256,bytes FROM contents'))
        self.assertEqual(stored[self.expected['before_sha256']], self.before)
        self.assertEqual(stored[self.expected['candidate_sha256']], self.raw)

    def test_partial_append_keeps_original_prefix_and_requires_reconciliation(self):
        original = draft_files.exclusive_existing

        class PartialWriter:
            def __init__(self, stream):
                self.stream = stream

            def __getattr__(self, name):
                return getattr(self.stream, name)

            def write(self, suffix):
                self.stream.write(suffix[:4])
                raise OSError('simulated interrupted append')

        @contextmanager
        def fail_partway(path):
            with original(path) as stream:
                yield PartialWriter(stream)

        with patch('roc.draft_append.draft_files.exclusive_existing', side_effect=fail_partway):
            with self.assertRaisesRegex(OSError, 'simulated interrupted'):
                self.apply()
        self.assertEqual(self.target.read_bytes(), self.before + self.addition[:4])
        self.assertTrue(self.target.read_bytes().startswith(self.before))
        self.assertEqual(self.db.execute('SELECT state FROM actions').fetchone()[0], 'prepared')
        with self.assertRaisesRegex(ValueError, 'Interrupted integration'):
            self.apply()

    @unittest.skipUnless(sys.platform == 'win32', 'Windows sharing-mode test')
    def test_windows_handle_blocks_competing_process_write_and_rename(self):
        script = (
            "import os,sys\n"
            "p=sys.argv[1]; q=p+'.renamed'\n"
            "try:\n f=open(p,'ab'); f.write(b'bad'); f.close(); raise SystemExit(11)\n"
            "except PermissionError: pass\n"
            "try:\n os.replace(p,q); raise SystemExit(12)\n"
            "except PermissionError: pass\n"
        )
        with draft_files.exclusive_existing(self.target):
            result = subprocess.run([sys.executable, '-c', script, str(self.target)],
                                    capture_output=True, text=True)
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(self.target.read_bytes(), self.before)
        self.assertFalse(self.target.with_suffix('.cpp.renamed').exists())

    def test_prepared_action_with_ambiguous_current_bytes_blocks_recovery(self):
        identity = proof_key(dict(proof=self.proof_id, path=self.path,
                                  sha256=content_hash(self.raw)))
        self.db.execute('INSERT INTO actions VALUES(?,?,?,?,?,?,?,?)',
                        (identity, 'run-1', 'bundle-1', self.path,
                         self.expected['before_sha256'], self.expected['candidate_sha256'],
                         'prepared', '{}'))
        ambiguous = b'different concurrent edit\r\n'
        self.target.write_bytes(ambiguous)
        with self.assertRaisesRegex(ValueError, 'Interrupted integration'):
            self.apply()
        self.assertEqual(self.target.read_bytes(), ambiguous)
        self.assertEqual(self.db.execute('SELECT state FROM actions WHERE id=?', (identity,)).fetchone()[0],
                         'prepared')


if __name__ == '__main__':
    unittest.main()
