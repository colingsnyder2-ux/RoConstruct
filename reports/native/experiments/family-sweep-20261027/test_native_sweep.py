import hashlib
import json
from pathlib import Path
from types import SimpleNamespace

import pytest

from roc import native_sweep as sweep


def test_recipe_modes_select_only_requested_compiler_experiments():
    trials = sweep.experiments('#include "A.h"\nvoid A::f() {}\n', ['fp-osize', 'fp-noautoinline'])
    assert [row[0] for row in trials] == ['baseline', 'fp-osize', 'fp-noautoinline']
    assert '#pragma optimize("s", on)' in trials[1][1]
    assert '#pragma auto_inline(off)' in trials[2][1]


def test_network_uses_its_installed_native_recipe_includes(tmp_path, monkeypatch):
    monkeypatch.setattr(sweep.libs, 'LIBS', tmp_path)
    monkeypatch.setattr(sweep.libs, '_case_path', lambda p: p)
    monkeypatch.setitem(sweep.libs.RECIPES, 'rbxgs-net', {'include': ['RakNet/source', 'Network/include/network', 'WINSDK'], 'defines': 'WIN32'})
    monkeypatch.setattr(sweep.rebuild, '_overlaid', lambda roots, files, overlay: (roots, files))
    contexts = sweep.compilation_contexts(['Network/API.cpp', 'App/A.cpp'], tmp_path, tmp_path / 'overlay')
    roots, defines = contexts['Network/']
    assert roots == [tmp_path / 'RakNet/source', tmp_path / 'Network/include/network']
    assert defines == 'WIN32 BOOST_ALL_NO_LIB'
    assert len(contexts) == 1


def test_assertion_edit_keeps_control_flow_and_ignores_literals():
    source = '''void A::candidate() const {
    if (ready) RBXASSERT(check("brace } and )")); else fallback();
    // RBXASSERT(comment);
    const char* label = "RBXASSERT(string)";
}'''
    result, edits = sweep.variant(source, 'assertions')
    assert len(edits) == 1
    assert 'else fallback();' in result and '; else' in result
    assert '// RBXASSERT(comment);' in result and '"RBXASSERT(string)"' in result
    assert 'RBXASSERT(check' not in result


def test_pragma_modes_prepend_once_in_fixed_order():
    source = '#include "A.h"\nvoid A::f() { RBXASSERT(x); g(); }\n'
    text, edits = sweep.variant(source, 'assertions-osize-noautoinline')
    assert text.startswith('#pragma optimize("s", on)\n#pragma auto_inline(off)\n#include "A.h"\n')
    assert 'RBXASSERT' not in text and len(edits) == 2
    assert sweep.variant(source, 'fp-fast')[0].startswith('#pragma float_control(precise, off)\n#include')
    assert sweep.variant(text, 'osize')[0].count('#pragma optimize') == 1  # already present: not added twice


def test_scoped_profile_changes_only_selected_method_and_restores_state():
    source = '#include "A.h"\nvoid A::keep() { g(); }\nvoid A::fix() { RBXASSERT(x); g(); }\n'
    changed, edits = sweep.variant(source, 'scoped-assertions-fp-noautoinline', {'A::fix'})
    assert len(edits) == 1
    assert 'void A::keep() { g(); }' in changed
    assert '#pragma float_control(push)' in changed and '#pragma float_control(pop)' in changed
    assert '#pragma auto_inline(off)' in changed and '#pragma auto_inline(on)' in changed
    assert 'RBXASSERT' not in changed
    assert changed.startswith('#include "A.h"')


def test_scoped_profile_preserves_existing_tu_inline_setting():
    changed, _ = sweep.variant('#pragma auto_inline(off)\nvoid A::f() {}\n', 'scoped-noautoinline')
    assert '#pragma auto_inline(on)' not in changed


