import ast
import hashlib
import json
import re
from types import SimpleNamespace
from pathlib import Path

import pytest


SOURCE = Path(__file__).resolve().parents[1] / 'rebuild/2008-06/p6/build_client.py'


@pytest.fixture
def cache(tmp_path):
    tree = ast.parse(SOURCE.read_text(encoding='utf-8'))
    nodes = [node for node in tree.body if isinstance(node, ast.FunctionDef)
             and node.name in ('native_deps', 'cache_key')]
    assert {node.name for node in nodes} == {'native_deps', 'cache_key'}
    root = tmp_path
    native = root / 'rebuild/2008-06'
    headers = native / 'native-headers'
    compiler = root / 'compiler.exe'
    compiler.write_bytes(b'compiler-one')
    namespace = {'ROOT': root, 'native_root': native, 'header_root': headers,
                 'tc': {'cl': compiler}, 'Path': Path, 'hashlib': hashlib, 're': re, 'out': root, 'rebuild': SimpleNamespace(env=lambda tc: {})}
    exec(compile(ast.Module(body=nodes, type_ignores=[]), str(SOURCE), 'exec'), namespace)
    return root, namespace


def write(path, text):
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text, encoding='utf-8')
    return path


def test_moved_source_and_header_invalidate_cache(cache):
    root, ns = cache
    native = root / 'rebuild/2008-06'
    source = write(native / 'native-classes/Foo.cpp', '#include "../App/src/Foo.cpp"\n')
    moved = write(native / 'App/src/Foo.cpp', '#include "../../native-headers/util/Foo.h"\nint f() { return FOO; }\n')
    write(native / 'native-headers/util/Foo.h', '#include "../../Base/include/util/Foo.h"\n')
    header = write(native / 'Base/include/util/Foo.h', '#define FOO 1\n')
    first = ns['cache_key'](source, [])
    assert str(moved.relative_to(root)) in dict(first['native_deps'])
    assert str(header.relative_to(root)) in dict(first['native_deps'])
    header.write_text('#define FOO 2\n', encoding='utf-8')
    second = ns['cache_key'](source, [])
    assert second != first
    moved.write_text('#include "../../native-headers/util/Foo.h"\nint f() { return FOO + 1; }\n', encoding='utf-8')
    assert ns['cache_key'](source, []) != second


def test_profile_override_follows_organized_header(cache):
    root, ns = cache
    native = root / 'rebuild/2008-06'
    source = write(native / 'native-classes/Foo.cpp', '#include <boost/foo.h>\n')
    profile = native / 'native-headers/override'
    write(profile / 'boost/foo.h', '#include "../../../Unclassified/include/boost/foo.h"\n')
    target = write(native / 'Unclassified/include/boost/foo.h', '#define FOO 1\n')
    first = ns['cache_key'](source, ['/I' + str(profile)])
    assert str(target.relative_to(root)) in dict(first['native_profile_headers'])
    assert json.loads(json.dumps(first)) == first
    target.write_text('#define FOO 2\n', encoding='utf-8')
    assert ns['cache_key'](source, ['/I' + str(profile)]) != first


def test_compiler_change_invalidates_cache(cache):
    root, ns = cache
    source = write(root / 'rebuild/2008-06/native-classes/Foo.cpp', 'int f() { return 1; }\n')
    first = ns['cache_key'](source, [])
    (root / 'compiler.exe').write_bytes(b'compiler-two')
    assert ns['cache_key'](source, []) != first




def test_compiler_backend_change_invalidates_cache(cache):
    root, ns = cache
    source = write(root / 'rebuild/2008-06/native-classes/Foo.cpp', 'int f() { return 1; }\n')
    backend = root / 'c2.dll'
    backend.write_bytes(b'backend-one')
    first = ns['cache_key'](source, [])
    backend.write_bytes(b'backend-two')
    assert ns['cache_key'](source, []) != first


