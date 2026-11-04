"""Verify the inactive native CObjectBrowser (object browser view: a CView hosting two CXTSplitterWnd with the class,
member and declaration panes): layout test, exact bodies, every call/data target, the vtable, the CRuntimeClass record
and the message map.
Profile: document-swap flags + XTP 11.2.2 headers (/UNOMINMAX /D_XTP_STATICLINK), preprocessed then compiled with the
class-tree-view profile flags (no noinline needles needed), see object_browser_profile.py. The CXTSplitterWnd
constructor/destructor targets are proven by compiling XTP 11.2.2 Controls/XTSplitterWnd.cpp (xtp-11.2.2-shared-mfc
style) and matching the bodies at the bound address.
Writes work/2008-06/shared-layouts/object-browser-working.json.
OnSize 004339d0 stays open (210 vs 212 bytes): the original computes delta = cy - rect.Height() as
eax = bottom - top; esi = cy - eax, while every natural spelling tried compiles to esi = top - bottom + cy
(reassociated); everything else in the body (frame, GetRowInfo/SetRowInfo, std::min/std::max selects) is identical.
"""
import json
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(HERE))
import native_bind  # noqa: E402
from native_bind import XTP_FLAGS, Original, match, rebuild, sha, verify  # noqa: E402
import object_browser_profile as probe  # noqa: E402

OUT = probe.OUT
tool = rebuild.toolchain(21022)
FLAGS = probe.FLAGS

# 1. layout test: sizes/offsets as tiny functions, checked by their bytes (mov eax, imm32; ret)
layout = OUT / 'NativeObjectBrowserLayout.obj'
code, log = rebuild.run(tool, 'cl', FLAGS + XTP_FLAGS + ['/Fo' + str(layout), str(HERE / 'NativeObjectBrowserLayout.cpp')], OUT)
assert code == 0, log[-3000:]
layout_bodies = {n: b for n, b, r in match.coff_functions(layout.read_bytes())}
LAYOUT = {'?viewSize@@YAHXZ': 0x58, '?splitterSize@@YAHXZ': 0x118, '?objectBrowserSize@@YAHXZ': 0x288,
          '?classSplitterOffset@@YAHXZ': 0x58, '?memberSplitterOffset@@YAHXZ': 0x170, '?splitterWindowOffset@@YAHXZ': 0x20}
for n, v in LAYOUT.items():
    assert layout_bodies[n] == b'\xb8' + struct.pack('<I', v) + b'\xc3', (n, layout_bodies[n].hex())

# 2. unit
obj = probe.build()
raw = obj.read_bytes()

# 3. XTP CXTSplitterWnd bodies
XTP_SRC = ROOT / 'tools/libs/xtp-11.2.2/Source'
xtp_bodies = {}
for rel in ('Controls/XTSplitterWnd.cpp',):
    o = OUT / ('xtp_' + Path(rel).stem + '.obj')
    base = ['/nologo', '/c', '/O2', '/MD', '/GS', '/EHsc', '/Ob1', '/D_AFXDLL', '/D_XTP_STATICLINK', '/D_DLL',
            '/I' + str(XTP_SRC), '/I' + str(ROOT / 'tools/libs/mfc-9.0/atlmfc/include')]
    # recipe xtp-11.2.2-lib: Codejock's library prelude (Common/XTPDLLExports.h) and _LIB
    code, log = rebuild.run(tool, 'cl', base + ['/D_LIB', '/FICommon/XTPDLLExports.h', '/FIXTToolkitPro.h',
                                                '/Fo' + str(o), str(XTP_SRC / rel)], OUT)
    assert code == 0, (rel, log[-2000:])
    for n, b, r in match.coff_functions(o.read_bytes()):
        xtp_bodies.setdefault(n, (b, r))
XTP_TARGETS = {
    '??0CXTSplitterWnd@@QAE@XZ': 0x708c50,
    '??1CXTSplitterWnd@@UAE@XZ': 0x708280,
}
xtp_proof = {}
for symbol, address in XTP_TARGETS.items():
    t, tr, _ = match.target('2008-06', '%08x' % address)
    hit = xtp_bodies.get(symbol)
    xtp_proof[symbol] = 'XTP recipe body exact' if hit and match.exact_match(t, tr, hit[0], hit[1]) else 'bound by call site only'

