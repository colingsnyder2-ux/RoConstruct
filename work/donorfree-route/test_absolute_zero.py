import re
import unittest
from pathlib import Path

import capstone
import pefile

root = Path(__file__).parent


class AbsoluteZero(unittest.TestCase):
    def test_texture_pointer_constructor_initializes_to_null(self):
        symbol = '??0?$ReferenceCountedPointer@VTextureProxy@RenderNew@RBX@@@G3D@@QAE@XZ'
        for line in (root / 'linkexp/qt.map').read_text(errors='ignore').splitlines():
            parts = line.split()
            if len(parts) >= 3 and parts[1] == symbol:
                address = int(parts[2], 16)
                break
        else:
            self.fail('texture pointer constructor missing from linker map')
        exe = pefile.PE(str(root / 'run/RobloxQT.exe'))
        code = exe.get_data(address - exe.OPTIONAL_HEADER.ImageBase, 32)
        instructions = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32).disasm(code, address)
        self.assertTrue(any(ins.mnemonic == 'mov' and re.fullmatch(r'dword ptr \[eax\], 0', ins.op_str)
                            for ins in instructions), 'constructor does not store null')


if __name__ == '__main__':
    unittest.main()
