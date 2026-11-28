"""python nearmatch.py [ADDR...]: NEAR-MATCH fallback for exact sources that compile but are not byte-identical
(rename.json status 'nomatch'). Owner decision 2026-11-24: a working (buggy) client first, so a close analog beats a
stub that returns 0. For each address, from rename.py's leftover object (work/native-client/rename/<addr>.obj):
  1. pick the object function closest to the original bytes (relocation bytes masked, difflib ratio >= MIN_RATIO)
  2. bind its relocations to the original function's targets PAIRED BY ORDER when the call/data reference counts
     agree (codegen differences rarely reorder references); otherwise keep the analog's own names
  3. rename that function to the address's name (func_<addr> / real name), write renamed/near/<addr>.obj
Results go to renamed/near/results.json (native_check_runner format) and are appended to linkexp/qt_results.txt, so
quicktest links them as GAP-FILL drafts: last, never defining a name a real object defines. NOT exact: replace with
exact recoveries as workers produce them. Writes auto/nearmatch.json (addr -> ratio, paired, symbol)."""
import difflib, json, os, re, struct, sys
from pathlib import Path
H = Path(__file__).parent
ROOT = H.parents[1]
os.environ.setdefault('ROC_ADDRMAP', str(H / 'renamed/addrmap.json'))
os.environ.setdefault('ROC_RENAME_DEFINED', str(H / 'renamed/defined.json'))
os.environ.setdefault('ROC_RENAME_PLACEHOLDER', '1')
sys.path.insert(0, str(ROOT)); sys.path.insert(0, str(ROOT / 'work/native-client'))
import capstone
os.chdir(ROOT)   # rename.py reads repo-relative paths at import
import rename as R   # noqa: E402  (module setup only; main() is guarded)
from roc import match
MIN_RATIO = float(os.environ.get('NEAR_MIN_RATIO', '0.6'))
OUT = H / 'renamed/near'
OUT.mkdir(exist_ok=True)
REN = json.loads((H / 'renamed/rename.json').read_text())
FF = json.load(open(ROOT / 'work/native-client/layout/function-files.json'))
R.REGISTRY = R.load_registry()
base, image = match._image('2008-06')
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)


_STARTS = sorted(int(k, 16) for k in FF)


def orig_size(a):
    t = (ROOT / 'src/2008-06' / (a + '.cpp')).read_text(errors='replace')[:400]
    m = re.search(r'size:\s*(\d+)', t)
    if m:
        return int(m.group(1))
    import bisect
    va = int(a, 16)   # no size in the header: up to the next known function start
    i = bisect.bisect_right(_STARTS, va)
    return min((_STARTS[i] - va) if i < len(_STARTS) else 64, 0x2000)


def orig_refs(va, size):
    """original function's references in order: (offset, 'DIR32'|'REL32', target va)"""
    out = []
    code = bytes(image[va - base:va - base + size])
    from roc import fingerprint
    if 'T' not in G:
        G['T'] = fingerprint.Target('2008-06')
    for o in sorted(G['T'].exe_relocs(va, size)):
        if o + 4 > len(code):
            continue
        out.append((o, 'DIR32', struct.unpack_from('<I', code, o)[0]))
    for ins in md.disasm(code, va):
        if ins.mnemonic in ('call', 'jmp') or ins.mnemonic.startswith('j'):
            if ins.size == 5 and ins.bytes[0] in (0xe8, 0xe9):
                t = int(ins.op_str, 16) if ins.op_str.startswith('0x') else None
                if t is not None and not (va <= t < va + size):   # calls/tail jumps out of the function
                    out.append((ins.address - va + 1, 'REL32', t))
    return sorted(out)


G = {}


def masked(code, rel):
    b = bytearray(code)
    for o in rel:
        b[o:o + 4] = b'\0\0\0\0'
    return bytes(b)


