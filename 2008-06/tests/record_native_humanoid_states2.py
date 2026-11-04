"""Verify the inactive Freefall/Flying/Jumping/GettingUp humanoid states against 2008-06."""
import hashlib, json, shutil, struct, subprocess, sys
from pathlib import Path
import pefile
root = Path(__file__).resolve().parents[3]; sys.path.insert(0, str(root))
from roc import match, rebuild
R = root/'rebuild/2008-06'
out = R/'out/native-layouts'; out.mkdir(parents=True, exist_ok=True)
base = json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
common = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')] + ['/fp:fast']
header = R/'native-headers/humanoid/HumanoidStates2.h'
calls = R/'tests/NativeHumanoidStates2Calls.h'
state_header = R/'native-headers/humanoid/HumanoidState.h'
overlay = out/'humanoid-states2-overlay'; (overlay/'humanoid').mkdir(parents=True, exist_ok=True)
shutil.copyfile(calls, overlay/'humanoid'/'Humanoid.h')
(overlay/'humanoid'/'HumanoidState.h').unlink(missing_ok=True)   # stale proposal copy from older runs must not shadow the real header
units = [('layout', R/'tests/NativeHumanoidStates2Layout.cpp', 'NativeHumanoidStates2Layout.obj', []),
         ('states', R/'native-classes/HumanoidStates2.cpp', 'NativeHumanoidStates2.obj', [])]
