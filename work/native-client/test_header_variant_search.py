import unittest
import header_variant_search as search


class HeaderSearchTest(unittest.TestCase):
    def test_replacements_must_be_unambiguous(self):
        self.assertEqual(search.apply_variant('a b c', [{'old':'b','new':'B'}]), 'a B c')
        for old in ('a', '', 'z'):
            with self.assertRaises(ValueError):
                search.apply_variant('a a', [{'old':old,'new':'x'}])

    def test_bounded_combination_search_and_deduplication(self):
        def group(name, old, new):
            return {'name': name, 'choices': [
                {'name': 'keep', 'replacements': []},
                {'name': 'change', 'replacements': [{'old': old, 'new': new}]}]}
        recipe = {'groups': [group('first', 'a', 'A'), group('second', 'b', 'B')]}
        self.assertEqual({body for _, body in search.expand_variants(recipe, 'a b')},
                         {'a b', 'A b', 'a B', 'A B'})
        recipe['groups'].append(group('third', 'c', 'C'))
        recipe['groups'].append(group('fourth', 'd', 'D'))
        with self.assertRaises(ValueError):
            search.expand_variants(recipe, 'a b c d')

    def test_shared_inputs_detect_changes_additions_and_deletions(self):
        from pathlib import Path
        scratch = Path('scratch-test').resolve()
        original = {str(scratch / 'old.cpp'): '1', 'stable': '1', 'changed': '1', 'deleted': '1'}
        variant = {str(scratch / 'new.cpp'): '2', 'stable': '1', 'changed': '2', 'added': '2'}
        self.assertEqual(search.input_changes(original, variant, scratch),
                         {'changed': ['changed'], 'added': ['added'], 'deleted': ['deleted']})

    def test_count_only_bound_exact_addresses(self):
        manifest = {'families': [{'blockers': [], 'symbols': [
            {'status':'inactive_exact', 'addr':'001'},
            {'status':'draft', 'candidates':['002']},
        ]}]}
        self.assertEqual(search.exact_addresses(manifest), {'001'})
        manifest['families'][0]['blockers'] = ['missing evidence']
        with self.assertRaises(ValueError):
            search.exact_addresses(manifest)


if __name__ == '__main__':
    unittest.main()