def test_scoped_inline_depth_restores_existing_depth():
    source = '#pragma inline_depth(4)\nvoid A::f() {}\n'
    changed, _ = sweep.variant(source, 'scoped-depth0')
    assert '#pragma inline_depth(0)' in changed
    assert changed.endswith('#pragma inline_depth(4)\n\n')
    changed, _ = sweep.variant('void A::f() {}\n', 'scoped-depth0')
    assert '#pragma inline_depth()' in changed


def test_scoped_precise_fp_preserves_original_fp_context():
    changed, _ = sweep.variant('float A::f() { return x + y; }\n', 'scoped-fp-precise')
    assert '#pragma float_control(precise, on)' in changed
    assert '#pragma float_control(push)' in changed and '#pragma float_control(pop)' in changed


def test_scoped_minimization_keeps_only_new_exact_native_method():
    source = 'void A::keep() {}\nvoid A::fix() {}\n'
    proposal = sweep.proven_proposal(source, 'scoped-fp-fast',
        [{'addr': '00500000', 'symbol': '?fix@A@@QAEXXZ'}], set())
    assert len(proposal['edits']) == 1
    assert proposal['edits'][0][0] == 'A::fix() {}'


def test_foreign_claims_without_server_db_is_empty(tmp_path, monkeypatch):
    monkeypatch.setenv('ROC_NATIVE_EVIDENCE_ROOT', str(tmp_path))
    assert sweep.foreign_claims('colin', 'abc') == set()


def test_ambiguous_overloads_and_conditional_bodies_defer():
    source = '''void A::f(int) { RBXASSERT(x); }
void A::f(float) { RBXASSERT(y); }
void A::conditional() {
#ifdef USE_CHECK
RBXASSERT(z);
#endif
}
'''
    assert sweep.variant(source, 'assertions')[1] == []


def test_diagnostic_minimizes_to_newly_exact_real_method():
    source = 'void A::first(){RBXASSERT(x);}\nvoid A::second(){RBXASSERT(y);}\n'
    hits = [{'addr': '00500000', 'symbol': '?first@A@RBX@@QAEXXZ'},
            {'addr': '00500001', 'symbol': '?second@A@RBX@@QAEXXZ'},
            {'addr': '00500002', 'symbol': '??$templateNoise@std@@'}]
    proposal = sweep.proven_proposal(source, 'assertions', hits, {'00500000'})
    assert len(proposal['edits']) == 1
    assert 'RBXASSERT(x)' in proposal['source'] and 'RBXASSERT(y)' not in proposal['source']
    assert len(proposal['witnesses']) == 1


def test_ambiguous_byte_twins_are_not_automatic_fixes():
    hits = [{'addr': addr, 'symbol': '??1Joint@RBX@@UAE@XZ'} for addr in ['00500000', '00500001']]
    assert sweep.proven_proposal('Joint::~Joint(){RBXASSERT(owner);}\n', 'assertions', hits, set()) is None


def test_factory_tag_uses_compiled_native_class_for_scheduling():
    hit = {'symbol': '?computePersistentPart@PartInstance@RBX@@ABE?AVPart@2@XZ'}
    assert sweep.claim_unit(hit, {'unit': 'RBX::VPartInstance::?$FactoryProduct'}) == 'RBX::PartInstance'


def test_ownership_checks_twins_outside_the_discovery_pool(monkeypatch):
    hits = [{'addr': '00500000', 'symbol': '?f@A@@'}, {'addr': '00500001', 'symbol': '?g@A@@'}]
    monkeypatch.setattr(sweep.match, 'coff_functions', lambda _: [('?f@A@@', b'body', []), ('?g@A@@', b'other', [])])
    def pair(client, funcs):
        assert client == '2008-06' and len(funcs) == 2
        return [('?f@A@@', 4, ['00500000', '00700000']), ('?g@A@@', 5, ['00500001'])]
    monkeypatch.setattr(sweep.rebuild, 'pair', pair)
    kept, deferred = sweep.ownership_witnesses(b'object', hits)
    assert kept == [hits[1]]
    assert deferred[0]['addr'] == '00500000'


