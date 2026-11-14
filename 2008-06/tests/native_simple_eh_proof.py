"""Conservative verifier for simple MSVC x86 unwind-only exception handlers.

Handlers with catches, unsupported unwind actions or unknown references remain
unverified. This proves the original and object EH structure, not linked ABI or
runtime behavior.
"""
import struct

from capstone import Cs, CS_ARCH_X86, CS_MODE_32
from capstone.x86 import X86_INS_JMP, X86_INS_LEA, X86_OP_MEM, X86_REG_EBP


def verify(raw, owner, handler_address, index, image_base, image, imports):
    sections, symbols, definitions, starts = index

    def original(address, size):
        offset = address - image_base
        if offset < 0 or offset + size > len(image):
            raise ValueError('original address outside image')
        return bytes(image[offset:offset + size])

    def obj(name, size=None):
        value, section = definitions[name]
        table = sections[section]
        stop = min([x for x in starts[section + 1] if x > value] + [table[3]])
        if size is not None:
            if value + size > stop:
                raise ValueError('object symbol overlaps another symbol')
            stop = value + size
        if stop > table[3] or not table[4]:
            raise ValueError('object symbol outside initialized section')
        data = raw[table[4] + value:table[4] + stop]
        relocs = {}
        for i in range(table[7]):
            off, sym, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
            if value <= off < stop:
                if off - value in relocs:
                    raise ValueError('duplicate relocation')
                relocs[off - value] = (symbols[sym][0], kind)
        return data, relocs

    def imported(slot, symbol):
        label = imports[0].get(slot, '')
        dll, sep, export = label.partition('!')
        return bool(sep and symbol in imports[1].get((dll.lower(), export), set()))

    try:
        suffix = '$' + owner
        handler, refs = obj('__ehhandler' + suffix, 10)
        if (handler != b'\xb8\0\0\0\0\xe9\0\0\0\0' or refs != {
                1: ('__ehfuncinfo' + suffix, 6), 6: ('___CxxFrameHandler3', 20)}):
            return False
        old = original(handler_address, 10)
        if old[0] != 0xb8 or old[5] != 0xe9:
            return False
        info_address = struct.unpack_from('<I', old, 1)[0]
        thunk = (handler_address + 10 + struct.unpack_from('<i', old, 6)[0]) & 0xffffffff
        thunk_code = original(thunk, 6)
        if thunk_code[:2] != b'\xff\x25':
            return False
        thunk_slot = struct.unpack_from('<I', thunk_code, 2)[0]
        if not imported(thunk_slot, '__imp____CxxFrameHandler3'):
            return False
        info, refs = obj('__ehfuncinfo' + suffix, 36)
        old_info = original(info_address, 36)
        values = struct.unpack('<9I', info)
        old_values = struct.unpack('<9I', old_info)
        if (values[0] != 0x19930522 or not 0 < values[1] <= 32 or values[2] != 0 or values[3] != 0
                or any(values[i] != old_values[i] for i in (0, 1, 3, 4, 5, 6, 7, 8))
                or refs != {8: ('__unwindtable' + suffix, 6)}):
            return False
        count = values[1]
        unwind, refs = obj('__unwindtable' + suffix, count * 8)
        old_unwind = original(old_values[2], count * 8)
        if set(refs) != {i * 8 + 4 for i in range(count)}:
            return False
        decoder = Cs(CS_ARCH_X86, CS_MODE_32)
        decoder.detail = True
        for i in range(count):
            off = i * 8
            if unwind[off:off + 4] != old_unwind[off:off + 4]:
                return False
            name, kind = refs[off + 4]
            if kind != 6 or unwind[off + 4:off + 8] != b'\0' * 4 or not name.startswith('__unwindfunclet' + suffix + '$'):
                return False
            action_address = struct.unpack_from('<I', old_unwind, off + 4)[0]
            action, relocs = obj(name)
            if not 0 < len(action) <= 32:
                return False
            ins = list(decoder.disasm(action, 0))
            if (len(ins) != 2 or ins[0].id != X86_INS_LEA or ins[1].id != X86_INS_JMP
                    or len(ins[0].operands) != 2 or ins[0].operands[1].type != X86_OP_MEM
                    or ins[0].operands[1].mem.base != X86_REG_EBP or ins[1].operands[0].type != X86_OP_MEM
                    or ins[1].operands[0].mem.base or ins[1].operands[0].mem.index or ins[1].disp_size != 4
                    or ins[1].address + ins[1].size != len(action)):
                return False
            at = ins[1].address + ins[1].disp_offset
            if set(relocs) != {at} or relocs[at][1] != 6 or action[at:at + 4] != b'\0' * 4:
                return False
            old_action = original(action_address, len(action))
            if old_action[:at] != action[:at] or old_action[at + 4:] != action[at + 4:]:
                return False
            slot = struct.unpack_from('<I', old_action, at)[0]
            if not imported(slot, relocs[at][0]):
                return False
        return True
    except (KeyError, IndexError, ValueError, struct.error):
        return False
