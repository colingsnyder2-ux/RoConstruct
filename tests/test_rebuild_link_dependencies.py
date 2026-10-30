import json
from types import SimpleNamespace

from roc import rebuild


def test_harness_definition_can_delegate_to_verified_library(tmp_path, monkeypatch):
    """A header-emitted COMDAT must not satisfy a requested native library root."""
    seen = []

    def run(tc, tool, args, out):
        obj = out / 'smoke.obj'
        if tool == 'cl':
            obj.write_bytes(b'harness definition')
        else:
            assert obj.read_bytes() == b'library reference'
        return 0, ''

    def strip(data, **kwargs):
        seen.append((data, kwargs['drop']))
        return b'library reference'

    monkeypatch.setattr(rebuild, 'workspace', lambda _: tmp_path)
    monkeypatch.setattr(rebuild, 'toolchain', lambda _: {})
    monkeypatch.setattr(rebuild, 'run', run)
    monkeypatch.setattr(rebuild, 'strip_symbols', strip)
    monkeypatch.setattr(rebuild.subprocess, 'run', lambda *args, **kwargs:
                        SimpleNamespace(returncode=0, stdout='', stderr=''))
    result = rebuild.link_test('test', 'smoke', [], library_symbols={'_native'})
    assert result['linked'] and result['exit'] == 0
    assert seen == [(b'harness definition', {'_native'})]


def test_unresolved_symbols_keeps_imported_cpp_names():
    output = '\n'.join([
        'a.obj : error LNK2019: unresolved external symbol "public: void A::f(void)" (__imp_?f@A@@QAEXXZ) referenced in function "main" (_main)',
        'a.obj : error LNK2001: unresolved external symbol "void g(void)" (?g@@YAXXZ)',
        'a.obj : error LNK2019: unresolved external symbol __imp__GetTickCount@0 referenced in function _main',
        'a.obj : error LNK2001: unresolved external symbol _compress',
    ])
    assert rebuild.unresolved_symbols(output) == [
        '__imp_?f@A@@QAEXXZ', '?g@@YAXXZ', '__imp__GetTickCount@0', '_compress',
    ]


def test_missing_indirect_dependency_excludes_entire_verified_object(tmp_path, monkeypatch):
    """A callback can reach a missing helper even when LINK reports no kept function as referencer."""
    out = tmp_path / 'out' / 'App'
    (out / 'verified').mkdir(parents=True)
    (out / 'verified' / 'sinks.json').write_text(json.dumps(['_callback_target']))
    layer = out / 'layer-verified'
    layer.mkdir()
    (layer / 'verified_a.obj').write_bytes(b'object')
    exclusions = []

    def verified_layer(client, spec, **kwargs):
        exclusions.append(set(kwargs['exclude']))
        return layer, {'_owner', '_callback'} - kwargs['exclude']

    def resolve(*args, **kwargs):
        linked = {'_owner', '_callback'} <= exclusions[-1]
        return {'linked': linked, 'exit': 0 if linked else None, 'output': '',
                'unresolved': [] if linked else ['_callback_target'], 'referencers': []}

    monkeypatch.setattr(rebuild, 'workspace', lambda client: tmp_path)
    monkeypatch.setattr(rebuild, 'load_module', lambda *args: {'name': 'App', 'layers': [], 'test': 'test'})
    monkeypatch.setattr(rebuild, 'build_overlay', lambda *args: None)
    monkeypatch.setattr(rebuild, 'verified_layer', verified_layer)
    monkeypatch.setattr(rebuild, 'resolve_objects', resolve)
    monkeypatch.setattr(rebuild, 'coff_externals', lambda data: {'_owner': True, '_callback': True,
                                                             '_callback_target': False})
    monkeypatch.setattr(rebuild, 'progress', lambda *args, **kwargs: None)

    assert rebuild.build_module('test', 'app', log=lambda text: None)['linked']
    assert exclusions == [set(), {'_owner', '_callback'}]
    assert json.loads((out / 'verified' / 'excluded.json').read_text()) == ['_callback', '_owner']


