"""Partial proof for the inactive native CBrowserViewExternal (ATL COM class): layout test
(sizeof / offsetof compile assertions), both declared COM methods, creator, ATL template/helper bodies,
and the original RTTI of vtable 0080d778 (CComObjectNoLock<CBrowserViewExternal>).
The creator 0040fbf0 (authentic ATL9 construction sequence) and the four vtables' emitted ATL bodies are bound slot by slot.
Both declared COM methods, the creator and enum bodies are recovered. Several library/data targets remain open;
the receipt separates masked-exact bodies from verified relocation identities and transitive body proofs.
Writes work/2008-06/shared-layouts/browser-view-external-working.json (status PARTIAL when all recorded checks pass);
on any failure writes a FAIL receipt under work/cbrowserviewexternal-guided-20261104/ and exits non-zero.

Profile: document-swap flags with this checkout's include roots; MSVC 15.00.21022 (VS2008 RTM). Original: the registered
clients/2008-06/Roblox.exe checked against clients.json. Scope: source/object proof only.
"""
import hashlib
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
PROPOSAL = ROOT / 'work/2008-06/shared-layouts/browser-view-external-stack-extent.json'
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
                '__GUID_b196b285_bab4_101a_b69c_00aa00341d07': 0x80d7c8, '__GUID_b196b287_bab4_101a_b69c_00aa00341d07': 0x80d3e0,
                # SDK __uuidof() copies read by the typeinfo helpers (bytes checked here; SDK declarations in prove_typeinfo_guids)
                '__GUID_00020412_0000_0000_c000_000000000046': 0x80b130, '__GUID_00020401_0000_0000_c000_000000000046': 0x80b1f0,
                '__GUID_00000000_0000_0000_c000_000000000046': 0x80b154}
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
           ('?AtlThrowImpl@ATL@@YGXJ@Z', 0x401000), ('??$AtlAdd@K@ATL@@YAJPAKKK@Z', 0x402520)]
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
# ATL typeinfo helper bodies that GetTI 00404a80 calls (and that the helpers call). They are already emitted, unchanged, by the
# authentic ATL9 header templates in this object: no provider, source or flag is added. Each is bound by exact masked bytes;
# every relocation operand must then resolve (import, row, GUID data, CRT member proof) or stay an explicit unproven target.
TYPEINFO_HELPERS = [
    ('?AtlA2WHelper@@YGPA_WPA_WPBDHI@Z', 0x401760),
    ('??1?$CComCritSecLock@VCComCriticalSection@ATL@@@ATL@@QAE@XZ', 0x420bb0),
    ('??$?4UITypeInfo2@@@?$CComPtr@UITypeInfo@@@ATL@@QAEPAUITypeInfo@@ABV?$CComPtr@UITypeInfo2@@@1@@Z', 0x403af0),
    ('?Cleanup@CComTypeInfoHolder@ATL@@SGXK@Z', 0x402f00),
    ('?AddTermFunc@CAtlModule@ATL@@QAEJP6GXK@ZK@Z', 0x403da0),
    ('?LoadNameCache@CComTypeInfoHolder@ATL@@QAEJPAUITypeInfo@@@Z', 0x402d30),
    # callees of the helpers above
    ('??1stringdispid@CComTypeInfoHolder@ATL@@QAE@XZ', 0x401020),
    ('??0stringdispid@CComTypeInfoHolder@ATL@@QAE@XZ', 0x402370),
    ('?IsEqualObject@?$CComPtrBase@UITypeInfo@@@ATL@@QAE_NPAUIUnknown@@@Z', 0x402fb0)]
typeinfo_helper_pairs = []
for symbol, address in TYPEINFO_HELPERS:
    if symbol in present and address not in {a for s, a in METHODS}:
        METHODS.append((symbol, address))
        typeinfo_helper_pairs.append((symbol, address))
    else:
        failures.append('typeinfo helper %08x: not emitted or already a row' % address)
# 004038f0 is emitted too (authentic atlbase.inl AtlModuleAddTermFunc) but its bytes are NOT exact: it is never a row.
ATL_ADD_TERM = '?AtlModuleAddTermFunc@ATL@@YGJPAU_ATL_MODULE70@1@P6GXK@ZK@Z'
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
ASSERTED['?_AtlVerifyStackAvailable@_ATL_SAFE_ALLOCA_IMPL@ATL@@YA_NK@Z'] = 0x402610   # full 156-byte span matches (masked); recorded extent 93 is stale and NOT applied: see full_stack_owner_pending_extent
ASSERTED['__alloca_probe'] = 0x6a1520   # CRT helper: relocation operand in rows; archive member bytes proven separately (crt_stack_probe_proof)
ASSERTED['__alloca_probe_16'] = 0x6a1560   # CRT helper: relocation operand in rows; archive member bytes proven separately (crt_stack_probe_proof)
ASSERTED['??_L@YGXPAXIHP6EX0@Z1@Z'] = 0x6a1598   # CRT EH vector constructor iterator: archive member proven separately (crt_eh_vector_proof)
ASSERTED['??_M@YGXPAXIHP6EX0@Z@Z'] = 0x6a165b    # CRT EH vector destructor iterator: archive member proven separately (crt_eh_vector_proof)
ASSERTED[ATL_ADD_TERM] = 0x4038f0   # emitted authentic atlbase.inl body is NOT byte exact (typeinfo_helper_proof.atl_module_add_term_func): address is a relocation operand only


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



STACK = '?_AtlVerifyStackAvailable@_ATL_SAFE_ALLOCA_IMPL@ATL@@YA_NK@Z'
STACK_ADDRESS, STACK_RECORDED, STACK_FULL = 0x402610, 93, 156
ATLADD = '??$AtlAdd@K@ATL@@YAJPAKKK@Z'
verify_stack = first_difference(STACK, STACK_ADDRESS) if STACK in present else None
if verify_stack:
    verify_stack.update({
        'classification': 'recorded extent stale (pending server extent acceptance); not wrong codegen',
        'reason': 'the first raw difference (offset 6) is the __sehtable$ relocation operand, not a wrong body; the full 156 bytes match under 5 relocations (see full_stack_owner_pending_extent)',
        'recorded_original_size_is_stale': True, 'superseded_by': 'full_stack_owner_pending_extent'})


