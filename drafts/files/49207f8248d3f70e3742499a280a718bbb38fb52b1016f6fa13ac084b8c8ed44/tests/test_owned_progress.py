import json

from roc import owned_progress


def test_notifications_deduplicate_and_retain_failed_delivery(tmp_path, monkeypatch):
    owners = tmp_path / 'rebuild/2008-06/out/RbxgsApp';owners.mkdir(parents=True)
    (owners / 'owned-symbols.json').write_text('{"00400000":[{"symbol":"?f@Native@@QAEXXZ"}]}')
    monkeypatch.setattr(owned_progress, 'server_mines_webhook', lambda: 'https://example.test/webhook')
    requests = []
    def failed(*args, **kwargs):
        raise OSError('temporary failure')
    monkeypatch.setattr(owned_progress.urllib.request, 'urlopen', failed)
    before = dict(owned_addrs=[])
    report = dict(module='RbxgsApp', owned_addrs=['00400000'])
    args = (tmp_path, before, report, 'colin', 'actual model')
    first = owned_progress.record(*args, log=lambda _: None)
    assert first == dict(discovered=1, sent=0, pending=1)
    class Response:
        def __enter__(self):return self
        def __exit__(self, *args):pass
        def read(self):return b'{"id":"receipt"}'
    def delivered(request, **kwargs):
        requests.append(json.loads(request.data))
        return Response()
    monkeypatch.setattr(owned_progress.urllib.request, 'urlopen', delivered)
    assert owned_progress.record(*args)['sent'] == 1
    assert owned_progress.record(*args)['sent'] == 0
    assert len(requests) == 1
    embed = requests[0]['embeds'][0]
    assert embed['color'] == 0xA855F7
    assert '0 accepted integration credits' in str(embed)
    assert '00400000' in str(embed)


def test_accepted_or_analog_addresses_never_notified(tmp_path, monkeypatch):
    proof = tmp_path / 'work/integration';proof.mkdir(parents=True)
    (proof / 'progress-native.json').write_text('{"addresses":["00400000"]}')
    monkeypatch.setattr(owned_progress, 'server_mines_webhook', lambda: None)
    report = dict(module='RbxgsApp', owned_addrs=['00400000'])
    assert owned_progress.record(tmp_path, dict(owned_addrs=[]), report, 'colin')['discovered'] == 0
    report['module'] = 'CodegenAnalogs'
    assert owned_progress.record(tmp_path, dict(owned_addrs=[]), report, 'colin')['discovered'] == 0
