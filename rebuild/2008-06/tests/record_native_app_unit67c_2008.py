"""Verify the inactive 2008-06 native rows of the application range 0067c000..00688000 (Roblox's exe-local Ogre 1.4.5
forks after the VisualEngine unit), and record the unit map of the range.

Unit map (boundary evidence in the receipt's `unit_map`; rows counted by other receipts are listed there):
  * VisualEngine unit tail 0067c000..0067c4c0 (ogre-visual-engine-working.json; not rebuilt here).
  * Ogre::RbxEntity unit 0067c4d0..0067f16f: RbxEntity is declared by another owner (RenderLib/AggregateChunk2008.h,
    a minimal declaration without its Entity base), so it is not built here; layout evidence goes to that owner.
  * Ogre::RbxSky unit 0067f170..0068118f (ogre-rbx-sky / ogre-rbx-locals), RbxSceneNode / TwoDManager unit
    00681190..006843ef (ogre-rbx-node); not rebuilt here.
  * Ogre::RbxFont unit 006843f0..00684f9f (no declaration; not built).
  * Ogre::RbxSubEntity unit 00684fa0..00685e07: native-classes/AppUnit67C_2008SubEntity.cpp against the new
    native-headers/AppUnit67C_2008/RbxSubEntity2008.h (a new path: it shadows no donor or native header).
  * Mesh-builder helpers 00685e10..: 00685e10 / 00685e30 and the builders 00685ea0 / 00687860 (not built).

Build: document-swap flags plus the Ogre 1.4.5 client headers, VS2008 RTM 21022, /fp:fast (the profile of
record_native_ogre_rbx_node.py). A layout probe generated under out/app-unit67c-2008/ checks sizeof / offsets of the
header against the evidence. Every counted row is relocation-masked exact against the original and every REL32/DIR32
target is bound to the address the original instruction uses and verified: imports (and import thunks) by DLL export
name, string literals by bytes, vtables and type descriptors by original RTTI names, throw infos by their catchable type,
own rows, local statics by one address per symbol, bodies folded by the linker onto identical code elsewhere by an exact
comparison of the body compiled here, and the remaining statically linked externals by the explicit EXTERNAL map. Both
RbxSubEntity vtables and the shadow-renderable vtable are compared slot by slot with the object built from the current
header (there is no pending build). A row is counted only when no other receipt counts it.
Writes work/2008-06/shared-layouts/app-unit67c-2008-working.json. Set NATIVE_APP_UNIT67C_DISCOVER=1 to list unbound
targets and non-exact rows instead of asserting.
"""
import glob
import json
import os
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match, rebuild  # noqa: E402
import native_bind as nb  # noqa: E402

R = ROOT / 'rebuild/2008-06'
OUT = nb.OUT / 'app-unit67c-2008'
OUT.mkdir(parents=True, exist_ok=True)
OGRE = '/I' + str(ROOT / 'tools/libs/ogre-1.4.5/ogrenew/OgreMain/include')
HEADER = R / 'native-headers/AppUnit67C_2008/RbxSubEntity2008.h'
SOURCES = {'sub_entity': R / 'native-classes/AppUnit67C_2008SubEntity.cpp'}
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT67C_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit67c-2008-working.json'
RANGE = ('0067c000', '00688000')

