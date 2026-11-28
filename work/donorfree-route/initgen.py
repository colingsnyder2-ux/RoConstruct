"""python initgen.py: original static objects that our link only has as ZERO STUBS. The original builds ~490 globals in
.CRT$XCU initializers (mov ecx, G / push args / call CTOR / atexit DTOR); the converted initializer objects are analog
mocks (`struct D d`, 1-byte .bss), so G stayed a zero stub: MeshCache's static Ogre::MeshPtr 0x9738b8 had no vtable
and the first script-parented Part crashed in rgmain (RenderScene::render -> MeshCache::update).
For every initializer of that simple shape whose G is stubbed, writes one native TU
work/native-client/stub-drafts/InitGen.cpp:  struct I_<A> { I_<A>(unsigned...); char b[SIZE]; } g_<A>(args...);
the ctor is aliased to CTOR (its func_ / registry / import name), address arguments to their symbols, string
arguments become literals of the original text; SIZE = distance to the next known original data item (<= 0x400).
No destructor (nothing at exit). Skips reflection descriptors whose name literal a native TU registers (duplicate
declare). Compiles it (bindsrc.py) and writes aliases_initgen.txt (dat_G / stubbed name -> g_<A>, ctor/args)."""
import json, os, re, struct, subprocess, sys, pickle
from pathlib import Path
import capstone, pefile
H = Path(__file__).parent
ROOT = H.parents[1]
sys.path.insert(0, str(ROOT))
from roc import rebuild as rb
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
pe = pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe'))
img = pe.get_memory_mapped_image()
B = 0x400000
iat = {}
for d in pe.DIRECTORY_ENTRY_IMPORT:
    for s in d.imports:
        if s.name:
            iat[s.address] = s.name.decode('latin-1')
reg = json.load(open(ROOT / 'work/2008-06/identity-registry.json'))
dat = {}
for l in open(H / 'aliases_renamed.txt', errors='replace'):
    m = re.match(r'dat_([0-9a-f]{8})=(.+)$', l.strip())
    if m:
        dat[int(m.group(1), 16)] = m.group(2)
defs = {}
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        defs.setdefault(p[1], p[-1])
known = sorted({int(a, 16) for a in reg if re.fullmatch(r'[0-9a-f]{8}', a) and int(a, 16) >= 0x900000} | set(dat))


def name_of(a):
    return (reg.get('%08x' % a) or {}).get('name') or dat.get(a)


def is_stub(n):
    o = defs.get(n)
    return o is None or 'stubs' in o


def sym_for_code(t):
    n = 'func_%08x' % t
    if n in defs:
        return n
    rn = (reg.get('%08x' % t) or {}).get('name')
    return rn if rn and rn in defs else n


def cstr(a):
    s = bytes(img[a - B:a - B + 256]).split(b'\0')[0]
    return s.decode('latin-1') if s and all(32 <= c < 127 for c in s) and len(s) < 200 else None


natset = set()
try:   # descinit.py's per-object literal cache: name literals native descriptor TUs register
    for _k, (_m, lits) in pickle.load(open(H / 'auto/descinit_lits.pkl', 'rb')).items():
        natset |= lits
except (OSError, ValueError):
    pass
