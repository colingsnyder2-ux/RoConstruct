"""Verify the inactive native RBX::ViewNew::PartChunk / Part / Decal / Texture (2008-06).

Builds (document-swap flags, VS2008 RTM 21022, /fp:fast; native-headers/ViewNew/PartChunk.h is a new path with no donor
counterpart, so it shadows nothing):
  * tests/NativeViewNewPartLayout.cpp      sizeof/offset probes (mov eax, imm32; ret);
  * native-classes/ViewNewPartChunk.cpp    ~PartChunk / ~Decal / ~Texture, their ??_G, PartChunk::getMesh, and the
                                           boost::function managers / Decal invokers of the constructor slots
                                           (needs RenderLib/Material2008.h, hence the Ogre 1.4.5 include path);
  * native-classes/ViewNewPart.cpp         PartChunk::cframe, ~Part (+ ??_G, Listener thunk), Part::onPropertyChanged,
                                           Part::invalidate (native v8datamodel/PartInstance.h),
                                           Decal::onDecalPropertyChanged and Texture::onTexturePropertyChanged
                                           (native v8datamodel/Decal.h, char sDecal[] / sTexture[]). Texture's row is a
                                           block-order near-miss: recorded exact=false, never counted.

Every counted row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the
address the original instruction uses and verified: imports by DLL export name, type descriptors and vtables by
original RTTI names, own symbols by the row proven here, folded inline bodies by their bytes at the folded address,
reflection descriptors by the initializer that constructs them with their name string, and the remaining externals by
the explicit EXTERNAL map (call sites read in the original disassembly). A symbol binds to one address across rows.
Vtables are compared slot by slot from the objects built with the current headers.
Writes work/2008-06/shared-layouts/viewnew-part-working.json. NATIVE_VIEWNEW_PART_DISCOVER=1 lists unbound targets.
"""
import json
import os
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match, rebuild  # noqa: E402
import native_bind as nb  # noqa: E402

R = ROOT / 'rebuild/2008-06'
OUT = nb.OUT
OUT.mkdir(parents=True, exist_ok=True)
OGRE = '/I' + str(ROOT / 'tools/libs/ogre-1.4.5/ogrenew/OgreMain/include')
LAYOUT = R / 'tests/NativeViewNewPartLayout.cpp'
UNITS = {
    'chunk': R / 'native-classes/ViewNewPartChunk.cpp',
    'part': R / 'native-classes/ViewNewPart.cpp',
}
HEADER = R / 'native-headers/ViewNew/PartChunk.h'
DISCOVER = bool(os.environ.get('NATIVE_VIEWNEW_PART_DISCOVER'))

def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + [OGRE, '/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeViewNewPartLayout', LAYOUT, ['/fp:fast'])
OBJ, FLAGS = {}, {'layout': layout_flags}
for key, src in UNITS.items():
    OBJ[key], FLAGS[key] = build('NativeViewNewPart_' + key, src, ['/fp:fast'])

# ---- layout -------------------------------------------------------------------------------------------------------
# Evidence: PartChunk ctor 004eaae0 (stores +0x28 .. +0xd4, see the header), Part ctor 004ebcc0 (+0xd8 vptr, +0xdc),
# Decal ctor 004eae10 (+0xd8 shared_ptr, +0xe0 / +0xf4), the destructors, and the allocation sizes checked below.
raw = layout_obj.read_bytes()
SIZES = {
    'partChunkSize': 0xd8, 'partChunkCoordinateFrame': 0x28, 'partChunkChildAdded': 0x58, 'partChunkChildRemoved': 0x6c,
    'partChunkAncestorChanged': 0x80, 'partChunkPropertyChanged': 0x94, 'partChunkShapePropertyChanged': 0xa8,
    'partChunkPartInstance': 0xbc, 'partChunkMaterial': 0xc4, 'partChunkMaterialInvalid': 0xc8, 'partChunkMesh': 0xcc,
    'partChunkView': 0xd0, 'partChunkSpecialShape': 0xd4, 'scopedConnectionSize': 0x14, 'partSize': 0xf0,
    'partConnection': 0xdc, 'decalSize': 0x108, 'decalDecal': 0xd8, 'decalAncestorChanged': 0xe0,
    'decalPropertyChanged': 0xf4, 'textureSize': 0x108, 'textureDecal': 0xd8, 'textureAncestorChanged': 0xe0,
    'texturePropertyChanged': 0xf4,
}
for fn, size in SIZES.items():
    name_, body_, _ = next(x for x in match.coff_functions(raw) if x[0].startswith('?native' + fn + '@@'))
    assert body_ == b'\xb8' + struct.pack('<I', size) + b'\xc3', (fn, body_.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]

