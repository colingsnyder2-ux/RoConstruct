"""Verify the inactive native CRenderSettings recovery: method bodies and their call/data targets.

Compiles the settings unit and fullscreen getter with document-swap flags plus /fp:fast (the unit's x87
ordering needs it). Each row must be relocation-masked exact against the original
EXE, then every relocation is bound to the address the original instruction uses:
  * imports: IAT slot / jmp thunk resolves to the same DLL export name;
  * string literals: original bytes equal the literal;
  * ??_7 vtables: RTTI complete-object locator names the same class (3QBDB vs 3PBDB accepted);
  * other symbols: INTERNAL (original call sites / data uses) or OWN (rows proven here).
Every row listed in record_native_render_settings.json must pass; writes
work/2008-06/shared-layouts/render-settings-working.json.
"""
import json, re, struct, sys
from pathlib import Path
import pefile
root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild
import hashlib

SIDE = json.loads(Path(__file__).with_name('record_native_render_settings.json').read_text())
source = root / 'rebuild/2008-06/native-classes/CRenderSettings.cpp'
getter_source = root / 'rebuild/2008-06/native-classes/CRenderSettingsFullscreen.cpp'
getter_obj = root / 'rebuild/2008-06/out/native-layouts/NativeRenderSettingsFullscreen.obj'
fixture = root / 'rebuild/2008-06/tests/NativeRenderSettingsLayout.cpp'
out = root / 'rebuild/2008-06/out/native-layouts'
out.mkdir(parents=True, exist_ok=True)
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')] + ['/fp:fast']
obj = out / 'NativeRenderSettings.obj'
for path, target in [(source, obj), (getter_source, getter_obj), (fixture, out / 'NativeRenderSettingsLayout.obj')]:
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/Fo' + str(target), str(path)], out)
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

T = '$1?sRenderSettings@@3PADA@RBX@@'
# Internal targets, from the original call sites / data uses read in the disassembly (see header notes).
INTERNAL = {
    # External code (named in evidence.json or proven by an existing committed recovery).
    '?setName@Instance@RBX@@UAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': 0x55af90,
    '?raisePropertyChanged@Instance@RBX@@QAEXABVPropertyDescriptor@Reflection@2@@Z': 0x40db00,
    '?videoMemorySize@DXCaps@G3D@@SA_KXZ': 0x476470,
    '?setParent@Instance@RBX@@QAEXPAV12@@Z': 0x55a8f0,
    '?do_lock@recursive_mutex@boost@@AAEXXZ': 0x563090,
    '?do_unlock@recursive_mutex@boost@@AAEXXZ': 0x5630e0,
    '?singleton@GlobalSettings@RBX@@SA?AV?$shared_ptr@VGlobalSettings@RBX@@@boost@@XZ': 0x5690f0,
    '?mutex@GlobalSettings@RBX@@2Vrecursive_mutex@boost@@A': 0x974aa0,
    # Class data used by the constructor/setters (data-initialized; not defined by this unit).
    '?aaSamples@CRenderSettings@@2W4AASamples@1@A': 0x930668,
    '?defaultWindowSize@CRenderSettings@@2VVector2int16@G3D@@A': 0x93066c,
    '?aggregateSize@CRenderSettings@@2HA': 0x942df8,
    '?defaultShadingQuality@CRenderSettings@@2MB': 0x815bc0,
    '?defaultMeshDetail@CRenderSettings@@2MB': 0x815bc8,
    '?sing@?$GlobalSettingsItem@VCRenderSettings@@' + T + '0PAV12@A': 0x96cbec,
    # Property descriptors: object addresses passed as `this` by the dynamic initializers 007ef430..007ef7a0.
    '?prop_graphicsMode@@3V?$EnumPropDescriptor@VCRenderSettings@@W4GraphicsMode@1@@Reflection@RBX@@A': 0x96d35c,
    '?prop_frameRateManager@@3V?$EnumPropDescriptor@VCRenderSettings@@W4FrameRateManagerMode@1@@Reflection@RBX@@A': 0x96d380,
    '?prop_bevels@@3V?$EnumPropDescriptor@VCRenderSettings@@W4BevelMode@1@@Reflection@RBX@@A': 0x96d3a4,
    '?prop_shadow@@3V?$EnumPropDescriptor@VCRenderSettings@@W4ShadowMode@1@@Reflection@RBX@@A': 0x96d3c8,
    '?prop_antialiasing@@3V?$EnumPropDescriptor@VCRenderSettings@@W4AntialiasingMode@1@@Reflection@RBX@@A': 0x96d3ec,
    '?prop_windowSize@@3V?$PropDescriptor@VCRenderSettings@@VVector2int16@G3D@@@Reflection@RBX@@A': 0x96d410,
    '?prop_fullscreenSize@@3V?$PropDescriptor@VCRenderSettings@@VVector2int16@G3D@@@Reflection@RBX@@A': 0x96d42c,
    '?prop_minShadingQuality@@3V?$PropDescriptor@VCRenderSettings@@M@Reflection@RBX@@A': 0x96d448,
    '?prop_maxShadingQuality@@3V?$PropDescriptor@VCRenderSettings@@M@Reflection@RBX@@A': 0x96d464,
    '?prop_minMeshDetail@@3V?$PropDescriptor@VCRenderSettings@@M@Reflection@RBX@@A': 0x96d480,
    '?prop_maxMeshDetail@@3V?$PropDescriptor@VCRenderSettings@@M@Reflection@RBX@@A': 0x96d49c,
    '?prop_aggregateSize@@3V?$PropDescriptor@VCRenderSettings@@H@Reflection@RBX@@A': 0x96d4b8,
    '?prop_aaSamples@@3V?$EnumPropDescriptor@VCRenderSettings@@W4AASamples@1@@Reflection@RBX@@A': 0x96d4d4,
    '?prop_delaySwapBuffer@@3V?$BoundProp@_N$00@Reflection@RBX@@A': 0x96d4f8,
    '?prop_profileName@@3V?$BoundProp@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@$00@Reflection@RBX@@A': 0x96d514,
}
# Static descriptor objects: the obj names them by their C symbol; the address is the `this` the
# initializer passes, proven together with the name/category literals in the same initializer row.
for prop, addr in [('graphicsMode', 0x96d35c), ('frameRateManager', 0x96d380), ('bevels', 0x96d3a4),
                   ('shadow', 0x96d3c8), ('antialiasing', 0x96d3ec), ('windowSize', 0x96d410),
                   ('fullscreenSize', 0x96d42c), ('minShadingQuality', 0x96d448), ('maxShadingQuality', 0x96d464),
                   ('minMeshDetail', 0x96d480), ('maxMeshDetail', 0x96d49c), ('aggregateSize', 0x96d4b8),
                   ('aaSamples', 0x96d4d4), ('delaySwapBuffer', 0x96d4f8), ('profileName', 0x96d514)]:
    INTERNAL['_prop_' + prop] = addr
