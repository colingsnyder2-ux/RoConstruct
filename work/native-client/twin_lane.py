"""Twin lane (no model).  Many remaining functions are members of class-template instantiations whose registry names
are wrong; their bodies are byte-identical twins, so only the binary says which instantiation each address is.
research-twins/identities.json gives that identity from RTTI: the body stores a vftable whose type descriptor names
the class (`RBX::Reflection::BoundFuncDesc<DHTMLWindow, void(void), 0>` ...).

For each such address: a unit that includes the native headers declaring the template and the classes named in its
arguments, plus `template class <identity>;` (explicit instantiation emits every member).  Compile (5 s), prove once,
bind the symbol the prover found byte-equal at that address (evidence: RTTI identity), prove again, keep only exact.
Unproved drafts stay in lane-drafts/.  Files: rebuild/2008-06/native-classes/TwinInst_<addr>.cpp
  python work/native-client/twin_lane.py [--limit N] [--jobs 2] [--only ADDR,ADDR]"""
import argparse
import collections
import json
import re
import shutil
import subprocess
import sys
import time
import uuid
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
ap = argparse.ArgumentParser()
ap.add_argument('--limit', type=int, default=0)
ap.add_argument('--jobs', type=int, default=2)
ap.add_argument('--only', default='')
args = ap.parse_args()
sys.argv = sys.argv[:1]
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(ROOT))
import agent_prove  # noqa: E402
import shared_json  # noqa: E402
from roc import native_bulk, rebuild  # noqa: E402

RUNNER = native_bulk.checker()
TC = rebuild.toolchain(21022)
CLASSES = ROOT / 'rebuild/2008-06/native-classes'
HEADERS = ROOT / 'rebuild/2008-06/native-headers'
LOCK = HERE / 'prove-out/CENSUS.lock'
FLAGS = '// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS'
NONTYPE = re.compile(r'&[^,<>]*?((?:\w+::)*\w+)(?=\s*[,>])')
DEFINES = re.compile(r'^\s*(?:template\s*<[^;{]*>\s*)?(?:class|struct)\s+(?:\w+\s+)?(\w+)\s*(?:<[^;{]*?>\s*)?(?:final\s*)?(?::[^;{]*)?\{', re.M)   # <...>: partial specializations
DIFFERS = re.compile(r'reference identity differs: (\S+) \(bound ([0-9a-f]{8}), original reference ([0-9a-f]{8})\)')
STD_INCLUDES = [('boost::any', '<boost/any.hpp>'), ('boost::_bi', '<boost/bind.hpp>'), ('boost::function', '<boost/function.hpp>'),
                ('boost::shared_ptr', '<boost/shared_ptr.hpp>'), ('std::basic_string', '<string>'), ('std::vector', '<vector>'),
                ('RBX::TextureId', '"util/TextureId.h"')]
# per-template compiler flags the binary proves.  TypedStatsItem: its boost::function0 member stores a constant
# {manager, invoker} table from .rdata (00819ce4) with no init guard = boost 1.35 `static const vtable_type`; the
# default boost 1.34.1 (`static vtable_type stored_vtable(f)`) keeps assign_to out of line (120 bytes, target 194).
LEAF_FLAGS = {'TypedStatsItem': ' /I{headers}/../../../tools/libs/boost_1_35_0'}


def header_index():
    """class/struct name -> native headers that define it (shortest path first)."""
    index = collections.defaultdict(list)
    for path in sorted(HEADERS.rglob('*.h'), key=lambda p: len(str(p))):
        try:
            text = path.read_text(errors='replace')
        except OSError:
            continue
        # classes, and the class-name arrays used as template arguments (`extern const char sSnap[];`)
        for name in set(DEFINES.findall(text)) | set(re.findall(r'\bextern\s+(?:const\s+)?char\s+(\w+)\s*\[', text)):
            index[name].append(path.relative_to(HEADERS).as_posix())
    # classes that exist only inside a native unit (SurfaceDescriptor ...): include that unit, with its flags
    for path in sorted(CLASSES.glob('*.cpp'), key=lambda p: p.stat().st_size):
        if path.name.startswith(('Thunk_', 'WF_', 'TwinInst_', 'TmplInst_', 'CloneProp_', 'DonorCtx_')):
            continue
        try:
            text = path.read_text(errors='replace')
        except OSError:
            continue
        for name in set(DEFINES.findall(text)):
            if name not in index:
                UNITS.setdefault(name, path)
    return index