original = Original()
INTERNAL = dict(XTP_TARGETS)
INTERNAL.update({
    '?classCObjectBrowser@CObjectBrowser@@2UCRuntimeClass@@B': 0x812520,
    '?messageMap@?1??GetThisMessageMap@CObjectBrowser@@KGPBUAFX_MSGMAP@@XZ@4U3@B': 0x812b64,
    '??_7CObjectBrowser@@6B@': 0x812794,
    # pane runtime classes, each verified by its own committed recorder (class-tree-view, member-tree-view, declaration-view)
    '?classCClassTreeView@CClassTreeView@@2UCRuntimeClass@@B': 0x812504,
    '?classCMemberTreeView@CMemberTreeView@@2UCRuntimeClass@@B': 0x81253c,
    '?classCDeclarationView@CDeclarationView@@2UCRuntimeClass@@B': 0x8124e8,
})
for address, name in ((0x812504, 'CClassTreeView'), (0x81253c, 'CMemberTreeView'), (0x8124e8, 'CDeclarationView')):
    assert original.string(struct.unpack('<I', original.data(address, 4))[0]) == name, name
METHODS = [
    ('??0CObjectBrowser@@QAE@XZ', 0x433420),
    ('??1CObjectBrowser@@UAE@XZ', 0x433480),
    ('??_GCObjectBrowser@@UAEPAXI@Z', 0x4339b0),
    ('?CreateObject@CObjectBrowser@@SGPAVCObject@@XZ', 0x433950),
    ('?GetRuntimeClass@CObjectBrowser@@UBEPAUCRuntimeClass@@XZ', 0x433410),
    ('?GetMessageMap@CObjectBrowser@@MBEPBUAFX_MSGMAP@@XZ', 0x4346a0),
    ('?OnCreate@CObjectBrowser@@QAEHPAUtagCREATESTRUCTA@@@Z', 0x433b80),
    ('?OnInitialUpdate@CObjectBrowser@@UAEXXZ', 0x4334f0),
    # identical-COMDAT folds: the original keeps one copy shared with other classes
    ('?_GetBaseClass@CObjectBrowser@@KGPAUCRuntimeClass@@XZ', 0x6c4cb0),              # jmp CView::GetThisClass
    ('?PreCreateWindow@CObjectBrowser@@UAEHAAUtagCREATESTRUCTA@@@Z', 0x463910),        # also CScriptEditor / CXTHexEdit
    ('?OnDraw@CObjectBrowser@@UAEXPAVCDC@@@Z', 0x70bdf0),                              # `ret 4`
]
FOLDED = {0x6c4cb0, 0x463910, 0x70bdf0}
OPEN = [('?OnSize@CObjectBrowser@@QAEXIHH@Z', 0x4339d0)]
OWN = dict(METHODS + OPEN)
OWN['??_ECObjectBrowser@@UAEPAXI@Z'] = 0x4339b0  # weak alias of ??_G (no array new of the class)
rows = verify(original, obj, METHODS, INTERNAL, OWN)
for r in rows:
    if int(r['address'], 16) in FOLDED:
        r['role'] = 'identical-COMDAT fold shared with other classes'
bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
open_rows = []
for name, address in OPEN:
    t, tr, _ = match.target('2008-06', '%08x' % address)
    b, r = bodies[name]
    ok = match.exact_match(t, tr, b, r)
    assert not ok, 'OnSize now exact: move it to METHODS'
    open_rows.append({'address': '%08x' % address, 'symbol': name, 'exact': False, 'size': len(b), 'target_size': len(t),
                      'note': 'delta = cy - rect.Height() reassociated (top - bottom + cy) vs original (cy - (bottom - top))'})

# 4. vtable 00812794 (101 slots)
sections, symbols, definitions, _ = match._coff_data_index(raw)
def relocations(section):
    table = sections[section]
    return [struct.unpack_from('<IIH', raw, table[5] + 10 * i) for i in range(table[7])]
