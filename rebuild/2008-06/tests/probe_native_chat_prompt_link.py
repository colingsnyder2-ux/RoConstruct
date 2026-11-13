"""Measure ChatPrompt provider closure against the frozen App diagnostic; never run it."""
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor

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
if '--render-settings' in sys.argv:
    units['CRenderSettings'] = ['00412d50=?singleton@?$GlobalSettingsItem@VCRenderSettings@@']
if '--render-singleton' in sys.argv:
    units['CRenderSettingsSingleton'] = ['00412d50=?singleton@?$GlobalSettingsItem@VCRenderSettings@@']
    units['CRenderSettingsSingletonState'] = []
if '--render-ctor-trial' in sys.argv:
    units['CRenderSettingsDefaults'] = []
if '--render-base' in sys.argv:
    units['CRenderSettingsBase'] = ['00448120=??0?$GlobalSettingsItem@VCRenderSettings@@',
                                    '00445c10=??1?$GlobalSettingsItem@VCRenderSettings@@',
                                    '00445cf0=?getClassName@?$FactoryProduct@VCRenderSettings@@']
if '--render-described' in sys.argv:
    units['CRenderSettingsDescribed'] = ['00448040=??0?$DescribedCreatable@VCRenderSettings@@',
                                         '00447980=?classDescriptor@?$Described@VCRenderSettings@@']
    units['CRenderSettingsFactory'] = ['004454d0=??0?$FactoryProduct@VCRenderSettings@@',
                                       '00445410=??1?$FactoryProduct@VCRenderSettings@@']
if '--mainframe-color' in sys.argv:
    units['CMainFramePropertyGrid'] = ['00431160=?handle_431160@CMainFrame@@']
    units['PartTools'] = ['005b6530=?onMouseDown@DropperTool@RBX@@']
if '--mainframe-select' in sys.argv:
    units['ActiveDataModel'] = ['004306c0=?getActiveDataModel@@']
    units['CMainFrameColorSelection'] = []
if '--brick-map' in sys.argv:
    units['BrickColorMapAccess'] = ['005b6120=?color4uint8@BrickColor@RBX@@',
                                    '005b5d80=?closest@BrickColor@RBX@@SA?AV12@VColor4uint8']
if '--brick-singleton' in sys.argv:
    units['BrickColorMapSingleton'] = ['005b5c20=?singleton@BrickMap@BrickColor@RBX@@']
def compile_unit(item):
    unit, checks = item
    cmd = [sys.executable, str(root / 'rebuild/2008-06/tests/check_native_class.py'),
           'native-classes/' + unit + '.cpp'] + checks
    result = subprocess.run(cmd, cwd=root, env=env, text=True, capture_output=True, check=True)
    assert ('%d/%d exact' % (len(checks), len(checks))) in result.stdout, result.stdout
    return unit, result.stdout

# Each checker writes a distinct object; no shared generated files or debug database.
compile_started = time.monotonic()
with ThreadPoolExecutor(max_workers=3) as pool:
    compiles = dict(pool.map(compile_unit, units.items()))
compile_seconds = round(time.monotonic() - compile_started, 2)
if '--render-ctor-trial' in sys.argv:
    assert '--render-singleton' in sys.argv and '--render-settings' not in sys.argv
    ctor_env = dict(env, NATIVE_FLAGS='/O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast')
    result = subprocess.run([sys.executable, str(root / 'rebuild/2008-06/tests/check_native_class.py'),
                             'tests/NativeRenderSettingsConstructorTrial.cpp', '00448c60=??0CRenderSettings@@'],
                            cwd=root, env=ctor_env, text=True, capture_output=True, check=True)
    assert '1/1 exact' in result.stdout, result.stdout
    compiles['render_ctor_trial'] = result.stdout
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
    elif '--mainframe-color' in sys.argv and Path(arg).name.lower() == 'nativeparttoolsfull.obj':
        args.append(str(out / 'CheckPartTools.obj'))
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
if '--render-settings' in sys.argv:
    args.append(str(out / 'CheckCRenderSettings.obj'))
if '--render-singleton' in sys.argv:
    assert '--render-settings' not in sys.argv
    args.append(str(out / 'CheckCRenderSettingsSingleton.obj'))
    args.append(str(out / 'CheckCRenderSettingsSingletonState.obj'))
if '--render-ctor-trial' in sys.argv:
    args.append(str(out / 'CheckNativeRenderSettingsConstructorTrial.obj'))
    args.append(str(out / 'CheckCRenderSettingsDefaults.obj'))
if '--render-base' in sys.argv:
    args.append(str(out / 'CheckCRenderSettingsBase.obj'))
