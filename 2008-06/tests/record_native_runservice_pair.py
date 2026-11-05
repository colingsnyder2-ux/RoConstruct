"""Verify native RunService creation and lookup form a matching provider pair."""
import hashlib
import json
import os
from pathlib import Path
import struct
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match, rebuild
out = ROOT/'work/2008-06/runservice-provider-pair'
out.mkdir(parents=True, exist_ok=True)
env = dict(os.environ, NATIVE_CHECK_OUT=str(out))
for src, checks in [('RunServiceCreate.cpp', ['004530f0=??$create@VRunService@RBX@@@ServiceProvider']), ('RunServiceFind.cpp', ['00452c80=??$find@VRunService@RBX@@@ServiceProvider', '00600660=??1?$shared_ptr@VInstance@RBX@@'])]:
    result = subprocess.run([sys.executable, str(ROOT/'rebuild/2008-06/tests/check_native_class.py'), 'native-classes/'+src] + checks, cwd=ROOT, env=env, capture_output=True, text=True, check=True)
    assert f'{len(checks)}/{len(checks)} exact' in result.stdout, result.stdout
create = out/'CheckRunServiceCreate.obj'
find = out/'CheckRunServiceFind.obj'
raw = create.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('??$create@VRunService@RBX@@@ServiceProvider'))
start, section = definitions[name]
table = sections[section]
target, _, _ = match.target('2008-06', '004530f0')
expected = {'??$find@VRunService@RBX@@@ServiceProvider': 0x452c80, '??$create@VRunService@RBX@@@?$Creatable': 0x405fa0, '?setParent@Instance@RBX@@': 0x55a8f0}
found = {}
for i in range(table[7]):
    offset, index, kind = struct.unpack_from('<IIH', raw, table[5]+10*i)
    offset -= start
    symbol = symbols[index][0]
    prefix = next((p for p in expected if symbol.startswith(p)), None)
    if prefix and kind == 20 and 0 <= offset <= len(body)-4:
        addr = (0x4530f0+offset+4+struct.unpack_from('<i',target,offset)[0]) & 0xffffffff
        assert addr == expected[prefix] and struct.unpack_from('<I',body,offset)[0] == 0, (symbol, hex(addr))
        found[prefix] = hex(addr)
assert set(found) == set(expected), found
lookup = next(s for s in rebuild.coff_externals(raw) if s.startswith('??$find@VRunService@RBX@@@ServiceProvider') and s.endswith('QBEPAVRunService@1@XZ'))
assert not rebuild.coff_externals(raw)[lookup] and rebuild.coff_externals(find.read_bytes())[lookup]
eh = out/'create-eh.json'
subprocess.run([sys.executable, str(ROOT/'rebuild/2008-06/tests/audit_native_eh_graph.py'), str(create), '004530f0', name, '--output', str(eh)], cwd=ROOT, check=True)
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
paths = ['rebuild/2008-06/native-classes/RunServiceCreate.cpp','rebuild/2008-06/native-classes/RunServiceFind.cpp','rebuild/2008-06/p6/build_client.py','rebuild/2008-06/tests/record_native_runservice_pair.py']
receipt = {'scope':'Inactive native create and lookup bodies, selected call targets and create local EH; executable selection, ABI and runtime unproven.', 'create_targets':found, 'lookup_symbol':lookup, 'inputs':{p:sha(ROOT/p) for p in paths}, 'create_object_sha256':sha(create), 'find_object_sha256':sha(find), 'eh_sha256':sha(eh)}
(out/'result.json').write_text(json.dumps(receipt, indent=2)+'\n', encoding='utf-8')
print('PASS native RunService create/lookup pair and call bindings')
