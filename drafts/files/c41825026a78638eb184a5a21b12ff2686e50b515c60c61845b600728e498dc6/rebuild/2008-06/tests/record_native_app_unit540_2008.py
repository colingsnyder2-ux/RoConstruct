"""Verify the inactive 2008-06 native rows of the application range 00540000..0054c000, and record the unit map of the
range (boundary evidence in the receipt's `unit_map`; rows counted by other receipts are listed there as text).

The range holds two RenderBase library units, both compiled /Od /Ob0 /GS (frame pointer, no inlining, EH frames with
the security cookie 00965cc0), the profile tests/record_native_render_scene.py documents for every RenderBase body:
  * AggregatingSceneManager.cpp, from 0053f0d0 (below the range) to 0054743f: the AggregatingSceneManager / Bucket /
    BucketKey members and the std::map<BucketKey, RCP<Bucket> >, std::set<WeakRCP<Chunk> >, std::vector<RCP<Chunk> >
    and G3D ReferenceCountedPointer / WeakReferenceCountedPointer instantiations they call (Roblox-instantiated
    templates only this unit and the RenderBase AggregateChunk unit reference).
  * Mesh.cpp, from 00547440 past 0054c000: Mesh::aggregate-style statics (00547610, called by the AggregateChunk unit
    00552270 with the components vector +0xf0 and the cframe +0x30), allocVertex / freeVertex, Mesh() 00548570 /
    ~Mesh() 00548a90, Level, ShadowSurface and their STL instantiations. Not built here (see unit_map).

Units built here (VS2008 RTM 21022, document-swap flags with /Od /Ob0 /GS ahead of native-headers and the Ogre 1.4.5
client headers, as record_native_render_scene.py builds them):
  * native-classes/SceneManagerAggregating2008.cpp (render-scene owner, compiled read-only): its members are counted by
    render-scene-working.json; here they are identity roots only.
  * native-classes/AppUnit540_2008AggregatingSceneManager.cpp (this group): BucketKey::operator< 0053f280,
    queueSleepingChunk 0053f340, dequeueSleepingChunk 0053f470, Bucket::dequeueSleepingChunk 0053f4e0 (below the range:
    exact identity roots, not counted here), deconstructAggregate 005400f0 and Bucket::clear 005404b0 (counted).
No new header is created (no shadowing): both units use the read-only RenderLib/SceneManager2008.h,
RenderLib/AggregateChunk2008.h and RenderLib/Material2008.h.

Row identity is proven by a call-graph closure: starting from the member rows (each relocation-masked exact at the
address its evidence names), every REL32 call target of an exact row is bound to the symbol the compiled instruction
references; that symbol's compiled body must be exact at that address, and so on. Each symbol binds to one address;
an address may carry several symbols (identical-code folding), each of whose bodies must be exact there. Every
REL32/DIR32 target of every proven row is then verified: imports by DLL export name, strings by bytes, vtables by
original RTTI names, own (proven) rows, the security cookie / RenderStats statics and the remaining externals by the
explicit EXTERNAL map (call-site evidence in comments). Counted rows are the proven rows inside the range that no other
receipt counts. Writes work/2008-06/shared-layouts/app-unit540-2008-working.json. Set NATIVE_APP_UNIT540_DISCOVER=1 to
list unbound targets instead of asserting.
"""
import glob
import json
import os
import re
import struct
import sys
from collections import deque
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match, rebuild  # noqa: E402
import native_bind as nb  # noqa: E402

R = ROOT / 'rebuild/2008-06'
OUT = nb.OUT / 'app-unit540-2008'
OUT.mkdir(parents=True, exist_ok=True)
OGRE = '/I' + str(ROOT / 'tools/libs/ogre-1.4.5/ogrenew/OgreMain/include')
SOURCES = {
    'aggregating': R / 'native-classes/SceneManagerAggregating2008.cpp',      # render-scene owner, read-only
    'unit': R / 'native-classes/AppUnit540_2008AggregatingSceneManager.cpp',
}
HEADERS = [R / 'native-headers/RenderLib/SceneManager2008.h', R / 'native-headers/RenderLib/AggregateChunk2008.h',
           R / 'native-headers/RenderLib/Material2008.h', R / 'native-headers/ViewNew/RenderBaseMesh.h']
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT540_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit540-2008-working.json'
RANGE = (0x540000, 0x54c000)
PROFILE = ['/Od', '/Ob0', '/GS', OGRE]

