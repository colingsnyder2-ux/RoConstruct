import struct
import unittest

from codex_import_thunks import import_symbols, import_thunk_aliases


class ImportThunkTests(unittest.TestCase):
    def test_symbols_require_matching_dll_import(self):
        imports = {0x1000: ('user32.dll', 'GetSysColor')}
        lines = ['0002:00000000 __imp__GetSysColor@4 00001000 user32:USER32.dll']
        extras = {'per': {'fmodex.dll': ['FMOD_Memory_GetStats']},
                  'aliases': ['_FMOD_Memory_GetStats@8=_FMOD_Memory_GetStats']}
        result = import_symbols(imports, lines, extras)
        self.assertEqual(result[('user32.dll', 'GetSysColor')], {'_GetSysColor@4'})
        self.assertEqual(result[('fmodex.dll', 'FMOD_Memory_GetStats')], {'_FMOD_Memory_GetStats@8'})

    def test_unique_dll_specific_symbol_only(self):
        image = bytearray(40)
        image[4:10] = b'\xff\x25' + struct.pack('<I', 0x1234)
        image[12:18] = b'\xff\x25' + struct.pack('<I', 0x5678)
        imports = {0x1234: ('fmodex.dll', 'FMOD_Memory_GetStats'), 0x5678: ('user32.dll', 'GetSysColor')}
        symbols = {imports[0x1234]: {'_FMOD_Memory_GetStats@8'}, imports[0x5678]: {'_GetSysColor@4', '_GetSysColor@8'}}
        result = import_thunk_aliases(image, 0x400000, imports,
                                      ['func_00400004', 'func_0040000c', 'func_00400020'], symbols)
        self.assertEqual(result, {'func_00400004': '_FMOD_Memory_GetStats@8'})


if __name__ == '__main__':
    unittest.main()
