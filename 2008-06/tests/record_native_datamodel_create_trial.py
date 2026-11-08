"""Profile DataModel creation using native shared ownership and lock types."""
import hashlib
import json
import struct
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/experiments/trials/NativeDataModelCreateTrial.cpp'
obj = out / 'NativeDataModelCreateTrial.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if x != '/c' and not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
pre = out / 'datamodel-create-preprocess'
pre.mkdir(exist_ok=True)
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/P', str(source)], pre)
assert code == 0, log
text = (pre / 'NativeDataModelCreateTrial.i').read_text(errors='replace')
profile = out / 'NativeDataModelCreateProfile.cpp'
profile.write_text(text)
compileflags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/Fo' + str(obj), str(profile)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', compileflags, out)
assert code == 0, log
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?createDataModel@DataModel@RBX@@'))
target, targetrefs, _ = match.target('2008-06', '0057c100')
assert match.exact_match(target, targetrefs, body, refs)
sections, symbols, definitions, _ = match._coff_data_index(raw)
start, section = definitions[name]
table = sections[section]
calls = {}
for i in range(table[7]):
    offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
    offset -= start
    if kind == 20 and 0 <= offset < len(body) - 3:
        calls[symbols[index][0]] = (0x57c100 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
for prefix, address in [('??$create@VDataModel@RBX@@', 0x57c080), ('??0Lock@DataModel@RBX@@', 0x411b40), ('?initializeContents@DataModel@RBX@@', 0x57a9f0), ('??1Lock@DataModel@RBX@@', 0x5773c0)]:
    assert any(k.startswith(prefix) and v == address for k, v in calls.items()), (prefix, calls)
assert bytes.fromhex('c6805902000001') in body
receipt = {'scope': 'Inactive typed DataModel creation matches; +0x259 flag name, constructors, initializeContents, ownership and runtime ABI remain unproven.', 'observer_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(), 'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(), 'profile_sha256': hashlib.sha256(profile.read_bytes()).hexdigest(), 'object_sha256': hashlib.sha256(raw).hexdigest(), 'address': '0057c100', 'symbol': name, 'size': len(body), 'exact': True, 'flag_offset': '0x259', 'calls': {k: hex(v) for k, v in calls.items()}, 'flags': compileflags}
(root / 'work/2008-06/shared-layouts/datamodel-create-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native DataModel creation 0057c100 and selected call targets')
