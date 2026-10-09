"""Named family boundaries for fingerprint transfer."""
import sys
import sqlite3
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent.parent))
from roc.batch_fingerprint import flag_batches, source_class, unit_class, unit_family


class FingerprintFamilyTests(unittest.TestCase):
    def test_ogre_filename_prefix_stays_family_scoped(self):
        from roc.server import _source_class_token
        source = '// roc-lib: ogre-1.7.0 OgreMain/src/OgreSceneManager.cpp'
        self.assertEqual(source_class(source), 'scenemanager')
        self.assertEqual(_source_class_token(source), 'scenemanager')
        self.assertEqual(unit_class('Ogre::SceneManager'), 'scenemanager')
        self.assertEqual(unit_class('OgreSceneManager'), 'scenemanager')
        self.assertEqual(source_class(source.replace('ogre-1.7.0', 'rbxgs')), 'ogrescenemanager')
        self.assertEqual(unit_class('RBX::OgreSceneManager'), 'ogrescenemanager')
        camera = source.replace('SceneManager', 'Camera')
        self.assertEqual(source_class(camera), unit_class('Ogre::Camera'))
        self.assertEqual(_source_class_token(camera), unit_class('Ogre::Camera'))

    def test_xtp_theme_namespace(self):
        self.assertEqual(unit_family('XTPPaintThemes::CXTPOffice2003Theme'), 'xtp')
        self.assertEqual(unit_class('XTPPaintThemes::CXTPOffice2003Theme'), 'office2003theme')

    def test_no_substring_family_transfer(self):
        self.assertEqual(unit_family('RBX::XTPPaintThemes'), 'roblox')
        self.assertIsNone(unit_family('Other::XTPPaintThemes::CXTPOffice2003Theme'))
        self.assertIsNone(unit_family('XTPPaintThemesOther::CXTPOffice2003Theme'))

    def test_flags_require_exact_recipe_and_same_class(self):
        db = sqlite3.connect(':memory:')
        db.execute('CREATE TABLE funcs(client,addr,unit,score,source)')
        source = '// roc-lang: cpp\n// roc-cl: 30729\n// roc-flags: /O2 /Ob2 /Oy /GS-\n// roc-lib: xtp-11.2.2 Source/XTPReportControl.cpp'
        changed = source.replace('/Ob2 /Oy', '').replace('/O2  /GS-', '/O2 /GS- /Ob1 /Oy-')
        db.executemany('INSERT INTO funcs VALUES(?,?,?,?,?)', [
            ('A', 'exact', 'CXTPReportControl', 100, source),
            ('B', 'eligible', 'CXTPReportControl', 60, source),
            ('B', 'other_family', 'RBX::ReportControl', 60, source),
            ('B', 'unknown', 'seg_00400000', 60, source),
            ('B', 'other_class', 'CXTPReportRow', 60, source),
            ('B', 'low', 'CXTPReportControl', 39, source),
            ('B', 'already', 'CXTPReportControl', 80, changed),
            ('B', 'unproven_recipe', 'CXTPReportControl', 80, source.replace('11.2.2', '15.2.1')),
        ])
        self.assertEqual(list(flag_batches(db)), [('B', changed, ['eligible'])])
        db.execute('DELETE FROM funcs WHERE score=100')
        self.assertEqual(list(flag_batches(db)), [])
        db.close()


if __name__ == '__main__':
    unittest.main()
