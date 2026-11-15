import unittest
from roc.draft_methods import extract

class MethodTests(unittest.TestCase):
    def keys(self, source): return {r['signature'] for r in extract(source.encode())[0]}
    def test_inline_equals_out_of_line(self):
        self.assertEqual(self.keys('namespace RBX { class X { ~X() {} }; }'), self.keys('namespace RBX { X::~X() {} }'))
    def test_parameter_names_do_not_create_methods(self):
        self.assertEqual(self.keys('namespace R { int X::f(int first) const {return first;} }'), self.keys('namespace R { int X::f(int second) const {return second;} }'))
    def test_overloads_distinct(self):
        self.assertEqual(len(self.keys('void X::f(int x) {} void X::f(float x) {}')),2)
    def test_const_distinct(self):
        self.assertEqual(len(self.keys('void X::f() {} void X::f() const {}')),2)
    def test_namespace_distinct(self):
        self.assertEqual(len(self.keys('namespace A { void f() {} } namespace B { void f() {} }')),2)
    def test_default_argument_is_not_overload(self):
        self.assertEqual(self.keys('void X::f(int x = 2) {}'), self.keys('void X::f(int y) {}'))
    def test_pointer_reference_distinct(self):
        self.assertEqual(len(self.keys('void X::f(int* x) {} void X::f(int& x) {}')),2)
    def test_reference_return_method_is_extracted(self):
        self.assertEqual(self.keys('namespace RBX { const G3D::Color3& Color::red() { return value; } }'),
                         {'RBX::Color::red()'})
    def test_declarations_not_implementations(self):
        self.assertFalse(self.keys('namespace R { class X { void f(); }; }'))
    def test_preprocessor_requires_resolution(self):
        rows,_=extract(b'#ifdef DEBUG\nvoid X::f() {}\n#endif')
        self.assertTrue(rows[0]['needs_semantic_resolution'])
    def test_strings_preserved(self):
        rows,_=extract(b'void f() { log("Hello"); }')
        self.assertEqual(rows[0]['strings'],['"Hello"'])
    def test_body_ignores_format_and_comments(self):
        left,_=extract(b'int X::f() { return 1; }')
        right,_=extract(b'int X::f(){/* note */return 1;}')
        self.assertEqual(left[0]['body_sha256'],right[0]['body_sha256'])
    def test_templates_flagged(self):
        rows,_=extract(b'template<class T> void X<T>::f(T t) {}')
        self.assertTrue(rows[0]['needs_semantic_resolution'])

if __name__=='__main__':unittest.main()
