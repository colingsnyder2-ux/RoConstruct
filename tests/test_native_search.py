import json
from pathlib import Path
from types import SimpleNamespace

import pytest

from roc import native_search as search, native_sweep as sweep, match, setup


def test_partials_keep_structural_alternative_reject_losses_stale_revision_and_tampering(tmp_path):
    store = search.Partials(tmp_path, 'revision')
    result = dict(ok=True, object='candidate.obj', object_sha256='hash')
    baseline = {'a': dict(score=70, frame_ok=False, calls_ok=False)}
    rows = lambda score, frame=False: {'a': dict(score=score, frame_ok=frame, calls_ok=False, blocker='frame-lifetime')}
    assert store.retain('App/A.cpp', 'original', 'bytes-better', result, rows(90), baseline, []) == ['a']
    assert store.retain('App/A.cpp', 'original', 'frame-better', result, rows(80, True), baseline, []) == ['a']
    assert not store.retain('App/A.cpp', 'original', 'loses-exact', result, rows(99), baseline, ['owned'])
    assert not store.retain('App/A.cpp', 'original', 'worse', result, rows(75), baseline, [])
    entries = json.loads(next(store.root.glob('*.json')).read_text())
    assert {e['source'] for e in entries} == {'bytes-better', 'frame-better'}
    assert all(not e['accepted'] and e['losses'] == [] for e in entries)
    assert store.seed('App/A.cpp', 'original', ['a'])['source'] == 'bytes-better'
    assert search.Partials(tmp_path, 'next').seed('App/A.cpp', 'original', ['a']) is None
    assert store.seed('App/A.cpp', 'changed-original', ['a']) is None
    path = next(store.root.glob('*.json'))
    for entry in entries:
        entry['source'] = 'tampered'
    path.write_text(json.dumps(entries))
    assert store.seed('App/A.cpp', 'original', ['a']) is None


def test_diagnostic_separates_data_mismatch_missing_body_and_fuzzy_relocations(monkeypatch):
    code = bytes.fromhex('a100000000c3')
    monkeypatch.setattr(match, 'coff_functions', lambda _: [('method', code, [1])])
    monkeypatch.setattr(match, 'target', lambda *args: (code, [1], None))
    monkeypatch.setattr(match, 'coff_data_refs', lambda *args: [])
    monkeypatch.setattr(match, 'data_check', lambda *args: ([], ['wrong string']))
    rows = search.diagnose(b'obj', {'a': 'method', 'b': 'missing'})
    assert rows['a']['blocker'] == 'referenced-data' and not rows['a']['data_exact']
    assert rows['b']['blocker'] == 'missing-body'
    monkeypatch.setattr(match, 'coff_functions', lambda _: [('method', code, [])])
    row = search.diagnose(b'obj', {'a': 'method'})['a']
    assert row['score'] == 100 and not row['code_exact']  # fuzzy union mask cannot certify exact


def test_scoped_profiles_include_return_type_leave_other_method_and_existing_state_alone():
    source = 'namespace RBX {\nunsigned int A::f() { return 1; }\nvoid A::g() {}\n}'
    candidates = list(search.scoped_variants(source, ['scoped-osize', 'scoped-fp'], {'A::f'}))
    assert len(candidates) == 2
    for mode, candidate, edits in candidates:
        assert sweep.apply_edits(source, edits) == candidate
        assert 'void A::g() {}' in candidate
        assert candidate.index('#pragma') < candidate.index('unsigned int A::f')
        assert candidate.rfind('#pragma') < candidate.index('void A::g')
    assert not list(search.scoped_variants('#pragma optimize("s", on)\n' + source, ['scoped-osize']))


@pytest.mark.skipif(21022 not in setup.compilers(), reason='historical compiler not installed')
def test_scoped_profiles_compile_with_historical_msvc():
    source = 'namespace RBX {\nclass A { public: int f(); int g(); };\nint A::f(){return 1;}\nint A::g(){return 2;}\n}\n'
    for _, candidate, _ in search.scoped_variants(source,
            ['scoped-osize', 'scoped-speed', 'scoped-fp', 'scoped-noautoinline'], {'A::f'}):
        obj = match.compile_text('2008-06', candidate, flags='/O2 /GS- /EHsc /MD', build=21022)
        assert any(s.startswith('?g@A@RBX@@') for s, _, _ in match.coff_functions(obj))


