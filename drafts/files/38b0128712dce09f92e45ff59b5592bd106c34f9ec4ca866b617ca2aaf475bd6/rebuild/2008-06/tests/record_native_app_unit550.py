"""Verify the inactive 2008-06 native rows of the application range 00550000..00554000, and record the unit map of the
range (boundary evidence in the receipt's `unit_map`; rows counted by other receipts are listed there as text).

Unit map summary (details in UNIT_MAP below):
  * 00550000..0055172f: the tail of the RenderBase Mesh.cpp COMDAT instantiations (std::map / std::set _Tree members,
    G3D::Array members) that the AggregatingSceneManager.cpp and Mesh.cpp units below the range call
    (app-unit540-2008 / app-unit548 maps).
  * 00551730..00551f2f: TextureProxy factories and TextureProxy members (render-material owner).
  * 00551f30..0055390f: RenderBase AggregateChunk.cpp: ctor / dtor / virtual slots (render-scene owner), makeMesh
    00552270, renderShadows 00552300 and the template instantiations of that unit.
  * 00553910..00553fff: util/Name.cpp and the ICF-shared std::map _Tree helpers (Name owner, core header).

Units built here (VS2008 RTM 21022, document-swap flags with /Od /Ob0 /GS ahead of native-headers and the Ogre 1.4.5
client headers: the RenderBase library profile of tests/record_native_render_scene.py):
  * unit:      native-classes/AppUnit550AggregateChunk.cpp (this group): explicit template member instantiations.
  * pending:   the same source with NATIVE_APPUNIT550_PENDING against generated copies of ViewNew/RenderBaseMesh.h and
               RenderLib/AggregateChunk2008.h under out/native-layouts/app-unit550/pending/ that add the declarations
               the binary proves (see PROPOSALS): AggregateChunk::renderShadows 00552300 and makeMesh 00552270. Rows
               exact only there are recorded exact=false (pending-build-only) and never counted.
  * read-only identity roots (compiled, never edited): native-classes/SceneManagerAggregating2008.cpp (render-scene
    owner), native-classes/AppUnit540_2008AggregatingSceneManager.cpp and native-classes/AppUnit548Mesh.cpp (their
    main builds). Their ROOTS / EXTERNAL tables are read from tests/record_native_app_unit540_2008.py and
    tests/record_native_app_unit548.py (parsed, not executed), so the identity evidence stays in one place.
No header is created under native-headers (nothing is shadowed).

Row identity is proven by a call-graph closure from the root rows (each relocation-masked exact at the address its
evidence names): every REL32 call target of an exact row binds to the symbol the compiled instruction references; that
symbol's compiled body must be exact there, and so on. Each symbol binds to one address; an address may carry several
symbols (identical-code folding), each of whose bodies must be exact there. Rows the analysis splits at a catch(...)
funclet are compared joined with the funclet row (bounds evidence) and traversed, but never counted. Every REL32/DIR32
target of every proven row is verified: imports by DLL export name, strings and constants by bytes, vtables by
original RTTI names, own (proven) rows, and the remaining externals by the explicit EXTERNAL map (call-site evidence in
comments). Counted rows are the main-build proven rows inside the range that no other receipt counts.
Writes work/2008-06/shared-layouts/app-unit550-working.json. Never writes a quoted bare address of a row it does not
count. Set NATIVE_APP_UNIT550_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
"""
import ast
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
T = R / 'tests'
OUT = nb.OUT / 'app-unit550'
OUT.mkdir(parents=True, exist_ok=True)
OGRE = '/I' + str(ROOT / 'tools/libs/ogre-1.4.5/ogrenew/OgreMain/include')
SOURCE = R / 'native-classes/AppUnit550AggregateChunk.cpp'
READ_ONLY = {
    'aggregating': R / 'native-classes/SceneManagerAggregating2008.cpp',      # render-scene owner
    'unit540': R / 'native-classes/AppUnit540_2008AggregatingSceneManager.cpp',
    'unit548': R / 'native-classes/AppUnit548Mesh.cpp',
}
MESH_H = R / 'native-headers/ViewNew/RenderBaseMesh.h'
CHUNK_H = R / 'native-headers/RenderLib/AggregateChunk2008.h'
HEADERS = [MESH_H, CHUNK_H, R / 'native-headers/RenderLib/SceneManager2008.h', R / 'native-headers/RenderLib/Material2008.h']
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT550_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit550-working.json'
RANGE = (0x550000, 0x554000)
PROFILE = ['/Od', '/Ob0', '/GS', OGRE]

