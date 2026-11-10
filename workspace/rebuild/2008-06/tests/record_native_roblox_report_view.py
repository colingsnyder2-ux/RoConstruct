"""Verify the inactive native CRobloxReportView (stats report view on XTP ReportControl 11.2.2): layout test, exact
bodies with every call/data target, the three vtables, the CRuntimeClass record and the message map.
Profile: document-swap flags + XTP 11.2.2 headers (/UNOMINMAX /D_XTP_STATICLINK); no noinline needles are needed.
XTP call targets are proven by compiling the XTP 11.2.2 ReportControl units and matching their bodies at the bound
address. Scratch location: writes out/robloxreport-view-working.json next to this script.
"""
import json
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(HERE))
import native_bind  # noqa: E402
from native_bind import XTP_FLAGS, Original, flags, match, rebuild, sha, verify  # noqa: E402

OUT = ROOT / 'rebuild/2008-06/out/native-layouts/roblox-report-view'; OUT.mkdir(parents=True, exist_ok=True)
tool = rebuild.toolchain(21022)
FLAGS = flags()

# 1. layout test and listener subobject offsets
layout = OUT / 'NativeRobloxReportViewLayout.obj'
code, log = rebuild.run(tool, 'cl', FLAGS + XTP_FLAGS + ['/Fo' + str(layout), str(HERE / 'NativeRobloxReportViewLayout.cpp')], OUT)
assert code == 0, log[-3000:]
lb = dict((n, b) for n, b, r in match.coff_functions(layout.read_bytes()))
assert lb['?childAddedOffset@@YAHXZ'] == bytes.fromhex('b878030000c3'), lb['?childAddedOffset@@YAHXZ'].hex()
assert lb['?childRemovedOffset@@YAHXZ'] == bytes.fromhex('b89c030000c3'), lb['?childRemovedOffset@@YAHXZ'].hex()

# 2. the unit
obj = OUT / 'CRobloxReportView.obj'
code, log = rebuild.run(tool, 'cl', FLAGS + XTP_FLAGS + ['/Fo' + str(obj), str(ROOT / 'rebuild/2008-06/native-classes/CRobloxReportView.cpp')], OUT)
assert code == 0, log[-3000:]
raw = obj.read_bytes()
present = {n for n, b, r in match.coff_functions(raw)}

# 3. XTP library bodies (recipe style of record_native_class_tree_view.py)
XTP_SRC = ROOT / 'tools/libs/xtp-11.2.2/Source'
xtp_bodies = {}
for rel in ('ReportControl/XTPReportView.cpp', 'ReportControl/XTPReportControl.cpp', 'ReportControl/XTPReportHeader.cpp',
            'ReportControl/XTPReportColumn.cpp'):
    o = OUT / ('xtp_' + Path(rel).stem + '.obj')
    base = ['/nologo', '/c', '/O2', '/MD', '/GS', '/EHsc', '/Ob1', '/D_AFXDLL', '/D_XTP_STATICLINK', '/D_DLL',
            '/I' + str(XTP_SRC), '/I' + str(ROOT / 'tools/libs/mfc-9.0/atlmfc/include')]
    if not o.exists():
        code, log = rebuild.run(tool, 'cl', base + ['/Fo' + str(o), str(XTP_SRC / rel)], OUT)
        if code:
            code, log = rebuild.run(tool, 'cl', base + ['/I' + str(ROOT / 'tools/libs/mfc-9.0/atlmfc/src/mfc'),
                                                        '/FIXTToolkitPro.h', '/FIafximpl.h', '/Fo' + str(o), str(XTP_SRC / rel)], OUT)
        assert code == 0, (rel, log[-2000:])
    for n, b, r in match.coff_functions(o.read_bytes()):
        xtp_bodies.setdefault(n, (b, r))