def test_cache_rejects_corrupt_object_and_old_receipt(tmp_path):
    import os
    import shutil
    import time
    tree = ast.parse(SOURCE.read_text(encoding='utf-8'))
    nodes = [n for n in tree.body if isinstance(n, ast.FunctionDef)
             and n.name in ('cache_paths', 'restore_cached', 'store_cached', 'directory_signature', 'include_directories', 'directories_unchanged')]
    output = tmp_path / 'out'
    output.mkdir()
    (output / 'candidate.obj').write_bytes(b'valid object')
    ns = {'Path': Path, 'hashlib': hashlib, 'json': json, 'os': os, 'shutil': shutil,
          'cache_dir': tmp_path / 'cache', 'out': output, 'NATIVE_DOC': True, 'NATIVE_DOC_CACHE': True, 're': re, 'restored_cache_records': [], 'rebuild': SimpleNamespace(env=lambda tc: {})}
    exec(compile(ast.Module(body=nodes, type_ignores=[]), str(SOURCE), 'exec'), ns)
    source = write(tmp_path / 'src/candidate.cpp', 'int f() {}\n')
    key = {'schema': 3, 'source': str(source)}
    header = tmp_path / 'vendor/vendor.h'
    header.parent.mkdir()
    header.write_bytes(b'original header')
    ns['store_cached']('candidate.obj', key, include_log='Note: including file: ' + str(header), started_ns=time.time_ns() + 1_000_000_000)
    assert ns['restore_cached']('candidate.obj', key, 'restored.obj')
    header.write_bytes(b'changed header')
    assert not ns['restore_cached']('candidate.obj', key, 'stale.obj')
    assert not (output / 'stale.obj').exists()
    header.write_bytes(b'original header')
    artifact, receipt = ns['cache_paths']('candidate.obj', key)
    artifact.write_bytes(b'corrupt object')
    assert not ns['restore_cached']('candidate.obj', key, 'corrupt.obj')
    assert not (output / 'corrupt.obj').exists()
    receipt.write_text(json.dumps(key))
    assert not ns['restore_cached']('candidate.obj', key, 'legacy.obj')


def test_cache_skips_missing_or_changing_header_evidence(tmp_path):
    import os
    import shutil
    tree = ast.parse(SOURCE.read_text(encoding='utf-8'))
    nodes = [n for n in tree.body if isinstance(n, ast.FunctionDef)
             and n.name in ('cache_paths', 'restore_cached', 'store_cached', 'directory_signature', 'include_directories', 'directories_unchanged')]
    output = tmp_path / 'out'
    output.mkdir()
    (output / 'candidate.obj').write_bytes(b'candidate')
    ns = {'Path': Path, 'hashlib': hashlib, 'json': json, 'os': os, 'shutil': shutil, 're': re,
          'cache_dir': tmp_path / 'cache', 'out': output, 'NATIVE_DOC': True, 'NATIVE_DOC_CACHE': True, 'restored_cache_records': [], 'rebuild': SimpleNamespace(env=lambda tc: {})}
    exec(compile(ast.Module(body=nodes, type_ignores=[]), str(SOURCE), 'exec'), ns)
    key = {'schema': 3}
    header = tmp_path / 'vendor/vendor.h'
    header.parent.mkdir()
    header.write_bytes(b'header')
    ns['store_cached']('candidate.obj', key)
    assert not ns['cache_paths']('candidate.obj', key)[0].exists()
    with pytest.raises(RuntimeError, match='Header changed'):
        ns['store_cached']('candidate.obj', key, include_log='Note: including file: ' + str(header), started_ns=0)
    assert not ns['cache_paths']('candidate.obj', key)[0].exists()


def test_cache_rejects_new_shadowing_header(tmp_path):
    import os
    import shutil
    import time
    tree = ast.parse(SOURCE.read_text(encoding='utf-8'))
    nodes = [n for n in tree.body if isinstance(n, ast.FunctionDef)
             and n.name in ('cache_paths', 'restore_cached', 'store_cached', 'directory_signature',
                            'include_directories', 'directories_unchanged')]
    output, first, second = tmp_path / 'out', tmp_path / 'first', tmp_path / 'second'
    for path in (output, first, second):
        path.mkdir()
    (output / 'candidate.obj').write_bytes(b'candidate')
    header = second / 'foo.h'
    header.write_bytes(b'original header')
    ns = {'Path': Path, 'hashlib': hashlib, 'json': json, 'os': os, 'shutil': shutil, 're': re,
          'cache_dir': tmp_path / 'cache', 'out': output, 'NATIVE_DOC': True, 'NATIVE_DOC_CACHE': True, 'restored_cache_records': [], 'rebuild': SimpleNamespace(env=lambda tc: {})}
    exec(compile(ast.Module(body=nodes, type_ignores=[]), str(SOURCE), 'exec'), ns)
    key = {'schema': 3, 'include_roots': [str(first), str(second)]}
    ns['store_cached']('candidate.obj', key, include_log='Note: including file: ' + str(header),
                       started_ns=time.time_ns() + 1_000_000_000)
    assert ns['restore_cached']('candidate.obj', key, 'valid.obj')
    (first / 'foo.h').write_bytes(b'shadowing header')
    assert not ns['restore_cached']('candidate.obj', key, 'stale.obj')
    assert not (output / 'stale.obj').exists()


