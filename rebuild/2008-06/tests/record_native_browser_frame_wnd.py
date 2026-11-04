"""Verify the inactive native CBrowserFrameWnd (CXTPFrameWnd subclass, no own members): layout test, exact bodies,
every call/data target, the 103-slot vtable, the CRuntimeClass record and the message map.

Profile: the document-swap flags with this checkout's include roots (document-swap-current.json records the owner PC's
C:\\Users\\colin paths, remapped here) plus the XTP 11.2.2 headers (/D_XTP_STATICLINK); MSVC 15.00.21022 (VS2008 RTM).
The original is the registered client clients/2008-06/Roblox.exe, checked against clients/clients.json (the pinned
work/2008-06/original-p4-reference/Roblox.exe copy is not present in every checkout).
XTP call targets are proven by compiling the XTP 11.2.2 library units (recipe xtp-11.2.2-shared-mfc: /O2 /MD /GS /EHsc /Ob1)
and matching their bodies at the bound address.
Writes work/2008-06/shared-layouts/browser-frame-wnd-working.json.
"""
import hashlib
import json
import re
import struct
import sys
from pathlib import Path

import pefile

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(HERE))
import native_bind  # noqa: E402
from native_bind import XTP_FLAGS, plain, rebuild, sha  # noqa: E402
from roc import match  # noqa: E402

OWNER_ROOT = 'C:' + chr(92) + 'Users' + chr(92) + 'colin' + chr(92) + 'RoConstruct'
CLIENT = ROOT / 'clients/2008-06/Roblox.exe'
LOCAL_EH = native_bind.LOCAL_EH
OUT = ROOT / 'rebuild/2008-06/out/native-layouts/browser-frame-wnd'
OUT.mkdir(parents=True, exist_ok=True)
HEADER = ROOT / 'rebuild/2008-06/native-headers/CBrowserFrameWnd.h'
SOURCE = ROOT / 'rebuild/2008-06/native-classes/CBrowserFrameWnd.cpp'
LAYOUT = HERE / 'NativeBrowserFrameWndLayout.cpp'
RECEIPT = ROOT / 'work/2008-06/shared-layouts/browser-frame-wnd-working.json'


