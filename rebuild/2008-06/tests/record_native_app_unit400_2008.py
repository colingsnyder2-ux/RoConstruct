"""Verify the inactive 2008-06 native rows of the application range 00400000..0040c000 and record its unit map.

Unit map (boundary evidence in the receipt's `unit_map` / `unit_blocks`, checked below; rows counted by other receipts
are listed as 'ADDR counted by RECEIPT' text, never as a quoted bare address):
  * 00401000..0040190f  the CAboutRobloxDialog unit (vtable 0080aac4; ATL helper COMDATs);
  * 00401910..00405a9f  the ATL COM unit of CWorkspace (CComObject / CComContainedObject / CComAggObject<CWorkspace>,
                        CComClassFactory, the ATL registrar CRegObject, IObjectSafetyRobloxImpl<CWorkspace>), with the
                        COMDAT Name::doDeclare<sRunService> 00401a00;
  * 00405aa0..00405d9f  the active-document unit (setActiveDocument 00405aa0 and three small RBX helpers);
  * 00405da0..0040995f  the ATL COM unit of CApp (CComObject<CApp> ..., "CApp::RobloxAuthenticate %s %s"), with the
                        ATL CUrl / CSimpleStringT inline COMDATs and the Creatable / Name instances of RunService,
                        DebugSettings, CRenderSettings, Team, Network::Player and Selection;
  * 00409960..          the reflection-metadata / AuthoringSettings unit (Name instances of the ReflectionMetadata*
                        and Authoring classes, GlobalSettingsItem<AuthoringSettings> thunks, boost any / signals and
                        TypedPropertyDescriptor<bool> COMDATs, Metadata::Reflection / Classes / Class / Properties /
                        Functions FactoryProduct rows), continuing past 0040c000.
  No separately compiled library unit starts in the range; the ATL / STL / boost rows are header instances.

Builds (VS2008 RTM 21022, document-swap flags, /fp:fast), current native headers only (read-only):
  * native-classes/AppUnit400_2008Creators.cpp  Creator::create, create<C> and shared_ptr<C>(C*, Deleter) instances
    (and the DebugSettings / CRenderSettings shared_count constructors); the Selection rows only with
    NATIVE_APPUNIT400_PENDING against a generated v8datamodel/Selection.h copy (pending-build-only, never counted);
  * native-classes/AppUnit400_2008Names.cpp     Name::doDeclare / callDoDeclare instances.

Every relocation of a counted row is resolved to the address the original instruction uses and verified, one address
per symbol over all rows: imports by DLL export name, type descriptors and vtables by original RTTI, own rows by their
row address, rows counted by other receipts by that receipt (and the compiled body must be exact there), constructors
by evidence name or by the complete-object vtable they store, class-name arrays by the string at the pushed address.
Every Creator::create row is slot 0 of the original one-slot Creator vtable whose RTTI names the class.
A row is counted only when no other receipt counts it.
Writes work/2008-06/shared-layouts/app-unit400-2008-working.json. NATIVE_APP_UNIT400_DISCOVER=1 lists unbound
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
OUT = R / 'out/app-unit400-2008'
OUT.mkdir(parents=True, exist_ok=True)
SOURCES = {
    'creators': R / 'native-classes/AppUnit400_2008Creators.cpp',
    'names': R / 'native-classes/AppUnit400_2008Names.cpp',
}
HEADERS = [R / 'native-headers' / h for h in (
    'util/Object.h', 'util/Name.h', 'util/RunStateOwner.h', 'v8datamodel/DebugSettings.h', 'CRenderSettings.h',
    'v8datamodel/Team.h', 'Network/Player.h', 'v8datamodel/Selection.h', 'reflection/Metadata.h',
    'AuthoringSettings.h', 'v8datamodel/GlobalSettings.h')]
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit400-2008-working.json'
LO, HI = 0x400000, 0x40c000
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT400_DISCOVER'))


def build(name, src, extra=(), pre=()):
    obj = OUT / (name + '.obj')
    flags = list(pre) + nb.flags() + ['/fp:fast'] + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log[-4000:]
    return obj, flags


# ---- pending header copy: v8datamodel/Selection.h with the 2008 constructor / destructor / onEvent declarations ----
# The same declarations app-unit564 proposes (its generated copy, record_native_app_unit564_2008.py): Selection()
# 00568180, ~Selection 00566f00 and the Listener<Instance, AncestorChanged> override onEvent 005682e0. Without them the
# native Selection is abstract and create<Selection> cannot be instantiated. Pending build only; never counted.
PENDING = OUT / 'pending'
(PENDING / 'v8datamodel').mkdir(parents=True, exist_ok=True)
_selection = (R / 'native-headers/v8datamodel/Selection.h').read_text()
_anchor = '    std::vector<ISelectionBase*> filteredSelections;\n'
assert _selection.count(_anchor) == 1
(PENDING / 'v8datamodel/Selection.h').write_text(
    '// generated by tests/record_native_app_unit400_2008.py (pending build only; proposal for v8datamodel/Selection.h)\n'
    + _selection.replace(_anchor, _anchor + (
        '    Selection();                                                // 00568180\n'
        '    virtual ~Selection();                                       // 00566f00\n'
        'protected:\n'
        '    virtual void onEvent(const Instance*, AncestorChanged);     // 005682e0\n'
        'public:\n')))

OBJ, FLAGS = {}, {}
for _k, _src in SOURCES.items():
    OBJ[_k], FLAGS[_k] = build('AppUnit400_2008' + _k, _src)
OBJ['creators_pending'], FLAGS['creators_pending'] = build(
    'AppUnit400_2008creators_pending', SOURCES['creators'], ['/DNATIVE_APPUNIT400_PENDING'], ['/I' + str(PENDING)])

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


# Class -> (mangled class, FactoryProduct base mangling inside the Creator symbol, Creator name mangling (native),
#           original Creator RTTI, Creator::create, shared_ptr ctor, create<C>, shared_count, constructor, ctor symbol,
#           Creator vtable)
CREATORS = {
    'RunService': ('VRunService@RBX@@', 0x406020, 0x405ef0, 0x405fa0, 0x405e60, 0x556b00,
                   '??0RunService@RBX@@QAE@XZ', 0x80b2e8,
                   '.?AVCreator@?$FactoryProduct@VRunService@RBX@@VInstance@2@$1?sRunService@2@3QBDB@RBX@@'),
    'DebugSettings': ('VDebugSettings@RBX@@', 0x408ce0, 0x407450, 0x407820, 0x406ed0, 0x565ac0,
                      '??0DebugSettings@RBX@@QAE@XZ', 0x80b66c,
                      '.?AVCreator@?$FactoryProduct@VDebugSettings@RBX@@VItem@GlobalSettings@2@$1?sDebugSettings@2@'
                      '3QBDB@RBX@@'),
    'CRenderSettings': ('VCRenderSettings@@', 0x408f50, 0x408e20, 0x408ed0, 0x408d90, 0x448c60,
                        '??0CRenderSettings@@QAE@XZ', 0x80b674,
                        '.?AVCreator@?$FactoryProduct@VCRenderSettings@@VItem@GlobalSettings@RBX@@$1?sRenderSettings@@'
                        '3QBDB@RBX@@'),
    'Team': ('VTeam@RBX@@', 0x4091c0, 0x409090, 0x409140, 0x409000, 0x5665e0, '??0Team@RBX@@QAE@XZ', 0x80b690,
             '.?AVCreator@?$FactoryProduct@VTeam@RBX@@VInstance@2@$1?sTeam@2@3QBDB@RBX@@'),
    'Player': ('VPlayer@Network@RBX@@', 0x409430, 0x409300, 0x4093b0, 0x409270, 0x493da0,
               '??0Player@Network@RBX@@QAE@XZ', 0x80b6ac,
               '.?AVCreator@?$FactoryProduct@VPlayer@Network@RBX@@VInstance@3@$1?sPlayer@23@3PADA@RBX@@'),
    'Selection': ('VSelection@RBX@@', 0x4096a0, 0x409570, 0x409620, 0x4094e0, 0x568180,
                  '??0Selection@RBX@@QAE@XZ', 0x80b6c8,
                  '.?AVCreator@?$FactoryProduct@VSelection@RBX@@VInstance@2@$1?sSelection@2@3QBDB@RBX@@'),
}
PENDING_CLASSES = {'Selection'}


def find(obj, test, what):
    hits = [n for n, _, _ in match.coff_functions(Path(obj).read_bytes()) if not nb.LOCAL_EH.match(n) and test(n)]
    assert len(hits) == 1, (what, hits)
    return hits[0]


def creator_symbols(obj, c, mangled):
    cr = find(obj, lambda n: n.startswith('?create@Creator@?$FactoryProduct@' + mangled) and n.endswith(
        'UBE?AV?$shared_ptr@VObject@RBX@@@boost@@XZ'), (c, 'Creator::create'))
    sp = find(obj, lambda n: n.startswith('??$?0' + mangled) and '?$shared_ptr@' + mangled in n and 'QAE@PAV' in n,
              (c, 'shared_ptr'))
    cc = find(obj, lambda n: n.startswith('??$create@' + mangled + '@' + CI), (c, 'create'))
    sc = find(obj, lambda n: n.startswith('??$?0PA' + mangled) and '@shared_count@detail@boost@@QAE@' in n,
              (c, 'shared_count'))
    return cr, sp, cc, sc


ROWS = {k: [] for k in SOURCES}
PENDING_ROWS = []
COUNTED_TARGETS = {}   # symbol -> (address, receipts)
EXTERNAL = {}
CTOR = {}
for c, (mangled, cr, sp, cc, sc, ctor, ctor_sym, vt, rtti) in CREATORS.items():
    obj = OBJ['creators_pending' if c in PENDING_CLASSES else 'creators']
    syms = dict(zip(('cr', 'sp', 'cc', 'sc'), creator_symbols(obj, c, mangled)))
    rows = PENDING_ROWS if c in PENDING_CLASSES else ROWS['creators']
    for key, address in (('cr', cr), ('sp', sp), ('cc', cc), ('sc', sc)):
        where = elsewhere.get('%08x' % address)
        if where:
            COUNTED_TARGETS[syms[key]] = (address, sorted(set(where)))
        else:
            rows.append((address, syms[key]))
    CTOR[ctor_sym] = ctor
    EXTERNAL[ctor_sym] = ctor

# Name::doDeclare / callDoDeclare instances (AppUnit400_2008Names.cpp): (row, name array symbol, string)
NM = '@Name@RBX@@'
NAME_ROWS = [
    (0x401a00, None, '?sRunService@RBX@@3PADA', 'RunService'),
    (0x406770, 0x406e90, '?sRenderSettings@@3PADA', 'RenderSettings'),
    (0x4067e0, 0x406ea0, '?sTeam@RBX@@3QBDB', 'Team'),
    (0x406850, 0x406eb0, '?sPlayer@Network@RBX@@3PADA', 'Player'),
    (0x4068c0, 0x406ec0, '?sSelection@RBX@@3PADA', 'Selection'),
    (0x4099c0, 0x409fd0, '?sReflection@Metadata@RBX@@3PADA', 'ReflectionMetadata'),
    (0x409a30, 0x409fe0, '?sClasses@Metadata@Reflection@RBX@@3PADA', 'ReflectionMetadataClasses'),
    (0x409aa0, 0x409ff0, '?sClass@Metadata@Reflection@RBX@@3PADA', 'ReflectionMetadataClass'),
    (0x409b10, 0x40a000, '?sProperties@Metadata@Reflection@RBX@@3PADA', 'ReflectionMetadataProperties'),
    (0x409b80, 0x40a010, '?sFunctions@Metadata@Reflection@RBX@@3PADA', 'ReflectionMetadataFunctions'),
    (0x409bf0, 0x40a020, '?sEvents@Metadata@Reflection@RBX@@3PADA', 'ReflectionMetadataEvents'),
    (0x409c60, 0x40a030, '?sMember@Metadata@Reflection@RBX@@3PADA', 'ReflectionMetadataMember'),
    (0x409cd0, 0x40a040, '?sAuthoringSettings@@3PADA', 'Authoring'),
    (0x40b790, 0x40b800, '?sItem@Metadata@Reflection@RBX@@3PADA', 'ReflectionMetadataItem'),
]
NAME_DATA = {}
for _do, _call, _sym, _text in NAME_ROWS:
    # each doDeclare row holds exactly its class-name string; each callDoDeclare row is a jmp to its doDeclare row
    assert FUNCTIONS[_do]['strings'] == [_text], (hex(_do), FUNCTIONS[_do]['strings'])
    _pairs = [(_do, '??$doDeclare@$1' + _sym + NM + 'CAABV01@XZ')]
    if _call is not None:
        _b = original.data(_call, 5)
        assert _b[0] == 0xe9 and _call + 5 + struct.unpack_from('<i', _b, 1)[0] == _do, hex(_call)
        _pairs.append((_call, '??$callDoDeclare@$1' + _sym + NM + 'CAXXZ'))
    for _a, _s in _pairs:
        if '%08x' % _a in elsewhere:
            COUNTED_TARGETS[_s] = (_a, sorted(set(elsewhere['%08x' % _a])))
        else:
            ROWS['names'].append((_a, _s))
    NAME_DATA[_sym] = _text
EXTERNAL['?declare@Name@RBX@@SAABV12@PBDH@Z'] = 0x553f90
EXTERNAL['??3@YAXPAX@Z'] = 0x6a067a
# Creatable<Instance>::Deleter::operator()(Instance*) 00405e30, called from the shared_count catch funclet (bound as
# record_native_creatable_shared_count.py binds it)
EXTERNAL['??RDeleter@?$Creatable@VInstance@RBX@@@RBX@@QAEXPAVInstance@2@@Z'] = 0x405e30
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


def ctor_vtables(address):
    """Vtables a constructor body stores (C7 /0 imm32 into a register base), with their original RTTI class."""
    body, _, _ = match.target('2008-06', '%08x' % address)
    found = []
    for i in range(len(body) - 6):
        if body[i] == 0xc7 and (body[i + 1] & 0xf8) in (0x00, 0x40, 0x80):
            off = {0x00: 0, 0x40: 1, 0x80: 4}[body[i + 1] & 0xc0]
            v = struct.unpack_from('<I', body, i + 2 + off)[0]
            try:
                c = original.vtable_class(v)
            except Exception:
                continue
            if c and c[0]:
                found.append((v, c))
    return found


CONSTRUCTOR_PROOF = {}


def prove_constructor(symbol, value):
    if names.get(value, '') == symbol:
        return 'evidence name'
    cls = symbol[3:-len('QAE@XZ')]
    stores = [v for v, c in ctor_vtables(value) if c == ('.?AV' + cls, 0)]
    assert stores, (symbol, hex(value), ctor_vtables(value))
    return 'stores the .?AV%s complete-object vtable %s' % (cls, hex(stores[0]))


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
            elif symbol.startswith('??_R0') and symbol.endswith('@8'):
                rtti = original.string(value + 8)
                assert norm(rtti) == norm('.' + symbol[5:-2]), (where, symbol, hex(value), rtti)
                how = 'RTTI %s' % rtti
            elif symbol.startswith('??_7'):
                rtti, at = original.vtable_class(value)
                cls = symbol[4:symbol.index('@@6B') + 2]
                assert norm(rtti) == norm('.?AV' + cls), (where, symbol, hex(value), rtti)
                how = 'vtable RTTI %s offset %#x' % (rtti, at)
            elif symbol in COUNTED_TARGETS:
                other, receipts = COUNTED_TARGETS[symbol]
                assert other == value, (where, symbol, hex(value), hex(other))
                hb, hr = bodies[symbol]
                ht, htr, _ = match.target('2008-06', '%08x' % value)
                assert match.exact_match(ht, htr, hb, hr), ('counted-elsewhere body not exact', symbol, hex(value))
                how = 'row counted by %s (compiled body exact at the bound address)' % ', '.join(receipts)
            elif symbol in NAME_DATA:
                assert original.string(value) == NAME_DATA[symbol], (where, symbol, hex(value))
                how = 'class-name array %r (string at the pushed address)' % NAME_DATA[symbol]
            elif symbol in EXTERNAL:
                assert EXTERNAL[symbol] == value, (where, symbol, hex(value), hex(EXTERNAL[symbol]))
                if symbol in CTOR:
                    how = 'constructor: ' + CONSTRUCTOR_PROOF.setdefault(symbol, prove_constructor(symbol, value))
                else:
                    how = 'external' + (' (evidence name)' if names.get(value, '') == symbol else '')
            elif symbol in bodies:
                # helper / COMDAT body compiled here but not a row: exact at the bound address, never counted
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
pending = verify('creators_pending', OBJ['creators_pending'], PENDING_ROWS, record=False)
not_exact = [r for rows in groups.values() for r in rows if not r['exact']]
if DISCOVER:
    for u in UNBOUND:
        print('UNBOUND', u)
    for r in not_exact + [r for r in pending if not r['exact']]:
        print('NOT EXACT', r['address'], r['size'], r['target_size'], r['symbol'][:100])
assert not UNBOUND or DISCOVER, UNBOUND
assert not not_exact or DISCOVER, [(r['address'], r['symbol'][:80]) for r in not_exact]
assert all(r['exact'] for r in pending) or DISCOVER, [r['address'] for r in pending if not r['exact']]
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
                            'slot0': '%#x (Creator::create row%s)' % (cr, ', pending-build-only' if c in PENDING_CLASSES
                                                                       else '')})


# ---- sizeof(C): the malloc size each create<C> passes, against the native header --------------------------------
def malloc_size(address):
    body, _, _ = match.target('2008-06', '%08x' % address)
    sizes = [struct.unpack_from('<I', body, k.start() + 1)[0] for k in re.finditer(rb'\x68', body)]
    return [s for s in sizes if 0x40 <= s < 0x4000]


SIZES = {}
for c, (mangled, cr, sp, cc, sc, ctor, ctor_sym, vt, rtti) in CREATORS.items():
    got = malloc_size(cc)
    assert len(got) == 1, (c, hex(cc), [hex(x) for x in got])
    SIZES[c] = 'sizeof %#x (malloc in create<%s> %#x; %s)' % (
        got[0], c, cc, 'pending build' if c in PENDING_CLASSES else
        ('compiled exact there, row counted by %s' % ', '.join(sorted(set(elsewhere['%08x' % cc]))))
        if '%08x' % cc in elsewhere else 'exact here against the native header layout')


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
    ('rbx CAboutRobloxDialog unit (ATL helper COMDATs)', LO, 0x401910,
     [('string', 0x401390, 'Version')], [('vt', 0x401040, '.?AVCAboutRobloxDialog@@')]),
    ('rbx ATL COM unit of CWorkspace (CComObject<CWorkspace>, CComClassFactory, CRegObject registrar; COMDAT '
     'Name::doDeclare<sRunService>)', 0x401910, 0x405aa0,
     [('string', 0x403b60, 'Failed to get SiteUrl'), ('string', 0x403650, 'HKCR'), ('string', 0x4043f0, 'ForceRemove'),
      ('string', 0x401a00, 'RunService')],
     [('vt', 0x401960, '.?AV?$CComObject@VCWorkspace@@@ATL@@'), ('vt', 0x405340, '.?AV?$CComObject@VCWorkspace@@@ATL@@'),
      ('vt', 0x403180, '.?AVCComClassFactory@ATL@@'), ('vt', 0x403f40, '.?AVCRegObject@ATL@@')]),
    ('rbx active-document unit (setActiveDocument)', 0x405aa0, 0x405da0, [], []),
    ('rbx ATL COM unit of CApp (CComObject<CApp>, CUrl inline, Creatable / Name instances)', 0x405da0, 0x409960,
     [('string', 0x408a70, 'CApp::RobloxAuthenticate %s %s'), ('string', 0x4078a0, 'requested WindowType is invalid'),
      ('string', 0x4097c0, '?suggest='), ('string', 0x406700, 'DebugSettings')],
     [('vt', 0x406110, '.?AV?$CComObject@VCApp@@@ATL@@'), ('vt', 0x408a70, '.?AV?$CComObject@VCApp@@@ATL@@'),
      ('vt', 0x406020, '.?AVCreator@?$FactoryProduct@VRunService@RBX@@'),
      ('vt', 0x4096a0, '.?AVCreator@?$FactoryProduct@VSelection@RBX@@')]),
    ('rbx reflection-metadata / AuthoringSettings unit (continues past the range)', 0x409960, HI,
     [('string', 0x4099c0, 'ReflectionMetadata'), ('string', 0x409cd0, 'Authoring'),
      ('string', 0x40a220, 'Exception caught in onEvent. %s')],
     [('vt', 0x409e60, '.?AVItem@GlobalSettings@RBX@@'),
      ('vt', 0x40a720, '.?AV?$GlobalSettingsItem@VAuthoringSettings@@'), ('vt', 0x40a9f0, '.?AVAuthoringSettings@@'),
      ('vt', 0x40b3a0, '.?AVCreator@?$FactoryProduct@VReflection@Metadata@'),
      ('vt', 0x40bee0, '.?AV?$FactoryProduct@VFunctions@Metadata@Reflection@RBX@@')]),
]
range_rows = sorted(a for a in FUNCTIONS if LO <= a < HI)
for a in range_rows:
    assert sum(lo <= a < hi for _, lo, hi, _, _ in BLOCKS) == 1, hex(a)
for name, lo, hi, strings, vts in BLOCKS:
    for _, a, text in strings:
        assert lo <= a < hi and holds_string(a, text), (name, hex(a), text)
    for _, a, prefix in vts:
        assert lo <= a < hi and in_vtable(a, prefix), (name, hex(a), prefix)
# setActiveDocument 00405aa0 (ActiveDocView.h proposal): called by getPlayDocument 0044b9a0, reads CRobloxDoc 00403040
assert '0044b9a0' in FUNCTIONS[0x405aa0]['callers'] and '00403040' in FUNCTIONS[0x405aa0]['call_targets']
# the class-name static initializers 007ee760..007eebe0 are the callers of the Name rows (one TU after another)
for _do, _call, _sym, _text in NAME_ROWS:
    if _do != 0x40b790:
        assert any('007ee700' <= c < '007eec00' for c in FUNCTIONS[_do]['callers']), (hex(_do), FUNCTIONS[_do]['callers'])

exact_rows = sorted({r['address'] for rows in groups.values() for r in rows if r['exact']})
double = {a: elsewhere[a] for a in exact_rows if a in elsewhere}
assert not double, double
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if LO <= int(a, 16) < HI}
open_rows = ['%08x' % a for a in range_rows if '%08x' % a not in exact_rows and '%08x' % a not in range_counted]


def category(a):
    for name, lo, hi, _, _ in BLOCKS:
        if lo <= a < hi:
            blk = name.split(' (')[0][4:]
    n = names.get(a, '')
    if '@ATL@@' in n:
        return 'ATL library inline (%s)' % blk
    if re.search(r'@(std|boost)@@', n.split('@@Q')[0]) or n.startswith('??$_') or '@detail@boost@@' in n:
        return 'STL/boost template instance (%s)' % blk
    return 'RBX / unnamed (%s)' % blk


OPEN_CATEGORIES = {}
for a in open_rows:
    OPEN_CATEGORIES.setdefault(category(int(a, 16)), []).append('%#x' % int(a, 16))

UNIT_MAP = {
    'rbx CAboutRobloxDialog unit 0x401000..0x40190f': (
        'AtlThrowImpl 0x401000 and the ATL string / CRT helper COMDATs (AtlCrtErrorCheck 0x401680, tcsncpy_s 0x401810, '
        'evidence names), CAboutRobloxDialog members 0x401040..0x401390 (vtable 0x80aac4 slots 0/1/12/65/66/67/81/86/94, '
        'the CDHtmlDialog sub-vtable 0x80aa98 slot 7 0x4012d0; 0x401390 holds "Version" / "systemInfo" / "glVersion"). '
        'Not recovered here: CAboutRobloxDialog has its own native header / sources (CAboutRobloxDialog.h, '
        'CAboutRobloxDialog*.cpp, other owners); the ATL rows are library header code.'),
    'rbx ATL COM unit of CWorkspace 0x401910..0x405a9f': (
        'CComObject / CComContainedObject / CComAggObject<CWorkspace> slots and QueryInterface / AddRef / Release '
        'thunks (vtables 0x80ae0c..0x80b144), the COM map 0x401910 / 0x402730 (workspace-com-map-trial), CComClassFactory '
        '(0x80b168) and CComObjectNoLock<CComClassFactory> (0x80b230), the ATL registrar CRegObject / CRegParser '
        '(0x80b184; "HKCR" 0x403650, "Delete" / "ForceRemove" / "NoRemove" 0x4043f0, RegDeleteKeyExA 0x401bf0), CRegKey '
        'Open / Close (evidence names), the IObjectSafetyRobloxImpl<CWorkspace> site check 0x403b60 ("Failed to get '
        'SiteUrl", "Untrusted Site: %s"; callers 0x404d20 / 0x404db0 = slots 3/4 of 0x81c80c), boost shared_count '
        'helpers 0x402570 / 0x4025b0 and the COMDAT Name::doDeclare<sRunService> 0x401a00 (built and counted here). '
        'Not recovered here: CWorkspace has native sources (CWorkspace*.cpp / Workspace*.cpp, record_native_workspace.py; '
        'other owners); the ATL registrar / class-factory rows are library header code.'),
    'rbx active-document unit 0x405aa0..0x405d9f': (
        'setActiveDocument(bool, CRobloxDoc*) 0x405aa0 (CRobloxDoc::getDataModel 0x403040; callers getPlayDocument '
        '0x44b9a0 and two others; native-classes/ActiveDocument.cpp of another owner) and three helpers 0x405ce0 / '
        '0x405d50 / 0x405d80 (callers in the doc / view units). Not recovered here (ActiveDocView owner; it dispatches '
        'into CRobloxDoc, a maintainer exclusion).'),
    'rbx ATL COM unit of CApp 0x405da0..0x40995f': (
        'AbstractFactoryProduct<Instance>::getCreators 0x405da0 (evidence name), boost sp_counted_base COMDATs, the '
        'Creatable blocks of RunService (0x405e60..0x40602f), DebugSettings (0x406ed0, 0x407450, 0x407820, 0x408ce0), '
        'CRenderSettings (0x408d90..0x408fff), Team (0x409000..0x40926f), Network::Player (0x409270..0x4094df) and '
        'Selection (0x4094e0..0x40974f); Name::doDeclare 0x406700..0x4068c0 and callDoDeclare 0x406e80..0x406ec0 '
        '(static initializers 0x7ee7b0..0x7ee8f0); the CComObject / CComContainedObject / CComAggObject<CApp> slots and '
        'thunks (vtables 0x80b50c..0x80b638; WindowType / workspace creation 0x4078a0, "CApp::RobloxAuthenticate %s %s" '
        '0x408a70 and its negotiation helper 0x4097c0 "?suggest="), IObjectSafetyRobloxImpl<CApp> 0x407500 / 0x407690 / '
        '0x407720, GlobalSettingsItem<DebugSettings>::singleton 0x407be0 (settings owner), and the ATL CUrl / '
        'AtlUnescapeUrl / CSimpleStringT inline COMDATs 0x4062a0..0x408960 (evidence names). Built here: the Creatable '
        'and Name instances; CApp itself is a WindowsClient COM class with no native header (not recovered); the ATL '
        'rows are library header code.'),
    'rbx reflection-metadata / AuthoringSettings unit 0x409960..0x40c000 (continues past the range)': (
        'GlobalSettings::Item inline constructor 0x409960 / 0x409e00, Name::doDeclare of the ReflectionMetadata* and '
        'Authoring classes 0x4099c0..0x409cd0 with callDoDeclare 0x409fd0..0x40a040 (static initializers '
        '0x7ee9b0..0x7eebe0) and ReflectionMetadataItem 0x40b790 / 0x40b800 (built and counted here); std / boost '
        'exception COMDATs (runtime_error, bad_function_call, bad_any_cast, any::holder<bool>), '
        'Notifier::raise 0x40a220 ("Exception caught in onEvent. %s"), TypedPropertyDescriptor<bool> 0x40a290 / 0x40a5c0 '
        '/ 0x40a660 / 0x40aa70, the GlobalSettingsItem<AuthoringSettings> / AuthoringSettings adjustor thunks '
        '0x40a140..0x40aa60, boost signals named_slot_map iterator COMDATs, ~ClassDescriptor 0x40abc0, rootDescriptor '
        '0x40ad20, Described<Instance>::classDescriptor 0x40ad80 (counted by humanoid2008), and the '
        'Metadata::Reflection / Classes / Class / Properties / Functions FactoryProduct rows 0x40ae60..0x40c000 '
        '(Creator vtable 0x80bc4c etc.). The unit continues past 0x40c000 (AuthoringSettings() 0x40d140, '
        'create<AuthoringSettings> 0x40d410; the app-unit 0040c000 range). Not recovered here beyond the Name rows: the '
        'Metadata classes have native sources of another owner (Metadata*.cpp) and the Metadata::Reflection rows need '
        'the reflection/Metadata.h namespace proposal (RTTI .?AVReflection@Metadata@Reflection@RBX@@).'),
    'library code': (
        'No separately compiled library unit starts in the range. ATL (atlbase.h registrar / class factory / '
        'CComObject, atlutil.h CUrl, atlsimpstr.h CSimpleStringT), STL and boost rows are header instances inside the '
        'units above and are not recovered.'),
    'excluded': (
        'No CRobloxApp / CMainFrame / CRobloxDoc / CRobloxView member lies in the range (the CRobloxApp vtable 0x816a64 '
        'is referenced only from 0x44c3d0 / 0x44c440). setActiveDocument 0x405aa0 dispatches into CRobloxDoc and is '
        'left to its owner.'),
}
PENDING_REASON = ('pending-build-only (NATIVE_APPUNIT400_PENDING with the generated v8datamodel/Selection.h copy '
                  'that declares Selection() / ~Selection / onEvent(AncestorChanged); proposal); not counted')
NOT_EXACT = {
    '0x409570 / 0x409620 / 0x4096a0 shared_ptr<Selection>, create<Selection>, Selection Creator::create': PENDING_REASON,
}
REJECTED = {
    'explicit instantiation `template boost::shared_ptr<Selection>::shared_ptr(Selection*, Deleter)` to build '
    '0x409570 from the current headers': (
        'C2794 (the boost 1.34.1 auto_ptr constructor template is matched first); with explicit template arguments '
        'C2977. The row is built through create<Selection> in the pending build instead.'),
}
PROPOSALS = {
    'v8datamodel/Selection.h (owner)': (
        'declare `Selection();` (0x568180, called by create<Selection> 0x409620 after malloc 0x174), `virtual '
        '~Selection();` (0x566f00) and the protected override `virtual void onEvent(const Instance*, AncestorChanged);` '
        '(0x5682e0), as app-unit564 proposes. With the generated copy out/app-unit400-2008/pending/v8datamodel/'
        'Selection.h, shared_ptr<Selection> 0x409570, create<Selection> 0x409620 and the Creator 0x4096a0 (slot 0 of '
        'vtable 0x80b6c8) are exact with every target bound (pending_build_only, exact=false).'),
    'mangling FYI (no row here depends on it)': (
        'the original Creator RTTI names sRunService (0x80b2e8), sRenderSettings (0x80b674) and sSelection (0x80b6c8) '
        'const char arrays (3QBDB) while util/RunStateOwner.h, CRenderSettings.h and v8datamodel/Selection.h declare '
        '`extern char` (3PADA); Network::sPlayer is 3PADA in both. Symbol mangling only.'),
}

paths = [Path(__file__).resolve()] + list(SOURCES.values()) + HEADERS
receipt = {
    'class': 'RBX Creatable / Name template instances of the application range 00400000..0040c000 (2008-06), inactive',
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
    'creator_vtables': creator_vtables,
    'helper_bodies_not_counted': HELPERS,
    'pending_build_only': [{'row': '%#x (pending-build-only, exact=false)' % int(r['address'], 16),
                            'symbol': r['symbol'], 'exact': False, 'pending_exact': r['exact'],
                            'reason': PENDING_REASON, 'verified_targets': r['verified_targets']} for r in pending],
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
print('PASS app-unit400-2008: %d counted exact rows (%s); %d range rows, %d counted elsewhere, %d open; %d Creator '
      'vtables checked; %d pending-build-only' % (len(exact_rows), ' '.join(exact_rows), len(range_rows),
                                                  len(range_counted), len(open_rows), len(creator_vtables), len(pending)))