UNITS = {}
INDEX = header_index()
INDEX.setdefault('Bridge', ['lua/LuaBridge.h'])
INDEX.setdefault('SharedPtrBridge', ['lua/LuaBridge.h'])

BRIDGE_MAP = {
    'EnumItem': ('RBX::Lua::Bridge<RBX::Lua::EnumDescriptorItemPtr, true>', ['LuaBridge2008/LuaEnumBridge2008.h']),
    'Enums': ('RBX::Lua::Bridge<RBX::Lua::AllEnumDescriptorsPtr, true>', ['LuaBridge2008/LuaEnumBridge2008.h']),
    'Enum': ('RBX::Lua::Bridge<RBX::Lua::EnumDescriptorPtr, true>', ['LuaBridge2008/LuaEnumBridge2008.h']),
    'RBXScriptConnection': ('RBX::Lua::Bridge<boost::signals::connection, true>', ['lua/LuaBridge.h', '<boost/signals/connection.hpp>']),
    'Color3': ('RBX::Lua::Bridge<G3D::Color3, true>', ['lua/LuaBridge.h', '<g3d/color3.h>']),
    'BrickColor': ('RBX::Lua::Bridge<RBX::BrickColor, true>', ['lua/LuaBridge.h']),
    'shared_ptr<ThreadRef::Node>': ('RBX::Lua::Bridge<boost::shared_ptr<RBX::Lua::ThreadRef::Node>, true>', ['lua/LuaBridge.h', '"script/ThreadRef.h"']),
    'Object': ('RBX::Lua::Bridge<boost::shared_ptr<RBX::Reflection::DescribedBase>, false>', ['lua/LuaBridge.h']),
    'RBXScriptSignal': ('RBX::Lua::Bridge<boost::shared_ptr<RBX::Reflection::SignalInstance>, false>', ['lua/LuaBridge.h']),
    'CFrame': ('RBX::Lua::Bridge<G3D::CoordinateFrame, true>', ['lua/LuaBridge.h', '<g3d/coordinateframe.h>']),
    'Vector3': ('RBX::Lua::Bridge<G3D::Vector3, true>', ['lua/LuaBridge.h', '<g3d/vector3.h>']),
}


def spell(identity):
    if identity in BRIDGE_MAP:
        identity = BRIDGE_MAP[identity][0]
    text = re.sub(r'\s*\[subobject [^\]]*\]', '', identity).strip()
    text = NONTYPE.sub(r'\1', text)
    return re.sub(r'^(?:class|struct)\s+', '', text)


def includes(cls):
    out = []
    for name in dict.fromkeys(re.findall(r'(?<!std::)(?<!boost::)(?<!G3D::)\b[A-Za-z_]\w*', cls)):   # std/boost names: STD_INCLUDES
        if name in UNITS and UNITS[name].name not in out:
            out.append(UNITS[name].name)
        for header in INDEX.get(name, [])[:1]:
            if header not in out:
                out.append(header)
    extra = [inc for key, inc in STD_INCLUDES if key in cls]
    extra += ['<G3D/%s.h>' % n for n in dict.fromkeys(re.findall(r'G3D::(\w+)', cls))]   # G3D: one header per class
    return extra, out[:10]