def test_cache_rejects_new_relative_parent_shadow(tmp_path):
    import os
    import shutil
    import time
    tree = ast.parse(SOURCE.read_text(encoding='utf-8'))
    nodes = [n for n in tree.body if isinstance(n, ast.FunctionDef)
             and n.name in ('cache_paths', 'restore_cached', 'store_cached', 'directory_signature',
                            'include_directories', 'directories_unchanged')]
    output, first, second = tmp_path / 'out', tmp_path / 'first/inner', tmp_path / 'second'
    for path in (output, first, second):
        path.mkdir(parents=True)
    (output / 'candidate.obj').write_bytes(b'candidate')
    source = first / 'source.cpp'
    source.write_text('#include "../foo.h"\n')
    header = second / 'foo.h'
    header.write_bytes(b'original header')
    ns = {'Path': Path, 'hashlib': hashlib, 'json': json, 'os': os, 'shutil': shutil, 're': re,
          'cache_dir': tmp_path / 'cache', 'out': output, 'NATIVE_DOC': True, 'NATIVE_DOC_CACHE': True, 'restored_cache_records': [], 'rebuild': SimpleNamespace(env=lambda tc: {})}
    exec(compile(ast.Module(body=nodes, type_ignores=[]), str(SOURCE), 'exec'), ns)
    key = {'schema': 3, 'source': str(source), 'include_roots': [str(first), str(second)]}
    ns['cache_dir'].mkdir()
    ns['store_cached']('candidate.obj', key, include_log='Note: including file: ' + str(header),
                       started_ns=time.time_ns() + 1_000_000_000)
    assert ns['restore_cached']('candidate.obj', key, 'valid.obj')
    (first.parent / 'foo.h').write_bytes(b'new parent shadow')
    assert not ns['restore_cached']('candidate.obj', key, 'stale.obj')


@pytest.mark.parametrize('change', ['header', 'shadow'])
def test_link_rejects_inputs_changed_after_cache_restore(tmp_path, change):
    import os
    import shutil
    import time
    tree = ast.parse(SOURCE.read_text(encoding='utf-8'))
    nodes = [n for n in tree.body if isinstance(n, ast.FunctionDef)
             and n.name in ('cache_paths', 'restore_cached', 'store_cached', 'directory_signature',
                            'include_directories', 'directories_unchanged', 'assert_cached_inputs_unchanged')]
    output, first, second = tmp_path / 'out', tmp_path / 'first', tmp_path / 'second'
    for path in (output, first, second):
        path.mkdir()
    source = write(tmp_path / 'src/a.cpp', '#include <foo.h>\n')
    compiler = write(tmp_path / 'tools/cl.exe', 'compiler')
    header = second / 'foo.h'
    header.write_bytes(b'original')
    (output / 'candidate.obj').write_bytes(b'object')
    sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
    key = {'source': str(source), 'source_sha256': sha(source), 'compiler_sha256': sha(compiler),
           'compiler_components': {}, 'include_roots': [str(first), str(second)], 'native_deps': []}
    ns = {'Path': Path, 'hashlib': hashlib, 'json': json, 'os': os, 'shutil': shutil, 're': re,
          'cache_dir': tmp_path / 'cache', 'out': output, 'ROOT': tmp_path, 'tc': {'cl': compiler},
          'NATIVE_DOC': True, 'NATIVE_DOC_CACHE': True, 'restored_cache_records': [], 'rebuild': SimpleNamespace(env=lambda tc: {})}
    exec(compile(ast.Module(body=nodes, type_ignores=[]), str(SOURCE), 'exec'), ns)
    ns['store_cached']('candidate.obj', key, include_log='Note: including file: ' + str(header),
                       started_ns=time.time_ns() + 1_000_000_000)
    assert ns['restore_cached']('candidate.obj', key, 'restored.obj')
    ns['assert_cached_inputs_unchanged']()
    if change == 'header':
        header.write_bytes(b'changed')
    else:
        (first / 'foo.h').write_bytes(b'shadow')
    with pytest.raises(RuntimeError, match='changed'):
        ns['assert_cached_inputs_unchanged']()


def test_new_compiler_backend_invalidates_cache(cache):
    root, ns = cache
    source = write(root / 'rebuild/2008-06/native-classes/Foo.cpp', 'int f() { return 1; }\n')
    first = ns['cache_key'](source, [])
    (root / 'c1.dll').write_bytes(b'new backend')
    assert ns['cache_key'](source, []) != first


