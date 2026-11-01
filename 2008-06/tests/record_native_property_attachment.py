"""Prove genuine row attachment, real container callees and SDK import bindings."""
import hashlib
import json
from pathlib import Path
import re
import struct
import subprocess
import sys
import pefile
ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match, rebuild
OUT = ROOT / 'rebuild/2008-06/out/native-layouts'
HEADERS = ROOT / 'rebuild/2008-06/native-headers'
source = Path(__file__).with_name('NativePropertyAttachment.cpp')
flags = json.loads((ROOT / 'work/2008-06/shared-layouts/property-grid-working-probe.json').read_text())['flags']
preprocess_flags = [f for f in flags if f != '/c'] + ['/P', str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', preprocess_flags, OUT)
assert code == 0, log
body = (OUT / 'NativePropertyAttachment.i').read_text(errors='replace')
profile = ('CString CXTPPropertyGridItem::GetCaption() const',
           'operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );',
           'void push_back(const _Ty& _Val)\n\t\t{\t\n\t\tif (size() < capacity())')
for needle in profile:
    assert body.count(needle) == 1, needle
    body = body.replace(needle, '__declspec(noinline) ' + needle)
translation = OUT / 'NativePropertyAttachmentProfile.cpp'
translation.write_text(body)
obj = OUT / 'NativePropertyAttachment.obj'
compile_flags = ['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD',
                 '/Fo' + str(obj), str(translation)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', compile_flags, OUT)
assert code == 0, log
raw = obj.read_bytes()
functions = match.coff_functions(raw)
sections, symbols, definitions, _ = match._coff_data_index(raw)
methods = []
callees = []
edges = []
original = pefile.PE(str(ROOT / 'work/2008-06/original-p4-reference/Roblox.exe'))
imports = {item.address: (dll.dll.lower(), item.name, item.ordinal)
           for dll in original.DIRECTORY_ENTRY_IMPORT for item in dll.imports}
mfc_def = ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/src/mfc/intel/mfc90.def'
exports = {int(ordinal): name for name, ordinal in re.findall(r'^\s*(\S+)\s+@\s*(\d+)\s+NONAME', mfc_def.read_text(), re.M)}
bindings = {'?getCategory@CPropGrid@@': 0x438630, '?GetCaption@CXTPPropertyGridItem@@': 0x437ea0,
            '?GetAt@CXTPPropertyGridItems@@': 0x712420,
            '?InsertChildItem@CXTPPropertyGridItem@@': 0x712790,
            '??A?$map@': 0x5644a0, '?push_back@?$vector@': 0x4213a0}
for address, prefix, helper in (
    ('00439810', '??$addItem@VXBoolItem', False),
    ('00439ba0', '??$addItem@V?$XItem@M', False),
    ('00439940', '??$addItem@V?$XItem@VColor3', False),
    ('00439a70', '??$addItem@V?$XItem@H', False),
    ('00437ea0', '?GetCaption@CXTPPropertyGridItem', True),
    ('004213a0', '?push_back@?$vector', True),
    ('005644a0', '??A?$map', True),
):
    name, candidate, refs = next((n,b,r) for n,b,r in functions if n.startswith(prefix))
    target, target_refs, _ = match.target('2008-06', address)
    assert match.exact_match(target, target_refs, candidate, refs), (address, name)
    (callees if helper else methods).append(dict(address=address, symbol=name, size=len(candidate), relocation_masked_match=True))
    start, section = definitions[name]
    table = sections[section]
    for index in range(table[7]):
        offset, si, kind = struct.unpack_from('<IIH', raw, table[5] + index * 10)
        offset -= start
        if not 0 <= offset <= len(candidate) - 4:
            continue
        symbol = symbols[si][0]
        for beginning, destination in bindings.items():
            if symbol.startswith(beginning):
                assert kind == 20
                actual = (int(address,16) + offset + 4 + struct.unpack_from('<i',target,offset)[0]) & 0xffffffff
                assert actual == destination, (address,symbol,hex(actual))
                edges.append(dict(caller=address, offset=offset, symbol=symbol, target=hex(destination)))
        if symbol.startswith('__imp_'):
            imported = imports[struct.unpack_from('<I', target, offset)[0]]
            dll, imported_name, ordinal = imported
            expected = symbol[len('__imp_'):]
            if dll == b'mfc90.dll':
                assert exports[ordinal] == expected, (address,expected,ordinal)
            elif imported_name is not None:
                c_name = expected[1:].split('@')[0] if expected.startswith('_') else expected
                assert imported_name.decode() == c_name, (address,c_name,imported_name)
paths = [Path(__file__), source, HEADERS / 'PropertyGridItems.h', HEADERS / 'CPropGrid.h',
         HEADERS / 'SelectionGroup.h', mfc_def]
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = dict(revision=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),
               sources={str(p.relative_to(ROOT)):sha(p) for p in paths}, compiler=21022,
               preprocess_flags=preprocess_flags, compile_flags=compile_flags, profile=list(profile),
               object_sha256=sha(obj), methods=methods, real_callee_body_proofs=callees, verified_bindings=edges,
               scope='Inactive four attachment variants. Genuine SDK sorted insertion, std::map descriptor lookup and vector registration. '
                     'No fake map/callee. Caption getter, map operator[] and vector push_back bodies also match; selected imports/calls verified. '
                     'Full editor virtual behavior, factory and game/frame integration remain open; no runtime credit.')
(ROOT / 'work/2008-06/shared-layouts/property-attachment-working-probe.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS: four real row attachment bodies, three genuine callee bodies and selected import/call bindings')
