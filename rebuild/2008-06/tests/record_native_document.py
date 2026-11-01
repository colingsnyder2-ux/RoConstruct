"""Prove candidate document storage and virtual-slot declarations before swapping."""
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

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
methods = []
for address, method in (('00451a10', 'bindExisting'), ('00451a60', 'bindOwned'),
                        ('00403040', 'getDataModel'), ('0044fad0', 'SetModifiedFlag'), ('0044fb80', 'SetTitle'), ('004508f0', 'IsModified'), ('0044f8d0', 'DoSave'),
                        ('004513c0', 'DeleteContents'),
                        ('00452f60', 'OnNewDocument'), ('0044f210', 'OnCloseDocument'),
                        ('0044f200', 'GetRuntimeClass'), ('00452f00', 'CreateObject')):
    expected, expected_relocations, _ = match.target('2008-06', address)
    assert expected == pe.get_data(int(address, 16) - pe.OPTIONAL_HEADER.ImageBase, len(expected))
    method_symbol, method_body, method_relocations = next(
        (name, body, relocs) for name, body, relocs in match.coff_functions(obj)
        if name.startswith('?' + method + '@CRobloxDoc@@'))
    assert match.exact_match(expected, expected_relocations, method_body, method_relocations), method
    methods.append(dict(address=address, symbol=method_symbol, size=len(method_body),
                        relocation_normalized_exact=True, target_relocations=expected_relocations,
                        candidate_relocations=method_relocations))
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
                         header.parent / 'v8tree/Verb.h', header.parent / 'v8tree/Service.h')},
               original_sha256=sha(original), object_sha256=sha(out / 'NativeDocumentLayout.obj'),
               compile_log_sha256=sha(out / 'doc-compile.log'),
               static_layout_gates=dict(size=0x98, XmlElement=0x28, StandardVerbs=0x704,
                                        IWorkspace=4, IContent=4, VARIANT=16, savedState=0x74, ownedVerbs=0x78,
                                        standardVerbs=0x90, workspace=0x94),
               constructor=dict(address='00451ac0', symbol=symbol, size=len(body),
                                relocation_normalized_exact=True, target_relocations=relocations,
                                candidate_relocations=candidate_relocations),
               exact_methods=methods,
               ownership_dependencies=dependencies, unresolved_lifecycle=unresolved,
               virtual_slots=[dict(slot=slot, source_symbol=name, original_address=hex(native[slot]))
                              for slot, name in sorted(slots.items())],
               active_client_changed=False,
               scope='Compiler-only document storage, virtual-slot declarations, thirteen document bodies and three destructor proofs, including the document destructor. Other virtual bodies and relocated targets remain unverified. No active class swap, linked-function increase or server verification claimed.')
output = ROOT / 'work/2008-06' / sys.argv[1]
output.parent.mkdir(parents=True, exist_ok=True)
output.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS: document storage, %d document bodies and XML/StandardVerbs destructors; document destructor exact' % (len(methods) + 1))
