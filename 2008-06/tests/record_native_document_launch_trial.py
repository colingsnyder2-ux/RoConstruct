"""Check native document launch handlers without activating their unmatched helper."""
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
source = root / 'rebuild/2008-06/tests/NativeDocumentLaunchTrial.cpp'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [f for f in base['flags'] if not f.startswith('/Fo') and not f.endswith('NativeDocumentLayout.cpp') and not f.startswith('/Ob')]
obj = out / 'NativeDocumentLaunchTrial.obj'
flags += ['/Ob0', '/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
image_base = pe.OPTIONAL_HEADER.ImageBase
literals = {0x8179f8: b' -script "loadfile(\'', 0x8179e0: b'/game/visit.ashx\')()"',
            0x8179d8: b'Visit', 0x817a18: b'/game/gameserver.ashx\')(0, 53640)"',
            0x817a10: b'Server', 0x817a3c: b'/game/join.ashx?UserID=0&serverPort=53640\')()"'}
for address, value in literals.items():
    assert pe.get_string_at_rva(address-image_base) == value
rows = []
for address in ('004500d0', '004501c0', '004502b0'):
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?handle_' + address[2:] + '@CRobloxDoc'))
    target, targetrefs, _ = match.target('2008-06', address)
    assert match.exact_match(target, targetrefs, body, refs), address
    start, index = definitions[name]
    section = sections[index]
    edges = {}
    for i in range(section[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
        offset -= start
        if kind == 20 and 0 <= offset < len(body)-3:
            value = (int(address, 16) + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            edges[symbols[symbol][0]] = value
    for prefix, expected in [('?applicationBaseUrl@@', 0x4060d0), ('??HATL@@', 0x44f220),
                             ('??HATL@@', 0x40e160), ('?launch@@', 0x44ff40), ('?AfxMessageBox@@', 0x6a0c50)]:
        assert any(k.startswith(prefix) and v == expected for k, v in edges.items()), (address, prefix, edges)
    if address != '004502b0':
        assert any(k.startswith('?documentUrl@@') and v == 0x44fe00 for k, v in edges.items())
    rows.append({'address': address, 'size': len(body), 'direct_calls': {k: hex(v) for k,v in edges.items()}})
helper_name, helper, helper_refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?launch@@'))
helper_target, helper_targetrefs, _ = match.target('2008-06', '0044ff40')
assert match.exact_match(helper_target, helper_targetrefs, helper, helper_refs)
start, index = definitions[helper_name]
section = sections[index]
helper_edges = {}
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
    offset -= start
    if 0 <= offset < len(helper)-3:
        value = struct.unpack_from('<I', helper_target, offset)[0]
        if kind == 20:
            value = (0x44ff40 + offset + 4 + struct.unpack_from('<i', helper_target, offset)[0]) & 0xffffffff
        helper_edges[symbols[symbol][0]] = value
for prefix, expected in [('?AfxGetModuleState@@', 0x6a0926), ('?AfxGetModuleShortFileName@@', 0x6a093e),
                         ('?AfxGetThread@@', 0x6a0e4e), ('__imp__SHGetFolderPathA@20', 0x802b00),
                         ('__imp__ShellExecuteA@24', 0x802b04), ('__CxxThrowException@8', 0x6a158c)]:
    assert any(k.startswith(prefix) and v == expected for k,v in helper_edges.items()), (prefix, helper_edges)
imports = {entry.address: entry.name for dll in pe.DIRECTORY_ENTRY_IMPORT for entry in dll.imports if entry.name}
assert imports[0x802b00] == b'SHGetFolderPathA' and imports[0x802b04] == b'ShellExecuteA'
for address, value in [(0x8179b0, b'Unable to get common document folder'),
                       (0x81799c, b'ShellExecute failed'), (0x8168ac, b'open')]:
    assert pe.get_string_at_rva(address-image_base) == value
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256': sha(source), 'header_sha256': sha(root/'rebuild/2008-06/native-headers/CRobloxDoc.h'),
           'observer_sha256': sha(Path(__file__)), 'object_sha256': sha(obj), 'flags': flags, 'methods': rows,
           'helper': {'symbol': helper_name, 'candidate_size': len(helper), 'original_size': len(helper_target),
                      'exact': True, 'targets': {k: hex(v) for k,v in helper_edges.items()}},
           'scope': 'Inactive trial. Helper and selected targets match; linked exception metadata, string helper dependencies and runtime ABI remain unproven.'}
(root / 'work/2008-06/shared-layouts/document-launch-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS three launch handlers and helper; selected targets and strings checked')
