"""Verify the inactive native RBX::BodyColors and RBX::Accoutrement / RBX::Hat recoveries.

Builds tests/NativeAppearanceLayout.cpp, native-classes/BodyColors.cpp and native-classes/Accoutrement.cpp:
  * BodyColors base: current headers (declaration-only Humanoid overlay tests/NativeClothingHumanoid.h, read only);
  * BodyColors pending: additionally NATIVE_BODYCOLORS_PENDING with generated header copies under out/;
  * Accoutrement: current headers, unit profile + /fp:fast (getAttachmentForward 005b0970 x87 order).
Each listed COFF function must be byte-identical to the original (relocations masked), and every relocation
target is bound to the address the original instruction uses: imports by name, string literals by bytes,
RTTI and vtables by class name and subobject offset (complete-object locator), listed externals by address,
and every other symbol consistently (the same symbol binds the same address in every row and vtable slot).
Rows exact only in the pending build are recorded with exact=False, status='pending-build-only', not counted.
Every relocation target of a counted row must be pinned (no consistency-only bindings).
Vtable slots and vbtables are read from the objects built from the current headers only.
Writes work/2008-06/shared-layouts/appearance-working.json.
"""
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
SOURCE = R / 'native-classes/BodyColors.cpp'
HEADER = R / 'native-headers/v8datamodel/BodyColors.h'
ACC_SOURCE = R / 'native-classes/Accoutrement.cpp'
ACC_HEADER = R / 'native-headers/v8datamodel/Accoutrement.h'
CLOTHING_HEADER = R / 'native-headers/v8datamodel/Clothing.h'
LAYOUT = R / 'tests/NativeAppearanceLayout.cpp'
HUMANOID = R / 'tests/NativeClothingHumanoid.h'

overlay = OUT / 'appearance-overlay'
(overlay / 'humanoid').mkdir(parents=True, exist_ok=True)
shutil.copyfile(HUMANOID, overlay / 'humanoid/Humanoid.h')

# Generated copies of shared headers with the proposed declarations (pending build only).
pending = OUT / 'appearance-pending-overlay'
# (1) v8datamodel/Camera.h (donor, pulled in by native ModelInstance.h): the 2008 DescribedCreatable takes
#     const char*, and the RTTI names `char sCamera[]` (3PADA), so the copy declares that instead of
#     `const char* sCamera` / `&sCamera` (C2440 otherwise).
# (2) v8datamodel/ModelInstance.h (native, other owner): member template findModifierOfType<T>() walking the
#     existing `modifiers` vector (005d4460 = <Skin>; name a proposal). No field or vtable change.
(pending / 'v8datamodel').mkdir(parents=True, exist_ok=True)
text = (ROOT / 'tools/rbxgs/Client/App/include/v8datamodel/Camera.h').read_text()
for old, new in (('extern const char* sCamera;', 'extern char sCamera[];'),
                 ('DescribedCreatable<Camera, Instance, &sCamera>', 'DescribedCreatable<Camera, Instance, sCamera>')):
    assert text.count(old) == 1, old
    text = text.replace(old, new)
(pending / 'v8datamodel/Camera.h').write_text(text)
MODEL_TEMPLATE = '''\t\ttemplate<class T> T* findModifierOfType() const   // proposal (005d4460 = <Skin>)
\t\t{
\t\t\tstd::vector<IModelModifier*>::const_iterator end = modifiers.end();
\t\t\tfor (std::vector<IModelModifier*>::const_iterator iter = modifiers.begin(); iter != end; ++iter)
\t\t\t{
\t\t\t\tif (T* result = dynamic_cast<T*>(*iter))
\t\t\t\t\treturn result;
\t\t\t}
\t\t\treturn NULL;
\t\t}
'''
text = (R / 'native-headers/v8datamodel/ModelInstance.h').read_text()
anchor = '\t\tPartInstance* getPrimaryPartInternal() const;\n'
assert text.count(anchor) == 1
(pending / 'v8datamodel/ModelInstance.h').write_text(text.replace(anchor, MODEL_TEMPLATE + anchor))


def build(name, src, extra):
    obj = OUT / (name + '.obj')
    flags = extra + nb.flags() + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeAppearanceLayout', LAYOUT, ['/I' + str(overlay)])
base_obj, base_flags = build('NativeBodyColors', SOURCE, ['/I' + str(overlay)])
pend_obj, pend_flags = build('NativeBodyColorsPending', SOURCE,
                             ['/I' + str(pending), '/I' + str(overlay), '/DNATIVE_BODYCOLORS_PENDING'])
acc_obj, acc_flags = build('NativeAccoutrement', ACC_SOURCE, ['/fp:fast'])

