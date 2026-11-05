"""Read-only exact/data checks of existing native archive members against a check manifest."""
import argparse
import hashlib
import json
from pathlib import Path
import sys
import time

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import libs, match
from native_check_runner import analyze_object

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('archive', type=Path)
parser.add_argument('manifest', type=Path)
parser.add_argument('--member', action='append', default=[])
args = parser.parse_args()
checks = []
for job in json.loads(args.manifest.read_text(encoding='utf-8-sig'))['jobs']:
    for check in job['checks']:
        if check not in checks:
            checks.append(check)
assert checks, 'manifest has no checks'
output = ROOT / 'work/2008-06/archive-check-runs' / str(time.time_ns())
output.mkdir(parents=True)
rows, found = [], set()
sha = lambda data: hashlib.sha256(data).hexdigest()
for name, raw in libs.archive_members(args.archive):
    if args.member and Path(name).name.lower() not in {m.lower() for m in args.member}:
        continue
    bodies = match.coff_functions(raw)
    applicable = [c for c in checks if any(n == c['symbol'] or n.startswith(c['symbol']) for n, _, _ in bodies)]
    if not applicable:
        continue
    path = output / ('%03d-' % len(rows) + Path(name).name)
    path.write_bytes(raw)
    result = analyze_object({'checks': applicable, 'ranges': [], 'layouts': []}, path)
    rows.append({'member': name, 'object_sha256': sha(raw), **result})
    found.update((c['addr'], c['symbol']) for c in applicable)
missing = [c for c in checks if (c['addr'], c['symbol']) not in found]
results = [c for row in rows for c in row['checks']]
verified = sum(c['status'] == 'exact' and not c.get('data_errors') for c in results)
receipt = output / 'receipt.json'
receipt.write_text(json.dumps({'scope': __doc__ + ' Not callee/ABI/runtime/server proof.',
    'archive': str(args.archive.resolve()), 'archive_sha256': sha(args.archive.read_bytes()),
    'manifest_sha256': sha(args.manifest.read_bytes()),
    'original_sha256': sha((ROOT / 'clients/2008-06/Roblox.exe').read_bytes()),
    'tool_sha256': sha(Path(__file__).read_bytes()), 'members': rows, 'missing_checks': missing}, indent=2) + '\n')
print(json.dumps({'verified_candidates': verified, 'candidates': len(results),
    'missing_checks': len(missing), 'receipt': str(receipt)}))
raise SystemExit(0 if not missing and verified == len(results) else 1)