def prove_stack_owner():
    """Full 156-byte owner of 00402610 (recorded as 93): masked byte match, five relocation identities, SEH scope table,
    control flow, calling convention and the pure (unrecorded) tail_proof. Nothing here changes bounds or inventory."""
    import hashlib
    from capstone import Cs, CS_ARCH_X86, CS_MODE_32
    from roc import bounds_proof
    need(STACK in definitions, 'owner symbol not emitted')
    start, section = definitions[STACK]
    sec = sections[section]
    need(start == 0 and sec[3] == STACK_FULL and sec[9] & 0x20, ('owner COMDAT', start, sec[3]))
    code = raw[sec[4]:sec[4] + STACK_FULL]
    target = original.data(STACK_ADDRESS, STACK_FULL)
    relocs = [struct.unpack_from('<IIH', raw, sec[5] + 10 * k) for k in range(sec[7])]
    need([r[0] for r in relocs] == [6, 11, 62, 84, 123], relocs)
    window = {i for off, _, _ in relocs for i in range(off, off + 4)}
    raw_diff = [i for i in range(STACK_FULL) if code[i] != target[i]]
    need(raw_diff and set(raw_diff) <= window, ('bytes differ outside relocation windows', raw_diff))
    resolved = {}
    for off, index, kind in relocs:
        name = symbols[index][0]
        if kind == 20:
            value, form = (STACK_ADDRESS + off + 4 + struct.unpack_from('<i', target, off)[0]) & 0xffffffff, 'rel32'
            need(struct.unpack_from('<i', code, off)[0] == 0, ('rel32 addend', name))
        else:
            need(kind == 6, (name, kind))
            value, form = (struct.unpack_from('<I', target, off)[0] - struct.unpack_from('<i', code, off)[0]) & 0xffffffff, 'dir32'
        resolved[off] = (name, form, value)
    # identities, each against the original's own data
    name, _, value = resolved[6]
    need(name.startswith('__sehtable$' + STACK) and value == 0x8d0748, resolved[6])
    sec_seh = sections[symbols[relocs[0][1]][2] - 1]
    seh_relocs = [struct.unpack_from('<IIH', raw, sec_seh[5] + 10 * k) for k in range(sec_seh[7])]
    seh_data = raw[sec_seh[4]:sec_seh[4] + 12]
    need(sec_seh[3] == 12 and [r[0] for r in seh_relocs] == [4, 8] and all(r[2] == 6 for r in seh_relocs), seh_relocs)
    labels = [symbols[r[1]] for r in seh_relocs]
    need(all(l[2] == section + 1 for l in labels), labels)
    emitted_scope = (struct.unpack_from('<I', seh_data, 0)[0],) + tuple(
        (STACK_ADDRESS + l[1] + struct.unpack_from('<I', seh_data, r[0])[0]) & 0xffffffff for r, l in zip(seh_relocs, labels))
    original_scope = struct.unpack('<3I', original.data(0x8d0748, 12))
    need(emitted_scope == original_scope == (0xffffffff, 0x40266d, 0x402681), (emitted_scope, original_scope))
    name, _, value = resolved[11]
    thunk = original.imported(value)
    need(name == '__except_handler3' and thunk == ('msvcr90.dll', '_except_handler3') and name == '_' + thunk[1], (resolved[11], thunk))
    need(resolved[62][0] == ATLADD and resolved[62][2] == 0x402520 and dict(METHODS).get(ATLADD) == 0x402520, resolved[62])
    need(resolved[84][0] == '__alloca_probe_16' and resolved[84][2] == 0x6a1560, resolved[84])
    name, _, value = resolved[123]
    iat = original.imports.get(value)
    need(name == '__imp___resetstkoflw' and iat and (iat[0], iat[2]) == ('msvcr90.dll', '_resetstkoflw') and name == '__imp__' + iat[2], (resolved[123], iat))
    # control flow, filter constant, calling convention (disassembly of the ORIGINAL bytes)
    instructions = list(Cs(CS_ARCH_X86, CS_MODE_32).disasm(target, STACK_ADDRESS))
    need(sum(i.size for i in instructions) == STACK_FULL, 'disassembly does not cover the span')
    to_exit = [hex(i.address) for i in instructions if i.mnemonic.startswith('j') and i.op_str == '0x40268f']
    need(len(to_exit) == 2, to_exit)
    need(target[0x70:0x71] == b'\xc3' and target[-1:] == b'\xc3' and not any(i.mnemonic == 'ret' and i.op_str for i in instructions), 'owner is not bare-ret cdecl')
    need(b'\x3d\xfd\x00\x00\xc0' in target, 'filter STATUS_STACK_OVERFLOW constant')
    # inventory rows (read only) and the pure tail proof
    rows = bounds_proof._rows('2008-06')[0]
    own, filt, hand = rows['00402610'], rows['0040266d'], rows['00402681']
    need((own['size'], filt['size'], hand['size'], filt['kind'], hand['kind']) == (93, 20, 43, 'eh', 'eh'), (own['size'], filt['size'], hand['size']))
    need(STACK_ADDRESS + STACK_RECORDED == 0x40266d and 0x40266d + 20 == 0x402681 and 0x402681 + 43 == 0x4026ac, 'adjacent rows do not tile 156')
    prev_end = 0x4025b0 + rows['004025b0']['size']
    need(prev_end == 0x402609 and set(original.data(prev_end, STACK_ADDRESS - prev_end)) <= {0xcc}, 'previous function end/padding')
    need(set(original.data(0x4026ac, 4)) == {0xcc} and '004026b0' in rows, 'next function after padding')
    callers = own['callers']
    call_sites = []
    for caller in callers:
        body = original.data(int(caller, 16), rows[caller]['size'])
        for i in range(len(body) - 4):
            if body[i] == 0xe8 and (int(caller, 16) + i + 5 + struct.unpack_from('<i', body, i + 1)[0]) & 0xffffffff == STACK_ADDRESS:
                call_sites.append((caller, body[i + 5:i + 8] == b'\x83\xc4\x04'))
    cleaned = sum(1 for _, ok in call_sites if ok)
    need(call_sites and cleaned == len(call_sites), ('caller cleanup is not add esp,4', [c for c, ok in call_sites if not ok]))
    tail = bounds_proof.tail_proof('2008-06', '%08x' % STACK_ADDRESS, [(STACK, code, [off for off, _, _ in relocs])])
    need(tail and (tail['old'], tail['new'], tail['clean']) == (93, 156, True) and tail['absorbs'] == ['0040266d', '00402681'], tail)
    comp = [v for n, v, _s, _k in symbols.values() if n == '@comp.id']
    need(len(comp) == 1 and comp[0] & 0xffff == 21022, comp)
    header = ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/include/atlalloc.h'
    return {
        'status': 'FULL-SPAN MASKED MATCH, EXTENT NOT APPLIED',
        'accepted_exact_function': False, 'counted_in_methods': False, 'bound_in_verified_targets': False,
        'bounds_status': 'pending server extent acceptance: the inventory/server extent is still 93; this receipt records proof only',
        'server_extent_status': 'not applied', 'server_credit_asserted': False,
        'symbol': STACK, 'address': '%08x' % STACK_ADDRESS,
        'recorded_size': STACK_RECORDED, 'proposed_size': STACK_FULL, 'proposed_end': '004026ac',
        'inventory_rows_absorbed': [{'address': '0040266d', 'size': 20, 'role': 'SEH filter ($LN7, object offset 0x5d)'},
                                    {'address': '00402681', 'size': 43, 'role': 'SEH handler ($LN8, object offset 0x71); also contains the normal-exit label 0040268f'}],
        'adjacent': {'previous': '004025b0 (89 bytes, ends 00402609, 0xcc padding to 00402610)', 'next': '004026b0 after 0xcc padding'},
        'original_156_sha256': hashlib.sha256(target).hexdigest(), 'original_93_prefix_sha256': hashlib.sha256(target[:STACK_RECORDED]).hexdigest(),
        'object': {'comdat_text_size': len(code), 'comdat_text_sha256': hashlib.sha256(code).hexdigest(), 'object_sha256': sha(obj),
                   'compiler': 'MSVC 15.00.21022 (VS2008 RTM)', 'coff_compiler_id': comp[0], 'flags': FLAGS, 'profile_flags': PROFILE_FLAGS,
                   'source': 'ATL9 atlalloc.h _AtlVerifyStackAvailable (header-instantiated, no application source)',
                   'source_header': 'tools/libs/mfc-9.0-rtm/atlmfc/include/atlalloc.h', 'source_header_sha256': sha(header)},
        'masked_differences': [], 'raw_difference_offsets': raw_diff,
        'raw_difference_note': 'all raw differences lie inside the 5 relocation windows (first at +6 = __sehtable$ operand); the 93-byte body is not wrong',
        'relocations': {str(off): {'symbol': n, 'form': f, 'original_value': '%08x' % v} for off, (n, f, v) in resolved.items()},
        'relocation_identities': {
            '+6': '__sehtable$ scope table at 008d0748',
            '+11': '__except_handler3 operand 006a1512 = jmp [%08x] = %s!%s' % (struct.unpack_from('<I', original.data(0x6a1512, 6), 2)[0], thunk[0], thunk[1]),
            '+62': 'AtlAdd<unsigned long> row 00402520 (exact masked row in methods)',
            '+84': '__alloca_probe_16 at 006a1560 (CRT archive member proof: crt_stack_probe_proof)',
            '+123': '__imp___resetstkoflw = IAT 00802894 = msvcr90.dll!_resetstkoflw'},
        'seh_scope_table': {'address': '008d0748', 'original_words': ['%08x' % w for w in original_scope], 'emitted_words_after_label_resolution': ['%08x' % w for w in emitted_scope],
                            'object_labels': {symbols[r[1]][0]: '0x%x' % symbols[r[1]][1] for r in seh_relocs},
                            'filter': '0040266d: [ebp-0x14] -> EXCEPTION_POINTERS, compares ExceptionCode with 0xc00000fd (STATUS_STACK_OVERFLOW)',
                            'handler': '00402681: restores esp from [ebp-0x18], clears result, calls _resetstkoflw, falls into the normal-exit label'},
        'control_flow': {'normal_exit_label': '0040268f (inside the handler row 00402681)', 'jumps_to_normal_exit': to_exit,
                         'alloca_site': '00402663 call 006a1560 with eax = [ebp-0x20] (probe size), esp saved to [ebp-0x18] afterwards'},
        'calling_convention': {'return': 'bare c3 (cdecl, caller cleans) - NOT ret 4', 'decoration': 'YA_NK (cdecl)',
                               'caller_cleanup': '%d/%d call sites followed by add esp,4 across %d caller functions' % (cleaned, len(call_sites), len(callers))},
        'data_checks': {'scope_table': 'compared word by word with the original after resolving object labels', 'iat': '00802894 import by name', 'except_handler3_thunk': '006a1512 jmp [IAT] import by name'},
        'bounds_proof': {k: tail[k] for k in ('old', 'new', 'absorbs', 'clean', 'proof')},
        'bounds_proof_note': 'bounds_proof.tail_proof called directly: nothing recorded, bounds.json/functions.jsonl untouched, roc extents --apply not run',
        'caller_status': 'pending-boundary: callers see the recorded 93-byte extent. This is an extent gap, not a wrong-codegen finding.'}


