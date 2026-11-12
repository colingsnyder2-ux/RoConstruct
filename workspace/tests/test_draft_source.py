import unittest

from roc.draft_source import method_contract, prelude_contract


class SourceMethodContractTests(unittest.TestCase):
    def test_additive_include_and_function_declaration_without_global_state(self):
        raw = prelude_contract(dict(includes=['#include "v8datamodel/Teams.h"'],
            declarations=[dict(namespace='RBX', source='unsigned int stringHash(const std::string&);')]))
        self.assertIn(b'Teams.h', raw)
        self.assertIn(b'stringHash', raw)
        for bad in ['int global = 4;', 'int function() {return 1;}', 'class Extra {};']:
            with self.subTest(bad=bad), self.assertRaises(ValueError):
                prelude_contract(dict(declarations=[dict(namespace='RBX', source=bad)]))
        with self.assertRaises(ValueError):
            prelude_contract(dict(includes=['#include "safe.h"\n#define unsafe 1\n']))

    def method(self, **changes):
        result = dict(source='int Foo::calculate(int value) const { return value + 1; }',
                      signature='RBX::Foo::calculate(int)const', address='00401000',
                      symbol='?calculate@Foo@RBX@@QBEHH@Z')
        result.update(changes)
        return result

    def test_non_getter_method_and_inferred_name_allowed(self):
        raw = method_contract('RBX', self.method())
        self.assertIn(b'return value + 1;', raw)

    def test_global_constructor_and_destructor_partial_improvements(self):
        for source, signature, symbol in [
                ('Foo::Foo() { value = 1; }', 'Foo::Foo()', '??0Foo@@QAE@XZ'),
                ('Foo::~Foo() { release(); }', 'Foo::~Foo()', '??1Foo@@UAE@XZ')]:
            with self.subTest(signature=signature):
                self.assertIn(source.encode(), method_contract('', self.method(source=source, signature=signature, symbol=symbol)))

    def test_nested_namespace_uses_original_toolchain_syntax(self):
        raw = method_contract('RBX::Network', self.method(signature='RBX::Network::Foo::calculate(int)const'))
        self.assertIn(b'namespace RBX {\nnamespace Network {', raw)

    def test_globals_multiple_methods_wrong_identity_and_directives_blocked(self):
        for changes in [dict(source='int global; int Foo::calculate(int value) const {return value + 1;}'),
                        dict(source='int Foo::calculate(int value) const {return value;} int Foo::other() {return 2;}'),
                        dict(symbol='?other@Foo@RBX@@QBEHH@Z'),
                        dict(signature='RBX::Foo::other(int)const'),
                        dict(source='#include "evil.h"\nint Foo::calculate(int value) const {return value;}')]:
            with self.subTest(changes=changes), self.assertRaises(ValueError):
                method_contract('RBX', self.method(**changes))


if __name__ == '__main__':
    unittest.main()
