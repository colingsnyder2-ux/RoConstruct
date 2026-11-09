"""Verify active-model accessor and record inactive main-frame color-handler draft."""
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
out = base / 'out/native-mainframe-color-selection-evidence'
env = dict(os.environ, NATIVE_CHECK_OUT=str(out))
checker = str(base / 'tests/check_native_class.py')
checks = [('native-classes/ActiveDataModel.cpp', '004306c0=?getActiveDataModel@@'),
          ('native-classes/CMainFrameColorSelection.cpp', '00431260=?handle_431260@CMainFrame@@')]
results = []
for source, check in checks:
    run = subprocess.run([sys.executable, checker, source, check], cwd=root, env=env,
                         capture_output=True, text=True, check=True)
    results.append(run.stdout)
assert '1/1 exact' in results[0] and 'differs' in results[1], results
obj = out / 'CheckActiveDataModel.obj'
raw = obj.read_bytes()
names = [n for n, _, _ in match.coff_functions(raw)]
symbol = next(n for n in names if n.startswith('?getActiveDataModel@@'))
_, symbols, _, _ = match._coff_data_index(raw)
storage = next(s[0] for s in symbols.values() if s[0].startswith('?activeDocDataModel@@'))
rows = verify(Original(), obj, [(symbol, 0x4306c0)], {storage: 0x96c25c})
paths = [base / 'native-classes/ActiveDataModel.cpp', base / 'native-classes/CMainFrameColorSelection.cpp',
         base / 'native-headers/ActiveDocView.h', base / 'native-headers/CMainFrame.h',
         base / 'native-headers/CRobloxControlColorSelector.h', base / 'native-headers/v8datamodel/ToolsPart.h',
         base / 'native-headers/v8datamodel/DataModel.h', base / 'native-headers/v8tree/Verb.h',
         base / 'tests/native_bind.py', Path(__file__)]
receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
           'sources': {str(p.relative_to(root)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
           'object_sha256': hashlib.sha256(raw).hexdigest(), 'methods': rows, 'draft_checks': results[1],
           'scope': 'Inactive exact accessor; color handler still differs. No selected binary or runtime proof.'}
path = root / 'work/2008-06/native-mainframe-color-selection.json'
path.write_text(json.dumps(receipt, indent=2) + '\n')
print(''.join(results), end='')
print(path)