def prove_crt_stack_probes():
    """__alloca_probe/__chkstk (006a1520) and __alloca_probe_16 (006a1560), from the genuine RTM 21022 CRT archives (recipe msvc-crt)."""
    import hashlib
    from roc import libs, setup
    build = 21022
    compiler = setup.compilers()[build]
    folder = libs._archive_dir(libs.RECIPES['msvc-crt'], compiler)
    wanted = ('chkstk.obj', 'alloca16.obj')
    members, archives = {}, {}
    for library in libs.RECIPES['msvc-crt']['files']:
        path = folder / library
        archives[library] = {'path': str(path), 'sha256': sha(path)}
        for member, data in libs.archive_members(path):
            leaf = member.replace(chr(92), '/').split('/')[-1].lower()
            if leaf in wanted:
                members[(library, leaf)] = (member, data)

    def text_section(data):
        for i in range(struct.unpack_from('<H', data, 2)[0]):
            header = struct.unpack_from('<8sIIIIIIHHI', data, 20 + 40 * i)
            if header[0].startswith(b'.text'):
                return header
    chk_target = original.data(0x6a1520, 43)
    a16_target = original.data(0x6a1560, 22) + original.data(0x6a1576, 22)
    jumps = [(0x6a1560 + 17 + 5 + struct.unpack_from('<i', a16_target, 18)[0]) & 0xffffffff,
             (0x6a1576 + 17 + 5 + struct.unpack_from('<i', a16_target, 40)[0]) & 0xffffffff]
    need(jumps == [0x6a1520, 0x6a1520], jumps)
    need(set(original.data(0x6a154b, 1)) == {0xcc}, 'padding after __chkstk')
    result = {}
    for (library, leaf), (member, data) in sorted(members.items()):
        header = text_section(data)
        body = data[header[4]:header[4] + header[3]]
        _, member_symbols, _, _ = match._coff_data_index(data)
        global_symbols = {n: v for n, v, sec, typ in member_symbols.values() if sec == 1 and typ in (0, 0x20)}
        if leaf == 'chkstk.obj':
            need(body == chk_target and header[7] == 0, (library, leaf, 'bytes differ'))
            need(global_symbols.get('__alloca_probe') == 0 and global_symbols.get('__chkstk') == 0, global_symbols)
            proof = {'original': '006a1520, 43 bytes (byte equal; no relocations)', 'symbols': {'__alloca_probe': '006a1520', '__chkstk': '006a1520 (alias, same member offset 0)'}}
        else:
            relocs = [struct.unpack_from('<IIH', data, header[5] + 10 * k) for k in range(header[7])]
            need([(r[0], member_symbols[r[1]][0], r[2]) for r in relocs] == [(18, '__chkstk', 20), (40, '__chkstk', 20)], relocs)
            mine, ref = bytearray(body), bytearray(a16_target)
            for off in (18, 40):
                mine[off:off + 4] = ref[off:off + 4] = b'\0\0\0\0'
            need(bytes(mine) == bytes(ref) and len(body) == 44, (library, leaf, 'masked bytes differ'))
            need(global_symbols.get('__alloca_probe_16') == 0 and global_symbols.get('__alloca_probe_8') == 0x16, global_symbols)
            proof = {'original': '006a1560 (22) + 006a1576 (22), masked equal; both rel32 jumps resolve to 006a1520 = __chkstk',
                     'symbols': {'__alloca_probe_16': '006a1560', '__alloca_probe_8': '006a1576'}, 'relocations': '2 x rel32 __chkstk at +18, +40'}
        result['%s!%s' % (library, leaf)] = dict(proof, member=member, member_sha256=hashlib.sha256(data).hexdigest(),
                                                  text_size=len(body), text_sha256=hashlib.sha256(body).hexdigest(), archive_sha256=archives[library]['sha256'])
    need(len(result) == 4, sorted(result))
    # calling convention evidence from the original call sites
    code = original.data(0x4100a0, 440)
    site = 0x410168 - 0x4100a0
    need(code[site] == 0xe8 and (0x4100a0 + site + 5 + struct.unpack_from('<i', code, site + 1)[0]) & 0xffffffff == 0x6a1520
         and code[site - 5:site] == b'\xb8\x04\x00\x00\x00', 'call site 00410168')
    owner = original.data(STACK_ADDRESS, STACK_FULL)
    need(owner[0x50:0x53] == b'\x8b\x45\xe0' and owner[0x53] == 0xe8 and (STACK_ADDRESS + 0x53 + 5 + struct.unpack_from('<i', owner, 0x54)[0]) & 0xffffffff == 0x6a1560, 'call site 00402663')
    return {'status': 'PASS', 'kind': 'genuine compiler runtime archive members (recipe msvc-crt); no source, no assembler, no byte blob provider',
            'compiler': str(compiler), 'compiler_build': build, 'compiler_sha256': sha(compiler), 'archives': archives, 'members': result,
            'archive_choice_note': 'libcmt.lib (mt_obj) and msvcrt.lib (dll_obj) .text bytes are identical, so the bytes do not choose between them; the client imports msvcr90.dll (/MD), whose import library is msvcrt.lib',
            'original_layout': {'006a1520': '__alloca_probe/__chkstk (43 bytes)', '006a154c, 006a1552': 'msvcr90 import thunks (unrelated), 0xcc padding to 006a1560',
                                '006a1560': '__alloca_probe_16 (22)', '006a1576': '__alloca_probe_8 (22)'},
            'abi': {'convention': 'special register intrinsic, not a C++ function: size in EAX on entry; the helper subtracts it from ESP (probing pages) and returns with ESP lowered',
                    'call_sites': {'00402663': 'mov eax,[ebp-0x20]; call 006a1560; mov [ebp-0x18],esp (owner 00402610)', '00410168': 'mov eax,4; call 006a1520 (EnumConnectionPoints 004100a0)'}},
            'caller_note': '00404a80 (GetTI) calls 006a1560, not 006a1520; 006a1520 is called by 004100a0',
            'scope': 'runtime/library byte identity only; not a native C++ body row and not counted in methods'}



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
stack_owner = check('full stack owner 00402610 (156 bytes)', prove_stack_owner)
crt_stack_probes = check('CRT stack probe archive members', prove_crt_stack_probes)


