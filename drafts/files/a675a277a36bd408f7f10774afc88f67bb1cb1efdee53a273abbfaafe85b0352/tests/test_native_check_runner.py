import importlib.util
import json
from pathlib import Path
import tempfile
import sys
import unittest
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[1]
SCRIPT = ROOT / 'rebuild/2008-06/tests/native_check_runner.py'
spec = importlib.util.spec_from_file_location('native_check_runner', SCRIPT)
runner = importlib.util.module_from_spec(spec)
spec.loader.exec_module(runner)


class RunnerTests(unittest.TestCase):
    def test_manifest_compiler_selection_is_explicit_and_validated(self):
        self.assertEqual(runner.compiler_build({}), 21022)
        self.assertEqual(runner.compiler_build({'compiler_build': 50727}), 50727)
        for value in (True, '50727', 12345, None):
            with self.subTest(value=value), self.assertRaises(ValueError):
                runner.compiler_build({'compiler_build': value})

    def test_vc2005_rtm_variant_is_explicit_and_has_its_own_paths(self):
        manifest = {'compiler_build': 50727, 'compiler_variant': 'rtm'}
        with patch.object(runner.rebuild, 'toolchain', return_value={'build': 50727}):
            tc = runner.selected_toolchain(manifest)
        self.assertIn('vc2005', str(tc['cl']))
        self.assertEqual(tc['cl'].name.lower(), 'cl.exe')
        self.assertIn('vc2005', str(tc['vc_include']))
        with self.assertRaises(ValueError):
            runner.selected_toolchain({'compiler_build': 21022, 'compiler_variant': 'rtm'})
        with self.assertRaises(ValueError):
            runner.selected_toolchain({'compiler_build': 50727, 'compiler_variant': 'unknown'})

    def test_execute_uses_persisted_compiler_build(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            compiler = root / 'cl.exe'
            compiler.write_bytes(b'tool')
            runner.save(root / 'manifest.json', {'compiler_build': 50727, 'jobs': []})
            with patch.object(runner.rebuild, 'toolchain', return_value={'cl': compiler}) as tc, \
                 patch.object(runner.native_work, 'headers', return_value={}):
                summary = runner.execute(root, 1)
            tc.assert_called_once_with(50727)
            self.assertEqual(summary['compiler_build'], 50727)

    def test_catch_continuation_reports_separate_full_range_without_promoting_status(self):
        with tempfile.TemporaryDirectory() as temporary:
            obj = Path(temporary) / 'candidate.obj'
            obj.write_bytes(b'fixture')
            job = {'checks': [{'addr': '00500000', 'symbol': '?foo'}], 'ranges': [], 'layouts': []}
            symbols = {0: ('?foo', 0, 1, 0x20), 1: ('__catch$?foo$0', 4, 1, 0x20)}
            index = ([], symbols, {'?foo': (0, 0)}, {})
            with patch.object(runner.match, 'target', return_value=(b'abcd', [], None)), \
                 patch.object(runner.match, 'coff_functions', return_value=[('?foo', b'abcdef', [])]), \
                 patch.object(runner.match, '_coff_data_index', return_value=index), \
                 patch.object(runner.match, '_image', return_value=(0x500000, b'abcdef')), \
                 patch.object(runner.match, '_base_relocs', return_value=set()):
                row = runner.analyze_object(job, obj)['checks'][0]
            self.assertEqual(row['status'], 'different')
            self.assertTrue(row['contiguous_catch_comparison']['relocation_normalized_match'])
            self.assertEqual(row['contiguous_catch_comparison']['metrics']['unmasked_differences'], 0)

    def test_larger_function_without_owned_catch_has_no_continuation_comparison(self):
        with tempfile.TemporaryDirectory() as temporary:
            obj = Path(temporary) / 'candidate.obj'
            obj.write_bytes(b'fixture')
            job = {'checks': [{'addr': '00500000', 'symbol': '?foo'}], 'ranges': [], 'layouts': []}
            symbols = {0: ('?foo', 0, 1, 0x20), 1: ('__catch$?other$0', 4, 1, 0x20)}
            with patch.object(runner.match, 'target', return_value=(b'abcd', [], None)), \
                 patch.object(runner.match, 'coff_functions', return_value=[('?foo', b'abcdef', [])]), \
                 patch.object(runner.match, '_coff_data_index', return_value=([], symbols, {'?foo': (0, 0)}, {})), \
                 patch.object(runner.match, '_image') as image:
                row = runner.analyze_object(job, obj)['checks'][0]
            self.assertNotIn('contiguous_catch_comparison', row)
            image.assert_not_called()

    def test_decimal_diagnostic_score_is_not_positional_byte_percentage(self):
        with tempfile.TemporaryDirectory() as temporary:
            obj = Path(temporary) / 'candidate.obj'
            obj.write_bytes(b'fixture')
            job = {'checks': [{'addr': '00500000', 'symbol': '?foo'}], 'ranges': [], 'layouts': []}
            with patch.object(runner.match, 'target', return_value=(b'abcdef', [], None)), \
                 patch.object(runner.match, 'coff_functions', return_value=[('?foo', b'bcdefa', [])]):
                row = runner.analyze_object(job, obj)['checks'][0]
            self.assertEqual(row['status'], 'different')
            self.assertAlmostEqual(row['score'], 83.333333)
            self.assertEqual(row['legacy_score'], 83)
            self.assertEqual(row['metrics']['positional_percent'], 0)

    def test_masked_similarity_of_100_does_not_grant_exact_without_relocations(self):
        with tempfile.TemporaryDirectory() as temporary:
            obj = Path(temporary) / 'candidate.obj'
            obj.write_bytes(b'fixture')
            job = {'checks': [{'addr': '00500000', 'symbol': '?foo'}], 'ranges': [], 'layouts': []}
            with patch.object(runner.match, 'target', return_value=(b'A1234Z', [1], None)), \
                 patch.object(runner.match, 'coff_functions', return_value=[('?foo', b'A0000Z', [])]), \
                 patch.object(runner.match, 'data_check') as data_check:
                row = runner.analyze_object(job, obj)['checks'][0]
            self.assertEqual(row['status'], 'different')
            self.assertLess(row['score'], 100)
            self.assertEqual(row['metrics']['fuzzy_percent'], 100)
            self.assertEqual(row['metrics']['missing_relocations'], [1])
            data_check.assert_not_called()

    def test_batch_header_drift_invalidates_prior_exact_rows(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            header = root / 'shared.h'
            header.write_text('before')
            runner.save(root / 'manifest.json', {'jobs': [{'source': 'Foo.cpp', 'checks': [
                {'addr': '00500000', 'symbol': '?foo'}]}]})
            compiler = root / 'cl.exe'
            compiler.write_bytes(b'tool')
            def compile_job(*args):
                header.write_text('after')
                return {'source': 'Foo.cpp', 'status': 'complete', 'checks': [
                    {'addr': '00500000', 'requested_symbol': '?foo', 'status': 'exact',
                     'data_errors': []}], 'dependencies': {}}
            with patch.object(runner.rebuild, 'toolchain', return_value={'cl': compiler}), \
                 patch.object(runner, 'compile_job', side_effect=compile_job), \
                 patch.object(runner.native_work, 'headers', side_effect=lambda: {str(header): runner.sha(header)}):
                summary = runner.execute(root, 1)
            self.assertEqual(summary['state'], 'failed')
            self.assertEqual(summary['verified_checks'], 0)
            self.assertEqual(summary['shared_headers_changed'], [str(header)])

    def test_exhausted_function_budget_prevents_another_compile(self):
        with tempfile.TemporaryDirectory() as temporary:
            with patch.object(runner.native_work, 'over_budget', return_value=['00500000']), \
                 patch.object(runner.rebuild, 'run') as compiler:
                result = runner.compile_job({'source': 'Foo.cpp'}, Path(temporary) / 'unit', {})
            compiler.assert_not_called()
            self.assertIn('budget exhausted', result['error'])

    def test_manifest_merges_sources_and_preserves_template_symbol(self):
        with tempfile.TemporaryDirectory() as temporary:
            source = Path(temporary) / 'Foo.cpp'
            source.write_text('// test')
            check = {'addr': '00500000', 'symbol': '?get@?$Thing@VFoo@@'}
            jobs = runner.jobs_from({'jobs': [{'source': str(source), 'checks': [check]},
                                             {'source': str(source), 'checks': [check], 'ranges': ['500000-500010']}]})
            self.assertEqual(len(jobs), 1)
            self.assertEqual(jobs[0]['checks'], [check])
            self.assertEqual(jobs[0]['ranges'], ['500000-500010'])

    def test_layout_requires_explicit_entry_assumption(self):
        with tempfile.TemporaryDirectory() as temporary:
            source = Path(temporary) / 'Foo.cpp'
            source.touch()
            with self.assertRaisesRegex(ValueError, 'thiscall'):
                runner.jobs_from({'jobs': [{'source': str(source), 'layouts': [{'addr': '500000', 'symbol': '?foo'}]}]})

    def test_compile_once_unique_output_and_saved_log(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            source = root / 'Foo.cpp'
            source.write_text('void foo() {}')
            calls = []
            def compiler(tc, tool, flags, cwd):
                calls.append(flags)
                Path(next(s[3:] for s in flags if s.startswith('/Fo'))).write_bytes(b'object')
                return 0, 'full compiler log'
            with patch.object(runner.rebuild, 'run', side_effect=compiler), patch.object(runner, 'analyze_object', return_value={'checks': [], 'coverage': [], 'layouts': []}):
                result = runner.compile_job({'source': str(source)}, root / 'unit', {})
            self.assertEqual(len(calls), 1)
            self.assertEqual(result['status'], 'complete')
            self.assertEqual(Path(result['log']).read_text(), 'full compiler log')
            self.assertEqual(result['object_sha256'], runner.sha(root / 'unit/candidate.obj'))
            self.assertTrue((root / 'unit/receipt.json').exists())

    def test_failed_compiler_never_analyzes_stale_object(self):
        with tempfile.TemporaryDirectory() as temporary:
            source = Path(temporary) / 'Foo.cpp'
            source.touch()
            with patch.object(runner.rebuild, 'run', return_value=(1, 'bad compile')), patch.object(runner, 'analyze_object') as analyze:
                result = runner.compile_job({'source': str(source)}, Path(temporary) / 'unit', {})
            analyze.assert_not_called()
            self.assertEqual(result['status'], 'failed')

    def test_source_mutation_during_compile_fails_receipt(self):
        with tempfile.TemporaryDirectory() as temporary:
            source = Path(temporary) / 'Foo.cpp'
            source.write_text('before')
            def compiler(*args):
                source.write_text('after')
                return 0, ''
            with patch.object(runner.rebuild, 'run', side_effect=compiler), patch.object(runner, 'analyze_object') as analyze:
                result = runner.compile_job({'source': str(source)}, Path(temporary) / 'unit', {})
            analyze.assert_not_called()
            self.assertIn('changed', result['error'])

    def test_same_stem_sources_compile_in_different_directories(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            jobs = [{'source': '/one/Foo.cpp'}, {'source': '/two/Foo.cpp'}]
            runner.save(root / 'manifest.json', {'jobs': jobs})
            compiler = root / 'cl.exe'
            compiler.write_bytes(b'tool')
            folders = []
            def compile_job(job, folder, tc):
                folders.append(folder)
                return {'source': job['source'], 'status': 'complete', 'checks': [], 'coverage': []}
            with patch.object(runner.rebuild, 'toolchain', return_value={'cl': compiler}), patch.object(runner, 'compile_job', side_effect=compile_job) as compile_call:
                summary = runner.execute(root, 2)
            self.assertEqual(compile_call.call_count, 2)
            self.assertEqual(len(set(folders)), 2)
            self.assertEqual(summary['state'], 'complete')
            with self.assertRaises(FileExistsError):
                runner.execute(root, 2)

    def test_coverage_summary_unions_duplicate_analogs(self):
        coverage = {'range': '500000-500010', 'hits': [{'addr': '00500000', 'size': 4}],
                    'missing': [{'addr': '00500004', 'size': 4}]}
        result = {'source': 'Foo.cpp', 'status': 'complete', 'checks': [], 'coverage': [coverage]}
        summary = runner.compact([result, result])
        self.assertEqual(summary['coverage'][0]['matched_functions'], 1)
        self.assertEqual(summary['coverage'][0]['functions'], 2)

    def test_exact_code_with_wrong_data_is_not_verified(self):
        with tempfile.TemporaryDirectory() as temporary:
            obj = Path(temporary) / 'test.obj'
            obj.write_bytes(b'object')
            job = {'checks': [{'addr': '500000', 'symbol': '?foo'}], 'ranges': [], 'layouts': []}
            with patch.object(runner.match, 'coff_functions', return_value=[('?foo', b'body', [])]), \
                 patch.object(runner.match, 'target', return_value=(b'body', [], None)), \
                 patch.object(runner.match, 'exact_match', return_value=True), \
                 patch.object(runner.match, 'score', return_value=100), \
                 patch.object(runner.match, 'coff_data_refs', return_value={}), \
                 patch.object(runner.match, 'data_check', return_value=([], ['wrong literal'])):
                result = runner.analyze_object(job, obj)
            summary = runner.compact([{'status': 'complete', **result}])
            self.assertEqual(summary['exact_checks'], 1)
            self.assertEqual(summary['data_checked'], 1)
            self.assertEqual(summary['verified_checks'], 0)
            self.assertEqual(len(summary['data_mismatches']), 1)

    def test_missing_and_ambiguous_checks_are_not_exact(self):
        with tempfile.TemporaryDirectory() as temporary:
            obj = Path(temporary) / 'test.obj'
            obj.write_bytes(b'object')
            job = {'checks': [{'addr': '500000', 'symbol': '?missing'}, {'addr': '500000', 'symbol': '?foo'}], 'ranges': [], 'layouts': []}
            with patch.object(runner.match, 'coff_functions', return_value=[('?foo1', b'', []), ('?foo2', b'', [])]), patch.object(runner.match, 'target', return_value=(b'', [], None)):
                result = runner.analyze_object(job, obj)
            self.assertEqual([r['status'] for r in result['checks']], ['missing', 'ambiguous'])

    def test_dead_worker_is_reported_without_hanging(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            runner.save(root / 'summary.json', {'state': 'running', 'pid': 123})
            with patch.object(runner, 'alive', return_value=False), patch('builtins.print'):
                summary = runner.display(root)
            self.assertEqual(summary['state'], 'failed')

    def test_float_profile_allowed_but_output_override_rejected(self):
        with tempfile.TemporaryDirectory() as temporary:
            source = Path(temporary) / 'Foo.cpp'
            source.touch()
            with patch.dict('os.environ', {'NATIVE_FLAGS': '/O2 /fp:fast'}):
                self.assertIn('/fp:fast', runner.compiler_flags(source))
            with patch.dict('os.environ', {'NATIVE_FLAGS': '/O2 /FoOTHER.obj'}):
                with self.assertRaisesRegex(ValueError, 'output'):
                    runner.compiler_flags(source)

    def test_analyze_reuses_hash_verified_object_without_compiling(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            source, obj = root / 'Foo.cpp', root / 'candidate.obj'
            source.touch()
            obj.write_bytes(b'compiled')
            runner.save(root / 'manifest.json', {'jobs': [{'source': str(source)}]})
            runner.save(root / 'results.json', [{'source': str(source), 'object': str(obj), 'object_sha256': runner.sha(obj),
                                               'status': 'complete', 'dependencies': {str(source): runner.sha(source)}}])
            with patch.object(sys, 'argv', [str(SCRIPT), 'analyze', str(root)]), patch.object(runner.rebuild, 'run') as compile_call, patch.object(runner, 'analyze_object', return_value={}), patch('builtins.print'):
                runner.main()
                compile_call.assert_not_called()
                obj.write_bytes(b'changed')
                with self.assertRaisesRegex(ValueError, 'object failed or changed'):
                    runner.main()


if __name__ == '__main__':
    unittest.main()
