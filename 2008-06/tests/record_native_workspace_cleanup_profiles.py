"""Compare Workspace cleanup under documented historical compiler profiles."""
import hashlib
import json
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/tests/NativeWorkspaceLayout.cpp'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
common = [x for x in base['flags'] if x not in ('/O2', '/Ob2', '/Oy', '/GF', '/c') and not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
target, targetrefs, _ = match.target('2008-06', '0046b0e0')
rows = []
for index, options in enumerate([['/O2', '/Ob2', '/Oy', '/GF'], ['/O2', '/Ob1', '/Oy', '/GF'], ['/O2', '/Ob2', '/Oy-', '/GF'], ['/O2', '/Ob1', '/Oy-', '/GF'], ['/O2', '/Ob2', '/Oy', '/GF-']]):
    obj = out / ('NativeWorkspaceCleanupProfile%d.obj' % index)
    flags = ['/c'] + common + options + ['/Fo' + str(obj), str(source)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
    assert code == 0, log
    name, body, refs = next(x for x in match.coff_functions(obj.read_bytes()) if x[0].startswith('?cleanup@CWorkspace@@'))
    rows.append({'options': options, 'size': len(body), 'exact': match.exact_match(target, targetrefs, body, refs), 'object_sha256': hashlib.sha256(obj.read_bytes()).hexdigest()})
receipt = {'scope': 'Inactive compiler profile comparison; runtime ABI and call targets not verified.', 'observer_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(), 'source_sha256': hashlib.sha256((root / 'rebuild/2008-06/native-classes/CWorkspace.cpp').read_bytes()).hexdigest(), 'address': '0046b0e0', 'original_size': len(target), 'profiles': rows}
(root / 'work/2008-06/shared-layouts/workspace-cleanup-profiles.json').write_text(json.dumps(receipt, indent=2) + '\n')
print(rows)
