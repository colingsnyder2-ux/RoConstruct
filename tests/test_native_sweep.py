import hashlib
import json
from pathlib import Path
from types import SimpleNamespace

import pytest

from roc import native_sweep as sweep


def test_provider_family_keeps_real_instantiation_and_scopes_base_omission():
    source = '''namespace RBX {
void A::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider) {
 if (oldProvider) Instance::onServiceProvider(oldProvider, newProvider);
 run = ServiceProvider::create<RunService>(newProvider);
}
void B::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider) {
 Instance::onServiceProvider(oldProvider, newProvider);
}
}'''
    changed, edits = sweep.variant(source, 'runservice-outofline-no-base', {'A::onServiceProvider'})
    assert changed.count('template __declspec(noinline) RunService*') == 1
    assert 'if (oldProvider) ;' in changed
    assert changed.count('Instance::onServiceProvider(oldProvider, newProvider);') == 1
    assert sweep.apply_edits(source, edits) == changed
    again, _ = sweep.variant(changed, 'runservice-outofline-no-base', {'A::onServiceProvider'})
    assert again == changed
    outlined, _ = sweep.variant(source, 'runservice-outofline')
    assert outlined.count('Instance::onServiceProvider(oldProvider, newProvider);') == 2
    assert sweep.variant('// create<RunService>(provider)\nnamespace RBX {}', 'runservice-outofline')[1] == []


def test_provider_family_supports_global_using_namespace_source():
    source = 'using namespace RBX;\nvoid A::f() { create<RunService>(provider); }'
    changed, edits = sweep.variant(source, 'runservice-outofline')
    assert 'RBX::RunService* RBX::ServiceProvider::create<RBX::RunService>() const;' in changed
    assert sweep.apply_edits(source, edits) == changed
    assert sweep.variant(changed, 'runservice-outofline')[0] == changed
    with pytest.raises(ValueError, match='global using'):
        sweep.variant('namespace Other { ' + source + ' }', 'runservice-outofline')


def test_nonempty_trial_changes_only_selected_real_method_expressions():
    source = '''void A::candidate() {
    if (!items.empty()) use();
    while (!owner->items.empty()) use();
    if (!selected->empty()) use();
    const char* text = "!items.empty()";
    // !items.empty()
}
void A::other() { if (!items.empty()) use(); }
'''
    result, edits = sweep.variant(source, 'nonempty', selected={'A::candidate'})
    assert len(edits) == 1
    assert '(items.size() > 0)' in result and '(owner->items.size() > 0)' in result
    assert '(selected->size() > 0)' in result
    assert '"!items.empty()"' in result and '// !items.empty()' in result
    assert 'void A::other() { if (!items.empty()) use(); }' in result


def test_recipe_can_choose_only_nonempty_trials():
    trials = sweep.experiments('void A::f(){ if (!items.empty()) use(); }', ['nonempty'])
    assert [t[0] for t in trials] == ['baseline', 'nonempty']
    with pytest.raises(ValueError, match='list of mode names'):
        sweep.experiments('source', 'nonempty')


def test_foreign_claims_ignore_completed_and_released_leases(tmp_path, monkeypatch):
    import sqlite3
    import time
    (tmp_path / 'work').mkdir()
    db = sqlite3.connect(tmp_path / 'work/server.db')
    db.execute('CREATE TABLE integration_claims(unit TEXT,worker TEXT,expires REAL,state TEXT)')
    future = time.time() + 300
    db.executemany('INSERT INTO integration_claims VALUES(?,?,?,?)', [
        ('active', 'other', future, 'claimed'), ('queued', 'other', future, 'submitted'),
        ('parked', 'other', future, 'parked:header'), ('completed', 'other', future, 'accepted'),
        ('released', 'other', future, 'released'), ('expired', 'other', 0, 'claimed'),
        ('mine', 'alice@native-sweep:own-id', future, 'claimed')])
    db.commit()
    db.close()
    monkeypatch.setenv('ROC_NATIVE_EVIDENCE_ROOT', str(tmp_path))
    assert sweep.foreign_claims('alice', 'own-id') == {'active', 'queued', 'parked'}


