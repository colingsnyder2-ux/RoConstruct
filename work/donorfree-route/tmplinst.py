"""python tmplinst.py [--max N]: resolve stubbed STL/Ogre TEMPLATE members by explicit instantiation. The original exe
compiled std::_Tree<...Ogre::X*...>, std::vector<Ogre::Y>, Ogre::ConstMapIterator<...> members into itself; converted
objects reference them by name but their bodies were dropped as helpers, so they link as stubs (~5,900 today).
For every distinct class template instance among the stubbed names (from linkexp/qt.map *stubs*.obj symbols): demangle
(VS2005 undname, back-reference bug patched), emit `template class <instance>;` in its own TU with the Ogre client-import
+ STL headers, compile in parallel (VS2008 RTM, the natives' Ogre flags), keep the ones that compile, archive them
into linkexp/tmplinst.lib. quicktest.py links it after every real object (COMDAT: real definitions still win).
Writes auto/tmplinst.json (ok / failed classes). Re-runs reuse compiled objects (cache key: instance text)."""
import hashlib, json, os, re, subprocess, sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
H = Path(__file__).parent
ROOT = H.parents[1]
sys.path.insert(0, str(ROOT))
from roc import rebuild
OUT = H / 'linkexp/tmplinst'
OUT.mkdir(parents=True, exist_ok=True)
MAX = int(sys.argv[sys.argv.index('--max') + 1]) if '--max' in sys.argv else 100000
UND = str(ROOT / 'tools/msvc800sp1/VC/bin/undname.exe')

stub = set()
for l in (H / 'linkexp/qt.map').read_text(errors='replace').splitlines():
    p = l.split()
    if len(p) >= 4 and ':' in p[0] and p[-1].lower().endswith(('stubs.obj', 'stubs2.obj')) and '?$' in p[1]:
        stub.add(p[1])
names = sorted(n for n in stub if n.startswith('?') and not n.startswith('??$'))   # members of class templates


def demangle(batch):
    out = subprocess.run([UND] + batch, capture_output=True, text=True).stdout
    return re.findall(r'is :- "(.*)"', out)


dem = {}
B = 40
for i in range(0, len(names), B):
    part = names[i:i + B]
    res = demangle(part)
    if len(res) == len(part):
        dem.update(zip(part, res))


def fix(s):
    # VS2005 undname resolves some template back-references to the wrong scope: Foo::less<..> / Foo::allocator<..>
    return re.sub(r'\b\w+::(less|allocator|char_traits|basic_string|pair|equal_to|hash_compare)<', r'std::\1<', s)


def class_of(sig):
    """'... __thiscall std::_Tree<...>::clear(void)' -> 'std::_Tree<...>' (qualified class, nested classes included)"""
    i = sig.find('(')
    head = sig[:i] if i > 0 else sig
    depth, last, start = 0, -1, 0
    for k, ch in enumerate(head):
        if ch == '<':
            depth += 1
        elif ch == '>':
            depth -= 1
        elif depth == 0 and ch == ' ':
            start = k + 1
        elif depth == 0 and head[k:k + 2] == '::':
            last = k
    if last <= start:
        return None
    return head[start:last]


classes = {}
for n, s in dem.items():
    c = class_of(fix(s))
    if c and '<' in c and not c.startswith(('`', 'RBX::', 'G3D::')) and 'RBX::' not in c and '`' not in c:
        classes.setdefault(c, []).append(n)
order = sorted(classes, key=lambda c: -len(classes[c]))[:MAX]
print('%d stubbed template members, %d demangled, %d distinct class instances' % (len(names), len(dem), len(classes)))

# the natives' own compiler flags (rbxgs defines, boost/G3D/MFC/XTP include paths) with the Ogre client-import profile
sys.path.insert(0, str(ROOT / 'rebuild/2008-06/tests'))
import native_check_runner as _ncr
_prof = OUT / 'profile.cpp'
_prof.write_text('// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include' + chr(10))
FLAGS = _ncr.compiler_flags(_prof)
PRE = chr(10).join(['#undef OGRE_NONCLIENT_BUILD', '#define NOMINMAX', '#include <winsock2.h>', '#include <map>', '#include <vector>', '#include <list>', '#include <set>', '#include <deque>', '#include <string>', '#include <boost/shared_ptr.hpp>', '#include <boost/weak_ptr.hpp>', '#include <boost/function.hpp>', '#include <G3D/ReferenceCount.h>', '#include <G3D/Vector3.h>', '#include <Ogre.h>', '#include <OgreStaticGeometry.h>']) + chr(10)
tc = rebuild.toolchain(21022)


