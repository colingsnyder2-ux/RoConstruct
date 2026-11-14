"""Verify the inactive native Studio property-grid editor rows of PropertyGridItems2008.h (2008-06).

Classes: XBrickColorItem (0081480c), Vector3Item (0081497c), Vector3ComponentItem (00814ae4), EnumItem (00814f24),
RefItem (00814c4c), ScriptItem (00814dbc), ContentItem<TextureId|SoundId> (00815214/008150ac), TextureItem (00815524),
SoundItem (008153b4), plus the XItem<T, GridItem, Descriptor> instantiations they are built on.

Profile (same recipe as record_native_editor_values.py / record_native_property_grid_item_brick_color.py):
document-swap flags + XTP 11.2.2 headers, unit preprocessed with std::string::c_str, CString operator PCXSTR,
CXTPPropertyGridItem::GetValue and CString::IsEmpty noinline (the original imports or calls each of them out of line),
compiled /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast (Vector3ComponentItem::equalValues 0043d890 uses fcomp; the
BrickColor readValue 00437c20 multiplies by the 1/255 float constant with fimul).

Builds:
  * main: native headers as committed. Exact rows, relocation bindings and every vtable slot come from this object.
  * pending: out/propgrid/pending holds a generated copy of PropertyGridItems.h whose XItem::OnValueChanged body is
    `GridItem::OnValueChanged(value); applyValue(readValue());` (proposal to the header owner) plus a copy of
    PropertyGridItems2008.h so the quoted include resolves to it. Rows exact only there are recorded exact=false
    (pending-build-only), never counted, and never used for vtable checks. The same pending copy is checked against
    the already-exact float/int OnValueChanged 004413e0/00441460 (tests/NativePropertyGridItems2008Pending.cpp).

Every REL32/DIR32 target of an exact row is verified (native_bind.verify: imports by DLL export name, strings by
bytes, vtables by RTTI, own rows, the INTERNAL map read from original call sites); one address per symbol.
Writes work/2008-06/shared-layouts/propgrid-items2008-working.json.
"""
import json
import os
import re
import struct
import sys
from pathlib import Path

from capstone import Cs, CS_ARCH_X86, CS_MODE_32
from capstone.x86 import X86_OP_IMM

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match, rebuild  # noqa: E402
import native_bind as nb  # noqa: E402

R = ROOT / 'rebuild/2008-06'
OUT = R / 'out/propgrid'
OUT.mkdir(parents=True, exist_ok=True)
SRC = R / 'native-classes/PropertyGridItems2008.cpp'
HEADER = R / 'native-headers/PropertyGridItems2008.h'
BASE_HEADER = R / 'native-headers/PropertyGridItems.h'
LAYOUT = R / 'tests/NativePropertyGridItems2008Layout.cpp'
PENDING_SRC = R / 'tests/NativePropertyGridItems2008Pending.cpp'
TC = rebuild.toolchain(21022)
XTP = nb.XTP_FLAGS
NEEDLES = ('const _Elem * c_str() const',
           'operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );',
           'CString CXTPPropertyGridItem::GetValue() const',
           'bool IsEmpty() const throw()\n\t{\n\t\treturn( GetLength() == 0 );')
COMPILE = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/fp:fast']

# ---- pending overlay (generated; never a native header) --------------------------------------------------------
PENDING = OUT / 'pending'
PENDING.mkdir(exist_ok=True)
text = BASE_HEADER.read_text()
OLD_BODY = '        GridItem::OnValueChanged(value);\n        T converted = readValue();\n        applyValue(converted);'
NEW_BODY = '        GridItem::OnValueChanged(value);\n        applyValue(readValue());'
assert text.count(OLD_BODY) == 1
(PENDING / 'PropertyGridItems.h').write_text(text.replace(OLD_BODY, NEW_BODY))
(PENDING / 'PropertyGridItems2008.h').write_text(HEADER.read_text())


def build(name, source, extra=(), profile=True):
    flags = nb.flags()
    if not profile:
        obj = OUT / (name + '.obj')
        code, log = rebuild.run(TC, 'cl', list(extra) + flags + XTP + ['/Fo' + str(obj), str(source)], OUT)
        assert code == 0, log[-3000:]
        return obj, None
    pre = OUT / (name + '-pre')
    pre.mkdir(exist_ok=True)
    code, log = rebuild.run(TC, 'cl', list(extra) + [x for x in flags if x != '/c'] + XTP + ['/P', str(source)], pre)
    assert code == 0, log[-3000:]
    body = (pre / (source.stem + '.i')).read_text(errors='replace')
    for needle in NEEDLES:
        if needle in body:
            assert body.count(needle) == 1, needle
            body = body.replace(needle, '__declspec(noinline) ' + needle)
    unit = OUT / (name + 'Profile.cpp')
    unit.write_text(body)
    obj = OUT / (name + '.obj')
    code, log = rebuild.run(TC, 'cl', COMPILE + ['/Fo' + str(obj), str(unit)], OUT)
    assert code == 0, log[-3000:]
    return obj, COMPILE


