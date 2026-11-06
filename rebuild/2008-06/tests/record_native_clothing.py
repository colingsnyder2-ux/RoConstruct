"""Verify the inactive native CharacterAppearance / Clothing / Shirt / Pants / ShirtGraphic / Skin recovery.

Builds tests/NativeClothingLayout.cpp and native-classes/Clothing.cpp twice:
  * base: current shared headers (declaration-only Humanoid/Players overlays from tests/NativeClothing*.h);
  * pending: additionally NATIVE_CLOTHING_PENDING with generated copies of the shared headers carrying the
    proposed declarations (PartInstance::outfitChanged, a second GetSet bool virtual), under out/: only
    Clothing::apply 005d3a30 now (the setters 005d40c0/005d4120, ShirtGraphic::apply 005d4240 and
    findFirstChildOfType<Decal> 005d41a0 are base rows against the native Decal.h / Instance.h / reflection).
Each listed COFF function must be byte-identical to the original (relocations masked), and every relocation
target is bound to the address the original instruction uses: imports by name, string literals by bytes,
RTTI and vtables by class name, listed externals by address, and every other symbol consistently (the same
symbol binds the same address in every row and vtable slot). Writes
work/2008-06/shared-layouts/clothing-working.json.
"""
import hashlib
import json
import re
import shutil
import struct
import subprocess
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
SOURCE = R / 'native-classes/Clothing.cpp'
HEADER = R / 'native-headers/v8datamodel/Clothing.h'
LAYOUT = R / 'tests/NativeClothingLayout.cpp'
HUMANOID = R / 'tests/NativeClothingHumanoid.h'
PLAYERS = R / 'tests/NativeClothingPlayers.h'

overlay = OUT / 'clothing-overlay'
for dest, src in (('humanoid/Humanoid.h', HUMANOID), ('Network/Players.h', PLAYERS)):
    (overlay / dest).parent.mkdir(parents=True, exist_ok=True)
    shutil.copyfile(src, overlay / dest)

# Generated copies of shared headers with the proposed declarations (pending build only).
pending = OUT / 'clothing-pending-overlay'
part_src = R / 'native-headers/v8datamodel/PartInstance.h'
text = part_src.read_text()
anchor = '\t\tvoid setColor(BrickColor value);\n'
assert text.count(anchor) == 1
(pending / 'v8datamodel').mkdir(parents=True, exist_ok=True)
(pending / 'v8datamodel/PartInstance.h').write_text(text.replace(
    anchor, anchor + '\t\tvoid outfitChanged(); // 0059e3a0 (proposal; fires event "OutfitChanged")\n'))
prop_src = ROOT / 'tools/rbxgs/Client/App/include/reflection/property.h'
text = prop_src.read_text()
anchor = '\t\t\t\tvirtual bool isReadOnly() const = 0;\n'
assert text.count(anchor) == 1
(pending / 'reflection').mkdir(parents=True, exist_ok=True)
(pending / 'reflection/property.h').write_text(text.replace(
    anchor, anchor + '\t\t\t\tvirtual bool isWriteOnly() const { return false; } // proposal: slot 1 (0060a2f0)\n'))


def build(name, src, extra):
    obj = OUT / (name + '.obj')
    flags = extra + nb.flags() + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeClothingLayout', LAYOUT, ['/I' + str(overlay)])
base_obj, base_flags = build('NativeClothing', SOURCE, ['/I' + str(overlay)])
pend_obj, pend_flags = build('NativeClothingPending', SOURCE,
                             ['/I' + str(pending), '/I' + str(overlay), '/DNATIVE_CLOTHING_PENDING'])

raw = layout_obj.read_bytes()
for prefix, value in (('?clothingOutfit1@@', 0x134), ('?clothingOutfit2@@', 0x154),
                      ('?shirtGraphicGraphic@@', 0x134), ('?skinColor@@', 0x134)):
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    assert body == b'\xb8' + struct.pack('<I', value) + b'\xc3', (prefix, body.hex())
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?clothingModifier@@'))
assert bytes.fromhex('05300100') in body, body.hex()   # add eax, 0x130 after the null test

original = nb.Original()