# ---- layout probe (generated, build-local) ---------------------------------------------------------------------------
LAYOUT = OUT / 'NativeAppUnit67CLayout.cpp'
PROBES = {
    # RbxSubEntity: new(0x15c) at 00671d60 before the constructor 00685660; ShadowCaster base at +0xec (RTTI 0084e90c)
    'size': ('sizeof(Ogre::RbxSubEntity)', 0x15c),
    'subEntitySize': ('sizeof(Ogre::SubEntity)', 0xec),
    'shadowCaster': ('(int)((char*)static_cast<Ogre::ShadowCaster*>(reinterpret_cast<Ogre::RbxSubEntity*>(0x1000))'
                     ' - (char*)0x1000)', 0xec),   # probe-only constant pointer (no null check)
    'parentEntity': ('offsetof(Ogre::RbxSubEntity, mParentEntity)', 0x28),     # getSquaredViewDepth 00685031
    'material': ('offsetof(Ogre::RbxSubEntity, mpMaterial)', 0x48),            # setMaterial 006850a0
    'subMesh': ('offsetof(Ogre::RbxSubEntity, mSubMesh)', 0x54),               # getSubMesh 006850d8
    'cachedDist': ('offsetof(Ogre::RbxSubEntity, mCachedCameraDist)', 0xe4),   # getSquaredViewDepth 00685023
    'cachedCamera': ('offsetof(Ogre::RbxSubEntity, mCachedCamera)', 0xe8),     # getSquaredViewDepth 0068501b
    'transform': ('offsetof(Ogre::RbxSubEntity, mTransform)', 0xf0),           # getWorldTransforms 00685716
    'lodSubMeshes': ('offsetof(Ogre::RbxSubEntity, mLodSubMeshes)', 0x130),    # constructors 006856e4 / 006858cf
    'lod': ('offsetof(Ogre::RbxSubEntity, mLod)', 0x134),                      # setLod 006850f4
    'customValue': ('offsetof(Ogre::RbxSubEntity, mCustomValue)', 0x138),      # 00685824
    'castShadows': ('offsetof(Ogre::RbxSubEntity, mCastShadows)', 0x13c),      # constructors 006856b1
    'shadowSubMesh': ('offsetof(Ogre::RbxSubEntity, mShadowSubMesh)', 0x140),  # constructors 006856de
    'shadowRenderables': ('offsetof(Ogre::RbxSubEntity, mShadowRenderables)', 0x144),   # 006856b7
    # RbxSubEntityShadowRenderable: new(0x70) at 00685bf9 / 0068534c; ShadowRenderable() is 0x4c bytes
    'srSize': ('sizeof(Ogre::RbxSubEntity::RbxSubEntityShadowRenderable)', 0x70),
    'srBase': ('sizeof(Ogre::ShadowRenderable)', 0x4c),
    'srPosition': ('offsetof(Ogre::RbxSubEntity::RbxSubEntityShadowRenderable, mPositionBuffer)', 0x4c),
    'srW': ('offsetof(Ogre::RbxSubEntity::RbxSubEntityShadowRenderable, mWBuffer)', 0x58),
    'srVertexData': ('offsetof(Ogre::RbxSubEntity::RbxSubEntityShadowRenderable, mCurrentVertexData)', 0x64),
    'srBinding': ('offsetof(Ogre::RbxSubEntity::RbxSubEntityShadowRenderable, mOriginalPosBufferBinding)', 0x68),
    'srSubEntity': ('offsetof(Ogre::RbxSubEntity::RbxSubEntityShadowRenderable, mSubEntity)', 0x6c),
}
LAYOUT.write_text(
    '// generated by tests/record_native_app_unit67c_2008.py: sizeof / offset probes (mov eax, imm32; ret)\n'
    '#include "AppUnit67C_2008/RbxSubEntity2008.h"\n#include <cstddef>\n'
    'struct NativeAppUnit67CLayout\n{\n'
    + ''.join('\tstatic int %s(Ogre::RbxSubEntity& r);\n' % k for k in PROBES)
    + '};\n'
    + ''.join('int NativeAppUnit67CLayout::%s(Ogre::RbxSubEntity& r)\n{\n\t(void)r;\n\treturn %s;\n}\n' % (k, e)
              for k, (e, _) in PROBES.items()))


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i + 1] + [OGRE] + flags[i + 1:] + ['/fp:fast'] + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log[-4000:]
    return obj, flags


OBJ, FLAGS = {}, {}
OBJ['layout'], FLAGS['layout'] = build('NativeAppUnit67CLayout', LAYOUT)
for key, src in SOURCES.items():
    OBJ[key], FLAGS[key] = build('NativeAppUnit67C_2008_' + key, src)

layout = {}
for n, b, _ in match.coff_functions(Path(OBJ['layout']).read_bytes()):
    m = re.match(r'\?(\w+)@NativeAppUnit67CLayout@@', n)
    if m and m.group(1) in PROBES:
        assert b == b'\xb8' + struct.pack('<I', PROBES[m.group(1)][1]) + b'\xc3', (m.group(1), b.hex())
        layout[m.group(1)] = hex(PROBES[m.group(1)][1])
