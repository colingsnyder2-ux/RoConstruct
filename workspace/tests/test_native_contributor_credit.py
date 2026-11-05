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
    assert set(sections[0]) <= set('🟪🟧🩷⬜') and len(sections[0]) == 23
    assert sections[1].startswith('**Integrated code · 60.00%**')
    assert '**1 integrated**' in sections[2] and '**1 inactive exact**' in sections[2]
    assert 'no runtime activation or server credit' in sections[-1]
    assert len(value) <= 1024
