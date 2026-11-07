import collections
import importlib.util
import json
import pytest
from pathlib import Path
from types import SimpleNamespace


def test_organized_source_is_included_in_status(tmp_path, monkeypatch):
    path = Path(__file__).resolve().parents[1] / 'roc/native_status.py'
    spec = importlib.util.spec_from_file_location('native_status_organized_test', path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    source = tmp_path / 'rebuild/2008-06/App/src/v8tree/InstanceChildLookup.cpp'
    source.parent.mkdir(parents=True)
    source.write_text('void f() {}\n')
    monkeypatch.setattr(module, 'ROOT', tmp_path)
    monkeypatch.setattr(module, 'load_links', lambda: {})
    monkeypatch.setattr(module, 'load_names', lambda: {})
    monkeypatch.setattr(module, 'load_integration', lambda: {})
    monkeypatch.setattr(module, 'load_db', lambda: ({}, {}, {}, {}))
    assert str(source.relative_to(tmp_path)) in module.build_index()


def test_missing_database_is_not_created(tmp_path, monkeypatch):
    path = Path(__file__).resolve().parents[1] / 'roc/native_status.py'
    spec = importlib.util.spec_from_file_location('native_status_missing_db_test', path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    monkeypatch.setattr(module, 'ROOT', tmp_path)
    with pytest.raises(FileNotFoundError, match='existing server database'):
        module.load_db()
    assert not (tmp_path / 'work/server.db').exists()


def test_json_output_serializes_real_index_fields(monkeypatch, capsys):
    path = Path(__file__).resolve().parents[1] / 'roc/native_status.py'
    spec = importlib.util.spec_from_file_location('native_status_test', path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    monkeypatch.setattr(module, 'parse_args', lambda: SimpleNamespace(path=None, staged=False, json=True))
    monkeypatch.setattr(module, 'build_index', lambda _: {'file.cpp': {
        'miners': collections.Counter({'Colin': 2}), 'models': collections.Counter({'model': 1}),
        'strings': {'z', 'a'}, 'receipts': {'r2', 'r1'}, 'exact': 1}})
    assert module.main() == 0
    result = json.loads(capsys.readouterr().out)['file.cpp']
    assert result['miners'] == {'Colin': 2}
    assert result['strings'] == ['a', 'z']
    assert result['receipts'] == ['r1', 'r2']


def test_missing_native_mappings_warns(monkeypatch, capsys):
    path = Path(__file__).resolve().parents[1] / 'roc/native_status.py'
    spec = importlib.util.spec_from_file_location('native_status_warning_test', path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    monkeypatch.setattr(module, 'parse_args', lambda: SimpleNamespace(path=None, staged=False, json=True))
    monkeypatch.setattr(module, 'build_index', lambda _: {'file.cpp': {
        'addrs': [], 'miners': collections.Counter(), 'models': collections.Counter(),
        'strings': set(), 'receipts': set()}})
    assert module.main() == 0
    assert 'no native source mappings' in capsys.readouterr().err


def test_banner_does_not_claim_complete_class_or_selected_code(monkeypatch):
    path = Path(__file__).resolve().parents[1] / 'roc/native_status.py'
    spec = importlib.util.spec_from_file_location('native_status_labels_test', path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    monkeypatch.setattr(module, '_integ', lambda: {})
    fields = dict(addrs=['00400000'], exact=1, named=1, partial=0, strings=set(),
                  miners=collections.Counter(), models=collections.Counter(), receipts=set(),
                  is_header=False, **{'class': 'Example'})
    banner = module.banner_for('Example.cpp', fields, 'void Example::one() {}')
    assert '1/1 mapped addresses reported exact (subset)' in banner
    assert 'selection unverified' in banner
    assert '100%' not in banner


def test_staged_paths_are_relative_and_keep_spaces(monkeypatch, capsys):
    import subprocess
    path = Path(__file__).resolve().parents[1] / 'roc/native_status.py'
    spec = importlib.util.spec_from_file_location('native_status_staged_test', path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    monkeypatch.setattr(module, 'parse_args', lambda: SimpleNamespace(path=None, staged=True, json=True))
    entry = {'addrs': [], 'miners': collections.Counter(), 'models': collections.Counter(),
             'strings': set(), 'receipts': set()}
    monkeypatch.setattr(module, 'build_index', lambda _: {'rebuild/with space.cpp': entry, 'other.cpp': entry})
    def staged(command, **kwargs):
        assert '--relative' in command and '-z' in command
        return 'rebuild/with space.cpp\0'
    monkeypatch.setattr(subprocess, 'check_output', staged)
    assert module.main() == 0
    assert list(json.loads(capsys.readouterr().out)) == ['rebuild/with space.cpp']


def test_staged_check_reads_index_not_working_file(tmp_path, monkeypatch):
    import subprocess
    path = Path(__file__).resolve().parents[1] / 'roc/native_status.py'
    spec = importlib.util.spec_from_file_location('native_status_index_test', path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    fields = dict(addrs=[], exact=0, named=0, partial=0, strings=set(), miners=collections.Counter(),
                  models=collections.Counter(), receipts=set(), is_header=False, **{'class': 'Example'})
    source = tmp_path / 'file.cpp'
    monkeypatch.setattr(module, 'ROOT', tmp_path)
    monkeypatch.setattr(module, '_integ', lambda: {})
    source.write_text(module.apply_banner('int f() {}\n', 'file.cpp', fields))
    monkeypatch.setattr(module, 'parse_args', lambda: SimpleNamespace(path=None, staged=True, json=False, check=True, write=False))
    monkeypatch.setattr(module, 'build_index', lambda _: {'file.cpp': fields})
    def git(command, **kwargs):
        if command[1] == 'diff':
            return 'file.cpp\0'
        if command[1] == 'rev-parse':
            return 'workspace/\n'
        assert command == ['git', 'show', ':workspace/file.cpp']
        return b'int f() {}\n'
    monkeypatch.setattr(subprocess, 'check_output', git)
    assert module.main() == 1


def test_write_preserves_crlf_and_bom_and_is_idempotent(tmp_path, monkeypatch):
    path = Path(__file__).resolve().parents[1] / 'roc/native_status.py'
    spec = importlib.util.spec_from_file_location('native_status_write_test', path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    source = tmp_path / 'file.cpp'
    source.write_bytes(b'\xef\xbb\xbf// native-flags: /O2\r\nint f() { return 1; }\r\n')
    fields = dict(addrs=[], exact=0, named=0, partial=0, strings=set(), miners=collections.Counter(),
                  models=collections.Counter(), receipts=set(), is_header=False, **{'class': 'Example'})
    monkeypatch.setattr(module, 'ROOT', tmp_path)
    monkeypatch.setattr(module, '_integ', lambda: {})
    monkeypatch.setattr(module, 'parse_args', lambda: SimpleNamespace(path=None, staged=False, json=False, check=False, write=True))
    monkeypatch.setattr(module, 'build_index', lambda _: {'file.cpp': fields})
    monkeypatch.setattr(module, 'require_live_leases', lambda paths: float('inf'))
    assert module.main() == 0
    first = source.read_bytes()
    assert first.startswith(b'\xef\xbb\xbf// native-flags: /O2\r\n')
    assert b'int f() { return 1; }\r\n' in first
    assert b'\n' not in first.replace(b'\r\n', b'')
    assert module.main() == 0
    assert source.read_bytes() == first


def test_write_requires_live_owned_lease(monkeypatch):
    from roc import leases
    path = Path(__file__).resolve().parents[1] / 'roc/native_status.py'
    spec = importlib.util.spec_from_file_location('native_status_lease_test', path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    records = [{'user': 'other', 'expires': module.time.time() + 600, 'patterns': ['rebuild/*']}]
    monkeypatch.setattr(leases, '_api', lambda args: (SimpleNamespace(call=lambda path: {'leases': records}), 'me'))
    with pytest.raises(RuntimeError, match='live lease'):
        module.require_live_leases(['rebuild/file.cpp'])
    records[0]['user'] = 'me'
    assert module.require_live_leases(['rebuild/file.cpp']) > module.time.time()
    records[0]['expires'] = module.time.time() - 1
    with pytest.raises(RuntimeError, match='live lease'):
        module.require_live_leases(['rebuild/file.cpp'])
