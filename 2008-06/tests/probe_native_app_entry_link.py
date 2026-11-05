"""Expose native CRobloxApp closure using existing Doc diagnostic libraries. Never run output."""
import json
import subprocess
import sys
import hashlib
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import rebuild

# Compile/check each selected provider once. Checker's exit status alone does not
# reject nonexact bodies, so require its complete per-method exact summary too.
checks = [
    ('native-classes/CMainFrameDestructor.cpp', ['00432000=??1CMainFrame']),
    ('native-classes/CMainFrameWindow.cpp', ['0042e500=?PreCreateWindow', '00430ae0=?OnSetPreviewMode']),
    ('native-classes/CMainFrameColor.cpp', ['0042e460=?GetRuntimeClass@CMainFrame', '0042fb20=?onEvent@CMainFrame']),
    ('native-classes/CMainFrameConstructor.cpp', ['004321f0=??0CMainFrame']),
    ('native-classes/CMainFrameCommands.cpp', ['004309f0=?hideEditorChrome', '00430f50=?showEditorChrome']),
    ('native-classes/AppFramework.cpp', ['00449bf0=?initializeFramework']),
    ('native-classes/CMainFrameShow.cpp', ['0042e4c0=?showFrame']),
    ('native-classes/AppDocumentStartup.cpp', ['0044a2c0=?initializeEmptyDocument']),
    ('native-classes/ApplicationExceptionLog.cpp', ['00428850=?ReportException@LogManager']),
    ('native-classes/ErrorUploaderState.cpp', ['0044d0c0=??0data@ErrorUploader']),
    ('native-classes/ErrorUploaderConstructor.cpp', ['0044d610=??0ErrorUploader']),
    ('native-classes/ErrorUploaderLifetime.cpp', ['0044a830=??1ErrorUploader']),
    ('native-classes/ErrorUploaderCallback.cpp', ['0041d760=?upload@ErrorUploader']),
    ('native-classes/ApplicationWindowClass.cpp', ['004495a0=?nativeInitializeCom']),
    ('native-classes/CBrowserFrameWnd.cpp', ['00432fc0=?GetThisClass@CBrowserFrameWnd',
     '00433280=?CreateObject@CBrowserFrameWnd', '00433130=?OnCreate@CBrowserFrameWnd',
     '00433240=??_GCBrowserFrameWnd']),
    ('native-classes/CBrowserDoc.cpp', ['00433310=?CreateObject@CNullDoc', '0040e4f0=?CreateObject@CBrowserDoc',
     '0040dfa0=?GetThisClass@CBrowserDoc', '004332e0=?GetThisClass@CNullDoc']),
    ('native-classes/CBrowserDocManager.cpp', ['00449650=??0CBrowserDocManager', '0044a150=??_GCBrowserDocManager']),
    ('tests/NativeAppEntryLinkProbe.cpp', ['0044c3d0=??0CRobloxApp', '0044c440=??1CRobloxApp',
     '0044d790=?Run@CRobloxApp', '0044d810=?InitInstance@CRobloxApp', '0044ad60=?ExitInstance@CRobloxApp']),
    ('native-classes/CRobloxCommandLineInfo.cpp', ['0044c1b0=??0CRobloxCommandLineInfo',
     '0044c360=??1CRobloxCommandLineInfo', '0044d200=?ParseParam@CRobloxCommandLineInfo',
     '0044c310=?nativeCommandLineBaseUrl']),
    ('native-classes/Profiling.cpp', ['005c3f00=?init@Profiling']),
    ('native-classes/CVersionInfo.cpp', ['0046a200=??0CVersionInfo', '0046a220=?Load@CVersionInfo@@QAEHAB',
     '0046a370=?GetValue@CVersionInfo', '0046a440=?GetFileVersionAsString',
     '0046a4b0=??1CVersionInfo', '0046a4f0=?Load@CVersionInfo@@QAEHPAU']),
]
verification = []
for source, methods in checks:
    command = [sys.executable, str(ROOT / 'rebuild/2008-06/tests/check_native_class.py'), source] + methods
    run = subprocess.run(command, cwd=ROOT, capture_output=True, text=True)
    verification.append(dict(source=source, output=run.stdout, errors=run.stderr, exit=run.returncode))
    summary = '%d/%d exact' % (len(methods), len(methods))
    if run.returncode or summary not in run.stdout.splitlines():
        raise SystemExit('Provider verification failed: ' + source + '\n' + run.stdout + run.stderr)
    print(source, summary, flush=True)

