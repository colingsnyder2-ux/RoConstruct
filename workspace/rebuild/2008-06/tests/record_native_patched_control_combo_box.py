"""Verify the inactive native CPatchedControlComboBox: layout, exact bodies, call/data targets, vtables, CRuntimeClass.

Profile: document-swap flags + XTP 11.2.2 headers (/UNOMINMAX /D_XTP_STATICLINK). Inherited call targets are proven by
compiling the XTP library units (recipe copy xtp-11.2.2-shared-mfc: /O2 /MD /GS /EHsc /Ob1) and matching their bodies.
Run with DISCOVER=1 to list unproven relocation bindings.
"""
import hashlib, json, os, re, struct, sys
from pathlib import Path
import pefile

root = Path(__file__).resolve().parents[3]
here = Path(__file__).resolve().parent
sys.path.insert(0, str(root))
from roc import match, rebuild  # noqa: E402

DISCOVER = os.environ.get('DISCOVER')
out = root / 'rebuild/2008-06/out/native-layouts'
out.mkdir(parents=True, exist_ok=True)
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x
         for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
xtp = ['/UNOMINMAX', '/I' + str(root / 'tools/libs/xtp-11.2.2/Source'), '/D_XTP_STATICLINK']
source = root / 'rebuild/2008-06/native-classes/CPatchedControlComboBox.cpp'
fixture = here / 'NativePatchedControlComboBoxLayout.cpp'
header = root / 'rebuild/2008-06/native-headers/CPatchedControlComboBox.h'
obj = out / 'NativePatchedControlComboBox.obj'
for path, target in [(source, obj), (fixture, out / 'NativePatchedControlComboBoxLayout.obj')]:
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + xtp + ['/Fo' + str(target), str(path)], out)
    assert code == 0, log

pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
image = pe.OPTIONAL_HEADER.ImageBase
def data(address, size):
    return pe.get_data(address - image, size)
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
    dll, ordinal, name = imports[slot]
    return dll, (mfc.get(ordinal) if dll == 'mfc90.dll' else name)

def plain(symbol):
    if symbol.startswith('__imp_'):
        symbol = symbol[6:]
    if symbol.startswith('?'):
        return symbol
    return re.sub(r'@\d+$', '', symbol[1:] if symbol.startswith('_') else symbol)

C = 'CPatchedControlComboBox'
METHODS = [
    ('?_GetBaseClass@%s@@KGPAUCRuntimeClass@@XZ' % C, 0x42eb20),
    ('?Compare@%s@@MAEHPAVCXTPControl@@@Z' % C, 0x42eac0),
    ('?GetRuntimeClass@%s@@UBEPAUCRuntimeClass@@XZ' % C, 0x42eb30),
    ('??_E%s@@WCA@AEPAXI@Z' % C, 0x42f070),
    ('?CreateObject@%s@@SGPAVCObject@@XZ' % C, 0x42fd50),
    ('??_G%s@@UAEPAXI@Z' % C, 0x42fdb0),
    ('?Clone@%s@@UAEPAVCXTPControl@@H@Z' % C, 0x42fdd0),
]
OWN = dict(METHODS)
LOCAL_EH = re.compile(r'^(__ehhandler\$|__unwindfunclet\$|__catch\$|__tryblocktable\$|__unwindtable\$|__ehfuncinfo\$|\$LN\d|__catchsym\$)')

# XTP library bodies for the base calls: compile the recipe units and match each candidate at its bound address.
XTP_SRC = str(root / 'tools/libs/xtp-11.2.2/Source')
(out / 'xtp-combo-box').mkdir(exist_ok=True)
xtp_bodies = {}
for unit in ('CommandBars/XTPControlComboBox.cpp', 'CommandBars/XTPControl.cpp'):
    o = out / 'xtp-combo-box' / (Path(unit).stem + '.obj')
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', ['/nologo', '/c', '/O2', '/MD', '/GS', '/EHsc', '/Ob1', '/D_AFXDLL',
                            '/D_XTP_STATICLINK', '/D_DLL', '/I' + XTP_SRC, '/I' + str(root / 'tools/libs/mfc-9.0/atlmfc/include'),
                            '/Fo' + str(o), XTP_SRC + '/' + unit], out / 'xtp-combo-box')
    assert code == 0, log
    xtp_bodies.update({n: (b, r) for n, b, r in match.coff_functions(o.read_bytes())})

