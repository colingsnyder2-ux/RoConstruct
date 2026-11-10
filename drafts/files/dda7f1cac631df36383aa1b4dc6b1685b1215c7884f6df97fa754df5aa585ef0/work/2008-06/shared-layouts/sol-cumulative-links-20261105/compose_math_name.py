"""Compose reviewed member replacements; never mutate a baseline archive."""
import hashlib
import json
from pathlib import Path
import shutil
import sys

ROOT = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(ROOT))
from roc import libs, rebuild

HERE = Path(__file__).resolve().parent
sha = lambda path: hashlib.sha256(Path(path).read_bytes()).hexdigest()
content = json.loads((ROOT / 'work/2008-06/shared-layouts/sol-aggregate-content-20261105/replacement.json').read_text())
proposals = json.loads((ROOT / 'work/2008-06/shared-layouts/sol-math-name-owner-20261105/preservation.json').read_text())
archive = Path(content['replacement'])
assert sha(archive) == content['replacement_sha256']

# A removed numeric COMDAT may still have consumers elsewhere. Inspect every
# explicit input of the actual cumulative link; do not infer implicit closure.
inputs = json.loads((ROOT / 'work/2008-06/native-doc-relinks/20261105-131845-e437aaa4/inputs.json').read_text())
constant = '__real@3ee4f8b588e368f1'
constant_rows = []
for filename, expected in inputs.items():
    path = Path(filename)
    assert sha(path) == expected, filename
    if path.suffix.lower() not in ('.lib', '.obj'):
        continue
    members = libs.archive_members(path) if path.suffix.lower() == '.lib' else [(path.name, path.read_bytes())]
    for member, raw in members:
        if constant.encode() not in raw:
            continue
        external = rebuild.coff_externals(raw)
        if constant in external:
            constant_rows.append({'input': filename, 'member': member, 'defined': external[constant]})
survivors = [r for r in constant_rows if r['defined'] and r['member'] != 'Math.obj']
assert survivors, 'Removed numeric constant has no proved surviving explicit provider'

steps = []
tc = rebuild.toolchain(21022)
for index, proposal in enumerate(proposals):
    name = proposal['member']
    obj = Path(proposal['replacement'])
    assert sha(obj) == proposal['replacement_sha256']
    before_rows = list(libs.archive_members(archive))
    before = dict(before_rows)
    assert len(before) == len(before_rows), 'Repeated archive member names need explicit handling'
    assert hashlib.sha256(before[name]).hexdigest() == proposal['original_sha256']
    folder = HERE / ('member-step-%d' % index)
    folder.mkdir(exist_ok=True)
    shutil.copyfile(obj, folder / name)
    arguments = ['/nologo', '/OUT:linked.lib', str(archive), name]
    code, log = rebuild.run(tc, 'lib', arguments, folder)
    (folder / 'librarian.log').write_text(log)
    assert code == 0, log
    output = folder / 'linked.lib'
    after_rows = list(libs.archive_members(output))
    after = dict(after_rows)
    assert len(after) == len(after_rows) and before.keys() == after.keys()
    assert after[name] == obj.read_bytes()
    assert all(before[n] == after[n] for n in before if n != name)
    steps.append({'member': name, 'input_archive': str(archive), 'input_sha256': sha(archive),
                  'output_archive': str(output), 'output_sha256': sha(output),
                  'unchanged_other_members': len(before) - 1, 'arguments': arguments})
    archive = output

receipt = {'source_compiles': 0, 'steps': steps, 'replacement': str(archive),
           'replacement_sha256': sha(archive), 'constant': constant,
           'explicit_constant_symbols': constant_rows,
           'scope': 'Explicit providers and byte-preserved archive members only; implicit library, selected binding, ABI/EH/runtime remain separate.',
           'activation': False, 'server_credit': 0}
(HERE / 'composition.json').write_text(json.dumps(receipt, indent=2) + '\n')
print(json.dumps({'replacement': str(archive), 'sha256': sha(archive), 'members_replaced': len(steps), 'explicit_constant_symbols': len(constant_rows)}))