def template_args(cls):
    inner = cls[cls.index('<') + 1:cls.rindex('>')]
    out, depth, cur = [], 0, ''
    for ch in inner:
        depth += ch in '<('
        depth -= ch in '>)'
        if ch == ',' and depth == 0:
            out.append(cur.strip())
            cur = ''
        else:
            cur += ch
    return out + [cur.strip()]


def plain(arg):
    return re.sub(r'^(?:class|struct|enum)\s+', '', arg)


def member_templates(cls, leaf):
    """Explicit instantiations of constructor TEMPLATES (`template class X;` does not emit those).  The property
    descriptor constructors are templates over the getter/setter pointer TYPES, which follow from the class and
    value type; the usual spellings are all requested and the proof picks the one at the address."""
    a = template_args(cls)
    func = 'RBX::Reflection::PropertyDescriptor::Functionality'
    if leaf == 'EnumPropDescriptor' and len(a) == 2:
        c, e = plain(a[0]), plain(a[1])
        return ['template %s::EnumPropDescriptor(char const*, char const*, %s, %s, %s);' % (cls, g, st, func)
                for g in ('%s (%s::*)() const' % (e, c), '%s (%s::*)()' % (e, c))
                for st in ('void (%s::*)(%s)' % (c, e), 'void (%s::*)(%s const&)' % (c, e))]
    if leaf in ('FactoryProduct', 'DescribedCreatable', 'NonFactoryProduct', 'DescribedNonCreatable'):
        # forwarding constructor template `Leaf(T arg) : Base(arg)`: T is the parameter type of a one-argument
        # constructor of the base class, as its native header declares it (`Base(Joint* joint);`)
        # ponytail: single-token parameter types only (`T`, `T*`, `T&`); widen the regex when a base needs `const T&`
        name = plain(a[0] if leaf == 'NonFactoryProduct' else a[1]).rsplit('::', 1)[-1]
        text = ''.join((HEADERS / h).read_text(errors='replace') for h in INDEX.get(name, [])[:1])
        types = dict.fromkeys(re.findall(r'\b%s\s*\(\s*([\w:]+(?:\s*[*&]|\s+(?=\w)))\s*\w*\s*\)\s*[;:{]' % name, text))
        ns = cls.split('<')[0].rpartition('::')[0]
        return ['namespace %s { template %s::%s(%s); }' % (ns, cls, leaf, t.strip()) for t in types] if ns else []
    # INFERRED: boost::any::holder<ValueType> constructor template is not emitted by `template class holder<T>;`
    # The holder class (from <boost/any.hpp>) has: holder(const ValueType&) : held(value) {}
    # We must explicitly instantiate this constructor template for each ValueType.
    # Note: parameter type is ValueType const& (not const ValueType&) to correctly handle pointer-to-const types.
    if leaf == 'holder' and len(a) == 1:
        vt = plain(a[0])
        return ['template boost::any::holder<%s>::holder(%s const&);' % (vt, vt)]
    # INFERRED: Creatable<Instance>::create<TypedStatsItem<T>, boost::function0<T>> is a static member function
    # template not emitted by `template class TypedStatsItem<T>;`. The binary shows these at 005a4af0 (double),
    # 005a4bd0 (float), 005a4cb0 (int) - byte-identical twins calling the respective constructors.
    if leaf == 'TypedStatsItem' and len(a) == 1:
        t = plain(a[0])
        func0 = 'boost::function0<%s, std::allocator<boost::function_base> >' % t
        shared_ptr = 'boost::shared_ptr<%s>' % cls
        return ['template %s RBX::Creatable<RBX::Instance>::create<%s, %s>(%s);' % (shared_ptr, cls, func0, func0)]
    if leaf == 'Bridge' and len(a) == 2:
        t = plain(a[0])
        tag = a[1].strip()
        lines = ['template bool RBX::Lua::Bridge<%s, %s>::getValue<RBX::Reflection::Value>(lua_State*, size_t, RBX::Reflection::Value&);' % (t, tag)]
        m = re.match(r'boost::shared_ptr<(.+)>', t)
        if m:
            u = m.group(1)
            lines.append('template class RBX::Lua::SharedPtrBridge<%s>;' % u)
            lines.append('template bool RBX::Lua::SharedPtrBridge<%s>::getPtr<RBX::Reflection::Value>(lua_State*, size_t, RBX::Reflection::Value&);' % u)
        return lines
    return []