PD = 'PBVPropertyDescriptor@Reflection@3@@'
EXTERNAL = {
    '??3@YAXPAX@Z': 0x6a067a,
    '??1Chunk@RenderBase@RBX@@UAE@XZ': 0x4e81d0,               # chunkCount -= 1 (render-scene recorder row)
    '??1scoped_connection@signals@boost@@QAE@XZ': 0x5954b0,
    '?ReferenceCountedObject_zeroWeakPointers@ReferenceCountedObject@G3D@@QAEXXZ': 0x45ad90,   # evidence name
    '?setPointer@?$ReferenceCountedPointer@VMesh@RenderBase@RBX@@@G3D@@AAEXPAVMesh@RenderBase@RBX@@@Z': 0x598fa0,  # ICF
    '?getCoordinateFrame@PartInstance@RBX@@QBEABVCoordinateFrame@G3D@@XZ': 0x598cb0,              # evidence name
    # ICF-shared Notifier::removeListener body (other recorders bind their instances to the same address)
    '?removeListener@?$Notifier@VPartInstance@RBX@@UCanAggregateChanged@2@@RBX@@QBEXPAV?$Listener@VPartInstance@RBX@@'
    'UCanAggregateChanged@2@@2@@Z': 0x5e5a80,
    # bodies of this family that are not built here (read PartInstance +0x1c8 / +0x1dc / +0x224): call sites
    # 004e6b09 (PartChunk::onPropertyChanged), 004e6b18 (usesMegaTexture), 004e6b23 / 004e73ab (invalidateMesh,
    # releases mesh +0xcc), 004e6b2a / 004e73a3 (invalidateMaterial, releases material +0xc4 and sets +0xc8)
    '?onPropertyChanged@PartChunk@ViewNew@RBX@@MAEX' + PD + 'Z': 0x4e6a30,
    '?usesMegaTexture@Part@ViewNew@RBX@@ABE_NXZ': 0x4e5f80,
    '?invalidateMesh@PartChunk@ViewNew@RBX@@IAEXXZ': 0x4e6740,
    '?invalidateMaterial@PartChunk@ViewNew@RBX@@IAEXXZ': 0x4e68b0,
    # the vector deleting destructor the Listener thunk 004ea460 jumps to: the linker keeps the scalar ??_G body
    '??_EPart@ViewNew@RBX@@UAEPAXI@Z': 0x4ea470,
}
# Reflection descriptors (zero-initialised .bss, constructed by the dynamic initializers named here; checked below by the
# `mov ecx, descriptor` and the pushed name string of each initializer).
DESCRIPTORS = {
    '?prop_Color@PartInstance@RBX@@2V?$PropDescriptor@VPartInstance@RBX@@VColor3@G3D@@@Reflection@2@B': (0x97610c, None, None),
    '?prop_Transparency@PartInstance@RBX@@2V?$PropDescriptor@VPartInstance@RBX@@M@Reflection@2@B': (0x976128, 0x7f46f0, 'Transparency'),
    '?prop_Reflectance@PartInstance@RBX@@2V?$PropDescriptor@VPartInstance@RBX@@M@Reflection@2@B': (0x97601c, 0x7f4750, 'Reflectance'),
    '?prop_Face@FaceInstance@RBX@@2V?$EnumPropDescriptor@VFaceInstance@RBX@@W4NormalId@2@@Reflection@2@B': (0x97b57c, 0x7f7600, 'Face'),
    '?prop_Texture@Decal@RBX@@2V?$PropDescriptor@VDecal@RBX@@VTextureId@2@@Reflection@2@B': (0x975f14, 0x7f4190, 'Texture'),
    '?prop_Specular@Decal@RBX@@2V?$PropDescriptor@VDecal@RBX@@M@Reflection@2@B': (0x975ef8, 0x7f41d0, 'Specular'),
    '?prop_Shiny@Decal@RBX@@2V?$PropDescriptor@VDecal@RBX@@M@Reflection@2@B': (0x975f30, 0x7f4210, 'Shiny'),
    '?prop_StudsPerTileU@Texture@RBX@@2V?$PropDescriptor@VTexture@RBX@@M@Reflection@2@B': (0x975f68, 0x7f4250, 'StudsPerTileU'),
    '?prop_StudsPerTileV@Texture@RBX@@2V?$PropDescriptor@VTexture@RBX@@M@Reflection@2@B': (0x975f4c, 0x7f4290, 'StudsPerTileV'),
}
DATA = {k: v[0] for k, v in DESCRIPTORS.items()}
# Header-inline virtuals the linker folds onto identical bodies elsewhere: compared by bytes at the folded address.
FOLDED = {
    '?cachesShadows@Chunk@RenderBase@RBX@@UBE_NXZ': 0x60a2f0,                    # xor al, al; ret
    '?renderShadows@Chunk@RenderBase@RBX@@UAEXPAVRenderDevice@G3D@@ABVGLight@5@_NM@Z': 0x4e83a0,   # ret 0x10
    '?castsShadows@PartChunk@ViewNew@RBX@@UBE_NXZ': 0x565950,                     # mov al, 1; ret
    '?cullable@PartChunk@ViewNew@RBX@@UBE_NXZ': 0x565950,
}
# Vtable slots whose bodies are not built here (bound to the address the original vtable holds, read below).
SLOT_EXTERNAL = {
    '?setSortValue@Chunk@RenderBase@RBX@@UAEXM@Z': 0x4e5b60,                     # render-scene recorder rows
    '?getSortValue@Chunk@RenderBase@RBX@@UBEMXZ': 0x4e5b70,
    '?getMaterial@Part@ViewNew@RBX@@UAE?AV?$ReferenceCountedPointer@VMaterialBase@RenderBase@RBX@@@G3D@@XZ': 0x4eb190,
    '?updateMesh@Part@ViewNew@RBX@@EAEXXZ': 0x4ef930,
    '?onEvent@Part@ViewNew@RBX@@MAEXPBVPartInstance@3@UCanAggregateChanged@3@@Z': 0x4e6400,
    '?getMaterial@Decal@ViewNew@RBX@@UAE?AV?$ReferenceCountedPointer@VMaterialBase@RenderBase@RBX@@@G3D@@XZ': 0x4ebe70,
    '?updateMesh@Decal@ViewNew@RBX@@EAEXXZ': 0x4f0300,
    '?getMaterial@Texture@ViewNew@RBX@@UAE?AV?$ReferenceCountedPointer@VMaterialBase@RenderBase@RBX@@@G3D@@XZ': 0x4ec070,
    '?updateMesh@Texture@ViewNew@RBX@@EAEXXZ': 0x4f0540,
}
LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
binding = {}


