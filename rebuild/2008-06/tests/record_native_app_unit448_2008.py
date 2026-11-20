"""Verify the inactive 2008-06 native rows of the application range 00448000..00454000 and record its unit map.

Unit map (boundary evidence in the receipt's `unit_map`, checked below; rows counted by other receipts are listed as
'ADDR counted by RECEIPT' text, never as a quoted bare address):
  * 00448000..0044945f  the CRenderSettings unit (RenderSettings.cpp, render-settings-working.json counts most rows).
  * 00449460..0044ddcf  the CRobloxApp unit (RobloxApp.cpp): CRobloxApp, CRbxDocTemplate / CRbxPlayDocTemplate,
    CIDEDocManager / CBrowserDocManager, CRobloxModule, CRobloxCommandLineInfo, ErrorUploader and the GameSettings
    template instances. CRobloxApp is a maintainer exclusion; only two RBX template instances are built here.
  * 0044ddd0..0044ee7f  the CRobloxControlColorSelector unit (roblox-control-color-selector-working.json).
  * 0044ee80..0044f16f  the CRobloxDHtmlDialog unit.
  * 0044f170..0044f19f  three 8-byte `push k; call 00554da0` helpers referenced only by dynamic initializers.
  * 0044f1a0..00454000  the CRobloxDoc unit (RobloxDoc.cpp, continuing past 00454000; maintainer exclusion): its
    RBX ServiceProvider / Name / Creatable / FactoryProduct instances are built here.

Build (VS2008 RTM 21022, document-swap flags): native-classes/AppUnit448_2008Services.cpp against the committed
native headers only (read-only; no pending build, no new header, no shadowing). Every counted row is relocation-masked
exact against the original and every REL32/DIR32 target is bound to the address the original instruction uses and
verified, one address per symbol over all rows: imports by DLL export name, vtables by the original complete-object
locator class, own rows by their row address, the class-name array by its original bytes, rows counted by other
receipts by that receipt's symbol (and the compiled body must be exact there), open rows by identity, functions by
evidence name, static locals by consistency (.data / .bss, one address each). Each Creator::create row is slot 0 of the
original Creator vtable whose RTTI names the class. A row is counted only when no other receipt counts it.
Writes work/2008-06/shared-layouts/app-unit448-2008-working.json.
"""
import glob
import json
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
OUT = R / 'out/app-unit448-2008'
OUT.mkdir(parents=True, exist_ok=True)
UNIT = R / 'native-classes/AppUnit448_2008Services.cpp'
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit448-2008-working.json'
LO, HI = 0x448000, 0x454000


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags() + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


OBJ, FLAGS = build('AppUnit448_2008Services', UNIT)
original = nb.Original()
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
FUNCTIONS = {}
for line in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines():
    x = json.loads(line)
    FUNCTIONS[int(x['addr'], 16)] = x
DATA_SECTIONS = [(original.image + s.VirtualAddress, original.image + s.VirtualAddress + s.Misc_VirtualSize)
                 for s in original.pe.sections if s.Name.rstrip(b'\0') in (b'.data', b'.rdata')]
TEXT = [(original.image + s.VirtualAddress, original.image + s.VirtualAddress + s.Misc_VirtualSize)
        for s in original.pe.sections if s.Name.rstrip(b'\0') == b'.text'][0]


def norm(s):
    return s.replace('3QBDB', '3PBDB')


