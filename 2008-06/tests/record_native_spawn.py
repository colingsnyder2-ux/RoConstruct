"""Verify the inactive native RBX::TimerService, RBX::SpawnerService and RBX::SpawnLocation recovery (2008-06).

Builds (document-swap flags, VS2008 RTM 21022), all from the current native headers unless noted:
  * tests/NativeSpawnLayout.cpp        sizeof/offset probes (mov eax, imm32; ret);
  * native-classes/TimerService.cpp    the whole Timer unit 005d6960..005d73a0 (+ list ctor 0055e590, class descriptor
                                       005c0710, doDeclare 0048a250 / callDoDeclare 0048ab50, atexit 007fe6b0). The
                                       3-argument _Buynode and onEvent bodies each span two rows of the function list
                                       (the catch funclets 005d6c61 / 005d700f start a row of their own): they are
                                       compared against the concatenation of both rows, which are contiguous;
  * native-classes/SpawnLocation.cpp   the SpawnLocation/SpawnerService unit without the SpawnerService constructor;
  * SpawnLocation.cpp with NATIVE_SPAWN_PENDING against generated headers in out/native-layouts/spawn-pending/
    (copies of native-headers/v8tree/Instance.h with Instance::propArchivable and of the donor reflection/property.h
    with the 2008 second GetSet bool virtual; PROPOSAL_* below): SpawnerService::SpawnerService 005d30c0. Rows exact
    only in this build are recorded exact=false (pending-build-only) and not counted.

Every exact row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified: imports by DLL export name, string literals by bytes, type descriptors and
vtables by original RTTI names, own symbols by the row proven here, folded bodies by their address, and the remaining
externals by the explicit EXTERNAL / DATA maps (call sites read in the original disassembly). A symbol binds to one
address across all rows. Vtables are compared slot by slot from the objects built with the current headers.

SpawnLocation rows that depend on PartInstance's layout (constructor, destructor, field accessors, base constructors
and destructor, property initializers, vtordisp thunks) are compiled and recorded with exact=false: the current
native PartInstance.h has sizeof 0x2ec where the 2008 PartInstance's non-virtual part is 0x3e8 (the bodies have the
original sizes; only field and base offsets differ). Writes work/2008-06/shared-layouts/spawn-working.json.
"""
import json
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
TIMER_SRC = R / 'native-classes/TimerService.cpp'
SPAWN_SRC = R / 'native-classes/SpawnLocation.cpp'
TIMER_H = R / 'native-headers/v8datamodel/TimerService.h'
SPAWNER_H = R / 'native-headers/v8datamodel/SpawnerService.h'
SPAWN_H = R / 'native-headers/v8datamodel/SpawnLocation.h'
LAYOUT = R / 'tests/NativeSpawnLayout.cpp'

# Proposed declarations for shared headers (not edited here; generated copies for the pending build only).
PROPOSAL_INSTANCE_ANCHOR = '    static Reflection::SignalDesc<Instance, void(boost::shared_ptr<Instance>)> event_ancestryChanged;\n'
PROPOSAL_INSTANCE = '    static Reflection::BoundProp<bool, 1> propArchivable; // 00973e74 (initializer 007f28e0, member +0x12c)\n'
PROPOSAL_PROPERTY_ANCHOR = '\t\t\t\tvirtual bool isReadOnly() const = 0;\n'
PROPOSAL_PROPERTY = '\t\t\t\tvirtual bool isWriteOnly() const { return false; } // proposal: slot 1 (0060a2f0)\n'

pending = OUT / 'spawn-pending'
for sub in ('v8tree', 'reflection'):
    (pending / sub).mkdir(parents=True, exist_ok=True)
text = (R / 'native-headers/v8tree/Instance.h').read_text()
assert text.count('static Reflection::BoundProp<bool, 1> propArchivable;') == 1
(pending / 'v8tree/Instance.h').write_text(text)
text = (R / 'native-headers/reflection/property.h').read_text()
getset = text.split('class GetSet\n', 1)[1].split('};', 1)[0]
assert getset.count('virtual bool isWriteOnly() const = 0;') == 1
(pending / 'reflection/property.h').write_text(text)


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeSpawnLayout', LAYOUT)
timer_obj, timer_flags = build('NativeTimerService', TIMER_SRC)
spawn_obj, spawn_flags = build('NativeSpawnLocation', SPAWN_SRC)
pend_obj, pend_flags = build('NativeSpawnLocationPending', SPAWN_SRC, ['/I' + str(pending), '/DNATIVE_SPAWN_PENDING'])

# ---- layout ---------------------------------------------------------------------------------------
raw = layout_obj.read_bytes()
for prefix, value in (('?nativeTimerServiceSize@@', 0x158), ('?nativeSpawnerServiceSize@@', 0x14c),
                      ('?nativeSpawnInstanceSize@@', 0x130)):
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    assert body == b'\xb8' + struct.pack('<I', value) + b'\xc3', (prefix, body.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}


def norm(symbol):
    return symbol.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