def near(a):
    if 0x7c0000 <= int(a, 16) < 0x800000:   # static initializers/atexit: a near copy builds globals wrongly (startup crash)
        return None, 'static initializer'
    obj = ROOT / 'work/native-client/rename' / (a + '.obj')
    if not obj.exists():
        return None, 'no leftover object'
    data = obj.read_bytes()
    va, size = int(a, 16), orig_size(a)
    ref = orig_refs(va, size)
    orig = masked(bytes(image[va - base:va - base + size]), [o for o, _, _ in ref])
    best = None
    for name, code, rel in match.coff_functions(data):
        if not (0.5 * size <= len(code) <= 2 * size):
            continue
        r_ = difflib.SequenceMatcher(None, orig, masked(code, rel), autojunk=False).ratio()
        if not best or r_ > best[0]:
            best = (r_, name)
    if not best or best[0] < MIN_RATIO:
        return None, 'best ratio %.2f' % (best[0] if best else 0)
    fsym = best[1]
    syms = {i: (n, sec) for i, n, sec, cls, v in R.symtab(data)[0]}
    cls_of = {i: cls for i, n, sec, cls, v in R.symtab(data)[0]}
    rel = [(off, 'DIR32' if typ == R.DIR32 else 'REL32', idx) for off, typ, idx, fo in R.relocations(data, fsym)
           if typ in (R.DIR32, R.REL32)]
    mapping = {}
    paired = False
    o_ = [x for x in ref]
    if len(rel) == len(o_) and all(r[1] == o[1] for r, o in zip(rel, o_)):
        paired = True
        for (off, typ, idx), (_, _, t) in zip(rel, o_):
            nm = syms[idx][0]
            if cls_of.get(idx) == 3 or nm.startswith(('??_C@', '$', '.', '__ehhandler$', '__unwindfunclet$', '__imp_',
                                                     '___security_cookie', '__CxxFrameHandler', '__chkstk', '__EH_prolog')):
                continue
            rn = R.real_name(t)
            new = rn if (rn and rn in R.DEFINED) else ('func_%08x' if t < 0x7c0000 else 'dat_%08x') % t
            if new != nm and idx not in mapping:
                mapping[idx] = new
    if not paired and not os.environ.get('NEAR_UNPAIRED'):
        # unpaired copies keep the analog's own reference names: nativeSetVersion's call resolved to an absolute symbol and
        # jumped to 0xb8 (startup crash, 2026-11-24). Worse than the stub, so only paired copies are linked
        return None, 'references not paired (ratio %.2f)' % best[0]
    sym = REN.get(a, {}).get('symbol') or 'func_' + a
    fidx = next(i for i, (n, s) in syms.items() if n == fsym and s > 0)
    mapping[fidx] = sym
    (OUT / (a + '.obj')).write_bytes(R.rename(data, mapping))
    return dict(ratio=round(best[0], 3), paired=paired, analog=fsym, symbol=sym), None


if __name__ == '__main__':
    sel = sys.argv[1:] or sorted(a for a, x in REN.items() if x.get('status') == 'nomatch')
    res, rows, why = {}, [], {}
    for a in sel:
        try:
            r, w = near(a)
        except Exception as e:
            r, w = None, repr(e)[:120]
        if r:
            res[a] = r
            rows.append(dict(status='complete', source=str(H / ('renamed/near/Near_%s.cpp' % a)), object=str(OUT / (a + '.obj'))))
        else:
            why[a] = w
    (H / 'auto/nearmatch.json').write_text(json.dumps(dict(ok=res, skipped=why), indent=1))
    rf = OUT / 'results.json'
    rf.write_text(json.dumps({'results': rows}))
    q = H / 'linkexp/qt_results.txt'
    cur = [l for l in (q.read_text().splitlines() if q.exists() else []) if l.strip()]
    if str(rf) not in cur:
        q.write_text('\n'.join(cur + [str(rf)]) + '\n')
    print('nearmatch: %d of %d linked as gap-fill (%d with paired references), %d skipped' %
          (len(res), len(sel), sum(r['paired'] for r in res.values()), len(why)))
