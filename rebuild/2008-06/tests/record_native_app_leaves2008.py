"""Verify the inactive native 2008-06 app leaves: CRbxDocTemplate / CRbxPlayDocTemplate and RobloxCrashReporter.

Builds (document-swap flags, VS2008 RTM 21022; the CrashReporter unit also puts native-headers/mfc-noinline-pcxstr
first, the CRobloxApp profile, because 00427a20 calls the mfc90 CString PCXSTR operator out of line):
  * tests/NativeAppLeaves2008Layout.cpp       sizeof/offsetof checks and the two doc-template vtables (the
                                              constructors are inline in the original, inside 00449910);
  * native-classes/AppLeaves2008DocTemplates.cpp  native-headers/AppLeaves2008/RbxDocTemplates2008.h;
  * native-classes/AppLeaves2008CrashReporter.cpp  native-headers/AppLeaves2008/RobloxCrashReporter2008.h on the
                                              donor Network/CrashReporter.h;
  * both units again with NATIVE_APPLEAVES2008_PENDING against generated header copies in
    out/native-layouts/app-leaves2008-pending/ (no shared header is edited):
      CRobloxApp.h with `BOOL initializeFramework(bool);` (committed: `(void*)`; 00449bf0 tests the argument
      with `cmp byte ptr [esp+0x1c], 0` and 0044a170 pushes 1), and the donor Network/CrashReporter.h with an inline
      `CrashReporter() { singleton = this; }` (00427a20 has no CrashReporter constructor call, only the
      singleton store 009706c0). Rows exact only there are recorded exact=false (pending-build-only) and are not
      counted.
Second pass (2026-11-05), separate units so the 13 rows above keep their objects:
  * native-classes/AppLeaves2008PlayDocument.cpp  CRbxPlayDocTemplate::getPlayDocument 0044b9a0 and the pending
                                              play-error global/helpers, preprocessed with CSimpleStringT::IsEmpty and
                                              operator PCXSTR noinline (the original imports both: mfc90 #4311/#910);
  * native-classes/AppLeaves2008RobloxModule.cpp   CRobloxModule (CAtlMfcModule) and its global;
  * native-classes/AppLeaves2008Marshaller.cpp     Marshaller (ATL CWindowImpl, deque of boost::function, mutex);
  * native-classes/AppLeaves2008RBXImage.cpp       RBXImage (CImage-shaped, no GDI+ bookkeeping);
  * native-classes/AppLeaves2008Exposer.cpp        Exposer : PacketLogger (RakNet 3.0 headers);
  * tests/NativeAppLeaves2008Layout2.cpp           sizeof/offsetof checks for those four classes.
  RakNet PacketLogger.cpp / PluginInterface.cpp are compiled from tools/rbxgs (read-only) as library providers.
Inline/library instances a row calls (ATL, boost, STL, RakNet) are bound by bytes: the instance this build emits
must equal the function at the called address, with every one of its own targets verified the same way
(recursively); they are listed under 'instances' and not counted.
Every relocation of an exact row is bound to the address the original instruction uses and verified: imports by
mfc90 ordinal / DLL name, literals by bytes, RTTI and vtables by original RTTI names, own symbols by the row
proven here, everything else by the explicit EXTERNAL / DATA maps below (one address per symbol).
Vtable slots are compared from the object built from the current headers (never the pending one).
Writes work/2008-06/shared-layouts/app-leaves2008-working.json.
"""
import json
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import native_bind as nb  # noqa: E402
from native_bind import ROOT, OUT, LOCAL_EH, Original, flags, match, rebuild, sha  # noqa: E402

HDR = ROOT / 'rebuild/2008-06/native-headers'
SRC = ROOT / 'rebuild/2008-06/native-classes'
LAYOUT = Path(__file__).resolve().parent / 'NativeAppLeaves2008Layout.cpp'
DOC_H = HDR / 'AppLeaves2008/RbxDocTemplates2008.h'
CRASH_H = HDR / 'AppLeaves2008/RobloxCrashReporter2008.h'
EH_H = HDR / 'AppLeaves2008/EventHandler2008.h'
DOC_CPP = SRC / 'AppLeaves2008DocTemplates.cpp'
EH_CPP = SRC / 'AppLeaves2008EventHandler.cpp'
CRASH_CPP = SRC / 'AppLeaves2008CrashReporter.cpp'
APP_H = HDR / 'CRobloxApp.h'
DONOR_CRASH_H = ROOT / 'tools/rbxgs/Client/Network/include/Network/CrashReporter.h'
PCXSTR = '/I' + str(HDR / 'mfc-noinline-pcxstr')
PENDING = OUT / 'app-leaves2008-pending'
original = Original()


def d(address):
    return struct.unpack('<I', original.data(address, 4))[0]


def build(source, name, pre=(), extra=()):
    OUT.mkdir(parents=True, exist_ok=True)
    obj = OUT / (name + '.obj')
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', list(pre) + flags() + list(extra) + ['/Fo' + str(obj), str(source)], OUT)
    assert code == 0, log
    return obj


