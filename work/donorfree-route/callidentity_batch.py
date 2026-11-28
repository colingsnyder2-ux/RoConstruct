"""Diagnostic batch finder for misbound call identities (read-only).

callaudit.py only flags a mismatch when OUR target has a '?' (C++) name, so a converted
body whose analog external is a CRT/MFC C name (_clearerr_s -> MSVCRT) escapes the audit
even when the original target is a real Roblox function.  This script compares every
converted main function's rel32 calls against the original, then for each mismatch uses
work/2008-06/identity-registry.json to name the ORIGINAL target and checks that our link
defines that exact name as real code.  It writes candidates for review; it never patches.

python callidentity_batch.py [EXE [MAP]]
"""
import bisect, collections, json, re, struct, sys
from pathlib import Path
import pefile

H = Path(__file__).parent
exe = sys.argv[1] if len(sys.argv) > 1 else str(H / 'run/RobloxQT.exe')
mp = sys.argv[2] if len(sys.argv) > 2 else str(H / 'linkexp/qt.map')
orig_exe = str(H.parents[1] / 'clients/2008-06/Roblox.exe')
registry = json.load(open(H.parents[1] / 'work/2008-06/identity-registry.json'))
B = 0x400000

q = pefile.PE(exe, fast_load=True).get_memory_mapped_image()
o = pefile.PE(orig_exe, fast_load=True).get_memory_mapped_image()

syms, at, objof = {}, collections.defaultdict(list), {}
for line in open(mp, errors='replace'):
    p = line.split()
    if len(p) >= 4 and ':' in p[0]:
        try:
            v = int(p[2], 16)
        except ValueError:
            continue
        if v:
            syms.setdefault(p[1], v)
            at[v].append(p[1])
            objof[p[1]] = p[-1]

rr = json.loads((H / 'renamed/rename.json').read_text())
main = {}
for line in open(mp, errors='replace'):
    p = line.split()
    if len(p) >= 4 and ':' in p[0] and len(p[-1]) == 12 and p[-1].endswith('.obj'):
        a8 = p[-1][:8]
        if p[1] in ('func_' + a8, (rr.get(a8) or {}).get('symbol')):
            try:
                main.setdefault(a8, int(p[2], 16))
            except ValueError:
                pass

# name -> original addresses from the registry (names covering >1 address are ambiguous)
name_addrs = collections.defaultdict(set)
for a, v in registry.items():
    if v and v.get('name'):
        name_addrs[v['name']].add(int(a, 16))


def real_def(name):
    """Our linked definition must be non-stub code."""
    return syms.get(name, 0) and 'stubs' not in objof.get(name, 'stubs')


def imports(path):
    pe = pefile.PE(path, fast_load=True)
    pe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_IMPORT']])
    return {i.address: (d.dll.decode().lower(), i.name.decode() if i.name else i.ordinal)
            for d in pe.DIRECTORY_ENTRY_IMPORT for i in d.imports}


imp_o, imp_q = imports(orig_exe), imports(exe)


def follow(t, img):
    for _ in range(4):
        b = img[t - B:t - B + 8]
        if len(b) < 8:
            break
        if b[:2] == b'\xff\x25':
            return ('imp', struct.unpack_from('<I', b, 2)[0])
        if b[0] == 0xe9:
            t = t + 5 + struct.unpack_from('<i', b, 1)[0]
            continue
        break
    return ('code', t)


def same_code(to, tq):
    fo, fq = follow(to, o), follow(tq, q)
    if fo[0] != fq[0]:
        return False
    if fo[0] == 'imp':
        return imp_o.get(fo[1]) is not None and imp_o.get(fo[1]) == imp_q.get(fq[1])
    bo = o[fo[1] - B:fo[1] - B + 24]
    bq = q[fq[1] - B:fq[1] - B + 24]
    return sum(x == y for x, y in zip(bo, bq)) >= 21


import capstone
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
candidates = collections.defaultdict(dict)
evidence = collections.defaultdict(list)
for a8, A in sorted(main.items()):
    X = int(a8, 16)
    end = min(0x400, len(o) - (X - B))
    oi = [(i.address - X, i.mnemonic) for i in md.disasm(bytes(o[X - B:X - B + end]), X)]
    qi = [(i.address - A, i.mnemonic) for i in md.disasm(bytes(q[A - B:A - B + end]), A)]
    starts = set()
    for (ko, mo), (kq, mq) in zip(oi, qi):
        if ko != kq or mo != mq:
            break
        starts.add(ko)
    k = 0
    while k < end - 5:
        if k in starts and q[A - B + k] == 0xe8 and o[X - B + k] == 0xe8:
            to = X + k + 5 + struct.unpack_from('<i', o, X - B + k + 1)[0]
            tq = A + k + 5 + struct.unpack_from('<i', q, A - B + k + 1)[0]
            names = at.get(tq, [])
            if names and not same_code(to, tq):
                # The original target's registry name is the call identity we want.
                reg = registry.get('%08x' % to) or {}
                want = reg.get('name')
                # High-confidence batch class only: original calls a C++/ATL function; our converted body
                # accidentally calls an imported C/CRT symbol instead.  Legitimate import-to-import calls
                # and func_<T> stubs are handled by callaudit.py and are deliberately not listed here.
                imported = {n for n in names if ':' in objof.get(n, '') or n.startswith('_')}
                if (want and want.startswith('?') and len(name_addrs[want]) == 1
                        and real_def(want) and follow(to, o)[0] == 'code'
                        and follow(tq, q)[0] == 'imp' and imported):
                    for name in imported:
                        candidates[a8 + '.obj'][name] = want
                        evidence[a8 + '.obj'].append([hex(k), '%08x' % to, name, want])
            k += 5
            continue
        k += 1

out = H / 'auto/callidentity_candidates.json'
out.write_text(json.dumps(candidates, indent=1))
ev = H / 'auto/callidentity_evidence.json'
ev.write_text(json.dumps(evidence, indent=1))
print('callidentity candidates: %d objects, %d symbol renames' % (
    len(candidates), sum(len(v) for v in candidates.values())))
for obj, m in list(candidates.items())[:20]:
    print(' ', obj, m)
print('wrote', out, ev)
