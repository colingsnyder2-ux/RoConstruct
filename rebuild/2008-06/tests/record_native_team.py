"""Verify the inactive native RBX::Team / RBX::Teams recovery (2008-06).

Builds (document-swap flags, VS2008 RTM 21022):
  * tests/NativeTeamLayout.cpp      sizeof/offset probes (mov eax, imm32; ret);
  * native-classes/Team.cpp         whole Team unit (00565e00..00566720, initializers 007f3240..007f3300,
                                    atexit 007fcfd0..007fd050) plus Team template instances folded elsewhere;
  * native-classes/Teams.cpp        Teams unit, including the Player-dependent bodies against the native
                                    Network/Player.h and Network/Players.h, without getTeamColorForHumanoid;
  * Teams.cpp with NATIVE_TEAMS_PENDING against generated headers in out/native-team-pending/:
    declaration-only Humanoid/ModelInstance overlays (tests/NativeTeamPendingHumanoid.h,
    tests/NativeTeamPendingModel.h) and a copy of native-headers/v8tree/Instance.h with the
    proposed Instance::findFirstChildOfType<Type>() (PROPOSAL below; shared header not edited).

Every row must be relocation-masked exact against the original, and every relocation target is bound
to the address the original instruction uses and verified: imports by DLL export / mfc ordinal name,
string literals by bytes, type descriptors and vtables by original RTTI names, own symbols by the row
proven here, and the remaining externals by the explicit EXTERNAL map (call sites read in the original
disassembly; names from offline/evidence.json where available). A symbol must bind to one address in
every row. Writes work/2008-06/shared-layouts/team-working.json.
"""
import hashlib
import json
import re
import shutil
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
TEAM_SRC = R / 'native-classes/Team.cpp'
TEAMS_SRC = R / 'native-classes/Teams.cpp'
TEAM_H = R / 'native-headers/v8datamodel/Team.h'
TEAMS_H = R / 'native-headers/v8datamodel/Teams.h'
LAYOUT = R / 'tests/NativeTeamLayout.cpp'
PLAYER_H = R / 'native-headers/Network/Player.h'
PLAYERS_H = R / 'native-headers/Network/Players.h'
HUMANOID_OVERLAY = R / 'tests/NativeTeamPendingHumanoid.h'
MODEL_OVERLAY = R / 'tests/NativeTeamPendingModel.h'

# Proposed declaration for native-headers/v8tree/Instance.h (shared, not edited here): the original
# emits the Humanoid instance 005d5f40 in the Teams unit (getTeamColorForHumanoid 005d6180 calls it
# with ecx = player character), the same body as the donor v8tree/Instance.h member template.
PROPOSAL_ANCHOR = '    void setParent(Instance*);\n'
PROPOSAL = '''    template<class Type> Type* findFirstChildOfType() const // e.g. 005d5f40 (Humanoid)
    {
        if (children)
        {
            std::vector<boost::shared_ptr<Instance> >::const_iterator end = children->end();
            std::vector<boost::shared_ptr<Instance> >::const_iterator iter = children->begin();
            for (; iter != end; iter++)
            {
                if (Type* result = dynamic_cast<Type*>((*iter).get()))
                    return result;
            }
        }
        return NULL;
    }
'''

pending = OUT / 'native-team-pending'
for sub in ('humanoid', 'v8tree', 'v8datamodel'):
    (pending / sub).mkdir(parents=True, exist_ok=True)
shutil.copyfile(HUMANOID_OVERLAY, pending / 'humanoid/Humanoid.h')
shutil.copyfile(MODEL_OVERLAY, pending / 'v8datamodel/ModelInstance.h')
instance_text = (R / 'native-headers/v8tree/Instance.h').read_text()
assert instance_text.count('Type* findFirstChildOfType() const') == 1
(pending / 'v8tree/Instance.h').write_text(instance_text)


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeTeamLayout', LAYOUT)
team_obj, team_flags = build('NativeTeam', TEAM_SRC)
teams_obj, teams_flags = build('NativeTeams', TEAMS_SRC)
pend_obj, pend_flags = build('NativeTeamsPending', TEAMS_SRC, ['/I' + str(pending), '/DNATIVE_TEAMS_PENDING'])

