from roc import rebuild_audit as audit


def test_namespace_function_is_not_a_class():
    assert audit.scope('?f@RBX@@YAXXZ') is None
    assert audit.scope('?f@Thing@RBX@@QAEXXZ') == 'RBX::Thing'
    assert audit.scope('??0Thing@RBX@@QAE@XZ') == 'RBX::Thing'
    assert audit.scope('??1Thing@@UAE@XZ') == 'Thing'


def test_class_backlog_prefers_names_retains_hint_confidence_and_offsets():
    functions = {'a': {'unit': 'Wrong', 'this_reads': [4], 'this_writes': [8]},
                 'b': {'unit': 'Unknown', 'this_reads': [12]}}
    rows = [{'addr': a, 'source_kind': 'snippet', 'score': 100} for a in functions]
    result = audit.class_backlog(functions, rows,
        {'a': {'symbol': '?get@Thing@RBX@@QAEHXZ', 'score': 100}}, {}, {'RBX::Thing': {'alloc_sizes': {'0x10': ['c']}}})
    by_class = {r['class']: r for r in result}
    assert by_class['RBX::Thing']['basis'] == {'symbol': 1}
    assert by_class['RBX::Thing']['this_reads'] == {4: 1}
    assert by_class['RBX::Thing']['abi']['alloc_sizes'] == {'0x10': ['c']}
    assert by_class['Unknown']['basis'] == {'unit_hint': 1}
    assert result[-1]['cumulative'] == 2


def test_vendor_shape_match_does_not_establish_source_provenance():
    rows = [{'source_kind': 'vendor-file', 'score': 100, 'file': 'src/OgreScriptLexer.cpp', 'unit': 'CNullDoc'},
            {'source_kind': 'vendor-file', 'score': 100, 'file': 'src/XTPButton.cpp', 'unit': 'CXTPButton'},
            {'source_kind': 'vendor-file', 'score': 100, 'file': 'a.cpp', 'unit': 'seg_0000'}]
    result = audit.vendor_review(rows)
    assert [r['provenance'] for r in result] == ['unit_file_conflict', 'compatible_hint', 'unresolved']
    assert not any(r['authentic_source_verified'] for r in result)


def test_parent_pairing_uses_funcinfo_not_nearest_address():
    functions = {'1000': {'kind': 'code', 'data_refs': ['0x2000']},
                 '1100': {'kind': 'code'},
                 '2000': {'kind': 'gen'},
                 '3000': {'kind': 'eh', 'unwind_context': [{'handler': 0x2000}]},
                 '4000': {'kind': 'eh'},
                 '5000': {'kind': 'adjustor', 'call_targets': ['1000']}}
    parents = audit.piece_parents(functions)
    assert parents['3000'] == {'1000'}
    assert parents['4000'] == set()
    assert parents['5000'] == {'1000'}


def test_byte_index_keeps_twins_and_rejects_missing_relocations(monkeypatch):
    from roc import match
    targets = {'a': (b'\xb8\x01\0\0\0\xc3', [1], {}),
               'b': (b'\xb8\x02\0\0\0\xc3', [1], {})}
    monkeypatch.setattr(match, 'target', lambda client, addr: targets[addr])
    index = audit.ByteIndex('test', {'a': {'kind': 'code'}, 'b': {'kind': 'eh'}})
    assert index.hits(b'\xb8\0\0\0\0\xc3', [1]) == ['a', 'b']
    assert index.hits(b'\xb8\x01\0\0\0\xc3', []) == []


def test_adjustor_parent_is_decoded_from_jump(monkeypatch):
    functions = {'00001000': {'kind': 'code'}, '00002000': {'kind': 'adjustor'}}
    monkeypatch.setattr(audit.match, 'target', lambda *_: (b'\xe9\xfb\xef\xff\xff', [], {}))
    assert audit.piece_parents(functions, 'test')['00002000'] == {'00001000'}


def test_cached_review_rejects_changed_object_even_with_same_mtime(tmp_path, monkeypatch):
    import hashlib
    import json
    import os
    monkeypatch.setattr(audit.rebuild, 'ROOT', tmp_path)
    monkeypatch.setattr(audit.rebuild, 'workspace', lambda _: tmp_path)
    (tmp_path / 'out/App').mkdir(parents=True)
    (tmp_path / 'work/test').mkdir(parents=True)
    inputs = tmp_path / 'work/test/functions.jsonl'
    inputs.write_bytes(b'functions')
    report = tmp_path / 'out/App/report.json'
    report.write_bytes(b'report')
    obj = tmp_path / 'out/App/a.obj'
    obj.write_bytes(b'object')
    digest = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
    value = {'functions_sha256': digest(inputs), 'modules': [
        {'module': 'App', 'report_sha256': digest(report),
         'objects': [{'path': str(obj), 'sha256': digest(obj)}]}]}
    (tmp_path / 'out/ownership-review.json').write_text(json.dumps(value))
    assert audit.cached_review('test') == value
    stamp = obj.stat()
    obj.write_bytes(b'edited')
    os.utime(obj, ns=(stamp.st_atime_ns, stamp.st_mtime_ns))
    assert audit.cached_review('test') is None


def test_status_per_kind_uses_linked_set_not_failed_report_counts(tmp_path, monkeypatch):
    import json
    rebuild = audit.rebuild
    workspace = tmp_path / 'rebuild/test'
    modules = workspace / 'modules'
    modules.mkdir(parents=True)
    for name, linked, addrs in [('Good', True, ['a', 'b']), ('Bad', False, ['b', 'c'])]:
        (modules / (name + '.json')).write_text(json.dumps({'name': name, 'layers': []}))
        out = workspace / 'out' / name
        (out / 'linked').mkdir(parents=True)
        (out / 'linked/linked.lib').write_bytes(b'library')
        (out / 'report.json').write_text(json.dumps({'linked': linked, 'test_exit': 0 if linked else None,
            'owned_addrs': addrs, 'owned_2008': 2, 'object_functions': 2}))
        (out / 'linked/a.obj').write_bytes(b'object')
    monkeypatch.setattr(rebuild, 'ROOT', tmp_path)
    monkeypatch.setattr(rebuild.match, 'coff_functions', lambda _: [])
    monkeypatch.setattr(rebuild, 'pair', lambda *_: [('one', 20, ['a']), ('twins', 20, ['b', 'c'])])
    monkeypatch.setattr(rebuild.match, '_functions', lambda _: {'a': {'kind': 'code'}})
    monkeypatch.setattr(rebuild, 'progress', lambda *_, **kw: None)
    monkeypatch.setattr(audit, 'cached_review', lambda _: None)
    messages = []
    _, owned = rebuild.status('test', log=messages.append)
    assert owned == {'a'}
    assert "linked per-kind counts: {'code': 1}" in messages
    assert any('reports (includes failed links): 3; 2 absent' in s for s in messages)
