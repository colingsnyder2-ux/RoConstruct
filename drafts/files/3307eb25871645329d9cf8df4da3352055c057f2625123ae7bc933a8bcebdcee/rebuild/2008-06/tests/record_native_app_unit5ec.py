"""Verify the inactive 2008-06 native rows of the application range 005ec000..005f0000, and record the unit map of the
range (boundary evidence in the receipt's `unit_map`; rows counted by other receipts are written there as
'ADDR counted by RECEIPT' text, never as quoted bare addresses).

Unit map summary (details in UNIT_MAP below):
  * Sky.cpp tail: 005ec170 (an ICF-folded 5-byte return-argument body; counted by stats-service-working.json).
  * util/NormalId.cpp 005ec180..005ec9ef: built here from native-classes/AppUnit5ECNormalId.cpp against the donor
    util/NormalId.h (read-only) and the new native-headers/AppUnit5EC/NormalIdVector.h (a new path: it shadows no
    donor header). The app-unit5e8 map put 005ec9f0..005ecbaf into NormalId.cpp; those rows are Surfaces.cpp.
  * v8datamodel/Surfaces.cpp 005ec9f0..005ef3ff: Surfaces members, then the per-face property descriptor templates.
    Built here from native-classes/AppUnit5ECSurfaces.cpp against the read-only native v8datamodel/Surfaces.h:
    Surfaces(PartInstance*) 005ecbb0 and isStandardPart 005ecc50.
  * v8datamodel/FaceInstance.cpp 005ef400..005ef79f (most rows counted by app-unit5e8-2008 / face-instance-lifetime).
  * the unattributed G3D TextInput user 005ef7a0.. (continues past 005f0000).

Builds: document-swap flags, VS2008 RTM 21022 (normalid: no extra flags; surfaces: native-headers/part-embedded
first, as for the committed Surface rows of app-unit5f0-2008).
Every counted row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the
address the original instruction uses and verified: imports by DLL export name, constants by bytes, own symbols by
the row proven here, externals by the explicit EXTERNAL map (evidence name or call-site identification), and
function-local statics and their guards by one address per symbol. A row is counted only when no other receipt
counts it. Writes work/2008-06/shared-layouts/app-unit5ec-working.json.
Set NATIVE_APP_UNIT5EC_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
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
OUT = nb.OUT / 'app-unit5ec'
OUT.mkdir(parents=True, exist_ok=True)
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT5EC_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit5ec-working.json'
LO, HI = 0x5ec000, 0x5f0000
SOURCES = {
    'normalid': R / 'native-classes/AppUnit5ECNormalId.cpp',
    'surfaces': R / 'native-classes/AppUnit5ECSurfaces.cpp',
}
NORMALID_H = R / 'native-headers/AppUnit5EC/NormalIdVector.h'
PART_EMBEDDED = R / 'native-headers/part-embedded'


def build(name, src, extra=(), first=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + ['/I' + str(p) for p in first] + flags[i:] + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


OBJ, FLAGS = {}, {}
OBJ['normalid'], FLAGS['normalid'] = build('NativeAppUnit5EC_normalid', SOURCES['normalid'])
OBJ['surfaces'], FLAGS['surfaces'] = build('NativeAppUnit5EC_surfaces', SOURCES['surfaces'], [], [PART_EMBEDDED])

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}

# ---- externals: address the original instruction uses -------------------------------------------------------------
EXTERNAL = {
    # evidence names
    '??0Surface@RBX@@QAE@PAVPartInstance@1@W4NormalId@1@@Z': 0x5f1270,          # 005ecbbb.. (six calls, ret 8)
    '?getSurfaceType@Surface@RBX@@QBE?AW4SurfaceType@2@XZ': 0x5f1290,           # 005ecc56.. (five calls)
    # G3D 6.09 out-of-line library bodies (call-site identification; same bindings as app-unit5dc / 588 / 5b0 /
    # 564 / 57c and appearance)
    '?getColumn@Matrix3@G3D@@QBE?AVVector3@2@H@Z': 0x513240,                    # 005ec31e (push 2)
    '??0Matrix3@G3D@@QAE@MMMMMMMMM@Z': 0x513b70,                                # 005ec6e0 body (nine floats)
    '?identity@Matrix3@G3D@@SAABV12@XZ': 0x513e20,                              # 005ec800 default branch
}
# function-local statics (one address per symbol): the G3D header-inline Vector3::unitX/unitY/unitZ/zero() statics
# and this unit's own normalIdToVector3 / normalIdToMatrix3 statics and guards
LOCAL_STATIC_AT = {
    '?v@?1??unitX@Vector3@G3D@@SAABV23@XZ@4V23@A': 0x9737f4, '??_B?1??unitX@Vector3@G3D@@SAABV12@XZ@51': 0x973800,
    '?v@?1??unitY@Vector3@G3D@@SAABV23@XZ@4V23@A': 0x972898, '??_B?1??unitY@Vector3@G3D@@SAABV12@XZ@51': 0x9728a4,
    '?v@?1??unitZ@Vector3@G3D@@SAABV23@XZ@4V23@A': 0x96ef9c, '??_B?1??unitZ@Vector3@G3D@@SAABV12@XZ@51': 0x96efa8,
    '?v@?1??zero@Vector3@G3D@@SAABV23@XZ@4V23@A': 0x96f044, '??_B?1??zero@Vector3@G3D@@SAABV12@XZ@51': 0x96f050,
    '?$S1@?4??normalIdToVector3@RBX@@YAABVVector3@G3D@@W4NormalId@2@@Z@4IA': 0x97ae48,
    '?x@?4??normalIdToVector3@RBX@@YAABVVector3@G3D@@W4NormalId@2@@Z@4V34@B': 0x97ae3c,
    '?y@?5??normalIdToVector3@RBX@@YAABVVector3@G3D@@W4NormalId@2@@Z@4V34@B': 0x97ae30,
    '?z@?6??normalIdToVector3@RBX@@YAABVVector3@G3D@@W4NormalId@2@@Z@4V34@B': 0x97ae24,
    '?xn@?7??normalIdToVector3@RBX@@YAABVVector3@G3D@@W4NormalId@2@@Z@4V34@B': 0x97ae18,
    '?yn@?8??normalIdToVector3@RBX@@YAABVVector3@G3D@@W4NormalId@2@@Z@4V34@B': 0x97ae0c,
    '?zn@?9??normalIdToVector3@RBX@@YAABVVector3@G3D@@W4NormalId@2@@Z@4V34@B': 0x97ae00,
    '?$S2@?4??normalIdToMatrix3@RBX@@YAABVMatrix3@G3D@@W4NormalId@2@@Z@4IA': 0x97af24,
    '?x@?4??normalIdToMatrix3@RBX@@YAABVMatrix3@G3D@@W4NormalId@2@@Z@4V34@B': 0x97af00,
    '?y@?5??normalIdToMatrix3@RBX@@YAABVMatrix3@G3D@@W4NormalId@2@@Z@4V34@B': 0x97aedc,
    '?z@?6??normalIdToMatrix3@RBX@@YAABVMatrix3@G3D@@W4NormalId@2@@Z@4V34@B': 0x97aeb8,
    '?xn@?7??normalIdToMatrix3@RBX@@YAABVMatrix3@G3D@@W4NormalId@2@@Z@4V34@B': 0x97ae94,
    '?yn@?8??normalIdToMatrix3@RBX@@YAABVMatrix3@G3D@@W4NormalId@2@@Z@4V34@B': 0x97ae70,
    '?zn@?9??normalIdToMatrix3@RBX@@YAABVMatrix3@G3D@@W4NormalId@2@@Z@4V34@B': 0x97ae4c,
}
UNBOUND = []
binding = {}

# (address, symbol or unique prefix): one entry per counted address
ROWS = {
    'normalid': [
        (0x005ec180, '?normalIdOpposite@RBX@@YA?AW4NormalId@1@W421@@Z'),
        (0x005ec1a0, '??$uvwToObject@$0A@@RBX@@YA?AVVector3@G3D@@ABV12@@Z'),
        (0x005ec1c0, '??$uvwToObject@$00@RBX@@YA?AVVector3@G3D@@ABV12@@Z'),
        (0x005ec1e0, '??$uvwToObject@$02@RBX@@YA?AVVector3@G3D@@ABV12@@Z'),
        (0x005ec200, '??$uvwToObject@$03@RBX@@YA?AVVector3@G3D@@ABV12@@Z'),
        (0x005ec220, '??$uvwToObject@$04@RBX@@YA?AVVector3@G3D@@ABV12@@Z'),
        (0x005ec240, '?normalIdToVector3Internal@RBX@@'),
        (0x005ec290, '?Vector3ToNormalId@RBX@@'),
        (0x005ec310, '?Matrix3ToNormalId@RBX@@'),
        (0x005ec330, '?uvwToObject@RBX@@YA?AVVector3@G3D@@ABV23@W4NormalId@1@@Z'),
        (0x005ec450, '?objectToUvw@RBX@@'),
        (0x005ec570, '?normalIdToVector3@RBX@@'),
        (0x005ec6e0, '?normalIdToMatrix3Internal@RBX@@'),
        (0x005ec800, '?normalIdToMatrix3@RBX@@'),
        (0x005ec9d0, '?mapToUvw_Legacy@RBX@@'),
    ],
    'surfaces': [
        (0x005ecbb0, '??0Surfaces@RBX@@QAE@PAVPartInstance@1@@Z'),
        (0x005ecc50, '?isStandardPart@Surfaces@RBX@@QBE?B_NXZ'),
    ],
}
REJECTED = {}


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

# ---- layout evidence checked against the target bytes ---------------------------------------------------------------
# Surfaces(PartInstance*) 005ecbb0: six Surface(part, id) calls at this+0/+8/+0x10/+0x18/+0x20/+0x28 with ids
# 1 / 4 / 3 / 0 / 5 / 2 (Top NORM_Y, Bottom NORM_Y_NEG, Left NORM_X_NEG, Right NORM_X, Front NORM_Z_NEG, Back NORM_Z),
# i.e. the member order of the native Surfaces.h; ret 4.
ctor = original.data(0x5ecbb0, 78)
assert ctor[6:8] == bytes.fromhex('6a01') and ctor[16:18] == bytes.fromhex('6a04') and ctor[19:22] == bytes.fromhex('8d4e08'), ctor.hex()
for off, disp, ident in [(0x1b, 0x10, 3), (0x26, 0x18, 0), (0x31, 0x20, 5), (0x3c, 0x28, 2)]:
    assert ctor[off:off + 2] == bytes([0x6a, ident]) and ctor[off + 3:off + 6] == bytes([0x8d, 0x4e, disp]), (off, ctor.hex())
assert ctor[-3:] == bytes.fromhex('c20400'), ctor.hex()
# Surface is 8 bytes: { PartInstance* +0, NormalId +4 } (ctor 005f1270 stores both, ret 8)
s_ctor = original.data(0x5f1270, 18)
assert s_ctor[10:12] == bytes.fromhex('8908') and s_ctor[12:15] == bytes.fromhex('895004'), s_ctor.hex()


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
    ('Sky.cpp tail', 0x5ec000, 0x5ec180),
    ('util/NormalId.cpp', 0x5ec180, 0x5ec9f0),
    ('v8datamodel/Surfaces.cpp', 0x5ec9f0, 0x5ef400),
    ('v8datamodel/FaceInstance.cpp', 0x5ef400, 0x5ef7a0),
    ('unattributed G3D TextInput user', 0x5ef7a0, 0x5f0000),
]
unit_rows = {}
for r in RANGE_ROWS:
    a = int(r['addr'], 16)
    unit = [u for u, lo, hi in UNITS if lo <= a < hi][0]
    unit_rows.setdefault(unit, []).append(r)

UNIT_MAP = {
    'Sky.cpp tail ..005ec17f': (
        'The range starts inside v8datamodel/Sky.cpp (effects owner, native v8datamodel/Sky.h; the unit starts at '
        '005eaef0, see app-unit5e8-2008). Its only row in this range is the 5-byte ICF-folded `mov eax,[esp+4]; ret` '
        'body at 005ec170, counted by stats-service-working.json. Not built here.'),
    'util/NormalId.cpp 005ec180..005ec9ef': (
        'util/NormalId.cpp: normalIdOpposite 005ec180 ((id + 3) % 6), the uvwToObject<id> specializations NORM_X '
        '005ec1a0, NORM_Y 005ec1c0, NORM_X_NEG 005ec1e0, NORM_Y_NEG 005ec200, NORM_Z_NEG 005ec220 (the NORM_Z copy is '
        'ICF-folded at 006784d0, outside the range; ViewNew binds all six as externals), normalIdToVector3Internal '
        '005ec240 (zero, then +-1.0f at component id % 3; -1.0f constant 0081c3b8), Vector3ToNormalId 005ec290, '
        'Matrix3ToNormalId 005ec310 (G3D Matrix3::getColumn(2) 00513240), uvwToObject(v, id) 005ec330 (six-way jump '
        'table 005ec430, default Vector3::unitX() static 009737f4 / guard 00973800), objectToUvw 005ec450, '
        'normalIdToVector3 005ec570 (six function statics 0097ae00..0097ae3c, guard 0097ae48, default '
        'Vector3::zero() 0096f044), normalIdToMatrix3Internal 005ec6e0 (unitX/unitY/unitZ statics, Matrix3(9 floats) '
        '00513b70), normalIdToMatrix3 005ec800 (six Matrix3 statics 0097ae4c..0097af00, guard 0097af24, EH frame, '
        'default Matrix3::identity() 00513e20) and mapToUvw_Legacy 005ec9d0. The body shapes follow the later '
        'openrbx-client NormalId.cpp; declarations are the donor util/NormalId.h (read-only) plus '
        'native-headers/AppUnit5EC/NormalIdVector.h for normalIdToVector3Internal. Built here: all 15 rows counted.'),
    'v8datamodel/Surfaces.cpp 005ec9f0..005ef3ff': (
        'v8datamodel/Surfaces.cpp (native v8datamodel/Surfaces.h, read-only). The app-unit5e8-2008 map ended '
        'NormalId.cpp at 005ecbaf; the rows 005ec9f0..005ecbaf belong here: Surfaces::isSurfaceDescriptor 005ec9f0 '
        '(compares against the six SurfaceType descriptor statics 0097b348 / 0097b1f0 / 0097b260 / 0097b3f4 / '
        '0097b1d0 / 0097b128), getSurfaceType 005eca30, getSurfaceInput 005eca90, getParamA 005ecaf0, getParamB '
        '005ecb50 (six-way switches returning the per-face descriptor statics; app-unit5f0-2008 binds the four as '
        'externals of the Surface setters). Surfaces(PartInstance*) 005ecbb0 (layout: Top +0 NORM_Y, Bottom +8, '
        'Left +0x10, Right +0x18, Front +0x20, Back +0x28; Surface ctor 005f1270), operator[] 005ecc00 (counted by '
        'surfaces-lookup-trial.json), isStandardPart 005ecc50 (Bottom INLET, the other four sides except Top '
        'NO_SURFACE), the ICF-folded std::map iterator operator== 005ecca0 (Roblox-instantiated STL shared with '
        'other units; not built). Then the surface reflection instantiations: the EnumDesc call_once holders for '
        'SurfaceType and Controller::InputType (005eccd0 / 005ecce0 / 005eccf0 / 005ed110 / 005ed140 / 005ed580 / '
        '005ed5a0, EnumDesc getters 005ed5c0 / 005ed630, call_once thunks 005ed620 / 005ed690, singleton 005ed6a0, '
        'convertToValue 005ed170 / 005ed300 / 005ed3f0 / 005ed770 / 005ed800), the SurfaceGetSet<face> get/set '
        'pairs 005ecd60..005ed0e0 (PartInstance::getSurfaces 00598de0), SurfaceEnumPropDescriptor<face, '
        'SurfaceType / InputType> members 005ed830..005ef3d0 (incl. the "Unable to cast %s to %s" setStringValue '
        'bodies 005eef20 / 005ef020) and SurfaceDescriptor<face> 005eecc0..005ef180 ("SurfaceDescriptor::set/get '
        'not implemented" 005eed50 / 005eee80). Built here: Surfaces(PartInstance*) and isStandardPart (2 counted '
        'rows). Not built: isSurfaceDescriptor and the four descriptor getters need the 2008 per-face descriptor '
        'statics (SurfaceEnumPropDescriptor / SurfacePropDescriptor templates on the 2008 reflection core), and the '
        'descriptor templates need the reflection-core EnumDesc call_once proposal (see proposals).'),
    'v8datamodel/FaceInstance.cpp 005ef400..005ef79f': (
        'v8datamodel/FaceInstance.cpp (native v8datamodel/FaceInstance.h, read-only): render3dSelect 005ef400 '
        '(IRenderable override; this is the IRenderable base at FaceInstance +0x130: dynamic_cast<PartInstance*> of '
        'the parent read at this-0x2c via __RTDynamicCast, then 005149b0 / PartInstance 0059aa90 / Adorn 00677630 '
        'with the face at this+0x10, i.e. FaceInstance +0x140), the boost::function functor allocation 005ef470, EnumDesc<NormalId> getter 005ef4c0 and '
        'call_once thunk 005ef520, FaceInstance() 005ef530, the ??_E thunks 005ef5f0..005ef660, ??_G 005ef670, '
        'EnumPropDescriptor<FaceInstance, NormalId>() 005ef690 and setFace 005ef770. Counted elsewhere (see '
        'counted_elsewhere). Not built here: render3dSelect is not declared by the native FaceInstance.h '
        '(proposal), and 005ef470 / 005ef4c0 / 005ef520 / 005ef690 need the EnumDesc call_once proposal.'),
    'unattributed G3D TextInput user 005ef7a0..': (
        '005ef7a0 compares two files with _stat64i32 and _unlink()s the stale one; 005ef840 (6698 B, ends at '
        '005f126a) is its only caller and is called from 004eb56c / 004eb71e; it drives G3D TextInput token reads. '
        'No RTTI, string or evidence name ties it to an RBX class (as mapped by app-unit5e8-2008). Not recovered.'),
}
unit_map = []
for u, lo, hi in UNITS:
    key = [k for k in UNIT_MAP if k.startswith(u)][0]
    rows = unit_rows.get(u, [])
    unit_map.append({'unit': key, 'rows': len(rows), 'bytes': sum(r['size'] for r in rows),
                     'counted_elsewhere': ['%s counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()
                                           if lo <= int(a, 16) < hi],
                     'counted_here': len([a for a in exact_rows if lo <= int(a, 16) < hi]),
                     'library': False,
                     'evidence': UNIT_MAP[key]})
assert sum(u['rows'] for u in unit_map) == len(RANGE_ROWS)

PROPOSALS = [
    'Owner of native-headers/reflection/enumconverter.h (reflection core; not edited): repeats the app-unit5f0-2008 '
    'proposal. The 2008 EnumDesc<Enum>::singleton() is boost::call_once(&<thunk>, <static once_flag>) followed by '
    'an out-of-line function-static instance getter: SurfaceType call_once thunk 005ed620 / getter 005ed5c0, '
    'Controller::InputType 005ed690 / 005ed630, NormalId 005ef520 / 005ef4c0; convertToValue(const char*) is out '
    'of line (005ed800). With it the SurfaceEnumPropDescriptor / SurfaceDescriptor instantiations 005eccd0..005ef3d0 '
    'and the FaceInstance prop_Face descriptor rows become candidates.',
    'Owner of native-headers/v8datamodel/FaceInstance.h: declare the IRenderable override '
    '`virtual void render3dSelect(Adorn* adorn, SelectState selectState);` (005ef400: ret 8, two stack arguments; '
    'this is the IRenderable base at FaceInstance +0x130, the parent read at this-0x2c, the face at this+0x10, i.e. '
    'FaceInstance +0x140), so '
    'that row can be built. The exact IRenderable signature must come from the native util/IRenderable.h owner.',
    'Owner of native-headers/v8datamodel/Surfaces.h (FYI): its layout and member order are proven by Surfaces() '
    '005ecbb0 (Top +0 NORM_Y, Bottom +8 NORM_Y_NEG, Left +0x10 NORM_X_NEG, Right +0x18 NORM_X, Front +0x20 '
    'NORM_Z_NEG, Back +0x28 NORM_Z); Surfaces(PartInstance*) and isStandardPart are now counted by '
    'app-unit5ec-working.json. isSurfaceDescriptor / getSurfaceType / getSurfaceInput / getParamA / getParamB need '
    'the 2008 per-face descriptor statics (24 objects 0097b128..0097b468), which need the descriptor templates.',
    'BOUNDS / map correction (no bounds.json change): app-unit5e8-2008 lists 005ec9f0..005ecbaf under NormalId.cpp; '
    'by their bodies (descriptor statics, Surfaces analog names) they are Surfaces.cpp rows.',
]

receipt = {
    'scope': ('Inactive 2008-06 native recovery of the application range 005ec000..005f0000: unit map of every row, '
              'util/NormalId.cpp against the donor util/NormalId.h plus a new AppUnit5EC header, and the Surfaces '
              'constructor / isStandardPart against the native v8datamodel/Surfaces.h. No runtime, link or class-swap '
              'claim.'),
    'exact_function_rows': exact_rows,
    'exact_function_row_count': len(exact_rows),
    'range_rows': len(RANGE_ROWS),
    'rows': groups,
    'unit_map': unit_map,
    'proposals': PROPOSALS,
    'rejected': REJECTED,
    'flags': FLAGS,
    'sources': {k: nb.sha(p) for k, p in list(SOURCES.items()) + [('normalid_header', NORMALID_H)]},
    'headers_read_only': ['tools/rbxgs/Client/App/include/util/NormalId.h (donor)',
                          'native-headers/v8datamodel/Surfaces.h', 'native-headers/v8datamodel/Surface.h',
                          'native-headers/part-embedded/v8datamodel/PartInstance.h'],
    'new_headers': ['native-headers/AppUnit5EC/NormalIdVector.h (new path; shadows no donor header)'],
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit5ec: %d counted rows (%d range rows)' % (len(exact_rows), len(RANGE_ROWS)))
