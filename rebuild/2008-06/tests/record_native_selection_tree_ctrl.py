"""Verify the inactive native CSelectionTreeCtrl unit (CRobloxTreeCtrl base, XTP 11.2.2): layout test, exact bodies
with every call/data target, the vtables, the CRuntimeClass record and the message map.

Profile: document-swap flags + XTP 11.2.2 headers (/UNOMINMAX /D_XTP_STATICLINK); the unit is preprocessed and the
.i compiled with /O2 /Ob2 /Oy /GF /GS- /EHsc /MD (as record_native_roblox_tree_ctrl.py). Rows that call functions the
committed shared headers do not declare are compiled under NATIVE_TREE_PENDING_SELECTION / _NODE / _DROP with, for
this verification only, the proposed declaration-only changes applied to the preprocessed text; they are reported as
exact-pending-header. Writes work/2008-06/shared-layouts/selection-tree-ctrl-working.json.
"""
import json
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(HERE))
import native_bind  # noqa: E402
from native_bind import XTP_FLAGS, Original, flags, match, rebuild, sha  # noqa: E402

OUT = ROOT / 'rebuild/2008-06/out/native-layouts/selection-tree-ctrl'; OUT.mkdir(parents=True, exist_ok=True)
tool = rebuild.toolchain(21022)
FLAGS = flags()
INC = []
names = json.load(open(ROOT / 'rebuild/2008-06/offline/evidence.json'))['names']

# 1. layout test
layout = OUT / 'NativeSelectionTreeCtrlLayout.obj'
code, log = rebuild.run(tool, 'cl', INC + FLAGS + XTP_FLAGS + ['/Fo' + str(layout), str(HERE / 'NativeSelectionTreeCtrlLayout.cpp')], OUT)
assert code == 0, log[-3000:]
lb = dict((n, b) for n, b, r in match.coff_functions(layout.read_bytes()))
assert lb['?treeBaseOffset@@YAHXZ'] == bytes.fromhex('b854000000c3')
assert lb['?activeDocViewOffset@@YAHXZ'] == bytes.fromhex('b8d0000000c3')
assert lb['?selectionListenerOffset@@YAHXZ'] == bytes.fromhex('b8d4000000c3')

# 2. the unit: plain profile and pending-header profile
SELECTION = ('    void addToSelection(Instance*);',
             '    void addToSelection(Instance*); bool isSelected(const Instance*) const; '
             'void removeFromSelection(const Instance*); void setSelection(Instance*); '
             'std::vector<boost::shared_ptr<Instance> >::const_iterator begin() const; '
             'std::vector<boost::shared_ptr<Instance> >::const_iterator end() const;')
INSTANCE = ('Instance* getParent() const { return parent; }',
            'Instance* getParent() const { return parent; } bool isDescendentOf(const Instance*) const; '
            'bool canAcceptChildren(std::vector<boost::shared_ptr<Instance> >::const_iterator, '
            'std::vector<boost::shared_ptr<Instance> >::const_iterator);')
NODE = ('bool hasChildren();', 'bool hasChildren(); void refreshText(); void removeChildren();')
PENDING = []  # SELECTION, INSTANCE and NODE declarations are now in the shared headers
DEFINES = ['/DNATIVE_TREE_PENDING_SELECTION', '/DNATIVE_TREE_PENDING_NODE', '/DNATIVE_TREE_PENDING_DROP']