def test_macro_generated_include_is_not_cached(tmp_path):
    import os
    import shutil
    import time
    tree = ast.parse(SOURCE.read_text(encoding='utf-8'))
    nodes = [n for n in tree.body if isinstance(n, ast.FunctionDef)
             and n.name in ('cache_paths', 'restore_cached', 'store_cached', 'directory_signature',
                            'include_directories', 'directories_unchanged')]
    output = tmp_path / 'out'
    output.mkdir()
    (output / 'candidate.obj').write_bytes(b'object')
    source = write(tmp_path / 'src/a.cpp', '#include SELECT_HEADER\n')
    header = write(tmp_path / 'vendor/foo.h', 'header')
    ns = {'Path': Path, 'hashlib': hashlib, 'json': json, 'os': os, 'shutil': shutil, 're': re,
          'cache_dir': tmp_path / 'cache', 'out': output, 'NATIVE_DOC': True, 'NATIVE_DOC_CACHE': True,
          'restored_cache_records': [], 'rebuild': SimpleNamespace(env=lambda tc: {})}
    exec(compile(ast.Module(body=nodes, type_ignores=[]), str(SOURCE), 'exec'), ns)
    key = {'schema': 3, 'source': str(source), 'include_roots': [str(header.parent)]}
    ns['store_cached']('candidate.obj', key, include_log='Note: including file: ' + str(header),
                       started_ns=time.time_ns() + 1_000_000_000)
    assert not ns['cache_paths']('candidate.obj', key)[0].exists()


def test_response_and_pch_flags_disable_cache_but_float_flags_do_not(cache):
    root, ns = cache
    source = write(root / 'rebuild/2008-06/native-classes/Foo.cpp', 'int f() { return 1; }\n')
    assert ns['cache_key'](source, ['@flags.rsp'])['unsupported_cache_flags']
    assert ns['cache_key'](source, ['/Fpoutput.pch'])['unsupported_cache_flags']
    assert ns['cache_key'](source, ['/Yuheader.h'])['unsupported_cache_flags']
    assert not ns['cache_key'](source, ['/fp:fast'])['unsupported_cache_flags']


def test_cache_rejects_created_include_root_and_compiler_override(tmp_path):
    import os
    import shutil
    import time
    tree = ast.parse(SOURCE.read_text(encoding='utf-8'))
    nodes = [n for n in tree.body if isinstance(n, ast.FunctionDef)
             and n.name in ('cache_paths', 'restore_cached', 'store_cached', 'directory_signature',
                            'include_directories', 'directories_unchanged')]
    output, missing, vendor = tmp_path / 'out', tmp_path / 'missing', tmp_path / 'vendor'
    output.mkdir()
    vendor.mkdir()
    header = vendor / 'foo.h'
    header.write_bytes(b'header')
    (output / 'candidate.obj').write_bytes(b'object')
    ns = {'Path': Path, 'hashlib': hashlib, 'json': json, 'os': os, 'shutil': shutil, 're': re,
          'cache_dir': tmp_path / 'cache', 'out': output, 'NATIVE_DOC': True, 'NATIVE_DOC_CACHE': True,
          'restored_cache_records': []}
    exec(compile(ast.Module(body=nodes, type_ignores=[]), str(SOURCE), 'exec'), ns)
    key = {'include_roots': [str(missing), str(vendor)], 'compiler_environment': {}}
    log = 'Note: including file: ' + str(header)
    ns['store_cached']('candidate.obj', key, include_log=log, started_ns=time.time_ns() + 1_000_000_000)
    assert ns['restore_cached']('candidate.obj', key, 'valid.obj')
    missing.mkdir()
    (missing / 'foo.h').write_bytes(b'shadow')
    assert not ns['restore_cached']('candidate.obj', key, 'stale.obj')
    override = {'include_roots': [str(vendor)], 'compiler_environment': {'CL': '/Ielsewhere'}}
    ns['store_cached']('candidate.obj', override, include_log=log, started_ns=time.time_ns() + 1_000_000_000)
    assert not ns['cache_paths']('candidate.obj', override)[0].exists()


def test_cache_rejects_linked_include_ancestor(cache, monkeypatch):
    root, ns = cache
    source = write(root / 'rebuild/2008-06/native-classes/Foo.cpp', 'int f() { return 1; }\n')
    linked = root / 'linked'
    include = linked / 'include'
    include.mkdir(parents=True)
    original = Path.is_symlink
    monkeypatch.setattr(Path, 'is_symlink', lambda path: path == linked or original(path))
    assert ns['cache_key'](source, ['/I' + str(include)])['unsupported_cache_flags']


def test_directory_validation_rejects_replaced_link(tmp_path, monkeypatch):
    import os
    tree = ast.parse(SOURCE.read_text(encoding='utf-8'))
    nodes = [n for n in tree.body if isinstance(n, ast.FunctionDef) and n.name in ('directory_signature', 'directories_unchanged')]
    scope = {'Path': Path, 'os': os, 'hashlib': hashlib, 'json': json}
    exec(compile(ast.Module(body=nodes, type_ignores=[]), str(SOURCE), 'exec'), scope)
    folder = tmp_path / 'include'
    folder.mkdir()
    signature = scope['directory_signature'](folder)
    original = Path.is_symlink
    monkeypatch.setattr(Path, 'is_symlink', lambda path: path == folder or original(path))
    assert not scope['directories_unchanged']({str(folder): signature})
