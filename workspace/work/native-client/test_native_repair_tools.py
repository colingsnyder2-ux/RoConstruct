import json
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch
import native_repair_tools as tools


class RepairToolTests(unittest.TestCase):
    def test_score_zero_requires_exact_bytes_and_relocations(self):
        with patch.object(tools.match, 'target', return_value=(b'abcdef', {1}, None)), \
             patch.object(tools, 'function', return_value=(b'abcdef', {1})):
            self.assertEqual(0, tools.score('unused', '00400000', 'symbol'))
        with patch.object(tools.match, 'target', return_value=(b'abcdef', {1}, None)), \
             patch.object(tools, 'function', return_value=(b'abcdef', set())):
            self.assertGreater(tools.score('unused', '00400000', 'symbol'), 0)
        with patch.object(tools.match, 'target', return_value=(b'abcdef', set(), None)), \
             patch.object(tools, 'function', return_value=(b'abcdeg', set())):
            self.assertGreater(tools.score('unused', '00400000', 'symbol'), 0)

    def test_context_mismatch_never_launches_permuter(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            source = root / 'source.cpp'
            source.write_text('void f() {}')
            completed = tools.subprocess.CompletedProcess([], 0, '', '')
            with patch.object(tools, 'OUTPUT', root / 'runs'), \
                 patch.object(tools, 'tool', return_value=root / 'tool.exe'), \
                 patch.object(tools, 'bounded', return_value=completed) as run, \
                 patch.object(tools, 'function', side_effect=[(b'a', set()), (b'b', set())]):
                with self.assertRaisesRegex(RuntimeError, 'scratch compile differs'):
                    tools.permute(source, '00400000', 'symbol', 'Thing::method', 2, 20)
            self.assertEqual(2, run.call_count)
            self.assertEqual('void f() {}', source.read_text())

    def test_budget_and_shell_validation(self):
        with tempfile.TemporaryDirectory() as folder:
            source = Path(folder) / 'source.cpp'
            source.write_text('void f() {}')
            with self.assertRaises(ValueError):
                tools.permute(source, '00400000', 'symbol', 'Thing::method', 201, 20)
            with self.assertRaises(ValueError):
                tools.permute(source, '00400000', 'symbol', 'Thing::method', 2, 1501)
        with self.assertRaises(ValueError):
            tools.shell_quote('bad&command')

    def test_diff_labels_omitted_relocations(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            obj = root / 'candidate.obj'
            obj.write_bytes(b'object')
            completed = tools.subprocess.CompletedProcess([], 0, '', '')
            with patch.object(tools.match, 'target', return_value=(b'abcdef', {1}, None)), \
                 patch.object(tools, 'function', return_value=(b'abcdef', {1})), \
                 patch.object(tools, 'tool', return_value=root / 'objdiff.exe'), \
                 patch.object(tools, 'bounded', return_value=completed):
                receipt = tools.diff_object('00400000', 'symbol', obj, root / 'out')
            self.assertEqual(1, receipt['original_relocations_omitted'])
            self.assertIn('not exact or reference proof', receipt['scope'])
            self.assertTrue((root / 'out/original-diagnostic.obj').is_file())

    def test_setup_never_replaces_an_existing_different_binary(self):
        with tempfile.TemporaryDirectory() as folder:
            objdiff = Path(folder) / 'objdiff.exe'
            objdiff.write_bytes(b'user file')
            with patch.dict(tools.DEFAULTS, {'objdiff': objdiff}):
                with self.assertRaisesRegex(RuntimeError, 'not replacing'):
                    tools.setup(10)
            self.assertEqual(b'user file', objdiff.read_bytes())


if __name__ == '__main__':
    unittest.main()