@pytest.mark.parametrize('failure', ['', 'lost', 'compile', 'ambiguous'])
@pytest.mark.parametrize('custom', [False, True])
def test_header_family_checks_all_transitive_dependents(tmp_path, monkeypatch, failure, custom):
    tree, overlay = tmp_path / 'tree', tmp_path / 'base'
    files = {'App/include/Core.h': 'inline void f(){RBXASSERT(ok);}\n',
             'Network/include/Bridge.h': '#include <Core.h>\n',
             'Network/Net.cpp': '#include "Bridge.h"\n'}
    if custom:
        files['App/include/Core.h'] = 'inline void f(){first();}\n'
    for rel, text in files.items():
        p = tree / rel
        p.parent.mkdir(parents=True, exist_ok=True)
        p.write_text(text)
    ranking = sweep.header_families(tree, overlay, ['Network/Net.cpp'], ['App/include/Core.h'] if custom else [])
    assert ranking[0]['file'] == 'App/include/Core.h'
    assert ranking[0]['files'] == ['Network/Net.cpp']
    def compile_unit(text, rel, label, output, tree, shadow, roots, defines, flags):
        is_variant = label != 'family-baseline'
        if is_variant:
            assert (shadow / 'Network/include/Bridge.h').read_text() == files['Network/include/Bridge.h']
            assert 'RBXASSERT' not in (shadow / 'App/include/Core.h').read_text()
            if custom:
                assert 'second();' in (shadow / 'App/include/Core.h').read_text()
        obj = output / (label + '.obj')
        obj.write_bytes(b'variant' if is_variant else b'baseline')
        return {'file': rel, 'ok': not (failure == 'compile' and is_variant), 'object': str(obj)}
    monkeypatch.setattr(sweep, 'compile_unit', compile_unit)
    monkeypatch.setattr(sweep, 'ownership_witnesses', lambda obj, hits: ([], hits) if failure == 'ambiguous' else (hits, []))
    keep = {'addr': '00500000', 'symbol': '?keep@A@@'}
    gain = {'addr': '00500001', 'symbol': '?f@A@@'}
    matcher = SimpleNamespace(scan=lambda obj: [keep] if obj == b'baseline' else
                              ([gain] if failure == 'lost' else [keep, gain]))
    out = tmp_path / 'out'
    out.mkdir()
    config = {'header_families': 1}
    if custom:
        config['family_edits'] = {'App/include/Core.h': {'edits': [['first();', 'second();']], 'evidence': 'Native instruction evidence'}}
    records, proposals, checks = sweep.discover_families(config, ['Network/Net.cpp'],
        tree, overlay, [tree / 'App/include', tree / 'Network/include'], '', '', matcher,
        {'00500001'}, {'00500000'}, {'00500001': {'unit': 'RBX::A'}}, out, 1, lambda _: None)
    assert len(records) == 2
    assert len(proposals) == (0 if failure else 1)
    if not failure:
        assert proposals[0]['witnesses'][0]['addr'] == '00500001'
    assert bool(checks) == (failure == 'ambiguous')


def test_rejected_family_split_keeps_gates_and_resyncs_each_half(tmp_path, monkeypatch):
    calls, synced = [], []
    def child(spec, name, server, jobs, output, log):
        calls.append(spec['native_sweep'])
        assert len(synced) == len(calls)
        return {'new_verified': 2}
    monkeypatch.setattr(sweep, 'run', child)
    monkeypatch.setattr(sweep.integration, 'command', lambda args: synced.append(args.action))
    monkeypatch.setattr(sweep.integration, 'native_token', lambda: 'private')
    config = {'header_families': 4, 'after_job': 'old', 'submit': True, 'wait': True, 'split_rejected': True}
    results = sweep.split_families({'native_sweep': config}, [{'file': str(n)} for n in range(4)],
                                  'families', 'server', 4, tmp_path, lambda _: None)
    assert [c['header_families'] for c in calls] == [['0', '1'], ['2', '3']]
    assert all(c['submit'] and c['wait'] and c['split_rejected'] and 'after_job' not in c for c in calls)
    assert config['header_families'] == 4 and config['after_job'] == 'old'
    assert sum(r['new_verified'] for r in results) == 4