layout_obj, _ = build('NativePropertyGridItems2008Layout', LAYOUT, profile=False)   # C_ASSERT layout checks
plain_obj, _ = build('NativePropertyGridItems2008Plain', SRC, profile=False)
main_obj, _ = build('NativePropertyGridItems2008', SRC)
pending_obj, _ = build('NativePropertyGridItems2008Pending', SRC, ['/I' + str(PENDING)])
safety_obj, _ = build('NativePropertyGridItems2008Safety', PENDING_SRC, ['/I' + str(PENDING)])

raw = layout_obj.read_bytes()
for prefix, value in (('?brickColorItemOffset@@', 0x118), ('?enumItemOffset@@', 0x114),
                      ('?vector3ItemOffset@@', 0x10c), ('?textureItemOffset@@', 0x10c)):
    name, body, _ = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    assert struct.pack('<I', value) in body, (prefix, body.hex())

original = nb.Original()
u32 = lambda a: struct.unpack('<I', original.data(a, 4))[0]
S = 'V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@'

# ---- rows: (symbol prefix, original address, kind) -------------------------------------------------------------
# kind: 'class' counted; 'folded' identical-code body shared with other XItem shapes (counted once per address);
# 'elsewhere' already credited by another receipt (bound, not counted); 'support' library/SDK instance (not counted).
ROWS = [
    ('??0?$XItem@VBrickColor@RBX@@', 0x43b400, 'class'),
    ('??0XBrickColorItem@@', 0x43d560, 'class'),
    ('?OnDrawItemValue@XBrickColorItem@@', 0x43d5b0, 'class'),
    ('??_GXBrickColorItem@@', 0x43d660, 'folded'),
    ('??_EXBrickColorItem@@WCA@', 0x43d5a0, 'folded'),
    ('?readValue@?$XItem@VBrickColor@', 0x437c20, 'class'),
    ('?displayValue@?$XItem@VBrickColor@', 0x437c90, 'class'),
    ('?writeValue@?$XItem@VBrickColor@', 0x43b030, 'class'),
    ('?equalValues@?$XItem@VBrickColor@', 0x43b4c0, 'elsewhere'),
    ('?emptyValue@?$XItem@VBrickColor@', 0x43b4e0, 'elsewhere'),
    ('??0?$XItem@VVector3@G3D@@', 0x43c020, 'class'),
    ('??0Vector3Item@@', 0x43d6c0, 'class'),
    ('?update@Vector3Item@@', 0x43d790, 'class'),
    ('?OnAfterEdit@Vector3Item@@', 0x43d710, 'class'),
    ('?OnAddChildItem@Vector3Item@@', 0x43dae0, 'class'),
    ('??_GVector3Item@@', 0x43e900, 'folded'),
    ('??_EVector3Item@@WCA@', 0x43e8f0, 'folded'),
    ('?readValue@?$XItem@VVector3@', 0x4384b0, 'class'),
    ('?displayValue@?$XItem@VVector3@', 0x437cd0, 'class'),
    ('?equalValues@?$XItem@VVector3@', 0x43aff0, 'class'),
    ('?emptyValue@?$XItem@VVector3@', 0x43b4e0, 'elsewhere'),
    ('??0Vector3ComponentItem@@', 0x43d7d0, 'class'),
    ('?readValue@Vector3ComponentItem@@', 0x43d930, 'class'),
    ('?displayValue@Vector3ComponentItem@@', 0x43d8c0, 'class'),
    ('?equalValues@Vector3ComponentItem@@', 0x43d890, 'class'),
    ('?writeValue@Vector3ComponentItem@@', 0x43da10, 'class'),
    ('??_GVector3ComponentItem@@', 0x43e900, 'folded'),
    ('??_EVector3ComponentItem@@WCA@', 0x43e8f0, 'folded'),
    ('??0?$XItem@HVCXTPPropertyGridItemEnum@@', 0x43c440, 'class'),
    ('??_GEnumItem@@', 0x43c640, 'folded'),
    ('??_EEnumItem@@WCA@', 0x43c4f0, 'folded'),
    ('?readValue@?$XItem@HVCXTPPropertyGridItemEnum@', 0x437e70, 'class'),
    ('?displayValue@?$XItem@HVCXTPPropertyGridItemEnum@', 0x437e80, 'class'),
    ('?writeValue@?$XItem@HVCXTPPropertyGridItemEnum@', 0x43c5b0, 'class'),
    ('?OnValueChanged@?$XItem@HVCXTPPropertyGridItemEnum@', 0x441770, 'class'),
    ('?equalValues@?$XItem@HVCXTPPropertyGridItemEnum@', 0x43b4c0, 'elsewhere'),
    ('?emptyValue@?$XItem@HVCXTPPropertyGridItemEnum@', 0x43b4e0, 'elsewhere'),
    ('??0RefItem@@', 0x43db80, 'class'),
    ('?OnValueChanged@RefItem@@', 0x43dbf0, 'class'),
    ('??_GRefItem@@', 0x43e900, 'folded'),
    ('??_ERefItem@@WCA@', 0x43e8f0, 'folded'),
    ('??0ScriptItem@@', 0x43df50, 'class'),
    ('?OnValueChanged@ScriptItem@@', 0x43dbf0, 'folded'),
    ('??_GScriptItem@@', 0x43e900, 'folded'),
    ('??0?$XItem@VTextureId@RBX@@', 0x43cfa0, 'class'),
    ('??0?$XItem@VSoundId@Soundscape@RBX@@', 0x43c9b0, 'class'),
    ('?readValue@?$XItem@VTextureId@', 0x438580, 'class'),
    ('?readValue@?$XItem@VSoundId@', 0x438580, 'folded'),
    ('?displayValue@?$XItem@VTextureId@', 0x437d30, 'class'),
    ('?displayValue@?$XItem@VSoundId@', 0x437d30, 'folded'),
    ('?equalValues@?$XItem@VTextureId@', 0x43ca60, 'class'),
    ('?equalValues@?$XItem@VSoundId@', 0x43ca60, 'folded'),
    ('?emptyValue@?$XItem@VTextureId@', 0x43b4e0, 'elsewhere'),
    ('?emptyValue@?$XItem@VSoundId@', 0x43b4e0, 'elsewhere'),
    ('??0?$ContentItem@VTextureId@RBX@@@@', 0x43ea20, 'class'),
    ('??0?$ContentItem@VSoundId@Soundscape@RBX@@@@', 0x43e840, 'class'),
    ('?OnValueChanged@?$ContentItem@VTextureId@', 0x43e960, 'class'),
    ('?OnValueChanged@?$ContentItem@VSoundId@', 0x43e960, 'folded'),
    ('??_G?$ContentItem@VTextureId@', 0x43e900, 'folded'),
    ('??_G?$ContentItem@VSoundId@', 0x43e900, 'folded'),
    ('??0TextureItem@@', 0x440db0, 'class'),
    ('??0?$XItem@V?$basic_string@', 0x43b860, 'elsewhere'),
    ('??_GTextureItem@@', 0x43e900, 'folded'),
    ('??0SoundItem@@', 0x440d30, 'class'),
    ('??_GSoundItem@@', 0x43e900, 'folded'),
    ('?find@?$_Tree@V?$_Tmap_traits@PBVClassDescriptor@Reflection@RBX@@V?$vector@V?$shared_ptr@VInstance', 0x43a320, 'support'),
]
# Compiled here but not byte-identical (recorded exact=false with the reason).
NONEXACT = [
    ('??0EnumItem@@', 0x43e3a0, 'one byte longer: same instructions, different register allocation for the cached '
                                '_invalid_parameter_noinfo pointer and the vector end iterator'),
    ('?update@ScriptItem@@', 0x43dff0, 'original is 329 bytes with a hoisted SelectionGroup* validity check; '
                                       'loop/find shape not yet reproduced'),
    ('?update@RefItem@@', 0x43dc00, 'original is 835 bytes; same algorithm (first referent name, SetValue("") on a '
                                    'mismatch, SetHidden(!found)) but different checked-iterator code'),
]
# XItem template OnValueChanged for the new types: exact only with the proposed PropertyGridItems.h body.
PENDING_ROWS = [
    ('?OnValueChanged@?$XItem@VBrickColor@', 0x441560),
    ('?OnValueChanged@?$XItem@VVector3@', 0x441660),
    ('?OnValueChanged@?$XItem@VTextureId@', 0x4416e0),
    ('?OnValueChanged@?$XItem@VSoundId@', 0x4416e0),
]
NOT_ATTEMPTED = {
    '0043e140': 'ScriptItem::OnInplaceButtonDown (603 bytes; opens the script document)',
    '00441d60': 'TextureItem::browse (445 bytes; file dialog + content upload)',
    '00441bc0': 'SoundItem::browse (406 bytes)',
    '0043b5b0/0043c170/0043c6a0/0043cc20': 'XItem<T>::update instantiations (template body owned by PropertyGridItems.h)',
    '0043f890/0043ff70/004402d0/0043e4c0': 'XItem<T>::applyValue instantiations (template body owned by PropertyGridItems.h)',
}