assert sorted(layout) == sorted(PROBES), sorted(set(PROBES) - set(layout))

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]

SE = 'RbxSubEntity@Ogre@@'
SR = 'RbxSubEntityShadowRenderable@RbxSubEntity@Ogre@@'
ROWS = {
    'sub_entity': [
        (0x6851d0, '??0' + SR + 'QAE@PAVEntity@2@PAVHardwareIndexBufferSharedPtr@2@PBVVertexData@2@_NPAV12@3@Z'),
        (0x6853a0, '??1' + SR + 'UAE@XZ'),
        (0x685640, '??_G' + SR + 'UAEPAXI@Z'),
        (0x685450, '?getWorldTransforms@' + SR + 'UBEXPAVMatrix4@3@@Z'),
        (0x685460, '?getWorldOrientation@' + SR + 'UBEABVQuaternion@3@XZ'),
        (0x685470, '?getWorldPosition@' + SR + 'UBEABVVector3@3@XZ'),
        (0x684fa0, '?getPositionBuffer@' + SR + 'QAE?AVHardwareVertexBufferSharedPtr@3@XZ'),
        (0x685480, '?isVisible@' + SR + 'UBE_NXZ'),
        (0x685660, '??0' + SE + 'QAE@PAVEntity@1@@Z'),
        (0x685850, '??0' + SE + 'QAE@PAVEntity@1@PAVSubMesh@1@H@Z'),
        (0x685910, '??1' + SE + 'UAE@XZ'),
        (0x685a20, '??_G' + SE + 'UAEPAXI@Z'),
        (0x685840, '??_E' + SE + 'WOM@AEPAXI@Z'),
        (0x684fd0, '?getRenderOperation@' + SE + 'UAEXAAVRenderOperation@2@@Z'),
        (0x685710, '?getWorldTransforms@' + SE + 'UBEXPAVMatrix4@2@@Z'),
        (0x685730, '?getWorldOrientation@' + SE + 'UBEABVQuaternion@2@XZ'),
        (0x685010, '?getSquaredViewDepth@' + SE + 'UBEMPBVCamera@2@@Z'),
        (0x685820, '?setCustomValue@' + SE + 'UAEXM@Z'),
        (0x685830, '?getCustomValue@' + SE + 'UBEMXZ'),
        (0x685700, '?getCastShadows@' + SE + 'UBE_NXZ'),
        (0x685170, '?getEdgeList@' + SE + 'UAEPAVEdgeData@2@XZ'),
        (0x6851a0, '?hasEdgeList@' + SE + 'UAE_NXZ'),
        (0x685100, '?getLightCapBounds@' + SE + 'UBEABVAxisAlignedBox@2@XZ'),
        (0x685590, '?getDarkCapBounds@' + SE + 'UBEABVAxisAlignedBox@2@ABVLight@2@M@Z'),
        (0x685110, '?getPointExtrusionDistance@' + SE + 'UBEMPBVLight@2@@Z'),
        (0x6850a0, '?setMaterial@' + SE + 'QAEXABVMaterialPtr@2@@Z'),
        (0x6850b0, '?setSubMesh@' + SE + 'QAEXHPAVSubMesh@2@@Z'),
        (0x6850d0, '?getSubMesh@' + SE + 'QAEPAVSubMesh@2@H@Z'),
        (0x6850f0, '?setLod@' + SE + 'QAEXH@Z'),
        (0x685140, '?getCoarsestSubMesh@' + SE + 'QAEPAVSubMesh@2@XZ'),
    ],
}
NON_EXACT_ROWS = [
    (0x6857e0, '?getWorldPosition@' + SE + 'UBEABVVector3@2@XZ', 'sub_entity',
     '63 / 63 B: only the static-guard store `or [guard], 1` is scheduled one fld later than in the original (the '
     'original sets the guard before the three translation loads). Tried: `static Vector3 position = '
     'mTransform.getTrans()` (this source), Vector3(m[0][3], m[1][3], m[2][3]) direct / copy init, a const static, a '
     'Matrix4 reference local, Vector3(getTrans()) and position(getTrans()) (all 63 B, same pair), a non-static '
     'translation local (75 B), /fp:precise (81 B), VS2005 50727 (same pair; 7 of the 31 rows exact).'),
]
# Declared, not built (exe-local SubMesh subclass members): bound by address for the vtable slot checks only.
NOT_BUILT = {
    '?getWorldBoundingBox@' + SE + 'UBEABVAxisAlignedBox@2@_N@Z': 0x685490,
    '?getShadowVolumeRenderableIterator@' + SE + 'UAE?AV?$VectorIterator@V?$vector@PAVShadowRenderable@Ogre@@V?$alloc'
    'ator@PAVShadowRenderable@Ogre@@@std@@@std@@@2@W4ShadowTechnique@2@PBVLight@2@PAVHardwareIndexBufferSharedPtr@2@_N'
    'MK@Z': 0x685a40,
}
EXTERNAL = {
    '??2@YAPAXI@Z': 0x6a0920, '??3@YAXPAX@Z': 0x6a067a,         # operator new / delete (ShadowRenderable 00685234)
    '__CxxThrowException@8': 0x6a158c,                           # getEdgeList 00685195
    '___RTDynamicCast': 0x6a17c6,                                # getSquaredViewDepth 0068504a
    '_atexit': 0x6a17af,                                         # getDarkCapBounds 006855d7
}
LOCAL_STATIC_AT = {}                                             # symbol -> address, filled from the patterns below
LOCAL_STATIC = [
    (r'^\?darkCapBounds@\?1\?\?getDarkCapBounds@' + SE, 0x97dbf0),        # 006855f1
    (r'^\?\$S\d+@\?1\?\?getDarkCapBounds@' + SE, 0x97dc10),                  # guard 006855b1
    (r'^\?orientation@\?1\?\?getWorldOrientation@' + SE, 0x97dc14),       # 006857b8
    (r'^\?\$S\d+@\?1\?\?getWorldOrientation@' + SE, 0x97dc24),              # guard 00685790
]
THROW_INFO = {}
UNBOUND = []
FOLDED = {}
binding = {}
support_out = {}