def test_pruned_module_releases_helpers_after_their_caller_is_excluded(tmp_path, monkeypatch):
    out = tmp_path / 'out' / 'App'
    (out / 'verified').mkdir(parents=True)
    cache = out / 'verified' / 'helpers-pruned.json'
    cache.write_text(json.dumps({'_orphan': 'a.obj'}))
    layer = out / 'layer-verified'
    layer.mkdir()
    attempts = []

    def verified_layer(client, spec, **kwargs):
        roots = {'_bad', '_good'} - kwargs['exclude']
        attempts.append((roots, dict(kwargs['helpers'])))
        return layer, roots

    def resolve(*args, **kwargs):
        roots, helpers = attempts[-1]
        missing = '_bad' in roots or '_orphan' in helpers
        return {'linked': not missing, 'exit': None if missing else 0, 'output': '',
                'unresolved': ['_missing'] if missing else [],
                'referencers': ['_bad'] if '_bad' in roots else []}

    monkeypatch.setattr(rebuild, 'workspace', lambda _: tmp_path)
    monkeypatch.setattr(rebuild, 'load_module', lambda *args: {
        'name': 'App', 'layers': [], 'test': 'test', 'prune_unselected_sections': True})
    monkeypatch.setattr(rebuild, 'build_overlay', lambda *args: None)
    monkeypatch.setattr(rebuild, 'verified_layer', verified_layer)
    monkeypatch.setattr(rebuild, 'resolve_objects', resolve)
    monkeypatch.setattr(rebuild, 'progress', lambda *args, **kwargs: None)

    assert rebuild.build_module('test', 'app', log=lambda _: None)['linked']
    assert attempts == [({'_bad', '_good'}, {'_orphan': 'a.obj'}), ({'_good'}, {})]
    assert json.loads(cache.read_text()) == {}


def test_verified_layer_discards_stale_trap_object(tmp_path, monkeypatch):
    folder = tmp_path / 'out' / 'App' / 'verified'
    folder.mkdir(parents=True)
    (folder / 'swaps.json').write_text('{"swaps": []}')
    layer = folder.with_name('layer-verified')
    layer.mkdir()
    (layer / 'verified_sinks.obj').write_bytes(b'old trap')
    monkeypatch.setattr(rebuild, 'workspace', lambda client: tmp_path)

    assert rebuild.verified_layer('test', {'name': 'App', 'verified': True}, log=lambda text: None) == (layer, set())
    assert not list(layer.glob('*.obj'))


def test_verified_layer_does_not_force_local_eh_or_callbacks(tmp_path, monkeypatch):
    folder = tmp_path / 'out' / 'App' / 'verified'
    folder.mkdir(parents=True)
    (folder / 'a.obj').write_bytes(b'object')
    (folder / 'swaps.json').write_text(json.dumps({'swaps': [
        {'obj': 'a.obj', 'keep': ['_owner', '__ehhandler$_owner', '_local_callback']}]}))
    monkeypatch.setattr(rebuild, 'workspace', lambda client: tmp_path)
    monkeypatch.setattr(rebuild, 'coff_externals', lambda data: {'_owner': True})
    retained = []
    monkeypatch.setattr(rebuild, 'strip_symbols', lambda data, **kw: retained.append(kw['keep']) or data)
    _, taken = rebuild.verified_layer('test', {'name': 'App', 'verified': True}, log=lambda _: None)
    assert taken == {'_owner'}
    assert retained == [{'_owner'}]


def test_unselected_inline_uses_native_module_provider_without_dropping_exact_owner(tmp_path, monkeypatch):
    folder = tmp_path / 'out' / 'App' / 'verified'
    folder.mkdir(parents=True)
    (folder / 'a.obj').write_bytes(b'object')
    (folder / 'swaps.json').write_text(json.dumps({'swaps': [
        {'obj': 'a.obj', 'keep': ['_owner']}]}))
    monkeypatch.setattr(rebuild, 'workspace', lambda client: tmp_path)
    monkeypatch.setattr(rebuild, 'coff_externals', lambda data: {'_owner': True, '_inline': True})
    stripped = []
    monkeypatch.setattr(rebuild, 'strip_symbols', lambda data, **kw: stripped.append(kw) or data)
    _, taken = rebuild.verified_layer('test', {'name': 'App', 'verified': True}, log=lambda _: None,
                                     helpers={'_inline': 'a.obj', '_private_helper': 'a.obj'},
                                     base_functions={'_owner', '_inline'})
    assert taken == {'_owner'}
    assert stripped[0]['drop'] == {'_inline'}
    assert '_owner' in stripped[0]['keep'] and '_private_helper' in stripped[0]['keep']


