"""python natcallaudit.py: call-identity audit of NATIVE functions (callaudit.py covers converted ones).
A native function whose masked body equals one original function's is that function; at each rel32 call offset the
original target T and our target are compared. A native draft that declared the wrong callee (ContentProvider's
plain boost::mutex declared recursive_mutex -> calls ?do_lock@recursive_mutex where the original called
mutex::do_lock 0x594ce0) runs the wrong code: the recursive lock bumped a count past the plain mutex and corrupted the
next member (ContentProvider's content map) -> File->New crashed once recursive_mutex::do_lock was the real one.
Plan: in that native object, the callee symbol S -> func_<T> (only when every compared call to S in the object agrees
on T and the original target has real code in our link). Writes auto/natcallfix_plan.json {object path: {S: func_T}}
(grow-only); quicktest patches copies with callfix.patch."""
import collections, hashlib, json, os, re, struct, sys
from pathlib import Path
import capstone, pefile
H = Path(__file__).parent
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
q = pefile.PE(str(H / 'run/RobloxQT.exe'), fast_load=True).get_memory_mapped_image()
o = pefile.PE(str(H.parents[1] / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image()
B = 0x400000


def body(img, va, nxt, lo, hi):
    code = bytes(img[va - B:va - B + min(nxt - va, 0x1800)])
    sig, calls = bytearray(), []
    for ins in md.disasm(code, va):
        raw = bytearray(ins.bytes)
        if raw[0] in (0xe8, 0xe9) and len(raw) == 5:
            if raw[0] == 0xe8:
                calls.append((ins.address - va, ins.address + 5 + struct.unpack_from('<i', raw, 1)[0]))
            raw[1:] = bytes(4)
        else:
            for k in range(len(raw) - 3):
                if lo <= struct.unpack_from('<I', raw, k)[0] < hi:
                    raw[k:k + 4] = bytes(4)
        sig += raw
        if ins.mnemonic in ('ret', 'int3'):
            break
    return (hashlib.sha1(bytes(sig)).hexdigest() if len(sig) >= 12 else None), calls


def follow(t, img):
    for _ in range(4):
        b = bytes(img[t - B:t - B + 8])
        if b[:1] == b'\xe9':
            t = t + 5 + struct.unpack_from('<i', b, 1)[0]; continue
        break
    return t


ff = sorted(int(a, 16) for a in json.load(open(H.parents[0] / 'native-client/layout/function-files.json')))
osig = collections.defaultdict(list)
for i, a in enumerate(ff):
    if 0x401000 <= a < 0x7c0000:
        s, c = body(o, a, ff[i + 1] if i + 1 < len(ff) else a + 0x200, 0x400000, 0x9a0000)
        if s:
            osig[s].append((a, c))
names, objat, rows, real = {}, {}, [], set()
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        try:
            v = int(p[2], 16)
        except ValueError:
            continue
        if not v:
            continue
        names.setdefault(v, p[1]); objat.setdefault(v, p[-1])
        if 'stubs' not in p[-1]:
            real.add(p[1])
        if p[0].startswith('0001:'):
            rows.append((v, p[1], p[-1]))
rows.sort()
starts = [v for v, _, _ in rows]
rsp = {}
for l in open(H / 'linkexp/qt.rsp', errors='replace'):
    pth = l.strip().strip('"')
    if pth.lower().endswith('.obj'):
        rsp.setdefault(Path(pth).name, []).append(pth)
votes = collections.defaultdict(lambda: collections.defaultdict(set))   # obj -> S -> {T or None}
nfun = nflag = 0
for i, (v, n, ob) in enumerate(rows):
    if re.fullmatch(r'(?:ca_|cf_|dr_)?[0-9a-f]{8}\.obj', ob) or 'stubs' in ob or ':' in ob or n.startswith(('__', '$')):
        continue
    if i and starts[i - 1] == v:
        continue
    nx = starts[i + 1] if i + 1 < len(starts) else v + 0x200
    s, qc = body(q, v, nx, 0x400000, 0x3000000)
    c = osig.get(s) if s else None
    if not c or len(c) != 1:
        continue
    nfun += 1
    oa, oc = c[0]
    oc = dict(oc)
    for off, tq in qc:
        to = oc.get(off)
        if to is None or not 0x401000 <= to < 0x7c0000:
            continue
        S = names.get(tq)
        if not S or not S.startswith('?'):
            continue
        fo, fq = follow(to, o), follow(tq, q)
        same = sum(x == y for x, y in zip(o[fo - B:fo - B + 24], q[fq - B:fq - B + 24])) >= 21
        T = None if same else 'func_%08x' % fo
        if T:   # proof: our S body IS another original function (do_lock -> 0x563090); a merely different build of the
            # same function (native G3D alignedFree vs 2008 codegen) stays: retargeting free alone split malloc/free
            j = __import__('bisect').bisect_left(starts, fq)
            sq = body(q, fq, starts[j + 1] if j + 1 < len(starts) and starts[j] == fq else fq + 0x200, 0x400000, 0x3000000)[0]
            other = [a_ for a_, _ in osig.get(sq, [])] if sq else []
            if not other or fo in other:
                T = 'skip'
        if T and T not in real:
            T = 'skip'   # no real code for the original target in our link: nothing better to bind
        votes[ob][S].add(T)
        nflag += T not in (None, 'skip')
def _base(ob):   # map shows patched copies (ca_ from callfix/natcallfix, nx_ from natext): key by the original name
    while ob[:3] in ('ca_', 'nx_'):
        ob = ob[3:]
    return ob


def proof(S, T):   # S's body (by name in our link) is an original function other than T
    v = syms_by.get(S)
    if not v:
        return False
    j = __import__('bisect').bisect_left(starts, v)
    sq = body(q, v, starts[j + 1] if j + 1 < len(starts) and starts[j] == v else v + 0x200, 0x400000, 0x3000000)[0]
    other = [a_ for a_, _ in osig.get(sq, [])] if sq else []
    return bool(other) and int(T[5:], 16) not in other


syms_by = {n_: v_ for v_, n_, _ in rows}
plan = {}
for ob, d in votes.items():
    for S, ts in d.items():
        if len(ts) == 1 and next(iter(ts)) not in (None, 'skip'):
            plan.setdefault(_base(ob), {})[S] = next(iter(ts))
pf = H / 'auto/natcallfix_plan.json'   # grow-only (a fixed call leaves the audit), every entry re-proven each run
for k, v in (json.loads(pf.read_text()) if pf.exists() else {}).items():
    for S, T in v.items():
        plan.setdefault(_base(Path(k).name), {}).setdefault(S, T)
plan = {k: {S: T for S, T in v.items() if proof(S, T)} for k, v in plan.items()}
_cnt = collections.Counter(_base(n_) for n_ in rsp for _ in rsp[n_])
plan = {k: v for k, v in plan.items() if v and _cnt.get(k) == 1}   # candidate.obj names many objects: never ambiguous
pf.write_text(json.dumps(plan, indent=0))
print('natcallaudit: native functions matched to the original %d, calls bound to different code %d; plan %d objects %d renames'
      % (nfun, nflag, len(plan), sum(map(len, plan.values()))))
for k, v in list(plan.items())[:10]:
    print('  ', Path(k).name[:60], list(v.items())[:2])
