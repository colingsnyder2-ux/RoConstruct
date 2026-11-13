"""Verify the inactive 2008-06 native rows of the application range 00450000..00454000 and record its unit map.

Unit map (boundary evidence in the receipt's `unit_map` / `unit_blocks`, asserted below; rows counted by other receipts
are listed as 'ADDR counted by RECEIPT' text, never as a quoted bare address):
  * 00450000..00454000  entirely inside the CRobloxDoc translation unit (RobloxDoc.cpp, which starts at 0044f1a0 in
                        the app-unit448 map and continues to 00455d3f in the app-unit454 map): the CRobloxDoc
                        message handlers (entries of the message map 00817f0c), CRobloxDoc vtable 00817ce4 slots,
                        CRuntimeClass "CRobloxDoc" CreateObject, VerbBinder<CRobloxDoc, CDocument> (vtable 00817c24),
                        the shared CameraVerb destructors of the camera command vtables (CameraTiltUpCommand 00817a94
                        ...), STL instances (ostream sentry / inserter, map<const Name*, const ICreator*>::find) and the
                        RBX ServiceProvider / Creatable / FactoryProduct / Name COMDAT instances. CRobloxDoc is a
                        maintainer exclusion: its rows are mapped only.

Build (VS2008 RTM 21022, document-swap flags), current native headers only (read-only):
  * native-classes/AppUnit450ServiceFind.cpp compiled with native-headers/boost-noinline-shared-destructor first on
    the include path: ServiceProvider::find<C>() const for ChangeHistoryService / Visit / RunService /
    Soundscape::SoundService (the original calls ~shared_ptr<Instance> out of line at 00600660; the same profile as
    record_native_app_unit454_2008.py / record_native_service_history.py). The same source under the default boost
    header is also compiled and recorded as the rejected variant (404 vs 320 B).

Every relocation of a counted row is resolved to the address the original instruction uses and verified, one address
per symbol over all rows: imports by DLL export name, own rows by their row address, rows counted by other receipts by
that receipt (and the compiled body must be exact there), helper bodies compiled here by being exact at the bound
address, own statics by consistency inside .data/.rdata, the remaining externals by evidence name or by the bindings
other committed recorders use. A row is counted only when no other receipt counts it.
Writes work/2008-06/shared-layouts/app-unit450-working.json. NATIVE_APP_UNIT450_DISCOVER=1 lists unbound targets and
non-exact rows instead of asserting.
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
OUT = R / 'out/app-unit450'
OUT.mkdir(parents=True, exist_ok=True)
SOURCE = R / 'native-classes/AppUnit450ServiceFind.cpp'
NOINLINE = R / 'native-headers/boost-noinline-shared-destructor'
HEADERS = [R / 'native-headers' / h for h in (
    'util/Object.h', 'util/Name.h', 'v8tree/Service.h', 'v8tree/Instance.h', 'v8datamodel/ChangeHistoryService.h',
    'util/RunStateOwner.h', 'util/Sound.h', 'v8datamodel/Visit.h')] + [NOINLINE / 'boost/shared_ptr.hpp']
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit450-working.json'
LO, HI = 0x450000, 0x454000
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT450_DISCOVER'))


def build(name, src, pre=()):
    obj = OUT / (name + '.obj')
    flags = list(pre) + nb.flags() + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log[-4000:]
    return obj, flags


OBJ, FLAGS = {}, {}
OBJ['find'], FLAGS['find'] = build('AppUnit450ServiceFind', SOURCE, ['/I' + str(NOINLINE)])
OBJ['default'], FLAGS['default'] = build('AppUnit450ServiceFind_default', SOURCE)

original = nb.Original()
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
FUNCTIONS = {}
for line in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines():
    x = json.loads(line)
    FUNCTIONS[int(x['addr'], 16)] = x


# ---- counting rules ----------------------------------------------------------------------------------------------
def counted_elsewhere():
    """Rows other receipts count: their top-level exact_function_rows (or an equivalent key); for receipts without
    one, every row object marked exact anywhere in the receipt (a conservative reading of their counted lists)."""
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
        rows = []
        for key in ('exact_function_rows', 'exact_addresses', 'exact_unique_addresses', 'exact_distinct_addresses'):
            if isinstance(data.get(key), (list, dict)):
                rows = list(data[key])
                break
        else:
            def walk(o):
                if isinstance(o, list):
                    for e in o:
                        walk(e)
                elif isinstance(o, dict):
                    if 'address' in o and o.get('exact') is True:
                        rows.append(o['address'])
                    for v in o.values():
                        walk(v)
            walk(data)
        for r in rows:
            r = r.get('address', '') if isinstance(r, dict) else str(r)
            m = re.match(r'(?:0x)?([0-9a-fA-F]{6,8})', r)
            if m:
                out.setdefault('%08x' % int(m.group(1), 16), []).append(Path(path).name)
    return out


elsewhere = counted_elsewhere()

# ---- rows --------------------------------------------------------------------------------------------------------
SP = '@ServiceProvider@RBX@@'
CHS = 'VChangeHistoryService@RBX@@'
VISIT = 'VVisit@RBX@@'
RUN = 'VRunService@RBX@@'
SOUND = 'VSoundService@Soundscape@RBX@@'
ROWS = [
    (0x452a00, '??$find@' + CHS + SP + 'QBEPAVChangeHistoryService@1@XZ'),
    (0x452b40, '??$find@' + VISIT + SP + 'QBEPAVVisit@1@XZ'),
    (0x452c80, '??$find@' + RUN + SP + 'QBEPAVRunService@1@XZ'),
    (0x452dc0, '??$find@' + SOUND + SP + 'QBEPAVSoundService@Soundscape@1@XZ'),
]
for _a, _s in ROWS:
    assert '%08x' % _a not in elsewhere, (hex(_a), elsewhere['%08x' % _a])

# Targets that are neither rows, imports nor compiled exact helpers: symbol -> (address, proof)
KNOWN = {
    '?call_once@boost@@YAXP6AXXZAAJ@Z': (0x557330, 'boost.thread call_once (bound the same way by '
                                         'record_native_app_unit454_2008.py / record_native_service_history.py)'),
    '?newIndex@ServiceProvider@RBX@@SAIXZ': (0x572690, 'ServiceProvider::newIndex (bound the same way by '
                                             'record_native_app_unit448_2008.py / record_native_app_unit454_2008.py)'),
    '?findServiceByClassName@ServiceProvider@RBX@@QBE?AV?$shared_ptr@VInstance@RBX@@@boost@@ABVName@2@@Z': (
        0x572a90, 'ServiceProvider::findServiceByClassName (bound the same way by record_native_app_unit454_2008.py / '
        'record_native_service_history.py)'),
    '?resize@?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@'
    'QAEXIV?$shared_ptr@VInstance@RBX@@@boost@@@Z': (
        0x4124c0, 'vector<shared_ptr<Instance> >::resize (bound the same way by record_native_app_unit454_2008.py / '
        'record_native_filtered_selection.py)'),
    '??1?$shared_ptr@VInstance@RBX@@@boost@@QAE@XZ': (0x600660, 'evidence name (ICF-shared destructor)'),
    '?declare@Name@RBX@@SAABV12@PBDH@Z': (0x553f90, 'evidence name'),
    '??4shared_count@detail@boost@@QAEAAV012@ABV012@@Z': (0x4025b0, 'evidence name'),
}
DATA_SECTIONS = [(original.image + s.VirtualAddress, original.image + s.VirtualAddress + s.Misc_VirtualSize)
                 for s in original.pe.sections if s.Name.rstrip(b'\0') in (b'.data', b'.rdata')]
TEXT = [(original.image + s.VirtualAddress, original.image + s.VirtualAddress + s.Misc_VirtualSize)
        for s in original.pe.sections if s.Name.rstrip(b'\0') == b'.text'][0]
BINDING = {}
UNBOUND = []
HELPERS = {}
COUNTED_TARGETS = {}


def bind(symbol, value, where):
    prev = BINDING.setdefault(symbol, (value, where))
    assert prev[0] == value, ('one address per symbol', symbol, hex(prev[0]), prev[1], hex(value), where)


def body_exact_at(bodies, symbol, value):
    if symbol not in bodies or not TEXT[0] <= value < TEXT[1]:
        return False
    target, target_refs, _ = match.target('2008-06', '%08x' % value)
    return bool(match.exact_match(target, target_refs, *bodies[symbol]))


def verify(build, obj, rows, check_targets=True):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    own = {s: a for a, s in ROWS}
    out = []
    for address, name in rows:
        assert name in bodies, (build, hex(address), name, [n for n in bodies if name[:30] in n][:5])
        body, refs = bodies[name]
        target, target_refs, _ = match.target('2008-06', '%08x' % address)
        exact = match.exact_match(target, target_refs, body, refs)
        row = {'address': '%08x' % address if exact else '%#x' % address, 'symbol': name, 'size': len(body),
               'target_size': len(target), 'exact': bool(exact), 'build': build, 'verified_targets': {},
               'local_eh': []}
        out.append(row)
        if not exact or not check_targets:
            continue
        start, section = definitions[name]
        table = sections[section]
        code = raw[table[4] + start:]
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
            offset -= start
            if not 0 <= offset < len(body):
                continue
            symbol = symbols[index][0]
            if kind == 20:
                value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            else:
                value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
            where = '%08x+%#x' % (address, offset)
            if nb.LOCAL_EH.match(symbol):
                row['local_eh'].append(symbol)
                continue
            how = None
            hit = original.imported(value)
            counted_by = sorted(set(elsewhere.get('%08x' % value, [])))
            if hit is not None:
                assert hit[1] == nb.plain(symbol), (where, symbol, hex(value), hit)
                how = '%s!%s' % hit
            elif symbol in own:
                assert own[symbol] == value, (where, symbol, hex(value))
                how = 'own row'
            elif counted_by and symbol in bodies:
                # a row another receipt counts: the body compiled here must be exact at that address
                assert body_exact_at(bodies, symbol, value), ('counted-elsewhere body not exact', where, symbol,
                                                              hex(value))
                COUNTED_TARGETS[symbol] = '%#x counted by %s' % (value, ', '.join(counted_by))
                how = 'row counted by %s (compiled body exact at the bound address)' % ', '.join(counted_by)
            elif body_exact_at(bodies, symbol, value):
                # helper / COMDAT body compiled here but not a row of this range: exact at the bound address
                HELPERS.setdefault(symbol, '%#x' % value)
                how = 'helper body exact at the bound address (not counted)'
                if symbol in KNOWN:
                    assert KNOWN[symbol][0] == value, (where, symbol, hex(value))
            elif symbol in KNOWN:
                assert KNOWN[symbol][0] == value, (where, symbol, hex(value), hex(KNOWN[symbol][0]))
                proof = KNOWN[symbol][1]
                if 'evidence name' in proof:
                    assert names.get(value, '') == symbol, (where, symbol, hex(value), names.get(value))
                how = 'external: ' + proof
            elif symbol in definitions and symbol not in bodies:
                assert any(lo <= value < hi for lo, hi in DATA_SECTIONS), (where, symbol, hex(value))
                how = 'own static (bound by consistency)'
            elif names.get(value, '') == symbol:
                how = 'external (evidence name)'
            if how is None:
                UNBOUND.append((where, symbol, hex(value), names.get(value, '')[:80]))
                continue
            bind(symbol, value, where)
            row['verified_targets'][symbol] = '%#x (%s)' % (value, how)
    return out


rows_find = verify('find', OBJ['find'], ROWS)
rows_default = verify('default', OBJ['default'], ROWS, check_targets=False)
not_exact = [r for r in rows_find if not r['exact']]
if DISCOVER:
    for u in UNBOUND:
        print('UNBOUND', u)
    for r in not_exact:
        print('NOT EXACT', r['address'], r['size'], r['target_size'], r['symbol'][:100])
assert not UNBOUND or DISCOVER, UNBOUND
assert not not_exact or DISCOVER, [(r['address'], r['symbol'][:80]) for r in not_exact]
for symbol, (address, _) in KNOWN.items():
    assert address in FUNCTIONS or original.imported(address) is not None, (symbol, hex(address))
# the default boost header inlines ~shared_ptr<Instance>: recorded as the rejected variant
assert not any(r['exact'] for r in rows_default), [r['address'] for r in rows_default if r['exact']]
DEFAULT_SIZES = sorted({r['size'] for r in rows_default})
# each find row calls the out-of-line destructor 0x600660 twice and is reached from create<C> rows of this unit
for a, _ in ROWS:
    assert FUNCTIONS[a]['call_targets'].count('00600660') == 1, hex(a)
CREATE_CALLERS = {0x452a00: 0x453000, 0x452c80: 0x4530f0, 0x452dc0: 0x4531e0}
for f, c in CREATE_CALLERS.items():
    assert '%08x' % f in FUNCTIONS[c]['call_targets'], (hex(f), hex(c))


# ---- unit map evidence -------------------------------------------------------------------------------------------
def holds_string(address, text):
    """The row's bytes hold a DIR32 pointer to that exact NUL-terminated string."""
    body = original.data(address, FUNCTIONS[address]['size'])
    for i in range(len(body) - 3):
        v = struct.unpack_from('<I', body, i)[0]
        if any(lo <= v < hi for lo, hi in DATA_SECTIONS):
            try:
                if original.string(v) == text:
                    return True
            except Exception:
                pass
    return False


