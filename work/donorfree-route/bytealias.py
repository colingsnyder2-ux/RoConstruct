"""python bytealias.py: bind stubbed func_<X> to code our link ALREADY has under another name. Unnamed library functions
(XTP's tab paint-manager / docking helpers, func_0077da70...) are in the linked XTP objects, but with no registry name
nothing tied func_<X> to them: the window procs got `return 0` stubs. Signature = the function's bytes up to its
padding, with every rel32 call/jmp operand and every image-address dword masked; a UNIQUE signature equal in the
original (at X) and in our exe (a non-stub function) -> alias func_<X>=<our name>. Writes aliases_bytealias.txt
(grow-only) and prints counts. Quicktest reads the file."""
import collections, hashlib, json, re, struct
from pathlib import Path
import capstone, pefile
H = Path(__file__).parent
ROOT = H.parents[1]
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
md.detail = False


def sig(img, va, lo, hi, nxt):
    o = va - 0x400000
    end = min(nxt - va, 0x2000)
    b = bytearray(img[o:o + end])
    out, n = bytearray(), 0
    for ins in md.disasm(bytes(b), va):
        raw = bytearray(ins.bytes)
        if ins.mnemonic in ('call', 'jmp') and raw[0] in (0xe8, 0xe9):
            raw[1:] = b'\0' * (len(raw) - 1)
        else:
            for k in range(len(raw) - 3):
                v = struct.unpack_from('<I', raw, k)[0]
                if lo <= v < hi:
                    raw[k:k + 4] = b'\0\0\0\0'
        out += raw; n += len(ins.bytes)
        if ins.mnemonic in ('ret', 'int3') or n >= end:
            break
    if len(out) < 8:
        return None
    return hashlib.sha1(bytes(out)).hexdigest()


o = pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image()
q = pefile.PE(str(H / 'run/RobloxQT.exe'), fast_load=True).get_memory_mapped_image()
ff = sorted(int(a, 16) for a in json.load(open(ROOT / 'work/native-client/layout/function-files.json')))
stubs, real = [], []
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and p[0].startswith('0001:'):
        try:
            v = int(p[2], 16)
        except ValueError:
            continue
        if 'stubs' in p[-1]:
            m = re.fullmatch(r'func_([0-9a-f]{8})', p[1])
            if m:
                stubs.append(p[1])
        elif not p[1].startswith(('__', '$', '??_C')) and ':' not in p[-1]:
            real.append((v, p[1]))
real.sort()
addrs = [v for v, _ in real]
qidx = collections.defaultdict(set)
for i, (v, n) in enumerate(real):
    nx = addrs[i + 1] if i + 1 < len(addrs) else v + 0x100
    if nx == v:
        continue
    s = sig(q, v, 0x400000, 0x3000000, nx)
    if s:
        qidx[s].add((v, n))
import bisect
al = {}
for s_ in stubs:
    x = int(s_[5:], 16)
    i = bisect.bisect_right(ff, x)
    nx = ff[i] if i < len(ff) else x + 0x100
    s = sig(o, x, 0x400000, 0x9a0000, nx)
    c = qidx.get(s, set()) if s else set()
    if len({v for v, _ in c}) == 1:
        al[s_] = sorted(c)[0][1]
f = H / 'aliases_bytealias.txt'
# re-verify kept lines: the file was grow-only and a target name can later move to other code (func_00773710 =
# XTP InplaceEdit::SetValue stayed bound to ~thread_resource_error -> property-grid edit crash). Keep an old line only
# when the original's signature still equals the signature of the code now under that name.
qsig = {}
for i, (v, n) in enumerate(real):
    nx = addrs[i + 1] if i + 1 < len(addrs) else v + 0x100
    j = i + 1
    while nx == v and j < len(addrs):   # folded names share an address: the body ends at the next distinct address
        nx = addrs[j]; j += 1
    qsig.setdefault(n, sig(q, v, 0x400000, 0x3000000, nx))
stale = []
if f.exists():
    for l in f.read_text().splitlines():
        if '=' in l:
            k, v = l.split('=', 1)
            x = int(k[5:], 16)
            i = bisect.bisect_right(ff, x)
            so = sig(o, x, 0x400000, 0x9a0000, ff[i] if i < len(ff) else x + 0x100)
            if v in qsig and so and qsig[v] and qsig[v] != so:
                stale.append(l); al.pop(k, None); continue
            al.setdefault(k, v)
if stale:
    print('bytealias: dropped %d stale lines: %s' % (len(stale), stale))
f.write_text(''.join('%s=%s\n' % kv for kv in sorted(al.items())))
print('bytealias: func_ stubs %d, bound to our identical code: %d (e.g. %s)' % (len(stubs), len(al), sorted(al.items())[:3]))