# ---- generated pending header copies ------------------------------------------------------------------------
(PENDING / 'Network').mkdir(parents=True, exist_ok=True)
app = APP_H.read_text()
assert app.count('BOOL initializeFramework(void*);') == 1
(PENDING / 'CRobloxApp.h').write_text(app.replace('BOOL initializeFramework(void*);', 'BOOL initializeFramework(bool);'))
crash = DONOR_CRASH_H.read_text()
assert crash.count('\tCrashReporter();') == 1
(PENDING / 'Network/CrashReporter.h').write_text(crash.replace('\tCrashReporter();', '\tCrashReporter() { singleton = this; }'))

layout_obj = build(LAYOUT, 'NativeAppLeaves2008Layout')
doc_obj = build(DOC_CPP, 'NativeAppLeaves2008Doc')
crash_obj = build(CRASH_CPP, 'NativeAppLeaves2008Crash', pre=[PCXSTR])
eh_obj = build(EH_CPP, 'NativeAppLeaves2008EventHandler')
doc_pobj = build(DOC_CPP, 'NativeAppLeaves2008DocPending', pre=['/I' + str(PENDING)], extra=['/DNATIVE_APPLEAVES2008_PENDING'])
crash_pobj = build(CRASH_CPP, 'NativeAppLeaves2008CrashPending', pre=['/I' + str(PENDING), PCXSTR],
                   extra=['/DNATIVE_APPLEAVES2008_PENDING'])

RAKNET_SRC = ROOT / 'tools/rbxgs/Client/Network/raknet30/Source'
RAKNET = ['/I' + str(RAKNET_SRC)]
PLAY_CPP = SRC / 'AppLeaves2008PlayDocument.cpp'
MODULE_CPP = SRC / 'AppLeaves2008RobloxModule.cpp'
MARSHALLER_CPP = SRC / 'AppLeaves2008Marshaller.cpp'
IMAGE_CPP = SRC / 'AppLeaves2008RBXImage.cpp'
EXPOSER_CPP = SRC / 'AppLeaves2008Exposer.cpp'
LAYOUT2 = Path(__file__).resolve().parent / 'NativeAppLeaves2008Layout2.cpp'
NEW_HEADERS = [HDR / ('AppLeaves2008/%s.h' % n) for n in ('RobloxModule2008', 'Marshaller2008', 'RBXImage2008', 'Exposer2008')]


def build_noinline(source, name):
    """Preprocess, mark CSimpleStringT::operator PCXSTR and IsEmpty noinline, compile (the browser-view profile)."""
    tool = rebuild.toolchain(21022)
    code, log = rebuild.run(tool, 'cl', [x for x in flags() if x != '/c'] + ['/P', str(source)], OUT)
    assert code == 0, log[-3000:]
    body = (OUT / (Path(source).stem + '.i')).read_text(errors='replace')
    for needle in ('operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );',
                   'bool IsEmpty() const throw()\n\t{\n\t\treturn( GetLength() == 0 );'):
        assert body.count(needle) == 1, needle
        body = body.replace(needle, '__declspec(noinline) ' + needle)
    unit = OUT / (name + '.cpp')
    unit.write_text(body)
    obj = OUT / (name + '.obj')
    code, log = rebuild.run(tool, 'cl', ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD',
                                         '/Fo' + str(obj), str(unit)], OUT)
    assert code == 0, log[-3000:]
    return obj


play_obj = build_noinline(PLAY_CPP, 'NativeAppLeaves2008Play')
module_obj = build(MODULE_CPP, 'NativeAppLeaves2008Module')
marshaller_obj = build(MARSHALLER_CPP, 'NativeAppLeaves2008Marshaller')
image_obj = build(IMAGE_CPP, 'NativeAppLeaves2008Image')
exposer_obj = build(EXPOSER_CPP, 'NativeAppLeaves2008Exposer', extra=RAKNET)
layout2_obj = build(LAYOUT2, 'NativeAppLeaves2008Layout2', extra=RAKNET)
# Library providers (RakNet 3.0 as shipped in the donor tree), same flags.
packetlogger_obj = build(RAKNET_SRC / 'PacketLogger.cpp', 'NativeAppLeaves2008RakPacketLogger', extra=RAKNET)
plugin_obj = build(RAKNET_SRC / 'PluginInterface.cpp', 'NativeAppLeaves2008RakPluginInterface', extra=RAKNET)
LIBS = [packetlogger_obj, plugin_obj]
# atls.lib (MFC 9.0 RTM, the archive the exe links: recipe msvc-atlmfc-rtm): members are extracted on demand for the
# out-of-line ATL library functions an instance calls (thunk allocation, CAtlWinModule).
ATLS = ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/lib/atls.lib'


class ArchiveIndex(dict):
    """symbol -> member object path; a member is written under out/ only when one of its symbols is needed."""
    def __init__(self, path):
        dict.__init__(self)
        data, i, k = Path(path).read_bytes(), 8, 0
        assert data[:8] == b'!<arch>\n'
        self.members = {}
        while i < len(data):
            size = int(data[i + 48:i + 58])
            member = data[i + 60:i + 60 + size]
            if member[:2] == b'\x4c\x01':
                names = [n for n, _, _ in match.coff_functions(member)]
                if names:
                    obj = OUT / ('atls-member-%d.obj' % k)
                    self.members[obj] = member
                    k += 1
                    for n in names:
                        self.setdefault(n, obj)
            i += 60 + size + (size & 1)

    def get(self, symbol, default=None):
        obj = dict.get(self, symbol, default)
        if obj is not None and obj in self.members and not obj.exists():
            obj.write_bytes(self.members[obj])
        return obj

    def __getitem__(self, symbol):
        return self.get(symbol)


