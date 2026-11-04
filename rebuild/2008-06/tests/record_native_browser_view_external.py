"""Partial proof for the inactive native CBrowserViewExternal (ATL COM class, declaration-only header): layout test
(sizeof / offsetof compile assertions), the one exact body so far (IBrowserViewExternal::get_IsIDE 00410f90) with every
call target, and the original RTTI of vtable 0080d778 (CComObjectNoLock<CBrowserViewExternal>).
The creator 0040fbf0 (authentic ATL9 construction sequence) and the four vtables' emitted ATL bodies are bound slot by slot.
Both declared COM methods and the creator are recovered. Enum bodies and several library/data targets remain open;
the receipt separates masked-exact bodies from verified relocation identities and transitive body proofs.
Writes work/2008-06/shared-layouts/browser-view-external-working.json (status PARTIAL when the getter and layout pass);
on any failure writes a FAIL receipt under work/cbrowserviewexternal-guided-20261104/ and exits non-zero.

Profile: document-swap flags with this checkout's include roots; MSVC 15.00.21022 (VS2008 RTM). Original: the registered
clients/2008-06/Roblox.exe checked against clients.json. Scope: source/object proof only.
"""
import json
import re
import uuid
import struct
import sys
from pathlib import Path

import pefile

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(HERE))
import native_bind  # noqa: E402
from native_bind import rebuild, sha  # noqa: E402
from roc import match  # noqa: E402

OWNER_ROOT = 'C:' + chr(92) + 'Users' + chr(92) + 'colin' + chr(92) + 'RoConstruct'
CLIENT = ROOT / 'clients/2008-06/Roblox.exe'
OUT = ROOT / 'rebuild/2008-06/out/native-layouts/browser-view-external'
OUT.mkdir(parents=True, exist_ok=True)
HEADER = ROOT / 'rebuild/2008-06/native-headers/CBrowserViewExternal.h'
SOURCE = ROOT / 'rebuild/2008-06/native-classes/CBrowserViewExternal.cpp'
LAYOUT = HERE / 'NativeBrowserViewExternalLayout.cpp'
GUIDS = ROOT / 'rebuild/2008-06/native-classes/CBrowserViewExternalGuids.cpp'
HELPER = ROOT / 'rebuild/2008-06/native-classes/WorkspaceSiteError.cpp'
RECEIPT = ROOT / 'work/2008-06/shared-layouts/browser-view-external-working.json'
FAIL = ROOT / 'work/cbrowserviewexternal-guided-20261104/browser-view-external-fail.json'
C = 'CBrowserViewExternal'
VTABLE = 0x80d778


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


failures = []


def check(label, fn):
    try:
        return fn()
    except (AssertionError, KeyError) as error:
        failures.append('%s: %s' % (label, error))
    return None


def need(condition, message):
    if not condition:
        raise AssertionError(message)


# ATL9 atlbase.h: _ATL_APARTMENT_THREADED -> CComObjectThreadModel = CComSingleThreadModel (Globals stay Multi). The original enumerators'
# RTTI (0080d790, 0080d7f0) name CComSingleThreadModel (allocation 0x1c; the default multi model gives 0x38). The original macro spelling is not proven.
THREAD_MODEL = '/D_ATL_APARTMENT_THREADED'
PCXSTR_NEEDLE = 'operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );'
PROFILE_FLAGS = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD']   # the same flags the document-swap profile uses


def compile_profiled(source, obj):
    """GetApp 00410fe0 calls the CString operator PCXSTR through mfc90 import #910: preprocess the unit with the document-swap
    flags, mark exactly that accessor noinline, and compile the result (the tested noinline-PCXSTR profile; header unchanged)."""
    code, log = rebuild.run(tool, 'cl', [x for x in FLAGS if x != '/c'] + [THREAD_MODEL, '/P', str(source)], OUT)
    assert code == 0, log[-3000:]
    text = (OUT / 'CBrowserViewExternal.i').read_text(errors='replace')
    assert text.count(PCXSTR_NEEDLE) == 1, 'PCXSTR accessor needle count %d' % text.count(PCXSTR_NEEDLE)
    profile = OUT / 'CBrowserViewExternalProfile.cpp'
    profile.write_text(text.replace(PCXSTR_NEEDLE, '__declspec(noinline) ' + PCXSTR_NEEDLE))
    code, log = rebuild.run(tool, 'cl', PROFILE_FLAGS + ['/Fo' + str(obj), str(profile)], OUT)
    assert code == 0, log[-3000:]
    return obj


layout_obj = compile_one(LAYOUT, OUT / 'NativeBrowserViewExternalLayout.obj')   # compile = every assertion passes
guid_obj = compile_one(GUIDS, OUT / 'CBrowserViewExternalGuids.obj')
helper_obj = compile_one(HELPER, OUT / 'WorkspaceSiteError.obj')
obj = compile_profiled(SOURCE, OUT / 'CBrowserViewExternal.obj')
raw = obj.read_bytes()
KNOWN_OPEN = ()   # no tolerated open row: both Enum bodies are exact with the single-thread enumerator model, any row failure is a failure
CREATOR = '?createBrowserViewExternal@@YAJPAPAV?$CComObjectNoLock@VCBrowserViewExternal@@@ATL@@H@Z'
GETTER = '?get_IsIDE@%s@@UAGJPAF@Z' % C
NOLOCK = '??_7?$CComObjectNoLock@VCBrowserViewExternal@@@ATL@@6B'
# the four original tables of CComObjectNoLock<CBrowserViewExternal> (primary + three secondary vtables), with the
# subobject offset the original complete-object locator records for each
VTABLES = [(NOLOCK + '?$ISupportErrorInfoImpl@$1?IID_IBrowserViewExternal@@3U_GUID@@B@1@@', 0x80d778, 0x00),
           (NOLOCK + '?$IConnectionPointContainerImpl@VCBrowserViewExternal@@@1@@', 0x80d760, 0x04),
           (NOLOCK + '?$CProxy_IBrowserViewExternalEvents@VCBrowserViewExternal@@@@@', 0x80d73c, 0x08),
           (NOLOCK + '?$IDispatchImpl@UIBrowserViewExternal@@$1?IID_IBrowserViewExternal@@3U_GUID@@B$1?LIBID_RobloxLib@@3U3@B$00$0A@VCComTypeInfoHolder@ATL@@@1@@', 0x80d714, 0x14)]
