import contextlib
import io
import json
import subprocess
import tempfile
import unittest
from pathlib import Path
from types import SimpleNamespace
from unittest.mock import patch
import native_repair_tools as tools
import prove


class ProveObjdiffTests(unittest.TestCase):
    def test_explicit_symbol_generates_diagnostic_after_proof(self):
        with tempfile.TemporaryDirectory() as folder:
            out = Path(folder)
            (out / 'manifest.json').write_text(json.dumps({'families': []}))
            obj = out / 'objects/unit/candidate.obj'
            obj.parent.mkdir(parents=True)
            obj.write_bytes(b'object')
            args = SimpleNamespace(why=None, diff='00400000', objdiff_symbol='?method@Owner@@')
            with patch.object(prove.subprocess, 'run', return_value=subprocess.CompletedProcess([], 0, 'asm', '')), \
                 patch.object(tools, 'run_dir', return_value=out / 'report'), \
                 patch.object(tools, 'diff_object', return_value={'scope': 'diagnostic'}) as diff, \
                 contextlib.redirect_stdout(io.StringIO()) as output:
                prove.report(out, args)
            diff.assert_called_once_with('00400000', '?method@Owner@@', obj, out / 'report')
            self.assertIn('diagnostic', output.getvalue())

    def test_objdiff_failure_does_not_change_proof_result(self):
        with tempfile.TemporaryDirectory() as folder:
            out = Path(folder)
            (out / 'manifest.json').write_text(json.dumps({'families': []}))
            obj = out / 'objects/unit/candidate.obj'
            obj.parent.mkdir(parents=True)
            obj.write_bytes(b'object')
            args = SimpleNamespace(why=None, diff='00400000', objdiff_symbol='symbol')
            with patch.object(prove.subprocess, 'run', return_value=subprocess.CompletedProcess([], 0, 'asm', '')), \
                 patch.object(tools, 'run_dir', side_effect=ValueError('bad address')), \
                 contextlib.redirect_stdout(io.StringIO()) as output:
                prove.report(out, args)
            self.assertIn('objdiff unavailable', output.getvalue())


if __name__ == '__main__':
    unittest.main()
