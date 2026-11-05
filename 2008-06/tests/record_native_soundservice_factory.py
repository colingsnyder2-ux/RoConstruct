"""Verify native SoundService factory and shared-pointer helpers."""
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
out = base / 'out/native-soundservice-factory-evidence'
checks = [('00440980', '??$create@VSoundService@Soundscape@RBX@@@?$Creatable'),
          ('004408d0', '??$?0VSoundService@Soundscape@RBX@@'),
          ('00440840', '??$?0PAVSoundService@Soundscape@RBX@@')]
run = subprocess.run([sys.executable, str(base / 'tests/check_native_class.py'),
                      'native-classes/SoundServiceProvider.cpp'] + [a + '=' + p for a, p in checks],
                     cwd=root, env=dict(os.environ, NATIVE_CHECK_OUT=str(out)),
                     capture_output=True, text=True, check=True)
assert '3/3 exact' in run.stdout, run.stdout
obj = out / 'CheckSoundServiceProvider.obj'
raw = obj.read_bytes()
names = [n for n, _, _ in match.coff_functions(raw)]
methods = [(next(n for n in names if n.startswith(prefix)), int(address, 16)) for address, prefix in checks]
_, symbols, _, _ = match._coff_data_index(raw)
mapping = [('??0SoundService@Soundscape@RBX@@', 0x5bc160),
           ('??RDeleter@?$Creatable@VInstance@RBX@@', 0x405e30)]
internal = {next(s[0] for s in symbols.values() if s[0].startswith(prefix)): address for prefix, address in mapping}
rows = verify(Original(), obj, methods, internal)
paths = [base / 'native-classes/SoundServiceProvider.cpp', base / 'native-headers/util/Sound.h',
         base / 'native-headers/v8tree/Instance.h', base / 'tests/native_bind.py', Path(__file__)]
receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
           'sources': {str(p.relative_to(root)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
           'object_sha256': hashlib.sha256(raw).hexdigest(), 'methods': rows,
           'scope': 'Inactive exact factory and shared-pointer helpers; relocations verified. Constructor ABI, provider selection and runtime unverified.'}
(root / 'work/2008-06/native-soundservice-factory.json').write_text(json.dumps(receipt, indent=2) + '\n')
print(run.stdout, end='')
