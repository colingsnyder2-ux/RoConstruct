"""Link out/p6/Roblox.exe: MFC client, RTM appmodul.cpp, original resources, and
the player's engine libraries from this worktree's own player build."""
import hashlib, json, os, re, shutil, subprocess, sys
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
NATIVE_DOC_CACHE = '--native-doc-cache' in sys.argv
args = sys.argv[1:]
NATIVE_DOC_OUT = None
if '--native-doc-out' in args:
    out_index = args.index('--native-doc-out')
    if out_index + 1 == len(args):
        raise SystemExit('--native-doc-out needs a directory')
    NATIVE_DOC_OUT = Path(args[out_index + 1])
    del args[out_index:out_index + 2]
inputs = [arg for arg in args if arg not in ('--native-doc', '--native-doc-cache')]
SNAPSHOT = Path(inputs[0]) if inputs else rebuild.workspace(client) / "out"
if NATIVE_DOC_OUT and not NATIVE_DOC:
    raise SystemExit('--native-doc-out requires --native-doc')
out = NATIVE_DOC_OUT or (rebuild.workspace(client) / "out" / "p6")
if not out.is_absolute():
    out = ROOT / out
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
    metadata = rebuild.workspace(client) / "out" / "p6" / "ReflectionMetadata.xml"
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
data_overlay = rebuild.build_overlay(client, spec["name"], spec["overlay"])
cache_dir = rebuild.workspace(client) / 'out' / 'p6' / 'native-doc-cache'
overlay_path = data_overlay[1] if data_overlay else None
# The generated overlay is recreated every run even when byte-identical; its
# timestamp must not flush the native-doc object cache.
header_roots = [ROOT / 'rebuild/2008-06/native-headers']
header_stamp = max((p.stat().st_mtime_ns for root in header_roots if root.exists()
                    for p in root.rglob('*') if p.is_file() and p.suffix.lower() in ('.c', '.cc', '.cpp', '.h', '.hpp')),
                   default=0)
def cache_key(source, flags):
    return {'source': str(source.resolve()), 'source_mtime': source.stat().st_mtime_ns,
            'headers_mtime': header_stamp,
            'flags': hashlib.sha256('\0'.join(flags).encode()).hexdigest()}
def restore_cached(name, key, target=None):
    artifact, receipt = cache_dir / name, cache_dir / (name + '.json')
    if not (NATIVE_DOC and NATIVE_DOC_CACHE and artifact.exists() and receipt.exists()):
        return False
    if json.loads(receipt.read_text()) != key:
        return False
    shutil.copyfile(artifact, out / (target or name))
    return True
def store_cached(name, key, source=None):
    if NATIVE_DOC and NATIVE_DOC_CACHE:
        cache_dir.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(out / (source or name), cache_dir / name)
        (cache_dir / (name + '.json')).write_text(json.dumps(key, sort_keys=True))
data_flags = data_defines.split() + [engine["flags"]]
data_key = cache_key(HERE / 'P6Data.cpp', data_flags)
if not restore_cached('CoreP6Data.obj', data_key, 'P6Data.obj'):
    built = rebuild.compile_direct(client, [HERE / "P6Data.cpp"], out, data_includes, data_defines, engine["flags"],
                                   overlay=data_overlay)
    for ok, message in built.values():
        print(message[-2500:] if message else "")
        if not ok:
            sys.exit(1)
    store_cached('CoreP6Data.obj', data_key, 'P6Data.obj')

for obj, source, flags in units:
    key = cache_key(source, flags)
    cache_name = 'Core-' + obj
    if restore_cached(cache_name, key, obj):
        continue
    code, text = rebuild.run(tc, "cl", flags + ["/Fo" + obj, str(source)], out)
    print(text[-2500:])
    if code:
        sys.exit(code)
    store_cached(cache_name, key, obj)
