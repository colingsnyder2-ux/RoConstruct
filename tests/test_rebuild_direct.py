import json
import threading
import time
import os
import shutil
import pytest
from pathlib import Path

from roc import rebuild


def test_original_source_name_preserves_lines_siblings_and_cache_identity(tmp_path, monkeypatch):
    source = tmp_path / 'vendor' / 'Stopwatch.cpp'
    source.parent.mkdir()
    source.write_text('#include "local.h"\nconst char* name = __FILE__;\n')
    appended = tmp_path / 'after.h'
    appended.write_text('// appended declarations')
    monkeypatch.chdir(tmp_path)
    output = Path('out')
    calls = []
    monkeypatch.setattr(rebuild, 'toolchain', lambda _: {})

    def run(tc, tool, args, cwd):
        assert Path(args[-1]).is_absolute()
        calls.append(args)
        (cwd / 'Stopwatch.obj').write_bytes(b'object')
        return 0, ''

    monkeypatch.setattr(rebuild, 'run', run)
    name = '.\\g3dcpp\\Stopwatch.cpp'

    def build(spelling, extra=None):
        names = {str(source): spelling, **(extra or {})}
        return rebuild.compile_direct('test', [source], output, [], '', append=appended, source_names=names)

    assert build(name)[str(source)][0]
    wrapper = Path(calls[0][-1]).read_text()
    assert wrapper.startswith('#line 1 ' + json.dumps(name) + '\n' + source.read_text())
    assert wrapper.endswith('#include "' + appended.as_posix() + '"\n')
    assert '/I' + str(source.parent) in calls[0]
    assert build(name, {str(tmp_path / 'unrelated.cpp'): 'other.cpp'})[str(source)] == (True, 'content cache hit')
    build('different.cpp')
    assert len(calls) == 2


def test_unchanged_source_uses_adopted_sibling_header_directory(tmp_path):
    tree, overlay = tmp_path/'tree', tmp_path/'overlay'
    tree.mkdir(); overlay.mkdir()
    source = tree/'API.cpp'
    source.write_text('#include "Client.h"\nint f(){return VALUE;}')
    (tree/'Client.h').write_text('#define VALUE 1')
    (overlay/'Client.h').write_text('#define VALUE 2')
    includes, sources = rebuild._overlaid([tree], [source], (tree, overlay))
    assert sources == [overlay/'API.cpp']
    assert sources[0].read_bytes() == source.read_bytes()
    assert includes == [overlay, tree]
    assert (tree/'Client.h').read_text() == '#define VALUE 1'


def test_adopted_source_is_never_overwritten_by_sibling_copy(tmp_path):
    tree, overlay = tmp_path/'tree', tmp_path/'overlay'
    tree.mkdir(); overlay.mkdir()
    source = tree/'API.cpp'
    source.write_text('old source')
    (overlay/'Client.h').write_text('header')
    (overlay/'API.cpp').write_text('accepted source patch')
    assert rebuild._overlaid([], [source], (tree, overlay))[1] == [overlay/'API.cpp']
    assert (overlay/'API.cpp').read_text() == 'accepted source patch'


def test_overlay_only_source_compiles_caches_and_detects_new_original(tmp_path, monkeypatch):
    tree, overlay, output = tmp_path/'tree', tmp_path/'overlay', tmp_path/'out'
    tree.mkdir(); overlay.mkdir()
    original = tree/'Promoted.cpp'
    (overlay/'Promoted.cpp').write_text('int promoted(){return 1;}')
    monkeypatch.setattr(rebuild, 'toolchain', lambda _: {})
    calls = []
    def run(tc, tool, args, cwd):
        calls.append(args)
        (cwd/'Promoted.obj').write_bytes(b'object')
        return 0, ''
    monkeypatch.setattr(rebuild, 'run', run)
    def build():
        return rebuild.compile_direct('2008-06', [original], output, [], '', overlay=(tree,overlay))
    assert build()[str(original)][0]
    assert build()[str(original)] == (True, 'content cache hit')
    original.write_text('different authentic source now exists')
    build()
    assert len(calls) == 2