# ctor-time table of the CProxy base (the creator stores it at +8 before the final tables); verified by RTTI below
CTOR_PROXY_VTABLE = '??_7?$CProxy_IBrowserViewExternalEvents@VCBrowserViewExternal@@@@6B@'
CTOR_PROXY_ADDRESS = 0x80d388
present = {n for n, b, r in match.coff_functions(raw)}
sections, symbols, definitions, _ = match._coff_data_index(raw)


def vtable_slots(symbol):
    """(slot count, {slot: relocated symbol}) read from the emitted COFF vtable, not guessed from neighbours."""
    start, section = definitions[symbol]
    table = sections[section]
    ends = sorted(o for n, (o, s) in definitions.items() if s == section and o > start)
    end = ends[0] if ends else table[3]
    slots = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if start <= offset < end:
            slots[(offset - start) // 4] = symbols[index][0]
    assert len(slots) == (end - start) // 4, symbol
    return (end - start) // 4, slots


def alias(symbol):
    """The vtable names the vector deleting destructor (??_E, a weak external); the body is the emitted ??_G."""
    return '??_G' + symbol[4:] if symbol.startswith('??_E') else symbol


slot_table, emitted_slots, internal = {}, {}, {}
for symbol, address, subobject in VTABLES:
    count, slots = vtable_slots(symbol)
    internal[symbol] = address
    emitted_slots[address] = (count, slots)
    for slot in range(count):
        word = struct.unpack('<I', original.data(address + 4 * slot, 4))[0]
        slot_table[(address, slot)] = (word, alias(slots[slot]), slots[slot])
internal[CTOR_PROXY_VTABLE] = CTOR_PROXY_ADDRESS
# a symbol may be a slot of two tables only if both tables hold the same original address; unique (symbol, address) rows
exact_pairs, open_slots = {}, []
for (address, slot), (word, body, raw_symbol) in sorted(slot_table.items()):
    if body in present:
        exact_pairs.setdefault(body, word)
        assert exact_pairs[body] == word, (body, hex(word), hex(exact_pairs[body]))
    else:
        open_slots.append({'vtable': '%08x' % address, 'slot': slot, 'original': '%08x' % word, 'emitted_symbol': raw_symbol})
GETAPP = '?GetApp@%s@@UAGJPAPAUIDispatch@@@Z' % C
METHODS = [(GETTER, 0x410f90), (CREATOR, 0x40fbf0), (GETAPP, 0x410fe0)] + sorted((s, a) for s, a in exact_pairs.items() if s not in (GETTER, GETAPP))
missing = [s for s, a in METHODS if s not in present]
if missing:
    failures.append('emitted symbols missing: %s' % missing)
# Data the bound bodies read, each checked against the original bytes before it may bind a relocation.
def guid_at(address):
    return original.data(address, 16)


def named_guid(name):
    m = re.search(r'GUID_([0-9a-f]{8})_([0-9a-f]{4})_([0-9a-f]{4})_([0-9a-f]{4})_([0-9a-f]{12})', name)
    return uuid.UUID('-'.join(m.groups())).bytes_le


IID_IBVE = 0x8164d8                     # _IID_IBrowserViewExternal (no definition in the native sources: link blocker)
GUID_SYMBOLS = {'__GUID_dd754d30_321a_45a2_a40c_75783afabfab': 0x80d3a8,
                '__GUID_b196b284_bab4_101a_b69c_00aa00341d07': 0x80d3b8,
                '__GUID_b196b286_bab4_101a_b69c_00aa00341d07': 0x80d3f0,
                '__GUID_b196b285_bab4_101a_b69c_00aa00341d07': 0x80d7c8, '__GUID_b196b287_bab4_101a_b69c_00aa00341d07': 0x80d3e0}
COM_MAP, TIH, CONN_ENTRIES, CONN_GUARD = 0x80d64c, 0x92b744, 0x96cbc8, 0x96cbd0
INTERFACE_IIDS = {'IDispatch': uuid.UUID('00020400-0000-0000-c000-000000000046').bytes_le,
                  'ISupportErrorInfo': uuid.UUID('df0b3d60-548f-101b-8e65-08002b2bd119').bytes_le,
                  'IConnectionPointContainer': uuid.UUID('b196b284-bab4-101a-b69c-00aa00341d07').bytes_le}
data_facts = {}


def check_data():
    for name, address in GUID_SYMBOLS.items():
        need(guid_at(address) == named_guid(name), (name, hex(address)))
        data_facts[name] = '%08x: 16 bytes equal the GUID in the symbol name' % address
    need(guid_at(IID_IBVE) == uuid.UUID('e2ece10d-9997-414b-b40b-0928b8f3cadb').bytes_le, 'IID_IBrowserViewExternal bytes')
    data_facts['_IID_IBrowserViewExternal'] = '%08x: e2ece10d-9997-414b-b40b-0928b8f3cadb (equals the header __declspec(uuid))' % IID_IBVE
    entries = [struct.unpack('<3I', original.data(COM_MAP + 12 * i, 12)) for i in range(5)]
    expect = [(IID_IBVE, 0x14), (None, 0x14, 'IDispatch'), (None, 0, 'ISupportErrorInfo'), (None, 4, 'IConnectionPointContainer')]
    need(entries[0][1:] == (0x14, 1) and guid_at(entries[0][0]) == guid_at(IID_IBVE), entries[0])   # __uuidof copy, same bytes
    for entry, (_, offset, name) in zip(entries[1:4], expect[1:]):
        need(entry[1] == offset and entry[2] == 1 and guid_at(entry[0]) == INTERFACE_IIDS[name], (name, entry))
    need(entries[4] == (0, 0, 0), entries[4])
    data_facts['_entries(COM map)'] = '%08x: IBrowserViewExternal+0x14, IDispatch+0x14, ISupportErrorInfo+0, IConnectionPointContainer+4, all simple entries, terminator' % COM_MAP
    enum_map = [struct.unpack('<3I', original.data(0x80d3c8 + 12 * i, 12)) for i in range(2)]
    need(enum_map[0] == (0x80d3e0, 0, 1) and enum_map[1] == (0, 0, 0) and guid_at(0x80d3e0) == named_guid('GUID_b196b287_bab4_101a_b69c_00aa00341d07'), enum_map)
    data_facts['CComEnum<IEnumConnections>::_entries'] = '0080d3c8: {&IID_IEnumConnections 0080d3e0 (bytes verified), offset 0, simple entry}, terminator'
    enum_map1 = [struct.unpack('<3I', original.data(0x80d7b0 + 12 * i, 12)) for i in range(2)]
    need(enum_map1[0] == (0x80d7c8, 0, 1) and enum_map1[1] == (0, 0, 0) and guid_at(0x80d7c8) == named_guid('GUID_b196b285_bab4_101a_b69c_00aa00341d07'), enum_map1)
    data_facts['CComEnum<IEnumConnectionPoints>::_entries'] = '0080d7b0: {&IID_IEnumConnectionPoints 0080d7c8 (bytes verified), offset 0, simple entry}, terminator'
    tih = struct.unpack('<2I2H', original.data(TIH, 12))
    need(tih[0] == IID_IBVE and tih[2:] == (1, 0), tih)
    data_facts['_tih'] = '%08x: CComTypeInfoHolder{pguid=IID_IBrowserViewExternal, plibid=%08x, 1.0}' % (TIH, tih[1])
    data = [x for x in original.pe.sections if x.Name.startswith(b'.data')][0]
    start = original.image + data.VirtualAddress
    need(CONN_ENTRIES >= start + data.SizeOfRawData and CONN_GUARD == CONN_ENTRIES + 8, 'connection map statics not zero-initialised bss')
    need(start <= 0x96c268 < 0x96c26c + 16 <= start + data.Misc_VirtualSize, 'ATL module statics outside .data')
    data_facts['GetConnMap statics'] = '%08x entries (2 dwords) + %08x init guard: both in the zero-initialised tail of .data' % (CONN_ENTRIES, CONN_GUARD)


check('data facts', check_data)
internal.update(GUID_SYMBOLS)
ENUM_ENTRIES = {'b196b285': (0x80d7b0, 0x80d7c8), 'b196b287': (0x80d3c8, 0x80d3e0)}   # CComEnum<..>::_entries -> (map, its IID)
for name, address in ((next(n for n in definitions if n.startswith('?_entries@?1??_GetEntries@?$CComEnum@UIEnumConnections@')), 0x80d3c8),
                      (next(n for n in definitions if n.startswith('?_entries@?1??_GetEntries@?$CComEnum@UIEnumConnectionPoints@')), 0x80d7b0), ('_IID_IBrowserViewExternal', IID_IBVE),
                      ('?_entries@?1??_GetEntries@CBrowserViewExternal@@SGPBU_ATL_INTMAP_ENTRY@ATL@@XZ@4QBU34@B', COM_MAP),
                      ('?_entries@?1??GetConnMap@CBrowserViewExternal@@SAPBU_ATL_CONNMAP_ENTRY@ATL@@PAH@Z@4QBU34@B', CONN_ENTRIES),
                      ('??_B?1??GetConnMap@CBrowserViewExternal@@SAPBU_ATL_CONNMAP_ENTRY@ATL@@PAH@Z@51', CONN_GUARD)):
    internal[name] = address
for _, (name, *_rest) in ((i, v) for i, v in symbols.items() if v[0].startswith('?_tih@?$IDispatchImpl@UIBrowserViewExternal@')):
    internal[name] = TIH
# Support bodies this object also emits (not vtable slots): bound by exact bytes where they match.
SUPPORT = [('??1?$IConnectionPointImpl@VCBrowserViewExternal@', 0x40e990), ('?Add@CComDynamicUnkArray@ATL@@QAEKPAUIUnknown@@@Z', 0x40ea90),
           ('?GetTI@CComTypeInfoHolder@ATL@@QAEJK@Z', 0x404a80), ('??$AtlMultiply@H@ATL@@YAJPAHHH@Z', 0x401710), ('?Allocate@?$CAtlSafeAllocBufferManager@VCCRTAllocator@ATL@@@_ATL_SAFE_ALLOCA_IMPL@ATL@@QAEPAXK@Z', 0x402f50), ('?GetIDsOfNames@CComTypeInfoHolder@ATL@@QAEJABU_GUID@@PAPA_WIKPAJ@Z', 0x405190),
           ('?GetCookie@CComDynamicUnkArray@ATL@@QAGKPAPAUIUnknown@@@Z', 0x40ed10), ('??1?$CAtlSafeAllocBufferManager@VCCRTAllocator@ATL@@@_ATL_SAFE_ALLOCA_IMPL@ATL@@QAE@XZ', 0x401150),
           ('?Init@?$CComEnumImpl@UIEnumConnectionPoints@@', 0x40f570), ('?Init@?$CComEnumImpl@UIEnumConnections@@', 0x40ef00),
           ('?AtlThrowImpl@ATL@@YGXJ@Z', 0x401000)]
for prefix, address in SUPPORT:
    hits = [n for n in present if n.startswith(prefix)]
    if len(hits) == 1:
        METHODS.append((hits[0], address))

# The two CComObject<CComEnum<..., CComSingleThreadModel>> tables created by EnumConnectionPoints / EnumConnections.
# Slot count and slot symbols come from the emitted COFF vtable; the original words are read at the bound address.
# A slot whose original address is already a row is an ALIAS (folded body), not a new address.
ENUM_TABLES = [('b196b285', 0x80d790, 'IEnumConnectionPoints'), ('b196b287', 0x80d7f0, 'IEnumConnections')]
ENUM_SUPPORT = [('?CreateInstance@?$CComObject@V?$CComEnum@', 'b196b285', 0x40fe50), ('?CreateInstance@?$CComObject@V?$CComEnum@', 'b196b287', 0x40ff20),
                ('??1?$CComEnumImpl@', 'b196b285', 0x40f440), ('??1?$CComEnumImpl@', 'b196b287', 0x40ec90)]
enum_vtable_symbol, enum_slot_words, enum_new_rows, enum_alias_pairs, enum_support_pairs = {}, {}, [], [], []
baseline_addresses = {a for s, a in METHODS}
for tag, address, _name in ENUM_TABLES:
    symbols_for_tag = [n for n in definitions if n.startswith('??_7?$CComObject@V?$CComEnum@') and tag in n and n.endswith('@@6B@')]
    if len(symbols_for_tag) != 1:
        failures.append('enum vtable %s: %d COFF definitions' % (tag, len(symbols_for_tag)))
        continue
    enum_vtable_symbol[address] = symbols_for_tag[0]
    count, slots = vtable_slots(symbols_for_tag[0])
    enum_slot_words[address] = (count, slots)
    for slot in range(count):
        word = struct.unpack('<I', original.data(address + 4 * slot, 4))[0]
        body = alias(slots[slot])
        if body not in present:
            failures.append('enum slot %08x[%d] %s: emitted body missing' % (address, slot, body[:60]))
        elif word in baseline_addresses:
            enum_alias_pairs.append((body, word))
        else:
            METHODS.append((body, word))
            baseline_addresses.add(word)
            enum_new_rows.append((body, word))
for prefix, tag, address in ENUM_SUPPORT:
    hits = [n for n in present if n.startswith(prefix) and tag in n]
    if len(hits) == 1:
        METHODS.append((hits[0], address))
        enum_support_pairs.append((hits[0], address))
    else:
        failures.append('enum support %08x: %d emitted symbols' % (address, len(hits)))
# Reuse the authentic vendor replay, explicitly selecting RTM even though the stored mining winner uses SP1.
# Both functions are in this object; verify the only call relocation against the separately exact helper body.
LIBRARY_METHODS = [
    ('?AtlInternalQueryInterface@ATL@@YGJPAXPBU_ATL_INTMAP_ENTRY@1@ABU_GUID@@PAPAX@Z', 0x402280),
    ('?InlineIsEqualUnknown@ATL@@YGHABU_GUID@@@Z', 0x401b60),
]


def prove_library_query_interface():
    import hashlib
    from roc import libs, setup

    build = 21022
    unit_path = 'atlmfc/src/mfc/wincore.cpp'
    specification = libs.source_for('mfc-9.0', unit_path, build=build, flags='/O2 /GS- /MD')
    expanded = libs.unit('mfc-9.0', unit_path, build)
    library_raw = match.compile_text('2008-06', specification, build=build)
    library_obj = OUT / 'MfcWincore21022.obj'
    library_obj.write_bytes(library_raw)
    _, library_symbols, _, _ = match._coff_data_index(library_raw)
    compiler_ids = [value for name, value, _section, _kind in library_symbols.values() if name == '@comp.id']
    need(len(compiler_ids) == 1 and compiler_ids[0] & 0xffff == build, ('COFF compiler identity', compiler_ids))
    library_rows = native_bind.verify(original, library_obj, LIBRARY_METHODS, {})
    data_checks = {}
    for symbol, address in LIBRARY_METHODS:
        score, selected, _diff, spans = match.check_text('2008-06', '%08x' % address, specification, obj=library_raw)
        need(score == 100 and selected == symbol, (symbol, score, selected))
        data_checks['%08x' % address] = {'exact_symbol_and_defined_data': True, 'referenced_data_spans': spans}
    inputs = [ROOT / 'tools/libs/mfc-9.0' / unit_path,
              ROOT / 'tools/libs/mfc-9.0/atlmfc/include/atlbase.h']
    return {'status': 'PASS', 'kind': 'authentic vendor library replay, not a new application provider',
            'recipe': 'mfc-9.0', 'unit': unit_path, 'specification': specification,
            'compiler_build': build, 'compiler_path': str(setup.compilers()[build]),
            'compiler_sha256': sha(setup.compilers()[build]), 'coff_compiler_id': compiler_ids[0],
            'compiler_flags': ['/nologo', '/c', '/Gy', '/O2', '/GS-', '/MD'],
            'expanded_cpp_sha256': hashlib.sha256(expanded.encode()).hexdigest(),
            'input_hashes': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in inputs},
            'object_sha256': sha(library_obj), 'rows': library_rows, 'data_checks': data_checks}


