"""Relink only reviewed saved providers; no compilation or executable run."""
import hashlib
import json
from pathlib import Path
import shutil
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[4]
HERE = Path(__file__).resolve().parent
sha = lambda p: hashlib.sha256(Path(p).read_bytes()).hexdigest()
fs = ROOT / 'work/2008-06/shared-layouts/sol-filesystem-owner-20261105'
for path, expected in json.loads((fs / 'guard-inputs.json').read_text()).items():
    assert sha(path) == expected, path
replacement = json.loads((fs / 'replacement.json').read_text())
assert sha(replacement['base_archive']) == replacement['base_sha256']
assert sha(fs / 'FileSystem.obj') == replacement['object_sha256']
assert sha(fs / 'linked.lib') == replacement['private_archive_sha256']

receipts = [
    ROOT / 'work/2008-06/native-check-runs/20261105-122907-a81d3e5b/unit-000/receipt.json',
    ROOT / 'work/2008-06/native-check-runs/20261105-131546-668ff08d/unit-000/receipt.json',
    ROOT / 'work/2008-06/native-check-runs/20261105-132451-074c792f/unit-001/receipt.json',
]
axis = json.loads((ROOT / 'work/2008-06/shared-layouts/sol-axis-virtual-20261105/handoff.json').read_text())
saved = [json.loads(p.read_text()) for p in receipts]
saved += [unit['receipt'] for unit in axis['units'] if unit['unit'] in (0, 1, 2, 4, 5)]
objects = []
for receipt in saved:
    assert receipt['status'] == 'complete'
    assert sha(receipt['source']) == receipt['source_sha256']
    assert sha(receipt['object']) == receipt['object_sha256']
    for path, expected in receipt['dependencies'].items():
        assert sha(path) == expected, path
    assert receipt['checks'] and all(c['status'] == 'exact' and 'data_errors' in c and not c['data_errors'] for c in receipt['checks'])
    objects.append(receipt['object'])

command = [sys.executable, str(ROOT / 'rebuild/2008-06/tests/relink_native_document.py'),
           str(ROOT / 'work/2008-06/p6-probe-runs/20261105-130705-87b5983d'),
           '--replace-library', str(ROOT / 'work/2008-06/p6-probe-runs/20261105-130705-87b5983d/output/null-tool-owner/linked.lib'), str(fs / 'linked.lib')]
for obj in objects:
    command += ['--add', obj]
completed = subprocess.run(command, cwd=ROOT, capture_output=True, text=True, check=True)
print(completed.stdout, end='')
summary = json.loads(completed.stdout.strip().splitlines()[-1])
run = Path(summary['run'])
destination = HERE / run.name
destination.mkdir(exist_ok=True)
for name in ('command.json', 'inputs.json', 'result.json', 'link.log'):
    shutil.copyfile(run / name, destination / name)
(HERE / 'verified-provider-link.json').write_text(json.dumps({'run': str(run), 'summary': summary,
    'objects': objects, 'archive_sha256': sha(fs / 'linked.lib'), 'source_compiles': 0,
    'scope': 'Diagnostic link only. Render providers excluded; EH/import/ABI/runtime remain gated.',
    'activation': False, 'server_credit': 0}, indent=2) + '\n')
