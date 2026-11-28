"""python descinit.py: run the ORIGINAL reflection-descriptor initializers that no native object performs.
`part:Remove()` failed ("Remove is not a valid member of Part") for every class: Instance's function descriptors
(Remove 0x973cd8.., Clone, ...) are file statics the original builds in unnamed .CRT$XCU initializers
(func_007f2910..007f2a90: mov ecx, <global>; call ??0?$BoundFuncDesc<...>), and our native Instance TU never defines
them. Same class of gap as creatorinit.py. Candidates: initializers in 0x7c0000-0x801000 that construct a global with
a Reflection descriptor ctor (BoundFuncDesc / SignalDesc / PropDescriptor / BoundProp / ...); skipped when the global
has a name our link defines natively (that native ??__E constructs it). Writes linkexp/xcu_descs.obj (.CRT$XCU
pointers to the converted func_<A>); quicktest links it after the native objects."""
import json, os, re, struct
from pathlib import Path
import capstone, pefile
H = Path(__file__).parent
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
o = pefile.PE(str(H.parents[1] / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image()
B = 0x400000
reg = json.load(open(H.parents[0] / '2008-06/identity-registry.json'))
CTOR = re.compile(r'\?\?0\?\$(BoundFuncDesc|BoundYieldFuncDesc|BoundCallbackDesc|SignalDesc|PropDescriptor|BoundProp|'
                  r'EnumPropDescriptor|RefPropDescriptor|FuncDesc)@.*@Reflection@RBX@@QAE@')
datname = {}
for l in open(H / 'aliases_renamed.txt', errors='replace'):
    m = re.match(r'dat_([0-9a-f]{8})=(.+)$', l.strip())
    if m:
        datname[int(m.group(1), 16)] = m.group(2)
defs = {}
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        defs.setdefault(p[1], p[-1])
ff = sorted(int(a, 16) for a in json.load(open(H.parents[0] / 'native-client/layout/function-files.json')))
cands = {}
for a in ff:
    if not 0x7c0000 <= a < 0x801000:
        continue
    tgt = None; lit = None
    for ins in md.disasm(bytes(o[a - B:a - B + 0x60]), a):
        if ins.mnemonic == 'push' and ins.op_str.startswith('0x') and lit is None and 0x800000 <= int(ins.op_str, 16) < 0x900000:
            sb = bytes(o[int(ins.op_str, 16) - B:int(ins.op_str, 16) - B + 64]).split(b'\0')[0]
            if sb and all(32 <= c < 127 for c in sb):
                lit = sb   # the descriptor's Lua-visible name ("Remove")
        m = re.match(r'ecx, 0x([0-9a-f]+)$', ins.op_str) if ins.mnemonic == 'mov' else None
        if m and int(m.group(1), 16) >= 0x900000:
            tgt = int(m.group(1), 16)
        if ins.mnemonic == 'call' and ins.op_str.startswith('0x'):
            if tgt and CTOR.match((reg.get('%08x' % int(ins.op_str, 16)) or {}).get('name') or ''):
                cands[a] = (tgt, lit)
            break   # the descriptor ctor is the initializer's first call
        if ins.mnemonic in ('ret', 'int3'):
            break
# native objects that construct reflection descriptors: their name literals (a native TU registering the same name,
# e.g. Player's LoadCharacter as _loadCharacterFunction, must not get a second, converted copy: declare() crashed)
import pickle
CF = H / 'auto/descinit_lits.pkl'
cache = pickle.load(open(CF, 'rb')) if CF.exists() else {}
natset = set()
for l in open(H / 'linkexp/qt.final.rsp'):
    p_ = l.strip().strip('"')
    bn = os.path.basename(p_)
    if not p_.lower().endswith('.obj') or 'renamed' in p_ or 'stubs' in p_ or re.fullmatch(r'(?:(?:ca|cf|dr|nx|ni|su|rs|lc)_)*[0-9a-f]{8}\.obj', bn) or not os.path.exists(p_):
        continue   # converted copies (ca_/rs_/ni_..._<A>.obj) carry the original TU's whole literal pool
    k = (os.path.getmtime(p_), os.path.getsize(p_))
    c = cache.get(p_)
    if not c or c[0] != k:
        b_ = open(p_, 'rb').read()
        lits = set(re.findall(rb'\0([ -~]{2,40})(?=\0)', b_)) if b'@Reflection@RBX@@QAE@' in b_ and re.search(rb'BoundFuncDesc|SignalDesc|PropDescriptor|BoundProp', b_) else set()
        c = cache[p_] = (k, lits)
    natset |= c[1]
pickle.dump(cache, open(CF, 'wb'))
conv = {Path(r_['object']).name for r_ in json.load(open(H / 'renamed/results.json'))}
rr = json.loads((H / 'renamed/rename.json').read_text())


def native(c):
    t, lit = c
    if lit and lit in natset:
        return True
    n = (reg.get('%08x' % t) or {}).get('name') or datname.get(t)
    ob = defs.get(n) if n else None
    return ob is not None and 'stubs' not in ob and not re.fullmatch(r'(?:(?:ca|cf|dr|nx|ni|su)_)*[0-9a-f]{8}\.obj', ob)


pick = sorted(a for a, t in cands.items() if not native(t) and '%08x.obj' % a in conv and (rr.get('%08x' % a) or {}).get('symbol'))
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
(H / 'linkexp/xcu_descs.obj').write_bytes(obj)
print('descinit: original descriptor initializers %d, natively constructed %d, converted initializers run %d (e.g. %s)'
      % (len(cands), sum(1 for c in cands.values() if native(c)), n, ['%08x' % a for a in pick[:6]]))
