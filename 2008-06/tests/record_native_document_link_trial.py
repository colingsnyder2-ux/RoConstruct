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
native_instance = '--native-instance' in sys.argv
filtered_donor = '--filtered-donor' in sys.argv
provider_trial = '--provider-trial' in sys.argv
assert not (native_instance and filtered_donor)
assert not provider_trial or filtered_donor
if native_instance or filtered_donor:
    archive = snap/'RbxgsApp/linked/linked.lib'
    filtered = out/'RbxgsAppWithoutInstance.lib'
    remove = ['/REMOVE:Instance.obj']
    if provider_trial:
        remove += ['/REMOVE:glue_content_provider.obj', '/REMOVE:MouseCommand.obj', '/REMOVE:Primitive.obj', '/REMOVE:Workspace.obj', '/REMOVE:FaceInstance.obj', '/REMOVE:Decal.obj']
    filter_code, filter_log = rebuild.run(rebuild.toolchain(), 'lib',
        ['/nologo'] + remove + ['/OUT:' + str(filtered), str(archive)], out)
    (out/'filter.log').write_text(filter_log)
    assert filter_code == 0, filter_log
pending = list(spec['depends'])
while pending:
    dep = rebuild.load_module('2008-06', pending.pop(0))
    lib = snap/dep['name']/'linked/linked.lib'
    if lib not in libs:
        libs.append(lib)
        pending += dep.get('depends', [])
libs += [snap/'XTP/linked/linked.lib']
if native_instance or filtered_donor:
    assert archive in libs
    libs[libs.index(archive)] = filtered