def build(c):
    k = hashlib.md5(c.encode()).hexdigest()[:16]
    obj = OUT / (k + '.obj')
    if obj.exists():
        return c, True, ''
    fail = OUT / (k + '.fail')   # failures cached too: re-runs compile only new instances
    if fail.exists():
        return c, False, fail.read_text()
    src = OUT / (k + '.cpp')
    src.write_text(PRE + 'template class %s;\n' % c.replace('class ', '').replace('struct ', '').replace('enum ', ''))
    code, text = rebuild.run(tc, 'cl', FLAGS + ['/Fo' + str(obj), str(src)], OUT)
    if code or not obj.exists():
        obj.unlink(missing_ok=True)
        err = '\n'.join(l for l in text.splitlines() if 'error' in l)[:300]
        fail.write_text(err)
        return c, False, err
    return c, True, ''


INLINE_ONLY = '--inline' in sys.argv or '--rbx' in sys.argv   # the template archive is already built: skip straight to the inline pass
if INLINE_ONLY:
    order = []
with ThreadPoolExecutor(max_workers=int(os.environ.get('TI_JOBS', '12'))) as ex:
    res = list(ex.map(build, order))
ok = [c for c, g, _ in res if g]
covered = sum(len(classes[c]) for c in ok)
objs = [str(OUT / (hashlib.md5(c.encode()).hexdigest()[:16] + '.obj')) for c in ok]
lib = H / 'linkexp/tmplinst.lib'
if objs and not INLINE_ONLY:
    rsp = OUT / 'lib.rsp'
    rsp.write_text('\n'.join('"%s"' % o for o in objs))
    code, text = rebuild.run(tc, 'lib', ['/nologo', '/OUT:' + str(lib), '@' + str(rsp)], OUT)
    if code:
        print('lib failed:', text[:300])
INLINE_ONLY or (H / 'auto/tmplinst.json').write_text(json.dumps({'ok': ok, 'failed': {c: e for c, g, e in res if not g}}, indent=1))
print('instantiated %d / %d classes, covering %d of %d stubbed template members -> %s' % (len(ok), len(order), covered, len(names), lib.name))

