"""python foldaudit.py: converted code bound to ONE native data symbol from TWO OR MORE distinct original data addresses.
The registry folds identical-code functions under one name (doDeclare<sDecal> for every Name::declare helper), so
rename bound each converted copy's function-local static (?n@?1??doDeclare<sDecal>...) to the same native symbol:
Name "NetworkClient" overwrote "Decal", Client::clientIsPresent found a service and Run stayed disabled.
Walks every converted function (renamed/<addr>.obj) against its original body, pairs original data address A with
our referenced symbol S at the same operand, and reports S reached from several A.
Writes auto/foldaudit.json {symbol: [orig addrs]} and auto/foldaudit_refs.json [[object, symbol, orig addr]]."""
import collections, json, re, struct
from pathlib import Path
import pefile
H = Path(__file__).parent
import capstone, hashlib
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
q = pefile.PE(str(H / 'run/RobloxQT.exe'), fast_load=True).get_memory_mapped_image()
o = pefile.PE(str(H.parents[1] / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image()
B = 0x400000


class nb:
    @staticmethod
    def body(img, va, nxt, lo, hi):   # same masking as natdata.body
        code = bytes(img[va - B:va - B + min(nxt - va, 0x1800)])
        sig, refs = bytearray(), []
        for ins in md.disasm(code, va):
            raw = bytearray(ins.bytes)
            if raw[0] in (0xe8, 0xe9) and len(raw) == 5:
                raw[1:] = b'\0\0\0\0'
            else:
                for k in range(len(raw) - 3):
                    v = struct.unpack_from('<I', raw, k)[0]
                    if lo <= v < hi:
                        refs.append((ins.address - va, k, v)); raw[k:k + 4] = b'\0\0\0\0'
            sig += raw
            if ins.mnemonic in ('ret', 'int3'):
                break
        return (hashlib.sha1(bytes(sig)).hexdigest() if len(sig) >= 12 else None), refs
syms, objat, rows = {}, {}, []
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        try:
            v = int(p[2], 16)
        except ValueError:
            continue
        if not v:
            continue
        syms.setdefault(v, p[1]); objat.setdefault(v, p[-1])
        if p[0].startswith('0001:'):
            rows.append((v, p[1], p[-1]))
rows.sort()
starts = [v for v, _, _ in rows]
sv = sorted(syms)
pair = collections.defaultdict(set)
refs = []
for i, (v, n, ob) in enumerate(rows):
    m = re.fullmatch(r'(?:ca_)?([0-9a-f]{8})\.obj', ob)
    if not m or (i and starts[i - 1] == v):
        continue
    oa = int(m.group(1), 16)
    nx = starts[i + 1] if i + 1 < len(starts) else v + 0x200
    if nx == v or not 0x401000 <= oa < 0x7c0000:
        continue
    s1, r1 = nb.body(q, v, nx, 0x400000, 0x3000000)
    s2, r2 = nb.body(o, oa, oa + min(nx - v + 0x40, 0x1800), 0x400000, 0x9a0000)
    if not s1 or s1 != s2 or len(r1) != len(r2):
        continue
    for (io, k, ov), (iq, kq, qv) in zip(r2, r1):
        if io != iq or k != kq or not 0x7c0000 <= ov < 0x9a0000:
            continue
        nm = syms.get(qv)
        if nm and not nm.startswith(('dat_', 'roc_str_', '??_C', '__real', '__xmm', '??_7', '??_R')):
            pair[(nm, qv)].add(ov); refs.append([ob, nm, '%08x' % ov, '%08x' % qv])
bad = {'%s@%08x' % k: sorted('%08x' % a for a in v) for k, v in pair.items() if len(v) > 1}
(H / 'auto/foldaudit.json').write_text(json.dumps(bad, indent=0))
(H / 'auto/foldaudit_refs.json').write_text(json.dumps([r for r in refs if '%s@%s' % (r[1], r[3]) in bad], indent=0))
print('foldaudit: native data symbols reached from >1 original address: %d (refs %d)' % (len(bad), sum(len(v) for v in bad.values())))
for k, v in sorted(bad.items(), key=lambda kv: -len(kv[1]))[:8]:
    print('  %3d %s' % (len(v), k[:110]))

# plan: in each converted object, a conflicting DATA symbol (original .rdata/.data) reached from an address that is
# not its registry-named owner becomes dat_<orig> (callfix.patch rename, merged by quicktest like datafix)
reg = json.load(open(H.parents[0] / '2008-06/identity-registry.json'))
plan, clash = collections.defaultdict(dict), set()
for ob, nm, ov, qv in json.loads((H / 'auto/foldaudit_refs.json').read_text()):
    if int(ov, 16) < 0x802000 or (reg.get(ov) or {}).get('name') == nm:
        continue
    new = 'dat_' + ov
    if plan[ob].get(nm, new) != new:
        clash.add((ob, nm))
    plan[ob][nm] = new
for ob, nm in clash:
    plan[ob].pop(nm, None)
plan = {k: v for k, v in plan.items() if v}
_pf = H / 'auto/foldfix_plan.json'   # grow-only: fixed refs leave the audit on the next link
for k, v in (json.loads(_pf.read_text()) if _pf.exists() else {}).items():
    plan.setdefault(k, {}); plan[k] = {**v, **plan[k]}
(H / 'auto/foldfix_plan.json').write_text(json.dumps(plan, indent=0))
print('foldfix plan: %d objects, %d renames (skipped %d same-object clashes)' % (len(plan), sum(map(len, plan.values())), len(clash)))
