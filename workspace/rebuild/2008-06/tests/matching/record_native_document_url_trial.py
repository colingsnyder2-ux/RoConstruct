"""Compile original document-save helper with inactive diagnostic bridge."""
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
source = root/'rebuild/2008-06/experiments/trials/NativeDocumentUrlTrial.cpp'
base = json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [f for f in base['flags'] if f != '/c' and not f.startswith('/Fo') and not f.endswith('NativeDocumentLayout.cpp')]
flags += ['/P', str(source)]
pre = out/'document-url-preprocess'
pre.mkdir(exist_ok=True)
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, pre)
assert code == 0, log
body = (pre/'NativeDocumentUrlTrial.i').read_text(errors='replace')
for needle in ('const _Elem * c_str() const', 'operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );'):
    assert body.count(needle) == 1
    body = body.replace(needle, '__declspec(noinline) ' + needle)
profile = out/'NativeDocumentUrlProfile.cpp'
profile.write_text(body)
obj = out/'NativeDocumentUrlProfile.obj'
compile_flags = ['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj),str(profile)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', compile_flags, out)
assert code == 0, log
raw = obj.read_bytes()
name, candidate, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?copyDocument@@'))
target, targetrefs, _ = match.target('2008-06','0044fe00')
assert match.exact_match(target, targetrefs, candidate, refs)
sections, symbols, definitions, _ = match._coff_data_index(raw)
start, index = definitions[name]
section = sections[index]
edges = {}
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5]+10*i)
    offset -= start
    if 0 <= offset < len(candidate)-3:
        value = struct.unpack_from('<I', target, offset)[0]
        if kind == 20:
            value = (0x44fe00 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        edges[symbols[symbol][0]] = value
for prefix, wanted in [('?getUserAppDataDirectory@FileSystem@RBX@@',0x5a7ac0),
                       ('__imp__GetShortPathNameA@12',0x802218), ('__imp_?c_str@',0x802464),
                       ('__CxxThrowException@8',0x6a158c)]:
    assert any(k.startswith(prefix) and v == wanted for k,v in edges.items()), (prefix,edges)
assert target[0xc0:0xc6] == bytes.fromhex('8b 82 94 00 00 00')
assert target[0xca:0xcd] == bytes.fromhex('8b 42 1c')
pe = pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'))
for address, value in [(0x8111ec,b'Test'), (0x817994,b'.rbxl'), (0x81797c,b'Failed to copy document')]:
    assert pe.get_string_at_rva(address-pe.OPTIONAL_HEADER.ImageBase) == value
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256':sha(source),'observer_sha256':sha(Path(__file__)),'object_sha256':sha(obj),
           'preprocess_flags':flags,'compile_flags':compile_flags,'address':'0044fe00','size':len(candidate),
           'targets':{k:hex(v) for k,v in edges.items()},
           'scope':'Inactive diagnostic bridge adds a call absent in the original. Runtime ABI, COM object and linked EH metadata remain unproven.'}
(root/'work/2008-06/shared-layouts/document-url-trial.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS document-save helper body and selected targets; bridge is diagnostic only')