# Call targets whose bodies are not exact here (shared reflection/GlobalSettings templates differ from
# the 2008 ones): bound by call site plus a check that the original body uses the class-specific
# vtable (RTTI) or literal named here.
CALLSITE = {
    '??0?$GlobalSettingsItem@VCRenderSettings@@' + T + 'IAE@XZ': (0x448120, 'vtable', 0x815e84, 'GlobalSettingsItem@VCRenderSettings'),
    '?classDescriptor@?$Described@VCRenderSettings@@$1?sRenderSettings@@3PADAV?$FactoryProduct@VCRenderSettings@@VItem@GlobalSettings@RBX@@$1?sRenderSettings@@3PADA@RBX@@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ': (0x447980, 'literal', 0x815bd4, b'RenderSettings'),
    '??$singleton@VVector2int16@G3D@@@Type@Reflection@RBX@@SAABV012@XZ': (0x56ced0, 'literal', 0x82f6c8, b'Vector2int16'),
    # boost 1.34.1 shared_count ctor has a try/catch the 2008 build lacks (as for AuthoringSettings 0040c620).
    '??$?0PAVCRenderSettings@@VDeleter@?$Creatable@VInstance@RBX@@@RBX@@@shared_count@detail@boost@@QAE@PAVCRenderSettings@@VDeleter@?$Creatable@VInstance@RBX@@@RBX@@@Z': (0x408d90, 'vtable', 0x80b67c, 'sp_counted_impl_pd@PAVCRenderSettings@@'),
}
for enum, ctor, vt in [('GraphicsMode', 0x448220, 0x8160fc), ('FrameRateManagerMode', 0x4484d0, 0x81614c),
                       ('BevelMode', 0x448660, 0x81619c), ('ShadowMode', 0x448950, 0x8161ec),
                       ('AntialiasingMode', 0x448a30, 0x81623c), ('AASamples', 0x448b40, 0x81628c)]:
    CALLSITE[('??$?0', '@?$EnumPropDescriptor@VCRenderSettings@@W4%s@1@@Reflection@RBX@@QAE@' % enum)] = (ctor, 'vtable', vt, 'EnumPropDescriptor@VCRenderSettings@@W4%s@1@@' % enum)
