"""Clone propagation (no model): remaining functions whose masked asm equals an already-exact function's.
Generated sibling source only for mechanical substitutions (see gen_* below); gated with native_creator_gate.
  python work/native-client/clone_propagate.py [--cluster-only] [--limit N] [--only ADDR,ADDR] [--jobs 4]"""
import argparse, collections, json, pathlib, re, sys
HERE = pathlib.Path(__file__).resolve().parent
ROOT = HERE.parent.parent
LOCK = HERE / 'prove-out/CENSUS.lock'
OUT = HERE / 'clone-propagate'
ap = argparse.ArgumentParser()
ap.add_argument('--recluster', action='store_true')
ap.add_argument('--cluster-only', action='store_true')
ap.add_argument('--limit', type=int, default=0)
ap.add_argument('--only', default='')
ap.add_argument('--jobs', type=int, default=4)
args = ap.parse_args()
if LOCK.is_file():
    sys.exit('a census is running (prove-out/CENSUS.lock)')
import os
os.chdir(ROOT)
sys.path.insert(0, str(ROOT)); sys.path.insert(0, str(HERE))
from roc import integration_site, match
import capstone
CS = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32); CS.detail = True
BASE = match._base_relocs('2008-06')
base, IMG = match._image('2008-06')
match._image = lambda c, _r=(base, IMG): _r   # target() reparses the PE per call otherwise
LO, HI = base, base + len(IMG)


def masked(addr):
    code, relocs, row = match.target('2008-06', addr)
    a = int(addr, 16)
    b = bytearray(code)
    for r in relocs:
        b[r:r + 4] = b'\0\0\0\0'
    for i in CS.disasm(code, a):
        o = i.address - a
        if i.bytes[0] in (0xe8, 0xe9) or (i.bytes[0] == 0x0f and 0x80 <= i.bytes[1] <= 0x8f):
            t = i.operands[0].imm
            if not a <= t < a + len(code):
                b[o + len(i.bytes) - 4:o + len(i.bytes)] = b'\0\0\0\0'
        else:
            for off, sz in ((i.disp_offset, 4), (i.imm_offset, 4)):
                if sz and off and i.imm_size in (0, 4) and off + 4 <= len(i.bytes):
                    v = int.from_bytes(i.bytes[off:off + 4], 'little')
                    if LO <= v < HI and (a + o + off) in BASE:
                        b[o + off:o + off + 4] = b'\0\0\0\0'
    return bytes(b)


cl = json.loads((HERE / 'remaining-classified.json').read_text())
ic = integration_site.inactive_code(pathlib.Path('.'))
exact = {k: v for k, v in ic.items() if v[1]}
def cluster():
    groups = collections.defaultdict(lambda: ([], []))
    for k in exact:
        try:
            groups[masked(k)][0].append(k)
        except BaseException:
            pass
    rem = [k for k in cl if k not in exact]
    pairs = []
    for k in rem:
        try:
            g = groups.get(masked(k))
        except BaseException:
            continue
        if g and g[0]:
            pairs.append((k, g[0]))
    return pairs


OUT.mkdir(exist_ok=True)
CAND = OUT / 'candidates.json'
pairs = cluster() if (args.recluster or not CAND.is_file()) else json.loads(CAND.read_text())
CAND.write_text(json.dumps(pairs, indent=1))
if args.cluster_only:
    sys.exit()


# ---- generators: mechanical substitution only, driven by the sibling's registry signature -------------------------
import native_llm as m
import native_creator_gate as cg
reg = m.load_registry()
HEADERS = ROOT / 'rebuild/2008-06/native-headers'
CLASSES = ROOT / 'rebuild/2008-06/native-classes'
GCC = {}


def ext_header(sym):
    """native header declaring `extern ... sym[]` (the Name constants)."""
    if sym not in GCC:
        pat = re.compile(r'extern\s+(?:const\s+)?char\s+%s\s*\[' % re.escape(sym))
        GCC[sym] = next((h for h in HEADERS.rglob('*.h') if pat.search(h.read_text(errors='replace'))), None)
    return GCC[sym]


def decl_ns(h, sym):
    """Enclosing namespace chain ('RBX::HUMAN::') of the extern declaration of SYM in header H."""
    text = re.sub(
        r'/\*.*?\*/', '', re.sub(r'(?m)//.*$', '', h.read_text(errors='replace')), flags=re.S)
    mo = re.search(r'extern\s+(?:const\s+)?char\s+%s\s*\[' % re.escape(sym), text)
    stack = []
    for t in re.finditer(r'namespace\s+(\w+)\s*\{|\{|\}', text[:mo.start()]):
        if t.group(0) == '}':
            stack and stack.pop()
        else:
            stack.append(t.group(1))
    return ''.join(n + '::' for n in stack if n)


