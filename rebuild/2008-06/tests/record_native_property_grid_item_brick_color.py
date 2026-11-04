"""Verify the inactive native CPropertyGridItemBrickColor: layout, exact bodies, call/data targets, vtables, RTTI.

Profiles: document-swap flags + XTP 11.2.2 headers (/UNOMINMAX /D_XTP_STATICLINK) for the layout test and a
plain compile of the unit; the method comparison uses the same unit preprocessed with CString operator PCXSTR and
std::string::c_str noinline (the original imports both from mfc90/msvcp90) and /fp:fast (brickColorName 00437a20
multiplies by the float constant 1/255 at 008135d4 with fimul). OnInplaceButtonDown reads the protected
CRobloxControlColorSelector::m_bColorPicked, so it is guarded by NATIVE_BRICKCOLOR_SELECTOR_PENDING; this probe
compiles it against a copy of CRobloxControlColorSelector.h (in out/) that only adds
`friend class CPropertyGridItemBrickColor;` - the proposed shared-header declaration.
Run with DISCOVER=1 to list every relocation binding instead of asserting the INTERNAL table.
"""
import hashlib, json, os, re, struct, sys
from pathlib import Path
import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32
from capstone.x86 import X86_OP_IMM

root = Path(__file__).resolve().parents[3]
here = Path(__file__).resolve().parent
sys.path.insert(0, str(root))
from roc import match, rebuild  # noqa: E402

DISCOVER = os.environ.get('DISCOVER')
tc = rebuild.toolchain(21022)
out = root / 'rebuild/2008-06/out/native-layouts'
out.mkdir(parents=True, exist_ok=True)
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
xtp = ['/UNOMINMAX', '/I' + str(root / 'tools/libs/xtp-11.2.2/Source'), '/D_XTP_STATICLINK']
source = root / 'rebuild/2008-06/native-classes/CPropertyGridItemBrickColor.cpp'
header = root / 'rebuild/2008-06/native-headers/CPropertyGridItemBrickColor.h'
selector_header = root / 'rebuild/2008-06/native-headers/CRobloxControlColorSelector.h'
fixture = here / 'NativePropertyGridItemBrickColorLayout.cpp'

# 1. layout test and the plain (pending body excluded) unit
for path, target in [(fixture, out / 'NativePropertyGridItemBrickColorLayout.obj'),
                     (source, out / 'NativePropertyGridItemBrickColorPlain.obj')]:
    code, log = rebuild.run(tc, 'cl', flags + xtp + ['/Fo' + str(target), str(path)], out)
    assert code == 0, log[-3000:]

# 2. pending profile: proposed friend declaration in a copy of the selector header, searched first
pending = out / 'brickcolor-pending'
pending.mkdir(exist_ok=True)
text = selector_header.read_text()
anchor = 'class CRobloxControlColorSelector : public CXTPControl {\n'
assert text.count(anchor) == 1
(pending / 'CRobloxControlColorSelector.h').write_text(
    text.replace(anchor, anchor + '    friend class CPropertyGridItemBrickColor;\n'))
extra = ['/I' + str(pending), '/DNATIVE_BRICKCOLOR_SELECTOR_PENDING']
pre = out / 'brickcolor-noinl'
pre.mkdir(exist_ok=True)
code, log = rebuild.run(tc, 'cl', extra + [x for x in flags if x != '/c'] + xtp + ['/P', str(source)], pre)
assert code == 0, log[-3000:]
body = (pre / (source.stem + '.i')).read_text(errors='replace')
for needle in ('const _Elem * c_str() const', 'operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );'):
    assert body.count(needle) == 1, needle
    body = body.replace(needle, '__declspec(noinline) ' + needle)
unit = out / 'NativePropertyGridItemBrickColorProfile.cpp'
unit.write_text(body)
obj = out / 'NativePropertyGridItemBrickColorProfile.obj'
compile_flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/fp:fast', '/Fo' + str(obj), str(unit)]
code, log = rebuild.run(tc, 'cl', compile_flags, out)
assert code == 0, log[-3000:]

pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
image = pe.OPTIONAL_HEADER.ImageBase
def data(address, size):
    return pe.get_data(address - image, size)
u32 = lambda address: struct.unpack('<I', data(address, 4))[0]
imports = {x.address: (d.dll.decode().lower(), x.ordinal, x.name.decode() if x.name else None)
           for d in pe.DIRECTORY_ENTRY_IMPORT for x in d.imports}
