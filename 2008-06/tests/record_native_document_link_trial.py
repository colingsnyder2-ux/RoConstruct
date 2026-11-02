"""Compile and link an isolated shell using the native CRobloxDoc candidate."""
import hashlib
import json
import pathlib
import subprocess
import sys

root = pathlib.Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import libs as recipes, rebuild
snap = root/'rebuild/2008-06/out'
p6 = snap/'p6'
out = snap/'native-layouts/document-swap-link-trial'
out.mkdir(parents=True, exist_ok=True)
shell = root/'rebuild/2008-06/p6/RobloxShell.cpp'
source = shell.read_text()
start = source.index('class CRobloxDoc : public CDocument {')
end = source.index('IMPLEMENT_DYNCREATE(CRobloxDoc, CDocument)',start) + len('IMPLEMENT_DYNCREATE(CRobloxDoc, CDocument)')
source = source[:start] + '#include "CRobloxDoc.h"' + source[end:]
source = source.replace('#include "../native-headers/', '#include "')
trial = out/'NativeDocShell.cpp'
trial.write_text(source)
mfc = root/'tools/libs/mfc-9.0-rtm/atlmfc/include'
xtp = root/'tools/libs/xtp-11.2.2/Source'
recipe = recipes.RECIPES['rbxgs']
flags = ['/nologo','/c','/O2','/GS-','/EHsc','/MD','/DWIN32','/DNDEBUG','/D_MBCS','/D_AFXDLL','/D_XTP_STATICLINK','/D_XTPLIB_NOAUTOLINK','/DBOOST_ALL_NO_LIB']
flags += ['/D'+value for value in recipe['defines'].split()]
flags += ['/I'+str(mfc),'/I'+str(xtp),'/I'+str(root/'rebuild/2008-06/native-headers'),'/I'+str(root/'rebuild/2008-06/p6')]
flags += ['/I'+str((recipes.LIBS/item).resolve()) for item in recipe['include'] if item != 'WINSDK']
flags += ['/FoNativeDocShell.obj',str(trial)]
code, log = rebuild.run(rebuild.toolchain(), 'cl', flags, out)
(out/'compile.log').write_text(log)
if code:
    print('shell compile failed:', code, log[-4000:])
    sys.exit(code)
spec = rebuild.load_module('2008-06','player')
libs = [snap/spec['name']/'linked/linked.lib']
pending = list(spec['depends'])
while pending:
    dep = rebuild.load_module('2008-06', pending.pop(0))
    lib = snap/dep['name']/'linked/linked.lib'
    if lib not in libs:
        libs.append(lib)
        pending += dep.get('depends', [])
libs += [snap/'XTP/linked/linked.lib']
libs += [rebuild.dll_import_lib('2008-06', dll) for dll in spec['import_dlls']]
objects = [out/'NativeDocShell.obj'] + [p6/name for name in ['MyXTPCommandBars.obj','appmodul.obj','P6Engine.obj','P6Data.obj','roblox.res','mfc90.lib']]
objects += [snap/'native-layouts'/name for name in ['NativeFrameIconsFresh.obj','NativeFrameIconWidth.obj','NativeDHtmlDialog.obj','NativeAboutDialog.obj','NativeAboutDialogData.obj','NativeFileVersionInfo.obj','NativeGLCaps.obj','NativeSaveDialogProfile.obj','NativeApplicationBaseUrl.obj','NativeDocumentHistoryProfile.obj','NativeDocumentException.obj','NativeWorkspaceLayout.obj','NativeWorkspaceLoad.obj','WorkspaceInsertNativeProfile.obj','NativeParserDestructor.obj','SelectionFront.obj','InstanceClassLookup.obj','NativeDataModelTiming.obj','NativeDataModelDutyCycle.obj','NativePlayersAbuse.obj','NativeLuaAllocatorStats.obj']]
objects += [snap/'native-layouts'/name for name in ['NativeVerbLifetime.obj','NativeVerbBaseLifetime.obj','NativeVerbQueries.obj']]
objects += [snap/'native-layouts'/name for name in ['NativeWorkspaceObjectSafety.obj','NativeWorkspaceSiteUrl.obj']]
objects += [snap/'native-layouts'/name for name in ['ServiceSelectionProfile.obj','NativeServiceLookup.obj']]
objects += [snap/'native-layouts'/name for name in ['ServiceChangeHistoryProfile.obj','ServiceChangeHistoryCreate.obj']]
objects += [snap/'native-layouts'/name for name in ['NativeChangeHistoryQueries.obj','NativeChangeHistoryPlayback.obj','NativeHistoryRecordPlayback.obj','NativeHistoryItemPlayback.obj','NativeChangeHistoryEnable.obj','NativeChangeHistoryReset.obj','NativeHistoryRecordLifetime.obj']]
objects += [snap/'native-layouts'/'NativeChangeHistoryLayout.obj']
objects += [snap/'native-layouts'/'NativeInstanceLifetimeLink.obj']
objects += [snap/'native-layouts'/name for name in ['NativeChangeHistoryEvents.obj','NativeHistoryRecordLookup.obj','NativeHistoryItemState.obj']]
objects += [snap/'property-abi-trial'/'HistoryItemPropertyTrial.obj']
objects += [snap/'history-start-trial'/'NativeChangeHistoryStartTrial.obj']
system = ['gdiplus','kernel32','user32','gdi32','advapi32','shell32','ole32','oleaut32','comdlg32','comctl32','ws2_32','winmm','opengl32','glu32','imagehlp','version','wininet','dbghelp','psapi']
args = ['/nologo','/SUBSYSTEM:WINDOWS','/MACHINE:X86','/MAP:NativeDoc.map','/OUT:NativeDoc.exe','/NODEFAULTLIB:mfcs90.lib','/MANIFEST:NO']
args += [str(path) for path in objects+libs] + [name+'.lib' for name in system] + ['/NODEFAULTLIB:'+name for name in rebuild.VENDOR_AUTOLINK]
code, log = rebuild.run(rebuild.toolchain(), 'link', args, out)
(out/'link.log').write_text(log)
errors = [line.strip() for line in log.splitlines() if 'unresolved external symbol' in line or 'already defined' in line]
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'revision':subprocess.check_output(['git','rev-parse','HEAD'],cwd=root,text=True).strip(), 'shell_sha256':sha(shell), 'generated_shell_sha256':sha(trial), 'script_sha256':sha(pathlib.Path(__file__)), 'compile_flags':flags,'link_exit':code,'link_flags':args,'errors':errors,'objects':{str(path.relative_to(root)):sha(path) for path in objects}, 'scope':'Isolated diagnostic native Doc shell with descriptor and signal ABI trial objects; incompatible ABI, never run. No runtime swap, no stubs, no P5/P6 gates.'}
if code == 0:
    receipt['exe_sha256'] = sha(out/'NativeDoc.exe')
(root/'work/2008-06/shared-layouts/document-swap-link-trial.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('link_exit:',code,'errors:',len(errors))
for line in errors[:45]: print(line)
