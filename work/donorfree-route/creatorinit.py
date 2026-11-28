"""python creatorinit.py: run the ORIGINAL factory-creator registrations that no native object performs.
Insert Object listed 23 of 41 classes: AbstractFactoryProduct<Instance>::create found no creator for BoolValue, Decal,
Message, Sparkles, the Value classes...: the original registers each FactoryProduct<C>::creator from a .CRT$XCU
initializer (getCreators()[&Name] = &creator; atexit unregister), and our native objects only define 74 of them
(??__E?creator@?$FactoryProduct@V<C>...). The converted initializers are linked but nothing calls them.
Original pattern: an initializer calling getCreators (0x405da0) and map::operator[], storing a creator address.
Class name = the doDeclare<s<X>> it calls. Skips classes a native ??__E?creator registers. Writes
linkexp/xcu_creators.obj (.CRT$XCU pointers to the converted func_<A>)."""
import json, re, struct, bisect
from pathlib import Path
import capstone, pefile
H = Path(__file__).parent
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
o = pefile.PE(str(H.parents[1] / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image()
B = 0x400000
reg = json.load(open(H.parents[0] / '2008-06/identity-registry.json'))
GETCREATORS = 0x405da0
ff = sorted(int(a, 16) for a in json.load(open(H.parents[0] / 'native-client/layout/function-files.json')))
cands = {}
for a in ff:
    if not 0x7c0000 <= a < 0x801000:   # static initializers live at the end of .text
        continue
    calls, store, cls = [], False, None
    for ins in md.disasm(bytes(o[a - B:a - B + 0x60]), a):
        if ins.mnemonic == 'call' and ins.op_str.startswith('0x'):
            t = int(ins.op_str, 16); calls.append(t)
            m = re.match(r'\?\?\$doDeclare@\$1\?(s\w+)@', (reg.get('%08x' % t) or {}).get('name') or '')
            if m:
                cls = m.group(1)
        if ins.mnemonic == 'mov' and ins.op_str.startswith('dword ptr [eax], 0x'):
            store = True
        if ins.mnemonic in ('ret', 'int3'):
            break
    if GETCREATORS in calls and store and cls and '_atexit' not in str(calls):
        cands[a] = cls
names, objat = {}, {}
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        names.setdefault(p[1], p[-1])
native = set()
for n, ob in names.items():
    m = re.match(r'\?\?__E\?creator@\?\$FactoryProduct@.*?\$1\?(s\w+)@', n)
    if m and not re.fullmatch(r'(?:(?:ca|cf|dr|nx|ni)_)*[0-9a-f]{8}\.obj', ob):
        native.add(m.group(1))
conv = {Path(r_['object']).name for r_ in json.load(open(H / 'renamed/results.json'))}   # linked converted set (dropped by /OPT:REF until referenced)
rr = json.loads((H / 'renamed/rename.json').read_text())
# the converted object's own symbol (func_<A> or the ??__E?creator@... name rename.json kept: Decal, Message, the
# Value classes were skipped because only func_<A> spellings were accepted)
pick = sorted(a for a, c in cands.items() if c not in native and '%08x.obj' % a in conv and (rr.get('%08x' % a) or {}).get('symbol'))
syms = [rr['%08x' % a]['symbol'] for a in pick]
n = len(syms)
raw = bytes(4 * n)
strtab, symtab = bytearray(), bytearray()
for s in syms:
    b = s.encode()
    nm = b.ljust(8, b'\0') if len(b) <= 8 else struct.pack('<II', 0, 4 + len(strtab))
    if len(b) > 8:
        strtab += b + b'\0'
    symtab += nm + struct.pack('<IhHBB', 0, 0, 0x20, 2, 0)
raw_ptr = 60; rel_ptr = raw_ptr + len(raw); sym_ptr = rel_ptr + 10 * n
relocs = b''.join(struct.pack('<IIH', 4 * i, i, 6) for i in range(n))
obj = struct.pack('<HHIIIHH', 0x14c, 1, 0, sym_ptr, n, 0, 0) + b'.CRT$XCU' + struct.pack('<IIIIIIHHI', 0, 0, len(raw), raw_ptr, rel_ptr, 0, n, 0, 0x40300040) \
    + raw + relocs + bytes(symtab) + struct.pack('<I', 4 + len(strtab)) + bytes(strtab)
(H / 'linkexp/xcu_creators.obj').write_bytes(obj)
print('creatorinit: original creator registrations %d, natively registered classes %d, converted registrations run %d (%s)'
      % (len(cands), len(native), n, sorted(cands[a] for a in pick)[:12]))