# ---- rows --------------------------------------------------------------------------------------------------------
SP = '@ServiceProvider@RBX@@'
CI = '?$Creatable@VInstance@RBX@@@'
DEL = 'VDeleter@' + CI
# class -> (C mangled, doGetClassIndex, callDoGetClassIndex, find() const (open), create() const or None,
#           Creatable<Instance>::create<C>, its receipt or None, class-name doDeclare callee of find, declared name)
SERVICES = {
    'ChangeHistoryService': ('VChangeHistoryService@RBX@@', 0x44f360, 0x450850, 0x452a00, 0x453000, 0x4150d0,
                             'app-unit40c-2008-working.json', 0x4137a0, 'ChangeHistoryService'),
    'RunService': ('VRunService@RBX@@', 0x44f3c0, 0x450860, 0x452c80, 0x4530f0, 0x405fa0,
                   'app-unit400-2008-working.json', 0x401a00, 'RunService'),
    'SoundService': ('VSoundService@Soundscape@RBX@@', 0x44f420, 0x450870, 0x452dc0, 0x4531e0, 0x440980, None,
                     0x437f20, 'SoundService'),
    'Visit': ('VVisit@RBX@@', 0x44f4a0, 0x450880, 0x452b40, None, None, None, 0x44f2f0, 'Visit'),
}


ROWS = []
FIND = {}           # find<C>() const: open rows (not exact, see NOT_EXACT), bound by identity from create<C>() const
for c, (m, do, call, fnd, cre, cc, ccr, decl, text) in SERVICES.items():
    short = m[1:m.index('@')]
    ns = m[1 + len(short) + 1:-2]  # 'RBX' or 'Soundscape@RBX'
    ROWS.append((do, '??$doGetClassIndex@%s@ServiceProvider@RBX@@SAIXZ' % m))
    ROWS.append((call, '??$callDoGetClassIndex@%s@ServiceProvider@RBX@@SAXXZ' % m))
    ret = 'PAV%s@%s@XZ' % (short, '1' if ns == 'RBX' else 'Soundscape@1')
    FIND['??$find@%s%sQBE%s' % (m, SP, ret)] = (fnd, c)
    if cre:
        ROWS.append((cre, '??$create@%s%sQBE%s' % (m, SP, ret)))
ROWS += [
    (0x44f2f0, '??$doDeclare@$1?sVisit@RBX@@3PADA@Name@RBX@@CAABV01@XZ'),
    (0x450840, '??$callDoDeclare@$1?sVisit@RBX@@3PADA@Name@RBX@@CAXXZ'),
    (0x4528d0, '??$create@VVisit@RBX@@@%sRBX@@SA?AV?$shared_ptr@VVisit@RBX@@@boost@@XZ' % CI),
    (0x452820, '??$?0VVisit@RBX@@%s1@@?$shared_ptr@VVisit@RBX@@@boost@@QAE@PAVVisit@RBX@@%s3@@Z' % (DEL, DEL)),
    (0x452950, '?create@Creator@?$FactoryProduct@VVisit@RBX@@VInstance@2@$1?sVisit@2@3PADA@RBX@@UBE?AV?$shared_ptr@'
               'VObject@RBX@@@boost@@XZ'),
    (0x44a8c0, '??$?0PAVGameSettings@RBX@@%s1@@shared_count@detail@boost@@QAE@PAVGameSettings@RBX@@%s4@@Z' % (DEL, DEL)),
    (0x44d560, '?create@Creator@?$FactoryProduct@VGameSettings@RBX@@VItem@GlobalSettings@2@$1?sGameSettings@2@3QBDB@'
               'RBX@@UBE?AV?$shared_ptr@VObject@RBX@@@boost@@XZ'),
]
CREATORS = {  # Creator::create row -> (Creator vtable, RTTI the original locator must name)
    0x452950: (0x817e5c, '.?AVCreator@?$FactoryProduct@VVisit@RBX@@VInstance@2@$1?sVisit@2@3PADA@RBX@@'),
    0x44d560: (0x816db4, '.?AVCreator@?$FactoryProduct@VGameSettings@RBX@@VItem@GlobalSettings@2@$1?sGameSettings@2@'
                         '3QBDB@RBX@@'),
}

