"""Pair each vtable slot of a compiled object's ??_7Class vtables with the exe vtable that the class's constructor stores,
then byte-check every slot function the object defines. python vtable_check.py SOURCE OBJ CTOR_ADDR... (hex)"""
import json, re, struct, subprocess, sys
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
import capstone
from roc import clients
exe = clients.exe_path('2008-06', clients.load()['2008-06']).read_bytes()
pe = struct.unpack_from('<I', exe, 0x3c)[0]; nsec = struct.unpack_from('<H', exe, pe + 6)[0]; opt = struct.unpack_from('<H', exe, pe + 20)[0]
secs = [struct.unpack_from('<8sIIII', exe, pe + 24 + opt + 40 * i) for i in range(nsec)]
def rd(va, n):
    r = va - 0x400000
    for _, vs, vaddr, rs, rp in secs:
        if vaddr <= r < vaddr + max(vs, rs): return exe[rp + r - vaddr: rp + r - vaddr + n]
def coff_vtables(data):
    """{vtable symbol: [slot symbol names]} from relocations of each ??_7 symbol's section."""
    _, nsec, _, symptr, nsym, optsz, _ = struct.unpack_from('<HHIIIHH', data, 0)
    strtab = symptr + nsym * 18; syms = []; i = 0
    while i < nsym:
        raw, value, secnum, typ, cls, naux = struct.unpack_from('<8sIHHBB', data, symptr + 18 * i)
        secnum = secnum - 0x10000 if secnum >= 0xFFFE else secnum   # unsigned section number; -1 abs / -2 debug stay special
        name = data[strtab + struct.unpack_from('<I', raw, 4)[0]:].split(b'\0', 1)[0] if raw[:4] == b'\0\0\0\0' else raw.rstrip(b'\0')
        syms.append((name.decode('latin-1'), value, secnum)); syms.extend([None] * naux); i += 1 + naux
    out = {}
    for idx, s in enumerate(syms):
        if s and s[0].startswith('??_7') and s[2] > 0:
            sec = struct.unpack_from('<8sIIIIIIHHI', data, 20 + optsz + 40 * (s[2] - 1))
            relptr, nrel = sec[5], sec[7]
            rel = sorted(struct.unpack_from('<IIH', data, relptr + 10 * k) for k in range(nrel))
            out[s[0]] = [(off - s[1]) // 4 for off, _, _ in rel if off >= s[1]], [syms[sym][0] for off, sym, _ in rel if off >= s[1]]
    return out
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
src, obj = sys.argv[1], Path(sys.argv[2]); ctors = [int(a, 16) for a in sys.argv[3:]]
vts = coff_vtables(obj.read_bytes())
defined = {n for n, v in __import__('roc.rebuild', fromlist=['x']).coff_externals(obj.read_bytes()).items() if v}
def rtti_name(vt):
    col = struct.unpack_from('<I', rd(vt - 4, 4))[0]
    td = struct.unpack_from('<5I', rd(col, 20))[3]
    return rd(td + 8, 300).split(bytes(1), 1)[0].decode('latin-1')
exe_vts = {}
for ctor in ctors:
    for ins in md.disasm(rd(ctor, 0x200), ctor):
        if ins.mnemonic == 'mov' and ins.op_str.startswith('dword ptr [') and ', 0x' in ins.op_str:
            v = int(ins.op_str.split(', 0x')[1], 16)
            if 0x800000 < v < 0x880000:
                try:
                    exe_vts[rtti_name(v)] = v
                except Exception:
                    pass
jobs, paired = [], 0
for vt, (slots, syms) in vts.items():
    key = '.?AV' + vt[4:].rsplit('6B', 1)[0]
    if key not in exe_vts:
        continue
    paired += 1
    exe_slots = struct.unpack_from('<60I', rd(exe_vts[key], 240))
    for slot, sym in zip(slots, syms):
        if sym in defined and slot < 60:
            jobs.append({'addr': '%08x' % exe_slots[slot], 'symbol': sym})
checks = [0] * paired
m = ROOT / 'work/donorfree-route/vt.json'
m.write_text(json.dumps({'compiler_build': 21022, 'jobs': [{'source': src, 'checks': jobs}]}))
p = subprocess.run([sys.executable, str(ROOT / 'rebuild/2008-06/tests/native_check_runner.py'), 'run', str(m), '--workers', '1'], cwd=ROOT, capture_output=True, text=True)
d = json.loads(Path(json.loads(p.stdout.strip().splitlines()[-1])['results']).read_text()); rows = d if isinstance(d, list) else d['results']
st = [c['status'] for c in rows[0]['checks']]
print('vtables paired', len(checks), '| slot checks', len(st), '| exact', st.count('exact'))
from collections import Counter
bad = Counter(re.match(r'\?(\w+)@', c['requested_symbol']).group(1) for c in rows[0]['checks'] if c['status'] != 'exact')
print('non-exact by member:', dict(bad))