def test_pruned_verified_layer_keeps_selected_bodies_and_required_helpers(tmp_path, monkeypatch):
    folder = tmp_path / 'out/Ogre/verified'
    folder.mkdir(parents=True)
    (folder / 'a.obj').write_bytes(b'object')
    (folder / 'swaps.json').write_text(json.dumps({'swaps': [{'obj': 'a.obj', 'keep': ['_owner']}]}))
    monkeypatch.setattr(rebuild, 'workspace', lambda _: tmp_path)
    monkeypatch.setattr(rebuild, 'coff_externals', lambda _: {'_owner': True})
    monkeypatch.setattr(rebuild.match, 'coff_functions', lambda _: [
        ('_owner', b'owner', []), ('_helper', b'helper', []), ('_unused', b'unused', [])])
    calls = []
    monkeypatch.setattr(rebuild, 'strip_symbols', lambda data, **kw: calls.append(kw) or data)
    monkeypatch.setattr(rebuild, '_coff_subset', lambda data, roots, **kw: (data, roots))
    _, taken = rebuild.verified_layer('test', {'name': 'Ogre', 'verified': True,
                                             'prune_unselected_sections': True},
                                     log=lambda _: None, helpers={'_helper': 'a.obj'})
    assert taken == {'_owner'}
    assert calls == [{'keep': {'_owner', '_helper'}, 'drop': set()}]


def test_native_import_provider_overrides_cached_helper_copy(tmp_path, monkeypatch):
    folder = tmp_path / 'out/Ogre/verified'
    folder.mkdir(parents=True)
    (folder / 'a.obj').write_bytes(b'object')
    (folder / 'swaps.json').write_text(json.dumps({'swaps': [{'obj': 'a.obj', 'keep': ['_owner']}]}))
    monkeypatch.setattr(rebuild, 'workspace', lambda _: tmp_path)
    monkeypatch.setattr(rebuild, 'coff_externals', lambda _: {'_owner': True, '_imported': True})
    subsets, strips = [], []
    def subset(data, roots, external):
        subsets.append((roots, external))
        return data, roots
    monkeypatch.setattr(rebuild, '_coff_subset', subset)
    monkeypatch.setattr(rebuild, 'strip_symbols', lambda data, **kw: strips.append(kw) or data)
    _, taken = rebuild.verified_layer('test', {'name': 'Ogre', 'verified': True,
        'prune_unselected_sections': True, 'external_helpers': ['_imported']},
        log=lambda _: None, helpers={'_imported': 'a.obj'})
    assert taken == {'_owner'}
    assert subsets == [({'_owner'}, {'_imported'}), ({'_owner'}, {'_imported'})]
    assert strips == [{'keep': {'_owner'}, 'drop': set()}]


def test_overlay_root_resolves_recipe_tree_without_changing_vendor_sources(tmp_path, monkeypatch):
    source = tmp_path / 'patched-tree'
    source.mkdir()
    (source / 'GApp.cpp').write_text('namespace G3D { main(); }')
    patches = tmp_path / 'patches.json'
    patches.write_text(json.dumps({'GApp.cpp': [['namespace G3D {', '#undef main\nnamespace G3D {']]}))
    monkeypatch.setattr(rebuild, 'ROOT', tmp_path)
    monkeypatch.setattr(rebuild, 'workspace', lambda _: tmp_path)
    monkeypatch.setattr(rebuild, 'patched_tree', lambda client, recipe: source)
    root, overlay = rebuild.build_overlay('test', 'G3D-GL', {'root': 'tree:g3d-test/', 'patches': 'patches.json'})
    assert root == source
    assert (overlay / 'GApp.cpp').read_text().startswith('#undef main\n')
    assert (source / 'GApp.cpp').read_text() == 'namespace G3D { main(); }'


def test_module_archive_layer_uses_exact_compiler_member(tmp_path, monkeypatch):
    from roc import libs
    calls = []
    monkeypatch.setattr(rebuild, 'workspace', lambda _: tmp_path)
    monkeypatch.setattr(rebuild, 'load_module', lambda *args: {'name': 'App', 'test': 'test', 'layers': [
        {'name': 'crt-data', 'mode': 'archive', 'recipe': 'msvc-crt',
         'files': ['libcpmt.lib/compile/path/xvalues.obj'], 'cl': 21022}]})
    monkeypatch.setattr(libs, 'archive_unit', lambda *args: calls.append(args) or b'crt-data')
    monkeypatch.setattr(rebuild, 'coff_externals', lambda _: {'__Inf': True})
    monkeypatch.setattr(rebuild, 'resolve_objects', lambda *args, **kw: {
        'linked': True, 'exit': 0, 'output': '', 'unresolved': []})
    monkeypatch.setattr(rebuild, 'progress', lambda *args, **kw: None)
    result = rebuild.build_module('test', 'app', log=lambda _: None)
    assert result['linked'] and result['object_functions'] == 0
    assert (tmp_path / 'out/App/layer-crt-data/xvalues.obj').read_bytes() == b'crt-data'
    assert calls == [('msvc-crt', 'libcpmt.lib/compile/path/xvalues.obj', 21022)]


