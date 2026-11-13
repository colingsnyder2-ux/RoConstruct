"""Verify native SoundService creation and original call targets."""
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
out = base / 'out/native-soundservice-create-evidence'
prefix = '??$create@VSoundService@Soundscape@RBX@@@ServiceProvider@RBX@@QBE'
context_prefix = '??$create@VSoundService@Soundscape@RBX@@@ServiceProvider@RBX@@SA'
run = subprocess.run([sys.executable, str(base / 'tests/check_native_class.py'),
                      'native-classes/SoundServiceProvider.cpp', '004531e0=' + prefix,
                      '005807b0=' + context_prefix], cwd=root,
                     env=dict(os.environ, NATIVE_CHECK_OUT=str(out)), capture_output=True, text=True, check=True)
assert '2/2 exact' in run.stdout, run.stdout
obj = out / 'CheckSoundServiceProvider.obj'
raw = obj.read_bytes()
names = [n for n, _, _ in match.coff_functions(raw)]
name = next(n for n in names if n.startswith(prefix))
context_name = next(n for n in names if n.startswith(context_prefix))
_, symbols, _, _ = match._coff_data_index(raw)
mapping = [('??$find@VSoundService@Soundscape@RBX@@@ServiceProvider', 0x452dc0),
           ('??$create@VSoundService@Soundscape@RBX@@@?$Creatable', 0x440980),
           ('?call_once@boost@@', 0x557330), ('??$doGetClassIndex@VSoundService', 0x44f420),
           ('??4shared_count@detail@boost@@', 0x4025b0), ('?setParent@Instance@RBX@@', 0x55a8f0),
           ('?flag@?1???$getClassIndex@VSoundService', 0x96dd74), ('??$callDoGetClassIndex@VSoundService', 0x450870)]
internal = {next(s[0] for s in symbols.values() if s[0].startswith(p)): a for p, a in mapping}
rows = verify(Original(), obj, [(name, 0x4531e0), (context_name, 0x5807b0)], internal)
paths = [base / 'native-classes/SoundServiceProvider.cpp', base / 'native-headers/util/Sound.h',
         base / 'native-headers/v8tree/Service.h', base / 'tests/native_bind.py', Path(__file__)]
receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
           'sources': {str(p.relative_to(root)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
           'object_sha256': hashlib.sha256(raw).hexdigest(), 'methods': rows,
           'scope': 'Inactive exact SoundService creation overloads and relocations; indirect calls, provider selection, ABI and runtime unverified.'}
(root / 'work/2008-06/native-soundservice-create.json').write_text(json.dumps(receipt, indent=2) + '\n')
print(run.stdout, end='')
