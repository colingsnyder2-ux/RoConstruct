import importlib.util
import json
import os
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
    def test_reviewed_global_reference_checks_symbol_base_and_addend(self):
        import struct
        raw = struct.pack('<IIH', 1, 0, 6)
        section = (0, 0, 0, 0, 0, 0, 0, 1)
        symbols = {0: ('?vector', 0, 0, 0)}
        definitions = {'_caller': (0, 0)}
        body = bytes.fromhex('b8 04000000 c3')
        target = bytes.fromhex('b8 7c563412 c3')
        expected = [{'offset': 1, 'target': '12345678', 'symbol': '?vector',
                     'addend': 4, 'evidence': 'reviewed base and vector field'}]
        with patch.object(runner.match, '_coff_data_index', return_value=([section], symbols, definitions, None)):
            self.assertTrue(runner.check_noncall_refs(raw, '_caller', body, target, [], [], expected)['passed'])
            self.assertFalse(runner.check_noncall_refs(raw, '_caller', body, target, [], [],
                                                       [dict(expected[0], addend=0)])['passed'])
            self.assertFalse(runner.check_noncall_refs(raw, '_caller', body, target, [], [],
                                                       [dict(expected[0], target='1234567c')])['passed'])

    def test_unreviewed_global_relocation_blocks_reference_proof(self):
        import struct
        raw = struct.pack('<IIH', 1, 0, 6)
        sections = [(0, 0, 0, 0, 0, 0, 0, 1)]
        symbols = {0: ('?version@API@@', 0, 0, 0)}
        definitions = {'_caller': (0, 0)}
        original = bytes.fromhex('b8 78563412 c3')
        compiled = bytes.fromhex('b8 00000000 c3')
        expectation = [{'offset': 1, 'target': '12345678', 'symbol': '?version@API@@',
                        'evidence': 'independently identified global'}]
        with patch.object(runner.match, '_coff_data_index', return_value=(sections, symbols, definitions, None)):
            self.assertFalse(runner.check_noncall_refs(raw, '_caller', compiled, original, [], [], [])['passed'])
            self.assertTrue(runner.check_noncall_refs(raw, '_caller', compiled, original, [], [], expectation)['passed'])
            self.assertFalse(runner.check_noncall_refs(raw, '_caller', compiled, original, [], [],
                                                       [dict(expectation[0], symbol='?other@@')])['passed'])

    def test_only_verified_readonly_constants_are_implicitly_covered(self):
        import struct
        raw = struct.pack('<IIH', 1, 0, 6)
        code = (0, 0, 0, 0, 0, 0, 0, 1, 0, 0x20)
        readonly = (0, 0, 0, 0, 0, 0, 0, 0, 0, 0x40)
        writable = (*readonly[:9], 0x80000040)
        symbols = {0: ('constant', 0, 2, 0)}
        definitions = {'_caller': (0, 0)}
        target = bytes.fromhex('b8 78563412 c3')
        body = bytes.fromhex('b8 00000000 c3')
        ref = (1, b'constant', [])
        with patch.object(runner.match, '_coff_data_index', return_value=([code, readonly], symbols, definitions, None)), \
             patch.object(runner.match, 'data_check', return_value=([(0x12345678, 8)], [])):
            self.assertTrue(runner.check_noncall_refs(raw, '_caller', body, target, [ref], [], [], 0x1000)['passed'])
            self.assertFalse(runner.check_noncall_refs(raw, '_caller', body, target, [(1, b'constant', [0])], [], [], 0x1000)['passed'])
        with patch.object(runner.match, '_coff_data_index', return_value=([code, writable], symbols, definitions, None)), \
             patch.object(runner.match, 'data_check', return_value=([(0x12345678, 8)], [])):
            self.assertFalse(runner.check_noncall_refs(raw, '_caller', body, target, [ref], [], [], 0x1000)['passed'])
        with patch.object(runner.match, '_coff_data_index', return_value=([code, readonly], symbols, definitions, None)), \
             patch.object(runner.match, 'data_check', return_value=([], [])):
            self.assertFalse(runner.check_noncall_refs(raw, '_caller', body, target, [ref], [], [], 0x1000)['passed'])

    def test_local_labels_and_imported_data_need_exact_identity(self):
        import struct
        raw = struct.pack('<IIH', 1, 0, 6)
        text = (0, 0, 0, 0, 0, 0, 0, 1, 0, 0x20)
        body = bytes.fromhex('b8 06000000 c3 90')
        target = bytes.fromhex('b8 06100000 c3 90')
        defs = {'_caller': (0, 0)}
        with patch.object(runner.match, '_coff_data_index', return_value=([text], {0: ('$LN1', 0, 1, 0)}, defs, None)):
            self.assertTrue(runner.check_noncall_refs(raw, '_caller', body, target, [], [], [], 0x1000)['passed'])
            wrong = bytes.fromhex('b8 07100000 c3 90')
            self.assertFalse(runner.check_noncall_refs(raw, '_caller', body, wrong, [], [], [], 0x1000)['passed'])
        symbols = {0: ('__imp__global', 0, 0, 0)}
        imports = ({0x802000: 'TEST.dll!global'}, {('test.dll', 'global'): {'__imp__global'}}, {})
        target = bytes.fromhex('b8 00208000 c3')
        body = bytes.fromhex('b8 00000000 c3')
        with patch.object(runner.match, '_coff_data_index', return_value=([text], symbols, defs, None)), \
             patch.object(runner, 'import_evidence', return_value=imports):
            self.assertTrue(runner.check_noncall_refs(raw, '_caller', body, target, [], [], [], 0x1000)['passed'])
            self.assertFalse(runner.check_noncall_refs(raw, '_caller', body, bytes.fromhex('b8 04208000 c3'), [], [], [], 0x1000)['passed'])
    def test_register_import_requires_dominating_unclobbered_load(self):
        # mov edi,[0x802000]; call edi; ret
        code = bytes.fromhex('8b3d00208000 ffd7 c3')
        self.assertTrue(runner.register_import_flow(code, 0x1000, 0, 6, 'edi'))
        # A branch can bypass the load and reach the call.
        bypass = bytes.fromhex('eb06 8b3d00208000 ffd7 c3')
        self.assertFalse(runner.register_import_flow(bypass, 0x1000, 2, 8, 'edi'))
        # A register write invalidates the loaded pointer.
        clobbered = bytes.fromhex('8b3d00208000 31ff ffd7 c3')
        self.assertFalse(runner.register_import_flow(clobbered, 0x1000, 0, 8, 'edi'))
        # Indirect branches make reachability unknowable; caller-saved registers are unsafe.
        unknown_jump = bytes.fromhex('8b3d00208000 ffe0 ffd7 c3')
        self.assertFalse(runner.register_import_flow(unknown_jump, 0x1000, 0, 8, 'edi'))
        self.assertFalse(runner.register_import_flow(code, 0x1000, 0, 6, 'eax'))

    def test_register_import_checks_iat_alias_relocation_and_all_call_paths(self):
        import struct
        raw = struct.pack('<IIH', 2, 0, 6)
        sections = [(0, 0, 0, 0, 0, 0, 0, 1)]
        symbols = [('__imp__rand',)]
        definitions = {'_caller': (0, 0)}
        original = bytes.fromhex('8b3d00208000 ffd7 ffd7 c3')
        compiled = bytes.fromhex('8b3d00000000 ffd7 ffd7 c3')
        expected = [{'offset': n, 'load_offset': 0, 'target': '00802000', 'symbol': '__imp__rand',
                     'kind': 'import_reg', 'import': 'MSVCR90.dll!rand'} for n in (6, 8)]
        imports = ({0x802000: 'MSVCR90.dll!rand'}, {('msvcr90.dll', 'rand'): {'__imp__rand'}}, {})
        with patch.object(runner.match, '_coff_data_index', return_value=(sections, symbols, definitions, None)), \
             patch.object(runner, 'import_evidence', return_value=imports):
            self.assertTrue(runner.check_calls(raw, '_caller', compiled, original, 0x1000, expected)['passed'])
            self.assertFalse(runner.check_calls(raw, '_caller', compiled, original, 0x1000,
                                                [dict(e, symbol='__imp__wrong') for e in expected])['passed'])
            self.assertFalse(runner.check_calls(raw, '_caller', compiled, original, 0x1000,
                                                [dict(e, target='00802004') for e in expected])['passed'])
            self.assertFalse(runner.check_calls(struct.pack('<IIH', 2, 0, 20), '_caller', compiled,
                                                original, 0x1000, expected)['passed'])
            self.assertFalse(runner.check_calls(raw, '_caller', compiled, original, 0x1000,
                                                expected[:1])['passed'])
            self.assertFalse(runner.check_calls(raw, '_caller', original, original, 0x1000, expected)['passed'])
            self.assertFalse(runner.check_calls(raw, '_caller', compiled, original, 0x1000,
                                                [dict(e, **{'import': 'MSVCR90.dll!srand'}) for e in expected])['passed'])

    def test_oleaut_ordinal_import_matches_system_export(self):
        sdk = runner.rebuild.toolchain(21022).get('sdk_lib')
        if not sdk or not (Path(sdk) / 'OleAut32.Lib').is_file():
            self.skipTest('VC9 SDK OleAut32 import library unavailable')
        labels, aliases, hashes = runner.import_evidence()
        self.assertEqual(labels[0x802938].lower(), 'oleaut32.dll!varui4fromstr')
        self.assertIn('__imp__VarUI4FromStr@16', aliases[('oleaut32.dll', 'VarUI4FromStr')])
        self.assertIn(str(Path(sdk) / 'OleAut32.Lib'), hashes)
        self.assertTrue(any(Path(path).name.lower() == 'oleaut32.dll' for path in hashes))

    def test_reviewed_tail_jump_checks_target_opcode_and_relocation(self):
        import struct
        raw = struct.pack('<IIH', 1, 0, 20)
        sections = [(0, 0, 0, 0, 0, 0, 0, 1)]
        symbols = [('_callee',)]
        defs = {'_caller': (0, 0)}
        target = b'\xe9\x0b\x00\x00\x00'
        body = b'\xe9\x00\x00\x00\x00'
        expected = [{'offset': 0, 'target': '00001010', 'symbol': '_callee', 'kind': 'jump'}]
        with patch.object(runner.match, '_coff_data_index', return_value=(sections, symbols, defs, None)):
            self.assertTrue(runner.check_calls(raw, '_caller', body, target, 0x1000, expected)['passed'])
            self.assertFalse(runner.check_calls(raw, '_caller', body, target, 0x1000, [])['passed'])
            self.assertFalse(runner.check_calls(raw, '_caller', b'\xe8'+body[1:], target, 0x1000, expected)['passed'])
            self.assertFalse(runner.check_calls(raw, '_caller', body, target, 0x1000, [dict(expected[0], target='00001011')])['passed'])
            self.assertFalse(runner.check_calls(raw, '_caller', body, target, 0x1000, [dict(expected[0], symbol='_wrong')])['passed'])
            self.assertFalse(runner.check_calls(struct.pack('<IIH', 1, 0, 6), '_caller', body, target, 0x1000, expected)['passed'])
            self.assertFalse(runner.check_calls(raw, '_caller', body, b'\xeb\x0e', 0x1000, expected)['passed'])

    def test_registry_import_alias_is_checked_against_sdk_library(self):
        sdk = runner.rebuild.toolchain(21022).get('sdk_lib')
        if not sdk or not (Path(sdk) / 'Advapi32.Lib').is_file():
            self.skipTest('VC9 SDK Advapi32 import library unavailable')
        labels, aliases, hashes = runner.import_evidence()
        self.assertEqual(labels[0x802020].lower(), 'advapi32.dll!regqueryvalueexa')
        self.assertIn('__imp__RegQueryValueExA@24', aliases[('advapi32.dll', 'RegQueryValueExA')])
        self.assertIn(str(Path(sdk) / 'Advapi32.Lib'), hashes)

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
            source = root / 'src' / 'Foo.cpp'
            source.parent.mkdir()
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

    def test_compile_cache_reuses_object_only_while_inputs_match(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            source, header = root / 'src' / 'Foo.cpp', root / 'src' / 'used.h'
            source.parent.mkdir()
            source.write_text('#include "used.h"\nvoid foo() {}')
            header.write_text('// first')
            # A freshly created Windows file can share the runner's start tick.
            # The cache baseline represents an input from before compilation.
            os.utime(header, ns=(1_000_000_000, 1_000_000_000))
            job = {'source': str(source), 'checks': [], 'ranges': [], 'layouts': []}
            calls = []
            def compiler(tc, tool, flags, cwd):
                calls.append(1)
                Path(next(flag[3:] for flag in flags if flag.startswith('/Fo'))).write_bytes(b'object')
                return 0, 'Note: including file: ' + str(header)
            def analysis(job, obj):
                return {'checks': [], 'coverage': [], 'layouts': []}
            # Keep this cache test independent of concurrently edited repository
            # include trees; used.h and the compiler's source directory are real.
            with patch.object(runner, 'compiler_flags', return_value=['/nologo', '/c', '/O2', '/I' + str(source.parent)]), \
                 patch.dict(runner.os.environ, {'CL': '', '_CL_': '', 'INCLUDE': ''}), \
                 patch.object(runner, 'CACHE', root / 'cache'), \
                 patch.object(runner.rebuild, 'run', side_effect=compiler), \
                 patch.object(runner, 'analyze_object', side_effect=analysis):
                first = runner.compile_job(job, root / 'unit-1', {})
                second = runner.compile_job(job, root / 'unit-2', {})
                self.assertEqual(first['status'], 'complete', first.get('error'))
                self.assertFalse(first['cache_hit'])
                self.assertTrue(second['cache_hit'])
                self.assertEqual(len(calls), 1)
                header.write_text('// changed')
                third = runner.compile_job(job, root / 'unit-3', {})
            self.assertFalse(third['cache_hit'])
            self.assertEqual(len(calls), 2)

    def test_compile_cache_invalidates_on_new_higher_priority_header(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            source = root / 'src' / 'Foo.cpp'
            source.parent.mkdir()
            source.write_text('void foo() {}')
            job = {'source': str(source), 'checks': [], 'ranges': [], 'layouts': []}
            calls = []
            def compiler(tc, tool, flags, cwd):
                calls.append(1)
                Path(next(flag[3:] for flag in flags if flag.startswith('/Fo'))).write_bytes(b'object')
                return 0, ''
            with patch.object(runner, 'CACHE', root / 'cache'), \
                 patch.object(runner.rebuild, 'run', side_effect=compiler), \
                 patch.object(runner, 'analyze_object', return_value={'checks': [], 'coverage': [], 'layouts': []}):
                runner.compile_job(job, root / 'unit-1', {})
                (root / 'src' / 'new.h').write_text('// shadows newly added include')
                result = runner.compile_job(job, root / 'unit-2', {})
            self.assertFalse(result['cache_hit'])
            self.assertEqual(len(calls), 2)

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

    def test_index_requires_fresh_complete_proof_and_never_overwrites(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            base = root / 'rebuild/2008-06'
            source = base / 'native-classes/Foo.cpp'
            source.parent.mkdir(parents=True)
            source.write_text('void foo() {}')
            obj = root / 'candidate.obj'
            obj.write_bytes(b'object')
            output = root / 'work/2008-06/shared-layouts/checked.json'
            output.parent.mkdir(parents=True)
            row = {'addr': '00400000', 'symbol': '?foo@@YAXXZ', 'status': 'exact',
                   'data_errors': [], 'data_matches': [], 'metrics': {'raw_positional_percent': 100.0},
                   'call_identity': {'passed': True, 'calls': []},
                   'reference_identity': {'passed': True, 'references': []}}
            analysis = [{'source': str(source), 'object': str(obj), 'changed_inputs': [], 'checks': [row]}]
            receipt = {'source': str(source), 'object': str(obj), 'status': 'complete',
                       'source_sha256': runner.sha(source), 'object_sha256': runner.sha(obj),
                       'dependencies': {str(source): runner.sha(source)}}
            with patch.object(runner, 'ROOT', root), patch.object(runner, 'BASE', base), \
                 patch.object(runner, 'build_changes', return_value=[]):
                runner.index_inactive(analysis, {str(source).casefold(): receipt}, {}, output, root / 'analysis.json')
                saved = json.loads(output.read_text())
                self.assertEqual(saved['checks'][0]['address'], '00400000')
                self.assertTrue(saved['checks'][0]['exact'])
                with self.assertRaises(FileExistsError):
                    runner.index_inactive(analysis, {str(source).casefold(): receipt}, {}, output, root / 'analysis.json')
                source.write_text('changed')
                with self.assertRaisesRegex(ValueError, 'changed'):
                    runner.index_inactive(analysis, {str(source).casefold(): receipt}, {}, output.with_name('stale.json'), root / 'analysis.json')
                source.write_text('void foo() {}')
                row['call_identity']['passed'] = False
                with self.assertRaises(SystemExit):
                    runner.index_inactive(analysis, {str(source).casefold(): receipt}, {}, output.with_name('unverified.json'), root / 'analysis.json')
                self.assertFalse(output.with_name('unverified.json').exists())
                row['call_identity']['passed'] = True
                row['reference_identity']['passed'] = False
                with self.assertRaises(SystemExit):
                    runner.index_inactive(analysis, {str(source).casefold(): receipt}, {}, output.with_name('unknown-global.json'), root / 'analysis.json')
                row['reference_identity']['passed'] = True
                receipt['status'] = 'failed'
                with self.assertRaisesRegex(ValueError, 'not complete'):
                    runner.index_inactive(analysis, {str(source).casefold(): receipt}, {}, output.with_name('failed.json'), root / 'analysis.json')
                receipt['status'] = 'complete'
                with self.assertRaisesRegex(ValueError, 'shared-layouts'):
                    runner.index_inactive(analysis, {str(source).casefold(): receipt}, {}, root / 'outside.json', root / 'analysis.json')


if __name__ == '__main__':
    unittest.main()