# ---- layout ---------------------------------------------------------------------------------------
raw = layout_obj.read_bytes()
for prefix, value in (('?nativeTeamSize@@', 0x13c), ('?nativeTeamsSize@@', 0x138), ('?nativeInstanceSize@@', 0x130)):
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    assert body == b'\xb8' + struct.pack('<I', value) + b'\xc3', (prefix, body.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}


def norm(symbol):
    return symbol.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


# ---- externals: address the original instruction uses, read at the call sites listed ----------------
EXTERNAL = {
    '??0Instance@RBX@@QAE@XZ': 0x55b7e0,                       # FactoryProduct ctors 00565ec0 / 005d5be0
    '??1Instance@RBX@@UAE@XZ': 0x55a540,                       # FactoryProduct dtors (tail jmp)
    '?setName@Instance@RBX@@UAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': 0x55af90,
    '?raisePropertyChanged@Instance@RBX@@QAEXABVPropertyDescriptor@Reflection@2@@Z': 0x40db00,
    '?numChildren@Instance@RBX@@QBEIXZ': 0x48ae20,
    '___RTDynamicCast': 0x6a17c6, '_atexit': 0x6a17af,
    '??2@YAPAXI@Z': 0x6a0920, '??3@YAXPAX@Z': 0x6a067a,
    '?declare@Name@RBX@@SAABV12@PBDH@Z': 0x553f90,              # doDeclare 004067e0
    '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330,               # getClassName 00566190 / 005d5fe0
    '??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z': 0x5708f0,
    '??1ClassDescriptor@Reflection@RBX@@UAE@XZ': 0x40abc0,
    '?classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3QBDBVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ': 0x40ad80,
    # TypedPropertyDescriptor<T> constructors called by the PropDescriptor/BoundProp ctors 00566220..00566430
    '??0?$TypedPropertyDescriptor@H@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@H@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x4432a0,
    '??0?$TypedPropertyDescriptor@VBrickColor@RBX@@@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@VBrickColor@RBX@@@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x48b180,
    '??0?$TypedPropertyDescriptor@_N@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@_N@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x40a290,
    # Teams: CopyOnWrite / vector / reflection helpers (call sites in 005d6850, 005d5ed0, 005d6340, 005d6400, 005d6610..005d67f0)
    '??0?$CopyOnWrite@V?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@@RBX@@QAE@ABV?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@@Z': 0x49ad50,
    '??1?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@QAE@XZ': 0x5a2fe0,
    '?write@?$CopyOnWrite@V?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@@RBX@@QAEAAV?$shared_ptr@V?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@@boost@@XZ': 0x49add0,
    '?read@?$CopyOnWrite@V?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@@RBX@@QBE?AV?$shared_ptr@$$CBV?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@@boost@@XZ': 0x4915b0,
    '??$shared_from@VInstance@RBX@@@RBX@@YA?AV?$shared_ptr@VInstance@RBX@@@boost@@PAVInstance@0@@Z': 0x618a40,
    '?push_back@?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@QAEXABV?$shared_ptr@VInstance@RBX@@@boost@@@Z': 0x420110,
    '?erase@?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@QAE?AV?$_Vector_iterator@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@2@V?$_Vector_const_iterator@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@2@@Z': 0x439480,
    '??$?4V?$shared_ptr@$$CBV?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@@boost@@@any@boost@@QAEAAV01@ABV?$shared_ptr@$$CBV?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@@1@@Z': 0x49b6b0,  # BoundFuncDesc::call 005d6750
    '??1?$list@UItem@SignatureDescriptor@Reflection@RBX@@V?$allocator@UItem@SignatureDescriptor@Reflection@RBX@@@std@@@std@@QAE@XZ': 0x4199e0,  # atexit 007ff220 / 007ff260
    '__TI2?AVbad_cast@std@@': 0x8d362c,  # execute 005d6680 / 005d67f0 throw; catchable type checked below
    '??0FunctionDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBDW4Security@012@@Z': 0x595790,
    '??$singleton@X@Type@Reflection@RBX@@SAABV012@XZ': 0x594a50,
    '??$singleton@V?$shared_ptr@$$CBV?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@@boost@@@Type@Reflection@RBX@@SAABV012@XZ': 0x56cb50,
    # Player-dependent bodies (pending build): Player setters, ServiceProvider lookup, Color3/BrickColor
    '?setTeamColor@Player@Network@RBX@@QAEXVBrickColor@3@@Z': 0x494600,
    '?setNeutral@Player@Network@RBX@@QAEX_N@Z': 0x494620,
    '??$find@VPlayers@Network@RBX@@@ServiceProvider@RBX@@SAPAVPlayers@Network@1@PBVInstance@1@@Z': 0x491d50,
    '?color3@BrickColor@RBX@@QBE?AVColor3@G3D@@XZ': 0x5b6270,
    '?white@Color3@G3D@@SAABV12@XZ': 0x514a60,
}
# Descriptor objects: the `this` the dynamic initializers 007f3240..007f3300 / 007f6270 / 007f62a0 pass.
DATA = {
    '?prop_Score@RBX@@3V?$PropDescriptor@VTeam@RBX@@H@Reflection@2@A': 0x9748cc,
    '?prop_Color@RBX@@3V?$PropDescriptor@VTeam@RBX@@VBrickColor@2@@Reflection@2@A': 0x974904,
    '?prop_AutoAssignable@RBX@@3V?$PropDescriptor@VTeam@RBX@@_N@Reflection@2@A': 0x9748b0,
    '?prop_AutoColorCharacters@Team@RBX@@2V?$BoundProp@_N$00@Reflection@2@A': 0x9748e8,
    '?teams_rebalanceTeamsFunction@RBX@@3V?$BoundFuncDesc@VTeams@RBX@@$$A6AXXZ$0A@@Reflection@2@A': 0x97a1c8,
    '?func_teams@RBX@@3V?$BoundFuncDesc@VTeams@RBX@@$$A6A?AV?$shared_ptr@$$CBV?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@@boost@@XZ$0A@@Reflection@2@A': 0x97a208,
    '_prop_Score': 0x9748cc, '_prop_Color': 0x974904, '_prop_AutoAssignable': 0x9748b0,   # file statics
    '_teams_rebalanceTeamsFunction': 0x97a1c8, '_func_teams': 0x97a208,
    '?sTeam@RBX@@3QBDB': 0x82e8e8,       # "Team" (also pushed by doDeclare 004067e0)
    '?sTeams@RBX@@3QBDB': 0x83cd08,      # "Teams"
}
# ICF / trivial-wrapper folds: the original keeps one body where this unit emits several identical ones.
FOLDED = {
    # DescribedCreatable/Described destructors are empty; their deleting dtors and thunks fold into the
    # FactoryProduct ones (00565f30 / 005d65f0), and the wrappers' dtor calls resolve to the FactoryProduct dtor.
    '??1?$DescribedCreatable@VTeam@RBX@@VInstance@2@$1?sTeam@2@3QBDB@RBX@@UAE@XZ': 0x565f80,
    '??1?$DescribedCreatable@VTeams@RBX@@VInstance@2@$1?sTeams@2@3QBDB@RBX@@UAE@XZ': 0x5d5c80,
    '??_G?$DescribedCreatable@VTeam@RBX@@VInstance@2@$1?sTeam@2@3QBDB@RBX@@UAEPAXI@Z': 0x565f30,
    '??_G?$DescribedCreatable@VTeams@RBX@@VInstance@2@$1?sTeams@2@3QBDB@RBX@@UAEPAXI@Z': 0x5d65f0,
    # Teams::rebalanceTeams is an empty body folded with the shared `ret` at 0047d410.
    '?rebalanceTeams@Teams@RBX@@QAEXXZ': 0x47d410,
}