def resolve(functions, prefix):
    hits = [n for n in functions if n.startswith(prefix)]
    assert len(hits) == 1, (prefix, hits)
    return hits[0]


raw = main_obj.read_bytes()
bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
methods = [(resolve(bodies, p), a) for p, a, _ in ROWS]
kind_of = {resolve(bodies, p): k for p, a, k in ROWS}

# Targets outside this unit, each read at the original call/jump site (address -> evidence).
INTERNAL_NOTES = {
    '??0CXTPPropertyGridItem@@QAE@PBD0PAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z': (0x713510, 'XTP ctor; same binding as record_native_property_editors.py'),
    '??0CXTPPropertyGridItemEnum@@QAE@PBDHPAH@Z': (0x717e30, 'XTP enum ctor called by 0043c440 (ret 0xc, stores Enum vptrs)'),
    '?SetReadOnly@CXTPPropertyGridItem@@QAEXH@Z': (0x7120e0, 'XTP; same binding as record_native_property_editors.py'),
    '??0Item@CPropGrid@@QAE@PBVPropertyDescriptor@Reflection@RBX@@PAV1@@Z': (0x43a070, 'exact in record_native_property_editors.py'),
    '??0CPropertyGridItemBrickColor@@QAE@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@K@Z': (0x437ae0, 'exact in record_native_property_grid_item_brick_color.py'),
    '?GetValue@CXTPPropertyGridItem@@QBE?A%sXZ' % S: (0x437ed0, 'exact XTP inline in record_native_property_grid_item_brick_color.py'),
    '?OnDrawItemValue@CXTPPropertyGridItemColor@@MAEHAAVCDC@@VCRect@@@Z': (0x713c20, 'XTP Color slot 26 (CXTPPropertyGridItemColor vtable 0085d7c4)'),
    '?GetFlags@CXTPPropertyGridItem@@QBEIXZ': (0x710e30, 'XTP out-of-line accessor, ScriptItem ctor 0043df50'),
    '?SetFlags@CXTPPropertyGridItem@@QAEXI@Z': (0x710dd0, 'XTP, ScriptItem ctor 0043df50'),
    '?SetValue@CXTPPropertyGridItem@@UAEX%s@Z' % S: (0x7119f0, 'XTP slot 24 base body; same binding as the BrickColor recorder'),
    '?OnValueChanged@CXTPPropertyGridItem@@UAEX%s@Z' % S: (0x711ac0, 'XTP slot 25 base body; same binding as record_native_editor_values.py'),
    '?OnAddChildItem@CXTPPropertyGridItem@@MAEXXZ': (0x711600, 'XTP slot 51 base body (CXTPPropertyGridItem vtable 0085d5e4)'),
    '?AddChildItem@CXTPPropertyGridItem@@QAEPAV1@PAV1@@Z': (0x7131c0, 'XTP, Vector3Item::OnAddChildItem 0043dae0'),
    '??1CXTPPropertyGridItem@@UAE@XZ': (0x713630, 'XTP destructor, deleting destructor 0043e900'),
    '??1CXTPPropertyGridItemColor@@UAE@XZ': (0x713760, 'same binding as the BrickColor recorder'),
    '??1CXTPPropertyGridItemEnum@@UAE@XZ': (0x7178b0, 'XTP destructor, deleting destructor 0043c640'),
    '??3@YAXPAX@Z': (0x6a067a, 'operator delete (deleting destructors)'),
    '??2@YAPAXI@Z': (0x6a0920, 'operator new, same address as the factory 00440e30 calls'),
    '?doLock@Lock@DataModel@RBX@@AAEXPBV23@@Z': (0x576f00, 'evidence name'),
    '??1Lock@DataModel@RBX@@QAE@XZ': (0x5773c0, 'evidence name'),
    '?convertToValue@?$StringConverter@VVector3@G3D@@@RBX@@SA_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AAVVector3@G3D@@@Z': (0x5bebb0, 'evidence name'),
    '?convertToValue@?$StringConverter@M@RBX@@SA_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AAM@Z': (0x5be790, 'evidence name'),
    '?closest@BrickColor@RBX@@SA?AV12@VColor3@G3D@@@Z': (0x5b62e0, 'evidence name'),
    '?color4uint8@BrickColor@RBX@@QBE?AVColor4uint8@G3D@@XZ': (0x5b6120, 'BrickMap::singleton()->map find; color3uint8 005b6180 calls it'),
    '?getNullName@Name@RBX@@SAABV12@XZ': (0x554270, 'evidence name'),
    '??8RBX@@YA_NABVContentId@0@0@Z': (0x55bd70, 'tail jump to msvcp90 std::operator== (ContentId::id at +0)'),
    '__real@3b808081': (0x8135d4, 'float 1/255 (same constant as the BrickColor recorder)'),
    '?GetColor@CXTPPropertyGridItemColor@@UBEKXZ': (0x43a1c0, 'exact XTP inline in the BrickColor recorder'),
    '?SetHidden@CXTPPropertyGridItem@@QAEXH@Z': (0x7110d0, 'XTP, ScriptItem/RefItem update tails'),
    '?applyValue@?$XItem@VBrickColor@RBX@@VCPropertyGridItemBrickColor@@V?$TypedPropertyDescriptor@VBrickColor@RBX@@@Reflection@2@@@QAEXABVBrickColor@RBX@@@Z': (0x43f890, 'call in 00441560'),
    '?applyValue@?$XItem@VVector3@G3D@@VCXTPPropertyGridItem@@V?$TypedPropertyDescriptor@VVector3@G3D@@@Reflection@RBX@@@@QAEXABVVector3@G3D@@@Z': (0x43ff70, 'call in 00441660'),
    '?applyValue@?$XItem@HVCXTPPropertyGridItemEnum@@VEnumPropertyDescriptor@Reflection@RBX@@@@QAEXABH@Z': (0x4402d0, 'call in 00441770'),
    '?applyValue@?$XItem@VTextureId@RBX@@VCXTPPropertyGridItem@@V?$TypedPropertyDescriptor@VTextureId@RBX@@@Reflection@2@@@QAEXABVTextureId@RBX@@@Z': (0x43e4c0, 'calls in 0043e960 / 004416e0 (identical-code fold with SoundId)'),
    '?applyValue@?$XItem@VSoundId@Soundscape@RBX@@VCXTPPropertyGridItem@@V?$TypedPropertyDescriptor@VSoundId@Soundscape@RBX@@@Reflection@3@@@QAEXABVSoundId@Soundscape@RBX@@@Z': (0x43e4c0, 'calls in 0043e960 / 004416e0 (identical-code fold with TextureId)'),
    '?update@?$XItem@VVector3@G3D@@VCXTPPropertyGridItem@@V?$TypedPropertyDescriptor@VVector3@G3D@@@Reflection@RBX@@@@UAEXPAVSelectionGroup@RBX@@@Z': (0x43c170, 'XItem<Vector3> Item-slot update called by Vector3Item::update 0043d790 and in table 00814030; template body not in this unit'),
    '??0TextureId@RBX@@QAE@XZ': (0x43d050, 'ContentId() inline body (string ctor + getNullName), call in 0043e960'),
    '??0SoundId@Soundscape@RBX@@QAE@XZ': (0x43d050, 'identical-code fold with TextureId(), call in 0043e960'),
    '??0TextureId@RBX@@QAE@PBD@Z': (0x4377c0, 'ContentId(const char*) inline body, call in 0043e960'),
    '??0SoundId@Soundscape@RBX@@QAE@PBD@Z': (0x4377c0, 'identical-code fold with TextureId(const char*), call in 0043e960'),
}
INTERNAL = {k: v[0] for k, v in INTERNAL_NOTES.items()}
# RBX::operator==(ContentId, ContentId) 0055bd70 is a 6-byte tail jump through the msvcp90 std::operator== import
# slot (ContentId::id at +0); bind it as a function, not as the import it jumps to.
assert original.data(0x55bd70, 6) == b'\xff\x25' + struct.pack('<I', 0x802444)
assert original.imports[0x802444][2].startswith('??$?8DU?$char_traits@D@std@@')
_imported = original.imported
original.imported = lambda value: None if value == 0x55bd70 else _imported(value)
# Vector deleting destructors (??_E) are referenced by the vtables and the +0x20 thunks; MSVC emits the identical
# body as the scalar one (??_G) and the original folds both (brickcolor recorder precedent).
DELETING = {}
for p, a, k in ROWS:
    if p.startswith('??_G'):
        name = resolve(bodies, p)
        DELETING['??_E' + name[4:]] = a