STR = '?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@'
# ---- externals: address the original instruction uses, read at the call sites listed ----------------
EXTERNAL = {
    '??0Instance@RBX@@QAE@XZ': 0x55b7e0, '??1Instance@RBX@@UAE@XZ': 0x55a540,
    '?setName@Instance@RBX@@UAEXABV' + STR + '@Z': 0x55af90,
    '?raisePropertyChanged@Instance@RBX@@QAEXABVPropertyDescriptor@Reflection@2@@Z': 0x40db00,
    '??2@YAPAXI@Z': 0x6a0920, '??3@YAXPAX@Z': 0x6a067a, '_atexit': 0x6a17af,
    '?declare@Name@RBX@@SAABV12@PBDH@Z': 0x553f90,
    '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330,
    '??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z': 0x5708f0,
    '??1ClassDescriptor@Reflection@RBX@@UAE@XZ': 0x40abc0,
    '?classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3QBDBVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ': 0x40ad80,
    '?classDescriptor@?$Described@VPartInstance@RBX@@$1?sPart@2@3PADAV?$FactoryProduct@VPartInstance@RBX@@VPVInstance@2@$1?sPart@2@3PADA@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ': 0x59c7f0,
    # TypedPropertyDescriptor<T> constructors called by the BoundProp / PropDescriptor ctors 005d27d0 / 005d28b0 / 005d2990
    '??0?$TypedPropertyDescriptor@H@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@H@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x4432a0,
    '??0?$TypedPropertyDescriptor@_N@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@_N@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x40a290,
    '??0?$TypedPropertyDescriptor@VBrickColor@RBX@@@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@VBrickColor@RBX@@@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x48b180,
    # Timer unit: G3D time, StandardOut, boost::function, RunService notifier helpers (call sites in 005d6e10, 005d6f70,
    # 005d700f, 005d73a0, 005d71b0, 005d72f0)
    '?getLocalTime@System@G3D@@SANXZ': 0x508410,
    '?singleton@StandardOut@RBX@@SA?AV?$shared_ptr@VStandardOut@RBX@@@boost@@XZ': 0x569620,
    '?print@StandardOut@RBX@@QAEXW4MessageType@2@ABVexception@std@@@Z': 0x416e10,
    '??0bad_function_call@boost@@QAE@XZ': 0x409ef0,
    '??$throw_exception@Vbad_function_call@boost@@@boost@@YAXABVbad_function_call@0@@Z': 0x40a500,
    '??4?$function0@XV?$allocator@Vfunction_base@boost@@@std@@@boost@@QAEAAV01@ABV01@@Z': 0x554470,   # delay 005d6e53
    '__TI3?AVlength_error@std@@': 0x8d0cc0,   # _Incsize 005d6ac0 throw; catchable type checked below
    # template instances ICF-shared with other instantiations (evidence names the Instance flavour)
    '??1?$shared_ptr@VStandardOut@RBX@@@boost@@QAE@XZ': 0x600660,
    '??4shared_count@detail@boost@@QAEAAV012@ABV012@@Z': 0x4025b0,
    '?removeListener@?$Notifier@VRunService@RBX@@VHeartbeat@2@@RBX@@QBEXPAV?$Listener@VRunService@RBX@@VHeartbeat@2@@2@@Z': 0x5e5a80,
    '?addListener@?$Notifier@VRunService@RBX@@VHeartbeat@2@@RBX@@QBEXPAV?$Listener@VRunService@RBX@@VHeartbeat@2@@2@@Z': 0x4218a0,
    '??$create@VRunService@RBX@@@ServiceProvider@RBX@@QBEPAVRunService@1@XZ': 0x4530f0,
    '??$shared_from@VRunService@RBX@@@RBX@@YA?AV?$shared_ptr@VRunService@RBX@@@boost@@PAVRunService@0@@Z': 0x618a40,
    # SpawnerService constructor / destructor (005d30c0, 005d2410): list<SpawnLocation*> helpers folded with other lists
    '??0?$list@PAVSpawnLocation@RBX@@V?$allocator@PAVSpawnLocation@RBX@@@std@@@std@@QAE@XZ': 0x61a200,
    '?_Tidy@?$list@PAVSpawnLocation@RBX@@V?$allocator@PAVSpawnLocation@RBX@@@std@@@std@@IAEXXZ': 0x682b40,
    # SpawnLocation (layout-dependent rows only)
    '?setName@PartInstance@RBX@@UAEXABV' + STR + '@Z': 0x598c20,
    '??0PartInstance@RBX@@QAE@XZ': 0x59d4d0,
    # PartInstance virtuals reached through SpawnLocation's vtordisp thunks 005d36b0 / 005d36d0 / 005d3720 / 005d37a0
    '?onCameraNear@PartInstance@RBX@@UAEXM@Z': 0x59e430,
    '?getCameraIgnorePrimitives@PartInstance@RBX@@UAEXAAV?$vector@PBVPrimitive@RBX@@V?$allocator@PBVPrimitive@RBX@@@std@@@std@@@Z': 0x59c0d0,
    '?getLocation@PartInstance@RBX@@UBE?BVCoordinateFrame@G3D@@XZ': 0x59bbf0,      # returns the primitive's CoordinateFrame
    '?getPrimaryPart@PartInstance@RBX@@UAEPAV12@XZ': 0x59bb10,                      # lea eax, [ecx-0x3ec] (IPrimaryPart -> this)
}
# Descriptor objects and class-name arrays: the `this` / pushes the original passes.
DATA = {
    '?sTimerService@RBX@@3PADA': 0x953654,           # "Timer" (doDeclare 0048a250, classDescriptor 005c0710)
    '?sSpawnerService@RBX@@3QBDB': 0x83ba38,         # "SpawnerService" (doDeclare 00489ed0, classDescriptor 005c07f0)
    '?sSpawnLocation@RBX@@3PADA': 0x9525cc,          # "SpawnLocation" (doDeclare 00489e60)
    '?prop_Duration@SpawnLocation@RBX@@2V?$BoundProp@H$00@Reflection@2@A': 0x979ea8,
    '?prop_Neutral@SpawnLocation@RBX@@2V?$BoundProp@_N$00@Reflection@2@A': 0x979e8c,
    '?prop_AllowTeamChangeOnTouch@SpawnLocation@RBX@@2V?$BoundProp@_N$00@Reflection@2@A': 0x979e70,
    '?prop_TeamColor@RBX@@3V?$PropDescriptor@VSpawnLocation@RBX@@VBrickColor@2@@Reflection@2@A': 0x979ec4,
    '_prop_TeamColor': 0x979ec4,
    '?propArchivable@Instance@RBX@@2V?$BoundProp@_N$00@Reflection@2@A': 0x973e74,   # initializer 007f28e0
}
# Data the binder may only bind by consistency (string data checked below).
for address, text in ((0x953654, 'Timer'), (0x83ba38, 'SpawnerService'), (0x9525cc, 'SpawnLocation')):
    assert original.string(address) == text, (hex(address), text)

