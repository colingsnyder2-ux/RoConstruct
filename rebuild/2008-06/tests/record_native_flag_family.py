"""Verify the inactive native RBX::FlagStand and RBX::Flag recovery (2008-06).

Builds (document-swap flags, VS2008 RTM 21022):
  * tests/NativeFlagFamilyLayout.cpp   layout probes (mov eax, imm32; ret);
  * native-classes/FlagStand.cpp       the FlagStand half of the original FlagStand/FlagStandService unit
                                       (0062b8f0..0062cf40, initializers 007f7e90/007f7ef0, atexit 00800450/00800470)
                                       plus the template instances whose original bodies live elsewhere (COMDAT / ICF);
  * native-classes/Flag.cpp                 the Flag unit (00618380..00619a60, initializer 007f7cc0, atexit 00800310)
                                       against the native v8datamodel/Tool.h / Hopper.h (Tool and BackpackItem are
                                       recovered and verified by tests/record_native_hopper.py). Flag rows count as
                                       exact, and the Flag vtables are compared slot by slot from this object.

Every exact row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified: imports by DLL export name, string literals by bytes, type descriptors and
vtables by original RTTI names, own symbols by the row proven here, ICF folds by the FOLDED map, and the remaining
externals by the EXTERNAL / DATA maps (call sites read in the original disassembly). A symbol binds to one address
across all rows. Adjustor thunk rows are derived from the original bytes (`sub ecx, imm; jmp target`): the mangled
adjustment and the jump target must agree with the compiled thunk. FlagStand and Flag vtables are compared slot by
slot from the main-build objects (an inherited slot must equal the Part / Tool vtable of the same subobject, read from
the PartInstance constructor 0059d4d0 / Tool constructor 00600240 stores).

FlagStand rows that depend on PartInstance's layout (constructor, destructor, field accessors, base constructors and
destructor, vtordisp thunks through the FlagStand vbase displacement) are compiled and recorded with exact=false: the
current native PartInstance.h has sizeof 0x2ec where the 2008 PartInstance's non-virtual part is 0x3e8.
Writes work/2008-06/shared-layouts/flag-family-working.json.
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
FS_SRC = R / 'native-classes/FlagStand.cpp'
FLAG_SRC = R / 'native-classes/Flag.cpp'
FS_H = R / 'native-headers/v8datamodel/FlagStand.h'
FLAG_H = R / 'native-headers/v8datamodel/Flag.h'
LAYOUT = R / 'tests/NativeFlagFamilyLayout.cpp'
DONOR = ROOT / 'tools/rbxgs/Client/App/include/v8datamodel'

def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeFlagFamilyLayout', LAYOUT)
fs_obj, fs_flags = build('NativeFlagStand', FS_SRC)
flag_obj, flag_flags = build('NativeFlag', FLAG_SRC)

# ---- layout ---------------------------------------------------------------------------------------------------
raw = layout_obj.read_bytes()
for prefix, value in (('?nativeFlagStandTeamColorAfterConnection@@', 0x14), ('?nativeFlagStandConnectionSize@@', 0x14),
                      ('?nativeFlagStandBrickColorSize@@', 4)):
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    assert body == b'\xb8' + struct.pack('<I', value) + b'\xc3', (prefix, body.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]


def norm(symbol):
    return symbol.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


def enc(n):
    """MSVC mangled unsigned number (thunk adjustments)."""
    if 1 <= n <= 10:
        return str(n - 1)
    return ''.join('ABCDEFGHIJKLMNOP'[int(c, 16)] for c in '%X' % n) + '@'


def thunk(address):
    """(adjustment, jump target) of an original `sub ecx, imm; jmp rel32` adjustor thunk."""
    body, _, _ = match.target('2008-06', '%08x' % address)
    if body[:2] == b'\x83\xe9':
        adj, at = body[2], 3
    else:
        assert body[:2] == b'\x81\xe9', (hex(address), body.hex())
        adj, at = struct.unpack_from('<I', body, 2)[0], 6
    assert body[at] == 0xe9 and len(body) == at + 5, (hex(address), body.hex())
    return adj, (address + at + 5 + struct.unpack_from('<i', body, at + 1)[0]) & 0xffffffff


STR = '?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@'
FPS = '?$FactoryProduct@VFlagStand@RBX@@VPartInstance@2@$1?sFlagStand@2@3PADA@RBX@@'
DCS = '?$DescribedCreatable@VFlagStand@RBX@@VPartInstance@2@$1?sFlagStand@2@3PADA@RBX@@'
DSS = '?$Described@VFlagStand@RBX@@$1?sFlagStand@2@3PADAV' + FPS[:-6] + '@2@@Reflection@RBX@@'
GSS = '?$GetSetImpl@P8FlagStand@RBX@@BE?AVBrickColor@2@XZP812@AEXV32@@Z@?$PropDescriptor@VFlagStand@RBX@@VBrickColor@2@@Reflection@RBX@@'
PDS = '?$PropDescriptor@VFlagStand@RBX@@VBrickColor@2@@Reflection@RBX@@'
SGS = '?$SignalDesc@VFlagStand@RBX@@$$A6AXV?$shared_ptr@VInstance@RBX@@@boost@@@Z@Reflection@RBX@@'
TSD = '?$TSignalDesc@$$A6AXV?$shared_ptr@VInstance@RBX@@@boost@@@Z@Reflection@RBX@@'
FPF = '?$FactoryProduct@VFlag@RBX@@VTool@2@$1?sFlag@2@3QBDB@RBX@@'
DCF = '?$DescribedCreatable@VFlag@RBX@@VTool@2@$1?sFlag@2@3QBDB@RBX@@'
DSF = '?$Described@VFlag@RBX@@$1?sFlag@2@3QBDBV' + FPF[:-6] + '@2@@Reflection@RBX@@'
GSF = '?$GetSetImpl@P8Flag@RBX@@BE?AVBrickColor@2@XZP812@AEXV32@@Z@?$PropDescriptor@VFlag@RBX@@VBrickColor@2@@Reflection@RBX@@'
PDF = '?$PropDescriptor@VFlag@RBX@@VBrickColor@2@@Reflection@RBX@@'

# ---- externals: address the original instruction uses, read at the call sites listed -------------------------
EXTERNAL = {
    '??1Instance@RBX@@UAE@XZ': 0x55a540,
    '?raisePropertyChanged@Instance@RBX@@QAEXABVPropertyDescriptor@Reflection@2@@Z': 0x40db00,   # 0062cdc0 / 00619a60
    '??2@YAPAXI@Z': 0x6a0920, '??3@YAXPAX@Z': 0x6a067a, '_atexit': 0x6a17af,                        # getset 0062be80
    '?declare@Name@RBX@@SAABV12@PBDH@Z': 0x553f90,                                                   # doDeclare 005bf8e0
    '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330,                                                    # getClassName 0062c080
    '??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z': 0x5708f0,                                 # 005c38f0 / 005c3880
    '??1ClassDescriptor@Reflection@RBX@@UAE@XZ': 0x40abc0,                                           # atexit 007fe740
    '?classDescriptor@?$Described@VPartInstance@RBX@@$1?sPart@2@3PADAV?$FactoryProduct@VPartInstance@RBX@@VPVInstance@2@$1?sPart@2@3PADA@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ': 0x59c7f0,
    '??0?$TypedPropertyDescriptor@VBrickColor@RBX@@@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@VBrickColor@RBX@@@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x48b180,
    # SignalDesc<FlagStand, void(shared_ptr<Instance>)> constructor 0062c8f0: SignalDescriptor ctor, Name::declare,
    # signature descriptor / list helpers
    '??0SignalDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD@Z': 0x56bab0,
    '??$singleton@V?$shared_ptr@VInstance@RBX@@@boost@@@Type@Reflection@RBX@@SAABV012@XZ': 0x56cae0,
    '??0Value@Reflection@RBX@@QAE@XZ': 0x594ac0,
    '?_Buynode@?$list@UItem@SignatureDescriptor@Reflection@RBX@@V?$allocator@UItem@SignatureDescriptor@Reflection@RBX@@@std@@@std@@IAEPAU_Node@?$_List_nod@UItem@SignatureDescriptor@Reflection@RBX@@V?$allocator@UItem@SignatureDescriptor@Reflection@RBX@@@std@@@2@PAU342@0ABUItem@SignatureDescriptor@Reflection@RBX@@@Z': 0x417f00,
    '?_Incsize@?$list@UItem@SignatureDescriptor@Reflection@RBX@@V?$allocator@UItem@SignatureDescriptor@Reflection@RBX@@@std@@@std@@IAEXI@Z': 0x682cc0,
    # ~SignalDesc inlined into atexit 00800470 / ??_G 0041bdf0: the signature list destructor
    '??1?$list@UItem@SignatureDescriptor@Reflection@RBX@@V?$allocator@UItem@SignatureDescriptor@Reflection@RBX@@@std@@@std@@QAE@XZ': 0x4199e0,
    # TSignalDesc::newSignalInstance 00499fd0 -> TSignalInstance constructor
    '??0TSignalInstance@' + TSD + 'QAE@PAVSignalSource@23@ABVSignalDescriptor@23@@Z': 0x499cf0,
    # PartInstance virtuals reached through FlagStand's vtordisp thunks 0062cb70 / 0062cb90 / 0062cbd0 / 0062ccc0
    '?onCameraNear@PartInstance@RBX@@UAEXM@Z': 0x59e430,
    '?getLocation@PartInstance@RBX@@UBE?BVCoordinateFrame@G3D@@XZ': 0x59bbf0,
    '?getPrimaryPart@PartInstance@RBX@@UAEPAV12@XZ': 0x59bb10,
    '?getPrimaryPartConst@PartInstance@RBX@@UBEPBV12@XZ': 0x59bb10,   # ICF with getPrimaryPart: vtable 008464b4 = 0062cbd0 twice
    '?getCameraIgnorePrimitives@PartInstance@RBX@@UAEXAAV?$vector@PBVPrimitive@RBX@@V?$allocator@PBVPrimitive@RBX@@@std@@@std@@@Z': 0x59c0d0,
    # FlagStand layout rows (bound only; these rows are not exact)
    '?setName@PartInstance@RBX@@UAEXABV' + STR + '@Z': 0x598c20,
    '??0PartInstance@RBX@@QAE@XZ': 0x59d4d0,
    # Flag: Instance::setName, Tool base constructor/destructor, Tool class descriptor (rows proven exact by
    # tests/record_native_hopper.py)
    '?setName@Instance@RBX@@UAEXABV' + STR + '@Z': 0x55af90,
    '??0Tool@RBX@@QAE@XZ': 0x600240, '??1Tool@RBX@@UAE@XZ': 0x5fe4b0,                               # 00618460 / 006183c0
    '?getLocation@Tool@RBX@@EBE?BVCoordinateFrame@G3D@@XZ': 0x5fd770,                                # thunk 006187f0
    '?classDescriptor@?$Described@VTool@RBX@@$1?sTool@2@3QBDBV?$FactoryProduct@VTool@RBX@@VBackpackItem@2@$1?sTool@2@3QBDB@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ': 0x5c3810,
    '??1scoped_connection@signals@boost@@QAE@XZ': 0x5954b0,                                          # ~Flag 00618670
    '??$callDoDeclare@$1?sFlag@RBX@@3QBDB@Name@RBX@@CAXXZ': 0x5a09b0,                               # getClassName 00618a20
}
# Descriptor objects and class-name arrays: the `this` / pushes the original passes.
DATA_FS = {
    '_prop_Color': 0x97c094, '_event_FlagCaptured': 0x97c060,
    '?sFlagStand@RBX@@3PADA': 0x95be6c,          # "FlagStand" (doDeclare 005bf8e0, classDescriptor 005c38f0)
    '?prop_Color@RBX@@3V?$PropDescriptor@VFlagStand@RBX@@VBrickColor@2@@Reflection@2@A': 0x97c094,   # 007f7e90
    '?event_FlagCaptured@RBX@@3V?$SignalDesc@VFlagStand@RBX@@$$A6AXV?$shared_ptr@VInstance@RBX@@@boost@@@Z@Reflection@2@A': 0x97c060,
    '?prop_Color@PartInstance@RBX@@2V?$PropDescriptor@VPartInstance@RBX@@VColor3@G3D@@@Reflection@2@B': 0x97610c,   # 0062cdc0
}
DATA_FLAG = {
    '_prop_Color': 0x97bf20,
    '?sFlag@RBX@@3QBDB': 0x843c90,               # "Flag" (doDeclare 005a0320, classDescriptor 005c3880)
    '?prop_Color@RBX@@3V?$PropDescriptor@VFlag@RBX@@VBrickColor@2@@Reflection@2@A': 0x97bf20,        # 007f7cc0 / 00619a60
}
for address, text in ((0x95be6c, 'FlagStand'), (0x843c90, 'Flag'), (0x822548, 'TeamColor'), (0x822490, 'Data'),
                      (0x8465f8, 'FlagCaptured'), (0x8439ac, 'Player')):
    assert original.string(address) == text, (hex(address), text)
# ICF / trivial-wrapper folds: the original keeps one body where this unit emits several identical ones.
FOLDED = {
    '??1' + DCS + 'UAE@XZ': 0x62bdb0,             # ??1 Described<FlagStand> 0062bdb0 (jmp ??1 FactoryProduct)
    '??_G' + DCS + 'UAEPAXI@Z': 0x62c800,         # DescribedCreatable vtable 00846344 slot 0 -> FactoryProduct thunks
    '?className@' + FPS + 'SAABVName@2@XZ': 0x5bf8e0,
    '??$declare@$1?sFlagStand@RBX@@3PADA@Name@RBX@@SAABV01@XZ': 0x5bf8e0,
    '??1' + DCF + 'UAE@XZ': 0x618660, '??_G' + DCF + 'UAEPAXI@Z': 0x619800,
    '?className@' + FPF + 'SAABVName@2@XZ': 0x5a0320,
    '??$declare@$1?sFlag@RBX@@3QBDB@Name@RBX@@SAABV01@XZ': 0x5a0320,
    '?canUnequip@Flag@RBX@@MAE_NXZ': 0x60a2f0,    # Flag vtable 00843eb4 slot 35: the ICF-shared `return false` body
}
# Call targets whose own rows are not exact yet (FlagStand layout rows): bound by the address the original uses.
UNPROVEN = {
    '??1FlagStand@RBX@@UAE@XZ': 0x62cc50,
    '??1' + FPS + 'MAE@XZ': 0x62b970,
    '??0' + FPS + 'IAE@XZ': 0x62bc80,
    '??0' + DCS + 'IAE@XZ': 0x62c660,
    '?getTeamColor@FlagStand@RBX@@QBE?AVBrickColor@2@XZ': 0x62b8f0,
    '?setTeamColor@FlagStand@RBX@@QAEXVBrickColor@2@@Z': 0x62cdc0,
    '?onServiceProvider@FlagStand@RBX@@UAEXPBVServiceProvider@2@0@Z': 0x62cf40,   # vtable slot 12; not attempted
    '?onServiceProvider@Flag@RBX@@UAEXPBVServiceProvider@2@0@Z': 0x6194a0,        # Flag vtable 00843eb4 slot 12; not attempted
    '?onChildAdded@Flag@RBX@@UAEXPAVInstance@2@@Z': 0x619970,                     # Flag vtable 00843eb4 slot 7; not attempted
}

FS_ROWS = [
    (0x62c800, '??_G' + FPS + 'MAEPAXI@Z'),
    (0x62cca0, '??_GFlagStand@RBX@@UAEPAXI@Z'),
    (0x62c800, '??_G' + DCS + 'UAEPAXI@Z'),
    (0x62cb70, '?onCameraNear@PartInstance@RBX@@$4PPPPPPPM@BI@AEXM@Z'),
    (0x62cb90, '?getLocation@PartInstance@RBX@@$4PPPPPPPM@BI@'),
    (0x62cbd0, '?getPrimaryPart@PartInstance@RBX@@$4PPPPPPPM@BI@AEPAV12@XZ'),
    (0x62cbd0, '?getPrimaryPartConst@PartInstance@RBX@@$4PPPPPPPM@BI@'),
    (0x62ccc0, '?getCameraIgnorePrimitives@PartInstance@RBX@@$4PPPPPPPM@BI@'),
    (0x62bdb0, '??1' + DSS + 'UAE@XZ'),
    (0x62be80, '??$getset@P8FlagStand@RBX@@BE?AVBrickColor@'),
    (0x62c4c0, '??$?0P8FlagStand@RBX@@BE?AVBrickColor@'),
    (0x62c8f0, '??0' + SGS + 'QAE@PBD0@Z'),
    (0x62c080, '?getClassName@' + FPS + 'UBEABVName@2@XZ'),
    (0x7f7e90, '??__Eprop_Color@RBX@@YAXXZ'),
    (0x7f7ef0, '??__Eevent_FlagCaptured@RBX@@YAXXZ'),
    (0x800450, '??__Fprop_Color@RBX@@YAXXZ'),
    (0x800470, '??__Fevent_FlagCaptured@RBX@@YAXXZ'),
    # template instances whose original bodies live outside the unit (COMDAT / ICF-shared)
    (0x5c38f0, '?classDescriptor@' + DSS + 'SAAAVClassDescriptor@23@XZ'),
    (0x7fe740, '??__Ffoo@?1??classDescriptor@' + DSS),
    (0x5bf8e0, '??$doDeclare@$1?sFlagStand@RBX@@3PADA@Name@RBX@@CAABV01@XZ'),
    (0x5bff90, '??$callDoDeclare@$1?sFlagStand@RBX@@3PADA@Name@RBX@@CAXXZ'),
    (0x5d2130, '?getValue@' + GSS),
    (0x608cd0, '?setValue@' + GSS),
    (0x60a2f0, '?isReadOnly@' + GSS),
    (0x583a00, '??1' + PDS + 'UAE@XZ'),
    (0x598310, '??_G' + PDS + 'UAEPAXI@Z'),
    (0x41bdf0, '??_G' + SGS + 'UAEPAXI@Z'),
    (0x499fd0, '?newSignalInstance@' + TSD + 'EBEPAVSignalInstance@23@AAVSignalSource@23@@Z'),
]
# Adjustor thunks: original addresses; the adjustment and the target come from the original bytes.
FS_THUNKS = {
    ('??_E' + FPS + 'O', 0x62c800): (0x62bb90, 0x62bbd0, 0x62bc00, 0x62bc20, 0x62bc40, 0x62bc50, 0x62bc70, 0x62c7d0,
                                     0x62c7e0, 0x62c7f0),
    ('??_E' + DCS + 'W', 0x62c800): (0x62bb90, 0x62bbd0, 0x62bc00, 0x62bc20, 0x62bc40, 0x62bc50, 0x62bc70, 0x62c7d0,
                                     0x62c7e0, 0x62c7f0),
    ('??_EFlagStand@RBX@@W', 0x62cca0): (0x62cb80, 0x62cbb0, 0x62cbc0, 0x62cbe0, 0x62cbf0, 0x62cc00, 0x62cc10, 0x62cc20,
                                         0x62cc30, 0x62cc40),
}
FLAG_THUNKS = {
    ('??_E' + FPF + 'O', 0x619800): (0x6185e0, 0x6185f0, 0x618600, 0x6197a0, 0x6197b0, 0x6197c0, 0x6197d0, 0x6197e0,
                                     0x6197f0),
    ('??_E' + DCF + 'W', 0x619800): (0x6185e0, 0x6185f0, 0x618600, 0x6197a0, 0x6197b0, 0x6197c0, 0x6197d0, 0x6197e0,
                                     0x6197f0),
    ('??_EFlag@RBX@@W', 0x618980): (0x618790, 0x6187a0, 0x6187b0, 0x6187c0, 0x6187d0, 0x6187e0, 0x618800, 0x618810,
                                    0x618820),
}


def thunk_rows(table):
    rows = []
    for (prefix, target), addresses in table.items():
        for address in addresses:
            adj, to = thunk(address)
            assert to == target, (prefix, hex(address), hex(to), hex(target))
            rows.append((address, prefix + enc(adj) + 'AEPAXI@Z'))
    return rows


FS_ROWS += thunk_rows(FS_THUNKS)
# Compiled, not exact: they depend on the 2008 PartInstance layout (non-virtual size 0x3e8) that the native
# PartInstance.h does not have yet. Recorded with exact=false and the reason.
LAYOUT_ROWS = [
    (0x62b8f0, '?getTeamColor@FlagStand@RBX@@QBE?AVBrickColor@2@XZ', 'reads teamColor +0x3fc'),
    (0x62cdc0, '?setTeamColor@FlagStand@RBX@@QAEXVBrickColor@2@@Z', 'writes teamColor +0x3fc'),
    (0x62c9c0, '??0FlagStand@RBX@@QAE@XZ', 'fields +0x3e8..+0x3fc, vtables and vbase displacements'),
    (0x62cc50, '??1FlagStand@RBX@@UAE@XZ', 'scoped_connection +0x3e8'),
    (0x62b970, '??1' + FPS + 'MAE@XZ', 'stores PartInstance-layout vtables and vbase displacements'),
    (0x62bc80, '??0' + FPS + 'IAE@XZ', 'PartInstance base construction and vtables'),
    (0x62c660, '??0' + DCS + 'IAE@XZ', 'vtables and vbase displacements'),
    (0x62bbe0, '??_E' + FPS + '$2PPPPPPPM@', 'vtordisp thunk: vbase offset 0x3fc'),
    (0x62cba0, '??_EFlagStand@RBX@@$4PPPPPPPM@', 'vtordisp thunk: vbase offset 0x414'),
]
# Flag rows (main build against the native Tool.h / Hopper.h).
FLAG_ROWS = [
    (0x618380, '?getTeamColor@Flag@RBX@@QBE?AVBrickColor@2@XZ'),
    (0x618390, '?canBePickedUpByPlayer@Flag@RBX@@MAE_NPAVPlayer@Network@2@@Z'),
    (0x619a60, '?setTeamColor@Flag@RBX@@QAEXVBrickColor@2@@Z'),
    (0x6183c0, '??1' + FPF + 'MAE@XZ'),
    (0x618460, '??0' + FPF + 'IAE@XZ'),
    (0x6196b0, '??0' + DCF + 'IAE@XZ'),
    (0x619820, '??0Flag@RBX@@QAE@XZ'),
    (0x618670, '??1Flag@RBX@@UAE@XZ'),
    (0x618980, '??_GFlag@RBX@@UAEPAXI@Z'),
    (0x619800, '??_G' + FPF + 'MAEPAXI@Z'),
    (0x618660, '??1' + DSF + 'UAE@XZ'),
    (0x6187f0, '?getLocation@Tool@RBX@@$0PPPPPPPM@CI@'),
    (0x618610, '?getValue@' + GSF),
    (0x6188e0, '??$getset@P8Flag@RBX@@BE?AVBrickColor@'),
    (0x6191c0, '??$?0P8Flag@RBX@@BE?AVBrickColor@'),
    (0x618a20, '?getClassName@' + FPF + 'UBEABVName@2@XZ'),
    (0x5c3880, '?classDescriptor@' + DSF + 'SAAAVClassDescriptor@23@XZ'),
    (0x7fe750, '??__Ffoo@?1??classDescriptor@' + DSF),
    (0x5a0320, '??$doDeclare@$1?sFlag@RBX@@3QBDB@Name@RBX@@CAABV01@XZ'),
    (0x7f7cc0, '??__Eprop_Color@RBX@@YAXXZ'),
    (0x800310, '??__Fprop_Color@RBX@@YAXXZ'),
] + thunk_rows(FLAG_THUNKS)
NOT_ATTEMPTED = {
    '0062b900': 'FlagStand::GetFlag: Primitive embedded at PartInstance +0x228 (getFirstRigid 005e7c80 / getNextRigid '
                '005e7ca0), PartInstance::fromPrimitive 00599f80, Instance parent +0x104, dynamic_cast<Flag*>; needs the '
                '2008 PartInstance layout and a complete Flag (native Tool.h)',
    '0062bdc0': 'FlagStand::AffixFlag: Tool::getHandle 005fd760 (native Tool.h), PartInstance setters; vbase call through +0x134',
    '0062cde0': 'FlagStand::onEvent_standTouched (bound by onServiceProvider)',
    '0062cf40': 'FlagStand::onServiceProvider: ServiceProvider::create<FlagStandService> 00619360 (Flag unit), '
                'SignalDesc::connect with the 2008 third argument, scoped_connection +0x3e8',
    '0062bb30/0062bee0': 'boost::function functor manager for the onEvent_standTouched bind (type_info 0095bf40)',
    '0062c590': 'boost::signal1<void(shared_ptr<Instance>)> constructor instance (195 bytes; this unit emits 201)',
    '00618520/00618650': 'Flag unit: a ClassDescriptor singleton getter (00572690) and its jmp wrapper',
    '00618580/00618830..00618ec0/00618f70/00619080/00619290/00619360/00619450/006194a0/006195b0/00619970':
        'Flag::doUglyPeriodicCloneHack, onServiceProvider, onChildAdded, onEvent_flagTouched and their boost::bind / '
        'boost::function / ServiceProvider::create<FlagStandService/TimerService> plumbing: not attempted',
}

LOCAL_EH = nb.LOCAL_EH
DATA = [DATA_FS]   # the build being verified (the Flag build has its own static prop_Color)
UNBOUND = []
binding = {}   # symbol -> (address, row) for the one-address-per-symbol check


def resolve(obj, rows):
    raw = Path(obj).read_bytes()
    funcs = match.coff_functions(raw)
    out = []
    for row in rows:
        address, key = row[0], row[1]
        hits = [x for x in funcs if x[0] == key] or [x for x in funcs if x[0].startswith(key) and not LOCAL_EH.match(x[0])]
        assert len(hits) == 1, (hex(address), key, [h[0] for h in hits])
        out.append((address, hits[0][0]))
    return out


def classify(symbol, value, own, raw, sections, definitions, where):
    """Return how a relocation target bound to `value` is verified, or None when unknown."""
    hit = original.imported(value)
    if hit is not None:
        assert hit[1] == nb.plain(symbol), (where, symbol, hex(value), hit)
        return '%s!%s' % hit
    if symbol.startswith('??_C@'):
        pos, at = definitions[symbol]
        literal = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
        assert original.data(value, len(literal)) == literal, (where, symbol, hex(value))
        return 'literal %r' % literal[:-1].decode()
    if symbol.startswith('??_R0') and symbol.endswith('@8'):
        rtti = original.string(value + 8)
        assert norm(rtti) == norm('.' + symbol[5:-2]), (where, symbol, hex(value), rtti)
        return 'RTTI %s' % rtti
    if symbol.startswith('??_7'):
        rtti, at = original.vtable_class(value)
        cls = symbol[4:symbol.index('@@6B') + 2]
        assert norm(rtti) == norm('.?AV' + cls), (where, symbol, hex(value), rtti)
        return 'vtable RTTI %s offset %#x' % (rtti, at)
    if symbol.startswith('??_8'):
        return 'vbtable (bound by consistency)'
    if symbol in own:
        assert own[symbol] == value, (where, symbol, hex(value), hex(own[symbol]))
        return 'own row'
    if symbol.startswith('??_E') and ('??_G' + symbol[4:]) in own:
        assert own['??_G' + symbol[4:]] == value, (where, symbol, hex(value))
        return 'own row (??_G)'
    if symbol.startswith('??_E') and ('??_G' + symbol[4:]) in FOLDED:
        assert FOLDED['??_G' + symbol[4:]] == value, (where, symbol, hex(value))
        return 'folded (??_G)'
    if symbol in FOLDED:
        assert FOLDED[symbol] == value, (where, symbol, hex(value))
        return 'folded'
    if symbol in DATA[0]:
        assert DATA[0][symbol] == value, (where, symbol, hex(value))
        return 'data'
    if symbol in EXTERNAL:
        assert EXTERNAL[symbol] == value, (where, symbol, hex(value), hex(EXTERNAL[symbol]))
        return 'external' + (' (evidence name)' if norm(names.get(value, '')) == norm(symbol) else '')
    if symbol in UNPROVEN:
        assert UNPROVEN[symbol] == value, (where, symbol, hex(value))
        return 'call target of a non-exact row'
    if symbol.startswith('??_B?1??') or symbol.startswith('?$S') or '?$TSS' in symbol or symbol.startswith('?flag@') \
            or symbol.startswith('?foo@') or symbol.startswith('?root@') or symbol.startswith('?n@?1???$doDeclare@'):
        return 'local static'
    return None


def verify(obj, rows, own, strict=True, group=''):
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
            assert not strict, (group, name, hex(address), len(body), len(target))
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
            how = classify(symbol, value, own, raw, sections, definitions, name)
            if how is None:
                UNBOUND.append('%s: %s in %s -> %s' % (group, symbol, name, hex(value)))
                continue
            key = (group == 'flag', symbol)   # the Flag build binds in its own namespace (same-named statics)
            prev = binding.setdefault(key, (value, name))
            assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
            verified[symbol] = '%s (%s)' % (hex(value), how)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local)})
        result.append(entry)
    return result


fs_rows = resolve(fs_obj, FS_ROWS)
layout_rows = resolve(fs_obj, LAYOUT_ROWS)
flag_rows = resolve(flag_obj, FLAG_ROWS)
own_fs, own_flag = {}, {}
for address, name in fs_rows:
    own_fs.setdefault(name, address)
for address, name in flag_rows:
    own_flag.setdefault(name, address)
fs_out = verify(fs_obj, fs_rows, own_fs, group='flagstand')
layout_out = verify(fs_obj, layout_rows, own_fs, strict=False, group='flagstand-layout')
for row, (_, _, why) in zip(layout_out, LAYOUT_ROWS):
    if row['exact']:   # would need re-review: these depend on the PartInstance layout
        raise AssertionError('layout-dependent row unexpectedly exact: %s' % row['address'])
    row['reason'] = 'needs the 2008 PartInstance layout: ' + why
DATA[0] = DATA_FLAG
flag_out = verify(flag_obj, flag_rows, own_flag, group='flag')
assert not UNBOUND, '\n'.join(UNBOUND)
DATA[0] = DATA_FS

# ---- FlagStand vtables of the main build, slot by slot ---------------------------------------------------------
# PartInstance's own vtables by subobject offset (PartInstance constructor 0059d4d0 stores them): an inherited slot
# must hold the same address as the Part vtable of the same subobject. Read from the constructor's stores.
CLASSES = ('FlagStand@RBX@@', FPS, DCS)
# The primary FlagStand vtable is stored only by the (layout-blocked) constructor 0062c9c0: bind it by RTTI here.
PRIMARY = '??_7FlagStand@RBX@@6B?$GuidItem@VInstance@RBX@@@1@@'
assert original.vtable_class(0x84657c) == ('.?AVFlagStand@RBX@@', 0)
binding.setdefault((False, PRIMARY), (0x84657c, 'RTTI .?AVFlagStand@RBX@@ offset 0 (constructor 0062c9c0)'))
# Secondary vtables at fixed subobject offsets: pair the compiled constructor's `mov [esi+disp], offset ??_7...` stores
# with the original constructor 0062c9c0's stores at the same displacement (offsets below the PartInstance size the
# native header gets right; vbase-relative stores are skipped). Each pairing is RTTI-checked by classify below.
import capstone  # noqa: E402
_md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
_md.detail = True


def _stores(body):
    out = {}
    for ins in _md.disasm(body, 0):
        if ins.mnemonic == 'mov' and len(ins.operands) == 2 and ins.operands[0].type == capstone.x86.X86_OP_MEM \
                and ins.operands[1].type == capstone.x86.X86_OP_IMM and ins.operands[0].mem.index == 0 \
                and ins.size >= 6:
            out[ins.operands[0].mem.disp] = ins.address + ins.size - 4
    return out


part_body, _, _ = match.target('2008-06', '0059d4d0')
PART_VTABLES = {}
for disp, at in _stores(part_body).items():
    imm = struct.unpack_from('<I', part_body, at)[0]
    try:
        cls, sub = original.vtable_class(imm)
    except Exception:
        continue
    if cls == '.?AVPartInstance@RBX@@' and sub == disp:
        PART_VTABLES[disp] = imm
assert original.vtable_class(0x832d4c) == ('.?AVPartInstance@RBX@@', 0)
PART_VTABLES.setdefault(0, 0x832d4c)   # primary Part vtable (stored through a register in 0059d4d0)
for _at, _vt in ((0x1a0, 0x832cb0), (0x1c0, 0x832ca4)):   # also referenced by 0059d4d0 (register-relative stores)
    assert original.vtable_class(_vt) == ('.?AVPartInstance@RBX@@', _at), hex(_vt)
    PART_VTABLES.setdefault(_at, _vt)
_raw = fs_obj.read_bytes()
_sec, _sym, _defs, _ = match._coff_data_index(_raw)
_ctor = next(n for n, b, r in match.coff_functions(_raw) if n == '??0FlagStand@RBX@@QAE@XZ')
_cbody = {n: b for n, b, r in match.coff_functions(_raw)}[_ctor]
_start, _s = _defs[_ctor]
_rel = {}
for i in range(_sec[_s][7]):
    off, idx, kind = struct.unpack_from('<IIH', _raw, _sec[_s][5] + 10 * i)
    _rel[off - _start] = _sym[idx][0]
_obody, _, _ = match.target('2008-06', '0062c9c0')
_ost = _stores(_obody)
for disp, at in _stores(_cbody).items():
    vsym = _rel.get(at, '')
    if not vsym.startswith('??_7FlagStand@RBX@@') or disp not in _ost or disp >= 0x3e8:
        continue
    value = struct.unpack_from('<I', _obody, _ost[disp])[0]
    assert original.vtable_class(value) == ('.?AVFlagStand@RBX@@', disp), (vsym, hex(disp), hex(value))
    binding.setdefault((False, vsym), (value, 'constructor 0062c9c0 store at +%#x' % disp))
vtables = {}
HEADER_GAPS = []


def check_vtables(obj, pend, classes, own, base_vtables, base_label, own_class):
    """Compare every bound vtable of `classes` from `obj` slot by slot with the original. An inherited slot may hold a
    compiled base symbol bound elsewhere only when it equals the base class vtable of the same subobject."""
    raw = obj.read_bytes()
    sections, symbols, definitions, starts = match._coff_data_index(raw)
    for (p, symbol), (vt, _) in sorted(binding.items()):
        if p != pend or not symbol.startswith('??_7') or not any(symbol[4:].startswith(c + '6B') for c in classes):
            continue
        rtti, at = original.vtable_class(vt)
        value, sec = definitions[symbol]
        table = sections[sec]
        end = min([x for x in starts[sec + 1] if x > value] + [table[3]])
        slots = {}
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
            if value <= offset < end:
                slots[(offset - value) // 4] = symbols[index][0]
        assert slots and max(slots) == len(slots) - 1, (symbol, sorted(slots))
        checked = {}
        for slot, sym in sorted(slots.items()):
            value_orig = d(vt + 4 * slot)
            inherited = at in base_vtables and d(base_vtables[at] + 4 * slot) == value_orig and own_class not in sym
            gap = None
            try:
                how = classify(sym, value_orig, own, raw, sections, definitions, symbol)
            except AssertionError as e:   # compiled base symbol bound elsewhere: only an inherited slot may differ
                how, gap = None, str(e.args[0][-1]) if e.args and isinstance(e.args[0], tuple) else str(e)
            if gap is not None:
                assert inherited, (symbol, slot, sym, hex(value_orig), gap)
                HEADER_GAPS.append('%s slot %d: compiled %s, original %s = %s vtable %#x slot %d (the native base header '
                                   'lacks the override)' % (symbol, slot, sym, hex(value_orig), base_label,
                                                            base_vtables[at], slot))
                how = 'inherited (%s vtable %#x slot %d; header gap, see receipt)' % (base_label, base_vtables[at], slot)
                checked[slot] = '%s = %s (%s)' % (sym, hex(value_orig), how)
                continue
            if how is None and inherited:
                how = 'inherited (%s vtable %#x slot %d)' % (base_label, base_vtables[at], slot)
            if how is None and norm(names.get(value_orig, '')) == norm(sym):
                how = 'evidence name'
            if how is None:
                UNBOUND.append('vtable %s slot %d %s -> %s' % (symbol, slot, sym, hex(value_orig)))
                continue
            prev = binding.setdefault((pend, sym), (value_orig, symbol))
            assert prev[0] == value_orig, ('inconsistent', sym, hex(prev[0]), prev[1], hex(value_orig), symbol)
            checked[slot] = '%s = %s (%s)' % (sym, hex(value_orig), how)
        vtables[symbol] = {'address': hex(vt), 'rtti': rtti, 'offset': hex(at), 'slots': checked}


check_vtables(fs_obj, False, CLASSES, own_fs, PART_VTABLES, 'Part', 'FlagStand@RBX@@')
# Flag: Tool's own vtables by subobject offset, read from the Tool constructor 00600240's stores (RTTI-checked).
tool_body, _, _ = match.target('2008-06', '00600240')
TOOL_VTABLES = {}
for disp, at in _stores(tool_body).items():
    imm = struct.unpack_from('<I', tool_body, at)[0]
    try:
        cls, sub = original.vtable_class(imm)
    except Exception:
        continue
    if cls == '.?AVTool@RBX@@' and sub == disp:
        TOOL_VTABLES[disp] = imm
assert TOOL_VTABLES.get(0x1b0) == 0x8419a4, TOOL_VTABLES
for _at, _vt in ((0, 0x841a4c), (0x1a0, 0x8419bc)):   # 006002a4 `mov [esi], imm` / 006002fc `mov [edi], imm` (edi = esi + 0x1a0)
    assert original.vtable_class(_vt) == ('.?AVTool@RBX@@', _at), hex(_vt)
    TOOL_VTABLES.setdefault(_at, _vt)
DATA[0] = DATA_FLAG
check_vtables(flag_obj, True, ('Flag@RBX@@', FPF, DCF), own_flag, TOOL_VTABLES, 'Tool', 'Flag@RBX@@')
DATA[0] = DATA_FS
assert not UNBOUND, '\n'.join(UNBOUND)
flag_vt = [v for v in vtables.values() if v['address'] == hex(0x843eb4)]
assert flag_vt and flag_vt[0]['rtti'] == '.?AVFlag@RBX@@', flag_vt
main_vt = [v for v in vtables.values() if v['address'] == hex(0x84657c)]
assert main_vt and len(main_vt[0]['slots']) == 26, main_vt
assert main_vt[0]['slots'][12].startswith('?onServiceProvider@FlagStand@RBX@@') and '0x62cf40' in main_vt[0]['slots'][12]

# ---- allocation sizes and RTTI bases ---------------------------------------------------------------------------
for factory, size, ctor in ((0x5c1040, 0x41c, 0x62c9c0), (0x5a31b0, 0x298, 0x619820)):
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


assert original.vtable_class(0x84657c) == ('.?AVFlagStand@RBX@@', 0)
assert original.vtable_class(0x843eb4) == ('.?AVFlag@RBX@@', 0)
fb = bases(0x84657c)
assert '.?AV?$DescribedCreatable@VFlagStand@RBX@@VPartInstance@2@$1?sFlagStand@2@3PADA@RBX@@' in fb, fb
assert '.?AVPartInstance@RBX@@' in fb
gb = bases(0x843eb4)
assert '.?AV?$DescribedCreatable@VFlag@RBX@@VTool@2@$1?sFlag@2@3QBDB@RBX@@' in gb, gb
assert gb['.?AVTool@RBX@@'] == 0 and gb['.?AVBackpackItem@RBX@@'] == 0 and gb['.?AVWidget@RBX@@'] == 0
assert gb['.?AVGuiTarget@RBX@@'] == 0x130 and gb['.?AVIEquipable@RBX@@'] == 0x1a0 and gb['.?AVIRenderable@RBX@@'] == 0x1b0

sha = nb.sha
paths = [Path(__file__).resolve(), FS_H, FLAG_H, FS_SRC, FLAG_SRC, LAYOUT]
exact = sorted({r['address'] for r in fs_out + flag_out if r['exact']})
flag_exact = sorted({r['address'] for r in flag_out if r['exact']})
receipt = {
    'class': 'RBX::FlagStand, RBX::Flag', 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': {'layout': layout_flags, 'flagstand': fs_flags, 'flag': flag_flags},
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in (layout_obj, fs_obj, flag_obj)},
    'layout': {'FlagStand': '0x41c (005c1040); PartInstance non-virtual part to +0x3e8, scoped_connection standTouched '
                            '+0x3e8, teamColor +0x3fc, virtual bases from +0x400',
               'Flag': '0x298 (005a31b0); Tool non-virtual part to +0x268, evilClone +0x268, (donor state +0x270), '
                       'scoped_connection flagTouched +0x274, timer +0x288, teamColor +0x28c, vtordisp +0x290, '
                       'virtual bases from +0x294'},
    'rows': {'flagstand': fs_out, 'flagstand_layout_blocked': layout_out, 'flag': flag_out},
    'exact_function_rows': exact,
    'vtables': vtables,
    'flag_note': 'Flag rows are built against the native v8datamodel/Tool.h / Hopper.h (no pending overlay); the Flag '
                 'vtables are slot-checked from that object, inherited slots against the Tool constructor 00600240 '
                 'vtables.',
    'layout_blocked_note': 'flagstand_layout_blocked rows compile to the original sizes but need native PartInstance.h '
                           'with the 2008 non-virtual size 0x3e8 (currently sizeof 0x2ec including virtual bases).',
    'not_attempted': NOT_ATTEMPTED,
    'vtable_header_gaps': HEADER_GAPS,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/flag-family-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native FlagStand/Flag: %d FlagStand + %d Flag rows exact (%d distinct addresses, %d of them Flag); %d '
      'layout-blocked rows not counted; %d vtables checked'
      % (len(fs_out), len(flag_out), len(exact), len(flag_exact), len(layout_out), len(vtables)))
