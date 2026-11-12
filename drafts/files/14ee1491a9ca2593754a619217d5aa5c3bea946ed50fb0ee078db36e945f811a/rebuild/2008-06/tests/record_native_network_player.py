"""Verify the inactive native RBX::Network::Player recovery (2008-06).

Builds (document-swap flags + /fp:fast, VS2008 RTM 21022):
  * tests/NativeNetworkPlayerLayout.cpp   sizeof/offset probes, current native headers only;
  * native-classes/NetworkPlayer.cpp      base build: current native headers plus declaration-only stand-ins
                                          for headers of other classes that do not compile against the 2008
                                          const-char-array DescribedCreatable (out/native-layouts/network-player-overlay/:
                                          Network/Players.h = tests/NativeNetworkPlayerPlayers.h,
                                          v8datamodel/ModelInstance.h = tests/NativeTeamPendingModel.h, read only);
The RefPropDescriptor constructor 004913d0 is a base row: the native reflection/reflection.h declares IIDREF
__declspec(novtable) (the original constructor stores only the final vtable 00821b4c); the build asserts it.

Every row must be relocation-masked exact against the original, and every REL32/DIR32 target is bound to the
address the original instruction uses and verified: imports by DLL export / mfc ordinal name, string literals by
bytes, type descriptors and vtables by original RTTI names, own symbols by the row proven here, and the remaining
externals by the explicit EXTERNAL / DATA / FOLDED maps (call sites read in the original disassembly). A symbol
must bind to one address in every row. Vtable slot checks use the base (current-header) object's class layout:
the Player vtables in the binary must hold the thunks/overrides proven by base rows.
Writes work/2008-06/shared-layouts/network-player-working.json.
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

DISCOVER = os.environ.get('NP_DISCOVER') == '1'
R = ROOT / 'rebuild/2008-06'
OUT = nb.OUT
OUT.mkdir(parents=True, exist_ok=True)
SRC = R / 'native-classes/NetworkPlayer.cpp'
HEADER = R / 'native-headers/Network/Player.h'
LAYOUT = R / 'tests/NativeNetworkPlayerLayout.cpp'
PLAYERS_STANDIN = R / 'tests/NativeNetworkPlayerPlayers.h'
MODEL_STANDIN = R / 'tests/NativeTeamPendingModel.h'

overlay = OUT / 'network-player-overlay'
for sub in ('Network', 'v8datamodel'):
    (overlay / sub).mkdir(parents=True, exist_ok=True)
shutil.copyfile(PLAYERS_STANDIN, overlay / 'Network/Players.h')
shutil.copyfile(MODEL_STANDIN, overlay / 'v8datamodel/ModelInstance.h')

# IIDREF is novtable in the native reflection.h (canonical); 004913d0 relies on it.
assert (R / 'native-headers/reflection/reflection.h').read_text().count('\tclass __declspec(novtable) IIDREF\n') == 1

def build(name, src, extra=(), tail=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + list(tail) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeNetworkPlayerLayout', LAYOUT)
base_obj, base_flags = build('NativeNetworkPlayer', SRC, ['/I' + str(overlay)], ['/fp:fast'])

# ---- layout ---------------------------------------------------------------------------------------
raw = layout_obj.read_bytes()
for prefix, value in (('?nativeNetworkPlayerSize@@', 0x1d8), ('?nativeScopedConnectionSize@@', 0x14),
                      ('?nativeNotifierAddedOffset@@', 0x130), ('?nativeNotifierRemovingOffset@@', 0x150)):
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    assert body == b'\xb8' + struct.pack('<I', value) + b'\xc3', (prefix, body.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}


def norm(symbol):
    return symbol.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


P = 'Player@Network@RBX@@'
FP = '?$FactoryProduct@VPlayer@Network@RBX@@VInstance@3@$1?sPlayer@23@3PADA@RBX@@'
DC = '?$DescribedCreatable@VPlayer@Network@RBX@@VInstance@3@$1?sPlayer@23@3PADA@RBX@@'
DS = '?$Described@VPlayer@Network@RBX@@$1?sPlayer@23@3PADAV' + FP[:-6] + '@3@@Reflection@RBX@@'

# ---- externals: address the original instruction uses, read at the call sites listed ----------------
EXTERNAL = {
    # Instance / ServiceProvider / reflection runtime
    '??0Instance@RBX@@QAE@XZ': 0x55b7e0,                       # FactoryProduct ctor 00489a40
    '??1Instance@RBX@@UAE@XZ': 0x55a540,                       # FactoryProduct dtor 004899e0
    '?setName@Instance@RBX@@UAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': 0x55af90,  # 004937c0
    '?raisePropertyChanged@Instance@RBX@@QAEXABVPropertyDescriptor@Reflection@2@@Z': 0x40db00,
    '?setParent@Instance@RBX@@QAEXPAV12@@Z': 0x55a8f0,          # setCharacter 004944b0
    '??$shared_from@VInstance@RBX@@@RBX@@YA?AV?$shared_ptr@VInstance@RBX@@@boost@@PAVInstance@0@@Z': 0x618a40,
    '??4shared_count@detail@boost@@QAEAAV012@ABV012@@Z': 0x4025b0,
    '?disconnect@connection@signals@boost@@QBEXXZ': 0x595230,    # setCharacter
    '??1scoped_connection@signals@boost@@QAE@XZ': 0x5954b0,      # destructor 00494c60
    '?getLocalTime@System@G3D@@SANXZ': 0x508410,                # onServiceProvider 00494740
    '?zero@Vector2@G3D@@SAABV12@XZ': 0x509ba0,                  # constructor 00493da0
    '??0Vector2int16@G3D@@QAE@ABVVector2@1@@Z': 0x5122d0,
    # Players statics (declaration-only stand-in); call sites in 004944b0, 004947b0, 00494740, 00495d00
    '?backendProcessing@Players@Network@RBX@@SA_NPBVInstance@3@_N@Z': 0x495eb0,
    '?frontendProcessing@Players@Network@RBX@@SA_NPBVInstance@3@_N@Z': 0x495e80,
    # Player members outside this recovery (bodies not attempted): call sites in 00494740 / 00495d00 / 004944b0
    '?onCharacterChangedFrontend@Player@Network@RBX@@AAEXXZ': 0x4924e0,
    '?doPeriodicIdleCheck@Player@Network@RBX@@AAEXXZ': 0x494650,
    '?loadCharacterAppearance@Player@Network@RBX@@AAEX_N@Z': 0x495380,
    '?loadCharacter@Player@Network@RBX@@QAEX_N@Z': 0x4957a0,    # initializer 007f0f40 (member pointer)
    # Notifier<Player, E>: constructor folded with the identical StandardOut instance; raise bodies (no
    # vtable references) proven as rows below
    '??0?$Notifier@VPlayer@Network@RBX@@UCharacterAdded@23@@RBX@@IAE@XZ': 0x5e9ec0,
    '??0?$Notifier@VPlayer@Network@RBX@@UCharacterRemoving@23@@RBX@@IAE@XZ': 0x5e9ec0,
    # reflection / boost / G3D runtime (call sites in the descriptor constructors, 00493760, 00489810)
    '??$convert@_N@Value@Reflection@RBX@@QAEAA_NXZ': 0x56ebb0,
    '??$singleton@M@Type@Reflection@RBX@@SAABV012@XZ': 0x56cca0,
    '??$singleton@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Type@Reflection@RBX@@SAABV012@XZ': 0x56cdf0,
    '??$singleton@V?$shared_ptr@VInstance@RBX@@@boost@@@Type@Reflection@RBX@@SAABV012@XZ': 0x56cae0,
    '??$singleton@X@Type@Reflection@RBX@@SAABV012@XZ': 0x594a50,
    '??$singleton@_N@Type@Reflection@RBX@@SAABV012@XZ': 0x56cc30,
    '??0?$TypedPropertyDescriptor@H@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@H@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x4432a0,
    '??0?$TypedPropertyDescriptor@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x443230,
    '??0?$TypedPropertyDescriptor@VBrickColor@RBX@@@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@VBrickColor@RBX@@@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x48b180,
    '??0?$TypedPropertyDescriptor@VVector2int16@G3D@@@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@VVector2int16@G3D@@@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x445560,
    '??0?$TypedPropertyDescriptor@_N@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@_N@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x40a290,
    '??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z': 0x5708f0,
    '??0FunctionDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBDW4Security@012@@Z': 0x595790,
    '??0PropertyDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@ABVType@12@PBD2W4Functionality@012@@Z': 0x56c650,
    '??0SignalDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD@Z': 0x56bab0,
    '??0Value@Reflection@RBX@@QAE@XZ': 0x594ac0,
    '??0runtime_error@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z': 0x409d50,
    '??1?$list@UItem@SignatureDescriptor@Reflection@RBX@@V?$allocator@UItem@SignatureDescriptor@Reflection@RBX@@@std@@@std@@QAE@XZ': 0x4199e0,
    '?_Buynode@?$list@UItem@SignatureDescriptor@Reflection@RBX@@V?$allocator@UItem@SignatureDescriptor@Reflection@RBX@@@std@@@std@@IAEPAU_Node@?$_List_nod@UItem@SignatureDescriptor@Reflection@RBX@@V?$allocator@UItem@SignatureDescriptor@Reflection@RBX@@@std@@@2@PAU342@0ABUItem@SignatureDescriptor@Reflection@RBX@@@Z': 0x417f00,
    '?_Incsize@?$list@UItem@SignatureDescriptor@Reflection@RBX@@V?$allocator@UItem@SignatureDescriptor@Reflection@RBX@@@std@@@std@@IAEXI@Z': 0x682cc0,
    '?addArgument@SignatureDescriptor@Reflection@RBX@@QAEXABVName@3@ABVType@23@ABVValue@23@@Z': 0x594b40,
    '?classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3QBDBVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ': 0x40ad80,
    '?declare@Name@RBX@@SAABV12@PBDH@Z': 0x553f90,
    '?cleanup@tss@detail@boost@@QAEXPAX@Z': 0x5a6ff0,
    '?get@tss@detail@boost@@QBEPAXXZ': 0x5a7570,
    '?set@tss@detail@boost@@QAEXPAX@Z': 0x5a76b0,
    '?format@G3D@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PBDZZ': 0x509b10,
    '?isInRole@Context@Security@RBX@@SA_NW4Identities@23@W4Permissions@23@@Z': 0x5cf070,
    '?ptr@Context@Security@RBX@@CAAAV?$thread_specific_ptr@VContext@Security@RBX@@@boost@@XZ': 0x42bbb0,
    # Notifier<Player, E>::raise(E, Listener*) bodies (283 bytes, not reproduced here); called by raise(E) 0048b9a0 / 0048ba70
    '?raise@?$Notifier@VPlayer@Network@RBX@@UCharacterAdded@23@@RBX@@IBEXUCharacterAdded@Network@2@PAV?$Listener@VPlayer@Network@RBX@@UCharacterAdded@23@@2@@Z': 0x48af10,
    '?raise@?$Notifier@VPlayer@Network@RBX@@UCharacterRemoving@23@@RBX@@IBEXUCharacterRemoving@Network@2@PAV?$Listener@VPlayer@Network@RBX@@UCharacterRemoving@23@@2@@Z': 0x48b030,
    # ICF-shared instances (same bytes as the Instance / Player versions named by the evidence)
    '??$shared_from@VModelInstance@RBX@@@RBX@@YA?AV?$shared_ptr@VModelInstance@RBX@@@boost@@PAVModelInstance@0@@Z': 0x618a40,
    '?reset@?$shared_ptr@VModelInstance@RBX@@@boost@@QAEXXZ': 0x456e80,
    # setUnder13/setSuperSafeChat inline copies (they call the GetSet through slot 3, see the Clothing GetSet proposal)
    '?setUnder13@Player@Network@RBX@@QAEX_N@Z': 0x48b910,
    '?setSuperSafeChat@Player@Network@RBX@@QAEX_N@Z': 0x48b940,
    '??0Type@Reflection@RBX@@IAE@PBDABVtype_info@@0@Z': 0x4897a0,   # RefType::singleton<Player*> 0048a910
    '??1ClassDescriptor@Reflection@RBX@@UAE@XZ': 0x40abc0,
    '__TI2?AVbad_cast@std@@': 0x8d362c, '__TI2?AVruntime_error@std@@': 0x8d1bc8,   # catchable types checked below
    # runtime
    '___RTDynamicCast': 0x6a17c6, '_atexit': 0x6a17af, '??2@YAPAXI@Z': 0x6a0920, '??3@YAXPAX@Z': 0x6a067a,
    '__CxxThrowException@8': 0x6a158c,
}
# Descriptor objects: the `this` the dynamic initializers 007f0f40..007f12f0 pass.
DATA = {
    '_loadCharacterFunction': 0x96fe28, '_removeCharacterFunction': 0x96fd28, '_func_SetUnder13': 0x96fd88,
    '_func_SetSuperSafeChat': 0x96fc08, '_prop_Character': 0x96fe70, '_prop_characterAppearance': 0x96fe90,
    '_prop_userId': 0x96fc84, '_prop_teamColor': 0x96fd68, '_prop_neutral': 0x96fec8,
    '_event_Chatted': 0x96fca0, '_event_Idled': 0x96fc50,
    '?prop_Under13@' + P + '2V?$BoundProp@_N$00@Reflection@3@A': 0x96fee4,
    '?prop_SuperSafeChat@' + P + '2V?$BoundProp@_N$00@Reflection@3@A': 0x96fcd4,
    '?prop_ServerRequestLow@' + P + '2V?$BoundProp@VVector2int16@G3D@@$00@Reflection@3@A': 0x96fe08,
    '?prop_ServerRequestHigh@' + P + '2V?$BoundProp@VVector2int16@G3D@@$00@Reflection@3@A': 0x96fdec,
    '?prop_ServerDemandLow@' + P + '2V?$BoundProp@VVector2int16@G3D@@$00@Reflection@3@A': 0x96fd0c,
    '?prop_ServerDemandHigh@' + P + '2V?$BoundProp@VVector2int16@G3D@@$00@Reflection@3@A': 0x96feac,
    '?prop_ClientSimulateLow@' + P + '2V?$BoundProp@VVector2int16@G3D@@$00@Reflection@3@A': 0x96fdd0,
    '?prop_ClientSimulateHigh@' + P + '2V?$BoundProp@VVector2int16@G3D@@$00@Reflection@3@A': 0x96fcf0,
    '?sPlayer@Network@RBX@@3PADA': 0x934d38,   # "Player" (.data), setName in the constructor
}
FOLDED = {}

# (address, symbol or unique symbol prefix)
ROWS = [
    # Player bodies
    (0x494c60, '??1' + P + 'UAE@XZ'),
    (0x494f60, '??_G' + P + 'UAEPAXI@Z'),
    (0x494040, '??_E' + P + 'WBE@AEPAXI@Z'), (0x494050, '??_E' + P + 'WBDA@AEPAXI@Z'),
    (0x494060, '??_E' + P + 'WBFA@AEPAXI@Z'), (0x494070, '??_E' + P + 'WCE@AEPAXI@Z'),
    (0x494080, '??_E' + P + 'WEE@AEPAXI@Z'), (0x494090, '??_E' + P + 'WGE@AEPAXI@Z'),
    (0x4940a0, '??_E' + P + 'WIE@AEPAXI@Z'), (0x4940b0, '??_E' + P + 'WKE@AEPAXI@Z'),
    (0x4940c0, '??_E' + P + 'WME@AEPAXI@Z'), (0x4940d0, '??_E' + P + 'WBA@AEPAXI@Z'),
    (0x4937c0, '?setName@' + P + 'UAEXABV'),
    (0x4944b0, '?setCharacter@' + P),
    (0x494600, '?setTeamColor@' + P),
    (0x494620, '?setNeutral@' + P),
    (0x494740, '?onServiceProvider@' + P),
    (0x4947b0, '?removeCharacter@' + P),
    (0x494830, '?setUserID@' + P),
    (0x495d00, '?setCharacterAppearance@' + P),
    # base-class template instances of the unit
    (0x4927a0, '??0' + DC + 'IAE@XZ'),
    (0x492870, '??_G' + DC + 'UAEPAXI@Z'),
    (0x492840, '??_E' + DC + 'WIE@AEPAXI@Z'), (0x492850, '??_E' + DC + 'WBA@AEPAXI@Z'),
    (0x492860, '??_E' + DC + 'WCE@AEPAXI@Z'),
    (0x491360, '?classDescriptor@' + DS + 'SAAAVClassDescriptor@23@XZ'),
    # descriptor constructors / functions emitted in the unit
    (0x4918f0, '??$?0P8Player@Network@RBX@@BE?AV?$basic_string@'),
    (0x4919a0, '??$?0P8Player@Network@RBX@@BEHXZ'),
    (0x491a50, '??$?0VPlayer@Network@RBX@@@?$BoundProp@_N$00@'),
    (0x491b20, '??$?0VPlayer@Network@RBX@@@?$BoundProp@VVector2int16@G3D@@$00@'),
    (0x491bf0, '??$?0P8Player@Network@RBX@@BE?AVBrickColor@'),
    (0x491ca0, '??$?0P8Player@Network@RBX@@BE_NXZ'),
    (0x492890, '??0?$SignalDesc@VPlayer@Network@RBX@@$$A6AXV?$basic_string@'),
    (0x4929c0, '??0?$BoundFuncDesc@VPlayer@Network@RBX@@$$A6AX_N@Z$00@Reflection@RBX@@QAE@P8Player@Network@2@AEX_N@ZPBD20'),
    (0x492ae0, '?execute@?$BoundFuncDesc@VPlayer@Network@RBX@@$$A6AX_N@Z$00@'),
    (0x492bc0, '??0?$BoundFuncDesc@VPlayer@Network@RBX@@$$A6AX_N@Z$00@Reflection@RBX@@QAE@P8Player@Network@2@AEX_N@ZPBD2W4'),
    (0x492c60, '??0?$BoundFuncDesc@VPlayer@Network@RBX@@$$A6AXXZ$0A@@'),
    (0x492cd0, '?execute@?$BoundFuncDesc@VPlayer@Network@RBX@@$$A6AXXZ$0A@@'),
    (0x492d30, '??0?$SignalDesc@VPlayer@Network@RBX@@$$A6AXM@Z@'),
    (0x493760, '?current@Context@Security@RBX@@SAAAV123@XZ'),
    # dynamic initializers
    (0x7f0f40, '??__EloadCharacterFunction@@YAXXZ'),
    (0x7f0f70, '??__EremoveCharacterFunction@@YAXXZ'),
    (0x7f0fa0, '??__Efunc_SetUnder13@@YAXXZ'),
    (0x7f0fd0, '??__Efunc_SetSuperSafeChat@@YAXXZ'),
    (0x7f1000, '??__Eprop_Character@@YAXXZ'),
    (0x7f1040, '??__Eprop_characterAppearance@@YAXXZ'),
    (0x7f1080, '??__Eprop_userId@@YAXXZ'),
    (0x7f10c0, '??__E?prop_Under13@'),
    (0x7f10f0, '??__E?prop_SuperSafeChat@'),
    (0x7f1120, '??__E?prop_ServerRequestLow@'),
    (0x7f1150, '??__E?prop_ServerRequestHigh@'),
    (0x7f1180, '??__E?prop_ServerDemandLow@'),
    (0x7f11b0, '??__E?prop_ServerDemandHigh@'),
    (0x7f11e0, '??__E?prop_ClientSimulateLow@'),
    (0x7f1210, '??__E?prop_ClientSimulateHigh@'),
    (0x7f1240, '??__Eprop_teamColor@@YAXXZ'),
    (0x7f1280, '??__Eprop_neutral@@YAXXZ'),
    (0x7f12c0, '??__Eevent_Chatted@@YAXXZ'),
    (0x7f12f0, '??__Eevent_Idled@@YAXXZ'),
    # template instances whose original bodies live outside the unit (COMDAT / ICF-shared)
    (0x489a40, '??0' + FP + 'IAE@XZ'),
    (0x4899e0, '??1' + FP + 'MAE@XZ'),
    (0x489810, '?requirePermission@Context@Security@RBX@@QBEXW4Permissions@23@PBD@Z'),
    (0x48ba70, '?raise@?$Notifier@VPlayer@Network@RBX@@UCharacterRemoving@23@@RBX@@IBEXUCharacterRemoving@Network@2@@Z'),
    (0x48b9a0, '?raise@?$Notifier@VPlayer@Network@RBX@@UCharacterAdded@23@@RBX@@IBEXUCharacterAdded@Network@2@@Z'),
    (0x5b6590, '?getCharacter@' + P),
    (0x445260, '?getTeamColor@' + P),
    (0x489960, '?getNeutral@' + P),
    (0x489970, '?getCharacterAppearance@' + P),
    (0x4899a0, '?getUserID@' + P),
    (0x48a910, '??$singleton@PAVPlayer@Network@RBX@@@RefType@Reflection@RBX@@SAABV012@XZ'),
    (0x48b3a0, '??$getset@P8Player@Network@RBX@@BEPAVModelInstance@'),
    (0x48b3f0, '??$getset@P8Player@Network@RBX@@BE?AV?$basic_string@'),
    (0x48b440, '??$getset@P8Player@Network@RBX@@BEHXZ'),
    (0x48b490, '??$getset@P8Player@Network@RBX@@BE?AVBrickColor@'),
    (0x48a990, '??$getset@P8Player@Network@RBX@@BE_NXZ'),
    (0x4a34e0, '??1?$BoundFuncDesc@VPlayer@Network@RBX@@$$A6AX_N@Z$00@'),
    (0x7fb2c0, '??__Ffoo@?1??classDescriptor@' + DS),
    (0x7fb110, '??__Ftype@?1???$singleton@PAVPlayer@Network@RBX@@@RefType@'),
]
# The atexit destructor each initializer registers (push imm32 before call _atexit), bound below.
ATEXIT = {
    0x7f0f40: '??__FloadCharacterFunction@@YAXXZ', 0x7f0f70: '??__FremoveCharacterFunction@@YAXXZ',
    0x7f0fa0: '??__Ffunc_SetUnder13@@YAXXZ', 0x7f0fd0: '??__Ffunc_SetSuperSafeChat@@YAXXZ',
    0x7f1000: '??__Fprop_Character@@YAXXZ', 0x7f1040: '??__Fprop_characterAppearance@@YAXXZ',
    0x7f1080: '??__Fprop_userId@@YAXXZ', 0x7f10c0: '??__F?prop_Under13@', 0x7f10f0: '??__F?prop_SuperSafeChat@',
    0x7f1120: '??__F?prop_ServerRequestLow@', 0x7f1150: '??__F?prop_ServerRequestHigh@',
    0x7f1180: '??__F?prop_ServerDemandLow@', 0x7f11b0: '??__F?prop_ServerDemandHigh@',
    0x7f11e0: '??__F?prop_ClientSimulateLow@', 0x7f1210: '??__F?prop_ClientSimulateHigh@',
    0x7f1240: '??__Fprop_teamColor@@YAXXZ', 0x7f1280: '??__Fprop_neutral@@YAXXZ',
    0x7f12c0: '??__Fevent_Chatted@@YAXXZ', 0x7f12f0: '??__Fevent_Idled@@YAXXZ',
}
ROWS.append((0x4913d0, '??$?0P8Player@Network@RBX@@BEPAVModelInstance@'))   # RefPropDescriptor ctor (IIDREF novtable)
# Rows compiled but not exact (recorded with the reason).
NOT_EXACT = {
    0x493da0: ('??0' + P + 'QAE@XZ', 'constructor: same 657 bytes but the x87 order of the four DPHYS region sums differs '
               '(target x+c, y+c, x-c, y-c with c kept in st(3)); calls, data and every field store otherwise match'),
}

LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
binding = {}


def resolve(obj, rows):
    raw = Path(obj).read_bytes()
    funcs = match.coff_functions(raw)
    out = []
    for address, key in rows:
        hits = [x for x in funcs if x[0] == key] or [x for x in funcs if x[0].startswith(key)
                                                       and not LOCAL_EH.match(x[0])]
        assert len(hits) == 1, (hex(address), key, [h[0] for h in hits])
        out.append((address, hits[0][0]))
    return out


def verify(obj, rows, own, exact_required=True):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    result = []
    for address, name in rows:
        body, refs = bodies[name]
        target, target_refs, _ = match.target('2008-06', '%08x' % address)
        ok = match.exact_match(target, target_refs, body, refs)
        if DISCOVER and not ok:
            print('NOT EXACT', hex(address), name)
            continue
        assert ok, (name, hex(address), len(body), len(target))
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
            elif symbol.startswith('??_R0') and symbol.endswith('@8'):
                rtti = original.string(value + 8)
                assert norm(rtti) == norm('.' + symbol[5:-2]), (name, symbol, hex(value), rtti)
                how = 'RTTI %s' % rtti
            elif symbol.startswith('??_7'):
                rtti, at = original.vtable_class(value)
                cls = symbol[4:symbol.index('@@6B') + 2]
                assert norm(rtti) == norm('.?AV' + cls), (name, symbol, hex(value), rtti)
                how = 'vtable RTTI %s offset %#x' % (rtti, at)
            elif symbol.startswith('??_E') and ('??_G' + symbol[4:]) in own:
                assert own['??_G' + symbol[4:]] == value, (name, symbol, hex(value))
                how = 'own row (??_G)'
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
            elif symbol.startswith('??_B?1??') or symbol.startswith('?$S') or '?$TSS' in symbol or symbol.startswith('?flag@') \
                    or symbol.startswith('?foo@') or symbol.startswith('?n@') or symbol.startswith('?root@') \
                    or symbol.startswith('?value@?1??ptr@Context@Security') or symbol.startswith('?type@?1???$singleton@'):
                how = 'local static'
            else:
                UNBOUND.append('%s in %s -> %s (%s)' % (symbol, name, hex(value), names.get(value, '')))
                continue
            prev = binding.setdefault(symbol, (value, name))
            assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
            verified[symbol] = '%s (%s)' % (hex(value), how)
        result.append({'address': '%08x' % address, 'symbol': name, 'size': len(body), 'exact': True,
                       'verified_targets': verified, 'local_eh': sorted(local)})
    return result


# atexit rows: the destructor address is the immediate the initializer pushes before `call _atexit`.
atexit_rows = []
for init, key in ATEXIT.items():
    body, _, _ = match.target('2008-06', '%08x' % init)
    call = max(i for i in range(len(body) - 4) if body[i] == 0xe8
               and (init + i + 5 + struct.unpack_from('<i', body, i + 1)[0]) & 0xffffffff == EXTERNAL['_atexit'])
    push = body.rindex(b'\x68', 0, call)
    atexit_rows.append((struct.unpack_from('<I', body, push + 1)[0], key))

base_rows = resolve(base_obj, ROWS + atexit_rows)
own = {}
for address, name in base_rows:
    own.setdefault(name, address)
base_out = verify(base_obj, base_rows, own)
if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    sys.exit(0)
assert not UNBOUND, '\n'.join(UNBOUND)

# not-exact rows: present in the base object, bytes differ (recorded, not counted)
not_exact = []
base_funcs = {n: b for n, b, r in match.coff_functions(base_obj.read_bytes())}
for address, (key, reason) in NOT_EXACT.items():
    hits = [n for n in base_funcs if n == key or n.startswith(key)]
    assert len(hits) == 1, (key, hits)
    target, target_refs, _ = match.target('2008-06', '%08x' % address)
    assert not match.exact_match(target, target_refs, base_funcs[hits[0]], [r for n, b, r in match.coff_functions(base_obj.read_bytes()) if n == hits[0]][0])
    not_exact.append({'address': '%08x' % address, 'symbol': hits[0], 'size': len(base_funcs[hits[0]]), 'target_size': len(target),
                      'exact': False, 'reason': reason})

# ---- vtables, RTTI, allocation size and strings (checked against base rows) --------------------------
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
VT = 0x82220c
assert original.vtable_class(VT) == ('.?AVPlayer@Network@RBX@@', 0)
assert (d(VT + 4), d(VT + 8), d(VT + 48)) == (own[resolve(base_obj, [(0, '?setName@' + P + 'UAEXABV')])[0][1]], 0x565ff0, 0x494740)
# deleting-destructor thunks: each sub-vtable's slot 0 is the ??_E thunk proven above for that offset
thunks = {0x10: 'WBA', 0x14: 'WBE', 0x24: 'WCE', 0x44: 'WEE', 0x64: 'WGE', 0x84: 'WIE', 0xa4: 'WKE', 0xc4: 'WME', 0x130: 'WBDA', 0x150: 'WBFA'}
ctor, _, _ = match.target('2008-06', '00494c60')
for offset, tag in thunks.items():
    store = (b'\xc7\x06' if offset == 0 else (b'\xc7\x46' + bytes([offset]) if offset < 0x80 else b'\xc7\x86' + struct.pack('<I', offset)))
    at = ctor.index(store)
    sub_vt = struct.unpack_from('<I', ctor, at + len(store))[0]
    assert original.vtable_class(sub_vt) == ('.?AVPlayer@Network@RBX@@', offset), (hex(sub_vt), offset)
    assert d(sub_vt) == own['??_E' + P + tag + '@AEPAXI@Z'], (tag, hex(d(sub_vt)))
# askAddChild returns true (shared body with Team::askAddChild 00565ff0: mov al,1; ret 4)
assert match.target('2008-06', '00565ff0')[0] == b'\xb0\x01\xc2\x04\x00'
body, _, _ = match.target('2008-06', '004093b0')
assert b'\x68' + struct.pack('<I', 0x1d8) in body
assert original.string(0x934d38) == 'Player'
for address, text in ((0x822158, 'create a Player'), (0x821fa8, "set a Player's name"), (0x8224e0, 'DPHYS'),
                      (0x822434, 'LoadCharacter'), (0x822444, 'inGame'), (0x82244c, 'RemoveCharacter'),
                      (0x822548, 'TeamColor'), (0x822554, 'Team'), (0x82255c, 'Neutral'), (0x822564, 'Chatted'),
                      (0x822580, 'Idled'), (0x8224ac, 'userId'), (0x8224b4, 'Under13'), (0x8224bc, 'SuperSafeChat')):
    assert original.string(address) == text, (hex(address), text)
for throw_info, cls in ((0x8d362c, '.?AVbad_cast@std@@'), (0x8d1bc8, '.?AVruntime_error@std@@')):
    cta = d(throw_info + 12)
    assert original.string(d(d(cta + 4) + 4) + 8) == cls, (hex(throw_info), cls)
locator = d(VT - 4)
hierarchy = d(locator + 16)
items = [d(d(hierarchy + 12) + 4 * i) for i in range(d(hierarchy + 8))]
bases = {original.string(d(item) + 8): struct.unpack('<i', original.data(item + 8, 4))[0] for item in items}
assert bases['.?AV?$Notifier@VPlayer@Network@RBX@@UCharacterAdded@23@@RBX@@'] == 0x130, bases
assert bases['.?AV?$Notifier@VPlayer@Network@RBX@@UCharacterRemoving@23@@RBX@@'] == 0x150, bases

sha = nb.sha
paths = [Path(__file__).resolve(), HEADER, SRC, LAYOUT, PLAYERS_STANDIN, MODEL_STANDIN]
exact_addresses = sorted({r['address'] for r in base_out})
receipt = {
    'class': 'RBX::Network::Player', 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': {'layout': layout_flags, 'base': base_flags},
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in (layout_obj, base_obj)},
    'layout': 'Player 0x1d8 (Creatable<Instance>::create<Player> 004093b0); Notifiers 0x130/0x150; character +0x170, '
              'teamColor +0x178, neutral +0x17c, characterDiedConnection +0x180, characterAppearance +0x194, under13 +0x1b0, '
              'superSafeChat +0x1b1, userId +0x1b4, six Vector2int16 DPHYS regions +0x1b8..+0x1cc, lastActivityTime +0x1d0',
    'methods': base_out, 'not_exact': not_exact,
    'exact_distinct_addresses': exact_addresses,
    'standins_note': 'base build uses declaration-only stand-ins for Network/Players.h and v8datamodel/ModelInstance.h '
                     '(other classes; donor/native headers do not compile with the 2008 DescribedCreatable).',
    'reflection_h_note': 'IIDREF __declspec(novtable) is canonical in native-headers/reflection/reflection.h; '
                         '004913d0 is a base row.',
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/network-player-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native Network::Player: %d exact rows (%d distinct addresses), %d not exact; targets verified'
      % (len(base_out), len(exact_addresses), len(not_exact)))
