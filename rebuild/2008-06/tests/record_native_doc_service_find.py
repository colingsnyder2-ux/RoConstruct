"""Verify native Visit service lookup and its original shared_ptr boundary."""
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
out = base / 'out/native-doc-service-find-evidence'
checks = [('00452b40', '??$find@VVisit@RBX@@@ServiceProvider'),
          ('0044f4a0', '??$doGetClassIndex@VVisit@RBX@@@ServiceProvider'),
          ('0044f2f0', '??$doDeclare@$1?sVisit'),
          ('00600660', '??1?$shared_ptr@VInstance@RBX@@')]
run = subprocess.run([sys.executable, str(base / 'tests/check_native_class.py'),
                      'native-classes/VisitServiceLookup.cpp'] + [a + '=' + p for a, p in checks],
                     cwd=root, env=dict(os.environ, NATIVE_CHECK_OUT=str(out)),
                     capture_output=True, text=True, check=True)
assert '4/4 exact' in run.stdout, run.stdout
obj = out / 'CheckVisitServiceLookup.obj'
raw = obj.read_bytes()
names = [n for n, _, _ in match.coff_functions(raw)]
methods = [(next(n for n in names if n.startswith(prefix)), int(address, 16)) for address, prefix in checks]
_, symbols, _, _ = match._coff_data_index(raw)
mapping = [('?call_once@boost@@', 0x557330), ('?resize@?$vector@V?$shared_ptr@VInstance', 0x4124c0),
           ('?findServiceByClassName@ServiceProvider', 0x572a90),
           ('??4shared_count@detail@boost@@', 0x4025b0), ('?flag@?1???$getClassIndex@VVisit', 0x96dd78),
           ('??$callDoGetClassIndex@VVisit', 0x450880), ('?flag@?1???$declare@$1?sVisit', 0x96dd68),
           ('??$callDoDeclare@$1?sVisit', 0x450840), ('?newIndex@ServiceProvider', 0x572690),
           ('??_B?1???$doGetClassIndex@VVisit', 0x96dd64), ('?index@?1???$doGetClassIndex@VVisit', 0x96dd60),
           ('?$S2@?1???$doDeclare@$1?sVisit', 0x96dd44), ('?name@?1???$doDeclare@$1?sVisit', 0x96dd40),
           ('?declare@Name@RBX@@', 0x553f90)]
internal = {next(s[0] for s in symbols.values() if s[0].startswith(prefix)): address for prefix, address in mapping}
rows = verify(Original(), obj, methods, internal)
paths = [base / 'native-classes/VisitServiceLookup.cpp', base / 'native-headers/v8datamodel/Visit.h',
         base / 'native-headers/v8tree/Service.h', base / 'native-headers/util/Name.h',
         base / 'native-headers/boost-noinline-shared-destructor/boost/shared_ptr.hpp',
         base / 'tests/native_bind.py', Path(__file__)]
receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
           'sources': {str(p.relative_to(root)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
           'object_sha256': hashlib.sha256(raw).hexdigest(), 'methods': rows,
           'scope': 'Inactive exact Visit lookup, index and shared_ptr destructor; relocations checked. Indirect calls, provider selection, ABI and runtime unverified.'}
(root / 'work/2008-06/native-doc-service-find.json').write_text(json.dumps(receipt, indent=2) + '\n')
print(run.stdout, end='')
