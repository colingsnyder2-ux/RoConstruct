import hashlib
import json
from pathlib import Path
from types import SimpleNamespace

import pytest

from roc import native_try


def test_check_canonicalizes_against_baseline_after_context_sync(tmp_path, monkeypatch):
    monkeypatch.setattr(native_try.native_sweep, 'ROOT', tmp_path)
    registry = tmp_path / 'rebuild/2008-06/patches/rbxgs-client.json'
    registry.parent.mkdir(parents=True)
    registry.write_text('{}')
    def context():
        registry.write_text(json.dumps({'App/gui/GUI.cpp': [['old', 'accepted']]}))
        return 'synced-context'
    monkeypatch.setattr(native_try, 'context', context)
    calls = []
    monkeypatch.setattr(native_try, 'cmd_check', lambda ctx, args: calls.append((ctx, args.file)))
    native_try.dispatch(SimpleNamespace(action='check', file='App/gui/Gui.cpp'))
    assert calls == [('synced-context', 'App/gui/GUI.cpp')]


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
    monkeypatch.setattr(native_try.native_sweep.integration, 'run_generator', lambda *args, **kwargs: calls.append(args))
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


@pytest.fixture
def editable_trial(trial, tmp_path, monkeypatch):
    ctx, found, proposals, blocks = trial
    monkeypatch.setattr(native_try, 'OUT', tmp_path / 'native-try')
    ctx.tree, ctx.overlay = tmp_path / 'tree', tmp_path / 'overlay'
    for rel, text in [('App/A.cpp', 'old'), ('App/include/A.h', 'field')]:
        path = ctx.tree / rel
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(text)
    return ctx, found, proposals


def test_direct_edit_captures_saved_baseline_and_retains_original_tree(editable_trial):
    ctx, _, proposals = editable_trial
    args = SimpleNamespace(file='App/A.cpp', related=[], blocks=None)
    native_try.cmd_edit(ctx, args)
    draft = native_try.native_edit.folder(native_try.OUT, args.file) / args.file
    assert draft.read_text() == 'saved'
    draft.write_text('new', encoding='utf-8')
    native_try.cmd_check(ctx, args)
    result = json.loads(proposals.read_text())[0]
    assert result['edits'] == [['old', 'saved'], ['saved', 'new']]
    assert draft.read_text() == 'new'
    assert (ctx.tree / args.file).read_text() == 'old'
    assert list(draft.parents[1].glob('archive/*.json'))


def test_direct_edit_failure_preserves_candidate_and_saved_proof(editable_trial):
    ctx, found, proposals = editable_trial
    args = SimpleNamespace(file='App/A.cpp', related=[], blocks=None)
    native_try.cmd_edit(ctx, args)
    draft = native_try.native_edit.folder(native_try.OUT, args.file) / args.file
    draft.write_text('new', encoding='utf-8')
    original = proposals.read_bytes()
    found.remove('00000001')
    with pytest.raises(SystemExit):
        native_try.cmd_check(ctx, args)
    assert proposals.read_bytes() == original
    assert draft.read_text() == 'new'
    native_try.cmd_edit(ctx, args)
    assert draft.read_text() == 'new'


def test_direct_edit_paired_header_uses_same_minimization_gate(editable_trial):
    ctx, _, proposals = editable_trial
    args = SimpleNamespace(file='App/A.cpp', related=['App/include/A.h'], blocks=None)
    native_try.cmd_edit(ctx, args)
    folder = native_try.native_edit.folder(native_try.OUT, args.file)
    (folder / args.file).write_text('new', encoding='utf-8')
    (folder / args.related[0]).write_text('correct field', encoding='utf-8')
    compile_original = ctx.compile
    def compile_trial(*args):
        if ['field', 'correct field'] not in ctx.related_headers.get('App/include/A.h', []):
            return {'ok': False, 'error': 'missing declaration'}
        return compile_original(*args)
    ctx.compile = compile_trial
    native_try.cmd_check(ctx, args)
    result = json.loads(proposals.read_text())[0]
    assert result['related_headers'] == {'App/include/A.h': [['field', 'correct field']]}
    assert (folder / args.file).read_text() == 'saved'  # unnecessary CPP edit minimized away
    assert (ctx.tree / args.related[0]).read_text() == 'field'


def test_direct_edit_preserves_concurrent_candidate(editable_trial):
    ctx, _, _ = editable_trial
    args = SimpleNamespace(file='App/A.cpp', related=[], blocks=None)
    native_try.cmd_edit(ctx, args)
    path = native_try.native_edit.folder(native_try.OUT, args.file) / args.file
    path.write_text('new', encoding='utf-8')
    compile_original = ctx.compile
    def compile_trial(*args):
        path.write_text('newer unsaved work', encoding='utf-8')
        return compile_original(*args)
    ctx.compile = compile_trial
    native_try.cmd_check(ctx, args)
    assert path.read_text() == 'newer unsaved work'


