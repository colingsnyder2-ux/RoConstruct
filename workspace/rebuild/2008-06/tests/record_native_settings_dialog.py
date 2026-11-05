"""Verify the inactive native CSettingsDialog: layout test, 9 exact bodies, every call/data target, class data.

Compiled with the XTP 11.2.2 headers (CXTSplitterWnd member). Uses native_bind.py for the target checks.
Writes work/2008-06/shared-layouts/settings-dialog-working.json.
"""
import json
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from native_bind import ROOT, XTP_FLAGS, Original, compile_unit, flags, sha, verify

source = ROOT / 'rebuild/2008-06/native-classes/CSettingsDialog.cpp'
fixture = ROOT / 'rebuild/2008-06/tests/NativeSettingsDialogLayout.cpp'
obj = compile_unit(source, 'NativeSettingsDialog', XTP_FLAGS)
compile_unit(fixture, 'NativeSettingsDialogLayout', XTP_FLAGS)
original = Original()

# Internal targets: original call sites, RTTI-identified constructors/destructors, existing receipts and names.
INTERNAL = {
    '??$create@VSelection@RBX@@@ServiceProvider@RBX@@QBEPAVSelection@1@XZ': 0x4153b0,
    '??0CPropGrid@@QAE@XZ': 0x442b20,
    '??0CXTSplitterWnd@@QAE@XZ': 0x708c50,
    '??1CXTSplitterWnd@@UAE@XZ': 0x708280,
    '??1?$shared_ptr@VGlobalSettings@RBX@@@boost@@QAE@XZ': 0x600660,
    '??1CSelectionPropGrid@@UAE@XZ': 0x430700,
    '??_7CSettingsDialog@@6B@': 0x81bfb4,
    '?classCSettingsDialog@CSettingsDialog@@2UCRuntimeClass@@B': 0x81bd90,
    '?classCSettingsExplorer@CSettingsExplorer@@2UCRuntimeClass@@B': 0x81bdac,
    '?eraseSettingsStore@GlobalSettings@RBX@@QAEXXZ': 0x5684d0,
    '?messageMap@?1??GetThisMessageMap@CSettingsDialog@@KGPBUAFX_MSGMAP@@XZ@4U3@B': 0x81c120,
    '?setRoot@CInstanceExplorer@@QAEXPAVInstance@RBX@@@Z': 0x421a50,
    '?setSelection@CSelectionPropGrid@@QAEXPAVSelection@RBX@@@Z': 0x442650,
    '?singleton@GlobalSettings@RBX@@SA?AV?$shared_ptr@VGlobalSettings@RBX@@@boost@@XZ': 0x5690f0,
}
METHODS = [
    ('??0CSettingsDialog@@QAE@PAVCWnd@@@Z', 0x466e10),
    ('??1CSettingsDialog@@UAE@XZ', 0x466ca0),
    ('??_GCSettingsDialog@@UAEPAXI@Z', 0x466d10),
    ('?GetRuntimeClass@CSettingsDialog@@UBEPAUCRuntimeClass@@XZ', 0x466b60),
    ('?_GetBaseClass@CSettingsDialog@@KGPAUCRuntimeClass@@XZ', 0x41f9b0),
    ('?GetMessageMap@CSettingsDialog@@MBEPBUAFX_MSGMAP@@XZ', 0x466e00),
    ('?CreateObject@CSettingsDialog@@SGPAVCObject@@XZ', 0x466fa0),
    ('?OnResetSettings@CSettingsDialog@@QAEXXZ', 0x466c00),
    ('?OnInitDialog@CSettingsDialog@@UAEHXZ', 0x467030),
]
rows = verify(original, obj, METHODS, INTERNAL)

# CRuntimeClass 0081bd90: name, size 0x3d4, schema 0xffff, CreateObject 00466fa0, base getter 0041f9b0.
runtime = struct.unpack('<IiIIII', original.data(0x81bd90, 24))
assert original.data(runtime[0], 16) == b'CSettingsDialog\0'
assert runtime[1:5] == (0x3d4, 0xffff, 0x466fa0, 0x41f9b0), runtime
# CSettingsExplorer CRuntimeClass 0081bdac: size 0x3cc (CInstanceExplorer's), CreateObject 00466b90.
explorer = struct.unpack('<IiIIII', original.data(0x81bdac, 24))
assert original.data(explorer[0], 18) == b'CSettingsExplorer\0' and explorer[1:4] == (0x3cc, 0xffff, 0x466b90), explorer
# Message map 0081c120: CDialog base getter and one BN_CLICKED (WM_COMMAND code 0) 1002 entry -> 00466c00.
base_getter, entries = struct.unpack('<II', original.data(0x81c120, 8))
assert original.imported(base_getter)[1] == '?GetThisMessageMap@CDialog@@KGPBUAFX_MSGMAP@@XZ'
assert struct.unpack('<6I', original.data(entries, 24))[:4] == (0x111, 0, 1002, 1002)
assert struct.unpack('<6I', original.data(entries, 24))[5] == 0x466c00
assert struct.unpack('<6I', original.data(entries + 24, 24)) == (0, 0, 0, 0, 0, 0)
# The three CSettingsPropGrid tables stored by the constructor carry CSettingsPropGrid RTTI.
for table in (0x81c174, 0x81c168, 0x81c15c):
    assert original.vtable_class(table)[0] == '.?AVCSettingsPropGrid@@'

headers = ['CSettingsDialog.h', 'CSettingsExplorer.h', 'CInstanceExplorer.h', 'CSettingsPropGrid.h']
paths = [Path(__file__), ROOT / 'rebuild/2008-06/tests/native_bind.py', source, fixture] + \
        [ROOT / 'rebuild/2008-06/native-headers' / h for h in headers]
(ROOT / 'work/2008-06/shared-layouts/settings-dialog-working.json').write_text(json.dumps({
    'class': 'CSettingsDialog', 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)', 'flags': flags() + XTP_FLAGS,
    'original_sha256': sha(original.path),
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths}, 'object_sha256': sha(obj),
    'layout': {'size': '0x3d4', 'splitter': '0x74 (CXTSplitterWnd, 0x118)', 'explorer': '0x18c (CSettingsExplorer*)',
               'propGrid': '0x190 (CSettingsPropGrid == CSelectionPropGrid, 0x244)',
               'evidence': 'CRuntimeClass 0081bd90 and CreateObject operator new(0x3d4); constructor 00466e10 and destructor 00466ca0; OnInitDialog store at +0x18c; compile-time sizeof/offsetof test'},
    'methods': rows,
    'runtime_class': {'address': '0081bd90', 'size': '0x3d4', 'create': '00466fa0', 'base_getter': '0041f9b0'},
    'message_map': {'address': '0081c120', 'entries': [{'message': 'WM_COMMAND', 'code': 'BN_CLICKED', 'id': 1002, 'handler': '00466c00'}]},
    'open': ['CInstanceExplorer::setRoot 00421a50 and the CInstanceExplorer layout (0x3cc)',
             'CSettingsExplorer runtime class functions 00466b70/00466b80/00466b90'],
    'scope': 'Inactive. 9 exact bodies with verified call/data targets. Names OnResetSettings, setRoot, splitter, explorer and propGrid are chosen names. No active build, swap or credit.'},
    indent=2) + '\n')
print('PASS native CSettingsDialog: %d exact methods, targets verified' % len(rows))
