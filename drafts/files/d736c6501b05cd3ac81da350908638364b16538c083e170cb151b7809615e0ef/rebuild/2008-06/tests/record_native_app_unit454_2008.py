"""Verify the inactive 2008-06 native rows of the application range 00454000..00460000 and record its unit map.

Unit map (boundary evidence in the receipt's `unit_map` / `unit_blocks`, asserted below; rows counted by other receipts
are listed as 'ADDR counted by RECEIPT' text, never as a quoted bare address):
  * ..00455d3f          the CRobloxDoc unit tail (message handlers of message map 00817f0c, CRobloxDoc vtable
                        00817ce4 slots): maintainer exclusion, not recovered;
  * 00455d40..00458e6f  the CRobloxReportView unit (CRobloxReportView / ReportDocView / ReportPaneView vtables, the
                        CStatsItemRecord items, MarshaledListener<Instance, ChildAdded/ChildRemoved>) with the COMDAT
                        ServiceProvider / Creatable instances for Stats::StatsService (built and counted here);
  * 00458e70..0045afcf  the CRobloxView unit (CRobloxView vtable 0081933c, its verbs and VerbBinder): maintainer
                        exclusion (the verbs are leased by codex-layout), not recovered;
  * 0045afd0..0045fe1f  the CRobloxWnd unit (vtable 008199f4; RenderStatsItem, Stats::Item / TypedStatsItem
                        COMDATs) with the COMDAT Name / ServiceProvider / Creatable / FactoryProduct instances for
                        Camera and ControllerService and Instance::for_eachChild<void (*)(Instance*)> (built and
                        counted here);
  * 0045fe20..0045ffcf  the save-to-Roblox dialog unit (CPublishAsPlaceDialog / CUploadPlaceDialog /
                        CSaveModelToRobloxDialog / CSaveToRobloxDialog vtables, "DialogResult"): other owner;
  * 0045ffd0..          Scintilla MFC wrapper CScintillaCtrl (scintilla-mfc 1.20 library, continues past 00460000).

Builds (VS2008 RTM 21022, document-swap flags, /fp:fast), current native headers only (read-only):
  * native-classes/AppUnit454_2008ReportStats.cpp   StatsService doGetClassIndex / callDoGetClassIndex /
    create<StatsService>() const / Creatable create / shared_ptr, and boost::shared_dynamic_cast<Stats::Item> with its
    shared_ptr<Stats::Item>(const shared_ptr<Instance>&, dynamic_cast_tag) constructor; find<StatsService>() const from the same source
    compiled with native-headers/boost-noinline-shared-destructor first (the original find calls the
    shared_ptr<Instance> destructor out of line at 00600660, while create inlines it; same profile as
    record_native_service_history.py);
  * native-classes/AppUnit454_2008WndServices.cpp   the CRobloxWnd-unit rows, find<ControllerService>() const from
    the noinline-destructor build in the same way.

Every relocation of a counted row is resolved to the address the original instruction uses and verified, one address
per symbol over all rows: imports by DLL export name, type descriptors and vtables by original RTTI, own rows by their
row address, rows counted by other receipts by that receipt (and the compiled body must be exact there), constructors
by evidence name, class-name arrays by the string at the pushed address, helper bodies compiled here by being exact at
the bound address, the remaining externals by evidence name or by the bindings other committed recorders use.
Every Creator::create row is slot 0 of the original one-slot Creator vtable whose RTTI names the class; every
create<C> row's malloc size is recorded.
A row is counted only when no other receipt counts it.
Writes work/2008-06/shared-layouts/app-unit454-2008-working.json. NATIVE_APP_UNIT454_DISCOVER=1 lists unbound
targets and non-exact rows instead of asserting.
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
OUT = R / 'out/app-unit454-2008'
OUT.mkdir(parents=True, exist_ok=True)
SOURCES = {
    'report': R / 'native-classes/AppUnit454_2008ReportStats.cpp',
    'wnd': R / 'native-classes/AppUnit454_2008WndServices.cpp',
}
NOINLINE = R / 'native-headers/boost-noinline-shared-destructor'
HEADERS = [R / 'native-headers' / h for h in (
    'util/Object.h', 'util/Name.h', 'v8tree/Service.h', 'v8tree/Instance.h', 'stats/Stats.h',
    'v8datamodel/UserController.h', 'v8datamodel/Camera.h')] + [NOINLINE / 'boost/shared_ptr.hpp']
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit454-2008-working.json'
LO, HI = 0x454000, 0x460000
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT454_DISCOVER'))


def build(name, src, extra=(), pre=()):
    obj = OUT / (name + '.obj')
    flags = list(pre) + nb.flags() + ['/fp:fast'] + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log[-4000:]
    return obj, flags


OBJ, FLAGS = {}, {}
for _k, _src in SOURCES.items():
    OBJ[_k], FLAGS[_k] = build('AppUnit454_2008' + _k, _src)
    OBJ[_k + '_find'], FLAGS[_k + '_find'] = build('AppUnit454_2008' + _k + '_find', _src, (), ['/I' + str(NOINLINE)])

original = nb.Original()
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
FUNCTIONS = {}
for line in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines():
    x = json.loads(line)
    FUNCTIONS[int(x['addr'], 16)] = x


def norm(s):
    return s.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


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
CI = '?$Creatable@VInstance@RBX@@@'
DEL = 'VDeleter@' + CI
SP = '@ServiceProvider@RBX@@'


def create(c):
    return '??$create@%s@%sRBX@@SA?AV?$shared_ptr@%s@boost@@XZ' % (c, CI, c)


_ALL = {}
for _k in SOURCES:
    for _n, _, _ in match.coff_functions(Path(OBJ[_k]).read_bytes()):
        _ALL.setdefault(_n, _k)


def unique(test, what):
    hits = [n for n in _ALL if not nb.LOCAL_EH.match(n) and test(n)]
    assert len(hits) == 1, (what, hits)
    return hits[0]


def sptr(c, short=None):
    """shared_ptr<C>(C*, Creatable<Instance>::Deleter), resolved in the compiled objects."""
    return unique(lambda n: n.startswith('??$?0' + c + DEL) and ('?$shared_ptr@' + c + '@boost@@QAE@PA') in n, ('sptr', c))


def scount(c, short=None):
    """shared_count(C*, Creatable<Instance>::Deleter), resolved in the compiled objects."""
    return unique(lambda n: n.startswith('??$?0PA' + c + DEL) and '@shared_count@detail@boost@@QAE@' in n, ('scount', c))


def creator(c, name):
    return '?create@Creator@?$FactoryProduct@%sVInstance@2@$1?%s@2@3PADA@RBX@@UBE?AV?$shared_ptr@VObject@RBX@@@boost@@XZ' % (
        c, name)


STATS = 'VStatsService@Stats@RBX@@'
CTRL = 'VControllerService@RBX@@'
CAM = 'VCamera@RBX@@'
# (build, row, symbol)
ROWS_SPEC = [
    ('report', 0x455ea0, '??$doGetClassIndex@' + STATS + SP + 'SAIXZ'),
    ('report', 0x456400, '??$callDoGetClassIndex@' + STATS + SP + 'SAXXZ'),
    ('report_find', 0x457b60, '??$find@' + STATS + SP + 'QBEPAVStatsService@Stats@1@XZ'),
    ('report', 0x458610, '??$create@' + STATS + SP + 'QBEPAVStatsService@Stats@1@XZ'),
    ('report', 0x458590, create(STATS)),
    ('report', 0x456f10, sptr(STATS, ('2', '3'))),
    # boost::shared_dynamic_cast<Stats::Item>(const shared_ptr<Instance>&) and its dynamic_cast_tag constructor
    ('report', 0x456ee0, unique(lambda n: n.startswith('??$shared_dynamic_cast@VItem@Stats@RBX@@VInstance@3@@boost@@'),
                                'shared_dynamic_cast<Item>')),
    ('report', 0x456360, unique(lambda n: n.startswith('??$?0VInstance@RBX@@@?$shared_ptr@VItem@Stats@RBX@@@boost@@QAE@')
                                and 'dynamic_cast_tag' in n, 'shared_ptr<Item>(dynamic_cast_tag)')),
    ('wnd', 0x45b240, '??$doDeclare@$1?sCamera@RBX@@3PADA@Name@RBX@@CAABV01@XZ'),
    ('wnd', 0x45b6f0, '??$callDoDeclare@$1?sCamera@RBX@@3PADA@Name@RBX@@CAXXZ'),
    ('wnd', 0x45b2b0, '??$doGetClassIndex@' + CTRL + SP + 'SAIXZ'),
    ('wnd', 0x45b820, '??$callDoGetClassIndex@' + CTRL + SP + 'SAXXZ'),
    ('wnd_find', 0x45dce0, '??$find@' + CTRL + SP + 'QBEPAVControllerService@1@XZ'),
    ('wnd', 0x45de20, '??$create@' + CTRL + SP + 'QBEPAVControllerService@1@XZ'),
    ('wnd', 0x45c580, create(CTRL)),
    ('wnd', 0x45c1a0, sptr(CTRL, ('1', '3'))),
    ('wnd', 0x45d950, creator(CTRL, 'sControllerService')),
    ('wnd', 0x45db40, create(CAM)),
    ('wnd', 0x45da90, sptr(CAM, ('1', '3'))),
    ('wnd', 0x45dbc0, creator(CAM, 'sCamera')),
    ('wnd', 0x45c470, '??$for_eachChild@P6AXPAVInstance@RBX@@@Z@Instance@RBX@@QBEXP6AXPAV01@@Z@Z'),
]
ROWS = {}
for _b, _a, _s in ROWS_SPEC:
    assert '%08x' % _a not in elsewhere, (hex(_a), elsewhere['%08x' % _a])
    ROWS.setdefault(_b, []).append((_a, _s))

# Creator vtables (original): (class, row, vtable, RTTI)
CREATOR_VTABLES = [
    ('ControllerService', 0x45d950, 0x819d8c,
     '.?AVCreator@?$FactoryProduct@VControllerService@RBX@@VInstance@2@$1?sControllerService@2@3PADA@RBX@@'),
    ('Camera', 0x45dbc0, 0x819d94, '.?AVCreator@?$FactoryProduct@VCamera@RBX@@VInstance@2@$1?sCamera@2@3PADA@RBX@@'),
]
# create<C> rows: (class, row, constructor the body calls)
CREATES = [('Stats::StatsService', 0x458590, 0x458520), ('ControllerService', 0x45c580, 0x5cb9e0),
           ('Camera', 0x45db40, 0x5cd9a0)]

# Targets that are neither rows, imports, RTTI nor compiled exact helpers: symbol -> (address, proof)
KNOWN = {
    '?call_once@boost@@YAXP6AXXZAAJ@Z': (0x557330, 'boost.thread call_once (bound the same way by '
                                         'record_native_app_unit48c_2008.py / record_native_service_history.py)'),
    '?newIndex@ServiceProvider@RBX@@SAIXZ': (0x572690, 'ServiceProvider::newIndex (bound the same way by '
                                             'record_native_app_unit480_2008.py / record_native_app_unit424_2008.py)'),
    '?findServiceByClassName@ServiceProvider@RBX@@QBE?AV?$shared_ptr@VInstance@RBX@@@boost@@ABVName@2@@Z': (
        0x572a90, 'ServiceProvider::findServiceByClassName (bound the same way by record_native_service_history.py / '
        'record_native_content_provider_service.py)'),
    '?resize@?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@'
    'QAEXIV?$shared_ptr@VInstance@RBX@@@boost@@@Z': (
        0x4124c0, 'vector<shared_ptr<Instance> >::resize (bound the same way by record_native_filtered_selection.py / '
        'record_native_content_provider_service.py)'),
    '??1?$shared_ptr@VInstance@RBX@@@boost@@QAE@XZ': (0x600660, 'evidence name (ICF-shared destructor)'),
    '?setParent@Instance@RBX@@QAEXPAV12@@Z': (0x55a8f0, 'evidence name'),
    '?declare@Name@RBX@@SAABV12@PBDH@Z': (0x553f90, 'evidence name'),
    '??4shared_count@detail@boost@@QAEAAV012@ABV012@@Z': (0x4025b0, 'evidence name'),
    '??0ControllerService@RBX@@QAE@XZ': (0x5cb9e0, 'constructor (evidence name)'),
    '??0Camera@RBX@@QAE@XZ': (0x5cd9a0, 'constructor (evidence name)'),
    '?read@?$CopyOnWrite@V?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@'
    '@std@@@std@@@RBX@@QBE?AV?$shared_ptr@$$CBV?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@'
    'VInstance@RBX@@@boost@@@std@@@std@@@boost@@XZ': (0x4915b0, 'evidence name'),
    '??3@YAXPAX@Z': (0x6a067a, 'operator delete (MSVCR90 thunk; bound the same way by record_native_app_unit400_2008.py)'),
    '??RDeleter@?$Creatable@VInstance@RBX@@@RBX@@QAEXPAVInstance@2@@Z': (
        0x405e30, 'Creatable<Instance>::Deleter::operator() (bound the same way by record_native_app_unit400_2008.py)'),
}
# Rows counted by other receipts that counted rows call: symbol -> address (the receipt is looked up below)
COUNTED = {
    '??$doDeclare@$1?sStats@Stats@RBX@@3PADA@Name@RBX@@CAABV01@XZ': 0x455dc0,
    '??$callDoDeclare@$1?sStats@Stats@RBX@@3PADA@Name@RBX@@CAXXZ': 0x4563f0,
    '??0StatsService@Stats@RBX@@QAE@XZ': 0x458520,
    scount(STATS, ('2', '4')): 0x456410,
    '??$doDeclare@$1?sControllerService@RBX@@3PADA@Name@RBX@@CAABV01@XZ': 0x45b160,
    '??$callDoDeclare@$1?sControllerService@RBX@@3PADA@Name@RBX@@CAXXZ': 0x45b6d0,
    scount(CTRL, ('1', '4')): 0x45b790,
    scount(CAM, ('1', '4')): 0x45da00,
}
NAME_DATA = {'?sCamera@RBX@@3PADA': 'Camera'}
DATA_SECTIONS = [(original.image + s.VirtualAddress, original.image + s.VirtualAddress + s.Misc_VirtualSize)
                 for s in original.pe.sections if s.Name.rstrip(b'\0') in (b'.data', b'.rdata')]
TEXT = [(original.image + s.VirtualAddress, original.image + s.VirtualAddress + s.Misc_VirtualSize)
        for s in original.pe.sections if s.Name.rstrip(b'\0') == b'.text'][0]
BINDING = {}
UNBOUND = []
HELPERS = {}


def bind(symbol, value, where):
    prev = BINDING.setdefault(symbol, (value, where))
    assert prev[0] == value, ('one address per symbol', symbol, hex(prev[0]), prev[1], hex(value), where)


def verify(build, obj, rows):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    own = {s: a for _, a, s in ROWS_SPEC}
    out = []
    for address, name in rows:
        assert name in bodies, (build, hex(address), name, [n for n in bodies if name[:30] in n][:5])
        body, refs = bodies[name]
        target, target_refs, _ = match.target('2008-06', '%08x' % address)
        exact = match.exact_match(target, target_refs, body, refs)
        row = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target),
               'exact': bool(exact), 'build': build, 'verified_targets': {}, 'local_eh': []}
        out.append(row)
        if not exact:
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
            if hit is not None:
                assert hit[1] == nb.plain(symbol), (where, symbol, hex(value), hit)
                how = '%s!%s' % hit
            elif symbol in own:
                assert own[symbol] == value, (where, symbol, hex(value))
                how = 'own row'
            elif symbol.startswith('??_R0') and symbol.endswith('@8'):
                rtti = original.string(value + 8)
                assert norm(rtti) == norm('.' + symbol[5:-2]), (where, symbol, hex(value), rtti)
                how = 'RTTI %s' % rtti
            elif symbol.startswith('??_7'):
                rtti, at = original.vtable_class(value)
                cls = symbol[4:symbol.index('@@6B') + 2]
                assert norm(rtti) == norm('.?AV' + cls), (where, symbol, hex(value), rtti)
                how = 'vtable RTTI %s offset %#x' % (rtti, at)
            elif symbol in COUNTED:
                assert COUNTED[symbol] == value, (where, symbol, hex(value), hex(COUNTED[symbol]))
                receipts = sorted(set(elsewhere.get('%08x' % value, [])))
                assert receipts, ('not counted elsewhere', symbol, hex(value))
                if symbol in bodies:
                    hb, hr = bodies[symbol]
                    ht, htr, _ = match.target('2008-06', '%08x' % value)
                    assert match.exact_match(ht, htr, hb, hr), ('counted-elsewhere body not exact', symbol, hex(value))
                    how = 'row counted by %s (compiled body exact at the bound address)' % ', '.join(receipts)
                else:
                    how = 'row counted by %s' % ', '.join(receipts)
            elif symbol in NAME_DATA:
                assert original.string(value) == NAME_DATA[symbol], (where, symbol, hex(value))
                how = 'class-name array %r (string at the pushed address)' % NAME_DATA[symbol]
            elif symbol in bodies and match.exact_match(*match.target('2008-06', '%08x' % value)[:2], *bodies[symbol]):
                # helper / COMDAT body compiled here but not a row: exact at the bound address, never counted here
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


groups = {k: verify(k, OBJ[k], v) for k, v in ROWS.items()}
not_exact = [r for rows in groups.values() for r in rows if not r['exact']]
if DISCOVER:
    for u in UNBOUND:
        print('UNBOUND', u)
    for r in not_exact:
        print('NOT EXACT', r['address'], r['size'], r['target_size'], r['symbol'][:100])
assert not UNBOUND or DISCOVER, UNBOUND
assert not not_exact or DISCOVER, [(r['address'], r['symbol'][:80]) for r in not_exact]
for symbol, (address, _) in KNOWN.items():
    assert address in FUNCTIONS or original.imported(address) is not None, (symbol, hex(address))

# ---- Creator vtables (original): slot 0 is the Creator::create row; the RTTI names the class -----------------------
creator_vtables = []
for c, cr, vt, rtti in CREATOR_VTABLES:
    got = original.vtable_class(vt)
    assert got == (rtti, 0), (c, hex(vt), got)
    assert d(vt) == cr, (c, hex(vt), hex(d(vt)), hex(cr))
    slots = 0
    while TEXT[0] <= d(vt + 4 * slots) < TEXT[1]:
        slots += 1
    assert slots == 1, (c, hex(vt), slots)
    creator_vtables.append({'vtable': hex(vt), 'rtti': rtti, 'original_slots': slots,
                            'slot0': '%#x (Creator::create row)' % cr})


# ---- sizeof(C): the malloc size each create<C> passes ----------------------------------------------------------
def malloc_size(address):
    body, _, _ = match.target('2008-06', '%08x' % address)
    sizes = [struct.unpack_from('<I', body, k.start() + 1)[0] for k in re.finditer(rb'\x68', body)]
    return [s for s in sizes if 0x40 <= s < 0x4000]


SIZES = {}
for c, cc, ctor in CREATES:
    got = malloc_size(cc)
    assert len(got) == 1, (c, hex(cc), [hex(x) for x in got])
    assert ('%08x' % ctor) in FUNCTIONS[cc]['call_targets'], (c, hex(cc))
    SIZES[c] = 'sizeof %#x (malloc in create<%s> %#x, then the constructor %#x; exact here against the native header)' % (
        got[0], c, cc, ctor)


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
    ('rbx CRobloxDoc unit tail (message handlers; maintainer exclusion)', LO, 0x455d40,
     [('string', 0x4545d0, 'Script heap %s (%d blocks), %d threads'), ('string', 0x454c90, 'LDraw'),
      ('string', 0x454ac0, 'Doc script')],
     [('vt', 0x455060, '.?AVCRobloxDoc@@'), ('vt', 0x455d20, '.?AVCRobloxDoc@@')]),
    ('rbx CRobloxReportView unit (StatsService ServiceProvider / Creatable instances)', 0x455d40, 0x458e70,
     [('string', 0x456c30, 'Cannot open benchmark file '), ('string', 0x456820, 'Render')],
     [('vt', 0x455d40, '.?AVCRobloxReportDocView@@'), ('vt', 0x455d50, '.?AVCRobloxReportView@@'),
      ('vt', 0x456570, '.?AVCNameItem@CStatsItemRecord@CRobloxReportView@@'),
      ('vt', 0x457030, '.?AVStatsService@Stats@RBX@@'),
      ('vt', 0x457650, '.?AVEventData@?$MarshaledListener@VInstance@RBX@@UChildAdded@'),
      ('vt', 0x4589c0, '.?AVCRobloxReportView@@'), ('vt', 0x458a90, '.?AVCRobloxReportPaneView@@')]),
    ('rbx CRobloxView unit (verbs, VerbBinder; maintainer exclusion)', 0x458e70, 0x45afd0,
     [('string', 0x458ec0, 'ToggleToolbox'), ('string', 0x459570, '/Game/Help.aspx'),
      ('string', 0x45a4a0, 'ToggleFullScreen')],
     [('vt', 0x458e70, '.?AVCRobloxView@@'), ('vt', 0x458f50, '.?AVInsertModelFromRobloxVerb@@'),
      ('vt', 0x459040, '.?AVToggleIDEModeVerb@@'), ('vt', 0x459150, '.?AVHelpCommand@@'),
      ('vt', 0x459b40, '.?AV?$VerbBinder@VCRobloxView@@VCView@@@@'), ('vt', 0x45ac30, '.?AVCRobloxView@@')]),
    ('rbx CRobloxWnd unit (RenderStatsItem; Camera / ControllerService templates)', 0x45afd0, 0x45fe20,
     [('string', 0x45b240, 'Camera'), ('string', 0x45ba90, 'renderDevice->init failed'),
      ('string', 0x45f340, '2D CPU Render'), ('string', 0x45e3f0, '\\Roblox.jpg')],
     [('vt', 0x45afd0, '.?AVCRobloxWnd@@'), ('vt', 0x45b4a0, '.?AVCRobloxWnd@@'),
      ('vt', 0x45d950, '.?AVCreator@?$FactoryProduct@VControllerService@RBX@@'),
      ('vt', 0x45dbc0, '.?AVCreator@?$FactoryProduct@VCamera@RBX@@'), ('vt', 0x45df10, '.?AVCRobloxWnd@@'),
      ('vt', 0x45fe10, '.?AVCRobloxWnd@@')]),
    ('rbx save-to-Roblox dialog unit (CPublishAsPlaceDialog / CUploadPlaceDialog / CSaveModelToRobloxDialog)',
     0x45fe20, 0x45ffd0,
     [('string', 0x45ff20, 'DialogResult')],
     [('vt', 0x45fe40, '.?AVCPublishAsPlaceDialog@@'), ('vt', 0x45fe70, '.?AVCUploadPlaceDialog@@'),
      ('vt', 0x45fef0, '.?AVCSaveToRobloxDialog@@')]),
    ('library Scintilla MFC wrapper CScintillaCtrl (scintilla-mfc 1.20; continues past the range)', 0x45ffd0, HI,
     [], [('vt', 0x45ffd0, '.?AVCScintillaCtrl@Scintilla@@')]),
]
range_rows = sorted(a for a in FUNCTIONS if LO <= a < HI)   # every row kind (code, gen, adjustor, eh), as app-unit400
for a in range_rows:
    assert sum(lo <= a < hi for _, lo, hi, _, _ in BLOCKS) == 1, hex(a)
for name, lo, hi, strings, vts in BLOCKS:
    for _, a, text in strings:
        assert lo <= a < hi and holds_string(a, text), (name, hex(a), text)
    for _, a, prefix in vts:
        assert lo <= a < hi and in_vtable(a, prefix), (name, hex(a), prefix)
# the CRobloxDoc handlers are entries of its message map 00817f0c; the Camera doDeclare is called by static initializers
assert all(in_table(a, 0x817f0c, 200) for a in (0x454040, 0x454170, 0x454c90, 0x455460, 0x455c30))
assert set(FUNCTIONS[0x45b240]['callers']) == {'007ef9f0', '007faf40'}, FUNCTIONS[0x45b240]['callers']
# setDataModel of the report view 00458700 and the CRobloxWnd 0045f7b0 reach the service rows
assert '00458610' in FUNCTIONS[0x458700]['call_targets'] and '0045de20' in FUNCTIONS[0x45f7b0]['call_targets']

exact_rows = sorted({r['address'] for rows in groups.values() for r in rows if r['exact']})
double = {a: elsewhere[a] for a in exact_rows if a in elsewhere}
assert not double, double
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if LO <= int(a, 16) < HI}
open_rows = ['%08x' % a for a in range_rows if '%08x' % a not in exact_rows and '%08x' % a not in range_counted]


def block_of(a):
    for name, lo, hi, _, _ in BLOCKS:
        if lo <= a < hi:
            return name.split(' (')[0]


OPEN_BY_BLOCK = {}
for a in open_rows:
    OPEN_BY_BLOCK.setdefault(block_of(int(a, 16)), []).append('%#x' % int(a, 16))

UNIT_MAP = {
    'rbx CRobloxDoc unit tail ..0x455d3f': (
        'CRobloxDoc command / update-UI handlers 0x454040..0x455c30 (entries of the CRobloxDoc message map 0x817f0c: '
        '"Script heap %s (%d blocks), %d threads" 0x4545d0, "Doc script" 0x454ac0, "LDraw" 0x454c90), '
        'the CRobloxDoc vtable 0x817ce4 slots 0x455060 ("NoVisit") and 0x455d20 / 0x455d30. Maintainer exclusion '
        '(CRobloxDoc): not recovered.'),
    'rbx CRobloxReportView unit 0x455d40..0x458e6f': (
        'CRobloxReportView / CRobloxReportDocView / CRobloxReportPaneView (vtables 0x81888c / 0x818c94 / 0x818e7c; '
        'native CRobloxReportView.h / CRobloxReportSubViews.h and their receipts roblox-report-view / report-sub-views, '
        'other owners), CStatsItemRecord with CNameItem / CValueItem (0x8184a4 / 0x8185f4), the MarshaledListener<'
        'Instance, ChildAdded / ChildRemoved> listeners and EventData (0x81884c / 0x818858), dumpStats / benchmark '
        'output 0x456820 / 0x456c30, the Stats::StatsService COMDATs counted by stats-service (constructor 0x458520, '
        'Name::doDeclare<sStats> 0x455dc0 ...), and the ServiceProvider / Creatable instances for StatsService '
        'built and counted here: doGetClassIndex 0x455ea0, callDoGetClassIndex 0x456400, find 0x457b60, create '
        '0x458610 (called by setDataModel 0x458700, 0x45f7b0 and two later units), Creatable<Instance>::create '
        '0x458590 and shared_ptr(StatsService*, Deleter) 0x456f10, plus boost::shared_dynamic_cast<Stats::Item> 0x456ee0 '
        'and its dynamic_cast_tag constructor 0x456360 (callers: the ChildAdded / ChildRemoved handlers 0x4582f0 / '
        '0x4581a0 of this unit). Open here: the report-view owner rows '
        '(EventData::execute 0x457650 is compiled not exact in roblox-report-view), the deleting destructors 0x456fc0 / '
        '0x458150 and the CStatsItemRecord / item bodies not yet in that owner\'s receipt.'),
    'rbx CRobloxView unit 0x458e70..0x45afcf': (
        'CRobloxView (vtable 0x81933c) members, InsertModelFromRobloxVerb / ToggleIDEModeVerb / LockPlayModeVerb / '
        'ToggleFullscreenVerb / HelpCommand (vtables 0x819090..0x819140; ViewVerbs.cpp / InsertModelFromRobloxVerb.cpp, '
        'leased by codex-layout), VerbBinder<CRobloxView, CView> 0x819174, header inline copies (G3D Vector3 operator- '
        '0x45ac40, AtomicInt32::decrement 0x45ad80, ReferenceCountedObject_zeroWeakPointers 0x45ad90, GWindow::'
        'makeCurrent 0x45ad50, the TextureManager::TextureArgs vtable 0x819770 slot 0x45ae10, UserInputBase::'
        'ctrlKeyDown 0x45aec0, Camera::getCameraFocus 0x45aef0 / getCameraCoordinateFrame 0x45af00). Maintainer '
        'exclusion (CRobloxView): not recovered.'),
    'rbx CRobloxWnd unit 0x45afd0..0x45fe1f': (
        'CRobloxWnd (vtable 0x8199f4; declared in native CRobloxView.h, other owner): window creation / OnWndMsg / '
        'render-device init ("renderDevice->init failed" 0x45ba90, the driver blacklist 0x45cbf0, "OpenGL-G3D failed" '
        '0x45d280), doRender / draw 0x45e3f0..0x45e910, updateThrottle 0x45c890, setDataModel 0x45f7b0; the '
        'RenderStatsItem nested class (render-stats-item2008, pending there: constructor 0x45f340, update 0x45f570, '
        'create 0x45f730, shared_ptr 0x45c0f0, shared_count 0x45b700), G3D Table<TextureArgs, ...> COMDATs and '
        'Stats::Item / TypedStatsItem COMDATs (render-stats-item2008 / stats-service), the boost RegEx destructor '
        '0x45b620 and G3D Vector3::magnitude 0x45b310 / Rect2D::xyxy 0x45b950 header copies, and the instances built '
        'and counted here: Name::doDeclare<sCamera> 0x45b240 / callDoDeclare 0x45b6f0 (static initializers 0x7ef9f0 / '
        '0x7faf40), ServiceProvider doGetClassIndex / callDoGetClassIndex / find / create<ControllerService> 0x45b2b0 / '
        '0x45b820 / 0x45dce0 / 0x45de20, Creatable<Instance>::create / shared_ptr / Creator::create for '
        'ControllerService 0x45c580 / 0x45c1a0 / 0x45d950 and Camera 0x45db40 / 0x45da90 / 0x45dbc0, and '
        'Instance::for_eachChild<void (*)(Instance*)> 0x45c470 (also a support body in app-unit5a0). Not recovered: '
        'the CRobloxWnd members (CRobloxView.h owner) and the file-local recursive visitor 0x45c600 (no declaration).'),
    'rbx save-to-Roblox dialog unit 0x45fe20..0x45ffcf': (
        'CPublishAsPlaceDialog / CUploadPlaceDialog / CSaveModelToRobloxDialog shared vtable slots 0x45fe40 / 0x45fe70, '
        'CSaveToRobloxDialog 0x45fef0 (vtable 0x81a564), the dialog constructor 0x45fe80 called by the CRobloxDoc '
        'publish handlers, "DialogResult" 0x45ff20. Native CSaveToRobloxDialog.h / CUploadPlaceDialog.h belong to '
        'other owners: not recovered here.'),
    'library code': (
        'Scintilla MFC wrapper CScintillaCtrl 0x45ffd0.. (scintilla-mfc 1.20 ScintillaCtrl.cpp; vtable 0x81a754; '
        'continues into the app-unit460 range). G3D / boost / MFC header inline copies inside the units above are '
        'library header code and are not recovered.'),
    'excluded': (
        'CRobloxDoc (unit tail ..0x455d3f) and CRobloxView (0x458e70..0x45afcf) are maintainer exclusions; their '
        'rows are mapped only.'),
}
NOT_EXACT = {
    'find<StatsService> 0x457b60 / find<ControllerService> 0x45dce0 under the default boost header': (
        'not exact (404 vs 320 B): the native build inlines the shared_ptr<Instance> destructor that the original '
        'calls out of line at 0x600660; exact (and counted) only from the noinline-destructor build, while the '
        'create rows of the same units are exact only from the default build (the original inlines it there).'),
}
REJECTED = {
    'compile the whole unit with native-headers/boost-noinline-shared-destructor first': (
        'create<StatsService> 0x458610 / create<ControllerService> 0x45de20 drop to 187 vs 228 B and the Creator::create '
        'rows 0x45d950 / 0x45dbc0 to 132 vs 175 B (the original inlines ~shared_ptr there); the profile is used only '
        'for the find rows.'),
    'UserInputBase::ctrlKeyDown 0x45aec0 as a definition in this unit': (
        'not attempted: util/UserInputBase.h (core owner) declares it out of line, while its placement here between '
        'CRobloxView COMDATs (and the user-controller note) indicates an inline header member; left to the header '
        'owner (proposal).'),
}
PROPOSALS = {
    'util/UserInputBase.h (owner), FYI': (
        'ctrlKeyDown 0x45aec0 (48 B: keyDown(SDLK_RCTRL 0x131) || keyDown(SDLK_LCTRL 0x132) through vtable slot 5) is '
        'an out-of-line copy emitted in the CRobloxView unit, the pattern of an inline header member (as the '
        'user-controller receipt proposes for altKeyDown). Declaring it inline would let the first using unit emit it.'),
    'util/Object.h / v8tree/Service.h (core owners), informational, no edit needed': (
        'this unit repeats the FactoryProduct::className / Creator::create, NonFactoryProduct::className and '
        'ServiceProvider doGetClassIndex / getClassIndex / find / create template definitions of '
        'AppUnit48C_2008Services.cpp and AppUnit400_2008Creators.cpp.'),
}

paths = [Path(__file__).resolve()] + list(SOURCES.values()) + HEADERS
receipt = {
    'class': 'RBX Name / ServiceProvider / Creatable / FactoryProduct template instances of the application range '
             '00454000..00460000 (2008-06), inactive',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM), document-swap flags, /fp:fast',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): nb.sha(p) for p in paths},
    'objects': {k: nb.sha(v) for k, v in OBJ.items()},
    'layout': SIZES,
    'unit_map': UNIT_MAP,
    'unit_blocks': ['%#x..%#x %s' % (lo, hi, n) for n, lo, hi, _, _ in BLOCKS],
    'range_functions': len(range_rows),
    # 'ADDR counted by RECEIPT' text, never a quoted bare address (local_backpack / viewnew_brick_build /
    # viewnew_part_mesh treat any quoted bare address in another receipt as counted there).
    'range_rows_counted_by_other_receipts': ['%s counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()],
    'range_rows_open': ['%#x (open)' % int(a, 16) for a in open_rows],
    'range_rows_open_by_block': OPEN_BY_BLOCK,
    'rows': groups,
    'creator_vtables': creator_vtables,
    'helper_bodies_not_counted': HELPERS,
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
    print('DISCOVER: receipt not written; %d exact rows' % len(exact_rows), ' '.join(exact_rows))
    sys.exit(0)
RECEIPT.write_text(text)
print('PASS app-unit454-2008: %d counted exact rows (%s); %d range rows, %d counted elsewhere, %d open; %d Creator '
      'vtables checked' % (len(exact_rows), ' '.join(exact_rows), len(range_rows), len(range_counted), len(open_rows),
                           len(creator_vtables)))
