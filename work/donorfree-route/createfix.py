"""python createfix.py: stubbed func_<X> that are really Creatable<Instance>::create<T>() (the original body mallocs,
calls T's constructor and wraps the object in a shared_ptr) -> aliases_createfix.txt func_<X> = our linked
??$create@VT@..@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VT@..@@@boost@@XZ. ICF-folded registry names lie
(00639a00 'create<Team>' builds a Color3Value), so T is the class whose vtable the constructor stores.
Insert Object -> Creator<...>::create called the stub -> null deref. Lists the create<T> names we would need to build
(auto/createfix_missing.json) for createinst."""
import json, re
from pathlib import Path
import capstone, pefile
H = Path(__file__).parent
reg = json.load(open(H.parents[1] / 'work/2008-06/identity-registry.json'))
o = pefile.PE(str(H.parents[1] / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image()
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
MALLOC = bytes([0xFF, 0x15, 0xB0, 0x28, 0x80, 0x00])   # call dword ptr [__imp__malloc]
VTSTORE = re.compile(r'dword ptr \[e(?:si|ax|cx|di)\], 0x([0-9a-f]+)$')
stubs, defined = set(), set()
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        (stubs if 'stubs' in p[-1] else defined).add(p[1])


def body(a, n):
    return list(md.disasm(bytes(o[a - 0x400000:a - 0x400000 + n]), a))


def class_of(A):
    if MALLOC not in bytes(o[A - 0x400000:A - 0x400000 + 0x60]):
        return None
    ins = body(A, 0xa0)
    k = next((i for i, x in enumerate(ins) if x.mnemonic == 'call' and 'ptr [0x8028b0]' in x.op_str), None)
    if k is None:
        return None
    ctor = next((int(x.op_str, 16) for x in ins[k + 1:] if x.mnemonic == 'call' and x.op_str.startswith('0x')), None)
    if not ctor:
        return None
    for j in body(ctor, 0x120):
        m = VTSTORE.match(j.op_str) if j.mnemonic == 'mov' else None
        if m:
            vn = (reg.get('%08x' % int(m.group(1), 16)) or {}).get('name') or ''
            mv = re.fullmatch(r'\?\?_7(.+@)6B@', vn)
            return ('V' + mv.group(1)) if mv else None
        if j.mnemonic == 'ret':
            return None
    return None


out, miss = {}, []
for s in sorted(stubs):
    m = re.fullmatch(r'func_([0-9a-f]{8})', s)
    if not m or not 0x401000 <= int(m.group(1), 16) < 0x7c0000:
        continue
    T = class_of(int(m.group(1), 16))
    if not T:
        continue
    want = '??$create@%s@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@%s@boost@@XZ' % (T, T)
    if want in defined:
        out[s] = want
    else:
        miss.append((s, want))
try:   # grow-only: once aliased, a stub no longer shows in the map and a rerun wiped the file
    for l_ in open(H / 'aliases_createfix.txt'):
        if '=' in l_:
            k_, v_ = l_.strip().split('=', 1)
            out.setdefault(k_, v_)
except OSError:
    pass
(H / 'aliases_createfix.txt').write_text(''.join('%s=%s\n' % kv for kv in sorted(out.items())))
(H / 'auto/createfix_missing.json').write_text(json.dumps(miss, indent=0))
print('createfix: stubbed create<T> bodies %d aliased, %d without a linked create<T>' % (len(out), len(miss)))
for s, w in miss[:30]:
    print('  missing', s, w[:120])