mfc = {}
for line in (root / 'tools/libs/mfc-9.0-rtm/atlmfc/src/mfc/intel/mfc90.def').read_text(errors='ignore').splitlines():
    m = re.match(r'\s*(\S+)\s+@\s*(\d+)', line)
    if m:
        mfc[int(m.group(2))] = m.group(1)

def imported(value):
    slot = value
    if slot not in imports:
        head = data(value, 6)
        if head[:2] != b'\xff\x25':
            return None
        slot = struct.unpack_from('<I', head, 2)[0]
        if slot not in imports:
            return None
    dll, ordinal, name = imports[slot]
    return dll, (mfc.get(ordinal) if dll == 'mfc90.dll' else name)

def plain(symbol):
    if symbol.startswith('__imp_'):
        symbol = symbol[6:]
    if symbol.startswith('?'):
        return symbol
    return re.sub(r'@\d+$', '', symbol[1:] if symbol.startswith('_') else symbol)

C = 'CPropertyGridItemBrickColor'
S = 'V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@'
METHODS = [
    ('?brickColorName@%s@@CA?A%sK@Z' % (C, S), 0x437a20),
    ('?SetColor@%s@@UAEXK@Z' % C, 0x437ab0),
    ('??0%s@@QAE@%sK@Z' % (C, S), 0x437ae0),
    ('?brickColorRef@%s@@CAK%s@Z' % (C, S), 0x437b90),
    ('??1%s@@UAE@XZ' % C, 0x437c10),
    ('??_E%s@@WCA@AEPAXI@Z' % C, 0x438020),
    ('?SetValue@%s@@UAEX%s@Z' % (C, S), 0x4381f0),
    ('??_G%s@@UAEPAXI@Z' % C, 0x438290),
    ('?OnInplaceButtonDown@%s@@MAEXPAVCXTPPropertyGridInplaceButton@@@Z' % C, 0x4382b0),
]
# XTP header inlines emitted as COMDATs in this unit (owned by XTP; matched and bound, not class methods).
INLINES = [('?GetValue@CXTPPropertyGridItem@@QBE?A%sXZ' % S, 0x437ed0),
           ('?GetColor@CXTPPropertyGridItemColor@@UBEKXZ', 0x43a1c0)]

# Internal targets bound from original call sites (address -> how proven).
INTERNAL = {
    '??0CXTPPropertyGridItemColor@@QAE@PBDKPAK@Z': ('0x713b80', 'XTP: stores CXTPPropertyGridItemColor vptrs 0085d7c4/0085d764, ret 0xc'),
    '??1CXTPPropertyGridItemColor@@UAE@XZ': ('0x713760', 'XTP: stores CXTPPropertyGridItemColor vptrs then jumps to ~CXTPPropertyGridItem'),
    '?SetValue@CXTPPropertyGridItem@@UAEX%s@Z' % S: ('0x7119f0', 'XTP CXTPPropertyGridItem vtable slot 24 base body (non-virtual call)'),
    '?GetItemRect@CXTPPropertyGridItem@@QBE?AVCRect@@XZ': ('0x711bf0', 'XTP item rect (hidden CRect return)'),
    '?SendNotifyMessageA@CXTPPropertyGridView@@QAEJIJ@Z': ('0x714100', 'XTP grid view notify, ecx = m_pGrid (+0xbc)'),
    '?CreatePopupBar@CXTPPopupBar@@SAPAV1@PAVCXTPCommandBars@@@Z': ('0x6ee720', 'XTP static, cdecl one arg; result +0xfc = m_pControls'),
    '?Add@CXTPControls@@QAEPAVCXTPControl@@PAV2@HPBDHH@Z': ('0x6f48d0', 'XTP CXTPControls::Add(ctrl, 0, NULL, -1, FALSE)'),
    '?TrackPopupMenu@CXTPCommandBars@@SAHPAVCXTPPopupBar@@IHHPAVCWnd@@PBUtagRECT@@1@Z': ('0x6a4fb0', 'XTP static cdecl, 7 args'),
    '??0CRobloxControlColorSelector@@QAE@XZ': ('0x44ec60', 'native CRobloxControlColorSelector constructor (exact in its recorder); operator new(0x184)'),
    '?SetColor@CRobloxControlColorSelector@@QAEXK@Z': ('0x44de10', 'native CRobloxControlColorSelector::SetColor (exact in its recorder)'),
    '?GetColor@CRobloxControlColorSelector@@QBEKXZ': ('0x44de00', 'native CRobloxControlColorSelector::GetColor (exact in its recorder)'),
    '?closest@BrickColor@RBX@@SA?AV12@VColor3@G3D@@@Z': ('0x5b62e0', 'offline evidence name'),
    '?name@BrickColor@RBX@@QBEABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ': ('0x5b61b0', 'offline evidence name (score 100)'),
    '?parse@BrickColor@RBX@@SA?AV12@PBD@Z': ('0x5b5cb0', 'offline evidence name'),
    '?color3uint8@BrickColor@RBX@@QBE?AVColor3uint8@G3D@@XZ': ('0x5b6180', 'call site only (same binding as CRobloxControlColorSelector recorder)'),
    '??_E%s@@UAEPAXI@Z' % C: ('0x438290', 'vector deleting destructor folded with the scalar one (identical code, exact here); +0x20 thunk 00438020 jumps there'),
    '??_C@_00CNPNBAHC@?$AA@': ('0x80b716', 'empty string literal (NUL byte checked below)'),
    '__real@3b808081': ('0x8135d4', 'float 1/255 constant'),
}
OWN = {n: a for n, a in METHODS + INLINES}
LOCAL_EH = re.compile(r'^(__ehhandler\$|__unwindfunclet\$|__catch\$|__tryblocktable\$|__unwindtable\$|__ehfuncinfo\$|\$LN\d|__catchsym\$)')

