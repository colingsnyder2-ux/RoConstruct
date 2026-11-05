"""Verify the inactive native hit-test filters (2008-06): RBX::Unlocked, RBX::PartByLocalCharacter,
RBX::UnlockedPartByLocalCharacter, RBX::FilterStairs, RBX::FilterCharacterOcclusion (HitTestFilter interface from the
donor util/HitTestFilter.h).

Builds (document-swap flags, VS2008 RTM 21022, /fp:fast for both: the unit's getIsTransparent 006601c0 and the
FilterCharacterOcclusion compare 00660220 are fp:fast code), all from the current native headers:
  * tests/NativeHitTestFilterLayout.cpp   sizeof probes (mov eax, imm32; ret), offset asserts, and the inline
                                          constructors that emit Unlocked::filterResult 00615b60, the implicit
                                          ~PartByLocalCharacter 00615b80 (both MouseCommand-unit COMDATs in the
                                          original) and the Unlocked / UnlockedPartByLocalCharacter vtables;
  * native-classes/Filters.cpp            the unit 006601c0..00660544;
  * Filters.cpp with NATIVE_HIT_FILTERS_PENDING and the declaration-only Humanoid overlay
    (tests/NativeHitTestFilterPendingHumanoid.h copied to out/native-layouts/hit-filters-pending/humanoid/Humanoid.h):
    the PartByLocalCharacter constructor 00660380. Rows of this build are recorded exact=false (pending-build-only)
    and not counted; their targets are kept out of the one-address-per-symbol table.

Every exact row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified: imports by DLL export name, literals by bytes, RTTI and vtables by
original RTTI names, own symbols by the row proven here, and the remaining externals by the EXTERNAL map (evidence
names, or the call-site / registration evidence noted there). Vtables are compared slot by slot from the objects built
with the current headers (never the pending one). Writes work/2008-06/shared-layouts/hit-filters-working.json.
Set NATIVE_HIT_FILTERS_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
"""
import json
import os
import shutil
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match, rebuild  # noqa: E402
import native_bind as nb  # noqa: E402

R = ROOT / 'rebuild/2008-06'
OUT = R / 'out/native-hit-filters'
OUT.mkdir(parents=True, exist_ok=True)
LAYOUT = R / 'tests/NativeHitTestFilterLayout.cpp'
SRC = R / 'native-classes/Filters.cpp'
HDR = R / 'native-headers/v8datamodel/Filters2008.h'
PENDING_HUMANOID = R / 'tests/NativeHitTestFilterPendingHumanoid.h'
PENDING = OUT / 'hit-filters-pending'
(PENDING / 'humanoid').mkdir(parents=True, exist_ok=True)
shutil.copyfile(PENDING_HUMANOID, PENDING / 'humanoid/Humanoid.h')
DISCOVER = bool(os.environ.get('NATIVE_HIT_FILTERS_DISCOVER'))


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeHitTestFilterLayout', LAYOUT, ['/fp:fast'])
unit_obj, unit_flags = build('NativeHitTestFilters', SRC, ['/fp:fast'])
pend_obj, pend_flags = build('NativeHitTestFiltersPending', SRC,
                             ['/fp:fast', '/I' + str(PENDING), '/DNATIVE_HIT_FILTERS_PENDING'])

# ---- layout ---------------------------------------------------------------------------------------
raw = layout_obj.read_bytes()
SIZES = {'nativePartByLocalCharacterSize': 0x14, 'nativeUnlockedPartByLocalCharacterSize': 0x14,
         'nativeFilterStairsSize': 0x0c, 'nativeUnlockedSize': 4, 'nativeFilterCharacterOcclusionSize': 4}
for fn, size in SIZES.items():
    name_, body_, _ = next(x for x in match.coff_functions(raw) if x[0].startswith('?' + fn + '@@'))
    assert body_ == b'\xb8' + struct.pack('<I', size) + b'\xc3', (fn, body_.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]

# PartInstance::getCanCollide 00598d20 has no evidence name: the "CanCollide" property registration 007f4870 passes
# it as the getter (mov edi, 00598d20 at 007f4891) next to the setter 0059dd80 (007f487b) and the name 00833180.
assert original.data(0x7f4891, 5) == b'\xbf' + struct.pack('<I', 0x598d20)
assert original.data(0x7f487b, 5) == b'\xb9' + struct.pack('<I', 0x59dd80)
assert original.data(0x7f48a4, 5) == b'\x68' + struct.pack('<I', 0x833180)
assert original.string(0x833180) == 'CanCollide'

