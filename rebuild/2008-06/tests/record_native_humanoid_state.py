"""Verify the inactive HumanoidState base layout, lifetime and base methods against 2008-06."""
import hashlib, json, shutil, struct, subprocess, sys
from pathlib import Path
import pefile
root = Path(__file__).resolve().parents[3]; sys.path.insert(0, str(root))
from roc import match, rebuild
out = root/'rebuild/2008-06/out/native-layouts'; out.mkdir(parents=True, exist_ok=True)
base = json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
common = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')] + ['/fp:fast']
header = root/'rebuild/2008-06/native-headers/humanoid/HumanoidState.h'
calls = root/'rebuild/2008-06/tests/NativeHumanoidStateCalls.h'
overlay = out/'humanoid-state-overlay'; (overlay/'humanoid').mkdir(parents=True, exist_ok=True)
shutil.copyfile(calls, overlay/'humanoid'/'Humanoid.h')
units = [('layout', root/'rebuild/2008-06/tests/NativeHumanoidStateLayout.cpp', 'NativeHumanoidStateLayout.obj'),
         ('state', root/'rebuild/2008-06/native-classes/HumanoidState.cpp', 'NativeHumanoidState.obj')]
objects = {}; flags = {}
for name, src, objname in units:
    obj = out/objname; f = ['/I'+str(overlay)] + common + ['/Fo'+str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', f, out); assert code == 0, log
    objects[name] = obj; flags[name] = f
raw = objects['layout'].read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?humanoidStateFilter@@'))
assert body == bytes.fromhex('8b44240485c0740483c004c333c0c3') and not refs
S = '@HumanoidState@HUMAN@RBX@@'
methods = [
    ('00643e00', '??0'+S[1:], [('?setJump@Humanoid@RBX@@', 0x5dc270), ('?setStrafe@Humanoid@RBX@@', 0x5dc230), ('?setLimbFlag'+S, 0x6431b0), ('??0CoordinateFrame@G3D@@', 0x4782d0)]),
    ('006435c0', '??1'+S[1:], [('?setLimbFlag'+S, 0x6431b0), ('?alignedFree@System@G3D@@', 0x507d20)]),
    ('00643d10', '??_G'+S[1:], [('??1'+S[1:], 0x6435c0), ('??3@YAXPAX@Z', 0x6a067a)]),
    ('00643330', '?speedSettled'+S, []),
    ('00643b60', '?computeWalkVelocity'+S, [('?getIntendedMovementVector@Humanoid@RBX@@', 0x5d9c10)]),
    ('00643bc0', '?setLegsFlag'+S, [('?getLeftLegPrimitive@Humanoid@RBX@@', 0x5d90c0), ('?getRightLegPrimitive@Humanoid@RBX@@', 0x5d90e0), ('?setFlagAB@Primitive@RBX@@', 0x5e75e0)]),
    ('00643c20', '?setArmsFlag'+S, [('?getLeftArmPrimitive@Humanoid@RBX@@', 0x5d9120), ('?getRightArmPrimitive@Humanoid@RBX@@', 0x5d9140), ('?setFlagAB@Primitive@RBX@@', 0x5e75e0)]),
    ('00643c80', '?setTorsoHeadFlag'+S, [('?getTorsoPrimitive@Humanoid@RBX@@', 0x5d90a0), ('?getHeadPrimitive@Humanoid@RBX@@', 0x5d9100), ('?setFlagAB@Primitive@RBX@@', 0x5e75e0)]),
]
# Inline virtual defaults: identical-code-folded in the original, so their slot targets are shared bodies.
folded = [('00458e90', '?onStep'+S), ('00565950', '?query3'+S), ('00565950', '?query4'+S), ('00565950', '?query5'+S),
          ('005e72c0', '?getIntendedRotationAboutYAxis'+S), ('0070bdf0', '?onComputeForce'+S)]
pe = pefile.PE(str(root/'clients/2008-06/Roblox.exe'), fast_load=True); imagebase = pe.OPTIONAL_HEADER.ImageBase
original_data = lambda va, n: pe.get_data(va-imagebase, n)
expected_data = {'??_7HitTestFilter@RBX@@6B@': '0x843a40', '??_7'+S[1:]+'6BINamed@2@@': '0x84ad00', '??_7'+S[1:]+'6BHitTestFilter@2@@': '0x84acf8'}
raw = objects['state'].read_bytes(); functions = match.coff_functions(raw)
sections, symbols, definitions, _ = match._coff_data_index(raw); rows = []
for address, prefix, expected in methods:
    name, body, refs = next(x for x in functions if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', address)
    assert match.exact_match(target, targetrefs, body, refs), (address, len(body), len(target))
    start, idx = definitions[name]; tab = sections[idx]; edges = {}
    for i in range(tab[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, tab[5]+10*i); offset -= start
        if 0 <= offset <= len(body)-4 and kind == 20:
            edges[symbols[index][0]] = hex(int(address, 16)+offset+4+struct.unpack_from('<i', target, offset)[0])
    for symbol, dest in expected:
        assert any(k.startswith(symbol) and v == hex(dest) for k, v in edges.items()), (address, symbol, edges)
    data = {}
    for i in range(tab[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, tab[5]+10*i); offset -= start
        if 0 <= offset <= len(body)-4 and kind == 6:
            data[symbols[index][0]] = hex(struct.unpack_from('<I', target, offset)[0])
    for symbol, dest in data.items():
        if symbol in expected_data:
            assert dest == expected_data[symbol], (address, symbol, dest)
        elif symbol.startswith('__real@'):
            assert original_data(int(dest, 16), 4) == bytes.fromhex(symbol[7:15])[::-1], (address, symbol, dest)
        elif symbol.startswith('__ehhandler$'):
            assert original_data(int(dest, 16), 1) == b'\xb8' and original_data(int(dest, 16)+5, 1) == b'\xe9', (address, symbol, dest)
        else:
            raise AssertionError((address, 'unchecked data target', symbol, dest))
    rows.append({'address': address, 'symbol': name, 'size': len(body), 'direct_calls': edges, 'data_targets': data})
folded_rows = []
for address, prefix in folded:
    name, body, refs = next(x for x in functions if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', address)
    assert match.exact_match(target, targetrefs, body, refs), (address, prefix)
    folded_rows.append({'address': address, 'symbol': name, 'size': len(body)})
u = lambda va: struct.unpack('<I', pe.get_data(va-imagebase, 4))[0]
def slots(prefix):
    vname = next(n for n in definitions if n.startswith(prefix)); start, index = definitions[vname]; section = sections[index]; out = {}
    for i in range(section[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5]+10*i)
        if offset >= start and kind == 6: out[(offset-start)//4] = symbols[symbol][0]
    return out
primary = slots('??_7'+S[1:]+'6BINamed@'); filt = slots('??_7'+S[1:]+'6BHitTestFilter@')
expected_primary = {0: ('__purecall', 0x6a16be), 1: ('?onStep', 0x458e90), 2: ('__purecall', 0x6a16be), 3: ('?query3', 0x565950), 4: ('?query4', 0x565950),
                    5: ('?query5', 0x565950), 6: ('??_EHumanoidState', 0x643d10), 7: ('?getIntendedRotationAboutYAxis', 0x5e72c0), 8: ('?onComputeForce', 0x70bdf0)}
assert len(primary) == 9, primary
for slot, (symbol, address) in expected_primary.items():
    assert primary[slot].startswith(symbol) and u(0x84ad00+4*slot) == address, (slot, primary[slot], hex(u(0x84ad00+4*slot)))
assert filt[0].startswith('?filterResult'+S) and u(0x84acf8) == 0x6432e0 and len(filt) == 1
locator = u(0x84ad00-4); typedesc = u(locator+12)
assert pe.get_string_at_rva(typedesc+8-imagebase) == b'.?AVHumanoidState@HUMAN@RBX@@'
for vt, cls in ((0x84acf8, b'.?AVHumanoidState@HUMAN@RBX@@'), (0x843a40, b'.?AVHitTestFilter@RBX@@')):
    assert pe.get_string_at_rva(u(u(vt-4)+12)+8-imagebase) == cls, hex(vt)
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
paths = [Path(__file__).resolve(), header, calls] + [src for _, src, _ in units]
receipt = dict(revision=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
               sources={str(p.relative_to(root)): sha(p) for p in paths}, objects={k: sha(v) for k, v in objects.items()},
               compiler_build=21022, flags=flags, size=0xa0, primary_vtable='0x84ad00', filter_vtable='0x84acf8',
               methods=rows, folded_virtual_defaults=folded_rows,
               pending=['006432e0 filterResult (Primitive +0xa8/+0xab layout)', '006431b0 setLimbFlag (PartInstance+0x228 Primitive, Primitive+0xa0 Body, Body+0x30)',
                        '00643d30 floor primitive (PartInstance embeds Primitive at +0x228; native PartInstance.h declares scoped_ptr)',
                        '00643360/00643a70/006439b0/00643a30/00643a50 (Body/Primitive/World layouts)', '00643d40/00643eb0 (BodyMover type)',
                        '00643660 factory (subclass layouts)', '006451c0/006453a0/00645450/00645060/00644000-00644c80 state machine bodies'],
               scope='Inactive HumanoidState layout and eight matched base bodies plus vtable/RTTI linkage; Humanoid and Primitive declarations come from the declaration-only overlay tests/NativeHumanoidStateCalls.h (proposal). Field names after flag11 and method names are analog names. No runtime swap.')
(root/'work/2008-06/shared-layouts/humanoid-state-working.json').write_text(json.dumps(receipt, indent=2)+'\n')
print('PASS: HumanoidState layout, %d exact base bodies, %d folded virtual defaults, vtables and RTTI' % (len(rows), len(folded_rows)))
