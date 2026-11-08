import importlib.util
import json
from pathlib import Path
import pytest

SCRIPT = Path(__file__).resolve().parents[1] / 'rebuild/2008-06/p6/glue_owner.py'
spec = importlib.util.spec_from_file_location('glue_owner_regression', SCRIPT)
owner = importlib.util.module_from_spec(spec)
spec.loader.exec_module(owner)


def test_native_owner_requires_unique_identity_exact_code_and_data(tmp_path, monkeypatch):
    obj = tmp_path / 'candidate.obj'
    obj.write_bytes(b'object')
    names = tmp_path / 'native-names.json'
    symbol = owner.CACHE + 'test'
    names.write_text(json.dumps({'00100000': {'symbol': symbol}}))
    monkeypatch.setattr(owner.match, 'coff_functions', lambda raw: [(symbol, b'code', [])])
    monkeypatch.setattr(owner.match, 'target', lambda client, addr: (b'code', [], {}))
    monkeypatch.setattr(owner.match, 'exact_match', lambda *args: True)
    monkeypatch.setattr(owner.match, 'coff_data_refs', lambda *args: [])
    monkeypatch.setattr(owner.match, 'data_check', lambda *args: ([], []))
    assert owner.verify_native(obj, names) == (symbol, '00100000')
    names.write_text(json.dumps({'00100000': {'symbol': symbol}, '00200000': {'symbol': symbol}}))
    with pytest.raises(ValueError, match='identity'):
        owner.verify_native(obj, names)
    names.write_text(json.dumps({'00100000': {'symbol': symbol}}))
    monkeypatch.setattr(owner.match, 'exact_match', lambda *args: False)
    with pytest.raises(ValueError, match='code differs'):
        owner.verify_native(obj, names)
    monkeypatch.setattr(owner.match, 'exact_match', lambda *args: True)
    monkeypatch.setattr(owner.match, 'data_check', lambda *args: ([], ['mismatch']))
    with pytest.raises(ValueError, match='data differs'):
        owner.verify_native(obj, names)


def test_glue_comparison_requires_exactly_the_duplicate_to_be_removed(monkeypatch):
    cache = owner.CACHE + 'test'
    def funcs(raw):
        if raw == b'original':
            return [(cache, b'old', []), ('?keep', b'a', [])]
        if raw == b'good':
            return [('?keep', b'a', [])]
        if raw == b'changed':
            return [('?keep', b'b', [])]
        return []
    table = [0] * 8
    monkeypatch.setattr(owner.match, 'coff_functions', funcs)
    monkeypatch.setattr(owner.match, '_coff_data_index', lambda raw: ([table], {}, {'?keep': (0, 0)}, {}))
    monkeypatch.setattr(owner.match, 'exact_match', lambda a, ar, b, br: a == b)
    monkeypatch.setattr(owner.match, 'coff_data_refs', lambda *args: [])
    monkeypatch.setattr(owner, 'sections', lambda raw: ({}, []))
    assert owner.compare(b'original', b'good') == (1, cache)
    with pytest.raises(ValueError, match='retained function changed'):
        owner.compare(b'original', b'changed')
    with pytest.raises(ValueError, match='provider set'):
        owner.compare(b'original', b'original')


def test_glue_comparison_rejects_colliding_normalized_names(monkeypatch):
    monkeypatch.setattr(owner.match, 'coff_functions', lambda raw: [
        ('?same?A0x12345678', b'a', []), ('?same?A0x87654321', b'b', [])])
    with pytest.raises(ValueError, match='ambiguous normalized provider'):
        owner.compare(b'original', b'replacement')
