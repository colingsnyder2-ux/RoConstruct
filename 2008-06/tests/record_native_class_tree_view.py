"""Verify the inactive native CClassTreeView (object browser class pane): layout test, exact bodies, every call/data
target, both vtables, the CRuntimeClass record and the message map.
Profile: document-swap flags + XTP 11.2.2 headers, through the noinline profile for the members the original calls out
of line (CString operator PCXSTR, std::string::c_str, EnumDescriptor::enumsBegin/enumsEnd). XTP call targets are proven
by compiling the XTP 11.2.2 library units (xtp-11.2.2-shared-mfc style) and matching their bodies at the bound address.
Writes work/2008-06/shared-layouts/class-tree-view-working.json.
"""
import json
import os
import struct
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(HERE))
from native_bind import XTP_FLAGS, Original, match, rebuild, sha, verify  # noqa: E402
import class_tree_view_profile as probe  # noqa: E402

OUT = probe.OUT
tool = rebuild.toolchain(21022)
FLAGS = probe.FLAGS

# 1. layout test (compile-time sizeof/offsetof checks) and the CXTTreeBase subobject offset
layout = OUT / 'NativeClassTreeViewLayout.obj'
code, log = rebuild.run(tool, 'cl', FLAGS + XTP_FLAGS + ['/Fo' + str(layout),
                                                       str(HERE / 'NativeClassTreeViewLayout.cpp')], OUT)
assert code == 0, log[-3000:]
assert dict((n, b) for n, b, r in match.coff_functions(layout.read_bytes()))['?treeBaseOffset@@YAHXZ'] == bytes.fromhex('b860000000c3')

# 2. the unit
obj = probe.build()

# 4. XTP library bodies for the out-of-line XTP calls
XTP_SRC = ROOT / 'tools/libs/xtp-11.2.2/Source'
xtp_bodies = {}
for rel in ('Controls/XTTreeCtrlView.cpp', 'Controls/XTTreeBase.cpp', 'Controls/XTGlobal.cpp', 'Common/XTPImageManager.cpp'):
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
    '??0CXTLogFont@@QAE@XZ': 0x70ff20,
}
xtp_proof = {}
for symbol, address in XTP_TARGETS.items():
    t, tr, _ = match.target('2008-06', '%08x' % address)
    hit = xtp_bodies.get(symbol)
    xtp_proof[symbol] = 'XTP recipe body exact' if hit and match.exact_match(t, tr, hit[0], hit[1]) else 'bound by call site only'

