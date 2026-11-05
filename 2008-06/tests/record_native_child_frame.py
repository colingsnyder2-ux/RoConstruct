"""Verify the inactive native CChildFrame / CRbxChildFrame: layout, exact bodies, call/data targets, vtables,
CRuntimeClass records and message maps.

Profile: the CMainFrame native profile (rbxgs recipe defines/includes, /O2 /Ob2 /Oy /GF /GS- /EHsc /MD, MFC 9.0 RTM,
XTP 11.2.2 headers with /D_XTP_STATICLINK), VS2008 RTM 21022.

CRbxChildFrame::OnGetMinMaxInfo calls the out-of-line CRenderSettings::getFullscreenSize.
Run with DISCOVER=1 to list unproven relocation bindings.
"""
import hashlib, json, os, re, struct, sys
from pathlib import Path
import pefile

root = Path(__file__).resolve().parents[3]
here = Path(__file__).resolve().parent
sys.path.insert(0, str(root))
from roc import libs, match, rebuild  # noqa: E402

DISCOVER = os.environ.get('DISCOVER')
out = root / 'rebuild/2008-06/out/native-layouts'
out.mkdir(parents=True, exist_ok=True)
recipe = libs.RECIPES['rbxgs']
flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD',
         '/D_AFXDLL', '/DNDEBUG', '/D_MBCS', '/DBOOST_ALL_NO_LIB']
flags += ['/D' + value for value in recipe['defines'].split()]
includes = ['/I' + str(root / 'rebuild/2008-06/native-headers'),
            '/I' + str(root / 'tools/libs/mfc-9.0-rtm/atlmfc/include')]
includes += ['/I' + str((libs.LIBS / value).resolve()) for value in recipe['include'] if value != 'WINSDK']
includes += ['/D_XTP_STATICLINK', '/D_XTPLIB_NOAUTOLINK', '/I' + str(root / 'tools/libs/xtp-11.2.2/Source')]

source = root / 'rebuild/2008-06/native-classes/CChildFrame.cpp'
fixture = here / 'NativeChildFrameLayout.cpp'
header = root / 'rebuild/2008-06/native-headers/CChildFrame.h'
settings_header = root / 'rebuild/2008-06/native-headers/CRenderSettings.h'
obj = out / 'NativeChildFrame.obj'
for path, target, extra in [(source, obj, []), (fixture, out / 'NativeChildFrameLayout.obj', [])]:
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + extra + includes + ['/Fo' + str(target), str(path)], out)
    assert code == 0, log

pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
image = pe.OPTIONAL_HEADER.ImageBase
def data(address, size):
    return pe.get_data(address - image, size)
def cstring(address):
    return pe.get_string_at_rva(address - image)
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

A, B = 'CChildFrame', 'CRbxChildFrame'
METHODS = [
    ('?_GetBaseClass@%s@@KGPAUCRuntimeClass@@XZ' % A, 0x412ae0),
    ('?GetRuntimeClass@%s@@UBEPAUCRuntimeClass@@XZ' % A, 0x412af0),
    ('?GetThisClass@%s@@SGPAUCRuntimeClass@@XZ' % A, 0x412af0),
    ('?_GetBaseClass@%s@@KGPAUCRuntimeClass@@XZ' % B, 0x412af0),
    ('?PreCreateWindow@%s@@UAEHAAUtagCREATESTRUCTA@@@Z' % A, 0x412b00),
    ('?ActivateFrame@%s@@UAEXH@Z' % A, 0x412b40),
    ('?GetRuntimeClass@%s@@UBEPAUCRuntimeClass@@XZ' % B, 0x412b80),
    ('?GetThisClass@%s@@SGPAUCRuntimeClass@@XZ' % B, 0x412b80),
    ('?OnCreate@%s@@IAEHPAUtagCREATESTRUCTA@@@Z' % A, 0x412b90),
    ('?GetMessageMap@%s@@MBEPBUAFX_MSGMAP@@XZ' % A, 0x412c50),
    ('?GetThisMessageMap@%s@@KGPBUAFX_MSGMAP@@XZ' % A, 0x412c50),
    ('??_G%s@@UAEPAXI@Z' % A, 0x412c60),
    ('??_G%s@@UAEPAXI@Z' % B, 0x412c60),
    ('?CreateObject@%s@@SGPAVCObject@@XZ' % A, 0x412c90),
    ('?CreateObject@%s@@SGPAVCObject@@XZ' % B, 0x412cf0),
    ('?GetMessageMap@%s@@MBEPBUAFX_MSGMAP@@XZ' % B, 0x412f20),
    ('?GetThisMessageMap@%s@@KGPBUAFX_MSGMAP@@XZ' % B, 0x412f20),
]
METHODS.append(('?OnGetMinMaxInfo@%s@@IAEXPAUtagMINMAXINFO@@@Z' % B, 0x412e60))
OWN = dict(METHODS)
LOCAL_EH = re.compile(r'^(__ehhandler\$|__unwindfunclet\$|__catch\$|__tryblocktable\$|__unwindtable\$|__ehfuncinfo\$|\$LN\d|__catchsym\$)')