def test_direct_compile_overlaps_independent_sources_and_keeps_result_order(tmp_path, monkeypatch):
    sources = [tmp_path / (name + '.cpp') for name in ('first', 'second', 'third', 'fourth')]
    for source in sources:
        source.write_text('void f();')
    header = tmp_path / 'shared.h'
    header.write_text('')
    barrier = threading.Barrier(4)
    monkeypatch.setattr(rebuild, 'toolchain', lambda _: {})

    def run(tc, tool, args, cwd):
        barrier.wait(timeout=5)
        (cwd / next(a[3:] for a in args if a.startswith('/Fo'))).write_bytes(b'object')
        return 0, 'Note: including file: ' + str(header)

    monkeypatch.setattr(rebuild, 'run', run)
    result = rebuild.compile_direct('2008-06', sources, tmp_path / 'out', [], '')
    assert list(result) == list(map(str, sources))
    assert all(ok for ok, _ in result.values())
    for source in sources:
        assert json.loads((tmp_path / 'out' / (source.stem + '.deps')).read_text()) == [str(header)]


def test_direct_compile_serializes_colliding_object_names(tmp_path, monkeypatch):
    sources = [tmp_path / folder / 'same.cpp' for folder in ('one', 'two')]
    for source in sources:
        source.parent.mkdir()
        source.write_text('void f();')
    monkeypatch.setattr(rebuild, 'toolchain', lambda _: {})
    calls = []
    active = threading.Lock()

    def run(tc, tool, args, cwd):
        assert active.acquire(blocking=False)
        calls.append(Path(args[-1]))
        time.sleep(0.01)
        active.release()
        return 0, ''

    monkeypatch.setattr(rebuild, 'run', run)
    rebuild.compile_direct('2008-06', sources, tmp_path / 'out', [], '')
    assert calls == sources


def test_failed_direct_compile_removes_stale_object(tmp_path, monkeypatch):
    source = tmp_path / 'broken.cpp'
    source.write_text('broken')
    out = tmp_path / 'out'
    out.mkdir()
    obj = out / 'broken.obj'
    obj.write_bytes(b'stale')
    monkeypatch.setattr(rebuild, 'toolchain', lambda _: {})
    monkeypatch.setattr(rebuild, 'run', lambda *args: (1, 'broken.cpp: error C2143'))
    result = rebuild.compile_direct('2008-06', [source], out, [], '')
    assert result[str(source)] == (False, 'broken.cpp: error C2143')
    assert not obj.exists()


@pytest.mark.parametrize('change', ['touch', 'unrelated_source', 'unrelated_header', 'source', 'header', 'flags', 'defines', 'compiler', 'object', 'new_header', 'include_order'])
@pytest.mark.parametrize('header_name', ['shared.h', 'shared.cpp'])
def test_content_cache_checks_inputs_and_ignores_timestamps(tmp_path, monkeypatch, change, header_name):
    source = tmp_path / 'src' / 'unit.cpp'
    source.parent.mkdir()
    source.write_text('#include "%s"\nint f(){return 1;}' % header_name)
    header = source.with_name(header_name)
    header.write_text('int value;')
    compiler = tmp_path / 'bin' / 'cl.exe'
    compiler.parent.mkdir()
    compiler.write_bytes(b'compiler1')
    includes = [source.parent, tmp_path / 'extra']
    includes[1].mkdir()
    monkeypatch.setattr(rebuild, 'toolchain', lambda _: {'cl': compiler})
    calls = []

    def run(tc, tool, args, cwd):
        calls.append(args)
        (cwd / 'unit.obj').write_bytes(b'object')
        return 0, 'Note: including file: ' + str(header)

    monkeypatch.setattr(rebuild, 'run', run)
    out = tmp_path / 'out'
    def build(flags='/O2', defines='WIN32'):
        return rebuild.compile_direct('2008-06', [source], out, includes, defines, flags)

    build()
    command = json.loads((out / 'unit.command.json').read_text())
    assert command['source'] == str(source) and '/O2' in command['args']
    assert str(header) in command['dependencies'] and command['exit'] == 0
    assert build()[str(source)] == (True, 'content cache hit')
    assert len(calls) == 1
    if change == 'touch':
        os.utime(source, None)
        os.utime(header, None)
    elif change in ('source', 'header', 'compiler'):
        path = {'source': source, 'header': header, 'compiler': compiler}[change]
        stat = path.stat()
        data = path.read_bytes()
        path.write_bytes(data[:-1] + bytes([data[-1] ^ 1]))
        os.utime(path, ns=(stat.st_atime_ns, stat.st_mtime_ns))
    elif change == 'object':
        (out / 'unit.obj').write_bytes(b'broken')
    elif change == 'new_header':
        (includes[1] / header_name).write_text('int shadow;')
    elif change == 'include_order':
        includes.reverse()
    elif change in ('unrelated_source', 'unrelated_header'):
        (includes[1] / ('other.cpp' if change == 'unrelated_source' else 'other.h')).write_text('int other;')
    build('/O1' if change == 'flags' else '/O2', 'OTHER' if change == 'defines' else 'WIN32')
    assert len(calls) == (1 if change in ('touch', 'unrelated_source', 'unrelated_header') else 2)