# ---- layout probe (generated, build-local): the public offsets the bodies here rely on ------------------------------
LAYOUT = OUT / 'NativeAppUnit540Layout.cpp'
PROBES = {
    # deconstructAggregate 0054012b / 00540143 / 00540208: add eax, 0xf0 after RCP<AggregateChunk>::operator->
    'aggregateComponents': ('offsetof(RBX::RenderBase::AggregateChunk, components)', 0xf0),
    # deconstructAggregate 00540187: add eax, 0x20 (the component's weak aggregate pointer) before operator= 00540530
    'chunkAggregate': ('offsetof(RBX::RenderBase::Chunk, aggregate)', 0x20),
    # AggregateChunk new 0x108 (0053ffc3), Chunk 0x28 (AggregateChunk's first own member +0x28)
    'aggregateChunkSize': ('sizeof(RBX::RenderBase::AggregateChunk)', 0x108),
}
LAYOUT.write_text(
    '// generated by tests/record_native_app_unit540_2008.py: offset / size probes (mov eax, imm32; ret)\n'
    '#include <stddef.h>\n#include "RenderLib/SceneManager2008.h"\n#include "RenderLib/Material2008.h"\n'
    + ''.join('int NativeAppUnit540Layout_%s()\n{\n\treturn %s;\n}\n' % (k, e) for k, (e, _) in PROBES.items()))


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log[-4000:]
    return obj, flags


OBJ, FLAGS = {}, {}
OBJ['layout'], FLAGS['layout'] = build('NativeAppUnit540Layout', LAYOUT, ['/fp:fast', OGRE])
for key, src in SOURCES.items():
    OBJ[key], FLAGS[key] = build('NativeAppUnit540_2008_' + key, src, PROFILE)

layout = {}
for n, b, _ in match.coff_functions(Path(OBJ['layout']).read_bytes()):
    m = re.match(r'\?NativeAppUnit540Layout_(\w+)@@', n)
    if m and m.group(1) in PROBES:
        assert b == b'\xb8' + struct.pack('<I', PROBES[m.group(1)][1]) + b'\xc3', (m.group(1), b.hex())
        layout[m.group(1)] = hex(PROBES[m.group(1)][1])