# CRenderSettings bodies proven exact by the CRenderSettings native receipt.
receipt_rows = json.loads((root / 'work/2008-06/shared-layouts/render-settings-working.json').read_text())['methods']
RECEIPT = {r['symbol']: int(r['address'], 16) for r in receipt_rows if r.get('exact')}

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

class Unit:
    def __init__(self, path):
        self.raw = path.read_bytes()
        self.sections, self.symbols, self.definitions, _ = match._coff_data_index(self.raw)
        self.bodies = {n: (b, r) for n, b, r in match.coff_functions(self.raw)}
        self.proven_data = {}
        self.weak = weak_externals(self.raw)

    def relocs(self, section):
        table = self.sections[section]
        return [struct.unpack_from('<IIH', self.raw, table[5] + 10 * i) for i in range(table[7])]

    def extent(self, name):
        start, section = self.definitions[name]
        later = [v for _, (v, s) in self.definitions.items() if s == section and v > start]
        return start, section, min(later + [self.sections[section][3]])

    def compare_data(self, name, address):
        """Defined data: bytes equal outside relocations, every relocation proven at the original value."""
        if name in self.proven_data:
            assert self.proven_data[name][0] == address, (name, hex(address))
            return self.proven_data[name][1]
        start, section, end = self.extent(name)
        size = end - start
        code = self.raw[self.sections[section][4] + start:self.sections[section][4] + end]
        target = data(address, size)
        self.proven_data[name] = (address, None)
        fixed, targets = set(), {}
        for offset, index, kind in self.relocs(section):
            if not start <= offset < end:
                continue
            offset -= start
            assert kind == 6, (name, kind)
            fixed.update(range(offset, offset + 4))
            value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
            symbol = self.symbols[index][0]
            targets['+%#x %s' % (offset, symbol)] = self.prove(symbol, value, name)
        assert all(code[i] == target[i] for i in range(size) if i not in fixed), (name, code.hex(), target.hex())
        result = '%#x (%d bytes equal, %d relocations proven)' % (address, size, len(targets))
        self.proven_data[name] = (address, result)
        return {'address': '%08x' % address, 'size': size, 'targets': targets}

    def prove(self, symbol, value, where):
        hit = imported(value)
        if hit is not None:
            assert hit[1] == plain(symbol), (where, symbol, hex(value), hit)
            return '%s!%s' % hit
        if symbol in OWN:
            assert OWN[symbol] == value, (where, symbol, hex(value))
            return '%#x (exact here)' % value
        if self.weak.get(symbol) in OWN:
            assert OWN[self.weak[symbol]] == value, (where, symbol, hex(value))
            return '%#x (weak external, COFF class 105, defaulting to %s: exact here)' % (value, self.weak[symbol])
        if symbol in RECEIPT:
            assert RECEIPT[symbol] == value, (where, symbol, hex(value))
            return '%#x (exact in work/2008-06/shared-layouts/render-settings-working.json)' % value
        # The stored receipt names the singleton with the template argument sRenderSettings typed const char[]
        # (3PBDB); native-headers/CRenderSettings.h now declares it char[] (3PADA). Same member, same address.
        alias = symbol.replace('$1?sRenderSettings@@3PADA@', '$1?sRenderSettings@@3PBDB@')
        if alias != symbol and alias in RECEIPT:
            assert RECEIPT[alias] == value, (where, symbol, hex(value))
            return '%#x (exact in render-settings-working.json as %s)' % (value, alias)
        if symbol.startswith('??_7'):
            return vtable_identity(symbol, value)
        if symbol.startswith('??_C@'):
            start, section, end = self.extent(symbol)
            literal = self.raw[self.sections[section][4] + start:self.sections[section][4] + end]
            assert data(value, len(literal)) == literal, (symbol, hex(value))
            return '%#x (string %r)' % (value, literal.rstrip(b'\0').decode())
        if symbol in self.bodies:
            b, r = self.bodies[symbol]
            t, tr, _ = match.target('2008-06', '%08x' % value)
            assert match.exact_match(t, tr, b, r), (where, symbol, hex(value))
            return '%#x (header COMDAT, body exact)' % value
        if symbol in self.definitions:
            return self.compare_data(symbol, value)
        if DISCOVER:
            discovered.setdefault(symbol, set()).add(hex(value))
            return 'UNPROVEN'
        raise AssertionError((where, symbol, hex(value)))

    def bind(self, name, address):
        start, section = self.definitions[name]
        body = self.bodies[name][0]
        target, _, _ = match.target('2008-06', '%08x' % address)
        code = self.raw[self.sections[section][4] + start:]
        verified, local = {}, set()
        for offset, index, kind in self.relocs(section):
            offset -= start
            if not 0 <= offset < len(body):
                continue
            symbol = self.symbols[index][0]
            if LOCAL_EH.match(symbol):
                local.add(symbol)
                continue
            if kind == 20:
                value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            else:
                value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
            verified[symbol] = self.prove(symbol, value, name)
        return verified, sorted(local)

