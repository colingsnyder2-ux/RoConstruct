"""Contributor packages omit the host module; analysis must still finish."""
import ast
import io
import json
from pathlib import Path
import sys
import urllib.request


def reseed(root):
    source = Path(__file__).resolve().parents[1] / 'roc.py'
    tree = ast.parse(source.read_text(encoding='utf-8'))
    function = next(node for node in tree.body if isinstance(node, ast.FunctionDef) and node.name == '_hot_reseed')
    namespace = {'ROOT': root, 'json': json, 'settings': lambda: {'token': 'test-token'}}
    exec(compile(ast.Module(body=[function], type_ignores=[]), str(source), 'exec'), namespace)
    return namespace['_hot_reseed']


def test_contributor_analysis_needs_neither_server_module_nor_network(tmp_path, monkeypatch):
    monkeypatch.setitem(sys.modules, 'roc.server', None)
    def unexpected_request(*args, **kwargs):
        raise AssertionError('Contributor analysis must not contact a local host')
    monkeypatch.setattr(urllib.request, 'urlopen', unexpected_request)
    reseed(tmp_path)('2008-06')


def test_host_analysis_preserves_authenticated_local_reseed(tmp_path, monkeypatch, capsys):
    key = tmp_path / 'work/state/admin.key'
    key.parent.mkdir(parents=True)
    key.write_text('test-admin\n')
    requests = []
    def respond(request, timeout):
        requests.append((request, timeout))
        return io.BytesIO(json.dumps({'resized': ['00500000'], 'exact_after_resize': []}).encode())
    monkeypatch.setitem(sys.modules, 'roc.server', None)
    monkeypatch.setattr(urllib.request, 'urlopen', respond)
    reseed(tmp_path)('2008-06')
    request, timeout = requests[0]
    assert request.full_url == 'http://127.0.0.1:8765/v1/admin/reseed'
    assert json.loads(request.data) == {'client': '2008-06'}
    assert request.get_header('X-roc-admin') == 'test-admin'
    assert request.get_header('X-roc-token') == 'test-token'
    assert timeout == 1800
    assert 'live server reseeded: 1 resized' in capsys.readouterr().out
