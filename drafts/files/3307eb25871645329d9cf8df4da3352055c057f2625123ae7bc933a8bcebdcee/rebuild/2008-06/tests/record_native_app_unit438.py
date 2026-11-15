"""Record the 2008-06 application range 00438000..0043c000 (inactive) and verify its CPropGrid unit rows.

Step 1, unit map. The whole range belongs to one translation unit, the Studio property grid (CPropGrid.cpp with the
CPropertyGridItemBrickColor / XItem<T> editor rows; it starts below the range at the CPropertyGridItemBrickColor
helpers 0x437a20 and runs past it into the editor factory 0x440e30 and CSelectionPropGrid 0x442490). Inside it the
rows are: CPropGrid / CPropGrid::Item / SelectionGroup members, the XItem<T> editor template instances, the
CPropertyGridItemBrickColor rows (property-grid-item-brick-color), and the std / MFC (CMap<UINT,UINT,int,int&>) / XTP
instances the unit emits first. Evidence per row (RTTI of referenced vtables, strings, imports, callers, evidence names)
is re-read from the original and written to the receipt; boundary anchors are asserted below.
Rows other receipts count are found with the top-level exact_function_rows rule (receipts without that key: their
exact_addresses / exact_unique_addresses lists, else the methods marked exact) and written as 'ADDR counted by
RECEIPT' text; every other address of a row not counted here is written 0x-prefixed (local_backpack /
viewnew_brick_build / viewnew_part_mesh read any quoted bare address as counted).

Step 2, recovery. native-classes/AppUnit438PropGrid.cpp holds the CPropGrid unit bodies (CPropGrid members, Item,
SelectionGroup::remove, the addItem<Editor> attachments and the XItem<T> constructors) against the committed native
headers, all included read-only (CPropGrid.h, SelectionGroup.h, PropertyGridItems.h, DataModel.h, Instance.h,
PropertyChanged.h). The generated out/appunit438/AppUnit438Combined.cpp includes it and then the owner's
native-classes/DataModelLock.cpp (read-only), so DataModel::Lock's constructor is visible to OnUpdate as it was in the
original unit. Profile (as record_native_propgrid_items2008.py / record_native_property_attachment.py): VS2008 RTM
21022, document-swap flags + XTP 11.2.2, preprocessed with std::string::c_str, CString operator PCXSTR,
CXTPPropertyGridItem::GetCaption and std::vector::push_back noinline (the original calls or imports each out of line),
compiled /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast (XItem<float>::equalValues 0x43a700 needs /fp:fast).
A row counts only if its bytes match exactly and every relocation is bound to the address the original instruction
uses and verified: imports by DLL export name, literals by bytes, RTTI and vtables by original RTTI names, own rows,
the EXTERNAL map (bindings other recorders prove or evidence names), and any other body this build emits by bytes at
the called address with its own targets verified the same way (recursively; 'instances', not counted). One address per
symbol. The XItem vtables the counted constructors store are checked slot by slot from this object (no pending build).
Writes work/2008-06/shared-layouts/app-unit438-working.json.
"""
import glob
import json
import os
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import native_bind as nb  # noqa: E402
from native_bind import ROOT, LOCAL_EH, Original, match, rebuild, sha  # noqa: E402

R = ROOT / 'rebuild/2008-06'
HDR = R / 'native-headers'
SRC = R / 'native-classes'
UNIT_CPP = SRC / 'AppUnit438PropGrid.cpp'
LOCK_CPP = SRC / 'DataModelLock.cpp'
OUT = R / 'out/appunit438'
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit438-working.json'
LO, HI = 0x438000, 0x43c000
H = lambda a: '0x%08x' % a
TC = rebuild.toolchain(21022)
NEEDLES = ('const _Elem * c_str() const',
           'operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );',
           'CString CXTPPropertyGridItem::GetCaption() const',
           'void push_back(const _Ty& _Val)\n\t\t{\t\n\t\tif (size() < capacity())')
COMPILE = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/fp:fast']
original = Original()


def d(address):
    return struct.unpack('<I', original.data(address, 4))[0]


FUNCS = {}
for line in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines():
    if line.strip():
        row = json.loads(line)
        FUNCS[int(row['addr'], 16)] = row
rows = sorted(a for a in FUNCS if LO <= a < HI)
EVIDENCE = json.loads((R / 'offline/evidence.json').read_text())['names']