def test_overlay_header_creation_invalidates_content_cache(tmp_path, monkeypatch):
    root, overlay = tmp_path / 'src', tmp_path / 'overlay'
    root.mkdir()
    overlay.mkdir()
    source = root / 'unit.cpp'
    source.write_text('int f();')
    header = root / 'shared.h'
    header.write_text('')
    monkeypatch.setattr(rebuild, 'toolchain', lambda _: {})
    calls = []
    def run(tc, tool, args, cwd):
        calls.append(args)
        (cwd / 'unit.obj').write_bytes(b'object')
        return 0, 'Note: including file: ' + str(header)
    monkeypatch.setattr(rebuild, 'run', run)
    def build():
        return rebuild.compile_direct('2008-06', [source], tmp_path / 'out', [root], '', overlay=(root, overlay))
    build()
    build()
    assert len(calls) == 1
    (overlay / 'shared.h').write_text('int changed;')
    build()
    assert len(calls) == 2


def test_removed_dependency_invalidates_cache_and_failed_rebuild_removes_old_object(tmp_path, monkeypatch):
    source, header = tmp_path/'unit.cpp', tmp_path/'shared.h'
    source.write_text('#include "shared.h"\nint f();')
    header.write_text('int shared;')
    output = tmp_path/'out'
    calls = []
    monkeypatch.setattr(rebuild, 'toolchain', lambda _: {})
    def run(tc, tool, args, cwd):
        calls.append(args)
        if not header.exists():
            return 1, 'unit.cpp: error C1083: Cannot open include file: shared.h'
        (cwd/'unit.obj').write_bytes(b'object')
        return 0, 'Note: including file: ' + str(header)
    monkeypatch.setattr(rebuild, 'run', run)
    def build():
        return rebuild.compile_direct('2008-06', [source], output, [], '')[str(source)]
    assert build()[0]
    assert build() == (True, 'content cache hit')
    header.unlink()
    assert not build()[0]
    assert len(calls) == 2
    assert not (output/'unit.obj').exists()
    assert not (output/'unit.compile.json').exists()


def test_sdk_discovery_is_cached_per_tools_tree(tmp_path):
    tools = tmp_path / 'tools'
    sdk = tools / 'compiler' / 'WinSDK'
    sdk.mkdir(parents=True)
    assert rebuild.sdk_roots(tools) == (sdk,)
    hits = rebuild.sdk_roots.cache_info().hits
    assert rebuild.sdk_roots(tools) == (sdk,)
    assert rebuild.sdk_roots.cache_info().hits == hits + 1


def test_explicit_sdk_skips_tree_scan(tmp_path, monkeypatch):
    sdk = tmp_path / 'sdk'
    (sdk / 'Lib').mkdir(parents=True)
    (sdk / 'Lib' / 'kernel32.lib').touch()
    (sdk / 'Include').mkdir()
    monkeypatch.setenv('ROC_WINSDK', str(sdk))
    monkeypatch.setattr(rebuild.setup, 'compilers', lambda: {})
    monkeypatch.setattr(rebuild, 'sdk_roots', lambda _: pytest.fail('override must skip discovery'))
    assert rebuild.toolchain()['sdk_include'] == sdk / 'Include'


