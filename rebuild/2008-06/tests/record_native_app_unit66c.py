"""Verify the inactive 2008-06 native rows of the application range 0066c000..00670000 and record the unit map of the
range (boundary evidence in the receipt's `unit_map` / `row_map`; rows counted by other receipts are listed there).

Units built here (VS2008 RTM 21022, document-swap flags plus /fp:fast /U_RELEASEASSERT):
  * RBX::RunDragger 0066c330..0066e650 (+ its two atexit thunks 0x00801430 / 0x00801440):
    native-classes/AppUnit66CRunDragger.cpp against the donor tool/RunDragger.h (read-only; no native header declares
    RunDragger), built with native-headers/part-embedded and native-headers/engine-world first on the include path (the
    2008 Primitive / PartInstance / World / ContactManager declarations, as AppUnit5E4PrimitiveParts.cpp).
  * RBX::AssemblyStage (RTTI .?AVAssemblyStage@RBX@@, vtable 0084d1a4): native-classes/AppUnit66CAssemblyStage.cpp
    against the new native-headers/AppUnit66C/AssemblyStage.h (no donor header has this path, so it shadows nothing).
A layout probe generated under out/native-layouts/app-unit66c/ checks sizeof(RunDragger) = 0x70 (PartDragTool()
00665fc1 news 0x70 before RunDragger() 0066c900), the public SnapInfo offsets, sizeof(AssemblyStage) = 0x50 (TreeStage()
006698ac news 0x50 before AssemblyStage() 0066f800) and its set offsets.

Every counted row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the
address the original instruction uses and verified: imports by DLL export name, constants by bytes, vtables by original
RTTI names, own rows, function-local statics by one address per symbol, COMDAT helper bodies by an exact comparison at
the bound address, the remaining externals by the explicit EXTERNAL map (one address per symbol). The AssemblyStage
vtable is compared slot by slot with the object built from the current headers. A row is counted only when no other
receipt counts it (top-level exact_function_rows rule). Addresses of rows not counted here are written as 0x-prefixed
or 'ADDR counted by RECEIPT' text, never as quoted bare addresses (local_backpack / viewnew_brick_build /
viewnew_part_mesh read any quoted bare address as counted there).
Writes work/2008-06/shared-layouts/app-unit66c-working.json. Set NATIVE_APP_UNIT66C_DISCOVER=1 to list unbound
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
import capstone  # noqa: E402

CS = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
R = ROOT / 'rebuild/2008-06'
OUT = nb.OUT / 'app-unit66c'
OUT.mkdir(parents=True, exist_ok=True)
SOURCES = {
    'drag': R / 'native-classes/AppUnit66CRunDragger.cpp',
    'stage': R / 'native-classes/AppUnit66CAssemblyStage.cpp',
}
PART_EMBEDDED = [R / 'native-headers/part-embedded', R / 'native-headers/engine-world']
FIRST = {'drag': PART_EMBEDDED, 'stage': [], 'layout': PART_EMBEDDED}
HEADERS = [R / 'native-headers/AppUnit66C/AssemblyStage.h',
           R / 'native-headers/v8world/Joints2008.h',
           R / 'native-headers/part-embedded/v8world/Primitive.h',
           R / 'native-headers/part-embedded/v8datamodel/PartInstance.h',
           R / 'native-headers/engine-world/v8world/World.h',
           R / 'native-headers/engine-world/v8world/ContactManager.h',
           ROOT / 'tools/rbxgs/Client/App/include/tool/RunDragger.h',
           ROOT / 'tools/rbxgs/Client/App/include/v8world/IWorldStage.h',
           ROOT / 'tools/rbxgs/Client/App/include/v8kernel/IStage.h']
UNIT = ['/fp:fast', '/U_RELEASEASSERT']   # no RBXASSERT code in these rows
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT66C_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit66c-working.json'
LO, HI = 0x66c000, 0x670000
H = lambda a: '0x%08x' % a

# ---- layout probe (generated, build-local) ---------------------------------------------------------------------------
LAYOUT = OUT / 'NativeAppUnit66CLayout.cpp'
PROBES = {
    'runDraggerSize': ('sizeof(RBX::RunDragger)', 0x70),                       # PartDragTool() 00665fc1: new(0x70)
    'snapInfoSize': ('sizeof(RBX::RunDragger::SnapInfo)', 0x20),               # copy ctor 0066c480 (2 + 6 dwords)
    'snapInfoSnap': ('offsetof(RBX::RunDragger::SnapInfo, snap)', 0x0),        # SnapInfo() 0066c603
    'snapInfoSurface': ('offsetof(RBX::RunDragger::SnapInfo, surface)', 0x4),  # SnapInfo() 0066c609 (= 6)
    'snapInfoHitWorld': ('offsetof(RBX::RunDragger::SnapInfo, hitWorld)', 0x8),           # SnapInfo() 0066c617
    'snapInfoLastDragSnap': ('offsetof(RBX::RunDragger::SnapInfo, lastDragSnap)', 0x14),  # SnapInfo() 0066c62d
    'assemblyStageSize': ('sizeof(RBX::AssemblyStage)', 0x50),                 # TreeStage() 006698ac: new(0x50)
    'assemblies': ('offsetof(RBX::AssemblyStage, assemblies)', 0x10),          # ctor 0066f864, dtor 0066f7c3
    'joints': ('offsetof(RBX::AssemblyStage, joints)', 0x30),                  # stepWorld 0066f57e, ctor 0066f885
    'setSize': ('sizeof(std::set<RBX::Joint*>)', 0x20),                        # stepWorld reads joints' head at +0x48
}
LAYOUT.write_text(
    '// generated by tests/record_native_app_unit66c.py: sizeof / offsetof probes (mov eax, imm32; ret)\n'
    '#include <stddef.h>\n#include "tool/RunDragger.h"\n#include "AppUnit66C/AssemblyStage.h"\n'
    'struct NativeAppUnit66CLayout\n{\n'
    + ''.join('\tstatic int %s()\n\t{\n\t\treturn %s;\n\t}\n' % (k, e) for k, (e, _) in PROBES.items())
    + '};\n'
    + ''.join('int NativeAppUnit66CLayout_%s()\n{\n\treturn NativeAppUnit66CLayout::%s();\n}\n' % (k, k) for k in PROBES))


def build(name, src, first=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, f in enumerate(flags) if f.startswith('/I'))
    flags = flags[:i] + ['/I' + str(p) for p in first] + flags[i:] + UNIT + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log[-4000:]
    return obj, flags


OBJ, FLAGS = {}, {}
OBJ['layout'], FLAGS['layout'] = build('NativeAppUnit66CLayout', LAYOUT, FIRST['layout'])
for key, src in SOURCES.items():
    OBJ[key], FLAGS[key] = build('NativeAppUnit66C_' + key, src, FIRST[key])

layout = {}
for n, b, _ in match.coff_functions(Path(OBJ['layout']).read_bytes()):
    m = re.match(r'\?NativeAppUnit66CLayout_(\w+)@@', n)
    if m and m.group(1) in PROBES:
        assert b in (b'\xb8' + struct.pack('<I', PROBES[m.group(1)][1]) + b'\xc3',
                     b'\x33\xc0\xc3' if PROBES[m.group(1)][1] == 0 else b'-'), (m.group(1), b.hex())
        layout[m.group(1)] = hex(PROBES[m.group(1)][1])
assert sorted(layout) == sorted(PROBES), sorted(set(PROBES) - set(layout))

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
FUNCS = {}
for line in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines():
    if line.strip():
        row = json.loads(line)
        FUNCS[int(row['addr'], 16)] = row
FUNCTIONS = set(FUNCS)

RD = '@RunDragger@RBX@@'
ARR_P = 'ABV?$Array@PAVPrimitive@RBX@@@G3D@@'
UPD = '?updateHitFromSurface@SnapInfo@RunDragger@RBX@@QAEXABVRay@G3D@@@Z'
ROWS = {
    'drag': [
        (0x66c330, '?updateSurfaceFromHit@SnapInfo' + RD + 'QAEXXZ'),
        (0x66c400, '??1RunDragger@RBX@@QAE@XZ'),
        (0x66c480, '??0SnapInfo' + RD + 'QAE@ABV012@@Z'),
        (0x66c4c0, '?adjacent' + RD + 'AAE_NPAVPrimitive@2@0@Z'),
        (0x66c510, '?tooCloseToCamera' + RD + 'AAE_NXZ'),
        (0x66c5a0, '?rotatePart' + RD + 'SAXPAVPartInstance@2@@Z'),
        (0x66c600, '??0SnapInfo' + RD + 'QAE@XZ'),
        (0x66c640, UPD),
        (0x66c810, '?hitOutsideExtents@SnapInfo' + RD + 'QAEMXZ'),
        (0x66c900, '??0RunDragger@RBX@@QAE@XZ'),
        (0x66c970, '?createSnapSurface' + RD + 'AAE?AVSnapInfo@12@PAVPrimitive@2@PAV?$Array@W4NormalId@RBX@@@G3D@@@Z'),
        (0x66cc70, '?notTried' + RD + 'AAE_NPAVPrimitive@2@' + ARR_P + '@Z'),
        (0x66ccc0, '?bestProximatePart' + RD + 'AAE?AVSnapInfo@12@' + ARR_P + 'P8Contact@2@AE_NM@Z@Z'),
        (0x66ce20, '?turnUpright' + RD + 'SAXPAVPartInstance@2@@Z'),
        (0x66ced0, '?tiltPart' + RD + 'SAXPAVPartInstance@2@ABVCoordinateFrame@G3D@@@Z'),
        (0x66cfd0, '?resize@?$Array@W4NormalId@RBX@@@G3D@@QAEXH_N@Z'),
        (0x66d0d0, '?rayHitsPart' + RD + 'AAE?AVSnapInfo@12@' + ARR_P + '_N@Z'),
        (0x66d260, '?findSnap' + RD + 'AAE?AVSnapInfo@12@' + ARR_P + '@Z'),
        (0x66d3c0, '?append@?$Array@W4NormalId@RBX@@@G3D@@QAEXABW4NormalId@RBX@@@Z'),
        (0x66d430, '?smartPtrHackPre' + RD + 'AAEXXZ'),
        (0x66d4f0, '?init' + RD + 'QAEXPAVWorkspace@2@V?$weak_ptr@VPartInstance@RBX@@@boost@@ABVVector3@G3D@@@Z'),
        (0x66d710, '?snapDragPart' + RD + 'AAE_NXZ'),
        (0x66d9f0, '?rayHitsCloserPart' + RD + 'AAE_NXZ'),
        (0x66daf0, '?findSafeY' + RD + 'AAEXXZ'),
        (0x66dc80, '?smartPtrHackPost' + RD + 'AAEXXZ'),
        (0x66e1a0, '?fallOffPart' + RD + 'AAE_NAA_N@Z'),
        (0x66e330, '?findNoSnapPosition' + RD + 'AAEXABVCoordinateFrame@G3D@@@Z'),
        (0x66e3d0, '?snap' + RD + 'QAE_NABVRay@G3D@@@Z'),
        (0x801430, '??__FdebugPlane@?6??updateHitFromSurface@SnapInfo@RunDragger@RBX@@QAEXABVRay@G3D@@@Z@YAXXZ'),
        (0x801440, '??__FdebugRay@?6??updateHitFromSurface@SnapInfo@RunDragger@RBX@@QAEXABVRay@G3D@@@Z@YAXXZ'),
    ],
    'stage': [
        (0x66f570, '?stepWorld@AssemblyStage@RBX@@UAEXHH_N@Z'),
        (0x66f790, '??1AssemblyStage@RBX@@UAE@XZ'),
        (0x66f8b0, '??_GAssemblyStage@RBX@@UAEPAXI@Z'),
    ],
}
# Built but not exact (recorded exact=false, never counted).
NEAR = {
    'drag': [(0x66dd90, '?moveDragPart' + RD + 'AAE_NXZ')],
}
# ---- externals: the address the original instruction uses (call site in parentheses) --------------------------------
EXTERNAL = {
    # G3D 6.09 out-of-line members (G3D owner; 0x00513220 is Matrix3::operator= by evidence name: the identical
    # copy-constructor body is folded onto it)
    '??AFace@RBX@@QAEAAVVector3@G3D@@H@Z': 0x476570,          # snapDragPart 0066d760 (folded with Matrix3::operator[])
    '?alignedFree@System@G3D@@SAXPAX@Z': 0x507d20,            # ~Array in fallOffPart / snap / findSafeY
    '??0Matrix3@G3D@@QAE@ABV01@@Z': 0x513220,                 # rotatePart 0066c5b7, findSafeY, snapDragPart
    '?getColumn@Matrix3@G3D@@QBE?AVVector3@2@H@Z': 0x513240,  # tiltPart (CoordinateFrame::rightVector)
    '??DMatrix3@G3D@@QBE?AV01@ABV01@@Z': 0x513350,            # tiltPart
    '?fromAxisAngle@Matrix3@G3D@@SA?AV12@ABVVector3@2@M@Z': 0x513680,   # tiltPart
    '?identity@Matrix3@G3D@@SAABV12@XZ': 0x513e20,            # turnUpright 0066cea5
    '?toObjectSpace@CoordinateFrame@G3D@@QBE?AVRay@2@ABV32@@Z': 0x518970,   # createSnapSurface, updateHitFromSurface
    # PartInstance / Primitive / Surfaces (2008 part-embedded declarations)
    '?getCoordinateFrame@PartInstance@RBX@@QBEABVCoordinateFrame@G3D@@XZ': 0x598cb0,
    '?getSurfaces@PartInstance@RBX@@QAEAAVSurfaces@2@XZ': 0x598de0,          # turnUpright 0066ce2a
    '?nonNullInWorkspace@PartInstance@RBX@@SA_NV?$shared_ptr@VPartInstance@RBX@@@boost@@@Z': 0x5995f0,
    '?fromPrimitive@PartInstance@RBX@@SAPAV12@PAVPrimitive@2@@Z': 0x599f80,  # findSafeY / smartPtrHackPost (fromPrimitiveConst body)
    '?setCoordinateFrame@PartInstance@RBX@@QAEXABVCoordinateFrame@G3D@@@Z': 0x59d8a0,
    '?lock@?$weak_ptr@VPartInstance@RBX@@@boost@@QBE?AV?$shared_ptr@VPartInstance@RBX@@@2@XZ': 0x5cab00,
    '?iRoundVector3@Math@RBX@@SA?AVVector3@G3D@@ABV34@@Z': 0x5de090,
    '?getClosestObjectNormalId@Math@RBX@@SA?AW4NormalId@2@ABVVector3@G3D@@ABVMatrix3@5@@Z': 0x5de560,   # turnUpright / tiltPart
    '?rotateMatrixAboutY90@Math@RBX@@SAXAAVMatrix3@G3D@@H@Z': 0x5de740,
    '?intersectRayPlane@Math@RBX@@SA_NABVRay@G3D@@ABVPlane@4@AAVVector3@4@@Z': 0x5df380,   # as app-unit660
    '?setVelocity@Primitive@RBX@@QAEXABVVelocity@2@@Z': 0x5e7760,
    '?getFirstContact@Primitive@RBX@@QAEPAVContact@2@XZ': 0x5e7bd0,
    '?getNextContact@Primitive@RBX@@QAEPAVContact@2@PAV32@@Z': 0x5e7be0,
    '?getFaceInWorld@Primitive@RBX@@QAE?AVFace@2@W4NormalId@2@@Z': 0x5e81b0,
    '?getCoordinateFrame@Primitive@RBX@@QBEABVCoordinateFrame@G3D@@XZ': 0x5e82c0,
    '?isStandardPart@Surfaces@RBX@@QBE?B_NXZ': 0x5ecc50,                      # turnUpright 0066ce31
    '?computeIsAdjacent@Contact@RBX@@QAE_NM@Z': 0x606ca0,
    '??_9Contact@RBX@@$BBM@AE': 0x606ce0,   # findSnap: vcall thunk of Contact::computeIsColliding (slot 0x1c)
    '?intersectingOthers@ContactManager@RBX@@QAE_NPAVPrimitive@2@M@Z': 0x60dcd0,
    '?closestFace@Extents@RBX@@QAE?AW4NormalId@2@ABVVector3@G3D@@@Z': 0x60f3e0,   # only caller 0066c3ec (app-unit609)
    '?getPlane@Extents@RBX@@QBE?AVPlane@G3D@@W4NormalId@2@@Z': 0x60fe40,
    '?safeMoveNoDrop@Dragger@RBX@@SA?AVVector3@G3D@@ABV?$Array@PAVPrimitive@RBX@@@4@ABV34@AAVContactManager@2@@Z':
        0x610930,                                                              # findSafeY (app-unit609 counts it)
    '?getMousePart@MouseCommand@RBX@@SAPAVPartInstance@2@ABVRay@G3D@@ABVContactManager@2@PBVPrimitive@2@PBVHitTestFilter'
    '@2@AAVVector3@5@M@Z': 0x6160b0,
    '?hasOverlap@Face@RBX@@SA_NABV12@0M@Z': 0x649e90,
    '??0PartByLocalCharacter@RBX@@QAE@PAVInstance@1@@Z': 0x660380,
    '_atexit': 0x6a17af,                                                       # the two debug statics' destructors
    '__ftol2_sse': 0x6a17f0,                                                   # Array<NormalId>::resize grow factor
}
# Function-local statics: one address per symbol (the guard / object the original instruction uses).
LOCAL_STATIC = {
    '?v@?1??zero@Vector3@G3D@@SAABV23@XZ@4V23@A': 0x96f044, '??_B?1??zero@Vector3@G3D@@SAABV12@XZ@51': 0x96f050,
    '?v@?1??unitY@Vector3@G3D@@SAABV23@XZ@4V23@A': 0x972898, '??_B?1??unitY@Vector3@G3D@@SAABV12@XZ@51': 0x9728a4,
    '?v@?1??zero@Velocity@RBX@@SAABV23@XZ@4V23@A': 0x97d568, '??_B?1??zero@Velocity@RBX@@SAABV12@XZ@51': 0x97d580,
    # updateHitFromSurface's two debug copies (guard bits 1 / 2 of 0x0097da3c) and Array<NormalId>::resize's minSize
    '?debugPlane@?6??updateHitFromSurface@SnapInfo@RunDragger@RBX@@QAEXABVRay@G3D@@@Z@4VPlane@6@A': 0x97da0c,
    '?debugRay@?6??updateHitFromSurface@SnapInfo@RunDragger@RBX@@QAEXABVRay@G3D@@@Z@4V56@A': 0x97da20,
    '?$S2@?6??updateHitFromSurface@SnapInfo@RunDragger@RBX@@QAEXABVRay@G3D@@@Z@4IA': 0x97da3c,
    '?minSize@?3??resize@?$Array@W4NormalId@RBX@@@G3D@@QAEXH_N@Z@4HB': 0x97da40,
    '??_B?3??resize@?$Array@W4NormalId@RBX@@@G3D@@QAEXH_N@Z@53': 0x97da44,
}
# Not-built AssemblyStage virtuals / inherited out-of-line slots: the vtable slot value (0084d1a4 + 4 * slot).
VTABLE_NOT_BUILT = {
    '?getStageType@AssemblyStage@RBX@@UAE?AW4StageType@IStage@2@XZ': 0x6fa3f0,   # folded `mov eax, 4`
    '?onEdgeAdded@AssemblyStage@RBX@@UAEXPAVEdge@2@@Z': 0x66f5f0,
    '?onEdgeRemoving@AssemblyStage@RBX@@UAEXPAVEdge@2@@Z': 0x66f6e0,
    '?getMetric@IWorldStage@RBX@@UAEHW4MetricType@12@@Z': 0x64a3d0,             # kernel-stages owner
}
assert original.data(0x6fa3f0, 6) == b'\xb8\x04\x00\x00\x00\xc3'
USED_EXTERNAL = set()
UNBOUND = []
FOLDED = {}
binding = {}
BODIES = {}
for key in SOURCES:
    for n, b, r in match.coff_functions(Path(OBJ[key]).read_bytes()):
        BODIES.setdefault(key, {})[n] = (b, r)


def target_of(address):
    body, refs, _ = match.target('2008-06', '%08x' % address)
    return body, refs


def try_fold(which, symbol, value):
    """A COMDAT / library helper body bound outside the counted rows: the body compiled here must be exact there."""
    if symbol not in BODIES[which] or value not in FUNCTIONS:
        return False
    body, refs = BODIES[which][symbol]
    target, target_refs = target_of(value)
    if not match.exact_match(target, target_refs, body, refs):
        return False
    FOLDED.setdefault(symbol, (value, which))
    return FOLDED[symbol][0] == value


def verify(which, rows, own, strict=True):
    raw = Path(OBJ[which]).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = BODIES[which]
    result = []
    for address, name in rows:
        assert name in bodies or DISCOVER, (name, [n for n in bodies if n[:16] == name[:16]])
        if name not in bodies:
            continue
        body, refs = bodies[name]
        target, target_refs = target_of(address)
        exact = match.exact_match(target, target_refs, body, refs)
        entry = {'address': '%08x' % address if strict else H(address), 'symbol': name, 'size': len(body),
                 'target_size': len(target), 'exact': exact}
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
            elif symbol.startswith('??_7'):
                rtti, at = original.vtable_class(value)
                cls = symbol[4:symbol.index('@@6B') + 2]
                assert rtti == '.?AV' + cls, (name, symbol, hex(value), rtti)
                how = 'vtable RTTI %s offset %#x' % (rtti, at)
            elif symbol in own:
                assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
                how = 'own row'
            elif symbol in LOCAL_STATIC:
                assert LOCAL_STATIC[symbol] == value, (name, symbol, hex(value), hex(LOCAL_STATIC[symbol]))
                how = 'function-local static'
            elif symbol in EXTERNAL:
                assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
                how = 'external' + (' (evidence name)' if names.get(value, '') == symbol else '')
                USED_EXTERNAL.add(symbol)
            elif try_fold(which, symbol, value):
                how = 'helper / COMDAT body, compared exact at the bound address'
            else:
                UNBOUND.append("    %r: %#x,   # %s in %s" % (symbol, value, names.get(value, '')[:60], name[:60]))
                continue
            prev = binding.setdefault(symbol, (value, name))
            assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
            verified[symbol] = '%s (%s)' % (hex(value), how)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local)})
        result.append(entry)
    return result


own = {n: a for rows in ROWS.values() for a, n in rows}
own.update({n: a for rows in NEAR.values() for a, n in rows})
groups = {k: verify(k, rows, own) for k, rows in ROWS.items()}
near = {k: verify(k, rows, own, strict=False) for k, rows in NEAR.items()}
folded_out = [{'address': H(v), 'symbol': s, 'unit': w,
               'reason': 'COMDAT / library helper body bound at this address and compared exact; not counted'}
              for s, (v, w) in sorted(FOLDED.items())]
if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for g in list(groups.values()) + list(near.values()):
        for r in g:
            if not r['exact']:
                print('NOT EXACT', r['address'], r['symbol'][:110], r['size'], r['target_size'])
    print('FOLDED', FOLDED)
    sys.exit(0)
assert not UNBOUND, '\n'.join(UNBOUND)
assert sorted(USED_EXTERNAL) == sorted(EXTERNAL), sorted(set(EXTERNAL) - USED_EXTERNAL)
for symbol, address in EXTERNAL.items():
    assert address in FUNCTIONS, (symbol, hex(address))
assert all(not r['exact'] for g in near.values() for r in g), 'a NEAR row became exact: move it to ROWS'


# ---- structure: allocation size before the constructor call, RTTI bases ----------------------------------------------
def new_before(call_site, ctor, size):
    window = original.data(call_site - 0x40, 0x45)
    assert window[-5] == 0xe8 and call_site + 5 + struct.unpack_from('<i', window, 0x41)[0] == ctor, hex(call_site)
    push = (b'\x6a' + bytes([size])) if size < 0x80 else (b'\x68' + struct.pack('<I', size))
    at = window.rindex(push)
    calls = [i for i in range(at + len(push), len(window) - 9)
             if window[i] == 0xe8 and call_site - 0x40 + i + 5 + struct.unpack_from('<i', window, i + 1)[0] == 0x6a0920]
    assert calls, hex(call_site)
    return '%08x: new(%#x) before %08x' % (call_site, size, ctor)


def call_site(caller, callee):
    for ins in CS.disasm(original.data(caller, FUNCS[caller]['size']), caller):
        if ins.mnemonic == 'call' and ins.op_str == hex(callee):
            return ins.address
    raise AssertionError((hex(caller), hex(callee)))


allocations = [
    new_before(call_site(0x665f20, 0x66c900), 0x66c900, 0x70),    # PartDragTool(): new(0x70) RunDragger()
    new_before(call_site(0x669870, 0x66f800), 0x66f800, 0x50),    # TreeStage(): new(0x50) AssemblyStage(this, world)
    new_before(call_site(0x66f800, 0x64b8e0), 0x64b8e0, 0x1ec),   # AssemblyStage(): new(0x1ec) SleepStage (not built)
]
ctor_bytes = original.data(0x66f800, FUNCS[0x66f800]['size'])
for needle in (b'\x89\x4e\x04', b'\x89\x46\x08', b'\x89\x7e\x0c', b'\x8d\x4e\x10', b'\x8d\x4e\x30',
               b'\xc7\x06' + struct.pack('<I', 0x84d1a4)):
    assert needle in ctor_bytes, needle.hex()


def bases(vtable):
    hierarchy = d(d(vtable - 4) + 16)
    out = {}
    for i in range(d(hierarchy + 8)):
        bcd = d(d(hierarchy + 12) + 4 * i)
        out.setdefault(original.string(d(bcd) + 8), struct.unpack('<i', original.data(bcd + 8, 4))[0])
    return out


rtti = {'AssemblyStage 0084d1a4': bases(0x84d1a4)}
assert rtti['AssemblyStage 0084d1a4'] == {'.?AVAssemblyStage@RBX@@': 0, '.?AVIWorldStage@RBX@@': 0,
                                          '.?AVIStage@RBX@@': 0}, rtti


# ---- vtable from the object built with the current header, slot by slot ----------------------------------------------
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


def check_vtable(obj, symbol, address, which):
    out, bad = [], []
    slot_names = dict(own)
    for s, (v, _) in FOLDED.items():
        slot_names.setdefault(s, v)
    for i, slot in enumerate(compiled_vtable(obj, symbol)):
        value = d(address + 4 * i)
        if slot.startswith('??_E') and '??_G' + slot[4:] in slot_names:
            ok, how = slot_names['??_G' + slot[4:]] == value, 'bound (??_G row)'
        elif slot in slot_names:
            ok, how = slot_names[slot] == value, 'bound'
        elif slot in VTABLE_NOT_BUILT:
            ok, how = VTABLE_NOT_BUILT[slot] == value, 'not built here; slot value checked'
        elif slot in BODIES[which] and value in FUNCTIONS:
            target, target_refs = target_of(value)
            ok, how = match.exact_match(target, target_refs, *BODIES[which][slot]), 'inline body compared exact'
        else:
            ok, how = False, 'unbound'
        out.append({'slot': i, 'symbol': slot, 'original': H(value), 'ok': ok, 'how': how})
        if not ok:
            bad.append((i, slot, hex(value), how))
    assert not bad or DISCOVER, (symbol, bad)
    assert len(out) == 7, len(out)
    return out


vt = {'AssemblyStage 0084d1a4': check_vtable(OBJ['stage'], '??_7AssemblyStage@RBX@@6B@', 0x84d1a4, 'stage')}


# ---- counting rules --------------------------------------------------------------------------------------------------
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
        found = []
        if 'exact_function_rows' in data:
            found = data['exact_function_rows']
        elif isinstance(data.get('exact_addresses'), list):
            found = data['exact_addresses']
        elif isinstance(data.get('exact_unique_addresses'), list):
            found = data['exact_unique_addresses']
        else:
            def walk(o):
                if isinstance(o, list):
                    for e in o:
                        walk(e)
                elif isinstance(o, dict):
                    if 'address' in o and o.get('exact') is True:
                        found.append(o['address'])
                    else:
                        for v in o.values():
                            walk(v)
            walk(data.get('methods', []))
        if isinstance(found, dict):
            found = list(found)
        for r in found:
            r = r.get('address', '') if isinstance(r, dict) else str(r)
            m = re.match(r'(?:0x)?([0-9a-fA-F]{6,8})', r)
            if m:
                out.setdefault(int(m.group(1), 16), set()).add(Path(path).name)
    return out


elsewhere = counted_elsewhere()
exact_rows = sorted({r['address'] for rows in groups.values() for r in rows if r['exact']})
double = {a: sorted(elsewhere[int(a, 16)]) for a in exact_rows if int(a, 16) in elsewhere}
assert not double, double
rows = sorted(a for a in FUNCS if LO <= a < HI)
range_counted = {a: sorted(v) for a, v in sorted(elsewhere.items()) if LO <= a < HI}


def method_rows(receipt):
    """Rows a receipt lists in its methods without an exact marker (built there, not counted by the rule)."""
    data = json.loads((ROOT / 'work/2008-06/shared-layouts' / receipt).read_text())
    return {int(m['address'], 16) for m in data.get('methods', []) if isinstance(m, dict) and 'address' in m}


# ---- unit map: blocks with boundary evidence (checked) ---------------------------------------------------------------
def rel32_targets(a):
    out = set()
    end = a + FUNCS[a]['size']
    for ins in CS.disasm(original.data(a, FUNCS[a]['size']), a):
        if ins.mnemonic in ('call', 'jmp') and ins.op_str.startswith('0x'):
            v = int(ins.op_str, 16)
            if not a <= v < end:
                out.add(v)
    return out


def calls(a, *targets):
    t = rel32_targets(a)
    missing = [H(x) for x in targets if x not in t]
    assert not missing, (H(a), missing)
    return True


# Lua lcode.c tail (evidence names), RunDragger call graph, Balancing / MovingNoPhysicsBase, AssemblyStage, Adorn
assert names[0x66c040].startswith('?luaK_infix@@') and names[0x66c2f0].startswith('?luaK_patchlist@@')
assert calls(0x66e3d0, 0x66d430, 0x66c640, 0x66d260, 0x66dd90, 0x66e1a0, 0x66d9f0, 0x66c510, 0x66e330, 0x66dc80)
assert calls(0x66dd90, 0x66d710) and calls(0x66e1a0, 0x66d3c0, 0x66cfd0, 0x66c970, 0x66dd90)
assert calls(0x66d260, 0x66c600, 0x66ccc0, 0x66d0d0) and calls(0x66d4f0, 0x66ce20)
assert 0x66d4f0 in rel32_targets(0x665b00) or 0x66d4f0 in {v for a in FUNCS if 0x665900 <= a < 0x666240 for v in rel32_targets(a)}
assert calls(0x66e660, 0x643e00)                 # Balancing(humanoid, kP, kD): HumanoidState() 00643e00
assert calls(0x66f8b0, 0x66f790) and calls(0x669870, 0x66f800)
assert calls(0x66f5f0, 0x645830, 0x5e8c40) and calls(0x66f6e0, 0x645840, 0x5e9f60)
assert d(0x84d1a4) == 0x66f8b0 and d(0x84d1a4 + 8) == 0x66f570
assert d(0x84d1cc) == 0x66f8e0                   # IndexBox ??_G (leaves2008 owner)
states1, states3 = method_rows('humanoid-states1-working.json'), method_rows('humanoid-states3-working.json')
assert 0x66e660 in states1 and {0x66eaa0, 0x66eac0, 0x66eca0, 0x66edf0, 0x66ee10} <= states3

BLOCKS = [
    (0x66c000, 0x66c330, 'lua-lcode', 'Lua 5.1.1 lcode.c tail (luaK_infix 0x0066c040, luaK_posfix 0x0066c0b0, '
     'luaK_patchlist 0x0066c2f0; Lua evidence names): library code, not recovered.'),
    (0x66c330, 0x66e650, 'run-dragger', 'RBX::RunDragger (no vtable; 0x70 bytes, PartDragTool() 0x00665fc1 news 0x70 '
     'before RunDragger() 0x0066c900; tool/RunDragger.cpp): SnapInfo members, ctor / dtor, the SnapInfo copy ctor and '
     'default ctor (out of line for findSnap), the G3D::Array<NormalId> append / resize instantiation used only by '
     'fallOffPart (callers 0x0066e270 / 0x0066e27e only), findSnap, smartPtrHackPre / Post, init (PartDragTool '
     '0x00665b3f), snapDragPart, rayHitsCloserPart, findSafeY, moveDragPart, fallOffPart, findNoSnapPosition, snap '
     '(PartDragTool 0x00665bb9 / 0x00666148). Built here; moveDragPart 0x0066dd90 is the only non-exact row.'),
    (0x66e650, 0x66eaa0, 'balancing', 'HUMAN::Balancing (vtable 0x0084d0dc / 0x0084d0d4): constructor 0x0066e660 '
     '(built by humanoid-states1, methods list without an exact marker) and onComputeForce 0x0066e6a0 (pending there: '
     'Body / Cofm / SimBody layouts), thunk 0x0066ea90. Owner: humanoid states; not rebuilt here.'),
    (0x66eaa0, 0x66f510, 'moving-no-physics', 'HUMAN::MovingNoPhysicsBase (RTTI 7 bases, SimJob at +0xa0, vtable '
     '0x0084d150): getTorsoAssembly 0x0066eaa0, Name doDeclare / callDoDeclare / getName 0x0066eac0 / 0x0066eca0 / '
     '0x0066edf0 and ~MovingNoPhysicsBase 0x0066ee10 (built by humanoid-states3, methods list without exact markers), '
     'the Vector3 + inline-static helper 0x0066eb30, 0x0066eb90 (Humanoid::getRootBody 0x005d9180, Cofm::getMass), '
     'the boost::function manager / invoker 0x0066ecb0 / 0x0066ed10 (type_info 0x00962ce0), release 0x0066ed50, the '
     'bound step thunk 0x0066edc0, boost::function / slot construction 0x0066ef10 / 0x0066ef70, the dynamic_cast walk '
     '0x0066f020, constructor 0x0066f070 and onStep 0x0066f2c0 (pending there). Owner: humanoid states (lease '
     'family); not rebuilt here.'),
    (0x66f510, 0x66f8d0, 'assembly-stage', 'RBX::AssemblyStage (RTTI .?AVAssemblyStage@RBX@@, vtable 0x0084d1a4, 0x50 '
     'bytes): wakeAssembly 0x0066f510, onAssemblyAdded 0x0066f530, onAssemblyRemoving 0x0066f550 (SleepStage members '
     '0x0064b890 / 0x0064aff0 / 0x0064b0a0), stepWorld 0x0066f570, onEdgeAdded 0x0066f5f0, onEdgeRemoving 0x0066f6e0, '
     '~AssemblyStage 0x0066f790, AssemblyStage() 0x0066f800, ??_G 0x0066f8b0. Built here: stepWorld, the destructor '
     'and ??_G; the others need a 2008 SleepStage, Assembly and Edge accessors (see proposals).'),
    (0x66f8d0, 0x66f900, 'index-box', 'RBX::IndexBox ~IndexBox 0x0066f8d0 / ??_G 0x0066f8e0 (vtable 0x0084d1cc): '
     'counted by leaves2008-working.json.'),
    (0x66f900, HI, 'adorn-rbxgfx', 'RBX::AdornRbxGfx tail (vtable 0x0084d2a4: getWidth / getHeight 0x0066f900 / '
     '0x0066f910, quad / line draws 0x0066f920 / 0x0066f9c0 / 0x0066fa50, setObjectToWorldMatrix .. uniqueName and '
     'the map<string, MeshPtr> pair / _Tree helpers, the weak_ptr<PartInstance> _Allocate 0x0066fd40, measure '
     '0x0066fda0 / 0x0066fe30, SharedPtr<RbxFont> dtor / ??_G 0x0066fe70 / 0x0066fe90, the RenderMaterial row '
     '0x0066ffb0): adorn / render-material owners; not rebuilt here.'),
]
UNIT_MAP = {}
row_map = []
for lo, hi, key, text in BLOCKS:
    inside = [a for a in rows if lo <= a < hi]
    assert inside, key
    UNIT_MAP['%s %s..%s' % (key, H(lo), H(hi - 1))] = {
        'rows': len(inside), 'unit': text, 'library': key == 'lua-lcode',
        'counted_here': [a for a in exact_rows if lo <= int(a, 16) < hi],
        'counted_elsewhere': ['%08x counted by %s' % (a, ', '.join(range_counted[a])) for a in inside
                              if a in range_counted],
    }
    for a in inside:
        row_map.append({'row': H(a), 'size': FUNCS[a]['size'], 'block': key,
                        'evidence_name': names.get(a, '')[:120] or None,
                        'counted': 'here' if '%08x' % a in exact_rows else
                        ('elsewhere: ' + ', '.join(range_counted[a]) if a in range_counted else
                         'no (methods list of humanoid-states1-working.json)' if a in states1 else
                         'no (methods list of humanoid-states3-working.json)' if a in states3 else 'no')})
assert sum(v['rows'] for v in UNIT_MAP.values()) == len(rows)
outside = [a for a in exact_rows if not LO <= int(a, 16) < HI]
assert outside == ['00801430', '00801440'], outside   # the two atexit thunks of updateHitFromSurface's statics

NOT_BUILT = {
    'RunDragger::moveDragPart 0x0066dd90': 'built, 1027 / 1027 B, not exact: the snap normal Math::getWorldNormal('
        'surface, snapCoord) is scheduled with all three column loads before the sign (target: two loads, sign, then '
        '`fmul [edi+ecx*4+0x18]`), which shifts the register choice of the following lea / push sequence.',
    'AssemblyStage() 0x0066f800': 'news a 0x1ec-byte SleepStage (0x0064b8e0); no native header declares a 2008 '
                                  'SleepStage (native-world SleepStage.h is the source-derived port).',
    'AssemblyStage::wakeAssembly / onAssemblyAdded / onAssemblyRemoving 0x0066f510 / 0x0066f530 / 0x0066f550': 'call '
        'SleepStage::onWakeUpRequest(a, false) 0x0064b890, onAssemblyAdded 0x0064aff0, onAssemblyRemoving 0x0064b0a0 '
        'and Assembly::putInPipeline / removeFromStage (IPipelined 0x00645830 / 0x00645840): need 2008 SleepStage and '
        'Assembly declarations.',
    'AssemblyStage::onEdgeAdded / onEdgeRemoving 0x0066f5f0 / 0x0066f6e0': 'write the 2008 Assembly +0x14 byte of '
        'both primitives\' assemblies (Primitive::getAssembly 0x005e7560), read Edge prim0 / prim1 (+0xc / +0x10) and '
        'call Primitive::getContact / getJoint 0x005e7ce0 / 0x005e7d30 (declared by part-embedded Primitive.h, whose '
        'donor Edge / Joint headers do not mix with Joints2008.h in one unit).',
    'AssemblyStage::getStageType 0x006fa3f0': 'folded `mov eax, 4`: ASSEMBLY_STAGE is 4 in 2008, 3 in the donor '
                                              'IStage.h (kernel-stages IStage.h proposal); slot value checked only.',
}
REJECTED = {
    'smartPtrHackPre with `snapInfo.snap = nonNullInWorkspace(part) ? part->getPrimitive() : NULL`': 'one shared '
        'store (lea / xor then mov); the target stores in each branch (add ebp, 0x228 / mov [edi+0x24], 0): if / else',
    'init with the parameter named dragPart (shadowing the member)': 'the second lock (turnUpright argument) then '
        'reads the parameter; the target locks the parameter first and the member second',
    'snapDragPart with snapCoord built from drag->getCoordinateFrame().rotation': 'target reads snapInfo.snap '
        '(+0x24) for the rotation',
    'snapDragPart with Math::iRoundVector3(snapCoord.pointToObjectSpace(dragCorner)) in one expression': '720 / 723 '
        'B: one Vector3 temporary fewer; the named dragInSnap local is exact',
    'snapDragPart with const Vector3& corners, a named snappedWorld, or translation = translation + offset': 'not exact',
    'moveDragPart with (dragRotation.transpose() * aligned).transpose() in one expression': '1015 B and a 0x24-byte '
        'larger frame; the named `relative` Matrix3 gives the target size and frame',
    'moveDragPart snap normal from getWorldNormal(surface, snapCoord.rotation), a NormalId local, a const reference, '
    'or getColumn(...) * (float)sign': 'same x87 schedule (or 1013 B for the float form)',
    'AssemblyStage::stepWorld with a const_iterator and it++': 'not exact (loop head register moves); iterator with '
                                                               '++it (or it++) is exact',
}
PROPOSALS = {
    'engine owner (SleepStage)': (
        'a 2008 SleepStage declaration: 0x1ec bytes (AssemblyStage() 0x0066f81c pushes 0x1ec before SleepStage(this, '
        'world) 0x0064b8e0) with onWakeUpRequest(Assembly*, bool) 0x0064b890, onAssemblyAdded(Assembly*) 0x0064aff0 '
        'and onAssemblyRemoving(Assembly*) 0x0064b0a0. With it AssemblyStage() and the three assembly rows can be '
        'built here.'),
    'engine owner (Assembly)': (
        'a 2008 Assembly declaration with the byte at +0x14 that AssemblyStage::onEdgeAdded 0x0066f614 / 0x0066f61a '
        'and onEdgeRemoving 0x0066f6fb / 0x0066f6ff set to true on both primitives\' assemblies.'),
    'humanoid states owner (humanoid-states1 / humanoid-states3 receipts)': (
        'their methods lists carry no exact marker and the receipts have no exact_function_rows, so by the counting '
        'rule the rows 0x0066e660, 0x0066eaa0, 0x0066eac0, 0x0066eca0, 0x0066edf0 and 0x0066ee10 count nowhere; '
        'adding exact_function_rows (or exact: true) there would count them without a second recovery here.'),
    'open question (AssemblyStage +0x10)': (
        'the first std::set<T*> of AssemblyStage (+0x10) is constructed and destroyed only in this unit; it is declared '
        'std::set<Assembly*> after the donor member order. A reader elsewhere would settle the element type.'),
    'tool/RunDragger.h (donor, FYI)': (
        'the 2008 RunDragger keeps the donor layout and member set; colliding() is inline in 2008 (no row; snap '
        '0x0066e550 inlines it), so this unit defines it `inline` in the .cpp.'),
}

sha = nb.sha
receipt = {
    'class': 'RBX RunDragger / AssemblyStage rows and the unit map of the application range 0066c000..00670000 '
             '(2008-06), inactive',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM), /fp:fast /U_RELEASEASSERT',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in
                [Path(__file__).resolve()] + list(SOURCES.values()) + HEADERS},
    'objects': {k: sha(v) for k, v in OBJ.items()},
    'layout': layout,
    'allocations': allocations,
    'rtti_bases': rtti,
    'unit_map': UNIT_MAP,
    'row_map': row_map,
    'range_functions': len(rows),
    'range_rows_counted_by_other_receipts': ['%08x counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()],
    'rows': groups,
    'near_misses': near,
    'helper_bodies_not_counted': folded_out,
    'vtables': vt,
    'not_built': NOT_BUILT,
    'exact_function_rows': exact_rows,
    'rejected': REJECTED,
    'proposals': PROPOSALS,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
text = json.dumps(receipt, indent=2) + '\n'
bare = sorted(set(re.findall(r'"([0-9a-f]{8})"', text)) - set(exact_rows))
assert not bare, bare   # never a quoted bare address of a row not counted here
RECEIPT.write_text(text)
print('PASS app-unit66c: %d counted exact rows (%s); %d helper bodies compared; %d near miss; %d range rows, %d counted '
      'elsewhere; %d vtable verified'
      % (len(exact_rows), ' '.join(exact_rows), len(folded_out), sum(len(v) for v in near.values()), len(rows),
         len(range_counted), len(vt)))
