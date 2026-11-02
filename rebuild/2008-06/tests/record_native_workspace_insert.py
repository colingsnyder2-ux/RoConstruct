"""Compile inactive CWorkspace::insert and record original call-edge evidence."""
import hashlib
import json
import struct
from pathlib import Path
import sys
import pefile

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from capstone import Cs, CS_ARCH_X86, CS_MODE_32
from roc import libs, match, rebuild

out = ROOT / 'rebuild/2008-06/out/native-layouts'
out.mkdir(parents=True, exist_ok=True)
source = ROOT / 'rebuild/2008-06/native-classes/CWorkspaceInsert.cpp'
recipe = libs.RECIPES['rbxgs']
flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD',
         '/D_AFXDLL', '/DNDEBUG', '/D_MBCS', '/DNOMINMAX', '/DBOOST_ALL_NO_LIB']
flags += ['/D' + value for value in recipe['defines'].split()]
flags += ['/I' + str(ROOT / 'rebuild/2008-06/native-headers'),
          '/I' + str(ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/include')]
flags += ['/I' + str((libs.LIBS / value).resolve()) for value in recipe['include'] if value != 'WINSDK']
flags += ['/FoWorkspaceInsert.obj', str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = (out / 'WorkspaceInsert.obj').read_bytes()
symbol, body, refs = next(row for row in match.coff_functions(raw) if row[0].startswith('?insert@CWorkspace@@'))
target, target_refs, _ = match.target('2008-06', '0046b9d0')
sections, symbols, definitions, _ = match._coff_data_index(raw)
start, section = definitions[symbol]
table = sections[section]
relocs = {}
for index in range(table[7]):
    offset, symbol_index, kind = struct.unpack_from('<IIH', raw, table[5] + index * 10)
    if start <= offset < start + len(body) and kind == 20:
        relocs[offset-start] = symbols[symbol_index][0]
original_calls = {hex(i.address): i.op_str for i in Cs(CS_ARCH_X86, CS_MODE_32).disasm(target, 0x46b9d0)
                  if i.mnemonic == 'call' and i.op_str.startswith('0x')}
expected = {'0x46ba16':'0x46ae30', '0x46ba63':'0x421cb0', '0x46ba8f':'0x413c20',
            '0x46bb34':'0x58f6c0', '0x46bb6a':'0x593250', '0x46bbb3':'0x5911d0',
            '0x46bbf5':'0x413b00'}
assert all(original_calls.get(site) == dest for site, dest in expected.items())
for prefix in ('?findFirstChildByClassName@Instance@RBX@@', '??$create@VSelection@RBX@@',
               '?front@Selection@RBX@@', '?parse@TextXmlParser@@',
               '?loadInstances@SerializerV2@@', '?insertInstances@RootInstance@RBX@@',
               '??$setSelection@'):
    assert any(value.startswith(prefix) for value in relocs.values()), prefix
inputs = [Path(__file__), source, ROOT/'rebuild/2008-06/native-headers/CWorkspace.h',
          ROOT/'rebuild/2008-06/native-headers/v8tree/Instance.h',
          ROOT/'rebuild/2008-06/native-headers/v8tree/Service.h',
          ROOT/'rebuild/2008-06/native-headers/v8datamodel/Selection.h',
          ROOT/'rebuild/2008-06/native-headers/v8datamodel/DataModel.h',
          ROOT/'rebuild/2008-06/native-headers/util/RunStateOwner.h',
          ROOT/'rebuild/2008-06/native-headers/v8xml/XmlSerializer.h']
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
receipt = {'scope':'Inactive source candidate; layout, binding, exception path and runtime integration remain unproved.',
           'inputs':{str(path.relative_to(ROOT)):sha(path) for path in inputs},
           'flags':flags, 'object_sha256':sha(out/'WorkspaceInsert.obj'),
           'symbol':symbol, 'candidate_size':len(body), 'original_size':len(target),
           'relocation_normalized_exact':match.exact_match(target,target_refs,body,refs),
           'original_call_sites':expected, 'candidate_relocations':relocs}
pre = out / 'workspace-insert-profile-preprocess'
pre.mkdir(exist_ok=True)
pre_flags = [flag for flag in flags if flag != '/c' and not flag.startswith('/Fo')] + ['/P']
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', pre_flags, pre)
assert code == 0, log
profile = (pre / 'CWorkspaceInsert.i').read_text(errors='replace')
inline_rdbuf = '_Mysb * rdbuf() const\n\t\t{\t\n\t\treturn (_Mystrbuf);\n\t\t}'
assert profile.count(inline_rdbuf) == 1
# The original binary imports this exact standard-library method from MSVCP90.
profile = profile.replace(inline_rdbuf, '_Mysb * rdbuf() const;', 1)
implicit_profile = profile
# Compile the implicit destructor separately, as in the original library.
parser_decl = 'class TextXmlParser : public XmlParser\n{\nprivate:'
assert profile.count(parser_decl) == 1
profile = profile.replace(parser_decl, 'class TextXmlParser : public XmlParser\n{\npublic:\n\t~TextXmlParser();\nprivate:', 1)
profile_source = out / 'WorkspaceInsertNativeProfile.cpp'
profile_source.write_text(profile)
profile_obj = out / 'WorkspaceInsertNativeProfile.obj'
profile_flags = ['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD',
                 '/Fo'+str(profile_obj),str(profile_source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', profile_flags, out)
assert code == 0, log
profile_raw = profile_obj.read_bytes()
functions = list(match.coff_functions(profile_raw))
profile_name, profile_body, profile_refs = next(row for row in functions if row[0].startswith('?insert@CWorkspace@@'))
assert match.exact_match(target, target_refs, profile_body[:len(target)], [ref for ref in profile_refs if ref < len(target)])
ctor_target, ctor_refs, _ = match.target('2008-06', '00415350')
ctor_name, ctor_body, ctor_candidate_refs = next(row for row in functions if row[0].startswith('??0TextXmlParser@@'))
assert match.exact_match(ctor_target, ctor_refs, ctor_body, ctor_candidate_refs)
dtor_source = out / 'WorkspaceInsertImplicitDtor.cpp'
dtor_source.write_text(implicit_profile)
dtor_obj = out / 'WorkspaceInsertImplicitDtor.obj'
dtor_flags = ['/nologo','/c','/O2','/Ob1','/Oy','/GF','/GS-','/EHsc','/MD',
              '/Fo'+str(dtor_obj),str(dtor_source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', dtor_flags, out)
assert code == 0, log
dtor_target, dtor_refs, _ = match.target('2008-06', '004147c0')
dtor_name, dtor_body, dtor_candidate_refs = next(row for row in match.coff_functions(dtor_obj.read_bytes()) if row[0].startswith('??1TextXmlParser@@'))
assert match.exact_match(dtor_target, dtor_refs, dtor_body, dtor_candidate_refs)
pe = pefile.PE(str(ROOT/'work/2008-06/original-p4-reference/Roblox.exe'))
dll, imp = next((entry.dll.decode(), item.name.decode()) for entry in pe.DIRECTORY_ENTRY_IMPORT
                for item in entry.imports if item.address == 0x8023c4)
assert dll.lower() == 'msvcp90.dll' and imp.startswith('?rdbuf@?$basic_ios@D')
sections, symbols, definitions, _ = match._coff_data_index(profile_raw)
start, section = definitions[profile_name]
table = sections[section]
profile_symbols = [symbols[struct.unpack_from('<IIH', profile_raw, table[5]+10*i)[1]][0]
                   for i in range(table[7])
                   if start <= struct.unpack_from('<IIH', profile_raw, table[5]+10*i)[0] < start+len(target)]
assert '__imp_' + imp in profile_symbols
main_expected = {
    0x047:('?findFirstChildByClassName@Instance@RBX@@', 0x46ae30),
    0x07a:('??0Lock@DataModel@RBX@@', 0x411b40),
    0x094:('??$create@VSelection@RBX@@', 0x421cb0),
    0x0c0:('?front@Selection@RBX@@', 0x413c20),
    0x137:('??0?$vector@', 0x4293d0),
    0x154:('??0TextXmlParser@@', 0x415350),
    0x165:('?parse@TextXmlParser@@', 0x58f6c0),
    0x182:('??1XmlElement@@', 0x413a70), 0x188:('??3@YAXPAX@Z', 0x6a067a),
    0x19b:('?loadInstances@SerializerV2@@', 0x593250),
    0x1a9:('??1XmlElement@@', 0x413a70), 0x1af:('??3@YAXPAX@Z', 0x6a067a),
    0x1be:('??1TextXmlParser@@', 0x4147c0),
    0x1e4:('?insertInstances@RootInstance@RBX@@', 0x5911d0),
    0x226:('??$setSelection@', 0x413b00),
    0x235:('??1?$vector@', 0x5a2fe0), 0x244:('??1Lock@DataModel@RBX@@', 0x5773c0)}
main_bindings = {}
for index in range(table[7]):
    offset, symbol_index, kind = struct.unpack_from('<IIH', profile_raw, table[5] + 10*index)
    offset -= start
    if offset in main_expected:
        prefix, expected_target = main_expected[offset]
        symbol = symbols[symbol_index][0]
        target_address = 0x46b9d0 + offset + 4 + struct.unpack_from('<i', target, offset)[0]
        assert kind == 20 and symbol.startswith(prefix) and target_address == expected_target
        main_bindings[hex(offset)] = {'symbol':symbol, 'target':hex(target_address)}
assert len(main_bindings) == len(main_expected)
selection_target, selection_refs, _ = match.target('2008-06', '00413b00')
selection_name, selection_body, selection_candidate_refs = next(row for row in functions if row[0].startswith('??$setSelection@'))
assert match.exact_match(selection_target, selection_refs, selection_body, selection_candidate_refs)
front_source = ROOT/'rebuild/2008-06/native-classes/SelectionFront.cpp'
front_flags = flags[:-2] + ['/FoSelectionFront.obj',str(front_source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', front_flags, out)
assert code == 0, log
front_name, front_body, front_refs = next(row for row in match.coff_functions((out/'SelectionFront.obj').read_bytes()) if row[0].startswith('?front@Selection@RBX@@'))
front_target, front_target_refs, _ = match.target('2008-06', '00413c20')
assert match.exact_match(front_target, front_target_refs, front_body, front_refs)
receipt['inputs'][str(front_source.relative_to(ROOT))] = sha(front_source)
lookup_source = ROOT/'rebuild/2008-06/native-classes/InstanceClassLookup.cpp'
lookup_flags = flags[:-2] + ['/FoInstanceClassLookup.obj',str(lookup_source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', lookup_flags, out)
assert code == 0, log
lookup_raw = (out/'InstanceClassLookup.obj').read_bytes()
lookup_functions = list(match.coff_functions(lookup_raw))
existing_instance_obj = ROOT/'rebuild/2008-06/out/RbxgsApp/linked/Instance.obj'
existing_functions = list(match.coff_functions(existing_instance_obj.read_bytes()))
lookup_methods = []
for address, prefix in [('0041f2b0','?getClassNameStr@Instance@RBX@@'),
                        ('0046ae30','?findFirstChildByClassName@Instance@RBX@@')]:
    expected_body, expected_refs, _ = match.target('2008-06', address)
    method_name, method_body, method_refs = next(row for row in (existing_functions if address == '0041f2b0' else lookup_functions) if row[0].startswith(prefix))
    assert match.exact_match(expected_body, expected_refs, method_body, method_refs)
    lookup_methods.append({'address':address, 'symbol':method_name, 'size':len(method_body),
                           'relocation_normalized_exact':True})
lookup_sections, lookup_symbols, lookup_defs, _ = match._coff_data_index(lookup_raw)
lookup_start, lookup_section = lookup_defs[lookup_methods[1]['symbol']]
lookup_table = lookup_sections[lookup_section]
lookup_edges = []
for index in range(lookup_table[7]):
    offset, symbol_index, kind = struct.unpack_from('<IIH', lookup_raw, lookup_table[5]+10*index)
    offset -= lookup_start
    if 0 <= offset < lookup_methods[1]['size'] and kind == 20:
        symbol = lookup_symbols[symbol_index][0]
        if symbol.startswith('?getClassNameStr@Instance@RBX@@'):
            lookup_target, _, _ = match.target('2008-06','0046ae30')
            assert 0x46ae30 + offset + 4 + struct.unpack_from('<i',lookup_target,offset)[0] == 0x41f2b0
            lookup_edges.append({'symbol':symbol,'target':'0x41f2b0'})
assert len(lookup_edges) == 1
receipt['inputs'][str(lookup_source.relative_to(ROOT))] = sha(lookup_source)
original_full = pe.get_data(0x46b9d0 - pe.OPTIONAL_HEADER.ImageBase, len(profile_body))
catch_relocs = [offset for offset in profile_refs if offset >= len(target)]
assert catch_relocs == [612, 625, 639, 683, 693]
expected_catch = {612:('?setParent@Instance@RBX@@', 0x55a8f0, 6),
                  625:('?end@', 0x68ff20, 20), 639:('?begin@', 0x68fef0, 20),
                  683:('??$for_each@', 0x5903f0, 20), 693:('__CxxThrowException@8', 0x6a158c, 20)}
catch_symbols = {}
for index in range(table[7]):
    offset, symbol_index, kind = struct.unpack_from('<IIH', profile_raw, table[5] + 10*index)
    offset -= start
    if offset in expected_catch:
        prefix, destination, expected_kind = expected_catch[offset]
        symbol = symbols[symbol_index][0]
        assert kind == expected_kind and symbol.startswith(prefix), (offset, symbol)
        value = struct.unpack_from('<i' if kind == 20 else '<I', original_full, offset)[0]
        assert (0x46b9d0 + offset + 4 + value if kind == 20 else value) == destination
        catch_symbols[str(offset)] = {'symbol':symbol, 'target':hex(destination)}
assert len(catch_symbols) == len(expected_catch)
original_catch = bytearray(original_full[len(target):])
candidate_catch = bytearray(profile_body[len(target):])
for offset in catch_relocs:
    original_catch[offset-len(target):offset-len(target)+4] = b'\0'*4
    candidate_catch[offset-len(target):offset-len(target)+4] = b'\0'*4
assert original_catch == candidate_catch
receipt['native_crt_profile'] = {
    'preprocess_flags':pre_flags, 'compile_flags':profile_flags, 'object_sha256':sha(profile_obj),
    'original_msvcp90_import':imp, 'main_size':len(target), 'main_relocation_normalized_exact':True,
    'verified_main_bindings':main_bindings,
    'total_candidate_size_including_exception_funclet':len(profile_body),
    'parser_constructor':{'symbol':ctor_name, 'size':len(ctor_body), 'relocation_normalized_exact':True},
    'parser_destructor':{'symbol':dtor_name, 'candidate_size':len(dtor_body), 'original_size':len(dtor_target),
                         'relocation_normalized_exact':True, 'compile_flags':dtor_flags, 'object_sha256':sha(dtor_obj)},
    'exception_funclet':{'size':len(candidate_catch), 'relocation_normalized_exact':True, 'verified_targets':catch_symbols},
    'selection':{'setSelection':{'symbol':selection_name, 'size':len(selection_body), 'relocation_normalized_exact':True},
                 'front':{'symbol':front_name, 'size':len(front_body), 'relocation_normalized_exact':True, 'flags':front_flags}},
    'class_lookup':{'methods':lookup_methods, 'existing_getter_object_sha256':sha(existing_instance_obj), 'verified_calls':lookup_edges, 'flags':lookup_flags},
    'scope':'Original import profile matches insert main body and exception funclet with listed targets; parser ctor/dtor match separately. Remaining bindings, linking and runtime remain unverified.'}
(ROOT/'work/2008-06/shared-layouts/workspace-insert-candidate.json').write_text(json.dumps(receipt, indent=2)+'\n')
print('PASS insert main %d bytes, exception funclet, parser ctor and dtor match: %s' %
      (len(target), receipt['native_crt_profile']['parser_destructor']['relocation_normalized_exact']))
