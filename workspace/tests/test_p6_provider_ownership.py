import ast
import os
import re
from pathlib import Path

import pytest


SOURCE = Path(__file__).resolve().parents[1] / 'rebuild/2008-06/p6/build_client.py'
MARKER = '// Compatibility translation unit; compile this file or the organized source, not both.'


@pytest.fixture
def check():
    tree = ast.parse(SOURCE.read_text(encoding='utf-8'))
    nodes = [n for n in tree.body if isinstance(n, ast.FunctionDef)
             and n.name in ('source_owner', 'check_source_ownership')]
    assert {n.name for n in nodes} == {'source_owner', 'check_source_ownership'}
    scope = {'Path': Path, 'os': os, 're': re}
    exec(compile(ast.Module(body=nodes, type_ignores=[]), str(SOURCE), 'exec'), scope)
    return scope['check_source_ownership']


def write(path, content):
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(content, encoding='utf-8')
    return path


def test_old_and_new_source_paths_cannot_both_be_selected(check, tmp_path):
    real = write(tmp_path / 'App/src/Foo.cpp', 'int foo() { return 1; }\n')
    shim = write(tmp_path / 'native-classes/Foo.cpp', MARKER + '\n#include "../App/src/Foo.cpp"\n')
    with pytest.raises(RuntimeError, match='Duplicate provider source'):
        check([('old.obj', shim), ('new.obj', real)])


def test_two_shims_to_same_source_are_rejected(check, tmp_path):
    write(tmp_path / 'App/src/Foo.cpp', 'int foo() { return 1; }\n')
    old = write(tmp_path / 'native-classes/Foo.cpp', '// native-flags: /O2\n' + MARKER + '\n#include "../App/src/Foo.cpp"\n')
    alias = write(tmp_path / 'other/Foo.cpp', '// >>> native-status (generated) -- do not edit >>>\n// status\n// <<< native-status | src deadbeef\n' + MARKER + '\n#include "../App/src/Foo.cpp"\n')
    with pytest.raises(RuntimeError, match='Duplicate provider source'):
        check([('one.obj', old), ('two.obj', alias)])


def test_duplicate_object_name_is_rejected(check, tmp_path):
    a = write(tmp_path / 'a.cpp', 'int a;\n')
    b = write(tmp_path / 'b.cpp', 'int b;\n')
    with pytest.raises(RuntimeError, match='Duplicate provider object'):
        check([('same.obj', a), ('SAME.OBJ', b)])


def test_invalid_and_cyclic_shims_fail_closed(check, tmp_path):
    a = write(tmp_path / 'a.cpp', MARKER + '\n#include "b.cpp"\n')
    b = write(tmp_path / 'b.cpp', MARKER + '\n#include "a.cpp"\n')
    with pytest.raises(RuntimeError, match='Cyclic compatibility source'):
        check([('a.obj', a)])
    b.write_text(MARKER + '\n#include "a.cpp"\nint extra;\n', encoding='utf-8')
    with pytest.raises(RuntimeError, match='Malformed compatibility source'):
        check([('a.obj', a)])


def test_distinct_sources_are_accepted(check, tmp_path):
    a = write(tmp_path / 'a.cpp', 'int a;\n')
    b = write(tmp_path / 'b.cpp', 'int b;\n')
    check([('a.obj', a, []), ('b.obj', b)])


def test_guard_runs_before_core_and_doc_compiles():
    text = SOURCE.read_text(encoding='utf-8')
    assert text.index("check_source_ownership(units + [('P6Data.obj'") < text.index('for obj, source, flags in units:')
    assert text.index('check_source_ownership(units + doc_sources') < text.index('pool.map(compile_doc_source')


def test_known_split_profile_is_narrow_and_fail_closed(check, tmp_path):
    target = write(tmp_path / 'App/src/ServiceChangeHistory.cpp',
                   '#ifndef SERVICE_HISTORY_FIND_ONLY\n#endif\n#ifndef SERVICE_HISTORY_CREATE_ONLY\n#endif\n')
    source = write(tmp_path / 'native-classes/ServiceChangeHistory.cpp',
                   '// native-flags: /DSERVICE_HISTORY_FIND_ONLY\n' + MARKER +
                   '\n#include "../App/src/ServiceChangeHistory.cpp"\n')
    entries = [('NativeServiceChangeHistoryFull.obj', source), ('ServiceChangeHistoryCreateFull.obj', source)]
    check(entries, source)
    with pytest.raises(RuntimeError, match='Duplicate provider source'):
        check(entries)
    with pytest.raises(RuntimeError, match='Duplicate provider source'):
        check([entries[0], ('other.obj', source)], source)
    target.write_text('#ifndef SERVICE_HISTORY_FIND_ONLY\n#endif\n', encoding='utf-8')
    with pytest.raises(RuntimeError, match='Duplicate provider source'):
        check(entries, source)


def test_split_create_profile_keeps_its_define():
    tree = ast.parse(SOURCE.read_text(encoding='utf-8'))
    matching = [n for n in ast.walk(tree) if isinstance(n, ast.If)
                and isinstance(n.test, ast.Compare)
                and isinstance(n.test.left, ast.Name) and n.test.left.id == 'obj'
                and any(isinstance(c, ast.Constant) and c.value == 'ServiceChangeHistoryCreateFull.obj'
                        for c in n.test.comparators)]
    assert len(matching) == 1
    values = {n.value for n in ast.walk(matching[0]) if isinstance(n, ast.Constant) and isinstance(n.value, str)}
    assert '/DSERVICE_HISTORY_CREATE_ONLY' in values
