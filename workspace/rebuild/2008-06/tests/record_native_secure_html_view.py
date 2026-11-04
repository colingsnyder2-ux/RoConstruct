"""Verify the inactive native CSecureHtmlView (CHtmlView subclass, base of CWebToolbox and the browser views):
layout test, 7 exact bodies (8 symbols; GetThisClass folds with GetRuntimeClass) and every call/data target.
Writes work/2008-06/shared-layouts/secure-html-view-working.json.
"""
import json
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from native_bind import ROOT, Original, compile_unit, flags, sha, verify  # noqa: E402

source = ROOT / 'rebuild/2008-06/native-classes/CSecureHtmlView.cpp'
fixture = ROOT / 'rebuild/2008-06/tests/NativeSecureHtmlViewLayout.cpp'
obj = compile_unit(source, 'NativeSecureHtmlView')
compile_unit(fixture, 'NativeSecureHtmlViewLayout')
original = Original()
INTERNAL = {
    '?classCSecureHtmlView@CSecureHtmlView@@2UCRuntimeClass@@B': 0x81b840,
    '??_7CSecureHtmlView@@6B@': 0x81b864,
    '?checkDialogUrl@@YAJPBD@Z': 0x41dcb0,      # same helper committed CRobloxDHtmlDialog.cpp defines
    '?isApplicationUrl@@YA_NPBD@Z': 0x465b50,   # name provisional; body recovery open
}
METHODS = [
    ('?GetRuntimeClass@CSecureHtmlView@@UBEPAUCRuntimeClass@@XZ', 0x465a50),
    ('?GetThisClass@CSecureHtmlView@@SGPAUCRuntimeClass@@XZ', 0x465a50),
    ('??0CSecureHtmlView@@QAE@XZ', 0x465a60),
    ('??1CSecureHtmlView@@UAE@XZ', 0x465a80),
    ('??_GCSecureHtmlView@@UAEPAXI@Z', 0x465b20),
    ('?PreCreateWindow@CSecureHtmlView@@UAEHAAUtagCREATESTRUCTA@@@Z', 0x465ae0),
    ('?OnAmbientProperty@CSecureHtmlView@@UAEHPAVCOleControlSite@@JPAUtagVARIANT@@@Z', 0x465a90),
    ('?OnBeforeNavigate2@CSecureHtmlView@@UAEXPBDK0AAVCByteArray@@0PAH@Z', 0x465d70),
]
rows = verify(original, obj, METHODS, INTERNAL)
runtime = struct.unpack('<IiIIII', original.data(0x81b840, 24))
assert original.data(runtime[0], 16) == b'CSecureHtmlView\0' and runtime[1:5] == (0xf8, 0xffff, 0, 0x433370), runtime
assert original.imported(0x433370 + 5 + struct.unpack('<i', original.data(0x433371, 4))[0])[1] == '?GetThisClass@CHtmlView@@SGPAUCRuntimeClass@@XZ'
paths = [Path(__file__), ROOT / 'rebuild/2008-06/tests/native_bind.py', source, fixture, ROOT / 'rebuild/2008-06/native-headers/CSecureHtmlView.h']
(ROOT / 'work/2008-06/shared-layouts/secure-html-view-working.json').write_text(json.dumps({
    'class': 'CSecureHtmlView', 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)', 'flags': flags(), 'original_sha256': sha(original.path),
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths}, 'object_sha256': sha(obj),
    'layout': {'size': '0xf8', 'flag_f4': '0xf4 bool', 'evidence': 'CRuntimeClass 0081b840; constructor 00465a60 store; OnAmbientProperty test; destructors; compile-time test'},
    'methods': rows, 'open': ['isApplicationUrl 00465b50 (480-byte URL check helper, declared only)'],
    'scope': 'Inactive. 7 exact bodies (8 symbols) with verified targets. No active build, swap or credit.'}, indent=2) + '\n')
print('PASS native CSecureHtmlView: %d exact symbols, targets verified' % len(rows))