def prove_crt_eh_vector():
    """??_L (006a1598) and ??_M (006a165b), called by the typeinfo helpers LoadNameCache / Cleanup: genuine RTM 21022 CRT archive members
    ehvecctr.obj / ehvecdtr.obj (recipe msvc-crt), compared to the original bytes with the member's own relocations masked."""
    import hashlib
    from roc import libs, setup
    compiler = setup.compilers()[21022]
    folder = libs._archive_dir(libs.RECIPES['msvc-crt'], compiler)
    wanted = {'ehvecctr.obj': ('??_L@YGXPAXIHP6EX0@Z1@Z', 0x6a1598), 'ehvecdtr.obj': ('??_M@YGXPAXIHP6EX0@Z@Z', 0x6a165b)}
    result, archives = {}, {}
    for library in libs.RECIPES['msvc-crt']['files']:
        path = folder / library
        archives[library] = {'path': str(path), 'sha256': sha(path)}
        for member, data in libs.archive_members(path):
            leaf = member.replace(chr(92), '/').split('/')[-1].lower()
            if leaf not in wanted:
                continue
            symbol, address = wanted[leaf]
            msections, msymbols, mdefinitions, _ = match._coff_data_index(data)
            need(symbol in mdefinitions and mdefinitions[symbol][0] == 0, (library, leaf, 'symbol not at member offset 0'))
            table = msections[mdefinitions[symbol][1]]
            body = data[table[4]:table[4] + table[3]]
            relocs = [struct.unpack_from('<IIH', data, table[5] + 10 * k) for k in range(table[7])]
            unmasked = original.data(address, len(body))
            mine, ref = bytearray(body), bytearray(unmasked)
            for off, _index, _kind in relocs:
                mine[off:off + 4] = ref[off:off + 4] = b'\0\0\0\0'
            need(bytes(mine) == bytes(ref), (library, leaf, 'masked bytes differ'))
            targets = {}
            for off, index, kind in relocs:
                name = msymbols[index][0]
                if kind == 20:
                    targets[name] = '%08x' % ((address + off + 4 + struct.unpack_from('<i', unmasked, off)[0]) & 0xffffffff)
                else:
                    targets[name] = '%08x (relocation operand, not verified here)' % struct.unpack_from('<I', unmasked, off)[0]
            inventory = len(match.target('2008-06', '%08x' % address)[0])
            result['%s!%s' % (library, leaf)] = {
                'symbol': symbol, 'original': '%08x' % address, 'member_text_size': len(body), 'inventory_extent': inventory,
                'inventory_extent_stale': inventory != len(body), 'masked_equal_over_full_member': True,
                'relocation_operands_in_original': targets, 'member': member, 'member_sha256': hashlib.sha256(data).hexdigest(),
                'text_sha256': hashlib.sha256(body).hexdigest(), 'archive_sha256': archives[library]['sha256']}
    need(len(result) == 4, sorted(result))
    return {'status': 'PASS', 'kind': 'genuine compiler runtime archive members (recipe msvc-crt); no source, no assembler, no byte blob provider',
            'compiler': str(compiler), 'compiler_sha256': sha(compiler), 'archives': archives, 'members': result,
            'scope': 'runtime/library byte identity only; not a native C++ row and not counted in methods. __SEH_prolog4 006a1fbc, __SEH_epilog4 006a2001 and '
                     '__ArrayUnwind 006a15fd (jump targets of these members) and the members\' __sehtable$ scope tables are relocation operands here and are NOT proven',
            'extent_note': 'inventory extents (77 / 75 bytes) are stale prefixes of the 101 / 99 byte members; metadata not changed'}


crt_eh_vector = check('CRT EH vector archive members', prove_crt_eh_vector)


def section_name(value):
    return (value.decode() if isinstance(value, bytes) else str(value)).rstrip(chr(0))


