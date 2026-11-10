import json
from pathlib import Path
from types import SimpleNamespace

import pytest

from roc import integration, integration_context, integration_local as local, rebuild, native_sweep


@pytest.mark.parametrize('code,category', [('C1083', 'missing_include'), ('C2065', 'missing_declaration'),
    ('C2039', 'wrong_namespace'), ('C2664', 'wrong_parameter_type'), ('C2373', 'wrong_calling_convention')])
def test_diagnostic_keeps_location(code, category):
    row, = local.diagnostics('C:\\native\\Example.cpp(42) : error ' + code + ': evidence')
    assert row == dict(category=category, code=code, message='evidence', file='C:\\native\\Example.cpp', line=42)


def test_header_dependents_cold_conservative_warm_selective(tmp_path):
    tree = tmp_path / 'tree'
    sources = [tree / ('App/' + name + '.cpp') for name in ('First', 'Second')]
    plan = dict(sources=sources)
    output = tmp_path / 'objects'
    output.mkdir()
    assert local.affected(plan, {'App/include/Used.h': []}, tree, output) == sources
    (output / 'First.deps').write_text(json.dumps([str(tmp_path / 'overlay/App/include/Used.h')]))
    (output / 'Second.deps').write_text(json.dumps([str(tree / 'App/include/Other.h')]))
    assert local.affected(plan, {'App/include/Used.h': []}, tree, output) == sources[:1]
    assert local.affected(plan, {'App/Second.cpp': []}, tree, output) == sources[1:]
    # A newly introduced header can shadow a different include tree's header.
    assert local.affected(plan, {'App/overrides/Used.h': []}, tree, output) == sources[:1]


@pytest.fixture
def check_setup(tmp_path, monkeypatch):
    monkeypatch.setattr(rebuild, 'ROOT', tmp_path)
    tree = tmp_path / 'tools/rbxgs/Client'
    source = tree / 'App/Test.cpp'
    source.parent.mkdir(parents=True)
    source.write_text('old')
    registry = tmp_path / 'patches.json'
    registry.write_text('{}')
    spec = dict(name='RbxgsApp', overlay=dict(root='tools/rbxgs/Client', patches='patches.json'))
    monkeypatch.setattr(rebuild, 'load_module', lambda *a: spec)
    plan = dict(layer=dict(name='app', flags='/O2'), sources=[source], includes=[], defines='NDEBUG', flags='/O2', append=None)
    monkeypatch.setattr(local, 'layer_plan', lambda s: iter([plan]))
    manifest = tmp_path / 'rebuild/2008-06/manifests/functions.json'
    manifest.parent.mkdir(parents=True)
    manifest.write_text(json.dumps([dict(addr='00500000'), dict(addr='00500001')]))
    calls = []

    def compile(client, sources, folder, includes, defines, flags, **kw):
        calls.append((sources, flags, kw))
        folder.mkdir(parents=True, exist_ok=True)
        overlay = kw['overlay'][1] / 'App/Test.cpp'
        text = overlay.read_text() if overlay.exists() else source.read_text()
        (folder / 'Test.obj').write_bytes(text.encode())
        return {str(source): (text != 'bad', 'Test.cpp(7) : error C2065: missing' if text == 'bad' else '')}

    monkeypatch.setattr(rebuild, 'compile_direct', compile)
    class Matcher:
        def __init__(self, *a):
            pass
        def scan(self, data):
            return [dict(addr=a) for a in (['00500001'] if data == b'old' else
                    ['00500000'] if data == b'loss' else ['00500000', '00500001'])]
    monkeypatch.setattr(native_sweep, 'Matcher', Matcher)
    claim = dict(id='a'*32, addresses=['00500000'], protected_native=['00500001'], baseline=dict(overlay={}))
    return claim, tmp_path / 'output', calls


def test_fast_compiles_only_candidate_no_link_or_match(check_setup, monkeypatch):
    claim, output, calls = check_setup
    monkeypatch.setattr(native_sweep, 'Matcher', lambda *a: pytest.fail('Fast compile must not match'))
    report = local.evaluate(claim, {'App/Test.cpp': [['old', 'new']]}, 'fast', output)
    assert report['ok'] and report['compile_ok'] and len(calls) == 1
    assert not report['accepted'] and not report['grants_credit']
    assert not report['targets']


