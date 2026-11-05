import importlib.util
import json
import threading
from pathlib import Path

import pytest


def test_size_header_lookup_reads_each_header_once_preserving_first_definition(tmp_path, monkeypatch):
    source = Path(__file__).resolve().parents[1] / 'rebuild/2008-06/size_check.py'
    spec = importlib.util.spec_from_file_location('size_header_lookup', source)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    folder = tmp_path / 'include'
    folder.mkdir()
    (folder / 'a.h').write_text('class A;\nclass B : public Base\n{};\n')
    (folder / 'b.h').write_text('class A\n{};\nclass B\n{};\n')
    monkeypatch.setattr(module, 'TREE', tmp_path)
    read_text, reads = Path.read_text, []
    def read(path, *args, **kwargs):
        reads.append(path.name)
        return read_text(path, *args, **kwargs)
    monkeypatch.setattr(Path, 'read_text', read)
    assert module.header_of('A') == 'b.h'
    assert module.header_of('B') == 'a.h'
    assert module.header_of('Absent') is None
    assert reads == ['a.h', 'b.h']


@pytest.mark.parametrize('kind', ['base', 'size'])
@pytest.mark.parametrize('failed', [False, True])
def test_abi_probes_overlap_without_sharing_outputs_or_losing_errors(tmp_path, monkeypatch, kind, failed):
    source = Path(__file__).resolve().parents[1] / 'rebuild/2008-06' / (kind + '_check.py')
    spec = importlib.util.spec_from_file_location('probe_' + kind, source)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    output = tmp_path / 'out'
    output.mkdir()
    monkeypatch.setattr(module, 'ROOT', tmp_path)
    monkeypatch.setattr(module, 'OUT', output)
    monkeypatch.setattr(module, 'header_of', lambda cls: cls + '.h')
    barrier = threading.Barrier(4)
    folders = []
    if kind == 'base':
        monkeypatch.setattr(module.rebuild, 'toolchain', lambda: {})
        monkeypatch.setattr(module, 'rtti_bases', lambda: {cls: [('Base', 0)] for cls in 'DCBA'})
        def probe(header, rows, folder, tc):
            folders.append(folder)
            (folder / 'probe.cpp').write_text(header)
            barrier.wait(timeout=5)
            assert (folder / 'probe.cpp').read_text() == header
            return (None, 'compile failed') if failed and header == 'D.h' else ({0: 0}, None)
    else:
        evidence = tmp_path / 'rebuild/2008-06/manifests/abi-evidence.json'
        evidence.parent.mkdir(parents=True)
        evidence.write_text(json.dumps({'RBX::' + cls: {'alloc_sizes': {'10': []}} for cls in 'DCBA'}))
        def probe(header, classes):
            barrier.wait(timeout=5)
            return ({}, 'compile failed') if failed and header == 'D.h' else ({cls: 16 for cls in classes}, None)
    monkeypatch.setattr(module, 'probe', probe)
    module.main()
    result = json.loads((output / (kind + '-check.json')).read_text())
    assert result['probe_errors'] == ({'D.h': 'compile failed'} if failed else {})
    if kind == 'base':
        assert len(set(folders)) == 4
        assert all(folder.is_relative_to(output / 'base-check') for folder in folders)
        assert result['checked'] == (3 if failed else 4)
        assert result['mismatch'] == []
    else:
        assert [r['class'] for r in result['rows']] == list('ABC' if failed else 'ABCD')
        assert result['no_header'] == []
