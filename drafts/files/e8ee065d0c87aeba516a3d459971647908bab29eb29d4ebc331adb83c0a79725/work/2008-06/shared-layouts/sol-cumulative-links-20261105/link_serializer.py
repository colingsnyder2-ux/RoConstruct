"""Compose one guarded loader member and supply the exact native loader object."""
import json
from pathlib import Path
import shutil
import time
import uuid
from guarded_replay import ROOT, HERE, digest, write, replay, rebuild
from link_irenderable import members

old = ROOT / 'work/2008-06/shared-layouts/sol-clone-owner-20261105/linked.lib'
audit = ROOT / 'work/2008-06/shared-layouts/sol-serializer-audit-20261105'
owner = ROOT / 'work/2008-06/shared-layouts/sol-serializer-owner-20261105'
summary = json.loads((audit / 'summary.json').read_text())
assert digest(old) == summary['archive_sha256'] == '3a0490de7239801417a5ae524ed5e54fd5301cf77a7b5cd88d170e8431a1fcbe'
assert summary['retained_changed'] == summary['drift'] == summary['errors'] == []
assert len(summary['consumed_without_strict_alternate']) == 1
assert summary['consumed_without_strict_alternate'][0].startswith('?loadInstances@SerializerV2@@')
command = json.loads((owner / 'actual-command.json').read_text())
assert digest(command['source']) == command['source_sha256']
for path, expected in command['dependencies'].items():
    assert digest(path) == expected, path
candidate = owner / 'unit-000/candidate.obj'
assert digest(candidate) == summary['candidate_sha256'] == '410f7416ff2ab4dd10ca8c608affa2637efcfbad04cee7ac8c7e160f6e0ec58f'
receipt = json.loads((owner / 'unit-000/receipt.json').read_text())
assert receipt['status'] == 'complete' and digest(receipt['object']) == receipt['object_sha256']
assert digest(receipt['source']) == receipt['source_sha256']
for path, expected in receipt['dependencies'].items():
    assert digest(path) == expected, path
native_run = ROOT / 'work/2008-06/native-check-runs/20261105-151943-cff659c3'
native = json.loads((native_run / 'unit-000/receipt.json').read_text())
assert native['status'] == 'complete'
assert digest(native['object']) == native['object_sha256'] == 'e5508d0afe443b7195efdce28703b97e7c634e15d85a84a97b4ba28d5fc88767'
assert digest(native['source']) == native['source_sha256']
for path, expected in native['dependencies'].items():
    assert digest(path) == expected, path
checks = json.loads((native_run / 'analysis-21bfbed1.json').read_text())[0]
assert not checks['changed_inputs'] and len(checks['checks']) == 1
check = checks['checks'][0]
assert check['status'] == 'exact' and check['target_size'] == check['object_size'] == 550
assert not check['data_errors'] and len(check['data_matches']) == 3
direct = [row for row in check['call_identity']['calls'] if row['status'] == 'verified_binding']
assert len(direct) == 17 and not check['call_identity']['passed']
profile = json.loads((HERE / 'serializer-inline-cstr-context.json').read_text())
for path, expected in ((profile['materialized_header'], profile['materialized_sha256']),
                       (profile['uploadable_template'], profile['template_sha256']),
                       (profile['private_instance_header'], profile['private_instance_sha256'])):
    assert digest(path) == expected
stage = HERE / ('serializer-member-' + time.strftime('%H%M%S') + '-' + uuid.uuid4().hex[:6])
stage.mkdir()
shutil.copyfile(candidate, stage / 'glue_serializer.obj')
new = stage / 'linked.lib'
tc = rebuild.toolchain(21022)
arguments = ['/nologo', '/OUT:' + str(new), str(old), 'glue_serializer.obj']
code, log = rebuild.run(tc, 'lib', arguments, stage)
(stage / 'librarian.log').write_text(log + '\n')
assert code == 0 and new.is_file(), log
before, after = members(old), members(new)
assert sum(before.values()) == sum(after.values()) == 267
assert before[summary['old_member_sha256']] == after[summary['candidate_sha256']] == 1
before.subtract([summary['old_member_sha256']])
after.subtract([summary['candidate_sha256']])
assert +before == +after and sum((+before).values()) == 266
write(HERE / 'serializer-composition.json', {
    'base_archive': str(old), 'base_sha256': digest(old),
    'new_archive': str(new), 'new_sha256': digest(new),
    'replaced_member': 'glue_serializer.obj', 'old_member_sha256': summary['old_member_sha256'],
    'new_member_sha256': digest(candidate), 'other_members_identical': 266,
    'native_object': native['object'], 'native_object_sha256': native['object_sha256'],
    'profile': profile, 'actual_show_includes': 'Recorded command/log prove runner restored /showIncludes; earlier omission concern corrected.',
    'librarian_arguments': arguments, 'source_compiles': 0, 'executed': False})
replay(ROOT / 'work/2008-06/native-doc-relinks/20261105-145908-8c2e91ac',
       [(old, new)], [native['object']], 'serializer', [
           'ArchiveBinder resolveRefs native near-match remains excluded; old provider is still a transitive exactness gate.',
           'Competing factory create COMDAT implementations require selected-PE identity.',
           'Four loader indirect calls, private canonical ODR, complete EH/ABI and runtime remain unproven.'])