def test_unchanged_diagnostic_profiles_do_not_compile_twice():
    text = '#pragma float_control(precise, off)\nvoid A::f(){}\n'
    assert [mode for mode, _, error in sweep.experiments(text)] == ['baseline']
    text = '#include "A.h"\nvoid A::f(){}\n'
    assert [mode for mode, _, error in sweep.experiments(text)] == ['baseline', 'fp-fast']


def test_matcher_resets_variants_and_requires_referenced_data(monkeypatch):
    reads = []
    class Target:
        def __init__(self, client):
            pass
        def same(self, addr, code, relocs):
            return code
    monkeypatch.setattr(sweep.fingerprint, 'Target', Target)
    monkeypatch.setattr(sweep.match, '_functions', lambda _: {addr: {'size': 30} for addr in ['00500000', '00500001']})
    monkeypatch.setattr(sweep.match, 'coff_functions', lambda _: [('?f@A@RBX@@', b'x'*30, [])])
    monkeypatch.setattr(sweep.match, 'coff_data_refs', lambda obj, name: reads.append(name) or ['refs'])
    def check(client, addr, code, refs):
        assert refs == ['refs']
        return [], ['data mismatch'] if addr == '00500001' else []
    monkeypatch.setattr(sweep.match, 'data_check', check)
    matcher = sweep.Matcher({'00500000', '00500001'})
    assert matcher.scan(b'object') == matcher.scan(b'object') == [{'addr': '00500000', 'symbol': '?f@A@RBX@@'}]
    assert len(reads) == 2


def test_staging_preserves_concurrent_user_edits(tmp_path, monkeypatch):
    monkeypatch.setattr(sweep, 'ROOT', tmp_path)
    generator = tmp_path / 'generator.py'
    original = (sweep.OUTPUT_MARKER + '\n').encode()
    generator.write_bytes(original + b'# user edit\n')
    with pytest.raises(ValueError, match='changed'):
        sweep.stage_generator(generator, original, {'App/A.cpp': [['old', 'new']]})
    assert generator.read_bytes().endswith(b'# user edit\n')


def test_authoritative_server_checkout_cannot_be_staged(tmp_path, monkeypatch):
    (tmp_path / 'work').mkdir()
    (tmp_path / 'work/server.db').touch()
    monkeypatch.setattr(sweep, 'ROOT', tmp_path)
    generator = tmp_path / 'generator.py'
    original = (sweep.OUTPUT_MARKER + '\n').encode()
    generator.write_bytes(original)
    with pytest.raises(ValueError, match='private contributor'):
        sweep.stage_generator(generator, original, {'App/A.cpp': [['old', 'new']]})
    assert generator.read_bytes() == original


@pytest.mark.parametrize('state', ['accepted', 'rejected'])
def test_wait_uses_authoritative_terminal_receipt(monkeypatch, state):
    rows = iter([{'state': 'verifying', 'phase': 'building'}, {'state': 'verifying', 'phase': 'building'},
                 {'state': state, 'phase': 'complete', 'receipt': {'accepted': state == 'accepted', 'credits': 2 if state == 'accepted' else 0}}])
    api = SimpleNamespace(call=lambda path: {'jobs': [next(rows)]})
    monkeypatch.setattr(sweep.time, 'sleep', lambda _: None)
    logs = []
    result = sweep.wait_for_job(api, 'job', 30, logs.append)
    assert result['state'] == state and len(logs) == 2
    assert result['receipt']['accepted'] == (state == 'accepted')


