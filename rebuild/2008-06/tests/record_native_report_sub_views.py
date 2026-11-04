"""Verify the inactive native CRobloxReportDocView / CRobloxReportPaneView leaves of CRobloxReportView: layout test,
exact bodies with every call/data target, identical-COMDAT folds, all seven vtables, the CRuntimeClass records and the
pane's (empty) message map. Profile: the CRobloxReportView profile (document-swap flags + XTP 11.2.2 headers,
/UNOMINMAX /D_XTP_STATICLINK). Writes work/2008-06/shared-layouts/report-sub-views-working.json.
"""
import json
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(HERE))
from native_bind import XTP_FLAGS, Original, flags, match, rebuild, sha, verify  # noqa: E402

OUT = ROOT / 'rebuild/2008-06/out/native-layouts/roblox-report-sub-views'; OUT.mkdir(parents=True, exist_ok=True)
tool = rebuild.toolchain(21022)
FLAGS = flags()

# 1. layout test: ActiveDocView subobject of the pane view at +0x3d4 (sizes are compile-time asserts)
layout = OUT / 'NativeRobloxReportSubViewsLayout.obj'
code, log = rebuild.run(tool, 'cl', FLAGS + XTP_FLAGS + ['/Fo' + str(layout), str(HERE / 'NativeRobloxReportSubViewsLayout.cpp')], OUT)
assert code == 0, log[-3000:]
lb = dict((n, b) for n, b, r in match.coff_functions(layout.read_bytes()))
assert lb['?activeDocViewOffset@@YAHXZ'] == bytes.fromhex('b8d4030000c3'), lb['?activeDocViewOffset@@YAHXZ'].hex()

# 2. the unit
obj = OUT / 'CRobloxReportSubViews.obj'
code, log = rebuild.run(tool, 'cl', FLAGS + XTP_FLAGS + ['/Fo' + str(obj), str(ROOT / 'rebuild/2008-06/native-classes/CRobloxReportSubViews.cpp')], OUT)
assert code == 0, log[-3000:]
raw = obj.read_bytes()
present = {n for n, b, r in match.coff_functions(raw)}

