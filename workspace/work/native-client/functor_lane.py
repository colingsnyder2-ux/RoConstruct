"""Functor lane (no model).  Remaining boost::function / boost::slot pieces whose functor type F the binary names by
typeid (research-twins/identities.json rules functor / typeid / via-callee).  Per address: a unit that includes the
native headers of the classes named in F and requests every plausible instantiation for F (table below); a 10 s
compile says which emitted symbol is byte-equal at the address; the unit is rewritten with only that line, the symbol
is bound (typeid evidence), its unproven references are bound from the original relocations (inline_alias rule) and
the proof is rerun.  Only EXACT units move to rebuild/2008-06/native-classes/FunctorInst_<addr>.cpp.
Callers run first, so a slot / function constructor binds the exact callee symbol (allocator included) by reference.
Flags use native-headers/boost-function-pod-vtable (the binary's stored_vtable is a constant table, boost 1.35 shape).

  role            line (F = functor, FN = boost::functionN<R, Args, A>, A = std::allocator<boost::function_base> | <void>)
  assign          template void FN::assign_to<F>(const F&);
  ctor            template FN::functionN(F, ENABLE);   |   template boost::function<R (Args), A>::function(F, ENABLE);
  slot            template boost::slot<boost::function<R (Args), std::allocator<void> > >::slot(const F&);
  manager         template struct boost::detail::function::functor_manager<F, A>;
  tss             template boost::thread_specific_ptr<T>::thread_specific_ptr();
  (ENABLE = the constructor's SFINAE parameter type spelled out; MSVC 2008 refuses plain `int` there, C2770)

  python work/native-client/functor_lane.py [--limit N] [--jobs 1] [--only ADDR,ADDR]"""
import argparse
import collections
import json
import re
import shutil
import sys
import time
import uuid
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
ap = argparse.ArgumentParser()
ap.add_argument('--limit', type=int, default=0)
ap.add_argument('--jobs', type=int, default=1)
ap.add_argument('--only', default='')
args = ap.parse_args()
sys.argv = sys.argv[:1]
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(ROOT))
import agent_prove  # noqa: E402
import inline_alias  # noqa: E402
import shared_json  # noqa: E402
from roc import match, native_bulk, rebuild, standins  # noqa: E402

RUNNER = native_bulk.checker()
TC = rebuild.toolchain(21022)
CLASSES = ROOT / 'rebuild/2008-06/native-classes'
HEADERS = ROOT / 'rebuild/2008-06/native-headers'
LOCK = HERE / 'prove-out/CENSUS.lock'
BINDINGS = HERE / 'class-identity-bindings.json'
FLAGS = ('// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast '
         '/I{headers}/boost-function-pod-vtable')
STD = ['<string>', '<vector>', '<boost/shared_ptr.hpp>', '<boost/bind.hpp>', '<boost/function.hpp>',
       '<boost/signals/slot.hpp>', '<boost/thread/tss.hpp>']
ENABLE = 'boost::enable_if_c<(boost::type_traits::ice_not<(boost::is_integral<F>::value)>::value), int>::type'
ALLOC = {'fb': 'std::allocator<boost::function_base>', 'void': 'std::allocator<void>'}
DEFINES = re.compile(r'^\s*(?:template\s*<[^;{]*>\s*)?(?:class|struct)\s+(?:\w+(?:\([^)]*\))?\s+)?(?:\w+::)*(\w+)\s*(?:final\s*)?(?::[^:;{][^;{]*)?\{', re.M)
SKIP = {'boost', 'std', 'RBX', 'void', 'bool', 'int', 'float', 'double', 'char', 'const', 'basic_string', 'allocator',
        'char_traits', 'vector', 'shared_ptr', 'bind_t', 'value', 'arg', 'detail', 'tss_adapter', '_bi', '_mfi',
        'Reflection', 'Network', 'ViewNew', 'G3D', 'Lua', 'Security', 'SignalDescImpl', 'GenericSlotAdapter'}


