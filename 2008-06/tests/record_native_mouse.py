"""Verify the inactive native RBX::Mouse recovery (2008-06).

Builds (document-swap flags, VS2008 RTM 21022, native headers only):
  * tests/NativeMouseLayout.cpp   layout probes (mov eax, imm32; ret) against the allocation size and constructor stores;
  * native-classes/Mouse.cpp      (/fp:fast) Mouse bodies (0064df60..0064e80f), descriptor template instances (0064e1e0..0064e5f0),
                                  initializers 007f8c40..007f8f30 and atexit rows, plus the class-template instances the
                                  original emits in the Tool unit (constructor chain, classDescriptor, ~Mouse,
                                  create<Mouse>), here COMDATs of an explicit create<Mouse> instantiation.
Comparison build uses the canonical native IIDREF declaration in an isolated include overlay. Pending-only rows
remain excluded and vtables are not walked in that comparison build.

Rows are found by closure from seeds (the constructor and factory, the dynamic initializers, update): every
REL32/DIR32 relocation of an exact row is bound to the address the original instruction uses. A target defined in the
compiled object becomes a row at that address; a vtable target is checked by original RTTI (class name and subobject
offset) and walked slot by slot, each slot symbol bound to the original slot value (main build only). Every other
target is verified: imports by DLL export name, string literals and the class-name array by bytes, type descriptors
by RTTI name, external functions by the evidence name or the EXTERNAL map (call sites read in the original
disassembly). A symbol binds to one address. Writes work/2008-06/shared-layouts/mouse-working.json.
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
OUT = R / 'out/native-mouse'
OUT.mkdir(parents=True, exist_ok=True)
SRC = R / 'native-classes/Mouse.cpp'
HDR = R / 'native-headers/v8datamodel/Mouse.h'
LAYOUT = R / 'tests/NativeMouseLayout.cpp'
VERBOSE = '--verbose' in sys.argv

# ---- comparison overlay mirrors the canonical IIDREF declaration --------------------------------------------
pending = OUT / 'mouse-pending'
(pending / 'reflection').mkdir(parents=True, exist_ok=True)
PROPOSAL_ANCHOR = '\tclass IIDREF\n'
PROPOSAL = '\tclass __declspec(novtable) IIDREF\n'
text = (R / 'native-headers/reflection/reflection.h').read_text()
if text.count(PROPOSAL_ANCHOR) == 1:
    text = text.replace(PROPOSAL_ANCHOR, PROPOSAL)
else:
    assert text.count(PROPOSAL) == 1, 'IIDREF declaration is neither canonical nor the known pre-proposal form'
(pending / 'reflection/reflection.h').write_text(text)


def build(name, src, extra=(), post=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + list(post) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


UNIT_FLAGS = ['/fp:fast']   # getOrigin 0064e050 keeps ray.origin + ray.direction in x87 registers
layout_obj, layout_flags = build('NativeMouseLayout', LAYOUT)
main_obj, main_flags = build('NativeMouse', SRC, post=UNIT_FLAGS)
pend_obj, pend_flags = build('NativeMousePending', SRC, ['/I' + str(pending), '/DNATIVE_MOUSE_PENDING'], UNIT_FLAGS)

# ---- layout ---------------------------------------------------------------------------------------------------
LAYOUT_VALUES = {'nativeMouseSize': 0x168, 'nativeMouseLastEvent': 0x130, 'nativeMouseIcon': 0x144,
                 'nativeMouseCommand': 0x164, 'nativeUIEventSize': 0x14, 'nativeTextureIdSize': 0x20,
                 'nativeInstanceSize': 0x130}
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


# Allocation size: create<Mouse> 005ff600 pushes 0x168, calls operator new, then the constructor 005ff3b0.
body, _, _ = match.target('2008-06', '005ff600')
at = body.index(b'\x68' + struct.pack('<I', 0x168))
call = body.index(b'\xe8', at + 5)
while (0x5ff600 + call + 5 + struct.unpack_from('<i', body, call + 1)[0]) & 0xffffffff != 0x5ff3b0:
    call = body.index(b'\xe8', call + 1)


def bases(vtable):
    hierarchy = d(d(vtable - 4) + 16)
    out = {}
    for i in range(d(hierarchy + 8)):
        bcd = d(d(hierarchy + 12) + 4 * i)
        out.setdefault(original.string(d(bcd) + 8), struct.unpack('<i', original.data(bcd + 8, 4))[0])
    return out


assert original.vtable_class(0x841cdc) == ('.?AVMouse@RBX@@', 0)
mb = bases(0x841cdc)
assert len(mb) == 21 and mb['.?AVInstance@RBX@@'] == 0, mb
assert '.?AV?$DescribedNonCreatable@VMouse@RBX@@VInstance@2@$1?sMouse@2@3QBDB@RBX@@' in mb
assert '.?AV?$NonFactoryProduct@VInstance@RBX@@$1?sMouse@2@3QBDB@RBX@@' in mb
# No virtual overrides: the Mouse vtable repeats the 16 Instance slots (0082d884).
assert [d(0x841cdc + 4 * i) for i in range(16)] == [d(0x82d884 + 4 * i) for i in range(16)]
assert original.string(0x84b260) == 'Mouse'

# ---- verification maps ----------------------------------------------------------------------------------------
# Externals whose evidence name differs from the compiled symbol (or has none): the address the original call site
# uses, with the site it was read from.
EXTERNAL = {
    # Independently compiled authentic App/reflection/signal.cpp and Boost 1.34.1 bodies match these original
    # extents byte-for-byte with relocations (isolated signal-destructor-proof receipt).
    '??1SignalInstance@Reflection@RBX@@UAE@XZ': 0x56b4f0,
    '??1signal_base@detail@signals@boost@@QAE@XZ': 0x600660,
    '??1trackable@signals@boost@@IAE@XZ': 0x5950e0,
    '_atexit': 0x6a17af,                                                                     # initializer 007f8c40
    '??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z': 0x5708f0,                         # classDescriptor 005fe7f0
    '??0Instance@RBX@@IAE@XZ': 0x55b7e0,                                                     # NonFactoryProduct 005fd5c0
    '??1Instance@RBX@@MAE@XZ': 0x55a540,                                                     # ~Mouse 005ff520
    '??1ClassDescriptor@Reflection@RBX@@UAE@XZ': 0x40abc0,                                   # atexit 00800040
    '?identity@Matrix3@G3D@@SAABV12@XZ': 0x513e20,                                           # getOrigin 0064e0c6
    '??0Matrix3@G3D@@QAE@ABV01@@Z': 0x513220,                                                # getOrigin 0064e0d2
    '??0Instance@RBX@@QAE@XZ': 0x55b7e0,                                                     # NonFactoryProduct 005fd5c3
    '??1Instance@RBX@@UAE@XZ': 0x55a540,                                                     # ~Mouse 005ff55b
    '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330,                                            # as record_native_hopper.py
    '?ignoreVector3@MouseCommand@RBX@@0VVector3@G3D@@A': 0x97bee0,                           # getTarget 0064e032
    '?getUnitMouseRay@MouseCommand@RBX@@QBE?AVRay@G3D@@ABVUIEvent@2@@Z': 0x615d00,           # getOrigin 0064e097
    '?lookAt@CoordinateFrame@G3D@@QAEXABVVector3@2@@Z': 0x518e20,                            # getOrigin 0064e111
    '??RDeleter@?$Creatable@VInstance@RBX@@@RBX@@QAEXPAVInstance@2@@Z': 0x405e30,            # shared_count catch funclet 005fda0e
    # boost::signals internals called by the signal0 / signal1 call operators (support rows, read at their call sites)
    '??0call_notification@detail@signals@boost@@QAE@ABV?$shared_ptr@Vsignal_base_impl@detail@signals@boost@@@3@@Z': 0x56a760,
    '??1call_notification@detail@signals@boost@@QAE@XZ': 0x56a650,
    '?begin@named_slot_map@detail@signals@boost@@QAE?AVnamed_slot_map_iterator@234@XZ': 0x571380,
    '?end@named_slot_map@detail@signals@boost@@QAE?AVnamed_slot_map_iterator@234@XZ': 0x5713b0,
    # SignalDesc<...> vector deleting destructor: one ICF-shared body 0041bdf0 (slot 0 of every SignalDesc vtable;
    # the same address record_native_hopper.py binds for SignalDesc<Tool>)
    '??_E?$SignalDesc@VMouse@RBX@@$$A6AXXZ@Reflection@RBX@@UAEPAXI@Z': 0x41bdf0,
    '??_E?$SignalDesc@VMouse@RBX@@$$A6AXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z@Reflection@RBX@@UAEPAXI@Z': 0x41bdf0,
}
# Slots of other classes' vtables reached from this unit (reflection internals, std exceptions): the value is read
# from the original vtable the compiled one binds to by RTTI (class name and offset); listed so a change shows.
EXTERNAL_SLOTS = {
    '??_EDescriptor@Reflection@RBX@@UAEPAXI@Z': 0x5eee00,
    '??_ESignalInstance@Reflection@RBX@@UAEPAXI@Z': 0x41a5d0,
    '??_ETSignalInstance@?$TSignalDesc@$$A6AXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z@Reflection@RBX@@UAEPAXI@Z': 0x6347a0,
    '??_ETSignalInstance@?$TSignalDesc@$$A6AXXZ@Reflection@RBX@@UAEPAXI@Z': 0x6347a0,
    '??_Elength_error@std@@UAEPAXI@Z': 0x55c390,
    '??_Elogic_error@std@@UAEPAXI@Z': 0x55c390,
    '??_Eruntime_error@std@@UAEPAXI@Z': 0x409dc0,
    '??_Ebad_function_call@boost@@UAEPAXI@Z': 0x409dc0,
    '??_ERay@G3D@@UAEPAXI@Z': 0x510780,
    '??_EType@Reflection@RBX@@UAEPAXI@Z': 0x5eee00,
    '??_E?$sp_counted_impl_pd@PAVMouse@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@2@@detail@boost@@UAEPAXI@Z': 0x415000,
    '?connectGeneric@?$SignalDescImpl@$00$$A6AXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z@Reflection@RBX@@MBE?AVconnection@signals@boost@@PAVSignalInstance@23@PAVGenericSlotWrapper@23@W4connect_position@56@@Z': 0x41d3d0,
    '?connectGeneric@?$SignalDescImpl@$0A@$$A6AXXZ@Reflection@RBX@@MBE?AVconnection@signals@boost@@PAVSignalInstance@23@PAVGenericSlotWrapper@23@W4connect_position@56@@Z': 0x4b5f60,
}
# Own functions that are not compiled here (not attempted): bound by the original call / pointer that uses them.
UNPROVEN = {}
CLASS_NAMES = {'sMouse': b'Mouse', 'sInstance': b'Instance'}
DATA = {}
FOLDED = {}
SEEDS = [
    (0x5ff600, '??$create@VMouse@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VMouse@RBX@@@boost@@XZ'),
    (0x64e390, '??$?0P8Mouse@RBX@@BEPAVPartInstance@1@XZH@?$RefPropDescriptor@VMouse@RBX@@VPartInstance@2@@Reflection@RBX@@QAE@PBD0P8Mouse@2@BEPAVPartInstance@2@XZHW4Functionality@PropertyDescriptor@12@@Z'),
    (0x64e660, '?update@Mouse@RBX@@QAEXABVUIEvent@2@@Z'),
    (0x7f8c40, '??__Eevent_Move@RBX@@YAXXZ'),
    (0x7f8c70, '??__Eevent_Idle@RBX@@YAXXZ'),
    (0x7f8ca0, '??__Eevent_Button1Down@RBX@@YAXXZ'),
    (0x7f8cd0, '??__Eevent_Button2Down@RBX@@YAXXZ'),
    (0x7f8d00, '??__Eevent_Button1Up@RBX@@YAXXZ'),
    (0x7f8d30, '??__Eevent_Button2Up@RBX@@YAXXZ'),
    (0x7f8d60, '??__Eevent_WheelForward@RBX@@YAXXZ'),
    (0x7f8d90, '??__Eevent_WheelBackward@RBX@@YAXXZ'),
    (0x7f8dc0, '??__Eevent_KeyDown@RBX@@YAXXZ'),
    (0x7f8de0, '??__Eprop_Hit@RBX@@YAXXZ'),
    (0x7f8e10, '??__Eprop_Origin@RBX@@YAXXZ'),
    (0x7f8e40, '??__Eprop_Target@RBX@@YAXXZ'),
    (0x7f8e70, '??__Eprop_X@RBX@@YAXXZ'),
    (0x7f8ea0, '??__Eprop_Y@RBX@@YAXXZ'),
    (0x7f8ed0, '??__Eprop_ViewSizeX@RBX@@YAXXZ'),
    (0x7f8f00, '??__Eprop_ViewSizeY@RBX@@YAXXZ'),
    (0x7f8f30, '??__Eprop_Icon@RBX@@YAXXZ'),
]
SEEDS += [
    (0x64e220, '??$getset@P8Mouse@RBX@@BEPAVPartInstance@2@XZ@?$PropDescriptor@VMouse@RBX@@PAVPartInstance@2@@Reflection@RBX@@SA?AV?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@PAVPartInstance@RBX@@@Reflection@RBX@@@std@@P8Mouse@2@BEPAVPartInstance@2@XZH@Z'),
    (0x583f40, '??$singleton@PAVMouse@RBX@@@RefType@Reflection@RBX@@SAABV012@XZ'),
]
# GetSet bodies, read from the original getset vtables. The 2008 GetSet has four slots (isReadOnly, a second bool
# virtual, getValue, setValue); the native reflection.h GetSet has three, so these vtables are not walked (shared
# header gap, recorded) and each body is seeded from its original slot instead.
GETSET_VTABLES = {
    0x84b26c: '?$GetImpl@P8Mouse@RBX@@BE?AVCoordinateFrame@G3D@@XZ@?$PropDescriptor@VMouse@RBX@@VCoordinateFrame@G3D@@@Reflection@RBX@@',
    0x84b280: '?$GetImpl@P8Mouse@RBX@@BEPAVPartInstance@2@XZ@?$PropDescriptor@VMouse@RBX@@PAVPartInstance@2@@Reflection@RBX@@',
    0x84b294: '?$GetImpl@P8Mouse@RBX@@BEHXZ@?$PropDescriptor@VMouse@RBX@@H@Reflection@RBX@@',
    0x84b2a8: '?$GetSetImpl@P8Mouse@RBX@@BE?AVTextureId@2@XZP812@AEXABV32@@Z@?$PropDescriptor@VMouse@RBX@@VTextureId@2@@Reflection@RBX@@',
}
for vt, cls in GETSET_VTABLES.items():
    assert original.vtable_class(vt) == ('.?AV' + cls, 0), (hex(vt), original.vtable_class(vt))
    assert d(vt + 4) == 0x60a2f0, hex(vt)   # second bool virtual: return false (ICF-shared)
    SEEDS += [(d(vt), '?isReadOnly@' + cls + 'UBE_NXZ'), (d(vt + 8), '?getValue@' + cls), (d(vt + 12), '?setValue@' + cls)]
PENDING_SEEDS = [(0x64e390, '??$?0P8Mouse@RBX@@BEPAVPartInstance@1@XZH@?$RefPropDescriptor@VMouse@RBX@@VPartInstance@2@@Reflection@RBX@@QAE@PBD0P8Mouse@2@BEPAVPartInstance@2@XZHW4Functionality@PropertyDescriptor@12@@Z')]
OWN_CLASSES = 'Mouse'
OWN = re.compile(r'Mouse@RBX@@|\?\?__[EF](event_|prop_)|sMouse')
NOT_ATTEMPTED = {
    '005ff680': 'Tool::getMouse (Tool unit) lives in native-classes/Tool.cpp under NATIVE_TOOL_PENDING: exact there '
                'against a generated donor ToolMouseCommand.h with the 2008 class-name array (record_native_hopper.py, '
                'pending-build-only, not counted).',
}
NON_EXACT_REASONS = {
    '005ff520': '~Mouse: byte-exact with bound targets, but the analyzed extent (0x6f) also covers ??_GMouse 005ff570; '
                'boundary evidence, not counted.',
    '005ff570': '??_GMouse: byte-exact with bound targets, but no analyzed function starts here (inside 005ff520).',
}
HEADER_NOTES = [
    'native-headers/reflection/reflection.h GetSet has three virtuals; the 2008 GetSet vtables (0084b26c, 0084b280, '
    '0084b294, 0084b2a8) have four (isReadOnly, a second bool virtual = 0060a2f0 return false, getValue, setValue). The '
    'GetImpl / GetSetImpl vtables are therefore not walked; their bodies are seeded from the original slots.',
    'PropDescriptor<Mouse, T> / TypedPropertyDescriptor<T> vtables are shared reflection layouts (the original has a '
    'per-type bool virtual in slot 6 where the donor property.h has read): RTTI-bound, not walked.',
]

# Inherited methods lack evidence-name entries. Exact slots are anchored by two independent RTTI-checked vtables.
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

MOUSE_REF_SLOTS = {
    '?assignIDREF@?$RefPropDescriptor@VMouse@RBX@@VPartInstance@2@@Reflection@RBX@@UBEXPAVDescribedBase@23@ABVInstanceHandle@3@@Z': (0x84b2f0, 0),
    '?isReadOnly@?$RefPropDescriptor@VMouse@RBX@@VPartInstance@2@@Reflection@RBX@@UBE_NXZ': (0x84b2f8, 1),
    '?isWriteOnly@RefPropertyDescriptor@Reflection@RBX@@UBE_NXZ': (0x84b2f8, 2),
    '?equalValues@?$RefPropDescriptor@VMouse@RBX@@VPartInstance@2@@Reflection@RBX@@UBE_NPBVDescribedBase@23@0@Z': (0x84b2f8, 3),
    '?getVariant@RefPropertyDescriptor@Reflection@RBX@@UBEXPBVDescribedBase@23@AAVValue@23@@Z': (0x84b2f8, 4),
    '?setVariant@RefPropertyDescriptor@Reflection@RBX@@UBEXPAVDescribedBase@23@ABVValue@23@@Z': (0x84b2f8, 5),
    '?getStringValue@RefPropertyDescriptor@Reflection@RBX@@MBE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PBVDescribedBase@23@@Z': (0x84b2f8, 7),
    '?setStringValue@RefPropertyDescriptor@Reflection@RBX@@MBE_NPAVDescribedBase@23@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': (0x84b2f8, 8),
    '?writeValue@?$RefPropDescriptor@VMouse@RBX@@VPartInstance@2@@Reflection@RBX@@UBEXPBVDescribedBase@23@PAVXmlElement@@@Z': (0x84b2f8, 10),
    '?readValue@?$RefPropDescriptor@VMouse@RBX@@VPartInstance@2@@Reflection@RBX@@UBEXPAVDescribedBase@23@PBVXmlElement@@AAVIReferenceBinder@3@@Z': (0x84b2f8, 11),
    '?getRefValue@?$RefPropDescriptor@VMouse@RBX@@VPartInstance@2@@Reflection@RBX@@UBEPAVDescribedBase@23@PBV423@@Z': (0x84b2f8, 12),
    '?setRefValue@?$RefPropDescriptor@VMouse@RBX@@VPartInstance@2@@Reflection@RBX@@UBEXPAVDescribedBase@23@0@Z': (0x84b2f8, 13),
}
assert original.vtable_class(0x84b2f8) == ('.?AV?$RefPropDescriptor@VMouse@RBX@@VPartInstance@2@@Reflection@RBX@@', 0)
assert original.vtable_class(0x84b2f0) == ('.?AV?$RefPropDescriptor@VMouse@RBX@@VPartInstance@2@@Reflection@RBX@@', 0x18)
for symbol, (vtable, slot) in MOUSE_REF_SLOTS.items():
    assert d(vtable + 4 * slot) != 0, (symbol, vtable, slot)

LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
SLOTS = []   # (build, own vtable, symbol, original value, where)
HEADER_GAPS = []


def own_vtable(rtti):
    # Mouse itself and the class templates parameterized on the class-name array; descriptor templates
    # (PropDescriptor<Mouse, T>, SignalDesc<Mouse, ...>) share the reflection header's vtable layout: not own.
    return rtti.startswith('.?AVMouse@RBX@@') or (rtti.startswith('.?AV?$') and '$1?sMouse@2@' in rtti)


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
        self.split = []       # funclet row addresses proven as the second half of a two-row body

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
            assert not (own and at == 0 and rtti == '.?AVMouse@RBX@@'), (symbol, hex(value), 'original vtable longer')
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
                # Inherited external virtual: verified after the build (evidence name, EXTERNAL map, or the same
                # address at every other place the symbol occurs).
                SLOTS.append((self.name, own, sym, orig, where))
                how = 'external slot'
            checked[slot] = '%s = %s (%s)' % (sym, hex(orig), how)
        info['slots'] = checked

    def row(self, address, name):
        if address in self.rows and self.rows[address]['symbol'] == name:
            return
        body, refs = self.bodies[name]
        status = None
        try:
            target, target_refs, _ = match.target('2008-06', '%08x' % address)
            exact = match.exact_match(target, target_refs, body, refs)
            if not exact and len(target) < len(body):
                # a catch funclet the function list starts as a row of its own (shared_count<Mouse> 005fd9a0 +
                # 005fda0e): compare against the concatenation of the two contiguous rows
                try:
                    tail, tail_refs, _ = match.target('2008-06', '%08x' % (address + len(target)))
                except SystemExit:
                    tail = None
                if tail is not None and len(target) + len(tail) == len(body) and match.exact_match(
                        target + tail, list(target_refs) + [len(target) + r for r in tail_refs], body, refs):
                    exact = True
                    status = 'two contiguous rows: %08x + %08x (catch funclet)' % (address, address + len(target))
                    target = target + tail
                    self.split.append('%08x' % (address + len(target) - len(tail)))
            if not exact and len(target) > len(body) and match.exact_match(
                    target[:len(body)], [r for r in target_refs if r < len(body)], body, refs):
                # the analyzed extent runs on into the next function (~Mouse 005ff520 covers ??_G 005ff570)
                status = 'bytes-exact-prefix: analyzed extent %#x covers the next function at %08x' % (
                    len(target), address + len(body) + (-len(body)) % 16)
        except SystemExit:
            # no analyzed function start (??_GMouse 005ff570 sits inside the 005ff520 extent): compare the original
            # bytes directly with this object's relocation fields masked
            target, target_refs = original.data(address, len(body)), []
            exact = False
            if match.exact_match(target, [], body, refs):
                status = 'bytes-exact-no-function-start'
        entry = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target),
                 'exact': exact, 'counted_class': bool(OWN.search(name))}
        if status:
            entry['bounds_status'] = status
        key = address if address not in self.rows else (address, name)
        self.rows[key] = entry
        if not exact and not status:
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
            if name not in self.bodies:
                hits = [n for n in self.bodies if n.startswith(name) and not LOCAL_EH.match(n)]
                assert len(hits) == 1, (self.name, name, hits)
                name = hits[0]
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


mouse = Build('mouse', main_obj, True).run(SEEDS)
pending_build = Build('mouse-pending', pend_obj, False).run(PENDING_SEEDS)
occurrences = {}
for symbol, (value, origin) in mouse.binding.items():
    occurrences.setdefault(symbol, set()).add((value, 'mouse: ' + origin))
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
    elif symbol in MOUSE_REF_SLOTS and not own:
        vtable, slot = MOUSE_REF_SLOTS[symbol]
        assert d(vtable + 4 * slot) == value, (symbol, hex(value), hex(vtable), slot)
        how = 'Mouse RefPropDescriptor RTTI vtable slot %d' % slot
    elif symbol in EXTERNAL_SLOTS and not own:
        assert EXTERNAL_SLOTS[symbol] == value, (symbol, hex(value))
        how = 'slot of another class vtable (bound by RTTI)'
    elif len({w for _, w in occurrences[symbol]}) > 1:
        how = 'same address at %d places' % len({w for _, w in occurrences[symbol]})
    else:
        UNBOUND.append('%s: unverified external slot %s -> %s (%s)' % (build, symbol, hex(value), where))
        continue
    SLOT_CHECK['%s | %s' % (where, symbol)] = '%s (%s)' % (hex(value), how)

if VERBOSE:
    for r in sorted(mouse.rows.values(), key=lambda r: r['address']):
        print('%s %s %4d/%4d %s %s' % (r['address'], 'EXACT' if r['exact'] else '-----', r['size'], r['target_size'],
                                       r['symbol'][:150], r.get('bounds_status', '')))
    for r in pending_build.rows.values():
        print('pending %s %s %s' % (r['address'], r['exact'], r['symbol'][:150]))
assert not UNBOUND, '\n'.join(sorted(set(UNBOUND)))

REQUIRED = [0x5ff3b0, 0x5ff600, 0x5fe7f0, 0x64e660, 0x64df60, 0x64e050, 0x64e1a0, 0x64e020, 0x7f8c40, 0x7f8f30]
for address in REQUIRED:
    hits = [r for k, r in mouse.rows.items() if (k if isinstance(k, int) else k[0]) == address]
    assert hits and all(r['exact'] for r in hits), (hex(address), hits)
pending_rows = []
for row in pending_build.rows.values():
    main = [r for r in mouse.rows.values() if r['address'] == row['address'] and r['symbol'] == row['symbol'] and r['exact']]
    if main:
        continue   # also exact in the main build: counted there
    row['exact_pending_build_only'] = row['exact']
    row['exact'] = False
    pending_rows.append(dict(row, build=pending_build.name))

main_rows = list(mouse.rows.values())
# Counted: exact rows with a Mouse symbol inside the original Mouse stretch (bodies + descriptor instances), its
# initializers and atexit rows, the Tool unit (where the original emits the Mouse class-template instances: constructor
# chain, classDescriptor, doDeclare, getClassName, shared_ptr<Mouse>, ~Mouse, create<Mouse>) and the Mouse inline
# members emitted in the ScriptMouseCommand unit (checkActive 00642f10, getIcon 00642f80). Everything else is an
# exact support row, not counted: ICF-shared generic bodies reached through Mouse vtables or descriptors (thunks and
# deleting destructors shared by every NonFactoryProduct<Instance, N>, GetSet bodies, reflection/boost templates).
UNIT_RANGES = ((0x64df60, 0x64e840), (0x7f8c40, 0x7f8f70), (0x8010c0, 0x801400), (0x5fd300, 0x600600),
               (0x642f10, 0x642fc0), (0x800040, 0x800050))


def counts(address):
    a = int(address, 16)
    syms = [r['symbol'] for r in main_rows if r['address'] == address and r['exact']]
    if not syms or not all(r['exact'] for r in main_rows if r['address'] == address):
        return False
    return any(lo <= a < hi for lo, hi in UNIT_RANGES) and any(OWN.search(x) for x in syms)


counted = sorted({r['address'] for r in main_rows if counts(r['address'])})
# second halves of two-row bodies (catch funclets) count with their first half
counted = sorted(set(counted) | {f for r in main_rows if r['address'] in counted
                                 for f in [r.get('bounds_status', '').split(' + ')[-1][:8]] if r.get('bounds_status', '').startswith('two contiguous')})
support = sorted({r['address'] for r in main_rows if r['exact']} - set(counted))
inexact = list({(r['address'], r['symbol']): r for r in main_rows if not r['exact']}.values())
sha = nb.sha
paths = [Path(__file__).resolve(), LAYOUT, SRC, HDR]
receipt = {
    'class': 'RBX::Mouse',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': {'layout': layout_flags, 'mouse': main_flags, 'mouse_pending': pend_flags},
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in (layout_obj, main_obj, pend_obj)},
    'layout': {k: hex(v) for k, v in LAYOUT_VALUES.items()},
    'exact_function_rows': counted,
    'exact_support_rows': support,
    'rows': main_rows,
    'not_exact_rows': [{'address': r['address'], 'symbol': r['symbol'], 'size': r['size'],
                        'target_size': r['target_size']} for r in inexact],
    'pending_rows': pending_rows,
    'vtables': mouse.vtables,
    'external_slots': SLOT_CHECK,
    'shared_header_gaps': HEADER_GAPS + HEADER_NOTES,
    'non_exact_reasons': NON_EXACT_REASONS,
    'pending_note': 'comparison-build pending-only rows remain excluded; comparison-build vtables are not walked.',
    'proposals': [],
    'not_attempted': NOT_ATTEMPTED,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/mouse-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native Mouse: %d distinct class addresses exact (+%d support rows), %d compiled rows not exact, '
      '%d pending-build-only rows not counted; %d vtables walked'
      % (len(counted), len(support), len(inexact), sum(1 for r in pending_rows if r.get('exact_pending_build_only')),
         len(receipt['vtables'])))
