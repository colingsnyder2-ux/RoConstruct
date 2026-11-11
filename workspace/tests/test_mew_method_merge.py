import unittest
from importlib.util import find_spec

AVAILABLE = find_spec('tree_sitter') and find_spec('tree_sitter_cpp')
if AVAILABLE:
    from roc.mew_method_merge import combine


@unittest.skipUnless(AVAILABLE, 'optional tree-sitter C++ parser not installed')
class MethodMergeTests(unittest.TestCase):
    def test_adds_missing_body_and_preserves_existing(self):
        base = b'namespace RBX { int Foo::a() { return 1; } }\n'
        donor = b'namespace RBX { int Foo::a() { return 9; } int Foo::b() { return 2; } }\n'
        merged, added, skipped = combine(base, donor, 'RBX', 'Foo')
        self.assertEqual(added, ['b'])
        self.assertIn(b'return 1;', merged)
        self.assertNotIn(b'return 9;', merged)
        self.assertIn(b'return 2;', merged)
        self.assertEqual(skipped[0]['method'], 'a')

    def test_skips_overloaded_methods(self):
        base = b'namespace RBX {}'
        donor = b'namespace RBX { int Foo::b(int x) { return x; } int Foo::b() { return 0; } }'
        _, added, skipped = combine(base, donor, 'RBX', 'Foo')
        self.assertEqual(added, [])
        self.assertEqual(len(skipped), 2)

    def test_does_not_move_conditional_methods(self):
        base = b'namespace RBX {}'
        donor = b'namespace RBX {\n#ifdef FEATURE\nint Foo::b() { return 1; }\n#endif\n}'
        _, added, _ = combine(base, donor, 'RBX', 'Foo')
        self.assertEqual(added, [])

    def test_existing_conditional_definition_is_not_duplicated(self):
        base = b'namespace RBX {\n#ifdef FEATURE\nint Foo::b() { return 1; }\n#endif\n}'
        donor = b'namespace RBX { int Foo::b() { return 2; } }'
        merged, added, _ = combine(base, donor, 'RBX', 'Foo')
        self.assertEqual(added, [])
        self.assertEqual(merged, base)

    def test_rejects_malformed_or_multiple_namespaces(self):
        with self.assertRaises(ValueError):
            combine(b'namespace RBX {', b'namespace RBX {}', 'RBX', 'Foo')
        with self.assertRaises(ValueError):
            combine(b'namespace RBX {} namespace RBX {}', b'namespace RBX {}', 'RBX', 'Foo')


if __name__ == '__main__':
    unittest.main()
