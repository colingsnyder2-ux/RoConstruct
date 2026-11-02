"""Record native-type LDraw parser near miss without treating it as linked."""
import hashlib
import json
import struct
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[3]
sys.path.insert(0,str(root))
from roc import match,rebuild

out = root/'rebuild/2008-06/out/native-layouts'
source = root/'rebuild/2008-06/tests/NativeLDrawParseTrial.cpp'
base = json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if x != '/c' and not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags += ['/P',str(source)]
pre = out/'ldraw-parse-pre'
pre.mkdir(exist_ok=True)
code,log = rebuild.run(rebuild.toolchain(21022),'cl',flags,pre)
assert code == 0,log
text = (pre/'NativeLDrawParseTrial.i').read_text(errors='replace')
for needle in ('const _Elem * c_str() const','bool  eof() const',
               'size_type  find_first_not_of(const _Elem *_Ptr,\n\t\tsize_type _Off = 0) const'):
    assert text.count(needle) == 1
    text = text.replace(needle,'__declspec(noinline) '+needle)
profile = out/'NativeLDrawParseProfile.cpp'
profile.write_text(text)
obj = out/'NativeLDrawParseProfile.obj'
compile_flags = ['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj),str(profile)]
code,log = rebuild.run(rebuild.toolchain(21022),'cl',compile_flags,out)
assert code == 0,log
raw = obj.read_bytes()
name,body,refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?parse@LDrawParser@'))
target,targetrefs,_ = match.target('2008-06','0046f200')
exact = match.exact_match(target,targetrefs,body,refs)
assert exact
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
            value = (0x46f200+offset+4+struct.unpack_from('<i',target,offset)[0]) & 0xffffffff
        bindings.setdefault(symbols[symbol][0],[]).append(hex(value))
for prefix,wanted in [('??0LDrawModel@',0x46f630), ('??1LDrawModel@',0x46f820),
                      ('??0LDrawPart@',0x46ea30), ('?add@LDrawModel@',0x46f920),
                      ('?writeLua@LDrawModel@',0x46f6b0), ('?currentMap@',0x96ee60),
                      ('__imp_?find_first_not_of@',0x80247c)]:
    assert any(k.startswith(prefix) and hex(wanted) in v for k,v in bindings.items()),(prefix,bindings)
sha = lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
inputs = [source,Path(__file__),root/'rebuild/2008-06/tests/NativeLDrawParserTrial.h',
          root/'rebuild/2008-06/tests/NativeLDrawMapRootTrial.h',root/'rebuild/2008-06/tests/NativeLDrawEntitiesTrial.h']
receipt = {'inputs':{str(p.relative_to(root)):sha(p) for p in inputs},'object_sha256':sha(obj),
           'preprocess_flags':flags,'compile_flags':compile_flags,'address':'0046f200',
           'candidate_size':len(body),'original_size':len(target),'exact':exact,'bindings':bindings,
           'scope':'Inactive trial. Part/model constructors, destructors, allocation layout, resource ownership and runtime unproven.'}
(root/'work/2008-06/shared-layouts/ldraw-parse-trial.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS native LDraw parser body and selected targets')