def build():
    OUT.mkdir(parents=True, exist_ok=True)
    combined = OUT / 'AppUnit438Combined.cpp'
    combined.write_text('#include "%s"\n#include "%s"\n' % (UNIT_CPP.as_posix(), LOCK_CPP.as_posix()))
    pre = OUT / 'pre'
    pre.mkdir(exist_ok=True)
    code, log = rebuild.run(TC, 'cl', [x for x in nb.flags() if x != '/c'] + nb.XTP_FLAGS + ['/P', str(combined)], pre)
    assert code == 0, log[-3000:]
    body = (pre / 'AppUnit438Combined.i').read_text(errors='replace')
    for needle in NEEDLES:
        assert body.count(needle) == 1, needle
        body = body.replace(needle, '__declspec(noinline) ' + needle)
    unit = OUT / 'AppUnit438Profile.cpp'
    unit.write_text(body)
    obj = OUT / 'NativeAppUnit438PropGrid.obj'
    code, log = rebuild.run(TC, 'cl', COMPILE + ['/Fo' + str(obj), str(unit)], OUT)
    assert code == 0, log[-3000:]
    return obj


unit_obj = build()

# ---- rows counted here ----------------------------------------------------------------------------------------
TS = 'V?$TypedPropertyDescriptor@'
XB = '?$XItem@_NVCXTPPropertyGridItemBool@@' + TS + '_N@Reflection@RBX@@@'
XF = '?$XItem@MVCXTPPropertyGridItem@@' + TS + 'M@Reflection@RBX@@@'
XI = '?$XItem@HVCXTPPropertyGridItem@@' + TS + 'H@Reflection@RBX@@@'
XC = '?$XItem@VColor3@G3D@@VCXTPPropertyGridItemColor@@' + TS + 'VColor3@G3D@@@Reflection@RBX@@@'
XS = ('?$XItem@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@VCXTPPropertyGridItem@@'
      'VPropertyDescriptor@Reflection@RBX@@@')
XE = '?$XItem@HVCXTPPropertyGridItemEnum@@VEnumPropertyDescriptor@Reflection@RBX@@@'
PD = 'PBV?$TypedPropertyDescriptor@'
ROWS = [
    (0x00438000, '??_9Item@CPropGrid@@$BA@AE'),                      # vcall thunk, &Item::update (OnUpdate)
    (0x00438010, '??_9CPropGrid@@$BBGI@AE'),                         # vcall thunk, &CPropGrid::addProperty (rebuild)
    (0x00438060, '?sync@Reflection@RBX@@YAAAVrecursive_mutex@boost@@XZ'),
    (0x004385f0, '?OnCreate@CPropGrid@@QAEHPAUtagCREATESTRUCTA@@@Z'),
    (0x00438630, '?getCategory@CPropGrid@@QAEPAVCXTPPropertyGridItem@@ABVName@RBX@@@Z'),
    (0x00438940, '??0Lock@DataModel@RBX@@QAE@PBV12@@Z'),
    (0x00438c10, None),   # for_each<vector<PropertyDescriptor*>::const_iterator, bind(&CPropGrid::addProperty, this, descriptor, _1)>
    (0x00438c60, None),   # for_each<set<Item*>::iterator, binder2nd<mem_fun1_t<void, Item, SelectionGroup*>>>
    (0x00439130, '??1' + XB + '@UAE@XZ'),
    (0x00439180, None),   # ~XItem<float> / ~XItem<int> (identical code; resolved by the vtable it stores)
    (0x004391d0, '?rebuild@CPropGrid@@QAEXPBVClassDescriptor@Reflection@RBX@@@Z'),
    (0x00439370, '?onEvent@CPropGrid@@UAEXPBVInstance@RBX@@VPropertyChanged@3@@Z'),
    (0x00439600, '?addClass@Item@CPropGrid@@QAEXPBVClassDescriptor@Reflection@RBX@@@Z'),
    (0x00439660, '?remove@SelectionGroup@RBX@@QAEXPAVInstance@2@@Z'),
    (0x00439810, '??$addItem@VXBoolItem@@@CPropGrid@@QAEXPAVXBoolItem@@@Z'),
    (0x00439940, '??$addItem@V' + XC + '@@CPropGrid@@QAEXPAV' + XC + '@@Z'),
    (0x00439a70, '??$addItem@V' + XE + '@@CPropGrid@@QAEXPAV' + XE + '@@Z'),
    (0x00439ba0, '??$addItem@V' + XF + '@@CPropGrid@@QAEXPAV' + XF + '@@Z'),
    (0x00439cd0, '?removeInstance@CPropGrid@@QAEXV?$shared_ptr@VInstance@RBX@@@boost@@@Z'),
    (0x00439d70, '?OnUpdate@CPropGrid@@QAEJIJ@Z'),
    (0x0043a070, '??0Item@CPropGrid@@QAE@PBVPropertyDescriptor@Reflection@RBX@@PAV1@@Z'),
    (0x0043a0f0, '??0' + XB + '@QAE@' + PD + '_N@Reflection@RBX@@PAVCPropGrid@@@Z'),
    (0x0043a1a0, '?equalValues@' + XB + '@UAE_NAB_N0@Z'),
    (0x0043a650, '??0' + XF + '@QAE@' + PD + 'M@Reflection@RBX@@PAVCPropGrid@@@Z'),
    (0x0043a700, '?equalValues@' + XF + '@UAE_NABM0@Z'),
    (0x0043ab10, '??0' + XI + '@QAE@' + PD + 'H@Reflection@RBX@@PAVCPropGrid@@@Z'),
    (0x0043af00, '??0' + XC + '@QAE@' + PD + 'VColor3@G3D@@@Reflection@RBX@@PAVCPropGrid@@@Z'),
]
BODIES = {}