def test_wait_survives_server_restart_without_resubmitting(monkeypatch):
    calls = []
    def call(path):
        calls.append(path)
        if len(calls) < 3:
            raise sweep.worker.ApiFailure('offline', 'restarting')
        return {'jobs': [{'state': 'accepted', 'phase': 'complete', 'receipt': {'accepted': True}}]}
    monkeypatch.setattr(sweep.time, 'sleep', lambda _: None)
    logs = []
    assert sweep.wait_for_job(SimpleNamespace(call=call), 'existing', 30, logs.append)['state'] == 'accepted'
    assert calls == ['/v1/integration?id=existing'] * 3
    assert len(logs) == 2


def test_wait_does_not_retry_auth_failure():
    def call(path):
        raise sweep.worker.ApiFailure('auth_fail', 'invalid invitation')
    with pytest.raises(sweep.worker.ApiFailure, match='auth_fail'):
        sweep.wait_for_job(SimpleNamespace(call=call), 'existing', 30, lambda _: None)


def test_campaign_wait_rejects_stale_run_and_follows_saved_terminal_receipt(tmp_path, monkeypatch):
    path = tmp_path / 'summary.json'
    path.write_text(json.dumps({'run_id': 'old', 'state': 'accepted'}))
    saved = tmp_path / 'runs/new.json'
    def finish(_):
        saved.parent.mkdir(exist_ok=True)
        saved.write_text(json.dumps({'run_id': 'new', 'state': 'no-proposals'}))
    monkeypatch.setattr(sweep.time, 'sleep', finish)
    result = sweep.wait_for_campaign({'summary': str(path), 'run_id': 'new'}, 5, lambda _: None)
    assert result['run_id'] == 'new' and result['state'] == 'no-proposals'


@pytest.mark.parametrize('lose_owned,existing_owned,terminal', [(False, True, None), (True, True, None), (False, False, None),
                                                            (False, True, 'accepted'), (False, True, 'rejected')])
