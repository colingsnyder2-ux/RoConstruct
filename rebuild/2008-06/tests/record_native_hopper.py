"""Verify the inactive native RBX::Hopper family and RBX::Tool recovery (2008-06).

Builds (document-swap flags, VS2008 RTM 21022, native headers only):
  * tests/NativeHopperLayout.cpp   layout probes (mov eax, imm32; ret) against allocation sizes and constructor stores;
  * native-classes/Hopper.cpp      Hopper / StarterPackService / LegacyHopperService / BackpackItem / HopperBin
                                   (the original Hopper unit 005cf160..005d1670, initializers 007f5df0..007f5ef0), /fp:fast;
  * native-classes/Tool.cpp        Tool (005fd3a0..006004d0, initializers 007f7640..007f7990), /fp:fast.
Pending builds (rows recorded exact=false, pending-build-only, never counted, vtables never walked):
  * Hopper.cpp with NATIVE_HOPPER_PENDING and Backpack.cpp with NATIVE_BACKPACK_PENDING against
    out/native-layouts/hopper-pending: a generated copy of the donor script/Script.h with the 2008 const-char-array
    class names (`extern const char sScript[]` / `sLocalScript[]`), which Backpack.h needs for IScriptOwner;
  * Tool.cpp with NATIVE_TOOL_PENDING against a generated copy of the native v8tree/Service.h plus the one declaration
    `static const ServiceProvider* findServiceProvider(const Instance* context);` (004898d0 in the original), and a
    generated copy of donor v8datamodel/ToolMouseCommand.h using the original const-char-array class-name ABI
    (Tool::getMouse 005ff680; no native header).

Rows are found by closure from a few seeds (constructors named by the factories that allocate the objects, the dynamic
initializers, and a handful of evidence-named leaves): every REL32/DIR32 relocation of an exact row is bound to the
address the original instruction uses. A target defined in the compiled object becomes a row at that address; a
vtable target is checked by original RTTI (class name and subobject offset) and walked slot by slot, each slot
symbol bound to the original slot value (main builds only). Every other target is verified: imports by DLL export
name, string literals and class-name arrays by bytes, type descriptors by RTTI name, external functions by the
evidence name or the EXTERNAL map (call sites read in the original disassembly). A symbol binds to one address.
Rows of other classes' inline functions reached this way (GuiItem/Widget/Instance inlines, reflection templates) are
recorded as support rows and not counted. Writes work/2008-06/shared-layouts/hopper-family-working.json.
"""
import json
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
HOPPER_SRC = R / 'native-classes/Hopper.cpp'
TOOL_SRC = R / 'native-classes/Tool.cpp'
BACKPACK_SRC = R / 'native-classes/Backpack.cpp'
HEADERS = [R / 'native-headers/v8datamodel' / n for n in ('Hopper.h', 'Tool.h', 'Backpack.h')]
LAYOUT = R / 'tests/NativeHopperLayout.cpp'

# ---- pending overlays ----------------------------------------------------------------------------------------
pending = OUT / 'hopper-pending'
(pending / 'script').mkdir(parents=True, exist_ok=True)
text = (ROOT / 'tools/rbxgs/Client/App/include/script/Script.h').read_text()
text, n1 = re.subn(r'extern const char\* (s\w+);', r'extern const char \1[];', text)
text, n2 = re.subn(r'&(s[A-Z]\w*)>', r'\1>', text)
assert n1 == n2 == 2, (n1, n2)
(pending / 'script/Script.h').write_text(text)
tool_pending = OUT / 'hopper-tool-pending'
(tool_pending / 'v8tree').mkdir(parents=True, exist_ok=True)
text = (R / 'native-headers/v8tree/Service.h').read_text()
assert text.count('static const ServiceProvider* findServiceProvider(const Instance*);') == 1
# The proven declaration is canonical now; retain no duplicate pending declaration.
(tool_pending / 'v8tree/Service.h').write_text(text)
# Tool::getMouse 005ff680: donor declaration with the original char-array Named ABI, never added to native headers.
(tool_pending / 'v8datamodel').mkdir(parents=True, exist_ok=True)
text = (ROOT / 'tools/rbxgs/Client/App/include/v8datamodel/ToolMouseCommand.h').read_text()
for old, new in (('extern const char* sToolMouseCommand;', 'extern const char sToolMouseCommand[];'),
                 ('Named<ScriptMouseCommand, &sToolMouseCommand>', 'Named<ScriptMouseCommand, sToolMouseCommand>')):
    assert text.count(old) == 1, old
    text = text.replace(old, new)
(tool_pending / 'v8datamodel/ToolMouseCommand.h').write_text(text)


