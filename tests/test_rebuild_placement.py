import json
import struct

import pytest

from roc import match, rebuild
from test_coff_data_index import object_bytes


def long_object():
    data = bytearray(object_bytes())
    for offset in (8, 44, 80, 84):
        struct.pack_into('<I', data, offset, struct.unpack_from('<I', data, offset)[0]+10)
    struct.pack_into('<I', data, 36, 16)
    data[106:106] = b'\x90'*10
    return bytes(data)


@pytest.fixture
def targets(monkeypatch):
    image = bytearray(256)
    image[0x80:0x88] = b'abcd1234'
    image[0x90:0x98] = b'WXYZ5678'
    def pointer(at, destination):
        image[at:at+16] = b'\xb8'+struct.pack('<I', destination)+b'\xc3'+b'\x90'*10
    pointer(0, 0x500080);pointer(32, 0x500090)
    functions = {'00500000': dict(size=16,relocs=[1]), '00500020': dict(size=16,relocs=[1])}
    monkeypatch.setattr(match, '_image', lambda client: (0x500000, bytes(image)))
    monkeypatch.setattr(match, '_functions', lambda client: functions)
    monkeypatch.setattr(match, '_base_relocs', lambda client: frozenset())
    monkeypatch.setattr(rebuild, '_INDEX', {})
    rebuild._paired_addresses.cache_clear()
    return image, pointer, functions


def test_complete_data_and_explicit_mismatch_place_one_twin(targets):
    assert rebuild._placed_object('test', long_object()) == ['00500000']


def test_unmapped_twin_cannot_be_silently_rejected(targets):
    _, pointer, _ = targets
    pointer(32, 0x600000)
    assert rebuild._placed_object('test', long_object()) == []


def test_incomplete_winner_never_qualifies(targets, monkeypatch):
    original = match.coff_data_refs
    monkeypatch.setattr(match, 'coff_data_refs', lambda *a, **kw: original(*a, **kw)+[(8,b'unmapped',[])])
    assert rebuild._placed_object('test', long_object()) == []


def test_placement_cache_rechecks_same_object_after_target_change(targets, tmp_path, monkeypatch):
    image, _, functions = targets
    modules = tmp_path / 'rebuild/test/modules';modules.mkdir(parents=True)
    (modules / 'module.json').write_text('{"name":"Module"}')
    out = tmp_path / 'out/Module';(out / 'linked').mkdir(parents=True)
    (out / 'linked/Native.obj').write_bytes(long_object())
    (out / 'report.json').write_text('{"linked":true}')
    monkeypatch.setattr(rebuild, 'ROOT', tmp_path)
    monkeypatch.setattr(rebuild, 'workspace', lambda client: tmp_path)
    assert rebuild.placed('test', log=lambda _: None) == {'00500000':'Module'}
    first = json.loads((out / 'placed.json').read_text())
    image[0x80:0x84] = b'WXYZ';image[0x90:0x94] = b'abcd'
    assert rebuild.placed('test', log=lambda _: None) == {'00500020':'Module'}
    assert json.loads((out / 'placed.json').read_text()) != first
    functions['00500020']['kind'] = 'data'
    assert rebuild.placed('test', log=lambda _: None) == {}