def test_parallel_sdk_discovery_runs_once_for_twenty_workers(monkeypatch,tmp_path):
    from concurrent.futures import ThreadPoolExecutor
    calls=[]
    tools=tmp_path/'tools'
    (tools/'compiler').mkdir(parents=True)
    def walk(folder):
        calls.append(folder)
        time.sleep(.03)
        return []
    monkeypatch.setattr(rebuild.setup.os,'walk',walk)
    with ThreadPoolExecutor(20) as pool:
        assert list(pool.map(rebuild.sdk_roots,[tools]*20)) == [()]*20
    assert calls == [tools/'compiler']


def test_content_cache_survives_private_snapshot_remapping(tmp_path, monkeypatch):
    before, after = tmp_path / 'before', tmp_path / 'after'
    source = before / 'src' / 'unit.cpp'
    source.parent.mkdir(parents=True)
    source.write_text('int f();')
    header = source.with_name('shared.h')
    header.write_text('')
    monkeypatch.setattr(rebuild, 'ROOT', before)
    monkeypatch.setattr(rebuild, 'toolchain', lambda _: {})
    calls = []
    def run(tc, tool, args, cwd):
        calls.append(args)
        (cwd / 'unit.obj').write_bytes(b'object')
        return 0, 'Note: including file: ' + str(header)
    monkeypatch.setattr(rebuild, 'run', run)
    rebuild.compile_direct('2008-06', [source], before / 'out', [], '')
    shutil.copytree(before, after)
    deps = after / 'out' / 'unit.deps'
    deps.write_text(json.dumps([str(after / 'src' / 'shared.h')]))
    monkeypatch.setattr(rebuild, 'ROOT', after)
    source = after / 'src' / 'unit.cpp'
    result = rebuild.compile_direct('2008-06', [source], after / 'out', [], '')
    assert result[str(source)] == (True, 'content cache hit') and len(calls) == 1


@pytest.mark.skipif(os.name != 'nt', reason='Windows include path aliases are case insensitive')
def test_windows_header_case_aliases_do_not_recompile_identical_inputs(tmp_path,monkeypatch):
    source=tmp_path/'source.cpp';source.write_text('int f();')
    header=tmp_path/'WinSDK'/'Include'/'PshPack.h';header.parent.mkdir(parents=True);header.write_text('')
    monkeypatch.setattr(rebuild,'toolchain',lambda _: {})
    calls=[]
    def run(tc,tool,args,cwd):
        calls.append(args)
        (cwd/'source.obj').write_bytes(b'object')
        # MSVC can report the same file twice; serialized deps are sorted, unlike
        # the compiler stream. A Path set must not leak the surviving spelling.
        return 0,'Note: including file: '+str(header).lower()+'\nNote: including file: '+str(header)
    monkeypatch.setattr(rebuild,'run',run)
    out=tmp_path/'out'
    rebuild.compile_direct('2008-06',[source],out,[],'')
    result=rebuild.compile_direct('2008-06',[source],out,[],'')
    assert result[str(source)] == (True,'content cache hit')
    assert len(calls)==1


def test_nested_header_inventories_reuse_parent_walk_but_scan_excluded_wrap(tmp_path, monkeypatch):
    source = tmp_path / 'src/unit.cpp'
    source.parent.mkdir()
    source.write_text('int f();')
    includes = tmp_path / 'include'
    nested, wrap = includes / 'nested', includes / '_wrap'
    nested.mkdir(parents=True)
    wrap.mkdir()
    header, wrapped = nested / 'shared.h', wrap / 'generated.h'
    header.write_text('int a;')
    wrapped.write_text('int b;')
    monkeypatch.setattr(rebuild, 'toolchain', lambda _: {})
    walk = os.walk
    walks, compiles = [], []
    def counted_walk(folder):
        walks.append(Path(folder))
        return walk(folder)
    def run(tc, tool, args, cwd):
        compiles.append(args)
        (cwd / 'unit.obj').write_bytes(b'object')
        return 0, '\n'.join('Note: including file: ' + str(p) for p in (header, wrapped))
    monkeypatch.setattr(rebuild.os, 'walk', counted_walk)
    monkeypatch.setattr(rebuild, 'run', run)
    def build():
        return rebuild.compile_direct('2008-06', [source], tmp_path / 'out', [includes, nested, wrap], '')
    build()
    assert nested not in walks and includes in walks and wrap in walks
    assert build()[str(source)] == (True, 'content cache hit')
    (nested / 'deeper').mkdir()
    (nested / 'deeper/shared.h').write_text('new shadow')
    build()
    assert len(compiles) == 2

