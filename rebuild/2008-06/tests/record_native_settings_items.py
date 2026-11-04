"""Verify the inactive native RBX::GameSettings and RBX::DebugSettings recovery (2008-06).

Both are GlobalSettings items (GlobalSettingsItem<Class, sClass>, as native-classes/NetworkSettings.cpp and
tests/record_native_services.py); each unit defines the GlobalSettingsItem constructor/destructor/sing locally.
Builds (document-swap flags, VS2008 RTM 21022), all from the current native headers unless noted:
  * tests/NativeSettingsItemsLayout.cpp   sizeof/offset probes (mov eax, imm32; ret) and the explicit
                                          Creatable<Instance>::create<DebugSettings> instantiation (00407820);
  * native-classes/GameSettings.cpp       the GameSettings unit 005bf0d0..005bf7e0, class name/descriptor
                                          (0044a0e0/0044a8b0), the 5 property initializers 007f5560..007f5620 with their
                                          atexit functions, and GlobalSettingsItem<GameSettings>::singleton 0044bee0 with
                                          the creator 0044bdc0 / shared_ptr constructor 0044b850 it emits;
  * native-classes/DebugSettings.cpp      the DebugSettings unit (lifecycle, descriptor plumbing, accessors over its own
                                          fields and over PartInstance / Debugable statics, EnumDesc<ErrorReporting> and
                                          EnumDesc<Debugable::AssertAction>, 27 property initializers and atexits);
  * DebugSettings.cpp with NATIVE_DEBUGSETTINGS_PENDING against generated copies under
    out/native-layouts/settings-items-pending/ of the donor v8world/World.h (PROPOSAL_WORLD: World::EThrottle and its
    static) and the donor v8datamodel/Camera.h (2008 class-name declaration, needed by the native ModelInstance.h):
    the EThrottle and ShowModelCoords accessors, EnumDesc<World::EThrottle> and the PhysicsEnviromentalThrottle
    initializer. Rows exact only in this build are recorded exact=false (pending-build-only) and not counted.

Every exact row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified: imports by DLL export name, string literals by bytes, type descriptors and
vtables by original RTTI names, own symbols by the row proven here, folded bodies by their address, and the remaining
externals by the EXTERNAL / DATA maps in tests/record_native_settings_items_maps.py (call sites read in the original
disassembly). A symbol binds to one address across all rows. Vtables are compared slot by slot from the objects built
with the current headers (never the pending one). Writes work/2008-06/shared-layouts/settings-items-working.json.
Set NATIVE_SETTINGS_ITEMS_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
"""
import json
import os
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match, rebuild  # noqa: E402
import native_bind as nb  # noqa: E402
from record_native_settings_items_maps import (EXTERNAL, DATA, FOLDED, UNPROVEN, NOT_ATTEMPTED,  # noqa: E402
                                               GAME_ROWS, DEBUG_ROWS, DEBUG_PENDING_ROWS, LAYOUT_ROWS,
                                               PROPOSAL_WORLD_ANCHOR, PROPOSAL_WORLD, CAMERA_FIX, VTABLES)

R = ROOT / 'rebuild/2008-06'
OUT = nb.OUT
OUT.mkdir(parents=True, exist_ok=True)
LAYOUT = R / 'tests/NativeSettingsItemsLayout.cpp'
GAME_SRC = R / 'native-classes/GameSettings.cpp'
DEBUG_SRC = R / 'native-classes/DebugSettings.cpp'
GAME_H = R / 'native-headers/v8datamodel/GameSettings.h'
DEBUG_H = R / 'native-headers/v8datamodel/DebugSettings.h'
MAPS = R / 'tests/record_native_settings_items_maps.py'
DISCOVER = bool(os.environ.get('NATIVE_SETTINGS_ITEMS_DISCOVER'))

# Generated header copies for the pending build only (shared headers are not edited).
pending = OUT / 'settings-items-pending'
(pending / 'v8world').mkdir(parents=True, exist_ok=True)
(pending / 'v8datamodel').mkdir(parents=True, exist_ok=True)
text = (ROOT / 'tools/rbxgs/Client/App/include/v8world/World.h').read_text()
assert text.count(PROPOSAL_WORLD_ANCHOR) == 1
(pending / 'v8world/World.h').write_text(text.replace(PROPOSAL_WORLD_ANCHOR, PROPOSAL_WORLD_ANCHOR + PROPOSAL_WORLD))
text = (ROOT / 'tools/rbxgs/Client/App/include/v8datamodel/Camera.h').read_text()
for old, new in CAMERA_FIX:
    assert text.count(old) == 1, old
    text = text.replace(old, new)