library_query_interface = check('authentic ATL query-interface library proof', prove_library_query_interface)
if library_query_interface:
    internal.update(dict(LIBRARY_METHODS))
ASSERTED = {} if library_query_interface else {LIBRARY_METHODS[0][0]: LIBRARY_METHODS[0][1]}
ASSERTED['?_pAtlModule@ATL@@3PAVCAtlModule@1@A'] = 0x96c268   # ATL global module pointer: bss address only, name from the relocation
ASSERTED['?m_libid@CAtlModule@ATL@@2U_GUID@@A'] = 0x96c26c   # ATL static GUID: .data address only
ASSERTED['?_AtlBaseModule@ATL@@3VCAtlBaseModule@1@A'] = 0x97f2a8   # ATL global base module: data address only
ASSERTED['?_AtlVerifyStackAvailable@_ATL_SAFE_ALLOCA_IMPL@ATL@@YA_NK@Z'] = 0x402610   # emitted body is NOT exact (156 vs 93): recorded below
ASSERTED['__alloca_probe'] = 0x6a1520   # CRT helper: relocation operand only
ASSERTED['__alloca_probe_16'] = 0x6a1560   # CRT helper: relocation operand only


def observed_targets(symbol, address):
    """{relocated symbol: original operand value} read the same way native_bind.verify reads them."""
    body = dict((n, b) for n, b, r in match.coff_functions(raw))[symbol]
    target = match.target('2008-06', '%08x' % address)[0]
    start, section = definitions[symbol]
    table = sections[section]
    code = raw[table[4] + start:]
    found = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        offset -= start
        name = symbols[index][0]
        if not 0 <= offset < len(body) or native_bind.LOCAL_EH.match(name):
            continue
        if kind == 20:
            found[name] = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        else:
            found[name] = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
    return found