def flags():
    base = json.loads((ROOT / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
    return [x.replace(OWNER_ROOT, str(ROOT)) for x in base['flags']
            if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]


FLAGS = flags()
tool = rebuild.toolchain(21022)


class Client(native_bind.Original):
    """The registered 2008-06 client, accepted only when its hash is the one clients.json records."""
    def __init__(self):
        expected = json.loads((ROOT / 'clients/clients.json').read_text())['2008-06']['sha256']
        assert sha(CLIENT) == expected, 'clients/2008-06/Roblox.exe does not match clients.json'
        self.path = CLIENT
        self.pe = pefile.PE(str(CLIENT))
        self.image = self.pe.OPTIONAL_HEADER.ImageBase
        self.imports = {x.address: (d.dll.decode().lower(), x.ordinal, x.name.decode() if x.name else None)
                        for d in self.pe.DIRECTORY_ENTRY_IMPORT for x in d.imports}
        self.mfc = {}
        for line in (ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/src/mfc/intel/mfc90.def').read_text(errors='ignore').splitlines():
            m = re.match(r'\s*(\S+)\s+@\s*(\d+)', line)
            if m:
                self.mfc[int(m.group(2))] = m.group(1)


original = Client()


def compile_one(source, obj, extra=()):
    code, log = rebuild.run(tool, 'cl', FLAGS + XTP_FLAGS + list(extra) + ['/Fo' + str(obj), str(source)], OUT)
    assert code == 0, log[-3000:]
    return obj


layout_obj = compile_one(LAYOUT, OUT / 'NativeBrowserFrameWndLayout.obj')
obj = compile_one(SOURCE, OUT / 'CBrowserFrameWnd.obj')

# XTP library bodies for the out-of-line XTP calls.
XTP_SRC = ROOT / 'tools/libs/xtp-11.2.2/Source'
xtp_bodies = {}
for rel in ('CommandBars/XTPFrameWnd.cpp', 'CommandBars/XTPCommandBars.cpp', 'CommandBars/XTPControlComboBox.cpp'):
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
    '?GetThisClass@CXTPFrameWnd@@SGPAUCRuntimeClass@@XZ': 0x6e1930,
    '??0CXTPFrameWnd@@QAE@XZ': 0x6e1960,
    '?GetThisClass@CXTPEdit@@SGPAUCRuntimeClass@@XZ': 0x6a67c0,
    '?PreTranslateFrameMessage@CXTPCommandBars@@QAEHPAUtagMSG@@@Z': 0x6a4ae0,
    '?OnFrameWndMsg@CXTPCommandBars@@QAEHIIJPAJ@Z': 0x6a4d30,
    '?GetShortcutManager@CXTPCommandBars@@QBEPAVCXTPShortcutManager@@XZ': 0x6a2940,
    '?OnSetPreviewMode@CXTPCommandBars@@QAEXH@Z': 0x6a3a10,
}
xtp_proof = {}
for symbol, address in XTP_TARGETS.items():
    t, tr, _ = match.target('2008-06', '%08x' % address)
    hit = xtp_bodies.get(symbol)
    xtp_proof[symbol] = 'XTP recipe body exact' if hit and match.exact_match(t, tr, hit[0], hit[1]) else 'bound by call site only'

C = 'CBrowserFrameWnd'
SITE = '?$CXTPCommandBarsSiteBase@VCFrameWnd@@'
BASE = '?$CXTPFrameWndBase@VCFrameWnd@@'
METHODS = [
    ('?_GetBaseClass@%s@@KGPAUCRuntimeClass@@XZ' % C, 0x432fb0),
    ('?GetRuntimeClass@%s@@UBEPAUCRuntimeClass@@XZ' % C, 0x432fc0),
    ('?GetThisClass@%s@@SGPAUCRuntimeClass@@XZ' % C, 0x432fc0),
    ('??1%s@@UAE@XZ' % SITE, 0x432fd0),
    ('?PreTranslateMessage@%s@@MAEHPAUtagMSG@@@Z' % SITE, 0x433030),
    ('?OnWndMsg@%s@@MAEHIIJPAJ@Z' % SITE, 0x4330c0),
    ('??_G%s@@UAEPAXI@Z' % SITE, 0x433110),
    ('?OnCreate@%s@@IAEHPAUtagCREATESTRUCTA@@@Z' % C, 0x433130),
    ('?LoadFrame@%s@@UAEHIKPAVCWnd@@PAUCCreateContext@@@Z' % BASE, 0x4331c0),
    ('?OnSetPreviewMode@%s@@UAEXHPAUCPrintPreviewState@@@Z' % BASE, 0x433210),
    ('??_G%s@@UAEPAXI@Z' % C, 0x433240),
    ('??_G%s@@UAEPAXI@Z' % BASE, 0x433240),
    ('?GetMessageMap@%s@@MBEPBUAFX_MSGMAP@@XZ' % C, 0x433270),
    ('?GetThisMessageMap@%s@@KGPBUAFX_MSGMAP@@XZ' % C, 0x433270),
    ('?CreateObject@%s@@SGPAVCObject@@XZ' % C, 0x433280),
]
INTERNAL = dict(XTP_TARGETS)
INTERNAL.update({
    '?class%s@%s@@2UCRuntimeClass@@B' % (C, C): 0x811e90,
    '?messageMap@?1??GetThisMessageMap@%s@@KGPBUAFX_MSGMAP@@XZ@4U3@B' % C: 0x8121f0,
    '??_7%s@@6B@' % C: 0x81225c,
    '??_7%s@@6B@' % BASE: 0x812054,
    '??_7%s@@6B@' % SITE: 0x811eb4,
})

present = {n for n, b, r in match.coff_functions(obj.read_bytes())}
missing = [n for n, a in METHODS if n not in present]
assert not missing, missing
rows = native_bind.verify(original, obj, METHODS, INTERNAL)

# 103-slot vtable of CBrowserFrameWnd: own slots bind to exact bodies, CObject's empty inlines to exact COMDATs, every
# other slot to the matching mfc90 import thunk.
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
OWN = dict(METHODS)


def relocs(section):
    table = sections[section]
    return [struct.unpack_from('<IIH', raw, table[5] + 10 * i) for i in range(table[7])]


def prove_slot(symbol, value):
    hit = original.imported(value)
    if hit is not None:
        assert hit[1] == plain(symbol), (symbol, hex(value), hit)
        return '%s!%s' % hit
    if symbol.startswith('??_E') and symbol not in bodies:
        # COFF weak external: the vector deleting destructor defaults to the scalar one (no delete[] in this unit).
        alias = '??_G' + symbol[4:]
        assert OWN[alias] == value, (symbol, hex(value))
        return 'exact here (weak external of %s)' % alias
    if symbol in OWN:
        assert OWN[symbol] == value, (symbol, hex(value))
        return 'exact here'
    if symbol in bodies:
        b, r = bodies[symbol]
        t, tr, _ = match.target('2008-06', '%08x' % value)
        assert match.exact_match(t, tr, b, r), (symbol, hex(value))
        return 'header COMDAT, body exact'
    raise AssertionError((symbol, hex(value)))


def check_vtable(name, address, count):
    start, section = definitions[name]
    slots = {}
    for offset, index, kind in relocs(section):
        if start <= offset < start + count * 4:
            slots[(offset - start) // 4] = symbols[index][0]
    assert len(slots) == count and sections[section][3] - start == count * 4, (name, len(slots))
    values = struct.unpack('<%dI' % count, original.data(address, count * 4))
    rtti, off = original.vtable_class(address)
    assert rtti == '.?AV' + name[4:name.index('@@6B')] + '@@' and off == 0, (name, rtti, off)
    return {slot: '%08x %s: %s' % (values[slot], symbol, prove_slot(symbol, values[slot]))
            for slot, symbol in sorted(slots.items())}


vtable = check_vtable('??_7%s@@6B@' % C, 0x81225c, 103)
assert [slot for slot, row in vtable.items() if row.split(': ', 1)[1].startswith('exact here')] == [0, 1, 12, 68, 71, 82, 92], vtable
# the CXTPFrameWndBase table (00812054) differs from CBrowserFrameWnd's only in slots 0 (CFrameWnd::GetRuntimeClass
# import) and 12 (CFrameWnd::GetMessageMap import) (the browser frame overrides nothing else).
a = struct.unpack('<103I', original.data(0x81225c, 412))
b = struct.unpack('<103I', original.data(0x812054, 412))
assert [i for i in range(103) if a[i] != b[i]] == [0, 12], [i for i in range(103) if a[i] != b[i]]
# AFX_MSGMAP at 008121f0 (base getter CFrameWnd::GetThisMessageMap, entries 008121f8) is exact against the unit's data.
pfn_base, entries = struct.unpack('<II', original.data(0x8121f0, 8))
assert original.imported(pfn_base) == ('mfc90.dll', '?GetThisMessageMap@CFrameWnd@@KGPBUAFX_MSGMAP@@XZ')
parsed = [struct.unpack('<6I', original.data(entries + 24 * i, 24)) for i in range(4)]
assert parsed[0][:5] == (0x2, 0, 0, 0, 0x13) and original.imported(parsed[0][5]) == ('mfc90.dll', '?OnDestroy@CFrameWnd@@IAEXXZ')
assert parsed[1] == (0x1, 0, 0, 0, 0xd, 0x433130)
assert parsed[2][:5] == (0x82, 0, 0, 0, 0x13) and original.imported(parsed[2][5]) == ('mfc90.dll', '?OnNcDestroy@CWnd@@IAEXXZ')
assert parsed[3] == (0, 0, 0, 0, 0, 0)
# CRuntimeClass record at 00811e90: name 00811e70, size 0xec, schema 0xffff, CreateObject, base getter, no next.
rec = struct.unpack('<IiIIIII', original.data(0x811e90, 28))
assert original.string(rec[0]) == C and rec[1:] == (0xec, 0xffff, 0x433280, 0x432fb0, 0, 0), rec
# the vtable and CRuntimeClass bytes the compiled unit emits agree with the original outside relocations
for symbol, address, size in (('?class%s@%s@@2UCRuntimeClass@@B' % (C, C), 0x811e90, 28),
                              ('?messageMap@?1??GetThisMessageMap@%s@@KGPBUAFX_MSGMAP@@XZ@4U3@B' % C, 0x8121f0, 8),
                              ('?_messageEntries@?1??GetThisMessageMap@%s@@KGPBUAFX_MSGMAP@@XZ@4QBUAFX_MSGMAP_ENTRY@@B' % C, 0x8121f8, 96)):
    start, section = definitions[symbol]
    code = raw[sections[section][4] + start:sections[section][4] + start + size]
    target = original.data(address, size)
    fixed = set()
    for offset, index, kind in relocs(section):
        if start <= offset < start + size:
            fixed.update(range(offset - start, offset - start + 4))
    assert all(code[i] == target[i] for i in range(size) if i not in fixed), (symbol, code.hex(), target.hex())

weak = [s for s, p in xtp_proof.items() if p != 'XTP recipe body exact']
RECEIPT.write_text(json.dumps({
    'class': C, 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)', 'flags': FLAGS + XTP_FLAGS,
    'original': 'clients/2008-06/Roblox.exe', 'original_sha256': sha(CLIENT), 'object_sha256': sha(obj),
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in (Path(__file__), SOURCE, HEADER, LAYOUT)},
    'layout': {'sizeof': '0xec = sizeof(CXTPFrameWnd) (CRuntimeClass 00811e90, operator new(0xec) in CreateObject 00433280); '
                         'no own members: deleting destructor 00433240 stores only a vptr and calls 00432fd0, which '
                         'releases the site-base pointer at +0xe8',
               'layout_test': 'tests/NativeBrowserFrameWndLayout.cpp compiled into ' + layout_obj.name},
    'xtp_targets': {'%08x' % XTP_TARGETS[s]: '%s: %s' % (s, xtp_proof[s]) for s in XTP_TARGETS},
    'methods': rows, 'vtable_00_81225c': vtable,
    'runtime_class': {'address': '00811e90', 'name': C, 'size': '0xec', 'create_object': '00433280', 'base_getter': '00432fb0'},
    'message_map': {'address': '008121f0', 'entries': 'WM_DESTROY -> CFrameWnd::OnDestroy, WM_CREATE -> 00433130, '
                                                         'WM_NCDESTROY -> CWnd::OnNcDestroy',
                    'base': 'CFrameWnd::GetThisMessageMap'},
    'open': {}}, indent=2) + '\n')
print('PASS native %s: %d exact rows (%d distinct addresses), vtable 103 slots verified; XTP targets body-proven %d/%d%s'
      % (C, len(rows), len({r['address'] for r in rows}), len(XTP_TARGETS) - len(weak), len(XTP_TARGETS),
         (' (call-site only: %s)' % ', '.join(weak)) if weak else ''))
