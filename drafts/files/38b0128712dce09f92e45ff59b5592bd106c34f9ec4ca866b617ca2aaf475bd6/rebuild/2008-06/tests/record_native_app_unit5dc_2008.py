"""Verify the inactive 2008-06 native rows of the application range 005dc000..005e8000, and record the unit map of the
range (boundary evidence in the receipt's `unit_map`; rows counted by other receipts are written there as text).

Unit map summary (details in UNIT_MAP below):
  * Humanoid.cpp tail ..005dcacf (humanoid owner), Message.cpp 005dcad0..005dd2bf (effects owner).
  * IRenderable.cpp 005dd2c0..005dd54f: built here from native-classes/AppUnit5DC_2008IRenderable.cpp against the
    native util/IRenderable.h (read-only).
  * Quaternion.cpp 005dd550..005dd77f and Math.cpp 005dd780..005df47f: built here from
    native-classes/AppUnit5DC_2008Quaternion.cpp / AppUnit5DC_2008Math.cpp against the donor util/Quaternion.h /
    util/Math.h (read-only; no native header declares RBX::Quaternion or RBX::Math, and no new header is created).
  * Lighting.cpp 005df480..005e275f (lighting owner), JointInstance.cpp 005e2760..005e50bf (JointInstance owner),
    Mechanism.cpp 005e50c0..005e54bf, JointsService.cpp 005e54c0..005e5bef, MotorJoint.cpp 005e5bf0..005e5eff,
    Assembly.cpp 005e5f00..005e729f, Primitive.cpp head 005e72a0.. (engine owners). Not built here.

Builds (document-swap flags, VS2008 RTM 21022):
  * math:   AppUnit5DC_2008Math.cpp, /fp:fast;
  * quat:   AppUnit5DC_2008Quaternion.cpp, /fp:fast;
  * render: AppUnit5DC_2008IRenderable.cpp (no extra flags).
No build here declares a class with a vtable of its own (Math / Quaternion / IRenderableBucket have none; IRenderable
is __declspec(novtable) and its slots are not emitted), so there is no vtable slot check; the only vtable reference
(G3D::Line, intersectRayPlane 005df380) is bound by its complete-object locator class.

Every counted row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the
address the original instruction uses and verified: imports by DLL export name, constants and string literals by
bytes, RTTI type descriptors by name, vtables by the complete-object locator class, own symbols by the row proven
here, COMDAT support bodies by exactness at the bound address, the remaining externals by the explicit EXTERNAL map
(evidence name, or call-site identification), local statics by one address per symbol.
A row is counted only when no other receipt counts it (top-level exact_function_rows, or exact_addresses /
exact_unique_addresses, or any entry marked exact for older receipts).
The receipt never writes a quoted bare address for a row it does not count.
Writes work/2008-06/shared-layouts/app-unit5dc-2008-working.json.
Set NATIVE_APP_UNIT5DC_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
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
OUT = nb.OUT / 'app-unit5dc-2008'
OUT.mkdir(parents=True, exist_ok=True)
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT5DC_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit5dc-2008-working.json'
MATH_SRC = R / 'native-classes/AppUnit5DC_2008Math.cpp'
QUAT_SRC = R / 'native-classes/AppUnit5DC_2008Quaternion.cpp'
RENDER_SRC = R / 'native-classes/AppUnit5DC_2008IRenderable.cpp'


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags() + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


OBJ, FLAGS = {}, {}
OBJ['math'], FLAGS['math'] = build('NativeAppUnit5DC_2008_math', MATH_SRC, ['/fp:fast'])
OBJ['quat'], FLAGS['quat'] = build('NativeAppUnit5DC_2008_quat', QUAT_SRC, ['/fp:fast'])
OBJ['render'], FLAGS['render'] = build('NativeAppUnit5DC_2008_render', RENDER_SRC)

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}

# ---- externals: address the original instruction uses -------------------------------------------------------------
EXTERNAL = {
    # util/NormalId.cpp (005e8000 range unit map)
    '?Vector3ToNormalId@RBX@@YA?AW4NormalId@1@ABVVector3@G3D@@@Z': 0x5ec290,                   # getOrientId (evidence name)
    '?normalIdToVector3@RBX@@YAABVVector3@G3D@@W4NormalId@1@@Z': 0x5ec570,                     # idToMatrix3 (evidence name)
    '?intToNormalId@RBX@@YA?AW4NormalId@1@H@Z': 0x5ec170,                                     # idToMatrix3 005ddce0 (call site)
    # Math::radWrap is out of this unit (rotationToByte 005ded68 calls it; ControllerService range, no evidence name)
    '?radWrap@Math@RBX@@SAMM@Z': 0x5cbec0,
    # G3D 6.09 library bodies (G3D::GCamera / Matrix3 / CoordinateFrame unit 00513000.., call-site identification:
    # the only out-of-line body the source calls at that instruction)
    '??4Matrix3@G3D@@QAEAAV01@ABV01@@Z': 0x513220,                                            # evidence name
    '??0Matrix3@G3D@@QAE@ABV01@@Z': 0x513220,          # copy ctor, ICF-folded with operator= (evidence name) 005de9e6..
    '?getColumn@Matrix3@G3D@@QBE?AVVector3@2@H@Z': 0x513240,
    '?setColumn@Matrix3@G3D@@QAEXHABVVector3@2@@Z': 0x513260,
    '??HMatrix3@G3D@@QBE?AV01@ABV01@@Z': 0x5132f0,
    '??DMatrix3@G3D@@QBE?AV01@ABV01@@Z': 0x513350,
    '??DG3D@@YA?AVMatrix3@0@MABV10@@Z': 0x5134e0,
    '?transpose@Matrix3@G3D@@QBE?AV12@XZ': 0x513510,
    '?orthonormalize@Matrix3@G3D@@QAEXXZ': 0x513550,
    '?isOrthonormal@Matrix3@G3D@@QBE_NXZ': 0x5138e0,
    '??0Matrix3@G3D@@QAE@MMMMMMMMM@Z': 0x513b70,
    '?identity@Matrix3@G3D@@SAABV12@XZ': 0x513e20,
    '?inf@Vector3@G3D@@SAABV12@XZ': 0x510960,                                                 # evidence name
    '?unitize@Vector2@G3D@@QAEMM@Z': 0x509c80,
    '?lookAt@CoordinateFrame@G3D@@QAEXABVVector3@2@@Z': 0x518e20,
    '?halfSpaceContains@Plane@G3D@@QBE_NVVector3@2@@Z': 0x518f20,
    '?intersection@Line@G3D@@QBE?AVVector3@2@ABVPlane@2@@Z': 0x7bbce0,
    '??0Line@G3D@@IAE@ABVVector3@1@0@Z': 0x525f40,                                            # library row 005dd780 only
    # G3D::Array<IRenderable*> (G3D Array.h template, out of line in the original: render build). Call-site binding
    # only: the unit's own COMDAT resize is 264 B against the 256 B body at 004abe40, which is not claimed exact.
    '?resize@?$Array@PAVIRenderable@RBX@@@G3D@@QAEXH_N@Z': 0x4abe40,
    '?alignedFree@System@G3D@@SAXPAX@Z': 0x507d20,                                            # ~IRenderableBucket
    # CRT float-to-int helper (statically linked; record_native_geometry_service.py binds the same)
    '__ftol2_sse': 0x6a17f0,
}
# data symbols verified by their bytes at the bound address
DATA_BYTES = {
    '?zLookDirection@CoordinateFrame@G3D@@2MB': (0x828b60, struct.pack('<f', -1.0)),   # lookVector (as app-unit588)
}
# function-local statics: one address per symbol (guard bits and objects of the Math statics)
LOCAL_STATIC_AT = {
    '?ssr@?1??segSizeRadians@RBX@@YAABMXZ@4MA': 0x97a684,
    '?$S1@?1??segSizeRadians@RBX@@YAABMXZ@4IA': 0x97a688,
    '?y90@?1??rotateMatrixAboutY90@Math@RBX@@SAXAAVMatrix3@G3D@@H@Z@4V45@A': 0x97a68c,
    '?$S2@?1??rotateMatrixAboutY90@Math@RBX@@SAXAAVMatrix3@G3D@@H@Z@4IA': 0x97a6b0,
    '?rotateY@?1??matrixRotateY@Math@RBX@@SAABVMatrix3@G3D@@XZ@4V45@A': 0x97a6b4,
    '?$S3@?1??matrixRotateY@Math@RBX@@SAABVMatrix3@G3D@@XZ@4IA': 0x97a6d8,
    '?tiltZ@?1??matrixTiltZ@Math@RBX@@SAABVMatrix3@G3D@@XZ@4V45@A': 0x97a6dc,
    '?$S4@?1??matrixTiltZ@Math@RBX@@SAABVMatrix3@G3D@@XZ@4IA': 0x97a700,
    '?tiltNegativeZ@?1??matrixTiltNegativeZ@Math@RBX@@SAABVMatrix3@G3D@@XZ@4V45@A': 0x97a704,
    '?$S5@?1??matrixTiltNegativeZ@Math@RBX@@SAABVMatrix3@G3D@@XZ@4IA': 0x97a728,
}
# COMDAT bodies emitted in the unit object that the original reaches out of line: accepted only when the compiled body
# is relocation-masked exact at the bound address (library support rows, never counted here).
SUPPORT = {
    '?fromPointAndDirection@Line@G3D@@SA?AV12@ABVVector3@2@0@Z': 0x5dd780,                    # intersectRayPlane
    '?append@?$Array@PAVIRenderable@RBX@@@G3D@@QAEXABQAVIRenderable@RBX@@@Z': 0x5dd390,       # recomputeShouldRender
}
UNBOUND = []
binding = {}
support_out = {}

# (address, symbol or unique prefix): one entry per counted address
ROWS = {
    'render': [
        (0x005dd2c0, '??1IRenderableBucket@RBX@@QAE@XZ'),
        (0x005dd330, '?render2dItems@IRenderableBucket@RBX@@QAEXPAVAdorn@2@@Z'),
        (0x005dd360, '?render3dAdornItems@IRenderableBucket@RBX@@QAEXPAVAdorn@2@@Z'),
        (0x005dd400, '?recomputeShouldRender@IRenderableBucket@RBX@@IAEXPAVIRenderable@2@@Z'),
        (0x005dd4c0, '?onAdded@IRenderableBucket@RBX@@IAEXPAVIRenderable@2@@Z'),
        (0x005dd4d0, '?onRemoving@IRenderableBucket@RBX@@IAEXPAVIRenderable@2@@Z'),
        (0x005dd540, '?shouldRenderSetDirty@IRenderable@RBX@@QAEXXZ'),
    ],
    'quat': [
        (0x005dd550, '??4Quaternion@RBX@@QAEAAV01@ABV01@@Z'),
        (0x005dd570, '??0Quaternion@RBX@@QAE@ABVMatrix3@G3D@@@Z'),
        (0x005dd6d0, '?toRotationMatrix@Quaternion@RBX@@QBEXAAVMatrix3@G3D@@@Z'),
    ],
    'math': [
        (0x005dd7b0, '?isDenormal@Math@RBX@@SA_NM@Z'),
        (0x005dd7d0, '?isNanInfDenorm@Math@RBX@@SA_NM@Z'),
        (0x005dd860, '?isNanInfDenormVector3@Math@RBX@@SA_NABVVector3@G3D@@@Z'),
        (0x005dd940, '?fixDenorm@Math@RBX@@SA_NAAVVector3@G3D@@@Z'),
        (0x005dd9b0, '?legalCameraCoord@Math@RBX@@SA_NABVCoordinateFrame@G3D@@@Z'),
        (0x005dda30, '?rotationFromByte@Math@RBX@@SAME@Z'),
        (0x005dda70, '?getIWorldAtPoint@Math@RBX@@SA?AVMatrix3@G3D@@ABVVector3@4@0ABV34@M@Z'),
        (0x005ddb30, '?momentToObjectSpace@Math@RBX@@SA?AVMatrix3@G3D@@ABV34@0@Z'),
        (0x005ddb70, '?momentToWorldSpace@Math@RBX@@SA?AVMatrix3@G3D@@ABV34@0@Z'),
        (0x005ddbb0, '?toDiagonal@Math@RBX@@SA?AVVector3@G3D@@ABVMatrix3@4@@Z'),
        (0x005ddbd0, '?fromDiagonal@Math@RBX@@SA?AVMatrix3@G3D@@ABVVector3@4@@Z'),
        (0x005ddc20, '?isAxisAligned@Math@RBX@@SA_NABVMatrix3@G3D@@@Z'),
        (0x005ddc90, '?getOrientId@Math@RBX@@SAHABVMatrix3@G3D@@@Z'),
        (0x005ddce0, '?idToMatrix3@Math@RBX@@SAXHAAVMatrix3@G3D@@@Z'),
        (0x005dddc0, '?rotateAboutZ@Math@RBX@@SA?AVMatrix3@G3D@@ABV34@M@Z'),
        (0x005dde50, '?snapToAxes@Math@RBX@@SA?AVMatrix3@G3D@@ABV34@@Z'),
        (0x005de090, '?iRoundVector3@Math@RBX@@SA?AVVector3@G3D@@ABV34@@Z'),
        (0x005de0f0, '?angleToE0@Math@RBX@@SAMABVVector2@G3D@@@Z'),
        (0x005de140, '?angle@Math@RBX@@SAMABVVector3@G3D@@0@Z'),
        (0x005de190, '?elevationAngle@Math@RBX@@SAMABVVector3@G3D@@@Z'),
        (0x005de1d0, '?fuzzyEq@Math@RBX@@SA_NABVVector3@G3D@@0M@Z'),
        (0x005de230, '?fuzzyEq@Math@RBX@@SA_NABVMatrix3@G3D@@0M@Z'),
        (0x005de2a0, '?fuzzyEq@Math@RBX@@SA_NABVCoordinateFrame@G3D@@0MM@Z'),
        (0x005de2f0, '?alignAxesClosest@Math@RBX@@SA?AVMatrix3@G3D@@ABV34@0@Z'),
        (0x005de560, '?getClosestObjectNormalId@Math@RBX@@SA?AW4NormalId@2@ABVVector3@G3D@@ABVMatrix3@5@@Z'),
        (0x005de630, '?vector3Abs@Math@RBX@@SA?AVVector3@G3D@@ABV34@@Z'),
        (0x005de650, '?getHeading@Math@RBX@@SAMABVVector3@G3D@@@Z'),
        (0x005de660, '?getHeadingElevation@Math@RBX@@SAXABVCoordinateFrame@G3D@@AAM1@Z'),
        (0x005de6c0, '?setHeadingElevation@Math@RBX@@SAXAAVCoordinateFrame@G3D@@MM@Z'),
        (0x005de740, '?rotateMatrixAboutY90@Math@RBX@@SAXAAVMatrix3@G3D@@H@Z'),
        (0x005de800, '?matrixRotateY@Math@RBX@@SAABVMatrix3@G3D@@XZ'),
        (0x005de890, '?matrixTiltZ@Math@RBX@@SAABVMatrix3@G3D@@XZ'),
        (0x005de910, '?matrixTiltNegativeZ@Math@RBX@@SAABVMatrix3@G3D@@XZ'),
        (0x005de990, '?matrixTiltQuadrant@Math@RBX@@SA?BVMatrix3@G3D@@H@Z'),
        (0x005dea60, '?toYAxisQuadrant@Math@RBX@@SAHABVCoordinateFrame@G3D@@@Z'),
        (0x005dec60, '?getFocusSpace@Math@RBX@@SA?AVCoordinateFrame@G3D@@ABV34@@Z'),
        (0x005dece0, '?rotationToByteBase@RBX@@YAEM@Z'),
        (0x005ded60, '?rotationToByte@Math@RBX@@SAEM@Z'),
        (0x005dee10, '?toGrid@Math@RBX@@SA?AVVector3@G3D@@ABV34@0@Z'),
        (0x005dee90, '?toGrid@Math@RBX@@SA?AVVector3@G3D@@ABV34@M@Z'),
        (0x005deed0, '?snapToGrid@Math@RBX@@SA?AVCoordinateFrame@G3D@@ABV34@M@Z'),
        (0x005def40, '?snapToGrid@Math@RBX@@SA?AVCoordinateFrame@G3D@@ABV34@ABVVector3@4@@Z'),
        (0x005defa0, '?fuzzyAxisAligned@Math@RBX@@SA_NABVMatrix3@G3D@@0M@Z'),
        (0x005df0a0, '?orthonormalizeIfNecessary@Math@RBX@@SA_NAAVMatrix3@G3D@@@Z'),
        (0x005df1b0, '?sortVector3@Math@RBX@@SA?AVVector3@G3D@@ABV34@@Z'),
        (0x005df220, '?maxAxisLength@Math@RBX@@SAMABVVector3@G3D@@@Z'),
        (0x005df380, '?intersectRayPlane@Math@RBX@@SA_NABVRay@G3D@@ABVPlane@4@AAVVector3@4@@Z'),
    ],
}
# library COMDAT bodies the unit objects emit that are exact at an address of the range: verified like a row, never
# counted (G3D / STL code; G3D::Array<T*>::append is ICF-folded with the Array<const void*> and Array<Edge*> copies)
LIBRARY_ROWS = {
    'math': [(0x005dd780, '?fromPointAndDirection@Line@G3D@@SA?AV12@ABVVector3@2@0@Z', 'G3D Line.h inline'),
             (0x005dec40, '??$max@M@std@@YAABMABM0@Z', 'STL std::max<float>')],
    'render': [(0x005dd390, '?append@?$Array@PAVIRenderable@RBX@@@G3D@@QAEXABQAVIRenderable@RBX@@@Z',
                'G3D Array<T*>::append (evidence name Array<const void*>::append, ICF)')],
}
NOT_RECOVERED = [
    '005dd820 (float) and 005dd8b0 (Vector3): the NaN / Inf predicates with the inlined isDenormal test. Exact when '
    'written as Math::isNanInfDenorm / isNanInfDenormVector3 over a file-level isNanInf (005dd7d0) / isNanInfVector3 '
    '(005dd860) pair, but the evidence names (and record_native_app_unit609_2008.py, which binds searchUpFine 0061033e '
    'to isNanInfDenormVector3 at 005dd860) put those two names on 005dd7d0 / 005dd860; util/Math.h declares no '
    'other names for them, so they are not recovered under invented ones.',
    '005ded80 computeLaunchAngle(float, float, float, float): float body with min of the two atan roots compiles to '
    '126 / 134 B (not exact; the original keeps the roots in the argument slots +4 / +0x10).',
    '005df0c0 (pan-like lookAt of translation + look + amount * side, 2 arguments) and 005df140 (Matrix3 rotated by '
    'fromAxisAngle(static (0, 1, 0), angle)): util/Math.h declares pan(const Vector3&, CoordinateFrame&, float) '
    'and rotateAboutYGlobal(CoordinateFrame&, float) with different arguments; not attempted.',
    '005dead0 (368 B, called from 00676cca / 006773fa): no evidence name, not identified.',
    '005df270 counted by resize-tool-methods-trial.json (not built here).',
]
REJECTED = {
    'snapToAxes donor body (unkMat[v15][v11], second declared before bestV)': (
        '574/574 B but not exact with only the index fixed to unkMat[v15][calcColmTemp]; the declaration order '
        'bestV, second is needed as well.'),
    'segSizeRadians as the donor (pi() - 0.00001f) / 128': 'constant 0x3cc90fb1; 0083db40 holds 0x3cc90fda = twoPi() / 256',
    'angleToE0 with twoPi()': 'constant 0x40c90fda; 0083db44 holds 0x40c90fdb = 2 * pi()',
    'toYAxisQuadrant with twoPi() + pi() / 4': 'constant 0x40e231d5; 0083db50 holds 0x40e231d6 = 2 * pi() + pi() / 4',
    'fuzzyAxisAligned with Vector3::magnitude()': '246/250 B; the original sums z*z + y*y + x*x (explicit sqrtf).',
    'isNanInfDenorm donor body (with the isDenormal test)': '96/80 B; 005dd7d0 has only the four _FInf / _FNan compares.',
    'whole unit without /fp:fast': ('getIWorldAtPoint 331/177, toGrid 151/127, fuzzyEq(Vector3) 146/85, '
                                   'fuzzyEq(Matrix3) 167/106, snapToAxes 663/574'),
    'elevationAngle as G3D::aSin(v.y) or with the < / > clamp order': '54/54 B not exact, or 58 B',
}


def target_of(address):
    body, refs, _ = match.target('2008-06', '%08x' % address)
    return body, refs


def resolve(obj, rows):
    funcs = match.coff_functions(Path(obj).read_bytes())
    out = []
    for row in rows:
        address, key = row[0], row[1]
        hits = [x for x in funcs if x[0] == key] or [x for x in funcs if x[0].startswith(key) and not nb.LOCAL_EH.match(x[0])]
        if DISCOVER and len(hits) != 1:
            print('UNRESOLVED', '%08x' % address, key[:120], [h[0][:120] for h in hits])
            continue
        assert len(hits) == 1, ('%08x' % address, key, [h[0] for h in hits])
        out.append((address, hits[0][0]))
    return out


def bind_value(raw, sections, symbols, definitions, bodies, name, body, target, address, own, extern, record=True):
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
            how = 'string %r' % literal[:-1].decode('latin-1')[:40]
        elif symbol.startswith('??_R0') and symbol.endswith('@8'):
            rtti = original.string(value + 8)
            assert rtti == '.' + symbol[5:-2], (name, symbol, hex(value), rtti)
            how = 'RTTI type %s' % rtti
        elif symbol.startswith('??_7'):
            rtti, offset_in_object = original.vtable_class(value)
            cls = symbol[4:symbol.index('@@6B') + 2]
            assert rtti == '.?AV' + cls, (name, symbol, hex(value), rtti)
            how = 'vtable (RTTI %s, offset %#x)' % (rtti, offset_in_object)
        elif symbol in own:
            assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
            how = 'own row'
        elif symbol in SUPPORT:
            assert SUPPORT[symbol] == value, (name, symbol, hex(value))
            sbody, srefs = bodies[symbol]
            starget, strefs = target_of(value)
            assert match.exact_match(starget, strefs, sbody, srefs), ('support body not exact', symbol, hex(value))
            support_out[symbol] = '%08x' % value
            how = 'support body exact at the bound address'
        elif symbol in extern:
            assert extern[symbol] == value, (name, symbol, hex(value), hex(extern[symbol]))
            how = 'external' + (' (evidence name)' if names.get(value, '') == symbol else '')
        elif symbol in DATA_BYTES:
            at, want = DATA_BYTES[symbol]
            assert at == value and original.data(value, len(want)) == want, (name, symbol, hex(value))
            how = 'data, bytes verified'
        elif symbol in LOCAL_STATIC_AT:
            assert LOCAL_STATIC_AT[symbol] == value, (name, symbol, hex(value), hex(LOCAL_STATIC_AT[symbol]))
            how = 'static data (one address per symbol)'
        else:
            UNBOUND.append("    %r: %#x,   # %s in %s" % (symbol, value, names.get(value, '')[:60], name[:60]))
            continue
        if record:
            prev = binding.setdefault(symbol, (value, name))
            assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
        verified[symbol] = '%s (%s)' % (hex(value), how)
    return verified, local


def verify(which, rows, own, extern, strict=True, record=True):
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
        verified, local = bind_value(raw, sections, symbols, definitions, bodies, name, body, target, address, own,
                                     extern, record)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local)})
        result.append(entry)
    return result


resolved = {k: resolve(OBJ[k], rows) for k, rows in ROWS.items()}
own = {}
for rows in resolved.values():
    for address, name in rows:
        own.setdefault(name, address)
groups = {k: verify(k, rows, own, EXTERNAL) for k, rows in resolved.items()}

# library bodies (never counted): exact with every target bound
library_rows = []
for which, items in LIBRARY_ROWS.items():
    rows = resolve(OBJ[which], [(a, s) for a, s, _ in items])
    for (address, name), (_, _, what) in zip(rows, items):
        r = verify(which, [(address, name)], own, EXTERNAL)[0]
        assert r['exact'] or DISCOVER, r
        library_rows.append({'row': '%08x (library, not counted)' % address, 'symbol': name, 'what': what,
                             'exact': r['exact'], 'verified_targets': r.get('verified_targets', {})})

if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for g, rows in groups.items():
        for r in rows:
            if not r['exact']:
                print('NOT EXACT', g, r['address'], r['symbol'][:90], r['size'], r['target_size'])
    sys.exit(0)
assert not UNBOUND, UNBOUND


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
            # conservative: any entry marked exact anywhere in the receipt
            def walk(o):
                if isinstance(o, list):
                    for e in o:
                        walk(e)
                elif isinstance(o, dict):
                    a = o.get('address') or o.get('addr')
                    if a and o.get('exact') is True:
                        rows.append(a)
                    for v in o.values():
                        if isinstance(v, (list, dict)):
                            walk(v)
            walk(data)
        if isinstance(rows, dict):
            rows = list(rows)
        for r in rows:
            r = (r.get('address') or r.get('addr') or '') if isinstance(r, dict) else str(r)
            m = re.match(r'(?:0x)?([0-9a-fA-F]{6,8})', r)
            if m:
                out.setdefault('%08x' % int(m.group(1), 16), []).append(Path(path).name)
    return out


elsewhere = counted_elsewhere()
exact_rows = sorted({r['address'] for rows in groups.values() for r in rows if r['exact']})
double = {a: elsewhere[a] for a in exact_rows if a in elsewhere}
assert not double, double
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if '005dc000' <= a < '005e8000'}
# the static locals the counted rows reach must each have been bound to one address (binding asserts consistency)
statics = {s: '%#x' % v for s, (v, _) in sorted(binding.items()) if s.startswith('?') and '@?' in s and '@4' in s}

# ---- unit map --------------------------------------------------------------------------------------------------
RANGE_ROWS = [json.loads(l) for l in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines() if l.strip()]
RANGE_ROWS = [r for r in RANGE_ROWS if 0x5dc000 <= int(r['addr'], 16) < 0x5e8000]
UNITS = [
    ('Humanoid.cpp tail', 0x5dc000, 0x5dcad0),
    ('Message.cpp', 0x5dcad0, 0x5dd2c0),
    ('IRenderable.cpp', 0x5dd2c0, 0x5dd550),
    ('Quaternion.cpp', 0x5dd550, 0x5dd780),
    ('Math.cpp', 0x5dd780, 0x5df480),
    ('Lighting.cpp', 0x5df480, 0x5e2760),
    ('JointInstance.cpp', 0x5e2760, 0x5e50c0),
    ('Mechanism.cpp', 0x5e50c0, 0x5e54c0),
    ('JointsService.cpp', 0x5e54c0, 0x5e5bf0),
    ('MotorJoint.cpp', 0x5e5bf0, 0x5e5f00),
    ('Assembly.cpp', 0x5e5f00, 0x5e72a0),
    ('Primitive.cpp head', 0x5e72a0, 0x5e8000),
]
unit_rows = {}
for r in RANGE_ROWS:
    a = int(r['addr'], 16)
    unit = [u for u, lo, hi in UNITS if lo <= a < hi][0]
    unit_rows.setdefault(unit, []).append(r)

UNIT_MAP = {
    'Humanoid.cpp tail ..005dcacf': (
        'v8datamodel/Humanoid.cpp (humanoid owner, native humanoid/Humanoid2008.h): evidence names setWalkToPart '
        '005dc150, setJump 005dc270, setSit 005dc2b0, moveTo 005dc3d0, setLeftLeg / setRightLeg / setTorso '
        '005dc480 / 005dc540 / 005dc600, cameraSetWalkOrientation 005dc7f0, moveTo2 005dca00. Most rows are counted '
        'by humanoid2008-working.json; 005dc6c0 / 005dc740 / 005dc7f0 / 005dc920 are not (the humanoid receipt '
        'proposes the PartInstance +0x228 Primitive layout they need). Not built here.'),
    'Message.cpp 005dcad0..005dd2bf': (
        'v8datamodel/Message.cpp (effects owner, native v8datamodel/Message.h): getText 005dcad0, '
        'FactoryProduct / DescribedCreatable<Message> constructors 005dcae0 / 005dcff0, renderFullScreen 005dcb50, '
        'renderPersonalMsg 005dcc60, render2d 005dcd90, Hint::render2d 005dcde0, Message() 005dd120 with its ??_E '
        'thunks, setText 005dd280. Counted by effects-working.json. Not built here.'),
    'IRenderable.cpp 005dd2c0..005dd54f': (
        'util/IRenderable.cpp: evidence names recomputeShouldRender 005dd400, onAdded 005dd4c0, onRemoving 005dd4d0, '
        'shouldRenderSetDirty 005dd540; ~IRenderableBucket 005dd2c0 (the two IndexArray / G3D::Array destructors; '
        'evidence name MeshAlg::Vertex::~Vertex, an ICF-folded identical body; record_native_services_maps.py binds '
        '~IRenderableBucket to it from ~JointsService), render2dItems 005dd330 / render3dAdornItems 005dd360 (slot '
        'calls +0x8 / +0xc of IRenderable), and the folded G3D Array<T*>::append 005dd390 (library). Layout from the '
        'native util/IRenderable.h: IRenderable index2d +0x4, index3d +0x8, bucket +0xc (onAdded 005dd4c0 stores '
        'bucket at +0xc; onRemoving 005dd4d0 tests +0x4 / +0x8); IRenderableBucket renderable2ds +0x0, renderable3ds '
        '+0xc. Built here: 7 counted rows.'),
    'Quaternion.cpp 005dd550..005dd77f': (
        'util/Quaternion.cpp: operator= 005dd550 (copies w +0xc, x +0x0, y +0x4, z +0x8), Quaternion(const Matrix3&) '
        '005dd570 (evidence by its body: trace test then the three largest-diagonal branches), toRotationMatrix '
        '005dd6d0. Built here: 3 counted rows.'),
    'Math.cpp 005dd780..005df47f': (
        'util/Math.cpp (RBX::Math, static members only): evidence names isDenormal 005dd7b0, isNanInfDenorm '
        '005dd7d0, isNanInfDenormVector3 005dd860, fixDenorm 005dd940, getIWorldAtPoint 005dda70, '
        'momentToObjectSpace / momentToWorldSpace 005ddb30 / 005ddb70, toDiagonal / fromDiagonal 005ddbb0 / '
        '005ddbd0, getOrientId 005ddc90, snapToAxes 005dde50, iRoundVector3 005de090, the three fuzzyEq 005de1d0 / '
        '005de230 / 005de2a0, rotateMatrixAboutY90 005de740, matrixRotateY 005de800, matrixTiltZ 005de890, toGrid '
        '005dee10 / 005dee90, snapToGrid 005deed0 / 005def40, fuzzyAxisAligned 005defa0, orthonormalizeIfNecessary '
        '005df0a0; the other members by body (donor util/Math.cpp shape, call / constant evidence in the source '
        'comments). The unit starts with the G3D Line::fromPointAndDirection 005dd780 inline (library) and has the '
        'std::max<float> instance 005dec40 (library). Built here: 47 counted rows; see not_recovered for the rest.'),
    'Lighting.cpp 005df480..005e275f': (
        'v8datamodel/Lighting.cpp (lighting owner, native v8datamodel/Lighting2008.h): the getters 005df480 / '
        '005df490 / 005df4a0, getMoonPosition 005df4d0, getSunPosition 005df500, askAddChild 005df530, '
        '~FactoryProduct<Lighting> 005df560, boost tokenizer / char_separator / date_time / lexical_cast instances '
        '005df620..005e0c20, the property descriptors 005dffa0 / 005e1170..005e1960, Lighting() 005e1a40, ~Lighting '
        '005e1d60, setClearColor 005e2030, onChild* 005e2100..005e2260, setTime / setTimeStr 005e2570 / 005e2730. '
        'Most rows are counted by lighting2008-working.json (005df620 by content-upload-trial.json). Not built here.'),
    'JointInstance.cpp 005e2760..005e50bf': (
        'v8datamodel/JointInstance.cpp: JointInstance shouldRender3dAdorn 005e27a0, getC0 / getC1 005e27b0 / '
        '005e27c0, NonFactoryProduct<Instance, sJointInstance> 005e27e0, getPart0 / getPart1 005e2a10 / 005e2a70, '
        'render3dAdorn 005e2af0, setPart 005e2cd0, ~JointInstance 005e2e10, the Snap / Weld / Glue / Rotate / '
        'RotateP / RotateV / Motor ??_E thunks, getClassName, FactoryProduct / DescribedCreatable constructors and '
        'default constructors (Snap() 005e4600, Glue() 005e49a0, Rotate() 005e4ad0, Motor() 005e4ee0), '
        'askSetParent 005e3790, JointInstance(Joint*) 005e3870, onAncestorChanged 005e3a80, setPart0 / setPart1 / '
        'setC0 / setC1 005e4450..005e44c0, Motor::setMaxVelocity 005e4fe0. Not built here: in 2008 these members '
        'and part[2] belong to JointInstance itself (RTTI $1?sJointInstance@2@3QBDB; no AutoJoint class), which '
        'the native v8datamodel/JointInstance.h does not declare (see proposals). 005e2760 / 005e28c0 / 005e28e0 are '
        'counted by world-joints-working.json, 005e2790 by world-shapes-working.json, 005e28b0 by '
        'feature-working.json.'),
    'Mechanism.cpp 005e50c0..005e54bf': (
        'v8world/Mechanism.cpp (kernel / SimJob owner): Mechanism::getMechanismFromPrimitive 005e50c0, '
        'MechanismTracker::tracking 005e50e0, the rows 005e50f0..005e51e0 counted by kernel-stages-working.json, '
        'fastRemoveShort<Assembly*> 005e5200, MechanismTracker::stopTracking 005e5320, 005e5350 / 005e53a0. Not built '
        'here.'),
    'JointsService.cpp 005e54c0..005e5bef': (
        'v8datamodel/JointsService.cpp (services owner, native v8datamodel/JointsService.h): onDescendentAdded '
        '005e54c0, onDescendentRemoving 005e5520 and the rows to 005e5860 (counted by services-working.json), the '
        'Notifier<Instance, ChildAdded>::removeListener instance 005e5a80 (counted by humanoid2008-working.json), '
        'onServiceProvider 005e5b50 (needs the Workspace getWorld proposal). Not built here.'),
    'MotorJoint.cpp 005e5bf0..005e5eff': (
        'v8world/MotorJoint.cpp (engine owner, native v8world/Joints2008.h): MotorJoint() 005e5bf0, isAligned '
        '005e5d00, ~MotorJoint 005e5e00 (world-joints-working.json counts 005e5bf0 / 005e5e00 / 005e5e70 / '
        '005e5ee0). Not built here.'),
    'Assembly.cpp 005e5f00..005e729f': (
        'v8world/Assembly.cpp (engine owner): SleepInfo() 005e5f30, assemblyPrimEnd / Begin 005e5fc0 / 005e5fa0, '
        'otherAssembly 005e61b0, getMotor 005e6400, G3D Array<Edge*> resize / append 005e6540 / 005e6640, and the '
        'std::sort instances over MotorJoint* (005e61e0, 005e66b0..005e6e90; library templates). Not built here.'),
    'Primitive.cpp head 005e72a0..': (
        'v8world/Primitive.cpp (Body/Primitive owner, native v8world/Primitive2008.h): Geometry / Block / Ball '
        'inline virtuals 005e72a0..005e7400 (world-shapes-working.json), setUnknown0x14 005e7420, newTouch 005e74c0, '
        'onNewTouch 005e7530, setClump 005e7550, getAssembly 005e7560 / 005e7570, computeJointK 005e7580, '
        'getFaceCoordInObject 005e7680, getFaceInObject 005e76f0, ~EdgeList 005e7910, computeFuzzyExtents 005e7980, '
        'getFirstContact / getNextContact 005e7bd0 / 005e7be0, newGeometry 005e7d80, hitTest 005e7f20; continues '
        'into the 005e8000 range. Not built here.'),
}
unit_map = []
for u, lo, hi in UNITS:
    key = [k for k in UNIT_MAP if k.startswith(u)][0]
    rows = unit_rows.get(u, [])
    unit_map.append({'unit': key, 'rows': len(rows), 'bytes': sum(r['size'] for r in rows),
                     'counted_elsewhere': ['%s counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()
                                           if lo <= int(a, 16) < hi],
                     'counted_here': len([a for a in exact_rows if lo <= int(a, 16) < hi]),
                     'evidence': UNIT_MAP[key]})
assert sum(u['rows'] for u in unit_map) == len(RANGE_ROWS)

PROPOSALS = [
    'Owner of native-headers/v8datamodel/JointInstance.h (information, same facts as the joint receipts): the 2008 '
    'JointInstance.cpp block 005e2760..005e50bf has no AutoJoint. getPart0 / getPart1 005e2a10 / 005e2a70, setPart '
    '005e2cd0, askSetParent 005e3790, onAncestorChanged 005e3a80, setPart0 / setPart1 / setC0 / setC1 '
    '005e4450..005e44c0 are JointInstance members, ~JointInstance 005e2e10 is the only joint-instance destructor, '
    'sJointInstance is extern const char[] (RTTI $1?sJointInstance@2@3QBDB, NonFactoryProduct ctor 005e27e0), and '
    'Snap / Weld / Glue / Rotate / RotateP / RotateV / Motor derive from DescribedCreatable<C, JointInstance, sC>. '
    'With that declaration the ~140 rows of the block become candidates.',
    'Owner of a native RBX::Math declaration (none exists; util/Math.h is donor): 005dd820 (float) and 005dd8b0 '
    '(Vector3) are the NaN / Inf predicates with the inlined denormal test, while 005dd7d0 / 005dd860 (evidence names '
    'isNanInfDenorm / isNanInfDenormVector3) test NaN / Inf only. A 2008 declaration that names all four would let '
    'them be counted (they are exact in a trial with file-level helpers; see not_recovered).',
]

receipt = {
    'scope': ('Inactive 2008-06 native recovery of the application range 005dc000..005e8000: unit map of every row, '
              'and the IRenderable.cpp, Quaternion.cpp and Math.cpp rows against the native util/IRenderable.h and '
              'the donor util/Quaternion.h / util/Math.h. No runtime, link or class-swap claim.'),
    'exact_function_rows': exact_rows,
    'exact_function_row_count': len(exact_rows),
    'range_rows': len(RANGE_ROWS),
    'rows': groups,
    'library_rows': library_rows,
    'local_statics': statics,
    'not_recovered': NOT_RECOVERED,
    'unit_map': unit_map,
    'proposals': PROPOSALS,
    'rejected': REJECTED,
    'flags': FLAGS,
    'sources': {k: nb.sha(p) for k, p in [('math', MATH_SRC), ('quat', QUAT_SRC), ('render', RENDER_SRC)]},
    'headers_read_only': ['native-headers/util/IRenderable.h', 'tools/rbxgs/Client/App/include/util/Math.h',
                          'tools/rbxgs/Client/App/include/util/Quaternion.h'],
    'new_headers': [],
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit5dc-2008: %d counted rows (%d range rows), %d library rows verified'
      % (len(exact_rows), len(RANGE_ROWS), len(library_rows)))