@pytest.mark.parametrize('existing', [False, True])
@pytest.mark.parametrize('compiler_error', [False, True])
def test_header_trial_compiles_caller_and_restores_overlay(tmp_path, monkeypatch, existing, compiler_error):
    tree, overlay = tmp_path / 'tree', tmp_path / 'overlay'
    caller = tree / 'App/A.cpp'
    caller.parent.mkdir(parents=True)
    caller.write_text('#include "A.h"\nvoid A::f() {}')
    header = overlay / 'App/include/A.h'
    if existing:
        header.parent.mkdir(parents=True)
        header.write_bytes(b'original header\r\n')

    def compile_direct(client, sources, folder, *args):
        assert header.read_text() == 'candidate header'
        assert sources[0].name == 'A.cpp'
        if compiler_error:
            raise ValueError('compiler failure')
        sources[0].with_suffix('.obj').write_bytes(b'object')
        return {str(sources[0]): (True, '')}

    monkeypatch.setattr(sweep.rebuild, 'compile_direct', compile_direct)
    monkeypatch.setattr(sweep.rebuild, 'coff_externals', lambda data: {})
    if compiler_error:
        with pytest.raises(ValueError, match='compiler failure'):
            sweep.compile_unit('candidate header', 'App/include/A.h', 'trial', tmp_path/'out', tree, overlay, [], '', '',
                               translation_unit='App/A.cpp')
    else:
        result = sweep.compile_unit('candidate header', 'App/include/A.h', 'trial', tmp_path/'out', tree, overlay, [], '', '',
                                    translation_unit='App/A.cpp')
        assert result['ok'] and result['translation_unit'] == 'App/A.cpp'
    assert header.read_bytes() == b'original header\r\n' if existing else not header.exists()


def test_header_trial_cannot_write_outside_private_overlay(tmp_path):
    with pytest.raises(ValueError, match='inside the private overlay'):
        sweep.compile_unit('bad', '../vendor.h', 'trial', tmp_path/'out', tmp_path/'tree', tmp_path/'overlay', [], '', '',
                           translation_unit='App/A.cpp')


@pytest.mark.parametrize('existing', [False, True])
@pytest.mark.parametrize('compiler_error', [False, True])
def test_paired_headers_restore_exact_bytes_after_cpp_trial(tmp_path, monkeypatch, existing, compiler_error):
    tree, overlay = tmp_path / 'tree', tmp_path / 'overlay'
    original = tree / 'App/include/A.h'
    original.parent.mkdir(parents=True)
    original.write_bytes(b'original\r\n')
    header = overlay / 'App/include/A.h'
    if existing:
        header.parent.mkdir(parents=True)
        header.write_bytes(b'original\r\n')
    def compile_direct(client, sources, folder, *args):
        assert header.read_text() == 'changed\n'
        if compiler_error:
            raise ValueError('compiler failed')
        sources[0].with_suffix('.obj').write_bytes(b'object')
        return {str(sources[0]): (True, '')}
    monkeypatch.setattr(sweep.rebuild, 'compile_direct', compile_direct)
    monkeypatch.setattr(sweep.rebuild, 'coff_externals', lambda data: {})
    args = ('CPP trial', 'App/A.cpp', 'paired', tmp_path/'out', tree, overlay, [], '', '')
    if compiler_error:
        with pytest.raises(ValueError, match='compiler failed'):
            sweep.compile_unit(*args, related_headers={'App/include/A.h': [['original', 'changed']]})
    else:
        assert sweep.compile_unit(*args, related_headers={'App/include/A.h': [['original', 'changed']]})['related_header_sha256']
    assert header.read_bytes() == b'original\r\n' if existing else not header.exists()
    assert original.read_bytes() == b'original\r\n'


