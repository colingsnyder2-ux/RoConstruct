"""Verify the inactive 2008-06 native rows of the code after the GuiBuilder unit (006060b0..0060c000).

Unit map of the range (boundary evidence in the receipt's `unit_map`):
  * Connector unit 006060b0..00606a50 (ContactConnector statics 0097b878/0097b87c, the connector getBody /
    computeForce / canThrottle slots, GeoPair::match 00606a50): world-joints-working.json counts 00606150..006062c0
    and 00606d40; this recorder adds PointToPointBreakConnector::computeForce 006065d0
    (native-classes/ContactUnit2008Connector.cpp, against native-headers/v8kernel/Connector2008.h, read-only).
  * Contact unit 00606b00..00608945 (Contact statics 0097b880..0097b88c, Contact / BallBall / BallBlock /
    BlockBlockContact): world-shapes / leaves2008 count their rows; the remaining rows need the 2008 Primitive /
    Body layouts (reported, not built).
  * PVInstance unit 00608950..00609a1f (native-classes/ContactUnit2008PVInstance.cpp against the shared
    native-headers/v8datamodel/PVInstance.h, read-only).
  * Feature / VelocityMotor unit 00609a30..: feature-working.json.

Builds (document-swap flags, VS2008 RTM 21022):
  * ContactUnit2008Connector.cpp with /fp:fast /U_RELEASEASSERT (the world-joints connector profile: without /fp:fast
    the force arithmetic is 259 bytes);
  * ContactUnit2008PVInstance.cpp with /U_RELEASEASSERT (the 2008 rbx_static_cast has no dynamic_cast check:
    computeIsTopFlag 006090c0 reads the parent +0x104 directly);
  * ContactUnit2008PVInstance.cpp again with /DNATIVE_CONTACTUNIT_PENDING and a generated copy of the native
    v8tree/Instance.h that declares Instance::readProperties (00557920) under out/native-layouts/contact-unit2008-pending.
    Rows exact only there are recorded exact=false (pending-build-only) and never counted.

Every counted row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified: imports by DLL export name, string literals by bytes, constants by bytes,
type descriptors and vtables by original RTTI names, vbtables by their bytes, own symbols by the row proven here, and
the remaining externals by the explicit EXTERNAL / DATA maps (call sites read in the original disassembly). A symbol
binds to one address across all rows. Every vtable an exact row references is compared slot by slot from the
current-header object (never the pending one): a slot is accepted when the compiled slot function is an own row at that
address, its body is relocation-masked exact against the original slot target (folded / out-of-unit instances), or it
is an explicitly bound external. A row is counted only when it is not already counted by another receipt (top-level
exact_function_rows, or exact_addresses / exact_unique_addresses / exact method entries for older receipts).
Writes work/2008-06/shared-layouts/contact-unit2008-working.json.
Set NATIVE_CONTACT_UNIT_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
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
OUT = nb.OUT
OUT.mkdir(parents=True, exist_ok=True)
SOURCES = {
    'conn': R / 'native-classes/ContactUnit2008Connector.cpp',
    'pv': R / 'native-classes/ContactUnit2008PVInstance.cpp',
}
UNIT = {'conn': ['/fp:fast', '/U_RELEASEASSERT'], 'pv': ['/U_RELEASEASSERT']}
DISCOVER = bool(os.environ.get('NATIVE_CONTACT_UNIT_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/contact-unit2008-working.json'

# ---- generated pending header (a copy under out/; the shared Instance.h is not edited) -----------------------------
PENDING = OUT / 'contact-unit2008-pending'
(PENDING / 'v8tree').mkdir(parents=True, exist_ok=True)
INSTANCE_H = R / 'native-headers/v8tree/Instance.h'
_anchor = '    void readChildren(const ::XmlElement*, IReferenceBinder&);\n'
_text = INSTANCE_H.read_text()
assert _text.count(_anchor) == 1
(PENDING / 'v8tree/Instance.h').write_text(_text.replace(
    _anchor, _anchor + '    void readProperties(const ::XmlElement*, IReferenceBinder&); // 00557920\n'))
PENDING_FLAGS = ['/I' + str(PENDING), '/DNATIVE_CONTACTUNIT_PENDING']
PROPOSALS = {
    'native-headers/v8tree/Instance.h (core owner)': (
        'declare `void readProperties(const ::XmlElement*, IReferenceBinder&);` public (evidence name '
        '?readProperties@Instance@RBX@@QAEXPBVXmlElement@@AAVIReferenceBinder@2@@Z at 00557920, called by '
        'PVInstance::readProperty 006089a0 at 00608a12 / 00608a42). With it PVInstance::readProperty is exact '
        '(pending build, generated copy out/native-layouts/contact-unit2008-pending/v8tree/Instance.h).'),
    'native-headers/v8datamodel/PVInstance.h (owner of the shared PVInstance header), FYI': (
        'the header layout is the 2008 one: the constructor 006098d0 and 26 unit rows are exact against it '
        '(IsControllable +0x140, IsTopFlag +0x158, TopPVController +0x170 with the member-function pointer at +0x180, '
        'controllerType +0x194, showControllerFlag +0x198, legacyOffset +0x19c, vbptr +0x134). No change needed.'),
    'native-headers/reflection/reflection.h (reflection owner)': (
        'the 2008 EnumPropDescriptor<PVInstance, ControllerType> constructor 00609590 (244 B) first runs '
        'boost::call_once(00609400, flag 0097b98c), where 00609400 is `jmp EnumDesc<ControllerType>::singleton` '
        '006093a0, then calls singleton() and PropertyDescriptor(classDescriptor, type, ...) 0056c650; the native '
        'reflection.h constructor (195 B) calls the singleton once without call_once. Not changed here.'),
    'v8world/Contact2008.h, v8kernel/Connector2008.h, a native 2008 Body / Primitive header (world / kernel owners)': (
        'the remaining Connector / Contact unit rows need: Body pv at +0x94.. (NormalBreakConnector::computeForce '
        '00606670 reads [body + 4 * i + 0x94/0xa0/0xac] after Body::updatePV 00599360), Body canThrottle +0x30 '
        '(00606250), Primitive geometry +0x9c / body +0xa0 / friction +0xb0 / elasticity +0xb4 / jointK ComputeProp '
        '+0xec..+0xf8 (00606e90, 00607ad0), and declarations Contact::step(int) 00606c50, computeIsAdjacent 00606ca0, '
        'createConnector 00606e00 and the static hit-ratio counters (00606bc0 contactPairHitRatio reads '
        '0097b880/0097b884, 00606bf0 contactFeatureHitRatio reads 0097b888/0097b88c, 00606100 percentConnectorsActive '
        'reads and resets 0097b878/0097b87c, written by ContactConnector::computeForce 00606834 / 00606a1d; DataModel::'
        'evaluate 005760a1 / 005760d5 / 005762f3 names them by the strings "contactPairHitRatio", '
        '"contactFeatureHitRatio" and "percentConnectorsActive").'),
}


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


OBJ, FLAGS = {}, {}
for key, src in SOURCES.items():
    OBJ[key], FLAGS[key] = build('NativeContactUnit2008_' + key, src, UNIT[key])
OBJ['pv_pending'], FLAGS['pv_pending'] = build('NativeContactUnit2008_pv_pending', SOURCES['pv'],
                                               PENDING_FLAGS + UNIT['pv'])

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}


def norm(symbol):
    return symbol.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


STR = '?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@'
# ---- externals: address the original instruction uses, read at the call sites listed ----------------
EXTERNAL = {
    '??2@YAPAXI@Z': 0x6a0920, '??3@YAXPAX@Z': 0x6a067a, '___RTDynamicCast': 0x6a17c6, '_atexit': 0x6a17af,
    '__CxxThrowException@8': 0x6a158c,
    '?findWorkspace@Workspace@RBX@@SAPAV12@PBVInstance@2@@Z': 0x5a3380,              # moveToPoint 00608964
    '?moveToPoint@RootInstance@RBX@@QAEXPAVPVInstance@2@VVector3@G3D@@@Z': 0x5909e0,   # 0060898c
    '?numChildren@Instance@RBX@@QBEIXZ': 0x48ae20,                                     # 00608d2b, 00608da8, 00608fc1
    '?onDescendentAdded@Instance@RBX@@MAEXPAV12@@Z': 0x55ae20,                         # 00608ba8
    '?onDescendentRemoving@Instance@RBX@@MAEXABV?$shared_ptr@VInstance@RBX@@@boost@@@Z': 0x55ae90,   # 00608be4
    '?raisePropertyChanged@Instance@RBX@@QAEXABVPropertyDescriptor@Reflection@2@@Z': 0x40db00,  # 006099ec, 00609a1a
    '??0Instance@RBX@@IAE@PBD@Z': 0x55b960,                                            # PVInstance() 00609906
    '??0Instance@RBX@@QAE@PBD@Z': 0x55b960,            # same call, native Instance.h access spelling (public)
    # native Instance.h spells these virtuals public (U); the evidence names are protected (M): same addresses
    '?onDescendentAdded@Instance@RBX@@UAEXPAV12@@Z': 0x55ae20,
    '?onDescendentRemoving@Instance@RBX@@UAEXABV?$shared_ptr@VInstance@RBX@@@boost@@@Z': 0x55ae90,
    # EnumDesc<ControllerType> (singleton 006093a0 / ~EnumDesc 006091f0): the constructor is in the Controller unit
    '??0?$EnumDesc@W4ControllerType@Controller@RBX@@@Reflection@RBX@@AAE@XZ': 0x615280,   # 006093d5
    '??1EnumDescriptor@Reflection@RBX@@MAE@XZ': 0x56c080,                              # 006091f0 tail
    # ICF-shared STL bodies (same as record_native_feature.py's EnumDesc rows)
    '??1?$_Tree@V?$_Tmap_traits@PBVName@RBX@@W4ControllerType@Controller@2@U?$less@PBVName@RBX@@@std@@V?$allocator@U?$pair@QBVName@RBX@@W4ControllerType@Controller@2@@std@@@6@$0A@@std@@@std@@QAE@XZ': 0x553d80,
    '?_Tidy@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXXZ': 0x4077d0,
    '??0?$TypedPropertyDescriptor@VCoordinateFrame@G3D@@@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@VCoordinateFrame@G3D@@@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x584440,   # 00609410 (evidence name)
    '??__Fs@?1??singleton@?$EnumDesc@W4ControllerType@Controller@RBX@@@Reflection@RBX@@SAABV123@XZ@YAXXZ': 0x8001b0,   # atexit argument 006093da
    '??0CoordinateFrame@G3D@@QAE@XZ': 0x4782d0,                                        # setPVGridOffsetLegacy 0060918e
    '?isTopLevelPVInstance@PVInstance@RBX@@QBE_NXZ': 0x5840a0,                         # computeIsTopFlag 00609117
    '?getTopPVController@PVInstance@RBX@@QBEPAVController@2@XZ': 0x59a9e0,             # 0060912a (evidence name)
    '?getValue@?$ComputeProp@V?$ReferenceCountedPointer@VController@RBX@@@G3D@@VPVInstance@RBX@@@RBX@@QBE?AV?$ReferenceCountedPointer@VController@RBX@@@G3D@@XZ': 0x59a0d0,  # 00608e7f
    '?unitZ@Vector3@G3D@@SAABV12@XZ': 0x514910,                                        # renderCoordinateFrame 00608ad3
    '?unitX@Vector3@G3D@@SAABV12@XZ': 0x5148b0,                                        # 00608b11
    # Color3::red/green/blue are ICF-folded with the Vector3 unit statics (same {1,0,0} / {0,1,0} / {0,0,1} bodies)
    '?red@Color3@G3D@@SAABV12@XZ': 0x5148b0, '?green@Color3@G3D@@SAABV12@XZ': 0x5148e0,
    '?blue@Color3@G3D@@SAABV12@XZ': 0x514910,
    '??0Matrix3@G3D@@QAE@ABV01@@Z': 0x513220,
    '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330,
    '??0PropertyDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@ABVType@12@PBD2W4Functionality@012@@Z': 0x56c650,
    '??0?$TypedPropertyDescriptor@_N@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@_N@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x40a290,   # 00609551 (evidence name)
    # Described<PVInstance>::classDescriptor (evidence name mangles 3PBDB; the shared header's sPVInstance is 3PADA)
    '?classDescriptor@?$Described@VPVInstance@RBX@@$1?sPVInstance@2@3PADAVInstance@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ': 0x585090,
}
DATA = {
    '?prop_ControllerType@PVInstance@RBX@@2V?$EnumPropDescriptor@VPVInstance@RBX@@W4ControllerType@Controller@2@@Reflection@2@B': 0x97b994,
    '?prop_ControllerFlagShown@RBX@@3V?$PropDescriptor@VPVInstance@RBX@@_N@Reflection@2@A': 0x97b9d4,
    '?name_name@@3ABVName@RBX@@B': 0x975338,
    '_prop_ControllerFlagShown': 0x97b9d4,
}
# Call targets of rows that are built but not counted (non-exact / bounds): bound at the original instruction.
UNPROVEN = {
    '?computeTopPVController@PVInstance@RBX@@ABE?AV?$ReferenceCountedPointer@VController@RBX@@@G3D@@XZ': 0x609690,  # 00609963
    '?clearLegacyOffset@PVInstance@RBX@@QAEXXZ': 0x608fa0,                            # recursive call 0060900a
}
FOLDED = {}
# (address, symbol or unique prefix); one entry per counted address (folded aliases listed in ALIASES)
ROWS = {
    'conn': [
        (0x6065d0, '?computeForce@PointToPointBreakConnector@RBX@@UAEXM_N@Z'),
    ],
    'pv': [
        (0x608950, '?getShowControllerFlag@PVInstance@RBX@@QBE_NXZ'),
        (0x608960, '?moveToPoint@PVInstance@RBX@@QAEXVVector3@G3D@@@Z'),
        (0x608a60, '?onChildAdded@PVInstance@RBX@@MAEXPAVInstance@2@@Z'),
        (0x608aa0, '?renderCoordinateFrame@PVInstance@RBX@@IAEXPAVAdorn@2@@Z'),
        (0x608b60, '?onChildControllerChanged@PVInstance@RBX@@MAEXXZ'),
        (0x608ba0, '?onDescendentAdded@PVInstance@RBX@@MAEXPAVInstance@2@@Z'),
        (0x608bd0, '?onDescendentRemoving@PVInstance@RBX@@MAEXABV?$shared_ptr@VInstance@RBX@@@boost@@@Z'),
        (0x608bf0, '?onExtentsChanged@PVInstance@RBX@@MBEXXZ'),
        (0x608c20, '?getValue@?$SetImpl@P8PVInstance@RBX@@AEXABVCoordinateFrame@G3D@@@Z@'),
        (0x608c90, '?setValue@?$SetImpl@P8PVInstance@RBX@@AEXABVCoordinateFrame@G3D@@@Z@'),
        (0x608d10, '?onParentControllerChanged@PVInstance@RBX@@MAEXXZ'),
        (0x608da0, '?computeIsControllable@PVInstance@RBX@@ABE_NXZ'),
        (0x608e70, '??B?$ComputeProp@V?$ReferenceCountedPointer@VController@RBX@@@G3D@@VPVInstance@RBX@@@RBX@@QBE'),
        (0x608e90, '??$getset@P8PVInstance@RBX@@AEXABVCoordinateFrame@G3D@@@Z@'),
        (0x608ee0, '??$getset@P8PVInstance@RBX@@BE_NXZ'),
        (0x608f40, '??$getset@P8PVInstance@RBX@@BE?AW4ControllerType@'),
        (0x6090c0, '?computeIsTopFlag@PVInstance@RBX@@ABE_NXZ'),
        (0x609150, '?setPVGridOffsetLegacy@PVInstance@RBX@@QAEXABVCoordinateFrame@G3D@@@Z'),
        (0x6091f0, '??1?$EnumDesc@W4ControllerType@Controller@RBX@@@Reflection@RBX@@EAE@XZ'),
        (0x609380, '??_G?$EnumDesc@W4ControllerType@Controller@RBX@@@Reflection@RBX@@EAEPAXI@Z'),
        (0x6093a0, '?singleton@?$EnumDesc@W4ControllerType@Controller@RBX@@@Reflection@RBX@@SAABV123@XZ'),
        (0x609410, '??$?0HP8PVInstance@RBX@@AEXABVCoordinateFrame@G3D@@@Z@'),
        (0x6094c0, '??$?0P8PVInstance@RBX@@BE_NXZ'),
        (0x6098d0, '??0PVInstance@RBX@@IAE@PBD@Z'),
        (0x6099c0, '?setControllerType@PVInstance@RBX@@QAEXW4ControllerType@Controller@2@@Z'),
        (0x609a00, '?setShowControllerFlag@PVInstance@RBX@@QAEX_N@Z'),
    ],
}
# Identical bodies the original keeps once (ICF): verified exact at the same address, not counted again.
ALIASES = [('pv', 0x608a60, '?onChildRemoving@PVInstance@RBX@@MAEXPAVInstance@2@@Z')]
NON_EXACT_ROWS = [
    (0x609690, '?computeTopPVController@PVInstance@RBX@@ABE?AV', 'pv',
     'the original inlines the top-level test (dynamic_cast of the parent, then an out-of-line getTypedRoot<PVInstance> '
     '005836d0) and keeps one more RCP copy; the native header form calls isTopLevelPVInstance out of line (511 / 573 B). '
     'Rejected: an explicit `queryTypedParent() && getTypedRoot() != getTypedParent()` (602 B, getTypedRoot inlined).'),
    (0x609590, '??$?0P8PVInstance@RBX@@BE?AW4ControllerType@', 'pv',
     'the 2008 EnumPropDescriptor constructor runs boost::call_once(00609400, 0097b98c) before EnumDesc::singleton; '
     'the shared native reflection.h constructor does not (195 / 244 B, see PROPOSALS).'),
]
# BOUNDS: the function list gives 00608fa0 278 bytes, but `ret` at 0060901f ends clearLegacyOffset (128 bytes) and
# 00609020 (`push -1; push 0x7bd3c8`, the EH prologue of ~PVInstance: delete legacyOffset, release TopPVController,
# ~Instance 0055a540) is a separate function that is not in the list. The 128-byte prefix is compared here.
BOUNDS_ROWS = [(0x608fa0, '?clearLegacyOffset@PVInstance@RBX@@QAEXXZ', 'pv', 128)]
PENDING_ROWS = [
    (0x6089a0, '?readProperty@PVInstance@RBX@@MAEXPBVXmlElement@@AAVIReferenceBinder@2@@Z', 'pv_pending',
     'exact only with the generated Instance.h that declares Instance::readProperties 00557920 (see PROPOSALS)'),
]
PENDING_EXTERNAL = {
    '?getTag@XmlElement@@QBEABVName@RBX@@XZ': None,
    '?readProperties@Instance@RBX@@QAEXPBVXmlElement@@AAVIReferenceBinder@2@@Z': 0x557920,
    '?readProperty@Instance@RBX@@MAEXPBVXmlElement@@AAVIReferenceBinder@2@@Z': 0x559170,
    '?readProperty@Instance@RBX@@UAEXPBVXmlElement@@AAVIReferenceBinder@2@@Z': 0x559170,   # native spelling
    '?findAttribute@XmlElement@@QBEPBVXmlAttribute@@ABVName@RBX@@@Z': 0x57c2b0,
    '?getValue@XmlNameValuePair@@QBE_NAAPBVName@RBX@@@Z': 0x57c360,
}
UNBOUND = []
binding = {}


def target_of(address):
    body, refs, _ = match.target('2008-06', '%08x' % address)
    return body, refs


def resolve(obj, rows):
    funcs = match.coff_functions(Path(obj).read_bytes())
    out = []
    for address, key in rows:
        hits = [x for x in funcs if x[0] == key] or [x for x in funcs if x[0].startswith(key) and not nb.LOCAL_EH.match(x[0])]
        if DISCOVER and len(hits) != 1:
            print('UNRESOLVED', '%08x' % address, key[:120], [h[0][:120] for h in hits])
            continue
        assert len(hits) == 1, ('%08x' % address, key, [h[0] for h in hits])
        out.append((address, hits[0][0]))
    return out


def bind_value(raw, sections, symbols, definitions, name, body, target, address, own, extra=None, record=True, limit=None):
    """Verify every relocation of `name` (body compared against target); returns {symbol: proof}, local EH set."""
    start, section = definitions[name]
    table = sections[section]
    code = raw[table[4] + start:]
    verified, local = {}, set()
    size = len(body) if limit is None else limit
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        offset -= start
        if not 0 <= offset < size:
            continue
        symbol = symbols[index][0]
        if kind == 20:
            value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        else:
            value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
        if nb.LOCAL_EH.match(symbol):
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
        elif symbol.startswith('__real@'):
            assert original.data(value, len(symbol[7:]) // 2) == bytes.fromhex(symbol[7:])[::-1], (name, symbol, hex(value))
            how = 'constant %s' % symbol[7:]
        elif symbol.startswith('??_7'):
            rtti, at = original.vtable_class(value)
            cls = symbol[4:symbol.index('@@6B') + 2]
            assert norm(rtti) == norm('.?AV' + cls), (name, symbol, hex(value), rtti)
            VTABLES.setdefault(symbol, value)
            how = 'vtable RTTI %s offset %#x' % (rtti, at)
        elif symbol.startswith('??_8'):
            pos, at = definitions[symbol]
            blob = raw[sections[at][4] + pos:sections[at][4] + pos + 8]
            assert original.data(value, 8) == blob, (name, symbol, hex(value), blob.hex())
            how = 'vbtable bytes %s' % blob.hex()
        elif symbol in own:
            assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
            how = 'own row'
        elif symbol in FOLDED:
            assert FOLDED[symbol] == value, (name, symbol, hex(value))
            how = 'folded'
        elif symbol in DATA:
            assert DATA[symbol] == value, (name, symbol, hex(value))
            how = 'data'
        elif symbol in EXTERNAL:
            assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
            how = 'external' + (' (evidence name)' if norm(names.get(value, '')) == norm(symbol) else '')
        elif symbol in UNPROVEN:
            assert UNPROVEN[symbol] == value, (name, symbol, hex(value))
            how = 'call target of a built, non-counted row'
        elif symbol.startswith('__TI'):
            # ThrowInfo -> CatchableTypeArray (+0xc) -> first CatchableType (+4) -> TypeDescriptor (+4) -> name
            d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
            rtti = original.string(d(d(d(value + 12) + 4) + 4) + 8)
            assert rtti == '.' + symbol[symbol.index('?'):], (name, symbol, hex(value), rtti)
            how = 'throw info, first catchable type %s' % rtti
        elif extra is not None and symbol in extra:
            assert extra[symbol] in (None, value), (name, symbol, hex(value))
            how = 'pending-build external'
        elif symbol.startswith('??_B?1??') or symbol.startswith('?$S') or '?$TSS' in symbol or symbol.startswith('?s@?1??'):
            how = 'local static'
        else:
            UNBOUND.append("    %r: %#x,   # %s in %s" % (symbol, value, names.get(value, '')[:60], name[:60]))
            continue
        if record:
            prev = binding.setdefault(symbol, (value, name))
            assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
        verified[symbol] = '%s (%s)' % (hex(value), how)
    return verified, local


VTABLES = {}


def verify(which, rows, own, strict=True, record=True, extra=None, limit=None):
    raw = Path(OBJ[which]).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    result = []
    for address, name in rows:
        body, refs = bodies[name]
        target, target_refs = target_of(address)
        if limit:
            exact = len(body) == limit and match.exact_match(target[:limit], [r for r in target_refs if r < limit], body, refs)
        else:
            exact = match.exact_match(target, target_refs, body, refs)
        entry = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target), 'exact': exact}
        if not exact:
            assert not strict or DISCOVER, (name, entry['address'], len(body), len(target))
            result.append(entry)
            continue
        verified, local = bind_value(raw, sections, symbols, definitions, name, body, target, address, own, extra, record, limit)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local),
                      'vtables': sorted(x for x in verified if x.startswith('??_7'))})
        result.append(entry)
    return result


# ---- rows ---------------------------------------------------------------------------------------------
resolved = {k: resolve(OBJ[k], rows) for k, rows in ROWS.items()}
own = {}
for rows in resolved.values():
    for address, name in rows:
        own.setdefault(name, address)
for which, address, symbol in ALIASES:
    own.setdefault(symbol, address)
groups = {k: verify(k, rows, own) for k, rows in resolved.items()}
alias_out = [dict(verify(w, [(a, s)], own)[0], counted=False, note='ICF alias of the counted row') for w, a, s in ALIASES]
non_out = []
for address, key, which, why in NON_EXACT_ROWS:
    row = verify(which, resolve(OBJ[which], [(address, key)]), own, strict=False, record=False)[0]
    assert not row['exact'] or DISCOVER, ('non-exact row unexpectedly exact', row['address'])
    row.update({'exact': False, 'reason': why})
    non_out.append(row)
bounds_out = []
for address, key, which, size in BOUNDS_ROWS:
    row = verify(which, resolve(OBJ[which], [(address, key)]), own, strict=False, record=False, limit=size)[0]
    assert row['exact'] or DISCOVER, ('bounds prefix not exact', row['address'])
    row.update({'prefix_exact': row['exact'], 'exact': False, 'counted': False, 'status': 'bounds',
                'reason': 'function-list extent is %d bytes; the body ends at %d bytes (BOUNDS evidence)' % (row['target_size'], size)})
    bounds_out.append(row)
pend_out = []
for address, key, which, why in PENDING_ROWS:
    row = verify(which, resolve(OBJ[which], [(address, key)]), own, strict=False, record=False, extra=PENDING_EXTERNAL)[0]
    assert row['exact'] or DISCOVER, ('pending row not exact in the pending build', row['address'])
    row.update({'pending_build_exact': row['exact'], 'exact': False, 'status': 'pending-build-only', 'reason': why})
    pend_out.append(row)
    # the current-header build must not emit it
    assert not [x for x in match.coff_functions(OBJ['pv'].read_bytes()) if x[0] == row['symbol']]


# ---- vtables referenced by the exact rows: slot by slot, current-header objects only ---------------------
def vtable_slots(which, symbol):
    raw = Path(OBJ[which]).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    start, section = definitions[symbol]
    table = sections[section]
    slots = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if offset >= start:
            slots[(offset - start) // 4] = symbols[index][0]
    return [slots[i] for i in range(len(slots))]


vt_out = {}
bodies_by_obj = {k: {n: (b, r) for n, b, r in match.coff_functions(Path(OBJ[k]).read_bytes())} for k in ('conn', 'pv')}
for symbol, address in sorted(VTABLES.items()):
    which = next(k for k in ('pv', 'conn') if symbol in match._coff_data_index(Path(OBJ[k]).read_bytes())[2])
    entries = []
    for slot, fn in enumerate(vtable_slots(which, symbol)):
        value = struct.unpack('<I', original.data(address + 4 * slot, 4))[0]
        gname = '??_G' + fn[4:] if fn.startswith('??_E') else None
        if fn in own:
            ok, how = own[fn] == value, 'own row'
        elif gname and gname in own:
            ok, how = own[gname] == value, 'own row (??_G)'
        elif gname and gname in bodies_by_obj[which]:
            body, refs = bodies_by_obj[which][gname]
            target, target_refs = target_of(value)
            ok, how = match.exact_match(target, target_refs, body, refs), '??_G body exact at the original slot target'
        elif fn == '__purecall':
            ok, how = original.imported(value) is not None or value == 0x6a16be, 'purecall'
        elif fn in bodies_by_obj[which]:
            body, refs = bodies_by_obj[which][fn]
            target, target_refs = target_of(value)
            ok, how = match.exact_match(target, target_refs, body, refs), 'body exact at the original slot target'
        elif fn in EXTERNAL:
            ok, how = EXTERNAL[fn] == value, 'external'
        elif norm(names.get(value, '')) == norm(fn):
            ok, how = True, 'evidence name'
        else:
            ok, how = False, 'unbound'
        entries.append({'slot': slot, 'symbol': fn, 'original': '%08x' % value, 'ok': ok, 'how': how})
    vt_out[symbol] = {'address': '%08x' % address, 'ok': all(e['ok'] for e in entries), 'slots': entries}

if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for g, rows in groups.items():
        for r in rows:
            if not r['exact']:
                print('NOT EXACT', g, r['address'], r['symbol'][:90], r['size'], r['target_size'])
    for s, v in vt_out.items():
        for e in v['slots']:
            if not e['ok']:
                print('VTABLE', s[:80], e)
    sys.exit(0)
assert not UNBOUND, UNBOUND


# ---- counted elsewhere? (top-level exact_function_rows rule) ----------------------------------------------
def counted_elsewhere():
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
        if 'exact_function_rows' in data:
            rows = data['exact_function_rows']
        elif isinstance(data.get('exact_addresses'), list):
            rows = data['exact_addresses']
        elif isinstance(data.get('exact_unique_addresses'), list):
            rows = data['exact_unique_addresses']
        else:
            def walk(o):
                if isinstance(o, list):
                    for e in o:
                        walk(e)
                elif isinstance(o, dict):
                    if 'address' in o and o.get('exact') is True:
                        rows.append(o['address'])
                    else:
                        for v in o.values():
                            walk(v)
            walk(data.get('methods', []))
        if isinstance(rows, dict):
            rows = list(rows)
        for r in rows:
            r = r.get('address', '') if isinstance(r, dict) else str(r)
            m = re.match(r'(?:0x)?([0-9a-fA-F]{6,8})', r)
            if m:
                out.setdefault('%08x' % int(m.group(1), 16), []).append(Path(path).name)
    return out


elsewhere = counted_elsewhere()
# A row is counted only when every vtable it references passes the slot-by-slot check.
vtable_unproven = []
for rows in groups.values():
    for r in rows:
        if r['exact']:
            bad = [v for v in r['vtables'] if not vt_out[v]['ok']]
            r['counted'] = not bad
            if bad:
                r['not_counted_reason'] = 'references vtables whose slots are not all proven: ' + ', '.join(bad)
                vtable_unproven.append(r['address'])
exact_rows = sorted({r['address'] for rows in groups.values() for r in rows if r['exact'] and r['counted']})
double = {a: elsewhere[a] for a in exact_rows if a in elsewhere}
assert not double, double

UNIT_MAP = {
    'connector 006060b0..00606a50': (
        '006060b0 (Body force helper on the root SimBody: [this+0x10]+0x2c, dirty -> 00658d20, += +0x90..+0x98; callers '
        '0062ec1a / 00666634 / 006676f2), 00606100 percentConnectorsActive (0097b878/0097b87c), connector getBody / '
        'potentialEnergy / RotateConnector() / ??_G 00606150..006062c0 (world-joints), GeoPair helper 00606270 + thunk '
        '00606770 (`add ecx, 8; jmp 00606270`, called from deleteUnmatchedConnectors 00607e2f), 006062e0 (called by '
        'RotateConnector::computeForce 006064c5), computeForce 006064a0 / 006065d0 / 00606670 / 00606780, GeoPair::match '
        '00606a50. The counters 0097b878/0097b87c are written only by 00606780 (00606834 / 00606a1d).'),
    'contact 00606b00..00608945': (
        'Block edge helper 00606b00 (table 0084aec8), Extents::overlapsOrTouches 00606b60, contactPairHitRatio 00606bc0 '
        '(0097b880/0097b884, incremented by 00607d09 / 00607d3d), contactFeatureHitRatio 00606bf0 (0097b888/0097b88c, '
        '0060754a / 0060758a), Contact::step 00606c50, Contact() 00606c20 (world-shapes), computeIsAdjacent 00606ca0, '
        '00606ce0 (getFastFuzzyExtents of both primitives, then computeIsColliding), deleteConnector 00606d10, '
        'ContactConnector() 00606d40 (world-joints), createConnector 00606e00, BallBall / BallBlock / BlockBlock bodies '
        '00606e90..00608945 (world-shapes / leaves2008 count 00607c60, 006078f0).'),
    'pvinstance 00608950..00609a1f': (
        'starts after BlockBlockContact::stepContact helpers (00608890 ends 00608945); getShowControllerFlag 00608950 .. '
        'setShowControllerFlag 00609a00; ~PVInstance 00609020 (not a function-list start, BOUNDS); flag-family / spawn '
        'count 00608cd0 (GetSetImpl<ControllerType>::setValue, ICF), hopper-family lists 00608c20 only as support.'),
    'feature 00609a30..': 'getFaceId 00609a30 .. (feature-working.json).',
}

receipt = {
    'class': 'RBX connector / contact / PVInstance units after GuiBuilder (2008-06), inactive',
    'compiler': 'VS2008 RTM 21022',
    'flags': {k: v for k, v in FLAGS.items()},
    'sources': {str(p.relative_to(ROOT)): nb.sha(p) for p in list(SOURCES.values()) + [Path(__file__).resolve(),
                R / 'native-headers/v8kernel/Connector2008.h', R / 'native-headers/v8datamodel/PVInstance.h', INSTANCE_H]},
    'generated_pending_headers': {str((PENDING / 'v8tree/Instance.h').relative_to(ROOT)): nb.sha(PENDING / 'v8tree/Instance.h')},
    'objects': {k: nb.sha(v) for k, v in OBJ.items()},
    'unit_map': UNIT_MAP,
    'rows': groups,
    'aliases': alias_out,
    'not_exact': non_out,
    'bounds': bounds_out,
    'pending_rows': pend_out,
    'vtables': vt_out,
    'exact_function_rows': exact_rows,
    'exact_but_vtable_unproven_rows': sorted(vtable_unproven),
    'proposals': PROPOSALS,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS contact-unit2008: %d counted exact rows (%s); %d exact but vtable-unproven (%s), %d not exact, %d bounds, '
      '%d pending-build-only, %d vtables (%d fully proven)'
      % (len(exact_rows), ' '.join(exact_rows), len(vtable_unproven), ' '.join(sorted(vtable_unproven)), len(non_out),
         len(bounds_out), len(pend_out), len(vt_out), sum(1 for v in vt_out.values() if v['ok'])))
