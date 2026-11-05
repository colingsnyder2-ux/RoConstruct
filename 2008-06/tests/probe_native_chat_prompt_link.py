"""Measure ChatPrompt provider closure against the frozen App diagnostic; never run it."""
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import sys

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild

base = root / 'rebuild/2008-06/out/native-current-audit'
baseline = json.loads((base / 'native-app-closure.json').read_text())
for name, expected in baseline['object_hashes'].items():
    path = Path(name)
    if not path.is_absolute():
        path = base / path
    assert path.is_file() and hashlib.sha256(path.read_bytes()).hexdigest() == expected, name
out = root / 'rebuild/2008-06/out/native-chat-prompt-link'
out.mkdir(parents=True, exist_ok=True)
env = dict(os.environ, NATIVE_CHECK_OUT=str(out))
units = {
    'CChatPrompt': ['00411be0=??0CChatPrompt', '00412800=?bind@CChatPrompt'],
    'CChatPromptLifetime': ['004129c0=??1CChatPrompt', '00412aa0=??_GCChatPrompt'],
    'CChatPromptWindow': ['004115c0=?OnSetFocusReflect@CChatPrompt',
                          '00411370=?PreCreateWindow@CChatPrompt',
                          '004113a0=?CtlColor@CChatPrompt'],
}
if '--chat-enter' in sys.argv:
    units['ChatEnter'] = ['00411720=??0ChatEnter', '00411300=?process@ChatEnter',
                          '00574150=??_GChatEnter']
if '--prop-grid' in sys.argv:
    units['CPropGridRebuild'] = ['004391d0=?rebuild@CPropGrid']
if '--string-value' in sys.argv:
    units['StringValueGet'] = ['00434f20=??$get@V?$basic_string@DU?$char_traits@D@std@@',
                               '00434470=??$any_cast@ABV?$basic_string']
if '--metadata' in sys.argv:
    units['MetadataMemberLookup'] = ['00443780=??$findFirstChildOfType@VProperties',
                                     '00443820=??$findFirstChildOfType@VFunctions',
                                     '004438c0=??$findFirstChildOfType@VEvents']
compiles = {}
for unit, checks in units.items():
    cmd = [sys.executable, str(root / 'rebuild/2008-06/tests/check_native_class.py'),
           'native-classes/' + unit + '.cpp'] + checks
    result = subprocess.run(cmd, cwd=root, env=env, text=True, capture_output=True, check=True)
    assert ('%d/%d exact' % (len(checks), len(checks))) in result.stdout, result.stdout
    compiles[unit] = result.stdout
if '--prop-grid' in sys.argv:
    classes = root / 'rebuild/2008-06/native-classes'
    combined = out / 'CPropGridRefreshCombined.cpp'
    lock_source = (classes / 'DataModelLock.cpp').read_text()
    lock_source = lock_source.replace('DataModel::Lock::Lock(', 'inline DataModel::Lock::Lock(')
    lock_source = lock_source.replace('void DataModel::Lock::doLock(', 'inline void DataModel::Lock::doLock(')
    lock_source = lock_source.replace('DataModel::Lock::~Lock(', 'inline DataModel::Lock::~Lock(')
    inline_lock = out / 'DataModelLockInline.cpp'
    inline_lock.write_text(lock_source.replace('#include "../native-headers/v8datamodel/DataModel.h"', '#include "v8datamodel/DataModel.h"'))
    combined.write_text('#include "CPropGrid.h"\n#include "' + inline_lock.as_posix() +
                        '"\n#include "' + (classes / 'CPropGridRefresh.cpp').as_posix() + '"\n')
    flags = json.loads((root / 'work/2008-06/shared-layouts/property-grid-working-probe.json').read_text())['flags']
    grid_obj = out / 'CPropGridRefreshCombined.obj'
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/Gy', '/Fo' + str(grid_obj), str(combined)], out)
    assert code == 0, log
    name, body, refs = next(x for x in match.coff_functions(grid_obj.read_bytes()) if x[0].startswith('?OnUpdate@CPropGrid@@'))
    target, target_refs, _ = match.target('2008-06', '00439d70')
    assert match.exact_match(target, target_refs, body, refs), name
    compiles['CPropGridRefresh'] = '00439d70 exact; combined with DataModelLock.cpp'
if '--caption' in sys.argv:
    pane_receipt = json.loads((root / 'work/2008-06/shared-layouts/pane-callbacks-working-probe.json').read_text())
    for name, expected in pane_receipt['sources'].items():
        path = root / name
        assert path.is_file() and hashlib.sha256(path.read_bytes()).hexdigest() == expected, name
    caption_obj = root / 'rebuild/2008-06/out/native-layouts/NativeCSelectionCaptionText.obj'
    name, body, refs = next(x for x in match.coff_functions(caption_obj.read_bytes())
                            if x[0].startswith('?updateCaption@CSelectionCaption@@'))
    target, target_refs, _ = match.target('2008-06', '00465e40')
    assert match.exact_match(target, target_refs, body, refs), name
    compiles['CSelectionCaptionText'] = '00465e40 exact; pane callback receipt and sources revalidated'
