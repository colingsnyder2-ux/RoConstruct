"""Verify the inactive native CMemberTreeView (object browser member pane): layout test, exact bodies, every call/data
target, both vtables, the CRuntimeClass record and the message map; then rebuild CClassTreeView.cpp (copy; only the setItemStyle parameter type changed)
against the changed shared headers in this directory and re-check its bodies (no regression).
Profile: document-swap flags + XTP 11.2.2 headers, through the noinline profile for CString operator PCXSTR and
std::string::c_str (imported in the original). Scratch-only: outputs go to ./out.
Header overrides in this directory (describe as shared-header changes): CClassTreeView.h (CMemberTreeView block moved to
CMemberTreeView.h), CReflectionTreeView.h (setItemStyle takes Metadata::Item*), reflection/Metadata.h (Member + three
member lookups), reflection/property.h (inline isPublic), reflection/function.h (inline getSignature).
"""
import json
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(ROOT / 'rebuild/2008-06/tests'))
import native_bind  # noqa: E402
from native_bind import XTP_FLAGS, Original, match, rebuild, sha, verify  # noqa: E402
import class_tree_view_profile as probe  # noqa: E402

OUT = probe.OUT
tool = rebuild.toolchain(21022)
FLAGS = probe.FLAGS

# 1. layout test
layout = OUT / 'NativeMemberTreeViewLayout.obj'
code, log = rebuild.run(tool, 'cl', FLAGS + XTP_FLAGS + ['/Fo' + str(layout),
                                                       str(HERE / 'NativeMemberTreeViewLayout.cpp')], OUT)
assert code == 0, log[-3000:]
assert dict((n, b) for n, b, r in match.coff_functions(layout.read_bytes()))['?treeBaseOffset@@YAHXZ'] == bytes.fromhex('b860000000c3')

# 2. the unit
obj = probe.build('CMemberTreeView')

# 3. XTP bodies (reuse the CClassTreeView receipt's compiled XTP units when present)
XTP_SRC = ROOT / 'tools/libs/xtp-11.2.2/Source'
xtp_bodies = {}
for rel in ('Controls/XTTreeCtrlView.cpp', 'Controls/XTTreeBase.cpp', 'Controls/XTGlobal.cpp', 'Common/XTPImageManager.cpp'):
    o = OUT / ('xtp_' + Path(rel).stem + '.obj')
    if not o.exists():
        base = ['/nologo', '/c', '/O2', '/MD', '/GS', '/EHsc', '/Ob1', '/D_AFXDLL', '/D_XTP_STATICLINK', '/D_DLL',
                '/I' + str(XTP_SRC), '/I' + str(ROOT / 'tools/libs/mfc-9.0/atlmfc/include')]
        code, log = rebuild.run(tool, 'cl', base + ['/Fo' + str(o), str(XTP_SRC / rel)], OUT)
        if code:
            code, log = rebuild.run(tool, 'cl', base + ['/I' + str(ROOT / 'tools/libs/mfc-9.0/atlmfc/src/mfc'),
                                                        '/FIXTToolkitPro.h', '/FIafximpl.h', '/Fo' + str(o), str(XTP_SRC / rel)], OUT)
        assert code == 0, (rel, log[-2000:])
    for n, b, r in match.coff_functions(o.read_bytes()):
        xtp_bodies.setdefault(n, (b, r))

XTP_TARGETS = {
    '??0CXTTreeView@@IAE@XZ': 0x6dbcd0,
    '??1CXTTreeView@@MAE@XZ': 0x6dbd00,
    '?GetThisClass@CXTTreeView@@SGPAUCRuntimeClass@@XZ': 0x6dbaa0,
    '?GetThisMessageMap@CXTTreeView@@KGPBUAFX_MSGMAP@@XZ': 0x6dbab0,
    '?GetItemState@CXTTreeBase@@QBEIPAU_TREEITEM@@I@Z': 0x6dcd30,
    '?SelectItem@CXTTreeBase@@QAEHPAU_TREEITEM@@@Z': 0x6dcd80,
    '?SetItemState@CXTTreeBase@@QAEHPAU_TREEITEM@@II@Z': 0x6dca00,
    '?OnNotify@CXTTreeBase@@MAEHIJPAJ@Z': 0x6dc070,
    '?PreTranslateMessage@CXTTreeBase@@MAEHPAUtagMSG@@@Z': 0x6dd610,
    '?GetBitmapMaskColor@CXTPImageManager@@SAKAAVCBitmap@@VCPoint@@@Z': 0x6bbed0,
}
xtp_proof = {}
for symbol, address in XTP_TARGETS.items():
    t, tr, _ = match.target('2008-06', '%08x' % address)
    hit = xtp_bodies.get(symbol)
    xtp_proof[symbol] = 'XTP recipe body exact' if hit and match.exact_match(t, tr, hit[0], hit[1]) else 'bound by call site only'