def bodies_of(obj):
    if obj not in BODIES:
        BODIES[obj] = {n: (b, r) for n, b, r in match.coff_functions(Path(obj).read_bytes())}
    return BODIES[obj]


def candidates(address):
    target, target_refs, _ = match.target('2008-06', '%08x' % address)
    return sorted(n for n, (b, r) in bodies_of(unit_obj).items() if match.exact_match(target, target_refs, b, r))


# Unnamed rows: the one masked-exact candidate whose vtable / callee relocations agree with the original.
FOR_EACH_SET = [n for n in candidates(0x438c60) if n.startswith('??$for_each@Viterator@?$_Tree@V?$_Tset_traits@PAVItem@')]
assert len(FOR_EACH_SET) == 1, FOR_EACH_SET
FOR_EACH_VECTOR = [n for n in candidates(0x438c10)
                   if n.startswith('??$for_each@V?$_Vector_const_iterator@PAVPropertyDescriptor@Reflection@RBX@@')]
assert len(FOR_EACH_VECTOR) == 1, FOR_EACH_VECTOR
ROWS = [(a, FOR_EACH_SET[0] if a == 0x438c60 and s is None else s) for a, s in ROWS]
ROWS = [(a, FOR_EACH_VECTOR[0] if a == 0x438c10 and s is None else s) for a, s in ROWS]
DTOR_CANDIDATES = candidates(0x439180)
# ~XItem<float> / <int> / <std::string> compile to the same code (no vptr store: vector free, then the
# CXTPPropertyGridItem destructor); the original has one body (identical-code fold), counted once under the float name.
DTOR_FOLD = sorted(['??1' + XF + '@UAE@XZ', '??1' + XI + '@UAE@XZ', '??1' + XS + '@UAE@XZ'])
assert DTOR_CANDIDATES == DTOR_FOLD, DTOR_CANDIDATES
DTOR = '??1' + XF + '@UAE@XZ'
ROWS = [(a, DTOR if a == 0x439180 and s is None else s) for a, s in ROWS]