def profile(name, defines=(), replace=()):
    pre = OUT / ('pre-' + name); pre.mkdir(exist_ok=True)
    src = ROOT / 'rebuild/2008-06/native-classes/CSelectionTreeCtrl.cpp'
    code, log = rebuild.run(tool, 'cl', [x for x in FLAGS if x != '/c'] + XTP_FLAGS + INC + list(defines) + ['/P', str(src)], pre)
    assert code == 0, log[-3000:]
    body = (pre / 'CSelectionTreeCtrl.i').read_text(errors='replace')
    for old, new in replace:
        assert body.count(old) == 1, old
        body = body.replace(old, new)
    unit = OUT / (name + '.cpp'); unit.write_text(body)
    obj = OUT / (name + '.obj')
    code, log = rebuild.run(tool, 'cl', ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/Fo' + str(obj), str(unit)], OUT)
    assert code == 0, log[-3000:]
    return obj


obj = profile('NativeSelectionTreeCtrlProfile')
penobj = profile('NativeSelectionTreeCtrlPending', DEFINES, PENDING)

T = 'CSelectionTreeCtrl@@'
METHODS = [
    ('?GetRuntimeClass@' + T + 'UBEPAUCRuntimeClass@@XZ', 0x422640),
    ('?OnSelChanging@' + T + 'QAEXPAUtagNMHDR@@PAJ@Z', 0x4226e0),
    ('?Enable@CEnabledCmdUI@@UAEXH@Z', 0x422700),
    ('?showContextMenu@' + T + 'QAEXVCPoint@@@Z', 0x422720),
    ('?OnContextMenu@' + T + 'QAEXPAVCWnd@@VCPoint@@@Z', 0x4228b0),
    ('?OnButtonDown@' + T + 'MAEHHIVCPoint@@@Z', 0x4228d0),
    ('?DoPreSelection@' + T + 'MAEXPAU_TREEITEM@@HI@Z', 0x4228f0),
    ('?DoAction@' + T + 'MAEXPAU_TREEITEM@@HIVCPoint@@@Z', 0x422900),
    ('?DoBanding@' + T + 'MAEXIVCPoint@@@Z', 0x422930),
    ('?UpdateSelectionForRect@' + T + 'MAEXPBUtagRECT@@IAAV?$CTypedPtrList@VCPtrList@@PAU_TREEITEM@@@@@Z', 0x422950),
    ('?OnCmdMsg@' + T + 'UAEHIHPAXPAUAFX_CMDHANDLERINFO@@@Z', 0x422960),
    ('?OnRButtonDown@' + T + 'QAEXIVCPoint@@@Z', 0x422e50),
    ('?OnSelChanged@' + T + 'QAEXPAUtagNMHDR@@PAJ@Z', 0x423240),
    ('?OnBeginDrag@' + T + 'QAEXPAUtagNMHDR@@PAJ@Z', 0x4233d0),
    ('?OnCreate@' + T + 'QAEHPAUtagCREATESTRUCTA@@@Z', 0x4234d0),
    ('?OnMouseMove@' + T + 'QAEXIVCPoint@@@Z', 0x423d50),
    ('?onInstanceChanged@' + T + 'UAEXPBVInstance@RBX@@@Z', 0x424600),
    ('?onNodeChanged@' + T + 'UAEXPAVCRobloxTreeCtrlNode@@@Z', 0x4246d0),
    ('?onNodeDestroyed@' + T + 'UAEXPAVCRobloxTreeCtrlNode@@@Z', 0x424750),
    ('?onEvent@' + T + 'MAEXPBVSelection@RBX@@VSelectionChanged@3@@Z', 0x425810),
    ('??0' + T + 'QAE@XZ', 0x425c90),
    ('??_E' + T + 'WFE@AEPAXI@Z', 0x425d80),
    ('??_E' + T + 'WNE@AEPAXI@Z', 0x425d90),
    ('?getDataModel@' + T + 'UAE?AV?$shared_ptr@VDataModel@RBX@@@boost@@XZ', 0x425da0),
    ('??0RootNode@@QAE@ABV?$shared_ptr@VInstance@RBX@@@boost@@PAVCRobloxTreeCtrl@@@Z', 0x4265e0),
    ('?insertItem@RootNode@@UAEPAU_TREEITEM@@XZ', 0x426640),
    ('?rebuild@' + T + 'UAEXXZ', 0x426680),
    ('?findNode@' + T + 'QAEPAVCRobloxTreeCtrlNode@@ABV?$shared_ptr@VInstance@RBX@@@boost@@@Z', 0x426780),
    ('?getSelection@' + T + 'UAEPAVSelection@RBX@@XZ', 0x426bd0),
    ('?setDataModel@' + T + 'QAEXV?$shared_ptr@VDataModel@RBX@@@boost@@@Z', 0x426bf0),
    ('??1' + T + 'UAE@XZ', 0x4270c0),
    ('?update@' + T + 'UAEXV?$shared_ptr@VDataModel@RBX@@@boost@@0@Z', 0x4271e0),
    ('??_G' + T + 'UAEPAXI@Z', 0x4272d0),
    ('?GetMessageMap@' + T + 'MBEPBUAFX_MSGMAP@@XZ', 0x427300),
]
PEND = [
    ('?select@' + T + 'QAEXPAUtagTVITEMA@@_N@Z', 0x4230f0),
    ('?SelectAllIgnore@' + T + 'MAEXHPAU_TREEITEM@@@Z', 0x423510),
    ('?for_each@', 0x423ba0),
    ('?dropTarget@' + T + 'QAEPAU_TREEITEM@@PAU2@@Z', 0x423c40),
    ('?OnTimer@' + T + 'QAEXI@Z', 0x426a80),
    ('?dropInstance@@YAXPAVInstance@RBX@@V?$shared_ptr@VInstance@RBX@@@boost@@@Z', 0x426db0),
    ('?OnLButtonUp@' + T + 'QAEXIVCPoint@@@Z', 0x426ef0),
]
# Identical-COMDAT folds reached through vtables (no array new of these classes; empty overrides fold).
FOLDS = {'??_E' + T + 'UAEPAXI@Z': 0x4272d0, '??_GRootNode@@UAEPAXI@Z': 0x426660, '??_ERootNode@@UAEPAXI@Z': 0x426660,
         '?updateSelection@RootNode@@UAEXXZ': 0x47d410, '?onGetDispInfo@RootNode@@UAEXPAUtagTVDISPINFOA@@@Z': 0x70bdf0,
         '?SetCheck@CEnabledCmdUI@@UAEXH@Z': 0x70bdf0, '?SetRadio@CEnabledCmdUI@@UAEXH@Z': 0x70bdf0,
         '?SetText@CEnabledCmdUI@@UAEXPBD@Z': 0x70bdf0,
         '??_ERootNode@@W3AEPAXI@Z': 0x424b50, '??_ERootNode@@W7AEPAXI@Z': 0x426650}
# Inherited slots bound by the committed CRobloxTreeCtrl receipt (record_native_roblox_tree_ctrl.py).
INHERITED = {
    '?PreCreateWindow@CRobloxTreeCtrl@@UAEHAAUtagCREATESTRUCTA@@@Z': 0x422e10,
    '?GetNextItem@CXTTreeCtrlBase@@UBEPAU_TREEITEM@@PAU2@I@Z': 0x425ba0,
    '?GetItemState@CXTTreeCtrlBase@@UBEIPAU_TREEITEM@@I@Z': 0x425bc0,
    '?SelectItem@CXTTreeCtrlBase@@UAEHPAU_TREEITEM@@@Z': 0x425bd0,
    '?SetItemState@CXTTreeCtrlBase@@UAEHPAU_TREEITEM@@II@Z': 0x425be0,
    '?OnNotify@CXTTreeCtrlBase@@MAEHIJPAJ@Z': 0x425bf0,
    '?PreTranslateMessage@CXTTreeCtrlBase@@MAEHPAUtagMSG@@@Z': 0x425c00,
    '?Init@CXTTreeCtrlBase@@MAE_NXZ': 0x425c10,
    '?PreSubclassWindow@CXTTreeCtrlBase@@MAEXXZ': 0x425c20,
    '?PreTranslateMessage@CXTTreeCtrlBase@@OFE@AEHPAUtagMSG@@@Z': 0x425c50,
    '?OnNotify@CXTTreeCtrlBase@@OFE@AEHIJPAJ@Z': 0x425c60,
    '?onEvent@CRobloxTreeCtrlNode@@MAEXPBVInstance@RBX@@VPropertyChanged@3@@Z': 0x424dd0,
    '?onEvent@CRobloxTreeCtrlNode@@MAEXPBVInstance@RBX@@UChildAdded@3@@Z': 0x425450,
    '?onEvent@CRobloxTreeCtrlNode@@MAEXPBVInstance@RBX@@UChildRemoved@3@@Z': 0x4256c0,
    '??_ECRobloxTreeCtrlNode@@W3AEPAXI@Z': 0x424b50,
    '??_ECRobloxTreeCtrlNode@@W7AEPAXI@Z': 0x426650,
    '?initialize@CRobloxTreeCtrlNode@@UAEXXZ': 0x426010,
    '?onItemExpanded@CRobloxTreeCtrlNode@@UAEXI@Z': 0x424ae0,
}
OWN_DATA = {
    '??_7' + T + '6BCTreeCtrl@@@': 0x80fed4,
    '??_7' + T + '6BCXTTreeBase@@@': 0x80fe4c,
    '??_7' + T + '6BActiveDocView@@@': 0x810040,
    '??_7' + T + '6B?$Listener@VSelection@RBX@@VSelectionChanged@2@@RBX@@@': 0x80fe40,
    '??_7RootNode@@6B?$Listener@VInstance@RBX@@VPropertyChanged@2@@RBX@@@': 0x810060,
    '??_7RootNode@@6B?$Listener@VInstance@RBX@@UChildAdded@2@@RBX@@@': 0x810054,
    '??_7RootNode@@6B?$Listener@VInstance@RBX@@UChildRemoved@2@@RBX@@@': 0x810048,
    '??_7CEnabledCmdUI@@6B@': 0x80fbfc,
    '?classCSelectionTreeCtrl@' + T + '2UCRuntimeClass@@B': 0x80fb3c,
    '?messageMap@?1??GetThisMessageMap@' + T + 'KGPBUAFX_MSGMAP@@XZ@4U3@B': 0x8101b0,
}

original = Original()


def resolve(o, rows):
    funcs = {n: (b, r) for n, b, r in match.coff_functions(o.read_bytes())}
    out = []
    for prefix, address in rows:
        hits = [n for n in funcs if n == prefix] or [n for n in funcs if n.startswith('??$for_each@') and prefix == '?for_each@']
        assert len(hits) == 1, (prefix, hits)
        out.append((hits[0], address))
    return out


def check(o, rows, out_rows, bound, own):
    raw = o.read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    for name, address in rows:
        body, refs = bodies[name]
        target, target_refs, _ = match.target('2008-06', '%08x' % address)
        assert match.exact_match(target, target_refs, body, refs), (name, hex(address))
        start, section = definitions[name]
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
            if native_bind.LOCAL_EH.match(symbol):
                local.add(symbol); continue
            hit = original.imported(value)
            if hit is not None:
                assert hit[1] == native_bind.plain(symbol), (name, symbol, hex(value), hit)
                verified[symbol] = '%s!%s' % hit
            elif symbol.startswith('??_C@'):
                pos, at = definitions[symbol]
                literal = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
                assert original.data(value, len(literal)) == literal, (name, symbol, hex(value))
                verified[symbol] = '%s (literal %r)' % (hex(value), literal)
            elif symbol in OWN_DATA or symbol in own or symbol in INHERITED:
                want = OWN_DATA.get(symbol, own.get(symbol, INHERITED.get(symbol)))
                assert want == value, (name, symbol, hex(value), hex(want))
                verified[symbol] = '%s (own/inherited)' % hex(value)
            else:
                assert bound.setdefault(symbol, value) == value, (name, symbol, hex(value), hex(bound[symbol]))
                hint = names.get('%08x' % value, {}).get('symbol', '')
                verified[symbol] = '%s (call site; pool name %s)' % (hex(value), hint[:80] or '-')
        out_rows.append({'address': '%08x' % address, 'symbol': name, 'size': len(body), 'exact': True,
                         'verified_targets': verified, 'local_eh': sorted(local)})


methods = resolve(obj, METHODS)
pending = resolve(penobj, PEND)
own = dict(methods + pending); own.update(FOLDS)
bound, rows, pen_rows = {}, [], []
check(obj, methods, rows, bound, own)
check(penobj, pending, pen_rows, bound, own)

# 3. vtables (pending profile carries every slot body)
raw = penobj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
vtables = {}
for symbol, address in OWN_DATA.items():
    if not symbol.startswith('??_7'):
        continue
    start, section = definitions[symbol]
    table = sections[section]
    slots = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if offset >= start and (offset - start) % 4 == 0:
            slots.setdefault((offset - start) // 4, symbols[index][0])
    count = 0
    while count in slots:
        count += 1
    values = struct.unpack('<%dI' % count, original.data(address, 4 * count))
    result = {'slots': count, 'verified': 0, 'unverified': {}}
    for slot in range(count):
        name, value = slots[slot], values[slot]
        if name in own:
            assert own[name] == value, (symbol, slot, name, hex(value))
        elif name in INHERITED:
            assert INHERITED[name] == value, (symbol, slot, name, hex(value))
        elif name == '__purecall':
            assert value == 0x6a16be, (symbol, slot, hex(value))
        else:
            hit = original.imported(value)
            if hit is not None:
                assert hit[1] == native_bind.plain(name), (symbol, slot, name, hit)
            elif name in bound:
                assert bound[name] == value, (symbol, slot, name, hex(value))
            else:
                result['unverified'][slot] = (name, hex(value)); continue
        result['verified'] += 1
    vtables['%08x' % address] = result

# 4. CRuntimeClass record and message map
runtime = struct.unpack('<IiIIII', original.data(0x80fb3c, 24))
assert original.data(runtime[0], 19) == b'CSelectionTreeCtrl\0'
assert runtime[1:5] == (0x130, 0xffff, 0, 0x422630), runtime
base_getter, entries = struct.unpack('<II', original.data(0x8101b0, 8))
assert base_getter == 0x4272f0
MAP = [(0x7b, 0, 0, 0, 0x26, 0x4228b0), (0xbc4e, 0xfe6e, 0, 0, 61, 0x423240), (0xbc4e, 0xfe6f, 0, 0, 61, 0x4226e0),
       (0x204, 0, 0, 0, 0x35, 0x422e50), (0xbc4e, 0xfe69, 0, 0, 61, 0x4233d0), (0x202, 0, 0, 0, 0x35, 0x426ef0),
       (0x200, 0, 0, 0, 0x35, 0x423d50), (1, 0, 0, 0, 13, 0x4234d0), (0x113, 0, 0, 0, 0x14, 0x426a80), (0, 0, 0, 0, 0, 0)]
for i, entry in enumerate(MAP):
    assert struct.unpack('<6I', original.data(entries + 24 * i, 24)) == entry, (i, entry)
start, section = definitions['?_messageEntries@?1??GetThisMessageMap@' + T + 'KGPBUAFX_MSGMAP@@XZ@4QBUAFX_MSGMAP_ENTRY@@B']
compiled = raw[sections[section][4] + start:]
for i, entry in enumerate(MAP):
    assert struct.unpack_from('<5I', compiled, 24 * i) == entry[:5], (i, entry)

H = ROOT / 'rebuild/2008-06/native-headers'
paths = [Path(__file__), ROOT / 'rebuild/2008-06/native-classes/CSelectionTreeCtrl.cpp', H / 'CSelectionTreeCtrl.h', HERE / 'NativeSelectionTreeCtrlLayout.cpp']
receipt = {
    'class': 'CSelectionTreeCtrl (+ RootNode, CEnabledCmdUI)',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': FLAGS + XTP_FLAGS, 'profile': 'preprocessed unit, /O2 /Ob2 /Oy /GF /GS- /EHsc /MD',
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths}, 'object_sha256': sha(obj), 'pending_object_sha256': sha(penobj),
    'methods': rows, 'pending_shared_header': pen_rows,
    'call_site_bindings': {k: hex(v) for k, v in sorted(bound.items())}, 'vtables': vtables,
}
(ROOT / 'work/2008-06/shared-layouts/selection-tree-ctrl-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native CSelectionTreeCtrl: %d exact rows, %d exact pending shared headers; vtables %s'
      % (len(rows), len(pen_rows), {k: (v['verified'], v['slots'], v['unverified']) for k, v in vtables.items()}))
