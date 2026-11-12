import hashlib
import json
from pathlib import Path
from types import SimpleNamespace

import pytest
from roc import native_sweep as sweep


def test_recovery_archive_is_immutable_versioned_and_keeps_original_model(tmp_path):
    proposals = [dict(file='App/A.cpp', base_revision='old', edits=[['old', 'new']])]
    ticket = sweep.hold_proposals(tmp_path, proposals, 'old', model='codex:original')
    selected, archive = sweep.pending_proposals(tmp_path, 'new')
    assert selected == ticket
    before = archive.read_bytes()
    assert json.loads(before) == proposals
    assert json.loads(ticket.read_text())['model'] == 'codex:original'
    assert json.loads(ticket.read_text())['attempted_revision'] == 'new'
    assert sweep.pending_proposals(tmp_path, 'new') == (ticket, archive)  # interrupted recheck resumes
    assert archive.read_bytes() == before
    archive.write_bytes(before+b' ')
    with pytest.raises(ValueError, match='hash mismatch'):
        sweep.pending_proposals(tmp_path, 'new')


def test_blocked_recovery_waits_for_new_revision_and_unattributed_proofs_stay_local(tmp_path):
    sweep.hold_proposals(tmp_path, [], 'old')
    assert sweep.pending_proposals(tmp_path, 'new') == (None, None)
    ticket = sweep.hold_proposals(tmp_path, [], 'old', state='blocked', model='claude:original')
    assert sweep.pending_proposals(tmp_path, 'old') == (None, None)
    assert sweep.pending_proposals(tmp_path, 'new')[0] == ticket
    record = json.loads(ticket.read_text())
    sweep.integration.atomic_json(ticket, dict(record, state='done'))
    assert sweep.pending_proposals(tmp_path, 'third') == (None, None)


def test_recovery_archive_cannot_escape_owned_directory(tmp_path):
    ticket = sweep.hold_proposals(tmp_path, [], 'old', model='codex:original')
    outside = tmp_path/'outside.json'
    outside.write_text('[]')
    record = json.loads(ticket.read_text())
    sweep.integration.atomic_json(ticket, dict(record, proposals='outside.json', sha256=hashlib.sha256(outside.read_bytes()).hexdigest()))
    with pytest.raises(ValueError, match='escapes'):
        sweep.pending_proposals(tmp_path, 'new')


def test_rebase_uses_only_exact_unique_original_or_already_applied_anchors():
    assert sweep.rebase_saved_edits('one two', [['one','ONE'],['missing','two'],['','three']]) == [['one','ONE'],['','three']]
    assert sweep.rebase_saved_edits('already', [['','already']]) == []
    assert sweep.rebase_saved_edits('already deleted', [['missing assertion','']]) == []
    for text, edits in [('one one',[['one','ONE']]),('new new',[['old','new']]),('changed',[['old','new']])]:
        with pytest.raises(sweep.SavedProposalError, match='anchor'):
            sweep.rebase_saved_edits(text, edits)


@pytest.mark.parametrize('case', ['valid','covered','integrated','lost','compile-error','definitions','ambiguous','baseline-error'])
def test_saved_recheck_preserves_compiler_data_ownership_and_loss_gates(tmp_path, monkeypatch, case):
    text = 'int A::f(){return 1;} int A::keep(){return 9;}'
    if case == 'covered':
        text = text.replace('return 1;', 'return 100;')
    calls = []
    def compile(source, rel, label, output, *args, **kwargs):
        calls.append(label)
        path = output/(label+'.obj')
        path.write_text(source)
        return dict(ok=not (case == 'baseline-error' and label == 'recheck-baseline' or
                            case == 'compile-error' and label == 'recheck-final'),
                    object=str(path), undefined_symbols=['required'] if case == 'definitions' else [])
    def scan(data):
        text = data.decode()
        hits = [] if case == 'lost' and 'return 100;' in text else [dict(addr='keeper',symbol='keep')]
        return hits + ([dict(addr='target',symbol='fresh-symbol')] if 'return 100;' in text else [])
    monkeypatch.setattr(sweep, 'compile_unit', compile)
    monkeypatch.setattr(sweep, 'claim_unit', lambda *args:'RBX::A')
    monkeypatch.setattr(sweep, 'ownership_candidates', lambda obj,hits:{'target':['target','other'] if case == 'ambiguous' else ['target']})
    ctx = SimpleNamespace(tree=tmp_path, overlay=tmp_path, includes=[], defines='', flags='',
        matcher=SimpleNamespace(scan=scan), integrated={'target'} if case == 'integrated' else set(),
        by_addr={'target':{'unit':'RBX::A'}})
    proposal = dict(file='App/A.cpp', base_revision='old', edits=[['return 1;', 'return 100;']],
        witnesses=[dict(addr='target',symbol='old-symbol',claim_unit='RBX::A')], proof=dict(defined_symbols=['required']))
    if case in ('lost','compile-error','definitions','baseline-error'):
        with pytest.raises(ValueError, match='lost exact|compile failed|required definitions'):
            sweep.recheck_proposal(proposal, ctx, {'App/A.cpp':text}, tmp_path, 'new', lambda _:None, recover=True)
    else:
        result = sweep.recheck_proposal(proposal, ctx, {'App/A.cpp':text}, tmp_path, 'new', lambda _:None, recover=True)
        if case in ('covered','integrated','ambiguous'):
            assert result is None
            assert len(calls) == (2 if case == 'ambiguous' else 1)
        else:
            assert result['base_revision'] == 'new'
            assert result['proof']['losses'] == []
            assert result['witnesses'] == [dict(addr='target',symbol='fresh-symbol',claim_unit='RBX::A')]
