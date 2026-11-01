"""Verify native DataModel base extent and recovered VerbContainer constructor."""
import hashlib
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match, rebuild

out = ROOT / 'rebuild/2008-06/out/native-layouts'
baseline = json.loads((ROOT / 'work/2008-06/shared-layouts/document-compile.json').read_text())
common = baseline['flags'][:-2]
rows = {}
for unit in ('NativeVerbContainerLayout', 'NativeDataModelBases'):
    source = ROOT / ('rebuild/2008-06/tests/' + unit + '.cpp')
    flags = common + (['/d1reportSingleClassLayoutDataModel'] if unit == 'NativeDataModelBases' else [])
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/Fo' + unit + '.obj', str(source)], out)
    assert code == 0, log
    rows[unit] = dict(source_sha256=hashlib.sha256(source.read_bytes()).hexdigest(),
                      object_sha256=hashlib.sha256((out / (unit + '.obj')).read_bytes()).hexdigest())
    if unit == 'NativeDataModelBases':
        for name, offset in (('VerbContainer', 456), ('IDataState', 496), ('Evaluator', 500),
                             ('?$Listener@VRunService', 504)):
            marker = 'DataModel::$vftable@' + name
            tail = log[log.index(marker):]
            assert '| -%d' % offset in tail[:300], (name, offset)
        assert 'class DataModel\tsize(508):' in log
        (out / 'datamodel-bases.log').write_text(log)

target, relocations, _ = match.target('2008-06', '00583460')
objects = match.coff_functions((out / 'NativeVerbContainerLayout.obj').read_bytes())
name, body, refs = next((name, body, refs) for name, body, refs in objects
                        if name.startswith('??0VerbContainer@RBX@@'))
assert match.exact_match(target, relocations, body, refs)
source_files = ['rebuild/2008-06/native-headers/v8tree/Instance.h',
                'rebuild/2008-06/native-headers/v8tree/Service.h',
                'rebuild/2008-06/native-headers/v8tree/IDataState.h',
                'rebuild/2008-06/native-headers/v8tree/VerbContainer.h',
                'rebuild/2008-06/native-classes/VerbContainer.cpp']
receipt = dict(revision=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
               compiler=21022, base_extent=508,
               offsets=dict(VerbContainer=456, IDataState=496, Evaluator=500, RunTransitionListener=504),
               original_rtti='datamodel-rtti.json',
               constructor=dict(address='00583460', symbol=name, size=len(body), relocation_normalized_exact=True),
               units=rows, sources={f: hashlib.sha256((ROOT / f).read_bytes()).hexdigest() for f in source_files},
               observer_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
               scope='Inactive DataModel base layout probe and VerbContainer constructor. Complete fields, virtual bodies, linkage and runtime ABI remain open.')
output = ROOT / 'work/2008-06' / sys.argv[1]
output.parent.mkdir(parents=True, exist_ok=True)
output.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS: four native DataModel base offsets, base extent 0x1fc, VerbContainer constructor 40 bytes exact')