FPT = '?$FactoryProduct@VTeam@RBX@@VInstance@2@$1?sTeam@2@3QBDB@RBX@@'
DCT = '?$DescribedCreatable@VTeam@RBX@@VInstance@2@$1?sTeam@2@3QBDB@RBX@@'
DST = '?$Described@VTeam@RBX@@$1?sTeam@2@3QBDBV' + FPT[:-6] + '@2@@Reflection@RBX@@'
FPS = '?$FactoryProduct@VTeams@RBX@@VInstance@2@$1?sTeams@2@3QBDB@RBX@@'
DCS = '?$DescribedCreatable@VTeams@RBX@@VInstance@2@$1?sTeams@2@3QBDB@RBX@@'
DSS = '?$Described@VTeams@RBX@@$1?sTeams@2@3QBDBV' + FPS[:-6] + '@2@@Reflection@RBX@@'
GS_I = '?$GetSetImpl@P8Team@RBX@@BEHXZP812@AEXH@Z@?$PropDescriptor@VTeam@RBX@@H@Reflection@RBX@@'
GS_C = '?$GetSetImpl@P8Team@RBX@@BE?AVBrickColor@2@XZP812@AEXV32@@Z@?$PropDescriptor@VTeam@RBX@@VBrickColor@2@@Reflection@RBX@@'
GS_B = '?$GetSetImpl@P8Team@RBX@@BE_NXZP812@AEX_N@Z@?$PropDescriptor@VTeam@RBX@@_N@Reflection@RBX@@'
BP_B = '?$BoundPropGetSet@VTeam@RBX@@@?$BoundProp@_N$00@Reflection@RBX@@'

