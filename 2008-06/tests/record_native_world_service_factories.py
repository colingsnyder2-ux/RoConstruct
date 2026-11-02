"""Verify native world service creation against original specializations."""
import hashlib
import json
import struct
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/tests/NativeWorldServiceFactoriesTrial.cpp'
find_trial = '--find-trial' in sys.argv
obj = out / ('NativeWorldServiceFindTrial.obj' if find_trial else 'NativeWorldServiceFactoriesTrial.obj')
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
if find_trial:
    flags.append('/DWORLD_FIND_PROFILE')
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
rows = []
for cls, address, find_addr, create_addr, index_addr in [('JointsService', '004b3a50', 0x4b34c0, 0x4b0df0, 0x4ab4d0), ('PhysicsService', '004cd7e0', 0x4ccca0, 0x4cd760, 0x4c9be0)]:
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('??$create@V' + cls + '@RBX@@@ServiceProvider'))
    target, targetrefs, _ = match.target('2008-06', address)
    assert match.exact_match(target, targetrefs, body, refs)
    start, section = definitions[name]
    table = sections[section]
    calls = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        offset -= start
        if kind == 20 and 0 <= offset < len(body) - 3:
            calls[symbols[index][0]] = (int(address, 16) + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
    expected = [('??$find@V' + cls, find_addr), ('??$create@V' + cls + '@RBX@@@?$Creatable', create_addr), ('??$doGetClassIndex@V' + cls, index_addr), ('?setParent@Instance@RBX@@', 0x55a8f0)]
    for prefix, value in expected:
        assert any(k.startswith(prefix) and v == value for k, v in calls.items()), (cls, prefix, calls)
    rows.append({'class': cls, 'address': address, 'symbol': name, 'size': len(body), 'exact': True, 'calls': {k: hex(v) for k, v in calls.items()}})
receipt = {'scope': 'Inactive typed service factories match; class layouts, cache/once identity, constructors and runtime ABI remain unproven.', 'observer_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(), 'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(), 'object_sha256': hashlib.sha256(raw).hexdigest(), 'methods': rows, 'flags': flags}
if find_trial:
    receipt['scope'] = 'Inactive find hypotheses differ; neither find body is included in the diagnostic link.'
    receipt['find_methods'] = []
    for cls, address in [('JointsService', '004b34c0'), ('PhysicsService', '004ccca0')]:
        name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('??$find@V' + cls + '@RBX@@@ServiceProvider'))
        target, targetrefs, _ = match.target('2008-06', address)
        exact = match.exact_match(target, targetrefs, body, refs)
        assert not exact
        receipt['find_methods'].append({'class': cls, 'address': address, 'candidate_size': len(body), 'original_size': len(target), 'exact': exact})
filename = 'world-service-find-mismatch.json' if find_trial else 'world-service-factories-trial.json'
(root / 'work/2008-06/shared-layouts' / filename).write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native service factory checks; find trial:', find_trial)
