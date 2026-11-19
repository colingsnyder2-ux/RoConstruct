import os
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))


class StageFilesTest(unittest.TestCase):
    def test_batched_staging_matches_one_by_one(self):
        from roc.server import stage_files
        with tempfile.TemporaryDirectory() as tmp:
            repo = Path(tmp) / 'r'
            docs = repo / 'docs'
            (docs / 'sub dir').mkdir(parents=True)
            names = ['a.json', 'b.html', 'sub dir/c with space.js']
            for i, name in enumerate(names):
                (docs / name).write_bytes(b'file %d\n' % i)
            subprocess.run(['git', 'init', '-q', str(repo)], check=True)
            index = Path(tmp) / 'index'
            env = dict(os.environ, GIT_INDEX_FILE=str(index))

            def git(*args, **kw):
                return subprocess.run(['git', *args], cwd=repo, env=env, capture_output=True, text=True, **kw)

            files = [docs / n for n in names]
            self.assertIsNone(stage_files(git, docs, files))
            staged = sorted(git('ls-files', '-s').stdout.splitlines())
            expected = []
            for i, name in enumerate(names):
                blob = git('hash-object', '-w', str(docs / name)).stdout.strip()
                expected.append('100644 %s 0\t%s' % (blob, name))
            self.assertEqual(staged, sorted(expected))

    def test_empty_list_and_failure_are_reported(self):
        from roc.server import stage_files
        self.assertIsNone(stage_files(lambda *a, **k: None, Path('.'), []))

        class Bad:
            returncode, stdout, stderr = 1, '', 'boom'
        self.assertIn('boom', stage_files(lambda *a, **k: Bad(), Path('.'), [Path('x')]))


if __name__ == '__main__':
    unittest.main()