# (address, symbol or unique symbol prefix)
TEAM_ROWS = [
    (0x565e00, '?askSetParent@Team@RBX@@UBE_NPBVInstance@2@@Z'),
    (0x565e30, '?getScore@Team@RBX@@QBEHXZ'),
    (0x565e40, '?getTeamColor@Team@RBX@@QBE?AVBrickColor@2@XZ'),
    (0x565e50, '?getAutoAssignable@Team@RBX@@QBE_NXZ'),
    (0x565e60, '??1' + FPT + 'MAE@XZ'),
    (0x565ec0, '??0' + FPT + 'IAE@XZ'),
    (0x565f20, '??_E' + FPT + 'OBE@AEPAXI@Z'),
    (0x565f30, '??_G' + FPT + 'MAEPAXI@Z'),
    (0x565f50, '??_E' + FPT + 'OKE@AEPAXI@Z'),
    (0x565f60, '??_E' + FPT + 'OME@AEPAXI@Z'),
    (0x565f70, '??_E' + FPT + 'OBA@AEPAXI@Z'),
    (0x565f80, '??1' + DST + 'UAE@XZ'),
    (0x565f90, '??1Team@RBX@@UAE@XZ'),
    (0x565ff0, '?askAddChild@Team@RBX@@UBE_NPBVInstance@2@@Z'),
    (0x566000, '??_ETeam@RBX@@WCE@AEPAXI@Z'), (0x566010, '??_ETeam@RBX@@WEE@AEPAXI@Z'),
    (0x566020, '??_ETeam@RBX@@WGE@AEPAXI@Z'), (0x566030, '??_ETeam@RBX@@WIE@AEPAXI@Z'),
    (0x566040, '??_ETeam@RBX@@WKE@AEPAXI@Z'), (0x566050, '??_ETeam@RBX@@WME@AEPAXI@Z'),
    (0x566060, '??_ETeam@RBX@@WBA@AEPAXI@Z'), (0x566070, '??_ETeam@RBX@@WBE@AEPAXI@Z'),
    (0x566080, '??$getset@P8Team@RBX@@BEHXZ'),
    (0x5660d0, '??$getset@P8Team@RBX@@BE?AVBrickColor@'),
    (0x566120, '??$getset@P8Team@RBX@@BE_NXZ'),
    (0x566170, '??_GTeam@RBX@@UAEPAXI@Z'),
    (0x566190, '?getClassName@' + FPT + 'UBEABVName@2@XZ'),
    (0x5661b0, '?classDescriptor@' + DST + 'SAAAVClassDescriptor@23@XZ'),
    (0x566220, '??$?0P8Team@RBX@@BEHXZ'),
    (0x5662d0, '??$?0P8Team@RBX@@BE?AVBrickColor@'),
    (0x566380, '??$?0P8Team@RBX@@BE_NXZ'),
    (0x566430, '??$?0VTeam@RBX@@@?$BoundProp@_N$00@'),
    (0x566500, '??0' + DCT + 'IAE@XZ'),
    (0x5665a0, '??_E' + DCT + 'WEE@AEPAXI@Z'), (0x5665b0, '??_E' + DCT + 'WGE@AEPAXI@Z'),
    (0x5665c0, '??_E' + DCT + 'WIE@AEPAXI@Z'), (0x5665d0, '??_E' + DCT + 'WCE@AEPAXI@Z'),
    (0x5665e0, '??0Team@RBX@@QAE@XZ'),
    (0x5666d0, '?setScore@Team@RBX@@QAEXH@Z'),
    (0x566700, '?setTeamColor@Team@RBX@@QAEXVBrickColor@2@@Z'),
    (0x566720, '?setAutoAssignable@Team@RBX@@QAEX_N@Z'),
    (0x7f3240, '??__Eprop_Score@RBX@@YAXXZ'),
    (0x7f3280, '??__Eprop_Color@RBX@@YAXXZ'),
    (0x7f32c0, '??__Eprop_AutoAssignable@RBX@@YAXXZ'),
    (0x7f3300, '??__E?prop_AutoColorCharacters@Team@RBX@@'),
    (0x7fcfd0, '??__F?prop_AutoColorCharacters@Team@RBX@@'),
    (0x7fcff0, '??__Fprop_AutoAssignable@RBX@@YAXXZ'),
    (0x7fd010, '??__Fprop_Color@RBX@@YAXXZ'),
    (0x7fd030, '??__Fprop_Score@RBX@@YAXXZ'),
    (0x7fd050, '??__Ffoo@?1??classDescriptor@' + DST),
    # Team template instances whose original bodies live outside the unit (COMDAT / ICF-shared)
    (0x4067e0, '??$doDeclare@$1?sTeam@RBX@@3QBDB@Name@RBX@@CAABV01@XZ'),
    (0x406ea0, '??$callDoDeclare@$1?sTeam@RBX@@3QBDB@Name@RBX@@CAXXZ'),
    (0x60a2f0, '?isReadOnly@' + GS_I + 'UBE_NXZ'),
    (0x60a2f0, '?isReadOnly@' + GS_C + 'UBE_NXZ'),
    (0x60a2f0, '?isReadOnly@' + GS_B + 'UBE_NXZ'),
    (0x60a2f0, '?isReadOnly@' + BP_B + 'UBE_NXZ'),
    (0x5cf660, '?getValue@' + GS_I),
    (0x5cf660, '?getValue@' + GS_B),
    (0x445370, '?getValue@' + GS_C),
    (0x563b00, '?setValue@' + GS_I),
    (0x563b00, '?setValue@' + GS_C),
    (0x48abf0, '?setValue@' + GS_B),
    (0x443190, '?getValue@' + BP_B),
    (0x63dd00, '?setValue@' + BP_B),
]
TEAMS_ROWS = [
    (0x5d5b80, '??1' + FPS + 'MAE@XZ'),
    (0x5d5be0, '??0' + FPS + 'IAE@XZ'),
    (0x5d5c40, '??_E' + FPS + 'OCE@AEPAXI@Z'), (0x5d5c50, '??_E' + FPS + 'OEE@AEPAXI@Z'),
    (0x5d5c60, '??_E' + FPS + 'OGE@AEPAXI@Z'), (0x5d5c70, '??_E' + FPS + 'OME@AEPAXI@Z'),
    (0x5d5c80, '??1' + DSS + 'UAE@XZ'),
    (0x5d5c90, '??1Teams@RBX@@UAE@XZ'),
    (0x5d5d60, '?askAddChild@Teams@RBX@@UBE_NPBVInstance@2@@Z'),
    (0x5d5d90, '??_ETeams@RBX@@WCE@AEPAXI@Z'), (0x5d5da0, '??_ETeams@RBX@@WEE@AEPAXI@Z'),
    (0x5d5db0, '??_ETeams@RBX@@WGE@AEPAXI@Z'), (0x5d5dc0, '??_ETeams@RBX@@WIE@AEPAXI@Z'),
    (0x5d5dd0, '??_ETeams@RBX@@WKE@AEPAXI@Z'), (0x5d5de0, '??_ETeams@RBX@@WME@AEPAXI@Z'),
    (0x5d5df0, '??_ETeams@RBX@@WBA@AEPAXI@Z'), (0x5d5e00, '??_ETeams@RBX@@WBE@AEPAXI@Z'),
    (0x5d5e10, '?getTeamFromTeamColor@Teams@RBX@@QAEPAVTeam@2@VBrickColor@2@@Z'),
    (0x5d5ed0, '?getTeams@Teams@RBX@@'),
    (0x5d5f00, '??_GTeams@RBX@@UAEPAXI@Z'),
    (0x5d5f20, '?teamExists@Teams@RBX@@QAE_NVBrickColor@2@@Z'),
    (0x5d5fe0, '?getClassName@' + FPS + 'UBEABVName@2@XZ'),
    (0x5d6000, '?classDescriptor@' + DSS + 'SAAAVClassDescriptor@23@XZ'),
    (0x5d6340, '?onChildAdded@Teams@RBX@@MAEXPAVInstance@2@@Z'),
    (0x5d6400, '?onChildRemoving@Teams@RBX@@MAEXPAVInstance@2@@Z'),
    (0x5d6510, '??0' + DCS + 'IAE@XZ'),
    (0x5d65b0, '??_E' + FPS + 'OBA@AEPAXI@Z'), (0x5d65c0, '??_E' + FPS + 'OBE@AEPAXI@Z'),
    (0x5d65d0, '??_E' + FPS + 'OIE@AEPAXI@Z'), (0x5d65e0, '??_E' + FPS + 'OKE@AEPAXI@Z'),
    (0x5d65f0, '??_G' + FPS + 'MAEPAXI@Z'),
    (0x5d6610, '??0?$BoundFuncDesc@VTeams@RBX@@$$A6AXXZ$0A@@'),
    (0x5d6680, '?execute@?$BoundFuncDesc@VTeams@RBX@@$$A6AXXZ$0A@@'),
    (0x5d66e0, '??0?$BoundFuncDesc@VTeams@RBX@@$$A6A?AV?$shared_ptr@'),
    (0x5d6750, '??$call@V?$shared_ptr@$$CBV?$vector@'),
    (0x5d67f0, '?execute@?$BoundFuncDesc@VTeams@RBX@@$$A6A?AV?$shared_ptr@'),
    (0x5d6850, '??0Teams@RBX@@QAE@XZ'),
    (0x7f6270, '??__Eteams_rebalanceTeamsFunction@RBX@@YAXXZ'),
    (0x7f62a0, '??__Efunc_teams@RBX@@YAXXZ'),
    (0x7ff210, '??__Ffoo@?1??classDescriptor@' + DSS),
    (0x7ff220, '??__Ffunc_teams@RBX@@YAXXZ'),
    (0x7ff260, '??__Fteams_rebalanceTeamsFunction@RBX@@YAXXZ'),
    (0x48a1e0, '??$doDeclare@$1?sTeams@RBX@@3QBDB@Name@RBX@@CAABV01@XZ'),
    (0x48ab40, '??$callDoDeclare@$1?sTeams@RBX@@3QBDB@Name@RBX@@CAXXZ'),
    # Player-dependent bodies, built against the native Network/Player.h and Network/Players.h
    (0x5d5ea0, '?getTeamFromPlayer@Teams@RBX@@'),
    (0x5d6070, '?isTeamGame@Teams@RBX@@QAE_NXZ'),
    (0x5d60f0, '?getNumPlayersInTeam@Teams@RBX@@QAEHVBrickColor@2@@Z'),
    (0x5d6250, '?assignNewPlayerToTeam@Teams@RBX@@'),
]
PENDING_ROWS = [
    (0x5d5f40, '??$findFirstChildOfType@VHumanoid@RBX@@@Instance@RBX@@'),
    (0x5d6180, '?getTeamColorForHumanoid@Teams@RBX@@'),
]

LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
binding = {}   # symbol -> (address, row) for the one-address-per-symbol check


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


def verify(obj, rows, own):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    result = []
    for address, name in rows:
        body, refs = bodies[name]
        target, target_refs, _ = match.target('2008-06', '%08x' % address)
        assert match.exact_match(target, target_refs, body, refs), (name, hex(address), len(body), len(target))
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
                # vector deleting dtor reference: no array new of the class, so the weak ??_E
                # resolves to the scalar deleting destructor ??_G
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
            elif symbol.startswith('??_B?1??') or symbol.startswith('?$S') or '?$TSS' in symbol or symbol.startswith('?flag@') or symbol.startswith('?foo@') \
                    or symbol.startswith('?n@') or symbol.startswith('?root@'):
                # function-local statics / guards: bound by address, checked for consistency below
                how = 'local static'
            else:
                UNBOUND.append('%s in %s -> %s' % (symbol, name, hex(value)))
                continue
            prev = binding.setdefault(symbol, (value, name))
            assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
            verified[symbol] = '%s (%s)' % (hex(value), how)
        result.append({'address': '%08x' % address, 'symbol': name, 'size': len(body), 'exact': True,
                       'verified_targets': verified, 'local_eh': sorted(local)})
    return result


team_rows = resolve(team_obj, TEAM_ROWS)
teams_rows = resolve(teams_obj, TEAMS_ROWS)
pend_rows = resolve(pend_obj, PENDING_ROWS)
own = {}
for address, name in team_rows + teams_rows + pend_rows:
    own.setdefault(name, address)
