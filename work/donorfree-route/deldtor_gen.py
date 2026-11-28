"""python deldtor_gen.py: compiler-generated deleting destructors (??_G/??_E, registry kind `gen`) and the this-adjusting
thunks in front of them (kind `adjustor`) that our link left as `return 0` stubs. They sit in the copied vtables: deleting
such an object ran no destructor and freed nothing, and the stub's wrong `ret` popped nothing. Each original body is
decoded (scalar shape: [mov [esi],vtbl] call ~T ; if (f & 1) operator delete(this) ; return this ; adjustor shape:
sub ecx,N / add ecx,-N ; jmp T) and re-expressed as a small C++ analog (struct Dd_<addr> { d(); g(unsigned); }),
compiled through native_check_runner. Bindings go to aliases_deldtor.txt (grow-only): the stub name -> the analog,
the analog's `d` -> our definition of the destructor, its vtable -> our ??_7 definition. Prints results.json to bind."""
import json, re, subprocess, sys
from pathlib import Path
import capstone, pefile
H = Path(__file__).parent
ROOT = H.parents[1]
BS = chr(92)
reg = json.load(open(ROOT / 'work/2008-06/identity-registry.json'))
byname = {}
for a, v in reg.items():
    if (v or {}).get('name'):
        byname.setdefault(v['name'], a)
pe = pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe'), fast_load=True)
img, B = pe.get_memory_mapped_image(), 0x400000
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
stubs, defs = set(), set()
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        (stubs if 'stubs' in p[-1] else defs).add(p[1])


def addr_of(s):
    return s[5:].lower() if s.startswith('func_') else byname.get(s)


def our_name(a):
    """our link's DEFINED (non-stub) name for original address a, else None"""
    n = (reg.get(a) or {}).get('name')
    for c in (n, 'func_' + a):
        if c and c in defs:
            return c
    return None


def body(a, n=40):
    out = []
    for i in md.disasm(bytes(img[int(a, 16) - B:int(a, 16) - B + 160]), int(a, 16)):
        out.append(i)
        if i.mnemonic in ('ret', 'jmp') or len(out) >= n:
            break
    return out


def imm(i):
    m = re.search(r'0x([0-9a-f]+)', i.op_str)
    return '%08x' % int(m.group(1), 16) if m else None


def gen_shape(a):
    """-> (vtable_addr|None, dtor_addr|None) for a scalar deleting destructor, else None"""
    ins = body(a)
    t = ' | '.join(i.mnemonic + ' ' + i.op_str for i in ins)
    if not re.search(r'test byte ptr \[esp \+ [48]\], 1', t) or not t.endswith('ret 4') or 'esp + 8], 2' in t or 'ebp' in t:
        return None
    vt = dt = None
    calls = [i for i in ins if i.mnemonic == 'call']
    for i in ins:
        if i.mnemonic == 'mov' and i.op_str.startswith('dword ptr [esi], 0x'):
            vt = imm(i)
    tst = next(k for k, i in enumerate(ins) if i.mnemonic == 'test')
    pre = [i for i in ins[:tst] if i.mnemonic == 'call']
    if len(pre) > 1 or len(calls) - len(pre) != 1:
        return None
    if pre:
        if not pre[0].op_str.startswith('0x'):
            return None
        dt = imm(pre[0])
    return vt, dt


gens, adjs, cadjs, skipped = {}, {}, {}, {'gen-shape': 0, 'adj-target': 0, 'unresolved': 0}
cand = sorted(s for s in stubs if addr_of(s) and (s.startswith(('func_', '??_G', '??_E')) or re.match(r'^\?\w+@.*@[WC]\w', s)))
for s in cand:
    a = addr_of(s)
    if a in gens or not re.fullmatch(r'[0-9a-f]{8}', a or ''):
        continue
    g = gen_shape(a)
    if g:
        gens[a] = g
        continue
    ins = body(a, 3)
    if len(ins) == 2 and ins[1].mnemonic == 'jmp' and ins[1].op_str.startswith('0x'):
        m = re.fullmatch(r'(sub|add) ecx, (0x[0-9a-f]+|\d+)', ins[0].op_str and ins[0].mnemonic + ' ' + ins[0].op_str)
        if m:
            n = int(m.group(2), 0)
            n = n if m.group(1) == 'sub' else (-n) & 0xffffffff
            n = n - (1 << 32) if n & 0x80000000 else n
            adjs[a] = (n, imm(ins[1]))
        m = re.fullmatch(r'sub dword ptr \[esp \+ 4\], (0x[0-9a-f]+|\d+)', ins[0].op_str and ins[0].mnemonic + ' ' + ins[0].op_str)
        if m:   # COM stdcall adjustor: this is on the stack
            cadjs[a] = (int(m.group(1), 0), imm(ins[1]))
