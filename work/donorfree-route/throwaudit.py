"""python throwaudit.py [EXE MAP]: static audit of every C++ throw descriptor (__TI* ThrowInfo -> __CTA* catchable-type
array -> __CT* catchable types -> ??_R0 type descriptors) in our link. The exception dispatcher walks this chain to
match catch clauses; a pointer into garbage / a byte-copy placeholder / a type descriptor without its ".?A" name makes
msvcr90 fault mid-dispatch (the 2.4 s crash: AV in msvcr90 under __ehhandler$??1Sentry, then a jump to 0).
Writes auto/throwaudit.json. Read-only, seconds."""
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
inimg = lambda v: b <= v < b + len(img) - 16
u32 = lambda v: struct.unpack_from('<I', img, v - b)[0]
inv, ti, owner = {}, [], {}
for l in open(mp, errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        try:
            a = int(p[2], 16)
        except ValueError:
            continue
        inv.setdefault(a, p[1]); owner[p[1]] = p[-1]
        if p[1].startswith('__TI'):
            ti.append((p[1], a))


def tdname(t):
    if not inimg(t):
        return None
    raw = bytes(img[t - b + 8:t - b + 120]).split(b'\0', 1)[0]
    return raw.decode('latin-1') if raw.startswith(b'.?A') or raw.startswith(b'.PA') or raw.startswith(b'.H') or raw.startswith(b'.?') else None


bad = {}
for n, a in ti:
    issues = []
    attrs, unwind, fwd, cta = struct.unpack_from('<IIII', img, a - b)
    if unwind and not iscode(unwind):
        issues.append('pmfnUnwind %08x (%s) not code' % (unwind, inv.get(unwind, '?')[:40]))
    if not inimg(cta):
        issues.append('CTA %08x outside image' % cta)
    else:
        cnt = u32(cta)
        if not 0 < cnt < 32:
            issues.append('CTA %s count %d' % (inv.get(cta, '?')[:40], cnt))
        else:
            for i in range(cnt):
                ct = u32(cta + 4 + 4 * i)
                if not inimg(ct):
                    issues.append('CT[%d] %08x outside image' % (i, ct)); continue
                props, ptype = struct.unpack_from('<II', img, ct - b)
                copyf = u32(ct + 24)
                if tdname(ptype) is None:
                    issues.append('CT[%d] %s type descriptor %08x (%s) has no type name' % (i, inv.get(ct, '?')[:30], ptype, inv.get(ptype, '?')[:40]))
                if copyf and not iscode(copyf):
                    issues.append('CT[%d] copy ctor %08x (%s) not code' % (i, copyf, inv.get(copyf, '?')[:40]))
    if issues:
        bad[n] = dict(owner=owner.get(n), issues=issues)
(H / 'auto/throwaudit.json').write_text(json.dumps(bad, indent=1))
print('throw descriptors: %d, broken: %d (auto/throwaudit.json)' % (len(ti), len(bad)))
for n, v in list(bad.items())[:20]:
    print('  %-55s [%s] %s' % (n[:55], (v['owner'] or '')[:22], '; '.join(v['issues'][:2])[:120]))