EXTERNAL = {
    # CRT / MFC operator new / delete (record_native_propgrid_items2008.py bindings).
    '??2@YAPAXI@Z': 0x006a0920,
    '??3@YAXPAX@Z': 0x006a067a,
    '_atexit': 0x006a17af,
    # DataModel::Lock (record_native_lock.py / record_native_app_unit574.py bindings, evidence names).
    '?doLock@Lock@DataModel@RBX@@AAEXPBV23@@Z': 0x00576f00,
    '??1Lock@DataModel@RBX@@QAE@XZ': 0x005773c0,
    # boost::recursive_mutex (record_native_selection_grid.py bindings).
    '?do_lock@recursive_mutex@boost@@AAEXXZ': 0x00563090,
    '?do_unlock@recursive_mutex@boost@@AAEXXZ': 0x005630e0,
    # boost::recursive_mutex ctor / dtor (record_native_app_leaves2008_services.py bindings).
    '??0recursive_mutex@boost@@QAE@XZ': 0x00563070,
    '??1recursive_mutex@boost@@QAE@XZ': 0x00594cb0,
    # Reflection / Instance helpers (record_native_selection_grid.py, record_native_property_attachment.py bindings).
    '?rootDescriptor@ClassDescriptor@Reflection@RBX@@SAAAV123@XZ': 0x0040ad20,
    '?GetCaption@CXTPPropertyGridItem@@QBE?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@XZ': 0x00437ea0,
    # XTP 11.2.2 library bodies (record_native_selection_grid.py / record_native_property_attachment.py /
    # record_native_propgrid_items2008.py bindings).
    '?SetTheme@CXTPPropertyGrid@@QAEXW4XTPPropertyGridPaintTheme@@@Z': 0x006fc0b0,
    '?SetImageManager@CXTPPropertyGrid@@QAEXPAVCXTPImageManager@@@Z': 0x006fa560,
    '?XTPImageManager@@YAPAVCXTPImageManager@@XZ': 0x006c0e80,
    '?GetAt@CXTPPropertyGridItems@@QBEPAVCXTPPropertyGridItem@@H@Z': 0x00712420,
    '?InsertChildItem@CXTPPropertyGridItem@@QAEPAV1@HPAV1@@Z': 0x00712790,
    '?SetReadOnly@CXTPPropertyGridItem@@QAEXH@Z': 0x007120e0,
    '?SetHidden@CXTPPropertyGridItem@@QAEXH@Z': 0x007110d0,
    '??1CXTPPropertyGridItem@@UAE@XZ': 0x00713630,
    # ~CXTPPropertyGridItemBool: called by the SDK deleting destructor 0x717bd0 in CXTPPropertyGridItemBool's vtable
    # 0x85e38c slot 1 (asserted below).
    '??1CXTPPropertyGridItemBool@@UAE@XZ': 0x00717510,
    '??1CXTPPropertyGridItemColor@@UAE@XZ': 0x00713760,   # record_native_property_grid_item_brick_color.py binding
    # std exception throw infos (record_native_app_unit540_2008.py / record_native_adorn.py bindings; types asserted below).
    '__TI2?AVbad_alloc@std@@': 0x008d07d8,
    '__TI3?AVlength_error@std@@': 0x008d0cc0,
    '__TI3?AVout_of_range@std@@': 0x008d0c3c,
    # XTP property-grid accessors (record_native_property_editors.py bindings).
    # OnUpdate's XTP calls (proven by the XTP recipe bodies below).
    '??0CXTPPropertyGridUpdateContext@@QAE@XZ': 0x006fbba0,
    '?BeginUpdate@CXTPPropertyGrid@@QAEXAAVCXTPPropertyGridUpdateContext@@@Z': 0x006fc780,
    '?EndUpdate@CXTPPropertyGrid@@QAEXAAVCXTPPropertyGridUpdateContext@@@Z': 0x006fc5b0,
    '?GetCategories@CXTPPropertyGrid@@QBEPAVCXTPPropertyGridItems@@XZ': 0x006fa530,
    '?IsHidden@CXTPPropertyGridItem@@QBEHXZ': 0x007110c0,
    '?Refresh@CXTPPropertyGrid@@QAEXXZ': 0x006fb910,
    '?GetGridView@CXTPPropertyGrid@@QBEAAVCXTPPropertyGridView@@XZ': 0x006fa3b0,
    # XItem constructors' SDK base constructors (record_native_property_editors.py bindings) and the SDK slot-25 body
    # (record_native_propgrid_items2008.py binding); also proven by the XTP recipe bodies below.
    '??0CXTPPropertyGridItemBool@@QAE@PBDHPAH@Z': 0x00717b20,
    '??0CXTPPropertyGridItemColor@@QAE@PBDKPAK@Z': 0x00713b80,
    '?OnValueChanged@CXTPPropertyGridItem@@UAEXV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z': 0x00711ac0,
    '?FindItem@CXTPPropertyGridItems@@QBEPAVCXTPPropertyGridItem@@PBD@Z': 0x00712460,
    '?AddCategory@CXTPPropertyGridView@@QAEPAVCXTPPropertyGridItem@@PBDPAV2@@Z': 0x00716f60,
    '?Expand@CXTPPropertyGridItem@@QAEXXZ': 0x007117e0,
    '??0CXTPPropertyGridItem@@QAE@PBD0PAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z': 0x00713510,
}


def throw_info_type(address):
    array = d(address + 12)
    return original.string(d(d(array + 4) + 4) + 8)


assert throw_info_type(0x8d07d8) == '.?AVbad_alloc@std@@'
assert throw_info_type(0x8d0cc0) == '.?AVlength_error@std@@'
assert original.vtable_class(0x85e38c) == ('.?AVCXTPPropertyGridItemBool@@', 0) and d(0x85e38c + 4) == 0x717bd0
assert original.data(0x717bd3, 5) == b'\xe8' + struct.pack('<i', 0x717510 - 0x717bd8)

# Every XTP library target is proven by compiling the XTP 11.2.2 source with recipe xtp-11.2.2-lib (Codejock's library
# prelude Common/XTPDLLExports.h and _LIB, as record_native_object_browser.py) and comparing the body at the address.
XTP_SRC = ROOT / 'tools/libs/xtp-11.2.2/Source'
xtp_bodies = {}
for rel in ('PropertyGrid/XTPPropertyGrid.cpp', 'PropertyGrid/XTPPropertyGridItem.cpp',
            'PropertyGrid/XTPPropertyGridItemBool.cpp', 'PropertyGrid/XTPPropertyGridItemColor.cpp',
            'PropertyGrid/XTPPropertyGridView.cpp', 'Common/XTPImageManager.cpp'):
    o = OUT / ('xtp_' + Path(rel).stem + '.obj')
    base = ['/nologo', '/c', '/O2', '/MD', '/GS', '/EHsc', '/Ob1', '/D_AFXDLL', '/D_XTP_STATICLINK', '/D_DLL',
            '/I' + str(XTP_SRC), '/I' + str(ROOT / 'tools/libs/mfc-9.0/atlmfc/include')]
    code, log = rebuild.run(TC, 'cl', base + ['/D_LIB', '/FICommon/XTPDLLExports.h', '/FIXTToolkitPro.h',
                                              '/Fo' + str(o), str(XTP_SRC / rel)], OUT)
    assert code == 0, (rel, log[-2000:])
    for n, b, r in match.coff_functions(o.read_bytes()):
        xtp_bodies.setdefault(n, (b, r, rel))
