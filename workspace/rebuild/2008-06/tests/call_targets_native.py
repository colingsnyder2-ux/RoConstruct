"""List a body's calls in order: original target (import name or address) next to the native
relocation symbol. usage: call_targets_native.py obj ADDR symbol-prefix"""
import json, struct, sys
from pathlib import Path
import capstone
ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match  # noqa: E402
from roc.delink import import_names  # noqa: E402

obj = Path(sys.argv[1]).read_bytes()
addr = int(sys.argv[2], 16)
code = match.target('2008-06', sys.argv[2])[0]
base, image = match._image('2008-06')
pe_slots = {}
import pefile
pe = pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe'), fast_load=True); pe.parse_data_directories()
for e in pe.DIRECTORY_ENTRY_IMPORT:
    for i in e.imports:
        pe_slots[i.address] = '%s!%s' % (e.dll.decode().lower(), i.name.decode() if i.name else i.ordinal)

def orig_name(t):
    rva = t - base
    if image[rva:rva + 2] == b'\xff\x25':
        return pe_slots.get(struct.unpack_from('<I', image, rva + 2)[0], hex(t))
    return '%08x' % t

secs, syms, defined, _ = match._coff_data_index(obj)
name = next(n for n in defined if n.startswith(sys.argv[3]))
value, sec = defined[name]
relocs = {}
for k in range(secs[sec][7]):
    off, idx, kind = struct.unpack_from('<IIH', obj, secs[sec][5] + 10 * k)
    relocs[off - value] = syms[idx][0]
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
mine = []
body = next(b for n, b, r in match.coff_functions(obj) if n == name)
for i in md.disasm(body, 0):
    if i.mnemonic == 'call':
        mine.append(relocs.get(i.address + (2 if i.bytes[0] == 0xff else 1), i.op_str))
orig = []
for i in md.disasm(code, addr):
    if i.mnemonic == 'call':
        if i.bytes[0] == 0xe8:
            orig.append(orig_name(int(i.op_str, 16)))
        elif i.bytes[:2] == b'\xff\x15':
            orig.append(pe_slots.get(struct.unpack_from('<I', i.bytes, 2)[0], i.op_str) + ' [iat]')
        else:
            orig.append(i.op_str)
for k in range(max(len(orig), len(mine))):
    a = orig[k] if k < len(orig) else ''
    b = mine[k] if k < len(mine) else ''
    print('%3d %-55s %s' % (k, a[:55], b[:90]))