raw = layout_obj.read_bytes()
for prefix, value in (('?bodyHeadColor@@', 0x134), ('?bodyLeftArmColor@@', 0x138), ('?bodyRightArmColor@@', 0x13c),
                      ('?bodyTorsoColor@@', 0x140), ('?bodyLeftLegColor@@', 0x144), ('?bodyRightLegColor@@', 0x148),
                      ('?accState@@', 0x154), ('?accAttachmentPoint@@', 0x158), ('?accHandleTouched@@', 0x188),
                      ('?accChildAdded@@', 0x19c), ('?accChildRemoved@@', 0x1b0)):
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    assert body == b'\xb8' + struct.pack('<I', value) + b'\xc3', (prefix, body.hex())
for prefix, value in (('?accEquipable@@', 0x130), ('?accRenderable@@', 0x140)):
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    assert bytes.fromhex('05') + struct.pack('<I', value) in body, (prefix, body.hex())   # add eax, n after null test

original = nb.Original()
u = lambda va: struct.unpack('<I', original.data(va, 4))[0]

# Externals whose addresses are asserted (call targets named in the evidence or proven elsewhere).
KNOWN = {
    '??0Instance@RBX@@IAE@XZ': 0x55b7e0, '??1Instance@RBX@@MAE@XZ': 0x55a540,
    '?setName@Instance@RBX@@UAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': 0x55af90,
    '?declare@Name@RBX@@SAABV12@PBDH@Z': 0x553f90,
    '?classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3QBDBVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ': 0x40ad80,
    '?raisePropertyChanged@Instance@RBX@@QAEXABVPropertyDescriptor@Reflection@2@@Z': 0x40db00,
    '?dataChanged@CharacterAppearance@RBX@@IAEXABVPropertyDescriptor@Reflection@2@@Z': 0x5d3b50,
    '?askSetParent@CharacterAppearance@RBX@@MBE_NPBVInstance@2@@Z': 0x5d7640,
    '?onAncestorChanged@CharacterAppearance@RBX@@MAEXABUAncestorChanged@2@@Z': 0x5d4c40,
    '?apply@BodyColors@RBX@@MAEXPAVHumanoid@2@@Z': 0x5d4b60,
    '?getHead@Humanoid@RBX@@QBEPAVPartInstance@2@XZ': 0x5d8a10,
    '?getTorso@Humanoid@RBX@@QBEPAVPartInstance@2@XZ': 0x5d8b10,
    '?getLeftLeg@Humanoid@RBX@@QBEPAVPartInstance@2@XZ': 0x5d8c10,
    '?getRightLeg@Humanoid@RBX@@QBEPAVPartInstance@2@XZ': 0x5d8d10,
    '?getLeftArm@Humanoid@RBX@@QBEPAVPartInstance@2@XZ': 0x5d8e10,
    '?getRightArm@Humanoid@RBX@@QBEPAVPartInstance@2@XZ': 0x5d8f10,
    '?setColor@PartInstance@RBX@@QAEXVBrickColor@2@@Z': 0x59df40,
    '?sBodyColors@RBX@@3QBDB': 0x83c1c4,
    '?prop_HeadColor@BodyColors@RBX@@2V?$BoundProp@VBrickColor@RBX@@$00@Reflection@2@A': 0x979fa8,
    '?prop_LeftArmColor@BodyColors@RBX@@2V?$BoundProp@VBrickColor@RBX@@$00@Reflection@2@A': 0x97a06c,
    '?prop_RightArmColor@BodyColors@RBX@@2V?$BoundProp@VBrickColor@RBX@@$00@Reflection@2@A': 0x97a0dc,
    '?prop_TorsoColor@BodyColors@RBX@@2V?$BoundProp@VBrickColor@RBX@@$00@Reflection@2@A': 0x97a0a4,
    '?prop_LeftLegColor@BodyColors@RBX@@2V?$BoundProp@VBrickColor@RBX@@$00@Reflection@2@A': 0x97a088,
    '?prop_RightLegColor@BodyColors@RBX@@2V?$BoundProp@VBrickColor@RBX@@$00@Reflection@2@A': 0x979fc4,
    # Accoutrement / Hat
    '?sAccoutrement@RBX@@3QBDB': 0x8349f8, '?sHat@RBX@@3QBDB': 0x834a08,
    '??0IEquipable@RBX@@IAE@XZ': 0x628fc0, '??0CoordinateFrame@G3D@@QAE@XZ': 0x4782d0,
    '?setAttachmentPoint@Accoutrement@RBX@@QAEXABVCoordinateFrame@G3D@@@Z': 0x5b2670,
    '?setAttachmentForward@Accoutrement@RBX@@QAEXABVVector3@G3D@@@Z': 0x5b2750,
    '?setAttachmentUp@Accoutrement@RBX@@QAEXABVVector3@G3D@@@Z': 0x5b28d0,
    '?setAttachmentRight@Accoutrement@RBX@@QAEXABVVector3@G3D@@@Z': 0x5b2a40,
    '?onAncestorChanged@Accoutrement@RBX@@MAEXABUAncestorChanged@2@@Z': 0x5b25f0,
    '?readProperty@Accoutrement@RBX@@MAEXPBVXmlElement@@AAVIReferenceBinder@2@@Z': 0x5b0840,
    '?write@Accoutrement@RBX@@UAEPAVXmlElement@@XZ': 0x5b1480,
    '?getLocation@Accoutrement@RBX@@MBE?BVCoordinateFrame@G3D@@XZ': 0x5b0b70,
    '?onCameraNear@Accoutrement@RBX@@UAEXM@Z': 0x5b0fa0,
    '?render3dSelect@Accoutrement@RBX@@MAEXPAVAdorn@2@W4SelectState@2@@Z': 0x5b1020,
    '?prop_AttachmentPoint@RBX@@3V?$PropDescriptor@VAccoutrement@RBX@@VCoordinateFrame@G3D@@@Reflection@2@A': 0x976d20,
    '?prop_AttachmentPos@RBX@@3V?$PropDescriptor@VAccoutrement@RBX@@VVector3@G3D@@@Reflection@2@A': 0x976ce8,
    '?prop_AttachmentForward@RBX@@3V?$PropDescriptor@VAccoutrement@RBX@@VVector3@G3D@@@Reflection@2@A': 0x976d3c,
    '?prop_AttachmentUp@RBX@@3V?$PropDescriptor@VAccoutrement@RBX@@VVector3@G3D@@@Reflection@2@A': 0x976cb0,
    '?prop_AttachmentRight@RBX@@3V?$PropDescriptor@VAccoutrement@RBX@@VVector3@G3D@@@Reflection@2@A': 0x976d04,
    '?prop_BackendAccoutrementState@RBX@@3V?$PropDescriptor@VAccoutrement@RBX@@H@Reflection@2@A': 0x976ccc,
    # Shared externals (addresses also asserted by record_native_team / body_movers / network_player /
    # effects / camera_units; 0x628f80 is the IEquipable destructor called from ~Accoutrement 005b0da0,
    # identical-code-folded with boost stored_group's shared_ptr release; 0x40ab30 folds the three
    # MemberDescriptorContainer destructors, called from ~ClassDescriptor 0x40abc0, a verified helper row).
    '??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z': 0x5708f0,
    '??1ClassDescriptor@Reflection@RBX@@UAE@XZ': 0x40abc0,
    '??1?$MemberDescriptorContainer@VFunctionDescriptor@Reflection@RBX@@@Reflection@RBX@@QAE@XZ': 0x40ab30,
    '??1?$MemberDescriptorContainer@VPropertyDescriptor@Reflection@RBX@@@Reflection@RBX@@QAE@XZ': 0x40ab30,
    '??1?$MemberDescriptorContainer@VSignalDescriptor@Reflection@RBX@@@Reflection@RBX@@QAE@XZ': 0x40ab30,
    '??0?$TypedPropertyDescriptor@H@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@H@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x4432a0,
    '??0?$TypedPropertyDescriptor@VBrickColor@RBX@@@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@VBrickColor@RBX@@@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x48b180,
    '??0?$TypedPropertyDescriptor@VCoordinateFrame@G3D@@@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@VCoordinateFrame@G3D@@@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x584440,
    '??0?$TypedPropertyDescriptor@VVector3@G3D@@@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@VVector3@G3D@@@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x59a4b0,
    '??0Instance@RBX@@QAE@XZ': 0x55b7e0, '??1Instance@RBX@@UAE@XZ': 0x55a540,
    '??0Matrix3@G3D@@QAE@ABV01@@Z': 0x513220, '?getColumn@Matrix3@G3D@@QBE?AVVector3@2@H@Z': 0x513240,
    '?zLookDirection@CoordinateFrame@G3D@@2MB': 0x828b60,
    '??1IEquipable@RBX@@MAE@XZ': 0x628f80, '??1IRenderable@RBX@@QAE@XZ': 0x47d410,
    '??1scoped_connection@signals@boost@@QAE@XZ': 0x5954b0, '?disconnect@connection@signals@boost@@QBEXXZ': 0x595230,
    '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330, '_atexit': 0x6a17af,
    # file-static descriptors as named in the atexit destructors
    '_prop_AttachmentPoint': 0x976d20, '_prop_AttachmentPos': 0x976ce8, '_prop_AttachmentForward': 0x976d3c,
    '_prop_AttachmentUp': 0x976cb0, '_prop_AttachmentRight': 0x976d04, '_prop_BackendAccoutrementState': 0x976ccc,
    '??3?$Creatable@VInstance@RBX@@@RBX@@CAXPAX@Z': None,  # inline operator delete (free import), never a target
}

