"""Verify the inactive boost shared_count<T*, Creatable<Instance>::Deleter> constructor fan-out (2008-06).

Authentic vendor-template family (CLAUDE.md method 4): boost 1.34.1
`detail::shared_count::shared_count<P, D>(P p, D d)` instantiated for P = T*, D = RBX::Creatable<RBX::Instance>::Deleter.
Every original instance is a 131-byte function (pinned extent in bounds.json: `ret 8` at +0x6b, then the 21-byte
catch(...) funclet that calls Deleter::operator()(Instance*) 00405e30 and rethrows). Each stores its own
sp_counted_impl_pd<T*, Deleter> vtable (`mov dword ptr [eax], imm32` at +0x4a); T of every row is read from that
vtable's RTTI complete-object locator and listed in ROWS below.

Builds (document-swap flags, VS2008 RTM 21022), all from the current committed native headers (read-only):
  * native-classes/CreatableSharedCount2008.cpp       the main unit (explicit instantiations, one per row);
  * native-classes/CreatableSharedCount2008Stats.cpp  T from stats/Stats.h / stats/WorkspaceStatsItem.h (their
                                                      RBX::Stats::Item collides with v8datamodel/Stats.h, which the
                                                      main unit reaches through util/Sound.h);
  * native-classes/CreatableSharedCount2008Content.cpp  RBX::ContentProvider from util/NativeContentProvider.h
                                                      (collides with the donor util/ContentProvider.h).

Per row: the compiled function (resolved through its ??_7sp_counted_impl_pd relocation, whose class must equal the
RTTI name of the vtable the original stores) is relocation-masked exact against the original's complete 131-byte
extent, and every REL32/DIR32 target is bound to the address the original instruction uses and verified: operator new
by its mfc90 import, the vtable by original RTTI name, the deleter call by the explicit EXTERNAL map (same binding as
the committed service recorders), _CxxThrowException by its msvcr90 import. A symbol binds to one address across all
rows. Each compiled sp_counted_impl_pd vtable (from the objects built here) is compared slot by slot with the original
vtable; its slot bodies (??_G, dispose, get_deleter) are compared with the ICF-folded originals 00415000 / 0048ee50 /
005a0460 (sp_counted_base::destroy 00405e10) and recorded as evidence only (never counted here; ??_G / get_deleter are
counted by other receipts; dispose 0048ee50 inlines the deleter in the original and is not exact from these units).

A row already counted by another receipt in work/2008-06/shared-layouts is never counted here (checked at run time).
Writes work/2008-06/shared-layouts/creatable-shared-count-working.json. Set NATIVE_SHARED_COUNT_DISCOVER=1 to list
unbound targets and non-exact rows instead of asserting.
"""
import json
import os
import struct
import sys
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match, rebuild  # noqa: E402
import native_bind as nb  # noqa: E402

R = ROOT / 'rebuild/2008-06'
OUT = R / 'out/creatable-shared-count'
OUT.mkdir(parents=True, exist_ok=True)
UNITS = {
    'main': R / 'native-classes/CreatableSharedCount2008.cpp',
    'stats': R / 'native-classes/CreatableSharedCount2008Stats.cpp',
    'content': R / 'native-classes/CreatableSharedCount2008Content.cpp',
}
RECEIPT = ROOT / 'work/2008-06/shared-layouts/creatable-shared-count-working.json'
DISCOVER = bool(os.environ.get('NATIVE_SHARED_COUNT_DISCOVER'))
DLR = 'VDeleter@?$Creatable@VInstance@RBX@@@'
SCPD = '.?AV?$sp_counted_impl_pd@PAV'


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