# Targets counted (with this symbol) by another receipt.
COUNTED_TARGETS = {
    '??$create@VChangeHistoryService@RBX@@@%sRBX@@SA?AV?$shared_ptr@VChangeHistoryService@RBX@@@boost@@XZ' % CI:
        (0x4150d0, 'app-unit40c-2008-working.json'),
    '??$create@VRunService@RBX@@@%sRBX@@SA?AV?$shared_ptr@VRunService@RBX@@@boost@@XZ' % CI:
        (0x405fa0, 'app-unit400-2008-working.json'),
    '??0Visit@RBX@@QAE@XZ': (0x5c5220, 'app-unit5bc-2008-working.json'),
    '??$create@VGameSettings@RBX@@@%sRBX@@SA?AV?$shared_ptr@VGameSettings@RBX@@@boost@@XZ' % CI:
        (0x44bdc0, 'settings-items-working.json'),
    '??$?0PAVVisit@RBX@@%s1@@shared_count@detail@boost@@QAE@PAVVisit@RBX@@%s4@@Z' % (DEL, DEL):
        (0x452790, 'creatable-shared-count-working.json'),
}
# Open targets outside the range that no receipt counts: identified by their compiled body (same object) being
# relocation-masked exact at the bound address.
HELPER_BODIES = {
    '??$create@VSoundService@Soundscape@RBX@@@%sRBX@@SA?AV?$shared_ptr@VSoundService@Soundscape@RBX@@@boost@@XZ' % CI:
        0x440980,
}
EXTERNAL = {
    '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330,                 # boost.thread call_once (thread library)
    '?newIndex@ServiceProvider@RBX@@SAIXZ': 0x572690,              # InterlockedIncrement; app-unit480 binds it the same
    '?declare@Name@RBX@@SAABV12@PBDH@Z': 0x553f90,                 # evidence name
    '?setParent@Instance@RBX@@QAEXPAV12@@Z': 0x55a8f0,             # evidence name
    '??4shared_count@detail@boost@@QAEAAV012@ABV012@@Z': 0x4025b0,  # evidence name
    '??RDeleter@?$Creatable@VInstance@RBX@@@RBX@@QAEXPAVInstance@2@@Z': 0x405e30,  # as creatable-shared-count binds it
}
STRINGS = {'?sVisit@RBX@@3PADA': 'Visit'}

BINDING = {}
UNBOUND = []
IDENTITY = {}


def bind(symbol, value, where):
    prev = BINDING.setdefault(symbol, (value, where))
    assert prev[0] == value, ('one address per symbol', symbol, hex(prev[0]), prev[1], hex(value), where)


def receipt_symbols(name, address):
    """Symbols another receipt records as counted exact at `address` (top-level exact_function_rows, else exact rows)."""
    data = json.loads((ROOT / 'work/2008-06/shared-layouts' / name).read_text())
    if 'exact_function_rows' in data and '%08x' % address not in [str(r) for r in data['exact_function_rows']]:
        return []
    found = []

    def walk(o):
        if isinstance(o, dict):
            if o.get('address') == '%08x' % address and o.get('symbol') and o.get('exact') is True:
                found.append(o['symbol'])
            for v in o.values():
                walk(v)
        elif isinstance(o, list):
            for v in o:
                walk(v)
    walk(data)
    return found


own = {s: a for a, s in ROWS}


def prove_find(symbol, value):
    """find<C>() const (open row of this range): the original pushes this receipt's callDoGetClassIndex<C> row for
    call_once, calls its doGetClassIndex<C> row and the Name::doDeclare instance that declares C's name."""
    _, c = FIND[symbol]
    m, do, call, fnd, cre, cc, ccr, decl, text = SERVICES[c]
    body, _, _ = match.target('2008-06', '%08x' % value)
    assert b'\x68' + struct.pack('<I', call) in body, (hex(value), hex(call))
    x = FUNCTIONS[value]
    assert '%08x' % do in x['call_targets'] and '%08x' % decl in x['call_targets'], (hex(value), x['call_targets'])
    assert FUNCTIONS[decl]['strings'] == [text], (hex(decl), FUNCTIONS[decl]['strings'])
    return ('open row of this range (not counted), identified by its call_once push of the callDoGetClassIndex row '
            '%#x, its call to the doGetClassIndex row %#x and to the doDeclare %#x of %r' % (call, do, decl, text))