BODY_ROWS = [
    ('005d3ec0', '??0?$FactoryProduct@VBodyColors@'), ('005d5350', '??0?$DescribedCreatable@VBodyColors@'),
    ('005d59c0', '??0BodyColors@RBX@@'),
    ('005c0240', '?classDescriptor@?$Described@VBodyColors@'), ('005d42b0', '?getClassName@?$FactoryProduct@VBodyColors@'),
    ('005d3ca0', '??1?$FactoryProduct@VBodyColors@'), ('005d5af0', '??_GBodyColors@RBX@@'),
    ('005d4f90', '??$?0VBodyColors@RBX@@@?$BoundProp@VBrickColor@'),
    ('007f6150', '??__E?prop_HeadColor@'), ('007f6180', '??__E?prop_LeftArmColor@'), ('007f61b0', '??__E?prop_RightArmColor@'),
    ('007f61e0', '??__E?prop_TorsoColor@'), ('007f6210', '??__E?prop_LeftLegColor@'), ('007f6240', '??__E?prop_RightLegColor@'),
    # adjustor thunks of the BodyColors vtables (this -= n, jmp ??_GBodyColors)
    ('005d3d00', '??_EBodyColors@RBX@@WGE@'), ('005d3d10', '??_EBodyColors@RBX@@WKE@'), ('005d3d20', '??_EBodyColors@RBX@@WBDA@'),
    ('005d53f0', '??_EBodyColors@RBX@@WCE@'), ('005d5400', '??_EBodyColors@RBX@@WIE@'), ('005d5410', '??_EBodyColors@RBX@@WME@'),
    ('005d5ac0', '??_EBodyColors@RBX@@WEE@'), ('005d5ad0', '??_EBodyColors@RBX@@WBA@'), ('005d5ae0', '??_EBodyColors@RBX@@WBE@'),
]
PENDING_ROWS = [('005d4b60', '?apply@BodyColors@'), ('005d4460', '??$findModifierOfType@VSkin@')]
ACC_ROWS = [
    ('005b0a60', '??0?$FactoryProduct@VAccoutrement@'), ('005b2140', '??0?$DescribedCreatable@VAccoutrement@'),
    ('005b2230', '??0Accoutrement@RBX@@'), ('005b23f0', '??0?$FactoryProduct@VHat@'),
    ('005b2bb0', '??0?$DescribedCreatable@VHat@'), ('005b2d10', '??0Hat@RBX@@'),
    ('005b1950', '?classDescriptor@?$Described@VAccoutrement@'), ('005b19c0', '?classDescriptor@?$Described@VHat@'),
    ('005b16e0', '?getClassName@?$FactoryProduct@VAccoutrement@'), ('005b1700', '?getClassName@?$FactoryProduct@VHat@'),
    ('005b0a00', '??1?$FactoryProduct@VAccoutrement@'), ('005b0da0', '??1Accoutrement@RBX@@UAE@XZ'),
    ('005b1230', '??1?$FactoryProduct@VHat@'),
    ('005b0820', '?getBackendAccoutrementState@'), ('005b0830', '?getAttachmentPoint@'),
    ('005b0920', '?downFrom_InCharacter@'), ('005b0940', '?getAttachmentPos@'), ('005b0970', '?getAttachmentForward@'),
    ('005b09c0', '?getAttachmentUp@'), ('005b09e0', '?getAttachmentRight@'),
    ('005b24e0', '?setBackendAccoutrementState@'), ('005b2700', '?setAttachmentPos@'),
    ('005b1a30', '??$?0P8Accoutrement@RBX@@BEABVCoordinateFrame@'), ('005b1b00', '??$?0P8Accoutrement@RBX@@BE?BVVector3@'),
    ('005b1bd0', '??$?0P8Accoutrement@RBX@@BEHXZ'),
    ('005b0bd0', '?getValue@?$GetSetImpl@P8Accoutrement@RBX@@BEABVCoordinateFrame@'),
    ('005b0c30', '?getValue@?$GetSetImpl@P8Accoutrement@RBX@@BE?BVVector3@'),
    ('005b0c90', '?getValue@?$GetSetImpl@P8Accoutrement@RBX@@BEHXZ'),
    ('007f4fb0', '??__Eprop_AttachmentPoint@'), ('007f5010', '??__Eprop_AttachmentPos@'),
    ('007f5070', '??__Eprop_AttachmentForward@'), ('007f50d0', '??__Eprop_AttachmentUp@'),
    ('007f5130', '??__Eprop_AttachmentRight@'), ('007f5190', '??__Eprop_BackendAccoutrementState@'),
]


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