(pending / 'v8datamodel/Camera.h').write_text(text)


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeSettingsItemsLayout', LAYOUT)
game_obj, game_flags = build('NativeGameSettings', GAME_SRC)
debug_obj, debug_flags = build('NativeDebugSettings', DEBUG_SRC)
debugp_obj, debugp_flags = build('NativeDebugSettingsPending', DEBUG_SRC, ['/I' + str(pending), '/DNATIVE_DEBUGSETTINGS_PENDING'])

# ---- layout ---------------------------------------------------------------------------------------
raw = layout_obj.read_bytes()
for prefix, value in (('?nativeGameSettingsSize@@', 0x13c), ('?nativeDebugSettingsSize@@', 0x138)):
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    assert body == b'\xb8' + struct.pack('<I', value) + b'\xc3', (prefix, body.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}


def norm(symbol):
    return symbol.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
binding = {}   # symbol -> (address, row) for the one-address-per-symbol check


def resolve(obj, rows):
    funcs = match.coff_functions(Path(obj).read_bytes())
    out = []
    for address, key in rows:
        hits = [x for x in funcs if x[0] == key] or [x for x in funcs if x[0].startswith(key) and not LOCAL_EH.match(x[0])]
        assert len(hits) == 1, (hex(address), key, [h[0] for h in hits])
        out.append((address, hits[0][0]))
    return out


def verify(obj, rows, own, strict=True):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    result = []
    for address, name in rows:
        body, refs = bodies[name]
        target, target_refs, _ = match.target('2008-06', '%08x' % address)
        exact = match.exact_match(target, target_refs, body, refs)
        entry = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target), 'exact': exact}
        if not exact:
            assert not strict, (name, entry['address'], len(body), len(target))
            result.append(entry)
            continue
        start, section = definitions[name]
        table = sections[section]
        code = raw[table[4] + start:]
        verified, local = {}, set()
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
            if LOCAL_EH.match(symbol):
                local.add(symbol)
                continue
            hit = original.imported(value)
            if hit is not None:
                assert hit[1] == nb.plain(symbol), (name, symbol, hex(value), hit)
                how = '%s!%s' % hit
            elif symbol.startswith('??_C@'):
                pos, at = definitions[symbol]
                literal = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
                assert original.data(value, len(literal)) == literal, (name, symbol, hex(value))
                how = 'literal %r' % literal[:-1].decode()
            elif symbol.startswith('??_R0') and symbol.endswith('@8'):
                rtti = original.string(value + 8)
                assert norm(rtti) == norm('.' + symbol[5:-2]), (name, symbol, hex(value), rtti)
                how = 'RTTI %s' % rtti
            elif symbol.startswith('??_7'):
                rtti, at = original.vtable_class(value)
                cls = symbol[4:symbol.index('@@6B') + 2]
                assert norm(rtti) == norm('.?AV' + cls), (name, symbol, hex(value), rtti)
                how = 'vtable RTTI %s offset %#x' % (rtti, at)
            elif symbol.startswith('??_E') and ('??_G' + symbol[4:]) in own:
                assert own['??_G' + symbol[4:]] == value, (name, symbol, hex(value))
                how = 'own row (??_G)'
            elif symbol.startswith('??_E') and ('??_G' + symbol[4:]) in FOLDED:
                assert FOLDED['??_G' + symbol[4:]] == value, (name, symbol, hex(value))
                how = 'folded (??_G)'
            elif symbol in own:
                assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
                how = 'own row'
            elif symbol in FOLDED:
                assert FOLDED[symbol] == value, (name, symbol, hex(value))
                how = 'folded'
            elif symbol in DATA:
                assert DATA[symbol] == value, (name, symbol, hex(value))
                how = 'data'
            elif symbol in UNPROVEN:
                assert UNPROVEN[symbol] == value, (name, symbol, hex(value))
                how = 'call target of a non-exact row'
            elif symbol in EXTERNAL:
                assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
                how = 'external' + (' (evidence name)' if norm(names.get(value, '')) == norm(symbol) else '')
            elif symbol.startswith('??_B?1??') or symbol.startswith('?$S') or '?$TSS' in symbol or symbol.startswith('?flag@') \
                    or symbol.startswith('?foo@') or symbol.startswith('?n@') or symbol.startswith('?root@'):
                how = 'local static'
            else:
                UNBOUND.append("    %r: %#x,   # %s in %s" % (symbol, value, names.get(value, '')[:60], name[:60]))
                continue
            prev = binding.setdefault(symbol, (value, name))
            assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
            verified[symbol] = '%s (%s)' % (hex(value), how)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local)})
        result.append(entry)
    return result


