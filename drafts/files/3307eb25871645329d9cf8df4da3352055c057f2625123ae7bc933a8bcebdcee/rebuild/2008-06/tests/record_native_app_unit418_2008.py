"""Verify the inactive 2008-06 native rows of the application range 00418000..00424000 and record its unit map.

Unit map (boundary evidence in the receipt's `unit_map` / `unit_blocks`, checked below; rows counted by other receipts
are listed as 'ADDR counted by RECEIPT' text, never as a quoted bare address):
  * ..00419d0f          CLuaFunction ATL COM unit (CComObject / CComContainedObject / CComAggObject<CLuaFunction>,
                        ATL window thunks; starts below the range);
  * 00419d10..0041d4af  the DHTMLWindowService / Marshaller / DHTMLWindow descriptor unit (app-leaves owners), with the
                        boost any / signals / function COMDATs and the DHTMLWindowService Creatable instances;
  * 0041d4b0..0041dd5f  a content-url helper run ("?filename=" / "Empty!!!" 0041d760, reached from the CApp unit
                        through 0041db00) and shared COMDAT helpers;
  * 0041dd60..0041f9bf  the insert-verb unit (InsertDecal / InsertTexture / InsertObject / InsertService verbs, vtables
                        0080f15c / 00817324 / 0080f204 / 0080f22c) with the Name / Creatable instances of Decal,
                        Texture, Part(Instance), SpecialMesh(SpecialShape) and ContentProvider;
  * 0041f9c0..0042077f  CInsertObjectDialog / CListCtrl (insert-object-dialog owner) with the AbstractFactoryProduct /
                        vector<shared_ptr<Instance>> COMDATs;
  * 00420780..0042261f  CInstanceExplorer / CInstanceRecord::CNameItem / MarshaledListener<Instance, Descendant*>
                        (instance-explorer owner), MFC CImageList / CMenu inline COMDATs and CRT / STL helpers;
  * 00422620..          CRobloxTreeCtrl / CSelectionTreeCtrl / RootNode (tree-ctrl owners), continuing past the range.
  No separately compiled library unit starts in the range; the ATL / MFC / STL / boost rows are header instances.

Builds (VS2008 RTM 21022, document-swap flags, /fp:fast), current native headers only (read-only, no new header):
  * native-classes/AppUnit418_2008Creators.cpp  shared_ptr<C> / create<C> / Creator::create of DHTMLWindowService,
    Decal, Texture, PartInstance, SpecialShape and Name::doDeclare / callDoDeclare of Decal / Texture / Part;
  * native-classes/AppUnit418_2008Content.cpp   shared_ptr / create<ContentProvider> and its Name instances (separate
    unit: util/NativeContentProvider.h collides with the donor ContentProvider, C2011).

Every relocation of a counted row is resolved to the address the original instruction uses and verified, one address
per symbol over all rows: imports by DLL export name, type descriptors and vtables by original RTTI, own rows by their
row address, rows counted by other receipts by that receipt (and the compiled body must be exact there), constructors
by evidence name or by the complete-object vtable they store, class-name arrays by the string at the pushed address.
Every Creator::create row is slot 0 of the original one-slot Creator vtable whose RTTI names the class.
A row is counted only when no other receipt counts it.
Writes work/2008-06/shared-layouts/app-unit418-2008-working.json. NATIVE_APP_UNIT418_DISCOVER=1 lists unbound
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
OUT = R / 'out/app-unit418-2008'
OUT.mkdir(parents=True, exist_ok=True)
SOURCES = {
    'creators': R / 'native-classes/AppUnit418_2008Creators.cpp',
    'content': R / 'native-classes/AppUnit418_2008Content.cpp',
}
HEADERS = [R / 'native-headers' / h for h in (
    'util/Object.h', 'util/Name.h', 'AppLeaves2008/DHTMLWindowService2008.h', 'v8datamodel/Decal.h',
    'v8datamodel/PartInstance.h', 'v8datamodel/SpecialShape.h', 'util/NativeContentProvider.h')]
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit418-2008-working.json'
LO, HI = 0x418000, 0x424000
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT418_DISCOVER'))


def build(name, src, extra=(), pre=()):
    obj = OUT / (name + '.obj')
    flags = list(pre) + nb.flags() + ['/fp:fast'] + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log[-4000:]
    return obj, flags


OBJ, FLAGS = {}, {}
for _k, _src in SOURCES.items():
    OBJ[_k], FLAGS[_k] = build('AppUnit418_2008' + _k, _src)

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

# Class -> (build, mangled class, Creator::create (None: no Creator), shared_ptr ctor, create<C>, shared_count,
#           constructor, ctor symbol, Creator vtable, Creator RTTI prefix)
CREATORS = {
    'DHTMLWindowService': ('creators', 'VDHTMLWindowService@@', 0x41ceb0, 0x41baa0, 0x41cda0, 0x41ba00, 0x41c9c0,
                           '??0DHTMLWindowService@@QAE@XZ', 0x80ed48,
                           '.?AVCreator@?$FactoryProduct@VDHTMLWindowService@@VInstance@RBX@@$1?sDHTMLWindowService@@'),
    'Decal': ('creators', 'VDecal@RBX@@', 0x41e720, 0x41e2c0, 0x41e4d0, 0x41e100, 0x598400, '??0Decal@RBX@@QAE@XZ',
              0x80f1b4, '.?AVCreator@?$FactoryProduct@VDecal@RBX@@VFaceInstance@2@$1?sDecal@2@'),
    'Texture': ('creators', 'VTexture@RBX@@', 0x41e7d0, 0x41e370, 0x41e550, 0x41e190, 0x598870,
                '??0Texture@RBX@@QAE@XZ', 0x80f1bc, '.?AVCreator@?$FactoryProduct@VTexture@RBX@@VDecal@2@$1?sTexture@2@'),
    'PartInstance': ('creators', 'VPartInstance@RBX@@', 0x41ea40, 0x41e910, 0x41e9c0, 0x41e880, 0x59d4d0,
                     '??0PartInstance@RBX@@QAE@XZ', 0x80f1c4,
                     '.?AVCreator@?$FactoryProduct@VPartInstance@RBX@@VPVInstance@2@$1?sPart@2@'),
    'SpecialShape': ('creators', 'VSpecialShape@RBX@@', 0x41ecb0, 0x41eb80, 0x41ec30, 0x41eaf0, 0x59fbb0,
                     '??0SpecialShape@RBX@@QAE@XZ', 0x80f1e0,
                     '.?AVCreator@?$FactoryProduct@VSpecialShape@RBX@@VInstance@2@$1?sSpecialShape@2@'),
    'ContentProvider': ('content', 'VContentProvider@RBX@@', None, 0x41e420, 0x41e5d0, 0x41e230, 0x562c30,
                        '??0ContentProvider@RBX@@QAE@XZ', None, None),
}


def find(obj, test, what):
    hits = [n for n, _, _ in match.coff_functions(Path(obj).read_bytes()) if not nb.LOCAL_EH.match(n) and test(n)]
    assert len(hits) == 1, (what, hits)
    return hits[0]


def creator_symbols(obj, c, mangled, has_creator):
    cr = find(obj, lambda n: n.startswith('?create@Creator@?$FactoryProduct@' + mangled) and n.endswith(
        'UBE?AV?$shared_ptr@VObject@RBX@@@boost@@XZ'), (c, 'Creator::create')) if has_creator else None
    sp = find(obj, lambda n: n.startswith('??$?0' + mangled) and '?$shared_ptr@' + mangled in n and 'QAE@PAV' in n,
              (c, 'shared_ptr'))
    cc = find(obj, lambda n: n.startswith('??$create@' + mangled + '@' + CI), (c, 'create'))
    sc = find(obj, lambda n: n.startswith('??$?0PA' + mangled) and '@shared_count@detail@boost@@QAE@' in n,
              (c, 'shared_count'))
    return cr, sp, cc, sc


ROWS = {k: [] for k in SOURCES}
# create<PartInstance> 0041e9c0 mallocs 0x404 but the native v8datamodel/PartInstance.h layout is only 0x2ec bytes
# (its fields past the embedded Primitive are not derived), so that row is not exact and the PartInstance Creator
# 0041ea40, byte-exact but calling it, is not counted either (both built and reported, never counted).
NOT_COUNTED_KEYS = {('PartInstance', 'cc'), ('PartInstance', 'cr')}
NOT_COUNTED_ROWS = []
COUNTED_TARGETS = {}   # symbol -> (address, receipts)
EXTERNAL = {}
CTOR = {}
for c, (b, mangled, cr, sp, cc, sc, ctor, ctor_sym, vt, rtti) in CREATORS.items():
    syms = dict(zip(('cr', 'sp', 'cc', 'sc'), creator_symbols(OBJ[b], c, mangled, cr is not None)))
    for key, address in (('cr', cr), ('sp', sp), ('cc', cc), ('sc', sc)):
        if address is None:
            continue
        where = elsewhere.get('%08x' % address)
        if where:
            COUNTED_TARGETS[syms[key]] = (address, sorted(set(where)))
        elif (c, key) in NOT_COUNTED_KEYS:
            NOT_COUNTED_ROWS.append((address, syms[key]))
        else:
            ROWS[b].append((address, syms[key]))
    CTOR[ctor_sym] = ctor
    EXTERNAL[ctor_sym] = ctor

# Name::doDeclare / callDoDeclare instances: (build, doDeclare row, callDoDeclare row, name array symbol, string)
NM = '@Name@RBX@@'
NAME_ROWS = [
    ('creators', 0x41de20, 0x41e0b0, '?sDecal@RBX@@3PADA', 'Decal'),
    ('creators', 0x41de90, 0x41e0c0, '?sTexture@RBX@@3PADA', 'Texture'),
    ('creators', 0x41df00, 0x41e0d0, '?sPart@RBX@@3PADA', 'Part'),
    ('content', 0x41dfe0, 0x41e0f0, '?sContentProvider@RBX@@3PADA', 'ContentProvider'),
]
NAME_DATA = {}
for _b, _do, _call, _sym, _text in NAME_ROWS:
    # each doDeclare row holds exactly its class-name string; each callDoDeclare row is a jmp to its doDeclare row
    assert FUNCTIONS[_do]['strings'] == [_text], (hex(_do), FUNCTIONS[_do]['strings'])
    _b5 = original.data(_call, 5)
    assert _b5[0] == 0xe9 and _call + 5 + struct.unpack_from('<i', _b5, 1)[0] == _do, hex(_call)
    for _a, _s in ((_do, '??$doDeclare@$1' + _sym + NM + 'CAABV01@XZ'), (_call, '??$callDoDeclare@$1' + _sym + NM + 'CAXXZ')):
        if '%08x' % _a in elsewhere:
            COUNTED_TARGETS[_s] = (_a, sorted(set(elsewhere['%08x' % _a])))
        else:
            ROWS[_b].append((_a, _s))
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
not_counted = verify('creators', OBJ['creators'], NOT_COUNTED_ROWS, record=False)
not_exact = [r for rows in groups.values() for r in rows if not r['exact']]
_nc = {r['address']: r['exact'] for r in not_counted}
assert _nc == {'0041e9c0': False, '0041ea40': True} or DISCOVER, _nc
if DISCOVER:
    for u in UNBOUND:
        print('UNBOUND', u)
    for r in not_exact:
        print('NOT EXACT', r['address'], r['size'], r['target_size'], r['symbol'][:100])
assert not UNBOUND or DISCOVER, UNBOUND
assert not not_exact or DISCOVER, [(r['address'], r['symbol'][:80]) for r in not_exact]
for symbol, address in EXTERNAL.items():
    assert address in FUNCTIONS or original.imported(address) is not None, (symbol, hex(address))

# ---- Creator vtables (original): slot 0 is the Creator::create row; the RTTI names the class -----------------------
creator_vtables = []
for c, (b, mangled, cr, sp, cc, sc, ctor, ctor_sym, vt, rtti) in CREATORS.items():
    if cr is None:
        continue
    got = original.vtable_class(vt)
    assert got[1] == 0 and got[0].startswith(rtti), (c, hex(vt), got)
    assert d(vt) == cr, (c, hex(vt), hex(d(vt)), hex(cr))
    slots = 0
    while TEXT[0] <= d(vt + 4 * slots) < TEXT[1]:
        slots += 1
    assert slots == 1, (c, hex(vt), slots)
    creator_vtables.append({'vtable': hex(vt), 'rtti': got[0], 'original_slots': slots,
                            'slot0': '%#x (Creator::create row)' % cr})


# ---- sizeof(C): the malloc size each create<C> passes, against the native header --------------------------------
def malloc_size(address):
    body, _, _ = match.target('2008-06', '%08x' % address)
    sizes = [struct.unpack_from('<I', body, k.start() + 1)[0] for k in re.finditer(rb'\x68', body)]
    return [s for s in sizes if 0x40 <= s < 0x4000]


SIZES = {}
for c, (b, mangled, cr, sp, cc, sc, ctor, ctor_sym, vt, rtti) in CREATORS.items():
    got = malloc_size(cc)
    assert len(got) == 1, (c, hex(cc), [hex(x) for x in got])
    SIZES[c] = 'sizeof %#x (malloc in create<%s> %#x; %s)' % (
        got[0], c, cc, ('compiled exact there, row counted by %s' % ', '.join(sorted(set(elsewhere['%08x' % cc]))))
        if '%08x' % cc in elsewhere else 'exact here against the native header layout')
SIZES['PartInstance'] = ('sizeof 0x404 (malloc in create<PartInstance> 0x41e9c0); the native v8datamodel/'
                         'PartInstance.h layout compiles to 0x2ec, so create<PartInstance> is not exact here')
SIZES['PartInstance'] += ('; PartInstance() 0x59d4d0 ends ret 4: the 1 that create<PartInstance> pushes is the '
                          'virtual-base construction flag, so the 122-byte body is the no-argument constructor call')


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
    ('rbx CLuaFunction ATL COM unit (starts below the range)', LO, 0x419d10,
     [],
     [('vt', 0x418880, '.?AV?$CComAggObject@VCLuaFunction@@@ATL@@'),
      ('vt', 0x419080, '.?AV?$CComObject@VCLuaFunction@@@ATL@@')]),
    ('rbx DHTMLWindowService / Marshaller / DHTMLWindow descriptor unit', 0x419d10, 0x41d4b0,
     [('string', 0x41b8a0, 'HtmlWindow'), ('string', 0x41bb70, 'HtmlService'), ('string', 0x41c9c0, 'WindowService'),
      ('string', 0x41d0a0, 'The object to bind to must not be nil')],
     [('vt', 0x419d10, '.?AV?$sp_counted_impl_pd@PAVDHTMLWindowService@@'), ('vt', 0x41b1e0, '.?AVMarshaller@@'),
      ('vt', 0x41ceb0, '.?AVCreator@?$FactoryProduct@VDHTMLWindowService@@'),
      ('vt', 0x41c610, '.?AV?$BoundFuncDesc@VDHTMLWindow@@')]),
    ('rbx content-url helper run and shared COMDAT helpers', 0x41d4b0, 0x41dd60,
     [('string', 0x41d760, '?filename='), ('string', 0x41d760, 'Empty!!!')], []),
    ('rbx insert-verb unit (InsertDecal / InsertTexture / InsertObject / InsertService; Name / Creatable instances of '
     'Decal, Texture, Part, SpecialShape, ContentProvider)', 0x41dd60, 0x41f9c0,
     [('string', 0x41de20, 'Decal'), ('string', 0x41df70, 'SpecialMesh'), ('string', 0x41dfe0, 'ContentProvider'),
      ('string', 0x41f2e0, 'Insert Object'), ('string', 0x41f310, 'Insert Service'),
      ('string', 0x41f3c0, 'InsertService')],
     [('vt', 0x41e650, '.?AVInsertDecal@@'), ('vt', 0x41e670, '.?AVInsertTexture@@'),
      ('vt', 0x41f680, '.?AVInsertObject@@'), ('vt', 0x41f3c0, '.?AVInsertService@@'),
      ('vt', 0x41e720, '.?AVCreator@?$FactoryProduct@VDecal@RBX@@'),
      ('vt', 0x41ecb0, '.?AVCreator@?$FactoryProduct@VSpecialShape@RBX@@')]),
    ('rbx CInsertObjectDialog / CListCtrl unit (AbstractFactoryProduct / vector<shared_ptr<Instance>> COMDATs)',
     0x41f9c0, 0x420780,
     [('string', 0x41fa30, 'DataModel')],
     [('vt', 0x41f9c0, '.?AVCInsertObjectDialog@@'), ('vt', 0x41fa10, '.?AVCListCtrl@@'),
      ('vt', 0x420580, '.?AVCInsertObjectDialog@@')]),
    ('rbx CInstanceExplorer unit (CInstanceRecord::CNameItem, MarshaledListener<Instance, Descendant*>, MFC '
     'CImageList / CMenu inline COMDATs, CRT / STL helpers)', 0x420780, 0x422620,
     [('string', 0x420990, 'Name'), ('string', 0x421ed0, 'ImageList_BeginDrag')],
     [('vt', 0x420780, '.?AVCInstanceExplorer@@'), ('vt', 0x420790, '.?AVCNameItem@CInstanceRecord@@'),
      ('vt', 0x421530, '.?AVEventData@?$MarshaledListener@VInstance@RBX@@'),
      ('vt', 0x421c90, '.?AVCInstanceExplorer@@')]),
    ('rbx CRobloxTreeCtrl / CSelectionTreeCtrl / RootNode unit (continues past the range)', 0x422620, HI,
     [('string', 0x423e30, 'map/set<T> too long')],
     [('vt', 0x422630, '.?AVCRobloxTreeCtrl@@'), ('vt', 0x422640, '.?AVCSelectionTreeCtrl@@'),
      ('vt', 0x4226a0, '.?AVRootNode@@'), ('vt', 0x422700, '.?AVCEnabledCmdUI@@')]),
]
range_rows = sorted(a for a in FUNCTIONS if LO <= a < HI)
for a in range_rows:
    assert sum(lo <= a < hi for _, lo, hi, _, _ in BLOCKS) == 1, hex(a)
for name, lo, hi, strings, vts in BLOCKS:
    for _, a, text in strings:
        assert lo <= a < hi and holds_string(a, text), (name, hex(a), text)
    for _, a, prefix in vts:
        assert lo <= a < hi and in_vtable(a, prefix), (name, hex(a), prefix)
# 0041db00 (the "?filename=" helper's caller) is reached from the CApp ATL unit (00406a80)
assert '00406a80' in FUNCTIONS[0x41db00]['callers']

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
    return 'RBX / MFC / unnamed (%s)' % blk


OPEN_CATEGORIES = {}
for a in open_rows:
    OPEN_CATEGORIES.setdefault(category(int(a, 16)), []).append('%#x' % int(a, 16))

UNIT_MAP = {
    'rbx CLuaFunction ATL COM unit ..0x419d0f (starts below the range; app-unit40c maps its head 0x417850..)': (
        'CComObject / CComContainedObject / CComAggObject<CLuaFunction> slots and QueryInterface / AddRef / Release '
        'thunks (vtables 0x80ebd8 / 0x80ec58 / 0x80ec9c; 0x418880 / 0x418950 are CComAggObject slots 0/3, 0x419080.. '
        'CComObject slots 4..6), the ATL window-class / thunk helpers (RegisterClassExA 0x418580, GetClassInfoExA '
        '0x418ab0, FlushInstructionCache 0x4189d0, SetWindowLongA 0x418970) and std::string / type_info COMDATs. Not '
        'recovered here: CLuaFunction is a WindowsClient ATL COM class with no native header; the ATL rows are library '
        'header code.'),
    'rbx DHTMLWindowService / Marshaller / DHTMLWindow descriptor unit 0x419d10..0x41d4af': (
        'sp_counted_impl_pd<DHTMLWindowService*> slots (vtable 0x80ee10), boost any holder / function / signals slot '
        'COMDATs (0x41a5f0..0x41b170), the Marshaller (vtable 0x80eccc, CMarshalWindow proc 0x41a2d0; app-leaves2008), '
        'DHTMLWindow BoundFuncDesc / SignalDesc descriptors (vtables 0x80ef00..0x80ef40; app-leaves2008-dhtml), '
        'DHTMLWindowService FactoryProduct / DescribedCreatable rows and its constructor 0x41c9c0 '
        '(app-leaves2008-services), Bind 0x41d0a0 ("The object to bind to must not be nil"), and the Creatable '
        'instances shared_count 0x41ba00 (creatable-shared-count), shared_ptr 0x41baa0, create 0x41cda0 and Creator '
        '0x41ceb0 (built and counted here). Still open: the function0 / bind_t COMDATs 0x41cf60 / 0x41cff0 / 0x41d310, '
        'the SignalDesc slot 0x41d3d0 and the ATL / boost helpers listed under range_rows_open.'),
    'rbx content-url helper run 0x41d4b0..0x41dd5f': (
        '0x41d760 builds a "?filename=" url and logs "Empty!!!"; it and the vector<string> helpers 0x41d570 / '
        '0x41d6d0 are reached only through 0x41db00, whose caller is the CApp ATL unit 0x406a80 (app-unit400 map). '
        '0x41d4b0 / 0x41d500 (_Allocate<std::string>) / 0x41dcb0..0x41dd40 are COMDAT helpers shared with other units. '
        'Owner class not derived (no vtable / RTTI); not recovered.'),
    'rbx insert-verb unit 0x41dd60..0x41f9bf': (
        'InsertDecal (vtable 0x80f15c: ctor 0x41dd60 via Verb ctor 0x57e730, slots 2/4/5 0x41f280 / 0x41f040 / '
        '0x41e650), InsertTexture (vtable 0x817324, slot 5 0x41e670), InsertObject ("Insert Object" 0x41f2e0, vtable '
        '0x80f204, doIt 0x41f680 "InsertObject: Target Instance is NULL"), InsertService ("Insert Service" 0x41f310, '
        'vtable 0x80f22c, 0x41f3c0 "ClassName"/"InsertService"), Instance::canAddChild / canSetParent / '
        'getClassNameStr inline COMDATs 0x41f2b0..0x41f390; Name::doDeclare 0x41de20 Decal, 0x41de90 Texture, 0x41df00 '
        'Part, 0x41df70 SpecialMesh (special-shape), 0x41dfe0 ContentProvider, callDoDeclare 0x41e0b0..0x41e0f0 '
        '(0x41e0b0 / 0x41e0c0 counted by app-unit594, 0x41e0e0 by special-shape), the ServiceProvider::create<'
        'ContentProvider> COMDATs 0x41e050 / 0x41e220 / 0x41ed60 / 0x41eea0 / 0x41ef90, and the Creatable runs of Decal '
        '0x41e100.., Texture 0x41e190.., ContentProvider 0x41e230.., PartInstance 0x41e880.. and SpecialShape '
        '0x41eaf0.. (shared_count rows counted by creatable-shared-count; create<Decal> 0x41e4d0, create<Texture> '
        '0x41e550, doDeclare 0x41de20 / 0x41de90 and the createInstance wrappers 0x41e650 / 0x41e670 are marked exact '
        'by the decal / document-initialize trial receipts and are only bound here; the other shared_ptr / create / '
        'Creator / Name rows are built and counted here, except create<PartInstance> and its Creator, see not_exact). '
        'Not recovered: the verb classes themselves (no native Verb / InsertDecal declarations; the '
        'Verb base ctor 0x57e730 and the CRobloxDoc-side insert dialogs are other owners).'),
    'rbx CInsertObjectDialog / CListCtrl unit 0x41f9c0..0x42077f': (
        'CInsertObjectDialog (vtable 0x80f48c) and CListCtrl (0x80f304) members, Name compare 0x41faa0, '
        'AbstractFactoryProduct<Instance>::create(const Name&) 0x420190, shared_dynamic_cast / vector<shared_ptr<'
        'Instance>> COMDATs, addClasses 0x4202b0 and RaiseRange::removeIndex 0x420740 (evidence names). Owned by the '
        'insert-object-dialog receipt; not recovered here.'),
    'rbx CInstanceExplorer unit 0x420780..0x42261f': (
        'CInstanceExplorer (vtable 0x80f8c4 and its Listener sub-vtables 0x80f898 / 0x80f8ac), CInstanceRecord '
        '(0x80f7e4) and CInstanceRecord::CNameItem (0x80f65c; CXTPReportRecordItem inline slots 0x4207c0..0x420980), '
        'MarshaledListener<Instance, DescendantAdded / DescendantRemoving> and their EventData (0x80f84c / 0x80f86c / '
        '0x80f880 / 0x80f88c), the MFC CImageList drag wrappers 0x421ed0..0x422513 and CMenu 0x422550, CRT / STL '
        'helpers 0x420a80..0x420bd0 (HeapSetInformation probe, _Allocate). Owned by instance-explorer; not recovered '
        'here.'),
    'rbx CRobloxTreeCtrl / CSelectionTreeCtrl / RootNode unit 0x422620..0x424000 (continues past the range)': (
        'CRobloxTreeCtrl (0x80fcd4), CSelectionTreeCtrl (0x80fed4 / 0x80fe4c), RootNode (0x810060), CEnabledCmdUI '
        '(0x80fbfc), CXTTreeCtrl / CXTTreeView inline slots, Instance::isDescendentOf 0x422ae0, ~SelectionChanged '
        '0x422c60 and the std::set<WeakReferenceCountedPointer<Chunk>> / set<Script*> _Tree COMDATs. Owned by '
        'roblox-tree-ctrl / selection-tree-ctrl; not recovered here.'),
    'library code': (
        'No separately compiled library unit starts in the range. ATL (CComObject / window thunks), MFC (CImageList, '
        'CMenu, CListCtrl inline), XTP (CXTTreeCtrl, CXTPReportRecordItem inline), STL and boost rows are header '
        'instances inside the units above and are not recovered.'),
    'excluded': (
        'No CRobloxApp / CMainFrame / CRobloxDoc / CRobloxView vtable slot or constructor lies in the range; the '
        'content-url run 0x41d4b0.. is reached from the CApp ATL unit (not CRobloxApp) and is left open.'),
}
NOT_EXACT = {
    '0x41e9c0 create<PartInstance>': (
        'not exact: it mallocs 0x404 and the native v8datamodel/PartInstance.h compiles to sizeof 0x2ec (the fields '
        'between the embedded Primitive +0x228..+0x324 and 0x404 are not derived); every other byte matches. Not '
        'counted.'),
    '0x41ea40 PartInstance Creator::create (slot 0 of the one-slot Creator vtable 0x80f1c4)': (
        'byte-exact with its targets bound, but it calls the non-exact create<PartInstance> 0x41e9c0; not counted '
        'until that row is exact.'),
}
REJECTED = {}
PROPOSALS = {
    'v8datamodel/PartInstance.h (owner)': (
        'sizeof(PartInstance) is 0x404 in 2008-06 (create<PartInstance> 0x41e9c0 pushes 0x404 to malloc and calls '
        'PartInstance() 0x59d4d0, whose ret 4 pops the virtual-base flag 1). The current header compiles to 0x2ec. '
        'Once the remaining fields are derived from the constructor 0x59d4d0 / destructor 0x59b970, create<'
        'PartInstance> 0x41e9c0 and its Creator 0x41ea40 (vtable 0x80f1c4) become countable here; no field is '
        'proposed without that evidence.'),
    'util/Object.h (core owner, FYI, no edit needed)': (
        'FactoryProduct<C,D,N>::Creator::create() const is declared without a body; AppUnit418_2008Creators.cpp '
        'repeats the out-of-class definition `return Creatable<Instance>::create<Class>();` used by app-unit400 / '
        '40c / 4b0 / 48c / 5bc. It makes the DHTMLWindowService Creator 0x41ceb0 (listed as not attempted by '
        'app-leaves2008-dhtml / -services) and the Decal / Texture / PartInstance / SpecialShape Creators exact. A '
        'shared definitions header could replace these copies.'),
    'mangling FYI (no row here depends on it)': (
        'the original Creator RTTI of Decal (0x80f1b4), Texture (0x80f1bc), PartInstance (0x80f1c4), SpecialShape '
        '(0x80f1e0) and DHTMLWindowService (0x80ed48) is read back into the receipt; normalisation of 3QBDB / 3PADA '
        'is symbol-only.'),
}

paths = [Path(__file__).resolve()] + list(SOURCES.values()) + HEADERS
receipt = {
    'class': 'RBX Creatable / Name template instances of the application range 00418000..00424000 (2008-06), inactive',
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
    'built_not_counted': [{'row': '%#x (not counted, exact=false)' % int(r['address'], 16), 'symbol': r['symbol'],
                           'exact': False, 'body_exact': r['exact'], 'verified_targets': r['verified_targets']}
                          for r in not_counted],
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
print('PASS app-unit418-2008: %d counted exact rows (%s); %d range rows, %d counted elsewhere, %d open; %d Creator '
      'vtables checked' % (len(exact_rows), ' '.join(exact_rows), len(range_rows), len(range_counted), len(open_rows),
                           len(creator_vtables)))