def callsite_key(symbol):
    for key in CALLSITE:
        if key == symbol or (isinstance(key, tuple) and symbol.startswith(key[0]) and key[1] in symbol):
            return key
    return None
def callsite_ok(symbol, value):
    want, kind, ref, expect = CALLSITE[callsite_key(symbol)]
    if want != value:
        return None
    body, _, _ = match.target('2008-06', '%08x' % want)
    if struct.pack('<I', ref) not in body:
        return None
    if kind == 'vtable':
        locator = struct.unpack('<I', data(ref - 4, 4))[0]
        descriptor = struct.unpack('<I', data(locator + 12, 4))[0]
        rtti = pe.get_string_at_rva(descriptor + 8 - image).decode()
        return '%s (call site; body uses vtable %s RTTI %s)' % (hex(value), hex(ref), rtti) if expect in rtti else None
    return '%s (call site; body pushes literal %r)' % (hex(value), expect) if data(ref, len(expect) + 1) == expect + b'\0' else None

FOLDED = {}
INTERNAL.update({k: int(v, 16) for k, v in SIDE['internal_extra'].items()})
OWN = {}
LOCAL_EH = re.compile(r'^(__ehhandler\$|__unwindfunclet\$|__catch\$|__tryblocktable\$|__unwindtable\$|__ehfuncinfo\$|\$LN\d)')

def vtable_identity(symbol, value):
    cls = symbol[4:symbol.index('@@6B') + 2]
    locator = struct.unpack('<I', data(value - 4, 4))[0]
    descriptor = struct.unpack('<I', data(locator + 12, 4))[0]
    rtti = pe.get_string_at_rva(descriptor + 8 - image).decode()
    if rtti.replace('3QBDB', '3PBDB') != '.?AV' + cls:
        raise AssertionError('vtable %s at %s is %s' % (symbol, hex(value), rtti))
    return '%s (RTTI %s, offset %#x)' % (hex(value), rtti, struct.unpack('<I', data(locator + 4, 4))[0])

raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
getter_bodies = {n: (b, r) for n, b, r in match.coff_functions(getter_obj.read_bytes())}
getter_name = '?getFullscreenSize@CRenderSettings@@QBE?AVVector2int16@G3D@@XZ'
assert getter_name in getter_bodies and not getter_bodies[getter_name][1]
bodies[getter_name] = getter_bodies[getter_name]
def relocations(section):
    table = sections[section]
    return [struct.unpack_from('<IIH', raw, table[5] + 10 * i) for i in range(table[7])]

def original(address, size, raw_range):
    if raw_range:
        t = data(address, size)
        trel = sorted(s - address for s in match._base_relocs('2008-06') if address <= s < address + size)
        return t, trel
    t, trel, _ = match.target('2008-06', '%08x' % address)
    return t, trel

def bind(name, address, target):
    if name == getter_name:
        return {}, [], {}
    start, section = definitions[name]
    body_size = len(bodies[name][0])
    code = raw[sections[section][4] + start:]
    verified, local, bad = {}, set(), {}
    for offset, index, kind in relocations(section):
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
        try:
            hit = imported(value)
        except Exception:
            hit = None
        if hit is not None:
            if hit[1] != plain(symbol):
                bad[symbol] = 'import %s!%s' % hit
            else:
                verified[symbol] = '%s!%s' % hit
        elif symbol.startswith('??_C@'):
            pos, at = definitions[symbol]
            table = sections[at]
            literal = raw[table[4] + pos:table[4] + table[3]].split(b'\0')[0] + b'\0'
            if data(value, len(literal)) == literal:
                verified[symbol] = hex(value)
            else:
                bad[symbol] = hex(value)
        elif symbol.startswith('__real@'):
            raw_hex = bytes.fromhex(symbol[7:])[::-1]
            if data(value, len(raw_hex)) == raw_hex:
                verified[symbol] = '%s (%s)' % (hex(value), symbol)
            else:
                bad[symbol] = hex(value)
        elif symbol in FOLDED:
            want, why = FOLDED[symbol]
            if want == value:
                verified[symbol] = '%s (%s)' % (hex(value), why)
            else:
                bad[symbol] = '%s (folded expected %s)' % (hex(value), hex(want))
        elif symbol.startswith('??_7') and symbol not in INTERNAL:
            try:
                verified[symbol] = vtable_identity(symbol, value)
            except AssertionError as e:
                bad[symbol] = str(e)
        else:
            want = INTERNAL.get(symbol, OWN.get(symbol))
            if want is None and symbol.startswith('??_E'):
                # Vector deleting destructor reference: no array new of the class, so the
                # compiler's weak ??_E resolves to the scalar deleting destructor ??_G.
                want = OWN.get('??_G' + symbol[4:])
            if want == value:
                verified[symbol] = hex(value)
            elif callsite_key(symbol) and callsite_ok(symbol, value):
                verified[symbol] = callsite_ok(symbol, value)
            else:
                bad[symbol] = '%s (expected %s)' % (hex(value), hex(want) if want else 'unknown')
    return verified, sorted(local), bad

