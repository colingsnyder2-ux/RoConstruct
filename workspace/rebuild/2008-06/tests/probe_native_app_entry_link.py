"""Expose native CRobloxApp closure using existing Doc diagnostic libraries. Never run output."""
import json
import os
import subprocess
import sys
import hashlib
import re
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match, rebuild

# Compile/check each selected provider once. Checker's exit status alone does not
# reject nonexact bodies, so require its complete per-method exact summary too.
checks = [
    ('native-classes/ThreadName.cpp', ['00596e60=?currentThreadName']),
    ('native-classes/ThreadNameStorage.cpp', ['00596d50=?init_foo@boost_detail@RBX']),
    ('native-classes/ThreadNameState.cpp', []),
    ('native-classes/ThreadLogPath.cpp', ['00427890=?getLogPath@ThreadLogManager']),
    ('native-classes/MainLogManagerState.cpp', []),
    ('native-classes/ThreadLogFactory.cpp', ['0042a4f0=?currentThreadLogManager',
     '0042a490=?initializeThreadLogs', '00428cf0=??_GLogManager', '00429300=??_GThreadLogManager']),
    ('native-classes/LogManagerState.cpp', []),
    ('native-classes/LogManagerGet.cpp', ['00427950=?getLog@LogManager']),
    ('native-classes/LogManagerDestructor.cpp', ['004285e0=??1LogManager']),
    ('native-classes/MainLogProvider.cpp', ['0042a5c0=?provideLog@MainLogManager']),
    ('native-classes/LogLifetime.cpp', ['005a6da0=??0Log@RBX', '005a6e60=??1Log@RBX', '005a6d10=?logTimeStamp']),
    ('native-classes/LogWriteEntry.cpp', ['005a6ef0=?writeEntry@Log@RBX']),
    ('native-classes/LogFormatTime.cpp', ['005a6c60=?formatTime@Log@RBX']),
    ('native-classes/LogFormatMemory.cpp', ['005a6bc0=?formatMem@Log@RBX']),
    ('native-classes/CRobloxReportView.cpp', ['00457a40=??0CRobloxReportView',
     '00458b70=??1CRobloxReportView', '00455fd0=?OnCreate@CRobloxReportView',
     '00456e60=?OnTimer@CRobloxReportView', '004589c0=?OnInitialUpdate@CRobloxReportView']),
    ('native-classes/CMainFrameMemoryLabels.cpp', ['0042ed20=?handle_42ed20@CMainFrame',
     '0042edd0=?handle_42edd0@CMainFrame']),
    ('native-classes/NativeMainFrameLocks.cpp', []),
    ('native-classes/NativeProfilerEnable.cpp', ['005c3f00=?nativeProfilerEnable']),
    ('native-classes/NativeOutputMode.cpp', ['00569910=?nativeSetOutputMode']),
    ('native-classes/NativeAppStartupState.cpp', []),
    ('native-classes/NativeCrashReportState.cpp', []),
    ('native-classes/LogArchive.cpp', []),
    ('native-classes/LoginRenewalUrl.cpp', []),
    ('native-classes/AppUnit568GlobalSettings.cpp', ['005684d0=?eraseSettingsStore@GlobalSettings@RBX@@QAEXXZ', '00568910=?saveState@GlobalSettings@RBX@@QAEXXZ']),
    ('native-classes/COutputView.cpp', ['00436a30=??0COutputView', '00436090=?OnInitialUpdate@COutputView', '004364b0=?OnDocumentComplete@COutputView', '00436b60=?appendElement@COutputView', '004373a0=??0CStandardOutputView', '00436ce0=??1CStandardOutputView', '00437070=?onEvent@CStandardOutputView', '00437150=?appendMessage@CStandardOutputView']),
    ('native-classes/AppLeaves2008RobloxModule.cpp', ['0044bea0=?RegisterServer@?$CAtlModuleT']),
    ('native-classes/NativeAtlModuleAliases.cpp', []),
    ('native-classes/CChatPrompt.cpp', ['00411be0=??0CChatPrompt', '00412800=?bind@CChatPrompt']),
    ('native-classes/ChatEnter.cpp', ['00411720=??0ChatEnter', '00574150=??_GChatEnter']),
    ('native-classes/CInstanceExplorer.cpp', ['00421a50=?setRoot@CInstanceExplorer',
     '00466b80=?GetRuntimeClass@CSettingsExplorer', '00466b90=?CreateObject@CSettingsExplorer',
     '00466d40=?onEvent@CSettingsExplorer', '00421d00=?OnReportSelChanged@CInstanceExplorer',
     '00420d20=??$setSelection@', '00420db0=??0CInstanceRecord', '00420790=?GetCaption@CNameItem']),
    ('native-classes/CMainFrameSettingsCommand.cpp', ['0042ee80=?handle_42ee80@CMainFrame']),
    ('native-classes/CRenderSettingsFullscreen.cpp', ['00445250=?getFullscreenSize@CRenderSettings']),
    ('native-classes/CWebToolboxPage.cpp', ['0046a590=?showPage@CWebToolbox']),
    ('native-classes/CWebToolbox.cpp', ['0046a710=?OnInitialUpdate@CWebToolbox', '0046a850=?CreateObject@CWebToolbox', '0046a8e0=?OnGetExternal@CWebToolbox']),
    ('native-classes/CSecureHtmlView.cpp', ['00465a60=??0CSecureHtmlView', '00465a80=??1CSecureHtmlView', '00465d70=?OnBeforeNavigate2@CSecureHtmlView']),
    ('native-classes/CBrowserView.cpp', ['00410d60=?CreateObject@CBrowserView', '00410dc0=?CreateObject@CIDEBrowserView', '00410e20=?CreateObject@CPlayBrowserView', '004108b0=??0CBrowserView', '00410950=??1CBrowserView']),
    ('native-classes/BrowserViewExternalFactory.cpp', ['0040fbf0=?createBrowserViewExternal']),
    ('native-classes/BrowserViewExternalMethods.cpp', ['00410f90=?get_IsIDE@CBrowserViewExternal']),
    ('native-classes/BrowserViewExternalGetApp.cpp', ['00410fe0=?GetApp@CBrowserViewExternal']),
    ('native-classes/HttpRobloxSite.cpp', ['0056a160=?isRobloxSite@Http@RBX']),
    ('native-classes/HttpScriptCheck.cpp', ['0056a040=?isScript@Http@RBX']),
    ('native-classes/HttpTrustCheck.cpp', ['0056a2e0=?trustCheck@Http@RBX']),
    ('native-classes/HttpTrustInitialize.cpp', ['00569bf0=?initializeTrustCheck@RBX']),
    ('native-classes/HttpTrustState.cpp', []),
    ('native-classes/SecureHtmlAdSyndicator.cpp', ['00409750=??0Http@RBX', '005df620=??1Http@RBX']),
    ('native-classes/HttpTransport.cpp', ['00569a40=?post@Http@RBX', '00569ae0=?get@Http@RBX']),
    ('native-classes/HttpTransportState.cpp', ['00569910=?setHttpTransportMode@RBX']),
    ('native-classes/HttpResultCheck.cpp', ['00569920=?checkHttpResult@Http@RBX']),
    ('native-classes/HttpWinInet.cpp', ['005f9c30=?httpRequest@Http@RBX', '005f9450=?read@WiniInetRequest_source', '005f9800=??0?$stream_buffer@VWiniInetRequest_source', '005f9900=??_G?$stream_buffer@VWiniInetRequest_source']),
    ('native-classes/HttpWinHttp.cpp', ['005f8b60=?httpRequestAlternate@Http@RBX', '005f2c40=?read@WinHttpRequest_source', '005f3e80=??0?$stream_buffer@VWinHttpRequest_source', '005f3fa0=??_G?$stream_buffer@VWinHttpRequest_source']),
    ('tests/NativeHttpLayout.cpp', []),
    ('native-classes/MetadataExplorerOrder.cpp', ['004225b0=?explorerOrder@Class@Metadata']),
    ('native-classes/PlayersSuperSafe.cpp', ['00497600=?superSafeOn@Players@Network']),
    ('native-classes/SelectionIterators.cpp', ['00413d10=?begin@Selection@RBX', '00413d40=?end@Selection@RBX']),
    ('native-classes/BrickColorConversions.cpp', ['005b6180=?color3uint8@BrickColor@RBX', '005b62a0=?closest@BrickColor@RBX']),
    ('native-classes/BrickColorMapAccess.cpp', ['005b6120=?color4uint8@BrickColor@RBX',
     '005b5d80=?closest@BrickColor@RBX@@SA?AV12@VColor4uint8']),
    ('native-classes/InstanceChildAcceptance.cpp', ['00423700=?canAcceptChildren@Instance@RBX']),
    ('native-classes/SettingsDialogShow.cpp', ['00466eb0=?showSettingsDialog']),
    ('native-classes/CSettingsDialog.cpp', ['00466e10=??0CSettingsDialog', '00466ca0=??1CSettingsDialog',
     '00467030=?OnInitDialog@CSettingsDialog', '00466c00=?OnResetSettings@CSettingsDialog']),
    ('native-classes/CMainFrameNewDocument.cpp', ['0042ecf0=?handle_42ecf0@CMainFrame']),
    ('native-classes/ViewCommandRouting.cpp', ['004598f0=?OnCmdMsg@?$VerbBinder@VCRobloxView']),
    ('native-classes/ChangeHistoryBase.cpp', ['0058c5e0=?initializeBase@ChangeHistoryService']),
    ('native-classes/ChangeHistoryCommit.cpp', ['0058c2c0=?commit@ChangeHistoryService',
     '0058bf80=?mergeFirst@ChangeHistoryService', '0058c0f0=?prepare@ChangeHistoryService']),
    ('native-classes/ViewVerbs.cpp', ['00459150=?doIt@HelpCommand', '00459100=?isChecked@ToggleFullscreenVerb',
     '00459120=?doIt@ToggleFullscreenVerb', '004590d0=?doIt@LockPlayModeVerb', '00458fd0=??0ToggleIDEModeVerb',
     '00459040=?isEnabled@ToggleIDEModeVerb', '00459080=?isChecked@ToggleIDEModeVerb', '004590a0=?doIt@ToggleIDEModeVerb']),
    ('native-classes/InsertModelFromRobloxVerb.cpp', ['00458ec0=??0InsertModelFromRobloxVerb',
     '00458f50=?isEnabled@InsertModelFromRobloxVerb', '00458f90=?isChecked@InsertModelFromRobloxVerb',
     '00458fb0=?doIt@InsertModelFromRobloxVerb']),
    ('native-classes/CRobloxViewInit.cpp', ['0045a4a0=?OnInitialUpdate@CRobloxView']),
    ('native-classes/SelectionGroup.cpp', ['00442350=?add@SelectionGroup', '00439660=?remove@SelectionGroup']),
    ('native-classes/CSelectionPropGridEvents.cpp', ['00442490=?onEvent@CSelectionPropGrid']),
    ('native-classes/CPropGridEvents.cpp', ['00439370=?onEvent@CPropGrid']),
    ('native-classes/CPropGridInstances.cpp', ['00439cd0=?removeInstance@CPropGrid', '004423f0=?addInstance@CPropGrid']),
    ('native-classes/CSelectionPropGrid.cpp', ['00430700=??1CSelectionPropGrid', '00437830=?GetRuntimeClass@CSelectionPropGrid']),
    ('native-classes/CRobloxWndActive.cpp', ['0070bdf0=?setActive@CRobloxWnd']),
    ('native-classes/CSelectionPropGridSelection.cpp', ['00442650=?setSelection@CSelectionPropGrid']),
    ('native-classes/AppOpenFile.cpp', ['0044a1f0=?openFile@CRobloxApp']),
    ('native-classes/AppOpenFiles.cpp', ['0044d1b0=?openFiles@CRobloxApp',
     '0044a950=?openFileFailed@CRobloxApp', '0044c0d0=??$_Find_if@PAV']),
    ('native-classes/CMultiPlayerPane.cpp', ['00432e30=??0CMultiPlayerPane', '00432e50=??1CMultiPlayerPane',
     '00432e60=?initialize@CMultiPlayerPane', '00432f20=?OnSize@CMultiPlayerPane',
     '00432f60=?OnDestroy@CMultiPlayerPane']),
    ('native-classes/CRobloxView.cpp', ['00459eb0=??0CRobloxView', '00459ba0=??1CRobloxView',
     '00458e70=?GetThisClass@CRobloxView', '004593b0=?OnActivateView@CRobloxView',
     '00459270=?getDataModel@CRobloxView', '00459250=?OnUpdateToolboxCheck@CRobloxView']),
    ('native-classes/CReflectorWnd.cpp', []),
    ('native-classes/CMainFrameToolbars.cpp', ['004307e0=?initializeToolbars@CMainFrame']),
    ('native-classes/ActiveDocViewRefresh.cpp', ['00420bd0=?refresh@ActiveDocView']),
    ('native-classes/CDataModelPropGridUpdate.cpp', ['00442900=?update@CDataModelPropGrid']),
    ('native-classes/CSelectionCaptionUpdate.cpp', ['00466940=?update@CSelectionCaption', '00466510=??1CSelectionCaption']),
    ('native-classes/ActiveDocView.cpp', ['00405d50=??0ActiveDocView', '00405d80=??1ActiveDocView']),
    ('native-classes/CObjectBrowser.cpp', ['00433410=?GetThisClass@CObjectBrowser']),
    ('native-classes/CRobloxReportSubViews.cpp', ['00455d40=?GetThisClass@CRobloxReportDocView']),
    ('native-classes/BrowserPopup.cpp', ['0040f050=?showBrowserPopup']),
    ('native-classes/CChildFrame.cpp', ['00412af0=?GetThisClass@CChildFrame', '00412b80=?GetThisClass@CRbxChildFrame', '00412c90=?CreateObject@CChildFrame', '00412cf0=?CreateObject@CRbxChildFrame', '00412e60=?OnGetMinMaxInfo@CRbxChildFrame']),
    ('native-classes/CScriptDoc.cpp', ['004638a0=?GetThisClass@CScriptDoc', '004647b0=?CreateObject@CScriptDoc']),
    ('native-classes/CRobloxViewHelp.cpp', ['00459570=?showHelp@CRobloxView', '0040e160=??HATL@@']),
    ('native-classes/ActiveDocument.cpp', ['00405aa0=?setActiveDocument']),
    ('native-classes/CIDEDocManager.cpp', ['00449910=??0CIDEDocManager', '0044a1a0=??_GCRbxDocTemplate', '0044a1c0=??_GCRbxPlayDocTemplate']),
    ('native-classes/CRbxDocTemplate.cpp', ['0044a170=?CreateNewFrame@CRbxDocTemplate', '004496f0=?RemoveDocument@CRbxPlayDocTemplate']),
    ('native-classes/TreeNodeRemoveChildren.cpp', ['00425520=?removeChildren@CRobloxTreeCtrlNode']),
    ('native-classes/TreeNodeRefresh.cpp', ['00422650=?refreshText@CRobloxTreeCtrlNode']),
    ('native-classes/CRobloxTreeCtrl.cpp', ['00425b00=??0CRobloxTreeCtrl@@', '00424900=??1CRobloxTreeCtrlNode',
     '00425de0=??0CRobloxTreeCtrlNode', '004262c0=?populate@CRobloxTreeCtrlNode',
     '004272f0=?GetMessageMap@CRobloxTreeCtrl']),
    ('native-classes/MarshalWindowGlobals.cpp', ['007ef220=??__EmarshalWindows',
     '007ef250=??__EmarshalRegistryLock', '007fa9c0=??__FmarshalRegistryLock',
     '007fa9d0=??__FmarshalWindows']),
    ('native-classes/CMarshalWindow.cpp', ['00432c50=??0CMarshalWindow', '00432950=?post@CMarshalWindow']),
    ('native-classes/MarshalWindowRegistry.cpp', ['00432ce0=?acquireMarshalWindow', '00432bd0=?releaseMarshalWindow']),
    ('native-classes/CPropGrid.cpp', ['00442b20=??0CPropGrid', '00442a30=??1CPropGrid']),
    ('native-classes/CPropGridMap.cpp', ['00440d20=?GetMessageMap@CPropGrid']),
    ('native-classes/CSelectionCaption.cpp', ['00466880=??0CSelectionCaption']),
    ('native-classes/CSelectionTreeCtrl.cpp', ['00425c90=??0CSelectionTreeCtrl']),
    ('native-classes/CDataModelPropGrid.cpp', ['00431040=??0CDataModelPropGrid', '004310f0=??1CDataModelPropGrid']),
    ('native-classes/CPatchedControlComboBox.cpp', ['0042eac0=?Compare', '0042eb30=?GetRuntimeClass', '0042fdd0=?Clone']),
    ('native-classes/LoginRenewer.cpp', ['004277d0=??0LoginRenewer']),
    ('native-classes/CRobloxControlColorSelector.cpp', ['0044ec60=??0CRobloxControlColorSelector', '0044de10=?SetColor@CRobloxControlColorSelector']),
    ('native-classes/CMainFrameXtp.cpp', ['0042fcf0=?handle_42fcf0', '0042fe00=?handle_42fe00',
     '004314e0=?handle_4314e0', '0042fbf0=?handle_42fbf0', '0070bdf0=?OnDraw@CWrapperView',
     '0042eb40=??0CWrapperView', '0042eb90=?PreCreateWindow@CWrapperView',
     '0042ebc0=?OnCmdMsg@CWrapperView', '0042ec10=?OnWndMsg@CWrapperView']),
    ('native-classes/CMainFrameCreate.cpp', ['00431d00=?OnCreate@CMainFrame']),
    ('native-classes/CMainFrameDisplay.cpp', ['004318b0=?configureFullscreen']),
    ('native-classes/CMainFrameMap.cpp', ['004321c0=?GetMessageMap@CMainFrame']),
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
    ('native-classes/CChatPromptWindow.cpp', ['004115c0=?OnSetFocusReflect@CChatPrompt',
     '00411370=?PreCreateWindow@CChatPrompt', '004113a0=?CtlColor@CChatPrompt']),
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
def verify_provider(check):
    source, methods = check
    started = time.monotonic()
    command = [sys.executable, str(ROOT / 'rebuild/2008-06/tests/check_native_class.py'), source] + methods
    run = subprocess.run(command, cwd=ROOT, capture_output=True, text=True)
    summary = '%d/%d exact' % (len(methods), len(methods))
    if run.returncode or summary not in run.stdout.splitlines():
        raise SystemExit('Provider verification failed: ' + source + '\n' + run.stdout + run.stderr)
    return dict(source=source, checked_methods=len(methods), output=run.stdout, errors=run.stderr, exit=run.returncode,
                seconds=round(time.monotonic() - started, 2))

# Each source has a distinct Check<stem>.obj. Never run two probe instances at
# once: separate instances would still write those same object paths.
assert len({Path(source).stem for source, _ in checks}) == len(checks)
started = time.monotonic()
with ThreadPoolExecutor(max_workers=min(6, os.cpu_count() or 1)) as pool:
    verification = list(pool.map(verify_provider, checks))
raw = (ROOT / 'rebuild/2008-06/out/native-layouts/CheckLogManagerState.obj').read_bytes()
sections, _, definitions, _ = match._coff_data_index(raw)
offset, section = definitions['?loggingEnabled@@3_NA']
original_base, original_image = match._image('2008-06')
assert raw[sections[section][4] + offset] == original_image[0x92e486 - original_base] == 1
# Independently verify both original fragments, call targets and static data.
ad_audit = subprocess.run([sys.executable, str(ROOT / 'rebuild/2008-06/tests/record_native_ad_syndicator.py'),
                           str(ROOT / 'rebuild/2008-06/out/native-layouts/CheckSecureHtmlAdSyndicator.obj')],
                          cwd=ROOT, capture_output=True, text=True)
if ad_audit.returncode:
    raise SystemExit('Ad-syndicator split-range audit failed: ' + ad_audit.stdout + ad_audit.stderr)
print(ad_audit.stdout.strip(), flush=True)
# Original static HTTP trust state starts zero; transport mode starts at -1.
http_state = (ROOT / 'rebuild/2008-06/out/native-layouts/CheckHttpTrustState.obj').read_bytes()
state_sections, _, state_defs, _ = match._coff_data_index(http_state)
for name, address, size in [('?skipTrustCheck@RBX@@3_NA', 0x974ab9, 1), ('?trustCheckOnce@RBX@@3JA', 0x974abc, 4)]:
    offset, section = state_defs[name]
    assert state_sections[section][0].rstrip(b'\0') == b'.bss'
    assert original_image[address - original_base:address - original_base + size] == bytes(size)
http_mode = (ROOT / 'rebuild/2008-06/out/native-layouts/CheckHttpTransportState.obj').read_bytes()
mode_sections, _, mode_defs, _ = match._coff_data_index(http_mode)
offset, section = mode_defs['?httpTransportMode@RBX@@3HA']
assert http_mode[mode_sections[section][4] + offset:mode_sections[section][4] + offset + 4] == original_image[0x946274 - original_base:0x946278 - original_base] == b'\xff\xff\xff\xff'
print('sources:', len(checks), 'checked in', round(time.monotonic() - started, 2), 'seconds', flush=True)

base = ROOT / 'rebuild/2008-06/out/native-current-audit'
spec = json.loads((base / 'native-doc-link-command.json').read_text())
args = [str(ROOT / "rebuild/2008-06/out/native-layouts/CheckCRobloxViewHelp.obj"), str(ROOT / "rebuild/2008-06/out/native-layouts/CheckInstanceChildAcceptance.obj"), str(ROOT / "rebuild/2008-06/out/native-layouts/CheckSecureHtmlAdSyndicator.obj")]
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
for name in ('CObjectBrowser', 'CRobloxReportSubViews'):
    args.append(str(ROOT / ('rebuild/2008-06/out/native-layouts/Check' + name + '.obj')))
args.append(str(ROOT / 'rebuild/2008-06/out/native-layouts/CheckBrowserPopup.obj'))
args.append(str(ROOT / 'rebuild/2008-06/out/native-layouts/CheckActiveDocument.obj'))
args.append(str(ROOT / 'rebuild/2008-06/out/native-layouts/CheckActiveDocView.obj'))
for name in ('CRobloxView', 'CReflectorWnd', 'CMainFrameToolbars', 'CMultiPlayerPane', 'AppOpenFiles', 'AppOpenFile',
             'CRobloxWndActive', 'CSelectionPropGridSelection', 'CSelectionPropGridEvents',
             'CPropGridEvents', 'CPropGridInstances', 'CSelectionPropGrid', 'CRobloxViewInit', 'SelectionGroup',
             'ViewVerbs', 'InsertModelFromRobloxVerb', 'ChangeHistoryBase', 'ViewCommandRouting',
             'CMainFrameNewDocument', 'CMainFrameSettingsCommand', 'CRenderSettingsFullscreen', 'CWebToolboxPage', 'CWebToolbox', 'CSecureHtmlView', 'CBrowserView', 'BrowserViewExternalFactory', 'BrowserViewExternalMethods', 'BrowserViewExternalGetApp', 'HttpRobloxSite', 'HttpScriptCheck', 'HttpTrustCheck', 'HttpTrustInitialize', 'HttpTrustState', 'HttpTransport', 'HttpTransportState', 'HttpResultCheck', 'HttpWinInet', 'HttpWinHttp', 'MetadataExplorerOrder', 'PlayersSuperSafe', 'SelectionIterators', 'BrickColorConversions', 'SettingsDialogShow', 'CSettingsDialog',
             'CInstanceExplorer', 'CChatPrompt', 'ChatEnter', 'CMainFrameMemoryLabels', 'NativeMainFrameLocks', 'NativeProfilerEnable', 'NativeOutputMode', 'NativeAppStartupState', 'NativeCrashReportState', 'LogArchive', 'LoginRenewalUrl', 'AppUnit568GlobalSettings', 'COutputView', 'AppLeaves2008RobloxModule', 'NativeAtlModuleAliases', 'CRobloxReportView',
             'BrickColorMapAccess',
             'LogLifetime', 'LogWriteEntry', 'LogFormatTime', 'LogFormatMemory', 'MainLogProvider', 'LogManagerGet',
             'LogManagerState', 'LogManagerDestructor', 'ThreadLogFactory', 'ThreadLogPath', 'MainLogManagerState',
             'ThreadName', 'ThreadNameState'):
    args.append(str(ROOT / ('rebuild/2008-06/out/native-layouts/Check' + name + '.obj')))
for name in ('ActiveDocViewRefresh', 'CDataModelPropGridUpdate', 'CSelectionCaptionUpdate'):
    args.append(str(ROOT / ('rebuild/2008-06/out/native-layouts/Check' + name + '.obj')))
for name in ('CChildFrame', 'CScriptDoc'):
    args.append(str(ROOT / ('rebuild/2008-06/out/native-layouts/Check' + name + '.obj')))
for name in ('CIDEDocManager', 'CRbxDocTemplate'):
    args.append(str(ROOT / ('rebuild/2008-06/out/native-layouts/Check' + name + '.obj')))
args.append(str(ROOT / 'rebuild/2008-06/out/native-layouts/CheckTreeNodeRemoveChildren.obj'))
args.append(str(ROOT / 'rebuild/2008-06/out/native-layouts/CheckTreeNodeRefresh.obj'))
args.append(str(ROOT / 'rebuild/2008-06/out/native-layouts/CheckCRobloxTreeCtrl.obj'))
args.append(str(ROOT / 'rebuild/2008-06/out/native-layouts/CheckMarshalWindowGlobals.obj'))
for name in ('CMarshalWindow', 'MarshalWindowRegistry', 'CPropGrid', 'CPropGridMap'):
    args.append(str(ROOT / ('rebuild/2008-06/out/native-layouts/Check' + name + '.obj')))
for name in ('CSelectionCaption', 'CSelectionTreeCtrl', 'CDataModelPropGrid', 'CPatchedControlComboBox'):
    args.append(str(ROOT / ('rebuild/2008-06/out/native-layouts/Check' + name + '.obj')))
for name in ('LoginRenewer', 'CRobloxControlColorSelector'):
    args.append(str(ROOT / ('rebuild/2008-06/out/native-layouts/Check' + name + '.obj')))
for name in ('CMainFrameXtp', 'CMainFrameCreate', 'CMainFrameDisplay'):
    args.append(str(ROOT / ('rebuild/2008-06/out/native-layouts/Check' + name + '.obj')))
args.append(str(ROOT / 'rebuild/2008-06/out/native-layouts/CheckCMainFrameMap.obj'))
for name in ('CMainFrameDestructor', 'CMainFrameWindow', 'CMainFrameColor'):
    args.append(str(ROOT / ('rebuild/2008-06/out/native-layouts/Check' + name + '.obj')))
for name in ('CMainFrameConstructor', 'CMainFrameCommands'):
    args.append(str(ROOT / ('rebuild/2008-06/out/native-layouts/Check' + name + '.obj')))
for name in ('AppFramework', 'CMainFrameShow'):
    args.append(str(ROOT / ('rebuild/2008-06/out/native-layouts/Check' + name + '.obj')))
for name in ('AppDocumentStartup', 'ApplicationExceptionLog', 'ErrorUploaderState',
             'ErrorUploaderConstructor', 'ErrorUploaderLifetime', 'ErrorUploaderCallback'):
    args.append(str(ROOT / ('rebuild/2008-06/out/native-layouts/Check' + name + '.obj')))
# Supplies the exact MFC message map; PreCreateWindow still has a separate protected/public ABI spelling gap.
args.append(str(ROOT / 'rebuild/2008-06/out/native-layouts/CheckCChatPromptWindow.obj'))
# Isolate native Log and Http trust providers without mutating the shared donor archive.
donor_log_library = base / 'content-load-owner/linked.lib'
native_log_library = base / 'content-without-donor-log.lib'
code, log = rebuild.run(rebuild.toolchain(), 'lib',
                        ['/nologo', '/remove:Log.obj', '/remove:Http.obj', '/out:' + str(native_log_library), str(donor_log_library)], base)
if code:
    raise SystemExit('Unable to isolate donor Log.obj: ' + log)
assert sum(Path(arg) == donor_log_library for arg in args) == 1
args = [str(native_log_library) if Path(arg) == donor_log_library else arg for arg in args]
object_names = {Path(arg).name.lower() for arg in args if arg.lower().endswith('.obj')}
for item in verification:
    item['object_on_link_command'] = ('Check' + Path(item['source']).stem + '.obj').lower() in object_names
print('checked source objects on link command:', sum(item['object_on_link_command'] for item in verification),
      'of', len(verification), flush=True)
response.write_text('\n'.join(subprocess.list2cmdline([a]) for a in args) + '\n')
code, log = rebuild.run(rebuild.toolchain(), 'link', ['@' + str(response)], base)
(base / 'native-app-closure.log').write_text(log)
symbols = sorted(set(re.findall(r'unresolved external symbol "([^"]+)"', log)))
duplicates = sorted(set(re.findall(r'error LNK2005: (.*)', log)))
receipt = dict(link_exit=code, unresolved=symbols, count=len(symbols),
               duplicate_errors=duplicates, verification=verification,
               donor_log_library_sha256=hashlib.sha256(donor_log_library.read_bytes()).hexdigest(),
               native_log_library_sha256=hashlib.sha256(native_log_library.read_bytes()).hexdigest(),
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
