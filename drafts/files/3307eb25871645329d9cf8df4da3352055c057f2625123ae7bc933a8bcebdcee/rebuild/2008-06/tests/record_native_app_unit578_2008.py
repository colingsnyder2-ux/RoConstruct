"""Verify the inactive 2008-06 native rows of the application range 00578000..0057c000 and record its unit map.

Unit map (boundary evidence in the receipt's `unit_map` / `unit_blocks`, checked below; rows counted by other receipts
are listed as 'ADDR counted by RECEIPT' text, never as a quoted bare address):
  * the whole range lies inside v8datamodel/DataModel.cpp (00574f10..0057c1af; app-unit570 / app-unit57c maps):
    the Creatable / FactoryProduct COMDATs of LocalBackpackItem, LocalBackpack and Tool, ServiceProvider::find /
    create<LocalBackpack>, the DataModel reflection descriptors (SignalDesc / BoundFuncDesc<DataModel, ...>), the
    DataModel members, adjustor thunks, constructor and destructor, and the rbx_httpGet / rbx_httpPost helpers.
  No separately compiled library unit starts in the range; the boost / STL rows are header instances.

Build (VS2008 RTM 21022, document-swap flags, /fp:fast), current native headers only (read-only):
  * native-classes/AppUnit578_2008Creators.cpp  Creator::create, create<C> and shared_ptr<C>(C*, Deleter) instances of
    LocalBackpackItem / LocalBackpack / Tool and ServiceProvider::find / create<LocalBackpack>.
No new header is created (nothing shadowed). DataModel's own rows need declarations the core v8datamodel/DataModel.h
does not have (proposals in the receipt); they are mapped, not built.

Every relocation of a counted row is resolved to the address the original instruction uses and verified, one address
per symbol over all rows: imports by DLL export name, type descriptors and vtables by original RTTI, own rows by their
row address, rows counted by other receipts by that receipt (and the compiled body must be exact there), constructors
by evidence name, the open find<LocalBackpack> row by identity, other compiled helper bodies by an exact body at the
bound address (never counted). Every Creator::create row is slot 0 of the original one-slot Creator vtable whose RTTI
names the class; sizeof(C) is checked by the malloc size each create<C> passes. A row is counted only when no other
receipt counts it. Writes work/2008-06/shared-layouts/app-unit578-2008-working.json. NATIVE_APP_UNIT578_DISCOVER=1
lists unbound targets and non-exact rows instead of asserting.
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
OUT = R / 'out/app-unit578-2008'
OUT.mkdir(parents=True, exist_ok=True)
SOURCES = {'creators': R / 'native-classes/AppUnit578_2008Creators.cpp'}
HEADERS = [R / 'native-headers' / h for h in (
    'util/Object.h', 'util/Name.h', 'v8tree/Service.h', 'LocalBackpack2008/LocalBackpack2008.h', 'v8datamodel/Tool.h',
    'v8datamodel/Hopper.h', 'v8datamodel/DataModel.h')]
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit578-2008-working.json'
LO, HI = 0x578000, 0x57c000
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT578_DISCOVER'))


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags() + ['/fp:fast'] + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log[-4000:]
    return obj, flags


OBJ, FLAGS = {}, {}
for _k, _src in SOURCES.items():
    OBJ[_k], FLAGS[_k] = build('AppUnit578_2008' + _k, _src)

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
# Class -> (mangled class, Creator::create, shared_ptr ctor, create<C>, shared_count, constructor, ctor symbol,
#           Creator vtable, original Creator RTTI). Rows outside the range are compiled helper bodies (never counted).
CREATORS = {
    'LocalBackpackItem': ('VLocalBackpackItem@RBX@@', 0x578160, 0x578030, 0x5780e0, 0x577fa0, 0x5fccd0,
                          '??0LocalBackpackItem@RBX@@QAE@XZ', 0x82fffc,
                          '.?AVCreator@?$FactoryProduct@VLocalBackpackItem@RBX@@VWidget@2@$1?sLocalBackpackItem@2@'
                          '3QBDB@RBX@@'),
    'LocalBackpack': ('VLocalBackpack@RBX@@', 0x578210, None, 0x5771b0, None, 0x5fceb0,
                      '??0LocalBackpack@RBX@@QAE@XZ', 0x830018,
                      '.?AVCreator@?$FactoryProduct@VLocalBackpack@RBX@@VRelativePanel@2@$1?sLocalBackpack@2@3QBDB@'
                      'RBX@@'),
    'Tool': ('VTool@RBX@@', 0x578480, 0x578350, 0x578400, 0x5782c0, 0x600240, '??0Tool@RBX@@QAE@XZ', 0x830020,
             '.?AVCreator@?$FactoryProduct@VTool@RBX@@VBackpackItem@2@$1?sTool@2@3QBDB@RBX@@'),
}
SP = '@ServiceProvider@RBX@@'
FIND_ROW = (0x578530, '??$find@VLocalBackpack@RBX@@@ServiceProvider@RBX@@QBEPAVLocalBackpack@1@XZ')
CREATE_ROW = (0x578930, '??$create@VLocalBackpack@RBX@@@ServiceProvider@RBX@@QBEPAVLocalBackpack@1@XZ')
# find<LocalBackpack> identity: call_once push of callDoGetClassIndex<LocalBackpack>, call to doGetClassIndex and to
# the Name::doDeclare instance declaring "LocalBackpack" (counted by local-backpack).
FIND_EVIDENCE = (0x576800, 0x575630, 0x575550, 'LocalBackpack')


def find(obj, test, what):
    hits = [n for n, _, _ in match.coff_functions(Path(obj).read_bytes()) if not nb.LOCAL_EH.match(n) and test(n)]
    assert len(hits) == 1, (what, hits)
    return hits[0]


ROWS = {'creators': []}
COUNTED_TARGETS = {}   # symbol -> (address, receipts)
EXTERNAL = {}
CTOR = {}
OUTSIDE = {}           # helper rows outside the range: symbol -> address (compiled exact there, not counted)
for c, (mangled, cr, sp, cc, sc, ctor, ctor_sym, vt, rtti) in CREATORS.items():
    obj = OBJ['creators']
    syms = {
        'cr': find(obj, lambda n: n.startswith('?create@Creator@?$FactoryProduct@' + mangled) and n.endswith(
            'UBE?AV?$shared_ptr@VObject@RBX@@@boost@@XZ'), (c, 'Creator::create')),
        'cc': find(obj, lambda n: n.startswith('??$create@' + mangled + '@' + CI), (c, 'create')),
    }
    if sp is not None:
        syms['sp'] = find(obj, lambda n: n.startswith('??$?0' + mangled) and '?$shared_ptr@' + mangled in n
                          and 'QAE@PAV' in n, (c, 'shared_ptr'))
    if sc is not None:
        syms['sc'] = find(obj, lambda n: n.startswith('??$?0PA' + mangled) and '@shared_count@detail@boost@@QAE@' in n,
                          (c, 'shared_count'))
    for key, address in (('cr', cr), ('sp', sp), ('cc', cc), ('sc', sc)):
        if address is None:
            continue
        where = elsewhere.get('%08x' % address)
        if where:
            COUNTED_TARGETS[syms[key]] = (address, sorted(set(where)))
        elif LO <= address < HI:
            ROWS['creators'].append((address, syms[key]))
        else:
            OUTSIDE[syms[key]] = address
    CTOR[ctor_sym] = ctor
    EXTERNAL[ctor_sym] = ctor
ROWS['creators'].append(CREATE_ROW)

EXTERNAL['?call_once@boost@@YAXP6AXXZAAJ@Z'] = 0x557330   # boost.thread call_once (thread library)
EXTERNAL['??RDeleter@?$Creatable@VInstance@RBX@@@RBX@@QAEXPAVInstance@2@@Z'] = 0x405e30
DATA_SECTIONS = [(original.image + s.VirtualAddress, original.image + s.VirtualAddress + s.Misc_VirtualSize)
                 for s in original.pe.sections if s.Name.rstrip(b'\0') in (b'.data', b'.rdata')]
TEXT = [(original.image + s.VirtualAddress, original.image + s.VirtualAddress + s.Misc_VirtualSize)
        for s in original.pe.sections if s.Name.rstrip(b'\0') == b'.text'][0]
BINDING = {}
UNBOUND = []
HELPERS = {}
IDENTITY = {}


def bind(symbol, value, where):
    prev = BINDING.setdefault(symbol, (value, where))
    assert prev[0] == value, ('one address per symbol', symbol, hex(prev[0]), prev[1], hex(value), where)


def prove_find(value):
    call, do, decl, text = FIND_EVIDENCE
    body, _, _ = match.target('2008-06', '%08x' % value)
    assert b'\x68' + struct.pack('<I', call) in body, (hex(value), hex(call))
    x = FUNCTIONS[value]
    assert '%08x' % do in x['call_targets'] and '%08x' % decl in x['call_targets'], (hex(value), x['call_targets'])
    assert FUNCTIONS[decl]['strings'] == [text], (hex(decl), FUNCTIONS[decl]['strings'])
    return ('open row of this range (not counted), identified by its call_once push of callDoGetClassIndex %#x, its '
            'call to doGetClassIndex %#x and to the doDeclare %#x of %r' % (call, do, decl, text))


def verify(build, obj, rows, record=True):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    own = {s: a for a, s in rows}
    out = []
    for address, name in rows:
        assert name in bodies, (build, hex(address), name)
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
            elif symbol == FIND_ROW[1]:
                assert value == FIND_ROW[0], (where, symbol, hex(value))
                how = IDENTITY.setdefault(symbol, prove_find(value))
            elif symbol.startswith('??_R0') and symbol.endswith('@8'):
                rtti = original.string(value + 8)
                assert norm(rtti) == norm('.' + symbol[5:-2]), (where, symbol, hex(value), rtti)
                how = 'RTTI %s' % rtti
            elif symbol.startswith('??_7'):
                rtti, at = original.vtable_class(value)
                cls = symbol[4:symbol.index('@@6B') + 2]
                assert norm(rtti) == norm('.?AV' + cls), (where, symbol, hex(value), rtti)
                how = 'vtable RTTI %s offset %#x' % (rtti, at)
            elif symbol in COUNTED_TARGETS or ('%08x' % value in elsewhere and symbol in bodies):
                other, receipts = COUNTED_TARGETS.get(symbol, (value, sorted(set(elsewhere.get('%08x' % value, [])))))
                assert other == value, (where, symbol, hex(value), hex(other))
                hb, hr = bodies[symbol]
                ht, htr, _ = match.target('2008-06', '%08x' % value)
                assert match.exact_match(ht, htr, hb, hr), ('counted-elsewhere body not exact', symbol, hex(value))
                how = 'row counted by %s (compiled body exact at the bound address)' % ', '.join(receipts)
            elif symbol in EXTERNAL:
                assert EXTERNAL[symbol] == value, (where, symbol, hex(value), hex(EXTERNAL[symbol]))
                if symbol in CTOR:
                    assert names.get(value, '') == symbol, (where, symbol, hex(value), names.get(value))
                    how = 'constructor (evidence name)'
                else:
                    how = 'external' + (' (evidence name)' if names.get(value, '') == symbol else '')
            elif symbol in bodies:
                # helper / COMDAT body compiled here but not a row: exact at the bound address, never counted
                if symbol in OUTSIDE:
                    assert OUTSIDE[symbol] == value, (where, symbol, hex(value))
                hb, hr = bodies[symbol]
                ht, htr, _ = match.target('2008-06', '%08x' % value)
                assert match.exact_match(ht, htr, hb, hr) or DISCOVER, (where, symbol, hex(value))
                HELPERS.setdefault(symbol, '%#x' % value)
                how = 'helper body exact at the bound address (not counted)'
            elif symbol in definitions and symbol not in bodies:
                assert any(lo <= value < hi for lo, hi in DATA_SECTIONS), (where, symbol, hex(value))
                how = 'own static (bound by consistency)'
            elif names.get(value, '') == symbol:
                how = 'external (evidence name)'
            if how is None:
                UNBOUND.append((where, symbol, hex(value), names.get(value, '')[:80]))
                continue
            if record:
                bind(symbol, value, where)
            row['verified_targets'][symbol] = '%#x (%s)' % (value, how)
    return out


groups = {k: verify(k, OBJ[k], ROWS[k]) for k in SOURCES}
find_rows = verify('creators', OBJ['creators'], [FIND_ROW], record=False)
not_exact = [r for rows in groups.values() for r in rows if not r['exact']]
if DISCOVER:
    for u in UNBOUND:
        print('UNBOUND', u)
    for r in not_exact + find_rows:
        print('ROW', r['address'], r['exact'], r['size'], r['target_size'], r['symbol'][:100])
assert not UNBOUND or DISCOVER, UNBOUND
assert not not_exact or DISCOVER, [(r['address'], r['symbol'][:80]) for r in not_exact]
assert not any(r['exact'] for r in find_rows), 'find<LocalBackpack>() const became exact: count it'
for symbol, address in EXTERNAL.items():
    assert address in FUNCTIONS or original.imported(address) is not None, (symbol, hex(address))

# ---- Creator vtables (original): slot 0 is the Creator::create row; the RTTI names the class -----------------------
creator_vtables = []
for c, (mangled, cr, sp, cc, sc, ctor, ctor_sym, vt, rtti) in CREATORS.items():
    got = original.vtable_class(vt)
    assert got == (rtti, 0), (c, hex(vt), got)
    assert d(vt) == cr, (c, hex(vt), hex(d(vt)), hex(cr))
    slots = 0
    while TEXT[0] <= d(vt + 4 * slots) < TEXT[1]:
        slots += 1
    assert slots == 1, (c, hex(vt), slots)
    creator_vtables.append({'vtable': hex(vt), 'rtti': rtti, 'original_slots': slots,
                            'slot0': '%#x (Creator::create row)' % cr})


# ---- sizeof(C): the malloc size each create<C> passes, against the native header --------------------------------
def malloc_size(address):
    body, _, _ = match.target('2008-06', '%08x' % address)
    sizes = [struct.unpack_from('<I', body, k.start() + 1)[0] for k in re.finditer(rb'\x68', body)]
    return [s for s in sizes if 0x40 <= s < 0x4000]


SIZES = {}
for c, (mangled, cr, sp, cc, sc, ctor, ctor_sym, vt, rtti) in CREATORS.items():
    got = malloc_size(cc)
    assert len(got) == 1, (c, hex(cc), [hex(x) for x in got])
    state = ('exact here against the native header layout' if LO <= cc < HI else
             'compiled helper body exact at that address (outside the range, not counted)')
    if '%08x' % cc in elsewhere:
        state = 'compiled exact there, row counted by %s' % ', '.join(sorted(set(elsewhere['%08x' % cc])))
    SIZES[c] = 'sizeof %#x (malloc in create<%s> %#x; %s)' % (got[0], c, cc, state)


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
        for back in range(0, 120):
            try:
                rtti, _ = original.vtable_class(ref - 4 * back)
            except Exception:
                continue
            if rtti and rtti.startswith(rtti_prefix):
                return True
            if rtti:
                break
    return False


BLOCKS = [
    ('rbx v8datamodel/DataModel.cpp (begins at 0x574f10, ends at 0x57c1af)', LO, HI,
     [('string', 0x5788c0, 'DataModel'), ('string', 0x579db0, 'DataModel Loading %s'),
      ('string', 0x57a1b0, '[[[progress]]]'), ('string', 0x57b9f0, 'Level'), ('string', 0x57bc00, 'rbx_httpGet'),
      ('string', 0x57be10, 'rbx_httpPost')],
     [('vt', 0x578160, '.?AVCreator@?$FactoryProduct@VLocalBackpackItem@RBX@@'),
      ('vt', 0x578480, '.?AVCreator@?$FactoryProduct@VTool@RBX@@'),
      ('vt', 0x578b80, '.?AV?$SignalDesc@VDataModel@RBX@@'),
      ('vt', 0x579270, '.?AV?$BoundFuncDesc@VDataModel@RBX@@'),
      ('vt', 0x57a850, '.?AV?$NonFactoryProduct@VServiceProvider@RBX@@$1?sDataModel@'),
      ('vt', 0x57b020, '.?AVDataModel@RBX@@'),
      ('vt', 0x57b160, '.?AVDataModel@RBX@@')]),
]
range_rows = sorted(a for a in FUNCTIONS if LO <= a < HI)
for a in range_rows:
    assert sum(lo <= a < hi for _, lo, hi, _, _ in BLOCKS) == 1, hex(a)
for name, lo, hi, strings, vts in BLOCKS:
    for _, a, text in strings:
        assert lo <= a < hi and holds_string(a, text), (name, hex(a), text)
    for _, a, prefix in vts:
        assert lo <= a < hi and in_vtable(a, prefix), (name, hex(a), prefix)
# DataModel() / ~DataModel / initializeContents identities used by the map
assert names.get(0x57b9f0) == '??0DataModel@RBX@@QAE@XZ'
assert '0057bbe0' in FUNCTIONS[0x57ad70]['callers'] and '0057c100' in FUNCTIONS[0x57a9f0]['callers']
assert FUNCTIONS[0x578930]['callers'] == ['0057a9f0'] and FUNCTIONS[0x578530]['callers'] == ['00578930']
# the DataModel adjustor thunks 0x57b0a0..0x57b160 all jump to the deleting destructor 0x57bbe0
for a in range(0x57b0a0, 0x57b170, 0x10):
    b = original.data(a, FUNCTIONS[a]['size'])
    assert b[-5] == 0xe9 and a + len(b) + struct.unpack_from('<i', b, len(b) - 4)[0] == 0x57bbe0, hex(a)

exact_rows = sorted({r['address'] for rows in groups.values() for r in rows if r['exact']})
double = {a: elsewhere[a] for a in exact_rows if a in elsewhere}
assert not double, double
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if LO <= int(a, 16) < HI}
open_rows = ['%08x' % a for a in range_rows if '%08x' % a not in exact_rows and '%08x' % a not in range_counted]

# Open rows by sub-block (evidence: evidence names, vtable slots, strings, callers; see unit_map)
CATEGORY_SPANS = [
    ((0x578530, 0x578531), 'ServiceProvider::find<LocalBackpack>() const (built, 404 vs 320 B: inlined '
                           '~shared_ptr<Instance>, the known find<C> blocker)'),
    ((0x578670, 0x578671), 'SignalDesc<DataModel, void()> helper (vector<any> argument pack; caller 0x578b80)'),
    ((0x578b80, 0x578b81), 'SignalDesc<DataModel, void()> slot 4 (vtable 0x8300a4)'),
    ((0x578790, 0x578791), 'SignalDesc<Instance, void(shared_ptr<Instance>, const PropertyDescriptor*)> constructor '
                           '(static initializer 0x7f3440)'),
    ((0x5788c0, 0x5788c1), 'Described<DataModel>::classDescriptor() ("DataModel"; ClassDescriptor(base, name) '
                           '0x5708f0)'),
    ((0x578a20, 0x578ad1), 'boost::function / bind storage helpers of rbx_httpGet / rbx_httpPost'),
    ((0x578c20, 0x578e51), 'DataModel RunService-transition path (caller chain from 0x554880)'),
    ((0x578ef0, 0x578ef1), 'DataModel::clearContents (removeAllChildren; callers 0x455580, 0x57b800)'),
    ((0x578fa0, 0x579a91), 'BoundFuncDesc<DataModel, ...> descriptor constructors (static initializers '
                           '0x7f3470..0x7f3670) and their call / execute slots ("bad cast")'),
    ((0x579b70, 0x579b71), 'boost functor_manager of bind_t<void(*)(const function0&, MessageType, bool)> '
                           '(boost header instance with RBX::MessageType)'),
    ((0x57a9b0, 0x57a9b1), 'boost function manage entry for the same bind_t (vtable 0x8302d4 slot 6)'),
    ((0x579c10, 0x57a1b1), 'DataModel members bound by the reflection descriptors (load "DataModel Loading %s", '
                           'stats text "[[[progress]]]", callers 0x45bc80 / 0x45e3f0)'),
    ((0x57a6c0, 0x57a6c1), 'DataModel member (callers 0x45bc80 / 0x45e3f0)'),
    ((0x57a7b0, 0x57a7b1), 'DescribedNonCreatable<DataModel, ServiceProvider, sDataModel> constructor (vtables '
                           '0x8301bc..0x83010c)'),
    ((0x57a830, 0x57a841), 'ICF-shared ServiceProvider / GlobalSettings ??_E adjustor thunks (jmp 0x568d40)'),
    ((0x57aca0, 0x57aca1), 'ICF-shared ServiceProvider / GlobalSettings ??_E adjustor thunk (jmp 0x568d40)'),
    ((0x57a850, 0x57a851), 'NonFactoryProduct<ServiceProvider, sDataModel>::getClassName'),
    ((0x57a870, 0x57a901), 'boost::function assignment helpers of the Instance signal connection (0x57acb0 chain)'),
    ((0x57acb0, 0x57acb1), 'Instance signal connection helper (caller 0x57b680)'),
    ((0x57b680, 0x57b681), 'SignalDesc<Instance, void(shared_ptr<Instance>, const PropertyDescriptor*)> slot 1'),
    ((0x57a9f0, 0x57a9f1), 'DataModel::initializeContents (datamodel-initialize-trial, not counted)'),
    ((0x57abf0, 0x57abf1), 'DataModel base-construction helper (classDescriptor 0x5788c0, 0x57a7b0; caller 0x57b9f0)'),
    ((0x57ad70, 0x57ad71), '~DataModel (called by the deleting destructor 0x57bbe0)'),
    ((0x57b020, 0x57b031), 'DataModel::setDirty / isDirty (IDataState slots 0/1; header inlines)'),
    ((0x57b040, 0x57b071), 'DataModel::onDescendentAdded / onDescendentRemoving (vtable 0x8303cc slots 5/6)'),
    ((0x57b0a0, 0x57b161), 'DataModel ??_E adjustor thunks (jmp 0x57bbe0)'),
    ((0x57b170, 0x57b631), 'DataModel::onChildChanged 0x57b630 and its property-changed raise chain'),
    ((0x57b760, 0x57b761), 'boost::function assign helper of rbx_httpGet / rbx_httpPost'),
    ((0x57b800, 0x57b801), 'DataModel close / stop path (RunStateOwner inlines 0x554330 / 0x554460; caller 0x46b0e0)'),
    ((0x57b9f0, 0x57b9f1), 'DataModel() (evidence name)'),
    ((0x57bbe0, 0x57bbe1), 'DataModel deleting destructor'),
    ((0x57bc00, 0x57be11), 'rbx_httpGet / rbx_httpPost'),
]
OPEN_CATEGORIES = {}
for a in open_rows:
    v = int(a, 16)
    cat = [n for (lo, hi), n in CATEGORY_SPANS if lo <= v < hi]
    assert len(cat) == 1, (a, cat)
    OPEN_CATEGORIES.setdefault(cat[0], []).append('%#x' % v)

UNIT_MAP = {
    'rbx v8datamodel/DataModel.cpp 0x578000..0x57c000 (unit 0x574f10..0x57c1af)': (
        'The whole range continues the DataModel unit that app-unit570 maps from 0x574f10 and app-unit57c ends at '
        '0x57c1af (Creatable<Instance>::create<DataModel> 0x57c080, createDataModel 0x57c100). Link order: the '
        'Creatable / FactoryProduct COMDATs of LocalBackpackItem (shared_ptr 0x578030, create 0x5780e0, Creator 0x578160 '
        '= slot 0 of 0x82fffc), LocalBackpack (Creator 0x578210 = slot 0 of 0x830018) and Tool (shared_count 0x5782c0, '
        'shared_ptr 0x578350, create 0x578400, Creator 0x578480 = slot 0 of 0x830020); ServiceProvider::find / '
        'create<LocalBackpack> 0x578530 / 0x578930 (caller initializeContents 0x57a9f0); the DataModel reflection '
        'descriptors (SignalDesc<DataModel> vtable 0x8300a4, BoundFuncDesc<DataModel, ...> vtables 0x83005c..0x830098, '
        'static initializers 0x7f3440..0x7f3670, classDescriptor 0x5788c0 "DataModel"); DataModel members '
        '(clearContents 0x578ef0, load "DataModel Loading %s" 0x579db0, stats text 0x57a1b0, initializeContents '
        '0x57a9f0, setDirty / isDirty 0x57b020 / 0x57b030, onDescendentAdded / Removing 0x57b040 / 0x57b070, '
        'onChildChanged 0x57b630); the DescribedNonCreatable<DataModel> constructor 0x57a7b0, the DataModel ??_E '
        'thunks 0x57b0a0..0x57b160, ~DataModel 0x57ad70, DataModel() 0x57b9f0 ("Level"), ??_G 0x57bbe0, and '
        'rbx_httpGet / rbx_httpPost 0x57bc00 / 0x57be10. Built here: the Creatable / FactoryProduct / ServiceProvider '
        'instances (current headers). DataModel\'s own rows need declarations the core v8datamodel/DataModel.h lacks '
        '(proposals); not built.'),
    'library code': (
        'No separately compiled library unit starts in the range. The boost function / bind / any and STL rows '
        '(functor_manager 0x579b70 / 0x57a9b0, storage helpers) are header instances inside the DataModel unit, '
        'instantiated with Roblox types; not recovered here.'),
    'excluded': (
        'No CRobloxApp / CMainFrame / CRobloxDoc / CRobloxView member lies in the range. 0x57a1b0 / 0x57a6c0 are '
        'called from the view unit (0x45bc80 / 0x45e3f0) but are DataModel code (stats strings, ArrowCursor).'),
}
NOT_EXACT = {
    '0x578530 ServiceProvider::find<LocalBackpack>() const (320 B)': (
        'built: 404 B, the native boost shared_ptr<Instance> destructor is inlined; the original calls it out of line '
        'at 0x600660 (the same blocker app-unit448 / app-unit48c record for find<C>). Open; create<LocalBackpack> '
        '0x578930 binds it by identity.'),
}
REJECTED = {}
PROPOSALS = {
    'v8datamodel/DataModel.h (core owner; not edited)': (
        '(1) `extern const char sDataModel[];` instead of `extern char sDataModel[];`: the RTTI of 0x8301ac / 0x8302a0 '
        'names .?AV?$NonFactoryProduct@VServiceProvider@RBX@@$1?sDataModel@2@3QBDB@RBX@@ and '
        '.?AV?$DescribedNonCreatable@VDataModel@RBX@@VServiceProvider@2@$1?sDataModel@2@3QBDB@RBX@@ (const char array). '
        '(2) declare `DataModel();` (0x57b9f0, evidence name ??0DataModel@RBX@@QAE@XZ) and `virtual ~DataModel();` '
        '(0x57ad70, called by ??_G 0x57bbe0; the 13 ??_E thunks 0x57b0a0..0x57b160 jump there). (3) declare the '
        'protected overrides `virtual void onDescendentAdded(Instance*);` (0x57b040: ServiceProvider::onDescendentAdded '
        '0x5726a0, then setDirty(true) through the IDataState subobject +0x1f0 slot 0) and `virtual void '
        'onDescendentRemoving(const boost::shared_ptr<Instance>&);` (0x57b070, ServiceProvider 0x5726c0), slots 5/6 of '
        'vtable 0x8303cc, and `virtual void onChildChanged(Instance*, const PropertyChanged&);` (0x57b630, evidence '
        'name, slot 5 of 0x8303f4). (1)-(3) are evidence-backed but not verified in a pending build here; the first '
        'also needs the Service.h onDescendentAdded / Removing proposal of app-unit570.'),
}

paths = [Path(__file__).resolve()] + list(SOURCES.values()) + HEADERS
receipt = {
    'class': 'RBX Creatable / FactoryProduct / ServiceProvider template instances of the application range '
             '00578000..0057c000 (2008-06, DataModel unit), inactive',
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
    'range_rows_open_by_category': OPEN_CATEGORIES,
    'rows': groups,
    'open_rows_built': [{'row': '%#x (open, not counted)' % int(r['address'], 16), 'symbol': r['symbol'],
                         'exact': False, 'size': r['size'], 'target_size': r['target_size']} for r in find_rows],
    'identity_bindings': IDENTITY,
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
print('PASS app-unit578-2008: %d counted exact rows (%s); %d range rows, %d counted elsewhere, %d open; %d Creator '
      'vtables checked' % (len(exact_rows), ' '.join(exact_rows), len(range_rows), len(range_counted), len(open_rows),
                           len(creator_vtables)))
