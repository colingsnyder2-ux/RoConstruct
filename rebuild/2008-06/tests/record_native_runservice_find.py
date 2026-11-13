"""Verify RunService lookup using the out-of-line shared_ptr destructor."""
import hashlib
import json
import os
import subprocess
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root / 'rebuild/2008-06/tests'))
from native_bind import Original, match, verify

base = root / 'rebuild/2008-06'
out = base / 'out/native-runservice-find-evidence'
checks = [('00452c80', '??$find@VRunService@RBX@@@ServiceProvider'),
          ('00600660', '??1?$shared_ptr@VInstance@RBX@@')]
run = subprocess.run([sys.executable, str(base / 'tests/check_native_class.py'),
                      'native-classes/RunServiceFind.cpp'] + [a + '=' + p for a, p in checks],
                     cwd=root, env=dict(os.environ, NATIVE_CHECK_OUT=str(out)),
                     capture_output=True, text=True, check=True)
assert '2/2 exact' in run.stdout, run.stdout
obj = out / 'CheckRunServiceFind.obj'
raw = obj.read_bytes()
names = [n for n, _, _ in match.coff_functions(raw)]
methods = [(next(n for n in names if n.startswith(prefix)), int(address, 16)) for address, prefix in checks]
_, symbols, _, _ = match._coff_data_index(raw)
mapping = [('?call_once@boost@@', 0x557330), ('??$doGetClassIndex@VRunService', 0x44f3c0),
           ('?resize@?$vector@V?$shared_ptr@VInstance', 0x4124c0), ('??$doDeclare@$1?sRunService', 0x401a00),
           ('?findServiceByClassName@ServiceProvider', 0x572a90), ('??4shared_count@detail@boost@@', 0x4025b0),
           ('?flag@?1???$getClassIndex@VRunService', 0x96dd70), ('??$callDoGetClassIndex@VRunService', 0x450860),
           ('?flag@?1???$declare@$1?sRunService', 0x96c2b0), ('??$callDoDeclare@$1?sRunService', 0x4029f0)]
internal = {next(s[0] for s in symbols.values() if s[0].startswith(prefix)): address for prefix, address in mapping}
rows = verify(Original(), obj, methods, internal)
paths = [base / 'native-classes/RunServiceFind.cpp', base / 'native-headers/v8tree/Service.h',
         base / 'native-headers/util/Name.h', base / 'native-headers/boost-noinline-shared-destructor/boost/shared_ptr.hpp',
         base / 'tests/native_bind.py', Path(__file__)]
receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
           'sources': {str(p.relative_to(root)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
           'object_sha256': hashlib.sha256(raw).hexdigest(), 'methods': rows,
           'scope': 'Inactive exact lookup and shared_ptr destructor; relocations checked. Indirect calls, header interoperability, provider selection and runtime unverified.'}
(root / 'work/2008-06/native-runservice-find.json').write_text(json.dumps(receipt, indent=2) + '\n')
print(run.stdout, end='')