RDATA = [s for s in original.pe.sections if s.Name.rstrip(b'\0') == b'.rdata'][0]
RDATA_VA = original.image + RDATA.VirtualAddress
RDATA_BYTES = RDATA.get_data()


def in_vtable(address, rtti_prefix):
    """Some original vtable slot holds the row and the vtable's complete-object locator names that class."""
    pat = struct.pack('<I', address)
    for m in re.finditer(re.escape(pat), RDATA_BYTES):
        if m.start() % 4:
            continue
        ref = RDATA_VA + m.start()
        for back in range(0, 200):
            try:
                rtti, _ = original.vtable_class(ref - 4 * back)
            except Exception:
                continue
            if rtti and rtti.startswith(rtti_prefix):
                return True
            if rtti:
                break
    return False


def in_table(address, table, entries):
    """The row is one of the first `entries` dwords of an original table (the CRobloxDoc message map)."""
    return any(d(table + 4 * k) == address for k in range(entries))


BLOCKS = [
    ('rbx CRobloxDoc unit (RobloxDoc.cpp; maintainer exclusion, RBX template COMDATs)', LO, HI,
     [('string', 0x4500d0, '/game/visit.ashx\')()"'), ('string', 0x4501c0, 'Server'), ('string', 0x450c00, '%.3gfps'),
      ('string', 0x450f30, 'rbxm'), ('string', 0x451b60, 'ReportAbuse'),
      ('string', 0x452fc2, 'An error occured while creating the document')],
     [('vt', 0x4508f0, '.?AVCRobloxDoc@@'), ('vt', 0x452f60, '.?AVCRobloxDoc@@'), ('vt', 0x4533f0, '.?AVCRobloxDoc@@'),
      ('vt', 0x4518e0, '.?AV?$VerbBinder@VCRobloxDoc@@VCDocument@@@@'),
      ('vt', 0x451170, '.?AVCameraTiltUpCommand@RBX@@')]),
]
range_rows = sorted(a for a in FUNCTIONS if LO <= a < HI)   # every row kind (code, gen, eh), as app-unit454
code_rows = [a for a in range_rows if FUNCTIONS[a].get('kind', 'code') == 'code']
for a in range_rows:
    assert sum(lo <= a < hi for _, lo, hi, _, _ in BLOCKS) == 1, hex(a)