def fm(cls, arg):
    """functor_manager / invoker symbol prefix for the bind_t of `cls` (mf1 with `arg`, or mf0 when arg is None)."""
    if arg is None:
        return 'V?$bind_t@XV?$mf0@XV%s@ViewNew@RBX@@@_mfi@boost@@V?$list1@V?$value@PAV%s@ViewNew@RBX@@@_bi@boost@@@_bi@3@@_bi@boost@@' % (cls, cls)
    return 'V?$bind_t@XV?$mf1@XV%s@ViewNew@RBX@@%s_mfi@boost@@V?$list2@V?$value@PAV%s@ViewNew@RBX@@@_bi@boost@@V?$arg@$00@3@@_bi@3@@_bi@boost@@' % (cls, arg, cls)


SP = 'V?$shared_ptr@VInstance@RBX@@@boost@@@'
PDA = 'PBVPropertyDescriptor@Reflection@3@@'
MANAGE = '?manage@?$functor_manager@'
CHUNK_ROWS = [
    (0x4e8250, '??1PartChunk@ViewNew@RBX@@UAE@XZ'),
    (0x4e8fc0, '??_GPartChunk@ViewNew@RBX@@UAEPAXI@Z'),
    (0x4e6b50, '?getMesh@PartChunk@ViewNew@RBX@@UAE?AV?$ReferenceCountedPointer@VMesh@RenderBase@RBX@@@G3D@@XZ'),
    (0x4e8550, '??1Decal@ViewNew@RBX@@UAE@XZ'),
    (0x4e8fe0, '??_GDecal@ViewNew@RBX@@UAEPAXI@Z'),
    (0x4e85f0, '??1Texture@ViewNew@RBX@@UAE@XZ'),
    (0x4e9000, '??_GTexture@ViewNew@RBX@@UAEPAXI@Z'),
    (0x4e7100, MANAGE + fm('PartChunk', SP)),
    (0x4e7160, MANAGE + fm('PartChunk', PDA)),
    (0x4e71c0, MANAGE + fm('PartChunk', None)),
    (0x4e70c0, MANAGE + fm('Part', None)),
    (0x4e63a0, '?manager@?$functor_manager@' + fm('Part', None) + 'V?$allocator@X@std@@@function@detail@boost@@CAXABT'
               'function_buffer@234@AAT5234@W4functor_manager_operation_type@234@Ufunction_obj_tag@234@@Z'),
    (0x4e7220, MANAGE + fm('Decal', SP)),
    (0x4e7280, MANAGE + fm('Decal', PDA)),
    (0x4e72e0, MANAGE + fm('Texture', SP)),
    (0x4e7340, MANAGE + fm('Texture', PDA)),
    (0x4e80a0, '?invoke@?$void_function_obj_invoker1@' + fm('Decal', SP)),
    (0x4e8140, '?invoke@?$void_function_obj_invoker1@' + fm('Decal', PDA)),
    # mf1::operator() called by the invoker (out of line; the identical PartChunk / Texture copies are folded here)
    (0x4e6300, '??R?$mf1@XVDecal@ViewNew@RBX@@' + SP + '_mfi@boost@@QBEXPAVDecal@ViewNew@RBX@@V?$shared_ptr@VInstance@RBX@@@2@@Z'),
]
PART_ROWS = [
    (0x4e5ff0, '?cframe@PartChunk@ViewNew@RBX@@UAEABVCoordinateFrame@G3D@@XZ'),
    (0x4ea3e0, '??1Part@ViewNew@RBX@@UAE@XZ'),
    (0x4ea470, '??_GPart@ViewNew@RBX@@UAEPAXI@Z'),
    (0x4ea460, '??_EPart@ViewNew@RBX@@WNI@AEPAXI@Z'),      # Listener-base thunk (sub ecx, 0xd8; jmp)
    (0x4e6b00, '?onPropertyChanged@Part@ViewNew@RBX@@MAEX' + PD + 'Z'),
    (0x4e73a0, '?invalidate@Part@ViewNew@RBX@@AAEXXZ'),
    (0x4e6b90, '?onDecalPropertyChanged@Decal@ViewNew@RBX@@IAEX' + PD + 'Z'),
]
# Built from the same part unit with the current headers; counted only when exact.
NEAR_ROWS = [
    (0x4e6bc0, '?onTexturePropertyChanged@Texture@ViewNew@RBX@@IAEX' + PD + 'Z'),
]
NON_EXACT_REASON = {
    '004e6bc0': 'block order: the original places the invalidateMaterial block before the StudsPerTileU/V compares '
                '(Face / StudsPerTile share the invalidateMesh tail); else-if chain, early returns, goto, a combined '
                'condition and two separate StudsPerTileU / StudsPerTileV else-if statements were tried',
}
ROWS = {'chunk': CHUNK_ROWS, 'part': PART_ROWS}


