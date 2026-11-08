"""Compare native preset values with the original 2008 function under x86 emulation."""
import hashlib
import json
from pathlib import Path
import struct
import sys

import pefile
from unicorn import Uc, UC_ARCH_X86, UC_HOOK_CODE, UC_MODE_32
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_EIP, UC_X86_REG_ESP


def original_preset(image, index, system=0x1234):
    machine = Uc(UC_ARCH_X86, UC_MODE_32)
    machine.mem_map(0x400000, 0x700000)
    machine.mem_write(0x400000, image)
    machine.mem_map(0x10000000, 0x20000)
    machine.mem_map(0x20000000, 0x10000)
    machine.mem_map(0x30000000, 0x1000)
    machine.mem_write(0x20000134, struct.pack('<I', system))
    machine.mem_write(0x20000170, struct.pack('<I', index))
    machine.reg_write(UC_X86_REG_ECX, 0x20000000)
    machine.reg_write(UC_X86_REG_ESP, 0x10010000)
    machine.mem_write(0x10010000, struct.pack('<I', 0x30000000))
    captured = []

    def hook(cpu, address, size, _):
        if address == 0x69fbe8:  # FMOD::System::setReverbProperties thunk
            stack = cpu.reg_read(UC_X86_REG_ESP)
            ret, system, preset = struct.unpack('<III', cpu.mem_read(stack, 12))
            assert system == 0x1234
            captured.append(bytes(cpu.mem_read(preset, 0x7c)))
            cpu.reg_write(UC_X86_REG_EAX, 0)
            cpu.reg_write(UC_X86_REG_ESP, stack + 12)
            cpu.reg_write(UC_X86_REG_EIP, ret)
        elif address == 0x5b87a0:  # result logger, result is FMOD_OK
            stack = cpu.reg_read(UC_X86_REG_ESP)
            ret = struct.unpack('<I', cpu.mem_read(stack, 4))[0]
            cpu.reg_write(UC_X86_REG_ESP, stack + 4)
            cpu.reg_write(UC_X86_REG_EIP, ret)

    machine.hook_add(UC_HOOK_CODE, hook)
    machine.emu_start(0x5b8880, 0x30000000, count=3000)
    assert len(captured) <= 1
    return captured[0] if captured else None


original = Path(sys.argv[1])
actual = Path(sys.argv[2]).read_bytes()
assert len(actual) == 24 * 0x7c
pe = pefile.PE(str(original))
assert pe.OPTIONAL_HEADER.ImageBase == 0x400000
image = pe.get_memory_mapped_image()
expected = b''.join(original_preset(image, index) for index in range(24))
assert original_preset(image, 24) is None
assert original_preset(image, 0xffffffff) is None
assert original_preset(image, 1, system=0) is None
differences = [index for index in range(24)
               if actual[index * 0x7c:(index + 1) * 0x7c] != expected[index * 0x7c:(index + 1) * 0x7c]]
print(json.dumps({'original_sha256': hashlib.sha256(original.read_bytes()).hexdigest(),
                  'original_presets_sha256': hashlib.sha256(expected).hexdigest(),
                  'rebuilt_presets_sha256': hashlib.sha256(actual).hexdigest(),
                  'presets_compared': 24, 'different_indices': differences,
                  'invalid_indices_and_null_system_skipped': True}, indent=2))
if differences:
    raise SystemExit(1)