views = {
    'class-tree': ('class-tree-view-working', 'rebuild/2008-06/out/native-layouts/class-tree-view/NativeClassTreeViewProfile.obj', 'object_sha256'),
    'declaration': ('declaration-view-working', 'rebuild/2008-06/out/native-layouts/declaration-view/NativeDeclarationViewProfile.obj', 'unit_obj'),
    'script-editor': ('script-editor-working', 'rebuild/2008-06/out/native-layouts/NativeScriptEditorProfile.obj', 'object_sha256'),
}
view_arg = next((x.split('=', 1)[1] for x in sys.argv if x.startswith('--view=')), None)
if view_arg:
    receipt_stem, object_path, object_key = views[view_arg]
    view_receipt_path = root / ('work/2008-06/shared-layouts/' + receipt_stem + '.json')
    view_receipt = json.loads(view_receipt_path.read_text())
    for name, expected in view_receipt['sources'].items():
        path = root / name
        assert path.is_file() and hashlib.sha256(path.read_bytes()).hexdigest() == expected, name
    view_obj = root / object_path
    assert hashlib.sha256(view_obj.read_bytes()).hexdigest() == view_receipt[object_key]
    compiles['view_' + view_arg] = 'Recovered object and recorded source hashes revalidated; full selection unverified'
args = []
replaced = 0
for arg in baseline['arguments']:
    if Path(arg).name.lower() == 'checkcchatprompt.obj':
        args.append(str(out / 'CheckCChatPrompt.obj'))
        replaced += 1
    elif arg.upper().startswith('/OUT:'):
        args.append('/OUT:' + str(out / 'diagnostic.exe'))
    elif arg.upper().startswith('/MAP:'):
        args.append('/MAP:' + str(out / 'diagnostic.map'))
    else:
        args.append(arg)
assert replaced == 1
for unit in ('CChatPromptLifetime', 'CChatPromptWindow'):
    args.append(str(out / ('Check' + unit + '.obj')))
if 'ChatEnter' in units:
    args.append(str(out / 'CheckChatEnter.obj'))
if '--prop-grid' in sys.argv:
    args.append(str(grid_obj))
    args.append(str(out / 'CheckCPropGridRebuild.obj'))
if '--caption' in sys.argv:
    args.append(str(caption_obj))
if view_arg:
    args.append(str(view_obj))
if '--string-value' in sys.argv:
    args.append(str(out / 'CheckStringValueGet.obj'))
if '--metadata' in sys.argv:
    args.append(str(out / 'CheckMetadataMemberLookup.obj'))
response = out / 'link.rsp'
response.write_text('\n'.join(subprocess.list2cmdline([a]) for a in args) + '\n')
code, log = rebuild.run(rebuild.toolchain(), 'link', ['@' + str(response)], base)
(out / 'link.log').write_text(log)
unresolved = sorted(set(re.findall(r'unresolved external symbol "([^"]+)"', log)))
duplicates = sorted(set(re.findall(r'error LNK2005: (.*)', log)))
receipt = {'baseline_unresolved': baseline['count'], 'unresolved': unresolved,
           'count': len(unresolved), 'duplicates': duplicates, 'link_exit': code,
           'compiles': compiles,
           'source_sha256': {unit: hashlib.sha256((root / 'rebuild/2008-06/native-classes' / (unit + '.cpp')).read_bytes()).hexdigest() for unit in units},
           'scope': 'Donor-linked diagnostic only; OnCreate nonexact, call and vtable ABI incomplete; never run.'}
if '--metadata' in sys.argv:
    receipt['scope'] += ' Metadata lookup wrappers are nonexact drafts.'
if '--prop-grid' in sys.argv:
    receipt['grid_sources'] = {name: hashlib.sha256((classes / name).read_bytes()).hexdigest()
                               for name in ('CPropGridRefresh.cpp', 'DataModelLock.cpp')}
    receipt['grid_note'] = 'Diagnostic tests inline lock definitions and /Gy against donor ownership.'
if '--caption' in sys.argv:
    receipt['caption_object_sha256'] = hashlib.sha256(caption_obj.read_bytes()).hexdigest()
    receipt['pane_receipt_sha256'] = hashlib.sha256((root / 'work/2008-06/shared-layouts/pane-callbacks-working-probe.json').read_bytes()).hexdigest()
if view_arg:
    receipt['view_object_sha256'] = hashlib.sha256(view_obj.read_bytes()).hexdigest()
    receipt['view_receipt_sha256'] = hashlib.sha256(view_receipt_path.read_bytes()).hexdigest()
receipt_name = ('receipt-view-' + view_arg + ('-string' if '--string-value' in sys.argv else '') + ('-metadata' if '--metadata' in sys.argv else '') + '.json' if view_arg else
                'receipt-caption.json' if '--caption' in sys.argv else
                'receipt-prop-grid.json' if '--prop-grid' in sys.argv else
                'receipt-chat-enter.json' if 'ChatEnter' in units else 'receipt.json')
(out / receipt_name).write_text(json.dumps(receipt, indent=2) + '\n')
print('diagnostic: unresolved %d -> %d, duplicate errors %d, exit %d' %
      (baseline['count'], len(unresolved), len(duplicates), code))
print('new unresolved:', *sorted(set(unresolved) - set(baseline['unresolved'])), sep='\n')
sys.exit(0 if code in (0, 1120) else code)
