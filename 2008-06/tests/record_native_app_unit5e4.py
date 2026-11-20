"""Verify the inactive 2008-06 native rows of the application range 005e4000..005e8000, and record the unit map of the
range (boundary evidence in the receipt's `unit_map`; rows counted by other receipts are written there as
'ADDR counted by RECEIPT' text, never as quoted bare addresses).

Unit map summary (details in UNIT_MAP below; the same unit boundaries as the app-unit5dc-2008 map of 005dc000..005e8000):
  * v8datamodel/JointInstance.cpp tail ..005e50bf: blocked by the JointInstance.h AutoJoint layout (proposal).
  * v8world/Mechanism.cpp 005e50c0..005e54bf: MechanismTracker::tracking 005e50e0 built here
    (native-classes/AppUnit5E4Mechanism.cpp, donor v8world/Mechanism.h read-only).
  * v8datamodel/JointsService.cpp 005e54c0..005e5bef: services owner (counted elsewhere / Workspace proposal).
  * v8world/MotorJoint.cpp 005e5bf0..005e5eff: MotorJoint::isAligned 005e5d00 built here
    (native-classes/AppUnit5E4MotorJoint.cpp against the native Joints2008.h / Primitive2008.h).
  * v8world/Assembly.cpp (Assembly / Clump) 005e5f00..005e729f: the std::sort<MotorJoint**> helpers and
    G3D::Array<Edge*>::resize / append built here (native-classes/AppUnit5E4AssemblyTemplates.cpp).
  * v8world/Primitive.cpp head 005e72a0..: Primitive rows built here against the native Primitive2008.h
    (AppUnit5E4Primitive.cpp) and the part-embedded Primitive.h (AppUnit5E4PrimitiveParts.cpp).

Builds: document-swap flags, VS2008 RTM 21022, /fp:fast for the world units (none for the Mechanism unit); the
part-embedded build puts native-headers/part-embedded and native-headers/engine-world first on the include path.
No new header is created (no shadowing). Every counted row is relocation-masked exact against the original, and every
REL32/DIR32 target is bound to the address the original instruction uses and verified: imports by DLL export name,
constants by bytes, own symbols by the row proven here, externals by the explicit EXTERNAL map (evidence name or
call-site identification), and function-local statics by one address per symbol. A row is counted only when no other
receipt counts it. Writes work/2008-06/shared-layouts/app-unit5e4-working.json.
Set NATIVE_APP_UNIT5E4_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
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
OUT = nb.OUT / 'app-unit5e4'
OUT.mkdir(parents=True, exist_ok=True)
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT5E4_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit5e4-working.json'
LO, HI = 0x5e4000, 0x5e8000
SOURCES = {
    'primitive': R / 'native-classes/AppUnit5E4Primitive.cpp',
    'parts': R / 'native-classes/AppUnit5E4PrimitiveParts.cpp',
    'motor': R / 'native-classes/AppUnit5E4MotorJoint.cpp',
    'templates': R / 'native-classes/AppUnit5E4AssemblyTemplates.cpp',
    'mechanism': R / 'native-classes/AppUnit5E4Mechanism.cpp',
}
PART_EMBEDDED = R / 'native-headers/part-embedded'
ENGINE_WORLD = R / 'native-headers/engine-world'


def build(name, src, extra=(), first=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + ['/I' + str(p) for p in first] + flags[i:] + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


OBJ, FLAGS = {}, {}
OBJ['primitive'], FLAGS['primitive'] = build('NativeAppUnit5E4_primitive', SOURCES['primitive'], ['/fp:fast'])
OBJ['parts'], FLAGS['parts'] = build('NativeAppUnit5E4_parts', SOURCES['parts'], ['/fp:fast'],
                                     [PART_EMBEDDED, ENGINE_WORLD])
OBJ['motor'], FLAGS['motor'] = build('NativeAppUnit5E4_motor', SOURCES['motor'], ['/fp:fast'])
OBJ['templates'], FLAGS['templates'] = build('NativeAppUnit5E4_templates', SOURCES['templates'], ['/fp:fast'])
OBJ['mechanism'], FLAGS['mechanism'] = build('NativeAppUnit5E4_mechanism', SOURCES['mechanism'])

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}

# ---- externals: address the original instruction uses -------------------------------------------------------------
EXTERNAL = {
    # evidence names
    '?getJointK@Constants@RBX@@SA?BMABVVector3@G3D@@_N@Z': 0x649730,        # computeJointK 005e75a4
    '?newTouch@RBX@@YAXPAVPrimitive@1@0@Z': 0x5e74c0,                       # onNewTouch 005e753c / 005e7543
    '?getCoordinateFrame@Primitive@RBX@@QBEABVCoordinateFrame@G3D@@XZ': 0x5e82c0,   # isAligned 005e5d12 / 005e5d2a
    '??DCoordinateFrame@G3D@@QBE?AV01@ABV01@@Z': 0x476700,                  # isAligned 005e5d19 / 005e5d31
    '?fuzzyEq@Math@RBX@@SA_NABVVector3@G3D@@0M@Z': 0x5de1d0,                # isAligned (app-unit5dc row)
    '?onPrimitiveContactParametersChanged@World@RBX@@QAEXPAVPrimitive@2@@Z': 0x5e9190,   # setFriction / setElasticity
    '?setVelocity@Body@RBX@@QAEXABVVelocity@2@@Z': 0x614040,                # setVelocity tail jump (body-primitive2008 row)
    '?fromExtentsSide@Face@RBX@@SA?AV12@ABVExtents@2@W4NormalId@2@@Z': 0x649920,   # getFaceInObject
    '?normalIdToMatrix3@RBX@@YAABVMatrix3@G3D@@W4NormalId@1@@Z': 0x5ec800,  # getFaceCoordInObject (app-unit5ec row)
    '?normalIdToVector3@RBX@@YAABVVector3@G3D@@W4NormalId@1@@Z': 0x5ec570,  # getFaceCoordInObject (app-unit5ec row)
    # call-site identification
    '?assign@Guid@RBX@@QAEXUData@12@@Z': 0x5a8200,                          # setGuid 005e7461: 8-byte Data by value on this+8
    '?onPrimitiveCanCollideChanged@World@RBX@@QAEXPAVPrimitive@2@@Z': 0x5e9460,   # setCanCollide tail jump (World.cpp)
    '?alignedFree@System@G3D@@SAXPAX@Z': 0x507d20,                          # ~EdgeList (same binding as app-unit5dc)
    '?getColumn@Matrix3@G3D@@QBE?AVVector3@2@H@Z': 0x513240,                # isAligned (push 2; app-unit5ec binding)
    '??0Matrix3@G3D@@QAE@ABV01@@Z': 0x513220,                               # getFaceCoordInObject (ICF with operator=; app-unit5dc)
    '?realloc@?$Array@PAVEdge@RBX@@@G3D@@AAEXH@Z': 0x502080,                # Array<Edge*>::resize (ICF-shared realloc, as contact-unit2008)
    '__ftol2_sse': 0x6a17f0,                                                # Array<Edge*>::resize (static CRT)
}
LOCAL_STATIC_AT = {
    # Array<Edge*>::resize function-local `static const int minSize` and its guard (one address per symbol)
    '?minSize@?3??resize@?$Array@PAVEdge@RBX@@@G3D@@QAEXH_N@Z@4HB': 0x97abb8,
    '??_B?3??resize@?$Array@PAVEdge@RBX@@@G3D@@QAEXH_N@Z@53': 0x97abbc,
}
UNBOUND = []
binding = {}

# (address, symbol or unique prefix): one entry per counted address
ROWS = {
    'primitive': [
        (0x005e7420, '?setUnknown0x14@Primitive@RBX@@QAEXH@Z'),
        (0x005e7530, '?onNewTouch@Primitive@RBX@@SAXPAV12@0@Z'),
        (0x005e7580, '?computeJointK@Primitive@RBX@@IBEMXZ'),
        (0x005e7850, '?setSurfaceType@Primitive@RBX@@QAEXW4NormalId@2@W4SurfaceType@2@@Z'),
        (0x005e7910, '??1EdgeList@RBX@@QAE@XZ'),
        (0x005e7bd0, '?getFirstContact@Primitive@RBX@@QAEPAVContact@2@XZ'),
        (0x005e7f10, '?getRadius@Primitive@RBX@@UBEMXZ'),
    ],
    'parts': [
        (0x005e7450, '?setGuid@Primitive@RBX@@QAEXABVGuid@2@@Z'),
        (0x005e7550, '?setClump@Primitive@RBX@@QAEXPAVClump@2@@Z'),
        (0x005e75b0, '?setCanCollide@Primitive@RBX@@QAEX_N@Z'),
        (0x005e75e0, '?setCanSleep@Primitive@RBX@@QAEX_N@Z'),
        (0x005e7600, '?setFriction@Primitive@RBX@@QAEXM@Z'),
        (0x005e7640, '?setElasticity@Primitive@RBX@@QAEXM@Z'),
        (0x005e7680, '?getFaceCoordInObject@Primitive@RBX@@QAE?AVCoordinateFrame@G3D@@W4NormalId@2@@Z'),
        (0x005e76f0, '?getFaceInObject@Primitive@RBX@@QAE?AVFace@2@W4NormalId@2@@Z'),
        (0x005e7760, '?setVelocity@Primitive@RBX@@QAEXABVVelocity@2@@Z'),
    ],
    'motor': [
        (0x005e5d00, '?isAligned@MotorJoint@RBX@@EAE_NXZ'),
    ],
    'templates': [
        (0x005e61e0, '??$_Push_heap@PAPAVMotorJoint@RBX@@HPAV12@P6A_NPBV12@0@Z@std@@'),
        (0x005e6540, '?resize@?$Array@PAVEdge@RBX@@@G3D@@QAEXH_N@Z'),
        (0x005e6640, '?append@?$Array@PAVEdge@RBX@@@G3D@@QAEXABQAVEdge@RBX@@@Z'),
        (0x005e66b0, '??$_Med3@PAPAVMotorJoint@RBX@@P6A_NPBV12@0@Z@std@@'),
        (0x005e6720, '??$_Adjust_heap@PAPAVMotorJoint@RBX@@HPAV12@P6A_NPBV12@0@Z@std@@'),
        (0x005e6830, '??$_Median@PAPAVMotorJoint@RBX@@P6A_NPBV12@0@Z@std@@'),
        (0x005e68e0, '??$_Make_heap@PAPAVMotorJoint@RBX@@HPAV12@P6A_NPBV12@0@Z@std@@'),
        (0x005e6920, '??$_Insertion_sort1@PAPAVMotorJoint@RBX@@P6A_NPBV12@0@ZPAV12@@std@@'),
        (0x005e69d0, '??$_Unguarded_partition@PAPAVMotorJoint@RBX@@P6A_NPBV12@0@Z@std@@'),
        (0x005e6ca0, '??$_Sort_heap@PAPAVMotorJoint@RBX@@P6A_NPBV12@0@Z@std@@'),
        (0x005e6e90, '??$_Sort@PAPAVMotorJoint@RBX@@HP6A_NPBV12@0@Z@std@@'),
    ],
    'mechanism': [
        (0x005e50e0, '?tracking@MechanismTracker@RBX@@QAE_NXZ'),
    ],
}


def target_of(address):
    body, refs, _ = match.target('2008-06', '%08x' % address)
    return body, refs


def resolve(obj, rows):
    funcs = match.coff_functions(Path(obj).read_bytes())
    out = []
    for address, key in rows:
        hits = [x for x in funcs if x[0] == key] or [x for x in funcs if x[0].startswith(key) and not nb.LOCAL_EH.match(x[0])]
        if DISCOVER and len(hits) != 1:
            print('UNRESOLVED', '%08x' % address, key[:120], [h[0][:120] for h in hits])
            continue
        assert len(hits) == 1, ('%08x' % address, key, [h[0] for h in hits])
        out.append((address, hits[0][0]))
    return out


def bind_value(raw, sections, symbols, definitions, name, body, target, address, own):
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
        elif symbol in own:
            assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
            how = 'own row'
        elif symbol in EXTERNAL:
            assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
            how = 'external' + (' (evidence name)' if names.get(value, '') == symbol else ' (call-site identification)')
        elif symbol in LOCAL_STATIC_AT:
            assert LOCAL_STATIC_AT[symbol] == value, (name, symbol, hex(value), hex(LOCAL_STATIC_AT[symbol]))
            how = 'static data (one address per symbol)'
        else:
            UNBOUND.append("    %r: %#x,   # %s in %s" % (symbol, value, names.get(value, '')[:60], name[:60]))
            continue
        prev = binding.setdefault(symbol, (value, name))
        assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
        verified[symbol] = '%s (%s)' % (hex(value), how)
    return verified, local


def verify(which, rows, own):
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
            assert DISCOVER, (name, entry['address'], len(body), len(target))
            entry['address'] = '%08x (not exact)' % address
            result.append(entry)
            continue
        verified, local = bind_value(raw, sections, symbols, definitions, name, body, target, address, own)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local)})
        result.append(entry)
    return result


resolved = {k: resolve(OBJ[k], rows) for k, rows in ROWS.items()}
own = {}
for rows in resolved.values():
    for address, name in rows:
        own.setdefault(name, address)
groups = {k: verify(k, rows, own) for k, rows in resolved.items()}

if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for g, rows in groups.items():
        for r in rows:
            if not r['exact']:
                print('NOT EXACT', g, r['address'], r['symbol'][:90], r['size'], r['target_size'])
    sys.exit(0)
assert not UNBOUND, UNBOUND

# ---- layout / slot evidence checked against the target bytes --------------------------------------------------------
# MotorJoint vtable 0083f764 slot 9 is isAligned 005e5d00 (Joints2008.h); Primitive vtable 0083f83c slot 3 is
# getRadius 005e7f10 (Primitive2008.h). Only the original image is read here: the objects built above emit no vtable.
assert struct.unpack('<I', original.data(0x83f764 + 9 * 4, 4))[0] == 0x5e5d00
assert struct.unpack('<I', original.data(0x83f83c + 3 * 4, 4))[0] == 0x5e7f10
# Primitive offsets the bodies use (also proven by the exact rows): clump +0x5c (setClump 005e7550), world +0x58
# (setUnknown0x14 005e7429), canCollide +0xac (005e75b6), friction +0xb0 (005e7600), elasticity +0xb4 (005e7640),
# surfaceType +0xb8 (005e7858), geometry +0x9c (005e7583), body +0xa0 (005e7760).
assert original.data(0x5e7554, 3) == bytes.fromhex('3b415c')
assert original.data(0x5e7429, 4) == bytes.fromhex('83795800')
assert original.data(0x5e75b6, 6) == bytes.fromhex('3a88ac000000')
assert original.data(0x5e7858, 7) == bytes.fromhex('399481b8000000')
assert original.data(0x5e7760, 6) == bytes.fromhex('8b89a0000000')


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
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if LO <= int(a, 16) < HI}

# ---- unit map --------------------------------------------------------------------------------------------------
RANGE_ROWS = [json.loads(l) for l in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines() if l.strip()]
RANGE_ROWS = [r for r in RANGE_ROWS if LO <= int(r['addr'], 16) < HI]
UNITS = [
    ('v8datamodel/JointInstance.cpp', 0x5e4000, 0x5e50c0),
    ('v8world/Mechanism.cpp', 0x5e50c0, 0x5e54c0),
    ('v8datamodel/JointsService.cpp', 0x5e54c0, 0x5e5bf0),
    ('v8world/MotorJoint.cpp', 0x5e5bf0, 0x5e5f00),
    ('v8world/Assembly.cpp', 0x5e5f00, 0x5e72a0),
    ('v8world/Primitive.cpp', 0x5e72a0, 0x5e8000),
]
unit_rows = {}
for r in RANGE_ROWS:
    a = int(r['addr'], 16)
    unit = [u for u, lo, hi in UNITS if lo <= a < hi][0]
    unit_rows.setdefault(unit, []).append(r)

UNIT_MAP = {
    'v8datamodel/JointInstance.cpp': (
        'v8datamodel/JointInstance.cpp tail (the unit starts at 005e2760, see app-unit5dc-2008): the Snap / Weld / Glue / '
        'Rotate / RotateP / RotateV / Motor FactoryProduct / DescribedCreatable constructors and default constructors '
        '(Snap() 005e4600, Weld() 005e4810, Glue() 005e49a0, Rotate() 005e4ad0, Motor() 005e4ee0; the 163-byte '
        'FactoryProduct constructors 005e4010 / 005e4100 / 005e41d0 / 005e42b0 / 005e43a0), their ??_E adjustor thunks and '
        'getClassName leaves (8 / 11 bytes), JointInstance setPart0 / setPart1 / setC0 / setC1 005e4450..005e44c0, the '
        'shared_ptr / Creator helpers 005e44f0 / 005e4710 / 005e4c60 / 005e4dd0 and Motor::setMaxVelocity 005e4fe0 '
        '(Motor +0x14c MotorJoint, maxVelocity +0x90), the per-joint ??_G bodies 005e4920 / 005e4a60 / 005e4b90 / '
        '005e4d30 and the JointInstance(Joint*) family constructors. Not built here: in 2008 these joints derive from '
        'DescribedCreatable<C, JointInstance, sC> with no AutoJoint base (RTTI of the Weld vtable 0083f24c, stored by '
        'Weld() 005e4810), which the native v8datamodel/JointInstance.h does not declare (proposal repeated below). '
        'Mapping only.'),
    'v8world/Mechanism.cpp': (
        'v8world/Mechanism.cpp (kernel / SimJob owner): Mechanism::getMechanismFromPrimitive 005e50c0 (evidence name: '
        'Primitive::getAssembly 005e7570, then the folded 4-byte getter 005e6110 `mov eax, [ecx+0x40]`), '
        'MechanismTracker::tracking 005e50e0, the SimJob() / ~SimJob / ??_G / AssemblySimJob rows 005e50f0..005e51e0 '
        '(kernel-stages), fastRemoveShort over the job +0x4 vector 005e5200, MechanismTracker::stopTracking 005e5320, '
        'setMechanism 005e5350 (vector push_back 004213a0 on job +0x4, then tracker +0x0 = job) and transferTrackers '
        '005e53a0. Built here: tracking 005e50e0 (donor v8world/Mechanism.h; the field at +0x0 is the only one used). '
        'Not built: the others need the 2008 tracker / SimJob relation (proposal to the SimJob2008.h owner).'),
    'v8datamodel/JointsService.cpp': (
        'v8datamodel/JointsService.cpp (services owner, native v8datamodel/JointsService.h): onDescendentAdded 005e54c0 '
        'through the shared_ptr deleters to 005e5860 (services-working.json), the Notifier removeListener instance '
        '005e5a80 (humanoid2008-working.json) and onServiceProvider 005e5b50 (needs the Workspace getWorld proposal of '
        'the app-unit5dc / services receipts). Not built here.'),
    'v8world/MotorJoint.cpp': (
        'v8world/MotorJoint.cpp (world-joints owner, native v8world/Joints2008.h): MotorJoint() 005e5bf0, resetLink '
        '005e5c90, isAligned 005e5d00, setCurrentAngle 005e5da0 (pending-build-only in world-joints), ~MotorJoint 005e5e00, '
        'stepUi 005e5e70, ??_G 005e5ee0. Built here: isAligned 005e5d00 (slot 9 of vtable 0083f764), against Joints2008.h '
        'and Primitive2008.h. Not built: resetLink reads Body::parent at +0x14 (`mov ecx,[eax+0x14]` at 005e5c9c); the '
        'native v8kernel/Body2008.h has it there but cannot share a unit with Joints2008.h, whose donor v8world/Edge.h '
        'pulls the donor Body.h (parent +0x8; trial 98 B vs 100 B). See proposals.'),
    'v8world/Assembly.cpp': (
        'v8world/Assembly.cpp (2008 Assembly / Clump unit; engine owner; no native Assembly or Clump declaration exists): '
        'a Primitive anchored-or-dragging test 005e5f00 (+0xa8 / +0xa9 / +0xaa), SleepInfo() 005e5f30, a Guid compare '
        '005e5f60 (Primitive::getGuid 005e7440, Guid::compare 005a8330), assemblyPrimBegin / End 005e5fa0 / 005e5fc0, '
        'the Assembly members 005e5fe0..005e6170 (root primitive +0x1c, parent +0x20, +0x40 getter 005e6110 = '
        'getMechanismFromPrimitive tail), otherAssembly 005e61b0, the recursive primitive walks 005e6240 / 005e62d0 / '
        '005e6360, getMotor 005e6400, 005e6420 (Body / Math 005de630), the 7-byte leaf 005e6530, 005e6790 / 005e67c0 / '
        '005e6cf0 (new Assembly, setClump 005e7550, Body::setParent 006148b0, RigidJoint::getChildInParent 00645930, '
        'Body::setMeInParent 006142d0), 005e6ba0 / 005e6c70 (Array<Edge*> collection), the std::vector instance 005e6de0, '
        'the MotorJoint sorter 005e6f70 (push_back 004213a0, then std::sort), 005e6fd0 / 005e7050 (MotorJoint::resetLink '
        '005e5c90), ~Assembly 005e70a0 and its ??_G 005e7280. Built here (AppUnit5E4AssemblyTemplates.cpp, '
        'Roblox-instantiated templates referenced only by this unit and Primitive.cpp): the std::sort<MotorJoint**, '
        'bool (*)(const MotorJoint*, const MotorJoint*)> helpers _Push_heap 005e61e0, _Med3 005e66b0, _Adjust_heap 005e6720, '
        '_Median 005e6830, _Make_heap 005e68e0, _Insertion_sort1 005e6920, _Unguarded_partition 005e69d0, _Sort_heap '
        '005e6ca0, _Sort 005e6e90 (evidence names on the first six), and G3D::Array<Edge*>::resize 005e6540 / append '
        '005e6640 (evidence names; /fp:fast proven by resize: 264 B vs 256 B without it). The Assembly / Clump members '
        'need a 2008 Assembly / Clump declaration (layout from the constructor 005e6cf0 and ~Assembly 005e70a0); not '
        'attempted in this pass.'),
    'v8world/Primitive.cpp': (
        'v8world/Primitive.cpp head (continues into 005e8000; Body/Primitive owner, native v8world/Primitive2008.h and '
        'part-embedded v8world/Primitive.h). Geometry / Block / Ball inline virtuals 005e72a0..005e7400 and '
        'nullGeometry / Geometry::getCenterToCorner 005e7870 / 005e78c0 are counted by world-shapes-working.json. '
        'Built here against Primitive2008.h (AppUnit5E4Primitive.cpp): setUnknown0x14 005e7420, onNewTouch 005e7530, '
        'computeJointK 005e7580, setSurfaceType 005e7850, ~EdgeList 005e7910, getFirstContact 005e7bd0, getRadius '
        '005e7f10. Built here against part-embedded Primitive.h + engine-world World.h (AppUnit5E4PrimitiveParts.cpp): '
        'setGuid 005e7450, setClump 005e7550, setCanCollide 005e75b0, setCanSleep 005e75e0, setFriction 005e7600, '
        'setElasticity 005e7640, getFaceCoordInObject 005e7680, getFaceInObject 005e76f0, setVelocity 005e7760. Not '
        'built: the Body::getDepth-style walks 005e7300 (a function-static Vector3 compare, guard 0097abd0) / 005e7370 / '
        '005e7470, Edge::otherPrimitive-style 005e7490, newTouch 005e74c0 (needs 2008 Clump +0x24 / Assembly sleep '
        'state), getAssembly 005e7560 (unchecked copy) / 005e7570 (donor Clump puts the assembly at +0x20; 2008 +0x24), '
        'getGuid 005e7440, setSurfaceData 005e7770, computeFuzzyExtents 005e7980 and getFastFuzzyExtents 005e7a50 '
        '(part-embedded: donor Body pv +0x88, 2008 +0x94; Primitive2008.h: computeFuzzyExtents / hitTest not '
        'declared), the index-based EdgeList walkers 005e7ae0..005e7ba0, 005e7b20, 005e7c10, getFirstRigid / '
        'getNextRigid 005e7c80 / 005e7ca0, getJoint-style 005e7ce0 / 005e7d30 (need the 2008 Edge with list indices '
        '+0x14 / +0x18; contact owner proposal), getNextContact 005e7be0 (same), newGeometry 005e7d80 (not declared by '
        'Primitive2008.h), ~Primitive 005e7df0 (native-classes/PrimitiveLifetime.cpp, another owner), hitTest 005e7f20 '
        '(same Body offset issue).'),
}
unit_map = []
for u, lo, hi in UNITS:
    rows = unit_rows.get(u, [])
    unit_map.append({'unit': '%s %08x..%08x' % (u, lo, hi - 1), 'rows': len(rows), 'bytes': sum(r['size'] for r in rows),
                     'counted_elsewhere': ['%s counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()
                                           if lo <= int(a, 16) < hi],
                     'counted_here': len([a for a in exact_rows if lo <= int(a, 16) < hi]),
                     'library': False,
                     'evidence': UNIT_MAP[u]})
assert sum(u['rows'] for u in unit_map) == len(RANGE_ROWS)

REJECTED = {
    'MotorJoint::resetLink (005e5c90)': (
        'Joints2008.h + Primitive2008.h + donor Body.h: 100 B vs 98 B (donor Body::parent at +0x8, 2008 +0x14). Adding '
        'v8kernel/Body2008.h fails to compile (C2011 Body / Cofm / SimBody redefinition through the donor Edge.h -> '
        'IPipelined.h -> Kernel.h chain).'),
    'Primitive::hitTest / computeFuzzyExtents / getFastFuzzyExtents (part-embedded)': (
        'same size (212 / 197 / 136 B) but the donor Body.h reads pv at +0x88 (2008 +0x94); with v8kernel/Body2008.h the '
        'part-embedded Primitive.h does not compile (donor Body.h already included).'),
    'Primitive::getAssembly (part-embedded + donor Clump.h)': '14 / 14 B, reads Clump +0x20; the 2008 body reads +0x24.',
    'G3D::Array<Edge*>::resize without /fp:fast': '264 B vs 256 B (x87 growth-factor sequence).',
    'Primitive::setCanCollide with `canCollide != value`': 'cmp operand order (38 vs 3a); `value != canCollide` is exact.',
}

PROPOSALS = [
    'Owner of native-headers/v8world/Primitive2008.h (Body/Primitive): declare `Extents computeFuzzyExtents() const;` '
    '(005e7980), `bool hitTest(const G3D::Ray&, G3D::Vector3&, bool&);` (005e7f20), `static Geometry* '
    'newGeometry(Geometry::GeometryType);` (005e7d80, called by Primitive() 005e8770; Block new 0x18 vtable 0083f7ec, '
    'Ball new 0x14 vtable 0083f814, default Geometry::nullGeometry 005e7870), `void setClump(Clump*)` (005e7550), '
    '`Assembly* getAssembly() const` (005e7570: clump +0x5c, then Clump +0x24) and the setters setGuid 005e7450 / '
    'setCanCollide 005e75b0 / setCanSleep(+0xab) 005e75e0 / setFriction 005e7600 / setElasticity 005e7640. With '
    'computeFuzzyExtents declared, getFastFuzzyExtents 005e7a50 (already declared) and hitTest use the native Body2008 '
    'pv +0x94 and can be built in the native-Primitive configuration (they are not exact against the donor Body).',
    'Owner of native-headers/v8world/Joints2008.h (world-joints): MotorJoint::resetLink 005e5c90 needs Body::getParent '
    '(+0x14, native Body2008.h) in a unit that includes Joints2008.h; the donor v8world/Edge.h it includes pulls the '
    'donor Body.h. Including the native IPipelined2008.h Edge (contact owner proposal) would let resetLink be built. '
    'Byte shape: parentId = prim1->body->parent != prim0->body; link->reset(getJointCoord(parentId), '
    'getJointCoord(1 - parentId)) (Link::reset 00613da0); jointAngle +0xcc = currentAngle; Link::dirty 00613cb0.',
    'Owner of native-headers/v8world/SimJob2008.h (kernel stages): in 2008 MechanismTracker (one pointer at +0x0) tracks '
    'a SimJob, and the vector at SimJob +0x4 holds the trackers: stopTracking 005e5320 removes the tracker from '
    'job+0x4 with fastRemoveShort 005e5200, setMechanism 005e5350 pushes it (push_back 004213a0) and stores the job '
    'at tracker+0x0, and the ICF-folded out-of-line ~MechanismTracker 004c99b0 jumps to 005e5320. A 2008 '
    'MechanismTracker declaration next to SimJob would let 005e5200 / 005e5320 / 005e5350 / 005e53a0 be built.',
    'Owner of native-headers/v8datamodel/JointInstance.h (repeats the app-unit5dc / app-unit4b0 proposal): the 2008 '
    'joints derive from DescribedCreatable<C, JointInstance, sC> with `extern const char sC[]` and no AutoJoint; the '
    'JointInstance.cpp rows 005e4000..005e50bf of this range become candidates with that declaration.',
    'A future native v8world Assembly / Clump declaration (engine owner): Clump +0x24 is the Assembly (getAssembly '
    '005e7570, newTouch 005e74e3), Assembly root primitive +0x1c, parent +0x20, +0x40 getter 005e6110; the Assembly '
    'constructor 005e6cf0 and ~Assembly 005e70a0 give the remaining layout.',
]

receipt = {
    'scope': ('Inactive 2008-06 native recovery of the application range 005e4000..005e8000: unit map of every row; '
              'Primitive rows against the native Primitive2008.h and the part-embedded Primitive.h, MotorJoint::isAligned '
              'against Joints2008.h, the Assembly-unit std::sort<MotorJoint**> and G3D::Array<Edge*> instances, and '
              'MechanismTracker::tracking. No new header, no PENDING build. No runtime, link or class-swap claim.'),
    'exact_function_rows': exact_rows,
    'exact_function_row_count': len(exact_rows),
    'range_rows': len(RANGE_ROWS),
    'rows': groups,
    'unit_map': unit_map,
    'proposals': PROPOSALS,
    'rejected': REJECTED,
    'flags': FLAGS,
    'sources': {k: nb.sha(p) for k, p in SOURCES.items()},
    'headers_read_only': ['native-headers/v8world/Primitive2008.h', 'native-headers/v8world/Contact2008.h',
                          'native-headers/v8world/Joints2008.h', 'native-headers/part-embedded/v8world/Primitive.h',
                          'native-headers/engine-world/v8world/World.h',
                          'tools/rbxgs/Client/App/include/v8world/Mechanism.h (donor)',
                          'tools/rbxgs/Client/App/include/v8kernel/Constants.h (donor)',
                          'tools/rbxgs/Client/App/include/util/Math.h (donor)'],
    'new_headers': [],
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit5e4: %d counted rows (%d range rows)' % (len(exact_rows), len(RANGE_ROWS)))