def weak_externals(raw):
    # COFF weak externals: MSVC leaves ??_E (vector deleting dtor) as a weak alias of ??_G when the unit has no delete[].
    ptr, count = struct.unpack_from('<II', raw, 8)
    strings = ptr + 18 * count
    def name(i):
        e = raw[ptr + 18 * i:ptr + 18 * i + 8]
        if e[:4] == b'\0\0\0\0':
            o = strings + struct.unpack_from('<I', e, 4)[0]
            return raw[o:raw.index(b'\0', o)].decode()
        return e.rstrip(b'\0').decode()
    result, i = {}, 0
    while i < count:
        cls, aux = struct.unpack_from('<BB', raw, ptr + 18 * i + 16)
        if cls == 105 and aux:
            result[name(i)] = name(struct.unpack_from('<I', raw, ptr + 18 * (i + 1))[0])
        i += 1 + aux
    return result
WEAK = weak_externals(obj.read_bytes())

def body_proof(symbol, value):
    if symbol in WEAK and WEAK[symbol] in OWN and OWN[WEAK[symbol]] == value:
        return 'weak external (COFF class 105) defaulting to %s, exact here' % WEAK[symbol]
    if symbol in xtp_bodies:
        b, r = xtp_bodies[symbol]
        t, tr, _ = match.target('2008-06', '%08x' % value)
        if match.exact_match(t, tr, b, r):
            return 'XTP 11.2.2 recipe build: body exact'
    return None

def vtable_identity(symbol, value):
    cls = symbol[4:symbol.index('@@6B') + 2]
    locator = struct.unpack('<I', data(value - 4, 4))[0]
    descriptor = struct.unpack('<I', data(locator + 12, 4))[0]
    rtti = pe.get_string_at_rva(descriptor + 8 - image).decode()
    assert rtti == '.?AV' + cls, (symbol, hex(value), rtti)
    return '%s (RTTI %s, offset %#x)' % (hex(value), rtti, struct.unpack('<I', data(locator + 4, 4))[0])

# Data targets proven by content (not code): CRuntimeClass records and the AFX_CLASSINIT byte.
def runtime_identity(value, name):
    rec = struct.unpack('<IiIIIII', data(value, 28))
    got = pe.get_string_at_rva(rec[0] - image).decode()
    assert got == name, (hex(value), got, name)
    return '%s (CRuntimeClass "%s")' % (hex(value), got)
DATA = {
    '?class%s@%s@@2UCRuntimeClass@@A' % (C, C): lambda v: runtime_identity(v, C),
    '?_init_%s@@3UAFX_CLASSINIT@@A' % C: lambda v: (assert_eq(v, 0x96d13a), '0x96d13a (CRuntimeClass 0092ecc8 pClassInit field)')[1],
    '?classCXTPControlComboBox@CXTPControlComboBox@@2UCRuntimeClass@@B': lambda v: runtime_identity(v, 'CXTPControlComboBox'),
}
def assert_eq(a, b):
    assert a == b, (hex(a), hex(b))

discovered = {}
def bind(raw, name, address):
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    start, section = definitions[name]
    body_size = next(len(b) for n, b, _ in match.coff_functions(raw) if n == name)
    target, _, _ = match.target('2008-06', '%08x' % address)
    code = raw[sections[section][4] + start:]
    table = sections[section]
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
        elif symbol in DATA:
            verified[symbol] = DATA[symbol](value)
        else:
            p = body_proof(symbol, value)
            if p:
                verified[symbol] = '%s (%s)' % (hex(value), p)
            elif DISCOVER:
                discovered.setdefault(symbol, set()).add(hex(value))
            else:
                raise AssertionError((name, symbol, hex(value)))
    return verified, sorted(local)

raw = obj.read_bytes()
bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
rows = []
for name, address in METHODS:
    b, r = bodies[name]
    target, target_refs, _ = match.target('2008-06', '%08x' % address)
    assert match.exact_match(target, target_refs, b, r), (name, hex(address), len(b), len(target))
    verified, local = bind(raw, name, address)
    rows.append({'address': '%08x' % address, 'symbol': name, 'size': len(b), 'exact': True, 'profile': 'XTP headers',
                 'verified_targets': verified, 'local_eh': local})
if DISCOVER:
    for k, v in sorted(discovered.items()):
        print(sorted(v), k)
    sys.exit(0)

