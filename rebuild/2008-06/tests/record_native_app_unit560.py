"""Verify the inactive 2008-06 native rows of the application range 00560000..00564000, and record the unit map of the
range (boundary evidence in the receipt's `unit_map`; rows counted by other receipts are listed there as text).

Unit map summary (details in UNIT_MAP below):
  * util/ContentProvider.cpp 0055bae0..0056306f (starts below the range, mapped by app-unit55c-working.json): the
    container / boost.function instances of the cache map, request list and callback vector, setAssetFolder,
    registerFile, loadContent, getFile, getContent, the worker processRequests, classDescriptor /
    DescribedNonCreatable<ContentProvider>, ContentProvider() / ~ContentProvider, the ??_E adjustor thunks and ??_G.
    The ContentProvider owner's committed native-classes ContentProvider.cpp, ContentProviderGetFile.cpp,
    ContentProviderLoadContent.cpp, ContentProviderRegisterFile.cpp and ContentProviderWorkerBinding.cpp are compiled
    here READ-ONLY (never copied or edited); a row is counted when its body is exact and every target verifies.
  * shared helpers 00563070..005630ff: boost::recursive_mutex constructor and two ICF-shared std::string COMDATs
    (library code, not recovered).
  * v8datamodel/DebugSettings.cpp 00563100.. (continues past 00564000): the settings-items owner's unit. Built here:
    the "Profile" getters (native-classes/AppUnit560DebugProfile.cpp, new) against the committed
    v8datamodel/DebugSettings.h and AppUnit500/RenderSpecData.h, both read-only, plus the implicit
    ~SpecData 005631c0 they call.

Build: document-swap flags (native_bind.flags()), VS2008 RTM 21022, no extra flags. No pending build, no new header
(nothing is shadowed).

Every counted row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the
address the original instruction uses and verified: imports by DLL export name, string literals by bytes, RTTI type
descriptors by name, vtables by their complete-object-locator RTTI, own symbols by the row proven here, COMDAT support
bodies by exactness at the bound address (their own targets verified recursively), the remaining externals by
evidence names or the EXTERNAL map with asserted evidence, static data by one address per symbol. A fixed point drops
every row whose target cannot be verified (including calls to rows dropped this way). A row is counted only when no
other receipt counts it.
Writes work/2008-06/shared-layouts/app-unit560-working.json.
Set NATIVE_APP_UNIT560_DISCOVER=1 to list unbound targets and dropped rows instead of asserting.
"""
import glob
import json
import os
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match, rebuild  # noqa: E402
import native_bind as nb  # noqa: E402

R = ROOT / 'rebuild/2008-06'
NC = R / 'native-classes'
OUT = nb.OUT / 'app-unit560'
OUT.mkdir(parents=True, exist_ok=True)
# 'profile' is this lease's new unit; the other sources are the ContentProvider owner's committed files, compiled
# read-only.
SOURCES = {
    'profile': NC / 'AppUnit560DebugProfile.cpp',
    'cp': NC / 'ContentProvider.cpp',
    'getfile': NC / 'ContentProviderGetFile.cpp',
    'load': NC / 'ContentProviderLoadContent.cpp',
    'register': NC / 'ContentProviderRegisterFile.cpp',
    'worker': NC / 'ContentProviderWorkerBinding.cpp',
    # support-body sources only (no row is taken from them): callees of the rows above
    'cache': NC / 'ContentProviderCacheSupport.cpp',
    'read': NC / 'ContentRead.cpp',
}
HEADERS = [R / 'native-headers/v8datamodel/DebugSettings.h', R / 'native-headers/AppUnit500/RenderSpecData.h',
           R / 'native-headers/util/NativeContentProvider.h']
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT560_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit560-working.json'
LO, HI = 0x560000, 0x564000

# Profiles: each committed ContentProvider file is compiled with its own `// native-flags:` line (its /I directories go
# ahead of native-headers; every other flag must already be a document-swap base flag, checked). ContentProvider.cpp
# has no pinned line: it gets native-headers/content-cache-inline ahead of native-headers (read-only, the variant
# app-unit55c-working.json and the owner's LoadContent / WorkerBinding / CacheSupport pins use): it adds the inline
# ContentId operator< the original map / tree instances need (they call the msvcp90 string operator< import 0080235c
# directly; the out-of-line operator< 0055bd50 is a single jmp through that import). The new AppUnit560DebugProfile.cpp
# uses the base flags.
HEADER_DIR = R / 'native-headers'
INLINE = HEADER_DIR / 'content-cache-inline'
UNPINNED_FIRST = {'cp': [INLINE]}


def pinned_first(key, src):
    m = re.search(r'^// native-flags: (.*)$', src.read_text(), re.M)
    if not m:
        return UNPINNED_FIRST.get(key, [])
    base = set(nb.flags())
    first = []
    for f in m.group(1).split():
        if f.startswith('/I'):
            first.append(Path(f[2:].replace('{headers}', str(HEADER_DIR))))
        else:
            assert f in base, (src.name, f)
    return first


def unit_flags(key, src):
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    return flags[:i] + ['/I' + str(p) for p in pinned_first(key, src)] + flags[i:]


for _p in sorted({p for k, s in SOURCES.items() for p in pinned_first(k, s)}):
    HEADERS.extend(sorted(_p.rglob('*.h')))
