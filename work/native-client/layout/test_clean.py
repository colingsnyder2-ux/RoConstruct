import unittest

import layout_clean


class CleanTest(unittest.TestCase):
    def test_recovery_notes_leave_and_program_tokens_stay(self):
        text = ('// native-flags: /O2\n// unit 00656bf0 (inactive)\n#include "a.h"\n\n\n'
                '// Draws the panel.\n// INFERRED: size from 00656bf0\nint f() { return 1; } // "x" 00656bf0\n')
        cleaned, notes = layout_clean.clean(text)
        self.assertEqual(cleaned, '#include "a.h"\n\n// INFERRED: size from 00656bf0\n'
                                  'int f() { return 1; } // "x" 00656bf0\n')
        self.assertEqual([n['line'] for n in notes], [1, 6])
        self.assertEqual(layout_clean.tokens(cleaned), layout_clean.tokens(text))
        self.assertEqual(layout_clean.build_notes(text), {'flags': '/O2'})

    def test_plain_comments_stay(self):
        text = '// Draws the panel.\nint f();\n'
        self.assertEqual(layout_clean.clean(text), (text, []))

    def test_token_check_sees_code_changes_and_string_contents(self):
        self.assertNotEqual(layout_clean.tokens('f("a//b");'), layout_clean.tokens('f("a");'))
        self.assertEqual(layout_clean.tokens('a /* x */ b // y\n'), layout_clean.tokens('a b'))
        self.assertTrue(layout_clean.line_sensitive('RBXASSERT(x);'))
        self.assertFalse(layout_clean.line_sensitive('// assert in a comment\nint x;'))


class WrapperTest(unittest.TestCase):
    def test_only_comments_and_includes_is_a_wrapper(self):
        self.assertTrue(layout_clean.is_wrapper('// native-profile: vendor\n#undef X\n#include "a/b.cpp.i"\n'))
        self.assertTrue(layout_clean.is_wrapper('/* note\n int x; */\n#include "y.c"\n'))
        self.assertFalse(layout_clean.is_wrapper('#include "a.h"\nint f() { return 1; }\n'))
        self.assertFalse(layout_clean.is_wrapper('// nothing here\n'))


class JoinTest(unittest.TestCase):
    def test_identical_definition_kept_once_and_similar_ones_kept(self):
        import layout_pipeline
        texts = {'a': '#include "x.h"\nstruct S { int x; };\n\nint f() { return 1; }\n',
                 'b': '#include "x.h"\nstruct S { int x; };\n\nint g() { return 2; }\n\nstruct S2 { int x; };\n'}
        out = layout_pipeline.join_members(['a', 'b'], texts, layout_pipeline.ROOT / 'rebuild/2008-06/layout/x/y.cpp')
        self.assertEqual(out.count('struct S {'), 1)
        self.assertEqual(out.count('#include "x.h"'), 1)
        for kept in ('int f()', 'int g()', 'struct S2'):
            self.assertIn(kept, out)


class RepairTest(unittest.TestCase):
    def test_block_at_error_line_is_dropped_and_others_stay(self):
        import layout_pipeline
        text = 'int a;\n\nstruct S { int x; };\n\nint f()\n{\n  return 1;\n}\n\nint z;\n'
        self.assertEqual(layout_pipeline.drop_blocks(text, {6}), 'int a;\n\nstruct S { int x; };\n\n\nint z;\n')
        self.assertIsNone(layout_pipeline.drop_blocks(text, {2}))          # blank line: nothing to drop
        self.assertIsNone(layout_pipeline.drop_blocks('#if X\nint a;\n#endif\n', {2}))  # preprocessor block stays

    def test_definition_dropped_inside_a_run_of_definitions(self):
        import layout_pipeline
        text = 'void a()\n{\n}\nvoid f()\n{\n  if (x) {\n    g();\n  }\n}\nvoid b()\n{\n}\nint v = 1;\n'
        self.assertEqual(layout_pipeline.drop_definitions(text, {4}), 'void a()\n{\n}\nvoid b()\n{\n}\nint v = 1;\n')
        self.assertEqual(layout_pipeline.drop_definitions(text, {13}), text.replace('int v = 1;\n', ''))
        self.assertIsNone(layout_pipeline.drop_definitions(text, {99}))

    def test_only_redefinition_errors_count(self):
        import layout_pipeline
        hit = layout_pipeline.REDEFINED.search("y.cpp(12) : error C2011: 'S' : 'struct' type redefinition")
        self.assertEqual(hit[1], '12')
        self.assertIsNone(layout_pipeline.REDEFINED.search("y.cpp(12) : error C2065: 'q' : undeclared identifier"))


class ExportTreeTest(unittest.TestCase):
    def test_one_tree_for_every_file(self):
        import layout_export
        target = 'rebuild/2008-06/client/app/gui/Foo.cpp'
        self.assertEqual(layout_export.destination(target, 'inferred'), layout_export.destination(target, ''))
        self.assertNotIn('inferred', layout_export.destination(target, 'inferred').as_posix())

    def test_path_tier_comes_from_the_receipt(self):
        import layout_pipeline
        self.assertEqual(layout_pipeline.path_tier('rebuild/2008-06/layout/client/a.cpp', {'path': 'inferred'}), 'inferred')
        self.assertEqual(layout_pipeline.path_tier('rebuild/2008-06/layout/client/a.cpp', {}), 'original')
        # receipts written before the change kept guesses in an inferred/ folder
        self.assertEqual(layout_pipeline.path_tier('rebuild/2008-06/layout/inferred/client/a.cpp', {}), 'inferred')


class MergeLocalsTest(unittest.TestCase):
    def test_identical_local_helpers_are_interchangeable_only_when_folding(self):
        import coff_compare
        from unittest.mock import patch

        def sym(name, data, refs=(), external=False):
            return {'name': name, 'external': external, 'section': '.text', 'type': 0x20, 'data': data, 'refs': list(refs)}
        objs = {'a': [sym('h1', 'aa'), sym('f', '01', [(0, 'h1', 6)], True)],
                'b': [sym('h2', 'aa'), sym('g', '02', [(0, 'h2', 6)], True)],
                'merged': [sym('h', 'aa'), sym('f', '01', [(0, 'h', 6)], True), sym('g', '02', [(0, 'h', 6)], True)],
                'changed': [sym('h', 'aa'), sym('f', '01', [(0, 'h', 6)], True), sym('g', '03', [(0, 'h', 6)], True)],
                'b_other_reloc': [sym('h2', 'aa', [(0, 'x', 6)]), sym('g', '02', [(0, 'h2', 6)], True)]}
        with patch.object(coff_compare, 'defined', side_effect=lambda obj: objs[obj]):
            self.assertTrue(coff_compare.compare_merge(['a', 'b'], ['merged'], dedupe=True)['passed'])
            self.assertFalse(coff_compare.compare_merge(['a', 'b'], ['changed'], dedupe=True)['passed'])
            # same bytes but different relocations: not interchangeable, reported as a mismatch
            self.assertFalse(coff_compare.compare_merge(['a', 'b_other_reloc'], ['merged'], dedupe=True)['passed'])
            self.assertEqual(coff_compare.compare_merge(['a', 'b'], ['merged']).get('reason'), 'ambiguous local symbol body')


if __name__ == '__main__':
    unittest.main()