def archive_index(path):
    return ArchiveIndex(path)


ATLS_INDEX = archive_index(ATLS)

# ---- rows ---------------------------------------------------------------------------------------------------
ONEXEC = '?onExecute@Marshaller@@QAEJIIJAAH@Z'
INVOKE = '?Invoke@EventHandler@@UAGJJABU_GUID@@KGPAUtagDISPPARAMS@@PAUtagVARIANT@@PAUtagEXCEPINFO@@PAI@Z'
ROWS = {   # object -> [(address | (address, start, end), symbol)]
    'layout': [(0x0044a1a0, '??_GCRbxDocTemplate@@UAEPAXI@Z'),
               (0x0044a1c0, '??_GCRbxPlayDocTemplate@@UAEPAXI@Z')],
    'doc': [(0x004496f0, '?RemoveDocument@CRbxPlayDocTemplate@@UAEXPAVCDocument@@@Z'),
            (0x00449720, '?openDocumentFile@CRbxPlayDocTemplate@@QAEPAVCDocument@@PBDH@Z')],
    'crash': [(0x00427b00, '?ProcessException@RobloxCrashReporter@@UAEJPAU_EXCEPTION_POINTERS@@@Z')],
    'eh': [(0x0042acb0, '??0EventHandler@@QAE@V?$function0@_NV?$allocator@Vfunction_base@boost@@@std@@@boost@@@Z'),
           (0x0042adb0, '?QueryInterface@EventHandler@@UAGJABU_GUID@@PAPAX@Z'),
           (0x0042ae10, '?AddRef@EventHandler@@UAGKXZ'),
           (0x0042b350, '?Release@EventHandler@@UAGKXZ'),
           (0x0042ae20, '?GetTypeInfoCount@EventHandler@@UAGJPAI@Z'),
           (0x0042ae30, '?GetTypeInfo@EventHandler@@UAGJIKPAPAUITypeInfo@@@Z'),
           (0x0042ae40, '?GetIDsOfNames@EventHandler@@UAGJABU_GUID@@PAPA_WIKPAJ@Z'),
           # Invoke: the function list cuts the body at its catch funclet; both pieces are checked.
           ((0x0042b130, 0, 97), INVOKE), ((0x0042b191, 97, 170), INVOKE)],
    'play': [(0x0044b9a0, '?getPlayDocument@CRbxPlayDocTemplate@@QAEPAVCDocument@@XZ'),
             (0x0044aa70, '?setPendingPlayError@@YAXABVexception@std@@@Z'),
             (0x0044ab30, '?throwPendingPlayError@@YAXXZ'),
             (0x007ef860, '??__EpendingPlayError@@YAXXZ'),
             (0x007fadf0, '??__FpendingPlayError@@YAXXZ')],
    'module': [(0x007ef7d0, '??__E_AtlModule@@YAXXZ'),
               (0x007fae10, '??__F_AtlModule@@YAXXZ'),
               (0x0044be40, '??_GCRobloxModule@@UAEPAXI@Z')],
    'marshaller': [(0x0041b310, '??0Marshaller@@QAE@K@Z'),
                   (0x0041a250, '??1Marshaller@@UAE@XZ'),
                   (0x0041b3d0, '??_GMarshaller@@UAEPAXI@Z'),
                   (0x0041b1e0, '?ProcessWindowMessage@Marshaller@@UAEHPAUHWND__@@IIJAAJK@Z'),
                   # onExecute: the function list ends the body at 0041a4f0, where its catch funclet starts (that
                   # funclet is not a listed function: checked against the image bytes, fields masked, targets bound).
                   ((0x0041a410, 0, 224), ONEXEC), ((0x0041a4f0, 224, 273, 'raw'), ONEXEC),
                   (0x0041a530, '?post@Marshaller@@QAEXV?$function0@XV?$allocator@Vfunction_base@boost@@@std@@@boost@@@Z'),
                   (0x00432a70, '?OnFinalMessage@Marshaller@@UAEXPAUHWND__@@@Z')],
    'image': [(0x00442c90, '??0RBXImage@@QAE@XZ'),
              (0x00442db0, '??1RBXImage@@UAE@XZ'),
              (0x00442f20, '??_GRBXImage@@UAEPAXI@Z'),
              (0x00442c50, '?GetPixelAddress@RBXImage@@QAEPAXHH@Z'),
              (0x00442c80, '?GetWidth@RBXImage@@QBEHXZ'),
              (0x00442ce0, '?UpdateBitmapInfo@RBXImage@@QAEXW4DIBOrientation@1@@Z'),
              (0x00442df0, '?CreateEx@RBXImage@@QAEHHHHKPBKK@Z'),
              (0x00442f70, '?Create@RBXImage@@QAEHHHHK@Z')],
    'exposer': [(0x0049f180, '?IDTOString@Exposer@@SAPBDH@Z'),
                (0x0049ed90, '??_GExposer@@UAEPAXI@Z')],
}
# SDK / boost inline instances emitted out of line in the original and in this unit: verified, not counted.
HELPERS = {
    'eh': [(0x0042ad40, '_IsEqualGUID'),
           (0x0042afc0, '??R?$function0@_NV?$allocator@Vfunction_base@boost@@@std@@@boost@@QBE_NXZ')],
}
PENDING_ROWS = {
    'doc_pending': [(0x0044a170, '?CreateNewFrame@CRbxDocTemplate@@UAEPAVCFrameWnd@@PAVCDocument@@PAV2@@Z')],
    'crash_pending': [(0x00427a20, '??0RobloxCrashReporter@@QAE@PBD0W4_MINIDUMP_TYPE@@@Z')],
}
OBJ = {'layout': layout_obj, 'doc': doc_obj, 'crash': crash_obj, 'eh': eh_obj, 'doc_pending': doc_pobj, 'crash_pending': crash_pobj,
       'play': play_obj, 'module': module_obj, 'marshaller': marshaller_obj, 'image': image_obj, 'exposer': exposer_obj,
       'layout2': layout2_obj}