def test_bytes_preserves_baseline_code_data_exacts(check_setup):
    claim, output, calls = check_setup
    report = local.evaluate(claim, {'App/Test.cpp': [['old', 'new']]}, 'bytes', output)
    assert len(calls) == 2 and report['ok']
    assert report['targets']['00500000']['status'] == 'object_code_and_data_exact'
    assert report['requires_linked_verification'] and not report['accepted']


def test_bytes_rejects_regression_even_if_claim_is_exact(check_setup):
    claim, output, _ = check_setup
    report = local.evaluate(claim, {'App/Test.cpp': [['old', 'loss']]}, 'bytes', output)
    assert not report['ok'] and report['lost'] == ['00500001']
    assert report['diagnostics'][0]['category'] == 'native_regression'


def test_failed_compile_cannot_reuse_stale_object(check_setup):
    claim, output, _ = check_setup
    report = local.evaluate(claim, {'App/Test.cpp': [['old', 'bad']]}, 'bytes', output)
    assert not report['ok'] and not report['targets']
    assert report['diagnostics'][0]['category'] == 'missing_declaration'


def test_no_changes_fail_without_compiling(check_setup):
    claim, output, calls = check_setup
    assert not local.evaluate(claim, {}, 'fast', output)['ok']
    assert calls == []


def test_rank_modes_trade_value_for_effort():
    small = [dict(addr='a', size=24)]
    large = [dict(addr=str(i), size=1000) for i in range(4)]
    key = lambda rows, mode: integration_context.rank(rows, {}, ['Class.h'], {}, mode)
    assert key(small, 'easy') < key(large, 'easy')
    assert key(small, 'balanced') < key(large, 'balanced')
    assert key(large, 'large') < key(small, 'large')


def test_full_context_writes_complete_files_not_truncated(tmp_path):
    identifier, addr = 'a'*32, '00500000'
    packet = tmp_path / 'claims' / identifier / 'packet.json'
    integration.atomic_json(packet, dict(addresses=[addr]))
    content = '// roc-cl: 21022\n' + 'long source\n'*5000
    payload = dict(source=content, assembly=['ret']*300, native_files={'App/include/A.h': 'class A {};'}, size=30)
    result = integration_context.retrieve(SimpleNamespace(call=lambda path: payload), tmp_path, identifier, addr)
    assert Path(result['source_file']['path']).read_text() == content
    assert result['assembly_file']['last_line'] == 300
    assert 'source' not in result and 'native_files' not in result
    assert result['native_paths'][0]['last_line'] == 1


def test_context_rejects_foreign_address_before_network(tmp_path):
    identifier = 'b'*32
    integration.atomic_json(tmp_path / 'claims' / identifier / 'packet.json', dict(addresses=['00500000']))
    with pytest.raises(ValueError, match='not in this local claim'):
        integration_context.retrieve(SimpleNamespace(call=lambda p: pytest.fail('No API call')), tmp_path, identifier, '00600000')


def test_metrics_do_not_invent_server_credit():
    report = local.summary([dict(ok=True, units=[dict(ok=True, seconds=2, compile_cache_hit=True), dict(ok=True, seconds=4)])])
    assert report['compile_mean_seconds'] == report['compile_median_seconds'] == 3
    assert report['cache_hit_rate'] == .5 and report['server_credits'] == 0


def test_selection_config_validates_without_changing_mining_defaults():
    from roc import gui_worker
    assert gui_worker.validate({'native_selection': 'large', 'user': 'tester', 'server': 'localhost:8765', 'source_only': True}, check_model=False)['native_selection'] == 'large'
    assert gui_worker.validate({'user': 'tester', 'server': 'localhost:8765', 'source_only': True}, check_model=False)['lease_mode'] == 'function'
    with pytest.raises(ValueError, match='native selection'):
        gui_worker.validate({'native_selection': 'unsafe'}, check_model=False)