def verify(obj, rows):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    out = []
    for address, name in rows:
        assert name in bodies, (hex(address), name)
        body, refs = bodies[name]
        target, target_refs, _ = match.target('2008-06', '%08x' % address)
        exact = match.exact_match(target, target_refs, body, refs)
        row = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target),
               'exact': bool(exact), 'verified_targets': {}, 'local_eh': []}
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
            elif symbol.startswith('??_7'):
                rtti, at = original.vtable_class(value)
                cls = symbol[4:symbol.index('@@6B') + 2]
                assert norm(rtti) == norm('.?AV' + cls), (where, symbol, hex(value), rtti)
                how = 'vtable RTTI %s offset %#x' % (rtti, at)
            elif symbol in STRINGS:
                text = STRINGS[symbol].encode() + b'\0'
                assert original.data(value, len(text)) == text, (where, symbol, hex(value))
                how = 'class-name array %r' % STRINGS[symbol]
            elif symbol in COUNTED_TARGETS:
                other, receipt = COUNTED_TARGETS[symbol]
                assert other == value, (where, symbol, hex(value), hex(other))
                assert symbol in receipt_symbols(receipt, value), (receipt, hex(value), symbol)
                if symbol in bodies:
                    hb, hr = bodies[symbol]
                    ht, htr, _ = match.target('2008-06', '%08x' % value)
                    assert match.exact_match(ht, htr, hb, hr), ('counted-elsewhere body not exact', symbol, hex(value))
                    how = 'row counted by %s with this symbol (compiled body exact there)' % receipt
                else:
                    how = 'row counted by %s with this symbol' % receipt
            elif symbol in FIND:
                assert FIND[symbol][0] == value, (where, symbol, hex(value))
                how = IDENTITY.setdefault(symbol, prove_find(symbol, value))
            elif symbol in HELPER_BODIES:
                assert HELPER_BODIES[symbol] == value, (where, symbol, hex(value))
                hb, hr = bodies[symbol]
                ht, htr, _ = match.target('2008-06', '%08x' % value)
                assert match.exact_match(ht, htr, hb, hr), (where, symbol, hex(value))
                assert not counted_at(value), (symbol, hex(value))
                how = 'open row outside the range (not counted): the compiled body is exact at the bound address'
            elif symbol in EXTERNAL:
                assert EXTERNAL[symbol] == value, (where, symbol, hex(value), hex(EXTERNAL[symbol]))
                how = 'external' + (' (evidence name)' if names.get(value, '') == symbol else '')
            elif symbol in definitions and symbol not in bodies:
                assert any(lo <= value < hi for lo, hi in DATA_SECTIONS), (where, symbol, hex(value))
                how = 'own static (bound by consistency)'
            if how is None:
                UNBOUND.append((where, symbol, hex(value), names.get(value, '')[:80]))
                continue
            bind(symbol, value, where)
            row['verified_targets'][symbol] = '%#x (%s)' % (value, how)
    return out


# ---- counting rules ------------------------------------------------------------------------------------------------
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
                out.setdefault(int(m.group(1), 16), set()).add(Path(path).name)
    return out


ELSEWHERE = counted_elsewhere()


def counted_at(address):
    return sorted(ELSEWHERE.get(address, ()))


rows = verify(OBJ, ROWS)
find_rows = verify(OBJ, sorted((a, s) for s, (a, _) in FIND.items()))
assert not UNBOUND, UNBOUND
assert all(r['exact'] for r in rows), [(r['address'], r['size'], r['target_size']) for r in rows if not r['exact']]
assert not any(r['exact'] for r in find_rows), 'find<C>() const became exact: count it'
for r in find_rows:  # never a quoted bare address for a row this receipt does not count
    r['address'] = '%s (open, not counted)' % r['address']

