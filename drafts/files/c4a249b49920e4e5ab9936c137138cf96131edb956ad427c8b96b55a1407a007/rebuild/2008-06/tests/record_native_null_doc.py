"""Verify the inactive native CNullDoc (CDocument subclass with no added storage): layout test, the exact bodies with
every call/data target, the 46-slot vtable, CRuntimeClass 00812410, the message map 0081242c with its three entries,
and the RTTI hierarchy. Writes work/2008-06/shared-layouts/null-doc-working.json when everything passes; on any
failure it writes a FAIL receipt under work/cnulldoc-guided-20261104/ instead and exits non-zero.

Profile: the document-swap flags with this checkout's include roots (document-swap-current.json records the owner PC's
C:\\Users\\colin paths, remapped here); MSVC 15.00.21022 (VS2008 RTM). The original is the registered client
clients/2008-06/Roblox.exe checked against clients/clients.json. The handler's name (004332f0) and the symbolic name
of command ID 0x80B6 are unknown; the source uses a neutral analog name.
"""
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
from native_bind import plain, rebuild, sha  # noqa: E402
from roc import match  # noqa: E402

OWNER_ROOT = 'C:' + chr(92) + 'Users' + chr(92) + 'colin' + chr(92) + 'RoConstruct'
CLIENT = ROOT / 'clients/2008-06/Roblox.exe'
OUT = ROOT / 'rebuild/2008-06/out/native-layouts/null-doc'
OUT.mkdir(parents=True, exist_ok=True)
HEADER = ROOT / 'rebuild/2008-06/native-headers/CBrowserDoc.h'
SOURCE = ROOT / 'rebuild/2008-06/native-classes/CNullDoc.cpp'
LAYOUT = HERE / 'NativeNullDocLayout.cpp'
RECEIPT = ROOT / 'work/2008-06/shared-layouts/null-doc-working.json'
FAIL = ROOT / 'work/cnulldoc-guided-20261104/null-doc-fail.json'
C = 'CNullDoc'


