"""Link out/p6/Roblox.exe: MFC client, RTM appmodul.cpp, original resources, and
the player's engine libraries from this worktree's own player build."""
import hashlib, json, shutil, subprocess, sys
from pathlib import Path
ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).parent
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(HERE))
from roc import rebuild
import gen_res

subprocess.run([sys.executable, str(HERE / "build_native_icons.py")], cwd=ROOT, check=True)
subprocess.run([sys.executable, str(HERE / "build_native_about.py")], cwd=ROOT, check=True)

client = "2008-06"
NATIVE_DOC = '--native-doc' in sys.argv
inputs = [arg for arg in sys.argv[1:] if arg != '--native-doc']
SNAPSHOT = Path(inputs[0]) if inputs else rebuild.workspace(client) / "out"
out = rebuild.workspace(client) / "out" / "p6"
out.mkdir(parents=True, exist_ok=True)
runtime = SNAPSHOT / "tests" / "P2RecoveredPlayer"
for folder in ("Content", "Places"):
    shutil.copytree(runtime / folder, out / folder, dirs_exist_ok=True)
for dll in ("rgmain.dll", "rgdx.dll", "fmodex.dll"):
    shutil.copyfile(runtime / dll, out / dll)
shutil.copyfile(ROOT / "clients" / client / "SciLexer.dll", out / "SciLexer.dll")
(out / "runtime-stage.json").write_text(json.dumps({
    str(path.relative_to(runtime)): hashlib.sha256(path.read_bytes()).hexdigest()
    for path in runtime.rglob("*")
    if path.is_file() and (path.parts[len(runtime.parts)] in ("Content", "Places")
                          or path.name in ("rgmain.dll", "rgdx.dll", "fmodex.dll"))
}, indent=2) + "\n")
tc = rebuild.toolchain()
metadata = ROOT / "clients" / client / "ReflectionMetadata.xml"
if not metadata.exists():
    metadata = out / "ReflectionMetadata.xml"
assert metadata.exists(), metadata
if metadata.resolve() != (out / "ReflectionMetadata.xml").resolve():
    shutil.copyfile(metadata, out / "ReflectionMetadata.xml")
gen_res.generate(str(ROOT / "clients" / client / "Roblox.exe"), str(out / "roblox.res"))
shutil.copyfile(rebuild.mfc_import_lib(client), out / "mfc90.lib")
mfc = ROOT / "tools" / "libs" / "mfc-9.0-rtm" / "atlmfc" / "include"
spec = rebuild.load_module(client, "player")

libs, pending = [SNAPSHOT / spec["name"] / "linked" / "linked.lib"], list(spec["depends"])
while pending:
    dep = rebuild.load_module(client, pending.pop(0))
    lib = SNAPSHOT / dep["name"] / "linked" / "linked.lib"
    if lib not in libs:
        libs.append(lib)
        pending += dep.get("depends", [])
libs.append(SNAPSHOT / "XTP" / "linked" / "linked.lib")
libs += [rebuild.dll_import_lib(client, dll) for dll in spec["import_dlls"]]

# Same overlay-first include order the player test compiles with.
overlay = SNAPSHOT / spec["name"] / "overlay"
tree = ROOT / "tools" / "rbxgs" / "Client"
includes = []
for item in spec["test_includes"]:
    path = rebuild._spec_path(client, item)
    if path.is_relative_to(tree) and (overlay / path.relative_to(tree)).exists():
        includes.append(overlay / path.relative_to(tree))
    includes.append(path)

xtp = ROOT / "tools" / "libs" / "xtp-11.2.2" / "Source"
mfc_flags = ["/nologo", "/c", "/O2", "/GS-", "/EHsc", "/MD", "/DWIN32", "/DNDEBUG", "/D_MBCS", "/D_AFXDLL", "/D_XTP_STATICLINK", "/D_XTPLIB_NOAUTOLINK",
             "/I" + str(mfc), "/I" + str(xtp)]
shell_source = HERE / "RobloxShell.cpp"
shell_object = "RobloxShell.obj"
shell_flags = mfc_flags + ["/I" + str(HERE)]
if NATIVE_DOC:
    shell_text = shell_source.read_text()
    start = shell_text.index('class CRobloxDoc : public CDocument {')
    end = shell_text.index('IMPLEMENT_DYNCREATE(CRobloxDoc, CDocument)', start) + len('IMPLEMENT_DYNCREATE(CRobloxDoc, CDocument)')
    shell_source = out / 'RobloxShellNativeDoc.cpp'
    shell_source.write_text(shell_text[:start] + '#include "CRobloxDoc.h"' + shell_text[end:])
    shell_object = 'RobloxShellNativeDoc.obj'
    shell_flags = mfc_flags + ["/I" + str(ROOT / 'rebuild/2008-06/native-headers'), "/I" + str(HERE)] + ["/I" + str(i) for i in includes]