ff = sorted(int(a, 16) for a in json.load(open(ROOT / 'work/native-client/layout/function-files.json')) if 0x7c0000 <= int(a, 16) < 0x801000)
items = []
for a in ff:
    ins = list(md.disasm(bytes(img[a - B:a - B + 0x60]), a))
    end = next((i for i, x in enumerate(ins) if x.mnemonic == 'ret'), None)
    if end is None or not any(x.mnemonic == 'call' and x.op_str == '0x6a17af' for x in ins[:end]):
        continue
    regs, pushes, G, ctor, ok = {'ecx': 0, 'eax': None}, [], None, None, True
    for x in ins:
        m, o = x.mnemonic, x.op_str
        if (m, o) in (('push', 'ebp'), ('mov', 'ebp, esp'), ('pop', 'ebp')):
            continue
        if m == 'xor' and o in ('ecx, ecx', 'eax, eax'):
            regs[o[:3]] = 0; continue
        if m == 'mov' and re.fullmatch(r'(eax|ecx), 0x[0-9a-f]+', o):
            r_, v = o.split(', '); v = int(v, 16)
            if r_ == 'ecx' and v >= 0x900000:
                G = v
            else:
                regs[r_] = v
            continue
        if m == 'push':
            if o.startswith('0x') or o.isdigit():
                pushes.append(int(o, 0))
            elif o in regs and regs[o] is not None:
                pushes.append(regs[o])
            else:
                ok = False
            continue
        if m == 'call':
            if o.startswith('0x'):
                ctor = ('code', int(o, 16))
            else:
                mm = re.fullmatch(r'dword ptr \[0x([0-9a-f]+)\]', o)
                ctor = ('imp', iat.get(int(mm.group(1), 16))) if mm else None
            break
        ok = False; break
    if not ok or G is None or ctor is None or (ctor[0] == 'imp' and not ctor[1]):
        continue
    gname = name_of(G)
    if not is_stub(gname or 'dat_%08x' % G) or not is_stub('dat_%08x' % G):
        continue
    if ctor[0] == 'code':
        cn = (reg.get('%08x' % ctor[1]) or {}).get('name') or ''
        lits = [cstr(v) for v in pushes if 0x800000 <= v < 0x900000]
        if '@Reflection@RBX@@' in cn and any(l and l.encode() in natset for l in lits):
            continue
    j = next((k for k in known if k > G), G + 0x400)
    items.append((a, G, gname, ctor, list(reversed(pushes)), max(4, min(j - G, 0x400))))
src = ['// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS',
       '// generated by work/donorfree-route/initgen.py: original static objects built by .CRT$XCU initializers',
       '// (INFERRED storage: size = distance to the next known original data item; constructor = the original one).', '']
refs = {}
for a, G, gname, ctor, args, size in items:
    cargs = []
    for v in args:
        if 0x800000 <= v < 0x900000 and cstr(v) is not None:
            cargs.append('(unsigned)"%s"' % cstr(v).replace('\\', '\\\\').replace('"', '\\"'))
        elif 0x401000 <= v < 0x800000 or 0x800000 <= v < 0x1400000:
            refs[v] = 1; cargs.append('(unsigned)&r_%08x' % v)
        else:
            cargs.append('%du' % v)
    src.append('struct I_%08x { I_%08x(%s); char b[%d]; };   // init %08x -> %08x %s' % (
        a, a, ', '.join(['unsigned'] * len(args)), size, a, G, (gname or '')[:60]))
    src.append('I_%08x g_%08x%s;' % (a, a, '(%s)' % ', '.join(cargs) if cargs else ''))
src[4:4] = ['extern char r_%08x;' % v for v in sorted(refs)] + ['']
out = ROOT / 'work/native-client/stub-drafts/InitGen.cpp'
out.write_text('\n'.join(src) + '\n')
r = subprocess.run([sys.executable, str(H / 'bindsrc.py'), str(out)], capture_output=True, text=True)
print(r.stdout.strip()[-300:], r.stderr.strip()[-600:])
res = re.search(r'bound (.+results\.json)', r.stdout)
if not res:
    sys.exit('initgen: compile failed')
obj = Path(json.loads(Path(res.group(1)).read_text())[0]['object']).read_bytes()
ext = rb.coff_externals(obj)
al = {}
for a, G, gname, ctor, args, size in items:
    g = next((n for n in ext if n.startswith('?g_%08x@@' % a)), None)
    c = next((n for n in ext if n.startswith('??0I_%08x@@' % a)), None)
    if not g or not c:
        continue
    al['dat_%08x' % G] = g
    if gname and gname != 'dat_%08x' % G:
        al[gname] = g
    al[c] = ctor[1] if ctor[0] == 'imp' else sym_for_code(ctor[1])
for v in refs:
    n = next((x for x in ext if x.startswith('?r_%08x@@' % v)), None)
    if n:
        al[n] = sym_for_code(v) if v < 0x800000 else (name_of(v) or 'dat_%08x' % v)
(H / 'aliases_initgen.txt').write_text(''.join('%s=%s\n' % kv for kv in sorted(al.items())))
print('initgen: stubbed initializer-built globals %d, aliases %d (MeshPtr 0x9738b8: %s)' % (len(items), len(al), al.get('dat_009738b8')))