def vtable_identity(symbol, value):
    cls = symbol[4:symbol.index('@@6B') + 2]
    locator = u32(value - 4)
    rtti = pe.get_string_at_rva(u32(locator + 12) + 8 - image).decode()
    assert rtti == '.?AV' + cls, (symbol, hex(value), rtti)
    return '%s (RTTI %s, offset %#x)' % (hex(value), rtti, u32(locator + 4))

raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
discovered = {}
def bind(name, address):
    start, section = definitions[name]
    body_size = len(bodies[name][0])
    target, _, _ = match.target('2008-06', '%08x' % address)
    table = sections[section]
    code = raw[table[4] + start:]
    verified, local = {}, set()
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        offset -= start
        if not 0 <= offset < body_size:
            continue
        symbol = symbols[index][0]
        if kind == 20:
            value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        else:
            value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
        if LOCAL_EH.match(symbol):
            local.add(symbol); continue
        hit = imported(value)
        if hit is not None:
            assert hit[1] == plain(symbol), (name, symbol, hex(value), hit)
            verified[symbol] = '%s!%s' % hit
        elif symbol.startswith('??_7'):
            verified[symbol] = vtable_identity(symbol, value)
        elif symbol in OWN:
            assert OWN[symbol] == value, (name, symbol, hex(value))
            verified[symbol] = '%s (exact here)' % hex(value)
        elif DISCOVER:
            discovered.setdefault(symbol, set()).add(hex(value))
        else:
            assert symbol in INTERNAL and int(INTERNAL[symbol][0], 16) == value, (name, symbol, hex(value))
            verified[symbol] = '%s (%s)' % (hex(value), INTERNAL[symbol][1])
    return verified, sorted(local)

rows = []
for name, address in METHODS + INLINES:
    b, r = bodies[name]
    target, target_refs, _ = match.target('2008-06', '%08x' % address)
    assert match.exact_match(target, target_refs, b, r), (name, hex(address), len(b), len(target))
    verified, local = bind(name, address)
    rows.append({'address': '%08x' % address, 'symbol': name, 'size': len(b), 'exact': True,
                 'pending_guard': address == 0x4382b0, 'inline_owner': (name, address) in INLINES,
                 'verified_targets': verified, 'local_eh': local})
if DISCOVER:
    for k, v in sorted(discovered.items()):
        print(sorted(v), k)
    sys.exit(0)

