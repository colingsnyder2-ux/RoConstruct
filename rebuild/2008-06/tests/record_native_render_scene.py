"""Verify the inactive native RBX::RenderBase scene pieces (2008-06): Chunk (base members), SceneManager /
SimpleSceneManager and the AggregateChunk leaves.

Builds (VS2008 RTM 21022), all from the current native headers (native-headers/RenderLib/{AggregateChunk2008,
SceneManager2008}.h; the *2008.h names never shadow a donor RenderLib header):
  * tests/NativeRenderSceneLayout.cpp      sizeof/offset probes (mov eax, imm32; ret), document-swap flags + /fp:fast;
  * native-classes/SceneManager2008.cpp    document-swap flags (/O2) + /fp:fast: Chunk ctor / dtor / +0x14 accessors,
                                           SceneManager ctor / dtor / ??_G, SimpleSceneManager (invalidateModel and
                                           the empty setSleeping / prerender);
  * native-classes/AggregateChunk2008.cpp  the RenderBase library profile: /Od /Ob0 /GS (frame pointer, no inlining,
                                           EH frames carry the security cookie 00965cc0: every RenderBase body
                                           0053f0d0..005543b0 is compiled that way);
  * native-classes/SceneManagerAggregating2008.cpp  same /Od profile: Bucket ctor / dtor / ??_G and
                                           AggregatingSceneManager::addModel.

Every exact row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified: imports by DLL export name, constants by bytes, vtables by original RTTI
names, own symbols by the row proven here, data by address (each named below with its evidence) and the remaining
externals by the explicit EXTERNAL map (call sites read in the original disassembly). A symbol binds to one address
across all rows. Vtables are compared slot by slot from the objects built with the current headers (never a pending
build). Rows not built here (RenderSceneBase layout / RenderBase::MaterialBase missing) are listed under 'blocked' and are
not counted. Writes work/2008-06/shared-layouts/render-scene-working.json. Set NATIVE_RENDER_SCENE_DISCOVER=1 to list
unbound targets and non-exact rows instead of asserting.
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
LAYOUT = R / 'tests/NativeRenderSceneLayout.cpp'
UNITS = {
    'scene': (R / 'native-classes/SceneManager2008.cpp', ['/fp:fast']),
    'aggregate': (R / 'native-classes/AggregateChunk2008.cpp', ['/Od', '/Ob0', '/GS']),
    'aggregating': (R / 'native-classes/SceneManagerAggregating2008.cpp', ['/Od', '/Ob0', '/GS']),
}
HEADERS = [R / 'native-headers/RenderLib/AggregateChunk2008.h', R / 'native-headers/RenderLib/SceneManager2008.h']
DISCOVER = bool(os.environ.get('NATIVE_RENDER_SCENE_DISCOVER'))


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeRenderSceneLayout', LAYOUT, ['/fp:fast'])
OBJ, FLAGS = {}, {'layout': layout_flags}
for key, (src, extra) in UNITS.items():
    OBJ[key], FLAGS[key] = build('NativeRenderScene_' + key, src, extra)

# ---- layout -------------------------------------------------------------------------------------------------------
# Evidence: Chunk ctor 004e8160 (stores +0x4/+0x8 ReferenceCountedObject, +0xc/+0x10 NULL, +0x14 0.0f, +0x18 the
# float argument, +0x1c G3D::inf(), +0x20 weak-pointer vtable 00826ea0 / +0x24 NULL), dtor 004e81d0 (+0xc/+0x10,
# +0x20); AggregateChunk ctor 00551f30 (+0x28/+0x2c RCP ctors, +0x30 CoordinateFrame, +0x60/+0x61 from slots 3/4,
# +0x68 GLight ctor 00514390, +0xb8 VAR ctor 00489470, +0xd8 / +0xe4 Array ctors, +0xf0 std::vector ctor), new 0x108
# at 0053ffc3; SceneManager ctor 004d6f60 (+0x4); new 8 before the inlined SimpleSceneManager ctor (004d9a8a);
# Bucket new 0x24 (0053f3b9), ctor 00540390 (vector +0xc); BucketKey ctor 0053f200 (+0x0 / +0x1 / +0x4 / +0x8);
# AggregatingSceneManager new 0x68 (004dbcf4), ctor 0053f0d0 (map +0x8, sets +0x28 / +0x48).
raw = layout_obj.read_bytes()
SIZES = {
    'chunkSize': 0x28, 'chunkEntity': 0xc, 'chunkSubEntity': 0x10, 'chunkSortValue': 0x14, 'chunkPolygonOffset': 0x18,
    'chunkRadius': 0x1c, 'chunkAggregate': 0x20, 'aggregateChunkSize': 0x108, 'aggregateMaterial': 0x28,
    'aggregateMesh': 0x2c, 'aggregateCframe': 0x30, 'aggregateCastsShadows': 0x60, 'aggregateCullable': 0x61,
    'aggregateShadowSource': 0x68, 'aggregateShadowVAR': 0xb8, 'aggregateShadowIndexArray': 0xd8,
    'aggregateShadowIndexArray16': 0xe4, 'aggregateComponents': 0xf0, 'sceneManagerSize': 0x8,
    'sceneManagerRenderScene': 0x4, 'simpleSceneManagerSize': 0x8, 'bucketSize': 0x24, 'bucketQueue': 0xc,
    'bucketKeySize': 0xc, 'bucketKeyCullable': 0x1, 'bucketKeyPolygonOffset': 0x4, 'bucketKeyMaterial': 0x8,
    'aggregatingSize': 0x68, 'aggregatingBuckets': 0x8, 'aggregatingInvalidSleeping': 0x28,
    'aggregatingInvalidMoving': 0x48,
}
for fn, size in SIZES.items():
    name_, body_, _ = next(x for x in match.coff_functions(raw) if x[0].startswith('?native' + fn + '@@'))
    assert body_ == b'\xb8' + struct.pack('<I', size) + b'\xc3', (fn, body_.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]

CHUNK_RCP = '?$ReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@'
EXTERNAL = {
    '??3@YAXPAX@Z': 0x6a067a,
    # Ogre::RbxEntity (RTTI .?AVRbxEntity@Ogre@@) unit 0067c890..0067d3d0; called by ~Chunk 004e820a and
    # SimpleSceneManager::invalidateModel 004d7335 (checked below: erases from a std::vector and deletes the argument)
    '?removeSubEntity@RbxEntity@Ogre@@QAEXPAVRbxSubEntity@2@@Z': 0x67d2d0,
    # WeakReferenceCountedPointer<AggregateChunk>::zeroPointer: ICF copy (evidence names the donor Render::Chunk one)
    '?zeroPointer@?$WeakReferenceCountedPointer@VAggregateChunk@RenderBase@RBX@@@G3D@@AAEXXZ': 0x4f0840,
    # ReferenceCountedPointer<Mesh> copy constructor (/Od call in getMesh 0055273a): ICF copy (evidence: TextureProxyBase)
    '??0?$ReferenceCountedPointer@VMesh@RenderBase@RBX@@@G3D@@QAE@ABV01@@Z': 0x4f0820,
    # /Od COMDATs called by the Bucket rows (structure checked below)
    '??0ReferenceCountedObject@G3D@@IAE@XZ': 0x472990,        # stores 0081e1e0, zeroes +0x4 / +0x8
    '??1ReferenceCountedObject@G3D@@UAE@XZ': 0x7accf0,        # stores 0081e1e0 (ICF O2 copy)
    '??0noncopyable@noncopyable_@boost@@IAE@XZ': 0x7188c0,    # mov eax, ecx; ret (ICF; evidence: Kernel::getKernel)
    '??1noncopyable@noncopyable_@boost@@IAE@XZ': 0x47d410,    # ret (ICF)
    '?addToScene@SceneManager@RenderBase@RBX@@IAEXABV?$ReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@@Z': 0x4d7db0,
    # VS2008 <xutility> / <xmemory> helpers shared by every std container of the exe (/Od COMDAT copies the linker
    # kept; bound to the address the original call uses, bodies checked below where they are trivial)
    '??0_Aux_cont@std@@QAE@QBV_Container_base_aux@1@@Z': 0x6f6a20,
    '??0_Container_base_aux@std@@QAE@XZ': 0x7188c0,           # mov eax, ecx; ret (ICF)
    '??1_Container_base_aux@std@@QAE@XZ': 0x47d410,           # ret (ICF)
    '??2@YAPAXIPAX@Z': 0x401670,                              # placement new (evidence name)
    '?allocate@?$allocator@V_Aux_cont@std@@@std@@QAEPAV_Aux_cont@2@I@Z': 0x4034a0,
    '?deallocate@?$allocator@V_Aux_cont@std@@@std@@QAEXPAV_Aux_cont@2@I@Z': 0x4dc3e0,
    # RCP<Chunk> scalar deleting destructor: the linker kept the O2 copy from the ViewRbxGfx unit (72 bytes, checked
    # below: releases the pointer through ReferenceCountedObject_zeroWeakPointers 0045ad90, then operator delete)
    '??_G?$ReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@QAEPAXI@Z': 0x4d76e0,
    '??0bad_alloc@std@@QAE@PBD@Z': 0x402390,                  # evidence name
    '??0length_error@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z': 0x402480,
}
DATA = {
    '?chunkCount@RenderStats@@2HA': 0x97288c,          # ++ in Chunk() 004e81b2, -- in ~Chunk() 004e81f5
    '?i@?1??inf@G3D@@YAABNXZ@4NB': 0x96f018,           # G3D::inf() local static (Chunk ctor 004e8199 / 004e819f)
    '??_B?1??inf@G3D@@YAABNXZ@51': 0x96f020,           # its init guard (004e8181 / 004e8189)
    '___security_cookie': 0x965cc0,                    # /GS cookie (holds the CRT default 0xbb40e64e)
    '__TI3?AVlength_error@std@@': 0x8d0cc0,            # throw info of std::length_error (checked below)
    '__TI2?AVbad_alloc@std@@': 0x8d07d8,               # throw info of std::bad_alloc (checked below)
}
FOLDED = {}
# Rows at shared (ICF) addresses: 00458e90 is a generic `ret 8` body; 004e5b70 is also Block::getRadius (evidence
# name); 004d7350 serves both SceneManager and SimpleSceneManager. Each counts once as a distinct address.
LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
binding = {}

SCENE_ROWS = [
    (0x4e8160, '??0Chunk@RenderBase@RBX@@QAE@M@Z'),
    (0x4e81d0, '??1Chunk@RenderBase@RBX@@UAE@XZ'),
    (0x4e5b60, '?setSortValue@Chunk@RenderBase@RBX@@UAEXM@Z'),
    (0x4e5b70, '?getSortValue@Chunk@RenderBase@RBX@@UBEMXZ'),
    (0x4d6f60, '??0SceneManager@RenderBase@RBX@@IAE@PAVRenderSceneBase@12@@Z'),
    (0x4d6f50, '??1SceneManager@RenderBase@RBX@@UAE@XZ'),
    (0x4d7350, '??_GSceneManager@RenderBase@RBX@@UAEPAXI@Z'),
    (0x4d7350, '??_GSimpleSceneManager@RenderBase@RBX@@UAEPAXI@Z'),
    (0x4d7320, '?invalidateModel@SimpleSceneManager@RenderBase@RBX@@UAEXABV' + CHUNK_RCP + '_N@Z'),
    (0x458e90, '?setSleeping@SimpleSceneManager@RenderBase@RBX@@UAEXABV' + CHUNK_RCP + '_N@Z'),
    (0x458e90, '?prerender@SimpleSceneManager@RenderBase@RBX@@UAEXN@Z'),
]
AGGREGATE_ROWS = [
    (0x5526d0, '?cachesShadows@AggregateChunk@RenderBase@RBX@@UBE_NXZ'),
    (0x552690, '?castsShadows@AggregateChunk@RenderBase@RBX@@UBE_NXZ'),
    (0x5526b0, '?cullable@AggregateChunk@RenderBase@RBX@@UBE_NXZ'),
    (0x552720, '?getMesh@AggregateChunk@RenderBase@RBX@@UAE?AV?$ReferenceCountedPointer@VMesh@RenderBase@RBX@@@G3D@@XZ'),
    (0x552760, '?cframe@AggregateChunk@RenderBase@RBX@@UAEABVCoordinateFrame@G3D@@XZ'),
]
AGGREGATING_ROWS = [
    (0x540390, '??0Bucket@AggregatingSceneManager@RenderBase@RBX@@QAE@XZ'),
    (0x540440, '??1Bucket@AggregatingSceneManager@RenderBase@RBX@@UAE@XZ'),
    (0x540410, '??_GBucket@AggregatingSceneManager@RenderBase@RBX@@UAEPAXI@Z'),
    (0x53f1e0, '?addModel@AggregatingSceneManager@RenderBase@RBX@@UAEXABV' + CHUNK_RCP + '@Z'),
    (0x540560, '??0?$vector@V' + CHUNK_RCP + 'V?$allocator@V' + CHUNK_RCP + '@std@@@std@@QAE@XZ'),
    (0x5405d0, '??1?$vector@V' + CHUNK_RCP + 'V?$allocator@V' + CHUNK_RCP + '@std@@@std@@QAE@XZ'),
    (0x54e310, '??0?$allocator@V' + CHUNK_RCP + '@std@@QAE@XZ'),
    (0x54da40, '??0?$_Vector_val@V' + CHUNK_RCP + 'V?$allocator@V' + CHUNK_RCP + '@std@@@std@@IAE@V?$allocator@V'
               + CHUNK_RCP + '@1@@Z'),
    (0x5411c0, '??1?$_Vector_val@V' + CHUNK_RCP + 'V?$allocator@V' + CHUNK_RCP + '@std@@@std@@QAE@XZ'),
    (0x5530e0, '?_Buy@?$vector@V' + CHUNK_RCP + 'V?$allocator@V' + CHUNK_RCP + '@std@@@std@@IAE_NI@Z'),
    (0x5414d0, '?_Tidy@?$vector@V' + CHUNK_RCP + 'V?$allocator@V' + CHUNK_RCP + '@std@@@std@@IAEXXZ'),
    (0x54ef60, '??0?$_Container_base_aux_alloc_real@V?$allocator@V' + CHUNK_RCP + '@std@@@std@@IAE@V?$allocator@V'
               + CHUNK_RCP + '@1@@Z'),
    (0x553220, '??0?$allocator@V' + CHUNK_RCP + '@std@@QAE@ABV01@@Z'),
    (0x541580, '??1?$_Container_base_aux_alloc_real@V?$allocator@V' + CHUNK_RCP + '@std@@@std@@IAE@XZ'),
    (0x5414a0, '?_Destroy@?$vector@V' + CHUNK_RCP + 'V?$allocator@V' + CHUNK_RCP + '@std@@@std@@IAEXPAV' + CHUNK_RCP
               + '0@Z'),
    (0x553270, '?_Xlen@?$vector@V' + CHUNK_RCP + 'V?$allocator@V' + CHUNK_RCP + '@std@@@std@@KAXXZ'),
    (0x542de0, '?allocate@?$allocator@V' + CHUNK_RCP + '@std@@QAEPAV' + CHUNK_RCP + 'I@Z'),
    (0x543610, '?deallocate@?$allocator@V' + CHUNK_RCP + '@std@@QAEXPAV' + CHUNK_RCP + 'I@Z'),
    (0x542a30, '?max_size@?$vector@V' + CHUNK_RCP + 'V?$allocator@V' + CHUNK_RCP + '@std@@@std@@QBEIXZ'),
    (0x553220, '??$?0V' + CHUNK_RCP + '@?$allocator@V_Aux_cont@std@@@std@@QAE@ABV?$allocator@V' + CHUNK_RCP + '@1@@Z'),
    (0x546070, '??$_Allocate@V' + CHUNK_RCP + '@std@@YAPAV' + CHUNK_RCP + 'IPAV12@@Z'),
    (0x545f10, '??$_Destroy_range@V?$allocator@V' + CHUNK_RCP + '@std@@@std@@YAXPAV' + CHUNK_RCP
               + '0AAV?$allocator@V' + CHUNK_RCP + '@0@@Z'),
    (0x5446f0, '?max_size@?$allocator@V' + CHUNK_RCP + '@std@@QBEIXZ'),
    (0x5469b0, '??$_Destroy_range@V?$allocator@V' + CHUNK_RCP + '@std@@@std@@YAXPAV' + CHUNK_RCP
               + '0AAV?$allocator@V' + CHUNK_RCP + '@0@U_Nonscalar_ptr_iterator_tag@0@@Z'),
    (0x546900, '??$_Ptr_cat@PAV' + CHUNK_RCP + 'PAV12@@std@@YA?AU_Nonscalar_ptr_iterator_tag@0@AAPAV' + CHUNK_RCP
               + '0@Z'),
    (0x546d20, '?destroy@?$allocator@V' + CHUNK_RCP + '@std@@QAEXPAV' + CHUNK_RCP + '@Z'),
    (0x546fd0, '??$_Destroy@V' + CHUNK_RCP + '@std@@YAXPAV' + CHUNK_RCP + '@Z'),
]
NON_EXACT_ROWS = []
UNPROVEN = {}
# Vtable slots whose bodies are not built here (bound to the address the original vtable holds; see BLOCKED).
SLOT_EXTERNAL = {
    '?addModel@SimpleSceneManager@RenderBase@RBX@@UAEXABV' + CHUNK_RCP + '@Z': 0x4d7db0,
    '?removeModel@SimpleSceneManager@RenderBase@RBX@@UAEXABV' + CHUNK_RCP + '@Z': 0x4d8380,
    '?clear@SimpleSceneManager@RenderBase@RBX@@UAEXXZ': 0x4d8310,
}
BLOCKED = {
    '004d7db0': 'SceneManager::addToScene / SimpleSceneManager::addModel (renderScene->chunkArray.append): needs the '
                'RenderSceneBase layout (chunk array +0x8; the 4-byte member at +0x4 is not derived)',
    '004d8320': 'SceneManager::removeFromScene: same RenderSceneBase blocker',
    '004d8380': 'SimpleSceneManager::removeModel (jmp 004d8320): same RenderSceneBase blocker',
    '004d8310': 'SimpleSceneManager::clear (chunkArray.resize(0, true) 004d7890): same RenderSceneBase blocker',
    '005526e0': 'AggregateChunk::getMaterial: needs the RenderBase::MaterialBase class (RCP copy ctor instantiation)',
    '00551f30': 'AggregateChunk ctor: RenderBase::MaterialBase class (RCP<MaterialBase> member ctor / unwind)',
    '00552160': 'AggregateChunk dtor: RenderBase::MaterialBase class (RCP<MaterialBase> member dtor)',
    '00552780': 'AggregateChunk ??_G: emitted only with the vtable, i.e. with the ctor or dtor above',
    '0053f0d0': 'AggregatingSceneManager ctor: its unwind destroys the map<BucketKey, ...> (BucketKey holds '
                'RCP<MaterialBase>): RenderBase::MaterialBase class',
    '0053f160': 'AggregatingSceneManager dtor: same material blocker',
    '00540300': 'AggregatingSceneManager ??_G: emitted only with the vtable (ctor / dtor above)',
    '0053f200': 'BucketKey ctor (slot 5 getMaterial result into +0x8): RenderBase::MaterialBase class',
}

ROWS = {'scene': SCENE_ROWS, 'aggregate': AGGREGATE_ROWS, 'aggregating': AGGREGATING_ROWS}


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
            _, sym_value, sym_section, _ = symbols[index]
            if kind == 6 and sym_section == section + 1 and symbol.startswith('$LN'):
                # switch-table entry inside the row: the original entry must name the same offset in the function
                assert value == address + sym_value - start, (name, symbol, hex(value), hex(address + sym_value - start))
                local.add('%s: switch target +%#x verified' % (symbol, sym_value - start))
                continue
            if LOCAL_EH.match(symbol):
                local.add(symbol)
                continue
            hit = original.imported(value)
            if hit is not None:
                assert hit[1] == nb.plain(symbol), (name, symbol, hex(value), hit)
                how = '%s!%s' % hit
            elif symbol.startswith('??_C@'):
                pos, at = definitions[symbol]
                literal = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
                assert original.data(value, len(literal)) == literal, (name, symbol, hex(value))
                how = 'literal %r' % literal[:-1].decode()
            elif symbol.startswith('??_R0') and symbol.endswith('@8'):
                rtti = original.string(value + 8)
                assert rtti == '.' + symbol[5:-2], (name, symbol, hex(value), rtti)
                how = 'RTTI %s' % rtti
            elif symbol.startswith('__real@'):
                assert original.data(value, len(symbol[7:]) // 2) == bytes.fromhex(symbol[7:])[::-1], (name, symbol, hex(value))
                how = 'constant %s' % symbol[7:]
            elif symbol.startswith('??_7'):
                rtti, at = original.vtable_class(value)
                cls = symbol[4:symbol.index('@@6B') + 2]
                assert rtti == '.?AV' + cls, (name, symbol, hex(value), rtti)
                how = 'vtable RTTI %s offset %#x' % (rtti, at)
            elif symbol in own:
                assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
                how = 'own row'
            elif symbol in FOLDED:
                assert FOLDED[symbol] == value, (name, symbol, hex(value))
                how = 'folded'
            elif symbol in DATA:
                assert DATA[symbol] == value, (name, symbol, hex(value))
                how = 'data'
            elif symbol in EXTERNAL:
                assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
                how = 'external' + (' (evidence name)' if names.get(value, '') == symbol else '')
            elif symbol in UNPROVEN:
                assert UNPROVEN[symbol] == value, (name, symbol, hex(value))
                how = 'call target of a non-exact row'
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
strict = not DISCOVER
groups = {k: verify(OBJ[k], rows, own, strict) for k, rows in resolved.items()}
non_out = []
if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for g in groups.values():
        for r in g:
            if not r['exact']:
                print('NOT EXACT', r['address'], r['symbol'][:110], r['size'], r['target_size'])
    sys.exit(0)
assert not UNBOUND, '\n'.join(UNBOUND)

# ---- externals named by structure ------------------------------------------------------------------------------------


def body_has(address, imm):
    body, _, _ = match.target('2008-06', '%08x' % address)
    return struct.pack('<I', imm) in body


# 0067d2d0: compares its argument with the std::vector elements, memmoves the tail, and calls the argument's
# virtual deleting destructor with 1 (push 1; call [vtable+0]); the vector sits at +0xd8..+0xe8 of the entity.
body, _, _ = match.target('2008-06', '0067d2d0')
assert b'\x8b\xae\xe8\x00\x00\x00' in body and b'\xff\x15\x50\x28\x80\x00' in body   # mov ebp, [esi+0xe8]; memmove
assert b'\x6a\x01\x8b\xcd\xff\xd2' in body
for address, imm in ((0x472990, 0x81e1e0), (0x7accf0, 0x81e1e0)):
    assert body_has(address, imm), hex(address)                     # ReferenceCountedObject ctor / dtor
assert match.target('2008-06', '007188c0')[0] == bytes.fromhex('8bc1c3')    # trivial ctors (ICF)
assert match.target('2008-06', '0047d410')[0] == bytes.fromhex('c3')        # trivial dtors (ICF)
body, _, _ = match.target('2008-06', '004d76e0')                             # RCP<Chunk>::`scalar deleting dtor'
assert b'\xe8' + struct.pack('<i', 0x45ad90 - 0x4d76fe) in body and b'\xe8' + struct.pack('<i', 0x6a067a - 0x4d771f) in body


def throw_info(address, count, first):
    cta = d(address + 12)
    assert d(cta) == count, (hex(address), d(cta))
    assert original.string(d(d(cta + 4) + 4) + 8) == first, hex(address)


throw_info(0x8d0cc0, 3, '.?AVlength_error@std@@')
throw_info(0x8d07d8, 2, '.?AVbad_alloc@std@@')
assert original.vtable_class(0x826ea0) == ('.?AV?$WeakReferenceCountedPointer@VAggregateChunk@RenderBase@RBX@@@G3D@@', 0)
assert body_has(0x4e8160, 0x826ea0) and body_has(0x4e81d0, 0x826ea0)

# ---- vtables from the objects built with the current headers, slot by slot -----------------------------------------
slot_names = {}
for table_ in (own, FOLDED, EXTERNAL, UNPROVEN, SLOT_EXTERNAL):
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
            expect, how = slot_names.get(slot), 'bound'
        ok = expect == value
        out.append({'slot': i, 'symbol': slot, 'original': '%08x' % value, 'ok': ok, 'how': how})
        if not ok:
            bad.append((i, slot, hex(value)))
    assert not bad, (symbol, bad)
    return out


vt = {}
for key, cls, address, count in (
        ('scene', 'SceneManager@RenderBase@RBX', 0x826b44, 7),
        ('scene', 'SimpleSceneManager@RenderBase@RBX', 0x826b64, 7),
        ('aggregating', 'Bucket@AggregatingSceneManager@RenderBase@RBX', 0x82cef0, 1)):
    assert original.vtable_class(address) == ('.?AV%s@@' % cls, 0), (cls, original.vtable_class(address))
    vt[cls] = check_vtable(OBJ[key], '??_7%s@@6B@' % cls, address)
    assert len(vt[cls]) == count, (cls, len(vt[cls]))

# ---- RTTI bases (original) -------------------------------------------------------------------------------------------


def bases(vtable):
    hierarchy = d(d(vtable - 4) + 16)
    out = {}
    for i in range(d(hierarchy + 8)):
        bcd = d(d(hierarchy + 12) + 4 * i)
        out.setdefault(original.string(d(bcd) + 8), struct.unpack('<i', original.data(bcd + 8, 4))[0])
    return out


RCO = '.?AVReferenceCountedObject@G3D@@'
assert bases(0x826b44) == {'.?AVSceneManager@RenderBase@RBX@@': 0}
assert bases(0x826b64) == {'.?AVSimpleSceneManager@RenderBase@RBX@@': 0, '.?AVSceneManager@RenderBase@RBX@@': 0}
assert bases(0x82cef0) == {'.?AVBucket@AggregatingSceneManager@RenderBase@RBX@@': 0, RCO: 0,
                           '.?AVnoncopyable@noncopyable_@boost@@': 0xc}
assert bases(0x82ced0) == {'.?AVAggregatingSceneManager@RenderBase@RBX@@': 0, '.?AVSceneManager@RenderBase@RBX@@': 0}
assert d(0x82ced0 + 4) == 0x53f1e0                                   # slot 1 addModel (row)
assert bases(0x82d258) == {'.?AVAggregateChunk@RenderBase@RBX@@': 0, '.?AVChunk@RenderBase@RBX@@': 0, RCO: 0}
assert original.vtable_class(0x81e1e0) == (RCO, 0) and body_has(0x4e8160, 0x81e1e0)   # novtable Chunk
# AggregateChunk vtable slots that are rows here (the rest are blocked or out of scope)
for slot, address in ((1, 0x5526d0), (3, 0x552690), (4, 0x5526b0), (6, 0x552720), (7, 0x552760), (8, 0x4e5b60),
                      (9, 0x4e5b70), (0, 0x552780)):
    assert d(0x82d258 + 4 * slot) == address, (slot, hex(d(0x82d258 + 4 * slot)))


def alloc_before(function, size, callee):
    body, _, _ = match.target('2008-06', '%08x' % function)
    at = body.index(b'\x68' + struct.pack('<I', size)) if size > 0x7f else body.index(b'\x6a' + bytes([size]))
    call = body.index(b'\xe8', at)
    while (function + call + 5 + struct.unpack_from('<i', body, call + 1)[0]) & 0xffffffff != callee:
        call = body.index(b'\xe8', call + 1)
    return at


alloc_before(0x53fe10, 0x108, 0x551f30)      # new AggregateChunk
alloc_before(0x4dbbe0, 0x68, 0x53f0d0)       # new AggregatingSceneManager (ViewG3D ctor; size recorded only)
body, _, _ = match.target('2008-06', '004d9990')  # ViewRbxGfx ctor: new 8, inlined SimpleSceneManager ctor
at = body.index(b'\x6a\x08')
assert body.index(struct.pack('<I', 0x826b64)) > at

sha = nb.sha
paths = [Path(__file__).resolve(), LAYOUT] + [u[0] for u in UNITS.values()] + HEADERS
exact = sorted({r['address'] for g in groups.values() for r in g if r['exact']})
groups['not_exact'] = non_out
PROPOSALS = {
    'RenderBase::MaterialBase (owner: material group, RenderLib/Material2008.h)': 'AggregateChunk +0x28 and '
        'BucketKey +0x8 hold G3D::ReferenceCountedPointer<MaterialBase> (RTTI .?AVMaterialBase@RenderBase@RBX@@, '
        'base of Render::Material / RenderNew::Material; getMaterial 005526e0 copies it, chunk slot 5). Once that '
        'header is committed, AggregateChunk2008.h can include it instead of the forward declaration; that '
        'unblocks getMaterial, AggregateChunk ctor 00551f30 / dtor 00552160 / ??_G 00552780 (+ vtable 0082d258), '
        'AggregatingSceneManager ctor 0053f0d0 / dtor 0053f160 / ??_G 00540300 and BucketKey 0053f200.',
    'RenderBase::RenderSceneBase (this group, RenderLib/RenderScene2008.h once +0x4 is derived)': 'vtable 00827424 '
        '(slots: 0 ??_G 00503a30, 1 presetLighting base 005039e0 throws std::exception("shouldn\'t be here"), 2 '
        'setThrottle pure, 3 getShadingQuality +0x24 (folded 00503cb0), 4 getMeshDetail +0x28 (folded 007b76d0), '
        '5 render pure); ctor 00504fd0: chunk array +0x8, Color4 +0x14 = (0.5, 0.5, 1, 1), +0x24 / +0x28 = -1, '
        'RenderStats +0x30 (6 Stopwatch 0x58 + 10 ints = 0x238); size 0x268 (Render::RenderScene members start '
        '+0x268, size 0x500; RenderNew::RenderScene size 0x590). The 4-byte member +0x4 is neither initialised nor '
        'destroyed by the ctor / dtor 005039d0 and no access was found in the View/Render/RenderNew/RenderBase units.',
}
receipt = {
    'class': 'RBX::RenderBase::Chunk (base), SceneManager, SimpleSceneManager, AggregateChunk (leaves)',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in [layout_obj] + list(OBJ.values())},
    'layout': {k: hex(v) for k, v in SIZES.items()},
    'rows': groups,
    'exact_function_rows': exact,
    'blocked': BLOCKED,
    'vtables': vt,
    'proposals': PROPOSALS,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/render-scene-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native render scene: %d distinct function rows exact (%s); %d blocked rows not built; targets and %d '
      'vtables verified' % (len(exact), ', '.join('%s %d' % (k, sum(r['exact'] for r in g))
                                                   for k, g in groups.items() if k != 'not_exact'),
                            len(BLOCKED), len(vt)))
