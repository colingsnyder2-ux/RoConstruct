"""Verify the inactive native RBX::BodyMover family and RBX::Rocket recovery (2008-06).

Original unit 0062e090..00633101 (+ dynamic initializers 007f7f10..007f85a0, atexit functions 008004xx..00800axx and
the Name::declare COMDATs 005bfaa0..005c0030). Builds (document-swap flags, VS2008 RTM 21022):
  * tests/NativeBodyMoverLayout.cpp     sizeof/offset/base probes (mov eax, imm32; ret);
  * native-classes/BodyMovers.cpp        BodyMover + BodyGyro/Position/Velocity/AngularVelocity/Force/Thrust;
  * native-classes/Rocket.cpp            Rocket (same original unit, split by the file leases);
  * both again with NATIVE_BODYMOVER_PENDING / NATIVE_ROCKET_PENDING against generated headers under
    out/native-layouts/native-body-movers-pending/: declaration-only Workspace.h / Network/Players.h (copies of
    tests/NativeBodyMoverPending*.h) and a copy of native reflection/reflection.h with IIDREF declared novtable.
Unit profile: /fp:fast (Vector3 != in BoundPropGetSet::setValue 00633090 and preventBodySleep 00632370/00632720 is
`fld value; fcomp member`, fucompp without it) and /U_RELEASEASSERT (no RBXASSERT code anywhere in the unit: the
donor KernelIndex destructor assert would add 28 bytes to ~BodyMover 0062e460).

Every row (tests/NativeBodyMoverRows.json) must be relocation-masked exact against the original and every relocation
target is bound to the address the original instruction uses and verified: imports by DLL export name, string
literals by bytes, type descriptors and vtables by original RTTI names, float constants by bytes, own symbols by the
row proven here, descriptor statics / class-name arrays by the DATA map (names by bytes), and the remaining externals
by the explicit EXTERNAL map (cross-checked with offline/evidence.json where it names them). A symbol must bind to one
address in every row. Rows exact only in a pending build are recorded with exact=false and not counted. Vtable slots
are checked on the objects built from current headers. Writes work/2008-06/shared-layouts/body-movers-working.json.
"""
import json
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
MOVERS_SRC = R / 'native-classes/BodyMovers.cpp'
ROCKET_SRC = R / 'native-classes/Rocket.cpp'
MOVERS_H = R / 'native-headers/v8datamodel/BodyMovers.h'
ROCKET_H = R / 'native-headers/v8datamodel/Rocket.h'
LAYOUT = R / 'tests/NativeBodyMoverLayout.cpp'
ROWS = R / 'tests/NativeBodyMoverRows.json'
WORKSPACE_OVERLAY = R / 'tests/NativeBodyMoverPendingWorkspace.h'
PLAYERS_OVERLAY = R / 'tests/NativeBodyMoverPendingPlayers.h'
UNIT = ['/fp:fast', '/U_RELEASEASSERT']

# ---- generated pending headers (copies; shared/donor headers are not edited) -------------------------
pending = OUT / 'native-body-movers-pending'
for sub in ('v8datamodel', 'Network', 'reflection'):
    (pending / sub).mkdir(parents=True, exist_ok=True)
(pending / 'v8datamodel/Workspace.h').write_text(WORKSPACE_OVERLAY.read_text())
(pending / 'Network/Players.h').write_text(PLAYERS_OVERLAY.read_text())
IIDREF_ANCHOR = '\tclass IIDREF\n'
PROPOSAL_IIDREF = '\tclass __declspec(novtable) IIDREF // 2008: RefPropDescriptor ctor 006310d0 stores only the derived IIDREF vptr\n'
reflection = (R / 'native-headers/reflection/reflection.h').read_text()
APPLIED_IIDREF = '\tclass __declspec(novtable) IIDREF\n'  # proposal adopted in the native reflection.h
assert reflection.count(IIDREF_ANCHOR) + reflection.count(APPLIED_IIDREF) == 1
(pending / 'reflection/reflection.h').write_text(reflection.replace(IIDREF_ANCHOR, PROPOSAL_IIDREF))


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


