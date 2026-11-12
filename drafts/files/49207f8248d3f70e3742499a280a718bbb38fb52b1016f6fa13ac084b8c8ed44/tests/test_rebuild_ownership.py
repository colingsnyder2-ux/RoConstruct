import struct

from roc import match, rebuild
from test_coff_data_index import object_bytes


def targets(monkeypatch, first=b'abcd', second=b'WXYZ', second_pointer=0x500090):
    image = bytearray(256)
    image[0x80:0x88] = first + b'1234'
    image[0x90:0x98] = second + b'5678'
    bodies = {'00500000': b'\xb8' + struct.pack('<I', 0x500080) + b'\xc3',
              '00500010': b'\xb8' + struct.pack('<I', second_pointer) + b'\xc3'}
    monkeypatch.setattr(match, '_image', lambda client: (0x500000, bytes(image)))
    monkeypatch.setattr(match, '_base_relocs', lambda client: frozenset())
    monkeypatch.setattr(match, 'target', lambda client, address: (bodies[address], [1], {}))
    monkeypatch.setattr(rebuild, 'pair', lambda client, funcs:
                        [(name, len(body), list(bodies)) for name, body, relocs in funcs])


def test_referenced_data_resolves_whole_binary_code_twins(monkeypatch):
    targets(monkeypatch)
    assert rebuild.pair_object('test', object_bytes()) == [('_f', 6, ['00500000'])]


def test_identical_referenced_data_keeps_twins_ambiguous(monkeypatch):
    targets(monkeypatch, second=b'abcd')
    assert rebuild.pair_object('test', object_bytes()) == [('_f', 6, ['00500000', '00500010'])]


def test_unmapped_data_cannot_create_unique_owner(monkeypatch):
    targets(monkeypatch, first=b'WXYZ', second_pointer=0x600000)
    assert rebuild.pair_object('test', object_bytes()) == [('_f', 6, ['00500000', '00500010'])]


def test_all_data_mismatches_reject_code_twins(monkeypatch):
    targets(monkeypatch, first=b'WXYZ')
    assert rebuild.pair_object('test', object_bytes()) == [('_f', 6, [])]


def test_ownership_symbol_filter_ignores_unrelated_functions(monkeypatch):
    targets(monkeypatch)
    assert rebuild.pair_object('test', object_bytes(), {'unrelated'}) == []


def test_no_referenced_data_keeps_code_twins_without_target_reads(monkeypatch):
    targets(monkeypatch)
    monkeypatch.setattr(match, 'coff_data_refs', lambda *args, **kwargs: [])
    def unexpected(*args):
        raise AssertionError('No data to compare: target reads are unnecessary')
    monkeypatch.setattr(match, 'target', unexpected)
    assert rebuild.pair_object('test', object_bytes()) == [('_f', 6, ['00500000', '00500010'])]
