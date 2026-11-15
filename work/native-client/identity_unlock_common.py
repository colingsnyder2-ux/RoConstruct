"""Shared helpers for identity_unlock_*.py: PE image, function bounds, disassembly, registry."""
import json
import subprocess
from functools import lru_cache
from pathlib import Path

import capstone
import pefile

ROOT = Path(__file__).resolve().parents[2]
REGISTRY = ROOT / 'work/2008-06/identity-registry.json'
REMAINING = ROOT / 'work/native-client/remaining-3901.json'
UNDNAME = ROOT / 'tools/vc2008rtm/Program Files/Microsoft Visual Studio 9.0/VC/bin/undname.exe'

pe = pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe'), fast_load=True)
BASE = pe.OPTIONAL_HEADER.ImageBase
IMG = pe.get_memory_mapped_image()
MD = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
MD.detail = True
REG = json.load(open(REGISTRY))
CODE_STARTS = sorted(int(a, 16) for a, v in REG.items() if v.get('kind') == 'code')


def u32(va):
    o = va - BASE
    return int.from_bytes(IMG[o:o + 4], 'little')


def end_of(va):
    import bisect
    i = bisect.bisect_right(CODE_STARTS, va)
    return CODE_STARTS[i] if i < len(CODE_STARTS) else va + 0x400


def insns(va):
    o = va - BASE
    return list(MD.disasm(bytes(IMG[o:o + (end_of(va) - va)]), va))


def unnamed():
    return [a for a in json.load(open(REMAINING)) if REG.get(a, {}).get('placeholder', True)]


def named(va):
    row = REG.get('%08x' % va)
    if row and not row.get('placeholder'):
        return row
    return None


@lru_cache(None)
def undname(sym):
    out = subprocess.run([str(UNDNAME), sym], capture_output=True, text=True).stdout
    for line in out.splitlines():
        if line.startswith('is :- '):
            return line[6:].strip().strip('"')
    return None


def undname_many(syms):
    """Batch undname (one process per 200 names)."""
    syms = [s for s in dict.fromkeys(syms)]
    res = {}
    for i in range(0, len(syms), 200):
        chunk = syms[i:i + 200]
        out = subprocess.run([str(UNDNAME)] + chunk, capture_output=True, text=True).stdout
        cur = None
        for line in out.splitlines():
            if line.startswith('Undecoration of :- '):
                cur = line[len('Undecoration of :- '):].strip().strip('"')
            elif line.startswith('is :- ') and cur is not None:
                res[cur] = line[6:].strip().strip('"')
    return res


def refs(i):
    """Immediate / memory-displacement operands of one instruction."""
    out = []
    for op in i.operands:
        if op.type == capstone.x86.X86_OP_IMM:
            out.append(op.imm & 0xffffffff)
        elif op.type == capstone.x86.X86_OP_MEM and op.mem.base == 0 and op.mem.index == 0:
            out.append(op.mem.disp & 0xffffffff)
    return out


def show(a, n=12):
    for i in insns(int(a, 16))[:n]:
        t = ''
        for v in refs(i):
            r = REG.get('%08x' % v)
            if r:
                t += ' ; %s:%s' % (r.get('kind'), str(r.get('name'))[:90])
        print(' ', hex(i.address), i.mnemonic, i.op_str, t)
        if i.mnemonic in ('ret', 'jmp'):
            break