def unit_flags(headers):
    """flags line of the smallest proved unit that already includes one of these headers (include order, /D, /FI)"""
    names = [Path(h).name for h in headers if h.endswith('.h')]
    found = {}
    for path in sorted(CLASSES.glob('*.cpp'), key=lambda q: q.stat().st_size):
        if path.name.startswith(('Thunk_', 'WF_', 'TwinInst_')) or path.stat().st_size > 40000:
            continue
        head = path.read_text(errors='replace')[:3000]
        for n in names[-2:]:
            if head.startswith('// native-flags:') and n not in found and ('/' + n + '"' in head or '"' + n + '"' in head):
                found[n] = head.split('\n', 1)[0].rstrip()
    return next((found[n] for n in reversed(names[-2:]) if n in found), None)   # the argument class's own header first (its include paths)


def bind(rows):
    while LOCK.is_file():
        time.sleep(30)

    def add(doc):
        have = {(r.get('symbol'), r.get('address')) for r in doc['identity_bindings']}
        doc['identity_bindings'] += [r for r in rows if (r['symbol'], r['address']) not in have]
        return doc
    shared_json.update(HERE / 'class-identity-bindings.json', add)


def symbols_at(manifest, addr):
    """symbols the prover found byte-equal at ADDR: (exact?, symbol)."""
    try:
        rows = json.loads(manifest.read_text(encoding='utf-8'))['families'][0]['symbols']
    except (OSError, ValueError, KeyError, IndexError):
        return []
    out = []
    for r in rows:
        if r.get('status') == 'inactive_exact' and r.get('addr') == addr:
            out.append((True, r['symbol']))
        elif addr in (r.get('candidates') or []) or any(q.get('addr') == addr for q in r.get('rejections') or []):
            out.append((False, r['symbol']))
    return out


def primary_vftables(manifest, addr):
    """The registry names the offset-0 vftable `??_7X@@6B@` (rtti-primary-vtable).  For a class with several vftables
    MSVC gives that name to a secondary one (the others carry a base path): a byte-equal constructor stores it where
    the original stores a vftable whose RTTI locator has a non-zero offset and the same type.  Bind it there."""
    registry = json.loads((ROOT / 'work/2008-06/identity-registry.json').read_text())
    rows = []
    for r in json.loads(manifest.read_text(encoding='utf-8'))['families'][0]['symbols']:
        for rej in r.get('rejections') or []:
            for sym, was, orig in DIFFERS.findall(' '.join(rej.get('errors', [])) if rej.get('addr') == addr else ''):
                a, b = registry.get(was) or {}, registry.get(orig) or {}
                col = lambda row: next((e for e in row.get('evidence', []) if e.get('kind') == 'rtti-complete-object-locator'), {})
                if (sym.startswith('??_7') and sym.endswith('@6B@') and a.get('name_source') == 'rtti-primary-vtable'
                        and col(b).get('offset') and col(b).get('raw_type') == col(a).get('raw_type')):
                    rows.append({'symbol': sym, 'address': orig, 'votes': 1, 'identity_evidence':
                                 'vftable stored by the byte-equal constructor %s at the offset of RTTI locator %s (offset %d, '
                                 'same type as the primary vftable %s)' % (addr, col(b)['locator'], col(b)['offset'], was)})
    return rows