def header_index():
    """class/struct name -> [(header, text)] of the headers that define it: native headers first (shortest path
    first; the hyphenated top-level folders are per-unit variant snapshots and are skipped), then the vendor App
    headers behind them on the include path."""
    index = collections.defaultdict(list)
    for root in (HEADERS, ROOT / 'tools/rbxgs/Client/App/include'):
        for path in sorted(list(root.rglob('*.h')) + list(root.rglob('*.hpp')), key=lambda p: len(str(p))):
            rel = path.relative_to(root).as_posix()
            if '-' in rel.split('/')[0]:
                continue
            try:
                text = path.read_text(errors='replace')
            except OSError:
                continue
            for name in set(DEFINES.findall(text)):
                index[name].append((rel, text))
    return index


INDEX = header_index()
PLACEHOLDER = re.compile(r'sub_[0-9a-f]{8}')            # inferred placeholder names never block a real identity
EVIDENCE = json.loads((HERE / 'research-twins/evidence.json').read_text())


def spell(identity):
    text = re.sub(r'\s*\[subobject [^\]]*\]', '', identity).strip()
    return re.sub(r'\b(?:class|struct|enum)\s+', '', text).replace('__cdecl', '')


def includes(functor):
    """one header per class named in F; with several definitions, the one that names the qualifier too"""
    out = ['reflection/signal.h'] if 'SignalDescImpl' in functor else []
    names = list(re.finditer(r'[A-Za-z_]\w*', functor))
    for k, hit in enumerate(names):
        name = hit.group()
        if name in SKIP or re.match(r'(?:mf|list|function)\d$', name):
            continue
        qual = names[k - 1].group() if k and functor[names[k - 1].end():hit.start()] == '::' else ''
        if qual == 'G3D':                                # vendor G3D: one header per class
            best = 'G3D/%s.h' % name
        else:
            found = INDEX.get(name, [])
            # INFERRED: native ContentProvider binds nested RequestResult identity (0048e470/00492ea0/00493210)
            if name == 'ContentProvider' and 'ContentProvider::RequestResult' in functor:
                native = next((h for h, _ in found if h.endswith('NativeContentProvider.h')), None)
                if native:
                    best = native
                else:
                    best = next((h for h, _ in found if qual and qual + '/' in h), None) or next(
                        (h for h, text in found if qual and re.search(r'\b(?:namespace|class|struct)\s+%s\b' % qual, text)),
                        found[0][0] if found else None)
            else:
                best = next((h for h, _ in found if qual and qual + '/' in h), None) or next(
                    (h for h, text in found if qual and re.search(r'\b(?:namespace|class|struct)\s+%s\b' % qual, text)),
                    found[0][0] if found else None)
        if best and best not in out:
            out.append(best)
    return out


def split(inner, keep_void=False):
    out, depth, cur = [], 0, ''
    for ch in inner:
        depth += ch in '<('
        depth -= ch in '>)'
        if ch == ',' and depth == 0:
            out.append(cur.strip())
            cur = ''
        else:
            cur += ch
    return [x for x in out + [cur.strip()] if x and (keep_void or x != 'void')]


def targs(cls):
    return split(cls[cls.index('<') + 1:cls.rindex('>')], True)


def signature(functor):
    """(R, [Args]) of the boost::function that stores F, or None"""
    if functor.endswith('::GenericSlotAdapter'):
        sig = targs(functor[:-len('::GenericSlotAdapter')])[1]
        return sig[:sig.index('(')].strip(), split(sig[sig.index('(') + 1:sig.rindex(')')])
    if functor.startswith('boost::detail::tss_adapter<'):
        return 'void', ['void *']
    if not functor.startswith('boost::_bi::bind_t<'):
        return None
    full = functor[functor.index('<') + 1:functor.rindex('>')]
    parts, depth, cur = [], 0, ''                       # R, f, list: f may be `R (*)(A, B)`
    for ch in full:
        depth += ch in '<('
        depth -= ch in '>)'
        if ch == ',' and depth == 0:
            parts.append(cur.strip())
            cur = ''
        else:
            cur += ch
    ret, func, lst = parts + [cur.strip()]
    if func.startswith('boost::_mfi::'):
        fa = targs(func)
        params = [fa[1] + ' *'] + fa[2:]
    else:
        params = split(func[func.rindex('(', 0, func.rindex(')')) + 1:func.rindex(')')]) if func.endswith(')') else []
        # ponytail: a function-pointer parameter list that itself contains parentheses is not parsed; none in 2008-06
    held = {}
    for i, item in enumerate(targs(lst) if '<' in lst else []):
        hit = re.match(r'boost::arg<(\d+)>', item)
        if hit and i < len(params):
            held[int(hit.group(1))] = params[i]
    return ret, [held[k] for k in sorted(held)]


