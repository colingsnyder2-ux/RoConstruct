import json
from types import SimpleNamespace

import pytest

from roc import native_edit, native_sweep


@pytest.mark.parametrize('before,after', [
    ('int a;\nint b;\n', 'int a;\nint c;\n'),
    ('int a;\n', 'int b;\nint a;\n'),
    ('int a;\nint b;\n', 'int a;\n'),
    ('int a;', 'int a;\n'),
    ('old\n' * 30, 'old\n' * 10 + 'new\n' + 'old\n' * 19),
    ('a\n' + 'same\n' * 20 + 'b\n', 'A\n' + 'same\n' * 20 + 'B\n'),
])
def test_diff_capture_roundtrip(before, after):
    assert native_sweep.apply_edits(before, native_edit.edits(before, after)) == after


@pytest.mark.parametrize('rel', ['../escape.cpp', '/escape.cpp', 'C:/escape.cpp', 'App/../../escape.h', 'App/file.py'])
def test_draft_rejects_paths_outside_native_sources(rel):
    with pytest.raises(ValueError):
        native_edit.name(rel)


@pytest.mark.parametrize('conflict', [False, True])
def test_capture_rebases_unique_anchors_and_preserves_conflicts(tmp_path, conflict):
    tree = tmp_path / 'tree'
    rel = 'App/A.cpp'
    path = tree / rel
    path.parent.mkdir(parents=True)
    original = 'int A::f() { return 1; }\n'
    path.write_text(original)
    ctx = SimpleNamespace(tree=tree, overlay=tmp_path/'overlay', base_revision='first')
    state = native_edit.prepare(ctx, tmp_path/'out', rel, [], {})
    draft = native_edit.folder(tmp_path/'out', rel) / rel
    draft.write_text(original.replace('return 1', 'return 2'))
    path.write_text(original.replace('return 1', 'return 3') if conflict else '// accepted elsewhere\n'+original)
    candidate = draft.read_bytes()
    if conflict:
        with pytest.raises(ValueError, match='baseline changed'):
            native_edit.capture(ctx, tmp_path/'out', rel, state, {})
    else:
        bundle, _ = native_edit.capture(ctx, tmp_path/'out', rel, state, {})
        assert native_sweep.apply_edits(path.read_text(), bundle[rel]) == '// accepted elsewhere\n'+original.replace('return 1', 'return 2')
    assert draft.read_bytes() == candidate


def test_fresh_export_archives_work_before_resetting(tmp_path):
    tree, output, rel = tmp_path/'tree', tmp_path/'out', 'App/A.cpp'
    original = tree / rel
    original.parent.mkdir(parents=True)
    original.write_text('original')
    ctx = SimpleNamespace(tree=tree, overlay=tmp_path/'overlay', base_revision='first')
    native_edit.prepare(ctx, output, rel, [], {})
    draft = native_edit.folder(output, rel) / rel
    draft.write_text('unfinished work')
    original.write_text('new accepted baseline')
    native_edit.prepare(ctx, output, rel, [], {}, fresh=True)
    assert draft.read_text() == 'new accepted baseline'
    archive = next((native_edit.folder(output, rel)/'archive').glob('*.json'))
    assert json.loads(archive.read_text())['sources'][rel] == 'unfinished work'


def test_fresh_does_not_overwrite_an_untracked_editable_file(tmp_path):
    rel = 'App/A.cpp'
    original = tmp_path/'tree'/rel
    original.parent.mkdir(parents=True)
    original.write_text('baseline')
    ctx = SimpleNamespace(tree=tmp_path/'tree', overlay=tmp_path/'overlay', base_revision='first')
    candidate = native_edit.folder(tmp_path/'out', rel)/rel
    candidate.parent.mkdir(parents=True)
    candidate.write_text('existing work without manifest')
    with pytest.raises(ValueError, match='untracked editable file'):
        native_edit.prepare(ctx, tmp_path/'out', rel, [], {}, fresh=True)
    assert candidate.read_text() == 'existing work without manifest'


def test_export_conflict_leaves_no_partial_primary_file(tmp_path):
    rel, header = 'App/A.cpp', 'App/include/A.h'
    ctx = SimpleNamespace(tree=tmp_path/'tree', overlay=tmp_path/'overlay', base_revision='first')
    for path in [rel, header]:
        original = ctx.tree / path
        original.parent.mkdir(parents=True, exist_ok=True)
        original.write_text('baseline')
    directory = native_edit.folder(tmp_path/'out', rel)
    candidate = directory / header
    candidate.parent.mkdir(parents=True)
    candidate.write_text('untracked header work')
    with pytest.raises(ValueError, match='untracked editable file'):
        native_edit.prepare(ctx, tmp_path/'out', rel, [header], {})
    assert not (directory/rel).exists()
    assert candidate.read_text() == 'untracked header work'
