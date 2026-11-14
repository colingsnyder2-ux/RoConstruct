import json
import sqlite3
import hashlib
from pathlib import Path

from roc import integration_site


def test_linked_native_inventory_uses_passing_linked_modules(tmp_path):
    for name, linked, test, addresses in (
            ('ATL', True, 0, ['00401000', '00402000']),
            ('Broken', False, None, ['00403000']),
            ('Failing', True, 1, ['00404000'])):
        folder = tmp_path / 'rebuild/2008-06/out' / name
        folder.mkdir(parents=True)
        (folder / 'report.json').write_text(json.dumps({
            'linked': linked, 'test_exit': test, 'owned_addrs': addresses,
        }))

    assert integration_site.linked_native_inventory(tmp_path) == {'00401000', '00402000'}


def test_site_groups_and_merged_receipts(tmp_path):
    (tmp_path / "research").mkdir()
    (tmp_path / "research/native-source-lock.json").write_text("{}")
    work = tmp_path / 'work'
    (work / 'integration').mkdir(parents=True)
    (work / '2008-06').mkdir()
    (work / 'integration/progress-native.json').write_text(json.dumps({'addresses': ['00400000']}))
    (work / '2008-06/functions.jsonl').write_text('\n'.join(
        json.dumps({'addr': '%08x' % (0x400000 + n), 'size': 10 * (n + 1)}) for n in range(4)))
    trial = tmp_path / 'rebuild/2008-06/out/Trial'
    trial.mkdir(parents=True)
    (trial / 'report.json').write_text(json.dumps({'linked': True, 'test_exit': 0, 'owned_addrs': ['00400001']}))
    db = sqlite3.connect(work / 'server.db')
    db.executescript('''
        CREATE TABLE funcs(client TEXT, addr TEXT, score INTEGER);
        CREATE TABLE integration_jobs(id TEXT, user TEXT, model TEXT, unit TEXT, receipt TEXT, updated REAL, state TEXT);
        CREATE TABLE integration_credit(client TEXT, user TEXT, model TEXT);
        CREATE TABLE integration_claims(client TEXT, unit TEXT, user TEXT, worker TEXT,
                                       expires REAL, state TEXT, addresses TEXT);
    ''')
    db.executemany('INSERT INTO funcs VALUES (?,?,?)', [('2008-06', '%08x' % (0x400000 + n), s)
                                                       for n, s in enumerate([100, 100, 50, 0])])
    receipt = json.dumps({'job': 'merged-primary', 'gains': ['00400000', '00400001'],
                          'new_distinct': ['00400000'], 'owned_after': 2})
    db.executemany('INSERT INTO integration_jobs VALUES (?,?,?,?,?,?,?)', [
        (job, 'tester', 'model', 'RBX::Camera', receipt, 1, 'accepted') for job in ('first', 'second')])
    db.execute('INSERT INTO integration_jobs VALUES (?,?,?,?,?,?,?)',
               ('pending', 'tester', 'model', 'RBX::Camera', '{}', 2, 'queued'))
    db.execute('INSERT INTO integration_credit VALUES (?,?,?)', ('2008-06', 'tester', 'model'))
    db.commit()
    db.close()
    data = integration_site.build(tmp_path, log=lambda _: None)
    assert data['groups'] == {
        'integrated': {'functions': 1, 'bytes': 10}, 'exact_waiting': {'functions': 1, 'bytes': 20},
        'partial': {'functions': 1, 'bytes': 30}, 'unmined': {'functions': 1, 'bytes': 40},
        'owned_waiting': {'functions': 0, 'bytes': 0}}
    assert data['activity'] == data['working'] == {}
    assert len(data['jobs']) == 1
    assert data['jobs'][0]['gains'] == 2
    assert data['jobs'][0]['distinct_gains'] == 1
    assert data['daily'] == [{'day': '1969-12-31', 'gains': 1, 'jobs': 1, 'models': {'model': {'gains': 1, 'jobs': 1}}}]
    assert data['leaderboard'][0]['native_credits'] == 1
    assert json.loads((tmp_path / 'docs/integration.json').read_text()) == data
    recorded = {'day': '2020-01-01', 'groups': data['groups']}
    data['history'].insert(0, recorded)
    (tmp_path / 'docs/integration.json').write_text(json.dumps(data))
    with (work / '2008-06/functions.jsonl').open('a') as handle:
        handle.write('\n' + json.dumps({'addr': '00900000', 'size': 1000, 'kind': 'thunk'}))
    refreshed = integration_site.build(tmp_path, log=lambda _: None)
    assert refreshed['groups'] == data['groups']
    assert refreshed['history'][0] == recorded
    assert len(refreshed['history']) == 2