base = ROOT / 'rebuild/2008-06/out/native-current-audit'
spec = json.loads((base / 'native-doc-link-command.json').read_text())
args = []
for arg in spec['arguments']:
    if arg == 'RobloxShellNativeDoc.obj':
        args.append(str(ROOT / 'rebuild/2008-06/out/native-layouts/CheckNativeAppEntryLinkProbe.obj'))
    elif arg.startswith('/OUT:'):
        args.append('/OUT:NativeAppClosureDiagnostic.exe')
    elif arg.startswith('/MAP:'):
        args.append('/MAP:NativeAppClosureDiagnostic.map')
    else:
        args.append(arg)
args.append(str(ROOT / 'rebuild/2008-06/out/native-layouts/CheckCRobloxCommandLineInfo.obj'))
# Existing linked.lib already owns the full Profiling family. Selecting the
# standalone object too duplicates ten definitions when that member is pulled.
args.append(str(ROOT / 'rebuild/2008-06/out/native-layouts/CheckCVersionInfo.obj'))
args.append(str(ROOT / 'rebuild/2008-06/out/native-layouts/CheckCBrowserDocManager.obj'))
args.append(str(ROOT / 'rebuild/2008-06/out/native-layouts/CheckCBrowserDoc.obj'))
args.append(str(ROOT / 'rebuild/2008-06/out/native-layouts/CheckCBrowserFrameWnd.obj'))
args.append(str(ROOT / 'rebuild/2008-06/out/native-layouts/CheckApplicationWindowClass.obj'))
response = base / 'native-app-closure.rsp'
for name in ('CMainFrameDestructor', 'CMainFrameWindow', 'CMainFrameColor'):
    args.append(str(ROOT / ('rebuild/2008-06/out/native-layouts/Check' + name + '.obj')))
for name in ('CMainFrameConstructor', 'CMainFrameCommands'):
    args.append(str(ROOT / ('rebuild/2008-06/out/native-layouts/Check' + name + '.obj')))
for name in ('AppFramework', 'CMainFrameShow'):
    args.append(str(ROOT / ('rebuild/2008-06/out/native-layouts/Check' + name + '.obj')))
for name in ('AppDocumentStartup', 'ApplicationExceptionLog', 'ErrorUploaderState',
             'ErrorUploaderConstructor', 'ErrorUploaderLifetime', 'ErrorUploaderCallback'):
    args.append(str(ROOT / ('rebuild/2008-06/out/native-layouts/Check' + name + '.obj')))
response.write_text('\n'.join(subprocess.list2cmdline([a]) for a in args) + '\n')
code, log = rebuild.run(rebuild.toolchain(), 'link', ['@' + str(response)], base)
(base / 'native-app-closure.log').write_text(log)
symbols = sorted(set(re.findall(r'unresolved external symbol "([^"]+)"', log)))
duplicates = sorted(set(re.findall(r'error LNK2005: (.*)', log)))
receipt = dict(link_exit=code, unresolved=symbols, count=len(symbols),
               duplicate_errors=duplicates, verification=verification,
               object_hashes={arg: hashlib.sha256((Path(arg) if Path(arg).is_absolute() else base / arg).read_bytes()).hexdigest()
                              for arg in args if arg.lower().endswith('.obj') and
                              (Path(arg) if Path(arg).is_absolute() else base / arg).exists()},
               scope='Native App entry replaces handmade shell for dependency diagnosis only. Donor libraries remain; never run.',
               arguments=args)
(base / 'native-app-closure.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('native App diagnostic:', code, 'unresolved:', len(symbols), 'duplicates:', len(duplicates))
for symbol in symbols:
    print(symbol)
sys.exit(0 if code in (0, 1120) else code)