OBJ, FLAGS = {}, {}
for _key, _src in SOURCES.items():
    OBJ[_key] = OUT / ('NativeAppUnit560_' + _key + '.obj')
    FLAGS[_key] = unit_flags(_key, _src)
    _code, _log = rebuild.run(rebuild.toolchain(21022), 'cl', FLAGS[_key] + ['/Fo' + str(OBJ[_key]), str(_src)], OUT)
    assert _code == 0, _log

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
FUNCTIONS = {}
for line in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines():
    if line.strip():
        x = json.loads(line)
        FUNCTIONS[int(x['addr'], 16)] = x


class Unit:
    def __init__(self, key, path):
        self.key = key
        self.raw = path.read_bytes()
        self.sections, self.symbols, self.definitions, self.starts = match._coff_data_index(self.raw)
        self.bodies = {n: (b, r) for n, b, r in match.coff_functions(self.raw)}
        self.compiled = [n for n in self.bodies if not nb.LOCAL_EH.match(n)]

    def sym(self, prefix, *contains):
        hits = [n for n in self.compiled if n.startswith(prefix) and all(c in n for c in contains)]
        assert len(hits) == 1, (self.key, prefix, contains, hits)
        return hits[0]


U = {k: Unit(k, p) for k, p in OBJ.items()}
P, CP, LD = U['profile'], U['cp'], U['load']

# ---- rows ----------------------------------------------------------------------------------------------------------
STR = 'V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@'
FN = 'V?$function@$$A6AXW4RequestResult@RBX@@AAV?$basic_istream@DU?$char_traits@D@std@@@std@@@ZV?$allocator@X@4@@boost@@'
ROWS = [
    # DebugSettings "Profile" getters (new unit)
    (0x5631c0, 'profile', '??1SpecData@Render@RBX@@QAE@XZ'),
    (0x563230, 'profile', '?videoMemory@DebugSettings@RBX@@QBEHXZ'),
    (0x563260, 'profile', '?cpuSpeed@DebugSettings@RBX@@QBEHXZ'),
    (0x563290, 'profile', '?cpuCount@DebugSettings@RBX@@QBEHXZ'),
    (0x5632c0, 'profile', '?osVer@DebugSettings@RBX@@QBE?A' + STR + 'XZ'),
    (0x563330, 'profile', '?osPlatformId@DebugSettings@RBX@@QBEHXZ'),
    (0x563370, 'profile', '?systemProductName@DebugSettings@RBX@@QBE?A' + STR + 'XZ'),
    (0x563430, 'profile', '?glVendor@DebugSettings@RBX@@QBE?A' + STR + 'XZ'),
    (0x5634b0, 'profile', '?gfxcard@DebugSettings@RBX@@QBE?A' + STR + 'XZ'),
    (0x5638c0, 'profile', '?cpu@DebugSettings@RBX@@QBE?A' + STR + 'XZ'),
    (0x563940, 'profile', '?ram@DebugSettings@RBX@@QBEHXZ'),
    (0x563970, 'profile', '?resolution@DebugSettings@RBX@@QBE?A' + STR + 'XZ'),
    (0x563a50, 'profile', '?shaderModel@DebugSettings@RBX@@QBEMXZ'),
    # ContentProvider unit (committed owner files, read-only)
    (0x560200, 'register', U['register'].sym('?registerFile@ContentProvider@RBX@@')),
    (0x560890, 'load', LD.sym('?_Ufill@?$vector@' + FN)),
    (0x560a40, 'cp', CP.sym('??$_Ucopy@PA' + FN)),
    (0x560ea0, 'load', '??0ContentRequest@RBX@@QAE@ABU01@@Z'),
    (0x560fa0, 'cp', '??0ContentRequest@RBX@@QAE@XZ'),
    (0x561070, 'cp', CP.sym('??4?$vector@' + FN)),
    (0x5611f0, 'load', LD.sym('?insert@?$vector@' + FN)),
    (0x5612b0, 'cp', CP.sym('?classDescriptor@?$Described@VContentProvider@RBX@@')),
    (0x561320, 'cp', CP.sym('??1?$map@VContentId@RBX@@UCachedContent@ContentProvider@2@')),
    (0x561330, 'load', LD.sym('?push_back@?$vector@' + FN)),
    (0x5613b0, 'worker', U['worker'].sym('?manage@?$functor_manager@V?$bind_t@W4work_result@worker_thread@RBX@@')),
    (0x5613f0, 'cp', CP.sym('??0?$DescribedNonCreatable@VContentProvider@RBX@@')),
    (0x561780, 'load', LD.sym('?push_back@?$list@UContentRequest@RBX@@')),
    (0x561980, 'load', LD.sym('?loadContent@ContentProvider@RBX@@')),
    (0x561e30, 'getfile', U['getfile'].sym('?getFile@ContentProvider@RBX@@')),
    (0x5620f0, 'cp', CP.sym('?processRequests@ContentProvider@RBX@@')),
    (0x562c30, 'cp', '??0ContentProvider@RBX@@QAE@XZ'),
    (0x562de0, 'cp', '??_EContentProvider@RBX@@WKE@AEPAXI@Z'),
    (0x562df0, 'cp', '??_EContentProvider@RBX@@WME@AEPAXI@Z'),
    (0x562e00, 'cp', '??_EContentProvider@RBX@@WBA@AEPAXI@Z'),
    (0x562e10, 'cp', '??_EContentProvider@RBX@@WBE@AEPAXI@Z'),
    (0x562e20, 'cp', '??_EContentProvider@RBX@@WCE@AEPAXI@Z'),
    (0x562e30, 'cp', '??_EContentProvider@RBX@@WEE@AEPAXI@Z'),
    (0x562e40, 'cp', '??_EContentProvider@RBX@@WGE@AEPAXI@Z'),
    (0x562e50, 'cp', '??_EContentProvider@RBX@@WIE@AEPAXI@Z'),
    (0x562e60, 'cp', '??1ContentProvider@RBX@@UAE@XZ'),
    (0x563050, 'cp', '??_GContentProvider@RBX@@UAEPAXI@Z'),
]
ROWS.sort()
for _a, _u, _s in ROWS:
    assert LO <= _a < HI and _a in FUNCTIONS, hex(_a)
    assert _s in U[_u].bodies, (hex(_a), _u, _s)