# Externals whose addresses are asserted (call targets named in the evidence or proven elsewhere).
KNOWN = {
    '??0Instance@RBX@@QAE@XZ': 0x55b7e0, '??1Instance@RBX@@UAE@XZ': 0x55a540,
    '?setName@Instance@RBX@@UAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': 0x55af90,
    '?getNullName@Name@RBX@@SAABV12@XZ': 0x554270,
    '?declare@Name@RBX@@SAABV12@PBDH@Z': 0x553f90,
    '?onAncestorChanged@Instance@RBX@@UAEXABUAncestorChanged@2@@Z': 0x55acc0,
    '?backendProcessing@Players@Network@RBX@@SA_NPBVInstance@3@_N@Z': 0x495eb0,
    '?modelIsCharacter@Humanoid@RBX@@SAPAV12@PBVInstance@2@@Z': 0x5d9a20,
    '?getHead@Humanoid@RBX@@QBEPAVPartInstance@2@XZ': 0x5d8a10,
    '?getTorso@Humanoid@RBX@@QBEPAVPartInstance@2@XZ': 0x5d8b10,
    '?getLeftLeg@Humanoid@RBX@@QBEPAVPartInstance@2@XZ': 0x5d8c10,
    '?getRightLeg@Humanoid@RBX@@QBEPAVPartInstance@2@XZ': 0x5d8d10,
    '?getLeftArm@Humanoid@RBX@@QBEPAVPartInstance@2@XZ': 0x5d8e10,
    '?getRightArm@Humanoid@RBX@@QBEPAVPartInstance@2@XZ': 0x5d8f10,
    '?setColor@PartInstance@RBX@@QAEXVBrickColor@2@@Z': 0x59df40,
    '?outfitChanged@PartInstance@RBX@@QAEXXZ': 0x59e3a0,
    '?resetLimbs@Clothing@RBX@@QAEXXZ': 0x5d4b00,
    '?sShirt@RBX@@3QBDB': 0x83c190, '?sPants@RBX@@3QBDB': 0x83c198, '?sShirtGraphic@RBX@@3QBDB': 0x83c1a0,
    '?sClothing@RBX@@3QBDB': 0x83c1b0, '?sSkin@RBX@@3QBDB': 0x83c1bc,
    '?prop_Graphic@ShirtGraphic@RBX@@2V?$BoundProp@VTextureId@RBX@@$00@Reflection@2@A': 0x979fe0,
    '?prop_Outfit1@Clothing@RBX@@2V?$BoundProp@VTextureId@RBX@@$00@Reflection@2@A': 0x979ffc,
    '?prop_Outfit2@Clothing@RBX@@2V?$BoundProp@VTextureId@RBX@@$00@Reflection@2@A': 0x97a034,
    '?prop_SkinColor@Skin@RBX@@2V?$BoundProp@VBrickColor@RBX@@$00@Reflection@2@A': 0x97a0c0,
    '?prop_ShirtTemplate@RBX@@3V?$PropDescriptor@VShirt@RBX@@VTextureId@2@@Reflection@2@A': 0x97a050,
    '?prop_PantsTemplate@RBX@@3V?$PropDescriptor@VPants@RBX@@VTextureId@2@@Reflection@2@A': 0x97a018,
    '?askSetParent@CharacterAppearance@RBX@@MBE_NPBVInstance@2@@Z': 0x5d7640,
    '??3?$Creatable@VInstance@RBX@@@RBX@@CAXPAX@Z': None,  # inline operator delete (free import), never a target
}

C, SG, SK, SH, PA = 'Clothing', 'ShirtGraphic', 'Skin', 'Shirt', 'Pants'
FP = {C: '??0?$FactoryProduct@VClothing@', SG: '??0?$FactoryProduct@VShirtGraphic@', SK: '??0?$FactoryProduct@VSkin@',
      SH: '??0?$FactoryProduct@VShirt@', PA: '??0?$FactoryProduct@VPants@'}