# grow-only state: the --results swap keeps only the newest object per source, so every run must re-emit everything an
# earlier run emitted (stubs it bound are gone from the map now; their aliases still name these analogs)
_stf = H / 'auto/deldtor_state.json'
try:
    _st = json.load(open(_stf))
except (OSError, ValueError):
    _st = {'gens': {}, 'adjs': {}}
try:   # seed: every analog an alias in aliases_deldtor.txt names is re-decoded from the original
    for l_ in open(H / 'aliases_deldtor.txt'):
        m_ = re.search(r'@D([da])_([0-9a-f]{8})@@', l_)
        if not m_:
            continue
        a_ = m_.group(2)
        if m_.group(1) == 'd' and a_ not in gens and a_ not in _st['gens']:
            g_ = gen_shape(a_)
            if g_:
                _st['gens'][a_] = list(g_)
        elif m_.group(1) == 'a' and a_ not in adjs and a_ not in _st['adjs']:
            i_ = body(a_, 3)
            if len(i_) == 2 and i_[1].mnemonic == 'jmp' and i_[1].op_str.startswith('0x'):
                mm_ = re.fullmatch(r'(sub|add) ecx, (0x[0-9a-f]+|\d+)', i_[0].mnemonic + ' ' + i_[0].op_str)
                if mm_:
                    n_ = int(mm_.group(2), 0); n_ = n_ if mm_.group(1) == 'sub' else (-n_) & 0xffffffff
                    _st['adjs'][a_] = [n_ - (1 << 32) if n_ & 0x80000000 else n_, imm(i_[1])]
except OSError:
    pass
for a_, v_ in _st['gens'].items():
    gens.setdefault(a_, tuple(v_))
for a_, v_ in _st['adjs'].items():
    adjs.setdefault(a_, tuple(v_))
json.dump({'gens': {a_: list(v_) for a_, v_ in gens.items()}, 'adjs': {a_: list(v_) for a_, v_ in adjs.items()}}, open(_stf, 'w'))
# adjustors are kept only when their target is a deleting destructor (ours generated, or one our link defines)
gen_by_addr = dict(gens)
lines, al, keep_adj, made, gadj, gmade = [], {}, {}, set(), {}, {}
for a, (vt, dt) in sorted(gens.items()):
    d = our_name(dt) if dt else None
    v = (our_name(vt) or ('dat_' + vt if 'dat_' + vt in defs else None)) if vt else None
    if (dt and not d) or (vt and not v):
        skipped['unresolved'] += 1
        continue
    st = 'Dd_' + a
    made.add(a)
    lines.append('struct %s { void d(); void* g(unsigned f); };' % st)
    body_ = ''
    if v:
        lines.append('extern "C" const int VT_%s;' % a)
        body_ += ' *(const void**)this = &VT_%s;' % a
        al['_VT_' + a] = v
    if d:
        body_ += ' d();'
        al['?d@%s@@QAEXXZ' % st] = d
    lines.append('void* %s::g(unsigned f) {%s if (f & 1) operator delete(this); return this; }' % (st, body_))
for a, (n, t) in sorted(adjs.items()):
    tn = our_name(t)
    if t in made or (tn and tn.startswith(('??_G', '??_E'))):
        keep_adj[a] = (n, t, tn)
    elif tn:
        gadj[a] = (n, t, tn)   # ordinary virtual: a forwarding wrapper with the target's own stack-argument count
    else:
        skipped['adj-target'] += 1


def retn(t):
    """stack bytes the original function at t pops (its first ret)"""
    for i in md.disasm(bytes(img[int(t, 16) - B:int(t, 16) - B + 0x3000]), int(t, 16)):
        if i.mnemonic == 'ret':
            return int(i.op_str, 0) if i.op_str else 0
        if i.mnemonic == 'int3':
            break
    return None