DISCOVER = os.environ.get('DISCOVER')
if DISCOVER:
    for name, address in methods:
        try:
            nb.verify(original, main_obj, [(name, address)], INTERNAL, dict(methods, **DELETING))
        except AssertionError as e:
            print('UNBOUND', hex(address), e)
    sys.exit(0)
rows = nb.verify(original, main_obj, methods, INTERNAL, dict(methods, **DELETING))
for row in rows:
    row['kind'] = kind_of[row['symbol']]
own = {r['symbol']: int(r['address'], 16) for r in rows}
own.update(DELETING)

# ---- non-exact and pending-only rows -----------------------------------------------------------------------------
nonexact = []
for prefix, address, reason in NONEXACT:
    name = resolve(bodies, prefix)
    body, refs = bodies[name]
    target, target_refs, _ = match.target('2008-06', '%08x' % address)
    assert not match.exact_match(target, target_refs, body, refs), (name, 'now exact: promote it')
    nonexact.append({'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target),
                     'exact': False, 'reason': reason})
praw = pending_obj.read_bytes()
pbodies = {n: (b, r) for n, b, r in match.coff_functions(praw)}
pending_rows = []
for prefix, address in PENDING_ROWS:
    name = resolve(pbodies, prefix)
    body, refs = pbodies[name]
    target, target_refs, _ = match.target('2008-06', '%08x' % address)
    pexact = match.exact_match(target, target_refs, body, refs)
    mbody, mrefs = bodies[resolve(bodies, prefix)]
    assert not match.exact_match(target, target_refs, mbody, mrefs), (name, 'exact in main build: promote it')
    assert pexact, (name, hex(address))
    prow = nb.verify(original, pending_obj, [(name, address)], INTERNAL, own)[0]
    prow.update(exact=False, pending_build_only=True, proposal='PropertyGridItems.h XItem::OnValueChanged: applyValue(readValue())')
    pending_rows.append(prow)
