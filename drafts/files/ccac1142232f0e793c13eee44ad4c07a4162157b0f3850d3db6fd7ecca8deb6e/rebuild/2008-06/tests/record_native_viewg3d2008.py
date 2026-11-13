"""Verify the inactive native RBX::ViewNew::ViewG3D (2008-06).

Builds (VS2008 RTM 21022, document-swap flags + /fp:fast, like the ViewBase / ViewRbxGfx units of
tests/record_native_render_scene.py), all from the current native headers:
  * tests/NativeViewG3D2008Layout.cpp   sizeof/offset probes (mov eax, imm32; ret);
  * native-classes/ViewG3D2008.cpp      ViewG3D::invalidateLighting 004db610 and ViewG3D::render 004db690.

native-headers/ViewG3D2008/ViewG3D2008.h is a new path: no donor or native header of that name exists, so it shadows
nothing. Every exact row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the
address the original instruction uses and verified (imports by DLL export name, constants by bytes, the remaining
externals by an explicit map with the call site evidence). A symbol binds to one address across all rows. The ViewG3D
vtable is emitted only with its ctor / dtor (not built), so it is checked against the original by RTTI and slot
addresses only. Slots 2, 3, 4, 6, 7, 8 are ICF bodies shared with ViewRbxGfx (counted or folded by
record_native_render_scene.py) and are never counted here. Writes work/2008-06/shared-layouts/viewg3d2008-working.json.
Set NATIVE_VIEWG3D_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
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

R = ROOT / 'rebuild/2008-06'
OUT = nb.OUT
OUT.mkdir(parents=True, exist_ok=True)
LAYOUT = R / 'tests/NativeViewG3D2008Layout.cpp'
UNIT = R / 'native-classes/ViewG3D2008.cpp'
HEADERS = [R / 'native-headers/ViewG3D2008/ViewG3D2008.h']
DISCOVER = bool(os.environ.get('NATIVE_VIEWG3D_DISCOVER'))


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeViewG3D2008Layout', LAYOUT, ['/fp:fast'])
OBJ, FLAGS = build('NativeViewG3D2008', UNIT, ['/fp:fast'])

# ---- layout -------------------------------------------------------------------------------------------------------
# Evidence: new 0x6c at 0045d86a before the ctor 004dbbe0 (checked below); ctor 004dbc40 stores NULL to +0x48 and
# constructs the map with lea ecx, [esi+0x4c] (004dbc50) through _Tree(const less&, const allocator&) 00446110, which
# fills the head at +0x18 and size at +0x1c (0x20 bytes); its _Buynode 0056d3d0 allocates 0x18-byte nodes (12 bytes of
# links + an 8-byte value + color / isnil bytes at +0x14 / +0x15: 0x446159 writes isnil at node +0x15); the dtor
# 004dc270 destroys +0x4c (00553d80) then releases +0x48 through ReferenceCountedObject; lightingValid +0x44 and
# dataModel +0x14 come from ViewBase (render_scene receipt); dataModel->workspace is +0x204 (render 004db6b4). The map's
# key / mapped types are not derived, so it is not declared natively and only +0x48 and the inherited offsets are
# probed; the 0x6c size and the map facts are asserted on the original bytes below.
raw = layout_obj.read_bytes()
SIZES = {
    'viewG3DSky': 0x48,
    'viewBaseLightingValid': 0x44, 'viewBaseDataModel': 0x14, 'dataModelWorkspace': 0x204,
}
for fn, size in SIZES.items():
    name_, body_, _ = next(x for x in match.coff_functions(raw) if x[0].startswith('?native' + fn + '@@'))
    assert body_ == b'\xb8' + struct.pack('<I', size) + b'\xc3', (fn, body_.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]

EXTERNAL = {
    # header-inline G3D COMDAT; the original calls the ICF copy at 0045ad90 (evidence name) from 004db636
    '?ReferenceCountedObject_zeroWeakPointers@ReferenceCountedObject@G3D@@QAEXXZ': 0x45ad90,
}
DATA = {}
LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
binding = {}

ROWS = [
    (0x4db610, '?invalidateLighting@ViewG3D@ViewNew@RBX@@EAEX_N@Z'),
    (0x4db690, '?render@ViewG3D@ViewNew@RBX@@UAEXPAVRenderDevice@G3D@@@Z'),
]
BLOCKED = {
    '004dbbe0': 'ViewG3D ctor: new 0x10 ViewNew::MaterialFactory (ctor 004f0920; the class is not declared, see the '
                'render-scene receipt proposal), the Lighting service accessor 004b3870 and the Lighting-changed / '
                'descendant-added signal descriptors 0097a88c / 00973e40 with their slot ctors 004dbaa0 / 004dbb40 and '
                'connect calls 004d8390 / 004a3340, plus the workspace descendant visit 004d7c00 (Lighting / Instance / '
                'reflection owners)',
    '004dc270': 'ViewG3D dtor: the ServiceProvider call 004b3380 on dataModel and the seven ViewNew mesh-cache flushes '
                '004db130 / 004db040 / 004daf50 / 004e5670 / 004db310 / 004db220 / 004db400 (shared with ~ViewRbxGfx '
                '004db4f0; not declared in any native header, names not derived)',
    '004dc340': 'ViewG3D ??_G: emitted only with the vtable, i.e. with the ctor or dtor (both blocked)',
    '004dbf00': 'ViewG3D::suppressSkybox: Lighting service fields (+0x130 sky parameters, +0x228 / +0x234 Color3, '
                '+0x244 Color4) and the LightingParameters builder 004d7020 (Lighting owner)',
    '004dc040': 'ViewG3D::updateLighting: as suppressSkybox, plus +0x240 sky-enabled bool, +0x2d4 sky parameters, the '
                'Sky factory 005ebbb0 and the GImage::Error / ... handlers printing 00826dc4 / 00826dac (Lighting owner)',
}
SHARED_SLOTS = {2: 0x64a390, 3: 0x4d76d0, 4: 0x4db660, 6: 0x4d7370, 7: 0x4db6f0, 8: 0x4db7c0}


def target_of(address):
    body, refs, _ = match.target('2008-06', '%08x' % address)
    return body, refs


def resolve(obj, rows):
    funcs = match.coff_functions(Path(obj).read_bytes())
    out = []
    for address, key in rows:
        hits = [x for x in funcs if x[0] == key]
        assert len(hits) == 1, ('%08x' % address, key, [h[0] for h in funcs if 'ViewG3D' in h[0]])
        out.append((address, hits[0][0]))
    return out


def verify(obj, rows, own, strict=True):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    result = []
    for address, name in rows:
        body, refs = bodies[name]
        target, target_refs = target_of(address)
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
            elif symbol.startswith('__real@'):
                assert original.data(value, len(symbol[7:]) // 2) == bytes.fromhex(symbol[7:])[::-1], (name, symbol, hex(value))
                how = 'constant %s' % symbol[7:]
            elif symbol in own:
                assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
                how = 'own row'
            elif symbol in DATA:
                assert DATA[symbol] == value, (name, symbol, hex(value))
                how = 'data'
            elif symbol in EXTERNAL:
                assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
                how = 'external' + (' (evidence name)' if names.get(value, '') == symbol else '')
            else:
                UNBOUND.append("    %r: %#x,   # %s in %s" % (symbol, value, names.get(value, '')[:60], name[:60]))
                continue
            prev = binding.setdefault(symbol, (value, name))
            assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
            verified[symbol] = '%s (%s)' % (hex(value), how)
        entry.update({'verified_targets': verified, 'local': sorted(local)})
        result.append(entry)
    return result


resolved = resolve(OBJ, ROWS)
own = {name: address for address, name in resolved}
rows = verify(OBJ, resolved, own, strict=not DISCOVER)
if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for r in rows:
        if not r['exact']:
            print('NOT EXACT', r['address'], r['symbol'][:110], r['size'], r['target_size'])
    sys.exit(0)
assert not UNBOUND, '\n'.join(UNBOUND)

# ---- original structure: vtable, RTTI, allocation, members ----------------------------------------------------------


def bases(vtable):
    hierarchy = d(d(vtable - 4) + 16)
    out = {}
    for i in range(d(hierarchy + 8)):
        bcd = d(d(hierarchy + 12) + 4 * i)
        out.setdefault(original.string(d(bcd) + 8), struct.unpack('<i', original.data(bcd + 8, 4))[0])
    return out


VTABLE = 0x826e04
assert original.vtable_class(VTABLE) == ('.?AVViewG3D@ViewNew@RBX@@', 0)
assert bases(VTABLE) == {'.?AVViewG3D@ViewNew@RBX@@': 0, '.?AVViewBase@RBX@@': 0}
slots = {i: d(VTABLE + 4 * i) for i in range(11)}
assert slots[0] == 0x4dc340 and slots[1] == 0x4db690 and slots[5] == 0x4dbf00 and slots[9] == 0x4dc040
assert slots[10] == 0x4db610
for slot, address in SHARED_SLOTS.items():                   # ICF bodies shared with ViewRbxGfx: never counted here
    assert slots[slot] == address == d(0x826c70 + 4 * slot), slot
vtable_check = [{'slot': i, 'original': '%08x' % a,
                 'row': ('%08x' % a) in {r['address'] for r in rows if r['exact']},
                 'shared_with_ViewRbxGfx': i in SHARED_SLOTS} for i, a in slots.items()]
# Slot order comes from ViewBase2008.h; the exact render row calls slot 9 (updateLighting, [eax+0x24]).


def calls(function):
    body, _, _ = match.target('2008-06', '%08x' % function)
    return [(function + i + 5 + struct.unpack_from('<i', body, i + 1)[0]) & 0xffffffff
            for i in range(len(body) - 4) if body[i] == 0xe8], body


def alloc_before(function, size, callee):
    body, _, _ = match.target('2008-06', '%08x' % function)
    at = body.index(b'\x68' + struct.pack('<I', size)) if size > 0x7f else body.index(b'\x6a' + bytes([size]))
    call = body.index(b'\xe8', at)
    while (function + call + 5 + struct.unpack_from('<i', body, call + 1)[0]) & 0xffffffff != callee:
        call = body.index(b'\xe8', call + 1)
    return at


alloc_before(0x45d850, 0x6c, 0x4dbbe0)                       # new ViewG3D
ctor_calls, ctor = calls(0x4dbbe0)
assert 0x4d8a20 in ctor_calls and 0x446110 in ctor_calls      # ViewBase ctor, map _Tree ctor
assert bytes.fromhex('c706046e8200') in ctor                  # mov [esi], 00826e04
assert bytes.fromhex('c7464800000000') in ctor                # +0x48 = NULL
assert bytes.fromhex('8d4e4c') in ctor                       # lea ecx, [esi+0x4c] (map ctor this)
dtor_calls, dtor = calls(0x4dc270)
assert 0x553d80 in dtor_calls and dtor_calls[-1] == 0x4d8920  # ~map, then ~ViewBase last
assert bytes.fromhex('8d4e4c') in dtor                        # lea ecx, [esi+0x4c]
assert match.target('2008-06', '0056d3d0')[0].startswith(b'\x6a\x18')        # _Buynode: new 0x18
assert 0x56d3d0 in calls(0x446110)[0] and bytes.fromhex('c6401501') in match.target('2008-06', '00446110')[0]
assert 0x553ca0 in calls(0x553d80)[0]                       # _Tree dtor -> erase
assert match.target('2008-06', '004dc340')[0].startswith(bytes.fromhex('568bf1e8'))   # ??_G -> dtor
assert calls(0x4dc340)[0][0] == 0x4dc270
assert struct.unpack('<d', original.data(0x826938, 8))[0] == struct.unpack('<f', struct.pack('<f', 0.1))[0]

sha = nb.sha
paths = [Path(__file__).resolve(), LAYOUT, UNIT] + HEADERS
exact = sorted({r['address'] for r in rows if r['exact']})
PROPOSALS = {
    'ViewNew mesh owners (ViewNew/*.h), FYI': 'the ViewG3D and ViewRbxGfx dtors call seven static cache flushes '
        '004db130 / 004db040 / 004daf50 / 004e5670 / 004db310 / 004db220 / 004db400 (each locks a static cache object, '
        'e.g. 0097272c via call_once 00557330 / init 004d9810, and empties its two maps); declaring them (names and '
        'classes are not derived here) unblocks both dtors and their ??_G rows.',
    'Lighting owner, FYI': 'ViewG3D::suppressSkybox 004dbf00 / updateLighting 004dc040 read the Lighting service '
        '(004b3870 on the DataModel): +0x130 passed to 004d7020 to build the LightingParameters by value, +0x228 / '
        '+0x234 Color3 (presetLighting arguments), +0x240 bool (sky enabled), +0x244 Color4 (copied to the scene '
        'clear colour +0x14), +0x2d4 the sky parameters passed to the Sky factory 005ebbb0.',
    'ViewNew::MaterialFactory (carried over from render-scene)': 'the ViewG3D ctor also needs it (new 0x10, ctor '
        '004f0920, dtor 004d7460).',
}
receipt = {
    'class': 'RBX::ViewNew::ViewG3D',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': {'layout': layout_flags, 'unit': FLAGS},
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in (layout_obj, OBJ)},
    'layout': {k: hex(v) for k, v in SIZES.items()},
    'rows': rows,
    'exact_function_rows': exact,
    'vtable': vtable_check,
    'notes': ['+0x4c map: only the ctor (00446110) and dtor (00553d80 -> erase 00553ca0) touch it in 2008-06, so its '
              'key / mapped types are not derived and it is NOT declared (no invented types); the native class is '
              'declared through +0x4b only (sizeof 0x4c vs the original new 0x6c). Its size evidence (new 0x6c, lea '
              '[esi+0x4c], 0x18-byte _Buynode) is asserted on the original bytes only. The rows do not touch it.'],
    'blocked': BLOCKED,
    'proposals': PROPOSALS,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/viewg3d2008-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native ViewG3D: %d distinct function rows exact (%s); %d blocked rows not built; targets verified; '
      'vtable 00826e04 checked by RTTI and slot addresses (6 ICF slots shared with ViewRbxGfx not counted)'
      % (len(exact), ', '.join(exact), len(BLOCKED)))
