from roc.native_autopilot_identity import bind_tables
from roc import native_autopilot_identity as identity
import struct
from unittest.mock import patch


def test_virtual_slot_identity_requires_type_ordinal_and_complete_table():
    method = '?SetPrintID@PacketLogger@@UAEX_N@Z'
    compiled = [{'class': 'PacketLogger', 'symbol': '??_7PacketLogger@@6B@', 'methods': ['destructor', method]}]
    original = [{'class': 'PacketLogger', 'vtable': '00800000', 'slots': [['00401000', 0], ['00401010', 0]]}]
    checks = {('00401010', method)}
    result = bind_tables(compiled, original, checks)
    assert len(result) == 1
    assert result[0]['original_slot'] == '00800004'
    assert bind_tables(compiled, original, {('00401000', method)}) == []
    original[0]['class'] = 'DifferentClass'
    assert bind_tables(compiled, original, checks) == []
    original[0]['class'] = 'PacketLogger'; original[0]['slots'].append(['00401020', 0])
    assert bind_tables(compiled, original, checks) == []


def test_inherited_method_does_not_acquire_identity_from_generic_derived_type():
    method = '?SetPrintID@PacketLogger@@UAEX_N@Z'
    compiled = [{'class': 'Exposer', 'symbol': '??_7Exposer@@6B@', 'methods': [method]}]
    original = [{'class': 'Exposer', 'vtable': '00800000', 'slots': [['00401010', 0]]}]
    assert bind_tables(compiled, original, {('00401010', method)}) == []


def test_coff_tables_reject_secondary_table_and_reference_addends():
    raw = bytearray(220)
    raw[72:81] = b'.?AVFoo@@'
    sections = [(b'.rdata', 0, 0, 12, 0, 128, 0, 3),
                (b'.rdata', 0, 0, 20, 32, 158, 0, 1),
                (b'.data', 0, 0, 24, 64, 0, 0, 0)]
    names = ['locator', '?one@Foo@@UAEXXZ', '?two@Foo@@UAEXXZ', 'descriptor']
    symbols = {i: (name, 0, 0, 0) for i, name in enumerate(names)}
    definitions = {'??_7Foo@@6B@': (4, 0), 'locator': (0, 1), 'descriptor': (0, 2)}
    for index, offset in enumerate((0, 4, 8)):
        struct.pack_into('<IIH', raw, 128 + index * 10, offset, index, 6)
    struct.pack_into('<IIH', raw, 158, 12, 3, 6)
    with patch.object(identity.match, '_coff_data_index', return_value=(sections, symbols, definitions, {})):
        assert identity.coff_tables(bytes(raw))[0]['class'] == 'Foo'
        raw[36] = 4  # COL offset: a secondary base table.
        assert identity.coff_tables(bytes(raw)) == []
        raw[36] = 0; raw[8] = 1  # Nonzero function-pointer addend.
        assert identity.coff_tables(bytes(raw)) == []