xtp_proof = {}
for symbol, address in sorted(EXTERNAL.items()):
    if 'XTP' not in symbol:
        continue
    t, tr, _ = match.target('2008-06', '%08x' % address)
    hit = xtp_bodies.get(symbol)
    xtp_proof[symbol] = ('XTP recipe body exact (%s) at 0x%08x' % (hit[2], address)
                         if hit and match.exact_match(t, tr, hit[0], hit[1]) else 'NOT PROVEN')
missing = sorted(k for k, v in xtp_proof.items() if v == 'NOT PROVEN')
assert not missing, missing
own = {}
for address, symbol in ROWS:
    own.setdefault(symbol, address)
binding = {}
CURRENT = []
INSTANCES = {}
OPEN_TARGETS = {}


def evidence_symbol(value):
    return EVIDENCE.get('%08x' % value, {}).get('symbol')


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
        return 'own row'
    if symbol in EXTERNAL:
        assert EXTERNAL[symbol] == value, (where, symbol, hex(value), hex(EXTERNAL[symbol]))
        return 'external'
    if evidence_symbol(value) == symbol:
        return 'evidence name'
    return instance(symbol, value, where)


def instance(symbol, value, where):
    """A body this build emits, proven by bytes at the referenced address and by its own targets."""
    if symbol in INSTANCES:
        assert INSTANCES[symbol]['address'] == '%08x' % value, (where, symbol, hex(value))
        return 'instance (bytes equal, targets verified)'
    obj = CURRENT[-1]
    if symbol not in bodies_of(obj):
        return static_data(symbol, value, where)
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
    row['status'] = 'instance (emitted by this unit; every own target verified), bytes equal, not counted'
    if unlisted:
        row['status'] += '; not a listed function start, whole body compared with the image bytes'
    elif merged:
        row['status'] += '; listed extent %#x != body %#x, whole body compared with the image bytes' % (
            len(target), len(body))
    INSTANCES[symbol] = row
    return 'instance (bytes equal, targets verified)'


# Function-local statics of own rows: uninitialized storage the original addresses at the same instruction; bound
# once (one address per symbol) and checked to be referenced only by that row's code in the original .text.
STATIC_OWNER = {}


def static_data(symbol, value, where):
    obj = CURRENT[-1]
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, starts = match._coff_data_index(raw)
    if symbol not in definitions:
        return None
    pos, sec = definitions[symbol]
    table = sections[sec]
    if table[4] and not table[9] & 0x80:
        return None
    owner = STATIC_OWNER.setdefault(symbol, where)
    assert owner == where, (symbol, owner, where)
    assert symbol.startswith('?') and '@?' in symbol and where.replace('?', '') in symbol.replace('?', ''), (symbol, where)
    INSTANCES[symbol] = {'address': '%08x' % value, 'symbol': symbol, 'exact': False,
                         'status': 'function-local static of %s (.bss), bound at the original instruction' % where}
    return 'function-local static (.bss) of the referencing row'


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
        out.append({'address': '%08x' % address, 'symbol': name, 'size': len(body), 'exact': exact_flag,
                    'verified_targets': verified, 'local_eh': sorted(local)})
    return out


results = verify(unit_obj, ROWS, True)
for r in results:
    assert r['size'] == FUNCS[int(r['address'], 16)]['size'], (r['address'], r['size'])
exact = sorted({r['address'] for r in results})
exact_ints = {int(a, 16) for a in exact}


# ---- vtables the counted constructors / destructors store (object from the current headers) -------------------------
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
    return raw, sections, definitions, slots, (end - value) // 4


PURECALL = d(0x8137a4)   # CPropGrid::Item's one-slot pure vtable holds the _purecall stub
assert original.imported(PURECALL) == ('msvcr90.dll', '_purecall')
vtable_addresses = {}
for r in results:
    for symbol, proof in r['verified_targets'].items():
        if symbol.startswith('??_7'):
            vtable_addresses[symbol] = int(proof.split()[0], 16)
