"""Link isolated ResizeTool candidate into the diagnostic; never run the result."""
import hashlib, json, re, subprocess, sys
from pathlib import Path
root = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(root))
from roc import rebuild
out = root / 'rebuild/2008-06/out/native-layouts'
work = out / 'document-swap-link-trial'
basepath = root / 'work/2008-06/shared-layouts/document-swap-provider-trial.json'
base = json.loads(basepath.read_text())
assert base['link_exit'] != 0 and base['provider_trial']
axis = '--axis' in sys.argv
test_alias = '--test-alias' in sys.argv
assert not test_alias or axis
prefix = 'NativeDocResizeAxisTestProbe' if test_alias else 'NativeDocResizeAxisProbe' if axis else 'NativeDocResizeProbe'
args = [('/OUT:' + prefix + '.exe' if x.upper().startswith('/OUT:') else
         '/MAP:NativeDocResizeProbe.map' if x.upper().startswith('/MAP:') else x)
        for x in base['link_flags']]
objects = [out / (x + '.obj') for x in ('NativeResizeToolFactoryTrial', 'NativeResizeToolTrial',
                                          'NativeResizeToolMethodsTrial', 'NativeResizeToolNameTrial',
                                          'NativeResizeToolRenderTrial', 'NativeResizeToolFindTrial',
                                          'NativeResizeToolMoveTrial', 'NativeResizeToolDragTrial', 'NativeClosestRayTrial',
                                          'NativeHandleHitTestTrial', 'NativeHandleRadiusTrial', 'NativePartResizeLink')]
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
proof = root / 'work/2008-06/shared-layouts'
lifetime = json.loads((proof / 'resize-tool-lifetime-trial.json').read_text())
methods = json.loads((proof / 'resize-tool-methods-trial.json').read_text())
part = json.loads((proof / 'part-resize-trial.json').read_text())
expected = {'NativeResizeToolTrial': lifetime['object_sha256'],
            'NativeResizeToolFactoryTrial': lifetime['factory_object_sha256'],
            'NativePartResizeLink': part['link_object_sha256']}
for item in methods['objects']:
    expected[Path(item['source']).stem] = item['object_sha256']
assert {p.stem for p in objects} == set(expected)
for obj in objects:
    assert sha(obj) == expected[obj.stem], ('stale trial object', obj)
for path, expected_hash in base['objects'].items():
    assert sha(root / path) == expected_hash, ('stale baseline object', path)
if axis:
    axis_proof = json.loads((proof / 'axis-move-tool-lifetime-trial.json').read_text())
    for extra in axis_proof['extra_objects']:
        obj = out / (extra['stem'] + '.obj'); assert sha(obj) == extra['object_sha256'], ('stale axis object', obj)
        objects.append(obj)
    for stem, key in [('NativeAxisMoveToolTrial', 'object_sha256'), ('NativeAxisMoveToolMethodsTrial', 'methods_object_sha256'), ('NativeAxisMoveDownTrial', 'down_object_sha256'), ('NativeHitMoveHandlesTrial', 'hit_object_sha256')]:
        obj = out / (stem + '.obj'); assert sha(obj) == axis_proof[key], ('stale axis object', obj)
        objects.append(obj)
if test_alias:
    trial = json.loads((proof / 'test-move-trial.json').read_text())
    obj = out / 'NativeTestMoveTrial.obj'
    assert sha(obj) == trial['object_sha256'] and trial['exact']
    caller = rebuild.coff_externals((out / 'NativeSubdivideMoveTrial.obj').read_bytes())
    callee = rebuild.coff_externals(obj.read_bytes())
    missing = next(k for k,v in caller.items() if k.startswith('?testMove@RBX@@') and not v)
    present = next(k for k,v in callee.items() if k.startswith('?testMove@RBX@@') and v)
    assert missing.replace('YA_N','YAH',1) == present
    args.append('/alternatename:' + missing + '=' + present)
    objects.append(obj)
if '--bool-test' in sys.argv:
    assert axis and not test_alias
    trial = json.loads((proof / 'test-move-bool-trial.json').read_text())
    obj = out / 'NativeTestMoveBoolTrial.obj'
    assert sha(obj) == trial['object_sha256'] and trial['exact']
    caller = rebuild.coff_externals((out / 'NativeSubdivideMoveTrial.obj').read_bytes())
    callee = rebuild.coff_externals(obj.read_bytes())
    assert caller.get(trial['symbol']) is False and callee.get(trial['symbol']) is True
    objects.append(obj)
selected = {str((root / path).resolve()).lower() for path in base['objects']}
args += [str(obj) for obj in objects if str(obj.resolve()).lower() not in selected]
response = work / (prefix + '.rsp')
response.write_text('\n'.join(subprocess.list2cmdline([arg]) for arg in args) + '\n')
code, log = rebuild.run(rebuild.toolchain(21022), 'link', ['@' + str(response)], work)
(work / (prefix + '.log')).write_text(log)
errors = [line for line in log.splitlines() if re.search(r'\berror LNK(?:2001|2019|2005)\b', line)]
receipt = {'scope': 'Isolated incompatible ABI diagnostic; do not run. No live swap or gate claims.',
           'axis_profile': axis, 'provisional_test_return_alias': test_alias, 'baseline_receipt_sha256': sha(basepath), 'baseline_errors': len(base['errors']),
           'link_exit': code, 'errors': errors, 'objects': {str(p.relative_to(root)): sha(p) for p in objects},
           'lifetime_receipt_sha256': sha(proof / 'resize-tool-lifetime-trial.json'),
           'methods_receipt_sha256': sha(proof / 'resize-tool-methods-trial.json'),
           'part_receipt_sha256': sha(proof / 'part-resize-trial.json'), 'observer_sha256': sha(Path(__file__))}
(proof / ('resize-axis-bool-probe.json' if '--bool-test' in sys.argv else 'resize-axis-test-alias-probe.json' if test_alias else 'resize-axis-document-probe.json' if axis else 'resize-document-probe.json')).write_text(json.dumps(receipt, indent=2) + '\n')
print('Resize probe: exit', code, 'errors', len(errors), 'baseline', len(base['errors']))
