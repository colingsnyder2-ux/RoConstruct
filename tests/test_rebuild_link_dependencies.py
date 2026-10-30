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


def test_verified_shared_helper_exclusion_reaches_symbol_stripper(tmp_path,monkeypatch):
    folder=tmp_path/'out/App/verified';folder.mkdir(parents=True)
    (folder/'a.obj').write_bytes(b'object')
    (folder/'swaps.json').write_text(json.dumps({'swaps':[dict(obj='a.obj',keep=['_owner'])]}))
    monkeypatch.setattr(rebuild,'workspace',lambda *a:tmp_path)
    monkeypatch.setattr(rebuild,'coff_externals',lambda *a:{'_owner':True,'_native_helper':True})
    calls=[]
    monkeypatch.setattr(rebuild,'strip_symbols',lambda data,**kw:calls.append(kw) or data)
    _,kept=rebuild.verified_layer('test',dict(name='App',verified=True),
        exclude={'_native_helper'},vdrop={'_duplicate'},log=lambda *a:None)
    assert kept=={'_owner'}
    assert calls==[dict(keep={'_owner'},drop={'_native_helper','_duplicate'})]


def test_verified_dependency_resolution_converges_beyond_twelve_rounds(tmp_path,monkeypatch):
    folder=tmp_path/'out/App/verified';folder.mkdir(parents=True)
    (folder/'a.obj').write_bytes(b'object')
    calls=[]
    def resolve(*a,**kw):
        calls.append(True)
        return dict(linked=len(calls)==14,exit=0,output='',
            unresolved=[] if len(calls)==14 else ['helper%d'%len(calls)])
    monkeypatch.setattr(rebuild,'workspace',lambda *a:tmp_path)
    monkeypatch.setattr(rebuild,'load_module',lambda *a:dict(name='App',layers=[],test='test'))
    monkeypatch.setattr(rebuild,'build_overlay',lambda *a:None)
    monkeypatch.setattr(rebuild,'verified_layer',lambda *a,**kw:(folder,{'_owner'}))
    monkeypatch.setattr(rebuild,'resolve_objects',resolve)
    monkeypatch.setattr(rebuild,'coff_externals',lambda *a:{'helper%d'%i:True for i in range(1,14)})
    monkeypatch.setattr(rebuild,'progress',lambda *a,**kw:None)
    assert rebuild.build_module('test','app',log=lambda *a:None)['linked']
    assert len(calls)==14
