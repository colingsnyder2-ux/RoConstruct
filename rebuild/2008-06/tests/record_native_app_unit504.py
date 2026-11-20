"""Verify the inactive 2008-06 native rows of the application range 00504000..00508000, and record the unit map of the
range (boundary evidence in the receipt's `unit_map`; rows counted by other receipts are listed there as text).

Unit map summary (details in UNIT_MAP below):
  * 00504000..005058ef: the Render::RenderScene unit (RenderLib RenderScene.cpp / RenderSurface.cpp): render helpers,
    render 00504bf0, RenderSceneBase / RenderScene ctors and the RenderSurface sort procs and std::sort helpers. The
    members and helpers already built are counted by tests/record_native_render_scene.py (render-scene owner); the
    rest is blocked there (render draw path) or undeclared (proposals).
  * 005058f0..00507178: RenderLib EffectSettings.cpp: the `brighter` light predicate, the std::sort<GLight*, brighter>
    helpers, EffectSettings::getToneMap / getDepthBlur / update and the inline COMDATs the linker took from this object
    (implicit ~ToneMap / ~DepthBlur, G3D::Lighting / Array<GLight> assignment). Built here.
  * 00507180..0050783f: RenderLib DepthBlur.cpp: DepthBlur::allocateTextures / apply / DepthBlur() and the G3D header
    inlines it emits (Texture::createEmpty overload, Shader ctor / dtor / fromStrings / preserve-state accessors,
    the Table<std::string, Arg> and folded scalar deleting destructors). Built here.
  * 00507840..: G3D 6.09 library code (System.cpp: processor extensions, memcpyMMX / memfill, BufferPool, System::free /
    alignedFree; TextOutput var helpers). Never recovered here.

Builds: native-classes/AppUnit504EffectSettings.cpp and native-classes/AppUnit504DepthBlur.cpp with the document-swap
flags, VS2008 RTM 21022, /fp:fast (the RenderSceneBase unit profile of tests/record_native_render_scene.py), both from
the new native-headers/AppUnit504/RenderEffects.h (DepthBlur and EffectSettings; no donor header has that path, so
nothing is shadowed). No pending build: no body here needs a missing declaration.

Row identity is proven by a call-graph closure from the root rows (each relocation-masked exact at the address its
evidence names): every REL32 call target of an exact row binds to the symbol the compiled instruction references; that
symbol's compiled body must be exact there, and so on. Each symbol binds to one address across both objects; an
address may carry several symbols (identical-code folding), each of whose bodies must be exact there. Every REL32 /
DIR32 target of every proven row is verified: imports by DLL export name, constants by bytes, strings by bytes, vtables
by original RTTI names, own (proven) rows of either object, and the remaining externals by the explicit EXTERNAL map
(call-site evidence in comments). Counted rows are the RBX rows and the Roblox-instantiated sort templates inside the
range that no other receipt counts; G3D header inlines and compiler-generated members of G3D classes are verified
support rows (library code), not counted.
Writes work/2008-06/shared-layouts/app-unit504-working.json. Never writes a quoted bare address of a row it does not
count (some recorders treat any such string in another receipt as counted there).
Set NATIVE_APP_UNIT504_DISCOVER=1 to list unbound targets instead of asserting.
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
HDR = R / 'native-headers'
OUT = nb.OUT / 'app-unit504'
OUT.mkdir(parents=True, exist_ok=True)
SOURCES = {
    'effects': R / 'native-classes/AppUnit504EffectSettings.cpp',
    'depthblur': R / 'native-classes/AppUnit504DepthBlur.cpp',
}
HEADERS = [HDR / 'AppUnit504/RenderEffects.h']
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT504_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit504-working.json'
RANGE = (0x504000, 0x508000)


def build(name, src):
    obj = OUT / (name + '.obj')
    flags = nb.flags() + ['/fp:fast', '/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log[-4000:]
    return obj, flags


OBJ, FLAGS = {}, {}
for key, src in SOURCES.items():
    OBJ[key], FLAGS[key] = build('NativeAppUnit504_' + key, src)

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
FUNCTIONS = {int(json.loads(l)['addr'], 16): json.loads(l)['size'] for l in
             (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines() if l.strip()}

ES = 'EffectSettings@Render@RBX@@'
GL = 'PAVGLight@G3D@@'
PRED = 'P6A_NABVGLight@G3D@@0@Z'

# ---- identity roots: (object, address, symbol pattern, evidence) ---------------------------------------------------
# A pattern is a symbol prefix plus optional substrings; it must select exactly one compiled symbol of that object, whose body must be
# exact at the address.
ROOTS = [
    ('effects', 0x506dd0, ['?update@' + ES],
     'Render::RenderScene::setThrottle 00502df4 / setLighting 00502ec8 call it with this = RenderScene +0x2d4 '
     '(EffectSettings member, render-scene layout probe); ret 0x20'),
    ('effects', 0x5058f0, ['?brighter@Render@RBX@@'],
     'its address is pushed as the std::sort predicate by update 00506f5d / 00506fd5'),
    ('effects', 0x506b80, ['?getToneMap@' + ES + 'SA'],
     'called by update 0050704d / 0050705f / 0050713c (ToneMap methods 007b1650 / 007b2520 / 007b1580 on the result)'),
    ('effects', 0x506c00, ['?getDepthBlur@' + ES + 'SA'],
     'new 0xc and the DepthBlur ctor 00507740; guard 009728e4; its atexit destructor 007fc5d0'),
    ('effects', 0x7fc5b0, ['??__FtoneMap@'], 'atexit argument pushed by getToneMap 00506bcf'),
    ('effects', 0x7fc5d0, ['??__FdepthBlur@'], 'atexit argument pushed by getDepthBlur 00506c4f'),
    ('depthblur', 0x507740, ['??0DepthBlur@Render@RBX@@QAE@XZ'],
     'evidence name; called by getDepthBlur 00506c46 after new 0xc'),
    ('depthblur', 0x507420, ['?apply@DepthBlur@Render@RBX@@'],
     'evidence name; caller Render::RenderScene::render 00504bf0 (blocked there)'),
    # G3D::Shader vtable 008274d4 (RTTI .?AVShader@G3D@@, stored by the inline Shader ctor 00507527): slots 0..2.
    ('depthblur', 0x507720, ['??_GShader@G3D@@'], 'G3D::Shader vtable 008274d4 slot 0 (ICF-shared scalar deleting dtor)'),
    ('depthblur', 0x5075d0, ['?setPreserveState@Shader@G3D@@'], 'G3D::Shader vtable 008274d4 slot 1 (evidence name)'),
    ('depthblur', 0x5075e0, ['?preserveState@Shader@G3D@@'], 'G3D::Shader vtable 008274d4 slot 2 (evidence name)'),
    # Table<std::string, VertexAndPixelShader::ArgList::Arg> vtable 008274a4 (stored by the Shader ctor 0050754e).
    ('depthblur', 0x5074c0, ['??_G?$Table@V?$basic_string@'], 'G3D::Table<std::string, Arg> vtable 008274a4 slot 0'),
]
# ---- externals: the address the original instruction uses (call site in parentheses) --------------------------------
EXTERNAL = {
    # G3D 6.09 library functions and the G3D template / inline COMDATs other units emitted (outside the range; the
    # closure stops there), called from the bodies built here.
    '?create@Lighting@G3D@@SA?AV?$ReferenceCountedPointer@VLighting@G3D@@@2@XZ': 0x503960,  # update 00506e94
    '?append@?$Array@VGLight@G3D@@@G3D@@QAEXABVGLight@2@@Z': 0x503000,  # update 00506f96
    '?resize@?$Array@VGLight@G3D@@@G3D@@QAEXH_N@Z': 0x5026d0,  # update 00506fad / 00506fff, Array op= 00505f4f
    '??4LightingParameters@G3D@@QAEAAV01@ABV01@@Z': 0x501d80,  # update 0050715a
    '?ReferenceCountedObject_zeroWeakPointers@ReferenceCountedObject@G3D@@QAEXXZ': 0x45ad90,  # ~ToneMap 00505b10
    '??4GLight@G3D@@QAEAAV01@ABV01@@Z': 0x4769a0,  # evidence name; std::sort helpers (_Insertion_sort1 00506890)
    '??0GLight@G3D@@QAE@ABV01@@Z': 0x477c50,  # evidence name; _Unguarded_partition 00505ff0
    # ReferenceCountedPointer<T>::setPointer / ~ReferenceCountedPointer: ICF-shared COMDATs (evidence names
    # setPointer<Shader> / ~RCP<Shader>) bound once per instantiation the bodies here reference.
    '?setPointer@?$ReferenceCountedPointer@VTexture@G3D@@@G3D@@AAEXPAVTexture@2@@Z': 0x598fa0,  # Lighting op= 00506aa5
    '?setPointer@?$ReferenceCountedPointer@VShader@G3D@@@G3D@@AAEXPAVShader@2@@Z': 0x598fa0,  # DepthBlur() 005077f2
    '?setPointer@?$ReferenceCountedPointer@VVertexAndPixelShader@G3D@@@G3D@@AAEXPAVVertexAndPixelShader@2@@Z': 0x598fa0,
    '??1?$ReferenceCountedPointer@VShader@G3D@@@G3D@@QAE@XZ': 0x502a70,  # DepthBlur() 00507800
    '??1?$ReferenceCountedPointer@VTexture@G3D@@@G3D@@QAE@XZ': 0x502a70,  # ~ToneMap 00505b2b (eh vector dtor argument)
    '?freeMemory@?$Table@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@VArg@ArgList@'
    'VertexAndPixelShader@G3D@@@G3D@@AAEXXZ': 0x486ba0,  # evidence name; Table ??_G 005074c0
    '??0ToneMap@G3D@@QAE@XZ': 0x7b29c0,  # getToneMap 00506bc6 after new 0x18 (G3D ToneMap.cpp)
    '?setEnabled@ToneMap@G3D@@QAEX_N@Z': 0x7b1650,  # update 00507054
    '?prepareLighting@ToneMap@G3D@@QBE?AV?$ReferenceCountedPointer@VLighting@G3D@@@2@ABV32@@Z': 0x7b2520,  # 00507066
    '?prepareLightingParameters@ToneMap@G3D@@QBE?AVLightingParameters@2@ABV32@@Z': 0x7b1580,  # update 00507143
    '?glGetInteger@G3D@@YAHI@Z': 0x4837e0,  # update 00506e1e (GL_MAX_LIGHTS 0xd31) / 00506ebe (GL_STENCIL_BITS 0xd57)
    '?depth@TextureFormat@G3D@@SAPBV12@H@Z': 0x483820,  # allocateTextures 0050725c (push 0)
    '?video@Settings@Texture@G3D@@SAABV123@XZ': 0x472b20,  # allocateTextures 00507253 / 0050730d
    '?createEmpty@Texture@G3D@@SA?AV?$ReferenceCountedPointer@VTexture@G3D@@@2@HHABV?$basic_string@DU?$char_traits@D'
    '@std@@V?$allocator@D@2@@std@@PBVTextureFormat@2@W4WrapMode@12@W4InterpolateMode@12@W4Dimension@12@W4DepthReadMode'
    '@12@M@Z': 0x474950,  # the inline createEmpty overload 005071be forwards to the G3D Texture.cpp one
    '?set@ArgList@VertexAndPixelShader@G3D@@QAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@ABV?$'
    'ReferenceCountedPointer@VTexture@G3D@@@3@@Z': 0x486eb0,  # allocateTextures 005073bf / 005073f4
    '?copyFromScreen@Texture@G3D@@QAEXABVRect2D@2@_N@Z': 0x4739f0,  # apply 0050745d / 0050746c
    '?getViewport@RenderDevice@G3D@@QBE?AVRect2D@2@XZ': 0x476d60,  # apply 00507442
    '?push2D@RenderDevice@G3D@@QAEXXZ': 0x47d3a0,  # apply 00507436
    '?pop2D@RenderDevice@G3D@@QAEXXZ': 0x47d360,  # apply 005074ad
    '?setShader@RenderDevice@G3D@@QAEXABV?$ReferenceCountedPointer@VShader@G3D@@@2@@Z': 0x478f20,  # apply 00507474
    '?fastRect2D@Draw@G3D@@SAXABVRect2D@2@PAVRenderDevice@2@ABVColor4@2@@Z': 0x7b0170,  # apply 005074a3
    '?white@Color3@G3D@@SAABV12@XZ': 0x514a60,  # apply 00507479
    '?fromStrings@VertexAndPixelShader@G3D@@SA?AV?$ReferenceCountedPointer@VVertexAndPixelShader@G3D@@@2@ABV?$basic_'
    'string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0W4UseG3DUniforms@2@_N@Z': 0x488fe0,  # fromStrings 005076d7
    '?alignedMalloc@System@G3D@@SAPAXII@Z': 0x508580,  # Shader ctor 0050755f (G3D System.cpp, library rows)
    '?memset@System@G3D@@SAXPAXEI@Z': 0x508a30,  # Shader ctor 00507571
    # G3D::Shader vtable 008274d4 slots 3..6 (G3D Shader.cpp out-of-line virtuals)
    '?ok@Shader@G3D@@UBE_NXZ': 0x485a20,
    '?beforePrimitive@Shader@G3D@@UAEXPAVRenderDevice@2@@Z': 0x487c60,
    '?afterPrimitive@Shader@G3D@@UAEXPAVRenderDevice@2@@Z': 0x485460,
    '?messages@Shader@G3D@@UBEABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ': 0x485a30,
    # G3D::ReferenceCountedObject vtable 0081e1e0 slot 0 (stored by the inline Shader ctor 00507510)
    '??_EReferenceCountedObject@G3D@@UAEPAXI@Z': 0x4729b0,
    # MSVC CRT statically linked code
    '_atexit': 0x6a17af,  # getToneMap 00506bd9 / getDepthBlur 00506c59
    '??_M@YGXPAXIHP6EX0@Z@Z': 0x6a165b,  # `eh vector destructor iterator' (~ToneMap 00505b3d, ToneMap +0x8 RCP[2])
    '__ftol2_sse': 0x6a17f0,  # allocateTextures 00507269 / 00507273 / 0050731f / 00507329
}
# Data: address used by the original instruction, with its evidence.
DATA = {
    # getToneMap / getDepthBlur static locals (this unit's own data): guard words and the auto_ptr objects
    # (atexit destructors 007fc5b0 / 007fc5d0 read the same pointers).
    '?$S1@?1??getToneMap@EffectSettings@Render@RBX@@SAPAVToneMap@G3D@@XZ@4IA': 0x9728dc,
    '?toneMap@?1??getToneMap@EffectSettings@Render@RBX@@SAPAVToneMap@G3D@@XZ@4V?$auto_ptr@VToneMap@G3D@@@std@@A':
        0x9728d8,
    '?$S2@?1??getDepthBlur@EffectSettings@Render@RBX@@SAPAVDepthBlur@34@XZ@4IA': 0x9728e4,
    '?depthBlur@?1??getDepthBlur@EffectSettings@Render@RBX@@SAPAVDepthBlur@34@XZ@4V?$auto_ptr@VDepthBlur@Render@RBX@@'
    '@std@@A': 0x9728e0,
    # G3D::inf() static local (guard ??_B, value ?i) shared with every unit that inlines inf()
    '??_B?1??inf@G3D@@YAABNXZ@51': 0x96f020,
    '?i@?1??inf@G3D@@YAABNXZ@4NB': 0x96f018,
    # G3D library statics: TextureFormat::RGB8 (allocateTextures 00507317) and the GLCaps support flags read by the
    # inline GLCaps::supports_* accessors in DepthBlur() 0050777b / 0050778d / 0050779a.
    '?RGB8@TextureFormat@G3D@@2PBV12@B': 0x96fab0,
    '?_supports_GL_ARB_shader_objects@GLCaps@G3D@@0_NA': 0x96ee88,
    '?_supports_GL_ARB_shading_language_100@GLCaps@G3D@@0_NA': 0x96ee89,
    '?_supports_GL_EXT_texture_rectangle@GLCaps@G3D@@0_NA': 0x96ee79,
}
DATA_EXTERNAL = set(DATA)
EXTERNAL.update(DATA)


def load_bodies(obj):
    raw = Path(obj).read_bytes()
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
        bodies.setdefault(n, (b, r, rel))
    return bodies


TARGET = {}


def target_of(address):
    if address not in TARGET:
        body, refs, _ = match.target('2008-06', '%08x' % address)
        TARGET[address] = (body, refs)
    return TARGET[address]


class Closure:
    """Proves rows of one object by call-graph closure; verification runs later against the shared OWN map."""

    def __init__(self, key, roots):
        self.key = key
        self.obj = OBJ[key]
        self.bodies = load_bodies(self.obj)
        self.raw = Path(self.obj).read_bytes()
        self.index = match._coff_data_index(self.raw)
        self.unbound = []
        self.proven, self.aliases, self.why, self.not_exact = {}, {}, {}, {}
        queue = deque()
        for obj_key, address, pattern, evidence in roots:
            if obj_key != key:
                continue
            hits = [n for n in self.bodies if not nb.LOCAL_EH.match(n) and n.startswith(pattern[0])
                    and all(p in n for p in pattern[1:])]
            assert len(hits) == 1, ('root pattern must select one symbol', pattern, hits)
            queue.append((address, hits[0], 'root: ' + evidence))
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
            _, _, rel = self.bodies[symbol]
            target, _ = target_of(address)
            for offset, sym, kind in rel:
                if kind == 20:
                    value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
                    if value in FUNCTIONS and sym in self.bodies and not nb.LOCAL_EH.match(sym) \
                            and sym not in EXTERNAL:
                        queue.append((value, sym, 'called by %08x' % address))

    def exact_at(self, symbol, address):
        if symbol not in self.bodies or address not in FUNCTIONS:
            return False
        body, refs, _ = self.bodies[symbol]
        target, target_refs = target_of(address)
        return len(target) == len(body) and match.exact_match(target, target_refs, body, refs)

    def resolve(self, owner, sym, value):
        """Verify one relocation target; returns a description or None (unbound)."""
        sections, symbols, definitions, _ = self.index
        hit = original.imported(value)
        if hit is not None:
            assert hit[1] == nb.plain(sym), (owner, sym, hex(value), hit)
            return '%s!%s' % hit
        if sym.startswith('__real@'):
            assert original.data(value, len(sym[7:]) // 2) == bytes.fromhex(sym[7:])[::-1], (owner, sym)
            return 'constant %s' % sym[7:]
        if sym.startswith('??_C@'):
            pos, at = definitions[sym]
            literal = self.raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
            assert original.data(value, len(literal)) == literal, (owner, sym, hex(value))
            return 'string %r' % literal[:-1].decode('latin-1')[:60]
        if sym.startswith('??_7'):
            rtti, at = original.vtable_class(value)
            cls = sym[4:sym.index('@@6B') + 2]
            assert rtti == '.?AV' + cls, (owner, sym, hex(value), rtti)
            return 'vtable RTTI %s offset %#x; %s' % (rtti, at, self.verify_vtable(owner, sym, value))
        if sym.startswith('??_R0'):
            name = '.' + sym[5:-2]
            assert original.string(value + 8) == name, (owner, sym, hex(value), original.string(value + 8))
            return 'type descriptor %s' % name
        if sym in OWN:
            assert OWN[sym] == value, (owner, sym, hex(value), hex(OWN[sym]))
            return 'own row'
        if sym in EXTERNAL:
            assert EXTERNAL[sym] == value, (owner, sym, hex(value), hex(EXTERNAL[sym]))
            USED.add(sym)
            return 'external' + (' (evidence name)' if names.get(value, '') == sym else '')
        return None

    def verify_vtable(self, owner, sym, value):
        """Compare the compiled vtable slot by slot with the original one (each slot resolved like a call target)."""
        if sym in VTABLES:
            assert VTABLES[sym][0] == value, (owner, sym, hex(value))
            return VTABLES[sym][1]
        sections, symbols, definitions, _ = self.index
        pos, at = definitions[sym]
        table = sections[at]
        slots = []
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', self.raw, table[5] + 10 * i)
            offset -= pos
            if offset < 0:
                continue
            assert kind == 6 and offset % 4 == 0, (sym, kind, offset)
            slot = symbols[index][0]
            original_slot = struct.unpack('<I', original.data(value + offset, 4))[0]
            scalar = '??_G' + slot[4:] if slot.startswith('??_E') else None
            if scalar in OWN and slot not in self.bodies:
                # the vector deleting destructor slot resolves to the scalar one (no array new of the class)
                assert OWN[scalar] == original_slot, (sym, slot, hex(original_slot))
                how = 'own row %s (??_E resolved to ??_G)' % scalar[:40]
            else:
                how = self.resolve(sym, slot, original_slot)
            if how is None:
                self.unbound.append("    %r: %#x,   # vtable %s slot %d" % (slot, original_slot, sym[:40], offset // 4))
                how = 'UNBOUND'
            slots.append('slot %d %s -> %#x (%s)' % (offset // 4, slot[:60], original_slot, how))
        VTABLES[sym] = (value, 'slots: ' + '; '.join(slots))
        return VTABLES[sym][1]

    def verify(self, address, symbol):
        body, refs, rel = self.bodies[symbol]
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
            how = self.resolve(symbol, sym, value)
            if how is None:
                self.unbound.append("    %r: %#x,   # %s in %s at %08x" % (sym, value, names.get(value, '')[:50],
                                                                          symbol[:50], address + offset))
                continue
            verified[sym] = '%s (%s)' % (hex(value), how)
        return {'size': len(body), 'target_size': len(target), 'verified_targets': verified, 'local_eh': sorted(local)}


CLOSURES = {key: Closure(key, ROOTS) for key in SOURCES}
# One address per symbol across both objects (shared COMDATs must agree).
OWN = {}
for c in CLOSURES.values():
    for address, syms in c.aliases.items():
        for s in syms:
            prev = OWN.setdefault(s, address)
            assert prev == address, ('one address per symbol', s, hex(prev), hex(address))
USED = set()
VTABLES = {}
for c in CLOSURES.values():
    c.checked = {a: c.verify(a, s) for a, s in sorted(c.proven.items())}

if DISCOVER:
    for c in CLOSURES.values():
        print('==', c.key)
        print('\n'.join(sorted(set(c.unbound))))
        for a, (s, r) in sorted(c.not_exact.items()):
            print('NOT EXACT %08x %s (%s)' % (a, s[:120], r))
        for a in sorted(c.proven):
            print('PROVEN %08x %s %s' % (a, c.proven[a][:110], c.why[a][:40]))
    print('UNUSED EXTERNAL', sorted(set(EXTERNAL) - USED))
    sys.exit(0)
for c in CLOSURES.values():
    assert not c.unbound, '\n'.join(c.unbound)
    assert not c.not_exact, {('%08x' % a): v for a, v in c.not_exact.items()}
assert sorted(USED) == sorted(EXTERNAL), sorted(set(EXTERNAL) - USED)
for symbol, address in EXTERNAL.items():
    assert address in FUNCTIONS or original.imported(address) is not None or symbol in DATA_EXTERNAL, \
        (symbol, hex(address))


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


# In-range rows that are proven exact here but are G3D library code: header inlines and compiler-generated members of
# G3D classes whose COMDAT copy the linker took from these objects (other units call several of them). Verified
# support rows, never counted.
LIBRARY_SUPPORT = {
    0x505ad0: 'implicit G3D::ToneMap destructor (RCPs +0x10, +0x8[2], +0x0); called by the atexit destructor 007fc5b0',
    0x505f40: 'G3D::Array<GLight>::operator= (G3D Array.h template over a G3D type); called by Lighting::operator=',
    0x506a60: 'implicit G3D::Lighting::operator=; also called by RenderNew::EffectSettings::update 007afce0 and the '
              'ToneMap code 007b2520',
    0x507180: 'G3D::Texture::createEmpty(name, w, h, format, dimension, settings), an inline Texture.h overload',
    0x5074c0: 'scalar deleting destructor of G3D::Table<std::string, VertexAndPixelShader::ArgList::Arg> (vtable '
              '008274a4 slot 0), emitted with the inline Shader ctor',
    0x5074f0: 'inline G3D::Shader constructor (GLG3D Shader.h)',
    0x5075d0: 'inline G3D::Shader::setPreserveState (vtable 008274d4 slot 1)',
    0x5075e0: 'inline G3D::Shader::preserveState (vtable 008274d4 slot 2)',
    0x5075f0: 'inline G3D::Shader destructor',
    0x507680: 'inline G3D::Shader::fromStrings (GLG3D Shader.h)',
    0x507720: 'scalar deleting destructor shared by identical-code folding (G3D::Shader vtable 008274d4 slot 0; also '
              'the ToneMap / DepthBlur / Lighting ??_G bodies)',
}
proven = {}
for c in CLOSURES.values():
    for a in c.proven:
        assert a not in proven or proven[a] is c or a in (0x45ad90, 0x598fa0, 0x502a70), hex(a)
        proven.setdefault(a, c)
assert set(LIBRARY_SUPPORT) <= set(proven), sorted('%08x' % a for a in set(LIBRARY_SUPPORT) - set(proven))

elsewhere = counted_elsewhere()
range_functions = sorted(a for a in FUNCTIONS if RANGE[0] <= a < RANGE[1])
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if RANGE[0] <= a < RANGE[1]}
counted = sorted(a for a in proven if RANGE[0] <= a < RANGE[1] and a not in elsewhere and a not in LIBRARY_SUPPORT)
assert not set(counted) & set(elsewhere)
support = sorted(a for a in proven if a not in counted)


def entry(a):
    c = proven[a]
    return dict({'symbol': c.proven[a], 'folded_symbols': c.aliases[a][1:], 'identity': c.why[a], 'object': c.key},
                **c.checked[a])


def note(a):
    if a in elsewhere:
        return 'counted by ' + ', '.join(sorted(set(elsewhere[a])))
    if a in LIBRARY_SUPPORT:
        return 'G3D library code, not counted: ' + LIBRARY_SUPPORT[a]
    return 'outside the range %08x..%08x' % RANGE


rows_out = [dict({'address': '%08x' % a, 'exact': True}, **entry(a)) for a in counted]
support_out = [dict({'address': '%08x (%s)' % (a, note(a))}, **entry(a)) for a in support]

NOT_BUILT = [
    ('00504290 / 00504b00 / 00504b60', 'Render::RenderScene render helpers (callers: render 00504bf0 calls 00504b60, '
     'which calls 00504290 / 00504b00 and the sortBy* rows 00505860 / 00505890 / 005058c0): private RenderScene '
     'members not declared in RenderLib/RenderSceneRender2008.h (render-scene owner; proposal)'),
    ('00504bf0', 'Render::RenderScene::render (vtable 00827454 slot 5): blocked in the render-scene receipt (the G3D '
     'draw path: RenderDevice state, shadow volumes, DepthBlur::apply / EffectSettings accessors)'),
    ('00507840..00507fd0', 'G3D 6.09 library code (System.cpp: getStandardProcessorExtensions 00507840, memcpyMMX '
     '005078b0, memfill 00507940, initTime 00507990, BufferPool flushPool / malloc / free 00507a00..00507c00, '
     'System::free 00507d00 / alignedFree 00507d20; TextOutput var helpers 00507d40 / 00507e80 / 00507fd0): '
     'library, never recovered here'),
]
proven_in_range = {a for a in proven if RANGE[0] <= a < RANGE[1]}
unbuilt = ['%08x' % a + ' not built' for a in range_functions if a not in proven_in_range and a not in range_counted]

UNIT_MAP = {
    'render-scene 00504000..005058ef': (
        'RenderLib RenderScene.cpp / RenderSurface.cpp (continues the 00500000 range: setThrottle 00502d30, '
        'setLighting 00502e70, presetLighting 00503cc0, dtor 00503a60). Boundary evidence: Render::RenderScene vtable '
        '00827454 slot 5 render 00504bf0; RenderSceneBase ctor 00504fd0 (vtable 00827424) and RenderScene ctor '
        '00505040 (new 0x500 at 00551820); the RenderSurface sort procs 005051e0 / 00505220 / 00505240 and the '
        'std::sort<RenderSurface**> helpers 00505270..00505780 with the sortBy* wrappers 00505860..005058c0. Rows '
        'counted by render-scene; render and its three helpers are not built (see not_built_reasons).'),
    'effect-settings 005058f0..00507178': (
        'RenderLib EffectSettings.cpp. Boundary evidence: brighter 005058f0 (address pushed by update 00506f5d / '
        '00506fd5) opens the object; the std::sort<GLight*, brighter> helpers 00505940..00506c80 are referenced only '
        'by update; getToneMap 00506b80 / getDepthBlur 00506c00 own the static auto_ptrs 009728d8 / 009728e0 '
        '(atexit destructors 007fc5b0 / 007fc5d0 call the implicit ~ToneMap 00505ad0 / ~DepthBlur 00505b90 COMDATs '
        'of this object); update 00506dd0 (ret 0x20) is called with this = RenderScene +0x2d4 by setThrottle 00502df4 '
        '/ setLighting 00502ec8. Built here: native-classes/AppUnit504EffectSettings.cpp.'),
    'depth-blur 00507180..0050783f': (
        'RenderLib DepthBlur.cpp. Boundary evidence: strings "Depth Buffer" / "Color Buffer" in allocateTextures '
        '005071d0 (evidence names for allocateTextures, apply 00507420 and DepthBlur() 00507740); the G3D::Shader '
        'vtable 008274d4 and Table<std::string, Arg> vtable 008274a4 stored by the inline Shader ctor 005074f0; '
        'G3D System.cpp starts at 00507840. Built here: native-classes/AppUnit504DepthBlur.cpp.'),
    'g3d-system 00507840..': 'G3D 6.09 System.cpp / TextOutput library code; not recovered.',
    'excluded / library code': (
        'no CRobloxApp / CMainFrame / CRobloxDoc / CRobloxView row. G3D header inlines and compiler-generated '
        'members of G3D classes in the two built objects are verified support rows (LIBRARY_SUPPORT), not counted. '
        'The std::sort<GLight*, brighter> instances are Roblox-instantiated templates referenced only by update; '
        'they are counted.'),
    'counted here': 'the RBX rows and Roblox-instantiated sort templates listed in exact_function_rows.',
    'bounds': 'no extent problem found in the rows built here (every proven row is exact at its analysed size).',
}
REJECTED = {
    'EffectSettings::update': [
        'donor openrbx body as-is: groundLOD / LODShift through G3D::lerp with a double divisor (fld qword 0.01; '
        'target multiplies by the float constants 0.01f / 0.02f)',
        'skyBox / hemisphereLighting tested on meshDetail: the target compares the first float argument '
        '(shadingDetail, [esp+0x124] after the call) with 10.0f / 30.0f',
        'std::sort(begin(), end(), brighter): loads num before data; Array::sort(brighter) loads data first',
        'empty-bodied light loops or a const reference body: hoisted (no per-iteration Lighting reload); a GLight '
        'copy body: calls the GLight copy ctor; enabled self-assignment / color self-assignment: extra stores',
        'G3D::iMin / iMax for numNonShadowLights, numLights declared after numShadowLights: register allocation '
        'differs (ebx / ebp swapped)',
    ],
    'brighter': ['(r + g + b) / 3.0f * (1.2 - w) (and with named locals or external linkage): loads B into eax late '
                 '(target loads it into ecx up front); Color3::average() matches'],
}
PROPOSALS = {
    'RenderLib/RenderSceneRender2008.h (render-scene owner)': (
        'Include "AppUnit504/RenderEffects.h" instead of the donor "RenderLib/EffectSettings.h" for the RenderScene '
        '+0x2d4 EffectSettings member: the donor DepthBlur.h it pulls in declares an out-of-line ~DepthBlur, while '
        'the 2008 destructor is implicit (its COMDAT 00505b90 sits in the EffectSettings object and is called by the '
        'atexit destructor 007fc5d0). Layout is unchanged (EffectSettings 0x14 bytes; same field order). Re-run '
        'tests/record_native_render_scene.py before / after.'),
    'RenderLib/RenderSceneRender2008.h (render-scene owner), render helpers': (
        'Declare the three private Render::RenderScene helpers called from render 00504bf0: 00504b60 (thiscall, '
        'calls 00504290 / 00504b00 and sortByMaterialAndDepth / sortByMaterial / sortByDepth 00505860 / 00505890 / '
        '005058c0), 00504290 (2147 B) and 00504b00 (95 B). Names and signatures are not derived here.'),
}

receipt = {
    'class': 'RBX::Render::EffectSettings / DepthBlur units of the application range 00504000..00508000 (2008-06), '
             'inactive',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM), document-swap flags, /fp:fast',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): nb.sha(p) for p in
                [Path(__file__).resolve()] + list(SOURCES.values()) + HEADERS},
    'objects': {k: nb.sha(v) for k, v in OBJ.items()},
    'layout': {
        'DepthBlur': '0xc: shader +0x0, depth +0x4, color +0x8 (new 0xc at 00506c26; ctor 00507740 zeroes +0x0 / '
                     '+0x4 / +0x8; implicit dtor 00505b90 releases +0x8 / +0x4 / +0x0)',
        'EffectSettings': '0x14: bools +0x0..+0x6, floats +0x8 / +0xc / +0x10 (update 00506dd0 stores; RenderScene '
                          '+0x2d4 member, render-scene layout probe effectSettingsSize 0x14)',
        'ToneMap (G3D)': 'new 0x18 at 00506ba6 before ToneMap() 007b29c0 (matches the G3D 6.09 header layout)',
    },
    'unit_map': UNIT_MAP,
    'range_functions': len(range_functions),
    # Written as 'ADDR counted by RECEIPT' text, never as a quoted bare address: some recorders (local_backpack,
    # viewnew_brick_build, viewnew_part_mesh) treat any '"ADDR"' in another receipt as counted there and drop it.
    'range_rows_counted_by_other_receipts': ['%08x counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()],
    'range_rows_not_built': unbuilt,
    'not_built_reasons': ['%s: %s' % x for x in NOT_BUILT],
    'vtables': {k: '%#x %s' % v for k, v in VTABLES.items()},
    'rows': rows_out,
    'support_rows_not_counted': support_out,
    'pending_build_only': [],
    'exact_function_rows': ['%08x' % a for a in counted],
    'rejected': REJECTED,
    'proposals': PROPOSALS,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit. New header '
             'native-headers/AppUnit504/RenderEffects.h (no donor header at that path).',
}
text = json.dumps(receipt, indent=2) + '\n'
quoted = set(re.findall(r'"([0-9a-f]{8})"', text))
assert quoted <= {'%08x' % a for a in counted}, sorted(quoted - {'%08x' % a for a in counted})[:10]
RECEIPT.write_text(text)
print('PASS app-unit504: %d counted exact rows; %d support rows; %d range rows, %d counted elsewhere, %d not built'
      % (len(counted), len(support_out), len(range_functions), len(range_counted), len(unbuilt)))
print(' '.join('%08x' % a for a in counted))