def test_readable_native_method():
    assert integration_site.readable('?askSetParent@Camera@RBX@@UBEXPAVInstance@2@@Z') == 'RBX::Camera::askSetParent'
    assert integration_site.readable('??1Camera@RBX@@UAE@XZ') == 'RBX::Camera::~Camera'


def test_inactive_inline_header_source_location(tmp_path):
    header = tmp_path / 'rebuild/2008-06/native-headers/Ogre/Entity.h'
    header.parent.mkdir(parents=True)
    header.write_text('class Entity {\npublic:\n    int getCount() const { return count; }\n};\n')
    receipts = tmp_path / 'work/2008-06/shared-layouts'
    receipts.mkdir(parents=True)
    (receipts / 'getter.json').write_text(json.dumps({
        'address': '006857e0', 'symbol': '?getCount@Entity@Ogre@@QBEHXZ',
        'exact': True, 'source_sha256': hashlib.sha256(header.read_bytes()).hexdigest(),
    }))
    row = integration_site.inactive_code(tmp_path)['006857e0']
    assert row[1] is True
    assert row[3] == ['rebuild/2008-06/native-headers/Ogre/Entity.h', 3]


def test_inactive_index_skips_temporary_search_trees(tmp_path, monkeypatch):
    source = tmp_path / 'rebuild/2008-06/native-classes/accepted/Foo.cpp'
    source.parent.mkdir(parents=True)
    source.write_text('void foo() {}\n')
    scratch = tmp_path / 'work/native-client/search/trial.cpp'
    scratch.parent.mkdir(parents=True)
    scratch.write_text('temporary trial')
    receipts = tmp_path / 'work/2008-06/shared-layouts'
    receipts.mkdir(parents=True)
    (receipts / 'foo.json').write_text(json.dumps({
        'address': '00401000', 'symbol': '?foo@@YAXXZ', 'exact': True,
        'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(),
    }))
    read_bytes = Path.read_bytes

    def checked_read(path):
        assert path != scratch
        return read_bytes(path)

    monkeypatch.setattr(Path, 'read_bytes', checked_read)
    row = integration_site.inactive_code(tmp_path)['00401000']
    assert row[3][0] == 'rebuild/2008-06/native-classes/accepted/Foo.cpp'


def test_daily_history_exceeds_recent_jobs(tmp_path):
    (tmp_path / "research").mkdir()
    (tmp_path / "research/native-source-lock.json").write_text("{}")
    work = tmp_path / 'work/2008-06'
    work.mkdir(parents=True)
    (work / 'functions.jsonl').write_text('')
    db = sqlite3.connect(tmp_path / 'work/server.db')
    db.executescript('''
        CREATE TABLE funcs(client TEXT, addr TEXT, score INTEGER);
        CREATE TABLE integration_jobs(id TEXT, user TEXT, model TEXT, unit TEXT, receipt TEXT, updated REAL, state TEXT);
        CREATE TABLE integration_credit(client TEXT, user TEXT, model TEXT);
        CREATE TABLE integration_claims(client TEXT, unit TEXT, user TEXT, worker TEXT,
                                       expires REAL, state TEXT, addresses TEXT);
    ''')
    db.executemany('INSERT INTO integration_jobs VALUES (?,?,?,?,?,?,?)', [
        (str(n), 'tester', 'model', 'RBX::Camera', json.dumps({'new_distinct': [str(n)]}),
         1793145600 + n, 'accepted') for n in range(105)])  # Oct 28 UTC, still Oct 27 Eastern.
    db.commit()
    db.close()
    data = integration_site.build(tmp_path, log=lambda _: None)
    assert len(data['jobs']) == 100
    assert data['daily'] == [{'day': '2026-10-27', 'gains': 105, 'jobs': 105, 'models': {'model': {'gains': 105, 'jobs': 105}}}]