def target_of(address):
    body, refs, _ = match.target('2008-06', '%08x' % address)
    return body, refs


def resolve(obj, rows):
    funcs = match.coff_functions(Path(obj).read_bytes())
    out = []
    for address, key in rows:
        hits = [x for x in funcs if x[0] == key] or [x for x in funcs if x[0].startswith(key) and not LOCAL_EH.match(x[0])]
        if DISCOVER and len(hits) != 1:
            print('UNRESOLVED', '%08x' % address, key[:120], [h[0][:120] for h in hits])
            continue
        assert len(hits) == 1, ('%08x' % address, key, [h[0] for h in hits])
        out.append((address, hits[0][0]))
    return out


def verify(obj, rows, own, strict=True, record=True):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    result = []
    for address, name in rows:
        body, refs = bodies[name]
        target, target_refs = target_of(address)
        exact = match.exact_match(target, target_refs, body, refs)
        entry = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target), 'exact': exact}
        if not exact:
            assert not strict, (name, entry['address'], len(body), len(target))
            result.append(entry)
            continue
        start, section = definitions[name]
        table = sections[section]
        code = raw[table[4] + start:]
        verified, local = {}, set()
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
            offset -= start
            if not 0 <= offset < len(body):
                continue
            symbol = symbols[index][0]
            if kind == 20:
                value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            else:
                value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
            if LOCAL_EH.match(symbol):
                local.add(symbol)
                continue
            hit = original.imported(value)
            if hit is not None:
                assert hit[1] == nb.plain(symbol), (name, symbol, hex(value), hit)
                how = '%s!%s' % hit
            elif symbol.startswith('??_R0') and symbol.endswith('@8'):
                rtti = original.string(value + 8)
                assert rtti == '.' + symbol[5:-2], (name, symbol, hex(value), rtti)
                how = 'RTTI %s' % rtti
            elif symbol.startswith('??_7'):
                rtti, at = original.vtable_class(value)
                cls = symbol[4:symbol.index('@@6B') + 2]
                assert rtti == '.?AV' + cls, (name, symbol, hex(value), rtti)
                how = 'vtable RTTI %s offset %#x' % (rtti, at)
            elif symbol in own:
                assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
                how = 'own row'
            elif symbol in DATA:
                assert DATA[symbol] == value, (name, symbol, hex(value))
                how = 'descriptor (initializer checked)'
            elif symbol in EXTERNAL:
                assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
                how = 'external' + (' (evidence name)' if names.get(value, '') == symbol else '')
            else:
                UNBOUND.append("    %r: %#x,   # %s in %s" % (symbol, value, names.get(value, '')[:60], name[:60]))
                continue
            if record:
                prev = binding.setdefault(symbol, (value, name))
                assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
            verified[symbol] = '%s (%s)' % (hex(value), how)
        entry.update({'verified_targets': verified, 'local': sorted(local)})
        result.append(entry)
    return result