# Subobject offset of each vtable name suffix (RTTI base lists of 0083cc1c BodyColors / 00834bf4 Accoutrement /
# 00835094 Hat, mdisp; the virtual bases ILocation/ICameraSubject sit at +0x1c8/+0x1d0 from the constructor).
SUBOBJECT = {'?$GuidItem@': 0, '?$AbstractFactoryProduct@': 0x10, '?$Described@VInstance@': 0x14, 'Debugable@': 0x20,
             '?$Notifier@VInstance@RBX@@UChildAdded@': 0x24, '?$Notifier@VInstance@RBX@@UChildRemoved@': 0x44,
             '?$Notifier@VInstance@RBX@@UDescendantAdded@': 0x64, '?$Notifier@VInstance@RBX@@UDescendantRemoving@': 0x84,
             '?$Notifier@VInstance@RBX@@UAncestorChanged@': 0xa4, '?$Notifier@VInstance@RBX@@VPropertyChanged@': 0xc4,
             'IEquipable@': 0x130, 'IRenderable@': 0x140, 'ILocation@': 0x1c8, 'ICameraSubject@': 0x1d0,
             '@': 0x130}   # bare suffix: BodyColors' IModelModifier vtable


def subobject(symbol):
    sub = symbol[symbol.index('@@6B') + 4:]
    return SUBOBJECT[next(k for k in SUBOBJECT if sub.startswith(k))]


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
        assert len(target) == len(body) and match.exact_match(target, target_refs, body, refs), (address, name, len(body), len(target))
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
        if 'Reflection' not in cls:   # Instance-derived: the suffix names the subobject
            assert off == subobject(symbol), (where, symbol, hex(off))
        binder.bind(where, symbol, value)
        return '%s (RTTI %s, offset %#x)' % (hex(value), rtti, off)
    if symbol.startswith('??_8'):
        # vbtable: the original words must equal the compiled table (displacements, no relocations)
        pos, at = definitions[symbol]
        mine = raw[sections[at][4] + pos:sections[at][4] + pos + 12]
        size = 12 if symbol.endswith('7B01@@') or 'Accoutrement@1@@' in symbol else 8
        assert original.data(value, size) == mine[:size], (where, symbol, hex(value), mine.hex())
        binder.bind(where, symbol, value)
        return '%s (vbtable %s)' % (hex(value), mine[:size].hex())
    if symbol.startswith('__real@'):
        assert original.data(value, 4) == bytes.fromhex(symbol[7:15])[::-1], (where, symbol)
        return hex(value)
    return binder.bind(where, symbol, value)


