"""Test both Workspace lifetime methods against the same recovered class profile."""
import hashlib
import json
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
source = out / 'NativeWorkspaceDefaultCtorProfile.cpp'
text = source.read_text()
assert text.rstrip().endswith('}')
text = text.rstrip()[:-1] + 'Workspace::~Workspace() {}\n}\n'
profile = out / 'NativeWorkspaceSharedLifetime.cpp'
profile.write_text(text)
obj = out / 'NativeWorkspaceSharedLifetime.obj'
flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/Fo' + str(obj), str(profile)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
functions = match.coff_functions(obj.read_bytes())
rows = []
for prefix, address in [('??0Workspace@RBX@@', '005a4d90'), ('??1Workspace@RBX@@', '005a28c0')]:
    name, body, refs = next(x for x in functions if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', address)
    rows.append({'symbol': name, 'address': address, 'size': len(body), 'original_size': len(target), 'exact': match.exact_match(target, targetrefs, body, refs)})
assert rows[0]['exact'] and not rows[1]['exact']
assert rows[1]['size'] == 755 and rows[1]['original_size'] == 878
receipt = {'scope': 'Inactive mismatch evidence. Constructor matches but destructor differs; full base types, vtables and runtime ownership remain unproven.', 'observer_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(), 'input_profile_sha256': hashlib.sha256(source.read_bytes()).hexdigest(), 'profile_sha256': hashlib.sha256(profile.read_bytes()).hexdigest(), 'object_sha256': hashlib.sha256(obj.read_bytes()).hexdigest(), 'methods': rows, 'flags': flags}
(root / 'work/2008-06/shared-layouts/workspace-shared-lifetime-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print(rows)