PEND = ['/I' + str(pending)]
layout_obj, layout_flags = build('NativeBodyMoverLayout', LAYOUT)
mov_obj, mov_flags = build('NativeBodyMovers', MOVERS_SRC, UNIT)
movp_obj, movp_flags = build('NativeBodyMoversPending', MOVERS_SRC, UNIT + PEND + ['/DNATIVE_BODYMOVER_PENDING'])
rkt_obj, rkt_flags = build('NativeBodyMoverRocket', ROCKET_SRC, UNIT)
rktp_obj, rktp_flags = build('NativeBodyMoverRocketPending', ROCKET_SRC, UNIT + PEND + ['/DNATIVE_ROCKET_PENDING'])

# ---- layout ---------------------------------------------------------------------------------------
raw = layout_obj.read_bytes()
LAYOUT_VALUES = {
    'moverConnector': 0x130, 'moverListener': 0x138, 'moverWorld': 0x13c, 'moverPart': 0x140,
    'gyroKD': 0x14c, 'gyroMaxTorque': 0x150, 'gyroCFrame': 0x15c,
    'positionMaxForce': 0x150, 'positionPosition': 0x15c, 'positionLastForce': 0x168,
    'velocityMaxForce': 0x14c, 'velocityVelocity': 0x158, 'velocityLastForce': 0x164,
    'angularMaxTorque': 0x14c, 'angularVelocity': 0x158, 'angularLastTorque': 0x164,
    'forceForce': 0x148, 'thrustLocation': 0x154,
    'rocketActive': 0x148, 'rocketTarget': 0x14c, 'rocketTargetOffset': 0x154, 'rocketTargetRadius': 0x160,
    'rocketFiredEvent': 0x164, 'rocketMaxThrust': 0x168, 'rocketMaxSpeed': 0x174, 'rocketMaxTorque': 0x180,
    'rocketCartoonFactor': 0x18c,
    'sizeBodyMover': 0x148, 'sizeBodyGyro': 0x18c, 'sizeBodyPosition': 0x174, 'sizeBodyVelocity': 0x170,
    'sizeBodyAngularVelocity': 0x170, 'sizeBodyForce': 0x154, 'sizeBodyThrust': 0x160, 'sizeRocket': 0x190,
}
layout_funcs = {n: b for n, b, _ in match.coff_functions(raw)}
for key, value in LAYOUT_VALUES.items():
    body = layout_funcs['?nativeBodyMover_%s@@YAIXZ' % key]
    assert body == b'\xb8' + struct.pack('<I', value) + b'\xc3', (key, body.hex())

original = nb.Original()
assert nb.sha(original.path) == json.loads((ROOT / "clients/clients.json").read_text())["2008-06"]["sha256"]
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}


def norm(symbol):
    return symbol.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