# ATL support bodies whose helper callees (alloca, string conversion, throw) this probe does not recover: the bytes of these
# rows are exact, their library-call operands are recorded as unproven instead of being bound.
LOOSE = ('?GetTI@CComTypeInfoHolder@ATL@@QAEJK@Z', '?Allocate@?$CAtlSafeAllocBufferManager@')
for symbol, address in list(METHODS):
    if symbol.startswith(LOOSE) and symbol in present:
        for name, value in observed_targets(symbol, address).items():
            if name not in internal and name not in dict(METHODS) and not name.startswith(('??_C@', '??_R0', '__imp_', '??2', '??3')):
                ASSERTED[name] = value
internal.update(ASSERTED)

# Typed GUID definitions (CBrowserViewExternalGuids.cpp): every emitted symbol's 16 bytes against the registered original's data.
GUID_DEFS = {'_IID_IBrowserViewExternal': 0x8164d8, '_LIBID_RobloxLib': 0x8164e8, '_CLSID_BrowserViewExternal': 0x816548}
guid_raw = guid_obj.read_bytes()
guid_sections, guid_symbols, guid_definitions, _ = match._coff_data_index(guid_raw)
guid_facts = {}


def check_guid_definitions():
    for name, address in GUID_DEFS.items():
        start, section = guid_definitions[name]
        emitted = guid_raw[guid_sections[section][4] + start:][:16]
        need(emitted == original.data(address, 16), (name, hex(address)))
        guid_facts[name] = {'original_address': '%08x' % address, 'bytes': str(uuid.UUID(bytes_le=emitted)), 'section': guid_sections[section][0] if isinstance(guid_sections[section][0], str) else None,
                            'result': 'emitted 16 bytes equal the original data'}
    need(not [n for (n, v, sec, typ) in guid_symbols.values() if sec == 0], 'GUID unit has undefined symbols')


