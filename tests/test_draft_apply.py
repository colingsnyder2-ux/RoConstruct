import json
from pathlib import Path
import sqlite3
import tempfile
import unittest

from roc import draft_proof
from roc.draft_merger import SCHEMA, apply_new_file, content_hash, proof_key


class DraftApplyTests(unittest.TestCase):
    path = 'rebuild/2008-06/native-classes/Foo.cpp'

    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.root = Path(self.temp.name)
        self.db = sqlite3.connect(':memory:')
        self.db.executescript(SCHEMA)
        self.raw = b'\xef\xbb\xbfint Foo::bar() {\r\n    return 7;\r\n}\r\n'
        self.proof_id = 'proof-1'
        self.expected = {
            'candidate_sha256': content_hash(self.raw),
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
            'before_methods': [],
            'after_methods': ['Foo::bar'],
            'checks': {name: True for name in draft_proof.BASE_CHECKS},
        }
        self.add_proof()

    def tearDown(self):
        self.db.close()
        self.temp.cleanup()

    def add_proof(self, adapter='original-msvc-method-v1', receipt=None):
        self.db.execute('INSERT OR REPLACE INTO proofs VALUES(?,?,?,?,?,?)',
                        (self.proof_id, self.expected['input_key'], adapter,
                         self.expected['candidate_sha256'], json.dumps(receipt or self.receipt), 1))

    def apply(self, lease_check=None, input_check=None):
        return apply_new_file(self.root, self.db, 'run-1', 'bundle-1', self.path,
                              self.raw, self.proof_id, self.expected,
                              lease_check or (lambda path: None),
                              input_check or (lambda: self.expected['input_key']))

    def test_valid_proof_adds_exact_bytes_and_retries_idempotently(self):
        first = self.apply()
        self.assertEqual(first['state'], 'applied-inactive')
        self.assertFalse(first['recovered'])
        self.assertEqual((self.root / self.path).read_bytes(), self.raw)
        second = self.apply()
        self.assertEqual(second['state'], 'applied-inactive')
        self.assertTrue(second['recovered'])
        self.assertEqual((self.root / self.path).read_bytes(), self.raw)

    def test_changed_inputs_block_apply_without_writing(self):
        with self.assertRaisesRegex(ValueError, 'Inputs changed'):
            self.apply(input_check=lambda: 'c' * 64)
        self.assertFalse((self.root / self.path).exists())
        self.assertEqual(self.db.execute('SELECT COUNT(*) FROM actions').fetchone()[0], 0)

    def test_existing_target_is_preserved(self):
        target = self.root / self.path
        target.parent.mkdir(parents=True)
        target.write_bytes(b'local work')
        with self.assertRaisesRegex(ValueError, 'already exists'):
            self.apply()
        self.assertEqual(target.read_bytes(), b'local work')

    def test_unregistered_adapter_and_incomplete_receipt_are_blocked(self):
        self.add_proof(adapter='uploaded-json')
        with self.assertRaisesRegex(ValueError, 'Unregistered proof adapter'):
            self.apply()
        self.add_proof(receipt={**self.receipt, 'checks': {}})
        with self.assertRaisesRegex(ValueError, 'compile check must be true'):
            self.apply()
        self.assertFalse((self.root / self.path).exists())

    def test_missing_coordinator_proof_cannot_be_supplied_by_id_alone(self):
        self.db.execute('DELETE FROM proofs WHERE id=?', (self.proof_id,))
        with self.assertRaisesRegex(ValueError, 'No independently generated proof'):
            self.apply()
        self.assertFalse((self.root / self.path).exists())

    def test_lease_rejection_blocks_write(self):
        def reject(path):
            raise PermissionError('lease held')

        with self.assertRaisesRegex(PermissionError, 'lease held'):
            self.apply(lease_check=reject)
        self.assertFalse((self.root / self.path).exists())

    def test_prepared_action_recovers_matching_interrupted_write(self):
        target = self.root / self.path
        target.parent.mkdir(parents=True)
        target.write_bytes(self.raw)
        action_id = proof_key(dict(proof=self.proof_id, path=self.path,
                                   sha256=content_hash(self.raw)))
        self.db.execute('INSERT INTO actions VALUES(?,?,?,?,?,?,?,?)',
                        (action_id, 'run-1', 'bundle-1', self.path, None,
                         content_hash(self.raw), 'prepared', '{}'))

        result = self.apply()
        self.assertEqual(result, {'action': action_id, 'state': 'applied-inactive', 'recovered': True})
        self.assertEqual(self.db.execute('SELECT state FROM actions WHERE id=?', (action_id,)).fetchone()[0],
                         'applied-inactive')
        self.assertEqual(target.read_bytes(), self.raw)


if __name__ == '__main__':
    unittest.main()
