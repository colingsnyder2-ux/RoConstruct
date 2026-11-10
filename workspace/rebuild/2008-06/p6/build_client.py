"""Link out/p6/Roblox.exe: MFC client, RTM appmodul.cpp, original resources, and
the player's engine libraries from this worktree's own player build."""
import hashlib, json, os, re, shutil, subprocess, sys
from concurrent.futures import ThreadPoolExecutor
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
header_root = (ROOT / 'rebuild/2008-06/native-headers').resolve()
def native_deps(source):
    pending, seen = [source.resolve()], set()
    while pending:
        path = pending.pop()
        if path in seen or not path.exists():
            continue
        seen.add(path)
        for name in re.findall(r'^\s*#include\s+"([^"]+)"', path.read_text(errors='replace'), re.M):
            local, native = (path.parent / name).resolve(), (header_root / name).resolve()
            child = local if local.exists() else native
            if child.exists() and (str(child).startswith(str(header_root)) or child.parent == path.parent):
                pending.append(child)
    return sorted([str(path.relative_to(ROOT)) if str(path).startswith(str(ROOT)) else str(path), hashlib.sha256(path.read_bytes()).hexdigest()]
                  for path in seen)
def cache_key(source, flags):
    key = {'schema': 2, 'source': str(source.resolve()),
           'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(),
           'native_deps': native_deps(source),
           'flags': hashlib.sha256('\0'.join(flags).encode()).hexdigest()}
    # Angle includes can select per-source STL/MFC overrides. Track those
    # directories without invalidating every object for unrelated native headers.
    profile_headers = set()
    for flag in flags:
        if flag.lower().startswith('/i'):
            folder = Path(flag[2:].strip('"')).resolve()
            if folder != header_root and folder.is_relative_to(header_root) and folder.is_dir():
                profile_headers.update(path for path in folder.rglob('*') if path.is_file())
    if profile_headers:
        key['native_profile_headers'] = [[str(path.relative_to(ROOT)), hashlib.sha256(path.read_bytes()).hexdigest()]
                                         for path in sorted(profile_headers)]
    return key
def cache_paths(name, key):
    variant = hashlib.sha256(json.dumps(key, sort_keys=True).encode()).hexdigest()
    folder = cache_dir / 'variants' / variant
    return folder / name, folder / (name + '.json')

def restore_cached(name, key, target=None):
    artifact, receipt = cache_paths(name, key)
    if not (NATIVE_DOC and NATIVE_DOC_CACHE and artifact.exists() and receipt.exists()):
        return False
    try:
        recorded = json.loads(receipt.read_text())
    except (OSError, ValueError):
        return False
    if recorded != key:
        return False
    shutil.copyfile(artifact, out / (target or name))
    return True
