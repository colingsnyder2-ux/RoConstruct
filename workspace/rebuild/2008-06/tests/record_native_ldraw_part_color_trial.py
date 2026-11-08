"""Verify inactive native LDraw color Lua writer."""
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
source = root/'rebuild/2008-06/experiments/trials/NativeLDrawPartColorTrial.cpp'
base = json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
obj = out/'NativeLDrawPartColorTrial.obj'
flags += ['/Fo'+str(obj),str(source)]
code,log = rebuild.run(rebuild.toolchain(21022),'cl',flags,out)
assert code == 0,log
raw = obj.read_bytes()
name,body,refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?writeColor@LDrawPart@'))
target,targetrefs,_ = match.target('2008-06','0046ecf0')
assert match.exact_match(target,targetrefs,body,refs)
sections,symbols,definitions,_ = match._coff_data_index(raw)
start,index = definitions[name]
section = sections[index]
bindings = {}
for i in range(section[7]):
    offset,symbol,kind = struct.unpack_from('<IIH',raw,section[5]+10*i)
    offset -= start
    if 0 <= offset < len(body)-3:
        value = struct.unpack_from('<I',target,offset)[0]
        if kind == 20:
            value = (0x46ecf0+offset+4+struct.unpack_from('<i',target,offset)[0]) & 0xffffffff
        bindings.setdefault(symbols[symbol][0],[]).append(hex(value))
for prefix,wanted in [('?mapColor@',0x46d080),('??$?6',0x44a450),('__imp_??6',0x802470)]:
    assert any(k.startswith(prefix) and hex(wanted) in v for k,v in bindings.items()),(prefix,bindings)
pe = pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'))
for address,value in [(0x81cae4,b'part.BrickColor = BrickColor.new( '),(0x81cb08,b' )'),(0x81cbcc,b'\n')]:
    assert pe.get_string_at_rva(address-pe.OPTIONAL_HEADER.ImageBase) == value
sha = lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256':sha(source),'observer_sha256':sha(Path(__file__)),'object_sha256':sha(obj),
           'flags':flags,'address':'0046ecf0','size':len(body),'bindings':bindings,
           'scope':'Inactive trial; map ownership, linked ABI and runtime remain unproven.'}
(root/'work/2008-06/shared-layouts/ldraw-part-color-trial.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS native LDraw color writer and original literals')
