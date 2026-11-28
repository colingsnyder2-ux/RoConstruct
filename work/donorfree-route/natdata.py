"""python natdata.py: bind dat_<A> placeholders to the NATIVE global that owns the same state. XTP's hook-manager
singleton lived twice: native code used ?s_managerInstance@?1??XTPHookManager@@, converted code the placeholder
dat_0097ed78 (never constructed) -> the Untitled frame's hook was looked up in the other map -> HookWndProc returned 0
for WM_PAINT -> endless WM_PAINT, 100% CPU, WM_TIMER starved (empty Explorer), modal dialogs never shown.
For every function in a NATIVE object of our link whose masked body (rel32 + image-address dwords zeroed) equals a
unique ORIGINAL function's, the two bodies are walked instruction by instruction: an original data address A and our
native symbol S at the same operand pair A -> S. Every dat_<A> our link only has as a placeholder (stub) gets
alias dat_<A>=S when the pairing is unique. Writes aliases_natdata.txt (grow-only)."""
import bisect, collections, hashlib, json, re, struct
from pathlib import Path
import capstone, pefile
H = Path(__file__).parent
ROOT = H.parents[1]
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
o = pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image()
import os as _os, sys as _sys
_EXE = _sys.argv[1] if len(_sys.argv) > 2 else str(H / 'run/RobloxQT.exe')   # natdata.py [EXE MAP] (recover from an older good build)
_MAP = _sys.argv[2] if len(_sys.argv) > 2 else str(H / 'linkexp/qt.map')
q = pefile.PE(_EXE, fast_load=True).get_memory_mapped_image()
B = 0x400000


def body(img, va, nxt, lo, hi):
    """(signature, [(insn offset, dword offset in insn, value)] image-address dwords) up to the first ret/int3"""
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


ff = sorted(int(a, 16) for a in json.load(open(ROOT / 'work/native-client/layout/function-files.json')))
reg = json.load(open(ROOT / 'work/2008-06/identity-registry.json'))
osig = collections.defaultdict(list)
for i, a in enumerate(ff):
    if 0x401000 <= a < 0x7c0000:
        s, r = body(o, a, ff[i + 1] if i + 1 < len(ff) else a + 0x200, 0x400000, 0x9a0000)
        if s:
            osig[s].append((a, r))