# ---- Creator vtables (original): slot 0 is the counted Creator::create row; the RTTI names the class ---------------
creator_vtables = []
for row_address, (vt, want) in CREATORS.items():
    rtti, at = original.vtable_class(vt)
    assert (rtti, at) == (want, 0), (hex(vt), rtti, at)
    assert d(vt) == row_address, (hex(vt), hex(d(vt)))
    slots = 0
    while TEXT[0] <= d(vt + 4 * slots) < TEXT[1]:
        slots += 1
    assert slots == 1, (hex(vt), slots)
    creator_vtables.append({'vtable': 'vtable %s' % hex(vt), 'rtti': rtti, 'original_slots': slots,
                            'slot0': '%s (Creator::create row)' % hex(row_address)})

# sizeof(Visit): the malloc size create<Visit> 004528d0 passes equals the native Visit.h layout (exact body).
_body, _, _ = match.target('2008-06', '004528d0')
assert b'\x68\x50\x01\x00\x00' in _body
SIZES = {'Visit': 'sizeof 0x150 (malloc 0x150 in the exact create<Visit> 0x4528d0; native v8datamodel/Visit.h)',
         'Soundscape::SoundService': 'sizeof 0x1c8 (malloc 0x1c8 in create<SoundService> 0x440980, exact from the '
                                     'native util/Sound.h; open row outside the range)'}
_body, _, _ = match.target('2008-06', '00440980')
assert b'\x68\xc8\x01\x00\x00' in _body


# ---- unit map evidence -------------------------------------------------------------------------------------------
def holds_string(address, text):
    """The row's bytes hold a DIR32 pointer to that exact NUL-terminated string."""
    x = FUNCTIONS[address]
    body = original.data(address, x['size'])
    for i in range(len(body) - 3):
        v = struct.unpack_from('<I', body, i)[0]
        if any(lo <= v < hi for lo, hi in DATA_SECTIONS):
            try:
                if original.string(v) == text:
                    return True
            except Exception:
                pass
    return False


def slot_of(address, vt, slot, rtti, offset=0):
    got, at = original.vtable_class(vt)
    return d(vt + 4 * slot) == address and got == rtti and at == offset


BLOCKS = [
    ('render-settings', LO, 0x449460, [('string', 0x448120, 'RenderSettings'), ('string', 0x448c60, 'Rendering'),
                                       ('slot', 0x448de0, 0x81634c, 0, '.?AVCRenderSettings@@', 0x14)]),
    ('robloxapp', 0x449460, 0x44ddd0, [('string', 0x4495a0, 'ROBLOX-ATOM'), ('string', 0x44ad60, 'ROBLOX ExitInstance'),
                                       ('string', 0x44d810, 'ROBLOX InitInstance'),
                                       ('slot', 0x44ad60, 0x816a64, 28, '.?AVCRobloxApp@@'),
                                       ('slot', 0x44be40, 0x816a28, 0, '.?AVCRobloxModule@@'),
                                       ('slot', 0x44d560, 0x816db4, 0, None)]),
    ('color-selector', 0x44ddd0, 0x44ee80, [('slot', 0x44ddd0, 0x816e74, 0, '.?AVCRobloxControlColorSelector@@'),
                                            ('slot', 0x44ee50, 0x816e74, 81, '.?AVCRobloxControlColorSelector@@')]),
    ('dhtml-dialog', 0x44ee80, 0x44f170, [('slot', 0x44ee90, 0x8170bc, 0, '.?AVCRobloxDHtmlDialog@@'),
                                          ('slot', 0x44f0a0, 0x8170bc, 1, '.?AVCRobloxDHtmlDialog@@'),
                                          ('string', 0x44f0c0, 'DialogResult')]),
    ('initializer-helpers', 0x44f170, 0x44f1a0, []),
    ('robloxdoc', 0x44f1a0, HI, [('slot', 0x44f200, 0x817ce4, 0, '.?AVCRobloxDoc@@'),
                                 ('slot', 0x452f60, 0x817ce4, 30, '.?AVCRobloxDoc@@'),
                                 ('string', 0x44f2f0, 'Visit'), ('string', 0x451b60, 'ReportAbuse'),
                                 ('slot', 0x452950, 0x817e5c, 0, None)]),
]
range_rows = sorted(a for a, x in FUNCTIONS.items() if LO <= a < HI and x.get('kind', 'code') == 'code')
for a in range_rows:
    assert sum(lo <= a < hi for _, lo, hi, _ in BLOCKS) == 1, hex(a)