STR = 'V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@'
TPD = '@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@'
# ---- externals: address the original instruction uses, read at the call sites listed ----------------
EXTERNAL = {
    '??0Instance@RBX@@QAE@PBD@Z': 0x55b960,                     # BodyMover(const char*) 0062e320
    '??1Instance@RBX@@UAE@XZ': 0x55a540,                        # ~BodyMover 0062e460
    '?onAncestorChanged@Instance@RBX@@UAEXABUAncestorChanged@2@@Z': 0x55acc0,   # 006308f0 (pending)
    '??0Matrix3@G3D@@QAE@ABV01@@Z': 0x513220,                   # copy ctor; evidence names the identical (ICF) operator= here
    '??9CoordinateFrame@G3D@@QBE_NABV01@@Z': 0x4765e0,          # BoundPropGetSet<CoordinateFrame>::setValue 0063b2b0
    '??1?$list@UItem@SignatureDescriptor@Reflection@RBX@@V?$allocator@UItem@SignatureDescriptor@Reflection@RBX@@@std@@@std@@QAE@XZ': 0x4199e0,
    '?raisePropertyChanged@Instance@RBX@@QAEXABVPropertyDescriptor@Reflection@2@@Z': 0x40db00,
    '___RTDynamicCast': 0x6a17c6, '_atexit': 0x6a17af, '__CxxThrowException@8': 0x6a158c,
    '??2@YAPAXI@Z': 0x6a0920, '??3@YAXPAX@Z': 0x6a067a,
    '?declare@Name@RBX@@SAABV12@PBDH@Z': 0x553f90,              # doDeclare 005bfaa0..005bfd40
    '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330,               # getClassName 00630780..00630840, registerBodyMovers
    '??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z': 0x5708f0,
    '??1ClassDescriptor@Reflection@RBX@@UAE@XZ': 0x40abc0,
    '?classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3QBDBVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ': 0x40ad80,
    '??0FunctionDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBDW4Security@012@@Z': 0x595790,
    '??0SignalDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD@Z': 0x56bab0,
    '??0PropertyDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@ABVType@12@PBD2W4Functionality@012@@Z': 0x56c650,
    '??$singleton@X@Type@Reflection@RBX@@SAABV012@XZ': 0x594a50,
    '??$singleton@VVector3@G3D@@@Type@Reflection@RBX@@SAABV012@XZ': 0x56ce60,
    # RefPropDescriptor 006310d0 (pending): one RefType singleton shared by five RefPropDescriptor constructors (type
    # name "Object" 00821634); the native template instantiates it for the class, so the argument is unproven.
    '??$singleton@PAVRocket@RBX@@@RefType@Reflection@RBX@@SAABV012@XZ': 0x583f40,
    '??$shared_from@VPartInstance@RBX@@@RBX@@YA?AV?$shared_ptr@VPartInstance@RBX@@@boost@@PAVPartInstance@0@@Z': 0x618a40,  # ICF with shared_from<Instance> (evidence)
    '??4shared_count@detail@boost@@QAEAAV012@ABV012@@Z': 0x4025b0,                       # setTarget 00632fd0
    '?lock@?$weak_ptr@VPartInstance@RBX@@@boost@@QBE?AV?$shared_ptr@VPartInstance@RBX@@@2@XZ': 0x5cab00,
    '??$create@VRunService@RBX@@@ServiceProvider@RBX@@QBEPAVRunService@1@XZ': 0x4530f0,   # onServiceProvider 00632db0
    '?removeListener@?$Notifier@VRunService@RBX@@VStepped@2@@RBX@@QBEXPAV?$Listener@VRunService@RBX@@VStepped@2@@2@@Z': 0x5e5a80,  # ICF (evidence names a ChildAdded copy)
    '?addListener@?$Notifier@VRunService@RBX@@VStepped@2@@RBX@@QBEXPAV?$Listener@VRunService@RBX@@VStepped@2@@2@@Z': 0x4218a0,     # ICF (evidence names a DescendentAdded copy)
    '?getWorldIfInWorkspace@Workspace@RBX@@SAPAVWorld@2@PBVInstance@2@@Z': 0x5a3390,       # 006308f0 (pending)
    '?findWorkspace@Workspace@RBX@@SAPAV12@PBVInstance@2@@Z': 0x5a3380,                    # fire 0062e1c0 (pending)
    '?clientIsPresent@Players@Network@RBX@@SA_NPBVInstance@3@_N@Z': 0x495e60,             # fire 0062e1c0 (pending)
    '?getKernel@World@RBX@@QAEAAVKernel@2@XZ': 0x5e9150,                                   # 006308f0 (pending)
    '?removeConnector2ndPass@Kernel@RBX@@QAEXPAVConnector@2@@Z': 0x5fad80,                 # donor names; 006308f0 (pending)
    '?insertConnector2ndPass@Kernel@RBX@@QAEXPAVConnector@2@@Z': 0x5fad50,
    '??0runtime_error@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z': 0x409d50,
    '??0CoordinateFrame@G3D@@QAE@XZ': 0x4782d0,                                            # BodyGyro 00632070
    '??$set@VVector3@G3D@@@Value@Reflection@RBX@@QAEXABVVector3@G3D@@@Z': 0x56d1d0,       # execute (not exact)
    # TypedPropertyDescriptor<T> constructors called by the BoundProp ctors
    '??0?$TypedPropertyDescriptor@M' + TPD + 'M@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x445610,
    '??0?$TypedPropertyDescriptor@VVector3@G3D@@' + TPD + 'VVector3@G3D@@@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x59a4b0,
    '??0?$TypedPropertyDescriptor@VCoordinateFrame@G3D@@' + TPD + 'VCoordinateFrame@G3D@@@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x584440,
}
# Descriptor objects (`this` of the dynamic initializers) and the class-name arrays (.data).
DATA = {
    '?prop_Target@Rocket@RBX@@': 0x97cae8, '?prop_targetOffset@Rocket@RBX@@': 0x97c774,
    '?prop_targetRadius@Rocket@RBX@@': 0x97c758, '?prop_MaxSpeed@Rocket@RBX@@': 0x97c8cc,
    '?prop_MaxThrust@Rocket@RBX@@': 0x97c73c, '?prop_ThrustP@Rocket@RBX@@': 0x97c944, '?prop_ThrustD@Rocket@RBX@@': 0x97c928,
    '?prop_TurnP@Rocket@RBX@@': 0x97ca50, '?prop_TurnD@Rocket@RBX@@': 0x97c7ac, '?prop_MaxTorque@Rocket@RBX@@': 0x97c850,
    '?prop_CartoonFactor@Rocket@RBX@@': 0x97c694, '?func_Fire@Rocket@RBX@@': 0x97c870, '?func_Abort@Rocket@RBX@@': 0x97ca70,
    '?event_ReachedTarget@Rocket@RBX@@': 0x97c81c,
    '?prop_kP@BodyGyro@RBX@@': 0x97c678, '?prop_kD@BodyGyro@RBX@@': 0x97c800, '?prop_maxTorque@BodyGyro@RBX@@': 0x97c7c8,
    '?prop_cframe@BodyGyro@RBX@@': 0x97cab0,
    '?prop_kP@BodyPosition@RBX@@': 0x97c6b0, '?prop_kD@BodyPosition@RBX@@': 0x97c790,
    '?prop_maxForce@BodyPosition@RBX@@': 0x97cacc, '?prop_position@BodyPosition@RBX@@': 0x97c704,
    '?func_getLastForceOld@RBX@@': 0x97c638, '?func_getLastForce@RBX@@': 0x97ca10,
    '?prop_kP@BodyVelocity@RBX@@': 0x97c7e4, '?prop_maxForce@BodyVelocity@RBX@@': 0x97c9b4,
    '?prop_velocity@BodyVelocity@RBX@@': 0x97c97c, '?func_getLastForceVOld@RBX@@': 0x97c9d0, '?func_getLastForceV@RBX@@': 0x97c8e8,
    '?prop_kP@BodyAngularVelocity@RBX@@': 0x97c960, '?prop_maxTorque@BodyAngularVelocity@RBX@@': 0x97c6cc,
    '?prop_angularVelocity@BodyAngularVelocity@RBX@@': 0x97c6e8,
    '?prop_Force@BodyForce@RBX@@': 0x97c720, '?prop_force@BodyThrust@RBX@@': 0x97c998, '?prop_location@BodyThrust@RBX@@': 0x97c8b0,
    '?sBodyPosition@RBX@@3PADA': 0x95c6e8, '?sBodyVelocity@RBX@@3PADA': 0x95c6f8, '?sBodyGyro@RBX@@3PADA': 0x95c708,
    '?sBodyAngularVelocity@RBX@@3PADA': 0x95c714, '?sBodyForce@RBX@@3PADA': 0x95c728, '?sBodyThrust@RBX@@3PADA': 0x95c734,
    '?sRocket@RBX@@3PADA': 0x95c740,
    '_func_getLastForceOld': 0x97c638, '_func_getLastForce': 0x97ca10, '_func_getLastForceVOld': 0x97c9d0,
    '_func_getLastForceV': 0x97c8e8,
}
NAMES = {0x95c6e8: 'BodyPosition', 0x95c6f8: 'BodyVelocity', 0x95c708: 'BodyGyro', 0x95c714: 'BodyAngularVelocity',
         0x95c728: 'BodyForce', 0x95c734: 'BodyThrust', 0x95c740: 'RocketPropulsion'}

