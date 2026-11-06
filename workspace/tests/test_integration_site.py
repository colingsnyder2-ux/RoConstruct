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


def test_inactive_source_links_require_published_content(tmp_path):
    import hashlib
    source = 'rebuild/2008-06/native-classes/WorkspaceLifetime.cpp'
    path = tmp_path / source
    path.parent.mkdir(parents=True)
    body = b'namespace RBX {\nWorkspace::Workspace() {}\n}\n'
    path.write_bytes(body.replace(b'\n', b'\r\n'))
    blob = hashlib.sha1(b'blob ' + str(len(body)).encode() + b'\0' + body).hexdigest()
    receipt = tmp_path / 'work/2008-06/shared-layouts/lifetime.json'
    receipt.parent.mkdir(parents=True)
    receipt.write_text(json.dumps({'sources': {source.replace('/', '\\'): 'recorded-hash'}}))
    inactive = {'005a4d90': ['RBX::Workspace::Workspace', True, 'lifetime.json'],
                '00500000': ['Draft::handle_500000', False, source]}
    result = integration_site.inactive_sources(tmp_path, inactive, {source: blob})
    assert result['005a4d90'] == {'path': 'workspace/' + source, 'line': 2}
    assert result['00500000']['path'] == 'workspace/' + source
    assert integration_site.inactive_sources(tmp_path, inactive, {}) == {}
    path.write_text('Different in-flight worker body')
    assert integration_site.inactive_sources(tmp_path, inactive, {source: blob}) == {}


def test_daily_history_exceeds_recent_jobs(tmp_path):
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


def test_live_progress_reads_new_receipts_scores_and_selection(tmp_path):
    work = tmp_path / 'work'
    (work / 'integration').mkdir(parents=True)
    (work / '2008-06/shared-layouts').mkdir(parents=True)
    proof = work / 'integration/progress-native.json'
    proof.write_text(json.dumps({'addresses': ['00400000']}))
    (work / '2008-06/functions.jsonl').write_text('\n'.join(
        json.dumps({'addr': '%08x' % (0x400000 + n), 'size': 10}) for n in range(4)))
    db = sqlite3.connect(work / 'server.db')
    db.execute('CREATE TABLE funcs(client TEXT, addr TEXT, score INTEGER)')
    db.executemany('INSERT INTO funcs VALUES (?,?,100)', [('2008-06', '%08x' % (0x400000+n)) for n in range(4)])
    db.commit()
    first = integration_site.live_progress(tmp_path)
    assert first['groups']['integrated']['functions'] == 1
    assert first['groups']['exact_waiting']['functions'] == 3
    receipt = work / '2008-06/shared-layouts/new.json'
    receipt.write_text(json.dumps([{'address':'00400001','symbol':'Exact','exact':True},
                                   {'address':'00400002','symbol':'Draft','exact':False}]))
    second = integration_site.live_progress(tmp_path)
    assert second['native_code']['inactive']['functions'] == 1
    assert second['native_code']['draft']['functions'] == 1
    assert second['groups']['exact_waiting']['functions'] == 1
    proof.write_text(json.dumps({'addresses':['00400000','00400001']}))
    third = integration_site.live_progress(tmp_path)
    assert third['groups']['integrated']['functions'] == 2
    assert third['native_code']['inactive']['functions'] == 0
    assert sum(g['functions'] for g in third['groups'].values()) - third['groups']['integrated']['functions'] == 2
    db.execute("UPDATE funcs SET score=50 WHERE addr='00400003'")
    db.commit(); db.close()
    assert integration_site.live_progress(tmp_path)['groups']['exact_waiting']['functions'] == 0


def test_runner_receipts_from_work_refresh_without_checkout_changes(tmp_path):
    import subprocess

    def git(*args, **kwargs):
        return subprocess.check_output(['git', *args], cwd=tmp_path, **kwargs).decode().strip()

    git('init', '-q')
    git('config', 'user.name', 'Test')
    git('config', 'user.email', 'test@example.invalid')
    folder = tmp_path / 'workspace/work/2008-06/shared-layouts'
    folder.mkdir(parents=True)
    row = dict(addr='00400000', symbol='Exact', status='exact', score=100,
               target_size=10, object_size=10, data_errors=[])
    path = folder / 'runner.json'
    path.write_text(json.dumps({'build': {'checks': [row]}}))
    git('add', '.')
    git('commit', '-qm', 'First receipt')
    first = git('rev-parse', 'HEAD')
    git('update-ref', 'refs/remotes/findings/work', first)
    git('update-ref', 'refs/forks/origin/work', first)
    assert integration_site.inactive_code(tmp_path)['00400000'][1] is True

    bad = dict(row, addr='00400001', data_errors=['wrong constant'])
    draft = dict(row, addr='00400002', status='different', score=99)
    path.write_text(json.dumps({'checks': [row, bad, draft]}))
    git('add', '.')
    git('commit', '-qm', 'New receipt')
    git('update-ref', 'refs/forks/origin/work', git('rev-parse', 'HEAD'))
    head = git('rev-parse', 'HEAD')
    index = (tmp_path / '.git/index').read_bytes()
    # Deliberately stale/dirty local file cannot hide the committed new receipt.
    path.write_text('worker edits remain untouched')
    result = integration_site.inactive_code(tmp_path)
    assert result['00400000'][1] is True
    assert result['00400001'][1] is False
    assert result['00400002'][1] is False
    assert path.read_text() == 'worker edits remain untouched'
    assert git('rev-parse', 'HEAD') == head
    assert (tmp_path / '.git/index').read_bytes() == index