units = [(shell_object, shell_source, shell_flags),
         ("MyXTPCommandBars.obj", ROOT / "rebuild/2008-06/native-classes/MyXTPCommandBars.cpp", mfc_flags + ["/I" + str(ROOT / "rebuild/2008-06/native-headers")]),
         ("appmodul.obj", mfc.parent / "src" / "mfc" / "appmodul.cpp", mfc_flags + ["/I" + str(mfc.parent / "src" / "mfc")]),  # WinMain, AfxInitialize
         ("P6Engine.obj", HERE / "P6Engine.cpp", ["/nologo", "/c", "/O2", "/GS-", "/EHsc", "/MD"] + ["/D" + d for d in spec["test_defines"].split()]
          + ["/I" + str(HERE)] + ["/I" + str(i) for i in includes])]
# P6Data.cpp shares the player engine layer's headers, defines and overlay.
from roc import libs as recipes
engine = spec["layers"][0]
recipe = recipes.RECIPES[engine["includes_from_recipe"]]
data_includes = [(recipes.LIBS / i).resolve() for i in recipe["include"] if i != "WINSDK"] + [(ROOT / i).resolve() for i in engine["extra_includes"]]
data_includes.append(HERE)
data_defines = (recipes.RECIPES[engine["defines_from_recipe"]]["defines"] + " " + engine["extra_defines"]).strip()
built = rebuild.compile_direct(client, [HERE / "P6Data.cpp"], out, data_includes, data_defines, engine["flags"],
                               overlay=rebuild.build_overlay(client, spec["name"], spec["overlay"]))
for ok, message in built.values():
    print(message[-2500:] if message else "")
    if not ok:
        sys.exit(1)

for obj, source, flags in units:
    code, text = rebuild.run(tc, "cl", flags + ["/Fo" + obj, str(source)], out)
    print(text[-2500:])
    if code:
        sys.exit(code)
