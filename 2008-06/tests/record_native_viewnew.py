"""Verify the inactive native RBX::ViewNew mesh builders / meshes and their RenderBase::Mesh base (2008-06).

Builds (document-swap flags, VS2008 RTM 21022, /fp:fast), all from the current native headers
(native-headers/ViewNew/*.h; no shared header is touched and no donor header is shadowed: the donor tree has no
ViewNew/ directory):
  * tests/NativeViewNewLayout.cpp       sizeof/offset probes (mov eax, imm32; ret);
  * native-classes/ViewNewQuadVolume.cpp LevelBuilder (00500ca0..0050103f) + G3D::Array<unsigned>::append(3) 00500690;
  * native-classes/ViewNewBevelMesh.cpp  BevelMesh::Builder::build 00501040;
  * native-classes/ViewNewSphereMesh.cpp SphereBuilder / SphereMesh (004fce90..004fd40f), the vertex function kept
                                         at 004fabb0, the header-inline Level constructor 004dd2e0, ??_G rows;
  * native-classes/ViewNewCylinderMesh.cpp CylinderBuilder / CylinderAlongXMesh (004fd430..004fdaef);
  * native-classes/ViewNewHeadMesh.cpp   HeadBuilder / HeadMesh (004fdaf0..0050068f).

Every exact row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified: imports by DLL export name, constants by bytes, type descriptors and
vtables by original RTTI names, own symbols by the row proven here, folded bodies by their address, switch tables by
their position inside the row, and the remaining externals by the explicit EXTERNAL map (call sites read in the
original disassembly; checked below against the bodies they name). A symbol binds to one address across all rows.
Vtables are compared slot by slot from the objects built with the current headers. Rows that are not exact are
recorded with exact=false and a reason and are not counted.
Writes work/2008-06/shared-layouts/viewnew-working.json. Set NATIVE_VIEWNEW_DISCOVER=1 to list unbound targets and
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
LAYOUT = R / 'tests/NativeViewNewLayout.cpp'
UNITS = {
    'quad': R / 'native-classes/ViewNewQuadVolume.cpp',
    'bevel': R / 'native-classes/ViewNewBevelMesh.cpp',
    'sphere': R / 'native-classes/ViewNewSphereMesh.cpp',
    'cylinder': R / 'native-classes/ViewNewCylinderMesh.cpp',
    'head': R / 'native-classes/ViewNewHeadMesh.cpp',
}
HEADERS = sorted((R / 'native-headers/ViewNew').glob('*.h'))
DISCOVER = bool(os.environ.get('NATIVE_VIEWNEW_DISCOVER'))


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeViewNewLayout', LAYOUT, ['/fp:fast'])
OBJ, FLAGS = {}, {'layout': layout_flags}
for key, src in UNITS.items():
    OBJ[key], FLAGS[key] = build('NativeViewNew_' + key, src, ['/fp:fast'])

# ---- layout -------------------------------------------------------------------------------------------------------
# Evidence: Mesh ctor 00548570 (member ctors at +0xc / +0x18 / +0x50 / +0x68, stores +0x4c / +0x80 / +0x84), the
# factories 004eea30 / 004eef30 / 004ef430 (push 0x8c before 004fcfb0 / 004fd6b0 / 00500180), SphereMesh 004fcfb0
# (push 0x28 before the Level ctor 004dd2e0, which stores +0xc..+0x24), LevelBuilder ctor 00500d80 (+0x4..+0x1c),
# the BevelMesh::Builder copy ctor 004f6e30 (+0x20), the face slots (+0x20 / +0x24), CylinderBuilder ctor 004fd430
# (+0x20), HeadBuilder ctor 004fdaf0 (+0x20 / +0x24), ShadowSurface ctor 0054a9f0 (+0x30 last member).
raw = layout_obj.read_bytes()
SIZES = {
    'meshSize': 0x88, 'meshLevels': 0xc, 'meshShadowSurface': 0x18, 'meshDebugBoundingRadius': 0x4c,
    'meshShadowIndices': 0x50, 'meshShadowVertices': 0x68, 'meshSubMesh': 0x80, 'meshKind': 0x84,
    'shadowSurfaceSize': 0x34, 'levelSize': 0x28, 'levelIndexArray': 0xc, 'levelPrimitive': 0x18, 'levelDirty': 0x1c,
    'levelVertexStart': 0x20, 'levelSubMesh': 0x24, 'levelBuilderSize': 0x20, 'levelBuilderHalfSize': 0x4,
    'levelBuilderSurfaceTypes': 0x10, 'levelBuilderLevel': 0x14, 'levelBuilderTextureScale': 0x18,
    'bevelBuilderSize': 0x24, 'bevelBuilderBevel': 0x20, 'sphereBuilderSize': 0x24, 'sphereBuilderElements': 0x20,
    'cylinderBuilderSize': 0x24, 'cylinderBuilderElements': 0x20, 'headBuilderSize': 0x28, 'headBuilderBevel': 0x20,
    'headBuilderElements': 0x24, 'sphereMeshSize': 0x8c, 'cylinderMeshSize': 0x8c, 'headMeshSize': 0x8c,
    'bevelMeshSize': 0x88,
}
for fn, size in SIZES.items():
    name_, body_, _ = next(x for x in match.coff_functions(raw) if x[0].startswith('?native' + fn + '@@'))
    assert body_ == b'\xb8' + struct.pack('<I', size) + b'\xc3', (fn, body_.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]

LEVEL = '?$ReferenceCountedPointer@VLevel@Mesh@RenderBase@RBX@@@G3D@@'
FN = 'P6AXAAVVector3@G3D@@0AAVVector2@2@ABV12@ABVVector2int16@2@@Z'
EXTERNAL = {
    '??2@YAPAXI@Z': 0x6a0920, '??3@YAXPAX@Z': 0x6a067a,
    '??0Mesh@RenderBase@RBX@@IAE@XZ': 0x548570,               # stores the Mesh vtable 0082d028 (checked below)
    '??1Mesh@RenderBase@RBX@@UAE@XZ': 0x548a90,               # stores 0082d028 first (checked below)
    '??1Level@Mesh@RenderBase@RBX@@UAE@XZ': 0x5489b0,         # stores the Level vtable 00826e4c first (checked below)
    '?allocVertex@Mesh@RenderBase@RBX@@SAIII@Z': 0x547fc0,    # returns its first argument after the ref-count update
    '?ReferenceCountedObject_zeroWeakPointers@ReferenceCountedObject@G3D@@QAEXXZ': 0x45ad90,   # evidence name
    '?setPointer@' + LEVEL + 'AAEXPAVLevel@Mesh@RenderBase@RBX@@@Z': 0x598fa0,                # ICF (evidence: Shader)
    '?append@?$Array@V' + LEVEL + '@G3D@@QAEXABV?$ReferenceCountedPointer@VLevel@Mesh@RenderBase@RBX@@@2@@Z': 0x4dcbb0,  # push_back
    '?append@?$Array@I@G3D@@QAEXABI000@Z': 0x4dc6a0,          # 4-value append (00500eb0 QUADS case)
    '?resize@?$Array@I@G3D@@QAEXH_N@Z': 0x4805b0,              # 00500722
    '?mapToUvw_Legacy@RBX@@YA?AVVector3@G3D@@ABV23@W4NormalId@1@@Z': 0x5ec9d0,                  # evidence name
    '?xy@Vector3@G3D@@QBE?AVVector2@2@XZ': 0x5185d0,          # ICF with Rect2D::x0y0 (evidence name)
    '?yz@Vector3@G3D@@QBE?AVVector2@2@XZ': 0x518610,          # 004fd53f
}
# The per-face grid template LevelBuilder::buildFace<NormalId, Function>(Function, Vector2int16, Purpose): instances not
# recovered here; each is bound to the address its call sites in the original use (the face slots of every builder
# that shares the instance agree: SphereBuilder and CylinderBuilder share the plain function-pointer instances, whose
# bodies sit in the TorsoMesh unit 004fbdb0..004fcbc0; HeadBuilder's EndcapTransform instances sit at 004fef10 /
# 004ff1e0). Checked below: each address starts a function of the original list inside 004fbdb0..004ffd40.
FACE = ('@LevelBuilder@ViewNew@RBX@@IAEXP6AXAAVVector3@G3D@@0AAVVector2@4@ABV34@ABVVector2int16@4@@ZV64@'
        'W4Purpose@012@@Z')
ENDCAP = ('VEndcapTransform@ViewNew@RBX@@@LevelBuilder@ViewNew@RBX@@IAEXVEndcapTransform@12@VVector2int16@G3D@@'
          'W4Purpose@012@@Z')
BUILD_FACE = {
    '??$buildFace@$0A@' + FN + FACE: 0x4fbdb0,      # NORM_X     (SphereBuilder 004fceab, CylinderBuilder 004fd5ab)
    '??$buildFace@$00' + FN + FACE: 0x4fc080,       # NORM_Y     (004fcedb, 004fd5e1)
    '??$buildFace@$01' + FN + FACE: 0x4fc350,       # NORM_Z     (004fcf0b, 004fd611)
    '??$buildFace@$02' + FN + FACE: 0x4fc620,       # NORM_X_NEG (004fcf3b, 004fd63b)
    '??$buildFace@$03' + FN + FACE: 0x4fc8f0,       # NORM_Y_NEG (004fcf6b, 004fd671)
    '??$buildFace@$04' + FN + FACE: 0x4fcbc0,       # NORM_Z_NEG (004fcf9b, 004fd6a1)
    '??$buildFace@$00' + ENDCAP: 0x4fef10,          # HeadBuilder::buildTop 00500044
    '??$buildFace@$03' + ENDCAP: 0x4ff1e0,          # HeadBuilder::buildBottom 00500074
}
EXTERNAL.update(BUILD_FACE)
DATA = {}
FOLDED = {}
LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
binding = {}

QUAD_ROWS = [
    (0x500ca0, '?buildFace@LevelBuilder@ViewNew@RBX@@QAEXW4NormalId@3@W4Purpose@123@@Z'),
    (0x500d30, '?build@LevelBuilder@ViewNew@RBX@@UAEXW4Purpose@123@@Z'),
    (0x500d80, '??0LevelBuilder@ViewNew@RBX@@IAE@AAV' + LEVEL + 'VVector3@4@VRenderSurfaceTypes@12@@Z'),
    (0x500de0, '?appendQuadFromVertexIndices@LevelBuilder@ViewNew@RBX@@IAEXIII@Z'),
    (0x500eb0, '?appendQuadFromVertexIndices@LevelBuilder@ViewNew@RBX@@IAEXIIII@Z'),
    (0x500fd0, '?appendQuadFromIndexArray@LevelBuilder@ViewNew@RBX@@IAEXHHH@Z'),
    (0x501000, '?appendQuadFromIndexArray@LevelBuilder@ViewNew@RBX@@IAEXHHHH@Z'),
    (0x500690, '?append@?$Array@I@G3D@@QAEXABI00@Z'),
]
BEVEL_ROWS = [
    (0x501040, '?build@Builder@BevelMesh@ViewNew@RBX@@UAEXW4Purpose@LevelBuilder@34@@Z'),
]
SPHERE_ROWS = [
    (0x4fce90, '?buildRight@SphereBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z'),
    (0x4fcec0, '?buildTop@SphereBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z'),
    (0x4fcef0, '?buildBack@SphereBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z'),
    (0x4fcf20, '?buildLeft@SphereBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z'),
    (0x4fcf50, '?buildBottom@SphereBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z'),
    (0x4fcf80, '?buildFront@SphereBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z'),
    (0x4fcfb0, '??0SphereMesh@ViewNew@RBX@@QAE@ABVVector3@G3D@@VRenderSurfaceTypes@12@@Z'),
    (0x4fd270, '??0SphereMesh@ViewNew@RBX@@QAE@ABVVector3@G3D@@W4NormalId@2@ABVVector2@4@@Z'),
    (0x4fabb0, '?SphereTransform@ViewNew@RBX@@YAXAAVVector3@G3D@@0AAVVector2@4@ABV34@ABVVector2int16@4@@Z'),
    (0x4dd2e0, '??0Level@Mesh@RenderBase@RBX@@QAE@W4Primitive@RenderDevice@G3D@@@Z'),
    (0x4dd340, '??_GLevel@Mesh@RenderBase@RBX@@UAEPAXI@Z'),
    (0x4e54c0, '??_GSphereMesh@ViewNew@RBX@@UAEPAXI@Z'),
]
CYLINDER_ROWS = [
    (0x4fd430, '??0CylinderBuilder@ViewNew@RBX@@QAE@AAV' + LEVEL + 'VVector3@4@VRenderSurfaceTypes@12@I@Z'),
    (0x4fd4a0, '?EndcapTransform@ViewNew@RBX@@YAXAAVVector3@G3D@@0AAVVector2@4@ABV34@ABVVector2int16@4@@Z'),
    (0x4fd530, '?CylinderTransform@ViewNew@RBX@@YAXAAVVector3@G3D@@0AAVVector2@4@ABV34@ABVVector2int16@4@@Z'),
    (0x4fd590, '?buildRight@CylinderBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z'),
    (0x4fd5c0, '?buildTop@CylinderBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z'),
    (0x4fd5f0, '?buildBack@CylinderBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z'),
    (0x4fd620, '?buildLeft@CylinderBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z'),
    (0x4fd650, '?buildBottom@CylinderBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z'),
    (0x4fd680, '?buildFront@CylinderBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z'),
    (0x4fd6b0, '??0CylinderAlongXMesh@ViewNew@RBX@@QAE@ABVVector3@G3D@@VRenderSurfaceTypes@12@@Z'),
    (0x4fd800, '??0CylinderAlongXMesh@ViewNew@RBX@@QAE@ABVVector3@G3D@@W4NormalId@2@@Z'),
    (0x4fd960, '??0CylinderAlongXMesh@ViewNew@RBX@@QAE@ABVVector3@G3D@@W4NormalId@2@ABVVector2@4@@Z'),
    (0x4e54c0, '??_GCylinderAlongXMesh@ViewNew@RBX@@UAEPAXI@Z'),
]
HEAD_ROWS = [
    (0x4fdaf0, '??0HeadBuilder@ViewNew@RBX@@QAE@V' + LEVEL + 'VVector3@4@VRenderSurfaceTypes@12@IM@Z'),
    (0x4fdbd0, '??RCylinderTransform@ViewNew@RBX@@QAEXAAVVector3@G3D@@0AAVVector2@4@ABV34@ABVVector2int16@4@@Z'),
    (0x500020, '?buildTop@HeadBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z'),
    (0x500050, '?buildBottom@HeadBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z'),
    (0x500180, '??0HeadMesh@ViewNew@RBX@@QAE@ABVVector3@G3D@@VRenderSurfaceTypes@12@@Z'),
    (0x4e54c0, '??_GHeadMesh@ViewNew@RBX@@UAEPAXI@Z'),
]
NON_EXACT_ROWS = [
    (0x4fd110, '??0SphereMesh@ViewNew@RBX@@QAE@ABVVector3@G3D@@W4NormalId@2@@Z',
     'EH state numbering only: the original FuncInfo 008e597c has seven states, 1->0 / 2->0 / 3->2 with no unwind '
     'action before the live 4 (new Level) / 5 (level) / 6 (builder), i.e. three objects of an eliminated block; the '
     'source of that block is not derivable from the bytes', 'sphere'),
    (0x4fdcc0, '??REndcapTransform@ViewNew@RBX@@QAEXAAVVector3@G3D@@0AAVVector2@4@ABV34@ABVVector2int16@4@@Z',
     'x87 register allocation: the original keeps fabs(y) / fabs(x) from the comparison and spills the chosen one '
     'across the xy() call; no tried spelling reproduces the shared tail', 'head'),
    (0x500080, '?buildLeft@HeadBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z',
     'the original reloads elements (+0x24) after storing the functor (no CSE); tried temp / named functor, int / '
     'size_t member, reference parameter', 'head'),
    (0x5000c0, '?buildRight@HeadBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z', 'same as 00500080', 'head'),
    (0x500100, '?buildFront@HeadBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z', 'same as 00500080', 'head'),
    (0x500140, '?buildBack@HeadBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z', 'same as 00500080', 'head'),
    (0x500350, '??0HeadMesh@ViewNew@RBX@@QAE@ABVVector3@G3D@@W4NormalId@2@@Z',
     'register allocation around the null check of new Level (edi preset to 0 in the original)', 'head'),
    (0x5004d0, '??0HeadMesh@ViewNew@RBX@@QAE@ABVVector3@G3D@@W4NormalId@2@ABVVector2@4@@Z', 'same as 00500350', 'head'),
]
UNPROVEN = {}
# Vtable slots whose bodies are not built here (bound to the address the original vtable holds).
SLOT_EXTERNAL = {}

ROWS = {'quad': QUAD_ROWS, 'bevel': BEVEL_ROWS, 'sphere': SPHERE_ROWS, 'cylinder': CYLINDER_ROWS, 'head': HEAD_ROWS}


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
non_rows = [(resolve(OBJ[w], [(a, k)]), w) for a, k, _, w in NON_EXACT_ROWS]
own = {}
for rows in resolved.values():
    for address, name in rows:
        own.setdefault(name, address)
strict = not DISCOVER
groups = {k: verify(OBJ[k], rows, own, strict) for k, rows in resolved.items()}
non_out = []
for (rows, w), (_, _, why, _) in zip(non_rows, NON_EXACT_ROWS):
    if not rows:
        continue
    row = verify(OBJ[w], rows, own, strict=False, record=False)[0]
    if row['exact'] and not DISCOVER:
        raise AssertionError('non-exact row unexpectedly exact: %s' % row['address'])
    row['exact'], row['reason'] = False, why
    non_out.append(row)
if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for g in groups.values():
        for r in g:
            if not r['exact']:
                print('NOT EXACT', r['address'], r['symbol'][:110], r['size'], r['target_size'])
    for r in non_out:
        if r['exact']:
            print('NOW EXACT', r['address'])
    sys.exit(0)
assert not UNBOUND, '\n'.join(UNBOUND)

# ---- externals named by structure: the bodies they bind to store the expected vtables -------------------------------


def body_has(address, imm):
    body, _, _ = match.target('2008-06', '%08x' % address)
    return struct.pack('<I', imm) in body


assert body_has(0x548570, 0x82d028) and body_has(0x548a90, 0x82d028)   # Mesh ctor / dtor
assert body_has(0x5489b0, 0x826e4c)                                  # ~Level
FUNCTIONS = {int(json.loads(l)['addr'], 16): json.loads(l).get('size') for l in
             (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines() if l.strip()} \
    if (ROOT / 'work/2008-06/functions.jsonl').exists() else None
for symbol, address in BUILD_FACE.items():
    assert 0x4fbdb0 <= address <= 0x4ffd40, symbol
    if FUNCTIONS is not None:
        assert address in FUNCTIONS and FUNCTIONS[address] > 600, (symbol, hex(address))
assert original.vtable_class(0x82d028) == ('.?AVMesh@RenderBase@RBX@@', 0)
assert original.vtable_class(0x826e4c) == ('.?AVLevel@Mesh@RenderBase@RBX@@', 0)

# ---- vtables from the objects built with the current headers, slot by slot -----------------------------------------
slot_names = {}
for table_ in (own, FOLDED, EXTERNAL, UNPROVEN, SLOT_EXTERNAL):
    for k, v in table_.items():
        slot_names.setdefault(k, v)
for address, symbol, _, _ in NON_EXACT_ROWS:
    slot_names.setdefault(symbol, address)    # slot identity only; these rows stay uncounted


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
        ('quad', 'LevelBuilder@ViewNew@RBX', 0x8270c8, 7),
        ('sphere', 'SphereBuilder@ViewNew@RBX', 0x827134, 7),
        ('sphere', 'SphereMesh@ViewNew@RBX', 0x827154, 1),
        ('sphere', 'Level@Mesh@RenderBase@RBX', 0x826e4c, 1),
        ('cylinder', 'CylinderBuilder@ViewNew@RBX', 0x827164, 7),
        ('cylinder', 'CylinderAlongXMesh@ViewNew@RBX', 0x827184, 1),
        ('head', 'HeadBuilder@ViewNew@RBX', 0x827194, 7),
        ('head', 'HeadMesh@ViewNew@RBX', 0x8271b8, 1)):
    assert original.vtable_class(address) == ('.?AV%s@@' % cls, 0), (cls, original.vtable_class(address))
    vt[cls] = check_vtable(OBJ[key], '??_7%s@@6B@' % cls, address)
    assert len(vt[cls]) == count, (cls, len(vt[cls]))

# ---- RTTI bases (original) and the compiled base class descriptors -------------------------------------------------


def bases(vtable):
    hierarchy = d(d(vtable - 4) + 16)
    out = {}
    for i in range(d(hierarchy + 8)):
        bcd = d(d(hierarchy + 12) + 4 * i)
        out.setdefault(original.string(d(bcd) + 8), struct.unpack('<i', original.data(bcd + 8, 4))[0])
    return out


RCO = '.?AVReferenceCountedObject@G3D@@'
assert bases(0x8270c8) == {'.?AVLevelBuilder@ViewNew@RBX@@': 0}
for vtable, cls in ((0x827134, 'SphereBuilder'), (0x827164, 'CylinderBuilder'), (0x827194, 'HeadBuilder'),
                    (0x827088, 'Builder@BevelMesh')):
    assert bases(vtable) == {'.?AV%s@ViewNew@RBX@@' % cls: 0, '.?AVLevelBuilder@ViewNew@RBX@@': 0}, cls
for vtable, cls in ((0x827154, 'SphereMesh'), (0x827184, 'CylinderAlongXMesh'), (0x8271b8, 'HeadMesh')):
    assert bases(vtable) == {'.?AV%s@ViewNew@RBX@@' % cls: 0, '.?AVMesh@RenderBase@RBX@@': 0, RCO: 0,
                             '.?AV?$MeshFactory@V%s@ViewNew@RBX@@$00@ViewNew@RBX@@' % cls: 0x89}, cls
    raw = OBJ[{'SphereMesh': 'sphere', 'CylinderAlongXMesh': 'cylinder', 'HeadMesh': 'head'}[cls]].read_bytes()
    _, _, definitions, _ = match._coff_data_index(raw)
    assert '??_R1IJ@?0A@EA@?$MeshFactory@V%s@ViewNew@RBX@@$00@ViewNew@RBX@@8' % cls in definitions, cls
assert bases(0x82d028) == {'.?AVMesh@RenderBase@RBX@@': 0, RCO: 0}
assert bases(0x826e4c) == {'.?AVLevel@Mesh@RenderBase@RBX@@': 0, RCO: 0}

# Allocation sizes: the factories push 0x8c before the surface constructors; SphereMesh pushes 0x28 before Level().


def alloc_before(function, size, callee):
    body, _, _ = match.target('2008-06', '%08x' % function)
    at = body.index(b'\x68' + struct.pack('<I', size)) if size > 0x7f else body.index(b'\x6a' + bytes([size]))
    call = body.index(b'\xe8', at)
    while (function + call + 5 + struct.unpack_from('<i', body, call + 1)[0]) & 0xffffffff != callee:
        call = body.index(b'\xe8', call + 1)
    return at


alloc_before(0x4eea30, 0x8c, 0x4fcfb0)
alloc_before(0x4eef30, 0x8c, 0x4fd6b0)
alloc_before(0x4ef430, 0x8c, 0x500180)
alloc_before(0x4fcfb0, 0x28, 0x4dd2e0)

sha = nb.sha
paths = [Path(__file__).resolve(), LAYOUT] + list(UNITS.values()) + HEADERS
exact = sorted({r['address'] for g in groups.values() for r in g if r['exact']})
groups['not_exact'] = non_out
PROPOSALS = {
    'RenderBase/Mesh.h (new native header, owner: RenderBase)': 'promote ViewNew/RenderBaseMesh.h: Mesh 0x88 '
        '(levels +0xc, ShadowSurface +0x18, debugBoundingRadius +0x4c, std::vector<unsigned short> +0x50, '
        'std::vector<12-byte> +0x68, owned Ogre sub-mesh +0x80, meshKind +0x84), Level 0x28 (indexArray +0xc, '
        'primitive +0x18, dirty +0x1c, +0x20 = -1, sub-mesh +0x24) with the header-inline Level(Primitive) 004dd2e0',
}
receipt = {
    'class': 'RBX::ViewNew::LevelBuilder, BevelMesh::Builder, SphereBuilder/SphereMesh, CylinderBuilder/'
             'CylinderAlongXMesh, HeadBuilder/HeadMesh; RBX::RenderBase::Mesh / Mesh::Level (base declarations)',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in [layout_obj] + list(OBJ.values())},
    'layout': {k: hex(v) for k, v in SIZES.items()},
    'rows': groups,
    'exact_function_rows': exact,
    'vtables': vt,
    'proposals': PROPOSALS,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/viewnew-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native ViewNew: %d distinct function rows exact (%s); %d non-exact rows not counted; targets and %d '
      'vtables verified' % (len(exact), ', '.join('%s %d' % (k, sum(r['exact'] for r in g))
                                                   for k, g in groups.items() if k != 'not_exact'),
                            len(non_out), len(vt)))