body_rows = rows_for(base_obj, BODY_ROWS)
acc_rows = rows_for(acc_obj, ACC_ROWS)

# GetSet vtable of the BodyColors BoundProp (stored by 005d4f90): the 2008 GetSet has two leading bool
# virtuals (0060a2f0 twice, see the Clothing reflection proposal), so its getValue/setValue are slots 2/3. They
# are identical-code-folded with the Skin instantiation (006334f0 / 0063b210); compare our bodies there.
getset_vt = binder.seen['??_7?$BoundPropGetSet@VBodyColors@RBX@@@?$BoundProp@VBrickColor@RBX@@$00@Reflection@RBX@@6B@']
assert getset_vt == 0x83c4a8, hex(getset_vt)
assert [u(getset_vt + 4 * i) for i in range(4)] == [0x60a2f0, 0x60a2f0, 0x6334f0, 0x63b210]
getset_rows = rows_for(base_obj, [('006334f0', '?getValue@?$BoundPropGetSet@VBodyColors@'),
                                  ('0063b210', '?setValue@?$BoundPropGetSet@VBodyColors@')])
# Accoutrement GetSetImpl vtables (bound from the getset<> factories): slots 0/1 are the two bool virtuals,
# slot 2 getValue (rows above); slot 3 setValue is not claimed (the 2008 bodies differ from the donor shape).
for symbol, getter in (('??_7?$GetSetImpl@P8Accoutrement@RBX@@BEABVCoordinateFrame@G3D@@XZP812@AEXABV34@@Z@?$PropDescriptor@VAccoutrement@RBX@@VCoordinateFrame@G3D@@@Reflection@RBX@@6B@', 0x5b0bd0),
                       ('??_7?$GetSetImpl@P8Accoutrement@RBX@@BE?BVVector3@G3D@@XZP812@AEXABV34@@Z@?$PropDescriptor@VAccoutrement@RBX@@VVector3@G3D@@@Reflection@RBX@@6B@', 0x5b0c30),
                       ('??_7?$GetSetImpl@P8Accoutrement@RBX@@BEHXZP812@AEXH@Z@?$PropDescriptor@VAccoutrement@RBX@@H@Reflection@RBX@@6B@', 0x5b0c90)):
    vt = binder.seen.get(symbol)
    if vt is not None:
        assert [u(vt + 4 * i) for i in range(3)] == [0x60a2f0, 0x60a2f0, getter], (symbol, hex(vt))


