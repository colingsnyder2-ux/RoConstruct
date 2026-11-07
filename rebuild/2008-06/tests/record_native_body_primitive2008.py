"""Verify the inactive 2008-06 native RBX::Body, RBX::Cofm and RBX::Point rows (Body unit 00613e80..00614bc7, Cofm unit
0065fef0..0066017c, Point unit 0064dc70..0064dde3).

Layout: native-headers/v8kernel/Body2008.h (a non-colliding path: the donor v8kernel/Body.h is reached by every engine
unit). Body 0xdc (new 0xdc in the world body initializer 00614b40 and Primitive() 005e8770), Cofm 0x3c (new 0x3c in
onChildAdded 006147f0); every field offset is checked by a generated layout unit (out/native-layouts/
NativeBodyPrimitive2008Layout.cpp, friend struct NativeBodyPrimitive2008Layout).

Builds (document-swap flags, VS2008 RTM 21022, /fp:fast /U_RELEASEASSERT: without /fp:fast getBranchMass is 37 B and
kineticEnergy 274 B):
  * native-classes/BodyPrimitive2008Body.cpp: Body rows that need only the Body / Cofm layout.
  * native-classes/BodyPrimitive2008Cofm.cpp: Cofm(Body*), getMass, updateIfDirty, getCofmInBody, getMoment.
  * native-classes/BodyPrimitive2008Point.cpp: Point::forceToBody, step, setWorldPos against native-headers/v8kernel/
    Point2008.h (Point(Body*) 0064dc00 / ??_G 0064dc50 are counted by leaves2008-working.json).
SimBody 0xb4 (new 0xb4 in Body() 006149c0 / setParent 006148b0, constructor 00658ae0) and the 2008 Point / GeoPair
layouts (native-headers/v8kernel/Point2008.h, native-headers/v8world/GeoPair2008.h) are checked by the same unit.

Every counted row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified: imports by DLL export name, constants by bytes, own symbols by the row
proven here, the remaining externals by the explicit EXTERNAL / DATA maps (call sites read in the original
disassembly). A symbol binds to one address across all rows. The rows reference no vtable. A row is counted only when
it is not already counted by another receipt (top-level exact_function_rows, or exact_addresses /
exact_unique_addresses / exact method entries for older receipts).
Writes work/2008-06/shared-layouts/body-primitive2008-working.json.
Set NATIVE_BODY_PRIMITIVE_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
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
OUT = nb.OUT
OUT.mkdir(parents=True, exist_ok=True)
HEADER = R / 'native-headers/v8kernel/Body2008.h'
PRIM_HEADER = R / 'native-headers/v8world/Primitive2008.h'
POINT_HEADER = R / 'native-headers/v8kernel/Point2008.h'
GEOPAIR_HEADER = R / 'native-headers/v8world/GeoPair2008.h'
SOURCES = {
    'body': R / 'native-classes/BodyPrimitive2008Body.cpp',
    'cofm': R / 'native-classes/BodyPrimitive2008Cofm.cpp',
    'point': R / 'native-classes/BodyPrimitive2008Point.cpp',
}
UNIT = {'body': ['/fp:fast', '/U_RELEASEASSERT'], 'cofm': ['/fp:fast', '/U_RELEASEASSERT'],
        'point': ['/fp:fast', '/U_RELEASEASSERT']}
DISCOVER = bool(os.environ.get('NATIVE_BODY_PRIMITIVE_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/body-primitive2008-working.json'

# ---- generated layout unit (offset / size proof of every declared field) ----------------------------------------
LAYOUT = OUT / 'NativeBodyPrimitive2008Layout.cpp'
FIELDS = {
    'Body': [('kernelIndex', 0x0), ('leafBodyIndex', 0x4), ('numConnectors', 0x8), ('unreadFlag', 0xc), ('root', 0x10),
             ('parent', 0x14), ('index', 0x18), ('children', 0x1c), ('cofm', 0x28), ('simBody', 0x2c),
             ('canThrottle', 0x30), ('link', 0x34), ('meInParent', 0x38), ('moment', 0x68), ('mass', 0x8c),
             ('stateIndex', 0x90), ('pv', 0x94)],
    'Cofm': [('body', 0x0), ('dirty', 0x4), ('cofmInBody', 0x8), ('mass', 0x14), ('moment', 0x18)],
    'SimBody': [('body', 0x0), ('dt', 0x4), ('dirty', 0x8), ('pv', 0xc), ('qOrientation', 0x54), ('angMomentum', 0x64),
                ('momentRecip', 0x70), ('massRecip', 0x7c), ('constantForceY', 0x80), ('force', 0x84),
                ('torque', 0x90), ('impulse', 0x9c), ('rotImpulse', 0xa8)],
    'Point': [('kernelIndex', 0x4), ('numOwners', 0x8), ('body', 0xc), ('localPos', 0x10), ('worldPos', 0x1c),
              ('force', 0x28)],
    'GeoPair': [('geoPairType', 0x0), ('offset0', 0x4), ('offset1', 0x8), ('body0', 0xc), ('body1', 0x10),
                ('edgeLength0', 0x14), ('pairData', 0x18)],
}
SIZES = {'Body': 0xdc, 'Cofm': 0x3c, 'SimBody': 0xb4, 'Point': 0x34, 'GeoPair': 0x24}
_lines = ['#include <stddef.h>', '#include "v8kernel/Body2008.h"', '#include "v8world/Primitive2008.h"',
          '#include "v8kernel/Point2008.h"', '#include "v8world/GeoPair2008.h"', '',
          'struct NativeBodyPrimitive2008Layout', '{', '\tstatic void check()', '\t{']
for cls, fields in FIELDS.items():
    for field, offset in fields:
        _lines.append('\t\ttypedef char %s_%s[offsetof(RBX::%s, %s) == 0x%x ? 1 : -1];' % (cls, field, cls, field, offset))
    _lines.append('\t\ttypedef char %s_size[sizeof(RBX::%s) == 0x%x ? 1 : -1];' % (cls, cls, SIZES[cls]))
_lines += ['\t}', '};', '', 'void nativeBodyPrimitive2008Layout()', '{', '\tNativeBodyPrimitive2008Layout::check();', '}', '']
LAYOUT.write_text('\n'.join(_lines))


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + [x for x in extra if x.startswith('/I')] + flags[i:] + [x for x in extra if not x.startswith('/I')]
    flags += ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


OBJ, FLAGS = {}, {}
OBJ['layout'], FLAGS['layout'] = build('NativeBodyPrimitive2008Layout', LAYOUT, ['/U_RELEASEASSERT'])
for key, src in SOURCES.items():
    OBJ[key], FLAGS[key] = build('NativeBodyPrimitive2008_' + key, src, UNIT[key])

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}


def norm(symbol):
    return symbol.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


# ---- externals: address the original instruction uses, read at the call sites listed ----------------
EXTERNAL = {
    '??2@YAPAXI@Z': 0x6a0920, '??3@YAXPAX@Z': 0x6a067a,
    '?updatePV@Body@RBX@@ABEXXZ': 0x599360,                                            # 00614407 (evidence name)
    '?setPv@Body@RBX@@QAEXABVPV@2@@Z': 0x613fb0,                                       # 00614472 (evidence name)
    '?setParent@Body@RBX@@QAEXPAV12@@Z': 0x6148b0,                                     # ~Body 00614aeb
    '??0Body@RBX@@QAE@XZ': 0x6149c0,                                                   # initWorldBody 00614b74
    '??1SimBody@RBX@@QAE@XZ': 0x47d410,                # ~Body 00614af9: folded empty destructor body (`ret`)
    '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330,                                      # getWorldBody 00614bba
    '??0Matrix3@G3D@@QAE@ABV01@@Z': 0x513220,          # copy constructor, ICF-folded with operator= (evidence name)
    '??4Matrix3@G3D@@QAEAAV01@ABV01@@Z': 0x513220,
    '?momentToWorldSpace@Math@RBX@@SA?AVMatrix3@G3D@@ABV34@0@Z': 0x5ddb70,             # 00614593 (evidence name)
    '?momentToObjectSpace@Math@RBX@@SA?AVMatrix3@G3D@@ABV34@0@Z': 0x5ddb30,            # 0066013c (evidence name)
    '?getIWorldAtPoint@Math@RBX@@SA?AVMatrix3@G3D@@ABVVector3@4@0ABV34@M@Z': 0x5dda70, # 006145c0 (evidence name)
    '?pointToWorldSpace@CoordinateFrame@G3D@@QBE?AVVector3@2@ABV32@@Z': 0x4766a0,      # 006144a5 (evidence name)
    '??KVector3@G3D@@QBE?AV01@M@Z': 0x518740,                                          # Vector3::operator/ 0066002a
    '??HMatrix3@G3D@@QBE?AV01@ABV01@@Z': 0x5132f0,                                     # Matrix3::operator+ 00660108
    '?alignedFree@System@G3D@@SAXPAX@Z': 0x507d20,      # inline ~Array<Body*> in ~Body 00614b16
    '??0SimBody@RBX@@QAE@PAVBody@1@@Z': 0x658ae0,                                      # Body() 00614a8a, setParent 0061493d
    '?update@SimBody@RBX@@AAEXXZ': 0x658d20,                                           # resetAccumulators 00613e89
    '?step@SimBody@RBX@@QAEXXZ': 0x658fb0,                                             # Body::step 0061422d
    '?getOwnerPV@SimBody@RBX@@QAE?AVPV@2@XZ': 0x658ca0,                                # Body::step 00614248
    '??0CoordinateFrame@G3D@@QAE@XZ': 0x4782d0,                                        # Body() 00614a16 / 00614a5c
    '?zero@Matrix3@G3D@@SAABV12@XZ': 0x513e20,                                         # Body() 00614a1b
    '??9Matrix3@G3D@@QBE_NABV01@@Z': 0x5132d0,                                         # setMoment 0061411f
    '??0Cofm@RBX@@QAE@PAVBody@1@@Z': 0x65fef0,
    '?accumulateForce@SimBody@RBX@@QAEXABVVector3@G3D@@0@Z': 0x612fb0,               # Point::forceToBody 0064dc87
    '?append@?$Array@PAVBody@RBX@@@G3D@@QAEXABQAVBody@RBX@@@Z': 0x5fabc0,              # onChildAdded 0061484f (ICF-shared)
    '?resize@?$Array@PAVBody@RBX@@@G3D@@QAEXH_N@Z': 0x5fa770,                          # onChildRemoved 00614786 (ICF-shared)
}
DATA = {
    '?worldBody@Body@RBX@@0PAV12@A': 0x97bec4,           # initWorldBody 00614b79, getWorldBody 00614bbf
    '?p@?1??getNextStateIndex@Body@RBX@@SAHXZ@4HA': 0x95a898,   # function-local counter: getNextStateIndex 00613f20 and
                                                                 # its inline copies (Body() 00614a2b, step 00614295 ...)
    '?v@?1??zero@Vector3@G3D@@SAABV23@XZ@4V23@A': 0x96f044,   # G3D Vector3::zero() static (Velocity() 00614170; the
                                                             # SimBody ctor 00658ae0 uses the same 0096f044 / guard 0096f050)
    '_worldBodyFlag': 0x97bed8,                          # call_once flag pushed at 00614bb0 (file static)
}
FOLDED = {}
UNPROVEN = {}
ROWS = {
    'body': [
        (0x613e80, '?resetAccumulators@SimBody@RBX@@QAEXXZ'),
        (0x613ef0, '?calcRoot@Body@RBX@@AAEPAV12@XZ'),
        (0x613f00, '?getBranchMass@Body@RBX@@QBEMXZ'),
        (0x613f20, '?getNextStateIndex@Body@RBX@@SAHXZ'),
        (0x613f40, '?advanceStateIndex@Body@RBX@@QAEXXZ'),
        (0x613f70, '?makeCofmDirty@Body@RBX@@AAEXXZ'),
        (0x613fb0, '?setPv@Body@RBX@@QAEXABVPV@2@@Z'),
        (0x614040, '?setVelocity@Body@RBX@@QAEXABVVelocity@2@@Z'),
        (0x6140b0, '?setMass@Body@RBX@@QAEXM@Z'),
        (0x614110, '?setMoment@Body@RBX@@QAEXABVMatrix3@G3D@@@Z'),
        (0x614170, '??0Velocity@RBX@@QAE@XZ'),
        (0x614200, '?step@Body@RBX@@QAEX_N@Z'),
        (0x6142d0, '?setMeInParent@Body@RBX@@QAEXABVCoordinateFrame@G3D@@@Z'),
        (0x614380, '?setMeInParent@Body@RBX@@QAEXPAVLink@2@@Z'),
        (0x614400, '?setCoordinateFrame@Body@RBX@@QAEXABVCoordinateFrame@G3D@@@Z'),
        (0x614480, '?getBranchCofmPos@Body@RBX@@QBE?AVVector3@G3D@@XZ'),
        (0x6144e0, '?getBranchCofmCoordinateFrame@Body@RBX@@QBE?AVCoordinateFrame@G3D@@XZ'),
        (0x614530, '?resetRoot@Body@RBX@@AAEXPAV12@@Z'),
        (0x614560, '?getIWorldAtPoint@Body@RBX@@QBE?AVMatrix3@G3D@@ABVVector3@4@@Z'),
        (0x6145e0, '?getBranchIWorldAtPoint@Body@RBX@@QBE?AVMatrix3@G3D@@ABVVector3@4@@Z'),
        (0x614670, '?kineticEnergy@Body@RBX@@QBEMXZ'),
        (0x614760, '?onChildRemoved@Body@RBX@@AAEXPAV12@@Z'),
        (0x6147f0, '?onChildAdded@Body@RBX@@AAEXPAV12@@Z'),
        (0x6148b0, '?setParent@Body@RBX@@QAEXPAV12@@Z'),
        (0x6149c0, '??0Body@RBX@@QAE@XZ'),
        (0x614ac0, '??1Body@RBX@@QAE@XZ'),
        (0x614b40, '?initWorldBody@Body@RBX@@CAXXZ'),
        (0x614bb0, '?getWorldBody@Body@RBX@@SAPAV12@XZ'),
    ],
    'point': [
        (0x64dc70, '?forceToBody@Point@RBX@@QAEXXZ'),
        (0x64dc90, '?step@Point@RBX@@QAEXXZ'),
        (0x64dd40, '?setWorldPos@Point@RBX@@QAEXABVVector3@G3D@@@Z'),
    ],
    'cofm': [
        (0x65fef0, '??0Cofm@RBX@@QAE@PAVBody@1@@Z'),
        (0x65ff10, '?getMass@Cofm@RBX@@QBE?BMXZ'),
        (0x65ff20, '?updateIfDirty@Cofm@RBX@@ABEXXZ'),
        (0x660160, '?getCofmInBody@Cofm@RBX@@QBEABVVector3@G3D@@XZ'),
        (0x660170, '?getMoment@Cofm@RBX@@QBEABVMatrix3@G3D@@XZ'),
    ],
}
ALIASES = []
NON_EXACT_ROWS = []
BOUNDS_ROWS = []
PENDING_ROWS = []
PENDING_EXTERNAL = {}
UNBOUND = []
binding = {}

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


def bind_value(raw, sections, symbols, definitions, name, body, target, address, own, extra=None, record=True, limit=None):
    """Verify every relocation of `name` (body compared against target); returns {symbol: proof}, local EH set."""
    start, section = definitions[name]
    table = sections[section]
    code = raw[table[4] + start:]
    verified, local = {}, set()
    size = len(body) if limit is None else limit
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        offset -= start
        if not 0 <= offset < size:
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
        elif symbol.startswith('??_C@'):
            pos, at = definitions[symbol]
            literal = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
            assert original.data(value, len(literal)) == literal, (name, symbol, hex(value))
            how = 'literal %r' % literal[:-1].decode()
        elif symbol.startswith('??_R0') and symbol.endswith('@8'):
            rtti = original.string(value + 8)
            assert norm(rtti) == norm('.' + symbol[5:-2]), (name, symbol, hex(value), rtti)
            how = 'RTTI %s' % rtti
        elif symbol.startswith('__real@'):
            assert original.data(value, len(symbol[7:]) // 2) == bytes.fromhex(symbol[7:])[::-1], (name, symbol, hex(value))
            how = 'constant %s' % symbol[7:]
        elif symbol.startswith('??_7'):
            rtti, at = original.vtable_class(value)
            cls = symbol[4:symbol.index('@@6B') + 2]
            assert norm(rtti) == norm('.?AV' + cls), (name, symbol, hex(value), rtti)
            VTABLES.setdefault(symbol, value)
            how = 'vtable RTTI %s offset %#x' % (rtti, at)
        elif symbol.startswith('??_8'):
            pos, at = definitions[symbol]
            blob = raw[sections[at][4] + pos:sections[at][4] + pos + 8]
            assert original.data(value, 8) == blob, (name, symbol, hex(value), blob.hex())
            how = 'vbtable bytes %s' % blob.hex()
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
            how = 'external' + (' (evidence name)' if norm(names.get(value, '')) == norm(symbol) else '')
        elif symbol in UNPROVEN:
            assert UNPROVEN[symbol] == value, (name, symbol, hex(value))
            how = 'call target of a built, non-counted row'
        elif symbol.startswith('__TI'):
            # ThrowInfo -> CatchableTypeArray (+0xc) -> first CatchableType (+4) -> TypeDescriptor (+4) -> name
            d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
            rtti = original.string(d(d(d(value + 12) + 4) + 4) + 8)
            assert rtti == '.' + symbol[symbol.index('?'):], (name, symbol, hex(value), rtti)
            how = 'throw info, first catchable type %s' % rtti
        elif extra is not None and symbol in extra:
            assert extra[symbol] in (None, value), (name, symbol, hex(value))
            how = 'pending-build external'
        elif symbol.startswith('??_B?1??') or symbol.startswith('?$S') or '?$TSS' in symbol or symbol.startswith('?s@?1??'):
            how = 'local static'
        else:
            UNBOUND.append("    %r: %#x,   # %s in %s" % (symbol, value, names.get(value, '')[:60], name[:60]))
            continue
        if record:
            prev = binding.setdefault(symbol, (value, name))
            assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
        verified[symbol] = '%s (%s)' % (hex(value), how)
    return verified, local


VTABLES = {}


def verify(which, rows, own, strict=True, record=True, extra=None, limit=None):
    raw = Path(OBJ[which]).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    result = []
    for address, name in rows:
        body, refs = bodies[name]
        target, target_refs = target_of(address)
        if limit:
            exact = len(body) == limit and match.exact_match(target[:limit], [r for r in target_refs if r < limit], body, refs)
        else:
            exact = match.exact_match(target, target_refs, body, refs)
        entry = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target), 'exact': exact}
        if not exact:
            assert not strict or DISCOVER, (name, entry['address'], len(body), len(target))
            result.append(entry)
            continue
        verified, local = bind_value(raw, sections, symbols, definitions, name, body, target, address, own, extra, record, limit)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local),
                      'vtables': sorted(x for x in verified if x.startswith('??_7'))})
        result.append(entry)
    return result



# ---- rows ---------------------------------------------------------------------------------------------
resolved = {k: resolve(OBJ[k], rows) for k, rows in ROWS.items()}
own = {}
for rows in resolved.values():
    for address, name in rows:
        own.setdefault(name, address)
groups = {k: verify(k, rows, own) for k, rows in resolved.items()}

# Body::getBranchMass is header-inline: Cofm::updateIfDirty and getBranchIWorldAtPoint inline it; the out-of-line COMDAT
# (both objects emit it) is counted once, at 00613f00, from the Body object.

def vtable_slots(which, symbol):
    raw = Path(OBJ[which]).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    start, section = definitions[symbol]
    table = sections[section]
    slots = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if offset >= start:
            slots[(offset - start) // 4] = symbols[index][0]
    return [slots[i] for i in range(len(slots))]



vt_out = {}
bodies_by_obj = {k: {n: (b, r) for n, b, r in match.coff_functions(Path(OBJ[k]).read_bytes())} for k in SOURCES}
for symbol, address in sorted(VTABLES.items()):
    which = next(k for k in SOURCES if symbol in match._coff_data_index(Path(OBJ[k]).read_bytes())[2])
    entries = []
    for slot, fn in enumerate(vtable_slots(which, symbol)):
        value = struct.unpack('<I', original.data(address + 4 * slot, 4))[0]
        if fn in own:
            ok, how = own[fn] == value, 'own row'
        elif fn in bodies_by_obj[which]:
            body, refs = bodies_by_obj[which][fn]
            target, target_refs = target_of(value)
            ok, how = match.exact_match(target, target_refs, body, refs), 'body exact at the original slot target'
        elif fn in EXTERNAL:
            ok, how = EXTERNAL[fn] == value, 'external'
        else:
            ok, how = False, 'unbound'
        entries.append({'slot': slot, 'symbol': fn, 'original': '%08x' % value, 'ok': ok, 'how': how})
    vt_out[symbol] = {'address': '%08x' % address, 'ok': all(e['ok'] for e in entries), 'slots': entries}

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
vtable_unproven = []
for rows in groups.values():
    for r in rows:
        if r['exact']:
            bad = [v for v in r['vtables'] if not vt_out[v]['ok']]
            r['counted'] = not bad
            if bad:
                r['not_counted_reason'] = 'references vtables whose slots are not all proven: ' + ', '.join(bad)
                vtable_unproven.append(r['address'])
exact_rows = sorted({r['address'] for rows in groups.values() for r in rows if r['exact'] and r['counted']})
double = {a: elsewhere[a] for a in exact_rows if a in elsewhere}
assert not double, double

BLOCKED = {
    'Body::accumulateTorque 006060b0': 'out-of-line COMDAT of the header-inline Body::accumulateTorque emitted in the '
                       'Connector unit (callers 0062ec1a / 00666634 / 006676f2 in other units); no unit here calls it '
                       'out of line (RotateConnector::computeForce inlines it), so it is not emitted.',
    'SimBody unit 00658a30..0065925e': 'SimBody(Body*) 00658ae0, getOwnerPV 00658ca0, update 00658d20 and step 00658fb0 '
                       'are only declared (call targets of the Body rows); update / step need Body::getCofmOffset, '
                       'Quaternion(Matrix3) and the momentRecip helpers, not attempted.',
    'SimBody::accumulateForce 00612fb0': 'declared out of line (Point::forceToBody 0064dc87 calls it); its COMDAT is '
                       'emitted in another unit (00612fb0 precedes the GeoPair unit 00613060), not attempted.',
    'Primitive': 'v8world/Primitive2008.h declares only Primitive::onNewTouch 005e7530 and getFastFuzzyExtents 005e7a50 '
                 '(call evidence for the contact unit). The 0xfc Primitive layout (constructor 005e8770: vtable 0083f83c, '
                 'Guid +0x8, geometry +0x9c, body +0xa0, friction +0xb0, elasticity +0xb4, jointK ComputeProp '
                 '+0xe8..+0xf8) is not declared: +0x4..+0x98 and +0xa4..+0xe4 are not assigned to fields yet, and its '
                 'base IPipelined is declared only by the donor v8world/IPipelined.h, which includes the donor '
                 'v8kernel/Kernel.h -> KernelData.h -> Body.h and so cannot be included next to Body2008.h (C2011). A 2008 '
                 'Primitive needs a native IPipelined (and Kernel) declaration first.',
}
receipt = {
    'class': 'RBX::Body / RBX::Cofm / RBX::SimBody layout / RBX::Point (2008-06), inactive',
    'compiler': 'VS2008 RTM 21022',
    'flags': {k: v for k, v in FLAGS.items()},
    'sources': {str(p.relative_to(ROOT)): nb.sha(p) for p in list(SOURCES.values()) + [Path(__file__).resolve(), HEADER,
                PRIM_HEADER, POINT_HEADER, GEOPAIR_HEADER]},
    'generated_layout_unit': {str(LAYOUT.relative_to(ROOT)): nb.sha(LAYOUT)},
    'layout': {cls: {'size': '%#x' % SIZES[cls], 'fields': {f: '%#x' % o for f, o in fields}} for cls, fields in FIELDS.items()},
    'objects': {k: nb.sha(v) for k, v in OBJ.items()},
    'rows': groups,
    'vtables': vt_out,
    'exact_function_rows': exact_rows,
    'exact_but_vtable_unproven_rows': sorted(vtable_unproven),
    'rejected_variants': {
        '00614670 kineticEnergy': 'returning the expression directly (238 B, matrix-row products scheduled differently); '
                                  '(I*w).dot(w); `* 0.5f`; `* 0.5`; mass * linear.dot(linear); linear.squaredLength() '
                                  '(230 B); linear term first (244 B); named Vector3 / split float locals (238 / 242 B). '
                                  'Exact: a named float `calc` local, then return it.',
        'Body::getBranchMass out of line': 'Cofm::updateIfDirty 0065ff20 is 526 / 575 B when getBranchMass is a call; '
                                           'the original inlines it (header-inline definition).',
        '/fp:precise': 'getBranchMass 37 / 21 B, kineticEnergy 274 / 238 B, updateIfDirty 611 / 575 B.',
        'Body::nextStateIndex as a class static': 'the inline getNextStateIndex copies in setVelocity 00614040, step '
                                  '00614200 and Body() 006149c0 then keep the last float store before the counter load '
                                  '(same size, scheduling differs). Exact: the function-local `static int p` of the donor '
                                  'getNextStateIndex (0095a898); getNextStateIndex 00613f20 stays exact.',
        'calcRoot inline': 'setParent 006148b0 is 269 / 263 B when calcRoot is inlined one level; the original calls it '
                           '(00614958): `__declspec(noinline)` as in the donor declaration.',
        'VS2005 50727 for the Body unit': 'setVelocity 113 / 111 B (kineticEnergy is exact there too); kept on 21022.',
    },
    'blocked': BLOCKED,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS body-primitive2008: %d counted exact rows (%s); %d not exact; layout Body 0xdc / Cofm 0x3c / SimBody 0xb4 / '
      'Point 0x34 / GeoPair 0x24 checked'
      % (len(exact_rows), ' '.join(exact_rows), sum(1 for rows in groups.values() for r in rows if not r['exact'])))
