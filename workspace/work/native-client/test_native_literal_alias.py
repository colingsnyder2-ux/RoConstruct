"""Compiler literal aliases must still verify original bytes and relocation."""
import struct
import sys
import unittest
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))
from roc import native_bulk


def check(name='__real@bdcccccd', data=b'\xcd\xcc\xcc\xbd', target_data=None,
          section=b'.rdata', writable=False, relocated=True, identity='00002000'):
    body = struct.pack('<I', 0)
    target = struct.pack('<I', 0x1000)
    raw = body + struct.pack('<IIH', 0, 2, 6) + data
    code = (b'.text', 0, 0, 4, 0, 4, 0, 1, 0, 0x20)
    flags = 0x40000000 | (0x80000000 if writable else 0)
    literal = (section, 0, 0, 4, 14, 0, 0, 0, 0, flags)
    symbols = {1: ('owner', 0, 1, 0), 2: (name, 0, 2, 0)}
    class Targets:
        relocs = set()
        def data(self, address, size): return target_data if target_data is not None else data
        def data_relocations(self, address, size): return set()
    with patch.object(native_bulk.match, '_coff_data_index',
                      return_value=([code, literal], symbols, {'owner': (0, 0)}, None)):
        return native_bulk.audit_references(raw, 'owner', body, target, {0} if relocated else set(),
                                            0x2000, Targets(), {name: identity})[1]


class LiteralAliasTests(unittest.TestCase):
    def test_valid_literal_alias(self):
        self.assertEqual([], check())
    def test_corrupt_original_rejected(self):
        self.assertIn('referenced data differs: __real@bdcccccd', check(target_data=b'\0'*4))
    def test_literal_name_must_encode_object_bytes(self):
        self.assertIn('reference identity differs: __real@bdcccccd', check(data=b'\0'*4))
    def test_only_readonly_constant_sections_qualify(self):
        self.assertIn('reference identity differs: __real@bdcccccd', check(writable=True))
        self.assertIn('reference identity differs: __real@bdcccccd', check(section=b'.data'))
    def test_other_symbols_keep_identity_gate(self):
        self.assertIn('reference identity differs: ordinary', check(name='ordinary'))
    def test_missing_original_relocation_rejected(self):
        self.assertIn('absolute field is not relocated in original', check(relocated=False))
    def test_ambiguous_literal_binding_stays_rejected(self):
        self.assertIn('conflicting reference identity: __real@bdcccccd', check(identity=None))


if __name__ == '__main__':
    unittest.main()
