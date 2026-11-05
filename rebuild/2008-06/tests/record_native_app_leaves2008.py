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

# ---- rows ---------------------------------------------------------------------------------------------------
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
OBJ = {'layout': layout_obj, 'doc': doc_obj, 'crash': crash_obj, 'eh': eh_obj, 'doc_pending': doc_pobj, 'crash_pending': crash_pobj}

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
}
DATA = {
    '?theApp@@3VCRobloxApp@@A': 0x0096dbe0,           # ecx of the 00449bf0 call; CRobloxApp ctor target (static init)
    '?silentCrashReport@@3_NA': 0x0096d0f4,           # "SilentCrashReport" != 0, stored by 0044c760
    '?singleton@CrashReporter@@2PAV1@A': 0x009706c0,  # CrashReporter::singleton (00427a20 stores this)
    '?_AtlBaseModule@ATL@@3VCAtlBaseModule@1@A': 0x0097f2a8,  # CAtlBaseModule ctor 007a5cd2 via static init 007f9ef6
    # ProcessException's function-local static and its guard bit (00427b00).
    '?messageShown@?1??ProcessException@RobloxCrashReporter@@UAEJPAU_EXCEPTION_POINTERS@@@Z@4_NA': 0x0096d104,
    '?$S1@?1??ProcessException@RobloxCrashReporter@@UAEJPAU_EXCEPTION_POINTERS@@@Z@4IA': 0x0096d108,
}

def first(address):
    return address[0] if isinstance(address, tuple) else address


# GUID constants (uuid.lib data in the original): verified by their 16 bytes.
GUIDS = {'_IID_IUnknown': '00000000-0000-0000-c000-000000000046', '_IID_IDispatch': '00020400-0000-0000-c000-000000000046'}

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
    return None


def verify(obj, rows, exact_flag):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    out = []
    for spec, name in rows:
        body, refs = bodies[name]
        address, lo, hi = spec if isinstance(spec, tuple) else (spec, 0, len(body))
        body, refs = body[lo:hi], [r - lo for r in refs if lo <= r < hi]
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
            if LOCAL_EH.match(symbol):
                local.add(symbol)
                continue
            how = classify(symbol, value, raw, sections, definitions, name)
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
           '??_7EventHandler@@6B@': (eh_obj, 0x00810598, '.?AVEventHandler@@', 7)}
vtables = {}
for symbol, (vobj, vt, rtti_name, count) in VTABLES.items():
    assert original.vtable_class(vt) == (rtti_name, 0), (hex(vt), original.vtable_class(vt))
    raw, sections, definitions, slots = vtable_slots(vobj, symbol)
    assert sorted(slots) == list(range(count)), (symbol, sorted(slots))
    checked = {}
    for slot, sym in sorted(slots.items()):
        value = d(vt + 4 * slot)
        how = classify(sym, value, raw, sections, definitions, symbol) or local_body(raw, sym, value)
        assert how is not None, ('unbound vtable slot', symbol, slot, sym, hex(value))
        prev = binding.setdefault(sym, value)
        assert prev == value, ('inconsistent', sym, hex(prev), hex(value))
        checked[slot] = '%s = %s (%s)' % (sym, hex(value), how)
    vtables[symbol] = {'address': hex(vt), 'rtti': rtti_name, 'slots': checked}
# RobloxCrashReporter: its constructor is the pending-only row, so the current headers emit no vtable; the original
# vtable is checked by RTTI and its one slot is the ProcessException row.
assert original.vtable_class(0x00810320) == ('.?AVRobloxCrashReporter@@', 0) and d(0x00810320) == 0x00427b00
assert not (0x00401000 <= d(0x00810324) < 0x007fe000), 'RobloxCrashReporter vtable has more than one slot'
vtables['RobloxCrashReporter (original only)'] = {'address': '0x810320', 'rtti': '.?AVRobloxCrashReporter@@',
                                                  'slots': {0: 'ProcessException = 0x427b00 (own row)'}}

exact = sorted({r['address'] for k in ROWS for r in results[k]} - {'0042b191'})  # Invoke counted once
pending = sorted({r['address'] for k in PENDING_ROWS for r in results[k]})
paths = [Path(__file__).resolve(), ROOT / 'rebuild/2008-06/tests/native_bind.py', LAYOUT, DOC_H, CRASH_H, EH_H, DOC_CPP,
         CRASH_CPP, EH_CPP, APP_H, DONOR_CRASH_H, HDR / 'VersionInfo.h']
receipt = {
    'family': 'AppLeaves2008 (CRbxDocTemplate, CRbxPlayDocTemplate, RobloxCrashReporter, EventHandler)',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)', 'flags': flags(),
    'profile': 'document-swap flags; CrashReporter unit with native-headers/mfc-noinline-pcxstr first (CRobloxApp profile)',
    'original_sha256': sha(original.path),
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {k: sha(v) for k, v in OBJ.items()},
    'layout': {
        'CRbxDocTemplate': '0x90 == sizeof(CMultiDocTemplate); 00449910 news 0x90, inline ctor stores vptr 00816684 only',
        'CRbxPlayDocTemplate': '0x98; 00449910 news 0x98: playDocument +0x90 (= 0), CString lastError +0x94 (mfc90 #316 / #601)',
        'EventHandler': '0x30 (0042c12a news 0x30): IDispatch vptr +0, boost::function0<bool> handler +8, refCount +0x28',
        'RobloxCrashReporter': '0x7d0 (00428180 news 0x7d0) == donor CrashReporter (vptr + CrashReportControls, minidumpType +0x7cc)',
    },
    'methods': results, 'helpers': helpers, 'exact': exact, 'exact_count': len(exact),
    'pending_build_only': pending,
    'not_counted': {'00449460': 'MFC inline ~CWaitCursor instance (not an app-class body); prefix bytes checked only'},
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
print('PASS native app leaves2008: %d exact (%s), %d pending-only (%s), %d vtables checked' % (
    len(exact), ' '.join(exact), len(pending), ' '.join(pending), len(vtables)))