@pytest.mark.parametrize('source_kind', ['snippet', 'vendor-file', 'generated-unit'])
@pytest.mark.parametrize('retention', [False, True])
def test_pipeline_recompiles_minimal_fix_before_claim_and_apply(tmp_path, monkeypatch, lose_owned, existing_owned, terminal, source_kind, retention):
    root = tmp_path / 'checkout'
    tree, overlay = root / 'tools/rbxgs/Client', root / 'work/overlay'
    source = tree / 'App/A.cpp'
    source.parent.mkdir(parents=True)
    source.write_text('void A::keep(){RBXASSERT(keep);}\n'
                      'void A::candidate(){RBXASSERT(candidate);}\n'
                      'void A::unrelated(){RBXASSERT(unrelated);}\n')
    generator = root / 'rebuild/2008-06/patches/make_rbxgs_client.py'
    generator.parent.mkdir(parents=True)
    original = ('import json\nfrom pathlib import Path\npatches={}\n'
                'out=Path(__file__).with_name("rbxgs-client.json")\n' + sweep.OUTPUT_MARKER + '\n').encode()
    generator.write_bytes(original)
    generator.with_name('rbxgs-client.json').write_text('{}')
    base = {'generator': hashlib.sha256(original).hexdigest(), 'overlay': {}, 'revision': 'base'}
    manifest, owned = root / 'manifest.json', root / 'owned.json'
    manifest.write_text(json.dumps([{'addr': '00500001', 'score': 100, 'source_kind': source_kind, 'unit': 'RBX::A'}]))
    owned.write_text(json.dumps({'owned_addrs': ['00500000'] if existing_owned else []}))
    calls = []
    class Api:
        def call(self, path, body=None):
            calls.append(path)
            if path.endswith('/base'):
                return base
            if path == '/v1/integration':
                return {'jobs': []}
            if path == '/v1/integration?id=settled':
                return {'jobs': [{'state': 'rejected', 'phase': 'complete', 'receipt': {'accepted': False}}]}
            if path.startswith('/v1/integration?id='):
                return {'jobs': [{'state': terminal, 'phase': 'complete', 'receipt':
                                 {'accepted': terminal == 'accepted', 'credits': 1 if terminal == 'accepted' else 0}}]}
            if path.endswith('/claim'):
                return {'claims': [{'id': 'own', 'unit': 'RBX::A', 'addresses': ['00500001'],
                                    'base_revision': 'base', 'baseline': base, 'user': 'alice'}]}
            return {'ok': True}
        def close(self):
            pass
    class Matcher:
        def __init__(self, addresses):
            assert addresses == ({'00500000', '00500001'} if existing_owned else {'00500001'})
        def scan(self, obj):
            text = obj.decode()
            hits = []
            if existing_owned and 'RBXASSERT(keep)' in text and not (lose_owned and 'RBXASSERT(candidate)' not in text):
                hits.append({'addr': '00500000', 'symbol': '?keep@A@RBX@@QAEXXZ'})
            if retention or 'RBXASSERT(candidate)' not in text:
                hits.append({'addr': '00500001', 'symbol': '?candidate@A@RBX@@QAEXXZ'})
            return hits
    def compile_unit(text, rel, label, output, *args):
        obj = output / (label + '.obj')
        obj.write_bytes(text.encode())
        return {'file': rel, 'mode': label, 'ok': True, 'object': str(obj)}
    monkeypatch.setattr(sweep, 'ROOT', root)
    monkeypatch.setattr(sweep.worker, 'load_settings', lambda: {'user': 'alice', 'server': 'http://test'})
    monkeypatch.setattr(sweep.worker, 'Api', lambda *args: Api())
    monkeypatch.setattr(sweep.integration, 'native_token', lambda: 'test')
    monkeypatch.setattr(sweep.rebuild, 'load_module', lambda *args: {'overlay': {}})
    monkeypatch.setattr(sweep.rebuild, 'build_overlay', lambda *args: (tree, overlay))
    monkeypatch.setattr(sweep.rebuild, 'toolchain', lambda: {})
    monkeypatch.setitem(sweep.libs.RECIPES, 'rbxgs', {'include': [], 'defines': ''})
    monkeypatch.setattr(sweep, 'Matcher', Matcher)
    monkeypatch.setattr(sweep, 'compile_unit', compile_unit)
    monkeypatch.setattr(sweep, 'ownership_witnesses', lambda obj, hits: (hits, []))
    actions = []
    def command(args):
        actions.append(args.action)
        if args.action == 'submit':
            sweep.integration.atomic_json(root / 'work/integration-client/claims/own/job.json', {'id': 'verified-job'})
    monkeypatch.setattr(sweep.integration, 'command', command)
    result = sweep.run({'native_sweep': {'manifest': str(manifest), 'owned_report': str(owned), 'files': ['App/*.cpp'],
                                       'modes': ['assertions'],
                                       'source_kinds': [source_kind], 'retain_existing_objects': retention,
                                       'settle_jobs': ['settled'] if terminal else [],
                                       'apply': True, 'submit': bool(terminal), 'wait': bool(terminal), 'model': 'human'}},
                       'test', output=root / 'work/sweep', log=lambda _: None)
    assert result['new_verified'] == (1 if terminal == 'accepted' else 0)
    if terminal:
        assert actions == (['sync', 'submit', 'sync'] if terminal == 'accepted' else ['sync', 'submit'])
        assert '/v1/integration?id=settled' in calls
        assert result['state'] == terminal
    if lose_owned:
        assert result['proposed_files'] == 0 and generator.read_bytes() == original
        assert '/v1/integration/claim' not in calls
    else:
        assert result['applied_files'] == 1
        edits = json.loads(generator.with_name('rbxgs-client.json').read_text())['App/A.cpp']
        assert len(edits) == 1 and 'A::candidate' in edits[0][0]
        assert all('A::keep' not in old and 'A::unrelated' not in old for old, _ in edits)
        assert '/v1/integration/claim' in calls and '/v1/integration/release' not in calls
