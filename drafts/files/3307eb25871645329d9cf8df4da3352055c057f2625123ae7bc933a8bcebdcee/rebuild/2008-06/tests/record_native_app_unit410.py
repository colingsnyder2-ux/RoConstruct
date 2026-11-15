"""Record the 2008-06 application range 00410000..00414000 (inactive): unit map and the recovered RBX rows.

Step 1, unit map (row list from work/2008-06/functions.jsonl; every block anchor is re-checked against the original):
  * the CBrowserView / CBrowserViewExternal unit (from 0x40df60, mapped by app-unit40c-2008) ..0x41111f: CBrowserView
    members (browser-view receipt) interleaved with the ATL COM instances over CBrowserViewExternal (RTTI vtables
    0x80d388..0x80d7f0, REGISTRY resource 119 "BrowserViewExternal Class" {70EBD57E-...}) and the two interface
    methods get_IsIDE 0x410f90 / GetApp 0x410fe0 (IDispatchImpl vtable 0x80d714 slots 7 / 8);
  * the CChatPrompt unit 0x411120..0x412adf: boost weak_ptr / bad_weak_ptr inlines, ChatEnter (vtable 0x80e12c) with
    the GuiItem inline members, CBrush / CGdiObject MFC inlines, the Network::Players service templates, the
    vector<shared_ptr<Instance>> STL instances find<Players> needs, CChatPrompt (vtable 0x80e1ac, CRuntimeClass
    0x80df88 "CChatPrompt" size 0xa8, message map 0x80e354);
  * the CChildFrame / CRbxChildFrame unit 0x412ae0..0x412f2f (child-frame receipt);
  * the CClassImages unit 0x412f30..0x41345f (CClassImages ctor 0x413230 "Unable to create CClassImages", the MFC
    comctl32 isolation wrappers ImageList_Add / ImageList_AddMasked and CImageList / CBitmap inlines);
  * the clipboard verb unit from 0x413460 (continues past the range; app-unit414 maps its tail): the XmlElement /
    XmlNameValuePair inlines ClipboardActions.cpp emits, CutVerb / CopyVerb / PasteVerb (vtables 0x80e990 / 0x80e960 /
    0x80e934), the Name / service-index templates of Model, Script, LocalScript, ChangeHistoryService, Selection and
    the STL instances (map<string, string>, map<InstanceHandle, int>, vector<shared_ptr<Instance>>).
No library unit (Ogre, G3D, CRT, XTP, zlib, Lua, RakNet) is linked here; library template / inline instances inside
the RBX units are mapped and only verified, not counted, except ATL / STL templates whose only references are this
unit (asserted from the callers and the vtables).
Rows other receipts count (top-level exact_function_rows rule) are written as 'ADDR counted by RECEIPT' text; every
other address of a row not counted here is written 0x-prefixed.

Step 2, recovery (sources under native-classes, all inactive):
  * AppUnit410BrowserExternal.cpp (new): get_IsIDE / GetApp and explicit ATL instantiations over CBrowserViewExternal
    against the committed CBrowserViewExternal.h (read-only), profile mfc-noinline-pcxstr; the rows of the unit that
    lie below 0x410000 (app-unit40c-2008's range, counted by no receipt) are counted here too;
  * AppUnit410ChatPrompt.cpp (new): ~CChatPrompt, IMPLEMENT_DYNCREATE(CChatPrompt, CEditView) and the
    Network::Players Name / ServiceProvider templates (/fp:fast; find<Players> from a second build with
    native-headers/boost-noinline-shared-destructor first, as record_native_app_unit454_2008.py);
  * AppUnit410ClipboardNames.cpp (new): Name::declare<sModel / sScript / sLocalScript / sChangeHistoryService> and
    doGetClassIndex / callDoGetClassIndex<Selection>;
  * the committed CChatPrompt.cpp (CChatPrompt(), bind) and ClipboardActions.cpp (std-noinline-string; ~XmlElement,
    setSelection, Name::c_str, ~XmlNameValuePair, ~XmlAttribute) are compiled unchanged.
Pending build (NATIVE_APPUNIT410_PENDING, generated header copy under rebuild/2008-06/out/native-layouts/app-unit410/
pending): CBrowserViewExternal.h plus DECLARE_REGISTRY_RESOURCEID(119) and DECLARE_PROTECT_FINAL_CONSTRUCT(); rows
exact only there are recorded exact=false (pending-build-only) and are not counted. Vtables are checked from the
objects built from the current headers only.
A row counts only if its bytes match exactly and every REL32 / DIR32 target is bound and verified (imports by DLL
name / ordinal, literals by bytes, RTTI and vtables by RTTI names, GUIDs by their 16 bytes from the cited evidence,
class-name arrays by their string, own rows, the EXTERNAL map with cited receipts, evidence names, and bodies / data
this build emits that are byte-equal at the referenced address with their own targets verified recursively).
Writes work/2008-06/shared-layouts/app-unit410-working.json.
"""
import glob
import json
import os
import re
import struct
import sys
import uuid
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import native_bind as nb  # noqa: E402
from native_bind import ROOT, OUT, LOCAL_EH, Original, flags, match, rebuild, sha  # noqa: E402

HDR = ROOT / 'rebuild/2008-06/native-headers'
SRC = ROOT / 'rebuild/2008-06/native-classes'
EXT_CPP = SRC / 'AppUnit410BrowserExternal.cpp'
CHAT_CPP = SRC / 'AppUnit410ChatPrompt.cpp'
NAMES_CPP = SRC / 'AppUnit410ClipboardNames.cpp'
PROMPT_CPP = SRC / 'CChatPrompt.cpp'
CLIP_CPP = SRC / 'ClipboardActions.cpp'
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit410-working.json'
PENDING_DIR = OUT / 'app-unit410/pending'
LO, HI = 0x410000, 0x414000
UNIT_LO = 0x40df60            # CBrowserView / CBrowserViewExternal unit start (app-unit40c-2008 map)
CHAT_LO, FRAME_LO, IMAGES_LO, CLIP_LO = 0x411120, 0x412ae0, 0x412f30, 0x413460
H = lambda a: '0x%08x' % a
original = Original()


def d(address):
    return struct.unpack('<I', original.data(address, 4))[0]


FUNCS = {}
for line in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines():
    if line.strip():
        row = json.loads(line)
        FUNCS[int(row['addr'], 16)] = row
rows = sorted(a for a in FUNCS if LO <= a < HI)
EVIDENCE = json.loads((ROOT / 'rebuild/2008-06/offline/evidence.json').read_text())['names']
FLAGS = {}