def store_cached(name, key, source=None):
    if NATIVE_DOC and NATIVE_DOC_CACHE:
        artifact, receipt = cache_paths(name, key)
        artifact.parent.mkdir(parents=True, exist_ok=True)
        pending = artifact.with_name(artifact.name + '.tmp-' + str(os.getpid()))
        shutil.copyfile(out / (source or name), pending)
        os.replace(pending, artifact)
        pending = receipt.with_name(receipt.name + '.tmp-' + str(os.getpid()))
        pending.write_text(json.dumps(key, sort_keys=True))
        os.replace(pending, receipt)
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
                        ('NativeStatsCommandsFull.obj', ROOT / 'rebuild/2008-06/native-classes/StatsCommands.cpp'),
                        ('NativeToolVerbCoreFull.obj', ROOT / 'rebuild/2008-06/native-classes/ToolVerbCore.cpp'),
                        ('NativeToolVerbFactoriesFull.obj', ROOT / 'rebuild/2008-06/native-classes/ToolVerbFactories.cpp'),
                        ('NativeToolVerbCheckedSurfaceFull.obj', ROOT / 'rebuild/2008-06/native-classes/ToolVerbCheckedSurface.cpp'),
                        ('NativeToolVerbCheckedModelFull.obj', ROOT / 'rebuild/2008-06/native-classes/ToolVerbCheckedModel.cpp'),
                        ('NativeToolVerbCheckedExistingFull.obj', ROOT / 'rebuild/2008-06/native-classes/ToolVerbCheckedExisting.cpp'),
                        ('NativeToolVerbCheckedBasicFull.obj', ROOT / 'rebuild/2008-06/native-classes/ToolVerbCheckedBasic.cpp'),
                        ('NativeToolVerbCheckedShootFull.obj', ROOT / 'rebuild/2008-06/native-classes/ToolVerbCheckedShoot.cpp'),
                        ('NativeToolVerbCheckedResizeFull.obj', ROOT / 'rebuild/2008-06/native-classes/ToolVerbCheckedResize.cpp'),
                        ('NativeToolVerbCheckedAxisFull.obj', ROOT / 'rebuild/2008-06/native-classes/ToolVerbCheckedAxis.cpp'),
                        ('NativeCameraFirstPersonFull.obj', ROOT / 'rebuild/2008-06/native-classes/CameraFirstPerson.cpp'),
                        ('NativeCameraZoomExtentsActionFull.obj', ROOT / 'rebuild/2008-06/native-classes/CameraZoomExtentsAction.cpp'),
                        ('NativeBasicVerbConstructorsFull.obj', ROOT / 'rebuild/2008-06/native-classes/BasicVerbConstructors.cpp'),
                        ('NativeClearBackpackFull.obj', ROOT / 'rebuild/2008-06/native-classes/ClearBackpack.cpp'),
                        ('NativeClearStarterpackFull.obj', ROOT / 'rebuild/2008-06/native-classes/ClearStarterpack.cpp'),
                        ('NativeSelectionBackFull.obj', ROOT / 'rebuild/2008-06/native-classes/SelectionBack.cpp'),
                        ('NativeJoinCommandFull.obj', ROOT / 'rebuild/2008-06/native-classes/JoinCommand.cpp'),
                        ('NativeSelectionVerbConstructorsFull.obj', ROOT / 'rebuild/2008-06/native-classes/SelectionVerbConstructors.cpp'),
                        ('NativeSelectionVerbStatesFull.obj', ROOT / 'rebuild/2008-06/native-classes/SelectionVerbStates.cpp'),
                        ('NativeBoolPropertyVerbFull.obj', ROOT / 'rebuild/2008-06/native-classes/BoolPropertyVerb.cpp'),
                        ('NativeDuplicateSelectionVerbFull.obj', ROOT / 'rebuild/2008-06/native-classes/DuplicateSelectionVerb.cpp'),
                        ('NativeWeldSnapActionsFull.obj', ROOT / 'rebuild/2008-06/native-classes/WeldSnapActions.cpp'),
                        ('NativeSurfaceVisitorsFull.obj', ROOT / 'rebuild/2008-06/native-classes/SurfaceVisitors.cpp'),
                        ('NativeMoveUpSelectionVerbFull.obj', ROOT / 'rebuild/2008-06/native-classes/MoveUpSelectionVerb.cpp'),
                        ('NativeMoveDownSelectionVerbFull.obj', ROOT / 'rebuild/2008-06/native-classes/MoveDownSelectionVerb.cpp'),
                        ('NativeUngroupOperationFull.obj', ROOT / 'rebuild/2008-06/native-classes/UngroupOperation.cpp'),
                        ('NativeUngroupSelectionVerbFull.obj', ROOT / 'rebuild/2008-06/native-classes/UngroupSelectionVerb.cpp'),
                        ('NativePartInstanceLockedFull.obj', ROOT / 'rebuild/2008-06/native-classes/PartInstanceLocked.cpp'),
                        ('NativeRunStateCommandsFull.obj', ROOT / 'rebuild/2008-06/native-classes/RunStateCommands.cpp'),
                        ('NativeGroupSelectionVerbFull.obj', ROOT / 'rebuild/2008-06/native-classes/GroupSelectionVerb.cpp'),
                        ('NativeDocumentExceptionFull.obj', ROOT / 'rebuild/2008-06/native-classes/DocumentException.cpp'),
                        ('NativeSaveDialogFull.obj', ROOT / 'rebuild/2008-06/native-classes/CSaveToRobloxDialog.cpp'),
                        ('NativeDocumentLoadFileFull.obj', ROOT / 'rebuild/2008-06/native-classes/DocumentLoadFile.cpp'),
                        ('NativeScriptFileLoadFull.obj', ROOT / 'rebuild/2008-06/native-classes/ScriptFileLoad.cpp'),
                        ('NativeDocumentLoadFromStringFull.obj', ROOT / 'rebuild/2008-06/native-classes/DocumentLoadFromString.cpp'),
                        ('NativeDocumentInsertModelFull.obj', ROOT / 'rebuild/2008-06/native-classes/DocumentInsertModel.cpp'),
                        ('NativeDocumentExecuteFull.obj', ROOT / 'rebuild/2008-06/native-classes/DocumentExecute.cpp'),
                        ('NativeDocumentLDrawFull.obj', ROOT / 'rebuild/2008-06/native-classes/DocumentLDraw.cpp'),
                        ('NativeDocumentLaunchFull.obj', ROOT / 'rebuild/2008-06/native-classes/DocumentLaunch.cpp'),
                        ('NativeFileSystemFull.obj', ROOT / 'rebuild/2008-06/native-classes/FileSystem.cpp'),
                        ('NativeContentProviderFull.obj', ROOT / 'rebuild/2008-06/native-classes/ContentProvider.cpp'),
                        ('NativeLDrawParserFull.obj', ROOT / 'rebuild/2008-06/native-classes/LDrawParser.cpp'),
                        ('NativeDocumentInitializeFull.obj', ROOT / 'rebuild/2008-06/native-classes/DocumentInitialize.cpp'),
                        ('NativeWorkspaceFactoryFull.obj', ROOT / 'rebuild/2008-06/native-classes/WorkspaceFactory.cpp'),
                        ('NativeWorkspaceGroupFull.obj', ROOT / 'rebuild/2008-06/native-classes/WorkspaceGroup.cpp'),
                        ('NativeWorkspaceSelectAllFull.obj', ROOT / 'rebuild/2008-06/native-classes/WorkspaceSelectAll.cpp'),
                        ('NativeWorkspaceGuidsFull.obj', ROOT / 'rebuild/2008-06/native-classes/WorkspaceGuids.cpp'),
                        ('NativeWorkspaceFinalConstructFull.obj', ROOT / 'rebuild/2008-06/native-classes/WorkspaceFinalConstruct.cpp'),
                        ('NativeDataModelCreateFull.obj', ROOT / 'rebuild/2008-06/native-classes/DataModelCreate.cpp'),
                        ('NativeDataModelInitializeFull.obj', ROOT / 'rebuild/2008-06/native-classes/DataModelInitialize.cpp'),
                        ('NativeWorkspaceEventsFull.obj', ROOT / 'rebuild/2008-06/native-classes/WorkspaceEvents.cpp'),
                        ('NativeWorkspaceCloseFull.obj', ROOT / 'rebuild/2008-06/native-classes/WorkspaceClose.cpp'),
                        ('NativeWorkspaceInsertUrlFull.obj', ROOT / 'rebuild/2008-06/native-classes/WorkspaceInsertUrl.cpp'),
                        ('NativeWorkspaceSaveFull.obj', ROOT / 'rebuild/2008-06/native-classes/CWorkspaceSave.cpp'),
                        ('NativeWorkspaceWriteFull.obj', ROOT / 'rebuild/2008-06/native-classes/WorkspaceWrite.cpp'),
                        ('NativeWorkspaceXmlWriterFull.obj', ROOT / 'rebuild/2008-06/native-classes/WorkspaceXmlWriter.cpp'),
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
                        ('NativeFilteredSelectionFactoryFull.obj', ROOT / 'rebuild/2008-06/native-classes/FilteredSelectionFactory.cpp'),
                        ('NativeFilteredSelectionMethodsFull.obj', ROOT / 'rebuild/2008-06/native-classes/FilteredSelectionMethods.cpp'),
                        ('NativeGuidItemFull.obj', ROOT / 'rebuild/2008-06/native-classes/GuidItem.cpp'),
                        ('NativeGuidRegistryMutexFull.obj', ROOT / 'rebuild/2008-06/native-classes/GuidRegistryMutex.cpp'),
                        ('NativeGuidRegistryInitializeFull.obj', ROOT / 'rebuild/2008-06/native-classes/GuidRegistryInitialize.cpp'),
                        ('NativeGuidRegistryConstructorFull.obj', ROOT / 'rebuild/2008-06/native-classes/GuidRegistryConstructor.cpp'),
                        ('NativeGuidRegistryCriticalSectionFull.obj', ROOT / 'rebuild/2008-06/native-classes/GuidRegistryCriticalSection.cpp'),
                        ('NativeServiceSelectionFull.obj', ROOT / 'rebuild/2008-06/native-classes/ServiceSelection.cpp'),
                        ('NativeServiceChangeHistoryFull.obj', ROOT / 'rebuild/2008-06/native-classes/ServiceChangeHistory.cpp'),
                        ('NativeApplicationBaseUrlFull.obj', ROOT / 'rebuild/2008-06/native-classes/ApplicationBaseUrl.cpp'),
                        ('NativeDataModelTimingFull.obj', ROOT / 'rebuild/2008-06/native-classes/DataModelTiming.cpp'),
                        ('NativeDataModelDutyCycleFull.obj', ROOT / 'rebuild/2008-06/native-classes/DataModelDutyCycle.cpp'),
                        ('NativeLuaAllocatorStatsFull.obj', ROOT / 'rebuild/2008-06/native-classes/LuaAllocatorStats.cpp'),
                        ('NativePlayersAbuseFull.obj', ROOT / 'rebuild/2008-06/native-classes/PlayersAbusePredicate.cpp'),
                        ('ServiceChangeHistoryCreateFull.obj', ROOT / 'rebuild/2008-06/native-classes/ServiceChangeHistory.cpp'),
                        ('NativeCWorkspaceFull.obj', ROOT / 'rebuild/2008-06/native-classes/CWorkspace.cpp'),
                        ('NativeVisitServiceLookupFull.obj', ROOT / 'rebuild/2008-06/native-classes/VisitServiceLookup.cpp'),
                        ('NativeInstanceLifetimeFull.obj', ROOT / 'rebuild/2008-06/native-classes/InstanceLifetime.cpp'),
                        ('NativeInstanceCallbacksFull.obj', ROOT / 'rebuild/2008-06/native-classes/InstanceBaseCallbacks.cpp'),
                        ('NativeInstanceDescendantsFull.obj', ROOT / 'rebuild/2008-06/native-classes/InstanceDescendantEvents.cpp'),
                        ('NativeInstanceAncestorFull.obj', ROOT / 'rebuild/2008-06/native-classes/InstanceAncestorChangedNative.cpp'),
                        ('NativeInstanceChildListenerFull.obj', ROOT / 'rebuild/2008-06/native-classes/InstanceChildListener.cpp'),
                        ('NativeInstanceReadPropertyFull.obj', ROOT / 'rebuild/2008-06/native-classes/InstanceReadProperty.cpp'),
                        ('NativeVerbFull.obj', ROOT / 'rebuild/2008-06/native-classes/Verb.cpp'),
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
                        ('NativeHistoryItemPropertyFull.obj', ROOT / 'rebuild/2008-06/native-classes/HistoryItemPropertyTrial.cpp'),
                        ('NativeAxisVerbConstructorsFull.obj', ROOT / 'rebuild/2008-06/native-classes/AxisVerbConstructors.cpp'),
                        ('NativeControllerActionsFull.obj', ROOT / 'rebuild/2008-06/native-classes/ControllerActions.cpp'),
                        ('NativeControllerEnabledFull.obj', ROOT / 'rebuild/2008-06/native-classes/ControllerEnabled.cpp'),
                        ('NativeControllerApplyFull.obj', ROOT / 'rebuild/2008-06/native-classes/ControllerApply.cpp'),
                        ('NativeTiltSelectionAxisFull.obj', ROOT / 'rebuild/2008-06/native-classes/TiltSelectionAxis.cpp'),
                        ('NativeRotateAxisActionFull.obj', ROOT / 'rebuild/2008-06/native-classes/RotateAxisAction.cpp'),
                        ('NativeMathTiltMatricesFull.obj', ROOT / 'rebuild/2008-06/native-classes/MathTiltMatrices.cpp'),
                        ('NativeMathTiltQuadrantFull.obj', ROOT / 'rebuild/2008-06/native-classes/MathTiltQuadrant.cpp'),
                        ('NativeSurfaceToolFull.obj', ROOT / 'rebuild/2008-06/native-classes/SurfaceTool.cpp'),
                        ('NativeFlatToolFull.obj', ROOT / 'rebuild/2008-06/native-classes/FlatTool.cpp'),
                        ('NativeSurfaceToolSiblingsFull.obj', ROOT / 'rebuild/2008-06/native-classes/SurfaceToolSiblings.cpp'),
                        ('NativeSurfaceToolFactoriesFull.obj', ROOT / 'rebuild/2008-06/native-classes/SurfaceToolFactories.cpp'),
                        ('NativeNullToolFull.obj', ROOT / 'rebuild/2008-06/native-classes/NullTool.cpp'),
                        ('NativeMouseCommandFull.obj', ROOT / 'rebuild/2008-06/native-classes/MouseCommand.cpp'),
                        ('NativeMouseCommandDistanceFull.obj', ROOT / 'rebuild/2008-06/native-classes/MouseCommandDistance.cpp'),
                        ('NativeModelToolFull.obj', ROOT / 'rebuild/2008-06/native-classes/ModelTool.cpp'),
                        ('NativeModelToolFactoriesFull.obj', ROOT / 'rebuild/2008-06/native-classes/ModelToolFactories.cpp'),
                        ('NativeAxisMoveToolCoreFull.obj', ROOT / 'rebuild/2008-06/native-classes/AxisMoveToolCore.cpp'),
                        ('NativeModelToolNamesFull.obj', ROOT / 'rebuild/2008-06/native-classes/ModelToolNames.cpp'),
                        ('NativeModelToolActionsFull.obj', ROOT / 'rebuild/2008-06/native-classes/ModelToolActions.cpp'),
                        ('NativeAnchorToolFull.obj', ROOT / 'rebuild/2008-06/native-classes/AnchorTool.cpp'),
                        ('NativeInstanceAnchorChildrenFull.obj', ROOT / 'rebuild/2008-06/native-classes/InstanceAnchorChildren.cpp'),
                        ('NativeWorkspaceFindTopInstanceFull.obj', ROOT / 'rebuild/2008-06/native-classes/WorkspaceFindTopInstance.cpp'),
                        ('NativeCloneToolFull.obj', ROOT / 'rebuild/2008-06/native-classes/CloneTool.cpp'),
                        ('NativeHammerToolFull.obj', ROOT / 'rebuild/2008-06/native-classes/HammerTool.cpp'),
                        ('NativeMouseUnlockedFull.obj', ROOT / 'rebuild/2008-06/native-classes/MouseUnlocked.cpp'),
                        ('NativeGrabToolFull.obj', ROOT / 'rebuild/2008-06/native-classes/GrabTool.cpp'),
                        ('NativeGameToolFull.obj', ROOT / 'rebuild/2008-06/native-classes/GameTool.cpp'),
                        ('NativeGameToolDragFull.obj', ROOT / 'rebuild/2008-06/native-classes/GameToolDrag.cpp'),
                        ('NativeDragToolFull.obj', ROOT / 'rebuild/2008-06/native-classes/DragTool.cpp'),
                        ('NativeCollectDragPartsFull.obj', ROOT / 'rebuild/2008-06/native-classes/CollectDragParts.cpp'),
                        ('NativeSurfaceFlatFull.obj', ROOT / 'rebuild/2008-06/native-classes/SurfaceFlat.cpp'),
                        ('NativePartInstanceGetSurfaceFull.obj', ROOT / 'rebuild/2008-06/native-classes/PartInstanceGetSurface.cpp'),
                        ('NativePartInstanceLockedInPlaceFull.obj', ROOT / 'rebuild/2008-06/native-classes/PartInstanceLockedInPlace.cpp'),
                        ('NativeLaserToolFull.obj', ROOT / 'rebuild/2008-06/native-classes/LaserTool.cpp'),
                        ('NativePartToolFull.obj', ROOT / 'rebuild/2008-06/native-classes/PartTool.cpp'),
                        ('NativePartToolsFull.obj', ROOT / 'rebuild/2008-06/native-classes/PartTools.cpp'),
                        ('NativePartToolFactoriesFull.obj', ROOT / 'rebuild/2008-06/native-classes/PartToolFactories.cpp'),
                        ('NativeFillToolColorFull.obj', ROOT / 'rebuild/2008-06/native-classes/FillToolColor.cpp'),
                        ('NativePVInstanceTopParentFull.obj', ROOT / 'rebuild/2008-06/native-classes/PVInstanceTopParent.cpp'),
                        ('NativeModelSetFrontToolFull.obj', ROOT / 'rebuild/2008-06/native-classes/ModelSetFrontTool.cpp'),
                        ('NativeChangeHistoryStartFull.obj', ROOT / 'rebuild/2008-06/native-classes/ChangeHistoryStart.cpp'),
                        ('NativeWorldServiceFactoriesFull.obj', ROOT / 'rebuild/2008-06/native-classes/WorldServiceFactories.cpp'),
                        ('NativePhysicsServiceFull.obj', ROOT / 'rebuild/2008-06/native-classes/PhysicsService.cpp'),
                        ('NativePhysicsServiceProviderFull.obj', ROOT / 'rebuild/2008-06/native-classes/PhysicsServiceProvider.cpp'),
                        ('NativeJointsServiceFull.obj', ROOT / 'rebuild/2008-06/native-classes/JointsService.cpp'),
                        ('NativeSlingshotToolCoreFull.obj', ROOT / 'rebuild/2008-06/native-classes/SlingshotToolCore.cpp'),
                        ('NativeRocketToolCoreFull.obj', ROOT / 'rebuild/2008-06/native-classes/RocketToolCore.cpp'),
                        ('NativeRocketToolProjectileFull.obj', ROOT / 'rebuild/2008-06/native-classes/RocketToolProjectile.cpp'),
                        ('NativeRocketToolLaunchFull.obj', ROOT / 'rebuild/2008-06/native-classes/RocketToolLaunch.cpp'),
                        ('NativeEngineStatsFull.obj', ROOT / 'rebuild/2008-06/native-classes/EngineStats.cpp'),
                        ('NativeContactManagerStatsFull.obj', ROOT / 'rebuild/2008-06/native-classes/ContactManagerStats.cpp'),
                        ('NativeSpatialHashStatsFull.obj', ROOT / 'rebuild/2008-06/native-classes/SpatialHashStats.cpp'),
                        ('NativeShootToolMethodsFull.obj', ROOT / 'rebuild/2008-06/native-classes/ShootToolMethods.cpp'),
                        ('NativeShootToolShootFull.obj', ROOT / 'rebuild/2008-06/native-classes/ShootToolShoot.cpp'),
                        ('NativeSlingshotToolLaunchFull.obj', ROOT / 'rebuild/2008-06/native-classes/SlingshotToolLaunch.cpp'),
                        ('NativeSlingshotBallisticFull.obj', ROOT / 'rebuild/2008-06/native-classes/SlingshotBallistic.cpp'),
                        ('NativeSlingshotToolProjectileFull.obj', ROOT / 'rebuild/2008-06/native-classes/SlingshotToolProjectile.cpp'),
                        ('NativeContentProviderCreateContextFull.obj', ROOT / 'rebuild/2008-06/native-classes/ContentProviderCreateContext.cpp'),
                        ('NativeContentIdAssetsFull.obj', ROOT / 'rebuild/2008-06/native-classes/ContentIdAssets.cpp'),
                        ('NativeContentProviderLoadFull.obj', ROOT / 'rebuild/2008-06/native-classes/ContentProviderLoad.cpp'),
                        ('NativeResizeToolCoreFull.obj', ROOT / 'rebuild/2008-06/native-classes/ResizeToolCore.cpp'),
                        ('NativeResizeToolMethodsFull.obj', ROOT / 'rebuild/2008-06/native-classes/ResizeToolMethods.cpp'),
                        ('NativeResizeToolMoveFull.obj', ROOT / 'rebuild/2008-06/native-classes/ResizeToolMove.cpp'),
                        ('NativeResizeToolDragFull.obj', ROOT / 'rebuild/2008-06/native-classes/ResizeToolDrag.cpp'),
                        ('NativeResizeToolFindFull.obj', ROOT / 'rebuild/2008-06/native-classes/ResizeToolFind.cpp'),
                        ('NativeResizeToolRenderFull.obj', ROOT / 'rebuild/2008-06/native-classes/ResizeToolRender.cpp'),
                        ('NativeMathClosestRayFull.obj', ROOT / 'rebuild/2008-06/native-classes/MathClosestRay.cpp'),
                        ('NativeHandleHitTestFull.obj', ROOT / 'rebuild/2008-06/native-classes/HandleHitTest.cpp'),
                        ('NativePartInstanceResizeFull.obj', ROOT / 'rebuild/2008-06/native-classes/PartInstanceResize.cpp'),
                        ('NativeHandleRadiusFull.obj', ROOT / 'rebuild/2008-06/native-classes/HandleRadius.cpp'),
                        ('NativeCInsertObjectDialogCoreFull.obj', ROOT / 'rebuild/2008-06/native-classes/CInsertObjectDialogCore.cpp'),
                        ('NativeCInsertObjectDialogActionFull.obj', ROOT / 'rebuild/2008-06/native-classes/CInsertObjectDialogAction.cpp'),
                        ('NativeMetadataClassFull.obj', ROOT / 'rebuild/2008-06/native-classes/MetadataClass.cpp'),
                        ('NativeMetadataClassesLookupFull.obj', ROOT / 'rebuild/2008-06/native-classes/MetadataClassesLookup.cpp'),
                        ('NativeMetadataReflectionLookupFull.obj', ROOT / 'rebuild/2008-06/native-classes/MetadataReflectionLookup.cpp'),
                        ('NativeMetadataReflectionSingletonFull.obj', ROOT / 'rebuild/2008-06/native-classes/MetadataReflectionSingleton.cpp'),
                        ('NativeMetadataReflectionLifetimeFull.obj', ROOT / 'rebuild/2008-06/native-classes/MetadataReflectionLifetime.cpp'),
                        ('NativeMetadataReflectionLoadFull.obj', ROOT / 'rebuild/2008-06/native-classes/MetadataReflectionLoad.cpp'),
                        ('NativeMetadataClassNamesFull.obj', ROOT / 'rebuild/2008-06/native-classes/MetadataClassNames.cpp'),
                        ('NativeMetadataClassesRegisterFull.obj', ROOT / 'rebuild/2008-06/native-classes/MetadataClassesRegister.cpp'),
                        ('NativeMetadataItemLifetimeFull.obj', ROOT / 'rebuild/2008-06/native-classes/MetadataItemLifetime.cpp'),
                        ('NativeMotorFeatureCommandsFull.obj', ROOT / 'rebuild/2008-06/native-classes/MotorFeatureCommands.cpp'),
                        ('NativeArrowToolFactoryFull.obj', ROOT / 'rebuild/2008-06/native-classes/ArrowToolFactory.cpp'),
                        ('NativeDataModelClassNameFull.obj', ROOT / 'rebuild/2008-06/native-classes/DataModelClassName.cpp'),
                        ('NativeAuthoringSettingsFull.obj', ROOT / 'rebuild/2008-06/native-classes/AuthoringSettings.cpp'),
                        ('NativeCClassImagesFull.obj', ROOT / 'rebuild/2008-06/native-classes/CClassImages.cpp'),
                        ('NativeNameCompareFull.obj', ROOT / 'rebuild/2008-06/native-classes/NameCompare.cpp'),
                        ('NativeChangeHistoryLifetimeFull.obj', ROOT / 'rebuild/2008-06/native-classes/ChangeHistoryLifetime.cpp'),
                        ('NativeChangeHistoryEventsFull.obj', ROOT / 'rebuild/2008-06/native-classes/ChangeHistoryEvents.cpp'),
                        ('NativeChangeHistoryFactoryFull.obj', ROOT / 'rebuild/2008-06/native-classes/ChangeHistoryFactory.cpp'),
                        ('NativeHistoryRecordLookupFull.obj', ROOT / 'rebuild/2008-06/native-classes/HistoryRecordLookup.cpp'),
                        ('NativeHistoryItemStateFull.obj', ROOT / 'rebuild/2008-06/native-classes/HistoryItemState.cpp'),
                        ('NativeSurfaceToolHoverRenderFull.obj', ROOT / 'rebuild/2008-06/native-classes/SurfaceToolHoverRender.cpp'),
                        ('NativeSurfaceToolMouseDownFull.obj', ROOT / 'rebuild/2008-06/native-classes/SurfaceToolMouseDown.cpp'),
                        ('NativeMouseGetSurfaceFull.obj', ROOT / 'rebuild/2008-06/native-classes/MouseGetSurface.cpp'),
                        ('NativeInsertObjectActionFull.obj', ROOT / 'rebuild/2008-06/native-classes/InsertObjectAction.cpp'),
                        ('NativeInsertDecalActionFull.obj', ROOT / 'rebuild/2008-06/native-classes/InsertDecalAction.cpp'),
                        ('NativeImageMimeTypeFull.obj', ROOT / 'rebuild/2008-06/native-classes/ImageMimeType.cpp'),
                        ('NativeImageContentRegistrationFull.obj', ROOT / 'rebuild/2008-06/native-classes/ImageContentRegistration.cpp'),
                        ('NativeClipboardActionsFull.obj', ROOT / 'rebuild/2008-06/native-classes/ClipboardActions.cpp'),
                        ('NativeLDrawPathFull.obj', ROOT / 'rebuild/2008-06/native-classes/LDrawPath.cpp'),
                        ('NativeLDrawAssetStateFull.obj', ROOT / 'rebuild/2008-06/native-classes/LDrawAssetState.cpp'),
                        ('NativeLDrawMapRootConstructorFull.obj', ROOT / 'rebuild/2008-06/native-classes/LDrawMapRootConstructor.cpp'),
                        ('NativeLDrawMapRootLifetimeFull.obj', ROOT / 'rebuild/2008-06/native-classes/LDrawMapRootLifetime.cpp'),
                        ('NativeLDrawMapOperationsFull.obj', ROOT / 'rebuild/2008-06/native-classes/LDrawMapOperations.cpp'),
                        ('NativeLDrawMapTagsFull.obj', ROOT / 'rebuild/2008-06/native-classes/LDrawMapTags.cpp'),
                        ('NativeLDrawStringCompareFull.obj', ROOT / 'rebuild/2008-06/native-classes/LDrawStringCompare.cpp'),
                        ('NativeLDrawParserParseFull.obj', ROOT / 'rebuild/2008-06/native-classes/LDrawParserParse.cpp'),
                        ('NativeLDrawEntityLifetimeFull.obj', ROOT / 'rebuild/2008-06/native-classes/LDrawEntityLifetime.cpp'),
                        ('NativeLDrawModelWriteFull.obj', ROOT / 'rebuild/2008-06/native-classes/LDrawModelWrite.cpp'),
                        ('NativeLDrawPartWriteFull.obj', ROOT / 'rebuild/2008-06/native-classes/LDrawPartWrite.cpp'),
                        ('NativeLDrawPartShapeFull.obj', ROOT / 'rebuild/2008-06/native-classes/LDrawPartShape.cpp'),
                        ('NativeLDrawPartTransformFull.obj', ROOT / 'rebuild/2008-06/native-classes/LDrawPartTransform.cpp'),
                        ('NativeLDrawPartParentFull.obj', ROOT / 'rebuild/2008-06/native-classes/LDrawPartParent.cpp'),
                        ('NativeLDrawPartColorFull.obj', ROOT / 'rebuild/2008-06/native-classes/LDrawPartColor.cpp'),
                        ('NativeContentReadFull.obj', ROOT / 'rebuild/2008-06/native-classes/ContentRead.cpp')]
    extra_sources = [Path(p) for p in os.environ.get('ROC_NATIVE_DOC_EXTRA', '').split(';') if p]
    for index, source in enumerate(extra_sources):
        assert source.is_file(), source
        doc_sources.append(('NativeDocExtra%02d.obj' % index, source))
    # Native-Doc closure probes change one source at a time. Cache only these
    # objects; key covers source, common native headers, overlay and flags.
    # Opt-in: normal diagnostic builds stay fully fresh.
    # Cache shared across isolated probe directories. Artifacts are immutable
    # once their source/header/flag stamp matches.
    def compile_doc_source(job):
        obj, source = job
        source_flags = doc_flags + (['/DNATIVE_FILE_SYSTEM_APPDATA_ONLY'] if obj == 'NativeFileSystemFull.obj' else [])
        pinned = re.search(r'^// native-flags: (.*)$', source.read_text(encoding='utf-8-sig', errors='replace'), re.M)
        if obj == 'ServiceChangeHistoryCreateFull.obj':
            # This second translation unit instantiates creation, not the lookup profile.
            source_flags += ['/Ob2', '/Oy', '/GF', '/DSERVICE_HISTORY_CREATE_ONLY']
            pinned = None
        if pinned:
            source_flags = ['/nologo', '/c'] + pinned.group(1).replace('{headers}', str(ROOT / 'rebuild/2008-06/native-headers')).split()
            source_flags += ['/DBOOST_ALL_NO_LIB', '/D_XTP_STATICLINK', '/D_XTPLIB_NOAUTOLINK'] + ['/D' + d for d in data_defines.split()]
            source_flags += ['/I' + str(ROOT / 'rebuild/2008-06/native-headers'), '/I' + str(mfc), '/I' + str(xtp)]
            source_flags += ['/I' + str(i) for i in includes]
        if obj == 'NativeInstanceLifetimeFull.obj':
            source_flags.append('/DNATIVE_INSTANCE_EXTERNAL_CREATE_CHILD')
        if obj == 'NativeInstanceCallbacksFull.obj':
            source_flags.append('/DNATIVE_INSTANCE_EXTERNAL_BASE_CALLBACKS')
        key = cache_key(source, source_flags)
        cache_name = obj
        if obj.startswith('NativeDocExtra'):
            cache_name += '-' + hashlib.sha256(str(source.resolve()).encode()).hexdigest()[:12]
        if restore_cached(cache_name, key, obj):
            return 0, ''
        code, text = rebuild.run(tc, 'cl', source_flags + ['/Fo' + obj, str(source)], out)
        if not code:
            store_cached(cache_name, key, obj)
        return code, text
    # Each job owns its object/cache path; no debug/PCH files are shared.
    assert len({obj for obj, _ in doc_sources}) == len(doc_sources)
    jobs = max(1, min(3, int(os.environ.get('ROC_NATIVE_DOC_JOBS', '3'))))
    with ThreadPoolExecutor(max_workers=jobs) as pool:
        for code, text in pool.map(compile_doc_source, doc_sources):
            if text:
                print(text[-2500:])
            if code:
                sys.exit(code)
