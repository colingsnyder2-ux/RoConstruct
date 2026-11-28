"""python classdesc.py: converted Described<C>::classDescriptor() copies that build a SECOND ClassDescriptor in a dat_
static while the native classDescriptor<C> builds the real one. StarterPackService instances carried the converted
copy (dat_00977838): Reflection::Metadata knew only the native descriptor -> lookup fell back -> explorerOrder -1 ->
StarterPack missing from Explorer (and the copy's atexit destroyed the folded Instance descriptor).
Original side: functions calling ClassDescriptor::ClassDescriptor (0x5708f0) with a pushed class-name literal.
Native side: ?classDescriptor@?$Described@V<C>@...$1?s<X>@...@@ in our link whose s<X> string equals that literal.
Plan: converted definition func_<A> renamed away (natbody_defrename.json) + alias func_<A>=native (aliases_classdesc.txt)."""
import json, re, struct, bisect
from pathlib import Path
import capstone, pefile
H = Path(__file__).parent
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
o = pefile.PE(str(H.parents[1] / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image()
q = pefile.PE(str(H / 'run/RobloxQT.exe'), fast_load=True).get_memory_mapped_image()
B = 0x400000
def cstr(img, va):
    s = bytes(img[va - B:va - B + 64]).split(b'\0')[0]
    return s.decode('latin-1') if s and all(32 <= c < 127 for c in s) else None
ff = sorted(int(a, 16) for a in json.load(open(H.parents[0] / 'native-client/layout/function-files.json')))
CTOR = 0x5708f0
orig = {}   # A -> literal
for i, a in enumerate(ff):
    if not 0x401000 <= a < 0x7c0000:
        continue
    code = bytes(o[a - B:a - B + 0x80])
    if b'\xe8' not in code:
        continue
    pushes, hit = [], None
    for ins in md.disasm(code, a):
        if ins.mnemonic == 'push' and ins.op_str.startswith('0x'):
            pushes.append(int(ins.op_str, 16))
        if ins.mnemonic == 'call' and ins.op_str.startswith('0x') and int(ins.op_str, 16) == CTOR:
            hit = True; break
        if ins.mnemonic in ('ret', 'int3'):
            break
    if hit:
        lit = next((cstr(o, p) for p in pushes if 0x800000 <= p < 0x980000 and cstr(o, p)), None)
        if lit:
            orig[a] = lit
names, objat = {}, {}
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        try:
            names.setdefault(p[1], int(p[2], 16)); objat.setdefault(p[1], p[-1])
        except ValueError:
            pass
nat = {}
for n, v in names.items():
    m = re.match(r'^\?classDescriptor@\?\$Described@V(\w+)@RBX@@\$1\?(s\w+)@', n)
    if not m or re.fullmatch(r'(?:(?:ca|cf|dr|nx|ni)_)*[0-9a-f]{8}\.obj', objat[n]) or 'stubs' in objat[n]:
        continue
    sv = names.get('?%s@RBX@@3QBDB' % m.group(2)) or names.get('?%s@RBX@@3PADA' % m.group(2))
    lit = cstr(q, sv) if sv else None
    if lit:
        nat.setdefault(lit, set()).add(n)
plan, al = {}, {}
for a, lit in orig.items():
    tgt = nat.get(lit)
    fa = 'func_%08x' % a
    if not tgt or len(tgt) != 1:
        continue
    if re.fullmatch(r'(?:(?:ca|cf|dr|nx|ni)_)*[0-9a-f]{8}\.obj', objat.get(fa, '')) and names.get(fa) != names.get(next(iter(tgt))):
        plan['%08x.obj' % a] = {fa: '__rocmis_' + fa}
        al[fa] = next(iter(tgt))
pf = H / 'auto/natbody_defrename.json'
cur = json.loads(pf.read_text()) if pf.exists() else {}
for k, v in plan.items():
    cur.setdefault(k, {}).update(v)
pf.write_text(json.dumps(cur, indent=0))
af = H / 'aliases_classdesc.txt'
prev = dict(l.split('=', 1) for l in af.read_text().splitlines() if '=' in l) if af.exists() else {}
prev.update(al)
af.write_text(''.join('%s=%s\n' % kv for kv in sorted(prev.items())))
print('classdesc: original classDescriptor builders %d, native descriptors by name %d, converted copies rebound %d (total %d)'
      % (len(orig), len(nat), len(al), len(prev)))
print('  func_005c0080 ->', prev.get('func_005c0080'))
