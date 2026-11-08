"""Verify inactive LDraw map root destructor and vtable target."""
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
source = root/'rebuild/2008-06/experiments/trials/NativeLDrawMapRootLifetimeTrial.cpp'
header = root/'rebuild/2008-06/tests/NativeLDrawMapRootTrial.h'
base = json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
obj = out/'NativeLDrawMapRootLifetimeTrial.obj'
flags += ['/Fo'+str(obj),str(source)]
code,log = rebuild.run(rebuild.toolchain(21022),'cl',flags,out)
assert code == 0,log
raw = obj.read_bytes()
name,body,refs = next(x for x in match.coff_functions(raw) if x[0].startswith('??1LDraw2RobloxMapRoot@'))
target,targetrefs,_ = match.target('2008-06','0046d590')
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
            value = (0x46d590+offset+4+struct.unpack_from('<i',target,offset)[0]) & 0xffffffff
        bindings.setdefault(symbols[symbol][0],[]).append(hex(value))
for prefix,wanted in [('??_7LDraw2RobloxMapRoot@',0x81c904), ('?_Inc@const_iterator@',0x68dfa0),
                      ('?_Inc@const_iterator@',0x68d1a0), ('??1?$_Tree@',0x46b070),
                      ('??1?$_Tree@',0x553d80), ('__imp_??1?$basic_string@',0x802468)]:
    assert any(k.startswith(prefix) and hex(wanted) in values for k,values in bindings.items()), (prefix,bindings)
pe = pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'))
assert struct.unpack('<I',pe.get_data(0x81c904-pe.OPTIONAL_HEADER.ImageBase,4))[0] == 0x46d6f0
thunk,_,_ = match.target('2008-06','0046d6f0')
assert 0x46d6f0+4+4+struct.unpack_from('<i',thunk,4)[0] == 0x46d590
constructor_source = root/'rebuild/2008-06/experiments/trials/NativeLDrawMapRootConstructorTrial.cpp'
constructor_obj = out/'NativeLDrawMapRootConstructorTrial.obj'
constructor_flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
constructor_flags += ['/Fo'+str(constructor_obj),str(constructor_source)]
code,log = rebuild.run(rebuild.toolchain(21022),'cl',constructor_flags,out)
assert code == 0,log
raw = constructor_obj.read_bytes()
name,constructor,refs = next(x for x in match.coff_functions(raw) if x[0].startswith('??0LDraw2RobloxMapRoot@'))
constructor_target,constructor_refs,_ = match.target('2008-06','0046d710')
assert match.exact_match(constructor_target,constructor_refs,constructor,refs)
sections,symbols,definitions,_ = match._coff_data_index(raw)
start,index = definitions[name]
section = sections[index]
constructor_bindings = {}
for i in range(section[7]):
    offset,symbol,kind = struct.unpack_from('<IIH',raw,section[5]+10*i)
    offset -= start
    if 0 <= offset < len(constructor)-3:
        value = struct.unpack_from('<I',constructor_target,offset)[0]
        if kind == 20:
            value = (0x46d710+offset+4+struct.unpack_from('<i',constructor_target,offset)[0]) & 0xffffffff
        constructor_bindings.setdefault(symbols[symbol][0],[]).append(hex(value))
for prefix,wanted in [('??_7LDraw2RobloxMapRoot@',0x81c904), ('??0TextXmlParser@@',0x415350),
                      ('?parse@TextXmlParser@@',0x58f6c0), ('?findFirstChildByTag@XmlElement@@',0x57c230),
                      ('?getValue@XmlNameValuePair@@',0x57c210), ('??0LDraw2RobloxColorMap@',0x46cac0),
                      ('?findColor@LDraw2RobloxMapRoot@',0x46d010), ('??0LDraw2RobloxPartMap@',0x46e6b0),
                      ('??0NativeRobloxPart@',0x46e970), ('?addPartMap@LDraw2RobloxMapRoot@',0x46d480),
                      ('??1TextXmlParser@@',0x4147c0)]:
    assert any(k.startswith(prefix) and hex(wanted) in values for k,values in constructor_bindings.items()), (prefix,constructor_bindings)
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256':sha(source),'header_sha256':sha(header),'observer_sha256':sha(Path(__file__)),
           'object_sha256':sha(obj),'flags':flags,'address':'0046d590','size':len(body),'bindings':bindings,
           'constructor':{'address':'0046d710','size':len(constructor),'source_sha256':sha(constructor_source),
                          'object_sha256':sha(constructor_obj),'flags':constructor_flags,'bindings':constructor_bindings},
           'scope':'Inactive candidate; element layouts, XML tag identity, RTTI ownership, exception tables and runtime remain unproven.'}
(root/'work/2008-06/shared-layouts/ldraw-map-lifetime-trial.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS LDraw map root constructor, destructor, vtable and selected targets')