check('typed GUID definitions', check_guid_definitions)
internal.update(GUID_DEFS)
# GetApp's two CoCreateInstance GUIDs are static analog-named constants of the class unit: the emitted bytes against the original data
for stem, address in (('applicationClassGuid', 0x816508), ('applicationInterfaceGuid', 0x80b468)):
    hits = [(n, definitions[n]) for n in definitions if stem in n]
    if len(hits) == 1:
        name, (start, section) = hits[0]
        check('GetApp GUID ' + stem, lambda: need(raw[sections[section][4] + start:][:16] == original.data(address, 16), stem))
        internal[name] = address
        guid_facts[name] = {'original_address': '%08x' % address, 'bytes': str(uuid.UUID(bytes_le=original.data(address, 16))), 'result': 'emitted 16 bytes equal the original data (CoCreateInstance-only value, static in the class unit)'}
    else:
        failures.append('GUID symbol %s: %d hits' % (stem, len(hits)))

# Helper 00429330 (WorkspaceSiteError.cpp compiled once separately): exact body, then its callees as relocation operands only.
HELPER_SYMBOL = '?reportWorkspaceSiteError@@YAJABU_GUID@@PBDJ@Z'
helper_internal = {'?reportWorkspaceStatus@@YAXGPBD@Z': 0x427c20, '?AtlReportError@ATL@@YGJABU_GUID@@PBDK10J@Z': 0x4290b0, '_GUID_NULL': 0x8501ec}
helper_rows = []
try:
    helper_rows = native_bind.verify(original, helper_obj, [(HELPER_SYMBOL, 0x429330)], helper_internal)
    for row in helper_rows:
        row['unproven_targets'] = {k: row['verified_targets'].pop(k) for k in list(row['verified_targets']) if k in helper_internal}
        row['unproven_note'] = 'callee bodies (workspace status reporter 00427c20, ATL AtlReportError 004290b0) and GUID_NULL are relocation operands only here'
    internal[HELPER_SYMBOL] = 0x429330
except (AssertionError, KeyError) as error:
    failures.append('helper 00429330: %s' % str(error)[:300])
rows, row_failures = [], []
for method in [m for m in METHODS if m[0] in present]:
    try:
        rows += native_bind.verify(original, obj, [method], internal, own={s: a for s, a in METHODS})
    except AssertionError as error:
        row_failures.append({'symbol': method[0], 'address': '%08x' % method[1], 'reason': str(error)[:300]})
        if not method[0].startswith(KNOWN_OPEN):
            failures.append('%s %08x: %s' % (method[0][:60], method[1], str(error)[:200]))


alias_rows = []
for symbol, address in enum_alias_pairs:
    try:
        alias_rows += native_bind.verify(original, obj, [(symbol, address)], internal, own={s: a for s, a in METHODS})
    except AssertionError as error:
        failures.append('enum alias %s %08x: %s' % (symbol[:60], address, str(error)[:200]))
for row in rows + alias_rows:
    for symbol in list(row['verified_targets']):
        if symbol in ASSERTED and str(row['verified_targets'][symbol]).startswith('0x'):
            row.setdefault('unproven_targets', {})[symbol] = row['verified_targets'].pop(symbol)
            row['unproven_note'] = 'address is the relocation operand; the ATL library function body is not proven by this probe'