def gmang(st, k, stdcall=False):
    return '?g@%s@@%s_K%s' % (st, 'SG' if stdcall else 'QAE', ('I' * k + '@Z') if k else 'XZ')


# adjustors in front of ordinary virtuals (stub_ret_audit: their `return 0` stubs popped the wrong byte count): wrapper
# g(k unsigned) -> target, returning unsigned __int64 (edx:eax intact; a float result stays in st0 untouched)
for a, (n, t, tn) in sorted(gadj.items()):
    r_ = retn(t)
    if r_ is None or r_ % 4:
        skipped['adj-target'] += 1; continue
    k = r_ // 4
    ps = ', '.join('unsigned a%d' % i for i in range(k)); cs = ', '.join('a%d' % i for i in range(k))
    lines.append('struct Dg_%s { unsigned __int64 g(%s); };' % (a, ', '.join(['unsigned'] * k)))
    lines.append('struct Dx_%s { unsigned __int64 g(%s); };' % (a, ', '.join(['unsigned'] * k)))
    lines.append('unsigned __int64 Dx_%s::g(%s) { return ((Dg_%s*)((char*)this - %d))->g(%s); }' % (a, ps, a, n, cs))
    al[gmang('Dg_' + a, k)] = tn
    gmade[a] = gmang('Dx_' + a, k)
for a, (n, t) in sorted(cadjs.items()):
    tn = our_name(t); r_ = retn(t)
    if not tn or r_ is None or r_ % 4 or r_ < 4:
        skipped['adj-target'] += 1; continue
    k = r_ // 4
    ps = ', '.join('unsigned a%d' % i for i in range(k)); cs = ', '.join(['a0 - %d' % n] + ['a%d' % i for i in range(1, k)])
    lines.append('struct Dh_%s { static unsigned __int64 __stdcall g(%s); };' % (a, ', '.join(['unsigned'] * k)))
    lines.append('struct Dy_%s { static unsigned __int64 __stdcall g(%s); };' % (a, ', '.join(['unsigned'] * k)))
    lines.append('unsigned __int64 __stdcall Dy_%s::g(%s) { return Dh_%s::g(%s); }' % (a, ps, a, cs))
    al[gmang('Dh_' + a, k, True)] = tn
    gmade[a] = gmang('Dy_' + a, k, True)
for a, (n, t, tn) in sorted(keep_adj.items()):
    st = 'Da_' + a
    if t in made:
        tgt = 'Dd_' + t
    else:
        tgt = 'Dt_' + a
        lines.append('struct %s { void* g(unsigned f); };' % tgt)
        al['?g@%s@@QAEPAXI@Z' % tgt] = tn
    lines.append('struct %s { void* g(unsigned f); };' % st)
    lines.append('void* %s::g(unsigned f) { return ((%s*)((char*)this - %d))->g(f); }' % (st, tgt, n))
# vcall thunks (mov eax,[ecx] ; jmp [eax+N]): what MSVC itself emits for &Class::virtualFn. A dummy polymorphic class
# with enough slots makes the compiler generate ??_9Vc@@$B<N>AE; the stub binds to that.
def mnum(n):
    if 1 <= n <= 10:
        return str(n - 1)
    h = '%X' % n
    return ''.join('ABCDEFGHIJKLMNOP'[int(c, 16)] for c in h) + '@'


vcs = {}
for s in cand:
    a = addr_of(s)
    if not re.fullmatch(r'[0-9a-f]{8}', a or ''):
        continue
    ins = body(a, 2)
    if len(ins) == 2 and ins[0].op_str == 'eax, dword ptr [ecx]' and ins[1].mnemonic == 'jmp':
        m = re.fullmatch(r'dword ptr \[eax(?: \+ (0x[0-9a-f]+|\d+))?\]', ins[1].op_str)
        if m:
            vcs[s] = int(m.group(1) or '0', 0)
def mdec(t):   # inverse of mnum: '7' -> 8, 'M@' -> 0xc, 'BCE@' -> 0x124
    if re.fullmatch(r'\d', t):
        return int(t) + 1
    m_ = re.fullmatch(r'([A-P]+)@', t)
    return int(''.join('%X' % ('ABCDEFGHIJKLMNOP'.index(c)) for c in m_.group(1)), 16) if m_ else None