assert len({a for a, _, _ in ROWS}) == len(ROWS) and len({s for _, _, s in ROWS}) == len(ROWS)
ROW_UNIT = {s: u for _, u, s in ROWS}

# ---- externals ------------------------------------------------------------------------------------------------------
# Callees without a body in these objects. Each entry is checked against the binary below (evidence name, strings,
# imports or bytes of the target).
EXTERNAL = {
    # SpecData() (counted by app-unit500-working.json; evidence: its row_identity, and the getters' calls)
    '??0SpecData@Render@RBX@@QAE@XZ': 0x501ae0,
    # G3D 6.09 library bodies, bound under the same names by app-unit500-working.json
    '?format@G3D@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PBDZZ': 0x509b10,
    '?readString@RegistryUtil@G3D@@SA_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AAV34@@Z':
        0x514190,
    # boost 1.34.1 boost.thread mutex (library, exe-local): bound under the same names by app-unit54c-2008 /
    # app-leaves2008 / app-unit554; told apart by their imports (asserted below)
    '??0mutex@boost@@QAE@XZ': 0x594c90,
    '??1mutex@boost@@QAE@XZ': 0x594cb0,
    '?do_lock@mutex@boost@@AAEXXZ': 0x594ce0,
    '?do_unlock@mutex@boost@@AAEXXZ': 0x594d00,
    # CRT atexit and the reflection ClassDescriptor constructor, bound the same way by app-unit568 / app-unit564 and
    # about a hundred receipts
    '_atexit': 0x6a17af,
    '??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z': 0x5708f0,
    # Described<Instance>::classDescriptor (evidence name, mangled 3PBDB there; RTTI 3QBDB): bound as an external
    '?classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3QBDBVDescribedBase@Reflection@2@@Reflection@RBX@@'
    'SAAAVClassDescriptor@23@XZ': 0x40ad80,
}
# Externals whose evidence name differs from the native declaration only in the access letter: the 2008 Instance
# constructor / destructor are protected (IAE / MAE); the core v8tree/Instance.h declares them public.
ACCESS_EXTERNAL = {
    '??0Instance@RBX@@QAE@XZ': (0x55b7e0, '??0Instance@RBX@@IAE@XZ'),
    '??1Instance@RBX@@UAE@XZ': (0x55a540, '??1Instance@RBX@@MAE@XZ'),
}
for _s, (_a, _e) in ACCESS_EXTERNAL.items():
    assert names.get(_a) == _e, (_s, hex(_a), names.get(_a))
# The adjustor thunks jump to the vector deleting destructor, which no unit emits: MSVC folds ??_E onto the scalar
# deleting destructor row (the same alias as app-unit568's GlobalSettings thunks).
ALIAS = {'??_EContentProvider@RBX@@UAEPAXI@Z': '??_GContentProvider@RBX@@UAEPAXI@Z'}
_mi = {a: {i.split('!')[1] for i in FUNCTIONS[a]['imports']} for a in (0x594cb0, 0x594ce0, 0x594d00)}
assert 'DeleteCriticalSection' in _mi[0x594cb0] and 'CloseHandle' in _mi[0x594cb0]
assert {'EnterCriticalSection', 'WaitForSingleObject'} == _mi[0x594ce0]
assert {'LeaveCriticalSection', 'ReleaseMutex'} == _mi[0x594d00]
assert FUNCTIONS[0x594c90]['call_targets'] == ['00594c10'] and FUNCTIONS[0x594c90]['size'] == 24
assert FUNCTIONS[0x6a17af]['size'] == 23 and FUNCTIONS[0x6a17af]['call_targets'] == ['006a170a']
assert names[0x40ad80].startswith('?classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3PBDB')
_imp = {a: {i.split('!')[1] for i in FUNCTIONS[a]['imports']} for a in (0x514190,)}
assert 'RegQueryValueExA' in _imp[0x514190] and any(i.startswith('??4') for i in _imp[0x514190])
assert original.data(0x509b10, 1) and FUNCTIONS[0x509b10]['size'] > 0
DATA_SECTIONS = [(original.image + s.VirtualAddress, original.image + s.VirtualAddress + s.Misc_VirtualSize)
                 for s in original.pe.sections if s.Name.rstrip(b'\0') in (b'.data', b'.rdata')]
TEXT = [(original.image + s.VirtualAddress, original.image + s.VirtualAddress + s.Misc_VirtualSize)
        for s in original.pe.sections if s.Name.rstrip(b'\0') == b'.text']


def norm(s):
    return s.replace('3QBDB', '3PBDB')


