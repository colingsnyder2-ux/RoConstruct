"""python bindcheck.py [EXE MAP]: whole-program binding check. Every name our exe resolves that CLAIMS an original
function address A -- func_<A>, a registry name unique to A, a converted object's rename symbol -- must land on code
that IS A. Each bug class of 2026-11-25 was one way of breaking that (folded create<Team> for create<GameSettings>,
boost mutex::do_lock posing as recursive_mutex::do_lock, a SpawnLocation draft defining func_00490c30, ...).
Verdict per (name, A): 'exact' (masked bodies equal), 'similar' (mnemonic ratio >= 0.6: a rebuild of the same
function), 'WRONG' (ratio < 0.6, or same shape but a different constructor/class callee), 'stub' (return-0 stub).
Writes auto/bindcheck.json {wrong: [...], stub_reached: [...]} and prints counts by owning object kind."""
import bisect, collections, difflib, hashlib, json, re, struct, sys
from pathlib import Path
import capstone, pefile
H = Path(__file__).parent
exe = sys.argv[1] if len(sys.argv) > 1 else str(H / 'run/RobloxQT.exe')
mp = sys.argv[2] if len(sys.argv) > 2 else str(H / 'linkexp/qt.map')
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
q = pefile.PE(exe, fast_load=True).get_memory_mapped_image()
o = pefile.PE(str(H.parents[1] / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image()
B = 0x400000
reg = json.load(open(H.parents[0] / '2008-06/identity-registry.json'))
rr = json.loads((H / 'renamed/rename.json').read_text())
regaddr = collections.defaultdict(set)
for a, v in reg.items():
    n = (v or {}).get('name') or ''
    if n.startswith('?') and 0x401000 <= int(a, 16) < 0x7c0000:
        regaddr[n].add(int(a, 16))
sym, objof, starts = {}, {}, set()
for l in open(mp, errors='replace'):
    p = l.split()
    if len(p) >= 4 and p[0].startswith('0001:'):
        try:
            v = int(p[2], 16)
        except ValueError:
            continue
        sym.setdefault(p[1], v); objof.setdefault(p[1], p[-1]); starts.add(v)
starts = sorted(starts)
ff = sorted(int(a, 16) for a in json.load(open(H.parents[0] / 'native-client/layout/function-files.json')))


def insns(img, va, limit):
    out = []
    for i in md.disasm(bytes(img[va - B:va - B + limit]), va):
        out.append(i)
        if i.mnemonic in ('ret', 'int3') or len(out) > 400:
            break
    return out


def sig(ins_, lo, hi):
    s = bytearray()
    for i in ins_:
        raw = bytearray(i.bytes)
        if raw[0] in (0xe8, 0xe9) and len(raw) == 5:
            raw[1:] = bytes(4)
        else:
            for k in range(len(raw) - 3):
                if lo <= struct.unpack_from('<I', raw, k)[0] < hi:
                    raw[k:k + 4] = bytes(4)
        s += raw
    return hashlib.sha1(bytes(s)).digest()


qn = {}
for n, v in sym.items():
    qn.setdefault(v, n)


def ctor_names(ins_, img, mine):
    out = []
    for i in ins_:
        if i.mnemonic == 'call' and i.op_str.startswith('0x'):
            t = int(i.op_str, 16)
            n = qn.get(t, '') if mine else ((reg.get('%08x' % t) or {}).get('name') or '')
            m = re.match(r'^\?\?0(\w+)@', n)
            out.append(m.group(1) if m else None)
    return out


osig = collections.defaultdict(list)   # masked original bodies -> addresses (proof: our code IS another function)
for i_, a_ in enumerate(ff):
    if 0x401000 <= a_ < 0x7c0000:
        oi_ = insns(o, a_, min((ff[i_ + 1] if i_ + 1 < len(ff) else a_ + 0x200) - a_, 0x1800))
        if len(oi_) >= 6 and oi_[0].mnemonic != 'jmp':
            osig[sig(oi_, 0x400000, 0x9a0000)].append(a_)
claims = {}   # name -> set(A)
for n in sym:
    m = re.fullmatch(r'func_([0-9a-f]{8})', n)
    if m:
        claims.setdefault(n, set()).add(int(m.group(1), 16))
    elif n in regaddr and len(regaddr[n]) == 1:
        claims.setdefault(n, set()).update(regaddr[n])
for a, x in rr.items():
    s = x.get('symbol')
    if x.get('status') == 'renamed' and s in sym:
        claims.setdefault(s, set()).add(int(a, 16))
ours_means = collections.defaultdict(set)   # our address -> original addresses the names there claim (reccmp-style entity)
for n_, As_ in claims.items():
    ours_means[sym[n_]] |= As_


def callee_diff(qi, oi):   # reccmp ParseAsm idea: compare call targets as ENTITIES (original address), not bytes
    qc = [int(i.op_str, 16) for i in qi if i.mnemonic == 'call' and i.op_str.startswith('0x')]
    oc = [int(i.op_str, 16) for i in oi if i.mnemonic == 'call' and i.op_str.startswith('0x')]
    bad = []
    for k, (tq, to) in enumerate(zip(qc, oc)):
        m = ours_means.get(tq)
        if m and to not in m and 0x401000 <= to < 0x7c0000:
            fo = to
            if bytes(o[to - B:to - B + 1]) == b'é':   # through a jmp thunk
                fo = to + 5 + struct.unpack_from('<i', o, to - B + 1)[0]
            if fo not in m:
                bad.append((k, '%08x' % to, qn.get(tq, '%08x' % tq)[:60]))
    return bad


res = collections.Counter()
cdiff = []
wrong, stubs = [], []
seen_pair = set()
for n, As in claims.items():
    v = sym[n]; ob = objof[n]
    if 'stubs' in ob:
        res['stub'] += len(As); stubs += [(n, '%08x' % A) for A in As]; continue
    if ':' in ob:   # import / library thunk
        continue
    qi = insns(q, v, 0x1800)
    for A in As:
        if not 0x401000 <= A < 0x7c0000 or (v, A) in seen_pair:
            continue
        seen_pair.add((v, A))
        oi = insns(o, A, 0x1800)
        if sig(qi, 0x400000, 0x3000000) == sig(oi, 0x400000, 0x9a0000):
            # same shape: a different constructor/class callee still means a different function
            cq, co = ctor_names(qi, q, True), ctor_names(oi, o, False)
            if any(x and y and x != y for x, y in zip(cq, co)) and (oi and any(i.mnemonic == 'call' and 'malloc' in str((reg.get('%08x' % int(i.op_str, 16)) or {}).get('name', '')) for i in oi if i.op_str.startswith('0x')) or 'create' in n or re.search(r'create', (reg.get('%08x' % A) or {}).get('name') or '')):   # factory paths only: elsewhere registry ctor names alias (GuidRegistryMutex = recursive_mutex)
                res['WRONG'] += 1; wrong.append([n, '%08x' % A, ob, 'ctor %s' % [(x, y) for x, y in zip(cq, co) if x and y and x != y][:2]])
            else:
                res['exact'] += 1
                cd = callee_diff(qi, oi)
                if cd:
                    res['CALLEE'] += 1; cdiff.append([n, '%08x' % A, ob, cd[:3]])
            continue
        if oi and oi[0].mnemonic == 'jmp':   # original is an import/jump thunk: compared elsewhere
            res['thunk'] += 1; continue
        other = osig.get(sig(qi, 0x400000, 0x3000000), [])
        if other and A not in other:
            res['PROVEN'] += 1; wrong.append([n, '%08x' % A, ob, 'PROVEN = %s' % ','.join('%08x' % x for x in other[:3])]); continue
        if len(oi) < 20 or len(qi) < 20:   # tiny inlined helpers: ratio is noise
            res['short'] += 1; continue
        r = difflib.SequenceMatcher(None, [i.mnemonic for i in oi], [i.mnemonic for i in qi], autojunk=False).ratio()
        if r >= 0.6:
            res['similar'] += 1
            cd = callee_diff(qi, oi)
            if cd:
                res['CALLEE'] += 1; cdiff.append([n, '%08x' % A, ob, cd[:3]])
        else:
            res['WRONG'] += 1; wrong.append([n, '%08x' % A, ob, 'ratio %.2f' % r])
kind = lambda ob: 'converted' if re.fullmatch(r'(?:(?:ca|cf|dr|nx|ni)_)*[0-9a-f]{8}\.obj', ob) else 'native/draft'
(H / 'auto/bindcheck.json').write_text(json.dumps({'wrong': wrong, 'callee': cdiff, 'stubs': stubs, 'counts': res}, indent=0))
print('CALLEE entity mismatches (function right, a callee bound to another original):', len(cdiff))
for c_ in cdiff[:20]:
    print('   ', c_[1], c_[0][:50], '|', c_[2][:30], '|', c_[3][:2])
print('bindcheck: %s' % dict(res))
print('  WRONG by owner:', collections.Counter(kind(w[2]) for w in wrong))
wrong.sort(key=lambda w: not w[3].startswith(('PROVEN', 'ctor')))
for w in wrong[:40]:
    print('   ', w[1], w[0][:70], '|', w[2][:45], '|', w[3])