# ---- --inline: NON-template Ogre members that are inline in Ogre's headers (Renderable::getRenderSystemData). With the
# client headers every Ogre class is dllimport, so the compiler expected rgmain.dll to export them -- it does not, and
# they linked as stubs. Compile them locally: OGRE_STATIC_LIB drops dllimport (decorated names are unchanged), and a
# global member-pointer per stubbed member forces the inline body out. Archive: linkexp/ogreinline.lib.
if '--inline' in sys.argv:
    import pefile as _pf
    _pe = _pf.PE(str(H / 'run/rgmain.dll'), fast_load=True)
    _pe.parse_data_directories(directories=[_pf.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_EXPORT']])
    _exp = {(e.name or b'').decode() for e in _pe.DIRECTORY_ENTRY_EXPORT.symbols}
    _st = set()
    for l in (H / 'linkexp/qt.map').read_text(errors='replace').splitlines():
        p = l.split()
        if len(p) >= 4 and ':' in p[0] and 'stubs' in p[-1].lower() and '@Ogre@@' in p[1]:
            _st.add(p[1])
    cand = sorted(n for n in _st if n.startswith('?') and not n.startswith(('??0', '??1', '??_', '??$', '??__'))
                  and '?$' not in n.split('@Ogre@@')[0] and n not in _exp and '@@2' not in n and '@@3' not in n)
    idem = {}
    for i in range(0, len(cand), 40):
        part = cand[i:i + 40]
        r_ = demangle(part)
        if len(r_) == len(part):
            idem.update(zip(part, r_))
    SIG = re.compile(r'^(?:public|protected|private): (virtual |static )?(.*?) (__thiscall|__cdecl|__stdcall) ((?:\w+::)*\w+)::(~?\w+|operator\W+)\((.*)\)( const)?\s*$')
    groups = {}
    for n, s in idem.items():
        m = SIG.match(fix(s))
        if not m or 'operator ' in s:
            continue
        virt, ret, cc, cls, meth, args, const = m.groups()
        args = '' if args == 'void' else args
        if virt == 'static ':
            ptr = '%s (%s *)(%s)' % (ret, cc, args)
        else:
            ptr = '%s (%s %s::*)(%s)%s' % (ret, cc, cls, args, ' const' if const else '')
        groups.setdefault(cls, []).append((n, ptr, '&%s::%s' % (cls, meth)))
    print('inline pass: %d stubbed non-template Ogre members not exported by rgmain, %d parsed in %d classes'
          % (len(cand), sum(len(v) for v in groups.values()), len(groups)))
    PRE2 = chr(10).join(['#define OGRE_STATIC_LIB', '#define private public', '#define protected public']) + chr(10) + PRE.replace('#undef OGRE_NONCLIENT_BUILD', '')
    OUT2 = H / 'linkexp/ogreinline'
    OUT2.mkdir(parents=True, exist_ok=True)

    def build2(item):
        cls, mem = item
        k = hashlib.md5((cls + '|'.join(n for n, _, _ in mem)).encode()).hexdigest()[:16]
        obj = OUT2 / (k + '.obj')
        if obj.exists():
            return cls, mem, True, ''
        lines = []
        for i, (n, ptr, addr) in enumerate(mem):
            t = ptr.replace('::*)', '::*roc_t_%d)' % i, 1) if '::*)' in ptr else ptr.replace('*)', '*roc_t_%d)' % i, 1)
            lines.append('typedef %s;' % t)
            # a global initialised with the member's address forces the inline body into this object; the linker
            # pulls the archive member in because it defines the name other objects reference
            lines.append('roc_t_%d roc_keep_%s_%d = %s;' % (i, k, i, addr))
        src = OUT2 / (k + '.cpp')
        src.write_text(PRE2 + chr(10).join(lines) + chr(10))
        code, text = rebuild.run(tc, 'cl', FLAGS + ['/Fo' + str(obj), str(src)], OUT2)
        if code or not obj.exists():
            obj.unlink(missing_ok=True)
            return cls, mem, False, chr(10).join(l for l in text.splitlines() if 'error' in l)[:400]
        return cls, mem, True, ''
    items = sorted(groups.items(), key=lambda kv: -len(kv[1]))[:int(os.environ.get('INLINE_MAX', '100000'))]
    # a class whose TU fails is retried member by member (one bad signature must not lose the rest)
    with ThreadPoolExecutor(max_workers=int(os.environ.get('TI_JOBS', '12'))) as ex:
        r1 = list(ex.map(build2, items))
    retry = [(cls, [m]) for cls, mem, g, _ in r1 if not g and len(mem) > 1 for m in mem]
    with ThreadPoolExecutor(max_workers=int(os.environ.get('TI_JOBS', '12'))) as ex:
        r2 = list(ex.map(build2, retry))
    good = [(cls, mem) for cls, mem, g, _ in r1 + r2 if g]
    objs2 = [str(OUT2 / (hashlib.md5((c + '|'.join(n for n, _, _ in m)).encode()).hexdigest()[:16] + '.obj')) for c, m in good]
    lib2 = H / 'linkexp/ogreinline.lib'
    if objs2:
        rsp2 = OUT2 / 'lib.rsp'
        rsp2.write_text('\n'.join('"%s"' % o for o in objs2))
        code, text = rebuild.run(tc, 'lib', ['/nologo', '/OUT:' + str(lib2), '@' + str(rsp2)], OUT2)
        if code:
            print('lib failed:', text[:300])
    fails = {cls: e for cls, mem, g, e in r1 + r2 if not g and len(mem) == 1}
    (H / 'auto/ogreinline.json').write_text(json.dumps({'ok_members': sum(len(m) for _, m in good), 'failed': fails}, indent=1))
    print('inline pass: %d members compiled into %s (%d single-member failures, auto/ogreinline.json)'
          % (sum(len(m) for _, m in good), lib2.name, len(fails)))

# ---- --rbx: stubbed members of ROBLOX class templates (FactoryProduct<Camera>::getClassName, RefPropDescriptor<Camera,
# Instance>::writeValue: XML clone of the Camera ran them as stubs -> nameless clone -> "circular reference" on File->New).
# Same `template class <instance>;` approach, but each TU includes the NATIVE headers declaring every RBX name the
# instance mentions (index: class name -> native-headers path; variant dirs with '-' skipped). linkexp/tmplinst_rbx.lib.
if '--rbx' in sys.argv:
    HDR = ROOT / 'rebuild/2008-06/native-headers'
    CL = re.compile(r'^\s*(?:class|struct)\s+(?:\w+\s+)?([A-Za-z_]\w*)\b[^;]*$', re.M)
    hidx, nsidx = {}, set()
    for h in sorted(HDR.rglob('*.h')):
        rel = h.relative_to(HDR).as_posix()
        if '-' in rel.split('/')[0]:
            continue
        _ht = h.read_text(errors='replace')
        for m in CL.finditer(_ht):
            hidx.setdefault(m.group(1), rel)
        nsidx.update(re.findall(r'\bnamespace\s+([A-Za-z_]\w*)', _ht))
    rcls = {}
    for n, s in dem.items():
        c = class_of(fix(s))
        if c and '<' in c and 'RBX::' in c and '`' not in c and 'lambda' not in c:
            rcls.setdefault(c, []).append(n)
    _flt = os.environ.get('RBX_FILTER')   # regex over the instance text: pilot the classes a crash names first
    rorder = sorted((c for c in rcls if not _flt or re.search(_flt, c)), key=lambda c: -len(rcls[c]))[:int(os.environ.get('RBX_MAX', '100000'))]
    print('rbx pass: %d stubbed members in %d Roblox class-template instances; building %d' % (sum(len(v) for v in rcls.values()), len(rcls), len(rorder)))
    OUT3 = H / 'linkexp/tmplinst_rbx'
    OUT3.mkdir(parents=True, exist_ok=True)
    # template MEMBER BODIES: headers only declare most of them (FactoryProduct::getClassName); natives define them
    # out-of-class in each .cpp that needs them ('template<class C, class D, const char* N> const Name&
    # FactoryProduct<C, D, N>::getClassName() const {...}'). Harvest, dedupe by head, group by template name; each TU
    # includes the groups of the templates it instantiates (explicit instantiation only emits DEFINED members).
    TDEF = re.compile(r'^[ \t]*template\s*<(?!\s*>)[^;{]*?>\s*\n?[^;{]*?\b([A-Za-z_]\w*)\s*<[^;{]*?>\s*::\s*(~?\w+)\s*\([^;{]*?\{', re.M)
    tdefs, seen_ = {}, set()
    for f in sorted((ROOT / 'rebuild/2008-06/native-classes').glob('*.cpp')):
        t = f.read_text(errors='replace')
        for m in TDEF.finditer(t):
            st_, d_, j_ = m.start(), 0, m.end() - 1
            while j_ < len(t):   # brace-balanced body
                d_ += {'{': 1, '}': -1}.get(t[j_], 0)
                j_ += 1
                if d_ == 0:
                    break
            head = re.sub(r'\s+', ' ', t[st_:m.end()])
            if head in seen_ or d_:
                continue
            seen_.add(head)
            tdefs.setdefault((m.group(1), m.group(2)), t[st_:j_].strip())   # first definition per (template, member)
    print('rbx pass: %d (template, member) definitions harvested from native sources' % len(tdefs))

    def build3(c):
        k = hashlib.md5(c.encode()).hexdigest()[:16]
        obj, fail = OUT3 / (k + '.obj'), OUT3 / (k + '.fail')
        if obj.exists():
            return c, True, ''
        if fail.exists():
            return c, False, fail.read_text()
        # precheck (no compile): a Roblox type/namespace no native header declares (analog-invented Listener, View::E)
        # can never compile -- ~45% of instances, ~4 s each
        for q_ in re.findall(r'\bRBX((?:::[A-Za-z_]\w*)+)', c):
            miss_ = [x for x in q_.split('::')[1:] if x not in hidx and x not in nsidx]
            if miss_:
                err = 'precheck: no native header declares RBX::%s' % miss_[0]
                fail.write_text(err)
                return c, False, err
        inc = []
        for nm in re.findall(r'\b([A-Za-z_]\w*)\b', c):
            h_ = hidx.get(nm)
            if h_ and h_ not in inc:
                inc.append(h_)
        body = c.replace('class ', '').replace('struct ', '').replace('enum ', '')
        # undname spells a pointer non-type argument with its type ('&char const * const RBX::sCamera'): C++ wants '&RBX::sCamera'
        body = re.sub(r'&[A-Za-z_][\w\s\*]*?\s((?:[A-Za-z_]\w*::)+[A-Za-z_]\w*)(?=\s*[,>])', r'&\1', body)
        src = OUT3 / (k + '.cpp')
        defs_ = []
        # only the members this instance has STUBBED (the rest are defined in headers or unneeded: fewer clashes)
        want_ = {re.sub(r'^.*::', '', fix(dem[n]).split('(')[0]).strip() for n in rcls[c]}
        tmpl_ = re.match(r'^(?:\w+::)*(\w+)\s*<', c)
        for mb in sorted(want_):
            d0 = tdefs.get((tmpl_.group(1) if tmpl_ else '', mb))
            if d0:
                defs_.append(d0)
        src.write_text('#define NOMINMAX\n#include <winsock2.h>\n#include <map>\n#include <vector>\n#include <list>\n#include <set>\n#include <string>\n#include <boost/shared_ptr.hpp>\n' + ''.join('#include "%s"\n' % h_ for h_ in inc)
                       + 'namespace RBX { namespace Reflection {} using namespace Reflection; }\nnamespace RBX {\n' + '\n'.join(defs_) + '\n}\n'
                       + 'template class %s;\n' % body)
        code, text = rebuild.run(tc, 'cl', FLAGS + ['/Fo' + str(obj), str(src)], OUT3)
        if (code or not obj.exists()) and 'WINDOWS.H already included' in text:   # MFC header among the includes: no winsock2 first
            src.write_text(src.read_text().replace('#include <winsock2.h>\n', ''))
            code, text = rebuild.run(tc, 'cl', FLAGS + ['/Fo' + str(obj), str(src)], OUT3)
        if (code or not obj.exists()) and "'char (*)[]'" in text:   # native declares char sCamera[]: pass the array itself
            src.write_text(src.read_text().replace('&RBX::', 'RBX::'))
            code, text = rebuild.run(tc, 'cl', FLAGS + ['/Fo' + str(obj), str(src)], OUT3)
        if code or not obj.exists():
            obj.unlink(missing_ok=True)
            err = '\n'.join(l for l in text.splitlines() if 'error' in l)[:400]
            fail.write_text(err)
            return c, False, err
        return c, True, ''
    with ThreadPoolExecutor(max_workers=int(os.environ.get('TI_JOBS', '12'))) as ex:
        r3 = list(ex.map(build3, rorder))
    ok3 = [c for c, g, _ in r3 if g]
    objs3 = [str(OUT3 / (hashlib.md5(c.encode()).hexdigest()[:16] + '.obj')) for c in ok3]
    lib3 = H / 'linkexp/tmplinst_rbx.lib'
    if objs3:
        rsp3 = OUT3 / 'lib.rsp'
        rsp3.write_text('\n'.join('"%s"' % o for o in objs3))
        code, text = rebuild.run(tc, 'lib', ['/nologo', '/OUT:' + str(lib3), '@' + str(rsp3)], OUT3)
        if code:
            print('lib failed:', text[:300])
    (H / 'auto/tmplinst_rbx.json').write_text(json.dumps({'ok': ok3, 'failed': {c: e for c, g, e in r3 if not g}}, indent=1))
    print('rbx pass: instantiated %d / %d, covering %d stubbed members -> %s' % (len(ok3), len(rorder), sum(len(rcls[c]) for c in ok3), lib3.name))