# ---- pending headers: generated copies with the declarations the 2008 binary proves -----------------------------------
PENDING_DIR = OUT / 'pending'
(PENDING_DIR / 'ViewNew').mkdir(parents=True, exist_ok=True)
(PENDING_DIR / 'RenderLib').mkdir(parents=True, exist_ok=True)
MESH_ANCHOR = '\t\t\tstatic void freeVertex(unsigned int index);                               // 00548640\n'
MESH_DECL = '''
			// NATIVE_APPUNIT550_PENDING proposal (app-unit550 receipt).
			// 00549050: thiscall, ret 0x14 (renderShadows 00552496: cframe, light vector, Array<unsigned int>& +0xd8,
			// Array<Vector3>& 009739bc, bool), called through RCP<Mesh>::operator-> (const in the donor).
			void computeDirectionalShadowVolume(const G3D::CoordinateFrame& cframe, const G3D::Vector3& wsLightVector,
				G3D::Array<unsigned int>& indexArray, G3D::Array<G3D::Vector3>& shadowVertex, bool generateLightCap) const;
			// 00547610: cdecl, hidden RCP<Mesh> return, 3 pointer arguments (makeMesh 005522b4: components +0xf0,
			// _cframe +0x30, radius +0x1c; add esp 0x10).
			static G3D::ReferenceCountedPointer<Mesh> aggregate(
				const std::vector<G3D::ReferenceCountedPointer<class Chunk> >& components, G3D::CoordinateFrame& cframe,
				float& radius);
'''
CHUNK_ANCHOR = '\t\t\tAggregateChunk(const G3D::ReferenceCountedPointer<Chunk>& firstChunk); // 00551f30\n'
CHUNK_DECL = '''			// NATIVE_APPUNIT550_PENDING proposal (app-unit550 receipt): 00552270 (thiscall, no arguments, plain ret;
			// called by the Bucket member 0053fe10 after the ctor).
			void makeMesh();
'''
for path, anchor, decl, rel in ((MESH_H, MESH_ANCHOR, MESH_DECL, 'ViewNew/RenderBaseMesh.h'),
                                (CHUNK_H, CHUNK_ANCHOR, CHUNK_DECL, 'RenderLib/AggregateChunk2008.h')):
    text = path.read_text()
    assert text.count(anchor) == 1, (rel, 'anchor moved')
    (PENDING_DIR / rel).write_text(text.replace(anchor, anchor + decl))