XTP_TARGETS = {
    '??0CXTPReportView@@IAE@XZ': 0x6c5070,
    '??1CXTPReportView@@MAE@XZ': 0x6c5150,
    '?OnCreate@CXTPReportView@@IAEHPAUtagCREATESTRUCTA@@@Z': 0x6c52a0,
    '?GetThisClass@CXTPReportView@@SGPAUCRuntimeClass@@XZ': 0x6c4cc0,
    '?GetThisMessageMap@CXTPReportView@@KGPBUAFX_MSGMAP@@XZ': 0x6c6890,
    '?AdjustLayout@CXTPReportControl@@QAEXXZ': 0x6cc910,
    '?AddColumn@CXTPReportControl@@QAEPAVCXTPReportColumn@@PAV2@@Z': 0x6c9600,
    '?SetAutoColumnSizing@CXTPReportHeader@@QAEXH@Z': 0x6d6890,
    '??0CXTPReportColumn@@QAE@HPBDHHHHH@Z': 0x6d4b70,
    '?SetTreeColumn@CXTPReportColumn@@QAEXH@Z': 0x6d4980,
}
xtp_proof = {}
for symbol, address in XTP_TARGETS.items():
    t, tr, _ = match.target('2008-06', '%08x' % address)
    hit = xtp_bodies.get(symbol)
    xtp_proof[symbol] = 'XTP recipe body exact' if hit and match.exact_match(t, tr, hit[0], hit[1]) else 'bound by call site only'

