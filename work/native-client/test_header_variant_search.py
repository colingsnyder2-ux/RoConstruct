import unittest
import header_variant_search as search


class HeaderSearchTest(unittest.TestCase):
    def test_replacements_must_be_unambiguous(self):
        self.assertEqual(search.apply_variant('a b c', [{'old':'b','new':'B'}]), 'a B c')
        for old in ('a', '', 'z'):
            with self.assertRaises(ValueError):
                search.apply_variant('a a', [{'old':old,'new':'x'}])

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
