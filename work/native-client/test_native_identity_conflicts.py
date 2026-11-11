"""Regression coverage for ambiguous identities in the native proof gate."""
import json
import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import native_bulk
import test_native_onepast


class IdentityConflicts(unittest.TestCase):
    def test_conflict_is_local_and_order_independent(self):
        with tempfile.TemporaryDirectory(dir=ROOT / 'work/native-client') as folder:
            paths = []
            for index, address in enumerate(('00400001', '00400002', '00400001')):
                path = Path(folder) / ('%s.json' % index)
                path.write_text(json.dumps({'rows': [
                    {'symbol': 'ambiguous', 'address': address},
                    {'symbol': 'independent', 'address': '00400003'}]}))
                paths.append(str(path))
            for order in (paths, paths[::-1]):
                names, bindings, blockers, _ = native_bulk.seed_evidence(ROOT, order, strict_conflicts=False)
                self.assertEqual([], blockers)
                self.assertNotIn('ambiguous', names)
                self.assertIsNone(bindings['ambiguous'])
                self.assertEqual({'00400003'}, names['independent'])
                self.assertEqual('00400003', bindings['independent'])
            _, _, blockers, _ = native_bulk.seed_evidence(ROOT, paths)
            self.assertIn('conflicting reference identity: ambiguous', blockers)

    def test_ambiguous_data_reference_is_rejected(self):
        errors = test_native_onepast.check(bindings={'array': None})
        self.assertIn('conflicting reference identity: array', errors)
        self.assertEqual([], test_native_onepast.check(bindings={'array': '00001000'}))

    def test_missing_receipt_still_blocks_family(self):
        _, _, blockers, _ = native_bulk.seed_evidence(ROOT, ['work/native-client/does-not-exist-for-test.json'])
        self.assertTrue(any('missing reference receipt' in error for error in blockers))

    def test_stale_receipt_still_blocks_family(self):
        with tempfile.TemporaryDirectory(dir=ROOT / 'work/native-client') as folder:
            path = Path(folder) / 'stale.json'
            path.write_text(json.dumps({'sources': {'roc/native_bulk.py': 'incorrect'},
                                        'rows': [{'symbol': 'untrusted', 'address': '00400001'}]}))
            names, _, blockers, _ = native_bulk.seed_evidence(ROOT, [str(path)])
            self.assertNotIn('untrusted', names)
            self.assertTrue(any('stale reference receipt' in error for error in blockers))

    def test_ambiguous_owner_cannot_be_inferred_or_accepted(self):
        class Targets:
            def candidates(self, body, relocs):
                return ['00400001']
            def body(self, address):
                return b'abcdef', set()
        with patch.object(native_bulk.match, 'coff_functions', return_value=[('owner', b'abcdef', set())]):
            rows = native_bulk.harvest(b'', Targets(), {}, {'owner': None})
        self.assertEqual('draft', rows[0]['status'])
        self.assertEqual(['conflicting symbol identity: owner'], rows[0]['rejections'][0]['errors'])

    def test_independent_owner_remains_exact(self):
        class Targets:
            def candidates(self, body, relocs):
                return ['00400003']
            def body(self, address):
                return b'abcdef', set()
        with patch.object(native_bulk.match, 'coff_functions', return_value=[('owner', b'abcdef', set())]), \
             patch.object(native_bulk, 'audit_references', return_value=([], [])):
            rows = native_bulk.harvest(b'', Targets(), {'owner': {'00400003'}}, {'other': None})
        self.assertEqual('inactive_exact', rows[0]['status'])


if __name__ == '__main__':
    unittest.main()