STRING_FAIL = []
for name, lo, hi, strings, vts in BLOCKS:
    for _, a, text in strings:
        ok = lo <= a < hi and holds_string(a, text)
        if not ok:
            STRING_FAIL.append((hex(a), text))
    for _, a, prefix in vts:
        assert lo <= a < hi and in_vtable(a, prefix), (name, hex(a), prefix)
assert not STRING_FAIL or DISCOVER, STRING_FAIL
# the CRobloxDoc handlers are entries of its message map 0x817f0c; 0x452f00 is CreateObject of the CRuntimeClass
# "CRobloxDoc" (0x8172c0: name, size 0x98, schema 0xffff, CreateObject, GetBaseClass); the camera command vtables share
# the deleting destructor 0x451170, which calls ~CameraVerb 0x4510f0 (then Verb::~Verb 0x5832c0)
assert all(in_table(a, 0x817f0c, 300) for a in (0x4500d0, 0x4501c0, 0x4502b0, 0x450a70, 0x450c00, 0x450d90,
                                                0x450f30, 0x453670, 0x453750, 0x4538b0, 0x453990, 0x453af0, 0x453c30))
assert original.string(d(0x8172c0)) == 'CRobloxDoc' and d(0x8172c4) == 0x98 and d(0x8172cc) == 0x452f00
assert FUNCTIONS[0x4510f0]['callers'] == ['00451170'] and FUNCTIONS[0x4510f0]['call_targets'] == ['005832c0']
assert names.get(0x451600, '').startswith('?find@?$_Tree@V?$_Tmap_traits@PBVName@RBX@@PBVICreator@2@')
assert len(FUNCTIONS[0x451600]['callers']) > 10

