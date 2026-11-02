"""Verify the inactive native CInsertObjectDialog: layout, method bodies, call/data targets and class data.

Each listed method must be relocation-masked exact against the original EXE. Every relocation in an
exact body is then bound to the address the original instruction uses and verified:
  * imports: the thunk/IAT slot resolves to the same mfc90 ordinal (by RTM .def name) or DLL export name;
  * internal targets: against the address list below (from the original call sites and names);
  * string literals: the original bytes at that address equal the literal;
  * compiler-generated EH state (handler/funclet symbols) is recorded as local, not as a proof.
Anything else fails the probe. Writes work/2008-06/shared-layouts/insert-object-dialog-working.json.
"""
import hashlib
import json
import re
import struct
import sys
from pathlib import Path

import pefile

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild  # noqa: E402

CLASS = 'CInsertObjectDialog'
out = root / 'rebuild/2008-06/out/native-layouts'
out.mkdir(parents=True, exist_ok=True)
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
source = root / 'rebuild/2008-06/native-classes/CInsertObjectDialog.cpp'
fixture = root / 'rebuild/2008-06/tests/NativeInsertObjectDialogLayout.cpp'
obj = out / 'NativeInsertObjectDialog.obj'
images_source = root / 'rebuild/2008-06/native-classes/CClassImages.cpp'
images_obj = out / 'NativeClassImages.obj'
metadata_source = root / 'rebuild/2008-06/native-classes/MetadataClass.cpp'
metadata_obj = out / 'NativeMetadataClass.obj'
authoring_source = root / 'rebuild/2008-06/native-classes/AuthoringSettings.cpp'
authoring_obj = out / 'NativeAuthoringSettings.obj'
# CClassImages calls the statically linked XTP 11.2.2 bitmap loader: XTP headers need min/max.
xtp_flags = ['/UNOMINMAX', '/I' + str(root / 'tools/libs/xtp-11.2.2/Source'), '/D_XTP_STATICLINK']
for path, target, extra in [(source, obj, []), (fixture, out / 'NativeInsertObjectDialogLayout.obj', []),
                            (images_source, images_obj, xtp_flags),
                            (metadata_source, metadata_obj, []), (authoring_source, authoring_obj, []),
                            (root / 'rebuild/2008-06/tests/NativeMetadataLayout.cpp', out / 'NativeMetadataLayout.obj', [])]:
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + extra + ['/Fo' + str(target), str(path)], out)
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
    """DLL export name for an IAT slot or a jmp [IAT] thunk, else None."""
    slot = value
    if slot not in imports:
        head = data(value, 6)
        if head[:2] != b'\xff\x25':
            return None
        slot = struct.unpack_from('<I', head, 2)[0]
    dll, ordinal, name = imports[slot]
    return dll, (mfc.get(ordinal) if dll == 'mfc90.dll' else name)

def plain(symbol):
    """Object symbol to export spelling: drop __imp_, and C decoration (_name@N)."""
    if symbol.startswith('__imp_'):
        symbol = symbol[6:]
    if symbol.startswith('?'):
        return symbol
    return re.sub(r'@\d+$', '', symbol[1:] if symbol.startswith('_') else symbol)

