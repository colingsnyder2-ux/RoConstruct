"""Verify the inactive Seated/Dead/FallingDown and MovingNoPhysicsBase/RunningNoPhysics/StrafingNoPhysics
humanoid states against 2008-06."""
import hashlib, json, shutil, struct, subprocess, sys
from pathlib import Path
import pefile
root = Path(__file__).resolve().parents[3]; sys.path.insert(0, str(root))
from roc import match, rebuild
R = root/'rebuild/2008-06'
out = R/'out/native-layouts'; out.mkdir(parents=True, exist_ok=True)
base = json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
common = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')] + ['/fp:fast']
header = R/'native-headers/humanoid/HumanoidStates3.h'
calls = R/'tests/NativeHumanoidStates3Calls.h'
simjob = R/'tests/NativeHumanoidStates3SimJob.h'
state_header = R/'native-headers/humanoid/HumanoidState.h'
overlay = out/'humanoid-states3-overlay'
for d in ('humanoid', 'v8world'): (overlay/d).mkdir(parents=True, exist_ok=True)
shutil.copyfile(calls, overlay/'humanoid'/'Humanoid.h')
shutil.copyfile(simjob, overlay/'v8world'/'SimJob.h')
# Proposed base declaration (not in the shared header yet): HumanoidState::getHumanoid(), the
# out-of-line getter 00793d50 (mov eax,[ecx+8]; ret) called from 006670b0, 00666e30, 00666ec0, 0066eaa0.
text = state_header.read_text(); anchor = '    void setLimbFlag(bool value);'
assert text.count(anchor) == 1
proposal = '    Humanoid* getHumanoid() const;                                    // 00793d50 (proposed)\n'
(overlay/'humanoid'/'HumanoidState.h').write_text(text.replace(anchor, proposal + anchor))
PENDING = ['/DNATIVE_HUMANOID_STATE_PENDING', '/DNATIVE_SIMJOB_PENDING']
units = [('layout', R/'tests/NativeHumanoidStates3Layout.cpp', 'NativeHumanoidStates3Layout.obj', ['/DNATIVE_SIMJOB_PENDING']),
         ('states', R/'native-classes/HumanoidStates3.cpp', 'NativeHumanoidStates3.obj', PENDING)]