# Explicit bindings (address the original instruction uses; evidence in the comment).
EXTERNAL = {
    # CrashReporter::ProcessException: evidence name of 0049e290 (?ProcessException@CrashReporter@@...).
    '?ProcessException@CrashReporter@@UAEJPAU_EXCEPTION_POINTERS@@@Z': 0x0049e290,
    # CRobloxApp::initializeFramework: native-headers/CRobloxApp.h names 00449bf0.
    '?initializeFramework@CRobloxApp@@QAEH_N@Z': 0x00449bf0,
    # CVersionInfo (native-headers/VersionInfo.h, sizeof 0x14): ctor 0046a200 (+0 = 0, +2 = 1252, +4..+10 = 0),
    # dtor 0046a4b0 (Unload + reset), Load(HINSTANCE) 0046a4f0 (GetModuleFileNameA then Load(CString)),
    # GetFileVersionAsString 0046a440 (GetValue("FileVersion"), string checked below).
    '??0CVersionInfo@@QAE@XZ': 0x0046a200,
    '??1CVersionInfo@@QAE@XZ': 0x0046a4b0,
    '?Load@CVersionInfo@@QAEHPAUHINSTANCE__@@@Z': 0x0046a4f0,
    '?GetFileVersionAsString@CVersionInfo@@QAE?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@XZ': 0x0046a440,
    # MFC inline ~CWaitCursor (AFX destructor try/catch) emitted out of line at 00449460; prefix checked below.
    '??1CWaitCursor@@QAE@XZ': 0x00449460,
    # RBX::StandardOut (donor util/standardout.h): singleton 00569620, print(MessageType, const std::exception&)
    # 00416e10, ~shared_ptr<StandardOut> 00600660 (the bindings record_native_leaves2008.py proves).
    '?singleton@StandardOut@RBX@@SA?AV?$shared_ptr@VStandardOut@RBX@@@boost@@XZ': 0x00569620,
    '?print@StandardOut@RBX@@QAEXW4MessageType@2@ABVexception@std@@@Z': 0x00416e10,
    '??1?$shared_ptr@VStandardOut@RBX@@@boost@@QAE@XZ': 0x00600660,
    # boost::function0 call-to-empty path (evidence names; same bindings as record_native_network_players.py).
    '??0bad_function_call@boost@@QAE@XZ': 0x00409ef0,
    '??$throw_exception@Vbad_function_call@boost@@@boost@@YAXABVbad_function_call@0@@Z': 0x0040a500,
    # setActiveDocument(bool, CRobloxDoc*): 00405aa0 (record_native_active_document_data.py / pane_callbacks bind it).
    '?setActiveDocument@@YAX_NPAVCRobloxDoc@@@Z': 0x00405aa0,
    # boost 1.34.1 mutex (thread library code): the bindings record_native_content_provider_layout.py and
    # record_native_content_load_trial.py prove (ctor 00594c90, dtor 00594cb0, do_lock 00594ce0, do_unlock 00594d00).
    '??0mutex@boost@@QAE@XZ': 0x00594c90,
    '??1mutex@boost@@QAE@XZ': 0x00594cb0,
    '?do_lock@mutex@boost@@AAEXXZ': 0x00594ce0,
    '?do_unlock@mutex@boost@@AAEXXZ': 0x00594d00,
    # CRT atexit (the binding record_native_active_document_data.py & co. use).
    '_atexit': 0x006a17af,
}
DATA = {
    '?theApp@@3VCRobloxApp@@A': 0x0096dbe0,           # ecx of the 00449bf0 call; CRobloxApp ctor target (static init)
    '?silentCrashReport@@3_NA': 0x0096d0f4,           # "SilentCrashReport" != 0, stored by 0044c760
    '?singleton@CrashReporter@@2PAV1@A': 0x009706c0,  # CrashReporter::singleton (00427a20 stores this)
    '?_AtlBaseModule@ATL@@3VCAtlBaseModule@1@A': 0x0097f2a8,  # CAtlBaseModule ctor 007a5cd2 via static init 007f9ef6
    '?activeRobloxDoc@@3PAVCRobloxDoc@@A': 0x0096c238,  # record_native_active_document_data.py (zero global)
    # pendingPlayError: the scoped_ptr whose atexit destructor 007fadf0 (a row here) deletes [0096dcf4].
    '?pendingPlayError@@3V?$scoped_ptr@Vexception@std@@@boost@@A': 0x0096dcf4,
    # _AtlModule: the CRobloxModule global (dynamic initializer 007ef7d0 stores its vptr 00816a28 there).
    '?_AtlModule@@3VCRobloxModule@@A': 0x0096dbb4,
    # ATL selectany globals: _pAtlModule (= this in the CAtlModule constructor; record_native_content* bind 0096c268)
    # and CAtlBaseModule::m_bInitFailed (set when the critical section Init fails, 007ef7e8).
    '?_pAtlModule@ATL@@3PAVCAtlModule@1@A': 0x0096c268,
    # atls.lib _AtlWinModule: CAtlWinModule ctor 007a6196 via static init 007f9f4f, atexit dtor 00801969 (the same
    # pattern as _AtlBaseModule 0097f2a8 just before it).
    '?_AtlWinModule@ATL@@3VCAtlWinModule@1@A': 0x0097f314,
    '?m_bInitFailed@CAtlBaseModule@ATL@@2_NA': 0x0096dcf8,
    # ProcessException's function-local static and its guard bit (00427b00).
    '?messageShown@?1??ProcessException@RobloxCrashReporter@@UAEJPAU_EXCEPTION_POINTERS@@@Z@4_NA': 0x0096d104,
    '?$S1@?1??ProcessException@RobloxCrashReporter@@UAEJPAU_EXCEPTION_POINTERS@@@Z@4IA': 0x0096d108,
}