def test_merged_proofs_require_every_witness_and_preserve_first_when_second_loses():
    choices = [dict(edits=[['one', 'ONE']], witnesses=[dict(addr='a')]),
               dict(edits=[['two', 'TWO']], witnesses=[dict(addr='b')]),
               dict(edits=[['one', 'different']], witnesses=[dict(addr='c')])]
    verified = []
    def verify(source, wanted):
        verified.append((source, wanted))
        return dict(losses=[]) if source != 'ONE TWO' else None
    result = search.merge_choices('one two', choices, verify)
    assert result['edits'] == [['one', 'ONE']]
    assert verified == [('ONE two', {'a'}), ('ONE TWO', {'a', 'b'})]
    result = search.merge_choices('one two', choices[:2], lambda source, wanted: dict(losses=[]))
    assert {w['addr'] for w in result['witnesses']} == {'a', 'b'}


def test_composed_seed_edits_roundtrip_repeated_lines():
    original = 'int A::f(){\n return 1;\n}\nint A::g(){\n return 1;\n}\n'
    candidate = original.replace('return 1', 'return 2', 1).replace('int A::g()', 'int A::g() /* context */')
    edits = search.anchored_changes(original, candidate)
    assert sweep.apply_edits(original, edits) == candidate


def grid_fixture(tmp_path, monkeypatch, hits=True):
    source = 'void A::one(){RBXASSERT(one);}\nvoid A::two(){RBXASSERT(two);}\nvoid A::keep(){}\n'
    names = {'a': dict(symbol='?one@A@RBX@@QAEXXZ'), 'b': dict(symbol='?two@A@RBX@@QAEXXZ')}
    inventory = {a: dict(unit='RBX::A') for a in names}
    records, signature = [], ['headers-v1']
    def compile(source, rel, label):
        records.append(label)
        folder = tmp_path / 'objects'
        folder.mkdir(exist_ok=True)
        obj = folder / (sweep.integration.digest([rel, label]) + '.obj')
        obj.write_text(source)
        return dict(file=rel, mode=label, ok=True, object=str(obj), input_signature=signature[0], object_sha256=sweep.integration.digest(source))
    def scan(data):
        text = data.decode()
        return [dict(addr=a, symbol=s) for a, s, present in [('owned', '?keep@A@RBX@@QAEXXZ', True),
            ('a', names['a']['symbol'], hits and 'RBXASSERT(one)' not in text),
            ('b', names['b']['symbol'], hits and 'RBXASSERT(two)' not in text)] if present]
    monkeypatch.setattr(sweep, 'ownership_candidates', lambda obj, rows: {h['addr']: [h['addr']] for h in rows})
    rules = [dict(name=name, files=['App/A.cpp'], evidence='target-call-order', edits=[[f'RBXASSERT({name});', ';']]) for name in ('one', 'two')]
    config = dict(modes=[], scoped_modes=[], rewrite_rules=rules, base_revision='revision', keep_partials=False)
    def run():
        return sweep.grid_discovery(config, {'App/A.cpp': source}, {'a', 'b'}, SimpleNamespace(scan=scan, identity='target'),
                                    tmp_path, 2, compile, names, inventory, lambda _: None)
    return run, records, signature, config


def test_grid_combines_disjoint_winners_and_journals_final_legacy_snapshot(tmp_path, monkeypatch):
    run, _, _, _ = grid_fixture(tmp_path, monkeypatch)
    proposals, records, checks = run()
    assert len(proposals) == 1
    assert {h['addr'] for h in proposals[0]['witnesses']} == {'a', 'b'}
    assert not proposals[0]['proof']['losses']
    assert checks and json.loads((tmp_path / 'trials.json').read_text()) == records
    assert len((tmp_path / 'trials.jsonl').read_text().splitlines()) == len(records)


def test_exhausted_grid_retries_after_header_or_search_change(tmp_path, monkeypatch):
    run, compiled, signature, config = grid_fixture(tmp_path, monkeypatch, hits=False)
    run()
    assert len(compiled) == 3
    compiled.clear()
    run()
    assert compiled == ['baseline']
    signature[0] = 'headers-v2'
    compiled.clear()
    run()
    assert len(compiled) == 3
    config['retry_exhausted'] = True
    compiled.clear()
    run()
    assert len(compiled) == 3


def test_grid_rejects_ambiguous_ownership(tmp_path, monkeypatch):
    run, _, _, _ = grid_fixture(tmp_path, monkeypatch)
    monkeypatch.setattr(sweep, 'ownership_candidates', lambda obj, rows: {h['addr']: [h['addr'], 'twin'] for h in rows})
    proposals, _, _ = run()
    assert not proposals
    assert json.loads((tmp_path / 'blockers.json').read_text())['ambiguous-ownership']


