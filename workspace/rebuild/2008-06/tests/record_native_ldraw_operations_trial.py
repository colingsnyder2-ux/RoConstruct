"""Verify recovered native LDraw map operations and element lifetimes."""
import hashlib
import json
import struct
import sys
from pathlib import Path

import pefile

root = Path(__file__).resolve().parents[3]
sys.path.insert(0,str(root))
from roc import match,rebuild

out = root/'rebuild/2008-06/out/native-layouts'
source = root/'rebuild/2008-06/experiments/trials/NativeLDrawMapOperationsTrial.cpp'
header = root/'rebuild/2008-06/tests/NativeLDrawMapRootTrial.h'
base = json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
obj = out/'NativeLDrawMapOperationsTrial.obj'
flags += ['/Fo'+str(obj),str(source)]
code,log = rebuild.run(rebuild.toolchain(21022),'cl',flags,out)
assert code == 0,log
raw = obj.read_bytes()
sections,symbols,definitions,_ = match._coff_data_index(raw)
pe = pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'))
assert struct.unpack('<I',pe.get_data(0x81c8b8-pe.OPTIONAL_HEADER.ImageBase,4))[0] == 0x46cae0
assert struct.unpack('<I',pe.get_data(0x81c9f8-pe.OPTIONAL_HEADER.ImageBase,4))[0] == 0x46e8c0
rows = []
for prefix,address in [('??0LDraw2RobloxColorMap@',0x46cac0), ('??0NativeRobloxPart@',0x46e970),
                       ('??0LDraw2RobloxPartMap@',0x46e6b0), ('?addPart@LDraw2RobloxPartMap@',0x46e960),
                       ('?findColor@LDraw2RobloxMapRoot@',0x46d010), ('??1LDraw2RobloxPartMap@',0x46e790),
                       ('??_GLDraw2RobloxColorMap@',0x46cae0), ('??_GLDraw2RobloxPartMap@',0x46e8c0),
                       ('?getFilename@LDraw2RobloxPartMap@',0x46cb00), ('?findPart@LDraw2RobloxMapRoot@',0x46d0a0),
                       ('?addPartMap@LDraw2RobloxMapRoot@',0x46d480),
                       ('?findPartCaseInsensitive@LDraw2RobloxMapRoot@',0x46d110),
                       ('?getPart@LDraw2RobloxPartMap@',0x46e370), ('?mapColor@LDraw2RobloxMapRoot@',0x46d080),
                       ('?readFidelity@LDraw2RobloxMapRoot@',0x46cb80), ('?readShape@LDraw2RobloxMapRoot@',0x46cc80),
                       ('?readFormFactor@LDraw2RobloxMapRoot@',0x46cde0)]:
    name,body,refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target,targetrefs,_ = match.target('2008-06',f'{address:08x}')
    assert match.exact_match(target,targetrefs,body,refs),prefix
    start,index = definitions[name]
    section = sections[index]
    bindings = {}
    for i in range(section[7]):
        offset,symbol,kind = struct.unpack_from('<IIH',raw,section[5]+10*i)
        offset -= start
        if 0 <= offset < len(body)-3:
            value = struct.unpack_from('<I',target,offset)[0]
            if kind == 20:
                value = (address+offset+4+struct.unpack_from('<i',target,offset)[0]) & 0xffffffff
            bindings.setdefault(symbols[symbol][0],[]).append(hex(value))
    if prefix == '??0LDraw2RobloxColorMap@': assert '0x81c8b8' in sum(bindings.values(),[])
    if prefix == '??0LDraw2RobloxPartMap@': assert '0x81c9f8' in sum(bindings.values(),[])
    if prefix == '??_GLDraw2RobloxPartMap@': assert '0x46e790' in sum(bindings.values(),[])
    if prefix == '?addPartMap@LDraw2RobloxMapRoot@':
        targets = sum(bindings.values(),[])
        assert {'0x46cb00','0x46cfa0','0x46d0a0','0x671910'} <= set(targets), targets
    if prefix == '?findPartCaseInsensitive@LDraw2RobloxMapRoot@':
        assert {'0x46cfa0','0x46d0a0'} <= set(sum(bindings.values(),[]))
    if prefix == '?getPart@LDraw2RobloxPartMap@': assert '0x46e280' in sum(bindings.values(),[])
    if prefix == '?mapColor@LDraw2RobloxMapRoot@': assert '0x46d010' in sum(bindings.values(),[])
    if prefix.startswith(('?readFidelity@','?readShape@','?readFormFactor@')):
        assert any(k.startswith('?stringCompareNoCase@@') and '0x46f9f0' in v for k,v in bindings.items())
    rows.append({'address':hex(address),'symbol':name,'size':len(body),'bindings':bindings})
sha = lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256':sha(source),'header_sha256':sha(header),'observer_sha256':sha(Path(__file__)),
           'object_sha256':sha(obj),'flags':flags,'methods':rows,
           'scope':'Inactive trial. RTTI, template identities, copy semantics, linked exception metadata and runtime remain unproven.'}
(root/'work/2008-06/shared-layouts/ldraw-operations-trial.json').write_text(json.dumps(receipt,indent=2)+'\n')
for address,value in [(0x81c8d0,b'exact'),(0x81c8c8,b'close'),(0x81c8e4,b'ball'),
                      (0x812bb8,b'block'),(0x81c8d8,b'cylinder'),(0x81c8f4,b'symmetric'),(0x81c8ec,b'brick')]:
    assert pe.get_string_at_rva(address-pe.OPTIONAL_HEADER.ImageBase) == value
print('PASS seventeen native LDraw map operations and lifetime bodies')