def test_build_reads_inactive_receipts_once(tmp_path, monkeypatch):
    test_daily_history_exceeds_recent_jobs(tmp_path)
    (tmp_path / 'work/2008-06/functions.jsonl').write_text(json.dumps({'addr': '00400000', 'size': 10}))
    snapshots = iter([{'00400000': ['First', True]}, {'00400001': ['Later', True]}])
    calls = []

    def changing_receipts(root):
        calls.append(root)
        return next(snapshots)

    monkeypatch.setattr(integration_site, 'inactive_code', changing_receipts)
    data = integration_site.build(tmp_path, log=lambda _: None)
    assert len(calls) == 1
    assert set(data['inactive']) == set(data['owned']) == {'00400000'}


def test_new_output_preserves_published_history(tmp_path):
    test_daily_history_exceeds_recent_jobs(tmp_path)
    published = tmp_path / 'docs/integration.json'
    data = json.loads(published.read_text())
    old = {'day': '2020-01-01', 'groups': data['groups']}
    data['history'].insert(0, old)
    published.write_text(json.dumps(data))
    snapshot = integration_site.build(tmp_path, output=tmp_path / 'snapshot.json', log=lambda _: None)
    assert snapshot['history'][0] == old


def test_existing_output_merges_published_history(tmp_path):
    test_daily_history_exceeds_recent_jobs(tmp_path)
    published = tmp_path / 'docs/integration.json'
    data = json.loads(published.read_text())
    published_day = {'day': '2020-01-01', 'groups': data['groups']}
    alternate_day = {'day': '2020-01-02', 'groups': data['groups']}
    data['history'].insert(0, published_day)
    published.write_text(json.dumps(data))
    alternate = tmp_path / 'snapshot.json'
    stale_day = {'day': published_day['day'], 'groups': {}}
    alternate.write_text(json.dumps({'client': '2008-06', 'history': [stale_day, alternate_day]}))
    snapshot = integration_site.build(tmp_path, output=alternate, log=lambda _: None)
    assert snapshot['history'][:2] == [published_day, alternate_day]


def test_bulk_manifest_read_once_with_later_source(tmp_path, monkeypatch):
    source = tmp_path / 'rebuild/2008-06/native-classes/Foo.cpp'
    source.parent.mkdir(parents=True)
    source.write_text('void Foo::bar() {}\n')
    proofs = tmp_path / 'work/native-client/prove-out'
    first = proofs / 'first/manifest.json'
    second = proofs / 'second/manifest.json'
    first.parent.mkdir(parents=True)
    second.parent.mkdir(parents=True)
    symbol = '?bar@Foo@@QAE@XZ'
    first.write_text(json.dumps({'families': [{'jobs': [{'source': 'unused1'}, {'source': 'unused2'}],
        'symbols': [{'symbol': symbol, 'status': 'inactive_exact', 'candidates': ['00400000']}]}]}))
    second.write_text(json.dumps({'families': [{'jobs': [{'source': str(source)}],
        'symbols': [{'symbol': symbol, 'status': 'draft', 'candidates': ['00400000']}]}]}))
    import os
    os.utime(first, (1, 1))
    os.utime(second, (2, 2))
    read_text = Path.read_text
    reads = []
    def count_reads(path, *args, **kwargs):
        if path.name == 'manifest.json':
            reads.append(path)
        return read_text(path, *args, **kwargs)
    monkeypatch.setattr(Path, 'read_text', count_reads)
    found = integration_site.inactive_code(tmp_path)
    assert found['00400000'][1] is True
    assert found['00400000'][3] == ['rebuild/2008-06/native-classes/Foo.cpp', 1]
    assert reads == [first, second]


def test_stale_hashed_receipt_is_not_exact(tmp_path):
    source = tmp_path / 'rebuild/2008-06/native-classes/Foo.cpp'
    source.parent.mkdir(parents=True)
    source.write_text('void Foo::bar() { /* changed */ }\n')
    receipts = tmp_path / 'work/2008-06/shared-layouts'
    receipts.mkdir(parents=True)
    old = b'void Foo::bar() {}\n'
    (receipts / 'stale.json').write_text(json.dumps({
        'source_path': str(source), 'source_sha256': hashlib.sha256(old).hexdigest(),
        'checks': [{'address': '00400000', 'symbol': '?bar@Foo@@QAE@XZ', 'exact': True}],
    }))
    stale = integration_site.inactive_code(tmp_path)['00400000']
    assert stale[1] is False
    assert stale[3] is None
    original = source.with_name('FooOriginal.cpp')
    original.write_bytes(old)
    restored = integration_site.inactive_code(tmp_path)['00400000']
    assert restored[1] is True
    assert restored[3][0].endswith('FooOriginal.cpp')
