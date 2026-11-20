"""Verify the inactive 2008-06 native rows of the application range 005a8000..005b0000, and record the unit map of the
range (boundary evidence in the receipt's `unit_map`; rows counted by other receipts are listed there as text).

Unit map summary (details in UNIT_MAP below):
  * Guid unit tail ..005a858f (util/Guid.cpp): the committed native-classes/Guid.cpp (owner, read-only) is compiled
    unchanged and its four exact rows are counted here (guid-working-probe.json records them but does not count them).
  * ScriptContext unit 005a8590..005b071f (script/ScriptContext.cpp and the Lua bridge templates it is the first unit
    in link order to instantiate), continuing past 005b0000 (app-unit5b0 unit map).

Built here:
  * native-classes/AppUnit5A8_2008ScriptContext.cpp against the committed native script/ScriptContext.h, the donor
    lua/LuaBridge.h / script/LuaAtomicClasses.h / script/ThreadRef.h templates and the LuaBridge2008 owner's headers
    (all read-only; no new header, nothing shadowed): ScriptContext statics / members and explicit instantiations of the
    Bridge<T> / SharedPtrBridge<T> / SingletonBridge<T> templates whose COMDATs lie in this range.
  * the committed native-classes/ScriptContextLifetime.cpp (owner script/ScriptContext.h, compiled unchanged): it
    defines the constructor and destructor, so it emits ~ScriptContext, the ??_G / ??_E thunks of ScriptContext and of
    FactoryProduct<ScriptContext>, ~FactoryProduct and the ICF-folded ~DescribedCreatable jump. Its vtables are compared
    slot by slot with the original vtables (RTTI and COL subobject offset) on this current-header object.

Build: document-swap flags, VS2008 RTM 21022 (no extra profile flag).

Every counted row is relocation-masked exact against the original with the same relocation offsets on both sides,
and every REL32/DIR32 target is bound to the address the original instruction uses and verified: imports by DLL export
name, constants and string literals by bytes, RTTI type descriptors by name, vtables by RTTI, Bridge<T>::className
statics by their constant pointer and the string it names, own symbols by the row proven here, the __newindex
wrappers (not exact, see not_exact) structurally by the className static they read, the remaining externals by the
explicit EXTERNAL map (evidence name, or a binding another recorder proves), static data by one address per symbol.
A row is counted only when no other receipt counts it.
Writes work/2008-06/shared-layouts/app-unit5a8-2008-working.json.
Set NATIVE_APP_UNIT5A8_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
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
OUT = nb.OUT / 'app-unit5a8-2008'
OUT.mkdir(parents=True, exist_ok=True)
SOURCE = R / 'native-classes/AppUnit5A8_2008ScriptContext.cpp'
OWNER_SOURCE = R / 'native-classes/ScriptContextLifetime.cpp'       # script/ScriptContext.h owner, compiled read-only
GUID_SOURCE = R / 'native-classes/Guid.cpp'                          # util/Guid owner, compiled read-only
HEADER = R / 'native-headers/script/ScriptContext.h'
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT5A8_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit5a8-2008-working.json'


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags() + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


OBJ, FLAGS = {}, {}
OBJ['unit'], FLAGS['unit'] = build('NativeAppUnit5A8_2008_script_context', SOURCE)
OBJ['lifetime'], FLAGS['lifetime'] = build('NativeAppUnit5A8_2008_owner_script_context_lifetime', OWNER_SOURCE)
OBJ['guid'], FLAGS['guid'] = build('NativeAppUnit5A8_2008_owner_guid', GUID_SOURCE)

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}


def d(address):
    return struct.unpack('<I', original.data(address, 4))[0]


# Bridge<T>::className statics: constant-initialized pointers (the bridge units' data blocks, record_native_lua_bridge2008
# CLASSNAMES; ThreadRef::Node's static 00949730 lies in the ThreadRef unit). The string each names is read here.
CLASSNAMES = {
    'V?$shared_ptr@VDescribedBase@Reflection@RBX@@@boost@@$0A@': (0x0095af74, 'Object'),
    'VColor3@G3D@@$00': (0x0095b1bc, 'Color3'), 'VVector3@G3D@@$00': (0x0095b1c0, 'Vector3'),
    'VBrickColor@RBX@@$00': (0x0095b1c4, 'BrickColor'), 'VCoordinateFrame@G3D@@$00': (0x0095b1c8, 'CFrame'),
    'V?$shared_ptr@VSignalInstance@Reflection@RBX@@@boost@@$0A@': (0x0095b1e4, 'RBXScriptSignal'),
    'Vconnection@signals@boost@@$00': (0x0095b1e8, 'RBXScriptConnection'),
    'PBVAllEnumDescriptors@Lua@RBX@@$0A@': (0x0095b1d4, 'Enums'),
    'PBVEnumDescriptor@Reflection@RBX@@$0A@': (0x0095b1d8, 'Enum'),
    'PBVItem@EnumDescriptor@Reflection@RBX@@$0A@': (0x0095b1dc, 'EnumItem'),
    'V?$shared_ptr@VNode@ThreadRef@Lua@RBX@@@boost@@$00': (0x00949730, 'shared_ptr<ThreadRef::Node>'),
}
for key, (address, text) in CLASSNAMES.items():
    assert original.string(d(address)) == text, (key, hex(address), original.string(d(address)))

# ---- externals: address the original instruction uses --------------------------------------------------------------
EXTERNAL = {
    # G3D::System::getTick (record_native_sound_lifetime_bindings_worker.py binds ?getTick@System@G3D@@ to 005083d0)
    '?getTick@System@G3D@@SANXZ': 0x5083d0,
    # StandardOut (leaves2008: singleton 00569620, print 005693a0; evidence names)
    '?singleton@StandardOut@RBX@@SA?AV?$shared_ptr@VStandardOut@RBX@@@boost@@XZ': 0x569620,
    '?print@StandardOut@RBX@@QAAXW4MessageType@2@PBDZZ': 0x5693a0,
    '??0runtime_error@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z': 0x409d50,
    '??_7runtime_error@std@@6B@': 0x80b7f8,
    '__TI2?AVruntime_error@std@@': 0x8d1bc8,
    '__CxxThrowException@8': 0x6a158c,
    # GlobalSettingsItem<DebugSettings>::singleton (evidence name spells the class-name parameter 3PBDB; the native
    # header's sDebugSettings is `extern const char[]`, 3QBDB: same address in every native recorder that calls it)
    '?singleton@?$GlobalSettingsItem@VDebugSettings@RBX@@$1?sDebugSettings@2@3QBDB@RBX@@SAAAVDebugSettings@2@XZ': 0x407be0,
    '?current@Context@Security@RBX@@SAAAV123@XZ': 0x493760,
    '?requirePermission@Context@Security@RBX@@QBEXW4Permissions@23@PBD@Z': 0x489810,
    '?singleton@GlobalSettings@RBX@@SA?AV?$shared_ptr@VGlobalSettings@RBX@@@boost@@XZ': 0x5690f0,
    '??0Impersonator@Security@RBX@@QAE@W4Identities@12@@Z': 0x42bc10,
    # Lua bridge unit rows (counted by lua-bridge2008-working.json; symbol names as that recorder binds them)
    '?on_index@?$Bridge@VVector3@G3D@@$00@Lua@RBX@@KAHABVVector3@G3D@@PBDPAUlua_State@@@Z': 0x61cfe0,
    '?on_index@?$Bridge@VCoordinateFrame@G3D@@$00@Lua@RBX@@KAHABVCoordinateFrame@G3D@@PBDPAUlua_State@@@Z': 0x61e690,
    '?on_index@?$Bridge@VColor3@G3D@@$00@Lua@RBX@@KAHABVColor3@G3D@@PBDPAUlua_State@@@Z': 0x61c8c0,
    '?on_index@?$Bridge@VBrickColor@RBX@@$00@Lua@RBX@@KAHABVBrickColor@3@PBDPAUlua_State@@@Z': 0x61d640,
    '?on_index@?$Bridge@Vconnection@signals@boost@@$00@Lua@RBX@@KAHABVconnection@signals@boost@@PBDPAUlua_State@@@Z': 0x61f480,
    '?on_index@?$Bridge@V?$shared_ptr@VSignalInstance@Reflection@RBX@@@boost@@$0A@@Lua@RBX@@KAHABV?$shared_ptr@VSignalInstance@Reflection@RBX@@@boost@@PBDPAUlua_State@@@Z': 0x620760,
    '?on_index@?$Bridge@PBVItem@EnumDescriptor@Reflection@RBX@@$0A@@Lua@RBX@@KAHABQBVItem@EnumDescriptor@Reflection@3@PBDPAUlua_State@@@Z': 0x61ee50,
    '?on_index@?$Bridge@PBVEnumDescriptor@Reflection@RBX@@$0A@@Lua@RBX@@KAHABQBVEnumDescriptor@Reflection@3@PBDPAUlua_State@@@Z': 0x61efc0,
    # Bridge<EnumItem>::on_tostring(const Item*&, L) 005a85b0 (no evidence name, not built exact here: 116/167 B; not
    # counted by lua-bridge2008): checked structurally below (formats "Enum.%s.%s" with G3D::format 00509b10)
    '?on_tostring@?$Bridge@PBVItem@EnumDescriptor@Reflection@RBX@@$0A@@Lua@RBX@@KAHABQBVItem@EnumDescriptor@Reflection@3@PAUlua_State@@@Z': 0x5a85b0,
    '??1connection@signals@boost@@QAE@XZ': 0x595370,
    '?format@G3D@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PBDZZ': 0x509b10,
    # boost::call_once (guid-working-probe.json verifies Guid() 005a830e -> 00557330)
    '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330,
    # ScriptContext destructor callees (the same bindings the ScriptContext lifetime receipt and app-unit54c record;
    # 0064b230 / 005a2fe0 are ICF-folded bodies whose evidence names spell another element type)
    '??1?$_Tree@V?$_Tset_traits@PAVScript@RBX@@U?$less@PAVScript@RBX@@@std@@V?$allocator@PAVScript@RBX@@@4@$0A@@std@@@std@@QAE@XZ': 0x64b230,
    '??1?$vector@V?$shared_ptr@VScript@RBX@@@boost@@V?$allocator@V?$shared_ptr@VScript@RBX@@@boost@@@std@@@std@@QAE@XZ': 0x5a2fe0,
    '??1condition_impl@detail@boost@@QAE@XZ': 0x5f1c70,
    '??1mutex@boost@@QAE@XZ': 0x594cb0,
    '??1thread@boost@@QAE@XZ': 0x5a6840,
    '??1Instance@RBX@@UAE@XZ': 0x55a540,          # evidence ??1Instance@RBX@@MAE@XZ (app-unit40c / 54c / 564 / 57c)
    # The thunks call the vector deleting destructor; ScriptContext / FactoryProduct<ScriptContext> are never array-
    # allocated, so ??_E has the ??_G body and its address is the ??_G row counted here (vtable slot 0 checks below).
    '??_EScriptContext@RBX@@UAEPAXI@Z': 0x5aed20,
    '??_E?$FactoryProduct@VScriptContext@RBX@@VInstance@2@$1?sScriptContext@2@3PADA@RBX@@MAEPAXI@Z': 0x5a8e50,
    # Vector3 / CFrame metamethods (rows counted by lua-bridge2008-working.json, same symbols there)
    '?on_add@Vector3Bridge@Lua@RBX@@CAHPAUlua_State@@@Z': 0x61cba0,
    '?on_sub@Vector3Bridge@Lua@RBX@@CAHPAUlua_State@@@Z': 0x61cc00,
    '?on_mul@Vector3Bridge@Lua@RBX@@CAHPAUlua_State@@@Z': 0x61cc60,
    '?on_div@Vector3Bridge@Lua@RBX@@CAHPAUlua_State@@@Z': 0x61cd40,
    '?on_unm@Vector3Bridge@Lua@RBX@@CAHPAUlua_State@@@Z': 0x61ce40,
    '?on_add@CoordinateFrameBridge@Lua@RBX@@CAHPAUlua_State@@@Z': 0x61dbf0,
    '?on_sub@CoordinateFrameBridge@Lua@RBX@@CAHPAUlua_State@@@Z': 0x61dc70,
    # StringConverter<CoordinateFrame>::convertToString 005beaf0 (no evidence name; checked structurally below: it
    # converts the translation at +0x24 with StringConverter<Vector3> 005bea10 and the matrix with
    # StringConverter<float> 005be040, between the Vector3 005bea10 and BrickColor 005becc0 converters)
    '?convertToString@?$StringConverter@VCoordinateFrame@G3D@@@RBX@@SA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@ABVCoordinateFrame@G3D@@@Z': 0x5beaf0,
}


def _cframe_converter():
    body, _, _ = match.target('2008-06', '005beaf0')
    calls = set()
    for i in range(len(body) - 4):
        if body[i] == 0xe8:
            calls.add((0x5beaf0 + i + 5 + struct.unpack_from('<i', body, i + 1)[0]) & 0xffffffff)
    assert {0x5bea10, 0x5be040} <= calls, [hex(c) for c in calls]
    assert b'\x8d\x46\x24' in body          # lea eax, [esi+0x24]: the translation of CoordinateFrame
    assert names.get(0x5bea10, '').startswith('?convertToString@?$StringConverter@VVector3@G3D@@@RBX@@')
    assert names.get(0x5be040, '').startswith('?convertToString@?$StringConverter@M@RBX@@')


_cframe_converter()


def _enumitem_tostring():
    body, refs, _ = match.target('2008-06', '005a85b0')
    calls = set()
    for i in range(len(body) - 4):
        if body[i] == 0xe8:
            calls.add((0x5a85b0 + i + 5 + struct.unpack_from('<i', body, i + 1)[0]) & 0xffffffff)
    assert 0x509b10 in calls, [hex(c) for c in calls]
    texts = set()
    for r in refs:
        try:
            texts.add(original.string(struct.unpack_from('<I', body, r)[0]))
        except Exception:
            pass
    assert 'Enum.%s.%s' in texts, texts


_enumitem_tostring()
# COMDAT bodies emitted in the unit object whose call target is out of line in the original: accepted only when the
# compiled body is relocation-masked exact at the bound address (support rows, never counted here).
SUPPORT = {}
# static data: one address per symbol
LOCAL_STATIC_AT = {
    # Guid.cpp file statics: Guid() 005a8300 and initLocalScope 005a8260 read / write them, and the out-of-line
    # localScope getter 005a82e0 (call_once(initLocalScope, 00976b6c), then mov eax, [00976b64]) names the same two
    '?localScope@@3PBVName@RBX@@B': 0x976b64,
    '?nextIndex@@3JA': 0x976b68,
    '?flag@?1???0Guid@RBX@@QAE@XZ@4JA': 0x976b6c,
}
UNBOUND = []
binding = {}
support_out = {}
structural_out = {}

# (address, symbol or unique prefix): one entry per counted address
ROWS = {
    'unit': [
        (0x005a8660, '?sandboxThread@ScriptContext@RBX@@CAXPAUlua_State@@@Z'),
        (0x005a86e0, '?getContext@ScriptContext@RBX@@SAAAV12@PAUlua_State@@@Z'),
        (0x005a8750, '?tick@ScriptContext@RBX@@CAHPAUlua_State@@@Z'),
        (0x005a8770, '?onEvent@ScriptContext@RBX@@MAEXPBVRunService@2@VRunTransition@2@@Z'),
        (0x005a8830, '?getObject@?$Bridge@VCoordinateFrame@G3D@@$00@Lua@RBX@@SAAAVCoordinateFrame@G3D@@PAUlua_State@@I@Z'),
        (0x005a8850, '?on_tostring@?$Bridge@VCoordinateFrame@G3D@@$00@Lua@RBX@@KAHABVCoordinateFrame@G3D@@PAUlua_State@@@Z'),
        (0x005a88d0, '?getObject@?$Bridge@VVector3@G3D@@$00@Lua@RBX@@SAAAVVector3@G3D@@PAUlua_State@@I@Z'),
        (0x005a88f0, '?on_tostring@?$Bridge@VVector3@G3D@@$00@Lua@RBX@@KAHABVVector3@G3D@@PAUlua_State@@@Z'),
        (0x005a8a30, '?getObject@?$Bridge@VColor3@G3D@@$00@Lua@RBX@@SAAAVColor3@G3D@@PAUlua_State@@I@Z'),
        (0x005a8a50, '?on_tostring@?$Bridge@VColor3@G3D@@$00@Lua@RBX@@KAHABVColor3@G3D@@PAUlua_State@@@Z'),
        (0x005a8ad0, '?getObject@?$Bridge@VBrickColor@RBX@@$00@Lua@RBX@@SAAAVBrickColor@3@PAUlua_State@@I@Z'),
        (0x005a8af0, '?on_tostring@?$Bridge@VBrickColor@RBX@@$00@Lua@RBX@@KAHABVBrickColor@3@PAUlua_State@@@Z'),
        (0x005a8b70, '?on_gc@?$Bridge@PBVItem@EnumDescriptor@Reflection@RBX@@$0A@@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a8b90, '?on_tostring@?$Bridge@PBVItem@EnumDescriptor@Reflection@RBX@@$0A@@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a8be0, '?on_index@?$Bridge@PBVItem@EnumDescriptor@Reflection@RBX@@$0A@@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a8c10, '?on_eq@?$Bridge@PBVItem@EnumDescriptor@Reflection@RBX@@$0A@@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a8f70, '?on_tostring@?$Bridge@V?$shared_ptr@VSignalInstance@Reflection@RBX@@@boost@@$0A@@Lua@RBX@@KAHABV?$shared_ptr@VSignalInstance@Reflection@RBX@@@boost@@P'),
        (0x005a9120, '?getThreadCount@ScriptContext@RBX@@QBEIXZ'),
        (0x005a9320, '?print@ScriptContext@RBX@@CAHPAUlua_State@@@Z'),
        (0x005a94e0, '?on_gc@?$Bridge@VCoordinateFrame@G3D@@$00@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a9500, '?on_tostring@?$Bridge@VCoordinateFrame@G3D@@$00@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a9550, '?on_index@?$Bridge@VCoordinateFrame@G3D@@$00@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a9600, '?on_gc@?$Bridge@VVector3@G3D@@$00@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a9620, '?on_tostring@?$Bridge@VVector3@G3D@@$00@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a9670, '?on_index@?$Bridge@VVector3@G3D@@$00@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a9710, '?on_gc@?$Bridge@Vconnection@signals@boost@@$00@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a9730, '?on_tostring@?$Bridge@Vconnection@signals@boost@@$00@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a9790, '?on_index@?$Bridge@Vconnection@signals@boost@@$00@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a9810, '?on_tostring@?$Bridge@V?$shared_ptr@VNode@ThreadRef@Lua@RBX@@@boost@@$00@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a98a0, '?on_gc@?$Bridge@VColor3@G3D@@$00@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a98c0, '?on_tostring@?$Bridge@VColor3@G3D@@$00@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a9910, '?on_index@?$Bridge@VColor3@G3D@@$00@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a99b0, '?on_gc@?$Bridge@VBrickColor@RBX@@$00@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a99d0, '?on_tostring@?$Bridge@VBrickColor@RBX@@$00@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a9a20, '?on_index@?$Bridge@VBrickColor@RBX@@$00@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a9a50, '?on_eq@?$Bridge@VBrickColor@RBX@@$00@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a9a90, '?push@?$SingletonBridge@PBVAllEnumDescriptors@Lua@RBX@@@Lua@RBX@@SAXPAUlua_State@@PBVAllEnumDescriptors@23@@Z'),
        (0x005a9b30, '?push@?$SingletonBridge@PBVEnumDescriptor@Reflection@RBX@@@Lua@RBX@@SAXPAUlua_State@@PBVEnumDescriptor@Reflection@3@@Z'),
        (0x005a9bd0, '?push@?$SingletonBridge@PBVItem@EnumDescriptor@Reflection@RBX@@@Lua@RBX@@SAXPAUlua_State@@PBVItem@EnumDescriptor@Reflection@3@@Z'),
        (0x005a9d60, '?on_tostring@?$Bridge@V?$shared_ptr@VSignalInstance@Reflection@RBX@@@boost@@$0A@@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a9db0, '?on_index@?$Bridge@V?$shared_ptr@VSignalInstance@Reflection@RBX@@@boost@@$0A@@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a9de0, '?on_gc@?$Bridge@PBVAllEnumDescriptors@Lua@RBX@@$0A@@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a9e90, '?on_eq@?$Bridge@PBVAllEnumDescriptors@Lua@RBX@@$0A@@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a9ed0, '?on_gc@?$Bridge@PBVEnumDescriptor@Reflection@RBX@@$0A@@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a9f70, '?on_index@?$Bridge@PBVEnumDescriptor@Reflection@RBX@@$0A@@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a9fa0, '?on_eq@?$Bridge@PBVEnumDescriptor@Reflection@RBX@@$0A@@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005aa110, '??$pushNewObject@V?$shared_ptr@VDescribedBase@Reflection@RBX@@@boost@@@?$Bridge@V?$shared_ptr@VDescribedBase@Reflection@RBX@@@boost@@$0A@@Lua@RBX@@SAP'),
        (0x005aa1d0, '??$pushNewObject@V?$shared_ptr@VSignalInstance@Reflection@RBX@@@boost@@@?$Bridge@V?$shared_ptr@VSignalInstance@Reflection@RBX@@@boost@@$0A@@Lua@RBX@@S'),
        (0x005aa2f0, '?registerClass@?$Bridge@VVector3@G3D@@$00@Lua@RBX@@SAXPAUlua_State@@@Z'),
        (0x005aa460, '?registerClass@?$Bridge@VCoordinateFrame@G3D@@$00@Lua@RBX@@SAXPAUlua_State@@@Z'),
        (0x005aa660, '?registerClass@?$Bridge@Vconnection@signals@boost@@$00@Lua@RBX@@SAXPAUlua_State@@@Z'),
        (0x005aa730, '?push@?$SharedPtrBridge@VDescribedBase@Reflection@RBX@@@Lua@RBX@@SAXPAUlua_State@@V?$shared_ptr@VDescribedBase@Reflection@RBX@@@boost@@@Z'),
        (0x005aa860, '?registerClass@?$Bridge@VColor3@G3D@@$00@Lua@RBX@@SAXPAUlua_State@@@Z'),
        (0x005aa930, '?registerClass@?$Bridge@VBrickColor@RBX@@$00@Lua@RBX@@SAXPAUlua_State@@@Z'),
        (0x005aaa30, '?on_gc@?$Bridge@V?$shared_ptr@VNode@ThreadRef@Lua@RBX@@@boost@@$00@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005aaa80, '?on_eq@?$Bridge@V?$shared_ptr@VNode@ThreadRef@Lua@RBX@@@boost@@$00@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005aaac0, '?push@?$SharedPtrBridge@VSignalInstance@Reflection@RBX@@@Lua@RBX@@SAXPAUlua_State@@V?$shared_ptr@VSignalInstance@Reflection@RBX@@@boost@@@Z'),
        (0x005aad90, '?on_gc@?$Bridge@V?$shared_ptr@VDescribedBase@Reflection@RBX@@@boost@@$0A@@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005aade0, '?on_gc@?$Bridge@V?$shared_ptr@VSignalInstance@Reflection@RBX@@@boost@@$0A@@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005ab6c0, '?registerClass@?$Bridge@V?$shared_ptr@VNode@ThreadRef@Lua@RBX@@@boost@@$00@Lua@RBX@@SAXPAUlua_State@@@Z'),
        (0x005ab790, '?registerClass@?$Bridge@V?$shared_ptr@VDescribedBase@Reflection@RBX@@@boost@@$0A@@Lua@RBX@@SAXPAUlua_State@@@Z'),
        (0x005ab840, '?registerClass@?$Bridge@V?$shared_ptr@VSignalInstance@Reflection@RBX@@@boost@@$0A@@Lua@RBX@@SAXPAUlua_State@@@Z'),
        (0x005ac8d0, '??$getPtr@VValue@Reflection@RBX@@@?$SharedPtrBridge@VDescribedBase@Reflection@RBX@@@Lua@RBX@@SA_NPAUlua_State@@IAAVValue@Reflection@2@@Z'),
        (0x005ad8c0, '??0ScriptImpersonator@ScriptContext@RBX@@QAE@PAUlua_State@@@Z'),
        (0x005adc60, '?settings@ScriptContext@RBX@@CAHPAUlua_State@@@Z'),
        (0x005aeaf0, '?setThreadIdentity@ScriptContext@RBX@@CAXPAUlua_State@@W4Identities@Security@2@@Z'),
    ],
    'guid': [
        # Guid.cpp (committed native-classes/Guid.cpp, compiled unchanged): makeGuidString is the out-of-line
        # CoCreateGuid / StringFromGUID2 / WideCharToMultiByte helper 005a80d0 that generateGUID 005a8140 calls
        (0x005a80d0, '?makeGuidString@RBX@@YAXAAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z'),
        (0x005a8140, '?generateGUID@Guid@RBX@@SAXAAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z'),
        (0x005a8260, '?initLocalScope@@YAXXZ'),
        (0x005a8300, '??0Guid@RBX@@QAE@XZ'),
    ],
    'lifetime': [
        (0x005a8790, '??1?$FactoryProduct@VScriptContext@RBX@@VInstance@2@$1?sScriptContext@2@3PADA@RBX@@MAE@XZ'),
        (0x005a8e40, '??_E?$FactoryProduct@VScriptContext@RBX@@VInstance@2@$1?sScriptContext@2@3PADA@RBX@@OCE@AEPAXI@Z'),
        (0x005a8e50, '??_G?$FactoryProduct@VScriptContext@RBX@@VInstance@2@$1?sScriptContext@2@3PADA@RBX@@MAEPAXI@Z'),
        (0x005a8e70, '??_E?$FactoryProduct@VScriptContext@RBX@@VInstance@2@$1?sScriptContext@2@3PADA@RBX@@OEE@AEPAXI@Z'),
        (0x005a8e80, '??_E?$FactoryProduct@VScriptContext@RBX@@VInstance@2@$1?sScriptContext@2@3PADA@RBX@@OGE@AEPAXI@Z'),
        (0x005a8e90, '??_E?$FactoryProduct@VScriptContext@RBX@@VInstance@2@$1?sScriptContext@2@3PADA@RBX@@OIE@AEPAXI@Z'),
        (0x005a8ea0, '??_E?$FactoryProduct@VScriptContext@RBX@@VInstance@2@$1?sScriptContext@2@3PADA@RBX@@OBA@AEPAXI@Z'),
        (0x005a8eb0, '??_E?$FactoryProduct@VScriptContext@RBX@@VInstance@2@$1?sScriptContext@2@3PADA@RBX@@OBE@AEPAXI@Z'),
        # ICF: one 5-byte `jmp ~FactoryProduct` body for ~DescribedCreatable / ~Described<ScriptContext>; counted once
        # under the DescribedCreatable symbol
        (0x005aa650, '??1?$DescribedCreatable@VScriptContext@RBX@@VInstance@2@$1?sScriptContext@2@3PADA@RBX@@UAE@XZ'),
        (0x005ad9d0, '??_E?$FactoryProduct@VScriptContext@RBX@@VInstance@2@$1?sScriptContext@2@3PADA@RBX@@OKE@AEPAXI@Z'),
        (0x005ad9e0, '??_E?$FactoryProduct@VScriptContext@RBX@@VInstance@2@$1?sScriptContext@2@3PADA@RBX@@OME@AEPAXI@Z'),
        (0x005ae690, '??_EScriptContext@RBX@@WGE@AEPAXI@Z'),
        (0x005ae6a0, '??_EScriptContext@RBX@@WIE@AEPAXI@Z'),
        (0x005ae6b0, '??_EScriptContext@RBX@@WKE@AEPAXI@Z'),
        (0x005ae6c0, '??_EScriptContext@RBX@@WME@AEPAXI@Z'),
        (0x005ae6d0, '??_EScriptContext@RBX@@WBA@AEPAXI@Z'),
        (0x005ae6e0, '??_EScriptContext@RBX@@WBE@AEPAXI@Z'),
        (0x005ae6f0, '??_EScriptContext@RBX@@WBDA@AEPAXI@Z'),
        (0x005ae700, '??_EScriptContext@RBX@@WBDE@AEPAXI@Z'),
        (0x005ae710, '??_EScriptContext@RBX@@WCE@AEPAXI@Z'),
        (0x005ae720, '??_EScriptContext@RBX@@WEE@AEPAXI@Z'),
        (0x005ae730, '??1ScriptContext@RBX@@UAE@XZ'),
        (0x005aed20, '??_GScriptContext@RBX@@UAEPAXI@Z'),
    ],
}
# rows built in this unit that are not exact (recorded, never counted)
NEAR = {
    'unit': [
        (0x005a8ec0, '?on_tostring@?$Bridge@V?$shared_ptr@VDescribedBase@Reflection@RBX@@@boost@@$0A@@Lua@RBX@@KAHABV'),
        (0x005a9520, '?on_newindex@?$Bridge@VCoordinateFrame@G3D@@$00@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a9640, '?on_newindex@?$Bridge@VVector3@G3D@@$00@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a9760, '?on_newindex@?$Bridge@Vconnection@signals@boost@@$00@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a9840, '?on_newindex@?$Bridge@V?$shared_ptr@VNode@ThreadRef@Lua@RBX@@@boost@@$00@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a98e0, '?on_newindex@?$Bridge@VColor3@G3D@@$00@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a99f0, '?on_newindex@?$Bridge@VBrickColor@RBX@@$00@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a89d0, '?on_newindex@?$Bridge@V?$shared_ptr@VDescribedBase@Reflection@RBX@@@boost@@$0A@@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a9d80, '?on_newindex@?$Bridge@V?$shared_ptr@VSignalInstance@Reflection@RBX@@@boost@@$0A@@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a8bb0, '?on_newindex@?$Bridge@PBVItem@EnumDescriptor@Reflection@RBX@@$0A@@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a9e30, '?on_newindex@?$Bridge@PBVAllEnumDescriptors@Lua@RBX@@$0A@@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a9f40, '?on_newindex@?$Bridge@PBVEnumDescriptor@Reflection@RBX@@$0A@@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a9580, '?on_eq@?$Bridge@VCoordinateFrame@G3D@@$00@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a96a0, '?on_eq@?$Bridge@VVector3@G3D@@$00@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005a9940, '?on_eq@?$Bridge@VColor3@G3D@@$00@Lua@RBX@@KAHPAUlua_State@@@Z'),
        (0x005ac560, '??$getValue@VValue@Reflection@RBX@@@?$Bridge@V?$shared_ptr@VDescribedBase@Reflection@RBX@@@boost@@$0A@@Lua@RBX@@SA_NPAUlua_State@@IAAVValue@Reflection@2@@Z'),
    ],
}
REJECTED = {}

# Bridge<T> Lua C-function wrappers (on_index / on_newindex / on_gc / on_tostring / on_eq taking lua_State*) that are not
# counted here (not exact, or their own callee is not verified) but are referenced by counted registerClass rows: each
# referenced address is accepted only when the original body there reads the className static of the same T (its
# luaL_checkudata argument), and is listed under structural_targets (never counted).
WRAPPER = re.compile(r'^\?(on_index|on_newindex|on_gc|on_tostring|on_eq)@\?\$Bridge@(.*)@Lua@RBX@@KAHPAUlua_State@@@Z$')
WRAPPER_AT = {
    0x005a9520: 'VCoordinateFrame@G3D@@$00', 0x005a9640: 'VVector3@G3D@@$00',
    0x005a9760: 'Vconnection@signals@boost@@$00', 0x005a9840: 'V?$shared_ptr@VNode@ThreadRef@Lua@RBX@@@boost@@$00',
    0x005a98e0: 'VColor3@G3D@@$00', 0x005a99f0: 'VBrickColor@RBX@@$00',
    0x005a89d0: 'V?$shared_ptr@VDescribedBase@Reflection@RBX@@@boost@@$0A@',
    0x005a9d80: 'V?$shared_ptr@VSignalInstance@Reflection@RBX@@@boost@@$0A@',
    0x005a8bb0: 'PBVItem@EnumDescriptor@Reflection@RBX@@$0A@', 0x005a9e30: 'PBVAllEnumDescriptors@Lua@RBX@@$0A@',
    0x005a9f40: 'PBVEnumDescriptor@Reflection@RBX@@$0A@',
    0x005a9580: 'VCoordinateFrame@G3D@@$00', 0x005a96a0: 'VVector3@G3D@@$00', 0x005a9940: 'VColor3@G3D@@$00',
    0x005a97c0: 'Vconnection@signals@boost@@$00', 0x005a9870: 'V?$shared_ptr@VNode@ThreadRef@Lua@RBX@@@boost@@$00',
    0x005a8a00: 'V?$shared_ptr@VDescribedBase@Reflection@RBX@@@boost@@$0A@',
    0x005a9d40: 'V?$shared_ptr@VDescribedBase@Reflection@RBX@@@boost@@$0A@',
}


def classname(symbol, value):
    """Bridge<T>::className: the address must be the listed static and its constant pointer must name the string."""
    if not symbol.startswith('?className@?$Bridge@'):
        return None
    for key, (address, text) in CLASSNAMES.items():
        if symbol.startswith('?className@?$Bridge@' + key + '@Lua@RBX@@'):
            assert value == address and original.string(d(value)) == text, (symbol, hex(value))
            return 'className static -> %r' % text
    raise AssertionError(('unlisted className', symbol, hex(value)))


def wrapper(symbol, value):
    m = WRAPPER.match(symbol)
    if not m or symbol in own:
        return None
    key = m.group(2)
    assert WRAPPER_AT.get(value) == key, (symbol, hex(value))
    body, refs = target_of(value)
    reads = {struct.unpack_from('<I', body, r)[0] for r in refs} & {a for a, _ in CLASSNAMES.values()}
    assert reads == {CLASSNAMES[key][0]}, (symbol, hex(value), [hex(x) for x in reads])
    structural_out['%08x' % value] = '%s(lua_State*) wrapper of Bridge<%s> (reads className %s; not counted here)' % (
        m.group(1), key, CLASSNAMES[key][1])
    return 'structural: %s wrapper reading className %r' % (m.group(1), CLASSNAMES[key][1])


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
    for address, key in rows:
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
        how = classname(symbol, value)
        if how:
            pass
        elif hit is not None:
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
        elif symbol.startswith('??_7') and symbol in own:
            assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
            how = 'own row'
        elif symbol.startswith('??_7') and symbol not in EXTERNAL:
            rtti, offset_in_object = original.vtable_class(value)
            cls = symbol[4:symbol.index('@@6B') + 2]
            assert rtti == '.?AV' + cls, (name, symbol, hex(value), rtti)
            how = 'vtable (RTTI %s, offset %#x)' % (rtti, offset_in_object)
        elif symbol in own:
            assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
            how = 'own row'
        elif wrapper(symbol, value):
            how = wrapper(symbol, value)
        elif support_key(symbol):
            assert SUPPORT[support_key(symbol)] == value, (name, symbol, hex(value))
            sbody, srefs = bodies[symbol]
            starget, strefs = target_of(value)
            assert match.exact_match(starget, strefs, sbody, srefs), ('support body not exact', symbol, hex(value))
            support_out[symbol] = '%#x (support body exact at the bound address, not counted here)' % value
            how = 'support body exact at the bound address'
        elif symbol in EXTERNAL:
            assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
            how = 'external' + (' (evidence name)' if names.get(value, '') == symbol else '')
        elif names.get(value, '') == symbol:
            how = 'external (evidence name)'
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


def reloc_offsets(raw, sections, definitions, name, size):
    start, section = definitions[name]
    table = sections[section]
    out = set()
    for i in range(table[7]):
        offset, _, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        offset -= start
        if 0 <= offset < size and kind != 20:      # DIR32 fields (the image's base relocations); REL32 are bound
            out.add(offset)
    return out


def verify(which, rows, own, strict=True, record=True):
    raw = Path(OBJ[which]).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    result = []
    for address, name in rows:
        body, refs = bodies[name]
        target, target_refs = target_of(address)
        exact = match.exact_match(target, target_refs, body, refs)
        # the masked compare uses the union of both relocation sets: also require the same absolute (DIR32) fields
        same_relocs = exact and reloc_offsets(raw, sections, definitions, name, len(body)) == set(target_refs)
        entry = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target),
                 'exact': bool(exact and same_relocs)}
        if exact and not same_relocs:
            entry['note'] = 'bytes equal under the union mask but the DIR32 field offsets differ'
        if not entry['exact']:
            assert not strict or DISCOVER, (name, entry['address'], len(body), len(target), entry.get('note'))
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
groups = {k: verify(k, rows, own) for k, rows in resolved.items()}
near = {k: verify(k, resolve(OBJ[k], rows), own, strict=False, record=False) for k, rows in NEAR.items()}
for k, rows in near.items():
    for r in rows:
        assert not r['exact'], ('near-miss row became exact: move it to ROWS', r['address'])


def vtable_slots(obj_path, prefix, candidates):
    """Every vtable of the current-header object whose symbol starts with `prefix` is matched to the original vtable
    (same RTTI class, same COL subobject / constructor-displacement offsets, same slot count) whose bound slots agree;
    a slot whose function is a row proven here must hold that row's address."""
    raw = Path(obj_path).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    known = dict(own)
    known.update(EXTERNAL)
    code_range = range(0x401000, 0x7e0000)
    out = {}
    for symbol in sorted(s for s in definitions if s.startswith(prefix)):
        start, sec = definitions[symbol]
        table = sections[sec]
        relocs = sorted((struct.unpack_from('<IIH', raw, table[5] + 10 * k)) for k in range(table[7]))
        slots = [(off - start, symbols[idx][0]) for off, idx, kind in relocs if kind == 6 and off >= start]
        slots = [x for x in slots if x[0] < table[3] - start]
        col = [symbols[idx][0] for off, idx, kind in relocs if kind == 6 and off == start - 4]
        assert len(col) == 1 and col[0].startswith('??_R4'), (symbol, col)
        cstart, csec = definitions[col[0]]
        cpos = sections[csec][4] + cstart
        sub_offset, cd_offset = struct.unpack_from('<II', raw, cpos + 4)
        matches = []
        for address in candidates:
            locator = d(address - 4)
            if struct.unpack('<II', original.data(locator + 4, 8)) != (sub_offset, cd_offset):
                continue
            originals = [d(address + 4 * k) for k in range(len(slots) + 1)]
            if not (all(v in code_range for v in originals[:-1]) and originals[-1] not in code_range):
                continue
            checked, ok = [], True
            for off, target_symbol in slots:
                expect = known.get(target_symbol)
                value = originals[off // 4]
                if expect is not None:
                    if expect != value:
                        ok = False
                        break
                    checked.append('%d %s = %#x' % (off // 4, target_symbol[:80], value))
            if ok:
                matches.append((address, checked))
        assert len(matches) == 1, ('vtable match', symbol, [hex(a) for a, _ in matches])
        address, checked = matches[0]
        out[symbol] = {'address': '%#x' % address, 'subobject_offset': '%#x' % sub_offset, 'slots': len(slots),
                       'checked_bound_slots': checked}
    return out


def rtti_class(value):
    try:
        return original.vtable_class(value)[0]
    except Exception:
        return None


def vptr_candidates(address, cls):
    body, refs = target_of(address)
    return sorted({v for v in (struct.unpack_from('<I', body, r)[0] for r in refs)
                   if 0x7e0000 <= v < 0x900000 and rtti_class(v) == cls})


# original vtables: the vptr stores of ~ScriptContext 005ae730 (counted here) and ~FactoryProduct 005a8790 (counted here)
SC_CANDIDATES = vptr_candidates(0x5ae730, '.?AVScriptContext@RBX@@')
FP_CLASS = '.?AV?$FactoryProduct@VScriptContext@RBX@@VInstance@2@$1?sScriptContext@2@3PADA@RBX@@'
FP_CANDIDATES = vptr_candidates(0x5a8790, FP_CLASS)
vtables = vtable_slots(OBJ['lifetime'], '??_7ScriptContext@RBX@@6B', SC_CANDIDATES)
vtables.update(vtable_slots(OBJ['lifetime'], '??_7?$FactoryProduct@VScriptContext@RBX@@', FP_CANDIDATES))
assert len(SC_CANDIDATES) == len([k for k in vtables if k.startswith('??_7ScriptContext')]) or DISCOVER, SC_CANDIDATES
bound_rows = {int(c.split(' = ')[1], 16) for v in vtables.values() for c in v['checked_bound_slots']}
# every ??_E thunk counted here must be the slot the original vtable of its subobject holds (??_G 005aed20 / 005a8e50
# are reached only through these thunks: the primary GuidItem vtable has no destructor slot)
THUNK_ROWS = [a for a, n in ROWS['lifetime'] if n.startswith('??_E')]
for row in THUNK_ROWS:
    assert row in bound_rows or DISCOVER, ('vtable slot not checked', hex(row))

if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for g, rows in list(groups.items()) + [('near', sum(near.values(), []))]:
        for r in rows:
            print('EXACT' if r['exact'] else 'NOT EXACT', g, r['address'], r['symbol'][:90], r['size'], r['target_size'],
                  r.get('note', ''))
    print(json.dumps(vtables, indent=1)[:3000])
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
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if '005a8000' <= a < '005b0000'}

# range rows (functions.jsonl) with the unit each lies in
RANGE_ROWS = [json.loads(l) for l in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines() if l.strip()]
RANGE_ROWS = [r for r in RANGE_ROWS if 0x5a8000 <= int(r['addr'], 16) < 0x5b0000]
UNITS = [
    ('guid tail', 0x5a8000, 0x5a8590),
    ('script-context', 0x5a8590, 0x5b0000),
]
unit_rows = {}
for r in RANGE_ROWS:
    a = int(r['addr'], 16)
    unit = [u for u, lo, hi in UNITS if lo <= a < hi][0]
    unit_rows.setdefault(unit, []).append(r['addr'])

UNIT_MAP = {
    'guid tail ..005a858f': (
        'util/Guid.cpp, continued from 005a80d0 (app-unit5a0 unit map): generateGUID 005a8140 (CoCreateGuid / '
        'StringFromGUID2 / WideCharToMultiByte imports), Data::operator< 005a8210, initLocalScope 005a8260, Guid() '
        '005a8300 (boost::call_once 00557330), the scope / index comparisons 005a8330 / 005a83b0 and readableString '
        '005a8440 ("%%s_%%d"). Owner: native-classes/Guid.cpp / util/Guid.h (guid-working-probe.json records them '
        'relocation-normalized but does not count them). Built here from the committed Guid.cpp compiled unchanged: '
        'makeGuidString 005a80d0, generateGUID 005a8140, initLocalScope 005a8260, Guid() 005a8300 (4 counted rows). '
        'Not exact from the donor shapes: Data::operator< 005a8210 (86/70 B), Data::readableString 005a8440 (303/324 B); '
        'not attempted: 005a8200 (Data copy), 005a82e0 (localScope getter), 005a8330 / 005a83b0 (compare).'),
    'script-context 005a8590..005affff': (
        'script/ScriptContext.cpp (continues to 005b071f, app-unit5b0 unit map). Boundary: after Guid.cpp readableString '
        '005a8440; Lua::ScopedPopper::~ScopedPopper 005a8590 (called only from this unit\'s EH funclets 007d35c5 / '
        '007d363c) opens the unit. Evidence: RTTI .?AVScriptContext@RBX@@ vtables (vptr stores of ~ScriptContext '
        '005ae730 and ScriptContext() 005ae490, malloc 0x1f8 in Creatable<Instance>::create<ScriptContext> 0042d3f0 = '
        'sizeof ScriptContext), FactoryProduct<ScriptContext, Instance, sScriptContext> ctor 005a8970 / dtor 005a8790 '
        '/ ??_G 005a8e50 and its ??_E thunks 005a8e40..005a8eb0 / 005ad9d0 / 005ad9e0, DescribedCreatable ctor '
        '005ad930, Described<ScriptContext>::classDescriptor 005ad200 ("ScriptContext", classDescriptor<Instance> '
        '0040ad80), the ScriptContext ??_E thunks 005ae690..005ae720 and ??_G 005aed20, the static Lua C functions '
        '(sandboxThread 005a8660, getContext 005a86e0, tick 005a8750, delay 005a9140 ("delay function requires 2 '
        'arguments"), wait 005a9260, the RunService time getter 005a92d0, print 005a9320 ("tostring"), settings() '
        '005adc60, loadfile 005ade40, dofile 005adf80, stats 005aeea0 ("Stats")), setThreadIdentity 005aeaf0 ("io", '
        '"settings"), ScriptImpersonator 005ad8c0, resume 005ae0d0 ("Game script timout"), the timeout hook '
        '005adbf0 / 005ae230, closeState 005ae280 ("Script memory leaks"), openState 005aefa0 ("Failed to create Lua '
        'state"), executeInNewThread 005af940, onServiceProvider 005afd60, startScript 005affa0, reportError 005ac610 '
        '("nSlu", "%%s, line %%d - %%s %%s"), LuaArguments::push 005aba50 / get 005ad380 and pushArguments 005abf90, '
        'the Stats::Item COMDATs 005ad770 / 005ad810 (Item(const char*)) / Creatable::create<Item> 005adb70, and the '
        'Lua bridge template COMDATs this unit is the first to instantiate: Bridge<T>::getObject / on_index / '
        'on_newindex / on_gc / on_tostring / on_eq wrappers, registerClass ("__index" / "__newindex" / "__gc" / '
        '"__eq" / "__tostring") and pushNewObject for CFrame, Vector3, Color3, BrickColor, Object '
        '(shared_ptr<DescribedBase>), RBXScriptSignal, RBXScriptConnection, ThreadRef::Node and Enums / Enum / '
        'EnumItem (className statics listed under classnames), SharedPtrBridge<T>::push, SingletonBridge<T>::push, '
        'getValue / getPtr<Value>, boost::any holder<shared_ptr<DescribedBase>>, plus the STL / boost instantiations '
        'for set<Script*>, vector<shared_ptr<Script>>, vector<WaitingThread>, vector<shared_ptr<Instance>>, '
        'thread_specific_ptr<Security::Context> (functor_manager / tss_adapter) and boost::function invokers. '
        'Library code: none (Lua 5.1.1 lies at 006217f0..00628f73; lapi / lauxlib calls are bound by address). '
        'Maintainer exclusion: none in this range.'),
}

NOT_ATTEMPTED = {
    'gc 005a86c0 / ScopedPopper::~ScopedPopper 005a8590': (
        'out-of-line copies of header inlines (gc is __declspec(noinline) in ScriptContext.h; ~ScopedPopper is called '
        'only from EH funclets): emitted only by the callers (closeState / startScript / executeInNewThread), which are '
        'not built here'),
    'delay 005a9140 / wait 005a9260': (
        'call YieldingThreads::queueWaiter(lua_State*, double) 006214e0 through yieldEvent (+0x1a8): the native '
        'ScriptContext.h holds scoped_ptr<Lua::YieldingThreads> of the donor ScriptEvent.h (float queueWaiter); the '
        '2008 class is LuaBridge2008/LuaYieldingThreads2008.h YieldingThreads2008 (proposal)'),
    'openState / closeState / executeInNewThread / resume / startScript / onServiceProvider / reportError / '
    'loadfile / dofile / stats / timeout hook': (
        'large members needing 2008 declarations not in the native headers (LuaAllocator, the timeout fields '
        '+0x1c8.. and the 00976b78 counter, Stats::Item binds, ObjectBridge registration); next pass'),
    'STL / boost instantiations (vector<shared_ptr<Script>>, vector<WaitingThread>, set<Script*>, tss_adapter, '
    'boost::function invokers)': (
        'ICF-folded bodies shared by several instantiations (e.g. 005aaa00, 005acc50, 005ace90, 005ad190, 005ab470, '
        '005acc70): bytes match more than one candidate, identity not proven by a relocation; not counted'),
    'boost::any holder<shared_ptr<DescribedBase>> ~holder 005ab000 / ??_G 005ab070': (
        'bytes exact (and holder::type 005acd00, whose type descriptor 0092bf60 is .?AV?$vector@VValue@...: another holder), but ~holder stores the placeholder vtable 008265e4, an ICF-folded vtable whose COL names '
        '.?AVItem@?$Association@VInstance@RBX@@@RBX@@: the vtable cannot be verified by RTTI; not counted'),
    'Bridge<T>::getValue<Value> 005ac0d0 .. 005ac270, 005a9c70.. enum registerClass, pushVector3 / Color3 / CFrame '
    'helpers': 'not exact in this build or bound to rows of the lua-bridge2008 owner; see not_exact / next pass',
}

PROPOSALS = {
    'native-headers/script/ScriptContext.h (owner)': (
        'Declare yieldEvent as the 2008 YieldingThreads (LuaBridge2008/LuaYieldingThreads2008.h YieldingThreads2008, '
        'queueWaiter(lua_State*, double) 006214e0): delay 005a9140 and wait 005a9260 load the delay with fstp qword '
        'and call [this+0x1a8]->queueWaiter(L, double). With the donor float class they cannot be exact.'),
    'lua/LuaBridge.h (maintainer: donor header at the donor path, read-only)': (
        'The 2008 Bridge<T>::on_newindex(T&, const char*, lua_State*) was only declared in the class in the units '
        'that instantiate the __newindex wrappers: the 11 wrappers 005a89d0 / 005a8bb0 / 005a9520 / 005a9640 / '
        '005a9760 / 005a9840 / 005a98e0 / 005a99f0 / 005a9d80 / 005a9e30 / 005a9f40 are 48 B and end with '
        '`add esp,0x24; pop edi; xor eax,eax; pop esi; ret` after the call, while the in-class definition lets the '
        'compiler see the throw and drop the return path (45 B). Same finding as lua-bridge2008 (0061f220).'),
    'LuaBridge2008/LuaInstanceBridge2008.h (LuaBridge2008 owner)': (
        'SharedPtrBridge<DescribedBase>::on_tostring(const shared_ptr&, L) 005a8ec0 is 161 B; the header version '
        '(classDescriptor().name) builds 156 B: the target reads the descriptor through [object+8]->+4 (getDescriptor '
        'inline, as getInstance 0061aac0 does).'),
}

receipt = {
    'class': 'RBX ScriptContext unit of the application range 005a8000..005b0000 (2008-06), inactive',
    'compiler': 'VS2008 RTM 21022 (document-swap flags)',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)): nb.sha(p) for p in [SOURCE, OWNER_SOURCE, GUID_SOURCE, Path(__file__).resolve(),
                                                              HEADER]},
    'objects': {k: nb.sha(v) for k, v in OBJ.items()},
    'layout': {
        'ScriptContext': 'sizeof 0x1f8 (malloc 0x1f8 in Creatable<Instance>::create<ScriptContext> 0042d3f0); '
                         'globalState +0x138 (gc 005a86c0, getThreadCount 005a9120; +8 from the '
                         'Listener<RunService, RunTransition> subobject at +0x130 in onEvent 005a8770); yieldEvent '
                         '+0x1a8 (wait 005a9260); RobloxExtraSpace 12 bytes before lua_State (getThreadCount reads '
                         '[L-0xc] -> *threadCount)',
    },
    'classnames': {'%08x' % a: t for a, t in CLASSNAMES.values()},
    'unit_map': UNIT_MAP,
    'unit_rows': {u: {'rows': len(v), 'span': '%s..%s' % (v[0], v[-1])} for u, v in unit_rows.items()},
    'range_rows_total': len(RANGE_ROWS),
    # Written as 'ADDR counted by RECEIPT' text, never as a quoted bare address: some recorders (local_backpack,
    # viewnew_brick_build, viewnew_part_mesh) treat any '"ADDR"' in another receipt as counted there and drop it.
    'range_rows_counted_by_other_receipts': ['%s counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()],
    'rows': groups,
    'support_rows': support_out,
    'structural_targets': ['%s: %s' % (a, t) for a, t in sorted(structural_out.items())],
    'vtables_current_headers': vtables,
    'not_exact': ['%s %s: %d/%d B, not counted' % (r['address'], r['symbol'][:70], r['size'], r['target_size'])
                  for rows in near.values() for r in rows],
    'not_attempted': NOT_ATTEMPTED,
    'rejected': REJECTED,
    'proposals': PROPOSALS,
    'exact_function_rows': exact_rows,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit5a8-2008: %d counted exact rows (%s); %d vtables checked, %d support rows, %d range rows '
      '(%d counted elsewhere)' % (len(exact_rows), ' '.join(exact_rows), len(vtables), len(support_out),
                                  len(RANGE_ROWS), len(range_counted)))