def counted_elsewhere():
    out = {}
    for path in glob.glob(str(ROOT / 'work/2008-06/shared-layouts/*.json')):
        if Path(path).name == RECEIPT.name:
            continue
        try:
            data = json.loads(Path(path).read_text())
        except Exception:
            continue
        if not isinstance(data, dict):
            continue
        found = []
        for key in ('exact_function_rows', 'exact_addresses', 'exact_unique_addresses', 'exact_distinct_addresses'):
            if isinstance(data.get(key), (list, dict)):
                found = list(data[key])
                break
        else:
            def walk(o):
                if isinstance(o, list):
                    for e in o:
                        walk(e)
                elif isinstance(o, dict):
                    if 'address' in o and o.get('exact') is True:
                        found.append(o['address'])
                    for v in o.values():
                        walk(v)
            walk(data)
        for r in found:
            r = r.get('address', '') if isinstance(r, dict) else str(r)
            m = re.match(r'(?:0x)?([0-9a-fA-F]{6,8})', r)
            if m:
                out.setdefault('%08x' % int(m.group(1), 16), []).append(Path(path).name)
    return out


elsewhere = counted_elsewhere()
_double = {'%08x' % a: elsewhere['%08x' % a] for a, _, _ in ROWS if '%08x' % a in elsewhere}
assert not _double, _double

# ---- verification ---------------------------------------------------------------------------------------------------
BINDING = {}          # symbol -> (address, where)
CONFLICTS = []
LOCAL_STATIC = {}
SUPPORT = {}          # (unit, symbol, address) -> (ok, reason)
SUPPORT_TARGETS = {}


def bind(symbol, value, where):
    prev = BINDING.setdefault(symbol, (value, where))
    if prev[0] != value:
        CONFLICTS.append((symbol, hex(prev[0]), prev[1], hex(value), where))
        return False
    return True


SPLITS = {}


def is_catch_funclet(address):
    # catch(...) { delete p; throw; } funclet of the boost shared_count constructors: the deleter call on the
    # [ebp + 8] pointer, then push 0; push 0; call _CxxThrowException (006a158c) as the last instruction
    row = FUNCTIONS.get(address)
    if not row or not 16 <= row['size'] <= 24:
        return False
    code = original.data(address, row['size'])
    tail = code[-9:]
    return (b'\x75\x08' in code[:4] or b'\x55\x08' in code[:4] or b'\x45\x08' in code[:4] or
            b'\x4d\x08' in code[:4]) and tail[:4] == b'\x6a\x00\x6a\x00' and tail[4] == 0xe8 and \
        (address + row['size'] + struct.unpack('<i', tail[5:9])[0]) & 0xffffffff == 0x6a158c


def body_exact_at(unit, symbol, value):
    hb, hr = unit.bodies[symbol]
    ht, htr, _ = match.target('2008-06', '%08x' % value)
    if len(ht) == len(hb):
        return match.exact_match(ht, htr, hb, hr)
    # support bodies only: a compiled function whose original extent functions.jsonl splits at its catch(...)
    # funclet (the 138 local-extent pins / app-unit4b4 pattern) is compared as head + funclet row
    end = value + len(ht)
    if len(hb) > len(ht) and is_catch_funclet(end) and len(ht) + FUNCTIONS[end]['size'] == len(hb):
        ft, ftr, _ = match.target('2008-06', '%08x' % end)
        ok = match.exact_match(ht + ft, list(htr) + [r + len(ht) for r in ftr], hb, hr)
        if ok:
            SPLITS['%s at %#x' % (symbol[:90], value)] = (
                '%d-byte compiled body = %d-byte row + the %d-byte catch(...) funclet row at %#x (BOUNDS evidence)'
                % (len(hb), len(ht), len(ft), end))
        return ok
    return False


def relocs(unit, address, name):
    body, _ = unit.bodies[name]
    target = original.data(address, len(body))   # the original bytes (a split body continues into its funclet)
    start, section = unit.definitions[name]
    table = unit.sections[section]
    code = unit.raw[table[4] + start:]
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', unit.raw, table[5] + 10 * i)
        offset -= start
        if not 0 <= offset < len(body):
            continue
        symbol = unit.symbols[index][0]
        if kind == 20:
            value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        else:
            value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) \
                & 0xffffffff
        yield offset, symbol, value


