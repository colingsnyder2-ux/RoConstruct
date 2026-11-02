"""Prove candidate document storage and virtual-slot declarations before swapping."""
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

import pefile

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import libs, match, rebuild

out = ROOT / 'rebuild/2008-06/out/native-layouts'
out.mkdir(parents=True, exist_ok=True)
source = ROOT / 'rebuild/2008-06/tests/NativeDocumentLayout.cpp'
header = ROOT / 'rebuild/2008-06/native-headers/CRobloxDoc.h'
recipe = libs.RECIPES['rbxgs']
flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD',
         '/D_AFXDLL', '/DNDEBUG', '/D_MBCS', '/DNOMINMAX', '/DBOOST_ALL_NO_LIB']
flags += ['/D' + value for value in recipe['defines'].split()]
flags += ['/I' + str(ROOT / 'rebuild/2008-06/native-headers'),
          '/I' + str(ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/include')]
flags += ['/I' + str((libs.LIBS / value).resolve()) for value in recipe['include'] if value != 'WINSDK']
flags += ['/FoNativeDocumentLayout.obj', str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
(out / 'doc-compile.log').write_text(log)
assert code == 0, log

original = ROOT / 'work/2008-06/original-p4-reference/Roblox.exe'
pe = pefile.PE(str(original), fast_load=True)
target, relocations, row = match.target('2008-06', '00451ac0')
assert target == pe.get_data(0x451ac0 - pe.OPTIONAL_HEADER.ImageBase, len(target))
obj = (out / 'NativeDocumentLayout.obj').read_bytes()
symbol = '??0CRobloxDoc@@QAE@XZ'
body, candidate_relocations = next((body, relocs) for name, body, relocs in match.coff_functions(obj) if name == symbol)
assert match.exact_match(target, relocations, body, candidate_relocations)
constructor = dict(address='00451ac0', symbol=symbol, size=len(body),
                   relocation_normalized_exact=True, target_relocations=relocations,
                   candidate_relocations=candidate_relocations)
methods = []
for address, method in (('00451a10', 'bindExisting'), ('00451a60', 'bindOwned'),
                        ('00403040', 'getDataModel'), ('00450890', 'getVerbContainer'), ('0044fad0', 'SetModifiedFlag'), ('0044fb80', 'SetTitle'), ('004508f0', 'IsModified'), ('0044f8d0', 'DoSave'), ('004533f0', 'OnOpenDocument'), ('0044f9b0', 'OnSaveDocument'),
                        ('004513c0', 'DeleteContents'),
                        ('00452f60', 'OnNewDocument'), ('0044f210', 'OnCloseDocument'),
                        ('0044f200', 'GetRuntimeClass'), ('00455d20', 'GetMessageMap'), ('00455460', 'handle_455460'), ('00455820', 'handle_455820'), ('0042e550', 'OnUpdateAlwaysEnable'), ('00452f00', 'CreateObject')):
    expected, expected_relocations, _ = match.target('2008-06', address)
    assert expected == pe.get_data(int(address, 16) - pe.OPTIONAL_HEADER.ImageBase, len(expected))
    method_symbol, method_body, method_relocations = next(
        (name, body, relocs) for name, body, relocs in match.coff_functions(obj)
        if name.startswith('?' + method + '@CRobloxDoc@@'))
    assert match.exact_match(expected, expected_relocations, method_body, method_relocations), method
    methods.append(dict(address=address, symbol=method_symbol, size=len(method_body),
                        relocation_normalized_exact=True, target_relocations=expected_relocations,
                        candidate_relocations=method_relocations))
expected, expected_relocations, _ = match.target('2008-06', '00451690')
routing_symbol, routing_body, routing_relocations = next(
    (name, body, relocs) for name, body, relocs in match.coff_functions(obj)
    if name.startswith('?OnCmdMsg@?$VerbBinder@VCRobloxDoc'))
assert match.exact_match(expected, expected_relocations, routing_body, routing_relocations), 'OnCmdMsg'
routing = dict(address='00451690', symbol=routing_symbol, size=len(routing_body),
               relocation_normalized_exact=True)
dependencies = []
unresolved = []
for address, prefix, required in (('00413a70', '??1XmlElement@@', True),
                                  ('00450450', '??1StandardVerbs@RBX@@', True),
                                  ('00451940', '??1CRobloxDoc@@', True)):
    expected, expected_relocations, _ = match.target('2008-06', address)
    dependency_symbol, dependency_body, dependency_relocations = next(
        (name, body, relocs) for name, body, relocs in match.coff_functions(obj) if name.startswith(prefix))
    exact = match.exact_match(expected, expected_relocations, dependency_body, dependency_relocations)
    if required:
        assert exact, dependency_symbol
    row = dict(address=address, symbol=dependency_symbol, target_size=len(expected),
               compiled_size=len(dependency_body), relocation_normalized_exact=exact)
    (dependencies if required else unresolved).append(row)

sections, symbols, definitions, starts = match._coff_data_index(obj)
# Bind play/pause call relocations to their original implementations.
for address, method in (('00455460', 'handle_455460'), ('00455820', 'handle_455820')):
    record = next(item for item in methods if item['address'] == address)
    start, section = definitions[record['symbol']]
    table = sections[section]
    relocs = {}
    for index in range(table[7]):
        offset, symbol_index, kind = struct.unpack_from('<IIH', obj, table[5] + 10 * index)
        if offset >= start:
            relocs[offset - start] = symbols[symbol_index][0]
    body, _, _ = match.target('2008-06', address)
    calls = {instruction.address - int(address, 16) + 1: int(instruction.op_str, 16)
             for instruction in Cs(CS_ARCH_X86, CS_MODE_32).disasm(body, int(address, 16))
             if instruction.mnemonic == 'call' and instruction.op_str.startswith('0x')}
    targets = {'?getDataModel@CWorkspace@@': 0x46a940,
               '??0Lock@DataModel@RBX@@QAE@V?$shared_ptr': 0x411b40,
               '?getDataModel@CRobloxDoc@@': 0x403040,
               '??$create@VRunService@RBX@@@ServiceProvider@RBX@@': 0x4530f0,
               '?setRunState@RunService@RBX@@': 0x554da0,
               '??1Lock@DataModel@RBX@@': 0x5773c0,
               '?newRootElement@SerializerV2@@': 0x591a30,
               '?writeChildren@Instance@RBX@@': 0x558110,
               '??1XmlElement@@': 0x413a70, '??3@YAXPAX@Z': 0x6a067a}
    checked = []
    for offset, symbol in relocs.items():
        target = next((value for prefix, value in targets.items() if symbol.startswith(prefix)), None)
        if target is not None:
            assert calls.get(offset) == target, (method, symbol, calls.get(offset), target)
            checked.append(dict(offset=offset, symbol=symbol, target=hex(target)))
    assert len(checked) == (6 if method == 'handle_455460' else 13), (method, checked)
    record['verified_direct_calls'] = checked
message_symbol = next(name for name in definitions if name.startswith('?_messageEntries@?1??GetThisMessageMap@CRobloxDoc@@'))
map_symbol = next(name for name in definitions if name.startswith('?messageMap@?1??GetThisMessageMap@CRobloxDoc@@'))
map_start, map_section = definitions[map_symbol]
map_table = sections[map_section]
assert map_table[3] - map_start == 8 and map_table[7] == 2
map_targets = {}
for index in range(map_table[7]):
    offset, symbol_index, kind = struct.unpack_from('<IIH', obj, map_table[5] + 10 * index)
    assert kind == 6
    map_targets[offset - map_start] = symbols[symbol_index][0]
assert map_targets[0].startswith('?GetThisMessageMap@CDocument@@')
assert map_targets[4] == message_symbol
message_start, message_section = definitions[message_symbol]
message_table = sections[message_section]
assert message_table[3] - message_start == 40 * 24
message_relocations = {}
for index in range(message_table[7]):
    offset, symbol_index, kind = struct.unpack_from('<IIH', obj, message_table[5] + 10 * index)
    assert kind == 6
    message_relocations[offset - message_start] = symbols[symbol_index][0]
assert len(message_relocations) == 39
message_entries = []
for index in range(40):
    offset = index * 24
    candidate = struct.unpack_from('<6I', obj, message_table[4] + message_start + offset)
    native_entry = struct.unpack('<6I', pe.get_data(0x817f18 + offset - pe.OPTIONAL_HEADER.ImageBase, 24))
    assert candidate[:5] == native_entry[:5] and candidate[5] == 0, index
    if index == 39:
        assert not any(native_entry)
        break
    symbol = message_relocations[offset + 20]
    expected = '?OnUpdateAlwaysEnable@CRobloxDoc@@' if native_entry[5] == 0x42e550 else '?handle_%x@CRobloxDoc@@' % native_entry[5]
    assert symbol.startswith(expected), (index, symbol, expected)
    message_entries.append(dict(index=index, original_handler=hex(native_entry[5]), candidate_symbol=symbol))
value, section = definitions['??_7CRobloxDoc@@6B@']
table = sections[section]
slots = {}
for index in range(table[7]):
    offset, target_symbol, kind = struct.unpack_from('<IIH', obj, table[5] + 10 * index)
    if offset >= value:
        assert kind == 6
        slots[(offset - value) // 4] = symbols[target_symbol][0]
assert len(slots) == 46
overrides = {slot for slot, name in slots.items() if '@CRobloxDoc@@' in name and '?$VerbBinder' not in name}
assert overrides == {0, 12, 22, 24, 25, 29, 30, 31, 32, 33, 38, 40}, overrides
assert slots[1].startswith('??_ECRobloxDoc@@')
native = struct.unpack('<46I', pe.get_data(0x817ce4 - pe.OPTIONAL_HEADER.ImageBase, 46 * 4))
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
receipt = dict(revision=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
               compiler_build=21022, flags=flags, compile_exit=code,
               sources={str(path.relative_to(ROOT)): sha(path) for path in
                        (source, header, header.parent / 'VerbBinder.h', Path(__file__),
                         ROOT / 'rebuild/2008-06/native-classes/CRobloxDoc.cpp',
                         ROOT / 'rebuild/2008-06/native-classes/StandardVerbs.cpp',
                         header.parent / 'StandardVerbs.h', header.parent / 'v8xml/XmlElement.h',
                         header.parent / 'RobloxLib.h', header.parent / 'v8datamodel/DataModel.h',
                         header.parent / 'v8tree/Verb.h', header.parent / 'v8tree/Service.h',
                         header.parent / 'script/ScriptContext.h')},
               original_sha256=sha(original), object_sha256=sha(out / 'NativeDocumentLayout.obj'),
               compile_log_sha256=sha(out / 'doc-compile.log'),
               static_layout_gates=dict(size=0x98, XmlElement=0x28, StandardVerbs=0x704,
                                        IWorkspace=4, IContent=4, VARIANT=16, savedState=0x74, ownedVerbs=0x78,
                                        standardVerbs=0x90, workspace=0x94),
               constructor=constructor,
               exact_methods=methods, command_routing=routing, message_entries=message_entries,
               ownership_dependencies=dependencies, unresolved_lifecycle=unresolved,
               virtual_slots=[dict(slot=slot, source_symbol=name, original_address=hex(native[slot]))
                              for slot, name in sorted(slots.items())],
               active_client_changed=False,
               scope='Compiler-only document storage, virtual-slot declarations, twenty document bodies, 39 message entries, command routing and three destructor proofs, including the document destructor. Other virtual bodies and relocated targets remain unverified. No active class swap, linked-function increase or server verification claimed.')
output = ROOT / 'work/2008-06' / sys.argv[1]
output.parent.mkdir(parents=True, exist_ok=True)
output.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS: document storage, %d document bodies and XML/StandardVerbs destructors; document destructor exact' % (len(methods) + 1))