def target_of(address):
    body, refs, _ = match.target('2008-06', '%08x' % address)
    return body, refs


def throw_info_type(ti):
    array = d(ti + 12)
    return original.string(d(d(array + 4) + 4) + 8)


FUNCTIONS = {int(json.loads(l)['addr'], 16) for l in
             (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines() if l.strip()}
BODIES = {}
for key in SOURCES:
    for n, b, r in match.coff_functions(Path(OBJ[key]).read_bytes()):
        BODIES.setdefault(n, (b, r, key))


def try_fold(symbol, value):
    """Bind a call to a body the linker folded elsewhere (or a compiler-generated helper outside the block): the body
    compiled here must equal the target exactly."""
    if symbol not in BODIES or value not in FUNCTIONS:
        return False
    body, refs, _ = BODIES[symbol]
    target, target_refs = target_of(value)
    if not match.exact_match(target, target_refs, body, refs):
        return False
    FOLDED.setdefault(symbol, value)
    return FOLDED[symbol] == value


def local_static(symbol, value):
    for pattern, address in LOCAL_STATIC:
        if re.match(pattern, symbol):
            prev = LOCAL_STATIC_AT.setdefault(symbol, address)
            return prev == value == address
    return False


def resolve(rows, which):
    funcs = {n for n, _, _ in match.coff_functions(Path(OBJ[which]).read_bytes())}
    for address, name in rows:
        assert name in funcs or DISCOVER, ('%08x' % address, name)
    return [(a, n) for a, n in rows if n in funcs]


def verify(which, rows, own, strict=True, record=True):
    raw = Path(OBJ[which]).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    result = []
    for address, name in rows:
        body, refs = bodies[name]
        target, target_refs = target_of(address)
        exact = match.exact_match(target, target_refs, body, refs)
        entry = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target), 'exact': exact}
        if not exact:
            assert not strict or DISCOVER, (name, entry['address'], len(body), len(target))
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
            if nb.LOCAL_EH.match(symbol):
                local.add(symbol)
                continue
            hit = original.imported(value)
            if hit is not None:
                assert hit[1] == nb.plain(symbol), (name, symbol, hex(value), hit)
                how = '%s!%s' % hit
            elif symbol.startswith('__real@'):
                assert original.data(value, len(symbol[7:]) // 2) == bytes.fromhex(symbol[7:])[::-1], (name, symbol, hex(value))
                how = 'constant %s' % symbol[7:]
            elif symbol.startswith('??_C@'):
                pos, at = definitions[symbol]
                literal = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
                assert original.data(value, len(literal)) == literal, (name, symbol, hex(value))
                how = 'string %r' % literal[:-1].decode('latin-1')
            elif symbol.startswith('__TI'):
                cls = '.?AV' + symbol[symbol.index('?AV') + 3:]
                assert throw_info_type(value) == cls, (name, symbol, hex(value), throw_info_type(value))
                THROW_INFO[symbol] = (value, cls)
                how = 'throw info %s' % cls
            elif symbol.startswith('??_R0?AV'):
                cls = symbol[5:symbol.rindex('@8')]
                assert original.string(value + 8) == '.' + cls, (name, symbol, hex(value), original.string(value + 8))
                how = 'type descriptor %s' % original.string(value + 8)
            elif symbol.startswith('??_7'):
                rtti, at = original.vtable_class(value)
                cls = symbol[4:symbol.index('@@6B') + 2]
                assert rtti == '.?AV' + cls, (name, symbol, hex(value), rtti)
                how = 'vtable RTTI %s offset %#x' % (rtti, at)
            elif symbol in own:
                assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
                how = 'own row'
            elif symbol.startswith('??_E') and '??_G' + symbol[4:] in own:
                # the adjustor thunk 00685840 jumps to the scalar deleting destructor row (vector form not emitted)
                assert own['??_G' + symbol[4:]] == value, (name, symbol, hex(value))
                how = 'own ??_G row (deleting destructor)'
            elif symbol in EXTERNAL:
                assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
                how = 'external' + (' (evidence name)' if names.get(value, '') == symbol else '')
            elif local_static(symbol, value):
                how = 'local static'
            elif try_fold(symbol, value):
                how = 'folded / helper body, compared exact'
            else:
                UNBOUND.append("    %r: %#x,   # %s in %s" % (symbol, value, names.get(value, '')[:60], name[:60]))
                continue
            if record:
                prev = binding.setdefault(symbol, (value, name))
                assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
            verified[symbol] = '%s (%s)' % (hex(value), how)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local)})
        result.append(entry)
    return result


