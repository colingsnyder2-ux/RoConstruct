"""Verify the inactive native CBrowserDoc (CNullDoc subclass, one added pointer member): layout test, the exact bodies
with every call/data target, the 46-slot vtable, CRuntimeClass 0080cfac and the RTTI hierarchy. The class has no own
message map: the inherited GetMessageMap slot is proved to be CNullDoc's getter through the canonical CNullDoc receipt.
Writes work/2008-06/shared-layouts/browser-doc-working.json when everything passes; on any failure it writes a FAIL
receipt under work/cbrowserdoc-guided-20261104/ instead and exits non-zero.

Profile: the document-swap flags with this checkout's include roots (document-swap-current.json records the owner PC's
C:\\Users\\colin paths, remapped here); MSVC 15.00.21022 (VS2008 RTM). The original is the registered client
clients/2008-06/Roblox.exe checked against clients.json. Scope: source/object proof only.
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
OUT = ROOT / 'rebuild/2008-06/out/native-layouts/browser-doc'
OUT.mkdir(parents=True, exist_ok=True)
HEADER = ROOT / 'rebuild/2008-06/native-headers/CBrowserDoc.h'
SOURCE = ROOT / 'rebuild/2008-06/native-classes/CBrowserDoc.cpp'
LAYOUT = HERE / 'NativeBrowserDocLayout.cpp'
RECEIPT = ROOT / 'work/2008-06/shared-layouts/browser-doc-working.json'
FAIL = ROOT / 'work/cbrowserdoc-guided-20261104/browser-doc-fail.json'
C = 'CBrowserDoc'


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


def compile_one(source, obj):
    code, log = rebuild.run(tool, 'cl', FLAGS + ['/Fo' + str(obj), str(source)], OUT)
    assert code == 0, log[-3000:]
    return obj


layout_obj = compile_one(LAYOUT, OUT / 'NativeBrowserDocLayout.obj')   # sizeof / offsetof typedefs: compile = pass
obj = compile_one(SOURCE, OUT / 'CBrowserDoc.obj')
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


# Canonical CNullDoc receipt: external CNullDoc symbols resolve through its proven rows, valid only while every
# input hash it recorded is still current (header, CNullDoc.cpp, recorder, layout test, native_bind) and it is PASS.
NULL_RECEIPT_PATH = ROOT / 'work/2008-06/shared-layouts/null-doc-working.json'
NULL_RECEIPT = json.loads(NULL_RECEIPT_PATH.read_text())
stale = [k for k, v in NULL_RECEIPT['sources'].items() if sha(ROOT / k) != v]
assert NULL_RECEIPT['status'] == 'PASS' and not stale, ('canonical CNullDoc proof is stale', stale)
EXT = {r['symbol']: int(r['address'], 16) for r in NULL_RECEIPT['methods']}
EXT_GET_MAP = '?GetMessageMap@CNullDoc@@MBEPBUAFX_MSGMAP@@XZ'
assert EXT[EXT_GET_MAP] == 0x433360 and EXT['?GetThisClass@CNullDoc@@SGPAUCRuntimeClass@@XZ'] == 0x4332e0

# Aliases share an address with the primary symbol (same bytes in the COFF).
METHODS = [
    ('?_GetBaseClass@%s@@KGPAUCRuntimeClass@@XZ' % C, 0x40df90),
    ('?GetRuntimeClass@%s@@UBEPAUCRuntimeClass@@XZ' % C, 0x40dfa0),
    ('?GetThisClass@%s@@SGPAUCRuntimeClass@@XZ' % C, 0x40dfa0),
    ('??_G%s@@UAEPAXI@Z' % C, 0x40e4d0),
    ('?CreateObject@%s@@SGPAVCObject@@XZ' % C, 0x40e4f0),
]
CRT, VTABLE = 0x80cfac, 0x80d2c4
CRT_SYM = '?class%s@%s@@2UCRuntimeClass@@B' % (C, C)
INTERNAL = {CRT_SYM: CRT, '??_7%s@@6B@' % C: VTABLE}
INTERNAL.update(EXT)
OWN = dict(METHODS)

present = {n for n, b, r in match.coff_functions(raw)}
missing = [s for s, a in METHODS if s not in present]
if missing:
    failures.append('emitted symbols missing: %s' % missing)
rows = check('exact bodies', lambda: native_bind.verify(original, obj, [m for m in METHODS if m[0] in present], INTERNAL)) or []

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
    for table in (INTERNAL, OWN, EXT):
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


data = {'runtime_class': check('runtime_class', lambda: data_symbol(CRT_SYM, CRT, 28))}


def check_original_metadata():
    rec = struct.unpack('<IiIIIII', original.data(CRT, 28))
    need(original.string(rec[0]) == C and rec[1:] == (0x58, 0xffff, 0x40e4f0, 0x40df90, 0, 0), rec)
    need(original.data(0x40df90, 5) == bytes([0xe9]) + struct.pack('<i', 0x4332e0 - 0x40df95), 'base getter jmp')
    need(original.data(0x40dfa0, 6) == bytes([0xb8]) + struct.pack('<I', CRT) + b'\xc3', 'GetRuntimeClass')
    return ('name CBrowserDoc, size 0x58, schema 0xffff, create 0040e4f0, base getter 0040df90 (5-byte jmp to '
            'CNullDoc::GetRuntimeClass body 004332e0); no message-map record: class declares none')


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
    if symbol == EXT_GET_MAP:
        need(EXT[symbol] == value, (symbol, hex(value)))
        return 'inherited CNullDoc::GetMessageMap; address proved by canonical null-doc-working.json (no own message map)'
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
    need(locator == 0x87b2e0 and (sig, offset, cd) == (0, 0, 0), (hex(locator), sig, offset, cd))
    _, attributes, count, array = struct.unpack('<4I', original.data(chd, 16))
    chain = []
    for i in range(count):
        bcd = struct.unpack('<I', original.data(array + 4 * i, 4))[0]
        tdesc, num, mdisp, pdisp, vdisp = struct.unpack('<IIiii', original.data(bcd, 20))
        chain.append((original.string(tdesc + 8), mdisp, pdisp, vdisp))
    need([c[0] for c in chain] == ['.?AV%s@@' % n for n in (C, 'CNullDoc', 'CDocument', 'CCmdTarget', 'CObject')]
         and all(c[1] == 0 for c in chain), chain)
    for symbol in ('??_R4%s@@6B@' % C, '??_R3%s@@8' % C, '??_R1A@?0A@EA@%s@@8' % C):
        need(symbol in definitions, symbol)
    return {'locator': '0x87b2e0', 'chain': ['%s mdisp=%d pdisp=%d vdisp=%d' % c for c in chain]}


rtti = check('rtti', check_rtti)
status = 'PASS' if not failures else 'FAIL'
sources = {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p)
           for p in (Path(__file__), SOURCE, HEADER, LAYOUT, HERE / 'native_bind.py')}
receipt = {
    'class': C, 'status': status, 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)', 'flags': FLAGS,
    'original': 'clients/2008-06/Roblox.exe', 'original_sha256': sha(CLIENT), 'object_sha256': sha(obj),
    'layout_object_sha256': sha(layout_obj), 'sources': sources,
    'canonical_null_doc_proof': {'receipt': 'work/2008-06/shared-layouts/null-doc-working.json',
                                 'receipt_sha256': sha(NULL_RECEIPT_PATH), 'input_hashes_current': True},
    'layout': {'sizeof': '0x58 = sizeof(CNullDoc) 0x54 + view pointer: CRuntimeClass 0080cfac objectSize 0x58, '
                         'CreateObject 0040e4f0 operator new(0x58), CDocument ctor, vptr, view=0',
               'view_offset': '0x54 (offsetof assert); written by CBrowserView::OnInitialUpdate 0040ed50 '
                              '(existing browser-view proof), raw non-owning pointer never released by the destructor',
               'layout_test': 'tests/NativeBrowserDocLayout.cpp compiled into ' + layout_obj.name},
    'methods': rows,
    'method_labels': {
        '0040df90': 'new recovery: CBrowserDoc::_GetBaseClass, jmp to reused CNullDoc 004332e0',
        '0040dfa0': 'new recovery: GetRuntimeClass (+ GetThisClass alias at the same address)',
        '0040e4d0': 'REUSED/FOLDED: scalar deleting destructor, also CNullDoc vtable slot 1; not a new gain',
        '0040e4f0': 'new recovery: CreateObject (constructor inlined; no standalone constructor-address claim)'},
    'vtable_00_80d2c4': vtable, 'runtime_class_00_80cfac': data.get('runtime_class'),
    'original_metadata': metadata, 'rtti': rtti, 'failures': failures,
    'emitted_function_symbols': sorted(n for n in present if 'CBrowserDoc' in n or 'CNullDoc' in n),
    'open': {
        'folded_destructor_0040e4d0': 'identical scalar deleting destructor shared with the CNullDoc vtable; the '
                                      'translation unit that originally emitted it is unproven',
        'constructor': 'inline in the .cpp as a codegen analog; the original constructor is inlined into CreateObject',
        'scope': 'source/object proof only; no server credit, no selection, no build/runtime claim'}}
(RECEIPT if status == 'PASS' else FAIL).write_text(json.dumps(receipt, indent=2) + '\n')
print('%s native %s: %d exact rows (%d distinct addresses)%s' % (
    status, C, len(rows), len({r['address'] for r in rows}), '' if not failures else '\n  ' + '\n  '.join(failures)))
sys.exit(0 if status == 'PASS' else 1)