def first_difference(symbol, address):
    body, refs = dict((n, (b, r)) for n, b, r in match.coff_functions(raw))[symbol]
    target = match.target('2008-06', '%08x' % address)[0]
    at = next((i for i in range(min(len(body), len(target))) if body[i] != target[i]), None)
    return {'address': '%08x' % address, 'emitted_size': len(body), 'original_size': len(target), 'first_byte_difference_offset': at}


for row in row_failures:
    if row['symbol'].startswith(KNOWN_OPEN):
        row.update(first_difference(row['symbol'], int(row['address'], 16)))
        row['reason'] = 'size/bytes differ: not exact, not claimed'


verify_stack = first_difference('?_AtlVerifyStackAvailable@_ATL_SAFE_ALLOCA_IMPL@ATL@@YA_NK@Z', 0x402610) if '?_AtlVerifyStackAvailable@_ATL_SAFE_ALLOCA_IMPL@ATL@@YA_NK@Z' in present else None


def locator_chain(vtable):
    locator = struct.unpack('<I', original.data(vtable - 4, 4))[0]
    sig, offset, cd, td, chd = struct.unpack('<5I', original.data(locator, 20))
    _, attributes, count, array = struct.unpack('<4I', original.data(chd, 16))
    chain = []
    for i in range(count):
        bcd = struct.unpack('<I', original.data(array + 4 * i, 4))[0]
        tdesc, num, mdisp, pdisp, vdisp = struct.unpack('<IIiii', original.data(bcd, 20))
        chain.append((original.string(tdesc + 8), mdisp, pdisp, vdisp))
    return hex(locator), ['%s mdisp=%d pdisp=%d vdisp=%d' % c for c in chain]


def check_rtti():
    result = {}
    for symbol, address, subobject in VTABLES:
        rtti_name, off = original.vtable_class(address)
        need(rtti_name == '.?AV?$CComObjectNoLock@VCBrowserViewExternal@@@ATL@@' and off == subobject, (hex(address), rtti_name, off))
        locator, chain = locator_chain(address)
        result['%08x' % address] = {'rtti': rtti_name, 'subobject_offset': subobject, 'locator': locator, 'chain': chain}
    proxy, off = original.vtable_class(CTOR_PROXY_ADDRESS)
    need(proxy == '.?AV?$CProxy_IBrowserViewExternalEvents@VCBrowserViewExternal@@@@', proxy)
    result['%08x' % CTOR_PROXY_ADDRESS] = {'rtti': proxy, 'role': 'ctor-time vtable stored at +8 by the creator'}
    return result


def table_words():
    """Original words of each table against the COFF slot count and the emitted symbol of every slot."""
    result = {}
    for symbol, address, subobject in VTABLES:
        count, slots = emitted_slots[address]
        following = struct.unpack('<I', original.data(address + 4 * count, 4))[0]   # locator word of the next table
        result['%08x' % address] = {
            'slots': count, 'coff_vtable_symbol': symbol,
            'words': [{'slot': k, 'original': '%08x' % slot_table[(address, k)][0], 'emitted_symbol': slots[k]} for k in range(count)],
            'word_after_table': '%08x' % following}
    return result


def reference_counts():
    """Dwords in the non-executable image equal to each exact address: [inside our four tables, elsewhere]."""
    ours = {a + 4 * k for _, a, _ in VTABLES for k in range(emitted_slots[a][0])}
    counts = {}
    wanted = {w for (a, k), (w, b, r) in slot_table.items() if b in present}
    for section in original.pe.sections:
        if section.Characteristics & 0x20000000:
            continue
        blob = section.get_data()
        base = original.image + section.VirtualAddress
        for k in range(0, len(blob) - 3, 4):
            value = struct.unpack_from('<I', blob, k)[0]
            if value in wanted:
                counts.setdefault(value, [0, 0])[0 if base + k in ours else 1] += 1
    return counts


def creator_alloc():
    code = original.data(0x40fbf0, 174)
    at = code.find(b'\x6a\x20')
    call = at + 11   # 0040fc18 push 0x20; 0040fc23 call operator new
    need(at >= 0 and code[call] == 0xe8, 'operator new call not at push+11')
    target = (0x40fbf0 + call + 5 + struct.unpack_from('<i', code, call + 1)[0]) & 0xffffffff
    hit = original.imported(target)
    need(hit is not None and hit[1] == '??2@YAPAXI@Z', hex(target))
    return 'creator 0040fbf0: push 0x20 at +%#x then call %08x = %s!%s (operator new)' % ((at, target) + hit)


def creator_lifetime():
    """The +0x18 reference-count window and the 0x1c VARIANT_BOOL store, read from the original bytes (the exact row proves them)."""
    code = original.data(0x40fbf0, 174)
    inc, dec = code.find(b'\xff\x40\x18'), code.find(b'\xff\x48\x18')
    need(inc > 0 and dec > inc, 'no inc/dec of [obj+0x18] around the construct calls')
    need(code.find(b'\x66\x89\x48\x1c') > 0, 'no 16-bit store at [obj+0x1c]')
    return {'AddRef_root_refcount': 'inc dword [eax+0x18] at +%#x (InternalFinalConstructAddRef via DECLARE_PROTECT_FINAL_CONSTRUCT)' % inc,
            'Release_root_refcount': 'dec dword [eax+0x18] at +%#x (InternalFinalConstructRelease)' % dec,
            'isIDE': 'mov word [eax+0x1c], cx (cleared to VARIANT_FALSE in the constructor)',
            'result_store': 'the only store of *result is the final output (no early clear, no null check)'}


