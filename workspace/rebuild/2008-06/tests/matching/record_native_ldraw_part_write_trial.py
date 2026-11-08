"""Verify inactive polymorphic LDraw part writer and selected calls."""
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
source = root/'rebuild/2008-06/experiments/trials/NativeLDrawPartWriteTrial.cpp'
headers = [root/'rebuild/2008-06/tests/NativeLDrawEntitiesTrial.h',root/'rebuild/2008-06/tests/NativeLDrawMapRootTrial.h']
base = json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
obj = out/'NativeLDrawPartWriteTrial.obj'
flags += ['/Fo'+str(obj),str(source)]
code,log = rebuild.run(rebuild.toolchain(21022),'cl',flags,out)
assert code == 0,log
raw = obj.read_bytes()
name,body,refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?writeLua@LDrawPart@'))
target,targetrefs,_ = match.target('2008-06','0046f000')
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
            value = (0x46f000+offset+4+struct.unpack_from('<i',target,offset)[0]) & 0xffffffff
        bindings.setdefault(symbols[symbol][0],[]).append(hex(value))
for prefix,wanted in [('?findPartCaseInsensitive@',0x46d110),('?getPart@',0x46e370),
                      ('?writeShape@',0x46eb40),('?writeColor@',0x46ecf0),
                      ('?writeTransform@',0x46ed40),('?writeParent@',0x46ef70),('??$?6',0x44a450)]:
    assert any(k.startswith(prefix) and hex(wanted) in v for k,v in bindings.items()),(prefix,bindings)
pe = pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'))
assert struct.unpack('<II',pe.get_data(0x81ca0c-pe.OPTIONAL_HEADER.ImageBase,8)) == (0x46eae0,0x46f000)
sha = lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256':sha(source),'headers':{str(p.relative_to(root)):sha(p) for p in headers},
           'observer_sha256':sha(Path(__file__)),'object_sha256':sha(obj),'flags':flags,
           'address':'0046f000','size':len(body),'bindings':bindings,
           'scope':'Inactive trial. Writer helpers, RTTI, resource ownership and runtime remain unproven.'}
(root/'work/2008-06/shared-layouts/ldraw-part-write-trial.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS native LDraw part virtual writer and selected bindings')
