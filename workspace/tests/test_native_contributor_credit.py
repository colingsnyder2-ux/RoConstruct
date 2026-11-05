import json

from roc import native_files_notify as files
from roc.integration_site import progress_description


def test_mixed_drafts_credit_each_uploader_without_pings(monkeypatch):
    ids = ['a' * 64, 'b' * 64]
    people = {ids[0]: 'coldek', ids[1]: 'Yeetserama\n**@everyone**'}
    monkeypatch.setattr(files, 'git', lambda *a, **kw: json.dumps({'user': people[a[1].split('/')[-1][:-5]]}))
    rows = [('owner/repo', 'work', 'c' * 40, 'drafts/files/' + bid + '/rebuild/2008-06/native-classes/A.cpp', 'new') for bid in ids]
    payloads = files.build_payloads(rows)
    assert len(payloads) == 2
    descriptions = [x['embeds'][0]['description'] for x in payloads]
    assert any('**Contributor:** coldek' in s for s in descriptions)
    assert any(r'\*\*@everyone\*\*' in s for s in descriptions)
    assert all(x['allowed_mentions'] == {'parse': []} for x in payloads)
    assert all('Inactive draft upload' in s and '[native-classes/A.cpp](' in s for s in descriptions)
    assert sum(s.count('https://github.com/') for s in descriptions) == 2


def test_fork_credit_and_unknown_upload_do_not_invent_authors(monkeypatch):
    monkeypatch.setattr(files, 'upstream_slug', lambda: 'owner/repo')
    assert files.contributor('mewpokemons/RoConstruct', 'a' * 40, 'A.cpp') == '**Contributor:** mewpokemons'
    monkeypatch.setattr(files, 'git', lambda *a, **kw: '')
    assert files.contributor('owner/repo', 'a' * 40, 'drafts/files/' + 'b' * 64 + '/A.cpp') == '**Contributor:** Unknown uploader'
    assert files.contributor('owner/repo', 'a' * 40, 'A.cpp') == '**Commit author:** Unknown author'


def test_progress_bar_first_and_spaced_bold_totals():
    snapshot = {'groups': {'integrated': {'functions': 1, 'bytes': 20}, 'exact_waiting': {'functions': 2, 'bytes': 80}}, 'native_code': {'inactive': {'functions': 1, 'bytes': 40}}}
    value = progress_description(snapshot)
    sections = value.split('\n\n')
    assert sections[0].startswith('**2008-06 Client**\n**1 / 3 integrated**')
    assert sections[1].endswith('**60.00% native code**')
    assert sum(sections[1].count(c) for c in '🟪🟧🩷⬜') == 23
    assert '**1 inactive exact**' in value
    assert 'no runtime activation or server credit' in sections[-1]
    assert len(value) <= 1024


def test_digest_fields_preserve_links_people_models_and_limits(monkeypatch):
    bid = 'a' * 64
    monkeypatch.setattr(files, 'git', lambda *a, **kw: json.dumps({'user': 'coldek', 'model': 'gpt-6.1-sol'}))
    paths = ['drafts/files/' + bid + '/rebuild/2008-06/native-classes/' + 'LongClass' * 16 + str(i) + '.cpp' for i in range(8)]
    rows = [('owner/repo', 'work', 'b' * 40, path, 'new') for path in paths]
    payloads = files.build_payloads(rows)
    for body in payloads:
        original = body['embeds'][0]['description']
        selected = [row for row in rows if files.link(row[0], row[2], row[3]) in original]
        files.format_payload(body, '**2008-06 Client**\nbar', selected)
        embed = body['embeds'][0]
        assert embed['description'] == '**2008-06 Client**\nbar'
        assert all(len(f['value']) <= 1024 for f in embed['fields'])
        assert any(f['name'] == '🏆 Workers' and 'coldek' in f['value'] for f in embed['fields'])
        assert any(f['name'] == '🔧 Models' and 'gpt-6.1-sol' in f['value'] for f in embed['fields'])
        content = '\n'.join(f['value'] for f in embed['fields'])
        assert all(files.link(row[0], row[2], row[3]) in content for row in selected)
        assert all(f['name'] != '⚡ Mining Rate' for f in embed['fields'])