def lines(functor, ret, fargs):
    """{(kind, cls, alloc): explicit instantiation line}"""
    out = {}
    n = len(fargs)
    for key, alloc in ALLOC.items():
        fn = 'boost::function%d<%s, %s >' % (n, ', '.join([ret] + fargs), alloc)
        func = 'boost::function<%s (%s), %s >' % (ret, ', '.join(fargs), alloc)
        out['assign', 'functionN', key] = 'template void %s::assign_to<F>(const F&);' % fn
        out['ctor', 'functionN', key] = 'template %s::function%d(F, %s);' % (fn, n, ENABLE)
        out['ctor', 'function', key] = 'template %s::function(F, %s);' % (func, ENABLE)
        out['manager', '', key] = 'template struct boost::detail::function::functor_manager<F, %s >;' % alloc
    if ret == 'void':
        out['slot', '', 'void'] = ('template boost::slot<boost::function<void (%s), std::allocator<void> > >::slot(const F&);'
                                   % ', '.join(fargs))
    if functor.startswith('boost::detail::tss_adapter<'):
        out['tss', '', 'fb'] = 'template boost::thread_specific_ptr<%s >::thread_specific_ptr();' % targs(functor)[0]
    return out


def classify(sym):
    """(kind, cls, alloc) of an emitted symbol, or None"""
    alloc = 'void' if '?$allocator@X@' in sym else 'fb'              # allocator<void>; `std` may be a back reference
    if sym.startswith(('__', '$')):
        return None
    if '@?$slot@' in sym and sym.startswith('??$?0'):
        return 'slot', '', 'void'
    if sym.startswith('??$assign_to@'):
        return 'assign', 'functionN', alloc
    if '@?$functor_manager@' in sym:
        return 'manager', '', alloc
    if sym.startswith('??0?$thread_specific_ptr@'):
        return 'tss', '', 'fb'
    if sym.startswith('??$?0') and re.search(r'@\?\$function\d?@', sym):
        return 'ctor', 'function' if '@?$function@$$A6' in sym else 'functionN', alloc
    return None


def byte_equal(obj, addr):
    """emitted symbols whose body equals the original at ADDR outside the candidate's relocations"""
    target = bytes(match.target('2008-06', addr)[0])
    out = []
    for name, body, relocs in match.coff_functions(obj.read_bytes()):
        if len(body) != len(target):
            continue
        a, b = bytearray(body), bytearray(target)
        for off in relocs:
            a[off:off + 4] = b[off:off + 4] = b'\0\0\0\0'
        if a == b:
            out.append(name)
    return out


def bound_at(addr):
    rows = json.loads(BINDINGS.read_text(encoding='utf-8'))['identity_bindings']
    return [r['symbol'] for r in rows if r.get('address') == addr]


def bind(rows):
    while LOCK.is_file():
        time.sleep(30)

    def add(doc):
        have = {(r.get('symbol'), r.get('address')) for r in doc['identity_bindings']}
        doc['identity_bindings'] += [r for r in rows if (r['symbol'], r['address']) not in have]
        return doc
    shared_json.update(BINDINGS, add)


def unbind(sym, addr):
    def drop(doc):
        doc['identity_bindings'] = [r for r in doc['identity_bindings'] if (r.get('symbol'), r.get('address')) != (sym, addr)]
        return doc
    shared_json.update(BINDINGS, drop)