@pytest.mark.parametrize('status,lost,expected', [('mismatch', [], False), ('not_established', [], True),
                                                ('object_code_and_data_exact', ['00500001'], False)])
def test_full_check_gate_preserves_server_only_credit(tmp_path, monkeypatch, status, lost, expected):
    from roc import integration_verify
    monkeypatch.setattr(rebuild, 'ROOT', tmp_path)
    patchdir = tmp_path / 'rebuild/2008-06/patches'
    patchdir.mkdir(parents=True)
    (tmp_path / 'base-generator.py').write_text('# accepted generator')
    claim = dict(baseline=dict(overlay={}, accepted=[]))
    report = dict(ok=False, accepted=False, grants_credit=False, compile_ok=True, lost=lost,
                  targets={'00500000': dict(status=status)})
    monkeypatch.setattr(local, 'evaluate', lambda *a: report)
    calls = []
    def linked(root, delta, output):
        calls.append(delta)
        assert json.loads((patchdir / 'rbxgs-client.json').read_text()) == {}
        assert (patchdir / 'make_rbxgs_client.py').read_text() == '# accepted generator'
        return dict(accepted=True)
    monkeypatch.setattr(integration_verify, 'linked_preflight', linked)
    result = local.run_check(claim, {'App/Test.cpp': [['old', 'new']]}, 'full', tmp_path / 'out')
    assert bool(calls) == expected
    assert result['ok'] == expected
    assert result['accepted'] is False and result['grants_credit'] is False


@pytest.mark.parametrize('ok', [True, False])
def test_claim_check_retains_attempts_and_uses_private_outputs(tmp_path, monkeypatch, ok):
    from roc import integrator
    monkeypatch.setattr(integration, 'ROOT', tmp_path)
    identifier = 'c'*32
    folder = tmp_path / 'work/integration-client/claims' / identifier
    integration.atomic_json(folder / 'packet.json', dict(id=identifier))
    private = tmp_path / 'local/integrators/private'
    private.mkdir(parents=True)
    generator = private / 'rebuild/2008-06/patches/make_rbxgs_client.py'
    generator.parent.mkdir(parents=True)
    generator.write_text('# retained candidate')
    monkeypatch.setattr(integrator, 'workspace', lambda: private)
    monkeypatch.setattr(local.shutil, 'copytree', lambda *a, **kw: None)
    def run(args, cwd, **kwargs):
        assert cwd == private and args[-1] == 'fast'
        integration.atomic_json(private / 'work/local-check/result.json', dict(ok=ok, accepted=False, grants_credit=False, units=[]))
        return SimpleNamespace(returncode=0 if ok else 1)
    monkeypatch.setattr(local.subprocess, 'run', run)
    args = SimpleNamespace(claim=identifier, fast=True, bytes=False, full=False)
    for attempt in range(2):
        if ok:
            local.command(args)
        else:
            with pytest.raises(SystemExit):
                local.command(args)
    assert len(list((folder / 'checks').glob('*.json'))) == 2
    assert len(list((folder / 'checks').glob('*/generator.py'))) == 2
    assert json.loads((folder / 'check-metrics.json').read_text())['checks'] == 2
    assert not (tmp_path / 'rebuild/2008-06/out').exists()


def test_object_diagnostic_reports_size_relocation_and_first_instruction(monkeypatch):
    from roc import match, native_search
    monkeypatch.setattr(native_search, 'diagnose', lambda *a: {'00500000': dict(code_exact=False, data_exact=False, blocker='instruction-order')})
    monkeypatch.setattr(match, 'coff_functions', lambda obj: [('method', b'xx', [])])
    monkeypatch.setattr(match, 'target', lambda *a: (b'xxx', [1], {}))
    monkeypatch.setattr(match, 'asm_lines', lambda body, relocs: ['mov eax, 1'] if len(body) == 3 else ['mov eax, 2'])
    report = local.object_diagnostic(b'object', '00500000', 'method')
    assert report['expected_size'] == 3 and report['object_size'] == 2
    assert report['category'] == 'function_size_mismatch'
    assert report['target_relocations'] == [1]
    assert report['first_mismatch'] == dict(instruction=0, target='mov eax, 1', object='mov eax, 2')
    assert report['classification_is_hint']