def classify(unit, symbol, value, where, own, stack):
    """Return (description, ok)."""
    hit = original.imported(value)
    if hit is not None:
        return '%s!%s' % hit, hit[1] == nb.plain(symbol)
    if symbol in own:
        return 'own row', own[symbol] == value
    if symbol in ALIAS and ALIAS[symbol] in own:
        return 'own row %s (??_E folded onto ??_G)' % ALIAS[symbol][:40], own[ALIAS[symbol]] == value
    if symbol in ACCESS_EXTERNAL:
        return 'external (evidence name %s)' % ACCESS_EXTERNAL[symbol][1], ACCESS_EXTERNAL[symbol][0] == value
    if symbol.startswith('??_C@'):
        pos, at = unit.definitions[symbol]
        lit = unit.raw[unit.sections[at][4] + pos:unit.sections[at][4] + unit.sections[at][3]]
        lit = lit.split(b'\0')[0] + b'\0'
        return 'literal %r' % lit[:-1].decode('latin-1'), original.data(value, len(lit)) == lit
    if symbol.startswith('??_R0') and symbol.endswith('@8'):
        rtti = original.string(value + 8)
        return 'RTTI %s' % rtti, norm(rtti) == norm('.' + symbol[5:-2])
    if symbol.startswith('??_7'):
        try:
            rtti, at = original.vtable_class(value)
        except Exception:
            return 'vtable without RTTI', False
        cls = symbol[4:symbol.index('@@6B') + 2]
        return 'vtable RTTI %s offset %#x' % (rtti, at), norm(rtti) == norm('.?AV' + cls)
    if symbol in EXTERNAL:
        return ('external' + (' (evidence name)' if norm(names.get(value, '')) == norm(symbol) else ''),
                EXTERNAL[symbol] == value)
    if symbol in unit.bodies and any(lo <= value < hi for lo, hi in TEXT):
        ok, why = support(unit, symbol, value, stack)
        tag = 'support body exact at the bound address (not counted here)'
        if '%08x' % value in elsewhere:
            tag = 'body exact at the bound address; row counted by %s' % ', '.join(sorted(set(elsewhere['%08x' % value])))
        return (tag if ok else 'support body: ' + why), ok
    if norm(names.get(value, '')) == norm(symbol):
        return 'external (evidence name)', True
    other = [u for u in U.values() if u is not unit and symbol in u.bodies]
    if other and any(lo <= value < hi for lo, hi in TEXT):
        ok, why = support(other[0], symbol, value, stack)
        return ('support body of the %s unit exact at the bound address' % other[0].key if ok else
                'support body (%s unit): %s' % (other[0].key, why)), ok
    if symbol not in unit.bodies and any(lo <= value < hi for lo, hi in DATA_SECTIONS):
        # static data (defined here or declared only: class-name statics, local statics, EH / RTTI records): one
        # address per symbol across every reference; named statics are asserted by content below
        LOCAL_STATIC.setdefault(symbol, value)
        return 'static data (one address per symbol)', True
    return None, False


def check(unit, address, name, own, stack):
    """Verify every relocation of `name` placed at `address`; return (targets, failures, local_eh)."""
    targets, failures, local_eh = {}, [], []
    for offset, symbol, value in relocs(unit, address, name):
        where = '%08x+%#x' % (address, offset)
        if nb.LOCAL_EH.match(symbol):
            local_eh.append(symbol)
            continue
        how, ok = classify(unit, symbol, value, where, own, stack)
        if how is None:
            failures.append('%s %s -> %#x: unbound%s' % (where, symbol[:90], value,
                                                          (' (' + names[value][:60] + ')') if value in names else ''))
            continue
        if not ok:
            failures.append('%s %s -> %#x: %s' % (where, symbol[:90], value, how))
            continue
        if not bind(symbol, value, where):
            failures.append('%s %s -> %#x: second address for one symbol' % (where, symbol[:90], value))
            continue
        targets[symbol] = '%#x (%s)' % (value, how)
    return targets, failures, sorted(set(local_eh))


def support(unit, symbol, value, stack):
    key = (unit.key, symbol, value)
    if key in SUPPORT:
        return SUPPORT[key]
    if key in stack:
        return True, 'recursive'
    if not body_exact_at(unit, symbol, value):
        SUPPORT[key] = (False, 'the body compiled here is not exact at %#x' % value)
        return SUPPORT[key]
    targets, failures, _ = check(unit, value, symbol, OWN_CURRENT, stack | {key})
    SUPPORT[key] = (not failures, '; '.join(failures)[:300] if failures else 'ok')
    SUPPORT_TARGETS['%s %s' % (unit.key, symbol)] = {'address': '%#x' % value, 'verified_targets': targets,
                                                    'failures': failures}
    return SUPPORT[key]


# fixed point: rows whose bytes are exact but whose targets cannot all be verified are dropped, and so are rows
# calling a dropped row
candidates = {}
for address, key, name in ROWS:
    body, refs = U[key].bodies[name]
    target, target_refs, _ = match.target('2008-06', '%08x' % address)
    candidates[address] = (key, name, len(body), len(target),
                           len(target) == len(body) and match.exact_match(target, target_refs, body, refs))
alive = {a for a, v in candidates.items() if v[4]}
DROP_REASON = {}
ALL_SUPPORT_FAILURES = {}
while True:
    OWN_CURRENT = {candidates[a][1]: a for a in alive}
    BINDING.clear()
    CONFLICTS.clear()
    SUPPORT.clear()
    SUPPORT_TARGETS.clear()
    LOCAL_STATIC.clear()
    results = {}
    for a in sorted(alive):
        key, name = candidates[a][:2]
        results[a] = check(U[key], a, name, OWN_CURRENT, frozenset())
    dropped = {a for a, r in results.items() if r[1]}
    ALL_SUPPORT_FAILURES.update({k: v for k, v in SUPPORT.items() if not v[0]})
    if not dropped:
        break
    for a in dropped:
        DROP_REASON[a] = results[a][1]
    alive -= dropped

# a dropped row's own symbol must not be accepted as a support body of a counted row
_dropped_syms = {candidates[a][1]: a for a in candidates if a not in alive}
for a in sorted(alive):
    for t in results[a][0]:
        assert t not in _dropped_syms, ('counted row calls a dropped row', hex(a), t)
assert not CONFLICTS, CONFLICTS

rows, not_counted = [], []
for a in sorted(candidates):
    key, name, size, tsize, exact = candidates[a][:5]
    if a in alive:
        targets, _, local_eh = results[a]
        rows.append({'address': '%08x' % a, 'unit': key, 'symbol': name, 'size': size, 'target_size': tsize,
                     'exact': True, 'verified_targets': targets, 'local_eh': local_eh})
    else:
        why = DROP_REASON.get(a) or ['%d / %d B, bytes differ' % (size, tsize)]
        # written as text (never a quoted bare address of a row not counted here)
        not_counted.append('%08x %s (%s unit): not counted; %s' % (a, name[:80], key, '; '.join(why)[:400]))
