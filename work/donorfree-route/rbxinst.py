"""python rbxinst.py: RBX function/member TEMPLATE instances our link only has as `return 0` stubs, by explicit
instantiation from the native headers (tmplinst.py does STL/Ogre class templates). Gemini dossier section 11/13:
ServiceProvider::getClassIndex<T> (all collide on slot 0), create<T>/find<T> (NULL services), Reflection::Type/RefType::
singleton<T> (NULL Type&), boost::polymorphic_cast<T,U> (NULL instead of the cast), Named<B,s>::getName,
StringConverter<T>::convertToString (uninitialized std::string sret).
Per stubbed name: undname -> `template <declaration>;` in its own TU with the headers that declare every RBX class in
it (class -> header map over native-headers) plus the template's own header; one native_check_runner run, every TU
that compiles and defines the stubbed name is bound (linkexp/qt_results.txt). Writes auto/rbxinst.json."""
import json, re, subprocess, sys
from pathlib import Path
H = Path(__file__).parent
ROOT = H.parents[1]
sys.path.insert(0, str(ROOT))
from roc import rebuild as rb
HDR = ROOT / 'rebuild/2008-06/native-headers'
UND = str(ROOT / 'tools/msvc800sp1/VC/bin/undname.exe')
PATS = [   # getClassIndex<T>: the stub returned 0, so every create<T> inserted into slot 0 (over Workspace); the native
        # body shares doGetClassIndex<T>'s COMDAT `index` static with every other user
        r'^\?\?\$getClassIndex@.*@ServiceProvider@RBX@@', r'^\?\?\$(create|find)@.*@ServiceProvider@RBX@@',
        r'^\?\?\$singleton@.*@(Ref)?Type@Reflection@RBX@@', r'^\?\?\$polymorphic_cast@.*@boost@@',
        r'^\?getName@\?\$Named@', r'^\?convertToString@\?\$StringConverter@',
        r'^\?(newSignalInstance|findSig|sig|connect)@\?\$TSignalDesc@', r'^\?connectGeneric@\?\$SignalDescImpl@', r'^\?\?RGenericSlotAdapter@\?\$SignalDescImpl@']
TPL_HDR = {'TSignalDesc': 'reflection/signal.h', 'SignalDescImpl': 'reflection/signal.h', 'ServiceProvider': 'v8tree/Service.h', 'Type': 'reflection/type.h', 'RefType': 'reflection/type.h',
           'Named': 'util/Name.h', 'StringConverter': 'util/Utilities.h', 'polymorphic_cast': None}
stubs = []
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0] and 'stubs' in p[-1] and any(re.match(x, p[1]) for x in PATS):
        stubs.append(p[1])
stubs = sorted(set(stubs))
cls_hdr = {}
for h in sorted(HDR.rglob('*.h')):
    rel = h.relative_to(HDR).as_posix()
    if '/' in rel and '-' in rel.split('/')[0]:   # variant header trees (instance-ancestor-inline/, cow-noinline-read/...)
        continue
    for m in re.finditer(r'^\s*(?:class|struct)\s+(?:\w+\s+)?(\w+)\s*(?::[^;{]*)?\{', h.read_text(errors='replace'), re.M):
        cls_hdr.setdefault(m.group(1), rel)
dem = {}
for i in range(0, len(stubs), 40):
    out = subprocess.run([UND] + stubs[i:i + 40], capture_output=True, text=True).stdout
    for m in re.finditer(r'Undecoration of :- "(.+?)"\s+is :- "(.+?)"', out):
        dem[m.group(1)] = m.group(2)


def decl(s):
    """undname text -> explicit instantiation declaration"""
    s = re.sub(r'^(public|private|protected): ', '', s)
    s = re.sub(r'\b(static|virtual) ', '', s)
    s = s.replace('(void)', '()')
    s = re.sub(r'&(?:const\s+)?char(?:\s+const)?\s*\*(?:\s*const)?\s+', '', s)
    if 'RefType::singleton<' in s:
        s = s.replace('class RBX::Reflection::Type const &', 'class RBX::Reflection::RefType const &')
    return 'template ' + s + ';'