original = Original()
AUTH_SINGLETON = '?singleton@?$GlobalSettingsItem@VAuthoringSettings@@$1?sAuthoringSettings@@3PADA@RBX@@SAAAVAuthoringSettings@@XZ'
SET_ITEM_STYLE = '?setItemStyle@CReflectionTreeView@@IAEXPAU_TREEITEM@@PBVItem@Metadata@Reflection@RBX@@@Z'
INTERNAL = dict(XTP_TARGETS)
INTERNAL.update({
    # addProperty remains open; addFunction is checked below.
    '?addProperty@CMemberTreeView@@QAEXPBVPropertyDescriptor@Reflection@RBX@@@Z': 0x4352a0,
    '?addFunction@CMemberTreeView@@QAEXPBVFunctionDescriptor@Reflection@RBX@@@Z': 0x435680,
    AUTH_SINGLETON: 0x41fcf0,
    '?singleton@Reflection@Metadata@RBX@@SA?AV?$shared_ptr@VReflection@Metadata@RBX@@@boost@@XZ': 0x445020,
    '?lookup@Reflection@Metadata@RBX@@QBEPAVMember@213@ABVPropertyDescriptor@13@@Z': 0x443ab0,
    '?lookup@Reflection@Metadata@RBX@@QBEPAVMember@213@ABVFunctionDescriptor@13@@Z': 0x443b00,
    '?lookup@Reflection@Metadata@RBX@@QBEPAVMember@213@ABVSignalDescriptor@13@@Z': 0x443b50,
    '??0recursive_mutex@boost@@QAE@XZ': 0x563070,
    '??1recursive_mutex@boost@@QAE@XZ': 0x594cb0,
    '?do_lock@recursive_mutex@boost@@AAEXXZ': 0x563090,
    '?do_unlock@recursive_mutex@boost@@AAEXXZ': 0x5630e0,
    '_atexit': 0x6a17af,
    '?s@?1??sync@Reflection@RBX@@YAAAVrecursive_mutex@boost@@XZ@4V45@A': 0x96d194,
    '?$S1@?1??sync@Reflection@RBX@@YAAAVrecursive_mutex@boost@@XZ@4IA': 0x96d1a0,
    SET_ITEM_STYLE: 0x433ef0,
    '?compareItems@CClassTreeView@@SGHJJJ@Z': 0x4335d0,
    '?showDescriptor@CDeclarationView@@QAEXPBVDescriptor@Reflection@RBX@@@Z': 0x435860,
    '?classCMemberTreeView@CMemberTreeView@@2UCRuntimeClass@@B': 0x81253c,
    '?messageMap@?1??GetThisMessageMap@CMemberTreeView@@KGPBUAFX_MSGMAP@@XZ@4U3@B': 0x812e74,
    '?_messageEntries@?1??GetThisMessageMap@CMemberTreeView@@KGPBUAFX_MSGMAP@@XZ@4QBUAFX_MSGMAP_ENTRY@@B': 0x812e80,
    '??_7CMemberTreeView@@6BCXTTreeBase@@@': 0x81292c,
    '??_7CMemberTreeView@@6BCTreeView@@@': 0x8129b4,
})
METHODS = [
    ('??0CMemberTreeView@@QAE@XZ', 0x433670),
    ('??1CMemberTreeView@@UAE@XZ', 0x4336e0),
    ('??_GCMemberTreeView@@UAEPAXI@Z', 0x433e10),
    ('??_ECMemberTreeView@@WGA@AEPAXI@Z', 0x433740),
    ('?CreateObject@CMemberTreeView@@SGPAVCObject@@XZ', 0x433db0),
    ('?GetRuntimeClass@CMemberTreeView@@UBEPAUCRuntimeClass@@XZ', 0x433660),
    ('?_GetBaseClass@CMemberTreeView@@KGPAUCRuntimeClass@@XZ', 0x433650),
    ('?GetMessageMap@CMemberTreeView@@MBEPBUAFX_MSGMAP@@XZ', 0x436040),
    ('?OnInitialUpdate@CMemberTreeView@@UAEXXZ', 0x4334f0),
    ('?OnCreate@CMemberTreeView@@QAEHPAUtagCREATESTRUCTA@@@Z', 0x433e30),
    ('?createImageList@@YAHAAVCImageList@@I@Z', 0x433ab0),
    ('?OnSelChanged@CMemberTreeView@@QAEXPAUtagNMHDR@@PAJ@Z', 0x435e70),
    ('?addEnumItem@CMemberTreeView@@QAEXPBVDescriptor@Reflection@RBX@@@Z', 0x433ea0),
    ('?showEnum@CMemberTreeView@@QAEXPBVEnumDescriptor@Reflection@RBX@@@Z', 0x435180),
    ('?showClass@CMemberTreeView@@QAEXPBVClassDescriptor@Reflection@RBX@@@Z', 0x435c80),
    ('?addSignal@CMemberTreeView@@QAEXPBVSignalDescriptor@Reflection@RBX@@@Z', 0x4353e0),
    ('?addFunction@CMemberTreeView@@QAEXPBVFunctionDescriptor@Reflection@RBX@@@Z', 0x435680),
    ('?appendArgument@@YAXAAHAAV?$basic_string', 0x435510),
    ('??$for_each@V?$_Const_iterator@$00@?$list@UItem@SignatureDescriptor', 0x435630),
    ('?sync@Reflection@RBX@@YAAAVrecursive_mutex@boost@@XZ', 0x433860),
    ('??__Fs@?1??sync@Reflection@RBX@@YAAAVrecursive_mutex@boost@@XZ@YAXXZ', 0x7fa9e0),
    # DECLATE_TREE_BASE(CXTTreeViewBase, CTreeView, CXTTreeBase) inline virtuals: same COMDAT bodies as CClassTreeView's
    ('?PreSubclassWindow@CXTTreeViewBase@@MAEXXZ', 0x4337c0),
    ('?PreCreateWindow@CXTTreeViewBase@@MAEHAAUtagCREATESTRUCTA@@@Z', 0x4337e0),
    ('?GetItemState@CXTTreeViewBase@@UBEIPAU_TREEITEM@@I@Z', 0x433760),
    ('?SelectItem@CXTTreeViewBase@@UAEHPAU_TREEITEM@@@Z', 0x433770),
    ('?SetItemState@CXTTreeViewBase@@UAEHPAU_TREEITEM@@II@Z', 0x433780),
    ('?OnNotify@CXTTreeViewBase@@MAEHIJPAJ@Z', 0x4337a0),
    ('?PreTranslateMessage@CXTTreeViewBase@@MAEHPAUtagMSG@@@Z', 0x4337b0),
    ('?PreTranslateMessage@CXTTreeViewBase@@OGA@AEHPAUtagMSG@@@Z', 0x433840),
    ('?OnNotify@CXTTreeViewBase@@OGA@AEHIJPAJ@Z', 0x433850),
    ('?OnCreate@CXTTreeViewBase@@IAEHPAUtagCREATESTRUCTA@@@Z', 0x433810),
]
present = {n for n, b, r in match.coff_functions(obj.read_bytes())}
def resolve(rows):
    return [(n if n in present else next(p for p in sorted(present) if p.startswith(n)), a) for n, a in rows]