def reference_aliases(manifest, addr):
    """Identities of what the byte-equal body references (base constructor, vftable slots: adjustor thunks, virtuals),
    read from the ORIGINAL relocation/data words at the same edges by native_reference_alias_bind.py."""
    objs = sorted(manifest.parent.glob('objects/*/candidate.obj'), key=lambda q: q.stat().st_mtime)
    mine = [sym for ok, sym in symbols_at(manifest, addr)]
    if not objs or not mine:
        return []
    receipt = manifest.parent / 'alias-bind.json'
    receipt.unlink(missing_ok=True)
    subprocess.run([sys.executable, str(HERE / 'native_reference_alias_bind.py'), '--object', str(objs[-1]), '--symbol', mine[0],
                    '--address', addr, '--closure', str(HERE / 'claude-identity-closure-llm.json'),
                    '--owner-evidence', str(HERE / 'class-identity-bindings.json'), '--output', str(receipt)],
                   cwd=ROOT, capture_output=True, text=True)
    try:
        return [dict(b, votes=1, identity_evidence='twin lane alias for %s: %s' % (addr, b.get('identity_evidence', 'exact-target-coff-reference-alias')))
                for b in json.loads(receipt.read_text()).get('identity_bindings', [])]
    except (OSError, ValueError):
        return []


def one(item):
    addr, identity = item
    extra_headers = BRIDGE_MAP.get(identity, (None, []))[1] if identity in BRIDGE_MAP else []
    cls = spell(identity)
    leaf = re.sub(r'<.*', '', cls).rsplit('::', 1)[-1]
    if leaf not in INDEX and leaf not in UNITS and leaf != 'CXTPBatchAllocManagerT':
        return addr, 'no native header declares ' + leaf, ''
    extra, hdrs = includes(cls)
    hdrs = list(dict.fromkeys(extra_headers + hdrs))
    flags = (unit_flags(hdrs) or FLAGS) + LEAF_FLAGS.get(leaf, '')
    if leaf == 'CXTPBatchAllocManagerT':
        hdrs = ['<XTToolkitPro.h>']
        flags = (CLASSES / 'XTPBatchAllocManagerReport.cpp').read_text().splitlines()[0]
    units = [h for h in hdrs if h.endswith('.cpp')]
    if units:                                   # a class defined inside a unit: compile with that unit's flags
        first = (CLASSES / units[0]).read_text(errors='replace').split('\n', 1)[0]
        flags = first.rstrip() if first.startswith('// native-flags:') else FLAGS
        if '/I{headers}/../native-classes' not in flags:
            flags += ' /I{headers}/../native-classes'
    final = CLASSES / ('TwinInst_%s.cpp' % addr)
    if final.is_file():
        return addr, 'already present', ''
    folder = HERE / 'lane-drafts' / final.stem
    folder.mkdir(parents=True, exist_ok=True)
    unit = folder / final.name
    while LOCK.is_file():
        time.sleep(30)
    write = lambda hdrs: unit.write_text(flags + '\n// %s: explicit instantiation of the class the body at %s stores the vftable of (RTTI identity, twin_lane.py, '
                    'no model)\n' % (addr, addr) + ''.join('#include %s\n' % e for e in extra)
                    + ''.join(('#include %s\n' if h.startswith('<') else '#include "%s"\n') % h for h in hdrs) + 'template class %s;\n' % cls
                    + ''.join(line + '\n' for line in member_templates(cls, leaf)), encoding='utf-8')
    write(hdrs)

    def fail(status, text=''):
        unit.unlink(missing_ok=True)
        shutil.rmtree(HERE / 'prove-out' / ('prove-' + final.stem), ignore_errors=True)
        return addr, status, text.replace('\n', ' | ')[:300]

    job_dir = folder / ('job-%s' % uuid.uuid4().hex[:10])
    try:
        job = RUNNER.compile_job({'source': str(unit), 'checks': [], 'ranges': [], 'layouts': []}, job_dir, TC)
        obj = Path(str(job.get('object') or ''))
    except Exception as error:                                   # noqa: BLE001
        return fail('compile harness error', repr(error))
    if not obj.is_file() and len(hdrs) > 1:      # winsock/MFC include order: retry with the argument classes' headers first
        write(hdrs[::-1])
        job_dir = folder / ('job-%s' % uuid.uuid4().hex[:10])
        try:
            obj = Path(str(RUNNER.compile_job({'source': str(unit), 'checks': [], 'ranges': [], 'layouts': []}, job_dir, TC).get('object') or ''))
        except Exception as error:                               # noqa: BLE001
            return fail('compile harness error', repr(error))
    if not obj.is_file():
        return fail('COMPILE FAILED', ' | '.join(agent_prove.compile_errors(job_dir, '')[:3]))
    manifest = HERE / 'prove-out' / ('prove-' + final.stem) / 'manifest.json'
    status, text = agent_prove.verdict(unit, {addr: leaf})[addr]
    found = symbols_at(manifest, addr)
    if not any(ok for ok, _ in found):
        mine = [sym for ok, sym in found if leaf in sym]
        if not mine:
            return fail('no emitted member is byte-equal at this address', text)
        bind([{'symbol': mine[0], 'address': addr, 'votes': 1, 'identity_evidence':
               'RTTI: the body at this address stores the vftable of %s; byte-equal member of that instantiation' % cls[:160]}])
        status, text = agent_prove.verdict(unit, {addr: leaf})[addr]
        found = symbols_at(manifest, addr)
    for learn in (primary_vftables, reference_aliases):         # constructors: the vftables they store and their slots
        rows = [] if any(ok for ok, _ in found) else learn(manifest, addr)
        if rows:
            bind(rows)
            status, text = agent_prove.verdict(unit, {addr: leaf})[addr]
            found = symbols_at(manifest, addr)
    if not any(ok for ok, _ in found):
        return fail('byte-equal, not proven: ' + status, text)
    shutil.move(str(unit), str(final))
    rel = final.relative_to(ROOT).as_posix()
    shared_json.update(HERE / 'class-lane-new-sources.json', lambda lst: lst if rel in lst else lst + [rel], [])
    return addr, 'EXACT', next(sym for ok, sym in found if ok)[:120]