src_dir = ROOT / 'work/native-client/stub-drafts/rbxinst'
src_dir.mkdir(exist_ok=True)
jobs, want = [], {}
for k, s in enumerate(stubs):
    d = dem.get(s)
    if not d:
        continue
    names = set(re.findall(r'\b[A-Za-z_]\w*\b', d))
    tpl = next((t for t in TPL_HDR if re.search(r'\b%s\b' % t, d)), None)
    inc = ['util/Object.h'] + sorted({cls_hdr[n] for n in names if n in cls_hdr})
    extra = '#include <boost/cast.hpp>\n' if 'polymorphic_cast' in d else ''
    if 'G3D::' in d:
        extra += '#include <G3D/Vector3.h>\n#include <G3D/Color3.h>\n#include <G3D/CoordinateFrame.h>\n#include <G3D/Vector2int16.h>\n'
    if 'EnumDescriptor' in d:
        inc.append('reflection/enumconverter.h')
    if 'PropertyDescriptor' in d:
        inc.append('reflection/property.h')
    if 'NormalId' in d:
        inc.append('util/NormalId.h')
    if 'Stats::' in d:
        inc.append('v8datamodel/Stats.h')
    if any(x in d for x in ('Balancing', 'Flying', 'HumanoidState')):
        inc += ['humanoid/HumanoidStates1.h', 'humanoid/HumanoidStates2.h', 'humanoid/HumanoidStates3.h']
    if tpl and TPL_HDR[tpl]:
        inc.insert(1, TPL_HDR[tpl])
    body = ''
    if 'getClassIndex' in d:   # v8tree/Service.h declares it without a body (2008: call_once on a static flag, then the index)
        extra += '#include <boost/thread/once.hpp>\n'
        body = ('namespace RBX {\n'
                'template<class Class> size_t ServiceProvider::doGetClassIndex() { static size_t index = newIndex(); return index; }\n'
                'template<class Class> void ServiceProvider::callDoGetClassIndex() { doGetClassIndex<Class>(); }\n'
                'template<class Class> size_t ServiceProvider::getClassIndex() { static boost::once_flag flag = BOOST_ONCE_INIT; '
                'boost::call_once(&callDoGetClassIndex<Class>, flag); return doGetClassIndex<Class>(); }\n}\n')
    f = src_dir / ('RbxInst_%03d.cpp' % k)
    f.write_text('// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/libs/RakNet-master/Source /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include\n// generated by work/donorfree-route/rbxinst.py\n'
                 + extra + ''.join('#include "%s"\n' % x for x in dict.fromkeys(inc)) + '\n' + body + decl(d) + '\n')
    jobs.append({'source': str(f), 'checks': [], 'ranges': [], 'layouts': []}); want[str(f)] = s
man = src_dir / 'rbxinst.json'
man.write_text(json.dumps({'compiler_build': 21022, 'compiler_variant': 'default', 'jobs': jobs}))
r = subprocess.run([sys.executable, str(ROOT / 'rebuild/2008-06/tests/native_check_runner.py'), 'run', str(man)], capture_output=True, text=True)
res = json.loads(re.findall(r'^\{.*\}$', r.stdout, re.M)[-1])['results']
rows = json.loads(Path(res).read_text())
ACC = str.maketrans('ACEIKMOQSUW', 'QSUQSUQQSUU')   # private/protected/public x member/static/virtual -> public


def norm(n):   # access codes after '@@' (the function-type prefix; template args may hold '@@' too)
    return re.sub(r'@@([ACEIKMOQSUW])', lambda m: '@@' + m.group(1).translate(ACC), n)


ok, bad, al = [], [], {}
for row in rows:
    s = want.get(row.get('source'))
    defs_ = {n for n, d_ in rb.coff_externals(Path(row['object']).read_bytes()).items() if d_} if row.get('status') == 'complete' else set()
    if s in defs_:
        ok.append(s)
        continue
    alt = next((n for n in defs_ if norm(n) == norm(s)), None)   # native header declares it with another access
    if not alt and 'RefType@Reflection@RBX@@SAABVType@12@XZ' in s:
        _rt = s.replace('SAABVType@12@XZ', 'SAABV012@XZ')
        if _rt in defs_:
            alt = _rt
    if alt:
        ok.append(s); al[s] = alt
    else:
        bad.append(s)
af = H / 'aliases_rbxinst.txt'
old = dict(l.strip().split('=', 1) for l in open(af) if '=' in l) if af.exists() else {}
old.update(al)
af.write_text(''.join('%s=%s' % kv + chr(10) for kv in sorted(old.items())))
q = H / 'linkexp/qt_results.txt'
if ok:
    q.write_text(q.read_text().rstrip('\n') + '\n' + res + '\n')
json.dump({'ok': ok, 'failed': bad, 'results': res}, open(H / 'auto/rbxinst.json', 'w'), indent=0)
print('rbxinst: stubbed RBX template instances %d, demangled %d, compiled+defined %d, failed %d' % (len(stubs), len(dem), len(ok), len(bad)))