METHODS = resolve(METHODS)
# the four vector for_each instances (enum items, properties, functions, signals) are identical-COMDAT folded at 00434ed0
FOLDED = [(p, 0x434ed0) for p in sorted(present) if p.startswith('??$for_each@V?$_Vector_const_iterator@P')]
assert len(FOLDED) == 4, FOLDED
OWN = dict(METHODS + FOLDED)
OWN['??_ECMemberTreeView@@UAEPAXI@Z'] = 0x433e10  # weak alias of ??_G (no array new of the class)
# Bodies owned by other units in the original, emitted here as COMDATs: exact copies prove the binding.
DEPENDENCIES = resolve([
    ('?_ImageList_AddMasked@CComCtlWrapper@@QAEHPAU_IMAGELIST@@PAUHBITMAP__@@K@Z', 0x4130d0),
    ('??1CGdiObject@@UAE@XZ', 0x4111a0),
])
OWN.update(DEPENDENCIES)
rows = verify(original, obj, METHODS, INTERNAL, OWN)
rows += verify(original, obj, FOLDED, INTERNAL, OWN)
dependency_rows = []
bodies = {n: (b, r) for n, b, r in match.coff_functions(obj.read_bytes())}
for name, address in DEPENDENCIES:
    t, tr, _ = match.target('2008-06', '%08x' % address)
    if not match.exact_match(t, tr, *bodies[name]):
        dependency_rows.append({'address': '%08x' % address, 'symbol': name, 'exact': False,
                                'note': 'COMDAT of another unit/flag set: bound by call site and name only'})
        continue
    site_only = {}
    for _ in range(8):
        try:
            r = verify(original, obj, [(name, address)], dict(INTERNAL, **site_only), OWN)
            break
        except AssertionError as e:
            _, symbol, value = e.args[0]
            site_only[symbol] = int(value, 16)
    r[0].update(role='dependency body (binding proof; owned by another unit)', call_site_only={k: hex(v) for k, v in site_only.items()})
    dependency_rows += r
