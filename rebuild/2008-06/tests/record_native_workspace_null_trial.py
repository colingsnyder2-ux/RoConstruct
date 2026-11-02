"""Verify original Workspace null-command setter against the recovered profile."""
import hashlib
import json
import struct
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
base = out / 'NativeWorkspaceDefaultProfile.cpp'
source = root / 'rebuild/2008-06/tests/NativeWorkspaceNullTrial.inc'
text = base.read_text()
declaration = 'void setDefaultMouseCommand();'
assert text.count(declaration) == 1
text = text.replace(declaration, 'void setNullMouseCommand();\n    void setMouseCommand(MouseCommand*);', 1)
start = text.index('namespace RBX {\nMouseCommand* createDefaultMouseCommand(Workspace*);\nvoid Workspace::setDefaultMouseCommand()')
text = text[:start] + source.read_text()
profile = out / 'NativeWorkspaceNullProfile.cpp'
profile.write_text(text)
obj = out / 'NativeWorkspaceNullProfile.obj'
flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/Fo' + str(obj), str(profile)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?setNullMouseCommand@Workspace@RBX@@'))
target, targetrefs, _ = match.target('2008-06', '005a2730')
assert match.exact_match(target, targetrefs, body, refs), (len(body), len(target))
sections, symbols, definitions, _ = match._coff_data_index(raw)
start, section = definitions[name]
table = sections[section]
calls = {}
for i in range(table[7]):
    offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
    offset -= start
    if kind == 20 and 0 <= offset < len(body) - 3:
        calls[symbols[index][0]] = (0x5a2730 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
assert any(k.startswith('?setMouseCommand@Workspace@RBX@@') and v == 0x5a1fc0 for k, v in calls.items()), calls
receipt = {'scope': 'Inactive null-command method matches; Workspace, MouseCommand and linked target ABI remain unproven.', 'observer_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(), 'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(), 'base_sha256': hashlib.sha256(base.read_bytes()).hexdigest(), 'profile_sha256': hashlib.sha256(profile.read_bytes()).hexdigest(), 'object_sha256': hashlib.sha256(raw).hexdigest(), 'address': '005a2730', 'symbol': name, 'size': len(body), 'exact': True, 'calls': {k: hex(v) for k, v in calls.items()}, 'flags': flags}
(root / 'work/2008-06/shared-layouts/workspace-null-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native Workspace null-command setter 005a2730')
