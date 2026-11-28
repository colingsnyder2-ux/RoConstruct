"""python alias_abi.py: every /alternatename alias whose decorated name implies a stack size (@name@N fastcall, _name@N
stdcall, plain _name cdecl) is checked against the ret N of the function it resolves to in link/donorfree.exe.
A mismatch corrupts the stack on every call. Reads aliases*.txt, link/donorfree.map, link/donorfree.exe."""
import re
from pathlib import Path
import capstone, pefile

H = Path(__file__).parent
pe = pefile.PE(str(H / 'link/donorfree.exe'), fast_load=True); img = pe.get_memory_mapped_image(); base = pe.OPTIONAL_HEADER.ImageBase
addr = {}
for l in open(H / 'link/donorfree.map', errors='replace'):
    m = re.match(r'\s*0001:[0-9a-f]{8}\s+(\S+)\s+([0-9a-f]{8})', l)
    if m:
        addr.setdefault(m.group(1), int(m.group(2), 16))
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)


def ret_of(a):
    for i in md.disasm(img[a - base:a - base + 0x3000], a):
        if i.mnemonic == 'ret':
            return int(i.op_str, 16) if i.op_str else 0
        if i.mnemonic == 'int3':
            return None
    return None


bad = 0
for f in ('aliases.txt', 'aliases_auto.txt', 'aliases_renamed.txt'):
    p = H / f
    if not p.exists():
        continue
    for l in p.read_text().splitlines():
        if '=' not in l or l.startswith('#'):
            continue
        k, v = l.split('=', 1)
        m = re.match(r'^@\w+@(\d+)$', k)
        want = (int(m.group(1)) - 8) if m else (int(re.match(r'^_\w+@(\d+)$', k).group(1)) if re.match(r'^_\w+@(\d+)$', k) else (0 if re.match(r'^_\w+$', k) else None))
        if want is None or v not in addr:
            continue
        got = ret_of(addr[v])
        if got is not None and got != max(want, 0):
            bad += 1
            print('%s: %s expects ret %d, %s does ret %d' % (f, k[:50], max(want, 0), v[:70], got))
print('alias ABI mismatches:', bad)