if '--render-described' in sys.argv:
    args.append(str(out / 'CheckCRenderSettingsDescribed.obj'))
    args.append(str(out / 'CheckCRenderSettingsFactory.obj'))
if '--mainframe-color' in sys.argv:
    args.append(str(out / 'CheckCMainFramePropertyGrid.obj'))
if '--mainframe-select' in sys.argv:
    args.append(str(out / 'CheckActiveDataModel.obj'))
    args.append(str(out / 'CheckCMainFrameColorSelection.obj'))
if '--brick-map' in sys.argv:
    args.append(str(out / 'CheckBrickColorMapAccess.obj'))
if '--brick-singleton' in sys.argv:
    args.append(str(out / 'CheckBrickColorMapSingleton.obj'))
response = out / 'link.rsp'
response.write_text('\n'.join(subprocess.list2cmdline([a]) for a in args) + '\n')
code, log = rebuild.run(rebuild.toolchain(), 'link', ['@' + str(response)], base)
(out / 'link.log').write_text(log)
unresolved = sorted(set(re.findall(r'unresolved external symbol "([^"]+)"', log)))
duplicates = sorted(set(re.findall(r'error LNK2005: (.*)', log)))
receipt = {'baseline_unresolved': baseline['count'], 'unresolved': unresolved,
           'count': len(unresolved), 'duplicates': duplicates, 'link_exit': code,
           'compiles': compiles, 'compile_seconds': compile_seconds,
           'source_sha256': {unit: hashlib.sha256((root / 'rebuild/2008-06/native-classes' / (unit + '.cpp')).read_bytes()).hexdigest() for unit in units},
           'scope': 'Donor-linked diagnostic only; OnCreate nonexact, call and vtable ABI incomplete; never run.'}
if '--metadata' in sys.argv:
    receipt['scope'] += ' Metadata lookup wrappers are nonexact drafts.'
if '--render-settings' in sys.argv:
    receipt['scope'] += ' Render settings singleton checked; whole object not audited for selection.'
if '--render-singleton' in sys.argv:
    receipt['scope'] += ' Render settings singleton only; class lifetime and initialization not selected.'
if '--render-ctor-trial' in sys.argv:
    ctor_source = root / 'rebuild/2008-06/tests/NativeRenderSettingsConstructorTrial.cpp'
    receipt['render_ctor_trial_sha256'] = hashlib.sha256(ctor_source.read_bytes()).hexdigest()
    receipt['scope'] += ' Render constructor is duplicated trial source; class vtable and initialization unverified.'
if '--render-base' in sys.argv:
    receipt['scope'] += ' Render base methods are inactive; provider ownership and full vtables unverified.'
if '--render-described' in sys.argv:
    receipt['scope'] += ' Render described/factory bases inactive; class descriptor lifetime and complete vtables unverified.'
if '--mainframe-color' in sys.argv:
    receipt['scope'] += ' Color command exact with canonical setter; listener ABI and runtime unverified.'
if '--mainframe-select' in sys.argv:
    receipt['scope'] += ' Color-selection handler is a nonexact draft.'
if '--brick-map' in sys.argv:
    receipt['scope'] += ' Brick map construction and palette initialization remain unverified.'
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
receipt_name = ('receipt-view-' + view_arg + ('-string' if '--string-value' in sys.argv else '') + ('-metadata' if '--metadata' in sys.argv else '') + ('-render' if '--render-settings' in sys.argv else '') + ('-render-singleton' if '--render-singleton' in sys.argv else '') + ('-ctor-trial' if '--render-ctor-trial' in sys.argv else '') + ('-base' if '--render-base' in sys.argv else '') + ('-described' if '--render-described' in sys.argv else '') + ('-color' if '--mainframe-color' in sys.argv else '') + ('-select' if '--mainframe-select' in sys.argv else '') + ('-brick' if '--brick-map' in sys.argv else '') + ('-brick-singleton' if '--brick-singleton' in sys.argv else '') + '.json' if view_arg else
                'receipt-caption.json' if '--caption' in sys.argv else
                'receipt-prop-grid.json' if '--prop-grid' in sys.argv else
                'receipt-chat-enter.json' if 'ChatEnter' in units else 'receipt.json')
(out / receipt_name).write_text(json.dumps(receipt, indent=2) + '\n')
print('diagnostic: unresolved %d -> %d, duplicate errors %d, exit %d' %
      (baseline['count'], len(unresolved), len(duplicates), code))
print('new unresolved:', *sorted(set(unresolved) - set(baseline['unresolved'])), sep='\n')
sys.exit(0 if code in (0, 1120) else code)