FPT = '?$FactoryProduct@VTimerService@RBX@@VInstance@2@$1?sTimerService@2@3PADA@RBX@@'
DCT = '?$DescribedCreatable@VTimerService@RBX@@VInstance@2@$1?sTimerService@2@3PADA@RBX@@'
DST = '?$Described@VTimerService@RBX@@$1?sTimerService@2@3PADAV' + FPT[:-6] + '@2@@Reflection@RBX@@'
LIT = '?$list@VItem@TimerService@RBX@@V?$allocator@VItem@TimerService@RBX@@@std@@@std@@'
FPS = '?$FactoryProduct@VSpawnerService@RBX@@VInstance@2@$1?sSpawnerService@2@3QBDB@RBX@@'
DCS = '?$DescribedCreatable@VSpawnerService@RBX@@VInstance@2@$1?sSpawnerService@2@3QBDB@RBX@@'
DSS = '?$Described@VSpawnerService@RBX@@$1?sSpawnerService@2@3QBDBV' + FPS[:-6] + '@2@@Reflection@RBX@@'
FPL = '?$FactoryProduct@VSpawnLocation@RBX@@VPartInstance@2@$1?sSpawnLocation@2@3PADA@RBX@@'
DCL = '?$DescribedCreatable@VSpawnLocation@RBX@@VPartInstance@2@$1?sSpawnLocation@2@3PADA@RBX@@'
DSL = '?$Described@VSpawnLocation@RBX@@$1?sSpawnLocation@2@3PADAV' + FPL[:-6] + '@2@@Reflection@RBX@@'
BPI = '?$BoundPropGetSet@VSpawnLocation@RBX@@@?$BoundProp@H$00@Reflection@RBX@@'
BPB = '?$BoundPropGetSet@VSpawnLocation@RBX@@@?$BoundProp@_N$00@Reflection@RBX@@'
GSC = '?$GetSetImpl@P8SpawnLocation@RBX@@BE?AVBrickColor@2@XZP812@AEXV32@@Z@?$PropDescriptor@VSpawnLocation@RBX@@VBrickColor@2@@Reflection@RBX@@'

# ICF / trivial-wrapper folds: the original keeps one body where this unit emits several identical ones.
FOLDED = {
    '??1' + DST + 'UAE@XZ': 0x5d6a90, '??1' + DCT + 'UAE@XZ': 0x5d6a90,
    '??_G' + DCT + 'UAEPAXI@Z': 0x5d6a20,
    '??1' + DSS + 'UAE@XZ': 0x5d2250, '??1' + DCS + 'UAE@XZ': 0x5d2250,
    '??_G' + DCS + 'UAEPAXI@Z': 0x5d30a0,
    '??1' + DSL + 'UAE@XZ': 0x5d2240, '??1' + DCL + 'UAE@XZ': 0x5d2240,
    '??_G' + DCL + 'UAEPAXI@Z': 0x5d3380,
    '?className@' + FPT + 'SAABVName@2@XZ': 0x5d6bd0,
    '??$declare@$1?sTimerService@RBX@@3PADA@Name@RBX@@SAABV01@XZ': 0x5d6bd0,
}
# Call targets whose own rows are not exact yet (layout-dependent SpawnLocation bodies): bound by the address the
# original instruction uses; listed separately so they never count as proof.
UNPROVEN = {
    '??1SpawnLocation@RBX@@UAE@XZ': 0x5d3730,
    '??1' + FPL + 'MAE@XZ': 0x5d1bb0,
    '??0' + FPL + 'IAE@XZ': 0x5d1fa0,
    '??0' + DCL + 'IAE@XZ': 0x5d31b0,
    '?getTeamColor@SpawnLocation@RBX@@QBE?AVBrickColor@2@XZ': 0x5d1ba0,
    '?setTeamColor@SpawnLocation@RBX@@QAEXVBrickColor@2@@Z': 0x5d37b0,
    '?onServiceProvider@SpawnLocation@RBX@@MAEXPBVServiceProvider@2@0@Z': 0x5d37d0,   # vtable slot 12; body not attempted
}

