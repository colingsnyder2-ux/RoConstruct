"""Verify the inactive native CBrowserView (CXTPCommandBarsSiteBase<CSecureHtmlView> subclass) with its thin subclasses
CIDEBrowserView/CPlayBrowserView: layout test, exact bodies, every call/data target, CRuntimeClass records and message map.
Profile: document-swap flags + XTP 11.2.2 headers; the original imports CString operator PCXSTR and CSimpleStringT::IsEmpty,
so the unit is compiled through the noinline profile for both. XTP call targets are proven by compiling the XTP 11.2.2
library units (xtp-11.2.2-shared-mfc style: /O2 /MD /GS /EHsc /Ob1) and matching their bodies at the bound address.
Writes work/2008-06/shared-layouts/browser-view-working.json.
"""
import json
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(HERE))
import native_bind  # noqa: E402
from native_bind import XTP_FLAGS, Original, flags, match, rebuild, sha, verify  # noqa: E402

OUT = ROOT / 'rebuild/2008-06/out/native-layouts/browser-view'
OUT.mkdir(parents=True, exist_ok=True)
FLAGS = flags()
INC = []
HEADERS = ROOT / 'rebuild/2008-06/native-headers'
tool = rebuild.toolchain(21022)

# 1. layout test
code, log = rebuild.run(tool, 'cl', FLAGS + XTP_FLAGS + INC + ['/Fo' + str(OUT / 'NativeBrowserViewLayout.obj'),
                                                             str(HERE / 'NativeBrowserViewLayout.cpp')], OUT)
assert code == 0, log[-3000:]

# 2. unit through the noinline profile
source = ROOT / 'rebuild/2008-06/native-classes/CBrowserView.cpp'
code, log = rebuild.run(tool, 'cl', [x for x in FLAGS if x != '/c'] + XTP_FLAGS + INC + ['/P', str(source)], OUT)
assert code == 0, log[-3000:]
body = (OUT / 'CBrowserView.i').read_text(errors='replace')
for needle in ('operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );',
               'bool IsEmpty() const throw()\n\t{\n\t\treturn( GetLength() == 0 );'):
    assert body.count(needle) == 1, needle
    body = body.replace(needle, '__declspec(noinline) ' + needle)
