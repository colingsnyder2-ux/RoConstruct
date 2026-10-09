"""Named family boundaries for fingerprint transfer."""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent.parent))
from roc.batch_fingerprint import unit_class, unit_family


class FingerprintFamilyTests(unittest.TestCase):
    def test_xtp_theme_namespace(self):
        self.assertEqual(unit_family('XTPPaintThemes::CXTPOffice2003Theme'), 'xtp')
        self.assertEqual(unit_class('XTPPaintThemes::CXTPOffice2003Theme'), 'office2003theme')

    def test_no_substring_family_transfer(self):
        self.assertEqual(unit_family('RBX::XTPPaintThemes'), 'roblox')
        self.assertIsNone(unit_family('Other::XTPPaintThemes::CXTPOffice2003Theme'))
        self.assertIsNone(unit_family('XTPPaintThemesOther::CXTPOffice2003Theme'))


if __name__ == '__main__':
    unittest.main()