resolved = {k: resolve(OBJ[k], rows) for k, rows in ROWS.items()}
own = {}
for rows in resolved.values():
    for address, name in rows:
        own.setdefault(name, address)
groups = {k: verify(OBJ[k], rows, own, strict=not DISCOVER) for k, rows in resolved.items()}
near = verify(OBJ['part'], resolve(OBJ['part'], NEAR_ROWS), own, strict=False)
groups['part'] += [r for r in near if r['exact']]
pending = [dict(r, reason=NON_EXACT_REASON[r['address']]) for r in near if not r['exact']]
if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for g in list(groups.values()) + [pending]:
        for r in g:
            if not r['exact']:
                print('NOT EXACT', r['address'], r['symbol'][:110], r['size'], r['target_size'])
    sys.exit(0)
assert not UNBOUND, '\n'.join(UNBOUND)

# ---- evidence for the named externals and descriptors ---------------------------------------------------------------


def body_of(address):
    return match.target('2008-06', '%08x' % address)[0]


assert struct.pack('<I', 0x826ec4) in body_of(0x4e8250)          # ~PartChunk stores the PartChunk vtable first
assert b'\x8b\x8e\xcc\x00\x00\x00' in body_of(0x4e6740)           # invalidateMesh releases mesh +0xcc
assert b'\xc6\x86\xc8\x00\x00\x00\x01' in body_of(0x4e68b0)       # invalidateMaterial sets materialInvalid +0xc8
assert b'\x8b\x89\xd4\x00\x00\x00' in body_of(0x4e5f80) or b'\x83\xb9\xd4\x00\x00\x00\x00' in body_of(0x4e5f80)
for symbol, (address, init, label) in DESCRIPTORS.items():
    if init is None:
        continue
    body = body_of(init)
    assert b'\xb9' + struct.pack('<I', address) in body, (symbol, hex(init))       # mov ecx, descriptor
    pushes = [struct.unpack_from('<I', body, i + 1)[0] for i in range(len(body) - 4) if body[i] == 0x68]
    assert any(original.data(p, len(label) + 1) == label.encode() + b'\0' for p in pushes if p > 0x800000), (symbol, label)
# prop_Color 0097610c is bound by record_native_flag_family.py (0062cdc0) under the same symbol.

