"""Verifier regression fixture; positive case becomes green after the leased fix."""
import struct
import sys
import unittest
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))
from roc import native_bulk


class Targets:
    relocs = set()
    def __init__(self, corrupt=False):
        self.corrupt = corrupt
    def data(self, address, size):
        assert address == 0x1000 and size == 12
        return (b'\1' + bytes(size - 1)) if self.corrupt else bytes(size)
    def data_relocations(self, address, size):
        return set()


def check(addend=12, length=12, corrupt=False, bindings=None):
    body = struct.pack('<i', addend)
    target = struct.pack('<I', 0x1000 + addend)
    raw = body + struct.pack('<IIH', 0, 2, 6)
    # COFF tuple: name, virtual size/address, raw size/offset, relocation offset,
    # line offset, relocation count, line count, characteristics.
    code = (b'.text', 0, 0, 4, 0, 4, 0, 1, 0, 0x20)
    data = (b'.bss', 0, 0, length, 0, 0, 0, 0, 0, 0x80)
    symbols = {1: ('function', 0, 1, 0), 2: ('array', 0, 2, 0)}
    definitions = {'function': (0, 0)}
    with patch.object(native_bulk.match, '_coff_data_index',
                      return_value=([code, data], symbols, definitions, None)):
        return native_bulk.audit_references(raw, 'function', body, target, {0},
                                            0x2000, Targets(corrupt), bindings or {})[1]


class OnePastTests(unittest.TestCase):
    def test_valid_one_past_verifies_complete_array(self):
        self.assertEqual([], check())
    def test_mismatching_data_rejected(self):
        self.assertIn('referenced data differs: array', check(corrupt=True))
    def test_wrong_symbol_address_rejected(self):
        self.assertIn('reference identity differs: array', check(bindings={'array': '00002000'}))
    def test_zero_length_rejected(self):
        self.assertIn('unproven data span: array', check(addend=0, length=0))
    def test_beyond_one_past_rejected(self):
        self.assertIn('unproven data span: array', check(addend=13))


if __name__ == '__main__':
    unittest.main()