# Internal targets: original addresses taken from the original call sites, RTTI and existing names.
INTERNAL = {
    '??0CClassImages@@QAE@XZ': 0x413230,
    '??1CClassImages@@UAE@XZ': 0x412f30,
    '??_7CInsertObjectDialog@@6B@': 0x80f48c,
    '??_7CListCtrl@@6B@': 0x80f304,
    '??1?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@QAE@XZ': 0x5a2fe0,
    '??$shared_from@VInstance@RBX@@@RBX@@YA?AV?$shared_ptr@VInstance@RBX@@@boost@@PAVInstance@0@@Z': 0x618a40,
    '??4shared_count@detail@boost@@QAEAAV012@ABV012@@Z': 0x4025b0,
    '?rootDescriptor@ClassDescriptor@Reflection@RBX@@SAAAV123@XZ': 0x40ad20,
    '?addClasses@CInsertObjectDialog@@QAEXABVClassDescriptor@Reflection@RBX@@@Z': 0x4202b0,
    '?compareItems@CInsertObjectDialog@@SGHJJJ@Z': 0x41fbb0,
    '?compare@Name@RBX@@SAHAAV12@0@Z': 0x41faa0,
    '??1CInsertObjectDialog@@UAE@XZ': 0x41ff40,
    '?classCInsertObjectDialog@CInsertObjectDialog@@2UCRuntimeClass@@B': 0x80f2e0,
    '?LoadBitmapFromResource@CXTPImageManagerIcon@@SAPAUHBITMAP__@@PBDPAH@Z': 0x6bc520,
    '??_7CClassImages@@6B@': 0x80e864,
    '??_7CBitmap@@6B@': 0x80e8a0,
    '??1CGdiObject@@UAE@XZ': 0x4111a0,
    '?_ImageList_Add@CComCtlWrapper@@QAEHPAU_IMAGELIST@@PAUHBITMAP__@@1@Z': 0x412fc0,
    '?_ImageList_AddMasked@CComCtlWrapper@@QAEHPAU_IMAGELIST@@PAUHBITMAP__@@K@Z': 0x4130d0,
    '??0runtime_error@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z': 0x409d50,
    '__TI2?AVruntime_error@std@@': 0x8d1bc8,
    '?getImageIndex@Class@Metadata@Reflection@RBX@@QBEHXZ': 0x41fb30,
    '??1Instance@RBX@@UAE@XZ': 0x55a540,
    '?setParent@Instance@RBX@@QAEXPAV12@@Z': 0x55a8f0,
    '?do_lock@recursive_mutex@boost@@AAEXXZ': 0x563090,
    '?do_unlock@recursive_mutex@boost@@AAEXXZ': 0x5630e0,
    '?singleton@GlobalSettings@RBX@@SA?AV?$shared_ptr@VGlobalSettings@RBX@@@boost@@XZ': 0x5690f0,
    '?mutex@GlobalSettings@RBX@@2Vrecursive_mutex@boost@@A': 0x974aa0,
    '?sing@?$GlobalSettingsItem@VAuthoringSettings@@$1?sAuthoringSettings@@3PBDB@RBX@@0PAV12@A': 0x96c39c,
    '??0?$GlobalSettingsItem@VAuthoringSettings@@$1?sAuthoringSettings@@3PBDB@RBX@@IAE@XZ': 0x40ccc0,
    '??$?0PAVAuthoringSettings@@VDeleter@?$Creatable@VInstance@RBX@@@RBX@@@shared_count@detail@boost@@QAE@PAVAuthoringSettings@@VDeleter@?$Creatable@VInstance@RBX@@@RBX@@@Z': 0x40c620,
    '?messageMap@?1??GetThisMessageMap@CInsertObjectDialog@@KGPBUAFX_MSGMAP@@XZ@4U3@B': 0x80f44c,
}
OWN = {}  # exact bodies proven by this probe, filled as rows pass

def vtable_identity(symbol, value):
    """A ??_7 table binds to an original vtable whose RTTI complete-object locator names the same class.
    The binary's template arguments use const char* const (3QBDB) where the shared templates use 3PBDB."""
    cls = symbol[4:symbol.index('@@6B') + 2]
    locator = struct.unpack('<I', data(value - 4, 4))[0]
    descriptor = struct.unpack('<I', data(locator + 12, 4))[0]
    rtti = pe.get_string_at_rva(descriptor + 8 - image).decode()
    assert rtti.replace('3QBDB', '3PBDB') == '.?AV' + cls, (symbol, hex(value), rtti)
    return '%s (RTTI %s, offset %#x)' % (hex(value), rtti, struct.unpack('<I', data(locator + 4, 4))[0])

LOCAL_EH = re.compile(r'^(__ehhandler\$|__unwindfunclet\$|__catch\$|__tryblocktable\$|__unwindtable\$|__ehfuncinfo\$|\$LN\d)')

def load(path):
    global raw, sections, symbols, definitions
    raw = path.read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