count = 101
start, section = definitions['??_7CObjectBrowser@@6B@']
slots = {(offset - start) // 4: symbols[index][0] for offset, index, _ in relocations(section) if start <= offset < start + count * 4}
values = struct.unpack('<%dI' % count, original.data(0x812794, count * 4))
assert len(slots) == count, len(slots)
vt = {'verified': 0, 'imported': 0, 'shared_bodies': {}, 'unverified': {}}
for slot, symbol in sorted(slots.items()):
    value = values[slot]
    if symbol in OWN:
        assert OWN[symbol] == value, (slot, symbol, hex(value))
        vt['verified'] += 1
        continue
    hit = original.imported(value)
    if hit is not None:
        assert hit[1] == native_bind.plain(symbol), (slot, symbol, hit)
        vt['verified'] += 1; vt['imported'] += 1
        continue
    t, tr, _ = match.target('2008-06', '%08x' % value)
    b = bodies.get(symbol)
    if b and match.exact_match(t, tr, b[0], b[1]):
        vt['shared_bodies'][slot] = (symbol, hex(value)); vt['verified'] += 1
    else:
        vt['unverified'][slot] = (symbol, hex(value))
rtti, off = original.vtable_class(0x812794)
assert rtti == '.?AVCObjectBrowser@@' and off == 0, (rtti, off)

# 5. CRuntimeClass 00812520: name, size 0x288, schema 0xffff, CreateObject 00433950, base getter 006c4cb0
rec = struct.unpack('<IiIIII', original.data(0x812520, 24))
assert original.string(rec[0]) == 'CObjectBrowser' and rec[1:5] == (0x288, 0xffff, 0x433950, 0x6c4cb0), rec
assert original.data(0x6c4cb0, 1) == b'\xe9'
assert original.imported(0x6c4cb5 + struct.unpack('<i', original.data(0x6c4cb1, 4))[0])[1] == '?GetThisClass@CView@@SGPAUCRuntimeClass@@XZ'
start, section = definitions['?classCObjectBrowser@CObjectBrowser@@2UCRuntimeClass@@B']
mine = struct.unpack_from('<IiIIII', raw, sections[section][4] + start)
assert mine[1:3] == (0x288, 0xffff), mine

# 6. message map 00812b64: CView base getter import; ON_WM_SIZE 004339d0, ON_WM_CREATE 00433b80
base_getter, entries = struct.unpack('<II', original.data(0x812b64, 8))
assert original.imported(base_getter)[1] == '?GetThisMessageMap@CView@@KGPBUAFX_MSGMAP@@XZ'
expected = [(0x5, 0, 0, 0, 0x19, 0x4339d0), (0x1, 0, 0, 0, 0xd, 0x433b80), (0, 0, 0, 0, 0, 0)]
assert [struct.unpack('<6I', original.data(entries + 24 * i, 24)) for i in range(3)] == expected
name = '?_messageEntries@?1??GetThisMessageMap@CObjectBrowser@@KGPBUAFX_MSGMAP@@XZ@4QBUAFX_MSGMAP_ENTRY@@B'
start, section = definitions[name]
mine = [struct.unpack_from('<6I', raw, sections[section][4] + start + 24 * i) for i in range(3)]
handlers = {(offset - start) // 24: symbols[index][0] for offset, index, _ in relocations(section) if start <= offset < start + 72}
assert [m[:5] for m in mine] == [e[:5] for e in expected], mine
assert OWN[handlers[0]] == 0x4339d0 and OWN[handlers[1]] == 0x433b80, handlers

H = ROOT / 'rebuild/2008-06/native-headers'
paths = [Path(__file__).resolve(), HERE / 'object_browser_profile.py', ROOT / 'rebuild/2008-06/native-classes/CObjectBrowser.cpp',
         H / 'CObjectBrowser.h', HERE / 'NativeObjectBrowserLayout.cpp']
result = {'class': 'CObjectBrowser', 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)', 'original_sha256': sha(original.path),
          'profile': 'document-swap flags + XTP 11.2.2 headers (/UNOMINMAX /D_XTP_STATICLINK)',
          'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
          'layout_obj': sha(layout), 'unit_obj': sha(obj), 'methods': rows, 'open': open_rows, 'xtp_targets': xtp_proof,
          'vtable': dict(vt, address='00812794', slots=count), 'runtime_class': '00812520', 'message_map': '00812b64',
          'layout': {'sizeof': '0x288', 'base': 'CView (0x58)', 'classSplitter': '0x58 (CXTSplitterWnd, 0x118)',
                     'memberSplitter': '0x170 (CXTSplitterWnd)',
                     'evidence': 'CRuntimeClass 00812520 size and CreateObject new(0x288); RTTI 00812794; constructor 00433420 '
                                 'and destructor 00433480 (CXTSplitterWnd ctor/dtor on +0x58/+0x170); OnSize m_hWnd reads +0x78/+0x190'}}
(ROOT / 'work/2008-06/shared-layouts/object-browser-working.json').write_text(json.dumps(result, indent=1) + '\n')
print('PASS native CObjectBrowser: %d exact bodies, %d open, targets verified' % (len(rows), len(open_rows)))
print(json.dumps({'exact': [r['address'] for r in rows], 'open': [(r['address'], r['size'], r['target_size']) for r in open_rows],
                  'xtp': xtp_proof, 'vtable': {k: vt[k] for k in ('verified', 'imported')}, 'vtable_shared': vt['shared_bodies'],
                  'vtable_unverified': vt['unverified']}, indent=1))