def vtable_identity(symbol, value):
    cls = symbol[4:symbol.index('@@6B') + 2]
    locator = struct.unpack('<I', data(value - 4, 4))[0]
    descriptor = struct.unpack('<I', data(locator + 12, 4))[0]
    rtti = cstring(descriptor + 8).decode()
    assert rtti == '.?AV' + cls, (symbol, hex(value), rtti)
    return '%#x (RTTI %s)' % (value, rtti)

discovered = {}
unit = Unit(obj)
rows = []
for name, address in METHODS:
    b, r = unit.bodies[name]
    target, target_refs, _ = match.target('2008-06', '%08x' % address)
    assert match.exact_match(target, target_refs, b, r), (name, hex(address), len(b), len(target))
    verified, local = unit.bind(name, address)
    rows.append({'address': '%08x' % address, 'symbol': name, 'size': len(b), 'exact': True,
                 'verified_targets': verified, 'local_eh': local})
if DISCOVER:
    for k, v in sorted(discovered.items()):
        print(sorted(v), k)
    sys.exit(0)

# Vtables: 105 slots each (the class's AFX_MSGMAP follows at +0x1a4). Own slots bind to this unit's exact bodies,
# CObject's inline empty AssertValid/Serialize/Dump bind to their exact header COMDATs, every other slot is the
# matching mfc90.dll import thunk.
def check_vtable(name, address, count):
    start, section = unit.definitions[name]
    table = unit.sections[section]
    slots = {}
    for offset, index, kind in unit.relocs(section):
        if start <= offset < start + count * 4:
            slots[(offset - start) // 4] = unit.symbols[index][0]
    assert len(slots) == count and table[3] - start == count * 4, (name, len(slots), table[3] - start)
    original = struct.unpack('<%dI' % count, data(address, count * 4))
    return {slot: '%08x %s: %s' % (original[slot], symbol, unit.prove(symbol, original[slot], name))
            for slot, symbol in sorted(slots.items())}
vt_a = check_vtable('??_7%s@@6B@' % A, 0x80e4a4, 105)
vt_b = check_vtable('??_7%s@@6B@' % B, 0x80e684, 105)
assert struct.unpack('<I', data(0x80e4a4 + 105 * 4, 4))[0] == 0x6a0e1e  # CChildFrame messageMap.pfnGetBaseMap
assert struct.unpack('<I', data(0x80e684 + 105 * 4, 4))[0] == 0x412c50  # CRbxChildFrame messageMap.pfnGetBaseMap
own_slots = lambda a, b: [i for i in range(105) if data(a + 4 * i, 4) != data(b + 4 * i, 4)]
assert own_slots(0x80e4a4, 0x80e684) == [0, 12], own_slots(0x80e4a4, 0x80e684)

# CRuntimeClass records and message maps, proven byte for byte (relocations resolved through prove()).
runtime = {}
for cls, address in ((A, 0x80e468), (B, 0x80e484)):
    runtime[cls] = unit.compare_data('?class%s@%s@@2UCRuntimeClass@@B' % (cls, cls), address)
    rec = struct.unpack('<IiIIIII', data(address, 28))
    assert cstring(rec[0]).decode() == cls and rec[1:] == (0xf0, 0xffff, OWN['?CreateObject@%s@@SGPAVCObject@@XZ' % cls],
                                                          OWN['?_GetBaseClass@%s@@KGPAUCRuntimeClass@@XZ' % cls], 0, 0), rec
maps = {}
for cls, address in ((A, 0x80e648), (B, 0x80e828)):
    symbol = next(n for n in unit.definitions if n.startswith('?messageMap@') and '@%s@@' % cls in n)
    maps[cls] = unit.compare_data(symbol, address)

if DISCOVER:
    for k, v in sorted(discovered.items()):
        print(sorted(v), k)
    sys.exit(0)

sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {
    'class': '%s, %s' % (A, B), 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)', 'flags': flags + includes,
    'sources': {str(p.relative_to(root)).replace('\\', '/'): sha(p) for p in [Path(__file__).resolve(), source, fixture, header, settings_header]},
    'object_sha256': sha(obj),
    'layout': {'CChildFrame': '0xf0 = sizeof(CMDIChildWnd), no own members (CRuntimeClass 0080e468, operator new(0xf0) in 00412c90)',
               'CRbxChildFrame': '0xf0, no own members (CRuntimeClass 0080e484, operator new(0xf0) in 00412cf0)',
               'CMDIChildWnd::m_hMenuShared': '0xe8 (cleared by OnCreate 00412b90)'},
    'methods': rows,
    'pending': [],
    'vtables': {'0080e4a4': vt_a, '0080e684': vt_b},
    'runtime_classes': runtime,
    'message_maps': maps,
}
(root / 'work/2008-06/shared-layouts/child-frame-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native %s/%s: %d exact rows (%d distinct addresses), 0 pending' %
      (A, B, len(rows), len({r['address'] for r in rows})))