auth = json.loads((ROOT / 'work/2008-06/shared-layouts/class-tree-view-working.json').read_text())
for path, expected in auth['sources'].items():
    assert sha(ROOT / path) == expected, path
assert any(r['address'] == '0041fcf0' and r['symbol'] == AUTH_SINGLETON and r['exact'] for r in auth['dependencies'])

# 4. vtables
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
def relocations(section):
    table = sections[section]
    return [struct.unpack_from('<IIH', raw, table[5] + 10 * i) for i in range(table[7])]
vtables = {}
for name, address, count in (('??_7CMemberTreeView@@6BCTreeView@@@', 0x8129b4, 104), ('??_7CMemberTreeView@@6BCXTTreeBase@@@', 0x81292c, 33)):
    start, section = definitions[name]
    slots = {(offset - start) // 4: symbols[index][0] for offset, index, _ in relocations(section) if start <= offset < start + count * 4}
    values = struct.unpack('<%dI' % count, original.data(address, count * 4))
    assert len(slots) == count, (name, len(slots))
    result = {'verified': 0, 'xtp': {}, 'unverified': {}}
    for slot, symbol in sorted(slots.items()):
        value = values[slot]
        if symbol in OWN:
            assert OWN[symbol] == value, (name, slot, symbol, hex(value))
            result['verified'] += 1
            continue
        hit = original.imported(value)
        if hit is not None:
            assert hit[1] == native_bind.plain(symbol), (name, slot, symbol, hit)
            result['verified'] += 1
            continue
        t, tr, _ = match.target('2008-06', '%08x' % value)
        b = xtp_bodies.get(symbol)
        if b and match.exact_match(t, tr, b[0], b[1]):
            result['xtp'][slot] = (symbol, hex(value))
            result['verified'] += 1
        else:
            result['unverified'][slot] = (symbol, hex(value))
    vtables[name] = dict(result, address='%08x' % address, slots=count)
    rtti, off = original.vtable_class(address)
    assert rtti == '.?AVCMemberTreeView@@' and off == (0 if address == 0x8129b4 else 0x60), (rtti, off)

# 5. CRuntimeClass 0081253c: name, size 0xb4, schema 0xffff, CreateObject 00433db0, base getter 00433650
rec = struct.unpack('<IiIIII', original.data(0x81253c, 24))
assert original.string(rec[0]) == 'CMemberTreeView' and rec[1:5] == (0xb4, 0xffff, 0x433db0, 0x433650), rec
assert original.data(0x433650, 1) == b'\xe9' and 0x433655 + struct.unpack('<i', original.data(0x433651, 4))[0] == 0x6dbaa0
name = '?classCMemberTreeView@CMemberTreeView@@2UCRuntimeClass@@B'
start, section = definitions[name]
mine = struct.unpack_from('<IiIIII', raw, sections[section][4] + start)
assert mine[1:3] == (0xb4, 0xffff), mine

# 6. message map 00812e74: CXTTreeView base getter, ON_WM_CREATE -> 00433e30, ON_NOTIFY_REFLECT(TVN_SELCHANGED) -> 00435e70
base_getter, entries = struct.unpack('<II', original.data(0x812e74, 8))
assert (base_getter, entries) == (0x6dbab0, 0x812e80)
expected = [(0x1, 0, 0, 0, 13, 0x433e30), (0xbc4e, 0xfe6e, 0, 0, 61, 0x435e70), (0, 0, 0, 0, 0, 0)]
assert [struct.unpack('<6I', original.data(entries + 24 * i, 24)) for i in range(3)] == expected
name = '?_messageEntries@?1??GetThisMessageMap@CMemberTreeView@@KGPBUAFX_MSGMAP@@XZ@4QBUAFX_MSGMAP_ENTRY@@B'
start, section = definitions[name]
mine = [struct.unpack_from('<6I', raw, sections[section][4] + start + 24 * i) for i in range(3)]
handlers = {(offset - start) // 24: symbols[index][0] for offset, index, _ in relocations(section) if start <= offset < start + 72}
assert [m[:5] for m in mine] == [e[:5] for e in expected], mine
assert OWN[handlers[0]] == 0x433e30 and OWN[handlers[1]] == 0x435e70, handlers

# 7. no regression: CClassTreeView.cpp (copy; only the setItemStyle parameter type changed) against the changed headers, CClassTreeView noinline profile
class_obj = probe.build('CClassTreeView')
class_funcs = {n: (b, r) for n, b, r in match.coff_functions(class_obj.read_bytes())}
class_rows = {}
for sym, address in (('??0CClassTreeView@@QAE@XZ', 0x4338d0), ('??1CClassTreeView@@UAE@XZ', 0x4333b0),
                     ('?OnCreate@CClassTreeView@@QAEHPAUtagCREATESTRUCTA@@@Z', 0x433e30),
                     ('?OnSelChanged@CClassTreeView@@QAEXPAUtagNMHDR@@PAJ@Z', 0x435fa0),
                     ('?OnInitialUpdate@CClassTreeView@@UAEXXZ', 0x435eb0),
                     ('?addClass@CClassTreeView@@QAEXPBVClassDescriptor@Reflection@RBX@@@Z', 0x434ff0),
                     ('?addEnum@CClassTreeView@@QAEXPBVEnumDescriptor@Reflection@RBX@@@Z', 0x433d00),
                     ('?compareItems@CClassTreeView@@SGHJJJ@Z', 0x4335d0), ('?rank@@YAHPBVDescriptor@Reflection@RBX@@@Z', 0x433500),
                     (SET_ITEM_STYLE, 0x433ef0)):
    t, tr, _ = match.target('2008-06', '%08x' % address)
    class_rows['%08x' % address] = bool(sym in class_funcs and match.exact_match(t, tr, *class_funcs[sym]))
assert all(class_rows.values()), class_rows

H = ROOT / 'rebuild/2008-06/native-headers'
paths = [Path(__file__), HERE / 'class_tree_view_profile.py', ROOT / 'rebuild/2008-06/native-classes/CMemberTreeView.cpp', H / 'CMemberTreeView.h', H / 'CClassTreeView.h',
         H / 'CReflectionTreeView.h', H / 'reflection/Metadata.h', HERE / 'NativeMemberTreeViewLayout.cpp']
paths += [H / 'reflection/function.h', H / 'reflection/signal.h']
receipt = {
    'class': 'CMemberTreeView',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'profile': 'document-swap flags + XTP 11.2.2 headers (/UNOMINMAX /D_XTP_STATICLINK); noinline: CString operator PCXSTR; std::string::c_str; EnumDescriptor enumsBegin/enumsEnd (shared class_tree_view_profile)',
    'open': ['addProperty 004352a0 still needs the original inline PropertyDescriptor::isPublic path.'],
    'original_sha256': sha(ROOT / 'work/2008-06/original-p4-reference/Roblox.exe'),
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'object_sha256': sha(obj),
    'layout': {'size': '0xb4', 'bases': 'CReflectionTreeView (novtable, no data) : CXTTreeView (0xa0) : CXTTreeViewBase : CTreeView @0 + CXTTreeBase @0x60',
               'images': '0xa0 (CImageList)', 'showInherited': '0xa8 (bool)', 'current': '0xac (const Descriptor*)',
               'declarationView': '0xb0 (CDeclarationView*)',
               'evidence': 'CRuntimeClass 0081253c size and CreateObject 00433db0 new(0xb4); RTTI; constructor 00433670 and destructor 004336e0; '
                           'OnSelChanged 00435e70 (+0xb0); member adders (+0xa8 byte test, +0xac compare with owner); compile-time layout test'},
    'methods': rows,
    'dependencies': dependency_rows,
    'xtp_targets': xtp_proof,
    'vtables': vtables,
    'runtime_class': {'address': '0081253c', 'size': '0xb4', 'create': '00433db0', 'base_getter': '00433650 -> 006dbaa0'},
    'message_map': {'address': '00812e74', 'entries': [{'message': 'WM_CREATE', 'handler': '00433e30'},
                                                       {'message': 'WM_NOTIFY reflect', 'code': 'TVN_SELCHANGED', 'handler': '00435e70'}]},
    'class_tree_view_regression': class_rows,
}
(ROOT / 'work/2008-06/shared-layouts/member-tree-view-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native CMemberTreeView: %d exact rows; vtables %s; CClassTreeView regression %d/%d exact' % (
    len(rows), {k: (v['verified'], len(v['unverified'])) for k, v in vtables.items()}, sum(class_rows.values()), len(class_rows)))
print(json.dumps(xtp_proof, indent=1))
for r in dependency_rows:
    print(r['address'], r['exact'], r.get('note', ''), r.get('call_site_only', ''))
for k, v in vtables.items():
    print(k, 'unverified', v['unverified'])