def build(name, src, extra=(), post=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + list(post) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeHopperLayout', LAYOUT)
hopper_obj, hopper_flags = build('NativeHopper', HOPPER_SRC, post=['/fp:fast'])
tool_obj, tool_flags = build('NativeTool', TOOL_SRC, post=['/fp:fast'])
hopper_p_obj, hopper_p_flags = build('NativeHopperPending', HOPPER_SRC, ['/I' + str(pending), '/DNATIVE_HOPPER_PENDING'], ['/fp:fast'])
backpack_p_obj, backpack_p_flags = build('NativeBackpackPending', BACKPACK_SRC, ['/I' + str(pending), '/DNATIVE_BACKPACK_PENDING'], ['/fp:fast'])
tool_p_obj, tool_p_flags = build('NativeToolPending', TOOL_SRC, ['/I' + str(tool_pending), '/DNATIVE_TOOL_PENDING'], ['/fp:fast'])

# ---- layout ---------------------------------------------------------------------------------------------------
LAYOUT_VALUES = {
    'nativeHopperSize': 0x168, 'nativeStarterPackSize': 0x168, 'nativeLegacyHopperSize': 0x168,
    'nativeBackpackItemSize': 0x1a0, 'nativeBackpackItemGuiImageDraw': 0x148, 'nativeBackpackItemTextureId': 0x180,
    'nativeHopperBinSize': 0x1a8, 'nativeHopperBinBinType': 0x1a0, 'nativeHopperBinActive': 0x1a4,
    'nativeToolSize': 0x270, 'nativeToolBackendToolState': 0x1c4, 'nativeToolFrontendActivationState': 0x1c8,
    'nativeToolGrip': 0x1cc, 'nativeToolEnabled': 0x1fc, 'nativeToolMouseCommand': 0x200,
    'nativeToolHandleTouched': 0x204, 'nativeToolTorsoChildRemoved': 0x254,
}
raw = layout_obj.read_bytes()
for prefix, value in LAYOUT_VALUES.items():
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?' + prefix + '@@'))
    assert body == b'\xb8' + struct.pack('<I', value) + b'\xc3', (prefix, body.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
pe = original.pe
TEXT = next(s for s in pe.sections if s.Name.startswith(b'.text'))
TEXT_LO = pe.OPTIONAL_HEADER.ImageBase + TEXT.VirtualAddress
TEXT_HI = TEXT_LO + TEXT.Misc_VirtualSize


def norm(symbol):
    return symbol.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


TEXTURE_ID_SLOTS = {
    '?getVariant@?$TypedPropertyDescriptor@VTextureId@RBX@@@Reflection@RBX@@UBEXPBVDescribedBase@23@AAVValue@23@@Z': 4,
    '?setVariant@?$TypedPropertyDescriptor@VTextureId@RBX@@@Reflection@RBX@@UBEXPAVDescribedBase@23@ABVValue@23@@Z': 5,
    '?getStringValue@?$TypedPropertyDescriptor@VTextureId@RBX@@@Reflection@RBX@@UBE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PBVDescribedBase@23@@Z': 7,
    '?setStringValue@?$TypedPropertyDescriptor@VTextureId@RBX@@@Reflection@RBX@@UBE_NPAVDescribedBase@23@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': 8,
    '?writeValue@?$TypedPropertyDescriptor@VTextureId@RBX@@@Reflection@RBX@@EBEXPBVDescribedBase@23@PAVXmlElement@@@Z': 10,
    '?readValue@?$TypedPropertyDescriptor@VTextureId@RBX@@@Reflection@RBX@@EBEXPAVDescribedBase@23@PBVXmlElement@@AAVIReferenceBinder@3@@Z': 11,
    '?isWriteOnly@?$TypedPropertyDescriptor@VTextureId@RBX@@@Reflection@RBX@@UBE_NXZ': 2,
}
TEXTURE_ID_VTABLE = 0x832494
DECAL_TEXTURE_VTABLE = 0x8325a0
assert original.vtable_class(TEXTURE_ID_VTABLE) == ('.?AV?$TypedPropertyDescriptor@VTextureId@RBX@@@Reflection@RBX@@', 0)
assert original.vtable_class(DECAL_TEXTURE_VTABLE) == ('.?AV?$PropDescriptor@VDecal@RBX@@VTextureId@2@@Reflection@RBX@@', 0)
for symbol, slot in TEXTURE_ID_SLOTS.items():
    assert d(TEXTURE_ID_VTABLE + 4 * slot) == d(DECAL_TEXTURE_VTABLE + 4 * slot), (symbol, slot)


# Allocation sizes: each factory pushes the size, calls operator new, then the constructor.
for factory, size, ctor in ((0x48e790, 0x1a8, 0x5d15a0), (0x48ea00, 0x168, 0x5d0fc0), (0x48ec70, 0x168, 0x5d10a0),
                            (0x48bc20, 0x16c, 0x5d1a80), (0x578400, 0x270, 0x600240)):
    body, _, _ = match.target('2008-06', '%08x' % factory)
    at = body.index(b'\x68' + struct.pack('<I', size))
    call = body.index(b'\xe8', at + 5)
    while (factory + call + 5 + struct.unpack_from('<i', body, call + 1)[0]) & 0xffffffff != ctor:
        call = body.index(b'\xe8', call + 1)


def bases(vtable):
    hierarchy = d(d(vtable - 4) + 16)
    out = {}
    for i in range(d(hierarchy + 8)):
        bcd = d(d(hierarchy + 12) + 4 * i)
        out.setdefault(original.string(d(bcd) + 8), struct.unpack('<i', original.data(bcd + 8, 4))[0])
    return out


for vt, cls in ((0x83ac0c, 'Hopper'), (0x83b454, 'StarterPackService'), (0x83acfc, 'LegacyHopperService'),
                (0x83b2f4, 'BackpackItem'), (0x83b66c, 'HopperBin'), (0x83b9bc, 'Backpack'), (0x841a4c, 'Tool')):
    assert original.vtable_class(vt) == ('.?AV%s@RBX@@' % cls, 0), (hex(vt), cls)
tb = bases(0x841a4c)
assert tb['.?AVBackpackItem@RBX@@'] == 0 and tb['.?AVGuiTarget@RBX@@'] == 0x130
assert tb['.?AVIEquipable@RBX@@'] == 0x1a0 and tb['.?AVIRenderable@RBX@@'] == 0x1b0
assert '.?AV?$DescribedCreatable@VTool@RBX@@VBackpackItem@2@$1?sTool@2@3QBDB@RBX@@' in tb
assert '.?AV?$DescribedNonCreatable@VBackpackItem@RBX@@VWidget@2@$1?sBackpackItem@2@3QBDB@RBX@@' in bases(0x83b2f4)
assert '.?AVRelativePanel@RBX@@' in bases(0x83ac0c)
assert bases(0x83b9bc)['.?AVIScriptOwner@RBX@@'] == 0x168

# ---- verification maps ----------------------------------------------------------------------------------------
STR = '?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@'
# Externals whose evidence name differs from the compiled symbol (or has none): the address the original call site
# uses, with the site it was read from.
EXTERNAL = {
    # Independently compiled authentic App/reflection/signal.cpp and Boost 1.34.1 bodies match these original
    # extents byte-for-byte with relocations (isolated signal-destructor-proof receipt).
    '??1SignalInstance@Reflection@RBX@@UAE@XZ': 0x56b4f0,
    '??1signal_base@detail@signals@boost@@QAE@XZ': 0x600660,
    '??1trackable@signals@boost@@IAE@XZ': 0x5950e0,
    '_atexit': 0x6a17af,                                                                     # initializers 007f5df0, 007f7640
    '??1Instance@RBX@@UAE@XZ': 0x55a540,                                                     # ~GuiItem 00411540
    '??0Instance@RBX@@QAE@XZ': 0x55b7e0,                                                     # getMouse pending closure
    '??RDeleter@?$Creatable@VInstance@RBX@@@RBX@@QAEXPAVInstance@2@@Z': 0x405e30,              # exact Mouse creator gate
    '??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z': 0x5708f0,                         # classDescriptor 005c3810
    '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330,                                            # getClassName 005cfdf0, 005fe420
    '??1scoped_connection@signals@boost@@QAE@XZ': 0x5954b0,                                  # ~Tool 005fe4b0
    '?disconnect@connection@signals@boost@@QBEXXZ': 0x595230,                                # downFrom_InCharacter 005fd4c0
    '??1IEquipable@RBX@@MAE@XZ': 0x628f80,                                                   # ~Tool 005fe4b0
    '??1IRenderable@RBX@@QAE@XZ': 0x47d410,                                                  # ~Tool 005fe4b0 (empty-body ICF)
    '??0Matrix3@G3D@@QAE@ABV01@@Z': 0x513220,                                                # getLocation 005fd770, setGripPos 005ffc00
    '?identity@Matrix3@G3D@@SAABV12@XZ': 0x513e20,                                           # CoordinateFrame() 004782d0
    '?white@Color3@G3D@@SAABV12@XZ': 0x514a60,                                               # Widget::getFontColor 005cf500
    '?clear@Color4@G3D@@SAABV12@XZ': 0x7baf10,                                               # GuiItem inlines (Gui.h)
    '?getColumn@Matrix3@G3D@@QBE?AVVector3@2@H@Z': 0x513240,                                # getGripForward 005fd530
    '?zero@Vector2@G3D@@SAABV12@XZ': 0x509ba0,                                               # GuiItem::getChildPosition 00411810
    '?toPixelSize@GuiRoot@RBX@@SA?AVVector2@G3D@@ABV34@@Z': 0x5736f0,                        # BackpackItem::getSize 005cf190
    '??$create@VStarterPackService@RBX@@@ServiceProvider@RBX@@QBEPAVStarterPackService@1@XZ': 0x490d70,  # onServiceProvider 005d0910
    # SignalDesc<...> vector deleting destructor: one ICF-shared body 0041bdf0 (slot 0 of every SignalDesc vtable;
    # the same address record_native_flag_family.py binds for SignalDesc<FlagStand>)
    '??_E?$SignalDesc@VHopperBin@RBX@@$$A6AXV?$shared_ptr@VInstance@RBX@@@boost@@@Z@Reflection@RBX@@UAEPAXI@Z': 0x41bdf0,
    '??_E?$SignalDesc@VHopperBin@RBX@@$$A6AXXZ@Reflection@RBX@@UAEPAXI@Z': 0x41bdf0,
    '??_E?$SignalDesc@VTool@RBX@@$$A6AXV?$shared_ptr@VInstance@RBX@@@boost@@@Z@Reflection@RBX@@UAEPAXI@Z': 0x41bdf0,
    '??_E?$SignalDesc@VTool@RBX@@$$A6AXXZ@Reflection@RBX@@UAEPAXI@Z': 0x41bdf0,
}
# Own functions that are not compiled here (not attempted): bound by the original call / jump / pointer that uses them.
UNPROVEN = {
    '?onSelectCommand@HopperBin@RBX@@AAEXXZ': 0x5d0ec0,                                      # jmp in onLocalClicked 005d1340
    '?onSelectScript@HopperBin@RBX@@AAEXXZ': 0x5d1240,      # jmp in 005d1340; inside the 005d11e0 extent (bounds)
    '?setBinType@HopperBin@RBX@@QAEXW4BinType@12@@Z': 0x5d16d0,                              # initializer 007f5e30
    '?setGripForward@Tool@RBX@@QAEXABVVector3@G3D@@@Z': 0x5ffc50,                            # initializer 007f7700
    '?setGripUp@Tool@RBX@@QAEXABVVector3@G3D@@@Z': 0x5ffdd0,                                 # initializer 007f7760
    '?setGripRight@Tool@RBX@@QAEXABVVector3@G3D@@@Z': 0x5fff40,                              # initializer 007f77c0
    '?setLegacyCommand@HopperBin@RBX@@QAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': 0x5d1770,  # 007f5ec0
}
CLASS_NAMES = {'sBackpackItem': b'BackpackItem', 'sHopperBin': b'HopperBin', 'sStarterPackService': b'StarterPack',
               'sLegacyHopperService': b'Hopper', 'sBackpack': b'Backpack', 'sTool': b'Tool', 'sInstance': b'Instance',
               'sMouse': b'Mouse', 'sToolMouseCommand': b'ToolMouseCommand'}
# External constants: address used by the original instruction, verified by value.
DATA = {'?zLookDirection@CoordinateFrame@G3D@@2MB': (0x828b60, struct.pack('<f', -1.0))}   # getGripForward 005fd530
# ICF folds the closure cannot reach by relocation (none expected).
FOLDED = {}
# Seeds: (address, compiled symbol). Constructors are named by the factories above; initializers and atexit rows are
# reached from them through relocations; leaves not referenced by any compiled row carry their evidence name.
HOPPER_SEEDS = [
    (0x5cf900, '??0Hopper@RBX@@QAE@XZ'),
    (0x5d0fc0, '??0StarterPackService@RBX@@QAE@XZ'),
    (0x5d10a0, '??0LegacyHopperService@RBX@@QAE@XZ'),
    (0x5d15a0, '??0HopperBin@RBX@@QAE@XZ'),
    (0x7f5df0, '??__Edesc_TextureId@RBX@@YAXXZ'),
    (0x7f5e30, '??__Edesc_BinType@RBX@@YAXXZ'),
    (0x7f5e70, '??__Edesc_Selected@RBX@@YAXXZ'),
    (0x7f5e90, '??__Edesc_Deselected@RBX@@YAXXZ'),
    (0x7f5ec0, '??__Edesc_legacyCommand@RBX@@YAXXZ'),
    (0x7f5ef0, '??__Edesc_legacyTextureName@RBX@@YAXXZ'),
]
TOOL_SEEDS = [
    (0x600240, '??0Tool@RBX@@QAE@XZ'),
    (0x7f7640, '??__Eprop_Grip@RBX@@YAXXZ'),
    (0x7f76a0, '??__Eprop_GripPos@RBX@@YAXXZ'),
    (0x7f7700, '??__Eprop_GripForward@RBX@@YAXXZ'),
    (0x7f7760, '??__Eprop_GripUp@RBX@@YAXXZ'),
    (0x7f77c0, '??__Eprop_GripRight@RBX@@YAXXZ'),
    (0x7f7820, '??__Eprop_BackendToolState@RBX@@YAXXZ'),
    (0x7f7880, '??__Eprop_FrontendActivationState@RBX@@YAXXZ'),
    (0x7f78e0, '??__E?prop_Enabled@Tool@RBX@@2V?$BoundProp@_N$00@Reflection@2@A@@YAXXZ'),
    (0x7f7910, '??__Eevent_Equipped@RBX@@YAXXZ'),
    (0x7f7930, '??__Eevent_Unequipped@RBX@@YAXXZ'),
    (0x7f7960, '??__Eevent_Activated@RBX@@YAXXZ'),
    (0x7f7990, '??__Eevent_Deactivated@RBX@@YAXXZ'),
    (0x5fd3e0, '?readProperty@Tool@RBX@@EAEXPBVXmlElement@@AAVIReferenceBinder@2@@Z'),
    (0x5fd4c0, '?downFrom_InCharacter@Tool@RBX@@AAEXXZ'),
    (0x5fd4e0, '?downFrom_HasTorso@Tool@RBX@@AAEXXZ'),
    (0x6004b0, '?activate@Tool@RBX@@QAEXXZ'),
    (0x6004d0, '?deactivate@Tool@RBX@@QAEXXZ'),
]
HOPPER_PENDING_SEEDS = [(0x5cff30, '?isEnabled@BackpackItem@RBX@@MAE_NXZ')]
BACKPACK_PENDING_SEEDS = [(0x5d1a80, '??0Backpack@RBX@@QAE@XZ')]
TOOL_PENDING_SEEDS = [(0x600420, '?setFrontendActivationState@Tool@RBX@@QAEXH@Z'),
                      (0x5ff680, '?getMouse@Tool@RBX@@AAE?AV?$shared_ptr@VMouse@RBX@@@boost@@XZ')]
OWN_CLASSES = 'Hopper|StarterPackService|LegacyHopperService|BackpackItem|HopperBin|Backpack|Tool'
# Classes whose rows count (template instances parameterized on them included).
OWN = re.compile(r'(Hopper|StarterPackService|LegacyHopperService|BackpackItem|HopperBin|Backpack|Tool)@RBX@@'
                 r'|\?\?__[EF](desc_|prop_|event_|\?prop_Enabled@Tool)|sBackpackItem|sHopperBin|sStarterPackService'
                 r'|sLegacyHopperService|sBackpack|sTool')
NOT_ATTEMPTED = {
    '005d05d0': 'BackpackItem::render2d (830 bytes; GuiDrawImage / Adorn drawing)',
    '005d11e0': 'BackpackItem::setTextureId (ContentProvider, ServiceProvider::find<Workspace>, Workspace DrawChanged '
                'notifier; donor Workspace.h does not compile against the native reflection.h)',
    '005cfcd0': 'StarterPackService::render2d (Instance::findFirstChildOfType<BackpackItem> 005cfc30, Adorn::drawFont2D)',
    '005d0ec0': 'HopperBin::onSelectCommand (DataModel verb container +0x1c8, EnumDesc<BinType> string + "Tool")',
    '005d1370/005d13d0': 'HopperBin::onLocalOtherClicked / setLegacyTextureName (Workspace, ContentId::fromAssets)',
    '005d0d80/005d0b40': 'EnumPropDescriptor<HopperBin, BinType> and SignalDesc<HopperBin> constructors: reached as call '
                         'targets of the exact initializers, compared below',
    '005d18e0': 'Backpack::scriptShouldRun (Workspace IScriptOwner +0x340, Players::backendProcessing)',
    '005fd460..005ffdd0': 'Tool state machine (computeDesiredState, upTo_/downFrom_ chains, onEvent_*, setGrip, '
                          'setGripForward/Up/Right, onAncestorChanged, onLocalClicked): needs native '
                          'Humanoid / Workspace / Players declarations; render3dSelect 005fdaf0',
    '005fe7f0..005ff600': 'RBX::Mouse class-template instances (same unit): verified by tests/record_native_mouse.py; '
                          'here only reached from pending getMouse 005ff680',
}

LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
SLOTS = []   # (build, own vtable, symbol, original value, where)
HEADER_GAPS = []


def own_vtable(rtti):
    if any(rtti.startswith('.?AV%s@RBX@@' % c) for c in OWN_CLASSES.split('|')):
        return True
    return rtti.startswith('.?AV?$') and any('$1?s%s@2@' % c in rtti for c in OWN_CLASSES.split('|') + ['StarterPackService', 'LegacyHopperService'])


class Build:
    def __init__(self, name, obj, walk_vtables):
        self.name, self.obj, self.walk = name, Path(obj), walk_vtables
        self.raw = self.obj.read_bytes()
        self.sections, self.symbols, self.definitions, self.starts = match._coff_data_index(self.raw)
        self.bodies = {n: (b, r) for n, b, r in match.coff_functions(self.raw)}
        self.binding = {}     # symbol -> (address, origin)
        self.rows = {}        # address -> row
        self.vtables = {}
        self.queue = []

    def bind(self, symbol, value, origin):
        prev = self.binding.setdefault(symbol, (value, origin))
        assert prev[0] == value, (self.name, 'inconsistent', symbol, hex(prev[0]), prev[1], hex(value), origin)

    def literal(self, symbol):
        pos, at = self.definitions[symbol]
        table = self.sections[at]
        return self.raw[table[4] + pos:table[4] + table[3]].split(b'\0')[0] + b'\0'

    def classify(self, symbol, value, where):
        if symbol in self.bodies and not LOCAL_EH.match(symbol):
            self.bind(symbol, value, where)
            self.queue.append((value, symbol))
            return 'own row'
        if symbol.startswith('??_E') and '??_G' + symbol[4:] in self.bodies:
            # vector deleting destructor referenced, scalar one compiled: the same body in the original
            self.bind('??_G' + symbol[4:], value, where)
            self.queue.append((value, '??_G' + symbol[4:]))
            return 'own row (??_G)'
        hit = original.imported(value)
        if hit is not None:
            assert hit[1] == nb.plain(symbol), (where, symbol, hex(value), hit)
            return '%s!%s' % hit
        if symbol.startswith('??_C@'):
            lit = self.literal(symbol)
            assert original.data(value, len(lit)) == lit, (where, symbol, hex(value))
            return 'literal %r' % lit[:-1].decode()
        if re.match(r'^\?s[A-Z]\w*@RBX@@3QBDB$', symbol):
            lit = self.literal(symbol) if symbol in self.definitions else CLASS_NAMES[symbol[1:symbol.index('@')]] + b'\0'
            assert original.data(value, len(lit)) == lit, (where, symbol, hex(value))
            return 'class name %r' % lit[:-1].decode()
        if symbol.startswith('??_R0') and symbol.endswith('@8'):
            rtti = original.string(value + 8)
            assert norm(rtti) == norm('.' + symbol[5:-2]), (where, symbol, hex(value), rtti)
            return 'RTTI %s' % rtti
        if symbol.startswith('??_7'):
            rtti, at = original.vtable_class(value)
            cls = symbol[4:symbol.index('@@6B') + 2]
            assert norm(rtti) == norm('.?AV' + cls), (where, symbol, hex(value), rtti)
            if self.walk and symbol in self.definitions:
                self.bind(symbol, value, where)
                self.queue.append((value, symbol))
            return 'vtable RTTI %s offset %#x' % (rtti, at)
        if symbol.startswith('??_8'):
            return 'vbtable (bound by consistency)'
        if symbol in FOLDED:
            assert FOLDED[symbol] == value, (where, symbol, hex(value))
            return 'folded'
        if symbol in EXTERNAL:
            assert EXTERNAL[symbol] == value, (where, symbol, hex(value), hex(EXTERNAL[symbol]))
            return 'external' + (' (evidence name)' if norm(names.get(value, '')) == norm(symbol) else '')
        if symbol in DATA:
            assert DATA[symbol][0] == value and original.data(value, len(DATA[symbol][1])) == DATA[symbol][1], (where, symbol)
            return 'constant %s' % DATA[symbol][1].hex()
        if symbol in UNPROVEN:
            assert UNPROVEN[symbol] == value, (where, symbol, hex(value))
            return 'own function not attempted (bound by the original reference)'
        if norm(names.get(value, '')) == norm(symbol) and symbol not in self.definitions:
            return 'external (evidence name)'
        if symbol in self.definitions and symbol not in self.bodies:
            # own static data (descriptor objects, local statics, guard flags): bound by consistency across rows
            return 'own static'
        return None

    def vtable(self, symbol, value):
        start, sec = self.definitions[symbol]
        table = self.sections[sec]
        end = min([x for x in self.starts[sec + 1] if x > start] + [table[3]])
        slots = {}
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', self.raw, table[5] + 10 * i)
            if start <= offset < end:
                slots[(offset - start) // 4] = self.symbols[index][0]
        assert slots and max(slots) == len(slots) - 1, (symbol, sorted(slots))
        rtti, at = original.vtable_class(value)
        own = own_vtable(rtti)
        after = d(value + 4 * len(slots))
        longer = TEXT_LO <= after < TEXT_HI
        info = {'address': hex(value), 'rtti': rtti, 'offset': hex(at), 'own_class': own}
        self.vtables[symbol] = info
        if longer:
            # The dword after the compiled length is a code address in the original. For the classes' own
            # most-derived vtables (offset 0) that would be a missing virtual: asserted. Elsewhere it can also be
            # unrelated .rdata that follows the vtable (FactoryProduct<Tool> 00841904 is followed by a boost::function
            # manager table 005fdec0 / 00618cd0): recorded only.
            assert not (own and at == 0 and any(rtti == '.?AV%s@RBX@@' % c for c in OWN_CLASSES.split('|'))), \
                (symbol, hex(value), 'original vtable longer', hex(after))
            info['next_dword_is_code'] = 'slot %d position holds %s in the original' % (len(slots), hex(after))
            if not own:
                info['not_walked'] = 'shared template vtable; length not proven'
                return
        checked = {}
        for slot, sym in sorted(slots.items()):
            orig = d(value + 4 * slot)
            where = '%s slot %d' % (symbol, slot)
            if (sym in self.bodies or sym.startswith('??_7') or sym.startswith('??_R')
                    or (sym.startswith('??_E') and '??_G' + sym[4:] in self.bodies)):
                how = self.classify(sym, orig, where)
                if how is None:
                    UNBOUND.append('%s: vtable %s slot %d %s -> %s' % (self.name, symbol, slot, sym, hex(orig)))
                    continue
                self.bind(sym, orig, where)
            else:
                # Inherited external virtual: verified after all builds (evidence name, EXTERNAL map, or the same
                # address at every other place the symbol occurs).
                SLOTS.append((self.name, own, sym, orig, where))
                how = 'external slot'
            checked[slot] = '%s = %s (%s)' % (sym, hex(orig), how)
        info['slots'] = checked

    def row(self, address, name):
        if address in self.rows and self.rows[address]['symbol'] == name:
            return
        body, refs = self.bodies[name]
        target, target_refs, _ = match.target('2008-06', '%08x' % address)
        exact = match.exact_match(target, target_refs, body, refs)
        entry = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target),
                 'exact': exact, 'counted_class': bool(OWN.search(name))}
        key = address if address not in self.rows else (address, name)
        self.rows[key] = entry
        if not exact:
            return
        start, section = self.definitions[name]
        table = self.sections[section]
        code = self.raw[table[4] + start:]
        verified, local = {}, set()
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', self.raw, table[5] + 10 * i)
            offset -= start
            if not 0 <= offset < len(body):
                continue
            symbol = self.symbols[index][0]
            if kind == 20:
                value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            else:
                value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
            if LOCAL_EH.match(symbol):
                local.add(symbol)
                continue
            how = self.classify(symbol, value, name)
            if how is None:
                UNBOUND.append('%s: %s in %s -> %s' % (self.name, symbol, name, hex(value)))
                continue
            self.bind(symbol, value, name)
            verified[symbol] = '%s (%s)' % (hex(value), how)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local)})

    def run(self, seeds):
        for address, name in seeds:
            assert name in self.bodies, (self.name, name)
            self.bind(name, address, 'seed')
            self.queue.append((address, name))
        while self.queue:
            value, symbol = self.queue.pop(0)
            if symbol.startswith('??_7'):
                if symbol not in self.vtables:
                    self.vtable(symbol, value)
            else:
                self.row(value, symbol)
        return self