# ---- rows: address -> T as named by the RTTI of the sp_counted_impl_pd vtable the original stores at +0x4a -----------
ROWS = {
    0x405e60: 'RunService@RBX', 0x409000: 'Team@RBX', 0x409270: 'Player@Network@RBX', 0x4094e0: 'Selection@RBX',
    0x40b560: 'Classes@Metadata@Reflection@RBX', 0x40b810: 'Class@Metadata@Reflection@RBX',
    0x40bcb0: 'Properties@Metadata@Reflection@RBX', 0x40bf70: 'Functions@Metadata@Reflection@RBX',
    0x40c260: 'Events@Metadata@Reflection@RBX', 0x40c430: 'Member@Metadata@Reflection@RBX',
    0x40c620: 'AuthoringSettings', 0x4118a0: 'ChatEnter', 0x411940: 'Players@Network@RBX',
    0x414820: 'ModelInstance@RBX', 0x414a90: 'Script@RBX', 0x414d00: 'LocalScript@RBX',
    0x414f70: 'ChangeHistoryService@RBX', 0x41ba00: 'DHTMLWindowService', 0x41e100: 'Decal@RBX', 0x41e190: 'Texture@RBX',
    0x41e230: 'ContentProvider@RBX', 0x41e880: 'PartInstance@RBX', 0x41eaf0: 'SpecialShape@RBX',
    0x42d0f0: 'ScriptContext@RBX', 0x4323e0: 'Accoutrement@RBX', 0x432650: 'Hat@RBX',
    0x440840: 'SoundService@Soundscape@RBX', 0x440ab0: 'SoundChannel@Soundscape@RBX', 0x452790: 'Visit@RBX',
    0x456410: 'StatsService@Stats@RBX', 0x45b790: 'ControllerService@RBX', 0x45da00: 'Camera@RBX',
    0x48ac30: 'Backpack@RBX', 0x48acc0: 'TimerService@RBX', 0x48e650: 'HopperBin@RBX',
    0x48e8c0: 'StarterPackService@RBX', 0x48eb30: 'LegacyHopperService@RBX', 0x48ee70: 'SpawnLocation@RBX',
    0x48f0e0: 'SpawnerService@RBX', 0x48f350: 'ShirtGraphic@RBX', 0x48f5c0: 'Clothing@RBX', 0x48f900: 'Pants@RBX',
    0x48fc00: 'Shirt@RBX', 0x48fe30: 'BodyColors@RBX', 0x4900a0: 'Skin@RBX', 0x490310: 'Teams@RBX',
    0x490630: 'Humanoid@RBX', 0x49e620: 'NetworkSettings@RBX', 0x4a3710: 'Message@RBX', 0x4a3a00: 'Hint@RBX',
    0x4ac620: '?$TypedStatsItem@_N@Stats@RBX', 0x4ac710: 'JointsService@RBX', 0x4b2270: 'Snap@RBX',
    0x4b24e0: 'Weld@RBX', 0x4b2750: 'Glue@RBX', 0x4b29c0: 'Rotate@RBX', 0x4b2c30: 'RotateP@RBX',
    0x4b2ea0: 'RotateV@RBX', 0x4b3110: 'Motor@RBX', 0x4d8b50: 'Sky@RBX', 0x568600: 'GlobalSettings@RBX',
    0x576630: 'DataModel@RBX', 0x5766c0: 'Workspace@RBX', 0x576750: 'GuiRoot@RBX', 0x576810: 'LocalBackpack@RBX',
    0x5782c0: 'Tool@RBX', 0x57ddc0: '?$FilteredSelection@VPVInstance@RBX@@@RBX',
    0x57de50: '?$FilteredSelection@VModelInstance@RBX@@@RBX', 0x57fe80: 'MotorFeature@RBX', 0x5800f0: 'Hole@RBX',
    0x580360: 'VelocityMotor@RBX', 0x5a0b50: 'WorkspaceStatsItem@RBX', 0x5a0be0: '?$TypedStatsItem@N@Stats@RBX',
    0x5a0c70: '?$TypedStatsItem@M@Stats@RBX', 0x5a3070: 'Flag@RBX', 0x5b7480: 'StockSound',
    0x5b7510: 'SoundServiceStatsItem', 0x5b75a0: '?$TypedStatsItem@I@Stats@RBX', 0x5c0a20: 'ClickDetector@RBX',
    0x5c0c90: 'Explosion@RBX', 0x5c0f00: 'FlagStand@RBX', 0x5c1170: 'FlagStandService@RBX', 0x5c18c0: 'BodyGyro@RBX',
    0x5c1b30: 'BodyForce@RBX', 0x5c1da0: 'BodyThrust@RBX', 0x5c2010: 'BodyPosition@RBX', 0x5c2280: 'BodyVelocity@RBX',
    0x5c24f0: 'BodyAngularVelocity@RBX', 0x5c2760: 'Rocket@RBX', 0x5c2af0: 'ObjectValue@RBX', 0x5c2f40: 'Seat@RBX',
    0x5c31b0: 'Sparkles@RBX', 0x5d7c80: '?$FilteredSelection@VPartInstance@RBX@@@RBX', 0x6006a0: 'RelativePanel@RBX',
    0x600730: 'MenuItem@RBX', 0x6007c0: 'ImageButton@RBX', 0x600850: 'TopMenuBar@RBX', 0x6008e0: 'ChatOutput@RBX',
    0x600970: 'ChatWidget@RBX', 0x600a00: 'PercentPanel@RBX', 0x600a90: 'ChatButton@RBX', 0x600b20: 'ScoreHud@RBX',
    0x600bb0: 'HealthHud@RBX', 0x600c40: 'TextDisplay@RBX', 0x600cd0: 'EquationDisplay@RBX', 0x600df0: 'ArrowPanel@RBX',
    0x600e80: 'MenuSpacer@RBX', 0x616410: '?$FilteredSelection@VInstance@RBX@@@RBX',
    0x635150: '?$Value@H$1?sIntValue@RBX@@3PADA@RBX', 0x6353c0: '?$Value@_N$1?sBoolValue@RBX@@3PADA@RBX',
    0x6358a0: '?$Value@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@$1?sStringValue@RBX@@3PADA@RBX',
    0x635ae0: '?$Value@VVector3@G3D@@$1?sVector3Value@RBX@@3PADA@RBX',
    0x635d70: '?$Value@VCoordinateFrame@G3D@@$1?sCFrameValue@RBX@@3PADA@RBX',
    0x635fd0: '?$Value@VColor3@G3D@@$1?sColor3Value@RBX@@3PADA@RBX',
    0x636210: '?$Value@VBrickColor@RBX@@$1?sBrickColorValue@2@3PADA@RBX',
    0x656c90: 'ImageWidget@RBX', 0x656d20: 'ArrowButton@RBX',
}
# Same family, no complete native 2008 declaration of T yet: not built, listed with the header each would need.
BLOCKED = {
    0x40b1e0: ('Reflection@Metadata@1RBX', 'reflection/Metadata.h declares class Reflection in namespace RBX::Metadata; '
               'the 2008 RTTI .?AVReflection@Metadata@0RBX@@ (and this vtable 0080bc54) place it in '
               'RBX::Reflection::Metadata (header-owner proposal)'),
    0x49a0a0: ('Client@Network@RBX', 'native Network/Client.h (RBX::Network::Client, Peer base) does not exist'),
    0x49a310: ('Server@Network@RBX', 'native Network/Server.h (RBX::Network::Server, Peer base) does not exist'),
    0x49e590: ('Replicator@Network@RBX', 'native-headers/Replicator.h is the provisional donor layout (needs '
               'PluginInterface.h; record_native_client_proxy.py: Replicator 2008 layout +0x2b74..+0x2d68 still open)'),
    0x4a1be0: ('ClientProxy@Server@Network@RBX', 'needs the native 2008 Network::Replicator and Server '
               '(record_native_client_proxy.py: blocked)'),
    0x4ac3a0: ('ReplicatorStatsItem@Replicator@Network@RBX', 'nested in the provisional native-headers/Replicator.h'),
    0x4ac4c0: ('Lighting@RBX', 'native v8datamodel/Lighting.h (RBX::Lighting) does not exist'),
    0x635640: ('?$Value@N$1?sDoubleValue@RBX@@3PADA@RBX', 'native v8datamodel/Value.h has no sDoubleValue / '
               'Value<double, sDoubleValue> (it declares Value<float, sFloatValue>; RTTI of vtable 008486b0 is '
               'Value<double, sDoubleValue>)'),
}
assert not set(ROWS) & set(BLOCKED)