BASE_ROWS = [
    # factory/reflection chain (constructors)
    ('005d3e50', FP[C]), ('005d3de0', FP[SG]), ('005d3f30', FP[SK]), ('0048fd40', FP[SH]), ('0048fac0', FP[PA]),
    ('005d5270', '??0?$DescribedCreatable@VClothing@'), ('005d51c0', '??0?$DescribedCreatable@VShirtGraphic@'),
    ('005d5420', '??0?$DescribedCreatable@VSkin@'), ('004933c0', '??0?$DescribedCreatable@VShirt@'),
    ('004932c0', '??0?$DescribedCreatable@VPants@'),
    ('005d5700', '??0Clothing@RBX@@'), ('005d5510', '??0ShirtGraphic@RBX@@'), ('005d58c0', '??0Skin@RBX@@'),
    ('004939b0', '??0Shirt@RBX@@'), ('00493920', '??0Pants@RBX@@'),
    # class descriptors and class names
    ('004909f0', '?classDescriptor@?$Described@VClothing@'), ('005c01d0', '?classDescriptor@?$Described@VShirtGraphic@'),
    ('005d4cb0', '?classDescriptor@?$Described@VSkin@'), ('00491fb0', '?classDescriptor@?$Described@VShirt@'),
    ('00491f40', '?classDescriptor@?$Described@VPants@'),
    ('0048fb60', '?getClassName@?$FactoryProduct@VClothing@'), ('0048fe10', '?getClassName@?$FactoryProduct@VShirt@'),
    ('0048fbe0', '?getClassName@?$FactoryProduct@VPants@'), ('005d4290', '?getClassName@?$FactoryProduct@VShirtGraphic@'),
    ('005d42d0', '?getClassName@?$FactoryProduct@VSkin@'),
    # destructors
    ('0048f830', '??1?$FactoryProduct@VClothing@'), ('0048fa50', '??1Clothing@RBX@@'),
    ('0048fdb0', '??1?$FactoryProduct@VShirt@'), ('0048fb80', '??1?$FactoryProduct@VPants@'),
    ('005d3bc0', '??1?$FactoryProduct@VShirtGraphic@'), ('005d3d30', '??1?$FactoryProduct@VSkin@'),
    ('0048f8e0', '??_G?$FactoryProduct@VClothing@'), ('005d3dc0', '??_G?$FactoryProduct@VShirtGraphic@'),
    ('005d58a0', '??_GClothing@RBX@@'), ('005d54f0', '??_GSkin@RBX@@'), ('00493a70', '??_GShirt@RBX@@'),
    ('004933a0', '??_GPants@RBX@@'),
    # property descriptors
    ('005d4d20', '??$?0VShirtGraphic@RBX@@@?$BoundProp@VTextureId@'), ('005d4df0', '??$?0VClothing@RBX@@@?$BoundProp@VTextureId@'),
    ('005d4ec0', '??$?0VSkin@RBX@@@?$BoundProp@VBrickColor@'),
    ('005d5060', '??$?0P8Shirt@RBX@@BE?AVTextureId@1@XZP801@AEXV21@@Z@?$PropDescriptor@VShirt@'),
    ('005d5110', '??$?0P8Pants@RBX@@BE?AVTextureId@1@XZP801@AEXV21@@Z@?$PropDescriptor@VPants@'),
    ('005d3fe0', '??$getset@P8Shirt@'), ('005d4030', '??$getset@P8Pants@'),
    ('007f6010', '??__E?prop_Graphic@'), ('007f6040', '??__E?prop_Outfit1@'), ('007f6070', '??__E?prop_Outfit2@'),
    ('007f60a0', '??__Eprop_ShirtTemplate@'), ('007f60e0', '??__Eprop_PantsTemplate@'), ('007f6120', '??__E?prop_SkinColor@'),
    # methods
    ('005d3b50', '?dataChanged@CharacterAppearance@'), ('005d4c40', '?onAncestorChanged@CharacterAppearance@'),
    ('005d3aa0', '?apply@Skin@'), ('005d3a00', '?getTemplate@Shirt@'), ('005d3b90', '?getTemplate@Pants@'),
    # GetSet bodies (vtables 0083c480 Clothing, 0083c494 Skin, 0083c1d4 Shirt slots 2/3; identical-code-folded
    # with the ShirtGraphic / BodyColors / Pants instantiations and other classes' properties)
    ('005d3fa0', '?getValue@?$BoundPropGetSet@VClothing@'), ('005d5b10', '?setValue@?$BoundPropGetSet@VClothing@'),
    ('006334f0', '?getValue@?$BoundPropGetSet@VSkin@'), ('0063b210', '?setValue@?$BoundPropGetSet@VSkin@'),
    ('005cf5d0', '?getValue@?$GetSetImpl@P8Shirt@'), ('005b7400', '?setValue@?$GetSetImpl@P8Shirt@'),
]
# Former pending rows that compile against the current headers (native Decal.h, Instance::findFirstChildOfType,
# the 2008 GetSet with isWriteOnly in the native reflection headers).
BASE_ROWS += [('005d40c0', '?setTemplate@Shirt@'), ('005d4120', '?setTemplate@Pants@'),
              ('005d4240', '?apply@ShirtGraphic@'), ('005d41a0', '??$findFirstChildOfType@VDecal@RBX@@@Instance@RBX@@')]