hopper = Build('hopper', hopper_obj, True).run(HOPPER_SEEDS)
tool = Build('tool', tool_obj, True).run(TOOL_SEEDS)
pending_builds = [Build('hopper-pending', hopper_p_obj, False).run(HOPPER_PENDING_SEEDS),
                  Build('backpack-pending', backpack_p_obj, False).run(BACKPACK_PENDING_SEEDS),
                  Build('tool-pending', tool_p_obj, False).run(TOOL_PENDING_SEEDS)]
# External vtable slots: one address per symbol across every vtable and relocation binding of the main builds.
occurrences = {}
for build in (hopper, tool):
    for symbol, (value, origin) in build.binding.items():
        occurrences.setdefault(symbol, set()).add((value, build.name + ': ' + origin))
for build, own, symbol, value, where in SLOTS:
    occurrences.setdefault(symbol, set()).add((value, build + ': ' + where))
SLOT_CHECK = {}
for build, own, symbol, value, where in SLOTS:
    values = {v for v, _ in occurrences[symbol]}
    if len(values) > 1:
        assert not own, ('inconsistent external slot in an own vtable', symbol, sorted(occurrences[symbol]))
        HEADER_GAPS.append('%s: %s -> %s, but %s elsewhere (the shared header lacks an override)'
                           % (where, symbol, hex(value), sorted(hex(v) for v in values - {value})))
        continue
    if symbol in EXTERNAL:
        assert EXTERNAL[symbol] == value, (symbol, hex(value))
        how = 'external'
    elif norm(names.get(value, '')) == norm(symbol):
        how = 'evidence name'
    elif symbol in TEXTURE_ID_SLOTS and not own:
        slot = TEXTURE_ID_SLOTS[symbol]
        assert d(TEXTURE_ID_VTABLE + 4 * slot) == value, (symbol, hex(value), slot)
        assert d(DECAL_TEXTURE_VTABLE + 4 * slot) == value, (symbol, hex(value), slot)
        how = 'matching RTTI-anchored TextureId descriptor slot %d' % slot
    elif len({w for _, w in occurrences[symbol]}) > 1:
        how = 'same address at %d places' % len({w for _, w in occurrences[symbol]})
    else:
        UNBOUND.append('%s: unverified external slot %s -> %s (%s)' % (build, symbol, hex(value), where))
        continue
    SLOT_CHECK['%s | %s' % (where, symbol)] = '%s (%s)' % (hex(value), how)
