"""python ehaudit.py [EXE MAP]: static audit of every C++ exception-handling table (__ehfuncinfo$...) in our link.
A throw unwinds through FuncInfo -> unwind map (cleanup funclets) and try-block map -> catch handlers; a NULL catch
handler or a funclet/handler pointing outside code jumps to garbage during unwinding (the 2.4 s `exception at
00000000` with e06d7363 in edi: a throw from Log::writeEntry unwinding into a null). Lists every bad table at once.
Writes auto/ehaudit.json. Read-only, seconds."""
import json, struct, sys
from pathlib import Path
import pefile
H = Path(__file__).parent
exe = sys.argv[1] if len(sys.argv) > 1 else str(H / 'run/RobloxQT.exe')
mp = sys.argv[2] if len(sys.argv) > 2 else str(H / 'linkexp/qt.map')
pe = pefile.PE(exe, fast_load=True)
img = pe.get_memory_mapped_image(); b = pe.OPTIONAL_HEADER.ImageBase
code = [(b + s.VirtualAddress, b + s.VirtualAddress + s.Misc_VirtualSize) for s in pe.sections if s.Characteristics & 0x20000000]
iscode = lambda v: any(lo <= v < hi for lo, hi in code)
inimg = lambda v: b <= v < b + len(img)
rd = lambda v, n=4: struct.unpack_from('<I', img, v - b)[0] if inimg(v) else None
syms, owner = [], {}
for l in open(mp, errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0] and p[1].startswith('__ehfuncinfo$'):
        try:
            syms.append((p[1], int(p[2], 16))); owner[p[1]] = p[-1]
        except ValueError:
            pass
bad = {}
for n, a in syms:
    magic = rd(a)
    if magic not in (0x19930520, 0x19930521, 0x19930522):
        bad[n] = ['bad magic %s' % (hex(magic) if magic is not None else None)]; continue
    max_state, p_unwind, n_try, p_try = struct.unpack_from('<IIII', img, a - b + 4)
    issues = []
    if max_state and not inimg(p_unwind):
        issues.append('unwind map %08x outside image' % p_unwind)
    else:
        for i in range(min(max_state, 512)):
            to_state, action = struct.unpack_from('<iI', img, p_unwind - b + 8 * i)
            if action and not iscode(action):
                issues.append('unwind[%d] action %08x not code' % (i, action))
    if n_try and not inimg(p_try):
        issues.append('try map %08x outside image' % p_try)
    else:
        for t in range(min(n_try, 128)):
            lo, hi, catch_hi, n_catch, p_handlers = struct.unpack_from('<iiiiI', img, p_try - b + 20 * t)
            if n_catch and not inimg(p_handlers):
                issues.append('try[%d] handler array %08x outside image' % (t, p_handlers)); continue
            for h in range(min(n_catch, 32)):
                adj, ptype, disp, handler = struct.unpack_from('<IIiI', img, p_handlers - b + 16 * h)
                if not handler or not iscode(handler):
                    issues.append('try[%d] catch[%d] handler %08x %s' % (t, h, handler, 'NULL' if not handler else 'not code'))
    if issues:
        bad[n] = issues
(H / 'auto/ehaudit.json').write_text(json.dumps({n: dict(owner=owner[n], issues=v) for n, v in bad.items()}, indent=1))
print('EH tables: %d, with bad handler/funclet pointers: %d (auto/ehaudit.json)' % (len(syms), len(bad)))
for n, v in list(bad.items())[:25]:
    print('  %-70s [%s] %s' % (n[:70], owner[n][:22], '; '.join(v[:2])[:110]))
