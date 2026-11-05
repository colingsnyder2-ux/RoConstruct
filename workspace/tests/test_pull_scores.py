import json
from types import SimpleNamespace

from roc import match, worker


def test_batch_scores_keep_best_and_do_not_rewrite_unchanged(tmp_path, monkeypatch):
    monkeypatch.setattr(match, 'ROOT', tmp_path)
    assert match.save_scores('C', {'a': 100, 'b': 40}) == {'a': 100, 'b': 40}
    path = tmp_path / 'work/C/scores.json'
    before = path.stat().st_mtime_ns
    assert match.save_scores('C', {'a': 20, 'b': 40}) == {'a': 100, 'b': 40}
    assert path.stat().st_mtime_ns == before
    assert match.save_score('C', 'b', 80) == 80
    assert json.loads(path.read_text()) == {'a': 100, 'b': 80}


def test_pull_merges_valid_scores_once_and_preserves_handwritten_source(tmp_path, monkeypatch):
    rows = [dict(addr=addr, score=100, source='int f() { return 42; }', user='alice')
            for addr in ('00500000', '00500001', '00500002', 'bad')]
    closed, batches = [], []
    monkeypatch.setattr(worker, 'ROOT', tmp_path)
    monkeypatch.setattr(worker, 'Api', lambda *a: SimpleNamespace(
        call=lambda *a, **kw: rows, close=lambda: closed.append(True)))
    monkeypatch.setattr(match, 'function_starts', lambda *a: {'00500000', '00500001'})
    monkeypatch.setattr(match, 'save_scores', lambda client, scores, **kw: batches.append((client, scores, kw)))
    monkeypatch.setattr(match, 'save_score', lambda *a: (_ for _ in ()).throw(AssertionError('per-row score IO')))
    monkeypatch.setattr(match, 'template', lambda *a: '// target\n\nvoid old() {}')
    folder = tmp_path / 'src/C'
    folder.mkdir(parents=True)
    (folder / '00500000.cpp').write_text('handwritten work')
    worker.pull_files('http://test', 'C', log=lambda *a: None)
    assert closed == [True]
    assert batches == [('C', {'00500000': 100, '00500001': 100}, {'authoritative': True})]
    assert (folder / '00500000.cpp').read_text() == 'handwritten work'
    assert 'return 42' in (folder / '00500001.cpp').read_text()
    assert not (folder / '00500002.cpp').exists()