original = nb.Original()
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]


def norm(symbol):
    # Strict: the compiled symbols carry the same char-array constness (3PADA) as the original RTTI, so no folding.
    return symbol


# The original stores the per-T vtable at +0x4a and its RTTI names the T of the row.
VTABLE = {}
for address, t in list(ROWS.items()) + [(a, v[0]) for a, v in BLOCKED.items()]:
    body, _, _ = match.target('2008-06', '%08x' % address)
    assert len(body) == 131 and body[0x4a:0x4c] == b'\xc7\x00', ('%08x' % address, len(body))
    vt = struct.unpack_from('<I', body, 0x4c)[0]
    rtti, offset = original.vtable_class(vt)
    assert offset == 0 and rtti.startswith(SCPD + t + '@'), ('%08x' % address, rtti, t)
    VTABLE[address] = (vt, rtti)

# ---- never double-count: rows counted by any other receipt ------------------------------------------------------------
others = {}
for path in sorted((ROOT / 'work/2008-06/shared-layouts').glob('*.json')):
    if path == RECEIPT:
        continue
    try:
        text = path.read_text()
        data = json.loads(text)
    except Exception:
        continue
    counted = set()

    def walk(node):
        if isinstance(node, dict):
            if node.get('exact') is True and isinstance(node.get('address'), str):
                counted.add(node['address'])
            for key in ('exact_function_rows', 'exact', 'exact_rows'):
                if isinstance(node.get(key), list):
                    counted.update(x for x in node[key] if isinstance(x, str))
            for v in node.values():
                walk(v)
        elif isinstance(node, list):
            for v in node:
                walk(v)
    if isinstance(data, dict) and isinstance(data.get('exact_function_rows'), list):
        # a receipt's top-level exact_function_rows is its counted list; its support rows are not counted
        counted.update(x for x in data['exact_function_rows'] if isinstance(x, str))
    else:
        walk(data)
    for address in ROWS:
        if '%08x' % address in counted:
            others.setdefault(address, []).append(path.name)