def ref_rows(manifest, addr):
    """Unproven references of the byte-equal body: each symbol is what the original body references at the same
    relocation (inline_alias rule; `__ehhandler$` = the push -1; push H immediate).  Folded bodies share addresses,
    so only a different real symbol bound here by class evidence blocks a row (placeholders and EH rows do not)."""
    out = []
    try:
        jobs = json.loads(Path(manifest).read_text(encoding='utf-8'))['families'][0].get('jobs') or []
        obj = Path(next(j['object'] for j in jobs if j.get('object'))).read_bytes()
    except (OSError, ValueError, KeyError, IndexError, StopIteration):
        obj = b''
    for x in inline_alias.rejections(manifest, {addr}):
        wanted = {e.split(': ', 1)[1] for e in x.get('errors') or [] if e.startswith('unproven reference identity: ')}
        refs = collections.defaultdict(set)
        for ref in x.get('references') or []:
            refs[ref.get('symbol')].add(ref.get('address') or '')
        # reached through a constant stored_vtable {manager, invoker} the body stores: the object's table relocations
        # name the symbols, the original table at the same address holds their addresses
        base, image = match._image('2008-06')
        through = {}
        for table, addrs in refs.items():
            if (table or '').startswith('?stored_vtable@') and len(addrs) == 1 and obj:
                for off, target, _ in [r for r in standins.obj_relocations(obj, table) if r[0] < 8]:
                    at = int(next(iter(addrs)), 16) + off - base
                    through.setdefault(target, set()).add('%08x' % int.from_bytes(bytes(image[at:at + 4]), 'little'))
        for sym in wanted:
            where = next(iter(refs[sym])) if len(refs.get(sym, ())) == 1 else ''
            folded = not where and len(through.get(sym, ())) == 1     # table entry: identical invokers/managers fold (ICF)
            if folded:
                where = next(iter(through[sym]))
            if not re.fullmatch(r'[0-9a-f]{8}', where):
                continue
            eh = sym.startswith('__ehhandler$')
            # ICF folds identical template bodies to one address: two bind_t copy ctors (??0?$bind_t@) or two
            # storage2 dtors (??1?$storage2@) share a mangled prefix but differ in template arguments. A byte-equal
            # body referencing that exact address with a sibling symbol is as much proof as the existing row; only a
            # different *kind* of symbol at the address must block the binding.
            sibling = lambda s: not PLACEHOLDER.search(s) and s[:13] == sym[:13]
            if not eh and not folded and any(s != sym and not PLACEHOLDER.search(s) and not sibling(s)
                                               for s in bound_at(where)):
                continue
            out.append({'symbol': sym, 'address': where, 'votes': 1, 'identity_evidence':
                        ('push -1; push handler prologue immediate of original body ' + addr) if eh else
                        'exact-target-coff-reference-alias (functor_lane: byte-equal body at %s references it here)' % addr})
    return out


def write(unit, addr, functor, hdrs, chosen, note):
    unit.write_text(FLAGS + '\n// %s: boost machinery instantiated for the functor whose typeid the binary names here '
                    '(functor_lane.py, no model)%s\n' % (addr, note)
                    + ''.join('#include %s\n' % e for e in STD) + ''.join('#include "%s"\n' % h for h in hdrs)
                    + 'typedef %s F;\n' % functor + ''.join(line + '\n' for line in chosen), encoding='utf-8')


def compile_unit(unit, folder):
    """(object, '') or (None, errors).  VS2008 accepts the explicit instantiation of the SFINAE constructor template
    only in about half of its runs (C2770 on the very same file), so that one error is retried."""
    errors = ''
    for _ in range(8):
        job_dir = folder / ('job-%s' % uuid.uuid4().hex[:10])
        try:
            job = RUNNER.compile_job({'source': str(unit), 'checks': [], 'ranges': [], 'layouts': []}, job_dir, TC)
        except Exception as error:                                   # noqa: BLE001
            return None, repr(error)
        obj = Path(str(job.get('object') or ''))
        if obj.is_file():
            return obj, ''
        errors = ' | '.join(agent_prove.compile_errors(job_dir, '')[:3])
        shutil.rmtree(job_dir, ignore_errors=True)
        if 'C2770' not in errors:
            break
    return None, errors


