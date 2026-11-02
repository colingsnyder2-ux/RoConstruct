"""Verify inactive LDraw model/part constructor and destructor candidates."""
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
source = root/'rebuild/2008-06/tests/NativeLDrawEntitiesTrial.cpp'
header = root/'rebuild/2008-06/tests/NativeLDrawEntitiesTrial.h'
base = json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
obj = out/'NativeLDrawEntitiesTrial.obj'
flags += ['/Fo'+str(obj),str(source)]
code,log = rebuild.run(rebuild.toolchain(21022),'cl',flags,out)
assert code == 0,log
raw = obj.read_bytes()
sections,symbols,definitions,_ = match._coff_data_index(raw)
pe = pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'))
for address,wanted in [(0x81ca0c,0x46eae0),(0x81cbd4,0x46f900)]:
    assert struct.unpack('<I',pe.get_data(address-pe.OPTIONAL_HEADER.ImageBase,4))[0] == wanted
rows = []
for prefix,address in [('??0LDrawModel@',0x46f630), ('??1LDrawModel@',0x46f820),
                       ('??_GLDrawModel@',0x46f900), ('?add@LDrawModel@',0x46f920),
                       ('??0LDrawPart@',0x46ea30), ('??_GLDrawPart@',0x46eae0)]:
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
    values = sum(bindings.values(),[])
    if prefix == '??0LDrawModel@': assert '0x81cbd4' in values
    if prefix == '??0LDrawPart@': assert '0x81ca0c' in values
    if prefix == '??_GLDrawPart@': assert {'0x81ca0c','0x81ca00'} <= set(values)
    if prefix == '??_GLDrawModel@': assert '0x46f820' in values
    if prefix == '?add@LDrawModel@': assert '0x4213a0' in values
    rows.append({'address':hex(address),'symbol':name,'size':len(body),'bindings':bindings})
sha = lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256':sha(source),'header_sha256':sha(header),'observer_sha256':sha(Path(__file__)),
           'object_sha256':sha(obj),'flags':flags,'methods':rows,
           'scope':'Inactive trial; container ABI, base identity, RTTI, exception metadata and runtime remain unproven.'}
(root/'work/2008-06/shared-layouts/ldraw-entities-trial.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS six native LDraw model/part lifetime and add bodies')