assert not UNBOUND, '\n'.join(sorted(set(UNBOUND)))

# The same symbol compiled in two main units (shared template instances) must bind to the same address.
for symbol, (value, _) in hopper.binding.items():
    if symbol in tool.binding:
        assert tool.binding[symbol][0] == value, (symbol, hex(value), hex(tool.binding[symbol][0]))

# Key rows that must be exact in the main builds.
REQUIRED = {
    'hopper': [0x5cf900, 0x5d0fc0, 0x5d10a0, 0x5d0c10, 0x5cfe50, 0x5d15a0, 0x5d0910, 0x5cf1c0, 0x5cf160, 0x5cf190,
               0x5d1340, 0x5d1670],
    'tool': [0x600240, 0x5fe4b0, 0x5fd770, 0x5c3810, 0x5ff8d0, 0x5ffc00, 0x6004b0, 0x6004d0, 0x5fd500, 0x5fd530],
}
for build in (hopper, tool):
    for address in REQUIRED[build.name]:
        hits = [r for k, r in build.rows.items() if (k if isinstance(k, int) else k[0]) == address]
        assert hits and all(r['exact'] for r in hits), (build.name, hex(address), hits)
pending_rows = []
for build in pending_builds:
    for row in build.rows.values():
        main = [r for r in list(hopper.rows.values()) + list(tool.rows.values())
                if r['address'] == row['address'] and r['symbol'] == row['symbol'] and r['exact']]
        if main:
            continue   # also exact in a main build: counted there
        row['exact_pending_build_only'] = row['exact']
        row['exact'] = False
        pending_rows.append(dict(row, build=build.name))

