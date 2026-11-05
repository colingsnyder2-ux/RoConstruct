"""Verify inactive Doc command execution using native XTP and service types."""
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
source = root/'rebuild/2008-06/tests/NativeDocumentExecuteTrial.cpp'
base = json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if x != '/c' and not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp') and x != '/DNOMINMAX']
flags += ['/D_XTP_STATICLINK','/D_XTPLIB_NOAUTOLINK','/I'+str(root/'tools/libs/xtp-11.2.2/Source'),'/P',str(source)]
pre = out/'doc-execute-pre'
pre.mkdir(exist_ok=True)
code,log = rebuild.run(rebuild.toolchain(21022),'cl',flags,pre)
assert code == 0,log
text = (pre/'NativeDocumentExecuteTrial.i').read_text(errors='replace')
for needle in ('const _Elem * c_str() const','operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );'):
    assert text.count(needle) == 1
    text = text.replace(needle,'__declspec(noinline) '+needle)
profile = out/'NativeDocumentExecuteProfile.cpp'
profile.write_text(text)
obj = out/'NativeDocumentExecuteProfile.obj'
compile_flags = ['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj),str(profile)]
code,log = rebuild.run(rebuild.toolchain(21022),'cl',compile_flags,out)
assert code == 0,log
raw = obj.read_bytes()
name,body,refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?handle_453c30@CRobloxDoc@'))
target,targetrefs,_ = match.target('2008-06','00453c30')
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
            value = (0x453c30+offset+4+struct.unpack_from('<i',target,offset)[0]) & 0xffffffff
        bindings.setdefault(symbols[symbol][0],[]).append(hex(value))
for prefix,wanted in [('?GetEditText@CXTPControlComboBox@',0x6a9640),('?GetComboBoxPopupBar@CXTPControlComboBox@',0x6a81e0),
                      ('?singleton@StandardOut@',0x569620),('?print@StandardOut@',0x5693a0),
                      ('?isUrl@ContentProvider@',0x55bd10),('??0ContentId@',0x615440),
                      ('??$create@VContentProvider@',0x41eea0),('?getContent@ContentProvider@',0x561f20),
                      ('??$copy_impl@',0x451300),('??0Lock@DataModel@',0x411b40),
                      ('?getDataModel@CWorkspace@',0x46a940),('??$create@VScriptContext@',0x42dfd0),
                      ('?executeInNewThread@ScriptContext@',0x5b03b0),('?SetFocus@CWnd@',0x6a0a28)]:
    assert any(k.startswith(prefix) and hex(wanted) in v for k,v in bindings.items()),(prefix,bindings)
assert target[0x89:0x8f] == bytes.fromhex('8b 82 14 02 00 00')
copy_name,copy_body,copy_refs = next(x for x in match.coff_functions(raw)
    if x[0].startswith('??$copy_impl@') and len(x[1]) == 179)
copy_target,copy_targetrefs,_ = match.target('2008-06','00451300')
assert match.exact_match(copy_target,copy_targetrefs,copy_body,copy_refs)
pe = pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'))
assert struct.unpack('<I',pe.get_data(0x850b14+0x214-pe.OPTIONAL_HEADER.ImageBase,4))[0] == 0x6a6f20
sha = lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
paths = [source,Path(__file__),root/'rebuild/2008-06/tests/NativeContentProviderTrial.cpp',
         root/'rebuild/2008-06/native-headers/CRobloxDoc.h',root/'rebuild/2008-06/native-headers/CWorkspace.h',
         root/'tools/libs/xtp-11.2.2/Source/CommandBars/XTPControlComboBox.h']
receipt = {'inputs':{str(p.relative_to(root)):sha(p) for p in paths},'object_sha256':sha(obj),
           'preprocess_flags':flags,'compile_flags':compile_flags,'address':'00453c30','size':len(body),'bindings':bindings,
           'stream_copy':{'symbol':copy_name,'address':'00451300','size':len(copy_body)},
           'scope':'Inactive trial. XTP runtime vtable, provider lifetime, catch metadata and Doc ABI remain unproven.'}
(root/'work/2008-06/shared-layouts/document-execute-trial.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS native Doc command handler and selected bindings')