libs += [rebuild.dll_import_lib('2008-06', dll) for dll in spec['import_dlls']]
objects = [out/'NativeDocShell.obj'] + [p6/name for name in ['MyXTPCommandBars.obj','appmodul.obj','P6Engine.obj','P6Data.obj','roblox.res','mfc90.lib']]
objects += [snap/'native-layouts'/name for name in ['NativeFrameIconsFresh.obj','NativeFrameIconWidth.obj','NativeDHtmlDialog.obj','NativeAboutDialog.obj','NativeAboutDialogData.obj','NativeFileVersionInfo.obj','NativeGLCaps.obj','NativeSaveDialogProfile.obj','NativeApplicationBaseUrl.obj','NativeDocumentHistoryProfile.obj','NativeDocumentException.obj','NativeWorkspaceLayout.obj','NativeWorkspaceLoad.obj','WorkspaceInsertNativeProfile.obj','NativeParserDestructor.obj','SelectionFront.obj','InstanceClassLookup.obj','NativeDataModelTiming.obj','NativeDataModelDutyCycle.obj','NativePlayersAbuse.obj','NativeLuaAllocatorStats.obj']]
objects += [snap/'native-layouts'/name for name in ['NativeVerbLifetime.obj','NativeVerbBaseLifetime.obj','NativeVerbQueries.obj']]
objects.append(snap/'native-layouts'/'NativeExitCommand.obj')
objects += [snap/'native-layouts'/'NativeCameraUnits.obj', snap/'native-layouts'/'NativeCameraConstants.obj']
objects.append(snap/'native-layouts'/'NativeSoundServicePlay.obj')
objects.append(snap/'native-layouts'/'NativeCameraHistory.obj')
objects.append(snap/'native-layouts'/'NativeFilteredSelectionService.obj')
objects.append(snap/'native-layouts'/'NativeFilteredSelectionFactory.obj')
objects.append(snap/'native-layouts'/'NativeCameraCenterAction.obj')
objects.append(snap/'native-layouts/zoom-extents-preprocess/NativeCameraZoomExtentsProfile.obj')
objects += [snap/'native-layouts'/'NativeFaceInstanceLifetime.obj', snap/'native-layouts'/'NativeDecalLifetime.obj']
objects.append(snap/'native-layouts'/'NativeDecalBases.obj')
objects.append(snap/'native-layouts'/'NativeRotateAxisTrial.obj')
objects.append(snap/'native-layouts/execscript-probe/NativeExecScriptProfile.obj')
objects.append(snap/'native-layouts/execscript-helper-probe/CWorkspaceExecScriptHelperProfile.obj')
objects.append(snap/'native-layouts/execurl-probe/NativeWorkspaceExecUrlProfile.obj')
objects.append(snap/'native-layouts/save-probe/CWorkspaceSaveProfile.obj')
objects.append(snap/'native-layouts/CWorkspaceSelectionTrial.obj')
objects.append(snap/'native-layouts/content-insert-probe/NativeWorkspaceInsertUrlProfile.obj')
objects.append(snap/'native-layouts/NativeContentFactoryTrial.obj')
objects.append(snap/'native-layouts/content-upload-probe/CContentUploadProfile.obj')
objects.append(snap/'native-layouts/content-upload-probe/CContentError.obj')
objects.append(snap/'native-layouts/content-upload-probe/CContentGuids.obj')
objects.append(snap/'native-layouts/NativeWorkspaceWriteTrial.obj')
objects.append(snap/'native-layouts/hresult-report-probe/WorkspaceHResultProfile.obj')
objects.append(snap/'native-layouts/NativeWorkspaceRaiseError.obj')
objects.append(snap/'native-layouts/lua-args-probe/LuaArgsProfile.obj')
objects += [snap/'native-layouts'/name for name in ['NativeWorkspaceObjectSafety.obj','NativeWorkspaceSiteUrl.obj']]
objects += [snap/'native-layouts'/name for name in ['ServiceSelectionProfile.obj','NativeServiceLookup.obj']]
objects += [snap/'native-layouts'/name for name in ['ServiceChangeHistoryProfile.obj','ServiceChangeHistoryCreate.obj']]
objects += [snap/'native-layouts'/name for name in ['NativeChangeHistoryQueries.obj','NativeChangeHistoryPlayback.obj','NativeHistoryRecordPlayback.obj','NativeHistoryItemPlayback.obj','NativeChangeHistoryEnable.obj','NativeChangeHistoryReset.obj','NativeHistoryRecordLifetime.obj']]
objects += [snap/'native-layouts'/'NativeChangeHistoryLayout.obj']
objects += [snap/'native-layouts'/'NativeChangeHistoryFactory.obj']
objects += [snap/'native-layouts'/('NativeInstanceLifetime.obj' if native_instance else 'NativeInstanceLifetimeLink.obj')]
if filtered_donor:
    objects += [snap/'native-layouts'/'instance-source-probe/InstanceWithoutSignals.obj']