EXTERNAL = {
    '?fromPrimitiveConst@PartInstance@RBX@@SAPBV12@PBVPrimitive@2@@Z': 0x599f80,   # 006601f5, 00660226, 0066032f
    '?isDescendentOf@Instance@RBX@@QBE_NPBV12@@Z': 0x422ae0,                        # 0066034b
    '?getCanCollide@PartInstance@RBX@@QBE_NXZ': 0x598d20,                           # 00660232, 00660356 (see above)
    '??$shared_from@VInstance@RBX@@@RBX@@YA?AV?$shared_ptr@VInstance@RBX@@@boost@@PAVInstance@0@@Z': 0x618a40,  # 006604dd
    '??4shared_count@detail@boost@@QAEAAV012@ABV012@@Z': 0x4025b0,                  # 006604f6
    '__purecall': 0x6a16be,                                                         # HitTestFilter vtable 00843a40 slot 0
    '??0PartByLocalCharacter@RBX@@QAE@PAVInstance@1@@Z': 0x660380,                  # MouseCommand 00616023 (pending row)
}
PENDING_EXTERNAL = {
    '?findLocalCharacter@Players@Network@RBX@@SAPAVModelInstance@3@PBVInstance@3@@Z': 0x49aca0,      # 006603c3
    '?getHeadFromCharacter@Humanoid@RBX@@SAPAVPartInstance@2@PBVModelInstance@2@@Z': 0x5d75a0,         # 00660429
    # ICF: shared_from<ModelInstance> / <PartInstance> fold into the shared_from<Instance> body (006603ce, 00660434).
    '??$shared_from@VModelInstance@RBX@@@RBX@@YA?AV?$shared_ptr@VModelInstance@RBX@@@boost@@PAVModelInstance@0@@Z': 0x618a40,
    '??$shared_from@VPartInstance@RBX@@@RBX@@YA?AV?$shared_ptr@VPartInstance@RBX@@@boost@@PAVPartInstance@0@@Z': 0x618a40,
}

LAYOUT_ROWS = [
    (0x615b60, '?filterResult@Unlocked@RBX@@UBE?AW4Result@HitTestFilter@2@PBVPrimitive@2@@Z'),
    (0x615b80, '??1PartByLocalCharacter@RBX@@QAE@XZ'),
]
UNIT_ROWS = [
    (0x6601f0, '?unlocked@Unlocked@RBX@@SA_NPBVPrimitive@2@@Z'),
    (0x660210, '??0FilterCharacterOcclusion@RBX@@QAE@H@Z'),
    (0x660220, '?filterResult@FilterCharacterOcclusion@RBX@@UBE?AW4Result@HitTestFilter@2@PBVPrimitive@2@@Z'),
    (0x660320, '?filterResult@FilterStairs@RBX@@UBE?AW4Result@HitTestFilter@2@PBVPrimitive@2@@Z'),
    (0x6604a0, '??0FilterStairs@RBX@@QAE@PAVInstance@1@@Z'),
]
NON_EXACT_ROWS = [
    (0x6601c0, '?getIsTransparent@PartInstance@RBX@@QBE_NXZ',
     'inline PartInstance member from native v8datamodel/PartInstance.h (other owner): the 2008 body is '
     '1 - (1 - transparency) * alphaModifier > 0.1f with alphaModifier at +0x328 (Primitive embedded at +0x228); the '
     'header gives (1 - transparency) * alphaModifier > 0.1f with alphaModifier at +0x230 (proposal)'),
    (0x660260, '?filterResult@PartByLocalCharacter@RBX@@UBE?AW4Result@HitTestFilter@2@PBVPrimitive@2@@Z',
     'the original calls getIsTransparent 006601c0 out of line; this /fp:fast build inlines the in-class definition '
     '(115 vs 73 bytes). Built without /fp:fast the call stays out of line and only edx/ecx differ, but then '
     'FilterCharacterOcclusion 00660220 and the 006601c0 body need /fp:fast. Cause not identified'),
    (0x6602b0, '?filterResult@UnlockedPartByLocalCharacter@RBX@@UBE?AW4Result@HitTestFilter@2@PBVPrimitive@2@@Z',
     'inlines PartByLocalCharacter::filterResult in the original; here the inlined getIsTransparent makes it too large '
     'to inline (same cause as 00660260)'),
]
PENDING_ROWS = [
    (0x660380, '??0PartByLocalCharacter@RBX@@QAE@PAVInstance@1@@Z'),
]
PENDING_REASONS = {
    '00660380': 'needs a Humanoid::getHeadFromCharacter(const ModelInstance*) declaration (005d75a0): no native '
                'humanoid/Humanoid.h; built against the declaration-only overlay tests/NativeHitTestFilterPendingHumanoid.h',
}

LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
binding = {}


def norm(symbol):
    return symbol.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


