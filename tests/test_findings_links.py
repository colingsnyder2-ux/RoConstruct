from roc.findings_links import definitions, native_sources


def test_definition_scopes_inline_multiline_and_comments():
    text = '''namespace RBX {
class Foo {
public:
    int get() const { return 1; }
    void declared();
    const char* text() { return "} class Wrong {"; }
};
void Foo::run(
    int arg)
{ if (arg) { declared(); } }
}
namespace Other { class Foo { int get() { return 2; } }; }
// void Foo::fake() {}
'''
    found = dict(definitions(text))
    assert found == {'RBX::Foo::get': 4, 'RBX::Foo::text': 6, 'RBX::Foo::run': 8, 'Other::Foo::get': 12}


def test_native_links_require_unique_definition_in_correct_namespace(tmp_path):
    folder = tmp_path / 'src/Client'
    folder.mkdir(parents=True)
    (folder / 'Foo.h').write_text('namespace RBX { class Foo { int get() { return 1; } }; }')
    (folder / 'Other.h').write_text('namespace Other { class Foo { int get() { return 2; } }; }')
    names = {'a': {'symbol': '?get@Foo@RBX@@QAEHXZ'}, 'b': {'symbol': '?missing@Foo@RBX@@QAEHXZ'}}
    files = ['src/Client/Foo.h', 'src/Client/Other.h']
    assert native_sources(tmp_path, files, names) == {'a': {'path': '2008-06/src/Client/Foo.h', 'line': 1}}
    (folder / 'Duplicate.h').write_text('namespace RBX { class Foo { int get() { return 3; } }; }')
    assert native_sources(tmp_path, files + ['src/Client/Duplicate.h'], names) == {}


def test_multiline_templates_preserve_source_line_numbers():
    text = 'namespace RBX {\ntemplate<class T,\nclass U> class Foo {\nint get() { return 1; }\n};\n}\n'
    assert list(definitions(text)) == [('RBX::Foo::get', 4)]


def test_comparisons_do_not_hide_following_definitions():
    text = 'namespace N { bool less() { return a < b; } bool greater() { return a > b; } }'
    assert list(definitions(text)) == [('N::less', 1), ('N::greater', 1)]
