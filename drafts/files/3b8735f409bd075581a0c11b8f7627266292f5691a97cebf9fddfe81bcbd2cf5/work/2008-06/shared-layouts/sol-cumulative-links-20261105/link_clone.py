"""Guard exact native clone/XML helper and the no-loss owner split before diagnostic."""
from pathlib import Path
import json
from link_irenderable import members
from guarded_replay import ROOT, HERE, digest, write, replay

scope = ROOT / 'work/2008-06/shared-layouts/sol-clone-owner-20261105'
handoff = json.loads((scope / 'handoff.json').read_text())
old = ROOT / 'work/2008-06/shared-layouts/sol-irenderable-20261105/linked.lib'
new = scope / 'linked.lib'
assert digest(old) == handoff['base_sha256']
assert digest(new) == handoff['proposal_sha256']
assert handoff['unchanged_other_members'] == 266 and not handoff['audit_errors'] and not handoff['input_drift']
command = json.loads((scope / 'actual-command.json').read_text())
assert digest(command['source']) == handoff['original_source_sha256']
for path, expected in command['dependencies'].items():
    assert digest(path) == expected, path
candidates = [p for p in (ROOT / 'work/native-candidates/sol-clone-owner-20261105').rglob('*.cpp')
              if digest(p) == handoff['candidate_source_sha256']]
assert len(candidates) == 1
before, after = members(old), members(new)
assert sum(before.values()) == sum(after.values()) == 267
assert before[handoff['old_member_sha256']] == after[handoff['new_member_sha256']] == 1
before.subtract([handoff['old_member_sha256']])
after.subtract([handoff['new_member_sha256']])
assert +before == +after and sum((+before).values()) == 266
clone = json.loads((ROOT / 'work/2008-06/shared-layouts/sol-clone-delayed-20261105/saved-object.json').read_text())
helper = json.loads((ROOT / 'work/2008-06/shared-layouts/sol-clone-helper-20261105/compile-receipt.json').read_text())[0]
expected_objects = ['5ce86906a4f9046887cb1a976ea551944069c3f08313bba25ca84a799a16457f',
                    '7048fbbf73b4d1f6e9e3fc967eded57734290e8ba4f9037578b99256446a3153']
for receipt, expected in zip((clone, helper), expected_objects):
    assert receipt['status'] == 'complete' and digest(receipt['object']) == receipt['object_sha256'] == expected
    assert digest(receipt['source']) == receipt['source_sha256']
    for path, expected in receipt['dependencies'].items():
        assert digest(path) == expected, path
    assert receipt['checks'] and all(c['status'] == 'exact' and not c['data_errors'] for c in receipt['checks'])
context = json.loads((HERE / 'clone-context.json').read_text())
assert digest(context['private_header']) == context['private_sha256']
assert digest(context['canonical_header']) == context['canonical_sha256']
write(HERE / 'clone-input-guard.json', {'archive_sha256': digest(new), 'other_members_identical': 266,
      'provider_objects': [{'object': r['object'], 'sha256': r['object_sha256'], 'flags': r['flags']}
                           for r in (clone, helper)], 'private_context': context,
      'source_compiles': 0, 'scope': 'Exact code/data providers only. Indirect, transitive and canonical ODR/runtime gates stay open.'})
replay(ROOT / 'work/2008-06/native-doc-relinks/20261105-141437-a0617a57', [(old, new)],
       [clone['object'], helper['object']], 'clone', [
           'Known nonexact current loadInstances provider remains a separate recovery obligation.',
           'Private static declaration profile; canonical compatibility/ODR remains unproven.',
           'Strict indirect calls, complete EH/ABI, selected PE and runtime gates remain open.'])
