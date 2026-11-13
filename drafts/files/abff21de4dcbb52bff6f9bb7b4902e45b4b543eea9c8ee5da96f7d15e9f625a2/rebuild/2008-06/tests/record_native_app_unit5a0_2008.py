"""Verify the inactive 2008-06 native rows of the application range 005a0000..005ac000, and record the unit map of the
range (boundary evidence in the receipt's `unit_map`; rows counted by other receipts are listed there).

Unit map summary (details in UNIT_MAP below):
  * SpecialShape unit tail ..005a012f (special-shape owner; not built here).
  * Workspace unit 005a0140..005a6baf (v8datamodel/Workspace.cpp): built here from
    native-classes/AppUnit5A0_2008Workspace.cpp against the committed native v8datamodel/Workspace.h (read-only).
  * Log unit 005a6bb0..005a76ff (leaves2008 owner), FileSystem / VistaAPIs 005a7770..005a80cf, Guid 005a80d0..005a858f,
    ScriptContext unit 005a8590..005ab06f and Lua bridge templates 005ab070.. (LuaBridge / ScriptContext owners).

Build: document-swap flags, VS2008 RTM 21022, /U_RELEASEASSERT (see `rejected`). No pending build: no body needs a
missing shared declaration. Vtable / RTTI checks use the object built from the current headers.

Every counted row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the
address the original instruction uses and verified: imports by DLL export name, constants and string literals by
bytes, RTTI type descriptors by name, vtables by the complete-object locator class, own symbols by the row proven
here, COMDAT support bodies by exactness at the bound address, the remaining externals by the explicit EXTERNAL map
(evidence name or a row counted by another receipt), data by bytes, local statics by one address per symbol.
A row is counted only when no other receipt counts it (top-level exact_function_rows, or exact_addresses /
exact_unique_addresses / exact method entries for older receipts).
Writes work/2008-06/shared-layouts/app-unit5a0-2008-working.json.
Set NATIVE_APP_UNIT5A0_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
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
OUT = nb.OUT / 'app-unit5a0-2008'
OUT.mkdir(parents=True, exist_ok=True)
SOURCES = {
    'workspace': R / 'native-classes/AppUnit5A0_2008Workspace.cpp',
}
UNIT = {'workspace': ['/U_RELEASEASSERT']}
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT5A0_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit5a0-2008-working.json'


def build(name, src, extra=(), include_first=()):
    obj = OUT / (name + '.obj')
    flags = list(include_first) + nb.flags() + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


OBJ, FLAGS = {}, {}
for key, src in SOURCES.items():
    OBJ[key], FLAGS[key] = build('NativeAppUnit5A0_2008_' + key, src, UNIT[key])

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}

# ---- externals: address the original instruction uses -------------------------------------------------------------
EXTERNAL = {
    # evidence names
    '??0NewNullTool@RBX@@QAE@PAVWorkspace@1@@Z': 0x618160,                                 # newNullTool 005a02b6
    '??0MouseCommand@RBX@@IAE@PAVWorkspace@1@@Z': 0x6159f0,                                # ArrowTool() inlined (005a04ec / 005a2024)
    '??0RootInstance@RBX@@IAE@XZ': 0x591580,                                               # NonFactoryProduct() 005a07d9
    '?addScript@ScriptContext@RBX@@QAEXPAVScript@2@@Z': 0x5b06c0,                          # runScript 005a27a9
    '?autoMode@Camera@RBX@@QAEXXZ': 0x5cc450,                                              # stop 005a027a
    '?zoomExtents@Camera@RBX@@QAE_NABVRect2D@G3D@@@Z': 0x5ce400,                           # zoomToExtents 005a0257
    '?backendProcessing@Players@Network@RBX@@SA_NPBVInstance@3@_N@Z': 0x495eb0,           # scriptShouldRun / runScript
    '?findLocalCharacter@Players@Network@RBX@@SAPAVModelInstance@3@PBVInstance@3@@Z': 0x49aca0,
    '?clearLegacyOffset@PVInstance@RBX@@QAEXXZ': 0x608fa0,                                 # onDescendentAdded 005a1ca9
    '?getCameraIgnorePrimitives@ModelInstance@RBX@@UAEXAAV?$vector@PBVPrimitive@RBX@@V?$allocator@PBVPrimitive@RBX@@@std@@@std@@@Z': 0x583570,
    '?getLocation@ModelInstance@RBX@@UBE?BVCoordinateFrame@G3D@@XZ': 0x583cf0,
    '?onCameraNear@ModelInstance@RBX@@UAEXM@Z': 0x5843c0,
    '?onExtentsChanged@ModelInstance@RBX@@UBEXXZ': 0x583a20,                              # onExtentsChanged 005a2db4
    '?onChildChanged@Instance@RBX@@UAEXPAV12@ABVPropertyChanged@2@@Z': 0x557490,          # onChildChanged 005a1b9f
    '?isDescendentOf@Instance@RBX@@QBE_NPBV12@@Z': 0x422ae0,
    '?setParent@Instance@RBX@@QAEXPAV12@@Z': 0x55a8f0,
    '?modelIsCharacter@Humanoid@RBX@@SAPAV12@PBVInstance@2@@Z': 0x5d9a20,                 # clearEmptiedModels 005a1d30
    '?onAdded@IRenderableBucket@RBX@@IAEXPAVIRenderable@2@@Z': 0x5dd4c0,                  # onDescendentAdded 005a1c68
    '?onRemoving@IRenderableBucket@RBX@@IAEXPAVIRenderable@2@@Z': 0x5dd4d0,               # onDescendentRemoving 005a1bec
    '_atexit': 0x6a17af,                                                                  # CRT atexit (915 callers)
    # rows counted by other receipts
    '?findLocalPlayer@Players@Network@RBX@@SAPAVPlayer@23@PBVInstance@3@@Z': 0x49ac80,    # network-players-working.json
    '??1RootInstance@RBX@@MAE@XZ': 0x590630,                                               # app-unit588-2008-working.json
    '?onDescendentAdded@RootInstance@RBX@@MAEXPAVInstance@2@@Z': 0x590160,                 # app-unit588-2008-working.json
    '?onDescendentRemoving@RootInstance@RBX@@MAEXABV?$shared_ptr@VInstance@RBX@@@boost@@@Z': 0x590180,
    '?classDescriptor@?$Described@VRootInstance@RBX@@$1?sRootInstance@2@3PADAVModelInstance@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ': 0x591510,
    '??$shared_from@VInstance@RBX@@@RBX@@YA?AV?$shared_ptr@VInstance@RBX@@@boost@@PAVInstance@0@@Z': 0x618a40,  # misc-leaves
    '??0CoordinateFrame@G3D@@QAE@XZ': 0x4782d0,                                            # humanoid2008-working.json
    # call-site identification (no evidence name; the callee is the only out-of-line body the source can call there)
    '?onWrapMouse@Camera@RBX@@QAEXABVVector2@G3D@@@Z': 0x5cce40,                           # 005a0238: getCamera()->onWrapMouse(delta)
    '?join@PartInstance@RBX@@QAEXXZ': 0x598c90,                                            # wrapper<true> 005a22d1 / 005a1910
    '?destroyJoints@PartInstance@RBX@@QAEXXZ': 0x598c70,                                   # wrapper<false> 005a2371 / 005a1950
    '?joinAll@World@RBX@@QAEXXZ': 0x5ea880,                                                # joinAllHack 005a0de6 (World unit)
    '?insertInstances@RootInstance@RBX@@QAEXABV?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@PAVInstance@2@W4InsertMode@2@W4PromptMode@2@@Z': 0x5911d0,  # RootInstance unit (app-unit588 unit map)
    '?loadInstances@SerializerV2@@QAEXPAVXmlElement@@AAV?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@@Z': 0x593250,  # SerializerV2 unit ("Unknown object class")
    '?render2dItems@IRenderableBucket@RBX@@QAEXPAVAdorn@2@@Z': 0x5dd330,                  # render2d 005a0680 (IRenderableBucket at +0x388)
    # ServiceProvider::find<Workspace>(const Instance*): 00491e50 walks getParent() (+0x104) with
    # dynamic_cast<const ServiceProvider*> (RTTI 0092e15c) and tail-calls provider->find<Workspace>() 00490af0
    '??$find@VWorkspace@RBX@@@ServiceProvider@RBX@@SAPAVWorkspace@1@PBVInstance@1@@Z': 0x491e50,   # findWorkspace 005a3380
    '??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z': 0x5708f0,                       # Reflection unit (117 callers; app-unit588)
    # 2-argument Notifier<Workspace, ToolChanged>::raise: this range's row 005a0ec0, whose analysed extent (62 B) stops
    # at its catch funclet; the compiled body equals 005a0ec0..005a0f78 (see bounds_evidence)
    '?raise@?$Notifier@VWorkspace@RBX@@VToolChanged@2@@RBX@@IBEXVToolChanged@2@PAV?$Listener@VWorkspace@RBX@@VToolChanged@2@@2@@Z': 0x5a0ec0,
}
# data symbols verified by their bytes in the original
DATA_BYTES = {
    '?sWorkspace@RBX@@3PADA': (0x94b680, b'Workspace\0'),                # classDescriptor 005a3b98
}
# COMDAT bodies emitted in the unit object whose call target is out of line in the original: accepted only when the
# compiled body is relocation-masked exact at the bound address (support rows, never counted here).
SUPPORT = {
    '?insert@?$_Tree@V?$_Tset_traits@PAVScript@RBX@@U?$less@PAVScript@RBX@@@std@@V?$allocator@PAVScript@RBX@@@4@$0A@@std@@@std@@QAE?AU?$pair@': 0x5e8c40,   # runScript 005a2794 (ICF with set<Primitive*>::insert)
    '?erase@?$_Tree@V?$_Tset_traits@PAVScript@RBX@@U?$less@PAVScript@RBX@@@std@@V?$allocator@PAVScript@RBX@@@4@$0A@@std@@@std@@QAEIABQAVScript@RBX@@@Z': 0x5e9f60,      # releaseScript 005a27cb
    '??$for_eachChild@P6AXPAVInstance@RBX@@@Z@Instance@RBX@@QBEXP6AXPAV01@@Z@Z': 0x45c470,          # wrapper<> 005a22df
    '??0?$shared_ptr@VInstance@RBX@@@boost@@QAE@ABV01@@Z': 0x4116f0,                                # clearEmptiedModels 005a1d83
    '??1?$shared_ptr@VInstance@RBX@@@boost@@QAE@XZ': 0x600660,                                      # clearEmptiedModels 005a1d99
    '?raise@?$Notifier@VWorkspace@RBX@@VDrawChanged@2@@RBX@@IBEXVDrawChanged@2@@Z': 0x576940,      # DataModel range
    '??$for_each@V?$_Vector_const_iterator@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@P6AXV?$shared_ptr@VInstance@RBX@@@boost@@@Z@std@@': 0x57e470,  # makeJoints 005a2477
    '??1Workspace@RBX@@UAE@XZ': 0x5a28c0,                      # ??_GWorkspace 005a3053 (counted by workspace-lifetime)
    '??__Ffoo@?1??classDescriptor@?$Described@VWorkspace@RBX@@': 0x7fe0d0,                         # atexit 005a3bb5
}
# symbols whose original target is the ICF-folded body of a row proven here (??_E and ??_G are one body)
ALIAS = {
    '??_EWorkspace@RBX@@UAEPAXI@Z': 0x5a3050,
    '??_E?$DescribedNonCreatable@VWorkspace@RBX@@VRootInstance@2@$1?sWorkspace@2@3PADA@RBX@@UAEPAXI@Z': 0x5a0910,
}
UNBOUND = []
binding = {}
support_out = {}
LOCAL_STATIC_AT = {
    '??_B?1??classDescriptor@?$Described@VWorkspace@RBX@@$1?sWorkspace@2@3PADAV?$NonFactoryProduct@VRootInstance@RBX@@$1?sWorkspace@2@3PADA@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ@51': 0x976b48,
    '?foo@?1??classDescriptor@?$Described@VWorkspace@RBX@@$1?sWorkspace@2@3PADAV?$NonFactoryProduct@VRootInstance@RBX@@$1?sWorkspace@2@3PADA@2@@Reflection@RBX@@SAAAVClassDescriptor@34@XZ@4V534@A': 0x976a88,
}
LOCAL_STATIC = re.compile(r'^(\?\$S\d+@|\?\w+@\?\d+\?\?|\?\?_B\?\d+\?\?)')

# (address, symbol or unique prefix): one entry per counted address
ROWS = {
    'workspace': [
        (0x005a0140, '?onMouseUp@MouseCommand@RBX@@MAEPAV12@ABVUIEvent@2@@Z'),
        (0x005a0150, '?releaseCapture@MouseCommand@RBX@@MAEXXZ'),
        (0x005a01e0, '?askAddChild@Workspace@RBX@@EBE_NPBVInstance@2@@Z'),
        (0x005a0210, '?getGCamera@Workspace@RBX@@UBEABVGCamera@G3D@@XZ'),
        (0x005a0220, '?onWrapMouse@Workspace@RBX@@QAEXABVVector2@G3D@@@Z'),
        (0x005a0240, '?zoomToExtents@Workspace@RBX@@QAEXXZ'),
        (0x005a0260, '?stop@Workspace@RBX@@QAEXXZ'),
        (0x005a0280, '?newNullTool@RBX@@YAPAVMouseCommand@1@PAVWorkspace@1@@Z'),
        (0x005a0310, '??1?$auto_ptr@VMouseCommand@RBX@@@std@@QAE@XZ'),
        (0x005a04a0, '?cancel@MouseCommand@RBX@@MAEXXZ'),
        (0x005a04b0, '?isSticky@ArrowTool@RBX@@UBEPAVMouseCommand@2@XZ'),
        (0x005a0530, '?getMyWorkspaceFast@Workspace@RBX@@SAPAV12@PBVInstance@2@@Z'),
        (0x005a0560, '?getMyWorldFast@Workspace@RBX@@SAPAVWorld@2@PBVInstance@2@@Z'),
        (0x005a05a0, '?getCamera@Workspace@RBX@@UBEPAVCamera@2@XZ'),
        (0x005a05d0, '?insertItems@Workspace@RBX@@QAEXPAVXmlElement@@AAV?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std'),
        (0x005a0610, '?setNullMouseCommand@Workspace@RBX@@QAEXXZ'),
        (0x005a0660, '?render2d@Workspace@RBX@@UAEXPAVAdorn@2@@Z'),
        (0x005a0740, '?scriptShouldRun@Workspace@RBX@@EAEPAVIScriptOwner@2@PAVScript@2@@Z'),
        (0x005a07b0, '??0?$NonFactoryProduct@VRootInstance@RBX@@$1?sWorkspace@2@3PADA@RBX@@QAE@XZ'),
        (0x005a08d0, '??_E?$DescribedNonCreatable@VWorkspace@RBX@@VRootInstance@2@$1?sWorkspace@2@3PADA@RBX@@WCII@AEPAXI@Z'),
        (0x005a08e0, '??_E?$DescribedNonCreatable@VWorkspace@RBX@@VRootInstance@2@$1?sWorkspace@2@3PADA@RBX@@WIE@AEPAXI@Z'),
        (0x005a08f0, '??_E?$DescribedNonCreatable@VWorkspace@RBX@@VRootInstance@2@$1?sWorkspace@2@3PADA@RBX@@WBA@AEPAXI@Z'),
        (0x005a0900, '??_E?$DescribedNonCreatable@VWorkspace@RBX@@VRootInstance@2@$1?sWorkspace@2@3PADA@RBX@@$4PPPPPPPM@CPM@AEPAXI@Z'),
        (0x005a0910, '??_G?$DescribedNonCreatable@VWorkspace@RBX@@VRootInstance@2@$1?sWorkspace@2@3PADA@RBX@@UAEPAXI@Z'),
        (0x005a0d90, '?findTopInstance@Workspace@RBX@@SAPAVInstance@2@PAV32@@Z'),
        (0x005a0de0, '?joinAllHack@Workspace@RBX@@QAEXXZ'),
        (0x005a1530, '?raise@?$Notifier@VWorkspace@RBX@@VToolChanged@2@@RBX@@IBEXVToolChanged@2@@Z'),
        (0x005a16b0, '??$findFirstChildOfType@VPartInstance@RBX@@@Instance@RBX@@QBEPAVPartInstance@1@XZ'),
        (0x005a1750, '??$findFirstChildOfType@VModelInstance@RBX@@@Instance@RBX@@QBEPAVModelInstance@1@XZ'),
        (0x005a1910, '??$wrapper@$00@RBX@@YAXPAVInstance@0@@Z'),
        (0x005a1950, '??$wrapper@$0A@@RBX@@YAXPAVInstance@0@@Z'),
        (0x005a1b90, '?onChildChanged@Workspace@RBX@@EAEXPAVInstance@2@ABVPropertyChanged@2@@Z'),
        (0x005a1bc0, '?onDescendentRemoving@Workspace@RBX@@EAEXABV?$shared_ptr@VInstance@RBX@@@boost@@@Z'),
        (0x005a1c20, '?onDescendentAdded@Workspace@RBX@@EAEXPAVInstance@2@@Z'),
        (0x005a1ce0, '?clearEmptiedModels@RBX@@YAXV?$shared_ptr@VInstance@RBX@@@boost@@PAVInstance@1@@Z'),
        (0x005a1e80, '?handleFallenParts@Workspace@RBX@@AAEXABV?$Array@V?$shared_ptr@VPartInstance@RBX@@@boost@@@G3D@@@Z'),
        (0x005a1fc0, '?setMouseCommand@Workspace@RBX@@QAEXPAVMouseCommand@2@@Z'),
        (0x005a2290, '??$wrapper2@$00@RBX@@YAXV?$shared_ptr@VInstance@RBX@@@boost@@@Z'),
        (0x005a2330, '??$wrapper2@$0A@@RBX@@YAXV?$shared_ptr@VInstance@RBX@@@boost@@@Z'),
        (0x005a2420, '?makeJoints@Workspace@RBX@@QAEXV?$shared_ptr@$$CBV?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std'),
        (0x005a24d0, '?breakJoints@Workspace@RBX@@QAEXV?$shared_ptr@$$CBV?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@st'),
        (0x005a2730, '?setDefaultMouseCommand@Workspace@RBX@@QAEXXZ'),
        (0x005a2760, '?runScript@Workspace@RBX@@EAEXPAVScript@2@PAVScriptContext@2@@Z'),
        (0x005a27c0, '?releaseScript@Workspace@RBX@@EAEXPAVScript@2@@Z'),
        (0x005a2c30, '?computeCameraOwnerExtents@Workspace@RBX@@EAE?AVExtents@2@XZ'),
        (0x005a2c50, '??_EWorkspace@RBX@@WME@AEPAXI@Z'),
        (0x005a2c70, '??_EWorkspace@RBX@@WDBE@AEPAXI@Z'),
        (0x005a2c80, '??_EWorkspace@RBX@@WBA@AEPAXI@Z'),
        (0x005a2c90, '?getCameraIgnorePrimitives@ModelInstance@RBX@@$4PPPPPPPM@BLI@AEXAAV?$vector@PBVPrimitive@RBX@@V?$allocator@PBVPrimitive@RBX@@@std@@@std@@@Z'),
        (0x005a2ca0, '??_EWorkspace@RBX@@WBE@AEPAXI@Z'),
        (0x005a2cb0, '??_EWorkspace@RBX@@$4PPPPPPPM@EFE@AEPAXI@Z'),
        (0x005a2cc0, '??_EWorkspace@RBX@@WBDA@AEPAXI@Z'),
        (0x005a2cd0, '??_EWorkspace@RBX@@WCII@AEPAXI@Z'),
        (0x005a2ce0, '??_EWorkspace@RBX@@WDEE@AEPAXI@Z'),
        (0x005a2cf0, '??_EWorkspace@RBX@@WDGE@AEPAXI@Z'),
        (0x005a2d00, '??_EWorkspace@RBX@@WDIE@AEPAXI@Z'),
        (0x005a2d10, '?onCameraNear@ModelInstance@RBX@@$4PPPPPPPM@BLI@AEXM@Z'),
        (0x005a2d20, '??_EWorkspace@RBX@@WCOM@AEPAXI@Z'),
        (0x005a2d30, '??_EWorkspace@RBX@@WCE@AEPAXI@Z'),
        (0x005a2d40, '??_EWorkspace@RBX@@WEE@AEPAXI@Z'),
        (0x005a2d50, '?getLocation@ModelInstance@RBX@@$4PPPPPPPM@BLI@BE?BVCoordinateFrame@G3D@@XZ'),
        (0x005a2d60, '??_EWorkspace@RBX@@WGE@AEPAXI@Z'),
        (0x005a2d70, '??_EWorkspace@RBX@@WIE@AEPAXI@Z'),
        (0x005a2d80, '??_EWorkspace@RBX@@WKE@AEPAXI@Z'),
        (0x005a2d90, '?cameraMoved@Workspace@RBX@@EAEXXZ'),
        (0x005a2db0, '?onExtentsChanged@Workspace@RBX@@EBEXXZ'),
        (0x005a3050, '??_GWorkspace@RBX@@UAEPAXI@Z'),
        (0x005a3380, '?findWorkspace@Workspace@RBX@@SAPAV12@PBVInstance@2@@Z'),
        (0x005a3390, '?getWorldIfInWorkspace@Workspace@RBX@@SAPAVWorld@2@PBVInstance@2@@Z'),
        (0x005a33d0, '?contextInWorkspace@Workspace@RBX@@SA_NPBVInstance@2@@Z'),
        (0x005a3b70, '?classDescriptor@?$Described@VWorkspace@RBX@@$1?sWorkspace@2@3PADAV?$NonFactoryProduct@VRootInstance@RBX@@$1?sWorkspace@2@3PADA@2@@Reflection@RBX@@SAA'),
        (0x005a4280, '??0?$DescribedNonCreatable@VWorkspace@RBX@@VRootInstance@2@$1?sWorkspace@2@3PADA@RBX@@IAE@XZ'),
        (0x005a43e0, '??_E?$DescribedNonCreatable@VWorkspace@RBX@@VRootInstance@2@$1?sWorkspace@2@3PADA@RBX@@WBDA@AEPAXI@Z'),
        (0x005a43f0, '??_E?$DescribedNonCreatable@VWorkspace@RBX@@VRootInstance@2@$1?sWorkspace@2@3PADA@RBX@@WGE@AEPAXI@Z'),
        (0x005a4400, '??_E?$DescribedNonCreatable@VWorkspace@RBX@@VRootInstance@2@$1?sWorkspace@2@3PADA@RBX@@WKE@AEPAXI@Z'),
        (0x005a4410, '??_E?$DescribedNonCreatable@VWorkspace@RBX@@VRootInstance@2@$1?sWorkspace@2@3PADA@RBX@@WME@AEPAXI@Z'),
    ],
}
REJECTED = {
    'AppUnit5A0_2008Workspace.cpp without /U_RELEASEASSERT': 'render2d 65/42 (RBXASSERT in getCurrentMouseCommand kept)',
    'insertItems with `instances.size() != 0`': '61/60 B: test ecx,0xfffffff8 / je instead of sar ecx,3 / test / jbe',
    'scriptShouldRun with a return in each branch': '128/103 B (the IScriptOwner conversion is duplicated)',
    'render3dAdorn with the donor body (sel->getSelection()->begin())': (
        'does not compile against the native Selection.h; the original reads the CopyOnWrite vector at +0x154 inline'),
    'clearEmptiedModels / onDescendentAdded with humanoid/Humanoid2008.h': (
        'C2011 Connector redefinition against v8kernel/Connector2008.h through v8datamodel/PartInstance.h; '
        'humanoid/Humanoid.h is used for the modelIsCharacter declaration'),
}


def support_key(symbol):
    keys = [k for k in SUPPORT if symbol == k or symbol.startswith(k)]
    assert len(keys) <= 1, (symbol, keys)
    return keys[0] if keys else None


def target_of(address):
    body, refs, _ = match.target('2008-06', '%08x' % address)
    return body, refs


def resolve(obj, rows):
    funcs = match.coff_functions(Path(obj).read_bytes())
    out = []
    for row in rows:
        address, key = row[0], row[1]
        hits = [x for x in funcs if x[0] == key] or [x for x in funcs if x[0].startswith(key) and not nb.LOCAL_EH.match(x[0])]
        if DISCOVER and len(hits) != 1:
            print('UNRESOLVED', '%08x' % address, key[:120], [h[0][:120] for h in hits])
            continue
        assert len(hits) == 1, ('%08x' % address, key, [h[0] for h in hits])
        out.append((address, hits[0][0]))
    return out


def bind_value(raw, sections, symbols, definitions, bodies, name, body, target, address, own, record=True):
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
        if nb.LOCAL_EH.match(symbol):
            local.add(symbol)
            continue
        hit = original.imported(value)
        if hit is not None:
            assert hit[1] == nb.plain(symbol), (name, symbol, hex(value), hit)
            how = '%s!%s' % hit
        elif symbol.startswith('__real@'):
            assert original.data(value, len(symbol[7:]) // 2) == bytes.fromhex(symbol[7:])[::-1], (name, symbol, hex(value))
            how = 'constant %s' % symbol[7:]
        elif symbol.startswith('??_C@'):
            pos, at = definitions[symbol]
            literal = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
            assert original.data(value, len(literal)) == literal, (name, symbol, hex(value))
            how = 'string %r' % literal[:-1].decode('latin-1')[:40]
        elif symbol.startswith('??_R0') and symbol.endswith('@8'):
            rtti = original.string(value + 8)
            assert rtti == '.' + symbol[5:-2], (name, symbol, hex(value), rtti)
            how = 'RTTI type %s' % rtti
        elif symbol.startswith('??_7'):
            rtti, offset_in_object = original.vtable_class(value)
            cls = symbol[4:symbol.index('@@6B') + 2]
            assert rtti == '.?AV' + cls, (name, symbol, hex(value), rtti)
            how = 'vtable (RTTI %s, offset %#x)' % (rtti, offset_in_object)
        elif symbol.startswith('??_8'):
            pos, at = definitions[symbol]
            table_bytes = raw[sections[at][4] + pos:sections[at][4] + pos + 8]
            assert original.data(value, len(table_bytes)) == table_bytes, (name, symbol, hex(value))
            how = 'vbtable bytes %s' % table_bytes.hex()
        elif symbol in ALIAS:
            assert ALIAS[symbol] == value, (name, symbol, hex(value), hex(ALIAS[symbol]))
            how = 'ICF-folded body (alias of a row proven here)'
        elif symbol in own:
            assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
            how = 'own row'
        elif support_key(symbol):
            assert SUPPORT[support_key(symbol)] == value, (name, symbol, hex(value))
            sbody, srefs = bodies[symbol]
            starget, strefs = target_of(value)
            assert match.exact_match(starget, strefs, sbody, srefs), ('support body not exact', symbol, hex(value))
            support_out[symbol] = '%08x' % value
            how = 'support body exact at the bound address'
        elif symbol in DATA_BYTES:
            where, expect = DATA_BYTES[symbol]
            assert where == value and original.data(value, len(expect)) == expect, (name, symbol, hex(value))
            how = 'data bytes %s' % expect.hex()
        elif symbol in EXTERNAL:
            assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
            how = 'external' + (' (evidence name)' if names.get(value, '') == symbol else '')
        elif symbol in LOCAL_STATIC_AT:
            assert LOCAL_STATIC_AT[symbol] == value, (name, symbol, hex(value), hex(LOCAL_STATIC_AT[symbol]))
            how = 'static data (one address per symbol)'
        else:
            UNBOUND.append("    %r: %#x,   # %s in %s" % (symbol, value, names.get(value, '')[:60], name[:60]))
            continue
        if record:
            prev = binding.setdefault(symbol, (value, name))
            assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
        verified[symbol] = '%s (%s)' % (hex(value), how)
    return verified, local


def verify(objs, which, rows, own, strict=True, record=True):
    raw = Path(objs[which]).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    result = []
    for address, name in rows:
        body, refs = bodies[name]
        target, target_refs = target_of(address)
        exact = match.exact_match(target, target_refs, body, refs)
        entry = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target), 'exact': exact}
        if not exact:
            assert not strict or DISCOVER, (name, entry['address'], len(body), len(target))
            result.append(entry)
            continue
        verified, local = bind_value(raw, sections, symbols, definitions, bodies, name, body, target, address, own, record)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local)})
        result.append(entry)
    return result


resolved = {k: resolve(OBJ[k], rows) for k, rows in ROWS.items()}
own = {}
for rows in resolved.values():
    for address, name in rows:
        own.setdefault(name, address)
groups = {k: verify(OBJ, k, rows, own) for k, rows in resolved.items()}


def vtable_slots(obj_path, vtable_address):
    """Compare every slot of each vtable in the current-header object with the original vtable whose
    address the vptr stores of the counted rows use; slots whose function is bound here must agree."""
    raw = Path(obj_path).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    out = {}
    for symbol, address in sorted(vtable_address.items()):
        start, sec = definitions[symbol]
        table = sections[sec]
        relocs = sorted((struct.unpack_from('<IIH', raw, table[5] + 10 * k)) for k in range(table[7]))
        slots = [(off - start, symbols[idx][0]) for off, idx, kind in relocs if kind == 6 and off >= start]
        slots = [x for x in slots if x[0] < table[3] - start]
        known = dict(own)
        known.update(EXTERNAL)
        checked, unbound = [], []
        for off, target_symbol in slots:
            value = struct.unpack('<I', original.data(address + off, 4))[0]
            expect = known.get(target_symbol)
            if expect is None and support_key(target_symbol):
                expect = SUPPORT[support_key(target_symbol)]
            if expect is None and names.get(value, '') == target_symbol:
                checked.append('%d %s = %#x (evidence name)' % (off // 4, target_symbol[:80], value))
                continue
            if expect is None:
                unbound.append('%d %s' % (off // 4, target_symbol[:80]))
                continue
            assert expect == value, ('vtable slot', symbol, off // 4, target_symbol, hex(value), hex(expect))
            checked.append('%d %s = %#x' % (off // 4, target_symbol[:80], value))
        # slot count: every original slot is a code address and the dword after the last slot is not
        code_range = range(0x401000, 0x7e0000)
        originals = [struct.unpack('<I', original.data(address + 4 * k, 4))[0] for k in range(len(slots) + 1)]
        assert all(v in code_range for v in originals[:-1]) and originals[-1] not in code_range, (
            'vtable slot count', symbol, hex(address), [hex(v) for v in originals])
        out[symbol] = {'address': '%08x' % address, 'slots': len(slots), 'checked': checked,
                       'not_bound_here': len(unbound)}
    return out


VTABLE_ADDRESS = {}
for rows in groups.values():
    for r in rows:
        for sym, how in r.get('verified_targets', {}).items():
            if sym.startswith('??_7'):
                VTABLE_ADDRESS[sym] = int(how.split()[0], 16)
vtables = vtable_slots(OBJ['workspace'], VTABLE_ADDRESS)

if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for g, rows in groups.items():
        for r in rows:
            if not r['exact']:
                print('NOT EXACT', g, r['address'], r['symbol'][:90], r['size'], r['target_size'])
    sys.exit(0)
assert not UNBOUND, UNBOUND


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
exact_rows = sorted({r['address'] for rows in groups.values() for r in rows if r['exact']})
double = {a: elsewhere[a] for a in exact_rows if a in elsewhere}
assert not double, double
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if '005a0000' <= a < '005ac000'}



def concatenated_target(parts):
    """Original bytes and relocation offsets of consecutive analysed rows, joined (bounds evidence only)."""
    data, relocs, start = b'', [], parts[0]
    for a in parts:
        body, refs = target_of(a)
        assert start + len(data) == a, ('rows not contiguous', hex(a))
        relocs += [r + len(data) for r in refs]
        data += body
    return data, relocs


BOUNDS = []
raw_ws = Path(OBJ['workspace']).read_bytes()
bodies_ws = {n: (b, r) for n, b, r in match.coff_functions(raw_ws)}
for parts, key, why in [
    ((0x5a0ec0, 0x5a0efe, 0x5a0f11), '?raise@?$Notifier@VWorkspace@RBX@@VToolChanged@2@@RBX@@IBEXVToolChanged@2@PAV?$Listener',
     'Notifier<Workspace, ToolChanged>::raise(ToolChanged, Listener*): the analysed rows 005a0ec0 (62 B), 005a0efe (19 B) '
     'and 005a0f11 (104 B, "Exception caught in onEvent. %s") are one function: the try body and its catch funclet. The '
     'compiled body (185 B) is relocation-masked exact against 005a0ec0..005a0f78. Not counted (extent fix needed).'),
]:
    hits = [n for n in bodies_ws if n.startswith(key)]
    assert len(hits) == 1, hits
    body, refs = bodies_ws[hits[0]]
    data, relocs = concatenated_target(parts)
    ok = len(data) == len(body) and match.exact_match(data, relocs, body, refs)
    assert ok or DISCOVER, ('bounds evidence', hits[0])
    BOUNDS.append({'rows': ['%08x' % a for a in parts], 'symbol': hits[0], 'compiled_size': len(body),
                   'joined_size': len(data), 'exact_when_joined': ok, 'reason': why})

# range rows (functions.jsonl) with the unit each lies in
RANGE_ROWS = [json.loads(l) for l in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines() if l.strip()]
RANGE_ROWS = [r for r in RANGE_ROWS if 0x5a0000 <= int(r['addr'], 16) < 0x5ac000]
UNITS = [
    ('special-shape tail', 0x5a0000, 0x5a0090),
    ('workspace', 0x5a0090, 0x5a6bb0),
    ('log', 0x5a6bb0, 0x5a6fd0),
    ('boost-thread-tss (library)', 0x5a6fd0, 0x5a7770),
    ('filesystem', 0x5a7770, 0x5a80d0),
    ('guid', 0x5a80d0, 0x5a8590),
    ('script-context + lua bridge templates', 0x5a8590, 0x5ac000),
]
unit_rows = {}
for r in RANGE_ROWS:
    a = int(r['addr'], 16)
    unit = [u for u, lo, hi in UNITS if lo <= a < hi][0]
    unit_rows.setdefault(unit, []).append(r['addr'])

UNIT_MAP = {
    'special-shape tail ..005a008f': (
        'SpecialShape.cpp (native-classes/SpecialShape.cpp header: unit 0059ece0..005a008d). 005a0030 setTextureId is '
        'counted by special-shape-working.json. Not built here.'),
    'workspace 005a0090..005a6baf': (
        'v8datamodel/Workspace.cpp. Evidence: askAddChild 005a01e0 .. onServiceProvider 005a66b0, RTTI '
        '.?AVWorkspace@RBX@@ vtables 008338.. / 008339d4 (the ??_E thunks 005a2c50..005a2d80 jump to ??_G 005a3050, '
        'which calls ~Workspace 005a28c0), NonFactoryProduct<RootInstance, sWorkspace>() 005a07b0 and '
        'DescribedNonCreatable<Workspace, ...>() 005a4280 (called by Workspace() 005a4d90), classDescriptor 005a3b70 '
        '("Workspace" 0094b680), the BoundFuncDesc / RefPropDescriptor instantiations 005a3cb0..005a5890 ("bad cast"), '
        'render3dAdorn 005a59e0, WorkspaceStatsItem() 005a5c90 ("Workspace", "Environment Speed %%", stats owner) and its '
        'boost::function / bind_t<double, cmf0<double, Workspace>> helpers (005a0400 manager, RTTI 0094ba88; '
        '005a67f0..005a6b40). 005a0090..005a0132 are the double getters the stats binds read: +0x410 / +0x418 / +0x420 '
        '(the unknown0x410..0x420 fields of the native header, zeroed by Workspace()) and three float ratios over '
        '+0x1c0. Rows 005a0140..005a0190 and 005a04a0..005a04b0 are MouseCommand / ArrowTool header inlines and 005a0160 / '
        '005a0190 are ControllerTypeArray-style byte scans (header inlines) emitted in this unit. 005a2250 is the '
        'jump table of process() 005a20e0 (data, not code). The thunks 005a08d0..005a0900 / 005a43e0..005a4410 and ??_G '
        '005a0910 are shared by the RootInstance, NonFactoryProduct and DescribedNonCreatable vtables (00831c.., 008337.., '
        '00833c..): ICF folded one body per offset; counted here once under the DescribedNonCreatable symbol (app-unit588 '
        'only uses 005a0910 as a support row). Built here: 76 counted rows. Counted by other receipts: ~Workspace '
        '005a28c0 / Workspace() 005a4d90 (workspace-lifetime-profiler-notifier-variant.json), shared_count<Camera / '
        'Flag, Creatable Deleter> 005a0b50 / 005a0be0 / 005a0c70 / 005a3070 (creatable-shared-count), 005a0320 '
        '(flag-family), sp_counted_impl_pd<RunService*> 005a0460 and the thunks 005a4140 / 005a4150 / 005a6610 '
        '(stats-service), 005a3410 / 005a4680 (humanoid2008).'),
    'log 005a6bb0..005a6fcf': (
        'Log.cpp (native leaves2008/Log2008.h: setLogProvider 005a6bb0 .. writeEntry 005a6ef0, ??_G 005a6fb0); counted '
        'by leaves2008-working.json. Not built here.'),
    'boost-thread-tss 005a6fd0..005a776f (library)': (
        'boost.thread thread_specific_ptr / tss support: TlsAlloc 005a739b, TlsGetValue 005a742d / 005a758e, '
        'TlsSetValue 005a7290 / 005a74ab, TlsFree 005a71c6, boost::lock_error throws (00568430, type 008d4f30), the '
        'call_once at 005a75fd. Library code (boost thread), never recovered here.'),
    'filesystem 005a7770..005a80cf': (
        'FileSystem.cpp: ~VistaAPIs 005a7770 (FreeLibrary), VistaAPIs::GetIntegrity 005a7780 (GetVersionExA / '
        'OpenProcessToken / GetSidSubAuthority), ATL CSimpleStringT<char>::Append 005a7920 (atlsimpstr template), '
        'the SHGetKnownFolderPath loader 005a7ac0 ("Shell32.dll" 00834224), getCacheDirectory 005a7ea0. Owner: '
        'native-classes/FileSystem.cpp / util/FileSystem.h (filesystem-trial.json). Not built here.'),
    'guid 005a80d0..005a858f': (
        'Guid.cpp: generateGUID 005a8140, Data::operator< 005a8210, initLocalScope 005a8260, Guid() 005a8300, '
        'readableString 005a8440 ("%%s_%%d"). Owner: native-classes/Guid.cpp / util/Guid.h. Not built here.'),
    'script-context 005a8590..005abfff': (
        'ScriptContext.cpp and the Lua bridge templates it instantiates: Lua::ScopedPopper 005a8590, '
        'sandboxThread 005a8660 ("__index"), gc 005a86c0, getContext 005a86e0, tick 005a8750, onEvent 005a8770, '
        'Bridge<CoordinateFrame / Vector3 / Color3 / BrickColor / SignalInstance / connection> push / on_tostring / '
        'on_eq / registerClass ("__index" / "__newindex"), delay 005a9140 ("delay function requires 2 arguments"), '
        'print 005a9320 ("tostring"), the ScriptContext factory thunks 005a8e40..005a8eb0, ThreadRef::Node helpers '
        '005ab070.., LuaArguments::push 005aba50 and pushArguments 005abf90 (continues past 005ac000). Owners: '
        'script/ScriptContext.h (ScriptContextLifetime.cpp) and the LuaBridge2008 lease. Not built here.'),
}

NON_EXACT_OUT = [
    {'address': '005a0ec0', 'symbol': '?raise@?$Notifier@VWorkspace@RBX@@VToolChanged@2@@RBX@@IBEXVToolChanged@2@PAV?$Listener...',
     'exact': False, 'reason': 'extent: see bounds_evidence (exact when 005a0ec0 / 005a0efe / 005a0f11 are joined)'},
    {'address': '005a4d90', 'symbol': '??0Workspace@RBX@@QAE@PAVIDataState@1@@Z', 'exact': False,
     'reason': 'compiled here only to emit the vtables, inline virtuals, thunks and base constructors (same body as '
               'native-classes/WorkspaceLifetime.cpp); not exact under this unit\'s build, not checked here; counted by '
               'workspace-lifetime-profiler-notifier-variant.json, not here'},
]
NOT_ATTEMPTED = {
    '005a0090..005a0132': 'stats double getters: no declared accessor in the native Workspace.h (proposal)',
    '005a0d00 / 005a0e40 / 005a0f80..005a1260 / 005a1810 / 005a1830 / 005a19f0..005a1b70': (
        'DecalTool / ArrowTool Name and getName / cursor helpers, G3D Array<shared_ptr<PartInstance>> dtor 005a0e40, '
        'ContentId descriptor helper 005a0d00 (tool owners / descriptor templates)'),
    '005a0df0 reset': 'inlines World::reset (World +0xa8 = 0); needs the 2008 World (World2008 lease)',
    '005a0e30 setThrottleEnabled': 'tail-calls 005e9520, not the donor inline World::setCanThrottle (World2008 lease)',
    '005a20e0 process': '2008 GuiTarget process: switch on UIEvent type 1..13 (jump table 005a2250) with idleMouseEvent at +0x3b8',
    '005a2580 step': 'needs the 2008 World touch / fallen accessors (World2008 lease)',
    '005a3470 onEvent / 005a3540 / 005a39d0 insertContent / 005a36e0 start': 'not attempted this pass',
    '005a59e0 render3dAdorn': ('2008 shape differs from the donor: reads the Selection CopyOnWrite vector at +0x154 '
                               'inline and binds DrawAdorn 005a0690 with three bound values; rejected donor body'),
    '005a5c90 WorkspaceStatsItem() / 005a66b0 onServiceProvider': 'stats owner (WorkspaceStatsItem.h) / not attempted',
}

PROPOSALS = {
    'v8datamodel/Workspace.h (Workspace owner)': (
        'The three doubles unknown0x410 / unknown0x418 / unknown0x420 are read by out-of-line getters 005a00f0 / '
        '005a0100 / 005a0110 (fld qword [ecx+0x410/0x418/0x420]; ret) and their sum 005a0120, which the '
        'WorkspaceStatsItem binds use (bind_t<double, cmf0<double, Workspace>, value<const Workspace*>>, RTTI '
        '0094ba88). Declaring `double getX() const` accessors for them (names from the stats item strings) would let '
        'these rows be recovered; the field names stay with the owner.'),
    'BOUNDS / unit map for the server host (no bounds.json change)': (
        '005a0ec0 (62 B), 005a0efe (19 B) and 005a0f11 (104 B) are one function, Notifier<Workspace, ToolChanged>::raise'
        '(ToolChanged, Listener*) with its catch funclet ("Exception caught in onEvent. %s"): the compiled 185-byte body '
        'is relocation-masked exact against 005a0ec0..005a0f78. 005a2250 (52 B) is the jump table of process() 005a20e0, '
        'not code. 005a6fd0..005a776f is boost.thread tss library code.'),
}

receipt = {
    'class': 'RBX Workspace unit of the application range 005a0000..005ac000 (2008-06), inactive',
    'compiler': 'VS2008 RTM 21022',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)): nb.sha(p) for p in list(SOURCES.values()) + [Path(__file__).resolve(),
                R / 'native-headers/v8datamodel/Workspace.h', R / 'native-headers/v8datamodel/RootInstance.h']},
    'objects': {k: nb.sha(v) for k, v in OBJ.items()},
    'unit_map': UNIT_MAP,
    'unit_rows': {u: {'rows': len(v), 'first': v[0], 'last': v[-1]} for u, v in unit_rows.items()},
    'range_rows_total': len(RANGE_ROWS),
    'range_rows_counted_by_other_receipts': range_counted,
    'rows': groups,
    'support_rows': support_out,
    'vtables_current_headers': vtables,
    'bounds_evidence': BOUNDS,
    'not_exact': NON_EXACT_OUT,
    'not_attempted': NOT_ATTEMPTED,
    'rejected': REJECTED,
    'proposals': PROPOSALS,
    'exact_function_rows': exact_rows,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit5a0-2008: %d counted exact rows (%s); %d vtables checked, %d support rows, %d range rows '
      '(%d counted elsewhere)' % (len(exact_rows), ' '.join(exact_rows), len(vtables), len(support_out),
                                  len(RANGE_ROWS), len(range_counted)))
