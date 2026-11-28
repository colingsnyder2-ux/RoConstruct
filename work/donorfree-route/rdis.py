"""python rdis.py ADDR|SYMBOL [N] [orig]: disassemble our exe (or the original) with map/registry names on operands."""
import json, os, re, sys
import capstone, pefile
from pathlib import Path
H = Path(__file__).parent
orig = 'orig' in sys.argv
img = bytes(pefile.PE(str(H.parents[1] / 'clients/2008-06/Roblox.exe') if orig else os.environ.get('RDIS_EXE') or str(H / 'link/donorfree.exe')).get_memory_mapped_image())
names = {}
if orig:
    for a, v in json.load(open(H.parents[1] / 'work/native-client/layout/function-files.json')).items():
        names[int(a, 16)] = (v or {}).get('name') or 'fn_' + a
else:
    for l in open(os.environ.get('RDIS_MAP') or H / 'link/donorfree.map', errors='replace'):
        m = re.match(r'\s*000\d:[0-9a-f]{8}\s+(\S+)\s+([0-9a-f]{8})', l)
        if m:
            names.setdefault(int(m.group(2), 16), m.group(1))
t = sys.argv[1]
a = int(t, 16) if re.fullmatch(r'[0-9a-fA-F]{6,8}', t) else next(k for k, v in names.items() if v == t)
n = int(sys.argv[2]) if len(sys.argv) > 2 and sys.argv[2].isdigit() else 60
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
for k, i in enumerate(md.disasm(img[a - 0x400000:a - 0x400000 + 0x1000], a)):
    op = i.op_str
    for h_ in re.findall(r'0x[0-9a-f]{6,8}', op):
        if int(h_, 16) in names:
            op += '  ; ' + names[int(h_, 16)][:80]
    print('%08x %-6s %s' % (i.address, i.mnemonic, op))
    if k >= n or i.mnemonic == 'ret':
        break