if NATIVE_DOC:
    doc_flags = mfc_flags + ["/D" + d for d in data_defines.split()] + ["/I" + str(ROOT / 'rebuild/2008-06/native-headers'), "/I" + str(HERE)] + ["/I" + str(i) for i in includes]
    doc_sources = [('NativeCRobloxDoc.obj', ROOT / 'rebuild/2008-06/native-classes/CRobloxDoc.cpp'),
                        ('NativeActiveDocumentDataFull.obj', ROOT / 'rebuild/2008-06/native-classes/ActiveDocumentData.cpp'),
                        ('NativeStandardVerbs.obj', ROOT / 'rebuild/2008-06/native-classes/StandardVerbs.cpp'),
                        ('NativeSelectionVerbConstructorsFull.obj', ROOT / 'rebuild/2008-06/native-classes/SelectionVerbConstructors.cpp'),
                        ('NativeSelectionVerbStatesFull.obj', ROOT / 'rebuild/2008-06/native-classes/SelectionVerbStates.cpp'),
                        ('NativeDocumentExceptionFull.obj', ROOT / 'rebuild/2008-06/native-classes/DocumentException.cpp'),
                        ('NativeDocumentLoadFileFull.obj', ROOT / 'rebuild/2008-06/native-classes/DocumentLoadFile.cpp'),
                        ('NativeDocumentLoadFromStringFull.obj', ROOT / 'rebuild/2008-06/native-classes/DocumentLoadFromString.cpp'),
                        ('NativeDocumentInsertModelFull.obj', ROOT / 'rebuild/2008-06/native-classes/DocumentInsertModel.cpp'),
                        ('NativeDocumentExecuteFull.obj', ROOT / 'rebuild/2008-06/native-classes/DocumentExecute.cpp'),
                        ('NativeDocumentLDrawFull.obj', ROOT / 'rebuild/2008-06/native-classes/DocumentLDraw.cpp'),
                        ('NativeDocumentLaunchFull.obj', ROOT / 'rebuild/2008-06/native-classes/DocumentLaunch.cpp'),
                        ('NativeFileSystemFull.obj', ROOT / 'rebuild/2008-06/native-classes/FileSystem.cpp'),
                        ('NativeContentProviderFull.obj', ROOT / 'rebuild/2008-06/native-classes/ContentProvider.cpp'),
                        ('NativeLDrawParserLifetimeFull.obj', ROOT / 'rebuild/2008-06/tests/NativeLDrawParserLifetimeTrial.cpp'),
                        ('NativeDocumentInitializeFull.obj', ROOT / 'rebuild/2008-06/native-classes/DocumentInitialize.cpp'),
                        ('NativeWorkspaceFactoryFull.obj', ROOT / 'rebuild/2008-06/native-classes/WorkspaceFactory.cpp'),
                        ('NativeWorkspaceGuidsFull.obj', ROOT / 'rebuild/2008-06/native-classes/WorkspaceGuids.cpp'),
                        ('NativeWorkspaceFinalConstructFull.obj', ROOT / 'rebuild/2008-06/native-classes/WorkspaceFinalConstruct.cpp'),
                        ('NativeDataModelCreateFull.obj', ROOT / 'rebuild/2008-06/native-classes/DataModelCreate.cpp'),
                        ('NativeDataModelInitializeFull.obj', ROOT / 'rebuild/2008-06/native-classes/DataModelInitialize.cpp'),
                        ('NativeWorkspaceEventsFull.obj', ROOT / 'rebuild/2008-06/native-classes/WorkspaceEvents.cpp'),
                        ('NativeWorkspaceCloseFull.obj', ROOT / 'rebuild/2008-06/native-classes/WorkspaceClose.cpp'),
                        ('NativeWorkspaceInsertUrlFull.obj', ROOT / 'rebuild/2008-06/native-classes/WorkspaceInsertUrl.cpp'),
                        ('NativeWorkspaceSaveFull.obj', ROOT / 'rebuild/2008-06/native-classes/CWorkspaceSave.cpp'),
                        ('NativeWorkspaceWriteFull.obj', ROOT / 'rebuild/2008-06/native-classes/WorkspaceWrite.cpp'),
                        ('NativeWorkspaceExecScriptHelperFull.obj', ROOT / 'rebuild/2008-06/native-classes/CWorkspaceExecScriptHelper.cpp'),
                        ('NativeWorkspaceExecUrlFull.obj', ROOT / 'rebuild/2008-06/native-classes/WorkspaceExecUrl.cpp'),
                        ('NativeWorkspaceExecScriptFull.obj', ROOT / 'rebuild/2008-06/native-classes/CWorkspaceExecScript.cpp'),
                        ('NativeWorkspaceSelectionFull.obj', ROOT / 'rebuild/2008-06/native-classes/CWorkspaceSelection.cpp'),
                        ('NativeWorkspaceRaiseErrorFull.obj', ROOT / 'rebuild/2008-06/native-classes/WorkspaceRaiseError.cpp'),
                        ('NativeContentGuidsFull.obj', ROOT / 'rebuild/2008-06/native-classes/CContentGuids.cpp'),
                        ('NativeSafeArrayFull.obj', ROOT / 'rebuild/2008-06/native-classes/SafeArray.cpp'),
                        ('NativeValueConverterFull.obj', ROOT / 'rebuild/2008-06/native-classes/ValueConverter.cpp'),
                        ('NativeLuaArgsFull.obj', ROOT / 'rebuild/2008-06/native-classes/LuaArgs.cpp'),
                        ('NativeContentUploadFull.obj', ROOT / 'rebuild/2008-06/native-classes/CContentUpload.cpp'),
                        ('NativeContentErrorFull.obj', ROOT / 'rebuild/2008-06/native-classes/CContentError.cpp'),
                        ('NativeWorkspaceLoadFull.obj', ROOT / 'rebuild/2008-06/native-classes/CWorkspaceLoad.cpp'),
                        ('NativeWorkspaceObjectSafetyFull.obj', ROOT / 'rebuild/2008-06/native-classes/CWorkspaceObjectSafety.cpp'),
                        ('NativeWorkspaceSiteCheckFull.obj', ROOT / 'rebuild/2008-06/native-classes/CWorkspaceSiteCheck.cpp'),
                        ('NativeWorkspaceSiteUrlFull.obj', ROOT / 'rebuild/2008-06/native-classes/CWorkspaceSiteUrl.cpp'),
                        ('NativeWorkspaceHResultFull.obj', ROOT / 'rebuild/2008-06/native-classes/WorkspaceHResult.cpp'),
                        ('NativeWorkspaceErrorFull.obj', ROOT / 'rebuild/2008-06/native-classes/WorkspaceSiteError.cpp'),
                        ('NativeWorkspaceStatusFull.obj', ROOT / 'rebuild/2008-06/native-classes/WorkspaceStatus.cpp'),
                        ('NativeAtlErrorCoreFull.obj', ROOT / 'rebuild/2008-06/native-classes/AtlErrorCore.cpp'),
                        ('NativeWorkspaceGetWorkspaceFull.obj', ROOT / 'rebuild/2008-06/native-classes/WorkspaceGetWorkspace.cpp'),
                        ('NativeContentProviderServiceFull.obj', ROOT / 'rebuild/2008-06/tests/NativeContentProviderServiceTrial.cpp'),
                        ('NativeCameraHistoryFull.obj', ROOT / 'rebuild/2008-06/native-classes/CameraHistory.cpp'),
                        ('NativeCameraCenterCommandFull.obj', ROOT / 'rebuild/2008-06/native-classes/CameraCenterCommand.cpp'),
                        ('NativeChangeHistoryCommitFull.obj', ROOT / 'rebuild/2008-06/native-classes/ChangeHistoryCommit.cpp'),
                        ('NativeExitCommandFull.obj', ROOT / 'rebuild/2008-06/native-classes/ExitCommand.cpp'),
                        ('NativeClassNamesFull.obj', ROOT / 'rebuild/2008-06/native-classes/NativeClassNames.cpp'),
                        ('NativeWorkspaceSharedFromFull.obj', ROOT / 'rebuild/2008-06/native-classes/WorkspaceSharedFrom.cpp'),
                        ('NativeEditSelectionVerbCtorFull.obj', ROOT / 'rebuild/2008-06/native-classes/EditSelectionVerbConstructor.cpp'),
                        ('NativeRunStateVerbCtorFull.obj', ROOT / 'rebuild/2008-06/native-classes/RunStateVerbConstructor.cpp'),
                        ('NativeSoundServicePlayFull.obj', ROOT / 'rebuild/2008-06/native-classes/SoundServicePlay.cpp'),
                        ('NativeCameraUnitsFull.obj', ROOT / 'rebuild/2008-06/native-classes/CameraUnits.cpp'),
                        ('NativeCameraConstantsFull.obj', ROOT / 'rebuild/2008-06/native-classes/CameraConstants.cpp'),
                        ('NativeFilteredSelectionServiceFull.obj', ROOT / 'rebuild/2008-06/native-classes/FilteredSelectionService.cpp'),
                        ('NativeInstanceLifetimeFull.obj', ROOT / 'rebuild/2008-06/native-classes/InstanceLifetime.cpp'),
                        ('NativeInstanceCallbacksFull.obj', ROOT / 'rebuild/2008-06/native-classes/InstanceBaseCallbacks.cpp'),
                        ('NativeInstanceDescendantsFull.obj', ROOT / 'rebuild/2008-06/native-classes/InstanceDescendantEvents.cpp'),
                        ('NativeInstanceAncestorFull.obj', ROOT / 'rebuild/2008-06/native-classes/InstanceAncestorChangedNative.cpp'),
                        ('NativeInstanceChildListenerFull.obj', ROOT / 'rebuild/2008-06/native-classes/InstanceChildListener.cpp'),
                        ('NativeInstanceReadPropertyFull.obj', ROOT / 'rebuild/2008-06/native-classes/InstanceReadProperty.cpp'),
                        ('NativeInstanceSerializationFull.obj', ROOT / 'rebuild/2008-06/native-classes/InstanceSerialization.cpp'),
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
                        ('NativeHistoryItemPropertyFull.obj', ROOT / 'rebuild/2008-06/native-classes/HistoryItemPropertyTrial.cpp')]
    extra_sources = [Path(p) for p in os.environ.get('ROC_NATIVE_DOC_EXTRA', '').split(';') if p]
    for index, source in enumerate(extra_sources):
        assert source.is_file(), source
        doc_sources.append(('NativeDocExtra%02d.obj' % index, source))
    # Native-Doc closure probes change one source at a time. Cache only these
    # objects; key covers source, common native headers, overlay and flags.
    # Opt-in: normal diagnostic builds stay fully fresh.
    # Cache shared across isolated probe directories. Artifacts are immutable
    # once their source/header/flag stamp matches.
    for obj, source in doc_sources:
        source_flags = doc_flags + (['/DNATIVE_FILE_SYSTEM_APPDATA_ONLY'] if obj == 'NativeFileSystemFull.obj' else [])
        pinned = re.search(r'^// native-flags: (.*)$', source.read_text(encoding='utf-8-sig', errors='replace'), re.M)
        if pinned:
            source_flags = ['/nologo', '/c'] + pinned.group(1).replace('{headers}', str(ROOT / 'rebuild/2008-06/native-headers')).split()
            source_flags += ['/DBOOST_ALL_NO_LIB', '/D_XTP_STATICLINK', '/D_XTPLIB_NOAUTOLINK'] + ['/D' + d for d in data_defines.split()]
            source_flags += ['/I' + str(ROOT / 'rebuild/2008-06/native-headers'), '/I' + str(mfc), '/I' + str(xtp)]
            source_flags += ['/I' + str(i) for i in includes]
        key = cache_key(source, source_flags)
        cache_name = obj
        if obj.startswith('NativeDocExtra'):
            cache_name += '-' + hashlib.sha256(str(source.resolve()).encode()).hexdigest()[:12]
        if restore_cached(cache_name, key, obj):
            continue
        code, text = rebuild.run(tc, 'cl', source_flags + ['/Fo' + obj, str(source)], out)
        print(text[-2500:])
        if code:
            sys.exit(code)
        store_cached(cache_name, key, obj)
