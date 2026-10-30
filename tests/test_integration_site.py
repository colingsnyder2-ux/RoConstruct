import json
import sqlite3

from roc import integration_site


def test_owned_inventory_is_disjoint_from_accepted_and_excludes_data(tmp_path):
    out = tmp_path / 'rebuild/2008-06/out'
    for module in ('First', 'Second', 'CodegenAnalogs'):
        folder = out / module;folder.mkdir(parents=True)
        addresses = ['00400000', '00400001', '00400003'] if module != 'CodegenAnalogs' else ['00400002']
        (folder / 'report.json').write_text(json.dumps(dict(module=module, owned_addrs=addresses)))
    work = tmp_path / 'work/2008-06';work.mkdir(parents=True)
    (work / 'functions.jsonl').write_text('\n'.join(json.dumps(dict(addr='0040000'+str(n),size=10,kind='data' if n==3 else 'code')) for n in range(4)))
    groups, functions = integration_site.coverage(tmp_path, {'00400001':100,'00400002':100}, {'00400000'})
    assert groups['integrated']['functions'] == 1
    assert groups['owned_waiting']['functions'] == 1
    assert groups['exact_waiting']['functions'] == 1
    assert sum(row['functions'] for row in groups.values()) == len(functions) == 3


def test_site_groups_and_merged_receipts(tmp_path):
    work = tmp_path / 'work'
    (work / 'integration').mkdir(parents=True)
    (work / '2008-06').mkdir()
    (work / 'integration/progress-native.json').write_text(json.dumps({'addresses': ['00400000']}))
    (work / '2008-06/functions.jsonl').write_text('\n'.join(
        json.dumps({'addr': '%08x' % (0x400000 + n), 'size': 10 * (n + 1)}) for n in range(4)))
    db = sqlite3.connect(work / 'server.db')
    db.executescript('''
        CREATE TABLE funcs(client TEXT, addr TEXT, score INTEGER);
        CREATE TABLE integration_jobs(id TEXT, user TEXT, model TEXT, unit TEXT, receipt TEXT, updated REAL, state TEXT);
        CREATE TABLE integration_credit(client TEXT, user TEXT, model TEXT);
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
        'owned_waiting': {'functions': 0, 'bytes': 0},
        'integrated': {'functions': 1, 'bytes': 10}, 'exact_waiting': {'functions': 1, 'bytes': 20},
        'partial': {'functions': 1, 'bytes': 30}, 'unmined': {'functions': 1, 'bytes': 40}}
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


def test_daily_history_exceeds_recent_jobs(tmp_path):
    work = tmp_path / 'work/2008-06'
    work.mkdir(parents=True)
    (work / 'functions.jsonl').write_text('')
    db = sqlite3.connect(tmp_path / 'work/server.db')
    db.executescript('''
        CREATE TABLE funcs(client TEXT, addr TEXT, score INTEGER);
        CREATE TABLE integration_jobs(id TEXT, user TEXT, model TEXT, unit TEXT, receipt TEXT, updated REAL, state TEXT);
        CREATE TABLE integration_credit(client TEXT, user TEXT, model TEXT);
    ''')
    db.executemany('INSERT INTO integration_jobs VALUES (?,?,?,?,?,?,?)', [
        (str(n), 'tester', 'model', 'RBX::Camera', json.dumps({'new_distinct': [str(n)]}),
         1793145600 + n, 'accepted') for n in range(105)])  # Oct 28 UTC, still Oct 27 Eastern.
    db.commit()
    db.close()
    data = integration_site.build(tmp_path, log=lambda _: None)
    assert len(data['jobs']) == 100
    assert data['daily'] == [{'day': '2026-10-27', 'gains': 105, 'jobs': 105, 'models': {'model': {'gains': 105, 'jobs': 105}}}]
