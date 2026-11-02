"""Verify the inactive native Doc LDraw command and selected call bindings."""
import hashlib
import json
import struct
import sys
from pathlib import Path

import pefile

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root/'rebuild/2008-06/out/native-layouts'
source = root/'rebuild/2008-06/tests/NativeDocumentLDrawTrial.cpp'
base = json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if x != '/c' and not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags += ['/P',str(source)]
pre = out/'doc-ldraw-pre'
pre.mkdir(exist_ok=True)
code, log = rebuild.run(rebuild.toolchain(21022),'cl',flags,pre)
assert code == 0, log
text = (pre/'NativeDocumentLDrawTrial.i').read_text(errors='replace')
for needle in ('const _Elem * c_str() const','operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );'):
    assert text.count(needle) == 1
    text = text.replace(needle,'__declspec(noinline) '+needle)
profile = out/'NativeDocumentLDrawProfile.cpp'
profile.write_text(text)
obj = out/'NativeDocumentLDrawProfile.obj'
compile_flags = ['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj),str(profile)]
code, log = rebuild.run(rebuild.toolchain(21022),'cl',compile_flags,out)
assert code == 0, log
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?handle_454c90@CRobloxDoc@@'))
target, targetrefs, _ = match.target('2008-06','00454c90')
assert match.exact_match(target,targetrefs,body,refs)
lifetime_source = root/'rebuild/2008-06/tests/NativeLDrawParserLifetimeTrial.cpp'
lifetime_obj = out/'NativeLDrawParserLifetimeTrial.obj'
lifetime_flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
lifetime_flags += ['/Fo'+str(lifetime_obj),str(lifetime_source)]
code, log = rebuild.run(rebuild.toolchain(21022),'cl',lifetime_flags,out)
assert code == 0, log
lifetime_raw = lifetime_obj.read_bytes()
destructor_name, destructor, destructor_refs = next(x for x in match.coff_functions(lifetime_raw)
    if x[0].startswith('??1LDrawParser@LDraw2Lua@RBX@@'))
destructor_target, destructor_targetrefs, _ = match.target('2008-06','0046f100')
assert match.exact_match(destructor_target,destructor_targetrefs,destructor,destructor_refs)
assert destructor_target[2:6] == struct.pack('<I',0x81cb74)
assert destructor_target[6:9] == bytes.fromhex('83 c1 04')
assert destructor_target[11:15] == struct.pack('<I',0x802468)
constructor_source = root/'rebuild/2008-06/tests/NativeLDrawParserConstructorTrial.cpp'
constructor_obj = out/'NativeLDrawParserConstructorTrial.obj'
constructor_flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
constructor_flags += ['/Fo'+str(constructor_obj),str(constructor_source)]
code, log = rebuild.run(rebuild.toolchain(21022),'cl',constructor_flags,out)
assert code == 0, log
constructor_raw = constructor_obj.read_bytes()
constructor_name, constructor, constructor_refs = next(x for x in match.coff_functions(constructor_raw)
    if x[0].startswith('??0LDrawParser@LDraw2Lua@RBX@@'))
constructor_target, constructor_targetrefs, _ = match.target('2008-06','0046f110')
assert match.exact_match(constructor_target,constructor_targetrefs,constructor,constructor_refs)
cs, cy, cd, _ = match._coff_data_index(constructor_raw)
cs_start, cs_index = cd[constructor_name]
cs_section = cs[cs_index]
constructor_bindings = {}
for i in range(cs_section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH',constructor_raw,cs_section[5]+10*i)
    offset -= cs_start
    if 0 <= offset < len(constructor)-3:
        value = struct.unpack_from('<I',constructor_target,offset)[0]
        if kind == 20:
            value = (0x46f110+offset+4+struct.unpack_from('<i',constructor_target,offset)[0]) & 0xffffffff
        constructor_bindings[cy[symbol][0]] = value
for prefix,wanted in [('??_7LDrawParser@',0x81cb74), ('?currentMap@',0x96ee60),
                      ('?resolveMapPath@',0x55d0b0), ('??0LDraw2RobloxMapRoot@',0x46d710)]:
    assert any(k.startswith(prefix) and v == wanted for k,v in constructor_bindings.items()), (prefix,constructor_bindings)
pe = pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'))
assert pe.get_string_at_rva(0x81cb78-pe.OPTIONAL_HEADER.ImageBase) == b'fonts\\LDraw2RobloxMap.xml'
sections, symbols, definitions, _ = match._coff_data_index(raw)
start, index = definitions[name]
section = sections[index]
calls = {}
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH',raw,section[5]+10*i)
    offset -= start
    if kind == 20 and 0 <= offset < len(body)-3:
        value = (0x454c90+offset+4+struct.unpack_from('<i',target,offset)[0]) & 0xffffffff
        calls.setdefault(symbols[symbol][0],[]).append(hex(value))
for prefix, wanted in [('??0CFileDialog@@',0x6a0e72), ('?DoModal@CFileDialog@@',0x6a0e6c),
                       ('??0LDrawParser@LDraw2Lua@RBX@@',0x46f110), ('??1LDrawParser@LDraw2Lua@RBX@@',0x46f100),
                       ('?parse@LDrawParser@LDraw2Lua@RBX@@',0x46f200), ('?getDataModel@CWorkspace@@',0x46a940),
                       ('??0Lock@DataModel@RBX@@',0x411b40), ('??1Lock@DataModel@RBX@@',0x5773c0),
                       ('??$create@VScriptContext@RBX@@',0x42dfd0), ('?executeInNewThread@ScriptContext@RBX@@',0x5b0480),
                       ('?AfxMessageBox@@',0x6a0c50)]:
    assert any(k.startswith(prefix) and hex(wanted) in v for k,v in calls.items()), (prefix,calls)
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
paths = [source,Path(__file__),lifetime_source,constructor_source,root/'rebuild/2008-06/tests/NativeLDrawParserTrial.h',root/'rebuild/2008-06/tests/NativeLDrawMapRootTrial.h',root/'rebuild/2008-06/native-headers/CRobloxDoc.h',
         root/'rebuild/2008-06/native-headers/CWorkspace.h',root/'rebuild/2008-06/native-headers/script/ScriptContext.h']
receipt = {'inputs':{str(p.relative_to(root)):sha(p) for p in paths},'object_sha256':sha(obj),
           'preprocess_flags':flags,'compile_flags':compile_flags,'address':'00454c90','size':len(body),'calls':calls,
           'parser_destructor':{'address':'0046f100','size':len(destructor),'object_sha256':sha(lifetime_obj),'flags':lifetime_flags},
           'parser_constructor':{'address':'0046f110','size':len(constructor),'object_sha256':sha(constructor_obj),
                                 'flags':constructor_flags,'bindings':{k:hex(v) for k,v in constructor_bindings.items()}},
           'scope':'Inactive trial. Parser lifetime bodies and selected bindings match. Global ownership, map lifecycle, RTTI, service ownership, exception tables and runtime remain unproven.'}
(root/'work/2008-06/shared-layouts/document-ldraw-trial.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS inactive native LDraw command and selected targets')