vtables = {}
unresolved_slots = {}
CURRENT.append(unit_obj)
for symbol, vt in sorted(vtable_addresses.items(), key=lambda x: x[1]):
    rtti_name, subobject = original.vtable_class(vt)
    raw, sections, definitions, slots, count = vtable_slots(unit_obj, symbol)
    assert sorted(slots) == list(range(count)), (symbol, sorted(slots))
    checked = {}
    for slot, sym in sorted(slots.items()):
        value = d(vt + 4 * slot)
        if sym == '__purecall':
            assert value == PURECALL, (symbol, slot, hex(value))
            how = '_purecall stub'
        else:
            # Prove the slot body like any other target; a slot body whose own targets are template members or SDK
            # virtuals with no body here stays unresolved, and everything that attempt recorded is rolled back.
            saved_instances, saved_binding = dict(INSTANCES), dict(binding)
            folded = '??_G' + sym[4:] if sym.startswith('??_E') else None
            try:
                how = classify(sym, value, raw, sections, definitions, symbol)
                if how is None and folded and folded in bodies_of(unit_obj):
                    how = instance(folded, value, symbol)
                    how = how and how + ' via ??_G'
            except (AssertionError, SystemExit) as error:
                if sym in own or sym in EXTERNAL:
                    raise
                INSTANCES.clear()
                INSTANCES.update(saved_instances)
                binding.clear()
                binding.update(saved_binding)
                how = None
        if how is None:
            # declared in an owner header with no body in this unit (XItem template members, XTP SDK virtuals):
            # recorded with the original slot value, one address per symbol, not proven here
            unresolved_slots.setdefault(sym, '0x%08x' % value)
            assert unresolved_slots[sym] == '0x%08x' % value, (sym, unresolved_slots[sym], hex(value))
            how = 'declared, no body in this unit (not proven here)'
        else:
            prev = binding.setdefault(sym, value)
            assert prev == value, ('inconsistent', sym, hex(prev), hex(value))
        checked[slot] = '%s = 0x%08x (%s)' % (sym, value, how)
    vtables[symbol] = {'address': H(vt), 'rtti': rtti_name, 'subobject': subobject, 'slots': count, 'proof': checked}
CURRENT.pop()


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


def walk_methods(o, out):
    if isinstance(o, list):
        for e in o:
            walk_methods(e, out)
    elif isinstance(o, dict):
        if 'address' in o and o.get('exact') is True:
            out.append(o['address'])
        else:
            for v in o.values():
                walk_methods(v, out)


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
        got = []
        walk_methods(doc.get('methods', []), got)
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


def evidence_of(a):
    r = FUNCS[a]
    ev = {}
    name = evidence_symbol(a)
    if name:
        ev['evidence_name'] = name
    vts = sorted({rtti_of(int(x, 16)) for x in r.get('data_refs', [])} - {None})
    if vts:
        ev['rtti_refs'] = vts
    strs = sorted({s for s in (string_at(int(x, 16)) for x in r.get('data_refs', [])) if s})
    if strs:
        ev['strings'] = strs[:4]
    imps = sorted({i.split('!', 1)[0] + '!' + i.split('!', 1)[1][:60] for i in r.get('imports', [])})
    if imps:
        ev['imports'] = imps[:4]
    if r.get('callers'):
        ev['callers'] = [H(int(c, 16)) for c in r['callers'][:6]]
    return ev


# Unit anchors: the CPropGrid message map / Item RTTI (record_native_selection_grid.py proofs), the XItem vtables
# stored by the counted constructors, and the CMap<UINT,UINT,int,int&> vtable of the MFC instance rows.
assert struct.unpack('<2I', original.data(0x8145dc, 8)) == (0x6fbf70, 0x8145e8)
assert d(0x8145e8 + 20) == 0x4385f0 and d(0x8145e8 + 44) == 0x439d70      # ON_WM_CREATE / ON_MESSAGE(WM_USER+101)
assert original.vtable_class(0x8137a4)[0] == '.?AVItem@CPropGrid@@'
assert d(0x81564c + 90 * 4) == 0x440e30                                     # CPropGrid slot 90 = addProperty
assert original.vtable_class(0x81378c)[0] == '.?AV?$CMap@IIHAAH@@'
for a, b in zip(rows, rows[1:]):
    assert a + FUNCS[a]['size'] <= b, hex(a)