# rows sharing one address (ICF) are listed under each instance symbol; own keeps the first
team_out = verify(team_obj, team_rows, own)
teams_out = verify(teams_obj, teams_rows, own)
pend_out = verify(pend_obj, pend_rows, own)
for row in pend_out:  # exact only under NATIVE_TEAMS_PENDING with the overlays: not counted as exact
    row['exact'] = False
    row['exact_pending_build_only'] = True
assert not UNBOUND, '\n'.join(UNBOUND)

# ---- vtables, RTTI, allocation sizes and strings ------------------------------------------------------
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
assert original.vtable_class(0x82ea84) == ('.?AVTeam@RBX@@', 0)
assert original.vtable_class(0x83ce54) == ('.?AVTeams@RBX@@', 0)
assert (d(0x82ea84 + 8), d(0x82ea84 + 12)) == (0x565ff0, 0x565e00)          # askAddChild, askSetParent
assert (d(0x83ce54 + 8), d(0x83ce54 + 28), d(0x83ce54 + 32)) == (0x5d5d60, 0x5d6340, 0x5d6400)
for factory, size, ctor in ((0x409140, 0x13c, 0x5665e0), (0x490450, 0x138, 0x5d6850)):
    body, _, _ = match.target('2008-06', '%08x' % factory)
    assert b'\x68' + struct.pack('<I', size) in body
    call = body.index(b'\xe8', body.index(b'\x68' + struct.pack('<I', size)) + 5)
    while (factory + call + 5 + struct.unpack_from('<i', body, call + 1)[0]) & 0xffffffff != ctor:
        call = body.index(b'\xe8', call + 1)