# Folded header-inline virtuals: the compiled body equals the original body at the folded address.
folded_checked = set()
for key in ('chunk', 'part'):
    for n, b, r in match.coff_functions(OBJ[key].read_bytes()):
        if n in FOLDED:
            t, tr = target_of(FOLDED[n])
            assert match.exact_match(t, tr, b, r) and not r, (n, hex(FOLDED[n]))
            folded_checked.add(n)
assert folded_checked == set(FOLDED), set(FOLDED) - folded_checked

# ---- allocation sizes ---------------------------------------------------------------------------------------------


def alloc_before(function, size, callee):
    body = body_of(function)
    at = body.index(b'\x68' + struct.pack('<I', size)) if size > 0x7f else body.index(b'\x6a' + bytes([size]))
    call = body.index(b'\xe8', at)
    while (function + call + 5 + struct.unpack_from('<i', body, call + 1)[0]) & 0xffffffff != callee:
        call = body.index(b'\xe8', call + 1)
    return at


alloc_before(0x4db7c0, 0xf0, 0x4ebcc0)     # new Part
alloc_before(0x4db7c0, 0x108, 0x4eafd0)    # new Texture (first 0x108 push)
assert body_of(0x4db7c0).count(b'\x68\x08\x01\x00\x00') == 2    # Texture and Decal both allocate 0x108
assert (0x4db9b3 + 5 + struct.unpack_from('<i', body_of(0x4db7c0), 0x4db9b3 - 0x4db7c0 + 1)[0]) & 0xffffffff == 0x4eae10

# ---- vtables from the objects built with the current headers, slot by slot -----------------------------------------
slot_names = {}
for table_ in (own, FOLDED, EXTERNAL, SLOT_EXTERNAL):
    for k, v in table_.items():
        slot_names.setdefault(k, v)