LOCAL_EH = nb.LOCAL_EH
binding = {}   # symbol -> (address, row) for the one-address-per-symbol check
unbound = {}


def resolve(obj, rows):
    raw = Path(obj).read_bytes()
    funcs = match.coff_functions(raw)
    out = []
    for address, key in rows:
        hits = [x for x in funcs if x[0] == key] or [x for x in funcs if x[0].startswith(key)
                                                       and not LOCAL_EH.match(x[0])]
        assert len(hits) == 1, (address, key, [h[0] for h in hits])
        out.append((int(address, 16), hits[0][0]))
    return out


def data_key(symbol):
    if symbol in DATA:
        return symbol
    hits = [k for k in DATA if symbol.startswith(k)]
    return hits[0] if len(hits) == 1 else None


def verify(obj, rows, own):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    result = []
    for address, name in rows:
        body, refs = bodies[name]
        target, target_refs, _ = match.target('2008-06', '%08x' % address)
        assert match.exact_match(target, target_refs, body, refs), (name, hex(address), len(body), len(target))
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
            elif symbol.startswith('??_7'):
                rtti, at = original.vtable_class(value)
                cls = symbol[4:symbol.index('@@6B') + 2]
                assert norm(rtti) == norm('.?AV' + cls), (name, symbol, hex(value), rtti)
                how = 'vtable RTTI %s offset %#x' % (rtti, at)
            elif symbol in own:
                assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
                how = 'own row'
            elif symbol.startswith('??_E') and own.get('??_G' + symbol[4:]) == value:
                how = 'vector deleting dtor folded into the ??_G row'
            elif symbol.startswith('__TI') and '?AV' in symbol:
                # _ThrowInfo: pCatchableTypeArray +12 -> first CatchableType -> TypeDescriptor name
                cta = struct.unpack('<I', original.data(value + 12, 4))[0]
                ct = struct.unpack('<I', original.data(cta + 4, 4))[0]
                rtti = original.string(struct.unpack('<I', original.data(ct + 4, 4))[0] + 8)
                assert rtti == '.' + symbol[symbol.index('?AV'):], (name, symbol, hex(value), rtti)
                how = 'throw info %s' % rtti
            elif symbol.startswith('__real@'):
                literal = bytes.fromhex(symbol[7:])[::-1]
                assert original.data(value, len(literal)) == literal, (name, symbol, hex(value))
                how = 'float constant'
            elif data_key(symbol):
                assert DATA[data_key(symbol)] == value, (name, symbol, hex(value))
                if value in NAMES:
                    assert original.string(value) == NAMES[value], (symbol, hex(value))
                how = 'data'
            elif EXTERNAL.get(symbol) is not None:
                assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
                how = 'external' + (' (evidence name)' if norm(names.get(value, '')) == norm(symbol) else '')
            elif symbol.startswith('?$S') or symbol.startswith('??_B?1') or '?$TSS' in symbol or symbol.startswith('?flag@') \
                    or symbol.startswith('?foo@') or symbol.startswith('?n@?1??') or symbol.startswith('?v@?1??') or symbol.startswith('?type@?1??'):
                how = 'local static'
            else:
                unbound.setdefault(symbol, set()).add((hex(value), name[:60]))
                continue
            prev = binding.setdefault(symbol, (value, name))
            assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
            verified[symbol] = '%s (%s)' % (hex(value), how)
        result.append({'address': '%08x' % address, 'symbol': name, 'size': len(body), 'exact': True,
                       'verified_targets': verified, 'local_eh': sorted(local)})
    return result


