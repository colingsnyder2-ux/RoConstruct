"""python dtoraudit.py: authoritative destructor address of every polymorphic class in the ORIGINAL, from RTTI: COL (offset 0)
-> vtable -> the slot whose body is a deleting destructor -> the ~T it calls. Compared with the identity registry: when the
registry gives ??1<T> to ANOTHER address (weak names: ICF-folded or replay-matched bodies, e.g. 0040b8a0 named ??1Decal,
really a different class's destructor that destroys +0x134), every caller of ??1<T> in our link runs the wrong body
(Insert Object close: ~Decal freed garbage -> 0xC0000374). Writes auto/dtoraudit.json {class: {true, reg, reg_name_at_true}}."""
import json, re, struct
from pathlib import Path
import capstone, pefile
H = Path(__file__).parent
reg = json.load(open(H.parents[1] / 'work/2008-06/identity-registry.json'))
byname = {}
for a, v in reg.items():
    if (v or {}).get('name'):
        byname.setdefault(v['name'], a)
pe = pefile.PE(str(H.parents[1] / 'clients/2008-06/Roblox.exe'), fast_load=True)
img, B = pe.get_memory_mapped_image(), 0x400000
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
d = lambda va: struct.unpack_from('<I', img, va - B)[0]
txt = pe.sections[0]; T0, T1 = B + txt.VirtualAddress, B + txt.VirtualAddress + txt.Misc_VirtualSize


def dtor_called(g):
    """deleting destructor at g (scalar or vector form) -> address of the ~T it calls in the scalar path, else None"""
    ins = []
    for i in md.disasm(bytes(img[g - B:g - B + 160]), g):
        ins.append(i)
        if i.mnemonic == 'ret' or len(ins) > 45:
            break
    t = ' | '.join(i.mnemonic + ' ' + i.op_str for i in ins)
    if not re.search(r'test byte ptr \[(esp|ebp) \+ [48]\], 1', t):
        return None
    calls = [i for i in ins if i.mnemonic == 'call' and i.op_str.startswith('0x')]
    if re.search(r'test byte ptr \[(esp|ebp) \+ [48]\], 2', t):   # vector form: the scalar path's call follows the jump target
        cand = [int(c.op_str, 16) for c in calls]
        cand = [c for c in cand if c != int(calls[0].op_str, 16)] if len(cand) > 2 else cand
        return cand[-2] if len(cand) >= 2 else None
    first_test = next(k for k, i in enumerate(ins) if i.mnemonic == 'test')
    pre = [i for i in ins[:first_test] if i.mnemonic == 'call' and i.op_str.startswith('0x')]
    return int(pre[0].op_str, 16) if len(pre) == 1 else None


out = {}
for m in re.finditer(rb'\.\?AV([\w@?$]+?)@@\x00', bytes(img)):
    td = B + m.start() - 8
    cls = m.group(1).decode() + '@@'
    k = struct.pack('<I', td); i = bytes(img).find(k)
    while i >= 0:
        col = B + i - 12
        if d(col) == 0:   # any subobject offset: the virtual destructor often sits in a secondary vtable
            j = bytes(img).find(struct.pack('<I', col))
            while j >= 0:
                vt = B + j + 4
                for s in range(60):
                    g = d(vt + 4 * s)
                    if not (T0 <= g < T1):
                        break   # end of this vtable (the next one's COL pointer, or data)
                    if True:
                        h = list(md.disasm(bytes(img[g - B:g - B + 12]), g))[:2]   # adjustor thunk -> its ??_G
                        if len(h) == 2 and re.fullmatch(r'(sub|add) ecx, \S+', h[0].mnemonic + ' ' + h[0].op_str) and h[1].mnemonic == 'jmp' and h[1].op_str.startswith('0x'):
                            g = int(h[1].op_str, 16)
                        t = dtor_called(g)
                        if t:
                            out.setdefault(cls, {'true': '%08x' % t, 'G': '%08x' % g})
                            break
                j = bytes(img).find(struct.pack('<I', col), j + 1)
        i = bytes(img).find(k, i + 1)
bad = {}
for cls, r in out.items():
    nm = '??1' + cls + 'UAE@XZ'
    for v in ('UAE@XZ', 'MAE@XZ', 'QAE@XZ', 'AAE@XZ', 'IAE@XZ'):
        if '??1' + cls + v in byname:
            nm = '??1' + cls + v
    r['dtor_name'] = nm
    r['reg'] = byname.get(nm)
    r['name_at_true'] = (reg.get(r['true']) or {}).get('name')
    if r['reg'] and r['reg'] != r['true']:
        bad[cls] = r
json.dump({'classes': out, 'mislabeled': bad}, open(H / 'auto/dtoraudit.json', 'w'), indent=0)
print('dtoraudit: classes with a deleting destructor %d, registry ??1 elsewhere %d, registry has no ??1 name %d'
      % (len(out), len(bad), sum(1 for r in out.values() if not r['reg'])))
for c, r in list(bad.items())[:12]:
    print('  %-40s true %s (registry there: %s) | registry ??1 at %s' % (c[:40], r['true'], (r['name_at_true'] or '')[:40], r['reg']))
