import subprocess
from pathlib import Path
import tempfile
import unittest

from roc import draft_fork, native_drafts


class DraftForkTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        subprocess.run(['git', 'init', '-q'], cwd=self.root, check=True)
        subprocess.run(['git', 'config', 'user.email', 'test@example.com'], cwd=self.root, check=True)
        subprocess.run(['git', 'config', 'user.name', 'Test'], cwd=self.root, check=True)

    def commit(self, name, text):
        path = self.root / name
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(text)
        subprocess.run(['git', 'add', '--', name], cwd=self.root, check=True)
        subprocess.run(['git', 'commit', '-q', '-m', name], cwd=self.root, check=True)
        return subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=self.root, text=True).strip()

    def test_imports_pinned_text_delta_and_is_idempotent(self):
        base = self.commit('rebuild/2008-06/native-classes/Foo.cpp', 'int old;\n')
        target = self.commit('rebuild/2008-06/native-classes/Foo.cpp', 'int improved;\n')
        first = draft_fork.import_commit(self.root, 'example/repo', target, base, 'fork-test')
        second = draft_fork.import_commit(self.root, 'example/repo', target, base, 'fork-test')
        self.assertEqual(first['bundles'], second['bundles'])
        self.assertEqual(first['inserted'], 1)
        self.assertEqual(second['inserted'], 0)
        packet = native_drafts.Inbox(self.root).packet(first['bundles'][0])
        self.assertEqual(packet['baseline'], base)
        self.assertEqual(packet['files']['rebuild/2008-06/native-classes/Foo.cpp'],
                         {'base': 'int old;\n', 'text': 'int improved;\n'})
        self.assertEqual(packet['model'], 'git-fork:example/repo@' + target)

    def test_blocks_unsupported_paths_without_hiding_them(self):
        base = self.commit('rebuild/2008-06/native-classes/Foo.cpp', 'int old;\n')
        target = self.commit('private.bin', 'binary-ish')
        result = draft_fork.import_commit(self.root, 'example/repo', target, base, 'fork-test')
        self.assertEqual(result['bundles'], [])
        self.assertEqual(result['blockers'][0]['path'], 'private.bin')

    def test_can_import_one_pinned_path(self):
        base = self.commit('rebuild/2008-06/native-classes/Foo.cpp', 'int old;\n')
        (self.root / 'rebuild/2008-06/native-classes/Bar.cpp').write_text('int bar;\n')
        (self.root / 'rebuild/2008-06/native-classes/Foo.cpp').write_text('int improved;\n')
        subprocess.run(['git', 'add', '.'], cwd=self.root, check=True)
        subprocess.run(['git', 'commit', '-q', '-m', 'two'], cwd=self.root, check=True)
        target = subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=self.root, text=True).strip()
        result = draft_fork.import_commit(self.root, 'example/repo', target, base, 'fork-test',
                                          paths=['rebuild/2008-06/native-classes/Bar.cpp'])
        packet = native_drafts.Inbox(self.root).packet(result['bundles'][0])
        self.assertEqual(list(packet['files']), ['rebuild/2008-06/native-classes/Bar.cpp'])
        self.assertEqual(result['blockers'], [])

    def test_new_only_excludes_modified_and_already_present_paths(self):
        base = self.commit('rebuild/2008-06/native-classes/Foo.cpp', 'int old;\n')
        (self.root / 'rebuild/2008-06/native-classes/Foo.cpp').write_text('int modified;\n')
        (self.root / 'rebuild/2008-06/native-classes/New.cpp').write_text('int new_file;\n')
        subprocess.run(['git', 'add', '.'], cwd=self.root, check=True)
        subprocess.run(['git', 'commit', '-q', '-m', 'fork additions'], cwd=self.root, check=True)
        target = subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=self.root, text=True).strip()
        (self.root / 'rebuild/2008-06/native-classes/New.cpp').unlink()
        result = draft_fork.import_commit(self.root, 'example/repo', target, base, 'fork-test', new_only=True)
        packet = native_drafts.Inbox(self.root).packet(result['bundles'][0])
        self.assertEqual(list(packet['files']), ['rebuild/2008-06/native-classes/New.cpp'])


if __name__ == '__main__':
    unittest.main()