objects = {}; flags = {}
for name, src, objname, extra in units:
    obj = out/objname; f = ['/I'+str(overlay)] + common + extra + ['/Fo'+str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', f, out); assert code == 0, log
    objects[name] = obj; flags[name] = f
raw = objects['layout'].read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?jumpingFilter@@'))
assert body == bytes.fromhex('8b44240485c0740483c004c333c0c3') and not refs
H = '@HUMAN@RBX@@'
FF, FL, JU, GU = 'Freefall'+H, 'Flying'+H, 'Jumping'+H, 'GettingUp'+H
NB = lambda d, s: '?$Named@V%s@HUMAN@RBX@@$1?s%s@23@3QBDB@RBX@@' % (d, s)
EV = lambda e: '?event_%s@Humanoid@RBX@@' % e
getH = ('?getHumanoid@HumanoidState'+H, 0x793d50)
fire = [('?findSignalInstance@SignalDescriptor@Reflection@RBX@@', 0x56b620), ('??R?$signal1@X_N', 0x5e1f00)]
balancing = ('??0Balancing'+H, 0x66e660); base_dtor = ('??1HumanoidState'+H, 0x6435c0)
head = ('?getHead@Humanoid@RBX@@', 0x5d8a10); torso = ('?getTorso@Humanoid@RBX@@', 0x5d8b10)
setf = ('?setFriction@PartInstance@RBX@@', 0x59e090); getf = ('?getFriction@PartInstance@RBX@@', 0x598d50)
delete = ('??3@YAXPAX@Z', 0x6a067a)
vt = lambda cls, a, b: {'??_7'+cls+'6BINamed@2@@': a, '??_7'+cls+'6BHitTestFilter@2@@': b}
# (address, symbol prefix, call/jump edges, expected data symbol prefixes -> address)
methods = [
    ('00667810', '??0'+FF, [balancing, head, getf, setf, torso] + fire, dict(vt(FF, 0x84cea0, 0x84ce98), **{EV('FreeFalling'): 0x97a47c})),
    ('00667930', '??1'+FF, [getH, head, setf, torso, base_dtor] + fire, dict(vt(FF, 0x84cea0, 0x84ce98), **{EV('FreeFalling'): 0x97a47c})),
    ('00667a20', '??_G'+FF, [('??1'+FF, 0x667930), delete], {}),
    ('00667510', '?onStep@'+FF, [('?computeWalkVelocity@HumanoidState'+H, 0x643b60)], {}),
    ('006674b0', '??0'+FL, [balancing], vt(FL, 0x84ce54, 0x84ce4c)),
    ('00667c40', '??0'+JU, [('??0'+FL, 0x6674b0)] + fire, dict(vt(JU, 0x84ceec, 0x84cee4), **{EV('Jumping'): 0x97a5fc})),
    ('00667cd0', '??1'+JU, [getH, base_dtor] + fire, dict(vt(JU, 0x84ceec, 0x84cee4), **{EV('Jumping'): 0x97a5fc})),
    ('00667d60', '??_G'+JU, [('??1'+JU, 0x667cd0), delete], {}),
    ('00667e20', '??0'+GU, [balancing, getH] + fire, dict(vt(GU, 0x84cf30, 0x84cf28), **{EV('GettingUp'): 0x97a630})),
    ('00667ec0', '??1'+GU, [getH, base_dtor] + fire, dict(vt(GU, 0x84cf30, 0x84cf28), **{EV('GettingUp'): 0x97a630})),
    ('00667f50', '??_G'+GU, [('??1'+GU, 0x667ec0), delete], {}),
]
# Named<...>::getName, Name::doDeclare<sX> and Name::callDoDeclare<sX> per class:
# (getName, callDoDeclare, doDeclare, once flag, static guard, static value, string, Named base, s-name)
names = [(0x6677f0, 0x6677e0, 0x667560, 0x97d9e4, 0x97d9e0, 0x97d9dc, 0x84ce88, 'Balancing', 'Freefall'),
         (0x6674f0, 0x6674a0, 0x667430, 0x97d9d8, 0x97d9d4, 0x97d9d0, 0x84ce40, 'Balancing', 'Flying'),
         (0x667c20, 0x667c10, 0x667ba0, 0x97d9f0, 0x97d9ec, 0x97d9e8, 0x84ced8, 'Flying', 'Jumping'),
         (0x667e00, 0x667df0, 0x667d80, 0x97d9fc, 0x97d9f8, 0x97d9f4, 0x84cf18, 'Balancing', 'GettingUp')]
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
    assert len(hits) == 1, (address, prefix, [x[0] for x in functions])
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
# Identical-code-folded virtuals: bodies compile byte-identical to shared addresses.
folded = [('005e2790', '?getStateType@'+FF), ('006fa3f0', '?getStateType@'+FL), ('0077d810', '?getStateType@'+JU),
          ('007286a0', '?getStateType@'+GU), ('0060a2f0', '?query3@'+FF), ('0060a2f0', '?query4@'+FF),
          ('0060a2f0', '?query3@'+JU), ('0060a2f0', '?query4@'+JU), ('0060a2f0', '?query3@'+GU), ('0060a2f0', '?query4@'+GU),
          ('0070bdf0', '?onComputeForce@'+FL), ('00643d10', '??_G'+FL)]
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
S = lambda s: '?'+s[1:] if s.startswith('??') else s
common_slots = {7: ('?getIntendedRotationAboutYAxis@HumanoidState'+H, 0x5e72c0)}
vtables = {
    FF: (0x84cea0, 0x84ce98, {0: ('?getName@'+NB('Balancing', 'Freefall'), 0x6677f0), 1: ('?onStep@'+FF, 0x667510), 2: ('?getStateType@'+FF, 0x5e2790),
         3: ('?query3@'+FF, 0x60a2f0), 4: ('?query4@'+FF, 0x60a2f0), 5: ('?query5@HumanoidState'+H, 0x565950), 6: ('??_E'+FF, 0x667a20),
         8: ('?onComputeForce@'+FF, 0x6675d0)}),
    FL: (0x84ce54, 0x84ce4c, {0: ('?getName@'+NB('Balancing', 'Flying'), 0x6674f0), 1: ('?onStep@HumanoidState'+H, 0x458e90), 2: ('?getStateType@'+FL, 0x6fa3f0),
         3: ('?query3@HumanoidState'+H, 0x565950), 4: ('?query4@HumanoidState'+H, 0x565950), 5: ('?query5@HumanoidState'+H, 0x565950),
         6: ('??_E'+FL, 0x643d10), 8: ('?onComputeForce@'+FL, 0x70bdf0)}),
    JU: (0x84ceec, 0x84cee4, {0: ('?getName@'+NB('Flying', 'Jumping'), 0x667c20), 1: ('?onStep@HumanoidState'+H, 0x458e90), 2: ('?getStateType@'+JU, 0x77d810),
         3: ('?query3@'+JU, 0x60a2f0), 4: ('?query4@'+JU, 0x60a2f0), 5: ('?query5@HumanoidState'+H, 0x565950), 6: ('??_E'+JU, 0x667d60),
         8: ('?onComputeForce@'+JU, 0x667a40)}),
    GU: (0x84cf30, 0x84cf28, {0: ('?getName@'+NB('Balancing', 'GettingUp'), 0x667e00), 1: ('?onStep@HumanoidState'+H, 0x458e90), 2: ('?getStateType@'+GU, 0x7286a0),
         3: ('?query3@'+GU, 0x60a2f0), 4: ('?query4@'+GU, 0x60a2f0), 5: ('?query5@HumanoidState'+H, 0x565950), 6: ('??_E'+GU, 0x667f50),
         8: ('?onComputeForce@Balancing'+H, 0x66e6a0)}),
}
type_names = set(s[0] for s in (symbols.values() if isinstance(symbols, dict) else symbols) if isinstance(s, (tuple, list)))
vtable_rows = {}
for cls, (primary, filt, expected_slots) in vtables.items():
    p = slots('??_7'+cls+'6BINamed@'); fs = slots('??_7'+cls+'6BHitTestFilter@')
    expected_slots = {**common_slots, **expected_slots}
    assert len(p) == 9, (cls, p)
    for slot, (symbol, address) in expected_slots.items():
        assert p[slot].startswith(symbol) and u(primary+4*slot) == address, (cls, slot, p[slot], hex(u(primary+4*slot)))
    assert len(fs) == 1 and fs[0].startswith('?filterResult@HumanoidState'+H) and u(filt) == 0x6432e0, (cls, fs)
    # RTTI: every base class name in the original hierarchy has a matching compiled type descriptor.
    chd = u(u(primary-4)+16); n = u(chd+8); bca = u(chd+12); bases = []
    for i in range(n):
        td = u(u(bca+4*i)); bases.append(pe.get_string_at_rva(td+8-imagebase).decode())
    assert bases[0] == '.?AV'+cls, (cls, bases)
    for b in bases:
        assert '??_R0'+b[1:]+'@8' in type_names, (cls, b)
    assert pe.get_string_at_rva(u(u(filt-4)+12)+8-imagebase).decode() == '.?AV'+cls
    vtable_rows[cls] = {'primary': hex(primary), 'filter': hex(filt), 'rtti_bases': bases}
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
paths = [Path(__file__).resolve(), header, calls, state_header, R/'native-headers/humanoid/HumanoidStates1.h'] + [src for _, src, _, _ in units]
receipt = dict(revision=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip() if (root/'.git').exists() else None,
               sources={str(p.relative_to(root)): sha(p) for p in paths}, objects={k: sha(v) for k, v in objects.items()},
               compiler_build=21022, flags=flags, sizes={'Freefall': 0xc0, 'Flying': 0xa8, 'Jumping': 0xa8, 'GettingUp': 0xa8},
               vtables=vtable_rows, methods=rows, folded_virtual_defaults=folded_rows,
               pending=['006675d0 Freefall::onComputeForce (Body/Cofm/SimBody layouts, Velocity statics)',
                        '00667a40 Jumping::onComputeForce (floor primitive getter 00643d30, Body/Cofm/SimBody layouts; calls Flying::onComputeForce out of line)'],
               scope='Inactive Freefall/Flying/Jumping/GettingUp layouts, constructors, destructors, onStep, Named getName/doDeclare instantiations, vtables and RTTI. Humanoid declarations come from the declaration-only overlay tests/NativeHumanoidStates2Calls.h (proposal). Member names are analog names. No runtime swap.')
(root/'work/2008-06/shared-layouts/humanoid-states2-working.json').write_text(json.dumps(receipt, indent=2)+'\n')
print('PASS: Freefall/Flying/Jumping/GettingUp layouts, %d exact bodies, %d folded virtuals, 4 vtable pairs and RTTI' % (len(rows), len(folded_rows)))
