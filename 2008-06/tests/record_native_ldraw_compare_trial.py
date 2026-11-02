"""Verify original LDraw case-insensitive comparison with native STL types."""
import hashlib
import json
import struct
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[3]
sys.path.insert(0,str(root))
from roc import match,rebuild

out = root/'rebuild/2008-06/out/native-layouts'
source = root/'rebuild/2008-06/tests/NativeLDrawCompareTrial.cpp'
base = json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if x != '/c' and not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags += ['/P',str(source)]
pre = out/'ldraw-compare-pre'
pre.mkdir(exist_ok=True)
code,log = rebuild.run(rebuild.toolchain(21022),'cl',flags,pre)
assert code == 0,log
text = (pre/'NativeLDrawCompareTrial.i').read_text(errors='replace')
for needle in ('_Elem * _Myptr()\n','const _Elem * _Myptr() const\n','size_type  size() const'):
    assert text.count(needle) == 1
    text = text.replace(needle,'__declspec(noinline) '+needle)
profile = out/'NativeLDrawCompareProfile.cpp'
profile.write_text(text)
obj = out/'NativeLDrawCompareProfile.obj'
compile_flags = ['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj),str(profile)]
code,log = rebuild.run(rebuild.toolchain(21022),'cl',compile_flags,out)
assert code == 0,log
raw = obj.read_bytes()
name,body,refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?stringCompareNoCase@@'))
target,targetrefs,_ = match.target('2008-06','0046f9f0')
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
            value = (0x46f9f0+offset+4+struct.unpack_from('<i',target,offset)[0]) & 0xffffffff
        bindings[symbols[symbol][0]] = value
for prefix,wanted in [('__imp_?begin@?$basic_string@',0x802494), ('__imp_?end@?$basic_string@',0x802490),
                      ('__imp_?_Myptr@?$basic_string@',0x802358), ('__imp_?size@?$basic_string@',0x8023f4),
                      ('__imp__toupper',0x8027f8), ('__imp___invalid_parameter_noinfo',0x802890)]:
    assert any(k.startswith(prefix) and v == wanted for k,v in bindings.items()), (prefix,bindings)
sha = lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256':sha(source),'observer_sha256':sha(Path(__file__)),'object_sha256':sha(obj),
           'flags':flags,'compile_flags':compile_flags,'address':'0046f9f0','size':len(body),
           'bindings':{k:hex(v) for k,v in bindings.items()},
           'scope':'Inactive compiler profile; STL ABI and runtime still require end-to-end proof.'}
(root/'work/2008-06/shared-layouts/ldraw-compare-trial.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS native LDraw case-insensitive comparator and STL imports')