PENDING_ROWS = [('005d3a30', '?apply@Clothing@')]


class Binder:
    def __init__(self):
        self.seen = {}

    def bind(self, where, symbol, value):
        if symbol in KNOWN and KNOWN[symbol] is not None:
            assert KNOWN[symbol] == value, (where, symbol, hex(value), hex(KNOWN[symbol]))
            return 'known %s' % hex(value)
        prev = self.seen.setdefault(symbol, value)
        assert prev == value, (where, 'inconsistent binding', symbol, hex(prev), hex(value))
        return 'bound %s' % hex(value)


binder = Binder()


def rows_for(obj, table):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    funcs = match.coff_functions(raw)
    out = []
    for address, prefix in table:
        hits = [x for x in funcs if x[0].startswith(prefix)]
        assert len(hits) == 1, (prefix, [h[0] for h in hits])
        name, body, refs = hits[0]
        addr = int(address, 16)
        target, target_refs, _ = match.target('2008-06', address)
        if len(target) > len(body):   # function list extent covers a following body (bounds note)
            target_refs = [o for o in target_refs if o < len(body)]
            target = target[:len(body)]
        assert match.exact_match(target, target_refs, body, refs), (address, name, len(body), len(target))
        out.append(check_relocs(raw, sections, symbols, definitions, name, body, addr, target))
    return out