exact_rows = sorted({r['address'] for r in rows_find if r['exact']})
double = {a: elsewhere[a] for a in exact_rows if a in elsewhere}
assert not double, double
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if LO <= int(a, 16) < HI}
open_rows = ['%08x' % a for a in range_rows if '%08x' % a not in exact_rows and '%08x' % a not in range_counted]
open_code_rows = [a for a in open_rows if FUNCTIONS[int(a, 16)].get('kind', 'code') == 'code']

UNIT_MAP = {
    'rbx CRobloxDoc unit 0x450000..0x453fff (continues on both sides)': (
        'The whole range lies inside RobloxDoc.cpp (unit start 0x44f1a0 in the app-unit448 map, tail to 0x455d3f in '
        'the app-unit454 map). Evidence: CRobloxDoc message-map 0x817f0c entries 0x4500d0 / 0x4501c0 / 0x4502b0 '
        '(" -script \\"loadfile(\'" with "/game/visit.ashx", "/game/gameserver.ashx", "/game/join.ashx"), '
        '0x450a70 / 0x450c00 / 0x450d90 (update-UI "t %.4g", "%.3gfps", "%.3g%%"), 0x450f30 ("rbxm"), '
        '0x453670..0x453c30; CRobloxDoc vtable 0x817ce4 slots 0x4508f0 / 0x4513c0 / 0x452f60 / 0x4533f0; the '
        'CRuntimeClass "CRobloxDoc" (0x8172c0, object size 0x98) CreateObject 0x452f00; constructor pieces 0x451590 / '
        '0x451ac0 / 0x451b60 ("ReportAbuse", called by 0x452f60 and 0x4534ba), destructor 0x450450 and its EH '
        'helpers 0x451890 / 0x451940; "An error occured while creating the document" 0x452fc2 (eh row). Maintainer '
        'exclusion (CRobloxDoc): mapped only.'),
    'rbx VerbBinder<CRobloxDoc, CDocument>': (
        'vtable 0x817c24 slots 0x4518e0 / 0x451690 and 0x4515f0 (0x817c84), the bind helpers 0x451a10 / 0x451a60 '
        'called only by the CRobloxDoc constructor body 0x451b60: a Roblox template instantiated only with the '
        'excluded CRobloxDoc; mapped only.'),
    'rbx CameraVerb destructor': (
        '~CameraVerb 0x4510f0 (releases the selection shared_ptr count at +0x18, then Verb::~Verb 0x5832c0) and the '
        'deleting destructor 0x451170 (gen row) shared by the camera command vtables (CameraTiltUpCommand 0x817a94 '
        'and nine more, plus 0x830780). The implicit inline destructor is emitted here because CRobloxDoc constructs '
        'the commands (native NativeCameraCommands.h, camera-command owners); no unit of this range may build it '
        'without adding a helper that does not exist in the binary. Open.'),
    'rbx template COMDATs': (
        'ServiceProvider doGetClassIndex / callDoGetClassIndex / create<C>, Name::doDeclare<sVisit> / callDoDeclare, '
        'Creatable<Instance>::create<Visit>, shared_ptr<Visit>(Visit*, Deleter) and the Visit Creator::create are '
        'counted by app-unit448 (0x450840..0x450880, 0x452820 / 0x4528d0 / 0x452950, 0x453000 / 0x4530f0 / '
        '0x4531e0); shared_count<Visit*> 0x452790 by creatable-shared-count. Built and counted here: '
        'ServiceProvider::find<C>() const for ChangeHistoryService 0x452a00, Visit 0x452b40, RunService 0x452c80 '
        'and Soundscape::SoundService 0x452dc0 (open in app-unit448 under the default boost header).'),
    'library code': (
        'STL instances inside the unit: the ostream sentry destructor 0x451190 (pubsync on unitbuf) with its 5-byte '
        'jump 0x451200, the ostream inserter 0x451300 and its helper 0x451210 (callers 0x453c30, 0x46568b, 0x46c519), '
        'and std::map<const Name*, const ICreator*>::find 0x451600 (evidence name; called from more than 20 units). '
        'Library code, shared by many units: not recovered.'),
    'excluded': 'CRobloxDoc (the whole range); its rows are mapped only.',
}
NOT_EXACT = {
    'find<C>() const under the default boost header': (
        'not exact (%s vs 320 B): the native build inlines the shared_ptr<Instance> destructor that the original '
        'calls out of line at 0x600660; the rows are exact and counted only from the noinline-destructor build.'
        % '/'.join(str(s) for s in DEFAULT_SIZES)),
}
REJECTED = {
    'AppUnit450ServiceFind.cpp under the default boost header (rows_default)': NOT_EXACT[
        'find<C>() const under the default boost header'],
    'CameraVerb::~CameraVerb 0x4510f0 through an added helper that destroys a CameraVerb': (
        'not attempted: no such function exists in the binary (the only caller is the shared deleting destructor '
        '0x451170, emitted with the vtables CRobloxDoc instantiates).'),
}
PROPOSALS = {
    'util/Object.h / v8tree/Service.h (core owners), informational, no edit needed': (
        'this unit repeats the FactoryProduct::className and ServiceProvider doGetClassIndex / getClassIndex / find '
        'template definitions of AppUnit448_2008Services.cpp / AppUnit454_2008WndServices.cpp. find<C>() const '
        'matches only with ~shared_ptr<Instance> out of line (0x600660); create<C>() const needs it inlined.'),
    'app-unit448 owner, FYI': (
        'find<ChangeHistoryService / Visit / RunService / SoundService>() const 0x452a00 / 0x452b40 / 0x452c80 / '
        '0x452dc0, listed open in app-unit448, are counted here from the noinline-destructor build; no change to '
        'that recorder is needed (it does not count them).'),
}

