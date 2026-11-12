from pathlib import Path
import tempfile
import unittest
import importlib.util
from unittest.mock import patch

from roc import native_drafts
from roc.draft_family import merge_file, prepare, measure, _preservation, reuse_existing_methods, compare_layouts, layout_variants


class DraftFamilyTests(unittest.TestCase):
    source_path = 'rebuild/2008-06/native-classes/Foo.cpp'

    def test_layout_comparison_catches_changed_offsets_and_missing_classes(self):
        before = {'Owner': {'size': 8, 'offset': 4}, 'Removed': {'size': 4}}
        after = {'Owner': {'size': 8, 'offset': 0}, 'New': {'size': 4}}
        self.assertEqual(compare_layouts(before, after),
                         {'added': ['New'], 'removed': ['Removed'], 'changed': ['Owner']})

    def test_msvc_unqualified_name_collisions_do_not_hide_or_invent_layout_changes(self):
        tool = Path(__file__).resolve().parents[1] / 'work/native-client/native_class_layout.py'
        spec = importlib.util.spec_from_file_location('_test_layout_variants', tool)
        parser = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(parser)
        first = 'class Item size(4):\n    0 | value\n\n'
        second = 'class Item size(8):\n    0 | other\n    4 | extra\n\n'
        third = 'class Item size(12):\n    0 | unrelated\n\n'
        before = layout_variants(first + second, parser.parse)
        after = layout_variants(second + first + third, parser.parse)
        self.assertEqual(len(before), 2)
        self.assertEqual(compare_layouts(before, after)['removed'], [])
        self.assertEqual(len(compare_layouts(before, after)['added']), 1)
        changed = layout_variants(first.replace('0 | value', '2 | value') + second, parser.parse)
        self.assertEqual(len(compare_layouts(before, changed)['removed']), 1)

    def make_repo(self, changes):
        temp = tempfile.TemporaryDirectory()
        root = Path(temp.name)
        source = root / self.source_path
        source.parent.mkdir(parents=True)
        source.write_text('namespace RBX {\nint Foo::first() { return 1; }\nint Foo::second() { return 2; }\n}\n')
        header = root / 'rebuild/2008-06/native-headers/gui/Foo.h'
        header.parent.mkdir(parents=True)
        header.write_text('class Foo { int value; };\n')
        packet = {
            'schema': 1,
            'user': 'ReviewUser',
            'model': 'unit-test',
            'session': 'a' * 32,
            'baseline': 'test-baseline',
            'parent': None,
            'status': 'draft',
            'exact_credits': 0,
            'created': 1,
            'files': changes,
        }
        identifier = native_drafts.digest(packet)
        inbox = native_drafts.Inbox(root)
        with inbox.connect() as db:
            db.execute('INSERT INTO bundles(id,user,packet,received) VALUES(?,?,?,?)',
                       (identifier, packet['user'], native_drafts.encoded(packet).decode(), 1))
        return temp, root, identifier, source, header

    def test_three_way_merge_keeps_newer_siblings_and_writes_scratch_only(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            source = root / self.source_path
            source.parent.mkdir(parents=True)
            base = ('namespace RBX {\nint Foo::first() {\n    return 1;\n}\n\n'
                    'int Foo::second() {\n    return 2;\n}\n}\n')
            current = base.replace('    return 2;', '    return 4;')
            candidate = base.replace('    return 1;', '    return 3;')
            source.write_bytes(current.encode('utf-8'))
            header = root / 'rebuild/2008-06/native-headers/gui/Foo.h'
            header.parent.mkdir(parents=True)
            base_header = 'class Foo { int value; };\n'
            candidate_header = 'class Foo { float value; };\n'
            header.write_bytes(base_header.encode('utf-8'))
            packet = {
                'schema': 1, 'user': 'ReviewUser', 'model': 'unit-test', 'session': 'b' * 32,
                'baseline': 'test-baseline', 'parent': None, 'status': 'draft', 'exact_credits': 0,
                'created': 1, 'files': {
                    self.source_path: {'base': base, 'text': candidate},
                    'rebuild/2008-06/native-headers/gui/Foo.h': {
                        'base': base_header, 'text': candidate_header},
                },
            }
            identifier = native_drafts.digest(packet)
            inbox = native_drafts.Inbox(root)
            with inbox.connect() as db:
                db.execute('INSERT INTO bundles(id,user,packet,received) VALUES(?,?,?,?)',
                           (identifier, packet['user'], native_drafts.encoded(packet).decode(), 1))
            before_source = source.read_bytes()
            before_header = header.read_bytes()

            manifest = prepare(root, identifier)
            overlay = Path(manifest['output']) / 'overlay'
            merged = (overlay / self.source_path).read_text()
            self.assertIn('    return 3;', merged)
            self.assertIn('    return 4;', merged)
            overlay_header = overlay / 'rebuild/2008-06/native-headers/gui/Foo.h'
            self.assertEqual(overlay_header.read_text(), candidate_header)
            header_row = next(row for row in manifest['files'] if row['path'].endswith('Foo.h'))
            self.assertIn('original ABI, vtable and layout proof', header_row['blockers'][0])
            self.assertEqual(source.read_bytes(), before_source)
            self.assertEqual(header.read_bytes(), before_header)
            row = next(row for row in manifest['files'] if row['path'] == self.source_path)
            self.assertEqual(row['state'], 'merged')
            self.assertIn('RBX::Foo::first()', row['preservation']['changed_methods'])
            self.assertTrue((Path(manifest['output']) / 'manifest.json').is_file())

    def test_candidate_equal_to_base_does_not_revert_live_content(self):
        result = merge_file('base', 'newer-live', 'base')
        self.assertEqual(result['state'], 'unchanged')
        self.assertEqual(result['text'], 'newer-live')

    def test_identical_method_added_at_another_location_reuses_live_body(self):
        current = 'namespace RBX {\nint Foo::get() const\n{ return value; }\n}\n'
        merged = 'namespace RBX {\nint Foo::get() const {return value;}\n}\n' + current
        text, reused = reuse_existing_methods(current, merged)
        self.assertEqual(reused, ['RBX::Foo::get()const'])
        self.assertEqual(text.count('Foo::get'), 1)
        self.assertIn('int Foo::get() const\n{ return value; }', text)
        self.assertEqual(reuse_existing_methods(current, current + current)[0].count('Foo::get'), 1)
        different = merged.replace('{return value;}', '{return other;}')
        self.assertEqual(reuse_existing_methods(current, different), (different, []))
        self.assertEqual(_preservation(current, different, Path('Foo.cpp'))['duplicate_methods'], ['RBX::Foo::get()const'])

    def test_export_source_maps_to_canonical_and_wrapper_cannot_overwrite_it(self):
        base = 'namespace RBX {\nint Foo::first() { return 1; }\nint Foo::second() { return 2; }\n}\n'
        changes = {
            'rebuild/2008-06/App/src/gui/Foo.cpp': {'base': base, 'text': base + 'int added;\n'},
            self.source_path: {'base': '#include "../App/src/gui/Foo.cpp"\n',
                               'text': '// compatibility\n#include "../Unclassified/src/Foo.cpp"\n'},
        }
        temp, root, identifier, source, _ = self.make_repo(changes)
        with temp:
            before = source.read_bytes()
            manifest = prepare(root, identifier)
            rows = manifest['files']
            self.assertEqual(rows[0]['path'], self.source_path)
            self.assertEqual(rows[0]['state'], 'merged')
            self.assertEqual(rows[1]['state'], 'compatibility-wrapper')
            overlay = Path(manifest['output']) / 'overlay' / self.source_path
            self.assertIn('int added;', overlay.read_text())
            self.assertNotIn('Unclassified', overlay.read_text())
            self.assertEqual(source.read_bytes(), before)

    def test_conflict_and_deletion_never_overwrite_current(self):
        conflict = merge_file('old\n', 'local\n', 'draft\n')
        self.assertEqual(conflict['state'], 'conflict')
        self.assertEqual(conflict['text'], 'local\n')
        deletion = merge_file('old\n', 'newer\n', None)
        self.assertEqual(deletion['state'], 'deletion-review')
        self.assertEqual(deletion['text'], 'newer\n')

    def test_unrelated_new_file_conflicts_and_output_must_be_scratch(self):
        self.assertEqual(merge_file(None, 'local', 'draft')['state'], 'conflict')
        self.assertEqual(merge_file(None, 'same', 'same')['state'], 'already-present')
        changes = {self.source_path: {'base': 'old', 'text': 'candidate'}}
        temp, root, identifier, _, _ = self.make_repo(changes)
        with temp:
            with self.assertRaisesRegex(ValueError, 'scratch'):
                prepare(root, identifier, output=root / 'rebuild/2008-06/native-classes')

    def test_non_native_script_path_is_review_only_never_copied(self):
        changes = {'roc/untrusted.py': {'base': 'old', 'text': 'raise RuntimeError("ran")'}}
        temp, root, identifier, _, _ = self.make_repo(changes)
        with temp:
            manifest = prepare(root, identifier)
            row = next(row for row in manifest['files'] if row['path'] == 'roc/untrusted.py')
            self.assertEqual(row['state'], 'review-needed')
            self.assertFalse((Path(manifest['output']) / 'overlay/roc/untrusted.py').exists())
            self.assertIn('not an eligible native source/header path', row['blockers'][0])

    def test_multiple_conflicts_keep_current(self):
        base = 'first\n' + '\n'.join('unchanged%d' % n for n in range(20)) + '\nlast\n'
        current = base.replace('first', 'local-first').replace('last', 'local-last')
        candidate = base.replace('first', 'draft-first').replace('last', 'draft-last')
        result = merge_file(base, current, candidate)
        self.assertEqual(result['state'], 'conflict')
        self.assertEqual(result['text'], current)

    def test_windows_line_endings_do_not_create_false_conflicts(self):
        base = 'first\n' + '\n'.join('unchanged%d' % n for n in range(20)) + '\nlast\n'
        current = base.replace('last', 'local-last').replace('\n', '\r\n')
        candidate = base.replace('first', 'draft-first')
        result = merge_file(base, current, candidate)
        self.assertEqual(result['state'], 'merged')
        self.assertIn('draft-first\r\n', result['text'])
        self.assertIn('local-last\r\n', result['text'])
        self.assertNotIn('\n', result['text'].replace('\r\n', ''))

    def test_global_registration_strings_are_preserved(self):
        result = _preservation('const char* name = "RegisterClass";\n',
                               'const char* name = "OtherClass";\n', Path('Foo.cpp'))
        self.assertEqual(result['removed_literals'], ['"RegisterClass"'])
        self.assertEqual(result['added_literals'], ['"OtherClass"'])
        self.assertTrue(any('string' in text for text in result['blockers']))

    def test_family_compile_uses_paired_private_trees(self):
        changes = {self.source_path: {'base': None, 'text': 'int replacement;'}}
        temp, root, identifier, source, _ = self.make_repo(changes)
        with temp:
            changes = native_drafts.Inbox(root).packet(identifier)
            # An existing new-file conflict must not become a compiler candidate.
            manifest = prepare(root, identifier)
            self.assertEqual(measure(root, manifest['output'])['summary']['attempted'], 0)
            base = source.read_bytes().decode()
            packet = dict(changes, files={self.source_path: {'base': base, 'text': base + 'int added;\n'}})
            identifier = native_drafts.digest(packet)
            with native_drafts.Inbox(root).connect() as db:
                db.execute('INSERT INTO bundles(id,user,packet,received) VALUES(?,?,?,?)',
                           (identifier, packet['user'], native_drafts.encoded(packet).decode(), 1))
            manifest = prepare(root, identifier)
            with patch('roc.input_reuse.ensure_link'), patch('roc.draft_native.flags', return_value=[]), \
                    patch('roc.rebuild.toolchain', return_value={}), \
                    patch('roc.rebuild.run', return_value=(9, 'deliberate compile failure')) as compile:
                result = measure(root, manifest['output'])
            self.assertEqual(result['summary'], {'attempted': 1, 'compiled': 0, 'new_exact_reference_methods': 0})
            self.assertEqual(result['accepted'], 0)
            self.assertEqual(compile.call_count, 2)
            self.assertIn('baseline', compile.call_args_list[0].args[2][-1])
            self.assertIn('overlay', compile.call_args_list[1].args[2][-1])
            self.assertEqual(source.read_bytes().decode(), base)
            (Path(manifest['output']) / 'overlay' / self.source_path).write_text('tampered')
            with self.assertRaisesRegex(ValueError, 'inventory changed'):
                measure(root, manifest['output'])


if __name__ == '__main__':
    unittest.main()