@pytest.mark.parametrize('selection,expected', [(['roc_selected.cpp'], ['roc_selected.cpp']), ('*.cpp', ['overlay_plain.cpp', 'plain.cpp'])])
def test_explicit_native_unit_selection_preserves_wildcard_sweep_exclusion(tmp_path, monkeypatch, selection, expected):
    tree = tmp_path / 'tools/libs/vendor'
    tree.mkdir(parents=True)
    for name in ['roc_selected.cpp', 'roc_unrelated.cpp', 'plain.cpp']:
        (tree / name).write_text('int native_unit;')
    overlay = tmp_path / 'overlay'
    overlay.mkdir()
    (overlay / 'overlay_plain.cpp').write_text('int overlay_unit;')
    monkeypatch.setattr(rebuild, 'ROOT', tmp_path)
    from roc import libs
    monkeypatch.setattr(libs, 'LIBS', tmp_path / 'tools/libs')
    monkeypatch.setitem(libs.RECIPES, 'native-fixture', {'src': 'vendor', 'files': '*.cpp', 'include': []})
    monkeypatch.setattr(rebuild, 'load_module', lambda *args: {'name': 'Fixture', 'layers': [
        {'name': 'native', 'mode': 'recipe', 'recipe': 'native-fixture', 'files': selection,
         'direct': True, 'flags': '/O2 /MD', 'extra_includes': ['tools/fmod/include']}]})
    monkeypatch.setattr(rebuild, 'build_overlay', lambda *args: (tree, overlay))
    monkeypatch.setattr(rebuild, 'patched_tree', lambda *args: tree)

    class CompileObserved(Exception):
        pass

    def compile_direct(client, sources, *args, **kwargs):
        assert [p.name for p in sources] == expected
        assert args[1][-1] == tmp_path / 'tools/fmod/include'
        raise CompileObserved()

    monkeypatch.setattr(rebuild, 'compile_direct', compile_direct)
    with pytest.raises(CompileObserved):
        rebuild.build_module('2008-06', 'fixture')


def test_stale_generated_object_does_not_exclude_selected_native_roots(tmp_path, monkeypatch):
    from roc import libs
    tree = tmp_path / 'tools/libs/vendor'
    tree.mkdir(parents=True)
    (tree / 'roc_selected.cpp').write_text('int native_unit;')
    monkeypatch.setattr(rebuild, 'ROOT', tmp_path)
    monkeypatch.setattr(libs, 'LIBS', tmp_path / 'tools/libs')
    monkeypatch.setitem(libs.RECIPES, 'native-fixture', {'src': 'vendor', 'files': '*.cpp', 'include': []})
    monkeypatch.setattr(rebuild, 'load_module', lambda *args: {'name': 'Fixture', 'test': 'fixture', 'layers': [
        {'name': 'native', 'mode': 'recipe', 'recipe': 'native-fixture', 'files': ['roc_selected.cpp'],
         'direct': True, 'flags': '/O2 /MD'}]})
    monkeypatch.setattr(rebuild, 'build_overlay', lambda *args: None)
    monkeypatch.setattr(rebuild, 'patched_tree', lambda *args: tree)
    def compile_direct(client, sources, folder, *args, **kwargs):
        folder.mkdir(parents=True, exist_ok=True)
        (folder / 'roc_selected.obj').write_bytes(b'current')
        (folder / 'roc_previous.obj').write_bytes(b'stale')
        return {str(sources[0]): (True, '')}
    monkeypatch.setattr(rebuild, 'compile_direct', compile_direct)
    def externals(data):
        assert data != b'stale'
        return {'_native_root': True}
    monkeypatch.setattr(rebuild, 'coff_externals', externals)
    class OwnershipObserved(Exception):
        pass
    def verified_layer(client, spec, **kwargs):
        assert '_native_root' not in kwargs['exclude']
        raise OwnershipObserved()
    monkeypatch.setattr(rebuild, 'verified_layer', verified_layer)
    with pytest.raises(OwnershipObserved):
        rebuild.build_module('2008-06', 'fixture')