GET_MOUSE_PENDING = [r for r in pending_rows if r['build'] == 'tool-pending' and r['address'] == '005ff680'
                     and r['symbol'] == '?getMouse@Tool@RBX@@AAE?AV?$shared_ptr@VMouse@RBX@@@boost@@XZ']
assert len(GET_MOUSE_PENDING) == 1 and GET_MOUSE_PENDING[0]['exact_pending_build_only']

main_rows = list(hopper.rows.values()) + list(tool.rows.values())
# Unit ranges of the original Hopper and Tool units (and their initializer / atexit stretches). Outside them only
# class-specific template instances count (a class-name template argument of these classes); ICF-shared generic
# bodies reached through these classes' vtables (`return true` 00565ff0, empty 0047d410, RelativePanel thunks) are
# exact support rows, not counted.
UNIT_RANGES = ((0x5cf100, 0x5d1ba0), (0x5fd300, 0x600600), (0x7f5df0, 0x7f5f20), (0x7f7640, 0x7f79c0),
               (0x7fe000, 0x800200))
CLASS_ARG = re.compile(r'\$1\?s(%s)@' % (OWN_CLASSES + '|StarterPackService|LegacyHopperService'))


def counts(address):
    a = int(address, 16)
    syms = [r['symbol'] for r in main_rows if r['address'] == address and r['exact']]
    if not syms or not all(r['exact'] for r in main_rows if r['address'] == address):
        return False
    if any(lo <= a < hi for lo, hi in UNIT_RANGES):
        return any(OWN.search(x) for x in syms)
    return all(OWN.search(x) for x in syms) and any(CLASS_ARG.search(x) for x in syms)