# Rows: (address or (contiguous addresses), symbol or unique symbol prefix)
TIMER_ROWS = [
    (0x5d6960, '??1' + FPT + 'MAE@XZ'),
    (0x5d69c0, '??0' + FPT + 'IAE@XZ'),
    (0x5d6a20, '??_G' + FPT + 'MAEPAXI@Z'),
    (0x5d6a40, '??_E' + FPT + 'OME@AEPAXI@Z'), (0x5d6a50, '??_E' + FPT + 'OBA@AEPAXI@Z'),
    (0x5d6a60, '??_E' + FPT + 'OBE@AEPAXI@Z'), (0x5d6a70, '??_E' + FPT + 'OCE@AEPAXI@Z'),
    (0x5d6a80, '??_E' + FPT + 'OGE@AEPAXI@Z'),
    (0x5d6a90, '??1' + DST + 'UAE@XZ'),
    (0x5d6aa0, '?_Buynode@' + LIT + 'IAEPAU_Node@?$_List_nod@VItem@TimerService@RBX@@V?$allocator@VItem@TimerService@RBX@@@std@@@2@XZ'),
    (0x5d6ac0, '?_Incsize@' + LIT),
    (0x5d6b60, '??$_Construct@VItem@TimerService@RBX@@V123@@std@@'),
    (0x5d6bd0, '?getClassName@' + FPT + 'UBEABVName@2@XZ'),
    (0x5d6bf0, '?_Buynode@' + LIT + 'IAEPAU_Node@?$_List_nod@VItem@TimerService@RBX@@V?$allocator@VItem@TimerService@RBX@@@std@@@2@PAU342@0ABVItem@TimerService@RBX@@@Z'),
    (0x5d6c80, '?insert@' + LIT),
    (0x5d6d10, '?erase@' + LIT),
    (0x5d6db0, '?clear@' + LIT),
    (0x5d6e10, '?delay@TimerService@RBX@@'),
    (0x5d6f70, '?onEvent@TimerService@RBX@@MAEXPBVRunService@2@VHeartbeat@2@@Z'),
    (0x5d7080, '??1' + LIT + 'QAE@XZ'),
    (0x5d70e0, '??0' + DCT + 'IAE@XZ'),
    (0x5d7180, '??_E' + FPT + 'OEE@AEPAXI@Z'), (0x5d7190, '??_E' + FPT + 'OIE@AEPAXI@Z'),
    (0x5d71a0, '??_E' + FPT + 'OKE@AEPAXI@Z'),
    (0x5d71b0, '??0TimerService@RBX@@QAE@XZ'),
    (0x5d7260, '??_ETimerService@RBX@@WBE@AEPAXI@Z'), (0x5d7270, '??_ETimerService@RBX@@WBDA@AEPAXI@Z'),
    (0x5d7280, '??_ETimerService@RBX@@WCE@AEPAXI@Z'), (0x5d7290, '??_ETimerService@RBX@@WEE@AEPAXI@Z'),
    (0x5d72a0, '??_ETimerService@RBX@@WGE@AEPAXI@Z'), (0x5d72b0, '??_ETimerService@RBX@@WIE@AEPAXI@Z'),
    (0x5d72c0, '??_ETimerService@RBX@@WKE@AEPAXI@Z'), (0x5d72d0, '??_ETimerService@RBX@@WME@AEPAXI@Z'),
    (0x5d72e0, '??_ETimerService@RBX@@WBA@AEPAXI@Z'),
    (0x5d72f0, '??1TimerService@RBX@@UAE@XZ'),
    (0x5d7380, '??_GTimerService@RBX@@UAEPAXI@Z'),
    (0x5d73a0, '?onServiceProvider@TimerService@RBX@@MAEXPBVServiceProvider@2@0@Z'),
    (0x55e590, '??0' + LIT + 'QAE@XZ'),
    (0x5c0710, '?classDescriptor@' + DST + 'SAAAVClassDescriptor@23@XZ'),
    (0x48a250, '??$doDeclare@$1?sTimerService@RBX@@3PADA@Name@RBX@@CAABV01@XZ'),
    (0x48ab50, '??$callDoDeclare@$1?sTimerService@RBX@@3PADA@Name@RBX@@CAXXZ'),
    (0x7fe6b0, '??__Ffoo@?1??classDescriptor@' + DST),
]
SPAWN_ROWS = [
    (0x5d1cb0, '??1' + FPS + 'MAE@XZ'),
    (0x5d1d10, '??0' + FPS + 'IAE@XZ'),
    (0x5d1e30, '??_E' + FPL + 'OCE@AEPAXI@Z'), (0x5d1e40, '??_E' + FPL + 'OEE@AEPAXI@Z'),
    (0x5d1e50, '??_E' + FPL + 'OGE@AEPAXI@Z'), (0x5d1e60, '??_E' + FPL + 'OME@AEPAXI@Z'),
    (0x5d1e70, '??_E' + FPL + 'OBKA@AEPAXI@Z'),
    (0x5d1e80, '??_E' + FPS + 'OEE@AEPAXI@Z'), (0x5d1e90, '??_E' + FPS + 'OIE@AEPAXI@Z'),
    (0x5d1ea0, '??_E' + FPS + 'OKE@AEPAXI@Z'), (0x5d1eb0, '??_E' + FPS + 'OME@AEPAXI@Z'),
    (0x5d20d0, '?getValue@' + BPI), (0x5d2100, '?getValue@' + BPB),
    (0x5d2130, '?getValue@' + GSC),
    (0x5d2240, '??1' + DSL + 'UAE@XZ'),
    (0x5d2250, '??1' + DSS + 'UAE@XZ'),
    (0x5d2280, '??$getset@P8SpawnLocation@RBX@@BE?AVBrickColor@'),
    (0x5d2370, '?getClassName@' + FPL + 'UBEABVName@2@XZ'),
    (0x5d2390, '?getClassName@' + FPS + 'UBEABVName@2@XZ'),
    (0x5d2410, '??1SpawnerService@RBX@@UAE@XZ'),
    (0x5d2490, '??_ESpawnerService@RBX@@WCE@AEPAXI@Z'), (0x5d24a0, '??_ESpawnerService@RBX@@WEE@AEPAXI@Z'),
    (0x5d24b0, '??_ESpawnerService@RBX@@WGE@AEPAXI@Z'), (0x5d24c0, '??_ESpawnerService@RBX@@WIE@AEPAXI@Z'),
    (0x5d24d0, '??_ESpawnerService@RBX@@WKE@AEPAXI@Z'), (0x5d24e0, '??_ESpawnerService@RBX@@WME@AEPAXI@Z'),
    (0x5d24f0, '??_ESpawnerService@RBX@@WBA@AEPAXI@Z'), (0x5d2500, '??_ESpawnerService@RBX@@WBE@AEPAXI@Z'),
    (0x5d2510, '??_GSpawnerService@RBX@@UAEPAXI@Z'),
    (0x5d2760, '?classDescriptor@' + DSL + 'SAAAVClassDescriptor@23@XZ'),
    (0x5d27d0, '??$?0VSpawnLocation@RBX@@@?$BoundProp@H$00@'),
    (0x5d28b0, '??$?0VSpawnLocation@RBX@@@?$BoundProp@_N$00@'),
    (0x5d2990, '??$?0P8SpawnLocation@RBX@@BE?AVBrickColor@'),
    (0x5d2fc0, '??0' + DCS + 'IAE@XZ'),
    (0x5d3060, '??_E' + FPS + 'OGE@AEPAXI@Z'), (0x5d3070, '??_E' + FPS + 'OBA@AEPAXI@Z'),
    (0x5d3080, '??_E' + FPS + 'OBE@AEPAXI@Z'), (0x5d3090, '??_E' + FPS + 'OCE@AEPAXI@Z'),
    (0x5d30a0, '??_G' + FPS + 'MAEPAXI@Z'),
    (0x5d3320, '??_E' + FPL + 'OIE@AEPAXI@Z'), (0x5d3330, '??_E' + FPL + 'OKE@AEPAXI@Z'),
    (0x5d3340, '??_E' + FPL + 'OBA@AEPAXI@Z'), (0x5d3350, '??_E' + FPL + 'OBE@AEPAXI@Z'),
    (0x5d3360, '??_E' + FPL + 'OBDA@AEPAXI@Z'),
    (0x5d3380, '??_G' + FPL + 'MAEPAXI@Z'),
    (0x5d3650, '??_ESpawnLocation@RBX@@WCE@AEPAXI@Z'), (0x5d3660, '??_ESpawnLocation@RBX@@WEE@AEPAXI@Z'),
    (0x5d3670, '??_ESpawnLocation@RBX@@WGE@AEPAXI@Z'), (0x5d3680, '??_ESpawnLocation@RBX@@WIE@AEPAXI@Z'),
    (0x5d3690, '??_ESpawnLocation@RBX@@WKE@AEPAXI@Z'), (0x5d36a0, '??_ESpawnLocation@RBX@@WME@AEPAXI@Z'),
    (0x5d36c0, '??_ESpawnLocation@RBX@@WBKA@AEPAXI@Z'),
    (0x5d36e0, '??_ESpawnLocation@RBX@@WBA@AEPAXI@Z'), (0x5d36f0, '??_ESpawnLocation@RBX@@WBE@AEPAXI@Z'),
    (0x5d3700, '??_ESpawnLocation@RBX@@WBDA@AEPAXI@Z'),
    (0x5d36b0, '?onCameraNear@PartInstance@RBX@@$4PPPPPPPM@CA@AEXM@Z'),
    (0x5d36d0, '?getLocation@PartInstance@RBX@@$4PPPPPPPM@CA@'),
    (0x5d3720, '?getPrimaryPart@PartInstance@RBX@@$4PPPPPPPM@CA@AEPAV12@XZ'),
    (0x5d3780, '??_GSpawnLocation@RBX@@UAEPAXI@Z'),
    (0x5d37a0, '?getCameraIgnorePrimitives@PartInstance@RBX@@$4PPPPPPPM@CA@'),
    (0x7f5fb0, '??__Eprop_TeamColor@RBX@@YAXXZ'),
    (0x5d3920, '?setValue@' + BPI), (0x5d3990, '?setValue@' + BPB),
    (0x7feff0, '??__F?prop_AllowTeamChangeOnTouch@SpawnLocation@RBX@@'),
    (0x7ff010, '??__F?prop_Neutral@SpawnLocation@RBX@@'),
    (0x7ff030, '??__F?prop_Duration@SpawnLocation@RBX@@'),
    (0x7ff050, '??__Fprop_TeamColor@RBX@@YAXXZ'),
    (0x7ff070, '??__Ffoo@?1??classDescriptor@' + DSL),
    (0x7fe680, '??__Ffoo@?1??classDescriptor@' + DSS),
    (0x5c07f0, '?classDescriptor@' + DSS + 'SAAAVClassDescriptor@23@XZ'),
    (0x489e60, '??$doDeclare@$1?sSpawnLocation@RBX@@3PADA@Name@RBX@@CAABV01@XZ'),
    (0x489ed0, '??$doDeclare@$1?sSpawnerService@RBX@@3QBDB@Name@RBX@@CAABV01@XZ'),
    (0x48aac0, '??$callDoDeclare@$1?sSpawnLocation@RBX@@3PADA@Name@RBX@@CAXXZ'),
    (0x48aad0, '??$callDoDeclare@$1?sSpawnerService@RBX@@3QBDB@Name@RBX@@CAXXZ'),
    # template bodies the original keeps outside the unit (COMDAT / ICF-shared)
    (0x60a2f0, '?isReadOnly@' + BPI), (0x60a2f0, '?isReadOnly@' + BPB), (0x60a2f0, '?isReadOnly@' + GSC),
    (0x608cd0, '?setValue@' + GSC),
    (0x583a00, '??1?$PropDescriptor@VSpawnLocation@RBX@@VBrickColor@2@@Reflection@RBX@@UAE@XZ'),
    (0x598310, '??_G?$PropDescriptor@VSpawnLocation@RBX@@VBrickColor@2@@Reflection@RBX@@UAEPAXI@Z'),
]
PENDING_ROWS = [
    (0x5d30c0, '??0SpawnerService@RBX@@QAE@XZ'),
]
# Compiled, not exact: they depend on the 2008 PartInstance layout (non-virtual size 0x3e8) that the native
# PartInstance.h does not have yet. Recorded with exact=false and the reason.
LAYOUT_ROWS = [
    (0x5d1ba0, '?getTeamColor@SpawnLocation@RBX@@QBE?AVBrickColor@2@XZ', 'reads teamColor +0x3e8'),
    (0x5d1bb0, '??1' + FPL + 'MAE@XZ', 'stores PartInstance-layout vtables and vbase displacements'),
    (0x5d1fa0, '??0' + FPL + 'IAE@XZ', 'PartInstance base construction and vtables'),
    (0x5d31b0, '??0' + DCL + 'IAE@XZ', 'vtables and vbase displacements'),
    (0x5d3370, '??_E' + FPL + '$2PPPPPPPM@', 'vtordisp thunk: vbase offset 0x3fc'),
    (0x5d3490, '??0SpawnLocation@RBX@@QAE@XZ', 'fields +0x3e8..+0x404 and vbase displacements'),
    (0x5d3710, '??_ESpawnLocation@RBX@@$4PPPPPPPM@', 'vtordisp thunk: vbase offset 0x41c'),
    (0x5d3730, '??1SpawnLocation@RBX@@UAE@XZ', 'scoped_connection +0x3ec'),
    (0x5d37b0, '?setTeamColor@SpawnLocation@RBX@@QAEXVBrickColor@2@@Z', 'writes teamColor +0x3e8'),
    (0x7f5f20, '??__E?prop_Duration@SpawnLocation@RBX@@', 'member offset 0x404'),
    (0x7f5f50, '??__E?prop_Neutral@SpawnLocation@RBX@@', 'member offset 0x400'),
    (0x7f5f80, '??__E?prop_AllowTeamChangeOnTouch@SpawnLocation@RBX@@', 'member offset 0x401'),
]
NOT_ATTEMPTED = {
    '005d1ec0': 'SpawnLocation::onEvent_spawnerTouched (Humanoid::modelIsCharacter, Players 0049acd0, Player setters); needs fields +0x3e8/+0x400/+0x401',
    '005d37d0': 'SpawnLocation::onServiceProvider: SignalDesc::connect 004a3340 takes a third argument (10) the donor signal.h lacks; scoped_connection +0x3ec',
    '005d2180/005d22e0': 'boost::bind / boost::function plumbing for onEvent_spawnerTouched (member pointer with vbase adjust; functor manager)',
    '005d2320': 'list clear/_Tidy instance reading head +0x144 of an enclosing object (owner not identified)',
    '005d2530/005d2670': 'ServiceProvider find/create template instances (class index 005d1d70, statics 00979da4); not identified',
    '005d1d70/005d1dd0/005d2170/005d23b0': 'ServiceProvider class-index helpers (doGetClassIndex/callDoGetClassIndex/getClassIndex instances)',
    '005d2260': 'a 12-byte list node _Buynode instance (no exact counterpart in this unit build)',
    '005d2a60/005d2b30': 'SignalDesc connect helper and a dynamic_cast helper used by the spawn routine',
    '005d2b80': 'SpawnerService spawn routine (1084 bytes; "SpawnPlayer couldn\'t get the workspace", ForceField, DebrisService::addItem); reads SpawnLocation fields',
    '005d33a0': 'ServiceProvider::create<SpawnerService> template instance (needs native ServiceProvider create/find bodies)',
}

LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
binding = {}   # symbol -> (address, row) for the one-address-per-symbol check


def target_of(address):
    """Original bytes and relocation offsets of one row, or of contiguous rows concatenated."""
    parts = address if isinstance(address, tuple) else (address,)
    code, relocs = b'', []
    for part in parts:
        assert part == parts[0] + len(code), ('rows not contiguous', [hex(p) for p in parts])
        body, refs, _ = match.target('2008-06', '%08x' % part)
        relocs += [r + len(code) for r in refs]
        code += body
    return code, relocs


def resolve(obj, rows):
    raw = Path(obj).read_bytes()
    funcs = match.coff_functions(raw)
    out = []
    for row in rows:
        address, key = row[0], row[1]
        hits = [x for x in funcs if x[0] == key] or [x for x in funcs if x[0].startswith(key) and not LOCAL_EH.match(x[0])]
        assert len(hits) == 1, (address, key, [h[0] for h in hits])
        out.append((address, hits[0][0]))
    return out


def first(address):
    return address[0] if isinstance(address, tuple) else address


def verify(obj, rows, own, strict=True):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    result = []
    for address, name in rows:
        body, refs = bodies[name]
        target, target_refs = target_of(address)
        exact = match.exact_match(target, target_refs, body, refs)
        entry = {'address': '+'.join('%08x' % a for a in (address if isinstance(address, tuple) else (address,))),
                 'symbol': name, 'size': len(body), 'target_size': len(target), 'exact': exact}
        if not exact:
            assert not strict, (name, entry['address'], len(body), len(target))
            result.append(entry)
            continue
        start, section = definitions[name]
        table = sections[section]
        code = raw[table[4] + start:]
        verified, local = {}, set()
        base = first(address)
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
            offset -= start
            if not 0 <= offset < len(body):
                continue
            symbol = symbols[index][0]
            if kind == 20:
                value = (base + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
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
            elif symbol.startswith('??_R0') and symbol.endswith('@8'):
                rtti = original.string(value + 8)
                assert norm(rtti) == norm('.' + symbol[5:-2]), (name, symbol, hex(value), rtti)
                how = 'RTTI %s' % rtti
            elif symbol.startswith('??_7'):
                rtti, at = original.vtable_class(value)
                cls = symbol[4:symbol.index('@@6B') + 2]
                assert norm(rtti) == norm('.?AV' + cls), (name, symbol, hex(value), rtti)
                how = 'vtable RTTI %s offset %#x' % (rtti, at)
            elif symbol.startswith('??_8'):
                # vbtable: bound by consistency only (one address per symbol); no exact row references one today
                how = 'vbtable'
            elif symbol.startswith('??_E') and ('??_G' + symbol[4:]) in own:
                assert own['??_G' + symbol[4:]] == value, (name, symbol, hex(value))
                how = 'own row (??_G)'
            elif symbol.startswith('??_E') and ('??_G' + symbol[4:]) in FOLDED:
                assert FOLDED['??_G' + symbol[4:]] == value, (name, symbol, hex(value))
                how = 'folded (??_G)'
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
                how = 'call target of a non-exact row'
            elif symbol.startswith('??_B?1??') or symbol.startswith('?$S') or '?$TSS' in symbol or symbol.startswith('?flag@') \
                    or symbol.startswith('?foo@') or symbol.startswith('?n@') or symbol.startswith('?root@'):
                how = 'local static'
            else:
                UNBOUND.append('%s in %s -> %s' % (symbol, name, hex(value)))
                continue
            prev = binding.setdefault(symbol, (value, name))
            assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
            verified[symbol] = '%s (%s)' % (hex(value), how)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local)})
        result.append(entry)
    return result


