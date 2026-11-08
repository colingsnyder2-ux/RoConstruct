"""Verify inactive native LDraw transform writer and numeric constants."""
import hashlib
import json
import struct
import sys
from pathlib import Path

import pefile

root = Path(__file__).resolve().parents[4]
sys.path.insert(0,str(root))
from roc import match,rebuild

out = root/'rebuild/2008-06/out/native-layouts'
source = root/'rebuild/2008-06/experiments/trials/NativeLDrawPartTransformTrial.cpp'
base = json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if x != '/c' and not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags += ['/P',str(source)]
pre = out/'ldraw-transform-pre'
pre.mkdir(exist_ok=True)
code,log = rebuild.run(rebuild.toolchain(21022),'cl',flags,pre)
assert code == 0,log
text = (pre/'NativeLDrawPartTransformTrial.i').read_text(errors='replace')
needle = 'const _Elem * c_str() const'
assert text.count(needle) == 1
profile = out/'NativeLDrawPartTransformProfile.cpp'
profile.write_text(text.replace(needle,'__declspec(noinline) '+needle))
obj = out/'NativeLDrawPartTransformProfile.obj'
compile_flags = ['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj),str(profile)]
code,log = rebuild.run(rebuild.toolchain(21022),'cl',compile_flags,out)
assert code == 0,log
raw = obj.read_bytes()
name,body,refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?writeTransform@LDrawPart@'))
target,targetrefs,_ = match.target('2008-06','0046ed40')
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
            value = (0x46ed40+offset+4+struct.unpack_from('<i',target,offset)[0]) & 0xffffffff
        bindings.setdefault(symbols[symbol][0],[]).append(hex(value))
for prefix,wanted in [('__imp_?c_str@',0x802464),('__imp__atof',0x8027fc),
                      ('??$?6',0x44a450),('__imp_??6',0x802478),
                      ('__real@3fa999999999999a',0x81cb38),('__real@bfa999999999999a',0x81cb30)]:
    assert any(k.startswith(prefix) and hex(wanted) in v for k,v in bindings.items()),(prefix,bindings)
pe = pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'))
for address,value in [(0x81cb38,0.05),(0x81cb30,-0.05)]:
    assert struct.unpack('<d',pe.get_data(address-pe.OPTIONAL_HEADER.ImageBase,8))[0] == value
for address,value in [(0x81cb0c,b'part.CFrame = CFrame.new('),(0x81cb28,b','),(0x812e5c,b')'),(0x81cbcc,b'\n')]:
    assert pe.get_string_at_rva(address-pe.OPTIONAL_HEADER.ImageBase) == value
sha = lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256':sha(source),'observer_sha256':sha(Path(__file__)),'object_sha256':sha(obj),
           'header_sha256':sha(root/'rebuild/2008-06/tests/NativeLDrawEntitiesTrial.h'),
           'preprocess_flags':flags,'compile_flags':compile_flags,'address':'0046ed40','size':len(body),'bindings':bindings,
           'scope':'Inactive trial; part layout, linked exception metadata and runtime remain unproven.'}
(root/'work/2008-06/shared-layouts/ldraw-part-transform-trial.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS native LDraw transform writer, constants and bindings')