assert sorted(layout) == sorted(PROBES), sorted(set(PROBES) - set(layout))

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
FUNCTIONS = {int(json.loads(l)['addr'], 16) for l in
             (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines() if l.strip()}

CHUNK_RCP = '?$ReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@'
ASM = 'AggregatingSceneManager@RenderBase@RBX@@'
# ---- identity roots: (address, symbol, which object, evidence) ------------------------------------------------------
ROOTS = [
    # SceneManagerAggregating2008.cpp (render-scene owner; counted by render-scene-working.json, roots only here)
    (0x53f0d0, '??0' + ASM + 'QAE@PAVRenderSceneBase@12@@Z', 'aggregating', 'ctor (ViewG3D ctor 004dbcf4 after new 0x68)'),
    (0x53f160, '??1' + ASM + 'UAE@XZ', 'aggregating', 'dtor (??_G 00540300)'),
    (0x53f1e0, '?addModel@' + ASM + 'UAEXABV' + CHUNK_RCP + '@Z', 'aggregating', 'vtable 0082ced0 slot 1'),
    (0x53f200, '??0BucketKey@' + ASM + 'QAE@ABV' + CHUNK_RCP + '@Z', 'aggregating', 'queueSleepingChunk 0053f37e'),
    (0x53f580, '?removeModel@' + ASM + 'UAEXABV' + CHUNK_RCP + '@Z', 'aggregating', 'vtable 0082ced0 slot 2'),
    (0x53f6a0, '?clear@' + ASM + 'UAEXXZ', 'aggregating', 'vtable 0082ced0 slot 3'),
    (0x53fa50, '?setSleeping@' + ASM + 'UAEXABV' + CHUNK_RCP + '_N@Z', 'aggregating', 'vtable 0082ced0 slot 4'),
    (0x540240, '?invalidateModel@' + ASM + 'UAEXABV' + CHUNK_RCP + '_N@Z', 'aggregating', 'vtable 0082ced0 slot 0'),
    (0x540390, '??0Bucket@' + ASM + 'QAE@XZ', 'aggregating', 'queueSleepingChunk 0053f3d3 after new 0x24'),
    (0x540440, '??1Bucket@' + ASM + 'UAE@XZ', 'aggregating', 'Bucket ??_G 00540410'),
    # AppUnit540_2008AggregatingSceneManager.cpp (this group)
    (0x53f280, '??MBucketKey@' + ASM + 'QBE_NABU0123@@Z', 'unit',
     'std::less<BucketKey> through the map compare (below the range; not counted here)'),
    (0x53f340, '?queueSleepingChunk@' + ASM + 'AAEXABV' + CHUNK_RCP + '@Z', 'unit',
     'setSleeping 0053fa50 / prerender 0053fd3d (below the range; not counted here)'),
    (0x53f470, '?dequeueSleepingChunk@' + ASM + 'AAEXABV' + CHUNK_RCP + '@Z', 'unit',
     'removeModel / setSleeping / prerender 0053fd31 (below the range; not counted here)'),
    (0x53f4e0, '?dequeueSleepingChunk@Bucket@' + ASM + 'QAE_NABV' + CHUNK_RCP + '@Z', 'unit',
     'dequeueSleepingChunk 0053f4c2 (below the range; not counted here)'),
    (0x5400f0, '?deconstructAggregate@' + ASM + 'AAEXV?$ReferenceCountedPointer@VAggregateChunk@RenderBase@RBX@@@G3D@@@Z',
     'unit', 'removeModel / setSleeping / prerender 0053fd23 (by-value RCP copy 005410d0 before the call)'),
    (0x5404b0, '?clear@Bucket@' + ASM + 'QAEXXZ', 'unit', 'AggregatingSceneManager::clear 0053f704'),
]
# ---- externals: the address the original instruction uses (call site in parentheses) --------------------------------
EXTERNAL = {
    # Most of these are out-of-line bodies folded by identical-code folding into a copy compiled elsewhere (an /O2
    # unit's smaller body), so the /Od body compiled here is not exact there: bound by the call site only.
    # The four _Buynode rows are analysed split at their catch funclets (see bounds_evidence).
    '??$swap@D@std@@YAXAAD0@Z': 0x4019e0,  # 00543a35 / 00544b45
    '??0?$ReferenceCountedPointer@VAggregateChunk@RenderBase@RBX@@@G3D@@QAE@PAVAggregateChunk@RenderBase@RBX@@@Z': 0x4e6030,  # 00540173
    '??0?$ReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@QAE@PAVChunk@RenderBase@RBX@@@Z': 0x4e6030,  # 00540f8b
    '??0?$ReferenceCountedPointer@VMaterialBase@RenderBase@RBX@@@G3D@@QAE@ABV01@@Z': 0x4f0820,  # 00542a17
    '??0ReferenceCountedObject@G3D@@IAE@XZ': 0x472990,  # 005403ba
    '??0SceneManager@RenderBase@RBX@@IAE@PAVRenderSceneBase@12@@Z': 0x4d6f60,  # 0053f0fe
    '??0_Aux_cont@std@@QAE@QBV_Container_base_aux@1@@Z': 0x6f6a20,  # 0054efd9
    '??0_Container_base_aux@std@@QAE@XZ': 0x7188c0,  # 0054ef8c
    '??0_Iterator_base_aux@std@@QAE@XZ': 0x4f0810,  # 005446db
    '??0_WeakPtr@G3D@@QAE@XZ': 0x4e5c00,  # 00540fda
    '??0_WeakPtrLinkedList@G3D@@QAE@PAV_WeakPtr@1@PAV01@@Z': 0x5f1270,  # 0054131e / 005427de
    '??0bad_alloc@std@@QAE@PBD@Z': 0x402390,  # 00546098
    '??0length_error@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z': 0x402480,  # 00541fc9 / 00543159 / 005532b2
    '??0noncopyable@noncopyable_@boost@@IAE@XZ': 0x7188c0,  # 005403cc
    '??0out_of_range@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z': 0x4024a0,  # 005436ce / 005447de
    '??1?$ReferenceCountedPointer@VAggregateChunk@RenderBase@RBX@@@G3D@@QAE@XZ': 0x502a70,  # 0053f681 / 0053fbe8 / 00540199
    '??1?$ReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@QAE@XZ': 0x502a70,  # 005401fc / 005428d1
    '??1?$ReferenceCountedPointer@VMaterialBase@RenderBase@RBX@@@G3D@@QAE@XZ': 0x502a70,  # 0054037e
    '??1ReferenceCountedObject@G3D@@UAE@XZ': 0x7accf0,  # 00540492
    '??1SceneManager@RenderBase@RBX@@UAE@XZ': 0x4d6f50,  # 0053f1ca
    '??1_Container_base_aux@std@@QAE@XZ': 0x47d410,  # 005415cb
    '??1_WeakPtr@G3D@@UAE@XZ': 0x4e5b30,  # 00541079
    '??1noncopyable@noncopyable_@boost@@IAE@XZ': 0x47d410,  # 00540483
    '??2@YAPAXIPAX@Z': 0x401670,  # 0054efbd
    '??4?$ReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@QAEABV01@ABV01@@Z': 0x4d7560,  # 00546dc7
    '??8?$ReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@QBE_NABV01@@Z': 0x4d71d0,  # 0054689e
    '??C?$ReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@QBEPAVChunk@RenderBase@RBX@@XZ': 0x71f210,  # 0053f20d / 0053f22a / 0053f248
    '??_G?$ReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@QAEPAXI@Z': 0x4d76e0,  # 00546fd9
    '?ReferenceCountedObject_zeroWeakPointers@ReferenceCountedObject@G3D@@QAEXXZ': 0x45ad90,  # 005425b0
    '?_Buynode@?$_Tree@V?$_Tmap_traits@UBucketKey@AggregatingSceneManager@RenderBase@RBX@@V?$ReferenceCountedPointer@VBucket@AggregatingSceneManager@RenderBase@RBX@@@G3D@@U?$less@UBucketKey@AggregatingSceneManager@RenderBase@RBX@@@std@@V?$allocator@U?$pair@$$CBUBucketKey@AggregatingSceneManager@RenderBase@RBX@@V?$ReferenceCountedPointer@VBucket@AggregatingSceneManager@RenderBase@RBX@@@G3D@@@std@@@8@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@UBucketKey@AggregatingSceneManager@RenderBase@RBX@@V?$ReferenceCountedPointer@VBucket@AggregatingSceneManager@RenderBase@RBX@@@G3D@@U?$less@UBucketKey@AggregatingSceneManager@RenderBase@RBX@@@std@@V?$allocator@U?$pair@$$CBUBucketKey@AggregatingSceneManager@RenderBase@RBX@@V?$ReferenceCountedPointer@VBucket@AggregatingSceneManager@RenderBase@RBX@@@G3D@@@std@@@8@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBUBucketKey@AggregatingSceneManager@RenderBase@RBX@@V?$ReferenceCountedPointer@VBucket@AggregatingSceneManager@RenderBase@RBX@@@G3D@@@2@D@Z': 0x5453e0,  # 00543197
    '?_Buynode@?$_Tree@V?$_Tmap_traits@UBucketKey@AggregatingSceneManager@RenderBase@RBX@@V?$ReferenceCountedPointer@VBucket@AggregatingSceneManager@RenderBase@RBX@@@G3D@@U?$less@UBucketKey@AggregatingSceneManager@RenderBase@RBX@@@std@@V?$allocator@U?$pair@$$CBUBucketKey@AggregatingSceneManager@RenderBase@RBX@@V?$ReferenceCountedPointer@VBucket@AggregatingSceneManager@RenderBase@RBX@@@G3D@@@std@@@8@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@UBucketKey@AggregatingSceneManager@RenderBase@RBX@@V?$ReferenceCountedPointer@VBucket@AggregatingSceneManager@RenderBase@RBX@@@G3D@@U?$less@UBucketKey@AggregatingSceneManager@RenderBase@RBX@@@std@@V?$allocator@U?$pair@$$CBUBucketKey@AggregatingSceneManager@RenderBase@RBX@@V?$ReferenceCountedPointer@VBucket@AggregatingSceneManager@RenderBase@RBX@@@G3D@@@std@@@8@$0A@@std@@@2@XZ': 0x545260,  # 0054309b
    '?_Buynode@?$_Tree@V?$_Tset_traits@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@U?$less@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@@std@@V?$allocator@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@@4@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@U?$less@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@@std@@V?$allocator@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@@4@$0A@@std@@@2@PAU342@00ABV?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@D@Z': 0x5441a0,  # 00542007
    '?_Buynode@?$_Tree@V?$_Tset_traits@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@U?$less@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@@std@@V?$allocator@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@@4@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@U?$less@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@@std@@V?$allocator@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@@4@$0A@@std@@@2@XZ': 0x545550,  # 0054400b
    '?_Getmycont@_Iterator_base_aux@std@@QBEPBV_Container_base_aux@2@XZ': 0x402400,  # 00542734 / 005429b4 / 00544374
    '?_Has_container@_Iterator_base_aux@std@@QBE_NXZ': 0x402410,  # 00540edb / 0054271b / 0054299b
    '?_Same_container@_Iterator_base_aux@std@@QBE_NABV12@@Z': 0x4d71d0,  # 00540eee
    '?_Set_container@_Iterator_base_aux@std@@QAEXQBV_Container_base_aux@2@@Z': 0x4023f0,  # 005444dd / 0054f970
    '?addToQueue@Bucket@AggregatingSceneManager@RenderBase@RBX@@QAEXABV?$ReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@@Z': 0x53f720,  # 0053f445
    '?addToScene@SceneManager@RenderBase@RBX@@IAEXABV?$ReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@@Z': 0x4d7db0,  # 0053f1ef / 005401b4
    '?aggregatedChunkCount@RenderStats@@2HA': 0x972890,  # deconstructAggregate 0054019f / 005401a8 (render-scene: -= in ~AggregateChunk 005521c2)
    '?allocate@?$allocator@V_Aux_cont@std@@@std@@QAEPAV_Aux_cont@2@I@Z': 0x4034a0,  # 0054efaf
    '?clearScene@SceneManager@RenderBase@RBX@@IAEXXZ': 0x4d8310,  # 0053f717
    '?createStrongPtr@?$WeakReferenceCountedPointer@VAggregateChunk@RenderBase@RBX@@@G3D@@QBE?AV?$ReferenceCountedPointer@VAggregateChunk@RenderBase@RBX@@@2@XZ': 0x4e6c00,  # 0053f61c / 0053fb9d
    '?deallocate@?$allocator@V_Aux_cont@std@@@std@@QAEXPAV_Aux_cont@2@I@Z': 0x4dc3e0,  # 005415bc
    '?decrement@AtomicInt32@G3D@@QAEIXZ': 0x45ad80,  # 005425a2
    '?getPointer@?$ReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@QBEPAVChunk@RenderBase@RBX@@XZ': 0x71f210,  # 00540ffc
    '?increment@AtomicInt32@G3D@@QAEXXZ': 0x4672d0,  # 00542628
    '?notNull@?$ReferenceCountedPointer@VAggregateChunk@RenderBase@RBX@@@G3D@@QBE_NXZ': 0x402410,  # 0053f62b / 0053fbac
    '?removeFromScene@SceneManager@RenderBase@RBX@@IAEXABV?$ReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@@Z': 0x4d8320,  # 0053f658 / 0053f666 / 005401f0
    '?setPointer@?$ReferenceCountedPointer@VAggregateChunk@RenderBase@RBX@@@G3D@@AAEXPAVAggregateChunk@RenderBase@RBX@@@Z': 0x598fa0,  # 005410ea
    '?setPointer@?$ReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@AAEXPAVChunk@RenderBase@RBX@@@Z': 0x598fa0,  # 00545e4d
    '?zeroPointer@?$WeakReferenceCountedPointer@VAggregateChunk@RenderBase@RBX@@@G3D@@AAEXXZ': 0x4f0840,  # 005412dc
    '__TI2?AVbad_alloc@std@@': 0x8d07d8,  # 0054609d
    '__TI3?AVlength_error@std@@': 0x8d0cc0,  # 00541fce / 0054315e / 005532b7
    '__TI3?AVout_of_range@std@@': 0x8d0c3c,  # 005436d3 / 005447e3
    '___security_cookie': 0x965cc0,  # 0053f0e3 / 0053f173 / 0053f355
}
DATA_EXTERNAL = {'?aggregatedChunkCount@RenderStats@@2HA', '___security_cookie', '__TI2?AVbad_alloc@std@@',
                 '__TI3?AVlength_error@std@@', '__TI3?AVout_of_range@std@@'}
EXTERNAL = {k: v for k, v in EXTERNAL.items() if v is not None}
USED_EXTERNAL = set()
UNBOUND = []

BODIES = {}
for key in SOURCES:
    raw = Path(OBJ[key]).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    for n, b, r in match.coff_functions(raw):
        start, section = definitions[n]
        table = sections[section]
        rel = []
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
            offset -= start
            if 0 <= offset < len(b):
                rel.append((offset, symbols[index][0], kind))
        BODIES.setdefault(n, (key, b, r, rel))

TARGET = {}


def target_of(address):
    if address not in TARGET:
        body, refs, _ = match.target('2008-06', '%08x' % address)
        TARGET[address] = (body, refs)
    return TARGET[address]


def exact_at(symbol, address):
    if symbol not in BODIES or address not in FUNCTIONS:
        return False
    _, body, refs, _ = BODIES[symbol]
    target, target_refs = target_of(address)
    return match.exact_match(target, target_refs, body, refs)


# ---- call-graph closure ----------------------------------------------------------------------------------------------
proven, aliases, why = {}, {}, {}
NOT_EXACT_REACHED = {}
queue = deque()
for address, symbol, which, evidence in ROOTS:
    assert symbol in BODIES and BODIES[symbol][0] == which, (symbol, which)
    assert exact_at(symbol, address), ('root not exact', '%08x' % address, symbol)
    queue.append((address, symbol, 'root: ' + evidence))
while queue:
    address, symbol, reason = queue.popleft()
    if address in proven:
        if symbol not in aliases[address]:
            # identical-code folding: another symbol reaches the same body; its own compiled body must be exact there
            assert exact_at(symbol, address), ('folded alias not exact', '%08x' % address, symbol, proven[address])
            aliases[address].append(symbol)
        continue
    if not exact_at(symbol, address):
        NOT_EXACT_REACHED.setdefault(address, (symbol, reason))
        continue
    proven[address], aliases[address], why[address] = symbol, [symbol], reason
    _, body, _, rel = BODIES[symbol]
    target, _ = target_of(address)
    for offset, sym, kind in rel:
        if kind == 20:
            value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            if value in FUNCTIONS and sym in BODIES and not nb.LOCAL_EH.match(sym):
                queue.append((value, sym, 'called by %08x' % address))
own = {}
for address, syms in aliases.items():
    for s in syms:
        prev = own.setdefault(s, address)
        assert prev == address, ('one address per symbol', s, hex(prev), hex(address))


# ---- verify every relocation target of every proven row --------------------------------------------------------------
def verify(address, symbol):
    which, body, refs, rel = BODIES[symbol]
    target, target_refs = target_of(address)
    verified, local = {}, set()
    for offset, sym, kind in rel:
        if kind == 20:
            value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        else:
            raw = Path(OBJ[which]).read_bytes()
            sections, symbols, definitions, _ = match._coff_data_index(raw)
            start, section = definitions[symbol]
            code = raw[sections[section][4] + start:]
            value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
        if nb.LOCAL_EH.match(sym):
            local.add(sym)
            continue
        hit = original.imported(value)
        if hit is not None:
            assert hit[1] == nb.plain(sym), (symbol, sym, hex(value), hit)
            how = '%s!%s' % hit
        elif sym.startswith('__real@'):
            assert original.data(value, len(sym[7:]) // 2) == bytes.fromhex(sym[7:])[::-1], (symbol, sym, hex(value))
            how = 'constant %s' % sym[7:]
        elif sym.startswith('??_C@'):
            raw = Path(OBJ[which]).read_bytes()
            sections, symbols, definitions, _ = match._coff_data_index(raw)
            pos, at = definitions[sym]
            literal = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
            assert original.data(value, len(literal)) == literal, (symbol, sym, hex(value))
            how = 'string %r' % literal[:-1].decode('latin-1')
        elif sym.startswith('??_7'):
            rtti, at = original.vtable_class(value)
            cls = sym[4:sym.index('@@6B') + 2]
            assert rtti == '.?AV' + cls, (symbol, sym, hex(value), rtti)
            how = 'vtable RTTI %s offset %#x' % (rtti, at)
        elif sym in own:
            assert own[sym] == value, (symbol, sym, hex(value), hex(own[sym]))
            how = 'own row'
        elif sym in EXTERNAL:
            assert EXTERNAL[sym] == value, (symbol, sym, hex(value), hex(EXTERNAL[sym]))
            how = 'external' + (' (evidence name)' if names.get(value, '') == sym else '')
            USED_EXTERNAL.add(sym)
        else:
            UNBOUND.append("    %r: %#x,   # %s in %s at %08x" % (sym, value, names.get(value, '')[:50], symbol[:50],
                                                                address + offset))
            continue
        verified[sym] = '%s (%s)' % (hex(value), how)
    return {'size': len(body), 'target_size': len(target), 'verified_targets': verified, 'local_eh': sorted(local)}


checked = {a: verify(a, s) for a, s in sorted(proven.items())}
if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for a, (s, r) in sorted(NOT_EXACT_REACHED.items()):
        print('NOT EXACT %08x %s (%s)' % (a, s[:120], r))
    print('PROVEN', len(proven), 'in range', sum(1 for a in proven if RANGE[0] <= a < RANGE[1]))
    print('UNUSED EXTERNAL', sorted(set(EXTERNAL) - USED_EXTERNAL))
    sys.exit(0)
assert not UNBOUND, '\n'.join(UNBOUND)
assert sorted(USED_EXTERNAL) == sorted(EXTERNAL), sorted(set(EXTERNAL) - USED_EXTERNAL)
for symbol, address in EXTERNAL.items():
    assert address in FUNCTIONS or original.imported(address) is not None or symbol in DATA_EXTERNAL, (symbol, hex(address))


# ---- BOUNDS: _Buynode rows analysed split at their catch funclet -----------------------------------------------------
def concatenated_target(parts):
    """Original bytes and relocation offsets of consecutive analysed rows, joined (bounds evidence only)."""
    data, relocs, start = b'', [], parts[0]
    for a in parts:
        body, refs = target_of(a)
        assert start + len(data) == a, ('rows not contiguous', hex(a))
        relocs += [r + len(data) for r in refs]
        data += body
    return data, relocs


BUYNODE_SET = ('?_Buynode@?$_Tree@V?$_Tset_traits@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@U?$less@V'
               '?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@@std@@V?$allocator@V?$WeakReferenceCountedPointer'
               '@VChunk@RenderBase@RBX@@@G3D@@@4@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$WeakReferenceCounted'
               'Pointer@VChunk@RenderBase@RBX@@@G3D@@U?$less@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@@std@@'
               'V?$allocator@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@@4@$0A@@std@@@2@')
BUYNODE_MAP = '?_Buynode@?$_Tree@V?$_Tmap_traits@UBucketKey@' + ASM
BOUNDS = []
for parts, prefix in [((0x5441a0, 0x54423c), BUYNODE_SET), ((0x545260, 0x54533c), BUYNODE_MAP),
                      ((0x5453e0, 0x54547c), BUYNODE_MAP), ((0x545550, 0x54562c), BUYNODE_SET)]:
    hits = sorted(s for s, v in EXTERNAL.items() if v == parts[0] and s.startswith(prefix))
    assert len(hits) == 1, (hex(parts[0]), hits)
    _, body, refs, _ = BODIES[hits[0]]
    data, relocs = concatenated_target(parts)
    ok = len(data) == len(body) and match.exact_match(data, relocs, body, refs)
    assert ok, ('bounds evidence', hex(parts[0]))
    BOUNDS.append({'rows': '%08x + %08x' % parts, 'symbol': hits[0], 'compiled_size': len(body),
                   'joined_size': len(data), 'exact_when_joined': ok,
                   'reason': 'the second analysed row is the catch(...) funclet of _Buynode (delete the node and rethrow, '
                             '__CxxThrowException 006a158c); the compiled body is relocation-masked exact against the '
                             'joined extent. Not counted (extent fix needed; no bounds.json change).'})


# ---- counting rules ------------------------------------------------------------------------------------------------
def counted_elsewhere():
    out = {}
    for path in glob.glob(str(ROOT / 'work/2008-06/shared-layouts/*.json')):
        if Path(path).name == RECEIPT.name:
            continue
        try:
            data = json.loads(Path(path).read_text())
        except Exception:
            continue
        if not isinstance(data, dict):
            continue
        rows = []
        if 'exact_function_rows' in data:
            rows = data['exact_function_rows']
        elif isinstance(data.get('exact_addresses'), list):
            rows = data['exact_addresses']
        elif isinstance(data.get('exact_unique_addresses'), list):
            rows = data['exact_unique_addresses']
        else:
            def walk(o):
                if isinstance(o, list):
                    for e in o:
                        walk(e)
                elif isinstance(o, dict):
                    if 'address' in o and o.get('exact') is True:
                        rows.append(o['address'])
                    else:
                        for v in o.values():
                            walk(v)
            walk(data.get('methods', []))
        if isinstance(rows, dict):
            rows = list(rows)
        for r in rows:
            r = r.get('address', '') if isinstance(r, dict) else str(r)
            m = re.match(r'(?:0x)?([0-9a-fA-F]{6,8})', r)
            if m:
                out.setdefault(int(m.group(1), 16), []).append(Path(path).name)
    return out


elsewhere = counted_elsewhere()
counted = sorted(a for a in proven if RANGE[0] <= a < RANGE[1] and a not in elsewhere)
proven_elsewhere = sorted(a for a in proven if RANGE[0] <= a < RANGE[1] and a in elsewhere)
outside = sorted(a for a in proven if not RANGE[0] <= a < RANGE[1])
range_functions = sorted(a for a in FUNCTIONS if RANGE[0] <= a < RANGE[1])
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if RANGE[0] <= a < RANGE[1]}
assert not set(counted) & set(elsewhere)

ASM_END, MESH_START = 0x547440, 0x547440
rows_out = []
for a in counted:
    rows_out.append(dict({'address': '%08x' % a, 'symbol': proven[a], 'folded_symbols': aliases[a][1:],
                          'identity': why[a], 'exact': True}, **checked[a]))
support_out = []
for a in proven_elsewhere + outside:
    note = ('counted by ' + ', '.join(sorted(set(elsewhere[a])))) if a in elsewhere else (
        'outside the range %08x..%08x' % RANGE)
    support_out.append(dict({'address': '%08x (%s; support row, not counted here)' % (a, note), 'symbol': proven[a],
                             'folded_symbols': aliases[a][1:], 'identity': why[a]}, **checked[a]))

# rows of the AggregatingSceneManager unit in the range that are not proven, with the reason (text, never bare)
NOT_BUILT_REASON = {
    0x53f720: 'Bucket::addToQueue (508 B, below the range): needs the 2008 Chunk / Mesh API it calls (Chunk slot 6 '
              'with two different argument lists 0053f7af / 0053f80c, Mesh 00548f80, static 0053f920)',
    0x53fc00: 'prerender (522 B, below the range): needs a timer 005083d0, constant 00827980 and the global 00942df8',
    0x53fe10: 'Bucket::optimize-shaped member (below the range; new AggregateChunk 0x108 at 0053ffc3): not attempted',
}
unbuilt = []
for a in range_functions:
    if a in proven or a in range_counted:
        continue
    unit = 'AggregatingSceneManager.cpp' if a < ASM_END else 'Mesh.cpp'
    unbuilt.append('%08x %s' % (a, unit))

UNIT_MAP = {
    'RenderBase AggregatingSceneManager.cpp 0053f0d0..0054743f (head below the range)': (
        'AggregatingSceneManager ctor 0053f0d0 (vtable 0082ced0) .. deconstructAggregate 005400f0, invalidateModel '
        '00540240, ??_G 00540300, Bucket ctor / ??_G / dtor 00540390 / 00540410 / 00540440 (vtable 0082cef0), '
        'Bucket::clear 005404b0, then the COMDAT instantiations of std::map<BucketKey, RCP<Bucket> >, '
        'std::set<WeakRCP<Chunk> >, std::vector<RCP<Chunk> > and the G3D RCP / WeakRCP templates for Chunk, '
        'AggregateChunk, Bucket and MaterialBase up to 005473f0 (74 B, ends 0054743a). Identity of each template row '
        'is proven here by the call-graph closure from the member rows. Rows reached only from Bucket::addToQueue '
        '0053f720, prerender 0053fc00 and the 0053fe10 member (not built) and the vtable-only slots (WeakRCP<Chunk> '
        'objectCollected 00541090, the ??_G rows) stay open.'),
    'RenderBase Mesh.cpp 00547440..(past 0054c000)': (
        'Starts with two cdecl statics taking vector<RCP<Chunk> > iterators (00547440, called by 00547610; '
        '00547610 is called by the AggregateChunk unit at 005522b4 with components +0xf0, cframe +0x30 and +0x1c, and '
        'returns the RCP<Mesh> stored at +0x2c), then Mesh initStatics 00547f60 (flag 00973980), allocVertex '
        '00547fc0 / 00548000, freeVertex 00548640, Mesh() 00548570, Level cleanup 005486e0 / ~Level 005489b0, ~Mesh '
        '00548a90 (strings " shd", "RBX rm"), the Ogre sub-mesh builders 005493e0 ("General", "rbxvb") / 00549610 '
        '("RBX makeHWSubMesh: should not be here") / 00549a50 / 0054a920 (called by 007ab0a0), Mesh ??_G 0054a9c0, '
        'ShadowSurface ctor 0054a9f0 / dtor 0054aa80, the sub-mesh name map initialiser 0054ab60 (boost::call_once, '
        'ogre-visual-engine receipt), and the map / vector / G3D::Array instantiations from 0054ab10 to past '
        '0054c000. Not built here: ViewNew/RenderBaseMesh.h (ViewNew owner) declares the Mesh layout with element '
        'types inferred only from _Buy element sizes, and the Ogre sub-mesh classes are undeclared.'),
    'library code': ('none in the range: the STL / G3D / boost bodies are Roblox-instantiated templates of these two '
                     'RenderBase units (element types RBX::RenderBase::*), not separately linked library objects.'),
}
REJECTED = {
    'deconstructAggregate with explicit temporaries `chunk->aggregate = RCP<AggregateChunk>(NULL)` and '
    '`removeFromScene(RCP<Chunk>(aggregate))`': '340 vs 324 B: the functional-cast temporaries are copied through two '
    'extra locals; the implicit conversions (`= NULL`, `removeFromScene(aggregate)`) are exact',
    'BucketKey::operator< with the donor final `if (...) return true; else return false;`': '190 vs 188 B (a second '
    'jmp to the epilogue)',
    'dequeueSleepingChunk as the donor for loop (prefix ++)': '114 vs 112 B; the original is a while loop with ++ at '
    'the end of the body',
}
PROPOSALS = {
    'RenderLib/SceneManager2008.h / AggregateChunk2008.h (render-scene owner), FYI': (
        'No declaration change is needed for the rows counted here. Bucket::addToQueue 0053f720 calls Chunk vtable '
        'slot 6 (+0x18) twice with different argument lists (0053f7af: return slot only; 0053f80c: return slot, a '
        'second pointer and 1.0f), so the 2008 Chunk slot 6 is not the header\'s `getMesh()` alone; derive it before '
        'addToQueue / prerender / 0053fe10 are attempted.'),
    'BOUNDS for the server host (no bounds.json change)': (
        '005441a0+0054423c, 00545260+0054533c, 005453e0+0054547c and 00545550+0054562c are each one _Buynode '
        'function with its catch(...) funclet (bounds_evidence: exact when joined).'),
}

receipt = {
    'class': 'RBX::RenderBase AggregatingSceneManager.cpp unit of the application range 00540000..0054c000 (2008-06), '
             'inactive',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM), /Od /Ob0 /GS (RenderBase library profile) + Ogre 1.4.5 client headers',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): nb.sha(p) for p in
                [Path(__file__).resolve()] + list(SOURCES.values()) + HEADERS},
    'objects': {k: nb.sha(v) for k, v in OBJ.items()},
    'layout': layout,
    'unit_map': UNIT_MAP,
    'range_functions': len(range_functions),
    # Written as 'ADDR counted by RECEIPT' text, never as a quoted bare address: some recorders (local_backpack,
    # viewnew_brick_build, viewnew_part_mesh) treat any '"ADDR"' in another receipt as counted there and drop it.
    'range_rows_counted_by_other_receipts': ['%08x counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()],
    'range_rows_not_built': unbuilt,
    'not_built_reasons': {'%08x' % a + ' (not a row of this range)': r for a, r in NOT_BUILT_REASON.items()},
    'rows': rows_out,
    'support_rows_not_counted': support_out,
    'bounds_evidence': BOUNDS,
    'exact_function_rows': ['%08x' % a for a in counted],
    'rejected': REJECTED,
    'proposals': PROPOSALS,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
text = json.dumps(receipt, indent=2) + '\n'
# no quoted bare address of a row this receipt does not count
quoted = set(re.findall(r'"([0-9a-f]{8})"', text))
assert quoted <= {'%08x' % a for a in counted}, sorted(quoted - {'%08x' % a for a in counted})[:10]
RECEIPT.write_text(text)
print('PASS app-unit540-2008: %d counted exact rows; %d proven support rows (%d counted elsewhere, %d outside the '
      'range); %d bounds joins; %d range rows, %d counted elsewhere, %d not built'
      % (len(counted), len(support_out), len(proven_elsewhere), len(outside), len(BOUNDS), len(range_functions),
         len(range_counted), len(unbuilt)))
print(' '.join('%08x' % a for a in counted))