def prove_typeinfo_guids():
    """SDK declarations (from the preprocessed class unit, genuine Windows SDK headers) for the GUID data the typeinfo helpers read,
    plus the emitted COFF bytes against the original bytes. GUID_NULL: SDK declaration and the original read-only all-zero bytes."""
    text = (OUT / 'CBrowserViewExternal.i').read_text(errors='replace')

    def declaration(pattern):
        m = re.search(pattern, text, re.I)
        need(m, pattern)
        mark = text.rfind(chr(10) + '#line ', 0, m.start())
        path = re.search(r'"(.*)"', text[mark + 1:text.index(chr(10), mark + 1)]).group(1).replace(chr(92) * 2, chr(92))
        return Path(path)

    facts = {}
    for iface, guid, symbol, address in (('ITypeInfo2', '00020412-0000-0000-C000-000000000046', '__GUID_00020412_0000_0000_c000_000000000046', 0x80b130),
                                         ('ITypeInfo', '00020401-0000-0000-C000-000000000046', '__GUID_00020401_0000_0000_c000_000000000046', 0x80b1f0),
                                         ('IUnknown', '00000000-0000-0000-C000-000000000046', '__GUID_00000000_0000_0000_c000_000000000046', 0x80b154)):
        header = declaration(r'uuid\("%s"\)\)\s*__declspec\(novtable\)\s*%s\b' % (guid, iface))
        start, section = definitions[symbol]
        emitted = raw[sections[section][4] + start:][:16]
        need(emitted == original.data(address, 16) == uuid.UUID(guid).bytes_le, (symbol, 'bytes'))
        facts[symbol] = {'interface': iface, 'sdk_declaration': '__declspec(uuid("%s")) %s' % (guid, iface), 'sdk_header': str(header),
                         'sdk_header_sha256': sha(header) if header.exists() else None, 'original_address': '%08x' % address,
                         'emitted_coff_section': section_name(sections[section][0]), 'result': 'SDK __uuidof value, emitted 16 bytes and the original 16 bytes are equal'}
    header = declaration(r'extern const IID GUID_NULL;')
    section = next(s for s in original.pe.sections if original.image + s.VirtualAddress <= 0x8501ec < original.image + s.VirtualAddress + s.Misc_VirtualSize)
    need(original.data(0x8501ec, 16) == bytes(16) and not section.Characteristics & 0x80000000, 'GUID_NULL original bytes / section')
    null = {'symbol': '_GUID_NULL', 'original_address': '008501ec', 'sdk_declaration': 'extern const IID GUID_NULL;', 'sdk_header': str(header),
            'sdk_header_sha256': sha(header) if header.exists() else None, 'original_bytes': '16 x 00',
            'original_section': section.Name.rstrip(b'\0').decode(), 'original_section_readonly': True,
            'result': 'typed SDK GUID_NULL declaration, original storage is 16 zero bytes in a read-only section',
            'not_claimed': 'no runtime claim about zero-valued globals; helper callees 00427c20 and 004290b0 are NOT proven by this data check',
            'unit_note': 'declaration read from the class unit preprocess; WorkspaceSiteError.cpp includes windows.h (cguid.h via ole2.h) from the same SDK tree'}
    return {'status': 'PASS', 'guids': facts, 'guid_null': null}


typeinfo_guids = check('typeinfo SDK GUID data', prove_typeinfo_guids)


def describe_add_term_func():
    """004038f0 AtlModuleAddTermFunc: emitted by this object from the authentic atlbase.inl, compared with the original; recorded either way."""
    body, refs = dict((n, (b, r)) for n, b, r in match.coff_functions(raw))[ATL_ADD_TERM]
    target, target_refs, _ = match.target('2008-06', '004038f0')
    exact = bool(match.exact_match(target, target_refs, body, refs))
    masked = set()
    for off in set(refs) | set(target_refs):
        masked.update(range(off, off + 4))
    diff = [i for i in range(min(len(body), len(target))) if i not in masked and body[i] != target[i]]
    first = diff[0] if diff else None
    return {'address': '004038f0', 'symbol': ATL_ADD_TERM, 'exact': exact, 'emitted_size': len(body), 'original_size': len(target),
            'emitted_relocation_offsets': sorted(refs), 'original_relocation_offsets': sorted(target_refs),
            'non_relocation_difference_count': len(diff), 'first_non_relocation_difference': first,
            'emitted_window': body[first:first + 8].hex() if first is not None else None, 'original_window': target[first:first + 8].hex() if first is not None else None,
            'emitted_text_sha256': hashlib.sha256(body).hexdigest(), 'original_sha256': hashlib.sha256(target).hexdigest(),
            'status': 'exact (unexpected)' if exact else 'NOT EXACT: authentic atlbase.inl body (CComCritSecLock local) differs from the original; open, not a row, no server credit',
            'stored_analog': 'src/2008-06/004038f0.cpp (server cache 100%, library roc_unit_38a66487c88049f6.cpp, hand-written explicit Lock/Unlock, no CComCritSecLock): '
                             'an analog of unverified freshness, NOT adopted, NOT recompiled here, not authentic header text'}


add_term_func = check('AtlModuleAddTermFunc 004038f0 description', describe_add_term_func)


ADD_TERM_ANALOG = '?addTermDirect@@YGJPAU_ATL_MODULE70@ATL@@P6GXK@ZK@Z'
ADD_TERM_WRAPPER = ROOT / 'src/2008-06/004038f0.cpp'
ADD_TERM_UNIT = ROOT / 'tools/libs/mfc-9.0-rtm/roc_unit_38a66487c88049f6.cpp'
ADD_TERM_RELOCS = (6, 74, 115, 120, 142, 165)


