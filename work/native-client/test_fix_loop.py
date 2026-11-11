import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch
sys.path.insert(0, str(Path(__file__).resolve().parent))
import fix_loop as fix

class MechanicalFixTests(unittest.TestCase):
    def setUp(self):
        self.directory = tempfile.TemporaryDirectory()
        self.location = patch.object(fix, 'HERE', Path(self.directory.name))
        self.location.start()
        self.addCleanup(self.location.stop)
        self.addCleanup(self.directory.cleanup)

    def test_existing_ogre_header_and_idempotence(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / 'OgreCamera.h').write_text('class Camera {};')
            with patch.object(fix.transplant, 'OGRE_INC', root), patch.object(fix.transplant, 'HEADERS', root):
                error = "error C2065: 'Camera' : undeclared identifier"
                result = fix.includes('#include <vector>\nvoid f();\n', error)
                self.assertIn('#include <vector>\n#include <OgreCamera.h>\n', result)
                self.assertEqual(result, fix.includes(result, error))
    def test_missing_header_not_invented(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            with patch.object(fix.transplant, 'OGRE_INC', root), patch.object(fix.transplant, 'HEADERS', root):
                self.assertEqual('void f();\n', fix.includes('void f();\n', "error C2065: 'UnknownZzz' : undeclared identifier"))
    def test_nomiminmax_before_includes(self):
        result = fix.includes('#include <windows.h>\n', 'error C2589 std::max')
        self.assertTrue(result.startswith('#define NOMINMAX\n#include'))
        self.assertEqual(result, fix.includes(result, 'error C2589 std::max'))
    def test_global_declaration_stays_in_method_namespace(self):
        text = '// 004ef930: transplanted body\nnamespace RBX {\nnamespace ViewNew {\nvoid Part::f() { nativeShadowMode = true; }\n}\n}\n'
        result = fix.inferred_globals(text, "error C2065: 'nativeShadowMode' : undeclared identifier",
                                      'extern bool nativeShadowMode;')
        self.assertIn('namespace ViewNew {\n// INFERRED:', result)
        self.assertIn('extern bool nativeShadowMode;', result)
    def test_unknown_global_type_not_guessed(self):
        text = '// 004ef930: transplanted body\nvoid f() { value = 7; }'
        self.assertEqual(text, fix.inferred_globals(text, "'value' : undeclared identifier", 'value = 7;'))
    def test_member_is_not_global(self):
        text = '// 004ef930: transplanted body\nvoid f() { part->flag = true; }'
        self.assertEqual(text, fix.inferred_globals(text, "'flag' : undeclared identifier", 'extern bool flag;'))
    def test_failed_transplant_restores_exact_original_bytes(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            source = root / 'Native.cpp'
            original = b'// original\r\n'
            source.write_bytes(original)
            def failed(*args):
                source.write_text('broken trial')
                return 'reverted: synthetic compile rejection'
            import subprocess
            with patch.object(fix, 'ROOT', root), patch.object(fix, 'HERE', root), \
                 patch.object(fix.transplant, 'transplant_targets', return_value=[('004ef930', 'RBX::Part', 'Part', 'f', 'Native.cpp')]), \
                 patch.object(fix.transplant, 'transplant', side_effect=failed), \
                 patch.object(fix.subprocess, 'run', return_value=subprocess.CompletedProcess([], 0)) as run:
                result = fix.run_target('004ef930')
                self.assertIn('reverted', result)
                self.assertEqual(original, source.read_bytes())
                self.assertIn('release', run.call_args.args[0])
                self.assertTrue((root / 'fix-loop.jsonl').exists())
    def test_model_reply_rejects_extra_definitions(self):
        import native_llm
        with patch.object(native_llm, 'ask', return_value='void RBX::Part::f() {} void hidden() {}'):
            self.assertIsNone(fix.model_body('test', 'prompt', 'RBX::Part', 'f'))
    def test_model_reply_accepts_one_qualified_method(self):
        import native_llm
        body = 'void RBX::Part::f() { if (ready) { update(); } }'
        with patch.object(native_llm, 'ask', return_value=body):
            self.assertEqual(body, fix.model_body('test', 'prompt', 'RBX::Part', 'f'))
    def test_model_reply_rejects_byte_emission(self):
        import native_llm
        with patch.object(native_llm, 'ask', return_value='void RBX::Part::f() { __asm { _emit 0xc3 } }'):
            self.assertIsNone(fix.model_body('test', 'prompt', 'RBX::Part', 'f'))
    def test_interrupt_restores_source_and_releases_lease(self):
        import subprocess
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            source = root / 'Native.cpp'
            source.write_bytes(b'original\r\n')
            def interrupted(*args):
                source.write_text('partial')
                raise KeyboardInterrupt()
            with patch.object(fix, 'ROOT', root), patch.object(fix, 'HERE', root), \
                 patch.object(fix.transplant, 'transplant_targets', return_value=[('004ef930', 'RBX::Part', 'Part', 'f', 'Native.cpp')]), \
                 patch.object(fix.transplant, 'transplant', side_effect=interrupted), \
                 patch.object(fix.subprocess, 'run', return_value=subprocess.CompletedProcess([], 0)) as run:
                with self.assertRaises(KeyboardInterrupt):
                    fix.run_target('004ef930')
                self.assertEqual(b'original\r\n', source.read_bytes())
                self.assertIn('release', run.call_args.args[0])
    def test_indirect_header_dependents_from_compiler_cache(self):
        import json
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            headers = root / 'headers'
            headers.mkdir()
            header = headers / 'Shared.h'
            header.write_text('')
            source = root / 'Indirect.cpp'
            source.write_text('#include "Other.h"')
            cache = root / 'prove-cache'
            cache.mkdir()
            (cache / 'row.json').write_text(json.dumps({'source': str(source), 'dependencies': {str(header): 'hash'}}))
            with patch.object(fix, 'HERE', root), patch.object(fix.transplant, 'HEADERS', headers), patch.object(fix.transplant, 'CLASSES', root):
                self.assertEqual([source], fix.header_dependents(header))
    def test_model_reply_extracts_indented_namespace_method(self):
        import native_llm
        body = 'namespace RBX {\n    void Part::f() { update(); }\n}\n'
        with patch.object(native_llm, 'ask', return_value=body):
            self.assertIn('RBX::Part::f()', fix.model_body('test', 'prompt', 'RBX::Part', 'f'))
    def test_missing_evidence_reply_stops_target(self):
        import native_llm
        with patch.object(native_llm, 'ask', return_value='// Cannot reconstruct faithfully: missing native APIs.'):
            with self.assertRaisesRegex(RuntimeError, 'missing native evidence'):
                fix.model_body('test', 'prompt', 'RBX::Part', 'f')
    def test_header_context_includes_dependencies_once(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / 'Receiver.h').write_text('#include "Dependency.h"\nclass Receiver {};')
            (root / 'Dependency.h').write_text('#include "Receiver.h"\nclass Dependency {};')
            with patch.object(fix, 'ROOT', root), patch.object(fix.transplant, 'HEADERS', root):
                context = fix.header_context('Receiver.h')
                self.assertEqual(1, context.count('class Receiver'))
                self.assertEqual(1, context.count('class Dependency'))
    def test_crlf_write(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / 'test.cpp'
            fix.write(path, 'one\r\ntwo\n')
            self.assertEqual(b'one\r\ntwo\r\n', path.read_bytes())

class ReferenceBinderTests(unittest.TestCase):
    def row(self, errors):
        return {'status': 'draft', 'candidates': ['00100000', '00200000'],
                'rejections': [{'addr': address, 'errors': error} for address, error in
                               zip(['00100000', '00200000'], errors)]}

    def test_known_owner_among_byte_copies(self):
        from batch_reference_bind import reference_owner
        row = self.row([['unproven reference identity: helper'],
                        ['symbol identity not established by current reference evidence']])
        self.assertEqual('00100000', reference_owner(row))

    def test_two_possible_owners_are_not_bound(self):
        from batch_reference_bind import reference_owner
        self.assertIsNone(reference_owner(self.row([['unproven reference identity: a'],
                                                    ['unproven reference identity: b']])))

    def test_reference_conflict_does_not_establish_other_owner(self):
        from batch_reference_bind import reference_owner
        self.assertIsNone(reference_owner(self.row([['reference identity differs: a'],
                                                    ['unproven reference identity: b']])))

    def test_unexamined_alternative_is_not_ignored(self):
        from batch_reference_bind import reference_owner
        row = self.row([['unproven reference identity: a']])
        self.assertIsNone(reference_owner(row))


if __name__ == '__main__':
    unittest.main()