NOTES = {
    0x438030: 'CMap<UINT,UINT,int,int&>::RemoveAll (CPlex::FreeDataChain), MFC template instance, also called by XTP '
              '0x755170 / 0x760970: library',
    0x4380c0: 'XItem<float>::readValue (GetValue, StringConverter<float>); owner editor-values probe is 2 bytes long; '
              'not attempted here (template member body owned by PropertyGridItems.h)',
    0x438160: 'XItem<int>::readValue; as 0x4380c0',
    0x438450: 'XItem<std::string>::readValue (propgrid-items2008 unresolved slot); not attempted',
    0x438690: '_Tree<set<Item*>>::_Lrotate, identical-code fold shared with other set<T*> units (evidence name '
              'set<IMoving*>): shared std instance',
    0x4387e0: 'CMap<UINT,UINT,int,int&>::FreeAssoc, MFC template instance (caller 0x78eee0 XTP): library',
    0x438830: 'jmp to 0x437f20, referenced from other units (0x452e5c, 0x5b8456): shared std destructor stub',
    0x438840: 'jmp to 0x437f90, referenced from other units (0x5b8476): shared std destructor stub',
    0x438850: 'CMap<UINT,UINT,int,int&>::InitHashTable (MFC library instance, also called by XTP 0x6bd2a0)',
    0x4388c0: 'CMap<UINT,UINT,int,int&>::GetAssocAt (MFC library instance, also called by XTP 0x6fc290)',
    0x438910: 'CMap<UINT,UINT,int,int&> deleting destructor (MFC library instance, vtable 0x81378c)',
    0x438990: 'CXTPPropertyGridUpdateContext destructor (XTP library inline, also called by XTP 0x6fc2c0)',
    0x4389f0: 'std::_Copy_opt<Item**>, identical-code fold shared with vector<SpatialNode*> (evidence name): shared',
    0x438a30: 'boost mf1<RunService, shared_ptr<DataModel>> call (evidence name), identical-code fold shared with '
              'other units (callers 0x438d40, 0x555780)',
    0x438ae0: 'vector<const ClassDescriptor*>::_Buy, identical-code fold with vector<SpatialNode*> (evidence name): shared',
    0x438b30: 'std::find over vector<shared_ptr<Instance>>, also called by 0x55a8f0: shared',
    0x438b60: 'std::_Uninit_copy<shared_ptr<Instance>> (evidence name), shared (0x412240 / 0x5a2fb0 / 0x5acb00)',
    0x438ba0: 'CMap<UINT,UINT,int,int&>::operator[] (MFC library instance, also called by XTP 0x6fc6c0)',
    0x438cf0: 'std::_Tree node erase helper (identical-code std instance), not attempted',
    0x438d40: 'SelectionGroup map helper called by CSelectionPropGrid::setSelection 0x442650 (outside the range); '
              'no candidate body in this build',
    0x438db0: 'CMap<UINT,UINT,int,int&>::Serialize (MFC library instance)',
    0x439320: 'vector<Item*>::clear, identical-code fold with vector<SpatialNode*> (evidence name): shared',
    0x439480: 'vector<shared_ptr<Instance>>::erase (evidence name), also called by 0x49daa0 / 0x55a8f0: shared',
    0x439510: 'vector<Item*>::operator=, identical-code fold with vector<SpatialNode*> (evidence name): shared',
    0x439800: 'this-adjusting jmp (+4) to 0x5a2fe0, shared adjustor: not attempted',
    0x43a1d0: 'vcall thunk for XItem<BrickColor> slot 63 (pointer-to-member, used by update/applyValue, not built)',
    0x43a1e0: 'XItem<BrickColor> descriptor read under DataModel::Lock (GetSet slot +8); not attempted',
    0x43a280: 'XItem<bool>::writeValue under DataModel::Lock (GetSet slot +0xc; property-write-trial finding: '
              'current reflection header emits +8): blocked by reflection/*.h (core header)',
    0x43a3b0: 'XItem<bool>::update (template body owned by PropertyGridItems.h; not attempted)',
    0x43a720: 'vcall thunk for XItem slot 60 (pointer-to-member, used by update/applyValue, not built)',
    0x43a730: 'XItem<float> descriptor read under DataModel::Lock; not attempted',
    0x43a7d0: 'XItem<Vector3/SoundId/TextureId>::writeValue (identical-code fold); blocked like 0x43a280 '
              '(property-write-trial / property-write-overlay-trial)',
    0x43a870: 'XItem<float>::update (template body owned by PropertyGridItems.h; not attempted)',
    0x43abc0: 'XItem<int> descriptor read under DataModel::Lock; not attempted',
    0x43ac60: 'XItem<int>::update (not attempted)',
    0x43afb0: 'G3D::Color3::operator== (G3D library inline, also called by 0x514400): library',
    0x43b0d0: 'XItem<Color3>::update (not attempted)',
    0x43b390: 'std::for_each over a descriptor vector with a mem_fun pair (update helper), not attempted',
    0x43b510: 'XItem<Color3> descriptor read under DataModel::Lock; not attempted',
    0x43b5b0: 'XItem<BrickColor>::update (propgrid-items2008 not_attempted)',
    0x43b930: 'XItem<std::string> descriptor read under DataModel::Lock; not attempted',
    0x43b9d0: 'XItem<std::string>::writeValue (propgrid-items2008 unresolved slot); not attempted',
    0x43ba60: 'std::string-carrying binder copy (MSVCP90 string copy ctor), update helper; not attempted',
    0x43bad0: 'as 0x43ba60 (binder copy chain)',
    0x43bb50: 'as 0x43ba60 (binder copy chain, caller 0x43fc00 outside the range)',
    0x43bc20: 'XItem<std::string>::update (not attempted)',
    0x43bf60: 'binder copy chain helper (caller 0x43fc00 outside the range); not attempted',
}
unit_rows = []
for a in rows:
    entry = {'row': H(a), 'size': FUNCS[a]['size'], 'unit': 'CPropGrid (Studio property grid)'}
    if a in exact_ints:
        entry['kind'] = 'counted here'
        entry['counted'] = '%08x counted here' % a
    elif a in counted_elsewhere:
        entry['kind'] = 'counted elsewhere'
        entry['counted'] = '%08x counted by %s' % (a, ', '.join(sorted(counted_elsewhere[a])))
        entry['row'] = 'see counted'
    else:
        assert a in NOTES, ('unclassified', hex(a))
        lib = 'library' in NOTES[a]
        entry['kind'] = 'library (not recovered)' if lib else 'open (shared instance / not attempted / blocked)'
        entry['note'] = NOTES[a]
    entry['evidence'] = evidence_of(a)
    unit_rows.append(entry)
