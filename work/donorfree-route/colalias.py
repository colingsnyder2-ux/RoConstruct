"""python colalias.py: zero-stubbed dat_<X> placeholders that are the original's RTTI CompleteObjectLocators (vtable[-1] of
vt_orig/vt_orig_remap tables: Backpack, Shirt, Pants, Tool, HopperBin ... -> dynamic_cast / askSetParent crashed;
gemini dossier sections 8/15). The original COL at X names its class through its TypeDescriptor (+12 -> name at +8);
when our link defines that class's primary locator ??_R4<class>6B@ (offset 0), alias dat_<X> to it. Only offset-0 COLs.
Writes aliases_colalias.txt (grow-only)."""
import re, struct
from pathlib import Path
import pefile
H = Path(__file__).parent
o = pefile.PE(str(H.parents[1] / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image(); B = 0x400000
stub, defs = set(), set()
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        (stub if 'stubs' in p[-1] else defs).add(p[1])
al = {}
for s in stub:
    m = re.fullmatch(r'dat_([0-9a-f]{8})', s)
    if not m:
        continue
    a = int(m.group(1), 16) - B
    if not 0 <= a < len(o) - 20:
        continue
    sig, off, cd, td = struct.unpack_from('<IIII', o, a)
    if sig != 0 or off != 0 or not B <= td < B + len(o) - 64:
        continue
    nm = bytes(o[td - B + 8:td - B + 200]).split(b'\0')[0]
    if not re.fullmatch(rb'\.\?A[VU][\w@?$]+@@', nm):
        continue
    col = '??_R4' + nm[4:].decode() + '6B@'
    if col in defs:
        al[s] = col
af = H / 'aliases_colalias.txt'
old = dict(l.strip().split('=', 1) for l in open(af) if '=' in l) if af.exists() else {}
old.update(al)
af.write_text(''.join('%s=%s\n' % kv for kv in sorted(old.items())))
print('colalias: stubbed original RTTI locators bound to our ??_R4: %d (e.g. %s)' % (len(al), list(al.items())[:3]))
