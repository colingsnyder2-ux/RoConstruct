"""Verify the inactive native CWebToolbox (CSecureHtmlView/CHtmlView subclass): layout test, 14 exact bodies,
every call/data target, CRuntimeClass and message map. OnInitialUpdate needs the CString PCXSTR noinline profile
(the original imports it), so the whole unit is compiled through it. Writes shared-layouts/web-toolbox-working.json.
"""
import json
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from native_bind import OUT, ROOT, Original, compile_unit, flags, rebuild, sha, verify  # noqa: E402

source = ROOT / 'rebuild/2008-06/native-classes/CWebToolbox.cpp'
fixture = ROOT / 'rebuild/2008-06/tests/NativeWebToolboxLayout.cpp'
compile_unit(fixture, 'NativeWebToolboxLayout')
pre = OUT / 'web-toolbox-pre'
pre.mkdir(parents=True, exist_ok=True)
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', [x for x in flags() if x != '/c'] + ['/P', str(source)], pre)
assert code == 0, log
body = (pre / 'CWebToolbox.i').read_text(errors='replace')
needle = 'operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );'
assert body.count(needle) == 1
unit = OUT / 'NativeWebToolboxProfile.cpp'
unit.write_text(body.replace(needle, '__declspec(noinline) ' + needle))
obj = OUT / 'NativeWebToolboxProfile.obj'
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD',
                                                       '/Fo' + str(obj), str(unit)], OUT)
assert code == 0, log[-3000:]
original = Original()
INTERNAL = {
    '??0CSecureHtmlView@@QAE@XZ': 0x465a60,
    '??1CSecureHtmlView@@UAE@XZ': 0x465a80,
    '?applicationBaseUrl@@YA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@XZ': 0x4060d0,
    '??HATL@@YA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@0@ABV10@PBD@Z': 0x40e160,
    '?classCWebToolbox@CWebToolbox@@2UCRuntimeClass@@B': 0x81c4a8,
    '?messageMap@?1??GetThisMessageMap@CWebToolbox@@KGPBUAFX_MSGMAP@@XZ@4U3@B': 0x81c73c,
}
METHODS = [
    ('?CreateObject@CWebToolbox@@SGPAVCObject@@XZ', 0x46a850),
    ('??_GCWebToolbox@@UAEPAXI@Z', 0x46a7e0),
    ('?GetRuntimeClass@CWebToolbox@@UBEPAUCRuntimeClass@@XZ', 0x46a580),
    ('?GetMessageMap@CWebToolbox@@MBEPBUAFX_MSGMAP@@XZ', 0x46a8d0),
    ('?OnInitialUpdate@CWebToolbox@@UAEXXZ', 0x46a710),
    ('?OnActivateView@CWebToolbox@@UAEXHPAVCView@@0@Z', 0x46a6a0),
    ('?OnGetExternal@CWebToolbox@@UAEJPAPAUIDispatch@@@Z', 0x46a8e0),
    ('?OnGetHostInfo@CWebToolbox@@UAEJPAU_DOCHOSTUIINFO@@@Z', 0x46a680),
    ('?OnDocWindowActivate@CWebToolbox@@UAEJH@Z', 0x46a640),
    ('?OnFrameWindowActivate@CWebToolbox@@UAEJH@Z', 0x46a660),
    ('?OnGetMinMaxInfo@CWebToolbox@@QAEXPAUtagMINMAXINFO@@@Z', 0x46a7a0),
    ('?OnSetFocus@CWebToolbox@@QAEXPAVCWnd@@@Z', 0x46a6d0),
    ('?OnMouseActivate@CWebToolbox@@QAEHPAVCWnd@@II@Z', 0x46a6f0),
    ('?OnLButtonUp@CWebToolbox@@QAEXIVCPoint@@@Z', 0x46a7c0),
]
rows = verify(original, obj, METHODS, INTERNAL)
runtime = struct.unpack('<IiIIII', original.data(0x81c4a8, 24))
assert original.data(runtime[0], 12) == b'CWebToolbox\0' and runtime[1:5] == (0x100, 0xffff, 0x46a850, 0x436060), runtime
base_getter, entries = struct.unpack('<II', original.data(0x81c73c, 8))
assert original.imported(base_getter)[1] == '?GetThisMessageMap@CHtmlView@@KGPBUAFX_MSGMAP@@XZ'
handlers = [struct.unpack('<6I', original.data(entries + 24 * i, 24)) for i in range(6)]
assert [(h[0], h[5]) for h in handlers] == [(0x24, 0x46a7a0), (0x7, 0x46a6d0), (0x21, 0x46a6f0), (0x202, 0x46a7c0), (0x6, 0x46a7c0), (0, 0)], handlers
paths = [Path(__file__), ROOT / 'rebuild/2008-06/tests/native_bind.py', source, fixture,
         ROOT / 'rebuild/2008-06/native-headers/CWebToolbox.h', ROOT / 'rebuild/2008-06/native-headers/CSecureHtmlView.h']
(ROOT / 'work/2008-06/shared-layouts/web-toolbox-working.json').write_text(json.dumps({
    'class': 'CWebToolbox', 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)', 'flags': flags(),
    'profile': 'CString operator PCXSTR noinline (original imports it)', 'original_sha256': sha(original.path),
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths}, 'object_sha256': sha(obj),
    'layout': {'size': '0x100', 'base': 'CSecureHtmlView 0xf8 (CHtmlView 0xf4 + flag_f4)', 'field_f8': '0xf8 CWnd* (read by every handler, never written in the image)',
               'external': '0xfc CComPtr<IDispatch>', 'evidence': 'CRuntimeClass 0081c4a8 and CreateObject operator new(0x100); inlined constructor; deleting destructor 0046a7e0; compile-time sizeof/offsetof test'},
    'methods': rows, 'runtime_class': {'address': '0081c4a8', 'size': '0x100', 'create': '0046a850'},
    'message_map': {'address': '0081c73c', 'entries': ['WM_GETMINMAXINFO 0046a7a0', 'WM_SETFOCUS 0046a6d0', 'WM_MOUSEACTIVATE 0046a6f0', 'WM_LBUTTONUP 0046a7c0', 'WM_ACTIVATE 0046a7c0 (folded with OnLButtonUp)']},
    'open': ['CSecureHtmlView bodies 00465a60/00465a80/00465b20/00465ae0/00465a90/00465d70 (separate class, declared only)'],
    'scope': 'Inactive; the original image never references this class outside its own code. No active build, swap or credit.'},
    indent=2) + '\n')
print('PASS native CWebToolbox: %d exact bodies, targets verified' % len(rows))
