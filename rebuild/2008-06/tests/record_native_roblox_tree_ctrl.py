"""Verify the inactive native CRobloxTreeCtrl / CRobloxTreeCtrlNode unit (XTP 11.2.2 CXTTreeCtrl base): layout test,
exact bodies with every call/data target, the vtables, the CRuntimeClass record and the message map.

Profile: document-swap flags + XTP 11.2.2 headers (/UNOMINMAX /D_XTP_STATICLINK), compiled through the noinline
profile for the imported std::string::c_str (CRobloxTreeCtrlNode::onGetDispInfo 00425320 calls MSVCP90 c_str through
the IAT). onGetDispInfo's catch(...) block is a separate original function (00425425); the COFF body is split there.
CRobloxTreeCtrlNode::updateSelection 00424f80 calls Selection::isSelected (00424eb0), which the committed
v8datamodel/Selection.h does not declare: it is compiled with NATIVE_TREE_PENDING_SELECTION and, for this verification
only, the proposed declaration-only change applied to the preprocessed text; it is reported as exact-pending-header.
Writes work/2008-06/shared-layouts/roblox-tree-ctrl-working.json.
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

OUT = ROOT / 'rebuild/2008-06/out/native-layouts/roblox-tree-ctrl'; OUT.mkdir(parents=True, exist_ok=True)
tool = rebuild.toolchain(21022)
FLAGS = flags()
INC = []
names = json.load(open(ROOT / 'rebuild/2008-06/offline/evidence.json'))['names']

# 1. layout test
layout = OUT / 'NativeRobloxTreeCtrlLayout.obj'
code, log = rebuild.run(tool, 'cl', INC + FLAGS + XTP_FLAGS + ['/Fo' + str(layout), str(HERE / 'NativeRobloxTreeCtrlLayout.cpp')], OUT)
assert code == 0, log[-3000:]
lb = dict((n, b) for n, b, r in match.coff_functions(layout.read_bytes()))
assert lb['?treeBaseOffset@@YAHXZ'] == bytes.fromhex('b854000000c3')
assert lb['?childAddedOffset@@YAHXZ'] == bytes.fromhex('b804000000c3')
assert lb['?childRemovedOffset@@YAHXZ'] == bytes.fromhex('b808000000c3')
assert lb['?setTextDirty@@YAXPAVCRobloxTreeCtrlNode@@@Z'] == bytes.fromhex('8b44240480485401c3')
assert lb['?setExpanded@@YAXPAVCRobloxTreeCtrlNode@@@Z'] == bytes.fromhex('8b44240480485402c3')
assert lb['?instanceDescriptor@@YAPBXPAVInstance@RBX@@@Z'] == bytes.fromhex('8b4424048b401cc3')

# 2. the unit through the noinline profile
PENDING = [('    void addToSelection(Instance*);', '    void addToSelection(Instance*); bool isSelected(const Instance*) const;'),
           ('int getImageIndex() const;', 'int getImageIndex() const; int explorerOrder() const;')]


def profile(name, defines=(), replace=()):
    pre = OUT / ('pre-' + name); pre.mkdir(exist_ok=True)
    src = ROOT / 'rebuild/2008-06/native-classes/CRobloxTreeCtrl.cpp'
    code, log = rebuild.run(tool, 'cl', [x for x in FLAGS if x != '/c'] + XTP_FLAGS + INC + list(defines) + ['/P', str(src)], pre)
    assert code == 0, log[-3000:]
    body = (pre / 'CRobloxTreeCtrl.i').read_text(errors='replace')
    needle = 'const _Elem * c_str() const'
    assert body.count(needle) == 1
    body = body.replace(needle, '__declspec(noinline) ' + needle)
    for old, new in replace:
        assert body.count(old) == 1, old
        body = body.replace(old, new)
    unit = OUT / (name + '.cpp'); unit.write_text(body)
    obj = OUT / (name + '.obj')
    code, log = rebuild.run(tool, 'cl', ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/Fo' + str(obj), str(unit)], OUT)
    assert code == 0, log[-3000:]
    return obj


obj = profile('NativeRobloxTreeCtrlProfile')
selobj = profile('NativeRobloxTreeCtrlPending', ['/DNATIVE_TREE_PENDING_SELECTION'], PENDING)

T = 'CRobloxTreeCtrl@@'
N = 'CRobloxTreeCtrlNode@@'
METHODS = [
    ('?GetRuntimeClass@' + T + 'UBEPAUCRuntimeClass@@XZ', 0x422630),
    ('?OnItemExpanded@' + T + 'QAEXPAUtagNMHDR@@PAJ@Z', 0x4226a0),
    ('?OnGetDispInfo@' + T + 'QAEXPAUtagNMHDR@@PAJ@Z', 0x4226c0),
    ('?rebuild@' + T + 'UAEXXZ', 0x422b40),
    ('?OnDeleteItem@' + T + 'QAEXPAUtagNMHDR@@PAJ@Z', 0x422bd0),
    ('?OnDestroy@' + T + 'QAEXXZ', 0x422d10),
    ('?OnCreate@' + T + 'QAEHPAUtagCREATESTRUCTA@@@Z', 0x422da0),
    ('?PreCreateWindow@' + T + 'UAEHAAUtagCREATESTRUCTA@@@Z', 0x422e10),
    ('?OnBeginLabelEdit@' + T + 'QAEXPAUtagNMHDR@@PAJ@Z', 0x422e90),
    ('?OnPaint@' + T + 'QAEXXZ', 0x422ed0),
    ('?OnKeyDown@' + T + 'QAEXIII@Z', 0x422f70),
    ('?OnEndLabelEdit@' + T + 'QAEXPAUtagNMHDR@@PAJ@Z', 0x4232a0),
    ('??1' + T + 'UAE@XZ', 0x424510),
    ('?queueChild@' + N + 'QAEXABV?$shared_ptr@VInstance@RBX@@@boost@@@Z', 0x424580),
    ('??1' + N + 'UAE@XZ', 0x424900),
    ('?onItemExpanded@' + N + 'UAEXI@Z', 0x424ae0),
    ('??_E' + N + 'W3AEPAXI@Z', 0x424b50),
    ('?onEvent@' + N + 'MAEXPBVInstance@RBX@@VPropertyChanged@3@@Z', 0x424dd0),
    ('?onEvent@' + N + 'MAEXPBVInstance@RBX@@UChildAdded@3@@Z', 0x425450),
    ('?onEvent@' + N + 'MAEXPBVInstance@RBX@@UChildRemoved@3@@Z', 0x4256c0),
    ('??0' + T + 'QAE@XZ', 0x425b00),
    ('?GetNextItem@CXTTreeCtrlBase@@UBEPAU_TREEITEM@@PAU2@I@Z', 0x425ba0),
    ('?GetItemState@CXTTreeCtrlBase@@UBEIPAU_TREEITEM@@I@Z', 0x425bc0),
    ('?SelectItem@CXTTreeCtrlBase@@UAEHPAU_TREEITEM@@@Z', 0x425bd0),
    ('?SetItemState@CXTTreeCtrlBase@@UAEHPAU_TREEITEM@@II@Z', 0x425be0),
    ('?OnNotify@CXTTreeCtrlBase@@MAEHIJPAJ@Z', 0x425bf0),
    ('?PreTranslateMessage@CXTTreeCtrlBase@@MAEHPAUtagMSG@@@Z', 0x425c00),
    ('?Init@CXTTreeCtrlBase@@MAE_NXZ', 0x425c10),
    ('?PreSubclassWindow@CXTTreeCtrlBase@@MAEXXZ', 0x425c20),
    ('??_E' + T + 'WFE@AEPAXI@Z', 0x425c40),
    ('?PreTranslateMessage@CXTTreeCtrlBase@@OFE@AEHPAUtagMSG@@@Z', 0x425c50),
    ('?OnNotify@CXTTreeCtrlBase@@OFE@AEHIJPAJ@Z', 0x425c60),
    ('??_G' + T + 'UAEPAXI@Z', 0x425c70),
    ('??0' + N + 'QAE@PAV0@V?$shared_ptr@VInstance@RBX@@@boost@@PAVCRobloxTreeCtrl@@@Z', 0x425de0),
    ('?initialize@' + N + 'UAEXXZ', 0x426010),
    ('?populate@' + N + 'QAEXXZ', 0x4262c0),
    ('??_E' + N + 'W7AEPAXI@Z', 0x426650),
    ('??_G' + N + 'UAEPAXI@Z', 0x426660),
    ('?OnItemExpanding@' + T + 'QAEXPAUtagNMHDR@@PAJ@Z', 0x426d60),
    ('?GetMessageMap@' + T + 'MBEPBUAFX_MSGMAP@@XZ', 0x4272f0),
    ('?classImage@@YAHPBVClassDescriptor@Reflection@RBX@@@Z', 0x424b60),
    ('?insertItem@' + N + 'UAEPAU_TREEITEM@@XZ', 0x424c00),
]
SEL = [('?updateSelection@' + N + 'UAEXXZ', 0x424f80), ('?hasChildren@' + N + 'QAE_NXZ', 0x425050), ('?addChild@' + N + 'QAEPAV1@ABV?$shared_ptr@VInstance@RBX@@@boost@@@Z', 0x426100), ('?explorerOrder@@YAHPAVInstance@RBX@@@Z', 0x423050)]
SPLIT = [('?onGetDispInfo@' + N + 'UAEXPAUtagTVDISPINFOA@@@Z', 0x425320, 0x425425)]
# Identical-COMDAT folds reached through the vector deleting destructor symbols (no array new of these classes).
FOLDS = {'??_E' + T + 'UAEPAXI@Z': 0x425c70, '??_E' + N + 'UAEPAXI@Z': 0x426660}
OWN_DATA = {
    '??_7' + T + '6BCTreeCtrl@@@': 0x80fcd4,
    '??_7' + T + '6BCXTTreeBase@@@': 0x80fc4c,
    '??_7' + N + '6B?$Listener@VInstance@RBX@@VPropertyChanged@2@@RBX@@@': 0x80fc28,
    '??_7' + N + '6B?$Listener@VInstance@RBX@@UChildAdded@2@@RBX@@@': 0x80fc1c,
    '??_7' + N + '6B?$Listener@VInstance@RBX@@UChildRemoved@2@@RBX@@@': 0x80fc10,
    '?classCRobloxTreeCtrl@' + T + '2UCRuntimeClass@@B': 0x80fb20,
    '?messageMap@?1??GetThisMessageMap@' + T + 'KGPBUAFX_MSGMAP@@XZ@4U3@B': 0x810084,
}

original = Original()


def bodies_of(o):
    return {n: (b, r) for n, b, r in match.coff_functions(o.read_bytes())}


def check(o, rows, out_rows, bound, split=None):
    """Exact-match and collect every relocation target (bound-by-call-site targets must agree across all bodies)."""
    raw = o.read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = bodies_of(o)
    own = dict(METHODS + SEL + [(s[0], s[1]) for s in SPLIT])
    own.update(FOLDS)
    for name, address in rows:
        body, refs = bodies[name]
        pieces = [(address, 0, len(body))]
        if split and name in split:
            first = len(match.target('2008-06', '%08x' % address)[0])
            pieces = [(address, 0, first), (split[name], first, len(body))]
        start, section = definitions[name]
        table = sections[section]
        code = raw[table[4] + start:]
        verified, local = {}, set()
        for piece_address, lo, hi in pieces:
            target, target_refs, _ = match.target('2008-06', '%08x' % piece_address)
            piece_refs = [r - lo for r in refs if lo <= r < hi]
            assert match.exact_match(target, target_refs, body[lo:hi], piece_refs), (name, hex(piece_address))
            for i in range(table[7]):
                offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
                offset -= start
                if not lo <= offset < hi:
                    continue
                symbol = symbols[index][0]
                rel = offset - lo
                if kind == 20:
                    value = (piece_address + rel + 4 + struct.unpack_from('<i', target, rel)[0]) & 0xffffffff
                else:
                    value = (struct.unpack_from('<I', target, rel)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
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
                    verified[symbol] = '%s (literal)' % hex(value)
                elif symbol in OWN_DATA or symbol in own:
                    assert OWN_DATA.get(symbol, own.get(symbol)) == value, (name, symbol, hex(value))
                    verified[symbol] = '%s (own)' % hex(value)
                else:
                    assert bound.setdefault(symbol, value) == value, (name, symbol, hex(value), hex(bound[symbol]))
                    hint = names.get('%08x' % value, {}).get('symbol', '')
                    verified[symbol] = '%s (call site; pool name %s)' % (hex(value), hint[:80] or '-')
        out_rows.append({'address': '%08x' % address, 'symbol': name, 'size': len(body), 'exact': True,
                         'verified_targets': verified, 'local_eh': sorted(local)})


bound, rows, sel_rows, split_rows = {}, [], [], []
check(obj, METHODS, rows, bound)
check(obj, [(s[0], s[1]) for s in SPLIT], split_rows, bound, {s[0]: s[2] for s in SPLIT})
check(selobj, SEL, sel_rows, bound)
# Selection::isSelected 00424eb0 and Metadata::Class::explorerOrder 004225b0 are call-site bound in the pending rows.

# 3. vtables: every slot binds to the original slot value (own rows, imports, call-site bindings, _purecall).
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
own = dict(METHODS + SEL + [(s[0], s[1]) for s in SPLIT]); own.update(FOLDS)
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
    result = {'slots': count, 'verified': 0, 'bound': {}, 'unverified': {}}
    for slot in range(count):
        name, value = slots[slot], values[slot]
        if name in own:
            assert own[name] == value, (symbol, slot, name, hex(value))
        elif name == '__purecall':
            assert original.data(value, 2) == b'\xff\x25' or value == 0x6a16be, (symbol, slot, hex(value))
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
runtime = struct.unpack('<IiIIII', original.data(0x80fb20, 24))
assert original.data(runtime[0], 16) == b'CRobloxTreeCtrl\0'
assert runtime[1:5] == (0xd0, 0xffff, 0, 0x422620), runtime
base_getter, entries = struct.unpack('<II', original.data(0x810084, 8))
assert base_getter == 0x6dbde0
MAP = [(0xbc4e, 0xfe6d, 0, 0, 61, 0x4226c0), (0xbc4e, 0xfe6b, 0, 0, 61, 0x426d60), (0xbc4e, 0xfe6a, 0, 0, 61, 0x4226a0),
       (0xbc4e, 0xfe67, 0, 0, 61, 0x422bd0), (0xbc4e, 0xfe66, 0, 0, 61, 0x422e90), (0xbc4e, 0xfe65, 0, 0, 61, 0x4232a0),
       (2, 0, 0, 0, 19, 0x422d10), (1, 0, 0, 0, 13, 0x422da0), (0xf, 0, 0, 0, 19, 0x422ed0), (0x203, 0, 0, 0, 53, 0x4237d0),
       (0x100, 0, 0, 0, 24, 0x422f70), (0, 0, 0, 0, 0, 0)]
for i, entry in enumerate(MAP):
    assert struct.unpack('<6I', original.data(entries + 24 * i, 24)) == entry, (i, entry)
# compiled message map entries carry the same messages/codes/signatures in the same order
start, section = definitions['?_messageEntries@?1??GetThisMessageMap@' + T + 'KGPBUAFX_MSGMAP@@XZ@4QBUAFX_MSGMAP_ENTRY@@B']
compiled = raw[sections[section][4] + start:]
for i, entry in enumerate(MAP):
    assert struct.unpack_from('<5I', compiled, 24 * i) == entry[:5], (i, entry)

H = ROOT / 'rebuild/2008-06/native-headers'
paths = [Path(__file__), ROOT / 'rebuild/2008-06/native-classes/CRobloxTreeCtrl.cpp', H / 'CRobloxTreeCtrl.h', HERE / 'NativeRobloxTreeCtrlLayout.cpp']
receipt = {
    'class': 'CRobloxTreeCtrl (+ CRobloxTreeCtrlNode)',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': FLAGS + XTP_FLAGS, 'profile': 'noinline std::string::c_str (imported)',
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths}, 'object_sha256': sha(obj),
    'methods': rows, 'split_catch_funclet': split_rows, 'pending_shared_header': sel_rows,
    'call_site_bindings': {k: hex(v) for k, v in sorted(bound.items())}, 'vtables': vtables,
}
(ROOT / 'work/2008-06/shared-layouts/roblox-tree-ctrl-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native CRobloxTreeCtrl: %d exact rows, %d exact with split catch funclet, %d exact pending Selection.h; vtables %s'
      % (len(rows), len(split_rows), len(sel_rows),
         {k: (v['verified'], v['slots'], v['unverified']) for k, v in vtables.items()}))
