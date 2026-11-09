"""Rebuild inactive dialog candidate; report body matches without runtime credit."""
import hashlib
import json
from pathlib import Path
import subprocess
import sys
import struct
import re
import pefile

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import libs, match, rebuild

out = ROOT / 'rebuild/2008-06/out/native-layouts'
source = ROOT / 'rebuild/2008-06/native-classes/CRobloxDHtmlDialog.cpp'
header = ROOT / 'rebuild/2008-06/native-headers/CRobloxDHtmlDialog.h'
recipe = libs.RECIPES['rbxgs']
flags = ['/nologo', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD',
         '/D_AFXDLL', '/DNDEBUG', '/D_MBCS', '/DBOOST_ALL_NO_LIB']
flags += ['/D' + value for value in recipe['defines'].split()]
flags += ['/I' + str(ROOT / 'rebuild/2008-06/native-headers'),
          '/I' + str(ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/include')]
flags += ['/I' + str((libs.LIBS / value).resolve()) for value in recipe['include'] if value != 'WINSDK']
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/P', str(source)], out)
assert code == 0, log
body = (out / 'CRobloxDHtmlDialog.i').read_text(encoding='utf8', errors='replace')
# Keep the original out-of-line STL and imported CString calls.
for needle in ('const _Elem * c_str() const', 'operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );'):
    assert body.count(needle) == 1, needle
    body = body.replace(needle, '__declspec(noinline) ' + needle)
translation = out / 'NativeDHtmlDialogPreprocessed.cpp'
translation.write_text(body, encoding='utf8')
compile_flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/FoNativeDHtmlDialog.obj', str(translation)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', compile_flags, out)
assert code == 0, log
obj = (out / 'NativeDHtmlDialog.obj').read_bytes()
methods = []
for address, prefix in (
    ('0044ef40', '??0CRobloxDHtmlDialog@@'),
    ('00401050', '??1CRobloxDHtmlDialog@@'),
    ('0044ee90', '?GetRuntimeClass@CRobloxDHtmlDialog@@'),
    ('0044f0a0', '??_GCRobloxDHtmlDialog@@'),
    ('0044efd0', '?OnInitDialog@CRobloxDHtmlDialog@@'),
    ('0044eea0', '?GetEventSinkMap@CRobloxDHtmlDialog@@'),
    ('007286a0', '?IsExternalDispatchSafe@CRobloxDHtmlDialog@@'),
    ('0044f010', '?BeforeNavigate2@CRobloxDHtmlDialog@@'),
    ('0044f0c0', '?WindowClosing@CRobloxDHtmlDialog@@'),
    ('0041dcb0', '?checkDialogUrl@@'),
):
    target, target_refs, _ = match.target('2008-06', address)
    name, data, refs = next((n,b,r) for n,b,r in match.coff_functions(obj) if n.startswith(prefix))
    methods.append(dict(address=address, symbol=name, size=len(data), target_size=len(target),
                        relocation_masked_match=match.exact_match(target, target_refs, data, refs)))

pe = pefile.PE(str(ROOT / 'work/2008-06/original-p4-reference/Roblox.exe'))
base = pe.OPTIONAL_HEADER.ImageBase
sections, symbols, definitions, _ = match._coff_data_index(obj)
functions = {n: (b, r) for n, b, r in match.coff_functions(obj)}
imports = {entry.address: (dll.dll.lower(), entry.ordinal)
           for dll in pe.DIRECTORY_ENTRY_IMPORT for entry in dll.imports}
exports = {}
for line in (ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/src/mfc/intel/mfc90.def').read_text().splitlines():
    row = re.match(r'\s*(\S+)\s+@\s+(\d+)\s+NONAME', line)
    if row:
        exports[int(row[2])] = row[1]

def data_refs(name, size):
    start, index = definitions[name]
    section = sections[index]
    refs = {}
    for i in range(section[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', obj, section[5] + i * 10)
        if start <= offset < start + size:
            refs[offset - start] = symbols[symbol][0]
    return obj[section[4] + start:section[4] + start + size], refs

vtables = []
for suffix, address, count in (('CDialog@@@', 0x8170bc, 111), ('CDHtmlEventSink@@@', 0x81708c, 10)):
    name = next(n for n in definitions if n.startswith('??_7CRobloxDHtmlDialog@@6B') and n.endswith(suffix))
    _, refs = data_refs(name, count * 4)
    assert len(refs) == count
    original = struct.unpack('<%dI' % count, pe.get_data(address - base, count * 4))
    rows = []
    for slot, target_address in enumerate(original):
        symbol = refs[slot * 4]
        target = pe.get_data(target_address - base, 6)
        if target[:2] == b'\xff\x25':
            dll, ordinal = imports[struct.unpack_from('<I', target, 2)[0]]
            assert dll == b'mfc90.dll' and exports[ordinal] == symbol, (slot, symbol, ordinal)
            proof = 'MFC import ordinal and decorated symbol'
        elif symbol.startswith(('?Serialize@CObject@@', '?Dump@CObject@@', '?AssertValid@CObject@@')):
            expected = b'\xc3' if symbol.startswith('?AssertValid') else b'\xc2\x04\x00'
            assert target.startswith(expected)
            proof = 'folded release no-op; symbol identity inferred from base slot'
        else:
            # MSVC emits the vector symbol as an alias of the scalar deleting body.
            body_symbol = symbol.replace('??_E', '??_G') if symbol not in functions else symbol
            body, refs_body = functions[body_symbol]
            native, native_refs, _ = match.target('2008-06', '%08x' % target_address)
            assert match.exact_match(native, native_refs, body, refs_body), (slot, symbol, hex(target_address))
            proof = 'relocation-masked body; deleting alias still needs linked proof'
        rows.append(dict(slot=slot, address=hex(target_address), symbol=symbol, proof=proof))
    vtables.append(dict(address=hex(address), slots=rows))

runtime_symbol = '?classCRobloxDHtmlDialog@CRobloxDHtmlDialog@@2UCRuntimeClass@@B'
runtime, runtime_refs = data_refs(runtime_symbol, 28)
getter, _, _ = match.target('2008-06', '0044ee90')
runtime_address = struct.unpack_from('<I', getter, 1)[0]
original_runtime = struct.unpack('<7I', pe.get_data(runtime_address - base, 28))
runtime_words = struct.unpack('<7I', runtime)
assert runtime_words[1:4] == original_runtime[1:4] == (0x130, 0xffff, 0)
assert runtime_words[5:] == original_runtime[5:]
name, _ = data_refs(runtime_refs[0], len('CRobloxDHtmlDialog') + 1)
assert name.rstrip(b'\0') == pe.get_string_at_rva(original_runtime[0] - base) == b'CRobloxDHtmlDialog'
assert runtime_refs[16].startswith('?_GetBaseClass@CRobloxDHtmlDialog@@')
native, refs, _ = match.target('2008-06', '%08x' % original_runtime[4])
body, body_refs = functions[runtime_refs[16]]
assert match.exact_match(native, refs, body, body_refs)

entry_symbol = '?_eventsinkEntries@CRobloxDHtmlDialog@@0QBUAFX_EVENTSINKMAP_ENTRY@@B'
entries, entry_refs = data_refs(entry_symbol, 120)
original_entries = pe.get_data(0x816fc0 - base, 120)
for entry in range(3):
    for field in range(10):
        offset = entry * 40 + field * 4
        if offset not in entry_refs:
            assert entries[offset:offset+4] == original_entries[offset:offset+4], (entry, field)
        elif field in (0, 2):
            original_pointer = struct.unpack_from('<I', original_entries, offset)[0]
            text = pe.get_string_at_rva(original_pointer - base) + b'\0'
            candidate, _ = data_refs(entry_refs[offset], len(text))
            assert candidate == text, (entry, field)
        else:
            assert field == 4 and entry_refs[offset].startswith(
                '?BeforeNavigate2@' if entry == 0 else '?WindowClosing@')
about_source = ROOT / 'rebuild/2008-06/native-classes/CAboutRobloxDialog.cpp'
about_header = ROOT / 'rebuild/2008-06/native-headers/CAboutRobloxDialog.h'
code, log = rebuild.run(rebuild.toolchain(21022), 'cl',
                        flags + ['/c', '/FoNativeAboutDialog.obj', str(about_source)], out)
assert code == 0, log
about_obj = (out / 'NativeAboutDialog.obj').read_bytes()
about_methods = []
for address, prefix in (
    ('00401220', '??0CAboutRobloxDialog@@'),
    ('00401290', '??_GCAboutRobloxDialog@@'),
    ('00401040', '?GetRuntimeClass@CAboutRobloxDialog@@'),
    ('004012c0', '?GetMessageMap@CAboutRobloxDialog@@'),
    ('004010f0', '?OnInitDialog@CAboutRobloxDialog@@'),
    ('004010c0', '?OnDocumentComplete@CAboutRobloxDialog@@'),
    ('00401100', '?OnClickedButtonOK@CAboutRobloxDialog@@'),
    ('004012d0', '?GetDHtmlEventMap@CAboutRobloxDialog@@'),
    ('00401330', '?CreateObject@CAboutRobloxDialog@@'),
    ('00401030', '?_GetBaseClass@CAboutRobloxDialog@@'),
):
    target, target_refs, _ = match.target('2008-06', address)
    name, data, refs = next((n,b,r) for n,b,r in match.coff_functions(about_obj) if n.startswith(prefix))
    about_methods.append(dict(address=address, symbol=name, size=len(data),
                              relocation_masked_match=match.exact_match(target, target_refs, data, refs)))
paths = [source, header, about_source, about_header, Path(__file__)]
receipt = dict(revision=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),
               sources={str(p.relative_to(ROOT)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
               compiler_build=21022, compile_flags=compile_flags, methods=methods, vtables=vtables,
               runtime_size=runtime_words[1], verified_event_entries=3,
               about_methods=about_methods,
               scope='Inactive candidate. Complete vtable/data/EH linkage and runtime integration remain unproven; no integration count credit.')
output = ROOT / 'work/2008-06/shared-layouts/dhtml-dialog-working-probe.json'
output.write_text(json.dumps(receipt, indent=2) + '\n', encoding='utf8')
for row in methods:
    print(row['address'], row['relocation_masked_match'], row['size'], row['target_size'])
assert all(row['relocation_masked_match'] for row in methods)
for row in about_methods:
    print('About', row['address'], row['relocation_masked_match'], row['size'])
assert all(row['relocation_masked_match'] for row in about_methods)
