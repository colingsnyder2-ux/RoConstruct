"""python xcu_gen.py: a COFF object whose .CRT$XCU section points at the converted dynamic initializers the original
exe ran at startup (auto/init_fns.json from initscan.py: initializers of globals our link only had as zero placeholders).
Converted initializers are plain functions: nothing called them, the linker even dropped them (/OPT:REF), so every
converted-only static (reflection prop_/func_/event_ descriptors, maps, strings) stayed unconstructed. The CRT runs
every .CRT$XCU pointer before main, like the original's __xc_a..__xc_z table. Writes linkexp/xcu_init.obj."""
import json, struct
from pathlib import Path
H = Path(__file__).parent
fns = json.loads((H / 'auto/init_fns.json').read_text())
syms = sorted({v['symbol'] for f, v in fns.items() if v.get('status') == 'renamed' and v.get('symbol')}, key=lambda s: s)
# order by original address: initializers ran in table order in the original (keeps dependencies)
order = sorted(((f, v['symbol']) for f, v in fns.items() if v.get('status') == 'renamed' and v.get('symbol')), key=lambda x: x[0])
# XCU_CTOR=regex: only initializers whose constructor (auto/initscan.json) matches -- enable ONE family at a time
# (all 156 at once crashed static init; per family a regression is attributable)
import os, re as _re
if os.environ.get('XCU_CTOR'):
    _scan = json.loads((H / 'auto/initscan.json').read_text())
    # initscan's 'initializer' is the `mov ecx, ADDR` instruction: map it to its containing function start
    import bisect as _bs
    _starts = sorted(int(a, 16) for a in fns)
    def _fn_of(va):
        i = _bs.bisect_right(_starts, int(va, 16)) - 1
        return '%08x' % _starts[i] if i >= 0 else None
    _ok = {_fn_of(v['initializer']) for v in _scan.values() if _re.search(os.environ['XCU_CTOR'], v.get('ctor', ''))}
    order = [(f, s) for f, s in order if f in _ok]
names = [s for _, s in order]
n = len(names)
SEC_NAME = b'.CRT$XCU'
raw = bytes(4 * n)
# layout: header(20) + section header(40) + raw + relocs(10 each) + symtab(18 each) + strtab
hdr_size = 20 + 40
raw_ptr = hdr_size
rel_ptr = raw_ptr + len(raw)
sym_ptr = rel_ptr + 10 * n
strtab = bytearray()
symtab = bytearray()
for s in names:
    b = s.encode('latin-1')
    if len(b) <= 8:
        nm = b.ljust(8, b'\0')
    else:
        nm = struct.pack('<II', 0, 4 + len(strtab)); strtab += b + b'\0'
    symtab += nm + struct.pack('<IhHBB', 0, 0, 0x20, 2, 0)   # undefined external function
relocs = b''.join(struct.pack('<IIH', 4 * i, i, 6) for i in range(n))   # IMAGE_REL_I386_DIR32
header = struct.pack('<HHIIIHH', 0x14c, 1, 0, sym_ptr, n, 0, 0)
section = SEC_NAME + struct.pack('<IIIIIIHHI', 0, 0, len(raw), raw_ptr, rel_ptr, 0, n, 0, 0x40300040)
obj = header + section + raw + relocs + bytes(symtab) + struct.pack('<I', 4 + len(strtab)) + bytes(strtab)
_out = Path(os.environ['XCU_OUT']) if os.environ.get('XCU_OUT') else H / 'linkexp/xcu_init.obj'   # per-family variants
_out.write_bytes(obj)
print(_out.name + ': %d converted initializers registered in .CRT$XCU' % n)
