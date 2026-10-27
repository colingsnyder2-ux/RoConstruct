from roc.findings_links import native_sources


def test_links_point_to_unique_definitions_in_published_code(tmp_path):
    path = tmp_path / 'src/rbxgs/Client/App/Part.cpp'
    path.parent.mkdir(parents=True)
    path.write_text('namespace RBX {\nvoid Part::move()\n{\n}\nvoid Part::set(int x) {}\nvoid Part::set(float x) {}\n')
    names = {'00401000': {'symbol': '?move@Part@RBX@@QAEXXZ'},
             '00402000': {'symbol': '?set@Part@RBX@@QAEXH@Z'}}
    result = native_sources(tmp_path, {'src/rbxgs/Client/App/Part.cpp': 'hash'}, names)
    assert result == {'00401000': {'path': '2008-06/src/rbxgs/Client/App/Part.cpp', 'line': 2}}


def test_same_class_name_in_another_namespace_is_not_linked(tmp_path):
    path = tmp_path / 'src/rbxgs/Client/Sky.cpp'
    path.parent.mkdir(parents=True)
    path.write_text('namespace G3D {\nSky::~Sky() {}\n}')
    names = {'005ebae0': {'symbol': '??1Sky@RBX@@UAE@XZ'}}
    assert native_sources(tmp_path, {'src/rbxgs/Client/Sky.cpp': 'hash'}, names) == {}