def test_paired_header_failure_restores_earlier_header(tmp_path):
    tree, overlay = tmp_path / 'tree', tmp_path / 'overlay'
    header = overlay / 'App/A.h'
    header.parent.mkdir(parents=True)
    header.write_bytes(b'original')
    (header.parent/'B.h').write_bytes(b'other')
    with pytest.raises(ValueError):
        sweep.compile_unit('CPP', 'App/A.cpp', 'paired', tmp_path/'out', tree, overlay, [], '', '',
                           related_headers={'App/A.h': [['original', 'changed']], 'App/B.h': [['absent', 'bad']]})
    assert header.read_bytes() == b'original'


def test_constructor_target_uses_actual_cpp_definition():
    symbol = '??0PartDragTool@RBX@@QAE@XZ'
    assert sweep.symbol_method(symbol) == 'PartDragTool::PartDragTool'
    assert sweep.target_files({'App/tool/PartDragTool.cpp': 'PartDragTool::PartDragTool() : Base(0) {}'},
                              {'00665f20'}, {'00665f20': {'symbol': symbol}}, {}) == {
                                  'App/tool/PartDragTool.cpp': ['00665f20']}
    assert sweep.claim_unit({'symbol': symbol}, {'unit': 'RBX::Mouse'}) == 'RBX::PartDragTool'


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


def test_plain_misattributed_unit_does_not_hide_actual_class_from_claim_conflicts():
    hit = {'symbol': '?setBackendToolStateNoReplicate@Tool@RBX@@AAEXH@Z'}
    assert sweep.claim_unit(hit, {'unit': 'RBX::Mouse'}) == 'RBX::Tool'


def test_unchanged_diagnostic_profiles_do_not_compile_twice():
    text = '#pragma float_control(precise, off)\nvoid A::f(){}\n'
    assert [mode for mode, _, error in sweep.experiments(text)] == ['baseline']
    text = '#include "A.h"\nvoid A::f(){}\n'
    assert [mode for mode, _, error in sweep.experiments(text)] == ['baseline', 'fp-fast']


def test_ternary_variant_handles_nested_conditions_and_keeps_other_methods():
    text = 'int A::f(){if (ready(x)) return value(); else return 0;}\nint A::g(){if (x) return 1; else return 2;}\n'
    changed, edits = sweep.variant(text, 'ternary', {'A::f'})
    assert 'return (ready(x)) ? (value()) : (0);' in changed
    assert 'int A::g(){if (x) return 1; else return 2;}' in changed
    assert len(edits) == 1


def test_ternary_variant_ignores_comments_literals_and_nonreturn_branches():
    text = 'const char* A::f(){/* if(x) return a; else return b; */ return "if(x) return a; else return b;";}\nvoid A::g(){if(x) work(); else return;}\n'
    assert sweep.variant(text, 'ternary') == (text, [])


@pytest.mark.parametrize('mode,expected', [('index-int', 'int'), ('index-size_t', 'size_t')])
def test_index_profiles_change_only_selected_method_loop_types(mode, expected):
    text = 'void A::f(){for(size_t i=0;i<n;++i)work(i);for(int j=0;j<n;++j)work(j);}\nvoid A::g(){for(std::size_t k=0;k<n;++k)work(k);}\n'
    changed, edits = sweep.variant(text, mode, {'A::f'})
    assert f'for({expected} i=0;' in changed and f'for({expected} j=0;' in changed
    assert 'void A::g(){for(std::size_t k=0;' in changed and len(edits) == 1


def test_index_profiles_ignore_comments_literals_and_pointer_iterators():
    text = 'void A::f(){/* for(size_t i=0;...) */ const char*s="for(int i=0;...)";for(int* p=begin;p!=end;++p)work(p);}\n'
    assert sweep.variant(text, 'index-size_t') == (text, [])


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