def test_failed_linked_preflight_retains_local_diagnostics(tmp_path, monkeypatch):
    from roc import integration_verify
    monkeypatch.setattr(rebuild, 'ROOT', tmp_path)
    patches = tmp_path / 'rebuild/2008-06/patches'
    patches.mkdir(parents=True)
    (tmp_path / 'base-generator.py').write_text('# baseline')
    report = dict(ok=True, accepted=False, grants_credit=False, compile_ok=True, lost=[],
                  targets={'00500000': dict(status='object_code_and_data_exact')}, diagnostics=[])
    monkeypatch.setattr(local, 'evaluate', lambda *a: report)
    def fail(*args):
        raise ValueError('regression in previously integrated function')
    monkeypatch.setattr(integration_verify, 'linked_preflight', fail)
    result = local.run_check(dict(baseline=dict(overlay={}, accepted=[])),
                             {'App/A.cpp': [['old', 'new']]}, 'full', tmp_path / 'out')
    assert not result['ok'] and result['compile_ok']
    assert result['targets']['00500000']['status'] == 'object_code_and_data_exact'
    assert result['diagnostics'][0]['category'] == 'linked_verification_failure'



def test_empty_claim_cannot_pass_a_bytes_comparison(check_setup):
    claim, output, calls = check_setup
    claim['addresses'] = []
    report = local.evaluate(claim, {'App/Test.cpp': [['old','new']]}, 'bytes', output)
    assert not report['ok'] and calls == []


def test_baseline_and_candidate_objects_are_kept_separate(check_setup):
    claim, output, _ = check_setup
    report = local.evaluate(claim, {'App/Test.cpp': [['old','new']]}, 'bytes', output)
    before, after = report['units']
    assert before['object'] != after['object']
    assert Path(before['object']).read_bytes() == b'old'
    assert Path(after['object']).read_bytes() == b'new'


def test_same_stem_translation_units_get_private_artifacts(tmp_path):
    plan = dict(sources=[tmp_path/'one/Shared.cpp',tmp_path/'two/Shared.cpp'])
    a, b = [local.unit_output(plan, p, tmp_path/'objects') for p in plan['sources']]
    assert a != b
    a.mkdir(parents=True);b.mkdir(parents=True)
    (a/'Shared.deps').write_text(json.dumps([str(tmp_path/'tree/App/include/A.h')]))
    (b/'Shared.deps').write_text(json.dumps([str(tmp_path/'tree/App/include/B.h')]))
    assert local.affected(plan, {'App/include/A.h':[]}, tmp_path/'tree', tmp_path/'objects') == plan['sources'][:1]


def test_batch_check_merges_claims_once_and_rejects_mixed_baselines(tmp_path):
    ids = ['a'*32, 'b'*32]
    base = dict(overlay={}, generator='hash')
    for n,identifier in enumerate(ids):
        integration.atomic_json(tmp_path/'claims'/identifier/'packet.json',
            dict(id=identifier,user='alice',base_revision='r',baseline=base, addresses=['0050000'+str(n)], native_names={}))
    batch = tmp_path/'batch.json'
    integration.atomic_json(batch,dict(claims=ids))
    args=SimpleNamespace(claim=None,batch=str(batch),all=False)
    combined,folder,claims = local.selected_claims(args,tmp_path)
    assert combined['addresses'] == ['00500000','00500001'] and len(claims) == 2
    assert folder.parent.name == 'check-batches'
    path = tmp_path/'claims'/ids[1]/'packet.json'
    data=json.loads(path.read_text());data['base_revision']='other';integration.atomic_json(path,data)
    with pytest.raises(ValueError,match='identical baseline'):
        local.selected_claims(args,tmp_path)


def test_linker_diagnostics_preserve_symbol_and_object_location():
    row,=local.diagnostics('Part.obj : error LNK2001: unresolved external symbol ?missing@Part@@')
    assert row['category']=='linking_failure' and row['file']=='Part.obj'
    assert '?missing@Part@@' in row['message']