def flags():
    base = json.loads((ROOT / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
    return [x.replace(OWNER_ROOT, str(ROOT)) for x in base['flags']
            if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]


FLAGS = flags()
# Optional scratch override (investigation only): ROC_NULLDOC_HEADER_DIR is searched before native-headers and
# the receipt goes to the scratch evidence directory, never to shared-layouts.
import os  # noqa: E402
SCRATCH = os.environ.get('ROC_NULLDOC_HEADER_DIR')
if SCRATCH:
    FLAGS = ['/I' + SCRATCH] + FLAGS
    HEADER = Path(SCRATCH) / 'CBrowserDoc.h'
    RECEIPT = ROOT / 'work/cnulldoc-guided-20261104/null-doc-scratch-header.json'
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


def compile_one(source, obj):
    code, log = rebuild.run(tool, 'cl', FLAGS + ['/Fo' + str(obj), str(source)], OUT)
    assert code == 0, log[-3000:]
    return obj


layout_obj = compile_one(LAYOUT, OUT / 'NativeNullDocLayout.obj')   # sizeof / offsetof typedefs: compile = pass
obj = compile_one(SOURCE, OUT / 'CNullDoc.obj')
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
failures = []


def need(condition, message):
    if not condition:
        raise AssertionError(message)


def check(label, fn):
    try:
        return fn()
    except (AssertionError, KeyError) as error:
        failures.append('%s: %s' % (label, error))
    return None


# Aliases share an address with the primary symbol (same bytes in the COFF).
METHODS = [
    ('?GetRuntimeClass@%s@@UBEPAUCRuntimeClass@@XZ' % C, 0x4332e0),
    ('?GetThisClass@%s@@SGPAUCRuntimeClass@@XZ' % C, 0x4332e0),
    ('?OnUpdateDisabledCommand@%s@@IAEXPAVCCmdUI@@@Z' % C, 0x4332f0),
    ('?CreateObject@%s@@SGPAVCObject@@XZ' % C, 0x433310),
    ('?GetMessageMap@%s@@MBEPBUAFX_MSGMAP@@XZ' % C, 0x433360),
    ('?GetThisMessageMap@%s@@KGPBUAFX_MSGMAP@@XZ' % C, 0x433360),
    ('??_G%s@@UAEPAXI@Z' % C, 0x40e4d0),
    ('?IsModified@%s@@UAEHXZ' % C, 0x416690),
    ('?SaveModified@%s@@UAEHXZ' % C, 0x7286a0),
]
BASE_GETTER = ('?_GetBaseClass@%s@@KGPAUCRuntimeClass@@XZ' % C, 0x44f1f0)
METHODS.append(BASE_GETTER)
CRT, MAP, ENTRIES, VTABLE = 0x812410, 0x81242c, 0x812438, 0x80cfcc
CRT_SYM = '?class%s@%s@@2UCRuntimeClass@@B' % (C, C)
MAP_SYM = '?messageMap@?1??GetThisMessageMap@%s@@KGPBUAFX_MSGMAP@@XZ@4U3@B' % C
ENTRIES_SYM = '?_messageEntries@?1??GetThisMessageMap@%s@@KGPBUAFX_MSGMAP@@XZ@4QBUAFX_MSGMAP_ENTRY@@B' % C
INTERNAL = {CRT_SYM: CRT, MAP_SYM: MAP, ENTRIES_SYM: ENTRIES, '??_7%s@@6B@' % C: VTABLE, BASE_GETTER[0]: BASE_GETTER[1]}
OWN = dict(METHODS)

present = {n for n, b, r in match.coff_functions(raw)}
missing = [s for s, a in METHODS if s not in present]
if missing:
    failures.append('emitted symbols missing: %s' % missing)
rows = check('exact bodies', lambda: native_bind.verify(original, obj, [m for m in METHODS if m[0] in present], INTERNAL)) or []

# The class record references this shared import jump thunk: its emitted body is required above too.
base_row = next((row for row in rows if row['symbol'] == BASE_GETTER[0]), None)


def relocs(section):
    table = sections[section]
    return [struct.unpack_from('<IIH', raw, table[5] + 10 * i) for i in range(table[7])]


def resolve(symbol, value, addend):
    """The original address a relocation targets must equal the symbol's proven address."""
    address = value - addend
    hit = original.imported(address)
    if hit is not None:
        need(hit[1] == plain(symbol), (symbol, hex(address), hit))
        return '%s!%s' % hit
    if symbol.startswith('??_C@'):
        pos, at = definitions[symbol]
        literal = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
        need(original.data(address, len(literal)) == literal, (symbol, hex(address)))
        return 'string %r at %s' % (literal[:-1].decode(), hex(address))
    for table in (INTERNAL, OWN):
        if symbol in table:
            need(table[symbol] == address, (symbol, hex(address)))
            return hex(address)
    if symbol in bodies:  # inherited inline COMDAT: its body must be exact at the pointed-to address
        b, r = bodies[symbol]
        t, tr, _ = match.target('2008-06', '%08x' % address)
        need(match.exact_match(t, tr, b, r), (symbol, hex(address)))
        return 'header COMDAT, body exact at %s' % hex(address)
    raise AssertionError((symbol, hex(address)))


def data_symbol(symbol, address, size):
    """Compare the emitted bytes with the original outside relocations and prove every relocation's target."""
    start, section = definitions[symbol]
    code = raw[sections[section][4] + start:sections[section][4] + start + size]
    target = original.data(address, size)
    fixed, notes = set(), {}
    for offset, index, kind in relocs(section):
        if start <= offset < start + size:
            at = offset - start
            fixed.update(range(at, at + 4))
            addend = struct.unpack_from('<i', code, at)[0]
            value = struct.unpack_from('<I', target, at)[0]
            notes['+%#x' % at] = '%s -> %s' % (symbols[index][0], resolve(symbols[index][0], value, addend))
    need(all(code[i] == target[i] for i in range(size) if i not in fixed), (symbol, code.hex(), target.hex()))
    return {'address': '%08x' % address, 'size': size, 'masked_bytes_equal': True, 'relocations': notes}


data = {key: check(key, lambda s=symbol, a=address, n=size: data_symbol(s, a, n))
        for key, symbol, address, size in (('runtime_class', CRT_SYM, CRT, 28), ('message_map', MAP_SYM, MAP, 8),
                                           ('message_entries', ENTRIES_SYM, ENTRIES, 96))}


def check_original_metadata():
    rec = struct.unpack('<IiIIIII', original.data(CRT, 28))
    need(original.string(rec[0]) == C and rec[1:] == (0x54, 0xffff, 0x433310, 0x44f1f0, 0, 0), rec)
    thunk = rec[4]
    for _ in range(4):  # follow jmp rel32 stubs until the mfc90 import thunk
        if original.imported(thunk) is not None or original.data(thunk, 1) != bytes([0xe9]):
            break
        thunk = (thunk + 5 + struct.unpack('<i', original.data(thunk + 1, 4))[0]) & 0xffffffff
    need(original.imported(thunk) == ('mfc90.dll', '?GetThisClass@CDocument@@SGPAUCRuntimeClass@@XZ'),
         ('base getter thunk', hex(thunk), original.imported(thunk)))
    pfn_base, entries = struct.unpack('<II', original.data(MAP, 8))
    need(original.imported(pfn_base) == ('mfc90.dll', '?GetThisMessageMap@CDocument@@KGPBUAFX_MSGMAP@@XZ')
         and entries == ENTRIES, (hex(pfn_base), original.imported(pfn_base), hex(entries)))
    parsed = [struct.unpack('<6I', original.data(ENTRIES + 24 * i, 24)) for i in range(4)]
    need(parsed[:3] == [(0x111, 0xffffffff, i, i, 0x41, 0x4332f0) for i in (0xe103, 0xe104, 0x80b6)]
         and parsed[3] == (0,) * 6, [tuple(map(hex, p)) for p in parsed])
    return 'name CNullDoc, size 0x54, schema 0xffff, create 00433310, base getter 0044f1f0 (CDocument::GetThisClass import thunk); map base CDocument::GetThisMessageMap thunk; 3 CN_UPDATE_COMMAND_UI entries (ID 0xE103, 0xE104, 0x80B6; sig 0x41; handler 004332f0) + zero terminator'


metadata = check('original metadata', check_original_metadata)


# 46-slot vtable: every slot must be an import thunk of the same mfc90 name, an own body, or an inherited inline COMDAT
# exact at the original address.
def prove_slot(symbol, value):
    hit = original.imported(value)
    if hit is not None:
        need(hit[1] == plain(symbol), (symbol, hex(value), hit))
        return '%s!%s' % hit
    if symbol.startswith('??_E') and symbol not in bodies:
        # COFF weak external: the vector deleting destructor defaults to the scalar one (no delete[] in this unit).
        alias = '??_G' + symbol[4:]
        need(OWN[alias] == value, (symbol, hex(value)))
        return 'exact here (weak external of %s)' % alias
    if symbol in OWN:
        need(OWN[symbol] == value, (symbol, hex(value)))
        return 'exact here'
    if symbol in bodies:
        b, r = bodies[symbol]
        t, tr, _ = match.target('2008-06', '%08x' % value)
        need(match.exact_match(t, tr, b, r), (symbol, hex(value), 'original %s vs emitted %s' % (t.hex(), b.hex())))
        return 'inherited inline COMDAT, body exact'
    raise AssertionError((symbol, hex(value)))


def check_vtable():
    name = '??_7%s@@6B@' % C
    start, section = definitions[name]
    count = 46
    slots = {}
    for offset, index, kind in relocs(section):
        if start <= offset < start + count * 4:
            slots[(offset - start) // 4] = symbols[index][0]
    need(len(slots) == count and sections[section][3] - start == count * 4,
         ('emitted slots', len(slots), sections[section][3] - start))
    values = struct.unpack('<%dI' % count, original.data(VTABLE, count * 4))
    rtti_name, off = original.vtable_class(VTABLE)
    need(rtti_name == '.?AV%s@@' % C and off == 0, (rtti_name, off))
    result = {}
    for slot, symbol in sorted(slots.items()):
        try:
            result[slot] = '%08x %s: %s' % (values[slot], symbol, prove_slot(symbol, values[slot]))
        except AssertionError as error:
            result[slot] = '%08x %s: FAIL %s' % (values[slot], symbol, error)
            failures.append('vtable slot %d: %s' % (slot, error))
    return result


vtable = check('vtable', check_vtable)


def check_rtti():
    locator = struct.unpack('<I', original.data(VTABLE - 4, 4))[0]
    sig, offset, cd, td, chd = struct.unpack('<5I', original.data(locator, 20))
    need(locator == 0x87b080 and (sig, offset, cd) == (0, 0, 0), (hex(locator), sig, offset, cd))
    _, attributes, count, array = struct.unpack('<4I', original.data(chd, 16))
    chain = []
    for i in range(count):
        bcd = struct.unpack('<I', original.data(array + 4 * i, 4))[0]
        tdesc, num, mdisp, pdisp, vdisp = struct.unpack('<IIiii', original.data(bcd, 20))
        chain.append((original.string(tdesc + 8), mdisp, pdisp, vdisp))
    need([c[0] for c in chain] == ['.?AV%s@@' % n for n in (C, 'CDocument', 'CCmdTarget', 'CObject')]
         and all(c[1] == 0 for c in chain), chain)
    for symbol in ('??_R4%s@@6B@' % C, '??_R3%s@@8' % C, '??_R1A@?0A@EA@%s@@8' % C):
        need(symbol in definitions, symbol)
    return {'locator': '0x87b080', 'chain': ['%s mdisp=%d pdisp=%d vdisp=%d' % c for c in chain]}


rtti = check('rtti', check_rtti)
status = 'PASS' if not failures else 'FAIL'
sources = {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p)
           for p in (Path(__file__), SOURCE, HEADER, LAYOUT, HERE / 'native_bind.py')}
receipt = {
    'class': C, 'status': status, 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)', 'flags': FLAGS,
    'original': 'clients/2008-06/Roblox.exe', 'original_sha256': sha(CLIENT), 'object_sha256': sha(obj),
    'layout_object_sha256': sha(layout_obj), 'sources': sources,
    'layout': {'sizeof': '0x54 == sizeof(CDocument): CRuntimeClass 00812410 objectSize 0x54, operator new(0x54) in '
                         'CreateObject 00433310 followed by the vptr store only; no body reads or writes an own field',
               'cbrowserdoc_view_offset': '0x54 (CBrowserDoc.h, offsetof assert)',
               'layout_test': 'tests/NativeNullDocLayout.cpp compiled into ' + layout_obj.name},
    'methods': rows, 'get_base_class_00_44f1f0': base_row,
    'vtable_00_80cfcc': vtable, 'runtime_class_00_812410': data.get('runtime_class'),
    'message_map_00_81242c': data.get('message_map'), 'message_entries_00_812438': data.get('message_entries'),
    'original_metadata': metadata, 'rtti': rtti, 'failures': failures,
    'emitted_function_symbols': sorted(n for n in present if 'CNullDoc' in n or 'CDocument' in n),
    'open': {
        'handler_name': 'original name of 004332f0 unknown; OnUpdateDisabledCommand is a neutral codegen analog',
        'command_0x80B6': 'observed resource command ID, symbolic name unknown',
        'folded_destructor_0040e4d0': 'identical scalar deleting destructor also used by the CBrowserDoc vtable; the '
                                      'translation unit that originally emitted it is unproven',
        'scope': 'source/object proof only; no server credit, no selection, no build/runtime claim'}}
(RECEIPT if status == 'PASS' else FAIL).write_text(json.dumps(receipt, indent=2) + '\n')
print('%s native %s: %d exact rows (%d distinct addresses)%s' % (
    status, C, len(rows), len({r['address'] for r in rows}), '' if not failures else '\n  ' + '\n  '.join(failures)))
sys.exit(0 if status == 'PASS' else 1)
