"""Verify the inactive Balancing/RunningBase/Running/Landed/Climbing layouts, bodies and vtables against 2008-06."""
import hashlib, json, os, shutil, struct, subprocess, sys
from pathlib import Path
import pefile
root = Path(__file__).resolve().parents[3]; sys.path.insert(0, str(root))
from roc import match, rebuild
out = root/'rebuild/2008-06/out/native-layouts'; out.mkdir(parents=True, exist_ok=True)
base = json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
common = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')] + ['/fp:fast']
header = root/'rebuild/2008-06/native-headers/humanoid/HumanoidStates1.h'
base_header = root/'rebuild/2008-06/native-headers/humanoid/HumanoidState.h'
calls = root/'rebuild/2008-06/tests/NativeHumanoidStates1Calls.h'
overlay = out/'humanoid-states1-overlay'; (overlay/'humanoid').mkdir(parents=True, exist_ok=True)
shutil.copyfile(calls, overlay/'humanoid'/'Humanoid.h')
units = [('layout', root/'rebuild/2008-06/tests/NativeHumanoidStates1Layout.cpp', 'NativeHumanoidStates1Layout.obj'),
         ('states', root/'rebuild/2008-06/native-classes/HumanoidStates1.cpp', 'NativeHumanoidStates1.obj'),
         ('leaves', root/'rebuild/2008-06/native-classes/HumanoidStates1Leaves.cpp', 'NativeHumanoidStates1Leaves.obj')]