pending_symbols = {r['symbol'] for r in pending_rows}
nonexact_symbols = {r['symbol'] for r in nonexact}
NOT_ATTEMPTED_ADDRESSES = {'0043e140', '00441d60', '00441bc0'}
sraw = safety_obj.read_bytes()
safety = []
for prefix, address in (('?OnValueChanged@?$XItem@M', 0x4413e0), ('?OnValueChanged@?$XItem@H', 0x441460)):
    name, body, refs = next(x for x in match.coff_functions(sraw) if x[0].startswith(prefix))
    target, target_refs, _ = match.target('2008-06', '%08x' % address)
    assert match.exact_match(target, target_refs, body, refs), (prefix, 'proposal would regress an exact row')
    safety.append({'address': '%08x' % address, 'symbol': name, 'exact_with_proposal': True})

# ---- vtables (main build only): every slot bound to the original slot value ---------------------------------------
sections, symbols, definitions, _ = match._coff_data_index(raw)
vt_address = {}
for row in rows:
    for symbol, proof in row['verified_targets'].items():
        if symbol.startswith('??_7'):
            vt_address[symbol] = int(proof.split()[0], 16)
def bases(vtable):
    hierarchy = u32(u32(vtable - 4) + 16)
    out = []
    for i in range(u32(hierarchy + 8)):
        bcd = u32(u32(hierarchy + 12) + 4 * i)
        out.append((original.string(u32(bcd) + 8), struct.unpack('<i', original.data(bcd + 8, 4))[0]))
    return out