def one(item):
    addr, rule, identity = item
    functor = spell(identity)
    sig = signature(functor)
    if not sig:
        return addr, 'not a boost functor identity', functor[:80]
    final = CLASSES / ('FunctorInst_%s.cpp' % addr)
    if final.is_file():
        return addr, 'already present', ''
    hdrs = includes(functor)
    if 'util/NativeContentProvider.h' in hdrs:
        # NativeContentProvider.h includes Instance.h and can conflict if earlier headers define ContentProvider.
        hdrs = ['util/NativeContentProvider.h'] + [h for h in hdrs if h not in ('util/NativeContentProvider.h', 'v8tree/Instance.h')]
    table = lines(functor, *sig)
    folder = HERE / 'lane-drafts' / final.stem
    folder.mkdir(parents=True, exist_ok=True)
    unit = folder / final.name

    def fail(status, text=''):
        unit.unlink(missing_ok=True)
        shutil.rmtree(HERE / 'prove-out' / ('prove-' + final.stem), ignore_errors=True)
        return addr, status, text.replace('\n', ' | ')[:300]

    while LOCK.is_file():
        time.sleep(30)
    write(unit, addr, functor, hdrs, table.values(), '')
    obj, errors = compile_unit(unit, folder)
    clash = re.match(r'([\w.]+)\(\d+\): error C2011', errors)
    if not obj and clash:                       # two headers define one class: drop the one that redefines it
        name = clash.group(1)
        if any(h.endswith(name) for h in hdrs):
            i = next(i for i, h in enumerate(hdrs) if h.endswith(name))
            # error reported at redefinition site: earlier headers caused it, so keep this header and drop before it
            hdrs = hdrs[i:]
        else:
            hdrs = [h for h in hdrs if not h.endswith(name)]
        write(unit, addr, functor, hdrs, table.values(), '')
        obj, errors = compile_unit(unit, folder)
    if not obj:
        return fail('COMPILE FAILED', errors)
    found = {}
    for sym in byte_equal(obj, addr):
        key = classify(sym)
        if key and key in table:
            found.setdefault(key, sym)
    # a caller that is byte-equal to the emitted slot / function<Sig> constructor reaches this body through the
    # signal path, whose function<Sig> uses boost's default std::allocator<void>
    callers = re.findall(r'sub_([0-9a-f]{8})', ' '.join(EVIDENCE.get(addr, {}).get('caller') or []))
    via_signal = [c for c in callers for sym in byte_equal(obj, c) if (classify(sym) or ('', '', ''))[:2] in (('slot', ''), ('ctor', 'function'))]
    shutil.rmtree(obj.parent, ignore_errors=True)
    if not found:
        return fail('no emitted instantiation is byte-equal at this address')
    already = [s for s in bound_at(addr) if not PLACEHOLDER.search(s)]
    by_ref = [k for k, s in found.items() if s in already]
    if already and not by_ref:
        return fail('address is bound to another symbol', already[0][:200])
    # no reference names the symbol yet: boost's default allocator for the class the bytes select
    # (functionN: std::allocator<function_base>, function<Sig>: std::allocator<void>)
    key = by_ref[0] if by_ref else min(found, key=lambda k: k[2] != ('void' if k[1] == 'function' or via_signal else 'fb'))
    sym = found[key]
    twins = sorted(k for k in found if k != key)
    evidence = ('typeid: the boost::function manager for this body compares typeid(%s) (%s); byte-equal %s of that functor%s'
                % (functor[:150], rule, key[0],
                   '' if by_ref or not twins else '; INFERRED: allocator/class %s chosen over byte-identical %s (%s)' % (key[1:], twins,
                       'caller %s is the signal slot/function<Sig> constructor' % via_signal[0] if via_signal else 'boost default')))
    chosen = table[key]
    if key[0] == 'ctor':
        # VS2008 refuses the explicit instantiation of the SFINAE constructor template on many runs (C2770, depends on
        # the file name).  Its real parents emit it as their callee, deterministically: the signal slot constructor
        # (when the body is on the signal path) and thread_specific_ptr's constructor.
        parents = [k for k in (('tss', '', 'fb'), ('slot', '', 'void')) if k in table
                   and (k[0] == 'tss' or key[1:] == ('function', 'void') or via_signal)]
        for parent in parents:
            write(unit, addr, functor, hdrs, [table[parent]], '')
            obj, _ = compile_unit(unit, folder)
            emitted = bool(obj) and sym in byte_equal(obj, addr)
            if obj:
                shutil.rmtree(obj.parent, ignore_errors=True)
            if emitted:
                chosen = table[parent] + '      // emits the %s constructor at %s as its callee' % (key[1], addr)
                break
    write(unit, addr, functor, hdrs, [chosen],
          '' if by_ref or not twins else '\n// INFERRED: %s (%s) over the byte-identical %s'
          % (ALLOC[key[2]], 'signal path: caller %s' % via_signal[0] if via_signal else 'boost default', twins))
    mine = not by_ref
    if mine:
        bind([{'symbol': sym, 'address': addr, 'votes': 1, 'identity_evidence': evidence}])
    manifest = HERE / 'prove-out' / ('prove-' + final.stem) / 'manifest.json'
    status = text = ''
    for _ in range(3):
        for _ in range(8):
            status, text = agent_prove.verdict(unit, {addr: sym[:60]})[addr]
            if not (status == 'COMPILE FAILED' and 'C2770' in text):
                break
        if status != 'REJECTED':
            break
        rows = ref_rows(manifest, addr)
        if not rows:
            break
        bind(rows)
    if status != 'EXACT':
        if mine:
            unbind(sym, addr)
        return addr, 'byte-equal, not proven: ' + status, text.replace(chr(10), ' | ')[:300]      # draft + proof stay for diagnosis
    shutil.move(str(unit), str(final))
    rel = final.relative_to(ROOT).as_posix()
    shared_json.update(HERE / 'class-lane-new-sources.json', lambda lst: lst if rel in lst else lst + [rel], [])
    return addr, 'EXACT', '%s %s' % (key, sym[:120])