def build(name, src, extra=(), first=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(first) + list(extra) + flags[i:] + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log[-4000:]
    return obj, flags


OBJ, FLAGS = {}, {}
OBJ['unit'], FLAGS['unit'] = build('NativeAppUnit550_unit', SOURCE, PROFILE)
OBJ['pending'], FLAGS['pending'] = build('NativeAppUnit550_pending', SOURCE, PROFILE + ['/DNATIVE_APPUNIT550_PENDING'],
                                         ['/I' + str(PENDING_DIR)])
for key, src in READ_ONLY.items():
    OBJ[key], FLAGS[key] = build('NativeAppUnit550_' + key, src, PROFILE)

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
FUNCTIONS = {int(json.loads(l)['addr'], 16) for l in
             (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines() if l.strip()}


# ---- identity tables of the read-only units, parsed from their recorders (never executed) --------------------------
def recorder_tables(path, wanted, constants):
    tree = ast.parse(path.read_text())
    env = dict(constants)
    out = {}
    for node in tree.body:
        if isinstance(node, ast.Assign) and len(node.targets) == 1 and isinstance(node.targets[0], ast.Name):
            name = node.targets[0].id
            if name in constants or name in wanted:
                value = eval(compile(ast.Expression(node.value), str(path), 'eval'), {'__builtins__': {}}, env)
                env[name] = value
                if name in wanted and name not in out:
                    out[name] = value
    assert sorted(out) == sorted(wanted), (path.name, sorted(set(wanted) - set(out)))
    return out


T540 = recorder_tables(T / 'record_native_app_unit540_2008.py', ['ROOTS', 'EXTERNAL'],
                       {'CHUNK_RCP': None, 'ASM': None})
T548 = recorder_tables(T / 'record_native_app_unit548.py', ['ROOTS_MAIN', 'EXTERNAL'],
                       {'MESH': None, 'LEVEL_RCP': None})
MESH = 'Mesh@RenderBase@RBX@@'
CHUNK_RCP = '?$ReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@'
VEC = '?$vector@V' + CHUNK_RCP + 'V?$allocator@V' + CHUNK_RCP + '@std@@@std@@'
CHUNK = 'AggregateChunk@RenderBase@RBX@@'

# ---- identity roots: (address, symbol, evidence) ----------------------------------------------------------------------
ROOTS_UNIT = [
    (0x5527b0, '?clear@?$Array@VVector3@G3D@@@G3D@@QAEXXZ',
     'renderShadows 005523f9 on the function-local static shadowVertex 009739bc (Array<Vector3> ctor 00481520 under '
     'guard 009739c8, append 00502f50)'),
    (0x5527d0, '?clear@?$Array@I@G3D@@QAEXXZ', 'renderShadows 0055236e / 00552533 on shadowIndexArray +0xd8'),
    (0x552810, '?clear@?$Array@G@G3D@@QAEXXZ', 'renderShadows 0055237f on shadowIndexArray16 +0xe4'),
    (0x552830, '??$sendIndices@G@RenderDevice@G3D@@QAEXW4Primitive@01@ABV?$Array@G@1@@Z',
     'renderShadows 00552665 (push shadowIndexArray16 +0xe4, push 2 = TRIANGLES; the unsigned int overload is '
     '005029c0 at 00552612)'),
    (0x551600, '??0?$Array@VVector2@G3D@@@G3D@@QAE@XZ',
     'dynamic initializer 007f26e0 on the Mesh static texCoordArray 00973934 (resize 0054bda0, app-unit548)'),
    (0x5516d0, '??1?$Array@VFace@MeshAlg@G3D@@@G3D@@QAE@XZ',
     'ShadowSurface dtor 0054aad1 (app-unit548 binds Array<Face> / Array<Edge> dtors to this one folded body)'),
    (0x5516d0, '??1?$Array@VEdge@MeshAlg@G3D@@@G3D@@QAE@XZ', 'ShadowSurface dtor 0054aaef (folded with Array<Face>)'),
    (0x551400, '??$?0VVector2@G3D@@@VAR@G3D@@QAE@ABV?$Array@VVector2@G3D@@@1@V?$ReferenceCountedPointer@VVARArea@G3D@@@1@@Z',
     'Mesh.cpp VAR static 00548df7 on texCoordArray 00973934 (the Vector3 arrays 009738f0 / 009738fc / 00973928 use '
     'the Vector3 instantiation 00502910); element size 8 pushed at 0055143b'),
]
ROOTS_PENDING = [
    (0x552300, '?renderShadows@' + CHUNK + 'UAEXPAVRenderDevice@G3D@@ABVGLight@5@_NM@Z',
     'AggregateChunk vtable 0082d258 slot 2 (render-scene receipt binds it as an external there)'),
    (0x552270, '?makeMesh@' + CHUNK + 'QAEXXZ', 'Bucket member 0053fe10 after new AggregateChunk 0x108 / ctor 00551f30'),
]
READ_ONLY_ROOTS = [(a, s, '%s root: %s' % (w, e)) for a, s, w, e in T540['ROOTS']] + \
    [(a, s, 'unit548 root: ' + e) for a, s, e in T548['ROOTS_MAIN']]

# ---- externals: the address the original instruction uses (call site in parentheses) --------------------------------
# The read-only units' EXTERNAL maps (call-site evidence in their recorders) bind the bodies they reference; rows this
# closure proves take precedence over them (own rows are matched first).
EXTERNAL = {}
for table in (T540['EXTERNAL'], T548['EXTERNAL']):
    for k, v in table.items():
        if v is not None:
            assert EXTERNAL.setdefault(k, v) == v, (k, hex(v))
EXTERNAL.update({
    # AppUnit550 main build: G3D RenderDevice / Array members compiled elsewhere (folded), bound by call site
    '?internalSendIndices@RenderDevice@G3D@@AAEXW4Primitive@12@IHPBX@Z': 0x47b450,  # 0055287d
    '?setVARAreaMilestone@RenderDevice@G3D@@AAEXXZ': 0x479c30,  # 00552887
    '?countTriangles@RenderDevice@G3D@@AAEXW4Primitive@12@H@Z': 0x477f00,  # 00552895
    '?resize@?$Array@VVector3@G3D@@@G3D@@QAEXH@Z': 0x503100,  # 005527bc
    '?resize@?$Array@I@G3D@@QAEXH@Z': 0x4807d0,  # 005527dc
    '?resize@?$Array@G@G3D@@QAEXH@Z': 0x479a60,  # 0055281c
    '?getCArray@?$Array@G@G3D@@QBEPBGXZ': 0x71f210,  # 00552844
    '?size@?$Array@G@G3D@@QBEHXZ': 0x442cd0,  # 00552838
    '?alignedFree@System@G3D@@SAXPAX@Z': 0x507d20,  # 005516fe
    # VAR<Vector2>(const Array<Vector2>&, VARAreaRef) 00551400 callees (the VAR / RCP<VARArea> bodies are shared)
    '??0?$ReferenceCountedPointer@VVARArea@G3D@@@G3D@@QAE@XZ': 0x4f0810,  # 00551432 (VAR::area default ctor)
    '??0?$ReferenceCountedPointer@VVARArea@G3D@@@G3D@@QAE@ABV01@@Z': 0x4f0820,  # 0055144d (by-value area copy)
    '?init@VAR@G3D@@AAEXPBXHV?$ReferenceCountedPointer@VVARArea@G3D@@@2@II@Z': 0x489490,  # 00551478
    '??1?$ReferenceCountedPointer@VVARArea@G3D@@@G3D@@QAE@XZ': 0x502a70,  # 00551487 (by-value area parameter)
})
DATA_EXTERNAL = {'?aggregatedChunkCount@RenderStats@@2HA', '___security_cookie', '__TI2?AVbad_alloc@std@@',
                 '__TI3?AVlength_error@std@@', '__TI3?AVout_of_range@std@@'} | \
    {k for k in EXTERNAL if k.startswith('?minSize@') or k.startswith('??_B')}
EXTERNAL_PENDING = dict(EXTERNAL)
EXTERNAL_PENDING.update({
    # renderShadows 00552300 / makeMesh 00552270 callees (call site in parentheses)
    '??9GLight@G3D@@QBE_NABV01@@Z': 0x5144f0,  # 00552340
    '??4GLight@G3D@@QAEAAV01@ABV01@@Z': 0x4769a0,  # 0055235d
    '??C?$ReferenceCountedPointer@VMaterialBase@RenderBase@RBX@@@G3D@@QBEPAVMaterialBase@RenderBase@RBX@@XZ': 0x71f210,  # 0055238d
    '??0?$Array@VVector3@G3D@@@G3D@@QAE@XZ': 0x481520,  # 005523db
    '?xyz@Vector4@G3D@@QBE?AVVector3@2@XZ': 0x514890,  # 00552418 / 0055244c
    '?direction@Vector3@G3D@@QBE?AV12@XZ': 0x4fab70,  # 0055241f / 00552453
    '??GVector3@G3D@@QBE?AV01@XZ': 0x483410,  # 00552426
    '??DVector3@G3D@@QBE?AV01@M@Z': 0x485360,  # 0055242d
    '?append@?$Array@VVector3@G3D@@@G3D@@QAEXABVVector3@2@@Z': 0x502f50,  # 00552438
    '??C?$ReferenceCountedPointer@VMesh@RenderBase@RBX@@@G3D@@QBEPAVMesh@RenderBase@RBX@@XZ': 0x71f210,  # 0055248f
    '?computeDirectionalShadowVolume@' + MESH + 'QBEXABVCoordinateFrame@G3D@@ABVVector3@5@AAV?$Array@I@5@AAV?$Array@VVector3@G3D@@@5@_N@Z': 0x549050,  # 00552496
    '?size@?$Array@VVector3@G3D@@@G3D@@QBEHXZ': 0x442cd0,  # 005524a0 / 0055253f
    '?size@?$Array@I@G3D@@QBEHXZ': 0x442cd0,  # 005524bc / 005525db
    '??A?$Array@I@G3D@@QAEAAIH@Z': 0x47f7e0,  # 00552503
    '??A?$Array@G@G3D@@QAEAAGH@Z': 0x478230,  # 0055251a
    '?create@VARArea@G3D@@SA?AV?$ReferenceCountedPointer@VVARArea@G3D@@@2@IW4UsageHint@12@@Z': 0x4763d0,  # 0055254c
    '??0?$ReferenceCountedPointer@VVARArea@G3D@@@G3D@@QAE@ABV01@@Z': 0x4f0820,  # 00552568
    '??$?0VVector3@G3D@@@VAR@G3D@@QAE@ABV?$Array@VVector3@G3D@@@1@V?$ReferenceCountedPointer@VVARArea@G3D@@@1@@Z': 0x502910,  # 0055257e
    '??4VAR@G3D@@QAEAAV01@ABV01@@Z': 0x502ab0,  # 005525ac
    '??1VAR@G3D@@QAE@XZ': 0x502a70,  # 005525bb
    '??1?$ReferenceCountedPointer@VVARArea@G3D@@@G3D@@QAE@XZ': 0x502a70,  # 005525ca
    '?beginIndexedPrimitives@RenderDevice@G3D@@QAEXXZ': 0x477fb0,  # 005525e7 / 00552639
    '?setVertexArray@RenderDevice@G3D@@QAEXABVVAR@2@@Z': 0x479820,  # 005525fc / 0055264e
    '??$sendIndices@I@RenderDevice@G3D@@QAEXW4Primitive@01@ABV?$Array@I@1@@Z': 0x5029c0,  # 00552612
    '?endIndexedPrimitives@RenderDevice@G3D@@QAEXXZ': 0x4796a0,  # 0055261a / 0055266d
    '?aggregate@' + MESH + 'SA?AV?$ReferenceCountedPointer@VMesh@RenderBase@RBX@@@G3D@@ABV?$vector@V?$ReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@V?$allocator@V?$ReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@@std@@@std@@AAVCoordinateFrame@5@AAM@Z': 0x547610,  # 005522b4
    '??4?$ReferenceCountedPointer@VMesh@RenderBase@RBX@@@G3D@@QAEABV01@ABV01@@Z': 0x4d7560,  # 005522d6
    '??1?$ReferenceCountedPointer@VMesh@RenderBase@RBX@@@G3D@@QAE@XZ': 0x502a70,  # 005522e5
    '?shadowVertex@?8??renderShadows@' + CHUNK + 'UAEXPAVRenderDevice@G3D@@ABVGLight@6@_NM@Z@4V?$Array@VVector3@G3D@@@6@A': 0x9739bc,  # 005523d6 / 005523f4
    '?$S1@?8??renderShadows@' + CHUNK + 'UAEXPAVRenderDevice@G3D@@ABVGLight@6@_NM@Z@4IA': 0x9739c8,  # 005523b7 / 005523ca
    '??__FshadowVertex@?8??renderShadows@' + CHUNK + 'UAEXPAVRenderDevice@G3D@@ABVGLight@5@_NM@Z@YAXXZ': 0x7fc700,  # 005523e0
    '_atexit': 0x6a17af,  # 005523e5
})
DATA_EXTERNAL_PENDING = DATA_EXTERNAL | {k for k in EXTERNAL_PENDING if k.startswith('?shadowVertex@') or
                                         k.startswith('?$S1@')}

# ---- rows split at a catch(...) funclet: compared joined (bounds evidence), traversed, never counted ----------------
JOINS = {0x5441a0: 0x54423c, 0x545260: 0x54533c, 0x5453e0: 0x54547c, 0x545550: 0x54562c,   # app-unit540 bounds
         0x550a30: 0x550acc, 0x552ff0: 0x55305e, 0x553520: 0x553585, 0x553710: 0x5537cb}

TARGET = {}


def target_of(address):
    if address not in TARGET:
        if address in JOINS:
            data, relocs = b'', []
            for a in (address, JOINS[address]):
                body, refs, _ = match.target('2008-06', '%08x' % a)
                assert address + len(data) == a, ('rows not contiguous', hex(a))
                relocs += [r + len(data) for r in refs]
                data += body
            TARGET[address] = (data, relocs)
        else:
            body, refs, _ = match.target('2008-06', '%08x' % address)
            TARGET[address] = (body, refs)
    return TARGET[address]


def load_bodies(keys):
    bodies = {}
    for key in keys:
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
            bodies.setdefault(n, (key, b, r, rel))
    return bodies


INDEX = {k: (Path(v).read_bytes(), match._coff_data_index(Path(v).read_bytes())) for k, v in OBJ.items()}


class Closure:
    def __init__(self, keys, roots, external, data_external):
        self.external, self.data_external = external, data_external
        self.bodies = load_bodies(keys)
        self.used, self.unbound = set(), []
        self.proven, self.aliases, self.why, self.not_exact = {}, {}, {}, {}
        queue = deque()
        for address, symbol, evidence in roots:
            assert symbol in self.bodies, ('root symbol missing', symbol)
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
                    if value in FUNCTIONS and sym in self.bodies and not nb.LOCAL_EH.match(sym):
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
        return len(target) == len(body) and match.exact_match(target, target_refs, body, refs)

    def verify(self, address, symbol):
        which, body, refs, rel = self.bodies[symbol]
        target, _ = target_of(address)
        raw, (sections, symbols, definitions, _) = INDEX[which]
        verified, local = {}, set()
        for offset, sym, kind in rel:
            if kind == 20:
                value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            else:
                start, section = definitions[symbol]
                code = raw[sections[section][4] + start:]
                value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) \
                    & 0xffffffff
            if nb.LOCAL_EH.match(sym) or sym.startswith('__tryend$'):
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
                literal = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
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
            elif sym in self.external and (self.external[sym] == value or not DISCOVER):
                assert self.external[sym] == value, (symbol, sym, hex(value), hex(self.external[sym]))
                how = 'external' + (' (evidence name)' if names.get(value, '') == sym else '')
                self.used.add(sym)
            else:
                self.unbound.append("    %r: %#x,   # %s in %s at %08x" % (sym, value, names.get(value, '')[:50],
                                                                          symbol[:50], address + offset))
                continue
            verified[sym] = '%s (%s)' % (hex(value), how)
        return {'size': len(body), 'target_size': len(target), 'verified_targets': verified, 'local_eh': sorted(local)}

    def check(self, label):
        if DISCOVER:
            print('==', label)
            print('\n'.join(sorted(set(self.unbound))))
            for a, (s, r) in sorted(self.not_exact.items()):
                print('NOT EXACT %08x %s (%s)' % (a, s[:140], r))
            print('PROVEN', len(self.proven), 'in range', sorted('%08x' % a for a in self.proven if RANGE[0] <= a < RANGE[1]))
            return
        assert not self.unbound, '\n'.join(self.unbound)
        for symbol in self.used:
            address = self.external[symbol]
            assert address in FUNCTIONS or original.imported(address) is not None or symbol in self.data_external, \
                (symbol, hex(address))


MAIN_KEYS = ['unit', 'unit540', 'aggregating', 'unit548']
MAIN = Closure(MAIN_KEYS, READ_ONLY_ROOTS + ROOTS_UNIT, EXTERNAL, DATA_EXTERNAL)
MAIN.check('main')
PENDING = Closure(['pending'] + MAIN_KEYS[1:], READ_ONLY_ROOTS + ROOTS_UNIT + ROOTS_PENDING, EXTERNAL_PENDING,
                  DATA_EXTERNAL_PENDING)
PENDING.check('pending')
if DISCOVER:
    sys.exit(0)
for address, symbol, evidence in ROOTS_UNIT:
    assert address in MAIN.proven and symbol in MAIN.aliases[address], ('own root not exact', '%08x' % address, symbol)
for address, symbol, evidence in ROOTS_PENDING:
    assert address in PENDING.proven and symbol in PENDING.aliases[address], ('pending root not exact', '%08x' % address)
# every external this group added is used by a proven body
OWN_EXTERNAL = [k for k in EXTERNAL if k not in T540['EXTERNAL'] and k not in T548['EXTERNAL']]
assert not set(OWN_EXTERNAL) - MAIN.used, sorted(set(OWN_EXTERNAL) - MAIN.used)
OWN_EXTERNAL_PENDING = [k for k in EXTERNAL_PENDING if k not in EXTERNAL]
assert not set(OWN_EXTERNAL_PENDING) - PENDING.used, sorted(set(OWN_EXTERNAL_PENDING) - PENDING.used)
# the main proven rows are a subset of the pending ones with the same symbols (the pending build only adds)
assert all(PENDING.proven.get(a) == s for a, s in MAIN.proven.items()), 'pending build changed a main row'

# ---- vtable evidence (original bytes; this group compiles no vtable) ------------------------------------------------
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
rtti, at = original.vtable_class(0x82d258)
assert rtti == '.?AVAggregateChunk@RenderBase@RBX@@' and at == 0, (rtti, at)
assert d(0x82d258 + 2 * 4) == 0x552300, hex(d(0x82d258 + 8))   # slot 2 renderShadows
VTABLE = {'AggregateChunk vtable 0082d258': 'RTTI .?AVAggregateChunk@RenderBase@RBX@@ offset 0; slot 2 (+0x8) holds renderShadows (the '
                      'pending row of this receipt); no vtable is compiled by the main build of this group'}


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
in_range = lambda a: RANGE[0] <= a < RANGE[1]
joined = set(JOINS) | set(JOINS.values())
counted = sorted(a for a in MAIN.proven if in_range(a) and a not in elsewhere and a not in joined)
proven_elsewhere = sorted(a for a in MAIN.proven if in_range(a) and a in elsewhere)
pending_only = sorted(a for a in PENDING.proven if in_range(a) and a not in MAIN.proven)
range_functions = sorted(a for a in FUNCTIONS if in_range(a))
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if in_range(a)}
assert not set(counted) & set(elsewhere)
assert not set(pending_only) & set(elsewhere), 'a pending row is counted elsewhere'