objects = {}; flags = {}
for name, src, objname in units:
    obj = out/objname; f = ['/I'+str(overlay)] + common + ['/Fo'+str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', f, out); assert code == 0, log
    objects[name] = obj; flags[name] = f
# Proposal check (not counted): compile the leaves unit again with NATIVE_HUMANOID_STATE_PENDING against a copy of
# HumanoidState.h in out/ carrying the proposed additions (getHumanoid, bool speedSettled, onFloorStep).
pending_overlay = out/'humanoid-states1-pending-overlay'; (pending_overlay/'humanoid').mkdir(parents=True, exist_ok=True)
shutil.copyfile(calls, pending_overlay/'humanoid'/'Humanoid.h')
text = base_header.read_text(); assert text.count('    int speedSettled() const;') == 1
(pending_overlay/'humanoid'/'HumanoidState.h').write_text(text.replace('    int speedSettled() const;',
    '    bool speedSettled() const;\n    Humanoid* getHumanoid() const;\n    bool onFloorStep();'))
obj = out/'NativeHumanoidStates1Pending.obj'
f = ['/I'+str(pending_overlay)] + common + ['/DNATIVE_HUMANOID_STATE_PENDING', '/Fo'+str(obj), str(units[2][1])]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', f, out); assert code == 0, log
objects['pending'] = obj; flags['pending'] = f
raw = objects['layout'].read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?runningFilter@@'))
assert body == bytes.fromhex('8b44240485c0740483c004c333c0c3') and not refs
H = '@HUMAN@RBX@@'
NR = lambda tag: '?$Named@VRunningBase@HUMAN@RBX@@$1?s%s@23@3QBDB@RBX@@' % tag
SIG = '??R?$signal1@XMU?$last_value@X@boost@@HU?$less@H@std@@V?$function@$$A6AXM@ZV?$allocator@X@std@@@2@@boost@@'
FIND = '?findSignalInstance@SignalDescriptor@Reflection@RBX@@'
# (unit, address, symbol prefix, expected direct-call targets)
methods = [
    ('leaves', '0066e660', '??0Balancing'+H, [('??0HumanoidState'+H, 0x643e00)]),
    ('states', '00666980', '??0RunningBase'+H, [('??0Balancing'+H, 0x66e660), (FIND, 0x56b620), (SIG, 0x4937f0)]),
    ('states', '006663f0', '??1RunningBase'+H, [('??1HumanoidState'+H, 0x6435c0)]),
    ('states', '00666520', '??_GRunningBase'+H, [('??1HumanoidState'+H, 0x6435c0), ('??3@YAXPAX@Z', 0x6a067a)]),
    ('states', '00643400', '?getIntendedRotationAboutYAxis@RunningBase'+H, []),
    ('leaves', '00666ac0', '??0Running'+H, [('??0RunningBase'+H, 0x666980)]),
    ('leaves', '00643550', '??0Landed'+H, [('??0RunningBase'+H, 0x666980)]),
    ('leaves', '006435a0', '??0Climbing'+H, [('??0RunningBase'+H, 0x666980)]),
    ('leaves', '00643580', '??_GLanded'+H, [('??1RunningBase'+H, 0x6663f0), ('??3@YAXPAX@Z', 0x6a067a)]),
    ('leaves', '00666b00', '?getName@'+NR('Running'), [('?call_once@boost@@', 0x557330), ('??$doDeclare@$1?sRunning', 0x666a50)]),
    ('leaves', '00666a50', '??$doDeclare@$1?sRunning', [('?declare@Name@RBX@@SAABV12@PBDH@Z', 0x553f90)]),
    ('leaves', '00666af0', '??$callDoDeclare@$1?sRunning', [('??$doDeclare@$1?sRunning', 0x666a50)]),
    ('leaves', '00643ed0', '?getName@'+NR('Landed'), [('?call_once@boost@@', 0x557330), ('??$doDeclare@$1?sLanded', 0x643410)]),
    ('leaves', '00643410', '??$doDeclare@$1?sLanded', [('?declare@Name@RBX@@SAABV12@PBDH@Z', 0x553f90)]),
    ('leaves', '00643ce0', '??$callDoDeclare@$1?sLanded', [('??$doDeclare@$1?sLanded', 0x643410)]),
    ('leaves', '00643ef0', '?getName@'+NR('Climbing'), [('?call_once@boost@@', 0x557330), ('??$doDeclare@$1?sClimbing', 0x643480)]),
    ('leaves', '00643480', '??$doDeclare@$1?sClimbing', [('?declare@Name@RBX@@SAABV12@PBDH@Z', 0x553f90)]),
    ('leaves', '00643cf0', '??$callDoDeclare@$1?sClimbing', [('??$doDeclare@$1?sClimbing', 0x643480)]),
]
# Identical-code-folded bodies at shared addresses: compiled byte-identical, recorded, not counted.
folded = [('leaves', '00643d10', '??_GBalancing'+H), ('leaves', '005cb9d0', '?getStateType@Running'+H),
          ('leaves', '007359e0', '?getStateType@Landed'+H), ('leaves', '0064cac0', '?getStateType@Climbing'+H),
          ('leaves', '00643580', '??_GRunning'+H), ('leaves', '00643580', '??_GClimbing'+H),
          ('states', '0060a2f0', '?query3@RunningBase'+H), ('states', '0060a2f0', '?query4@RunningBase'+H)]
pe = pefile.PE(str(root/'clients/2008-06/Roblox.exe'), fast_load=True); imagebase = pe.OPTIONAL_HEADER.ImageBase
original_data = lambda va, n: pe.get_data(va-imagebase, n)
u = lambda va: struct.unpack('<I', original_data(va, 4))[0]
expected_data = {'??_7Balancing'+H+'6BINamed@2@@': 0x84d0dc, '??_7Balancing'+H+'6BHitTestFilter@2@@': 0x84d0d4,
                 '??_7RunningBase'+H+'6BINamed@2@@': 0x84cc38, '??_7RunningBase'+H+'6BHitTestFilter@2@@': 0x84cc30,
                 '??_7Running'+H+'6BINamed@2@@': 0x84cc94, '??_7Running'+H+'6BHitTestFilter@2@@': 0x84cc8c,
                 '??_7Landed'+H+'6BINamed@2@@': 0x84ac9c, '??_7Landed'+H+'6BHitTestFilter@2@@': 0x84ac94,
                 '??_7Climbing'+H+'6BINamed@2@@': 0x84acd0, '??_7Climbing'+H+'6BHitTestFilter@2@@': 0x84acc8,
                 '?event_Running@Humanoid@RBX@@2V?$SignalDesc@VHumanoid@RBX@@$$A6AXM@Z@Reflection@2@A': 0x97a504,
                 '?sRunning'+H+'3QBDB': 0x84cc68, '?sLanded'+H+'3QBDB': 0x84cc70, '?sClimbing'+H+'3QBDB': 0x84cc78}
statics = {}  # function-local statics (once flags, doDeclare results and guards) must map consistently
rows = []; folded_rows = []; index = {}
for unit in ('states', 'leaves', 'pending'):
    raw = objects[unit].read_bytes(); index[unit] = (raw, match.coff_functions(raw), match._coff_data_index(raw))
def check(unit, address, prefix, expected):
    raw, functions, (sections, symbols, definitions, _) = index[unit]
    name, body, refs = next(x for x in functions if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', address)
    assert match.exact_match(target, targetrefs, body, refs), (address, prefix, len(body), len(target))
    start, idx = definitions[name]; tab = sections[idx]; edges = {}; data = {}
    for i in range(tab[7]):
        offset, sym, kind = struct.unpack_from('<IIH', raw, tab[5]+10*i); offset -= start
        if not 0 <= offset <= len(body)-4: continue
        if kind == 20: edges[symbols[sym][0]] = hex(int(address, 16)+offset+4+struct.unpack_from('<i', target, offset)[0])
        elif kind == 6: data[symbols[sym][0]] = hex(struct.unpack_from('<I', target, offset)[0])
    for symbol, dest in expected:
        assert any(k.startswith(symbol) and v == hex(dest) for k, v in edges.items()), (address, symbol, edges)
    for symbol, dest in data.items():
        if symbol in expected_data: assert dest == hex(expected_data[symbol]), (address, symbol, dest)
        elif symbol.startswith('__real@'): assert original_data(int(dest, 16), 4) == bytes.fromhex(symbol[7:15])[::-1], (address, symbol, dest)
        elif symbol.startswith('__ehhandler$'): assert original_data(int(dest, 16), 1) == b'\xb8' and original_data(int(dest, 16)+5, 1) == b'\xe9', (address, symbol, dest)
        elif symbol.startswith(('?flag@?1', '?n@?1', '??_B?1')) and ('doDeclare' in symbol or 'declare' in symbol):
            assert statics.setdefault(symbol, dest) == dest, (address, symbol, dest, statics[symbol])
        elif symbol.startswith('??$callDoDeclare@$1?s'): edges[symbol] = dest
        else: raise AssertionError((address, 'unchecked data target', symbol, dest))
    return name, body, edges, data
for unit, address, prefix, expected in methods:
    name, body, edges, data = check(unit, address, prefix, expected)
    rows.append({'address': address, 'symbol': name, 'size': len(body), 'direct_calls': edges, 'data_targets': data})
# getName pushes &callDoDeclare<sX> as data: it must be the matched callDoDeclare body.
for row in rows:
    for k, v in row['direct_calls'].items():
        if k.startswith('??$callDoDeclare@$1?s'):
            assert any(r['symbol'] == k and int(r['address'], 16) == int(v, 16) for r in rows), (row['address'], k, v)
proposal_rows = []
for address, prefix, signal in (('00666b20', '?onStep@Running'+H, 0x97a504), ('00666bc0', '?onStep@Climbing'+H, 0x97a58c)):
    expected_data['?event_Climbing@Humanoid@RBX@@2V?$SignalDesc@VHumanoid@RBX@@$$A6AXM@Z@Reflection@2@A'] = 0x97a58c
    name, body, edges, data = check('pending', address, prefix, [('?onStep@RunningBase'+H, 0x666410), ('?speedSettled@HumanoidState'+H, 0x643330),
        ('?getHumanoid@HumanoidState'+H, 0x793d50), (FIND, 0x56b620), (SIG, 0x4937f0)] + ([('?onFloorStep@HumanoidState'+H, 0x6444f0)] if 'Running' in prefix else []))
    assert hex(signal) in data.values(), (address, data)
    proposal_rows.append({'address': address, 'symbol': name, 'size': len(body), 'direct_calls': edges, 'data_targets': data})
for unit, address, prefix in folded:
    name, body, edges, data = check(unit, address, prefix, [])
    folded_rows.append({'address': address, 'symbol': name, 'size': len(body)})
for tag, addr, text in (('Running', 0x84cc68, b'Running\0'), ('Landed', 0x84cc70, b'Landed\0'), ('Climbing', 0x84cc78, b'Climbing\0')):
    assert original_data(addr, len(text)) == text
# vtables: compare every slot target of the compiled vtables with the original.
P, F = '6BINamed@2@@', '6BHitTestFilter@2@@'
vtables = {'Balancing': (0x84d0dc, 0x84d0d4, 'leaves'), 'RunningBase': (0x84cc38, 0x84cc30, 'states'),
           'Running': (0x84cc94, 0x84cc8c, 'leaves'), 'Landed': (0x84ac9c, 0x84ac94, 'leaves'), 'Climbing': (0x84acd0, 0x84acc8, 'leaves')}
known = {r['symbol']: int(r['address'], 16) for r in rows + folded_rows}
known.update({'?onStep@HumanoidState'+H: 0x458e90, '?query3@HumanoidState'+H: 0x565950, '?query4@HumanoidState'+H: 0x565950,
              '?query5@HumanoidState'+H: 0x565950, '?getIntendedRotationAboutYAxis@HumanoidState'+H: 0x5e72c0,
              '?filterResult@HumanoidState'+H: 0x6432e0, '?onComputeForce@Balancing'+H: 0x66e6a0,
              '?onStep@RunningBase'+H: 0x666410, '?onComputeForce@RunningBase'+H: 0x666550,
              '?onStep@Running'+H: 0x666b20, '?onStep@Climbing'+H: 0x666bc0, '??_ERunningBase'+H: 0x666520})
deleting = {'Balancing': 0x643d10, 'Running': 0x643580, 'Landed': 0x643580, 'Climbing': 0x643580, 'RunningBase': 0x666520}
vtable_rows = {}
for cls, (pv, fv, unit) in vtables.items():
    raw, functions, (sections, symbols, definitions, _) = index[unit]
    for va, suffix, count in ((pv, P, 9), (fv, F, 1)):
        vname = '??_7'+cls+H+suffix; start, idx = definitions[vname]; sec = sections[idx]; got = {}
        for i in range(sec[7]):
            offset, sym, kind = struct.unpack_from('<IIH', raw, sec[5]+10*i)
            if offset >= start and kind == 6: got[(offset-start)//4] = symbols[sym][0]
        assert len(got) == count, (cls, got)
        for slot, symbol in got.items():
            orig = u(va+4*slot)
            if symbol == '__purecall': want = 0x6a16be
            elif symbol.startswith('??_E'): want = deleting[cls]
            else: want = next((a for k, a in known.items() if symbol.startswith(k)), None)
            assert want == orig, (cls, slot, symbol, hex(orig), want)
        vtable_rows[hex(va)] = {str(k): v for k, v in got.items()}
        assert pe.get_string_at_rva(u(u(va-4)+12)+8-imagebase) == ('.?AV%s@HUMAN@RBX@@' % cls).encode(), hex(va)
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
paths = [Path(__file__).resolve(), header, base_header, calls] + [src for _, src, _ in units]
receipt = dict(revision=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
               sources={str(p.relative_to(root)): sha(p) for p in paths}, objects={k: sha(v) for k, v in objects.items()},
               compiler_build=21022, flags=flags, sizes={'Balancing': 0xa8, 'RunningBase': 0xcc, 'Running': 0xcc, 'Landed': 0xcc, 'Climbing': 0xcc},
               vtables=vtable_rows, methods=rows, folded=folded_rows, proposal_gated=proposal_rows,
               pending=['0066e6a0 Balancing::onComputeForce (Body/Cofm/SimBody layouts)',
                        '00666410 RunningBase::onStep (base helpers 00643360/00643a70/006662f0, getHumanoid 00793d50 not in HumanoidState.h)',
                        '00666550 RunningBase::onComputeForce (Body/Primitive/Cofm layouts, getHumanoid)',
                        '00666b20 Running::onStep, 00666bc0 Climbing::onStep: byte-exact only with the proposed HumanoidState additions (proposal_gated)'],
               scope='Inactive Balancing/RunningBase/Running/Landed/Climbing layouts, constructors, destructors, getName and vtable/RTTI linkage; Humanoid signal declarations come from the declaration-only overlay tests/NativeHumanoidStates1Calls.h (proposal). Field names are analog names. No runtime swap.')
(root/'work/2008-06/shared-layouts/humanoid-states1-working.json').write_text(json.dumps(receipt, indent=2)+'\n')
print('PASS: Balancing/RunningBase/Running/Landed/Climbing layout, %d exact bodies, %d folded bodies, 10 vtables and RTTI; %d onStep bodies exact under the proposed HumanoidState additions' % (len(rows), len(folded_rows), len(proposal_rows)))