original = Original()
AUTH_SINGLETON = '?singleton@?$GlobalSettingsItem@VAuthoringSettings@@$1?sAuthoringSettings@@3PADA@RBX@@SAAAVAuthoringSettings@@XZ'
INTERNAL = dict(XTP_TARGETS)
INTERNAL.update({
    AUTH_SINGLETON: 0x41fcf0,
    '?singleton@Reflection@Metadata@RBX@@SA?AV?$shared_ptr@VReflection@Metadata@RBX@@@boost@@XZ': 0x445020,
    '?lookup@Reflection@Metadata@RBX@@QBEPAVClass@213@ABVClassDescriptor@13@_N@Z': 0x443210,
    '??0recursive_mutex@boost@@QAE@XZ': 0x563070,
    '??1recursive_mutex@boost@@QAE@XZ': 0x594cb0,
    '?do_lock@recursive_mutex@boost@@AAEXXZ': 0x563090,
    '?do_unlock@recursive_mutex@boost@@AAEXXZ': 0x5630e0,
    '_atexit': 0x6a17af,
    '?s@?1??sync@Reflection@RBX@@YAAAVrecursive_mutex@boost@@XZ@4V45@A': 0x96d194,
    '?$S1@?1??sync@Reflection@RBX@@YAAAVrecursive_mutex@boost@@XZ@4IA': 0x96d1a0,
    '?showClass@CMemberTreeView@@QAEXPBVClassDescriptor@Reflection@RBX@@@Z': 0x435c80,
    '?showEnum@CMemberTreeView@@QAEXPBVEnumDescriptor@Reflection@RBX@@@Z': 0x435180,
    '?showDescriptor@CDeclarationView@@QAEXPBVDescriptor@Reflection@RBX@@@Z': 0x435860,
    '?classCClassTreeView@CClassTreeView@@2UCRuntimeClass@@B': 0x812504,
    '?messageMap@?1??GetThisMessageMap@CClassTreeView@@KGPBUAFX_MSGMAP@@XZ@4U3@B': 0x812ec8,
    '?_messageEntries@?1??GetThisMessageMap@CClassTreeView@@KGPBUAFX_MSGMAP@@XZ@4QBUAFX_MSGMAP_ENTRY@@B': 0x812ed0,
    '??_7CClassTreeView@@6BCXTTreeBase@@@': 0x812564,
    '??_7CClassTreeView@@6BCTreeView@@@': 0x8125ec,
})
FE = '??$for_each@V?$_Vector_const_iterator@P%sVEnumDescriptor'
METHODS = [
    ('??0CClassTreeView@@QAE@XZ', 0x4338d0),
    ('??1CClassTreeView@@UAE@XZ', 0x4333b0),
    ('??_GCClassTreeView@@UAEPAXI@Z', 0x433930),
    ('??_ECClassTreeView@@WGA@AEPAXI@Z', 0x433750),
    ('?CreateObject@CClassTreeView@@SGPAVCObject@@XZ', 0x433fc0),
    ('?GetRuntimeClass@CClassTreeView@@UBEPAUCRuntimeClass@@XZ', 0x433390),
    ('?_GetBaseClass@CClassTreeView@@KGPAUCRuntimeClass@@XZ', 0x433650),
    ('?GetMessageMap@CClassTreeView@@MBEPBUAFX_MSGMAP@@XZ', 0x436050),
    ('?OnCreate@CClassTreeView@@QAEHPAUtagCREATESTRUCTA@@@Z', 0x433e30),
    ('?createImageList@@YAHAAVCImageList@@I@Z', 0x433ab0),
    ('?OnSelChanged@CClassTreeView@@QAEXPAUtagNMHDR@@PAJ@Z', 0x435fa0),
    ('?OnInitialUpdate@CClassTreeView@@UAEXXZ', 0x435eb0),
    ('?addClass@CClassTreeView@@QAEXPBVClassDescriptor@Reflection@RBX@@@Z', 0x434ff0),
    ('?addEnum@CClassTreeView@@QAEXPBVEnumDescriptor@Reflection@RBX@@@Z', 0x433d00),
    ('?rank@@YAHPBVDescriptor@Reflection@RBX@@@Z', 0x433500),
    ('?compareItems@CClassTreeView@@SGHJJJ@Z', 0x4335d0),
    ('?setItemStyle@CReflectionTreeView@@IAEXPAU_TREEITEM@@PBVItem@Metadata@Reflection@RBX@@@Z', 0x433ef0),
    ('?sync@Reflection@RBX@@YAAAVrecursive_mutex@boost@@XZ', 0x433860),
    ('??__Fs@?1??sync@Reflection@RBX@@YAAAVrecursive_mutex@boost@@XZ@YAXXZ', 0x7fa9e0),
    ('??$for_each@V?$_Vector_const_iterator@PBVEnumDescriptor', 0x434ed0),
    # DECLATE_TREE_BASE(CXTTreeViewBase, CTreeView, CXTTreeBase) inline virtuals emitted by this unit
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
# Bodies owned by other units in the original, emitted here as COMDATs/noinline copies: exact, used as binding proof.
DEPENDENCIES = [
    ('?enumsBegin@EnumDescriptor@Reflection@RBX@@SA?AV?$_Vector_const_iterator@PBVEnumDescriptor', 0x56bff0),
    ('?enumsEnd@EnumDescriptor@Reflection@RBX@@SA?AV?$_Vector_const_iterator@PBVEnumDescriptor', 0x56c020),
    ('?rootDescriptor@ClassDescriptor@Reflection@RBX@@SAAAV123@XZ', 0x40ad20),
    ('?_ImageList_AddMasked@CComCtlWrapper@@QAEHPAU_IMAGELIST@@PAUHBITMAP__@@K@Z', 0x4130d0),
    ('??1CGdiObject@@UAE@XZ', 0x4111a0),
]
present = {n for n, b, r in match.coff_functions(obj.read_bytes())}
def resolve(rows):
    return [(n if n in present else next(p for p in sorted(present) if p.startswith(n)), a) for n, a in rows]
METHODS, DEPENDENCIES = resolve(METHODS), resolve(DEPENDENCIES)
OWN = dict(METHODS + DEPENDENCIES)
FE_CLASS = next(p for p in present if p.startswith('??$for_each@V?$_Vector_const_iterator@PAVClassDescriptor'))
OWN[FE_CLASS] = 0x434ed0
# ??_E (vector deleting destructor) is the compiler's weak alias of ??_G in this unit (no array new of the class)
OWN['??_ECClassTreeView@@UAEPAXI@Z'] = 0x433930
rows = verify(original, obj, METHODS, INTERNAL, OWN)
# identical-COMDAT fold: the ClassDescriptor* for_each instance is the same bytes at 00434ed0
rows += verify(original, obj, [(FE_CLASS, 0x434ed0)], INTERNAL, OWN)
dependency_rows = []
bodies = {n: (b, r) for n, b, r in match.coff_functions(obj.read_bytes())}
for name, address in DEPENDENCIES:
    t, tr, _ = match.target('2008-06', '%08x' % address)
    if not match.exact_match(t, tr, *bodies[name]):
        dependency_rows.append({'address': '%08x' % address, 'symbol': name, 'exact': False,
                                'note': 'COMDAT of another unit/flag set (%d vs %d bytes): bound by call site and name only' % (len(bodies[name][0]), len(t))})
        continue
    site_only = {}
    for _ in range(8):  # targets of a dependency body that no row proves are recorded as call-site bindings
        try:
            r = verify(original, obj, [(name, address)], dict(INTERNAL, **site_only), OWN)
            break
        except AssertionError as e:
            _, symbol, value = e.args[0]
            site_only[symbol] = int(value, 16)
    r[0].update(role='dependency body (binding proof; owned by another unit)',
                call_site_only={k: hex(v) for k, v in site_only.items()})
    dependency_rows += r
# Recompile singleton with current char-array template name and verify old call/data targets.
committed = json.loads((ROOT / 'work/2008-06/shared-layouts/insert-object-dialog-working.json').read_text())
old = [r for r in committed['methods'] if r['address'] == '0041fcf0' and r['exact']]
assert len(old) == 1
auth_out = OUT / 'authoring-current'
env = dict(os.environ, NATIVE_CHECK_OUT=str(auth_out))
check = subprocess.run([sys.executable, str(HERE / 'check_native_class.py'),
                        'native-classes/AuthoringSettings.cpp', '0041fcf0=' + AUTH_SINGLETON],
                       cwd=ROOT, env=env, capture_output=True, text=True, check=True)
assert '1/1 exact' in check.stdout, check.stdout
auth_bindings = {key.replace('sAuthoringSettings@@3PBDB', 'sAuthoringSettings@@3PADA'): int(value, 16)
                 for key, value in old[0]['verified_targets'].items()}
auth_rows = verify(original, auth_out / 'CheckAuthoringSettings.obj', [(AUTH_SINGLETON, 0x41fcf0)], auth_bindings)
auth_rows[0]['role'] = 'current char-array singleton and original call/data targets reverified'

# 5. vtables: same slot count; every slot this object defines binds to the original slot value (own bodies by the exact
# rows above, imports by name, XTP bodies by the recipe proof).
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
def relocations(section):
    table = sections[section]
    return [struct.unpack_from('<IIH', raw, table[5] + 10 * i) for i in range(table[7])]
xtp_all = dict(XTP_TARGETS)
vtables = {}
for name, address, count in (('??_7CClassTreeView@@6BCTreeView@@@', 0x8125ec, 104), ('??_7CClassTreeView@@6BCXTTreeBase@@@', 0x812564, 33)):
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
            assert hit[1] == __import__('native_bind').plain(symbol), (name, slot, symbol, hit)
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
    # RTTI complete-object locator names CClassTreeView at the expected subobject offset
    rtti, off = original.vtable_class(address)
    assert rtti == '.?AVCClassTreeView@@' and off == (0 if address == 0x8125ec else 0x60), (rtti, off)

# 6. CRuntimeClass 00812504: name, size 0xb0, schema 0xffff, CreateObject 00433fc0, base getter 00433650
rec = struct.unpack('<IiIIII', original.data(0x812504, 24))
assert original.string(rec[0]) == 'CClassTreeView' and rec[1:5] == (0xb0, 0xffff, 0x433fc0, 0x433650), rec
# 00433650: jmp CXTTreeView::GetThisClass 006dbaa0
assert original.data(0x433650, 1) == b'\xe9' and 0x433655 + struct.unpack('<i', original.data(0x433651, 4))[0] == 0x6dbaa0

# 7. Message map 00812ec8: CXTTreeView base getter, ON_WM_CREATE, ON_NOTIFY_REFLECT(TVN_SELCHANGED); compiled entries equal
base_getter, entries = struct.unpack('<II', original.data(0x812ec8, 8))
assert (base_getter, entries) == (0x6dbab0, 0x812ed0)
expected = [(0x1, 0, 0, 0, 13, 0x433e30), (0xbc4e, 0xfe6e, 0, 0, 61, 0x435fa0), (0, 0, 0, 0, 0, 0)]
assert [struct.unpack('<6I', original.data(entries + 24 * i, 24)) for i in range(3)] == expected
name = '?_messageEntries@?1??GetThisMessageMap@CClassTreeView@@KGPBUAFX_MSGMAP@@XZ@4QBUAFX_MSGMAP_ENTRY@@B'
start, section = definitions[name]
mine = [struct.unpack_from('<6I', raw, sections[section][4] + start + 24 * i) for i in range(3)]
handlers = {(offset - start) // 24: symbols[index][0] for offset, index, _ in relocations(section) if start <= offset < start + 72}
assert [m[:5] for m in mine] == [e[:5] for e in expected], mine
assert OWN[handlers[0]] == 0x433e30 and OWN[handlers[1]] == 0x435fa0, handlers

H = ROOT / 'rebuild/2008-06/native-headers'
paths = [Path(__file__), HERE / 'class_tree_view_profile.py', ROOT / 'rebuild/2008-06/native-classes/CClassTreeView.cpp', H / 'CClassTreeView.h', H / 'CReflectionTreeView.h',
         HERE / 'NativeClassTreeViewLayout.cpp', HERE / 'check_native_class.py',
         ROOT / 'rebuild/2008-06/native-classes/AuthoringSettings.cpp', H / 'AuthoringSettings.h']
receipt = {
    'class': 'CClassTreeView',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'profile': 'document-swap flags + XTP 11.2.2 headers (/UNOMINMAX /D_XTP_STATICLINK); noinline: ' + '; '.join(n.split('\\')[0] for n in probe.NEEDLES),
    'original_sha256': sha(ROOT / 'work/2008-06/original-p4-reference/Roblox.exe'),
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'object_sha256': sha(obj),
    'layout': {'size': '0xb0', 'bases': 'CReflectionTreeView (novtable, no data) : CXTTreeView (0xa0) : CXTTreeViewBase : CTreeView @0 + CXTTreeBase @0x60',
               'images': '0xa0 (CImageList)', 'memberView': '0xa8 (CMemberTreeView*)', 'declarationView': '0xac (CDeclarationView*)',
               'evidence': 'CRuntimeClass 00812504 size and CreateObject new(0xb0); RTTI (CReflectionTreeView between, CXTTreeBase mdisp 0x60); constructor 004338d0 and destructor 004333b0; compile-time layout test'},
    'methods': rows,
    'dependencies': dependency_rows + auth_rows,
    'xtp_targets': xtp_proof,
    'vtables': vtables,
    'runtime_class': {'address': '00812504', 'size': '0xb0', 'create': '00433fc0', 'base_getter': '00433650 -> 006dbaa0'},
    'message_map': {'address': '00812ec8', 'entries': [{'message': 'WM_CREATE', 'handler': '00433e30'},
                                                       {'message': 'WM_NOTIFY reflect', 'code': 'TVN_SELCHANGED', 'handler': '00435fa0'}]},
}
(ROOT / 'work/2008-06/shared-layouts/class-tree-view-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native CClassTreeView: %d exact rows, %d dependency rows; vtables %s' % (
    len(rows), len(dependency_rows + auth_rows), {k: (v['verified'], len(v['unverified'])) for k, v in vtables.items()}))
print(json.dumps(xtp_proof, indent=1))
for k, v in vtables.items():
    print(k, 'unverified', v['unverified'])
for r in dependency_rows + auth_rows:
    print(r['address'], r['exact'], r.get('note', ''))