def prove_add_term_analog():
    """004038f0: replay the EXISTING stored wrapper (typed explicit Lock/Unlock analog addTermDirect) under the explicit RTM 21022 compiler.

    This is a typed codegen analog, NOT the authentic upstream AtlModuleAddTermFunc text and NOT the original declaration; the authentic
    CComCritSecLock body stays in add_term_func above (not exact). No provider, no link acceptance, no new native row. The EH stub and the
    imported runtime functions are identified by address and import identity only."""
    from roc import setup

    build = 21022
    text = ADD_TERM_WRAPPER.read_text()
    need('// roc-cl: 21022' in text and 'mfc-9.0-shared-rtm roc_unit_38a66487c88049f6.cpp' in text, 'wrapper is not the RTM 21022 stored analog')
    analog_raw = match.compile_text('2008-06', text, build=build)
    analog_obj = OUT / 'AtlTermAnalog21022.obj'
    analog_obj.write_bytes(analog_raw)
    asec, asym, adef, _ = match._coff_data_index(analog_raw)
    ids = [value for name, value, _s, _k in asym.values() if name == '@comp.id']
    need(len(ids) == 1 and ids[0] & 0xffff == build, ('COFF compiler identity', ids))
    bodies = {n: (b, r) for n, b, r in match.coff_functions(analog_raw)}
    need(ADD_TERM_ANALOG in bodies, 'analog symbol not emitted')
    body, refs = bodies[ADD_TERM_ANALOG]
    target, target_refs, _ = match.target('2008-06', '004038f0')
    masked = set()
    for off in set(refs) | set(target_refs):
        masked.update(range(off, off + 4))
    diffs = [i for i in range(min(len(body), len(target))) if i not in masked and body[i] != target[i]]
    need(len(body) == len(target) == 191 and not diffs, ('analog bytes', len(body), len(target), diffs[:4]))
    need(bool(match.exact_match(target, target_refs, body, refs)), 'match.exact_match refused the analog')
    need(body[-3:] == b'\xc2\x0c\x00', 'not stdcall ret 12')
    rows = native_bind.verify(original, analog_obj, [(ADD_TERM_ANALOG, 0x4038f0)], {})

    start, secno = adef[ADD_TERM_ANALOG]
    table = asec[secno]
    code = analog_raw[table[4] + start:]
    operands = {}
    for i in range(table[7]):
        off, idx, kind = struct.unpack_from('<IIH', analog_raw, table[5] + 10 * i)
        off -= start
        if not 0 <= off < len(body):
            continue
        if kind == 20:
            value = (0x4038f0 + off + 4 + struct.unpack_from('<i', target, off)[0]) & 0xffffffff
        else:
            value = (struct.unpack_from('<I', target, off)[0] - struct.unpack_from('<i', code, off)[0]) & 0xffffffff
        operands[off] = (asym[idx][0], value, asym[idx][1])
    need(tuple(sorted(operands)) == ADD_TERM_RELOCS, ('relocation windows', sorted(operands)))
    need(operands[6][0].startswith('__ehhandler$') and operands[6][1] == 0x7bcc50, operands[6])
    need(original.imported(operands[74][1]) == ('mfc90.dll', '??2@YAPAXI@Z') and operands[74][1] == 0x6a0920, ('new', operands[74]))
    need(original.imported(operands[115][1]) == ('mfc90.dll', '?Delete@CException@@QAEXXZ') and operands[115][1] == 0x6a0950, ('delete', operands[115]))
    need(operands[120][0].startswith('$LN') and operands[120][1] == 0x4038f0 + 87 and operands[120][2] == 87, ('local continuation', operands[120]))
    need(original.imports.get(operands[142][1]) == ('kernel32.dll', None, 'EnterCriticalSection') and operands[142][1] == 0x8022d4, operands[142])
    need(original.imports.get(operands[165][1]) == ('kernel32.dll', None, 'LeaveCriticalSection') and operands[165][1] == 0x8021f4, operands[165])

    # exception data: emitted funcinfo/handler tables against the original's, then the type, funclet and handler stub
    base, image = match._image('2008-06')
    at = lambda a, n: bytes(image[a - base:a - base + n])
    word = lambda a: struct.unpack('<I', at(a, 4))[0]
    eh, hh = '__ehfuncinfo$' + ADD_TERM_ANALOG, '__ehhandler$' + ADD_TERM_ANALOG
    need(eh in adef and hh in adef, 'EH symbols missing')
    xoff, xsec = adef[eh]
    xs = asec[xsec]
    xdata = analog_raw[xs[4]:xs[4] + xs[3]]
    xrelocs = [struct.unpack_from('<IIH', analog_raw, xs[5] + 10 * k) for k in range(xs[7])]
    xmask = set()
    for off, _i, _k in xrelocs:
        xmask.update(range(off, off + 4))
    ostart = 0x8d09bc - xoff
    original_x = at(ostart, len(xdata))
    xdiff = [i for i in range(len(xdata)) if i not in xmask and xdata[i] != original_x[i]]
    need(not xdiff and len(xrelocs) == 5, ('xdata', xdiff, len(xrelocs)))
    need((ostart, xoff, len(xdata)) == (0x8d0988, 52, 88), 'EH section layout')
    xbindings = {
        4: ('??_R0PAVCException@@@8', 0x928604),
        12: ('__catch$' + ADD_TERM_ANALOG + '$0', 0x40395f),
        48: ('__catchsym$' + ADD_TERM_ANALOG + '$2', ostart),
        60: ('__unwindtable$' + ADD_TERM_ANALOG, ostart + 16),
        68: ('__tryblocktable$' + ADD_TERM_ANALOG, ostart + 32)}
    need({o for o, _i, _k in xrelocs} == set(xbindings), 'EH relocation offsets')
    for off, index, kind in xrelocs:
        symbol, expected = xbindings[off]
        need(kind == 6 and asym[index][0] == symbol, ('EH relocation identity', off, asym[index], kind))
        addend = struct.unpack_from('<I', xdata, off)[0]
        need(word(ostart + off) == expected + addend, ('EH relocation target', off))
        if off == 12:
            need(adef[symbol] == (111, secno), 'catch funclet COFF position')
        elif off in (48, 60, 68):
            need(adef[symbol] == (expected - ostart, xsec), ('EH local table COFF position', off))
    need((word(ostart + 52), word(ostart + 56), word(ostart + 64)) == (0x19930522, 2, 1), 'funcinfo magic/max state/try count')
    need((word(ostart + 60), word(ostart + 68), word(ostart + 48)) == (ostart + 16, ostart + 32, ostart), 'unwind/try/catch table links')
    descriptor = word(ostart + 4)
    catch_name = b'.PAVCException@@\0'
    need(descriptor == 0x928604 and at(descriptor + 8, len(catch_name)) == catch_name, 'catch type')
    tdpos, tdsec = adef['??_R0PAVCException@@@8']
    td = asec[tdsec]
    need(analog_raw[td[4] + tdpos + 8:td[4] + tdpos + 8 + len(catch_name)] == catch_name, 'emitted catch type name')
    need(word(ostart + 12) == 0x4038f0 + 111, 'catch funclet')
    stub_sec = asec[adef[hh][1]]
    stub_relocs = sorted(struct.unpack_from('<IIH', analog_raw, stub_sec[5] + 10 * k)[0] for k in range(stub_sec[7]))
    ostub = at(0x7bcc50, 10)
    stub_offset = adef[hh][0]
    stub = analog_raw[stub_sec[4] + stub_offset:stub_sec[4] + stub_offset + 10]
    stub_records = [struct.unpack_from('<IIH', analog_raw, stub_sec[5] + 10 * k) for k in range(stub_sec[7])]
    need(stub_records == [(1, stub_records[0][1], 6), (6, stub_records[1][1], 20)], 'handler relocation kinds')
    need(asym[stub_records[0][1]][0] == eh and asym[stub_records[1][1]][0] == '___CxxFrameHandler3', 'handler relocation symbols')
    need(stub_offset == 0 and stub == b'\xb8\0\0\0\0\xe9\0\0\0\0', 'emitted handler stub')
    need(ostub[0] == 0xb8 and struct.unpack_from('<I', ostub, 1)[0] == 0x8d09bc and ostub[5] == 0xe9, ('handler stub', ostub.hex()))
    thunk = (0x7bcc50 + 10 + struct.unpack_from('<i', ostub, 6)[0]) & 0xffffffff
    need(at(thunk, 2) == b'\xff\x25' and original.imports.get(struct.unpack_from('<I', at(thunk + 2, 4))[0])
         == ('msvcr90.dll', None, '__CxxFrameHandler3'), ('frame handler thunk', hex(thunk)))

    # genuine ATL ABI the analog was compiled against
    atlbase = ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/include/atlbase.h'
    abi = atlbase.read_text(errors='ignore')
    need('m_pTermFuncs' in abi and '_ATL_TERMFUNC_ELEM' in abi and 'm_csStaticDataInitAndTypeInfo' in abi, 'atlbase.h ABI names')
    inputs = [ADD_TERM_WRAPPER, ADD_TERM_UNIT, atlbase,
              ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/include/atlbase.inl',
              ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/include/afxwin.h']
    return {
        'status': 'PASS', 'kind': 'typed explicit Lock/Unlock codegen analog replay (source function addTermDirect); NOT authentic upstream AtlModuleAddTermFunc text, NOT the original declaration',
        'provider_or_link_acceptance': False, 'native_row': False, 'counts_toward_methods': False,
        'wrapper': 'src/2008-06/004038f0.cpp (existing stored wrapper, recipe mfc-9.0-shared-rtm, roc-cl 21022, /O2 /GS- /EHsc /MD)',
        'compiler_build': build, 'compiler_path': str(setup.compilers()[build]), 'compiler_sha256': sha(setup.compilers()[build]), 'coff_compiler_id': hex(ids[0]),
        'symbol': ADD_TERM_ANALOG, 'address': '004038f0', 'size': len(body), 'stdcall_ret': 12, 'non_relocation_differences': 0,
        'emitted_text_sha256': hashlib.sha256(body).hexdigest(), 'original_sha256': hashlib.sha256(target).hexdigest(),
        'relocation_operands': {'+%d' % o: {'symbol': operands[o][0], 'original_operand': '0x%x' % operands[o][1]} for o in sorted(operands)},
        'operand_identity': {'+6': 'local EH handler stub 0x7bcc50 (identified, not a native row)',
                             '+74': 'mfc90.dll !??2@YAPAXI@Z import thunk 0x6a0920 (import identity only)',
                             '+115': 'mfc90.dll !CException::Delete import thunk 0x6a0950 (import identity only)',
                             '+120': 'local continuation $LN offset 87 = 0x403947',
                             '+142': 'kernel32!EnterCriticalSection IAT 0x8022d4', '+165': 'kernel32!LeaveCriticalSection IAT 0x8021f4'},
        'inventory_relocation_offsets_omit': [74, 115], 'native_bind_rows': rows,
        'eh': {'xdata_masked_equal_except_5_reloc_slots': True, 'all_five_xdata_relocations_resolved': True,
               'handler_stub_masked_match_and_both_relocations_resolved': True,
               'xdata_original_start': '0x%x' % ostart, 'funcinfo': '0x8d09bc magic 19930522 max_state 2 try_blocks 1',
               'tables': 'catch 0x%x unwind 0x%x try 0x%x' % (ostart, ostart + 16, ostart + 32), 'catch_type': '0x928604 .PAVCException@@',
               'catch_funclet': '0x40395f = start+111', 'handler_stub': '0x7bcc50 b8 funcinfo e9 -> 0x%x jmp [0x8028bc] msvcr90!__CxxFrameHandler3 '
               '(identified by import identity only; stub and runtime implementation are not native rows)' % thunk, 'emitted_stub_relocations': stub_relocs},
        'abi': 'genuine RTM atlbase.h _ATL_MODULE70 (m_pTermFuncs +8, m_csStaticDataInitAndTypeInfo +0xC) and 12-byte _ATL_TERMFUNC_ELEM; stdcall ret 0xc',
        'distinct_evidence': 'the authentic CComCritSecLock body (add_term_func above) emits 191 bytes with ten non-relocation differences starting at 26 and stays unmatched; an addTermScoped variant (183 bytes) is also not exact',
        'object': {'path': 'rebuild/2008-06/out/native-layouts/browser-view-external/AtlTermAnalog21022.obj', 'sha256': sha(analog_obj)},
        'input_hashes': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in inputs}}


