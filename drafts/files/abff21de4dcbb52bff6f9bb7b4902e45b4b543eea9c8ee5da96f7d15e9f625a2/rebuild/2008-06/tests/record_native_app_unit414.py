"""Record the 2008-06 application range 00414000..00418000 (inactive): unit map and the recovered RBX rows.

Step 1, unit map. The range continues three translation units and holds one whole unit; each block is anchored by
RTTI / vtable / string / import evidence that this recorder re-checks against the original binary (row list from
work/2008-06/functions.jsonl):
  * the clipboard verb unit (from 0x413490, app-unit40c-2008 map) ..0x4159df: the Creatable<Instance> instances of
    ModelInstance / Script / LocalScript / ChangeHistoryService (counted by app-unit40c-2008 and
    creatable-shared-count), the std::map<std::string, std::string> (TextXmlParser entities) and
    std::map<InstanceHandle, int> STL instances, TextXmlParser / XmlParser, ServiceProvider::find / create<Selection>
    (0x415200 / 0x4153b0), PasteVerb::isEnabled 0x4154a0 (vtable 0x80e934 slot 2), PasteVerb::doIt 0x415510 (slot 4)
    and CopyVerb::doIt 0x415800 (vtable 0x80e960 slot 4);
  * the VARIANT / SAFEARRAY conversion block 0x4159e0..0x41668f: ATL CComSafeArray / CComVariant helpers, the
    boost::any_cast instances and valueToVariant 0x416370 / makeSafeArray 0x4165e0 (names from the
    value-variant-mismatch / safearray-builder-mismatch receipts; CWorkspace::execScript calls makeSafeArray). No
    clipboard row calls into it; app-unit40c-2008 maps it with the clipboard unit, so the split is a block, not a
    proven unit boundary;
  * the CContent COM unit 0x416690..0x416e5f: CContent::Upload 0x4166a0 (vtable 0x80ea98 slot 7) and the ATL
    CComObject / CComAggObject / CComContainedObject<CContent> instances (vtables 0x80eabc / 0x80ea98 / 0x80eb4c /
    0x80eb38 / 0x80eb14);
  * the DHTMLWindowService / DHTMLWindow unit from 0x416e60 (askAddChild, vtable 0x80efd4 slot 2), continuing past
    the range: BoundFuncDesc<DHTMLWindow, ...>::declareSignature, Name::doDeclare<sDHTMLWindowService> ("HtmlService"),
    the boost::bind storage templates over shared_ptr<DHTMLWindow> (0x4173b0..0x417ff0), the DHTMLWindow worker bodies
    0x417a10..0x417d10 (pending in app-leaves2008-dhtml) and the CLuaFunction ATL / Lua FunctionRef helpers it
    instantiates. app-unit40c-2008 starts a separate CLuaFunction unit at 0x417360; the DHTMLWindow-only rows up to
    0x417ff0 place them in one unit here.
Rows other receipts count are found with the top-level exact_function_rows rule (receipts without that key: their
exact_addresses / exact_unique_addresses lists, else every dict with an address marked exact) and written as
'ADDR counted by RECEIPT' text; every other address of a row not counted here is written 0x-prefixed
(local_backpack / viewnew_brick_build / viewnew_part_mesh read any quoted bare address as counted).

Step 2, recovery (no new header, no pending build):
  * native-classes/AppUnit414ContentAtl.cpp (new) explicitly instantiates the ATL templates over CContent against
    the committed native-headers/CContent.h (read-only);
  * the committed native-classes/ClipboardActions.cpp is compiled unchanged (its own native-flags profile:
    native-headers/std-noinline-string first) for PasteVerb::doIt, CopyVerb::doIt and the TextXmlParser / XmlParser
    bodies it emits;
  * the committed native-classes/AppLeaves2008DHTMLWindow.cpp (profile of record_native_app_leaves2008_dhtml.py:
    std-noinline-string and boost-function-pod-vtable first) and AppLeaves2008DHTMLWindowService.cpp (plain
    document-swap flags, as record_native_app_leaves2008_services.py) are compiled unchanged for the DHTMLWindow-only
    template rows, which their own receipts prove only as uncounted instances.
A row counts only if its bytes match exactly and every relocation is bound to the address the original instruction
uses and verified: imports by DLL name / ordinal, literals by bytes, RTTI and vtables by original RTTI names, GUIDs by
the 16 bytes the committed CContentGuids.cpp / WorkspaceGuids.cpp define (or the Windows SDK value), own symbols by the
row proven here, the explicit EXTERNAL map (each entry cites the receipt or evidence that binds it), evidence names,
and any other body or data this build emits by bytes at the referenced address with its own targets verified the
same way (recursively; listed under 'instances', not counted). Catch funclets are separate function-list rows and are
compared as their own piece of the emitted body. The CContent vtables are compared slot by slot from the object
built from the current headers. Writes work/2008-06/shared-layouts/app-unit414-working.json.
"""
import glob
import json
import os
import struct
import sys
import uuid
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import native_bind as nb  # noqa: E402
from native_bind import ROOT, OUT, LOCAL_EH, Original, flags, match, rebuild, sha  # noqa: E402

HDR = ROOT / 'rebuild/2008-06/native-headers'
SRC = ROOT / 'rebuild/2008-06/native-classes'
CONTENT_CPP = SRC / 'AppUnit414ContentAtl.cpp'
CLIPBOARD_CPP = SRC / 'ClipboardActions.cpp'
WINDOW_CPP = SRC / 'AppLeaves2008DHTMLWindow.cpp'
SERVICE_CPP = SRC / 'AppLeaves2008DHTMLWindowService.cpp'
GUID_CPPS = [SRC / 'CContentGuids.cpp', SRC / 'WorkspaceGuids.cpp']
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit414-working.json'
LO, HI = 0x414000, 0x418000
CLIP_HI, VARIANT_HI, CONTENT_HI = 0x4159e0, 0x416690, 0x416e60
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


