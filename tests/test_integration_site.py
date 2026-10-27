import json
import sqlite3

from roc import integration_site


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
        'integrated': {'functions': 1, 'bytes': 10}, 'exact_waiting': {'functions': 1, 'bytes': 20},
        'partial': {'functions': 1, 'bytes': 30}, 'unmined': {'functions': 1, 'bytes': 40}}
    assert len(data['jobs']) == 1
    assert data['jobs'][0]['gains'] == 2
    assert data['jobs'][0]['distinct_gains'] == 1
    assert data['leaderboard'][0]['native_credits'] == 1
    assert json.loads((tmp_path / 'docs/integration.json').read_text()) == data


def test_readable_native_method():
    assert integration_site.readable('?askSetParent@Camera@RBX@@UBEXPAVInstance@2@@Z') == 'RBX::Camera::askSetParent'
    assert integration_site.readable('??1Camera@RBX@@UAE@XZ') == 'RBX::Camera::~Camera'
