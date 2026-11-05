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
    assert description == field
    assert sent[0]['embeds'][0]['fields'][0]['name'] == '📄 New native files'
    assert len(description) <= 4096
    assert '60.00%' in field and 'no runtime activation or server credit' not in field
    assert 'target bytes' not in field
    assert any(f['name'] == '⚡ Integration Rate' for f in sent[0]['embeds'][0]['fields'])
    assert sum(field.count(c) for c in ('🟪', '🟧', '🩷', '⬜')) == 27  # 23 cells + four-status legend
    assert len(field) <= 1024 and acknowledged == [row]


def test_integration_rate_uses_only_integrated_history(tmp_path):
    from datetime import datetime, timezone
    from roc.integration_site import integration_rate
    now = datetime(2026, 11, 5, 13, tzinfo=timezone.utc).timestamp()
    data = {'updated': '2026-11-05 12:00 UTC', 'groups': {'integrated': {'functions': 10, 'bytes': 100}, 'other': {'functions': 90, 'bytes': 900}}, 'native_code': {'inactive': {'functions': 20, 'bytes': 200}}}
    assert 'second progress sample' in integration_rate(data, tmp_path, now)
    assert 'second progress sample' in integration_rate(data, tmp_path, now)
    data['updated'] = '2026-11-05 13:00 UTC'
    data['groups']['integrated'] = {'functions': 12, 'bytes': 200}
    data['groups']['other'] = {'functions': 88, 'bytes': 800}
    data['native_code']['inactive'] = {'functions': 2000, 'bytes': 20000}
    value = integration_rate(data, tmp_path, now)
    assert '**2 functions/hr**' in value and '**100 B/hr**' in value
    assert 'observed 60 min' in value and 'byte ETA 8h 0m' in value
    assert integration_rate(data, tmp_path, now) == value  # Restart/repeated delivery preserves samples.
    before = (tmp_path / 'work/native-integration-rate.json').read_bytes()
    data['updated'] = '2026-11-05 12:30 UTC'
    assert 'current progress' in integration_rate(data, tmp_path, now)
    assert (tmp_path / 'work/native-integration-rate.json').read_bytes() == before
    data['updated'] = '2026-11-05 13:00 UTC'
    data['groups']['integrated']['functions'] = 9
    assert 'second progress sample' in integration_rate(data, tmp_path, now)
    assert 'fresh progress' in integration_rate(data, tmp_path, now + 7 * 3600)