def twin_flags(twin):
    src = ROOT / ic[twin][3][0]
    mo = re.search(r'(?m)^// native-flags:.*$', src.read_text(errors='replace')) if src.is_file() else None
    return mo.group(0) if mo else '// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL'


def gen(addr, twin):
    """-> (kind, headers, code, symbol needle) or None."""
    sig = ((reg.get(addr) or {}).get('signature') or '').strip()
    mo = re.search(r'Name::callDoDeclare<&(?:char(?: const)? \* (?:const )?)((?:\w+::)*)(\w+)>\(void\)$', sig)
    if mo:
        ns, sym = mo.groups()
        h = ext_header(sym)
        if not h:
            return None
        ns = decl_ns(h, sym) or ns
        return ('callDoDeclare', [h, HEADERS / 'util/Name.h'],
                'template void RBX::Name::callDoDeclare<%s%s>();\n' % (ns or 'RBX::', sym), 'callDoDeclare@$1?%s@' % sym)
    mo = re.search(r'ServiceProvider::callDoGetClassIndex<class ([\w:]+)>\(void\)$', sig)
    if mo:
        cls = mo.group(1)
        h = m.declaring_header(cls)
        if not h:
            return None
        code = ('#include <boost/thread/once.hpp>\n'
                'namespace RBX {\n'
                'template<class Class> size_t ServiceProvider::doGetClassIndex() { static size_t index = newIndex(); return index; }\n'
                'template<class Class> void ServiceProvider::callDoGetClassIndex() { doGetClassIndex<Class>(); }\n}\n'
                'template void RBX::ServiceProvider::callDoGetClassIndex<%s>();\n' % cls)
        return 'classindex', [pathlib.Path(h), HEADERS / 'v8tree/Service.h'], code, 'callDoGetClassIndex@V%s@' % cls.split('::')[-1]
    return None


def run(pair):
    addr, twin = pair
    g = gen(addr, twin)
    if not g:
        return addr, 'no-shape', ''
    kind, headers, code, needle = g
    work = OUT / addr
    try:
        sym = cg.discover_symbol(work, headers, code, addr, needle)
        if not sym:
            return addr, 'no-symbol', (cg.LAST_ERROR.get(addr) or '')[:200]
        status, detail = cg.gate_code(work, headers, code, {addr: sym})
    except Exception as error:   # noqa: BLE001
        return addr, 'harness-error', repr(error)[:200]
    st = status.get(addr, 'missing')
    if st != 'inactive_exact':
        return addr, st, (detail or '')[:200]
    if LOCK.is_file():
        sys.exit('census started: not writing')
    tu = CLASSES / ('CloneProp_%s.cpp' % addr)
    sdk = ''.join(l + '\n' for l in code.splitlines() if l.startswith('#include'))
    body = '\n'.join(l for l in code.splitlines() if not l.startswith('#include'))
    tu.write_text('%s\n// %s: clone of exact %s (%s), same masked bytes; %s (clone_propagate.py, byte-proved standalone)\n%s%s\n%s\n'
                  % (twin_flags(twin), addr, twin, ic[twin][3][0], kind, sdk,
                     ''.join('#include "%s"\n' % pathlib.Path(h).relative_to(HEADERS).as_posix() for h in dict.fromkeys(headers)), body))
    return addr, st, (tu.relative_to(ROOT).as_posix(), sym, twin)


import concurrent.futures as cf
todo = [(a, t[0]) for a, t in pairs]
if args.only:
    todo = [x for x in todo if x[0] in args.only.split(',')]
if args.limit:
    todo = todo[:args.limit]
counts = collections.Counter()
gen_n = sum(1 for x in todo if gen(*x))
rows_p = HERE / 'clone-identity-bindings.json'
rows = json.loads(rows_p.read_text()) if rows_p.is_file() else {
    'scope': 'identity evidence: clone_propagate.py byte-proved clones', 'sources': {}, 'identity_bindings': []}
src_p = HERE / 'class-lane-new-sources.json'
with cf.ThreadPoolExecutor(args.jobs) as pool:
    for addr, st, d in pool.map(run, todo):
        counts[st] += 1
        print(addr, st, d, flush=True)
        if st == 'inactive_exact':
            path, sym, twin = d
            rows['identity_bindings'].append({'symbol': sym, 'address': addr, 'votes': 1,
                                              'identity_evidence': 'clone of exact %s; body byte-proved' % twin})
            rows_p.write_text(json.dumps(rows, indent=1))
            lst = json.loads(src_p.read_text())
            if path not in lst:
                src_p.write_text(json.dumps(lst + [path], indent=1))
print('candidates: %d  generated: %d  exact: %d  %s' % (len(pairs), gen_n, counts['inactive_exact'], dict(counts)))
