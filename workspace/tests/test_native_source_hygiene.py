from pathlib import Path
import shutil
import subprocess
import sys
import tempfile
import unittest

SCRIPT = Path(__file__).resolve().parents[1] / 'rebuild/2008-06/tests/audit_native_source_hygiene.py'

class NativeSourceHygieneTests(unittest.TestCase):
    def test_default_scans_organized_and_legacy_sources(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            script = root / 'rebuild/2008-06/tests/audit_native_source_hygiene.py'
            script.parent.mkdir(parents=True)
            shutil.copyfile(SCRIPT, script)
            legacy = root / 'rebuild/2008-06/native-classes'
            moved = root / 'rebuild/2008-06/App/src/v8datamodel'
            legacy.mkdir(parents=True)
            moved.mkdir(parents=True)
            (legacy / 'Compat.cpp').write_text('// compat\n')
            candidate = moved / 'Candidate.cpp'
            candidate.write_text('#include "../../../tests/trial.h"\n')
            result = subprocess.run([sys.executable, str(script)], capture_output=True, text=True)
            self.assertNotEqual(result.returncode, 0)
            self.assertIn('Candidate.cpp', result.stdout)
            candidate.write_text('// clean\n')
            result = subprocess.run([sys.executable, str(script)], capture_output=True, text=True)
            self.assertEqual(result.returncode, 0)
            self.assertIn('2 files', result.stdout)

if __name__ == '__main__':
    unittest.main()