D, P = 'CRobloxReportDocView', 'CRobloxReportPaneView'
original = Original()
INTERNAL = {
    # CRobloxReportView receipt (work/2008-06/shared-layouts/roblox-report-view-working.json)
    '??0CRobloxReportView@@QAE@XZ': 0x457a40,
    '??1CRobloxReportView@@UAE@XZ': 0x458b70,
    '?GetThisClass@CRobloxReportView@@SGPAUCRuntimeClass@@XZ': 0x455d50,      # fold of GetRuntimeClass 00455d50
    '?GetThisMessageMap@CRobloxReportView@@KGPBUAFX_MSGMAP@@XZ': 0x457010,    # fold of GetMessageMap 00457010
    '?classCRobloxReportView@CRobloxReportView@@2UCRuntimeClass@@B': 0x818348,
    # own near-miss in the CRobloxReportView unit (open, early-return cleanup layout only); bound by call site
    '?setDataModel@CRobloxReportView@@QAEXV?$shared_ptr@VDataModel@RBX@@@boost@@@Z': 0x458700,
    # ActiveDocView receipts (active-doc-view-working-probe.json, pane-callbacks)
    '??0ActiveDocView@@QAE@XZ': 0x405d50,
    '??1ActiveDocView@@QAE@XZ': 0x405d80,
    '?setActiveDocument@@YAX_NPAVCRobloxDoc@@@Z': 0x405aa0,
    '?activeDocDataModel@@3V?$shared_ptr@VDataModel@RBX@@@boost@@A': 0x96c25c,
    # CRobloxDoc document receipt
    '?getDataModel@CRobloxDoc@@QAE?AV?$shared_ptr@VDataModel@RBX@@@boost@@XZ': 0x403040,
    # own data
    '?class%s@%s@@2UCRuntimeClass@@B' % (D, D): 0x818364,
    '?class%s@%s@@2UCRuntimeClass@@B' % (P, P): 0x818380,
    '??_7%s@@6BCXTPReportView@@@' % D: 0x818c94,
    '??_7%s@@6B?$MarshaledListener@VInstance@RBX@@UChildAdded@2@V12@U32@@RBX@@@' % D: 0x818c7c,
    '??_7%s@@6B?$MarshaledListener@VInstance@RBX@@UChildRemoved@2@V12@U32@@RBX@@@' % D: 0x818c68,
    '??_7%s@@6BCXTPReportView@@@' % P: 0x818e7c,
    '??_7%s@@6B?$MarshaledListener@VInstance@RBX@@UChildAdded@2@V12@U32@@RBX@@@' % P: 0x818e64,
    '??_7%s@@6B?$MarshaledListener@VInstance@RBX@@UChildRemoved@2@V12@U32@@RBX@@@' % P: 0x818e50,
    '??_7%s@@6B@' % P: 0x819038,   # ActiveDocView-path vtable (MSVC names it 6B@ here)
    '?messageMap@?1??GetThisMessageMap@%s@@KGPBUAFX_MSGMAP@@XZ@4U3@B' % P: 0x818800,
    '?_messageEntries@?1??GetThisMessageMap@%s@@KGPBUAFX_MSGMAP@@XZ@4QBUAFX_MSGMAP_ENTRY@@B' % P: 0x818808,
}
METHODS = [
    ('?GetRuntimeClass@%s@@UBEPAUCRuntimeClass@@XZ' % D, 0x455d40),
    ('?OnActivateView@%s@@UAEXHPAVCView@@0@Z' % D, 0x456310),
    ('?CreateObject@%s@@SGPAVCObject@@XZ' % D, 0x458d80),
    ('?GetRuntimeClass@%s@@UBEPAUCRuntimeClass@@XZ' % P, 0x455d60),
    ('?GetMessageMap@%s@@MBEPBUAFX_MSGMAP@@XZ' % P, 0x457020),
    ('??0%s@@QAE@XZ' % P, 0x458c80),
    ('??1%s@@UAE@XZ' % P, 0x458d10),
    ('??_G%s@@UAEPAXI@Z' % P, 0x458e50),
    ('??_E%s@@WDHI@AEPAXI@Z' % P, 0x458d00),
    ('??_E%s@@WDJM@AEPAXI@Z' % P, 0x458cf0),
    ('?CreateObject@%s@@SGPAVCObject@@XZ' % P, 0x458df0),
    ('?OnInitialUpdate@%s@@UAEXXZ' % P, 0x458a00),
    ('?update@%s@@UAEXV?$shared_ptr@VDataModel@RBX@@@boost@@0@Z' % P, 0x458a90),
]
# identical-COMDAT folds: same bytes and targets as a body already in the image
FOLDS = [
    ('?GetThisClass@%s@@SGPAUCRuntimeClass@@XZ' % D, 0x455d40),
    ('?GetThisClass@%s@@SGPAUCRuntimeClass@@XZ' % P, 0x455d60),
    ('?GetThisMessageMap@%s@@KGPBUAFX_MSGMAP@@XZ' % P, 0x457020),
    # the doc view adds no members: its deleting destructor and listener thunks are the base's bodies
    ('??_G%s@@UAEPAXI@Z' % D, 0x458d60),
    ('??_E%s@@WDHI@AEPAXI@Z' % D, 0x457ad0),
    ('??_E%s@@WDJM@AEPAXI@Z' % D, 0x457ae0),
]
OWN = dict(METHODS + FOLDS)
OWN['??_E%s@@UAEPAXI@Z' % D] = 0x458d60   # weak alias of ??_G (no array new)
OWN['??_E%s@@UAEPAXI@Z' % P] = 0x458e50
OWN['??1%s@@UAE@XZ' % D] = 0x458b70        # implicit destructor: jmp ~CRobloxReportView (inlined into ??_G)
import os
if os.environ.get('DISCOVER'):
    for n, a in METHODS + FOLDS:
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

# Non-exact by construction: _GetBaseClass (IMPLEMENT_DYNCREATE under _AFXDLL). In the original the leaves share the
# CRobloxReportView unit (their bodies sit between its functions), so RUNTIME_CLASS(CRobloxReportView) inlines and the
# CRuntimeClass base getter is the GetRuntimeClass body 00455d50; this separate unit emits jmp GetThisClass instead.
bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
sections, symbols, definitions, _ = match._coff_data_index(raw)
def relocations(section):
    table = sections[section]
    return [struct.unpack_from('<IIH', raw, table[5] + 10 * i) for i in range(table[7])]
cross_unit = []
for cls in (D, P):
    name = '?_GetBaseClass@%s@@KGPAUCRuntimeClass@@XZ' % cls
    b, r = bodies[name]
    start, section = definitions[name]
    target = [symbols[i][0] for o, i, kind in relocations(section) if o == start + 1 and kind == 20]
    assert b[:1] == b'\xe9' and len(b) == 5 and target == ['?GetThisClass@CRobloxReportView@@SGPAUCRuntimeClass@@XZ'], (name, b.hex(), target)
    cross_unit.append({'symbol': name, 'address': '00455d50', 'status': 'open (same-unit inline in the original)',
                       'local': 'jmp ' + target[0], 'original': original.data(0x455d50, 6).hex()})