def test_batch_direct_checks_reuse_context_and_continue_after_failure(tmp_path, monkeypatch):
    monkeypatch.setattr(native_try, 'OUT', tmp_path)
    for index, rel in enumerate(['App/A.cpp', 'App/B.cpp']):
        path = tmp_path / 'edit' / str(index) / 'edit.json'
        path.parent.mkdir(parents=True)
        path.write_text(json.dumps({'file': rel}))
    contexts, checked = [], []
    ctx = object()
    monkeypatch.setattr(native_try, 'context', lambda: contexts.append(True) or ctx)
    def check(context, args):
        assert context is ctx
        checked.append(args.file)
        if args.file == 'App/A.cpp':
            raise SystemExit(1)
    monkeypatch.setattr(native_try, 'cmd_check', check)
    with pytest.raises(SystemExit, match='App/A.cpp'):
        native_try.dispatch(SimpleNamespace(action='check', file=None, blocks=None, all=True))
    assert contexts == [True] and checked == ['App/A.cpp', 'App/B.cpp']


def test_direct_header_edit_remembers_real_caller(editable_trial):
    ctx, _, _ = editable_trial
    rel = 'App/include/A.h'
    ctx.translation_unit = 'App/A.cpp'
    native_try.native_edit.prepare(ctx, native_try.OUT, rel, [], {})
    del ctx.translation_unit
    native_try.cmd_edit(ctx, SimpleNamespace(file=rel, related=[], only=None))
    assert ctx.translation_unit == 'App/A.cpp'


def test_direct_edit_historical_compiler_roundtrip(tmp_path, monkeypatch):
    # Synthetic targets verify the actual historical compiler/cache path, never native credit.
    from roc import match, setup
    from roc import native_sweep as sweep
    if 21022 not in setup.compilers():
        pytest.skip('Historical MSVC 21022 not installed')
    tree, overlay, output = tmp_path/'tree', tmp_path/'overlay', tmp_path/'out'
    rel = 'App/v8world/Fixture.cpp'
    text = 'namespace RBX { struct Fixture { static int change(); static int keep(); }; }\nint RBX::Fixture::change() { return 1; }\nint RBX::Fixture::keep() { return 7; }\n'
    target = text.replace('return 1', 'return 2')
    original = tree/rel
    original.parent.mkdir(parents=True)
    original.write_text(text)
    def compile_source(source, rel, label):
        return sweep.compile_unit(source, rel, label, output, tree, overlay, [], '', '/O2 /GS- /EHsc /MD')
    proof = compile_source(target, rel, 'synthetic-target')
    assert proof['ok'], proof['error']
    functions = list(match.coff_functions(Path(proof['object']).read_bytes()))
    wanted = {}
    for addr, method in [('00000001', 'change'), ('00000002', 'keep')]:
        wanted[addr] = next((name, code, relocations) for name, code, relocations in functions if name.startswith('?'+method+'@Fixture@RBX@@'))
    class Matcher:
        def with_targets(self, addresses):
            return self
        def scan(self, data):
            actual = {name: (code, relocations) for name, code, relocations in match.coff_functions(data)}
            return [{'addr': addr, 'symbol': name} for addr, (name, code, relocations) in wanted.items()
                    if name in actual and match.exact_match(code, relocations, *actual[name])]
    ctx = SimpleNamespace(tree=tree, overlay=overlay, targets=set(wanted), owned=set(), base_revision='synthetic',
                          names={addr: {'symbol': row[0]} for addr,row in wanted.items()},
                          by_addr={addr: {'unit': 'RBX::Fixture'} for addr in wanted}, matcher=Matcher(), compile=compile_source)
    monkeypatch.setattr(native_try, 'OUT', output)
    monkeypatch.setattr(native_try, 'PROPOSALS', output/'proposals.json')
    monkeypatch.setattr(sweep, 'target_files', lambda *a: {rel: ['00000001']})
    monkeypatch.setattr(sweep, 'ownership_candidates', lambda obj,hits: {h['addr']: [h['addr']] for h in hits})
    args = SimpleNamespace(file=rel, related=[], blocks=None, only=None)
    native_try.cmd_edit(ctx, args)
    draft = native_try.native_edit.folder(output,rel)/rel
    draft.write_text(target, encoding='utf-8')
    native_try.cmd_check(ctx,args)
    assert native_try.saved()[0]['witnesses'][0]['addr'] == '00000001'
    native_try.cmd_check(ctx,args)
    assert native_try.saved()[0]['proof']['compile_cache_hit']
    assert original.read_text() == text


def test_direct_submit_refuses_newer_unchecked_edits(editable_trial):
    ctx, _, _ = editable_trial
    args = SimpleNamespace(file='App/A.cpp', related=[], blocks=None)
    native_try.cmd_edit(ctx, args)
    draft = native_try.native_edit.folder(native_try.OUT, args.file) / args.file
    draft.write_text('unfinished change', encoding='utf-8')
    with pytest.raises(ValueError, match='Unverified direct edits'):
        native_try.cmd_submit(SimpleNamespace(model='test'))
    assert draft.read_text() == 'unfinished change'


def test_batch_skips_unedited_files_without_saved_proofs(editable_trial, monkeypatch):
    ctx, _, _ = editable_trial
    rel = 'App/B.cpp'
    (ctx.tree / rel).write_text('void B::f() {}')
    native_try.native_edit.prepare(ctx, native_try.OUT, rel, [], {})
    monkeypatch.setattr(native_try, 'context', lambda: ctx)
    monkeypatch.setattr(native_try, 'cmd_check', lambda *args: pytest.fail('Unedited file compiled'))
    native_try.dispatch(SimpleNamespace(action='check', file=None, blocks=None, all=True))