ROWSET = json.loads(ROWS.read_text())
groups = [('movers', mov_obj, ROWSET['movers']), ('rocket', rkt_obj, ROWSET['rocket']),
          ('movers_pending', movp_obj, ROWSET['movers_pending']), ('rocket_pending', rktp_obj, ROWSET['rocket_pending'])]
resolved = [(g, obj, resolve(obj, rows)) for g, obj, rows in groups]
own = {}
for _, _, rows in resolved:
    for address, name in rows:
        own.setdefault(name, address)
results = {g: verify(obj, rows, own) for g, obj, rows in resolved}
assert not unbound, '\n'.join('%s -> %s' % (k, sorted(v)) for k, v in sorted(unbound.items()))

# Rows of a pending build are exact only against generated header copies: exact=false, not counted.
plain_exact = {r['address'] for g, v in results.items() if not g.endswith('_pending') for r in v}
for g, v in results.items():
    if g.endswith('_pending'):
        for r in v:
            assert r['address'] not in plain_exact, r['address']
            r['exact'] = False
            r['status'] = 'pending-build-only'

# ---- vtables, RTTI, allocation sizes and strings (binary facts) ---------------------------------------
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
PRIMARY = {'BodyMover': 0x846bec, 'BodyGyro': 0x847aa4, 'BodyPosition': 0x847b9c, 'BodyVelocity': 0x847c8c,
           'BodyAngularVelocity': 0x847d7c, 'BodyForce': 0x847e6c, 'BodyThrust': 0x847f5c, 'Rocket': 0x84816c}
for cls, vt in PRIMARY.items():
    assert original.vtable_class(vt) == ('.?AV%s@RBX@@' % cls, 0), cls