# EnumItem's constructor is non-exact, so its three vptr stores are read from the original constructor 0043e3a0
# (mov [esi], 00814f24 / [esi+0x20], 00814ec4 / [esi+0x114], 00814eb8) and checked by RTTI subobject offset.
ctor_code, _, _ = match.target('2008-06', '0043e3a0')
for symbol, store, address, subobject in (('??_7EnumItem@@6BCCmdTarget@@@', b'\xc7\x06', 0x814f24, 0),
                                          ('??_7EnumItem@@6BCXTPAccessible@@@', b'\xc7\x46\x20', 0x814ec4, 0x20),
                                          ('??_7EnumItem@@6B@', b'\xc7\x86\x14\x01\x00\x00', 0x814eb8, 0x114)):
    assert store + struct.pack('<I', address) in ctor_code, symbol
    assert original.vtable_class(address) == ('.?AVEnumItem@@', subobject), symbol
    assert symbol in definitions, symbol
    vt_address[symbol] = address
PURECALL = u32(0x8137a4)        # CPropGrid::Item's one-slot pure vtable (Codex RTTI proof) holds _purecall
assert original.imported(PURECALL) == ('msvcr90.dll', '_purecall')     # jmp [__imp__purecall] stub


def sdk_vtable(rtti_name, offset):
    """Original vtable of an SDK class by RTTI type descriptor name and subobject offset."""
    image = original.pe.get_memory_mapped_image()
    base = original.image
    td = base + image.index(rtti_name.encode() + b'\0') - 8
    for m in re.finditer(re.escape(struct.pack('<I', td)), image):
        col = base + m.start() - 12
        if struct.unpack_from('<I', image, col - base)[0] == 0 and struct.unpack_from('<I', image, col - base + 4)[0] == offset:
            hit = image.find(struct.pack('<I', col))
            while hit >= 0:
                if hit % 4 == 0:
                    return base + hit + 4
                hit = image.find(struct.pack('<I', col), hit + 1)
    raise AssertionError((rtti_name, offset))


GRIDS = ('CPropertyGridItemBrickColor', 'CXTPPropertyGridItemEnum', 'CXTPPropertyGridItemColor', 'CXTPPropertyGridItem')
SDK_CLASSES = GRIDS + ('CCmdTarget', 'CObject', 'CXTPAccessible')
CREDITED_ELSEWHERE = {'0043b4c0': 'editor-values-working-probe.json', '0043b4e0': 'editor-values-working-probe.json',
                      '0043b860': 'property-editor-constructors-working-probe.json'}