for address, text in ((0x82e8e8, 'Team'), (0x83cd08, 'Teams'), (0x82ec24, 'Score'), (0x822548, 'TeamColor'),
                      (0x82ec2c, 'AutoAssignable'), (0x82ec3c, 'AutoColorCharacters'), (0x822490, 'Data'),
                      (0x83cf6c, 'RebalanceTeams'), (0x83cf7c, 'GetTeams')):
    assert original.string(address) == text, (hex(address), text)
# ThrowInfo 008d362c (BoundFuncDesc::execute) first catchable type is std::bad_cast.
cta = d(0x8d362c + 12)
assert original.string(d(d(cta + 4) + 4) + 8) == '.?AVbad_cast@std@@'
# Teams has Service as an empty base at 0x130 (RTTI), sharing the offset with the CopyOnWrite member.
locator = d(0x83ce54 - 4)
hierarchy = d(locator + 16)
items = [d(d(hierarchy + 12) + 4 * i) for i in range(d(hierarchy + 8))]
bases = {original.string(d(item) + 8): struct.unpack('<i', original.data(item + 8, 4))[0] for item in items}
assert bases['.?AVService@RBX@@'] == 0x130, bases

sha = nb.sha
paths = [Path(__file__).resolve(), TEAM_H, TEAMS_H, TEAM_SRC, TEAMS_SRC, LAYOUT, PLAYER_H, PLAYERS_H, HUMANOID_OVERLAY, MODEL_OVERLAY]
receipt = {
    'class': 'RBX::Team, RBX::Teams', 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': {'layout': layout_flags, 'team': team_flags, 'teams': teams_flags, 'pending': pend_flags},
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in (layout_obj, team_obj, teams_obj, pend_obj)},
    'layout': {'Team': '0x13c (Creatable<Instance>::create<Team> 00409140); score +0x130, color +0x134, autoAssignable +0x138, autoColorCharacters +0x139',
               'Teams': '0x138 (00490450); Service empty base and CopyOnWrite<vector<shared_ptr<Instance>>> teams at +0x130'},
    'team_methods': team_out, 'teams_methods': teams_out,
    'pending_methods': pend_out,
    'pending_note': 'NATIVE_TEAMS_PENDING bodies are exact only with the generated headers in out/native-team-pending: '
                    'Instance::findFirstChildOfType<Type>() added to a copy of native-headers/v8tree/Instance.h (proposal), '
                    'and declaration-only Humanoid/ModelInstance overlays; Network::Player/Players use the native headers.',
    'proposal_instance_h': PROPOSAL,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/team-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native Team/Teams: %d Team rows, %d Teams rows, %d pending rows exact, targets verified'
      % (len(team_out), len(teams_out), len(pend_out)))
