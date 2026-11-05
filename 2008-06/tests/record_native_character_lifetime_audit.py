"""Audit original character base construction and destruction; no runtime swap."""
import hashlib, json, struct, sys
from pathlib import Path
import pefile
root = Path(__file__).resolve().parents[3]
sys.path.insert(0,str(root))
from roc import match, rebuild
out = root / 'rebuild/2008-06/out/RbxgsApp/linked'
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
image = pe.OPTIONAL_HEADER.ImageBase
readptr = lambda a: struct.unpack('<I', pe.get_data(a-image,4))[0]
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
rows = []
for filename, prefix, address, expected in [
    ('ICharacterSubject.obj','??0ICharacterSubject@RBX@@',0x641320,{'??_8ICharacterSubject@RBX@@':0x84a5fc,'?reset@Vector3ERA@RBX@@':0x666280,'?reset@floatERA@RBX@@':0x666240}),
    ('Humanoid.obj','??0Humanoid@RBX@@',0x5db280,{'??0ICharacterSubject@RBX@@':0x641320,'??_7Humanoid@RBX@@6BICameraSubject':0x83d388})]:
    path = out / filename
    raw = path.read_bytes()
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06',f'{address:08x}')
    assert match.exact_match(target,targetrefs,body,refs), filename
    sections,symbols,definitions,_ = match._coff_data_index(raw)
    start,index = definitions[name]; section = sections[index]; found = {}
    for i in range(section[7]):
        offset,symbol,kind = struct.unpack_from('<IIH',raw,section[5]+10*i);offset-=start
        if not 0 <= offset < len(body)-3: continue
        value = struct.unpack_from('<I',target,offset)[0]
        if kind == 20: value=(address+offset+4+struct.unpack_from('<i',target,offset)[0]) & 0xffffffff
        for key,want in expected.items():
            if symbols[symbol][0].startswith(key):
                assert value == want,(key,hex(value));found[key]=hex(value)
    assert set(found)==set(expected),found
    rows.append({'address':hex(address),'size':len(body),'object_sha256':sha(path),'bindings':found})
