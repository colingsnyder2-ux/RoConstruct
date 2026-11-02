"""Compare native XML writer constructor, destructor and Workspace caller."""
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
probe = out / 'xml-writer-probe'
overlay = probe / 'v8xml'
overlay.mkdir(parents=True, exist_ok=True)
header = root / 'rebuild/2008-06/native-headers/v8xml/XmlSerializer.h'
text = header.read_text()
member = 'std::set<RBX::ContentId> embeddedContent;'
constructor = '\tTextXmlWriterWithEmbeddedContent(std::ostream& stream)\n\t\t\t: TextXmlWriter(stream)\n\t{\n\t}'
assert text.count(member) == text.count(constructor) == 1
text = text.replace(member, member + '\n\tRBX::ContentProvider* contentProvider;')
text = text.replace(constructor, '\tTextXmlWriterWithEmbeddedContent(RBX::ContentProvider*, std::ostream&);\n\t~TextXmlWriterWithEmbeddedContent();')
(overlay / 'XmlSerializer.h').write_text(text)
source = root / 'rebuild/2008-06/tests/NativeWorkspaceXmlWriterMismatch.cpp'
obj = probe / 'NativeWorkspaceXmlWriterMismatch.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags.insert(0, '/I' + str(probe))
flags += ['/I' + str(root / 'rebuild/2008-06/tests'), '/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, probe)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
rows = []
for prefix, address, expected in [('??0TextXmlWriterWithEmbeddedContent@@', '0046b550', True), ('??1TextXmlWriterWithEmbeddedContent@@', '0046b1e0', False), ('?write@CWorkspace@@', '0046b860', False)]:
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', address)
    exact = match.exact_match(target, targetrefs, body, refs)
    assert exact == expected, (prefix, len(body), len(target))
    if prefix.startswith('?write@'):
        assert len(body) == len(target) == 112 and body[68] == 0 and target[68] == 1
    rows.append({'symbol': name, 'address': address, 'candidate_size': len(body), 'original_size': len(target), 'exact': exact})
implicit_header = text.replace('\n\t~TextXmlWriterWithEmbeddedContent();', '')
(overlay / 'XmlSerializer.h').write_text(implicit_header)
implicit_source = probe / 'NativeWorkspaceXmlWriterImplicit.cpp'
source_text = source.read_text()
explicit_destructor = 'TextXmlWriterWithEmbeddedContent::~TextXmlWriterWithEmbeddedContent() {}'
assert source_text.count(explicit_destructor) == 1
implicit_source.write_text(source_text.replace(explicit_destructor, ''))
implicit_obj = probe / 'NativeWorkspaceXmlWriterImplicit.obj'
implicit_flags = [x for x in flags if not x.startswith('/Fo') and x != str(source)] + ['/Fo' + str(implicit_obj), str(implicit_source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', implicit_flags, probe)
assert code == 0, log
implicit_raw = implicit_obj.read_bytes()
implicit_sections, implicit_symbols, implicit_definitions, _ = match._coff_data_index(implicit_raw)
implicit_rows = []
for prefix, address, expected in [('??0TextXmlWriterWithEmbeddedContent@@', '0046b550', True), ('??1TextXmlWriterWithEmbeddedContent@@', '0046b1e0', True), ('?write@CWorkspace@@', '0046b860', False)]:
    name, body, refs = next(x for x in match.coff_functions(implicit_raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', address)
    exact = match.exact_match(target, targetrefs, body, refs)
    assert exact == expected, (prefix, len(body), len(target))
    implicit_rows.append({'symbol': name, 'address': address, 'candidate_size': len(body), 'original_size': len(target), 'exact': exact})
name, body, refs = next(x for x in match.coff_functions(implicit_raw) if x[0].startswith('??1TextXmlWriterWithEmbeddedContent@@'))
target, _, _ = match.target('2008-06', '0046b1e0')
start, section = implicit_definitions[name]
table = implicit_sections[section]
destructor_calls = {}
for i in range(table[7]):
    offset, index, kind = struct.unpack_from('<IIH', implicit_raw, table[5] + 10 * i)
    offset -= start
    if kind == 20 and 0 <= offset < len(body) - 3:
        destructor_calls[implicit_symbols[index][0]] = (0x46b1e0 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
for prefix, address in [('??1?$_Tree@V?$_Tset_traits@VContentId@RBX@@', 0x46b070), ('??1?$_Tree@V?$_Tmap_traits@VInstanceHandle@RBX@@', 0x4146d0)]:
    assert any(k.startswith(prefix) and v == address for k, v in destructor_calls.items()), (prefix, destructor_calls)
(overlay / 'XmlSerializer.h').write_text(text)
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
image = pe.OPTIONAL_HEADER.ImageBase
readptr = lambda address: struct.unpack('<I', pe.get_data(address - image, 4))[0]
handler = 0x7c39e8
assert pe.get_data(handler - image, 1) == b'\xb8'
funcinfo = readptr(handler + 1)
magic, state_count, unwind_map = struct.unpack('<3I', pe.get_data(funcinfo - image, 12))
assert (magic, state_count) == (0x19930522, 2)
unwind_states = [struct.unpack('<II', pe.get_data(unwind_map - image + 8*i, 8)) for i in range(state_count)]
assert unwind_states == [(0xffffffff, 0), (0xffffffff, 0x7c39e0)]
locator = readptr(0x81c844)
type_descriptor = readptr(locator + 12)
assert pe.get_string_at_rva(type_descriptor + 8 - image) == b'.?AVTextXmlWriterWithEmbeddedContent@@'
assert readptr(0x81c848) == 0x58e810
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
receipt = {'scope': 'Inactive explicit-destructor profile: constructor matches, destructor and caller differ. Implicit-destructor results are recorded separately; no runtime promotion.', 'observer_sha256': sha(Path(__file__)), 'source_sha256': sha(source), 'header_sha256': sha(header), 'overlay_sha256': sha(overlay / 'XmlSerializer.h'), 'object_sha256': sha(obj), 'original_vtable': '0x81c848', 'original_type_descriptor': hex(type_descriptor), 'methods': rows, 'flags': flags}
receipt['original_caller_unwind'] = {'handler': hex(handler), 'funcinfo': hex(funcinfo), 'unwind_map': hex(unwind_map), 'states': [{'to': hex(state), 'action': hex(action)} for state, action in unwind_states], 'finding': 'State 0 has no cleanup action; state 1 invokes writer cleanup.'}
receipt['implicit_destructor_profile'] = {'scope': 'Constructor and implicit destructor match; caller still differs. Complete layout and runtime ABI remain unproven.', 'object_sha256': sha(implicit_obj), 'source_sha256': sha(implicit_source), 'overlay_sha256': hashlib.sha256(implicit_header.encode()).hexdigest(), 'methods': implicit_rows, 'destructor_calls': {k: hex(v) for k, v in destructor_calls.items()}, 'flags': implicit_flags}
(root / 'work/2008-06/shared-layouts/workspace-xml-writer-mismatch.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS XML writer constructor and implicit destructor; caller mismatch recorded')
