import json
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

import layout_pipeline


class OverrideSelectTest(unittest.TestCase):
    def test_overrides_load_only_when_the_file_exists(self):
        with tempfile.TemporaryDirectory() as tmp:
            here = Path(tmp)
            (here / 'overrides/client/app').mkdir(parents=True)
            (here / 'overrides/client/app/a.cpp').write_bytes(b'int f();\r\nint g();\r\n')
            (here / 'overrides/manifest.json').write_text(json.dumps({
                'client/app/a.cpp': {'members': ['x/A.cpp', 'x/B.cpp']},
                'client/app/missing.cpp': {'members': ['x/C.cpp']}}))
            with patch.object(layout_pipeline, 'HERE', here):
                got = layout_pipeline.load_overrides()
        self.assertEqual(list(got), ['client/app/a.cpp'])
        self.assertEqual(got['client/app/a.cpp']['text'], 'int f();\nint g();\n')
        self.assertIsNone(got['client/app/a.cpp']['flags'])

    def test_wrapper_does_not_make_its_real_source_a_conflict(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / 'real.cpp').write_bytes(b'int f() { return 1; }\n')
            (root / 'wrap.cpp').write_bytes(b'// native-profile: vendor\n#include "x.i"\n')
            sha = layout_pipeline.layout_export.sha(b'int f() { return 1; }\n')
            group = 'rebuild/2008-06/client/a.cpp'
            rows = {'real.cpp': {'target_path': group, 'evidence': 'pdb', 'sha256': sha, 'merge_group': group},
                    'wrap.cpp': {'target_path': group, 'evidence': 'pdb', 'sha256': 'x', 'merge_group': group}}
            with patch.object(layout_pipeline, 'ROOT', root):
                picked, _inferred, held = layout_pipeline.select(rows)
        self.assertEqual(picked, ['real.cpp'])
        self.assertEqual(held.get('wrapper around donor or library source'), 1)


class WorkersTest(unittest.TestCase):
    def test_runner_gets_the_worker_count(self):
        seen = {}

        def fake_run(argv, **kwargs):
            seen['argv'] = argv
            raise RuntimeError('stop after capturing the command')

        with tempfile.TemporaryDirectory() as tmp, patch.object(layout_pipeline, 'GATE', Path(tmp)),                 patch.object(layout_pipeline, 'WORKERS', 6), patch.object(layout_pipeline.subprocess, 'run', fake_run):
            with self.assertRaises(RuntimeError):
                layout_pipeline.compile_objects([layout_pipeline.ROOT / 'rebuild/2008-06/native-classes/A.cpp'], tag='t')
        argv = seen['argv']
        self.assertEqual(argv[argv.index('--workers') + 1], '6')


if __name__ == '__main__':
    unittest.main()