add_term_analog = check('AtlModuleAddTermFunc 004038f0 typed analog proof', prove_add_term_analog)
if add_term_analog:
    for row in rows:
        if row['address'] == '00403da0':
            value = row.get('unproven_targets', {}).pop(ATL_ADD_TERM)
            need(value == '0x4038f0', ('AddTermFunc callee', value))
            row['verified_targets'][ATL_ADD_TERM] = value
            row.setdefault('target_evidence', {})[ATL_ADD_TERM] = {
                'proof': 'termination_helper_analog_proof',
                'source_symbol': ADD_TERM_ANALOG,
                'kind': 'typed explicit-lock codegen analog; original declaration and upstream body spelling not proven',
                'provider_or_link_acceptance': False}

# Runtime archive identity is proved separately from application C++ rows. A proved full owner whose inventory
# extent is still stale remains pending; it is not bound as an accepted exact target.
runtime_targets = {'__alloca_probe': (0x6a1520, crt_stack_probes, 'crt_stack_probe_proof: authentic archive bytes, entry aliases and jump targets verified'),
                   '__alloca_probe_16': (0x6a1560, crt_stack_probes, 'crt_stack_probe_proof: authentic archive bytes, entry aliases and jump targets verified'),
                   '??_L@YGXPAXIHP6EX0@Z1@Z': (0x6a1598, crt_eh_vector, 'crt_eh_vector_proof: authentic ehvecctr.obj member, full 101-byte masked equality (its SEH/ArrayUnwind targets not proven)'),
                   '??_M@YGXPAXIHP6EX0@Z@Z': (0x6a165b, crt_eh_vector, 'crt_eh_vector_proof: authentic ehvecdtr.obj member, full 99-byte masked equality (its SEH/ArrayUnwind targets not proven)')}
for row in rows + alias_rows:
    unresolved = row.get('unproven_targets', {})
    for symbol, (address, proof, evidence) in runtime_targets.items():
        if proof and proof['status'] == 'PASS' and symbol in unresolved:
            value = unresolved.pop(symbol)
            need(value == hex(address), (symbol, value, hex(address)))
            row['verified_targets'][symbol] = value
            row.setdefault('runtime_target_evidence', {})[symbol] = evidence
    if stack_owner and STACK in unresolved:
        row.setdefault('pending_extent_targets', {})[STACK] = {
            'address': unresolved.pop(STACK), 'recorded_size': STACK_RECORDED, 'proposed_size': STACK_FULL,
            'status': stack_owner['status'], 'proof': 'full_stack_owner_pending_extent',
            'accepted_exact_function': False}
    if not unresolved:
        row.pop('unproven_targets', None)
        row.pop('unproven_note', None)
for symbol, (address, proof, evidence) in runtime_targets.items():
    if proof and proof['status'] == 'PASS':
        ASSERTED.pop(symbol, None)

# The vector-iterator archive symbols are identified, but their SEH scope/callees and larger logical extents
# are not fully validated. Keep those implementation dependencies separate from a completed CRT target proof.
vector_runtime_targets = {
    '??_L@YGXPAXIHP6EX0@Z1@Z': (0x6a1598, 101),
    '??_M@YGXPAXIHP6EX0@Z@Z': (0x6a165b, 99),
}
for row in rows + alias_rows:
    for symbol, (address, archive_span) in vector_runtime_targets.items():
        if symbol in row.get('runtime_target_evidence', {}):
            value = row['verified_targets'].pop(symbol)
            row.setdefault('pending_runtime_targets', {})[symbol] = {
                'address': value, 'entry_symbol_identity_proven': True,
                'recorded_size': len(match.target('2008-06', '%08x' % address)[0]),
                'archive_masked_span_size': archive_span, 'proof': 'crt_eh_vector_proof',
                'accepted_exact_function': False,
                'remaining': 'full extent, SEH scope tables and __SEH_prolog4/__SEH_epilog4/__ArrayUnwind targets'}
            row['runtime_target_evidence'][symbol] = 'authentic archive entry identity and masked span only; full implementation remains in pending_runtime_targets'