def test_module_stages_shipped_import_dll_before_runtime_link(tmp_path, monkeypatch):
    source = tmp_path / 'clients/test/rgmain.dll'
    source.parent.mkdir(parents=True)
    source.write_bytes(b'shipped DLL')
    monkeypatch.setattr(rebuild, 'ROOT', tmp_path)
    monkeypatch.setattr(rebuild, 'workspace', lambda _: tmp_path)
    monkeypatch.setattr(rebuild, 'load_module', lambda *args: {
        'name': 'Ogre', 'test': 'ogre_test', 'layers': [], 'import_dlls': ['rgmain.dll']})
    monkeypatch.setattr(rebuild, 'dll_import_lib', lambda *args: tmp_path / 'rgmain.lib')
    monkeypatch.setattr(rebuild, 'progress', lambda *args, **kw: None)

    def resolve(*args, **kwargs):
        assert (tmp_path / 'out/tests/ogre_test/rgmain.dll').read_bytes() == source.read_bytes()
        assert kwargs['extra_libs'] == [tmp_path / 'rgmain.lib']
        return {'linked': True, 'exit': 0, 'output': '', 'unresolved': []}

    monkeypatch.setattr(rebuild, 'resolve_objects', resolve)
    assert rebuild.build_module('test', 'ogre', log=lambda _: None)['test_exit'] == 0


def test_alternative_layer_objects_are_not_simultaneous_providers(tmp_path, monkeypatch):
    from roc import libs
    layers = [{"name": n, "mode": "archive", "recipe": "test", "files": ["same.obj"]}
              for n in ("first", "fallback")]
    spec = {"name": "App", "layers": layers, "test": "test"}
    exclusions, providers = [], []
    monkeypatch.setattr(rebuild, "workspace", lambda _: tmp_path)
    monkeypatch.setattr(rebuild, "load_module", lambda *a: spec)
    monkeypatch.setattr(rebuild, "build_overlay", lambda *a: None)
    monkeypatch.setattr(libs, "archive_unit", lambda *a: b"object")
    monkeypatch.setattr(rebuild, "coff_externals", lambda _: {"_owner": True})
    monkeypatch.setattr(rebuild, "progress", lambda *a, **k: None)
    def verified(*args, **kwargs):
        exclusions.append(kwargs["exclude"])
        providers.append(kwargs["base_functions"])
        return None, set()
    monkeypatch.setattr(rebuild, "verified_layer", verified)
    monkeypatch.setattr(rebuild, "resolve_objects", lambda *a, **k:
                        {"linked": True, "exit": 0, "unresolved": [], "output": ""})
    rebuild.build_module("test", "app", log=lambda _: None)
    assert exclusions[-1] == {"_owner"}
    spec["deduplicate_layer_files"] = True
    rebuild.build_module("test", "app", log=lambda _: None)
    assert exclusions[-1] == set()
    layers[1]["files"].append("different.obj")
    rebuild.build_module("test", "app", log=lambda _: None)
    assert exclusions[-1] == {"_owner"}

    monkeypatch.setattr(rebuild, "coff_externals", lambda _: {"_owner": True, "_state": True})
    monkeypatch.setattr(rebuild.match, "coff_functions", lambda _: [("_owner", b"code", [])])
    spec["prefer_module_helpers"] = True
    rebuild.build_module("test", "app", log=lambda _: None)
    assert providers[-1] == {"_owner"}
    spec["prefer_module_data"] = True
    rebuild.build_module("test", "app", log=lambda _: None)
    assert providers[-1] == {"_owner", "_state"}


def test_resolver_links_only_explicitly_selected_generated_objects(tmp_path, monkeypatch):
    layer = tmp_path / 'layer'
    layer.mkdir()
    for name in ['roc_selected.obj', 'roc_unselected.obj', 'vendor.obj']:
        (layer / name).write_bytes(b'object')
    monkeypatch.setattr(rebuild, 'workspace', lambda _: tmp_path)
    monkeypatch.setattr(rebuild, 'toolchain', lambda: {})
    monkeypatch.setattr(rebuild, 'defined_symbols', lambda _: set())
    def run(tc, tool, args, out):
        assert args[2:] == ['roc_selected.obj', 'vendor.obj']
        return 0, ''
    monkeypatch.setattr(rebuild, 'run', run)
    monkeypatch.setattr(rebuild, 'link_test', lambda *args, **kwargs:
                        {'linked': True, 'unresolved': []})
    result = rebuild.resolve_objects('test', 'smoke', [layer], 'linked',
                                     generated_objects={'roc_selected.obj'})
    assert set(result['choices']) == {'roc_selected.obj', 'vendor.obj'}