rows_out = [dict({'address': '%08x' % a, 'symbol': MAIN.proven[a], 'folded_symbols': MAIN.aliases[a][1:],
                  'identity': MAIN.why[a], 'exact': True}, **MAIN.checked[a]) for a in counted]
pending_out = [dict({'address': '%08x (pending-build-only, not counted)' % a, 'symbol': PENDING.proven[a],
                     'identity': PENDING.why[a], 'exact': False, 'reason': 'exact only against the generated pending '
                     'headers (see proposals)'}, **PENDING.checked[a]) for a in pending_only]
support_out = ['%08x %s (support row: %s)' % (a, MAIN.proven[a][:90], 'counted by ' + ', '.join(sorted(set(elsewhere[a]))))
               for a in proven_elsewhere]
BOUNDS = []
for head, tail in sorted(JOINS.items()):
    if head in MAIN.proven:
        body = MAIN.bodies[MAIN.proven[head]][1]
        BOUNDS.append('%08x + %08x: one function (%s) with its catch(...) funclet; the compiled body (%d B) is '
                      'relocation-masked exact against the joined extent. Not counted (extent fix needed; no '
                      'bounds.json change).' % (head, tail, MAIN.proven[head][:80], len(body)))

# ---- unit map: every row of the range not counted here, by unit, with the reason (text, never a bare address) ------
GROUPS = [
    ((0x550000, 0x551730), 'RenderBase Mesh.cpp / AggregatingSceneManager.cpp COMDAT tail'),
    ((0x551730, 0x551f30), 'TextureProxy factories and members (render-material owner)'),
    ((0x551f30, 0x553910), 'RenderBase AggregateChunk.cpp'),
    ((0x553910, 0x554000), 'util/Name.cpp and the ICF-shared std::map _Tree helpers (Name owner, core header)'),
]
REASONS = [
    ({0x5500a0, 0x550880, 0x550a30, 0x550acc, 0x550b50, 0x550d60, 0x550ea0},
     'std::map<unsigned int, 4-byte> of the Mesh.cpp sub-mesh builder 00549a50 (local map at ebp-0x3c, operator[] '
     '0054c2d0, erase 0054f340, _Insert 0054f3f0, unsigned key compare 0044f2b0 sbb): the mapped type (int or '
     'unsigned int) is not provable from the bytes, so the instantiation is not claimed'),
    ({0x550bd0, 0x550c00, 0x550e50, 0x550f60, 0x5514c0, 0x5514b0, 0x5515b0, 0x5515e0},
     'reached only from ~Mesh 00548a90 through 0054b3a0 / 0054b520 (the sub-mesh name map holder, types undeclared '
     'in ViewNew/RenderBaseMesh.h; app-unit548 map)'),
    ({0x550c20, 0x550ef0, 0x550f90, 0x550fb0},
     'G3D::Array of a 0x18-byte element (realloc 00550c20 from resize 0054fc70, element copy 00550ef0 with an '
     'Array<int>-shaped member copy 00550f90 / 00550fb0); reached from the Mesh.cpp static 00548150 and 007b9940, '
     'element type not derived'),
    ({0x551010}, 'Mesh.cpp static (953 B) called only by the unbuilt static 00548150'),
    ({0x5513d0}, 'VAR::set-shaped template on 009738d0 (00548c9b): three arguments to 004896b0, the donor G3D '
     'VAR::set(int, const T&) passes four; the 2008 VAR declaration is not available'),
    ({0x551670}, 'implicit MeshAlg::Geometry dtor (atexit 007fc650 on Mesh::visibleGeometry 009738f0, also 0054c4b0): '
     'needs the Mesh static pool declarations of the app-unit548 proposal'),
    ({0x551730, 0x551820, 0x551920, 0x551a30},
     'TextureProxy / Material factories ("Invalid factory type"; createMaterial declared by RenderLib/'
     'AggregateChunk2008.h, render-mode global 00942ec4 unnamed): render-material / render-scene owners'),
    (set(range(0x5528a0, 0x553910)),
     'AggregateChunk.cpp helpers reached from the unbuilt Bucket member 0053fe10 (00552bb0 / 00552a60 / 005528e0 / '
     '005528a0 / 00552d50): a vector of a 40-byte cell (Vector3 ctor 004377b0, vector ctor 00540560; _Buy 00553160, '
     '_Construct_n 00552ff0) and a second 4-byte-element vector whose COMDATs (_Destroy 005467b0, _Tidy 005470a0) '
     'are not the vector<RCP<Chunk> > ones (005414a0 / 005414d0, app-unit540): element types undeclared. Tried and '
     'rejected here as vector<RCP<Chunk> > (one-address-per-symbol conflict).'),
    (set(range(0x553910, 0x554000)), 'util/Name.cpp (Name::declare 00553f90 / lookup / getNullName, name-map mutex '
     '00553910) and the ICF-shared std::map _Tree _Lbound / erase / dtor bodies with 40+ callers across units: '
     'Name owner (core util/Name.h), not library code of this unit; not built here'),
]
unit_map_rows = []
for a in range_functions:
    if a in counted or a in pending_only or a in range_counted:
        continue
    unit = next(n for (lo, hi), n in GROUPS if lo <= a < hi)
    reason = next((r for s, r in REASONS if a in s), 'not attempted')
    unit_map_rows.append('%08x %s: %s' % (a, unit, reason))