original = Original()
INTERNAL = dict(XTP_TARGETS)
INTERNAL.update({
    # committed receipts: work/2008-06/shared-layouts/script-editor-working.json, frame-marshalling, document
    '?acquireMarshalWindow@RBX@@YAPAVCMarshalWindow@1@XZ': 0x432ce0,
    '?releaseMarshalWindow@RBX@@YAXPAVCMarshalWindow@1@@Z': 0x432bd0,
    '?post@CMarshalWindow@RBX@@QAEXPAVEventDataBase@2@@Z': 0x432950,
    '?getDataModel@CRobloxDoc@@QAE?AV?$shared_ptr@VDataModel@RBX@@@boost@@XZ': 0x403040,
    # call-site bindings (bodies owned by other units)
    '?updateStats@CRobloxReportView@@QAEXXZ': 0x456c30,
    # STL depth limit: vector<EventData*>::_Insert_n called from the exact insert 004c7c60 (bound by call site)
    '?_Insert_n@?$vector@PAV' + 'EventData@?$MarshaledListener@VInstance@RBX@@UChildAdded@2@V12@U32@@RBX@@': 0x4c7890,
    '?_Insert_n@?$vector@PAV' + 'EventData@?$MarshaledListener@VInstance@RBX@@UChildRemoved@2@V12@U32@@RBX@@': 0x4c7890,
    # own near-miss (open): only the early-return cleanup layout differs; bound by call site
    '?setDataModel@CRobloxReportView@@QAEXV?$shared_ptr@VDataModel@RBX@@@boost@@@Z': 0x458700,
    '??0ChildAdded@RBX@@QAE@ABU01@@Z': 0x4116f0,
    '??0ChildRemoved@RBX@@QAE@ABU01@@Z': 0x4116f0,
    # shared_from<const Instance>: same bytes as shared_from<Instance> 00618a40 (identical-COMDAT fold)
    '??$shared_from@$$CBVInstance@RBX@@@RBX@@YA?AV?$shared_ptr@$$CBVInstance@RBX@@@boost@@PBVInstance@0@@Z': 0x618a40,
    '?classCRobloxReportView@CRobloxReportView@@2UCRuntimeClass@@B': 0x818348,
    '?messageMap@?1??GetThisMessageMap@CRobloxReportView@@KGPBUAFX_MSGMAP@@XZ@4U3@B': 0x8187b0,
    '?_messageEntries@?1??GetThisMessageMap@CRobloxReportView@@KGPBUAFX_MSGMAP@@XZ@4QBUAFX_MSGMAP_ENTRY@@B': 0x8187b8,
    '??_7CRobloxReportView@@6BCXTPReportView@@@': 0x81888c,
    '??_7CRobloxReportView@@6B?$MarshaledListener@VInstance@RBX@@UChildAdded@2@V12@U32@@RBX@@@': 0x818878,
    '??_7CRobloxReportView@@6B?$MarshaledListener@VInstance@RBX@@UChildRemoved@2@V12@U32@@RBX@@@': 0x818864,
})
ML = '?$MarshaledListener@VInstance@RBX@@U%s@2@V12@U32@@RBX@@'
ED = 'EventData@' + ML
METHODS = [
    ('??0CRobloxReportView@@QAE@XZ', 0x457a40),
    ('??1CRobloxReportView@@UAE@XZ', 0x458b70),
    ('??_GCRobloxReportView@@UAEPAXI@Z', 0x458d60),
    ('??_ECRobloxReportView@@WDHI@AEPAXI@Z', 0x457ad0),
    ('??_ECRobloxReportView@@WDJM@AEPAXI@Z', 0x457ae0),
    ('?GetRuntimeClass@CRobloxReportView@@UBEPAUCRuntimeClass@@XZ', 0x455d50),
    ('?GetMessageMap@CRobloxReportView@@MBEPBUAFX_MSGMAP@@XZ', 0x457010),
    ('?OnCreate@CRobloxReportView@@QAEHPAUtagCREATESTRUCTA@@@Z', 0x455fd0),
    ('?OnTimer@CRobloxReportView@@QAEXI@Z', 0x456e60),
    ('?OnInitialUpdate@CRobloxReportView@@UAEXXZ', 0x4589c0),
    # MarshaledListener<Instance, ChildAdded/ChildRemoved> instances emitted by this unit
    ('??0' + ML % 'ChildAdded', 0x457050),
    ('??0' + ML % 'ChildRemoved', 0x4570d0),
    ('??1' + ML % 'ChildAdded', 0x4577e0),
    ('??1' + ML % 'ChildRemoved', 0x4578f0),
    ('?onEvent@' + ML % 'ChildAdded', 0x457150),
    ('?marshal@' + ML % 'ChildAdded', 0x457860),
    ('?marshal@' + ML % 'ChildRemoved', 0x457970),
    ('?detach@' + ML % 'ChildAdded', 0x457710),
    ('?remove@' + ML % 'ChildAdded', 0x4574b0),
    ('??0' + ED % 'ChildAdded', 0x457270),
    ('??0' + ED % 'ChildRemoved', 0x4573f0),
    ('??1' + ED % 'ChildAdded', 0x457330),
    ('??1' + ED % 'ChildRemoved', 0x457590),
    ('??_G' + ED % 'ChildAdded', 0x4576d0),
    ('??_G' + ED % 'ChildRemoved', 0x4576f0),
    ('?setSource@' + ED % 'ChildAdded', 0x4571d0),
]
# identical-COMDAT folds: the ChildRemoved twins are the same bytes at the ChildAdded address
FOLDS = [
    ('?onEvent@' + ML % 'ChildRemoved', 0x457150),
    ('?detach@' + ML % 'ChildRemoved', 0x457710),
    ('?remove@' + ML % 'ChildRemoved', 0x4574b0),
    ('?setSource@' + ED % 'ChildRemoved', 0x4571d0),
    # _GetBaseClass (IMPLEMENT_DYNAMIC under _AFXDLL): jmp CXTPReportView::GetThisClass, shared with the other
    # CXTPReportView subclasses' identical bodies at 00420770 (CRuntimeClass 00818348 base getter field)
    ('?_GetBaseClass@CRobloxReportView@@KGPAUCRuntimeClass@@XZ', 0x420770),
]
# Shared COMDATs (bodies also bound in committed receipts); exact here, used as binding proof.
DEPENDENCIES = [
    ('?push_back@?$vector@PAV' + ED % 'ChildAdded', 0x4213a0),
    ('?push_back@?$vector@PAV' + ED % 'ChildRemoved', 0x4213a0),
    ('?erase@?$vector@PAV' + ED % 'ChildAdded', 0x445dc0),
    ('?erase@?$vector@PAV' + ED % 'ChildRemoved', 0x445dc0),
    ('?insert@?$vector@PAV' + ED % 'ChildAdded', 0x4c7c60),
    ('?insert@?$vector@PAV' + ED % 'ChildRemoved', 0x4c7c60),
    ('??4shared_count@detail@boost@@QAEAAV012@ABV012@@Z', 0x4025b0),
]
def resolve(rows):
    return [(n if n in present else next(p for p in sorted(present) if p.startswith(n)), a) for n, a in rows]