# named vcall thunks of any class that only exist as stubs (gemini dossier 17: ??_9Instance@RBX@@$B7AE as zero DATA in
# su_ni_ca_qt_base_stubs -> executing it faults): the thunk depends only on the slot offset, so bind it to Vc's
for s in stubs:
    m_ = re.match(r'^\?\?_9.+@@\$B(\w+?@?)AE$', s)
    if m_ and s not in vcs and not s.startswith('??_9Vc@@') and '@RBX@@' in s:   # RBX engine only: CPropGrid::Item's real dispatch hit a garbage item set (the no-op stub had hidden it)
        o_ = mdec(m_.group(1))
        if o_ is not None and o_ % 4 == 0:
            vcs[s] = o_
if vcs:
    top = max(vcs.values()) // 4
    lines.append('struct Vc { %s };' % ' '.join('virtual void f%d();' % i for i in range(top + 1)))
    lines.append('typedef void (Vc::*VcP)();')
    for o in sorted(set(vcs.values())):
        lines.append('VcP vc_%x = &Vc::f%d;' % (o, o // 4))
# stub name -> analog
stub_of = {}


def cls_ok(s, a):
    """a NAMED stub binds only when the decoded body names the same class (registry names on ICF-folded addresses can
    belong to another class: binding ??_E<X> to Y's deleting destructor would run Y's destructor on an X)"""
    if s.startswith('func_'):
        return True
    m = re.match(r'^\?\?_[GE](.+@)@[UQAE]+PAXI@Z$', s)
    if not m or a not in made:
        return False
    vt, dt = gens[a]
    names = [our_name(dt) if dt else None, our_name(vt) if vt else None]
    return any(n and (n.startswith('??1' + m.group(1) + '@') or n.startswith('??_7' + m.group(1) + '6')) for n in names)


for s in cand:
    a = addr_of(s)
    if not cls_ok(s, a):
        continue
    if a in made:
        stub_of[s] = '?g@Dd_%s@@QAEPAXI@Z' % a
    elif a in keep_adj:
        stub_of[s] = '?g@Da_%s@@QAEPAXI@Z' % a
    elif a in gmade:
        stub_of[s] = gmade[a]
src = ROOT / 'work/native-client/stub-drafts/StubLive_DelDtor.cpp'
src.write_text('// native-flags: /O2 /GS- /MD /DNDEBUG\n// generated by work/donorfree-route/deldtor_gen.py: deleting-destructor and adjustor-thunk analogs\n'
               '#include <new>\n' + '\n'.join(lines) + '\n')
man = src.with_suffix('.json')
man.write_text(json.dumps({'compiler_build': 21022, 'compiler_variant': 'default', 'jobs': [{'source': str(src), 'checks': [], 'ranges': [], 'layouts': []}]}))
r = subprocess.run([sys.executable, str(ROOT / 'rebuild/2008-06/tests/native_check_runner.py'), 'run', str(man)], capture_output=True, text=True)
run = re.search(r'"results":"([^"]+)"', r.stdout)
resf = run.group(1).replace(BS + BS, BS) if run else None
rows = json.loads(Path(resf).read_text()) if resf else []
rows = rows if isinstance(rows, list) else rows.get('results', [])
ok = any(x.get('status') == 'complete' for x in rows)
if ok:
    al.update(stub_of)
    for s_, o in vcs.items():
        al[s_] = '??_9Vc@@$B%sAE' % mnum(o)
    old = {}
    try:
        old = dict(l.strip().split('=', 1) for l in open(H / 'aliases_deldtor.txt') if '=' in l)
    except OSError:
        pass
    old.update(al)
    (H / 'aliases_deldtor.txt').write_text(''.join('%s=%s\n' % kv for kv in sorted(old.items())))
else:
    print('BUILD FAILED; see', resf, r.stdout[-400:], r.stderr[-400:])
print('deldtor_gen: deleting dtors %d (vtable-setting %d), adjustors %d, stubs bound %d, skipped %s'
      % (sum(1 for a in gens if 'struct Dd_%s ' % a in '\n'.join(lines)), sum(1 for v in gens.values() if v[0]), len(keep_adj), len(stub_of) if ok else 0, skipped))
print(resf)