assert original.data(0x455d50, 6) == bytes.fromhex('b848838100c3')   # mov eax, classCRobloxReportView; ret

# 3. vtables: own slots must equal OWN; every inherited slot must hold the CRobloxReportView vtable's value at the
# same index (that vtable is verified by record_native_roblox_report_view.py) and reference a non-leaf symbol.
vt = {v['vtable']: v for v in json.loads((ROOT / 'work/2008-06/vtables.json').read_text())}
BASE = {'CXTPReportView': 0x81888c, 'ChildAdded': 0x818878, 'ChildRemoved': 0x818864}
vtables = {}
for name, address in INTERNAL.items():
    if not name.startswith('??_7'):
        continue
    cls = D if D in name else P
    count = len(vt['%08x' % address]['slots'])
    start, section = definitions[name]
    slots = {(o - start) // 4: symbols[i][0] for o, i, _ in relocations(section) if start <= o < start + count * 4}
    values = struct.unpack('<%dI' % count, original.data(address, count * 4))
    assert len(slots) == count, (name, len(slots), count)
    base = next((a for k, a in BASE.items() if '6B' + k in name or '@U' + k + '@' in name), None)
    base_values = struct.unpack('<%dI' % count, original.data(base, count * 4)) if base else None
    result = {'own': {}, 'inherited': 0}
    for slot, symbol in sorted(slots.items()):
        value = values[slot]
        if symbol in OWN:
            assert OWN[symbol] == value, (name, slot, symbol, hex(value))
            result['own'][slot] = (symbol, hex(value))
        else:
            assert '@' + cls + '@@' not in symbol, (name, slot, symbol)
            assert base_values and base_values[slot] == value, (name, slot, symbol, hex(value))
            result['inherited'] += 1
    rtti, off = original.vtable_class(address)
    assert rtti == '.?AV%s@@' % cls, (name, rtti)
    vtables[name] = dict(result, address='%08x' % address, slots=count, col_offset=hex(off))

# 4. CRuntimeClass records: name, size, schema 0xffff, CreateObject, base getter 00455d50
for address, cls, size, create in ((0x818364, D, 0x3d4, 0x458d80), (0x818380, P, 0x3d8, 0x458df0)):
    rec = struct.unpack('<IiIIII', original.data(address, 24))
    assert original.string(rec[0]) == cls and rec[1:5] == (size, 0xffff, create, 0x455d50), (cls, rec)
    assert OWN['?CreateObject@%s@@SGPAVCObject@@XZ' % cls] == create

# 5. pane message map 00818800: base getter = CRobloxReportView::GetThisMessageMap fold 00457010, terminator only
base_getter, entries = struct.unpack('<II', original.data(0x818800, 8))
assert (base_getter, entries) == (0x457010, 0x818808)
assert struct.unpack('<6I', original.data(entries, 24)) == (0,) * 6
name = '?_messageEntries@?1??GetThisMessageMap@%s@@KGPBUAFX_MSGMAP@@XZ@4QBUAFX_MSGMAP_ENTRY@@B' % P
start, section = definitions[name]
assert struct.unpack_from('<6I', raw, sections[section][4] + start) == (0,) * 6

paths = [Path(__file__).resolve(), HERE / 'native_bind.py', HERE / 'NativeRobloxReportSubViewsLayout.cpp',
         ROOT / 'rebuild/2008-06/native-classes/CRobloxReportSubViews.cpp', ROOT / 'rebuild/2008-06/native-headers/CRobloxReportSubViews.h',
         ROOT / 'rebuild/2008-06/native-headers/CRobloxReportView.h', ROOT / 'rebuild/2008-06/native-headers/ActiveDocView.h']
receipt = {
    'classes': [D, P], 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'profile': 'document-swap flags + XTP 11.2.2 headers (/UNOMINMAX /D_XTP_STATICLINK)',
    'original_sha256': sha(original.path), 'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'object_sha256': sha(obj), 'methods': rows, 'open': cross_unit, 'vtables': vtables,
}
(ROOT / 'work/2008-06/shared-layouts/report-sub-views-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native CRobloxReportDocView/CRobloxReportPaneView: %d exact rows (%d folds), %d open' % (
    len(rows), len(FOLDS), len(cross_unit)))
for k, v in vtables.items():
    print(k[:70], v['slots'], 'own', len(v['own']), 'inherited', v['inherited'])