objects += [snap/'native-layouts'/'NativeGuidItem.obj']
objects += [snap/'native-layouts'/'NativeGuidRegistryMutex.obj']
objects += [snap/'native-layouts'/'NativeGuidRegistryInitialize.obj']
objects += [snap/'native-layouts'/'NativeGuidRegistryConstructor.obj']
objects += [snap/'native-layouts'/'NativeGuidRegistryCriticalSection.obj']
objects += [snap/'native-layouts'/'NativeActiveDocument.obj']
objects += [snap/'native-layouts'/'NativeActiveDocumentData.obj']
objects += [snap/'native-layouts'/'NativeDocumentInsertModelProfile.obj']
objects += [snap/'native-layouts'/'NativeDocumentLoadFileProfile.obj']
objects += [snap/'native-layouts'/'NativeDocumentLoadFromStringProfile.obj']
objects += [snap/'native-layouts'/'NativeContentProviderUrl.obj']
if provider_trial:
    objects.append(snap/'native-layouts/content-source-probe/glue_without_content_get.obj')
    objects.append(snap/'native-layouts/mousecommand-source-probe/MouseCommandWithoutLifetime.obj')
    objects.append(snap/'native-layouts/primitive-source-probe/PrimitiveWithoutJointIteration.obj')
    objects.append(snap/'native-layouts/workspace-source-probe/WorkspaceWithoutDefault.obj')
    objects += [snap/'native-layouts'/name for name in
                ['NativeProviderFindProfile.obj', 'NativeProviderCreateTrial.obj', 'NativeContentProviderTrial.obj',
                 'NativeContentProviderWorkerTrial.obj', 'NativeContentReadTrial.obj', 'NativeContentGetTrial.obj',
                 'NativeContentLoadTrial.obj', 'NativeContentFindTrial.obj', 'NativeCacheDirectoryTrial.obj',
                 'NativeDocumentLaunchTrial.obj',
                 'NativeDocumentUrlProfile.obj',
                 'NativeDocumentSaveModifiedProfile.obj', 'NativeVisitFindProfile.obj',
                 'NativeDocumentLDrawProfile.obj', 'NativeLDrawParserLifetimeTrial.obj',
                 'NativeLDrawParserConstructorTrial.obj', 'NativeLDrawPathTrial.obj',
                 'NativeLDrawAssetStateTrial.obj', 'NativeLDrawMapRootLifetimeTrial.obj',
                 'NativeLDrawMapRootConstructorTrial.obj', 'NativeLDrawTagsTrial.obj',
                 'NativeLDrawMapOperationsTrial.obj', 'NativeLDrawCompareProfile.obj',
                 'NativeLDrawParseProfile.obj', 'NativeLDrawEntitiesTrial.obj', 'NativeLDrawWriteProfile.obj',
                 'NativeLDrawPartWriteTrial.obj', 'NativeLDrawPartParentProfile.obj', 'NativeLDrawPartColorTrial.obj',
                 'NativeLDrawPartShapeProfile.obj', 'NativeLDrawPartTransformProfile.obj',
                 'NativeDocumentExecuteProfile.obj', 'NativeDocumentInitializeTrial.obj',
                 'NativeWorkspaceGetWorkspaceTrial.obj', 'NativeVerbConstructor.obj',
                 'NativeStandardVerbsConstructorTrial.obj', 'NativeRunStateVerbConstructorTrial.obj',
                 'NativeEditSelectionVerbConstructorTrial.obj', 'NativeWorkspaceSharedFromTrial.obj',
                 'NativeSelectionCommandsTrial.obj', 'NativeWorkspaceSelectAllTrial.obj', 'NativeSurfaceVisitorsTrial.obj', 'NativeAxisCommandsTrial.obj', 'NativeAxisBaseTrial.obj',
                 'NativeBasicVerbConstructorsTrial.obj', 'NativeToolVerbActionTrial.obj',
                 'NativeMouseCommandLifetimeTrial.obj', 'NativeArrowFactoryTrial.obj',
                 'NativeNullToolFactoryTrial.obj', 'NativeGameToolFactoryTrial.obj',
                 'NativeGameToolLifetimeTrial.obj', 'NativeGameToolEventsTrial.obj',
                 'NativeGameToolNameTrial.obj', 'NativeGameToolDragTrial.obj',
                 'NativeMouseUnlockedTrial.obj', 'NativeGameToolMouseDownTrial.obj',
                 'NativePartLockProfile.obj', 'NativeJointIterationProfile.obj',
                 'NativeWorkspaceDefaultProfile.obj', 'NativeDefaultMouseCommandTrial.obj',
                 'NativeWorkspaceSiteCheck.obj', 'WorkspaceSiteTrustProfile.obj',
                 'NativeWorkspaceErrorTrial.obj', 'NativeWorkspaceStatusTrial.obj',
                 'NativeAtlErrorCoreTrial.obj', 'NativeWorkspaceComMapTrial.obj',
                 'NativeWorkspaceEventsTrial.obj', 'NativeWorkspaceCloseTrial.obj',
                 'NativeWorkspaceGuidsTrial.obj', 'NativeWorkspaceFinalConstructVectorTrial.obj',
                 'NativeDataModelCreateTrial.obj', 'NativeToolCheckedMultiTrial.obj',
                 'NativeDataModelInitializeTrial.obj', 'NativeWorkspaceNullProfile.obj',
                 'NativeWorldServiceJointFindTrial.obj', 'NativePhysicsArrayLifetimeTrial.obj',
                 'NativePhysicsArrayFindTrial.obj']]
