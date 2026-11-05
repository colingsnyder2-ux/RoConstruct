"""Verify the inactive native CInstanceExplorer / CSettingsExplorer / CInstanceRecord unit (XTP ReportControl 11.2.2):
layout test, exact bodies with every call/data target, the six explorer vtables, both CRuntimeClass records and the
message map. Profile: document-swap flags + XTP 11.2.2 headers (/UNOMINMAX /D_XTP_STATICLINK) compiled through the
noinline profile for the imported std::string::c_str (CInstanceRecord 00420db0 and CNameItem::GetCaption 00420790
call MSVCP90 c_str through the IAT). The other bodies are also exact without the needle.
OnReportSelChanged 00421d00 and Selection::setSelection<vector<Instance*>::iterator> 00420d20 use the current
Selection.h and are verified in a separate compilation.
Scratch location: writes out/instance-explorer-working.json next to this script.
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

OUT = ROOT / 'rebuild/2008-06/out/native-layouts/instance-explorer'; OUT.mkdir(parents=True, exist_ok=True)
tool = rebuild.toolchain(21022)
FLAGS = flags()
# The scratch directory must precede rebuild/2008-06/native-headers (which holds the committed declaration-only
# CInstanceExplorer.h/CSettingsExplorer.h); the source directory is searched first for quoted includes anyway.
INC = []

# 1. layout test and subobject offsets
layout = OUT / 'NativeInstanceExplorerLayout.obj'
code, log = rebuild.run(tool, 'cl', INC + FLAGS + XTP_FLAGS + ['/Fo' + str(layout), str(HERE / 'NativeInstanceExplorerLayout.cpp')], OUT)
assert code == 0, log[-3000:]
lb = dict((n, b) for n, b, r in match.coff_functions(layout.read_bytes()))
assert lb['?descendantAddedOffset@@YAHXZ'] == bytes.fromhex('b878030000c3')
assert lb['?descendantRemovingOffset@@YAHXZ'] == bytes.fromhex('b89c030000c3')
assert lb['?descendantAddedNotifier@@YAHXZ'] == bytes.fromhex('b864000000c3')
assert lb['?descendantRemovingNotifier@@YAHXZ'] == bytes.fromhex('b884000000c3')


# 2. the unit through the noinline profile
def profile(name, defines=(), replace=()):
    pre = OUT / ('pre-' + name); pre.mkdir(exist_ok=True)
    src = ROOT / 'rebuild/2008-06/native-classes/CInstanceExplorer.cpp'
    code, log = rebuild.run(tool, 'cl', [x for x in FLAGS if x != '/c'] + XTP_FLAGS + INC + list(defines) + ['/P', str(src)], pre)
    assert code == 0, log[-3000:]
    body = (pre / 'CInstanceExplorer.i').read_text(errors='replace')
    needle = 'const _Elem * c_str() const'
    assert body.count(needle) == 1
    body = body.replace(needle, '__declspec(noinline) ' + needle)
    for old, new in replace:
        assert body.count(old) >= 1, old
        body = body.replace(old, new)
    unit = OUT / (name + '.cpp'); unit.write_text(body)
    obj = OUT / (name + '.obj')
    code, log = rebuild.run(tool, 'cl', ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/Fo' + str(obj), str(unit)], OUT)
    assert code == 0, log[-3000:]
    return obj

obj = profile('NativeInstanceExplorerProfile')
selobj = profile('NativeInstanceExplorerSelChanged')

# 3. XTP library bodies (recipe style of record_native_roblox_report_view.py)
XTP_SRC = ROOT / 'tools/libs/xtp-11.2.2/Source'
xtp_bodies = {}
for rel in ('ReportControl/XTPReportView.cpp', 'ReportControl/XTPReportControl.cpp', 'ReportControl/XTPReportHeader.cpp',
            'ReportControl/XTPReportColumn.cpp', 'ReportControl/XTPReportRecord.cpp', 'ReportControl/XTPReportRecords.cpp',
            'ReportControl/XTPReportRecordItem.cpp', 'ReportControl/XTPReportRecordItemText.cpp',
            'ReportControl/XTPReportSelectedRows.cpp'):
    o = OUT / ('xtp_' + Path(rel).stem + '.obj')
    base = ['/nologo', '/c', '/O2', '/MD', '/GS', '/EHsc', '/Ob1', '/D_AFXDLL', '/D_XTP_STATICLINK', '/D_DLL',
            '/I' + str(XTP_SRC), '/I' + str(ROOT / 'tools/libs/mfc-9.0/atlmfc/include')]
    if not (XTP_SRC / rel).exists():
        continue
    if not o.exists():
        code, log = rebuild.run(tool, 'cl', base + ['/Fo' + str(o), str(XTP_SRC / rel)], OUT)
        if code:
            code, log = rebuild.run(tool, 'cl', base + ['/I' + str(ROOT / 'tools/libs/mfc-9.0/atlmfc/src/mfc'),
                                                        '/FIXTToolkitPro.h', '/FIafximpl.h', '/Fo' + str(o), str(XTP_SRC / rel)], OUT)
        if code:
            continue
    for n, b, r in match.coff_functions(o.read_bytes()):
        xtp_bodies.setdefault(n, (b, r))

XTP_TARGETS = {
    '??0CXTPReportView@@IAE@XZ': 0x6c5070,
    '??1CXTPReportView@@MAE@XZ': 0x6c5150,
    '?OnCreate@CXTPReportView@@IAEHPAUtagCREATESTRUCTA@@@Z': 0x6c52a0,
    '?GetThisClass@CXTPReportView@@SGPAUCRuntimeClass@@XZ': 0x6c4cc0,
    '?GetThisMessageMap@CXTPReportView@@KGPBUAFX_MSGMAP@@XZ': 0x6c6890,
    '?AddColumn@CXTPReportControl@@QAEPAVCXTPReportColumn@@PAV2@@Z': 0x6c9600,
    '?SetAutoColumnSizing@CXTPReportHeader@@QAEXH@Z': 0x6d6890,
    '??0CXTPReportColumn@@QAE@HPBDHHHHH@Z': 0x6d4b70,
    '?SetTreeColumn@CXTPReportColumn@@QAEXH@Z': 0x6d4980,
    '?RemoveAll@CXTPReportRecords@@QAEXXZ': 0x6d7850,
    '?GetAt@CXTPReportRecords@@QBEPAVCXTPReportRecord@@H@Z': 0x6d7920,
    '?RemoveAt@CXTPReportRecords@@QAEXH@Z': 0x6d7cd0,
    '?GetCount@CXTPReportRecords@@QBEHXZ': 0x6da050,
    '??0CXTPReportRecord@@QAE@XZ': 0x6d7fd0,
    '??1CXTPReportRecord@@UAE@XZ': 0x6d8100,
    '?AddItem@CXTPReportRecord@@QAEPAVCXTPReportRecordItem@@PAV2@@Z': 0x6d8070,
    '??0CXTPReportRecordItem@@QAE@XZ': 0x6c7340,
    '??0CXTPReportRecordItemText@@QAE@PBD@Z': 0x6d8600,
    '??2?$CXTPHeapObjectT@VCCmdTarget@@VCXTPReportDataAllocator@@@@SGPAXI@Z': 0x6c81f0,
    '?Free_mem@?$CXTPHeapAllocatorT@UCXTPReportDataAllocatorData@@@@SAXPAX@Z': 0x420a80,
    '?GetFirstSelectedRowPosition@CXTPReportSelectedRows@@QAEPAU__POSITION@@XZ': 0x6db550,
    '?GetNextSelectedRow@CXTPReportSelectedRows@@QAEPAVCXTPReportRow@@AAPAU__POSITION@@@Z': 0x6db580,
}
xtp_proof = {}
for symbol, address in XTP_TARGETS.items():
    t, tr, _ = match.target('2008-06', '%08x' % address)
    hit = xtp_bodies.get(symbol)
    xtp_proof[symbol] = 'XTP recipe body exact' if hit and match.exact_match(t, tr, hit[0], hit[1]) else 'bound by call site only'

original = Original()
INTERNAL = dict(XTP_TARGETS)
INTERNAL.update({
    # XTP allocator statics read by the CXTPHeapObjectT operator delete inlined in 00420f60
    '?ms_dwRefs@CXTPReportDataAllocatorData@@2JA': 0x97e10c,
    '?ms_bUseCustomHeap@CXTPReportDataAllocatorData@@2HA': 0x97e114,
    # call-site bindings (bodies owned by other units or identical-COMDAT folds; see 'folds' in the receipt)
    '??$shared_from@VInstance@RBX@@@RBX@@YA?AV?$shared_ptr@VInstance@RBX@@@boost@@PAVInstance@0@@Z': 0x618a40,
    '??4shared_count@detail@boost@@QAEAAV012@ABV012@@Z': 0x4025b0,
    '?removeListener@?$Notifier@VInstance@RBX@@UDescendantAdded@2@@RBX@@QBEXPAV?$Listener@VInstance@RBX@@UDescendantAdded@2@@2@@Z': 0x5e5a80,
    '?removeListener@?$Notifier@VInstance@RBX@@UDescendantRemoving@2@@RBX@@QBEXPAV?$Listener@VInstance@RBX@@UDescendantRemoving@2@@2@@Z': 0x5e5a80,
    '??1DescendantAdded@RBX@@QAE@XZ': 0x422c60,
    '??1DescendantRemoving@RBX@@QAE@XZ': 0x422c60,
    '??$create@VSelection@RBX@@@ServiceProvider@RBX@@SAPAVSelection@1@PBVInstance@1@@Z': 0x421cb0,
    '?clearSelection@Selection@RBX@@QAEXXZ': 0x5675d0,
    '?addToSelection@Selection@RBX@@QAEXPAVInstance@2@@Z': 0x567420,
    '___RTDynamicCast': 0x6a17c6,
    # marshal window (committed receipts: script-editor / frame-marshalling, roblox-report-view)
    '?acquireMarshalWindow@RBX@@YAPAVCMarshalWindow@1@XZ': 0x432ce0,
    '?releaseMarshalWindow@RBX@@YAXPAVCMarshalWindow@1@@Z': 0x432bd0,
    '?post@CMarshalWindow@RBX@@QAEXPAVEventDataBase@2@@Z': 0x432950,
    # MarshaledListener detach/remove/setSource: identical-COMDAT folds with the ChildAdded instances emitted and
    # verified exact by the CRobloxReportView unit (00457710, 004574b0, 004571d0)
    '?detach@?$MarshaledListener@VInstance@RBX@@UDescendantAdded@2@V12@U32@@RBX@@QAEXXZ': 0x457710,
    '?detach@?$MarshaledListener@VInstance@RBX@@UDescendantRemoving@2@V12@U32@@RBX@@QAEXXZ': 0x457710,
    '?setSource@EventData@?$MarshaledListener@VInstance@RBX@@UDescendantAdded@2@V12@U32@@RBX@@QAEXPBVInstance@3@@Z': 0x4571d0,
    '?setSource@EventData@?$MarshaledListener@VInstance@RBX@@UDescendantRemoving@2@V12@U32@@RBX@@QAEXPBVInstance@3@@Z': 0x4571d0,
    '??2@YAPAXI@Z': 0x6a0920,
    '??3@YAXPAX@Z': 0x6a067a,
    # ??_E (vector deleting destructor) symbols resolve to the scalar deleting bodies (no array new of these classes)
    '??_ECInstanceExplorer@@UAEPAXI@Z': 0x421c90,
    '??_ECSettingsExplorer@@UAEPAXI@Z': 0x421c90,
    '??_ECInstanceRecord@@UAEPAXI@Z': 0x420f60,
    # own vtables / runtime classes / message map
    '??_7CInstanceExplorer@@6BCXTPReportView@@@': 0x80f8c4,
    '??_7CInstanceExplorer@@6B?$MarshaledListener@VInstance@RBX@@UDescendantAdded@2@V12@U32@@RBX@@@': 0x80f8ac,
    '??_7CInstanceExplorer@@6B?$MarshaledListener@VInstance@RBX@@UDescendantRemoving@2@V12@U32@@RBX@@@': 0x80f898,
    '??_7CSettingsExplorer@@6BCXTPReportView@@@': 0x81bdf4,
    '??_7CSettingsExplorer@@6B?$MarshaledListener@VInstance@RBX@@UDescendantAdded@2@V12@U32@@RBX@@@': 0x81bde0,
    '??_7CSettingsExplorer@@6B?$MarshaledListener@VInstance@RBX@@UDescendantRemoving@2@V12@U32@@RBX@@@': 0x81bdcc,
    '??_7CInstanceRecord@@6B@': 0x80f7e4,
    '??_7CNameItem@CInstanceRecord@@6B@': 0x80f65c,
    '?classCInstanceExplorer@CInstanceExplorer@@2UCRuntimeClass@@B': 0x80f638,
    '?classCSettingsExplorer@CSettingsExplorer@@2UCRuntimeClass@@B': 0x81bdac,
    '?messageMap@?1??GetThisMessageMap@CInstanceExplorer@@KGPBUAFX_MSGMAP@@XZ@4U3@B': 0x80fa7c,
})
# vector<T*>::insert(iterator, const T&): one folded body 004c7c60 (exact in the CRobloxReportView receipt) for
# vector<Instance*> (00421d00) and the EventData/Listener pointer vectors (push_back 004213a0)
for o in (obj, selobj):
    for n, b, r in match.coff_functions(o.read_bytes()):
        if n.startswith('?insert@?$vector@PAV') and ('Descendant' in n or n.startswith('?insert@?$vector@PAVInstance@RBX@@')):
            INTERNAL[n] = 0x4c7c60

LISTENER = 'MarshaledListener@VInstance@RBX@@U%s@2@V12@U32@@RBX@@'
METHODS = [
    ('?GetRuntimeClass@CInstanceExplorer@@UBEPAUCRuntimeClass@@XZ', 0x420780),
    ('?GetCaption@CNameItem@CInstanceRecord@@UAE?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PAVCXTPReportColumn@@@Z', 0x420790),
    ('?OnCreate@CInstanceExplorer@@QAEHPAUtagCREATESTRUCTA@@@Z', 0x420990),
    ('?onMarshaledEvent@CInstanceExplorer@@UAEXPBVInstance@RBX@@UDescendantRemoving@3@@Z', 0x420c20),
    ('??0CInstanceRecord@@QAE@V?$shared_ptr@VInstance@RBX@@@boost@@@Z', 0x420db0),
    ('??1CInstanceRecord@@UAE@XZ', 0x420ee0),
    ('??_GCInstanceRecord@@UAEPAXI@Z', 0x420f60),
    ('?onMarshaledEvent@CInstanceExplorer@@UAEXPBVInstance@RBX@@UDescendantAdded@3@@Z', 0x420fb0),
    ('??0?$%sQAE@XZ' % (LISTENER % 'DescendantAdded'), 0x421080),
    ('??0?$%sQAE@XZ' % (LISTENER % 'DescendantRemoving'), 0x421130),
    ('?onEvent@?$%sUAEXPBVInstance@2@UDescendantAdded@2@@Z' % (LISTENER % 'DescendantAdded'), 0x4211b0),
    ('?onEvent@?$%sUAEXPBVInstance@2@UDescendantRemoving@2@@Z' % (LISTENER % 'DescendantRemoving'), 0x4211b0),
    ('??1?$%sUAE@XZ' % (LISTENER % 'DescendantAdded'), 0x421620),
    ('?marshal@?$%sUAEXPBVInstance@2@UDescendantAdded@2@@Z' % (LISTENER % 'DescendantAdded'), 0x4216a0),
    ('??1?$%sUAE@XZ' % (LISTENER % 'DescendantRemoving'), 0x421740),
    ('?marshal@?$%sUAEXPBVInstance@2@UDescendantRemoving@2@@Z' % (LISTENER % 'DescendantRemoving'), 0x4217c0),
    ('?addListener@?$Notifier@VInstance@RBX@@UDescendantAdded@2@@RBX@@QBEXPAV?$Listener@VInstance@RBX@@UDescendantAdded@2@@2@@Z', 0x4218a0),
    ('?addListener@?$Notifier@VInstance@RBX@@UDescendantRemoving@2@@RBX@@QBEXPAV?$Listener@VInstance@RBX@@UDescendantRemoving@2@@2@@Z', 0x4218a0),
    ('??0EventData@?$%sQAE@PAV12@PBVInstance@2@UDescendantAdded@2@@Z' % (LISTENER % 'DescendantAdded'), 0x421240),
    ('??0EventData@?$%sQAE@PAV12@PBVInstance@2@UDescendantRemoving@2@@Z' % (LISTENER % 'DescendantRemoving'), 0x4212f0),
    ('??0CInstanceExplorer@@QAE@XZ', 0x421940),
    ('??_ECInstanceExplorer@@WDHI@AEPAXI@Z', 0x4219d0),
    ('??_ECInstanceExplorer@@WDJM@AEPAXI@Z', 0x4219e0),
    ('??_ECSettingsExplorer@@WDHI@AEPAXI@Z', 0x4219d0),
    ('??_ECSettingsExplorer@@WDJM@AEPAXI@Z', 0x4219e0),
    ('?CreateObject@CInstanceExplorer@@SGPAVCObject@@XZ', 0x4219f0),
    ('?setRoot@CInstanceExplorer@@QAEXPAVInstance@RBX@@@Z', 0x421a50),
    ('??1CInstanceExplorer@@UAE@XZ', 0x421bc0),
    ('??_GCInstanceExplorer@@UAEPAXI@Z', 0x421c90),
    ('??_GCSettingsExplorer@@UAEPAXI@Z', 0x421c90),
    ('?GetMessageMap@CInstanceExplorer@@MBEPBUAFX_MSGMAP@@XZ', 0x421e70),
    ('?GetRuntimeClass@CSettingsExplorer@@UBEPAUCRuntimeClass@@XZ', 0x466b80),
    ('?CreateObject@CSettingsExplorer@@SGPAVCObject@@XZ', 0x466b90),
    ('?onEvent@CSettingsExplorer@@UAEXPBVInstance@RBX@@UDescendantAdded@3@@Z', 0x466d40),
    ('?onEvent@CSettingsExplorer@@UAEXPBVInstance@RBX@@UDescendantRemoving@3@@Z', 0x466d40),
]
# vector<T*>::push_back for the two EventData vectors and the two Listener vectors: one folded body 004213a0
for n, b, r in match.coff_functions(obj.read_bytes()):
    if n.startswith('?push_back@?$vector@PAV') and ('Descendant' in n):
        METHODS.append((n, 0x4213a0))
present = {n for n, b, r in match.coff_functions(obj.read_bytes())}
missing = [n for n, a in METHODS if n not in present]
assert not missing, missing
rows = verify(original, obj, METHODS, INTERNAL)
sel_present = {n for n, b, r in match.coff_functions(selobj.read_bytes())}
SEL = [('?OnReportSelChanged@CInstanceExplorer@@QAEXPAUtagNMHDR@@PAJ@Z', 0x421d00)]
SEL += [(n, 0x420d20) for n in sel_present if n.startswith('??$setSelection@V?$_Vector_iterator@PAVInstance@RBX@@')]
assert len(SEL) == 2, SEL
sel_rows = verify(original, selobj, SEL, INTERNAL)

# 4. vtables: every slot defined by this object binds to the original slot value (own exact rows, imports, XTP).
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
own = dict(METHODS); own.update(dict(SEL))
def relocations(section):
    table = sections[section]
    for i in range(table[7]):
        yield struct.unpack_from('<IIH', raw, table[5] + 10 * i)
vtables = {}
for symbol, address in INTERNAL.items():
    if not symbol.startswith('??_7') or symbol not in definitions:
        continue
    start, section = definitions[symbol]
    slots = {}
    for offset, index, kind in relocations(section):
        if offset >= start and (offset - start) % 4 == 0:
            slots.setdefault((offset - start) // 4, symbols[index][0])
    count = 0
    while count in slots:
        count += 1
    values = struct.unpack('<%dI' % count, original.data(address, 4 * count))
    result = {'verified': 0, 'unverified': {}}
    for slot in range(count):
        name, value = slots[slot], values[slot]
        if name in own:
            assert own[name] == value, (symbol, slot, name, hex(value))
        elif name in INTERNAL:
            assert INTERNAL[name] == value, (symbol, slot, name, hex(value))
        else:
            hit = original.imported(value)
            if hit is not None:
                assert hit[1] == native_bind.plain(name), (symbol, slot, name, hit)
            else:
                result['unverified'][slot] = (name, hex(value)); continue
        result['verified'] += 1
    result['slots'] = count
    vtables['%08x' % address] = result

# 5. CRuntimeClass records and the message map
for address, name, create, getter in ((0x80f638, b'CInstanceExplorer\0', 0x4219f0, 0x420770),
                                      (0x81bdac, b'CSettingsExplorer\0', 0x466b90, 0x466b70)):
    runtime = struct.unpack('<IiIIII', original.data(address, 24))
    assert original.data(runtime[0], len(name)) == name
    assert runtime[1:5] == (0x3cc, 0xffff, create, getter), runtime
base_getter, entries = struct.unpack('<II', original.data(0x80fa7c, 8))
assert base_getter == 0x6c6890
assert struct.unpack('<6I', original.data(entries, 24)) == (0x1, 0, 0, 0, 0xd, 0x420990)
assert struct.unpack('<6I', original.data(entries + 24, 24)) == (0x4e, 0xffcc, 100, 100, 0x3d, 0x421d00)
assert struct.unpack('<6I', original.data(entries + 48, 24)) == (0, 0, 0, 0, 0, 0)

H = ROOT / 'rebuild/2008-06/native-headers'
paths = [Path(__file__), ROOT / 'rebuild/2008-06/native-classes/CInstanceExplorer.cpp', H / 'CInstanceExplorer.h', H / 'CSettingsExplorer.h',
         HERE / 'NativeInstanceExplorerLayout.cpp']
receipt = {
    'class': 'CInstanceExplorer (+ CSettingsExplorer, CInstanceRecord, CInstanceRecord::CNameItem)',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': FLAGS + XTP_FLAGS, 'profile': 'noinline std::string::c_str (imported)',
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths}, 'object_sha256': sha(obj),
    'methods': rows, 'selection_methods': sel_rows, 'vtables': vtables, 'xtp_proof': xtp_proof,
}
(ROOT / 'work/2008-06/shared-layouts/instance-explorer-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native CInstanceExplorer: %d exact rows, %d selection rows; vtables %s'
      % (len(rows), len(sel_rows), {k: (v['verified'], v['slots'], len(v['unverified'])) for k, v in vtables.items()}))
print({k: v for k, v in xtp_proof.items()})
