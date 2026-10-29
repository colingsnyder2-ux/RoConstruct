import hashlib
import json
from pathlib import Path
from types import SimpleNamespace

import pytest

from roc import native_try


def test_reset_file_preserves_other_saved_proofs(tmp_path, monkeypatch):
    path = tmp_path / 'proposals.json'
    other = {'file': 'App/B.cpp', 'proof': {'object_sha256': 'unchanged'}}
    path.write_text(json.dumps([{'file': 'App/A.cpp'}, other]))
    monkeypatch.setattr(native_try, 'PROPOSALS', path)
    native_try.dispatch(SimpleNamespace(action='reset', file='App/A.cpp'))
    assert json.loads(path.read_text()) == [other]
    native_try.dispatch(SimpleNamespace(action='reset', file='App/missing.cpp'))
    assert json.loads(path.read_text()) == [other]
    native_try.dispatch(SimpleNamespace(action='reset', file=None))
    assert not path.exists()


@pytest.mark.parametrize('concurrent_edit', [False, True])
def test_submit_restores_baseline_only_when_generator_is_unchanged(tmp_path, monkeypatch, concurrent_edit):
    proposals = tmp_path / 'proposals.json'
    proposals.write_text('[{"file":"App/A.cpp"}]')
    job = tmp_path / 'work/integration-client/jobs/test-job'
    job.mkdir(parents=True)
    (job / 'submitted-generator.py').write_bytes(b'staged')
    (job / 'generator-base.py').write_bytes(b'base')
    generator = tmp_path / 'rebuild/2008-06/patches/make_rbxgs_client.py'
    generator.parent.mkdir(parents=True)
    generator.write_bytes(b'newer edit' if concurrent_edit else b'staged')
    calls = []
    monkeypatch.setattr(native_try, 'PROPOSALS', proposals)
    monkeypatch.setattr(native_try.native_sweep, 'ROOT', tmp_path)
    monkeypatch.setattr(native_try.native_sweep, 'run', lambda *args, **kwargs:
                        {'job': 'test-job', 'applied_paths': ['App/A.cpp']})
    monkeypatch.setattr(native_try.native_sweep.subprocess, 'run', lambda *args, **kwargs: calls.append(args))
    native_try.cmd_submit(SimpleNamespace(model='test'))
    assert generator.read_bytes() == (b'newer edit' if concurrent_edit else b'base')
    assert len(calls) == (0 if concurrent_edit else 1)


def test_brief_evidence_preserves_proof_and_diff_without_repeated_assembly(monkeypatch, capsys):
    ctx = SimpleNamespace(names={'00000001': {'symbol': '?f@A@@'}}, by_addr={})
    monkeypatch.setattr(native_try, 'file_state', lambda *args: ('native source', [], ['00000001'], {'00000001'}, b'obj'))
    monkeypatch.setattr(native_try, 'diff', lambda *args: 'actual instruction diff')
    monkeypatch.setattr(native_try.native_sweep, 'excerpt', lambda *args: 'native source')
    monkeypatch.setattr(native_try.native_sweep, 'model_evidence', lambda *args:
                        {'addr': '00000001', 'mined_source': 'exact proof', 'target_asm': ['redundant assembly']})
    native_try.cmd_evidence(ctx, SimpleNamespace(file='A.cpp', only=None, context='methods', brief=True))
    output = capsys.readouterr().out
    assert 'native source' in output and 'exact proof' in output and 'actual instruction diff' in output
    assert 'target_asm' not in output and 'redundant assembly' not in output
    assert '"tu_code_and_data_exact": true' in output and 'linked ownership/provider' in output


def test_evidence_headers_follow_compiler_overlay_not_original_tree(tmp_path, monkeypatch):
    tree, overlay = tmp_path / 'tree', tmp_path / 'overlay'
    tree.mkdir()
    overlay.mkdir()
    (tree / 'A.cpp').write_text('#include "util/Events.h"\n#include "missing.h"\n')
    obj = tmp_path / 'A.obj'
    obj.write_bytes(b'object')
    header = str(overlay / 'App/include/util/Events.h')
    obj.with_suffix('.deps').write_text(json.dumps([header, 'C:/SDK/vector']))
    monkeypatch.setattr(native_try, 'saved', lambda: [])
    monkeypatch.setattr(native_try.native_sweep, 'target_files', lambda *args: {})
    ctx = SimpleNamespace(tree=tree, overlay=overlay, targets=set(), owned=set(), names={}, by_addr={},
                          compile=lambda *args: {'ok': True, 'object': str(obj)},
                          matcher=SimpleNamespace(scan=lambda data: []))
    native_try.file_state(ctx, 'A.cpp')
    assert ctx.evidence_headers == {'util/Events.h': [header]}


