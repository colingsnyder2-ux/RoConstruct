"""Verify the inactive 2008-06 native rows of the application range 005e8000..005f4000, and record the unit map of the
range (boundary evidence in the receipt's `unit_map`; rows counted by other receipts are written there as text).

Unit map summary (details in UNIT_MAP below):
  * Primitive.cpp tail ..005e8ebf (Body/Primitive owner), PhysicsService.cpp 005e8ec0..005e914f (services owner).
  * World.cpp 005e9150..005eaeef: built here from native-classes/AppUnit5E8_2008World.cpp against the native
    engine-world v8world/World.h / ContactManager.h and v8world/JointStage2008.h (read-only).
  * Sky.cpp 005eaef0..005ec17f (effects owner), NormalId.cpp 005ec180..005ecbaf, Surfaces / surface reflection
    templates 005ecbb0..005ef3ff, FaceInstance.cpp 005ef400..005ef79f: built here from
    native-classes/AppUnit5E8_2008FaceInstance.cpp against the native v8datamodel/FaceInstance.h (read-only).
  * an unattributed G3D TextInput user 005ef7a0..005f126f, Surface.cpp 005f1270..005f202f, boost.iostreams
    gzip / zlib / stream_buffer instantiations (library) from 005f2030 past 005f4000.

Builds (document-swap flags, VS2008 RTM 21022):
  * world:         AppUnit5E8_2008World.cpp, /fp:fast, native-headers/engine-world first on the include path;
  * world_pending: the same with /DNATIVE_APPUNIT5E8_PENDING and, first on the path, generated copies under
                   out/native-layouts/app-unit5e8-2008/pending/ of the engine-world World.h (first stage at +0x88 typed
                   CleanStage*) and of the donor v8kernel/IStage.h (2008 StageType values). Its rows are recorded
                   exact=false (pending-build-only), never counted; vtable checks never use it;
  * face:          AppUnit5E8_2008FaceInstance.cpp (no extra flags, the face-instance-lifetime profile).

Every counted row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the
address the original instruction uses and verified: imports by DLL export name, constants and string literals by
bytes, RTTI type descriptors by name, vtables by the complete-object locator class, own symbols by the row proven
here, COMDAT support bodies by exactness at the bound address, the remaining externals by the explicit EXTERNAL map
(evidence name, or a row counted by another receipt, or call-site identification), data by bytes, local statics by one
address per symbol. A row is counted only when no other receipt counts it (top-level exact_function_rows, or
exact_addresses / exact_unique_addresses, or any entry marked exact for older receipts).
The receipt never writes a quoted bare address for a row it does not count.
Writes work/2008-06/shared-layouts/app-unit5e8-2008-working.json.
Set NATIVE_APP_UNIT5E8_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
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
DONOR = ROOT / 'tools/rbxgs/Client/App/include'
OUT = nb.OUT / 'app-unit5e8-2008'
OUT.mkdir(parents=True, exist_ok=True)
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT5E8_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit5e8-2008-working.json'
WORLD_SRC = R / 'native-classes/AppUnit5E8_2008World.cpp'
FACE_SRC = R / 'native-classes/AppUnit5E8_2008FaceInstance.cpp'
ENGINE_WORLD = R / 'native-headers/engine-world'

# ---- pending overlay (generated; never committed) ----------------------------------------------------------------
PENDING = OUT / 'pending'
(PENDING / 'v8kernel').mkdir(parents=True, exist_ok=True)
(PENDING / 'v8world').mkdir(parents=True, exist_ok=True)
istage = (DONOR / 'v8kernel/IStage.h').read_text()
DONOR_ENUM = istage[istage.index('JOINT_STAGE = 0x0,'):istage.index('KERNEL_STAGE = 0x8,') + len('KERNEL_STAGE = 0x8,')]
STAGES_2008 = ['CLEAN_STAGE', 'JOINT_STAGE', 'CLUMP_STAGE', 'TREE_STAGE', 'ASSEMBLY_STAGE', 'SLEEP_STAGE',
               'SIMJOB_STAGE', 'KERNEL_STAGE']   # getStageType bodies, cited in native-headers/v8world/CleanStage2008.h
assert istage.count(DONOR_ENUM) == 1
(PENDING / 'v8kernel/IStage.h').write_text(istage.replace(
    DONOR_ENUM, '\n\t\t\t\t'.join('%s = 0x%x,' % (n, i) for i, n in enumerate(STAGES_2008))))
world_h = (ENGINE_WORLD / 'v8world/World.h').read_text()
assert world_h.count('\t\tJointStage* jointStage;') == 1 and world_h.count('\tclass JointStage;') == 1
(PENDING / 'v8world/World.h').write_text(world_h.replace('\t\tJointStage* jointStage;', '\t\tCleanStage* jointStage;')
                                         .replace('\tclass JointStage;', '\tclass JointStage;\n\tclass CleanStage;'))


def build(name, src, extra=(), first=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + ['/I' + str(p) for p in first] + flags[i:] + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


OBJ, FLAGS = {}, {}
OBJ['world'], FLAGS['world'] = build('NativeAppUnit5E8_2008_world', WORLD_SRC, ['/fp:fast'], [ENGINE_WORLD])
OBJ['world_pending'], FLAGS['world_pending'] = build('NativeAppUnit5E8_2008_world_pending', WORLD_SRC,
                                                     ['/fp:fast', '/DNATIVE_APPUNIT5E8_PENDING'],
                                                     [PENDING, ENGINE_WORLD])
OBJ['face'], FLAGS['face'] = build('NativeAppUnit5E8_2008_face', FACE_SRC)

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}

# ---- externals: address the original instruction uses -------------------------------------------------------------
EXTERNAL = {
    # evidence names
    '?getFirstContact@Primitive@RBX@@QAEPAVContact@2@XZ': 0x5e7bd0,                       # 005e9198
    '?getNextContact@Primitive@RBX@@QAEPAVContact@2@PAV32@@Z': 0x5e7be0,                  # 005e91ad
    '?onPrimitiveContactParametersChanged@Contact@RBX@@QAEXXZ': 0x607ad0,                 # 005e91a5
    '?onPrimitiveGeometryTypeChanged@ContactManager@RBX@@QAEXPAVPrimitive@2@@Z': 0x60d8e0,  # 005e9236
    '?append@?$Array@PAVPrimitive@RBX@@@G3D@@QAEXABQAVPrimitive@RBX@@@Z': 0x59a190,       # 005e98ce / 005e98de
    '?insert@?$_Tree@V?$_Tset_traits@PAVPrimitive@RBX@@U?$less@PAVPrimitive@RBX@@@std@@V?$allocator@PAVPrimitive@RBX@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tset_traits@PAVPrimitive@RBX@@U?$less@PAVPrimitive@RBX@@@std@@V?$allocator@PAVPrimitive@RBX@@@4@$0A@@std@@@std@@_N@2@ABQAVPrimitive@RBX@@@Z': 0x5e8c40,  # counted by services-working.json etc.
    # call-site identification (no evidence name; the callee is the only out-of-line body the source can call there)
    '?onPrimitiveExtentsChanged@ContactManager@RBX@@QAEXPAVPrimitive@2@@Z': 0x60cc50,     # 005e91c6 (tail call)
    '?createJoints@World@RBX@@AAEXPAVPrimitive@2@PAV?$set@PAVPrimitive@RBX@@U?$less@PAVPrimitive@RBX@@@std@@V?$allocator@PAVPrimitive@RBX@@@4@@std@@@Z': 0x5ea4d0,   # 005ea5d7 / 005ea89e / 005eaea3
    '?destroyJoints@World@RBX@@AAEXPAVPrimitive@2@PAV?$set@PAVPrimitive@RBX@@U?$less@PAVPrimitive@RBX@@@std@@V?$allocator@PAVPrimitive@RBX@@@4@@std@@@Z': 0x5ea3f0,  # 005ea4c7 / 005eada3
    # 2-argument Notifier<World, E>::raise(E, Listener*): rows of this unit whose analysed extent stops at the catch
    # funclet; the compiled body equals the joined rows (bounds_evidence)
    '?raise@?$Notifier@VWorld@RBX@@UAutoJoin@2@@RBX@@IBEXUAutoJoin@2@PAV?$Listener@VWorld@RBX@@UAutoJoin@2@@2@@Z': 0x5e95c0,
    '?raise@?$Notifier@VWorld@RBX@@UAutoDestroy@2@@RBX@@IBEXUAutoDestroy@2@PAV?$Listener@VWorld@RBX@@UAutoDestroy@2@@2@@Z': 0x5e9680,
    '?raise@?$Notifier@VWorld@RBX@@UAssemblyPhysicsOn@2@@RBX@@IBEXUAssemblyPhysicsOn@2@PAV?$Listener@VWorld@RBX@@UAssemblyPhysicsOn@2@@2@@Z': 0x5e9740,
    '?raise@?$Notifier@VWorld@RBX@@UAssemblyPhysicsOff@2@@RBX@@IBEXUAssemblyPhysicsOff@2@PAV?$Listener@VWorld@RBX@@UAssemblyPhysicsOff@2@@2@@Z': 0x5e9800,
    # FaceInstance (face build)
    '?raisePropertyChanged@Instance@RBX@@QAEXABVPropertyDescriptor@Reflection@2@@Z': 0x40db00,  # setFace 005ef78a (Instance.h cites it)
    '??1FaceInstance@RBX@@UAE@XZ': 0x597500,                                               # ??_G 005ef673 (face-instance-lifetime)
    # support constructor 005ef530 (face-instance-lifetime binds the same two)
    '??0Instance@RBX@@QAE@XZ': 0x55b7e0,                                                   # 005ef54d
    '?askSetParent@FaceInstance@RBX@@MBE_NPBVInstance@2@@Z': 0x62e190,                     # vtable 0084072c slot 3 (face-instance-lifetime)
    '?classDescriptor@?$Described@VFaceInstance@RBX@@$1?sFaceInstance@2@3PADAVInstance@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ': 0x597fb0,  # 005ef55a
}
# data symbols verified by their address (static descriptor objects: one address per symbol)
DATA_AT = {
    '?prop_Face@FaceInstance@RBX@@2V?$EnumPropDescriptor@VFaceInstance@RBX@@W4NormalId@2@@Reflection@2@B': 0x97b57c,  # 005ef782
}
# COMDAT bodies emitted in the unit object that the original reaches out of line: accepted only when the compiled body
# is relocation-masked exact at the bound address (support rows, never counted here).
SUPPORT = {
    # std::set<Primitive*> constructor / erase(first, last) of the ignore set in create/destroyJointsToWorld
    # (005ead5b / 005eadcd); the erase body is ICF-folded with the set<Script*> one (evidence name)
    '??0?$_Tree@V?$_Tset_traits@PAVPrimitive@RBX@@U?$less@PAVPrimitive@RBX@@@std@@V?$allocator@PAVPrimitive@RBX@@@4@$0A@@std@@@std@@QAE@ABU?$less@PAVPrimitive@RBX@@@1@ABV?$allocator@PAVPrimitive@RBX@@@1@@Z': 0x64b2a0,
    '?erase@?$_Tree@V?$_Tset_traits@PAVPrimitive@RBX@@U?$less@PAVPrimitive@RBX@@@std@@V?$allocator@PAVPrimitive@RBX@@@4@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z': 0x64ad30,
}
# rows counted by another receipt that the face build compiles only to emit the vtables (never counted here)
SUPPORT_ROWS = {
    'face': [(0x5ef530, '??0FaceInstance@RBX@@QAE@XZ', 'face-instance-lifetime.json')],
}
ALIAS = {'??_EFaceInstance@RBX@@UAEPAXI@Z': 0x5ef670}   # ??_E and ??_G are one body (ICF)
UNBOUND = []
binding = {}
support_out = {}
LOCAL_STATIC_AT = {}

# (address, symbol or unique prefix): one entry per counted address
ROWS = {
    'world': [
        (0x005e9150, '?getKernel@World@RBX@@QAEAAVKernel@2@XZ'),
        (0x005e9160, '?getMetric@World@RBX@@QBEHW4MetricType@IWorldStage@2@@Z'),
        (0x005e9190, '?onPrimitiveContactParametersChanged@World@RBX@@QAEXPAVPrimitive@2@@Z'),
        (0x005e91c0, '?onPrimitiveExtentsChanged@World@RBX@@QAEXPAVPrimitive@2@@Z'),
        (0x005e9230, '?onPrimitiveGeometryTypeChanged@World@RBX@@QAEXPAVPrimitive@2@@Z'),
        (0x005e98c0, '?onPrimitiveTouched@World@RBX@@QAEXPAVPrimitive@2@0@Z'),
        (0x005e9940, '?raise@?$Notifier@VWorld@RBX@@UAutoJoin@2@@RBX@@IBEXUAutoJoin@2@@Z'),
        (0x005e99d0, '?raise@?$Notifier@VWorld@RBX@@UAutoDestroy@2@@RBX@@IBEXUAutoDestroy@2@@Z'),
        (0x005e9a60, '?raise@?$Notifier@VWorld@RBX@@UAssemblyPhysicsOn@2@@RBX@@IBEXUAssemblyPhysicsOn@2@@Z'),
        (0x005e9af0, '?raise@?$Notifier@VWorld@RBX@@UAssemblyPhysicsOff@2@@RBX@@IBEXUAssemblyPhysicsOff@2@@Z'),
        (0x005ea4c0, '?destroyJoints@World@RBX@@QAEXPAVPrimitive@2@@Z'),
        (0x005ea5d0, '?createJoints@World@RBX@@QAEXPAVPrimitive@2@@Z'),
        (0x005ea880, '?joinAll@World@RBX@@QAEXXZ'),
        (0x005ead30, '?destroyJointsToWorld@World@RBX@@QAEXABV?$Array@PAVPrimitive@RBX@@@G3D@@@Z'),
        (0x005eae10, '?createJointsToWorld@World@RBX@@QAEXABV?$Array@PAVPrimitive@RBX@@@G3D@@@Z'),
    ],
    'face': [
        (0x005ef5f0, '??_EFaceInstance@RBX@@WCE@AEPAXI@Z'),
        (0x005ef600, '??_EFaceInstance@RBX@@WEE@AEPAXI@Z'),
        (0x005ef610, '??_EFaceInstance@RBX@@WGE@AEPAXI@Z'),
        (0x005ef620, '??_EFaceInstance@RBX@@WIE@AEPAXI@Z'),
        (0x005ef630, '??_EFaceInstance@RBX@@WKE@AEPAXI@Z'),
        (0x005ef640, '??_EFaceInstance@RBX@@WME@AEPAXI@Z'),
        (0x005ef650, '??_EFaceInstance@RBX@@WBA@AEPAXI@Z'),
        (0x005ef660, '??_EFaceInstance@RBX@@WBE@AEPAXI@Z'),
        (0x005ef670, '??_GFaceInstance@RBX@@UAEPAXI@Z'),
        (0x005ef770, '?setFace@FaceInstance@RBX@@QAEXW4NormalId@2@@Z'),
    ],
}
# rows compiled here that are not exact against the current headers (recorded, never counted)
NOT_EXACT = {
    'world': [
        (0x005e9170, '?getNumHashNodes@World@RBX@@QBEHXZ',
         'the 2008 SpatialHash count is at +0x78 of the object ContactManager +0x0 points to; the donor SpatialHash.h '
         'puts nodesOut elsewhere (needs a 2008 SpatialHash declaration)'),
        (0x005e9180, '?getMaxBucketSize@World@RBX@@QBEHXZ', 'as getNumHashNodes: maxBucket at SpatialHash +0x7c in 2008'),
        (0x005e91d0, '?onAssemblyExtentsChanged@World@RBX@@QAEXPAVAssembly@2@@Z',
         '140/87 B: the 2008 Assembly::PrimIterator is out of line (005e5fc0 / 005e5fa0 / ++ 00647640); the donor '
         'Assembly.h inlines it'),
    ],
}
# pending-build-only rows (exact only in world_pending; recorded exact=false, never counted)
PENDING_ROWS = [
    (0x005e9240, '?onJointPrimitiveNulling@World@RBX@@QAEXPAVJoint@2@PAVPrimitive@2@@Z'),
    (0x005e9250, '?onJointPrimitiveSet@World@RBX@@QAEXPAVJoint@2@PAVPrimitive@2@@Z'),
    (0x005e93b0, '?getSimJobStage@World@RBX@@QAEAAVSimJobStage@2@XZ'),
    (0x005e93e0, '?getSleepStage@World@RBX@@QAEPAVSleepStage@2@XZ'),
]
PENDING_EXTERNAL = {
    '?onJointPrimitiveNulling@CleanStage@RBX@@QAEXPAVJoint@2@PAVPrimitive@2@@Z': 0x64a420,   # CleanStage2008.h cites it
    '?onJointPrimitiveSet@CleanStage@RBX@@QAEXPAVJoint@2@PAVPrimitive@2@@Z': 0x64a460,       # CleanStage2008.h cites it
}
REJECTED = {
    'getNumHashNodes / getMaxBucketSize with the donor SpatialHash.h': '12/12 B, different displacement (+0x78 / +0x7c needed)',
    'onAssemblyExtentsChanged with the donor Assembly::PrimIterator': '140/87 B (iterator inlined; 2008 calls it out of line)',
    'insertPrimitive / removePrimitive (pending build, donor Primitive.h)': (
        '69/69 and 99/99 B but not exact: the 2008 Primitive keeps worldIndex at +0x50 and world at +0x58 '
        '(005e990d / 005e9915 / 005ea901 / 005ea908); needs v8world/Primitive2008.h, which cannot be combined with the '
        'donor Primitive.h that engine-world World.h includes. Removed from the source.'),
}


def support_key(symbol):
    keys = [k for k in SUPPORT if symbol == k or symbol.startswith(k)]
    assert len(keys) <= 1, (symbol, keys)
    return keys[0] if keys else None


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


def bind_value(raw, sections, symbols, definitions, bodies, name, body, target, address, own, extern, record=True,
               unbound=None):
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
        elif symbol in ALIAS:
            assert ALIAS[symbol] == value, (name, symbol, hex(value), hex(ALIAS[symbol]))
            how = 'ICF-folded body (alias of a row proven here)'
        elif symbol in own:
            assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
            how = 'own row'
        elif support_key(symbol):
            assert SUPPORT[support_key(symbol)] == value, (name, symbol, hex(value))
            sbody, srefs = bodies[symbol]
            starget, strefs = target_of(value)
            assert match.exact_match(starget, strefs, sbody, srefs), ('support body not exact', symbol, hex(value))
            support_out[symbol] = '%08x' % value
            how = 'support body exact at the bound address'
        elif symbol in DATA_AT:
            assert DATA_AT[symbol] == value, (name, symbol, hex(value), hex(DATA_AT[symbol]))
            how = 'static descriptor (one address per symbol)'
        elif symbol in extern:
            assert extern[symbol] == value, (name, symbol, hex(value), hex(extern[symbol]))
            how = 'external' + (' (evidence name)' if names.get(value, '') == symbol else '')
        elif symbol in LOCAL_STATIC_AT:
            assert LOCAL_STATIC_AT[symbol] == value, (name, symbol, hex(value), hex(LOCAL_STATIC_AT[symbol]))
            how = 'static data (one address per symbol)'
        else:
            (UNBOUND if unbound is None else unbound).append(
                "    %r: %#x,   # %s in %s" % (symbol, value, names.get(value, '')[:60], name[:60]))
            continue
        if record:
            prev = binding.setdefault(symbol, (value, name))
            assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
        verified[symbol] = '%s (%s)' % (hex(value), how)
    return verified, local


def verify(which, rows, own, extern, strict=True, record=True, unbound=None):
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
                                     extern, record, unbound)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local)})
        result.append(entry)
    return result


resolved = {k: resolve(OBJ[k], rows) for k, rows in ROWS.items()}
own = {}
for rows in resolved.values():
    for address, name in rows:
        own.setdefault(name, address)
groups = {k: verify(k, rows, own, EXTERNAL) for k, rows in resolved.items()}

# support rows (counted elsewhere; verified exact with every target bound, never counted here)
support_rows = []
for which, items in SUPPORT_ROWS.items():
    rows = resolve(OBJ[which], [(a, s) for a, s, _ in items])
    for (address, name), (_, _, receipt) in zip(rows, items):
        r = verify(which, [(address, name)], own, EXTERNAL)[0]
        assert r['exact'] or DISCOVER, r
        support_rows.append({'row': '%08x counted by %s' % (address, receipt), 'symbol': name,
                             'exact': r['exact'], 'verified_targets': r.get('verified_targets', {})})

# not-exact rows of the current build
not_exact_rows = []
for which, items in NOT_EXACT.items():
    rows = resolve(OBJ[which], [(a, s) for a, s, _ in items])
    for (address, name), (_, _, why) in zip(rows, items):
        r = verify(which, [(address, name)], own, EXTERNAL, strict=False, record=False)[0]
        assert not r['exact'], ('now exact: count it', r['address'])
        not_exact_rows.append({'row': '%08x (not counted)' % address, 'symbol': name, 'size': r['size'],
                               'target_size': r['target_size'], 'exact': False, 'reason': why})

# pending-build-only rows
pend_unbound = []
pend_extern = dict(EXTERNAL)
pend_extern.update(PENDING_EXTERNAL)
pending_rows = []
for address, name in resolve(OBJ['world_pending'], PENDING_ROWS):
    r = verify('world_pending', [(address, name)], own, pend_extern, strict=False, record=False, unbound=pend_unbound)[0]
    assert r['exact'] or DISCOVER, ('pending row not exact', r['address'])
    pending_rows.append({'row': '%08x (pending-build-only)' % address, 'symbol': name, 'size': r['size'],
                         'exact': False, 'exact_pending_build_only': r['exact'],
                         'verified_targets': r.get('verified_targets', {})})
assert not pend_unbound or DISCOVER, pend_unbound


def vtable_slots(obj_path, vtable_address):
    """Compare every slot of each vtable in the current-header object with the original vtable whose address the
    bound vptr stores use; slots whose function is bound here must agree."""
    raw = Path(obj_path).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    out = {}
    for symbol, address in sorted(vtable_address.items()):
        start, sec = definitions[symbol]
        table = sections[sec]
        relocs = sorted((struct.unpack_from('<IIH', raw, table[5] + 10 * k)) for k in range(table[7]))
        slots = [(off - start, symbols[idx][0]) for off, idx, kind in relocs if kind == 6 and off >= start]
        slots = [x for x in slots if x[0] < table[3] - start]
        known = dict(own)
        known.update(EXTERNAL)
        known.update(ALIAS)
        checked, unbound = [], []
        for off, target_symbol in slots:
            value = struct.unpack('<I', original.data(address + off, 4))[0]
            expect = known.get(target_symbol)
            if expect is None and names.get(value, '') == target_symbol:
                checked.append('%d %s = %#x (evidence name)' % (off // 4, target_symbol[:80], value))
                continue
            if expect is None:
                unbound.append('%d %s' % (off // 4, target_symbol[:80]))
                continue
            assert expect == value, ('vtable slot', symbol, off // 4, target_symbol, hex(value), hex(expect))
            checked.append('%d %s = %#x' % (off // 4, target_symbol[:80], value))
        code_range = range(0x401000, 0x7e0000)
        originals = [struct.unpack('<I', original.data(address + 4 * k, 4))[0] for k in range(len(slots) + 1)]
        assert all(v in code_range for v in originals[:-1]) and originals[-1] not in code_range, (
            'vtable slot count', symbol, hex(address), [hex(v) for v in originals])
        out[symbol] = {'vtable': '%#x' % address, 'slots': len(slots), 'checked': checked,
                       'not_bound_here': len(unbound)}
    return out


# FaceInstance vtables: the addresses the (support) constructor 005ef530 stores, in the current-header face object
VTABLE_ADDRESS = {}
for r in support_rows:
    for sym, how in r['verified_targets'].items():
        if sym.startswith('??_7'):
            VTABLE_ADDRESS[sym] = int(how.split()[0], 16)
vtables = vtable_slots(OBJ['face'], VTABLE_ADDRESS)
thunk_slots = sum(1 for v in vtables.values() for c in v['checked'] if '??_E' in c or '??_G' in c)

if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND + pend_unbound))))
    for g, rows in groups.items():
        for r in rows:
            if not r['exact']:
                print('NOT EXACT', g, r['address'], r['symbol'][:90], r['size'], r['target_size'])
    for r in pending_rows:
        print('PENDING', r['row'], r['exact_pending_build_only'])
    sys.exit(0)
assert not UNBOUND, UNBOUND
# the eight ??_E adjustor thunks are the slot-0 entries of the eight secondary vtables (the primary GuidItem vtable
# has no destructor slot); each must be found at the slot the current-header object puts it in
assert len(VTABLE_ADDRESS) == 11 and thunk_slots == 8, (len(VTABLE_ADDRESS), thunk_slots)


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
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if '005e8000' <= a < '005f4000'}


def concatenated_target(parts):
    """Original bytes and relocation offsets of consecutive analysed rows, joined (bounds evidence only)."""
    data, relocs, start = b'', [], parts[0]
    for a in parts:
        body, refs = target_of(a)
        assert start + len(data) == a, ('rows not contiguous', hex(a))
        relocs += [r + len(data) for r in refs]
        data += body
    return data, relocs


BOUNDS = []
raw_w = Path(OBJ['world']).read_bytes()
bodies_w = {n: (b, r) for n, b, r in match.coff_functions(raw_w)}
for parts, event in [((0x5e95c0, 0x5e95f8, 0x5e960b), 'AutoJoin'), ((0x5e9680, 0x5e96bb, 0x5e96ce), 'AutoDestroy'),
                     ((0x5e9740, 0x5e977b, 0x5e978e), 'AssemblyPhysicsOn'),
                     ((0x5e9800, 0x5e983b, 0x5e984e), 'AssemblyPhysicsOff')]:
    key = '?raise@?$Notifier@VWorld@RBX@@U%s@2@@RBX@@IBEXU%s@2@PAV' % (event, event)
    hits = [n for n in bodies_w if n.startswith(key)]
    assert len(hits) == 1, hits
    body, refs = bodies_w[hits[0]]
    data, relocs = concatenated_target(parts)
    ok = len(data) == len(body) and match.exact_match(data, relocs, body, refs)
    assert ok or DISCOVER, ('bounds evidence', hits[0])
    BOUNDS.append({'rows': ' + '.join('%08x' % a for a in parts) + ' (one function, not counted)', 'symbol': hits[0],
                   'compiled_size': len(body), 'joined_size': len(data), 'exact_when_joined': ok,
                   'reason': ('Notifier<World, %s>::raise(%s, Listener*): the three analysed rows are the try body, the '
                              'continuation after the call and the catch funclet ("Exception caught in onEvent. %%s"). '
                              'The compiled body is relocation-masked exact against the joined rows. An extent fix is '
                              'needed before it can be counted.' % (event, event))})

# ---- unit map --------------------------------------------------------------------------------------------------
RANGE_ROWS = [json.loads(l) for l in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines() if l.strip()]
RANGE_ROWS = [r for r in RANGE_ROWS if 0x5e8000 <= int(r['addr'], 16) < 0x5f4000]
UNITS = [
    ('Primitive.cpp tail', 0x5e8000, 0x5e8ec0),
    ('PhysicsService.cpp', 0x5e8ec0, 0x5e9150),
    ('World.cpp', 0x5e9150, 0x5eaef0),
    ('Sky.cpp', 0x5eaef0, 0x5ec180),
    ('NormalId.cpp', 0x5ec180, 0x5ecbb0),
    ('Surfaces + surface reflection templates', 0x5ecbb0, 0x5ef400),
    ('FaceInstance.cpp', 0x5ef400, 0x5ef7a0),
    ('unattributed G3D TextInput user', 0x5ef7a0, 0x5f1270),
    ('Surface.cpp', 0x5f1270, 0x5f2030),
    ('boost.iostreams instantiations (library)', 0x5f2030, 0x5f4000),
]
unit_rows = {}
for r in RANGE_ROWS:
    a = int(r['addr'], 16)
    unit = [u for u, lo, hi in UNITS if lo <= a < hi][0]
    unit_rows.setdefault(unit, []).append(r)

UNIT_MAP = {
    'Primitive.cpp tail ..005e8ebf': (
        'v8world/Primitive.cpp (Body/Primitive owner, native v8world/Primitive2008.h): evidence names setDragging '
        '005e8050, getFaceInWorld 005e81b0, getCoordinateFrame 005e82c0, setController 005e85e0, EdgeList::removeEdge '
        '005e8610 / insertEdge 005e8990, setPrimitiveType 005e86f0, Body allocation new 0xdc at 005e8770, and the '
        'set<Primitive*> _Tree instantiations _Insert 005e8a40 / insert 005e8c40 (also used by World and Workspace). '
        'Not built here.'),
    'PhysicsService.cpp 005e8ec0..005e914f': (
        'v8datamodel/PhysicsService.cpp (services owner, native v8datamodel/PhysicsService.h): onServiceProvider '
        '005e8ec0 (Workspace find 00490af0, World at Workspace +0x2e4), the AssemblyPhysicsOn/Off listener '
        'onEvent bodies 005e9110 / 005e9130. Not built here (005e8ec0 needs the native Workspace getWorld proposal '
        'already filed by the services / geometry receipts).'),
    'World.cpp 005e9150..005eaeef': (
        'v8world/World.cpp. Evidence: World() 005ea920 (four Notifier vtables 0083f8d8 / 0083f8c8 / 0083f8b8 / '
        '0083f8a8, new 0x14 ContactManager 0060d260, new 0x10 CleanStage 0064a310, six new 0xc048 CodeProfiler '
        '005c43a0 at +0xfc..+0x110, i.e. the 0x114 size RootInstance() passes to new at 00591739), ~World 005ea5e0 and '
        'its ??_G 005ead10 with the three ??_E adjustor thunks 005ea850 / 005ea860 / 005ea870, the evidence names '
        'onPrimitiveContactParametersChanged 005e9190, insertContact 005e9260, destroyContact 005e9280, '
        'destroyJointsToWorld 005ead30, createJointsToWorld 005eae10 and the 2-argument raise 005e95c0 / 005e9680, '
        'the AssemblyPhysicsOn/Off raises 005e9740 / 005e9800 and 1-argument raises 005e9940..005e9af0, the stage '
        'finders (StageType 6 / 5 / 2 loops 005e93b0..005e9520), step 005e9fd0 (CodeProfiler marks, floor), '
        'insertJoint 005ea320 / removeJoint 005ea3a0, createJoints / destroyJoints 005ea3f0..005ea5d0, joinAll '
        '005ea880, removePrimitive 005ea8b0, and the set<Joint*> / set<Script*> iterator helpers 005e92b0 / 005e9340 '
        '/ 005e9f60. 005e9ec0 (a Notifier constructor folded with Notifier<StandardOut, ...>) is counted by '
        'leaves2008-working.json; 005e9f20 is a G3D::Array-like destructor helper. Built here: 15 counted rows.'),
    'Sky.cpp 005eaef0..005ec17f': (
        'v8datamodel/Sky.cpp (effects owner, native v8datamodel/Sky.h): testImage 005eaef0 (called by getG3DSky '
        '005ebbb0 for each face), FactoryProduct<Sky> rows 005eb020.., the Player classDescriptor / BoundProp '
        'instantiations 005eb290 / 005eb300 (ICF), Sky() 005eb640, the ??_E thunks 005eba60..005ebad0, ~Sky 005ebae0. '
        'Most rows are counted by effects-working.json; 005ec170 is counted by stats-service-working.json. Not built '
        'here.'),
    'NormalId.cpp 005ec180..005ecbaf': (
        'util/NormalId.cpp: evidence names normalIdOpposite 005ec180, Vector3ToNormalId 005ec290, Matrix3ToNormalId '
        '005ec310, uvwToObject 005ec330, objectToUvw 005ec450, normalIdToVector3 005ec570, normalIdToMatrix3 005ec800, '
        'mapToUvw_Legacy 005ec9d0, and the per-face uvwToObject<id> bodies 005ec1a0..005ec220 (ViewNew owner FYI). '
        'Not built here.'),
    'Surfaces + surface reflection templates 005ecbb0..005ef3ff': (
        'v8datamodel/Surfaces: Surfaces(PartInstance*) 005ecbb0, operator[] 005ecc00, the map<Vector3, '
        'BlockTemplate*> iterator == 005ecca0 (ICF), then the surface reflection instantiations: EnumDesc / holder '
        'for SurfaceType and Controller::InputType (005eccd0..005ed800), SurfaceGetSet<face> get/set pairs '
        '(005ecd60..005ed0e0), SurfaceEnumPropDescriptor<face, SurfaceType / InputType> (005ed830..005ef3d0) and '
        'SurfaceDescriptor<face> (005eecc0..005ef180). 005ecc00 is counted by surfaces-lookup-trial.json. Owners: '
        'native v8datamodel/Surface.h / Surfaces.h (read-only); the descriptors need the reflection core '
        'EnumPropDescriptor proposal (TANDEM 2026-11-05). Not built here.'),
    'FaceInstance.cpp 005ef400..005ef79f': (
        'v8datamodel/FaceInstance.cpp: render3dSelect 005ef400 (dynamic_cast<PartInstance*>(getParent()) from the '
        'IRenderable base at +0x130, face +0x140; evidence name is the IRenderable slot), the boost::function functor '
        'allocation 005ef470 (new 0x18, vtable 00840684) and EnumDesc<NormalId> singleton 005ef4c0 / call_once '
        'thunk 005ef520 used by EnumPropDescriptor<FaceInstance, NormalId>() 005ef690, FaceInstance() 005ef530 '
        '(counted by face-instance-lifetime.json), the eight ??_E adjustor thunks 005ef5f0..005ef660 and ??_G '
        '005ef670 (calls ~FaceInstance 00597500), setFace 005ef770 (prop_Face 0097b57c). Built here: 10 counted '
        'rows.'),
    'unattributed G3D TextInput user 005ef7a0..005f126f': (
        '005ef7a0 compares two files with _stat64i32 and _unlink()s the stale one; 005ef840 (6698 B) is its only '
        'caller and is called from 004eb56c / 004eb71e; it drives G3D TextInput token reads (0050eef0 / 0050d530, '
        'token types 0x80..0x8c). No RTTI, string or evidence name ties it to an RBX class. Not recovered.'),
    'Surface.cpp 005f1270..005f202f': (
        'v8datamodel/Surface.cpp: evidence names Surface(PartInstance*, NormalId) 005f1270, getSurfaceType 005f1290, '
        'getInput 005f12a0, isControllable 005f13c0; the property registration 005f17a0 ("SurfaceInput" 00840814, '
        '"ParamA" 0084080c, "ParamB" 00840804, "Constraint" 008407f8) and its helpers up to 005f2000. Owner: native '
        'v8datamodel/Surface.h. Not built here.'),
    'boost.iostreams instantiations (library) 005f2030..': (
        'boost 1.34.1 iostreams code (evidence names gzip_params 005f2030 / 005f2160 / 005f20f0, '
        'basic_gzip_compressor::normalize_params 005f21f0, zlib_compressor_impl / zlib_decompressor_impl, '
        'indirect_streambuf / stream_buffer / chain / filtering_stream_base, cant_read / cant_seek / cant_write) '
        'instantiated for basic_null_device and for the Http unit\'s String_sink / HttpRequest_source; continues past '
        '005f4000. Library templates (boost), not recovered.'),
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
    'Owner of native-headers/engine-world/v8world/World.h (colingsnyder2-ux): the 2008 World has an owned '
    'G3D::Array<Primitive*> at +0xb8 between primitives (+0xac) and breakableJoints, so breakableJoints is at +0xc4, '
    'numJoints +0xe4, numContacts +0xe8, numLinkCalls +0xec, tempPrimitives +0xf0 and the six CodeProfiler pointers '
    '+0xfc..+0x110 (size 0x114). Evidence: World() 005ea920 zeroes +0xb8 / +0xbc / +0xc0 after primitives and builds '
    'the set at +0xc4 (0064b2a0); 005e9bb0 clears +0xb8 (00599a70) and appends primitives to it (0059a190); '
    'insertContact 005e9260 / destroyContact 005e9280 use +0xe8, insertJoint 005ea320 / removeJoint 005ea3a0 use '
    '+0xe4 and +0xc4, createJoints 005ea4d0 uses +0xec and +0xf0. The member name is not in the evidence. With it, '
    'insertContact / destroyContact / insertJoint / removeJoint / doBreakJoints 005e9e00 become candidates.',
    'Same owner: World +0x88 is the first 2008 stage, a CleanStage (World() news 0x10 and calls CleanStage(NULL, this) '
    '0064a310; native v8world/CleanStage2008.h), not a JointStage. onJointPrimitiveNulling 005e9240 / '
    'onJointPrimitiveSet 005e9250 tail-call CleanStage 0064a420 / 0064a460, insertPrimitive 005e98f0 calls '
    'CleanStage::onPrimitiveAdded 0064a3e0 and removePrimitive 005ea8b0 calls onPrimitiveRemoving 0064a400. With '
    '`CleanStage* jointStage;` (generated copy out/native-layouts/app-unit5e8-2008/pending/v8world/World.h) 005e9240 '
    'and 005e9250 are exact with every target verified.',
    'Owner of the donor-shadowing v8kernel/IStage.h StageType (kernel-stages owner; proposal already in '
    'record_native_kernel_stages.py): with the 2008 values (CLEAN 0 .. KERNEL 7) World::getSimJobStage 005e93b0 '
    '(type 6) and getSleepStage 005e93e0 (type 5) are exact in this pending build; the ClumpStage (type 2) callers '
    '005e9460 / 005e94a0 / 005e94e0 / 005e9520 and ticklePrimitive 005e9410 (2008: two arguments, ret 8, '
    'SleepStage 0064b890) also need a 2008 ClumpStage / SleepStage declaration.',
    'Same World.h owner, FYI: the 2008 SpatialHash keeps the getNumHashNodes / getMaxBucketSize counters at +0x78 / '
    '+0x7c (005e9170 / 005e9180 read [[contactManager +0]+0x78 / +0x7c]); Assembly::PrimIterator is out of line '
    '(begin / end 005e5fc0 / 005e5fa0, ++ 00647640, used by onAssemblyExtentsChanged 005e91d0 and computeFallen '
    '005e9c40).',
    'BOUNDS for the server host (no bounds.json change): 005e95c0 + 005e95f8 + 005e960b, 005e9680 + 005e96bb + '
    '005e96ce, 005e9740 + 005e977b + 005e978e and 005e9800 + 005e983b + 005e984e are each one function, '
    'Notifier<World, AutoJoin / AutoDestroy / AssemblyPhysicsOn / AssemblyPhysicsOff>::raise(E, Listener*) with its '
    'catch funclet (receipt bounds_evidence: compiled 179 B bodies exact against the joined rows).',
]

receipt = {
    'scope': ('Inactive 2008-06 native recovery of the application range 005e8000..005f4000: unit map of every row, '
              'World.cpp rows against the native engine-world World.h and FaceInstance.cpp rows against the native '
              'FaceInstance.h. No runtime, link or class-swap claim.'),
    'exact_function_rows': exact_rows,
    'exact_function_row_count': len(exact_rows),
    'range_rows': len(RANGE_ROWS),
    'rows': groups,
    'support_rows': support_rows,
    'not_exact_rows': not_exact_rows,
    'pending_rows': pending_rows,
    'vtables': vtables,
    'bounds_evidence': BOUNDS,
    'unit_map': unit_map,
    'proposals': PROPOSALS,
    'rejected': REJECTED,
    'flags': FLAGS,
    'sources': {k: nb.sha(p) for k, p in [('world', WORLD_SRC), ('face', FACE_SRC)]},
    'headers_read_only': ['native-headers/engine-world/v8world/World.h', 'native-headers/engine-world/v8world/ContactManager.h',
                          'native-headers/v8world/JointStage2008.h', 'native-headers/v8world/CleanStage2008.h',
                          'native-headers/v8world/SimJobStage2008.h', 'native-headers/v8datamodel/FaceInstance.h'],
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit5e8-2008: %d counted rows (%d range rows), %d pending-build-only, %d vtables checked'
      % (len(exact_rows), len(RANGE_ROWS), sum(1 for r in pending_rows if r['exact_pending_build_only']), len(vtables)))