system = ["gdiplus", "kernel32", "user32", "gdi32", "advapi32", "shell32", "ole32", "oleaut32", "comdlg32", "comctl32", "ws2_32", "winmm",
          "opengl32", "glu32", "imagehlp", "version", "wininet", "dbghelp", "psapi"]
output_name = 'RobloxNativeDoc' if NATIVE_DOC else 'Roblox'
native_doc_objects = ['NativeCRobloxDoc.obj', 'NativeActiveDocumentDataFull.obj', 'NativeStandardVerbs.obj', 'NativeStatsCommandsFull.obj', 'NativeToolVerbFactoriesFull.obj', 'NativeToolVerbCoreFull.obj', 'NativeToolVerbCheckedSurfaceFull.obj', 'NativeToolVerbCheckedModelFull.obj', 'NativeToolVerbCheckedExistingFull.obj', 'NativeToolVerbCheckedBasicFull.obj', 'NativeToolVerbCheckedShootFull.obj', 'NativeToolVerbCheckedResizeFull.obj', 'NativeToolVerbCheckedAxisFull.obj', 'NativeCameraFirstPersonFull.obj', 'NativeCameraZoomExtentsActionFull.obj', 'NativeBasicVerbConstructorsFull.obj', 'NativeClearBackpackFull.obj', 'NativeClearStarterpackFull.obj', 'NativeSelectionBackFull.obj', 'NativeJoinCommandFull.obj', 'NativeSelectionVerbConstructorsFull.obj', 'NativeSelectionVerbStatesFull.obj', 'NativeBoolPropertyVerbFull.obj', 'NativeDuplicateSelectionVerbFull.obj', 'NativeWeldSnapActionsFull.obj', 'NativeSurfaceVisitorsFull.obj', 'NativeMoveUpSelectionVerbFull.obj', 'NativeMoveDownSelectionVerbFull.obj', 'NativeUngroupOperationFull.obj', 'NativeUngroupSelectionVerbFull.obj', 'NativePartInstanceLockedFull.obj', 'NativeRunStateCommandsFull.obj', 'NativeGroupSelectionVerbFull.obj',
                      'NativeDocumentExceptionFull.obj', 'NativeSaveDialogFull.obj', 'NativeDocumentLoadFileFull.obj', 'NativeScriptFileLoadFull.obj', 'NativeDocumentLoadFromStringFull.obj',
                      'NativeDocumentInsertModelFull.obj', 'NativeDocumentExecuteFull.obj', 'NativeDocumentLDrawFull.obj', 'NativeDocumentLaunchFull.obj', 'NativeFileSystemFull.obj', 'NativeContentProviderFull.obj',
                      'NativeLDrawParserFull.obj',
                      'NativeDocumentInitializeFull.obj', 'NativeVerbFull.obj',
                      'NativeWorkspaceFactoryFull.obj',
                      'NativeWorkspaceGroupFull.obj',
                      'NativeWorkspaceSelectAllFull.obj',
                      'NativeWorkspaceGuidsFull.obj', 'NativeWorkspaceFinalConstructFull.obj', 'NativeDataModelCreateFull.obj', 'NativeDataModelInitializeFull.obj',
                      'NativeWorkspaceEventsFull.obj',
                      'NativeWorkspaceCloseFull.obj',
                      'NativeWorkspaceInsertUrlFull.obj',
                      'NativeWorkspaceSaveFull.obj',
                      'NativeWorkspaceWriteFull.obj',
                      'NativeWorkspaceXmlWriterFull.obj',
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
                      'NativeFilteredSelectionFactoryFull.obj',
                      'NativeFilteredSelectionMethodsFull.obj',
                      'NativeGuidItemFull.obj', 'NativeGuidRegistryMutexFull.obj', 'NativeGuidRegistryInitializeFull.obj',
                      'NativeGuidRegistryConstructorFull.obj', 'NativeGuidRegistryCriticalSectionFull.obj',
                      'NativeServiceSelectionFull.obj', 'NativeServiceChangeHistoryFull.obj',
                      'NativeApplicationBaseUrlFull.obj', 'NativeDataModelTimingFull.obj', 'NativeDataModelDutyCycleFull.obj', 'NativeLuaAllocatorStatsFull.obj', 'NativePlayersAbuseFull.obj', 'ServiceChangeHistoryCreateFull.obj',
                      'NativeCWorkspaceFull.obj',
                      'NativeVisitServiceLookupFull.obj',
                      'NativeInstanceLifetimeFull.obj', 'NativeInstanceCallbacksFull.obj',
                      'NativeInstanceDescendantsFull.obj', 'NativeInstanceAncestorFull.obj',
                      'NativeInstanceChildListenerFull.obj', 'NativeInstanceReadPropertyFull.obj',
                      'NativeVerbBaseLifetimeFull.obj', 'NativeVerbQueriesFull.obj',
                      'NativeContentProviderUrlFull.obj', 'NativeServiceLookupFull.obj', 'NativeHistoryRecordPlaybackFull.obj',
                      'NativeChangeHistoryPlaybackFull.obj', 'NativeChangeHistoryQueriesFull.obj',
                      'NativeChangeHistoryEnableFull.obj', 'NativeChangeHistoryResetFull.obj', 'NativeSelectionFrontFull.obj', 'NativeInstanceClassLookupFull.obj',
                      'NativeHistoryRecordLifetimeFull.obj', 'NativeHistoryItemPlaybackFull.obj',
                      'NativeHistoryItemPropertyFull.obj',
                      'NativeAxisVerbConstructorsFull.obj', 'NativeControllerActionsFull.obj',
                      'NativeControllerEnabledFull.obj', 'NativeControllerApplyFull.obj',
                      'NativeTiltSelectionAxisFull.obj', 'NativeRotateAxisActionFull.obj',
                      'NativeMathTiltMatricesFull.obj', 'NativeMathTiltQuadrantFull.obj',
                      'NativeSurfaceToolFull.obj', 'NativeFlatToolFull.obj',
                      'NativeSurfaceToolSiblingsFull.obj', 'NativeSurfaceToolFactoriesFull.obj',
                      'NativeNullToolFull.obj', 'NativeMouseCommandFull.obj', 'NativeMouseCommandDistanceFull.obj',
                      'NativeModelToolFull.obj', 'NativeAxisMoveToolCoreFull.obj', 'NativeModelToolFactoriesFull.obj',
                      'NativeModelToolNamesFull.obj', 'NativeModelToolActionsFull.obj',
                      'NativeAnchorToolFull.obj', 'NativeInstanceAnchorChildrenFull.obj',
                      'NativeWorkspaceFindTopInstanceFull.obj',
                      'NativeCloneToolFull.obj',
                      'NativeHammerToolFull.obj', 'NativeMouseUnlockedFull.obj',
                      'NativeGrabToolFull.obj',
                      'NativeGameToolFull.obj',
                      'NativeGameToolDragFull.obj',
                      'NativeDragToolFull.obj', 'NativeCollectDragPartsFull.obj',
                      'NativeSurfaceFlatFull.obj', 'NativePartInstanceGetSurfaceFull.obj',
                      'NativePartInstanceLockedInPlaceFull.obj',
                      'NativeLaserToolFull.obj',
                      'NativePartToolFull.obj', 'NativePartToolsFull.obj', 'NativePartToolFactoriesFull.obj',
                      'NativeFillToolColorFull.obj', 'NativePVInstanceTopParentFull.obj',
                      'NativeModelSetFrontToolFull.obj',
                      'NativeChangeHistoryStartFull.obj',
                      'NativeWorldServiceFactoriesFull.obj', 'NativePhysicsServiceFull.obj', 'NativePhysicsServiceProviderFull.obj', 'NativeJointsServiceFull.obj',
                      
                      'NativeSlingshotToolCoreFull.obj', 'NativeRocketToolCoreFull.obj', 'NativeRocketToolProjectileFull.obj', 'NativeRocketToolLaunchFull.obj', 'NativeEngineStatsFull.obj', 'NativeContactManagerStatsFull.obj', 'NativeSpatialHashStatsFull.obj', 'NativeShootToolMethodsFull.obj', 'NativeShootToolShootFull.obj', 'NativeSlingshotToolLaunchFull.obj', 'NativeSlingshotBallisticFull.obj', 'NativeSlingshotToolProjectileFull.obj', 'NativeContentProviderCreateContextFull.obj', 'NativeContentIdAssetsFull.obj', 'NativeContentProviderLoadFull.obj',
                      'NativeResizeToolCoreFull.obj', 'NativeResizeToolMethodsFull.obj', 'NativeResizeToolMoveFull.obj', 'NativeResizeToolDragFull.obj', 'NativeResizeToolFindFull.obj', 'NativeResizeToolRenderFull.obj', 'NativeMathClosestRayFull.obj', 'NativeHandleHitTestFull.obj', 'NativePartInstanceResizeFull.obj', 'NativeHandleRadiusFull.obj',
                      'NativeCInsertObjectDialogCoreFull.obj', 'NativeCInsertObjectDialogActionFull.obj', 'NativeMetadataClassFull.obj', 'NativeMetadataClassesLookupFull.obj', 'NativeMetadataReflectionLookupFull.obj', 'NativeMetadataReflectionSingletonFull.obj', 'NativeMetadataReflectionLifetimeFull.obj', 'NativeMetadataReflectionLoadFull.obj', 'NativeMetadataClassNamesFull.obj', 'NativeMetadataClassesRegisterFull.obj', 'NativeMetadataItemLifetimeFull.obj', 'NativeMotorFeatureCommandsFull.obj', 'NativeArrowToolFactoryFull.obj', 'NativeDataModelClassNameFull.obj', 'NativeAuthoringSettingsFull.obj', 'NativeCClassImagesFull.obj', 'NativeNameCompareFull.obj',
                      
                      'NativeChangeHistoryLifetimeFull.obj', 'NativeChangeHistoryEventsFull.obj', 'NativeChangeHistoryFactoryFull.obj', 'NativeHistoryRecordLookupFull.obj', 'NativeHistoryItemStateFull.obj',
                      'NativeSurfaceToolHoverRenderFull.obj', 'NativeSurfaceToolMouseDownFull.obj',
                      'NativeMouseGetSurfaceFull.obj', 'NativeInsertObjectActionFull.obj',
                      'NativeInsertDecalActionFull.obj',
                      'NativeImageMimeTypeFull.obj', 'NativeImageContentRegistrationFull.obj',
                      'NativeClipboardActionsFull.obj', 'NativeLDrawPathFull.obj', 'NativeLDrawAssetStateFull.obj',
                      'NativeLDrawMapRootConstructorFull.obj', 'NativeLDrawMapRootLifetimeFull.obj',
                      'NativeLDrawMapOperationsFull.obj', 'NativeLDrawMapTagsFull.obj',
                      'NativeLDrawStringCompareFull.obj', 'NativeLDrawParserParseFull.obj',
                      'NativeLDrawEntityLifetimeFull.obj', 'NativeLDrawModelWriteFull.obj',
                      'NativeLDrawPartWriteFull.obj', 'NativeLDrawPartShapeFull.obj',
                      'NativeLDrawPartTransformFull.obj', 'NativeLDrawPartParentFull.obj',
                      'NativeLDrawPartColorFull.obj', 'NativeContentReadFull.obj'] if NATIVE_DOC else []