def resolve(obj, rows):
    funcs = match.coff_functions(Path(obj).read_bytes())
    out = []
    for address, key in rows:
        hits = [x for x in funcs if x[0] == key] or [x for x in funcs if x[0].startswith(key) and not LOCAL_EH.match(x[0])]
        if DISCOVER and len(hits) != 1:
            print('UNRESOLVED', '%08x' % address, key[:120], [h[0][:120] for h in hits])
            continue
        assert len(hits) == 1, ('%08x' % address, key, [h[0] for h in hits])
        out.append((address, hits[0][0]))
    return out


def verify(obj, rows, own, strict=True, external=EXTERNAL, record=True):
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
            elif symbol.startswith('__real@'):
                assert original.data(value, len(symbol[7:]) // 2) == bytes.fromhex(symbol[7:])[::-1], (name, symbol, hex(value))
                how = 'constant %s' % symbol[7:]
            elif symbol.startswith('??_7'):
                rtti, at = original.vtable_class(value)
                cls = symbol[4:symbol.index('@@6B') + 2]
                assert norm(rtti) == norm('.?AV' + cls), (name, symbol, hex(value), rtti)
                how = 'vtable RTTI %s offset %#x' % (rtti, at)
            elif symbol in own:
                assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
                how = 'own row'
            elif symbol in external:
                assert external[symbol] == value, (name, symbol, hex(value), hex(external[symbol]))
                how = 'external' + (' (evidence name)' if norm(names.get(value, '')) == norm(symbol) else '')
            else:
                UNBOUND.append("    %r: %#x,   # %s in %s" % (symbol, value, names.get(value, '')[:60], name[:60]))
                continue
            if record:
                prev = binding.setdefault(symbol, (value, name))
                assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
            verified[symbol] = '%s (%s)' % (hex(value), how)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local)})
        result.append(entry)
    return result


layout_rows = resolve(layout_obj, LAYOUT_ROWS)
unit_rows = resolve(unit_obj, UNIT_ROWS)
pend_rows = resolve(pend_obj, PENDING_ROWS)
non_rows = resolve(unit_obj, [(a, k) for a, k, _ in NON_EXACT_ROWS])
own = {}
for address, name in layout_rows + unit_rows:
    own.setdefault(name, address)
strict = not DISCOVER
layout_out = verify(layout_obj, layout_rows, own, strict)
unit_out = verify(unit_obj, unit_rows, own, strict)
pend_out = verify(pend_obj, pend_rows, own, strict=False, external=dict(EXTERNAL, **PENDING_EXTERNAL), record=False)
for row in pend_out:
    row['exact_pending_build_only'] = row['exact']
    row['exact'] = False
    row['reason'] = PENDING_REASONS[row['address']]
non_out = verify(unit_obj, non_rows, own, strict=False)
for row, (_, _, why) in zip(non_out, NON_EXACT_ROWS):
    if row['exact'] and not DISCOVER:
        raise AssertionError('non-exact row unexpectedly exact: %s' % row['address'])
    row['exact'], row['reason'] = False, why
if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for r in pend_out:
        print('PENDING', r['address'], r['exact_pending_build_only'], r['symbol'][:100], r['size'], r['target_size'])
    for g in (layout_out, unit_out):
        for r in g:
            if not r['exact']:
                print('NOT EXACT', r['address'], r['symbol'][:110], r['size'], r['target_size'])
    sys.exit(0)
assert not UNBOUND, '\n'.join(UNBOUND)
assert all(r['exact_pending_build_only'] for r in pend_out), pend_out

# ---- vtables from the objects built with the current headers, slot by slot ---------------------------------
slot_names = dict(EXTERNAL)
slot_names.update(own)
# PartByLocalCharacter::filterResult and UnlockedPartByLocalCharacter::filterResult are non-exact rows: their slots are
# checked by address only (the original slot holds the row address; the body is not claimed).
UNPROVEN_SLOTS = {r[1]: r[0] for r in non_rows}


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


def check_vtable(obj, symbol, address):
    out, bad = [], []
    for i, slot in enumerate(compiled_vtable(obj, symbol)):
        value = d(address + 4 * i)
        if slot in slot_names:
            expect, how = slot_names[slot], 'bound'
        elif slot in UNPROVEN_SLOTS:
            expect, how = UNPROVEN_SLOTS[slot], 'address of a non-exact row'
        else:
            expect, how = None, 'evidence name'
        ok = expect == value if expect is not None else norm(names.get(value, '')) == norm(slot)
        out.append({'slot': i, 'symbol': slot, 'original': '%08x' % value, 'ok': ok, 'how': how})
        if not ok:
            bad.append((i, slot, hex(value)))
    assert not bad, (symbol, bad)
    return out


