import json
from pathlib import Path
from unittest.mock import patch

from roc import native_autopilot_llm as lane


def test_hypothesis_never_becomes_proof_and_duplicate_input_is_not_repeated(tmp_path):
    original = tmp_path / 'clients/2008-06/Roblox.exe'
    original.parent.mkdir(parents=True); original.write_bytes(b'image')
    diagnostics = [{'address': '00401000', 'status': 'exact', 'identity_review_required': True}]
    output = tmp_path / 'out'
    calls = []
    def generate(messages, model):
        calls.append(model)
        return {'text': '{"approved":true}', 'model': model, 'verified': False}
    with patch.object(lane, 'model_chain', return_value=(['nvidia:model'], [])), \
         patch.object(lane, 'packet', return_value={'address': '00401000', 'source_sha256': 's'}):
        result = lane.investigate(tmp_path, diagnostics, output, generate=generate)
        again = lane.investigate(tmp_path, diagnostics, output, generate=generate)
    assert result['hypotheses'] == 1
    assert result['verified'] is False
    assert again['attempted'] == 0
    assert len(calls) == 1
    saved = json.loads(next(p for p in (output / 'llm-reviews').glob('*.json') if len(p.stem) == 64).read_text())
    assert saved['state'] == 'hypothesis' and saved['verified'] is False


def test_low_similarity_does_not_spend_llm_calls(tmp_path):
    original = tmp_path / 'clients/2008-06/Roblox.exe'
    original.parent.mkdir(parents=True); original.write_bytes(b'image')
    with patch.object(lane, 'model_chain', return_value=([], [])), patch.object(lane, 'packet') as packet:
        result = lane.investigate(tmp_path, [{'status': 'different', 'metrics': {'fuzzy_percent': 20}}], tmp_path / 'out')
        packet.assert_not_called()
        assert result['queued'] == 0


def test_new_evidence_supersedes_pending_copy_of_same_target(tmp_path):
    original = tmp_path / 'clients/2008-06/Roblox.exe'
    original.parent.mkdir(parents=True); original.write_bytes(b'image')
    folder = tmp_path / 'out/llm-reviews'; folder.mkdir(parents=True)
    (folder / 'queue.json').write_text(json.dumps({'jobs': {'old': {'address': '00401000', 'state': 'pending', 'packet': {}}}}))
    with patch.object(lane, 'model_chain', return_value=([], [])), \
         patch.object(lane, 'packet', return_value={'address': '00401000', 'new_evidence': True}):
        result = lane.investigate(tmp_path, [{'address': '00401000', 'status': 'exact'}], tmp_path / 'out')
    jobs = json.loads((folder / 'queue.json').read_text())['jobs']
    assert jobs['old']['state'] == 'superseded_evidence'
    assert result['attempted'] == 1


def test_competing_owners_for_same_address_are_both_reviewed(tmp_path):
    original = tmp_path / 'clients/2008-06/Roblox.exe'
    original.parent.mkdir(parents=True); original.write_bytes(b'image')
    rows = [{'address': '00401000', 'status': 'exact', 'symbol': symbol} for symbol in ('A', 'B')]
    with patch.object(lane, 'model_chain', return_value=([], [])), \
         patch.object(lane, 'packet', side_effect=lambda row: {'symbol': row['symbol'], 'source_sha256': row['symbol']}):
        result = lane.investigate(tmp_path, rows, tmp_path / 'out')
    assert result['attempted'] == 2