load(obj)
def relocations(section):
    table = sections[section]
    return [struct.unpack_from('<IIH', raw, table[5] + 10 * i) for i in range(table[7])]

def bind(name, address):
    """Verify every relocation of an exact body; returns (bindings, local EH symbols)."""
    start, section = definitions[name]
    body_size = next(len(b) for n, b, _ in match.coff_functions(raw) if n == name)
    target, _, _ = match.target('2008-06', '%08x' % address)
    code = raw[sections[section][4] + start:]
    verified, local = {}, set()
    for offset, index, kind in relocations(section):
        offset -= start
        if not 0 <= offset < body_size:
            continue
        symbol, _, symbol_section, _ = symbols[index]
        if kind == 20:  # REL32
            value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        else:          # DIR32: original operand = symbol + addend
            value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
        if LOCAL_EH.match(symbol):
            local.add(symbol)
            continue
        hit = imported(value)
        if hit is not None:
            assert hit[1] == plain(symbol), (name, symbol, hex(value), hit)
            verified[symbol] = '%s!%s' % hit
        elif symbol.startswith('??_C@'):
            pos, at = definitions[symbol]
            table = sections[at]
            literal = raw[table[4] + pos:table[4] + table[3]].split(b'\0')[0] + b'\0'
            assert data(value, len(literal)) == literal, (name, symbol, hex(value))
            verified[symbol] = hex(value)
        elif symbol.startswith('??_R0') and symbol.endswith('@8'):
            rtti = pe.get_string_at_rva(value + 8 - image).decode()
            assert rtti == '.' + symbol[5:-2], (name, symbol, hex(value), rtti)
            verified[symbol] = '%s (%s)' % (hex(value), rtti)
        elif symbol.startswith('??_7') and symbol not in INTERNAL:
            verified[symbol] = vtable_identity(symbol, value)
        else:
            assert INTERNAL.get(symbol, OWN.get(symbol)) == value, (name, symbol, hex(value), symbol_section)
            verified[symbol] = hex(value)
    return verified, sorted(local)

METHODS = [
    ('??0CInsertObjectDialog@@QAE@V?$shared_ptr@VInstance@RBX@@@boost@@PAVCWnd@@@Z', 0x41fe00),
    ('??1CInsertObjectDialog@@UAE@XZ', 0x41ff40),
    ('??_GCInsertObjectDialog@@UAEPAXI@Z', 0x4200f0),
    ('?GetRuntimeClass@CInsertObjectDialog@@UBEPAUCRuntimeClass@@XZ', 0x41f9c0),
    ('?_GetBaseClass@CInsertObjectDialog@@KGPAUCRuntimeClass@@XZ', 0x41f9b0),
    ('?GetMessageMap@CInsertObjectDialog@@MBEPBUAFX_MSGMAP@@XZ', 0x41fcb0),
    ('?OnInitDialog@CInsertObjectDialog@@UAEHXZ', 0x41f9d0),
    ('?OnNMDblclk@CInsertObjectDialog@@QAEXPAUtagNMHDR@@PAJ@Z', 0x41f9f0),
    ('?DoDataExchange@CInsertObjectDialog@@UAEXPAVCDataExchange@@@Z', 0x420580),
    ('?compareItems@CInsertObjectDialog@@SGHJJJ@Z', 0x41fbb0),
    ('??_GCListCtrl@@UAEPAXI@Z', 0x41fa10),
]
bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
rows = []
for name, address in METHODS:
    body, refs = bodies[name]
    target, target_refs, _ = match.target('2008-06', '%08x' % address)
    assert match.exact_match(target, target_refs, body, refs), (name, hex(address), len(body), len(target))
    verified, local = bind(name, address)
    rows.append({'address': '%08x' % address, 'symbol': name, 'size': len(body), 'exact': True,
                 'verified_targets': verified, 'local_eh': local})

