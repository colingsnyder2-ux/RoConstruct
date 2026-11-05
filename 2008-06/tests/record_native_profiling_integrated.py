"""Check recovered 2008 profiler constructors and deleting destructor."""
import hashlib, json, sys
from pathlib import Path
root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild
out = root / 'rebuild/2008-06/out/native-layouts/workspace-lifetime-integrated'
previous = json.loads((root / 'work/2008-06/shared-layouts/workspace-lifetime-integrated.json').read_text())
source = root / 'rebuild/2008-06/native-classes/Profiling.cpp'
header = root / 'rebuild/2008-06/native-headers/util/Profiling.h'
obj = out / 'Profiling.obj'
flags = [x for x in previous['flags'] if not x.startswith('/Fo') and not x.endswith('WorkspaceLifetime.cpp')]
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
(out / 'profiling.log').write_text(log)
if code:
    print(log)
    sys.exit(code)
rows = []
for prefix, address in [('??0Profiler@Profiling@RBX@@', '005c4340'), ('??0CodeProfiler@Profiling@RBX@@', '005c43a0'), ('??_GProfiler@Profiling@RBX@@', '005c3ed0')]:
    name, body, refs = next(x for x in match.coff_functions(obj.read_bytes()) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', address)
    rows.append({'symbol': name, 'address': address, 'size': len(body), 'original_size': len(target), 'exact': match.exact_match(target, targetrefs, body, refs)})
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'scope': 'Native profiler source byte check only; relocation targets, full ABI and runtime are unproven.', 'sources': {str(p.relative_to(root)): sha(p) for p in (source, header, Path(__file__))}, 'object_sha256': sha(obj), 'flags': flags, 'methods': rows}
(root / 'work/2008-06/shared-layouts/profiling-integrated.json').write_text(json.dumps(receipt, indent=2) + '\n')
print(rows)
if not all(row['exact'] for row in rows):
    sys.exit(1)
