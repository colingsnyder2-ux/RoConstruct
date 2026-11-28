"""python annot_dis.py ADDR [-n BYTES]: disasm of the original 2008-06 exe with string literals, IAT imports and known function names inline."""
import sys, struct, json, re, pefile, capstone
sys.path.insert(0, '.')
from roc import clients
exe = clients.exe_path('2008-06', clients.load()['2008-06']).read_bytes()
pe = pefile.PE(data=exe)
base = pe.OPTIONAL_HEADER.ImageBase
names = {int(a, 16): (r.get('name') or '') for a, r in json.load(open('work/native-client/layout/function-files.json')).items()}
imports = {}
for e in pe.DIRECTORY_ENTRY_IMPORT:
    for i in e.imports:
        imports[i.address] = '%s!%s' % (e.dll.decode().split('.')[0], (i.name or b'#%d' % i.ordinal).decode())
def rd(v, n=96):
    try:
        o = pe.get_offset_from_rva(v - base); return exe[o:o + n]
    except Exception: return None
def strat(v):
    b = rd(v)
    if not b: return None
    s = b.split(b'\0')[0]
    if len(s) >= 3 and all(32 <= c < 127 for c in s): return s.decode()
    return None
args = sys.argv[1:]; n = 0x200
if '-n' in args:
    i = args.index('-n'); n = int(args[i + 1], 0); del args[i:i + 2]
v = int(args[0], 16)
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
for ins in md.disasm(rd(v, n), v):
    note = ''
    for tok in re.findall(r'0x[0-9a-f]+', ins.op_str):
        t = int(tok, 16)
        if ins.mnemonic == 'call' and ins.op_str.startswith('0x') and t in names: note = names[t][:90]
        elif t in imports: note = imports[t]
        elif 0x700000 < t < 0x900000 and ins.mnemonic in ('push', 'mov', 'lea'):
            s = strat(t)
            if s: note = repr(s)
    print('%08x %-6s %-28s %s' % (ins.address, ins.mnemonic, ins.op_str, ('; ' + note) if note else ''))