system = ["gdiplus", "kernel32", "user32", "gdi32", "advapi32", "shell32", "ole32", "oleaut32", "comdlg32", "comctl32", "ws2_32", "winmm",
          "opengl32", "glu32", "imagehlp", "version", "wininet", "dbghelp", "psapi"]
output_name = 'RobloxNativeDoc' if NATIVE_DOC else 'Roblox'
native_doc_objects = ['NativeCRobloxDoc.obj', 'NativeActiveDocumentDataFull.obj', 'NativeStandardVerbs.obj', 'NativeSelectionVerbConstructorsFull.obj', 'NativeSelectionVerbStatesFull.obj',
                      'NativeDocumentExceptionFull.obj', 'NativeDocumentLoadFileFull.obj', 'NativeDocumentLoadFromStringFull.obj',
                      'NativeDocumentInsertModelFull.obj', 'NativeDocumentExecuteFull.obj', 'NativeDocumentLDrawFull.obj', 'NativeDocumentLaunchFull.obj', 'NativeFileSystemFull.obj', 'NativeContentProviderFull.obj',
                      'NativeLDrawParserLifetimeFull.obj',
                      'NativeDocumentInitializeFull.obj', 'NativeVerbFull.obj',
                      'NativeWorkspaceFactoryFull.obj',
                      'NativeWorkspaceGuidsFull.obj', 'NativeWorkspaceFinalConstructFull.obj', 'NativeDataModelCreateFull.obj', 'NativeDataModelInitializeFull.obj',
                      'NativeWorkspaceEventsFull.obj',
                      'NativeWorkspaceCloseFull.obj',
                      'NativeWorkspaceInsertUrlFull.obj',
                      'NativeWorkspaceSaveFull.obj',
                      'NativeWorkspaceWriteFull.obj',
                      'NativeWorkspaceExecScriptHelperFull.obj',
                      'NativeWorkspaceExecUrlFull.obj',
                      'NativeWorkspaceExecScriptFull.obj',
                      'NativeWorkspaceSelectionFull.obj', 'NativeWorkspaceRaiseErrorFull.obj',
                      'NativeContentGuidsFull.obj', 'NativeSafeArrayFull.obj', 'NativeValueConverterFull.obj',
                      'NativeLuaArgsFull.obj',
                      'NativeContentUploadFull.obj',
                      'NativeContentErrorFull.obj',
                      'NativeWorkspaceLoadFull.obj',
                      'NativeWorkspaceObjectSafetyFull.obj',
                      'NativeWorkspaceSiteCheckFull.obj', 'NativeWorkspaceSiteUrlFull.obj', 'NativeWorkspaceHResultFull.obj',
                      'NativeWorkspaceErrorFull.obj', 'NativeWorkspaceStatusFull.obj', 'NativeAtlErrorCoreFull.obj',
                      'NativeWorkspaceGetWorkspaceFull.obj',
                      'NativeContentProviderServiceFull.obj',
                      'NativeCameraHistoryFull.obj', 'NativeCameraCenterCommandFull.obj',
                      'NativeChangeHistoryCommitFull.obj',
                      'NativeExitCommandFull.obj',
                      'NativeClassNamesFull.obj',
                      'NativeWorkspaceSharedFromFull.obj',
                      'NativeEditSelectionVerbCtorFull.obj',
                      'NativeRunStateVerbCtorFull.obj',
                      'NativeSoundServicePlayFull.obj',
                      'NativeCameraUnitsFull.obj', 'NativeCameraConstantsFull.obj',
                      'NativeFilteredSelectionServiceFull.obj',
                      'NativeInstanceLifetimeFull.obj', 'NativeInstanceCallbacksFull.obj',
                      'NativeInstanceDescendantsFull.obj', 'NativeInstanceAncestorFull.obj',
                      'NativeInstanceChildListenerFull.obj', 'NativeInstanceReadPropertyFull.obj',
                      'NativeInstanceSerializationFull.obj',
                      'NativeVerbLifetimeFull.obj', 'NativeVerbBaseLifetimeFull.obj', 'NativeVerbQueriesFull.obj',
                      'NativeContentProviderUrlFull.obj', 'NativeServiceLookupFull.obj', 'NativeHistoryRecordPlaybackFull.obj',
                      'NativeChangeHistoryPlaybackFull.obj', 'NativeChangeHistoryQueriesFull.obj',
                      'NativeChangeHistoryEnableFull.obj', 'NativeChangeHistoryResetFull.obj', 'NativeSelectionFrontFull.obj', 'NativeInstanceClassLookupFull.obj',
                      'NativeHistoryRecordLifetimeFull.obj', 'NativeHistoryItemPlaybackFull.obj',
                      'NativeHistoryItemPropertyFull.obj'] if NATIVE_DOC else []
