"""Verify the inactive native RBX::Geometry / Block / Ball and Contact / BallBallContact / BallBlockContact recovery
(2008-06).

Builds (document-swap flags, VS2008 RTM 21022, /fp:fast), all from the current native headers:
  * tests/NativeWorldShapesLayout.cpp   sizeof/offset probe (mov eax, imm32; ret), a Primitive::newGeometry analog
                                        (compared with 005e7d80 for the inline constructors and allocation sizes, not
                                        counted) and two ContactManager::createContact ball-branch analogs. They emit
                                        the vtables and the header-inline virtuals / constructors the original keeps as
                                        COMDATs (Geometry 005e2790..005e78c0, nullGeometry 005e7870 and its atexit
                                        destructor 007ff9e0, Block/Ball getRadius/getCenterToCorner/getMoment, the
                                        ball contact constructors and slots 0060cae0..0060cbc0);
  * native-classes/Block.cpp            the unit 00647760..00649120 (Block methods, myLess, BlockTemplate and the
                                        std::map<Vector3, BlockTemplate*, myLess> members) plus the blockTemplates
                                        dynamic initializer 007f8c10 and atexit destructor 008010b0;
  * native-classes/Ball.cpp             the unit 00649130..006492bc;
  * native-classes/Contact.cpp          Contact constructor 00606c20 and deleteConnector 00606d10.

The headers use non-colliding names (v8world/Geometry2008.h, Block2008.h, Ball2008.h, Contact2008.h): a header at the
original path would shadow the donor for every unit that includes Primitive.h / PartInstance.h (see PROPOSALS).

Every exact row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified: imports by DLL export name, string literals by bytes, type descriptors and
vtables by original RTTI names, own symbols by the row proven here, folded bodies by their address, and the remaining
externals by the explicit EXTERNAL / DATA maps (call sites read in the original disassembly). A symbol binds to one
address across all rows. Vtables are compared slot by slot from the objects built with the current headers.
Writes work/2008-06/shared-layouts/world-shapes-working.json. Set NATIVE_WORLD_SHAPES_DISCOVER=1 to list unbound
targets and non-exact rows instead of asserting.
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
LAYOUT = R / 'tests/NativeWorldShapesLayout.cpp'
BLOCK = R / 'native-classes/Block.cpp'
BALL = R / 'native-classes/Ball.cpp'
CONTACT = R / 'native-classes/Contact.cpp'
HEADERS = [R / 'native-headers/v8world' / h for h in ('Geometry2008.h', 'Block2008.h', 'Ball2008.h', 'Contact2008.h')]
DISCOVER = bool(os.environ.get('NATIVE_WORLD_SHAPES_DISCOVER'))


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeWorldShapesLayout', LAYOUT, ['/fp:fast'])
block_obj, block_flags = build('NativeWorldShapesBlock', BLOCK, ['/fp:fast'])
ball_obj, ball_flags = build('NativeWorldShapesBall', BALL, ['/fp:fast'])
contact_obj, contact_flags = build('NativeWorldShapesContact', CONTACT, ['/fp:fast'])

# ---- layout ---------------------------------------------------------------------------------------
raw = layout_obj.read_bytes()
SIZES = {'nativeGeometrySize': 0x10, 'nativeBlockSize': 0x18, 'nativeBallSize': 0x14, 'nativeContactSize': 0x34,
         'nativeBallBallContactSize': 0x38, 'nativeBallBlockContactSize': 0x38}
for fn, size in SIZES.items():
    name_, body_, _ = next(x for x in match.coff_functions(raw) if x[0].startswith('?' + fn + '@@'))
    assert body_ == b'\xb8' + struct.pack('<I', size) + b'\xc3', (fn, body_.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}


def norm(symbol):
    return symbol


TREE = ('?$_Tree@V?$_Tmap_traits@VVector3@G3D@@PAVBlockTemplate@RBX@@UmyLess@4@V?$allocator@U?$pair@$$CBVVector3@G3D@@'
        'PAVBlockTemplate@RBX@@@std@@@std@@$0A@@std@@@std@@')
MAP = ('?$map@VVector3@G3D@@PAVBlockTemplate@RBX@@UmyLess@4@V?$allocator@U?$pair@$$CBVVector3@G3D@@PAVBlockTemplate'
       '@RBX@@@std@@@std@@@std@@')

# ---- externals: address the original instruction uses, read at the call sites listed ----------------
EXTERNAL = {
    '??2@YAPAXI@Z': 0x6a0920, '??3@YAXPAX@Z': 0x6a067a, '_atexit': 0x6a17af,
    '?zero@Matrix3@G3D@@SAABV12@XZ': 0x513dc0,                              # Geometry::getMoment 005e72d1
    '??0Matrix3@G3D@@QAE@ABV01@@Z': 0x513220,      # 005e72dd: the copy constructor (`*this = rkMatrix`) folds with
                                                   # Matrix3::operator= (evidence name ??4Matrix3 at 00513220)
    '??DMatrix3@G3D@@QBE?AVVector3@1@ABV21@@Z': 0x476580,                   # Block::getCenterToCorner (evidence name)
    '?fromOriginAndDirection@Ray@G3D@@SA?AV12@ABVVector3@2@0@Z': 0x518830,  # Block::hitTest (evidence name)
    '?collisionLocationForMovingPointFixedAABox@CollisionDetection@G3D@@SA_NABVVector3@2@0ABVAABox@2@AAV32@AA_N2@Z':
        0x7bb770,                                                            # Block::hitTest 00647fe0 / 0064806d
    '?collisionTimeForMovingPointFixedSphere@CollisionDetection@G3D@@SAMABVVector3@2@0ABVSphere@2@AAV32@2@Z':
        0x7bb5a0,                                                            # Ball::hitTest 0064927d
    # std::map const_iterator::operator== is not inlined: ICF-shared checked-iterator compare (evidence name)
    '??8const_iterator@' + TREE + 'QBE_NABV012@@Z': 0x5ecca0,
    '?fromDiagonal@Math@RBX@@SA?AVMatrix3@G3D@@ABVVector3@4@@Z': 0x5ddbd0,  # Ball::getMomentSolid 00649159
    '??0Edge@RBX@@QAE@PAVPrimitive@1@0@Z': 0x659260,                        # Contact ctor 00606c2f (evidence name)
    '?putInKernel@IPipelined@RBX@@UAEXPAVKernel@2@@Z': 0x645830,            # 0060cb18 (evidence name)
    '?removeFromKernel@IPipelined@RBX@@UAEXXZ': 0x645860,                   # 0060cb3d (evidence name)
    '?onPrimitiveContactParametersChanged@Contact@RBX@@QAEXXZ': 0x607ad0,  # 0060cb1f (evidence name)
    '?getKernel@IPipelined@RBX@@QBEPAVKernel@2@XZ': 0x645850,              # deleteConnector 00606d18
    '?removeConnector@Kernel@RBX@@QAEXPAVConnector@2@@Z': 0x5fb1f0,       # deleteConnector 00606d1f
}
DATA = {
    '?g@?1??nullGeometry@Geometry@RBX@@SAPAV23@XZ@4V23@A': 0x97abd4,       # nullGeometry static (005e7896 vtable store)
    '?v@?1??zero@Vector3@G3D@@SAABV23@XZ@4V23@A': 0x96f044,                # Vector3::zero() static (guard 0096f050)
    '?i@?1??inf@G3D@@YAABNXZ@4NB': 0x96f018,                               # G3D::inf() static (guard 0096f020)
    '?ignore@CollisionDetection@G3D@@0VVector3@2@A': 0x97f6d8,             # default outNormal (00647f81, 0064926d)
    '__TI3?AVlength_error@std@@': 0x8d0cc0,                                # _Insert throw info
    '__TI3?AVout_of_range@std@@': 0x8d0c3c,                                # erase throw info
    '?blockTemplates@BlockTemplate@RBX@@0VBlockTemplates@12@A': 0x97d5ec,   # getVertices 00648f41, 007f8c1b, 008010b0
}

# ICF / trivial-wrapper folds: the original keeps one body where these units emit several identical ones.
FOLDED = {
    '?onSetSize@Geometry@RBX@@MAEXXZ': 0x47d410,                            # Geometry vtable slot 0 (shared `ret`)
    '?getGridVolume@Geometry@RBX@@UBEMXZ': 0x5e72c0,                        # slot 7 = slot 4 body (`fldz; ret`)
    '??_GBlock@RBX@@UAEPAXI@Z': 0x5e73b0, '??_GBall@RBX@@UAEPAXI@Z': 0x5e73b0,   # empty destructors fold
    '?getGeometryType@Block@RBX@@UBE?AW4GeometryType@Geometry@2@XZ': 0x77d810,    # `mov eax, 2; ret`
    '?getGeometryType@Ball@RBX@@UBE?AW4GeometryType@Geometry@2@XZ': 0x7286a0,     # `mov eax, 1; ret`
    '?getEdgeType@Contact@RBX@@EBE?AW4EdgeType@Edge@2@XZ': 0x7286a0,              # `mov eax, 1; ret` (CONTACT)
    '?deleteAllConnectors@BallBlockContact@RBX@@EAEXXZ': 0x60cb50,
    '?numConnectors@BallBlockContact@RBX@@EBEHXZ': 0x60cb60,
    '?getConnector@BallBlockContact@RBX@@EAEPAVContactConnector@2@H@Z': 0x60cbc0,
}
NON_EXACT_ROWS = [
    (0x60cb70, '??_GBallBallContact@RBX@@UAEPAXI@Z',
     'the donor IPipelined destructor (v8world/IPipelined.h, no native header) carries RBXASSERT(currentStage == NULL), '
     'which the /D_RELEASEASSERT profile compiles in; the original 0060cb70 only restores the vtable', 'layout'),
    (0x60cbd0, '??_GBallBlockContact@RBX@@UAEPAXI@Z', 'same as 0060cb70 (donor ~IPipelined assertion)', 'layout'),
]
UNPROVEN = {
    '??_GBallBallContact@RBX@@UAEPAXI@Z': 0x60cb70,
    '??_GBallBlockContact@RBX@@UAEPAXI@Z': 0x60cbd0,
}
# Vtable slots whose bodies are not built here: bound to the address the original vtable holds (call sites / names).
SLOT_EXTERNAL = {
    '?setPrimitive@Edge@RBX@@UAEXHPAVPrimitive@2@@Z': 0x659290,            # Edge slot 4 (body sets +0xc / +0x10)
    '?stepContact@BallBallContact@RBX@@EAE_NXZ': 0x606f80,
    '?computeIsColliding@BallBallContact@RBX@@EAE_NM@Z': 0x606e90,
    '?stepContact@BallBlockContact@RBX@@EAE_NXZ': 0x607150,
    '?computeIsColliding@BallBlockContact@RBX@@EAE_NM@Z': 0x607bd0,       # evidence name
}

LAYOUT_ROWS = [
    (0x5e2790, '?getGeometryType@Geometry@RBX@@UBE?AW4GeometryType@12@XZ'),
    (0x5e72a0, '?setGridSize@Geometry@RBX@@UAEXABVVector3@G3D@@@Z'),
    (0x5e72c0, '?getRadius@Geometry@RBX@@UBEMXZ'),
    (0x5e72d0, '?getMoment@Geometry@RBX@@UBE?AVMatrix3@G3D@@M@Z'),
    (0x5e72f0, '?hitTest@Geometry@RBX@@UAE_NABVRay@G3D@@AAVVector3@4@AA_N@Z'),
    (0x5e73b0, '??_GGeometry@RBX@@UAEPAXI@Z'),
    (0x5e7870, '?nullGeometry@Geometry@RBX@@SAPAV12@XZ'),
    (0x5e78c0, '?getCenterToCorner@Geometry@RBX@@UBE?AVVector3@G3D@@ABVMatrix3@4@@Z'),
    (0x7ff9e0, '??__Fg@?1??nullGeometry@Geometry@RBX@@SAPAV12@XZ@YAXXZ'),
    (0x4e5b70, '?getRadius@Block@RBX@@UBEMXZ'),
    (0x5e7390, '?getMoment@Block@RBX@@UBE?AVMatrix3@G3D@@M@Z'),
    (0x5e73d0, '?getRadius@Ball@RBX@@UBEMXZ'),
    (0x5e73e0, '?getCenterToCorner@Ball@RBX@@UBE?AVVector3@G3D@@ABVMatrix3@4@@Z'),
    (0x5e7400, '?getMoment@Ball@RBX@@UBE?AVMatrix3@G3D@@M@Z'),
    (0x60cae0, '??0BallBallContact@RBX@@QAE@PAVPrimitive@1@0@Z'),
    (0x60cb90, '??0BallBlockContact@RBX@@QAE@PAVPrimitive@1@0@Z'),
    (0x60cb10, '?putInKernel@Contact@RBX@@EAEXPAVKernel@2@@Z'),
    (0x60cb30, '?removeFromKernel@Contact@RBX@@EAEXXZ'),
    (0x60cb50, '?deleteAllConnectors@BallBallContact@RBX@@EAEXXZ'),
    (0x60cb60, '?numConnectors@BallBallContact@RBX@@EBEHXZ'),
    (0x60cbc0, '?getConnector@BallBallContact@RBX@@EAEPAVContactConnector@2@H@Z'),
]
# Layout proof only (an analog-named copy of Primitive::newGeometry): compared, never counted.
PROOF_ROWS = [
    (0x5e7d80, '?nativeWorldShapesNewGeometry@@YAPAVGeometry@RBX@@W4GeometryType@12@@Z'),
]
BLOCK_ROWS = [
    (0x647760, '??RmyLess@RBX@@QBE_NABVVector3@G3D@@0@Z'),
    (0x6477b0, '?getMomentHollow@Block@RBX@@ABE?AVMatrix3@G3D@@M@Z'),
    (0x6478f0, '?getGridVolume@Block@RBX@@UBEMXZ'),
    (0x647900, '?getEdgePoint@Block@RBX@@ABEPBVVector3@G3D@@ABVVector3int16@4@AAW4NormalId@2@@Z'),
    (0x647990, '?getPlanePoint@Block@RBX@@ABEPBVVector3@G3D@@ABVVector3int16@4@AAW4NormalId@2@@Z'),
    (0x647a20, '?getBallBlockInfo@Block@RBX@@QAE?AW4GeoPairType@2@HVVector3int16@G3D@@AAPBVVector3@5@AAW4NormalId@2@@Z'),
    (0x647ab0, '?getBallInsideInfo@Block@RBX@@QAE?AW4GeoPairType@2@ABVVector3@G3D@@AAPBV45@AAW4NormalId@2@@Z'),
    (0x647b90, '?projectToFace@Block@RBX@@QAEXAAVVector3@G3D@@AAVVector3int16@4@AAH@Z'),
    (0x647c70, '?getProjectedVertex@Block@RBX@@QAE?AVVector2@G3D@@ABVVector3@4@W4NormalId@2@@Z'),
    (0x647d10, '?getClosestEdge@Block@RBX@@QAEHABVMatrix3@G3D@@W4NormalId@2@AAVVector3@4@@Z'),
    (0x647dd0, '?_Min@' + TREE),
    (0x647df0, '?_Rrotate@' + TREE),
    (0x647e50, '?_Max@' + TREE),
    (0x647e70, '??0BlockTemplate@RBX@@AAE@ABVVector3@G3D@@@Z'),
    (0x647f40, '?hitTest@Block@RBX@@UAE_NABVRay@G3D@@AAVVector3@4@AA_N@Z'),
    (0x6480b0, '?_Lbound@' + TREE),
    (0x648120, '?_Inc@const_iterator@' + TREE),
    (0x648190, '?_Lrotate@' + TREE),
    (0x6481e0, '?_Dec@const_iterator@' + TREE),
    (0x648270, '?getCenterToCorner@Block@RBX@@UBE?AVVector3@G3D@@ABVMatrix3@4@@Z'),
    (0x6483c0, '?_Buynode@' + TREE + 'IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@VVector3@G3D@@PAVBlockTemplate@RBX@@UmyLess@4@V?$allocator@U?$pair@$$CBVVector3@G3D@@PAVBlockTemplate@RBX@@@std@@@std@@$0A@@std@@@2@XZ'),
    (0x648400, '?_Buynode@' + TREE + 'IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@VVector3@G3D@@PAVBlockTemplate@RBX@@UmyLess@4@V?$allocator@U?$pair@$$CBVVector3@G3D@@PAVBlockTemplate@RBX@@@std@@@std@@$0A@@std@@@2@PAU342@00ABU?$pair'),
    (0x648450, '?_Erase@' + TREE),
    (0x648490, '?_Insert@' + TREE),
    (0x648690, '?erase@' + TREE + 'QAE?AViterator@12@Vconst_iterator@12@@Z'),
    (0x648960, '?insert@' + TREE + 'QAE?AU?$pair@'),
    (0x648a90, '?erase@' + TREE + 'QAE?AViterator@12@Vconst_iterator@12@0@Z'),
    (0x648b70, '?find@' + TREE),
    (0x648bf0, '?insert@' + TREE + 'QAE?AViterator@12@Vconst_iterator@12@'),
    (0x648e10, '??A' + MAP),
    (0x648ec0, '??1' + TREE),
    (0x648f30, '?getVertices@BlockTemplate@RBX@@SAPBVVector3@G3D@@ABV34@@Z'),
    (0x648fd0, '?onSetSize@Block@RBX@@EAEXXZ'),
    (0x649030, '??0' + TREE),
    (0x6490b0, '??1BlockTemplates@BlockTemplate@RBX@@QAE@XZ'),
    (0x7f8c10, '??__E?blockTemplates@BlockTemplate@RBX@@0VBlockTemplates@12@A@@YAXXZ'),
    (0x8010b0, '??__F?blockTemplates@BlockTemplate@RBX@@0VBlockTemplates@12@A@@YAXXZ'),
]
BALL_ROWS = [
    (0x649130, '?getMomentSolid@Ball@RBX@@ABE?AVMatrix3@G3D@@M@Z'),
    (0x649170, '?getGridVolume@Ball@RBX@@UBEMXZ'),
    (0x649190, '?onSetSize@Ball@RBX@@EAEXXZ'),
    (0x6491a0, '?hitTest@Ball@RBX@@UAE_NABVRay@G3D@@AAVVector3@4@AA_N@Z'),
]
CONTACT_ROWS = [
    (0x606c20, '??0Contact@RBX@@QAE@PAVPrimitive@1@0@Z'),
    (0x606d10, '?deleteConnector@Contact@RBX@@IAEXAAPAVContactConnector@2@@Z'),
]

LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
binding = {}   # symbol -> (address, row) for the one-address-per-symbol check


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
                assert norm(rtti) == norm('.' + symbol[5:-2]), (name, symbol, hex(value), rtti)
                how = 'RTTI %s' % rtti
            elif symbol.startswith('__real@'):
                assert original.data(value, len(symbol[7:]) // 2) == bytes.fromhex(symbol[7:])[::-1], (name, symbol, hex(value))
                how = 'constant %s' % symbol[7:]
            elif symbol.startswith('??_7'):
                rtti, at = original.vtable_class(value)
                cls = symbol[4:symbol.index('@@6B') + 2]
                assert norm(rtti) == norm('.?AV' + cls), (name, symbol, hex(value), rtti)
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
                how = 'external' + (' (evidence name)' if norm(names.get(value, '')) == norm(symbol) else '')
            elif symbol in UNPROVEN:
                assert UNPROVEN[symbol] == value, (name, symbol, hex(value))
                how = 'call target of a non-exact row'
            elif symbol.startswith('??_B?1??') or symbol.startswith('??_B?3??') or symbol.startswith('?$S') or '?$TSS' in symbol:
                how = 'local static'
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


OBJ = {'layout': layout_obj, 'block': block_obj, 'ball': ball_obj, 'contact': contact_obj}
layout_rows = resolve(layout_obj, LAYOUT_ROWS)
proof_rows = resolve(layout_obj, PROOF_ROWS)
block_rows = resolve(block_obj, BLOCK_ROWS)
ball_rows = resolve(ball_obj, BALL_ROWS)
contact_rows = resolve(contact_obj, CONTACT_ROWS)
non_rows = [(resolve(OBJ[w], [(a, k)])[0], w) for a, k, _, w in NON_EXACT_ROWS]
own = {}
for address, name in layout_rows + block_rows + ball_rows + contact_rows:
    own.setdefault(name, address)
strict = not DISCOVER
groups = {
    'layout': verify(layout_obj, layout_rows, own, strict),
    'block': verify(block_obj, block_rows, own, strict),
    'ball': verify(ball_obj, ball_rows, own, strict),
    'contact': verify(contact_obj, contact_rows, own, strict),
}
proof_out = verify(layout_obj, proof_rows, own, strict, record=False)
for row in proof_out:
    row['counted'] = False
    row['reason'] = 'analog-named copy of Primitive::newGeometry 005e7d80: proves the Block 0x18 / Ball 0x14 allocation ' \
                    'sizes and the inline constructors; not a recovered row'
non_out = [verify(OBJ[w], [r], own, strict=False)[0] for r, w in non_rows]
for row, (_, _, why, _) in zip(non_out, NON_EXACT_ROWS):
    if row['exact'] and not DISCOVER:
        raise AssertionError('non-exact row unexpectedly exact: %s' % row['address'])
    row['exact'], row['reason'] = False, why
if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for g in list(groups.values()) + [proof_out]:
        for r in g:
            if not r['exact']:
                print('NOT EXACT', r['address'], r['symbol'][:110], r['size'], r['target_size'])
    sys.exit(0)
assert not UNBOUND, '\n'.join(UNBOUND)
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]

# ---- vtables from the objects built with the current headers, slot by slot ---------------------------------
slot_names = {}
for table_ in (own, FOLDED, EXTERNAL, UNPROVEN, SLOT_EXTERNAL):
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
    """Each slot holds the address bound to its symbol (row, fold, external) or the evidence name."""
    out, bad = [], []
    for i, slot in enumerate(compiled_vtable(obj, symbol)):
        value = d(address + 4 * i)
        if slot.startswith('??_E') and '??_G' + slot[4:] in slot_names:
            expect, how = slot_names['??_G' + slot[4:]], 'bound (??_G)'
        else:
            expect, how = slot_names.get(slot), 'bound'
        ok = expect == value if expect is not None else norm(names.get(value, '')) == norm(slot)
        if expect is None:
            how = 'evidence name'
        out.append({'slot': i, 'symbol': slot, 'original': '%08x' % value, 'ok': ok, 'how': how})
        if not ok:
            bad.append((i, slot, hex(value)))
    assert not bad, (symbol, bad)
    return out


vt = {}
for cls, address, count in (('Geometry', 0x83f7c4, 9), ('Block', 0x83f7ec, 9), ('Ball', 0x83f814, 9),
                            ('BallBallContact', 0x8436bc, 10), ('BallBlockContact', 0x8436e8, 10)):
    assert original.vtable_class(address) == ('.?AV%s@RBX@@' % cls, 0), (cls, original.vtable_class(address))
    vt[cls] = check_vtable(layout_obj, '??_7%s@RBX@@6B@' % cls, address)
    assert len(vt[cls]) == count, (cls, len(vt[cls]))

# ---- RTTI bases ------------------------------------------------------------------------------------------------


def bases(vtable):
    hierarchy = d(d(vtable - 4) + 16)
    out = {}
    for i in range(d(hierarchy + 8)):
        bcd = d(d(hierarchy + 12) + 4 * i)
        out.setdefault(original.string(d(bcd) + 8), struct.unpack('<i', original.data(bcd + 8, 4))[0])
    return out


assert bases(0x83f7c4) == {'.?AVGeometry@RBX@@': 0}
assert bases(0x83f7ec) == {'.?AVBlock@RBX@@': 0, '.?AVGeometry@RBX@@': 0}
assert bases(0x83f814) == {'.?AVBall@RBX@@': 0, '.?AVGeometry@RBX@@': 0}
for address, cls in ((0x8436bc, 'BallBallContact'), (0x8436e8, 'BallBlockContact')):
    assert bases(address) == {'.?AV%s@RBX@@' % cls: 0, '.?AVContact@RBX@@': 0, '.?AVEdge@RBX@@': 0,
                              '.?AVIPipelined@RBX@@': 0}, cls

# Allocation sizes in the original creators: Primitive::newGeometry 005e7d80 (push 0x18 -> Block vtable, push 0x14 ->
# Ball vtable), ContactManager::createContact 0060d770 (push 0x38 before 0060cae0 and 0060cb90, push 0x7c before 0060d500).


def alloc_before(function, size, callee=None, vtable=None):
    body, _, _ = match.target('2008-06', '%08x' % function)
    at = body.index(b'\x6a' + bytes([size]))
    if callee is not None:
        call = body.index(b'\xe8', at + 2)
        while (function + call + 5 + struct.unpack_from('<i', body, call + 1)[0]) & 0xffffffff != callee:
            call = body.index(b'\xe8', call + 1)
    if vtable is not None:
        assert body.index(struct.pack('<I', vtable), at) > at
    return at


alloc_before(0x5e7d80, 0x18, vtable=0x83f7ec)
alloc_before(0x5e7d80, 0x14, vtable=0x83f814)
alloc_before(0x60d770, 0x38, callee=0x60cae0)
alloc_before(0x60d770, 0x7c, callee=0x60d500)
assert names.get(0x60d770, '').startswith('?createContact@ContactManager@RBX@@')

sha = nb.sha
paths = [Path(__file__).resolve(), LAYOUT, BLOCK, BALL, CONTACT] + HEADERS
objects = [layout_obj, block_obj, ball_obj, contact_obj]
exact = sorted({r['address'] for g in groups.values() for r in g if r['exact']})
groups['layout_proof'] = proof_out
groups['not_exact'] = non_out
PROPOSALS = {
    'v8world/Geometry.h, Block.h, Ball.h (original paths)': 'promote Geometry2008.h / Block2008.h / Ball2008.h to the '
        'original include paths once the owners of the units that include Primitive.h / PartInstance.h have re-run their '
        'recorders against them (the declarations are ABI-identical to the donor ones: same 9 slots, same fields)',
    'v8world/Contact.h (original path)': 'promote Contact2008.h together with a native Edge / IPipelined header',
    'v8world/IPipelined.h (new native header, owner: v8world core)': 'virtual ~IPipelined() {} without the '
        'RBXASSERT(currentStage == NULL): the 2008 deleting destructors 0060cb70 / 0060cbd0 contain no assertion; '
        'putInKernel 00645830 / removeFromKernel 00645860 / getKernel 00645850 out of line',
}
receipt = {
    'class': 'RBX::Geometry, RBX::Block, RBX::Ball, RBX::Contact, RBX::BallBallContact, RBX::BallBlockContact',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': {'layout': layout_flags, 'block': block_flags, 'ball': ball_flags, 'contact': contact_flags},
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in objects},
    'layout': {
        'Geometry': '0x10: vptr, gridSize +0x4 (nullGeometry static 0097abd4)',
        'Block': '0x18 (005e7d80): vertices +0x10, cornerRadius +0x14',
        'Ball': '0x14 (005e7d80): realRadius +0x10',
        'Contact': '0x34: Edge (0x20), lastContactStep +0x20, steppingIndex +0x24, jointK +0x28, elasticJointK +0x2c, '
                   'kFriction +0x30 (ctor 00606c20)',
        'BallBallContact / BallBlockContact': '0x38 (0060d770): connector +0x34',
        'BlockBlockContact': '0x7c (0060d770): not declared (fields beyond the arrays at +0x34 / +0x40 not derived)',
    },
    'rows': groups,
    'exact_function_rows': exact,
    'vtables': vt,
    'proposals': PROPOSALS,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/world-shapes-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native world shapes: %d distinct function rows exact (layout %d, block %d, ball %d, contact %d); '
      '%d non-exact rows and %d layout-proof rows not counted; targets and %d vtables verified'
      % (len(exact), sum(r['exact'] for r in groups['layout']), sum(r['exact'] for r in groups['block']),
         sum(r['exact'] for r in groups['ball']), sum(r['exact'] for r in groups['contact']), len(non_out),
         len(proof_out), len(vt)))