layout_rows = resolve(layout_obj, LAYOUT_ROWS)
game_rows = resolve(game_obj, GAME_ROWS)
debug_rows = resolve(debug_obj, DEBUG_ROWS)
debugp_rows = resolve(debugp_obj, DEBUG_PENDING_ROWS)
own = {}
for address, name in layout_rows + game_rows + debug_rows:
    own.setdefault(name, address)
own_pending = dict(own)
for address, name in debugp_rows:
    own_pending.setdefault(name, address)
strict = not DISCOVER
layout_out = verify(layout_obj, layout_rows, own, strict)
game_out = verify(game_obj, game_rows, own, strict)
debug_out = verify(debug_obj, debug_rows, own, strict)
debugp_out = verify(debugp_obj, debugp_rows, own_pending, strict)
for row in debugp_out:  # exact only under NATIVE_DEBUGSETTINGS_PENDING with generated header copies: not counted
    row['exact'] = False
    row['exact_pending_build_only'] = True
if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for g in (layout_out, game_out, debug_out, debugp_out):
        for r in g:
            if not r['exact'] and not r.get('exact_pending_build_only'):
                print('NOT EXACT', r['address'], r['symbol'][:100], r['size'], r['target_size'])
    sys.exit(0)
assert not UNBOUND, '\n'.join(UNBOUND)

# ---- vtables from the objects built with the current headers, slot by slot ---------------------------------
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
slot_names = {}
for table_ in (own, FOLDED, EXTERNAL, UNPROVEN):
    for k, v in table_.items():
        slot_names.setdefault(k, v)