def test_target_routing_does_not_fall_back_from_known_template_to_stale_inventory():
    texts = {'App/v8datamodel/DataModel.cpp': 'void DataModel::close() {}'}
    inventory = {'00500000': {'unit': 'RBX::DataModel'}}
    assert sweep.target_files(texts, {'00500000'}, {}, inventory) == {'App/v8datamodel/DataModel.cpp': ['00500000']}
    assert not sweep.target_files(texts, {'00500000'}, {'00500000': {'symbol': '??$raise@VWorkspace@@'}}, inventory)


def test_ownership_checks_twins_outside_discovery_targets(monkeypatch):
    monkeypatch.setattr(sweep.match, 'coff_functions', lambda obj: [('f', b'body', []), ('unrelated', b'other', [])])
    def pair(client, functions):
        assert [f[0] for f in functions] == ['f']
        return [('f', 4, ['00500000', '00500010'])]
    monkeypatch.setattr(sweep.rebuild, 'pair', pair)
    assert sweep.ownership_candidates(b'obj', [{'addr': '00500000', 'symbol': 'f'}]) == {
        '00500000': ['00500000', '00500010']}


@pytest.mark.parametrize('missing_proof', [False, True])
def test_evidence_embeds_local_generated_proof_without_changing_compiled_reference(tmp_path, monkeypatch, missing_proof):
    from roc import packet, standins
    folder = tmp_path/'library'
    folder.mkdir()
    (folder/'roc_proof.cpp').write_text('struct RealProof { int value; };')
    source = '// roc-lib: fixture roc_proof.cpp\n'
    monkeypatch.setattr(packet, '_source', lambda *args: (source, '', 100))
    monkeypatch.setattr(sweep.match, 'target', lambda *args: (b'code', [], {}))
    assembly = ['nop'] * 121 + ['00500079: call 0x600000', '0050007e: jmp 0x600100', '00500083: jmp 0x500001']
    monkeypatch.setattr(sweep.match, 'disasm', lambda *args: assembly)
    if missing_proof:
        def unavailable(*args):
            raise FileNotFoundError('optional local library missing')
        monkeypatch.setattr(sweep.libs, '_case_path', unavailable)
    monkeypatch.setattr(sweep.libs, 'LIBS', tmp_path)
    monkeypatch.setitem(sweep.libs.RECIPES, 'fixture', {'src': 'library'})
    def mapping(client, addr, actual):
        assert actual == source
        return []
    monkeypatch.setattr(standins, 'mapping', mapping)
    result = sweep.model_evidence('00500000', {}, {})
    assert result['mined_source_expanded'] == (not missing_proof)
    assert ('struct RealProof' in result['mined_source']) == (not missing_proof)
    assert result['target_asm_truncated'] == {'shown': 120, 'total': len(assembly)}
    assert [call['addr'] for call in result['target_calls']] == ['00600000', '00600100']


@pytest.mark.parametrize('configured', [False, True])
def test_missing_mined_source_reports_error_and_closes_remote_api(monkeypatch, configured):
    from roc import packet
    closed = []
    monkeypatch.setattr(packet, '_source', lambda *a: ('', 'none', 0))
    monkeypatch.setattr(sweep.worker, 'load_settings', lambda: {'server': 'http://test'} if configured else {})
    monkeypatch.setattr(sweep.integration, 'native_token', lambda: None)
    monkeypatch.setattr(sweep.worker, 'Api', lambda *a: SimpleNamespace(close=lambda: closed.append(True)))
    with pytest.raises(ValueError, match='[Mm]ined source'):
        sweep.model_evidence('00500000', {}, {})
    assert closed == ([True] if configured else [])


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
                                                            (False, True, 'accepted'), (False, True, 'rejected'),
                                                            (False, True, 'timeout')])