METHODS, FOLDS, DEPENDENCIES = resolve(METHODS), resolve(FOLDS), resolve(DEPENDENCIES)
OWN = dict(METHODS + FOLDS + DEPENDENCIES)
OWN['??_ECRobloxReportView@@UAEPAXI@Z'] = 0x458d60   # weak alias of ??_G (no array new)
OWN['?execute@' + ED % 'ChildAdded' + '@UAEXXZ'] = 0x457650
OWN['?execute@' + ED % 'ChildRemoved' + '@UAEXXZ'] = 0x457650
for k in list(INTERNAL):
    if k not in present:
        hit = [p for p in present if p.startswith(k)]
        if hit: INTERNAL[hit[0]] = INTERNAL.pop(k)
for k in list(OWN):
    if k not in present:
        hit = [p for p in present if p.startswith(k)]
        if hit: OWN[hit[0]] = OWN.pop(k)
import os
if os.environ.get('DISCOVER'):
    for n, a in METHODS + FOLDS + DEPENDENCIES:
        for _ in range(30):
            try:
                verify(original, obj, [(n, a)], INTERNAL, OWN); break
            except AssertionError as e:
                x = e.args[0]
                if len(x) == 3 and str(x[2]).startswith('0x'):
                    INTERNAL[x[1]] = int(x[2], 16); print('UNBOUND', x[2], x[1], 'in', n[:50], 'defined' if x[1] in present else '')
                else:
                    print('FAIL', n, x); break
    sys.exit(0)
rows = verify(original, obj, METHODS, INTERNAL, OWN)
rows += [dict(r, role='identical-COMDAT fold') for r in verify(original, obj, FOLDS, INTERNAL, OWN)]
dep_rows = [dict(r, role='shared COMDAT (binding proof)') for r in verify(original, obj, DEPENDENCIES, INTERNAL, OWN)]

# execute 00457650: the analysed extent (91 bytes) stops at the catch funclet 004576ab; the 124-byte body matches the
# raw image with relocations masked (bounds evidence only).
bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
ex = next(p for p in present if p.startswith('?execute@' + ED % 'ChildAdded'))
b, r = bodies[ex]
img = original.data(0x457650, len(b))
bounds = {'address': '00457650', 'symbol': ex, 'size': len(b), 'analysed_size': 91,
          'raw_match': bool(match.exact_match(img, [], b, r))}

# 4. vtables
sections, symbols, definitions, _ = match._coff_data_index(raw)
def relocations(section):
    table = sections[section]
    return [struct.unpack_from('<IIH', raw, table[5] + 10 * i) for i in range(table[7])]
