"""Verify initializeCommands in an isolated native layout."""
import hashlib
import json
import struct
import sys
from pathlib import Path

import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/tests/NativeDocumentInitializeTrial.cpp'
layout = root / 'rebuild/2008-06/native-headers/CRobloxDoc.h'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
obj = out / 'NativeDocumentInitializeTrial.obj'
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?initializeCommands@CRobloxDoc@@'))
target, targetrefs, _ = match.target('2008-06', '00451b60')
assert match.exact_match(target, targetrefs, body, refs)
sections, symbols, definitions, _ = match._coff_data_index(raw)
expected = {'?createNativeWorkspace@@': 0x450370, '?getDataModel@CWorkspace@@': 0x46a940,
            '?getWorkspace@CWorkspace@@': 0x46a970, '??0Lock@DataModel@RBX@@': 0x411b40,
            '??1Lock@DataModel@RBX@@': 0x5773c0, '??0StandardVerbs@RBX@@': 0x5c7ea0,
            '??1StandardVerbs@RBX@@': 0x450450, '?bindExisting@CRobloxDoc@@': 0x451a10,
            '?bindOwned@CRobloxDoc@@': 0x451a60, '?lookup@Name@RBX@@': 0x554290,
            '??_7ReportAbuseVerb@@': 0x8172e0, '??_7FixedCameraCommand@RBX@@': 0x817c00,
            '??_7InsertTexture@@': 0x817324}
