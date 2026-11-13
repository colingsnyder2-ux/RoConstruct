"""Verify standalone render-settings singleton; no class swap or runtime claim."""
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
out = base / 'out/native-render-singleton-evidence'
env = dict(os.environ, NATIVE_CHECK_OUT=str(out))
run = subprocess.run([sys.executable, str(base / 'tests/check_native_class.py'),
                      'native-classes/CRenderSettingsSingleton.cpp',
                      '00412d50=?singleton@?$GlobalSettingsItem@VCRenderSettings@@'],
                     cwd=root, env=env, capture_output=True, text=True, check=True)
assert '1/1 exact' in run.stdout, run.stdout
obj = out / 'CheckCRenderSettingsSingleton.obj'
raw = obj.read_bytes()
names = [n for n, _, _ in match.coff_functions(raw)]
name = next(n for n in names if n.startswith('?singleton@?$GlobalSettingsItem@VCRenderSettings@@'))
_, symbols, _, _ = match._coff_data_index(raw)
mapping = [('?mutex@GlobalSettings@RBX@@', 0x974aa0), ('?do_lock@recursive_mutex@boost@@', 0x563090),
           ('?sing@?$GlobalSettingsItem@VCRenderSettings@@', 0x96cbec),
           ('??$create@VCRenderSettings@@', 0x408ed0), ('?singleton@GlobalSettings@RBX@@', 0x5690f0),
           ('?setParent@Instance@RBX@@', 0x55a8f0), ('?do_unlock@recursive_mutex@boost@@', 0x5630e0)]
internal = {next(s[0] for s in symbols.values() if s[0].startswith(prefix)): address for prefix, address in mapping}
rows = verify(Original(), obj, [(name, 0x412d50)], internal)
paths = [base / 'native-classes/CRenderSettingsSingleton.cpp', base / 'native-headers/CRenderSettings.h',
         base / 'native-headers/v8datamodel/GlobalSettings.h', base / 'tests/native_bind.py',
         base / 'tests/check_native_class.py', Path(__file__)]
receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
           'sources': {str(p.relative_to(root)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
           'object_sha256': hashlib.sha256(raw).hexdigest(), 'methods': rows,
           'scope': 'Inactive exact singleton and bindings. Creator, shared storage, class lifetime and runtime remain open.'}
path = root / 'work/2008-06/native-render-settings-singleton.json'
path.write_text(json.dumps(receipt, indent=2) + '\n')
print(run.stdout, end='')
print(path)
