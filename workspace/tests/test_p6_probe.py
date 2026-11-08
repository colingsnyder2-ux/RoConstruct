import importlib.util
import json
import os
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[1]
SCRIPT = ROOT / 'rebuild/2008-06/tests/p6_probe.py'
spec = importlib.util.spec_from_file_location('p6_probe', SCRIPT)
probe = importlib.util.module_from_spec(spec)
spec.loader.exec_module(probe)


class ProbeTests(unittest.TestCase):
    def test_shared_header_change_prevents_build_launch(self):
        with tempfile.TemporaryDirectory() as temporary:
            run, builder, plan = self.fixture(temporary, '')
            plan['shared_headers'] = {'core.h': 'old'}
            probe.save(run / 'plan.json', plan)
            with patch.object(probe.native_work, 'headers', return_value={'core.h': 'new'}), \
                 patch.object(probe.subprocess, 'Popen') as launch:
                result = probe.run_probe(run, builder, Path(temporary) / 'locks')
            launch.assert_not_called()
            self.assertIn('shared headers changed since preflight', result['error'])

    def test_linked_output_with_mixed_headers_is_not_accepted(self):
        script = '''import sys
from pathlib import Path
out=Path(sys.argv[sys.argv.index('--native-doc-out')+1])
(out/'native-doc-link.log').write_text('fixture link success')
(out/'RobloxNativeDoc.exe').write_bytes(b'fixture never executed')
'''
        with tempfile.TemporaryDirectory() as temporary:
            run, builder, _ = self.fixture(temporary, script)
            with patch.object(probe.native_work, 'headers', side_effect=[{'core.h': 'old'}, {'core.h': 'old'}, {'core.h': 'new'}]):
                result = probe.run_probe(run, builder, Path(temporary) / 'locks')
            self.assertEqual(result['outcome'], 'inputs_changed')
            self.assertEqual(result['link_outcome'], 'linked')
            self.assertEqual(result['changed_shared_headers'], ['core.h'])

    def fixture(self, folder, script):
        root = Path(folder)
        builder = root / 'builder with spaces.py'
        builder.write_text(script, encoding='utf-8')
        run = root / 'run'
        run.mkdir()
        extra = root / 'extra with spaces.cpp'
        extra.write_text('// test')
        plan = {'extras': [str(extra)], 'extra_hashes': {str(extra): probe.sha(extra)},
                'snapshot': str(root / 'snapshot with spaces'), 'cache': False, 'builder_sha256': probe.sha(builder)}
        probe.save(run / 'plan.json', plan)
        return run, builder, plan

    def test_preflight_resolves_deduplicates_and_checks_prerequisites(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            base = root / 'rebuild/2008-06'
            snapshot = base / 'out'
            runtime = snapshot / 'tests/P2RecoveredPlayer'
            for name in ('Content', 'Places'):
                (runtime / name).mkdir(parents=True)
            files = [runtime / n for n in ('rgmain.dll', 'rgdx.dll', 'fmodex.dll')]
            files += [root / 'clients/2008-06' / n for n in ('Roblox.exe', 'SciLexer.dll', 'ReflectionMetadata.xml')]
            files += [snapshot / n / 'linked/linked.lib' for n in ('Engine', 'XTP')]
            builder, extra = root / 'build.py', root / 'extra with spaces.cpp'
            files += [builder, extra]
            for file in files:
                file.parent.mkdir(parents=True, exist_ok=True)
                file.touch()
            with patch.object(probe, 'ROOT', root), patch.object(probe, 'BASE', base), patch.object(probe, 'BUILDER', builder), patch.object(probe.rebuild, 'load_module', return_value={'name': 'Engine'}), patch.object(probe.rebuild, 'toolchain', return_value={k: builder for k in ('cl', 'link', 'vc_include', 'sdk_include')}):
                result = probe.preflight({'extras': [extra.name, extra.name]})
                self.assertEqual(result['extras'], [str(extra.resolve())])
                self.assertFalse(result['cache'])
                (runtime / 'rgmain.dll').unlink()
                with self.assertRaisesRegex(ValueError, 'rgmain.dll'):
                    probe.preflight({})
                with self.assertRaisesRegex(ValueError, 'extra C\\+\\+'):
                    probe.preflight({'extras': ['missing.cpp']})

    def test_manifest_rejects_typo_and_bad_cache_type(self):
        with self.assertRaisesRegex(ValueError, 'unknown'):
            probe.preflight({'exrta': []})
        with self.assertRaisesRegex(ValueError, 'boolean'):
            probe.preflight({'cache': 'false'})

    def test_compiler_failure_distinct_from_prelink_exception(self):
        self.assertEqual(probe.classify(1, 'a.cpp(2): fatal error C1083: missing', '')['outcome'], 'compile_failed')
        self.assertEqual(probe.classify(1, '', 'Traceback: bad path')['outcome'], 'build_failed_before_link')

    def test_missing_output_or_link_log_never_link_success(self):
        self.assertEqual(probe.classify(0, '', '')['outcome'], 'missing_output')
        self.assertEqual(probe.classify(0, '', '', exe_exists=True)['outcome'], 'missing_link_receipt')

    def test_unresolved_dedup_with_multiple_requesters_and_c_symbol(self):
        line = 'A.obj : error LNK2019: unresolved external symbol "public: void foo(void)" (?foo@@YAXXZ) referenced in function "caller"'
        text = '\n'.join([line, line, line.replace('A.obj', 'B.obj'), 'C.obj : error LNK2001: unresolved external symbol _external'])
        result = probe.classify(1, text, '', text)
        self.assertEqual(result['outcome'], 'link_failed')
        self.assertEqual(len(result['blockers']), 2)
        self.assertEqual(result['blockers'][0]['requesters'], ['A.obj', 'B.obj'])

    def test_duplicate_providers_reported_separately_from_unresolved(self):
        duplicate = 'lib(A.obj) : error LNK2005: "void foo(void)" (?foo@@YAXXZ) already defined in NativeFoo.obj'
        missing = 'B.obj : error LNK2001: unresolved external symbol _missing'
        result = probe.classify(1, duplicate + '\n' + missing, '', duplicate)
        self.assertEqual(len(result['duplicates']), 1)
        self.assertEqual(result['duplicates'][0]['symbol'], '?foo@@YAXXZ')
        self.assertEqual(result['duplicates'][0]['providers'], ['lib(A.obj)', 'NativeFoo.obj'])
        self.assertEqual(len(result['blockers']), 1)
        self.assertEqual(result['outcome'], 'link_failed')

    def test_real_subprocess_success_captures_logs_and_absolute_extras(self):
        script = '''import json,os,sys
from pathlib import Path
out=Path(sys.argv[sys.argv.index('--native-doc-out')+1])
print(json.dumps({'extras':os.environ['ROC_NATIVE_DOC_EXTRA'],'args':sys.argv[1:]}))
print('stderr preserved',file=sys.stderr)
(out/'native-doc-link.log').write_text('link success')
(out/'RobloxNativeDoc.exe').write_bytes(b'fixture, never execute')
'''
        with tempfile.TemporaryDirectory() as temporary:
            run, builder, plan = self.fixture(temporary, script)
            with patch.dict(os.environ, {'ROC_NATIVE_DOC_EXTRA': 'wrong inherited.cpp'}):
                result = probe.run_probe(run, builder, Path(temporary) / 'locks')
            self.assertEqual(result['state'], 'complete')
            self.assertEqual(result['exit_code'], 0)
            stdout = json.loads((run / 'stdout.log').read_text())
            self.assertEqual(stdout['extras'], ';'.join(plan['extras']))
            self.assertEqual(stdout['args'][0], plan['snapshot'])
            self.assertNotIn('--native-doc-cache', stdout['args'])
            self.assertIn('stderr preserved', (run / 'stderr.log').read_text())
            with self.assertRaises(FileExistsError):
                probe.run_probe(run, builder, Path(temporary) / 'locks')

    def test_subprocess_compile_failure_terminal_receipt(self):
        with tempfile.TemporaryDirectory() as temporary:
            run, builder, _ = self.fixture(temporary, "import sys; print('fake.cpp(1): error C2143: bad syntax'); sys.exit(2)")
            result = probe.run_probe(run, builder, Path(temporary) / 'locks')
            self.assertEqual(result['outcome'], 'compile_failed')
            self.assertEqual(result['exit_code'], 2)
            self.assertFalse(result['link_log_present'])
            self.assertTrue((run / 'result.json').exists())

    def test_subprocess_link_failure_saves_blockers(self):
        script = '''import sys
from pathlib import Path
out=Path(sys.argv[sys.argv.index('--native-doc-out')+1])
(out/'native-doc-link.log').write_text('A.obj : error LNK2001: unresolved external symbol _missing')
sys.exit(1)
'''
        with tempfile.TemporaryDirectory() as temporary:
            run, builder, _ = self.fixture(temporary, script)
            result = probe.run_probe(run, builder, Path(temporary) / 'locks')
            self.assertEqual(result['outcome'], 'link_failed')
            self.assertEqual(result['unique_unresolved'], 1)

    def test_real_detached_worker_writes_completion_receipt(self):
        script = '''import sys
from pathlib import Path
out=Path(sys.argv[sys.argv.index('--native-doc-out')+1])
(out/'native-doc-link.log').write_text('fixture link success')
(out/'RobloxNativeDoc.exe').write_bytes(b'fixture never executed')
'''
        with tempfile.TemporaryDirectory() as temporary:
            run, builder, _ = self.fixture(temporary, script)
            program = 'import sys; from pathlib import Path; sys.path.insert(0,sys.argv[1]); import p6_probe; p6_probe.run_probe(Path(sys.argv[2]),Path(sys.argv[3]),Path(sys.argv[4]))'
            options = {'creationflags': subprocess.CREATE_NO_WINDOW | subprocess.CREATE_NEW_PROCESS_GROUP} if os.name == 'nt' else {'start_new_session': True}
            with (run / 'worker.log').open('w') as log:
                worker = subprocess.Popen([sys.executable, '-c', program, str(SCRIPT.parent), str(run), str(builder), str(Path(temporary) / 'locks')],
                                          stdin=subprocess.DEVNULL, stdout=log, stderr=subprocess.STDOUT, close_fds=True, **options)
                self.assertEqual(worker.wait(timeout=30), 0)
            receipt = json.loads((run / 'summary.json').read_text())
            self.assertEqual(receipt['state'], 'complete')
            self.assertEqual(receipt['outcome'], 'linked')

    def test_changed_extra_during_build_invalidates_link_receipt(self):
        script = '''import os,sys
from pathlib import Path
Path(os.environ['ROC_NATIVE_DOC_EXTRA']).write_text('changed during build')
out=Path(sys.argv[sys.argv.index('--native-doc-out')+1])
(out/'native-doc-link.log').write_text('fixture link success')
(out/'RobloxNativeDoc.exe').write_bytes(b'fixture never executed')
'''
        with tempfile.TemporaryDirectory() as temporary:
            run, builder, _ = self.fixture(temporary, script)
            result = probe.run_probe(run, builder, Path(temporary) / 'locks')
            self.assertEqual(result['outcome'], 'inputs_changed')
            self.assertEqual(result['link_outcome'], 'linked')
            self.assertEqual(result['state'], 'failed')

    def test_changed_extra_prevents_launch(self):
        with tempfile.TemporaryDirectory() as temporary:
            run, builder, plan = self.fixture(temporary, '')
            Path(plan['extras'][0]).write_text('changed')
            with patch.object(probe.subprocess, 'Popen') as launch:
                result = probe.run_probe(run, builder, Path(temporary) / 'locks')
            launch.assert_not_called()
            self.assertEqual(result['state'], 'failed')
            self.assertIn('changed since preflight', result['error'])
            self.assertTrue((run / 'stderr.log').exists())

    def test_changed_builder_prevents_launch(self):
        with tempfile.TemporaryDirectory() as temporary:
            run, builder, _ = self.fixture(temporary, '')
            builder.write_text('changed')
            with patch.object(probe.subprocess, 'Popen') as launch:
                result = probe.run_probe(run, builder, Path(temporary) / 'locks')
            launch.assert_not_called()
            self.assertIn('builder changed', result['error'])

    def test_launch_failure_still_has_receipt_and_logs(self):
        with tempfile.TemporaryDirectory() as temporary:
            run, builder, _ = self.fixture(temporary, '')
            with patch.object(probe.subprocess, 'Popen', side_effect=OSError('launch failed')):
                result = probe.run_probe(run, builder, Path(temporary) / 'locks')
            self.assertEqual(result['state'], 'failed')
            self.assertTrue((run / 'stdout.log').exists())
            self.assertTrue((run / 'summary.json').exists())

    def test_shared_build_lock_prevents_second_writer(self):
        with tempfile.TemporaryDirectory() as temporary:
            run, builder, _ = self.fixture(temporary, '')
            locks = Path(temporary) / 'locks'
            with probe.build_lock(locks), patch.object(probe.subprocess, 'Popen') as launch:
                result = probe.run_probe(run, builder, locks)
            launch.assert_not_called()
            self.assertEqual(result['state'], 'failed')

    def test_dead_worker_status_is_terminal(self):
        with tempfile.TemporaryDirectory() as temporary:
            run = Path(temporary)
            probe.save(run / 'summary.json', {'state': 'running', 'pid': 123})
            with patch.object(probe, 'alive', return_value=False), patch('builtins.print'):
                result = probe.status(run)
            self.assertEqual(result['outcome'], 'worker_lost')


class RelinkTests(unittest.TestCase):
    def test_relink_calls_only_linker_and_redirects_outputs(self):
        with tempfile.TemporaryDirectory() as temporary:
            base = Path(temporary)
            (base / 'a.obj').write_bytes(b'object')
            (base / 'link.exe').write_bytes(b'linker')
            command = base / 'command.json'
            command.write_text(json.dumps({'cwd': str(base), 'arguments': [
                '/nologo', '/OUT:old.exe', '/MAP:old.map', 'a.obj']}))
            calls = []
            def run(tc, tool, args, cwd):
                calls.append((tool, args, cwd))
                return 1, 'a.obj : error LNK2001: unresolved external symbol _missing'
            with patch.object(probe.rebuild, 'toolchain', return_value={'link': base / 'link.exe'}), \
                 patch.object(probe.rebuild, 'env', return_value={}), \
                 patch.object(probe.rebuild, 'run', side_effect=run):
                result = probe.relink(command, base / 'runs')
            self.assertEqual([call[0] for call in calls], ['link'])
            self.assertEqual(result['state'], 'failed')
            self.assertEqual(result['unique_unresolved'], 1)
            self.assertEqual(result['compiled_objects'], 0)
            self.assertEqual(result['objects_reused'], 1)
            self.assertTrue(any(a.startswith('/OUT:' + str(base / 'runs')) for a in calls[0][1]))
            self.assertFalse((base / 'old.exe').exists())

    def test_relink_resolves_libpath_before_environment(self):
        with tempfile.TemporaryDirectory() as temporary:
            base = Path(temporary)
            explicit = base / 'explicit'
            implicit = base / 'implicit'
            explicit.mkdir()
            implicit.mkdir()
            (explicit / 'a.lib').write_bytes(b'explicit')
            (implicit / 'a.lib').write_bytes(b'implicit')
            (base / 'link.exe').write_bytes(b'linker')
            command = base / 'command.json'
            command.write_text(json.dumps({'cwd': str(base), 'arguments': [
                '/OUT:old.exe', '/MAP:old.map', '/LIBPATH:explicit', 'a.lib']}))
            with patch.object(probe.rebuild, 'toolchain', return_value={'link': base / 'link.exe'}), \
                 patch.object(probe.rebuild, 'env', return_value={'LIB': str(implicit)}), \
                 patch.object(probe.rebuild, 'run', return_value=(1, 'link failed')):
                result = probe.relink(command, base / 'runs')
            self.assertIn(str(explicit / 'a.lib'), result['inputs'])
            self.assertNotIn(str(implicit / 'a.lib'), result['inputs'])

    def test_relink_rejects_input_changes_during_link(self):
        with tempfile.TemporaryDirectory() as temporary:
            base = Path(temporary)
            obj = base / 'a.obj'
            obj.write_bytes(b'before')
            (base / 'link.exe').write_bytes(b'linker')
            command = base / 'command.json'
            command.write_text(json.dumps({'cwd': str(base), 'arguments': ['/OUT:old.exe', '/MAP:old.map', 'a.obj']}))
            def run(tc, tool, args, cwd):
                obj.write_bytes(b'after')
                return 1, 'link failed'
            with patch.object(probe.rebuild, 'toolchain', return_value={'link': base / 'link.exe'}), \
                 patch.object(probe.rebuild, 'env', return_value={}), \
                 patch.object(probe.rebuild, 'run', side_effect=run):
                result = probe.relink(command, base / 'runs')
            self.assertEqual(result['outcome'], 'inputs_changed')
            self.assertIn(str(obj), result['changed_inputs'])

    def test_relink_rejects_response_file_before_launch(self):
        with tempfile.TemporaryDirectory() as temporary:
            base = Path(temporary)
            command = base / 'command.json'
            command.write_text(json.dumps({'cwd': str(base), 'arguments': ['/OUT:old.exe', '/MAP:old.map', '@args.rsp']}))
            with patch.object(probe.rebuild, 'toolchain', return_value={}), \
                 patch.object(probe.rebuild, 'env', return_value={}), \
                 patch.object(probe.rebuild, 'run') as run:
                with self.assertRaisesRegex(ValueError, 'unsupported link argument'):
                    probe.relink(command, base / 'runs')
            run.assert_not_called()


if __name__ == '__main__':
    unittest.main()