timer_rows = resolve(timer_obj, TIMER_ROWS)
spawn_rows = resolve(spawn_obj, SPAWN_ROWS)
pend_rows = resolve(pend_obj, PENDING_ROWS)
layout_rows = resolve(spawn_obj, LAYOUT_ROWS)
own = {}
for address, name in timer_rows + spawn_rows + pend_rows:
    own.setdefault(name, first(address))
timer_out = verify(timer_obj, timer_rows, own)
spawn_out = verify(spawn_obj, spawn_rows, own)
pend_out = verify(pend_obj, pend_rows, own)
for row in pend_out:  # exact only under NATIVE_SPAWN_PENDING with generated shared-header copies: not counted
    row['exact'] = False
    row['exact_pending_build_only'] = True
layout_out = verify(spawn_obj, layout_rows, own, strict=False)
for row, (_, _, why) in zip(layout_out, LAYOUT_ROWS):
    if row['exact']:   # would need re-review: these depend on the PartInstance layout
        raise AssertionError('layout-dependent row unexpectedly exact: %s' % row['address'])
    row['reason'] = 'needs the 2008 PartInstance layout: ' + why
assert not UNBOUND, '\n'.join(UNBOUND)

# ---- vtables from the objects built with the current headers, slot by slot ---------------------------------
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
slot_names = {}
for table_ in (own, FOLDED, EXTERNAL, UNPROVEN):
    for k, v in table_.items():
        slot_names.setdefault(k, v)


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


