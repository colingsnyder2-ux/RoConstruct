import hashlib
import json
from pathlib import Path
from types import SimpleNamespace

import pytest

from roc import native_sweep as sweep


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


@pytest.mark.parametrize('lose_owned,existing_owned,terminal', [(False, True, None), (True, True, None), (False, False, None),
                                                            (False, True, 'accepted'), (False, True, 'rejected')])
def test_pipeline_recompiles_minimal_fix_before_claim_and_apply(tmp_path, monkeypatch, lose_owned, existing_owned, terminal):
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
    manifest.write_text(json.dumps([{'addr': '00500001', 'score': 100, 'source_kind': 'snippet', 'unit': 'RBX::A'}]))
    owned.write_text(json.dumps({'owned_addrs': ['00500000'] if existing_owned else []}))
    calls = []
    class Api:
        def call(self, path, body=None):
            calls.append(path)
            if path.endswith('/base'):
                return base
            if path == '/v1/integration':
                return {'jobs': []}
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
            if 'RBXASSERT(candidate)' not in text:
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
    actions = []
    def command(args):
        actions.append(args.action)
        if args.action == 'submit':
            sweep.integration.atomic_json(root / 'work/integration-client/claims/own/job.json', {'id': 'verified-job'})
    monkeypatch.setattr(sweep.integration, 'command', command)
    result = sweep.run({'native_sweep': {'manifest': str(manifest), 'owned_report': str(owned), 'files': ['App/*.cpp'],
                                       'apply': True, 'submit': bool(terminal), 'wait': bool(terminal), 'model': 'human'}},
                       'test', output=root / 'work/sweep', log=lambda _: None)
    assert result['new_verified'] == (1 if terminal == 'accepted' else 0)
    if terminal:
        assert actions == (['submit', 'sync'] if terminal == 'accepted' else ['submit'])
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