for cls, slot16 in (('BodyMover', 0x565950), ('BodyGyro', 0x565950), ('BodyPosition', 0x565950), ('Rocket', 0x565950),
                    ('BodyVelocity', 0x632370), ('BodyAngularVelocity', 0x632370), ('BodyForce', 0x632720),
                    ('BodyThrust', 0x632720)):
    assert d(PRIMARY[cls] + 64) == slot16, cls
    assert (d(PRIMARY[cls] + 12), d(PRIMARY[cls] + 16), d(PRIMARY[cls] + 48)) == (0x62e190, 0x6308f0, 0x632db0), cls
# The 2008 Connector vtable 0083d1f4 has six slots (dtor, computeForce pure, 00565950, 0060a2f0, pure, 005e72c0
# potentialEnergy); BodyMover's 00846b54 overrides slot 4 with 0062fa10.
assert original.vtable_class(0x83d1f4) == ('.?AVConnector@RBX@@', 0)
assert [d(0x83d1f4 + 4 * i) for i in (2, 3, 5)] == [0x565950, 0x60a2f0, 0x5e72c0]
assert d(0x83d1f4 + 4) == d(0x83d1f4 + 16) == 0x6a16be                   # _purecall
assert [d(0x846b54 + 4 * i) for i in (2, 3, 4, 5)] == [0x565950, 0x60a2f0, 0x62fa10, 0x5e72c0]
assert d(0x846b48) == 0x62fae0 and d(0x8480c4) == 0x632e10   # Listener onEvent: BodyMover, Rocket
for factory, size, ctor in ((0x5c1a00, 0x18c, 0x632070), (0x5c2150, 0x174, 0x632190), (0x5c23c0, 0x170, 0x632290),
                            (0x5c2630, 0x170, 0x632400), (0x5c1c70, 0x154, 0x6324f0), (0x5c1ee0, 0x160, 0x6325e0),
                            (0x5c28a0, 0x190, 0x632b50)):
    body, _, _ = match.target('2008-06', '%08x' % factory)
    assert b'\x68' + struct.pack('<I', size) in body, hex(factory)
    call = body.index(b'\xe8', body.index(b'\x68' + struct.pack('<I', size)) + 5)
    while (factory + call + 5 + struct.unpack_from('<i', body, call + 1)[0]) & 0xffffffff != ctor:
        call = body.index(b'\xe8', call + 1)
for address, text in list(NAMES.items()) + [(0x8481b0, 'Target'), (0x8481b8, 'Goals'), (0x848254, 'ReachedTarget'),
                                           (0x8482bc, 'angularvelocity'), (0x8482a0, 'GetLastForce')]:
    assert original.string(address) == text, (hex(address), text)


def bases(vtable):
    hierarchy = d(d(vtable - 4) + 16)
    out = {}
    for i in range(d(hierarchy + 8)):
        bcd = d(d(hierarchy + 12) + 4 * i)
        out[original.string(d(bcd) + 8)] = struct.unpack('<i', original.data(bcd + 8, 4))[0]
    return out


mb = bases(0x846bec)
assert (mb['.?AVConnector@RBX@@'], mb['.?AVKernelIndex@RBX@@'], mb['.?AV?$Listener@VRunService@RBX@@VStepped@2@@RBX@@']) == (0x130, 0x134, 0x138)
for cls in PRIMARY:
    if cls != 'BodyMover':
        assert '.?AVBodyMover@RBX@@' in bases(PRIMARY[cls]), cls
        assert '.?AV?$DescribedCreatable@V%s@RBX@@VBodyMover@2@$1?s%s@2@3PADA@RBX@@' % (cls, cls) in bases(PRIMARY[cls]), cls