for name, lo, hi, ev in BLOCKS:
    for e in ev:
        assert lo <= e[1] < hi, (name, e)
        if e[0] == 'string':
            assert holds_string(e[1], e[2]), (name, e)
        else:
            _, a, vt, slot, rtti = e[:5]
            want = rtti or original.vtable_class(vt)[0]
            assert slot_of(a, vt, slot, want, *e[5:]), (name, e)
# the three helpers 0044f170 / 0044f180 / 0044f190: `push k; call 00554da0; ret`, referenced only by the dynamic
# initializers at 007f285b / 007f288b / 007f28bb
for a, k in ((0x44f170, 1), (0x44f180, 2), (0x44f190, 0)):
    assert original.data(a, 8) == bytes([0x6a, k, 0xe8]) + struct.pack('<i', 0x554da0 - (a + 7)) + b'\xc3'

UNIT_MAP = {
    'render-settings 00448000..0044945f': (
        'CRenderSettings unit (RenderSettings.cpp): the GlobalSettingsItem<CRenderSettings> singleton ("RenderSettings", '
        '"singleton %s already exists"), the EnumPropDescriptor<CRenderSettings, GraphicsMode / FrameRateManagerMode / '
        'BevelMode / ShadowMode / AntialiasingMode / AASamples> virtuals (vtables 008160fc..0081628c), EnumDescriptor '
        'equalValue / isValue instances, the CRenderSettings thunks (vtables 008162e4..00816354) and the "Rendering" '
        'category descriptors; render-settings-working.json counts its rows (its recorder is a baseline failure: '
        'sRenderSettings 3PADA vs the RTTI 3QBDB). Other owner; not recovered here.'),
    'robloxapp 00449460..0044ddcf': (
        'CRobloxApp unit (RobloxApp.cpp; strings "ROBLOX-ATOM", "ROBLOX ExitInstance", "ROBLOX InitInstance", '
        '"/Game/MachineConfiguration.ashx", "AppSettings.xml"; vtables CRobloxApp 00816a64, CRobloxModule 00816a28, '
        'CRobloxCommandLineInfo 00816a44, CRbxDocTemplate 00816684, CRbxPlayDocTemplate 0081671c, CIDEDocManager '
        '0081685c, CBrowserDocManager 0081663c, sp_counted_impl_p<ErrorUploader::data> 00816900). CRobloxApp and its '
        'helpers are a maintainer exclusion (mapped, not recovered); the std::ostream inserters 0044a450 / 0044a640 '
        'are STL instances. Built here: the RBX template instances shared_count(GameSettings*, Deleter) and '
        'FactoryProduct<GameSettings>::Creator::create (Creator vtable 00816db4); the GameSettings doDeclare / '
        'callDoDeclare / create / shared_ptr / singleton rows are counted by settings-items-working.json.'),
    'color-selector 0044ddd0..0044ee7f': (
        'CRobloxControlColorSelector unit (vtables 00816e74 / 00816e14), counted by roblox-control-color-selector-'
        'working.json; 0044ed40 / 0044ed50 / 0044ed80 / 0044edb0 / 0044edc0 are ICF-folded XTP CXTPControl inline '
        'virtuals shared by many XTP vtables (library header code, not recovered).'),
    'dhtml-dialog 0044ee80..0044f16f': (
        'CRobloxDHtmlDialog unit (vtable 008170bc slots 0 / 1 / 17 / 86 shared by CPublishAsPlaceDialog / '
        'CUploadPlaceDialog / CSaveModelToRobloxDialog / CSaveToRobloxDialog, "DialogResult"); app class of another '
        'owner (native-headers/CRobloxDHtmlDialog.h), not recovered here.'),
    'initializer-helpers 0044f170..0044f19f': (
        'three 8-byte `push k; call 00554da0; ret` helpers (k = 1, 2, 0) referenced only by the dynamic initializers '
        'at 007f285b / 007f288b / 007f28bb; the callee and the unit are not derived. Open.'),
    'robloxdoc 0044f1a0..00454000': (
        'CRobloxDoc unit (RobloxDoc.cpp, continuing past 00454000): CRobloxDoc vtable 00817ce4, VerbBinder<CRobloxDoc, '
        'CDocument> 00817c24, ReportAbuseVerb 008172e0, ExitCommand 00817304, the camera command dtor 00451170 shared '
        'by the RBX camera command vtables, the upload / visit / play command bodies ("/IDE/Upload.aspx", '
        '"/game/visit.ashx", "ReportAbuse") and std::map / _Tree instances. CRobloxDoc is a maintainer exclusion. '
        'Built here: the RBX ServiceProvider instances for ChangeHistoryService / RunService / Soundscape::SoundService '
        '/ Visit (doGetClassIndex, callDoGetClassIndex, find (open), create), Name::doDeclare / callDoDeclare<sVisit>, '
        'Creatable<Instance>::create<Visit>, shared_ptr<Visit>(Visit*, Deleter) and FactoryProduct<Visit>::Creator::'
        'create; 00452790 shared_count<Visit*> is counted by creatable-shared-count-working.json.'),
}
NOT_EXACT = {
    '0x452a00 / 0x452b40 / 0x452c80 / 0x452dc0 ServiceProvider::find<C>() const (320 B)': (
        'the native boost shared_ptr<Instance> destructor is inlined there (404 B); the original calls it out of line '
        'at 0x600660 (same blocker as app-unit48c find<C>; only a generated noinline-destructor profile matched it). '
        'Open; the counted create<C>() const rows bind them by identity.'),
    '0x44f1b0 Visit::getUploadUrl()': (
        'an inline Visit.h member emitted in this unit; nothing a native unit of this range may build references it '
        '(its callers are CRobloxDoc 0x455060 and the Visit.cpp descriptor initializer 0x7f5bd0 of app-unit5bc), and no '
        'helper may be added to force it. Candidate for the app-unit5bc owner (the GetUploadUrl BoundFuncDesc there '
        'takes its address).'),
    '0x44f170 / 0x44f180 / 0x44f190': 'initializer helpers; callee 0x554da0 and owner not derived; open.',
}
REJECTED = {
    '/fp:fast for AppUnit448_2008Services.cpp': 'no effect: the same exact set and the same 404-byte find<C>; dropped.',
}

