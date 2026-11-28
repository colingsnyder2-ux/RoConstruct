"""python natret.py: callee-pop audit of NATIVE methods reached through vtables. For each vt_orig vtable slot (original
layout, original address known) whose target in our exe is native code (not converted <X>.obj, not a stub), compare
the target's `ret N` with the original slot function's. A native override with a different parameter list (wrong
header) pops a different amount and skews its caller's stack (func_00575ba0 returned to 0 after an input listener call).
Writes auto/natret.json [[vtable, slot, our symbol, our ret, original ret]]."""
import bisect, json, pickle, re, struct, sys
from pathlib import Path
import capstone, pefile
H = Path(__file__).parent
sys.path.insert(0, str(H))
import make_stubs as ms
q = pefile.PE(str(H / 'run/RobloxQT.exe'), fast_load=True).get_memory_mapped_image()
B = 0x400000
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
names, objat, vt = {}, {}, {}
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        try:
            v = int(p[2], 16)
        except ValueError:
            continue
        names.setdefault(v, p[1]); objat.setdefault(v, p[-1])
        if p[1].startswith(('??_7', '??_S')) and p[-1] in ('vt_orig.obj', 'vt_orig_remap.obj'):
            vt[p[1]] = v
_, vo = pickle.load(open(H / 'auto/orig_vt.pkl', 'rb'))
by_t = {}
for (tn, off), (oa, sl) in vo.items():
    by_t.setdefault(tn, []).append((off, oa, sl))
col_off = {}
for n, a in vt.items():
    c = struct.unpack_from('<I', q, a - B - 4)[0]
    if B < c < 0x4000000:
        col_off[n] = struct.unpack_from('<I', q, c - B + 4)[0]


def our_ret(a):
    for _ in range(3):   # follow jmp thunks
        b = bytes(q[a - B:a - B + 5])
        if b[0] == 0xe9:
            a = a + 5 + struct.unpack_from('<i', b, 1)[0]; continue
        if b[:2] == b'\xff\x25':
            return None
        break
    for ins in md.disasm(bytes(q[a - B:a - B + 0x1000]), a):
        if ins.mnemonic == 'ret':
            return int(ins.op_str, 16) if ins.op_str else 0
        if ins.mnemonic == 'int3':
            return None
    return None


bad, tables = [], {}
for n, a in vt.items():
    m = re.match(r'^\?\?_[7S](.+?)@@6B', n)
    if not m or n not in col_off:
        continue
    cand = [x for x in by_t.get('.?AV%s@@' % m.group(1), []) + by_t.get('.?AU%s@@' % m.group(1), []) if x[0] == col_off[n]]
    if len(cand) != 1:
        continue
    _, oa, sl = cand[0]
    tables[n] = '%08x' % oa
    for i, ot in enumerate(sl):
        t = struct.unpack_from('<I', q, a - B + 4 * i)[0]
        ob = objat.get(t, '')
        if not ob or re.fullmatch(r'(?:ca_)?[0-9a-f]{8}\.obj', ob) or 'stubs' in ob or ':' in ob or not 0x401000 <= ot < 0x7c0000:
            continue
        r_o, r_q = ms.addr_ret_bytes(ot), our_ret(t)
        if r_q is not None and r_o != r_q:
            bad.append([n, i, names.get(t, '%08x' % t), r_q, r_o])
(H / 'auto/natret.json').write_text(json.dumps(bad, indent=0))
try:
    tables = {**json.loads((H / 'auto/natret_tables.json').read_text()), **tables}
except (OSError, ValueError):
    pass
(H / 'auto/natret_tables.json').write_text(json.dumps(tables))
print('native vtable targets whose pop size differs from the original slot: %d' % len(bad))
for b in bad[:25]:
    print('  %-60s slot %3d %-60s ret %s orig %s' % (b[0][:60], b[1], b[2][:60], b[3], b[4]))