def first(address):
    return address[0] if isinstance(address, tuple) else address


# GUID constants (uuid.lib data in the original): verified by their 16 bytes.
GUIDS = {'_IID_IUnknown': '00000000-0000-0000-c000-000000000046', '_IID_IDispatch': '00020400-0000-0000-c000-000000000046',
         '_IID_IGlobalInterfaceTable': '00000146-0000-0000-c000-000000000046',
         '_CLSID_StdGlobalInterfaceTable': '00000323-0000-0000-c000-000000000046'}

all_rows = [x for v in ROWS.values() for x in v] + [x for v in PENDING_ROWS.values() for x in v] + \
    [x for v in HELPERS.values() for x in v]
own = {}
for addr, sym in all_rows:   # a split body binds to the address of its first piece
    own.setdefault(sym, first(addr))
pending_addrs = {addr for v in PENDING_ROWS.values() for addr, _ in v}
binding = {}


def classify(symbol, value, raw, sections, definitions, where):
    hit = original.imported(value)
    if hit is not None:
        assert hit[1] == nb.plain(symbol), (where, symbol, hex(value), hit)
        return '%s!%s' % hit
    if symbol.startswith('??_C@_1'):   # wide literal: up to the first aligned L'\0'
        pos, at = definitions[symbol]
        data = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]]
        end = next(i for i in range(0, len(data), 2) if data[i:i + 2] == b'\0\0') + 2
        literal = data[:end]
        assert original.data(value, len(literal)) == literal, (where, symbol, hex(value))
        return 'wide literal %r' % literal[:-2].decode('utf-16le')
    if symbol.startswith('??_C@'):
        pos, at = definitions[symbol]
        literal = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
        assert original.data(value, len(literal)) == literal, (where, symbol, hex(value))
        return 'literal %r' % literal[:-1].decode()
    if symbol.startswith('__TI') and '?AV' in symbol:
        # _ThrowInfo: pCatchableTypeArray +12 -> first CatchableType -> TypeDescriptor name
        cta = d(value + 12)
        assert d(cta) == int(symbol[4]), (where, symbol, hex(value))
        name = original.string(d(d(cta + 4) + 4) + 8)
        assert name == '.' + symbol[5:], (where, symbol, hex(value), name)
        return 'throw info %s (%d catchable types)' % (name, d(cta))
    if symbol.startswith('??_R0') and symbol.endswith('@8'):
        rtti = original.string(value + 8)
        assert rtti == '.' + symbol[5:-2], (where, symbol, hex(value), rtti)
        return 'RTTI %s' % rtti
    if symbol.startswith('??_7'):
        rtti, at = original.vtable_class(value)
        assert rtti == '.?AV' + symbol[4:symbol.index('@@6B') + 2], (where, symbol, hex(value), rtti)
        return 'vtable RTTI %s offset %#x' % (rtti, at)
    if symbol in own:
        assert own[symbol] == value, (where, symbol, hex(value), hex(own[symbol]))
        return 'pending-build-only row' if value in pending_addrs else 'own row'
    if symbol.startswith('??_E') and ('??_G' + symbol[4:]) in own:
        assert own['??_G' + symbol[4:]] == value, (where, symbol, hex(value))
        return 'own row (??_G)'
    if symbol in EXTERNAL:
        assert EXTERNAL[symbol] == value, (where, symbol, hex(value), hex(EXTERNAL[symbol]))
        return 'external'
    if symbol in GUIDS:
        import uuid
        assert str(uuid.UUID(bytes_le=original.data(value, 16))) == GUIDS[symbol], (where, symbol, hex(value))
        return 'GUID {%s}' % GUIDS[symbol]
    if symbol in DATA:
        assert DATA[symbol] == value, (where, symbol, hex(value), hex(DATA[symbol]))
        return 'data'
    if EVIDENCE.get('%08x' % value, {}).get('symbol') == symbol:
        return 'evidence name'
    return instance(symbol, value, where)