def guarded(item):
    try:
        return one(item)
    except Exception as error:                                   # noqa: BLE001  one address never stops the lane
        import traceback
        return item[0], 'lane error', repr(error)[:120] + ' @ ' + ' <- '.join(l.strip() for l in traceback.format_exc().splitlines()[-5:-1])[:300]


unique = json.loads((HERE / 'research-twins/identities.json').read_text())['unique']
done_path = HERE / 'twin-lane-done.json'
done = json.loads(done_path.read_text()) if done_path.is_file() else {}
_family = collections.Counter(re.sub(r'<.*', '', spell(v['identity'])) for v in unique.values() if v['rule'] == 'rtti')
# Family boost_functor_pieces_TypedStatsItem: also include these via-callee addresses (same template instantiations as rtti constructors)
_via_callee_family = {'005a4af0', '005a4bd0', '005a4cb0'}
todo = [(a, v['identity']) for a, v in sorted(unique.items(), key=lambda kv: (-_family[re.sub(r'<.*', '', spell(kv[1]['identity']))], kv[0]))
        if (v['rule'] == 'rtti' or a in _via_callee_family) and '<' in v['identity']
        and (a in args.only.split(',') if args.only else a not in done)]
todo = todo[:args.limit or None]
print('twin lane: %d addresses' % len(todo), flush=True)
exact = 0
with ThreadPoolExecutor(args.jobs) as pool:
    for addr, status, detail in pool.map(guarded, todo):
        exact += status == 'EXACT'
        done[addr] = status + (' | ' + detail if detail else '')
        done_path.write_text(json.dumps(done, indent=1))
        print(addr, status, detail, flush=True)
print('RESULT twin lane: %d exact of %d' % (exact, len(todo)), flush=True)
