import hashlib
import json
from pathlib import Path
import subprocess
import tempfile
import unittest

from roc import mew_unsafe_merge


class MewUnsafeMergeTests(unittest.TestCase):
    def test_merge_preserves_baseline_and_reports_provider_overlap(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            def git(*args):
                return subprocess.check_output(['git', *args], cwd=root).decode().strip()
            git('init')
            git('config', 'user.name', 'Test')
            git('config', 'user.email', 'test@example.invalid')
            baseline = root / 'workspace/rebuild/2008-06/App/src/Existing.cpp'
            baseline.parent.mkdir(parents=True)
            baseline.write_text('int Foo::same() { return 1; }')
            git('add', '.')
            git('commit', '-m', 'baseline')
            git('branch', 'baseline')
            donor = root / 'rebuild/2008-06/native-classes/New.cpp'
            donor.parent.mkdir(parents=True)
            donor.write_text('int Foo::same() { return 2; }')
            git('add', '.')
            git('commit', '-m', 'donor')
            blob = git('rev-parse', 'HEAD:rebuild/2008-06/native-classes/New.cpp')
            source = {'fork_commit': git('rev-parse', 'HEAD'), 'files': [{
                'path': 'rebuild/2008-06/native-classes/New.cpp', 'blob': blob,
                'sha256': hashlib.sha256(donor.read_bytes()).hexdigest()}]}
            manifest = root / 'input.json'
            manifest.write_text(json.dumps(source))
            output = root / 'out'
            report = mew_unsafe_merge.prepare(root, manifest, output, 'baseline')
            self.assertEqual(report['possible_method_overlaps'][0]['method'], 'Foo::same')
            self.assertEqual(baseline.read_text(), 'int Foo::same() { return 1; }')
            self.assertEqual((output / 'merged/native-classes/New.cpp').read_text(), donor.read_text())
            self.assertEqual((output / 'merged/App/src/Existing.cpp').read_text(), baseline.read_text())
            with self.assertRaises(FileExistsError):
                mew_unsafe_merge.prepare(root, manifest, output, 'baseline')


if __name__ == '__main__':
    unittest.main()