# Vtables: own slots bind to this unit's exact bodies; every other slot equals CXTPControlComboBox's vtable slot
# (RTTI vtables 0085091c / 008508bc, same counts) and, where this unit emits the inherited header COMDAT, its body
# is exact at the slot address too.
sections, symbols, definitions, _ = match._coff_data_index(raw)
BASE_VTABLE = {0x810914: 0x85091c, 0x8108b4: 0x8508bc}
BASES = ('@CXTPControlComboBox@@', '@CXTPControlPopup@@', '@CXTPControlButton@@', '@CXTPControl@@', '@CXTPAccessible@@',
         '@CCmdTarget@@', '@CObject@@', '@CXTPCmdTarget@@')
def check_vtable(name, address, count):
    start, section = definitions[name]
    table = sections[section]
    slots = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if start <= offset < start + count * 4:
            slots[(offset - start) // 4] = symbols[index][0]
    assert len(slots) == count and table[3] - start == count * 4, (name, len(slots), table[3] - start)
    original = struct.unpack('<%dI' % count, data(address, count * 4))
    inherited = struct.unpack('<%dI' % count, data(BASE_VTABLE[address], count * 4))
    proof, unverified = {}, {}
    for slot, symbol in sorted(slots.items()):
        value = original[slot]
        if symbol in OWN:
            assert OWN[symbol] == value, (slot, symbol, hex(value)); proof[slot] = 'own exact %08x' % value
            continue
        hit = imported(value)
        if hit is not None:
            assert hit[1] == plain(symbol); proof[slot] = 'import %s!%s' % hit; continue
        why = []
        if symbol in bodies:
            b, r = bodies[symbol]
            t, tr, _ = match.target('2008-06', '%08x' % value)
            if match.exact_match(t, tr, b, r):
                why.append('header COMDAT exact here')
        p = body_proof(symbol, value)
        if p:
            why.append(p)
        if inherited[slot] == value and any(x in symbol for x in BASES):
            why.append('equals CXTPControlComboBox vtable %08x slot %d' % (BASE_VTABLE[address], slot))
        if why:
            proof[slot] = '%08x %s: %s' % (value, symbol, '; '.join(why))
        else:
            unverified[slot] = (symbol, hex(value))
    return proof, unverified
primary, primary_open = check_vtable('??_7%s@@6BCCmdTarget@@@' % C, 0x810914, 96)
secondary, secondary_open = check_vtable('??_7%s@@6BCXTPAccessible@@@' % C, 0x8108b4, 23)
print('primary vtable: %d verified, open %s' % (len(primary), primary_open))
print('secondary vtable: %d verified, open %s' % (len(secondary), secondary_open))
assert not primary_open and not secondary_open
# Only slots 0 (GetRuntimeClass), 34 (Compare), 81 (Clone) and the secondary thunk differ from CXTPControlComboBox;
# slot 1 (0042fdb0) is shared because both deleting destructors fold to the same code.
diff = [i for i in range(96) if struct.unpack('<I', data(0x810914 + 4 * i, 4)) != struct.unpack('<I', data(0x85091c + 4 * i, 4))]
assert diff == [0, 34, 81], diff

runtime = struct.unpack('<IiIIIII', data(0x92ecc8, 28))
assert data(runtime[0], 24) == b'CPatchedControlComboBox\0'
assert runtime[1:7] == (0x1e0, 0x80000020, 0x42fd50, 0x42eb20, 0, 0x96d13a), [hex(x) for x in runtime]

sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {
    'class': C, 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)', 'flags': flags + xtp,
    'sources': {str(p.relative_to(root)).replace('\\', '/'): sha(p) for p in [Path(__file__), source, fixture, header]},
    'object_sha256': sha(obj),
    'layout': {'size': '0x1e0', 'base': 'CXTPControlComboBox (0x1e0, XTP 11.2.2)', 'CXTPAccessible subobject': '0x20',
               'own members': 'none (ctor inlined in CreateObject 0042fd50 stores only vptrs; dtor 0042fdb0 calls only ~CXTPControlComboBox)'},
    'methods': rows,
    'vtables': {'00810914': {'verified': primary, 'open': primary_open},
                '008108b4': {'verified': secondary, 'open': secondary_open}},
    'runtime_class': {'address': '0092ecc8', 'size': '0x1e0', 'schema': '0x80000020', 'create': '0042fd50',
                      'base_getter': '0042eb20', 'class_init': '0096d13a'},
}
(root / 'work/2008-06/shared-layouts/patched-control-combo-box-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native %s: %d exact rows' % (C, len(rows)))
