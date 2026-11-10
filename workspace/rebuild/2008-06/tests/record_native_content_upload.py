"""Verify native CContent Upload, exception reporter and COM identifiers."""
import hashlib
import json
import struct
import sys
import uuid
from pathlib import Path

import pefile

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
probe = out / 'content-upload-probe'
probe.mkdir(exist_ok=True)
source = root / 'rebuild/2008-06/native-classes/CContentUpload.cpp'
error_source = root / 'rebuild/2008-06/native-classes/CContentError.cpp'
guid_source = root / 'rebuild/2008-06/native-classes/CContentGuids.cpp'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
common = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags = [x for x in common if x != '/c'] + ['/P', str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, probe)
assert code == 0, log
text = (probe / 'CContentUpload.i').read_text(errors='replace')
needle = 'operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );'
assert text.count(needle) == 1
text = text.replace(needle, '__declspec(noinline) ' + needle)
profile = probe / 'CContentUploadProfile.cpp'
profile.write_text(text)
obj = probe / 'CContentUploadProfile.obj'
compile_flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/Fo' + str(obj), str(profile)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', compile_flags, probe)
assert code == 0, log
error_obj = probe / 'CContentError.obj'
guid_obj = probe / 'CContentGuids.obj'
for path, output in [(error_source, error_obj), (guid_source, guid_obj)]:
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', common + ['/Fo' + str(output), str(path)], probe)
    assert code == 0, log
rows = []
for output, prefix, address, expected in [
    (obj, '?Upload@CContent@@', 0x4166a0, [('?validateWorkspaceSiteUrl@@', 0x41dcd0), ('?reportWorkspaceSiteError@@', 0x429330), ('?reportWorkspaceSiteError@@', 0x429360), ('?CLSID_Content@@', 0x816518), ('?post@Http@RBX@@', 0x569a40)]),
    (obj, '??0Http@RBX@@QAE@PBD', 0x409750, []),
    (obj, '??1Http@RBX@@', 0x5df620, []),
    (error_obj, '?reportWorkspaceSiteError@@', 0x429360, [('?reportWorkspaceStatus@@', 0x427c20), ('?AtlReportError@ATL@@', 0x4290b0), ('_GUID_NULL', 0x8501ec)]),
]:
    raw = output.read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', '%08x' % address)
    assert match.exact_match(target, targetrefs, body, refs), (prefix, len(body), len(target))
    start, section = definitions[name]
    table = sections[section]
    bindings = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        offset -= start
        if 0 <= offset < len(body) - 3:
            value = struct.unpack_from('<I', target, offset)[0]
            if kind == 20:
                value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            bindings.setdefault(symbols[index][0], set()).add(value)
    for key, value in expected:
        assert any(k.startswith(key) and value in values for k, values in bindings.items()), (key, bindings)
    rows.append({'address': hex(address), 'symbol': name, 'size': len(body), 'exact': True, 'bindings': {k: [hex(v) for v in sorted(values)] for k, values in bindings.items()}})
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
image = pe.OPTIONAL_HEADER.ImageBase
assert struct.unpack('<I', pe.get_data(0x80ea98 + 28 - image, 4))[0] == 0x4166a0
raw = guid_obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
for symbol, value in [('?IID_IContent@@3U_GUID@@B', 'd63f927a-1170-4239-9c1d-06e8a658f300'), ('?CLSID_Content@@3U_GUID@@B', '19821fdd-546e-4284-a925-b2c5d7cc3084')]:
    start, section = definitions[symbol]
    data = raw[sections[section][4] + start:][:16]
    assert data == uuid.UUID(value).bytes_le
    if symbol.startswith('?CLSID_Content'):
        assert data == pe.get_data(0x816518 - image, 16)
    else:
        typelib = json.loads((root / 'work/2008-06/shared-layouts/original-typelib.json').read_text())
        assert typelib['types']['IContent']['guid'] == value
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
http_donor = root / 'rebuild/2008-06/out/RbxgsApp/linked/Http.obj'
http_raw = http_donor.read_bytes()
http_sections, http_symbols, http_definitions, _ = match._coff_data_index(http_raw)
http_rows = []
for prefix, address, exact in [('?post@Http@RBX@@', 0x569a40, True), ('?httpRequest@Http@RBX@@', 0x5f9c30, False), ('?httpRequestAlternate@Http@RBX@@', 0x5f8b60, False)]:
    name, body, refs = next(x for x in match.coff_functions(http_raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', '%08x' % address)
    assert match.exact_match(target, targetrefs, body, refs) == exact
    if exact:
        start, section = http_definitions[name]
        table = http_sections[section]
        calls = {}
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', http_raw, table[5] + 10 * i)
            offset -= start
            if kind == 20 and 0 <= offset < len(body) - 3:
                calls[http_symbols[index][0]] = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        for key, value in [('?httpRequest@Http@RBX@@', 0x5f9c30), ('?httpRequestAlternate@Http@RBX@@', 0x5f8b60)]:
            assert any(k.startswith(key) and v == value for k, v in calls.items()), (key, calls)
    http_rows.append({'symbol': name, 'address': hex(address), 'candidate_size': len(body), 'original_size': len(target), 'exact': exact})
receipt = {'scope': 'Inactive Upload, exception reporter and GUID bytes match; HTTP implementation, COM map identity and live ownership remain unproven. Do not run.', 'source_sha256': sha(source), 'error_source_sha256': sha(error_source), 'guid_source_sha256': sha(guid_source), 'observer_sha256': sha(Path(__file__)), 'header_sha256': sha(root / 'rebuild/2008-06/native-headers/CContent.h'), 'object_sha256': sha(obj), 'error_object_sha256': sha(error_obj), 'guid_object_sha256': sha(guid_obj), 'methods': rows, 'clsid_original': '0x816518', 'flags': compile_flags}
receipt['http_donor'] = {'object_sha256': sha(http_donor), 'methods': http_rows, 'scope': 'post matches but both HTTP backends differ; linker selection, global mode identity and runtime remain unproven.'}
(root / 'work/2008-06/shared-layouts/content-upload-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS CContent Upload, exception reporter and COM identifiers')