objects = {k: build('CreatableSharedCount2008' + ('' if k == 'main' else k.title()), src) for k, src in UNITS.items()}

EXTERNAL = {
    # Creatable<Instance>::Deleter::operator(): the catch(...) funclet of every 131-byte shared_count extent; same
    # binding as tests/record_native_geometry_service.py / record_native_hopper.py / record_native_stats_service.py.
    '??RDeleter@?$Creatable@VInstance@RBX@@@RBX@@QAEXPAVInstance@2@@Z': 0x405e30,
}
# sp_counted_impl_pd<T*, Deleter> slot bodies: one ICF-folded body each in the original (identical vtable slots of
# all rows, read below); counted by stats-service / local-backpack / mouse receipts, evidence only here.
FOLDED_SLOTS = {'??_G': 0x415000, '?dispose@': 0x48ee50, '?get_deleter@': 0x5a0460}
SLOT_BASE = {'?destroy@sp_counted_base@detail@boost@@UAEXXZ': 0x405e10}
LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
binding = {}


def slot_address(symbol):
    if symbol in SLOT_BASE:
        return SLOT_BASE[symbol]
    for prefix, address in FOLDED_SLOTS.items():
        if (symbol.startswith(prefix) or symbol.startswith('??_E') and prefix == '??_G') and \
                '?$sp_counted_impl_pd@PAV' in symbol and DLR in symbol:
            return address
    return None