resolved = {k: resolve(rows, k) for k, rows in ROWS.items()}
own = {}
for rows in resolved.values():
    for address, name in rows:
        own.setdefault(name, address)
groups = {k: verify(k, rows, own) for k, rows in resolved.items()}
non_out = []
for address, key, which, why in NON_EXACT_ROWS:
    row = verify(which, resolve([(address, key)], which), own, strict=False, record=False)[0]
    assert not row['exact'] or DISCOVER, ('non-exact row unexpectedly exact', row['address'])
    row.update({'exact': False, 'reason': why})
    non_out.append(row)

folded_out, seen = [], set()
while True:
    todo = [(a, s) for s, a in FOLDED.items() if s not in seen]
    if not todo:
        break
    for address, symbol in todo:
        seen.add(symbol)
        for row in verify(BODIES[symbol][2], [(address, symbol)], own, not DISCOVER):
            row['folded_exact'], row['exact'] = row['exact'], False
            row['reason'] = 'body outside this block (folded by the linker or a compiler helper); compared, not counted'
            folded_out.append(row)

if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for g in list(groups.values()) + [folded_out]:
        for r in g:
            if not r['exact']:
                print('NOT EXACT', r['address'], r['symbol'][:110], r['size'], r['target_size'], r.get('folded_exact'))
    sys.exit(0)
assert not UNBOUND, '\n'.join(UNBOUND)
assert all(r['folded_exact'] for r in folded_out)
assert len(LOCAL_STATIC_AT) == len(LOCAL_STATIC), LOCAL_STATIC_AT
for symbol, address in list(EXTERNAL.items()) + list(FOLDED.items()) + list(NOT_BUILT.items()):
    assert address in FUNCTIONS, (symbol, hex(address))
