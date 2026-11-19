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


_UND_CACHE = ROOT / 'work/native-client/identity-unlock-undname-cache.pkl'
_UND = None


def undname_many(syms):
    """Batch undname (one process per <=200 names and <=24k command-line chars).
    undname is a pure function of the symbol, so results persist in a disk cache."""
    global _UND
    import pickle
    if _UND is None:
        try:
            _UND = pickle.load(open(_UND_CACHE, 'rb'))
        except Exception:
            _UND = {}
    want = [s for s in dict.fromkeys(syms)]
    syms = [s for s in want if s not in _UND]
    res = {}
    chunks, cur_chunk, size = [], [], 0
    for s in syms:
        if cur_chunk and (len(cur_chunk) == 200 or size + len(s) > 24000):
            chunks.append(cur_chunk)
            cur_chunk, size = [], 0
        cur_chunk.append(s)
        size += len(s) + 3
    if cur_chunk:
        chunks.append(cur_chunk)
    for chunk in chunks:
        out = subprocess.run([str(UNDNAME)] + chunk, capture_output=True, text=True).stdout
        cur = None
        for line in out.splitlines():
            if line.startswith('Undecoration of :- '):
                cur = line[len('Undecoration of :- '):].strip().strip('"')
            elif line.startswith('is :- ') and cur is not None:
                res[cur] = line[6:].strip().strip('"')
    if syms:
        for x in syms:
            _UND[x] = res.get(x)
        tmp = str(_UND_CACHE) + '.tmp'
        pickle.dump(_UND, open(tmp, 'wb'))
        import os
        os.replace(tmp, _UND_CACHE)
    return {x: _UND[x] for x in want if _UND.get(x) is not None}


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


def dump_json(obj, path):
    """Atomic JSON write (tmp + replace), retried while another process holds the file open
    (Windows refuses the replace, or the open, with EACCES / EINVAL meanwhile)."""
    import os
    import time
    path = str(path)
    tmp = path + '.tmp%d' % os.getpid()
    for k in range(60):
        try:
            with open(tmp, 'w') as fh:
                json.dump(obj, fh, indent=1, sort_keys=True)
            os.replace(tmp, path)
            return
        except OSError:
            time.sleep(1)
    raise OSError('could not write %s (held open by another process)' % path)