def test_rewrite_rules_need_evidence_and_explicit_family():
    rules = [dict(name='pair', files=['App/A.cpp'], edits=[['old', 'new']])]
    assert not list(search.explicit_variants('old', rules, 'App/A.cpp'))
    rules[0]['evidence'] = 'measured-layout'
    assert list(search.explicit_variants('old', rules, 'App/A.cpp'))
    assert not list(search.explicit_variants('old', rules, 'App/B.cpp'))


def test_match_cache_retains_negatives_but_invalidates_changed_target(tmp_path, monkeypatch):
    from roc.fingerprint import Target
    target = Target.__new__(Target)
    target.base, target.image, target.relocs = 0x500000, b'abcdef', []
    monkeypatch.setattr(sweep.fingerprint, 'Target', lambda _: target)
    monkeypatch.setattr(match, '_functions', lambda _: {'00500000': dict(size=6)})
    reads = []
    monkeypatch.setattr(match, 'coff_functions', lambda obj: (reads.append(obj), [('f', b'ghijkl', [])])[1])
    assert sweep.Matcher({'00500000'}, tmp_path).scan(b'object') == []
    assert sweep.Matcher({'00500000'}, tmp_path).scan(b'object') == []
    assert len(reads) == 1
    target.image = b'changed'
    assert sweep.Matcher({'00500000'}, tmp_path).scan(b'object') == []
    assert len(reads) == 2


def test_model_resumes_partial_emits_once_and_rebases_winner_to_original(tmp_path, monkeypatch):
    from roc import providers
    rel, original = 'App/A.cpp', 'int A::one(){return 1;}\n'
    symbol = '?one@A@RBX@@QAEHXZ'
    names = {'a': dict(symbol=symbol, score=70)}
    events, compiled = [], []
    replies = iter(['<<<<<<< SEARCH\nreturn 1;\n=======\nreturn 2;\n>>>>>>> REPLACE',
                    '<<<<<<< SEARCH\nreturn 2;\n=======\nreturn 3;\n>>>>>>> REPLACE'])
    monkeypatch.setattr(providers, 'generate', lambda *args: SimpleNamespace(text=next(replies)))
    monkeypatch.setattr(sweep, 'model_evidence', lambda *args: dict(addr='a', rebuilt_symbol=symbol))
    monkeypatch.setattr(sweep, 'body_diff', lambda *args: 'target vs rebuilt')
    monkeypatch.setattr(sweep, 'ownership_candidates', lambda obj, rows: {h['addr']: [h['addr']] for h in rows})
    def diagnose(data, symbols):
        score = 100 if b'return 3' in data else 80 if b'return 2' in data else 70
        return {'a': dict(score=score, frame_ok=False, calls_ok=False, data_exact=score == 100,
                          blocker='instruction-order', recipes=['scoped-osize'], symbol=symbol)}
    monkeypatch.setattr(search, 'diagnose', diagnose)
    def compile(source, rel, label):
        compiled.append(source)
        obj = tmp_path / (sweep.integration.digest([source, label]) + '.obj')
        obj.write_text(source)
        return dict(file=rel, mode=label, ok=True, object=str(obj), input_signature='headers',
                    object_sha256=sweep.integration.digest(source), seconds=0)
    matcher = SimpleNamespace(identity='target', scan=lambda data: [dict(addr='a', symbol=symbol)] if b'return 3' in data else [])
    config = dict(llm='codex:default', rounds=1, keep_partials=True, base_revision='revision',
                  provider_options=dict(event=lambda kind, **row: events.append((kind, row))))
    run = lambda: sweep.model_discovery(config, {rel: original}, {'a'}, set(), {'a': dict(unit='RBX::A')},
                                        matcher, tmp_path, 1, lambda _: None, compile, names)
    assert not run()[0]
    proposals, _ = run()
    assert len(proposals) == 1
    assert sweep.apply_edits(original, proposals[0]['edits']) == original.replace('return 1', 'return 3')
    partial_events = [row for kind, row in events if kind == 'native_partial']
    assert len(partial_events) == 1 and partial_events[0]['previous'] == 70 and partial_events[0]['score'] == 80
    assert partial_events[0]['slot'] == 0 and not partial_events[0]['accepted']
    assert any('return 2' in source for source in compiled)