@pytest.fixture
def trial(tmp_path, monkeypatch):
    monkeypatch.setattr(native_try.native_sweep, 'ownership_candidates',
                        lambda obj, hits: {h['addr']: [h['addr']] for h in hits})
    proposals = tmp_path / 'proposals.json'
    monkeypatch.setattr(native_try, 'PROPOSALS', proposals)
    old = {'file': 'App/A.cpp', 'edits': [['old', 'saved']],
           'witnesses': [{'addr': '00000001', 'symbol': '?first@A@@QAEXXZ'}],
           'base_revision': 'old-base'}
    proposals.write_text(json.dumps([old]))
    obj = tmp_path / 'result.obj'
    obj.write_bytes(b'object')
    found = {'00000001', '00000002'}
    ctx = SimpleNamespace(owned=set(), targets={'00000001', '00000002'}, base_revision='new-base', by_addr={'00000002': {'unit': 'RBX::A'}},
                          matcher=SimpleNamespace(scan=lambda _: [{'addr': a, 'symbol': '?second@A@@QAEXXZ'} for a in found]),
                          compile=lambda *args: {'ok': True, 'object': str(obj)})
    monkeypatch.setattr(native_try, 'file_state', lambda *args:
                        ('saved', old['edits'], ['00000001', '00000002'], {'00000001'}, b'object'))
    monkeypatch.setattr(native_try, 'diff', lambda *args: 'diff')
    blocks = tmp_path / 'blocks.txt'
    blocks.write_text('<<<<<<< SEARCH\nsaved\n=======\nnew\n>>>>>>> REPLACE\n', encoding='utf-8-sig')
    return ctx, found, proposals, blocks


def test_check_preserves_previously_saved_gain(trial):
    ctx, found, proposals, blocks = trial
    original = proposals.read_bytes()
    found.remove('00000001')
    with pytest.raises(SystemExit):
        native_try.cmd_check(ctx, SimpleNamespace(file='App/A.cpp', blocks=str(blocks)))
    assert proposals.read_bytes() == original


def test_check_includes_unique_header_helper_outside_inventory_file_map(trial):
    ctx, found, proposals, blocks = trial
    ctx.targets.add('00000003')
    ctx.by_addr['00000003'] = {'unit': 'RBX::A'}
    found.add('00000003')
    native_try.cmd_check(ctx, SimpleNamespace(file='App/A.cpp', blocks=str(blocks)))
    assert '00000003' in {h['addr'] for h in json.loads(proposals.read_text())[0]['witnesses']}


def test_check_accepts_powershell_bom_and_merges_saved_gains(trial):
    ctx, _, proposals, blocks = trial
    native_try.cmd_check(ctx, SimpleNamespace(file='App/A.cpp', blocks=str(blocks)))
    saved = json.loads(proposals.read_text())[0]
    assert saved['edits'] == [['old', 'saved'], ['saved', 'new']]
    assert {w['addr'] for w in saved['witnesses']} == {'00000001', '00000002'}
    assert saved['base_revision'] == 'new-base'


def test_check_without_blocks_revalidates_saved_proposal(trial):
    ctx, _, proposals, _ = trial
    native_try.cmd_check(ctx, SimpleNamespace(file='App/A.cpp', blocks=None))
    saved = json.loads(proposals.read_text())[0]
    assert saved['edits'] == [['old', 'saved']]
    assert saved['base_revision'] == 'new-base'