vt = {v['vtable']: v for v in json.loads((ROOT / 'work/2008-06/vtables.json').read_text()) if v['class'] == 'CRobloxReportView'}
vtables = {}
for name, address in (('??_7CRobloxReportView@@6BCXTPReportView@@@', 0x81888c),
                      ('??_7CRobloxReportView@@6B?$MarshaledListener@VInstance@RBX@@UChildAdded@2@V12@U32@@RBX@@@', 0x818878),
                      ('??_7CRobloxReportView@@6B?$MarshaledListener@VInstance@RBX@@UChildRemoved@2@V12@U32@@RBX@@@', 0x818864)):
    count = len(vt['%08x' % address]['slots'])
    start, section = definitions[name]
    slots = {(o - start) // 4: symbols[i][0] for o, i, _ in relocations(section) if start <= o < start + count * 4}
    values = struct.unpack('<%dI' % count, original.data(address, count * 4))
    assert len(slots) == count, (name, len(slots), count)
    result = {'verified': 0, 'xtp': {}, 'unverified': {}, 'open': {}}
    for slot, symbol in sorted(slots.items()):
        value = values[slot]
        if symbol in OWN:
            assert OWN[symbol] == value, (name, slot, symbol, hex(value))
            result['verified'] += 1; continue
        hit = original.imported(value)
        if hit is not None:
            assert hit[1] == native_bind.plain(symbol), (name, slot, symbol, hit)
            result['verified'] += 1; continue
        t, tr, _ = match.target('2008-06', '%08x' % value)
        xb = xtp_bodies.get(symbol)
        if xb and match.exact_match(t, tr, xb[0], xb[1]):
            result['xtp'][slot] = (symbol, hex(value)); result['verified'] += 1
        elif symbol.startswith('?onMarshaledEvent@CRobloxReportView@@'):
            result['open'][slot] = (symbol, hex(value))
        else:
            result['unverified'][slot] = (symbol, hex(value))
    rtti, off = original.vtable_class(address)
    assert rtti == '.?AVCRobloxReportView@@', rtti
    vtables[name] = dict(result, address='%08x' % address, slots=count, col_offset=hex(off))

# 5. CRuntimeClass 00818348: name, size 0x3d4, schema 0xffff, no CreateObject, base getter 00420770
rec = struct.unpack('<IiIIII', original.data(0x818348, 24))
assert original.string(rec[0]) == 'CRobloxReportView' and rec[1:5] == (0x3d4, 0xffff, 0, 0x420770), rec

# 6. Message map 008187b0: CXTPReportView base getter, ON_WM_CREATE, ON_WM_TIMER
base_getter, entries = struct.unpack('<II', original.data(0x8187b0, 8))
assert (base_getter, entries) == (0x6c6890, 0x8187b8)
expected = [(0x1, 0, 0, 0, 13, 0x455fd0), (0x113, 0, 0, 0, 20, 0x456e60), (0, 0, 0, 0, 0, 0)]
assert [struct.unpack('<6I', original.data(entries + 24 * i, 24)) for i in range(3)] == expected
name = '?_messageEntries@?1??GetThisMessageMap@CRobloxReportView@@KGPBUAFX_MSGMAP@@XZ@4QBUAFX_MSGMAP_ENTRY@@B'
start, section = definitions[name]
mine = [struct.unpack_from('<6I', raw, sections[section][4] + start + 24 * i) for i in range(3)]
handlers = {(o - start) // 24: symbols[i][0] for o, i, _ in relocations(section) if start <= o < start + 72}
assert [m[:5] for m in mine] == [e[:5] for e in expected], mine
assert OWN[handlers[0]] == 0x455fd0 and OWN[handlers[1]] == 0x456e60, handlers

paths = [Path(__file__), ROOT / 'rebuild/2008-06/tests/native_bind.py', ROOT / 'rebuild/2008-06/native-classes/CRobloxReportView.cpp', ROOT / 'rebuild/2008-06/native-headers/CRobloxReportView.h', HERE / 'NativeRobloxReportViewLayout.cpp']
receipt = {
    'class': 'CRobloxReportView', 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'profile': 'document-swap flags + XTP 11.2.2 headers (/UNOMINMAX /D_XTP_STATICLINK)',
    'original_sha256': sha(original.path), 'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths}, 'object_sha256': sha(obj),
    'methods': rows, 'dependencies': dep_rows, 'bounds': [bounds], 'xtp_targets': xtp_proof, 'vtables': vtables,
}
(ROOT / 'work/2008-06/shared-layouts/roblox-report-view-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native CRobloxReportView: %d exact rows, %d dependency rows' % (len(rows), len(dep_rows)))
print(json.dumps(xtp_proof, indent=1)); print(bounds)
for k, v in vtables.items():
    print(k[:60], v['slots'], 'verified', v['verified'], 'xtp', len(v['xtp']), 'open', v['open'], 'unverified', v['unverified'])