def check_enum_tables():
    """RTTI, slot count and emitted-vs-original COM map of the two enumerator tables (read from the existing object)."""
    text = original.pe.sections[0]
    code_lo = original.image + text.VirtualAddress
    code_hi = code_lo + text.Misc_VirtualSize
    result = {}
    for tag, address, name in ENUM_TABLES:
        symbol = enum_vtable_symbol[address]
        count, slots = enum_slot_words[address]
        rtti_name, off = original.vtable_class(address)
        need(rtti_name == '.?AV' + symbol[4:symbol.index('@@6B') + 2] and off == 0, (hex(address), rtti_name, off))
        need('VCComSingleThreadModel@' in rtti_name, rtti_name)
        locator, chain = locator_chain(address)
        words = [struct.unpack('<I', original.data(address + 4 * k, 4))[0] for k in range(count)]
        need(all(code_lo <= w < code_hi for w in words), 'a slot word is outside .text')
        after = struct.unpack('<I', original.data(address + 4 * count, 4))[0]
        need(not code_lo <= after < code_hi, 'word after the table is code: slot count not closed')
        map_address, iid_address = ENUM_ENTRIES[tag]
        after_is_map = map_address == address + 4 * count
        need(iid_address == map_address + 24, 'COM map IID is not the record 24 bytes in')
        entry_symbol = next(n for n in definitions if n.startswith('?_entries@?1??_GetEntries@?$CComEnum@') and tag in n)
        start, section = definitions[entry_symbol]
        table = sections[section]
        emitted = raw[table[4] + start:table[4] + start + 24]
        relocations = [(o, symbols[i][0]) for o, i, k in (struct.unpack_from('<IIH', raw, table[5] + 10 * j) for j in range(table[7])) if start <= o < start + 24]
        need(len(relocations) == 1 and relocations[0][0] == start and tag in relocations[0][1], relocations)
        need(struct.unpack('<6I', emitted) == (0, 0, 1, 0, 0, 0), emitted.hex())   # piid (relocated), dw=0, simple entry, terminator
        original_map = struct.unpack('<6I', original.data(map_address, 24))
        need(original_map == (iid_address, 0, 1, 0, 0, 0) and guid_at(iid_address) == named_guid(relocations[0][1]), original_map)
        result['%08x' % address] = {
            'interface': name, 'coff_vtable_symbol': symbol, 'rtti': rtti_name, 'subobject_offset': off, 'locator': locator, 'chain': chain,
            'slots': count, 'slot_words_all_in_text': True, 'word_after_table': '%08x' % after, 'word_after_table_is_com_map': after_is_map,
            'com_map': {'address': '%08x' % map_address, 'emitted_symbol': entry_symbol, 'iid_symbol': relocations[0][1], 'iid_address': '%08x' % iid_address,
                        'result': 'emitted {piid(relocated), 0, simple} + terminator equal the original records; IID bytes equal the GUID in the symbol name'},
            'slot_list': [{'slot': k, 'original': '%08x' % words[k], 'emitted_symbol': slots[k]} for k in range(count)]}
    return result