assert any(v[1] == '.?AVexception@std@@' for v in THROW_INFO.values())

# ---- structure: allocation sizes before the constructor calls, RTTI bases --------------------------------------------


def new_before(call_site, ctor, size):
    window = original.data(call_site - 0x60, 0x65)
    assert window[-5] == 0xe8 and call_site + 5 + struct.unpack_from('<i', window, 0x61)[0] == ctor, hex(call_site)
    push = (b'\x6a' + bytes([size])) if size < 0x80 else (b'\x68' + struct.pack('<I', size))
    at = window.rindex(push + b'\xe8')
    assert call_site - 0x60 + at + len(push) + 5 + struct.unpack_from('<i', window, at + len(push) + 1)[0] == 0x6a0920, \
        hex(call_site)


new_before(0x671de9, 0x685660, 0x15c)          # AdornRbxGfx: new(0x15c) RbxSubEntity(entity)
new_before(0x685c3b, 0x6851d0, 0x70)           # getShadowVolumeRenderableIterator: new(0x70) shadow renderable
new_before(0x685379, 0x6851d0, 0x70)           # the light-cap recursion


def bases(vtable):
    hierarchy = d(d(vtable - 4) + 16)
    out = {}
    for i in range(d(hierarchy + 8)):
        bcd = d(d(hierarchy + 12) + 4 * i)
        out.setdefault(original.string(d(bcd) + 8), struct.unpack('<i', original.data(bcd + 8, 4))[0])
    return out


assert bases(0x84e90c) == {'.?AVRbxSubEntity@Ogre@@': 0, '.?AVSubEntity@Ogre@@': 0, '.?AVRenderable@Ogre@@': 0,
                           '.?AVShadowCaster@Ogre@@': 0xec}
assert bases(0x84e88c) == {'.?AV' + SR + '': 0, '.?AVShadowRenderable@Ogre@@': 0, '.?AVRenderable@Ogre@@': 0}

# ---- vtables from the object built with the current header, slot by slot --------------------------------------------
slot_names = {}
for table_ in (own, FOLDED, EXTERNAL, NOT_BUILT, {r[1]: r[0] for r in NON_EXACT_ROWS}):
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
        hit = original.imported(value)
        if slot.startswith('??_E') and '??_G' + slot[4:] in slot_names:
            ok, how = slot_names['??_G' + slot[4:]] == value, 'bound (??_G)'
        elif slot in slot_names:
            ok, how = slot_names[slot] == value, 'bound'
        elif hit is not None:
            ok, how = hit[1] == nb.plain(slot), 'import thunk %s!%s' % hit
        else:
            ok, how = False, 'unbound'
        out.append({'slot': i, 'symbol': slot, 'original': '%08x' % value, 'ok': ok, 'how': how})
        if not ok:
            bad.append((i, slot, hex(value), how))
    assert not bad, (symbol, bad)
    return out


vt = {'RbxSubEntity@Ogre 0084e90c': check_vtable(OBJ['sub_entity'], '??_7' + SE + '6BSubEntity@1@@', 0x84e90c),
      'RbxSubEntity@Ogre (ShadowCaster) 0084e8d4': check_vtable(OBJ['sub_entity'], '??_7' + SE + '6BShadowCaster@1@@',
                                                               0x84e8d4),
      'RbxSubEntityShadowRenderable 0084e88c': check_vtable(OBJ['sub_entity'], '??_7' + SR + '6B@', 0x84e88c)}
assert [len(v) for v in vt.values()] == [20, 12, 17], [len(v) for v in vt.values()]


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
                out.setdefault('%08x' % int(m.group(1), 16), []).append(Path(path).name)
    return out


elsewhere = counted_elsewhere()
exact_rows = sorted({r['address'] for rows in groups.values() for r in rows if r['exact']})
double = {a: elsewhere[a] for a in exact_rows if a in elsewhere}
assert not double, double
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if RANGE[0] <= a < RANGE[1]}
range_functions = sorted('%08x' % a for a in FUNCTIONS if int(RANGE[0], 16) <= a < int(RANGE[1], 16))