def check_vtable(obj, symbol, address, strict=True):
    slots = compiled_vtable(obj, symbol)
    out, bad = [], []
    for i, slot in enumerate(slots):
        value = d(address + 4 * i)
        if slot.startswith('??_E') and '??_G' + slot[4:] in slot_names:
            expect = slot_names['??_G' + slot[4:]]
        else:
            expect = slot_names.get(slot)
        if expect is not None:
            ok = expect == value
            how = 'bound'
        else:
            ok = norm(names.get(value, '')) == norm(slot)
            how = 'evidence name'
        out.append({'slot': i, 'symbol': slot, 'original': '%08x' % value, 'ok': ok, 'how': how})
        if not ok:
            bad.append((i, slot, hex(value)))
    if strict:
        assert not bad, (symbol, bad)
    return out, bad


# Slots bound to an inherited body (symbol of a base class) must hold the same address as the base class's own vtable:
# Instance 0082d884 (Instance constructor 0055b7e0) for the services, Part 00832d4c (PartInstance constructor 0059d4d0)
# for SpawnLocation.
assert original.vtable_class(0x82d884) == ('.?AVInstance@RBX@@', 0)
assert original.vtable_class(0x832d4c) == ('.?AVPartInstance@RBX@@', 0)


def inherited(rows, reference, own_class):
    bad = []
    for s in rows:
        if s['ok']:
            continue
        cls = s['symbol'].split('@')[1] if s['symbol'].startswith('?') and not s['symbol'].startswith('??') else ''
        if cls != own_class and int(s['original'], 16) == d(reference + 4 * s['slot']):
            s['ok'] = True
            s['how'] = 'inherited (%s slot of the base vtable %08x)' % (s['symbol'].split('@')[0][1:], reference)
        else:
            bad.append(s)
    return bad