rtti = check('rtti', check_rtti)
enum_tables = check('enumerator tables', check_enum_tables)
words = check('table words', table_words)
references = check('table references', reference_counts) or {}
alloc = check('creator allocation', creator_alloc)
lifetime = check('creator lifetime', creator_lifetime)
undefined_all = sorted(n for (n, value, secnum, typ) in symbols.values() if secnum == 0)
passed = not failures
sources = {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p)
           for p in (Path(__file__), SOURCE, GUIDS, HELPER, HEADER, LAYOUT, HERE / 'native_bind.py',
                     ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/include/atlexcept.h')}
reuse = {}
slot_addresses = {w for (a, k), (w, b, r) in slot_table.items()}
for symbol, address in METHODS:
    elsewhere = references.get(address, [0, 0])[1]
    if address in (0x410f90, 0x40fbf0, 0x410fe0):
        reuse['%08x' % address] = 'newly recovered for this class'
    elif address not in slot_addresses:
        reuse['%08x' % address] = 'support body called by the bound bodies (not a vtable slot)'
    elif elsewhere:
        reuse['%08x' % address] = 'vtable slot also shared by %d dword(s) outside these four tables (folded/shared body)' % elsewhere
    else:
        reuse['%08x' % address] = 'vtable slot used only by these four tables'
for symbol, address in enum_new_rows:
    reuse['%08x' % address] = 'new: enumerator template slot (CComObject<CComEnum> table %s)' % ('0080d790' if 'b196b285' in symbol else '0080d7f0')
for symbol, address in enum_support_pairs:
    reuse['%08x' % address] = 'new: enumerator template support body (called by the enumerator slots; not a vtable slot)'
receipt = {
    'class': C, 'status': 'PARTIAL' if passed else 'FAIL',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)', 'flags': FLAGS,
    'original': 'clients/2008-06/Roblox.exe', 'original_sha256': sha(CLIENT), 'object_sha256': sha(obj),
    'library_query_interface_proof': library_query_interface,
    'layout_object_sha256': sha(layout_obj), 'guid_object_sha256': sha(guid_obj), 'helper_object_sha256': sha(helper_obj),
    'compile_profile': 'class unit: document-swap flags + ' + THREAD_MODEL + ' (ATL object model CComSingleThreadModel, globals Multi; original spelling not proven) /P, CString operator PCXSTR marked noinline (original imports mfc90 #910; header unchanged), recompiled with ' + ' '.join(PROFILE_FLAGS) + '; layout, GUID and helper units: plain document-swap flags',
    'typed_guid_data': guid_facts, 'helper_rows': helper_rows, 'sources': sources, 'methods': rows,
    'method_labels': {'00410f90': 'exact: IBrowserViewExternal::get_IsIDE (compiler ABI; no thunk, no offset hack)',
                      '00410fe0': 'exact: IBrowserViewExternal::GetApp (AFX state guard, CoCreateInstance, CString::Format error path through reportWorkspaceSiteError, CComPtr temporary CopyTo); codegen analog',
                      '0040fbf0': 'exact: createBrowserViewExternal, codegen analog of ATL9 CComObject<Base>::CreateInstance for '
                                  'CComObjectNoLock (free-function name and the unused int are not proven)'},
    'reuse_classification': reuse,
    'layout': {
        'sizeof_ATL_CComObjectNoLock': '0x20 (assert) = operator new(0x20) in creator 0040fbf0',
        'sizeof_class': '0x20', 'isIDE_offset': '0x1c (offsetof assert)',
        'layout_test': 'tests/NativeBrowserViewExternalLayout.cpp compiled into ' + layout_obj.name,
        'creator_allocation': alloc, 'creator_lifetime': lifetime},
    'rtti': rtti, 'tables': words,
    'table_reference_counts': {'%08x' % k: v for k, v in references.items()},
    'vector_deleting_destructor': 'vtable slot 4 of 0080d778 names the weak external ??_E; the emitted body is ??_G and matches 0040f770',
    'data_facts': data_facts, 'asserted_body_not_exact': verify_stack, 'asserted_targets': {k: '%08x' % v for k, v in ASSERTED.items()}, 'failures': failures, 'known_open_bodies': row_failures,
    'thread_model': {'macro': THREAD_MODEL, 'atlbase_h': '_ATL_APARTMENT_THREADED: CComObjectThreadModel=CComSingleThreadModel, CComGlobalsThreadModel=CComMultiThreadModel',
                     'original_proof': 'enumerator vtables 0080d790/0080d7f0 RTTI name CComSingleThreadModel; allocation 0x1c (default multi model emitted 0x38)',
                     'original_macro_spelling': 'not proven', 'applies_to': 'class unit preprocess only; header and sources unchanged'},
    'declared_methods': {'total': 2, 'tested': ['get_IsIDE 00410f90', 'GetApp 00410fe0'], 'open': []},
    'enum_template_proof': {
        'status': 'PASS' if enum_tables and not failures else 'FAIL',
        'kind': 'authentic ATL9 CComObject<CComEnum<..., CComSingleThreadModel>> template instantiations (no wrapper fields, no vendor header edit)',
        'tables': enum_tables,
        'new_unique_address_rows': [{'symbol': s, 'address': '%08x' % a} for s, a in enum_new_rows],
        'new_support_rows': [{'symbol': s, 'address': '%08x' % a} for s, a in enum_support_pairs],
        'alias_rows_reused_address': [{'symbol': r['symbol'], 'address': r['address'], 'size': r['size'], 'exact': r['exact'],
                                       'reused_address_of': next(m[0] for m in METHODS if '%08x' % m[1] == r['address']),
                                       'verified_targets': r['verified_targets'], 'unproven_targets': r.get('unproven_targets', {})} for r in alias_rows],
        'counts': {'slots_total': sum(c for c, _ in enum_slot_words.values()), 'new_unique_slot_addresses': len(enum_new_rows),
                   'alias_slots_at_reused_addresses': len(enum_alias_pairs), 'new_support_addresses': len(enum_support_pairs),
                   'new_unique_addresses_total': len(enum_new_rows) + len(enum_support_pairs)},
        'reuse_hash_pins': {'AtlInternalQueryInterface 00402280': 'library_query_interface_proof (MFC wincore RTM 21022)', 'AtlThrowImpl 00401000': 'atlexcept.h row in methods'},
        'unproven_targets': 'ATL::_pAtlModule 0096c268 (CComObject deleting destructors and CreateInstance); no stack-verify or alloca target in these bodies; ATL module state, CRT and operator-delete bodies are import identities only',
        'not_claimed': 'class remains PARTIAL and inactive; library/static/linkage gaps retained; a byte-exact row with unproven targets is not full acceptance'},
    'open_vtable_slots': open_slots,
    'undefined_symbols_needed_by_object': undefined_all,
    'open': {
        'GetApp_00410fe0': 'exact object row; ole32 CoCreateInstance, CString and AFX state-guard import identities verified; format string and typed GUID data verified; helper 00429330 body exact from WorkspaceSiteError.cpp. Its further callees and GUID_NULL remain open as recorded in helper_rows; import identity does not claim an imported implementation body was reconstructed',
        'guid_definitions': 'IID_IBrowserViewExternal, LIBID_RobloxLib, CLSID_BrowserViewExternal now defined once in native-classes/CBrowserViewExternalGuids.cpp (separate unit: defined in the class unit they constant-fold InterfaceSupportsErrorInfo to 76 bytes vs 78). LIBID_RobloxLib is shared logically with CContent/CWorkspace headers (declared C++-linkage there): linkage identity not reconciled, owners not edited',
        'Enum_bodies': 'EnumConnectionPoints (004100a0, 440) and EnumConnections (004104b0, 436) are masked-exact rows with the single-thread enumerator profile; vtables 0080d790/0080d7f0 verified by RTTI. Their 16 slot bodies (QI/AddRef/Release/Next/Skip/Reset/Clone/deleting destructor) and the four support bodies (CreateInstance x2, ~CComEnumImpl x2) are masked-exact rows: see enum_template_proof. Still open: _pAtlModule 0096c268 as a relocation operand (also in 004100a0/004104b0), _AtlVerifyStackAvailable 00402610 (emitted 156 vs 93) and __alloca_probe 006a1520 (004100a0, 00404a80)',
        'constructor_destructor': 'standalone constructor/destructor bodies are inlined into the creator and the deleting destructor and are not rows',
        'scope': 'source/object proof only; partial class (ATL module/stack/alloca/static targets open); no server credit, no selection, no build/runtime claim'}}
RECEIPT.parent.mkdir(parents=True, exist_ok=True)
(RECEIPT if passed else FAIL).write_text(json.dumps(receipt, indent=2) + '\n')
print('%s native %s: %d exact row(s)%s' % (receipt['status'], C, len(rows), '' if passed else '\n  ' + '\n  '.join(failures)))
sys.exit(0 if passed else 1)
