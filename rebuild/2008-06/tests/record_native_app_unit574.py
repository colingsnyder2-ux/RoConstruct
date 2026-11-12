"""Verify the inactive 2008-06 native rows of the application range 00574000..00578000 and record its unit map.

Unit map (boundary evidence in the receipt's `unit_map` / `unit_blocks`, checked below; rows counted by other receipts
are listed as 'ADDR counted by RECEIPT' text, never as a quoted bare address):
  * gui/GUI.cpp tail 00574000..00574f0c (the unit starts at 00573130, app-unit570 map): TopMenuBar::render2d / process,
    the ICF-shared Widget ??_E / ??_G thunks (widget-family support rows), UnifiedWidget members, TextDisplay
    (constructor, getFontSize / getLabel, ??_E thunks, ~TextDisplay + ??_G) and GuiItem::onDescendentRemoving /
    processNonFocus / process.
  * v8datamodel/DataModel.cpp 00574f10..00578000 (continues to 0057c1af, app-unit578 / app-unit57c maps).
  No separately compiled library unit starts in the range; the boost / STL rows are header instances.

Builds (VS2008 RTM 21022, document-swap flags, /fp:fast), current native headers only (read-only, no new header):
  * native-classes/AppUnit574Creators.cpp     shared_ptr<C>(C*, Deleter) / create<C> instances of Workspace,
                                                   GuiRoot and LocalBackpack; doGetClassIndex / callDoGetClassIndex
                                                   <LocalBackpack>;
  * native-classes/AppUnit574Notifiers.cpp    Notifier<Workspace, DrawChanged>::raise(DrawChanged);
  * native-classes/AppUnit574TextDisplay.cpp  TextDisplay(name, text), getFontSize, getLabel (and the implicit
                                                   ~TextDisplay / ??_G / ??_E thunks its vtables reference);
  * the committed native-classes/GuiItem.cpp, DataModelTiming.cpp, DataModelDutyCycle.cpp and DataModelLock.cpp
    (owners, compiled unchanged, read-only): their probe receipts (gui-item-working-probe.json,
    datamodel-timing-working.json, datamodel-lock-working-probe.json) record these rows without counting them; the
    exact ones are counted here.

Every relocation of a counted row is resolved to the address the original instruction uses and verified, one address
per symbol over all rows: imports by DLL export name, type descriptors and vtables by original RTTI, own rows by their
row address, rows counted by other receipts by that receipt (and the compiled body must be exact there), externals by
evidence name or by an identity proof recorded in the receipt, compiled helper bodies by an exact body at the bound
address (never counted). The TextDisplay vtables of the current-header object are matched slot by slot to the
original vtables (RTTI, COL subobject offset, slot count, bound slots).
Writes work/2008-06/shared-layouts/app-unit574-working.json.
Set NATIVE_APP_UNIT574_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
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
OUT = R / 'out/app-unit574'
OUT.mkdir(parents=True, exist_ok=True)
SOURCES = {
    'creators': R / 'native-classes/AppUnit574Creators.cpp',
    'notifiers': R / 'native-classes/AppUnit574Notifiers.cpp',
    'lock': R / 'native-classes/DataModelLock.cpp',           # owner, read-only
    'textdisplay': R / 'native-classes/AppUnit574TextDisplay.cpp',
    'guiitem': R / 'native-classes/GuiItem.cpp',             # owner, read-only
    'timing': R / 'native-classes/DataModelTiming.cpp',      # owner, read-only
    'duty': R / 'native-classes/DataModelDutyCycle.cpp',     # owner, read-only
}
HEADERS = [R / 'native-headers' / h for h in (
    'util/Object.h', 'util/Events.h', 'v8tree/Service.h', 'LocalBackpack2008/LocalBackpack2008.h',
    'v8datamodel/Workspace.h', 'v8datamodel/DataModel.h', 'gui/Gui.h', 'util/RunStateOwner.h')]
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit574-working.json'
LO, HI = 0x574000, 0x578000
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT574_DISCOVER'))


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags() + ['/fp:fast'] + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log[-4000:]
    return obj, flags


OBJ, FLAGS = {}, {}
for _k, _src in SOURCES.items():
    OBJ[_k], FLAGS[_k] = build('AppUnit574' + _k, _src)

original = nb.Original()
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
FUNCTIONS = {}
for line in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines():
    x = json.loads(line)
    FUNCTIONS[int(x['addr'], 16)] = x


def norm(s):
    return s.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


def target_of(address):
    body, refs, _ = match.target('2008-06', '%08x' % address)
    return body, refs


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
CI = '?$Creatable@VInstance@RBX@@@RBX@@'
DEL = 'VDeleter@?$Creatable@VInstance@RBX@@@1@@'
ROW_SPECS = {
    'creators': [
        (0x575630, '??$doGetClassIndex@VLocalBackpack@RBX@@@ServiceProvider@RBX@@SAIXZ'),
        (0x576800, '??$callDoGetClassIndex@VLocalBackpack@RBX@@@ServiceProvider@RBX@@SAXXZ'),
        (0x576b20, '??$?0VWorkspace@RBX@@' + DEL + '?$shared_ptr@VWorkspace@RBX@@@boost@@QAE@PAVWorkspace@RBX@@'
                   'VDeleter@?$Creatable@VInstance@RBX@@@3@@Z'),
        (0x576bd0, '??$?0VGuiRoot@RBX@@' + DEL + '?$shared_ptr@VGuiRoot@RBX@@@boost@@QAE@PAVGuiRoot@RBX@@'
                   'VDeleter@?$Creatable@VInstance@RBX@@@3@@Z'),
        (0x576d10, '??$?0VLocalBackpack@RBX@@' + DEL + '?$shared_ptr@VLocalBackpack@RBX@@@boost@@QAE@PAVLocalBackpack@'
                   'RBX@@VDeleter@?$Creatable@VInstance@RBX@@@3@@Z'),
        (0x576ff0, '??$create@VWorkspace@RBX@@PAVDataModel@2@@' + CI + 'SA?AV?$shared_ptr@VWorkspace@RBX@@@boost@@'
                   'PAVDataModel@1@@Z'),
        (0x577090, '??$create@VGuiRoot@RBX@@@' + CI + 'SA?AV?$shared_ptr@VGuiRoot@RBX@@@boost@@XZ'),
        (0x5771b0, '??$create@VLocalBackpack@RBX@@@' + CI + 'SA?AV?$shared_ptr@VLocalBackpack@RBX@@@boost@@XZ'),
    ],
    'notifiers': [
        (0x576940, '?raise@?$Notifier@VWorkspace@RBX@@VDrawChanged@2@@RBX@@IBEXVDrawChanged@2@@Z'),
    ],
    'lock': [
        (0x5773c0, '??1Lock@DataModel@RBX@@QAE@XZ'),
    ],
    'textdisplay': [
        (0x5744a0, '??0TextDisplay@RBX@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z'),
        (0x574570, '?getFontSize@TextDisplay@RBX@@MBEHXZ'),
        (0x574580, '?getLabel@TextDisplay@RBX@@MBE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ'),
        (0x5745b0, '??_ETextDisplay@RBX@@WIE@AEPAXI@Z'),
        (0x5745c0, '??_ETextDisplay@RBX@@WKE@AEPAXI@Z'),
        (0x5745d0, '??_ETextDisplay@RBX@@WME@AEPAXI@Z'),
        (0x5745e0, '??_ETextDisplay@RBX@@WBA@AEPAXI@Z'),
        (0x5745f0, '??_ETextDisplay@RBX@@WBE@AEPAXI@Z'),
        (0x574600, '??_ETextDisplay@RBX@@WCE@AEPAXI@Z'),
        (0x574610, '??_ETextDisplay@RBX@@WEE@AEPAXI@Z'),
        (0x574620, '??_ETextDisplay@RBX@@WGE@AEPAXI@Z'),
    ],
    'guiitem': [
        (0x5746a0, '?onDescendentRemoving@GuiItem@RBX@@EAEXABV?$shared_ptr@VInstance@RBX@@@boost@@@Z'),
        (0x574980, '?processNonFocus@GuiItem@RBX@@AAE?AVGuiResponse@2@ABVGuiEvent@2@@Z'),
        (0x574b10, '?process@GuiItem@RBX@@UAE?AVGuiResponse@2@ABVGuiEvent@2@@Z'),
    ],
    'timing': [
        (0x5757d0, '?getGameTime@DataModel@RBX@@QBENXZ'),
        (0x5757e0, '?getFrameRate@DataModel@RBX@@QBENXZ'),
    ],
    'duty': [
        (0x5757f0, '?getDutyCycle@DataModel@RBX@@QBENXZ'),
    ],
}
ROWS = {k: [] for k in SOURCES}
for _k, _specs in ROW_SPECS.items():
    for _a, _s in _specs:
        ROWS[_k].append((_a, _s))
OWN = {s: a for rows in ROWS.values() for a, s in rows}

# Rows whose compiled body equals the original only across a split extent (BOUNDS evidence; never counted here).
# symbol -> (object, [original pieces in order], prefix_only)
SPLIT = {
    '??1TextDisplay@RBX@@UAE@XZ': ('textdisplay', [0x574630], 'prefix'),
    '??_GTextDisplay@RBX@@UAEPAXI@Z': ('textdisplay', [0x574680], 'inside 0x574630'),
    '?doLock@Lock@DataModel@RBX@@AAEXPBV23@@Z': ('lock', [0x576f00], 'prefix'),
    '?raise@?$Notifier@VWorkspace@RBX@@VDrawChanged@2@@RBX@@IBEXVDrawChanged@2@PAV?$Listener@VWorkspace@RBX@@'
    'VDrawChanged@2@@2@@Z': ('notifiers', [0x576450, 0x57648e, 0x5764a1], 'joined'),
}

# Externals bound by evidence name or an identity proof below.
EXTERNAL = {
    '??0Workspace@RBX@@QAE@PAVIDataState@1@@Z': 0x5a4d90,
    '??0LocalBackpack@RBX@@QAE@XZ': 0x5fceb0,
    '??0GuiRoot@RBX@@QAE@XZ': 0x573b10,
    '??RDeleter@?$Creatable@VInstance@RBX@@@RBX@@QAEXPAVInstance@2@@Z': 0x405e30,
    '?newIndex@ServiceProvider@RBX@@SAIXZ': 0x572690,
    '?do_unlock@recursive_mutex@boost@@AAEXXZ': 0x5630e0,
    '?init@TextDisplay@RBX@@AAEXXZ': 0x5735e0,
}
# Externals whose evidence name differs from the native declaration only in the access letter (U public vs M
# protected): the 2008 Instance::onDescendentRemoving is protected; the core v8tree/Instance.h declares it public.
ACCESS_EXTERNAL = {
    '?onDescendentRemoving@Instance@RBX@@UAEXABV?$shared_ptr@VInstance@RBX@@@boost@@@Z':
        (0x55ae90, '?onDescendentRemoving@Instance@RBX@@MAEXABV?$shared_ptr@VInstance@RBX@@@boost@@@Z'),
}
# The primary ??_E of TextDisplay is the ??_G body (no vector deleting destructor is emitted): the thunks jump there.
ALIAS = {'??_ETextDisplay@RBX@@UAEPAXI@Z': '??_GTextDisplay@RBX@@UAEPAXI@Z'}
IDENTITY = {}
DATA_SECTIONS = [(original.image + s.VirtualAddress, original.image + s.VirtualAddress + s.Misc_VirtualSize)
                 for s in original.pe.sections if s.Name.rstrip(b'\0') in (b'.data', b'.rdata')]
TEXT = [(original.image + s.VirtualAddress, original.image + s.VirtualAddress + s.Misc_VirtualSize)
        for s in original.pe.sections if s.Name.rstrip(b'\0') == b'.text'][0]


def rtti_class(value):
    try:
        return original.vtable_class(value)[0]
    except Exception:
        return None


def vptr_classes(address, size=None):
    body = original.data(address, size or FUNCTIONS[address]['size'])
    out = set()
    for i in range(len(body) - 3):
        v = struct.unpack_from('<I', body, i)[0]
        if 0x7e0000 <= v < 0x900000 and any(lo <= v < hi for lo, hi in DATA_SECTIONS):
            c = rtti_class(v)
            if c:
                out.add((c, v))
    return out


def prove_identities():
    # GuiRoot() 0x573b10: its vptr stores name .?AVGuiRoot@RBX@@; create<GuiRoot> 0x577090 calls it, and the shared_ptr
    # 0x576bd0 it calls hands the pointer to shared_count 0x576750, which creatable-shared-count counts as
    # shared_count<GuiRoot*> (sp_counted_impl_pd<GuiRoot*> vtable 0x82fde8).
    classes = {c for c, _ in vptr_classes(0x573b10)}
    assert '.?AVGuiRoot@RBX@@' in classes, classes
    assert {'00573b10', '00576bd0'} <= set(FUNCTIONS[0x577090]['call_targets']), FUNCTIONS[0x577090]['call_targets']
    assert '00576750' in FUNCTIONS[0x576bd0]['call_targets']
    assert rtti_class(0x82fde8) == '.?AV?$sp_counted_impl_pd@PAVGuiRoot@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@2@@' \
                                   'detail@boost@@', rtti_class(0x82fde8)
    IDENTITY['??0GuiRoot@RBX@@QAE@XZ'] = (
        '0x573b10: vptr stores of .?AVGuiRoot@RBX@@ vtables; called by create<GuiRoot> 0x577090 (malloc 0x144)')
    IDENTITY['GuiRoot rows 0x576bd0 / 0x577090'] = (
        'create<GuiRoot> 0x577090 calls GuiRoot() 0x573b10 and shared_ptr<GuiRoot> 0x576bd0; 0x576bd0 calls '
        'shared_count 0x576750 (creatable-shared-count: sp_counted_impl_pd<GuiRoot*> vtable 0x82fde8)')
    # doGetClassIndex / callDoGetClassIndex<LocalBackpack>: find<LocalBackpack> 0x578530 (evidence name) pushes the
    # callDoGetClassIndex row 0x576800 for call_once and calls doGetClassIndex 0x575630; 0x576800 is jmp 0x575630.
    assert names.get(0x578530) == '??$find@VLocalBackpack@RBX@@@ServiceProvider@RBX@@QBEPAVLocalBackpack@1@XZ' or \
        names.get(0x578530) is None
    body, _ = target_of(0x578530)
    assert b'\x68' + struct.pack('<I', 0x576800) in body
    assert '00575630' in FUNCTIONS[0x578530]['call_targets']
    jb = original.data(0x576800, 5)
    assert jb[0] == 0xe9 and 0x576805 + struct.unpack_from('<i', jb, 1)[0] == 0x575630
    IDENTITY['doGetClassIndex / callDoGetClassIndex<LocalBackpack> 0x575630 / 0x576800'] = (
        'find<LocalBackpack> 0x578530 pushes 0x576800 (call_once) and calls 0x575630; 0x576800 is jmp 0x575630')
    # ServiceProvider::newIndex 0x572690: the only call of doGetClassIndex; InterlockedIncrement through the IAT.
    nb_body = original.data(0x572690, FUNCTIONS[0x572690]['size'])
    hits = [original.imports[v][::2] for v in (struct.unpack_from('<I', nb_body, i)[0] for i in range(len(nb_body) - 3))
            if v in original.imports]
    assert ('kernel32.dll', 'InterlockedIncrement') in hits, hits
    IDENTITY['?newIndex@ServiceProvider@RBX@@SAIXZ'] = (
        '0x572690: InterlockedIncrement on the index counter (app-unit570 map: ServiceProvider::newIndex shape); the '
        'only call of every doGetClassIndex<C> (e.g. 0x575630 here)')
    # TextDisplay rows: the constructor stores the .?AVTextDisplay@RBX@@ vtables (slot checks below).
    assert '.?AVTextDisplay@RBX@@' in {c for c, _ in vptr_classes(0x5744a0)}
    # TextDisplay::init 0x5735e0: called only by the TextDisplay constructor 0x5744a0; stores the TextDisplay fields
    # fontSize +0x160 (= 18), fontColor +0x164.., borderColor +0x174.. and align +0x184 that gui/Gui.h lays out.
    assert FUNCTIONS[0x5735e0]['callers'] == ['005744a0'], FUNCTIONS[0x5735e0]['callers']
    ib = original.data(0x5735e0, FUNCTIONS[0x5735e0]['size'])
    assert b'\xc7\x86\x60\x01\x00\x00\x12\x00\x00\x00' in ib and b'\xc7\x86\x84\x01\x00\x00\x01\x00\x00\x00' in ib
    IDENTITY['?init@TextDisplay@RBX@@AAEXXZ'] = (
        '0x5735e0: only caller the TextDisplay constructor 0x5744a0 (after the vptr stores); stores fontSize +0x160 = '
        '18, the colours +0x164 / +0x174 and align +0x184')
    IDENTITY['?do_unlock@recursive_mutex@boost@@AAEXXZ'] = (
        '0x5630e0: boost 1.34.1 recursive_mutex::do_unlock (LeaveCriticalSection / ReleaseMutex through the IAT); '
        'record_native_app_leaves2008_dhtml.py and record_native_app_leaves2008_services.py bind the same address')
    ub = original.data(0x5630e0, FUNCTIONS[0x5630e0]['size'])
    uh = {original.imports[v][2] for v in (struct.unpack_from('<I', ub, i)[0] for i in range(len(ub) - 3))
          if v in original.imports}
    assert {'LeaveCriticalSection', 'ReleaseMutex'} <= uh, uh
    # DataModel timing rows: datamodel-timing-working.json records these symbols at these addresses (not counted).
    timing = json.loads((ROOT / 'work/2008-06/shared-layouts/datamodel-timing-working.json').read_text())
    recorded = {m['address']: m['symbol'] for m in timing['methods']}
    for a, s in ROW_SPECS['timing'] + ROW_SPECS['duty']:
        assert recorded.get('%08x' % a) == s, (hex(a), recorded.get('%08x' % a))
    IDENTITY['DataModel timing rows'] = ('datamodel-timing-working.json records getGameTime / getFrameRate / '
                                         'getDutyCycle at 0x5757d0 / 0x5757e0 / 0x5757f0 (methods list, no exact flag)')
    for a, s in ROW_SPECS['guiitem']:
        assert names.get(a) == s, (hex(a), names.get(a))


prove_identities()

BINDING = {}
UNBOUND = []
HELPERS = {}
SPLIT_RESULTS = {}


def bind(symbol, value, where):
    prev = BINDING.setdefault(symbol, (value, where))
    assert prev[0] == value, ('one address per symbol', symbol, hex(prev[0]), prev[1], hex(value), where)


ALL_BODIES = {}
for _k, _o in OBJ.items():
    for n, b, r in match.coff_functions(Path(_o).read_bytes()):
        ALL_BODIES.setdefault(n, (b, r))


def split_check(symbol):
    """Compiled body against the original pieces: 'joined' concatenates split extents, 'prefix' compares the compiled
    body with the start of a longer original extent, 'inside' compares it at its offset in the merged extent."""
    if symbol in SPLIT_RESULTS:
        return SPLIT_RESULTS[symbol]
    key, pieces, how = SPLIT[symbol]
    body, refs = ALL_BODIES[symbol]
    if how == 'joined':
        t, tr = b'', []
        for p in pieces:
            x, xr = target_of(p)
            tr += [o + len(t) for o in xr]
            t += x
        ok = len(t) == len(body) and bool(match.exact_match(t, tr, body, refs))
        value = pieces[0]
    elif how == 'prefix':
        x, xr = target_of(pieces[0])
        ok = len(x) > len(body) and bool(match.exact_match(x[:len(body)], [o for o in xr if o < len(body)], body, refs))
        value = pieces[0]
    else:
        base = 0x574630
        x, xr = target_of(base)
        off = pieces[0] - base
        seg = x[off:off + len(body)]
        ok = len(seg) == len(body) and off + len(body) == len(x) and bool(
            match.exact_match(seg, [o - off for o in xr if off <= o < off + len(body)], body, refs))
        value = pieces[0]
    SPLIT_RESULTS[symbol] = (ok, value, how)
    return SPLIT_RESULTS[symbol]


def verify(build_key, obj, rows):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    out = []
    for address, name in rows:
        assert name in bodies, (build_key, hex(address), name, [n for n in bodies if name[:30] in n])
        body, refs = bodies[name]
        target, target_refs = target_of(address)
        exact = match.exact_match(target, target_refs, body, refs)
        row = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target),
               'exact': bool(exact), 'build': build_key, 'verified_targets': {}, 'local_eh': []}
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
            elif symbol in OWN:
                assert OWN[symbol] == value, (where, symbol, hex(value))
                how = 'own row'
            elif symbol in ACCESS_EXTERNAL:
                expect, evidence = ACCESS_EXTERNAL[symbol]
                assert expect == value and names.get(value) == evidence, (where, symbol, hex(value), names.get(value))
                how = 'external (evidence name %s; access letter differs)' % evidence
            elif symbol in SPLIT or symbol in ALIAS:
                ok, expect, kind_ = split_check(ALIAS.get(symbol, symbol))
                assert ok and expect == value, (where, symbol, hex(value), ok, hex(expect))
                how = 'compiled body exact at the bound address across a split extent (%s; BOUNDS, not counted)' % kind_
            elif symbol.startswith('??_R0') and symbol.endswith('@8'):
                rtti = original.string(value + 8)
                assert norm(rtti) == norm('.' + symbol[5:-2]), (where, symbol, hex(value), rtti)
                how = 'RTTI %s' % rtti
            elif symbol.startswith('??_7'):
                rtti, at = original.vtable_class(value)
                cls = symbol[4:symbol.index('@@6B') + 2]
                assert norm(rtti) == norm('.?AV' + cls), (where, symbol, hex(value), rtti)
                how = 'vtable RTTI %s offset %#x' % (rtti, at)
            elif '%08x' % value in elsewhere and symbol in bodies:
                receipts = sorted(set(elsewhere['%08x' % value]))
                hb, hr = bodies[symbol]
                ht, htr = target_of(value)
                assert match.exact_match(ht, htr, hb, hr), ('counted-elsewhere body not exact', symbol, hex(value))
                how = 'row counted by %s (compiled body exact at the bound address)' % ', '.join(receipts)
            elif symbol in EXTERNAL:
                assert EXTERNAL[symbol] == value, (where, symbol, hex(value), hex(EXTERNAL[symbol]))
                if names.get(value, '') == symbol:
                    how = 'external (evidence name)'
                else:
                    assert symbol in IDENTITY, (where, symbol)
                    how = 'external (identity: %s)' % IDENTITY[symbol]
            elif symbol in bodies:
                hb, hr = bodies[symbol]
                ht, htr = target_of(value) if value in FUNCTIONS else (b'', [])
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
            bind(symbol, value, where)
            row['verified_targets'][symbol] = '%#x (%s)' % (value, how)
    return out


groups = {k: verify(k, OBJ[k], ROWS[k]) for k in SOURCES}
not_exact = [r for rows in groups.values() for r in rows if not r['exact']]
for s in SPLIT:
    split_check(s)
if DISCOVER:
    for u in UNBOUND:
        print('UNBOUND', u)
    for r in not_exact:
        print('ROW', r['address'], r['exact'], r['size'], r['target_size'], r['symbol'][:100])
    for s, v in SPLIT_RESULTS.items():
        print('SPLIT', s[:80], v)
assert not UNBOUND or DISCOVER, UNBOUND
assert not not_exact or DISCOVER, [(r['address'], r['symbol'][:80]) for r in not_exact]
assert all(v[0] for v in SPLIT_RESULTS.values()) or DISCOVER, SPLIT_RESULTS
for symbol, address in EXTERNAL.items():
    assert address in FUNCTIONS or original.imported(address) is not None, (symbol, hex(address))


# ---- TextDisplay vtables (current-header object): slot by slot against the original vtables ------------------------
def vtable_slots(obj_path, prefix, candidates):
    raw = Path(obj_path).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    known = dict(OWN)
    known.update({s: v[1] for s, v in SPLIT_RESULTS.items()})
    known.update({s: v[0] for s, v in BINDING.items()})
    code_range = range(0x401000, 0x7e0000)
    out = {}
    for symbol in sorted(s for s in definitions if s.startswith(prefix)):
        start, sec = definitions[symbol]
        table = sections[sec]
        relocs = sorted((struct.unpack_from('<IIH', raw, table[5] + 10 * k)) for k in range(table[7]))
        slots = [(off - start, symbols[idx][0]) for off, idx, kind in relocs if kind == 6 and off >= start]
        slots = [x for x in slots if x[0] < table[3] - start]
        col = [symbols[idx][0] for off, idx, kind in relocs if kind == 6 and off == start - 4]
        assert len(col) == 1 and col[0].startswith('??_R4'), (symbol, col)
        cstart, csec = definitions[col[0]]
        cpos = sections[csec][4] + cstart
        sub_offset, cd_offset = struct.unpack_from('<II', raw, cpos + 4)
        matches = []
        for address in candidates:
            locator = d(address - 4)
            if struct.unpack('<II', original.data(locator + 4, 8)) != (sub_offset, cd_offset):
                continue
            originals = [d(address + 4 * k) for k in range(len(slots) + 1)]
            if not (all(v in code_range for v in originals[:-1]) and originals[-1] not in code_range):
                continue
            checked, ok = [], True
            for off, target_symbol in slots:
                expect = known.get(target_symbol)
                if expect is None and target_symbol in ALL_BODIES:
                    # a compiled body that is not a row here: the original slot must hold an exact body
                    value = originals[off // 4]
                    if value in FUNCTIONS:
                        ht, htr = target_of(value)
                        hb, hr = ALL_BODIES[target_symbol]
                        if match.exact_match(ht, htr, hb, hr):
                            checked.append('%d %s = %#x (exact helper body)' % (off // 4, target_symbol[:80], value))
                    continue
                value = originals[off // 4]
                if expect is not None:
                    if expect != value:
                        ok = False
                        break
                    checked.append('%d %s = %#x' % (off // 4, target_symbol[:80], value))
            if ok:
                matches.append((address, checked))
        assert len(matches) == 1, ('vtable match', symbol, [hex(a) for a, _ in matches])
        address, checked = matches[0]
        out[symbol] = {'address': '%#x' % address, 'subobject_offset': '%#x' % sub_offset, 'slots': len(slots),
                       'checked_bound_slots': checked}
    return out


TD_CANDIDATES = sorted(v for c, v in vptr_classes(0x5744a0) if c == '.?AVTextDisplay@RBX@@')
vtables = vtable_slots(OBJ['textdisplay'], '??_7TextDisplay@RBX@@6B', TD_CANDIDATES)
assert len(vtables) == len(TD_CANDIDATES), (len(vtables), [hex(x) for x in TD_CANDIDATES])
bound_slots = {c.split(' ')[1] for v in vtables.values() for c in v['checked_bound_slots']}
for a, s in ROW_SPECS['textdisplay'][1:]:
    assert s[:80] in bound_slots, ('vtable slot not checked', hex(a), s)

# ---- sizeof(C): the malloc size each create<C> passes ---------------------------------------------------------------
SIZES = {}
for a, c in ((0x576ff0, 'Workspace'), (0x577090, 'GuiRoot'), (0x5771b0, 'LocalBackpack')):
    body, _ = target_of(a)
    sizes = [struct.unpack_from('<I', body, k.start() + 1)[0] for k in re.finditer(rb'\x68', body)]
    sizes = [s for s in sizes if 0x40 <= s < 0x4000]
    assert len(sizes) == 1, (c, sizes)
    SIZES[c] = 'sizeof %#x (malloc in create<%s> %#x; the compiled push is exact against the native header layout)' % (
        sizes[0], c, a)


# ---- unit map evidence -------------------------------------------------------------------------------------------
def holds_string(address, text):
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


BLOCKS = [
    ('rbx gui/GUI.cpp tail (unit begins at 0x573130, ends at 0x574f0c)', LO, 0x574f10,
     [('name', 0x574050, '?render2d@TopMenuBar@RBX@@UAEXPAVAdorn@2@@Z'),
      ('name', 0x5746a0, ROW_SPECS['guiitem'][0][1]), ('name', 0x574980, ROW_SPECS['guiitem'][1][1]),
      ('name', 0x574b10, ROW_SPECS['guiitem'][2][1]),
      ('name', 0x574bf0, '?process@TopMenuBar@RBX@@UAE?AVGuiResponse@2@ABVGuiEvent@2@@Z')],
     [('vptr', 0x5744a0, '.?AVTextDisplay@RBX@@')]),
    ('rbx v8datamodel/DataModel.cpp (begins at 0x574f10, continues past 0x578000 to 0x57c1af)', 0x574f10, HI,
     [('name', 0x574f10, '?setUiMessage@DataModel@RBX@@QAEXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@'
                         '@std@@@Z'),
      ('name', 0x575270, '?close@DataModel@RBX@@QAEXXZ'), ('string', 0x575270, "Couldn't find Exit Verb"),
      ('name', 0x575d90, '?evaluate@DataModel@RBX@@UBE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@'
                         '@std@@ABV34@@Z'), ('string', 0x575d90, 'SimCpu'),
      ('name', 0x576f00, '?doLock@Lock@DataModel@RBX@@AAEXPBV23@@Z'), ('name', 0x5773c0, '??1Lock@DataModel@RBX@@QAE@XZ')],
     []),
]
range_rows = sorted(a for a in FUNCTIONS if LO <= a < HI)
for a in range_rows:
    assert sum(lo <= a < hi for _, lo, hi, _, _ in BLOCKS) == 1, hex(a)
for name, lo, hi, ev, vps in BLOCKS:
    for kind, a, text in ev:
        assert lo <= a < hi, (name, hex(a))
        if kind == 'name':
            assert names.get(a) == text, (name, hex(a), names.get(a))
        else:
            assert holds_string(a, text), (name, hex(a), text)
    for _, a, cls in vps:
        assert lo <= a < hi and cls in {c for c, _ in vptr_classes(a)}, (name, hex(a), cls)
# the TextDisplay ??_E thunks all jump to ??_G 0x574680 inside the 0x574630 extent
for a, s in ROW_SPECS['textdisplay'][3:]:
    b = original.data(a, FUNCTIONS[a]['size'])
    assert b[-5] == 0xe9 and a + len(b) + struct.unpack_from('<i', b, len(b) - 4)[0] == 0x574680, hex(a)

exact_rows = sorted({r['address'] for rows in groups.values() for r in rows if r['exact']})
double = {a: elsewhere[a] for a in exact_rows if a in elsewhere}
assert not double, double
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if LO <= int(a, 16) < HI}
open_rows = ['%08x' % a for a in range_rows if '%08x' % a not in exact_rows and '%08x' % a not in range_counted]

CATEGORY_SPANS = [
    ((0x574050, 0x574051), 'TopMenuBar::render2d (evidence name): calls the out-of-line GuiItem::getMyRect2D 0x573960 '
                           'that gui/Gui.h declares inline (widget-family proposal)'),
    ((0x574130, 0x574151), 'ICF-shared Widget / KeyButton ??_E / ??_G thunks (support rows of widget-family-working, '
                           'compiled exact there)'),
    ((0x574170, 0x5744a0), 'UnifiedWidget members (render / child layout; matched-analog unit RBX::UnifiedWidget; '
                           'gui/Gui.h UnifiedWidget, widget-family pending getMenuState inline)'),
    ((0x574630, 0x574631), '~TextDisplay (built: the compiled 80-byte ~TextDisplay and 31-byte ??_G are exact as '
                           'prefix / tail of this 111-byte extent; BOUNDS: ??_G starts at 0x574680)'),
    ((0x5746e0, 0x574980), 'UnifiedWidget process helpers (callers 0x574de0 / 0x574e70; Rect::pointInRect 0x573130)'),
    ((0x574bf0, 0x574bf1), 'TopMenuBar::process (evidence name): calls the out-of-line Rect::pointInRect 0x573130 '
                           '(util/Rect.h inline; widget-family proposal)'),
    ((0x574cb0, 0x574f0d), 'UnifiedWidget process chain (0x574e70 called by 0x64ead0)'),
    ((0x574f10, 0x574f92), 'DataModel::setUiMessage and the uiMessage (+0x234) string assigns ("[[[progress]]]"); '
                           'not declared in v8datamodel/DataModel.h'),
    ((0x574fa0, 0x574fd1), 'ICF-folded field getters (0x574fb0 evidence name Primitive::getController; callers in '
                           'other units)'),
    ((0x574fe0, 0x5756e1), 'DataModel members / helpers not declared in DataModel.h (doHttpGet / doHttpPost 0x575060 / '
                           '0x575120, close 0x575270, stats text 0x575300, BoundFuncDesc execute helpers 0x575400 / '
                           '0x575460, render-time 0x575690, 0x575040 / 0x575240 / 0x5756e0)'),
    ((0x575700, 0x575701), 'boost::_bi::storage2<value<string>, value<string>> destructor (evidence name)'),
    ((0x575750, 0x575d91), 'DataModel::onChildAdded / onEvent / key handling ("CameraPanLeft") / evaluate (evidence '
                           'names; not declared in DataModel.h)'),
    ((0x576390, 0x5764a2), 'Notifier raise(event, listener) bodies: ServiceProvider/Closing 0x576390 and '
                           'Workspace/DrawChanged 0x576450 (built: exact only when joined with the catch funclets '
                           '0x57648e / 0x5764a1; BOUNDS) and their funclet pieces'),
    ((0x576510, 0x5765f1), 'boost::_bi::storage2 copy / value constructors (evidence names)'),
    ((0x5767e0, 0x5767e1), 'boost::checked_delete<recursive_mutex> (dtor 0x594cb0; boost header instance)'),
    ((0x5768a0, 0x5768a1), 'ICF jmp to the storage2 destructor 0x575700'),
    ((0x5768b0, 0x5768b1), 'Notifier<ServiceProvider, Closing>::raise(Closing) (needs a complete Closing: '
                           'v8tree/Service.h proposal)'),
    ((0x5769d0, 0x5769d1), 'boost::_bi::list2<value<string>, value<string>> constructor (evidence name)'),
    ((0x576a70, 0x576a71), 'shared_ptr<DataModel>(DataModel*, Deleter) (needs create<DataModel>, i.e. a declared '
                           'DataModel(); the explicit constructor-template instantiation does not compile under '
                           'VS2008 with boost 1.34.1 sp_enable_if_auto_ptr)'),
    ((0x576c80, 0x576cef), 'shared_count(recursive_mutex*) and its catch piece (boost header instance, '
                           'sp_counted_impl_p<recursive_mutex> vtable 0x82fdac)'),
    ((0x576dc0, 0x576e51), 'boost::_bi list1 / list2 operator() of the rbx_httpGet / rbx_httpPost binds'),
    ((0x576f00, 0x576f01), 'DataModel::Lock::doLock (built from DataModelLock.cpp: the compiled 128-byte body is '
                           'exact as the prefix of this 136-byte extent; BOUNDS: 0x576f80 "add ecx, 4; jmp 0x575700" '
                           'is a separate thunk)'),
    ((0x576f90, 0x576f91), 'DataModel helper (caller 0x578c20, RunService transition path)'),
    ((0x577110, 0x577111), 'boost::bind<string, string, string> (evidence name)'),
    ((0x577230, 0x577c71), 'boost::function / bind storage, list, functor_manager and invoker instances of the '
                           'DataModel http / message binds (evidence names)'),
    ((0x577d00, 0x577f31), 'boost::function / bind helpers of the same binds (callers 0x57b680 / 0x588db0)'),
    ((0x577fa0, 0x577fa1), 'shared_count(LocalBackpackItem*, Deleter) (compiled exact by app-unit578 as a helper)'),
]
OPEN_CATEGORIES = {}
for a in open_rows:
    v = int(a, 16)
    cat = [n for (lo, hi), n in CATEGORY_SPANS if lo <= v < hi]
    assert len(cat) == 1, (a, cat)
    OPEN_CATEGORIES.setdefault(cat[0], []).append('%#x' % v)

UNIT_MAP = {
    'rbx gui/GUI.cpp tail 0x574000..0x574f0c (unit 0x573130..0x574f0c)': (
        'Continues the GUI unit app-unit570 maps from 0x573130 (Rect::pointInRect, GuiItem colour statics, GuiItem / '
        'RelativePanel / TopMenuBar / GuiRoot members). In range: TopMenuBar::render2d 0x574050 and process 0x574bf0 '
        '(evidence names), the ICF-shared Widget ??_E / ??_G thunks 0x574130..0x574150 (widget-family support rows), '
        'UnifiedWidget members 0x574170..0x574400 and its process chain 0x5746e0..0x574e70, the TextDisplay block '
        '(constructor 0x5744a0 storing the .?AVTextDisplay@RBX@@ vtables, getFontSize 0x574570, getLabel 0x574580, '
        'eight ??_E thunks 0x5745b0..0x574620 jumping to ??_G 0x574680, ~TextDisplay 0x574630 whose extent also holds '
        '??_G), and GuiItem::onDescendentRemoving / processNonFocus / process 0x5746a0 / 0x574980 / 0x574b10 '
        '(evidence names; committed native-classes/GuiItem.cpp). Built here: the TextDisplay rows (own source) and '
        'the three GuiItem rows (owner source, compiled unchanged).'),
    'rbx v8datamodel/DataModel.cpp 0x574f10..0x578000 (unit 0x574f10..0x57c1af)': (
        'DataModel::setUiMessage 0x574f10 opens the unit (app-unit570 map), followed by DataModel members (doHttpGet / '
        'doHttpPost, close "Couldn\'t find Exit Verb", stats text "%i %%  %s (%.3gfps)", onChildAdded "NetworkClient", '
        'onEvent, key handling "CameraPanLeft", evaluate "SimCpu" / "GfxCpu", getGameTime / getFrameRate / '
        'getDutyCycle), then the template COMDAT run: Notifier raise instances (ServiceProvider/Closing 0x5768b0 / '
        '0x576390, Workspace/DrawChanged 0x576940 / 0x576450), Name::declare thunks (local-backpack / hopper-family '
        'count 0x5754e0 / 0x575550 / 0x5755c0 / 0x576600..0x576620), the shared_count (creatable-shared-count) / '
        'shared_ptr / create instances of DataModel, Workspace, GuiRoot and LocalBackpack, doGetClassIndex / '
        'callDoGetClassIndex<LocalBackpack>, DataModel::Lock::doLock / ~Lock, shared_count<recursive_mutex>, and the '
        'boost bind / function instances of rbx_httpGet / rbx_httpPost / the message binds. Built here: the Creatable '
        '/ ServiceProvider / Notifier instances (own sources), ~Lock and the timing members (owner sources, compiled '
        'unchanged). DataModel\'s other members need declarations the core v8datamodel/DataModel.h lacks.'),
    'library code': (
        'No separately compiled library unit starts in the range. boost::_bi / function / checked_delete / '
        'shared_count<recursive_mutex> rows are boost header instances inside the DataModel unit; not recovered.'),
    'excluded': (
        'No CRobloxApp / CMainFrame / CRobloxDoc / CRobloxView member lies in the range.'),
}
NOT_EXACT_BOUNDS = {
    '0x574630 ~TextDisplay (111 B extent)': (
        'built (own TextDisplay source): the implicit ~TextDisplay (80 B) is exact as the first 0x50 bytes and the '
        '??_G (31 B) as the last 0x1f bytes; BOUNDS for the server host: end 0x574630 at 0x574680 and start ??_G '
        'there (the eight ??_E thunks 0x5745b0..0x574620 jump to 0x574680). Not counted.'),
    '0x576f00 DataModel::Lock::doLock (136 B extent)': (
        'built: the compiled 128-byte body is exact as the prefix; BOUNDS: end at 0x576f80, where an 8-byte thunk '
        '"add ecx, 4; jmp 0x575700" starts. Not counted.'),
    '0x576450 Notifier<Workspace, DrawChanged>::raise(DrawChanged, Listener*) (62 B extent)': (
        'built: the compiled 185-byte body is exact against 0x576450 + 0x57648e + 0x5764a1 joined (the catch '
        'funclets are separate extents); BOUNDS: one function 0x576450..0x576509. Not counted.'),
}
REJECTED = {
    'shared_ptr<DataModel>(DataModel*, Deleter) 0x576a70 by explicit constructor instantiation': (
        '`template shared_ptr<DataModel>::shared_ptr(DataModel*, Deleter);` and the `<DataModel, Deleter>` / `<>` '
        'spellings do not compile (C2794 sp_enable_if_auto_ptr / C2977 / C2976 with boost 1.34.1 under VS2008).'),
}
PROPOSALS = {
    'v8tree/Service.h (owner of the native ServiceProvider declaration; not edited)': (
        'define `class Closing {};` (currently only forward-declared): Notifier<ServiceProvider, Closing>::raise(Closing) '
        '0x5768b0 passes it by value as one byte (0x57b906 mov byte ptr [esp+0x38], bl; push) and the listener raise '
        '0x576390 is the same 62 B + funclet shape as 0x576450. With it, 0x5768b0 becomes a candidate (not built here).'),
    'v8datamodel/DataModel.h (core owner; not edited)': (
        'declare `DataModel();` (0x57b9f0, evidence name ??0DataModel@RBX@@QAE@XZ; app-unit578 proposal) so '
        'create<DataModel> 0x57c080 instantiates shared_ptr<DataModel> 0x576a70; declare '
        '`void setUiMessage(std::string);` (0x574f10, evidence name ?setUiMessage@DataModel@RBX@@QAEXV?$basic_string'
        '...@@Z, assigns uiMessage +0x234), `void close();` (0x575270), `virtual std::string evaluate(const '
        'std::string&) const;` (0x575d90, Evaluator override), `virtual void onChildAdded(Instance*);` (0x575750, MAE) '
        'and `virtual void onEvent(const RunService*, RunTransition);` (0x575840, MAE), all evidence names.'),
    'gui/Gui.h (gui owner; not edited), FYI': (
        'as widget-family records: GuiItem::getMyRect2D 0x573960 is out of line (blocks TopMenuBar::render2d '
        '0x574050), and util/Rect.h pointInRect(Vector2int16) 0x573130 is out of line (blocks TopMenuBar::process '
        '0x574bf0).'),
}

paths = [Path(__file__).resolve()] + list(SOURCES.values()) + HEADERS
receipt = {
    'class': 'RBX gui/GUI.cpp tail and v8datamodel/DataModel.cpp rows of the application range 00574000..00578000 '
             '(2008-06), inactive',
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
    'identity_bindings': IDENTITY,
    'textdisplay_vtables_current_headers': vtables,
    'split_extent_bodies': {s[:120]: {'exact': v[0], 'at': '%#x' % v[1], 'how': v[2]} for s, v in SPLIT_RESULTS.items()},
    'helper_bodies_not_counted': HELPERS,
    'not_exact_bounds': NOT_EXACT_BOUNDS,
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
print('PASS app-unit574: %d counted exact rows (%s); %d range rows, %d counted elsewhere, %d open; %d TextDisplay '
      'vtables checked' % (len(exact_rows), ' '.join(exact_rows), len(range_rows), len(range_counted), len(open_rows),
                           len(vtables)))