ROWS = SIDE['methods']
exact_rows, nonexact = [], []
for row in ROWS:
    name, address, raw_range = row['symbol'], int(row['address'], 16), row.get('raw_range', False)
    if name not in bodies:
        nonexact.append(dict(row, why='symbol not in object')); continue
    body, refs = bodies[name]
    target, trel = original(address, len(body), raw_range)
    if match.exact_match(target, trel, body, refs):
        exact_rows.append((row, target))
    else:
        nonexact.append(dict(row, why='not exact (%d vs %d)' % (len(body), len(target))))
# Fixpoint: tentatively own every exact (symbol, address) whose symbol is unique among live rows.
# A row is disproven when a binding contradicts a known address or a literal/import/vtable check;
# bindings to still-ambiguous symbols are pending. Repeat until nothing changes.
alive = list(exact_rows)
while True:
    addrs = {}
    for row, _ in alive:
        addrs.setdefault(row['symbol'], set()).add(int(row['address'], 16))
    OWN.clear()
    OWN.update({k: next(iter(v)) for k, v in addrs.items() if len(v) == 1})
    keep, disproven, results, pending = [], [], [], []
    for row, target in alive:
        name, address = row['symbol'], int(row['address'], 16)
        verified, local, bad = bind(name, address, target)
        hard = {k: v for k, v in bad.items() if 'expected unknown' not in v}
        if hard:
            disproven.append(dict(row, why='unbound', bad=bad)); continue
        keep.append((row, target))
        if bad:
            pending.append(dict(row, why='pending', bad=bad))
        else:
            results.append({'address': '%08x' % address, 'symbol': name, 'size': len(bodies[name][0]), 'exact': True,
                            'raw_range': row.get('raw_range', False), 'verified_targets': verified, 'local_eh': local})
    nonexact += disproven
    if not disproven:
        break
    alive = keep
nonexact += pending
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
paths = [Path(__file__), Path(__file__).with_name('record_native_render_settings.json'), source, getter_source, fixture,
         root / 'rebuild/2008-06/native-headers/CRenderSettings.h']
if nonexact:
    (root / 'work/2008-06/shared-layouts/render-settings-failed.json').write_text(json.dumps({
        'scope': 'Failed native audit; no class-swap, ABI or runtime acceptance.',
        'flags': flags, 'failures': nonexact, 'verified_methods': results,
        'sources': {str(p.relative_to(root)): sha(p) for p in paths},
        'object_sha256': sha(obj), 'getter_object_sha256': sha(getter_obj),
    }, indent=2) + '\n')
assert not nonexact, nonexact
(root / 'work/2008-06/shared-layouts/render-settings-working.json').write_text(json.dumps({
    'class': 'CRenderSettings', 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)', 'flags': flags,
    'sources': {str(p.relative_to(root)).replace('\\', '/'): sha(p) for p in paths}, 'object_sha256': sha(obj), 'getter_object_sha256': sha(getter_obj),
    'layout': {'size': '0x17c', 'evidence': 'Creatable<Instance>::create<CRenderSettings> 00408ed0 malloc(0x17c); constructor 00448c60, destructor 00448e60, getters/setters; compile-time sizeof/offsetof test'},
    'methods': results,
    'bounds': ['00448e60 (80 bytes) and 00448eb0 (31 bytes) are exact as raw ranges; the current analysis has one 111-byte function at 00448e60 covering both (BOUNDS evidence for the server host)'],
    'open': ['GlobalSettingsItem<CRenderSettings> constructor 00448120 and Described classDescriptor 00447980: original folds the literal "RenderSettings" (const char* const ClassName in shared templates)',
             'EnumPropDescriptor constructors/virtuals and EnumDesc containers: 2008 reflection layout differs from the donor reflection.h/enumconverter.h',
             'boost shared_count<CRenderSettings*> constructor 00408d90: boost 1.34.1 try/catch tail absent in the 2008 build',
             'FactoryProduct base constructor 00448040 and Creator create slot 00408f50 not matched'],
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.'}, indent=2) + '\n')
print('PASS native CRenderSettings: %d exact bodies, targets verified' % len(results))
