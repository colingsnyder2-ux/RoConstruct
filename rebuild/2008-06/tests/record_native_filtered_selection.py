"""Verify native filtered selection constructor, destructor and call bindings."""
import hashlib
import json
import struct
import sys
from pathlib import Path
import pefile

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/tests/NativeFilteredSelectionTrial.cpp'
header = root / 'rebuild/2008-06/native-headers/v8datamodel/Selection.h'
obj = out / 'NativeFilteredSelectionTrial.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/Fo' + str(obj), str(source)], out)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
rows = []
for prefix, address, expected in [
        ('??0?$FilteredSelection@VPVInstance@RBX@@@RBX@@', 0x57eeb0, [('??0?$NonFactoryProduct@', 0x409960), ('?setName@Instance@RBX@@', 0x55af90), ('??_7?$FilteredSelection@VPVInstance@RBX@@@RBX@@', 0x830944)]),
        ('??1?$FilteredSelection@VPVInstance@RBX@@@RBX@@', 0x57f040, [('?removeFilteredSelection@Selection@RBX@@', 0x5670f0)]),
        ('?onSelectionChanged@?$FilteredSelection@VPVInstance@RBX@@@RBX@@', 0x57fba0, [('??_R0?AVPVInstance@RBX@@', 0x947f1c), ('??_R0?AVInstance@RBX@@', 0x92907c), ('___RTDynamicCast', 0x6a17c6), ('?push_back@?$vector@PAVPVInstance@RBX@@', 0x4213a0), ('?erase@?$vector@PAVPVInstance@RBX@@', 0x459830)])]:
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', '%08x' % address)
    assert match.exact_match(target, targetrefs, body, refs), (name, len(body), len(target))
    start, section = definitions[name]
    table = sections[section]
    bindings = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10*i)
        offset -= start
        if 0 <= offset < len(body) - 3:
            value = struct.unpack_from('<I', target, offset)[0]
            if kind == 20:
                value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            bindings[symbols[index][0]] = value
    for key, value in expected:
        assert any(k.startswith(key) and v == value for k, v in bindings.items()), (key, bindings)
    rows.append({'address': hex(address), 'symbol': name, 'size': len(body), 'exact': True, 'bindings': {k: hex(v) for k, v in bindings.items()}})
service_source = root / 'rebuild/2008-06/native-classes/FilteredSelectionService.cpp'
service_obj = out / 'NativeFilteredSelectionService.obj'
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/Fo' + str(service_obj), str(service_source)], out)
assert code == 0, log
service_raw = service_obj.read_bytes()
service_sections, service_symbols, service_definitions, _ = match._coff_data_index(service_raw)
service_name, service_body, service_refs = next(x for x in match.coff_functions(service_raw) if x[0].startswith('??$create@V?$FilteredSelection@VPVInstance@RBX@@'))
service_target, service_targetrefs, _ = match.target('2008-06', '00580800')
assert match.exact_match(service_target, service_targetrefs, service_body, service_refs)
start, section = service_definitions[service_name]
table = service_sections[section]
service_bindings = {}
for i in range(table[7]):
    offset, index, kind = struct.unpack_from('<IIH', service_raw, table[5] + 10*i)
    offset -= start
    if 0 <= offset < len(service_body) - 3:
        value = struct.unpack_from('<I', service_target, offset)[0]
        if kind == 20:
            value = (0x580800 + offset + 4 + struct.unpack_from('<i', service_target, offset)[0]) & 0xffffffff
        service_bindings[service_symbols[index][0]] = value
assert any(k.startswith('??$create@V?$FilteredSelection@VPVInstance@RBX@@') and v == 0x5805d0 for k, v in service_bindings.items()), service_bindings
factory_source = root / 'rebuild/2008-06/native-classes/FilteredSelectionFactory.cpp'
factory_obj = out / 'NativeFilteredSelectionFactory.obj'
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/Fo' + str(factory_obj), str(factory_source)], out)
assert code == 0, log
factory_raw = factory_obj.read_bytes()
factory_sections, factory_symbols, factory_definitions, _ = match._coff_data_index(factory_raw)
factory_name, factory_body, factory_refs = next(x for x in match.coff_functions(factory_raw) if x[0].startswith('??$create@V?$FilteredSelection@VPVInstance@RBX@@@RBX@@@ServiceProvider@RBX@@QBE'))
factory_target, factory_targetrefs, _ = match.target('2008-06', '005805d0')
assert match.exact_match(factory_target, factory_targetrefs, factory_body, factory_refs)
start, section = factory_definitions[factory_name]
table = factory_sections[section]
factory_bindings = {}
for i in range(table[7]):
    offset, index, kind = struct.unpack_from('<IIH', factory_raw, table[5] + 10*i)
    offset -= start
    if 0 <= offset < len(factory_body) - 3:
        value = struct.unpack_from('<I', factory_target, offset)[0]
        if kind == 20:
            value = (0x5805d0 + offset + 4 + struct.unpack_from('<i', factory_target, offset)[0]) & 0xffffffff
        factory_bindings[factory_symbols[index][0]] = value
