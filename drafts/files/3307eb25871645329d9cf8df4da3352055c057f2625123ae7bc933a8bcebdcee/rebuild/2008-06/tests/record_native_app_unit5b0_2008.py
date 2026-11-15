"""Verify the inactive 2008-06 native rows of the application range 005b0000..005bc000, and record the unit map of the
range (boundary evidence in the receipt's `unit_map`; rows counted by other receipts are listed there as text).

Unit map summary (details in UNIT_MAP below):
  * ScriptContext unit tail ..005b071f (script/ScriptContext owners; not built here).
  * Accoutrement unit 005b0820..005b2ebf (v8datamodel/Accoutrement.cpp): built here from
    native-classes/AppUnit5B0_2008Accoutrement.cpp against the committed native v8datamodel/Accoutrement.h
    (read-only), plus the committed native-classes/Accoutrement.cpp (appearance owner, read-only, compiled unchanged)
    for the two child-loop overrides it already defines.
  * BrickColor unit 005b2ec0..005b658f (util/BrickColor.cpp: BrickMap and its std::map instantiations).
  * Sound unit 005b65a0..005bbfff (util/Sound.cpp / SoundService: FMOD error strings, Sound / SoundService / StockSound
    descriptors), continuing past 005bc000.

Build: document-swap flags, VS2008 RTM 21022, /fp:fast (the G3D x87 order of the setAttachment* bodies needs it).
Pending build: the same source with NATIVE_APPUNIT5B0_PENDING and a generated copy of v8datamodel/Accoutrement.h
(proposed declarations: writeUnlocked and the state-machine members) under out/app-unit5b0-2008/pending/; its rows
are recorded exact=false (pending-build-only) and never counted. Vtable checks use the current-header object.

Every counted row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the
address the original instruction uses and verified: imports by DLL export name, constants and string literals by
bytes, RTTI type descriptors by name, own symbols by the row proven here, COMDAT support bodies by exactness at the
bound address, the remaining externals by the explicit EXTERNAL map (evidence name or a row counted by another
receipt), static data by one address per symbol. A row is counted only when no other receipt counts it.
Writes work/2008-06/shared-layouts/app-unit5b0-2008-working.json.
Set NATIVE_APP_UNIT5B0_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
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
OUT = nb.OUT / 'app-unit5b0-2008'
OUT.mkdir(parents=True, exist_ok=True)
SOURCE = R / 'native-classes/AppUnit5B0_2008Accoutrement.cpp'
OWNER_SOURCE = R / 'native-classes/Accoutrement.cpp'          # appearance owner, compiled read-only
HEADER = R / 'native-headers/v8datamodel/Accoutrement.h'
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT5B0_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit5b0-2008-working.json'

# ---- generated pending copy of v8datamodel/Accoutrement.h (proposal; never in the committed tree) ------------------
PENDING_DIR = OUT / 'pending'
(PENDING_DIR / 'v8datamodel').mkdir(parents=True, exist_ok=True)
PENDING_DECL = '''\t\t// proposal (app-unit5b0): state machine members and the write lock
\t\tAccoutrementState computeDesiredState()                           // inlined into 005b10a0
\t\t{
\t\t\tif (!getHandleConst())
\t\t\t\treturn NOTHING;
\t\t\tif (!Workspace::contextInWorkspace(this))
\t\t\t\treturn HAS_HANDLE;
\t\t\treturn computeDesiredState(getParent());
\t\t}
\t\tAccoutrementState computeDesiredState(Instance* testParent)       // inlined into 005b10a0
\t\t{
\t\t\tHumanoid* humanoid = Humanoid::modelIsCharacter(testParent);
\t\t\tif (!humanoid)
\t\t\t\treturn IN_WORKSPACE;
\t\t\tif (!humanoid->getTorso())
\t\t\t\treturn NOTHING;
\t\t\treturn EQUIPPED;
\t\t}
\t\tvoid updateDesiredState();                                        // 005b10a0
\t\tvoid setDesiredState(AccoutrementState desiredState, const ServiceProvider* serviceProvider);   // 005b2510
\tpublic:
\t\tstatic bool writeUnlocked;                                        // 00976cad
\tprotected:
'''
text = HEADER.read_text()
ANCHOR = '\t\tvoid downFrom_InCharacter();                                     // 005b0920\n'
INC = '#include "util/ISelectable3d.h"\n'
assert text.count(ANCHOR) == 1 and text.count(INC) == 1
text = text.replace(ANCHOR, ANCHOR + PENDING_DECL).replace(
    INC, INC + '#include "v8datamodel/Workspace.h"\n#include "humanoid/Humanoid.h"\n')
(PENDING_DIR / 'v8datamodel/Accoutrement.h').write_text(text)


def build(name, src, extra=(), include_first=()):
    obj = OUT / (name + '.obj')
    flags = list(include_first) + nb.flags() + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


OBJ, FLAGS = {}, {}
OBJ['accoutrement'], FLAGS['accoutrement'] = build('NativeAppUnit5B0_2008_accoutrement', SOURCE, ['/fp:fast'])
OBJ['owner'], FLAGS['owner'] = build('NativeAppUnit5B0_2008_owner_accoutrement', OWNER_SOURCE, ['/fp:fast'])
OBJ['pending'], FLAGS['pending'] = build('NativeAppUnit5B0_2008_accoutrement_pending', SOURCE,
                                         ['/fp:fast', '/DNATIVE_APPUNIT5B0_PENDING'], ['/I' + str(PENDING_DIR)])

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}

# ---- externals: address the original instruction uses -------------------------------------------------------------
EXTERNAL = {
    '?findFirstChildByName@Instance@RBX@@QBEPAV12@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': 0x557950,   # getHandleConst 005b08e7
    '?getCoordinateFrame@PartInstance@RBX@@QBEABVCoordinateFrame@G3D@@XZ': 0x598cb0,      # getLocation 005b0b8e
    '??0CoordinateFrame@G3D@@QAE@XZ': 0x4782d0,                                            # getLocation 005b0b99 (humanoid2008)
    '??0Matrix3@G3D@@QAE@ABV01@@Z': 0x513220,                                              # G3D library body (CoordinateFrame copy)
    '?getColumn@Matrix3@G3D@@QBE?AVVector3@2@H@Z': 0x513240,                               # G3D library body
    '?setColumn@Matrix3@G3D@@QAEXHABVVector3@2@@Z': 0x513260,                              # G3D library body
    '?unitize@Vector3@G3D@@QAEMM@Z': 0x518470,                                             # G3D library body (tolerance 1e-6)
    '??$find@VWorkspace@RBX@@@ServiceProvider@RBX@@SAPAVWorkspace@1@PBVInstance@1@@Z': 0x491e50,   # setAttachmentPoint 005b26b1 (app-unit5a0 map)
    '?raisePropertyChanged@Instance@RBX@@QAEXABVPropertyDescriptor@Reflection@2@@Z': 0x40db00,
    # setAttachmentPoint 005b26eb: weld (IEquipable +4 = +0x134) ->setC1; the native JointInstance.h declares setC1 on
    # AutoJoint (same binding as the other receipts that call 005e44c0)
    '?setC1@AutoJoint@RBX@@QAEXABVCoordinateFrame@G3D@@@Z': 0x5e44c0,
    # pending build only
    '?write@Instance@RBX@@UAEPAVXmlElement@@XZ': 0x558c50,                                 # app-unit558 map
    '??$?0VInstanceHandle@RBX@@@XmlElement@@QAE@ABVName@RBX@@VInstanceHandle@2@@Z': 0x417510,   # write 005b14d8 (app-unit558 map)
    '??0InstanceHandle@RBX@@QAE@PAVInstance@1@@Z': 0x594e00,
    '??2@YAPAXI@Z': 0x6a0920,
    '?findServiceProvider@ServiceProvider@RBX@@SAPBV12@PBVInstance@2@@Z': 0x4898d0,
    '?backendProcessing@Players@Network@RBX@@SA_NPBVInstance@3@_N@Z': 0x495eb0,
    '?onAncestorChanged@Instance@RBX@@UAEXABUAncestorChanged@2@@Z': 0x55acc0,
    '?contextInWorkspace@Workspace@RBX@@SA_NPBVInstance@2@@Z': 0x5a33d0,                  # app-unit5a0
    '?modelIsCharacter@Humanoid@RBX@@SAPAV12@PBVInstance@2@@Z': 0x5d9a20,
    '?getTorso@Humanoid@RBX@@QBEPAVPartInstance@2@XZ': 0x5d8b10,
    '?setDesiredState@Accoutrement@RBX@@IAEXW4AccoutrementState@12@PBVServiceProvider@2@@Z': 0x5b2510,   # this range (not built)
    '?tag_External@@3ABVName@RBX@@B': 0x975358,
}
# COMDAT bodies emitted in the unit object whose call target is out of line in the original: accepted only when the
# compiled body is relocation-masked exact at the bound address (support rows, never counted here).
SUPPORT = {
    '??9CoordinateFrame@G3D@@QBE_NABV01@@Z': 0x4765e0,                                    # setAttachmentPoint 005b2684
    '?raise@?$Notifier@VWorkspace@RBX@@VDrawChanged@2@@RBX@@IBEXVDrawChanged@2@@Z': 0x576940,   # raiseDrawChanged (DataModel range)
}
# static data: one address per symbol
LOCAL_STATIC_AT = {
    '_prop_AttachmentPoint': 0x976d20,           # file-static descriptor raised by setAttachmentPoint 005b26d2
    '?writeUnlocked@Accoutrement@RBX@@2_NA': 0x976cad,
}
UNBOUND = []
binding = {}
support_out = {}

# (address, symbol or unique prefix): one entry per counted address
ROWS = {
    'accoutrement': [
        (0x005b08a0, '?getHandleConst@Accoutrement@RBX@@QBEPBVPartInstance@2@XZ'),
        (0x005b0b70, '?getLocation@Accoutrement@RBX@@MBE?BVCoordinateFrame@G3D@@XZ'),
        (0x005b2670, '?setAttachmentPoint@Accoutrement@RBX@@QAEXABVCoordinateFrame@G3D@@@Z'),
        (0x005b2750, '?setAttachmentForward@Accoutrement@RBX@@QAEXABVVector3@G3D@@@Z'),
        (0x005b28d0, '?setAttachmentUp@Accoutrement@RBX@@QAEXABVVector3@G3D@@@Z'),
        (0x005b2a40, '?setAttachmentRight@Accoutrement@RBX@@QAEXABVVector3@G3D@@@Z'),
    ],
    'owner': [
        (0x005b0fa0, '?onCameraNear@Accoutrement@RBX@@UAEXM@Z'),
        (0x005b1020, '?render3dSelect@Accoutrement@RBX@@MAEXPAVAdorn@2@W4SelectState@2@@Z'),
    ],
}
# rows built in this unit that are not exact (recorded, never counted)
NEAR = {
    'accoutrement': [
        (0x005b0840, '?readProperty@Accoutrement@RBX@@MAEXPBVXmlElement@@AAVIReferenceBinder@2@@Z'),
    ],
}
PENDING_ROWS = [
    (0x005b1480, '?write@Accoutrement@RBX@@UAEPAVXmlElement@@XZ'),
    (0x005b10a0, '?updateDesiredState@Accoutrement@RBX@@IAEXXZ'),
    (0x005b25f0, '?onAncestorChanged@Accoutrement@RBX@@MAEXABUAncestorChanged@2@@Z'),
]
REJECTED = {
    'readProperty 005b0840 (donor body: nested ifs, name->toString() == "BackendAccoutrementState")': (
        '96/96 B, register allocation only: edx/eax swapped for the string pointer and the binder argument'),
    'readProperty with one combined condition (getValue && ==)': 'same 96 B register swap',
    'readProperty with negated condition and a single Instance::readProperty call': 'same 96 B register swap',
    'readProperty with a `const std::string&` local for toString()': 'same 96 B register swap',
    'the unit without /fp:fast': 'setAttachmentForward 391/376 B, setAttachmentUp / Right 344 B',
    'setAttachmentUp: donor-shape locals (oldX / oldZ, z = oldX.cross(y), x = y.cross(z))': '368/366 B (x87 order)',
    'setAttachmentUp: reuse x for the old column (x = col0; z = x.cross(y); x = y.cross(z))': '376/366 B',
    'setAttachmentUp: z = -y.cross(oldX)': '374/366 B',
    'setAttachmentUp: x = -z.cross(y)': '380/366 B',
    'setAttachmentUp: copy of the old column only (oldX = col0) with copies in the second cross': '368/366 B',
    'setAttachmentUp: copy of y only in the first cross, copies in the second': '364/366 B',
    'setAttachmentUp: copies in the first cross only': '368/366 B and 372/366 B (order of the two copies)',
    'setAttachmentUp: copies in the second cross only': '364/366 B',
    'setAttachmentRight with the donor setAttachmentForward shape (no copies)': '370/364 B',
    'updateDesiredState (pending) with one combined inline computeDesiredState (?: on getTorso)': (
        '98/100 B: the state lands in esi instead of being returned through eax; the two-level inline returns match'),
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
        elif support_key(symbol):
            assert SUPPORT[support_key(symbol)] == value, (name, symbol, hex(value))
            sbody, srefs = bodies[symbol]
            starget, strefs = target_of(value)
            assert match.exact_match(starget, strefs, sbody, srefs), ('support body not exact', symbol, hex(value))
            support_out[symbol] = '%#x (support body exact at the bound address, not counted here)' % value
            how = 'support body exact at the bound address'
        elif symbol in EXTERNAL:
            assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
            how = 'external' + (' (evidence name)' if names.get(value, '') == symbol else '')
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
near = {k: verify(k, resolve(OBJ[k], rows), own, strict=False, record=False) for k, rows in NEAR.items()}
for k, rows in near.items():
    for r in rows:
        assert not r['exact'], ('near-miss row became exact: move it to ROWS', r['address'])
pending_resolved = resolve(OBJ['pending'], PENDING_ROWS)
pending_own = dict(own)
pending_own.update({name: address for address, name in pending_resolved})
pending = verify('pending', pending_resolved, pending_own, strict=False, record=False)
assert all(r['exact'] for r in pending) or DISCOVER, [(r['address'], r['exact']) for r in pending]


def vtable_slots(obj_path, candidates):
    """Every Accoutrement vtable of the current-header object (native Accoutrement.cpp defines the constructor) is
    matched to the original vtable of the same RTTI class with the same slot count whose bound slots agree; a slot
    whose function is a row proven here must hold that row's address."""
    raw = Path(obj_path).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    known = dict(own)
    known.update(EXTERNAL)
    code_range = range(0x401000, 0x7e0000)
    out = {}
    for symbol in sorted(s for s in definitions if s.startswith('??_7Accoutrement@RBX@@6B')):
        start, sec = definitions[symbol]
        table = sections[sec]
        relocs = sorted((struct.unpack_from('<IIH', raw, table[5] + 10 * k)) for k in range(table[7]))
        slots = [(off - start, symbols[idx][0]) for off, idx, kind in relocs if kind == 6 and off >= start]
        slots = [x for x in slots if x[0] < table[3] - start]
        # subobject offset / constructor-displacement offset from the compiled complete-object locator
        col = [symbols[idx][0] for off, idx, kind in relocs if kind == 6 and off == start - 4]
        assert len(col) == 1 and col[0].startswith('??_R4'), (symbol, col)
        cstart, csec = definitions[col[0]]
        cpos = sections[csec][4] + cstart
        sub_offset, cd_offset = struct.unpack_from('<II', raw, cpos + 4)
        matches = []
        for address in candidates:
            locator = struct.unpack('<I', original.data(address - 4, 4))[0]
            if struct.unpack('<II', original.data(locator + 4, 8)) != (sub_offset, cd_offset):
                continue
            originals = [struct.unpack('<I', original.data(address + 4 * k, 4))[0] for k in range(len(slots) + 1)]
            if not (all(v in code_range for v in originals[:-1]) and originals[-1] not in code_range):
                continue
            checked, ok = [], True
            for off, target_symbol in slots:
                expect = known.get(target_symbol)
                value = originals[off // 4]
                if expect is not None:
                    if expect != value:
                        ok = False
                        break
                    checked.append('%d %s = %#x' % (off // 4, target_symbol[:80], value))
            if ok:
                matches.append((address, checked))
        assert len(matches) == 1, ('vtable match', symbol, [hex(a) for a, _ in matches])
        address, checked = matches[0]
        out[symbol] = {'address': '%#x' % address, 'subobject_offset': '%#x' % sub_offset, 'slots': len(slots),
                       'checked_bound_slots': checked}
    return out


# original Accoutrement vtables: the vptr stores of Accoutrement() 005b2230 (counted by appearance-working.json)
ctor, ctor_refs = target_of(0x5b2230)


def rtti_class(value):
    try:
        return original.vtable_class(value)[0]
    except Exception:
        return None


CANDIDATES = sorted({v for v in (struct.unpack_from('<I', ctor, r)[0] for r in ctor_refs)
                     if 0x7e0000 <= v < 0x900000 and rtti_class(v) == '.?AVAccoutrement@RBX@@'})
vtables = vtable_slots(OBJ['owner'], CANDIDATES)
# The ICameraSubject / ILocation slots hold vtordisp thunks (counted by appearance-working.json): their bodies are
# compared here at their own addresses and their jump targets must bind to the rows counted here.
THUNKS = [
    (0x005b1470, '?onCameraNear@Accoutrement@RBX@@$4PPPPPPPM@A@AEXM@Z'),
    (0x005b0f90, '?getLocation@Accoutrement@RBX@@$2PPPPPPPM@A@BE?BVCoordinateFrame@G3D@@XZ'),
]
thunks = verify('owner', resolve(OBJ['owner'], THUNKS), own, record=False)
for r in thunks:
    assert r['exact'] and any('own row' in v for v in r.get('verified_targets', {}).values()), r
thunk_out = ['%s %s: exact, jumps to a row counted here (counted by appearance-working.json, support only)'
             % (r['address'], r['symbol'][:70]) for r in thunks]
bound_rows = {int(c.split(' = ')[1], 16) for v in vtables.values() for c in v['checked_bound_slots']}
assert 0x5b1020 in bound_rows or DISCOVER, 'render3dSelect not in the IRenderable vtable'

if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for g, rows in list(groups.items()) + [('near', sum(near.values(), [])), ('pending', pending)]:
        for r in rows:
            print('EXACT' if r['exact'] else 'NOT EXACT', g, r['address'], r['symbol'][:90], r['size'], r['target_size'])
    print(json.dumps(vtables, indent=1)[:3000])
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
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if '005b0000' <= a < '005bc000'}

# range rows (functions.jsonl) with the unit each lies in
RANGE_ROWS = [json.loads(l) for l in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines() if l.strip()]
RANGE_ROWS = [r for r in RANGE_ROWS if 0x5b0000 <= int(r['addr'], 16) < 0x5bc000]
UNITS = [
    ('script-context tail', 0x5b0000, 0x5b0820),
    ('accoutrement', 0x5b0820, 0x5b2ec0),
    ('brick-color', 0x5b2ec0, 0x5b6590),
    ('player inline / sound', 0x5b6590, 0x5bc000),
]
unit_rows = {}
for r in RANGE_ROWS:
    a = int(r['addr'], 16)
    unit = [u for u, lo, hi in UNITS if lo <= a < hi][0]
    unit_rows.setdefault(unit, []).append(r['addr'])

UNIT_MAP = {
    'script-context tail ..005b071f': (
        'script/ScriptContext.cpp, continued from 005a8590 (app-unit5a0 unit map): rows from 005b03b0, '
        'startPendingScripts 005b0590, onChangedScriptEnabled 005b06a0, addScript 005b06c0, onEvent(RunService, '
        'Heartbeat) 005b0710. Owners: script/ScriptContext.h (ScriptContextLifetime.cpp) and the LuaBridge2008 lease. '
        'Not built here.'),
    'accoutrement 005b0820..005b2ebf': (
        'v8datamodel/Accoutrement.cpp. Evidence: RTTI .?AVAccoutrement@RBX@@ / .?AVHat@RBX@@ (vtables 00834bf4 / '
        '00835094), Accoutrement() 005b2230 new(0x1d8) (Creator 00432520), Hat() 005b2d10, ~Accoutrement 005b0da0, the '
        'FactoryProduct / DescribedCreatable chains and classDescriptors 005b1950 / 005b19c0 ("Accoutrement", "Hat"), '
        'the six PropDescriptor constructors 005b1a30..005b1bd0 and GetSetImpl getters (static initializers '
        '007f4fb0..007f5190, category "Appearance"), readProperty 005b0840 ("BackendAccoutrementState"), getHandleConst '
        '005b08a0 ("Handle"), the state machine (updateDesiredState 005b10a0, setDesiredState 005b2510 with jump tables '
        '005b25c8 / 005b25d8, connectTouchEvent 005b1d70, upTo_InCharacter 005b1e50, upTo_Equipped 005b1830 '
        '("HeadWeld"), downFrom_Equipped 005b1fc0), the boost::function managers / mf1 invokers / slot constructors of '
        'its three event binds (005b0ac0, 005b0cd0, 005b0d90, 005b1110, 005b1190, 005b1430, 005b15e0..005b17d0, '
        '005b1ca0), write 005b1480, onAncestorChanged 005b25f0 and the setAttachment* setters. The analysed row 005b1520 '
        'covers ??_GAccoutrement 005b15c0 locally (see appearance-working.json bounds_note). Most structural rows are '
        'counted by appearance-working.json; built here: 8 counted rows (6 from AppUnit5B0_2008Accoutrement.cpp, 2 from '
        'the committed Accoutrement.cpp compiled unchanged), 3 pending-build-only rows, 1 near miss.'),
    'brick-color 005b2ec0..005b658f': (
        'util/BrickColor.cpp: std::map<BrickColor::Number, Color4 / Color4uint8 / int / std::string> _Tree '
        'instantiations 005b2ec0..005b43a0 ("map/set<T> too long", "invalid map/set<T> iterator"), BrickMap::insert '
        '005b4410, ~BrickMap 005b4570, BrickMap() 005b4630 (5601 B: "White", "Grey", "Light yellow" ...), '
        'BrickMap::singleton 005b5c20, generatePaletteMap 005b4130 / 005b42f0, BrickColor colorPalette / '
        'getClosestPaletteIndex / parse / random / closest(Color4) / closest(Color3) / BrickColor(int) / name / color4 / '
        'color3 005b5c80..005b62e0 and helpers to 005b6580. The map instantiations are Roblox-instantiated STL '
        'templates referenced only by BrickMap. No committed native BrickColor header (the donor util/BrickColor.h is '
        'the only declaration); not built here.'),
    'player inline / sound 005b6590..005bbfff': (
        'Player::getCharacter 005b6590 (header inline, counted by network-player-working.json) and 005b65a0, then '
        'util/Sound.cpp / SoundService: FMOD_ErrorString table 005b65b0 ("Tried to call lock a second time", "Neither '
        'NTSCSI nor ASPI"), StringConverter<ContentId> 005b6940, the "FMOD %d: %s" checks 005b6fe0 / 005b87a0, '
        'Sound / SoundService value conversions (sound-value-* receipts), the FMOD system init 005ba060 ("Incorrect '
        'FMODEX DLL version", "No active sound driver detected"), the ReverbType enum 005bb330 ("NoReverb", '
        '"GenericReverb"), classDescriptors 005bb7f0 / 005bb860 / 005bb8d0 ("SoundService", "Sound", "StockSound") '
        'and the shared_count / thunk rows, continuing past 005bc000. Owner: the native sound recoveries '
        '(util/Sound.h, native-classes/Sound*.cpp). FMOD itself is a DLL import (no library code here). Not built '
        'here.'),
}

NOT_ATTEMPTED = {
    'setDesiredState 005b2510 and its transitions 005b1830 / 005b1d70 / 005b1e50 / 005b1fc0': (
        'need the 2008 state-machine members, the HeadWeld buildWeld path and the three boost::signals binds '
        '(proposal; only updateDesiredState / onAncestorChanged / write were built in the pending build)'),
    'boost::function / mf1 / slot helpers of the event binds (005b0ac0, 005b0cd0, 005b0d90, 005b1110, 005b1190, '
    '005b1430, 005b15e0..005b17d0, 005b1ca0)': 'emitted only with the onEvent_* members (not declared)',
    'BrickColor unit': 'no committed native BrickColor header; would need a new layout header (not this pass)',
}

PROPOSALS = {
    'v8datamodel/Accoutrement.h (appearance owner)': (
        'Add `static bool writeUnlocked;` (00976cad: write 005b1480 tests it, CMainFrame 0043232d stores it) and the '
        'state-machine members `void updateDesiredState();` (005b10a0), `void setDesiredState(AccoutrementState, const '
        'ServiceProvider*);` (005b2510) and the inline `computeDesiredState()` / `computeDesiredState(Instance*)` '
        '(inlined into 005b10a0: no handle -> NOTHING, not in workspace -> HAS_HANDLE, no character -> IN_WORKSPACE, '
        'torso ? EQUIPPED : NOTHING). With these declarations write 005b1480, updateDesiredState 005b10a0 and '
        'onAncestorChanged 005b25f0 are exact (pending build, generated header copy under out/app-unit5b0-2008/pending). '
        'No field or vtable change. Names are analog (donor) names.'),
    'appearance-working.json (FYI to the appearance owner)': (
        'onCameraNear 005b0fa0 and render3dSelect 005b1020 in the committed native-classes/Accoutrement.cpp are now '
        'exact with every target verified (the "register allocation differs" note in that receipt is stale against '
        'the current headers). This receipt counts them once; the appearance receipt does not.'),
}

receipt = {
    'class': 'RBX Accoutrement unit of the application range 005b0000..005bc000 (2008-06), inactive',
    'compiler': 'VS2008 RTM 21022, /fp:fast',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)): nb.sha(p) for p in [SOURCE, OWNER_SOURCE, Path(__file__).resolve(), HEADER]},
    'objects': {k: nb.sha(v) for k, v in OBJ.items()},
    'pending_header_copy': str((PENDING_DIR / 'v8datamodel/Accoutrement.h').relative_to(ROOT)),
    'unit_map': UNIT_MAP,
    'unit_rows': {u: {'rows': len(v), 'span': '%s..%s' % (v[0], v[-1])} for u, v in unit_rows.items()},
    'range_rows_total': len(RANGE_ROWS),
    # Written as 'ADDR counted by RECEIPT' text, never as a quoted bare address: some recorders (local_backpack,
    # viewnew_brick_build, viewnew_part_mesh) treat any '"ADDR"' in another receipt as counted there and drop it.
    'range_rows_counted_by_other_receipts': ['%s counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()],
    'rows': groups,
    'support_rows': support_out,
    'vtables_current_headers': vtables,
    'vtordisp_thunks_checked': thunk_out,
    'not_exact': ['%s %s: %d/%d B, not counted (see rejected)' % (r['address'], r['symbol'][:60], r['size'],
                                                                 r['target_size'])
                  for rows in near.values() for r in rows],
    'pending_build_only': ['%s %s: %s in the pending build (exact=false, not counted)' % (
        r['address'], r['symbol'][:70], 'exact' if r['exact'] else 'not exact') for r in pending],
    'not_attempted': NOT_ATTEMPTED,
    'rejected': REJECTED,
    'proposals': PROPOSALS,
    'exact_function_rows': exact_rows,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit5b0-2008: %d counted exact rows (%s); %d vtables checked, %d support rows, %d pending-build-only, '
      '%d range rows (%d counted elsewhere)' % (len(exact_rows), ' '.join(exact_rows), len(vtables), len(support_out),
                                                len(pending), len(RANGE_ROWS), len(range_counted)))
