import json
import sqlite3

from roc.findings_publish import export_native


def test_publish_snapshot_does_not_block_live_commits(tmp_path, monkeypatch):
    from roc import findings_publish, server
    (tmp_path / 'work').mkdir()
    path = tmp_path / 'work/server.db'
    with sqlite3.connect(path) as live:
        live.execute('CREATE TABLE items(value)')
        live.execute('INSERT INTO items VALUES(1)')

    def export_sources(store):
        with sqlite3.connect(path, timeout=0) as writer:
            writer.execute('INSERT INTO items VALUES(2)')
        assert store.db.execute('SELECT COUNT(*) FROM items').fetchone()[0] == 1

    monkeypatch.setattr(server, 'ROOT', tmp_path)
    monkeypatch.setattr(server, 'sync_findings', export_sources)
    from roc import findings_transport
    monkeypatch.setattr(findings_transport, 'publish', lambda *args: None)
    monkeypatch.setattr(findings_publish, 'prepare_native', lambda *args: {'clients': []})
    monkeypatch.setattr(findings_publish.sys, 'argv', ['findings_publish.py', '--root', str(tmp_path)])
    findings_publish.main()
    with sqlite3.connect(path) as live:
        assert live.execute('SELECT COUNT(*) FROM items').fetchone()[0] == 2
    assert not list((tmp_path / 'work').glob('findings-db-*'))


def test_native_export_preserves_accepted_history_and_excludes_private_trees(tmp_path):
    db = sqlite3.connect(":memory:")
    db.executescript("""
        CREATE TABLE integration_accepted(job,patches,ts);
        CREATE TABLE integration_config(key,value);
        CREATE TABLE integration_jobs(id,user,unit,model,state,phase,created,updated,patches,receipt);
        CREATE TABLE integration_credit(client,addr,user,model,job);
        CREATE TABLE funcs(client,source,score);
        INSERT INTO integration_accepted VALUES('accepted','{"patch":1}',1);
        INSERT INTO integration_config VALUES('initial_patches','{}');
        INSERT INTO integration_jobs VALUES('pending','colin','Part','Codex','queued','queued',2,2,'{}','{"token":"secret","credits":0}');
        INSERT INTO integration_credit VALUES('2008-06','00401000','colin','Codex','accepted');
        INSERT INTO funcs VALUES('2008-06','int f();',100);
        INSERT INTO funcs VALUES('2008-06','int g();',50);
    """)
    for relative in ("patches/test.json", "modules/test.json", "out/private.cpp", "manifests/private.json", "patches/private.obj"):
        path = tmp_path / "rebuild/2008-06" / relative
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(b"{\r\n}\r\n")
    private_source = tmp_path / 'roc/rebuild.py'
    private_source.parent.mkdir()
    webhook = b'https://discord.com/api/webhooks/123/example-private-token'
    private_source.write_bytes(b'WEBHOOK = "' + webhook + b'"\r\n')
    inventory = export_native(tmp_path, db)
    folder = tmp_path / "local/findings/2008-06/verification"
    assert inventory["clients"] == [{"client": "2008-06", "stored_sources": 2, "exact_sources": 1}]
    assert inventory["accepted_jobs"] == inventory["native_credits"] == 1
    assert inventory['sha256'] == {}
    assert webhook in private_source.read_bytes()
    assert not (folder / 'working-tree').exists()
    assert json.loads((folder / "accepted-integrations.json").read_text())["accepted"][0]["job"] == "accepted"
    assert json.loads((folder / "integration-jobs.json").read_text())[0]["state"] == "queued"
    assert "secret" not in (folder / "integration-jobs.json").read_text()
    before = {p.relative_to(folder): p.read_bytes() for p in folder.rglob("*") if p.is_file()}
    export_native(tmp_path, db)
    assert before == {p.relative_to(folder): p.read_bytes() for p in folder.rglob("*") if p.is_file()}


def test_server_native_export_uses_private_snapshot_and_closes_it(tmp_path, monkeypatch):
    from roc import findings_publish, rebuild_package
    (tmp_path / 'rebuild/2008-06').mkdir(parents=True)
    (tmp_path / 'work').mkdir()
    path = tmp_path / 'work/server.db'
    with sqlite3.connect(path) as db:
        db.execute('CREATE TABLE items(value)')
        db.execute('INSERT INTO items VALUES(1)')
    def export(root, snapshot):
        with sqlite3.connect(path, timeout=0) as live:
            live.execute('INSERT INTO items VALUES(2)')
        assert snapshot.execute('SELECT COUNT(*) FROM items').fetchone()[0] == 1
        return {'clients': []}
    monkeypatch.setattr(findings_publish, 'export_native', export)
    monkeypatch.setattr(rebuild_package, 'export', lambda *a: {'files': {}, 'large_files': {}, 'pending_build_files': []})
    assert findings_publish.prepare_native(tmp_path, lambda text: None) == {'clients': []}
    assert not list((tmp_path / 'work').glob('findings-native-db-*'))