assert sum(1 for e in unit_rows if e['kind'] == 'counted here') == len(exact)

paths = [Path(__file__).resolve(), R / 'tests/native_bind.py', UNIT_CPP, LOCK_CPP,
         HDR / 'CPropGrid.h', HDR / 'SelectionGroup.h', HDR / 'PropertyGridItems.h', HDR / 'v8datamodel/DataModel.h',
         HDR / 'v8tree/Instance.h', HDR / 'v8tree/PropertyChanged.h']
receipt = {
    'family': 'app unit 00438000: CPropGrid translation unit (Studio property grid)',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': nb.flags() + nb.XTP_FLAGS,
    'compile_flags': COMPILE,
    'profile': 'document-swap flags + XTP 11.2.2; preprocessed with c_str / PCXSTR / GetCaption / vector::push_back '
               'noinline, compiled /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast; owner DataModelLock.cpp appended '
               'read-only in the generated combined unit',
    'original_sha256': sha(original.path),
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {'propgrid': sha(unit_obj)},
    'xtp_targets': xtp_proof,
    'range': [H(LO), H(HI)],
    'range_rows': len(rows),
    'unit_map': {
        'CPropGrid unit 0x437a20..0x442900 (whole range)': {
            'rows_in_range': len(rows), 'kind': 'rbx',
            'why': 'CPropGrid message map 0x8145dc (WM_CREATE 0x4385f0, WM_USER+101 0x439d70), CPropGrid::Item RTTI '
                   '0x8137a4, the XItem<T> editor vtables, CPropertyGridItemBrickColor (counted by '
                   'property-grid-item-brick-color) and the CMap<UINT,UINT,int,int&> MFC instance (vtable 0x81378c) '
                   'all sit in this one unit; it continues past 0x43c000 into the editor factory 0x440e30 and '
                   'CSelectionPropGrid 0x442490 / 0x442650.'},
    },
    'rows': unit_rows,
    'methods': results,
    # instance rows are not counted: their addresses are written 0x-prefixed (never as quoted bare addresses)
    'instances': {k: dict(v, address='0x' + v['address'].replace('0x', '')) for k, v in INSTANCES.items()},
    'vtables': vtables,
    'unresolved_vtable_slots': unresolved_slots,
    'counted_elsewhere': ['%08x counted by %s' % (a, ', '.join(sorted(v))) for a, v in sorted(counted_elsewhere.items())],
    'proposals': [
        'native-classes/CPropGridRefresh.cpp (owner of the selection-grid probe): end CPropGrid::OnUpdate with '
        'Refresh() instead of RedrawControl(). The original call at 0x43a003 targets 0x6fb910, which the XTP 11.2.2 '
        'recipe proves is CXTPPropertyGrid::Refresh (GetGridView().SetPropertySort(GetPropertySort(), TRUE)); '
        'RedrawControl compiles to a different body. Both are 5-byte calls, so the probe\'s relocation-masked compare '
        'could not tell them apart.',
        'selection-grid / property-editor-constructors / property-attachment probe owners: their rows in this range '
        'are now counted once here, with every target verified; their receipts should keep them as probes, not add '
        'them to exact_function_rows.',
    ],
    'rejected': [
        'XItem<float>::readValue 0x4380c0 (explicit specialization, GetValue noinline): '
        '`convertToValue(std::string(GetValue()), value)` 149 bytes (passes the string ctor\'s eax result; the '
        'original recomputes lea edx,[esp+0x10]); a const CString& block with a temporary string 151 bytes; the owner\'s '
        'named-string block 155 bytes; a named string from GetValue() 156 bytes; a const char* argument 155 bytes. '
        'Not recovered; 0x438160 (int) has the same shape.',
        'CPropGrid::OnUpdate ending with RedrawControl() (owner CPropGridRefresh.cpp shape): bytes equal but the '
        'call target 0x6fb910 is CXTPPropertyGrid::Refresh, so the relocation check fails.',
    ],
    'shadowing': 'none (no new header; every native header is included read-only)',
    'exact_function_rows': exact,
    'scope': 'Inactive. Exact rows with every target verified; no pending build; no active build, swap or credit. '
             'Bodies follow the owners\' matched native-classes/CPropGrid*.cpp / SelectionGroup.cpp / '
             'PropertyGridItems.h; those probe receipts list them as relocation-masked matches without '
             'exact_function_rows, so they are counted here once.',
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native app unit438: %d rows mapped, %d exact (%s), %d counted elsewhere, %d vtables checked, '
      '%d instances' % (len(rows), len(exact), ' '.join(exact), len(counted_elsewhere), len(vtables), len(INSTANCES)))