def vtable_slots(obj, name):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    start, index = definitions[name]
    section = sections[index]
    slots = {}
    for i in range(section[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10 * i)
        if offset >= start and kind == 6:
            slots[(offset - start) // 4] = symbols[symbol][0]
    return slots


# Every vtable of BodyColors / Accoutrement / Hat (RTTI survey; each constructor stores each one) and of their
# FactoryProduct / DescribedCreatable bases (addresses bound from their constructors). Slots are read from the
# objects built from the current headers (not the pending build).
FAMILY_VTABLES = {
    'BodyColors@RBX@@': {0: 0x83cc1c, 0x10: 0x83cc10, 0x14: 0x83cc08, 0x20: 0x83cc00, 0x24: 0x83cbf0, 0x44: 0x83cbe0,
                         0x64: 0x83cbd0, 0x84: 0x83cbc0, 0xa4: 0x83cbb0, 0xc4: 0x83cba0, 0x130: 0x83cb98},
    'Accoutrement@RBX@@': {0: 0x834bf4, 0x10: 0x834be8, 0x14: 0x834be0, 0x20: 0x834bd8, 0x24: 0x834bc8, 0x44: 0x834bb8,
                           0x64: 0x834ba8, 0x84: 0x834b98, 0xa4: 0x834b88, 0xc4: 0x834b78, 0x130: 0x834b70,
                           0x140: 0x834b58, 0x1c8: 0x834b50, 0x1d0: 0x834b34},
    'Hat@RBX@@': {0: 0x835094, 0x10: 0x835084, 0x14: 0x83507c, 0x20: 0x835074, 0x24: 0x835064, 0x44: 0x835054,
                  0x64: 0x835044, 0x84: 0x835034, 0xa4: 0x835024, 0xc4: 0x835014, 0x130: 0x83500c,
                  0x140: 0x834ff4, 0x1c8: 0x834fec, 0x1d0: 0x834fd0},
}
vtables = []
for obj, family in ((base_obj, ('BodyColors',)), (acc_obj, ('Accoutrement', 'Hat'))):
    raw = obj.read_bytes()
    _, _, definitions, _ = match._coff_data_index(raw)
    for name in sorted(n for n in definitions if n.startswith('??_7') and '@@6B' in n):
        cls = name[4:name.index('@@6B') + 2]
        if 'Reflection' in cls or not any(('V%s@' % f) in cls or cls == '%s@RBX@@' % f for f in family):
            continue
        off = subobject(name)
        if cls in FAMILY_VTABLES:
            address = FAMILY_VTABLES[cls][off]
            binder.bind('vtable', name, address)
        else:
            if name not in binder.seen:   # template base vtable never stored by a claimed row
                continue
            address = binder.seen[name]
        rtti, roff = original.vtable_class(address)
        assert rtti.replace('3QBDB', '3PBDB') == ('.?AV' + cls).replace('3QBDB', '3PBDB') and roff == off, (name, rtti, roff)
        slots = vtable_slots(obj, name)
        assert sorted(slots) == list(range(len(slots))), (name, slots)
        entries = {}
        for slot, symbol in sorted(slots.items()):
            value = u(address + 4 * slot)
            entries[slot] = '%s -> %s' % (symbol, hex(value))
            binder.bind(name, symbol, value)
        vtables.append({'class': cls, 'subobject': hex(off), 'vtable': hex(address), 'slots': entries})
assert u(0x83cc1c + 64) == 0x5d4b60
# Inline askSetParent/askAddChild (return true) fill Accoutrement slots 2/3 with 00565ff0 (ICF fold): compare bytes.
_acc_funcs = {n: b for n, b, r in match.coff_functions(acc_obj.read_bytes())}
for _name in ('?askSetParent@Accoutrement@RBX@@MBE_NPBVInstance@2@@Z', '?askAddChild@Accoutrement@RBX@@MBE_NPBVInstance@2@@Z'):
    assert binder.seen[_name] == 0x565ff0 and original.data(0x565ff0, len(_acc_funcs[_name])) == _acc_funcs[_name], _name
assert sum(1 for v in vtables if v['class'] in FAMILY_VTABLES) == 11 + 14 + 14, len(vtables)

def masked_equal(raw, sections, definitions, name, body, target):
    start, section = definitions[name]
    table = sections[section]
    a, b = bytearray(body), bytearray(target)
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        offset -= start
        if 0 <= offset < len(body):
            a[offset:offset + 4] = b[offset:offset + 4] = b'\0\0\0\0'
    return a == b


# Template helpers and thunks reached only through bindings: callDoDeclare / doDeclare, static-descriptor atexit
# destructors, getset<> factories, adjustor / vtordisp thunks and destructors of the base templates. Verify each
# body whose address the binder learned; report (do not count) any that differ.
counted = {(r['symbol'], r['address']) for r in body_rows + getset_rows + acc_rows}
extra_rows, helper_misses, bounds_rows = [], [], []
objects = []
for obj in (base_obj, acc_obj):
    raw = obj.read_bytes()
    objects.append((raw, {n: (b, r) for n, b, r in match.coff_functions(raw)}, match._coff_data_index(raw)))
while True:   # thunks bound by helper rows reveal further targets (e.g. ??_E -> ??_G): iterate to a fixpoint
    learned = len(counted)
    for raw, funcs, (sections, symbols, definitions, _) in objects:
        for symbol, value in sorted(binder.seen.items()):
            if not re.match(r'^(\?\?\$callDoDeclare@|\?\?\$doDeclare@|\?\?\$getset@|\?\?__F|\?\?_E|\?\?_G|\?\?1|'
                            r'\?getLocation@Accoutrement@RBX@@\$|\?onCameraNear@Accoutrement@RBX@@\$)', symbol):
                continue
            own = symbol
            if own not in funcs and own.startswith('??_E') and ('??_G' + own[4:]) in funcs:
                own = '??_G' + own[4:]   # scalar deleting destructor referenced as the vector one
            if own not in funcs or (own, '%08x' % value) in counted:
                continue
            counted.add((own, '%08x' % value))
            body, refs = funcs[own]
            started = True
            try:
                target, target_refs, _ = match.target('2008-06', '%08x' % value)
                same = len(target) == len(body) and match.exact_match(target, target_refs, body, refs)
            except SystemExit:
                started = False
                # no analyzed function start (e.g. ??_GAccoutrement 005b15c0 sits inside write's extent):
                # compare the original bytes directly with this object's relocation fields masked
                target = original.data(value, len(body))
                same = masked_equal(raw, sections, definitions, own, body, target)
            if not same:
                helper_misses.append('%08x %s' % (value, own))
                continue
            row = check_relocs(raw, sections, symbols, definitions, own, body, value, target)
            if not started:   # byte-verified (and used to pin thunk targets) but not a countable server row
                row['exact'] = False
                row['status'] = 'bytes-exact-no-function-start'
                bounds_rows.append(row)
                continue
            extra_rows.append(row)
    if len(counted) == learned:
        break
for m in helper_misses:
    print('  helper not exact:', m[:110])

# Pending build (generated header copies): recorded, never counted.
pending_rows = []
for address, prefix in PENDING_ROWS:
    try:
        row = rows_for(pend_obj, [(address, prefix)])[0]
        row['exact'] = False
        row['status'] = 'pending-build-only'
    except AssertionError as e:
        row = {'address': address, 'symbol': prefix, 'exact': False, 'reason': 'pending build differs: %s' % (e,)}
    pending_rows.append(row)

exact_rows = body_rows + getset_rows + acc_rows + extra_rows
distinct = sorted({r['address'] for r in exact_rows})
pending_only = sorted({r['address'] for r in pending_rows if r.get('status') == 'pending-build-only'} - set(distinct))

# Every relocation target of every counted row must be pinned: an import, string, RTTI/vtable/vbtable (checked by
# class and subobject), a float constant, a KNOWN address, a function-local static, or a function this recorder
# verified exact itself (same symbol, same address). Consistency-only bindings are refused.
verified_own = {}
for row in exact_rows + bounds_rows + [r for r in pending_rows if r.get('status') == 'pending-build-only']:
    verified_own.setdefault(row['symbol'], set()).add(int(row['address'], 16))
deleting_dtors = {int(r['address'], 16) for r in exact_rows if r['symbol'].startswith('??_G')}
LOCAL_STATIC = re.compile(r'^(\?\?_B\?1|\?flag@\?1|\?n@\?1|\?descriptor@\?1)')
unpinned = []
for row in exact_rows + bounds_rows + [r for r in pending_rows if r.get('status') == 'pending-build-only']:
    for symbol, how in row['targets'].items():
        if not how.startswith('bound '):
            continue
        value = int(how.split()[1], 16)
        if symbol in KNOWN or LOCAL_STATIC.match(symbol):
            continue
        alias = '??_G' + symbol[4:] if symbol.startswith('??_E') else symbol
        if value in verified_own.get(symbol, ()) or value in verified_own.get(alias, ()):
            continue
        if symbol.startswith('??_E') and value in deleting_dtors:
            continue   # identical-code-folded scalar deleting destructor verified under another class's name
        unpinned.append('%s -> %s %s' % (row['address'], hex(value), symbol[:100]))
for m in unpinned:
    print('  unpinned target:', m)
print('exact rows: %d (BodyColors %d, getset %d, Accoutrement/Hat %d, helpers %d)' % (
    len(exact_rows), len(body_rows), len(getset_rows), len(acc_rows), len(extra_rows)))
for row in exact_rows:
    print('  %s %4d %s' % (row['address'], row['size'], row['symbol'][:100]))
for row in bounds_rows:
    print('  bounds %s %s %s' % (row['address'], row['status'], row['symbol'][:80]))
for row in pending_rows:
    print('  pending %s %s %s' % (row['address'], row['exact'], row['symbol'][:80]))

sha = nb.sha
paths = [Path(__file__).resolve(), HEADER, SOURCE, ACC_HEADER, ACC_SOURCE, LAYOUT, HUMANOID, CLOTHING_HEADER]
receipt = {
    'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
    'sources': {str(p.relative_to(ROOT)): sha(p) for p in paths},
    'objects': {'layout': sha(layout_obj), 'bodycolors': sha(base_obj), 'bodycolors_pending': sha(pend_obj),
                'accoutrement': sha(acc_obj)},
    'compiler_build': 21022,
    'flags': {'layout': layout_flags, 'bodycolors': base_flags, 'bodycolors_pending': pend_flags, 'accoutrement': acc_flags},
    'sizes': {'BodyColors': 0x14c, 'CharacterAppearance': 0x134, 'Accoutrement': 0x1d8, 'Hat': 0x1d8},
    'exact_addresses': distinct, 'pending_build_only_addresses': pending_only,
    'body_rows': body_rows, 'getset_rows': getset_rows, 'accoutrement_rows': acc_rows, 'helper_rows': extra_rows,
    'helper_misses': helper_misses, 'bounds_rows': bounds_rows,
    'bounds_note': ['005b15c0 ??_GAccoutrement: byte-identical with bound targets, but the analyzed function '
                    '005b1520 (size 191) runs over it; the original code of 005b1520 ends with ret at 005b15bf, '
                    'so its extent is 0xa0 and 005b15c0 is a separate function (int3-free adjacency). Not counted.'], 'unpinned_targets': unpinned, 'pending_rows': pending_rows, 'vtables': vtables,
    'bindings': {k: hex(v) for k, v in sorted(binder.seen.items())},
    'pending': ['005d4b60 BodyColors::apply and 005d4460 ModelInstance::findModifierOfType<Skin>: exact only with '
                'generated copies of v8datamodel/ModelInstance.h (member template, proposal) and the donor '
                'v8datamodel/Camera.h (extern char sCamera[], no &) under out/native-layouts/appearance-pending-overlay'],
    'open': ['Accoutrement onCameraNear 005b0fa0 / render3dSelect 005b1020: register allocation differs (child loop)',
             'Accoutrement readProperty 005b0840, getHandleConst 005b08a0, getLocation 005b0b70, write 005b1480, '
             'onAncestorChanged 005b25f0, setAttachmentPoint 005b2670, setAttachmentForward/Up/Right '
             '005b2750/005b28d0/005b2a40, GetSetImpl setValue bodies 005b1ca0..005b1fc0 and the state machine: not attempted'],
    'scope': 'Inactive diagnostic: layouts, constructors, destructors, adjustor/vtordisp thunks, factory/reflection '
             'chains, descriptors, static initializers and methods listed are exact with bound targets; pending rows '
             'use generated header copies under out/ and are not counted. Field names are analog names. No runtime swap.',
}
(ROOT / 'work/2008-06/shared-layouts/appearance-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
assert not helper_misses, helper_misses
assert not unpinned, unpinned
print('PASS native BodyColors / Accoutrement / Hat: %d exact rows (%d distinct addresses), +%d pending-build-only '
      '(not counted), %d vtables' % (len(exact_rows), len(distinct), len(pending_only), len(vtables)))
print('exact:', ' '.join(distinct))