unit = OUT / 'NativeBrowserViewProfile.cpp'
unit.write_text(body)
obj = OUT / 'NativeBrowserViewProfile.obj'
code, log = rebuild.run(tool, 'cl', ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/Fo' + str(obj), str(unit)], OUT)
assert code == 0, log[-3000:]

# 3. XTP library bodies for the out-of-line XTP calls
XTP_SRC = ROOT / 'tools/libs/xtp-11.2.2/Source'
xtp_bodies = {}
for rel in ('CommandBars/XTPToolBar.cpp', 'CommandBars/XTPControlComboBox.cpp', 'CommandBars/XTPControl.cpp',
            'CommandBars/XTPPaintManager.cpp', 'CommandBars/XTPCommandBar.cpp', 'CommandBars/XTPCommandBars.cpp',
            'Common/XTPImageManager.cpp'):
    o = OUT / ('xtp_' + Path(rel).stem + '.obj')
    base = ['/nologo', '/c', '/O2', '/MD', '/GS', '/EHsc', '/Ob1', '/D_AFXDLL', '/D_XTP_STATICLINK', '/D_DLL',
            '/I' + str(XTP_SRC), '/I' + str(ROOT / 'tools/libs/mfc-9.0/atlmfc/include')]
    code, log = rebuild.run(tool, 'cl', base + ['/Fo' + str(o), str(XTP_SRC / rel)], OUT)
    if code:  # recipe xtp-11.2.2-shared-mfc-internals: MFC private declarations
        code, log = rebuild.run(tool, 'cl', base + ['/I' + str(ROOT / 'tools/libs/mfc-9.0/atlmfc/src/mfc'),
                                                    '/FIXTToolkitPro.h', '/FIafximpl.h', '/Fo' + str(o), str(XTP_SRC / rel)], OUT)
    assert code == 0, (rel, log[-2000:])
    for n, b, r in match.coff_functions(o.read_bytes()):
        xtp_bodies.setdefault(n, (b, r))

XTP_TARGETS = {
    '??0CXTPToolBar@@QAE@XZ': 0x6c1da0,
    '??1CXTPToolBar@@UAE@XZ': 0x6c1eb0,
    '?CreateToolBar@CXTPToolBar@@QAEHKPAVCWnd@@I@Z': 0x6c2440,
    '?GetThisClass@CXTPToolBar@@SGPAUCRuntimeClass@@XZ': 0x6c1b10,
    '?XTPImageManager@@YAPAVCXTPImageManager@@XZ': 0x6c0e80,
    '?SetTheme@CXTPPaintManager@@SAXW4XTPPaintTheme@@@Z': 0x6af0a0,
    '?SetPaintManager@CXTPCommandBar@@QAEXPAVCXTPPaintManager@@@Z': 0x6b4ea0,
    '?SetImageManager@CXTPCommandBar@@QAEXPAVCXTPImageManager@@@Z': 0x6b4f20,
    '??0CXTPControlComboBox@@QAE@PAVCXTPCommandBars@@@Z': 0x6a7960,
    '?SetDropDownListStyle@CXTPControlComboBox@@QAEXH@Z': 0x6a6cb0,
    '?GetComboBoxPopupBar@CXTPControlComboBox@@QBEPAVCXTPControlComboBoxPopupBar@@XZ': 0x6a81e0,
    '?GetEditText@CXTPControlComboBox@@QBE?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@XZ': 0x6a9640,
    '?SetEditText@CXTPControlComboBox@@QAEXABV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z': 0x6a96f0,
    '?DelayLayoutParent@CXTPControl@@QAEXXZ': 0x6aafc0,
    '?SetFlags@CXTPControl@@QAEXK@Z': 0x6ab360,
    '?SetCaption@CXTPControl@@QAEXPBD@Z': 0x6ab940,
    '?GetThisClass@CXTPEdit@@SGPAUCRuntimeClass@@XZ': 0x6a67c0,
    '?PreTranslateFrameMessage@CXTPCommandBars@@QAEHPAUtagMSG@@@Z': 0x6a4ae0,
    '?OnFrameWndMsg@CXTPCommandBars@@QAEHIIJPAJ@Z': 0x6a4d30,
}
xtp_proof = {}
for symbol, address in XTP_TARGETS.items():
    t, tr, _ = match.target('2008-06', '%08x' % address)
    hit = xtp_bodies.get(symbol)
    xtp_proof[symbol] = 'XTP recipe body exact' if hit and match.exact_match(t, tr, hit[0], hit[1]) else 'bound by call site only'

original = Original()
# The static paint manager pointer: SetTheme 006af0a0 (XTP) writes it; check the data address the XTP body uses.
INTERNAL = dict(XTP_TARGETS)
INTERNAL.update({
    '?s_pInstance@CXTPPaintManager@@1PAV1@A': 0x97e060,
    '??0CSecureHtmlView@@QAE@XZ': 0x465a60,
    '??1CSecureHtmlView@@UAE@XZ': 0x465a80,
    '?OnBeforeNavigate2@CSecureHtmlView@@UAEXPBDK0AAVCByteArray@@0PAH@Z': 0x465d70,
    '?applicationBaseUrl@@YA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@XZ': 0x4060d0,
    '??HATL@@YA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@0@ABV10@PBD@Z': 0x40e160,
    '?loadBrowserIcons@@YAXPAVCXTPImageManager@@@Z': 0x42f380,
    '?isRobloxUrl@@YA_NPBD@Z': 0x56a160,
    '?classCBrowserView@CBrowserView@@2UCRuntimeClass@@B': 0x80cf58,
    '?classCIDEBrowserView@CIDEBrowserView@@2UCRuntimeClass@@B': 0x80cf74,
    '?classCPlayBrowserView@CPlayBrowserView@@2UCRuntimeClass@@B': 0x80cf90,
    '?messageMap@?1??GetThisMessageMap@CBrowserView@@KGPBUAFX_MSGMAP@@XZ@4U3@B': 0x80d414,
})
L = 'list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@'
S = 'V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@'
N = 'U_Node@?$_List_nod@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@'
IT = 'V?$_Iterator@$00@?$' + L
IT0 = 'V?$_Iterator@$0A@@?$' + L
METHODS = [
    ('?CreateObject@CBrowserView@@SGPAVCObject@@XZ', 0x410d60),
    ('?CreateObject@CIDEBrowserView@@SGPAVCObject@@XZ', 0x410dc0),
    ('?CreateObject@CPlayBrowserView@@SGPAVCObject@@XZ', 0x410e20),
    ('??_GCBrowserView@@UAEPAXI@Z', 0x410e80),
    ('?GetRuntimeClass@CBrowserView@@UBEPAUCRuntimeClass@@XZ', 0x40df60),
    ('?GetRuntimeClass@CIDEBrowserView@@UBEPAUCRuntimeClass@@XZ', 0x40df70),
    ('?GetRuntimeClass@CPlayBrowserView@@UBEPAUCRuntimeClass@@XZ', 0x40df80),
    ('?GetMessageMap@CBrowserView@@MBEPBUAFX_MSGMAP@@XZ', 0x40f810),
    ('??0CBrowserView@@QAE@XZ', 0x4108b0),
    ('??1CBrowserView@@UAE@XZ', 0x410950),
    ('??0CIDEBrowserView@@QAE@XZ', 0x410c40),
    ('??0CPlayBrowserView@@QAE@XZ', 0x410cd0),
    ('??1?$CXTPCommandBarsSiteBase@VCSecureHtmlView@@@@UAE@XZ', 0x40e230),
    ('?PreTranslateMessage@?$CXTPCommandBarsSiteBase@VCSecureHtmlView@@@@MAEHPAUtagMSG@@@Z', 0x40e290),
    ('?OnWndMsg@?$CXTPCommandBarsSiteBase@VCSecureHtmlView@@@@MAEHIIJPAJ@Z', 0x40e320),
    ('?OnInitialUpdate@CBrowserView@@UAEXXZ', 0x40ed50),
    ('?OnGetHostInfo@CBrowserView@@UAEJPAU_DOCHOSTUIINFO@@@Z', 0x40dfb0),
    ('?OnCommandStateChange@CBrowserView@@UAEXJH@Z', 0x40dfe0),
    ('?OnDocumentComplete@CBrowserView@@UAEXPBD@Z', 0x40dfd0),
    ('?OnTitleChange@CBrowserView@@UAEXPBD@Z', 0x40e560),
    ('?OnNavigateComplete2@CBrowserView@@UAEXPBD@Z', 0x410ea0),
    ('?OnBeforeNavigate2@CBrowserView@@UAEXPBDK0AAVCByteArray@@0PAH@Z', 0x4109e0),
    ('?OnEraseBkgnd@CBrowserView@@QAEHPAVCDC@@@Z', 0x6e8870),
    ('?OnSize@CBrowserView@@QAEXIHH@Z', 0x40e040),
    ('?OnCreate@CBrowserView@@QAEHPAUtagCREATESTRUCTA@@@Z', 0x40e5b0),
    ('?OnStop@CBrowserView@@QAEXXZ', 0x40e930),
    ('?OnUpdateStop@CBrowserView@@QAEXPAVCCmdUI@@@Z', 0x40e940),
    ('?OnHome@CBrowserView@@QAEXXZ', 0x40e790),
    ('?OnUpdateHome@CBrowserView@@QAEXPAVCCmdUI@@@Z', 0x40e130),
    ('?OnRefresh@CBrowserView@@QAEXXZ', 0x40e7d0),
    ('?OnUpdateRefresh@CBrowserView@@QAEXPAVCCmdUI@@@Z', 0x42e550),
    ('?OnBack@CBrowserView@@QAEXXZ', 0x40e920),
    ('?OnUpdateBack@CBrowserView@@QAEXPAVCCmdUI@@@Z', 0x40e0d0),
    ('?OnForward@CBrowserView@@QAEXXZ', 0x40e7e0),
    ('?OnUpdateForward@CBrowserView@@QAEXPAVCCmdUI@@@Z', 0x40e0f0),
    ('?OnGo@CBrowserView@@QAEXXZ', 0x40e7f0),
    ('?OnUpdateGo@CBrowserView@@QAEXPAVCCmdUI@@@Z', 0x40e110),
    ('?OnAddressExecute@CBrowserView@@QAEXPAUtagNMHDR@@PAJ@Z', 0x40eda0),
    ('?OnCreateControl@CBrowserView@@QAEHPAUXTP_COMMANDBARS_CREATECONTROL@@@Z', 0x40e670),
    # std::list<std::string> instances emitted by this unit (identical COMDATs in the original)
    ('??0?$' + L + 'QAE@XZ', 0x410830),
    ('??1?$' + L + 'QAE@XZ', 0x55e5f0),
    ('?clear@?$' + L + 'QAEXXZ', 0x55dfd0),
    ('?_Buynode@?$' + L + 'IAEPA' + N + 'XZ', 0x40f1c0),
    ('?_Incsize@?$' + L + 'IAEXI@Z', 0x40edd0),
    ('?erase@?$' + L + 'QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@@Z', 0x410350),
    ('??$find@' + IT, 0x410bd0),      # prefix, resolved below
    ('??$_Find@' + IT0, 0x40f7c0),    # prefix, resolved below
]
present = {n for n, b, r in match.coff_functions(obj.read_bytes())}
METHODS = [(n if n in present else next(p for p in sorted(present) if p.startswith(n)), a) for n, a in METHODS]
missing = [n for n, a in METHODS if n not in present]
assert not missing, missing
# CXTPControlComboBox::DeleteItem (XTP AFX_INLINE, emitted out of line by this unit): the analysed extent of 0040e470
# is 81 bytes but includes the next function 0040e4b0; the 64-byte body (ret 4 at 0040e4ad) is exact as a prefix.
DELETE_ITEM = '?DeleteItem@CXTPControlComboBox@@QAEXJ@Z'
db, dr = next((b, r) for n, b, r in match.coff_functions(obj.read_bytes()) if n == DELETE_ITEM)
dt, dtr, _ = match.target('2008-06', '0040e470')
assert len(db) == 64 and dt[63:64] == b'\x00' and dt[61] == 0xc2 and match.exact_match(dt[:64], [x for x in dtr if x < 64], db, dr)
INTERNAL[DELETE_ITEM] = 0x40e470
# list::_Buynode(next, prev, value): the COFF body carries its catch(...) funclet (rethrow after freeing the node);
# the original's analysed extent 0040f1e0 (124 bytes, ret 0Ch) ends before it. Main body exact as a prefix.
BUYNODE = '?_Buynode@?$' + L + 'IAEPA' + N + 'PAU342@0AB' + S + '2@@Z'
bb, br = next((b, r) for n, b, r in match.coff_functions(obj.read_bytes()) if n == BUYNODE)
bt, btr, _ = match.target('2008-06', '0040f1e0')
assert len(bt) == 124 and bt[-3:] == b'\xc2\x0c\x00' and match.exact_match(bt, btr, bb[:124], [x for x in br if x < 124])
INTERNAL[BUYNODE] = 0x40f1e0
# _Incsize throws std::length_error: check the ThrowInfo's catchable types by RTTI name.
_, _, _, cta = struct.unpack('<4I', original.data(0x8d0cc0, 16))
count = struct.unpack('<I', original.data(cta, 4))[0]
names = [original.string(struct.unpack('<I', original.data(struct.unpack('<I', original.data(cta + 4 + 4 * i, 4))[0] + 4, 4))[0] + 8)
         for i in range(count)]
assert names == ['.?AVlength_error@std@@', '.?AVlogic_error@std@@', '.?AVexception@std@@'], names
INTERNAL['__TI3?AVlength_error@std@@'] = 0x8d0cc0
rows = verify(original, obj, METHODS, INTERNAL)
# Folded bodies: the subclass deleting destructors are the same bytes at 00410e80.
for extra in ('??_GCIDEBrowserView@@UAEPAXI@Z', '??_GCPlayBrowserView@@UAEPAXI@Z'):
    rows += verify(original, obj, [(extra, 0x410e80)], INTERNAL, dict(METHODS))

# CRuntimeClass records: name, size, schema, CreateObject, base getter (jmp to CSecureHtmlView/CBrowserView GetRuntimeClass)
def runtime(address, name, create, base_getter):
    rec = struct.unpack('<IiIIII', original.data(address, 24))
    assert original.string(rec[0]) == name and rec[1:5] == (0x2d0, 0xffff, create, base_getter), (name, rec)
runtime(0x80cf58, 'CBrowserView', 0x410d60, 0x436060)      # 00436060: jmp 00465a50 (CSecureHtmlView::GetRuntimeClass)
runtime(0x80cf74, 'CIDEBrowserView', 0x410dc0, 0x40df60)
runtime(0x80cf90, 'CPlayBrowserView', 0x410e20, 0x40df60)
assert original.data(0x436060, 1) == b'\xe9' and 0x436065 + struct.unpack('<i', original.data(0x436061, 4))[0] == 0x465a50

# Message map 0080d414 (base CHtmlView::GetThisMessageMap import)
base_getter, entries = struct.unpack('<II', original.data(0x80d414, 8))
assert original.imported(base_getter)[1] == '?GetThisMessageMap@CHtmlView@@KGPBUAFX_MSGMAP@@XZ'
handlers = [struct.unpack('<6I', original.data(entries + 24 * i, 24)) for i in range(18)]
expected = [(0x14, 0, 0, 0, 1, 0x6e8870), (0x5, 0, 0, 0, 0x19, 0x40e040), (0x1, 0, 0, 0, 0xd, 0x40e5b0),
            (0x111, 0, 0x80bb, 0x80bb, 0x39, 0x40e930), (0x111, 0xffffffff, 0x80bb, 0x80bb, 0x41, 0x40e940),
            (0x111, 0, 0x80bd, 0x80bd, 0x39, 0x40e790), (0x111, 0xffffffff, 0x80bd, 0x80bd, 0x41, 0x40e130),
            (0x111, 0, 0x80bc, 0x80bc, 0x39, 0x40e7d0), (0x111, 0xffffffff, 0x80bc, 0x80bc, 0x41, 0x42e550),
            (0x111, 0, 0x80ba, 0x80ba, 0x39, 0x40e920), (0x111, 0xffffffff, 0x80ba, 0x80ba, 0x41, 0x40e0d0),
            (0x111, 0, 0x80b9, 0x80b9, 0x39, 0x40e7e0), (0x111, 0xffffffff, 0x80b9, 0x80b9, 0x41, 0x40e0f0),
            (0x111, 0, 0x80ca, 0x80ca, 0x39, 0x40e7f0), (0x111, 0xffffffff, 0x80ca, 0x80ca, 0x41, 0x40e110),
            (0x4e, 0x64, 0x80c9, 0x80c9, 0x3d, 0x40eda0), (0x285e, 0, 0, 0, 0xd, 0x40e670), (0, 0, 0, 0, 0, 0)]
assert handlers == expected, handlers

open_items = {
    '0040fff0': 'OnGetExternal: 2-instruction scheduling difference (object pointer reloaded after the isIDE store; '
                'original converts to IBrowserViewExternal before the store without a null check). Rejected 2026-11-06: '
                'CBrowserViewExternal& / IBrowserViewExternal& ext = *object before the store (the reference conversion '
                'keeps a null test, 181 / 183 B); external = (IDispatch*)object->GetUnknown() after the store (no null '
                'test, object reloaded, 173 B) or before it (hoisted above the dynamic_cast, 173 B); dynamic_cast into a '
                'local first, then GetUnknown, then the store (169 B vs 171: only object / cast result swap eax / ecx)',
    '0040e470': 'CXTPControlComboBox::DeleteItem (XTP inline, emitted here): first 64 bytes exact; the target extent '
                '(81) runs into the next function 0040e4b0 (bounds evidence)',
}
(ROOT / 'work/2008-06/shared-layouts/browser-view-working.json').write_text(json.dumps({
    'class': 'CBrowserView', 'subclasses': ['CIDEBrowserView', 'CPlayBrowserView'],
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)', 'flags': FLAGS + XTP_FLAGS,
    'profile': 'CString operator PCXSTR and CSimpleStringT::IsEmpty noinline (original imports both)',
    'original_sha256': sha(original.path), 'object_sha256': sha(obj),
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in (Path(__file__), source, HEADERS / 'CBrowserView.h', HEADERS / 'CBrowserDoc.h',
                                         HEADERS / 'CBrowserViewExternal.h', HEADERS / 'CBrowserFrameWnd.h', HERE / 'NativeBrowserViewLayout.cpp')},
    'xtp_targets': {'%08x' % XTP_TARGETS[s]: '%s: %s' % (s, xtp_proof[s]) for s in XTP_TARGETS},
    'methods': rows, 'open': open_items}, indent=2) + '\n')
weak = [s for s, p in xtp_proof.items() if p != 'XTP recipe body exact']
print('PASS native CBrowserView: %d exact bodies, targets verified; XTP targets body-proven %d/%d%s'
      % (len(rows), len(XTP_TARGETS) - len(weak), len(XTP_TARGETS), (' (call-site only: %s)' % ', '.join(weak)) if weak else ''))
