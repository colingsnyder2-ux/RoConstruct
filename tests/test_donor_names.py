from roc import matchers


def test_donor_names_include_exact_functions_and_withhold_conflicting_names(tmp_path, monkeypatch):
    class Target:
        def __init__(self, client):
            self.index = {}  # Mining queue empty: both functions already exact.

        def same(self, addr, code, relocs):
            return code if addr == 'b' or code == b'first!' else None

    monkeypatch.setattr(matchers.fingerprint, 'Target', Target)
    monkeypatch.setattr(matchers.match, '_functions', lambda client: {
        'a': {'size': 6, 'kind': 'code'}, 'b': {'size': 6, 'kind': 'code'},
        'c': {'size': 6, 'kind': 'data'}})
    monkeypatch.setattr(matchers, 'fetch', lambda: None)
    monkeypatch.setattr(matchers, 'donor_functions', lambda dll: {6: [(1, b'first!', []), (2, b'second', [])]})
    monkeypatch.setattr(matchers, 'names', lambda: {1: ('source', '?first@@YAXXZ'), 2: ('source', '?second@@YAXXZ')})
    monkeypatch.setattr(matchers, 'annotations', lambda: {})
    monkeypatch.setattr(matchers, 'ROOT', tmp_path)
    monkeypatch.setattr(matchers, 'TABLE', tmp_path / 'donors.json')
    (tmp_path / 'work' / 'test').mkdir(parents=True)
    result = matchers.build(['test'], log=lambda _: None)
    assert result['test'] == {'a': ['00000001', 'source', '?first@@YAXXZ', '']}
    import json
    ambiguous = json.loads((tmp_path / 'work/test/donor-ambiguous.json').read_text())
    assert len(ambiguous['b']) == 2