objects += [snap/'native-layouts'/'NativeInstanceBaseCallbacks.obj']
objects += [snap/'native-layouts'/'NativeInstanceReadPropertyTrial.obj']
objects += [snap/'native-layouts'/'NativeDescendantHelpersTrial.obj']
objects += [snap/'native-layouts'/'NativeInstanceAncestorTrial.obj']
objects += [snap/'native-layouts'/'NativeInstanceDescendantThrow.obj']
objects += [snap/'native-layouts'/'NativeInstanceDescendantAddTrial.obj']
objects += [snap/'native-layouts'/'NativeInstanceSignalDescriptors.obj']
objects += [snap/'native-layouts'/name for name in ['NativeChangeHistoryEvents.obj','NativeHistoryRecordLookup.obj','NativeHistoryItemState.obj']]
objects += [snap/'property-abi-trial'/'HistoryItemPropertyTrial.obj']
objects += [snap/'history-start-trial'/'NativeChangeHistoryStartTrial.obj']
system = ['gdiplus','kernel32','user32','gdi32','advapi32','shell32','ole32','oleaut32','comdlg32','comctl32','ws2_32','winmm','opengl32','glu32','imagehlp','version','wininet','dbghelp','psapi']
args = ['/nologo','/SUBSYSTEM:WINDOWS','/MACHINE:X86','/MAP:NativeDoc.map','/OUT:NativeDoc.exe','/NODEFAULTLIB:mfcs90.lib','/MANIFEST:NO']
if provider_trial:
    args.append('/alternatename:?createNativeWorkspace@@YGJPAPAVCWorkspace@@@Z=?CreateInstance@?$CComObject@VCWorkspace@@@ATL@@SGJPAPAV12@@Z')
args += [str(path) for path in objects+libs] + [name+'.lib' for name in system] + ['/NODEFAULTLIB:'+name for name in rebuild.VENDOR_AUTOLINK]
code, log = rebuild.run(rebuild.toolchain(), 'link', args, out)
(out/'link.log').write_text(log)
errors = [line.strip() for line in log.splitlines() if 'unresolved external symbol' in line or 'already defined' in line]
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'revision':subprocess.check_output(['git','rev-parse','HEAD'],cwd=root,text=True).strip(), 'shell_sha256':sha(shell), 'generated_shell_sha256':sha(trial), 'script_sha256':sha(pathlib.Path(__file__)), 'compile_flags':flags,'link_exit':code,'link_flags':args,'errors':errors,'objects':{str(path.relative_to(root)):sha(path) for path in objects}, 'native_instance_profile':native_instance, 'scope':'Isolated diagnostic native Doc shell with descriptor and signal ABI trial objects; incompatible ABI, never run. No runtime swap, no stubs, no P5/P6 gates.'}
receipt['filtered_donor_profile'] = filtered_donor
receipt['provider_trial'] = provider_trial
if native_instance or filtered_donor:
    receipt['archive_sha256'] = sha(archive)
    receipt['filtered_archive_sha256'] = sha(filtered)
if code == 0:
    receipt['exe_sha256'] = sha(out/'NativeDoc.exe')
receipt_name = ('document-swap-provider-trial.json' if provider_trial else
                'document-swap-native-instance-trial.json' if native_instance else
                'document-swap-filtered-donor-trial.json' if filtered_donor else 'document-swap-link-trial.json')
(root/'work/2008-06/shared-layouts'/receipt_name).write_text(json.dumps(receipt,indent=2)+'\n')
print('link_exit:',code,'errors:',len(errors))
for line in errors[:45]: print(line)
