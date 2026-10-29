import json

from roc import rebuild


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