exact_rows = sorted(r['address'] for r in rows)
double = {a: counted_at(int(a, 16)) for a in exact_rows if counted_at(int(a, 16))}
assert not double, double
range_counted = ['%08x counted by %s' % (a, ', '.join(counted_at(a))) for a in range_rows if counted_at(a)]

paths = [Path(__file__).resolve(), UNIT]
receipt = {
    'class': 'RBX rows of the application range 00448000..00454000 (2008-06), inactive',
    'compiler': 'VS2008 RTM 21022',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): nb.sha(p) for p in paths},
    'headers_read_only': ['v8tree/Service.h', 'util/Object.h', 'util/Name.h', 'v8datamodel/ChangeHistoryService.h',
                          'util/RunStateOwner.h', 'util/Sound.h', 'v8datamodel/Visit.h', 'v8datamodel/GameSettings.h'],
    'objects': {OBJ.name: nb.sha(OBJ)},
    'unit_map': UNIT_MAP,
    'range_rows': len(range_rows),
    'range_rows_counted_by_other_receipts': range_counted,
    'rows': rows,
    'open_find_rows': find_rows,
    'creator_vtables': creator_vtables,
    'sizes': SIZES,
    'not_exact': NOT_EXACT,
    'rejected': REJECTED,
    'proposals': [],
    'exact_function_rows': exact_rows,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit448-2008: %d counted exact rows (%s); %d of %d range rows counted by other receipts; find<C> open'
      % (len(exact_rows), ' '.join(exact_rows), len(range_counted), len(range_rows)))