def compiled_vtable(obj, symbol):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    start, section = definitions[symbol]
    table = sections[section]
    slots = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if offset >= start:
            slots[(offset - start) // 4] = symbols[index][0]
    return [slots[i] for i in range(len(slots))]


def check_vtable(obj, symbol, address, reference=None, own_class=''):
    """Each slot holds the address bound to its symbol, the evidence name, or (for an inherited slot) the same
    address as the base class's vtable at `reference`."""
    out, bad = [], []
    for i, slot in enumerate(compiled_vtable(obj, symbol)):
        value = d(address + 4 * i)
        if slot.startswith('??_E') and '??_G' + slot[4:] in slot_names:
            expect, how = slot_names['??_G' + slot[4:]], 'bound (??_G)'
        else:
            expect, how = slot_names.get(slot), 'bound'
        ok = expect == value if expect is not None else norm(names.get(value, '')) == norm(slot)
        if expect is None:
            how = 'evidence name'
        if not ok and reference is not None:
            cls = slot.split('@')[1] if slot.startswith('?') and not slot.startswith('??') else ''
            if cls != own_class and value == d(reference + 4 * i):
                ok, how = True, 'inherited (same slot of the base vtable %08x)' % reference
        out.append({'slot': i, 'symbol': slot, 'original': '%08x' % value, 'ok': ok, 'how': how})
        if not ok:
            bad.append((i, slot, hex(value)))
    assert not bad, (symbol, bad)
    return out


# Instance's own vtable 0082d884 (Instance constructor 0055b7e0) is the reference for inherited slots.
assert original.vtable_class(0x82d884) == ('.?AVInstance@RBX@@', 0)
objs = {'game': game_obj, 'debug': debug_obj}
vt = {}
for key, unit, symbol, address, own_class, reference in VTABLES:
    rtti, at = original.vtable_class(address)
    assert at == 0 and norm(rtti) == norm('.?AV' + symbol[4:symbol.index('@@6B') + 2]), (key, hex(address), rtti)
    vt[key] = check_vtable(objs[unit], symbol, address, reference, own_class)
assert vt['GameSettings'][2]['original'] == vt['DebugSettings'][2]['original'] == '00409e60'  # GlobalSettings::Item::askAddChild

# ---- RTTI bases, allocation sizes and strings ------------------------------------------------------------------


def bases(vtable):
    hierarchy = d(d(vtable - 4) + 16)
    out = {}
    for i in range(d(hierarchy + 8)):
        bcd = d(d(hierarchy + 12) + 4 * i)
        out.setdefault(original.string(d(bcd) + 8), struct.unpack('<i', original.data(bcd + 8, 4))[0])
    return out


for vtable, cls in ((0x838774, 'GameSettings'), (0x82e6e4, 'DebugSettings')):
    assert original.vtable_class(vtable) == ('.?AV%s@RBX@@' % cls, 0)
    b = bases(vtable)
    assert b['.?AVService@RBX@@'] == 0x130, b
    assert b['.?AV?$GlobalSettingsItem@V%s@RBX@@$1?s%s@2@3QBDB@RBX@@' % (cls, cls)] == 0, b
for factory, size, ctor in ((0x44bdc0, 0x13c, 0x5bf680), (0x407820, 0x138, 0x565ac0)):
    body, _, _ = match.target('2008-06', '%08x' % factory)
    at = body.index(b'\x68' + struct.pack('<I', size))
    call = body.index(b'\xe8', at + 5)
    while (factory + call + 5 + struct.unpack_from('<i', body, call + 1)[0]) & 0xffffffff != ctor:
        call = body.index(b'\xe8', call + 1)
for address, text in ((0x838478, 'GameSettings'), (0x82dfb8, 'DebugSettings'), (0x8387b4, 'Game Options'),
                      (0x8243a0, 'Diagnostics')):
    assert original.string(address) == text, (hex(address), text)

sha = nb.sha
paths = [Path(__file__).resolve(), MAPS, LAYOUT, GAME_H, DEBUG_H, GAME_SRC, DEBUG_SRC]
objects = [layout_obj, game_obj, debug_obj, debugp_obj]
groups = {'layout': layout_out, 'game': game_out, 'debug': debug_out, 'debug_pending': debugp_out}
exact_rows = sorted({r['address'] for g in (layout_out, game_out, debug_out) for r in g if r['exact']})
receipt = {
    'class': 'RBX::GameSettings, RBX::DebugSettings', 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': {'layout': layout_flags, 'game': game_flags, 'debug': debug_flags, 'debug_pending': debugp_flags},
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in objects},
    'layout': {'GameSettings': '0x13c (0044bdc0); GlobalSettingsItem<GameSettings, sGameSettings>, Service +0x130; '
                               'chatHistory +0x130, chatScrollLength +0x134, soundEnabled +0x138, softwareSound +0x139, '
                               'funnyPhysics +0x13a; class name "GameSettings" (const char[] 00838478)',
               'DebugSettings': '0x138 (00407820); GlobalSettingsItem<DebugSettings, sDebugSettings>, Service +0x130; '
                                'stackTracingEnabled +0x130, ioEnabled +0x131, validatingDebug +0x132, soundWarnings '
                                '+0x133, errorReporting +0x134; class name "DebugSettings" (const char[] 0082dfb8)'},
    'rows': groups,
    'exact_function_rows': exact_rows,
    'vtables': vt,
    'pending_note': 'pending rows are exact only with generated copies of the donor v8world/World.h (PROPOSAL_WORLD) '
                    'and v8datamodel/Camera.h (CAMERA_FIX) under out/native-layouts/settings-items-pending.',
    'not_attempted': NOT_ATTEMPTED,
    'proposal_world_h': PROPOSAL_WORLD,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/settings-items-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native GameSettings/DebugSettings: %d distinct function addresses exact (layout %d, game %d, debug %d); '
      '%d pending-build-only rows not counted; targets and %d vtables verified'
      % (len(exact_rows), sum(r['exact'] for r in layout_out), sum(r['exact'] for r in game_out),
         sum(r['exact'] for r in debug_out), len(debugp_out), len(vt)))
