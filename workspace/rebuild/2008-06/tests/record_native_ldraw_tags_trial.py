"""Verify original LDraw XML tag initialization and storage bindings."""
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
source = root/'rebuild/2008-06/experiments/trials/NativeLDrawTagsTrial.cpp'
base = json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
obj = out/'NativeLDrawTagsTrial.obj'
flags += ['/Fo'+str(obj),str(source)]
code,log = rebuild.run(rebuild.toolchain(21022),'cl',flags,out)
assert code == 0,log
raw = obj.read_bytes()
sections,symbols,definitions,_ = match._coff_data_index(raw)
pe = pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'))
names = ['schema_version','color_map','color','ldraw_code','roblox_code','part_map','part','name',
         'description','ldraw_filename','mapping_fidelity','roblox_part','shape','form_factor','size_vect3','y_offset']
rows = []
for i,tag in enumerate(names):
    name,body,refs = next(x for x in match.coff_functions(raw) if x[0].startswith('??__Etag_'+tag+'@@'))
    address = 0x7efb60+i*0x20
    target,targetrefs,_ = match.target('2008-06',f'{address:08x}')
    assert match.exact_match(target,targetrefs,body,refs),tag
    start,index = definitions[name]
    section = sections[index]
    values = {}
    for j in range(section[7]):
        offset,symbol,kind = struct.unpack_from('<IIH',raw,section[5]+10*j)
        offset -= start
        if 0 <= offset < len(body)-3:
            value = struct.unpack_from('<I',target,offset)[0]
            if kind == 20:
                value = (address+offset+4+struct.unpack_from('<i',target,offset)[0]) & 0xffffffff
            values[symbols[symbol][0]] = value
    assert any(k.startswith('?declare@Name@RBX@@') and v == 0x553f90 for k,v in values.items())
    assert any(k.startswith('?tag_'+tag+'@@') and v == 0x96ee1c+i*4 for k,v in values.items())
    literal = next(v for k,v in values.items() if k.startswith('??_C@'))
    assert pe.get_string_at_rva(literal-pe.OPTIONAL_HEADER.ImageBase) == tag.encode('ascii')
    rows.append({'tag':tag,'address':hex(address),'storage':hex(0x96ee1c+i*4),'literal':hex(literal)})
sha = lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256':sha(source),'observer_sha256':sha(Path(__file__)),'object_sha256':sha(obj),
           'flags':flags,'tags':rows,'scope':'Inactive trial; global ordering, name registry ABI and runtime ownership remain unproven.'}
(root/'work/2008-06/shared-layouts/ldraw-tags-trial.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS sixteen native LDraw XML tag initializers and bindings')