objects = {}; flags = {}
for name, src, objname, extra in units:
    obj = out/objname; f = ['/I'+str(overlay)] + common + extra + ['/Fo'+str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', f, out); assert code == 0, log
    objects[name] = obj; flags[name] = f
# Without the pending defines the unit and layout test must still compile (guarded parts drop out).
for src, objname in ((R/'native-classes/HumanoidStates3.cpp', 'NativeHumanoidStates3Guarded.obj'),
                     (R/'tests/NativeHumanoidStates3Layout.cpp', 'NativeHumanoidStates3LayoutGuarded.obj')):
    f = ['/I'+str(overlay)] + common + ['/Fo'+str(out/objname), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', f, out); assert code == 0, log
raw = objects['layout'].read_bytes(); lf = match.coff_functions(raw)
name, body, refs = next(x for x in lf if x[0].startswith('?seatedFilter@@'))
assert body == bytes.fromhex('8b44240485c0740483c004c333c0c3') and not refs
name, body, refs = next(x for x in lf if x[0].startswith('?movingJob@@'))
assert body == bytes.fromhex('8b44240485c0740605a0000000c333c0c3') and not refs   # SimJob at +0xa0
H = '@HUMAN@RBX@@'
SE, DE, FD, MB, RN, SN = 'Seated'+H, 'Dead'+H, 'FallingDown'+H, 'MovingNoPhysicsBase'+H, 'RunningNoPhysics'+H, 'StrafingNoPhysics'+H
NB = lambda d, s: '?$Named@V%s@HUMAN@RBX@@$1?s%s@23@3QBDB@RBX@@' % (d, s)
EV = lambda e: '?event_%s@Humanoid@RBX@@' % e
getH = ('?getHumanoid@HumanoidState'+H, 0x793d50)
fire = [('?findSignalInstance@SignalDescriptor@Reflection@RBX@@', 0x56b620), ('??R?$signal1@X_N', 0x5e1f00)]
firef = [('?findSignalInstance@SignalDescriptor@Reflection@RBX@@', 0x56b620), ('??R?$signal1@XM', 0x4937f0)]
state_ctor = ('??0HumanoidState'+H, 0x643e00); base_dtor = ('??1HumanoidState'+H, 0x6435c0)
moving_ctor = ('??0'+MB, 0x66f070)
delete = ('??3@YAXPAX@Z', 0x6a067a)
vt = lambda cls, a, b: {'??_7'+cls+'6BINamed@2@@': a, '??_7'+cls+'6BHitTestFilter@2@@': b}
vt3 = lambda cls, a, b, c: dict(vt(cls, a, b), **{'??_7'+cls+'6B@': c})
# (address, symbol prefix, call/jump edges, expected data symbol prefixes -> address)
methods = [
    ('00667010', '??0'+SE, [state_ctor, ('?setLimbFlag@HumanoidState'+H, 0x6431b0)] + fire, dict(vt(SE, 0x84cd54, 0x84cd4c), **{EV('Seated'): 0x97a558})),
    ('006670b0', '??1'+SE, [getH, base_dtor] + fire, dict(vt(SE, 0x84cd54, 0x84cd4c), **{EV('Seated'): 0x97a558})),
    ('00667140', '??_G'+SE, [('??1'+SE, 0x6670b0), delete], {}),
    ('00666d30', '??0'+DE, [state_ctor, ('?getCharacterFromHumanoid@Humanoid@RBX@@', 0x5d7670), ('?breakJoints@ModelInstance@RBX@@', 0x584c00)], vt(DE, 0x84cce0, 0x84ccd8)),
    ('00666da0', '??_G'+DE, [base_dtor, delete], vt(DE, 0x84cce0, 0x84ccd8)),
    ('00666e30', '??0'+FD, [state_ctor, getH] + fire, dict(vt(FD, 0x84cd10, 0x84cd08), **{EV('FallingDown'): 0x97a2f4})),
    ('00666ec0', '??1'+FD, [getH, base_dtor] + fire, dict(vt(FD, 0x84cd10, 0x84cd08), **{EV('FallingDown'): 0x97a2f4})),
    ('00666f50', '??_G'+FD, [('??1'+FD, 0x666ec0), delete], {}),
    ('0066ee10', '??1'+MB, [('?release@'+MB, 0x66ed50), ('??1scoped_connection@signals@boost@@', 0x5954b0), base_dtor, delete],
     dict(vt3(MB, 0x84d168, 0x84d160, 0x84d150), **{'??_7SimJob@RBX@@6B@': 0x83f72c})),
    ('00667410', '??_G'+MB, [('??1'+MB, 0x66ee10), delete], {}),
    ('0066eaa0', '?getTorsoAssembly@'+MB, [getH, ('?getTorsoPrimitive@Humanoid@RBX@@', 0x5d90a0), ('?getAssembly@Primitive@RBX@@', 0x5e7570)], {}),
    ('00667160', '?getAssembly@'+MB, [('?getTorsoAssembly@'+MB, 0x66eaa0)], {}),
    ('00667370', '??0'+RN, [moving_ctor] + firef, dict(vt3(RN, 0x84ce10, 0x84ce08, 0x84cdf8), **{EV('Running'): 0x97a504})),
    ('006672b0', '?onStep@'+RN, [('?onStep@'+MB, 0x66f2c0)], {}),
    ('00667210', '??0'+SN, [moving_ctor] + fire, dict(vt3(SN, 0x84cdb0, 0x84cda8, 0x84cd98), **{EV('Strafing'): 0x97a348})),
]
# Named<...>::getName, Name::callDoDeclare<sX> and Name::doDeclare<sX> per class:
# (getName, callDoDeclare, doDeclare, once flag, static guard, static value, string, Named base, s-name)
names = [(0x666ff0, 0x666fe0, 0x666f70, 0x97d9b4, 0x97d9b0, 0x97d9ac, 0x84cd40, 'HumanoidState', 'Seated'),
         (0x666df0, 0x666dd0, 0x666c50, 0x97d9a4, 0x97d998, 0x97d994, 0x84cccc, 'HumanoidState', 'Dead'),
         (0x666e10, 0x666de0, 0x666cc0, 0x97d9a8, 0x97d9a0, 0x97d99c, 0x84ccc0, 'HumanoidState', 'FallingDown'),
         (0x66edf0, 0x66eca0, 0x66eac0, 0x97da50, 0x97da4c, 0x97da48, 0x84d108, 'HumanoidState', 'MovingNoPhysicsBase'),
         (0x667350, 0x667340, 0x6672d0, 0x97d9cc, 0x97d9c8, 0x97d9c4, 0x84cde0, 'MovingNoPhysicsBase', 'RunningNoPhysics'),
         (0x6671f0, 0x6671e0, 0x667170, 0x97d9c0, 0x97d9bc, 0x97d9b8, 0x84cd80, 'MovingNoPhysicsBase', 'StrafingNoPhysics')]
for getname, cdd, dd, flag, guard, value, string, d, s in names:
    sname = '?s%s@HUMAN@RBX@@3QBDB' % s
    dd_sym = '??$doDeclare@$1'+sname+'@Name@RBX@@'; cdd_sym = '??$callDoDeclare@$1'+sname+'@Name@RBX@@'
    methods.append(('%08x' % getname, '?getName@'+NB(d, s), [('?call_once@boost@@', 0x557330), (dd_sym, dd)],
                    {cdd_sym: cdd, '?flag@?1???$declare@$1'+sname: flag}))
    methods.append(('%08x' % cdd, cdd_sym, [(dd_sym, dd)], {}))
    methods.append(('%08x' % dd, dd_sym, [('?declare@Name@RBX@@SAABV12@PBDH@Z', 0x553f90)],
                    {'?n@?1???$doDeclare@$1'+sname: value, '??_B?1???$doDeclare@$1'+sname: guard, '?s%s@HUMAN@RBX@@' % s: string}))
pe = pefile.PE(str(root/'clients/2008-06/Roblox.exe'), fast_load=True); imagebase = pe.OPTIONAL_HEADER.ImageBase
original_data = lambda va, n: pe.get_data(va-imagebase, n)
raw = objects['states'].read_bytes(); functions = match.coff_functions(raw)
sections, symbols, definitions, _ = match._coff_data_index(raw); rows = []
for address, prefix, expected, expected_data in methods:
    hits = [x for x in functions if x[0].startswith(prefix)]
    assert len(hits) == 1, (address, prefix, [x[0] for x in hits])
    name, body, refs = hits[0]
    target, targetrefs, _ = match.target('2008-06', address)
    assert match.exact_match(target, targetrefs, body, refs), (address, name, len(body), len(target))
    start, idx = definitions[name]; tab = sections[idx]; edges = {}; data = {}
    for i in range(tab[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, tab[5]+10*i); offset -= start
        if not 0 <= offset <= len(body)-4: continue
        if kind == 20:
            edges[symbols[index][0]] = hex(int(address, 16)+offset+4+struct.unpack_from('<i', target, offset)[0])
        elif kind == 6:
            data[symbols[index][0]] = hex(struct.unpack_from('<I', target, offset)[0])
    assert len(edges) == len(expected), (address, edges)
    for symbol, dest in expected:
        assert any(k.startswith(symbol) and v == hex(dest) for k, v in edges.items()), (address, symbol, edges)
    for symbol, dest in data.items():
        known = [v for k, v in expected_data.items() if symbol.startswith(k)]
        if known:
            assert dest == hex(known[0]), (address, symbol, dest)
        elif symbol.startswith('__real@'):
            assert original_data(int(dest, 16), 4) == bytes.fromhex(symbol[7:15])[::-1], (address, symbol, dest)
        elif symbol.startswith('__ehhandler$'):
            assert original_data(int(dest, 16), 1) == b'\xb8' and original_data(int(dest, 16)+5, 1) == b'\xe9', (address, symbol, dest)
        else:
            raise AssertionError((address, 'unchecked data target', symbol, dest))
    assert all(any(k.startswith(p) for k in data) for p in expected_data), (address, data)
    rows.append({'address': address, 'symbol': name, 'size': len(body), 'direct_calls': edges, 'data_targets': data})
for _, _, _, _, _, _, string, _, s in names:
    assert original_data(string, len(s)+1) == s.encode()+b'\0', s
# Identical-code-folded or shared-constant virtuals: bodies compile byte-identical to the shared addresses.
folded = [('006670a0', '?getStateType@'+SE), ('00666c40', '?getStateType@'+DE), ('00416690', '?getStateType@'+FD),
          ('0077d800', '?getStateType@'+MB), ('0063e420', '?getStateType@'+SN),
          ('0060a2f0', '?query3@'+SE), ('0060a2f0', '?query4@'+SE),
          ('0060a2f0', '?query3@'+MB), ('0060a2f0', '?query4@'+MB), ('0060a2f0', '?query5@'+MB),
          ('00667160', '?getAssembly2@'+MB), ('006672b0', '?onStep@'+SN),
          ('00667410', '??_G'+RN), ('00667410', '??_G'+SN)]
folded_rows = []
for address, prefix in folded:
    name, body, refs = next(x for x in functions if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', address)
    assert match.exact_match(target, targetrefs, body, refs), (address, prefix)
    folded_rows.append({'address': address, 'symbol': name, 'size': len(body)})
u = lambda va: struct.unpack('<I', pe.get_data(va-imagebase, 4))[0]
def slots(prefix):
    vname = next(n for n in definitions if n.startswith(prefix)); start, index = definitions[vname]; section = sections[index]; res = {}
    for i in range(section[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5]+10*i)
        if offset >= start and kind == 6: res[(offset-start)//4] = symbols[symbol][0]
    return res
HS = lambda m: '?'+m+'@HumanoidState'+H
common_slots = {7: (HS('getIntendedRotationAboutYAxis'), 0x5e72c0), 8: (HS('onComputeForce'), 0x70bdf0)}
vtables = {
    SE: (0x84cd54, 0x84cd4c, None, {0: ('?getName@'+NB('HumanoidState', 'Seated'), 0x666ff0), 1: (HS('onStep'), 0x458e90), 2: ('?getStateType@'+SE, 0x6670a0),
         3: ('?query3@'+SE, 0x60a2f0), 4: ('?query4@'+SE, 0x60a2f0), 5: (HS('query5'), 0x565950), 6: ('??_E'+SE, 0x667140)}),
    DE: (0x84cce0, 0x84ccd8, None, {0: ('?getName@'+NB('HumanoidState', 'Dead'), 0x666df0), 1: (HS('onStep'), 0x458e90), 2: ('?getStateType@'+DE, 0x666c40),
         3: (HS('query3'), 0x565950), 4: (HS('query4'), 0x565950), 5: (HS('query5'), 0x565950), 6: ('??_E'+DE, 0x666da0)}),
    FD: (0x84cd10, 0x84cd08, None, {0: ('?getName@'+NB('HumanoidState', 'FallingDown'), 0x666e10), 1: (HS('onStep'), 0x458e90), 2: ('?getStateType@'+FD, 0x416690),
         3: (HS('query3'), 0x565950), 4: (HS('query4'), 0x565950), 5: (HS('query5'), 0x565950), 6: ('??_E'+FD, 0x666f50)}),
    MB: (0x84d168, 0x84d160, 0x84d150, {0: ('?getName@'+NB('HumanoidState', 'MovingNoPhysicsBase'), 0x66edf0), 1: ('?onStep@'+MB, 0x66f2c0), 2: ('?getStateType@'+MB, 0x77d800),
         3: ('?query3@'+MB, 0x60a2f0), 4: ('?query4@'+MB, 0x60a2f0), 5: ('?query5@'+MB, 0x60a2f0), 6: ('??_E'+MB, 0x667410)}),
    RN: (0x84ce10, 0x84ce08, 0x84cdf8, {0: ('?getName@'+NB('MovingNoPhysicsBase', 'RunningNoPhysics'), 0x667350), 1: ('?onStep@'+RN, 0x6672b0), 2: ('?getStateType@'+MB, 0x77d800),
         3: ('?query3@'+MB, 0x60a2f0), 4: ('?query4@'+MB, 0x60a2f0), 5: ('?query5@'+MB, 0x60a2f0), 6: ('??_E'+RN, 0x667410)}),
    SN: (0x84cdb0, 0x84cda8, 0x84cd98, {0: ('?getName@'+NB('MovingNoPhysicsBase', 'StrafingNoPhysics'), 0x6671f0), 1: ('?onStep@'+SN, 0x6672b0), 2: ('?getStateType@'+SN, 0x63e420),
         3: ('?query3@'+MB, 0x60a2f0), 4: ('?query4@'+MB, 0x60a2f0), 5: ('?query5@'+MB, 0x60a2f0), 6: ('??_E'+SN, 0x667410)}),
}
# SimJob-in-MovingNoPhysicsBase vtables: slot 0 adjustor thunk 00667400 (sub ecx,0xa0; jmp 00667410),
# slots 1/2 are the overrides themselves (00667160, matched above); the compiled thunk is checked by bytes.
thunk_rows = []
def check_thunk(symbol, address, dest):
    name, body, refs = next(x for x in functions if x[0] == symbol)
    target = original_data(address, len(body))
    assert body[:-4] == target[:-4], (symbol, body.hex(), target.hex())
    assert address+len(body)+struct.unpack('<i', target[-4:])[0] == dest, (symbol, hex(address))
    thunk_rows.append({'address': '%08x' % address, 'symbol': symbol, 'size': len(body), 'jump': hex(dest)})
type_names = set(s[0] for s in symbols.values())
vtable_rows = {}
for cls, (primary, filt, job, expected_slots) in vtables.items():
    p = slots('??_7'+cls+'6BINamed@'); fs = slots('??_7'+cls+'6BHitTestFilter@')
    expected_slots = {**common_slots, **expected_slots}
    assert len(p) == 9, (cls, p)
    for slot, (symbol, address) in expected_slots.items():
        assert p[slot].startswith(symbol) and u(primary+4*slot) == address, (cls, slot, p[slot], hex(u(primary+4*slot)))
    assert len(fs) == 1 and fs[0].startswith(HS('filterResult')) and u(filt) == 0x6432e0, (cls, fs)
    row = {'primary': hex(primary), 'filter': hex(filt)}
    if job:
        js = slots('??_7'+cls+'6B@')  # MSVC names the SimJob-subobject vtable 6B@
        assert len(js) == 3, (cls, js)
        assert u(job) == 0x667400 and u(job+4) == 0x667160 and u(job+8) == 0x667160, cls
        assert js[0].startswith('??_E'+cls) and js[1].startswith('?getAssembly@'+MB) and js[2].startswith('?getAssembly2@'+MB), (cls, js)
        if cls == MB:
            check_thunk(js[0], 0x667400, 0x667410)
        assert pe.get_string_at_rva(u(u(job-4)+12)+8-imagebase).decode() == '.?AV'+cls
        row['simjob'] = hex(job)
    chd = u(u(primary-4)+16); n = u(chd+8); bca = u(chd+12); bases = []
    for i in range(n):
        td = u(u(bca+4*i)); bases.append(pe.get_string_at_rva(td+8-imagebase).decode())
    assert bases[0] == '.?AV'+cls, (cls, bases)
    for b in bases:
        assert '??_R0'+b[1:]+'@8' in type_names, (cls, b)
    assert pe.get_string_at_rva(u(u(filt-4)+12)+8-imagebase).decode() == '.?AV'+cls
    row['rtti_bases'] = bases; vtable_rows[cls] = row
assert u(0x83f72c-4) and pe.get_string_at_rva(u(u(0x83f72c-4)+12)+8-imagebase) == b'.?AVSimJob@RBX@@'
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
paths = [Path(__file__).resolve(), header, calls, simjob, state_header] + [src for _, src, _, _ in units]
receipt = dict(revision=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip() if (root/'.git').exists() else None,
               sources={str(p.relative_to(root)): sha(p) for p in paths}, objects={k: sha(v) for k, v in objects.items()},
               compiler_build=21022, flags=flags,
               sizes={'Seated': 0xa0, 'Dead': 0xa0, 'FallingDown': 0xa0, 'SimJob': 0x24, 'MovingNoPhysicsBase': 0x114, 'RunningNoPhysics': 0x114, 'StrafingNoPhysics': 0x114},
               vtables=vtable_rows, methods=rows, folded_virtual_defaults=folded_rows, adjustor_thunks=thunk_rows,
               proposed_declarations=['HumanoidState::getHumanoid() const, out-of-line 00793d50 (006670b0, 00666e30, 00666ec0, 0066eaa0 compile only with NATIVE_HUMANOID_STATE_PENDING and the recorder overlay)',
                                      'RBX::SimJob (tests/NativeHumanoidStates3SimJob.h, sizeof 0x24): MovingNoPhysicsBase family compiles only with NATIVE_SIMJOB_PENDING',
                                      'Humanoid/Primitive/ModelInstance call declarations in tests/NativeHumanoidStates3Calls.h'],
               pending=['0066f070 MovingNoPhysicsBase constructor (PhysicsService, World/SimJobStage, connection to 0x973c38 via 004a3340, boost::bind of 0066edc0)',
                        '0066f2c0 MovingNoPhysicsBase::onStep (Body/Primitive/World layouts, 00643a70/00643360)',
                        '0066ed50 MovingNoPhysicsBase::release (Humanoid+0x21c World, SimJobStage, PhysicsService, Primitive 005e8140)',
                        '005e50f0/005e5150/005e5190 SimJob constructor/destructors (declaration proposal only)'],
               scope='Inactive Seated/Dead/FallingDown/MovingNoPhysicsBase/RunningNoPhysics/StrafingNoPhysics layouts, constructors, destructors, onStep forwarder, SimJob slot overrides and their helper, Named getName/doDeclare instantiations, vtables, adjustor thunks and RTTI. Humanoid/Primitive/ModelInstance/SimJob declarations come from recorder overlays (proposals). Member names are analog names. No runtime swap.')
(root/'work/2008-06/shared-layouts/humanoid-states3-working.json').write_text(json.dumps(receipt, indent=2)+'\n')
print('PASS: Seated/Dead/FallingDown/MovingNoPhysicsBase/RunningNoPhysics/StrafingNoPhysics layouts, %d exact bodies, %d folded virtuals, %d thunks, 6 vtable sets and RTTI'
      % (len(rows), len(folded_rows), len(thunk_rows)))
