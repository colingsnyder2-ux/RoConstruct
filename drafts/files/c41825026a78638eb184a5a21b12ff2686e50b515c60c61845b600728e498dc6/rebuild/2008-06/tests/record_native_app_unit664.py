"""Verify the inactive 2008-06 native rows of the application range 00664000..00668000 and record the unit map of the
range (boundary evidence in the receipt's `unit_map` / `row_map`; rows counted by other receipts are listed there).

Units built here (VS2008 RTM 21022, document-swap flags plus /fp:fast, as the humanoid-states and kernel-stages units):
  * the humanoid state force limits 00666350 / 006663a0: native-classes/AppUnit664ForceLimits.cpp against the new
    native-headers/AppUnit664/HumanoidForceLimits.h (no donor header has that path, so it shadows nothing). Each returns
    a copy of a function-local static G3D::Vector3; the statics and guards are bound to the addresses the original
    instructions use and checked to be referenced by that row only.
  * std::multimap<Primitive*, Joint*>::lower_bound 00667fd0 (the JointStage map, called only by
    JointStage::removeFromMap 00668280): native-classes/AppUnit664JointMapTemplates.cpp, an explicit member
    instantiation of the VC9 _Tree.
There is no class layout of its own in these rows (two free functions and an STL member), so there is no layout probe;
the receipt records the RTTI / vtable / caller evidence of each block of the range instead.

Every counted row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the
address the original instruction uses and verified: constants by their bytes, the function-local statics by the
explicit LOCAL_STATIC map (one address per symbol, referenced by the owning row only). A row is counted only when no
other receipt counts it (top-level exact_function_rows rule). Addresses of rows not counted here are written as
0x-prefixed or 'ADDR counted by RECEIPT' text, never as quoted bare addresses (local_backpack / viewnew_brick_build /
viewnew_part_mesh read any quoted bare address as counted there).
Writes work/2008-06/shared-layouts/app-unit664-working.json. Set NATIVE_APP_UNIT664_DISCOVER=1 to list unbound
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
OUT = nb.OUT / 'app-unit664'
OUT.mkdir(parents=True, exist_ok=True)
SOURCES = {
    'limits': R / 'native-classes/AppUnit664ForceLimits.cpp',
    'jointmap': R / 'native-classes/AppUnit664JointMapTemplates.cpp',
}
HEADERS = [R / 'native-headers/AppUnit664/HumanoidForceLimits.h']
UNIT = ['/fp:fast']   # the humanoid-states / kernel-stages profile
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT664_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit664-working.json'
LO, HI = 0x664000, 0x668000
H = lambda a: '0x%08x' % a


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags() + UNIT + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log[-4000:]
    return obj, flags


OBJ, FLAGS = {}, {}
for key, src in SOURCES.items():
    OBJ[key], FLAGS[key] = build('NativeAppUnit664_' + key, src)

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
FUNCS = {}
for line in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines():
    if line.strip():
        row = json.loads(line)
        FUNCS[int(row['addr'], 16)] = row
FUNCTIONS = set(FUNCS)

TREE = ('?$_Tree@V?$_Tmap_traits@PAVPrimitive@RBX@@PAVJoint@2@U?$less@PAVPrimitive@RBX@@@std@@V?$allocator@U?$pair@'
        'QAVPrimitive@RBX@@PAVJoint@2@@std@@@5@$00@std@@@std@@')
ROWS = {
    'limits': [
        (0x666350, '?maxMoveForce@HUMAN@RBX@@YA?AVVector3@G3D@@XZ'),
        (0x6663a0, '?minMoveForce@HUMAN@RBX@@YA?AVVector3@G3D@@XZ'),
    ],
    'jointmap': [
        (0x667fd0, '?lower_bound@' + TREE + 'QAE?AViterator@12@ABQAVPrimitive@RBX@@@Z'),
    ],
}
# The function-local statics: storage (x / y / z at +0 / +4 / +8) and the init guard, as the original rows use them.
LOCAL_STATIC = [
    (r'^\?force@\?1\?\?maxMoveForce@HUMAN@RBX@@', 0x97d968),      # 00666369 / 00666375 / 0066637b, reads 00666385..
    (r'^\?\$S\d+@\?1\?\?maxMoveForce@HUMAN@RBX@@', 0x97d974),       # guard 00666355 / 00666363
    (r'^\?force@\?1\?\?minMoveForce@HUMAN@RBX@@', 0x97d978),      # 006663b9 / 006663c1 / 006663c7, reads 006663d1..
    (r'^\?\$S\d+@\?1\?\?minMoveForce@HUMAN@RBX@@', 0x97d984),       # guard 006663a5 / 006663b3
]
LOCAL_STATIC_AT = {}
UNBOUND = []
binding = {}
BODIES = {}
for key in SOURCES:
    for n, b, r in match.coff_functions(Path(OBJ[key]).read_bytes()):
        BODIES.setdefault(key, {})[n] = (b, r)


def target_of(address):
    body, refs, _ = match.target('2008-06', '%08x' % address)
    return body, refs


def local_static(symbol, value):
    for pattern, address in LOCAL_STATIC:
        if re.match(pattern, symbol):
            prev = LOCAL_STATIC_AT.setdefault(symbol, address)
            return prev == value == address
    return False


def verify(which, rows, own):
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
        entry = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target),
                 'exact': exact}
        if not exact:
            assert DISCOVER, (name, entry['address'], len(body), len(target))
            result.append(entry)
            continue
        assert len(body) == len(target) == FUNCS[address]['size'], (name, len(body), len(target))
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
            elif local_static(symbol, value):
                how = 'function-local static'
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
groups = {k: verify(k, rows, own) for k, rows in ROWS.items()}
if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for g in groups.values():
        for r in g:
            if not r['exact']:
                print('NOT EXACT', r['address'], r['symbol'][:110], r['size'], r['target_size'])
    sys.exit(0)
assert not UNBOUND, '\n'.join(UNBOUND)
assert len(LOCAL_STATIC_AT) == len(LOCAL_STATIC), LOCAL_STATIC_AT


# ---- the statics: writable data, referenced (as DIR32 operands) by the owning row only --------------------------------
def text_dir32_refs(value, span):
    """Code addresses whose instructions carry a DIR32 operand inside [value, value + span)."""
    pe = original.pe
    base = pe.OPTIONAL_HEADER.ImageBase
    hits = []
    for sec in pe.sections:
        if not sec.Name.startswith(b'.text'):
            continue
        data = sec.get_data()
        va0 = base + sec.VirtualAddress
        for v in range(value, value + span, 4):
            for m in re.finditer(re.escape(struct.pack('<I', v)), data):
                hits.append(va0 + m.start())
    return hits


def section_name(value):
    pe = original.pe
    rva = value - pe.OPTIONAL_HEADER.ImageBase
    for sec in pe.sections:
        if sec.VirtualAddress <= rva < sec.VirtualAddress + max(sec.Misc_VirtualSize, sec.SizeOfRawData):
            return sec.Name.rstrip(b'\0').decode()
    return None


statics = {}
OWNER = {0x97d968: 0x666350, 0x97d974: 0x666350, 0x97d978: 0x6663a0, 0x97d984: 0x6663a0}
for symbol, address in sorted(LOCAL_STATIC_AT.items(), key=lambda x: x[1]):
    assert section_name(address) == '.data', (symbol, hex(address), section_name(address))
    span = 4 if symbol.startswith('?$S') else 12
    refs = text_dir32_refs(address, span)
    owner = OWNER[address]
    assert refs and all(owner <= r < owner + FUNCS[owner]['size'] for r in refs), (symbol, [hex(r) for r in refs])
    statics[symbol] = '%s: .data, %d DIR32 operand(s), all inside row %s' % (H(address), len(refs), H(owner))

elsewhere = {}
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
            elsewhere.setdefault(int(m.group(1), 16), set()).add(Path(path).name)


def listed_in(receipt, address):
    """True when another receipt lists the row as a verified method (no exact flag: not counted by the rule)."""
    data = json.loads((ROOT / 'work/2008-06/shared-layouts' / receipt).read_text())
    if isinstance(data, dict):   # a back-reference naming this unit's own receipt is not a listing
        data = {k: v for k, v in data.items() if k != 'range_rows_counted_by_other_receipts'}
    return '"%08x"' % address in json.dumps(data)


exact_rows = sorted({r['address'] for rows in groups.values() for r in rows if r['exact']})
double = {a: sorted(elsewhere[int(a, 16)]) for a in exact_rows if int(a, 16) in elsewhere}
assert not double, double
listed = {a: [f for f in ('humanoid-states1-working.json', 'humanoid-states2-working.json',
                          'humanoid-states3-working.json', 'app-unit660-2008-working.json', 'effects-working.json')
              if listed_in(f, int(a, 16))] for a in exact_rows}
assert not any(listed.values()), listed   # no other receipt even lists these rows
rows = sorted(a for a in FUNCS if LO <= a < HI)
range_counted = {a: sorted(v) for a, v in sorted(elsewhere.items()) if LO <= a < HI}


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


def vtable_rtti(vtable):
    return original.string(d(d(vtable - 4) + 12) + 8)


lua_rows = [a for a in rows if a < 0x665670]
assert names[0x664050].startswith('?save@@YAXPAULexState@@') and names[0x665650].startswith('?luaX_lookahead@@')
assert all(names.get(a, '').startswith('?') and '@RBX@@' not in names.get(a, '') for a in lua_rows), \
    [H(a) for a in lua_rows if not names.get(a, '').startswith('?')]
# RBX::Effect leaf rows: the three rows store / read the Effect vtable 0x0084cb84
assert vtable_rtti(0x84cb84) == '.?AVEffect@RBX@@'
for a in (0x665670, 0x665680, 0x665690):
    assert struct.pack('<I', 0x84cb84) in original.data(a, FUNCS[a]['size']), H(a)
# PartDragTool unit (app-unit660 receipt), evidence names of its members
assert names[0x6659a0].startswith('?onMouseDown@PartDragTool@RBX@@') and names[0x666100].startswith('?onMouseUp@PartDragTool@RBX@@')
assert names[0x665aa0].startswith('?getMousePart@MegaDragger@RBX@@')
assert names[0x666240].startswith('?reset@floatERA@RBX@@') and names[0x6662d0].startswith('?getAverage@Vector3ERA@RBX@@')
# humanoid states: G3D::Vector3::isZero COMDAT 006662f0 (squared length fuzzy-compared with 0 through G3D::eps
# 00513080) called by RunningBase::onStep 00666410 and MovingNoPhysicsBase::onStep 0066f2c0
assert calls(0x6662f0, 0x513080) and calls(0x666410, 0x6662f0) and calls(0x66f2c0, 0x6662f0)
# the force limits: callers RunningBase::onComputeForce 00666550 and Freefall::onComputeForce 006675d0, then clamp
assert calls(0x666550, 0x666350, 0x6663a0, 0x4a6100) and calls(0x6675d0, 0x666350, 0x6663a0, 0x4a6100)
# RunningBase ctor 00666980 / Running ctor 00666ac0, RTTI of the state vtables the constructors store
for vt, cls in ((0x84cc38, 'RunningBase'), (0x84cc94, 'Running'), (0x84cce0, 'Dead'), (0x84cd10, 'FallingDown'),
                (0x84cd54, 'Seated'), (0x84cdb0, 'StrafingNoPhysics'), (0x84ce10, 'RunningNoPhysics'),
                (0x84ce54, 'Flying'), (0x84cea0, 'Freefall'), (0x84ceec, 'Jumping'), (0x84cf30, 'GettingUp')):
    assert vtable_rtti(vt) == '.?AV%s@HUMAN@RBX@@' % cls, (hex(vt), vtable_rtti(vt))
assert calls(0x666ac0, 0x666980) and calls(0x667c40, 0x6674b0) and calls(0x667210, 0x66f070)
assert calls(0x667370, 0x66f070)
# 006672a0 is `jmp 0x0066ee10` (~MovingNoPhysicsBase): the shared unwind funclet 0x007dc230 of the StrafingNoPhysics /
# RunningNoPhysics constructors (both use handler 0x007dc238) jumps to it; the HumanoidStates3 build with
# NATIVE_SIMJOB_PENDING emits exactly this body for the implicit ~Named<MovingNoPhysicsBase, ...> (pending only).
assert original.data(0x6672a0, 5) == b'\xe9' + struct.pack('<i', 0x66ee10 - 0x6672a5)
assert original.data(0x7dc230, 8) == b'\x8b\x4d\xf0\xe9' + struct.pack('<i', 0x6672a0 - 0x7dc238)
assert struct.pack('<I', 0x7dc238) in original.data(0x667210, 8) and struct.pack('<I', 0x7dc238) in original.data(0x667370, 8)
# JointStage head: edgeHasPrimitivesDownstream 00667f70 (kernel-stages) and the multimap lower_bound 00667fd0, whose
# only caller is removeFromMap 00668280 (insert 00668210 -> _Insert 00668010 carry the multimap evidence names)
assert calls(0x668280, 0x667fd0) and calls(0x668210, 0x668010)
assert names[0x668010].startswith('?_Insert@' + TREE) and names[0x668210].startswith('?insert@' + TREE)
assert text_dir32_refs(0x667fd0, 1) == []

HUMANOID_COUNTED_NOTE = ('listed as verified methods by humanoid-states1/2/3-working.json without an exact flag (not '
                         'counted by the rule); HumanoidState family sources, not rebuilt here')
BLOCKS = [
    (0x664000, 0x665670, 'lua-llex', 'Lua 5.1.1 llex.c (save 0x00664050 .. luaX_lookahead 0x00665650; Lua evidence '
     'names): library code, not recovered. luaX_init 0x006640c0 is a support row of script-app2008-working.json.'),
    (0x665670, 0x6656b0, 'effect', 'RBX::Effect leaf rows 0x00665670 / 0x00665680 / 0x00665690 (RTTI '
     '.?AVEffect@RBX@@, vtable 0x0084cb84 stored / read by each): verified by effects-working.json (Sparkles owner); '
     'not rebuilt here.'),
    (0x6656b0, 0x6659a0, 'tool-trials', 'resize / axis-move tool helpers 0x006656b0 and 0x00665880: counted by the '
     'resize-tool-methods-trial / axis-move-tool-lifetime-trial receipts.'),
    (0x6659a0, 0x666240, 'part-drag-tool', 'RBX::PartDragTool unit (NativeToolName<PartDragTool> statics, '
     'auto_ptr<RunDragger>, getName): counted by app-unit660-2008-working.json; MegaDragger::getMousePart 0x00665aa0 '
     'and PartDragTool onMouseDelta 0x00665b00 / onKeyDown 0x00665ce0 / render3dAdorn 0x00665e20 are pending-build-only '
     'there (MegaDragger.h proposal of that receipt). Not rebuilt here.'),
    (0x666240, 0x6662f0, 'era', 'floatERA / Vector3ERA reset / pushAndGetAverage / getAverage: counted by '
     'app-unit660-2008-working.json.'),
    (0x6662f0, 0x666350, 'g3d-vector3-iszero', 'G3D::Vector3::isZero 0x006662f0, the out-of-line COMDAT of the G3D '
     '6.09 inline (`fuzzyEq(squaredMagnitude(), 0.0f)`, G3D::eps 0x00513080): G3D library code, not recovered.'),
    (0x666350, 0x6663f0, 'humanoid-force-limits', 'the two humanoid force-limit accessors 0x00666350 (1000, 10000, '
     '1000) and 0x006663a0 (-1000, 0, -1000), each returning a copy of a function-local static Vector3 (callers '
     'RunningBase::onComputeForce 0x00666550 and Freefall::onComputeForce 0x006675d0). Built and counted here.'),
    (0x6663f0, 0x667f70, 'humanoid-states', 'HUMAN::RunningBase / Running / Dead / FallingDown / Seated / '
     'StrafingNoPhysics / RunningNoPhysics / Flying / Freefall / Jumping / GettingUp rows (RTTI of the vtables the '
     'constructors store), ' + HUMANOID_COUNTED_NOTE + '. Pending there: RunningBase::onStep 0x00666410, '
     'RunningBase::onComputeForce 0x00666550, Freefall::onComputeForce 0x006675d0, Jumping::onComputeForce '
     '0x00667a40. 0x006672a0 (`jmp ~MovingNoPhysicsBase`, the implicit ~Named<MovingNoPhysicsBase, '
     'sStrafingNoPhysics / sRunningNoPhysics> reached from the unwind funclet 0x007dc230) is not listed by any '
     'receipt; the HumanoidStates3 unit emits it only with NATIVE_SIMJOB_PENDING.'),
    (0x667f70, HI, 'joint-stage-head', 'JointStage.cpp head: edgeHasPrimitivesDownstream 0x00667f70 (counted by '
     'kernel-stages-working.json) and std::multimap<Primitive*, Joint*>::lower_bound 0x00667fd0 (only caller '
     'removeFromMap 0x00668280): built and counted here by explicit member instantiation.'),
]
UNIT_MAP = {}
row_map = []
for lo, hi, key, text in BLOCKS:
    inside = [a for a in rows if lo <= a < hi]
    assert inside, key
    UNIT_MAP['%s %s..%s' % (key, H(lo), H(hi - 1))] = {
        'rows': len(inside), 'unit': text, 'library': key in ('lua-llex', 'g3d-vector3-iszero'),
        'counted_here': [a for a in exact_rows if lo <= int(a, 16) < hi],
        'counted_elsewhere': ['%08x counted by %s' % (a, ', '.join(range_counted[a])) for a in inside
                              if a in range_counted],
    }
    for a in inside:
        row_map.append({'row': H(a), 'size': FUNCS[a]['size'], 'block': key,
                        'evidence_name': names.get(a, '')[:120] or None,
                        'counted': 'here' if '%08x' % a in exact_rows else
                        ('elsewhere: ' + ', '.join(range_counted[a]) if a in range_counted else 'no')})
assert sum(v['rows'] for v in UNIT_MAP.values()) == len(rows)

NOT_BUILT = {
    'RunningBase::onStep 0x00666410, RunningBase::onComputeForce 0x00666550, Freefall::onComputeForce 0x006675d0, '
    'Jumping::onComputeForce 0x00667a40': 'HumanoidState family members (humanoid-states1/2 pending lists): they need '
        'the 2008 Body / Cofm / SimBody declarations (native v8kernel/Body2008.h) together with the HumanoidStates '
        'headers, which compile only with the recorder overlays tests/NativeHumanoidStates1Calls.h / '
        'NativeHumanoidStates2Calls.h (Humanoid declarations); a native unit here cannot include those.',
    '0x006672a0 ~Named<MovingNoPhysicsBase, ...>': 'emitted only by native-classes/HumanoidStates3.cpp with '
        'NATIVE_SIMJOB_PENDING (MovingNoPhysicsBase constructor pending there); would be pending-build-only.',
    'G3D::Vector3::isZero 0x006662f0': 'G3D library inline, not recovered.',
}
REJECTED = {}
PROPOSALS = {
    'HumanoidState family owner (native humanoid/HumanoidStates1.h / HumanoidStates2.h)': (
        'RunningBase::onComputeForce 0x00666550 and Freefall::onComputeForce 0x006675d0 call the two force-limit '
        'accessors out of line (0x0066674a / 0x006668a0 / 0x006668ac and 0x0066776d / 0x00667779): when those bodies '
        'are written, declare the accessors from native AppUnit664/HumanoidForceLimits.h (or move the two '
        'declarations into the shared humanoid header) so the calls bind to 0x00666350 / 0x006663a0.'),
    'HumanoidState family owner, FYI': (
        '0x006672a0 is the implicit ~Named<MovingNoPhysicsBase, sStrafingNoPhysics / sRunningNoPhysics> (ICF-folded '
        '`jmp ~MovingNoPhysicsBase`), reached from the shared constructor unwind funclet 0x007dc230; your '
        'HumanoidStates3 object built with NATIVE_SIMJOB_PENDING already emits it (e9 rel32). It becomes countable '
        'once the MovingNoPhysicsBase constructor leaves the pending build.'),
    'kernel-stages owner (native v8world/JointStage2008.h), FYI': (
        'JointStage::removeFromMap 0x00668280 calls the multimap lower_bound 0x00667fd0 out of line; it is built '
        'and counted here by explicit member instantiation (AppUnit664JointMapTemplates.cpp), so it does not need '
        'to be counted again by the JointStage unit.'),
}

sha = nb.sha
receipt = {
    'class': 'Humanoid state force limits, the JointStage multimap lower_bound and the unit map of the application '
             'range 00664000..00668000 (2008-06), inactive',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM), /fp:fast',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in
                [Path(__file__).resolve()] + list(SOURCES.values()) + HEADERS},
    'objects': {k: sha(v) for k, v in OBJ.items()},
    'local_statics': statics,
    'unit_map': UNIT_MAP,
    'row_map': row_map,
    'range_functions': len(rows),
    'range_lua_library_rows': len(lua_rows),
    'range_rows_counted_by_other_receipts': ['%08x counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()],
    'rows': groups,
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
print('PASS app-unit664: %d counted exact rows (%s); %d range rows (%d Lua), %d counted elsewhere; %d statics bound'
      % (len(exact_rows), ' '.join(exact_rows), len(rows), len(lua_rows), len(range_counted), len(statics)))
