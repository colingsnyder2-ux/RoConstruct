import json
import threading
import time
import os
import shutil
import pytest
from pathlib import Path

from roc import rebuild


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


def test_parallel_sdk_discovery_runs_once_for_twenty_workers(monkeypatch):
    from concurrent.futures import ThreadPoolExecutor
    calls=[]
    class Tools:
        def glob(self, pattern):
            calls.append(pattern)
            time.sleep(.03)
            return []
    tools=Tools()
    with ThreadPoolExecutor(20) as pool:
        assert list(pool.map(rebuild.sdk_roots,[tools]*20)) == [()]*20
    assert calls == ['*/**/WinSDK']


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
