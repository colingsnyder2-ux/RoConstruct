import ast
import hashlib
import json
import re
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
                 'tc': {'cl': compiler}, 'Path': Path, 'hashlib': hashlib, 're': re}
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


