"""Verify inactive model Lua writer with recovered polymorphic slot."""
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
source = root/'rebuild/2008-06/tests/NativeLDrawWriteTrial.cpp'
header = root/'rebuild/2008-06/tests/NativeLDrawEntitiesTrial.h'
base = json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if x != '/c' and not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags += ['/P',str(source)]
pre = out/'ldraw-write-pre'
pre.mkdir(exist_ok=True)
code,log = rebuild.run(rebuild.toolchain(21022),'cl',flags,pre)
assert code == 0,log
text = (pre/'NativeLDrawWriteTrial.i').read_text(errors='replace')
needle = 'const _Elem * c_str() const'
assert text.count(needle) == 1
profile = out/'NativeLDrawWriteProfile.cpp'
profile.write_text(text.replace(needle,'__declspec(noinline) '+needle))
obj = out/'NativeLDrawWriteProfile.obj'
compile_flags = ['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj),str(profile)]
code,log = rebuild.run(rebuild.toolchain(21022),'cl',compile_flags,out)
assert code == 0,log
raw = obj.read_bytes()
name,body,refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?writeLua@LDrawModel@'))
target,targetrefs,_ = match.target('2008-06','0046f6b0')
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
            value = (0x46f6b0+offset+4+struct.unpack_from('<i',target,offset)[0]) & 0xffffffff
        bindings.setdefault(symbols[symbol][0],[]).append(hex(value))
for prefix,wanted in [('??$?6',0x44a450), ('__imp_?c_str@',0x802464)]:
    assert any(k.startswith(prefix) and hex(wanted) in v for k,v in bindings.items()),(prefix,bindings)
assert bytes.fromhex('8b 42 04 56 8b cd ff d0') in target
pe = pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'))
assert struct.unpack('<II',pe.get_data(0x81ca0c-pe.OPTIONAL_HEADER.ImageBase,8)) == (0x46eae0,0x46f000)
sha = lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256':sha(source),'header_sha256':sha(header),'observer_sha256':sha(Path(__file__)),
           'object_sha256':sha(obj),'preprocess_flags':flags,'compile_flags':compile_flags,'address':'0046f6b0',
           'size':len(body),'bindings':bindings,
           'scope':'Inactive trial. Writer slot identity checked; part writer, RTTI, linked ABI and runtime remain unproven.'}
(root/'work/2008-06/shared-layouts/ldraw-write-trial.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS native LDraw model writer and virtual slot')