def bases(vtable):
    hierarchy = d(d(vtable - 4) + 16)
    out = {}
    for i in range(d(hierarchy + 8)):
        bcd = d(d(hierarchy + 12) + 4 * i)
        out.setdefault(original.string(d(bcd) + 8), struct.unpack('<i', original.data(bcd + 8, 4))[0])
    return out


VTABLES = [
    (layout_obj, 'HitTestFilter', 0x843a40, ['HitTestFilter']),
    (layout_obj, 'Unlocked', 0x843a48, ['Unlocked', 'HitTestFilter']),
    (layout_obj, 'UnlockedPartByLocalCharacter', 0x843a50, ['UnlockedPartByLocalCharacter', 'PartByLocalCharacter', 'HitTestFilter']),
    (unit_obj, 'FilterCharacterOcclusion', 0x84c45c, ['FilterCharacterOcclusion', 'HitTestFilter']),
    (unit_obj, 'FilterStairs', 0x84c46c, ['FilterStairs', 'HitTestFilter']),
]
vt, rtti = {}, {}
for obj, cls, address, chain in VTABLES:
    assert original.vtable_class(address) == ('.?AV%s@RBX@@' % cls, 0), (cls, original.vtable_class(address))
    vt[cls] = check_vtable(obj, '??_7%s@RBX@@6B@' % cls, address)
    assert len(vt[cls]) == 1, (cls, vt[cls])
    b = bases(address)
    assert b == {'.?AV%s@RBX@@' % c: 0 for c in chain}, (cls, b)
    rtti[cls] = b
# PartByLocalCharacter's vtable is only emitted by the pending build (its constructor is the pending row); the original
# table is checked by RTTI and its one slot (the 00660260 row address), the compiled one is not claimed.
assert original.vtable_class(0x84c464) == ('.?AVPartByLocalCharacter@RBX@@', 0)
assert d(0x84c464) == 0x660260 and d(0x84c464 + 4) != 0x660260
rtti['PartByLocalCharacter'] = bases(0x84c464)
assert rtti['PartByLocalCharacter'] == {'.?AVPartByLocalCharacter@RBX@@': 0, '.?AVHitTestFilter@RBX@@': 0}

sha = nb.sha
paths = [Path(__file__).resolve(), LAYOUT, HDR, SRC, PENDING_HUMANOID]
objects = [layout_obj, unit_obj, pend_obj]
groups = {'layout': layout_out, 'unit': unit_out, 'not_exact': non_out, 'pending': pend_out}
exact = sorted({r['address'] for g in (layout_out, unit_out) for r in g if r['exact']})
PROPOSALS = {
    'humanoid/Humanoid.h (new native header, Humanoid owner)':
        'static PartInstance* getHeadFromCharacter(const ModelInstance* character); /*005d75a0*/ in class Humanoid : '
        'DescribedCreatable<Humanoid, Instance, sHumanoid> (extern char sHumanoid[]; RTTI 3PADA). With it, the '
        'PartByLocalCharacter constructor 00660380 is exact (pending build)',
    'v8datamodel/PartInstance.h (PartInstance owner)':
        'getTransparencyUi() { return 1.0f - (1.0f - transparency) * alphaModifier; } (getIsTransparent 006601c0: '
        'fld1; fld st0; fsub [+0x1e8]; fmul [+0x328]; fsubp; > 0.1f) with alphaModifier at +0x328, i.e. after the '
        'Primitive embedded at +0x228 (already proposed)',
}
receipt = {
    'class': 'RBX::HitTestFilter family (Unlocked, PartByLocalCharacter, UnlockedPartByLocalCharacter, FilterStairs, '
             'FilterCharacterOcclusion)',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': {'layout': layout_flags, 'unit': unit_flags, 'pending': pend_flags},
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in objects},
    'layout': {'PartByLocalCharacter': '0x14: character shared_ptr +0x04, head shared_ptr +0x0c (ctor 00660380)',
               'UnlockedPartByLocalCharacter': '0x14, no own fields (vtable 00843a50)',
               'FilterStairs': '0x0c: model shared_ptr<Instance> +0x04 (ctor 006604a0)',
               'Unlocked': '4', 'FilterCharacterOcclusion': '4'},
    'rows': groups,
    'exact_function_rows': exact,
    'vtables': vt,
    'rtti_bases': rtti,
    'proposals': PROPOSALS,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/hit-filters-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native hit filters: %d distinct function rows exact (layout %d, unit %d); %d pending-build-only rows '
      '(%d exact there) and %d non-exact rows not counted; targets, %d vtables and RTTI verified'
      % (len(exact), sum(r['exact'] for r in layout_out), sum(r['exact'] for r in unit_out),
         len(pend_out), sum(r['exact_pending_build_only'] for r in pend_out), len(non_out), len(vt)))
