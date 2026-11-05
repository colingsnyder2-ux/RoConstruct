"""Verify the inactive native RBX::Network::Players recovery (2008-06).

Builds (document-swap flags, VS2008 RTM 21022, RakNet include dirs as tests/record_native_players_lifetime.py):
  * tests/NativeNetworkPlayersLayout.cpp   sizeof/base/field offsets, current native headers only;
  * native-classes/NetworkPlayers.cpp      base build: current native headers plus declaration-only stand-ins for
                                           other classes' headers that do not compile against the 2008
                                           const-char-array DescribedCreatable (out/native-network-players/overlay/:
                                           Client.h and Server.h = tests/NativeNetworkPlayersPeers.h,
                                           v8datamodel/ModelInstance.h = tests/NativeTeamPendingModel.h, read only);
  * the same unit with NATIVE_NETWORK_PLAYERS_PENDING against generated copies of other owners' headers carrying the
    PROPOSALS below (out/native-network-players/pending/). Rows exact only there are recorded exact=false
    (pending-build-only) and are not counted.

Every row must be relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified: imports by DLL export name, string literals by bytes, type descriptors and
vtables by original RTTI names, own symbols by the row proven here, and the remaining externals by the explicit
EXTERNAL / DATA maps (call sites read in the original disassembly). A symbol must bind to one address in every row.
Vtable slot checks use the base (current-header) object's vtable layout.
Writes work/2008-06/shared-layouts/network-players-working.json.
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
SRC = R / 'native-classes/NetworkPlayers.cpp'
HEADER = R / 'native-headers/Network/Players.h'
LAYOUT = R / 'tests/NativeNetworkPlayersLayout.cpp'
PEERS_STANDIN = R / 'tests/NativeNetworkPlayersPeers.h'
MODEL_STANDIN = R / 'tests/NativeTeamPendingModel.h'
RAKNET = ['/I' + str(ROOT / 'tools/rbxgs/Client/Network/raknet30/Source')]

base_dir = R / 'out/native-network-players'
overlay = base_dir / 'overlay'
(overlay / 'v8datamodel').mkdir(parents=True, exist_ok=True)
shutil.copyfile(PEERS_STANDIN, overlay / 'Client.h')
shutil.copyfile(PEERS_STANDIN, overlay / 'Server.h')
shutil.copyfile(MODEL_STANDIN, overlay / 'v8datamodel/ModelInstance.h')

# Proposals for other owners' headers, applied only to generated copies (pending build).
PROPOSALS = [
    (R / 'native-headers/Network/Player.h', 'Network/Player.h',
     '\t\t\tvoid removeCharacter();                                   // 004947b0\n',
     '\t\t\tvoid removeCharacter();                                   // 004947b0\n'
     '\t\t\tvoid rebuildBackpack();                                   // proposal: 004925c0\n',
     'Network/Player.h (Player): declare `void rebuildBackpack();` (004925c0, thiscall; throws "rebuildBackpack can only be '
     'called by the backend server"; called by Players::onEvent 00496cf0 and onChildAdded 0049dc70)'),
]
pending = base_dir / 'pending'
for source, dest, anchor, replacement, _ in PROPOSALS:
    text = source.read_text()
    assert text.count(anchor) == 1, (source, anchor)
    (pending / dest).parent.mkdir(parents=True, exist_ok=True)
    (pending / dest).write_text(text.replace(anchor, replacement))


def build(name, src, extra=(), tail=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + list(tail) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeNetworkPlayersLayout', LAYOUT)
base_obj, base_flags = build('NativeNetworkPlayers', SRC, ['/I' + str(overlay)], RAKNET)
pend_obj, pend_flags = build('NativeNetworkPlayersPending', SRC, ['/I' + str(pending), '/I' + str(overlay)],
                             RAKNET + ['/DNATIVE_NETWORK_PLAYERS_PENDING'])

# ---- layout ---------------------------------------------------------------------------------------
raw = layout_obj.read_bytes()
for prefix, value in (('?nativePlayersSize@@', 0x1b0), ('?nativePlayersChatNotifierOffset@@', 0x130),
                      ('?nativePlayersSuperSafeNotifierOffset@@', 0x150), ('?nativePlayersListenerOffset@@', 0x170),
                      ('?nativePlayersServiceOffset@@', 0x174), ('?nativeChatMessageSize@@', 0x48),
                      ('?nativeChatHistorySize@@', 0x1c)):
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    assert body == b'\xb8' + struct.pack('<I', value) + b'\xc3', (prefix, body.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}


def norm(symbol):
    return symbol.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


P = 'Players@Network@RBX@@'
NFP = '?$NonFactoryProduct@VInstance@RBX@@$1?sPlayers@Network@2@3PADA@RBX@@'
STR = 'V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@'
SPI = 'V?$shared_ptr@VInstance@RBX@@@boost@@'
VEC = 'V?$shared_ptr@$$CBV?$vector@' + SPI + 'V?$allocator@' + SPI + '@std@@@std@@@boost@@'
BFD = '?$BoundFuncDesc@V' + P

# Externals: the address the original instruction uses (call sites in the rows below); names checked against
# the evidence names where those exist; one address per symbol across every row.
EXTERNAL = {
    '_atexit': 0x6a17af,
    '??4shared_count@detail@boost@@QAEAAV012@ABV012@@Z': 0x4025b0,
    '??$create@VPlayer@Network@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VPlayer@Network@RBX@@@boost@@XZ': 0x4093b0,
    '??0runtime_error@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z': 0x409d50,
    '??0bad_function_call@boost@@QAE@XZ': 0x409ef0,
    '??$throw_exception@Vbad_function_call@boost@@@boost@@YAXABVbad_function_call@0@@Z': 0x40a500,
    '?increment@named_slot_map_iterator@detail@signals@boost@@QAEXXZ': 0x40aaa0,
    '?classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3QBDBVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ': 0x40ad80,
    '??$find_if@Vnamed_slot_map_iterator@detail@signals@boost@@Uis_callable@234@@std@@YA?AVnamed_slot_map_iterator@detail@signals@boost@@V1234@0Uis_callable@234@@Z': 0x40af30,
    '?equal@?$slot_call_iterator@U?$caller@V?$shared_ptr@VInstance@RBX@@@boost@@V?$function@$$A6AXV?$shared_ptr@VInstance@RBX@@@boost@@@ZV?$allocator@X@std@@@2@@?$call_bound1@X@detail@signals@boost@@Vnamed_slot_map_iterator@345@@detail@signals@boost@@QBE_NABV1234@@Z': 0x40b050,
    '?raisePropertyChanged@Instance@RBX@@QAEXABVPropertyDescriptor@Reflection@2@@Z': 0x40db00,
    '??$doDeclare@$1?sPlayers@Network@RBX@@3PADA@Name@RBX@@CAABV01@XZ': 0x411420,
    '??$callDoDeclare@$1?sPlayers@Network@RBX@@3PADA@Name@RBX@@CAXXZ': 0x411890,
    '?_Buynode@?$list@UItem@SignatureDescriptor@Reflection@RBX@@V?$allocator@UItem@SignatureDescriptor@Reflection@RBX@@@std@@@std@@IAEPAU_Node@?$_List_nod@UItem@SignatureDescriptor@Reflection@RBX@@V?$allocator@UItem@SignatureDescriptor@Reflection@RBX@@@std@@@2@PAU342@0ABUItem@SignatureDescriptor@Reflection@RBX@@@Z': 0x417f00,
    '??1?$list@UItem@SignatureDescriptor@Reflection@RBX@@V?$allocator@UItem@SignatureDescriptor@Reflection@RBX@@@std@@@std@@QAE@XZ': 0x4199e0,
    '?push_back@?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@QAEXABV?$shared_ptr@VInstance@RBX@@@boost@@@Z': 0x420110,
    '?addListener@?$Notifier@VPlayer@Network@RBX@@UCharacterAdded@23@@RBX@@QBEXPAV?$Listener@VPlayer@Network@RBX@@UCharacterAdded@23@@2@@Z': 0x4218a0,
    '?ptr@Context@Security@RBX@@CAAAV?$thread_specific_ptr@VContext@Security@RBX@@@boost@@XZ': 0x42bbb0,
    '??0Impersonator@Security@RBX@@QAE@W4Identities@12@@Z': 0x42bc10,
    '?erase@?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@QAE?AV?$_Vector_iterator@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@2@V?$_Vector_const_iterator@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@2@@Z': 0x439480,
    '??0?$TypedPropertyDescriptor@H@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@H@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x4432a0,
    '?sp_enable_shared_from_this@detail@boost@@YAXABVshared_count@12@ZZ': 0x47d410,
    '??0Type@Reflection@RBX@@IAE@PBDABVtype_info@@0@Z': 0x4897a0,
    '?findServiceProvider@ServiceProvider@RBX@@SAPBV12@PBVInstance@2@@Z': 0x4898d0,
    '?OnReceive@Players@Network@RBX@@QAE_NPAVRakPeerInterface@@PAUPacket@@@Z': 0x49d770,
    '??$?4V?$shared_ptr@VInstance@RBX@@@boost@@@any@boost@@QAEAAV01@ABV?$shared_ptr@VInstance@RBX@@@1@@Z': 0x48dd00,
    '??0?$slot_call_iterator@U?$caller@V?$shared_ptr@VInstance@RBX@@@boost@@V?$function@$$A6AXV?$shared_ptr@VInstance@RBX@@@boost@@@ZV?$allocator@X@std@@@2@@?$call_bound1@X@detail@signals@boost@@Vnamed_slot_map_iterator@345@@detail@signals@boost@@QAE@Vnamed_slot_map_iterator@123@0U?$caller@V?$shared_ptr@VInstance@RBX@@@boost@@V?$function@$$A6AXV?$shared_ptr@VInstance@RBX@@@boost@@@ZV?$allocator@X@std@@@2@@?$call_bound1@X@123@AAV?$optional@Uunusable@detail@signals@boost@@@3@@Z': 0x4908a0,
    '??$find@VPlayers@Network@RBX@@@ServiceProvider@RBX@@SAPAVPlayers@Network@1@PBVInstance@1@@Z': 0x491d50,
    '?rebuildBackpack@Player@Network@RBX@@QAEXXZ': 0x4925c0,
    '?setUserID@Player@Network@RBX@@QAEXH@Z': 0x494830,
    '?raise@?$Notifier@VPlayers@Network@RBX@@VSuperSafeChanged@3@@RBX@@IBEXVSuperSafeChanged@2@PAV?$Listener@VPlayers@Network@RBX@@VSuperSafeChanged@3@@2@@Z': 0x496680,
    '??0?$signal1@XV?$shared_ptr@VInstance@RBX@@@boost@@U?$last_value@X@2@HU?$less@H@std@@V?$function@$$A6AXV?$shared_ptr@VInstance@RBX@@@boost@@@ZV?$allocator@X@std@@@2@@boost@@QAE@ABU?$last_value@X@1@ABU?$less@H@std@@@Z': 0x499c00,
    '??$?0V?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@@shared_count@detail@boost@@QAE@PAV?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@@Z': 0x49a6c0,
    '??$find@VTeams@RBX@@@ServiceProvider@RBX@@SAPAVTeams@1@PBVInstance@1@@Z': 0x49ab50,
    '?write@?$CopyOnWrite@V?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@@RBX@@QAEAAV?$shared_ptr@V?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@@boost@@XZ': 0x49add0,
    '?reportAbuse@Players@Network@RBX@@QAEXPAVPlayer@23@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': 0x49c7b0,
    '?chat@Players@Network@RBX@@QAEXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': 0x49cb30,
    '??0AbuseReporter@Network@RBX@@QAE@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': 0x49e040,
    '??0PluginInterface@@QAE@XZ': 0x49ed30,
    '??1PluginInterface@@UAE@XZ': 0x49ed40,
    '?clientIsPresent@Client@Network@RBX@@SA_NPBVInstance@3@_N@Z': 0x49fe20,
    '??1?$BoundFuncDesc@VPlayers@Network@RBX@@$$A6A?AV?$shared_ptr@VInstance@RBX@@@boost@@H@Z$00@Reflection@RBX@@UAE@XZ': 0x4a34e0,
    '??1?$BoundFuncDesc@VPlayers@Network@RBX@@$$A6A?AV?$shared_ptr@VInstance@RBX@@@boost@@V45@@Z$00@Reflection@RBX@@UAE@XZ': 0x4a34e0,
    '??1?$BoundFuncDesc@VPlayers@Network@RBX@@$$A6AXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z$00@Reflection@RBX@@UAE@XZ': 0x4a34e0,
    '??1?$BoundFuncDesc@VPlayers@Network@RBX@@$$A6AXV?$shared_ptr@VInstance@RBX@@@boost@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z$01@Reflection@RBX@@UAE@XZ': 0x4a3d40,
    '?serverIsPresent@Server@Network@RBX@@SA_NPBVInstance@3@_N@Z': 0x4a40d0,
    '?declare@Name@RBX@@SAABV12@PBDH@Z': 0x553f90,
    '??0?$args1@V?$shared_ptr@VInstance@RBX@@@boost@@H@detail@signals@boost@@QAE@V?$shared_ptr@VInstance@RBX@@@3@@Z': 0x554810,
    '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330,
    '??1Instance@RBX@@UAE@XZ': 0x55a540,
    '?setParent@Instance@RBX@@QAEXPAV12@@Z': 0x55a8f0,
    '?setName@Instance@RBX@@UAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': 0x55af90,
    '??0Instance@RBX@@QAE@XZ': 0x55b7e0,
    '??1call_notification@detail@signals@boost@@QAE@XZ': 0x56a650,
    '??0call_notification@detail@signals@boost@@QAE@ABV?$shared_ptr@Vsignal_base_impl@detail@signals@boost@@@3@@Z': 0x56a760,
    '?findSignalInstance@SignalDescriptor@Reflection@RBX@@IBEPAVSignalInstance@23@PBVSignalSource@23@@Z': 0x56b620,
    '??0SignalDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD@Z': 0x56bab0,
    '??0PropertyDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@ABVType@12@PBD2W4Functionality@012@@Z': 0x56c650,
    '??$singleton@V?$shared_ptr@VInstance@RBX@@@boost@@@Type@Reflection@RBX@@SAABV012@XZ': 0x56cae0,
    '??$singleton@V?$shared_ptr@$$CBV?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@@boost@@@Type@Reflection@RBX@@SAABV012@XZ': 0x56cb50,
    '??$singleton@H@Type@Reflection@RBX@@SAABV012@XZ': 0x56cbc0,
    '??$singleton@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Type@Reflection@RBX@@SAABV012@XZ': 0x56cdf0,
    '??$convert@H@Value@Reflection@RBX@@QAEAAHXZ': 0x56ea60,
    '??$convert@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Value@Reflection@RBX@@QAEAAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ': 0x56f0b0,
    '??$convert@V?$shared_ptr@VInstance@RBX@@@boost@@@Value@Reflection@RBX@@QAEAAV?$shared_ptr@VInstance@RBX@@@boost@@XZ': 0x56f8c0,
    '??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z': 0x5708f0,
    '?begin@named_slot_map@detail@signals@boost@@QAE?AVnamed_slot_map_iterator@234@XZ': 0x571380,
    '?end@named_slot_map@detail@signals@boost@@QAE?AVnamed_slot_map_iterator@234@XZ': 0x5713b0,
    '??$singleton@X@Type@Reflection@RBX@@SAABV012@XZ': 0x594a50,
    '??0Value@Reflection@RBX@@QAE@XZ': 0x594ac0,
    '?addArgument@SignatureDescriptor@Reflection@RBX@@QAEXABVName@3@ABVType@23@ABVValue@23@@Z': 0x594b40,
    '??0FunctionDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBDW4Security@012@@Z': 0x595790,
    '??1worker_thread@RBX@@QAE@XZ': 0x595cb0,
    '??1?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@QAE@XZ': 0x5a2fe0,
    '?cleanup@tss@detail@boost@@QAEXPAX@Z': 0x5a6ff0,
    '?get@tss@detail@boost@@QBEPAXXZ': 0x5a7570,
    '?set@tss@detail@boost@@QAEXPAX@Z': 0x5a76b0,
    '??0?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@QAE@ABV01@@Z': 0x5acb00,
    '?assignNewPlayerToTeam@Teams@RBX@@QAEXPAVPlayer@Network@2@@Z': 0x5d6250,
    '??$call@V?$shared_ptr@$$CBV?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@@boost@@@?$BoundFuncDesc@VPlayers@Network@RBX@@$$A6A?AV?$shared_ptr@$$CBV?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@@boost@@XZ$0A@@Reflection@RBX@@ABEXPAVPlayers@Network@2@AAVValue@12@@Z': 0x5d6750,
    '?removeListener@?$Notifier@VPlayer@Network@RBX@@UCharacterAdded@23@@RBX@@QBEXPAV?$Listener@VPlayer@Network@RBX@@UCharacterAdded@23@@2@@Z': 0x5e5a80,
    '??0?$Notifier@VPlayers@Network@RBX@@VChatMessage@23@@RBX@@IAE@XZ': 0x5e9ec0,
    '??0?$Notifier@VPlayers@Network@RBX@@VSuperSafeChanged@3@@RBX@@IAE@XZ': 0x5e9ec0,
    '??$shared_from@VInstance@RBX@@@RBX@@YA?AV?$shared_ptr@VInstance@RBX@@@boost@@PAVInstance@0@@Z': 0x618a40,
    '??$shared_from@VPlayer@Network@RBX@@@RBX@@YA?AV?$shared_ptr@VPlayer@Network@RBX@@@boost@@PAVPlayer@Network@0@@Z': 0x618a40,
    '?_Incsize@?$list@UItem@SignatureDescriptor@Reflection@RBX@@V?$allocator@UItem@SignatureDescriptor@Reflection@RBX@@@std@@@std@@IAEXI@Z': 0x682cc0,
    '??__Ftype@?1???$singleton@PAVPlayers@Network@RBX@@@RefType@Reflection@RBX@@SAABV012@XZ@YAXXZ': 0x7fb7b0,
    '??__Ffoo@?1??classDescriptor@?$Described@VPlayers@Network@RBX@@$1?sPlayers@23@3PADAV?$NonFactoryProduct@VInstance@RBX@@$1?sPlayers@Network@2@3PADA@3@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ@YAXXZ': 0x7fb820,
    '__TI2?AVruntime_error@std@@': 0x8d1bc8,
    '__TI2?AVbad_cast@std@@': 0x8d362c,
}
# Descriptor objects (the `this` the dynamic initializers 007f17c0..007f1a30 pass) and other data symbols.
DATA = {
    '?sPlayers@Network@RBX@@3PADA': 0x93784c,
    '?prop_SuperSafeChat@Player@Network@RBX@@2V?$BoundProp@_N$00@Reflection@3@A': 0x96fcd4,
    '_propPlayerMaxCount': 0x97029c,
    '_func_players': 0x9702b8,
    '_func_createLocalPlayer': 0x9702f8,
    '_func_GetPlayerByID': 0x970340,
    '?propLocalPlayer@Players@Network@RBX@@2V?$RefPropDescriptor@VPlayers@Network@RBX@@VPlayer@23@@Reflection@3@A': 0x970388,
    '_propPlayerCount': 0x9703a8,
    '_func_GetPlayers': 0x9703c8,
    '_funcReportAbuse': 0x970408,
    '_func_playerFromCharacter': 0x970458,
    '_event_PlayerAdded': 0x9704a0,
    '_funcChat': 0x9704d8,
    '_event_PlayerRemoving': 0x970520,
    '_func_setAbuseReportUrl': 0x970558,
    '_func_playerFromCharacterOld': 0x9705a0,
}

# (address, symbol or unique symbol prefix)
ROWS = [
    # Players bodies
    (0x495e50, '?getMaxPlayers@' + P),
    (0x495e60, '?clientIsPresent@' + P),
    (0x495e70, '?serverIsPresent@' + P),
    (0x495f30, '?askAddChild@' + P),
    (0x496390, '?canReportAbuse@' + P),
    (0x496510, '?setConnection@' + P),
    (0x496c10, '?numPlayers@' + P),
    (0x4974c0, '?getPlayers@' + P),
    (0x497f40, '?getPlayerByID@' + P),
    (0x498030, '?playerFromCharacter@' + P),
    (0x499630, '??1' + P + 'UAE@XZ'),
    (0x499fb0, '??_G' + P + 'UAEPAXI@Z'),
    (0x499830, '??_E' + P + 'WKE@AEPAXI@Z'), (0x499840, '??_E' + P + 'WME@AEPAXI@Z'),
    (0x499850, '??_E' + P + 'WBA@AEPAXI@Z'), (0x499860, '??_E' + P + 'WBE@AEPAXI@Z'),
    (0x499870, '??_E' + P + 'WBDA@AEPAXI@Z'), (0x499880, '??_E' + P + 'WBFA@AEPAXI@Z'),
    (0x499890, '??_E' + P + 'WBHA@AEPAXI@Z'), (0x4998a0, '??_E' + P + 'WCE@AEPAXI@Z'),
    (0x4998b0, '??_E' + P + 'WEE@AEPAXI@Z'), (0x4998c0, '??_E' + P + 'WGE@AEPAXI@Z'),
    (0x4998d0, '??_E' + P + 'WIE@AEPAXI@Z'),
    (0x49ac80, '?findLocalPlayer@' + P),
    (0x49aca0, '?findLocalCharacter@' + P),
    (0x49bdc0, '??0' + P + 'QAE@XZ'),
    (0x49ca70, '?reportAbuse@' + P + 'QAEXV'),
    (0x49d450, '?setMaxPlayers@' + P),
    (0x49d480, '?createLocalPlayer@' + P),
    (0x49e1d0, '?setAbuseReportUrl@' + P),
    (0x496370, '??_GPlugin@' + P),
    (0x49df50, '?OnReceive@?$PluginInterfaceAdapter@V' + P
     + '@@UAE?AW4PluginReceiveResult@@PAVRakPeerInterface@@PAUPacket@@@Z'),
    (0x497ec0, '?onChildChanged@' + P),
    (0x49aa60, '??$?0P8' + P + 'BEPAVPlayer@12@XZH@?$RefPropDescriptor@V' + P),
    (0x4971c0, '??1AbuseReporter@Network@RBX@@QAE@XZ'),
    (0x4963c0, '??1ChatMessage@Network@RBX@@QAE@XZ'),
    # base-class template instances of the unit
    (0x495fc0, '??0' + NFP + 'QAE@XZ'),
    (0x498250, '?getClassName@' + NFP),
    (0x49af70, '??0?$DescribedNonCreatable@V' + P + 'VInstance@3@$1?sPlayers@23@3PADA@RBX@@IAE@XZ'),
    (0x49a8a0, '?classDescriptor@?$Described@V' + P + '$1?sPlayers@23@3PADAV' + NFP[:-6] + '@3@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ'),
    (0x496e20, '?raise@?$Notifier@V' + P + 'VSuperSafeChanged@3@@RBX@@IBEXVSuperSafeChanged@2@@Z'),
    (0x496870, '??$singleton@PAV' + P + '@RefType@Reflection@RBX@@SAABV012@XZ'),
    (0x4987f0, '??0?$list@VChatMessage@Network@RBX@@'),
    (0x4993c0, '??1?$list@VChatMessage@Network@RBX@@'),
    (0x496ed0, '?_Buynode@?$list@VChatMessage@Network@RBX@@'),
    (0x498a60, '?clear@?$list@VChatMessage@Network@RBX@@'),
    (0x49ad50, '??0?$CopyOnWrite@V?$vector@' + SPI),
    # descriptor constructors / functions emitted in the unit
    (0x49a910, '??$?0P8' + P + 'BEHXZH@?$PropDescriptor@V' + P + 'H@'),
    (0x49a9b0, '??$?0P8' + P + 'BEHXZP8012@AEXH@Z@?$PropDescriptor@V' + P + 'H@'),
    (0x497320, '??$getset@P8' + P + 'BEHXZ@?$PropDescriptor@V' + P + 'H@'),
    (0x497360, '??$getset@P8' + P + 'BEHXZP8123@AEXH@Z@?$PropDescriptor@V' + P + 'H@'),
    (0x49b010, '??0' + BFD + '$$A6A?AV?$shared_ptr@VInstance@RBX@@@boost@@H@Z$00@'),
    (0x49b0b0, '??$call@' + SPI + '@' + BFD + '$$A6A?AV?$shared_ptr@VInstance@RBX@@@boost@@H@Z$00@'),
    (0x49b160, '?execute@' + BFD + '$$A6A?AV?$shared_ptr@VInstance@RBX@@@boost@@H@Z$00@'),
    (0x49b230, '??0' + BFD + '$$A6AX' + STR + '@Z$00@'),
    (0x49b2d0, '?execute@' + BFD + '$$A6AX' + STR + '@Z$00@'),
    (0x49b3b0, '??0' + BFD + '$$A6AX' + SPI + STR + '@Z$01@'),
    (0x49b440, '??$call@X@' + BFD + '$$A6AX' + SPI + STR + '@Z$01@'),
    (0x49b4d0, '?execute@' + BFD + '$$A6AX' + SPI + STR + '@Z$01@'),
    (0x49b5f0, '??0' + BFD + '$$A6A?A' + VEC + 'XZ$0A@'),
    (0x49b710, '?execute@' + BFD + '$$A6A?A' + VEC + 'XZ$0A@'),
    (0x49b6b0, '??$?4' + VEC + '@any@boost@@'),
    (0x49b770, '??0' + BFD + '$$A6A?AV?$shared_ptr@VInstance@RBX@@@boost@@V45@@Z$00@'),
    (0x49b810, '??$call@' + SPI + '@' + BFD + '$$A6A?AV?$shared_ptr@VInstance@RBX@@@boost@@V45@@Z$00@'),
    (0x49b8e0, '?execute@' + BFD + '$$A6A?AV?$shared_ptr@VInstance@RBX@@@boost@@V45@@Z$00@'),
    (0x49b9b0, '??0?$SignalDesc@V' + P + '$$A6AX' + SPI + '@Z@'),
    (0x495f60, '?declareSignature@' + BFD + '$$A6AX' + SPI + STR + '@Z$01@'),
    (0x4973b0, '??$getset@P8' + P + 'BEPAVPlayer@23@XZ@?$PropDescriptor@V' + P + 'PAVPlayer@23@@'),
    (0x499cf0, '??0TSignalInstance@?$TSignalDesc@$$A6AX' + SPI + '@Z@'),
    (0x499fd0, '?newSignalInstance@?$TSignalDesc@$$A6AX' + SPI + '@Z@'),
    # dynamic initializers 007f17c0..007f1a30
    (0x7f17c0, '??__EpropPlayerCount@@YAXXZ'),
    (0x7f17f0, '??__EpropPlayerMaxCount@@YAXXZ'),
    (0x7f1830, '??__E?propLocalPlayer@' + P),
    (0x7f1860, '??__Efunc_GetPlayerByID@@YAXXZ'),
    (0x7f1890, '??__EfuncChat@@YAXXZ'),
    (0x7f18c0, '??__EfuncReportAbuse@@YAXXZ'),
    (0x7f18f0, '??__Efunc_players@@YAXXZ'),
    (0x7f1920, '??__Efunc_GetPlayers@@YAXXZ'),
    (0x7f1950, '??__Efunc_createLocalPlayer@@YAXXZ'),
    (0x7f1980, '??__Efunc_setAbuseReportUrl@@YAXXZ'),
    (0x7f19b0, '??__Efunc_playerFromCharacterOld@@YAXXZ'),
    (0x7f19e0, '??__Efunc_playerFromCharacter@@YAXXZ'),
    (0x7f1a10, '??__Eevent_PlayerAdded@@YAXXZ'),
    (0x7f1a30, '??__Eevent_PlayerRemoving@@YAXXZ'),
    # template instances whose original bodies live outside the unit range (COMDAT / ICF-shared)
    (0x48a660, '?getLocalPlayer@' + P),
    (0x4915b0, '?read@?$CopyOnWrite@V?$vector@' + SPI),
]
ATEXIT = {
    0x7f17c0: '??__FpropPlayerCount@@YAXXZ', 0x7f17f0: '??__FpropPlayerMaxCount@@YAXXZ',
    0x7f1830: '??__F?propLocalPlayer@' + P, 0x7f1860: '??__Ffunc_GetPlayerByID@@YAXXZ',
    0x7f1890: '??__FfuncChat@@YAXXZ', 0x7f18c0: '??__FfuncReportAbuse@@YAXXZ',
    0x7f18f0: '??__Ffunc_players@@YAXXZ', 0x7f1920: '??__Ffunc_GetPlayers@@YAXXZ',
    0x7f1950: '??__Ffunc_createLocalPlayer@@YAXXZ', 0x7f1980: '??__Ffunc_setAbuseReportUrl@@YAXXZ',
    0x7f19b0: '??__Ffunc_playerFromCharacterOld@@YAXXZ', 0x7f19e0: '??__Ffunc_playerFromCharacter@@YAXXZ',
    0x7f1a10: '??__Fevent_PlayerAdded@@YAXXZ', 0x7f1a30: '??__Fevent_PlayerRemoving@@YAXXZ',
}
PENDING_ROWS = [
    (0x495e80, '?frontendProcessing@' + P),                 # findServiceProvider (Service.h proposal)
    (0x495eb0, '?backendProcessing@' + P),
    (0x496cf0, '?onEvent@' + P),                            # Player::rebuildBackpack (Player.h proposal)
    (0x49dc70, '?onChildAdded@' + P),
    (0x49daa0, '?onChildRemoving@' + P),
    (0x49d200, '?fire@?$SignalDescImpl@$00$$A6AX' + SPI + '@Z@'),
    (0x49cd00, '??R?$signal1@X' + SPI),
    (0x49c4f0, '??$?RV?$slot_call_iterator@U?$caller@' + SPI),
    (0x499ed0, '?increment@?$slot_call_iterator@U?$caller@' + SPI),
    (0x4973f0, '??$?RUconnection_slot_pair@detail@signals@boost@@@?$caller@' + SPI),
    (0x496a00, '??R?$function1@X' + SPI),
]
# Rows compiled in the base object but not exact there (recorded with the reason, not counted).
NOT_EXACT = {}

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


def bind(symbol, value, where):
    prev = binding.setdefault(symbol, (value, where))
    assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), where)


def verify(obj, rows, own):
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
            bind(symbol, value, name)
            verified[symbol] = '%s (%s)' % (hex(value), how)
        result.append({'address': '%08x' % address, 'symbol': name, 'size': len(body), 'exact': True,
                       'verified_targets': verified, 'local_eh': sorted(local)})
    return result


# atexit rows: the destructor address is the immediate the initializer pushes before `call _atexit`.
ATEXIT_CALL = 0x6a17af
atexit_rows = []
for init, key in ATEXIT.items():
    body, _, _ = match.target('2008-06', '%08x' % init)
    call = max(i for i in range(len(body) - 4) if body[i] == 0xe8
               and (init + i + 5 + struct.unpack_from('<i', body, i + 1)[0]) & 0xffffffff == ATEXIT_CALL)
    push = body.rindex(b'\x68', 0, call)
    atexit_rows.append((struct.unpack_from('<I', body, push + 1)[0], key))

base_rows = resolve(base_obj, ROWS + atexit_rows)
pend_rows = resolve(pend_obj, PENDING_ROWS)
own = {}
for address, name in base_rows + pend_rows:
    assert own.setdefault(name, address) == address, (name, hex(address))
base_out = verify(base_obj, base_rows, own)
pend_out = verify(pend_obj, pend_rows, own)
for row in pend_out:  # exact only with the generated header copies: not counted as exact
    row['exact'] = False
    row['exact_pending_build_only'] = True
if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    sys.exit(0)
assert not UNBOUND, '\n'.join(UNBOUND)

# not-exact rows: present in the base object, bytes differ (recorded, not counted)
not_exact = []
base_funcs = {n: (b, r) for n, b, r in match.coff_functions(base_obj.read_bytes())}
for address, (key, reason) in NOT_EXACT.items():
    hits = [n for n in base_funcs if n == key or n.startswith(key)]
    assert len(hits) == 1, (key, hits)
    target, target_refs, _ = match.target('2008-06', '%08x' % address)
    assert not match.exact_match(target, target_refs, *base_funcs[hits[0]])
    not_exact.append({'address': '%08x' % address, 'symbol': hits[0], 'size': len(base_funcs[hits[0]][0]),
                      'target_size': len(target), 'exact': False, 'reason': reason})

# ---- vtables (base object layout), RTTI, allocation size and strings ---------------------------------
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
VT = 0x8227bc
assert original.vtable_class(VT) == ('.?AVPlayers@Network@RBX@@', 0)
STORES = {0: 0x8227bc, 0x10: 0x8227b0, 0x14: 0x8227a8, 0x20: 0x8227a0, 0x24: 0x822790, 0x44: 0x822780,
          0x64: 0x822770, 0x84: 0x822760, 0xa4: 0x822750, 0xc4: 0x822740, 0x130: 0x822730, 0x150: 0x822720,
          0x170: 0x822714}
ctor, _, _ = match.target('2008-06', '0049bdc0')
dtor, _, _ = match.target('2008-06', '00499630')
for offset, vt in STORES.items():
    assert original.vtable_class(vt) == ('.?AVPlayers@Network@RBX@@', offset), (hex(vt), offset)
    assert struct.pack('<I', vt) in ctor and struct.pack('<I', vt) in dtor, hex(vt)


def vtable_slots(obj, symbol):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    start, index = definitions[symbol]
    section = sections[index]
    slots = {}
    for i in range(section[7]):
        offset, sym, kind = struct.unpack_from('<IIH', raw, section[5] + 10 * i)
        if offset >= start and kind == 6:
            slots[(offset - start) // 4] = symbols[sym][0]
    return slots


vt_symbols = {s: v for s, (v, _) in binding.items() if s.startswith('??_7' + P + '6B')}
assert sorted(vt_symbols.values()) == sorted(STORES.values()), sorted(hex(v) for v in vt_symbols.values())
vtables = []
for symbol, vt in sorted(vt_symbols.items(), key=lambda x: x[1]):
    slots = vtable_slots(base_obj, symbol)
    assert sorted(slots) == list(range(len(slots))), (symbol, slots)
    entries = {}
    for slot, name in sorted(slots.items()):
        value = d(vt + 4 * slot)
        if name.startswith('??_E') and ('??_G' + name[4:]) in own:
            assert own['??_G' + name[4:]] == value, (symbol, slot, name, hex(value))
            how = 'own row (??_G)'
        elif name in own:
            assert own[name] == value, (symbol, slot, name, hex(value), hex(own[name]))
            how = 'own row' + (' (pending-build-only)' if name in dict((n, a) for a, n in pend_rows) else '')
        elif name in EXTERNAL:
            assert EXTERNAL[name] == value, (symbol, slot, name, hex(value))
            how = 'external'
        else:
            how = 'evidence name' if norm(names.get(value, '')) == norm(name) else 'bound (consistent across rows/slots)'
        bind(name, value, symbol)
        entries[slot] = '%s -> %s (%s)' % (name, hex(value), how)
    vtables.append({'vtable': hex(vt), 'symbol': symbol, 'rtti_offset': original.vtable_class(vt)[1], 'slots': entries})
# Primary vtable: slot 2 askAddChild, slots 7/8 onChildAdded/onChildRemoving, slot 15 onChildChanged; Listener vtable
# slot 0 onEvent (pending-build rows), slot 1 the deleting thunk.
assert (d(VT + 8), d(VT + 28), d(VT + 32), d(VT + 60)) == (0x495f30, 0x49dc70, 0x49daa0, 0x497ec0)
assert (d(0x822714), d(0x822714 + 4)) == (0x496cf0, 0x499890)
locator = d(VT - 4)
hierarchy = d(locator + 16)
items = [d(d(hierarchy + 12) + 4 * i) for i in range(d(hierarchy + 8))]
bases = {original.string(d(item) + 8): struct.unpack('<i', original.data(item + 8, 4))[0] for item in items}
assert bases['.?AV?$Notifier@VPlayers@Network@RBX@@VChatMessage@23@@RBX@@'] == 0x130, bases
assert bases['.?AV?$Notifier@VPlayers@Network@RBX@@VSuperSafeChanged@3@@RBX@@'] == 0x150, bases
assert bases['.?AV?$Listener@VPlayer@Network@RBX@@UCharacterAdded@23@@RBX@@'] == 0x170, bases
assert bases['.?AVService@RBX@@'] == 0x174, bases
assert '.?AV?$DescribedNonCreatable@VPlayers@Network@RBX@@VInstance@3@$1?sPlayers@23@3PADA@RBX@@' in bases, bases
body, _, _ = match.target('2008-06', '00411fd0')
assert b'\x68' + struct.pack('<I', 0x1b0) in body
assert original.string(0x93784c) == 'Players'
for address, text in ((0x8194d0, 'Players'), (0x822b70, 'NumPlayers'), (0x822490, 'Data'), (0x822b7c, 'MaxPlayers'),
                      (0x822b88, 'LocalPlayer'), (0x822b94, 'GetPlayerByID'), (0x822708, 'userID'), (0x822ba4, 'Chat'),
                      (0x82256c, 'message'), (0x8172f4, 'ReportAbuse'), (0x822bac, 'player'), (0x822bb4, 'players'),
                      (0x822bbc, 'GetPlayers'), (0x822bc8, 'CreateLocalPlayer'), (0x8224ac, 'userId'),
                      (0x822bdc, 'SetAbuseReportUrl'), (0x80f08c, 'url'), (0x822bf0, 'playerFromCharacter'),
                      (0x822c04, 'character'), (0x822c10, 'GetPlayerFromCharacter'), (0x822c28, 'PlayerAdded'),
                      (0x822c34, 'PlayerRemoving'), (0x822af4, 'Local player already exists'),
                      (0x821cac, 'rebuildBackpack can only be called by the backend server')):
    assert original.string(address) == text, (hex(address), text)
for throw_info, cls in ((0x8d362c, '.?AVbad_cast@std@@'), (0x8d1bc8, '.?AVruntime_error@std@@')):
    cta = d(throw_info + 12)
    assert original.string(d(d(cta + 4) + 4) + 8) == cls, (hex(throw_info), cls)

sha = nb.sha
paths = [Path(__file__).resolve(), HEADER, SRC, LAYOUT, PEERS_STANDIN, MODEL_STANDIN]
exact_addresses = sorted({r['address'] for r in base_out})
pending_addresses = sorted({r['address'] for r in pend_out} - set(exact_addresses))
receipt = {
    'class': 'RBX::Network::Players', 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': {'layout': layout_flags, 'base': base_flags, 'pending': pend_flags},
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in (layout_obj, base_obj, pend_obj)},
    'layout': 'Players 0x1b0 (ServiceProvider::create<Players> 00411fd0); Notifier<Players,ChatMessage> 0x130, '
              'Notifier<Players,SuperSafeChanged> 0x150, Listener<Player,CharacterAdded> 0x170, Service 0x174; '
              'abuseReporter +0x174, chatHistory +0x178, plugin +0x194, players +0x198, localPlayer +0x1a0, peer +0x1a8, '
              'maxPlayers +0x1ac; ChatMessage 0x48 (time +0x00, message +0x1c, source +0x38, destination +0x40)',
    'methods': base_out, 'pending_methods': pend_out, 'not_exact': not_exact, 'vtables': vtables,
    'exact_distinct_addresses': exact_addresses, 'pending_only_addresses': pending_addresses,
    'pending_note': 'pending rows are exact only with generated copies of other owners\' headers (proposals); not counted.',
    'proposals': [p[4] for p in PROPOSALS],
    'standins_note': 'base build uses declaration-only stand-ins for "Client.h"/"Server.h" (tests/NativeNetworkPlayersPeers.h) '
                     'and v8datamodel/ModelInstance.h (tests/NativeTeamPendingModel.h).',
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/network-players-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native Network::Players: %d exact rows (%d distinct addresses), %d pending-build-only, %d not exact; %d vtables; '
      'targets verified' % (len(base_out), len(exact_addresses), len(pend_out), len(not_exact), len(vtables)))
