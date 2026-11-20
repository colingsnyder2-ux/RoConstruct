"""Verify the inactive 2008-06 native rows of the application range 00548000..0054c000, and record the unit map of the
range (boundary evidence in the receipt's `unit_map`; rows counted by other receipts are listed there as text).

The range is the middle of the RenderBase Mesh.cpp unit (00547440 .. past 0054c000), compiled /Od /Ob0 /GS (frame
pointer, no inlining, EH frames with the security cookie 00965cc0), the RenderBase library profile
tests/record_native_render_scene.py and tests/record_native_app_unit540_2008.py document.

Units built here (VS2008 RTM 21022, document-swap flags with /Od /Ob0 /GS ahead of native-headers and the Ogre 1.4.5
client headers):
  * main:    native-classes/AppUnit548Mesh.cpp against the read-only native ViewNew/RenderBaseMesh.h (ViewNew owner):
             ShadowSurface ctor / dtor and the explicitly instantiated template members of this unit. Counted.
  * pending: the same source with NATIVE_APPUNIT548_PENDING, against a generated copy of ViewNew/RenderBaseMesh.h under
             out/native-layouts/app-unit548/pending/ that adds the static vertex pool the 2008 binary proves (see
             PROPOSALS): Mesh() 00548570, initStatics 00547f60, allocVertex 00547fc0 / 00548000, freeVertex 00548640.
             Rows exact only here are recorded exact=false (pending-build-only) and never counted.
No new header is created under native-headers (nothing is shadowed).

Row identity is proven by a call-graph closure from the root rows (each relocation-masked exact at the address its
evidence names): every REL32 call target of an exact row binds to the symbol the compiled instruction references; that
symbol's compiled body must be exact there, and so on. Each symbol binds to one address; an address may carry several
symbols (identical-code folding), each of whose bodies must be exact there. Every REL32/DIR32 target of every proven
row is verified: imports by DLL export name, strings by bytes, vtables by original RTTI names, own (proven) rows, and
the remaining externals by the explicit EXTERNAL map (call-site evidence in comments). Counted rows are the main-build
proven rows inside the range that no other receipt counts. Writes work/2008-06/shared-layouts/app-unit548-working.json.
Set NATIVE_APP_UNIT548_DISCOVER=1 to list unbound targets instead of asserting.
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
OUT = nb.OUT / 'app-unit548'
OUT.mkdir(parents=True, exist_ok=True)
OGRE = '/I' + str(ROOT / 'tools/libs/ogre-1.4.5/ogrenew/OgreMain/include')
SOURCE = R / 'native-classes/AppUnit548Mesh.cpp'
MESH_H = R / 'native-headers/ViewNew/RenderBaseMesh.h'
HEADERS = [MESH_H]
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT548_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit548-working.json'
RANGE = (0x548000, 0x54c000)
PROFILE = ['/Od', '/Ob0', '/GS', OGRE]

# ---- pending header: a generated copy of ViewNew/RenderBaseMesh.h with the proposed static vertex pool ---------------
PENDING_DIR = OUT / 'pending'
(PENDING_DIR / 'ViewNew').mkdir(parents=True, exist_ok=True)
ANCHOR = '\t\t\tstatic void freeVertex(unsigned int index);                               // 00548640\n'
PENDING_DECL = '''
			// NATIVE_APPUNIT548_PENDING proposal (app-unit548 receipt): the static vertex pool of the 2008 Mesh.cpp unit.
			// Public: the ViewNew mesh builders read the arrays directly (004dcaa6 / 004dcab6 / 004e2edf).
			static G3D::MeshAlg::Geometry visibleGeometry;  // 009738f0 (vertexArray, normalArray 009738fc)
			static G3D::Array<G3D::Vector2> texCoordArray;  // 00973934
			static G3D::Array<G3D::Vector3> tangentArray;   // 00973928
			static G3D::Array<int> vertexRefCounts;         // 009738c4
			static G3D::Array<int> freeList;                // 009738ac
			static bool varDirty;                           // 009738a1 (also read by 0045ea5c)
			static bool vertexPoolChanged;                  // 00942ebc (.data, initial 1; RenderScene 007ab54d / 007acb50)
		protected:
			static void initStatics();                      // 00547f60 (Mesh() 005485f5, once)
			int detailIndex(double detail) const;           // 0054aca0 (thiscall, ret 8; levels.size() 0054bf70, iClamp)
		public:
			const G3D::ReferenceCountedPointer<Level> detailLevel(float detail); // 00548f80 (non-const: operator[] 0054ae90)
			static void sendGeometry(const Level* lvl, G3D::RenderDevice* rd);  // 00548fe0 (cdecl, 2 pushes)
			static void endRender(G3D::RenderDevice* rd);                       // 00549030
'''
_mesh_text = MESH_H.read_text()
assert _mesh_text.count(ANCHOR) == 1, 'RenderBaseMesh.h anchor moved'
PENDING_H = PENDING_DIR / 'ViewNew/RenderBaseMesh.h'
PENDING_H.write_text(_mesh_text.replace(ANCHOR, ANCHOR + PENDING_DECL))


def build(name, src, extra=(), first=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(first) + list(extra) + flags[i:] + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log[-4000:]
    return obj, flags


OBJ, FLAGS = {}, {}
OBJ['main'], FLAGS['main'] = build('NativeAppUnit548_main', SOURCE, PROFILE)
OBJ['pending'], FLAGS['pending'] = build('NativeAppUnit548_pending', SOURCE, PROFILE + ['/DNATIVE_APPUNIT548_PENDING'],
                                         ['/I' + str(PENDING_DIR)])

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
FUNCTIONS = {int(json.loads(l)['addr'], 16) for l in
             (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines() if l.strip()}

MESH = 'Mesh@RenderBase@RBX@@'
LEVEL_RCP = '?$ReferenceCountedPointer@VLevel@' + MESH + '@G3D@@'
# ---- identity roots: (address, symbol, evidence) -----------------------------------------------------------------------
ROOTS_MAIN = [
    (0x54a9f0, '??0ShadowSurface@' + MESH + 'QAE@XZ', 'Mesh() 005485c3 on +0x18 (four Array ctors + RCP<Level> ctor)'),
    (0x54aa80, '??1ShadowSurface@' + MESH + 'QAE@XZ', '~Mesh 00548c21 on +0x18'),
    (0x54bec0, '??0?$Array@V' + LEVEL_RCP + '@G3D@@QAE@XZ', 'Mesh() 005485b4 on levels +0xc'),
    (0x54bee0, '??1?$Array@V' + LEVEL_RCP + '@G3D@@QAE@XZ', '~Mesh 00548c30 on levels +0xc'),
    (0x54b2a0, '??0?$vector@GV?$allocator@G@std@@@std@@QAE@XZ', 'Mesh() 005485d2 on +0x50 (_Buy 0054c500: 2-byte elements)'),
    (0x54b310, '??1?$vector@GV?$allocator@G@std@@@std@@QAE@XZ', '~Mesh 00548c12 on +0x50'),
    (0x54c050, '??0?$vector@VVector3@G3D@@V?$allocator@VVector3@G3D@@@std@@@std@@QAE@XZ',
     'Mesh() 005485e1 on +0x68 (_Buy 0054d940: 0xc-byte elements)'),
    (0x54c0c0, '??1?$vector@VVector3@G3D@@V?$allocator@VVector3@G3D@@@std@@@std@@QAE@XZ', '~Mesh 00548c03 on +0x68'),
    (0x54ad70, '?append@?$Array@H@G3D@@QAEXABH@Z', 'allocVertex 00548098 on vertexRefCounts 009738c4 (temporary 1)'),
    (0x54ae30, '?push@?$Array@H@G3D@@QAEXABH@Z', 'freeVertex 005486bd on freeList 009738ac (int temporary of index)'),
    (0x54ae50, '?pop@?$Array@H@G3D@@QAEH_N@Z', 'allocVertex 005480a9 on freeList (push 0: default flag)'),
    (0x54ae90, '??A?$Array@H@G3D@@QAEAAHH@Z', 'initStatics 00547fa6 on vertexRefCounts (push 0, two asserts)'),
    (0x54aeb0, '??A?$Array@H@G3D@@QAEAAHI@Z', 'allocVertex 00547fd1 / freeVertex 00548686 (one assert: unsigned)'),
    (0x54ad50, '?length@?$Array@H@G3D@@QBEHXZ', 'allocVertex 00548024 on freeList (calls size 0054bf70)'),
    (0x54ad30, '?clear@?$Array@H@G3D@@QAEXXZ', 'initStatics 00547fb6 on freeList (resize(0) 004806b0)'),
    (0x54bda0, '?resize@?$Array@VVector2@G3D@@@G3D@@QAEXH@Z', 'initStatics 00547f82 on texCoordArray 00973934 (push 1)'),
    (0x54bdc0, '?append@?$Array@VVector2@G3D@@@G3D@@QAEXABVVector2@2@@Z',
     'allocVertex 0054806b on texCoordArray (recursive aliasing path 0054bdc0)'),
]
ROOTS_PENDING = [
    (0x548570, '??0' + MESH + 'IAE@XZ', 'BrickMesh ctor 004e53c0 / SphereMesh 004fcfb0 (vtable 0082d028)'),
    (0x547f60, '?initStatics@' + MESH + 'KAXXZ', 'Mesh() 005485f5 under the once flag 00973980'),
    (0x547fc0, '?allocVertex@' + MESH + 'SAIII@Z', 'ViewNew header evidence (static allocVertex(unsigned, unsigned))'),
    (0x548000, '?allocVertex@' + MESH + 'SAIABVVector3@G3D@@0ABVVector2@5@_N@Z',
     'LevelBuilder strips 004dcaa0 / 004de360 (4 pushes, add esp 0x10)'),
    (0x548640, '?freeVertex@' + MESH + 'SAXI@Z', '~Level 00548a1c / strips (1 push, add esp 4)'),
    (0x548f80, '?detailLevel@' + MESH + 'QAE?BV?$ReferenceCountedPointer@VLevel@' + MESH + '@G3D@@M@Z',
     'callers 00504290 / 0053f720 / 00547440 (hidden return RCP, float pushed)'),
    (0x548fe0, '?sendGeometry@' + MESH + 'SAXPBVLevel@123@PAVRenderDevice@G3D@@@Z', 'callers 00502370 / 005023e0'),
    (0x549030, '?endRender@' + MESH + 'SAXPAVRenderDevice@G3D@@@Z', 'caller 00504bf0'),
    (0x54a9c0, '??_G' + MESH + 'UAEPAXI@Z', 'Mesh vtable 0082d028 slot 0 (emitted with the vtable Mesh() references)'),
]
# ---- externals: the address the original instruction uses (call site in parentheses) --------------------------------
EXTERNAL = {
    # Template members folded by identical-code folding into a copy compiled elsewhere, or defined outside this range:
    # bound by the call site only.
    '??0?$Array@VVector3@G3D@@@G3D@@QAE@XZ': 0x481520,  # 0054aa2b / 0054aa49
    '??0?$ReferenceCountedPointer@VLevel@Mesh@RenderBase@RBX@@@G3D@@QAE@XZ': 0x4f0810,  # 0054aa58
    '??1?$ReferenceCountedPointer@VLevel@Mesh@RenderBase@RBX@@@G3D@@QAE@XZ': 0x502a70,  # 0054aab3
    '??1?$Array@VVector3@G3D@@@G3D@@QAE@XZ': 0x6433e0,  # 0054aac2 / 0054aae0
    '??1?$Array@VFace@MeshAlg@G3D@@@G3D@@QAE@XZ': 0x5516d0,  # 0054aad1
    '??1?$Array@VEdge@MeshAlg@G3D@@@G3D@@QAE@XZ': 0x5516d0,  # 0054aaef
    '___security_cookie': 0x965cc0,  # 0054aa02
    '??0Vector2@G3D@@QAE@ABV01@@Z': 0x411790,  # 0054be27 / 0054be70 / 0054ec7d
    '??0Vector2@G3D@@QAE@XZ': 0x467260,  # 0054d357
    '??4Vector2@G3D@@QAEAAV01@ABV01@@Z': 0x411790,  # 005480f8 / 0054beaa
    '??_B?3??resize@?$Array@VVector2@G3D@@@G3D@@QAEXH_N@Z@53': 0x9739a0,  # 0054d1bb / 0054d1c5 / 0054d1cd
    '?minSize@?3??resize@?$Array@VVector2@G3D@@@G3D@@QAEXH_N@Z@4HB': 0x97399c,  # 0054d1e5 / 0054d231 / 0054d23b
    # the template members' own callees (G3D System / STL helpers and folded COMDATs outside this unit)
    '??0Edge@MeshAlg@G3D@@QAE@XZ': 0x7bae80,  # 0054d627
    '??0Face@MeshAlg@G3D@@QAE@XZ': 0x7bae60,  # 0054d8d7
    '??0_Aux_cont@std@@QAE@QBV_Container_base_aux@1@@Z': 0x6f6a20,  # 0054efd9
    '??0_Container_base_aux@std@@QAE@XZ': 0x7188c0,  # 0054ef8c
    '??1_Container_base_aux@std@@QAE@XZ': 0x47d410,  # 005415cb
    '??2@YAPAXIPAX@Z': 0x401670,  # 0054efbd / 0054ad99 / 0054ed8f
    '??_B?3??resize@?$Array@VEdge@MeshAlg@G3D@@@G3D@@QAEXH_N@Z@53': 0x9739a8,  # 0054d48b / 0054d495 / 0054d49d
    '??_B?3??resize@?$Array@VFace@MeshAlg@G3D@@@G3D@@QAEXH_N@Z@53': 0x9739b0,  # 0054d73b / 0054d745 / 0054d74d
    '??_G?$ReferenceCountedPointer@VLevel@Mesh@RenderBase@RBX@@@G3D@@QAEPAXI@Z': 0x4d76e0,  # 0054bf14
    '?_Destroy@?$vector@GV?$allocator@G@std@@@std@@IAEXPAG0@Z': 0x458e90,  # 0054c5a2
    '?_Destroy@?$vector@VVector3@G3D@@V?$allocator@VVector3@G3D@@@std@@@std@@IAEXPAVVector3@G3D@@0@Z': 0x458e90,  # 0054d9e2
    '?_Xlen@?$vector@GV?$allocator@G@std@@@std@@KAXXZ': 0x4c6d40,  # 0054c53f
    '?_Xlen@?$vector@VVector3@G3D@@V?$allocator@VVector3@G3D@@@std@@@std@@KAXXZ': 0x4c6d40,  # 0054d97f
    '?alignedFree@System@G3D@@SAXPAX@Z': 0x507d20,  # 0054bf21 / 0054ee02 / 0054ef2e
    '?alignedMalloc@System@G3D@@SAPAXII@Z': 0x508580,  # 0054ed2e / 0054ee4e
    '?allocate@?$allocator@G@std@@QAEPAGI@Z': 0x4dc540,  # 0054c550
    '?allocate@?$allocator@VVector3@G3D@@@std@@QAEPAVVector3@G3D@@I@Z': 0x4dc570,  # 0054d990
    '?allocate@?$allocator@V_Aux_cont@std@@@std@@QAEPAV_Aux_cont@2@I@Z': 0x4034a0,  # 0054efaf
    '?deallocate@?$allocator@G@std@@QAEXPAGI@Z': 0x4dc3e0,  # 0054c5c3
    '?deallocate@?$allocator@VVector3@G3D@@@std@@QAEXPAVVector3@G3D@@I@Z': 0x4dc3e0,  # 0054da0b
    '?deallocate@?$allocator@V_Aux_cont@std@@@std@@QAEXPAV_Aux_cont@2@I@Z': 0x4dc3e0,  # 005415bc
    '?iMax@G3D@@YAHHH@Z': 0x46fc40,  # 0054d4ad / 0054d75d
    '?iMin@G3D@@YAHHH@Z': 0x46fc30,  # 0054ed46 / 0054ee66 / 0054d5d1
    '?inArray@?$Array@H@G3D@@AAE_NPBH@Z': 0x47f610,  # 0054addb
    '?max_size@?$vector@GV?$allocator@G@std@@@std@@QBEIXZ': 0x4dc400,  # 0054c535
    '?max_size@?$vector@VVector3@G3D@@V?$allocator@VVector3@G3D@@@std@@@std@@QBEIXZ': 0x4dc560,  # 0054d975
    '?minSize@?3??resize@?$Array@VEdge@MeshAlg@G3D@@@G3D@@QAEXH_N@Z@4HB': 0x9739a4,  # 0054d4b5 / 0054d501 / 0054d50b
    '?minSize@?3??resize@?$Array@VFace@MeshAlg@G3D@@@G3D@@QAEXH_N@Z@4HB': 0x9739ac,  # 0054d765 / 0054d7b1 / 0054d7bb
    '?resize@?$Array@H@G3D@@QAEXH@Z': 0x4806b0,  # 0054ad3d
    '?resize@?$Array@H@G3D@@QAEXH_N@Z': 0x480020,  # 0054ae0c / 0054ae82
    '?resize@?$Array@V?$ReferenceCountedPointer@VLevel@Mesh@RenderBase@RBX@@@G3D@@@G3D@@QAEXH_N@Z': 0x4dc7e0,  # 0054ed01
    '__ftol2_sse': 0x6a17f0,  # 0054d565 / 0054d815
}
# data: the security cookie and the function-local statics of the Array<Edge> / Array<Face> resize instantiations
DATA_EXTERNAL = {k for k in EXTERNAL if k.startswith('?minSize@') or k.startswith('??_B')} | {'___security_cookie'}
EXTERNAL_PENDING = dict(EXTERNAL)
EXTERNAL_PENDING.update({
    '??0?$Array@VVector3@G3D@@@G3D@@QAE@XZ': 0x481520,  # 0054aa2c / 0054aa4a
    '??0?$ReferenceCountedPointer@VLevel@Mesh@RenderBase@RBX@@@G3D@@QAE@XZ': 0x4f0810,  # 0054aa59
    '??1Mesh@RenderBase@RBX@@UAE@XZ': 0x548a90,  # 0054a9cb
    '??4Vector3@G3D@@QAEAAV01@ABV01@@Z': 0x514be0,  # 005480c6 / 005480df / 00548113
    '??A?$Array@VVector2@G3D@@@G3D@@QAEAAVVector2@1@I@Z': 0x4dc3c0,  # 005480f1
    '??A?$Array@VVector3@G3D@@@G3D@@QAEAAVVector3@1@I@Z': 0x518b80,  # 005480bf / 005480d8 / 0054810c
    '?append@?$Array@VVector3@G3D@@@G3D@@QAEXABVVector3@2@@Z': 0x502f50,  # 00548048 / 0054805a / 00548080
    '?getCArray@?$Array@H@G3D@@QAEPAHXZ': 0x71f210,  # 0054864d
    '?resize@?$Array@VVector3@G3D@@@G3D@@QAEXH@Z': 0x503100,  # 00547f6b / 00547f77 / 00547f8f
    '?size@?$Array@VVector3@G3D@@@G3D@@QBEHXZ': 0x442cd0,  # 00548033
    '?zero@Vector3@G3D@@SAABV12@XZ': 0x4782a0,  # 00548075 / 005480fd
    '??0ReferenceCountedObject@G3D@@IAE@XZ': 0x472990,  # 00548599
    '??1ReferenceCountedObject@G3D@@UAE@XZ': 0x7accf0,  # Mesh() unwind funclet (not compared)
    '?visibleGeometry@' + MESH + '2VGeometry@MeshAlg@G3D@@A': 0x9738f0,  # 00547f65 / 0054802e
    '?texCoordArray@' + MESH + '2V?$Array@VVector2@G3D@@@G3D@@A': 0x973934,  # 00547f7d / 00548066
    '?tangentArray@' + MESH + '2V?$Array@VVector3@G3D@@@G3D@@A': 0x973928,  # 00547f89 / 0054807a
    '?vertexRefCounts@' + MESH + '2V?$Array@H@G3D@@A': 0x9738c4,  # 00547f95 / 00547fcc / 00548647
    '?freeList@' + MESH + '2V?$Array@H@G3D@@A': 0x9738ac,  # 00547fb1 / 0054801f / 005486b8
    '?varDirty@' + MESH + '2_NA': 0x9738a1,  # 00548006 / 00548011
    '?vertexPoolChanged@' + MESH + '2_NA': 0x942ebc,  # 00548018
    '??$sendIndices@I@RenderDevice@G3D@@QAEXW4Primitive@01@ABV?$Array@I@1@@Z': 0x5029c0,  # 00549023
    '??0?$ReferenceCountedPointer@VLevel@Mesh@RenderBase@RBX@@@G3D@@QAE@PAVLevel@Mesh@RenderBase@RBX@@@Z': 0x4e6030,  # 00548fbf
    '?endIndexedPrimitives@RenderDevice@G3D@@QAEXXZ': 0x4796a0,  # 00549044
    '?iClamp@G3D@@YAHHHH@Z': 0x46fc10,  # 0054acd5
    '?size@?$Array@I@G3D@@QBEHXZ': 0x442cd0,  # 00549004
    '_init': 0x973980,  # 005485ed / 005485fc (file static)
    '_vertexRefCount': 0x9738a4,  # 00547fe8 / 00548131 / 00548670 (file static)
})
DATA_EXTERNAL_PENDING = DATA_EXTERNAL | {k for k in EXTERNAL_PENDING if k.startswith('?') and k.endswith('A')} | {
    '_init', '_vertexRefCount'} | {k for k in EXTERNAL_PENDING if k.startswith('?minSize@') or k.startswith('??_B')}


def load_bodies(which):
    raw = Path(OBJ[which]).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {}
    for n, b, r in match.coff_functions(raw):
        start, section = definitions[n]
        table = sections[section]
        rel = []
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
            offset -= start
            if 0 <= offset < len(b):
                rel.append((offset, symbols[index][0], kind))
        bodies.setdefault(n, (which, b, r, rel))
    return bodies


TARGET = {}


def target_of(address):
    if address not in TARGET:
        body, refs, _ = match.target('2008-06', '%08x' % address)
        TARGET[address] = (body, refs)
    return TARGET[address]


class Closure:
    def __init__(self, which, roots, external, data_external):
        self.which, self.external, self.data_external = which, external, data_external
        self.bodies = load_bodies(which)
        self.raw = Path(OBJ[which]).read_bytes()
        self.index = match._coff_data_index(self.raw)
        self.used, self.unbound = set(), []
        self.proven, self.aliases, self.why, self.not_exact = {}, {}, {}, {}
        queue = deque()
        for address, symbol, evidence in roots:
            assert symbol in self.bodies, ('root symbol missing', which, symbol)
            if not self.exact_at(symbol, address):
                self.not_exact[address] = (symbol, 'root: ' + evidence)
                continue
            queue.append((address, symbol, 'root: ' + evidence))
        while queue:
            address, symbol, reason = queue.popleft()
            if address in self.proven:
                if symbol not in self.aliases[address]:
                    assert self.exact_at(symbol, address), ('folded alias not exact', '%08x' % address, symbol)
                    self.aliases[address].append(symbol)
                continue
            if not self.exact_at(symbol, address):
                self.not_exact.setdefault(address, (symbol, reason))
                continue
            self.proven[address], self.aliases[address], self.why[address] = symbol, [symbol], reason
            _, body, _, rel = self.bodies[symbol]
            target, _ = target_of(address)
            for offset, sym, kind in rel:
                if kind == 20:
                    value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
                    if value in FUNCTIONS and sym in self.bodies and not nb.LOCAL_EH.match(sym) \
                            and sym not in self.external:
                        queue.append((value, sym, 'called by %08x' % address))
        self.own = {}
        for address, syms in self.aliases.items():
            for s in syms:
                prev = self.own.setdefault(s, address)
                assert prev == address, ('one address per symbol', s, hex(prev), hex(address))
        self.checked = {a: self.verify(a, s) for a, s in sorted(self.proven.items())}

    def exact_at(self, symbol, address):
        if symbol not in self.bodies or address not in FUNCTIONS:
            return False
        _, body, refs, _ = self.bodies[symbol]
        target, target_refs = target_of(address)
        return match.exact_match(target, target_refs, body, refs)

    def verify(self, address, symbol):
        _, body, refs, rel = self.bodies[symbol]
        target, _ = target_of(address)
        sections, symbols, definitions, _ = self.index
        verified, local = {}, set()
        for offset, sym, kind in rel:
            if kind == 20:
                value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            else:
                start, section = definitions[symbol]
                code = self.raw[sections[section][4] + start:]
                value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) \
                    & 0xffffffff
            if nb.LOCAL_EH.match(sym):
                local.add(sym)
                continue
            hit = original.imported(value)
            if hit is not None:
                assert hit[1] == nb.plain(sym), (symbol, sym, hex(value), hit)
                how = '%s!%s' % hit
            elif sym.startswith('__real@'):
                assert original.data(value, len(sym[7:]) // 2) == bytes.fromhex(sym[7:])[::-1], (symbol, sym)
                how = 'constant %s' % sym[7:]
            elif sym.startswith('??_C@'):
                pos, at = definitions[sym]
                literal = self.raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
                assert original.data(value, len(literal)) == literal, (symbol, sym, hex(value))
                how = 'string %r' % literal[:-1].decode('latin-1')
            elif sym.startswith('??_7'):
                rtti, at = original.vtable_class(value)
                cls = sym[4:sym.index('@@6B') + 2]
                assert rtti == '.?AV' + cls, (symbol, sym, hex(value), rtti)
                how = 'vtable RTTI %s offset %#x' % (rtti, at)
            elif sym in self.own:
                assert self.own[sym] == value, (symbol, sym, hex(value), hex(self.own[sym]))
                how = 'own row'
            elif sym in self.external:
                assert self.external[sym] == value, (symbol, sym, hex(value), hex(self.external[sym]))
                how = 'external' + (' (evidence name)' if names.get(value, '') == sym else '')
                self.used.add(sym)
            else:
                self.unbound.append("    %r: %#x,   # %s in %s at %08x" % (sym, value, names.get(value, '')[:50],
                                                                          symbol[:50], address + offset))
                continue
            verified[sym] = '%s (%s)' % (hex(value), how)
        return {'size': len(body), 'target_size': len(target), 'verified_targets': verified, 'local_eh': sorted(local)}

    def check(self, label, required_unused=()):
        if DISCOVER:
            print('==', label)
            print('\n'.join(sorted(set(self.unbound))))
            for a, (s, r) in sorted(self.not_exact.items()):
                print('NOT EXACT %08x %s (%s)' % (a, s[:120], r))
            print('PROVEN', len(self.proven), 'in range', sum(1 for a in self.proven if RANGE[0] <= a < RANGE[1]))
            print('UNUSED EXTERNAL', sorted(set(self.external) - self.used - set(required_unused)))
            return
        assert not self.unbound, '\n'.join(self.unbound)
        assert sorted(self.used | set(required_unused)) == sorted(self.external), \
            sorted(set(self.external) - self.used - set(required_unused))
        for symbol, address in self.external.items():
            assert address in FUNCTIONS or original.imported(address) is not None or symbol in self.data_external, \
                (symbol, hex(address))


MAIN = Closure('main', ROOTS_MAIN, EXTERNAL, DATA_EXTERNAL)
MAIN.check('main')
assert not MAIN.not_exact or DISCOVER, {('%08x' % a): v for a, v in MAIN.not_exact.items()}
# the unwind-only ReferenceCountedObject dtor is referenced from a funclet, not from a compared body
PENDING = Closure('pending', ROOTS_MAIN + ROOTS_PENDING, EXTERNAL_PENDING, DATA_EXTERNAL_PENDING)
PENDING.check('pending', required_unused=('??1ReferenceCountedObject@G3D@@UAE@XZ',))
if DISCOVER:
    sys.exit(0)
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
range_functions = sorted(a for a in FUNCTIONS if RANGE[0] <= a < RANGE[1])
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if RANGE[0] <= a < RANGE[1]}
counted = sorted(a for a in MAIN.proven if RANGE[0] <= a < RANGE[1] and a not in elsewhere)
assert not set(counted) & set(elsewhere)
support = sorted(a for a in MAIN.proven if a not in counted)
pending_only = sorted(a for a in PENDING.proven if a not in MAIN.proven)
pending_not_exact = sorted(a for a in PENDING.not_exact if a in {r[0] for r in ROOTS_PENDING})
assert not pending_not_exact, ['%08x' % a for a in pending_not_exact]


def row(c, a, note):
    return dict({'address': '%08x (%s)' % (a, note), 'symbol': c.proven[a], 'folded_symbols': c.aliases[a][1:],
                 'identity': c.why[a]}, **c.checked[a])


rows_out = [dict({'address': '%08x' % a, 'symbol': MAIN.proven[a], 'folded_symbols': MAIN.aliases[a][1:],
                  'identity': MAIN.why[a], 'exact': True}, **MAIN.checked[a]) for a in counted]
support_out = [row(MAIN, a, ('counted by ' + ', '.join(sorted(set(elsewhere[a])))) if a in elsewhere else
                   'outside the range %08x..%08x' % RANGE) for a in support]
pending_out = [dict(row(PENDING, a, 'pending-build-only, not counted'), exact=False) for a in pending_only]

NOT_BUILT_REASON = {
    0x548150: 'Mesh.cpp static (1046 B, no direct caller in the analysis; G3D Array / RCP<Chunk> helpers): not attempted',
    0x5486e0: 'Level sub-mesh release (713 B): needs the exe-local Ogre sub-mesh class (deleting dtor 0054ac70 -> '
              '006824e0), the sub-mesh name map holder 0054ab40 (boost::call_once 00557330, mutex +0x24, map '
              'operator[] 0054b3a0 / find 0054bd00 / erase 0054b520, log "RBX rm "), the static Ogre::MeshPtr 009738b8 '
              'and 00682150; none is declared',
    0x5489b0: '~Level (223 B): freeVertex loop (pending-exact callee) + Level release 005486e0 + static counter '
              '009738a8 + the static Ogre::MeshPtr 009738b8; not declared',
    0x548a90: '~Mesh (451 B): the same sub-mesh release as 005486e0 on +0x80 (" shd" log), not declared; its ??_G '
              '0054a9c0 is pending-exact',
    0x548c60: 'setShadowVertex-shaped static (66 B): needs the static VAR / Array at 009738d0 (0x20-byte gap '
              '009738d0..009738ef, type not derived)',
    0x548cb0: 'makeVAR-shaped static (517 B): needs the VAR statics (009738d0 ..) and VARArea; not derived',
    0x548ec0: 'beginRender-shaped static (178 B): needs the VAR statics; not derived',
    0x549050: 'Mesh.cpp member (900 B, callers 005032a0 / 00552300; Array<Edge> / G3D MeshAlg calls): not attempted',
    0x5493e0: 'Ogre sub-mesh builder ("General", "rbxvb", "create mesh="; RenderScene 007ab0a0): Ogre sub-mesh '
              'classes undeclared',
    0x549610: 'Ogre sub-mesh builder ("RBX makeHWSubMesh: should not be here"): Ogre sub-mesh classes undeclared',
    0x549a50: 'Ogre sub-mesh builder (3779 B): Ogre sub-mesh classes undeclared',
    0x54a920: 'Ogre sub-mesh helper (148 B, RenderScene 007ab0a0): Ogre sub-mesh classes undeclared',
    0x54ab10: 'scalar deleting dtor of an undeclared Ogre helper (delete via 006a067a; 005488b2)',
    0x54ab40: 'sub-mesh name map holder accessor (boost::call_once 00557330 with 0054ab60 / once flag 00973984)',
    0x54ab60: 'sub-mesh name map initialiser (ogre-visual-engine receipt names it; map type undeclared)',
    0x54abe0: 'sub-mesh name map holder ctor (map ctor 0054b370, mutex 00563070)',
    0x54ac50: 'sub-mesh name map holder dtor (map dtor 0054b4c0)',
    0x54ac70: 'deleting dtor of the exe-local Ogre sub-mesh (006824e0); class undeclared',
    0x54acf0: 'header-inline Ogre::VisualEngine bool accessor (+0x7f4 useLargeVertexBuffer, ogre-visual-engine '
              'receipt; called by 00549a50); VisualEngine2008.h does not exist yet',
    0x54ad10: 'one-call wrapper used by the 00549a50 builder (0054c390); type not derived',
    0x54aed0: 'recursive template member (410 B) called by 00549050: not built with it',
    0x54b070: 'recursive template member (553 B) called by 00549050: not built with it',
    0x54b370: 'std::map ctor of the sub-mesh name map (key / value types not declared)',
    0x54b3a0: 'std::map operator[] of the sub-mesh name map (005487a3 / 00548b3d / 0067c130)',
    0x54b4c0: 'std::map dtor of the sub-mesh name map',
    0x54b520: 'std::map erase of the sub-mesh name map (2004 B)',
    0x54bd00: 'std::map find of the sub-mesh name map',
    0x54bf90: 'Array<16-byte element> push helper called by the 00547610 aggregate static (not built)',
    0x54bfc0: 'Array<16-byte element> operator[] called by 00547610 / 00549050 (not built)',
}
unbuilt = []
for a in range_functions:
    if a in MAIN.proven or a in range_counted or a in PENDING.proven:
        continue
    unbuilt.append('%08x: %s' % (a, NOT_BUILT_REASON.get(a, 'not attempted')))

UNIT_MAP = {
    'RenderBase Mesh.cpp 00547440..(past 0054c000), the whole range': (
        'One /Od /Ob0 /GS RenderBase unit (head below the range in the app-unit540 map): initStatics 00547f60 (once flag '
        '00973980), allocVertex(unsigned, unsigned) 00547fc0, allocVertex(Vector3, Vector3, Vector2, bool) 00548000, '
        'a 1046-byte static 00548150, Mesh() 00548570 (vtable 0082d028), freeVertex 00548640, Level release 005486e0 / '
        '~Level 005489b0 (vtable 00826e4c), ~Mesh 00548a90 (strings " shd", "RBX rm "), the VAR statics 00548c60 / '
        '00548cb0 / 00548ec0, detailLevel 00548f80 / detailIndex 0054aca0, sendGeometry 00548fe0, endRender 00549030, '
        'a 900-byte member 00549050, the Ogre sub-mesh builders 005493e0 / 00549610 / 00549a50 / 0054a920 (RenderScene '
        '007ab0a0), Mesh ??_G 0054a9c0, ShadowSurface ctor 0054a9f0 / dtor 0054aa80, the sub-mesh name map holder '
        '0054ab10..0054ac70 (boost::call_once initialiser 0054ab60), then the COMDAT template instantiations of this unit '
        '(G3D::Array<int> / <Vector2> / <Edge> / <Face> / <RCP<Level> >, std::vector<unsigned short> / <Vector3>, the '
        'sub-mesh name std::map) from 0054acf0 to past 0054c000. The static vertex pool lives at 009738a1..00973934.'),
    'excluded / library code': (
        'none in the range: no CRobloxApp / CMainFrame / CRobloxDoc / CRobloxView row, and the STL / G3D / boost bodies '
        'are Roblox-instantiated templates of this unit (element types RBX::RenderBase::* or the Mesh statics), not '
        'separately linked library objects. 0054acf0 is a header-inline Ogre::VisualEngine (exe-local) accessor.'),
    'counted here (main build)': 'ShadowSurface ctor / dtor and the template members listed in exact_function_rows.',
    'pending-build-only (not counted)': (
        'Mesh() 00548570, allocVertex 00548000, freeVertex 00548640, detailLevel 00548f80, sendGeometry 00548fe0, '
        'endRender 00549030, ??_G 0054a9c0, detailIndex 0054aca0 (and below the range initStatics 00547f60, allocVertex '
        '00547fc0): exact only against the generated pending RenderBaseMesh.h (proposal below).'),
}
REJECTED = {
    'detailLevel as `return levels[detailIndex(detail)].getPointer();`': '79 B vs 85 B: the original stores the index '
    'in a named local before operator[] (exact with `int index = detailIndex(detail);`)',
}
PROPOSALS = {
    'ViewNew/RenderBaseMesh.h (ViewNew / RenderBase owner)': (
        'Add to RBX::RenderBase::Mesh (exact text in out/native-layouts/app-unit548/pending/ViewNew/RenderBaseMesh.h, '
        'generated by this recorder): public statics `G3D::MeshAlg::Geometry visibleGeometry` (009738f0: vertexArray '
        'resize/append 00503100 / 00502f50, normalArray 009738fc), `G3D::Array<G3D::Vector2> texCoordArray` (00973934; '
        '8-byte elements, resize 0054bda0 / append 0054bdc0), `G3D::Array<G3D::Vector3> tangentArray` (00973928), '
        '`G3D::Array<int> vertexRefCounts` (009738c4) and `G3D::Array<int> freeList` (009738ac; 4-byte elements, '
        'append 0054ad70 / push 0054ae30 / pop 0054ae50), `bool varDirty` (009738a1; also read by 0045ea5c), '
        '`bool vertexPoolChanged` (00942ebc, .data initial 1, set by allocVertex 00548018, tested by RenderScene '
        '007ab54d / 007acb50; the name is descriptive), `static void sendGeometry(const Level*, G3D::RenderDevice*)` '
        '00548fe0 and `static void endRender(G3D::RenderDevice*)` 00549030 (cdecl, 2 / 1 pushes), '
        '`const G3D::ReferenceCountedPointer<Level> detailLevel(float)` 00548f80 (non-const: it calls the non-const '
        'Array operator[] 0054ae90; hidden return pointer), and protected `static void initStatics()` 00547f60 and '
        '`int detailIndex(double) const` 0054aca0 (thiscall, ret 8). The array element types follow the donor '
        'RenderLib Mesh.h and match the element sizes; the public statics are read directly by the ViewNew builders '
        '(004dcaa6 / 004dcab6 / 004e2edf). With them, 10 rows (8 in this range) are exact in the pending build; the '
        'bodies are in native-classes/AppUnit548Mesh.cpp under NATIVE_APPUNIT548_PENDING.'),
    'Ogre owner, FYI': (
        '~Mesh 00548a90, Level release 005486e0 and ~Level 005489b0 also need the exe-local Ogre sub-mesh class '
        '(deleting dtor 0054ac70 -> 006824e0, see the ogre-visual-engine / rbx-entity proposals), the sub-mesh name map '
        'holder (accessor 0054ab40 via boost::call_once 00557330, initialiser 0054ab60, mutex at +0x24, std::map with '
        'operator[] 0054b3a0 / find 0054bd00 / erase 0054b520) and a static Ogre::MeshPtr 009738b8 plus a static '
        'counter 009738a8.'),
    'BOUNDS': 'none new.',
}

receipt = {
    'class': 'RBX::RenderBase Mesh.cpp unit of the application range 00548000..0054c000 (2008-06), inactive',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM), /Od /Ob0 /GS (RenderBase library profile) + Ogre 1.4.5 client headers',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): nb.sha(p) for p in
                [Path(__file__).resolve(), SOURCE] + HEADERS},
    'pending_header': {str(PENDING_H.relative_to(ROOT)).replace('\\', '/'): nb.sha(PENDING_H)},
    'objects': {k: nb.sha(v) for k, v in OBJ.items()},
    'unit_map': UNIT_MAP,
    'range_functions': len(range_functions),
    # Written as 'ADDR counted by RECEIPT' text, never as a quoted bare address: some recorders (local_backpack,
    # viewnew_brick_build, viewnew_part_mesh) treat any '"ADDR"' in another receipt as counted there and drop it.
    'range_rows_counted_by_other_receipts': ['%08x counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()],
    'range_rows_not_built': unbuilt,
    'rows': rows_out,
    'support_rows_not_counted': support_out,
    'pending_build_only': pending_out,
    'exact_function_rows': ['%08x' % a for a in counted],
    'rejected': REJECTED,
    'proposals': PROPOSALS,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit. Pending-build '
             'rows are exact=false and not counted.',
}
text = json.dumps(receipt, indent=2) + '\n'
quoted = set(re.findall(r'"([0-9a-f]{8})"', text))
assert quoted <= {'%08x' % a for a in counted}, sorted(quoted - {'%08x' % a for a in counted})[:10]
RECEIPT.write_text(text)
print('PASS app-unit548: %d counted exact rows; %d support rows; %d pending-build-only rows (%d in range); %d range '
      'rows, %d counted elsewhere, %d not built'
      % (len(counted), len(support_out), len(pending_out), sum(1 for a in pending_only if RANGE[0] <= a < RANGE[1]),
         len(range_functions), len(range_counted), len(unbuilt)))
print(' '.join('%08x' % a for a in counted))