# GUID_NULL (helper 00429330): typed SDK declaration + original read-only zero bytes. Only that one data target moves to verified.
if typeinfo_guids and typeinfo_guids['status'] == 'PASS':
    for row in helper_rows:
        if '_GUID_NULL' in row.get('unproven_targets', {}):
            value = row['unproven_targets'].pop('_GUID_NULL')
            need(value == '0x8501ec', value)
            row['verified_targets']['_GUID_NULL'] = value
            row['data_target_evidence'] = {'_GUID_NULL': 'typeinfo_guid_proof.guid_null: typed SDK declaration; original 16 zero bytes in a read-only section'}
            row['unproven_note'] = 'callee bodies (workspace status reporter 00427c20, ATL AtlReportError 004290b0) remain relocation operands only; GUID_NULL data is verified, which does not prove those callees'
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
for symbol, address in typeinfo_helper_pairs:
    reuse['%08x' % address] = 'new: ATL typeinfo helper body (emitted unchanged by the authentic headers; called by GetTI 00404a80 or by a helper; not a vtable slot)'
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
    'data_facts': data_facts, 'asserted_body_not_exact': verify_stack,
    'typeinfo_helper_proof': {
        'status': 'PASS' if typeinfo_guids and crt_eh_vector and not failures else 'FAIL',
        'kind': 'bodies emitted unchanged by the authentic ATL9 RTM headers of the existing class object; no new provider, source, flag or compile trial',
        'new_exact_rows': [{'symbol': s, 'address': '%08x' % a} for s, a in typeinfo_helper_pairs],
        'getti_direct_helpers': [m for m in ('00401760', '00420bb0', '00403af0', '00402f00', '00403da0', '00402d30')],
        'helper_of_helper_rows': ['00401020', '00402370', '00402fb0'],
        'aliases_or_library_reused_rows': [],
        'reuse_note': 'nine additional helper rows for this class; all 56 prior pairs are preserved separately in the regression receipt; no server gain claimed',
        'atl_module_add_term_func': add_term_func,
        'remaining_unproven_getti_targets': ['?_pAtlModule@ATL@@3PAVCAtlModule@1@A 0096c268', '?m_libid@CAtlModule@ATL@@2U_GUID@@A 0096c26c', '?_AtlBaseModule@ATL@@3VCAtlBaseModule@1@A 0097f2a8'],
        'remaining_unproven_helper_targets': ['CRT __SEH_prolog4 006a1fbc, __SEH_epilog4 006a2001, __ArrayUnwind 006a15fd, and the member __sehtable$ scope tables'],
        'provenance': {'class_object': 'RTM header tree (tools/libs/mfc-9.0-rtm) with compiler 21022',
                       'query_interface_library_replay': 'recipe mfc-9.0 source/header tree (tools/libs/mfc-9.0, hashes recorded as SP1-era input) with explicit RTM compiler 21022',
                       'note': 'compiler build and vendor header revision are separate provenance facts; the library input hashes are the vendor-unit hashes and are never replaced by class RTM header hashes'},
        'sdk_guid_proof': typeinfo_guids, 'not_claimed': 'unproven ATL module globals stay open; no always-zero/always-LoadRegTypeLib claim; status stays PARTIAL'},
    'crt_eh_vector_proof': crt_eh_vector, 'termination_helper_analog_proof': add_term_analog,
    'full_stack_owner_pending_extent': stack_owner, 'crt_stack_probe_proof': crt_stack_probes, 'asserted_targets': {k: '%08x' % v for k, v in ASSERTED.items()}, 'failures': failures, 'known_open_bodies': row_failures,
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
        'GetApp_00410fe0': 'exact object row; ole32 CoCreateInstance, CString and AFX state-guard import identities verified; format string and typed GUID data verified; helper 00429330 body exact from WorkspaceSiteError.cpp. GUID_NULL data is verified; its further callees remain open as recorded in helper_rows; import identity does not claim an imported implementation body was reconstructed',
        'guid_definitions': 'IID_IBrowserViewExternal, LIBID_RobloxLib, CLSID_BrowserViewExternal now defined once in native-classes/CBrowserViewExternalGuids.cpp (separate unit: defined in the class unit they constant-fold InterfaceSupportsErrorInfo to 76 bytes vs 78). LIBID_RobloxLib is shared logically with CContent/CWorkspace headers (declared C++-linkage there): linkage identity not reconciled, owners not edited',
        'Enum_bodies': 'EnumConnectionPoints (004100a0, 440) and EnumConnections (004104b0, 436) are masked-exact rows with the single-thread enumerator profile; vtables 0080d790/0080d7f0 verified by RTTI. Their 16 slot bodies (QI/AddRef/Release/Next/Skip/Reset/Clone/deleting destructor) and the four support bodies (CreateInstance x2, ~CComEnumImpl x2) are masked-exact rows: see enum_template_proof. Still open: _pAtlModule 0096c268 as a relocation operand (also in 004100a0/004104b0). _AtlVerifyStackAvailable 00402610: the full 156-byte owner matches (full_stack_owner_pending_extent) but the 93-byte extent is not accepted by the server, so it is NOT an accepted exact function and not a row. __alloca_probe 006a1520 (004100a0) and __alloca_probe_16 006a1560 (00402610, 00404a80) are proven as genuine CRT archive members (crt_stack_probe_proof), separate from native C++ rows',
        'typeinfo_helpers': 'GetTI 00404a80 helper bodies 00401760, 00420bb0, 00403af0, 00402f00, 00403da0, 00402d30 (+ callees 00401020, 00402370, 00402fb0) are masked-exact rows from the existing object; SDK ITypeInfo2/ITypeInfo/IUnknown GUID data verified. CRT ??_L/??_M archive entry identities are proven, with full implementations pending. Callee004038f0 is body/target/EH-proven by the separate typed explicit-lock analog; the authentic RAII body remains non-exact. Still open: _pAtlModule, m_libid, _AtlBaseModule, CRT SEH/ArrayUnwind members (see typeinfo_helper_proof)',
        'constructor_destructor': 'standalone constructor/destructor bodies are inlined into the creator and the deleting destructor and are not rows',
        'stack_helper_extent': 'proposal only (local): shared-layouts/browser-view-external-stack-extent.json, server_extent_status not applied; inventory, bounds.json and scores untouched; callers of 00402610 remain pending-boundary (not wrong codegen)',
        'scope': 'source/object proof only; partial class (ATL module/stack/alloca/static targets open); no server credit, no selection, no build/runtime claim'}}
RECEIPT.parent.mkdir(parents=True, exist_ok=True)
if passed and stack_owner:
    PROPOSAL.write_text(json.dumps({
        'schema': 'local-bounds-proposal-1', 'client': '2008-06', 'address': stack_owner['address'], 'symbol': STACK,
        'old_size': STACK_RECORDED, 'proposed_size': STACK_FULL, 'proposed_end': stack_owner['proposed_end'], 'absorbs': stack_owner['bounds_proof']['absorbs'],
        'tail_proof': stack_owner['bounds_proof'], 'original_156_sha256': stack_owner['original_156_sha256'], 'object_comdat_text_sha256': stack_owner['object']['comdat_text_sha256'],
        'compiler': stack_owner['object']['compiler'], 'relocation_count': 5, 'calling_convention': stack_owner['calling_convention']['return'],
        'server_extent_status': 'not applied', 'proposal': 'local', 'applied': False,
        'not_done': ['bounds.json', 'functions.jsonl', 'scores', 'client metadata', 'roc extents --apply', 'roc analyze', 'server restart'],
        'receipt': 'work/2008-06/shared-layouts/browser-view-external-working.json#full_stack_owner_pending_extent'}, indent=2) + '\n')
(RECEIPT if passed else FAIL).write_text(json.dumps(receipt, indent=2) + '\n')
print('%s native %s: %d exact row(s)%s' % (receipt['status'], C, len(rows), '' if passed else '\n  ' + '\n  '.join(failures)))
sys.exit(0 if passed else 1)