assert readptr(0x83d388) == 0x5d8090
adjust = pe.get_data(0x5d8090-image,11)
assert adjust[:6] == bytes.fromhex('81e94c010000') and adjust[6] == 0xe9
assert 0x5d809b + struct.unpack_from('<i',adjust,7)[0] == 0x5d8400
thunk = pe.get_data(0x5d8400-image,31)
assert thunk[3] == 0xe8 and 0x5d8408 + struct.unpack_from('<i',thunk,4)[0] == 0x5d7d20
raw = (out/'Humanoid.obj').read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('??1Humanoid@RBX@@'))
target,targetrefs,_ = match.target('2008-06','005d7d20')
assert not match.exact_match(target,targetrefs,body,refs)
exact_path = root / 'rebuild/2008-06/out/RbxgsApp/verified/0003.obj'
exact_raw = exact_path.read_bytes()
exact_name, exact_body, exact_refs = next(x for x in match.coff_functions(exact_raw) if x[0].startswith('??1Humanoid@RBX@@'))
assert match.exact_match(target,targetrefs,exact_body,exact_refs)
sections,symbols,definitions,_ = match._coff_data_index(exact_raw)
vt_name = next(n for n in definitions if n.startswith('??_7Humanoid@RBX@@6B?$GuidItem'))
pos,idx = definitions[vt_name]; section = sections[idx]; slots = {}
for i in range(section[7]):
    offset,symbol,kind = struct.unpack_from('<IIH',exact_raw,section[5]+10*i)
    if pos <= offset < pos+56: slots[(offset-pos)//4] = symbols[symbol][0]
assert slots[1].startswith('?onGuidChanged@'), slots
assert slots[11].startswith('?onLastChildRemoved@'), slots
assert slots[12].startswith('?readProperty@'), slots
assert readptr(0x83d47c + 11*4) == 0x559170
source = root / 'rebuild/2008-06/tests/NativeHumanoidDestructorTrial.cpp'
trial = root / 'rebuild/2008-06/out/native-layouts/NativeHumanoidDestructorTrial.obj'
base = json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
code, log = rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(trial),str(source)],trial.parent)
assert code == 0, log
trial_raw = trial.read_bytes()
trial_name,trial_body,trial_refs = next(x for x in match.coff_functions(trial_raw) if x[0].startswith('??1Humanoid@RBX@@'))
assert match.exact_match(target,targetrefs,trial_body,trial_refs)
sections,symbols,definitions,_ = match._coff_data_index(trial_raw)
vt_name = next(n for n in definitions if n.startswith('??_7Humanoid@RBX@@6B?$GuidItem'))
pos,idx = definitions[vt_name]; section = sections[idx]; trial_slots = {}
for i in range(section[7]):
    offset,symbol,kind = struct.unpack_from('<IIH',trial_raw,section[5]+10*i)
    if pos <= offset < pos+52: trial_slots[(offset-pos)//4] = symbols[symbol][0]
assert trial_slots[11].startswith('?readProperty@'), trial_slots
start,idx = definitions[trial_name]; section = sections[idx]; trial_edges = {}
for i in range(section[7]):
    offset,symbol,kind = struct.unpack_from('<IIH',trial_raw,section[5]+10*i); offset -= start
    if not 0 <= offset < len(trial_body)-3: continue
    value = struct.unpack_from('<I',target,offset)[0]
    if kind == 20: value = (0x5d7d20+offset+4+struct.unpack_from('<i',target,offset)[0]) & 0xffffffff
    trial_edges[symbols[symbol][0]] = value
for prefix, address in [('??1IRenderable@RBX@@',0x47d410), ('??1?$FactoryProduct@VHumanoid@RBX@@',0x5d77d0), ('??_7Humanoid@RBX@@6BICameraSubject',0x83d388), ('??_7Humanoid@RBX@@6B?$GuidItem',0x83d47c)]:
    assert any(k.startswith(prefix) and v == address for k,v in trial_edges.items()), (prefix,trial_edges)
for name, address in trial_edges.items():
    if name.startswith('??_7Humanoid@RBX@@'):
        descriptor = readptr(readptr(address-4)+12)
        assert pe.get_string_at_rva(descriptor+8-image) == b'.?AVHumanoid@RBX@@', (name,hex(address))
col = readptr(0x83d42c-4)
hierarchy = readptr(col+16)
count = readptr(hierarchy+8)
array = readptr(hierarchy+12)
base_names = [pe.get_string_at_rva(readptr(readptr(array+4*i))+8-image).decode('ascii') for i in range(count)]
for spelling in ('UDescendantAdded@','UDescendantRemoving@'):
    assert any(spelling in name for name in base_names), base_names
assert not any('UDescendentAdded@' in name or 'UDescendentRemoving@' in name for name in base_names)
receipt = {'original_humanoid_rtti_bases':base_names,'shared_header_dtor':{'size':len(trial_body),'exact':True,'source_sha256':sha(source),'object_sha256':sha(trial),'slots':trial_slots,'bindings':trial_edges},'exact_dtor_object_sha256':sha(exact_path),'exact_dtor_size':len(exact_body),'exact_dtor_body':True,'exact_object_vtable_slots':slots,'original_slot11':'0x559170','constructors':rows,'destructor_path':['0x83d388','0x5d8090','0x5d8400','0x5d7d20'],'destructor_candidate_size':len(body),'destructor_original_size':len(target),'destructor_exact':False,'scope':'Shared-header destructor body and readProperty slot match; remaining vtables, call targets, RTTI/data identity, other objects and runtime unproven. Recovered prior object has unsafe extra slot; donor destructor differs. No runtime swap or promotion.'}
(root/'work/2008-06/shared-layouts/character-lifetime-audit.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS two constructors and shared-header destructor; readProperty slot 11')
