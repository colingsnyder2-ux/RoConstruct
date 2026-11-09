from pathlib import Path
import json
from importlib.util import find_spec
import tempfile
from types import SimpleNamespace
import unittest
from unittest.mock import patch

from roc import native_accel


class NativeAccelTests(unittest.TestCase):
    def test_ninja_path_and_command_reject_shell_injection(self):
        self.assertEqual(native_accel.ninja_path('C:/a b/x.cpp'), 'C$:/a$ b/x.cpp')
        with self.assertRaises(ValueError):
            native_accel.compiler_command(['cl.exe', '/DTEST=1&bad'])
        with self.assertRaises(ValueError):
            native_accel.compiler_command(['cl.exe', '/DTEST=%SECRET%'])
        with self.assertRaises(ValueError):
            native_accel.ninja_path('bad\npath')

    def test_symbol_index_finds_provider_without_claiming_link(self):
        with tempfile.TemporaryDirectory() as temp:
            a, b = Path(temp) / 'a.obj', Path(temp) / 'b.obj'
            a.touch(); b.touch()
            responses = [SimpleNamespace(stdout='a.obj: ?name@@ U 0 0\na.obj: local t 0 0\n'),
                         SimpleNamespace(stdout='b.obj: ?name@@ T 0 0\n')]
            with patch('roc.native_accel.subprocess.run', side_effect=responses):
                report = native_accel.index_symbols('llvm-nm', [a, b])
            self.assertEqual(report['undefined']['?name@@']['callers'], ['a.obj'])
            self.assertEqual(report['undefined']['?name@@']['available_providers'], ['b.obj'])
            self.assertNotIn('local', report['undefined'])

    def test_merge_refuses_existing_output(self):
        with tempfile.TemporaryDirectory() as temp:
            paths = [Path(temp) / str(i) for i in range(4)]
            for path in paths:
                path.touch()
            with self.assertRaises(ValueError):
                native_accel.merge('mergiraf', *paths)

    def test_ninja_refuses_non_owned_build_directory(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            folder = root / 'work/native-ninja/existing'
            folder.mkdir(parents=True)
            ninja = root / 'ninja.exe'
            ninja.touch()
            with self.assertRaisesRegex(ValueError, 'not a RoConstruct'):
                native_accel.compile_sources(root, [], folder, ninja, 1)

    def test_ninja_refuses_concurrent_use_of_same_directory(self):
        from roc.native_drafts import lock
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            folder = root / 'work/native-ninja/owned'
            folder.mkdir(parents=True)
            (folder / '.roc-native-ninja').touch()
            ninja = root / 'ninja.exe'
            ninja.touch()
            with lock(folder / '.build.lock'):
                with self.assertRaisesRegex(RuntimeError, 'Already running'):
                    native_accel.compile_sources(root, [], folder, ninja, 1)

    def test_batch_isolates_errors_and_records_candidates(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            paths = [root / name for name in ('base', 'left', 'right')]
            for path in paths:
                path.write_text(path.name)
            plan = root / 'plan.json'
            good = dict(zip(('base', 'left', 'right'), map(str, paths)))
            bad = dict(good, left=str(root / 'missing'))
            plan.write_text(json.dumps({'items': [good, bad]}))
            def fake_merge(tool, base, left, right, output):
                output.write_text('merged')
                return {'input_sha256': {str(p): native_accel.sha(p) for p in (base, left, right)},
                        'output': str(output), 'output_sha256': native_accel.sha(output),
                        'conflicts': False, 'exit_code': 0, 'log': ''}
            with patch('roc.native_accel.merge', side_effect=fake_merge):
                result = native_accel.merge_batch('mergiraf', plan, root / 'out', 2)
            self.assertEqual((result['files'], result['changed'], result['errors']), (2, 1, 1))
            self.assertTrue((root / 'out/000.cpp').is_file())
            with self.assertRaises(FileExistsError):
                native_accel.merge_batch('mergiraf', plan, root / 'out', 1)

    @unittest.skipUnless(find_spec('tree_sitter') and find_spec('tree_sitter_cpp'), 'optional C++ parser not installed')
    def test_method_diff_flags_removed_changed_and_added_bodies(self):
        before = b'namespace RBX { int Foo::a() {return 1;} int Foo::b() {return 2;} }'
        after = b'namespace RBX { int Foo::a() {return 3;} int Foo::c() {return 4;} }'
        result = native_accel.method_diff(before, after)
        self.assertEqual((len(result['added']), len(result['missing']), len(result['changed'])), (1, 1, 1))


if __name__ == '__main__':
    unittest.main()