if DISCOVER:
    for line in not_counted:
        print('NOT COUNTED', line)
    for (k, sym, val), (ok, why) in sorted(ALL_SUPPORT_FAILURES.items(), key=lambda x: x[0][2]):
        if not ok and 'not exact' in why:
            print('SUPPORT NOT EXACT %#x %s %s' % (val, k, sym[:110]))
        elif not ok and 'support body' not in why:
            print('SUPPORT UNBOUND %#x %s %s: %s' % (val, k, sym[:80], why[:300]))
# candidates that stay uncounted are expected (callee chains of the owner's container / worker bodies); they are
# recorded as text. The Profile getters and the ContentProvider ctor/dtor family must survive.
assert DISCOVER or {0x5631c0, 0x563230, 0x5634b0, 0x5613f0, 0x562e60, 0x563050} <= alive, sorted(map(hex, alive))

# ---- evidence of identity ----------------------------------------------------------------------------------------------
IDENTITY = {}
# Profile getters: the initializers name the properties ("Profile" / VideoMemory ...), each getter reserves the
# 0x84-byte SpecData and calls the constructor 00501ae0 and the destructor 005631c0
for _getter, _off in [(0x563230, 4), (0x563260, 8), (0x563290, 0xc), (0x563940, 0x64)]:
    assert original.data(_getter, 6) == b'\x81\xec\x84\x00\x00\x00', hex(_getter)
    assert original.data(_getter + 0x10, 3) == bytes([0x8b, 0x70, _off]), hex(_getter)
for _a, _name in [(0x7f2c60, 'VideoMemory'), (0x7f2c90, 'CpuSpeed'), (0x7f2cc0, 'CpuCount')]:
    assert FUNCTIONS[_a]['strings'] == ['Profile', _name], (hex(_a), FUNCTIONS[_a]['strings'])
for _a in (0x563230, 0x563260, 0x563290, 0x563430, 0x5638c0, 0x563940, 0x563970, 0x563a50):
    assert 0x501ae0 in [int(x, 16) for x in FUNCTIONS[_a]['call_targets']], hex(_a)
    assert 0x5631c0 in [int(x, 16) for x in FUNCTIONS[_a]['call_targets']], hex(_a)
for _a, _what in [(0x5632c0, 'osVer'), (0x563330, 'osPlatformId')]:
    assert norm(names.get(_a, '')).startswith('?%s@DebugSettings@RBX@@' % _what), (hex(_a), names.get(_a))
    IDENTITY['%08x' % _a] = 'evidence name %s (GetVersionExA)' % names[_a][:60]
assert original.string(0x82dfc8) == 'HKEY_LOCAL_MACHINE\\HARDWARE\\DESCRIPTION\\System\\BIOS\\SystemProductName'
assert original.string(0x82e028) == 'HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\'
IDENTITY['getters'] = ('DebugSettings "Profile" getters: the 0x84-byte stack SpecData (constructor 00501ae0, counted by '
                       'app-unit500-working.json) read at +0x0 / +0x4 / +0x8 / +0xc / +0x10 / +0x48 / +0x64 / +0x68; '
                       'names from the committed DebugSettings.h, the property initializers 007f2c60 / 007f2c90 / '
                       '007f2cc0 ("Profile" / VideoMemory / CpuSpeed / CpuCount) and the donor DebugSettings.cpp')
IDENTITY['contentprovider'] = (
    'util/ContentProvider.cpp rows: ContentProvider() 00562c30 / ~ContentProvider 00562e60 store the ContentProvider '
    'vtables (RTTI .?AVContentProvider@RBX@@, verified per relocation), DescribedNonCreatable<ContentProvider> '
    '005613f0 calls NonFactoryProduct<Instance, sContentProvider>() 0055c080 and classDescriptor 005612b0; '
    'processRequests 005620f0 is the worker the ContentProvider ctor binds (functor manager 005613b0); loadContent '
    '00561980, getFile 00561e30, registerFile 00560200 and the container instances are identified by their verified '
    'call / data targets.')

# ---- vtables (current headers; there is no pending build) ------------------------------------------------------------