@pytest.mark.parametrize('saved_proof', [False, True, 'stale', 'unversioned', 'ambiguous'])
def test_pipeline_recompiles_minimal_fix_before_claim_and_apply(tmp_path, monkeypatch, lose_owned, existing_owned, terminal, saved_proof):
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
    sweep.integration.atomic_json(root / 'rebuild/2008-06/out/native-names.json', {})
    sweep.integration.atomic_json(root / 'work/integration/progress-native.json', {'addresses': []})
    monkeypatch.setenv('ROC_NATIVE_EVIDENCE_ROOT', str(root))
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
                if saved_proof == 'stale' and not getattr(self, 'refreshed_claim', False):
                    self.refreshed_claim = True
                    return {'claims': [{'id': 'stale', 'base_revision': 'old-base'}]}
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
    monkeypatch.setattr(sweep, 'ownership_candidates', lambda obj, hits: {
        h['addr']: [h['addr'], '00500099'] if saved_proof == 'ambiguous' else [h['addr']] for h in hits})
    actions = []
    def command(args):
        actions.append(args.action)
        if args.action == 'submit':
            sweep.integration.atomic_json(root / 'work/integration-client/claims/own/job.json', {'id': 'verified-job'})
    monkeypatch.setattr(sweep.integration, 'command', command)
    config = {'manifest': str(manifest), 'owned_report': str(owned), 'files': ['App/*.cpp'],
              'apply': True, 'submit': bool(terminal), 'wait': bool(terminal), 'model': 'human'}
    if saved_proof:
        proposals = root / 'proposals.json'
        proposals.write_text(json.dumps([{'file': 'App/A.cpp', 'edits': [['RBXASSERT(candidate)', '']],
                                         'mode': 'model', 'proof': {'object': 'missing-stale.obj'},
                                         'witnesses': [{'addr': '00500001', 'symbol': '?candidate@A@RBX@@QAEXXZ',
                                                        'claim_unit': 'RBX::A'}],
                                         'base_revision': None if saved_proof == 'unversioned' else
                                                          'old-base' if saved_proof == 'stale' else 'base'}]))
        config['proposals_file'] = str(proposals)
    if saved_proof and (lose_owned or saved_proof == 'unversioned'):
        with pytest.raises(ValueError, match='unversioned|lost exact matches'):
            sweep.run({'native_sweep': config}, 'test', output=root / 'work/sweep', log=lambda _: None)
        assert generator.read_bytes() == original and '/v1/integration/claim' not in calls
        assert json.loads((root / 'work/sweep/summary.json').read_text())['state'] == 'failed'
        return
    if saved_proof == 'ambiguous':
        result = sweep.run({'native_sweep': config}, 'test', output=root / 'work/sweep', log=lambda _: None)
        assert result['proposed_files'] == 0 and result['local_exact'] == 0
        assert generator.read_bytes() == original and '/v1/integration/claim' not in calls
        return
    if terminal == 'timeout':
        def timeout(*args):
            raise TimeoutError('verification still pending')
        monkeypatch.setattr(sweep, 'wait_for_job', timeout)
        with pytest.raises(TimeoutError):
            sweep.run({'native_sweep': config}, 'test', output=root / 'work/sweep', log=lambda _: None)
        pending = json.loads((root / 'work/sweep/summary.json').read_text())
        assert pending['state'] == 'queued' and pending['job'] == 'verified-job'
        return
    result = sweep.run({'native_sweep': config}, 'test', output=root / 'work/sweep', log=lambda _: None)
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
        assert len(edits) == 1 and ('A::candidate' in edits[0][0] or saved_proof)
        assert all('A::keep' not in old and 'A::unrelated' not in old for old, _ in edits)
        assert calls.count('/v1/integration/claim') == (2 if saved_proof == 'stale' else 1)
        assert calls.count('/v1/integration/release') == (1 if saved_proof == 'stale' else 0)