if NATIVE_DOC:
    doc_flags = mfc_flags + ["/D" + d for d in data_defines.split()] + ["/I" + str(ROOT / 'rebuild/2008-06/native-headers'), "/I" + str(HERE)] + ["/I" + str(i) for i in includes]
    for obj, source in [('NativeCRobloxDoc.obj', ROOT / 'rebuild/2008-06/native-classes/CRobloxDoc.cpp'),
                        ('NativeActiveDocumentDataFull.obj', ROOT / 'rebuild/2008-06/native-classes/ActiveDocumentData.cpp'),
                        ('NativeStandardVerbs.obj', ROOT / 'rebuild/2008-06/native-classes/StandardVerbs.cpp'),
                        ('NativeDocumentExceptionFull.obj', ROOT / 'rebuild/2008-06/native-classes/DocumentException.cpp'),
                        ('NativeDocumentLoadFileFull.obj', ROOT / 'rebuild/2008-06/native-classes/DocumentLoadFile.cpp'),
                        ('NativeDocumentLoadFromStringFull.obj', ROOT / 'rebuild/2008-06/native-classes/DocumentLoadFromString.cpp'),
                        ('NativeDocumentInsertModelFull.obj', ROOT / 'rebuild/2008-06/native-classes/DocumentInsertModel.cpp'),
                        ('NativeDocumentLaunchFull.obj', ROOT / 'rebuild/2008-06/native-classes/DocumentLaunch.cpp'),
                        ('NativeDocumentLaunchHandlersFull.obj', ROOT / 'rebuild/2008-06/tests/NativeDocumentLaunchTrial.cpp'),
                        ('NativeLDrawParserLifetimeFull.obj', ROOT / 'rebuild/2008-06/tests/NativeLDrawParserLifetimeTrial.cpp'),
                        ('NativeDocumentInitializeFull.obj', ROOT / 'rebuild/2008-06/tests/NativeDocumentInitializeTrial.cpp'),
                        ('NativeWorkspaceLoadFull.obj', ROOT / 'rebuild/2008-06/native-classes/CWorkspaceLoad.cpp'),
                        ('NativeWorkspaceObjectSafetyFull.obj', ROOT / 'rebuild/2008-06/native-classes/CWorkspaceObjectSafety.cpp'),
                        ('NativeWorkspaceSiteCheckFull.obj', ROOT / 'rebuild/2008-06/native-classes/CWorkspaceSiteCheck.cpp'),
                        ('NativeWorkspaceSiteUrlFull.obj', ROOT / 'rebuild/2008-06/native-classes/CWorkspaceSiteUrl.cpp'),
                        ('NativeWorkspaceErrorFull.obj', ROOT / 'rebuild/2008-06/tests/NativeWorkspaceErrorTrial.cpp'),
                        ('NativeWorkspaceStatusFull.obj', ROOT / 'rebuild/2008-06/tests/NativeWorkspaceStatusTrial.cpp'),
                        ('NativeAtlErrorCoreFull.obj', ROOT / 'rebuild/2008-06/tests/NativeAtlErrorCoreTrial.cpp'),
                        ('NativeWorkspaceGetWorkspaceFull.obj', ROOT / 'rebuild/2008-06/tests/NativeWorkspaceGetWorkspaceTrial.cpp'),
                        ('NativeContentProviderServiceFull.obj', ROOT / 'rebuild/2008-06/tests/NativeContentProviderServiceTrial.cpp'),
                        ('NativeCameraHistoryFull.obj', ROOT / 'rebuild/2008-06/native-classes/CameraHistory.cpp'),
                        ('NativeChangeHistoryCommitFull.obj', ROOT / 'rebuild/2008-06/native-classes/ChangeHistoryCommit.cpp'),
                        ('NativeExitCommandFull.obj', ROOT / 'rebuild/2008-06/tests/NativeExitCommand.cpp'),
                        ('NativeClassNamesFull.obj', ROOT / 'rebuild/2008-06/native-classes/NativeClassNames.cpp'),
                        ('NativeVerbFull.obj', ROOT / 'rebuild/2008-06/native-classes/Verb.cpp'),
                        ('NativeVerbLifetimeFull.obj', ROOT / 'rebuild/2008-06/native-classes/VerbLifetime.cpp'),
                        ('NativeVerbBaseLifetimeFull.obj', ROOT / 'rebuild/2008-06/native-classes/VerbBaseLifetime.cpp'),
                        ('NativeVerbQueriesFull.obj', ROOT / 'rebuild/2008-06/native-classes/VerbQueries.cpp'),
                        ('NativeContentProviderUrlFull.obj', ROOT / 'rebuild/2008-06/native-classes/ContentProviderUrl.cpp'),
                        ('NativeServiceLookupFull.obj', ROOT / 'rebuild/2008-06/native-classes/ServiceLookup.cpp'),
                        ('NativeHistoryRecordPlaybackFull.obj', ROOT / 'rebuild/2008-06/native-classes/HistoryRecordPlayback.cpp'),
                        ('NativeChangeHistoryPlaybackFull.obj', ROOT / 'rebuild/2008-06/native-classes/ChangeHistoryPlayback.cpp'),
                        ('NativeChangeHistoryQueriesFull.obj', ROOT / 'rebuild/2008-06/native-classes/ChangeHistoryQueries.cpp'),
                        ('NativeChangeHistoryEnableFull.obj', ROOT / 'rebuild/2008-06/native-classes/ChangeHistoryEnable.cpp'),
                        ('NativeChangeHistoryResetFull.obj', ROOT / 'rebuild/2008-06/native-classes/ChangeHistoryReset.cpp'),
                        ('NativeSelectionFrontFull.obj', ROOT / 'rebuild/2008-06/native-classes/SelectionFront.cpp'),
                        ('NativeInstanceClassLookupFull.obj', ROOT / 'rebuild/2008-06/native-classes/InstanceClassLookup.cpp'),
                        ('NativeHistoryRecordLifetimeFull.obj', ROOT / 'rebuild/2008-06/native-classes/HistoryRecordLifetime.cpp'),
                        ('NativeHistoryItemPlaybackFull.obj', ROOT / 'rebuild/2008-06/native-classes/HistoryItemPlayback.cpp'),
                        ('NativeHistoryItemPropertyFull.obj', ROOT / 'rebuild/2008-06/native-classes/HistoryItemPropertyTrial.cpp')]:
        code, text = rebuild.run(tc, 'cl', doc_flags + ['/Fo' + obj, str(source)], out)
        print(text[-2500:])
        if code:
            sys.exit(code)
system = ["gdiplus", "kernel32", "user32", "gdi32", "advapi32", "shell32", "ole32", "oleaut32", "comdlg32", "comctl32", "ws2_32", "winmm",
          "opengl32", "glu32", "imagehlp", "version", "wininet", "dbghelp", "psapi"]