for prefix, address in [('??$find@V?$FilteredSelection@VPVInstance@RBX@@', 0x57fd20),
                        ('??$create@V?$FilteredSelection@VPVInstance@RBX@@@RBX@@@?$Creatable@', 0x57f710),
                        ('?flag@?1???$getClassIndex@V?$FilteredSelection@VPVInstance@RBX@@', 0x9753c4),
                        ('??$doGetClassIndex@V?$FilteredSelection@VPVInstance@RBX@@', 0x57d800),
                        ('?setParent@Instance@RBX@@', 0x55a8f0)]:
    assert any(k.startswith(prefix) and v == address for k, v in factory_bindings.items()), (prefix, factory_bindings)
model_name,model_body,model_refs=next(x for x in match.coff_functions(factory_raw) if x[0].startswith('??$create@V?$FilteredSelection@VModelInstance@RBX@@@RBX@@@ServiceProvider@RBX@@QBE'))
model_target,model_targetrefs,_=match.target('2008-06','005806c0');assert match.exact_match(model_target,model_targetrefs,model_body,model_refs)
start,section=factory_definitions[model_name];table=factory_sections[section];model_bindings={}
for i in range(table[7]):
    offset,index,kind=struct.unpack_from('<IIH',factory_raw,table[5]+10*i);offset-=start
    if not 0<=offset<len(model_body)-3:continue
    value=struct.unpack_from('<I',model_target,offset)[0]
    if kind==20:value=(0x5806c0+offset+4+struct.unpack_from('<i',model_target,offset)[0])&0xffffffff
    model_bindings[factory_symbols[index][0]]=value
for prefix,address in [('??$find@V?$FilteredSelection@VModelInstance',0x57fdd0),('??$create@V?$FilteredSelection@VModelInstance',0x57f790),('??$doGetClassIndex@V?$FilteredSelection@VModelInstance',0x57d860),('?setParent@Instance@RBX@@',0x55a8f0)]:
    assert any(k.startswith(prefix) and v==address for k,v in model_bindings.items()),(prefix,model_bindings)
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
assert pe.get_string_at_rva(0x8308a4 - pe.OPTIONAL_HEADER.ImageBase) == b'FilteredSelection'
assert pe.get_string_at_rva(0x947f1c + 8 - pe.OPTIONAL_HEADER.ImageBase) == b'.?AVPVInstance@RBX@@'
assert struct.unpack('<I', pe.get_data(0x8308bc - pe.OPTIONAL_HEADER.ImageBase, 4))[0] == 0x57fba0
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'scope': 'Inactive FilteredSelection<PVInstance> constructor, destructor, context lookup and provider factory match; singleton identity, virtual behavior, ownership and runtime remain unproven.', 'source_sha256': sha(source), 'header_sha256': sha(header), 'observer_sha256': sha(Path(__file__)), 'object_sha256': sha(obj), 'methods': rows, 'service_source_sha256': sha(service_source), 'service_object_sha256': sha(service_obj), 'service_lookup': {'address': '00580800', 'size': len(service_body), 'exact': True, 'bindings': {k: hex(v) for k, v in service_bindings.items()}}, 'factory_source_sha256': sha(factory_source), 'factory_object_sha256': sha(factory_obj), 'model_provider_factory':{'address':'005806c0','size':len(model_body),'exact':True,'bindings':{k:hex(v) for k,v in model_bindings.items()}}, 'provider_factory': {'address': '005805d0', 'size': len(factory_body), 'exact': True, 'bindings': {k: hex(v) for k, v in factory_bindings.items()}}, 'flags': flags}
(root / 'work/2008-06/shared-layouts/filtered-selection-lifetime-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native filtered selection constructor and destructor')
