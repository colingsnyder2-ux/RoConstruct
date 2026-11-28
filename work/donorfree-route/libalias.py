"""python libalias.py DIR [DIR...]: bind stubbed func_<X> to functions of compiled LIBRARY objects (xtpbuild.py output)
whose body equals the original's at X. Unnamed XTP helpers (tab paint manager, docking, tree) had no registry name,
so the window procs got `return 0` stubs. Signature = instruction bytes up to the first ret, every relocation site
(COFF relocations in the object; rel32 call/jmp + image-address dwords in the original) masked. Unique matches only.
Writes aliases_libalias.txt (func_X=symbol, grow-only) and linkexp/libalias/<obj> copies that KEEP only the matched
functions (strip_symbols keep=: no clash with natives); linkexp/libalias_objs.txt lists them for quicktest."""
import collections, hashlib, json, re, struct, sys
from pathlib import Path
import capstone, pefile
H = Path(__file__).parent
ROOT = H.parents[1]
sys.path.insert(0, str(ROOT))
from roc import rebuild
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)


def sig_bytes(code, base, mask):
    out = bytearray()
    for ins in md.disasm(bytes(code), base):
        raw = bytearray(ins.bytes)
        for k in range(len(raw)):
            if ins.address - base + k in mask:
                raw[k] = 0
        if raw[0] in (0xe8, 0xe9) and len(raw) == 5:
            raw[1:] = b'\0\0\0\0'
        out += raw
        if ins.mnemonic in ('ret', 'int3'):
            break
    return hashlib.sha1(bytes(out)).hexdigest() if len(out) >= 8 else None


def obj_funcs(path):
    d = Path(path).read_bytes()
    _, nsec, _, sp, ns, opt, _ = struct.unpack_from('<HHIIIHH', d, 0)
    st = sp + ns * 18
    secs = [struct.unpack_from('<8sIIIIIIHHI', d, 20 + opt + 40 * i) for i in range(nsec)]
    syms, i = [], 0
    while i < ns:
        raw, val, sec, typ, cls, naux = struct.unpack_from('<8sIHHBB', d, sp + 18 * i)
        if raw[:4] == b'\0\0\0\0':
            o = st + struct.unpack_from('<I', raw, 4)[0]; n = d[o:d.index(b'\0', o)].decode('latin-1')
        else:
            n = raw.rstrip(b'\0').decode('latin-1')
        if typ == 0x20 and cls == 2 and 0 < sec <= nsec:
            syms.append((n, sec, val))
        i += 1 + naux
    for n, sec, val in syms:
        name, vs, va, size, ptr, relptr, _, nrel, _, ch = secs[sec - 1]
        if not ch & 0x20 or not size:
            continue
        code = d[ptr:ptr + size]
        mask = set()
        for r in range(nrel):
            off = struct.unpack_from('<I', d, relptr + 10 * r)[0]
            mask.update(range(off - val, off - val + 4))
        s = sig_bytes(code[val:], 0, mask)
        if s:
            yield n, s


def orig_sig(img, x, nxt):
    code = img[x - 0x400000:x - 0x400000 + min(nxt - x, 0x2000)]
    mask = set()
    for ins in md.disasm(bytes(code), x):
        for k in range(len(ins.bytes) - 3):
            v = struct.unpack_from('<I', ins.bytes, k)[0]
            if 0x400000 <= v < 0x9a0000:
                mask.update(range(ins.address - x + k, ins.address - x + k + 4))
        if ins.mnemonic in ('ret', 'int3'):
            break
    return sig_bytes(code, x, mask)


dirs = [Path(a) for a in sys.argv[1:]] or [H / 'linkexp/xtplib']
idx = collections.defaultdict(set)
for dd in dirs:
    for f in sorted(dd.glob('*.obj')):
        for n, s in obj_funcs(f):
            idx[s].add((str(f), n))
o = pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image()
ff = sorted(int(a, 16) for a in json.load(open(ROOT / 'work/native-client/layout/function-files.json')))
import bisect
stubs = []
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and p[0].startswith('0001:') and 'stubs' in p[-1] and re.fullmatch(r'func_[0-9a-f]{8}', p[1]):
        stubs.append(p[1])
al, keep = {}, collections.defaultdict(set)
for s_ in stubs:
    x = int(s_[5:], 16)
    i = bisect.bisect_right(ff, x)
    sg = orig_sig(o, x, ff[i] if i < len(ff) else x + 0x200)
    c = idx.get(sg, set()) if sg else set()
    names = {n for _, n in c}
    if len(names) == 1:
        f, n = sorted(c)[0]
        al[s_] = n; keep[f].add(n)
exec(open(H / 'libalias_g.py', encoding='utf-8').read())
outd = H / 'linkexp/libalias'
outd.mkdir(exist_ok=True)
lst = []
for f, ns in keep.items():
    q = outd / Path(f).name
    q.write_bytes(bytes(rebuild.strip_symbols(Path(f).read_bytes(), keep=ns)))
    lst.append(str(q))
af = H / 'aliases_libalias.txt'
if af.exists():
    for l in af.read_text().splitlines():
        if '=' in l:
            k, v = l.split('=', 1); al.setdefault(k, v)
af.write_text(''.join('%s=%s\n' % kv for kv in sorted(al.items())))
lf = H / 'linkexp/libalias_objs.txt'
prev = set(lf.read_text().split()) if lf.exists() else set()
lf.write_text('\n'.join(sorted(prev | set(lst))) + '\n')
print('libalias: library functions indexed %d, func_ stubs %d, bound %d from %d objects' % (sum(len(v) for v in idx.values()), len(stubs), len(al), len(keep)))
