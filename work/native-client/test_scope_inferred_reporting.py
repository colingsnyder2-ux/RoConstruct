import sys
import unittest
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).parent / 'ogre'))
import scope_audit


class InferredReportingTest(unittest.TestCase):
    def test_inferred_owner_count_does_not_claim_reference_audit(self):
        manifest = {'families': [{'symbols': [
            {'symbol': 'inferred_owner', 'addr': '001', 'status': 'inactive_exact'},
            {'symbol': 'other_owner', 'addr': '002', 'status': 'inactive_exact'},
        ]}]}
        inferred = {'rows': [{'symbol': 'inferred_owner', 'inferred_name': True},
                             {'symbol': 'callee', 'inferred_name': True}]}
        with patch.object(scope_audit.run_all, 'roots', return_value=['001', '002']), \
             patch.object(scope_audit.run_all.match, '_functions', return_value={'001': {}, '002': {}}), \
             patch.object(scope_audit.run_all.match, 'target', return_value=(b'1234', None)):
            totals = scope_audit.audit(manifest, inferred)['totals']
        self.assertEqual(totals['inferred_name_functions'], 1)
        self.assertIsNone(totals['inferred_name_dependency_functions'])
        self.assertIsNone(totals['inferred_field_functions'])
        self.assertIn('does not audit', totals['inferred_name_note'])


if __name__ == '__main__':
    unittest.main()