if NATIVE_DOC:
    native_doc_objects += ['NativeDocExtra%02d.obj' % index for index, _ in enumerate(extra_sources)]
    native_doc_objects += [str(ROOT / 'rebuild/2008-06/out/native-layouts' / name) for name in (
        'WorkspaceInsertNativeProfile.obj',
        'WorkspaceSiteTrustProfile.obj')]
if NATIVE_DOC:
    import script_context_owner
    script_context_owner.verify_native(out)
    original_app_library = SNAPSHOT / 'RbxgsApp/linked/linked.lib'
    if sum(path.resolve() == original_app_library.resolve() for path in libs) != 1:
        raise RuntimeError('expected one RbxgsApp archive for native ScriptContext ownership')
    script_app_library = script_context_owner.build(SNAPSHOT, out, tc)
    import part_getter_owner
    script_app_library = part_getter_owner.build(SNAPSHOT, out, tc, script_app_library)
    libs = [script_app_library if path.resolve() == original_app_library.resolve() else path for path in libs]
native_doc_aliases = ['/alternatename:?createNativeWorkspace@@YGJPAPAVCWorkspace@@@Z=?CreateInstance@?$CComObject@VCWorkspace@@@ATL@@SGJPAPAV12@@Z'] if NATIVE_DOC else []
native_doc_verbose = (['/VERBOSE'] if os.environ.get('ROC_NATIVE_DOC_VERBOSE_LIB') == 'full' else ['/VERBOSE:LIB']) if NATIVE_DOC and os.environ.get('ROC_NATIVE_DOC_VERBOSE_LIB') else []
link_args = (["/nologo", "/SUBSYSTEM:WINDOWS", "/MACHINE:X86", "/FORCE:MULTIPLE", "/MAP:" + output_name + ".map", "/OUT:" + output_name + ".exe",
                                      "/NODEFAULTLIB:mfcs90.lib", "/MANIFEST:NO"] + native_doc_aliases + native_doc_verbose + [u[0] for u in units] + [str(ROOT / "rebuild/2008-06/out/native-layouts" / name) for name in ("NativeFrameIconsFresh.obj", "NativeFrameIconWidth.obj", "NativeDHtmlDialog.obj", "NativeAboutDialog.obj", "NativeAboutDialogData.obj", "NativeFileVersionInfo.obj", "NativeGLCaps.obj")] + ["P6Data.obj", "roblox.res", "mfc90.lib"]
                         + native_doc_objects
                         + [str(l) for l in libs] + [s + ".lib" for s in system]
                         + ["/NODEFAULTLIB:" + l for l in rebuild.VENDOR_AUTOLINK])
if NATIVE_DOC:
    import null_tool_owner
    null_app_library = null_tool_owner.build(SNAPSHOT, out, tc, script_app_library, link_args)
    link_args = [str(null_app_library) if arg == str(script_app_library) else arg for arg in link_args]
    (out / 'native-doc-link-command.json').write_text(json.dumps({
        'cwd': str(out), 'arguments': link_args,
        'scope': 'Diagnostic link replay only; never executes client.'
    }, indent=2) + "\n")
code, text = rebuild.run(tc, "link", link_args, out)
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
