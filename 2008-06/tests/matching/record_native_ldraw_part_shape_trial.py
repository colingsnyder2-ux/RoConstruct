"""Verify inactive native LDraw part shape writer."""
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
source = root/'rebuild/2008-06/experiments/trials/NativeLDrawPartShapeTrial.cpp'
base = json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if x != '/c' and not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags += ['/P',str(source)]
pre = out/'ldraw-shape-pre'
pre.mkdir(exist_ok=True)
code,log = rebuild.run(rebuild.toolchain(21022),'cl',flags,pre)
assert code == 0,log
text = (pre/'NativeLDrawPartShapeTrial.i').read_text(errors='replace')
for needle in ('const _Elem * c_str() const','size_type  find_first_of(const _Elem *_Ptr, size_type _Off = 0) const'):
    assert text.count(needle) == 1
    text = text.replace(needle,'__declspec(noinline) '+needle)
profile = out/'NativeLDrawPartShapeProfile.cpp'
profile.write_text(text)
obj = out/'NativeLDrawPartShapeProfile.obj'
compile_flags = ['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj),str(profile)]
code,log = rebuild.run(rebuild.toolchain(21022),'cl',compile_flags,out)
assert code == 0,log
raw = obj.read_bytes()
name,body,refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?writeShape@LDrawPart@'))
target,targetrefs,_ = match.target('2008-06','0046eb40')
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
            value = (0x46eb40+offset+4+struct.unpack_from('<i',target,offset)[0]) & 0xffffffff
        bindings.setdefault(symbols[symbol][0],[]).append(hex(value))
for prefix,wanted in [('__imp_?find_first_of@',0x802474),('__imp_?substr@',0x8023e0),
                      ('__imp_?c_str@',0x802464),('??$?6',0x44a450),('__imp_??6',0x802470)]:
    assert any(k.startswith(prefix) and hex(wanted) in v for k,v in bindings.items()),(prefix,bindings)
pe = pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'))
for address,value in [(0x81caac,b'Part Description -------------------------------------'),
                      (0x81ca90,b'part = Instance.new("Part")'),(0x81ca68,b'part.Shape = '),
                      (0x81ca54,b'part.FormFactor = '),(0x81ca14,b'part.Size = Vector3.new(')]:
    assert pe.get_string_at_rva(address-pe.OPTIONAL_HEADER.ImageBase) == value
sha = lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256':sha(source),'observer_sha256':sha(Path(__file__)),'object_sha256':sha(obj),
           'preprocess_flags':flags,'compile_flags':compile_flags,'address':'0046eb40','size':len(body),'bindings':bindings,
           'scope':'Inactive trial; element layout, linked exception metadata and runtime remain unproven.'}
(root/'work/2008-06/shared-layouts/ldraw-part-shape-trial.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS native LDraw shape writer and original bindings')
