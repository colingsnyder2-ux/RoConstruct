"""python callaudit.py [EXE MAP]: call-identity audit of converted functions. Each converted func_<X> (object <X>.obj)
is the original's code: for every rel32 `call` at the same offset in our function and in the original at X, compare
targets. Our target is fine when its symbol is func_<T> / an analog renamed to func_<T> / a name the registry puts at T
(T = the original's target), or when the original target is a thunk / import and ours is its import thunk.
A mismatch = the analog's callee NAME bound real code of another function (func_00792440 called the real
boost::basic_regex::compare instead of the thunk 0078e6e0 -> CXTButton::SetColorFace crashed).
Writes auto/callaudit.json {func_X: [[offset, orig_target, our_symbol]]} and prints a summary."""
import bisect, collections, json, re, struct, sys
from pathlib import Path
import pefile
H = Path(__file__).parent
exe = sys.argv[1] if len(sys.argv) > 1 else str(H / 'run/RobloxQT.exe')
mp = sys.argv[2] if len(sys.argv) > 2 else str(H / 'linkexp/qt.map')
q = pefile.PE(exe, fast_load=True).get_memory_mapped_image()
o = pefile.PE(str(H.parents[1] / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image()
B = 0x400000
rg = json.load(open(H.parents[1] / 'work/2008-06/identity-registry.json'))
addr_of = collections.defaultdict(set)
for a, v in rg.items():
    if v and v.get('name'):
        addr_of[v['name']].add(int(a, 16))
# registry names proven wrong (natbody_defrename.json: the converted body at A is NOT S; native S matched another address)
_ndr_ = H / 'auto/natbody_defrename.json'
for _ob, _m in (json.loads(_ndr_.read_text()) if _ndr_.exists() else {}).items():
    for _S in _m:
        if re.fullmatch(r'[0-9a-f]{8}\.obj', _ob):
            addr_of[_S].discard(int(_ob[:8], 16))
syms, at, objof, objat = {}, collections.defaultdict(list), {}, {}
for l in open(mp, errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        try:
            v = int(p[2], 16)
        except ValueError:
            continue
        if v:
            syms.setdefault(p[1], v); at[v].append(p[1]); objof[p[1]] = p[-1]; objat.setdefault(v, p[-1])


FOLDED = {n_ for n_, s_ in addr_of.items() if len(s_) > 1}   # registry names covering several original functions


def orig_addrs(name):
    if name.startswith('func_') and len(name) == 13:
        return {int(name[5:], 16)}
    return addr_of.get(name, set())


def follow(t, img):   # through `jmp rel32` and `add/sub ecx,imm; jmp` thunks: the final code address (or import slot)
    for _ in range(4):
        b = img[t - B:t - B + 8]
        if len(b) < 8:
            break
        if b[:2] == b'\xff\x25':
            return ('imp', struct.unpack_from('<I', b, 2)[0])
        if b[0] == 0xe9:
            t = t + 5 + struct.unpack_from('<i', b, 1)[0]; continue
        break
    return ('code', t)


def imports(path):
    pe = pefile.PE(path, fast_load=True)
    pe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_IMPORT']])
    return {i.address: (d.dll.decode().lower(), i.name.decode() if i.name else i.ordinal) for d in pe.DIRECTORY_ENTRY_IMPORT for i in d.imports}


imp_o, imp_q = imports(str(H.parents[1] / 'clients/2008-06/Roblox.exe')), imports(exe)
bad = {}
n_funcs = n_calls = 0
# every converted object's main function: func_<X> or the real name rename.py gave it (SafeChat::singleton was missed)
_rr = json.loads((H / 'renamed/rename.json').read_text())
_main = {}
for l in open(mp, errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0] and len(p[-1]) == 12 and p[-1].endswith('.obj'):
        a_ = p[-1][:8]
        if p[1] in ('func_' + a_, (_rr.get(a_) or {}).get('symbol')):
            try:
                _main.setdefault(a_, (p[1], int(p[2], 16)))
            except ValueError:
                pass
_mainaddr = {a_ + '.obj': A_ for a_, (n_, A_) in _main.items()}


def real_at(t):   # our link has real code for original address t: its converted main function, or func_<t> non-stub
    a8 = '%08x' % t
    return a8 in _main or ('func_' + a8 in syms and 'stubs' not in objof.get('func_' + a8, 'stubs'))


def helper(t):   # code a converted object carries besides its byte-exact main function (analog helpers: not original)
    ob = objat.get(t, '')
    return len(ob) == 12 and ob.endswith('.obj') and ob in _mainaddr and _mainaddr[ob] != t


for a_, (name, A) in sorted(_main.items()):
    X = int(a_, 16)
    name = 'func_' + a_
    n_funcs += 1
    lst = []
    k = 0
    end = min(0x400, len(o) - (X - B))
    import capstone as _cs
    _md = globals().setdefault('_MD', _cs.Cs(_cs.CS_ARCH_X86, _cs.CS_MODE_32))
    _starts = {i_.address - X for i_ in _md.disasm(bytes(o[X - B:X - B + end]), X)}
    # both streams must agree instruction by instruction up to a compared call: a converted body that is not
    # byte-exact paired ClassDescriptor's ctor with the original's operator new at the same offset (callfix then
    # renamed the ctor object-wide -> static init crashed)
    _oi_ = [(i_.address - X, i_.mnemonic) for i_ in _md.disasm(bytes(o[X - B:X - B + end]), X)]
    _qi_ = [(i_.address - A, i_.mnemonic) for i_ in _md.disasm(bytes(q[A - B:A - B + end]), A)]
    _agree = set()
    for (ko_, mo_), (kq_, mq_) in zip(_oi_, _qi_):
        if ko_ != kq_ or mo_ != mq_:
            break
        _agree.add(ko_)
    _starts &= _agree   # real instruction starts: a false e8
    # inside an instruction (+0x5e in boost tss::init) skipped the real call at +0x5f to the misnamed do_lock
    while k < end - 5:
        if k in _starts and q[A - B + k] == 0xe8 and o[X - B + k] == 0xe8:
            to = X + k + 5 + struct.unpack_from('<i', o, X - B + k + 1)[0]
            tq = A + k + 5 + struct.unpack_from('<i', q, A - B + k + 1)[0]
            if 0x401000 <= to < 0x7c0000:
                n_calls += 1
                names = at.get(tq, [])
                ok = any(to in orig_addrs(n) for n in names) and not helper(tq)
                if ok and all(n in FOLDED for n in names if to in orig_addrs(n)):   # folded name (create<Team> = 4 create<X>):
                    fo_, fq_ = follow(to, o), follow(tq, q)                              # the bound code must BE the original target
                    ok = fo_[0] == fq_[0] == 'code' and sum(x == y for x, y in zip(o[fo_[1] - B:fo_[1] - B + 24], q[fq_[1] - B:fq_[1] - B + 24])) >= 21
                if not ok:   # same import through a thunk on both sides, or the same leading code bytes: the same function
                    fo, fq = follow(to, o), follow(tq, q)
                    if fo[0] == fq[0] == 'imp':
                        ok = imp_o.get(fo[1]) is not None and imp_o.get(fo[1]) == imp_q.get(fq[1])
                    elif fo[0] == fq[0] == 'code':
                        bo, bq = o[fo[1] - B:fo[1] - B + 24], q[fq[1] - B:fq[1] - B + 24]
                        ok = sum(x == y for x, y in zip(bo, bq)) >= 21
                stubbed = names and all('stubs' in objof.get(n, '') for n in names)
                # a call that lands on a STUB while the original target has real code here (converted body / glue):
                # per-object analog spellings (_fn = Name::declare) never got bound -> retarget to func_<T>
                if not ok and stubbed and real_at(to):
                    lst.append([k, '%08x' % to, names[0]])
                elif not ok and names and any(n.startswith('?') for n in names) and not stubbed:
                    lst.append([k, '%08x' % to, names[0]])
            k += 5
            continue
        # DIR32 code pointers (push offset fn / mov reg, offset fn): call_once(flag, init) in SafeChat::singleton pushed
        # the FOREIGN analog's own initLocalScope (Guid's init body) instead of the original's 006587e0
        wo = struct.unpack_from('<I', o, X - B + k)[0]
        if 0x401000 <= wo < 0x7c0000 and k >= 1 and o[X - B + k - 1] in (0x68, 0xb8, 0xb9, 0xba, 0xbb, 0xbe, 0xbf):
            wq = struct.unpack_from('<I', q, A - B + k)[0]
            if wq != wo:
                names = [n for n in at.get(wq, []) if not n.startswith(('__ehhandler$', '__unwindfunclet$', '$', '__catch$'))]
                local = objat.get(wq) == objat.get(A) or helper(wq)   # an analog helper, this object's or another's
                ok = (not local and any(wo in orig_addrs(n) for n in names)) or (wq == A and wo == X)
                if not ok and names and all('stubs' in objof.get(n, '') for n in names) and real_at(wo):
                    lst.append([k, '%08x' % wo, names[0]])
                elif not ok and names and not any('stubs' in objof.get(n, '') for n in names):
                    fo, fq = follow(wo, o), follow(wq, q)
                    same = fo[0] == fq[0] == 'code' and sum(x == y for x, y in zip(o[fo[1] - B:fo[1] - B + 24], q[fq[1] - B:fq[1] - B + 24])) >= 21
                    if not same:
                        lst.append([k, '%08x' % wo, names[0]])
                k += 4
                continue
        if q[A - B + k] == 0xcc and q[A - B + k + 1] == 0xcc and o[X - B + k] == 0xcc:
            break
        k += 1
    if lst:
        bad[name] = lst
(H / 'auto/callaudit.json').write_text(json.dumps(bad, indent=0))
print('converted functions %d, original-code calls compared %d, calls bound to a different named function: %d in %d functions'
      % (n_funcs, n_calls, sum(len(v) for v in bad.values()), len(bad)))
print('func_00792440 flagged:', 'func_00792440' in bad)
for n, v in list(bad.items())[:12]:
    print('  %s +%x orig->%s ours->%s' % (n, v[0][0], v[0][1], v[0][2][:70]))