def check_relocs(raw, sections, symbols, definitions, name, body, addr, target):
    start, section = definitions[name]
    table = sections[section]
    code = raw[table[4] + start:]
    targets, local = {}, []
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        offset -= start
        if not 0 <= offset < len(body):
            continue
        symbol = symbols[index][0]
        if kind == 20:
            value = (addr + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        else:
            value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
        if nb.LOCAL_EH.match(symbol):
            local.append(symbol)
            continue
        targets[symbol] = classify(name, symbol, value, raw, sections, definitions)
    return {'address': '%08x' % addr, 'symbol': name, 'size': len(body), 'exact': True,
            'targets': targets, 'local_eh': sorted(set(local))}


def classify(where, symbol, value, raw, sections, definitions):
    hit = original.imported(value)
    if hit is not None and symbol == '??9RBX@@YA_NABVContentId@0@0@Z':
        # RBX::operator!=(ContentId, ContentId) (out of line in ContentProvider.cpp) is a single
        # `jmp [string operator!=]` in the original (0055bd60), so the body itself is an import jump.
        assert hit == ('msvcp90.dll', '??$?9DU?$char_traits@D@std@@V?$allocator@D@1@@std@@YA_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@0@Z'), hit
        return '%s (jmp %s!%s)' % ((hex(binder.bind(where, symbol, value) and value),) + hit)
    if hit is not None:
        assert hit[1] == nb.plain(symbol), (where, symbol, hex(value), hit)
        return '%s!%s' % hit
    if symbol.startswith('??_C@'):
        pos, at = definitions[symbol]
        literal = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
        assert original.data(value, len(literal)) == literal, (where, symbol, hex(value))
        return '%s %r' % (hex(value), literal[:-1].decode())
    if symbol.startswith('??_R0') and symbol.endswith('@8'):
        rtti = original.string(value + 8)
        assert rtti.replace('3QBDB', '3PBDB') == ('.' + symbol[5:-2]).replace('3QBDB', '3PBDB'), (where, symbol, rtti)
        return '%s (%s)' % (hex(value), rtti)
    if symbol.startswith('??_7'):
        rtti, off = original.vtable_class(value)
        cls = symbol[4:symbol.index('@@6B') + 2]
        assert rtti.replace('3QBDB', '3PBDB') == ('.?AV' + cls).replace('3QBDB', '3PBDB'), (where, symbol, hex(value), rtti)
        binder.bind(where, symbol, value)
        return '%s (RTTI %s, offset %#x)' % (hex(value), rtti, off)
    if symbol.startswith('__real@'):
        assert original.data(value, 4) == bytes.fromhex(symbol[7:15])[::-1], (where, symbol)
        return hex(value)
    return binder.bind(where, symbol, value)


base_rows = rows_for(base_obj, BASE_ROWS)
pending_rows = rows_for(pend_obj, PENDING_ROWS)
for row in pending_rows:   # NATIVE_CLOTHING_PENDING bodies: exact only with generated header copies
    row['exact'] = 'pending-build-only'

# ShirtGraphic destructor 005d5690 (80 bytes) and deleting destructor 005d56e0 (31 bytes; adjustor 005d5600
# jumps to it). Some function lists record them as independent extents, others as one 111-byte extent at
# 005d5690: compare each body against its own slice of whichever extent covers it.
raw = base_obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
funcs = {n: (b, r) for n, b, r in match.coff_functions(raw)}
split_rows = []
for name, address, size in (('??1ShirtGraphic@RBX@@UAE@XZ', 0x5d5690, 80), ('??_GShirtGraphic@RBX@@UAEPAXI@Z', 0x5d56e0, 31)):
    body, refs = funcs[name]   # size: the target ret 005d56df / ret 4 005d56fc ends each body
    try:
        target, target_refs, _ = match.target('2008-06', '%08x' % address)
    except SystemExit:   # no extent starts here: slice the merged 005d5690 extent
        target, target_refs, _ = match.target('2008-06', '005d5690')
        lo = address - 0x5d5690
        target, target_refs = target[lo:], [o - lo for o in target_refs if o >= lo]
    target_refs = [o for o in target_refs if o < size]
    target = target[:size]
    assert len(target) == len(body) == size and match.exact_match(target, target_refs, body, refs), name
    split_rows.append(check_relocs(raw, sections, symbols, definitions, name, body, address, target))

# Template helpers reached only through bindings: callDoDeclare / doDeclare / static-descriptor atexit
# destructors / BoundPropGetSet and GetSetImpl bodies. Verify each body whose address the binder learned.
extra_rows = []
for symbol, value in sorted(binder.seen.items()):
    if not re.match(r'^(\?\?\$callDoDeclare@|\?\?\$doDeclare@|\?\?__F|\?\?__Fdescriptor@)', symbol):
        continue
    if symbol not in funcs:
        continue
    body, refs = funcs[symbol]
    target, target_refs, _ = match.target('2008-06', '%08x' % value)
    if not match.exact_match(target, target_refs, body, refs):
        print('  helper not exact:', hex(value), symbol[:90])
        continue
    extra_rows.append(check_relocs(raw, sections, symbols, definitions, symbol, body, value, target))


def vtable_slots(obj, prefix):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    names = [n for n in definitions if (n == prefix if prefix.endswith('6B@') else n.startswith(prefix))]
    assert len(names) == 1, (prefix, names)
    start, index = definitions[names[0]]
    section = sections[index]
    slots = {}
    for i in range(section[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10 * i)
        if offset >= start and kind == 6:
            slots[(offset - start) // 4] = symbols[symbol][0]
    return names[0], slots


u = lambda va: struct.unpack('<I', original.data(va, 4))[0]
vtables = []
for cls, primary, modifier in ((C, 0x83ca6c, 0x83c9e8), (SG, 0x83c994, 0x83c90c), (SK, 0x83cb44, 0x83cabc),
                               (SH, 0x822114, 0x82208c), (PA, 0x822044, 0x821fc0)):
    for prefix, address, count in (('??_7%s@RBX@@6B?$GuidItem@' % cls, primary, 17),
                                   ('??_7%s@RBX@@6B@' % cls, modifier, 1)):
        obj = base_obj
        name, slots = vtable_slots(obj, prefix)
        assert sorted(slots) == list(range(count)), (name, slots)
        rtti, off = original.vtable_class(address)
        assert rtti == '.?AV%s@RBX@@' % cls, (cls, rtti)
        entries = {}
        for slot, symbol in sorted(slots.items()):
            value = u(address + 4 * slot)
            if symbol in ('?askSetParent@CharacterAppearance@RBX@@MBE_NPBVInstance@2@@Z',):
                assert value == 0x5d7640
            entries[slot] = '%s -> %s' % (symbol, hex(value))
            binder.bind(name, symbol, value)
        vtables.append({'class': cls, 'vtable': hex(address), 'rtti_offset': off, 'slots': entries})
for vt, getter, setter in ((0x83c480, 0x5d3fa0, 0x5d5b10), (0x83c46c, 0x5d3fa0, 0x5d5b10), (0x83c494, 0x6334f0, 0x63b210),
                           (0x83c1d4, 0x5cf5d0, 0x5b7400), (0x83c1e8, 0x5cf5d0, 0x5b7400)):
    assert [u(vt + 4 * i) for i in range(4)] == [0x60a2f0, 0x60a2f0, getter, setter], hex(vt)
for cls, slot16 in ((C, 0x5d3a30), (SH, 0x5d3a30), (PA, 0x5d3a30), (SG, 0x5d4240), (SK, 0x5d3aa0)):
    assert u({C: 0x83ca6c, SH: 0x822114, PA: 0x822044, SG: 0x83c994, SK: 0x83cb44}[cls] + 64) == slot16

exact_rows = base_rows + split_rows + extra_rows
print('exact rows: %d (base %d, split %d, helpers %d); pending-build-only rows: %d (not counted)' % (
    len(exact_rows), len(base_rows), len(split_rows), len(extra_rows), len(pending_rows)))
for row in exact_rows + pending_rows:
    print('  %s %4d %s' % (row['address'], row['size'], row['symbol'][:100]))

sha = nb.sha
paths = [Path(__file__).resolve(), HEADER, SOURCE, LAYOUT, HUMANOID, PLAYERS]
receipt = {
    'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
    'sources': {str(p.relative_to(ROOT)): sha(p) for p in paths},
    'objects': {'layout': sha(layout_obj), 'base': sha(base_obj), 'pending': sha(pend_obj)},
    'compiler_build': 21022, 'flags': {'layout': layout_flags, 'base': base_flags, 'pending': pend_flags},
    'sizes': {'Clothing': 0x174, 'Shirt': 0x174, 'Pants': 0x174, 'ShirtGraphic': 0x154, 'Skin': 0x138,
              'CharacterAppearance': 0x134},
    'base_rows': base_rows, 'pending_rows': pending_rows, 'split_rows': split_rows, 'helper_rows': extra_rows,
    'vtables': vtables, 'bindings': {k: hex(v) for k, v in sorted(binder.seen.items())},
    'pending': ['005d3a30 Clothing::apply: PartInstance::outfitChanged() 0059e3a0 declaration (PartInstance.h)',
                '005d7640 askSetParent (ICF fold with ModelInstance::askSetParent): native ModelInstance.h does not compile standalone',
                '005d4b00 Clothing::resetLimbs and limb finders 005d4510/4640/4770/48a0/49d0: not attempted'],
    'scope': 'Inactive diagnostic: layout, constructors, destructors, factory/reflection chain, descriptors, '
             'static initializers and methods listed are exact with bound targets; pending rows use generated '
             'header copies under out/. Method and field names are analog names. No runtime swap.',
}
(ROOT / 'work/2008-06/shared-layouts/clothing-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native Clothing family: %d exact rows (+%d pending-build-only), %d vtables' % (
    len(exact_rows), len(pending_rows), len(vtables)))
