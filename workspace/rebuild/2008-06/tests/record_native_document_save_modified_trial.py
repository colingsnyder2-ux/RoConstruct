"""Verify inactive Doc SaveModified using shared document and service types."""
import hashlib
import json
import struct
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root/'rebuild/2008-06/out/native-layouts'
source = root/'rebuild/2008-06/experiments/trials/NativeDocumentSaveModifiedTrial.cpp'
base = json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [f for f in base['flags'] if f != '/c' and not f.startswith('/Fo') and not f.endswith('NativeDocumentLayout.cpp')]
flags += ['/P', str(source)]
pre = out/'doc-save-mod-pre'
pre.mkdir(exist_ok=True)
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, pre)
assert code == 0, log
body = (pre/'NativeDocumentSaveModifiedTrial.i').read_text(errors='replace')
for needle in ('std::string getUploadUrl()', 'size_type  size() const'):
    assert body.count(needle) == 1
    body = body.replace(needle, '__declspec(noinline) '+needle)
profile = out/'NativeDocumentSaveModifiedProfile.cpp'
profile.write_text(body)
obj = out/'NativeDocumentSaveModifiedProfile.obj'
compile_flags = ['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj),str(profile)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', compile_flags, out)
assert code == 0, log
raw = obj.read_bytes()
name, candidate, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?SaveModified@CRobloxDoc@@'))
target, targetrefs, _ = match.target('2008-06', '00455060')
assert match.exact_match(target, targetrefs, candidate, refs)
upload_name, upload, upload_refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?getUploadUrl@Visit@RBX@@'))
upload_target, upload_targetrefs, _ = match.target('2008-06', '0044f1b0')
assert match.exact_match(upload_target, upload_targetrefs, upload, upload_refs)
sections, symbols, definitions, _ = match._coff_data_index(raw)
start, index = definitions[name]
section = sections[index]
edges = {}
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5]+10*i)
    offset -= start
    if kind == 20 and 0 <= offset < len(candidate)-3:
        value = (0x455060+offset+4+struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        edges.setdefault(symbols[symbol][0], []).append(hex(value))
for prefix, wanted in [('?getDataModel@CWorkspace@@',0x46a940), ('?getDataModel@CRobloxDoc@@',0x403040),
                       ('??0Lock@DataModel@RBX@@',0x411b40), ('??1Lock@DataModel@RBX@@',0x5773c0),
                       ('??$find@VRunService@RBX@@',0x4530f0), ('??$find@VVisit@RBX@@',0x452b40),
                       ('?setRunState@RunService@RBX@@',0x554da0), ('?getUploadUrl@Visit@RBX@@',0x44f1b0),
                       ('?SaveModified@CDocument@@',0x6a13a6), ('??0CPublishAsPlaceDialog@@',0x44f5c0),
                       ('?DoModal@CDialog@@',0x6a084e)]:
    assert any(k.startswith(prefix) and hex(wanted) in values for k,values in edges.items()), (prefix,edges)
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
paths = [source, Path(__file__), root/'rebuild/2008-06/native-headers/CRobloxDoc.h',
         root/'rebuild/2008-06/native-headers/CWorkspace.h', root/'rebuild/2008-06/native-headers/CSaveToRobloxDialog.h',
         root/'rebuild/2008-06/native-headers/v8datamodel/DataModel.h',
         root/'rebuild/2008-06/native-headers/util/RunStateOwner.h', root/'tools/rbxgs/Client/App/include/v8datamodel/Visit.h']
receipt = {'inputs':{str(p.relative_to(root)):sha(p) for p in paths}, 'object_sha256':sha(obj),
           'preprocess_flags':flags, 'compile_flags':compile_flags, 'address':'00455060', 'size':len(candidate),
           'upload_url':{'address':'0044f1b0','size':len(upload)}, 'targets':edges,
           'scope':'Inactive trial. Visit constructor/destructor and service identity, dialog ownership, linked exception metadata and runtime remain unproven.'}
(root/'work/2008-06/shared-layouts/document-save-modified-trial.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS native SaveModified and upload URL bodies; selected targets checked')