EVIDENCE = json.loads((ROOT / 'rebuild/2008-06/offline/evidence.json').read_text())['names']
LENIENT = []          # inside a library body: unprovable library-internal targets are listed, not asserted
CURRENT = []          # object whose relocations are being bound (instances are looked up there first)
INSTANCES = {}        # symbol -> verified instance record
BODIES = {}


def bodies_of(obj):
    if obj not in BODIES:
        BODIES[obj] = {n: (b, r) for n, b, r in match.coff_functions(Path(obj).read_bytes())}
    return BODIES[obj]


def instance(symbol, value, where):
    """An inline / library body this build emits, proven by bytes at the called address and by its own targets."""
    if symbol in INSTANCES:
        assert INSTANCES[symbol]['address'] == '%08x' % value, (where, symbol, hex(value))
        return 'library instance (bytes equal)' if 'library' in INSTANCES[symbol].get('status', '') else \
            'instance (bytes equal, targets verified)'
    for obj in CURRENT[-1:] + LIBS + ([ATLS_INDEX[symbol]] if symbol in ATLS_INDEX else []):
        if symbol in bodies_of(obj):
            break
    else:
        return data_instance(symbol, value, where)
    library = obj in LIBS or obj == ATLS_INDEX.get(symbol)
    body = bodies_of(obj)[symbol][0]
    try:
        target, _, _ = match.target('2008-06', '%08x' % value)
        unlisted = False
    except SystemExit:   # not a listed function start (inside a merged extent): image bytes compared
        target, unlisted = b'', True
    merged = len(body) != len(target)
    # The function list cuts bodies at catch funclets / SEH filters and runs some library functions into their
    # neighbours; then the whole emitted body is compared with the image bytes at the called address.
    spec = (value, 0, len(body), 'raw') if merged else value
    INSTANCES[symbol] = {'address': '%08x' % value, 'pending': True}
    LENIENT.append(library)
    try:
        row = verify(obj, [(spec, symbol)], False)[0]
    except AssertionError:
        if not library:
            raise
        del INSTANCES[symbol]   # a donor-library body that differs proves nothing: leave the symbol unbound here
        return None
    finally:
        LENIENT.pop()
    row['status'] = 'instance (%s), bytes equal, not counted' % (
        ('library ' + ('atls.lib member' if obj == ATLS_INDEX.get(symbol) else Path(obj).stem) +
         '; its own targets bound where provable, library-internal ones listed as not followed')
        if library else 'emitted by this unit; every own target verified')
    if unlisted:
        row['status'] += '; not a listed function start, whole body compared with the image bytes'
    elif merged:
        row['status'] += '; listed extent %#x != body %#x, whole body compared with the image bytes' % (
            len(target), len(body))
    INSTANCES[symbol] = row
    return 'library instance (bytes equal)' if library else 'instance (bytes equal, targets verified)'


def data_instance(symbol, value, where):
    """Initialized data this unit defines (an ATL function-local static such as the window class info): bytes equal
    at the referenced address with relocated fields masked, and every relocated field bound like a code target."""
    if not CURRENT:
        return None
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
                         'status': 'data instance emitted by this unit (bytes equal, fields verified), not counted',
                         'verified_targets': verified}
    return 'data instance (bytes equal, fields verified)'


def verify(obj, rows, exact_flag):
    CURRENT.append(obj)
    try:
        return verify_rows(obj, rows, exact_flag)
    finally:
        CURRENT.pop()


def verify_rows(obj, rows, exact_flag):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = bodies_of(obj)
    out = []
    for spec, name in rows:
        body, refs = bodies[name]
        address, lo, hi = spec[:3] if isinstance(spec, tuple) else (spec, 0, len(body))
        body, refs = body[lo:hi], [r - lo for r in refs if lo <= r < hi]
        if isinstance(spec, tuple) and spec[3:] == ('raw',):
            # Not a listed function: compare with the image bytes; every masked field is bound below.
            target, target_refs = original.data(address, len(body)), []
        else:
            target, target_refs, _ = match.target('2008-06', '%08x' % address)
        assert match.exact_match(target, target_refs, body, refs), (name, hex(address), len(body), len(target))
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
            if how is None and LENIENT and LENIENT[-1]:
                verified[symbol] = '%s (library-internal, not followed)' % hex(value)
                continue
            assert how is not None, ('unbound relocation', name, symbol, hex(value))
            prev = binding.setdefault(symbol, value)
            assert prev == value, ('inconsistent binding', symbol, hex(prev), hex(value))
            verified[symbol] = '%s (%s)' % (hex(value), how)
        row = {'address': '%08x' % address, 'symbol': name + ('' if (lo, hi) == (0, len(bodies[name][0])) else ' [%#x:%#x]' % (lo, hi)),
               'size': len(body), 'exact': exact_flag,
               'verified_targets': verified, 'local_eh': sorted(local)}
        if not exact_flag:
            row['status'] = 'pending-build-only'
        out.append(row)
    return out