UNIT_MAP = {
    'RenderBase COMDAT tail 00550000..0055172f': (
        'The end of the COMDAT instantiations of the RenderBase AggregatingSceneManager.cpp (0053f0d0..) and Mesh.cpp '
        '(00547440..) units: std::set<WeakRCP<Chunk> > / std::map<BucketKey, RCP<Bucket> > _Tree members and their '
        'allocator helpers (callers 00540000..0054ffff), the Mesh.cpp G3D::Array / VAR instantiations '
        '(Array<Vector2> ctor + init on texCoordArray 00973934 from the dynamic initializer 007f26e0, '
        'VAR<Vector2> 00551400 with _GLFormat<Vector2> 005514a0, the folded Array<Edge / Face> dtor 005516d0), the '
        'MeshAlg::Geometry dtor 00551670 and the sub-mesh maps of Mesh.cpp. Counted here where the call-graph '
        'closure from the app-unit540 / app-unit548 roots (or a cited call site) proves the instantiation.'),
    'TextureProxy 00551730..00551f2f': (
        'TextureProxy factories 00551730 / 00551820 / 00551920 / 00551a30 and the Render / RenderNew TextureProxy, '
        'TextureProxyBase members (render-material-working.json counts them from 00551b30). Not built here.'),
    'RenderBase AggregateChunk.cpp 00551f30..0055390f': (
        'AggregateChunk ctor 00551f30, dtor 00552160, makeMesh 00552270, renderShadows 00552300 (vtable 0082d258 '
        'slot 2), the inline virtual slots 00552690..00552780 (render-scene counts them), then the COMDATs of this '
        'unit: Array<Vector3 / unsigned int / unsigned short>::clear, RenderDevice::sendIndices<unsigned short>, '
        'Array<unsigned short> ctor 005527f0, and the vector instantiations of the Bucket helpers 005528a0..'
        '005538b0. makeMesh / renderShadows are exact only in the pending build (proposals).'),
    'util/Name.cpp 00553910..': ('Name owner (core header util/Name.h); continues past 00554000 (app-unit54c map).'),
    'excluded / library code': (
        'No CRobloxApp / CMainFrame / CRobloxDoc / CRobloxView row. The STL / G3D bodies are Roblox-instantiated '
        'templates of the RenderBase units (element types RBX::RenderBase::* or the Mesh statics) or ICF-shared '
        'copies referenced only from those units; no separately linked library object (Ogre, boost, CRT, MFC, XTP, '
        'zlib, Lua, RakNet) lies in the range.'),
}
REJECTED = {
    'std::vector<RCP<Chunk> > as the element type of the AggregateChunk.cpp helper vectors (back 00552e90, pop_back '
    '00552ec0, operator[] 00552e60, copy ctor 00553710)': (
        'bytes exact, but the closure binds vector<RCP<Chunk> >::_Destroy / _Tidy to 005467b0 / 005470a0 while '
        'app-unit540 proves them at 005414a0 / 005414d0 (one address per symbol): a different 4-byte element type; '
        'not claimed'),
}
PROPOSALS = {
    'ViewNew/RenderBaseMesh.h (ViewNew owner; adds to the app-unit548 static vertex pool proposal)': (
        'Declare in class Mesh: `void computeDirectionalShadowVolume(const G3D::CoordinateFrame&, const G3D::Vector3&, '
        'G3D::Array<unsigned int>&, G3D::Array<G3D::Vector3>&, bool) const;` (00549050: thiscall, ret 0x14; '
        'renderShadows 00552496 pushes caps, the static shadowVertex 009739bc, shadowIndexArray +0xd8, the light '
        'vector and cframe()) and `static G3D::ReferenceCountedPointer<Mesh> aggregate(const std::vector<'
        'G3D::ReferenceCountedPointer<Chunk> >&, G3D::CoordinateFrame&, float&);` (00547610: cdecl, hidden return, '
        'makeMesh 005522b4 pushes radius +0x1c, _cframe +0x30, components +0xf0; add esp 0x10). Verified against '
        'out/native-layouts/app-unit550/pending/ViewNew/RenderBaseMesh.h.'),
    'RenderLib/AggregateChunk2008.h (render-scene owner)': (
        'Declare `void makeMesh();` in AggregateChunk (00552270: thiscall, no arguments, plain ret; called by the '
        'Bucket member 0053fe10 after new AggregateChunk / ctor 00551f30). With it and the RenderBaseMesh.h '
        'declarations, AggregateChunk::makeMesh 00552270 and renderShadows 00552300 (900 B, the donor body with '
        'append instead of push_back and two empty debugAsserts) are relocation-masked exact with every target '
        'verified (pending build) and could be counted.'),
}
receipt = {
    'class': 'RBX::RenderBase AggregateChunk.cpp / Mesh.cpp template rows of the application range 00550000..00554000 '
             '(2008-06), inactive',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM), /Od /Ob0 /GS (RenderBase library profile) + Ogre 1.4.5 client headers',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): nb.sha(p) for p in
                [Path(__file__).resolve(), SOURCE] + list(READ_ONLY.values()) + HEADERS +
                [T / 'record_native_app_unit540_2008.py', T / 'record_native_app_unit548.py']},
    'pending_headers': {str(p.relative_to(ROOT)).replace('\\', '/'): nb.sha(p) for p in
                        (PENDING_DIR / 'ViewNew/RenderBaseMesh.h', PENDING_DIR / 'RenderLib/AggregateChunk2008.h')},
    'objects': {k: nb.sha(v) for k, v in OBJ.items()},
    'vtables': VTABLE,
    'unit_map': UNIT_MAP,
    'range_functions': len(range_functions),
    # 'ADDR counted by RECEIPT' text, never a quoted bare address of a row this receipt does not count
    'range_rows_counted_by_other_receipts': ['%08x counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()],
    'range_rows_not_built': unit_map_rows,
    'rows': rows_out,
    'support_rows_not_counted': support_out,
    'pending_build_only': pending_out,
    'bounds_evidence': BOUNDS,
    'exact_function_rows': ['%08x' % a for a in counted],
    'rejected': REJECTED,
    'proposals': PROPOSALS,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
text = json.dumps(receipt, indent=2) + '\n'
quoted = set(re.findall(r'"([0-9a-f]{8})"', text))
assert quoted <= {'%08x' % a for a in counted}, sorted(quoted - {'%08x' % a for a in counted})[:10]
RECEIPT.write_text(text)
print('PASS app-unit550: %d counted exact rows; %d pending-build-only; %d support rows counted elsewhere; %d bounds '
      'joins; %d range rows, %d counted elsewhere, %d not built'
      % (len(counted), len(pending_out), len(support_out), len(BOUNDS), len(range_functions), len(range_counted),
         len(unit_map_rows)))
print(' '.join('%08x' % a for a in counted))