def guarded(item):
    try:
        return one(item)
    except Exception as error:                                   # noqa: BLE001  one address never stops the lane
        import traceback
        return item[0], 'lane error', repr(error)[:120] + ' @ ' + ' <- '.join(l.strip() for l in traceback.format_exc().splitlines()[-5:-1])[:300]


def demo():
    f = ('boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::ViewNew::ViewRbxGfx,bool>,'
         'boost::_bi::list2<boost::_bi::value<RBX::ViewNew::ViewRbxGfx *>,boost::arg<1> > >')
    assert signature(f) == ('void', ['bool'])
    assert signature('boost::_bi::bind_t<void,void (*)(boost::shared_ptr<X>,int),boost::_bi::list2<boost::arg<1>,'
                     'boost::_bi::value<int> > >') == ('void', ['boost::shared_ptr<X>'])
    assert signature('RBX::Reflection::SignalDescImpl<2,void (float,float)>::GenericSlotAdapter') == ('void', ['float', 'float'])
    assert signature('RBX::Reflection::SignalDescImpl<0,void (void)>::GenericSlotAdapter') == ('void', [])
    assert classify('??$assign_to@Vx@@@?$function1@X_NV?$allocator@X@std@@@boost@@AAEXABVx@@@Z') == ('assign', 'functionN', 'void')


demo()
if __name__ == '__main__':
    unique = json.loads((HERE / 'research-twins/identities.json').read_text())['unique']
    done_path = HERE / 'functor-lane-done.json'
    done = json.loads(done_path.read_text()) if done_path.is_file() else {}
    rank = lambda rule: 0 if rule.startswith('via-') else 1 if rule == 'functor' else 2      # callers before callees
    todo = [(a, v['rule'], v['identity']) for a, v in sorted(unique.items(), key=lambda kv: (rank(kv[1]['rule']), kv[0]))
            if (v['rule'] in ('functor', 'typeid') or v['rule'].startswith('via-'))
            and (a in args.only.split(',') if args.only else a not in done)]
    todo = todo[:args.limit or None]
    print('functor lane: %d addresses' % len(todo), flush=True)
    exact = 0
    with ThreadPoolExecutor(args.jobs) as pool:
        for addr, status, detail in pool.map(guarded, todo):
            exact += status == 'EXACT'
            done[addr] = status + (' | ' + detail if detail else '')
            done_path.write_text(json.dumps(done, indent=1))
            print(addr, status, detail, flush=True)
    print('RESULT functor lane: %d exact of %d' % (exact, len(todo)), flush=True)
