import unittest

from native_reference_alias_bind import evidence_bindings


class EvidenceBindingsTest(unittest.TestCase):
    def test_local_labels_only_bind_in_origin_object(self):
        rows = [
            {'symbol': '$LN2', 'address': '005eca70', 'object_sha256': 'owner-a'},
            {'symbol': 'shared', 'address': '005eca80'},
        ]
        self.assertEqual(evidence_bindings(rows, 'owner-a'), {'$LN2': '005eca70', 'shared': '005eca80'})
        self.assertEqual(evidence_bindings(rows, 'owner-b'), {'shared': '005eca80'})


if __name__ == '__main__':
    unittest.main()
