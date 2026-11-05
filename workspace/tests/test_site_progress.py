import json

from roc import native_files_notify as files, reports
from roc.integration_site import progress_description


def test_native_digest_uses_shared_progress_without_credit(monkeypatch, tmp_path):
    snapshot = {'updated': '2026-11-05 12:00 UTC', 'groups': {
        'integrated': {'functions': 1, 'bytes': 20},
        'owned_waiting': {'functions': 2, 'bytes': 50},
        'exact_waiting': {'functions': 1, 'bytes': 30}},
        'native_code': {'inactive': {'functions': 1, 'bytes': 40},
                        'draft': {'functions': 1, 'bytes': 10}}}
    folder = tmp_path / 'docs'
    folder.mkdir()
    (folder / 'integration.json').write_text(json.dumps(snapshot))
    monkeypatch.setattr(files, 'ROOT', tmp_path)
    monkeypatch.setattr(reports, 'server_mines_webhook', lambda: 'https://example.invalid/webhook')
    monkeypatch.setattr(files.time, 'sleep', lambda _: None)
    sent = []

    class Response:
        def read(self): return b''

    def send(request, **kwargs):
        sent.append(json.loads(request.data))
        return Response()

    monkeypatch.setattr(files.urllib.request, 'urlopen', send)
    row = ('owner/repo', 'work', 'a' * 40, 'workspace/rebuild/2008-06/native-classes/A.cpp', 'new')
    acknowledged = []
    assert files.post_files([row], on_sent=acknowledged.extend)
    description = sent[0]['embeds'][0]['description']
    field = progress_description(snapshot)
    assert description.startswith(field + '\n\n')
    assert len(description) <= 4096
    assert '60.00%' in field and 'no runtime activation or server credit' in field
    assert sum(field.count(c) for c in ('🟪', '🟧', '🩷', '⬜')) == 26  # 23 cells + legend
    assert len(field) <= 1024 and acknowledged == [row]
