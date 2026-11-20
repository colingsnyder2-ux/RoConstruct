"""Verify the inactive 2008-06 native rows of the application code 00609a30..00610bf0 (after the PVInstance unit, up to
the Lua 5.1.1 library).

Unit map (boundary evidence in the receipt's `unit_map`; rows already counted by other receipts are listed there):
  * Feature / Hole / MotorFeature / VelocityMotor unit 00609a30..0060cad0: feature-working.json (pending VelocityMotor
    rows wait for header proposals already filed there; not rebuilt here).
  * ContactManager unit 0060cae0..0060dd5f: Ball/Block contact leaf virtuals (world-shapes, leaves2008) and the
    ContactManager members; needs the 2008 Primitive / Contact layouts (Contact sibling lease, not built here).
  * MegaDragger unit 0060dd60..0060e96f and DragUtilities unit 0060e970..0060f3df: partly counted by
    axis-move-tool-lifetime-trial.json; MegaDragger fields are owned by tool/MegaDragger.h (not built here).
  * Extents unit 0060f3e0..0060fe95: native-classes/AppUnit609_2008Extents.cpp against the committed native
    util/Extents.h (read-only).
  * Dragger unit 0060fea0..00610bee: native-classes/AppUnit609_2008Dragger.cpp against the donor tool/Dragger.h.
  * Lua 5.1.1 library from luaL_where 00610bf0 (library code, never recovered here).

Builds: document-swap flags, VS2008 RTM 21022, both units with /fp:fast (without it the Extents float bodies and the
Dragger safeMove* bodies differ, see `rejected`).

Every counted row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the
address the original instruction uses and verified: imports by DLL export name, constants by bytes, own symbols by
the row proven here, COMDAT support bodies by exactness at the bound address, the remaining externals by the explicit
EXTERNAL map (evidence name or a row counted by another receipt), local statics by one address per symbol.
A row is counted only when no other receipt counts it (top-level exact_function_rows, or exact_addresses /
exact_unique_addresses / exact method entries for older receipts).
Writes work/2008-06/shared-layouts/app-unit609-2008-working.json.
Set NATIVE_APP_UNIT609_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
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
OUT = nb.OUT / 'app-unit609-2008'
OUT.mkdir(parents=True, exist_ok=True)
SOURCES = {
    'ext': R / 'native-classes/AppUnit609_2008Extents.cpp',
    'drag': R / 'native-classes/AppUnit609_2008Dragger.cpp',
}
UNIT = {'ext': ['/fp:fast'], 'drag': ['/fp:fast']}
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT609_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit609-2008-working.json'


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags() + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


OBJ, FLAGS = {}, {}
for key, src in SOURCES.items():
    OBJ[key], FLAGS[key] = build('NativeAppUnit609_2008_' + key, src, UNIT[key])

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}

ARR = 'V?$Array@PAVPrimitive@RBX@@@G3D@@'
# ---- externals: address the original instruction uses (call site in parentheses) --------------------------------
EXTERNAL = {
    '?normalIdToVector3@RBX@@YAABVVector3@G3D@@W4NormalId@1@@Z': 0x5ec570,             # getPlane 0060fe5c (evidence name)
    '??0Plane@G3D@@QAE@ABVVector3@1@0@Z': 0x5259e0,   # getPlane 0060fe88 (G3D Plane(normal, point), out of line)
    '?overlapsOrTouches@Extents@RBX@@QBE_NABV12@@Z': 0x606b60,   # separatedByMoreThan 0060f799 (Contact unit 00606b60, see unit_map)
    '?toGrid@Math@RBX@@SA?AVVector3@G3D@@ABV34@0@Z': 0x5dee10,                          # toGrid 0060fedd (evidence name)
    '?toGrid@Math@RBX@@SA?AVVector3@G3D@@ABV34@M@Z': 0x5dee90,                          # safeMoveYDrop 006108bb (evidence name)
    '?isNanInfDenormVector3@Math@RBX@@SA_NABVVector3@G3D@@@Z': 0x5dd860,                # searchUpFine 0061033e (evidence name)
    '?intersectingOthers@ContactManager@RBX@@QAE_NAB' + ARR + 'M@Z': 0x60dc10,           # 00610166 (evidence name)
    # Dragger rows counted by axis-move-tool-lifetime-trial.json under analog names (applyMove 0060fef0) or not
    # built here (computeExtents(Array) 00610070 needs the 2008 Primitive layout: geometry +0x9c).
    '?movePrimitives@Dragger@RBX@@CAXAB' + ARR + 'ABVVector3@4@@Z': 0x60fef0,           # movePrimitivesDelta 0061027f
    '?computeExtents@Dragger@RBX@@SA?AVExtents@2@AB' + ARR + '@Z': 0x610070,            # 0061013e (evidence name)
}
# COMDAT bodies emitted in the unit objects whose call target is out of line in the original: accepted only when the
# compiled body is relocation-masked exact at the bound address (support rows, never counted here).
SUPPORT = {
    '?halfSpaceContains@Plane@G3D@@QBE_NVVector3@2@@Z': 0x518f20,                       # containedByFrustum 0060f8a1
    '?inf@Vector3@G3D@@SAABV12@XZ': 0x510960,                                           # vv 0060f8e3
}
UNBOUND = []
binding = {}
support_out = {}
# function-local statics: the address each original instruction uses (guard / value)
LOCAL_STATIC_AT = {
    '??_B?1??inf@Math@RBX@@SAABMXZ@51': 0x97b894, '?inf@?1??0Math@RBX@@SAABMXZ@4MA': 0x97b890,
    '??_B?1??dragSnap@Dragger@RBX@@SAABVVector3@G3D@@XZ@51': 0x976354,
    '?v@?1??dragSnap@Dragger@RBX@@SAABVVector3@G3D@@XZ@4V45@A': 0x976348,
    '??_B?1??zero@Vector3@G3D@@SAABV12@XZ@51': 0x96f050, '?v@?1??zero@Vector3@G3D@@SAABV23@XZ@4V23@A': 0x96f044,
}
LOCAL_STATIC = re.compile(r'^(\?\$S\d+@|\?\w+@\?\d+\?\?|\?\?_B\?\d+\?\?)')

# (address, symbol or unique prefix): one entry per counted address
ROWS = {
    'ext': [
        (0x60f3e0, '?closestFace@Extents@RBX@@QAE?AW4NormalId@2@ABVVector3@G3D@@@Z'),
        (0x60f480, '?getCorner@Extents@RBX@@QBE?AVVector3@G3D@@H@Z'),
        (0x60f4e0, '?getFaceCorners@Extents@RBX@@QBEXW4NormalId@2@AAVVector3@G3D@@111@Z'),
        (0x60f750, '?separatedByMoreThan@Extents@RBX@@QBE_NABV12@M@Z'),
        (0x60f7b0, '?faceCenter@Extents@RBX@@QBE?AVVector3@G3D@@W4NormalId@2@@Z'),
        (0x60f820, '?containedByFrustum@Extents@RBX@@QBE_NABVFrustum@GCamera@G3D@@@Z'),
        (0x60f8e0, '?vv@Extents@RBX@@SA?AV12@ABVVector3@G3D@@0@Z'),
        (0x60fc20, '?toWorldSpace@Extents@RBX@@QAE?AV12@ABVCoordinateFrame@G3D@@@Z'),
        (0x60fe40, '?getPlane@Extents@RBX@@QBE?AVPlane@G3D@@W4NormalId@2@@Z'),
    ],
    'drag': [
        (0x60fea0, '?toGrid@Dragger@RBX@@SA?AVVector3@G3D@@ABV34@@Z'),
        (0x610130, '?intersectingWorldOrOthers@Dragger@RBX@@'),
        (0x610270, '?movePrimitivesDelta@Dragger@RBX@@'),
        (0x610310, '?searchUpFine@Dragger@RBX@@'),
        (0x6103a0, '?searchDownFine@Dragger@RBX@@'),
        (0x610440, '?searchUpGross@Dragger@RBX@@'),
        (0x6104e0, '?searchDownGross@Dragger@RBX@@'),
        (0x610830, '?safeMoveYDrop@Dragger@RBX@@'),
        (0x610930, '?safeMoveNoDrop@Dragger@RBX@@'),
    ],
}
NON_EXACT_ROWS = [
    (0x60f9b0, '?express@Extents@RBX@@QAE?AV12@ABVCoordinateFrame@G3D@@0@Z', 'ext',
     '617 / 617 B: only the row-1 sum of the inlined G3D pointToWorldSpace is associated differently '
     '((m10*x + m11*y) + m12*z in the original, (m11*y + m12*z) + m10*x here) under /fp:fast. Tried: '
     'pointToObjectSpace(pointToWorldSpace(getCorner(i))) (this source), a named world local (617, same pair), '
     'a named corner local (617), (world - translation) * rotation (635), rotation.transpose() * (...) (662), '
     'rotation * corner + translation (641). The matched server analog needs a private pointToWorldSpace with row-1 '
     'named locals; the shared G3D header is not changed.'),
]
REJECTED = {
    'AppUnit609_2008Extents.cpp without /fp:fast': 'separatedByMoreThan 138/93, faceCenter 135/106, vv 93/203, '
                                                   'express 1046/617, toWorldSpace 868/534',
    'containedByFrustum with `const G3D::Plane& plane = frustum.faceArray[i].plane` or a FrustumFace reference': (
        '187 B, lea operands swapped ([eax+ecx+0x10]) or `add eax, [esp+0x18]`; the getCArray() + i spelling is exact'),
    'containedByFrustum passing getCorner(j) directly / with the outer `if (size() > 0)`': (
        'sub esp,0xc frame / extra size compare (187 B, different code)'),
    'Dragger::intersectingWorldOrOthers without __declspec(noinline)': (
        'it is inlined into the four search loops (169/130, 187/148 x3); the original keeps every call out of line. '
        'Defining computeExtents(Array) in the unit (donor Primitive.h, trial only) does not prevent the inlining.'),
    'AppUnit609_2008Dragger.cpp without /fp:fast': 'safeMoveYDrop 257/251, safeMoveNoDrop 303/297',
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


def bind_value(raw, sections, symbols, definitions, bodies, name, body, target, address, own, record=True):
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
        elif symbol in SUPPORT:
            assert SUPPORT[symbol] == value, (name, symbol, hex(value), hex(SUPPORT[symbol]))
            sbody, srefs = bodies[symbol]
            starget, strefs = target_of(value)
            assert match.exact_match(starget, strefs, sbody, srefs), ('support body not exact', symbol, hex(value))
            support_out[symbol] = '%08x' % value
            how = 'support body exact at the bound address'
        elif symbol in EXTERNAL:
            assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
            how = 'external' + (' (evidence name)' if names.get(value, '') == symbol else '')
        elif LOCAL_STATIC.match(symbol) and symbol in LOCAL_STATIC_AT:
            assert LOCAL_STATIC_AT[symbol] == value, (name, symbol, hex(value), hex(LOCAL_STATIC_AT[symbol]))
            how = 'local static'
        else:
            UNBOUND.append("    %r: %#x,   # %s in %s" % (symbol, value, names.get(value, '')[:60], name[:60]))
            continue
        if record:
            prev = binding.setdefault(symbol, (value, name))
            assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
        verified[symbol] = '%s (%s)' % (hex(value), how)
    return verified, local


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
        verified, local = bind_value(raw, sections, symbols, definitions, bodies, name, body, target, address, own, record)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local)})
        result.append(entry)
    return result


resolved = {k: resolve(OBJ[k], rows) for k, rows in ROWS.items()}
own = {}
for rows in resolved.values():
    for address, name in rows:
        own.setdefault(name, address)
groups = {k: verify(k, rows, own) for k, rows in resolved.items()}
non_out = []
for address, key, which, why in NON_EXACT_ROWS:
    row = verify(which, resolve(OBJ[which], [(address, key)]), own, strict=False, record=False)[0]
    assert not row['exact'] or DISCOVER, ('non-exact row unexpectedly exact', row['address'])
    row.update({'exact': False, 'reason': why})
    non_out.append(row)

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
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if '00609a30' <= a < '00610bf0'}

UNIT_MAP = {
    'feature 00609a30..0060cad0': (
        'Feature / Hole / MotorFeature / VelocityMotor (native-classes/Feature.cpp, feature-working.json): getFaceId '
        '00609a30 .. MotorFeature::join 0060ca00 (209 B, ends 0060cad1). RTTI vtables Feature 00842be0, VelocityMotor '
        '00842cbc, MotorFeature 008435bc, Hole 008434d4; static initializers 007f7bc0..007f7c80. Uncounted here: the '
        'VelocityMotor rows pending on the JointInstance askSetParent/onAncestorChanged, signal connect(group), '
        'MotorJoint and KERNEL_STAGE proposals, the EnumPropDescriptor call_once rows (reflection.h proposal), '
        'computeLocalCoordinateFrame 00609da0 (PartInstance embedded Primitive) and getRenderCoord 0060a490 '
        '(register allocation), STL helpers 00609bb0/00609bd0 (ICF-shared _Tree helpers named by other types).'),
    'contact-manager 0060cae0..0060dd5f': (
        'BallBallContact() 0060cae0 (calls Contact() 00606c20) and the Ball/Block leaf virtuals 0060cb10..0060cc60 '
        '(world-shapes counts 0060cae0..0060cbc0), G3D::Array<Contact*> resize/append 0060cfd0/0060d0d0, '
        'BlockBlockContact() 0060d500 .. 0060d610 (leaves2008), ContactManager members intersectingOthers 0060d630 / '
        '0060dc10 / 0060dcd0, getHit 0060d6e0 / 0060db10, createContact 0060d770 (news 0x7c and calls 0060d500), '
        'onNewPair 0060d8b0, onPrimitiveGeometryTypeChanged 0060d8e0. Needs the 2008 Primitive / Contact layouts '
        '(body-primitive-contact lease); not built here.'),
    'mega-dragger 0060dd60..0060e96f': (
        '0060dd60 (tail call of DragUtilities::unJoinAndSetDragging 0060ee30), anyDragPartAlive 0060dd70, '
        'mousePartAlive 0060dde0 .. MegaDragger() 0060e630 / ~MegaDragger 0060e700 / finishDragging 0060e780, '
        'movePart 0060e840, CoordinateFrame::toObjectSpace 0060e8f0, 0060e920 (PartInstance::findParts 0059c640). '
        'axis-move-tool-lifetime-trial.json counts 0060dd70, 0060e200, 0060e840; tool/MegaDragger.h owner.'),
    'drag-utilities 0060e970..0060f3df': (
        'DragUtilities::hitObjectOrPlane 0060e970 .. getPrimitives 0060f3d0 (trial counts 0060ead0, 0060f340, '
        '0060f3d0).'),
    'extents 0060f3e0..0060fe95': (
        'Extents::closestFace 0060f3e0 (only caller 0066c3ec) .. getPlane 0060fe40 (ends 0060fe95); all nine '
        'out-of-line Extents members of the unit share the Math::inf local static 0097b890/0097b894. Built here.'),
    'dragger 0060fea0..00610bee': (
        'Dragger::toGrid 0060fea0 (dragSnap static 00976348/guard 00976354) .. safeRotate 00610a60 (ends 00610bee). '
        'Trial-counted: movePrimitives 0060fef0, computeExtents(vector) 0060ff80, movePrimitivesGoal 00610180, '
        'safePlaceAlongLine 00610580, safeMoveAlongLine 006106c0 (analog names applyMove / transformMove / '
        'subdivideMove). Built here: toGrid, intersectingWorldOrOthers, movePrimitivesDelta, the four searches, '
        'safeMoveYDrop, safeMoveNoDrop. Not built: computeExtents(Array) 00610070 and safeRotate 00610a60 (2008 '
        'Primitive geometry +0x9c / PartInstance coordinate frame).'),
    'lua 00610bf0..': 'Lua 5.1.1 lauxlib (luaL_where 00610bf0, luaL_error 00610c60, ...): library, not recovered.',
}

receipt = {
    'class': 'RBX Extents and Dragger units of the application range 00609a30..00610bf0 (2008-06), inactive',
    'compiler': 'VS2008 RTM 21022',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)): nb.sha(p) for p in list(SOURCES.values()) + [Path(__file__).resolve(),
                R / 'native-headers/util/Extents.h']},
    'objects': {k: nb.sha(v) for k, v in OBJ.items()},
    'unit_map': UNIT_MAP,
    'range_rows_counted_by_other_receipts': range_counted,
    'rows': groups,
    'support_rows': support_out,
    'not_exact': non_out,
    'rejected': REJECTED,
    'exact_function_rows': exact_rows,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit609-2008: %d counted exact rows (%s); %d not exact, %d support rows'
      % (len(exact_rows), ' '.join(exact_rows), len(non_out), len(support_out)))