def test_paired_check_minimizes_headers_and_retains_them_for_recheck(trial):
    ctx, _, proposals, blocks = trial
    required = ['field', 'correct field']
    blocks.write_text(json.dumps({'App/A.cpp': [['saved', 'new']],
                                 'App/include/A.h': [required, ['unused', 'unnecessary']]}))
    original_compile = ctx.compile
    def compile_trial(*args):
        if required not in ctx.related_headers.get('App/include/A.h', []):
            return {'ok': False, 'error': 'missing declaration'}
        return original_compile(*args)
    ctx.compile = compile_trial
    native_try.cmd_check(ctx, SimpleNamespace(file='App/A.cpp', blocks=str(blocks)))
    assert json.loads(proposals.read_text())[0]['related_headers'] == {'App/include/A.h': [required]}
    assert json.loads(proposals.read_text())[0]['edits'] == [['old', 'saved']]
    native_try.cmd_check(ctx, SimpleNamespace(file='App/A.cpp', blocks=None))
    assert json.loads(proposals.read_text())[0]['related_headers'] == {'App/include/A.h': [required]}


def test_check_does_not_save_address_ambiguous_gain(trial, monkeypatch, capsys):
    ctx, _, proposals, blocks = trial
    original = proposals.read_bytes()
    monkeypatch.setattr(native_try.native_sweep, 'ownership_candidates',
                        lambda obj, hits: {'00000002': ['00000002', '00000003']})
    with pytest.raises(SystemExit):
        native_try.cmd_check(ctx, SimpleNamespace(file='App/A.cpp', blocks=str(blocks)))
    assert proposals.read_bytes() == original
    output = capsys.readouterr().out
    assert 'address-ambiguous local exacts' in output and '"00000002": 2' in output
    report = Path(output.split('evidence: ', 1)[1].splitlines()[0])
    evidence = json.loads(report.read_text())
    assert evidence['ownership_candidates'] == {'00000002': ['00000002', '00000003']}
    assert evidence['newly_exact'] == [] and evidence['lost'] == []


def test_header_minimizer_keeps_inline_definition_needed_by_retained_calls(trial):
    ctx, _, proposals, blocks = trial
    required = ['int helper();', 'int helper() { return 1; }']
    blocks.write_text(json.dumps({'App/A.cpp': [['saved', 'new']], 'App/include/A.h': [required]}))
    original_compile = ctx.compile
    def compile_trial(*args):
        result = original_compile(*args)
        present = required in ctx.related_headers.get('App/include/A.h', [])
        return dict(result, defined_symbols=['helper'] if present else [], undefined_symbols=[] if present else ['helper'])
    ctx.compile = compile_trial
    native_try.cmd_check(ctx, SimpleNamespace(file='App/A.cpp', blocks=str(blocks)))
    assert json.loads(proposals.read_text())[0]['related_headers'] == {'App/include/A.h': [required]}


def test_main_reports_expected_errors_without_traceback(monkeypatch):
    def refuse():
        raise ValueError('private contributor checkout required')
    monkeypatch.setattr(native_try, 'context', refuse)
    with pytest.raises(SystemExit, match='private contributor checkout required'):
        native_try.main(SimpleNamespace(action='targets'))


def test_context_restores_unchanged_durable_submitted_generator(tmp_path, monkeypatch):
    generator = tmp_path / 'rebuild/2008-06/patches/make_rbxgs_client.py'
    generator.parent.mkdir(parents=True)
    generator.write_bytes(b'pass\n# submitted patch\n')
    generator.with_name('rbxgs-client.json').write_text('{}')
    job = tmp_path / 'work/integration-client/jobs/pending'
    job.mkdir(parents=True)
    (job/'submitted-generator.py').write_bytes(generator.read_bytes())
    (job/'generator-base.py').write_bytes(b'pass\n')
    base = {'generator': hashlib.sha256(b'pass\n').hexdigest(), 'overlay': {}, 'revision': 'base'}
    monkeypatch.setattr(native_try.native_sweep, 'ROOT', tmp_path)
    monkeypatch.setattr(native_try.worker, 'load_settings', lambda: {'server':'http://test'})
    monkeypatch.setattr(native_try.integration, 'native_token', lambda: 'test')
    monkeypatch.setattr(native_try.worker, 'Api', lambda *args: SimpleNamespace(call=lambda *args: base, close=lambda: None))
    monkeypatch.setattr(native_try.native_sweep, 'native_context', lambda *args: SimpleNamespace())
    monkeypatch.setattr(native_try.native_sweep.subprocess, 'run', lambda *args, **kwargs: None)
    assert native_try.context().base_revision == 'base'
    assert generator.read_bytes() == b'pass\n'