# ---- vtable slots of the objects built from current headers -------------------------------------------
def vtable_slots(obj, symbol):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    start, index = definitions[symbol]
    section = sections[index]
    slots = {}
    for i in range(section[7]):
        offset, sym, kind = struct.unpack_from('<IIH', raw, section[5] + 10 * i)
        if offset >= start and kind == 6:
            slots[(offset - start) // 4] = symbols[sym][0]
    return slots


def find_vtable(obj, prefix):
    raw = Path(obj).read_bytes()
    _, _, definitions, _ = match._coff_data_index(raw)
    hits = [n for n in definitions if n.startswith(prefix)]
    assert len(hits) == 1, (prefix, hits)
    return hits[0]


pending_set = {r['address'] for v in results.values() for r in v if not r['exact']}
vtables = []
for cls, vt in PRIMARY.items():
    obj = rkt_obj if cls == 'Rocket' else mov_obj
    sym = find_vtable(obj, '??_7%s@RBX@@6B?$GuidItem@' % cls)
    slots = vtable_slots(obj, sym)
    assert sorted(slots) == list(range(17)), (cls, slots)
    entries = {}
    for slot, symbol in sorted(slots.items()):
        value = d(vt + 4 * slot)
        if symbol in own or (symbol.startswith('??_E') and '??_G' + symbol[4:] in own):
            assert own.get(symbol, own.get('??_G' + symbol[4:])) == value, (cls, slot, symbol, hex(value))
            how = 'pending-build-only row' if '%08x' % value in pending_set else 'own row'
        elif EXTERNAL.get(symbol) is not None or norm(names.get(value, '')) == norm(symbol):
            how = 'external'
        elif names.get(value) and names[value].split('@@')[0] == symbol.split('@@')[0]:
            how = 'external (evidence name; access mangling differs)'
        else:
            how = 'unverified (no row)'
        prev = binding.setdefault(symbol, (value, sym))
        assert prev[0] == value, ('inconsistent vtable slot', cls, slot, symbol, hex(prev[0]), hex(value))
        entries[slot] = '%s -> %s (%s)' % (symbol, hex(value), how)
    vtables.append({'class': cls, 'vtable': hex(vt), 'slots': entries})
# Listener<RunService, Stepped> vtable: {onEvent, destructor thunk}.
for cls, vt in (('BodyMover', 0x846b48), ('BodyGyro', 0x8479f4), ('Rocket', 0x8480c4)):
    obj = rkt_obj if cls == 'Rocket' else mov_obj
    sym = find_vtable(obj, '??_7%s@RBX@@6B?$Listener@' % cls)
    slots = vtable_slots(obj, sym)
    assert sorted(slots) == [0, 1], (cls, slots)
    assert slots[0] == '?onEvent@%s@RBX@@MAEXPBVRunService@2@VStepped@2@@Z' % ('Rocket' if cls == 'Rocket' else 'BodyMover'), slots
    assert own[slots[1]] == d(vt + 4), (cls, slots[1])
# Connector subobject: the current headers (donor v8kernel/Connector.h) give five slots; the binary has six.
con = vtable_slots(mov_obj, find_vtable(mov_obj, '??_7BodyMover@RBX@@6BConnector@'))
assert sorted(con) == list(range(5)) and own[con[0]] == d(0x846b54), con
connector_note = ('current headers: %d Connector slots %s; binary 00846b54 has 6 (slot 4 0062fa10 getBody-like override, '
                  'see proposal)' % (len(con), [con[i] for i in sorted(con)]))

sha = nb.sha
paths = [Path(__file__).resolve(), MOVERS_H, ROCKET_H, MOVERS_SRC, ROCKET_SRC, LAYOUT, ROWS, WORKSPACE_OVERLAY, PLAYERS_OVERLAY]
objs = (layout_obj, mov_obj, movp_obj, rkt_obj, rktp_obj)
exact_addresses = sorted({r['address'] for v in results.values() for r in v if r['exact']})
pending_addresses = sorted({r['address'] for v in results.values() for r in v if not r['exact']})
NOT_RECOVERED = {
    '006328f0': 'BoundFuncDesc<BodyPosition, Vector3()>::execute: stack frame 0xc vs 0x18 (native reflection.h template lets the bad_cast and the Vector3 temporaries share one slot)',
    '006329e0': 'BoundFuncDesc<BodyVelocity, Vector3()>::execute: same as 006328f0',
    '0062fa10': 'BodyMover Connector slot 4 (getBody-like, int argument): needs the 2008 Connector vtable and Primitive at PartInstance+0x228',
    '0062fae0': 'BodyMover::onEvent: World::ticklePrimitive(Primitive*, bool) 005e9410 on PartInstance+0x228 (Primitive embedded, native PartInstance.h has a scoped_ptr)',
    '00632e10': 'Rocket::onEvent: same dependencies as 0062fae0 plus the ReachedTarget signal fire',
    '006300d0': 'BodyGyro::computeForce', '0062ec40': 'BodyGyro::computeBalance', '0062e910': 'BodyGyro::computeOrientation',
    '00630140': 'BodyPosition::computeForce', '006302d0': 'BodyVelocity::computeForce', '00630420': 'BodyAngularVelocity::computeForce',
    '00630570': 'BodyForce::computeForce', '00630610': 'BodyThrust::computeForce', '0062fc00': 'Rocket::computeForce',
    '0062e530': 'Rocket::turn',
    '0062e100': 'Body::getBranchIBodyV3 (inline Body helper)', '0062e140': 'Body helper (accumulateTorque-like)',
    '0062e2a0': 'Body helper (getBranchForce-like)', '0062e2e0': 'Body helper (getBranchTorque-like)',
}
receipt = {
    'class': 'RBX::BodyMover, BodyGyro, BodyPosition, BodyVelocity, BodyAngularVelocity, BodyForce, BodyThrust, Rocket',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)', 'unit_profile': UNIT,
    'original_sha256': nb.sha(original.path),
    'flags': {'layout': layout_flags, 'movers': mov_flags, 'movers_pending': movp_flags, 'rocket': rkt_flags,
              'rocket_pending': rktp_flags},
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in objs},
    'layout': {k: hex(v) for k, v in LAYOUT_VALUES.items()},
    'exact_addresses': exact_addresses,
    'pending_build_only_addresses': pending_addresses,
    'not_recovered': NOT_RECOVERED,
    'rows': results,
    'vtables': vtables, 'connector_vtable': connector_note,
    'proposal_reflection_h': PROPOSAL_IIDREF,
    'proposals': [
        'native v8kernel/Connector.h (kernel owner): the 2008 Connector vtable 0083d1f4 has six slots: virtual ~Connector(); '
        'virtual void computeForce(const float dt, bool throttling) = 0; a bool virtual returning true (00565950, donor '
        'canThrottle returns false); virtual bool getBroken() {return false;} (0060a2f0); a new pure virtual taking one '
        'int and returning the part body (BodyMover 0062fa10: index 0 && part.lock() ? part->primitive.body (+0x228+0xa0) : 0; '
        'name provisional, e.g. Body* getBody(int)); virtual float potentialEnergy() {return 0;} (005e72c0). KernelIndex '
        'destructor without RBXASSERT. With it the BodyMover Connector vtable (00846b54) can be checked slot by slot.',
        'reflection/reflection.h (reflection owner): declare IIDREF __declspec(novtable) (RefPropDescriptor constructor '
        '006310d0 stores only the RefPropDescriptor IIDREF vptr 008473dc; exact against a generated copy). The RefType '
        'singleton it calls (00583f40, type name "Object") is shared by five RefPropDescriptor constructors, so the 2008 '
        'template does not instantiate RefType::singleton<Class*>; argument unproven.',
        'reflection/reflection.h: BoundFuncDesc<C, R(), 0>::execute for a Vector3 result (006328f0, 006329e0) keeps the '
        'bad_cast and the result temporaries in separate stack slots (frame 0x18; native template gives 0xc).',
        'native v8datamodel/Workspace.h (findWorkspace 005a3380, getWorldIfInWorkspace 005a3390) and Network/Players.h '
        '(clientIsPresent 00495e60): the donor headers fail with C2440 (&sName). Declaration-only overlays: '
        'tests/NativeBodyMoverPendingWorkspace.h, tests/NativeBodyMoverPendingPlayers.h.',
        'v8tree/Instance.h now owns AncestorChanged (three pointers, 12 bytes); consumers share its definition.',
        'native v8datamodel/PartInstance.h: Primitive embedded at +0x228 (BodyMover::onEvent 0062fae0 passes part+0x228 to '
        'World::ticklePrimitive(Primitive*, bool) 005e9410), not boost::scoped_ptr; needed for onEvent, getBody and every '
        'computeForce.',
    ],
    'pending_note': 'pending-build-only rows: BodyMover::onAncestorChanged 006308f0 (declaration-only Workspace.h), '
                    'Rocket::fire 0062e1c0 (Workspace.h + Network/Players.h), RefPropDescriptor<Rocket, PartInstance> '
                    'constructor 006310d0 (IIDREF novtable in a reflection.h copy). Not counted as exact.',
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/body-movers-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native BodyMover family + Rocket: %d distinct addresses exact (%s), %d pending-build-only (not counted), '
      '%d not recovered; targets and vtables verified' % (
          len(exact_addresses), ', '.join('%s %d rows' % (g, sum(r['exact'] for r in v)) for g, v in results.items()),
          len(pending_addresses), len(NOT_RECOVERED)))