def compiled_vtable(obj, symbol):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    start, section = definitions[symbol]
    table = sections[section]
    slots = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if offset >= start:
            slots[(offset - start) // 4] = symbols[index][0]
    return [slots[i] for i in range(len(slots))]


def check_vtable(obj, symbol, address):
    out, bad = [], []
    for i, slot in enumerate(compiled_vtable(obj, symbol)):
        value = d(address + 4 * i)
        if slot.startswith('??_E') and '??_G' + slot[4:] in slot_names:
            expect, how = slot_names['??_G' + slot[4:]], 'bound (??_G)'
        elif slot == '__purecall':
            hit = original.imported(value)
            expect, how = (value if hit is not None and hit[1] == '_purecall' else None), 'import _purecall'
        else:
            expect, how = slot_names.get(slot), ('slot external' if slot in SLOT_EXTERNAL else 'bound')
        ok = expect == value
        out.append({'slot': i, 'symbol': slot, 'original': '%08x' % value, 'ok': ok, 'how': how})
        if not ok:
            bad.append((i, slot, hex(value)))
    assert not bad, (symbol, bad)
    return out


vt = {}
for key, cls, symbol, address, count in (
        ('chunk', 'PartChunk@ViewNew@RBX', '??_7PartChunk@ViewNew@RBX@@6B@', 0x826ec4, 12),
        ('chunk', 'Decal@ViewNew@RBX', '??_7Decal@ViewNew@RBX@@6B@', 0x826ef8, 12),
        ('chunk', 'Texture@ViewNew@RBX', '??_7Texture@ViewNew@RBX@@6B@', 0x826f2c, 12),
        ('part', 'Part@ViewNew@RBX', '??_7Part@ViewNew@RBX@@6BPartChunk@12@@', 0x826f94, 12),
        ('part', 'Part@ViewNew@RBX', '??_7Part@ViewNew@RBX@@6B?$Listener@VPartInstance@RBX@@UCanAggregateChanged@2@@2@@', 0x826f88, 2)):
    rtti, at = original.vtable_class(address)
    assert rtti == '.?AV%s@@' % cls, (cls, rtti)
    vt[symbol] = check_vtable(OBJ[key], symbol, address)
    assert len(vt[symbol]) == count, (symbol, len(vt[symbol]))

# ---- RTTI bases (original) ------------------------------------------------------------------------------------------


def bases(vtable):
    hierarchy = d(d(vtable - 4) + 16)
    out = {}
    for i in range(d(hierarchy + 8)):
        bcd = d(d(hierarchy + 12) + 4 * i)
        out.setdefault(original.string(d(bcd) + 8), struct.unpack('<i', original.data(bcd + 8, 4))[0])
    return out


CHUNK = {'.?AVPartChunk@ViewNew@RBX@@': 0, '.?AVChunk@RenderBase@RBX@@': 0, '.?AVReferenceCountedObject@G3D@@': 0}
assert bases(0x826ec4) == CHUNK
assert bases(0x826ef8) == dict(CHUNK, **{'.?AVDecal@ViewNew@RBX@@': 0})
assert bases(0x826f2c) == dict(CHUNK, **{'.?AVTexture@ViewNew@RBX@@': 0})
assert bases(0x826f94) == dict(CHUNK, **{'.?AVPart@ViewNew@RBX@@': 0,
                                         '.?AV?$Listener@VPartInstance@RBX@@UCanAggregateChanged@2@@RBX@@': 0xd8})

sha = nb.sha
paths = [Path(__file__).resolve(), LAYOUT, HEADER] + list(UNITS.values())
exact = sorted({r['address'] for g in groups.values() for r in g if r['exact']})
groups['pending_or_not_exact'] = pending
PROPOSALS = {
    'v8datamodel/PartInstance.h (native, owner: PartInstance)':
        'PartChunk::invalidateMesh 004e6740 / invalidateMaterial 004e68b0 / onPropertyChanged 004e6a30 and '
        'Part::onEvent / ctor read PartInstance +0x1c8 (int compared with 0: the aggregate / sleeping state passed '
        'to SceneManager::invalidateModel and setSleeping), +0x224 (float, slot 8 setSortValue argument) and +0x1dc '
        '(int == 1 in usesMegaTexture 004e5f80, presumably the part type). The Notifier<PartInstance, '
        'CanAggregateChanged> base is at +0x1a0 (~Part 004ea3e0), which the current header already yields.',
    'PartInstance.h include chain (owner: PartInstance / util)':
        'v8datamodel/PartInstance.h reaches the donor RbxGraphics/TextureProxyBase.h through util/IRenderable.h, so '
        'a unit cannot include both PartInstance.h and RenderLib/Material2008.h (TextureProxyBase2008.h). That is why '
        '~PartChunk (needs the complete MaterialBase) and cframe / ~Part (need PartInstance) sit in two units.',
    'view type (owner: render scene views, RenderLib/View*2008.h)':
        'PartChunk stores the view at +0xd0 and calls view+4 -> SceneManager slot 1 addModel (ctor 004eaae0), slot 4 '
        'setSleeping (Part ctor 004ebcc0), slot 0 invalidateModel (004e6740) and slot 2 (Decal ancestor 004e83b0). '
        'ViewRbxGfx / ViewG3D (RTTI base RBX::ViewBase only) both pass `this` unadjusted and both store the scene '
        'manager at +4 (ViewRbxGfx ctor 004d9ac3). A 2008 declaration of that view member unblocks the four ctors.',
}
receipt = {
    'class': 'RBX::ViewNew::PartChunk / Part / Decal / Texture',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in [layout_obj] + list(OBJ.values())},
    'layout': {k: hex(v) for k, v in SIZES.items()},
    'rows': groups,
    'exact_function_rows': exact,
    'vtables': vt,
    'proposals': PROPOSALS,
    'not_built': {
        '004eaae0/004ebcc0/004eae10/004eafd0': 'PartChunk / Part / Decal / Texture ctors: the view type with the scene '
                                               'manager at +4 is not declared (render-scene views owner)',
        '004e6740/004e68b0/004e6a30/004e5f80/004e6400': 'read PartInstance +0x1c8 / +0x224 / +0x1dc (PartInstance owner)',
        '004eb190/004ebe70/004ec070/004ef930/004f0300/004f0540': 'getMaterial / updateMesh bodies (material factory, '
                                                                 'mesh factories, SpecialShape) not attempted',
    },
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/viewnew-part-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native ViewNew parts: %d distinct function rows exact (%s); %d non-exact rows not counted; '
      'targets and %d vtables verified' % (len(exact), ', '.join('%s %d' % (k, sum(r['exact'] for r in g))
                                                                for k, g in groups.items() if k != 'pending_or_not_exact'),
                                          len(pending), len(vt)))