IMAGES = [
    ('??0CClassImages@@QAE@XZ', 0x413230),
    ('??1CClassImages@@UAE@XZ', 0x412f30),
    ('??_GCClassImages@@UAEPAXI@Z', 0x413400),
    ('??_GCBitmap@@UAEPAXI@Z', 0x413430),
]
load(images_obj)
image_bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
for name, address in IMAGES:
    body, refs = image_bodies[name]
    target, target_refs, _ = match.target('2008-06', '%08x' % address)
    assert match.exact_match(target, target_refs, body, refs), (name, hex(address), len(body), len(target))
    verified, local = bind(name, address)
    rows.append({'address': '%08x' % address, 'symbol': name, 'size': len(body), 'exact': True,
                 'verified_targets': verified, 'local_eh': local, 'profile': 'XTP headers (/UNOMINMAX /D_XTP_STATICLINK)'})
DEPENDENCIES = [
    (metadata_obj, [('?getImageIndex@Class@Metadata@Reflection@RBX@@QBEHXZ', 0x41fb30)]),
    (authoring_obj, [
        ('?singleton@?$GlobalSettingsItem@VAuthoringSettings@@$1?sAuthoringSettings@@3PBDB@RBX@@SAAAVAuthoringSettings@@XZ', 0x41fcf0),
        ('??0AuthoringSettings@@QAE@XZ', 0x40d140),
        ('??1AuthoringSettings@@UAE@XZ', 0x40a990),
        ('??_GAuthoringSettings@@UAEPAXI@Z', 0x40ab90),
        ('??1?$GlobalSettingsItem@VAuthoringSettings@@$1?sAuthoringSettings@@3PBDB@RBX@@MAE@XZ', 0x40a6c0),
        ('??_G?$GlobalSettingsItem@VAuthoringSettings@@$1?sAuthoringSettings@@3PBDB@RBX@@MAEPAXI@Z', 0x40a7c0),
        ('??1?$FactoryProduct@VAuthoringSettings@@VItem@GlobalSettings@RBX@@$1?sAuthoringSettings@@3PBDB@RBX@@MAE@XZ', 0x40a0e0),
        ('??$create@VAuthoringSettings@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VAuthoringSettings@@@boost@@XZ', 0x40d410),
        ('??$?0VAuthoringSettings@@VDeleter@?$Creatable@VInstance@RBX@@@RBX@@@?$shared_ptr@VAuthoringSettings@@@boost@@QAE@PAVAuthoringSettings@@VDeleter@?$Creatable@VInstance@RBX@@@RBX@@@Z', 0x40c6b0)]),
]
for dependency_obj, methods in DEPENDENCIES:
    OWN.update(methods)
for dependency_obj, methods in DEPENDENCIES:
    load(dependency_obj)
    dependency_bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    for name, address in methods:
        body, refs = dependency_bodies[name]
        target, target_refs, _ = match.target('2008-06', '%08x' % address)
        assert match.exact_match(target, target_refs, body, refs), (name, hex(address), len(body), len(target))
        verified, local = bind(name, address)
        rows.append({'address': '%08x' % address, 'symbol': name, 'size': len(body), 'exact': True,
                     'verified_targets': verified, 'local_eh': local, 'unit': dependency_obj.stem})
load(obj)

# Primary vtable: same slot count, and every slot this object defines binds to the original slot value
# (imports by name, own methods by the exact rows above). Inherited MFC slots resolve through imports.
own = {name: address for name, address in METHODS}
name = '??_7CInsertObjectDialog@@6B@'
start, section = definitions[name]
slots = {(offset - start) // 4: symbols[index][0] for offset, index, _ in relocations(section)
         if start <= offset < start + 91 * 4}
original = struct.unpack('<91I', data(0x80f48c, 91 * 4))
assert len(slots) == 91 and sections[section][3] - start >= 91 * 4
vtable = {}
for slot, symbol in sorted(slots.items()):
    value = original[slot]
    if symbol in own:
        assert own[symbol] == value, (slot, symbol, hex(value))
    else:
        hit = imported(value)
        if hit is not None:
            assert hit[1] == plain(symbol), (slot, symbol, hit)
        else:
            vtable.setdefault('unverified', {})[slot] = (symbol, hex(value))
            continue
    vtable[slot] = symbol
unverified_slots = vtable.pop('unverified', {})