def build(source, name, profile=(), extra=(), defines=()):
    OUT.mkdir(parents=True, exist_ok=True)
    obj = OUT / (name + '.obj')
    base = flags()
    i = next(k for k, x in enumerate(base) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    args = (base[:i] + ['/I' + str(p if isinstance(p, Path) else HDR / p) for p in profile] + base[i:] + list(extra)
            + ['/D' + x for x in defines] + ['/Fo' + str(obj), str(source)])
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', args, OUT)
    assert code == 0, log[-4000:]
    FLAGS[name] = args
    return obj


# Pending header copy: the committed CBrowserViewExternal.h plus the two ATL class macros the original unit proves
# (UpdateRegistry 0x410810 pushes resource 0x77 = REGISTRY 119; 0x40f9a0 / 0x40fbf0 bracket FinalConstruct with
# m_dwRef++ / m_dwRef--).
PENDING_DIR.mkdir(parents=True, exist_ok=True)
_hdr = (HDR / 'CBrowserViewExternal.h').read_text()
_anchor = '    BEGIN_COM_MAP(CBrowserViewExternal)'
assert _hdr.count(_anchor) == 1
(PENDING_DIR / 'CBrowserViewExternal.h').write_text(_hdr.replace(
    _anchor, '    DECLARE_REGISTRY_RESOURCEID(119)\n    DECLARE_PROTECT_FINAL_CONSTRUCT()\n\n' + _anchor))

OBJ = {
    'ext': build(EXT_CPP, 'NativeAppUnit410BrowserExternal', ['mfc-noinline-pcxstr']),
    'chat': build(CHAT_CPP, 'NativeAppUnit410ChatPrompt', extra=['/fp:fast']),
    'chat_find': build(CHAT_CPP, 'NativeAppUnit410ChatPromptFind', ['boost-noinline-shared-destructor'],
                       extra=['/fp:fast']),
    'names': build(NAMES_CPP, 'NativeAppUnit410ClipboardNames'),
    'prompt': build(PROMPT_CPP, 'NativeAppUnit410CChatPrompt'),
    'clip': build(CLIP_CPP, 'NativeAppUnit410ClipboardActions', ['std-noinline-string']),
}
# The noinline-destructor build of find<Players> calls helper bodies the plain build emits as in the original.
ALT = {OBJ['chat_find']: [OBJ['chat']]}
PENDING_OBJ = build(EXT_CPP, 'NativeAppUnit410BrowserExternalPending', [PENDING_DIR, 'mfc-noinline-pcxstr'],
                    defines=['NATIVE_APPUNIT410_PENDING'])

# ---- GUIDs (16 bytes each, with the evidence that names them) --------------------------------------------------------
GUID_TEXT = {
    '_IID_IBrowserViewExternal': ('e2ece10d-9997-414b-b40b-0928b8f3cadb', 'CBrowserViewExternal.h uuid / TYPELIB'),
    '_CLSID_BrowserViewExternal': ('70ebd57e-fd0d-4032-b090-9244aa7ded6e', 'REGISTRY resource 119 BrowserViewExternal'),
    '_LIBID_RobloxLib': ('03e1c8ed-c1c6-47bf-b9b9-a37b677318dd', 'REGISTRY TypeLib value / WorkspaceGuids.cpp'),
    '_CLSID_App': ('eec6b245-01be-4a51-92ba-2afdaf97581b', 'REGISTRY resource 110 "App Class"'),
    '_IID_IApp': ('54f58168-734e-4379-b198-64b0826a002e', 'TYPELIB interface after the App coclass'),
    '_IID_IUnknown': ('00000000-0000-0000-c000-000000000046', 'Windows SDK uuid.lib'),
    '_IID_IDispatch': ('00020400-0000-0000-c000-000000000046', 'Windows SDK uuid.lib'),
    '_IID_ISupportErrorInfo': ('df0b3d60-548f-101b-8e65-08002b2bd119', 'Windows SDK uuid.lib'),
    '_IID_IConnectionPointContainer': ('b196b284-bab4-101a-b69c-00aa00341d07', 'Windows SDK uuid.lib'),
    '_IID_IConnectionPoint': ('b196b286-bab4-101a-b69c-00aa00341d07', 'Windows SDK uuid.lib'),
    '_IID_IEnumConnectionPoints': ('b196b285-bab4-101a-b69c-00aa00341d07', 'Windows SDK uuid.lib'),
    '_IID_IEnumConnections': ('b196b287-bab4-101a-b69c-00aa00341d07', 'Windows SDK uuid.lib'),
    '_GUID_NULL': ('00000000-0000-0000-0000-000000000000', 'Windows SDK'),
}


def guid_of(symbol):
    if symbol in GUID_TEXT:
        return GUID_TEXT[symbol]
    m = re.match(r'^\?_GUID_([0-9a-f]{8})_([0-9a-f]{4})_([0-9a-f]{4})_([0-9a-f]{4})_([0-9a-f]{12})@@3U__s_GUID@@B$', symbol)
    if m:
        return '-'.join(m.groups()), '__uuidof (the GUID is the symbol name)'
    return None


NAME_DATA = {'?sPlayers@Network@RBX@@3PADA': 'Players', '?sModel@RBX@@3PADA': 'Model',
             '?sScript@RBX@@3PADA': 'Script', '?sLocalScript@RBX@@3PADA': 'LocalScript',
             '?sChangeHistoryService@RBX@@3PADA': 'ChangeHistoryService'}

# ---- rows counted here ------------------------------------------------------------------------------------------------
BVE = 'VCBrowserViewExternal@@'
CPI = ('?$IConnectionPointImpl@VCBrowserViewExternal@@$1?_GUID_dd754d30_321a_45a2_a40c_75783afabfab@@3U__s_GUID@@B'
       'VCComDynamicUnkArray@ATL@@@ATL@@')
ENUM_CP = ('?$CComEnum@UIEnumConnectionPoints@@$1?_GUID_b196b285_bab4_101a_b69c_00aa00341d07@@3U__s_GUID@@BPAUIConnect'
           'ionPoint@@V?$_CopyInterface@UIConnectionPoint@@@ATL@@VCComSingleThreadModel@6@@ATL@@')
ENUM_C = ('?$CComEnum@UIEnumConnections@@$1?_GUID_b196b287_bab4_101a_b69c_00aa00341d07@@3U__s_GUID@@BUtagCONNECTDATA@@'
          'V?$_Copy@UtagCONNECTDATA@@@ATL@@VCComSingleThreadModel@6@@ATL@@')
IMPL_CP = ('?$CComEnumImpl@UIEnumConnectionPoints@@$1?_GUID_b196b285_bab4_101a_b69c_00aa00341d07@@3U__s_GUID@@BPAUICon'
           'nectionPoint@@V?$_CopyInterface@UIConnectionPoint@@@ATL@@@ATL@@')
IMPL_C = ('?$CComEnumImpl@UIEnumConnections@@$1?_GUID_b196b287_bab4_101a_b69c_00aa00341d07@@3U__s_GUID@@BUtagCONNECTDA'
          'TA@@V?$_Copy@UtagCONNECTDATA@@@ATL@@@ATL@@')
CREATOR_AGG = '?CreateInstance@?$CComCreator@V?$CComAggObject@' + BVE + '@ATL@@@ATL@@SGJPAXABU_GUID@@PAPAX@Z'
ENUM_CONN = '?EnumConnections@' + CPI + 'UAGJPAPAUIEnumConnections@@@Z'
INIT_C = '?Init@' + IMPL_C + 'QAEJPAUtagCONNECTDATA@@0PAUIUnknown@@W4CComEnumFlags@2@@Z'
INIT_CP = '?Init@' + IMPL_CP + 'QAEJPAPAUIConnectionPoint@@0PAUIUnknown@@W4CComEnumFlags@2@@Z'
CI_CP = '?CreateInstance@?$CComObject@V' + ENUM_CP + '@ATL@@SGJPAPAV12@@Z'
CI_C = '?CreateInstance@?$CComObject@V' + ENUM_C + '@ATL@@SGJPAPAV12@@Z'
EXT_ROWS = [
    (0x0040e990, '??1' + CPI + 'QAE@XZ'),
    (0x0040ec90, '??1' + IMPL_C + 'UAE@XZ'),
    (0x0040f440, '??1' + IMPL_CP + 'UAE@XZ'),
    ((0x0040ef00, 0, 0x67), INIT_C),
    ((0x0040ef67, 0x67, 0x14e), INIT_C),
    ((0x0040f570, 0, 0x67), INIT_CP),
    ((0x0040f5d7, 0x67, 0x146), INIT_CP),
    (0x0040f280, '??0?$CComObject@' + BVE + '@ATL@@QAE@PAX@Z'),
    (0x0040fa60, '??0?$CComAggObject@' + BVE + '@ATL@@QAE@PAX@Z'),
    (0x0040fb70, '??1?$CComAggObject@' + BVE + '@ATL@@UAE@XZ'),
    ((0x0040fe50, 0, 0x93), CI_CP),
    ((0x0040fee3, 0x93, 0xc1), CI_CP),
    ((0x0040ff20, 0, 0x93), CI_C),
    ((0x0040ffb3, 0x93, 0xc1), CI_C),
    ((0x004103e0, 0, 0x9b), CREATOR_AGG),
    ((0x0041047b, 0x9b, 0xc1), CREATOR_AGG),
    ((0x004104b0, 0, 0x16b), ENUM_CONN),
    ((0x0041061b, 0x16b, 0x179), ENUM_CONN),
    ((0x00410629, 0x179, 0x19c), ENUM_CONN),
    ((0x0041064c, 0x19c, 0x1b4), ENUM_CONN),
]
CHAT_ROWS = [
    (0x004129c0, '??1CChatPrompt@@UAE@XZ'),
    (0x00412aa0, '??_GCChatPrompt@@UAEPAXI@Z'),
    (0x00411ef0, '?CreateObject@CChatPrompt@@SGPAVCObject@@XZ'),
    (0x00411350, '?_GetBaseClass@CChatPrompt@@KGPAUCRuntimeClass@@XZ'),
    (0x00411360, '?GetThisClass@CChatPrompt@@SGPAUCRuntimeClass@@XZ'),
    (0x00411420, '??$doDeclare@$1?sPlayers@Network@RBX@@3PADA@Name@RBX@@CAABV01@XZ'),
    (0x00411890, '??$callDoDeclare@$1?sPlayers@Network@RBX@@3PADA@Name@RBX@@CAXXZ'),
    (0x00411490, '??$doGetClassIndex@VPlayers@Network@RBX@@@ServiceProvider@RBX@@SAIXZ'),
    (0x00411930, '??$callDoGetClassIndex@VPlayers@Network@RBX@@@ServiceProvider@RBX@@SAXXZ'),
    (0x00412710, '??$create@VPlayers@Network@RBX@@@ServiceProvider@RBX@@QBEPAVPlayers@Network@1@XZ'),
]
CHAT_FIND_ROWS = [
    (0x004125d0, '??$find@VPlayers@Network@RBX@@@ServiceProvider@RBX@@QBEPAVPlayers@Network@1@XZ'),
]
PROMPT_ROWS = [
    (0x00411be0, '??0CChatPrompt@@QAE@XZ'),
    (0x00412800, '?bind@CChatPrompt@@QAEXPAVDataModel@RBX@@PAVCWnd@@@Z'),
]
NAMES_ROWS = []
for _addr, _jmp, _n in [(0x00413650, 0x00413a20, '?sModel@RBX@@3PADA'), (0x004136c0, 0x00413a30, '?sScript@RBX@@3PADA'),
                        (0x00413730, 0x00413a40, '?sLocalScript@RBX@@3PADA'),
                        (0x004137a0, 0x00413a50, '?sChangeHistoryService@RBX@@3PADA')]:
    NAMES_ROWS += [(_addr, '??$doDeclare@$1' + _n + '@Name@RBX@@CAABV01@XZ'),
                   (_jmp, '??$callDoDeclare@$1' + _n + '@Name@RBX@@CAXXZ')]
NAMES_ROWS += [(0x00413810, '??$doGetClassIndex@VSelection@RBX@@@ServiceProvider@RBX@@SAIXZ'),
               (0x00413a60, '??$callDoGetClassIndex@VSelection@RBX@@@ServiceProvider@RBX@@SAXXZ')]
SEL_IT = 'V?$_Vector_iterator@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@'
CLIP_ROWS = [
    (0x00413460, '?c_str@Name@RBX@@QBEPBDXZ'),
    (0x00413470, '??1XmlNameValuePair@@QAE@XZ'),
    (0x00413480, '??1XmlAttribute@@QAE@XZ'),
    (0x00413a70, '??1XmlElement@@QAE@XZ'),
    (0x00413b00, '??$setSelection@' + SEL_IT + '@Selection@RBX@@QAEXV?$_Vector_iterator@V?$shared_ptr@VInstance@RBX@@@b'
                 'oost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@0@Z'),
]
PENDING_ROWS = [
    ((0x0040f9a0, 0, 0x99), '?CreateInstance@?$CComCreator@V?$CComObject@' + BVE + '@ATL@@@ATL@@SGJPAXABU_GUID@@PAPAX@Z'),
    ((0x0040fa39, 0x99, 0xbf), '?CreateInstance@?$CComCreator@V?$CComObject@' + BVE + '@ATL@@@ATL@@SGJPAXABU_GUID@@PAPAX@Z'),
    (0x0040fbf0, '?createBrowserViewExternal@@YAJPAPAV?$CComObjectNoLock@' + BVE + '@ATL@@H@Z'),
    # CComCreator2 dispatcher: bytes exact in both builds, but its first target 0x40f9a0 is exact only in the pending
    # build, so the row is pending too.
    (0x00410890, '?CreateInstance@?$CComCreator2@V?$CComCreator@V?$CComObject@' + BVE + '@ATL@@@ATL@@V?$CComCreator@V'
                 '?$CComAggObject@' + BVE + '@ATL@@@2@@ATL@@SGJPAXABU_GUID@@PAPAX@Z'),
]
BUILDS = [('ext', EXT_ROWS), ('chat', CHAT_ROWS), ('chat_find', CHAT_FIND_ROWS), ('prompt', PROMPT_ROWS),
          ('names', NAMES_ROWS), ('clip', CLIP_ROWS)]

# Vtables of the unit: compiled vtable symbol -> (original vtable, RTTI complete-object name, subobject offset).
NL = '??_7?$CComObjectNoLock@' + BVE + '@ATL@@6B'
CO = '??_7?$CComObject@' + BVE + '@ATL@@6B'
CC = '??_7?$CComContainedObject@' + BVE + '@ATL@@6B'
SEI = '?$ISupportErrorInfoImpl@$1?IID_IBrowserViewExternal@@3U_GUID@@B@1@@'
CPC = '?$IConnectionPointContainerImpl@VCBrowserViewExternal@@@1@@'
PRX = '?$CProxy_IBrowserViewExternalEvents@VCBrowserViewExternal@@@@@'
DSP = ('?$IDispatchImpl@UIBrowserViewExternal@@$1?IID_IBrowserViewExternal@@3U_GUID@@B$1?LIBID_RobloxLib@@3U3@B$00$0A@'
       'VCComTypeInfoHolder@ATL@@@1@@')
R_NL, R_CO, R_CC = ('.?AV?$CComObjectNoLock@VCBrowserViewExternal@@@ATL@@', '.?AV?$CComObject@VCBrowserViewExternal@@@ATL@@',
                    '.?AV?$CComContainedObject@VCBrowserViewExternal@@@ATL@@')
EXT_VTABLES = {
    NL + SEI: (0x80d778, R_NL, 0), NL + CPC: (0x80d760, R_NL, 4), NL + PRX: (0x80d73c, R_NL, 8), NL + DSP: (0x80d714, R_NL, 0x14),
    CO + SEI: (0x80d638, R_CO, 0), CO + CPC: (0x80d620, R_CO, 4), CO + PRX: (0x80d5fc, R_CO, 8), CO + DSP: (0x80d5d4, R_CO, 0x14),
    CC + SEI: (0x80d700, R_CC, 0), CC + CPC: (0x80d6e8, R_CC, 4), CC + PRX: (0x80d6c4, R_CC, 8), CC + DSP: (0x80d69c, R_CC, 0x14),
    '??_7?$CComAggObject@' + BVE + '@ATL@@6B@': (0x80d7dc, '.?AV?$CComAggObject@VCBrowserViewExternal@@@ATL@@', 0),
    '??_7?$CProxy_IBrowserViewExternalEvents@VCBrowserViewExternal@@@@6B@':
        (0x80d388, '.?AV?$CProxy_IBrowserViewExternalEvents@VCBrowserViewExternal@@@@', 0),
    '??_7?$CComObject@V' + ENUM_CP + '@ATL@@6B@': (0x80d790, '.?AV?$CComObject@V' + ENUM_CP + '@ATL@@', 0),
    '??_7?$CComObject@V' + ENUM_C + '@ATL@@6B@': (0x80d7f0, '.?AV?$CComObject@V' + ENUM_C + '@ATL@@', 0),
}
CHAT_VTABLE = ('??_7CChatPrompt@@6B@', 0x80e1ac, '.?AVCChatPrompt@@', 0)


def first(spec):
    return spec[0] if isinstance(spec, tuple) else spec


EXTERNAL = {
    '??2@YAPAXI@Z': (0x006a0920, 'operator new (record_native_guid_critical_section.py binding)'),
    '??3@YAXPAX@Z': (0x006a067a, 'operator delete (record_native_guid_critical_section.py binding)'),
    '__CxxThrowException@8': (0x006a158c, 'CRT throw (record_native_app_unit428.py binding)'),
    '__alloca_probe': (0x006a1520, 'CRT (record_native_rakpeer_raw_rpc_integrated.py binding)'),
    '__alloca_probe_16': (0x006a1560, 'CRT (record_native_app_unit49c_2008.py binding)'),
    '?_pAtlModule@ATL@@3PAVCAtlModule@1@A': (0x0096c268, 'content-factory-trial / app-unit414 binding'),
    '?m_libid@CAtlModule@ATL@@2U_GUID@@A': (0x0096c26c, '_pAtlModule + 4 (atlbase.h selectany pair; app-unit414 binding)'),
    '?_AtlBaseModule@ATL@@3VCAtlBaseModule@1@A': (0x0097f2a8, 'record_native_app_leaves2008.py binding'),
    '?_AtlWinModule@ATL@@3VCAtlWinModule@1@A': (0x0097f314, 'record_native_app_leaves2008.py binding'),
    '?m_bInitFailed@CAtlBaseModule@ATL@@2_NA': (0x0096dcf8, 'record_native_app_leaves2008.py binding'),
    '?Delete@CException@@QAEXXZ': (0x006a0950, 'content-factory-trial CreateInstance catch binding'),
    '?reportWorkspaceSiteError@@YAJABU_GUID@@PBDJ@Z':
        (0x00429330, 'workspace-save-trial / workspace-site-trust-working binding (helper 0x429330)'),
    # ServiceProvider / Name helpers (record_native_app_unit454_2008.py / record_native_app_unit48c_2008.py bindings)
    '?newIndex@ServiceProvider@RBX@@SAIXZ': (0x00572690, 'ServiceProvider::newIndex (app-unit454-2008 binding)'),
    '?findServiceByClassName@ServiceProvider@RBX@@QBE?AV?$shared_ptr@VInstance@RBX@@@boost@@ABVName@2@@Z':
        (0x00572a90, 'app-unit454-2008 / app-unit48c-2008 binding'),
    '?call_once@boost@@YAXP6AXXZAAJ@Z': (0x00557330, 'boost::call_once (app-unit454-2008 binding)'),
    '?declare@Name@RBX@@SAABV12@PBDH@Z': (0x00553f90, 'Name::declare(const char*, int) (app-unit400-2008 binding)'),
    '??4shared_count@detail@boost@@QAEAAV012@ABV012@@Z': (0x004025b0, 'shared_count::operator= (app-unit454-2008 binding)'),
    '?setParent@Instance@RBX@@QAEXPAV12@@Z': (0x0055a8f0, 'Instance::setParent (app-unit454-2008 binding)'),
    '??1?$shared_ptr@VInstance@RBX@@@boost@@QAE@XZ': (0x00600660, 'out-of-line ~shared_ptr<Instance> (app-unit454-2008 '
                                                     'noinline-destructor binding)'),
    '??1CGdiObject@@UAE@XZ': (0x004111a0, 'MFC inline ~CGdiObject; exact dependency body of record_native_class_tree_view.py '
                                          '(also bound by insert-object-dialog / script-editor receipts)'),
    # CChatPrompt::bind callees (record_native_chat_prompt.py verified_direct_calls)
    '??$shared_from@VDataModel@RBX@@@RBX@@YA?AV?$shared_ptr@VDataModel@RBX@@@boost@@PAVDataModel@0@@Z':
        (0x00618a40, 'record_native_chat_prompt.py direct-call binding'),
    '??0Lock@DataModel@RBX@@QAE@V?$shared_ptr@$$CBVDataModel@RBX@@@boost@@@Z':
        (0x00411b40, 'DataModel::Lock ctor (evidence name; record_native_chat_prompt.py binding)'),
    '??1Lock@DataModel@RBX@@QAE@XZ': (0x005773c0, 'record_native_chat_prompt.py direct-call binding'),
    '?reset@?$shared_ptr@VChatEnter@@@boost@@QAEXXZ': (0x00456e80, 'record_native_chat_prompt.py direct-call binding'),
    '??$create@VChatEnter@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VChatEnter@@@boost@@XZ':
        (0x00411f50, 'row counted by app-unit40c-2008'),
    '??$create@VPlayers@Network@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VPlayers@Network@RBX@@@boost@@XZ':
        (0x00411fd0, 'row counted by app-unit40c-2008'),
}
# ATL library helpers (CComTypeInfoHolder, AtlModuleAddTermFunc, ...) that app-unit414-working.json proves as
# byte-equal instances with every target verified (plain document-swap build); the mfc-noinline-pcxstr build here
# lays some of them out differently, so they are bound from that receipt instead of being re-proven.
_r414 = json.loads((ROOT / 'work/2008-06/shared-layouts/app-unit414-working.json').read_text())
for _sym, _v in _r414.get('instances', {}).items():
    if 'ATL@@' in _sym and 'CContent' not in _sym and str(_v.get('status', '')).startswith('instance') and _sym not in EXTERNAL:
        EXTERNAL[_sym] = (int(_v['address'], 16), 'ATL library instance verified in app-unit414-working.json')
own = {}
for _, specs in BUILDS:
    for spec, sym in specs:
        own.setdefault(sym, first(spec))
binding = {}
LOCAL_STATICS = {}
COLLECT = set()
DATA_LO, DATA_HI = 0x928000, 0x97f710   # writable .data (incl. uninitialized tail) of the 2008-06 image
CURRENT = []
INSTANCES = {}
BODIES = {}


def classify(symbol, value, raw, sections, definitions, where):
    hit = original.imported(value)
    if hit is not None:
        assert hit[1] == nb.plain(symbol), (where, symbol, hex(value), hit)
        return '%s!%s' % hit
    if symbol.startswith('??_C@'):
        pos, at = definitions[symbol]
        literal = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
        assert original.data(value, len(literal)) == literal, (where, symbol, hex(value))
        return 'literal %r' % literal[:-1].decode()
    if symbol.startswith('??_R0') and symbol.endswith('@8'):
        rtti = original.string(value + 8)
        assert rtti == '.' + symbol[5:-2], (where, symbol, hex(value), rtti)
        return 'RTTI %s' % rtti
    if symbol.startswith('??_7'):
        rtti, at = original.vtable_class(value)
        assert rtti == '.?AV' + symbol[4:symbol.index('@@6B') + 2], (where, symbol, hex(value), rtti)
        return 'vtable RTTI %s offset %#x' % (rtti, at)
    g = guid_of(symbol)
    if g is not None:
        assert original.data(value, 16) == uuid.UUID(g[0]).bytes_le, (where, symbol, hex(value))
        return 'GUID {%s} (%s)' % g
    if symbol in NAME_DATA:
        text = NAME_DATA[symbol].encode() + b'\0'
        assert original.data(value, len(text)) == text, (where, symbol, hex(value))
        return 'class-name array %r (string at the pushed address)' % NAME_DATA[symbol]
    if symbol in own:
        assert own[symbol] == value, (where, symbol, hex(value), hex(own[symbol]))
        return 'own row'
    if ('?1??' in symbol or symbol.startswith('??_B?1??')) and DATA_LO <= value < DATA_HI:
        LOCAL_STATICS.setdefault(symbol, set()).add(where)
        return 'own static (bound by consistency)'
    if symbol in EXTERNAL:
        assert EXTERNAL[symbol][0] == value, (where, symbol, hex(value), hex(EXTERNAL[symbol][0]))
        return 'external (%s)' % EXTERNAL[symbol][1]
    if EVIDENCE.get('%08x' % value, {}).get('symbol') == symbol:
        return 'evidence name'
    return instance(symbol, value, where)


def bodies_of(obj):
    if obj not in BODIES:
        BODIES[obj] = {n: (b, r) for n, b, r in match.coff_functions(Path(obj).read_bytes())}
    return BODIES[obj]


def instance(symbol, value, where):
    """An inline body this build emits, proven by bytes at the referenced address and by its own targets."""
    if symbol in INSTANCES:
        assert INSTANCES[symbol]['address'].replace('0x', '') == '%08x' % value, (where, symbol, hex(value))
        return 'instance (bytes equal, targets verified)'
    obj = CURRENT[-1]
    if symbol not in bodies_of(obj):
        return data_instance(symbol, value, where)
    for alt in [obj] + ALT.get(obj, []):
        if symbol in bodies_of(alt) and alt_exact(alt, symbol, value):
            obj = alt
            break
    body = bodies_of(obj)[symbol][0]
    try:
        target, _, _ = match.target('2008-06', '%08x' % value)
        unlisted = False
    except SystemExit:
        target, unlisted = b'', True
    merged = len(body) != len(target)
    spec = (value, 0, len(body), 'raw') if merged else value
    INSTANCES[symbol] = {'address': '%08x' % value, 'pending': True}
    row = verify(obj, [(spec, symbol)], False)[0]
    row['status'] = 'instance (emitted by this build; every own target verified), bytes equal, not counted'
    if unlisted:
        row['status'] += '; not a listed function start, whole body compared with the image bytes'
    elif merged:
        row['status'] += '; listed extent %#x != body %#x, whole body compared with the image bytes' % (
            len(target), len(body))
    INSTANCES[symbol] = row
    return 'instance (bytes equal, targets verified)'


def alt_exact(obj, symbol, value):
    body, refs = bodies_of(obj)[symbol]
    try:
        target, target_refs, _ = match.target('2008-06', '%08x' % value)
    except SystemExit:
        return False
    if len(target) != len(body):
        target, target_refs = original.data(value, len(body)), []
    return match.exact_match(target, target_refs, body, refs)


def data_instance(symbol, value, where):
    obj = CURRENT[-1]
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, starts = match._coff_data_index(raw)
    if symbol not in definitions:
        return None
    pos, sec = definitions[symbol]
    table = sections[sec]
    if table[9] & 0x20 or not table[9] & 0x40 or not table[4]:
        return None
    end = min([x for x in starts[sec + 1] if x > pos] + [table[3]])
    data = raw[table[4] + pos:table[4] + end]
    mine = original.data(value, len(data))
    fields = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if pos <= offset < end:
            assert kind == 6, (symbol, kind)
            fields[offset - pos] = symbols[index][0]
    mask = set(x + k for x in fields for k in range(4))
    assert all(a == b for i, (a, b) in enumerate(zip(data, mine)) if i not in mask), ('data bytes', symbol, hex(value))
    INSTANCES[symbol] = {'address': '%08x' % value, 'pending': True}
    verified = {}
    for off, target_symbol in sorted(fields.items()):
        target = (struct.unpack_from('<I', mine, off)[0] - struct.unpack_from('<i', data, off)[0]) & 0xffffffff
        how = classify(target_symbol, target, raw, sections, definitions, symbol)
        assert how is not None, ('unbound data field', symbol, off, target_symbol, hex(target))
        prev = binding.setdefault(target_symbol, target)
        assert prev == target, ('inconsistent binding', target_symbol, hex(prev), hex(target))
        verified['+%#x %s' % (off, target_symbol)] = '%s (%s)' % (hex(target), how)
    INSTANCES[symbol] = {'address': '%08x' % value, 'symbol': symbol, 'size': len(data), 'exact': False,
                         'status': 'data instance emitted by this build (bytes equal, fields verified), not counted',
                         'verified_targets': verified}
    return 'data instance (bytes equal, fields verified)'


def verify(obj, specs, exact_flag):
    CURRENT.append(obj)
    try:
        return verify_rows(obj, specs, exact_flag)
    finally:
        CURRENT.pop()


def verify_rows(obj, specs, exact_flag):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = bodies_of(obj)
    out = []
    for spec, name in specs:
        assert name in bodies, ('not emitted', name, Path(obj).name)
        body, refs = bodies[name]
        address, lo, hi = spec[:3] if isinstance(spec, tuple) else (spec, 0, len(body))
        body, refs = body[lo:hi], [r - lo for r in refs if lo <= r < hi]
        if isinstance(spec, tuple) and spec[3:] == ('raw',):
            target, target_refs = original.data(address, len(body)), []
        else:
            target, target_refs, _ = match.target('2008-06', '%08x' % address)
        assert len(target) == len(body) and match.exact_match(target, target_refs, body, refs), (
            name, hex(address), len(body), len(target))
        start, section = definitions[name]
        start += lo
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
            if LOCAL_EH.match(symbol) or symbol.startswith('__sehtable$'):
                local.add(symbol)
                continue
            how = classify(symbol, value, raw, sections, definitions, name)
            if how is None and os.environ.get('U410_COLLECT'):
                COLLECT.add((symbol, hex(value)))
                how = 'UNBOUND'
            assert how is not None, ('unbound relocation', name, symbol, hex(value))
            prev = binding.setdefault(symbol, value)
            assert prev == value, ('inconsistent binding', symbol, hex(prev), hex(value))
            verified[symbol] = '%s (%s)' % (hex(value), how)
        piece = '' if (lo, hi) == (0, len(bodies[name][0])) else ' [%#x:%#x]' % (lo, hi)
        out.append({'address': '%08x' % address, 'symbol': name + piece, 'size': len(body), 'exact': exact_flag,
                    'verified_targets': verified, 'local_eh': sorted(local)})
    return out


def vtable_slots(obj, symbol):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, starts = match._coff_data_index(raw)
    value, sec = definitions[symbol]
    table = sections[sec]
    end = min([x for x in starts[sec + 1] if x > value] + [table[3]])
    slots = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if value <= offset < end:
            slots[(offset - value) // 4] = symbols[index][0]
    return raw, sections, definitions, slots


# ---- counting rules: what other receipts count ------------------------------------------------------------------------
def addr_of(x):
    if isinstance(x, dict):
        x = x.get('address') or x.get('addr') or ''
    s = str(x).lower()
    s = s[2:] if s.startswith('0x') else s
    try:
        return int(s[:8], 16) if len(s) >= 6 and all(c in '0123456789abcdef' for c in s[:6]) else None
    except ValueError:
        return None


def walk_exact(o, out):
    if isinstance(o, list):
        for e in o:
            walk_exact(e, out)
    elif isinstance(o, dict):
        if 'address' in o and o.get('exact') is True:
            out.append(o['address'])
        for k, v in o.items():
            if isinstance(v, (dict, list)):
                walk_exact(v, out)


counted_elsewhere = {}
for f in sorted(glob.glob(str(ROOT / 'work/2008-06/shared-layouts/*.json'))):
    if Path(f).resolve() == RECEIPT.resolve():
        continue
    try:
        doc = json.loads(Path(f).read_text())
    except Exception:
        continue
    if not isinstance(doc, dict):
        continue
    if 'exact_function_rows' in doc:
        got = doc['exact_function_rows']
    elif isinstance(doc.get('exact_addresses'), list):
        got = doc['exact_addresses']
    elif isinstance(doc.get('exact_unique_addresses'), list):
        got = doc['exact_unique_addresses']
    else:
        got = []
        walk_exact(doc, got)
    if isinstance(got, dict):
        got = list(got)
    for x in got:
        v = addr_of(x)
        if v is not None and UNIT_LO <= v < HI:
            counted_elsewhere.setdefault(v, set()).add(os.path.basename(f)[:-5])

# ---- explicit rows --------------------------------------------------------------------------------------------------
results = []
for key, specs in BUILDS:
    got = verify(OBJ[key], specs, True)
    for r in got:
        r['build'] = key
    results += got

# ---- vtables of the CBrowserViewExternal unit: every slot verified; in-unit rows counted by slot --------------------
UNIT_ROWS = {a for a in FUNCS if UNIT_LO <= a < CHAT_LO}
vtables, aliases = {}, {}
slot_rows = []
for symbol, (vt, rtti_name, offset) in EXT_VTABLES.items():
    assert original.vtable_class(vt) == (rtti_name, offset), (hex(vt), original.vtable_class(vt))
    raw, sections, definitions, slots = vtable_slots(OBJ['ext'], symbol)
    assert sorted(slots) == list(range(len(slots))), (symbol, sorted(slots))
    checked = {}
    CURRENT.append(OBJ['ext'])
    for slot, sym in sorted(slots.items()):
        value = d(vt + 4 * slot)
        name = sym
        if sym.startswith('??_E') and ('??_G' + sym[4:]) in bodies_of(OBJ['ext']):
            name = '??_G' + sym[4:]
        if value in UNIT_ROWS and value not in counted_elsewhere and name in bodies_of(OBJ['ext']) and (
                name not in own or own[name] == value):
            prior = next((r for r in results + slot_rows if int(r['address'], 16) == value), None)
            if prior is None:
                own.setdefault(name, value)
                got = verify(OBJ['ext'], [(value, name)], True)[0]
                got['build'] = 'ext'
                got['vtable_slot'] = '%s slot %d' % (hex(vt), slot)
                slot_rows.append(got)
            elif prior['symbol'].split(' [')[0] != name:
                aliases.setdefault('%08x' % value, set()).add(name)
        how = classify(name, value, raw, sections, definitions, symbol)
        assert how is not None, ('unbound vtable slot', symbol, slot, sym, hex(value))
        prev = binding.setdefault(name, value)
        assert prev == value, ('inconsistent', name, hex(prev), hex(value))
        checked[slot] = '%s = %s (%s)' % (sym, hex(value), how)
    CURRENT.pop()
    vtables[symbol] = {'address': hex(vt), 'rtti': rtti_name, 'offset': offset, 'slots': checked}
results += slot_rows

# CChatPrompt vtable 0x80e1ac (object from the current headers): slots compared, mismatches recorded.
chat_vtable = {}
_sym, _vt, _rtti, _off = CHAT_VTABLE
assert original.vtable_class(_vt) == (_rtti, _off)
_raw, _sections, _definitions, _slots = vtable_slots(OBJ['chat'], _sym)
CURRENT.append(OBJ['chat'])
for slot, sym in sorted(_slots.items()):
    value = d(_vt + 4 * slot)
    name = '??_G' + sym[4:] if sym.startswith('??_E') else sym
    try:
        how = classify(name, value, _raw, _sections, _definitions, _sym)
    except AssertionError as e:
        how = None
        chat_vtable[slot] = 'MISMATCH %s = %s (%s)' % (sym, hex(value), str(e)[:160])
        continue
    chat_vtable[slot] = ('%s = %s (%s)' % (sym, hex(value), how)) if how else 'UNBOUND %s = %s' % (sym, hex(value))
CURRENT.pop()

# ---- pending-build-only rows (never counted; vtables never taken from this object) -----------------------------------
pending = []
CURRENT.append(PENDING_OBJ)
for spec, name in PENDING_ROWS:
    body, refs = bodies_of(PENDING_OBJ)[name]
    a, lo, hi = spec if isinstance(spec, tuple) else (spec, 0, len(body))
    t, tr, _ = match.target('2008-06', '%08x' % a)
    ok = len(t) == hi - lo and match.exact_match(t, tr, body[lo:hi], [r - lo for r in refs if lo <= r < hi])
    try:
        cur_ok = name in bodies_of(OBJ['ext']) and match.exact_match(
            t, tr, bodies_of(OBJ['ext'])[name][0][lo:hi], [r - lo for r in bodies_of(OBJ['ext'])[name][1] if lo <= r < hi])
    except Exception:
        cur_ok = False
    pending.append({'address': '0x%08x' % a, 'symbol': name + ('' if (lo, hi) == (0, len(body)) else ' [%#x:%#x]' % (lo, hi)),
                    'exact': False, 'pending_exact': bool(ok), 'current_build_exact': bool(cur_ok),
                    'status': 'pending-build-only (NATIVE_APPUNIT410_PENDING + generated CBrowserViewExternal.h copy); '
                              'not counted'})
CURRENT.pop()
assert all(p['pending_exact'] for p in pending), pending

# ---- structural checks -----------------------------------------------------------------------------------------------
exact = sorted({r['address'] for r in results})
exact_ints = {int(a, 16) for a in exact}
double = sorted(exact_ints & set(counted_elsewhere))
assert not double, ('counted elsewhere too', [H(a) for a in double])
for r in results:
    a = int(r['address'], 16)
    assert a in FUNCS and r['size'] == FUNCS[a]['size'], (r['address'], r['size'])
# Library-template rows (ATL CComEnum / CComEnumImpl / IConnectionPointImpl over ATL types) are counted only when
# every caller listed for them lies inside the unit (their vtables are the unit's own, checked above).
for r in results:
    a = int(r['address'], 16)
    for c in FUNCS[a].get('callers', []):
        c = int(c, 16)
        if a < CHAT_LO:
            assert UNIT_LO <= c < CHAT_LO, ('external caller of a unit row', r['address'], hex(c))
assert original.vtable_class(0x80e1ac)[0] == '.?AVCChatPrompt@@'
assert original.vtable_class(0x80e12c)[0] == '.?AVChatEnter@@'
assert original.vtable_class(0x80e990)[0] == '.?AVCutVerb@@' and original.vtable_class(0x80e960)[0] == '.?AVCopyVerb@@'
assert original.vtable_class(0x80e934)[0] == '.?AVPasteVerb@@'
assert d(0x80df88) == 0x80df2c and original.data(0x80df2c, 12) == b'CChatPrompt\0' and d(0x80df88 + 4) == 0xa8
assert d(0x80df88 + 12) == 0x411ef0 and d(0x80df88 + 16) == 0x411350
assert d(0x80e354) == 0x6a0d10 and original.imported(0x6a0d10)[1] == '?GetThisMessageMap@CEditView@@KGPBUAFX_MSGMAP@@XZ'
assert d(0x80d714 + 28) == 0x410f90 and d(0x80d714 + 32) == 0x410fe0
_reg = [e for e in original.pe.DIRECTORY_ENTRY_RESOURCE.entries if str(e.name) == 'REGISTRY'][0]
_r119 = [e for e in _reg.directory.entries if e.id == 119][0].directory.entries[0].data.struct
assert b'{70EBD57E-FD0D-4032-B090-9244AA7DED6E}' in original.pe.get_data(_r119.OffsetToData, _r119.Size)
assert b'\x50\x6a\x77' in original.data(0x410810, 24)   # UpdateRegistry pushes resource id 0x77 = 119
for a, b in zip(rows, rows[1:]):
    assert a + FUNCS[a]['size'] <= b, hex(a)


# ---- step 1: per-row evidence and unit assignment --------------------------------------------------------------------
def rtti_of(v):
    if not 0x7c0000 <= v < 0x980000:
        return None
    try:
        name, _ = original.vtable_class(v)
    except Exception:
        return None
    return name if name and name.startswith('.?A') else None


def string_at(v):
    if not 0x7c0000 <= v < 0x980000:
        return None
    try:
        raw = original.data(v, 128)
    except Exception:
        return None
    end = raw.find(b'\0')
    if end < 3 or any(c < 0x20 and c not in (9, 10, 13) or c > 0x7e for c in raw[:end]):
        return None
    return raw[:end].decode('latin-1')


def refs_of(a):
    code, rel, _ = match.target('2008-06', '%08x' % a)
    return {struct.unpack_from('<I', code, i)[0] for i in rel if i + 4 <= len(code)} | {
        int(x, 16) for x in FUNCS[a].get('data_refs', [])}


def evidence_of(a):
    r = FUNCS[a]
    refs = refs_of(a)
    ev = {}
    name = EVIDENCE.get('%08x' % a, {}).get('symbol')
    if name:
        ev['evidence_name'] = name
    vts = sorted({rtti_of(x) for x in refs} - {None})
    if vts:
        ev['rtti_refs'] = vts
    strs = sorted({s for s in (string_at(x) for x in refs) if s})
    if strs:
        ev['strings'] = strs[:4]
    imps = sorted({str(original.imports[x][2])[:70] for x in refs if x in original.imports})
    if imps:
        ev['imports'] = imps[:4]
    if r.get('callers'):
        ev['callers'] = [H(int(c, 16)) for c in r['callers'][:6]]
    return ev


assert 'Unable to create CClassImages' in evidence_of(0x413230).get('strings', [])
assert 'IBrowserViewExternal::GetApp-0x%X' in evidence_of(0x410fe0).get('strings', [])
assert 'Players' in evidence_of(0x411420).get('strings', [])

NOTES = {
    # CBrowserView / CBrowserViewExternal unit
    0x410810: 'CBrowserViewExternal::UpdateRegistry (DECLARE_REGISTRY_RESOURCEID(119): pushes 0x77 to '
              'CAtlModule::UpdateRegistryFromResourceD 0x4057f0); the committed header has no such macro (proposal); '
              'not emitted without an object-map reference',
    # CChatPrompt unit
    0x411160: 'boost::bad_weak_ptr::what (boost library inline; ICF-shared 6 B shape)',
    0x411170: 'jmp [InterlockedIncrement-style import] shared by Creatable operator new / delete and bad_weak_ptr '
              'destructor (ICF-folded 6 B import thunk); library',
    0x411180: 'boost::bad_weak_ptr scalar deleting destructor (boost library)',
    0x4111a0: 'CGdiObject::~CGdiObject (MFC inline; DeleteObject); library',
    0x4111d6: 'EH funclet of ~CGdiObject 0x4111a0 (MFC inline); library',
    0x4111e7: 'EH funclet / AfxMessageBox block of ~CGdiObject (MFC inline, atlmfc path string); library',
    0x411290: 'CBrush::~CBrush (MFC inline; stores vtable 0x80e068, jmp ~CGdiObject); library',
    0x4112a0: 'CWnd::SendMessage-style MFC inline (import 0x802e0c via m_hWnd +0x20), callers outside the unit; library',
    0x4112c0: 'MFC inline (import 0x802e14 via m_hWnd), callers outside the unit; library',
    0x411300: 'ChatEnter::process(const UIEvent&) (key "/" posts WM 0x468 to the owner; ChatEnter vtable 0x80e12c): '
              'ChatEnter.h declares no such member (proposal)',
    0x411370: 'CChatPrompt::PreCreateWindow (calls CEditView::PreCreateWindow); not declared in CChatPrompt.h (proposal)',
    0x4113a0: 'CChatPrompt message handler (CWnd::FromHandle); not declared in CChatPrompt.h (proposal)',
    0x411400: 'std::bad_alloc / boost::bad_weak_ptr copy constructor (library inline, vtable 0x80dfa8)',
    0x4114f0: 'CGdiObject scalar deleting destructor (MFC inline); library',
    0x411510: 'CBrush scalar deleting destructor (MFC inline); library',
    0x4115c0: 'CChatPrompt message handler (Get/SetWindowText); not declared in CChatPrompt.h (proposal)',
    0x411640: 'CChatPrompt::OnCreate (CEditView::OnCreate, CreateSolidBrush, CGdiObject::Attach); not declared '
              '(proposal)',
    0x4116f0: 'boost::shared_ptr<Instance> copy constructor (boost library inline shared by many units)',
    0x411790: 'G3D::Vector2 copy (library inline)',
    0x4119d0: 'std::_Copy_opt<shared_ptr<Instance>*> (evidence name; STL instance shared with other units)',
    0x411a50: 'std::_Copy_backward_opt<shared_ptr<Instance>*> (STL instance shared with other units)',
    0x411b40: 'DataModel::Lock constructor (evidence name; out of line in the core DataModel.h, owner)',
    0x411c30: 'CChatPrompt chat-send handler (DataModel::Lock, Players chat 0x49cb30); not declared (proposal)',
    0x411d55: 'EH funclet of 0x411c30',
    0x412050: 'stdext::unchecked_copy<shared_ptr<Instance>*> (STL instance shared with other units)',
    0x4120a0: 'CChatPrompt::GetMessageMap (AFX_MSGMAP 0x80e354 over CEditView); the header has no '
              'DECLARE_MESSAGE_MAP / handler declarations (proposal)',
    0x4120b0: 'std::_Copy_backward_opt / _Move_backward_opt<shared_ptr<Instance>*> (STL instance)',
    0x412100: 'std::_Uninit_fill_n<shared_ptr<Instance>*> (evidence name; STL instance)',
    0x412140: 'vector<shared_ptr<Instance>>::_Ufill (STL instance)',
    0x412180: 'vector<shared_ptr<Instance>>::erase (evidence name set; STL instance shared with other units)',
    0x412240: 'vector<shared_ptr<Instance>>::_Insert_n (evidence name; STL instance shared by every find<C>)',
    0x412425: 'catch funclet of _Insert_n 0x412240 (STL instance)',
    0x4124c0: 'vector<shared_ptr<Instance>>::resize (STL instance called by every find<C>; library)',
    0x412ac0: 'CWnd::GetParent-style MFC inline (FromHandle of GetParent(m_hWnd)); library, callers outside the unit',
    # CChildFrame unit
    0x412e60: 'CRbxChildFrame::OnGetMinMaxInfo (child-frame pending: needs CRenderSettings.h getFullscreenSize out of '
              'line; owner)',
    # CClassImages unit
    0x412f40: 'MFC comctl32 isolation-aware loader (GetProcAddress cache) for ImageList_Add; MFC library',
    0x412f90: 'MFC isolation wrapper ImageList_Add; MFC library',
    0x412fc0: 'MFC CImageList::Add inline (ImageList_Add wrapper); MFC library',
    0x413063: 'EH funclet of 0x412fc0 (MFC library)',
    0x413069: 'MFC activation-context helper of 0x412fc0 (library)',
    0x4130a0: 'MFC isolation wrapper ImageList_AddMasked; MFC library',
    0x4130d0: 'MFC CImageList::Add(CBitmap*, COLORREF) inline; MFC library',
    0x413173: 'EH funclet of 0x4130d0 (MFC library)',
    0x413179: 'MFC activation-context helper of 0x4130d0 (library)',
    0x4131b0: 'CBitmap::~CBitmap (MFC inline, vtable 0x80e8a0); library',
    0x4131c0: 'MFC CImageList inline (calls 0x412fc0), callers outside the unit; library',
    0x413200: 'MFC CImageList inline (calls 0x4130d0), callers outside the unit; library',
    # clipboard verb unit
    0x413490: 'CutVerb::doIt (vtable 0x80e990): body only in the committed DocumentInitialize.cpp / '
              'CRobloxDocCommands.cpp (document owner, maintainer exclusion); not rebuilt here',
    0x4134d0: 'PasteVerb::PasteVerb (body in DocumentInitialize.cpp, document owner)',
    0x413530: 'CopyVerb::CopyVerb (body in DocumentInitialize.cpp, document owner)',
    0x413560: 'map<string, string>::_Lrotate (TextXmlParser entity map; STL library instance)',
    0x4135b0: 'map<string, string>::_Max (STL library instance)',
    0x4135d0: 'map<string, string>::_Min (STL library instance)',
    0x4135f0: 'map<string, string>::_Rrotate (STL library instance)',
    0x413870: 'DeleteSelectionVerb constructor (inline of the verb headers; base of CutVerb); verb-family owner',
    0x4138f0: 'CopyVerb scalar deleting destructor (EditSelectionVerb dtor 0x57e050); verb-family owner',
    0x413920: 'CutVerb::CutVerb (body in DocumentInitialize.cpp, document owner)',
    0x413970: 'vector<shared_ptr<Instance>> iterator operator* (STL library instance)',
    0x4139b0: 'map<string, string>::const_iterator::_Inc (STL library instance)',
    0x413b90: 'vector<shared_ptr<Instance>>::_Buy (STL library instance)',
    0x413be0: 'map<string, string>::_Buynode (STL library instance)',
    0x413c20: 'Selection::front() const (document-initialize-trial / join-command-trial binding; Selection.h owner '
              'proposal 2026-11-03)',
    0x413d10: 'Selection::begin() const (Selection.h owner proposal 2026-11-03)',
    0x413d40: 'Selection::end() const (Selection.h owner proposal 2026-11-03)',
    0x413d70: 'map<InstanceHandle, int>::erase(iterator) (evidence name; STL instance shared with other units)',
}


def block_of(a):
    if a < CHAT_LO:
        return 'CBrowserView / CBrowserViewExternal unit (from 0x40df60) ..0x41111f'
    if a < FRAME_LO:
        return 'CChatPrompt unit 0x411120..0x412adf'
    if a < IMAGES_LO:
        return 'CChildFrame / CRbxChildFrame unit 0x412ae0..0x412f2f'
    if a < CLIP_LO:
        return 'CClassImages unit 0x412f30..0x41345f'
    return 'clipboard verb unit 0x413460.. (continues past the range)'


UNCLASSIFIED = []
unit_rows = []
for a in rows:
    entry = {'row': H(a), 'size': FUNCS[a]['size'], 'unit': block_of(a)}
    if a in exact_ints:
        entry['kind'] = 'counted here'
        entry['counted'] = '%08x counted here' % a
    elif a in counted_elsewhere:
        entry['kind'] = 'counted elsewhere'
        entry['counted'] = '%08x counted by %s' % (a, ', '.join(sorted(counted_elsewhere[a])))
        entry['row'] = 'see counted'
    else:
        entry['kind'] = 'open'
        pend = next((p for p in pending if int(p['address'], 16) == a), None)
        inst = next((s for s, v in INSTANCES.items() if v.get('address', '').replace('0x', '') == '%08x' % a), None)
        entry['note'] = NOTES.get(a) or (pend and 'pending-build-only %s (DECLARE_PROTECT_FINAL_CONSTRUCT header '
                                                  'proposal); not counted' % pend['symbol']) or (
            inst and '%s: %s' % (inst, INSTANCES[inst].get('status')))
        if not entry['note']:
            UNCLASSIFIED.append(H(a))
    entry['evidence'] = evidence_of(a)
    unit_rows.append(entry)
assert not UNCLASSIFIED, UNCLASSIFIED
stale = sorted(a for a in NOTES if a in exact_ints or a in counted_elsewhere or a not in FUNCS)
assert not stale, [H(a) for a in stale]

per_block = {}
for e in unit_rows:
    b = per_block.setdefault(e['unit'], {'rows': 0, 'counted_here': 0, 'counted_elsewhere': 0, 'open': 0})
    b['rows'] += 1
    b[{'counted here': 'counted_here', 'counted elsewhere': 'counted_elsewhere', 'open': 'open'}[e['kind']]] += 1
in_range = sorted(a for a in exact_ints if LO <= a < HI)
below = sorted(a for a in exact_ints if a < LO)
n_else = sum(1 for e in unit_rows if e['kind'] == 'counted elsewhere')

paths = [Path(__file__).resolve(), ROOT / 'rebuild/2008-06/tests/native_bind.py', EXT_CPP, CHAT_CPP, NAMES_CPP,
         PROMPT_CPP, CLIP_CPP, HDR / 'AppUnit410/BrowserViewExternalApp.h', HDR / 'CBrowserViewExternal.h',
         HDR / 'CChatPrompt.h', HDR / 'ChatEnter.h', HDR / 'ClipboardVerbs.h', HDR / 'Network/Players.h',
         HDR / 'v8tree/Service.h', HDR / 'mfc-noinline-pcxstr/atlsimpstr.h',
         HDR / 'boost-noinline-shared-destructor/boost/shared_ptr.hpp', HDR / 'std-noinline-string/xstring']
paths = [p for p in paths if p.exists()]
receipt = {
    'family': 'app unit 00410000 (CBrowserViewExternal COM unit, CChatPrompt unit, CChildFrame / CClassImages units, '
              'clipboard verb unit head)',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': FLAGS,
    'profile': 'document-swap flags; AppUnit410BrowserExternal.cpp with native-headers/mfc-noinline-pcxstr first; '
               'AppUnit410ChatPrompt.cpp with /fp:fast (find<Players> from a second build with '
               'native-headers/boost-noinline-shared-destructor first, as record_native_app_unit454_2008.py); '
               'ClipboardActions.cpp with std-noinline-string first (its native-flags); the rest plain',
    'original_sha256': sha(original.path),
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {k: sha(v) for k, v in OBJ.items()},
    'pending_object_sha256': sha(PENDING_OBJ),
    'range': [H(LO), H(HI)],
    'range_rows': len(rows),
    'unit_map': {
        'CBrowserView / CBrowserViewExternal unit (from 0x40df60) ..0x41111f': {
            'kind': 'rbx + ATL template instances over CBrowserViewExternal',
            'evidence': 'RTTI vtables 0x80d388 (CProxy_IBrowserViewExternalEvents), 0x80d5d4..0x80d638 (CComObject), '
                        '0x80d69c..0x80d700 (CComContainedObject), 0x80d714..0x80d778 (CComObjectNoLock), 0x80d7dc '
                        '(CComAggObject), 0x80d790 / 0x80d7f0 (CComObject<CComEnum<IEnumConnectionPoints / '
                        'IEnumConnections>>); IDispatchImpl slots 7 / 8 = get_IsIDE 0x410f90 / GetApp 0x410fe0 '
                        '("IBrowserViewExternal::GetApp-0x%X"); UpdateRegistry 0x410810 pushes REGISTRY 119 '
                        '"BrowserViewExternal Class"; CBrowserView rows counted by browser-view.',
            'recovered': 'native-classes/AppUnit410BrowserExternal.cpp (get_IsIDE, GetApp, the ATL instances); rows '
                         'below 0x410000 of the same unit counted by no receipt are counted here too'},
        'CChatPrompt unit 0x411120..0x412adf': {
            'kind': 'rbx + boost / MFC / STL inline instances',
            'evidence': 'CChatPrompt vtable 0x80e1ac, CRuntimeClass 0x80df88 ("CChatPrompt", 0xa8, CreateObject '
                        '0x411ef0, _GetBaseClass 0x411350), message map 0x80e354; ChatEnter vtable 0x80e12c; '
                        'doDeclare<sPlayers> pushes "Players"; bind 0x412800 calls create<Players> 0x412710.',
            'recovered': 'AppUnit410ChatPrompt.cpp (~CChatPrompt, IMPLEMENT_DYNCREATE, Players templates) and the '
                         'committed CChatPrompt.cpp (constructor, bind)'},
        'CChildFrame / CRbxChildFrame unit 0x412ae0..0x412f2f': {
            'kind': 'rbx (MFC frame)', 'evidence': 'child-frame receipt (vtables / runtime classes / message maps)',
            'recovered': 'nothing new (rows counted by child-frame / render-settings; 0x412e60 pending there)'},
        'CClassImages unit 0x412f30..0x41345f': {
            'kind': 'rbx + MFC comctl32 isolation wrappers',
            'evidence': 'CClassImages ctor 0x413230 ("Unable to create CClassImages"), ImageList_Add / '
                        'ImageList_AddMasked name strings, CBitmap vtable 0x80e8a0',
            'recovered': 'nothing new (RBX rows counted by insert-object-dialog / child-frame; the rest is MFC '
                         'library inline code)'},
        'clipboard verb unit 0x413460.. (continues past the range)': {
            'kind': 'rbx + STL instances',
            'evidence': 'CutVerb / CopyVerb / PasteVerb vtables 0x80e990 / 0x80e960 / 0x80e934; doDeclare rows push '
                        '"Model" / "Script" / "LocalScript" / "ChangeHistoryService"; doGetClassIndex<Selection> '
                        '0x413810 is called by find<Selection> 0x415200; ~XmlNameValuePair / ~XmlAttribute / '
                        '~XmlElement / setSelection / Name::c_str are emitted by ClipboardActions.cpp at these '
                        'addresses.',
            'recovered': 'AppUnit410ClipboardNames.cpp and the committed ClipboardActions.cpp (inline rows)'},
    },
    'blocks': per_block,
    'rows': unit_rows,
    'methods': results,
    'folded_aliases': {'0x' + k: sorted(v) for k, v in sorted(aliases.items())},
    'instances': {k: dict(v, address='0x' + v['address'].replace('0x', '')) for k, v in INSTANCES.items()},
    'vtables': vtables,
    'chat_prompt_vtable': {'address': hex(_vt), 'rtti': _rtti, 'object': 'current headers (chat build)',
                           'slots': chat_vtable},
    'local_statics': {k: {'address': hex(binding[k]), 'used_by': sorted(v)} for k, v in sorted(LOCAL_STATICS.items())},
    'counted_elsewhere': ['%08x counted by %s' % (a, ', '.join(sorted(v))) for a, v in sorted(counted_elsewhere.items())],
    'pending': pending,
    'not_exact': {},
    'rejected': [
        'AppUnit410BrowserExternal.cpp without _ATL_APARTMENT_THREADED: CComObjectThreadModel is CComMultiThreadModel, '
        'the CComEnum object is 0x38 bytes and EnumConnectionPoints 0x4100a0 compiles to 391 vs 440 B; the original '
        'RTTI names CComSingleThreadModel',
        'GetApp without the mfc-noinline-pcxstr profile: operator PCXSTR is inlined (305 vs 314 B)',
        'find<Players> without NonFactoryProduct::className: className() is called out of line (386 B / 302 B '
        'with the noinline-destructor profile, vs 320 B)',
        'find<Players> in the plain build: ~shared_ptr<Instance> inlined (404 vs 320 B)',
        'CComCreator<CComObject<CBrowserViewExternal>>::CreateInstance 0x40f9a0 with the committed header (no '
        'DECLARE_PROTECT_FINAL_CONSTRUCT): 186 vs 153 + 38 B (pending build is exact)',
    ],
    'range_rows_counted_here': len(in_range),
    'unit_rows_counted_below_range': ['%08x' % a for a in below],
    'shadowing': 'none (new header native-headers/AppUnit410/BrowserViewExternalApp.h has no donor counterpart and is '
                 'included only by AppUnit410BrowserExternal.cpp)',
    'exact_function_rows': exact,
    'scope': 'Inactive. Exact rows with every target verified; pending-build rows are not counted; no active build, '
             'swap or credit.',
}
if COLLECT:
    for x in sorted(COLLECT):
        print('UNBOUND', x)
    raise SystemExit('unbound relocations')
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native app unit410: %d rows mapped, %d exact (%d in range, %d below), %d counted elsewhere, %d vtables, '
      '%d instances, %d pending-only' % (len(rows), len(exact), len(in_range), len(below), n_else, len(vtables),
                                        len(INSTANCES), len(pending)))
print('  exact:', ' '.join(exact))
for b, v in per_block.items():
    print('  %s: %s' % (b, v))
print('  CChatPrompt vtable mismatches:', {k: v for k, v in chat_vtable.items() if not str(v).startswith('?') and
                                            ('MISMATCH' in v or 'UNBOUND' in v)})