paths = [Path(__file__).resolve(), SOURCE] + HEADERS
receipt = {
    'class': 'RBX ServiceProvider::find<C>() const instances of the application range 00450000..00454000 (2008-06), '
             'inactive',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM), document-swap flags, boost-noinline-shared-destructor first',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): nb.sha(p) for p in paths},
    'objects': {k: nb.sha(v) for k, v in OBJ.items()},
    'unit_map': UNIT_MAP,
    'unit_blocks': ['%#x..%#x %s' % (lo, hi, n) for n, lo, hi, _, _ in BLOCKS],
    'range_functions': len(range_rows),
    'range_code_rows': len(code_rows),
    # 'ADDR counted by RECEIPT' text, never a quoted bare address (local_backpack / viewnew_brick_build /
    # viewnew_part_mesh treat any quoted bare address in another receipt as counted there).
    'range_rows_counted_by_other_receipts': ['%s counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()],
    'range_rows_open': ['%#x (open, %s)' % (int(a, 16), FUNCTIONS[int(a, 16)].get('kind', 'code')) for a in open_rows],
    'range_code_rows_open': len(open_code_rows),
    'rows': rows_find,
    'rows_default_header_rejected': rows_default,
    'helper_bodies_not_counted': HELPERS,
    'targets_counted_by_other_receipts': COUNTED_TARGETS,
    'not_exact': NOT_EXACT,
    'rejected': REJECTED,
    'proposals': PROPOSALS,
    'exact_function_rows': exact_rows,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
text = json.dumps(receipt, indent=2) + '\n'
bare = set(re.findall(r'"([0-9a-f]{8})"', text))
assert bare <= set(exact_rows), sorted(bare - set(exact_rows))
if DISCOVER:
    print('DISCOVER: receipt not written; %d exact rows' % len(exact_rows), ' '.join(exact_rows), STRING_FAIL)
    sys.exit(0)
RECEIPT.write_text(text)
print('PASS app-unit450: %d counted exact rows (%s); %d range rows (%d code), %d counted elsewhere, %d open (%d code)'
      % (len(exact_rows), ' '.join(exact_rows), len(range_rows), len(code_rows), len(range_counted), len(open_rows),
         len(open_code_rows)))