results = {k: verify(OBJ[k], v, True) for k, v in ROWS.items()}
results.update({k: verify(OBJ[k], v, False) for k, v in PENDING_ROWS.items()})
helpers = {k: verify(OBJ[k], v, True) for k, v in HELPERS.items()}
for k in helpers:
    for r in helpers[k]:
        r['exact'] = False
        r['status'] = 'helper instance (SDK/boost inline), verified, not counted'
names = json.loads((ROOT / 'rebuild/2008-06/offline/evidence.json').read_text())['names']
assert names['0042afc0']['symbol'] == HELPERS['eh'][1][1], names.get('0042afc0')

# ~CWaitCursor at 00449460: the function list cuts it at the catch funclet (56 bytes); the native inline instance
# emitted in the doc unit must start with the same bytes (relocation fields masked).
raw = doc_obj.read_bytes()
wc = {n: (b, r) for n, b, r in match.coff_functions(raw)}['??1CWaitCursor@@QAE@XZ']
target, target_refs, _ = match.target('2008-06', '00449460')
assert match.exact_match(target, [r for r in target_refs if r < len(target)], wc[0][:len(target)],
                         [r for r in wc[1] if r < len(target)]), 'CWaitCursor prefix'
assert original.string(0x0081c478) == 'FileVersion' and original.string(0x00816bc0) == 'SilentCrashReport'


# ---- vtables of the current-header objects ------------------------------------------------------------------
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


def local_body(raw, symbol, value):
    """An inline MFC body (CObject::Serialize & co.) emitted here: proven by bytes against the slot target."""
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    if symbol not in bodies:
        return None
    target, target_refs, _ = match.target('2008-06', '%08x' % value)
    body, refs = bodies[symbol]
    if not refs and len(body) == len(target) and match.exact_match(target, target_refs, body, refs):
        return 'inline body, bytes equal (ICF-shared copy)'
    return None


VTABLES = {'??_7CRbxDocTemplate@@6B@': (layout_obj, 0x00816684, '.?AVCRbxDocTemplate@@', 37),
           '??_7CRbxPlayDocTemplate@@6B@': (layout_obj, 0x0081671c, '.?AVCRbxPlayDocTemplate@@', 37),
           '??_7EventHandler@@6B@': (eh_obj, 0x00810598, '.?AVEventHandler@@', 7),
           '??_7CRobloxModule@@6B@': (module_obj, 0x00816a28, '.?AVCRobloxModule@@', 6),
           '??_7Marshaller@@6B@': (marshaller_obj, 0x0080eccc, '.?AVMarshaller@@', 4),
           '??_7RBXImage@@6B@': (image_obj, 0x008157c0, '.?AVRBXImage@@', 1),
           '??_7Exposer@@6B@': (exposer_obj, 0x00822d3c, '.?AVExposer@@', 19)}
# Exposer overrides nothing but the destructor: its other slots must equal PacketLogger's own vtable (00825724).
INHERITED = {'??_7Exposer@@6B@': (0x00825724, '.?AVPacketLogger@@', ('PacketLogger', 'PluginInterface'))}
vtables = {}
for symbol, (vobj, vt, rtti_name, count) in VTABLES.items():
    assert original.vtable_class(vt) == (rtti_name, 0), (hex(vt), original.vtable_class(vt))
    raw, sections, definitions, slots = vtable_slots(vobj, symbol)
    assert sorted(slots) == list(range(count)), (symbol, sorted(slots))
    checked = {}
    CURRENT.append(vobj)
    for slot, sym in sorted(slots.items()):
        value = d(vt + 4 * slot)
        how = classify(sym, value, raw, sections, definitions, symbol) or local_body(raw, sym, value)
        if how is None and symbol in INHERITED:
            # an inherited, not overridden slot: the same function pointer as the base class vtable (by RTTI) slot
            base_vt, base_rtti, classes = INHERITED[symbol]
            assert original.vtable_class(base_vt) == (base_rtti, 0), hex(base_vt)
            if any(('@%s@@' % c) in sym for c in classes) and d(base_vt + 4 * slot) == value:
                how = 'inherited: = %s vtable %s slot %d' % (base_rtti, hex(base_vt), slot)
        assert how is not None, ('unbound vtable slot', symbol, slot, sym, hex(value))
        prev = binding.setdefault(sym, value)
        assert prev == value, ('inconsistent', sym, hex(prev), hex(value))
        checked[slot] = '%s = %s (%s)' % (sym, hex(value), how)
    CURRENT.pop()
    vtables[symbol] = {'address': hex(vt), 'rtti': rtti_name, 'slots': checked}
# RobloxCrashReporter: its constructor is the pending-only row, so the current headers emit no vtable; the original
# vtable is checked by RTTI and its one slot is the ProcessException row.
assert original.vtable_class(0x00810320) == ('.?AVRobloxCrashReporter@@', 0) and d(0x00810320) == 0x00427b00
assert not (0x00401000 <= d(0x00810324) < 0x007fe000), 'RobloxCrashReporter vtable has more than one slot'
vtables['RobloxCrashReporter (original only)'] = {'address': '0x810320', 'rtti': '.?AVRobloxCrashReporter@@',
                                                  'slots': {0: 'ProcessException = 0x427b00 (own row)'}}