def build(source, name, profile=()):
    OUT.mkdir(parents=True, exist_ok=True)
    obj = OUT / (name + '.obj')
    base = flags()
    i = next(k for k, x in enumerate(base) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    args = base[:i] + ['/I' + str(HDR / p) for p in profile] + base[i:] + ['/Fo' + str(obj), str(source)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', args, OUT)
    assert code == 0, log[-4000:]
    FLAGS[name] = args
    return obj


OBJ = {
    'content': build(CONTENT_CPP, 'NativeAppUnit414ContentAtl'),
    'clipboard': build(CLIPBOARD_CPP, 'NativeAppUnit414ClipboardActions', ['std-noinline-string']),
    'window': build(WINDOW_CPP, 'NativeAppUnit414DHTMLWindow', ['std-noinline-string', 'boost-function-pod-vtable']),
    'service': build(SERVICE_CPP, 'NativeAppUnit414DHTMLWindowService'),
}
GUID_OBJS = [build(p, 'NativeAppUnit414' + p.stem) for p in GUID_CPPS]

# ---- GUIDs: bytes defined by the committed GUID units, or Windows SDK interface IDs -----------------------------------
GUIDS = {}
for obj in GUID_OBJS:
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    for sym, (pos, sec) in definitions.items():
        if sym.endswith('@@3U_GUID@@B'):
            GUIDS[sym] = (raw[sections[sec][4] + pos:sections[sec][4] + pos + 16], Path(obj).stem)
for sym, text in [('_IID_IDispatch', '00020400-0000-0000-c000-000000000046'),
                  ('_IID_IUnknown', '00000000-0000-0000-c000-000000000046'),
                  ('_IID_ISupportErrorInfo', 'df0b3d60-548f-101b-8e65-08002b2bd119')]:
    GUIDS[sym] = (uuid.UUID(text).bytes_le, 'Windows SDK uuid.lib')

# ---- rows counted here ----------------------------------------------------------------------------------------------
C = 'VCContent@@'
OBJ_C = '?$CComObject@' + C + '@ATL@@'
AGG_C = '?$CComAggObject@' + C + '@ATL@@'
CON_C = '?$CComContainedObject@' + C + '@ATL@@'
DISP = ('?$IDispatchImpl@UIContent@@$1?IID_IContent@@3U_GUID@@B$1?LIBID_RobloxLib@@3U3@B$00$0A@'
        'VCComTypeInfoHolder@ATL@@@ATL@@')
CREATE_OBJ = '?CreateInstance@?$CComCreator@V' + OBJ_C + '@ATL@@SGJPAXABU_GUID@@PAPAX@Z'
CREATE_AGG = '?CreateInstance@?$CComCreator@V' + AGG_C + '@ATL@@SGJPAXABU_GUID@@PAPAX@Z'
CONTENT_ROWS = [
    (0x00416880, '?InterfaceSupportsErrorInfo@?$ISupportErrorInfoImpl@$1?IID_IContent@@3U_GUID@@B@ATL@@UAGJABU_GUID@@@Z'),
    (0x004168d0, '?Release@' + OBJ_C + 'UAGKXZ'),
    (0x00416930, '?Release@' + OBJ_C + 'W3AGKXZ'),
    (0x00416940, '?AddRef@' + OBJ_C + 'W3AGKXZ'),
    (0x004169a0, '?AddRef@' + CON_C + 'W3AGKXZ'),
    (0x004169b0, '?QueryInterface@' + CON_C + 'W3AGJABU_GUID@@PAPAX@Z'),
    (0x004169c0, '?Release@' + CON_C + 'W3AGKXZ'),
    (0x004169d0, '?GetTypeInfo@' + DISP + 'UAGJIKPAPAUITypeInfo@@@Z'),
    (0x00416a30, '?GetIDsOfNames@' + DISP + 'UAGJABU_GUID@@PAPA_WIKPAJ@Z'),
    (0x00416a60, '?Invoke@' + DISP + 'UAGJJABU_GUID@@KGPAUtagDISPPARAMS@@PAUtagVARIANT@@PAUtagEXCEPINFO@@PAI@Z'),
    ((0x00416ac0, 0, 0xc9), CREATE_OBJ),
    ((0x00416b89, 0xc9, 0xef), CREATE_OBJ),
    (0x00416bb0, '??0' + AGG_C + 'QAE@PAX@Z'),
    (0x00416c30, '?QueryInterface@' + AGG_C + 'UAGJABU_GUID@@PAPAX@Z'),
    (0x00416ca0, '??1' + AGG_C + 'UAE@XZ'),
    (0x00416d00, '??_G' + AGG_C + 'UAEPAXI@Z'),
    ((0x00416d20, 0, 0x9e), CREATE_AGG),
    ((0x00416dbe, 0x9e, 0xc4), CREATE_AGG),
    (0x00416df0, '?CreateInstance@?$CComCreator2@V?$CComCreator@V' + OBJ_C + '@ATL@@V?$CComCreator@V' + AGG_C +
     '@2@@ATL@@SGJPAXABU_GUID@@PAPAX@Z'),
]
CLIPBOARD_ROWS = [
    (0x00415510, '?doIt@PasteVerb@@UAEXPAVIDataState@RBX@@@Z'),
    (0x00415800, '?doIt@CopyVerb@@UAEXPAVIDataState@RBX@@@Z'),
    (0x00415350, '??0TextXmlParser@@QAE@PAV?$basic_streambuf@DU?$char_traits@D@std@@@std@@@Z'),
    (0x004147c0, '??1TextXmlParser@@QAE@XZ'),
    (0x00414470, '??1XmlParser@@QAE@XZ'),
]
W = 'V?$value@V?$shared_ptr@VDHTMLWindow@@@boost@@@_bi@boost@@'
FR = 'V?$value@VFunctionRef@Lua@RBX@@@23@'
STR = 'V?$value@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@23@'
WINDOW_ROWS = [
    (0x00416eb0, '?declareSignature@?$BoundFuncDesc@VDHTMLWindow@@$$A6AXHH@Z$01@Reflection@RBX@@AAEXPBD0@Z'),
    (0x00416f10, '?declareSignature@?$BoundFuncDesc@VDHTMLWindow@@$$A6AXV?$shared_ptr@VInstance@RBX@@@boost@@V?$basic_'
                 'string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@1@Z$02@Reflection@RBX@@AAEXPBD00@Z'),
    (0x004173b0, '??1?$storage2@' + W + FR + '@_bi@boost@@QAE@XZ'),
    (0x004175f0, '??0?$storage2@' + W + FR + '@_bi@boost@@QAE@ABU012@@Z'),
    (0x00417660, '??0?$storage2@' + W + STR + '@_bi@boost@@QAE@ABU012@@Z'),
    (0x004176d0, '??0?$storage2@' + W + FR + '@_bi@boost@@QAE@V?$value@V?$shared_ptr@VDHTMLWindow@@@boost@@@12@V?$va'
                 'lue@VFunctionRef@Lua@RBX@@@12@@Z'),
    (0x004177a0, '??0?$storage2@' + W + 'V?$value@H@23@@_bi@boost@@QAE@V?$value@V?$shared_ptr@VDHTMLWindow@@@boost@@'
                 '@12@V?$value@H@12@@Z'),
    (0x00417ff0, '??0?$list2@' + W + FR + '@_bi@boost@@QAE@V?$value@V?$shared_ptr@VDHTMLWindow@@@boost@@@12@V?$value@'
                 'VFunctionRef@Lua@RBX@@@12@@Z'),
]
SERVICE_ROWS = [
    (0x00416f90, '??$doDeclare@$1?sDHTMLWindowService@@3PADA@Name@RBX@@CAABV01@XZ'),
    (0x00417290, '??$callDoDeclare@$1?sDHTMLWindowService@@3PADA@Name@RBX@@CAXXZ'),
]
BUILDS = [('content', CONTENT_ROWS), ('clipboard', CLIPBOARD_ROWS), ('window', WINDOW_ROWS), ('service', SERVICE_ROWS)]


def first(spec):
    return spec[0] if isinstance(spec, tuple) else spec


EXTERNAL = {
    # CRT and ATL / MFC helpers (record_native_adorn.py, record_native_content_factory.py and the content-factory-trial
    # receipt bind these; AtlThrowImpl / AtlInternalQueryInterface by evidence name or emitted body below).
    '??2@YAPAXI@Z': (0x006a0920, 'operator new (record_native_guid_critical_section.py binding)'),
    '??3@YAXPAX@Z': (0x006a067a, 'operator delete (record_native_guid_critical_section.py binding)'),
    '__CxxThrowException@8': (0x006a158c, 'CRT throw (record_native_app_unit428.py binding)'),
    '__alloca_probe_16': (0x006a1560, 'CRT (record_native_app_unit49c_2008.py binding)'),
    '??_M@YGXPAXIHP6EX0@Z@Z': (0x006a165b, 'CRT eh vector destructor iterator (record_native_replicator.py binding)'),
    '??_L@YGXPAXIHP6EX0@Z1@Z': (0x006a1598, 'CRT eh vector constructor iterator (record_native_replicator.py binding)'),
    '?_pAtlModule@ATL@@3PAVCAtlModule@1@A': (0x0096c268, 'content-factory-trial CreateInstance binding'),
    '?Delete@CException@@QAEXXZ': (0x006a0950, 'content-factory-trial CreateInstance catch binding'),
    # ATL selectany statics declared next to each other in atlbase.h: _pAtlModule (0x96c268, content-factory-trial)
    # and CAtlModule::m_libid, which CComTypeInfoHolder::GetTI 0x404a80 reads 4 bytes after it (zero-initialized,
    # asserted to lie in a writable section below).
    '?m_libid@CAtlModule@ATL@@2U_GUID@@A': (0x0096c26c, '_pAtlModule + 4 (atlbase.h selectany pair)'),
    # atls.lib globals (record_native_app_leaves2008.py bindings: CAtlBaseModule / CAtlWinModule static initializers).
    '?_AtlBaseModule@ATL@@3VCAtlBaseModule@1@A': (0x0097f2a8, 'record_native_app_leaves2008.py binding'),
    '?_AtlWinModule@ATL@@3VCAtlWinModule@1@A': (0x0097f314, 'record_native_app_leaves2008.py binding'),
    '?m_bInitFailed@CAtlBaseModule@ATL@@2_NA': (0x0096dcf8, 'record_native_app_leaves2008.py binding'),
    # CContent::Upload, counted by content-upload-trial (vtable 0x80ea98 slot 7 = 0x4166a0 is asserted below).
    '?Upload@CContent@@UAGJPA_W@Z': (0x004166a0, 'content-upload-trial row'),
    # Callees of PasteVerb::doIt / CopyVerb::doIt, each bound by the cited receipt.
    '?collectSelection@@YAXPAVXmlElement@@V?$shared_ptr@VInstance@RBX@@@boost@@@Z':
        (0x0057e140, 'row counted by workspace-selection-serializer-trial'),
    '?newRootElement@SerializerV2@@SAPAVXmlElement@@XZ': (0x00591a30, 'app-unit568 identity binding'),
    '?front@Selection@RBX@@QBE?AV?$shared_ptr@VInstance@RBX@@@boost@@XZ':
        (0x00413c20, 'document-initialize-trial / join-command-trial binding'),
    '?insertInstances@RootInstance@RBX@@QAEXABV?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_p'
    'tr@VInstance@RBX@@@boost@@@std@@@std@@PAVInstance@2@W4InsertMode@2@W4PromptMode@2@@Z':
        (0x005911d0, 'app-unit5a0-2008 external binding'),
    '?loadInstances@SerializerV2@@QAEXPAVXmlElement@@AAV?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V'
    '?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@@Z': (0x00593250, 'app-unit5a0-2008 external binding'),
    '?recordCameraHistory@RBX@@YAXPBDPBVInstance@1@@Z': (0x0058c5c0, 'app-unit660-2008 external binding'),
    # ServiceProvider::create<Selection>: called by both verb bodies; not emitted (core header owner). Its body calls
    # find<Selection> 0x415200, which calls doGetClassIndex<Selection> 0x413810 (asserted below; service-selection
    # receipt and record_native_settings_dialog.py bind the same address).
    '??$create@VSelection@RBX@@@ServiceProvider@RBX@@QBEPAVSelection@1@XZ':
        (0x004153b0, 'record_native_settings_dialog.py binding; calls find<Selection> 0x415200 (asserted)'),
}
own = {}
for _, specs in BUILDS:
    for spec, sym in specs:
        own.setdefault(sym, first(spec))
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
    if symbol in GUIDS:
        data, source = GUIDS[symbol]
        assert original.data(value, 16) == data, (where, symbol, hex(value))
        return 'GUID bytes (%s)' % source
    if symbol in own:
        assert own[symbol] == value, (where, symbol, hex(value), hex(own[symbol]))
        return 'own row'
    if ('?1??' in symbol or symbol.startswith('??_B?1??')) and DATA_LO <= value < DATA_HI:
        # Function-local static (or its guard) of an inline function this build emits: bound by consistency (the
        # same address at every use, enforced by `binding`) and listed under 'local_statics'.
        LOCAL_STATICS.setdefault(symbol, set()).add(where)
        return 'own static (bound by consistency)'
    if symbol in EXTERNAL:
        assert EXTERNAL[symbol][0] == value, (where, symbol, hex(value), hex(EXTERNAL[symbol][0]))
        return 'external (%s)' % EXTERNAL[symbol][1]
    if EVIDENCE.get('%08x' % value, {}).get('symbol') == symbol:
        return 'evidence name'
    return instance(symbol, value, where)


LOCAL_STATICS = {}
DATA_LO, DATA_HI = 0x928000, 0x97f710   # writable .data (incl. uninitialized tail) of the 2008-06 image
CURRENT = []
INSTANCES = {}
BODIES = {}


def bodies_of(obj):
    if obj not in BODIES:
        BODIES[obj] = {n: (b, r) for n, b, r in match.coff_functions(Path(obj).read_bytes())}
    return BODIES[obj]


def instance(symbol, value, where):
    """An inline body this build emits, proven by bytes at the called address and by its own targets."""
    if symbol in INSTANCES:
        assert INSTANCES[symbol]['address'] == '%08x' % value, (where, symbol, hex(value))
        return 'instance (bytes equal, targets verified)'
    obj = CURRENT[-1]
    if symbol not in bodies_of(obj):
        return data_instance(symbol, value, where)
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


def data_instance(symbol, value, where):
    """Initialized data this build defines (COM interface map, type-info holder, Name statics): bytes equal at the
    referenced address with relocated fields masked, and every relocated field bound like a code target."""
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
        assert name in bodies, ('not emitted', name)
        body, refs = bodies[name]
        address, lo, hi = spec[:3] if isinstance(spec, tuple) else (spec, 0, len(body))
        body, refs = body[lo:hi], [r - lo for r in refs if lo <= r < hi]
        if isinstance(spec, tuple) and spec[3:] == ('raw',):
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
            assert how is not None, ('unbound relocation', name, symbol, hex(value))
            prev = binding.setdefault(symbol, value)
            assert prev == value, ('inconsistent binding', symbol, hex(prev), hex(value))
            verified[symbol] = '%s (%s)' % (hex(value), how)
        piece = '' if (lo, hi) == (0, len(bodies[name][0])) else ' [%#x:%#x]' % (lo, hi)
        out.append({'address': '%08x' % address, 'symbol': name + piece, 'size': len(body), 'exact': exact_flag,
                    'verified_targets': verified, 'local_eh': sorted(local)})
    return out


def refs_of_target(a):
    code, rel, _ = match.target('2008-06', '%08x' % a)
    return {struct.unpack_from('<I', code, i)[0] for i in rel if i + 4 <= len(code)}


# Structural checks behind the EXTERNAL bindings.
assert d(0x80ea98 + 7 * 4) == 0x4166a0 and original.vtable_class(0x80ea98)[0] == '.?AV?$CComObject@VCContent@@@ATL@@'
_create, _, _ = match.target('2008-06', '004153b0')
_find, _, _ = match.target('2008-06', '00415200')


def calls(code, base):
    return {(base + i + 5 + struct.unpack_from('<i', code, i + 1)[0]) & 0xffffffff
            for i in range(len(code) - 4) if code[i] == 0xe8}


assert 0x415200 in calls(_create, 0x4153b0) and 0x413810 in calls(_find, 0x415200)

results = []
for key, specs in BUILDS:
    got = verify(OBJ[key], specs, True)
    for r in got:
        r['build'] = key
        assert r['size'] == FUNCS[int(r['address'], 16)]['size'], (r['address'], r['size'])
    results += got


# ---- vtables (objects from the current headers) ----------------------------------------------------------------------
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


SEI = '?$ISupportErrorInfoImpl@$1?IID_IContent@@3U_GUID@@B@1@@'
VTABLES = {
    '??_7' + OBJ_C + '6B' + SEI: (0x0080eabc, '.?AV?$CComObject@VCContent@@@ATL@@', 0, 5),
    '??_7' + OBJ_C + '6B?$IDispatchImpl@UIContent@@$1?IID_IContent@@3U_GUID@@B$1?LIBID_RobloxLib@@3U3@B$00$0A@'
    'VCComTypeInfoHolder@ATL@@@1@@': (0x0080ea98, '.?AV?$CComObject@VCContent@@@ATL@@', 4, 8),
    '??_7' + AGG_C + '6B@': (0x0080eb4c, '.?AV?$CComAggObject@VCContent@@@ATL@@', 0, 4),
    '??_7' + CON_C + '6B' + SEI: (0x0080eb38, '.?AV?$CComContainedObject@VCContent@@@ATL@@', 0, 4),
    '??_7' + CON_C + '6B?$IDispatchImpl@UIContent@@$1?IID_IContent@@3U_GUID@@B$1?LIBID_RobloxLib@@3U3@B$00$0A@'
    'VCComTypeInfoHolder@ATL@@@1@@': (0x0080eb14, '.?AV?$CComContainedObject@VCContent@@@ATL@@', 4, 8),
}
vtables = {}
for symbol, (vt, rtti_name, offset, count) in VTABLES.items():
    assert original.vtable_class(vt) == (rtti_name, offset), (hex(vt), original.vtable_class(vt))
    raw, sections, definitions, slots = vtable_slots(OBJ['content'], symbol)
    assert sorted(slots) == list(range(count)), (symbol, sorted(slots))
    checked = {}
    CURRENT.append(OBJ['content'])
    for slot, sym in sorted(slots.items()):
        value = d(vt + 4 * slot)
        how = classify(sym, value, raw, sections, definitions, symbol)
        if how is None and sym.startswith('??_E') and ('??_G' + sym[4:]) in bodies_of(OBJ['content']):
            how = classify('??_G' + sym[4:], value, raw, sections, definitions, symbol)
            how = how and how + ' via ??_G'
        assert how is not None, ('unbound vtable slot', symbol, slot, sym, hex(value))
        prev = binding.setdefault(sym, value)
        assert prev == value, ('inconsistent', sym, hex(prev), hex(value))
        checked[slot] = '%s = %s (%s)' % (sym, hex(value), how)
    CURRENT.pop()
    vtables[symbol] = {'address': hex(vt), 'rtti': rtti_name, 'offset': offset, 'slots': checked}

exact = sorted({r['address'] for r in results})
# The local statics are bound by consistency; the clipboard-format pair must also be what PasteVerb::isEnabled 0x4154a0
# (the third getClipboardFormat call site, compiled in DocumentInitialize.cpp) reads.
assert DATA_LO <= EXTERNAL['?m_libid@CAtlModule@ATL@@2U_GUID@@A'][0] < DATA_HI
_enabled_refs = refs_of_target(0x4154a0)
for sym in LOCAL_STATICS:
    if 'getClipboardFormat' in sym:
        assert binding[sym] in _enabled_refs, (sym, hex(binding[sym]))
exact_ints = {int(a, 16) for a in exact}


# ---- step 1: what other receipts count (top-level exact_function_rows rule) ------------------------------------------
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
        # Receipts without a counted list: every row they mark exact (the conservative reading app-unit40c-2008 uses,
        # e.g. safearray-builder-mismatch's accessor 0x415b00).
        got = []
        walk_exact(doc, got)
    if isinstance(got, dict):
        got = list(got)
    for x in got:
        v = addr_of(x)
        if v is not None and LO <= v < HI:
            counted_elsewhere.setdefault(v, set()).add(os.path.basename(f)[:-5])
double = sorted(exact_ints & set(counted_elsewhere))
assert not double, ('counted elsewhere too', [H(a) for a in double])


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


# Unit / block anchors.
assert original.vtable_class(0x80e960)[0] == '.?AVCopyVerb@@' and d(0x80e960 + 16) == 0x415800
assert original.vtable_class(0x80e934)[0] == '.?AVPasteVerb@@' and d(0x80e934 + 16) == 0x415510
assert d(0x80e934 + 8) == 0x4154a0
assert 'NetworkClient' in evidence_of(0x415510).get('strings', [])
assert 'Roblox' in evidence_of(0x4154a0).get('strings', [])
assert any('SafeArrayGetVartype' in i for i in evidence_of(0x4159e0).get('imports', []))
assert 0x4165e0 in calls(match.target('2008-06', '00416370')[0], 0x416370)
assert any('Untrusted Url' in s for s in evidence_of(0x4166a0).get('strings', []))
assert original.vtable_class(0x80eabc)[0] == '.?AV?$CComObject@VCContent@@@ATL@@'
assert original.vtable_class(0x80eb4c)[0] == '.?AV?$CComAggObject@VCContent@@@ATL@@'
assert original.vtable_class(0x80efd4)[0] == '.?AVDHTMLWindowService@@' and d(0x80efd4 + 8) == 0x416e60
assert 'HtmlService' in evidence_of(0x416f90).get('strings', [])
assert original.vtable_class(0x80ec00)[0] == '.?AV?$CComObject@VCLuaFunction@@@ATL@@'
for a, b in zip(rows, rows[1:]):
    assert a + FUNCS[a]['size'] <= b, hex(a)

NOTES = {
    # clipboard verb unit
    0x414070: 'std::map<std::string, std::string> erase(iterator) (TextXmlParser entities map; STL library instance)',
    0x414370: 'std::map<InstanceHandle, int>::_Erase (evidence name; STL instance shared with five other units)',
    0x4143e0: 'std::map<std::string, std::string>::_Erase (STL library instance)',
    0x414490: 'std::_Tree constructor (evidence name set<ContentId>; ICF-folded with map<string, string>, see '
              'ogre-scene-manager); STL library instance',
    0x414510: 'std::map<InstanceHandle, int>::erase(range) (evidence name); STL instance shared with other units',
    0x4145f0: 'std::map<std::string, std::string>::erase(range) (STL library instance)',
    0x4146d0: 'std::map<InstanceHandle, int> destructor (evidence name), called by five other units; STL instance',
    0x414740: 'std::map<std::string, std::string> destructor (STL library instance; called by ~TextXmlParser)',
    0x415200: 'ServiceProvider::find<Selection> (service-selection receipt; needs a find<> body in the core '
              'v8tree/Service.h, owner proposal)',
    0x4153b0: 'ServiceProvider::create<Selection> (needs a create<> body in the core v8tree/Service.h; bound here as a '
              'call target only)',
    0x4154a0: 'PasteVerb::isEnabled (vtable 0x80e934 slot 2; body in the committed DocumentInitialize.cpp, document '
              'owner)',
    # VARIANT / SAFEARRAY block
    0x4159e0: 'ATL CComSafeArray helper (SafeArrayGetVartype; ATL library instance)',
    0x415a20: 'ATL CComSafeArray copy (SafeArrayCopy; ATL library instance)',
    0x415aa0: 'ATL CComVariant copy (VariantClear / memcpy_s; ATL library instance)',
    0x415ae0: 'std::string copy wrapper (import only), called by other units; library instance',
    0x415b90: 'type_info compare helper (57 B), shared reflection / boost instance called from 0x56d410',
    0x415bd0: 'type_info compare helper (57 B), shared reflection / boost instance called from 0x56d530',
    0x415c10: 'type_info compare helper (57 B), shared reflection / boost instance called from 0x56d650',
    0x415c50: 'type_info compare helper (57 B), shared reflection / boost instance called from 0x56d770',
    0x415c90: 'type_info compare helper (57 B), shared by eight Value conversion bodies',
    0x415cd0: 'type_info compare helper (57 B), shared reflection / boost instance called from 0x56de80',
    0x415d10: 'Value::isType-shaped type_info compare (18 B), shared with 0x5aba50',
    0x415d30: 'Value::isType-shaped type_info compare (18 B), shared with 0x5aba50',
    0x415d50: 'Value::isType-shaped type_info compare (18 B), shared with 0x5aba50',
    0x415ea0: 'ATL CComSafeArray destroy (SafeArrayUnlock / SafeArrayDestroy; ATL library instance)',
    0x415ed0: 'boost::any_cast<int> (lua-bridge2008 instance); boost library instance shared with other units',
    0x415f60: 'boost::any_cast<bool> (evidence name); boost library instance shared with other units',
    0x415ff0: 'boost::any_cast<float> (evidence name); boost library instance shared with other units',
    0x416080: 'boost::any_cast<double> (evidence name); boost library instance shared with other units',
    0x416110: 'boost::any_cast<std::string> (evidence name); boost library instance shared with other units',
    0x4161b0: 'boost::any_cast of a string-holding type (ContentId-shaped copy); boost instance',
    0x416260: 'boost::any_cast instance (shared with 0x5aba50 / 0x5ad380)',
    0x4162f0: 'Value accessor wrapper used by valueToVariant (calls 0x415d70)',
    0x416310: 'Value::cast<std::string> wrapper used by valueToVariant (calls any_cast<std::string>)',
    0x416340: 'Value cast wrapper used by valueToVariant (calls 0x4161b0)',
    0x416370: 'valueToVariant (value-variant-mismatch: committed ValueConverter.cpp is 635 vs 615 B; owner)',
    0x4165e0: 'makeSafeArray (safearray-builder-mismatch: committed SafeArray.cpp is 189 vs 168 B; owner)',
    # CContent unit
    0x41682a: 'catch funclet of CContent::Upload 0x4166a0 (content-upload owner; its recorder preprocesses a profile)',
    0x416870: 'what()-shaped 9 B body ICF-folded with std::logic_error::what (library)',
    0x416e40: 'ATL "ATL:%p" window-class name formatter (sprintf_s), called from 0x418ab0; ATL library',
    # DHTMLWindow unit
    0x416ea0: '5 B jmp shared (ICF) by empty destructors / classDescriptor thunks; symbol not derivable',
    0x417000: 'boost::any::holder<std::string> constructor (evidence name); boost library instance shared widely',
    0x417050: '6 B max_size-shaped body (ICF-folded STL leaf); library',
    0x417060: 'boost::any::holder<std::string>::clone (evidence name); boost library instance',
    0x4170c0: 'ATL CStdCallThunk flush (FlushInstructionCache); ATL library',
    0x417120: 'Lua FunctionRef holder destructor (calls ~FunctionRef 0x594470), reached from CComObject<CLuaFunction> '
              '0x417ea0; CLuaFunction is not natively declared',
    0x4171a0: '5 B jmp to 0x417120 (ICF-shared destructor thunk); symbol not derivable',
    0x4171b0: 'std::_Construct<SignatureDescriptor::Item> (evidence name; mouse receipt proves it, not counted); '
              'STL instance shared by many reflection units',
    0x417230: 'boost::any(const std::string&) (evidence name); boost library instance shared by eight units',
    0x4172a0: 'XmlNameValuePair(const Name&, InstanceHandle) (evidence name; XmlElement / XmlNameValuePair family is '
              'leased by another contributor)',
    0x417360: 'Lua ThreadRef / FunctionRef vtable writer (73 B, called from 0x5947f0); Lua bridge owner',
    0x417430: 'ATL CSimpleArray::Add (_recalloc); ATL library',
    0x4174b0: 'MemberDescriptorContainer<PropertyDescriptor>::Iterator::operator* (evidence name; the native inline '
              'compiles to 89 B, TANDEM 2026-11-07 reflection proposal)',
    0x4174f0: 'boost scoped_lock<recursive_mutex> destructor; boost library',
    0x417510: 'XmlElement::XmlElement<InstanceHandle> (evidence name; XmlElement family leased by another contributor)',
    0x417850: 'type_info compare (79 B) functor-manager-shaped body; boost instance',
    0x4178a0: '12 B leaf (no calls); symbol not derivable',
    0x4178b0: 'ATL critical-section lock with RaiseException; ATL library',
    0x417920: 'ATL critical-section helper (EnterCriticalSection / GetCurrentThreadId); ATL library',
    0x4179b0: 'Lua ThreadRef / FunctionRef vtable writer (85 B, called from 0x4186d0 / 0x418800); Lua bridge owner',
    0x417a10: 'DHTMLWindow worker (pending-build-only in app-leaves2008-dhtml: needs a CLuaHtmlView declaration)',
    0x417aa0: 'DHTMLWindow worker (pending-build-only in app-leaves2008-dhtml)',
    0x417b30: '5 B jmp to the storage2<DHTMLWindow, FunctionRef> destructor 0x4173b0 (ICF-shared bind_t / list2 '
              'destructor); symbol not derivable',
    0x417b40: 'DHTMLWindow doSetCallback (not exact in app-leaves2008-dhtml: CLuaHtmlView +0xfc not derived)',
    0x417bd0: 'DHTMLWindow worker (pending-build-only in app-leaves2008-dhtml)',
    0x417c70: 'DHTMLWindow worker (pending-build-only in app-leaves2008-dhtml)',
    0x417d00: '5 B jmp to the SelectionChanged-signal storage destructor 0x422c60 (ICF-shared); symbol not derivable',
    0x417d10: 'DHTMLWindow worker (pending-build-only in app-leaves2008-dhtml)',
    0x417e10: 'CRT call wrapper (0x7a600b); library',
    0x417e20: 'ISupportErrorInfoImpl::InterfaceSupportsErrorInfo of CLuaFunction (78 B); no native CLuaFunction '
              'declaration',
    0x417e70: 'CComObject AddRef body (13 B) ICF-shared by the CContent and CLuaFunction objects (bound here as the '
              'target of the CContent adjustor thunk 0x416940; not counted)',
    0x417e80: 'CComObject<CLuaFunction>::QueryInterface (AtlInternalQueryInterface); no native CLuaFunction',
    0x417ea0: 'CComObject<CLuaFunction> scalar deleting destructor (RTTI vtables 0x80ec00 / 0x80ebd8)',
    0x417ef0: 'CComObject<CLuaFunction> QueryInterface adjustor thunk',
    0x417f00: 'std::list<SignatureDescriptor::Item>::_Buynode (evidence name; mouse receipt proves it, not counted); '
              'STL instance shared by many reflection units',
    0x417f71: 'catch funclet of _Buynode 0x417f00 (STL instance)',
    0x417f90: 'CComContainedObject AddRef body ICF-shared by the CContent and CLuaFunction objects (bound as the '
              'target of 0x4169a0; not counted)',
    0x417fb0: 'CComContainedObject Release body ICF-shared (bound as the target of 0x4169c0; not counted)',
    0x417fd0: 'CComContainedObject QueryInterface body ICF-shared (bound as the target of 0x4169b0; not counted)',
}


def block_of(a):
    if a < CLIP_HI:
        return 'clipboard verb unit (from 0x413490) ..0x4159df'
    if a < VARIANT_HI:
        return 'VARIANT / SAFEARRAY conversion block 0x4159e0..0x41668f'
    if a < CONTENT_HI:
        return 'CContent COM unit 0x416690..0x416e5f'
    return 'DHTMLWindowService / DHTMLWindow unit 0x416e60.. (continues past the range)'


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
        assert a in NOTES, ('unclassified', hex(a))
        entry['kind'] = 'open'
        entry['note'] = NOTES[a]
    entry['evidence'] = evidence_of(a)
    unit_rows.append(entry)
assert sum(1 for e in unit_rows if e['kind'] == 'counted here') == len(exact)
stale = sorted(a for a in NOTES if a in exact_ints or a in counted_elsewhere or a not in FUNCS)
assert not stale, [H(a) for a in stale]

per_block = {}
for e in unit_rows:
    b = per_block.setdefault(e['unit'], {'rows': 0, 'counted_here': 0, 'counted_elsewhere': 0, 'open': 0})
    b['rows'] += 1
    b[{'counted here': 'counted_here', 'counted elsewhere': 'counted_elsewhere', 'open': 'open'}[e['kind']]] += 1

paths = [Path(__file__).resolve(), ROOT / 'rebuild/2008-06/tests/native_bind.py', CONTENT_CPP, CLIPBOARD_CPP,
         WINDOW_CPP, SERVICE_CPP] + GUID_CPPS + [
         HDR / 'CContent.h', HDR / 'RobloxLib.h', HDR / 'ClipboardVerbs.h', HDR / 'v8xml/XmlSerializer.h',
         HDR / 'AppLeaves2008/DHTMLWindow2008.h', HDR / 'AppLeaves2008/DHTMLWindowService2008.h',
         HDR / 'std-noinline-string/xstring', HDR / 'boost-function-pod-vtable/boost/function/function_template.hpp']
n_counted_elsewhere = sum(1 for e in unit_rows if e['kind'] == 'counted elsewhere')
receipt = {
    'family': 'app unit 00414000 (clipboard verb unit tail, VARIANT / SAFEARRAY block, CContent COM unit, '
              'DHTMLWindowService / DHTMLWindow unit head)',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': FLAGS,
    'profile': 'document-swap flags; ClipboardActions.cpp with native-headers/std-noinline-string first (its pinned '
               'native-flags); AppLeaves2008DHTMLWindow.cpp with std-noinline-string and boost-function-pod-vtable '
               'first (as record_native_app_leaves2008_dhtml.py); the rest plain (as record_native_content_factory.py '
               '/ record_native_app_leaves2008_services.py)',
    'original_sha256': sha(original.path),
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {k: sha(v) for k, v in OBJ.items()},
    'range': [H(LO), H(HI)],
    'range_rows': len(rows),
    'unit_map': {
        'clipboard verb unit (from 0x413490) ..0x4159df': {
            'kind': 'rbx',
            'evidence': 'CopyVerb vtable 0x80e960 slot 4 = 0x415800, PasteVerb vtable 0x80e934 slots 2 / 4 = 0x4154a0 '
                        '/ 0x415510 ("NetworkClient", clipboard format "Roblox"); the Creatable instances counted by '
                        'app-unit40c-2008 / creatable-shared-count; TextXmlParser ctor / dtor and the map<string, '
                        'string> / map<InstanceHandle, int> instances emitted by ClipboardActions.cpp.',
            'recovered': 'PasteVerb::doIt, CopyVerb::doIt, TextXmlParser(streambuf*), ~TextXmlParser, ~XmlParser from '
                         'the committed ClipboardActions.cpp compiled unchanged.'},
        'VARIANT / SAFEARRAY conversion block 0x4159e0..0x41668f': {
            'kind': 'rbx + ATL / boost library instances',
            'evidence': 'starts with SafeArrayGetVartype right after CopyVerb::doIt; valueToVariant 0x416370 calls '
                        'makeSafeArray 0x4165e0 and the any_cast / CComSafeArray rows; no clipboard row calls into '
                        'it. The two RBX bodies have committed sources (ValueConverter.cpp / SafeArray.cpp) whose '
                        'mismatch receipts are 635 / 615 B and 189 / 168 B; not attempted here.'},
        'CContent COM unit 0x416690..0x416e5f': {
            'kind': 'rbx',
            'evidence': 'CComObject<CContent> vtables 0x80eabc / 0x80ea98 (slot 7 Upload 0x4166a0, "Untrusted Url"), '
                        'CComAggObject<CContent> 0x80eb4c, CComContainedObject<CContent> 0x80eb38 / 0x80eb14, '
                        'operator new(0x94) in CComCreator<CComObject<CContent>>::CreateInstance 0x416ac0.',
            'recovered': 'the ATL instances over CContent in native-classes/AppUnit414ContentAtl.cpp.'},
        'DHTMLWindowService / DHTMLWindow unit 0x416e60.. (continues past the range)': {
            'kind': 'rbx',
            'evidence': 'DHTMLWindowService vtable 0x80efd4 slot 2 = askAddChild 0x416e60; doDeclare pushes '
                        '"HtmlService"; DHTMLWindow-only boost::bind storages 0x4173b0..0x417ff0 and the DHTMLWindow '
                        'workers 0x417a10..0x417d10 lie in the same run as the CComObject<CLuaFunction> instances '
                        '(vtables 0x80ec00 / 0x80ebd8), so app-unit40c-2008\'s separate CLuaFunction unit at 0x417360 '
                        'is read here as part of this unit.',
            'recovered': 'the DHTMLWindow-only template rows from the committed AppLeaves2008DHTMLWindow.cpp and '
                         'AppLeaves2008DHTMLWindowService.cpp compiled unchanged (their receipts prove them only as '
                         'uncounted instances).'},
    },
    'blocks': per_block,
    'rows': unit_rows,
    'methods': results,
    # instance rows are not counted: their addresses are written 0x-prefixed (never as quoted bare addresses)
    'instances': {k: dict(v, address='0x' + v['address']) for k, v in INSTANCES.items()},
    'vtables': vtables,
    'local_statics': {k: {'address': hex(binding[k]), 'used_by': sorted(v)} for k, v in sorted(LOCAL_STATICS.items())},
    'counted_elsewhere': ['%08x counted by %s' % (a, ', '.join(sorted(v))) for a, v in sorted(counted_elsewhere.items())],
    'not_exact': {},
    'rejected': [],
    'proposals': [
        'native-headers/v8tree/Service.h (core owner): ServiceProvider::find<Class>() const and create<Class>() const '
        'are declared without bodies; 0x415200 / 0x4153b0 (find / create<Selection>, 328 / 228 B) stay open until '
        'bodies exist. Bound here only as call targets of the verb bodies.',
        'CLuaFunction owner (no native header): a CLuaFunction declaration (CComObject<CLuaFunction> RTTI vtables '
        '0x80ec00 / 0x80ebd8) would unlock 0x417e20 / 0x417e80 / 0x417ea0 / 0x417ef0 and the ICF-shared ATL bodies '
        '0x417e70 / 0x417f90 / 0x417fb0 / 0x417fd0 in this range.',
    ],
    'shadowing': 'none (no new header; CContent.h, ClipboardVerbs.h, the DHTMLWindow headers and the profile headers '
                 'are included read-only)',
    'exact_function_rows': exact,
    'scope': 'Inactive. Exact rows with every target verified; no pending build; no active build, swap or credit.',
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native app unit414: %d rows mapped, %d exact (%s), %d counted elsewhere, %d vtables checked, %d instances'
      % (len(rows), len(exact), ' '.join(exact), n_counted_elsewhere, len(vtables), len(INSTANCES)))
for b, v in per_block.items():
    print('  %s: %s' % (b, v))