syms, objat, real = {}, {}, set()
rows = []
for l in open(_MAP, errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        try:
            v = int(p[2], 16)
        except ValueError:
            continue
        if not v:
            continue
        syms.setdefault(v, p[1]); objat.setdefault(v, p[-1])
        if 'stubs' not in p[-1]:
            real.add(p[1])
        if p[0].startswith('0001:'):
            rows.append((v, p[1], p[-1]))
rows.sort()
starts = [v for v, _, _ in rows]
pair = collections.defaultdict(collections.Counter)
nfun = 0
for i, (v, n, ob) in enumerate(rows):
    if re.fullmatch(r'(?:ca_)?[0-9a-f]{8}\.obj', ob) or 'stubs' in ob or ':' in ob or n.startswith(('__', '$')):
        continue   # natives (and native drafts) only
    nx = starts[i + 1] if i + 1 < len(starts) else v + 0x200
    if nx == v:
        continue
    s, r = body(q, v, nx, 0x400000, 0x3000000)
    c = osig.get(s) if s else None
    if c and len(c) > 1:   # same shape (singleton getters): the candidate whose callees carry our callees' names
        qcalls = [struct.unpack_from('<i', q, v - B + io + 1)[0] + v + io + 5 for io, k_, _ in []] if False else None
        best, score = [], -1
        qc = [(ins.address - v, int(ins.op_str, 16)) for ins in md.disasm(bytes(q[v - B:v - B + min(nx - v, 0x1800)]), v)
              if ins.mnemonic == 'call' and ins.op_str.startswith('0x')]
        for cand in c:
            oc = [(ins.address - cand[0], int(ins.op_str, 16)) for ins in md.disasm(bytes(o[cand[0] - B:cand[0] - B + 0x400]), cand[0])
                  if ins.mnemonic == 'call' and ins.op_str.startswith('0x')][:len(qc)]
            sc = sum(1 for (a1, t1), (a2, t2) in zip(oc, qc) if a1 == a2 and ((reg.get('%08x' % t1) or {}).get('name') == syms.get(t2)
                     or (0x401000 <= t1 < 0x7c0000 and body(o, t1, t1 + 0x400, 0x400000, 0x9a0000)[0] == body(q, t2, t2 + 0x400, 0x400000, 0x3000000)[0])))
            if sc > score:
                best, score = [cand], sc
            elif sc == score:
                best.append(cand)
        c = best if score > 0 else c
    if not c or len(c) != 1:
        continue
    nfun += 1
    oa, orf = c[0]
    if len(orf) != len(r):
        continue
    for (io, k, ov), (iq, kq, qv) in zip(orf, r):
        if io != iq or k != kq or not 0x7c0000 <= ov < 0x9a0000:
            continue
        j = bisect.bisect_right(sorted(syms), qv) - 1
        nm = syms.get(qv)
        if nm and nm in real and not nm.startswith(('dat_', 'roc_str_', '??_C', '__real', '__xmm')):
            pair['%08x' % ov][nm] += 1
stubs = {n for v, n in syms.items() if 'stubs' in objat.get(v, '')}
stubs |= {l.split()[1] for l in open(_MAP, errors='replace') if len(l.split()) >= 4 and 'stubs' in l.split()[-1]}
ndef = collections.Counter(l.split()[1] for l in open(_MAP, errors='replace') if len(l.split()) >= 4 and ':' in l.split()[0])
al = {}
for a, c in pair.items():
    # only a GLOBAL defined once: a per-object static (_whitespaces in 30 objects) cannot be aliased -> resolved to 0
    if len(c) == 1 and ('dat_' + a) not in real and ndef[next(iter(c))] == 1:
        al['dat_' + a] = next(iter(c))
# a dat_<A> whose REGISTRY name is a symbol our link defines exactly once (native class-descriptor statics
# ?foo@?1??classDescriptor@?$Described@V<C>...: converted code used dat_ copies -> each class registered 2-3 times and
# listed repeatedly in Insert Object)
for l in open(_MAP, errors='replace'):
    p_ = l.split()
    if len(p_) >= 4 and re.fullmatch(r'dat_[0-9a-f]{8}', p_[1]) and p_[1] not in real and p_[1] not in al:
        rn = (reg.get(p_[1][4:]) or {}).get('name') or ''
        if rn and ndef[rn] == 1 and rn in real and not rn.startswith('dat_'):
            al[p_[1]] = rn
af = H / 'aliases_natdata.txt'
# grow-only WITH validation (2026-11-25: recomputing from a broken build dropped the XTP hook-manager binding ->
# the 100%% CPU bug came back): keep an old entry while its target is still defined exactly once by real code;
# never a code label (__ehhandler$/funclets are not globals)
if af.exists():
    for l in af.read_text().splitlines():
        if '=' in l:
            k_, v_ = l.split('=', 1)
            if v_ in real and ndef[v_] == 1:
                al.setdefault(k_, v_)
_deny = set(json.loads((H / 'auto/natdata_deny.json').read_text())) if (H / 'auto/natdata_deny.json').exists() else set()   # bisect 11-25: statics in shared-name candidate.obj drafts
al = {k_: v_ for k_, v_ in al.items() if v_ not in _deny}
al = {k_: v_ for k_, v_ in al.items() if not v_.startswith(('__ehhandler$', '__unwindfunclet$', '__catch$', '$', '??__F', '??__E'))
      and int(k_[4:12], 16) >= 0x802000}   # data addresses only (.rdata/.data): code labels are not globals
af.write_text(''.join('%s=%s\n' % kv for kv in sorted(al.items())))
print('natdata: native functions matched to the original %d; dat_ placeholders bound to native globals %d (e.g. %s)'
      % (nfun, len(al), sorted(al.items())[:3]))
print('  dat_0097ed78 ->', al.get('dat_0097ed78'))


# alias targets that are STATIC in their object (function-local statics: ?s_managerInstance@?1??XTPHookManager@@...)
# resolve to 0 through /alternatename: record (object, name) so quicktest links a copy with that symbol made external
owners = {}
for l in open(_MAP, errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0] and p[1] in set(al.values()):
        owners[p[1]] = p[-1]
rsp = {Path(l.strip().strip('"')).name: l.strip().strip('"') for l in open(H / 'linkexp/qt.rsp', errors='replace') if l.strip().strip('"').lower().endswith('.obj')}
ext = collections.defaultdict(list)
_rspall = {}   # base name -> every path: candidate.obj names hundreds of objects (the dict above kept only the last)
for l in open(H / 'linkexp/qt.rsp', errors='replace'):
    _p0 = l.strip().strip('"')
    if _p0.lower().endswith('.obj'):
        _rspall.setdefault(Path(_p0).name, []).append(_p0)
for n, ob in owners.items():
  for path in _rspall.get(ob, []):
    try:
        d = Path(path).read_bytes()
    except OSError:
        continue
    if n.encode('latin-1') not in d:
        continue
    _, nsec, _, sp, ns, opt, _ = struct.unpack_from('<HHIIIHH', d, 0)
    st = sp + ns * 18; i = 0
    while i < ns:
        raw, val, sec, typ, cls, naux = struct.unpack_from('<8sIHHBB', d, sp + 18 * i)
        if raw[:4] == b'\0\0\0\0':
            o_ = st + struct.unpack_from('<I', raw, 4)[0]; nm = d[o_:d.index(b'\0', o_)].decode('latin-1')
        else:
            nm = raw.rstrip(b'\0').decode('latin-1')
        if nm == n and cls in (2, 3) and 0 < sec < 0xfff0 and (cls == 3 or Path(path).name.startswith('nx_')):
            ext[path].append(n)
        i += 1 + naux
_ef = H / 'auto/natdata_extern.json'   # grow-only: after one link the owner is the patched nx_ copy (already
# external), so a recompute dropped the static -> its alias resolved to address 0 next link (hook manager again)
for k_, v_ in ((json.loads(_ef.read_text()) if _ef.exists() else {}) if not __import__('os').environ.get('NATDATA_NO_EXTERN_GROW') else {}).items():
    if k_ not in ext and Path(k_).exists():
        ext[k_] = v_
    elif k_ in ext:
        ext[k_] = sorted(set(ext[k_]) | set(v_))
_ef.write_text(json.dumps(ext, indent=0))
print('natdata: alias targets that are statics in their object (made external in a patched copy): %d' % sum(len(v) for v in ext.values()))