exact = sorted({r['address'] for k in ROWS for r in results[k]} - {'0042b191', '0041a4f0'})  # split bodies counted once
pending = sorted({r['address'] for k in PENDING_ROWS for r in results[k]})
paths = [Path(__file__).resolve(), ROOT / 'rebuild/2008-06/tests/native_bind.py', LAYOUT, DOC_H, CRASH_H, EH_H, DOC_CPP,
         CRASH_CPP, EH_CPP, APP_H, DONOR_CRASH_H, HDR / 'VersionInfo.h', PLAY_CPP, MODULE_CPP, MARSHALLER_CPP,
         IMAGE_CPP, EXPOSER_CPP, LAYOUT2, RAKNET_SRC / 'PacketLogger.cpp', RAKNET_SRC / 'PluginInterface.cpp',
         HDR / 'CRobloxDoc.h'] + NEW_HEADERS
receipt = {
    'family': 'AppLeaves2008 (CRbxDocTemplate, CRbxPlayDocTemplate, RobloxCrashReporter, EventHandler, CRobloxModule, '
              'Marshaller, RBXImage, Exposer)',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)', 'flags': flags(),
    'profile': 'document-swap flags; CrashReporter unit with native-headers/mfc-noinline-pcxstr first (CRobloxApp profile); '
               'PlayDocument unit preprocessed with CString operator PCXSTR and IsEmpty noinline; Exposer unit and the '
               'RakNet library providers with tools/rbxgs/Client/Network/raknet30/Source after the document-swap includes',
    'original_sha256': sha(original.path),
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {k: sha(v) for k, v in OBJ.items()},
    'layout': {
        'CRbxDocTemplate': '0x90 == sizeof(CMultiDocTemplate); 00449910 news 0x90, inline ctor stores vptr 00816684 only',
        'CRbxPlayDocTemplate': '0x98; 00449910 news 0x98: playDocument +0x90 (= 0), CString lastError +0x94 (mfc90 #316 / #601)',
        'EventHandler': '0x30 (0042c12a news 0x30): IDispatch vptr +0, boost::function0<bool> handler +8, refCount +0x28',
        'RobloxCrashReporter': '0x7d0 (00428180 news 0x7d0) == donor CrashReporter (vptr + CrashReportControls, minidumpType +0x7cc)',
        'CRobloxModule': '0x2c == sizeof(CAtlMfcModule): global 0096dbb4 up to theApp 0096dbe0; dynamic initializer 007ef7d0',
        'Marshaller': '0x54 (0041b7c5 news 0x54): CWindowImpl base to +0x24, useCount +0x24, threadId +0x28, '
                      'deque<boost::function0<void>> +0x2c, boost::mutex +0x4c',
        'RBXImage': '0x30: vptr + the CImage fields +4..+0x2c written by the constructor 00442c90 (no GDI+ count)',
        'Exposer': 'sizeof(PacketLogger): stack object of IDTOString 0049f180 (frame 0x20c), vptr 00822d3c only',
        'pendingPlayError': 'boost::scoped_ptr<std::exception> at 0096dcf4 (reset = load, store 0, delete; atexit 007fadf0)',
    },
    'methods': results, 'helpers': helpers, 'instances': INSTANCES, 'exact': exact, 'exact_count': len(exact),
    'pending_build_only': pending,
    'not_counted': {'00449460': 'MFC inline ~CWaitCursor instance (not an app-class body); prefix bytes checked only',
                    'instances': 'ATL / boost / STL / RakNet bodies proven by bytes and targets (see instances)'},
    'left': {
        'CIDEDocManager 0044abd0': 'calls through the play template (+0x24) and throwPendingPlayError; CIDEDocManager '
                                   'is not natively declared yet (CRobloxApp TU)',
        '0044bbf0': 'tail-jump [[ecx+0x58]+0x24] -> getPlayDocument; owner class (app / doc manager) not declared',
        'RenderStatsItem (CRobloxWnd::RenderStatsItem, vtable 0081a32c)': 'Stats::Item subclass; 0045f570 reads '
                                   'frame counters 0097288c/00972890/00972894 and children +0x158..+0x170 not yet derived',
        'DHTMLWindowService (vtable 0080efd4)': 'Instance service in the same TU as Marshaller; its per-thread '
                                   'Marshaller map (0096cec4, mutex 0096cee4, 0041b6f0) and descriptors not recovered',
    },
    'vtables': vtables,
    'proposals': [
        'native-headers/CRobloxApp.h: `BOOL initializeFramework(bool);` instead of `(void*)` (00449bf0 tests the '
        'argument as a byte at [esp+0x1c]; CRbxDocTemplate::CreateNewFrame 0044a170 pushes 1). Unlocks 0044a170.',
        'owner of a native Network/CrashReporter.h: inline `CrashReporter() { singleton = this; }` (00427a20 inlines '
        'it: only the store to CrashReporter::singleton 009706c0, no call). Unlocks 00427a20.',
    ],
    'scope': 'Inactive. Exact rows with verified targets; pending rows excluded from counts. No active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/app-leaves2008-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native app leaves2008: %d exact (%s), %d pending-only (%s), %d vtables checked, %d instances' % (
    len(exact), ' '.join(exact), len(pending), ' '.join(pending), len(vtables), len(INSTANCES)))
