"""Verify the inactive native RBX::Adorn interface and RBX::AdornG3D (2008-06).

Builds (document-swap flags, VS2008 RTM 21022, /fp:fast), all from the current native headers
(native-headers/RbxGraphics/Adorn2008.h, native-headers/AppDraw/AdornG3D2008.h; non-colliding names, so no donor header
is shadowed for any other unit):
  * tests/NativeAdornLayout.cpp   sizeof/offset probes (mov eax, imm32; ret) and nativeNewAdornG3D, which instantiates the
                                  header-inline constructor so that the object carries the AdornG3D vtable, ??_G and
                                  G3D::Table<TextureArgs, TextureRef>::freeMemory built from the current headers;
  * native-classes/AdornG3D.cpp   AdornG3D method bodies 00676480..00676aff.

A second, pending-only build (/DNATIVE_ADORN_PENDING plus generated proposal headers under
out/native-layouts/adorn-pending/, which replace the donor RbxGraphics/TextureProxyBase.h / RenderLib/TextureProxy.h for
that build only) compiles createTextureProxy / setTexture / getTextureSize. Those rows are recorded exact=false
(pending-build-only) and are not counted; the vtable check uses the current-header objects only.

Every exact row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified: imports by DLL export name, constants by bytes, vtables by original RTTI
names, own symbols by the row proven here, folded bodies by their bytes, and the remaining externals by the explicit
EXTERNAL map (call sites read in the original disassembly, structure checked below). One address per symbol.
Writes work/2008-06/shared-layouts/adorn-working.json. Set NATIVE_ADORN_DISCOVER=1 to list unbound targets and
non-exact rows instead of asserting.
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
LAYOUT = R / 'tests/NativeAdornLayout.cpp'
UNIT = R / 'native-classes/AdornG3D.cpp'
HEADERS = [R / 'native-headers/RbxGraphics/Adorn2008.h', R / 'native-headers/AppDraw/AdornG3D2008.h']
DISCOVER = bool(os.environ.get('NATIVE_ADORN_DISCOVER'))

# ---- pending proposal headers (generated, build-local; not part of the native tree) --------------------------------
# Evidence: TextureProxyBase vtable 0082d168 (RTTI .?AVTextureProxyBase@RBX@@, 8 slots: ??_G 00551d50, four accessors
# 00551c70 / 00551c90 (int at +0x28) and 00551cb0 / 00551cd0 (float at +0x2c), then three _purecall slots), base ctor
# 00551bf0 (ReferenceCountedObject 00472990, string at +0xc, +0x28 = 1, +0x2c = 1.0f); Render::TextureProxy vtable
# 0082d140 (9 slots), ctor 00551b30 (TextureManager&, const std::string&, bool; +0x30 texture, +0x34 loaded,
# +0x38 manager, +0x3c tiled, +0x40 root, +0x44 shadeTexture, +0x48 shade colour), new(0x54) in 00676aa0;
# AdornG3D 00676890 / 00676750 call slot 6 (+0x18) with (TextureRef* result, RenderDevice*): resolve.
# The accessor names are unknown (no donor counterpart); they are named by what they touch.
PENDING_DIR = OUT / 'adorn-pending'
PENDING_HEADERS = {
    'RbxGraphics/TextureProxyBase.h': '''#pragma once
// GENERATED proposal (record_native_adorn.py): 2008 RBX::TextureProxyBase, owner: texture proxies.
#include <string>
#include <G3D/ReferenceCount.h>
#include <G3D/Vector2.h>
#include <GLG3D/Texture.h>
namespace G3D { class RenderDevice; }
namespace RBX
{
	typedef G3D::ReferenceCountedPointer<class TextureProxyBase> TextureProxyBaseRef;
	class TextureProxyBase : public G3D::ReferenceCountedObject
	{
	public:
		std::string filename;          // +0x0c
	protected:
		int intValue28;                // +0x28 (= 1 in 00551bf0; name unknown)
		float floatValue2c;            // +0x2c (= 1.0f in 00551bf0; name unknown)
	public:
		TextureProxyBase();
		virtual ~TextureProxyBase();
		virtual void setIntValue28(int value);                                      // slot 1 00551c70
		virtual int getIntValue28() const;                                          // slot 2 00551c90
		virtual void setFloatValue2c(float value);                                  // slot 3 00551cb0
		virtual float getFloatValue2c() const;                                      // slot 4 00551cd0
		virtual G3D::ReferenceCountedPointer<G3D::Texture> getIfResolved() const = 0;     // slot 5
		virtual G3D::ReferenceCountedPointer<G3D::Texture> resolve(G3D::RenderDevice* rd) = 0;   // slot 6 (+0x18)
		virtual G3D::Vector2 getSize() = 0;                                         // slot 7
	};
}
''',
    'RenderLib/TextureProxy.h': '''#pragma once
// GENERATED proposal (record_native_adorn.py): 2008 RBX::Render::TextureProxy, owner: texture proxies.
#include "RbxGraphics/TextureProxyBase.h"
#include <G3D/Color3.h>
#include <GLG3D/RenderDevice.h>
#include <GLG3D/Texture.h>
#include <GLG3D/TextureManager.h>
namespace RBX
{
	namespace Render
	{
		class TextureProxy : public TextureProxyBase
		{
		protected:
			G3D::ReferenceCountedPointer<G3D::Texture> texture;          // +0x30
			bool loaded;                                                 // +0x34
			G3D::TextureManager* textureManager;                         // +0x38
			bool tiled;                                                  // +0x3c
			G3D::ReferenceCountedPointer<TextureProxy> root;             // +0x40
			G3D::ReferenceCountedPointer<TextureProxy> shadeTexture;     // +0x44
			G3D::Color3 shadeColor;                                      // +0x48 (size 0x54)
		public:
			TextureProxy(G3D::TextureManager& textureManager, const std::string& filename, bool tiled);   // 00551b30
			virtual ~TextureProxy();
			virtual G3D::ReferenceCountedPointer<G3D::Texture> getIfResolved() const;
			virtual G3D::ReferenceCountedPointer<G3D::Texture> resolve(G3D::RenderDevice* rd);
			virtual G3D::Vector2 getSize();
		};
	}
}
''',
}
for rel, text in PENDING_HEADERS.items():
    path = PENDING_DIR / rel
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text)


def build(name, src, extra=(), before_native=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(before_native) + flags[i:] + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeAdornLayout', LAYOUT, ['/fp:fast'])
unit_obj, unit_flags = build('NativeAdorn_g3d', UNIT, ['/fp:fast'])
pending_obj, pending_flags = build('NativeAdorn_g3d_pending', UNIT, ['/fp:fast', '/DNATIVE_ADORN_PENDING'],
                                   ['/I' + str(PENDING_DIR)])
OBJ = {'layout': layout_obj, 'g3d': unit_obj, 'pending': pending_obj}
FLAGS = {'layout': layout_flags, 'g3d': unit_flags, 'pending': pending_flags}

# ---- layout -------------------------------------------------------------------------------------------------------
# Evidence: 0045d850 pushes 0x20 to operator new, stores the vtable 00819d24 at +0, the RenderDevice at +4 and calls the
# TextureManager(size_t) constructor 0047e400 on +8; ??_G 0045d820 destroys the 0x18-byte TextureManager at +8.
raw = layout_obj.read_bytes()
SIZES = {'adornSize': 0x4, 'adornG3DSize': 0x20, 'adornG3DRenderDevice': 0x4, 'adornG3DTextureManager': 0x8,
         'textureManagerSize': 0x18}
for fn, size in SIZES.items():
    name_, body_, _ = next(x for x in match.coff_functions(raw) if x[0].startswith('?native' + fn + '@@'))
    assert body_ == b'\xb8' + struct.pack('<I', size) + b'\xc3', (fn, body_.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]

TABLE = '?$Table@VTextureArgs@TextureManager@G3D@@V?$ReferenceCountedPointer@VTexture@G3D@@@3@@G3D@@'
EXTERNAL = {
    '??2@YAPAXI@Z': 0x6a0920, '??3@YAXPAX@Z': 0x6a067a,
    # G3D::RenderDevice (GLG3D, not recovered here); call sites in the AdornG3D bodies, structure checked below.
    '?getViewport@RenderDevice@G3D@@QBE?AVRect2D@2@XZ': 0x476d60,          # 00676489
    '?getWidth@RenderDevice@G3D@@QBEHXZ': 0x478450,                         # 006764a3 (tail jump)
    '?getHeight@RenderDevice@G3D@@QBEHXZ': 0x478cd0,                        # 006764b3 (tail jump)
    '?setObjectToWorldMatrix@RenderDevice@G3D@@QAEXABVCoordinateFrame@2@@Z': 0x4777e0,   # 00676573 (tail jump)
    '?beginPrimitive@RenderDevice@G3D@@QAEXW4Primitive@12@@Z': 0x47b410,    # 006766d6 (push 5 = QUADS)
    '?sendVertex@RenderDevice@G3D@@QAEXABVVector3@2@@Z': 0x477ec0,          # 006766e3 / f0 / fd / 0670a
    '?endPrimitive@RenderDevice@G3D@@QAEXXZ': 0x478990,                     # 00676712
    '?setTexture@RenderDevice@G3D@@QAEXIV?$ReferenceCountedPointer@VTexture@G3D@@@2@@Z': 0x479450,   # 006768e4
    '?rect2DBounds@Texture@G3D@@QBE?AVRect2D@2@XZ': 0x473f90,               # 006767a4
    # G3D::GFont / G3D::Draw (GLG3D library bodies in the 007b.... range).
    '?get2DStringBounds@GFont@G3D@@QBE?AVVector2@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@NW4Spacing@12@@Z': 0x7b6b30,   # 00676988
    '?draw2D@GFont@G3D@@QBE?AVVector2@2@PAVRenderDevice@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@ABV32@NABVColor4@2@3W4XAlign@12@W4YAlign@12@W4Spacing@12@@Z': 0x7b6fc0,   # 00676a48
    '?ray@Draw@G3D@@SAXABVRay@2@PAVRenderDevice@2@ABVColor4@2@M@Z': 0x7b05b0,                  # 00676646
    '?lineSegment@Draw@G3D@@SAXABVLineSegment@2@PAVRenderDevice@2@ABVColor4@2@M@Z': 0x7b0250,  # 00676676
    '?axes@Draw@G3D@@SAXPAVRenderDevice@2@ABVColor4@2@11M@Z': 0x7b1490,                         # 006766ab
    # RBX::DrawPrimitives / RBX::Fonts and G3D reference counting: evidence names.
    '?line2d@DrawPrimitives@RBX@@SAXABVVector2@G3D@@0PAVRenderDevice@4@ABVColor4@4@@Z': 0x6781f0,
    '?outlineRect2d@DrawPrimitives@RBX@@SAXABVRect@2@MPAVRenderDevice@G3D@@ABVColor4@5@@Z': 0x678080,
    '?rect2d@DrawPrimitives@RBX@@SAXABVRect@2@PAVRenderDevice@G3D@@ABVColor4@5@@Z': 0x678280,
    '?rawBox@DrawPrimitives@RBX@@SAXABVAABox@G3D@@PAVRenderDevice@4@@Z': 0x677f60,
    '?rawSphere@DrawPrimitives@RBX@@SAXMPAVRenderDevice@G3D@@@Z': 0x677de0,
    '?rawCylinderAlongX@DrawPrimitives@RBX@@SAXMMPAVRenderDevice@G3D@@@Z': 0x677e20,
    '?getFont@Fonts@RBX@@SA?AV?$ReferenceCountedPointer@VGFont@G3D@@@G3D@@XZ': 0x678310,
    '?ReferenceCountedObject_zeroWeakPointers@ReferenceCountedObject@G3D@@QAEXXZ': 0x45ad90,
    # G3D::System memory (G3D library): free 00507d00 forwards to the allocator 00507c00, alignedFree 00507d20 frees
    # the block whose pointer sits at p[-4] (checked below).
    '?free@System@G3D@@SAXPAX@Z': 0x507d00,                                  # 0045c680 node delete
    '?alignedFree@System@G3D@@SAXPAX@Z': 0x507d20,                           # 0045c680 bucket array
    # pending-build-only targets (rows not counted)
    '??0TextureProxy@Render@RBX@@QAE@AAVTextureManager@G3D@@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z': 0x551b30,   # 00676ae8
    '?setPointer@?$ReferenceCountedPointer@VTextureProxyBase@RBX@@@G3D@@AAEXPAVTextureProxyBase@RBX@@@Z': 0x598fa0,   # ICF (evidence: Shader)
}
# Bodies folded by the linker with other identical bodies: verified by their bytes below.
FOLDED = {
    '?prepareRenderPass@Adorn@RBX@@UAEXXZ': 0x47d410,   # one-byte `ret`
    '?finishRenderPass@Adorn@RBX@@UAEXXZ': 0x47d410,
    '?sparkle@Adorn@RBX@@UAEXXZ': 0x47d410,
}
DATA = {}
LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
binding = {}

LAYOUT_ROWS = [
    (0x45d820, '??_GAdornG3D@RBX@@UAEPAXI@Z'),
    (0x45c680, '?freeMemory@' + TABLE + 'AAEXXZ'),
    (0x45b640, '??1Entry@' + TABLE + 'QAE@XZ'),
]
G3D_ROWS = [
    (0x676480, '?getViewport@AdornG3D@RBX@@UBE?AVRect2D@G3D@@XZ'),
    (0x6764a0, '?getWidth@AdornG3D@RBX@@UBEHXZ'),
    (0x6764b0, '?getHeight@AdornG3D@RBX@@UBEHXZ'),
    (0x6764c0, '?rect2d@AdornG3D@RBX@@UBEXABVRect2D@G3D@@ABVColor4@4@@Z'),
    (0x676500, '?outlineRect2d@AdornG3D@RBX@@UBEXABVRect2D@G3D@@MABVColor4@4@@Z'),
    (0x676550, '?line2d@AdornG3D@RBX@@UBEXABVVector2@G3D@@0ABVColor4@4@@Z'),
    (0x676570, '?setObjectToWorldMatrix@AdornG3D@RBX@@UAEXABVCoordinateFrame@G3D@@@Z'),
    (0x676580, '?box@AdornG3D@RBX@@UAEXABVAABox@G3D@@ABVColor4@4@1@Z'),
    (0x6765b0, '?sphere@AdornG3D@RBX@@UAEXABVSphere@G3D@@ABVColor4@4@1@Z'),
    (0x6765e0, '?explosion@AdornG3D@RBX@@UAEXABVSphere@G3D@@ABVColor4@4@1@Z'),
    (0x6765f0, '?cylinderAlongX@AdornG3D@RBX@@UAEXMMABVColor4@G3D@@0@Z'),
    (0x676630, '?ray@AdornG3D@RBX@@UAEXABVRay@G3D@@ABVColor4@4@M@Z'),
    (0x676660, '?lineSegment@AdornG3D@RBX@@UAEXABVLineSegment@G3D@@ABVColor4@4@M@Z'),
    (0x676690, '?axes@AdornG3D@RBX@@UAEXABVColor4@G3D@@00M@Z'),
    (0x6766c0, '?quad@AdornG3D@RBX@@UAEXABVVector3@G3D@@000ABVColor4@4@@Z'),
    (0x676720, '?setColor@AdornG3D@RBX@@UAEXABVColor4@G3D@@@Z'),
    (0x676940, '?get2DStringBounds@AdornG3D@RBX@@UBE?AVVector2@G3D@@ABV?$basic_string@DU?$char_traits@D@std@@'
               'V?$allocator@D@2@@std@@NW4Spacing@Adorn@2@@Z'),
    (0x6769e0, '?drawFont2D@AdornG3D@RBX@@UBE?AVVector2@G3D@@ABV?$basic_string@DU?$char_traits@D@std@@'
               'V?$allocator@D@2@@std@@ABV34@NABVColor4@4@2W4XAlign@Adorn@2@W4YAlign@92@W4Spacing@92@@Z'),
]
PENDING_ROWS = [
    (0x676aa0, '?createTextureProxy@AdornG3D@RBX@@UAE?AV?$ReferenceCountedPointer@VTextureProxyBase@RBX@@@G3D@@'
               'ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z'),
    (0x676890, '?setTexture@AdornG3D@RBX@@UAEXHV?$ReferenceCountedPointer@VTextureProxyBase@RBX@@@G3D@@@Z'),
    (0x676750, '?getTextureSize@AdornG3D@RBX@@UBE?AVRect2D@G3D@@V?$ReferenceCountedPointer@VTextureProxyBase@RBX@@@4@@Z'),
]
PENDING_REASON = ('pending-build-only: needs the 2008 TextureProxyBase (resolve = virtual slot 6, +0x18) and the out-of-line '
                  'Render::TextureProxy(TextureManager&, const std::string&, bool) 00551b30 (size 0x54); compiled only '
                  'with /DNATIVE_ADORN_PENDING against generated proposal headers')
ROWS = {'layout': LAYOUT_ROWS, 'g3d': G3D_ROWS}


def target_of(address):
    body, refs, _ = match.target('2008-06', '%08x' % address)
    return body, refs


def resolve(obj, rows):
    funcs = match.coff_functions(Path(obj).read_bytes())
    out = []
    for address, key in rows:
        hits = [x for x in funcs if x[0] == key]
        if DISCOVER and len(hits) != 1:
            print('UNRESOLVED', '%08x' % address, key[:120], [h[0][:120] for h in funcs if key[:20] in h[0]][:5])
            continue
        assert len(hits) == 1, ('%08x' % address, key)
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

# Pending-build-only rows: compared and their targets checked, but never counted (exact=False).
pending_out = []
pending_own = dict(own)
for address, key in PENDING_ROWS:
    pending_own[key] = address
for row in verify(OBJ['pending'], resolve(OBJ['pending'], PENDING_ROWS), pending_own, strict=False, record=False):
    row['pending_build_exact'] = row['exact']
    row['exact'], row['reason'] = False, PENDING_REASON
    pending_out.append(row)
# The pending build must not change any counted body.
pending_bodies = {n: b for n, b, _ in match.coff_functions(Path(OBJ['pending']).read_bytes())}
current_bodies = {n: b for n, b, _ in match.coff_functions(Path(OBJ['g3d']).read_bytes())}
for _, name in resolved['g3d']:
    assert pending_bodies[name] == current_bodies[name], name

if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for g in list(groups.values()) + [pending_out]:
        for r in g:
            if not r['exact']:
                print('NOT EXACT', r['address'], r['symbol'][:110], r['size'], r['target_size'], r.get('pending_build_exact'))
    sys.exit(0)
assert not UNBOUND, '\n'.join(UNBOUND)

# ---- externals: structure of the bodies they bind to ---------------------------------------------------------------


def body(address):
    return match.target('2008-06', '%08x' % address)[0]


FUNCTIONS = {int(json.loads(l)['addr'], 16) for l in
             (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines() if l.strip()} \
    if (ROOT / 'work/2008-06/functions.jsonl').exists() else None
if FUNCTIONS is not None:
    for symbol, address in list(EXTERNAL.items()) + list(FOLDED.items()):
        assert address in FUNCTIONS, (symbol, hex(address))
assert body(0x507d00) == bytes.fromhex('8b4424048b0d') + body(0x507d00)[6:] and b'\x8b\x40\xfc' in body(0x507d20)
assert body(0x47d410) == b'\xc3'                                         # folded empty virtuals
assert body(0x476d60)[:6] == bytes.fromhex('d981c0030000')               # getViewport reads the viewport at +0x3c0
assert body(0x478450)[:6] == bytes.fromhex('8b81e8030000')               # getWidth / getHeight read the window +0x3e8
assert body(0x478cd0)[:6] == bytes.fromhex('8b81e8030000')
assert original.vtable_class(0x819cd8) == ('.?AV' + TABLE, 0)                # ~Table vtable stored by ??_G
assert original.vtable_class(0x82d140) == ('.?AVTextureProxy@Render@RBX@@', 0)
assert original.vtable_class(0x82d168) == ('.?AVTextureProxyBase@RBX@@', 0)
assert body(0x551b30).count(struct.pack('<I', 0x82d140)) == 1          # TextureProxy ctor stores its vtable

# Allocation size and inline construction in 0045d850 (the only reference to the AdornG3D vtable).
ctor_site = body(0x45d850)
at = ctor_site.index(b'\x6a\x20')                                        # push 0x20
assert ctor_site.index(b'\xc7\x07' + struct.pack('<I', 0x819d24)) > at  # mov [edi], 00819d24
assert ctor_site.index(b'\x68' + struct.pack('<I', 0xa00000)) > at      # TextureManager(10 MiB)
assert body(0x676aa0).startswith(bytes.fromhex('6aff')) and b'\x6a\x54' in body(0x676aa0)   # new(0x54) TextureProxy

# ---- vtable from the object built with the current headers, slot by slot -------------------------------------------
slot_names = {}
for table_ in (own, FOLDED, EXTERNAL):
    for k, v in table_.items():
        slot_names.setdefault(k, v)
SLOT_PENDING = {key: address for address, key in PENDING_ROWS}   # slot identity only; rows stay uncounted


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
        elif slot in slot_names:
            expect, how = slot_names[slot], 'bound'
        elif slot in SLOT_PENDING:
            expect, how = SLOT_PENDING[slot], 'pending-build-only row (identity only)'
        else:
            expect, how = None, 'unbound'
        ok = expect == value
        out.append({'slot': i, 'symbol': slot, 'original': '%08x' % value, 'ok': ok, 'how': how})
        if not ok:
            bad.append((i, slot, hex(value)))
    assert not bad, (symbol, bad)
    return out


assert original.vtable_class(0x819d24) == ('.?AVAdornG3D@RBX@@', 0)
vt = {'AdornG3D@RBX': check_vtable(OBJ['layout'], '??_7AdornG3D@RBX@@6B@', 0x819d24)}
assert len(vt['AdornG3D@RBX']) == 25

# ---- RTTI bases (original) -----------------------------------------------------------------------------------------


def bases(vtable):
    hierarchy = d(d(vtable - 4) + 16)
    out = {}
    for i in range(d(hierarchy + 8)):
        bcd = d(d(hierarchy + 12) + 4 * i)
        out.setdefault(original.string(d(bcd) + 8), struct.unpack('<i', original.data(bcd + 8, 4))[0])
    return out


assert bases(0x819d24) == {'.?AVAdornG3D@RBX@@': 0, '.?AVAdorn@RBX@@': 0}
assert bases(0x84d2a4) == {'.?AVAdornRbxGfx@RBX@@': 0, '.?AVAdorn@RBX@@': 0}
# AdornRbxGfx (not built here): same 25-slot interface; slots 2 / 3 / 19 are real bodies there.
rbxgfx_slots = ['%08x' % d(0x84d2a4 + 4 * i) for i in range(25)]
assert rbxgfx_slots[19] == '00674790' and body(0x674790)[-1:] == b'\xc3'   # sparkle(): no arguments (plain ret)

sha = nb.sha
paths = [Path(__file__).resolve(), LAYOUT, UNIT] + HEADERS
exact = sorted({r['address'] for g in groups.values() for r in g if r['exact']})
groups['not_exact'] = pending_out
PROPOSALS = {
    'RbxGraphics/TextureProxyBase.h + RenderLib/TextureProxy.h (owner: texture proxies)':
        '2008 TextureProxyBase: ReferenceCountedObject base, filename +0xc, int +0x28 (=1), float +0x2c (=1.0f); '
        'vtable 0082d168: ??_G, four accessors 00551c70/90/b0/d0, then three pure virtuals with resolve(RenderDevice*) '
        'at slot 6 (+0x18). Render::TextureProxy (vtable 0082d140, 9 slots) with an out-of-line ctor '
        '(TextureManager&, const std::string&, bool) 00551b30, size 0x54 (+0x30 texture, +0x34 loaded, +0x38 manager, '
        '+0x3c tiled, +0x40 root, +0x44 shadeTexture, +0x48 Color3). With these, AdornG3D createTextureProxy 00676aa0, '
        'setTexture 00676890 and getTextureSize 00676750 compile exact (see the pending rows); the generated text is '
        'PENDING_HEADERS in this recorder.',
    'RbxGraphics/Adorn.h (donor path, owner: rendering)':
        '2008 Adorn is __declspec(novtable) with 25 slots: an extra no-argument virtual after explosion() (slot 19, '
        'AdornRbxGfx 00674790) and non-pure empty prepareRenderPass / finishRenderPass; see RbxGraphics/Adorn2008.h.',
}
receipt = {
    'class': 'RBX::Adorn (interface), RBX::AdornG3D',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'pending_headers': {k: __import__('hashlib').sha256(v.encode()).hexdigest() for k, v in PENDING_HEADERS.items()},
    'objects': {p.name: sha(p) for p in OBJ.values()},
    'layout': {k: hex(v) for k, v in SIZES.items()},
    'rows': groups,
    'exact_function_rows': exact,
    'vtables': vt,
    'adorn_rbxgfx_vtable_0084d2a4': rbxgfx_slots,
    'adorn_rbxgfx_evidence': 'not built (needs Ogre / RbxGfx context declarations): ctor 00674210 (only caller '
        '0045b451) stores 0084d2a4, std::string +0x8, two Ogre SharedPtr +0x24 / +0x38, std::vectors +0x48 / +0x60 / '
        '+0xa0 / +0xdc, std::maps +0x78 / +0xb8 / +0xf4, pointers +0x9c / +0xd8 = 0, G3D::CoordinateFrame +0x114, ctor '
        'argument +0x4; dtor 00673a90 called from ??_G 006741f0; getWidth/getHeight 0066f900/0066f910 tail-call '
        'Ogre::Viewport::getActualWidth/Height (IAT 00804c80 / 00804c7c) on [[this+4]+0x10]; setColor 0070bdf0 and '
        'axes 004e83a0 are shared empty bodies (ret 4 / ret 0x10).',
    'proposals': PROPOSALS,
    'scope': 'Inactive. Exact bodies with verified call/data targets; pending-build-only rows not counted; no active '
             'build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/adorn-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native Adorn: %d distinct function rows exact (%s); %d pending-build-only rows not counted (%d exact in '
      'the pending build); targets and %d vtable verified'
      % (len(exact), ', '.join('%s %d' % (k, sum(r['exact'] for r in g)) for k, g in groups.items() if k != 'not_exact'),
         len(pending_out), sum(1 for r in pending_out if r['pending_build_exact']), len(vt)))