start, index = definitions[name]
section = sections[index]
found = {}
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
    offset -= start
    if not 0 <= offset < len(body)-3:
        continue
    symbol = symbols[symbol][0]
    value = struct.unpack_from('<I', target, offset)[0]
    if kind == 20:
        value = (0x451b60 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
    for prefix, wanted in expected.items():
        if symbol.startswith(prefix):
            assert value == wanted, (symbol, hex(value), hex(wanted))
            found.setdefault(prefix, []).append(hex(value))
assert set(found) == set(expected), found
verb_name, verb_body, verb_refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?doIt@ReportAbuseVerb@@'))
verb_target, verb_targetrefs, _ = match.target('2008-06', '0044f700')
assert match.exact_match(verb_target, verb_targetrefs, verb_body, verb_refs)
verb_start, verb_index = definitions[verb_name]
verb_section = sections[verb_index]
verb_bindings = {}
for i in range(verb_section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, verb_section[5] + 10*i)
    offset -= verb_start
    if 0 <= offset < len(verb_body) - 3:
        value = struct.unpack_from('<I', verb_target, offset)[0]
        if kind == 20:
            value = (0x44f700 + offset + 4 + struct.unpack_from('<i', verb_target, offset)[0]) & 0xffffffff
        verb_bindings[symbols[symbol][0]] = value
assert verb_bindings['?AfxGetModuleState@@YGPAVAFX_MODULE_STATE@@XZ'] == 0x6a0926
assert verb_bindings['__imp__PostMessageA@16'] == 0x802e0c
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
assert struct.unpack('<I', pe.get_data(0x8172e0 + 16 - pe.OPTIONAL_HEADER.ImageBase, 4))[0] == 0x44f700
enabled_name, enabled_body, enabled_refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?isEnabled@ReportAbuseVerb@@'))
enabled_target, enabled_targetrefs, _ = match.target('2008-06', '004532d0')
assert match.exact_match(enabled_target, enabled_targetrefs, enabled_body, enabled_refs)
enabled_start, enabled_index = definitions[enabled_name]
enabled_section = sections[enabled_index]
enabled_bindings = {}
for i in range(enabled_section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, enabled_section[5] + 10*i)
    offset -= enabled_start
    if 0 <= offset < len(enabled_body) - 3 and kind == 20:
        value = (0x4532d0 + offset + 4 + struct.unpack_from('<i', enabled_target, offset)[0]) & 0xffffffff
        enabled_bindings[symbols[symbol][0]] = value
for prefix, address in [('?getDataModel@CRobloxDoc@@', 0x403040), ('??0Lock@DataModel@RBX@@', 0x411b40),
                        ('??$create@VPlayers@Network@RBX@@', 0x412710), ('?canReportAbuse@Players@Network@RBX@@', 0x496390),
                        ('??1Lock@DataModel@RBX@@', 0x5773c0)]:
    assert any(k.startswith(prefix) and v == address for k, v in enabled_bindings.items()), (prefix, enabled_bindings)
assert struct.unpack('<I', pe.get_data(0x8172e0 + 8 - pe.OPTIONAL_HEADER.ImageBase, 4))[0] == 0x4532d0
camera_enabled = []
for cls, vtable in [('CameraPanLeftCommand', 0x817ae4), ('CameraPanRightCommand', 0x817b0c),
                    ('CameraZoomExtentsCommand', 0x817b84)]:
    prefix = '?isEnabled@' + cls + '@RBX@@'
    camera_name, camera_body, camera_refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    camera_target, camera_targetrefs, _ = match.target('2008-06', '00565950')
    assert match.exact_match(camera_target, camera_targetrefs, camera_body, camera_refs)
    assert struct.unpack('<I', pe.get_data(vtable + 8 - pe.OPTIONAL_HEADER.ImageBase, 4))[0] == 0x565950
    camera_enabled.append({'symbol': camera_name, 'address': '00565950', 'vtable_slot': hex(vtable + 8), 'size': len(camera_body), 'exact': True})
for cls, address, vtable, prefix, callee in [
        ('CameraTiltUpCommand', 0x57d570, 0x817a94, '?canTilt@Camera@RBX@@', 0x5cc040),
        ('CameraTiltDownCommand', 0x57d590, 0x817abc, '?canTilt@Camera@RBX@@', 0x5cc040),
        ('CameraZoomInCommand', 0x57d5b0, 0x817b34, '?canZoom@Camera@RBX@@', 0x5cbf90),
        ('CameraZoomOutCommand', 0x57d5d0, 0x817b5c, '?canZoom@Camera@RBX@@', 0x5cbf90)]:
    symbol, candidate, relocations = next(x for x in match.coff_functions(raw) if x[0].startswith('?isEnabled@' + cls + '@RBX@@'))
    original, original_refs, _ = match.target('2008-06', '%08x' % address)
    assert match.exact_match(original, original_refs, candidate, relocations)
    assert struct.unpack('<I', pe.get_data(vtable + 8 - pe.OPTIONAL_HEADER.ImageBase, 4))[0] == address
    method_start, method_index = definitions[symbol]
    method_section = sections[method_index]
    calls = {}
    for i in range(method_section[7]):
        offset, symbol_index, kind = struct.unpack_from('<IIH', raw, method_section[5] + 10*i)
        offset -= method_start
        if kind == 20 and 0 <= offset < len(candidate) - 3:
            calls[symbols[symbol_index][0]] = (address + offset + 4 + struct.unpack_from('<i', original, offset)[0]) & 0xffffffff
    assert any(k.startswith(prefix) and v == callee for k, v in calls.items()), calls
    camera_enabled.append({'symbol': symbol, 'address': hex(address), 'vtable_slot': hex(vtable + 8), 'size': len(candidate), 'exact': True, 'calls': {k: hex(v) for k, v in calls.items()}})
ctor_name, ctor_body, ctor_refs = next(x for x in match.coff_functions(raw) if x[0].startswith('??0CameraVerb@RBX@@'))
ctor_target, ctor_targetrefs, _ = match.target('2008-06', '0057e3d0')
assert match.exact_match(ctor_target, ctor_targetrefs, ctor_body, ctor_refs)
ctor_start, ctor_index = definitions[ctor_name]
ctor_section = sections[ctor_index]
ctor_bindings = {}
for i in range(ctor_section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, ctor_section[5] + 10*i)
    offset -= ctor_start
    if 0 <= offset < len(ctor_body) - 3:
        value = struct.unpack_from('<I', ctor_target, offset)[0]
        if kind == 20:
            value = (0x57e3d0 + offset + 4 + struct.unpack_from('<i', ctor_target, offset)[0]) & 0xffffffff
        ctor_bindings[symbols[symbol][0]] = value
for prefix, address in [('??0Verb@RBX@@', 0x5833e0), ('??_7CameraVerb@RBX@@', 0x83077c)]:
    assert any(k.startswith(prefix) and v == address for k, v in ctor_bindings.items()), (prefix, ctor_bindings)
checked_name, checked_body, checked_refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?isChecked@FixedCameraCommand@RBX@@'))
checked_target, checked_targetrefs, _ = match.target('2008-06', '0057d5f0')
assert match.exact_match(checked_target, checked_targetrefs, checked_body, checked_refs)
assert struct.unpack('<I', pe.get_data(0x817c00 + 12 - pe.OPTIONAL_HEADER.ImageBase, 4))[0] == 0x57d5f0
fixed_name, fixed_body, fixed_refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?doIt@FixedCameraCommand@RBX@@'))
fixed_target, fixed_targetrefs, _ = match.target('2008-06', '0057d620')
assert match.exact_match(fixed_target, fixed_targetrefs, fixed_body, fixed_refs)
fixed_start, fixed_index = definitions[fixed_name]
fixed_section = sections[fixed_index]
fixed_calls = {}
for i in range(fixed_section[7]):
    offset, symbol_index, kind = struct.unpack_from('<IIH', raw, fixed_section[5] + 10*i)
    offset -= fixed_start
    if kind == 20 and 0 <= offset < len(fixed_body) - 3:
        fixed_calls[symbols[symbol_index][0]] = (0x57d620 + offset + 4 + struct.unpack_from('<i', fixed_target, offset)[0]) & 0xffffffff
for prefix, address in [('?setCameraType@Camera@RBX@@', 0x5cddd0), ('?recordCameraHistory@RBX@@', 0x58c5c0)]:
    assert any(k.startswith(prefix) and v == address for k, v in fixed_calls.items()), (prefix, fixed_calls)
assert struct.unpack('<I', pe.get_data(0x817c00 + 16 - pe.OPTIONAL_HEADER.ImageBase, 4))[0] == 0x57d620
camera_actions = []
for cls, address, vtable, extra in [
        ('CameraVerb', 0x5819a0, 0x83077c, None),
        ('CameraPanLeftCommand', 0x5819d0, 0x817ae4, ('?panUnits@Camera@RBX@@', 0x5cc930)),
        ('CameraPanRightCommand', 0x581a20, 0x817b0c, ('?panUnits@Camera@RBX@@', 0x5cc930)),
        ('CameraTiltUpCommand', 0x581a70, 0x817a94, ('?tiltUnits@Camera@RBX@@', 0x5cc890)),
        ('CameraTiltDownCommand', 0x581ac0, 0x817abc, ('?tiltUnits@Camera@RBX@@', 0x5cc890)),
        ('CameraZoomInCommand', 0x581b10, 0x817b34, ('?zoom@Camera@RBX@@', 0x5cce80)),
        ('CameraZoomOutCommand', 0x581b60, 0x817b5c, ('?zoom@Camera@RBX@@', 0x5cce80)),
        ('CameraModelViewCommand', 0x581bc0, 0x817bd8, ('?setImageServerView@Workspace@RBX@@', 0x5a5890))]:
    action_name, action_body, action_refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?doIt@' + cls + '@RBX@@'))
    action_target, action_targetrefs, _ = match.target('2008-06', '%08x' % address)
    assert match.exact_match(action_target, action_targetrefs, action_body, action_refs)
    assert struct.unpack('<I', pe.get_data(vtable + 16 - pe.OPTIONAL_HEADER.ImageBase, 4))[0] == address
    action_start, action_index = definitions[action_name]
    action_section = sections[action_index]
    calls = {}
    for i in range(action_section[7]):
        offset, symbol_index, kind = struct.unpack_from('<IIH', raw, action_section[5] + 10*i)
        offset -= action_start
        if kind == 20 and 0 <= offset < len(action_body) - 3:
            calls[symbols[symbol_index][0]] = (address + offset + 4 + struct.unpack_from('<i', action_target, offset)[0]) & 0xffffffff
    expected_calls = [('??$create@VSoundService@Soundscape@RBX@@', 0x5807b0), ('?playSound@SoundService@Soundscape@RBX@@', 0x5bd820)]
    if extra:
        expected_calls.append(extra)
    for prefix, target_address in expected_calls:
        assert any(k.startswith(prefix) and v == target_address for k, v in calls.items()), (cls, prefix, calls)
    camera_actions.append({'symbol': action_name, 'address': hex(address), 'size': len(action_body), 'vtable_slot': hex(vtable + 16), 'calls': {k: hex(v) for k, v in calls.items()}, 'exact': True})
assert struct.unpack('<f', pe.get_data(0x81c3b8 - pe.OPTIONAL_HEADER.ImageBase, 4))[0] == -1.0
sound_locator = struct.unpack('<I', pe.get_data(0x837ad4 - 4 - pe.OPTIONAL_HEADER.ImageBase, 4))[0]
sound_type = struct.unpack('<I', pe.get_data(sound_locator + 12 - pe.OPTIONAL_HEADER.ImageBase, 4))[0]
assert pe.get_string_at_rva(sound_type + 8 - pe.OPTIONAL_HEADER.ImageBase) == b'.?AVSoundService@Soundscape@RBX@@'
for address, callee in [(0x582300, 0x581d80), (0x581d80, 0x580800),
                        (0x580800, 0x5805d0), (0x5805d0, 0x57f710), (0x57f710, 0x57eeb0)]:
    original, _, _ = match.target('2008-06', '%08x' % address)
    assert any(i.mnemonic in ('call', 'jmp') and i.op_str == hex(callee)
               for i in Cs(CS_ARCH_X86, CS_MODE_32).disasm(original, address)), (hex(address), hex(callee))
selection_locator = struct.unpack('<I', pe.get_data(0x830944 - 4 - pe.OPTIONAL_HEADER.ImageBase, 4))[0]
selection_type = struct.unpack('<I', pe.get_data(selection_locator + 12 - pe.OPTIONAL_HEADER.ImageBase, 4))[0]
assert pe.get_string_at_rva(selection_type + 8 - pe.OPTIONAL_HEADER.ImageBase) == b'.?AV?$FilteredSelection@VPVInstance@RBX@@@RBX@@'
center_name, center_body, center_refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?isEnabled@CameraCenterCommand@RBX@@'))
center_target, center_targetrefs, _ = match.target('2008-06', '00582300')
assert match.exact_match(center_target, center_targetrefs, center_body, center_refs)
assert struct.unpack('<I', pe.get_data(0x817bb0 + 8 - pe.OPTIONAL_HEADER.ImageBase, 4))[0] == 0x582300
center_start, center_index = definitions[center_name]
center_section = sections[center_index]
center_calls = {}
for i in range(center_section[7]):
    offset, symbol_index, kind = struct.unpack_from('<IIH', raw, center_section[5] + 10*i)
    offset -= center_start
    if kind == 20 and 0 <= offset < len(center_body) - 3:
        center_calls[symbols[symbol_index][0]] = (0x582300 + offset + 4 + struct.unpack_from('<i', center_target, offset)[0]) & 0xffffffff
assert any(k.startswith('?createService@?$ServiceClient@V?$FilteredSelection@VPVInstance@RBX@@') and v == 0x581d80 for k, v in center_calls.items()), center_calls
client_name, client_body, client_refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?createService@?$ServiceClient@V?$FilteredSelection@VPVInstance@RBX@@'))
client_target, client_targetrefs, _ = match.target('2008-06', '00581d80')
assert match.exact_match(client_target, client_targetrefs, client_body, client_refs)
insert_lifetime = []
for prefix, address, required in [
        ('??0InsertDecal@@', 0x41dd60, [('??0EditSelectionVerb@RBX@@', 0x57e730), ('??_7InsertDecal@@', 0x80f15c)]),
        ('??_GInsertDecal@@', 0x5c6090, [('??1EditSelectionVerb@RBX@@', 0x57e050), ('??3@', 0x6a067a)])]:
    lifetime_name, lifetime_body, lifetime_refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    lifetime_target, lifetime_targetrefs, _ = match.target('2008-06', '%08x' % address)
    assert match.exact_match(lifetime_target, lifetime_targetrefs, lifetime_body, lifetime_refs)
    lifetime_start, lifetime_index = definitions[lifetime_name]
    lifetime_section = sections[lifetime_index]
    lifetime_bindings = {}
    for i in range(lifetime_section[7]):
        offset, symbol_index, kind = struct.unpack_from('<IIH', raw, lifetime_section[5] + 10*i)
        offset -= lifetime_start
        if 0 <= offset < len(lifetime_body) - 3:
            value = struct.unpack_from('<I', lifetime_target, offset)[0]
            if kind == 20:
                value = (address + offset + 4 + struct.unpack_from('<i', lifetime_target, offset)[0]) & 0xffffffff
            lifetime_bindings[symbols[symbol_index][0]] = value
    for key, value in required:
        assert any(k.startswith(key) and v == value for k, v in lifetime_bindings.items()), (key, lifetime_bindings)
    insert_lifetime.append({'symbol': lifetime_name, 'address': hex(address), 'size': len(lifetime_body), 'exact': True, 'bindings': {k: hex(v) for k, v in lifetime_bindings.items()}})
assert struct.unpack('<I', pe.get_data(0x80f15c + 4 - pe.OPTIONAL_HEADER.ImageBase, 4))[0] == 0x5c6090
insert_checks = []
for prefix, address, expected in [
        ('?getTarget@InsertDecal@@', 0x41ef90, [('??$create@VSelection@RBX@@', 0x4153b0), ('?front@Selection@RBX@@', 0x413c20), ('??_R0?AVPartInstance@RBX@@', 0x92dd50), ('??_R0?AVSpecialShape@RBX@@', 0x92dd30)]),
        ('?isEnabled@InsertDecal@@', 0x41f280, [('?isEnabled@EditSelectionVerb@RBX@@', 0x582830), ('?getTarget@InsertDecal@@', 0x41ef90)])]:
    check_name, check_body, check_refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    check_target, check_targetrefs, _ = match.target('2008-06', '%08x' % address)
    assert match.exact_match(check_target, check_targetrefs, check_body, check_refs)
    check_start, check_index = definitions[check_name]
    check_section = sections[check_index]
    check_bindings = {}
    for i in range(check_section[7]):
        offset, symbol_index, kind = struct.unpack_from('<IIH', raw, check_section[5] + 10*i)
        offset -= check_start
        if 0 <= offset < len(check_body) - 3:
            value = struct.unpack_from('<I', check_target, offset)[0]
            if kind == 20:
                value = (address + offset + 4 + struct.unpack_from('<i', check_target, offset)[0]) & 0xffffffff
            check_bindings[symbols[symbol_index][0]] = value
    for key, value in expected:
        assert any(k.startswith(key) and v == value for k, v in check_bindings.items()), (key, check_bindings)
    insert_checks.append({'symbol': check_name, 'address': hex(address), 'size': len(check_body), 'exact': True, 'bindings': {k: hex(v) for k, v in check_bindings.items()}})
assert struct.unpack('<I', pe.get_data(0x80f15c + 8 - pe.OPTIONAL_HEADER.ImageBase, 4))[0] == 0x41f280
assert pe.get_string_at_rva(0x92dd30 + 8 - pe.OPTIONAL_HEADER.ImageBase) == b'.?AVSpecialShape@RBX@@'
insert_factories = []
for cls, wrapper, vtable, factory in [('Decal', 0x41e650, 0x80f15c, 0x41e4d0), ('Texture', 0x41e670, 0x817324, 0x41e550)]:
    for prefix, address in [('?createInstance@Insert' + cls + '@@', wrapper),
                            ('??$create@V' + cls + '@RBX@@@?$Creatable@VInstance@RBX@@', factory)]:
        factory_name, factory_body, factory_refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
        factory_target, factory_targetrefs, _ = match.target('2008-06', '%08x' % address)
        assert match.exact_match(factory_target, factory_targetrefs, factory_body, factory_refs), (cls, prefix, len(factory_body), len(factory_target))
        insert_factories.append({'class': cls, 'symbol': factory_name, 'address': hex(address), 'size': len(factory_body), 'exact': True})
    assert struct.unpack('<I', pe.get_data(vtable + 20 - pe.OPTIONAL_HEADER.ImageBase, 4))[0] == wrapper
paste_name,paste_body,paste_refs=next(x for x in match.coff_functions(raw) if x[0].startswith('??0PasteVerb@@'))
paste_target,paste_targetrefs,_=match.target('2008-06','004134d0');assert match.exact_match(paste_target,paste_targetrefs,paste_body,paste_refs)
start,index=definitions[paste_name];section=sections[index];paste_edges={}
for i in range(section[7]):
    off,sym,kind=struct.unpack_from('<IIH',raw,section[5]+10*i);off-=start
    if not 0<=off<len(paste_body)-3:continue
    value=struct.unpack_from('<I',paste_target,off)[0]
    if kind==20:value=(0x4134d0+off+4+struct.unpack_from('<i',paste_target,off)[0])&0xffffffff
    paste_edges[symbols[sym][0]]=value
assert any(k.startswith('??0Verb@RBX@@') and v==0x5833e0 for k,v in paste_edges.items()),paste_edges
literal_values=[pe.get_string_at_rva(v-pe.OPTIONAL_HEADER.ImageBase) for k,v in paste_edges.items() if k.startswith('??_C@')]
assert b'Paste' in literal_values and b'PasteInto' in literal_values,literal_values
paste_enabled_name,paste_enabled_body,paste_enabled_refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?isEnabled@PasteVerb@@'))
paste_enabled_target,paste_enabled_targetrefs,_=match.target('2008-06','004154a0');assert match.exact_match(paste_enabled_target,paste_enabled_targetrefs,paste_enabled_body,paste_enabled_refs)
assert struct.unpack('<I',pe.get_data(0x80e934+8-pe.OPTIONAL_HEADER.ImageBase,4))[0]==0x4154a0
start,index=definitions[paste_enabled_name];section=sections[index];paste_enabled_edges={}
for i in range(section[7]):
    off,sym,kind=struct.unpack_from('<IIH',raw,section[5]+10*i);off-=start
    if not 0<=off<len(paste_enabled_body)-3:continue
    value=struct.unpack_from('<I',paste_enabled_target,off)[0]
    if kind==20:value=(0x4154a0+off+4+struct.unpack_from('<i',paste_enabled_target,off)[0])&0xffffffff
    paste_enabled_edges[symbols[sym][0]]=value
for token,want in [('RegisterClipboardFormatA',0x802df0),('IsClipboardFormatAvailable',0x802dec),('create@VSelection',0x4153b0),('format',0x96cbf0)]:assert any(token in k and v==want for k,v in paste_enabled_edges.items()),(token,paste_enabled_edges)
assert pe.get_string_at_rva(0x80e920-pe.OPTIONAL_HEADER.ImageBase)==b'Roblox'
cut_constructors=[]
for prefix,address,baseprefix,baseaddr in [('??0CutVerb@@',0x413920,'??0DeleteSelectionVerb@RBX@@',0x413870),('??0DeleteSelectionVerb@RBX@@',0x413870,'??0DeleteBase@RBX@@',0x581010),('??0DeleteBase@RBX@@IAE@PAVVerbContainer',0x581010,'??0EditSelectionVerb@RBX@@',0x580b50)]:
    name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06',f'{address:08x}');assert match.exact_match(target,targetrefs,body,refs)
    start,index=definitions[name];section=sections[index];edges={}
    for i in range(section[7]):
        off,sym,kind=struct.unpack_from('<IIH',raw,section[5]+10*i);off-=start
        if not 0<=off<len(body)-3:continue
        value=struct.unpack_from('<I',target,off)[0]
        if kind==20:value=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
        edges[symbols[sym][0]]=value
    assert any(k.startswith(baseprefix) and v==baseaddr for k,v in edges.items()),edges
    cut_constructors.append({'address':hex(address),'size':len(body),'bindings':edges})
edit_name,edit_body,edit_refs=next(x for x in match.coff_functions(raw) if x[0].startswith('??0EditSelectionVerb@RBX@@IAE@PAVVerbContainer'))
edit_target,edit_targetrefs,_=match.target('2008-06','00580b50');assert match.exact_match(edit_target,edit_targetrefs,edit_body,edit_refs)
start,index=definitions[edit_name];section=sections[index];edit_edges={}
for i in range(section[7]):
    off,sym,kind=struct.unpack_from('<IIH',raw,section[5]+10*i);off-=start
    if not 0<=off<len(edit_body)-3:continue
    value=struct.unpack_from('<I',edit_target,off)[0]
    if kind==20:value=(0x580b50+off+4+struct.unpack_from('<i',edit_target,off)[0])&0xffffffff
    edit_edges[symbols[sym][0]]=value
for token,want in [('??0Verb@RBX@@',0x5833e0),('create@VWorkspace',0x490af0),('shared_from@VWorkspace',0x618a40)]:assert any(token in k and v==want for k,v in edit_edges.items()),(token,edit_edges)
cut_action_name,cut_action_body,cut_action_refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?doIt@CutVerb@@'))
cut_action_target,cut_action_targetrefs,_=match.target('2008-06','00413490');assert match.exact_match(cut_action_target,cut_action_targetrefs,cut_action_body,cut_action_refs)
assert struct.unpack('<I',pe.get_data(0x80e990+16-pe.OPTIONAL_HEADER.ImageBase,4))[0]==0x413490
start,index=definitions[cut_action_name];section=sections[index];cut_action_edges={}
for i in range(section[7]):
    off,sym,kind=struct.unpack_from('<IIH',raw,section[5]+10*i);off-=start
    if not 0<=off<len(cut_action_body)-3:continue
    value=struct.unpack_from('<I',cut_action_target,off)[0]
    if kind==20:value=(0x413490+off+4+struct.unpack_from('<i',cut_action_target,off)[0])&0xffffffff
    cut_action_edges[symbols[sym][0]]=value
for token,want in [('getVerb@VerbContainer',0x583380),('doIt@DeleteBase',0x581090)]:assert any(token in k and v==want for k,v in cut_action_edges.items()),(token,cut_action_edges)
assert pe.get_string_at_rva(0x80e928-pe.OPTIONAL_HEADER.ImageBase)==b'Copy'
simple_constructors=[]
for cls,address,label,base_target in [('InsertObject',0x41f2e0,'Insert Object',0x57e330),('InsertService',0x41f310,'Insert Service',0x57e330),('CopyVerb',0x413530,'Copy',0x57e730)]:
    ctor,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('??0'+cls+'@@'))
    target,targetrefs,_=match.target('2008-06',f'{address:08x}');assert match.exact_match(target,targetrefs,body,refs),cls
    start,index=definitions[ctor];section=sections[index];edges={}
    for i in range(section[7]):
        off,sym,kind=struct.unpack_from('<IIH',raw,section[5]+10*i);off-=start
        if not 0<=off<len(body)-3:continue
        value=struct.unpack_from('<I',target,off)[0]
        if kind==20:value=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
        edges[symbols[sym][0]]=value
    assert any(k.startswith('??0'+('EditSelectionVerb' if cls=='CopyVerb' else 'RunStateVerb')) and v==base_target for k,v in edges.items()),edges
    literal=next(v for k,v in edges.items() if k.startswith('??_C@'));assert pe.get_string_at_rva(literal-pe.OPTIONAL_HEADER.ImageBase)==label.encode()
    vt=next(v for k,v in edges.items() if k.startswith('??_7'+cls+'@@'));readptr=lambda a:struct.unpack('<I',pe.get_data(a-pe.OPTIONAL_HEADER.ImageBase,4))[0]
    assert pe.get_string_at_rva(readptr(readptr(vt-4)+12)+8-pe.OPTIONAL_HEADER.ImageBase)==('.?AV'+cls+'@@').encode()
    simple_constructors.append({'class':cls,'address':hex(address),'size':len(body),'vtable':hex(vt),'base':hex(base_target),'label':label})
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256': sha(source), 'layout_sha256': sha(layout), 'observer_sha256': sha(Path(__file__)),
           'object_sha256': sha(obj), 'flags': flags, 'address': '00451b60', 'size': len(body), 'targets': found,
           'report_abuse_doIt': {'address': '0044f700', 'size': len(verb_body), 'exact': True, 'vtable_slot': '0x8172f0', 'bindings': {k: hex(v) for k, v in verb_bindings.items()}},
           'report_abuse_isEnabled': {'address': '004532d0', 'size': len(enabled_body), 'exact': True, 'vtable_slot': '0x8172e8', 'bindings': {k: hex(v) for k, v in enabled_bindings.items()}},
           'camera_enabled': camera_enabled,
           'camera_constructor': {'address': '0057e3d0', 'size': len(ctor_body), 'exact': True, 'bindings': {k: hex(v) for k, v in ctor_bindings.items()}},
           'fixed_camera_checked': {'symbol': checked_name, 'address': '0057d5f0', 'size': len(checked_body), 'exact': True, 'vtable_slot': '0x817c0c'},
           'fixed_camera_action': {'symbol': fixed_name, 'address': '0057d620', 'size': len(fixed_body), 'exact': True, 'vtable_slot': '0x817c10', 'calls': {k: hex(v) for k, v in fixed_calls.items()}},
           'camera_actions': camera_actions,
           'camera_selection': {'type': 'RBX::FilteredSelection<RBX::PVInstance>', 'factory': '0x57f710', 'constructor': '0x57eeb0', 'vtable': '0x830944', 'service_client': '0x581d80', 'type_descriptor': hex(selection_type)},
           'camera_center_enabled': {'symbol': center_name, 'address': '00582300', 'size': len(center_body), 'exact': True, 'vtable_slot': '0x817bb8', 'calls': {k: hex(v) for k, v in center_calls.items()}},
           'camera_selection_client': {'symbol': client_name, 'address': '00581d80', 'size': len(client_body), 'exact': True},
           'edit_container_ctor':{'address':'00580b50','size':len(edit_body),'bindings':edit_edges},'cut_action':{'address':'00413490','size':len(cut_action_body),'bindings':cut_action_edges},'cut_constructors':cut_constructors,'paste_enabled':{'address':'004154a0','size':len(paste_enabled_body),'bindings':paste_enabled_edges},'paste_constructor':{'address':'004134d0','size':len(paste_body),'bindings':paste_edges},'simple_constructors':simple_constructors,
           'insert_decal_lifetime': insert_lifetime,
           'insert_decal_checks': insert_checks,
           'insert_decal_factories': insert_factories,
           'scope': 'Inactive trial. Referenced command vtables, constructors, class layouts, workspace factory, exception handling and ownership remain unproven.'}
(root / 'work/2008-06/shared-layouts/document-initialize-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS ContentProvider initializeCommands and selected targets')