# 3. vtables: own slots bind to the original values; every other slot equals CXTPPropertyGridItemColor's own
# vtable (0085d7c4 / 0085d764) and is a base-class symbol (or a folded COMDAT body proven exact here).
BASE_VTABLE = {0x813644: 0x85d7c4, 0x8135e4: 0x85d764}
def check_vtable(name, address, count):
    start, section = definitions[name]
    table = sections[section]
    slots = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if start <= offset < start + count * 4:
            slots[(offset - start) // 4] = symbols[index][0]
    assert len(slots) == count and table[3] - start == count * 4, (name, len(slots), table[3] - start)
    proof = {}
    for slot, symbol in sorted(slots.items()):
        value = u32(address + 4 * slot)
        inherited = u32(BASE_VTABLE[address] + 4 * slot)
        if symbol in OWN:
            assert OWN[symbol] == value, (slot, symbol, hex(value))
            proof[slot] = 'own exact' + (' (identical COMDAT folded with the base slot)' if value == inherited else '')
        elif symbol in INTERNAL:
            assert int(INTERNAL[symbol][0], 16) == value, (slot, symbol, hex(value))
            proof[slot] = INTERNAL[symbol][1] + (' (folded with the base slot)' if value == inherited else '')
        else:
            assert value == inherited, (slot, symbol, hex(value), hex(inherited))
            assert C not in symbol, (slot, symbol)
            proof[slot] = 'inherited: equals %08x slot %d' % (BASE_VTABLE[address], slot)
    return proof
primary = check_vtable('??_7%s@@6BCCmdTarget@@@' % C, 0x813644, 60)
secondary = check_vtable('??_7%s@@6BCXTPAccessible@@@' % C, 0x8135e4, 23)
overridden = sorted(s for s, p in primary.items() if p.startswith('own') and 'folded' not in p)
assert overridden == [24, 52, 57], overridden

assert data(0x80b716, 1) == b'\0'

# 4. RTTI chain from the primary vtable's complete object locator.
col = u32(0x813644 - 4)
hierarchy = u32(col + 16)
bases = []
for index in range(u32(hierarchy + 8)):
    record = u32(u32(hierarchy + 12) + 4 * index)
    bases.append((pe.get_string_at_rva(u32(record) + 8 - image).decode(), struct.unpack('<i', data(record + 8, 4))[0]))
assert bases[:3] == [('.?AV%s@@' % C, 0), ('.?AVCXTPPropertyGridItemColor@@', 0), ('.?AVCXTPPropertyGridItem@@', 0)], bases
assert ('.?AVCXTPAccessible@@', 0x20) in bases and ('.?AVCCmdTarget@@', 0) in bases, bases

# 5. constructing site: XItem<RBX::BrickColor, ...> constructor 0043b400 calls 00437ae0 and builds the
# CPropGrid::Item base at +0x118; its factory 0043d560 is reached with operator new(0x13c) in 00440e30.
cs = Cs(CS_ARCH_X86, CS_MODE_32)
cs.detail = True
xitem, _, _ = match.target('2008-06', '0043b400')
ins = list(cs.disasm(xitem, 0x43b400))
assert any(i.mnemonic == 'call' and i.op_str == '0x437ae0' for i in ins)
assert any(i.mnemonic == 'lea' and i.op_str == 'ebx, [esi + 0x118]' for i in ins)
factory, _, _ = match.target('2008-06', '00440e30')
allocation, previous, sizes = None, None, {}
for i in cs.disasm(factory, 0x440e30):
    if i.mnemonic == 'call' and i.op_str.startswith('0x'):
        destination = int(i.op_str, 16)
        if destination == 0x6a0920 and previous.mnemonic == 'push' and previous.operands[0].type == X86_OP_IMM:
            allocation = previous.operands[0].imm
        if destination == 0x43d560:
            sizes[destination] = allocation
    previous = i
assert sizes == {0x43d560: 0x13c}, sizes

sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {
    'class': C, 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)', 'flags': flags + xtp,
    'profile': 'unit preprocessed with CString operator PCXSTR + std::string::c_str noinline, compiled ' + ' '.join(compile_flags[:-2])
               + '; OnInplaceButtonDown under NATIVE_BRICKCOLOR_SELECTOR_PENDING with the proposed friend declaration',
    'sources': {str(p.relative_to(root)).replace('\\', '/'): sha(p) for p in [Path(__file__).resolve(), source, fixture, header, selector_header]},
    'object_sha256': sha(obj),
    'layout': {'size': '0x118 (== CXTPPropertyGridItemColor, no own fields)', 'CXTPAccessible': '+0x20',
               'm_nFlags': '0x8c', 'm_strValue': '0xa4', 'm_strDefaultValue': '0xa8', 'm_pGrid': '0xbc', 'm_clrValue': '0x10c'},
    'rtti': bases, 'methods': rows,
    'vtables': {'00813644': primary, '008135e4': secondary},
    'constructed_by': {'0043b400': 'XItem<RBX::BrickColor, CPropertyGridItemBrickColor, ...> constructor (CPropGrid::Item at +0x118)',
                       '0043d560': 'editor factory branch, operator new(0x13c) in 00440e30'},
    'proposed_shared_declarations': ['CRobloxControlColorSelector.h: friend class CPropertyGridItemBrickColor;'],
    'scope': 'Inactive class recovery. XItem<RBX::BrickColor> instantiation (0043b400, update/read/write overrides) remains '
             'with the PropertyGridItems.h owner; no build-list or swap integration.',
}
(root / 'work/2008-06/shared-layouts/property-grid-item-brick-color-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native %s: %d exact rows (%d class methods + %d XTP header inlines)' % (C, len(rows), len(METHODS), len(INLINES)))