def verify_targets(raw, index, name, body, base, target, record=True):
    sections, symbols, definitions, _ = index
    start, section = definitions[name]
    table = sections[section]
    code = raw[table[4] + start:]
    verified, local = {}, set()
    for i in range(table[7]):
        offset, sym, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        offset -= start
        if not 0 <= offset < len(body):
            continue
        symbol = symbols[sym][0]
        assert kind in (6, 20), (name, symbol, 'unsupported relocation', kind)
        if kind == 20:
            value = (base + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        else:
            value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
        if LOCAL_EH.match(symbol):
            local.add(symbol)
            continue
        hit = original.imported(value)
        if hit is not None:
            assert hit[1] == nb.plain(symbol), (name, symbol, hex(value), hit)
            how = '%s!%s' % hit
        elif symbol.startswith('??_7'):
            rtti, at = original.vtable_class(value)
            assert norm(rtti) == norm('.?AV' + symbol[4:symbol.index('@@6B') + 2]), (name, symbol, hex(value), rtti)
            how = 'vtable RTTI %s offset %#x' % (rtti, at)
        elif symbol.startswith('??_R0') and symbol.endswith('@8'):
            rtti = original.string(value + 8)
            assert norm(rtti) == norm('.' + symbol[5:-2]), (name, symbol, hex(value), rtti)
            how = 'RTTI %s' % rtti
        elif symbol in EXTERNAL:
            assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
            how = 'external'
        elif slot_address(symbol) is not None:
            assert slot_address(symbol) == value, (name, symbol, hex(value))
            how = 'folded slot body'
        else:
            UNBOUND.append('    %r: %#x,   # in %s' % (symbol, value, name[:80]))
            continue
        if record:
            prev = binding.setdefault(symbol, (value, name))
            assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
        verified[symbol] = '%s (%s)' % (hex(value), how)
    return verified, sorted(local)


def compiled_vtable(raw, index, symbol):
    sections, symbols, definitions, _ = index
    start, section = definitions[symbol]
    table = sections[section]
    slots = {}
    for i in range(table[7]):
        offset, sym, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if offset >= start:
            slots[(offset - start) // 4] = symbols[sym][0]
    return [slots[i] for i in range(len(slots))]


rows, slot_rows, vtables, built = [], [], {}, {}
for unit, (obj, _) in objects.items():
    raw = Path(obj).read_bytes()
    index = match._coff_data_index(raw)
    funcs = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    for name, (body, refs) in funcs.items():
        if not (name.startswith('??$?0PAV') and '@shared_count@detail@boost@@QAE@' in name):
            continue
        sections, symbols, definitions, _ = index
        start, section = definitions[name]
        table = sections[section]
        vts = set()
        for i in range(table[7]):
            offset, sym, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
            if start <= offset < start + len(body) and symbols[sym][0].startswith('??_7?$sp_counted_impl_pd@'):
                vts.add(symbols[sym][0])
        assert len(vts) == 1, (name, vts)
        vsym = vts.pop()
        rtti = '.?AV' + vsym[4:vsym.index('@@6B') + 2]
        hits = [a for a, (vt, r) in VTABLE.items() if a in ROWS and norm(r) == norm(rtti)]
        assert len(hits) == 1, (name, rtti, hits)
        address = hits[0]
        assert address not in built, ('built twice', '%08x' % address)
        built[address] = unit
        target, target_refs = match.target('2008-06', '%08x' % address)[:2]
        exact = match.exact_match(target, target_refs, body, refs)
        entry = {'address': '%08x' % address, 'T': ROWS[address], 'unit': unit, 'symbol': name, 'size': len(body),
                 'target_size': len(target), 'exact': exact, 'vtable': '%08x' % VTABLE[address][0]}
        if exact:
            assert set(target_refs) <= set(refs), (name, 'missing original relocation')
            entry['verified_targets'], entry['local_eh'] = verify_targets(raw, index, name, body, address, target)
        elif not DISCOVER:
            raise AssertionError(('not exact', entry['address'], name, len(body), len(target)))
        rows.append(entry)

        # vtable slot by slot (object built from the current headers), then the per-T slot bodies vs the folded ones
        vt = VTABLE[address][0]
        slots = []
        for i, slot in enumerate(compiled_vtable(raw, index, vsym)):
            expect = slot_address(slot)
            value = d(vt + 4 * i)
            assert expect == value, ('%08x' % address, i, slot, hex(value), expect)
            slots.append({'slot': i, 'symbol': slot, 'original': '%08x' % value})
            body_name = '??_G' + slot[4:] if slot.startswith('??_E') else slot
            if body_name in funcs and slot not in SLOT_BASE:
                sbody, srefs = funcs[body_name]
                starget, strefs = match.target('2008-06', '%08x' % value)[:2]
                sexact = match.exact_match(starget, strefs, sbody, srefs)
                srow = {'address': '%08x' % value, 'symbol': body_name, 'exact': sexact, 'counted_here': False}
                if sexact:
                    srow['verified_targets'] = verify_targets(raw, index, body_name, sbody, value, starget)[0]
                slot_rows.append(srow)
        assert len(slots) == 4, ('%08x' % address, slots)
        vtables[entry['address']] = {'vtable': '%08x' % vt, 'slots': slots}

missing = sorted(set(ROWS) - set(built))
if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    print('MISSING', ['%08x' % a for a in missing])
    for r in rows:
        if not r['exact']:
            print('NOT EXACT', r['address'], r['T'], r['size'], r['target_size'])
    sys.exit(0)
assert not UNBOUND, '\n'.join(UNBOUND)
assert not missing, ['%08x' % a for a in missing]

for r in rows:
    a = int(r['address'], 16)
    if a in others:
        r['counted_by_other_receipt'] = others[a]
rows.sort(key=lambda r: r['address'])
exact_rows = sorted(r['address'] for r in rows if r['exact'] and 'counted_by_other_receipt' not in r)
# Slot bodies: one entry per folded address (identical for every T).
slot_evidence = {}
for s in slot_rows:
    e = slot_evidence.setdefault(s['address'], {'address': s['address'], 'exact_for_every_T': True, 'instances': 0,
                                                'counted_here': False, 'example_symbol': s['symbol']})
    e['instances'] += 1
    e['exact_for_every_T'] &= s['exact']
    if not s['exact'] and s['address'] == '0048ee50':
        e['reason'] = ('the original dispose inlines Deleter::operator() (31 bytes: Instance release then the virtual '
                       'deleting call through +0x10); boost dispose here calls the out-of-line 00405e30 (13 bytes)')
per_header = Counter(r['unit'] for r in rows if r['address'] in exact_rows)

sha = nb.sha
receipt = {
    'family': 'boost::detail::shared_count::shared_count<T*, RBX::Creatable<RBX::Instance>::Deleter>(T*, Deleter)',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': {k: v[1] for k, v in objects.items()},
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in [Path(__file__).resolve()] + list(UNITS.values())},
    'objects': {Path(v[0]).name: sha(v[0]) for v in objects.values()},
    'rows': rows,
    'exact_function_rows': exact_rows,
    'counted_by_other_receipts': {'%08x' % a: v for a, v in sorted(others.items())},
    'blocked': {'%08x' % a: {'T': t, 'vtable': '%08x' % VTABLE[a][0], 'needs': why} for a, (t, why) in sorted(BLOCKED.items())},
    'sp_counted_impl_pd_slots': {'vtables': vtables, 'folded_slot_bodies': sorted(slot_evidence.values(), key=lambda x: x['address']),
                                 'note': 'slot bodies are counted by other receipts; evidence only'},
    'exact_per_unit': dict(per_header),
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native Creatable shared_count fan-out: %d distinct function rows exact (%s); %d built rows counted by other '
      'receipts; %d blocked (no complete native T); %d vtables and %d folded slot bodies verified'
      % (len(exact_rows), ', '.join('%s %d' % kv for kv in sorted(per_header.items())), len(others), len(BLOCKED),
         len(vtables), len(slot_evidence)))