def compiled_vtables(unit):
    out = {}
    for name, (start, sec) in unit.definitions.items():
        if not name.startswith('??_7'):
            continue
        table = unit.sections[sec]
        end = min([x for x in unit.starts.get(sec + 1, ()) if x > start] + [table[3]])
        slots = {}
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', unit.raw, table[5] + 10 * i)
            if start <= offset < end:
                slots[(offset - start) // 4] = unit.symbols[index][0]
        out[name] = slots
    return out


OWN = {candidates[a][1]: a for a in alive}
vtable_checks, vtable_failures = {}, []
for _key in ('cp',):
    for _vt, _slots in sorted(compiled_vtables(U[_key]).items()):
        if _vt not in BINDING or 'ContentProvider@RBX@@6B' not in _vt or not _vt.startswith('??_7ContentProvider@'):
            continue
        _at = BINDING[_vt][0]
        _checked = []
        for _k, _s in sorted(_slots.items()):
            _got = struct.unpack('<I', original.data(_at + 4 * _k, 4))[0]
            if _s in ALIAS and ALIAS[_s] in OWN:
                _s = ALIAS[_s]   # ??_E slot folded onto the ??_G row
            if _s in OWN:
                ok = OWN[_s] == _got
                _checked.append('%d %s = %#x (own row)' % (_k, _s[:70], _got))
            elif _s in U[_key].bodies:
                ok = body_exact_at(U[_key], _s, _got)
                _checked.append('%d %s = %#x (compiled body %s at the slot)' % (_k, _s[:70], _got,
                                                                                 'exact' if ok else 'NOT exact'))
                ok = ok or True  # a non-exact inherited slot body is recorded, not asserted (not a counted row)
            elif norm(names.get(_got, '')) == norm(_s):
                ok = True
                _checked.append('%d %s = %#x (evidence name)' % (_k, _s[:70], _got))
            else:
                ok = True
                _checked.append('%d %s = %#x (declared only; not verified)' % (_k, _s[:70], _got))
            if not ok:
                vtable_failures.append((_vt, _k, _s, hex(_got)))
        vtable_checks[_vt] = {'address': '%#x' % _at, 'checked_slots': _checked}
assert not vtable_failures or DISCOVER, vtable_failures
# The ??_E adjustor thunks and ??_G of ContentProvider must be the slots the original vtables hold
_slot_rows = {a for v in vtable_checks.values() for c in v['checked_slots'] if '(own row)' in c
              for a in [int(c.split(' = ')[1].split()[0], 16)]}
for _a in (0x562de0, 0x562df0, 0x562e00, 0x562e10, 0x562e20, 0x562e30, 0x562e40, 0x562e50):
    assert DISCOVER or _a in _slot_rows, hex(_a)
# ??_G 00563050 is in no ContentProvider vtable slot (the primary GuidItem vtable 0082df6c has no destructor slot, as
# compiled); it is the jump target of every ??_E adjustor thunk above (own-row REL32 targets verified per row)
for _a in (0x562de0, 0x562df0, 0x562e00, 0x562e10, 0x562e20, 0x562e30, 0x562e40, 0x562e50):
    _r = next(r for r in rows if r['address'] == '%08x' % _a)
    assert DISCOVER or _r['verified_targets'].get('??_EContentProvider@RBX@@UAEPAXI@Z', '').startswith('0x563050 (own'), _r

# ---- range map ----------------------------------------------------------------------------------------------------------
exact_rows = sorted('%08x' % a for a in alive)
range_rows = sorted(a for a in FUNCTIONS if LO <= a < HI)
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if LO <= int(a, 16) < HI}
UNITS = [
    ('content provider', 0x560000, 0x563070),
    ('shared helpers', 0x563070, 0x563100),
    ('debug settings', 0x563100, 0x564000),
]
unit_rows = {}
for a in range_rows:
    unit = [u for u, lo, hi in UNITS if lo <= a < hi]
    assert len(unit) == 1, hex(a)
    unit_rows.setdefault(unit[0], []).append(a)
# boundary evidence read from the binary
assert original.vtable_class(0x82deec)[0] == '.?AVContentProvider@RBX@@'
assert 0x563050 + FUNCTIONS[0x563050]['size'] <= 0x563070                     # ??_G ContentProvider ends the unit
assert original.data(0x563100, 6)[:1] == b'\xa0'                                # first DebugSettings getter (mov al)
assert 0x5638c0 in FUNCTIONS and norm(names.get(0x5632c0, '')).startswith('?osVer@DebugSettings')