sdk_cache = {}
symbol_value = {}
vtables = {}
unresolved_slots = {}


def defining_class(symbol):
    if symbol.startswith('??_'):
        return None
    m = re.match(r'\?[^@]+@([^@]+)@@', symbol)
    return m.group(1) if m else None


for vt, address in sorted(vt_address.items(), key=lambda x: (original.vtable_class(x[1])[1] != 0, x[1])):
    start, section = definitions[vt]
    table = sections[section]
    slots = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if offset >= start:
            slots[(offset - start) // 4] = symbols[index][0]
    count = (table[3] - start) // 4
    assert sorted(slots) == list(range(count)), (vt, sorted(slots))
    rtti, subobject = original.vtable_class(address)
    names = [n for n, _ in bases(address)]
    grid = next(g for g in GRIDS if '.?AV%s@@' % g in names)
    proof = {}
    for slot, symbol in sorted(slots.items()):
        value = u32(address + 4 * slot)
        assert symbol_value.setdefault(symbol, value) == value, (vt, slot, symbol, hex(value), hex(symbol_value[symbol]))
        folded = '??_G' + symbol[4:] if symbol.startswith('??_E') else None
        if symbol in own or folded in own:
            assert own.get(symbol, own.get(folded)) == value, (vt, slot, symbol, hex(value))
            proof[slot] = 'own exact row' + (' (vector deleting destructor folded with %s)' % folded if symbol not in own else '')
        elif symbol == '__purecall':
            assert value == PURECALL, (vt, slot)
            proof[slot] = '_purecall'
        elif defining_class(symbol) in SDK_CLASSES or (symbol.startswith('??_E') and defining_class('?x@' + symbol[4:]) in SDK_CLASSES):
            key = ('.?AV%s@@' % grid, subobject)
            sdk = sdk_cache.setdefault(key, sdk_vtable(*key))
            assert u32(sdk + 4 * slot) == value, (vt, slot, symbol, hex(value), hex(sdk))
            proof[slot] = 'inherited %s: %08x slot %d' % (grid, sdk, slot)
        else:
            # XItem template members declared in PropertyGridItems.h with no body in this unit (owner's template bodies)
            # or bodies proven by other recorders (XItem<std::string>).
            if symbol in nonexact_symbols or (symbol not in bodies and '%08x' % value in NOT_ATTEMPTED_ADDRESSES):
                unresolved_slots[symbol] = '%08x' % value
                proof[slot] = ('non-exact row' if symbol in nonexact_symbols else 'declared, not attempted') + '; original %08x' % value
                continue
            exact_here = False
            if symbol not in bodies and folded in bodies:
                body, refs = bodies[folded]
                target, target_refs, _ = match.target('2008-06', '%08x' % value)
                if match.exact_match(target, target_refs, body, refs):
                    row = nb.verify(original, main_obj, [(folded, value)], INTERNAL, own)[0]
                    row.update(kind='support' if 'basic_string' in folded else 'folded', found_by='%s slot %d (vector deleting destructor %s folds with it)' % (vt, slot, symbol))
                    rows.append(row)
                    own[folded] = own[symbol] = value
                    proof[slot] = 'own exact row %s (vector deleting destructor folded)' % folded
                    continue
            if symbol in bodies:
                body, refs = bodies[symbol]
                target, target_refs, _ = match.target('2008-06', '%08x' % value)
                exact_here = match.exact_match(target, target_refs, body, refs)
            if exact_here:
                row = nb.verify(original, main_obj, [(symbol, value)], INTERNAL, own)[0]
                row['kind'] = 'support' if 'basic_string' in symbol else 'folded'
                if '%08x' % value in CREDITED_ELSEWHERE:
                    row['kind'] = 'elsewhere'
                row['found_by'] = '%s slot %d' % (vt, slot)
                rows.append(row)
                own[symbol] = value
                proof[slot] = 'own exact row (XItem template instance reached by this vtable)'
            else:
                assert '?$XItem@' in symbol, (vt, slot, symbol)
                assert symbol not in bodies or symbol in pending_symbols or 'basic_string' in symbol, (vt, slot, symbol)
                unresolved_slots[symbol] = '%08x' % value
                proof[slot] = ('pending-build-only body' if symbol in pending_symbols else
                               'not proven here (template body elsewhere)') + '; original %08x, one address per symbol' % value
    vtables['%08x' % address] = {'symbol': vt, 'rtti': rtti, 'subobject': subobject, 'slots': count, 'proof': proof}


# ---- RTTI of the classes and allocation sizes --------------------------------------------------------------------
CLASSES = {0x81480c: ('XBrickColorItem', 0x118), 0x81497c: ('Vector3Item', 0x10c), 0x814ae4: ('Vector3ComponentItem', 0x10c),
           0x814f24: ('EnumItem', 0x114), 0x814c4c: ('RefItem', 0x10c), 0x814dbc: ('ScriptItem', 0x10c),
           0x815524: ('TextureItem', 0x10c), 0x8153b4: ('SoundItem', 0x10c)}
rtti = {}
for vt, (cls, item) in CLASSES.items():
    b = bases(vt)
    assert b[0] == ('.?AV%s@@' % cls, 0) and ('.?AVItem@CPropGrid@@', item) in b and ('.?AVCXTPAccessible@@', 0x20) in b, (cls, b)
    assert '%08x' % vt in vtables, cls
    rtti[cls] = b
cs = Cs(CS_ARCH_X86, CS_MODE_32)
cs.detail = True


def allocations(address):
    code, _, _ = match.target('2008-06', '%08x' % address)
    found, size, prev = {}, None, None
    for i in cs.disasm(code, address):
        if i.mnemonic == 'call' and i.op_str.startswith('0x'):
            dest = int(i.op_str, 16)
            if dest == 0x6a0920 and prev.mnemonic == 'push' and prev.operands[0].type == X86_OP_IMM:
                size = prev.operands[0].imm
            else:
                found.setdefault(dest, size)
        prev = i
    return found


factory = allocations(0x440e30)
SIZES = {0x43d560: 0x13c, 0x43d6c0: 0x13c, 0x43e3a0: 0x138, 0x43db80: 0x134, 0x43df50: 0x130, 0x440db0: 0x130, 0x440d30: 0x130}
for ctor, size in SIZES.items():
    assert factory[ctor] == size, (hex(ctor), factory.get(ctor))
assert allocations(0x43dae0)[0x43d7d0] == 0x140

# ---- receipt ------------------------------------------------------------------------------------------------------
counted = sorted({r['address'] for r in rows if r['kind'] in ('class', 'folded')} - set(CREDITED_ELSEWHERE))
paths = [Path(__file__).resolve(), SRC, HEADER, BASE_HEADER, LAYOUT, PENDING_SRC, R / 'native-headers/CPropGrid.h',
         R / 'native-headers/CPropertyGridItemBrickColor.h', R / 'native-headers/SelectionGroup.h', R / 'tests/native_bind.py']
receipt = {
    'classes': sorted(CLASSES[v][0] for v in CLASSES) + ['ContentItem<RBX::TextureId>', 'ContentItem<RBX::Soundscape::SoundId>'],
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)', 'flags': nb.flags() + XTP,
    'profile': 'preprocessed with c_str / PCXSTR / XTP GetValue / CString::IsEmpty noinline, compiled ' + ' '.join(COMPILE),
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): nb.sha(p) for p in paths},
    'objects': {o.name: nb.sha(o) for o in (main_obj, pending_obj, safety_obj, layout_obj, plain_obj)},
    'layout': {'XBrickColorItem': '0x13c (Item +0x118, descriptor +0x138)', 'Vector3Item': '0x13c (components[3] +0x130)',
               'Vector3ComponentItem': '0x140 (component +0x130, value +0x134)', 'EnumItem': '0x138 (Item +0x114, descriptor +0x134)',
               'RefItem': '0x134 (refDescriptor +0x130)', 'ScriptItem': '0x130', 'TextureItem': '0x130', 'SoundItem': '0x130',
               'CXTPPropertyGridItemEnum': '0x114'},
    'allocation_sizes': {'%08x' % k: hex(v) for k, v in SIZES.items()} | {'0043d7d0 (in 0043dae0)': '0x140'},
    'rtti': rtti,
    'exact_counted_addresses': counted,
    'methods': rows,
    'nonexact': nonexact,
    'pending_build_only': pending_rows,
    'pending_proposal_safety': safety,
    'vtables': vtables,
    'unresolved_vtable_slots': unresolved_slots,
    'internal_bindings': {k: '%08x (%s)' % v for k, v in INTERNAL_NOTES.items()},
    'not_attempted': NOT_ATTEMPTED,
    'proposed_shared_declarations': [
        'native-headers/PropertyGridItems.h (owner): XItem::OnValueChanged body `GridItem::OnValueChanged(value); '
        'applyValue(readValue());` instead of a named `T converted` local: makes 00441560/00441660/004416e0 '
        'exact and keeps float/int 004413e0/00441460 exact.'],
    'scope': 'Inactive class recovery; no build-list, swap or runtime integration. Names browse()/component/value/'
             'components/refDescriptor are recovery names; layouts and ABIs come from the binary.',
}
(ROOT / 'work/2008-06/shared-layouts/propgrid-items2008-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native PropertyGridItems2008: %d exact rows (%d counted addresses), %d non-exact, %d pending-build-only, '
      '%d vtables slot-checked' % (len(rows), len(counted), len(nonexact), len(pending_rows), len(vtables)))
