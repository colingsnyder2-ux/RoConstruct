"""Verify the inactive 2008-06 native rows of the application range 0040c000..00418000 and record its unit map.

Unit map (boundary evidence in the receipt's `unit_map`, checked below; rows counted by other receipts are listed as
'ADDR counted by RECEIPT' text, never as a quoted bare address):
  * ..0040df5f          the AuthoringSettings / reflection-metadata unit (starts below the range): the template
                        instances of Metadata::Classes / Properties / Functions / Events / Class / Member / Item and of
                        AuthoringSettings (FactoryProduct / DescribedCreatable constructors, destructors, adjustor
                        thunks, Creator::create, shared_ptr / create<C>, classDescriptor);
  * 0040df60..0041115f  CBrowserView / CIDEBrowserView / CPlayBrowserView / CBrowserDoc / CNullDoc with the ATL
                        CBrowserViewExternal objects (browser-view owner);
  * 00411160..00412aef  boost::bad_weak_ptr / CGdiObject / CBrush leaves, ChatEnter and CChatPrompt (chat owner);
  * 00412af0..00412f2f  CChildFrame / CRbxChildFrame (child-frame);
  * 00412f30..0041348f  CClassImages / CComCtlWrapper / CBitmap (insert-object-dialog);
  * 00413490..0041668f  the clipboard verb unit (CutVerb / CopyVerb / PasteVerb, DeleteSelectionVerb, the clipboard
                        boost::any / SAFEARRAY helpers, the ModelInstance / Script / LocalScript / ChangeHistoryService
                        Creatable instances);
  * 00416690..00416e5f  RBX::NullController leaf, CContent (ATL CComObject / CComAggObject);
  * 00416e60..0041784f  DHTMLWindowService and the boost::any holder<std::string> / ATL thunk helpers;
  * 00417850..          CLuaFunction (ATL), continuing past the range.

Builds (VS2008 RTM 21022, document-swap flags, /fp:fast), current native headers only (read-only):
  * native-classes/AppUnit40C_2008Metadata.cpp  FactoryProduct / DescribedCreatable template members, Creator::create,
    create<C>, shared_ptr<C> and classDescriptor instances of the metadata classes and AuthoringSettings;
  * native-classes/AppUnit40C_2008Creators.cpp  Creatable instances of ChatEnter, Network::Players, ModelInstance,
    Script, LocalScript and ChangeHistoryService;
  * the committed native-classes/MetadataContainersLifetime.cpp, MetadataClassesLifetime.cpp, MetadataItemLifetime.cpp,
    MetadataClassesRegister.cpp and AuthoringSettings.cpp, compiled unchanged (read-only), for the metadata class
    bodies of this range, and the committed ChatEnter.cpp (unchanged) for ChatEnter() and the GuiItem inline members
    first emitted in the chat unit.

Every relocation of a counted row is resolved to the address the original instruction uses and verified, one address
per symbol over all rows: imports by DLL export name, string literals by bytes, type descriptors by RTTI name, vtables
by the original complete-object locator class, own rows (of any build here) by their row address, rows counted by
other receipts by that receipt (and the compiled body must be exact there), constructors by evidence name or by the
complete-object vtable they store, helper bodies compiled here by exactness at the bound address. Every Creator::create
row is slot 0 of the original Creator vtable whose RTTI names the class; every adjustor thunk row is slot 0 of the
original subobject vtable whose RTTI and offset name the thunk. A row is counted only when no other receipt counts it.
Writes work/2008-06/shared-layouts/app-unit40c-2008-working.json. NATIVE_APP_UNIT40C_DISCOVER=1 lists unbound targets
and non-exact rows instead of asserting.
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
OUT = R / 'out/app-unit40c-2008'
OUT.mkdir(parents=True, exist_ok=True)
NC = R / 'native-classes'
SOURCES = {
    'metadata': NC / 'AppUnit40C_2008Metadata.cpp',
    'creators': NC / 'AppUnit40C_2008Creators.cpp',
    # committed sources of other owners, compiled unchanged
    'containers': NC / 'MetadataContainersLifetime.cpp',
    'classes': NC / 'MetadataClassesLifetime.cpp',
    'item': NC / 'MetadataItemLifetime.cpp',
    'register': NC / 'MetadataClassesRegister.cpp',
    'authoring': NC / 'AuthoringSettings.cpp',
    'chatenter': NC / 'ChatEnter.cpp',
}
UNIT_FLAGS = {k: ['/fp:fast'] for k in SOURCES}
HEADERS = [R / 'native-headers' / h for h in (
    'util/Object.h', 'reflection/Metadata.h', 'AuthoringSettings.h', 'v8datamodel/GlobalSettings.h', 'ChatEnter.h',
    'Network/Players.h', 'v8datamodel/ModelInstance.h', 'script/Script.h', 'v8datamodel/ChangeHistoryService.h',
    'reflection/reflection.h', 'util/Name.h', 'gui/Gui.h')]
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit40c-2008-working.json'
LO, HI = 0x40c000, 0x418000
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT40C_DISCOVER'))


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags() + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


OBJ, FLAGS = {}, {}
for _k, _src in SOURCES.items():
    OBJ[_k], FLAGS[_k] = build('AppUnit40C_' + _src.stem, _src, UNIT_FLAGS[_k])
FUNCS = {k: [n for n, _, _ in match.coff_functions(Path(o).read_bytes()) if not nb.LOCAL_EH.match(n)]
         for k, o in OBJ.items()}

original = nb.Original()
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
FUNCTIONS = {}
for line in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines():
    x = json.loads(line)
    FUNCTIONS[int(x['addr'], 16)] = x


def norm(s):
    # template-argument mangling only: the binary's class-name parameters are const char* const (3QBDB) where the
    # native headers declare char arrays (3PADA) or const char* (3PBDB); the RTTI / class names must otherwise agree.
    return s.replace('3QBDB', '3PADA').replace('3PBDB', '3PADA')


# ---- rows --------------------------------------------------------------------------------------------------------
CI = '?$Creatable@VInstance@RBX@@@'
MD = 'Metadata@Reflection@RBX@@'
# metadata classes: (class, base mangled as in the FactoryProduct argument list, name symbol)
MCLS = {
    'Classes': 'VInstance@4@', 'Properties': 'VMembers@234@', 'Functions': 'VMembers@234@',
    'Events': 'VMembers@234@', 'Class': 'VItem@234@', 'Member': 'VItem@234@'}


def mfp(c):
    return '?$FactoryProduct@V%s@%s%s$1?s%s@234@3PADA@RBX@@' % (c, MD, MCLS[c], c)


def mdc(c):
    return '?$DescribedCreatable@V%s@%s%s$1?s%s@234@3PADA@RBX@@' % (c, MD, MCLS[c], c)


def msp(c):
    # (prefix, suffix): resolved to the unique compiled symbol (back-references make the full spelling build-specific)
    return ('??$?0V%s@%sVDeleter@%s' % (c, MD, CI), '?$shared_ptr@V%s@%s@boost@@QAE@PAV%s@%sVDeleter@' % (c, MD, c, MD))


def mcreate(c):
    return '??$create@V%s@%s@%sRBX@@SA?AV?$shared_ptr@V%s@%s@boost@@XZ' % (c, MD, CI, c, MD)


def mcreator(c):
    return '?create@Creator@' + mfp(c) + 'UBE?AV?$shared_ptr@VObject@RBX@@@boost@@XZ'


def mdesc(c):
    return ('?classDescriptor@?$Described@V%s@%s$1?s%s@234@3PADAV?$FactoryProduct@V%s@' % (c, MD, c, c),
            'SAAAVClassDescriptor@23@XZ')


AS = 'AuthoringSettings'
ASFP = '?$FactoryProduct@VAuthoringSettings@@VItem@GlobalSettings@RBX@@$1?sAuthoringSettings@@3PADA@RBX@@'
ASDC = '?$DescribedCreatable@VAuthoringSettings@@VItem@GlobalSettings@RBX@@$1?sAuthoringSettings@@3PADA@RBX@@'

# (row, build, symbol)
ROW_SPEC = [
    # shared_ptr<C>(C*, Deleter)
    (0x40c000, 'metadata', msp('Functions')), (0x40c2f0, 'metadata', msp('Events')),
    (0x40c550, 'metadata', msp('Member')),
    # FactoryProduct<C>::getClassName (Name::declare<sC>() inlined)
    (0x40c0b0, 'metadata', '?getClassName@' + mfp('Functions') + 'UBEABVName@2@XZ'),
    (0x40c3a0, 'metadata', '?getClassName@' + mfp('Events') + 'UBEABVName@2@XZ'),
    (0x40c600, 'metadata', '?getClassName@' + mfp('Member') + 'UBEABVName@2@XZ'),
    # Described<C>::classDescriptor()
    (0x40c0d0, 'metadata', mdesc('Functions')), (0x40c3c0, 'metadata', mdesc('Events')),
    (0x40c760, 'metadata', mdesc('Member')),
    # FactoryProduct<C>::FactoryProduct()
    (0x40c200, 'metadata', '??0' + mfp('Events') + 'IAE@XZ'), (0x40d1b0, 'metadata', '??0' + mfp('Class') + 'IAE@XZ'),
    (0x40d490, 'metadata', '??0' + mfp('Member') + 'IAE@XZ'),
    # DescribedCreatable<C>::DescribedCreatable()
    (0x40c8f0, 'metadata', '??0' + mdc('Classes') + 'IAE@XZ'), (0x40c990, 'metadata', '??0' + mdc('Properties') + 'IAE@XZ'),
    (0x40ca70, 'metadata', '??0' + mdc('Functions') + 'IAE@XZ'), (0x40cb60, 'metadata', '??0' + mdc('Events') + 'IAE@XZ'),
    (0x40d950, 'metadata', '??0' + mdc('Class') + 'IAE@XZ'), (0x40da00, 'metadata', '??0' + mdc('Member') + 'IAE@XZ'),
    # Creatable<Instance>::create<C>()
    (0x40d210, 'metadata', mcreate('Classes')), (0x40d290, 'metadata', mcreate('Properties')),
    (0x40d310, 'metadata', mcreate('Functions')), (0x40d390, 'metadata', mcreate('Events')),
    (0x40de10, 'metadata', mcreate('Member')), (0x40dc70, 'metadata', mcreate('Class')),
    # Creator::create
    (0x40d5e0, 'metadata', mcreator('Classes')), (0x40d690, 'metadata', mcreator('Properties')),
    (0x40d740, 'metadata', mcreator('Functions')), (0x40d7f0, 'metadata', mcreator('Events')),
    (0x40d8a0, 'metadata', '?create@Creator@' + ASFP + 'UBE?AV?$shared_ptr@VObject@RBX@@@boost@@XZ'),
    (0x40dd60, 'metadata', mcreator('Class')), (0x40de90, 'metadata', mcreator('Member')),
    # committed MetadataContainersLifetime.cpp
    (0x40c140, 'containers', '??1' + mfp('Events') + 'MAE@XZ'), (0x40c4c0, 'containers', '??1' + mfp('Member') + 'MAE@XZ'),
    (0x40c1e0, 'containers', '??_G' + mfp('Events') + 'MAEPAXI@Z'),
    (0x40ca50, 'containers', '??_G' + mfp('Properties') + 'MAEPAXI@Z'),
    (0x40cb40, 'containers', '??_G' + mfp('Functions') + 'MAEPAXI@Z'),
    (0x40dae0, 'containers', '??_G' + mfp('Member') + 'MAEPAXI@Z'),
    (0x40ce70, 'containers', '??0Properties@' + MD + 'QAE@XZ'), (0x40cef0, 'containers', '??0Functions@' + MD + 'QAE@XZ'),
    (0x40cf70, 'containers', '??0Events@' + MD + 'QAE@XZ'), (0x40dcf0, 'containers', '??0Member@' + MD + 'QAE@XZ'),
    # committed MetadataClassesLifetime.cpp
    (0x40cdc0, 'classes', '??0Classes@' + MD + 'QAE@XZ'),
    # committed MetadataItemLifetime.cpp
    (0x40cff0, 'item', '??0Item@' + MD + 'QAE@XZ'),
    (0x40cc20, 'item', '??0?$DescribedNonCreatable@VItem@' + MD + 'VInstance@4@$1?sItem@234@3PADA@RBX@@IAE@XZ'),
    (0x40d120, 'item', '??_GItem@' + MD + 'UAEPAXI@Z'),
    # committed MetadataClassesRegister.cpp
    (0x40dba0, 'register', '??0Class@' + MD + 'QAE@XZ'),
    (0x40dc50, 'register', '??_G' + mfp('Class') + 'MAEPAXI@Z'),
    # committed AuthoringSettings.cpp
    (0x40c7d0, 'authoring', '??0' + ASDC + 'IAE@XZ'),
    (0x40ccc0, 'authoring', '??0?$GlobalSettingsItem@VAuthoringSettings@@$1?sAuthoringSettings@@3PADA@RBX@@IAE@XZ'),
    (0x40c8d0, 'authoring', '??_G' + ASFP + 'MAEPAXI@Z'),
    # committed ChatEnter.cpp: ChatEnter() and the GuiItem / Instance inline members first emitted in this unit
    (0x411720, 'chatenter', '??0ChatEnter@@QAE@XZ'),
    (0x411540, 'chatenter', '??1GuiItem@RBX@@UAE@XZ'),
    (0x4117b0, 'chatenter', '?getName@Instance@RBX@@QBEABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ'),
    (0x4117c0, 'chatenter', '?askAddChild@GuiItem@RBX@@EBE_NPBVInstance@2@@Z'),
    (0x4117f0, 'chatenter', '?getPosition@GuiItem@RBX@@MBE?AVVector2@G3D@@XZ'),
    (0x411810, 'chatenter', '?getChildPosition@GuiItem@RBX@@MBE?AVVector2@G3D@@PBV12@@Z'),
    (0x411830, 'chatenter', '?getFontSize@GuiItem@RBX@@MBEHXZ'),
    (0x411840, 'chatenter', '?getTitle@GuiItem@RBX@@MAE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ'),
    (0x411870, 'chatenter', '?getSize@GuiItem@RBX@@UBE?AVVector2@G3D@@XZ'),
]
# Creatable instances of AppUnit40C_2008Creators.cpp: class -> (symbol class, FactoryProduct base or None, name mangling,
# shared_ptr row, create row, Creator row, shared_count row (creatable-shared-count), Creator vtable)
CREATORS = {
    'ChatEnter': ('ChatEnter@@', None, None, 0x411d90, 0x411f50, None, 0x4118a0, None),
    'Players': ('Players@Network@RBX@@', None, None, 0x411e40, 0x411fd0, None, 0x411940, None),
    'ModelInstance': ('ModelInstance@RBX@@', 'PVInstance', 'Model', 0x4148b0, 0x414960, 0x4149e0, 0x414820, 0x80e9ac),
    'Script': ('Script@RBX@@', 'Instance', 'Script', 0x414b20, 0x414bd0, 0x414c50, 0x414a90, 0x80e9c8),
    'LocalScript': ('LocalScript@RBX@@', 'Script', 'LocalScript', 0x414d90, 0x414e40, 0x414ec0, 0x414d00, 0x80e9e4),
    'ChangeHistoryService': ('ChangeHistoryService@RBX@@', 'Instance', 'ChangeHistoryService', 0x415020, 0x4150d0,
                             0x415150, 0x414f70, 0x80ea00),
}
COUNTED_TARGETS = {}   # symbol -> (address, receipt[, receipt symbol])


for c, (sc, base, nm, sp, cc, cr, scount, vt) in CREATORS.items():
    _sp = [n for n in FUNCS['creators'] if n.startswith('??$?0V' + sc + 'VDeleter@' + CI) and '?$shared_ptr@V' + sc in n]
    _cc = [n for n in FUNCS['creators'] if n.startswith('??$create@V' + sc + '@' + CI)]
    assert len(_sp) == 1 and len(_cc) == 1, (c, _sp, _cc)
    ROW_SPEC.append((sp, 'creators', _sp[0]))
    ROW_SPEC.append((cc, 'creators', _cc[0]))
    if cr:
        ROW_SPEC.append((cr, 'creators', '?create@Creator@?$FactoryProduct@V%s@RBX@@V%s@2@$1?s%s@2@3PADA@RBX@@UBE?AV?$'
                                         'shared_ptr@VObject@RBX@@@boost@@XZ' % (c, base, nm)))
    COUNTED_TARGETS[('shared_count', c)] = (scount, 'creatable-shared-count-working.json')

# ---- adjustor thunks (sub ecx, N; jmp ??_G): slot 0 of the original subobject vtables of each class -------------------
ADJ = {0x10: 'BA', 0x14: 'BE', 0x24: 'CE', 0x44: 'EE', 0x64: 'GE', 0x84: 'IE', 0xa4: 'KE', 0xc4: 'ME'}
RDATA = [s for s in original.pe.sections if s.Name.rstrip(b'\0') == b'.rdata'][0]
RDATA_VA = original.image + RDATA.VirtualAddress
RDATA_BYTES = RDATA.get_data()
TEXT = [(original.image + s.VirtualAddress, original.image + s.VirtualAddress + s.Misc_VirtualSize)
        for s in original.pe.sections if s.Name.rstrip(b'\0') == b'.text'][0]


def rdata_refs(value):
    pat = struct.pack('<I', value)
    return [RDATA_VA + m.start() for m in re.finditer(re.escape(pat), RDATA_BYTES) if m.start() % 4 == 0]


def original_vtables(rtti_name):
    """(vtable, subobject offset) of every original vtable whose complete-object locator names rtti_name."""
    out = []
    for sec in original.pe.sections:
        if sec.Name.rstrip(b'\0') not in (b'.data', b'.rdata'):
            continue
        raw, va = sec.get_data(), original.image + sec.VirtualAddress
        pos = raw.find(b'\0' + rtti_name.encode() + b'\0')
        while pos >= 0:
            td = va + pos + 1 - 8
            for col_ref in rdata_refs(td):
                col = col_ref - 12
                if d(col) != 0:
                    continue
                for vref in rdata_refs(col):
                    out.append((vref + 4, d(col + 4)))
            pos = raw.find(b'\0' + rtti_name.encode() + b'\0', pos + 1)
    return out


def thunk_target(a):
    b = original.data(a, 11)
    if b[:2] == b'\x83\xe9' and b[3] == 0xe9:
        return b[2], a + 8 + struct.unpack_from('<i', b, 4)[0]
    if b[:2] == b'\x81\xe9' and b[6] == 0xe9:
        return struct.unpack_from('<I', b, 2)[0], a + 11 + struct.unpack_from('<i', b, 7)[0]
    return None


# (class RTTI, build that emits its thunks): the DescribedCreatable<C> thunks are emitted with the DescribedCreatable
# vtables of AppUnit40C_2008Metadata.cpp; Item's with Item(); the AuthoringSettings DescribedCreatable ones in
# AuthoringSettings.cpp. The original FactoryProduct<C> / DescribedCreatable<C> / C vtables share (ICF) one thunk per
# subobject offset.
THUNK_CLASSES = [('.?AV' + mdc(c), 'metadata') for c in MCLS] + [
    ('.?AVItem@' + MD, 'item'), ('.?AV' + ASDC.replace('3PADA', '3QBDB'), 'authoring')]
THUNKS = []
for rtti, b in THUNK_CLASSES:
    vts = original_vtables(rtti)
    assert vts, rtti
    for vt, off in sorted(vts):
        if off == 0:
            continue
        a = d(vt)
        if not LO <= a < HI:
            continue
        t = thunk_target(a)
        assert t and t[0] == off, (rtti, hex(vt), hex(a), t)
        sym = '??_E' + norm(rtti[4:]) + 'W' + ADJ[off] + '@AEPAXI@Z'
        assert sym in FUNCS[b], (rtti, sym)
        THUNKS.append((a, b, sym, vt, off, t[1]))
_seen = {}
for a, b, sym, vt, off, g in THUNKS:
    _seen.setdefault(a, (b, sym))
for a, (b, sym) in sorted(_seen.items()):
    ROW_SPEC.append((a, b, sym))

def resolve(b, sym):
    if isinstance(sym, str):
        return sym
    hits = [n for n in FUNCS[b] if n.startswith(sym[0]) and (sym[1] in n[len(sym[0]):])]
    assert len(hits) == 1, (b, sym, hits)
    return hits[0]


ROW_SPEC = [(a, b, resolve(b, sym)) for a, b, sym in ROW_SPEC]
ROWS = {k: [] for k in SOURCES}
ALL_OWN = {}
for a, b, sym in ROW_SPEC:
    assert sym in FUNCS[b], (hex(a), b, sym)
    assert a not in [x for x, _ in ROWS[b]], hex(a)
    ROWS[b].append((a, sym))
_addrs = [a for a, _, _ in ROW_SPEC]
assert len(_addrs) == len(set(_addrs)), sorted(a for a in _addrs if _addrs.count(a) > 1)
for a, b, sym in ROW_SPEC:
    prev = ALL_OWN.setdefault(sym, a)
    assert prev == a, (sym, hex(prev), hex(a))

# class-name arrays (defined by MetadataClassNames.cpp / AuthoringSettings.cpp / the class units): bound by the string
NAME_DATA = {'?s%s@%s3PADA' % (c, MD.replace('Metadata@Reflection@RBX@@', 'Metadata@Reflection@RBX@@')): 'ReflectionMetadata' + c
             for c in ('Classes', 'Properties', 'Functions', 'Events', 'Class', 'Member', 'Item')}
NAME_DATA['?sAuthoringSettings@@3PADA'] = 'Authoring'
NAME_DATA['?sModel@RBX@@3PADA'] = 'Model'
NAME_DATA['?sScript@RBX@@3PADA'] = 'Script'
NAME_DATA['?sLocalScript@RBX@@3PADA'] = 'LocalScript'
NAME_DATA['?sChangeHistoryService@RBX@@3PADA'] = 'ChangeHistoryService'
EXTERNAL = {
    '?declare@Name@RBX@@SAABV12@PBDH@Z': 0x553f90,
    '??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z': 0x5708f0,
    '??1ClassDescriptor@Reflection@RBX@@UAE@XZ': 0x40abc0,
    '?classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3QBDBVDescribedBase@Reflection@2@@Reflection@RBX@@'
    'SAAAVClassDescriptor@23@XZ': 0x40ad80,
    '_atexit': 0x6a17af,
    '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330,
    '?setName@Instance@RBX@@UAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': 0x55af90,
    '??1Instance@RBX@@UAE@XZ': 0x55a540,
    '??0Instance@RBX@@QAE@XZ': 0x55b7e0,
    '??2@YAPAXI@Z': 0x6a0920,
    '??3@YAXPAX@Z': 0x6a067a,
    '___RTDynamicCast': 0x6a17c6,
    # G3D::format (bound the same way by the other receipts that call it)
    '?format@G3D@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PBDZZ': 0x509b10,
    # G3D::Vector2::zero() (function-local static; bound the same way by the gui receipts)
    '?zero@Vector2@G3D@@SAABV12@XZ': 0x509ba0,
}
DATA_SECTIONS = [(original.image + s.VirtualAddress, original.image + s.VirtualAddress + s.Misc_VirtualSize)
                 for s in original.pe.sections if s.Name.rstrip(b'\0') in (b'.data', b'.rdata')]
BINDING = {}
UNBOUND = []
HELPERS = {}
CONSTRUCTOR_PROOF = {}
BODIES = {k: {n: (b, r) for n, b, r in match.coff_functions(Path(o).read_bytes())} for k, o in OBJ.items()}


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


def ctor_vtables(address):
    """Vtables a constructor body stores (C7 /0 imm32 into a register base), with their original RTTI class."""
    body, _, _ = match.target('2008-06', '%08x' % address)
    found = []
    for i in range(len(body) - 6):
        if body[i] == 0xc7 and (body[i + 1] & 0xf8) in (0x00, 0x40, 0x80):
            off = {0x00: 0, 0x40: 1, 0x80: 4}[body[i + 1] & 0xc0]
            v = struct.unpack_from('<I', body, i + 2 + off)[0]
            try:
                c = original.vtable_class(v)
            except Exception:
                continue
            if c and c[0]:
                found.append((v, c))
    return found


def prove_constructor(symbol, value):
    cls = symbol[3:symbol.index('@@QAE@') + 2]
    if names.get(value, '') == symbol:
        return 'evidence name'
    stores = [v for v, c in ctor_vtables(value) if norm(c[0]) == norm('.?AV' + cls) and c[1] == 0]
    if not stores:
        return None
    return 'stores the .?AV%s complete-object vtable %s' % (cls, hex(stores[0]))


def counted_target(symbol):
    for (kind, c), (addr, receipt) in COUNTED_TARGETS.items():
        sc = CREATORS[c][0]
        if kind == 'shared_count' and symbol.startswith('??$?0PAV' + sc) and '@shared_count@detail@boost@@' in symbol:
            return addr, receipt
    return None


def verify(build, obj, rows):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = BODIES[build]
    out = []
    for address, name in rows:
        body, refs = bodies[name]
        target, target_refs, _ = match.target('2008-06', '%08x' % address)
        exact = match.exact_match(target, target_refs, body, refs)
        row = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target),
               'exact': bool(exact), 'build': build, 'verified_targets': {}, 'local_eh': []}
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
            ct = counted_target(symbol)
            if hit is not None:
                assert hit[1] == nb.plain(symbol), (where, symbol, hex(value), hit)
                how = '%s!%s' % hit
            elif symbol in ALL_OWN:
                assert ALL_OWN[symbol] == value, (where, symbol, hex(value), hex(ALL_OWN[symbol]))
                how = 'own row'
            elif symbol.startswith('??_C@'):
                pos, at = definitions[symbol]
                lit = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
                assert original.data(value, len(lit)) == lit, (where, symbol, hex(value))
                how = 'literal %r' % lit[:-1].decode()
            elif symbol.startswith('??_R0') and symbol.endswith('@8'):
                rtti = original.string(value + 8)
                assert norm(rtti) == norm('.' + symbol[5:-2]), (where, symbol, hex(value), rtti)
                how = 'RTTI %s' % rtti
            elif symbol.startswith('??_7'):
                rtti, at = original.vtable_class(value)
                cls = symbol[4:symbol.index('@@6B') + 2]
                assert norm(rtti) == norm('.?AV' + cls), (where, symbol, hex(value), rtti)
                how = 'vtable RTTI %s offset %#x' % (rtti, at)
            elif ct is not None:
                other, receipt = ct
                assert other == value, (where, symbol, hex(value), hex(other))
                assert symbol in receipt_symbols(receipt, value), (receipt, hex(value), symbol)
                if symbol in bodies:
                    hb, hr = bodies[symbol]
                    ht, htr, _ = match.target('2008-06', '%08x' % value)
                    assert match.exact_match(ht, htr, hb, hr), ('counted-elsewhere body not exact', symbol, hex(value))
                how = 'row counted by %s (body exact at the bound address)' % receipt
            elif symbol in NAME_DATA:
                assert original.string(value) == NAME_DATA[symbol], (where, symbol, hex(value), original.string(value))
                how = 'class-name array %r (string at the referenced address)' % NAME_DATA[symbol]
            elif symbol in EXTERNAL:
                assert EXTERNAL[symbol] == value, (where, symbol, hex(value), hex(EXTERNAL[symbol]))
                how = 'external' + (' (evidence name)' if names.get(value, '') == symbol else '')
            elif symbol.startswith('??_E') and symbol.endswith('AEPAXI@Z') and \
                    '??_G' + symbol[4:] in bodies:
                # the adjustor thunks jump to the vector deleting destructor; the original slot holds the scalar
                # deleting destructor (no array delete of these classes), whose compiled body must be exact there
                g = '??_G' + symbol[4:]
                hb, hr = bodies[g]
                ht, htr, _ = match.target('2008-06', '%08x' % value)
                assert match.exact_match(ht, htr, hb, hr), (where, symbol, hex(value))
                how = '%s %s (scalar deleting destructor exact there; no array delete in the original)' % (
                    'own row' if value in ALL_OWN.values() else 'helper body', g[:48])
            elif symbol in bodies:
                # helper / COMDAT body compiled here but not a row: exact at the bound address, never counted
                hb, hr = bodies[symbol]
                ht, htr, _ = match.target('2008-06', '%08x' % value)
                ok = match.exact_match(ht, htr, hb, hr)
                assert ok or DISCOVER, (where, symbol, hex(value))
                HELPERS.setdefault(symbol, '%#x' % value)
                how = 'helper body exact at the bound address (not counted)'
            elif symbol.startswith('??0') and '@@QAE@' in symbol and prove_constructor(symbol, value):
                how = 'constructor: ' + CONSTRUCTOR_PROOF.setdefault(symbol, prove_constructor(symbol, value))
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
if DISCOVER:
    for u in sorted(set(UNBOUND)):
        print('UNBOUND', u)
    for r in not_exact:
        print('NOT EXACT', r['address'], r['size'], r['target_size'], r['symbol'][:100])
assert not UNBOUND or DISCOVER, UNBOUND
assert not not_exact or DISCOVER, [(r['address'], r['symbol'][:80]) for r in not_exact]


def compiled_vtables(obj):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, starts = match._coff_data_index(raw)
    out = {}
    for name, (start, sec) in definitions.items():
        if not name.startswith('??_7'):
            continue
        table = sections[sec]
        end = min([x for x in starts.get(sec + 1, ()) if x > start] + [table[3]])
        slots = {}
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
            if start <= offset < end:
                slots[(offset - start) // 4] = symbols[index][0]
        out[name] = slots
    return out


def slot_hits(obj, rows):
    """Every counted row that a compiled vtable (current headers) holds must sit in the same slot of an original vtable
    whose RTTI names the same class."""
    compiled = compiled_vtables(obj)
    out = []
    for row in rows:
        symbol, address = row['symbol'], int(row['address'], 16)
        places = [(vt, i) for vt, slots in compiled.items() for i, s in slots.items() if s == symbol]
        if not places:
            continue
        hits = []
        for vt, i in places:
            cls = vt[4:vt.index('@@6B') + 2]
            for ref in rdata_refs(address):
                try:
                    rtti, at = original.vtable_class(ref - 4 * i)
                except Exception:
                    continue
                if norm(rtti) == norm('.?AV' + cls):
                    hits.append({'vtable': hex(ref - 4 * i), 'rtti': rtti, 'offset': hex(at), 'slot': i, 'compiled': vt})
        assert hits or DISCOVER, (row['address'], symbol, places)
        row['vtable_slots'] = hits
        out.append((row['address'], len(hits)))
    return out


SLOTS = []
for k in SOURCES:
    SLOTS += slot_hits(OBJ[k], groups[k])

# ---- adjustor thunk rows: slot 0 of the original subobject vtables, adjustment and jump target read from the bytes -----
THUNK_EVIDENCE = {}
for a, b, sym, vt, off, g in THUNKS:
    rtti, at = original.vtable_class(vt)
    THUNK_EVIDENCE.setdefault('%#x' % a, []).append('slot 0 of %s (%s +%#x); sub ecx, %#x; jmp %#x' % (
        hex(vt), rtti, at, off, g))

# ---- Creator vtables (original): slot 0 is the counted Creator::create row; the RTTI names the class ---------------
creator_vtables = []
MCREATORS = {'Classes': (0x80bc68, 0x40d5e0), 'Properties': (0x80bee8, 0x40d690), 'Functions': (0x80c088, 0x40d740),
             'Events': (0x80c168, 0x40d7f0), 'Class': (0x80bd44, 0x40dd60), 'Member': (0x80c248, 0x40de90)}
_cv = [('.?AVCreator@' + mfp(c), vt, cr) for c, (vt, cr) in MCREATORS.items()]
_cv.append(('.?AVCreator@' + ASFP.replace('3PADA', '3QBDB'), 0x80c328, 0x40d8a0))
for c, (sc, base, nm, sp, cc, cr, scount, vt) in CREATORS.items():
    if cr:
        _cv.append(('.?AVCreator@?$FactoryProduct@V%s@RBX@@V%s@2@$1?s%s@2@3PADA@RBX@@' % (c, base, nm), vt, cr))
for want, vt, cr in _cv:
    rtti, at = original.vtable_class(vt)
    assert (rtti, at) == (want, 0), (hex(vt), rtti, at, want)
    assert d(vt) == cr, (hex(vt), hex(d(vt)), hex(cr))
    slots = 0
    while TEXT[0] <= d(vt + 4 * slots) < TEXT[1]:
        slots += 1
    assert slots == 1, (hex(vt), slots)
    creator_vtables.append({'vtable': hex(vt), 'rtti': rtti, 'original_slots': slots,
                            'slot0': '%s (Creator::create row)' % hex(cr)})


# ---- sizeof(C): the malloc size each create<C> passes ---------------------------------------------------------------
def malloc_size(address):
    body, _, _ = match.target('2008-06', '%08x' % address)
    sizes = [struct.unpack_from('<I', body, k.start() + 1)[0] for k in re.finditer(rb'\x68', body)]
    return [s for s in sizes if 0x40 <= s < 0x4000]


SIZES = {}
for c, cc in (('Metadata::Classes', 0x40d210), ('Metadata::Properties', 0x40d290), ('Metadata::Functions', 0x40d310),
              ('Metadata::Events', 0x40d390), ('Metadata::Class', 0x40dc70), ('Metadata::Member', 0x40de10),
              ('ChatEnter', 0x411f50), ('Network::Players', 0x411fd0), ('ModelInstance', 0x414960),
              ('Script', 0x414bd0), ('LocalScript', 0x414e40), ('ChangeHistoryService', 0x4150d0)):
    got = malloc_size(cc)
    assert len(got) == 1, (c, hex(cc), [hex(x) for x in got])
    SIZES[c] = 'sizeof %#x (malloc %#x in create<%s> %#x, exact here against the native header layout)' % (
        got[0], got[0], c, cc)


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


def holds_vtable(address, rtti):
    """The row's bytes hold a DIR32 pointer to an original vtable whose locator names that class, or the row is a
    slot of such a vtable."""
    x = FUNCTIONS[address]
    body = original.data(address, x['size'])
    for i in range(len(body) - 3):
        v = struct.unpack_from('<I', body, i)[0]
        if any(lo <= v < hi for lo, hi in DATA_SECTIONS):
            try:
                if original.vtable_class(v)[0] == rtti:
                    return True
            except Exception:
                pass
    for vt, _ in original_vtables(rtti):
        i = 0
        while TEXT[0] <= d(vt + 4 * i) < TEXT[1]:
            if d(vt + 4 * i) == address:
                return True
            i += 1
    return False


BLOCKS = [
    ('rbx AuthoringSettings / reflection-metadata unit (template instances; starts below the range)', LO, 0x40df60,
     [(0x40c0d0, 's', 'ReflectionMetadataFunctions'), (0x40c3c0, 's', 'ReflectionMetadataEvents'),
      (0x40c760, 's', 'ReflectionMetadataMember'), (0x40ccc0, 's', 'singleton %s already exists')]),
    ('rbx CBrowserView / CIDEBrowserView / CPlayBrowserView / CBrowserDoc / CNullDoc unit with the ATL '
     'CBrowserViewExternal objects (browser-view owner)', 0x40df60, 0x411160,
     [(0x4109e0, 's', 'res://%s/%d'), (0x410c40, 's', '/IDE/Start.aspx'), (0x410cd0, 's', '/Start.aspx'),
      (0x410fe0, 's', 'IBrowserViewExternal::GetApp-0x%X')]),
    ('rbx ChatEnter / CChatPrompt unit (boost::bad_weak_ptr, CGdiObject / CBrush, GuiItem inline members)', 0x411160,
     0x412af0, [(0x411160, 's', 'tr1::bad_weak_ptr'), (0x411420, 's', 'Players'), (0x411300, 'v', '.?AVChatEnter@@'),
                (0x4129c0, 'v', '.?AVCChatPrompt@@')]),
    ('rbx CChildFrame / CRbxChildFrame unit (child-frame)', 0x412af0, 0x412f30,
     [(0x412c90, 'v', '.?AVCChildFrame@@'), (0x412cf0, 'v', '.?AVCRbxChildFrame@@')]),
    ('rbx CClassImages unit (CComCtlWrapper / CBitmap; insert-object-dialog)', 0x412f30, 0x413490,
     [(0x412f90, 's', 'ImageList_Add'), (0x413230, 's', 'Unable to create CClassImages')]),
    ('rbx clipboard verb unit (CutVerb / CopyVerb / PasteVerb / DeleteSelectionVerb, boost::any / SAFEARRAY helpers, '
     'the ModelInstance / Script / LocalScript / ChangeHistoryService Creatable instances)', 0x413490, 0x416690,
     [(0x413490, 's', 'Copy'), (0x4134d0, 's', 'PasteInto'), (0x413650, 's', 'Model'),
      (0x4137a0, 's', 'ChangeHistoryService'), (0x415510, 's', 'NetworkClient'), (0x4149e0, 'v',
      '.?AVCreator@?$FactoryProduct@VModelInstance@RBX@@VPVInstance@2@$1?sModel@2@3PADA@RBX@@')]),
    ('rbx CContent unit (ATL CComObject / CComAggObject<CContent>; the RBX::NullController leaf first)', 0x416690,
     0x416e60, [(0x4166a0, 's', 'Untrusted Url: %s'), (0x416e40, 's', 'ATL:%p'),
                (0x416ca0, 'v', '.?AV?$CComAggObject@VCContent@@@ATL@@')]),
    ('rbx DHTMLWindowService unit (boost::any holder<std::string>, XmlElement / ATL thunk helpers)', 0x416e60, 0x417360,
     [(0x416f90, 's', 'HtmlService'), (0x416e60, 'v', '.?AVDHTMLWindowService@@')]),
    ('rbx CLuaFunction unit (Lua ThreadRef / FunctionRef, ATL CComObject<CLuaFunction>; continues past the range)',
     0x417360, HI, [(0x417360, 'v', '.?AVThreadRef@Lua@RBX@@'), (0x417ea0, 'v', '.?AV?$CComObject@VCLuaFunction@@@ATL@@')]),
]
range_rows = sorted(a for a in FUNCTIONS if LO <= a < HI)
for a in range_rows:
    assert sum(lo <= a < hi for _, lo, hi, _ in BLOCKS) == 1, hex(a)
for name, lo, hi, ev in BLOCKS:
    for a, kind, text in ev:
        assert lo <= a < hi and (holds_string(a, text) if kind == 's' else holds_vtable(a, text)), (name, hex(a), text)


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
exact_rows = sorted({r['address'] for rows in groups.values() for r in rows if r['exact']})
double = {a: elsewhere[a] for a in exact_rows if a in elsewhere}
assert not double, double
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if LO <= int(a, 16) < HI}
open_rows = ['%08x' % a for a in range_rows if '%08x' % a not in exact_rows and '%08x' % a not in range_counted]


def block_of(a):
    return [n for n, lo, hi, _ in BLOCKS if lo <= a < hi][0]


OPEN_BY_BLOCK = {}
for a in open_rows:
    OPEN_BY_BLOCK.setdefault(block_of(int(a, 16)), []).append('%#x' % int(a, 16))

UNIT_MAP = {
    'rbx AuthoringSettings / reflection-metadata unit ..0040df5f (starts below the range)': (
        'The template run of the unit that holds AuthoringSettings (constructor 0x40d140, destructor 0x40a990): '
        'shared_count / shared_ptr<C>(C*, Deleter), Name::declare-based getClassName, Described<C>::classDescriptor '
        '("ReflectionMetadataFunctions" / "...Events" / "...Member"), FactoryProduct / DescribedCreatable / '
        'DescribedNonCreatable constructors and destructors, the ICF-shared adjustor thunks of the FactoryProduct<C> / '
        'DescribedCreatable<C> / C vtables, the scalar deleting destructors, Classes() / Properties() / Functions() / '
        'Events() / Item() / Class() / Member(), GlobalSettingsItem<AuthoringSettings>() ("Authoring", "singleton %s '
        'already exists"), create<C>() and the Creator::create bodies (vtables 0x80bc68 .. 0x80c328), then two COMDATs '
        'of other headers: a boost.signals slot_call_iterator dereference 0x40d4f0 and Instance::raisePropertyChanged '
        '0x40db00 (evidence names). The evidence names of 0x40c0d0 / 0x40c3c0 / 0x40c760 (classDescriptor of '
        'BodyVelocity / Rocket / BodyForce) are wrong: the rows push the ReflectionMetadataFunctions / Events / Member '
        'name arrays, verified here.'),
    'rbx CBrowserView unit 0040df60..0041115f': (
        'CBrowserView / CIDEBrowserView / CPlayBrowserView / CBrowserDoc / CNullDoc (MFC message maps, '
        '"/IDE/Start.aspx", "/Start.aspx", "res://%s/%d") with CXTPCommandBarsSiteBase<CSecureHtmlView> members and the '
        'ATL CComObject / CComAggObject / CComContainedObject / CComObjectNoLock<CBrowserViewExternal>, '
        'CProxy_IBrowserViewExternalEvents and CComEnum<IEnumConnectionPoints / IEnumConnections> instances. Mostly '
        'counted by browser-view-working.json; the ATL instances are left to that owner.'),
    'rbx ChatEnter / CChatPrompt unit 00411160..00412aef': (
        'boost::bad_weak_ptr::what / dtor, CGdiObject / CBrush, the GuiItem inline members first emitted here '
        '(askAddChild / getPosition / getChildPosition / getFontSize / getTitle / getSize), ChatEnter (RTTI '
        '.?AVChatEnter@@, GuiItem base), the shared_ptr / create<ChatEnter> and create<Network::Players> instances '
        '(counted here), std::vector<shared_ptr<Instance>> / <shared_ptr<Script>> helpers, DataModel::Lock, and '
        'CChatPrompt (RTTI .?AVCChatPrompt@@). ChatEnter() 0x411720, ~GuiItem 0x411540, Instance::getName 0x4117b0 '
        'and the six GuiItem virtuals (ChatEnter vtable 0x80e12c slots 2 / 18 / 19 / 20 / 22 / 23) are counted here '
        'from the committed native-classes/ChatEnter.cpp compiled unchanged. Open: ChatEnter\'s own virtuals '
        '(0x411300, its +0x130 listener) and the CChatPrompt bodies (chat owner, probe receipts); the G3D Vector2 copy '
        'constructor 0x411790 is library code and not counted.'),
    'rbx CChildFrame unit 00412af0..00412f2f': 'CChildFrame / CRbxChildFrame; counted by child-frame / render-settings.',
    'rbx CClassImages unit 00412f30..0041348f': (
        'CClassImages, the CComCtlWrapper ImageList_Add / ImageList_AddMasked COMDATs and CBitmap; mostly counted by '
        'insert-object-dialog.'),
    'rbx clipboard verb unit 00413490..0041668f': (
        'CutVerb / CopyVerb / PasteVerb / DeleteSelectionVerb (verb names "Copy" / "Paste" / "PasteInto"), '
        'ServiceProvider::find / create instances (Model, Script, LocalScript, ChangeHistoryService), Selection / '
        'std::map<InstanceHandle, int> / std::set<ContentId> instances, the Creatable instances of ModelInstance / '
        'Script / LocalScript / ChangeHistoryService (counted here), TextXmlWriterWithEmbeddedContent, PasteVerb::doIt '
        '("NetworkClient", clipboard "Roblox" format), CopyVerb::doIt, and the boost::any / SAFEARRAY / VARIANT '
        'conversion helpers. The verb bodies belong to the clipboard owner (clipboard-trial / ClipboardActions.cpp).'),
    'rbx CContent unit 00416690..00416e5f': (
        'the shared RBX::NullController 3-byte leaf (counted elsewhere), CContent::get ("Untrusted Url: %s") and the '
        'ATL CComObject / CComContainedObject / CComAggObject<CContent> instances; content-* trial receipts.'),
    'rbx DHTMLWindowService unit 00416e60..0041735f': (
        'DHTMLWindowService (RTTI .?AVDHTMLWindowService@@, "HtmlService"), boost::any holder<std::string>, the ATL '
        'CStdCallThunk FlushInstructionCache helper, SignatureDescriptor::Item construct, XmlNameValuePair.'),
    'rbx CLuaFunction unit 00417360.. (continues past the range)': (
        'Lua ThreadRef / FunctionRef holders, XmlElement / MemberDescriptorContainer helpers, and the ATL '
        'CComObject / CComContainedObject<CLuaFunction> instances.'),
    'library code': (
        'No separately compiled library unit lies in the range. The STL / boost / ATL rows are template instances '
        'emitted in these RBX units. Only Roblox-instantiated templates whose every row is on this receipt\'s classes '
        '(the metadata FactoryProduct / Creatable block and the six Creatable runs) are recovered.'),
    'excluded': (
        'No CRobloxApp / CMainFrame / CRobloxDoc / CRobloxView member lies in the range (no RTTI vtable of those '
        'classes references a row here); the clipboard verbs are registered by the CRobloxDoc initializer 0x451b60 but '
        'are verb classes, mapped and not recovered here.'),
}
NOT_EXACT = {
    '0x40df40': ('a 5-byte jmp shared (ICF) by the empty ~Described / ~DescribedCreatable destructors and other '
                 'leaves; which symbol it is cannot be derived; open.'),
    '0x40d4f0 / 0x40db00': ('boost.signals slot_call_iterator dereference and Instance::raisePropertyChanged '
                            '(Instance.h owner) COMDATs; not built here.'),
}
REJECTED = {}
PROPOSALS = {
    'evidence names (offline/evidence.json maintainers), FYI': (
        '0x40c0d0 / 0x40c3c0 / 0x40c760 are Described<Metadata::Functions / Events / Member>::classDescriptor(), not '
        'BodyVelocity / Rocket / BodyForce: each pushes the ReflectionMetadataFunctions / Events / Member name array '
        'and Members::classDescriptor / Item::classDescriptor (verified targets in this receipt).'),
    'reflection/Metadata.h / AuthoringSettings.cpp owners, FYI': (
        'the committed MetadataContainersLifetime.cpp, MetadataClassesLifetime.cpp, MetadataItemLifetime.cpp, '
        'MetadataClassesRegister.cpp and AuthoringSettings.cpp are compiled unchanged here; their rows in this range '
        '(Properties() / Functions() / Events() / Member() / Classes() / Item() / Class(), the FactoryProduct '
        'destructors and deleting destructors, DescribedNonCreatable<Item>(), DescribedCreatable<AuthoringSettings>() '
        'and GlobalSettingsItem<AuthoringSettings>() 0x40ccc0) are exact with every target bound, so the '
        'insert-object-dialog note "0040ccc0 (258 vs 255)" is stale under the current headers and /fp:fast.'),
}

paths = [Path(__file__).resolve()] + list(SOURCES.values()) + HEADERS
receipt = {
    'class': 'RBX reflection-metadata / Creatable template rows of the application range 0040c000..00418000 '
             '(2008-06), inactive',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM), document-swap flags, /fp:fast',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): nb.sha(p) for p in paths},
    'objects': {k: nb.sha(v) for k, v in OBJ.items()},
    'layout': SIZES,
    'unit_map': UNIT_MAP,
    'unit_blocks': ['%#x..%#x %s' % (lo, hi, n) for n, lo, hi, _ in BLOCKS],
    'range_functions': len(range_rows),
    # 'ADDR counted by RECEIPT' text, never a quoted bare address (local_backpack / viewnew_brick_build /
    # viewnew_part_mesh treat any quoted bare address in another receipt as counted there).
    'range_rows_counted_by_other_receipts': ['%s counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()],
    'range_rows_open': ['%#x (open)' % int(a, 16) for a in open_rows],
    'range_rows_open_by_block': OPEN_BY_BLOCK,
    'rows': groups,
    'adjustor_thunks': THUNK_EVIDENCE,
    'creator_vtables': creator_vtables,
    'helper_bodies_not_counted': HELPERS,
    'not_exact': NOT_EXACT,
    'rejected': REJECTED,
    'proposals': PROPOSALS,
    'exact_function_rows': exact_rows,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
text = json.dumps(receipt, indent=2) + '\n'
bare = set(re.findall(r'"([0-9a-f]{8})"', text))
assert bare <= set(exact_rows), sorted(bare - set(exact_rows))
if DISCOVER:
    print('DISCOVER: receipt not written; %d exact rows' % len(exact_rows))
    sys.exit(0)
RECEIPT.write_text(text)
print('PASS app-unit40c-2008: %d counted exact rows (%s); %d range rows, %d counted elsewhere, %d open; %d Creator '
      'vtables checked; %d vtable-slot rows' % (len(exact_rows), ' '.join(exact_rows), len(range_rows),
                                                len(range_counted), len(open_rows), len(creator_vtables), len(SLOTS)))
