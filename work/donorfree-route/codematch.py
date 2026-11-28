"""Relocation TARGETS are compared too (masked bytes alone matched 357/358 same-shaped deleting destructors and thunks
that call different functions): every relocated operand of the candidate names a symbol that must be one of the
original target address's names (registry name, func_<T>, dat_<T>, _g_<T>, or a name our link aliases to them).
python codematch.py: func_<A> stubs whose body a linked NATIVE object already compiles under another (real) name.
Converted callers reference the placeholder; the native definition is unreferenced and dropped by the linker, the
placeholder stays a `return 0` stub (ScriptContext::openState / func_005aefa0). For every func_<A> stub the original's
bytes (match.target) are compared instruction by instruction, relocations masked (native_asm.lines), with every
function the native objects in linkexp/qt.final.rsp define that has the same byte length; one EXACT match -> alias
func_<A>=<symbol> in aliases_codematch.txt (grow-only). Two different exact symbols = ICF twins: the first is taken
(identical code). Writes auto/codematch.json."""
import collections, json, re, struct, sys
from pathlib import Path
H = Path(__file__).parent
ROOT = H.parents[1]
sys.path.insert(0, str(ROOT))
from roc import match, native_asm as na
stubs, defs = set(), set()
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        (stubs if 'stubs' in p[-1] else defs).add(p[1])
want = sorted(s[5:].lower() for s in stubs if re.fullmatch(r'func_[0-9a-fA-F]{8}', s))
if '--hits' in sys.argv:   # only stubs the runtime census hit (auto/stubhits.json) or that the static audit saw called
    hot = {r['stub'] for r in json.load(open(H / 'auto/stubhits.json'))}
    try:
        a_ = json.load(open(ROOT / 'work/native-client/mass-tools/stubcall_audit.json'))
        hot |= {r['stub'] for r in a_['top_called_stubs']} | {r['target'] for r in a_['vtable_stub_slots']}
    except OSError:
        pass
    want = [a for a in want if 'func_' + a in hot]
reg = json.load(open(ROOT / 'work/2008-06/identity-registry.json'))
import pefile
_pe = pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe'), fast_load=True)
OIMG, OB = bytes(_pe.get_memory_mapped_image()), 0x400000
ALIAS = {}
for f in H.glob('aliases*.txt'):
    for l in open(f, errors='replace'):
        if '=' in l and not l.startswith('#'):
            k_, v_ = l.strip().split('=', 1); ALIAS.setdefault(k_, v_)


def relsyms(obj):
    """{function name: {offset in function: target symbol}} for every defined code symbol"""
    _, nsec, _, symptr, nsym, optsz, _ = struct.unpack_from('<HHIIIHH', obj, 0)
    strtab = symptr + nsym * 18
    secs = [struct.unpack_from('<8sIIIIIIHHI', obj, 20 + optsz + 40 * i) for i in range(nsec)]
    names, fns, i = {}, collections.defaultdict(list), 0
    while i < nsym:
        raw, value, secnum, typ, _, naux = struct.unpack_from('<8sIhHBB', obj, symptr + 18 * i)
        if raw[:4] == b'\0\0\0\0':
            off = strtab + struct.unpack_from('<I', raw, 4)[0]; raw = obj[off:obj.index(b'\0', off)]
        nm = raw.rstrip(b'\0').decode('latin-1'); names[i] = nm
        if secnum > 0 and typ == 0x20:
            fns[secnum - 1].append((value, nm))
        i += 1 + naux
    out = {}
    for sec, lst in fns.items():
        relptr, nrel = secs[sec][5], secs[sec][7]
        rel = [struct.unpack_from('<IIH', obj, relptr + 10 * k) for k in range(nrel)]
        lst.sort()
        for j, (v, nm) in enumerate(lst):
            end = lst[j + 1][0] if j + 1 < len(lst) else 1 << 31
            out[nm] = {va - v: names.get(si, '?') for va, si, _ in rel if v <= va < end}
    return out


def orig_names(t):
    a = '%08x' % t
    n = {'func_' + a, 'dat_' + a, '_g_' + a, (reg.get(a) or {}).get('name')}
    return {x for x in n if x}


def targets_ok(a, code, rmap):
    """every candidate reloc names the original's target at the same offset"""
    base = int(a, 16)
    for off, sym in rmap.items():
        if off + 4 > len(code):
            return False
        v = struct.unpack_from('<I', code, off)[0]
        op = code[off - 1] if off >= 1 else None
        cand = set()
        for t in (v, (base + off + 4 + v) & 0xffffffff):   # absolute dword, or rel32 operand
            cand |= orig_names(t)
        sym_ = sym.lstrip('_') if sym.startswith('__imp_') is False and sym.startswith('_') and not sym.startswith('__') else sym
        if sym in cand or ALIAS.get(sym) in cand or any(ALIAS.get(c) == sym for c in cand):
            continue
        return False
    return True


bylen = collections.defaultdict(list)
seen = set()
for l in open(H / 'linkexp/qt.final.rsp'):
    o = l.strip().strip('"')
    if not o.lower().endswith('.obj') or not any(t in o for t in ('_ns_', 'native', 'candidate', 'StubLive')):
        continue
    try:
        ob_ = Path(o).read_bytes(); rs_ = relsyms(ob_)
        for sym, body, crel in match.coff_functions(ob_):
            if sym.startswith('func_') or (sym, len(body)) in seen or len(body) < 6:
                continue
            seen.add((sym, len(body)))
            bylen[len(body)].append((sym, body, crel, rs_.get(sym, {})))
    except Exception:
        pass
al, tried = {}, 0
for a in want:
    try:
        code, relocs, _ = match.target('2008-06', a)
    except BaseException:   # SystemExit for addresses the function index does not start
        continue
    cands = bylen.get(len(code))
    if not cands:
        continue
    tried += 1
    base = int(a, 16)
    t = [r[2] for r in na.lines(code, base, relocs)]
    for sym, body, crel, rmap in cands:
        if [r[2] for r in na.lines(body, base, crel)] == t and targets_ok(a, code, rmap):
            al['func_' + a] = sym
            break
old = {}
try:
    old = dict(l.strip().split('=', 1) for l in open(H / 'aliases_codematch.txt') if '=' in l)
except OSError:
    pass
old.update(al)
(H / 'aliases_codematch.txt').write_text(''.join('%s=%s\n' % kv for kv in sorted(old.items())))
json.dump(al, open(H / 'auto/codematch.json', 'w'), indent=0)
print('codematch: func_ stubs %d, with a same-length native candidate %d, exact matches aliased %d (e.g. %s)'
      % (len(want), tried, len(al), list(al.items())[:3]))