def test_submit_network_failure_is_persisted_and_api_closed(tmp_path, monkeypatch):
    generator = tmp_path / 'rebuild/2008-06/patches/make_rbxgs_client.py'
    generator.parent.mkdir(parents=True)
    generator.write_text('# baseline')
    closed = []
    def fail(*args):
        raise sweep.worker.ApiFailure('offline', 'test timeout')
    monkeypatch.setattr(sweep, 'ROOT', tmp_path)
    monkeypatch.setattr(sweep.worker, 'load_settings', lambda: {'server': 'http://test'})
    monkeypatch.setattr(sweep.worker, 'Api', lambda *args: SimpleNamespace(call=fail, close=lambda: closed.append(True)))
    monkeypatch.setattr(sweep.integration, 'native_token', lambda: 'test')
    output = tmp_path / 'output'
    with pytest.raises(sweep.worker.ApiFailure, match='test timeout'):
        sweep.run({'native_sweep': {}}, 'test', output=output)
    summary = json.loads((output / 'summary.json').read_text())
    assert summary['state'] == 'failed' and summary['error'] == 'offline: test timeout'
    assert closed == [True]
def test_body_diff_hides_linked_relocations_but_retains_literal_difference(monkeypatch):
    from roc import native_sweep as sweep
    target = bytes.fromhex('68aabbccdd6a4dc3')
    candidate = bytes.fromhex('68000000006a4cc3')
    monkeypatch.setattr(sweep.match, 'coff_functions', lambda obj: [('symbol', candidate, [1])])
    monkeypatch.setattr(sweep.match, 'target', lambda *args: (target, [1], None))
    diff = sweep.body_diff(b'object', 'symbol', '00500000')
    assert '0xddccbbaa' not in diff
    assert '-push 0x4d' in diff and '+push 0x4c' in diff


def test_body_diff_distinguishes_symbol_address_from_pointer_load(monkeypatch):
    monkeypatch.setattr(sweep.match, 'coff_functions', lambda obj: [('symbol', bytes.fromhex('a10000000050c3'), [1])])
    monkeypatch.setattr(sweep.match, 'target', lambda *args: (bytes.fromhex('68aabbccddc3'), [1], None))
    diff = sweep.body_diff(b'obj', 'symbol', '00500000')
    assert '-push sym' in diff and '+mov eax, dword ptr [sym]' in diff
    assert 'push 0' not in diff


def test_body_diff_retains_large_nonrelocated_immediates(monkeypatch):
    monkeypatch.setattr(sweep.match, 'coff_functions', lambda obj: [('symbol', bytes.fromhex('b878563412c3'), [])])
    monkeypatch.setattr(sweep.match, 'target', lambda *args: (bytes.fromhex('b879563412c3'), [], None))
    diff = sweep.body_diff(b'obj', 'symbol', '00500000')
    assert '0x12345679' in diff and '0x12345678' in diff


def test_body_diff_preserves_literal_when_memory_address_is_relocated(monkeypatch):
    monkeypatch.setattr(sweep.match, 'coff_functions', lambda obj: [('symbol', bytes.fromhex('833d0000000001c3'), [2])])
    monkeypatch.setattr(sweep.match, 'target', lambda *args: (bytes.fromhex('833daabbccdd00c3'), [2], None))
    diff = sweep.body_diff(b'obj', 'symbol', '00500000')
    assert '-cmp dword ptr [sym], 0' in diff and '+cmp dword ptr [sym], 1' in diff


def test_body_diff_preserves_displacement_when_immediate_is_relocated(monkeypatch):
    monkeypatch.setattr(sweep.match, 'coff_functions', lambda obj: [('symbol', bytes.fromhex('c7800000020000000000c3'), [6])])
    monkeypatch.setattr(sweep.match, 'target', lambda *args: (bytes.fromhex('c78000000100aabbccddc3'), [6], None))
    diff = sweep.body_diff(b'obj', 'symbol', '00500000')
    assert '[eax + 0x10000], sym' in diff and '[eax + 0x20000], sym' in diff


def test_body_diff_handles_zero_displacement_symbol_with_scaled_index(monkeypatch):
    monkeypatch.setattr(sweep.match, 'coff_functions', lambda obj: [('symbol', bytes.fromhex('8b048500000000c3'), [3])])
    monkeypatch.setattr(sweep.match, 'target', lambda *args: (bytes.fromhex('8b0485aabbccddc3'), [3], None))
    assert sweep.body_diff(b'obj', 'symbol', '00500000') == 'identical after masking'