vt = {}
vt['TimerService'], _ = check_vtable(timer_obj, '??_7TimerService@RBX@@' + '6B?$GuidItem@VInstance@RBX@@@1@@', 0x83d1a4, strict=False)
vt['TimerService_listener'], _ = check_vtable(timer_obj, '??_7TimerService@RBX@@6B@', 0x83d118)
vt['SpawnerService'], _ = check_vtable(spawn_obj, '??_7SpawnerService@RBX@@' + '6B?$GuidItem@VInstance@RBX@@@1@@', 0x83bd2c, strict=False)
vt['SpawnLocation'], _ = check_vtable(spawn_obj, '??_7SpawnLocation@RBX@@' + '6B?$GuidItem@VInstance@RBX@@@1@@', 0x83c0d4, strict=False)
assert not inherited(vt['TimerService'], 0x82d884, 'TimerService'), vt['TimerService']
assert not inherited(vt['SpawnerService'], 0x82d884, 'SpawnerService'), vt['SpawnerService']
assert not inherited(vt['SpawnLocation'], 0x832d4c, 'SpawnLocation'), vt['SpawnLocation']
assert len(vt['TimerService']) == len(vt['SpawnerService']) == 16
assert vt['TimerService'][12]['original'] == '005d73a0' and vt['TimerService'][12]['symbol'].startswith('?onServiceProvider@TimerService')
assert vt['SpawnLocation'][12]['symbol'].startswith('?onServiceProvider@SpawnLocation') and vt['SpawnLocation'][12]['original'] == '005d37d0'
assert len(vt['SpawnLocation']) == 26, len(vt['SpawnLocation'])

# ---- RTTI, allocation sizes and strings ---------------------------------------------------------------------
assert original.vtable_class(0x83d1a4) == ('.?AVTimerService@RBX@@', 0)
assert original.vtable_class(0x83bd2c) == ('.?AVSpawnerService@RBX@@', 0)
assert original.vtable_class(0x83c0d4) == ('.?AVSpawnLocation@RBX@@', 0)
for factory, size, ctor in ((0x48bcf0, 0x158, 0x5d71b0), (0x48f220, 0x14c, 0x5d30c0), (0x48efb0, 0x424, 0x5d3490)):
    body, _, _ = match.target('2008-06', '%08x' % factory)
    assert b'\x68' + struct.pack('<I', size) in body, hex(factory)
    call = body.index(b'\xe8', body.index(b'\x68' + struct.pack('<I', size)) + 5)
    while (factory + call + 5 + struct.unpack_from('<i', body, call + 1)[0]) & 0xffffffff != ctor:
        call = body.index(b'\xe8', call + 1)
for address, text in ((0x83c150, 'Duration'), (0x83c15c, 'Forcefield'), (0x82255c, 'Neutral'), (0x83c168, 'Teams'),
                      (0x83c170, 'AllowTeamChangeOnTouch'), (0x822548, 'TeamColor')):
    assert original.string(address) == text, (hex(address), text)


def bases(vtable):
    hierarchy = d(d(vtable - 4) + 16)
    out = {}
    for i in range(d(hierarchy + 8)):
        bcd = d(d(hierarchy + 12) + 4 * i)
        out.setdefault(original.string(d(bcd) + 8), struct.unpack('<i', original.data(bcd + 8, 4))[0])
    return out


tb = bases(0x83d1a4)
assert tb['.?AVService@RBX@@'] == 0x134 and tb['.?AV?$Listener@VRunService@RBX@@VHeartbeat@2@@RBX@@'] == 0x130, tb
assert bases(0x83bd2c)['.?AVService@RBX@@'] == 0x130
assert '.?AVPartInstance@RBX@@' in bases(0x83c0d4)
# ThrowInfo 008d0cc0 (_Incsize) first catchable type is std::length_error.
cta = d(0x8d0cc0 + 12)
assert original.string(d(d(cta + 4) + 4) + 8) == '.?AVlength_error@std@@'

sha = nb.sha
paths = [Path(__file__).resolve(), TIMER_H, SPAWNER_H, SPAWN_H, TIMER_SRC, SPAWN_SRC, LAYOUT]
groups = {'timer': timer_out, 'spawn': spawn_out, 'pending': pend_out, 'layout_blocked': layout_out}
exact = sorted({r['address'] for g in (timer_out, spawn_out) for r in g if r['exact']})
exact_rows = sorted({a for e in exact for a in e.split('+')})
receipt = {
    'class': 'RBX::TimerService, RBX::SpawnerService, RBX::SpawnLocation', 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': {'layout': layout_flags, 'timer': timer_flags, 'spawn': spawn_flags, 'pending': pend_flags},
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in (layout_obj, timer_obj, spawn_obj, pend_obj)},
    'layout': {'TimerService': '0x158 (0048bcf0); Listener<RunService,Heartbeat> +0x130, Service +0x134, runService +0x134, std::list<Item> +0x13c; class name "Timer"',
               'SpawnerService': '0x14c (0048f220); Service empty base and std::list<SpawnLocation*> spawners at +0x130',
               'SpawnLocation': '0x424 (0048efb0); PartInstance non-virtual part to +0x3e8, teamColor +0x3e8, scoped_connection +0x3ec, neutral +0x400, allowTeamChangeOnTouch +0x401, duration +0x404, virtual bases from +0x408'},
    'rows': groups,
    'exact_function_rows': exact_rows,
    'vtables': vt,
    'pending_note': 'pending rows are exact only with generated copies of v8tree/Instance.h (Instance::propArchivable) and '
                    'reflection/property.h (2008 GetSet second bool virtual, setValue at slot 3) under out/native-layouts/spawn-pending.',
    'layout_blocked_note': 'layout_blocked rows compile to the original sizes but need native PartInstance.h with the 2008 '
                           'non-virtual size 0x3e8 (currently sizeof 0x2ec including virtual bases).',
    'not_attempted': NOT_ATTEMPTED,
    'proposal_instance_h': PROPOSAL_INSTANCE,
    'proposal_property_h': PROPOSAL_PROPERTY,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/spawn-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native TimerService/SpawnerService/SpawnLocation: %d Timer rows, %d Spawn rows exact (%d distinct function '
      'addresses); %d pending-build-only, %d layout-blocked rows not counted; targets and vtables verified'
      % (sum(r['exact'] for r in timer_out), sum(r['exact'] for r in spawn_out), len(exact_rows), len(pend_out), len(layout_out)))