output_name = 'RobloxNativeDoc' if NATIVE_DOC else 'Roblox'
native_doc_objects = ['NativeCRobloxDoc.obj', 'NativeActiveDocumentDataFull.obj', 'NativeStandardVerbs.obj',
                      'NativeDocumentExceptionFull.obj', 'NativeDocumentLoadFileFull.obj', 'NativeDocumentLoadFromStringFull.obj',
                      'NativeDocumentInsertModelFull.obj', 'NativeDocumentLaunchFull.obj', 'NativeDocumentLaunchHandlersFull.obj',
                      'NativeLDrawParserLifetimeFull.obj',
                      'NativeDocumentInitializeFull.obj', 'NativeVerbFull.obj',
                      'NativeWorkspaceLoadFull.obj',
                      'NativeWorkspaceObjectSafetyFull.obj',
                      'NativeWorkspaceSiteCheckFull.obj', 'NativeWorkspaceSiteUrlFull.obj',
                      'NativeWorkspaceErrorFull.obj', 'NativeWorkspaceStatusFull.obj', 'NativeAtlErrorCoreFull.obj',
                      'NativeWorkspaceGetWorkspaceFull.obj',
                      'NativeContentProviderServiceFull.obj',
                      'NativeCameraHistoryFull.obj',
                      'NativeChangeHistoryCommitFull.obj',
                      'NativeExitCommandFull.obj',
                      'NativeClassNamesFull.obj',
                      'NativeVerbLifetimeFull.obj', 'NativeVerbBaseLifetimeFull.obj', 'NativeVerbQueriesFull.obj',
                      'NativeContentProviderUrlFull.obj', 'NativeServiceLookupFull.obj', 'NativeHistoryRecordPlaybackFull.obj',
                      'NativeChangeHistoryPlaybackFull.obj', 'NativeChangeHistoryQueriesFull.obj',
                      'NativeChangeHistoryEnableFull.obj', 'NativeChangeHistoryResetFull.obj', 'NativeSelectionFrontFull.obj', 'NativeInstanceClassLookupFull.obj',
                      'NativeHistoryRecordLifetimeFull.obj', 'NativeHistoryItemPlaybackFull.obj',
                      'NativeHistoryItemPropertyFull.obj'] if NATIVE_DOC else []
if NATIVE_DOC:
    native_doc_objects += [str(ROOT / 'rebuild/2008-06/out/native-layouts' / name) for name in (
        'NativeSaveDialogProfile.obj', 'NativeApplicationBaseUrl.obj',
        'NativeWorkspaceLayout.obj', 'ServiceChangeHistoryCreate.obj',
        'ServiceChangeHistoryProfile.obj',
        'NativeVisitFindProfile.obj',
        'ServiceSelectionProfile.obj',
        'NativeDataModelTiming.obj', 'NativeDataModelDutyCycle.obj',
        'NativeLuaAllocatorStats.obj', 'NativePlayersAbuse.obj', 'WorkspaceInsertNativeProfile.obj',
        'WorkspaceSiteTrustProfile.obj',
        'NativeDocumentExecuteProfile.obj', 'NativeDocumentLDrawProfile.obj',
        'NativeDocumentSaveModifiedProfile.obj')]
native_doc_aliases = ['/alternatename:?createNativeWorkspace@@YGJPAPAVCWorkspace@@@Z=?CreateInstance@?$CComObject@VCWorkspace@@@ATL@@SGJPAPAV12@@Z'] if NATIVE_DOC else []
code, text = rebuild.run(tc, "link", ["/nologo", "/SUBSYSTEM:WINDOWS", "/MACHINE:X86", "/MAP:" + output_name + ".map", "/OUT:" + output_name + ".exe",
                                      "/NODEFAULTLIB:mfcs90.lib", "/MANIFEST:NO"] + native_doc_aliases + [u[0] for u in units] + [str(ROOT / "rebuild/2008-06/out/native-layouts" / name) for name in ("NativeFrameIconsFresh.obj", "NativeFrameIconWidth.obj", "NativeDHtmlDialog.obj", "NativeAboutDialog.obj", "NativeAboutDialogData.obj", "NativeFileVersionInfo.obj", "NativeGLCaps.obj")] + ["P6Data.obj", "roblox.res", "mfc90.lib"]
                         + native_doc_objects
                         + [str(l) for l in libs] + [s + ".lib" for s in system]
                         + ["/NODEFAULTLIB:" + l for l in rebuild.VENDOR_AUTOLINK], out)
if NATIVE_DOC:
    (out/'native-doc-link.log').write_text(text)
print(text[-3500:])
sys.exit(code)