if NATIVE_DOC:
    native_doc_objects += ['NativeDocExtra%02d.obj' % index for index, _ in enumerate(extra_sources)]
    native_doc_objects += [str(ROOT / 'rebuild/2008-06/out/native-layouts' / name) for name in (
        'NativeSaveDialogProfile.obj', 'NativeApplicationBaseUrl.obj',
        'NativeWorkspaceLayout.obj', 'ServiceChangeHistoryCreate.obj',
        'ServiceChangeHistoryProfile.obj',
        'NativeVisitFindProfile.obj',
        'ServiceSelectionProfile.obj',
        'NativeDataModelTiming.obj', 'NativeDataModelDutyCycle.obj',
        'NativeLuaAllocatorStats.obj', 'NativePlayersAbuse.obj', 'WorkspaceInsertNativeProfile.obj',
        'WorkspaceSiteTrustProfile.obj')]
native_doc_aliases = ['/alternatename:?createNativeWorkspace@@YGJPAPAVCWorkspace@@@Z=?CreateInstance@?$CComObject@VCWorkspace@@@ATL@@SGJPAPAV12@@Z'] if NATIVE_DOC else []
native_doc_verbose = ['/VERBOSE:LIB'] if NATIVE_DOC and os.environ.get('ROC_NATIVE_DOC_VERBOSE_LIB') else []
code, text = rebuild.run(tc, "link", ["/nologo", "/SUBSYSTEM:WINDOWS", "/MACHINE:X86", "/MAP:" + output_name + ".map", "/OUT:" + output_name + ".exe",
                                      "/NODEFAULTLIB:mfcs90.lib", "/MANIFEST:NO"] + native_doc_aliases + native_doc_verbose + [u[0] for u in units] + [str(ROOT / "rebuild/2008-06/out/native-layouts" / name) for name in ("NativeFrameIconsFresh.obj", "NativeFrameIconWidth.obj", "NativeDHtmlDialog.obj", "NativeAboutDialog.obj", "NativeAboutDialogData.obj", "NativeFileVersionInfo.obj", "NativeGLCaps.obj")] + ["P6Data.obj", "roblox.res", "mfc90.lib"]
                         + native_doc_objects
                         + [str(l) for l in libs] + [s + ".lib" for s in system]
                         + ["/NODEFAULTLIB:" + l for l in rebuild.VENDOR_AUTOLINK], out)
if NATIVE_DOC:
    (out/'native-doc-link.log').write_text(text)
    unresolved = sorted(set(re.findall(r'unresolved external symbol "([^"]+)"', text)))
    duplicates = sorted(set(re.findall(r'error LNK2005: "([^"]+)"', text)))
    families = {}
    for symbol in unresolved:
        family = next((name for name, token in (
            ('standard_verbs', 'Verb'), ('instance_vtable', 'Instance::'),
            ('change_history', 'ChangeHistory'), ('content_provider', 'ContentProvider'),
            ('filtered_selection', 'FilteredSelection'), ('ldraw', 'LDraw'),
            ('camera', 'Camera'), ('document', 'documentUrl'), ('workspace', 'Workspace')) if token in symbol), 'other')
        families[family] = families.get(family, 0) + 1
    (out/'native-doc-closure.json').write_text(json.dumps({
        'link_exit': code,
        'lnk_error_lines': len(re.findall(r'error LNK', text)),
        'unique_unresolved': len(unresolved),
        'duplicate_symbols': duplicates,
        'clean_link': code == 0,
        'families': families,
        'symbols': unresolved,
        'selected_source_objects': native_doc_objects,
    }, indent=2) + '\n')
print(text[-3500:])
sys.exit(code)