counted = sorted({r['address'] for r in main_rows if counts(r['address'])})
support = sorted({r['address'] for r in main_rows if r['exact']} - set(counted))
inexact = list({(r['address'], r['symbol']): r for r in main_rows if not r['exact']}.values())
sha = nb.sha
paths = [Path(__file__).resolve(), LAYOUT, HOPPER_SRC, TOOL_SRC, BACKPACK_SRC] + HEADERS + [
    ROOT / 'tools/rbxgs/Client/App/include/v8datamodel/ToolMouseCommand.h']
receipt = {
    'class': 'RBX::Hopper, StarterPackService, LegacyHopperService, BackpackItem, HopperBin, Backpack, Tool',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': {'layout': layout_flags, 'hopper': hopper_flags, 'tool': tool_flags, 'hopper_pending': hopper_p_flags,
              'backpack_pending': backpack_p_flags, 'tool_pending': tool_p_flags},
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in (layout_obj, hopper_obj, tool_obj, hopper_p_obj, backpack_p_obj, tool_p_obj)},
    'pending_overlays': {
        str(p.relative_to(ROOT)).replace('\\', '/'): sha(p)
        for p in (pending / 'script/Script.h', tool_pending / 'v8tree/Service.h',
                  tool_pending / 'v8datamodel/ToolMouseCommand.h')},
    'layout': {k: hex(v) for k, v in LAYOUT_VALUES.items()},
    'exact_function_rows': counted,
    'exact_support_rows': support,
    'rows': {'hopper': list(hopper.rows.values()), 'tool': list(tool.rows.values())},
    'not_exact_rows': [{'address': r['address'], 'symbol': r['symbol'], 'size': r['size'],
                        'target_size': r['target_size']} for r in inexact],
    'pending_rows': pending_rows,
    'tool_get_mouse_pending_only': GET_MOUSE_PENDING[0],
    'vtables': dict(hopper.vtables, **tool.vtables),
    'external_slots': SLOT_CHECK,
    'shared_header_gaps': HEADER_GAPS,
    'pending_note': 'pending_rows are exact only against generated copies (out/native-layouts/hopper-pending: donor '
                    'script/Script.h with const-char-array class names; hopper-tool-pending: native v8tree/Service.h + '
                    'ServiceProvider::findServiceProvider). Not counted; their vtables are not walked.',
    'not_attempted': NOT_ATTEMPTED,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/hopper-family-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native Hopper family/Tool: %d distinct class addresses exact (+%d support rows), %d compiled rows not '
      'exact, %d pending-build-only rows not counted; %d vtables walked'
      % (len(counted), len(support), len(inexact), sum(1 for r in pending_rows if r.get('exact_pending_build_only')),
         len(receipt['vtables'])))