@pytest.mark.parametrize('globally_integrated', [False, True])
def test_targets_reads_accepted_overlay(tmp_path, monkeypatch, capsys, globally_integrated):
    tree, overlay = tmp_path / 'tree', tmp_path / 'overlay'
    rel = 'App/v8datamodel/A.cpp'
    for folder, text in ((tree, 'void A::old() {}'), (overlay, 'void A::newMethod() {}')):
        (folder / rel).parent.mkdir(parents=True)
        (folder / rel).write_text(text)
    ctx = SimpleNamespace(tree=tree, overlay=overlay, targets={'00000001'}, owned=set(),
                          names={'00000001': {'symbol': '?newMethod@A@@QAEXXZ'}}, by_addr={},
                          integrated={'00000001'} if globally_integrated else set())
    native_try.cmd_targets(ctx, SimpleNamespace(limit=20))
    assert (rel in capsys.readouterr().out) is not globally_integrated


@pytest.mark.parametrize('synced', [False, True])
def test_context_requires_synced_baseline_and_closes_api(tmp_path, monkeypatch, synced):
    generator = tmp_path / 'rebuild/2008-06/patches/make_rbxgs_client.py'
    generator.parent.mkdir(parents=True)
    generator.write_bytes(b'generator')
    generator.with_name('rbxgs-client.json').write_text('{}')
    base = {'generator': hashlib.sha256(b'generator').hexdigest(),
            'overlay': {} if synced else {'outdated': []}, 'revision': 'base'}
    closed = []
    monkeypatch.setattr(native_try.native_sweep, 'ROOT', tmp_path)
    monkeypatch.setattr(native_try.worker, 'load_settings', lambda: {'server': 'http://test'})
    monkeypatch.setattr(native_try.integration, 'native_token', lambda: 'test')
    monkeypatch.setattr(native_try.worker, 'Api', lambda *args:
                        SimpleNamespace(call=lambda *args: base, close=lambda: closed.append(True)))
    monkeypatch.setattr(native_try.native_sweep, 'native_context', lambda *args: SimpleNamespace())
    if synced:
        assert native_try.context().base_revision == 'base'
    else:
        with pytest.raises(ValueError, match='sync first'):
            native_try.context()
    assert closed == [True]


@pytest.mark.parametrize('partial', [False, True])
def test_submit_preserves_proposals_not_selected_for_batch(tmp_path, monkeypatch, partial):
    proposals = tmp_path / 'proposals.json'
    first, second = {'file': 'App/A.cpp'}, {'file': 'App/B.cpp'}
    proposals.write_text(json.dumps([first, second]))
    monkeypatch.setattr(native_try, 'PROPOSALS', proposals)
    paths = ['App/A.cpp'] if partial else ['App/A.cpp', 'App/B.cpp']
    monkeypatch.setattr(native_try.native_sweep, 'run', lambda *args, **kwargs:
                        {'job': 'test-job', 'applied_paths': paths})
    native_try.cmd_submit(SimpleNamespace(model='test'))
    assert json.loads((tmp_path / 'submitted-test-job.json').read_text()) == ([first] if partial else [first, second])
    assert json.loads(proposals.read_text()) == [second] if partial else not proposals.exists()


def test_submit_without_job_reports_failure_and_retains_proposals(tmp_path, monkeypatch):
    proposals = tmp_path / 'proposals.json'
    proposals.write_text('[{"file": "App/A.cpp"}]')
    original = proposals.read_bytes()
    monkeypatch.setattr(native_try, 'PROPOSALS', proposals)
    monkeypatch.setattr(native_try.native_sweep, 'run', lambda *args, **kwargs:
                        {'state': 'blocked', 'job': None, 'blocked_units': ['RBX::A']})
    with pytest.raises(SystemExit, match='No submission queued; saved proposals retained'):
        native_try.cmd_submit(SimpleNamespace(model='test'))
    assert proposals.read_bytes() == original
