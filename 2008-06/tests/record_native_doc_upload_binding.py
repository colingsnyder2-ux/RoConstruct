"""Verify SaveModified binds the original native upload dialog."""
import hashlib
import json
import os
from pathlib import Path
import struct
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match

out = ROOT/'work/2008-06/doc-upload-binding'
out.mkdir(parents=True, exist_ok=True)
env = dict(os.environ, NATIVE_CHECK_OUT=str(out))
checks = [('native-classes/CRobloxDoc.cpp', '00455060=?SaveModified@CRobloxDoc@@'), ('native-classes/CUploadPlaceDialog.cpp', '0044f5c0=??0CUploadPlaceDialog@@')]
for source, check in checks:
    proc = subprocess.run([sys.executable, str(ROOT/'rebuild/2008-06/tests/check_native_class.py'), source, check], cwd=ROOT, env=env, capture_output=True, text=True, check=True)
    assert '1/1 exact' in proc.stdout, proc.stdout
obj = out/'CheckCRobloxDoc.obj'
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
name = next(n for n in definitions if n.startswith('?SaveModified@CRobloxDoc@@'))
start, section = definitions[name]
table = sections[section]
target, _, _ = match.target('2008-06', '00455060')
expected = {'??0CUploadPlaceDialog@@': 0x44f5c0, '??1CSaveToRobloxDialog@@': 0x45fe20, '?DoModal@CDialog@@': 0x6a084e, '??$create@VRunService@RBX@@@ServiceProvider': 0x4530f0}
found = {}
counts = {}
for i in range(table[7]):
    offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10*i)
    offset -= start
    symbol = symbols[index][0]
    prefix = next((x for x in expected if symbol.startswith(x)), None)
    if prefix and kind == 20 and 0 <= offset <= len(target)-4:
        address = (0x455060 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        assert address == expected[prefix] and struct.unpack_from('<I', next(b for n,b,r in match.coff_functions(raw) if n == name), offset)[0] == 0
        found[prefix] = hex(address)
        counts[prefix] = counts.get(prefix, 0) + 1
assert set(found) == set(expected), found
assert counts['??$create@VRunService@RBX@@@ServiceProvider'] == 3, counts
assert not any(symbols[struct.unpack_from('<IIH', raw, table[5]+10*i)[1]][0].startswith('??0CPublishAsPlaceDialog@@') for i in range(table[7]))
eh = out/'save-modified-eh.json'
subprocess.run([sys.executable, str(ROOT/'rebuild/2008-06/tests/audit_native_eh_graph.py'), str(obj), '00455060', name, '--output', str(eh)], cwd=ROOT, check=True)
paths = ['rebuild/2008-06/native-classes/CRobloxDoc.cpp', 'rebuild/2008-06/native-classes/CUploadPlaceDialog.cpp', 'rebuild/2008-06/native-headers/CUploadPlaceDialog.h', 'rebuild/2008-06/p6/build_client.py', 'rebuild/2008-06/tests/record_native_doc_upload_binding.py']
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
result = {'scope': 'Local Doc and upload constructor code, selected call identities and Doc local EH; no linked selection, ABI or runtime proof.', 'original_targets': found, 'inputs': {p:sha(ROOT/p) for p in paths}, 'object_sha256': sha(obj), 'upload_object_sha256':sha(out/'CheckCUploadPlaceDialog.obj'), 'eh_sha256':sha(eh)}
(out/'result.json').write_text(json.dumps(result, indent=2)+'\n', encoding='utf-8')
print('PASS native SaveModified upload owner, code, call bindings and local EH')