# CRuntimeClass 0080f2e0: name, object size 0xfc, schema 0xffff, no factory, base getter 0041f9b0.
runtime = struct.unpack('<IiIIII', data(0x80f2e0, 24))
assert data(runtime[0], 20) == b'CInsertObjectDialog\0'
assert runtime[1:5] == (0xfc, 0xffff, 0, 0x41f9b0), runtime
# Message map 0080f44c: CDialog base getter thunk and one ON_NOTIFY(NM_DBLCLK, 1000) entry -> 0041f9f0.
base_getter, entries = struct.unpack('<II', data(0x80f44c, 8))
assert imported(base_getter)[1] == '?GetThisMessageMap@CDialog@@KGPBUAFX_MSGMAP@@XZ'
assert struct.unpack('<6I', data(entries, 24)) == (0x4e, 0xfffd, 1000, 1000, 0x3d, 0x41f9f0)
assert struct.unpack('<6I', data(entries + 24, 24)) == (0, 0, 0, 0, 0, 0)

paths = [Path(__file__), source, fixture, images_source, metadata_source, authoring_source,
         root / 'rebuild/2008-06/tests/NativeMetadataLayout.cpp', root / 'rebuild/2008-06/native-headers/reflection/Metadata.h',
         root / 'rebuild/2008-06/native-headers/AuthoringSettings.h', root / 'rebuild/2008-06/native-headers/CInsertObjectDialog.h',
         root / 'rebuild/2008-06/native-headers/CClassImages.h']
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {
    'class': CLASS,
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': flags,
    'original_sha256': sha(root / 'work/2008-06/original-p4-reference/Roblox.exe'),
    'sources': {str(p.relative_to(root)).replace('\\', '/'): sha(p) for p in paths},
    'object_sha256': sha(obj), 'images_object_sha256': sha(images_obj),
    'layout': {'size': '0xfc', 'parent': '0x74', 'instances': '0x7c', 'className': '0x94', 'selected': '0x98',
               'images': '0xa0 (CClassImages, 8 bytes)', 'list': '0xa8 (CListCtrl)',
               'evidence': 'CRuntimeClass 0080f2e0 size; constructor 0041fe00 and destructor 0041ff40 member order; compile-time sizeof/offsetof test'},
    'methods': rows,
    'vtable': {'address': '0080f48c', 'slots': 91, 'verified_slots': len(vtable), 'unverified_slots': unverified_slots},
    'runtime_class': {'address': '0080f2e0', 'size': '0xfc', 'base_getter': '0041f9b0'},
    'message_map': {'address': '0080f44c', 'entries': [{'message': 'WM_NOTIFY', 'code': 'NM_DBLCLK', 'id': 1000, 'handler': '0041f9f0'}]},
    'open': ['addClasses 004202b0: 711 of 713 bytes under the c_str/PCXSTR/compare noinline profile; every call target lines up, the remaining difference is register allocation (descriptor/metadata in esi/edi swapped, getImageIndex/c_str order). Layouts and callees are recovered; parked after the source-shape grid in work/2008-06/shared-layouts/insert-object-dialog-working.json notes',
             'GlobalSettingsItem<AuthoringSettings> constructor 0040ccc0 (258 vs 255): the original folds *ClassName to the literal "Authoring", which needs const char* const template parameters in the shared reflection templates',
             'Bodies of call targets owned by other units (CComCtlWrapper COMDATs 00412fc0/004130d0, CGdiObject destructor 004111a0, XTP LoadBitmapFromResource 006bc520): bound by call site and name only',
             'Name::compare 0041faa0 body (shared util/Name.h)'],
    'scope': 'Inactive. Exact bodies with verified call/data targets for CInsertObjectDialog, CClassImages, Metadata::Class::getImageIndex and the AuthoringSettings singleton/lifetime; addClasses remains open. No active build, swap or credit.',
}
(root / 'work/2008-06/shared-layouts/insert-object-dialog-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native CInsertObjectDialog: %d exact methods, targets verified; %d vtable slots verified' % (len(rows), len(vtable)))