UNIT_MAP = {
    'visual-engine tail 0067c000..0067c4c0': (
        'VisualEngine unit (ogre-visual-engine-working.json, pending-build-only there): 0067c020 (boost::call_once '
        '0054ab60 / flag 00973984, then the SubMesh name map 0097db44 and Mesh::createSubMesh; ret 0x10), 0067c130 '
        '(896 B, boost thread_exception / call_once helpers), ??_G VisualEngine 0067c4b0 (vtable 0084df2c slot 0). '
        'Library-shaped boost code and pending VisualEngine rows; not built here.'),
    'rbx-entity 0067c4d0..0067f16f': (
        'Ogre::RbxEntity (RTTI 0084e45c -> Entity -> MovableObject -> ShadowCaster, AnimableObject +0x4, '
        'Resource::Listener +0xc8; secondary vtables 0084e448 / 0084e43c). Size 0x2bc (new 0x2bc at 0067452d / 007ab470 '
        'before the constructor 0067d1f0); imported Entity() / ~Entity (Entity is 0x274). Constructor / destructor '
        '0067d420: +0x274 4-byte value (setter 0067c510), bools +0x278 / +0x27a = true, +0x279 (set by slot 24 '
        '0067c570), AxisAlignedBox +0x27c, float +0x29c = [008222f0], int +0x2a0 = 0x378, std::vector +0x2a4..+0x2bb '
        '(aux proxy, first/last/end +0x2b0); the destructor deletes every SubEntity via dynamic_cast<RbxSubEntity*> '
        '(TD 0096301c) and erases the Entity +0xd8 vector. Rows: 0067c4d0 (InvalidParametersException factory, Ogre '
        'header template), 0067c510, 0067c520 (MeshPtr assign at +0xcc), 0067c570, 0067c5a0, STL instantiations '
        '0067c5e0..0067d1a0 / 0067d580 / 0067d5b0 / 0067d600 / 0067d820 / 0067d8f0 / 0067da70 (Vector4, Plane, '
        'double sort, 8/12/16-byte PODs, String vectors), constructor 0067d1f0, removeSubEntity 0067d2d0, 0067d3d0, '
        'destructor 0067d420, ??_G 0067d5e0, 0067d9b0 (news RbxSubEntity 00685850 at 0067d9f3), 0067da50, slot 53 '
        '0067daf0 (2039 B), 0067e2f0 (3704 B). Not built: RenderLib/AggregateChunk2008.h (render-scene owner) already '
        'declares Ogre::RbxEntity (removeSubEntity only, no base), so this unit sends a proposal instead of '
        'redeclaring it.'),
    'rbx-sky 0067f170..0068118f': (
        'Ogre::RbxSky (ogre-rbx-sky-working.json: the vector COMDATs are counted there, RbxSky members are '
        'pending-build-only) and the exe-local ManualObject rows 00681160 / 00681180 (ogre-rbx-locals).'),
    'rbx-scene-node 00681190..006843ef': (
        'Ogre::RbxSceneNode / TwoDManager (ogre-rbx-node-working.json). Uncounted there: 00682150 (map erase by key), '
        '00682430 (prepares the edge list of an exe-local SubMesh subclass: +0xc4 bool, +0xc8 = EdgeListBuilder::build; '
        'called by the RbxSubEntity iterator 00685a92), 006824e0 (its destructor: ~EdgeData +0xc8, ~AxisAlignedBox '
        '+0xcc, imported ~SubMesh; called by 0054ac7a), 006825b0, 006829a0, 00682ad0, 00682c70 and render 006832b0.'),
    'rbx-font 006843f0..00684f9f': (
        'Ogre::RbxFont (SharedPtr<RbxFont> vtable 0084d1d4): 006843f0 / 00684640 (STL helpers), 00684730 (draws a '
        'string through TwoDManager::addQuad 00682d60; caller 0066fe0c), 00684b10 (loads the "ft%d" textures from a '
        'G3D BinaryInput into MemoryDataStreams; called by 00684f42), 00684eb0 (creates the SharedPtr<RbxFont>; '
        'caller AdornRbxGfx 00674398). No declaration is derived (constructor size not read); not built.'),
    'rbx-sub-entity 00684fa0..00685e07': (
        'Ogre::RbxSubEntity and RbxSubEntity::RbxSubEntityShadowRenderable (built here; header '
        'AppUnit67C_2008/RbxSubEntity2008.h). getPositionBuffer 00684fa0 (only caller the iterator 00685c9c) starts '
        'the block; the vtables 0084e90c / 0084e8d4 / 0084e88c reference every virtual row; the iterator 00685a40 '
        '(968 B) ends at 00685e07. Not built: getWorldBoundingBox 00685490 and getShadowVolumeRenderableIterator '
        '00685a40 (exe-local SubMesh subclass +0xc8 / +0xec).'),
    'mesh-builders 00685e10..': (
        '00685e10 (Vector3 setter at +0x20) and 00685e30 (initialises a 0x2c-byte parameter block: +0 / +8 = 0, '
        '+4 = false, +0xc = 2, +0x10..+0x1c colour from 0081c3b8, +0x20 Vector3 zero), both called only by '
        'AdornRbxGfx 00672751..00673774 next to the builders 00685ea0 (6588 B, frame 0x180c; callers 006727c5 / '
        '00673678 / 006736f4) and 00687860 (6738 B; caller 0068b5fd), which run past 00688000 (next row 006892b2). '
        'Owner and parameter type not derived; not built.'),
}
PROPOSALS = {
    'RenderLib/AggregateChunk2008.h (render-scene owner): Ogre::RbxEntity': (
        'The minimal Ogre::RbxEntity there (removeSubEntity 0067d2d0 only, no base) is the only native declaration of '
        'the class. Evidence for a full one: RTTI 0084e45c RbxEntity -> Entity (Entity 0x274, rgmain import, ctor '
        'Entity() 0x80449c, ~Entity 0x804460), size 0x2bc (new 0x2bc 0067452d / 007ab470), constructor 0067d1f0 / '
        'destructor 0067d420 (members listed in unit_map rbx-entity). With `class RbxEntity : public Entity` and those '
        'members the RbxEntity unit 0067c4d0..0067f16f can be built here against it (the owner would include '
        'OgreEntity.h; its units already use the Ogre include path).'),
    'Ogre::RbxSubEntity users (RbxGraphics/AdornRbxGfx2008.h, RenderLib/AggregateChunk2008.h)': (
        'Ogre::RbxSubEntity is now declared in native-headers/AppUnit67C_2008/RbxSubEntity2008.h (0x15c, '
        'constructors 00685660 / 00685850, vtables 0084e90c / 0084e8d4). The forward declarations can include it once '
        'their units need a complete type (RbxSceneManager::renderSingleObject 0069bc50 reads mTransform +0xf0).'),
    'exe-local SubMesh subclass (owner not derived)': (
        'getWorldBoundingBox 00685490 / getShadowVolumeRenderableIterator 00685a40 read +0xc8 (EdgeData*, built by '
        '00682430) and +0xec (a radius scaled by [0083785c]) of the selected sub-mesh; the imported SubMesh is 0xc4 '
        'bytes and the subclass destructor is 006824e0 (AxisAlignedBox at +0xcc). Its constructor and size are not '
        'found, so no declaration is written; with one, both rows can be built in this unit.'),
}

sha = nb.sha
receipt = {
    'class': 'Ogre::RbxSubEntity / RbxSubEntityShadowRenderable unit of the application range 0067c000..00688000 '
             '(2008-06), inactive',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM), /fp:fast',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in
                [Path(__file__).resolve(), HEADER] + list(SOURCES.values())},
    'objects': {k: sha(v) for k, v in OBJ.items()},
    'layout': layout,
    'unit_map': UNIT_MAP,
    'range_functions': len(range_functions),
    'range_rows_counted_by_other_receipts': range_counted,
    'rows': groups,
    'folded_not_counted': folded_out,
    'not_exact': non_out,
    'not_built': {k: '%08x' % v for k, v in NOT_BUILT.items()},
    'vtables': vt,
    'exact_function_rows': exact_rows,
    'proposals': PROPOSALS,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit67c-2008: %d counted exact rows (%s); %d not exact, %d folded/helper rows compared; %d range rows '
      'counted elsewhere; %d vtables verified'
      % (len(exact_rows), ' '.join(exact_rows), len(non_out), len(folded_out), len(range_counted), len(vt)))
