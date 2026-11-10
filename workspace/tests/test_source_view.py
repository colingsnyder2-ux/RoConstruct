import pytest
from roc import source, libs


def setup(tmp_path, monkeypatch, text):
    p=tmp_path/'src/test/00401000.cpp';p.parent.mkdir(parents=True);p.write_text(text)
    monkeypatch.setitem(libs.RECIPES,'source-test',{'src':'Example'})
    return p


def test_inline(tmp_path,monkeypatch):
    setup(tmp_path,monkeypatch,'int f() { return 3; }')
    assert source.resolve('test','0x401000',tmp_path)['source']=='int f() { return 3; }'


def test_library_view_preserves_wrapper(tmp_path,monkeypatch):
    p=setup(tmp_path,monkeypatch,'// roc-lib: source-test real.cpp\n')
    real=tmp_path/'tools/libs/Example/real.cpp';real.parent.mkdir(parents=True);real.write_text('void actual() {}')
    result=source.resolve('test','00401000',tmp_path)
    assert result['source']=='void actual() {}'
    assert result['source_path']==str(real)
    assert p.read_text()=='// roc-lib: source-test real.cpp\n'


def test_missing_unit_uses_existing_managed_store(tmp_path,monkeypatch):
    setup(tmp_path,monkeypatch,'// roc-lib: source-test roc_unit.cpp\n')
    monkeypatch.setattr(libs,'generated_units',lambda:{'Example':{'roc_unit.cpp':'void managed() {}'}})
    assert source.resolve('test','00401000',tmp_path)['source']=='void managed() {}'


def test_missing_is_explicit(tmp_path,monkeypatch):
    setup(tmp_path,monkeypatch,'// roc-lib: source-test missing.cpp\n')
    monkeypatch.setattr(libs,'generated_units',lambda:{})
    with pytest.raises(RuntimeError,match='Implementation missing'):source.resolve('test','00401000',tmp_path)


def test_escape_rejected(tmp_path,monkeypatch):
    setup(tmp_path,monkeypatch,'// roc-lib: source-test ../outside.cpp\n')
    with pytest.raises(ValueError,match='escapes'):source.resolve('test','00401000',tmp_path)
