"""Verify original selection-command constructors and RTTI bindings."""
import hashlib, json, struct, sys
from pathlib import Path
import pefile
root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild
out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/tests/NativeSelectionCommandsTrial.cpp'
header = root / 'rebuild/2008-06/native-headers/StandardVerbs.h'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
obj = out / 'NativeSelectionCommandsTrial.obj'
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')] + ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
functions = match.coff_functions(raw)
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
image = pe.OPTIONAL_HEADER.ImageBase
readptr = lambda addr: struct.unpack('<I', pe.get_data(addr-image, 4))[0]
rows = []
for cls, address, label in [('GroupSelectionVerb',0x57e7e0,'Group'), ('WeldSelectionVerb',0x57e810,'WeldSelection'), ('SnapSelectionVerb',0x57e840,'SnapSelection'), ('UngroupSelectionVerb',0x57e870,'UnGroup'), ('DuplicateSelectionVerb',0x57e8a0,'Duplicate'), ('AttachCameraCommand',0x57e950,'AttachCamera'), ('TrackCameraCommand',0x57e980,'TrackCamera'), ('FollowCameraCommand',0x57e9b0,'FollowCamera'), ('WatchCameraCommand',0x57e9e0,'WatchCamera'), ('MoveDownSelectionVerb',0x57ea10,'SelectionDown')]:
    name, body, refs = next(x for x in functions if x[0].startswith('??0'+cls+'@RBX@@'))
    target, targetrefs, _ = match.target('2008-06', f'{address:08x}')
    assert match.exact_match(target, targetrefs, body, refs), cls
    start, index = definitions[name]
    section = sections[index]
    edges = {}
    for i in range(section[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
        offset -= start
        if not 0 <= offset < len(body)-3: continue
        value = struct.unpack_from('<I', target, offset)[0]
        if kind == 20: value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        edges[symbols[symbol][0]] = value
    def lookup(prefix):
        vals = [v for k,v in edges.items() if k.startswith(prefix)]
        assert len(vals) == 1, (cls, prefix, edges)
        return vals[0]
    assert lookup('??0EditSelectionVerb@RBX@@') == 0x57e730
    literal = lookup('??_C@')
    assert pe.get_string_at_rva(literal-image) == label.encode('ascii')
    vtable = lookup('??_7'+cls+'@RBX@@')
    type_descriptor = readptr(readptr(vtable-4)+12)
    assert pe.get_string_at_rva(type_descriptor+8-image) == ('.?AV'+cls+'@RBX@@').encode('ascii')
    rows.append({'class':cls,'address':hex(address),'size':len(body),'label':label,'literal':hex(literal),'vtable':hex(vtable),'type_descriptor':hex(type_descriptor)})
property_ctors = []
for cls, address, label, prop in [('AnchorVerb',0x5c6010,'AnchorVerb','Anchored'), ('TranslucentVerb',0x5c5300,'TranslucentVerb','Transparent'), ('CanCollideVerb',0x5c5380,'CanCollideVerb','CanCollide')]:
    name, body, refs = next(x for x in functions if x[0].startswith('??0'+cls+'@RBX@@'))
    target, targetrefs, _ = match.target('2008-06', f'{address:08x}')
    assert match.exact_match(target, targetrefs, body, refs), cls
    start, index = definitions[name]
    section = sections[index]
    edges = {}
    for i in range(section[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
        offset -= start
        if not 0 <= offset < len(body)-3: continue
        value = struct.unpack_from('<I', target, offset)[0]
        if kind == 20: value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        edges[symbols[symbol][0]] = value
    vtable = next(v for k,v in edges.items() if k.startswith('??_7'+cls+'@RBX@@'))
    desc = readptr(readptr(vtable-4)+12)
    assert pe.get_string_at_rva(desc+8-image) == ('.?AV'+cls+'@RBX@@').encode()
    literals = [pe.get_string_at_rva(v-image) for k,v in edges.items() if k.startswith('??_C@')]
    assert label.encode() in literals and prop.encode() in literals, (cls, literals)
    base = [v for k,v in edges.items() if k.startswith('??0BoolPropertyVerb@RBX@@')]
    assert len(base) == 1, (cls, edges)
    property_ctors.append({'class':cls,'address':hex(address),'size':len(body),'vtable':hex(vtable),'base':hex(base[0]),'labels':[label,prop]})
assert len({x['base'] for x in property_ctors}) == 1
name, body, refs = next(x for x in functions if x[0].startswith('??0BoolPropertyVerb@RBX@@'))
target, targetrefs, _ = match.target('2008-06', '0057f530')
assert match.exact_match(target, targetrefs, body, refs)
start, index = definitions[name]
section = sections[index]
property_base_edges = {}
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
    offset -= start
    if not 0 <= offset < len(body)-3: continue
    value = struct.unpack_from('<I', target, offset)[0]
    if kind == 20: value = (0x57f530 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
    property_base_edges[symbols[symbol][0]] = value
assert any(k.startswith('??0EditSelectionVerb@RBX@@') and v == 0x57e730 for k,v in property_base_edges.items()), property_base_edges
assert any('declare@Name@RBX@@' in k for k in property_base_edges), property_base_edges
property_vtable = next(v for k,v in property_base_edges.items() if k.startswith('??_7BoolPropertyVerb@RBX@@'))
property_desc = readptr(readptr(property_vtable-4)+12)
assert pe.get_string_at_rva(property_desc+8-image) == b'.?AVBoolPropertyVerb@RBX@@'
name, body, refs = next(x for x in functions if x[0].startswith('?isEnabled@TrackCameraCommand@RBX@@'))
target, targetrefs, _ = match.target('2008-06', '00582e50')
assert match.exact_match(target, targetrefs, body, refs)
assert readptr(0x830848 + 8) == 0x582e50
start, index = definitions[name]; section = sections[index]; track_edges = {}
for i in range(section[7]):
    offset,symbol,kind = struct.unpack_from('<IIH',raw,section[5]+i*10); offset-=start
    if kind == 20 and 0 <= offset < len(body)-3:
        track_edges[symbols[symbol][0]] = (0x582e50+offset+4+struct.unpack_from('<i',target,offset)[0]) & 0xffffffff
assert any('createService' in k and v == 0x581cc0 for k,v in track_edges.items()), track_edges
assert any('create@VSelection' in k and v == 0x4153b0 for k,v in track_edges.items()), track_edges
name,body,refs=next(x for x in functions if x[0].startswith('?isEnabled@AttachCameraCommand@RBX@@'))
target,targetrefs,_=match.target('2008-06','00582d70');assert match.exact_match(target,targetrefs,body,refs)
assert readptr(0x830830+8)==0x582d70
start,index=definitions[name];section=sections[index];attach_edges={}
for i in range(section[7]):
    offset,symbol,kind=struct.unpack_from('<IIH',raw,section[5]+i*10);offset-=start
    if kind==20 and 0<=offset<len(body)-3:attach_edges[symbols[symbol][0]]=(0x582d70+offset+4+struct.unpack_from('<i',target,offset)[0])&0xffffffff
assert any('createService' in k and v==0x581cc0 for k,v in attach_edges.items()),attach_edges
assert any('createService' in k and v==0x581d80 for k,v in attach_edges.items()),attach_edges
follow_enabled = []
for cls,vt in [('FollowCameraCommand',0x830860),('WatchCameraCommand',0x830878)]:
    name, body, refs = next(x for x in functions if x[0].startswith('?isEnabled@'+cls+'@RBX@@'))
    target, targetrefs, _ = match.target('2008-06', '00582ea0')
    assert match.exact_match(target,targetrefs,body,refs), cls
    assert readptr(vt+8) == 0x582ea0
    start,index=definitions[name];section=sections[index];edges={}
    for i in range(section[7]):
        offset,symbol,kind=struct.unpack_from('<IIH',raw,section[5]+i*10);offset-=start
        if kind==20 and 0<=offset<len(body)-3:edges[symbols[symbol][0]]=(0x582ea0+offset+4+struct.unpack_from('<i',target,offset)[0])&0xffffffff
    assert any('createService' in k and v==0x581cc0 for k,v in edges.items()),edges
    assert any('create@V?$FilteredSelection' in k and v==0x5805d0 for k,v in edges.items()),edges
    follow_enabled.append({'class':cls,'vtable':hex(vt),'size':len(body),'calls':edges})
selection_camera_actions=[]
for cls,address,vt in [('AttachCameraCommand',0x581360,0x830830),('WatchCameraCommand',0x5815a0,0x830878),('TrackCameraCommand',0x5813f0,0x830848),('FollowCameraCommand',0x581510,0x830860)]:
    name,body,refs=next(x for x in functions if x[0].startswith('?doIt@'+cls+'@RBX@@'))
    target,targetrefs,_=match.target('2008-06',f'{address:08x}');assert match.exact_match(target,targetrefs,body,refs)
    assert readptr(vt+16)==address
    start,index=definitions[name];section=sections[index];calls={}
    for i in range(section[7]):
        offset,symbol,kind=struct.unpack_from('<IIH',raw,section[5]+i*10);offset-=start
        if kind==20 and 0<=offset<len(body)-3:calls[symbols[symbol][0]]=(address+offset+4+struct.unpack_from('<i',target,offset)[0])&0xffffffff
    assert any(('create@VSelection' in k and v==0x4153b0) if cls=='TrackCameraCommand' else ('create@V?$FilteredSelection' in k and v==0x5805d0) for k,v in calls.items()),calls
    assert any('recordCameraHistory' in k and v==0x58c5c0 for k,v in calls.items()),calls
    selection_camera_actions.append({'class':cls,'address':hex(address),'size':len(body),'vtable':hex(vt),'calls':calls})
selection_enabled=[]
for cls,address,vt in [('WeldSelectionVerb',0x582940,0x8307ac),('SnapSelectionVerb',0x582940,0x8307c4),('DuplicateSelectionVerb',0x580fe0,0x8307f4),('GroupSelectionVerb',0x582860,0x830794)]:
    name,body,refs=next(x for x in functions if x[0].startswith('?isEnabled@'+cls+'@RBX@@'))
    target,targetrefs,_=match.target('2008-06',f'{address:08x}');assert match.exact_match(target,targetrefs,body,refs),cls
    assert readptr(vt+8)==address
    start,index=definitions[name];section=sections[index];calls={}
    for i in range(section[7]):
        offset,symbol,kind=struct.unpack_from('<IIH',raw,section[5]+i*10);offset-=start
        if kind==20 and 0<=offset<len(body)-3:calls[symbols[symbol][0]]=(address+offset+4+struct.unpack_from('<i',target,offset)[0])&0xffffffff
    if cls != 'DuplicateSelectionVerb': assert any('createService' in k and v==0x581cc0 for k,v in calls.items()),calls
    expected=0x581cc0 if cls=='GroupSelectionVerb' else 0x4153b0
    assert any(('createService' in k if cls=='GroupSelectionVerb' else 'create@VSelection' in k) and v==expected for k,v in calls.items()),calls
    selection_enabled.append({'class':cls,'address':hex(address),'size':len(body),'vtable':hex(vt),'calls':calls})
ungroup_rows=[]
for prefix,address in [('?isEnabled@UngroupSelectionVerb',0x582b50),('?hasChildren@RBX@@',0x57e110),('?findFirst@?$FilteredSelection',0x57edb0)]:
    name,body,refs=next(x for x in functions if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06',f'{address:08x}')
    assert match.exact_match(target,targetrefs,body,refs),prefix
    start,index=definitions[name];section=sections[index];edges={}
    for i in range(section[7]):
        offset,symbol,kind=struct.unpack_from('<IIH',raw,section[5]+i*10);offset-=start
        if not 0<=offset<len(body)-3:continue
        value=struct.unpack_from('<I',target,offset)[0]
        if kind==20:value=(address+offset+4+struct.unpack_from('<i',target,offset)[0])&0xffffffff
        edges[symbols[symbol][0]]=value
    if address==0x582b50:
        assert readptr(0x8307dc+8)==address
        for token,expected in [('createService',0x581cc0),('create@V?$FilteredSelection',0x5806c0),('findFirst',0x57edb0),('hasChildren',0x57e110)]:
            assert any(token in k and v==expected for k,v in edges.items()),(token,edges)
    ungroup_rows.append({'address':hex(address),'size':len(body),'edges':edges})
controller_rows=[]
for prefix,address in [('?isEnabled@ControllerCommand',0x582ef0),('?controllable@RBX@@',0x57d550),('?findFirst@?$FilteredSelection@VPVInstance',0x57edb0)]:
    name,body,refs=next(x for x in functions if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06',f'{address:08x}');assert match.exact_match(target,targetrefs,body,refs),prefix
    start,index=definitions[name];section=sections[index];edges={}
    for i in range(section[7]):
        offset,symbol,kind=struct.unpack_from('<IIH',raw,section[5]+i*10);offset-=start
        if not 0<=offset<len(body)-3:continue
        value=struct.unpack_from('<I',target,offset)[0]
        if kind==20:value=(address+offset+4+struct.unpack_from('<i',target,offset)[0])&0xffffffff
        edges[symbols[symbol][0]]=value
    if address==0x582ef0:
        assert readptr(0x830ad4+8)==address and readptr(0x830af8+8)==address
        for token,expected in [('createService',0x581cc0),('create@V?$FilteredSelection',0x5805d0),('findFirst',0x57edb0),('controllable',0x57d550)]:assert any(token in k and v==expected for k,v in edges.items()),(token,edges)
    controller_rows.append({'address':hex(address),'size':len(body),'edges':edges})
controller_actions=[]
for prefix,address in [('?doIt@PrimaryControllerCommand',0x581920),('?doIt@SecondaryControllerCommand',0x581960),('?applyController@ControllerCommand',0x581890),('?findDifferent@?$FilteredSelection@VPVInstance',0x57ecb0),('?setController@RBX@@',0x57d540),('??$for_each@V?$_Vector_const_iterator@PAVPVInstance',0x57ed70)]:
    name,body,refs=next(x for x in functions if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06',f'{address:08x}');assert match.exact_match(target,targetrefs,body,refs),prefix
    start,index=definitions[name];section=sections[index];edges={}
    for i in range(section[7]):
        offset,symbol,kind=struct.unpack_from('<IIH',raw,section[5]+i*10);offset-=start
        if not 0<=offset<len(body)-3:continue
        value=struct.unpack_from('<I',target,offset)[0]
        if kind==20:value=(address+offset+4+struct.unpack_from('<i',target,offset)[0])&0xffffffff
        edges[symbols[symbol][0]]=value
    expected=[]
    if address in (0x581920,0x581960): expected=[('applyController',0x581890),('recordCameraHistory',0x58c5c0)];assert readptr((0x830ad4 if address==0x581920 else 0x830af8)+16)==address
    if address==0x581890:expected=[('create@V?$FilteredSelection',0x5805d0),('findDifferent',0x57ecb0),('for_each',0x57ed70),('setController',0x57d540)]
    if address==0x57d540:expected=[('setControllerType',0x6099c0)]
    for token,want in expected:assert any(token in k and v==want for k,v in edges.items()),(token,edges)
    controller_actions.append({'address':hex(address),'size':len(body),'edges':edges})
delete_name,delete_body,delete_refs=next(x for x in functions if x[0].startswith('?doIt@DeleteBase@RBX@@'))
delete_target,delete_targetrefs,_=match.target('2008-06','00581090');assert match.exact_match(delete_target,delete_targetrefs,delete_body,delete_refs)
assert readptr(0x830818+16)==0x581090
start,index=definitions[delete_name];section=sections[index];delete_edges={}
for i in range(section[7]):
    offset,symbol,kind=struct.unpack_from('<IIH',raw,section[5]+i*10);offset-=start
    if not 0<=offset<len(delete_body)-3:continue
    value=struct.unpack_from('<I',delete_target,offset)[0]
    if kind==20:value=(0x581090+offset+4+struct.unpack_from('<i',delete_target,offset)[0])&0xffffffff
    delete_edges[symbols[symbol][0]]=value
for token,want in [('checkRunPermissions',0x57d250),('create@VSelection',0x4153b0),('setParent@Instance',0x55a8f0),('create@VSoundService',0x4531e0),('playSound@SoundService',0x5bd820),('recordCameraHistory',0x58c5c0)]:assert any(token in k and v==want for k,v in delete_edges.items()),(token,delete_edges)
for typename in ('Workspace','Players','Instance'):
    assert any(('??_R0?AV'+typename+'@') in k for k in delete_edges),delete_edges
weld_actions=[]
for cls,address,vt,callback in [('WeldSelectionVerb',0x582990,0x8307ac,0x57eb80),('SnapSelectionVerb',0x582a70,0x8307c4,0x57e530)]:
    name,body,refs=next(x for x in functions if x[0].startswith('?doIt@'+cls+'@RBX@@'));target,targetrefs,_=match.target('2008-06',f'{address:08x}');assert match.exact_match(target,targetrefs,body,refs),cls
    assert readptr(vt+16)==address
    start,index=definitions[name];section=sections[index];edges={}
    for i in range(section[7]):
        offset,symbol,kind=struct.unpack_from('<IIH',raw,section[5]+i*10);offset-=start
        if not 0<=offset<len(body)-3:continue
        value=struct.unpack_from('<I',target,offset)[0]
        if kind==20:value=(address+offset+4+struct.unpack_from('<i',target,offset)[0])&0xffffffff
        edges[symbols[symbol][0]]=value
    for token,want in [('checkRunPermissions',0x57d250),('create@VSelection',0x4153b0),('createService',0x581cc0),('for_each',0x57e4d0),('weldInstance' if cls=='WeldSelectionVerb' else 'snapInstance',callback),('playSound@SoundService',0x5bd820),('recordCameraHistory',0x58c5c0)]:assert any(token in k and v==want for k,v in edges.items()),(token,edges)
    weld_actions.append({'class':cls,'address':hex(address),'size':len(body),'vtable':hex(vt),'bindings':edges})
camera_checks = []
for cls, address, vtable in [('AttachCameraCommand', 0x57dcb0, 0x830830), ('TrackCameraCommand', 0x57dce0, 0x830848), ('FollowCameraCommand', 0x57dd10, 0x830860), ('WatchCameraCommand', 0x57dd40, 0x830878)]:
    name, body, refs = next(x for x in functions if x[0].startswith('?isChecked@'+cls+'@RBX@@'))
    target, targetrefs, _ = match.target('2008-06', f'{address:08x}')
    assert match.exact_match(target, targetrefs, body, refs)
    assert readptr(vtable + 12) == address
    camera_checks.append({'class': cls, 'address': hex(address), 'size': len(body), 'vtable_slot': hex(vtable + 12), 'exact': True})
name, body, refs = next(x for x in functions if x[0].startswith('?isEnabled@RunCommand@RBX@@'))
target, targetrefs, _ = match.target('2008-06', '00582700')
assert match.exact_match(target, targetrefs, body, refs), ('RunCommand::isEnabled', len(body))
assert readptr(0x83905c + 8) == 0x582700
run_type = readptr(readptr(0x83905c - 4) + 12)
assert pe.get_string_at_rva(run_type + 8 - image) == b'.?AVRunCommand@RBX@@'
start, index = definitions[name]
section = sections[index]
run_calls = {}
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
    offset -= start
    if kind == 20 and 0 <= offset < len(body)-3:
        run_calls[symbols[symbol][0]] = (0x582700 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
assert any('createService' in k and v == 0x581c00 for k, v in run_calls.items()), run_calls
assert any('clientIsPresent' in k and v == 0x495e60 for k, v in run_calls.items()), run_calls
name, body, refs = next(x for x in functions if x[0].startswith('?isEnabled@ResetCommand@RBX@@'))
target, targetrefs, _ = match.target('2008-06', '005827c0')
assert match.exact_match(target, targetrefs, body, refs), ('ResetCommand::isEnabled', len(body))
assert readptr(0x83908c + 8) == 0x5827c0
reset_type = readptr(readptr(0x83908c - 4) + 12)
assert pe.get_string_at_rva(reset_type + 8 - image) == b'.?AVResetCommand@RBX@@'
start, index = definitions[name]
section = sections[index]
reset_calls = {}
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
    offset -= start
    if kind == 20 and 0 <= offset < len(body)-3:
        reset_calls[symbols[symbol][0]] = (0x5827c0 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
assert any('createService' in k and v == 0x581c00 for k, v in reset_calls.items()), reset_calls
assert any('findLocalPlayer' in k and v == 0x49ac80 for k, v in reset_calls.items()), reset_calls
name, body, refs = next(x for x in functions if x[0].startswith('?isEnabled@StopCommand@RBX@@'))
target, targetrefs, _ = match.target('2008-06', '00582770')
assert match.exact_match(target, targetrefs, body, refs), ('StopCommand::isEnabled', len(body))
assert readptr(0x839074 + 8) == 0x582770
stop_type = readptr(readptr(0x839074 - 4) + 12)
assert pe.get_string_at_rva(stop_type + 8 - image) == b'.?AVStopCommand@RBX@@'
start, index = definitions[name]
section = sections[index]
stop_calls = {}
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
    offset -= start
    if kind == 20 and 0 <= offset < len(body)-3:
        stop_calls[symbols[symbol][0]] = (0x582770 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
assert any('createService' in k and v == 0x581c00 for k, v in stop_calls.items()), stop_calls
name, body, refs = next(x for x in functions if x[0].startswith('?isEnabled@FirstPersonCommand@RBX@@'))
target, targetrefs, _ = match.target('2008-06', '0057d9c0')
assert match.exact_match(target, targetrefs, body, refs)
assert readptr(0x830600 + 8) == 0x57d9c0
first_type = readptr(readptr(0x830600 - 4) + 12)
assert pe.get_string_at_rva(first_type+8-image) == b'.?AVFirstPersonCommand@RBX@@'
start, index = definitions[name]
section = sections[index]
first_calls = {}
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
    offset -= start
    if kind == 20 and 0 <= offset < len(body)-3:
        first_calls[symbols[symbol][0]] = (0x57d9c0 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
assert any('isFirstPersonCamera' in k and v == 0x5ccb00 for k,v in first_calls.items()), first_calls
actions = []
for cls, address, vtable in [('RunCommand', 0x582740, 0x83905c), ('StopCommand', 0x582790, 0x839074), ('ResetCommand', 0x582800, 0x83908c)]:
    name, action, refs = next(x for x in functions if x[0].startswith('?doIt@'+cls+'@RBX@@'))
    target, targetrefs, _ = match.target('2008-06', f'{address:08x}')
    assert match.exact_match(target, targetrefs, action, refs), (cls, len(action))
    assert readptr(vtable + 16) == address
    start, index = definitions[name]
    section = sections[index]
    calls = {}
    for i in range(section[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
        offset -= start
        if kind == 20 and 0 <= offset < len(action)-3:
            calls[symbols[symbol][0]] = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
    assert any('checkRunPermissions' in k and v == 0x57d250 for k,v in calls.items()), calls
    assert any('createService' in k and v == 0x581c00 for k,v in calls.items()), calls
    assert any('setRunState' in k and v == 0x554da0 for k,v in calls.items()), calls
    actions.append({'class':cls,'address':hex(address),'size':len(action),'vtable':hex(vtable),'calls':calls})
name, helper, refs = next(x for x in functions if x[0].startswith('?checkRunPermissions@RBX@@'))
target, targetrefs, _ = match.target('2008-06', '0057d250')
assert match.exact_match(target, targetrefs, helper, refs), ('checkRunPermissions', len(helper))
start, index = definitions[name]
section = sections[index]
helper_edges = {}
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
    offset -= start
    if not 0 <= offset < len(helper)-3: continue
    value = struct.unpack_from('<I', target, offset)[0]
    if kind == 20: value = (0x57d250 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
    helper_edges[symbols[symbol][0]] = value
assert any('clientIsPresent' in k and v == 0x495e60 for k,v in helper_edges.items()), helper_edges
assert any('serverIsPresent' in k and v == 0x495e70 for k,v in helper_edges.items()), helper_edges
assert pe.get_string_at_rva(0x8305e0-image) == b'Insufficinet permissions'
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
select_name, select_body, select_refs = next(x for x in functions if x[0].startswith('?doIt@SelectAllCommand@RBX@@'))
select_target, select_targetrefs, _ = match.target('2008-06', '0057d8c0')
assert match.exact_match(select_target, select_targetrefs, select_body, select_refs)
assert readptr(0x838f50 + 16) == 0x57d8c0
start, index = definitions[select_name]; section = sections[index]; select_edges = {}
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i); offset -= start
    if kind == 20 and 0 <= offset < len(select_body)-3:
        select_edges[symbols[symbol][0]] = (0x57d8c0 + offset + 4 + struct.unpack_from('<i', select_target, offset)[0]) & 0xffffffff
for token, address in [('checkRunPermissions', 0x57d250), ('?selectAll@Workspace@', 0x5a3e10)]:
    assert any(token in k and v == address for k,v in select_edges.items()), (token, select_edges)
all_name, all_body, all_refs = next(x for x in functions if x[0].startswith('?doIt@AllCanSelectCommand@RBX@@'))
all_target, all_targetrefs, _ = match.target('2008-06', '0057d8e0')
assert match.exact_match(all_target, all_targetrefs, all_body, all_refs)
assert readptr(0x838fc4 + 16) == 0x57d8e0
start, index = definitions[all_name]; section = sections[index]; all_edges = {}
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i); offset -= start
    if kind == 20 and 0 <= offset < len(all_body)-3:
        all_edges[symbols[symbol][0]] = (0x57d8e0 + offset + 4 + struct.unpack_from('<i', all_target, offset)[0]) & 0xffffffff
for token, address in [('checkRunPermissions', 0x57d250), ('?setLocked@PartInstance@', 0x59de20), ('recordCameraHistory', 0x58c5c0)]:
    assert any(token in k and v == address for k,v in all_edges.items()), (token, all_edges)
cannot_rows = []
for prefix,address,expected in [
    ('?doIt@CanNotSelectCommand@RBX@@',0x582630,[('checkRunPermissions',0x57d250),('??$create@V?$FilteredSelection@VPVInstance@',0x5805d0),('createService',0x581cc0),('cannotSelect',0x57d940),('??$for_each@',0x57e470),('clearSelection',0x5675d0),('recordCameraHistory',0x58c5c0)]),
    ('?cannotSelect@RBX@@',0x57d940,[('?setLocked@PartInstance@',0x59de20)])]:
    name,body,refs=next(x for x in functions if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06','%08x'%address);assert match.exact_match(target,targetrefs,body,refs)
    start,index=definitions[name];section=sections[index];edges={}
    for i in range(section[7]):
        offset,symbol,kind=struct.unpack_from('<IIH',raw,section[5]+10*i);offset-=start
        if not 0<=offset<len(body)-3:continue
        value=struct.unpack_from('<I',target,offset)[0]
        if kind==20:value=(address+offset+4+struct.unpack_from('<i',target,offset)[0])&0xffffffff
        edges.setdefault(symbols[symbol][0],value)
    for token,value in expected:assert any(token in k and v==value for k,v in edges.items()),(token,edges)
    cannot_rows.append({'address':hex(address),'size':len(body),'symbol':name,'bindings':{k:hex(v) for k,v in edges.items()}})
assert readptr(0x838fec+16)==0x582630
receipt = {'cannot_select': cannot_rows, 'all_can_select': {'address': '0x57d8e0', 'size': len(all_body), 'vtable': '0x838fc4', 'bindings': {k: hex(v) for k,v in all_edges.items()}}, 'select_all': {'address': '0x57d8c0', 'size': len(select_body), 'vtable': '0x838f50', 'bindings': {k: hex(v) for k,v in select_edges.items()}}, 'source_sha256':sha(source),'header_sha256':sha(header),'observer_sha256':sha(Path(__file__)),'object_sha256':sha(obj),'flags':flags,'methods':rows,'property_ctors':property_ctors,'property_base_ctor':{'address':'0x57f530','size':113,'vtable':hex(property_vtable),'edges':property_base_edges},'attach_enabled':{'address':'00582d70','size':221,'vtable':'0x830830','calls':attach_edges},'follow_enabled':follow_enabled,'track_enabled':{'address':'00582e50','size':77,'vtable':'0x830848','calls':track_edges},'selection_camera_actions':selection_camera_actions,'selection_enabled':selection_enabled,'ungroup_checks':ungroup_rows,'controller_checks':controller_rows,'controller_actions':controller_actions,'delete_action':{'address':'00581090','size':len(delete_body),'bindings':delete_edges},'weld_actions':weld_actions,'camera_checks':camera_checks,'first_person_enabled':{'address':'0x57d9c0','size':33,'vtable':'0x830600','calls':first_calls},'run_actions':actions,'permission_helper':{'address':'0x57d250','size':len(helper),'edges':helper_edges},'reset_enabled':{'address':'0x5827c0','size':56,'exact':True,'vtable':'0x83908c','calls':reset_calls},'run_enabled':{'address':'0x582700','size':56,'exact':True,'vtable':'0x83905c','calls':run_calls},'stop_enabled':{'address':'0x582770','size':len(body),'exact':True,'vtable':'0x839074','calls':stop_calls},'scope':'Inactive trials. Original RTTI names and camera check slots verified; full class lifetime and runtime ABI remain unproven.'}
(root / 'work/2008-06/shared-layouts/selection-command-constructors-trial.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS ten selection-command constructors, labels and RTTI')
