"""Verify mined filesystem source against the original Doc dependency."""
import hashlib
import json
import struct
import sys
from pathlib import Path

import pefile

root = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root/'rebuild/2008-06/out/native-layouts'
source = root/'tools/rbxgs/Client/App/roc_filesystem_nested_78e80a56ef829311.cpp'
header = root/'tools/rbxgs/Client/App/include/util/FileSystem.h'
base = json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [f for f in base['flags'] if not f.startswith('/Fo') and not f.endswith('NativeDocumentLayout.cpp')]
original = source.read_text()
def function(prefix):
    start = original.index(prefix)
    opening = original.index('{', start)
    depth = 0
    for end in range(opening, len(original)):
        if original[end] == '{': depth += 1
        elif original[end] == '}':
            depth -= 1
            if depth == 0: return original[start:end+1]
    raise ValueError(prefix)
isolated = out/'NativeFilesystemIsolated.cpp'
isolated.write_text('#include <atlpath.h>\n#include "util/FileSystem.h"\nnamespace RBX {\n' +
                    '\n'.join(function(x) for x in ['VistaAPIs::~VistaAPIs', 'HRESULT VistaAPIs::GetIntegrity',
                    'VistaAPIs::VistaAPIs', 'HRESULT VistaAPIs::SHGetKnownFolderPath',
                    'std::string FileSystem::getUserAppDataDirectory']) + '\n}\n')
obj = out/'NativeFilesystemIsolated.obj'
flags += ['/Fo'+str(obj), str(isolated)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?getUserAppDataDirectory@FileSystem@RBX@@'))
target, targetrefs, _ = match.target('2008-06', '005a7ac0')
assert match.exact_match(target, targetrefs, body, refs)
integrity_name, integrity, integrity_refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?GetIntegrity@VistaAPIs@RBX@@'))
integrity_target, integrity_targetrefs, _ = match.target('2008-06', '005a7780')
assert match.exact_match(integrity_target, integrity_targetrefs, integrity, integrity_refs)
sections, symbols, definitions, _ = match._coff_data_index(raw)
start, index = definitions[name]
section = sections[index]
edges = {}
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5]+10*i)
    offset -= start
    if 0 <= offset < len(body)-3:
        value = struct.unpack_from('<I', target, offset)[0]
        if kind == 20:
            value = (0x5a7ac0+offset+4+struct.unpack_from('<i',target,offset)[0]) & 0xffffffff
        edges[symbols[symbol][0]] = value
for prefix, wanted in [('?GetIntegrity@VistaAPIs@RBX@@',0x5a7780),
                       ('__imp__SHGetFolderPathAndSubDirA@24',0x802af4),
                       ('__imp__CreateDirectoryA@8',0x8022b4), ('__imp__LoadLibraryA@4',0x8021cc),
                       ('__imp__GetProcAddress@8',0x8021c0), ('__imp__FreeLibrary@4',0x8021a0),
                       ('?g_strmgr@ATL@@',0x97f2ec)]:
    assert any(k.startswith(prefix) and v == wanted for k,v in edges.items()), (prefix,edges)
pe = pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'))
for address, value in [(0x834224,b'Shell32.dll'), (0x83420c,b'SHGetKnownFolderPath'),
                       (0x834238,b'\\Roblox\\'), (0x834230,b'Roblox\\')]:
    assert pe.get_string_at_rva(address-pe.OPTIONAL_HEADER.ImageBase) == value
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256':sha(source), 'header_sha256':sha(header), 'observer_sha256':sha(Path(__file__)),
           'object_sha256':sha(obj), 'isolated_sha256':sha(isolated), 'flags':flags, 'address':'005a7ac0', 'size':len(body),
           'integrity':{'address':'005a7780','size':len(integrity)},
           'targets':{k:hex(v) for k,v in edges.items()},
           'scope':'Inactive trial. Directory and integrity bodies match; ATL data, exception metadata and runtime remain unproven.'}
(root/'work/2008-06/shared-layouts/filesystem-trial.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS native filesystem directory body and selected targets')
