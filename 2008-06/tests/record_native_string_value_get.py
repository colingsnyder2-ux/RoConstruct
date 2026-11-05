"""Verify native Value::get<string> and any_cast; convert<string> remains external."""
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root / 'rebuild/2008-06/tests'))
from native_bind import Original, match, verify

base = root / 'rebuild/2008-06'
out = base / 'out/native-string-value-get-evidence'
env = dict(os.environ, NATIVE_CHECK_OUT=str(out))
checks = ['00434f20=??$get@V?$basic_string@DU?$char_traits@D@std@@',
          '00434470=??$any_cast@ABV?$basic_string']
run = subprocess.run([sys.executable, str(base / 'tests/check_native_class.py'),
                      'native-classes/StringValueGet.cpp'] + checks,
                     cwd=root, env=env, capture_output=True, text=True, check=True)
assert '2/2 exact' in run.stdout, run.stdout
obj = out / 'CheckStringValueGet.obj'
names = [name for name, _, _ in match.coff_functions(obj.read_bytes())]
get = next(n for n in names if n.startswith('??$get@V?$basic_string@DU?$char_traits@D@std@@'))
cast = next(n for n in names if n.startswith('??$any_cast@ABV?$basic_string'))
raw = obj.read_bytes()
_, symbols, _, _ = match._coff_data_index(raw)
convert = next(s[0] for s in symbols.values() if s[0].startswith('??$convert@V?$basic_string'))
throw = next(s[0] for s in symbols.values() if s[0].startswith('??$throw_exception@Vbad_any_cast@boost@@'))
rows = verify(Original(), obj, [(get, 0x434f20), (cast, 0x434470)],
              {convert: 0x56f0b0, throw: 0x40a3f0})
paths = [base / 'native-classes/StringValueGet.cpp', base / 'native-headers/reflection/type.h',
         base / 'tests/native_bind.py', base / 'tests/check_native_class.py', Path(__file__)]
receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
           'sources': {str(p.relative_to(root)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
           'object_sha256': hashlib.sha256(raw).hexdigest(), 'methods': rows,
           'scope': 'Inactive bodies and relocation bindings; convert<string> provider and runtime remain unverified.'}
path = root / 'work/2008-06/native-string-value-get.json'
path.write_text(json.dumps(receipt, indent=2) + '\n')
print(run.stdout, end='')
print(path)