UNIT_MAP = {
    'content provider 00560000..0056306f (continues from 0055bae0)': (
        'util/ContentProvider.cpp, the unit app-unit55c-working.json maps from ContentId isAsset 0055bae0: the '
        'vector<function<void(RequestResult, istream&)>> / list<ContentRequest> / map<ContentId, CachedContent> / '
        'vector<string> / set<T*> instances (\"vector<T> too long\" users 00560c20 _Insert_n, 00560a70 copy '
        'constructor, the _Buynode 00561490 / push_back pair), registerFile 00560200, findAssetFile / setAssetFolder '
        '00560460 / 00560590, ContentRequest copy / default constructors 00560ea0 / 00560fa0 and operator= 00560f00, '
        'classDescriptor<ContentProvider> 005612b0, the functor manager 005613b0 of bind_t<work_result, mf0<.., '
        'ContentProvider>>, DescribedNonCreatable<ContentProvider> 005613f0, the request-list bodies 00561530 / '
        '005616e0 / 005618e0, loadContent 00561980, getFile 00561e30, getContent 00561f20, the std istringstream / '
        'ifstream deleting destructors 00562090 / 005620c0 (msvcp90 header instances; library), processRequests '
        '005620f0, the remaining worker / cache helpers 005624b0..00562a30, ContentProvider() 00562c30, the ??_E '
        'adjustor thunks 00562de0..00562e50, ~ContentProvider 00562e60, 00562f70 and ??_G 00563050 (the last row '
        'before the shared helpers). Built here from the owner\'s committed files (read-only).'),
    'shared helpers 00563070..005630ff': (
        'boost::recursive_mutex::recursive_mutex 00563070 and two std::string COMDATs 00563090 / 005630e0 called from '
        'many units (ICF-shared header instances; library code, not recovered; the guid-registry-mutex probe lists '
        'them).'),
    'debug settings 00563100..00563fff (continues past 00564000)': (
        'v8datamodel/DebugSettings.cpp (settings-items owner: native-headers/v8datamodel/DebugSettings.h, '
        'native-classes/DebugSettings.cpp, tests/record_native_settings_items.py): the inline getters 00563100..'
        '005631b0 (bool / enum / double statics), ~SpecData 005631c0, the "Profile" getters 00563230..00563a76 '
        '(built here), the ProfilerWindow / ProfilerBucketTimeSpan setters 005639f0 / 00563a20, the '
        'FactoryProduct<DebugSettings, GlobalSettings::Item> rows 00563b40 / 00563be0, the GetImpl / GetSetImpl '
        'descriptor rows 00563a80..00563ec0, boost::any holder<double> 00563cd0 / 00563ce0, any::operator=<double> '
        '00563f10 (caller 0056d7f5 in another unit), any_cast 00563f60 and TypedPropertyDescriptor<double> '
        '00563ff0 (slot 0 of three vtables 0082e1f4 / 0082e490 / 00848bc0: ICF-shared). Most rows are counted by '
        'settings-items-working.json.'),
    'excluded': 'No CRobloxApp / CMainFrame / CRobloxDoc / CRobloxView row lies in the range.',
}
NOT_ATTEMPTED = {
    'ContentProvider rows without a committed body that verifies here': (
        'setAssetFolder 00560590, findAssetFile 00560460, the vector copy constructor / _Insert_n 00560a70 / '
        '00560c20 and their catch funclets, ContentRequest::operator= 00560f00, list<ContentRequest> _Buynode '
        '00561490, the request-list bodies 00561530 / 005616e0 / 005618e0, getContent 00561f20, the worker helpers '
        '005624b0..00562a30 and 00562f70: the owner\'s committed files do not define an exact body for them under '
        'this profile (or define none); recovering them is the ContentProvider owner\'s work (proposal).'),
    'DebugSettings inline getters / profiler setters 00563150..005631b0, 005639f0, 00563a20': (
        'statics of classes without a native declaration (ModelInstance::showModelCoord 009753d9 is pending in '
        'settings-items, Workspace::showWorldCoord 00976899, the Profiling statics 0094f640 / 0094f638, '
        'DistributedPhysics 00974e61, 30FpsThrottle 00946790, EThrottle 0097ac54): no evidence-backed owner '
        'declaration; not attempted.'),
    'boost::any holder<double> / any_cast / any::operator= / TypedPropertyDescriptor<double> 00563cd0..00563ff0': (
        'boost library templates and ICF-shared reflection virtuals referenced from other units; not recovered.'),
}
REJECTED = {}
PROPOSALS = {
    'settings-items owner (native-classes/DebugSettings.cpp, tests/record_native_settings_items.py)': (
        'The DebugSettings "Profile" getters 00563230..00563a50, gfxcard 005634b0, systemProductName 00563370, osVer '
        '005632c0, osPlatformId 00563330 and the implicit ~SpecData 005631c0 are exact in '
        'native-classes/AppUnit560DebugProfile.cpp against the committed DebugSettings.h and AppUnit500/RenderSpecData.h '
        '(no header change). If the owner prefers them in DebugSettings.cpp, move the bodies (that unit would then '
        'need <windows.h>, <setupapi.h> and G3D/RegistryUtil.h) and drop them from this receipt.'),
    'ContentProvider owner (util/NativeContentProvider.h, native-classes/ContentProvider*.cpp)': (
        'The committed ContentProvider.cpp / GetFile / LoadContent / RegisterFile / WorkerBinding units compile under '
        'the document-swap profile to exact bodies whose call / data targets all verify; app-unit560-working.json '
        'counts those rows in 00560000..00564000 (the bodies are not copied). The trial receipts '
        '(content-provider-layout-trial.json and others) count none of them, so nothing is double-counted. Open: '
        'getContent 00561f20, setAssetFolder 00560590, findAssetFile 00560460 and the worker helpers.'),
}

receipt = {
    'class': 'RBX::DebugSettings "Profile" getters and the util/ContentProvider.cpp rows of the application range '
             '00560000..00564000 (2008-06), inactive',
    'compiler': 'VS2008 RTM 21022',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)): nb.sha(p) for p in list(SOURCES.values()) + [Path(__file__).resolve()]
                + HEADERS},
    'objects': {k: nb.sha(p) for k, p in OBJ.items()},
    'unit_map': UNIT_MAP,
    'unit_rows': {u: {'rows': len(v), 'span': '%#x..%#x' % (v[0], v[-1])} for u, v in unit_rows.items()},
    'range_rows_total': len(range_rows),
    # Written as 'ADDR counted by RECEIPT' text, never as a quoted bare address: some recorders (local_backpack,
    # viewnew_brick_build, viewnew_part_mesh) treat any '"ADDR"' in another receipt as counted there and drop it.
    'range_rows_counted_by_other_receipts': ['%s counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()],
    'rows': rows,
    'row_identity': IDENTITY,
    'support_body_targets': SUPPORT_TARGETS,
    'bounds_evidence_support_splits': SPLITS,
    'local_statics': {k: '%#x' % v for k, v in sorted(LOCAL_STATIC.items())},
    'vtables_current_headers': vtable_checks,
    'not_counted': not_counted,
    'pending_build_only': [],
    'not_attempted': NOT_ATTEMPTED,
    'rejected': REJECTED,
    'proposals': PROPOSALS,
    'exact_function_rows': exact_rows,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
if not DISCOVER:
    RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit560: %d counted exact rows (%s); %d range rows (%d counted elsewhere)' % (
    len(exact_rows), ' '.join(exact_rows), len(range_rows), len(range_counted)))
